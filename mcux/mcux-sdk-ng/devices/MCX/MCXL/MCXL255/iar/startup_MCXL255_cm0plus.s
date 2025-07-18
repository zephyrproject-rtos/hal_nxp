; -------------------------------------------------------------------------
;  @file:    startup_MCXL255_cm0plus.s
;  @purpose: CMSIS Cortex-M0P Core Device Startup File
;            MCXL255_cm0plus
;  @version: 1.0
;  @date:    2023-1-9
;  @build:   b250422
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
        DCD     0                                             ;Reserved
        DCD     0                                             ;Reserved
        DCD     0                                             ;Reserved
__vector_table_0x1c
        DCD     0                                             ;Reserved
        DCD     0                                             ;Reserved
        DCD     0                                             ;Reserved
        DCD     0                                             ;Reserved
        DCD     SVC_Handler                                   ;SVCall Handler
        DCD     0                                             ;Reserved
        DCD     0                                             ;Reserved
        DCD     PendSV_Handler                                ;PendSV Handler
        DCD     SysTick_Handler                               ;SysTick Handler

                                                              ;External Interrupts
        DCD     Reserved16_IRQHandler                         ;xxx Interrupt 16
        DCD     LPI2C0_AON_IRQHandler                         ;Low-Power Inter Integrated Circuit interrupt
        DCD     Reserved18_IRQHandler                         ;xxx Interrupt 18
        DCD     LPUART0_AON_IRQHandler                        ;Low-Power Universal Asynchronous Receive/Transmit interrupt
        DCD     Reserved20_IRQHandler                         ;xxx Interrupt 20
        DCD     GPIO00_AON_IRQHandler                         ;General Purpose Input/Output interrupt 0
        DCD     Reserved22_IRQHandler                         ;xxx Interrupt 22
        DCD     MU_B_TX_IRQHandler                            ;Ored tx interrupt to MUB
        DCD     MU_B_RX_IRQHandler                            ;Ored rx interrupt to MUB
        DCD     MU_B_INT_IRQHandler                           ;ORed general purpose interrupt request to MUB
        DCD     SMM_IRQHandler                                ;SMM IRQ
        DCD     SNS_IRQHandler                                ;SNS - first fail test finish
        DCD     LPCMP_IRQHandler                              ;Comparator
        DCD     RTC_ALARM0_IRQHandler                         ;RTC alarm 0
        DCD     RTC_ALARM1_IRQHandler                         ;RTC alarm 1
        DCD     RTC_ALARM2_IRQHandler                         ;RTC alarm 2
        DCD     RTC_WDT_IRQHandler                            ;RTC watchdog
        DCD     RTC_XTAL_IRQHandler                           ;RTC XTAL Fail
        DCD     SMM_EXT_IRQHandler                            ;External interrupt
        DCD     CGU_IRQHandler                                ;CGU IRQ
        DCD     PMU_IRQHandler                                ;PMU IRQ
        DCD     KPP_IRQHandler                                ;Keypad Interrupt
        DCD     LPADC_AON_IRQHandler                          ;Analog-to-Digital Converter interrupt
        DCD     SGLCD_AON_IRQHandler                          ;SLCD frame start interrupt
        DCD     TMR0_AON_IRQHandler                           ;ORed QTMR Interrupts
        DCD     TMR1_AON_IRQHandler                           ;ORed QTMR Interrupts
        DCD     Reserved42_IRQHandler                         ;xxx Interrupt 42
        DCD     LCSENSE_IRQHandler                            ;LCSense Fault/Tamper Interrupt
        DCD     LPTMR_AON_IRQHandler                          ;Low Power Timer 0 interrupt
        DCD     Reserved45_IRQHandler                         ;xxx Interrupt 45
        DCD     CMP0_AON_IRQHandler                           ;Comparator interrupt
        DCD     ADVC_IRQHandler                               ;ADVC_2.0 Controller Interrupt
        DCD     DefaultISR                                    ;48
        DCD     DefaultISR                                    ;49
        DCD     DefaultISR                                    ;50
        DCD     DefaultISR                                    ;51
        DCD     DefaultISR                                    ;52
        DCD     DefaultISR                                    ;53
        DCD     DefaultISR                                    ;54
        DCD     DefaultISR                                    ;55
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

        PUBWEAK SVC_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SVC_Handler
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

        PUBWEAK LPI2C0_AON_IRQHandler
        PUBWEAK LPI2C0_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C0_AON_IRQHandler
        LDR     R0, =LPI2C0_AON_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved18_IRQHandler
        PUBWEAK Reserved18_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved18_IRQHandler
        LDR     R0, =Reserved18_DriverIRQHandler
        BX      R0

        PUBWEAK LPUART0_AON_IRQHandler
        PUBWEAK LPUART_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART0_AON_IRQHandler
        LDR     R1, =LPUART_DriverIRQHandler
        LDR     R0, =2 ;instance number from MCXL255_cm0plus_COMMON.h
        BX      R1

        PUBWEAK Reserved20_IRQHandler
        PUBWEAK Reserved20_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved20_IRQHandler
        LDR     R0, =Reserved20_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO00_AON_IRQHandler
        PUBWEAK GPIO00_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO00_AON_IRQHandler
        LDR     R0, =GPIO00_AON_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved22_IRQHandler
        PUBWEAK Reserved22_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved22_IRQHandler
        LDR     R0, =Reserved22_DriverIRQHandler
        BX      R0

        PUBWEAK MU_B_TX_IRQHandler
        PUBWEAK MU_B_TX_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MU_B_TX_IRQHandler
        LDR     R0, =MU_B_TX_DriverIRQHandler
        BX      R0

        PUBWEAK MU_B_RX_IRQHandler
        PUBWEAK MU_B_RX_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MU_B_RX_IRQHandler
        LDR     R0, =MU_B_RX_DriverIRQHandler
        BX      R0

        PUBWEAK MU_B_INT_IRQHandler
        PUBWEAK MU_B_INT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MU_B_INT_IRQHandler
        LDR     R0, =MU_B_INT_DriverIRQHandler
        BX      R0

        PUBWEAK SMM_IRQHandler
        PUBWEAK SMM_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SMM_IRQHandler
        LDR     R0, =SMM_DriverIRQHandler
        BX      R0

        PUBWEAK SNS_IRQHandler
        PUBWEAK SNS_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SNS_IRQHandler
        LDR     R0, =SNS_DriverIRQHandler
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

        PUBWEAK SMM_EXT_IRQHandler
        PUBWEAK SMM_EXT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SMM_EXT_IRQHandler
        LDR     R0, =SMM_EXT_DriverIRQHandler
        BX      R0

        PUBWEAK CGU_IRQHandler
        PUBWEAK CGU_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CGU_IRQHandler
        LDR     R0, =CGU_DriverIRQHandler
        BX      R0

        PUBWEAK PMU_IRQHandler
        PUBWEAK PMU_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PMU_IRQHandler
        LDR     R0, =PMU_DriverIRQHandler
        BX      R0

        PUBWEAK KPP_IRQHandler
        PUBWEAK KPP_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
KPP_IRQHandler
        LDR     R0, =KPP_DriverIRQHandler
        BX      R0

        PUBWEAK LPADC_AON_IRQHandler
        PUBWEAK LPADC_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPADC_AON_IRQHandler
        LDR     R0, =LPADC_AON_DriverIRQHandler
        BX      R0

        PUBWEAK SGLCD_AON_IRQHandler
        PUBWEAK SGLCD_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SGLCD_AON_IRQHandler
        LDR     R0, =SGLCD_AON_DriverIRQHandler
        BX      R0

        PUBWEAK TMR0_AON_IRQHandler
        PUBWEAK TMR0_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
TMR0_AON_IRQHandler
        LDR     R0, =TMR0_AON_DriverIRQHandler
        BX      R0

        PUBWEAK TMR1_AON_IRQHandler
        PUBWEAK TMR1_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
TMR1_AON_IRQHandler
        LDR     R0, =TMR1_AON_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved42_IRQHandler
        PUBWEAK Reserved42_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved42_IRQHandler
        LDR     R0, =Reserved42_DriverIRQHandler
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

        PUBWEAK Reserved45_IRQHandler
        PUBWEAK Reserved45_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved45_IRQHandler
        LDR     R0, =Reserved45_DriverIRQHandler
        BX      R0

        PUBWEAK CMP0_AON_IRQHandler
        PUBWEAK CMP0_AON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CMP0_AON_IRQHandler
        LDR     R0, =CMP0_AON_DriverIRQHandler
        BX      R0

        PUBWEAK ADVC_IRQHandler
        PUBWEAK ADVC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ADVC_IRQHandler
        LDR     R0, =ADVC_DriverIRQHandler
        BX      R0

Reserved16_DriverIRQHandler
LPI2C0_AON_DriverIRQHandler
Reserved18_DriverIRQHandler
LPUART_DriverIRQHandler
Reserved20_DriverIRQHandler
GPIO00_AON_DriverIRQHandler
Reserved22_DriverIRQHandler
MU_B_TX_DriverIRQHandler
MU_B_RX_DriverIRQHandler
MU_B_INT_DriverIRQHandler
SMM_DriverIRQHandler
SNS_DriverIRQHandler
LPCMP_DriverIRQHandler
RTC_ALARM0_DriverIRQHandler
RTC_ALARM1_DriverIRQHandler
RTC_ALARM2_DriverIRQHandler
RTC_WDT_DriverIRQHandler
RTC_XTAL_DriverIRQHandler
SMM_EXT_DriverIRQHandler
CGU_DriverIRQHandler
PMU_DriverIRQHandler
KPP_DriverIRQHandler
LPADC_AON_DriverIRQHandler
SGLCD_AON_DriverIRQHandler
TMR0_AON_DriverIRQHandler
TMR1_AON_DriverIRQHandler
Reserved42_DriverIRQHandler
LCSENSE_DriverIRQHandler
LPTMR_AON_DriverIRQHandler
Reserved45_DriverIRQHandler
CMP0_AON_DriverIRQHandler
ADVC_DriverIRQHandler
DefaultISR
        LDR R0, =DefaultISR
        BX R0

        END
