; -------------------------------------------------------------------------
;  @file:    startup_MKM35Z7.s
;  @purpose: CMSIS Cortex-M0P Core Device Startup File
;            MKM35Z7
;  @version: 3.0
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
        DCD     DMA0_IRQHandler                               ;DMA channel 0 transfer complete
        DCD     DMA1_IRQHandler                               ;DMA channel 1 transfer complete
        DCD     DMA2_IRQHandler                               ;DMA channel 2 transfer complete
        DCD     DMA3_IRQHandler                               ;DMA channel 3 transfer complete
        DCD     SPI0_SPI1_SPI2_IRQHandler                     ;SPI0/SPI1/SPI2 ORed interrupt
        DCD     PDB0_IRQHandler                               ;PDB0 ORed interrupt
        DCD     PMC_IRQHandler                                ;Low-voltage detect, low-voltage warning
        DCD     TMR0_IRQHandler                               ;Quad Timer Channel 0
        DCD     TMR1_IRQHandler                               ;Quad Timer Channel 1
        DCD     TMR2_IRQHandler                               ;Quad Timer Channel 2
        DCD     TMR3_IRQHandler                               ;Quad Timer Channel 3
        DCD     PIT0_PIT1_IRQHandler                          ;PIT0/PIT1 ORed interrupt
        DCD     LLWU_IRQHandler                               ;Low Leakage Wakeup
        DCD     FTFA_IRQHandler                               ;Command complete and read collision
        DCD     CMP0_CMP1_CMP2_IRQHandler                     ;CMP0/CMP1/CMP2 ORed interrupt
        DCD     LCD_IRQHandler                                ;LCD interrupt
        DCD     ADC0_IRQHandler                               ;ADC0 interrupt
        DCD     PTx_IRQHandler                                ;Single interrupt vector for GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH,GPIOI,GPIOJ,GPIOK,GPIOL,GPIOM
        DCD     RNGA_IRQHandler                               ;RNGA interrupt
        DCD     UART0_UART1_UART2_UART3_IRQHandler            ;UART0/UART1/UART2/UART3 ORed interrupt
        DCD     MMAU_IRQHandler                               ;Memory Mapped Arithmetic Unit interrupt
        DCD     AFE_CH0_IRQHandler                            ;AFE Channel 0
        DCD     AFE_CH1_IRQHandler                            ;AFE Channel 1
        DCD     AFE_CH2_IRQHandler                            ;AFE Channel 2
        DCD     AFE_CH3_IRQHandler                            ;AFE Channel 3
        DCD     RTC_IRQHandler                                ;IRTC interrupt
        DCD     I2C0_I2C1_IRQHandler                          ;I2C0/I2C1 ORed interrupt
        DCD     LPUART0_IRQHandler                            ;LPUART0 status and error interrupt
        DCD     MCG_IRQHandler                                ;MCG interrupt
        DCD     WDOG_EWM_IRQHandler                           ;WDOG/EWM ORed interrupt
        DCD     LPTMR0_LPTMR1_IRQHandler                      ;LPTMR0/LPTMR1 interrupt
        DCD     XBAR_IRQHandler                               ;XBAR interrupt
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

        PUBWEAK SPI0_SPI1_SPI2_IRQHandler
        PUBWEAK SPI0_SPI1_SPI2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SPI0_SPI1_SPI2_IRQHandler
        LDR     R0, =SPI0_SPI1_SPI2_DriverIRQHandler
        BX      R0

        PUBWEAK PDB0_IRQHandler
        PUBWEAK PMC_IRQHandler
        PUBWEAK TMR0_IRQHandler
        PUBWEAK TMR1_IRQHandler
        PUBWEAK TMR2_IRQHandler
        PUBWEAK TMR3_IRQHandler
        PUBWEAK PIT0_PIT1_IRQHandler
        PUBWEAK LLWU_IRQHandler
        PUBWEAK FTFA_IRQHandler
        PUBWEAK CMP0_CMP1_CMP2_IRQHandler
        PUBWEAK LCD_IRQHandler
        PUBWEAK ADC0_IRQHandler
        PUBWEAK PTx_IRQHandler
        PUBWEAK RNGA_IRQHandler
        PUBWEAK UART0_UART1_UART2_UART3_IRQHandler
        PUBWEAK UART0_UART1_UART2_UART3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
UART0_UART1_UART2_UART3_IRQHandler
        LDR     R0, =UART0_UART1_UART2_UART3_DriverIRQHandler
        BX      R0

        PUBWEAK MMAU_IRQHandler
        PUBWEAK AFE_CH0_IRQHandler
        PUBWEAK AFE_CH1_IRQHandler
        PUBWEAK AFE_CH2_IRQHandler
        PUBWEAK AFE_CH3_IRQHandler
        PUBWEAK RTC_IRQHandler
        PUBWEAK I2C0_I2C1_IRQHandler
        PUBWEAK I2C0_I2C1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2C0_I2C1_IRQHandler
        LDR     R0, =I2C0_I2C1_DriverIRQHandler
        BX      R0

        PUBWEAK LPUART0_IRQHandler
        PUBWEAK LPUART0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART0_IRQHandler
        LDR     R0, =LPUART0_DriverIRQHandler
        BX      R0

        PUBWEAK MCG_IRQHandler
        PUBWEAK WDOG_EWM_IRQHandler
        PUBWEAK LPTMR0_LPTMR1_IRQHandler
        PUBWEAK XBAR_IRQHandler
        PUBWEAK DefaultISR
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_DriverIRQHandler
DMA1_DriverIRQHandler
DMA2_DriverIRQHandler
DMA3_DriverIRQHandler
SPI0_SPI1_SPI2_DriverIRQHandler
PDB0_IRQHandler
PMC_IRQHandler
TMR0_IRQHandler
TMR1_IRQHandler
TMR2_IRQHandler
TMR3_IRQHandler
PIT0_PIT1_IRQHandler
LLWU_IRQHandler
FTFA_IRQHandler
CMP0_CMP1_CMP2_IRQHandler
LCD_IRQHandler
ADC0_IRQHandler
PTx_IRQHandler
RNGA_IRQHandler
UART0_UART1_UART2_UART3_DriverIRQHandler
MMAU_IRQHandler
AFE_CH0_IRQHandler
AFE_CH1_IRQHandler
AFE_CH2_IRQHandler
AFE_CH3_IRQHandler
RTC_IRQHandler
I2C0_I2C1_DriverIRQHandler
LPUART0_DriverIRQHandler
MCG_IRQHandler
WDOG_EWM_IRQHandler
LPTMR0_LPTMR1_IRQHandler
XBAR_IRQHandler
DefaultISR
        LDR R0, =DefaultISR
        BX R0

        END
