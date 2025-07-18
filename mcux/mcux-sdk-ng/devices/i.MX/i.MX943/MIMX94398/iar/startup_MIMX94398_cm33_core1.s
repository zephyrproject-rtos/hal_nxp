; -------------------------------------------------------------------------
;  @file:    startup_MIMX94398_cm33_core1.s
;  @purpose: CMSIS Cortex-M33 Core Device Startup File
;            MIMX94398_cm33_core1
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
        DCD     SecureFault_Handler                           ;Secure Fault Handler
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
        DCD     IRQSTEERM33_CH0_IRQHandler                    ;IRQSTEERM33 output channel 0 interrupt
        DCD     IRQSTEERM33_CH1_IRQHandler                    ;IRQSTEERM33 output channel 1 interrupt
        DCD     IRQSTEERM33_CH2_IRQHandler                    ;IRQSTEERM33 output channel 2 interrupt
        DCD     IRQSTEERM33_CH3_IRQHandler                    ;IRQSTEERM33 output channel 3 interrupt
        DCD     IRQSTEERM33_CH4_IRQHandler                    ;IRQSTEERM33 output channel 4 interrupt
        DCD     IRQSTEERM33_CH5_IRQHandler                    ;IRQSTEERM33 output channel 5 interrupt
        DCD     EDMA1_CH0_IRQHandler                          ;WAKEUPMIX EDMA1 channel 0 interrupt
        DCD     EDMA1_CH1_IRQHandler                          ;WAKEUPMIX EDMA1 channel 1 interrupt
        DCD     EDMA1_CH2_IRQHandler                          ;WAKEUPMIX EDMA1 channel 2 interrupt
        DCD     EDMA1_CH3_IRQHandler                          ;WAKEUPMIX EDMA1 channel 3 interrupt
        DCD     EDMA1_CH4_IRQHandler                          ;WAKEUPMIX EDMA1 channel 4 interrupt
        DCD     EDMA1_CH5_IRQHandler                          ;WAKEUPMIX EDMA1 channel 5 interrupt
        DCD     EDMA1_CH6_IRQHandler                          ;WAKEUPMIX EDMA1 channel 6 interrupt
        DCD     EDMA1_CH7_IRQHandler                          ;WAKEUPMIX EDMA1 channel 7 interrupt
        DCD     EDMA1_CH8_IRQHandler                          ;WAKEUPMIX EDMA1 channel 8 interrupt
        DCD     EDMA1_CH9_IRQHandler                          ;WAKEUPMIX EDMA1 channel 9 interrupt
        DCD     EDMA1_CH10_IRQHandler                         ;WAKEUPMIX EDMA1 channel 10 interrupt
        DCD     EDMA1_CH11_IRQHandler                         ;WAKEUPMIX EDMA1 channel 11 interrupt
        DCD     EDMA1_CH12_IRQHandler                         ;WAKEUPMIX EDMA1 channel 12 interrupt
        DCD     EDMA1_CH13_IRQHandler                         ;WAKEUPMIX EDMA1 channel 13 interrupt
        DCD     EDMA1_CH14_IRQHandler                         ;WAKEUPMIX EDMA1 channel 14 interrupt
        DCD     EDMA1_CH15_IRQHandler                         ;WAKEUPMIX EDMA1 channel 15 interrupt
        DCD     EDMA1_CH16_IRQHandler                         ;WAKEUPMIX EDMA1 channel 16 interrupt
        DCD     EDMA1_CH17_IRQHandler                         ;WAKEUPMIX EDMA1 channel 17 interrupt
        DCD     EDMA1_CH18_IRQHandler                         ;WAKEUPMIX EDMA1 channel 18 interrupt
        DCD     EDMA1_CH19_IRQHandler                         ;WAKEUPMIX EDMA1 channel 19 interrupt
        DCD     EDMA1_CH20_IRQHandler                         ;WAKEUPMIX EDMA1 channel 20 interrupt
        DCD     EDMA1_CH21_IRQHandler                         ;WAKEUPMIX EDMA1 channel 21 interrupt
        DCD     EDMA1_CH22_IRQHandler                         ;WAKEUPMIX EDMA1 channel 22 interrupt
        DCD     EDMA1_CH23_IRQHandler                         ;WAKEUPMIX EDMA1 channel 23 interrupt
        DCD     EDMA1_CH24_IRQHandler                         ;WAKEUPMIX EDMA1 channel 24 interrupt
        DCD     EDMA1_CH25_IRQHandler                         ;WAKEUPMIX EDMA1 channel 25 interrupt
        DCD     EDMA1_CH26_IRQHandler                         ;WAKEUPMIX EDMA1 channel 26 interrupt
        DCD     EDMA1_CH27_IRQHandler                         ;WAKEUPMIX EDMA1 channel 27 interrupt
        DCD     EDMA1_CH28_IRQHandler                         ;WAKEUPMIX EDMA1 channel 28 interrupt
        DCD     EDMA1_CH29_IRQHandler                         ;WAKEUPMIX EDMA1 channel 29 interrupt
        DCD     EDMA1_CH30_IRQHandler                         ;WAKEUPMIX EDMA1 channel 30 interrupt
        DCD     EDMA1_CH31_IRQHandler                         ;WAKEUPMIX EDMA1 channel 31 interrupt
        DCD     MU1_A_IRQHandler                              ;AONMIX MU1 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU1_B_IRQHandler                              ;AONMIX MU1 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU2_A_IRQHandler                              ;AONMIX MU2 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU2_B_IRQHandler                              ;AONMIX MU2 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU3_A_IRQHandler                              ;AONMIX MU3 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU3_B_IRQHandler                              ;AONMIX MU3 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU4_A_IRQHandler                              ;AONMIX MU4 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU4_B_IRQHandler                              ;AONMIX MU4 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU5_B_IRQHandler                              ;AONMIX MU5 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU6_B_IRQHandler                              ;AONMIX MU6 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU7_B_IRQHandler                              ;AONMIX MU7 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU8_A_IRQHandler                              ;AONMIX MU8 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU8_B_IRQHandler                              ;AONMIX MU8 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU9_A_IRQHandler                              ;AONMIX MU9 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU9_B_IRQHandler                              ;AONMIX MU9 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU10_A_IRQHandler                             ;WAKEUPMIX MU10 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU11_A_IRQHandler                             ;WAKEUPMIX MU11 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU12_B_IRQHandler                             ;WAKEUPMIX MU12 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU13_B_IRQHandler                             ;WAKEUPMIX MU13 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU14_A_IRQHandler                             ;WAKEUPMIX MU14 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU14_B_IRQHandler                             ;WAKEUPMIX MU14 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU15_A_IRQHandler                             ;WAKEUPMIX MU15 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU15_B_IRQHandler                             ;WAKEUPMIX MU15 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU16_A_IRQHandler                             ;WAKEUPMIX MU16 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU16_B_IRQHandler                             ;WAKEUPMIX MU16 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU17_A_IRQHandler                             ;WAKEUPMIX MU17 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU17_B_IRQHandler                             ;WAKEUPMIX MU17 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU_E1_B_IRQHandler                            ;NETCMIX MU E1 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU_E2_B_IRQHandler                            ;NETCMIX MU E2 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU_E3_B_IRQHandler                            ;NETCMIX MU E3 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU_E4_B_IRQHandler                            ;NETCMIX MU E4 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MSGINTR1_IRQHandler                           ;MSGINTR Instance 1 Interrupt
        DCD     MSGINTR2_IRQHandler                           ;MSGINTR Instance 2 Interrupt
        DCD     MSGINTR3_IRQHandler                           ;MSGINTR Instance 3 Interrupt
        DCD     MSGINTR4_IRQHandler                           ;MSGINTR Instance 4 Interrupt
        DCD     MSGINTR5_IRQHandler                           ;MSGINTR Instance 5 Interrupt
        DCD     MSGINTR6_IRQHandler                           ;MSGINTR Instance 6 Interrupt
        DCD     MSGINTR7_IRQHandler                           ;MSGINTR Instance 7 Interrupt
        DCD     MSGINTR8_IRQHandler                           ;MSGINTR Instance 8 Interrupt
        DCD     V2X_FH_MU_APCH1_IRQHandler                    ;V2X-FH MU APCH1 (APP1) interrupt
        DCD     V2X_FH_MU_APHSM2_IRQHandler                   ;V2X-FH MU APHSM2 (HSM2) interrupt
        DCD     Reserved319_IRQHandler                        ;Sentinel Group 1 reset source if no s500 reference clock is detected.  Output synchronized to 32khz clk. New signal name for i.MX943 is s4v1_fdet0_tclk_err_irq. (Cause Reset)
        DCD     Reserved320_IRQHandler                        ;Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk the S500 clock. New signal name for i.MX943 is s4v1_fdet2_tclk_err_irq.  (Reset Request in CM33 domain)
        DCD     Reserved321_IRQHandler                        ;Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk. New signal name for i.MX943 is s4v1_fdet3_tclk_err_irq
        DCD     Reserved322_IRQHandler                        ;Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to S500 clock domain. New signal name for i.MX943 is s4v1_fdet1_tclk_err_irq
        DCD     Reserved323_IRQHandler                        ;s500 glue logic IRQ
        DCD     GPC_SM_REQ_IRQHandler                         ;SRC/GPC Low Power Handshake Gasket interrupt request for system management
        DCD     EDMA1_ERROR_IRQHandler                        ;AONMIX EDMA1 error interrupt
        DCD     Reserved326_IRQHandler                        ;AONMIX TRDC transfer error interrupt
        DCD     Reserved327_IRQHandler                        ;WAKEUPMIX TRDC-MGR1 transfer error interrupt
        DCD     Reserved328_IRQHandler                        ;MEGAMIX TRDC transfer error interrupt
        DCD     Reserved329_IRQHandler                        ;NOCMIX TRDC transfer error interrupt
        DCD     Reserved330_IRQHandler                        ;DISPLAYMIX TRDC transfer error interrupt
        DCD     Reserved331_IRQHandler                        ;NETCMIX TRDC/NET_M33_Sync Platform transfer error interrupt
        DCD     Reserved332_IRQHandler                        ;HSIOMIX TRDC transfer error interrupt
        DCD     Reserved333_IRQHandler                        ;WAKEUPMIX TRDC-MGR2 transfer error interrupt
        DCD     Reserved334_IRQHandler                        ;AONMIX ERM Single bit corrected ECC error
        DCD     Reserved335_IRQHandler                        ;M7MIX0 ERM Single bit corrected ECC error
        DCD     Reserved336_IRQHandler                        ;M7MIX1 ERM Single bit corrected ECC error
        DCD     Reserved337_IRQHandler                        ;WAKEUPMIX ERM Single bit corrected ECC error
        DCD     Reserved338_IRQHandler                        ;NPUMIX ERM Single bit corrected ECC error
        DCD     Reserved339_IRQHandler                        ;NETCMIX ERM Single bit corrected ECC error
        DCD     Reserved340_IRQHandler                        ;OCRAM ECC multi bit error
        DCD     Reserved341_IRQHandler                        ;AONMIX MTR Master error interrupt
        DCD     EDMA3_ERROR_IRQHandler                        ;EDMA3 DMA error interrupt
        DCD     Reserved343_IRQHandler                        ;AONMIX M33 PS Tag/Data parity error
        DCD     M33_TCM_ERROR_IRQHandler                      ;AONMIX M33 TCM error interrupt
        DCD     Reserved345_IRQHandler                        ;M7MIX ECC multi bit error
        DCD     Reserved346_IRQHandler                        ;NETCMIX M33 PS Tag/Data parity error
        DCD     M33_SYNC_TCM_ERROR_IRQHandler                 ;NETCMIX M33 TCM error interrupt
        DCD     ONE_POINT_FIVE_MB_OCRAM_ERROR_IRQHandler      ;NETCMIX 1.5MB OCSRAM Error interrupt
        DCD     Reserved349_IRQHandler                        ;M7MIX1 ECC Multi-bit error
        DCD     GIC700_FAULT_IRQHandler                       ;GIC700 Fault(Uncorrectable ECC errors)
        DCD     M33_MCM_IRQHandler                            ;CM33 MCM interrupt
        DCD     M33_SYNC_MCM_IRQHandler                       ;CM33_sync MCM interrupt
        DCD     ONE_POINT_FIVE_MB_SRAM_MCM_IRQHandler         ;NETCMIX 1.5MB SRAM MCM interrupt
        DCD     M7MIX0_MCM_IRQHandler                         ;M7MIX0 MCM interrupt
        DCD     M7MIX1_MCM_IRQHandler                         ;M7MIX1 MCM interrupt
        DCD     OCRAM_ECC_SINGLE_BIT_ERROR_IRQHandler         ;OCRAM ECC single bit error
        DCD     GIC700_ERROR_IRQHandler                       ;GIC700 Error(Correctable ECC errors)
        DCD     SFA_IRQHandler                                ;ANAMIX SFA(Signal Frequency Analyzer) interrupt
        DCD     TMPSNS_THR1_IRQHandler                        ;ANAMIX TempSensor non-secure interrupt from Threshold 1
        DCD     TMPSNS_THR2_IRQHandler                        ;ANAMIX TempSensor non-secure interrupt from Threshold 2
        DCD     Reserved361_IRQHandler                        ;ANAMIX TempSensor non-secure data ready interrupt
        DCD     Reserved362_IRQHandler                        ;CORTEXAMIX TempSensor non-secure interrupt from Threshold 1
        DCD     Reserved363_IRQHandler                        ;CORTEXAMIX TempSensor non-secure interrupt from Threshold 2
        DCD     Reserved364_IRQHandler                        ;CORTEXAMIX TempSensor non-secure data ready interrupt
        DCD     CM33_0_SYSRESETREQ_IRQHandler                 ;AONMIX CM33 SYSREQRST SRC reset source
        DCD     CM33_0_LOCKUP_IRQHandler                      ;AONMIX CM33 LOCKUP SRC reset source
        DCD     CM7_0_SYSRESETREQ_IRQHandler                  ;CM7_0 SYSREQRST SRC reset source
        DCD     CM7_0_LOCKUP_IRQHandler                       ;CM7_0 LOCKUP SRC reset source
        DCD     CM33_1_SYSRESETREQ_IRQHandler                 ;NETCMIX CM33_sync SYSREQRST SRC reset source
        DCD     CM33_1_LOCKUP_IRQHandler                      ;NETCMIX CM33_sync LOCKUP SRC reset source
        DCD     CM7_1_SYSRESETREQ_IRQHandler                  ;CM7_1 SYSREQRST SRC reset source
        DCD     CM7_1_LOCKUP_IRQHandler                       ;CM7_1 LOCKUP SRC reset source
        DCD     SOC_RESET_WO_NETC_IRQHandler                  ;SoC reset without netc interrupt
        DCD     Reserved374_IRQHandler                        ;NETC iEPRC PCI INT (one per each of two RC-EC, first one)
        DCD     Reserved375_IRQHandler                        ;NETC iEPRC PCI INT (one per each of two RC-EC, second one)
        DCD     PCIE1_INTA_IRQHandler                         ;PCIe Controller 1 INTA
        DCD     PCIE1_INTB_IRQHandler                         ;PCIe Controller 1 INTB
        DCD     PCIE1_INTC_IRQHandler                         ;PCIe Controller 1 INTC
        DCD     PCIE1_INTD_IRQHandler                         ;PCIe Controller 1 INTD
        DCD     Reserved380_IRQHandler                        ;PCIe 1 miscellaneous interrupts/PCIe MSI reception interrupt for RC mode/PCIe Link reset request interrupt
        DCD     Reserved381_IRQHandler                        ;PCIe Controller 1 EDMA channel interrupt
        DCD     PCIE2_INTA_IRQHandler                         ;PCIe Controller 2 INTA
        DCD     PCIE2_INTB_IRQHandler                         ;PCIe Controller 2 INTB
        DCD     PCIE2_INTC_IRQHandler                         ;PCIe Controller 2 INTC
        DCD     PCIE2_INTD_IRQHandler                         ;PCIe Controller 2 INTD
        DCD     Reserved386_IRQHandler                        ;PCIe 2 miscellaneous interrupts/PCIe MSI reception interrupt for RC mode/PCIe Link reset request interrupt
        DCD     Reserved387_IRQHandler                        ;PCIe Controller 2 EDMA channel interrupt
        DCD     Reserved388_IRQHandler                        ;NPUMIX Wakeup interrupt from CLKREQ#, WAKEUP#, BEACON_DET
        DCD     NPUMIX_FUNC_IRQHandler                        ;NPUMIX Functional interrupt
        DCD     Reserved390_IRQHandler                        ;DRAM controller Performance Monitor Interrupt
        DCD     Reserved391_IRQHandler                        ;DRAM controller Critical Interrupt
        DCD     Reserved392_IRQHandler                        ;DRAM Phy Critical Interrupt 0~15
        DCD     DCIF_CPU_DOMAIN0_IRQHandler                   ;DISPLAYMIX DCIF: Interrupt output for CPU domain0 (Controlled by common registers group)
        DCD     DCIF_CPU_DOMAIN1_IRQHandler                   ;DISPLAYMIX DCIF: Interrupt output for CPU domain1 (Controlled by background layer registers group)
        DCD     DCIF_CPU_DOMAIN2_IRQHandler                   ;DISPLAYMIX DCIF: Interrupt output for CPU domain2 (Controlled by foreground layer registers group)
        DCD     Reserved396_IRQHandler                        ;Reserved
        DCD     Reserved397_IRQHandler                        ;Reserved
        DCD     PXP_0_IRQHandler                              ;DISPLAYMIX PXP interrupt 0
        DCD     PXP_1_IRQHandler                              ;DISPLAYMIX PXP interrupt 1
        DCD     Reserved400_IRQHandler                        ;V2X-FH MU APSHE (SHE) A_TX/A_RX interrupt
        DCD     Reserved401_IRQHandler                        ;V2X-FH MU SCU/APDEBUG (DEBUG) B_TX/B_RX interrupt
        DCD     Reserved402_IRQHandler                        ;USB-1 (USB 3.0) Wake-up Interrupt
        DCD     Reserved403_IRQHandler                        ;USB-2 (USB 2.0) Wake-up Interrupt
        DCD     Reserved404_IRQHandler                        ;GIC700 PMU Counter Overflow
        DCD     Reserved405_IRQHandler                        ;Reserved
        DCD     XSPI1_IRQHandler                              ;xspi1 all interrupts ORed output for EENV0 (MEENV)/xspi1 arbitration lock timeout interrupt for EENV0/xspi1 arbitration win interrupt for EENV0/xspi1 FlashA error interrupt for EENV0
        DCD     Reserved407_IRQHandler                        ;xspi1 all interrupts ORed output for EENV1 (MEENV)/xspi1 arbitration lock timeout interrupt for EENV1/xspi1 arbitration lock timeout interrupt for EENV1/xspi1 arbitration win interrupt for EENV1/xspi1 FlashA error interrupt for EENV1
        DCD     Reserved408_IRQHandler                        ;xspi1 all interrupts ORed output for EENV2 (MEENV)/xspi1 arbitration lock timeout interrupt for EENV2/        xspi1 arbitration win interrupt for EENV2/xspi1 FlashA error interrupt for EENV2
        DCD     Reserved409_IRQHandler                        ;xspi1 all interrupts ORed output for EENV3 (MEENV)/xspi1 arbitration lock timeout interrupt for EENV3/xspi1 arbitration win interrupt for EENV3/xspi1 FlashA error interrupt for EENV3
        DCD     Reserved410_IRQHandler                        ;xspi1 all interrupts ORed output for EENV4 (MEENV)/xspi1 arbitration lock timeout interrupt for EENV4/xspi1 arbitration win interrupt for EENV4/xspi1 FlashA error interrupt for EENV4
        DCD     XSPI2_IRQHandler                              ;xspi2 all interrupts ORed output for EENV0 (MEENV)/xspi2 arbitration lock timeout interrupt for EENV0/xspi2 arbitration lock timeout interrupt for EENV0/xspi2 arbitration win interrupt for EENV0/xspi2 FlashA error interrupt for EENV0
        DCD     Reserved412_IRQHandler                        ;xspi2 all interrupts ORed output for EENV1 (MEENV)/xspi2 arbitration lock timeout interrupt for EENV1/xspi2 arbitration lock timeout interrupt for EENV1/xspi2 arbitration win interrupt for EENV1/xspi2 FlashA error interrupt for EENV1
        DCD     Reserved413_IRQHandler                        ;xspi2 all interrupts ORed output for EENV2 (MEENV)/xspi2 arbitration lock timeout interrupt for EENV2/xspi2 arbitration win interrupt for EENV2/xspi2 FlashA error interrupt for EENV2
        DCD     Reserved414_IRQHandler                        ;xspi2 all interrupts ORed output for EENV3 (MEENV)/xspi2 arbitration lock timeout interrupt for EENV3/xspi2 arbitration win interrupt for EENV3/xspi2 FlashA error interrupt for EENV3
        DCD     Reserved415_IRQHandler                        ;xspi2 all interrupts ORed output for EENV4 (MEENV)/xspi2 arbitration lock timeout interrupt for EENV4/xspi2 arbitration win interrupt for EENV4/xspi2 FlashA error interrupt for EENV4
        DCD     Reserved416_IRQHandler                        ;Reserved
        DCD     Reserved417_IRQHandler                        ;Reserved
        DCD     Reserved418_IRQHandler                        ;Reserved
        DCD     Reserved419_IRQHandler                        ;Reserved
        DCD     Reserved420_IRQHandler                        ;Reserved
        DCD     Reserved421_IRQHandler                        ;Reserved
        DCD     Reserved422_IRQHandler                        ;Global fault event Module=NETC IRQ=406
        DCD     EDMA2_CH0_IRQHandler                          ;WAKEUPMIX EDMA2 channel 0 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[0] - inputs[0]) IRQ=407
        DCD     EDMA2_CH1_IRQHandler                          ;WAKEUPMIX EDMA2 channel 1 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[1] - inputs[1]) IRQ=408
        DCD     EDMA2_CH2_IRQHandler                          ;WAKEUPMIX EDMA2 channel 2 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[2] - inputs[2]) IRQ=409
        DCD     EDMA2_CH3_IRQHandler                          ;WAKEUPMIX EDMA2 channel 3 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[3] - inputs[3]) IRQ=410
        DCD     EDMA2_CH4_IRQHandler                          ;WAKEUPMIX EDMA2 channel 4 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[4] - inputs[4]) IRQ=411
        DCD     EDMA2_CH5_IRQHandler                          ;WAKEUPMIX EDMA2 channel 5 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[5] - inputs[5]) IRQ=412
        DCD     EDMA2_CH6_IRQHandler                          ;WAKEUPMIX EDMA2 channel 6 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[6] - inputs[6]) IRQ=413
        DCD     EDMA2_CH7_IRQHandler                          ;WAKEUPMIX EDMA2 channel 7 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[7] - inputs[7]) IRQ=414
        DCD     EDMA2_CH8_IRQHandler                          ;WAKEUPMIX EDMA2 channel 8 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[8] - inputs[8]) IRQ=415
        DCD     EDMA2_CH9_IRQHandler                          ;WAKEUPMIX EDMA2 channel 9 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[9] - inputs[9]) IRQ=416
        DCD     EDMA2_CH10_IRQHandler                         ;WAKEUPMIX EDMA2 channel 10 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[10] - inputs[10]) IRQ=417
        DCD     EDMA2_CH11_IRQHandler                         ;WAKEUPMIX EDMA2 channel 11 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[11] - inputs[11]) IRQ=418
        DCD     EDMA2_CH12_IRQHandler                         ;WAKEUPMIX EDMA2 channel 12 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[12] - inputs[12]) IRQ=419
        DCD     EDMA2_CH13_IRQHandler                         ;WAKEUPMIX EDMA2 channel 13 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[13] - inputs[13]) IRQ=420
        DCD     EDMA2_CH14_IRQHandler                         ;WAKEUPMIX EDMA2 channel 14 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[14] - inputs[14]) IRQ=421
        DCD     EDMA2_CH15_IRQHandler                         ;WAKEUPMIX EDMA2 channel 15 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[15] - inputs[15]) IRQ=422
        DCD     EDMA2_CH16_IRQHandler                         ;WAKEUPMIX EDMA2 channel 16 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[16] - inputs[16]) IRQ=423
        DCD     EDMA2_CH17_IRQHandler                         ;WAKEUPMIX EDMA2 channel 17 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[17] - inputs[17]) IRQ=424
        DCD     EDMA2_CH18_IRQHandler                         ;WAKEUPMIX EDMA2 channel 18 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[18] - inputs[18]) IRQ=425
        DCD     EDMA2_CH19_IRQHandler                         ;WAKEUPMIX EDMA2 channel 19 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[19] - inputs[19]) IRQ=426
        DCD     EDMA2_CH20_IRQHandler                         ;WAKEUPMIX EDMA2 channel 20 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[20] - inputs[20]) IRQ=427
        DCD     EDMA2_CH21_IRQHandler                         ;WAKEUPMIX EDMA2 channel 21 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[21] - inputs[21]) IRQ=428
        DCD     EDMA2_CH22_IRQHandler                         ;WAKEUPMIX EDMA2 channel 22 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[22] - inputs[22]) IRQ=429
        DCD     EDMA2_CH23_IRQHandler                         ;WAKEUPMIX EDMA2 channel 23 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[23] - inputs[23]) IRQ=430
        DCD     EDMA2_CH24_IRQHandler                         ;WAKEUPMIX EDMA2 channel 24 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[24] - inputs[24]) IRQ=431
        DCD     EDMA2_CH25_IRQHandler                         ;WAKEUPMIX EDMA2 channel 25 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[25] - inputs[25]) IRQ=432
        DCD     EDMA2_CH26_IRQHandler                         ;WAKEUPMIX EDMA2 channel 26 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[26] - inputs[26]) IRQ=433
        DCD     EDMA2_CH27_IRQHandler                         ;WAKEUPMIX EDMA2 channel 27 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[27] - inputs[27]) IRQ=434
        DCD     EDMA2_CH28_IRQHandler                         ;WAKEUPMIX EDMA2 channel 28 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[28] - inputs[28]) IRQ=435
        DCD     EDMA2_CH29_IRQHandler                         ;WAKEUPMIX EDMA2 channel 29 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[29] - inputs[29]) IRQ=436
        DCD     EDMA2_CH30_IRQHandler                         ;WAKEUPMIX EDMA2 channel 30 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[30] - inputs[30]) IRQ=437
        DCD     EDMA2_CH31_IRQHandler                         ;WAKEUPMIX EDMA2 channel 31 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[31] - inputs[31]) IRQ=438
        DCD     Reserved455_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[32] - inputs[32]) IRQ=439
        DCD     Reserved456_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[33] - inputs[33]) IRQ=440
        DCD     Reserved457_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[34] - inputs[34]) IRQ=441
        DCD     Reserved458_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[35] - inputs[35]) IRQ=442
        DCD     Reserved459_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[36] - inputs[36]) IRQ=443
        DCD     Reserved460_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[37] - inputs[37]) IRQ=444
        DCD     Reserved461_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[38] - inputs[38]) IRQ=445
        DCD     Reserved462_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[39] - inputs[39]) IRQ=446
        DCD     Reserved463_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[40] - inputs[40]) IRQ=447
        DCD     Reserved464_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[41] - inputs[41]) IRQ=448
        DCD     Reserved465_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[42] - inputs[42]) IRQ=449
        DCD     Reserved466_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[43] - inputs[43]) IRQ=450
        DCD     Reserved467_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[44] - inputs[44]) IRQ=451
        DCD     Reserved468_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[45] - inputs[45]) IRQ=452
        DCD     Reserved469_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[46] - inputs[46]) IRQ=453
        DCD     Reserved470_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[47] - inputs[47]) IRQ=454
        DCD     Reserved471_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[48] - inputs[48]) IRQ=455
        DCD     Reserved472_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[49] - inputs[49]) IRQ=456
        DCD     Reserved473_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[50] - inputs[50]) IRQ=457
        DCD     Reserved474_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[51] - inputs[51]) IRQ=458
        DCD     Reserved475_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[52] - inputs[52]) IRQ=459
        DCD     Reserved476_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[53] - inputs[53]) IRQ=460
        DCD     Reserved477_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[54] - inputs[54]) IRQ=461
        DCD     Reserved478_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[55] - inputs[55]) IRQ=462
        DCD     Reserved479_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[56] - inputs[56]) IRQ=463
        DCD     Reserved480_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[57] - inputs[57]) IRQ=464
        DCD     Reserved481_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[58] - inputs[58]) IRQ=465
        DCD     Reserved482_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[59] - inputs[59]) IRQ=466
        DCD     Reserved483_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[60] - inputs[60]) IRQ=467
        DCD     Reserved484_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[61] - inputs[61]) IRQ=468
        DCD     Reserved485_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[62] - inputs[62]) IRQ=469
        DCD     Reserved486_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[63] - inputs[63]) IRQ=470
        DCD     EDMA2_CH32_IRQHandler                         ;WAKEUPMIX EDMA2 channel 32 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[0] - inputs[64]) IRQ=471
        DCD     EDMA2_CH33_IRQHandler                         ;WAKEUPMIX EDMA2 channel 33 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[1] - inputs[65]) IRQ=472
        DCD     EDMA2_CH34_IRQHandler                         ;WAKEUPMIX EDMA2 channel 34 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[2] - inputs[66]) IRQ=473
        DCD     EDMA2_CH35_IRQHandler                         ;WAKEUPMIX EDMA2 channel 35 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[3] - inputs[67]) IRQ=474
        DCD     EDMA2_CH36_IRQHandler                         ;WAKEUPMIX EDMA2 channel 36 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[4] - inputs[68]) IRQ=475
        DCD     EDMA2_CH37_IRQHandler                         ;WAKEUPMIX EDMA2 channel 37 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[5] - inputs[69]) IRQ=476
        DCD     EDMA2_CH38_IRQHandler                         ;WAKEUPMIX EDMA2 channel 38 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[6] - inputs[70]) IRQ=477
        DCD     EDMA2_CH39_IRQHandler                         ;WAKEUPMIX EDMA2 channel 39 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[7] - inputs[71]) IRQ=478
        DCD     EDMA2_CH40_IRQHandler                         ;WAKEUPMIX EDMA2 channel 40 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[8] - inputs[72]) IRQ=479
        DCD     EDMA2_CH41_IRQHandler                         ;WAKEUPMIX EDMA2 channel 41 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[9] - inputs[73]) IRQ=480
        DCD     EDMA2_CH42_IRQHandler                         ;WAKEUPMIX EDMA2 channel 42 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[10] - inputs[74]) IRQ=481
        DCD     EDMA2_CH43_IRQHandler                         ;WAKEUPMIX EDMA2 channel 43 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[11] - inputs[75]) IRQ=482
        DCD     EDMA2_CH44_IRQHandler                         ;WAKEUPMIX EDMA2 channel 44 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[12] - inputs[76]) IRQ=483
        DCD     EDMA2_CH45_IRQHandler                         ;WAKEUPMIX EDMA2 channel 45 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[13] - inputs[77]) IRQ=484
        DCD     EDMA2_CH46_IRQHandler                         ;WAKEUPMIX EDMA2 channel 46 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[14] - inputs[78]) IRQ=485
        DCD     EDMA2_CH47_IRQHandler                         ;WAKEUPMIX EDMA2 channel 47 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[15] - inputs[79]) IRQ=486
        DCD     EDMA2_CH48_IRQHandler                         ;WAKEUPMIX EDMA2 channel 48 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[16] - inputs[80]) IRQ=487
        DCD     EDMA2_CH49_IRQHandler                         ;WAKEUPMIX EDMA2 channel 49 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[17] - inputs[81]) IRQ=488
        DCD     EDMA2_CH50_IRQHandler                         ;WAKEUPMIX EDMA2 channel 50 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[18] - inputs[82]) IRQ=489
        DCD     EDMA2_CH51_IRQHandler                         ;WAKEUPMIX EDMA2 channel 51 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[19] - inputs[83]) IRQ=490
        DCD     EDMA2_CH52_IRQHandler                         ;WAKEUPMIX EDMA2 channel 52 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[20] - inputs[84]) IRQ=491
        DCD     EDMA2_CH53_IRQHandler                         ;WAKEUPMIX EDMA2 channel 53 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[21] - inputs[85]) IRQ=492
        DCD     EDMA2_CH54_IRQHandler                         ;WAKEUPMIX EDMA2 channel 54 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[22] - inputs[86]) IRQ=493
        DCD     EDMA2_CH55_IRQHandler                         ;WAKEUPMIX EDMA2 channel 55 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[23] - inputs[87]) IRQ=494
        DCD     EDMA2_CH56_IRQHandler                         ;WAKEUPMIX EDMA2 channel 56 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[24] - inputs[88]) IRQ=495
        DCD     EDMA2_CH57_IRQHandler                         ;WAKEUPMIX EDMA2 channel 57 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[25] - inputs[89]) IRQ=496
        DCD     EDMA2_CH58_IRQHandler                         ;WAKEUPMIX EDMA2 channel 58 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[26] - inputs[90]) IRQ=497
        DCD     EDMA2_CH59_IRQHandler                         ;WAKEUPMIX EDMA2 channel 59 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[27] - inputs[91]) IRQ=498
        DCD     EDMA2_CH60_IRQHandler                         ;WAKEUPMIX EDMA2 channel 60 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[28] - inputs[92]) IRQ=499
        DCD     EDMA2_CH61_IRQHandler                         ;WAKEUPMIX EDMA2 channel 61 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[29] - inputs[93]) IRQ=500
        DCD     EDMA2_CH62_IRQHandler                         ;WAKEUPMIX EDMA2 channel 62 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[30] - inputs[94]) IRQ=501
        DCD     EDMA2_CH63_IRQHandler                         ;WAKEUPMIX EDMA2 channel 63 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[31] - inputs[95]) IRQ=502
        DCD     Reserved519_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[32] - inputs[96]) IRQ=503
        DCD     Reserved520_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[33] - inputs[97]) IRQ=504
        DCD     Reserved521_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[34] - inputs[98]) IRQ=505
        DCD     Reserved522_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[35] - inputs[99]) IRQ=506
        DCD     Reserved523_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[36] - inputs[100]) IRQ=507
        DCD     Reserved524_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[37] - inputs[101]) IRQ=508
        DCD     Reserved525_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[38] - inputs[102]) IRQ=509
        DCD     Reserved526_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[39] - inputs[103]) IRQ=510
        DCD     Reserved527_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[40] - inputs[104]) IRQ=511
        DCD     Reserved528_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[41] - inputs[105]) IRQ=512
        DCD     Reserved529_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[42] - inputs[106]) IRQ=513
        DCD     Reserved530_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[43] - inputs[107]) IRQ=514
        DCD     Reserved531_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[44] - inputs[108]) IRQ=515
        DCD     Reserved532_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[45] - inputs[109]) IRQ=516
        DCD     Reserved533_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[46] - inputs[110]) IRQ=517
        DCD     Reserved534_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[47] - inputs[111]) IRQ=518
        DCD     Reserved535_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[48] - inputs[112]) IRQ=519
        DCD     Reserved536_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[49] - inputs[113]) IRQ=520
        DCD     Reserved537_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[50] - inputs[114]) IRQ=521
        DCD     Reserved538_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[51] - inputs[115]) IRQ=522
        DCD     Reserved539_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[52] - inputs[116]) IRQ=523
        DCD     Reserved540_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[53] - inputs[117]) IRQ=524
        DCD     Reserved541_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[54] - inputs[118]) IRQ=525
        DCD     Reserved542_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[55] - inputs[119]) IRQ=526
        DCD     Reserved543_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[56] - inputs[120]) IRQ=527
        DCD     Reserved544_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[57] - inputs[121]) IRQ=528
        DCD     Reserved545_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[58] - inputs[122]) IRQ=529
        DCD     Reserved546_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[59] - inputs[123]) IRQ=530
        DCD     Reserved547_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[60] - inputs[124]) IRQ=531
        DCD     Reserved548_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[61] - inputs[125]) IRQ=532
        DCD     Reserved549_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[62] - inputs[126]) IRQ=533
        DCD     Reserved550_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[63] - inputs[127]) IRQ=534
        DCD     EDMA4_CH0_IRQHandler                          ;WAKEUPMIX EDMA4 channel 0 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[0] - inputs[128]) IRQ=535
        DCD     EDMA4_CH1_IRQHandler                          ;WAKEUPMIX EDMA4 channel 1 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[1] - inputs[129]) IRQ=536
        DCD     EDMA4_CH2_IRQHandler                          ;WAKEUPMIX EDMA4 channel 2 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[2] - inputs[130]) IRQ=537
        DCD     EDMA4_CH3_IRQHandler                          ;WAKEUPMIX EDMA4 channel 3 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[3] - inputs[131]) IRQ=538
        DCD     EDMA4_CH4_IRQHandler                          ;WAKEUPMIX EDMA4 channel 4 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[4] - inputs[132]) IRQ=539
        DCD     EDMA4_CH5_IRQHandler                          ;WAKEUPMIX EDMA4 channel 5 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[5] - inputs[133]) IRQ=540
        DCD     EDMA4_CH6_IRQHandler                          ;WAKEUPMIX EDMA4 channel 6 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[6] - inputs[134]) IRQ=541
        DCD     EDMA4_CH7_IRQHandler                          ;WAKEUPMIX EDMA4 channel 7 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[7] - inputs[135]) IRQ=542
        DCD     EDMA4_CH8_IRQHandler                          ;WAKEUPMIX EDMA4 channel 8 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[8] - inputs[136]) IRQ=543
        DCD     EDMA4_CH9_IRQHandler                          ;WAKEUPMIX EDMA4 channel 9 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[9] - inputs[137]) IRQ=544
        DCD     EDMA4_CH10_IRQHandler                         ;WAKEUPMIX EDMA4 channel 10 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[10] - inputs[138]) IRQ=545
        DCD     EDMA4_CH11_IRQHandler                         ;WAKEUPMIX EDMA4 channel 11 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[11] - inputs[139]) IRQ=546
        DCD     EDMA4_CH12_IRQHandler                         ;WAKEUPMIX EDMA4 channel 12 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[12] - inputs[140]) IRQ=547
        DCD     EDMA4_CH13_IRQHandler                         ;WAKEUPMIX EDMA4 channel 13 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[13] - inputs[141]) IRQ=548
        DCD     EDMA4_CH14_IRQHandler                         ;WAKEUPMIX EDMA4 channel 14 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[14] - inputs[142]) IRQ=549
        DCD     EDMA4_CH15_IRQHandler                         ;WAKEUPMIX EDMA4 channel 15 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[15] - inputs[143]) IRQ=550
        DCD     EDMA4_CH16_IRQHandler                         ;WAKEUPMIX EDMA4 channel 16 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[16] - inputs[144]) IRQ=551
        DCD     EDMA4_CH17_IRQHandler                         ;WAKEUPMIX EDMA4 channel 17 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[17] - inputs[145]) IRQ=552
        DCD     EDMA4_CH18_IRQHandler                         ;WAKEUPMIX EDMA4 channel 18 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[18] - inputs[146]) IRQ=553
        DCD     EDMA4_CH19_IRQHandler                         ;WAKEUPMIX EDMA4 channel 19 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[19] - inputs[147]) IRQ=554
        DCD     EDMA4_CH20_IRQHandler                         ;WAKEUPMIX EDMA4 channel 20 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[20] - inputs[148]) IRQ=555
        DCD     EDMA4_CH21_IRQHandler                         ;WAKEUPMIX EDMA4 channel 21 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[21] - inputs[149]) IRQ=556
        DCD     EDMA4_CH22_IRQHandler                         ;WAKEUPMIX EDMA4 channel 22 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[22] - inputs[150]) IRQ=557
        DCD     EDMA4_CH23_IRQHandler                         ;WAKEUPMIX EDMA4 channel 23 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[23] - inputs[151]) IRQ=558
        DCD     EDMA4_CH24_IRQHandler                         ;WAKEUPMIX EDMA4 channel 24 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[24] - inputs[152]) IRQ=559
        DCD     EDMA4_CH25_IRQHandler                         ;WAKEUPMIX EDMA4 channel 25 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[25] - inputs[153]) IRQ=560
        DCD     EDMA4_CH26_IRQHandler                         ;WAKEUPMIX EDMA4 channel 26 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[26] - inputs[154]) IRQ=561
        DCD     EDMA4_CH27_IRQHandler                         ;WAKEUPMIX EDMA4 channel 27 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[27] - inputs[155]) IRQ=562
        DCD     EDMA4_CH28_IRQHandler                         ;WAKEUPMIX EDMA4 channel 28 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[28] - inputs[156]) IRQ=563
        DCD     EDMA4_CH29_IRQHandler                         ;WAKEUPMIX EDMA4 channel 29 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[29] - inputs[157]) IRQ=564
        DCD     EDMA4_CH30_IRQHandler                         ;WAKEUPMIX EDMA4 channel 30 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[30] - inputs[158]) IRQ=565
        DCD     EDMA4_CH31_IRQHandler                         ;WAKEUPMIX EDMA4 channel 31 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[31] - inputs[159]) IRQ=566
        DCD     Reserved583_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[32] - inputs[160]) IRQ=567
        DCD     Reserved584_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[33] - inputs[161]) IRQ=568
        DCD     Reserved585_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[34] - inputs[162]) IRQ=569
        DCD     Reserved586_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[35] - inputs[163]) IRQ=570
        DCD     Reserved587_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[36] - inputs[164]) IRQ=571
        DCD     Reserved588_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[37] - inputs[165]) IRQ=572
        DCD     Reserved589_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[38] - inputs[166]) IRQ=573
        DCD     Reserved590_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[39] - inputs[167]) IRQ=574
        DCD     Reserved591_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[40] - inputs[168]) IRQ=575
        DCD     Reserved592_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[41] - inputs[169]) IRQ=576
        DCD     Reserved593_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[42] - inputs[170]) IRQ=577
        DCD     Reserved594_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[43] - inputs[171]) IRQ=578
        DCD     Reserved595_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[44] - inputs[172]) IRQ=579
        DCD     Reserved596_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[45] - inputs[173]) IRQ=580
        DCD     Reserved597_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[46] - inputs[174]) IRQ=581
        DCD     Reserved598_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[47] - inputs[175]) IRQ=582
        DCD     Reserved599_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[48] - inputs[176]) IRQ=583
        DCD     Reserved600_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[49] - inputs[177]) IRQ=584
        DCD     Reserved601_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[50] - inputs[178]) IRQ=585
        DCD     Reserved602_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[51] - inputs[179]) IRQ=586
        DCD     Reserved603_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[52] - inputs[180]) IRQ=587
        DCD     Reserved604_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[53] - inputs[181]) IRQ=588
        DCD     Reserved605_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[54] - inputs[182]) IRQ=589
        DCD     Reserved606_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[55] - inputs[183]) IRQ=590
        DCD     Reserved607_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[56] - inputs[184]) IRQ=591
        DCD     Reserved608_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[57] - inputs[185]) IRQ=592
        DCD     Reserved609_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[58] - inputs[186]) IRQ=593
        DCD     Reserved610_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[59] - inputs[187]) IRQ=594
        DCD     Reserved611_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[60] - inputs[188]) IRQ=595
        DCD     Reserved612_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[61] - inputs[189]) IRQ=596
        DCD     Reserved613_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[62] - inputs[190]) IRQ=597
        DCD     Reserved614_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[63] - inputs[191]) IRQ=598
        DCD     EDMA4_CH32_IRQHandler                         ;WAKEUPMIX EDMA4 channel 32 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[0] - inputs[192]) IRQ=599
        DCD     EDMA4_CH33_IRQHandler                         ;WAKEUPMIX EDMA4 channel 33 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[1] - inputs[193]) IRQ=600
        DCD     EDMA4_CH34_IRQHandler                         ;WAKEUPMIX EDMA4 channel 34 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[2] - inputs[194]) IRQ=601
        DCD     EDMA4_CH35_IRQHandler                         ;WAKEUPMIX EDMA4 channel 35 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[3] - inputs[195]) IRQ=602
        DCD     EDMA4_CH36_IRQHandler                         ;WAKEUPMIX EDMA4 channel 36 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[4] - inputs[196]) IRQ=603
        DCD     EDMA4_CH37_IRQHandler                         ;WAKEUPMIX EDMA4 channel 37 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[5] - inputs[197]) IRQ=604
        DCD     EDMA4_CH38_IRQHandler                         ;WAKEUPMIX EDMA4 channel 38 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[6] - inputs[198]) IRQ=605
        DCD     EDMA4_CH39_IRQHandler                         ;WAKEUPMIX EDMA4 channel 39 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[7] - inputs[199]) IRQ=606
        DCD     EDMA4_CH40_IRQHandler                         ;WAKEUPMIX EDMA4 channel 40 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[8] - inputs[200]) IRQ=607
        DCD     EDMA4_CH41_IRQHandler                         ;WAKEUPMIX EDMA4 channel 41 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[9] - inputs[201]) IRQ=608
        DCD     EDMA4_CH42_IRQHandler                         ;WAKEUPMIX EDMA4 channel 42 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[10] - inputs[202]) IRQ=609
        DCD     EDMA4_CH43_IRQHandler                         ;WAKEUPMIX EDMA4 channel 43 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[11] - inputs[203]) IRQ=610
        DCD     EDMA4_CH44_IRQHandler                         ;WAKEUPMIX EDMA4 channel 44 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[12] - inputs[204]) IRQ=611
        DCD     EDMA4_CH45_IRQHandler                         ;WAKEUPMIX EDMA4 channel 45 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[13] - inputs[205]) IRQ=612
        DCD     EDMA4_CH46_IRQHandler                         ;WAKEUPMIX EDMA4 channel 46 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[14] - inputs[206]) IRQ=613
        DCD     EDMA4_CH47_IRQHandler                         ;WAKEUPMIX EDMA4 channel 47 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[15] - inputs[207]) IRQ=614
        DCD     EDMA4_CH48_IRQHandler                         ;WAKEUPMIX EDMA4 channel 48 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[16] - inputs[208]) IRQ=615
        DCD     EDMA4_CH49_IRQHandler                         ;WAKEUPMIX EDMA4 channel 49 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[17] - inputs[209]) IRQ=616
        DCD     EDMA4_CH50_IRQHandler                         ;WAKEUPMIX EDMA4 channel 50 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[18] - inputs[210]) IRQ=617
        DCD     EDMA4_CH51_IRQHandler                         ;WAKEUPMIX EDMA4 channel 51 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[19] - inputs[211]) IRQ=618
        DCD     EDMA4_CH52_IRQHandler                         ;WAKEUPMIX EDMA4 channel 52 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[20] - inputs[212]) IRQ=619
        DCD     EDMA4_CH53_IRQHandler                         ;WAKEUPMIX EDMA4 channel 53 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[21] - inputs[213]) IRQ=620
        DCD     EDMA4_CH54_IRQHandler                         ;WAKEUPMIX EDMA4 channel 54 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[22] - inputs[214]) IRQ=621
        DCD     EDMA4_CH55_IRQHandler                         ;WAKEUPMIX EDMA4 channel 55 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[23] - inputs[215]) IRQ=622
        DCD     EDMA4_CH56_IRQHandler                         ;WAKEUPMIX EDMA4 channel 56 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[24] - inputs[216]) IRQ=623
        DCD     EDMA4_CH57_IRQHandler                         ;WAKEUPMIX EDMA4 channel 57 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[25] - inputs[217]) IRQ=624
        DCD     EDMA4_CH58_IRQHandler                         ;WAKEUPMIX EDMA4 channel 58 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[26] - inputs[218]) IRQ=625
        DCD     EDMA4_CH59_IRQHandler                         ;WAKEUPMIX EDMA4 channel 59 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[27] - inputs[219]) IRQ=626
        DCD     EDMA4_CH60_IRQHandler                         ;WAKEUPMIX EDMA4 channel 60 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[28] - inputs[220]) IRQ=627
        DCD     EDMA4_CH61_IRQHandler                         ;WAKEUPMIX EDMA4 channel 61 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[29] - inputs[221]) IRQ=628
        DCD     EDMA4_CH62_IRQHandler                         ;WAKEUPMIX EDMA4 channel 62 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[30] - inputs[222]) IRQ=629
        DCD     EDMA4_CH63_IRQHandler                         ;WAKEUPMIX EDMA4 channel 63 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[31] - inputs[223]) IRQ=630
        DCD     Reserved647_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[32] - inputs[224]) IRQ=631
        DCD     Reserved648_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[33] - inputs[225]) IRQ=632
        DCD     Reserved649_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[34] - inputs[226]) IRQ=633
        DCD     Reserved650_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[35] - inputs[227]) IRQ=634
        DCD     Reserved651_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[36] - inputs[228]) IRQ=635
        DCD     Reserved652_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[37] - inputs[229]) IRQ=636
        DCD     Reserved653_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[38] - inputs[230]) IRQ=637
        DCD     Reserved654_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[39] - inputs[231]) IRQ=638
        DCD     Reserved655_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[40] - inputs[232]) IRQ=639
        DCD     Reserved656_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[41] - inputs[233]) IRQ=640
        DCD     Reserved657_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[42] - inputs[234]) IRQ=641
        DCD     Reserved658_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[43] - inputs[235]) IRQ=642
        DCD     Reserved659_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[44] - inputs[236]) IRQ=643
        DCD     Reserved660_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[45] - inputs[237]) IRQ=644
        DCD     Reserved661_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[46] - inputs[238]) IRQ=645
        DCD     Reserved662_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[47] - inputs[239]) IRQ=646
        DCD     Reserved663_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[48] - inputs[240]) IRQ=647
        DCD     Reserved664_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[49] - inputs[241]) IRQ=648
        DCD     Reserved665_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[50] - inputs[242]) IRQ=649
        DCD     Reserved666_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[51] - inputs[243]) IRQ=650
        DCD     Reserved667_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[52] - inputs[244]) IRQ=651
        DCD     Reserved668_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[53] - inputs[245]) IRQ=652
        DCD     Reserved669_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[54] - inputs[246]) IRQ=653
        DCD     Reserved670_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[55] - inputs[247]) IRQ=654
        DCD     Reserved671_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[56] - inputs[248]) IRQ=655
        DCD     Reserved672_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[57] - inputs[249]) IRQ=656
        DCD     Reserved673_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[58] - inputs[250]) IRQ=657
        DCD     Reserved674_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[59] - inputs[251]) IRQ=658
        DCD     Reserved675_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[60] - inputs[252]) IRQ=659
        DCD     Reserved676_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[61] - inputs[253]) IRQ=660
        DCD     Reserved677_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[62] - inputs[254]) IRQ=661
        DCD     Reserved678_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[63] - inputs[255]) IRQ=662
        DCD     EDMA3_CH0_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 0 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[0] - inputs[256]) IRQ=663
        DCD     EDMA3_CH1_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 1 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[1] - inputs[257]) IRQ=664
        DCD     EDMA3_CH2_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 2 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[2] - inputs[258]) IRQ=665
        DCD     EDMA3_CH3_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 3 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[3] - inputs[259]) IRQ=666
        DCD     EDMA3_CH4_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 4 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[4] - inputs[260]) IRQ=667
        DCD     EDMA3_CH5_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 5 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[5] - inputs[261]) IRQ=668
        DCD     EDMA3_CH6_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 6 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[6] - inputs[262]) IRQ=669
        DCD     EDMA3_CH7_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 7 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[7] - inputs[263]) IRQ=670
        DCD     EDMA3_CH8_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 8 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[8] - inputs[264]) IRQ=671
        DCD     EDMA3_CH9_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 9 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[9] - inputs[265]) IRQ=672
        DCD     EDMA3_CH10_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 10 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[10] - inputs[266]) IRQ=673
        DCD     EDMA3_CH11_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 11 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[11] - inputs[267]) IRQ=674
        DCD     EDMA3_CH12_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 12 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[12] - inputs[268]) IRQ=675
        DCD     EDMA3_CH13_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 13 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[13] - inputs[269]) IRQ=676
        DCD     EDMA3_CH14_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 14 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[14] - inputs[270]) IRQ=677
        DCD     EDMA3_CH15_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 15 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[15] - inputs[271]) IRQ=678
        DCD     EDMA3_CH16_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 16 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[16] - inputs[272]) IRQ=679
        DCD     EDMA3_CH17_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 17 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[17] - inputs[273]) IRQ=680
        DCD     EDMA3_CH18_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 18 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[18] - inputs[274]) IRQ=681
        DCD     EDMA3_CH19_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 19 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[19] - inputs[275]) IRQ=682
        DCD     EDMA3_CH20_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 20 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[20] - inputs[276]) IRQ=683
        DCD     EDMA3_CH21_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 21 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[21] - inputs[277]) IRQ=684
        DCD     EDMA3_CH22_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 22 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[22] - inputs[278]) IRQ=685
        DCD     EDMA3_CH23_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 23 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[23] - inputs[279]) IRQ=686
        DCD     EDMA3_CH24_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 24 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[24] - inputs[280]) IRQ=687
        DCD     EDMA3_CH25_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 25 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[25] - inputs[281]) IRQ=688
        DCD     EDMA3_CH26_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 26 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[26] - inputs[282]) IRQ=689
        DCD     EDMA3_CH27_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 27 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[27] - inputs[283]) IRQ=690
        DCD     EDMA3_CH28_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 28 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[28] - inputs[284]) IRQ=691
        DCD     EDMA3_CH29_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 29 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[29] - inputs[285]) IRQ=692
        DCD     EDMA3_CH30_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 30 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[30] - inputs[286]) IRQ=693
        DCD     EDMA3_CH31_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 31 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[31] - inputs[287]) IRQ=694
        DCD     Reserved711_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[32] - inputs[288]) IRQ=695
        DCD     Reserved712_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[33] - inputs[289]) IRQ=696
        DCD     Reserved713_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[34] - inputs[290]) IRQ=697
        DCD     Reserved714_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[35] - inputs[291]) IRQ=698
        DCD     Reserved715_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[36] - inputs[292]) IRQ=699
        DCD     Reserved716_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[37] - inputs[293]) IRQ=700
        DCD     Reserved717_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[38] - inputs[294]) IRQ=701
        DCD     Reserved718_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[39] - inputs[295]) IRQ=702
        DCD     Reserved719_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[40] - inputs[296]) IRQ=703
        DCD     Reserved720_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[41] - inputs[297]) IRQ=704
        DCD     Reserved721_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[42] - inputs[298]) IRQ=705
        DCD     Reserved722_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[43] - inputs[299]) IRQ=706
        DCD     Reserved723_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[44] - inputs[300]) IRQ=707
        DCD     Reserved724_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[45] - inputs[301]) IRQ=708
        DCD     Reserved725_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[46] - inputs[302]) IRQ=709
        DCD     Reserved726_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[47] - inputs[303]) IRQ=710
        DCD     Reserved727_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[48] - inputs[304]) IRQ=711
        DCD     Reserved728_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[49] - inputs[305]) IRQ=712
        DCD     Reserved729_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[50] - inputs[306]) IRQ=713
        DCD     Reserved730_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[51] - inputs[307]) IRQ=714
        DCD     Reserved731_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[52] - inputs[308]) IRQ=715
        DCD     Reserved732_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[53] - inputs[309]) IRQ=716
        DCD     Reserved733_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[54] - inputs[310]) IRQ=717
        DCD     Reserved734_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[55] - inputs[311]) IRQ=718
        DCD     Reserved735_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[56] - inputs[312]) IRQ=719
        DCD     Reserved736_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[57] - inputs[313]) IRQ=720
        DCD     Reserved737_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[58] - inputs[314]) IRQ=721
        DCD     Reserved738_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[59] - inputs[315]) IRQ=722
        DCD     Reserved739_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[60] - inputs[316]) IRQ=723
        DCD     Reserved740_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[61] - inputs[317]) IRQ=724
        DCD     Reserved741_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[62] - inputs[318]) IRQ=725
        DCD     Reserved742_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[63] - inputs[319]) IRQ=726
        DCD     EDMA3_CH32_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 32 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[0] - inputs[320]) IRQ=727
        DCD     EDMA3_CH33_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 33 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[1] - inputs[321]) IRQ=728
        DCD     EDMA3_CH34_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 34 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[2] - inputs[322]) IRQ=729
        DCD     EDMA3_CH35_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 35 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[3] - inputs[323]) IRQ=730
        DCD     EDMA3_CH36_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 36 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[4] - inputs[324]) IRQ=731
        DCD     EDMA3_CH37_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 37 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[5] - inputs[325]) IRQ=732
        DCD     EDMA3_CH38_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 38 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[6] - inputs[326]) IRQ=733
        DCD     EDMA3_CH39_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 39 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[7] - inputs[327]) IRQ=734
        DCD     EDMA3_CH40_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 40 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[8] - inputs[328]) IRQ=735
        DCD     EDMA3_CH41_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 41 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[9] - inputs[329]) IRQ=736
        DCD     EDMA3_CH42_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 42 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[10] - inputs[330]) IRQ=737
        DCD     EDMA3_CH43_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 43 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[11] - inputs[331]) IRQ=738
        DCD     EDMA3_CH44_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 44 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[12] - inputs[332]) IRQ=739
        DCD     EDMA3_CH45_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 45 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[13] - inputs[333]) IRQ=740
        DCD     EDMA3_CH46_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 46 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[14] - inputs[334]) IRQ=741
        DCD     EDMA3_CH47_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 47 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[15] - inputs[335]) IRQ=742
        DCD     EDMA3_CH48_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 48 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[16] - inputs[336]) IRQ=743
        DCD     EDMA3_CH49_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 49 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[17] - inputs[337]) IRQ=744
        DCD     EDMA3_CH50_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 50 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[18] - inputs[338]) IRQ=745
        DCD     EDMA3_CH51_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 51 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[19] - inputs[339]) IRQ=746
        DCD     EDMA3_CH52_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 52 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[20] - inputs[340]) IRQ=747
        DCD     EDMA3_CH53_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 53 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[21] - inputs[341]) IRQ=748
        DCD     EDMA3_CH54_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 54 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[22] - inputs[342]) IRQ=749
        DCD     EDMA3_CH55_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 55 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[23] - inputs[343]) IRQ=750
        DCD     EDMA3_CH56_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 56 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[24] - inputs[344]) IRQ=751
        DCD     EDMA3_CH57_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 57 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[25] - inputs[345]) IRQ=752
        DCD     EDMA3_CH58_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 58 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[26] - inputs[346]) IRQ=753
        DCD     EDMA3_CH59_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 59 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[27] - inputs[347]) IRQ=754
        DCD     EDMA3_CH60_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 60 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[28] - inputs[348]) IRQ=755
        DCD     EDMA3_CH61_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 61 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[29] - inputs[349]) IRQ=756
        DCD     EDMA3_CH62_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 62 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[30] - inputs[350]) IRQ=757
        DCD     EDMA3_CH63_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 63 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[31] - inputs[351]) IRQ=758
        DCD     Reserved775_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[32] - inputs[352]) IRQ=759
        DCD     Reserved776_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[33] - inputs[353]) IRQ=760
        DCD     Reserved777_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[34] - inputs[354]) IRQ=761
        DCD     Reserved778_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[35] - inputs[355]) IRQ=762
        DCD     Reserved779_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[36] - inputs[356]) IRQ=763
        DCD     Reserved780_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[37] - inputs[357]) IRQ=764
        DCD     Reserved781_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[38] - inputs[358]) IRQ=765
        DCD     Reserved782_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[39] - inputs[359]) IRQ=766
        DCD     Reserved783_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[40] - inputs[360]) IRQ=767
        DCD     Reserved784_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[41] - inputs[361]) IRQ=768
        DCD     Reserved785_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[42] - inputs[362]) IRQ=769
        DCD     Reserved786_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[43] - inputs[363]) IRQ=770
        DCD     Reserved787_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[44] - inputs[364]) IRQ=771
        DCD     Reserved788_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[45] - inputs[365]) IRQ=772
        DCD     Reserved789_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[46] - inputs[366]) IRQ=773
        DCD     Reserved790_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[47] - inputs[367]) IRQ=774
        DCD     Reserved791_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[48] - inputs[368]) IRQ=775
        DCD     Reserved792_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[49] - inputs[369]) IRQ=776
        DCD     Reserved793_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[50] - inputs[370]) IRQ=777
        DCD     Reserved794_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[51] - inputs[371]) IRQ=778
        DCD     Reserved795_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[52] - inputs[372]) IRQ=779
        DCD     Reserved796_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[53] - inputs[373]) IRQ=780
        DCD     Reserved797_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[54] - inputs[374]) IRQ=781
        DCD     Reserved798_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[55] - inputs[375]) IRQ=782
        DCD     Reserved799_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[56] - inputs[376]) IRQ=783
        DCD     Reserved800_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[57] - inputs[377]) IRQ=784
        DCD     Reserved801_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[58] - inputs[378]) IRQ=785
        DCD     Reserved802_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[59] - inputs[379]) IRQ=786
        DCD     Reserved803_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[60] - inputs[380]) IRQ=787
        DCD     Reserved804_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[61] - inputs[381]) IRQ=788
        DCD     Reserved805_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[62] - inputs[382]) IRQ=789
        DCD     Reserved806_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[63] - inputs[383]) IRQ=790
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

        PUBWEAK SecureFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SecureFault_Handler
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
        PUBWEAK IRQSTEERM33_CH0_IRQHandler
        PUBWEAK IRQSTEERM33_CH0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM33_CH0_IRQHandler
        LDR     R0, =IRQSTEERM33_CH0_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM33_CH1_IRQHandler
        PUBWEAK IRQSTEERM33_CH1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM33_CH1_IRQHandler
        LDR     R0, =IRQSTEERM33_CH1_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM33_CH2_IRQHandler
        PUBWEAK IRQSTEERM33_CH2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM33_CH2_IRQHandler
        LDR     R0, =IRQSTEERM33_CH2_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM33_CH3_IRQHandler
        PUBWEAK IRQSTEERM33_CH3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM33_CH3_IRQHandler
        LDR     R0, =IRQSTEERM33_CH3_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM33_CH4_IRQHandler
        PUBWEAK IRQSTEERM33_CH4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM33_CH4_IRQHandler
        LDR     R0, =IRQSTEERM33_CH4_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM33_CH5_IRQHandler
        PUBWEAK IRQSTEERM33_CH5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM33_CH5_IRQHandler
        LDR     R0, =IRQSTEERM33_CH5_DriverIRQHandler
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
        PUBWEAK MSGINTR2_IRQHandler
        PUBWEAK MSGINTR3_IRQHandler
        PUBWEAK MSGINTR4_IRQHandler
        PUBWEAK MSGINTR5_IRQHandler
        PUBWEAK MSGINTR6_IRQHandler
        PUBWEAK MSGINTR7_IRQHandler
        PUBWEAK MSGINTR8_IRQHandler
        PUBWEAK V2X_FH_MU_APCH1_IRQHandler
        PUBWEAK V2X_FH_MU_APHSM2_IRQHandler
        PUBWEAK Reserved319_IRQHandler
        PUBWEAK Reserved320_IRQHandler
        PUBWEAK Reserved321_IRQHandler
        PUBWEAK Reserved322_IRQHandler
        PUBWEAK Reserved323_IRQHandler
        PUBWEAK GPC_SM_REQ_IRQHandler
        PUBWEAK EDMA1_ERROR_IRQHandler
        PUBWEAK EDMA1_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_ERROR_IRQHandler
        LDR     R0, =EDMA1_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved326_IRQHandler
        PUBWEAK Reserved327_IRQHandler
        PUBWEAK Reserved328_IRQHandler
        PUBWEAK Reserved329_IRQHandler
        PUBWEAK Reserved330_IRQHandler
        PUBWEAK Reserved331_IRQHandler
        PUBWEAK Reserved332_IRQHandler
        PUBWEAK Reserved333_IRQHandler
        PUBWEAK Reserved334_IRQHandler
        PUBWEAK Reserved335_IRQHandler
        PUBWEAK Reserved336_IRQHandler
        PUBWEAK Reserved337_IRQHandler
        PUBWEAK Reserved338_IRQHandler
        PUBWEAK Reserved339_IRQHandler
        PUBWEAK Reserved340_IRQHandler
        PUBWEAK Reserved341_IRQHandler
        PUBWEAK EDMA3_ERROR_IRQHandler
        PUBWEAK EDMA3_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_ERROR_IRQHandler
        LDR     R0, =EDMA3_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved343_IRQHandler
        PUBWEAK M33_TCM_ERROR_IRQHandler
        PUBWEAK Reserved345_IRQHandler
        PUBWEAK Reserved346_IRQHandler
        PUBWEAK M33_SYNC_TCM_ERROR_IRQHandler
        PUBWEAK ONE_POINT_FIVE_MB_OCRAM_ERROR_IRQHandler
        PUBWEAK Reserved349_IRQHandler
        PUBWEAK GIC700_FAULT_IRQHandler
        PUBWEAK M33_MCM_IRQHandler
        PUBWEAK M33_SYNC_MCM_IRQHandler
        PUBWEAK ONE_POINT_FIVE_MB_SRAM_MCM_IRQHandler
        PUBWEAK M7MIX0_MCM_IRQHandler
        PUBWEAK M7MIX1_MCM_IRQHandler
        PUBWEAK OCRAM_ECC_SINGLE_BIT_ERROR_IRQHandler
        PUBWEAK GIC700_ERROR_IRQHandler
        PUBWEAK SFA_IRQHandler
        PUBWEAK TMPSNS_THR1_IRQHandler
        PUBWEAK TMPSNS_THR2_IRQHandler
        PUBWEAK Reserved361_IRQHandler
        PUBWEAK Reserved362_IRQHandler
        PUBWEAK Reserved363_IRQHandler
        PUBWEAK Reserved364_IRQHandler
        PUBWEAK CM33_0_SYSRESETREQ_IRQHandler
        PUBWEAK CM33_0_LOCKUP_IRQHandler
        PUBWEAK CM7_0_SYSRESETREQ_IRQHandler
        PUBWEAK CM7_0_LOCKUP_IRQHandler
        PUBWEAK CM33_1_SYSRESETREQ_IRQHandler
        PUBWEAK CM33_1_LOCKUP_IRQHandler
        PUBWEAK CM7_1_SYSRESETREQ_IRQHandler
        PUBWEAK CM7_1_LOCKUP_IRQHandler
        PUBWEAK SOC_RESET_WO_NETC_IRQHandler
        PUBWEAK Reserved374_IRQHandler
        PUBWEAK Reserved375_IRQHandler
        PUBWEAK PCIE1_INTA_IRQHandler
        PUBWEAK PCIE1_INTB_IRQHandler
        PUBWEAK PCIE1_INTC_IRQHandler
        PUBWEAK PCIE1_INTD_IRQHandler
        PUBWEAK Reserved380_IRQHandler
        PUBWEAK Reserved381_IRQHandler
        PUBWEAK PCIE2_INTA_IRQHandler
        PUBWEAK PCIE2_INTB_IRQHandler
        PUBWEAK PCIE2_INTC_IRQHandler
        PUBWEAK PCIE2_INTD_IRQHandler
        PUBWEAK Reserved386_IRQHandler
        PUBWEAK Reserved387_IRQHandler
        PUBWEAK Reserved388_IRQHandler
        PUBWEAK NPUMIX_FUNC_IRQHandler
        PUBWEAK Reserved390_IRQHandler
        PUBWEAK Reserved391_IRQHandler
        PUBWEAK Reserved392_IRQHandler
        PUBWEAK DCIF_CPU_DOMAIN0_IRQHandler
        PUBWEAK DCIF_CPU_DOMAIN1_IRQHandler
        PUBWEAK DCIF_CPU_DOMAIN2_IRQHandler
        PUBWEAK Reserved396_IRQHandler
        PUBWEAK Reserved397_IRQHandler
        PUBWEAK PXP_0_IRQHandler
        PUBWEAK PXP_1_IRQHandler
        PUBWEAK Reserved400_IRQHandler
        PUBWEAK Reserved401_IRQHandler
        PUBWEAK Reserved402_IRQHandler
        PUBWEAK Reserved403_IRQHandler
        PUBWEAK Reserved404_IRQHandler
        PUBWEAK Reserved405_IRQHandler
        PUBWEAK XSPI1_IRQHandler
        PUBWEAK XSPI1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
XSPI1_IRQHandler
        LDR     R0, =XSPI1_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved407_IRQHandler
        PUBWEAK Reserved408_IRQHandler
        PUBWEAK Reserved409_IRQHandler
        PUBWEAK Reserved410_IRQHandler
        PUBWEAK XSPI2_IRQHandler
        PUBWEAK XSPI2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
XSPI2_IRQHandler
        LDR     R0, =XSPI2_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved412_IRQHandler
        PUBWEAK Reserved413_IRQHandler
        PUBWEAK Reserved414_IRQHandler
        PUBWEAK Reserved415_IRQHandler
        PUBWEAK Reserved416_IRQHandler
        PUBWEAK Reserved417_IRQHandler
        PUBWEAK Reserved418_IRQHandler
        PUBWEAK Reserved419_IRQHandler
        PUBWEAK Reserved420_IRQHandler
        PUBWEAK Reserved421_IRQHandler
        PUBWEAK Reserved422_IRQHandler
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

        PUBWEAK Reserved455_IRQHandler
        PUBWEAK Reserved456_IRQHandler
        PUBWEAK Reserved457_IRQHandler
        PUBWEAK Reserved458_IRQHandler
        PUBWEAK Reserved459_IRQHandler
        PUBWEAK Reserved460_IRQHandler
        PUBWEAK Reserved461_IRQHandler
        PUBWEAK Reserved462_IRQHandler
        PUBWEAK Reserved463_IRQHandler
        PUBWEAK Reserved464_IRQHandler
        PUBWEAK Reserved465_IRQHandler
        PUBWEAK Reserved466_IRQHandler
        PUBWEAK Reserved467_IRQHandler
        PUBWEAK Reserved468_IRQHandler
        PUBWEAK Reserved469_IRQHandler
        PUBWEAK Reserved470_IRQHandler
        PUBWEAK Reserved471_IRQHandler
        PUBWEAK Reserved472_IRQHandler
        PUBWEAK Reserved473_IRQHandler
        PUBWEAK Reserved474_IRQHandler
        PUBWEAK Reserved475_IRQHandler
        PUBWEAK Reserved476_IRQHandler
        PUBWEAK Reserved477_IRQHandler
        PUBWEAK Reserved478_IRQHandler
        PUBWEAK Reserved479_IRQHandler
        PUBWEAK Reserved480_IRQHandler
        PUBWEAK Reserved481_IRQHandler
        PUBWEAK Reserved482_IRQHandler
        PUBWEAK Reserved483_IRQHandler
        PUBWEAK Reserved484_IRQHandler
        PUBWEAK Reserved485_IRQHandler
        PUBWEAK Reserved486_IRQHandler
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

        PUBWEAK Reserved519_IRQHandler
        PUBWEAK Reserved520_IRQHandler
        PUBWEAK Reserved521_IRQHandler
        PUBWEAK Reserved522_IRQHandler
        PUBWEAK Reserved523_IRQHandler
        PUBWEAK Reserved524_IRQHandler
        PUBWEAK Reserved525_IRQHandler
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

        PUBWEAK Reserved583_IRQHandler
        PUBWEAK Reserved584_IRQHandler
        PUBWEAK Reserved585_IRQHandler
        PUBWEAK Reserved586_IRQHandler
        PUBWEAK Reserved587_IRQHandler
        PUBWEAK Reserved588_IRQHandler
        PUBWEAK Reserved589_IRQHandler
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

        PUBWEAK Reserved647_IRQHandler
        PUBWEAK Reserved648_IRQHandler
        PUBWEAK Reserved649_IRQHandler
        PUBWEAK Reserved650_IRQHandler
        PUBWEAK Reserved651_IRQHandler
        PUBWEAK Reserved652_IRQHandler
        PUBWEAK Reserved653_IRQHandler
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
IRQSTEERM33_CH0_DriverIRQHandler
IRQSTEERM33_CH1_DriverIRQHandler
IRQSTEERM33_CH2_DriverIRQHandler
IRQSTEERM33_CH3_DriverIRQHandler
IRQSTEERM33_CH4_DriverIRQHandler
IRQSTEERM33_CH5_DriverIRQHandler
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
MSGINTR2_IRQHandler
MSGINTR3_IRQHandler
MSGINTR4_IRQHandler
MSGINTR5_IRQHandler
MSGINTR6_IRQHandler
MSGINTR7_IRQHandler
MSGINTR8_IRQHandler
V2X_FH_MU_APCH1_IRQHandler
V2X_FH_MU_APHSM2_IRQHandler
Reserved319_IRQHandler
Reserved320_IRQHandler
Reserved321_IRQHandler
Reserved322_IRQHandler
Reserved323_IRQHandler
GPC_SM_REQ_IRQHandler
EDMA1_ERROR_DriverIRQHandler
Reserved326_IRQHandler
Reserved327_IRQHandler
Reserved328_IRQHandler
Reserved329_IRQHandler
Reserved330_IRQHandler
Reserved331_IRQHandler
Reserved332_IRQHandler
Reserved333_IRQHandler
Reserved334_IRQHandler
Reserved335_IRQHandler
Reserved336_IRQHandler
Reserved337_IRQHandler
Reserved338_IRQHandler
Reserved339_IRQHandler
Reserved340_IRQHandler
Reserved341_IRQHandler
EDMA3_ERROR_DriverIRQHandler
Reserved343_IRQHandler
M33_TCM_ERROR_IRQHandler
Reserved345_IRQHandler
Reserved346_IRQHandler
M33_SYNC_TCM_ERROR_IRQHandler
ONE_POINT_FIVE_MB_OCRAM_ERROR_IRQHandler
Reserved349_IRQHandler
GIC700_FAULT_IRQHandler
M33_MCM_IRQHandler
M33_SYNC_MCM_IRQHandler
ONE_POINT_FIVE_MB_SRAM_MCM_IRQHandler
M7MIX0_MCM_IRQHandler
M7MIX1_MCM_IRQHandler
OCRAM_ECC_SINGLE_BIT_ERROR_IRQHandler
GIC700_ERROR_IRQHandler
SFA_IRQHandler
TMPSNS_THR1_IRQHandler
TMPSNS_THR2_IRQHandler
Reserved361_IRQHandler
Reserved362_IRQHandler
Reserved363_IRQHandler
Reserved364_IRQHandler
CM33_0_SYSRESETREQ_IRQHandler
CM33_0_LOCKUP_IRQHandler
CM7_0_SYSRESETREQ_IRQHandler
CM7_0_LOCKUP_IRQHandler
CM33_1_SYSRESETREQ_IRQHandler
CM33_1_LOCKUP_IRQHandler
CM7_1_SYSRESETREQ_IRQHandler
CM7_1_LOCKUP_IRQHandler
SOC_RESET_WO_NETC_IRQHandler
Reserved374_IRQHandler
Reserved375_IRQHandler
PCIE1_INTA_IRQHandler
PCIE1_INTB_IRQHandler
PCIE1_INTC_IRQHandler
PCIE1_INTD_IRQHandler
Reserved380_IRQHandler
Reserved381_IRQHandler
PCIE2_INTA_IRQHandler
PCIE2_INTB_IRQHandler
PCIE2_INTC_IRQHandler
PCIE2_INTD_IRQHandler
Reserved386_IRQHandler
Reserved387_IRQHandler
Reserved388_IRQHandler
NPUMIX_FUNC_IRQHandler
Reserved390_IRQHandler
Reserved391_IRQHandler
Reserved392_IRQHandler
DCIF_CPU_DOMAIN0_IRQHandler
DCIF_CPU_DOMAIN1_IRQHandler
DCIF_CPU_DOMAIN2_IRQHandler
Reserved396_IRQHandler
Reserved397_IRQHandler
PXP_0_IRQHandler
PXP_1_IRQHandler
Reserved400_IRQHandler
Reserved401_IRQHandler
Reserved402_IRQHandler
Reserved403_IRQHandler
Reserved404_IRQHandler
Reserved405_IRQHandler
XSPI1_DriverIRQHandler
Reserved407_IRQHandler
Reserved408_IRQHandler
Reserved409_IRQHandler
Reserved410_IRQHandler
XSPI2_DriverIRQHandler
Reserved412_IRQHandler
Reserved413_IRQHandler
Reserved414_IRQHandler
Reserved415_IRQHandler
Reserved416_IRQHandler
Reserved417_IRQHandler
Reserved418_IRQHandler
Reserved419_IRQHandler
Reserved420_IRQHandler
Reserved421_IRQHandler
Reserved422_IRQHandler
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
Reserved455_IRQHandler
Reserved456_IRQHandler
Reserved457_IRQHandler
Reserved458_IRQHandler
Reserved459_IRQHandler
Reserved460_IRQHandler
Reserved461_IRQHandler
Reserved462_IRQHandler
Reserved463_IRQHandler
Reserved464_IRQHandler
Reserved465_IRQHandler
Reserved466_IRQHandler
Reserved467_IRQHandler
Reserved468_IRQHandler
Reserved469_IRQHandler
Reserved470_IRQHandler
Reserved471_IRQHandler
Reserved472_IRQHandler
Reserved473_IRQHandler
Reserved474_IRQHandler
Reserved475_IRQHandler
Reserved476_IRQHandler
Reserved477_IRQHandler
Reserved478_IRQHandler
Reserved479_IRQHandler
Reserved480_IRQHandler
Reserved481_IRQHandler
Reserved482_IRQHandler
Reserved483_IRQHandler
Reserved484_IRQHandler
Reserved485_IRQHandler
Reserved486_IRQHandler
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
Reserved519_IRQHandler
Reserved520_IRQHandler
Reserved521_IRQHandler
Reserved522_IRQHandler
Reserved523_IRQHandler
Reserved524_IRQHandler
Reserved525_IRQHandler
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
Reserved583_IRQHandler
Reserved584_IRQHandler
Reserved585_IRQHandler
Reserved586_IRQHandler
Reserved587_IRQHandler
Reserved588_IRQHandler
Reserved589_IRQHandler
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
Reserved647_IRQHandler
Reserved648_IRQHandler
Reserved649_IRQHandler
Reserved650_IRQHandler
Reserved651_IRQHandler
Reserved652_IRQHandler
Reserved653_IRQHandler
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
DefaultISR
        B DefaultISR

        END
