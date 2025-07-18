; -------------------------------------------------------------------------
;  @file:    startup_LPC845.s
;  @purpose: CMSIS Cortex-M0P Core Device Startup File
;            LPC845
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
        DCD     SPI0_IRQHandler                               ;SPI0 interrupt
        DCD     SPI1_IRQHandler                               ;SPI1 interrupt
        DCD     DAC0_IRQHandler                               ;DAC0 interrupt
        DCD     USART0_IRQHandler                             ;USART0 interrupt
        DCD     USART1_IRQHandler                             ;USART1 interrupt
        DCD     USART2_IRQHandler                             ;USART2 interrupt
        DCD     Reserved22_IRQHandler                         ;Reserved interrupt
        DCD     I2C1_IRQHandler                               ;I2C1 interrupt
        DCD     I2C0_IRQHandler                               ;I2C0 interrupt
        DCD     SCT0_IRQHandler                               ;State configurable timer interrupt
        DCD     MRT0_IRQHandler                               ;Multi-rate timer interrupt
        DCD     CMP_CAPT_IRQHandler                           ;Analog comparator interrupt or Capacitive Touch interrupt
        DCD     WDT_IRQHandler                                ;Windowed watchdog timer interrupt
        DCD     BOD_IRQHandler                                ;BOD interrupts
        DCD     FLASH_IRQHandler                              ;flash interrupt
        DCD     WKT_IRQHandler                                ;Self-wake-up timer interrupt
        DCD     ADC0_SEQA_IRQHandler                          ;ADC0 sequence A completion.
        DCD     ADC0_SEQB_IRQHandler                          ;ADC0 sequence B completion.
        DCD     ADC0_THCMP_IRQHandler                         ;ADC0 threshold compare and error.
        DCD     ADC0_OVR_IRQHandler                           ;ADC0 overrun
        DCD     DMA0_IRQHandler                               ;DMA0 interrupt
        DCD     I2C2_IRQHandler                               ;I2C2 interrupt
        DCD     I2C3_IRQHandler                               ;I2C3 interrupt
        DCD     CTIMER0_IRQHandler                            ;Timer interrupt
        DCD     PIN_INT0_IRQHandler                           ;Pin interrupt 0 or pattern match engine slice 0 interrupt
        DCD     PIN_INT1_IRQHandler                           ;Pin interrupt 1 or pattern match engine slice 1 interrupt
        DCD     PIN_INT2_IRQHandler                           ;Pin interrupt 2 or pattern match engine slice 2 interrupt
        DCD     PIN_INT3_IRQHandler                           ;Pin interrupt 3 or pattern match engine slice 3 interrupt
        DCD     PIN_INT4_IRQHandler                           ;Pin interrupt 4 or pattern match engine slice 4 interrupt
        DCD     PIN_INT5_DAC1_IRQHandler                      ;Pin interrupt 5 or pattern match engine slice 5 interrupt or DAC1 interrupt
        DCD     PIN_INT6_USART3_IRQHandler                    ;Pin interrupt 6 or pattern match engine slice 6 interrupt or UART3 interrupt
        DCD     PIN_INT7_USART4_IRQHandler                    ;Pin interrupt 7 or pattern match engine slice 7 interrupt or UART4 interrupt
__Vectors_End

; Code Read Protection Level (CRP)
;    <0xFFFFFFFF=> Disabled
;    <0x4E697370=> NO_ISP
;    <0x12345678=> CRP1
;    <0x87654321=> CRP2
;    <0x43218765=> CRP3

#if !defined NO_CRP
        SECTION .crp:CODE
__CRP
        DCD     0xFFFFFFFF
__CRP_End
#endif

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

        PUBWEAK DAC0_IRQHandler
        PUBWEAK DAC0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DAC0_IRQHandler
        LDR     R0, =DAC0_DriverIRQHandler
        BX      R0

        PUBWEAK USART0_IRQHandler
        PUBWEAK USART0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USART0_IRQHandler
        LDR     R0, =USART0_DriverIRQHandler
        BX      R0

        PUBWEAK USART1_IRQHandler
        PUBWEAK USART1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USART1_IRQHandler
        LDR     R0, =USART1_DriverIRQHandler
        BX      R0

        PUBWEAK USART2_IRQHandler
        PUBWEAK USART2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USART2_IRQHandler
        LDR     R0, =USART2_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved22_IRQHandler
        PUBWEAK Reserved22_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved22_IRQHandler
        LDR     R0, =Reserved22_DriverIRQHandler
        BX      R0

        PUBWEAK I2C1_IRQHandler
        PUBWEAK I2C1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2C1_IRQHandler
        LDR     R0, =I2C1_DriverIRQHandler
        BX      R0

        PUBWEAK I2C0_IRQHandler
        PUBWEAK I2C0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2C0_IRQHandler
        LDR     R0, =I2C0_DriverIRQHandler
        BX      R0

        PUBWEAK SCT0_IRQHandler
        PUBWEAK SCT0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SCT0_IRQHandler
        LDR     R0, =SCT0_DriverIRQHandler
        BX      R0

        PUBWEAK MRT0_IRQHandler
        PUBWEAK MRT0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MRT0_IRQHandler
        LDR     R0, =MRT0_DriverIRQHandler
        BX      R0

        PUBWEAK CMP_CAPT_IRQHandler
        PUBWEAK CMP_CAPT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CMP_CAPT_IRQHandler
        LDR     R0, =CMP_CAPT_DriverIRQHandler
        BX      R0

        PUBWEAK WDT_IRQHandler
        PUBWEAK WDT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WDT_IRQHandler
        LDR     R0, =WDT_DriverIRQHandler
        BX      R0

        PUBWEAK BOD_IRQHandler
        PUBWEAK BOD_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
BOD_IRQHandler
        LDR     R0, =BOD_DriverIRQHandler
        BX      R0

        PUBWEAK FLASH_IRQHandler
        PUBWEAK FLASH_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLASH_IRQHandler
        LDR     R0, =FLASH_DriverIRQHandler
        BX      R0

        PUBWEAK WKT_IRQHandler
        PUBWEAK WKT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WKT_IRQHandler
        LDR     R0, =WKT_DriverIRQHandler
        BX      R0

        PUBWEAK ADC0_SEQA_IRQHandler
        PUBWEAK ADC0_SEQA_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ADC0_SEQA_IRQHandler
        LDR     R0, =ADC0_SEQA_DriverIRQHandler
        BX      R0

        PUBWEAK ADC0_SEQB_IRQHandler
        PUBWEAK ADC0_SEQB_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ADC0_SEQB_IRQHandler
        LDR     R0, =ADC0_SEQB_DriverIRQHandler
        BX      R0

        PUBWEAK ADC0_THCMP_IRQHandler
        PUBWEAK ADC0_THCMP_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ADC0_THCMP_IRQHandler
        LDR     R0, =ADC0_THCMP_DriverIRQHandler
        BX      R0

        PUBWEAK ADC0_OVR_IRQHandler
        PUBWEAK ADC0_OVR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ADC0_OVR_IRQHandler
        LDR     R0, =ADC0_OVR_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_IRQHandler
        PUBWEAK DMA0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK I2C2_IRQHandler
        PUBWEAK I2C2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2C2_IRQHandler
        LDR     R0, =I2C2_DriverIRQHandler
        BX      R0

        PUBWEAK I2C3_IRQHandler
        PUBWEAK I2C3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2C3_IRQHandler
        LDR     R0, =I2C3_DriverIRQHandler
        BX      R0

        PUBWEAK CTIMER0_IRQHandler
        PUBWEAK CTIMER0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CTIMER0_IRQHandler
        LDR     R0, =CTIMER0_DriverIRQHandler
        BX      R0

        PUBWEAK PIN_INT0_IRQHandler
        PUBWEAK PIN_INT0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PIN_INT0_IRQHandler
        LDR     R0, =PIN_INT0_DriverIRQHandler
        BX      R0

        PUBWEAK PIN_INT1_IRQHandler
        PUBWEAK PIN_INT1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PIN_INT1_IRQHandler
        LDR     R0, =PIN_INT1_DriverIRQHandler
        BX      R0

        PUBWEAK PIN_INT2_IRQHandler
        PUBWEAK PIN_INT2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PIN_INT2_IRQHandler
        LDR     R0, =PIN_INT2_DriverIRQHandler
        BX      R0

        PUBWEAK PIN_INT3_IRQHandler
        PUBWEAK PIN_INT3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PIN_INT3_IRQHandler
        LDR     R0, =PIN_INT3_DriverIRQHandler
        BX      R0

        PUBWEAK PIN_INT4_IRQHandler
        PUBWEAK PIN_INT4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PIN_INT4_IRQHandler
        LDR     R0, =PIN_INT4_DriverIRQHandler
        BX      R0

        PUBWEAK PIN_INT5_DAC1_IRQHandler
        PUBWEAK PIN_INT5_DAC1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PIN_INT5_DAC1_IRQHandler
        LDR     R0, =PIN_INT5_DAC1_DriverIRQHandler
        BX      R0

        PUBWEAK PIN_INT6_USART3_IRQHandler
        PUBWEAK PIN_INT6_USART3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PIN_INT6_USART3_IRQHandler
        LDR     R0, =PIN_INT6_USART3_DriverIRQHandler
        BX      R0

        PUBWEAK PIN_INT7_USART4_IRQHandler
        PUBWEAK PIN_INT7_USART4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PIN_INT7_USART4_IRQHandler
        LDR     R0, =PIN_INT7_USART4_DriverIRQHandler
        BX      R0

SPI0_DriverIRQHandler
SPI1_DriverIRQHandler
DAC0_DriverIRQHandler
USART0_DriverIRQHandler
USART1_DriverIRQHandler
USART2_DriverIRQHandler
Reserved22_DriverIRQHandler
I2C1_DriverIRQHandler
I2C0_DriverIRQHandler
SCT0_DriverIRQHandler
MRT0_DriverIRQHandler
CMP_CAPT_DriverIRQHandler
WDT_DriverIRQHandler
BOD_DriverIRQHandler
FLASH_DriverIRQHandler
WKT_DriverIRQHandler
ADC0_SEQA_DriverIRQHandler
ADC0_SEQB_DriverIRQHandler
ADC0_THCMP_DriverIRQHandler
ADC0_OVR_DriverIRQHandler
DMA0_DriverIRQHandler
I2C2_DriverIRQHandler
I2C3_DriverIRQHandler
CTIMER0_DriverIRQHandler
PIN_INT0_DriverIRQHandler
PIN_INT1_DriverIRQHandler
PIN_INT2_DriverIRQHandler
PIN_INT3_DriverIRQHandler
PIN_INT4_DriverIRQHandler
PIN_INT5_DAC1_DriverIRQHandler
PIN_INT6_USART3_DriverIRQHandler
PIN_INT7_USART4_DriverIRQHandler
DefaultISR
        B .

        END
