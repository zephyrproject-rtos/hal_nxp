; -------------------------------------------------------------------------
;  @file:    startup_MCXW727D_cm33_core1.s
;  @purpose: CMSIS Cortex-M33 Core Device Startup File
;            MCXW727D_cm33_core1
;  @version: 2.0
;  @date:    2024-10-29
;  @build:   b250522
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
        DCD     BLE_INT0_IRQHandler                           ;
        DCD     BLE_INT1_IRQHandler                           ;
        DCD     BLE_INT2_IRQHandler                           ;
        DCD     BTU_FIQ_IRQHandler                            ;
        DCD     BTU_INT_IRQHandler                            ;
        DCD     BRF_INT_IRQHandler                            ;
        DCD     CTI_IRQ0_IRQHandler                           ;
        DCD     T1_INT_IRQHandler                             ;
        DCD     T2_INT_IRQHandler                             ;
        DCD     T3_INT_IRQHandler                             ;
        DCD     T4_INT_IRQHandler                             ;
        DCD     WDG2_INT_IRQHandler                           ;
        DCD     SI_INT_IRQHandler                             ;
        DCD     CTI_IRQ1_IRQHandler                           ;
        DCD     CPU2_MSG_RDY_INT_IRQHandler                   ;
        DCD     CPU2_MSG_SPC_AVAIL_INT_IRQHandler             ;
        DCD     ZIGBEE_INT_IRQHandler                         ;
        DCD     CIU2_INT_IRQHandler                           ;
        DCD     CPU2_ERR_INT_IRQHandler                       ;
        DCD     GENLL_INT_IRQHandler                          ;
        DCD     BRIC_INT_IRQHandler                           ;
        DCD     RF_SFA_IRQHandler                             ;
        DCD     RBME_INT_IRQHandler                           ;
        DCD     LCL_INT_IRQHandler                            ;
        DCD     RSM_INT_IRQHandler                            ;
        DCD     XO_RDY_INT_IRQHandler                         ;
        DCD     PLL_ABORT_INT_IRQHandler                      ;
        DCD     FMU_INT_IRQHandler                            ;
        DCD     WOR_INT_IRQHandler                            ;
        DCD     TPM2_INT_IRQHandler                           ;Timer / PWM Module2 interrupt
        DCD     DSB_IRQHandler                                ;
        DCD     SECSUBSYS_IRQHandler                          ;
        DCD     LPTMR2_IRQHandler                             ;Low-Power Timer2 interrupt
        DCD     DefaultISR                                    ;49
        DCD     DefaultISR                                    ;50
        DCD     DefaultISR                                    ;51
        DCD     DefaultISR                                    ;52
        DCD     DefaultISR                                    ;53
        DCD     DefaultISR                                    ;54
        DCD     DefaultISR                                    ;55
        DCD     DefaultISR                                    ;56
        DCD     DefaultISR                                    ;57
        DCD     DefaultISR                                    ;58
        DCD     DefaultISR                                    ;59
        DCD     DefaultISR                                    ;60
        DCD     DefaultISR                                    ;61
        DCD     DefaultISR                                    ;62
        DCD     DefaultISR                                    ;63
        DCD     DefaultISR                                    ;64
        DCD     DefaultISR                                    ;65
        DCD     DefaultISR                                    ;66
        DCD     DefaultISR                                    ;67
        DCD     DefaultISR                                    ;68
        DCD     DefaultISR                                    ;69
        DCD     DefaultISR                                    ;70
        DCD     DefaultISR                                    ;71
        DCD     DefaultISR                                    ;72
        DCD     DefaultISR                                    ;73
        DCD     DefaultISR                                    ;74
        DCD     DefaultISR                                    ;75
        DCD     DefaultISR                                    ;76
        DCD     DefaultISR                                    ;77
        DCD     DefaultISR                                    ;78
        DCD     DefaultISR                                    ;79
        DCD     DefaultISR                                    ;80
        DCD     DefaultISR                                    ;81
        DCD     DefaultISR                                    ;82
        DCD     DefaultISR                                    ;83
        DCD     DefaultISR                                    ;84
        DCD     DefaultISR                                    ;85
        DCD     DefaultISR                                    ;86
        DCD     DefaultISR                                    ;87
        DCD     DefaultISR                                    ;88
        DCD     DefaultISR                                    ;89
        DCD     DefaultISR                                    ;90
        DCD     DefaultISR                                    ;91
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

        PUBWEAK BLE_INT0_IRQHandler
        PUBWEAK BLE_INT1_IRQHandler
        PUBWEAK BLE_INT2_IRQHandler
        PUBWEAK BTU_FIQ_IRQHandler
        PUBWEAK BTU_INT_IRQHandler
        PUBWEAK BRF_INT_IRQHandler
        PUBWEAK CTI_IRQ0_IRQHandler
        PUBWEAK T1_INT_IRQHandler
        PUBWEAK T2_INT_IRQHandler
        PUBWEAK T3_INT_IRQHandler
        PUBWEAK T4_INT_IRQHandler
        PUBWEAK WDG2_INT_IRQHandler
        PUBWEAK SI_INT_IRQHandler
        PUBWEAK CTI_IRQ1_IRQHandler
        PUBWEAK CPU2_MSG_RDY_INT_IRQHandler
        PUBWEAK CPU2_MSG_SPC_AVAIL_INT_IRQHandler
        PUBWEAK ZIGBEE_INT_IRQHandler
        PUBWEAK CIU2_INT_IRQHandler
        PUBWEAK CPU2_ERR_INT_IRQHandler
        PUBWEAK GENLL_INT_IRQHandler
        PUBWEAK BRIC_INT_IRQHandler
        PUBWEAK RF_SFA_IRQHandler
        PUBWEAK RF_SFA_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
RF_SFA_IRQHandler
        LDR     R0, =RF_SFA_DriverIRQHandler
        BX      R0

        PUBWEAK RBME_INT_IRQHandler
        PUBWEAK LCL_INT_IRQHandler
        PUBWEAK RSM_INT_IRQHandler
        PUBWEAK XO_RDY_INT_IRQHandler
        PUBWEAK PLL_ABORT_INT_IRQHandler
        PUBWEAK FMU_INT_IRQHandler
        PUBWEAK WOR_INT_IRQHandler
        PUBWEAK TPM2_INT_IRQHandler
        PUBWEAK DSB_IRQHandler
        PUBWEAK SECSUBSYS_IRQHandler
        PUBWEAK LPTMR2_IRQHandler
        PUBWEAK DefaultISR
        SECTION .text:CODE:REORDER:NOROOT(1)
BLE_INT0_IRQHandler
BLE_INT1_IRQHandler
BLE_INT2_IRQHandler
BTU_FIQ_IRQHandler
BTU_INT_IRQHandler
BRF_INT_IRQHandler
CTI_IRQ0_IRQHandler
T1_INT_IRQHandler
T2_INT_IRQHandler
T3_INT_IRQHandler
T4_INT_IRQHandler
WDG2_INT_IRQHandler
SI_INT_IRQHandler
CTI_IRQ1_IRQHandler
CPU2_MSG_RDY_INT_IRQHandler
CPU2_MSG_SPC_AVAIL_INT_IRQHandler
ZIGBEE_INT_IRQHandler
CIU2_INT_IRQHandler
CPU2_ERR_INT_IRQHandler
GENLL_INT_IRQHandler
BRIC_INT_IRQHandler
RF_SFA_DriverIRQHandler
RBME_INT_IRQHandler
LCL_INT_IRQHandler
RSM_INT_IRQHandler
XO_RDY_INT_IRQHandler
PLL_ABORT_INT_IRQHandler
FMU_INT_IRQHandler
WOR_INT_IRQHandler
TPM2_INT_IRQHandler
DSB_IRQHandler
SECSUBSYS_IRQHandler
LPTMR2_IRQHandler
DefaultISR
        B DefaultISR

        END
