; -------------------------------------------------------------------------
;  @file:    startup_MCXC041.s
;  @purpose: CMSIS Cortex-M0P Core Device Startup File
;            MCXC041
;  @version: 2.0
;  @date:    2024-10-29
;  @build:   b250521
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
        DCD     Reserved16_IRQHandler                         ;Reserved interrupt
        DCD     Reserved17_IRQHandler                         ;Reserved interrupt
        DCD     Reserved18_IRQHandler                         ;Reserved interrupt
        DCD     Reserved19_IRQHandler                         ;Reserved interrupt
        DCD     Reserved20_IRQHandler                         ;Reserved interrupt
        DCD     FTFA_IRQHandler                               ;Command complete and read collision
        DCD     PMC_IRQHandler                                ;Low-voltage detect, low-voltage warning
        DCD     LLWU_IRQHandler                               ;Low leakage wakeup
        DCD     I2C0_IRQHandler                               ;I2C0 interrupt
        DCD     Reserved25_IRQHandler                         ;Reserved interrupt
        DCD     SPI0_IRQHandler                               ;SPI0 single interrupt vector for all sources
        DCD     Reserved27_IRQHandler                         ;Reserved interrupt
        DCD     LPUART0_IRQHandler                            ;LPUART0 status and error
        DCD     Reserved29_IRQHandler                         ;Reserved interrupt
        DCD     Reserved30_IRQHandler                         ;Reserved interrupt
        DCD     ADC0_IRQHandler                               ;ADC0 interrupt
        DCD     CMP0_IRQHandler                               ;CMP0 interrupt
        DCD     TPM0_IRQHandler                               ;TPM0 single interrupt vector for all sources
        DCD     TPM1_IRQHandler                               ;TPM1 single interrupt vector for all sources
        DCD     Reserved35_IRQHandler                         ;Reserved interrupt
        DCD     RTC_IRQHandler                                ;RTC alarm
        DCD     RTC_Seconds_IRQHandler                        ;RTC seconds
        DCD     Reserved38_IRQHandler                         ;Reserved interrupt
        DCD     Reserved39_IRQHandler                         ;Reserved interrupt
        DCD     Reserved40_IRQHandler                         ;Reserved interrupt
        DCD     Reserved41_IRQHandler                         ;Reserved interrupt
        DCD     Reserved42_IRQHandler                         ;Reserved interrupt
        DCD     Reserved43_IRQHandler                         ;Reserved interrupt
        DCD     LPTMR0_IRQHandler                             ;LPTMR0 interrupt
        DCD     Reserved45_IRQHandler                         ;Reserved interrupt
        DCD     PORTA_IRQHandler                              ;PORTA Pin detect
        DCD     PORTB_IRQHandler                              ;PORTB Pin detect
__Vectors_End

        SECTION FlashConfig:CODE
__FlashConfig
        DCD 0xFFFFFFFF
        DCD 0xFFFFFFFF
        DCD 0xFFFFFFFF
        DCD 0xFFFF3DFE
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
        PUBWEAK Reserved17_IRQHandler
        PUBWEAK Reserved18_IRQHandler
        PUBWEAK Reserved19_IRQHandler
        PUBWEAK Reserved20_IRQHandler
        PUBWEAK FTFA_IRQHandler
        PUBWEAK PMC_IRQHandler
        PUBWEAK LLWU_IRQHandler
        PUBWEAK I2C0_IRQHandler
        PUBWEAK I2C0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2C0_IRQHandler
        LDR     R0, =I2C0_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved25_IRQHandler
        PUBWEAK SPI0_IRQHandler
        PUBWEAK SPI0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SPI0_IRQHandler
        LDR     R0, =SPI0_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved27_IRQHandler
        PUBWEAK LPUART0_IRQHandler
        PUBWEAK LPUART0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART0_IRQHandler
        LDR     R0, =LPUART0_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved29_IRQHandler
        PUBWEAK Reserved30_IRQHandler
        PUBWEAK ADC0_IRQHandler
        PUBWEAK CMP0_IRQHandler
        PUBWEAK TPM0_IRQHandler
        PUBWEAK TPM1_IRQHandler
        PUBWEAK Reserved35_IRQHandler
        PUBWEAK RTC_IRQHandler
        PUBWEAK RTC_Seconds_IRQHandler
        PUBWEAK Reserved38_IRQHandler
        PUBWEAK Reserved39_IRQHandler
        PUBWEAK Reserved40_IRQHandler
        PUBWEAK Reserved41_IRQHandler
        PUBWEAK Reserved42_IRQHandler
        PUBWEAK Reserved43_IRQHandler
        PUBWEAK LPTMR0_IRQHandler
        PUBWEAK Reserved45_IRQHandler
        PUBWEAK PORTA_IRQHandler
        PUBWEAK PORTB_IRQHandler
        PUBWEAK DefaultISR
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved16_IRQHandler
Reserved17_IRQHandler
Reserved18_IRQHandler
Reserved19_IRQHandler
Reserved20_IRQHandler
FTFA_IRQHandler
PMC_IRQHandler
LLWU_IRQHandler
I2C0_DriverIRQHandler
Reserved25_IRQHandler
SPI0_DriverIRQHandler
Reserved27_IRQHandler
LPUART0_DriverIRQHandler
Reserved29_IRQHandler
Reserved30_IRQHandler
ADC0_IRQHandler
CMP0_IRQHandler
TPM0_IRQHandler
TPM1_IRQHandler
Reserved35_IRQHandler
RTC_IRQHandler
RTC_Seconds_IRQHandler
Reserved38_IRQHandler
Reserved39_IRQHandler
Reserved40_IRQHandler
Reserved41_IRQHandler
Reserved42_IRQHandler
Reserved43_IRQHandler
LPTMR0_IRQHandler
Reserved45_IRQHandler
PORTA_IRQHandler
PORTB_IRQHandler
DefaultISR
        LDR R0, =DefaultISR
        BX R0

        END
