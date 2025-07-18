; -------------------------------------------------------------------------
;  @file:    startup_MCXL254_cm33.s
;  @purpose: CMSIS Cortex-M33 Core Device Startup File
;            MCXL254_cm33
;  @version: 1.0
;  @date:    2023-1-9
;  @build:   b240826
; -------------------------------------------------------------------------
;
; Copyright 1997-2016 Freescale Semiconductor, Inc.
; Copyright 2016-2024 NXP
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
        DCD     Reserved16_IRQHandler                         ;OR IRQ1 to IRQ79
        DCD     CMC_IRQHandler                                ;Core Mode Controller interrupt
        DCD     DMA0_CH0_IRQHandler                           ;DMA3_0_CH0 error or transfer complete
        DCD     DMA0_CH1_IRQHandler                           ;DMA3_0_CH1 error or transfer complete
        DCD     DMA0_CH2_IRQHandler                           ;DMA3_0_CH2 error or transfer complete
        DCD     DMA0_CH3_IRQHandler                           ;DMA3_0_CH3 error or transfer complete
        DCD     Reserved22_IRQHandler                         ;xxx Interrupt 22
        DCD     Reserved23_IRQHandler                         ;xxx Interrupt 23
        DCD     Reserved24_IRQHandler                         ;xxx Interrupt 24
        DCD     Reserved25_IRQHandler                         ;xxx Interrupt 25
        DCD     ERM0_IRQHandler                               ;ERM Single Bit error interrupt
        DCD     Reserved27_IRQHandler                         ;xxx Interrupt 27
        DCD     FMU0_IRQHandler                               ;Flash Management Unit interrupt
        DCD     GLIKEY0_IRQHandler                            ;GLIKEY Interrupt
        DCD     MBC0_IRQHandler                               ;MBC secure violation interrupt
        DCD     SCG0_IRQHandler                               ;System Clock Generator interrupt
        DCD     Reserved32_IRQHandler                         ;xxx Interrupt 32
        DCD     Reserved33_IRQHandler                         ;xxx Interrupt 33
        DCD     WUU0_IRQHandler                               ;Wake Up Unit interrupt
        DCD     Reserved35_IRQHandler                         ;xxx Interrupt 35
        DCD     Reserved36_IRQHandler                         ;xxx Interrupt 36
        DCD     Reserved37_IRQHandler                         ;xxx Interrupt 37
        DCD     Reserved38_IRQHandler                         ;xxx Interrupt 38
        DCD     Reserved39_IRQHandler                         ;xxx Interrupt 39
        DCD     Reserved40_IRQHandler                         ;xxx Interrupt 40
        DCD     Reserved41_IRQHandler                         ;xxx Interrupt 41
        DCD     LPI2C0_IRQHandler                             ;Low-Power Inter Integrated Circuit interrupt
        DCD     LPI2C1_IRQHandler                             ;Low-Power Inter Integrated Circuit interrupt
        DCD     LPSPI0_IRQHandler                             ;Low-Power Serial Peripheral Interface interrupt
        DCD     LPSPI1_IRQHandler                             ;Low-Power Serial Peripheral Interface interrupt
        DCD     Reserved46_IRQHandler                         ;xxx Interrupt 46
        DCD     LPUART0_IRQHandler                            ;Low-Power Universal Asynchronous Receive/Transmit interrupt
        DCD     LPUART1_IRQHandler                            ;Low-Power Universal Asynchronous Receive/Transmit interrupt
        DCD     Reserved49_IRQHandler                         ;xxx Interrupt 49
        DCD     Reserved50_IRQHandler                         ;xxx Interrupt 50
        DCD     Reserved51_IRQHandler                         ;xxx Interrupt 51
        DCD     Reserved52_IRQHandler                         ;xxx Interrupt 52
        DCD     Reserved53_IRQHandler                         ;xxx Interrupt 53
        DCD     CDOG0_IRQHandler                              ;Code Watchdog Timer 0 interrupt
        DCD     CTIMER0_IRQHandler                            ;Standard counter/timer 0 interrupt
        DCD     CTIMER1_IRQHandler                            ;Standard counter/timer 1 interrupt
        DCD     CTIMER2_IRQHandler                            ;Standard counter/timer 2 interrupt
        DCD     Reserved58_IRQHandler                         ;xxx Interrupt 58
        DCD     Reserved59_IRQHandler                         ;xxx Interrupt 59
        DCD     Reserved60_IRQHandler                         ;xxx Interrupt 60
        DCD     Reserved61_IRQHandler                         ;xxx Interrupt 61
        DCD     Reserved62_IRQHandler                         ;xxx Interrupt 62
        DCD     Reserved63_IRQHandler                         ;xxx Interrupt 63
        DCD     Reserved64_IRQHandler                         ;xxx Interrupt 64
        DCD     Reserved65_IRQHandler                         ;xxx Interrupt 65
        DCD     Reserved66_IRQHandler                         ;xxx Interrupt 66
        DCD     Reserved67_IRQHandler                         ;xxx Interrupt 67
        DCD     Reserved68_IRQHandler                         ;xxx Interrupt 68
        DCD     Reserved69_IRQHandler                         ;xxx Interrupt 69
        DCD     FREQME0_IRQHandler                            ;Frequency Measurement interrupt
        DCD     Reserved71_IRQHandler                         ;xxx Interrupt 71
        DCD     Reserved72_IRQHandler                         ;xxx Interrupt 72
        DCD     OS_EVENT_IRQHandler                           ;OS event timer interrupt
        DCD     Reserved74_IRQHandler                         ;xxx Interrupt 74
        DCD     UTICK0_IRQHandler                             ;Micro-Tick Timer interrupt
        DCD     WWDT0_IRQHandler                              ;Windowed Watchdog Timer 0 interrupt
        DCD     Reserved77_IRQHandler                         ;xxx Interrupt 77
        DCD     ADC0_IRQHandler                               ;Analog-to-Digital Converter interrupt
        DCD     Reserved79_IRQHandler                         ;xxx Interrupt 79
        DCD     CMP0_IRQHandler                               ;Comparator interrupt
        DCD     Reserved81_IRQHandler                         ;xxx Interrupt 81
        DCD     Reserved82_IRQHandler                         ;xxx Interrupt 82
        DCD     Reserved83_IRQHandler                         ;xxx Interrupt 83
        DCD     Reserved84_IRQHandler                         ;xxx Interrupt 84
        DCD     Reserved85_IRQHandler                         ;xxx Interrupt 85
        DCD     Reserved86_IRQHandler                         ;xxx Interrupt 86
        DCD     GPIO10_IRQHandler                             ;General Purpose Input/Output 1 interrupt 0
        DCD     GPIO11_IRQHandler                             ;General Purpose Input/Output 1 interrupt 1
        DCD     GPIO20_IRQHandler                             ;General Purpose Input/Output 2 interrupt 0
        DCD     GPIO21_IRQHandler                             ;General Purpose Input/Output 2 interrupt 1
        DCD     GPIO30_IRQHandler                             ;General Purpose Input/Output 3 interrupt 0
        DCD     GPIO31_IRQHandler                             ;General Purpose Input/Output 3 interrupt 1
        DCD     Reserved93_IRQHandler                         ;xxx Interrupt 93
        DCD     Reserved94_IRQHandler                         ;xxx Interrupt 94
        DCD     Reserved95_IRQHandler                         ;xxx Interrupt 95
        DCD     MU_A_TX_IRQHandler                            ;Ored tx interrupt to MUA
        DCD     MU_A_RX_IRQHandler                            ;Ored rx interrupt to MUA
        DCD     MU_A_INT_IRQHandler                           ;ORed general purpose interrupt request to MUA
        DCD     CDOG1_IRQHandler                              ;Code Watchdog Timer 1 interrupt
        DCD     Reserved100_IRQHandler                        ;xxx Interrupt 100
        DCD     Reserved101_IRQHandler                        ;xxx Interrupt 101
        DCD     Reserved102_IRQHandler                        ;xxx Interrupt 102
        DCD     Reserved103_IRQHandler                        ;xxx Interrupt 103
        DCD     Reserved104_IRQHandler                        ;xxx Interrupt 104
        DCD     Reserved105_IRQHandler                        ;xxx Interrupt 105
        DCD     Reserved106_IRQHandler                        ;xxx Interrupt 106
        DCD     Reserved107_IRQHandler                        ;xxx Interrupt 107
        DCD     Reserved108_IRQHandler                        ;xxx Interrupt 108
        DCD     Reserved109_IRQHandler                        ;xxx Interrupt 109
        DCD     Reserved110_IRQHandler                        ;xxx Interrupt 110
        DCD     Reserved111_IRQHandler                        ;xxx Interrupt 111
        DCD     DMA1_CH0_IRQHandler                           ;DMA3_1_CH0 error or transfer complete
        DCD     DMA1_CH1_IRQHandler                           ;DMA3_1_CH1 error or transfer complete
        DCD     DMA1_CH2_IRQHandler                           ;DMA3_1_CH2 error or transfer complete
        DCD     DMA1_CH3_IRQHandler                           ;DMA3_1_CH3 error or transfer complete
        DCD     Reserved116_IRQHandler                        ;xxx Interrupt 116
        DCD     Reserved117_IRQHandler                        ;xxx Interrupt 117
        DCD     Reserved118_IRQHandler                        ;xxx Interrupt 118
        DCD     Reserved119_IRQHandler                        ;xxx Interrupt 119
        DCD     Reserved120_IRQHandler                        ;xxx Interrupt 120
        DCD     Reserved121_IRQHandler                        ;xxx Interrupt 121
        DCD     Reserved122_IRQHandler                        ;xxx Interrupt 122
        DCD     Reserved123_IRQHandler                        ;xxx Interrupt 123
        DCD     Reserved124_IRQHandler                        ;xxx Interrupt 124
        DCD     Reserved125_IRQHandler                        ;xxx Interrupt 125
        DCD     PKC_IRQHandler                                ;PKC interrupt
        DCD     SGI_IRQHandler                                ;SGI interrupt
        DCD     TRNG_IRQHandler                               ;TRNG interrupt
        DCD     ERR_SGI_UDF_TRNG_PKC_IRQHandler               ;ORed Error Interrupt from SGI, UDF,TRNG and PKC
        DCD     HYPERVISOR_IRQHandler                         ;Hypervisor interrupt
        DCD     Reserved131_IRQHandler                        ;xxx Interrupt 131
        DCD     Reserved132_IRQHandler                        ;xxx Interrupt 132
        DCD     Reserved133_IRQHandler                        ;xxx Interrupt 133
        DCD     Reserved134_IRQHandler                        ;xxx Interrupt 134
        DCD     Reserved135_IRQHandler                        ;xxx Interrupt 135
        DCD     Reserved136_IRQHandler                        ;xxx Interrupt 136
        DCD     Reserved137_IRQHandler                        ;xxx Interrupt 137
        DCD     Reserved138_IRQHandler                        ;xxx Interrupt 138
        DCD     Reserved139_IRQHandler                        ;xxx Interrupt 139
        DCD     Reserved140_IRQHandler                        ;xxx Interrupt 140
        DCD     Reserved141_IRQHandler                        ;xxx Interrupt 141
        DCD     Reserved142_IRQHandler                        ;xxx Interrupt 142
        DCD     Reserved143_IRQHandler                        ;xxx Interrupt 143
        DCD     LPI2C0_AON_IRQHandler                         ;Low-Power Inter Integrated Circuit interrupt
        DCD     Reserved145_IRQHandler                        ;xxx Interrupt 145
        DCD     LPUART0_AON_IRQHandler                        ;Low-Power Universal Asynchronous Receive/Transmit interrupt
        DCD     Reserved147_IRQHandler                        ;xxx Interrupt 147
        DCD     GPIO00_AON_IRQHandler                         ;General Purpose Input/Output interrupt 0
        DCD     GPIO01_AON_IRQHandler                         ;General Purpose Input/Output interrupt 1
        DCD     Reserved150_IRQHandler                        ;xxx Interrupt 150
        DCD     Reserved151_IRQHandler                        ;xxx Interrupt 151
        DCD     Reserved152_IRQHandler                        ;xxx Interrupt 152
        DCD     Reserved153_IRQHandler                        ;xxx Interrupt 153
        DCD     Reserved154_IRQHandler                        ;xxx Interrupt 154
        DCD     LPCMP_IRQHandler                              ;Comparator
        DCD     RTC_ALARM0_IRQHandler                         ;RTC alarm 0
        DCD     RTC_ALARM1_IRQHandler                         ;RTC alarm 1
        DCD     RTC_ALARM2_IRQHandler                         ;RTC alarm 2
        DCD     RTC_WDT_IRQHandler                            ;RTC watchdog
        DCD     RTC_XTAL_IRQHandler                           ;RTC XTAL Fail
        DCD     Reserved161_IRQHandler                        ;xxx Interrupt 161
        DCD     Reserved162_IRQHandler                        ;xxx Interrupt 162
        DCD     Reserved163_IRQHandler                        ;xxx Interrupt 163
        DCD     KPP_AON_IRQHandler                            ;Keypad Interrupt
        DCD     LPADC_AON_IRQHandler                          ;ADC Summary Interrupt
        DCD     Reserved166_IRQHandler                        ;xxx Interrupt 166
        DCD     QTMR0_AON_IRQHandler                          ;ORed QTMR Interrupts
        DCD     QTMR1_AON_IRQHandler                          ;ORed QTMR Interrupts
        DCD     Reserved169_IRQHandler                        ;xxx Interrupt 169
        DCD     LCSENSE_IRQHandler                            ;LCSense Fault/Tamper Interrupt
        DCD     LPTMR_AON_IRQHandler                          ;Low Power Timer 0 interrupt
        DCD     Reserved172_IRQHandler                        ;xxx Interrupt 172
        DCD     ACMP_AON_IRQHandler                           ;Comparator interrupt
        DCD     ADVC_IRQHandler                               ;ADVC_2.0 Controller Interrupt
        DCD     Reserved175_IRQHandler                        ;xxx Interrupt 175
        DCD     SGLCD_FRAME_AON_IRQHandler                    ;Frame Update Interrupt
        DCD     SGLCD_FFAULT_AON_IRQHandler                   ;Fault Detect Interrupt
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
        CPSIE   I               ; Unmask interrupts
        LDR     R0, =SystemInit
        BLX     R0
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
        PUBWEAK Reserved16_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved16_IRQHandler
        LDR     R0, =Reserved16_DriverIRQHandler
        BX      R0

        PUBWEAK CMC_IRQHandler
        PUBWEAK CMC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CMC_IRQHandler
        LDR     R0, =CMC_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH0_IRQHandler
        PUBWEAK DMA0_CH0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH0_IRQHandler
        LDR     R0, =DMA0_CH0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH1_IRQHandler
        PUBWEAK DMA0_CH1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH1_IRQHandler
        LDR     R0, =DMA0_CH1_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH2_IRQHandler
        PUBWEAK DMA0_CH2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH2_IRQHandler
        LDR     R0, =DMA0_CH2_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH3_IRQHandler
        PUBWEAK DMA0_CH3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH3_IRQHandler
        LDR     R0, =DMA0_CH3_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved22_IRQHandler
        PUBWEAK Reserved22_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved22_IRQHandler
        LDR     R0, =Reserved22_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved23_IRQHandler
        PUBWEAK Reserved23_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved23_IRQHandler
        LDR     R0, =Reserved23_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved24_IRQHandler
        PUBWEAK Reserved24_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved24_IRQHandler
        LDR     R0, =Reserved24_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved25_IRQHandler
        PUBWEAK Reserved25_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved25_IRQHandler
        LDR     R0, =Reserved25_DriverIRQHandler
        BX      R0

        PUBWEAK ERM0_IRQHandler
        PUBWEAK ERM0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ERM0_IRQHandler
        LDR     R0, =ERM0_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved27_IRQHandler
        PUBWEAK Reserved27_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved27_IRQHandler
        LDR     R0, =Reserved27_DriverIRQHandler
        BX      R0

        PUBWEAK FMU0_IRQHandler
        PUBWEAK FMU0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FMU0_IRQHandler
        LDR     R0, =FMU0_DriverIRQHandler
        BX      R0

        PUBWEAK GLIKEY0_IRQHandler
        PUBWEAK GLIKEY0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GLIKEY0_IRQHandler
        LDR     R0, =GLIKEY0_DriverIRQHandler
        BX      R0

        PUBWEAK MBC0_IRQHandler
        PUBWEAK MBC0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MBC0_IRQHandler
        LDR     R0, =MBC0_DriverIRQHandler
        BX      R0

        PUBWEAK SCG0_IRQHandler
        PUBWEAK SCG0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SCG0_IRQHandler
        LDR     R0, =SCG0_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved32_IRQHandler
        PUBWEAK Reserved32_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved32_IRQHandler
        LDR     R0, =Reserved32_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved33_IRQHandler
        PUBWEAK Reserved33_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved33_IRQHandler
        LDR     R0, =Reserved33_DriverIRQHandler
        BX      R0

        PUBWEAK WUU0_IRQHandler
        PUBWEAK WUU0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WUU0_IRQHandler
        LDR     R0, =WUU0_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved35_IRQHandler
        PUBWEAK Reserved35_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved35_IRQHandler
        LDR     R0, =Reserved35_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved36_IRQHandler
        PUBWEAK Reserved36_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved36_IRQHandler
        LDR     R0, =Reserved36_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved37_IRQHandler
        PUBWEAK Reserved37_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved37_IRQHandler
        LDR     R0, =Reserved37_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved38_IRQHandler
        PUBWEAK Reserved38_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved38_IRQHandler
        LDR     R0, =Reserved38_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved39_IRQHandler
        PUBWEAK Reserved39_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved39_IRQHandler
        LDR     R0, =Reserved39_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved40_IRQHandler
        PUBWEAK Reserved40_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved40_IRQHandler
        LDR     R0, =Reserved40_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved41_IRQHandler
        PUBWEAK Reserved41_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved41_IRQHandler
        LDR     R0, =Reserved41_DriverIRQHandler
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

        PUBWEAK Reserved46_IRQHandler
        PUBWEAK Reserved46_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved46_IRQHandler
        LDR     R0, =Reserved46_DriverIRQHandler
        BX      R0

        PUBWEAK LPUART0_IRQHandler
        PUBWEAK LPUART_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART0_IRQHandler
        LDR     R1, =LPUART_DriverIRQHandler
        LDR     R0, =0 ;instance number
        BX      R1

        PUBWEAK LPUART1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART1_IRQHandler
        LDR     R1, =LPUART_DriverIRQHandler
        LDR     R0, =1 ;instance number  
        BX      R1

        PUBWEAK Reserved49_IRQHandler
        PUBWEAK Reserved49_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved49_IRQHandler
        LDR     R0, =Reserved49_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved50_IRQHandler
        PUBWEAK Reserved50_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved50_IRQHandler
        LDR     R0, =Reserved50_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved51_IRQHandler
        PUBWEAK Reserved51_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved51_IRQHandler
        LDR     R0, =Reserved51_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved52_IRQHandler
        PUBWEAK Reserved52_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved52_IRQHandler
        LDR     R0, =Reserved52_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved53_IRQHandler
        PUBWEAK Reserved53_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved53_IRQHandler
        LDR     R0, =Reserved53_DriverIRQHandler
        BX      R0

        PUBWEAK CDOG0_IRQHandler
        PUBWEAK CDOG0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CDOG0_IRQHandler
        LDR     R0, =CDOG0_DriverIRQHandler
        BX      R0

        PUBWEAK CTIMER0_IRQHandler
        PUBWEAK CTIMER0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CTIMER0_IRQHandler
        LDR     R0, =CTIMER0_DriverIRQHandler
        BX      R0

        PUBWEAK CTIMER1_IRQHandler
        PUBWEAK CTIMER1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CTIMER1_IRQHandler
        LDR     R0, =CTIMER1_DriverIRQHandler
        BX      R0

        PUBWEAK CTIMER2_IRQHandler
        PUBWEAK CTIMER2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CTIMER2_IRQHandler
        LDR     R0, =CTIMER2_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved58_IRQHandler
        PUBWEAK Reserved58_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved58_IRQHandler
        LDR     R0, =Reserved58_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved59_IRQHandler
        PUBWEAK Reserved59_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved59_IRQHandler
        LDR     R0, =Reserved59_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved60_IRQHandler
        PUBWEAK Reserved60_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved60_IRQHandler
        LDR     R0, =Reserved60_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved61_IRQHandler
        PUBWEAK Reserved61_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved61_IRQHandler
        LDR     R0, =Reserved61_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved62_IRQHandler
        PUBWEAK Reserved62_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved62_IRQHandler
        LDR     R0, =Reserved62_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved63_IRQHandler
        PUBWEAK Reserved63_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved63_IRQHandler
        LDR     R0, =Reserved63_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved64_IRQHandler
        PUBWEAK Reserved64_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved64_IRQHandler
        LDR     R0, =Reserved64_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved65_IRQHandler
        PUBWEAK Reserved65_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved65_IRQHandler
        LDR     R0, =Reserved65_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved66_IRQHandler
        PUBWEAK Reserved66_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved66_IRQHandler
        LDR     R0, =Reserved66_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved67_IRQHandler
        PUBWEAK Reserved67_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved67_IRQHandler
        LDR     R0, =Reserved67_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved68_IRQHandler
        PUBWEAK Reserved68_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved68_IRQHandler
        LDR     R0, =Reserved68_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved69_IRQHandler
        PUBWEAK Reserved69_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved69_IRQHandler
        LDR     R0, =Reserved69_DriverIRQHandler
        BX      R0

        PUBWEAK FREQME0_IRQHandler
        PUBWEAK FREQME0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FREQME0_IRQHandler
        LDR     R0, =FREQME0_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved71_IRQHandler
        PUBWEAK Reserved71_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved71_IRQHandler
        LDR     R0, =Reserved71_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved72_IRQHandler
        PUBWEAK Reserved72_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved72_IRQHandler
        LDR     R0, =Reserved72_DriverIRQHandler
        BX      R0

        PUBWEAK OS_EVENT_IRQHandler
        PUBWEAK OS_EVENT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
OS_EVENT_IRQHandler
        LDR     R0, =OS_EVENT_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved74_IRQHandler
        PUBWEAK Reserved74_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved74_IRQHandler
        LDR     R0, =Reserved74_DriverIRQHandler
        BX      R0

        PUBWEAK UTICK0_IRQHandler
        PUBWEAK UTICK0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
UTICK0_IRQHandler
        LDR     R0, =UTICK0_DriverIRQHandler
        BX      R0

        PUBWEAK WWDT0_IRQHandler
        PUBWEAK WWDT0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WWDT0_IRQHandler
        LDR     R0, =WWDT0_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved77_IRQHandler
        PUBWEAK Reserved77_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved77_IRQHandler
        LDR     R0, =Reserved77_DriverIRQHandler
        BX      R0

        PUBWEAK ADC0_IRQHandler
        PUBWEAK ADC0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ADC0_IRQHandler
        LDR     R0, =ADC0_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved79_IRQHandler
        PUBWEAK Reserved79_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved79_IRQHandler
        LDR     R0, =Reserved79_DriverIRQHandler
        BX      R0

        PUBWEAK CMP0_IRQHandler
        PUBWEAK CMP0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CMP0_IRQHandler
        LDR     R0, =CMP0_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved81_IRQHandler
        PUBWEAK Reserved81_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved81_IRQHandler
        LDR     R0, =Reserved81_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved82_IRQHandler
        PUBWEAK Reserved82_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved82_IRQHandler
        LDR     R0, =Reserved82_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved83_IRQHandler
        PUBWEAK Reserved83_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved83_IRQHandler
        LDR     R0, =Reserved83_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved84_IRQHandler
        PUBWEAK Reserved84_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved84_IRQHandler
        LDR     R0, =Reserved84_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved85_IRQHandler
        PUBWEAK Reserved85_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved85_IRQHandler
        LDR     R0, =Reserved85_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved86_IRQHandler
        PUBWEAK Reserved86_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved86_IRQHandler
        LDR     R0, =Reserved86_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO10_IRQHandler
        PUBWEAK GPIO10_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO10_IRQHandler
        LDR     R0, =GPIO10_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO11_IRQHandler
        PUBWEAK GPIO11_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO11_IRQHandler
        LDR     R0, =GPIO11_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO20_IRQHandler
        PUBWEAK GPIO20_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO20_IRQHandler
        LDR     R0, =GPIO20_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO21_IRQHandler
        PUBWEAK GPIO21_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO21_IRQHandler
        LDR     R0, =GPIO21_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO30_IRQHandler
        PUBWEAK GPIO30_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO30_IRQHandler
        LDR     R0, =GPIO30_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO31_IRQHandler
        PUBWEAK GPIO31_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO31_IRQHandler
        LDR     R0, =GPIO31_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved93_IRQHandler
        PUBWEAK Reserved93_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved93_IRQHandler
        LDR     R0, =Reserved93_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved94_IRQHandler
        PUBWEAK Reserved94_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved94_IRQHandler
        LDR     R0, =Reserved94_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved95_IRQHandler
        PUBWEAK Reserved95_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved95_IRQHandler
        LDR     R0, =Reserved95_DriverIRQHandler
        BX      R0

        PUBWEAK MU_A_TX_IRQHandler
        PUBWEAK MU_A_TX_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MU_A_TX_IRQHandler
        LDR     R0, =MU_A_TX_DriverIRQHandler
        BX      R0

        PUBWEAK MU_A_RX_IRQHandler
        PUBWEAK MU_A_RX_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MU_A_RX_IRQHandler
        LDR     R0, =MU_A_RX_DriverIRQHandler
        BX      R0

        PUBWEAK MU_A_INT_IRQHandler
        PUBWEAK MU_A_INT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MU_A_INT_IRQHandler
        LDR     R0, =MU_A_INT_DriverIRQHandler
        BX      R0

        PUBWEAK CDOG1_IRQHandler
        PUBWEAK CDOG1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CDOG1_IRQHandler
        LDR     R0, =CDOG1_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved100_IRQHandler
        PUBWEAK Reserved100_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved100_IRQHandler
        LDR     R0, =Reserved100_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved101_IRQHandler
        PUBWEAK Reserved101_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved101_IRQHandler
        LDR     R0, =Reserved101_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved102_IRQHandler
        PUBWEAK Reserved102_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved102_IRQHandler
        LDR     R0, =Reserved102_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved103_IRQHandler
        PUBWEAK Reserved103_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved103_IRQHandler
        LDR     R0, =Reserved103_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved104_IRQHandler
        PUBWEAK Reserved104_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved104_IRQHandler
        LDR     R0, =Reserved104_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved105_IRQHandler
        PUBWEAK Reserved105_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved105_IRQHandler
        LDR     R0, =Reserved105_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved106_IRQHandler
        PUBWEAK Reserved106_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved106_IRQHandler
        LDR     R0, =Reserved106_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved107_IRQHandler
        PUBWEAK Reserved107_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved107_IRQHandler
        LDR     R0, =Reserved107_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved108_IRQHandler
        PUBWEAK Reserved108_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved108_IRQHandler
        LDR     R0, =Reserved108_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved109_IRQHandler
        PUBWEAK Reserved109_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved109_IRQHandler
        LDR     R0, =Reserved109_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved110_IRQHandler
        PUBWEAK Reserved110_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved110_IRQHandler
        LDR     R0, =Reserved110_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved111_IRQHandler
        PUBWEAK Reserved111_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved111_IRQHandler
        LDR     R0, =Reserved111_DriverIRQHandler
        BX      R0

        PUBWEAK DMA1_CH0_IRQHandler
        PUBWEAK DMA1_CH0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_CH0_IRQHandler
        LDR     R0, =DMA1_CH0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA1_CH1_IRQHandler
        PUBWEAK DMA1_CH1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_CH1_IRQHandler
        LDR     R0, =DMA1_CH1_DriverIRQHandler
        BX      R0

        PUBWEAK DMA1_CH2_IRQHandler
        PUBWEAK DMA1_CH2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_CH2_IRQHandler
        LDR     R0, =DMA1_CH2_DriverIRQHandler
        BX      R0

        PUBWEAK DMA1_CH3_IRQHandler
        PUBWEAK DMA1_CH3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_CH3_IRQHandler
        LDR     R0, =DMA1_CH3_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved116_IRQHandler
        PUBWEAK Reserved116_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved116_IRQHandler
        LDR     R0, =Reserved116_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved117_IRQHandler
        PUBWEAK Reserved117_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved117_IRQHandler
        LDR     R0, =Reserved117_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved118_IRQHandler
        PUBWEAK Reserved118_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved118_IRQHandler
        LDR     R0, =Reserved118_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved119_IRQHandler
        PUBWEAK Reserved119_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved119_IRQHandler
        LDR     R0, =Reserved119_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved120_IRQHandler
        PUBWEAK Reserved120_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved120_IRQHandler
        LDR     R0, =Reserved120_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved121_IRQHandler
        PUBWEAK Reserved121_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved121_IRQHandler
        LDR     R0, =Reserved121_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved122_IRQHandler
        PUBWEAK Reserved122_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved122_IRQHandler
        LDR     R0, =Reserved122_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved123_IRQHandler
        PUBWEAK Reserved123_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved123_IRQHandler
        LDR     R0, =Reserved123_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved124_IRQHandler
        PUBWEAK Reserved124_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved124_IRQHandler
        LDR     R0, =Reserved124_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved125_IRQHandler
        PUBWEAK Reserved125_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved125_IRQHandler
        LDR     R0, =Reserved125_DriverIRQHandler
        BX      R0

        PUBWEAK PKC_IRQHandler
        PUBWEAK PKC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PKC_IRQHandler
        LDR     R0, =PKC_DriverIRQHandler
        BX      R0

        PUBWEAK SGI_IRQHandler
        PUBWEAK SGI_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SGI_IRQHandler
        LDR     R0, =SGI_DriverIRQHandler
        BX      R0

        PUBWEAK TRNG_IRQHandler
        PUBWEAK TRNG_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
TRNG_IRQHandler
        LDR     R0, =TRNG_DriverIRQHandler
        BX      R0

        PUBWEAK ERR_SGI_UDF_TRNG_PKC_IRQHandler
        PUBWEAK ERR_SGI_UDF_TRNG_PKC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ERR_SGI_UDF_TRNG_PKC_IRQHandler
        LDR     R0, =ERR_SGI_UDF_TRNG_PKC_DriverIRQHandler
        BX      R0

        PUBWEAK HYPERVISOR_IRQHandler
        PUBWEAK HYPERVISOR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
HYPERVISOR_IRQHandler
        LDR     R0, =HYPERVISOR_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved131_IRQHandler
        PUBWEAK Reserved131_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved131_IRQHandler
        LDR     R0, =Reserved131_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved132_IRQHandler
        PUBWEAK Reserved132_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved132_IRQHandler
        LDR     R0, =Reserved132_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved133_IRQHandler
        PUBWEAK Reserved133_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved133_IRQHandler
        LDR     R0, =Reserved133_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved134_IRQHandler
        PUBWEAK Reserved134_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved134_IRQHandler
        LDR     R0, =Reserved134_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved135_IRQHandler
        PUBWEAK Reserved135_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved135_IRQHandler
        LDR     R0, =Reserved135_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved136_IRQHandler
        PUBWEAK Reserved136_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved136_IRQHandler
        LDR     R0, =Reserved136_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved137_IRQHandler
        PUBWEAK Reserved137_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved137_IRQHandler
        LDR     R0, =Reserved137_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved138_IRQHandler
        PUBWEAK Reserved138_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved138_IRQHandler
        LDR     R0, =Reserved138_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved139_IRQHandler
        PUBWEAK Reserved139_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved139_IRQHandler
        LDR     R0, =Reserved139_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved140_IRQHandler
        PUBWEAK Reserved140_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved140_IRQHandler
        LDR     R0, =Reserved140_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved141_IRQHandler
        PUBWEAK Reserved141_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved141_IRQHandler
        LDR     R0, =Reserved141_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved142_IRQHandler
        PUBWEAK Reserved142_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved142_IRQHandler
        LDR     R0, =Reserved142_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved143_IRQHandler
        PUBWEAK Reserved143_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved143_IRQHandler
        LDR     R0, =Reserved143_DriverIRQHandler
        BX      R0

        PUBWEAK LPI2C0_AON_IRQHandler
        PUBWEAK LPI2C0_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C0_AON_IRQHandler
        LDR     R0, =LPI2C0_AON_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved145_IRQHandler
        PUBWEAK Reserved145_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved145_IRQHandler
        LDR     R0, =Reserved145_DriverIRQHandler
        BX      R0

        PUBWEAK LPUART0_AON_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART0_AON_IRQHandler
        LDR     R1, =LPUART_DriverIRQHandler
        LDR     R0, =2 ;instance number
        BX      R1

        PUBWEAK Reserved147_IRQHandler
        PUBWEAK Reserved147_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved147_IRQHandler
        LDR     R0, =Reserved147_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO00_AON_IRQHandler
        PUBWEAK GPIO00_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO00_AON_IRQHandler
        LDR     R0, =GPIO00_AON_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO01_AON_IRQHandler
        PUBWEAK GPIO01_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO01_AON_IRQHandler
        LDR     R0, =GPIO01_AON_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved150_IRQHandler
        PUBWEAK Reserved150_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved150_IRQHandler
        LDR     R0, =Reserved150_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved151_IRQHandler
        PUBWEAK Reserved151_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved151_IRQHandler
        LDR     R0, =Reserved151_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved152_IRQHandler
        PUBWEAK Reserved152_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved152_IRQHandler
        LDR     R0, =Reserved152_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved153_IRQHandler
        PUBWEAK Reserved153_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved153_IRQHandler
        LDR     R0, =Reserved153_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved154_IRQHandler
        PUBWEAK Reserved154_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved154_IRQHandler
        LDR     R0, =Reserved154_DriverIRQHandler
        BX      R0

        PUBWEAK LPCMP_IRQHandler
        PUBWEAK LPCMP_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPCMP_IRQHandler
        LDR     R0, =LPCMP_DriverIRQHandler
        BX      R0

        PUBWEAK RTC_ALARM0_IRQHandler
        PUBWEAK RTC_ALARM0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
RTC_ALARM0_IRQHandler
        LDR     R0, =RTC_ALARM0_DriverIRQHandler
        BX      R0

        PUBWEAK RTC_ALARM1_IRQHandler
        PUBWEAK RTC_ALARM1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
RTC_ALARM1_IRQHandler
        LDR     R0, =RTC_ALARM1_DriverIRQHandler
        BX      R0

        PUBWEAK RTC_ALARM2_IRQHandler
        PUBWEAK RTC_ALARM2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
RTC_ALARM2_IRQHandler
        LDR     R0, =RTC_ALARM2_DriverIRQHandler
        BX      R0

        PUBWEAK RTC_WDT_IRQHandler
        PUBWEAK RTC_WDT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
RTC_WDT_IRQHandler
        LDR     R0, =RTC_WDT_DriverIRQHandler
        BX      R0

        PUBWEAK RTC_XTAL_IRQHandler
        PUBWEAK RTC_XTAL_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
RTC_XTAL_IRQHandler
        LDR     R0, =RTC_XTAL_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved161_IRQHandler
        PUBWEAK Reserved161_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved161_IRQHandler
        LDR     R0, =Reserved161_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved162_IRQHandler
        PUBWEAK Reserved162_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved162_IRQHandler
        LDR     R0, =Reserved162_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved163_IRQHandler
        PUBWEAK Reserved163_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved163_IRQHandler
        LDR     R0, =Reserved163_DriverIRQHandler
        BX      R0

        PUBWEAK KPP_AON_IRQHandler
        PUBWEAK KPP_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
KPP_AON_IRQHandler
        LDR     R0, =KPP_AON_DriverIRQHandler
        BX      R0

        PUBWEAK LPADC_AON_IRQHandler
        PUBWEAK LPADC_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPADC_AON_IRQHandler
        LDR     R0, =LPADC_AON_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved166_IRQHandler
        PUBWEAK Reserved166_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved166_IRQHandler
        LDR     R0, =Reserved166_DriverIRQHandler
        BX      R0

        PUBWEAK QTMR0_AON_IRQHandler
        PUBWEAK QTMR0_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
QTMR0_AON_IRQHandler
        LDR     R0, =QTMR0_AON_DriverIRQHandler
        BX      R0

        PUBWEAK QTMR1_AON_IRQHandler
        PUBWEAK QTMR1_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
QTMR1_AON_IRQHandler
        LDR     R0, =QTMR1_AON_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved169_IRQHandler
        PUBWEAK Reserved169_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved169_IRQHandler
        LDR     R0, =Reserved169_DriverIRQHandler
        BX      R0

        PUBWEAK LCSENSE_IRQHandler
        PUBWEAK LCSENSE_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LCSENSE_IRQHandler
        LDR     R0, =LCSENSE_DriverIRQHandler
        BX      R0

        PUBWEAK LPTMR_AON_IRQHandler
        PUBWEAK LPTMR_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPTMR_AON_IRQHandler
        LDR     R0, =LPTMR_AON_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved172_IRQHandler
        PUBWEAK Reserved172_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved172_IRQHandler
        LDR     R0, =Reserved172_DriverIRQHandler
        BX      R0

        PUBWEAK ACMP_AON_IRQHandler
        PUBWEAK ACMP_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ACMP_AON_IRQHandler
        LDR     R0, =ACMP_AON_DriverIRQHandler
        BX      R0

        PUBWEAK ADVC_IRQHandler
        PUBWEAK ADVC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ADVC_IRQHandler
        LDR     R0, =ADVC_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved175_IRQHandler
        PUBWEAK Reserved175_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved175_IRQHandler
        LDR     R0, =Reserved175_DriverIRQHandler
        BX      R0

        PUBWEAK SGLCD_FRAME_AON_IRQHandler
        PUBWEAK SGLCD_FRAME_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SGLCD_FRAME_AON_IRQHandler
        LDR     R0, =SGLCD_FRAME_AON_DriverIRQHandler
        BX      R0

        PUBWEAK SGLCD_FFAULT_AON_IRQHandler
        PUBWEAK SGLCD_FFAULT_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SGLCD_FFAULT_AON_IRQHandler
        LDR     R0, =SGLCD_FFAULT_AON_DriverIRQHandler
        BX      R0

Reserved16_DriverIRQHandler
CMC_DriverIRQHandler
DMA0_CH0_DriverIRQHandler
DMA0_CH1_DriverIRQHandler
DMA0_CH2_DriverIRQHandler
DMA0_CH3_DriverIRQHandler
Reserved22_DriverIRQHandler
Reserved23_DriverIRQHandler
Reserved24_DriverIRQHandler
Reserved25_DriverIRQHandler
ERM0_DriverIRQHandler
Reserved27_DriverIRQHandler
FMU0_DriverIRQHandler
GLIKEY0_DriverIRQHandler
MBC0_DriverIRQHandler
SCG0_DriverIRQHandler
Reserved32_DriverIRQHandler
Reserved33_DriverIRQHandler
WUU0_DriverIRQHandler
Reserved35_DriverIRQHandler
Reserved36_DriverIRQHandler
Reserved37_DriverIRQHandler
Reserved38_DriverIRQHandler
Reserved39_DriverIRQHandler
Reserved40_DriverIRQHandler
Reserved41_DriverIRQHandler
LPI2C0_DriverIRQHandler
LPI2C1_DriverIRQHandler
LPSPI0_DriverIRQHandler
LPSPI1_DriverIRQHandler
Reserved46_DriverIRQHandler
LPUART_DriverIRQHandler
LPUART_DriverIRQHandler
Reserved49_DriverIRQHandler
Reserved50_DriverIRQHandler
Reserved51_DriverIRQHandler
Reserved52_DriverIRQHandler
Reserved53_DriverIRQHandler
CDOG0_DriverIRQHandler
CTIMER0_DriverIRQHandler
CTIMER1_DriverIRQHandler
CTIMER2_DriverIRQHandler
Reserved58_DriverIRQHandler
Reserved59_DriverIRQHandler
Reserved60_DriverIRQHandler
Reserved61_DriverIRQHandler
Reserved62_DriverIRQHandler
Reserved63_DriverIRQHandler
Reserved64_DriverIRQHandler
Reserved65_DriverIRQHandler
Reserved66_DriverIRQHandler
Reserved67_DriverIRQHandler
Reserved68_DriverIRQHandler
Reserved69_DriverIRQHandler
FREQME0_DriverIRQHandler
Reserved71_DriverIRQHandler
Reserved72_DriverIRQHandler
OS_EVENT_DriverIRQHandler
Reserved74_DriverIRQHandler
UTICK0_DriverIRQHandler
WWDT0_DriverIRQHandler
Reserved77_DriverIRQHandler
ADC0_DriverIRQHandler
Reserved79_DriverIRQHandler
CMP0_DriverIRQHandler
Reserved81_DriverIRQHandler
Reserved82_DriverIRQHandler
Reserved83_DriverIRQHandler
Reserved84_DriverIRQHandler
Reserved85_DriverIRQHandler
Reserved86_DriverIRQHandler
GPIO10_DriverIRQHandler
GPIO11_DriverIRQHandler
GPIO20_DriverIRQHandler
GPIO21_DriverIRQHandler
GPIO30_DriverIRQHandler
GPIO31_DriverIRQHandler
Reserved93_DriverIRQHandler
Reserved94_DriverIRQHandler
Reserved95_DriverIRQHandler
MU_A_TX_DriverIRQHandler
MU_A_RX_DriverIRQHandler
MU_A_INT_DriverIRQHandler
CDOG1_DriverIRQHandler
Reserved100_DriverIRQHandler
Reserved101_DriverIRQHandler
Reserved102_DriverIRQHandler
Reserved103_DriverIRQHandler
Reserved104_DriverIRQHandler
Reserved105_DriverIRQHandler
Reserved106_DriverIRQHandler
Reserved107_DriverIRQHandler
Reserved108_DriverIRQHandler
Reserved109_DriverIRQHandler
Reserved110_DriverIRQHandler
Reserved111_DriverIRQHandler
DMA1_CH0_DriverIRQHandler
DMA1_CH1_DriverIRQHandler
DMA1_CH2_DriverIRQHandler
DMA1_CH3_DriverIRQHandler
Reserved116_DriverIRQHandler
Reserved117_DriverIRQHandler
Reserved118_DriverIRQHandler
Reserved119_DriverIRQHandler
Reserved120_DriverIRQHandler
Reserved121_DriverIRQHandler
Reserved122_DriverIRQHandler
Reserved123_DriverIRQHandler
Reserved124_DriverIRQHandler
Reserved125_DriverIRQHandler
PKC_DriverIRQHandler
SGI_DriverIRQHandler
TRNG_DriverIRQHandler
ERR_SGI_UDF_TRNG_PKC_DriverIRQHandler
HYPERVISOR_DriverIRQHandler
Reserved131_DriverIRQHandler
Reserved132_DriverIRQHandler
Reserved133_DriverIRQHandler
Reserved134_DriverIRQHandler
Reserved135_DriverIRQHandler
Reserved136_DriverIRQHandler
Reserved137_DriverIRQHandler
Reserved138_DriverIRQHandler
Reserved139_DriverIRQHandler
Reserved140_DriverIRQHandler
Reserved141_DriverIRQHandler
Reserved142_DriverIRQHandler
Reserved143_DriverIRQHandler
LPI2C0_AON_DriverIRQHandler
Reserved145_DriverIRQHandler
LPUART_DriverIRQHandler
Reserved147_DriverIRQHandler
GPIO00_AON_DriverIRQHandler
GPIO01_AON_DriverIRQHandler
Reserved150_DriverIRQHandler
Reserved151_DriverIRQHandler
Reserved152_DriverIRQHandler
Reserved153_DriverIRQHandler
Reserved154_DriverIRQHandler
LPCMP_DriverIRQHandler
RTC_ALARM0_DriverIRQHandler
RTC_ALARM1_DriverIRQHandler
RTC_ALARM2_DriverIRQHandler
RTC_WDT_DriverIRQHandler
RTC_XTAL_DriverIRQHandler
Reserved161_DriverIRQHandler
Reserved162_DriverIRQHandler
Reserved163_DriverIRQHandler
KPP_AON_DriverIRQHandler
LPADC_AON_DriverIRQHandler
Reserved166_DriverIRQHandler
QTMR0_AON_DriverIRQHandler
QTMR1_AON_DriverIRQHandler
Reserved169_DriverIRQHandler
LCSENSE_DriverIRQHandler
LPTMR_AON_DriverIRQHandler
Reserved172_DriverIRQHandler
ACMP_AON_DriverIRQHandler
ADVC_DriverIRQHandler
Reserved175_DriverIRQHandler
SGLCD_FRAME_AON_DriverIRQHandler
SGLCD_FFAULT_AON_DriverIRQHandler
DefaultISR
        B .

        END
