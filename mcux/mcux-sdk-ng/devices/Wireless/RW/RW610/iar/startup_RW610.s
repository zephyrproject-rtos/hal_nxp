; -------------------------------------------------------------------------
;  @file:    startup_RW610.s
;  @purpose: CMSIS Cortex-M33 Core Device Startup File
;            RW610
;  @version: 3.0
;  @date:    2025-4-7
;  @build:   b250519
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
        SECTION RO:CODE:NOROOT(2)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit
        PUBLIC  __vector_table
        PUBLIC  __vector_table_0x1c
        PUBLIC  __Vectors
        PUBLIC  __Vectors_End
        PUBLIC  __Vectors_Size

        DATA

;;The vector table is not needed for initialization.
__iar_init$$done

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
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
        DCD     0x100000 ;Image length
#else
        DCD     sfe(RO) - __vector_table ;Image length
#endif
        DCD     0                                             ;Reserved
        DCD     0                                             ;Reserved
        DCD     SVC_Handler                                   ;SVCall Handler
        DCD     DebugMon_Handler                              ;Debug Monitor Handler
        DCD     __vector_table                                ;Image load address
        DCD     PendSV_Handler                                ;PendSV Handler
        DCD     SysTick_Handler                               ;SysTick Handler

                                                              ;External Interrupts
        DCD     WDT0_IRQHandler                               ;Windowed watchdog timer 0 (WDT0)(Cortex-M33 watchdog)
        DCD     DMA0_IRQHandler                               ;Direct memory access (DMA) controller 0 (secure or Cortex-M33 DMA)
        DCD     GPIO_INTA_IRQHandler                          ;GPIO interrupt A
        DCD     GPIO_INTB_IRQHandler                          ;GPIO interrupt B
        DCD     PIN_INT0_IRQHandler                           ;Pin interrupt 0 or pattern match engine slice 0
        DCD     PIN_INT1_IRQHandler                           ;Pin interrupt 1 or pattern match engine slice 1
        DCD     PIN_INT2_IRQHandler                           ;Pin interrupt 2 or pattern match engine slice 2
        DCD     PIN_INT3_IRQHandler                           ;Pin interrupt 3 or pattern match engine slice 3
        DCD     UTICK_IRQHandler                              ;Micro-tick Timer (UTICK)
        DCD     MRT_IRQHandler                                ;Multi-Rate Timer (MRT). Global MRT interrupts
        DCD     CTIMER0_IRQHandler                            ;Standard counter/timer CTIMER0
        DCD     CTIMER1_IRQHandler                            ;Standard counter/timer CTIMER1
        DCD     SCT0_IRQHandler                               ;SCTimer/PWM
        DCD     CTIMER3_IRQHandler                            ;Standard counter/timer CTIMER3
        DCD     FLEXCOMM0_IRQHandler                          ;Flexcomm Interface 0 (USART, SPI, I2C, I2S)
        DCD     FLEXCOMM1_IRQHandler                          ;Flexcomm Interface 1 (USART, SPI, I2C, I2S)
        DCD     FLEXCOMM2_IRQHandler                          ;Flexcomm Interface 2 (USART, SPI, I2C, I2S)
        DCD     FLEXCOMM3_IRQHandler                          ;Flexcomm Interface 3 (USART, SPI, I2C, I2S)
        DCD     Reserved34_IRQHandler                         ;Reserved interrupt
        DCD     Reserved35_IRQHandler                         ;Reserved interrupt
        DCD     FLEXCOMM14_IRQHandler                         ;Flexcomm Interface 14 (USART, SPI, I2C, I2S)
        DCD     Reserved37_IRQHandler                         ;Reserved interrupt
        DCD     Reserved38_IRQHandler                         ;Reserved interrupt
        DCD     GFMRT_IRQHandler                              ;Free Multi-rate timer (GFMRT). Global MRT interrupts
        DCD     Reserved40_IRQHandler                         ;Reserved interrupt
        DCD     DMIC_IRQHandler                               ;Digital microphone (DMIC) and DMIC subsystem
        DCD     WKDEEPSLEEP_IRQHandler                        ;Wake-up from deep sleep
        DCD     HYPERVISOR_IRQHandler                         ;Hypervisor service software interrupt
        DCD     SECUREVIOLATION_IRQHandler                    ;Secure violation
        DCD     HWVAD_IRQHandler                              ;Hardware Voice Activity Detector
        DCD     Reserved46_IRQHandler                         ;Reserved interrupt
        DCD     Reserved47_IRQHandler                         ;Reserved interrupt
        DCD     RTC_IRQHandler                                ;RTC alarm and wake-up
        DCD     Reserved49_IRQHandler                         ;Reserved interrupt
        DCD     Reserved50_IRQHandler                         ;Reserved interrupt
        DCD     PIN_INT4_IRQHandler                           ;Pin interrupt 4 or pattern match engine slice 4
        DCD     PIN_INT5_IRQHandler                           ;Pin interrupt 5 or pattern match engine slice 5
        DCD     PIN_INT6_IRQHandler                           ;Pin interrupt 6 or pattern match engine slice 6
        DCD     PIN_INT7_IRQHandler                           ;Pin interrupt 7 or pattern match engine slice 7
        DCD     CTIMER2_IRQHandler                            ;Standard counter/timer CTIMER2
        DCD     CTIMER4_IRQHandler                            ;Standard counter/timer CTIMER4
        DCD     OS_EVENT_TIMER_IRQHandler                     ;OS event timer 0
        DCD     FLEXSPI_IRQHandler                            ;FLEXSPI interface
        DCD     Reserved59_IRQHandler                         ;Reserved interrupt
        DCD     Reserved60_IRQHandler                         ;Reserved interrupt
        DCD     Reserved61_IRQHandler                         ;Reserved interrupt
        DCD     SDIO_IRQHandler                               ;The secure digital interface
        DCD     SGPIO_INTA_IRQHandler                         ;Secure GPIO interrupt A
        DCD     SGPIO_INTB_IRQHandler                         ;Secure GPIO interrupt B
        DCD     Reserved65_IRQHandler                         ;Reserved interrupt
        DCD     USB_IRQHandler                                ;High-speed USB device/host
        DCD     Reserved67_IRQHandler                         ;Reserved interrupt
        DCD     Reserved68_IRQHandler                         ;Reserved interrupt
        DCD     Reserved69_IRQHandler                         ;Reserved interrupt
        DCD     DMA1_IRQHandler                               ;DMA controller 1 (non-secure or HiFi 4 DMA)
        DCD     PUF_IRQHandler                                ;Physical Unclonable Function
        DCD     POWERQUAD_IRQHandler                          ;PowerQuad math coprocessor
        DCD     Reserved73_IRQHandler                         ;Reserved interrupt
        DCD     Reserved74_IRQHandler                         ;Reserved interrupt
        DCD     Reserved75_IRQHandler                         ;Reserved interrupt
        DCD     Reserved76_IRQHandler                         ;Reserved interrupt
        DCD     LCD_IRQHandler                                ;LCDIC
        DCD     CAPTIMER_IRQHandler                           ;Capture timer
        DCD     Reserved79_IRQHandler                         ;Reserved interrupt
        DCD     W2MWKUP_DONE0_IRQHandler                      ;Wi-Fi to MCU, wakeup done 0
        DCD     W2MWKUP_DONE1_IRQHandler                      ;Wi-Fi to MCU, wakeup done 1
        DCD     W2MWKUP_DONE2_IRQHandler                      ;Wi-Fi to MCU, wakeup done 2
        DCD     W2MWKUP_DONE3_IRQHandler                      ;Wi-Fi to MCU, wakeup done 3
        DCD     W2MWKUP_DONE4_IRQHandler                      ;Wi-Fi to MCU, wakeup done 4
        DCD     W2MWKUP_DONE5_IRQHandler                      ;Wi-Fi to MCU, wakeup done 5
        DCD     W2MWKUP_DONE6_IRQHandler                      ;Wi-Fi to MCU, wakeup done 6
        DCD     W2MWKUP_DONE7_IRQHandler                      ;Wi-Fi to MCU, wakeup done 7
        DCD     W2MWKUP0_IRQHandler                           ;Wi-Fi to MCU, wakeup signal 0
        DCD     W2MWKUP1_IRQHandler                           ;Wi-Fi to MCU, wakueup signal 1
        DCD     WL_MCI_INT0_IRQHandler                        ;Wi-Fi to MCU interrupt 0
        DCD     WL_MCI_INT1_IRQHandler                        ;Reserved for Wi-Fi to MCU
        DCD     WL_MCI_INT2_IRQHandler                        ;Reserved for Wi-Fi to MCU
        DCD     WL_MCI_INT3_IRQHandler                        ;Reserved for Wi-Fi to MCU
        DCD     WL_MCI_INT4_IRQHandler                        ;Reserved for Wi-Fi to MCU
        DCD     WL_MCI_INT5_IRQHandler                        ;Reserved for Wi-Fi to MCU
        DCD     WL_MCI_INT6_IRQHandler                        ;Reserved for Wi-Fi to MCU
        DCD     WL_MCI_INT7_IRQHandler                        ;Reserved for Wi-Fi to MCU
        DCD     B2MWKUP_DONE0_IRQHandler                      ;Bluetooth LE/802.15.4 radio to MCU, wakeup done 0
        DCD     B2MWKUP_DONE1_IRQHandler                      ;Bluetooth LE/802.15.4 radio to MCU, wakeup done 1
        DCD     B2MWKUP_DONE2_IRQHandler                      ;Bluetooth LE/802.15.4 radio to MCU, wakeup done 2
        DCD     B2MWKUP_DONE3_IRQHandler                      ;Bluetooth LE/802.15.4 radio to MCU, wakeup done 3
        DCD     B2MWKUP_DONE4_IRQHandler                      ;Bluetooth LE/802.15.4 radio to MCU, wakeup done 4
        DCD     B2MWKUP_DONE5_IRQHandler                      ;Bluetooth LE/802.15.4 radio to MCU, wakeup done 5
        DCD     B2MWKUP_DONE6_IRQHandler                      ;Bluetooth LE/802.15.4 radio to MCU, wakeup done 6
        DCD     B2MWKUP_DONE7_IRQHandler                      ;Bluetooth LE/802.15.4 radio to MCU, wakeup done 7
        DCD     B2MWKUP0_IRQHandler                           ;Bluetooth LE/802.15.4 radio to MCU, wakeup signal 0
        DCD     B2MWKUP1_IRQHandler                           ;Bluetooth LE/802.15.4 radio to MCU, wakeup signal 1
        DCD     BLE_MCI_INT0_IRQHandler                       ;Bluetooth LE/802.15.4 radio to MCU interrupt 0
        DCD     BLE_MCI_INT1_IRQHandler                       ;Reserved for Bluetooth LE/802.15.4 radio to MCU
        DCD     BLE_MCI_INT2_IRQHandler                       ;Reserved for Bluetooth LE/802.15.4 radio to MCU
        DCD     BLE_MCI_INT3_IRQHandler                       ;Reserved for Bluetooth LE/802.15.4 radio to MCU
        DCD     BLE_MCI_INT4_IRQHandler                       ;Reserved for Bluetooth LE/802.15.4 radio to MCU
        DCD     BLE_MCI_INT5_IRQHandler                       ;Reserved for Bluetooth LE/802.15.4 radio to MCU
        DCD     BLE_MCI_INT6_IRQHandler                       ;Reserved for Bluetooth LE/802.15.4 radio to MCU
        DCD     BLE_MCI_INT7_IRQHandler                       ;Reserved for Bluetooth LE/802.15.4 radio to MCU
        DCD     PIN0_INT_IRQHandler                           ;From AON GPIO
        DCD     PIN1_INT_IRQHandler                           ;From AON GPIO
        DCD     ELS_IRQHandler                                ;EdgeLock subsystem (ELS)
        DCD     ELS_GDET_IRQHandler                           ;ELS IRQ line for GDET error
        DCD     ELS_GDET_UM_IRQHandler                        ;ELS un-gated latched error
        DCD     PKC_INT_IRQHandler                            ;Public key crypto-processor (PKC) interrupt
        DCD     PKC_ERR_IRQHandler                            ;PKC error
        DCD     CDOG_INT_IRQHandler                           ;Code watch dog timmer interrupt
        DCD     GAU_DAC_IRQHandler                            ;General analog unit (GAU) digital to analog converter (DAC)
        DCD     GAU_ACOMP_WKUP_IRQHandler                     ;GAU analog comparator (ACOMP) wake-up
        DCD     GAU_ACOMP_IRQHandler                          ;GAU analog comparator
        DCD     GAU_ADC1_IRQHandler                           ;GAU analog to digital converter 1 (ADC1)
        DCD     GAU_ADC0_IRQHandler                           ;GAU analog to digital converter 0 (ADC0)
        DCD     USIM_IRQHandler                               ;Universal subscriber identity module (USIM) interface
        DCD     OTP_IRQHandler                                ;One time programmable (OTP) memory interrupt
        DCD     ENET_IRQHandler                               ;Etheret interrupt
        DCD     ENET_TIMER_IRQHandler                         ;Ethernet timer interrupt
        DCD     PMIP_IRQHandler                               ;Power management IP (PMIP)
        DCD     PMIP_CHANGE_IRQHandler                        ;PMIP change from 1 to 0
        DCD     ITRC_IRQHandler                               ;Intrusion and tamper response controller (ITRC) interrupt request
        DCD     Reserved136_IRQHandler                        ;Reserved interrupt
        DCD     Reserved137_IRQHandler                        ;Reserved interrupt
        DCD     Reserved138_IRQHandler                        ;Reserved interrupt
        DCD     TRNG_IRQHandler                               ;TRNG interrupt request
        DCD     ACC_C_INT_IRQHandler                          ;AHB memory access checker - Cortex-M33 code bus
        DCD     ACC_S_INT_IRQHandler                          ;AHB memory access checker - Cortex-M33 sys bus
        DCD     WACC_IRQHandler                               ;Wi-Fi accessed during power off
        DCD     BACC_IRQHandler                               ;Bluetooth LE/802.15.4 radio accessed during power off
        DCD     GDMA_IRQHandler                               ;General purpose direct memory access (GDMA) interrupt
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

        PUBWEAK WDT0_IRQHandler
        PUBWEAK WDT0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WDT0_IRQHandler
        LDR     R0, =WDT0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA0_IRQHandler
        PUBWEAK DMA0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA0_IRQHandler
        LDR     R0, =DMA0_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO_INTA_IRQHandler
        PUBWEAK GPIO_INTA_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO_INTA_IRQHandler
        LDR     R0, =GPIO_INTA_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO_INTB_IRQHandler
        PUBWEAK GPIO_INTB_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO_INTB_IRQHandler
        LDR     R0, =GPIO_INTB_DriverIRQHandler
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

        PUBWEAK UTICK_IRQHandler
        PUBWEAK UTICK_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
UTICK_IRQHandler
        LDR     R0, =UTICK_DriverIRQHandler
        BX      R0

        PUBWEAK MRT_IRQHandler
        PUBWEAK MRT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MRT_IRQHandler
        LDR     R0, =MRT_DriverIRQHandler
        BX      R0

        PUBWEAK CTIMER0_IRQHandler
        PUBWEAK CTIMER0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CTIMER0_IRQHandler
        LDR     R0, =CTIMER0_DriverIRQHandler
        BX      R0

        PUBWEAK CTIMER1_IRQHandler
        PUBWEAK CTIMER1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CTIMER1_IRQHandler
        LDR     R0, =CTIMER1_DriverIRQHandler
        BX      R0

        PUBWEAK SCT0_IRQHandler
        PUBWEAK SCT0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SCT0_IRQHandler
        LDR     R0, =SCT0_DriverIRQHandler
        BX      R0

        PUBWEAK CTIMER3_IRQHandler
        PUBWEAK CTIMER3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CTIMER3_IRQHandler
        LDR     R0, =CTIMER3_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXCOMM0_IRQHandler
        PUBWEAK FLEXCOMM0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXCOMM0_IRQHandler
        LDR     R0, =FLEXCOMM0_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXCOMM1_IRQHandler
        PUBWEAK FLEXCOMM1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXCOMM1_IRQHandler
        LDR     R0, =FLEXCOMM1_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXCOMM2_IRQHandler
        PUBWEAK FLEXCOMM2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXCOMM2_IRQHandler
        LDR     R0, =FLEXCOMM2_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXCOMM3_IRQHandler
        PUBWEAK FLEXCOMM3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXCOMM3_IRQHandler
        LDR     R0, =FLEXCOMM3_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved34_IRQHandler
        PUBWEAK Reserved34_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved34_IRQHandler
        LDR     R0, =Reserved34_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved35_IRQHandler
        PUBWEAK Reserved35_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved35_IRQHandler
        LDR     R0, =Reserved35_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXCOMM14_IRQHandler
        PUBWEAK FLEXCOMM14_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXCOMM14_IRQHandler
        LDR     R0, =FLEXCOMM14_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved37_IRQHandler
        PUBWEAK Reserved37_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved37_IRQHandler
        LDR     R0, =Reserved37_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved38_IRQHandler
        PUBWEAK Reserved38_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved38_IRQHandler
        LDR     R0, =Reserved38_DriverIRQHandler
        BX      R0

        PUBWEAK GFMRT_IRQHandler
        PUBWEAK GFMRT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GFMRT_IRQHandler
        LDR     R0, =GFMRT_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved40_IRQHandler
        PUBWEAK Reserved40_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved40_IRQHandler
        LDR     R0, =Reserved40_DriverIRQHandler
        BX      R0

        PUBWEAK DMIC_IRQHandler
        PUBWEAK DMIC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMIC_IRQHandler
        LDR     R0, =DMIC_DriverIRQHandler
        BX      R0

        PUBWEAK WKDEEPSLEEP_IRQHandler
        PUBWEAK WKDEEPSLEEP_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WKDEEPSLEEP_IRQHandler
        LDR     R0, =WKDEEPSLEEP_DriverIRQHandler
        BX      R0

        PUBWEAK HYPERVISOR_IRQHandler
        PUBWEAK HYPERVISOR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
HYPERVISOR_IRQHandler
        LDR     R0, =HYPERVISOR_DriverIRQHandler
        BX      R0

        PUBWEAK SECUREVIOLATION_IRQHandler
        PUBWEAK SECUREVIOLATION_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SECUREVIOLATION_IRQHandler
        LDR     R0, =SECUREVIOLATION_DriverIRQHandler
        BX      R0

        PUBWEAK HWVAD_IRQHandler
        PUBWEAK HWVAD_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
HWVAD_IRQHandler
        LDR     R0, =HWVAD_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved46_IRQHandler
        PUBWEAK Reserved46_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved46_IRQHandler
        LDR     R0, =Reserved46_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved47_IRQHandler
        PUBWEAK Reserved47_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved47_IRQHandler
        LDR     R0, =Reserved47_DriverIRQHandler
        BX      R0

        PUBWEAK RTC_IRQHandler
        PUBWEAK RTC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
RTC_IRQHandler
        LDR     R0, =RTC_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved49_IRQHandler
        PUBWEAK Reserved49_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved49_IRQHandler
        LDR     R0, =Reserved49_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved50_IRQHandler
        PUBWEAK Reserved50_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved50_IRQHandler
        LDR     R0, =Reserved50_DriverIRQHandler
        BX      R0

        PUBWEAK PIN_INT4_IRQHandler
        PUBWEAK PIN_INT4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PIN_INT4_IRQHandler
        LDR     R0, =PIN_INT4_DriverIRQHandler
        BX      R0

        PUBWEAK PIN_INT5_IRQHandler
        PUBWEAK PIN_INT5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PIN_INT5_IRQHandler
        LDR     R0, =PIN_INT5_DriverIRQHandler
        BX      R0

        PUBWEAK PIN_INT6_IRQHandler
        PUBWEAK PIN_INT6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PIN_INT6_IRQHandler
        LDR     R0, =PIN_INT6_DriverIRQHandler
        BX      R0

        PUBWEAK PIN_INT7_IRQHandler
        PUBWEAK PIN_INT7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PIN_INT7_IRQHandler
        LDR     R0, =PIN_INT7_DriverIRQHandler
        BX      R0

        PUBWEAK CTIMER2_IRQHandler
        PUBWEAK CTIMER2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CTIMER2_IRQHandler
        LDR     R0, =CTIMER2_DriverIRQHandler
        BX      R0

        PUBWEAK CTIMER4_IRQHandler
        PUBWEAK CTIMER4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CTIMER4_IRQHandler
        LDR     R0, =CTIMER4_DriverIRQHandler
        BX      R0

        PUBWEAK OS_EVENT_TIMER_IRQHandler
        PUBWEAK OS_EVENT_TIMER_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
OS_EVENT_TIMER_IRQHandler
        LDR     R0, =OS_EVENT_TIMER_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXSPI_IRQHandler
        PUBWEAK FLEXSPI_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXSPI_IRQHandler
        LDR     R0, =FLEXSPI_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved59_IRQHandler
        PUBWEAK Reserved59_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved59_IRQHandler
        LDR     R0, =Reserved59_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved60_IRQHandler
        PUBWEAK Reserved60_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved60_IRQHandler
        LDR     R0, =Reserved60_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved61_IRQHandler
        PUBWEAK Reserved61_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved61_IRQHandler
        LDR     R0, =Reserved61_DriverIRQHandler
        BX      R0

        PUBWEAK SDIO_IRQHandler
        PUBWEAK SDIO_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SDIO_IRQHandler
        LDR     R0, =SDIO_DriverIRQHandler
        BX      R0

        PUBWEAK SGPIO_INTA_IRQHandler
        PUBWEAK SGPIO_INTA_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SGPIO_INTA_IRQHandler
        LDR     R0, =SGPIO_INTA_DriverIRQHandler
        BX      R0

        PUBWEAK SGPIO_INTB_IRQHandler
        PUBWEAK SGPIO_INTB_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SGPIO_INTB_IRQHandler
        LDR     R0, =SGPIO_INTB_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved65_IRQHandler
        PUBWEAK Reserved65_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved65_IRQHandler
        LDR     R0, =Reserved65_DriverIRQHandler
        BX      R0

        PUBWEAK USB_IRQHandler
        PUBWEAK USB_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USB_IRQHandler
        LDR     R0, =USB_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved67_IRQHandler
        PUBWEAK Reserved67_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved67_IRQHandler
        LDR     R0, =Reserved67_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved68_IRQHandler
        PUBWEAK Reserved68_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved68_IRQHandler
        LDR     R0, =Reserved68_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved69_IRQHandler
        PUBWEAK Reserved69_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved69_IRQHandler
        LDR     R0, =Reserved69_DriverIRQHandler
        BX      R0

        PUBWEAK DMA1_IRQHandler
        PUBWEAK DMA1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA1_IRQHandler
        LDR     R0, =DMA1_DriverIRQHandler
        BX      R0

        PUBWEAK PUF_IRQHandler
        PUBWEAK PUF_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PUF_IRQHandler
        LDR     R0, =PUF_DriverIRQHandler
        BX      R0

        PUBWEAK POWERQUAD_IRQHandler
        PUBWEAK POWERQUAD_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
POWERQUAD_IRQHandler
        LDR     R0, =POWERQUAD_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved73_IRQHandler
        PUBWEAK Reserved73_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved73_IRQHandler
        LDR     R0, =Reserved73_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved74_IRQHandler
        PUBWEAK Reserved74_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved74_IRQHandler
        LDR     R0, =Reserved74_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved75_IRQHandler
        PUBWEAK Reserved75_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved75_IRQHandler
        LDR     R0, =Reserved75_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved76_IRQHandler
        PUBWEAK Reserved76_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved76_IRQHandler
        LDR     R0, =Reserved76_DriverIRQHandler
        BX      R0

        PUBWEAK LCD_IRQHandler
        PUBWEAK LCD_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LCD_IRQHandler
        LDR     R0, =LCD_DriverIRQHandler
        BX      R0

        PUBWEAK CAPTIMER_IRQHandler
        PUBWEAK CAPTIMER_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAPTIMER_IRQHandler
        LDR     R0, =CAPTIMER_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved79_IRQHandler
        PUBWEAK Reserved79_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved79_IRQHandler
        LDR     R0, =Reserved79_DriverIRQHandler
        BX      R0

        PUBWEAK W2MWKUP_DONE0_IRQHandler
        PUBWEAK W2MWKUP_DONE0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
W2MWKUP_DONE0_IRQHandler
        LDR     R0, =W2MWKUP_DONE0_DriverIRQHandler
        BX      R0

        PUBWEAK W2MWKUP_DONE1_IRQHandler
        PUBWEAK W2MWKUP_DONE1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
W2MWKUP_DONE1_IRQHandler
        LDR     R0, =W2MWKUP_DONE1_DriverIRQHandler
        BX      R0

        PUBWEAK W2MWKUP_DONE2_IRQHandler
        PUBWEAK W2MWKUP_DONE2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
W2MWKUP_DONE2_IRQHandler
        LDR     R0, =W2MWKUP_DONE2_DriverIRQHandler
        BX      R0

        PUBWEAK W2MWKUP_DONE3_IRQHandler
        PUBWEAK W2MWKUP_DONE3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
W2MWKUP_DONE3_IRQHandler
        LDR     R0, =W2MWKUP_DONE3_DriverIRQHandler
        BX      R0

        PUBWEAK W2MWKUP_DONE4_IRQHandler
        PUBWEAK W2MWKUP_DONE4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
W2MWKUP_DONE4_IRQHandler
        LDR     R0, =W2MWKUP_DONE4_DriverIRQHandler
        BX      R0

        PUBWEAK W2MWKUP_DONE5_IRQHandler
        PUBWEAK W2MWKUP_DONE5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
W2MWKUP_DONE5_IRQHandler
        LDR     R0, =W2MWKUP_DONE5_DriverIRQHandler
        BX      R0

        PUBWEAK W2MWKUP_DONE6_IRQHandler
        PUBWEAK W2MWKUP_DONE6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
W2MWKUP_DONE6_IRQHandler
        LDR     R0, =W2MWKUP_DONE6_DriverIRQHandler
        BX      R0

        PUBWEAK W2MWKUP_DONE7_IRQHandler
        PUBWEAK W2MWKUP_DONE7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
W2MWKUP_DONE7_IRQHandler
        LDR     R0, =W2MWKUP_DONE7_DriverIRQHandler
        BX      R0

        PUBWEAK W2MWKUP0_IRQHandler
        PUBWEAK W2MWKUP0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
W2MWKUP0_IRQHandler
        LDR     R0, =W2MWKUP0_DriverIRQHandler
        BX      R0

        PUBWEAK W2MWKUP1_IRQHandler
        PUBWEAK W2MWKUP1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
W2MWKUP1_IRQHandler
        LDR     R0, =W2MWKUP1_DriverIRQHandler
        BX      R0

        PUBWEAK WL_MCI_INT0_IRQHandler
        PUBWEAK WL_MCI_INT0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WL_MCI_INT0_IRQHandler
        LDR     R0, =WL_MCI_INT0_DriverIRQHandler
        BX      R0

        PUBWEAK WL_MCI_INT1_IRQHandler
        PUBWEAK WL_MCI_INT1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WL_MCI_INT1_IRQHandler
        LDR     R0, =WL_MCI_INT1_DriverIRQHandler
        BX      R0

        PUBWEAK WL_MCI_INT2_IRQHandler
        PUBWEAK WL_MCI_INT2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WL_MCI_INT2_IRQHandler
        LDR     R0, =WL_MCI_INT2_DriverIRQHandler
        BX      R0

        PUBWEAK WL_MCI_INT3_IRQHandler
        PUBWEAK WL_MCI_INT3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WL_MCI_INT3_IRQHandler
        LDR     R0, =WL_MCI_INT3_DriverIRQHandler
        BX      R0

        PUBWEAK WL_MCI_INT4_IRQHandler
        PUBWEAK WL_MCI_INT4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WL_MCI_INT4_IRQHandler
        LDR     R0, =WL_MCI_INT4_DriverIRQHandler
        BX      R0

        PUBWEAK WL_MCI_INT5_IRQHandler
        PUBWEAK WL_MCI_INT5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WL_MCI_INT5_IRQHandler
        LDR     R0, =WL_MCI_INT5_DriverIRQHandler
        BX      R0

        PUBWEAK WL_MCI_INT6_IRQHandler
        PUBWEAK WL_MCI_INT6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WL_MCI_INT6_IRQHandler
        LDR     R0, =WL_MCI_INT6_DriverIRQHandler
        BX      R0

        PUBWEAK WL_MCI_INT7_IRQHandler
        PUBWEAK WL_MCI_INT7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WL_MCI_INT7_IRQHandler
        LDR     R0, =WL_MCI_INT7_DriverIRQHandler
        BX      R0

        PUBWEAK B2MWKUP_DONE0_IRQHandler
        PUBWEAK B2MWKUP_DONE0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
B2MWKUP_DONE0_IRQHandler
        LDR     R0, =B2MWKUP_DONE0_DriverIRQHandler
        BX      R0

        PUBWEAK B2MWKUP_DONE1_IRQHandler
        PUBWEAK B2MWKUP_DONE1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
B2MWKUP_DONE1_IRQHandler
        LDR     R0, =B2MWKUP_DONE1_DriverIRQHandler
        BX      R0

        PUBWEAK B2MWKUP_DONE2_IRQHandler
        PUBWEAK B2MWKUP_DONE2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
B2MWKUP_DONE2_IRQHandler
        LDR     R0, =B2MWKUP_DONE2_DriverIRQHandler
        BX      R0

        PUBWEAK B2MWKUP_DONE3_IRQHandler
        PUBWEAK B2MWKUP_DONE3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
B2MWKUP_DONE3_IRQHandler
        LDR     R0, =B2MWKUP_DONE3_DriverIRQHandler
        BX      R0

        PUBWEAK B2MWKUP_DONE4_IRQHandler
        PUBWEAK B2MWKUP_DONE4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
B2MWKUP_DONE4_IRQHandler
        LDR     R0, =B2MWKUP_DONE4_DriverIRQHandler
        BX      R0

        PUBWEAK B2MWKUP_DONE5_IRQHandler
        PUBWEAK B2MWKUP_DONE5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
B2MWKUP_DONE5_IRQHandler
        LDR     R0, =B2MWKUP_DONE5_DriverIRQHandler
        BX      R0

        PUBWEAK B2MWKUP_DONE6_IRQHandler
        PUBWEAK B2MWKUP_DONE6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
B2MWKUP_DONE6_IRQHandler
        LDR     R0, =B2MWKUP_DONE6_DriverIRQHandler
        BX      R0

        PUBWEAK B2MWKUP_DONE7_IRQHandler
        PUBWEAK B2MWKUP_DONE7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
B2MWKUP_DONE7_IRQHandler
        LDR     R0, =B2MWKUP_DONE7_DriverIRQHandler
        BX      R0

        PUBWEAK B2MWKUP0_IRQHandler
        PUBWEAK B2MWKUP0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
B2MWKUP0_IRQHandler
        LDR     R0, =B2MWKUP0_DriverIRQHandler
        BX      R0

        PUBWEAK B2MWKUP1_IRQHandler
        PUBWEAK B2MWKUP1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
B2MWKUP1_IRQHandler
        LDR     R0, =B2MWKUP1_DriverIRQHandler
        BX      R0

        PUBWEAK BLE_MCI_INT0_IRQHandler
        PUBWEAK BLE_MCI_INT0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
BLE_MCI_INT0_IRQHandler
        LDR     R0, =BLE_MCI_INT0_DriverIRQHandler
        BX      R0

        PUBWEAK BLE_MCI_INT1_IRQHandler
        PUBWEAK BLE_MCI_INT1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
BLE_MCI_INT1_IRQHandler
        LDR     R0, =BLE_MCI_INT1_DriverIRQHandler
        BX      R0

        PUBWEAK BLE_MCI_INT2_IRQHandler
        PUBWEAK BLE_MCI_INT2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
BLE_MCI_INT2_IRQHandler
        LDR     R0, =BLE_MCI_INT2_DriverIRQHandler
        BX      R0

        PUBWEAK BLE_MCI_INT3_IRQHandler
        PUBWEAK BLE_MCI_INT3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
BLE_MCI_INT3_IRQHandler
        LDR     R0, =BLE_MCI_INT3_DriverIRQHandler
        BX      R0

        PUBWEAK BLE_MCI_INT4_IRQHandler
        PUBWEAK BLE_MCI_INT4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
BLE_MCI_INT4_IRQHandler
        LDR     R0, =BLE_MCI_INT4_DriverIRQHandler
        BX      R0

        PUBWEAK BLE_MCI_INT5_IRQHandler
        PUBWEAK BLE_MCI_INT5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
BLE_MCI_INT5_IRQHandler
        LDR     R0, =BLE_MCI_INT5_DriverIRQHandler
        BX      R0

        PUBWEAK BLE_MCI_INT6_IRQHandler
        PUBWEAK BLE_MCI_INT6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
BLE_MCI_INT6_IRQHandler
        LDR     R0, =BLE_MCI_INT6_DriverIRQHandler
        BX      R0

        PUBWEAK BLE_MCI_INT7_IRQHandler
        PUBWEAK BLE_MCI_INT7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
BLE_MCI_INT7_IRQHandler
        LDR     R0, =BLE_MCI_INT7_DriverIRQHandler
        BX      R0

        PUBWEAK PIN0_INT_IRQHandler
        PUBWEAK PIN0_INT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PIN0_INT_IRQHandler
        LDR     R0, =PIN0_INT_DriverIRQHandler
        BX      R0

        PUBWEAK PIN1_INT_IRQHandler
        PUBWEAK PIN1_INT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PIN1_INT_IRQHandler
        LDR     R0, =PIN1_INT_DriverIRQHandler
        BX      R0

        PUBWEAK ELS_IRQHandler
        PUBWEAK ELS_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ELS_IRQHandler
        LDR     R0, =ELS_DriverIRQHandler
        BX      R0

        PUBWEAK ELS_GDET_IRQHandler
        PUBWEAK ELS_GDET_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ELS_GDET_IRQHandler
        LDR     R0, =ELS_GDET_DriverIRQHandler
        BX      R0

        PUBWEAK ELS_GDET_UM_IRQHandler
        PUBWEAK ELS_GDET_UM_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ELS_GDET_UM_IRQHandler
        LDR     R0, =ELS_GDET_UM_DriverIRQHandler
        BX      R0

        PUBWEAK PKC_INT_IRQHandler
        PUBWEAK PKC_INT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PKC_INT_IRQHandler
        LDR     R0, =PKC_INT_DriverIRQHandler
        BX      R0

        PUBWEAK PKC_ERR_IRQHandler
        PUBWEAK PKC_ERR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PKC_ERR_IRQHandler
        LDR     R0, =PKC_ERR_DriverIRQHandler
        BX      R0

        PUBWEAK CDOG_INT_IRQHandler
        PUBWEAK CDOG_INT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CDOG_INT_IRQHandler
        LDR     R0, =CDOG_INT_DriverIRQHandler
        BX      R0

        PUBWEAK GAU_DAC_IRQHandler
        PUBWEAK GAU_DAC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GAU_DAC_IRQHandler
        LDR     R0, =GAU_DAC_DriverIRQHandler
        BX      R0

        PUBWEAK GAU_ACOMP_WKUP_IRQHandler
        PUBWEAK GAU_ACOMP_WKUP_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GAU_ACOMP_WKUP_IRQHandler
        LDR     R0, =GAU_ACOMP_WKUP_DriverIRQHandler
        BX      R0

        PUBWEAK GAU_ACOMP_IRQHandler
        PUBWEAK GAU_ACOMP_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GAU_ACOMP_IRQHandler
        LDR     R0, =GAU_ACOMP_DriverIRQHandler
        BX      R0

        PUBWEAK GAU_ADC1_IRQHandler
        PUBWEAK GAU_ADC1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GAU_ADC1_IRQHandler
        LDR     R0, =GAU_ADC1_DriverIRQHandler
        BX      R0

        PUBWEAK GAU_ADC0_IRQHandler
        PUBWEAK GAU_ADC0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GAU_ADC0_IRQHandler
        LDR     R0, =GAU_ADC0_DriverIRQHandler
        BX      R0

        PUBWEAK USIM_IRQHandler
        PUBWEAK USIM_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USIM_IRQHandler
        LDR     R0, =USIM_DriverIRQHandler
        BX      R0

        PUBWEAK OTP_IRQHandler
        PUBWEAK OTP_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
OTP_IRQHandler
        LDR     R0, =OTP_DriverIRQHandler
        BX      R0

        PUBWEAK ENET_IRQHandler
        PUBWEAK ENET_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ENET_IRQHandler
        LDR     R0, =ENET_DriverIRQHandler
        BX      R0

        PUBWEAK ENET_TIMER_IRQHandler
        PUBWEAK ENET_TIMER_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ENET_TIMER_IRQHandler
        LDR     R0, =ENET_TIMER_DriverIRQHandler
        BX      R0

        PUBWEAK PMIP_IRQHandler
        PUBWEAK PMIP_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PMIP_IRQHandler
        LDR     R0, =PMIP_DriverIRQHandler
        BX      R0

        PUBWEAK PMIP_CHANGE_IRQHandler
        PUBWEAK PMIP_CHANGE_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PMIP_CHANGE_IRQHandler
        LDR     R0, =PMIP_CHANGE_DriverIRQHandler
        BX      R0

        PUBWEAK ITRC_IRQHandler
        PUBWEAK ITRC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ITRC_IRQHandler
        LDR     R0, =ITRC_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved136_IRQHandler
        PUBWEAK Reserved136_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved136_IRQHandler
        LDR     R0, =Reserved136_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved137_IRQHandler
        PUBWEAK Reserved137_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved137_IRQHandler
        LDR     R0, =Reserved137_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved138_IRQHandler
        PUBWEAK Reserved138_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved138_IRQHandler
        LDR     R0, =Reserved138_DriverIRQHandler
        BX      R0

        PUBWEAK TRNG_IRQHandler
        PUBWEAK TRNG_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
TRNG_IRQHandler
        LDR     R0, =TRNG_DriverIRQHandler
        BX      R0

        PUBWEAK ACC_C_INT_IRQHandler
        PUBWEAK ACC_C_INT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ACC_C_INT_IRQHandler
        LDR     R0, =ACC_C_INT_DriverIRQHandler
        BX      R0

        PUBWEAK ACC_S_INT_IRQHandler
        PUBWEAK ACC_S_INT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ACC_S_INT_IRQHandler
        LDR     R0, =ACC_S_INT_DriverIRQHandler
        BX      R0

        PUBWEAK WACC_IRQHandler
        PUBWEAK WACC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WACC_IRQHandler
        LDR     R0, =WACC_DriverIRQHandler
        BX      R0

        PUBWEAK BACC_IRQHandler
        PUBWEAK BACC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
BACC_IRQHandler
        LDR     R0, =BACC_DriverIRQHandler
        BX      R0

        PUBWEAK GDMA_IRQHandler
        PUBWEAK GDMA_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GDMA_IRQHandler
        LDR     R0, =GDMA_DriverIRQHandler
        BX      R0

WDT0_DriverIRQHandler
DMA0_DriverIRQHandler
GPIO_INTA_DriverIRQHandler
GPIO_INTB_DriverIRQHandler
PIN_INT0_DriverIRQHandler
PIN_INT1_DriverIRQHandler
PIN_INT2_DriverIRQHandler
PIN_INT3_DriverIRQHandler
UTICK_DriverIRQHandler
MRT_DriverIRQHandler
CTIMER0_DriverIRQHandler
CTIMER1_DriverIRQHandler
SCT0_DriverIRQHandler
CTIMER3_DriverIRQHandler
FLEXCOMM0_DriverIRQHandler
FLEXCOMM1_DriverIRQHandler
FLEXCOMM2_DriverIRQHandler
FLEXCOMM3_DriverIRQHandler
Reserved34_DriverIRQHandler
Reserved35_DriverIRQHandler
FLEXCOMM14_DriverIRQHandler
Reserved37_DriverIRQHandler
Reserved38_DriverIRQHandler
GFMRT_DriverIRQHandler
Reserved40_DriverIRQHandler
DMIC_DriverIRQHandler
WKDEEPSLEEP_DriverIRQHandler
HYPERVISOR_DriverIRQHandler
SECUREVIOLATION_DriverIRQHandler
HWVAD_DriverIRQHandler
Reserved46_DriverIRQHandler
Reserved47_DriverIRQHandler
RTC_DriverIRQHandler
Reserved49_DriverIRQHandler
Reserved50_DriverIRQHandler
PIN_INT4_DriverIRQHandler
PIN_INT5_DriverIRQHandler
PIN_INT6_DriverIRQHandler
PIN_INT7_DriverIRQHandler
CTIMER2_DriverIRQHandler
CTIMER4_DriverIRQHandler
OS_EVENT_TIMER_DriverIRQHandler
FLEXSPI_DriverIRQHandler
Reserved59_DriverIRQHandler
Reserved60_DriverIRQHandler
Reserved61_DriverIRQHandler
SDIO_DriverIRQHandler
SGPIO_INTA_DriverIRQHandler
SGPIO_INTB_DriverIRQHandler
Reserved65_DriverIRQHandler
USB_DriverIRQHandler
Reserved67_DriverIRQHandler
Reserved68_DriverIRQHandler
Reserved69_DriverIRQHandler
DMA1_DriverIRQHandler
PUF_DriverIRQHandler
POWERQUAD_DriverIRQHandler
Reserved73_DriverIRQHandler
Reserved74_DriverIRQHandler
Reserved75_DriverIRQHandler
Reserved76_DriverIRQHandler
LCD_DriverIRQHandler
CAPTIMER_DriverIRQHandler
Reserved79_DriverIRQHandler
W2MWKUP_DONE0_DriverIRQHandler
W2MWKUP_DONE1_DriverIRQHandler
W2MWKUP_DONE2_DriverIRQHandler
W2MWKUP_DONE3_DriverIRQHandler
W2MWKUP_DONE4_DriverIRQHandler
W2MWKUP_DONE5_DriverIRQHandler
W2MWKUP_DONE6_DriverIRQHandler
W2MWKUP_DONE7_DriverIRQHandler
W2MWKUP0_DriverIRQHandler
W2MWKUP1_DriverIRQHandler
WL_MCI_INT0_DriverIRQHandler
WL_MCI_INT1_DriverIRQHandler
WL_MCI_INT2_DriverIRQHandler
WL_MCI_INT3_DriverIRQHandler
WL_MCI_INT4_DriverIRQHandler
WL_MCI_INT5_DriverIRQHandler
WL_MCI_INT6_DriverIRQHandler
WL_MCI_INT7_DriverIRQHandler
B2MWKUP_DONE0_DriverIRQHandler
B2MWKUP_DONE1_DriverIRQHandler
B2MWKUP_DONE2_DriverIRQHandler
B2MWKUP_DONE3_DriverIRQHandler
B2MWKUP_DONE4_DriverIRQHandler
B2MWKUP_DONE5_DriverIRQHandler
B2MWKUP_DONE6_DriverIRQHandler
B2MWKUP_DONE7_DriverIRQHandler
B2MWKUP0_DriverIRQHandler
B2MWKUP1_DriverIRQHandler
BLE_MCI_INT0_DriverIRQHandler
BLE_MCI_INT1_DriverIRQHandler
BLE_MCI_INT2_DriverIRQHandler
BLE_MCI_INT3_DriverIRQHandler
BLE_MCI_INT4_DriverIRQHandler
BLE_MCI_INT5_DriverIRQHandler
BLE_MCI_INT6_DriverIRQHandler
BLE_MCI_INT7_DriverIRQHandler
PIN0_INT_DriverIRQHandler
PIN1_INT_DriverIRQHandler
ELS_DriverIRQHandler
ELS_GDET_DriverIRQHandler
ELS_GDET_UM_DriverIRQHandler
PKC_INT_DriverIRQHandler
PKC_ERR_DriverIRQHandler
CDOG_INT_DriverIRQHandler
GAU_DAC_DriverIRQHandler
GAU_ACOMP_WKUP_DriverIRQHandler
GAU_ACOMP_DriverIRQHandler
GAU_ADC1_DriverIRQHandler
GAU_ADC0_DriverIRQHandler
USIM_DriverIRQHandler
OTP_DriverIRQHandler
ENET_DriverIRQHandler
ENET_TIMER_DriverIRQHandler
PMIP_DriverIRQHandler
PMIP_CHANGE_DriverIRQHandler
ITRC_DriverIRQHandler
Reserved136_DriverIRQHandler
Reserved137_DriverIRQHandler
Reserved138_DriverIRQHandler
TRNG_DriverIRQHandler
ACC_C_INT_DriverIRQHandler
ACC_S_INT_DriverIRQHandler
WACC_DriverIRQHandler
BACC_DriverIRQHandler
GDMA_DriverIRQHandler
DefaultISR
        B .

        END
