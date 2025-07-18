; -------------------------------------------------------------------------
;  @file:    startup_MCXE245.s
;  @purpose: CMSIS Cortex-M4 Core Device Startup File
;            MCXE245
;  @version: 1.0
;  @date:    2025-2-21
;  @build:   b250429
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
        DCD     DMA0_IRQHandler                               ;DMA channel 0 transfer complete
        DCD     DMA1_IRQHandler                               ;DMA channel 1 transfer complete
        DCD     DMA2_IRQHandler                               ;DMA channel 2 transfer complete
        DCD     DMA3_IRQHandler                               ;DMA channel 3 transfer complete
        DCD     DMA4_IRQHandler                               ;DMA channel 4 transfer complete
        DCD     DMA5_IRQHandler                               ;DMA channel 5 transfer complete
        DCD     DMA6_IRQHandler                               ;DMA channel 6 transfer complete
        DCD     DMA7_IRQHandler                               ;DMA channel 7 transfer complete
        DCD     DMA8_IRQHandler                               ;DMA channel 8 transfer complete
        DCD     DMA9_IRQHandler                               ;DMA channel 9 transfer complete
        DCD     DMA10_IRQHandler                              ;DMA channel 10 transfer complete
        DCD     DMA11_IRQHandler                              ;DMA channel 11 transfer complete
        DCD     DMA12_IRQHandler                              ;DMA channel 12 transfer complete
        DCD     DMA13_IRQHandler                              ;DMA channel 13 transfer complete
        DCD     DMA14_IRQHandler                              ;DMA channel 14 transfer complete
        DCD     DMA15_IRQHandler                              ;DMA channel 15 transfer complete
        DCD     DMA_Error_IRQHandler                          ;DMA error interrupt channels 0-15
        DCD     MCM_IRQHandler                                ;FPU sources
        DCD     FTFC_CMD_IRQHandler                           ;FTFC Command complete
        DCD     FTFC_Read_Collision_IRQHandler                ;FTFC Read collision
        DCD     LVD_LVW_IRQHandler                            ;PMC Low voltage detect interrupt
        DCD     FTFM_Fault_IRQHandler                         ;FTFM Double bit fault detect
        DCD     WDOG_EWM_IRQHandler                           ;Interrupt request out before WDOG reset out, EWM output as interrupt
        DCD     RCM_IRQHandler                                ;RCM Asynchronous Interrupt
        DCD     LPI2C0_Master_IRQHandler                      ;LPI2C0 Master Interrupt
        DCD     LPI2C0_Slave_IRQHandler                       ;LPI2C0 Slave Interrupt
        DCD     LPSPI0_IRQHandler                             ;LPSPI0 Interrupt
        DCD     LPSPI1_IRQHandler                             ;LPSPI1 Interrupt
        DCD     LPSPI2_IRQHandler                             ;LPSPI2 Interrupt
        DCD     Reserved45_IRQHandler                         ;xxx Interrupt 45
        DCD     Reserved46_IRQHandler                         ;xxx Interrupt 46
        DCD     LPUART0_IRQHandler                            ;Low-Power Universal Asynchronous Receive/Transmit interrupt
        DCD     Reserved48_IRQHandler                         ;xxx Interrupt 48
        DCD     LPUART1_IRQHandler                            ;Low-Power Universal Asynchronous Receive/Transmit interrupt
        DCD     Reserved50_IRQHandler                         ;xxx Interrupt 50
        DCD     LPUART2_IRQHandler                            ;Low-Power Universal Asynchronous Receive/Transmit interrupt
        DCD     Reserved52_IRQHandler                         ;xxx Interrupt 52
        DCD     Reserved53_IRQHandler                         ;xxx Interrupt 53
        DCD     Reserved54_IRQHandler                         ;xxx Interrupt 54
        DCD     ADC0_IRQHandler                               ;Analog-to-Digital Converter interrupt
        DCD     ADC1_IRQHandler                               ;Analog-to-Digital Converter interrupt
        DCD     CMP0_IRQHandler                               ;Comparator interrupt
        DCD     Reserved58_IRQHandler                         ;xxx Interrupt 58
        DCD     Reserved59_IRQHandler                         ;xxx Interrupt 59
        DCD     ERM_single_fault_IRQHandler                   ;ERM single bit error correction
        DCD     ERM_double_fault_IRQHandler                   ;ERM double bit error non-correctable
        DCD     RTC_IRQHandler                                ;RTC alarm interrupt
        DCD     RTC_Seconds_IRQHandler                        ;RTC seconds interrupt
        DCD     LPIT0_Ch0_IRQHandler                          ;LPIT0 channel 0 overflow interrupt
        DCD     LPIT0_Ch1_IRQHandler                          ;LPIT0 channel 1 overflow interrupt
        DCD     LPIT0_Ch2_IRQHandler                          ;LPIT0 channel 2 overflow interrupt
        DCD     LPIT0_Ch3_IRQHandler                          ;LPIT0 channel 3 overflow interrupt
        DCD     PDB0_IRQHandler                               ;PDB0 interrupt
        DCD     Reserved69_IRQHandler                         ;xxx Interrupt 69
        DCD     Reserved70_IRQHandler                         ;xxx Interrupt 70
        DCD     Reserved71_IRQHandler                         ;xxx Interrupt 71
        DCD     Reserved72_IRQHandler                         ;xxx Interrupt 72
        DCD     SCG_IRQHandler                                ;SCG bus interrupt request
        DCD     LPTMR0_IRQHandler                             ;LPTIMER interrupt request
        DCD     PORTA_IRQHandler                              ;Port A pin detect interrupt
        DCD     PORTB_IRQHandler                              ;Port B pin detect interrupt
        DCD     PORTC_IRQHandler                              ;Port C pin detect interrupt
        DCD     PORTD_IRQHandler                              ;Port D pin detect interrupt
        DCD     PORTE_IRQHandler                              ;Port E pin detect interrupt
        DCD     SWI_IRQHandler                                ;Software interrupt
        DCD     Reserved81_IRQHandler                         ;xxx Interrupt 81
        DCD     Reserved82_IRQHandler                         ;xxx Interrupt 82
        DCD     Reserved83_IRQHandler                         ;xxx Interrupt 83
        DCD     PDB1_IRQHandler                               ;PDB1 interrupt
        DCD     FLEXIO_IRQHandler                             ;Software interrupt
        DCD     Reserved86_IRQHandler                         ;xxx Interrupt 86
        DCD     Reserved87_IRQHandler                         ;xxx Interrupt 87
        DCD     Reserved88_IRQHandler                         ;xxx Interrupt 88
        DCD     Reserved89_IRQHandler                         ;xxx Interrupt 89
        DCD     Reserved90_IRQHandler                         ;xxx Interrupt 90
        DCD     Reserved91_IRQHandler                         ;xxx Interrupt 91
        DCD     Reserved92_IRQHandler                         ;xxx Interrupt 92
        DCD     Reserved93_IRQHandler                         ;xxx Interrupt 93
        DCD     CAN0_ORed_IRQHandler                          ;CAN0 OR'ed interrupt
        DCD     CAN0_Error_IRQHandler                         ;CAN0 Interrupt indicating that errors were detected on the CAN bus
        DCD     CAN0_Wake_Up_IRQHandler                       ;CAN0 Interrupt asserted when Pretended Networking operation is enabled, and a valid message matches the selected filter criteria during Low Power mode
        DCD     CAN0_ORed_0_15_MB_IRQHandler                  ;CAN0 OR'ed Message buffer (0-15)
        DCD     CAN0_ORed_16_31_MB_IRQHandler                 ;CAN0 OR'ed Message buffer (16-31)
        DCD     Reserved99_IRQHandler                         ;xxx Interrupt 99
        DCD     Reserved100_IRQHandler                        ;xxx Interrupt 100
        DCD     CAN1_ORed_IRQHandler                          ;CAN1 OR'ed interrupt
        DCD     CAN1_Error_IRQHandler                         ;CAN1 Interrupt indicating that errors were detected on the CAN bus
        DCD     Reserved103_IRQHandler                        ;xxx Interrupt 103
        DCD     CAN1_ORed_0_15_MB_IRQHandler                  ;CAN1 OR'ed Message buffer (0-15)
        DCD     Reserved105_IRQHandler                        ;xxx Interrupt 105
        DCD     Reserved106_IRQHandler                        ;xxx Interrupt 106
        DCD     Reserved107_IRQHandler                        ;xxx Interrupt 107
        DCD     CAN2_ORed_IRQHandler                          ;CAN2 OR'ed interrupt
        DCD     CAN2_Error_IRQHandler                         ;CAN2 Interrupt indicating that errors were detected on the CAN bus
        DCD     Reserved110_IRQHandler                        ;xxx Interrupt 110
        DCD     CAN2_ORed_0_15_MB_IRQHandler                  ;CAN2 OR'ed Message buffer (0-15)
        DCD     Reserved112_IRQHandler                        ;xxx Interrupt 112
        DCD     Reserved113_IRQHandler                        ;xxx Interrupt 113
        DCD     Reserved114_IRQHandler                        ;xxx Interrupt 114
        DCD     FTM0_Ch0_Ch1_IRQHandler                       ;FTM0 Channel 0 and 1 interrupt
        DCD     FTM0_Ch2_Ch3_IRQHandler                       ;FTM0 Channel 2 and 3 interrupt
        DCD     FTM0_Ch4_Ch5_IRQHandler                       ;FTM0 Channel 4 and 5 interrupt
        DCD     FTM0_Ch6_Ch7_IRQHandler                       ;FTM0 Channel 6 and 7 interrupt
        DCD     FTM0_Fault_IRQHandler                         ;FTM0 Fault interrupt
        DCD     FTM0_Ovf_Reload_IRQHandler                    ;FTM0 Counter overflow and Reload interrupt
        DCD     FTM1_Ch0_Ch1_IRQHandler                       ;FTM1 Channel 0 and 1 interrupt
        DCD     FTM1_Ch2_Ch3_IRQHandler                       ;FTM1 Channel 2 and 3 interrupt
        DCD     FTM1_Ch4_Ch5_IRQHandler                       ;FTM1 Channel 4 and 5 interrupt
        DCD     FTM1_Ch6_Ch7_IRQHandler                       ;FTM1 Channel 6 and 7 interrupt
        DCD     FTM1_Fault_IRQHandler                         ;FTM1 Fault interrupt
        DCD     FTM1_Ovf_Reload_IRQHandler                    ;FTM1 Counter overflow and Reload interrupt
        DCD     FTM2_Ch0_Ch1_IRQHandler                       ;FTM2 Channel 0 and 1 interrupt
        DCD     FTM2_Ch2_Ch3_IRQHandler                       ;FTM2 Channel 2 and 3 interrupt
        DCD     FTM2_Ch4_Ch5_IRQHandler                       ;FTM2 Channel 4 and 5 interrupt
        DCD     FTM2_Ch6_Ch7_IRQHandler                       ;FTM2 Channel 6 and 7 interrupt
        DCD     FTM2_Fault_IRQHandler                         ;FTM2 Fault interrupt
        DCD     FTM2_Ovf_Reload_IRQHandler                    ;FTM2 Counter overflow and Reload interrupt
        DCD     FTM3_Ch0_Ch1_IRQHandler                       ;FTM3 Channel 0 and 1 interrupt
        DCD     FTM3_Ch2_Ch3_IRQHandler                       ;FTM3 Channel 2 and 3 interrupt
        DCD     FTM3_Ch4_Ch5_IRQHandler                       ;FTM3 Channel 4 and 5 interrupt
        DCD     FTM3_Ch6_Ch7_IRQHandler                       ;FTM3 Channel 6 and 7 interrupt
        DCD     FTM3_Fault_IRQHandler                         ;FTM3 Fault interrupt
        DCD     FTM3_Ovf_Reload_IRQHandler                    ;FTM3 Counter overflow and Reload interrupt
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
        DCD     0xFFFFFFFF                                    ; Reserved for user TRIM value
__Vectors_End

        SECTION FlashConfig:CODE
__FlashConfig
        DCD 0xFFFFFFFF
        DCD 0xFFFFFFFF
        DCD 0xFFFFFFFF
        DCD 0xFFFFFFFE
__FlashConfig_End

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

        PUBWEAK DMA0_IRQHandler
        PUBWEAK DMA0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA1_IRQHandler
        PUBWEAK DMA1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_IRQHandler
        LDR     R0, =DMA1_DriverIRQHandler
        BX      R0

        PUBWEAK DMA2_IRQHandler
        PUBWEAK DMA2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA2_IRQHandler
        LDR     R0, =DMA2_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_IRQHandler
        PUBWEAK DMA3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_IRQHandler
        LDR     R0, =DMA3_DriverIRQHandler
        BX      R0

        PUBWEAK DMA4_IRQHandler
        PUBWEAK DMA4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA4_IRQHandler
        LDR     R0, =DMA4_DriverIRQHandler
        BX      R0

        PUBWEAK DMA5_IRQHandler
        PUBWEAK DMA5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA5_IRQHandler
        LDR     R0, =DMA5_DriverIRQHandler
        BX      R0

        PUBWEAK DMA6_IRQHandler
        PUBWEAK DMA6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA6_IRQHandler
        LDR     R0, =DMA6_DriverIRQHandler
        BX      R0

        PUBWEAK DMA7_IRQHandler
        PUBWEAK DMA7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA7_IRQHandler
        LDR     R0, =DMA7_DriverIRQHandler
        BX      R0

        PUBWEAK DMA8_IRQHandler
        PUBWEAK DMA8_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA8_IRQHandler
        LDR     R0, =DMA8_DriverIRQHandler
        BX      R0

        PUBWEAK DMA9_IRQHandler
        PUBWEAK DMA9_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA9_IRQHandler
        LDR     R0, =DMA9_DriverIRQHandler
        BX      R0

        PUBWEAK DMA10_IRQHandler
        PUBWEAK DMA10_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA10_IRQHandler
        LDR     R0, =DMA10_DriverIRQHandler
        BX      R0

        PUBWEAK DMA11_IRQHandler
        PUBWEAK DMA11_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA11_IRQHandler
        LDR     R0, =DMA11_DriverIRQHandler
        BX      R0

        PUBWEAK DMA12_IRQHandler
        PUBWEAK DMA12_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA12_IRQHandler
        LDR     R0, =DMA12_DriverIRQHandler
        BX      R0

        PUBWEAK DMA13_IRQHandler
        PUBWEAK DMA13_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA13_IRQHandler
        LDR     R0, =DMA13_DriverIRQHandler
        BX      R0

        PUBWEAK DMA14_IRQHandler
        PUBWEAK DMA14_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA14_IRQHandler
        LDR     R0, =DMA14_DriverIRQHandler
        BX      R0

        PUBWEAK DMA15_IRQHandler
        PUBWEAK DMA15_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA15_IRQHandler
        LDR     R0, =DMA15_DriverIRQHandler
        BX      R0

        PUBWEAK DMA_Error_IRQHandler
        PUBWEAK DMA_Error_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA_Error_IRQHandler
        LDR     R0, =DMA_Error_DriverIRQHandler
        BX      R0

        PUBWEAK MCM_IRQHandler
        PUBWEAK FTFC_CMD_IRQHandler
        PUBWEAK FTFC_Read_Collision_IRQHandler
        PUBWEAK LVD_LVW_IRQHandler
        PUBWEAK FTFM_Fault_IRQHandler
        PUBWEAK WDOG_EWM_IRQHandler
        PUBWEAK RCM_IRQHandler
        PUBWEAK LPI2C0_Master_IRQHandler
        PUBWEAK LPI2C0_Master_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C0_Master_IRQHandler
        LDR     R0, =LPI2C0_Master_DriverIRQHandler
        BX      R0

        PUBWEAK LPI2C0_Slave_IRQHandler
        PUBWEAK LPI2C0_Slave_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C0_Slave_IRQHandler
        LDR     R0, =LPI2C0_Slave_DriverIRQHandler
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

        PUBWEAK Reserved45_IRQHandler
        PUBWEAK Reserved46_IRQHandler
        PUBWEAK LPUART0_IRQHandler
        PUBWEAK LPUART0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART0_IRQHandler
        LDR     R0, =LPUART0_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved48_IRQHandler
        PUBWEAK LPUART1_IRQHandler
        PUBWEAK LPUART1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART1_IRQHandler
        LDR     R0, =LPUART1_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved50_IRQHandler
        PUBWEAK LPUART2_IRQHandler
        PUBWEAK LPUART2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART2_IRQHandler
        LDR     R0, =LPUART2_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved52_IRQHandler
        PUBWEAK Reserved53_IRQHandler
        PUBWEAK Reserved54_IRQHandler
        PUBWEAK ADC0_IRQHandler
        PUBWEAK ADC1_IRQHandler
        PUBWEAK CMP0_IRQHandler
        PUBWEAK Reserved58_IRQHandler
        PUBWEAK Reserved59_IRQHandler
        PUBWEAK ERM_single_fault_IRQHandler
        PUBWEAK ERM_double_fault_IRQHandler
        PUBWEAK RTC_IRQHandler
        PUBWEAK RTC_Seconds_IRQHandler
        PUBWEAK LPIT0_Ch0_IRQHandler
        PUBWEAK LPIT0_Ch1_IRQHandler
        PUBWEAK LPIT0_Ch2_IRQHandler
        PUBWEAK LPIT0_Ch3_IRQHandler
        PUBWEAK PDB0_IRQHandler
        PUBWEAK Reserved69_IRQHandler
        PUBWEAK Reserved70_IRQHandler
        PUBWEAK Reserved71_IRQHandler
        PUBWEAK Reserved72_IRQHandler
        PUBWEAK SCG_IRQHandler
        PUBWEAK LPTMR0_IRQHandler
        PUBWEAK PORTA_IRQHandler
        PUBWEAK PORTB_IRQHandler
        PUBWEAK PORTC_IRQHandler
        PUBWEAK PORTD_IRQHandler
        PUBWEAK PORTE_IRQHandler
        PUBWEAK SWI_IRQHandler
        PUBWEAK Reserved81_IRQHandler
        PUBWEAK Reserved82_IRQHandler
        PUBWEAK Reserved83_IRQHandler
        PUBWEAK PDB1_IRQHandler
        PUBWEAK FLEXIO_IRQHandler
        PUBWEAK FLEXIO_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXIO_IRQHandler
        LDR     R0, =FLEXIO_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved86_IRQHandler
        PUBWEAK Reserved87_IRQHandler
        PUBWEAK Reserved88_IRQHandler
        PUBWEAK Reserved89_IRQHandler
        PUBWEAK Reserved90_IRQHandler
        PUBWEAK Reserved91_IRQHandler
        PUBWEAK Reserved92_IRQHandler
        PUBWEAK Reserved93_IRQHandler
        PUBWEAK CAN0_ORed_IRQHandler
        PUBWEAK CAN0_ORed_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN0_ORed_IRQHandler
        LDR     R0, =CAN0_ORed_DriverIRQHandler
        BX      R0

        PUBWEAK CAN0_Error_IRQHandler
        PUBWEAK CAN0_Error_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN0_Error_IRQHandler
        LDR     R0, =CAN0_Error_DriverIRQHandler
        BX      R0

        PUBWEAK CAN0_Wake_Up_IRQHandler
        PUBWEAK CAN0_Wake_Up_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN0_Wake_Up_IRQHandler
        LDR     R0, =CAN0_Wake_Up_DriverIRQHandler
        BX      R0

        PUBWEAK CAN0_ORed_0_15_MB_IRQHandler
        PUBWEAK CAN0_ORed_0_15_MB_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN0_ORed_0_15_MB_IRQHandler
        LDR     R0, =CAN0_ORed_0_15_MB_DriverIRQHandler
        BX      R0

        PUBWEAK CAN0_ORed_16_31_MB_IRQHandler
        PUBWEAK CAN0_ORed_16_31_MB_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN0_ORed_16_31_MB_IRQHandler
        LDR     R0, =CAN0_ORed_16_31_MB_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved99_IRQHandler
        PUBWEAK Reserved100_IRQHandler
        PUBWEAK CAN1_ORed_IRQHandler
        PUBWEAK CAN1_ORed_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN1_ORed_IRQHandler
        LDR     R0, =CAN1_ORed_DriverIRQHandler
        BX      R0

        PUBWEAK CAN1_Error_IRQHandler
        PUBWEAK CAN1_Error_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN1_Error_IRQHandler
        LDR     R0, =CAN1_Error_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved103_IRQHandler
        PUBWEAK CAN1_ORed_0_15_MB_IRQHandler
        PUBWEAK CAN1_ORed_0_15_MB_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN1_ORed_0_15_MB_IRQHandler
        LDR     R0, =CAN1_ORed_0_15_MB_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved105_IRQHandler
        PUBWEAK Reserved106_IRQHandler
        PUBWEAK Reserved107_IRQHandler
        PUBWEAK CAN2_ORed_IRQHandler
        PUBWEAK CAN2_ORed_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN2_ORed_IRQHandler
        LDR     R0, =CAN2_ORed_DriverIRQHandler
        BX      R0

        PUBWEAK CAN2_Error_IRQHandler
        PUBWEAK CAN2_Error_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN2_Error_IRQHandler
        LDR     R0, =CAN2_Error_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved110_IRQHandler
        PUBWEAK CAN2_ORed_0_15_MB_IRQHandler
        PUBWEAK CAN2_ORed_0_15_MB_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN2_ORed_0_15_MB_IRQHandler
        LDR     R0, =CAN2_ORed_0_15_MB_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved112_IRQHandler
        PUBWEAK Reserved113_IRQHandler
        PUBWEAK Reserved114_IRQHandler
        PUBWEAK FTM0_Ch0_Ch1_IRQHandler
        PUBWEAK FTM0_Ch2_Ch3_IRQHandler
        PUBWEAK FTM0_Ch4_Ch5_IRQHandler
        PUBWEAK FTM0_Ch6_Ch7_IRQHandler
        PUBWEAK FTM0_Fault_IRQHandler
        PUBWEAK FTM0_Ovf_Reload_IRQHandler
        PUBWEAK FTM1_Ch0_Ch1_IRQHandler
        PUBWEAK FTM1_Ch2_Ch3_IRQHandler
        PUBWEAK FTM1_Ch4_Ch5_IRQHandler
        PUBWEAK FTM1_Ch6_Ch7_IRQHandler
        PUBWEAK FTM1_Fault_IRQHandler
        PUBWEAK FTM1_Ovf_Reload_IRQHandler
        PUBWEAK FTM2_Ch0_Ch1_IRQHandler
        PUBWEAK FTM2_Ch2_Ch3_IRQHandler
        PUBWEAK FTM2_Ch4_Ch5_IRQHandler
        PUBWEAK FTM2_Ch6_Ch7_IRQHandler
        PUBWEAK FTM2_Fault_IRQHandler
        PUBWEAK FTM2_Ovf_Reload_IRQHandler
        PUBWEAK FTM3_Ch0_Ch1_IRQHandler
        PUBWEAK FTM3_Ch2_Ch3_IRQHandler
        PUBWEAK FTM3_Ch4_Ch5_IRQHandler
        PUBWEAK FTM3_Ch6_Ch7_IRQHandler
        PUBWEAK FTM3_Fault_IRQHandler
        PUBWEAK FTM3_Ovf_Reload_IRQHandler
        PUBWEAK DefaultISR
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA0_DriverIRQHandler
DMA1_DriverIRQHandler
DMA2_DriverIRQHandler
DMA3_DriverIRQHandler
DMA4_DriverIRQHandler
DMA5_DriverIRQHandler
DMA6_DriverIRQHandler
DMA7_DriverIRQHandler
DMA8_DriverIRQHandler
DMA9_DriverIRQHandler
DMA10_DriverIRQHandler
DMA11_DriverIRQHandler
DMA12_DriverIRQHandler
DMA13_DriverIRQHandler
DMA14_DriverIRQHandler
DMA15_DriverIRQHandler
DMA_Error_DriverIRQHandler
MCM_IRQHandler
FTFC_CMD_IRQHandler
FTFC_Read_Collision_IRQHandler
LVD_LVW_IRQHandler
FTFM_Fault_IRQHandler
WDOG_EWM_IRQHandler
RCM_IRQHandler
LPI2C0_Master_DriverIRQHandler
LPI2C0_Slave_DriverIRQHandler
LPSPI0_DriverIRQHandler
LPSPI1_DriverIRQHandler
LPSPI2_DriverIRQHandler
Reserved45_IRQHandler
Reserved46_IRQHandler
LPUART0_DriverIRQHandler
Reserved48_IRQHandler
LPUART1_DriverIRQHandler
Reserved50_IRQHandler
LPUART2_DriverIRQHandler
Reserved52_IRQHandler
Reserved53_IRQHandler
Reserved54_IRQHandler
ADC0_IRQHandler
ADC1_IRQHandler
CMP0_IRQHandler
Reserved58_IRQHandler
Reserved59_IRQHandler
ERM_single_fault_IRQHandler
ERM_double_fault_IRQHandler
RTC_IRQHandler
RTC_Seconds_IRQHandler
LPIT0_Ch0_IRQHandler
LPIT0_Ch1_IRQHandler
LPIT0_Ch2_IRQHandler
LPIT0_Ch3_IRQHandler
PDB0_IRQHandler
Reserved69_IRQHandler
Reserved70_IRQHandler
Reserved71_IRQHandler
Reserved72_IRQHandler
SCG_IRQHandler
LPTMR0_IRQHandler
PORTA_IRQHandler
PORTB_IRQHandler
PORTC_IRQHandler
PORTD_IRQHandler
PORTE_IRQHandler
SWI_IRQHandler
Reserved81_IRQHandler
Reserved82_IRQHandler
Reserved83_IRQHandler
PDB1_IRQHandler
FLEXIO_DriverIRQHandler
Reserved86_IRQHandler
Reserved87_IRQHandler
Reserved88_IRQHandler
Reserved89_IRQHandler
Reserved90_IRQHandler
Reserved91_IRQHandler
Reserved92_IRQHandler
Reserved93_IRQHandler
CAN0_ORed_DriverIRQHandler
CAN0_Error_DriverIRQHandler
CAN0_Wake_Up_DriverIRQHandler
CAN0_ORed_0_15_MB_DriverIRQHandler
CAN0_ORed_16_31_MB_DriverIRQHandler
Reserved99_IRQHandler
Reserved100_IRQHandler
CAN1_ORed_DriverIRQHandler
CAN1_Error_DriverIRQHandler
Reserved103_IRQHandler
CAN1_ORed_0_15_MB_DriverIRQHandler
Reserved105_IRQHandler
Reserved106_IRQHandler
Reserved107_IRQHandler
CAN2_ORed_DriverIRQHandler
CAN2_Error_DriverIRQHandler
Reserved110_IRQHandler
CAN2_ORed_0_15_MB_DriverIRQHandler
Reserved112_IRQHandler
Reserved113_IRQHandler
Reserved114_IRQHandler
FTM0_Ch0_Ch1_IRQHandler
FTM0_Ch2_Ch3_IRQHandler
FTM0_Ch4_Ch5_IRQHandler
FTM0_Ch6_Ch7_IRQHandler
FTM0_Fault_IRQHandler
FTM0_Ovf_Reload_IRQHandler
FTM1_Ch0_Ch1_IRQHandler
FTM1_Ch2_Ch3_IRQHandler
FTM1_Ch4_Ch5_IRQHandler
FTM1_Ch6_Ch7_IRQHandler
FTM1_Fault_IRQHandler
FTM1_Ovf_Reload_IRQHandler
FTM2_Ch0_Ch1_IRQHandler
FTM2_Ch2_Ch3_IRQHandler
FTM2_Ch4_Ch5_IRQHandler
FTM2_Ch6_Ch7_IRQHandler
FTM2_Fault_IRQHandler
FTM2_Ovf_Reload_IRQHandler
FTM3_Ch0_Ch1_IRQHandler
FTM3_Ch2_Ch3_IRQHandler
FTM3_Ch4_Ch5_IRQHandler
FTM3_Ch6_Ch7_IRQHandler
FTM3_Fault_IRQHandler
FTM3_Ovf_Reload_IRQHandler
DefaultISR
        B DefaultISR

        END
