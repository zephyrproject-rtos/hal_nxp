; -------------------------------------------------------------------------
;  @file:    startup_K32L3A60_cm0plus.s
;  @purpose: CMSIS Cortex-M0P Core Device Startup File
;            K32L3A60_cm0plus
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
        DCD     CTI1_IRQHandler                               ;Cross Trigger Interface 1
        DCD     DMA1_04_IRQHandler                            ;DMA1 channel 0/4 transfer complete
        DCD     DMA1_15_IRQHandler                            ;DMA1 channel 1/5 transfer complete
        DCD     DMA1_26_IRQHandler                            ;DMA1 channel 2/6 transfer complete
        DCD     DMA1_37_IRQHandler                            ;DMA1 channel 3/7 transfer complete
        DCD     DMA1_Error_IRQHandler                         ;DMA1 channel 0-7 error interrupt
        DCD     MSMC_IRQHandler                               ;MSMC (SMC1) interrupt
        DCD     LLWU1_IRQHandler                              ;Low leakage wakeup 1
        DCD     MUB_IRQHandler                                ;MU Side B interrupt
        DCD     WDOG1_IRQHandler                              ;WDOG1 interrupt
        DCD     CAU3_Task_Complete_IRQHandler                 ;Cryptographic Acceleration Unit version 3 Task Complete
        DCD     CAU3_Security_Violation_IRQHandler            ;Cryptographic Acceleration Unit version 3 Security Violation
        DCD     TRNG_IRQHandler                               ;TRNG interrupt
        DCD     LPIT1_IRQHandler                              ;LPIT1 interrupt
        DCD     LPTMR2_IRQHandler                             ;LPTMR2 interrupt
        DCD     TPM3_IRQHandler                               ;TPM3 single interrupt vector for all sources
        DCD     LPI2C3_IRQHandler                             ;LPI2C3 interrupt
        DCD     Reserved33_IRQHandler                         ;Reserved interrupt
        DCD     Reserved34_IRQHandler                         ;Reserved interrupt
        DCD     LPSPI3_IRQHandler                             ;LPSPI3 single interrupt vector for all sources
        DCD     LPUART3_IRQHandler                            ;LPUART3 status and error
        DCD     PORTE_IRQHandler                              ;PORTE Pin detect
        DCD     LPCMP1_IRQHandler                             ;LPCMP1 interrupt
        DCD     RTC_IRQHandler                                ;RTC
        DCD     INTMUX1_0_IRQHandler                          ;INTMUX1 channel0 interrupt
        DCD     INTMUX1_1_IRQHandler                          ;INTMUX1 channel1 interrupt
        DCD     INTMUX1_2_IRQHandler                          ;INTMUX1 channel2 interrupt
        DCD     INTMUX1_3_IRQHandler                          ;INTMUX1 channel3 interrupt
        DCD     INTMUX1_4_IRQHandler                          ;INTMUX1 channel4 interrupt
        DCD     INTMUX1_5_IRQHandler                          ;INTMUX1 channel5 interrupt
        DCD     INTMUX1_6_IRQHandler                          ;INTMUX1 channel6 interrupt
        DCD     INTMUX1_7_IRQHandler                          ;INTMUX1 channel7 interrupt
        DCD     EWM_IRQHandler                                ;EWM interrupt  (INTMUX1 source IRQ0)
        DCD     FTFE_Command_Complete_IRQHandler              ;FTFE interrupt  (INTMUX1 source IRQ1)
        DCD     FTFE_Read_Collision_IRQHandler                ;FTFE interrupt  (INTMUX1 source IRQ2)
        DCD     SPM_IRQHandler                                ;SPM (INTMUX1 source IRQ3)
        DCD     SCG_IRQHandler                                ;SCG interrupt (INTMUX1 source IRQ4)
        DCD     LPIT0_IRQHandler                              ;LPIT0 interrupt (INTMUX1 source IRQ5)
        DCD     LPTMR0_IRQHandler                             ;LPTMR0 interrupt (INTMUX1 source IRQ6)
        DCD     LPTMR1_IRQHandler                             ;LPTMR1 interrupt (INTMUX1 source IRQ7)
        DCD     TPM0_IRQHandler                               ;TPM0 single interrupt vector for all sources (INTMUX1 source IRQ8)
        DCD     TPM1_IRQHandler                               ;TPM1 single interrupt vector for all sources (INTMUX1 source IRQ9)
        DCD     TPM2_IRQHandler                               ;TPM2 single interrupt vector for all sources (INTMUX1 source IRQ10)
        DCD     EMVSIM0_IRQHandler                            ;EMVSIM0 interrupt (INTMUX1 source IRQ11)
        DCD     FLEXIO0_IRQHandler                            ;FLEXIO0 (INTMUX1 source IRQ12)
        DCD     LPI2C0_IRQHandler                             ;LPI2C0 interrupt (INTMUX1 source IRQ13)
        DCD     LPI2C1_IRQHandler                             ;LPI2C1 interrupt (INTMUX1 source IRQ14)
        DCD     LPI2C2_IRQHandler                             ;LPI2C2 interrupt (INTMUX1 source IRQ15)
        DCD     I2S0_IRQHandler                               ;I2S0 interrupt (INTMUX1 source IRQ16)
        DCD     USDHC0_IRQHandler                             ;SDHC0 interrupt (INTMUX1 source IRQ17)
        DCD     LPSPI0_IRQHandler                             ;LPSPI0 single interrupt vector for all sources (INTMUX1 source IRQ18)
        DCD     LPSPI1_IRQHandler                             ;LPSPI1 single interrupt vector for all sources (INTMUX1 source IRQ19)
        DCD     LPSPI2_IRQHandler                             ;LPSPI2 single interrupt vector for all sources (INTMUX1 source IRQ20)
        DCD     LPUART0_IRQHandler                            ;LPUART0 status and error (INTMUX1 source IRQ21)
        DCD     LPUART1_IRQHandler                            ;LPUART1 status and error (INTMUX1 source IRQ22)
        DCD     LPUART2_IRQHandler                            ;LPUART2 status and error (INTMUX1 source IRQ23)
        DCD     USB0_IRQHandler                               ;USB0 interrupt (INTMUX1 source IRQ24)
        DCD     PORTA_IRQHandler                              ;PORTA Pin detect (INTMUX1 source IRQ25)
        DCD     PORTB_IRQHandler                              ;PORTB Pin detect (INTMUX1 source IRQ26)
        DCD     PORTC_IRQHandler                              ;PORTC Pin detect (INTMUX1 source IRQ27)
        DCD     PORTD_IRQHandler                              ;PORTD Pin detect (INTMUX1 source IRQ28)
        DCD     LPADC0_IRQHandler                             ;LPADC0 interrupt (INTMUX1 source IRQ29)
        DCD     LPCMP0_IRQHandler                             ;LPCMP0 interrupt (INTMUX1 source IRQ30)
        DCD     LPDAC0_IRQHandler                             ;LPDAC0 interrupt (INTMUX1 source IRQ31)
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

        PUBWEAK CTI1_IRQHandler
        PUBWEAK DMA1_04_IRQHandler
        PUBWEAK DMA1_04_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_04_IRQHandler
        LDR     R0, =DMA1_04_DriverIRQHandler
        BX      R0

        PUBWEAK DMA1_15_IRQHandler
        PUBWEAK DMA1_15_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_15_IRQHandler
        LDR     R0, =DMA1_15_DriverIRQHandler
        BX      R0

        PUBWEAK DMA1_26_IRQHandler
        PUBWEAK DMA1_26_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_26_IRQHandler
        LDR     R0, =DMA1_26_DriverIRQHandler
        BX      R0

        PUBWEAK DMA1_37_IRQHandler
        PUBWEAK DMA1_37_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_37_IRQHandler
        LDR     R0, =DMA1_37_DriverIRQHandler
        BX      R0

        PUBWEAK DMA1_Error_IRQHandler
        PUBWEAK DMA1_Error_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_Error_IRQHandler
        LDR     R0, =DMA1_Error_DriverIRQHandler
        BX      R0

        PUBWEAK MSMC_IRQHandler
        PUBWEAK LLWU1_IRQHandler
        PUBWEAK MUB_IRQHandler
        PUBWEAK WDOG1_IRQHandler
        PUBWEAK CAU3_Task_Complete_IRQHandler
        PUBWEAK CAU3_Security_Violation_IRQHandler
        PUBWEAK TRNG_IRQHandler
        PUBWEAK LPIT1_IRQHandler
        PUBWEAK LPTMR2_IRQHandler
        PUBWEAK TPM3_IRQHandler
        PUBWEAK LPI2C3_IRQHandler
        PUBWEAK LPI2C3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C3_IRQHandler
        LDR     R0, =LPI2C3_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved33_IRQHandler
        PUBWEAK Reserved34_IRQHandler
        PUBWEAK LPSPI3_IRQHandler
        PUBWEAK LPSPI3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPSPI3_IRQHandler
        LDR     R0, =LPSPI3_DriverIRQHandler
        BX      R0

        PUBWEAK LPUART3_IRQHandler
        PUBWEAK LPUART3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART3_IRQHandler
        LDR     R0, =LPUART3_DriverIRQHandler
        BX      R0

        PUBWEAK PORTE_IRQHandler
        PUBWEAK LPCMP1_IRQHandler
        PUBWEAK RTC_IRQHandler
        PUBWEAK INTMUX1_0_IRQHandler
        PUBWEAK INTMUX1_0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
INTMUX1_0_IRQHandler
        LDR     R0, =INTMUX1_0_DriverIRQHandler
        BX      R0

        PUBWEAK INTMUX1_1_IRQHandler
        PUBWEAK INTMUX1_1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
INTMUX1_1_IRQHandler
        LDR     R0, =INTMUX1_1_DriverIRQHandler
        BX      R0

        PUBWEAK INTMUX1_2_IRQHandler
        PUBWEAK INTMUX1_2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
INTMUX1_2_IRQHandler
        LDR     R0, =INTMUX1_2_DriverIRQHandler
        BX      R0

        PUBWEAK INTMUX1_3_IRQHandler
        PUBWEAK INTMUX1_3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
INTMUX1_3_IRQHandler
        LDR     R0, =INTMUX1_3_DriverIRQHandler
        BX      R0

        PUBWEAK INTMUX1_4_IRQHandler
        PUBWEAK INTMUX1_4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
INTMUX1_4_IRQHandler
        LDR     R0, =INTMUX1_4_DriverIRQHandler
        BX      R0

        PUBWEAK INTMUX1_5_IRQHandler
        PUBWEAK INTMUX1_5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
INTMUX1_5_IRQHandler
        LDR     R0, =INTMUX1_5_DriverIRQHandler
        BX      R0

        PUBWEAK INTMUX1_6_IRQHandler
        PUBWEAK INTMUX1_6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
INTMUX1_6_IRQHandler
        LDR     R0, =INTMUX1_6_DriverIRQHandler
        BX      R0

        PUBWEAK INTMUX1_7_IRQHandler
        PUBWEAK INTMUX1_7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
INTMUX1_7_IRQHandler
        LDR     R0, =INTMUX1_7_DriverIRQHandler
        BX      R0

        PUBWEAK EWM_IRQHandler
        PUBWEAK FTFE_Command_Complete_IRQHandler
        PUBWEAK FTFE_Read_Collision_IRQHandler
        PUBWEAK SPM_IRQHandler
        PUBWEAK SCG_IRQHandler
        PUBWEAK LPIT0_IRQHandler
        PUBWEAK LPTMR0_IRQHandler
        PUBWEAK LPTMR1_IRQHandler
        PUBWEAK TPM0_IRQHandler
        PUBWEAK TPM1_IRQHandler
        PUBWEAK TPM2_IRQHandler
        PUBWEAK EMVSIM0_IRQHandler
        PUBWEAK FLEXIO0_IRQHandler
        PUBWEAK FLEXIO0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXIO0_IRQHandler
        LDR     R0, =FLEXIO0_DriverIRQHandler
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

        PUBWEAK LPI2C2_IRQHandler
        PUBWEAK LPI2C2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C2_IRQHandler
        LDR     R0, =LPI2C2_DriverIRQHandler
        BX      R0

        PUBWEAK I2S0_IRQHandler
        PUBWEAK I2S0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2S0_IRQHandler
        LDR     R0, =I2S0_DriverIRQHandler
        BX      R0

        PUBWEAK USDHC0_IRQHandler
        PUBWEAK USDHC0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USDHC0_IRQHandler
        LDR     R0, =USDHC0_DriverIRQHandler
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

        PUBWEAK USB0_IRQHandler
        PUBWEAK PORTA_IRQHandler
        PUBWEAK PORTB_IRQHandler
        PUBWEAK PORTC_IRQHandler
        PUBWEAK PORTD_IRQHandler
        PUBWEAK LPADC0_IRQHandler
        PUBWEAK LPCMP0_IRQHandler
        PUBWEAK LPDAC0_IRQHandler
        PUBWEAK DefaultISR
        SECTION .text:CODE:REORDER:NOROOT(2)
CTI1_IRQHandler
DMA1_04_DriverIRQHandler
DMA1_15_DriverIRQHandler
DMA1_26_DriverIRQHandler
DMA1_37_DriverIRQHandler
DMA1_Error_DriverIRQHandler
MSMC_IRQHandler
LLWU1_IRQHandler
MUB_IRQHandler
WDOG1_IRQHandler
CAU3_Task_Complete_IRQHandler
CAU3_Security_Violation_IRQHandler
TRNG_IRQHandler
LPIT1_IRQHandler
LPTMR2_IRQHandler
TPM3_IRQHandler
LPI2C3_DriverIRQHandler
Reserved33_IRQHandler
Reserved34_IRQHandler
LPSPI3_DriverIRQHandler
LPUART3_DriverIRQHandler
PORTE_IRQHandler
LPCMP1_IRQHandler
RTC_IRQHandler
INTMUX1_0_DriverIRQHandler
INTMUX1_1_DriverIRQHandler
INTMUX1_2_DriverIRQHandler
INTMUX1_3_DriverIRQHandler
INTMUX1_4_DriverIRQHandler
INTMUX1_5_DriverIRQHandler
INTMUX1_6_DriverIRQHandler
INTMUX1_7_DriverIRQHandler
EWM_IRQHandler
FTFE_Command_Complete_IRQHandler
FTFE_Read_Collision_IRQHandler
SPM_IRQHandler
SCG_IRQHandler
LPIT0_IRQHandler
LPTMR0_IRQHandler
LPTMR1_IRQHandler
TPM0_IRQHandler
TPM1_IRQHandler
TPM2_IRQHandler
EMVSIM0_IRQHandler
FLEXIO0_DriverIRQHandler
LPI2C0_DriverIRQHandler
LPI2C1_DriverIRQHandler
LPI2C2_DriverIRQHandler
I2S0_DriverIRQHandler
USDHC0_DriverIRQHandler
LPSPI0_DriverIRQHandler
LPSPI1_DriverIRQHandler
LPSPI2_DriverIRQHandler
LPUART0_DriverIRQHandler
LPUART1_DriverIRQHandler
LPUART2_DriverIRQHandler
USB0_IRQHandler
PORTA_IRQHandler
PORTB_IRQHandler
PORTC_IRQHandler
PORTD_IRQHandler
LPADC0_IRQHandler
LPCMP0_IRQHandler
LPDAC0_IRQHandler
DefaultISR
        LDR R0, =DefaultISR
        BX R0

        END
