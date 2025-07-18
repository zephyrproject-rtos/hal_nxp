; -------------------------------------------------------------------------
;  @file:    startup_MKE02Z4.s
;  @purpose: CMSIS Cortex-M0P Core Device Startup File
;            MKE02Z4
;  @version: 2.0
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
        DCD     FTMRH_IRQHandler                              ;Command complete and error interrupt
        DCD     PMC_IRQHandler                                ;Low-voltage warning
        DCD     IRQ_IRQHandler                                ;External interrupt
        DCD     I2C0_IRQHandler                               ;Single interrupt vector for all sources
        DCD     Reserved25_IRQHandler                         ;Reserved interrupt
        DCD     SPI0_IRQHandler                               ;Single interrupt vector for all sources
        DCD     SPI1_IRQHandler                               ;Single interrupt vector for all sources
        DCD     UART0_IRQHandler                              ;Status and error
        DCD     UART1_IRQHandler                              ;Status and error
        DCD     UART2_IRQHandler                              ;Status and error
        DCD     ADC_IRQHandler                                ;ADC conversion complete interrupt
        DCD     ACMP0_IRQHandler                              ;Analog comparator 0 interrupt
        DCD     FTM0_IRQHandler                               ;FTM0 single interrupt vector for all sources
        DCD     FTM1_IRQHandler                               ;FTM1 single interrupt vector for all sources
        DCD     FTM2_IRQHandler                               ;FTM2 single interrupt vector for all sources
        DCD     RTC_IRQHandler                                ;RTC overflow
        DCD     ACMP1_IRQHandler                              ;Analog comparator 1 interrupt
        DCD     PIT_CH0_IRQHandler                            ;PIT CH0 overflow
        DCD     PIT_CH1_IRQHandler                            ;PIT CH1 overflow
        DCD     KBI0_IRQHandler                               ;Keyboard interrupt0
        DCD     KBI1_IRQHandler                               ;Keyboard interrupt1
        DCD     Reserved42_IRQHandler                         ;Reserved interrupt
        DCD     ICS_IRQHandler                                ;Clock loss of lock
        DCD     WDOG_IRQHandler                               ;Watchdog timeout
        DCD     Reserved45_IRQHandler                         ;Reserved interrupt
        DCD     Reserved46_IRQHandler                         ;Reserved interrupt
        DCD     Reserved47_IRQHandler                         ;Reserved interrupt
__Vectors_End

        SECTION FlashConfig:CODE
__FlashConfig
        DCD 0xFFFFFFFF
        DCD 0xFFFFFFFF
        DCD 0xFFFFFFFF
        DCD 0xFFFEFFFF
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
        PUBWEAK FTMRH_IRQHandler
        PUBWEAK PMC_IRQHandler
        PUBWEAK IRQ_IRQHandler
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

        PUBWEAK SPI1_IRQHandler
        PUBWEAK SPI1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SPI1_IRQHandler
        LDR     R0, =SPI1_DriverIRQHandler
        BX      R0

        PUBWEAK UART0_IRQHandler
        PUBWEAK UART0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
UART0_IRQHandler
        LDR     R0, =UART0_DriverIRQHandler
        BX      R0

        PUBWEAK UART1_IRQHandler
        PUBWEAK UART1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
UART1_IRQHandler
        LDR     R0, =UART1_DriverIRQHandler
        BX      R0

        PUBWEAK UART2_IRQHandler
        PUBWEAK UART2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
UART2_IRQHandler
        LDR     R0, =UART2_DriverIRQHandler
        BX      R0

        PUBWEAK ADC_IRQHandler
        PUBWEAK ACMP0_IRQHandler
        PUBWEAK FTM0_IRQHandler
        PUBWEAK FTM1_IRQHandler
        PUBWEAK FTM2_IRQHandler
        PUBWEAK RTC_IRQHandler
        PUBWEAK RTC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
RTC_IRQHandler
        LDR     R0, =RTC_DriverIRQHandler
        BX      R0

        PUBWEAK ACMP1_IRQHandler
        PUBWEAK PIT_CH0_IRQHandler
        PUBWEAK PIT_CH1_IRQHandler
        PUBWEAK KBI0_IRQHandler
        PUBWEAK KBI1_IRQHandler
        PUBWEAK Reserved42_IRQHandler
        PUBWEAK ICS_IRQHandler
        PUBWEAK WDOG_IRQHandler
        PUBWEAK Reserved45_IRQHandler
        PUBWEAK Reserved46_IRQHandler
        PUBWEAK Reserved47_IRQHandler
        PUBWEAK DefaultISR
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved16_IRQHandler
Reserved17_IRQHandler
Reserved18_IRQHandler
Reserved19_IRQHandler
Reserved20_IRQHandler
FTMRH_IRQHandler
PMC_IRQHandler
IRQ_IRQHandler
I2C0_DriverIRQHandler
Reserved25_IRQHandler
SPI0_DriverIRQHandler
SPI1_DriverIRQHandler
UART0_DriverIRQHandler
UART1_DriverIRQHandler
UART2_DriverIRQHandler
ADC_IRQHandler
ACMP0_IRQHandler
FTM0_IRQHandler
FTM1_IRQHandler
FTM2_IRQHandler
RTC_DriverIRQHandler
ACMP1_IRQHandler
PIT_CH0_IRQHandler
PIT_CH1_IRQHandler
KBI0_IRQHandler
KBI1_IRQHandler
Reserved42_IRQHandler
ICS_IRQHandler
WDOG_IRQHandler
Reserved45_IRQHandler
Reserved46_IRQHandler
Reserved47_IRQHandler
DefaultISR
        LDR R0, =DefaultISR
        BX R0

        END
