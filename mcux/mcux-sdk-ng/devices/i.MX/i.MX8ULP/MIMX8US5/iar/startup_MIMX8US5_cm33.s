/* ------------------------------------------------------------------------- */
/*  @file:    startup_MIMX8US5_cm33.s                                        */
/*  @purpose: CMSIS Cortex-M33 Core Device Startup File                      */
/*            MIMX8US5_cm33                                                  */
/*  @version: 6.0                                                            */
/*  @date:    2024-10-29                                                     */
/*  @build:   b250521                                                        */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Copyright 1997-2016 Freescale Semiconductor, Inc.                         */
/* Copyright 2016-2025 NXP                                                   */
/* SPDX-License-Identifier: BSD-3-Clause                                     */
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
        DCD     CTI0_IRQHandler                               ;Cross Trigger Interface
        DCD     DMA0_0_IRQHandler                             ;DMA0 Channel 0 Error or Transfer Complete
        DCD     DMA0_1_IRQHandler                             ;DMA0 Channel 1 Error or Transfer Complete
        DCD     DMA0_2_IRQHandler                             ;DMA0 Channel 2 Error or Transfer Complete
        DCD     DMA0_3_IRQHandler                             ;DMA0 Channel 3 Error or Transfer Complete
        DCD     DMA0_4_IRQHandler                             ;DMA0 Channel 4 Error or Transfer Complete
        DCD     DMA0_5_IRQHandler                             ;DMA0 Channel 5 Error or Transfer Complete
        DCD     DMA0_6_IRQHandler                             ;DMA0 Channel 6 Error or Transfer Complete
        DCD     DMA0_7_IRQHandler                             ;DMA0 Channel 7 Error or Transfer Complete
        DCD     DMA0_8_IRQHandler                             ;DMA0 Channel 8 Error or Transfer Complete
        DCD     DMA0_9_IRQHandler                             ;DMA0 Channel 9 Error or Transfer Complete
        DCD     DMA0_10_IRQHandler                            ;DMA0 Channel 10 Error or Transfer Complete
        DCD     DMA0_11_IRQHandler                            ;DMA0 Channel 11 Error or Transfer Complete
        DCD     DMA0_12_IRQHandler                            ;DMA0 Channel 12 Error or Transfer Complete
        DCD     DMA0_13_IRQHandler                            ;DMA0 Channel 13 Error or Transfer Complete
        DCD     DMA0_14_IRQHandler                            ;DMA0 Channel 14 Error or Transfer Complete
        DCD     DMA0_15_IRQHandler                            ;DMA0 Channel 15 Error or Transfer Complete
        DCD     DMA0_16_IRQHandler                            ;DMA0 Channel 16 Error or Transfer Complete
        DCD     DMA0_17_IRQHandler                            ;DMA0 Channel 17 Error or Transfer Complete
        DCD     DMA0_18_IRQHandler                            ;DMA0 Channel 18 Error or Transfer Complete
        DCD     DMA0_19_IRQHandler                            ;DMA0 Channel 19 Error or Transfer Complete
        DCD     DMA0_20_IRQHandler                            ;DMA0 Channel 20 Error or Transfer Complete
        DCD     DMA0_21_IRQHandler                            ;DMA0 Channel 21 Error or Transfer Complete
        DCD     DMA0_22_IRQHandler                            ;DMA0 Channel 22 Error or Transfer Complete
        DCD     DMA0_23_IRQHandler                            ;DMA0 Channel 23 Error or Transfer Complete
        DCD     DMA0_24_IRQHandler                            ;DMA0 Channel 24 Error or Transfer Complete
        DCD     DMA0_25_IRQHandler                            ;DMA0 Channel 25 Error or Transfer Complete
        DCD     DMA0_26_IRQHandler                            ;DMA0 Channel 26 Error or Transfer Complete
        DCD     DMA0_27_IRQHandler                            ;DMA0 Channel 27 Error or Transfer Complete
        DCD     DMA0_28_IRQHandler                            ;DMA0 Channel 28 Error or Transfer Complete
        DCD     DMA0_29_IRQHandler                            ;DMA0 Channel 29 Error or Transfer Complete
        DCD     DMA0_30_IRQHandler                            ;DMA0 Channel 30 Error or Transfer Complete
        DCD     DMA0_31_IRQHandler                            ;DMA0 Channel 31 Error or Transfer Complete
        DCD     DMA2_0_IRQHandler                             ;DMA2 Channel 0 Error or Transfer Complete
        DCD     DMA2_1_IRQHandler                             ;DMA2 Channel 1 Error or Transfer Complete
        DCD     DMA2_2_IRQHandler                             ;DMA2 Channel 2 Error or Transfer Complete
        DCD     DMA2_3_IRQHandler                             ;DMA2 Channel 3 Error or Transfer Complete
        DCD     DMA2_4_IRQHandler                             ;DMA2 Channel 4 Error or Transfer Complete
        DCD     DMA2_5_IRQHandler                             ;DMA2 Channel 5 Error or Transfer Complete
        DCD     DMA2_6_IRQHandler                             ;DMA2 Channel 6 Error or Transfer Complete
        DCD     DMA2_7_IRQHandler                             ;DMA2 Channel 7 Error or Transfer Complete
        DCD     DMA2_8_IRQHandler                             ;DMA2 Channel 8 Error or Transfer Complete
        DCD     DMA2_9_IRQHandler                             ;DMA2 Channel 9 Error or Transfer Complete
        DCD     DMA2_10_IRQHandler                            ;DMA2 Channel 10 Error or Transfer Complete
        DCD     DMA2_11_IRQHandler                            ;DMA2 Channel 11 Error or Transfer Complete
        DCD     DMA2_12_IRQHandler                            ;DMA2 Channel 12 Error or Transfer Complete
        DCD     DMA2_13_IRQHandler                            ;DMA2 Channel 13 Error or Transfer Complete
        DCD     DMA2_14_IRQHandler                            ;DMA2 Channel 14 Error or Transfer Complete
        DCD     DMA2_15_IRQHandler                            ;DMA2 Channel 15 Error or Transfer Complete
        DCD     DMA2_16_IRQHandler                            ;DMA2 Channel 16 Error or Transfer Complete
        DCD     DMA2_17_IRQHandler                            ;DMA2 Channel 17 Error or Transfer Complete
        DCD     DMA2_18_IRQHandler                            ;DMA2 Channel 18 Error or Transfer Complete
        DCD     DMA2_19_IRQHandler                            ;DMA2 Channel 19 Error or Transfer Complete
        DCD     DMA2_20_IRQHandler                            ;DMA2 Channel 20 Error or Transfer Complete
        DCD     DMA2_21_IRQHandler                            ;DMA2 Channel 21 Error or Transfer Complete
        DCD     DMA2_22_IRQHandler                            ;DMA2 Channel 22 Error or Transfer Complete
        DCD     DMA2_23_IRQHandler                            ;DMA2 Channel 23 Error or Transfer Complete
        DCD     DMA2_24_IRQHandler                            ;DMA2 Channel 24 Error or Transfer Complete
        DCD     DMA2_25_IRQHandler                            ;DMA2 Channel 25 Error or Transfer Complete
        DCD     DMA2_26_IRQHandler                            ;DMA2 Channel 26 Error or Transfer Complete
        DCD     DMA2_27_IRQHandler                            ;DMA2 Channel 27 Error or Transfer Complete
        DCD     DMA2_28_IRQHandler                            ;DMA2 Channel 28 Error or Transfer Complete
        DCD     DMA2_29_IRQHandler                            ;DMA2 Channel 29 Error or Transfer Complete
        DCD     DMA2_30_IRQHandler                            ;DMA2 Channel 30 Error or Transfer Complete
        DCD     DMA2_31_IRQHandler                            ;DMA2 Channel 31 Error or Transfer Complete
        DCD     CMC0_IRQHandler                               ;Core Mode Controller 0
        DCD     CMC2_IRQHandler                               ;Core Mode Controller 2
        DCD     uPower_IRQHandler                             ;uPower interrupt
        DCD     WUU0_IRQHandler                               ;Wake Up Unit 0
        DCD     CGC0_IRQHandler                               ;System Clock Generator for RT interrupt
        DCD     CGC1_IRQHandler                               ;Clock Generation and Control 1
        DCD     CGC2_IRQHandler                               ;Clock Generation and Control 2
        DCD     SIM0_IRQHandler                               ;System Integration Module 0
        DCD     PMC_IRQHandler                                ;Power Management Controller
        DCD     MU0_A_IRQHandler                              ;Messaging Unit 0 - Side A (to communicate with A35core)
        DCD     MU1_A_IRQHandler                              ;Messaging Unit 1 - Side A (to communicate with Fusion DSP)
        DCD     MU2_A_IRQHandler                              ;Messaging Unit 2 - Side A (to communicate with HiFi4 DSP)
        DCD     WDOG0_IRQHandler                              ;Watchdog 0 Interrupt
        DCD     WDOG1_IRQHandler                              ;Watchdog 1 Interrupt
        DCD     WDOG2_IRQHandler                              ;Watchdog 2 Interrupt
        DCD     WDOG3_IRQHandler                              ;Watchdog 3 Interrupt
        DCD     WDOG4_IRQHandler                              ;Watchdog 4 Interrupt
        DCD     EWM_IRQHandler                                ;External Watchdog Monitor Interrupt
        DCD     CMC1_IRQHandler                               ;Core Mode Controller 1
        DCD     SNTCommandInterface_IRQHandler                ;Sentinel command interface interrupt
        DCD     SNTSecure_IRQHandler                          ;Sentinel secure interrupt
        DCD     SNTNonSecure_IRQHandler                       ;Sentinel non-secure interrupt
        DCD     BBNSM_IRQHandler                              ;Secure Non-Volatile Storage Consolidated Interrupt
        DCD     TRDC_IRQHandler                               ;Trusted Resource Domain Controller interrupt
        DCD     XRDC_IRQHandler                               ;Extended Rexource Domain Control
        DCD     LPTMR0_IRQHandler                             ;Low Power Timer 0
        DCD     LPTMR1_IRQHandler                             ;Low Power Timer 1
        DCD     Reserved108_IRQHandler                        ;Reserved
        DCD     Reserved109_IRQHandler                        ;Reserved
        DCD     LPIT0_IRQHandler                              ;Low Power Periodic Interrupt Timer 0
        DCD     TPM0_IRQHandler                               ;Timer PWM module 0
        DCD     TPM1_IRQHandler                               ;Timer PWM module 1
        DCD     TPM2_IRQHandler                               ;Timer PWM module 2
        DCD     TPM3_IRQHandler                               ;Timer PWM module 3
        DCD     TPM4_IRQHandler                               ;Timer PWM module 4
        DCD     Reserved116_IRQHandler                        ;Reserved
        DCD     MRT0_IRQHandler                               ;Multi-Rate Timer interrupt
        DCD     FlexCAN_IRQHandler                            ;Flexible Controller Area Network interrupt
        DCD     FLEXIO0_IRQHandler                            ;Flexible IO 0
        DCD     LPI2C0_IRQHandler                             ;Low Power Inter-Integrated Circuit module 0
        DCD     LPI2C1_IRQHandler                             ;Low Power Inter-Integrated Circuit module 1
        DCD     LPI2C2_IRQHandler                             ;Low Power Inter-Integrated Circuit module 2
        DCD     LPI2C3_IRQHandler                             ;Low Power Inter-Integrated Circuit module 3
        DCD     LPSPI0_IRQHandler                             ;Low Power Serial Peripheral Interface 0
        DCD     LPSPI1_IRQHandler                             ;Low Power Serial Peripheral Interface 1
        DCD     LPSPI2_IRQHandler                             ;Low Power Serial Peripheral Interface 2
        DCD     LPSPI3_IRQHandler                             ;Low Power Serial Peripheral Interface 3
        DCD     LPUART0_IRQHandler                            ;Low Power UART 0
        DCD     LPUART1_IRQHandler                            ;Low Power UART 1
        DCD     LPUART2_IRQHandler                            ;Low Power UART 2
        DCD     LPUART3_IRQHandler                            ;Low Power UART 3
        DCD     USB0_IRQHandler                               ;USB Interrupt from A7 subsystem
        DCD     USBPHY0_IRQHandler                            ;USB PHY (used in conjunction with USB0)
        DCD     USB1_IRQHandler                               ;USB Interrupt from A7 subsystem
        DCD     USBPHY1_IRQHandler                            ;USB PHY (used in conjunction with USB1)
        DCD     PDM_EVENT_IRQHandler                          ;Digital Microphone interrupt
        DCD     PDM_HWVAD_EVENT_IRQHandler                    ;Digital Microphone Voice Activity Detection interrupt
        DCD     SAI0_IRQHandler                               ;Serial Audio Interface 0
        DCD     SAI1_IRQHandler                               ;Serial Audio Interface 1
        DCD     SAI2_IRQHandler                               ;Serial Audio Interface 2
        DCD     SAI3_IRQHandler                               ;Serial Audio Interface 3
        DCD     SAI6_IRQHandler                               ;Serial Audio Interface 6
        DCD     SAI7_IRQHandler                               ;Serial Audio Interface 7
        DCD     SPDIF_IRQHandler                              ;Sony/Phillips Digital Interface
        DCD     DCNano_IRQHandler                             ;Display Control Nano interrupt
        DCD     DSI_IRQHandler                                ;DSI controller interrupt
        DCD     GPU3D_IRQHandler                              ;Graphic Processor Unit 3D interrupt
        DCD     GPU2D_IRQHandler                              ;Graphic Processor Unit 2D interrupt
        DCD     GPIOA_INT0_IRQHandler                         ;General Purpose Input/Output A interrupt 0
        DCD     GPIOA_INT1_IRQHandler                         ;General Purpose Input/Output A interrupt 1
        DCD     GPIOB_INT0_IRQHandler                         ;General Purpose Input/Output B interrupt 0
        DCD     GPIOB_INT1_IRQHandler                         ;General Purpose Input/Output B interrupt 1
        DCD     GPIOC_INT0_IRQHandler                         ;General Purpose Input/Output C interrupt 0
        DCD     GPIOC_INT1_IRQHandler                         ;General Purpose Input/Output C interrupt 1
        DCD     GPIOD_INT0_IRQHandler                         ;General Purpose Input/Output D interrupt 0
        DCD     GPIOD_INT1_IRQHandler                         ;General Purpose Input/Output D interrupt 1
        DCD     GPIOE_INT0_IRQHandler                         ;General Purpose Input/Output E interrupt 0
        DCD     GPIOE_INT1_IRQHandler                         ;General Purpose Input/Output E interrupt 1
        DCD     GPIOF_INT0_IRQHandler                         ;General Purpose Input/Output F interrupt 0
        DCD     GPIOF_INT1_IRQHandler                         ;General Purpose Input/Output F interrupt 1
        DCD     Reserved161_IRQHandler                        ;Reserved
        DCD     Reserved162_IRQHandler                        ;Reserved
        DCD     Reserved163_IRQHandler                        ;Reserved
        DCD     Reserved164_IRQHandler                        ;Reserved
        DCD     Reserved165_IRQHandler                        ;Reserved
        DCD     Reserved166_IRQHandler                        ;Reserved
        DCD     ADC0_IRQHandler                               ;Analog to Digital Convertor 0
        DCD     ADC1_IRQHandler                               ;Analog to Digital Convertor 1
        DCD     CMP0_IRQHandler                               ;Comparator 0
        DCD     CMP1_IRQHandler                               ;Comparator 1
        DCD     DAC0_IRQHandler                               ;Digital to Analog Convertor 0
        DCD     DAC1_IRQHandler                               ;Digital to Analog Convertor 1
        DCD     FlexSPI0_IRQHandler                           ;FlexSPI controller interface interrupt 0
        DCD     FlexSPI1_IRQHandler                           ;FlexSPI controller interface interrupt 1
        DCD     FlexSPI2_IRQHandler                           ;FlexSPI controller interface interrupt 2
        DCD     uSDHC0_IRQHandler                             ;ultra Secure Digital Host Controller interrupt 0
        DCD     uSDHC1_IRQHandler                             ;ultra Secure Digital Host Controller interrupt 1
        DCD     uSDHC2_IRQHandler                             ;ultra Secure Digital Host Controller interrupt 2
        DCD     MDDR_IRQHandler                               ;Multi-Port Double Data Rate
        DCD     FLEXIO1_IRQHandler                            ;Flexible IO 1 interrupt
        DCD     I3C0_IRQHandler                               ;Improved Inter-Integrated Circuit 0 interrupt
        DCD     I3C1_IRQHandler                               ;Improved Inter-Integrated Circuit 1 interrupt
        DCD     CASPER_IRQHandler                             ;Cryptographic Accelerator and Signal Processing Engine with RAM-sharing
        DCD     PowerQuad_IRQHandler                          ;PowerQuad Digital Signal Co-Processor
        DCD     EPDC_IRQHandler                               ;Electronics Paper Display Controller interrupt
        DCD     PXP_IRQHandler                                ;Pixel Processor interrupt
        DCD     CTI1_IRQHandler                               ;Cross Trigger Interface
        DCD     DMA1_0_IRQHandler                             ;DMA1 Channel 0 error or transfer complete
        DCD     DMA1_1_IRQHandler                             ;DMA1 Channel 1 error or transfer complete
        DCD     DMA1_2_IRQHandler                             ;DMA1 Channel 2 error or transfer complete
        DCD     DMA1_3_IRQHandler                             ;DMA1 Channel 3 error or transfer complete
        DCD     DMA1_4_IRQHandler                             ;DMA1 Channel 4 error or transfer complete
        DCD     DMA1_5_IRQHandler                             ;DMA1 Channel 5 error or transfer complete
        DCD     DMA1_6_IRQHandler                             ;DMA1 Channel 6 error or transfer complete
        DCD     DMA1_7_IRQHandler                             ;DMA1 Channel 7 error or transfer complete
        DCD     DefaultISR                                    ;196
        DCD     DefaultISR                                    ;197
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
        LDR     R0, =sfb(CSTACK)
        MSR     MSPLIM, R0
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

        PUBWEAK CTI0_IRQHandler
        PUBWEAK DMA0_0_IRQHandler
        PUBWEAK DMA0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_0_IRQHandler
        MOV     R0, #0
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_1_IRQHandler
        MOV     R0, #1
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_2_IRQHandler
        MOV     R0, #2
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_3_IRQHandler
        MOV     R0, #3
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_4_IRQHandler
        MOV     R0, #4
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_5_IRQHandler
        MOV     R0, #5
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_6_IRQHandler
        MOV     R0, #6
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_7_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_7_IRQHandler
        MOV     R0, #7
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_8_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_8_IRQHandler
        MOV     R0, #8
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_9_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_9_IRQHandler
        MOV     R0, #9
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_10_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_10_IRQHandler
        MOV     R0, #10
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_11_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_11_IRQHandler
        MOV     R0, #11
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_12_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_12_IRQHandler
        MOV     R0, #12
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_13_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_13_IRQHandler
        MOV     R0, #13
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_14_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_14_IRQHandler
        MOV     R0, #14
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_15_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_15_IRQHandler
        MOV     R0, #15
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_16_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_16_IRQHandler
        MOV     R0, #16
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_17_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_17_IRQHandler
        MOV     R0, #17
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_18_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_18_IRQHandler
        MOV     R0, #18
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_19_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_19_IRQHandler
        MOV     R0, #19
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_20_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_20_IRQHandler
        MOV     R0, #20
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_21_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_21_IRQHandler
        MOV     R0, #21
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_22_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_22_IRQHandler
        MOV     R0, #22
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_23_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_23_IRQHandler
        MOV     R0, #23
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_24_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_24_IRQHandler
        MOV     R0, #24
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_25_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_25_IRQHandler
        MOV     R0, #25
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_26_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_26_IRQHandler
        MOV     R0, #26
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_27_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_27_IRQHandler
        MOV     R0, #27
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_28_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_28_IRQHandler
        MOV     R0, #28
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_29_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_29_IRQHandler
        MOV     R0, #29
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_30_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_30_IRQHandler
        MOV     R0, #30
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA0_31_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_31_IRQHandler
        MOV     R0, #31
        LDR     R1, =DMA0_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_0_IRQHandler
        PUBWEAK DMA2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_0_IRQHandler
        MOV     R0, #0
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_1_IRQHandler
        MOV     R0, #1
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_2_IRQHandler
        MOV     R0, #2
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_3_IRQHandler
        MOV     R0, #3
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_4_IRQHandler
        MOV     R0, #4
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_5_IRQHandler
        MOV     R0, #5
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_6_IRQHandler
        MOV     R0, #6
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_7_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_7_IRQHandler
        MOV     R0, #7
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_8_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_8_IRQHandler
        MOV     R0, #8
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_9_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_9_IRQHandler
        MOV     R0, #9
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_10_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_10_IRQHandler
        MOV     R0, #10
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_11_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_11_IRQHandler
        MOV     R0, #11
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_12_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_12_IRQHandler
        MOV     R0, #12
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_13_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_13_IRQHandler
        MOV     R0, #13
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_14_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_14_IRQHandler
        MOV     R0, #14
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_15_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_15_IRQHandler
        MOV     R0, #15
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_16_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_16_IRQHandler
        MOV     R0, #16
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_17_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_17_IRQHandler
        MOV     R0, #17
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_18_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_18_IRQHandler
        MOV     R0, #18
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_19_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_19_IRQHandler
        MOV     R0, #19
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_20_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_20_IRQHandler
        MOV     R0, #20
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_21_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_21_IRQHandler
        MOV     R0, #21
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_22_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_22_IRQHandler
        MOV     R0, #22
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_23_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_23_IRQHandler
        MOV     R0, #23
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_24_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_24_IRQHandler
        MOV     R0, #24
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_25_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_25_IRQHandler
        MOV     R0, #25
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_26_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_26_IRQHandler
        MOV     R0, #26
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_27_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_27_IRQHandler
        MOV     R0, #27
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_28_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_28_IRQHandler
        MOV     R0, #28
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_29_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_29_IRQHandler
        MOV     R0, #29
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_30_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_30_IRQHandler
        MOV     R0, #30
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK DMA2_31_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_31_IRQHandler
        MOV     R0, #31
        LDR     R1, =DMA2_DriverIRQHandler
        BX      R1

        PUBWEAK CMC0_IRQHandler
        PUBWEAK CMC2_IRQHandler
        PUBWEAK uPower_IRQHandler
        PUBWEAK WUU0_IRQHandler
        PUBWEAK CGC0_IRQHandler
        PUBWEAK CGC1_IRQHandler
        PUBWEAK CGC2_IRQHandler
        PUBWEAK SIM0_IRQHandler
        PUBWEAK PMC_IRQHandler
        PUBWEAK MU0_A_IRQHandler
        PUBWEAK MU1_A_IRQHandler
        PUBWEAK MU2_A_IRQHandler
        PUBWEAK WDOG0_IRQHandler
        PUBWEAK WDOG1_IRQHandler
        PUBWEAK WDOG2_IRQHandler
        PUBWEAK WDOG3_IRQHandler
        PUBWEAK WDOG4_IRQHandler
        PUBWEAK EWM_IRQHandler
        PUBWEAK CMC1_IRQHandler
        PUBWEAK SNTCommandInterface_IRQHandler
        PUBWEAK SNTSecure_IRQHandler
        PUBWEAK SNTNonSecure_IRQHandler
        PUBWEAK BBNSM_IRQHandler
        PUBWEAK TRDC_IRQHandler
        PUBWEAK XRDC_IRQHandler
        PUBWEAK LPTMR0_IRQHandler
        PUBWEAK LPTMR1_IRQHandler
        PUBWEAK Reserved108_IRQHandler
        PUBWEAK Reserved109_IRQHandler
        PUBWEAK LPIT0_IRQHandler
        PUBWEAK TPM0_IRQHandler
        PUBWEAK TPM1_IRQHandler
        PUBWEAK TPM2_IRQHandler
        PUBWEAK TPM3_IRQHandler
        PUBWEAK TPM4_IRQHandler
        PUBWEAK Reserved116_IRQHandler
        PUBWEAK MRT0_IRQHandler
        PUBWEAK FlexCAN_IRQHandler
        PUBWEAK CAN0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FlexCAN_IRQHandler
        LDR     R0, =CAN0_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXIO0_IRQHandler
        PUBWEAK FLEXIO0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXIO0_IRQHandler
        LDR     R0, =FLEXIO0_DriverIRQHandler
        BX      R0

        PUBWEAK LPI2C0_IRQHandler
        PUBWEAK LPI2C0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C0_IRQHandler
        LDR     R0, =LPI2C0_DriverIRQHandler
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

        PUBWEAK LPI2C3_IRQHandler
        PUBWEAK LPI2C3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C3_IRQHandler
        LDR     R0, =LPI2C3_DriverIRQHandler
        BX      R0

        PUBWEAK LPSPI0_IRQHandler
        PUBWEAK LPSPI0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPSPI0_IRQHandler
        LDR     R0, =LPSPI0_DriverIRQHandler
        BX      R0

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

        PUBWEAK LPSPI3_IRQHandler
        PUBWEAK LPSPI3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPSPI3_IRQHandler
        LDR     R0, =LPSPI3_DriverIRQHandler
        BX      R0

        PUBWEAK LPUART0_IRQHandler
        PUBWEAK LPUART0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART0_IRQHandler
        LDR     R0, =LPUART0_DriverIRQHandler
        BX      R0

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

        PUBWEAK LPUART3_IRQHandler
        PUBWEAK LPUART3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART3_IRQHandler
        LDR     R0, =LPUART3_DriverIRQHandler
        BX      R0

        PUBWEAK USB0_IRQHandler
        PUBWEAK USBPHY0_IRQHandler
        PUBWEAK USB1_IRQHandler
        PUBWEAK USBPHY1_IRQHandler
        PUBWEAK PDM_EVENT_IRQHandler
        PUBWEAK PDM_EVENT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PDM_EVENT_IRQHandler
        LDR     R0, =PDM_EVENT_DriverIRQHandler
        BX      R0

        PUBWEAK PDM_HWVAD_EVENT_IRQHandler
        PUBWEAK PDM_HWVAD_EVENT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PDM_HWVAD_EVENT_IRQHandler
        LDR     R0, =PDM_HWVAD_EVENT_DriverIRQHandler
        BX      R0

        PUBWEAK SAI0_IRQHandler
        PUBWEAK SAI0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SAI0_IRQHandler
        LDR     R0, =SAI0_DriverIRQHandler
        BX      R0

        PUBWEAK SAI1_IRQHandler
        PUBWEAK SAI1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SAI1_IRQHandler
        LDR     R0, =SAI1_DriverIRQHandler
        BX      R0

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

        PUBWEAK SAI6_IRQHandler
        PUBWEAK SAI6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SAI6_IRQHandler
        LDR     R0, =SAI6_DriverIRQHandler
        BX      R0

        PUBWEAK SAI7_IRQHandler
        PUBWEAK SAI7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SAI7_IRQHandler
        LDR     R0, =SAI7_DriverIRQHandler
        BX      R0

        PUBWEAK SPDIF_IRQHandler
        PUBWEAK SPDIF_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SPDIF_IRQHandler
        LDR     R0, =SPDIF_DriverIRQHandler
        BX      R0

        PUBWEAK DCNano_IRQHandler
        PUBWEAK DSI_IRQHandler
        PUBWEAK GPU3D_IRQHandler
        PUBWEAK GPU2D_IRQHandler
        PUBWEAK GPIOA_INT0_IRQHandler
        PUBWEAK GPIOA_INT1_IRQHandler
        PUBWEAK GPIOB_INT0_IRQHandler
        PUBWEAK GPIOB_INT1_IRQHandler
        PUBWEAK GPIOC_INT0_IRQHandler
        PUBWEAK GPIOC_INT1_IRQHandler
        PUBWEAK GPIOD_INT0_IRQHandler
        PUBWEAK GPIOD_INT1_IRQHandler
        PUBWEAK GPIOE_INT0_IRQHandler
        PUBWEAK GPIOE_INT1_IRQHandler
        PUBWEAK GPIOF_INT0_IRQHandler
        PUBWEAK GPIOF_INT1_IRQHandler
        PUBWEAK Reserved161_IRQHandler
        PUBWEAK Reserved162_IRQHandler
        PUBWEAK Reserved163_IRQHandler
        PUBWEAK Reserved164_IRQHandler
        PUBWEAK Reserved165_IRQHandler
        PUBWEAK Reserved166_IRQHandler
        PUBWEAK ADC0_IRQHandler
        PUBWEAK ADC1_IRQHandler
        PUBWEAK CMP0_IRQHandler
        PUBWEAK CMP1_IRQHandler
        PUBWEAK DAC0_IRQHandler
        PUBWEAK DAC1_IRQHandler
        PUBWEAK FlexSPI0_IRQHandler
        PUBWEAK FlexSPI0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FlexSPI0_IRQHandler
        LDR     R0, =FlexSPI0_DriverIRQHandler
        BX      R0

        PUBWEAK FlexSPI1_IRQHandler
        PUBWEAK FlexSPI1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FlexSPI1_IRQHandler
        LDR     R0, =FlexSPI1_DriverIRQHandler
        BX      R0

        PUBWEAK FlexSPI2_IRQHandler
        PUBWEAK FlexSPI2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FlexSPI2_IRQHandler
        LDR     R0, =FlexSPI2_DriverIRQHandler
        BX      R0

        PUBWEAK uSDHC0_IRQHandler
        PUBWEAK uSDHC0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
uSDHC0_IRQHandler
        LDR     R0, =uSDHC0_DriverIRQHandler
        BX      R0

        PUBWEAK uSDHC1_IRQHandler
        PUBWEAK uSDHC1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
uSDHC1_IRQHandler
        LDR     R0, =uSDHC1_DriverIRQHandler
        BX      R0

        PUBWEAK uSDHC2_IRQHandler
        PUBWEAK uSDHC2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
uSDHC2_IRQHandler
        LDR     R0, =uSDHC2_DriverIRQHandler
        BX      R0

        PUBWEAK MDDR_IRQHandler
        PUBWEAK FLEXIO1_IRQHandler
        PUBWEAK FLEXIO1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXIO1_IRQHandler
        LDR     R0, =FLEXIO1_DriverIRQHandler
        BX      R0

        PUBWEAK I3C0_IRQHandler
        PUBWEAK I3C0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I3C0_IRQHandler
        LDR     R0, =I3C0_DriverIRQHandler
        BX      R0

        PUBWEAK I3C1_IRQHandler
        PUBWEAK I3C1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I3C1_IRQHandler
        LDR     R0, =I3C1_DriverIRQHandler
        BX      R0

        PUBWEAK CASPER_IRQHandler
        PUBWEAK PowerQuad_IRQHandler
        PUBWEAK EPDC_IRQHandler
        PUBWEAK PXP_IRQHandler
        PUBWEAK CTI1_IRQHandler
        PUBWEAK DMA1_0_IRQHandler
        PUBWEAK DMA1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_0_IRQHandler
        MOV     R0, #0
        LDR     R1, =DMA1_DriverIRQHandler
        BX      R1

        PUBWEAK DMA1_1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_1_IRQHandler
        MOV     R0, #1
        LDR     R1, =DMA1_DriverIRQHandler
        BX      R1

        PUBWEAK DMA1_2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_2_IRQHandler
        MOV     R0, #2
        LDR     R1, =DMA1_DriverIRQHandler
        BX      R1

        PUBWEAK DMA1_3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_3_IRQHandler
        MOV     R0, #3
        LDR     R1, =DMA1_DriverIRQHandler
        BX      R1

        PUBWEAK DMA1_4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_4_IRQHandler
        MOV     R0, #4
        LDR     R1, =DMA1_DriverIRQHandler
        BX      R1

        PUBWEAK DMA1_5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_5_IRQHandler
        MOV     R0, #5
        LDR     R1, =DMA1_DriverIRQHandler
        BX      R1

        PUBWEAK DMA1_6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_6_IRQHandler
        MOV     R0, #6
        LDR     R1, =DMA1_DriverIRQHandler
        BX      R1

        PUBWEAK DMA1_7_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_7_IRQHandler
        MOV     R0, #7
        LDR     R1, =DMA1_DriverIRQHandler
        BX      R1

        PUBWEAK DefaultISR
        SECTION .text:CODE:REORDER:NOROOT(1)
CTI0_IRQHandler
DMA0_DriverIRQHandler
DMA2_DriverIRQHandler
CMC0_IRQHandler
CMC2_IRQHandler
uPower_IRQHandler
WUU0_IRQHandler
CGC0_IRQHandler
CGC1_IRQHandler
CGC2_IRQHandler
SIM0_IRQHandler
PMC_IRQHandler
MU0_A_IRQHandler
MU1_A_IRQHandler
MU2_A_IRQHandler
WDOG0_IRQHandler
WDOG1_IRQHandler
WDOG2_IRQHandler
WDOG3_IRQHandler
WDOG4_IRQHandler
EWM_IRQHandler
CMC1_IRQHandler
SNTCommandInterface_IRQHandler
SNTSecure_IRQHandler
SNTNonSecure_IRQHandler
BBNSM_IRQHandler
TRDC_IRQHandler
XRDC_IRQHandler
LPTMR0_IRQHandler
LPTMR1_IRQHandler
Reserved108_IRQHandler
Reserved109_IRQHandler
LPIT0_IRQHandler
TPM0_IRQHandler
TPM1_IRQHandler
TPM2_IRQHandler
TPM3_IRQHandler
TPM4_IRQHandler
Reserved116_IRQHandler
MRT0_IRQHandler
CAN0_DriverIRQHandler
FLEXIO0_DriverIRQHandler
LPI2C0_DriverIRQHandler
LPI2C1_DriverIRQHandler
LPI2C2_DriverIRQHandler
LPI2C3_DriverIRQHandler
LPSPI0_DriverIRQHandler
LPSPI1_DriverIRQHandler
LPSPI2_DriverIRQHandler
LPSPI3_DriverIRQHandler
LPUART0_DriverIRQHandler
LPUART1_DriverIRQHandler
LPUART2_DriverIRQHandler
LPUART3_DriverIRQHandler
USB0_IRQHandler
USBPHY0_IRQHandler
USB1_IRQHandler
USBPHY1_IRQHandler
PDM_EVENT_DriverIRQHandler
PDM_HWVAD_EVENT_DriverIRQHandler
SAI0_DriverIRQHandler
SAI1_DriverIRQHandler
SAI2_DriverIRQHandler
SAI3_DriverIRQHandler
SAI6_DriverIRQHandler
SAI7_DriverIRQHandler
SPDIF_DriverIRQHandler
DCNano_IRQHandler
DSI_IRQHandler
GPU3D_IRQHandler
GPU2D_IRQHandler
GPIOA_INT0_IRQHandler
GPIOA_INT1_IRQHandler
GPIOB_INT0_IRQHandler
GPIOB_INT1_IRQHandler
GPIOC_INT0_IRQHandler
GPIOC_INT1_IRQHandler
GPIOD_INT0_IRQHandler
GPIOD_INT1_IRQHandler
GPIOE_INT0_IRQHandler
GPIOE_INT1_IRQHandler
GPIOF_INT0_IRQHandler
GPIOF_INT1_IRQHandler
Reserved161_IRQHandler
Reserved162_IRQHandler
Reserved163_IRQHandler
Reserved164_IRQHandler
Reserved165_IRQHandler
Reserved166_IRQHandler
ADC0_IRQHandler
ADC1_IRQHandler
CMP0_IRQHandler
CMP1_IRQHandler
DAC0_IRQHandler
DAC1_IRQHandler
FlexSPI0_DriverIRQHandler
FlexSPI1_DriverIRQHandler
FlexSPI2_DriverIRQHandler
uSDHC0_DriverIRQHandler
uSDHC1_DriverIRQHandler
uSDHC2_DriverIRQHandler
MDDR_IRQHandler
FLEXIO1_DriverIRQHandler
I3C0_DriverIRQHandler
I3C1_DriverIRQHandler
CASPER_IRQHandler
PowerQuad_IRQHandler
EPDC_IRQHandler
PXP_IRQHandler
CTI1_IRQHandler
DMA1_DriverIRQHandler
DefaultISR
        B DefaultISR

        END
