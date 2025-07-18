; -------------------------------------------------------------------------
;  @file:    startup_MKE15Z4.s
;  @purpose: CMSIS Cortex-M0P Core Device Startup File
;            MKE15Z4
;  @version: 4.0
;  @date:    2024-10-29
;  @build:   b250520
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
        DCD     FTFA_IRQHandler                               ;Flash memory single interrupt vector for all sources
        DCD     LVD_LVW_IRQHandler                            ;Low-voltage detect, low-voltage warning
        DCD     PORTAE_IRQHandler                             ;Pin detect (Port A, E)
        DCD     LPI2C0_IRQHandler                             ;Inter-integrated circuit 0 interrupt
        DCD     Reserved25_IRQHandler                         ;Reserved interrupt
        DCD     LPSPI0_IRQHandler                             ;Serial peripheral Interface 0 interrupt
        DCD     Reserved27_IRQHandler                         ;Reserved interrupt
        DCD     LPUART0_IRQHandler                            ;Single interrupt vector for all sources
        DCD     LPUART1_IRQHandler                            ;Single interrupt vector for all sources
        DCD     LPUART2_IRQHandler                            ;Single interrupt vector for all sources
        DCD     ADC0_IRQHandler                               ;ADC0 conversion complete interrupt
        DCD     CMP0_IRQHandler                               ;CMP0 interrupt
        DCD     FTM0_IRQHandler                               ;FTM0 single interrupt vector for all sources
        DCD     FTM1_IRQHandler                               ;FTM1 single interrupt vector for all sources
        DCD     Reserved35_IRQHandler                         ;Reserved interrupt
        DCD     RTC_IRQHandler                                ;Single interrupt vector for all sources
        DCD     Reserved37_IRQHandler                         ;Reserved interrupt
        DCD     LPIT0_IRQHandler                              ;LPIT channel 0-1
        DCD     Reserved39_IRQHandler                         ;Reserved interrupt
        DCD     TSI_IRQHandler                                ;TSI interrupt
        DCD     PDB0_IRQHandler                               ;Programmable delay block interrupt
        DCD     PORTBCD_IRQHandler                            ;Pin detect (Port B, C, D)
        DCD     SCG_RCM_IRQHandler                            ;Single interrupt vector for SCG and RCM
        DCD     WDOG_EWM_IRQHandler                           ;Single interrupt vector for WDOG and EWM
        DCD     PWT_LPTMR0_IRQHandler                         ;Single interrupt vector for PWT and LPTMR0
        DCD     Reserved46_IRQHandler                         ;Reserved interrupt
        DCD     Reserved47_IRQHandler                         ;Reserved interrupt
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
        PUBWEAK LVD_LVW_IRQHandler
        PUBWEAK PORTAE_IRQHandler
        PUBWEAK LPI2C0_IRQHandler
        PUBWEAK LPI2C0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C0_IRQHandler
        LDR     R0, =LPI2C0_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved25_IRQHandler
        PUBWEAK LPSPI0_IRQHandler
        PUBWEAK LPSPI0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPSPI0_IRQHandler
        LDR     R0, =LPSPI0_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved27_IRQHandler
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

        PUBWEAK ADC0_IRQHandler
        PUBWEAK CMP0_IRQHandler
        PUBWEAK FTM0_IRQHandler
        PUBWEAK FTM1_IRQHandler
        PUBWEAK Reserved35_IRQHandler
        PUBWEAK RTC_IRQHandler
        PUBWEAK Reserved37_IRQHandler
        PUBWEAK LPIT0_IRQHandler
        PUBWEAK Reserved39_IRQHandler
        PUBWEAK TSI_IRQHandler
        PUBWEAK PDB0_IRQHandler
        PUBWEAK PORTBCD_IRQHandler
        PUBWEAK SCG_RCM_IRQHandler
        PUBWEAK WDOG_EWM_IRQHandler
        PUBWEAK PWT_LPTMR0_IRQHandler
        PUBWEAK Reserved46_IRQHandler
        PUBWEAK Reserved47_IRQHandler
        PUBWEAK DefaultISR
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved16_IRQHandler
Reserved17_IRQHandler
Reserved18_IRQHandler
Reserved19_IRQHandler
Reserved20_IRQHandler
FTFA_IRQHandler
LVD_LVW_IRQHandler
PORTAE_IRQHandler
LPI2C0_DriverIRQHandler
Reserved25_IRQHandler
LPSPI0_DriverIRQHandler
Reserved27_IRQHandler
LPUART0_DriverIRQHandler
LPUART1_DriverIRQHandler
LPUART2_DriverIRQHandler
ADC0_IRQHandler
CMP0_IRQHandler
FTM0_IRQHandler
FTM1_IRQHandler
Reserved35_IRQHandler
RTC_IRQHandler
Reserved37_IRQHandler
LPIT0_IRQHandler
Reserved39_IRQHandler
TSI_IRQHandler
PDB0_IRQHandler
PORTBCD_IRQHandler
SCG_RCM_IRQHandler
WDOG_EWM_IRQHandler
PWT_LPTMR0_IRQHandler
Reserved46_IRQHandler
Reserved47_IRQHandler
DefaultISR
        LDR R0, =DefaultISR
        BX R0

        END
