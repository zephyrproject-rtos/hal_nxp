/* ------------------------------------------------------------------------- */
/*  @file:    startup_MCXW716A.s                                             */
/*  @purpose: CMSIS Cortex-M33 Core Device Startup File                      */
/*            MCXW716A                                                       */
/*  @version: 1.0                                                            */
/*  @date:    2024-3-21                                                      */
/*  @build:   b240321                                                        */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Copyright 1997-2016 Freescale Semiconductor, Inc.                         */
/* Copyright 2016-2024 NXP                                                   */
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
        DCD     CTI_IRQHandler                                ;Cross Trigger Interface interrupt
        DCD     CMC0_IRQHandler                               ;Core Mode Controller interrupt
        DCD     DMA0_CH0_IRQHandler                           ;eDMA channel 0 error or transfer complete
        DCD     DMA0_CH1_IRQHandler                           ;eDMA channel 1 error or transfer complete
        DCD     DMA0_CH2_IRQHandler                           ;eDMA channel 2 error or transfer complete
        DCD     DMA0_CH3_IRQHandler                           ;eDMA channel 3 error or transfer complete
        DCD     DMA0_CH4_IRQHandler                           ;eDMA channel 4 error or transfer complete
        DCD     DMA0_CH5_IRQHandler                           ;eDMA channel 5 error or transfer complete
        DCD     DMA0_CH6_IRQHandler                           ;eDMA channel 6 error or transfer complete
        DCD     DMA0_CH7_IRQHandler                           ;eDMA channel 7 error or transfer complete
        DCD     DMA0_CH8_IRQHandler                           ;eDMA channel 8 error or transfer complete
        DCD     DMA0_CH9_IRQHandler                           ;eDMA channel 9 error or transfer complete
        DCD     DMA0_CH10_IRQHandler                          ;eDMA channel 10 error or transfer complete
        DCD     DMA0_CH11_IRQHandler                          ;eDMA channel 11 error or transfer complete
        DCD     DMA0_CH12_IRQHandler                          ;eDMA channel 12 error or transfer complete
        DCD     DMA0_CH13_IRQHandler                          ;eDMA channel 13 error or transfer complete
        DCD     DMA0_CH14_IRQHandler                          ;eDMA channel 14 error or transfer complete
        DCD     DMA0_CH15_IRQHandler                          ;eDMA channel 15 error or transfer complete
        DCD     EWM0_IRQHandler                               ;External Watchdog Monitor 0 interrupt
        DCD     MCM0_IRQHandler                               ;Miscellaneous Control Module interrupt
        DCD     MSCM0_IRQHandler                              ;Miscellaneous System Control Module interrupt
        DCD     SPC0_IRQHandler                               ;System Power Controller 0 interrupt
        DCD     WUU0_IRQHandler                               ;Wake-Up Unit 0 interrupt
        DCD     WDOG0_IRQHandler                              ;Watchdog Timer 0 interrupt
        DCD     WDOG1_IRQHandler                              ;Watchdog Timer 1 interrupt
        DCD     SCG0_IRQHandler                               ;System Clock Generator 0 interrupt
        DCD     SFA0_IRQHandler                               ;Singal Frequency Analyzer 0 interrupt
        DCD     FMU0_IRQHandler                               ;Flash Memory Unit 0 interrupt
        DCD     ELE_CMD_IRQHandler                            ;EdgeLock enclave command interface interrupt
        DCD     ELE_SECURE_IRQHandler                         ;EdgeLock enclave interrupt
        DCD     ELE_NONSECURE_IRQHandler                      ;EdgeLock enclave non-secure interrupt
        DCD     TRDC0_IRQHandler                              ;Trusted Resource Domain Controller 0 interrupt
        DCD     RTC_Alarm_IRQHandler                          ;Real Time Clock 0 alarm interrupt
        DCD     RTC_Seconds_IRQHandler                        ;Real Time Clock 0 seconds interrupt
        DCD     LPTMR0_IRQHandler                             ;Low-Power Timer0 interrupt
        DCD     LPTMR1_IRQHandler                             ;Low-Power Timer1 interrupt
        DCD     LPIT0_IRQHandler                              ;Low-Power Periodic Interrupt Timer 0 interrupt
        DCD     TPM0_IRQHandler                               ;Timer / PWM Module 0 interrupt
        DCD     TPM1_IRQHandler                               ;Timer / PWM Module 1 interrupt
        DCD     LPI2C0_IRQHandler                             ;Low-Power Inter Integrated Circuit 0 interrupt
        DCD     LPI2C1_IRQHandler                             ;Low-Power Inter Integrated Circuit 1 interrupt
        DCD     I3C0_IRQHandler                               ;Improved Inter-Integrated Circuit 0 interrupt
        DCD     LPSPI0_IRQHandler                             ;Low-Power Serial Peripheral Interface 0 interrupt
        DCD     LPSPI1_IRQHandler                             ;Low-Power Serial Peripheral Interface 1 interrupt
        DCD     LPUART0_IRQHandler                            ;Low-Power Universal Asynchronous Receiver/Transmitter 0 interrupt
        DCD     LPUART1_IRQHandler                            ;Low-Power Universal Asynchronous Receiver/Transmitter 1 interrupt
        DCD     FLEXIO0_IRQHandler                            ;Flexible Input/Output 0 interrupt
        DCD     Reserved63_IRQHandler                         ;Reserved interrupt
        DCD     RF_IMU0_IRQHandler                            ;Radio IMU interrupt 0 (msg_rdy_imu)
        DCD     RF_IMU1_IRQHandler                            ;Radio IMU interrupt 1(msg_space_avail_imu)
        DCD     RF_NBU_IRQHandler                             ;Radio NBU timeout interrupt
        DCD     RF_FMU_IRQHandler                             ;Radio FMU interrupt
        DCD     RF_WOR_IRQHandler                             ;Radio WOR RX FAIL interrupt
        DCD     RF_802_15_4_IRQHandler                        ;Radio Frequency 2.4GHz - 802.15.4 Link Layer interrupt
        DCD     RF_Generic_IRQHandler                         ;Radio Frequency 2.4 GHz - Generic Link Layer interrupt
        DCD     RF_BRIC_IRQHandler                            ;Radio Frequency 2.4 GHz - BRIC interrupt
        DCD     RF_LANT_SW_IRQHandler                         ;Radio Transceiver - Radio LANT_SW interrupt
        DCD     RFMC_IRQHandler                               ;RFMC interrupt
        DCD     DSB_IRQHandler                                ;Data Stream Buffer interrupt
        DCD     GPIOA_INT0_IRQHandler                         ;General Purpose Input/Output A interrupt 0
        DCD     GPIOA_INT1_IRQHandler                         ;General Purpose Input/Output A interrupt 1
        DCD     GPIOB_INT0_IRQHandler                         ;General Purpose Input/Output B interrupt 0
        DCD     GPIOB_INT1_IRQHandler                         ;General Purpose Input/Output B interrupt 1
        DCD     GPIOC_INT0_IRQHandler                         ;General Purpose Input/Output C interrupt 0
        DCD     GPIOC_INT1_IRQHandler                         ;General Purpose Input/Output C interrupt 1
        DCD     GPIOD_INT0_IRQHandler                         ;General Purpose Input/Output D interrupt 0
        DCD     GPIOD_INT1_IRQHandler                         ;General Purpose Input/Output D interrupt 1
        DCD     PORTA_EFT_IRQHandler                          ;PortA EFT interrupt
        DCD     PORTB_EFT_IRQHandler                          ;PortB EFT interrupt
        DCD     PORTC_EFT_IRQHandler                          ;PortC EFT interrupt
        DCD     PORTD_EFT_IRQHandler                          ;PortD EFT interrupt
        DCD     ADC0_IRQHandler                               ;Analog-to-Digital Converter 0 interrupt
        DCD     LPCMP0_IRQHandler                             ;Low-Power Comparator 0 interrupt
        DCD     LPCMP1_IRQHandler                             ;Low-Power Comparator 1 interrupt
        DCD     VBAT_IRQHandler                               ;Smart Power Switch Domain interrupt
        DCD     Reserved91_IRQHandler                         ;Reserved interrupt
        DCD     DefaultISR                                    ;92
        DCD     DefaultISR                                    ;93
        DCD     DefaultISR                                    ;94
        DCD     DefaultISR                                    ;95
        DCD     DefaultISR                                    ;96
        DCD     DefaultISR                                    ;97
        DCD     DefaultISR                                    ;98
        DCD     DefaultISR                                    ;99
        DCD     DefaultISR                                    ;100
        DCD     DefaultISR                                    ;101
        DCD     DefaultISR                                    ;102
        DCD     DefaultISR                                    ;103
        DCD     DefaultISR                                    ;104
        DCD     DefaultISR                                    ;105
        DCD     DefaultISR                                    ;106
        DCD     DefaultISR                                    ;107
        DCD     DefaultISR                                    ;108
        DCD     DefaultISR                                    ;109
        DCD     DefaultISR                                    ;110
        DCD     DefaultISR                                    ;111
        DCD     DefaultISR                                    ;112
        DCD     DefaultISR                                    ;113
        DCD     DefaultISR                                    ;114
        DCD     DefaultISR                                    ;115
        DCD     DefaultISR                                    ;116
        DCD     DefaultISR                                    ;117
        DCD     DefaultISR                                    ;118
        DCD     DefaultISR                                    ;119
        DCD     DefaultISR                                    ;120
        DCD     DefaultISR                                    ;121
        DCD     DefaultISR                                    ;122
        DCD     DefaultISR                                    ;123
        DCD     DefaultISR                                    ;124
        DCD     DefaultISR                                    ;125
        DCD     DefaultISR                                    ;126
        DCD     DefaultISR                                    ;127
        DCD     DefaultISR                                    ;128
        DCD     DefaultISR                                    ;129
        DCD     DefaultISR                                    ;130
        DCD     DefaultISR                                    ;131
        DCD     DefaultISR                                    ;132
        DCD     DefaultISR                                    ;133
        DCD     DefaultISR                                    ;134
        DCD     DefaultISR                                    ;135
        DCD     DefaultISR                                    ;136
        DCD     DefaultISR                                    ;137
        DCD     DefaultISR                                    ;138
        DCD     DefaultISR                                    ;139
        DCD     DefaultISR                                    ;140
        DCD     DefaultISR                                    ;141
        DCD     DefaultISR                                    ;142
        DCD     DefaultISR                                    ;143
        DCD     DefaultISR                                    ;144
        DCD     DefaultISR                                    ;145
        DCD     DefaultISR                                    ;146
        DCD     DefaultISR                                    ;147
        DCD     DefaultISR                                    ;148
        DCD     DefaultISR                                    ;149
        DCD     DefaultISR                                    ;150
        DCD     DefaultISR                                    ;151
        DCD     DefaultISR                                    ;152
        DCD     DefaultISR                                    ;153
        DCD     DefaultISR                                    ;154
        DCD     DefaultISR                                    ;155
        DCD     DefaultISR                                    ;156
        DCD     DefaultISR                                    ;157
        DCD     DefaultISR                                    ;158
        DCD     DefaultISR                                    ;159
        DCD     DefaultISR                                    ;160
        DCD     DefaultISR                                    ;161
        DCD     DefaultISR                                    ;162
        DCD     DefaultISR                                    ;163
        DCD     DefaultISR                                    ;164
        DCD     DefaultISR                                    ;165
        DCD     DefaultISR                                    ;166
        DCD     DefaultISR                                    ;167
        DCD     DefaultISR                                    ;168
        DCD     DefaultISR                                    ;169
        DCD     DefaultISR                                    ;170
        DCD     DefaultISR                                    ;171
        DCD     DefaultISR                                    ;172
        DCD     DefaultISR                                    ;173
        DCD     DefaultISR                                    ;174
        DCD     DefaultISR                                    ;175
        DCD     DefaultISR                                    ;176
        DCD     DefaultISR                                    ;177
        DCD     DefaultISR                                    ;178
        DCD     DefaultISR                                    ;179
        DCD     DefaultISR                                    ;180
        DCD     DefaultISR                                    ;181
        DCD     DefaultISR                                    ;182
        DCD     DefaultISR                                    ;183
        DCD     DefaultISR                                    ;184
        DCD     DefaultISR                                    ;185
        DCD     DefaultISR                                    ;186
        DCD     DefaultISR                                    ;187
        DCD     DefaultISR                                    ;188
        DCD     DefaultISR                                    ;189
        DCD     DefaultISR                                    ;190
        DCD     DefaultISR                                    ;191
        DCD     DefaultISR                                    ;192
        DCD     DefaultISR                                    ;193
        DCD     DefaultISR                                    ;194
        DCD     DefaultISR                                    ;195
        DCD     DefaultISR                                    ;196
        DCD     DefaultISR                                    ;197
        DCD     DefaultISR                                    ;198
        DCD     DefaultISR                                    ;199
        DCD     DefaultISR                                    ;200
        DCD     DefaultISR                                    ;201
        DCD     DefaultISR                                    ;202
        DCD     DefaultISR                                    ;203
        DCD     DefaultISR                                    ;204
        DCD     DefaultISR                                    ;205
        DCD     DefaultISR                                    ;206
        DCD     DefaultISR                                    ;207
        DCD     DefaultISR                                    ;208
        DCD     DefaultISR                                    ;209
        DCD     DefaultISR                                    ;210
        DCD     DefaultISR                                    ;211
        DCD     DefaultISR                                    ;212
        DCD     DefaultISR                                    ;213
        DCD     DefaultISR                                    ;214
        DCD     DefaultISR                                    ;215
        DCD     DefaultISR                                    ;216
        DCD     DefaultISR                                    ;217
        DCD     DefaultISR                                    ;218
        DCD     DefaultISR                                    ;219
        DCD     DefaultISR                                    ;220
        DCD     DefaultISR                                    ;221
        DCD     DefaultISR                                    ;222
        DCD     DefaultISR                                    ;223
        DCD     DefaultISR                                    ;224
        DCD     DefaultISR                                    ;225
        DCD     DefaultISR                                    ;226
        DCD     DefaultISR                                    ;227
        DCD     DefaultISR                                    ;228
        DCD     DefaultISR                                    ;229
        DCD     DefaultISR                                    ;230
        DCD     DefaultISR                                    ;231
        DCD     DefaultISR                                    ;232
        DCD     DefaultISR                                    ;233
        DCD     DefaultISR                                    ;234
        DCD     DefaultISR                                    ;235
        DCD     DefaultISR                                    ;236
        DCD     DefaultISR                                    ;237
        DCD     DefaultISR                                    ;238
        DCD     DefaultISR                                    ;239
        DCD     DefaultISR                                    ;240
        DCD     DefaultISR                                    ;241
        DCD     DefaultISR                                    ;242
        DCD     DefaultISR                                    ;243
        DCD     DefaultISR                                    ;244
        DCD     DefaultISR                                    ;245
        DCD     DefaultISR                                    ;246
        DCD     DefaultISR                                    ;247
        DCD     DefaultISR                                    ;248
        DCD     DefaultISR                                    ;249
        DCD     DefaultISR                                    ;250
        DCD     DefaultISR                                    ;251
        DCD     DefaultISR                                    ;252
        DCD     DefaultISR                                    ;253
        DCD     DefaultISR                                    ;254
        DCD     DefaultISR                                    ;255
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

#if !defined(BYPASS_ECC_RAM_INIT)
        LDR     R0, =0x04000000
        LDR     R1, =.ram_init_ctcm01
        BICS.W  R1, #0x10000000
        CMP     R0, R1
        BCC.N   .ram_init_done  ; Bypass ECC RAM initialization on RAM target, debugger will do the initialization

.ram_init_ctcm01:               ; Initialize CTCM01
        LDR     R0, =0x4000000
        LDR     R1, =0x4004000
        LDR     R2, =0
        LDR     R3, =0
        LDR     R4, =0
        LDR     R5, =0
.loop01:
        STMIA   R0!, {R2 - R5}
        CMP     R0, R1
        BCC.N   .loop01

.ram_init_stcm012:              ; Initialize STCM012
        LDR     R0, =0x20000000
        LDR     R1, =0x20010000
.loop012:
        STMIA   R0!, {R2 - R5}
        CMP     R0, R1
        BCC.N   .loop012

.ram_init_stcm5:
        LDR     R0, =0x2001A000
        LDR     R1, =0x2001C000
.loop5:                         ; Initialize STCM5
        STMIA   R0!, {R2 - R5}
        CMP     R0, R1
        BCC.N   .loop5

.ram_init_done:
#endif
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

        PUBWEAK CTI_IRQHandler
        PUBWEAK CMC0_IRQHandler
        PUBWEAK DMA0_CH0_IRQHandler
        PUBWEAK DMA0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH0_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH1_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH2_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH3_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH4_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH5_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH6_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH7_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH7_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH8_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH8_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH9_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH9_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH10_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH10_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH11_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH11_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH12_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH12_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH13_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH13_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH14_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH14_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_CH15_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_CH15_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK EWM0_IRQHandler
        PUBWEAK MCM0_IRQHandler
        PUBWEAK MSCM0_IRQHandler
        PUBWEAK SPC0_IRQHandler
        PUBWEAK WUU0_IRQHandler
        PUBWEAK WDOG0_IRQHandler
        PUBWEAK WDOG1_IRQHandler
        PUBWEAK SCG0_IRQHandler
        PUBWEAK SFA0_IRQHandler
        PUBWEAK SFA0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SFA0_IRQHandler
        LDR     R0, =SFA0_DriverIRQHandler
        BX      R0

        PUBWEAK FMU0_IRQHandler
        PUBWEAK ELE_CMD_IRQHandler
        PUBWEAK ELE_SECURE_IRQHandler
        PUBWEAK ELE_NONSECURE_IRQHandler
        PUBWEAK TRDC0_IRQHandler
        PUBWEAK RTC_Alarm_IRQHandler
        PUBWEAK RTC_Seconds_IRQHandler
        PUBWEAK LPTMR0_IRQHandler
        PUBWEAK LPTMR1_IRQHandler
        PUBWEAK LPIT0_IRQHandler
        PUBWEAK TPM0_IRQHandler
        PUBWEAK TPM1_IRQHandler
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

        PUBWEAK I3C0_IRQHandler
        PUBWEAK I3C0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I3C0_IRQHandler
        LDR     R0, =I3C0_DriverIRQHandler
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

        PUBWEAK FLEXIO0_IRQHandler
        PUBWEAK FLEXIO0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXIO0_IRQHandler
        LDR     R0, =FLEXIO0_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved63_IRQHandler
        PUBWEAK RF_IMU0_IRQHandler
        PUBWEAK RF_IMU1_IRQHandler
        PUBWEAK RF_NBU_IRQHandler
        PUBWEAK RF_FMU_IRQHandler
        PUBWEAK RF_WOR_IRQHandler
        PUBWEAK RF_802_15_4_IRQHandler
        PUBWEAK RF_Generic_IRQHandler
        PUBWEAK RF_BRIC_IRQHandler
        PUBWEAK RF_LANT_SW_IRQHandler
        PUBWEAK RFMC_IRQHandler
        PUBWEAK DSB_IRQHandler
        PUBWEAK GPIOA_INT0_IRQHandler
        PUBWEAK GPIOA_INT1_IRQHandler
        PUBWEAK GPIOB_INT0_IRQHandler
        PUBWEAK GPIOB_INT1_IRQHandler
        PUBWEAK GPIOC_INT0_IRQHandler
        PUBWEAK GPIOC_INT1_IRQHandler
        PUBWEAK GPIOD_INT0_IRQHandler
        PUBWEAK GPIOD_INT1_IRQHandler
        PUBWEAK PORTA_EFT_IRQHandler
        PUBWEAK PORTB_EFT_IRQHandler
        PUBWEAK PORTC_EFT_IRQHandler
        PUBWEAK PORTD_EFT_IRQHandler
        PUBWEAK ADC0_IRQHandler
        PUBWEAK LPCMP0_IRQHandler
        PUBWEAK LPCMP1_IRQHandler
        PUBWEAK VBAT_IRQHandler
        PUBWEAK Reserved91_IRQHandler
        PUBWEAK DefaultISR
        SECTION .text:CODE:REORDER:NOROOT(1)
CTI_IRQHandler
CMC0_IRQHandler
DMA0_DriverIRQHandler
EWM0_IRQHandler
MCM0_IRQHandler
MSCM0_IRQHandler
SPC0_IRQHandler
WUU0_IRQHandler
WDOG0_IRQHandler
WDOG1_IRQHandler
SCG0_IRQHandler
SFA0_DriverIRQHandler
FMU0_IRQHandler
ELE_CMD_IRQHandler
ELE_SECURE_IRQHandler
ELE_NONSECURE_IRQHandler
TRDC0_IRQHandler
RTC_Alarm_IRQHandler
RTC_Seconds_IRQHandler
LPTMR0_IRQHandler
LPTMR1_IRQHandler
LPIT0_IRQHandler
TPM0_IRQHandler
TPM1_IRQHandler
LPI2C0_DriverIRQHandler
LPI2C1_DriverIRQHandler
I3C0_DriverIRQHandler
LPSPI0_DriverIRQHandler
LPSPI1_DriverIRQHandler
LPUART0_DriverIRQHandler
LPUART1_DriverIRQHandler
FLEXIO0_DriverIRQHandler
Reserved63_IRQHandler
RF_IMU0_IRQHandler
RF_IMU1_IRQHandler
RF_NBU_IRQHandler
RF_FMU_IRQHandler
RF_WOR_IRQHandler
RF_802_15_4_IRQHandler
RF_Generic_IRQHandler
RF_BRIC_IRQHandler
RF_LANT_SW_IRQHandler
RFMC_IRQHandler
DSB_IRQHandler
GPIOA_INT0_IRQHandler
GPIOA_INT1_IRQHandler
GPIOB_INT0_IRQHandler
GPIOB_INT1_IRQHandler
GPIOC_INT0_IRQHandler
GPIOC_INT1_IRQHandler
GPIOD_INT0_IRQHandler
GPIOD_INT1_IRQHandler
PORTA_EFT_IRQHandler
PORTB_EFT_IRQHandler
PORTC_EFT_IRQHandler
PORTD_EFT_IRQHandler
ADC0_IRQHandler
LPCMP0_IRQHandler
LPCMP1_IRQHandler
VBAT_IRQHandler
Reserved91_IRQHandler
DefaultISR
        B DefaultISR

        END
