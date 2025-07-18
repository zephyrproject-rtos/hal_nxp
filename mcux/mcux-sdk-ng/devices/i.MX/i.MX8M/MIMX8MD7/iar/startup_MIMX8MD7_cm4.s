; -------------------------------------------------------------------------
;  @file:    startup_MIMX8MD7_cm4.s
;  @purpose: CMSIS Cortex-M4 Core Device Startup File
;            MIMX8MD7_cm4
;  @version: 5.0
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
        DCD     GPR_IRQ_IRQHandler                            ;GPR Interrupt. Used to notify cores on exception condition while boot.
        DCD     DAP_IRQHandler                                ;DAP Interrupt
        DCD     SDMA1_IRQHandler                              ;AND of all 48 SDMA interrupts (events) from all the channels
        DCD     GPU_IRQHandler                                ;GPU Interrupt
        DCD     SNVS_IRQHandler                               ;ON-OFF button press shorter than 5 seconds (pulse event)
        DCD     LCDIF_IRQHandler                              ;LCDIF Sync Interrupt
        DCD     SPDIF1_IRQHandler                             ;SPDIF1 Interrupt
        DCD     H264_IRQHandler                               ;h264 Decoder Interrupt
        DCD     VPUDMA_IRQHandler                             ;VPU DMA Interrupt
        DCD     QOS_IRQHandler                                ;QOS interrupt
        DCD     WDOG3_IRQHandler                              ;Watchdog Timer reset
        DCD     HS_CP1_IRQHandler                             ;HS Interrupt Request
        DCD     APBHDMA_IRQHandler                            ;GPMI operation channel 0-3 description complete interrupt
        DCD     SPDIF2_IRQHandler                             ;SPDIF2 Interrupt
        DCD     BCH_IRQHandler                                ;BCH operation complete interrupt
        DCD     GPMI_IRQHandler                               ;GPMI operation TIMEOUT ERROR interrupt
        DCD     HDMI_IRQ0_IRQHandler                          ;HDMI Interrupt 0
        DCD     HDMI_IRQ1_IRQHandler                          ;HDMI Interrupt 1
        DCD     HDMI_IRQ2_IRQHandler                          ;HDMI Interrupt 2
        DCD     SNVS_Consolidated_IRQHandler                  ;SRTC Consolidated Interrupt. Non TZ.
        DCD     SNVS_Security_IRQHandler                      ;SRTC Security Interrupt. TZ.
        DCD     CSU_IRQHandler                                ;CSU Interrupt Request. Indicates to the processor that one or more alarm inputs were asserted.
        DCD     USDHC1_IRQHandler                             ;uSDHC1 Enhanced SDHC Interrupt Request
        DCD     USDHC2_IRQHandler                             ;uSDHC2 Enhanced SDHC Interrupt Request
        DCD     DDC_IRQHandler                                ;DC8000 Display Controller IRQ
        DCD     DTRC_IRQHandler                               ;DTRC interrupt
        DCD     UART1_IRQHandler                              ;UART-1 ORed interrupt
        DCD     UART2_IRQHandler                              ;UART-2 ORed interrupt
        DCD     UART3_IRQHandler                              ;UART-3 ORed interrupt
        DCD     UART4_IRQHandler                              ;UART-4 ORed interrupt
        DCD     VP9_IRQHandler                                ;VP9 Decoder interrupt
        DCD     ECSPI1_IRQHandler                             ;ECSPI1 interrupt request line to the core.
        DCD     ECSPI2_IRQHandler                             ;ECSPI2 interrupt request line to the core.
        DCD     ECSPI3_IRQHandler                             ;ECSPI3 interrupt request line to the core.
        DCD     MIPI_DSI_IRQHandler                           ;DSI Interrupt
        DCD     I2C1_IRQHandler                               ;I2C-1 Interrupt
        DCD     I2C2_IRQHandler                               ;I2C-2 Interrupt
        DCD     I2C3_IRQHandler                               ;I2C-3 Interrupt
        DCD     I2C4_IRQHandler                               ;I2C-4 Interrupt
        DCD     RDC_IRQHandler                                ;RDC interrupt
        DCD     USB1_IRQHandler                               ;USB1 Interrupt
        DCD     USB2_IRQHandler                               ;USB1 Interrupt
        DCD     CSI1_IRQHandler                               ;CSI1 interrupt
        DCD     CSI2_IRQHandler                               ;CSI2 interrupt
        DCD     MIPI_CSI1_IRQHandler                          ;MIPI-CSI-1 Interrupt
        DCD     MIPI_CSI2_IRQHandler                          ;MIPI-CSI-2 Interrupt
        DCD     GPT6_IRQHandler                               ;OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines
        DCD     SCTR_IRQ0_IRQHandler                          ;ISO7816IP Interrupt 0
        DCD     SCTR_IRQ1_IRQHandler                          ;ISO7816IP Interrupt 1
        DCD     TEMPMON_IRQHandler                            ;TempSensor (Temperature alarm).
        DCD     I2S3_IRQHandler                               ;SAI3 Receive / Transmit Interrupt
        DCD     GPT5_IRQHandler                               ;OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines
        DCD     GPT4_IRQHandler                               ;OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines
        DCD     GPT3_IRQHandler                               ;OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines
        DCD     GPT2_IRQHandler                               ;OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines
        DCD     GPT1_IRQHandler                               ;OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines
        DCD     GPIO1_INT7_IRQHandler                         ;Active HIGH Interrupt from INT7 from GPIO
        DCD     GPIO1_INT6_IRQHandler                         ;Active HIGH Interrupt from INT6 from GPIO
        DCD     GPIO1_INT5_IRQHandler                         ;Active HIGH Interrupt from INT5 from GPIO
        DCD     GPIO1_INT4_IRQHandler                         ;Active HIGH Interrupt from INT4 from GPIO
        DCD     GPIO1_INT3_IRQHandler                         ;Active HIGH Interrupt from INT3 from GPIO
        DCD     GPIO1_INT2_IRQHandler                         ;Active HIGH Interrupt from INT2 from GPIO
        DCD     GPIO1_INT1_IRQHandler                         ;Active HIGH Interrupt from INT1 from GPIO
        DCD     GPIO1_INT0_IRQHandler                         ;Active HIGH Interrupt from INT0 from GPIO
        DCD     GPIO1_Combined_0_15_IRQHandler                ;Combined interrupt indication for GPIO1 signal 0 throughout 15
        DCD     GPIO1_Combined_16_31_IRQHandler               ;Combined interrupt indication for GPIO1 signal 16 throughout 31
        DCD     GPIO2_Combined_0_15_IRQHandler                ;Combined interrupt indication for GPIO2 signal 0 throughout 15
        DCD     GPIO2_Combined_16_31_IRQHandler               ;Combined interrupt indication for GPIO2 signal 16 throughout 31
        DCD     GPIO3_Combined_0_15_IRQHandler                ;Combined interrupt indication for GPIO3 signal 0 throughout 15
        DCD     GPIO3_Combined_16_31_IRQHandler               ;Combined interrupt indication for GPIO3 signal 16 throughout 31
        DCD     GPIO4_Combined_0_15_IRQHandler                ;Combined interrupt indication for GPIO4 signal 0 throughout 15
        DCD     GPIO4_Combined_16_31_IRQHandler               ;Combined interrupt indication for GPIO4 signal 16 throughout 31
        DCD     GPIO5_Combined_0_15_IRQHandler                ;Combined interrupt indication for GPIO5 signal 0 throughout 15
        DCD     GPIO5_Combined_16_31_IRQHandler               ;Combined interrupt indication for GPIO5 signal 16 throughout 31
        DCD     PCIE_CTRL2_IRQ0_IRQHandler                    ;Coming from GLUE logic, of set / reset FF, driven by PCIE signals.
        DCD     PCIE_CTRL2_IRQ1_IRQHandler                    ;Coming from GLUE logic, of set / reset FF, driven by PCIE signals.
        DCD     PCIE_CTRL2_IRQ2_IRQHandler                    ;Coming from GLUE logic, of set / reset FF, driven by PCIE signals.
        DCD     PCIE_CTRL2_IRQ3_IRQHandler                    ;Coming from GLUE logic, of set / reset FF, driven by PCIE signals.
        DCD     WDOG1_IRQHandler                              ;Watchdog Timer reset
        DCD     WDOG2_IRQHandler                              ;Watchdog Timer reset
        DCD     PCIE_CTRL2_IRQHandler                         ;Channels [63:32] interrupts requests
        DCD     PWM1_IRQHandler                               ;Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line.
        DCD     PWM2_IRQHandler                               ;Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line.
        DCD     PWM3_IRQHandler                               ;Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line.
        DCD     PWM4_IRQHandler                               ;Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line.
        DCD     CCM_IRQ1_IRQHandler                           ;CCM, Interrupt Request 1
        DCD     CCM_IRQ2_IRQHandler                           ;CCM, Interrupt Request 2
        DCD     GPC_IRQHandler                                ;GPC Interrupt Request 1
        DCD     MU_A53_IRQHandler                             ;Interrupt to A53
        DCD     SRC_IRQHandler                                ;SRC interrupt request
        DCD     I2S56_IRQHandler                              ;SAI5/6 Receive / Transmit Interrupt
        DCD     RTIC_IRQHandler                               ;RTIC Interrupt
        DCD     CPU_PerformanceUnit_IRQHandler                ;Performance Unit Interrupts from Cheetah (interrnally: PMUIRQ[n]
        DCD     CPU_CTI_Trigger_IRQHandler                    ;CTI trigger outputs (internal: nCTIIRQ[n]
        DCD     SRC_Combined_IRQHandler                       ;Combined CPU wdog interrupts (4x) out of SRC.
        DCD     I2S1_IRQHandler                               ;SAI1 Receive / Transmit Interrupt
        DCD     I2S2_IRQHandler                               ;SAI2 Receive / Transmit Interrupt
        DCD     MU_M4_IRQHandler                              ;Interrupt to M4
        DCD     DDR_PerformanceMonitor_IRQHandler             ;ddr Interrupt for performance monitor
        DCD     DDR_IRQHandler                                ;ddr Interrupt
        DCD     I2S4_IRQHandler                               ;SAI4 Receive / Transmit Interrupt
        DCD     CPU_Error_AXI_IRQHandler                      ;CPU Error indicator for AXI transaction with a write response error condition
        DCD     CPU_Error_L2RAM_IRQHandler                    ;CPU Error indicator for L2 RAM double-bit ECC error
        DCD     SDMA2_IRQHandler                              ;AND of all 48 SDMA interrupts (events) from all the channels
        DCD     Reserved120_IRQHandler                        ;Reserved
        DCD     CAAM_IRQ0_IRQHandler                          ;CAAM interrupt queue for JQ
        DCD     CAAM_IRQ1_IRQHandler                          ;CAAM interrupt queue for JQ
        DCD     QSPI_IRQHandler                               ;QSPI Interrupt
        DCD     TZASC_IRQHandler                              ;TZASC (PL380) interrupt
        DCD     Reserved125_IRQHandler                        ;Reserved
        DCD     Reserved126_IRQHandler                        ;Reserved
        DCD     Reserved127_IRQHandler                        ;Reserved
        DCD     PERFMON1_IRQHandler                           ;General Interrupt
        DCD     PERFMON2_IRQHandler                           ;General Interrupt
        DCD     CAAM_IRQ2_IRQHandler                          ;CAAM interrupt queue for JQ
        DCD     CAAM_ERROR_IRQHandler                         ;Recoverable error interrupt
        DCD     HS_CP0_IRQHandler                             ;HS Interrupt Request
        DCD     HEVC_IRQHandler                               ;HEVC interrupt
        DCD     ENET1_MAC0_Rx_Tx_Done1_IRQHandler             ;MAC 0 Receive / Trasmit Frame / Buffer Done
        DCD     ENET1_MAC0_Rx_Tx_Done2_IRQHandler             ;MAC 0 Receive / Trasmit Frame / Buffer Done
        DCD     ENET1_IRQHandler                              ;MAC 0 IRQ
        DCD     ENET1_1588_Timer_IRQHandler                   ;MAC 0 1588 Timer Interrupt - synchronous
        DCD     PCIE_CTRL1_IRQ0_IRQHandler                    ;Coming from GLUE logic, of set / reset FF, driven by PCIE signals.
        DCD     PCIE_CTRL1_IRQ1_IRQHandler                    ;Coming from GLUE logic, of set / reset FF, driven by PCIE signals.
        DCD     PCIE_CTRL1_IRQ2_IRQHandler                    ;Coming from GLUE logic, of set / reset FF, driven by PCIE signals.
        DCD     PCIE_CTRL1_IRQ3_IRQHandler                    ;Coming from GLUE logic, of set / reset FF, driven by PCIE signals.
        DCD     Reserved142_IRQHandler                        ;Reserved
        DCD     PCIE_CTRL1_IRQHandler                         ;Channels [63:32] interrupts requests
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

        PUBWEAK GPR_IRQ_IRQHandler
        PUBWEAK DAP_IRQHandler
        PUBWEAK SDMA1_IRQHandler
        PUBWEAK SDMA1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SDMA1_IRQHandler
        LDR     R0, =SDMA1_DriverIRQHandler
        BX      R0

        PUBWEAK GPU_IRQHandler
        PUBWEAK SNVS_IRQHandler
        PUBWEAK LCDIF_IRQHandler
        PUBWEAK SPDIF1_IRQHandler
        PUBWEAK SPDIF1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SPDIF1_IRQHandler
        LDR     R0, =SPDIF1_DriverIRQHandler
        BX      R0

        PUBWEAK H264_IRQHandler
        PUBWEAK VPUDMA_IRQHandler
        PUBWEAK VPUDMA_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
VPUDMA_IRQHandler
        LDR     R0, =VPUDMA_DriverIRQHandler
        BX      R0

        PUBWEAK QOS_IRQHandler
        PUBWEAK WDOG3_IRQHandler
        PUBWEAK HS_CP1_IRQHandler
        PUBWEAK APBHDMA_IRQHandler
        PUBWEAK APBHDMA_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
APBHDMA_IRQHandler
        LDR     R0, =APBHDMA_DriverIRQHandler
        BX      R0

        PUBWEAK SPDIF2_IRQHandler
        PUBWEAK SPDIF2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SPDIF2_IRQHandler
        LDR     R0, =SPDIF2_DriverIRQHandler
        BX      R0

        PUBWEAK BCH_IRQHandler
        PUBWEAK GPMI_IRQHandler
        PUBWEAK HDMI_IRQ0_IRQHandler
        PUBWEAK HDMI_IRQ1_IRQHandler
        PUBWEAK HDMI_IRQ2_IRQHandler
        PUBWEAK SNVS_Consolidated_IRQHandler
        PUBWEAK SNVS_Security_IRQHandler
        PUBWEAK CSU_IRQHandler
        PUBWEAK USDHC1_IRQHandler
        PUBWEAK USDHC1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USDHC1_IRQHandler
        LDR     R0, =USDHC1_DriverIRQHandler
        BX      R0

        PUBWEAK USDHC2_IRQHandler
        PUBWEAK USDHC2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USDHC2_IRQHandler
        LDR     R0, =USDHC2_DriverIRQHandler
        BX      R0

        PUBWEAK DDC_IRQHandler
        PUBWEAK DTRC_IRQHandler
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

        PUBWEAK UART3_IRQHandler
        PUBWEAK UART3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
UART3_IRQHandler
        LDR     R0, =UART3_DriverIRQHandler
        BX      R0

        PUBWEAK UART4_IRQHandler
        PUBWEAK UART4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
UART4_IRQHandler
        LDR     R0, =UART4_DriverIRQHandler
        BX      R0

        PUBWEAK VP9_IRQHandler
        PUBWEAK ECSPI1_IRQHandler
        PUBWEAK ECSPI1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ECSPI1_IRQHandler
        LDR     R0, =ECSPI1_DriverIRQHandler
        BX      R0

        PUBWEAK ECSPI2_IRQHandler
        PUBWEAK ECSPI2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ECSPI2_IRQHandler
        LDR     R0, =ECSPI2_DriverIRQHandler
        BX      R0

        PUBWEAK ECSPI3_IRQHandler
        PUBWEAK ECSPI3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ECSPI3_IRQHandler
        LDR     R0, =ECSPI3_DriverIRQHandler
        BX      R0

        PUBWEAK MIPI_DSI_IRQHandler
        PUBWEAK I2C1_IRQHandler
        PUBWEAK I2C1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2C1_IRQHandler
        LDR     R0, =I2C1_DriverIRQHandler
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

        PUBWEAK I2C4_IRQHandler
        PUBWEAK I2C4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2C4_IRQHandler
        LDR     R0, =I2C4_DriverIRQHandler
        BX      R0

        PUBWEAK RDC_IRQHandler
        PUBWEAK USB1_IRQHandler
        PUBWEAK USB2_IRQHandler
        PUBWEAK CSI1_IRQHandler
        PUBWEAK CSI2_IRQHandler
        PUBWEAK MIPI_CSI1_IRQHandler
        PUBWEAK MIPI_CSI2_IRQHandler
        PUBWEAK GPT6_IRQHandler
        PUBWEAK SCTR_IRQ0_IRQHandler
        PUBWEAK SCTR_IRQ1_IRQHandler
        PUBWEAK TEMPMON_IRQHandler
        PUBWEAK I2S3_IRQHandler
        PUBWEAK I2S3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2S3_IRQHandler
        LDR     R0, =I2S3_DriverIRQHandler
        BX      R0

        PUBWEAK GPT5_IRQHandler
        PUBWEAK GPT4_IRQHandler
        PUBWEAK GPT3_IRQHandler
        PUBWEAK GPT2_IRQHandler
        PUBWEAK GPT1_IRQHandler
        PUBWEAK GPIO1_INT7_IRQHandler
        PUBWEAK GPIO1_INT6_IRQHandler
        PUBWEAK GPIO1_INT5_IRQHandler
        PUBWEAK GPIO1_INT4_IRQHandler
        PUBWEAK GPIO1_INT3_IRQHandler
        PUBWEAK GPIO1_INT2_IRQHandler
        PUBWEAK GPIO1_INT1_IRQHandler
        PUBWEAK GPIO1_INT0_IRQHandler
        PUBWEAK GPIO1_Combined_0_15_IRQHandler
        PUBWEAK GPIO1_Combined_16_31_IRQHandler
        PUBWEAK GPIO2_Combined_0_15_IRQHandler
        PUBWEAK GPIO2_Combined_16_31_IRQHandler
        PUBWEAK GPIO3_Combined_0_15_IRQHandler
        PUBWEAK GPIO3_Combined_16_31_IRQHandler
        PUBWEAK GPIO4_Combined_0_15_IRQHandler
        PUBWEAK GPIO4_Combined_16_31_IRQHandler
        PUBWEAK GPIO5_Combined_0_15_IRQHandler
        PUBWEAK GPIO5_Combined_16_31_IRQHandler
        PUBWEAK PCIE_CTRL2_IRQ0_IRQHandler
        PUBWEAK PCIE_CTRL2_IRQ1_IRQHandler
        PUBWEAK PCIE_CTRL2_IRQ2_IRQHandler
        PUBWEAK PCIE_CTRL2_IRQ3_IRQHandler
        PUBWEAK WDOG1_IRQHandler
        PUBWEAK WDOG2_IRQHandler
        PUBWEAK PCIE_CTRL2_IRQHandler
        PUBWEAK PWM1_IRQHandler
        PUBWEAK PWM2_IRQHandler
        PUBWEAK PWM3_IRQHandler
        PUBWEAK PWM4_IRQHandler
        PUBWEAK CCM_IRQ1_IRQHandler
        PUBWEAK CCM_IRQ2_IRQHandler
        PUBWEAK GPC_IRQHandler
        PUBWEAK MU_A53_IRQHandler
        PUBWEAK SRC_IRQHandler
        PUBWEAK I2S56_IRQHandler
        PUBWEAK I2S56_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2S56_IRQHandler
        LDR     R0, =I2S56_DriverIRQHandler
        BX      R0

        PUBWEAK RTIC_IRQHandler
        PUBWEAK CPU_PerformanceUnit_IRQHandler
        PUBWEAK CPU_CTI_Trigger_IRQHandler
        PUBWEAK SRC_Combined_IRQHandler
        PUBWEAK I2S1_IRQHandler
        PUBWEAK I2S1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2S1_IRQHandler
        LDR     R0, =I2S1_DriverIRQHandler
        BX      R0

        PUBWEAK I2S2_IRQHandler
        PUBWEAK I2S2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2S2_IRQHandler
        LDR     R0, =I2S2_DriverIRQHandler
        BX      R0

        PUBWEAK MU_M4_IRQHandler
        PUBWEAK DDR_PerformanceMonitor_IRQHandler
        PUBWEAK DDR_IRQHandler
        PUBWEAK I2S4_IRQHandler
        PUBWEAK I2S4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2S4_IRQHandler
        LDR     R0, =I2S4_DriverIRQHandler
        BX      R0

        PUBWEAK CPU_Error_AXI_IRQHandler
        PUBWEAK CPU_Error_L2RAM_IRQHandler
        PUBWEAK SDMA2_IRQHandler
        PUBWEAK SDMA2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SDMA2_IRQHandler
        LDR     R0, =SDMA2_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved120_IRQHandler
        PUBWEAK CAAM_IRQ0_IRQHandler
        PUBWEAK CAAM_IRQ1_IRQHandler
        PUBWEAK QSPI_IRQHandler
        PUBWEAK QSPI_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
QSPI_IRQHandler
        LDR     R0, =QSPI_DriverIRQHandler
        BX      R0

        PUBWEAK TZASC_IRQHandler
        PUBWEAK Reserved125_IRQHandler
        PUBWEAK Reserved126_IRQHandler
        PUBWEAK Reserved127_IRQHandler
        PUBWEAK PERFMON1_IRQHandler
        PUBWEAK PERFMON2_IRQHandler
        PUBWEAK CAAM_IRQ2_IRQHandler
        PUBWEAK CAAM_ERROR_IRQHandler
        PUBWEAK HS_CP0_IRQHandler
        PUBWEAK HEVC_IRQHandler
        PUBWEAK ENET1_MAC0_Rx_Tx_Done1_IRQHandler
        PUBWEAK ENET1_MAC0_Rx_Tx_Done1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ENET1_MAC0_Rx_Tx_Done1_IRQHandler
        LDR     R0, =ENET1_MAC0_Rx_Tx_Done1_DriverIRQHandler
        BX      R0

        PUBWEAK ENET1_MAC0_Rx_Tx_Done2_IRQHandler
        PUBWEAK ENET1_MAC0_Rx_Tx_Done2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ENET1_MAC0_Rx_Tx_Done2_IRQHandler
        LDR     R0, =ENET1_MAC0_Rx_Tx_Done2_DriverIRQHandler
        BX      R0

        PUBWEAK ENET1_IRQHandler
        PUBWEAK ENET1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ENET1_IRQHandler
        LDR     R0, =ENET1_DriverIRQHandler
        BX      R0

        PUBWEAK ENET1_1588_Timer_IRQHandler
        PUBWEAK ENET1_1588_Timer_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ENET1_1588_Timer_IRQHandler
        LDR     R0, =ENET1_1588_Timer_DriverIRQHandler
        BX      R0

        PUBWEAK PCIE_CTRL1_IRQ0_IRQHandler
        PUBWEAK PCIE_CTRL1_IRQ1_IRQHandler
        PUBWEAK PCIE_CTRL1_IRQ2_IRQHandler
        PUBWEAK PCIE_CTRL1_IRQ3_IRQHandler
        PUBWEAK Reserved142_IRQHandler
        PUBWEAK PCIE_CTRL1_IRQHandler
        PUBWEAK DefaultISR
        SECTION .text:CODE:REORDER:NOROOT(1)
GPR_IRQ_IRQHandler
DAP_IRQHandler
SDMA1_DriverIRQHandler
GPU_IRQHandler
SNVS_IRQHandler
LCDIF_IRQHandler
SPDIF1_DriverIRQHandler
H264_IRQHandler
VPUDMA_DriverIRQHandler
QOS_IRQHandler
WDOG3_IRQHandler
HS_CP1_IRQHandler
APBHDMA_DriverIRQHandler
SPDIF2_DriverIRQHandler
BCH_IRQHandler
GPMI_IRQHandler
HDMI_IRQ0_IRQHandler
HDMI_IRQ1_IRQHandler
HDMI_IRQ2_IRQHandler
SNVS_Consolidated_IRQHandler
SNVS_Security_IRQHandler
CSU_IRQHandler
USDHC1_DriverIRQHandler
USDHC2_DriverIRQHandler
DDC_IRQHandler
DTRC_IRQHandler
UART1_DriverIRQHandler
UART2_DriverIRQHandler
UART3_DriverIRQHandler
UART4_DriverIRQHandler
VP9_IRQHandler
ECSPI1_DriverIRQHandler
ECSPI2_DriverIRQHandler
ECSPI3_DriverIRQHandler
MIPI_DSI_IRQHandler
I2C1_DriverIRQHandler
I2C2_DriverIRQHandler
I2C3_DriverIRQHandler
I2C4_DriverIRQHandler
RDC_IRQHandler
USB1_IRQHandler
USB2_IRQHandler
CSI1_IRQHandler
CSI2_IRQHandler
MIPI_CSI1_IRQHandler
MIPI_CSI2_IRQHandler
GPT6_IRQHandler
SCTR_IRQ0_IRQHandler
SCTR_IRQ1_IRQHandler
TEMPMON_IRQHandler
I2S3_DriverIRQHandler
GPT5_IRQHandler
GPT4_IRQHandler
GPT3_IRQHandler
GPT2_IRQHandler
GPT1_IRQHandler
GPIO1_INT7_IRQHandler
GPIO1_INT6_IRQHandler
GPIO1_INT5_IRQHandler
GPIO1_INT4_IRQHandler
GPIO1_INT3_IRQHandler
GPIO1_INT2_IRQHandler
GPIO1_INT1_IRQHandler
GPIO1_INT0_IRQHandler
GPIO1_Combined_0_15_IRQHandler
GPIO1_Combined_16_31_IRQHandler
GPIO2_Combined_0_15_IRQHandler
GPIO2_Combined_16_31_IRQHandler
GPIO3_Combined_0_15_IRQHandler
GPIO3_Combined_16_31_IRQHandler
GPIO4_Combined_0_15_IRQHandler
GPIO4_Combined_16_31_IRQHandler
GPIO5_Combined_0_15_IRQHandler
GPIO5_Combined_16_31_IRQHandler
PCIE_CTRL2_IRQ0_IRQHandler
PCIE_CTRL2_IRQ1_IRQHandler
PCIE_CTRL2_IRQ2_IRQHandler
PCIE_CTRL2_IRQ3_IRQHandler
WDOG1_IRQHandler
WDOG2_IRQHandler
PCIE_CTRL2_IRQHandler
PWM1_IRQHandler
PWM2_IRQHandler
PWM3_IRQHandler
PWM4_IRQHandler
CCM_IRQ1_IRQHandler
CCM_IRQ2_IRQHandler
GPC_IRQHandler
MU_A53_IRQHandler
SRC_IRQHandler
I2S56_DriverIRQHandler
RTIC_IRQHandler
CPU_PerformanceUnit_IRQHandler
CPU_CTI_Trigger_IRQHandler
SRC_Combined_IRQHandler
I2S1_DriverIRQHandler
I2S2_DriverIRQHandler
MU_M4_IRQHandler
DDR_PerformanceMonitor_IRQHandler
DDR_IRQHandler
I2S4_DriverIRQHandler
CPU_Error_AXI_IRQHandler
CPU_Error_L2RAM_IRQHandler
SDMA2_DriverIRQHandler
Reserved120_IRQHandler
CAAM_IRQ0_IRQHandler
CAAM_IRQ1_IRQHandler
QSPI_DriverIRQHandler
TZASC_IRQHandler
Reserved125_IRQHandler
Reserved126_IRQHandler
Reserved127_IRQHandler
PERFMON1_IRQHandler
PERFMON2_IRQHandler
CAAM_IRQ2_IRQHandler
CAAM_ERROR_IRQHandler
HS_CP0_IRQHandler
HEVC_IRQHandler
ENET1_MAC0_Rx_Tx_Done1_DriverIRQHandler
ENET1_MAC0_Rx_Tx_Done2_DriverIRQHandler
ENET1_DriverIRQHandler
ENET1_1588_Timer_DriverIRQHandler
PCIE_CTRL1_IRQ0_IRQHandler
PCIE_CTRL1_IRQ1_IRQHandler
PCIE_CTRL1_IRQ2_IRQHandler
PCIE_CTRL1_IRQ3_IRQHandler
Reserved142_IRQHandler
PCIE_CTRL1_IRQHandler
DefaultISR
        B DefaultISR

        END
