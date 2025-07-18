; -------------------------------------------------------------------------
;  @file:    startup_MIMX8ML6_cm7.s
;  @purpose: CMSIS Cortex-M7 Core Device Startup File
;            MIMX8ML6_cm7
;  @version: 6.0
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
        DCD     Reserved16_IRQHandler                         ;xxx Interrupt 16
        DCD     DAP_IRQHandler                                ;DAP Interrupt
        DCD     SDMA1_IRQHandler                              ;AND of all 48 SDMA1 interrupts (events) from all the channels
        DCD     GPU3D_IRQHandler                              ;GPU3D Interrupt
        DCD     SNVS_IRQHandler                               ;ON-OFF button press shorter than 5 seconds (pulse event)
        DCD     LCDIF1_IRQHandler                             ;LCDIF1 Interrupt
        DCD     LCDIF2_IRQHandler                             ;LCDIF2 Interrupt
        DCD     VPU_G1_IRQHandler                             ;VPU G1 Decoder Interrupt
        DCD     VPU_G2_IRQHandler                             ;VPU G2 Decoder Interrupt
        DCD     QOS_IRQHandler                                ;QOS interrupt
        DCD     WDOG3_IRQHandler                              ;Watchdog Timer reset
        DCD     HS_CP1_IRQHandler                             ;HS Interrupt Request
        DCD     APBHDMA_IRQHandler                            ;GPMI operation channel 0-3 description complete interrupt
        DCD     ML_IRQHandler                                 ;Machine Learning Processor Interrupt
        DCD     BCH_IRQHandler                                ;BCH operation complete interrupt
        DCD     GPMI_IRQHandler                               ;GPMI operation TIMEOUT ERROR interrupt
        DCD     ISI_IRQHandler                                ;ISI Interrupt
        DCD     MIPI_CSI1_IRQHandler                          ;MIPI CSI Interrupt
        DCD     MIPI_DSI_IRQHandler                           ;MIPI DSI Interrupt
        DCD     SNVS_Consolidated_IRQHandler                  ;SRTC Consolidated Interrupt. Non TZ.
        DCD     SNVS_Security_IRQHandler                      ;SRTC Security Interrupt. TZ.
        DCD     CSU_IRQHandler                                ;CSU Interrupt Request. Indicates to the processor that one or more alarm inputs were asserted.
        DCD     USDHC1_IRQHandler                             ;uSDHC1 Enhanced SDHC Interrupt Request
        DCD     USDHC2_IRQHandler                             ;uSDHC2 Enhanced SDHC Interrupt Request
        DCD     USDHC3_IRQHandler                             ;uSDHC3 Enhanced SDHC Interrupt Request
        DCD     GPU2D_IRQHandler                              ;GPU2D Interrupt
        DCD     UART1_IRQHandler                              ;UART-1 ORed interrupt
        DCD     UART2_IRQHandler                              ;UART-2 ORed interrupt
        DCD     UART3_IRQHandler                              ;UART-3 ORed interrupt
        DCD     UART4_IRQHandler                              ;UART-4 ORed interrupt
        DCD     VPU_IRQHandler                                ;VPU Encoder Interrupt
        DCD     ECSPI1_IRQHandler                             ;ECSPI1 interrupt request line to the core.
        DCD     ECSPI2_IRQHandler                             ;ECSPI2 interrupt request line to the core.
        DCD     ECSPI3_IRQHandler                             ;ECSPI3 interrupt request line to the core.
        DCD     SDMA3_IRQHandler                              ;AND of all 48 SDMA3 interrupts (events) from all the channels
        DCD     I2C1_IRQHandler                               ;I2C-1 Interrupt
        DCD     I2C2_IRQHandler                               ;I2C-2 Interrupt
        DCD     I2C3_IRQHandler                               ;I2C-3 Interrupt
        DCD     I2C4_IRQHandler                               ;I2C-4 Interrupt
        DCD     RDC_IRQHandler                                ;RDC interrupt
        DCD     USB1_IRQHandler                               ;USB1 Interrupt
        DCD     USB2_IRQHandler                               ;USB2 Interrupt
        DCD     ISI_CH1_IRQHandler                            ;ISI Camera Channel 1 Interrupt
        DCD     HDMI_TX_IRQHandler                            ;HDMI TX Subsystem Interrupt
        DCD     PDM_HWVAD_EVENT_IRQHandler                    ;Digital Microphone interface voice activity detector event interrupt
        DCD     PDM_HWVAD_ERROR_IRQHandler                    ;Digital Microphone interface voice activity detector error interrupt
        DCD     GPT6_IRQHandler                               ;OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines
        DCD     SCTR_IRQ0_IRQHandler                          ;System Counter Interrupt 0
        DCD     SCTR_IRQ1_IRQHandler                          ;System Counter Interrupt 1
        DCD     ANAMIX_IRQHandler                             ;TempSensor (Temperature alarm and criticl alarm).
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
        DCD     ISP1_IRQHandler                               ;ISP 1 ISP Interrupts
        DCD     ISP2_IRQHandler                               ;ISP 2 ISP Interrupts
        DCD     I2C5_IRQHandler                               ;I2C-5 Interrupt
        DCD     I2C6_IRQHandler                               ;I2C-6 Interrupt
        DCD     WDOG1_IRQHandler                              ;Watchdog Timer reset
        DCD     WDOG2_IRQHandler                              ;Watchdog Timer reset
        DCD     MIPI_CSI2_IRQHandler                          ;MIPI CSI 2 Interrupt
        DCD     PWM1_IRQHandler                               ;Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line.
        DCD     PWM2_IRQHandler                               ;Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line.
        DCD     PWM3_IRQHandler                               ;Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line.
        DCD     PWM4_IRQHandler                               ;Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line.
        DCD     CCM_IRQ1_IRQHandler                           ;CCM Interrupt Request 1
        DCD     CCM_IRQ2_IRQHandler                           ;CCM Interrupt Request 2
        DCD     GPC_IRQHandler                                ;GPC Interrupt Request 1
        DCD     MU1_A53_IRQHandler                            ;Interrupt to A53 (A53,M7 MU)
        DCD     SRC_IRQHandler                                ;SRC interrupt request
        DCD     I2S56_IRQHandler                              ;SAI5/6 Receive / Transmit Interrupt
        DCD     RTIC_IRQHandler                               ;RTIC Interrupt
        DCD     CPU_PerformanceUnit_IRQHandler                ;Performance Unit Interrupts from Cheetah (interrnally: PMUIRQ[n]
        DCD     CPU_CTI_Trigger_IRQHandler                    ;CTI trigger outputs (internal: nCTIIRQ[n]
        DCD     SRC_Combined_IRQHandler                       ;Combined CPU wdog interrupts (4x) out of SRC.
        DCD     I2S1_IRQHandler                               ;SAI1 Receive / Transmit Interrupt
        DCD     I2S2_IRQHandler                               ;SAI2 Receive / Transmit Interrupt
        DCD     MU1_M7_IRQHandler                             ;Interrupt to M7 (A53, M7 MU)
        DCD     DDR_PerformanceMonitor_IRQHandler             ;ddr Interrupt for performance monitor
        DCD     DDR_IRQHandler                                ;ddr Interrupt
        DCD     DEWARP_IRQHandler                             ;Dewarp Interrupt
        DCD     CPU_Error_AXI_IRQHandler                      ;CPU Error indicator for AXI transaction with a write response error condition
        DCD     CPU_Error_L2RAM_IRQHandler                    ;CPU Error indicator for L2 RAM double-bit ECC error
        DCD     SDMA2_IRQHandler                              ;AND of all 48 SDMA2 interrupts (events) from all the channels
        DCD     SJC_IRQHandler                                ;Interrupt triggered by SJC register
        DCD     CAAM_IRQ0_IRQHandler                          ;CAAM interrupt queue for JQ
        DCD     CAAM_IRQ1_IRQHandler                          ;CAAM interrupt queue for JQ
        DCD     FlexSPI_IRQHandler                            ;FlexSPI Interrupt
        DCD     TZASC_IRQHandler                              ;TZASC (PL380) interrupt
        DCD     PDM_EVENT_IRQHandler                          ;Digital Microphone interface interrupt
        DCD     PDM_ERROR_IRQHandler                          ;Digital Microphone interface error interrupt
        DCD     I2S7_IRQHandler                               ;SAI7 Receive / Transmit Interrupt
        DCD     PERFMON1_IRQHandler                           ;General Interrupt
        DCD     PERFMON2_IRQHandler                           ;General Interrupt
        DCD     CAAM_IRQ2_IRQHandler                          ;CAAM interrupt queue for JQ
        DCD     CAAM_ERROR_IRQHandler                         ;Recoverable error interrupt
        DCD     HS_CP0_IRQHandler                             ;HS Interrupt Request
        DCD     CM7_CTI_IRQHandler                            ;CTI trigger outputs from CM7 platform
        DCD     ENET1_MAC0_Rx_Tx_Done1_IRQHandler             ;MAC 0 Receive / Trasmit Frame / Buffer Done
        DCD     ENET1_MAC0_Rx_Tx_Done2_IRQHandler             ;MAC 0 Receive / Trasmit Frame / Buffer Done
        DCD     ENET1_IRQHandler                              ;MAC 0 IRQ
        DCD     ENET1_1588_Timer_IRQHandler                   ;MAC 0 1588 Timer Interrupt-synchronous
        DCD     ASRC_IRQHandler                               ;ASRC Interrupt
        DCD     PCIE_CTRL1_0_IRQHandler                       ;Coming from GLUE logic, of set/reset FF, driven by PCIE signals, interrupt 0
        DCD     PCIE_CTRL1_1_IRQHandler                       ;Coming from GLUE logic, of set/reset FF, driven by PCIE signals, interrupt 1
        DCD     PCIE_CTRL1_2_IRQHandler                       ;Coming from GLUE logic, of set/reset FF, driven by PCIE signals, interrupt 2
        DCD     PCIE_CTRL1_3_IRQHandler                       ;Coming from GLUE logic, of set/reset FF, driven by PCIE signals, interrupt 3
        DCD     PCIE_EDMA_IRQHandler                          ;Channels [63:32] interrupts requests
        DCD     AUDIO_XCVR0_IRQHandler                        ;eARC Interrupt 0
        DCD     AUDIO_XCVR1_IRQHandler                        ;eARC Interrupt 1
        DCD     AUD2HTX_IRQHandler                            ;Audio to HDMI TX Audio Link Master Interrupt
        DCD     EDMA1_ERR_IRQHandler                          ;Audio Subsystem eDMA Error Interrupt
        DCD     EDMA1_0_15_IRQHandler                         ;Audio Subsystem eDMA Channel Interrupts, Logical OR of channels [15:0]
        DCD     EDMA1_16_31_IRQHandler                        ;Audio Subsystem eDMA Channel Interrupts, Logical OR of channels [31:16]
        DCD     ENET_QOS_PMT_IRQHandler                       ;ENET QOS TSN Interrupt from PMT
        DCD     ENET_QOS_IRQHandler                           ;ENET QOS TSN LPI RX exit/Host System/RX/TX Channels[4:0] Interrupt
        DCD     MU2_A53_IRQHandler                            ;Interrupt to A53 (A53, Audio Processor MU)
        DCD     MU2_AUDIO_IRQHandler                          ;Interrupt to Audio Processor (A53, Audio Processor MU)
        DCD     MU3_M7_IRQHandler                             ;Interrupt to M7 (M7, Audio Processor MU)
        DCD     MU3_AUDIO_IRQHandler                          ;Interrupt to Audio Processor (M7, Audio Processor MU)
        DCD     PCIE_CTRL1_IRQHandler                         ;RC/EP message transaction Interrupt
        DCD     PCIE_CTRL1_ERR_IRQHandler                     ;RC/EP PME Message and Error Interrupt
        DCD     CAN_FD1_IRQHandler                            ;CAN-FD1 Interrupt from bus off/line error/RX warning/TX warning/wakeup/match in PN/timeout in PN/busoff done/FD error
        DCD     CAN_FD1_ERROR_IRQHandler                      ;CAN-FD1 Interrupt from correctable error/non correctable error int host/ non correctable error int internal
        DCD     CAN_FD2_IRQHandler                            ;CAN-FD2 Interrupt from bus off/line error/RX warning/TX warning/wakeup/match in PN/timeout in PN/busoff done/FD error
        DCD     CAN_FD2_ERROR_IRQHandler                      ;CAN-FD2 Interrupt from correctable error/non correctable error int host/ non correctable error int internal
        DCD     AUDIO_XCVR_IRQHandler                         ;eARC PHY - SPDIF wakeup interrupt
        DCD     DDR_ERR_IRQHandler                            ;DRAM Controller Error Interrupt
        DCD     USB1_WAKEUP_IRQHandler                        ;USB-1 Wake-up Interrupt
        DCD     USB2_WAKEUP_IRQHandler                        ;USB-2 Wake-up Interrupt
        DCD     MECC_IRQHandler                               ;OCRAM Memory ECC Interrupt
        DCD     MECC_ERR_IRQHandler                           ;OCRAM Memory ECC Error Interrupt
        DCD     MECC_S_IRQHandler                             ;OCRAM_S Memory ECC Interrupt
        DCD     MECC_S_ERR_IRQHandler                         ;OCRAM_S Memory ECC Error Interrupt
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

        PUBWEAK Reserved16_IRQHandler
        PUBWEAK Reserved16_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved16_IRQHandler
        LDR     R0, =Reserved16_DriverIRQHandler
        BX      R0

        PUBWEAK DAP_IRQHandler
        PUBWEAK DAP_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DAP_IRQHandler
        LDR     R0, =DAP_DriverIRQHandler
        BX      R0

        PUBWEAK SDMA1_IRQHandler
        PUBWEAK SDMA1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SDMA1_IRQHandler
        LDR     R0, =SDMA1_DriverIRQHandler
        BX      R0

        PUBWEAK GPU3D_IRQHandler
        PUBWEAK GPU3D_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPU3D_IRQHandler
        LDR     R0, =GPU3D_DriverIRQHandler
        BX      R0

        PUBWEAK SNVS_IRQHandler
        PUBWEAK SNVS_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SNVS_IRQHandler
        LDR     R0, =SNVS_DriverIRQHandler
        BX      R0

        PUBWEAK LCDIF1_IRQHandler
        PUBWEAK LCDIF1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LCDIF1_IRQHandler
        LDR     R0, =LCDIF1_DriverIRQHandler
        BX      R0

        PUBWEAK LCDIF2_IRQHandler
        PUBWEAK LCDIF2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LCDIF2_IRQHandler
        LDR     R0, =LCDIF2_DriverIRQHandler
        BX      R0

        PUBWEAK VPU_G1_IRQHandler
        PUBWEAK VPU_G1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
VPU_G1_IRQHandler
        LDR     R0, =VPU_G1_DriverIRQHandler
        BX      R0

        PUBWEAK VPU_G2_IRQHandler
        PUBWEAK VPU_G2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
VPU_G2_IRQHandler
        LDR     R0, =VPU_G2_DriverIRQHandler
        BX      R0

        PUBWEAK QOS_IRQHandler
        PUBWEAK QOS_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
QOS_IRQHandler
        LDR     R0, =QOS_DriverIRQHandler
        BX      R0

        PUBWEAK WDOG3_IRQHandler
        PUBWEAK WDOG3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WDOG3_IRQHandler
        LDR     R0, =WDOG3_DriverIRQHandler
        BX      R0

        PUBWEAK HS_CP1_IRQHandler
        PUBWEAK HS_CP1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
HS_CP1_IRQHandler
        LDR     R0, =HS_CP1_DriverIRQHandler
        BX      R0

        PUBWEAK APBHDMA_IRQHandler
        PUBWEAK APBHDMA_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
APBHDMA_IRQHandler
        LDR     R0, =APBHDMA_DriverIRQHandler
        BX      R0

        PUBWEAK ML_IRQHandler
        PUBWEAK ML_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ML_IRQHandler
        LDR     R0, =ML_DriverIRQHandler
        BX      R0

        PUBWEAK BCH_IRQHandler
        PUBWEAK BCH_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
BCH_IRQHandler
        LDR     R0, =BCH_DriverIRQHandler
        BX      R0

        PUBWEAK GPMI_IRQHandler
        PUBWEAK GPMI_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPMI_IRQHandler
        LDR     R0, =GPMI_DriverIRQHandler
        BX      R0

        PUBWEAK ISI_IRQHandler
        PUBWEAK ISI_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ISI_IRQHandler
        LDR     R0, =ISI_DriverIRQHandler
        BX      R0

        PUBWEAK MIPI_CSI1_IRQHandler
        PUBWEAK MIPI_CSI1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MIPI_CSI1_IRQHandler
        LDR     R0, =MIPI_CSI1_DriverIRQHandler
        BX      R0

        PUBWEAK MIPI_DSI_IRQHandler
        PUBWEAK MIPI_DSI_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MIPI_DSI_IRQHandler
        LDR     R0, =MIPI_DSI_DriverIRQHandler
        BX      R0

        PUBWEAK SNVS_Consolidated_IRQHandler
        PUBWEAK SNVS_Consolidated_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SNVS_Consolidated_IRQHandler
        LDR     R0, =SNVS_Consolidated_DriverIRQHandler
        BX      R0

        PUBWEAK SNVS_Security_IRQHandler
        PUBWEAK SNVS_Security_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SNVS_Security_IRQHandler
        LDR     R0, =SNVS_Security_DriverIRQHandler
        BX      R0

        PUBWEAK CSU_IRQHandler
        PUBWEAK CSU_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CSU_IRQHandler
        LDR     R0, =CSU_DriverIRQHandler
        BX      R0

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

        PUBWEAK USDHC3_IRQHandler
        PUBWEAK USDHC3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USDHC3_IRQHandler
        LDR     R0, =USDHC3_DriverIRQHandler
        BX      R0

        PUBWEAK GPU2D_IRQHandler
        PUBWEAK GPU2D_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPU2D_IRQHandler
        LDR     R0, =GPU2D_DriverIRQHandler
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

        PUBWEAK VPU_IRQHandler
        PUBWEAK VPU_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
VPU_IRQHandler
        LDR     R0, =VPU_DriverIRQHandler
        BX      R0

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

        PUBWEAK SDMA3_IRQHandler
        PUBWEAK SDMA3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SDMA3_IRQHandler
        LDR     R0, =SDMA3_DriverIRQHandler
        BX      R0

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
        PUBWEAK RDC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
RDC_IRQHandler
        LDR     R0, =RDC_DriverIRQHandler
        BX      R0

        PUBWEAK USB1_IRQHandler
        PUBWEAK USB1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USB1_IRQHandler
        LDR     R0, =USB1_DriverIRQHandler
        BX      R0

        PUBWEAK USB2_IRQHandler
        PUBWEAK USB2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USB2_IRQHandler
        LDR     R0, =USB2_DriverIRQHandler
        BX      R0

        PUBWEAK ISI_CH1_IRQHandler
        PUBWEAK ISI_CH1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ISI_CH1_IRQHandler
        LDR     R0, =ISI_CH1_DriverIRQHandler
        BX      R0

        PUBWEAK HDMI_TX_IRQHandler
        PUBWEAK HDMI_TX_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
HDMI_TX_IRQHandler
        LDR     R0, =HDMI_TX_DriverIRQHandler
        BX      R0

        PUBWEAK PDM_HWVAD_EVENT_IRQHandler
        PUBWEAK PDM_HWVAD_EVENT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PDM_HWVAD_EVENT_IRQHandler
        LDR     R0, =PDM_HWVAD_EVENT_DriverIRQHandler
        BX      R0

        PUBWEAK PDM_HWVAD_ERROR_IRQHandler
        PUBWEAK PDM_HWVAD_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PDM_HWVAD_ERROR_IRQHandler
        LDR     R0, =PDM_HWVAD_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK GPT6_IRQHandler
        PUBWEAK GPT6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPT6_IRQHandler
        LDR     R0, =GPT6_DriverIRQHandler
        BX      R0

        PUBWEAK SCTR_IRQ0_IRQHandler
        PUBWEAK SCTR_IRQ0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SCTR_IRQ0_IRQHandler
        LDR     R0, =SCTR_IRQ0_DriverIRQHandler
        BX      R0

        PUBWEAK SCTR_IRQ1_IRQHandler
        PUBWEAK SCTR_IRQ1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SCTR_IRQ1_IRQHandler
        LDR     R0, =SCTR_IRQ1_DriverIRQHandler
        BX      R0

        PUBWEAK ANAMIX_IRQHandler
        PUBWEAK ANAMIX_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ANAMIX_IRQHandler
        LDR     R0, =ANAMIX_DriverIRQHandler
        BX      R0

        PUBWEAK I2S3_IRQHandler
        PUBWEAK I2S3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2S3_IRQHandler
        LDR     R0, =I2S3_DriverIRQHandler
        BX      R0

        PUBWEAK GPT5_IRQHandler
        PUBWEAK GPT5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPT5_IRQHandler
        LDR     R0, =GPT5_DriverIRQHandler
        BX      R0

        PUBWEAK GPT4_IRQHandler
        PUBWEAK GPT4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPT4_IRQHandler
        LDR     R0, =GPT4_DriverIRQHandler
        BX      R0

        PUBWEAK GPT3_IRQHandler
        PUBWEAK GPT3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPT3_IRQHandler
        LDR     R0, =GPT3_DriverIRQHandler
        BX      R0

        PUBWEAK GPT2_IRQHandler
        PUBWEAK GPT2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPT2_IRQHandler
        LDR     R0, =GPT2_DriverIRQHandler
        BX      R0

        PUBWEAK GPT1_IRQHandler
        PUBWEAK GPT1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPT1_IRQHandler
        LDR     R0, =GPT1_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO1_INT7_IRQHandler
        PUBWEAK GPIO1_INT7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO1_INT7_IRQHandler
        LDR     R0, =GPIO1_INT7_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO1_INT6_IRQHandler
        PUBWEAK GPIO1_INT6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO1_INT6_IRQHandler
        LDR     R0, =GPIO1_INT6_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO1_INT5_IRQHandler
        PUBWEAK GPIO1_INT5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO1_INT5_IRQHandler
        LDR     R0, =GPIO1_INT5_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO1_INT4_IRQHandler
        PUBWEAK GPIO1_INT4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO1_INT4_IRQHandler
        LDR     R0, =GPIO1_INT4_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO1_INT3_IRQHandler
        PUBWEAK GPIO1_INT3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO1_INT3_IRQHandler
        LDR     R0, =GPIO1_INT3_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO1_INT2_IRQHandler
        PUBWEAK GPIO1_INT2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO1_INT2_IRQHandler
        LDR     R0, =GPIO1_INT2_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO1_INT1_IRQHandler
        PUBWEAK GPIO1_INT1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO1_INT1_IRQHandler
        LDR     R0, =GPIO1_INT1_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO1_INT0_IRQHandler
        PUBWEAK GPIO1_INT0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO1_INT0_IRQHandler
        LDR     R0, =GPIO1_INT0_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO1_Combined_0_15_IRQHandler
        PUBWEAK GPIO1_Combined_0_15_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO1_Combined_0_15_IRQHandler
        LDR     R0, =GPIO1_Combined_0_15_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO1_Combined_16_31_IRQHandler
        PUBWEAK GPIO1_Combined_16_31_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO1_Combined_16_31_IRQHandler
        LDR     R0, =GPIO1_Combined_16_31_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO2_Combined_0_15_IRQHandler
        PUBWEAK GPIO2_Combined_0_15_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO2_Combined_0_15_IRQHandler
        LDR     R0, =GPIO2_Combined_0_15_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO2_Combined_16_31_IRQHandler
        PUBWEAK GPIO2_Combined_16_31_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO2_Combined_16_31_IRQHandler
        LDR     R0, =GPIO2_Combined_16_31_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO3_Combined_0_15_IRQHandler
        PUBWEAK GPIO3_Combined_0_15_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO3_Combined_0_15_IRQHandler
        LDR     R0, =GPIO3_Combined_0_15_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO3_Combined_16_31_IRQHandler
        PUBWEAK GPIO3_Combined_16_31_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO3_Combined_16_31_IRQHandler
        LDR     R0, =GPIO3_Combined_16_31_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO4_Combined_0_15_IRQHandler
        PUBWEAK GPIO4_Combined_0_15_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO4_Combined_0_15_IRQHandler
        LDR     R0, =GPIO4_Combined_0_15_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO4_Combined_16_31_IRQHandler
        PUBWEAK GPIO4_Combined_16_31_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO4_Combined_16_31_IRQHandler
        LDR     R0, =GPIO4_Combined_16_31_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO5_Combined_0_15_IRQHandler
        PUBWEAK GPIO5_Combined_0_15_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO5_Combined_0_15_IRQHandler
        LDR     R0, =GPIO5_Combined_0_15_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO5_Combined_16_31_IRQHandler
        PUBWEAK GPIO5_Combined_16_31_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO5_Combined_16_31_IRQHandler
        LDR     R0, =GPIO5_Combined_16_31_DriverIRQHandler
        BX      R0

        PUBWEAK ISP1_IRQHandler
        PUBWEAK ISP1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ISP1_IRQHandler
        LDR     R0, =ISP1_DriverIRQHandler
        BX      R0

        PUBWEAK ISP2_IRQHandler
        PUBWEAK ISP2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ISP2_IRQHandler
        LDR     R0, =ISP2_DriverIRQHandler
        BX      R0

        PUBWEAK I2C5_IRQHandler
        PUBWEAK I2C5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2C5_IRQHandler
        LDR     R0, =I2C5_DriverIRQHandler
        BX      R0

        PUBWEAK I2C6_IRQHandler
        PUBWEAK I2C6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2C6_IRQHandler
        LDR     R0, =I2C6_DriverIRQHandler
        BX      R0

        PUBWEAK WDOG1_IRQHandler
        PUBWEAK WDOG1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WDOG1_IRQHandler
        LDR     R0, =WDOG1_DriverIRQHandler
        BX      R0

        PUBWEAK WDOG2_IRQHandler
        PUBWEAK WDOG2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WDOG2_IRQHandler
        LDR     R0, =WDOG2_DriverIRQHandler
        BX      R0

        PUBWEAK MIPI_CSI2_IRQHandler
        PUBWEAK MIPI_CSI2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MIPI_CSI2_IRQHandler
        LDR     R0, =MIPI_CSI2_DriverIRQHandler
        BX      R0

        PUBWEAK PWM1_IRQHandler
        PUBWEAK PWM1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PWM1_IRQHandler
        LDR     R0, =PWM1_DriverIRQHandler
        BX      R0

        PUBWEAK PWM2_IRQHandler
        PUBWEAK PWM2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PWM2_IRQHandler
        LDR     R0, =PWM2_DriverIRQHandler
        BX      R0

        PUBWEAK PWM3_IRQHandler
        PUBWEAK PWM3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PWM3_IRQHandler
        LDR     R0, =PWM3_DriverIRQHandler
        BX      R0

        PUBWEAK PWM4_IRQHandler
        PUBWEAK PWM4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PWM4_IRQHandler
        LDR     R0, =PWM4_DriverIRQHandler
        BX      R0

        PUBWEAK CCM_IRQ1_IRQHandler
        PUBWEAK CCM_IRQ1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CCM_IRQ1_IRQHandler
        LDR     R0, =CCM_IRQ1_DriverIRQHandler
        BX      R0

        PUBWEAK CCM_IRQ2_IRQHandler
        PUBWEAK CCM_IRQ2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CCM_IRQ2_IRQHandler
        LDR     R0, =CCM_IRQ2_DriverIRQHandler
        BX      R0

        PUBWEAK GPC_IRQHandler
        PUBWEAK GPC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPC_IRQHandler
        LDR     R0, =GPC_DriverIRQHandler
        BX      R0

        PUBWEAK MU1_A53_IRQHandler
        PUBWEAK MU1_A53_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MU1_A53_IRQHandler
        LDR     R0, =MU1_A53_DriverIRQHandler
        BX      R0

        PUBWEAK SRC_IRQHandler
        PUBWEAK SRC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SRC_IRQHandler
        LDR     R0, =SRC_DriverIRQHandler
        BX      R0

        PUBWEAK I2S56_IRQHandler
        PUBWEAK I2S56_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2S56_IRQHandler
        LDR     R0, =I2S56_DriverIRQHandler
        BX      R0

        PUBWEAK RTIC_IRQHandler
        PUBWEAK RTIC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
RTIC_IRQHandler
        LDR     R0, =RTIC_DriverIRQHandler
        BX      R0

        PUBWEAK CPU_PerformanceUnit_IRQHandler
        PUBWEAK CPU_PerformanceUnit_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CPU_PerformanceUnit_IRQHandler
        LDR     R0, =CPU_PerformanceUnit_DriverIRQHandler
        BX      R0

        PUBWEAK CPU_CTI_Trigger_IRQHandler
        PUBWEAK CPU_CTI_Trigger_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CPU_CTI_Trigger_IRQHandler
        LDR     R0, =CPU_CTI_Trigger_DriverIRQHandler
        BX      R0

        PUBWEAK SRC_Combined_IRQHandler
        PUBWEAK SRC_Combined_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SRC_Combined_IRQHandler
        LDR     R0, =SRC_Combined_DriverIRQHandler
        BX      R0

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

        PUBWEAK MU1_M7_IRQHandler
        PUBWEAK MU1_M7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MU1_M7_IRQHandler
        LDR     R0, =MU1_M7_DriverIRQHandler
        BX      R0

        PUBWEAK DDR_PerformanceMonitor_IRQHandler
        PUBWEAK DDR_PerformanceMonitor_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DDR_PerformanceMonitor_IRQHandler
        LDR     R0, =DDR_PerformanceMonitor_DriverIRQHandler
        BX      R0

        PUBWEAK DDR_IRQHandler
        PUBWEAK DDR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DDR_IRQHandler
        LDR     R0, =DDR_DriverIRQHandler
        BX      R0

        PUBWEAK DEWARP_IRQHandler
        PUBWEAK DEWARP_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DEWARP_IRQHandler
        LDR     R0, =DEWARP_DriverIRQHandler
        BX      R0

        PUBWEAK CPU_Error_AXI_IRQHandler
        PUBWEAK CPU_Error_AXI_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CPU_Error_AXI_IRQHandler
        LDR     R0, =CPU_Error_AXI_DriverIRQHandler
        BX      R0

        PUBWEAK CPU_Error_L2RAM_IRQHandler
        PUBWEAK CPU_Error_L2RAM_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CPU_Error_L2RAM_IRQHandler
        LDR     R0, =CPU_Error_L2RAM_DriverIRQHandler
        BX      R0

        PUBWEAK SDMA2_IRQHandler
        PUBWEAK SDMA2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SDMA2_IRQHandler
        LDR     R0, =SDMA2_DriverIRQHandler
        BX      R0

        PUBWEAK SJC_IRQHandler
        PUBWEAK SJC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SJC_IRQHandler
        LDR     R0, =SJC_DriverIRQHandler
        BX      R0

        PUBWEAK CAAM_IRQ0_IRQHandler
        PUBWEAK CAAM_IRQ0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAAM_IRQ0_IRQHandler
        LDR     R0, =CAAM_IRQ0_DriverIRQHandler
        BX      R0

        PUBWEAK CAAM_IRQ1_IRQHandler
        PUBWEAK CAAM_IRQ1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAAM_IRQ1_IRQHandler
        LDR     R0, =CAAM_IRQ1_DriverIRQHandler
        BX      R0

        PUBWEAK FlexSPI_IRQHandler
        PUBWEAK FlexSPI_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FlexSPI_IRQHandler
        LDR     R0, =FlexSPI_DriverIRQHandler
        BX      R0

        PUBWEAK TZASC_IRQHandler
        PUBWEAK TZASC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
TZASC_IRQHandler
        LDR     R0, =TZASC_DriverIRQHandler
        BX      R0

        PUBWEAK PDM_EVENT_IRQHandler
        PUBWEAK PDM_EVENT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PDM_EVENT_IRQHandler
        LDR     R0, =PDM_EVENT_DriverIRQHandler
        BX      R0

        PUBWEAK PDM_ERROR_IRQHandler
        PUBWEAK PDM_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PDM_ERROR_IRQHandler
        LDR     R0, =PDM_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK I2S7_IRQHandler
        PUBWEAK I2S7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I2S7_IRQHandler
        LDR     R0, =I2S7_DriverIRQHandler
        BX      R0

        PUBWEAK PERFMON1_IRQHandler
        PUBWEAK PERFMON1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PERFMON1_IRQHandler
        LDR     R0, =PERFMON1_DriverIRQHandler
        BX      R0

        PUBWEAK PERFMON2_IRQHandler
        PUBWEAK PERFMON2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PERFMON2_IRQHandler
        LDR     R0, =PERFMON2_DriverIRQHandler
        BX      R0

        PUBWEAK CAAM_IRQ2_IRQHandler
        PUBWEAK CAAM_IRQ2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAAM_IRQ2_IRQHandler
        LDR     R0, =CAAM_IRQ2_DriverIRQHandler
        BX      R0

        PUBWEAK CAAM_ERROR_IRQHandler
        PUBWEAK CAAM_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAAM_ERROR_IRQHandler
        LDR     R0, =CAAM_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK HS_CP0_IRQHandler
        PUBWEAK HS_CP0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
HS_CP0_IRQHandler
        LDR     R0, =HS_CP0_DriverIRQHandler
        BX      R0

        PUBWEAK CM7_CTI_IRQHandler
        PUBWEAK CM7_CTI_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CM7_CTI_IRQHandler
        LDR     R0, =CM7_CTI_DriverIRQHandler
        BX      R0

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

        PUBWEAK ASRC_IRQHandler
        PUBWEAK ASRC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ASRC_IRQHandler
        LDR     R0, =ASRC_DriverIRQHandler
        BX      R0

        PUBWEAK PCIE_CTRL1_0_IRQHandler
        PUBWEAK PCIE_CTRL1_0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PCIE_CTRL1_0_IRQHandler
        LDR     R0, =PCIE_CTRL1_0_DriverIRQHandler
        BX      R0

        PUBWEAK PCIE_CTRL1_1_IRQHandler
        PUBWEAK PCIE_CTRL1_1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PCIE_CTRL1_1_IRQHandler
        LDR     R0, =PCIE_CTRL1_1_DriverIRQHandler
        BX      R0

        PUBWEAK PCIE_CTRL1_2_IRQHandler
        PUBWEAK PCIE_CTRL1_2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PCIE_CTRL1_2_IRQHandler
        LDR     R0, =PCIE_CTRL1_2_DriverIRQHandler
        BX      R0

        PUBWEAK PCIE_CTRL1_3_IRQHandler
        PUBWEAK PCIE_CTRL1_3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PCIE_CTRL1_3_IRQHandler
        LDR     R0, =PCIE_CTRL1_3_DriverIRQHandler
        BX      R0

        PUBWEAK PCIE_EDMA_IRQHandler
        PUBWEAK PCIE_EDMA_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PCIE_EDMA_IRQHandler
        LDR     R0, =PCIE_EDMA_DriverIRQHandler
        BX      R0

        PUBWEAK AUDIO_XCVR0_IRQHandler
        PUBWEAK AUDIO_XCVR0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
AUDIO_XCVR0_IRQHandler
        LDR     R0, =AUDIO_XCVR0_DriverIRQHandler
        BX      R0

        PUBWEAK AUDIO_XCVR1_IRQHandler
        PUBWEAK AUDIO_XCVR1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
AUDIO_XCVR1_IRQHandler
        LDR     R0, =AUDIO_XCVR1_DriverIRQHandler
        BX      R0

        PUBWEAK AUD2HTX_IRQHandler
        PUBWEAK AUD2HTX_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
AUD2HTX_IRQHandler
        LDR     R0, =AUD2HTX_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_ERR_IRQHandler
        PUBWEAK EDMA1_ERR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_ERR_IRQHandler
        LDR     R0, =EDMA1_ERR_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_0_15_IRQHandler
        PUBWEAK EDMA1_0_15_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_0_15_IRQHandler
        LDR     R0, =EDMA1_0_15_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_16_31_IRQHandler
        PUBWEAK EDMA1_16_31_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_16_31_IRQHandler
        LDR     R0, =EDMA1_16_31_DriverIRQHandler
        BX      R0

        PUBWEAK ENET_QOS_PMT_IRQHandler
        PUBWEAK ENET_QOS_PMT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ENET_QOS_PMT_IRQHandler
        LDR     R0, =ENET_QOS_PMT_DriverIRQHandler
        BX      R0

        PUBWEAK ENET_QOS_IRQHandler
        PUBWEAK ENET_QOS_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ENET_QOS_IRQHandler
        LDR     R0, =ENET_QOS_DriverIRQHandler
        BX      R0

        PUBWEAK MU2_A53_IRQHandler
        PUBWEAK MU2_A53_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MU2_A53_IRQHandler
        LDR     R0, =MU2_A53_DriverIRQHandler
        BX      R0

        PUBWEAK MU2_AUDIO_IRQHandler
        PUBWEAK MU2_AUDIO_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MU2_AUDIO_IRQHandler
        LDR     R0, =MU2_AUDIO_DriverIRQHandler
        BX      R0

        PUBWEAK MU3_M7_IRQHandler
        PUBWEAK MU3_M7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MU3_M7_IRQHandler
        LDR     R0, =MU3_M7_DriverIRQHandler
        BX      R0

        PUBWEAK MU3_AUDIO_IRQHandler
        PUBWEAK MU3_AUDIO_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MU3_AUDIO_IRQHandler
        LDR     R0, =MU3_AUDIO_DriverIRQHandler
        BX      R0

        PUBWEAK PCIE_CTRL1_IRQHandler
        PUBWEAK PCIE_CTRL1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PCIE_CTRL1_IRQHandler
        LDR     R0, =PCIE_CTRL1_DriverIRQHandler
        BX      R0

        PUBWEAK PCIE_CTRL1_ERR_IRQHandler
        PUBWEAK PCIE_CTRL1_ERR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PCIE_CTRL1_ERR_IRQHandler
        LDR     R0, =PCIE_CTRL1_ERR_DriverIRQHandler
        BX      R0

        PUBWEAK CAN_FD1_IRQHandler
        PUBWEAK CAN_FD1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN_FD1_IRQHandler
        LDR     R0, =CAN_FD1_DriverIRQHandler
        BX      R0

        PUBWEAK CAN_FD1_ERROR_IRQHandler
        PUBWEAK CAN_FD1_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN_FD1_ERROR_IRQHandler
        LDR     R0, =CAN_FD1_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK CAN_FD2_IRQHandler
        PUBWEAK CAN_FD2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN_FD2_IRQHandler
        LDR     R0, =CAN_FD2_DriverIRQHandler
        BX      R0

        PUBWEAK CAN_FD2_ERROR_IRQHandler
        PUBWEAK CAN_FD2_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN_FD2_ERROR_IRQHandler
        LDR     R0, =CAN_FD2_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK AUDIO_XCVR_IRQHandler
        PUBWEAK AUDIO_XCVR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
AUDIO_XCVR_IRQHandler
        LDR     R0, =AUDIO_XCVR_DriverIRQHandler
        BX      R0

        PUBWEAK DDR_ERR_IRQHandler
        PUBWEAK DDR_ERR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DDR_ERR_IRQHandler
        LDR     R0, =DDR_ERR_DriverIRQHandler
        BX      R0

        PUBWEAK USB1_WAKEUP_IRQHandler
        PUBWEAK USB1_WAKEUP_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USB1_WAKEUP_IRQHandler
        LDR     R0, =USB1_WAKEUP_DriverIRQHandler
        BX      R0

        PUBWEAK USB2_WAKEUP_IRQHandler
        PUBWEAK USB2_WAKEUP_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USB2_WAKEUP_IRQHandler
        LDR     R0, =USB2_WAKEUP_DriverIRQHandler
        BX      R0

        PUBWEAK MECC_IRQHandler
        PUBWEAK MECC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MECC_IRQHandler
        LDR     R0, =MECC_DriverIRQHandler
        BX      R0

        PUBWEAK MECC_ERR_IRQHandler
        PUBWEAK MECC_ERR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MECC_ERR_IRQHandler
        LDR     R0, =MECC_ERR_DriverIRQHandler
        BX      R0

        PUBWEAK MECC_S_IRQHandler
        PUBWEAK MECC_S_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MECC_S_IRQHandler
        LDR     R0, =MECC_S_DriverIRQHandler
        BX      R0

        PUBWEAK MECC_S_ERR_IRQHandler
        PUBWEAK MECC_S_ERR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MECC_S_ERR_IRQHandler
        LDR     R0, =MECC_S_ERR_DriverIRQHandler
        BX      R0

        PUBWEAK DefaultISR
        SECTION .text:CODE:REORDER:NOROOT(1)
Reserved16_DriverIRQHandler
DAP_DriverIRQHandler
SDMA1_DriverIRQHandler
GPU3D_DriverIRQHandler
SNVS_DriverIRQHandler
LCDIF1_DriverIRQHandler
LCDIF2_DriverIRQHandler
VPU_G1_DriverIRQHandler
VPU_G2_DriverIRQHandler
QOS_DriverIRQHandler
WDOG3_DriverIRQHandler
HS_CP1_DriverIRQHandler
APBHDMA_DriverIRQHandler
ML_DriverIRQHandler
BCH_DriverIRQHandler
GPMI_DriverIRQHandler
ISI_DriverIRQHandler
MIPI_CSI1_DriverIRQHandler
MIPI_DSI_DriverIRQHandler
SNVS_Consolidated_DriverIRQHandler
SNVS_Security_DriverIRQHandler
CSU_DriverIRQHandler
USDHC1_DriverIRQHandler
USDHC2_DriverIRQHandler
USDHC3_DriverIRQHandler
GPU2D_DriverIRQHandler
UART1_DriverIRQHandler
UART2_DriverIRQHandler
UART3_DriverIRQHandler
UART4_DriverIRQHandler
VPU_DriverIRQHandler
ECSPI1_DriverIRQHandler
ECSPI2_DriverIRQHandler
ECSPI3_DriverIRQHandler
SDMA3_DriverIRQHandler
I2C1_DriverIRQHandler
I2C2_DriverIRQHandler
I2C3_DriverIRQHandler
I2C4_DriverIRQHandler
RDC_DriverIRQHandler
USB1_DriverIRQHandler
USB2_DriverIRQHandler
ISI_CH1_DriverIRQHandler
HDMI_TX_DriverIRQHandler
PDM_HWVAD_EVENT_DriverIRQHandler
PDM_HWVAD_ERROR_DriverIRQHandler
GPT6_DriverIRQHandler
SCTR_IRQ0_DriverIRQHandler
SCTR_IRQ1_DriverIRQHandler
ANAMIX_DriverIRQHandler
I2S3_DriverIRQHandler
GPT5_DriverIRQHandler
GPT4_DriverIRQHandler
GPT3_DriverIRQHandler
GPT2_DriverIRQHandler
GPT1_DriverIRQHandler
GPIO1_INT7_DriverIRQHandler
GPIO1_INT6_DriverIRQHandler
GPIO1_INT5_DriverIRQHandler
GPIO1_INT4_DriverIRQHandler
GPIO1_INT3_DriverIRQHandler
GPIO1_INT2_DriverIRQHandler
GPIO1_INT1_DriverIRQHandler
GPIO1_INT0_DriverIRQHandler
GPIO1_Combined_0_15_DriverIRQHandler
GPIO1_Combined_16_31_DriverIRQHandler
GPIO2_Combined_0_15_DriverIRQHandler
GPIO2_Combined_16_31_DriverIRQHandler
GPIO3_Combined_0_15_DriverIRQHandler
GPIO3_Combined_16_31_DriverIRQHandler
GPIO4_Combined_0_15_DriverIRQHandler
GPIO4_Combined_16_31_DriverIRQHandler
GPIO5_Combined_0_15_DriverIRQHandler
GPIO5_Combined_16_31_DriverIRQHandler
ISP1_DriverIRQHandler
ISP2_DriverIRQHandler
I2C5_DriverIRQHandler
I2C6_DriverIRQHandler
WDOG1_DriverIRQHandler
WDOG2_DriverIRQHandler
MIPI_CSI2_DriverIRQHandler
PWM1_DriverIRQHandler
PWM2_DriverIRQHandler
PWM3_DriverIRQHandler
PWM4_DriverIRQHandler
CCM_IRQ1_DriverIRQHandler
CCM_IRQ2_DriverIRQHandler
GPC_DriverIRQHandler
MU1_A53_DriverIRQHandler
SRC_DriverIRQHandler
I2S56_DriverIRQHandler
RTIC_DriverIRQHandler
CPU_PerformanceUnit_DriverIRQHandler
CPU_CTI_Trigger_DriverIRQHandler
SRC_Combined_DriverIRQHandler
I2S1_DriverIRQHandler
I2S2_DriverIRQHandler
MU1_M7_DriverIRQHandler
DDR_PerformanceMonitor_DriverIRQHandler
DDR_DriverIRQHandler
DEWARP_DriverIRQHandler
CPU_Error_AXI_DriverIRQHandler
CPU_Error_L2RAM_DriverIRQHandler
SDMA2_DriverIRQHandler
SJC_DriverIRQHandler
CAAM_IRQ0_DriverIRQHandler
CAAM_IRQ1_DriverIRQHandler
FlexSPI_DriverIRQHandler
TZASC_DriverIRQHandler
PDM_EVENT_DriverIRQHandler
PDM_ERROR_DriverIRQHandler
I2S7_DriverIRQHandler
PERFMON1_DriverIRQHandler
PERFMON2_DriverIRQHandler
CAAM_IRQ2_DriverIRQHandler
CAAM_ERROR_DriverIRQHandler
HS_CP0_DriverIRQHandler
CM7_CTI_DriverIRQHandler
ENET1_MAC0_Rx_Tx_Done1_DriverIRQHandler
ENET1_MAC0_Rx_Tx_Done2_DriverIRQHandler
ENET1_DriverIRQHandler
ENET1_1588_Timer_DriverIRQHandler
ASRC_DriverIRQHandler
PCIE_CTRL1_0_DriverIRQHandler
PCIE_CTRL1_1_DriverIRQHandler
PCIE_CTRL1_2_DriverIRQHandler
PCIE_CTRL1_3_DriverIRQHandler
PCIE_EDMA_DriverIRQHandler
AUDIO_XCVR0_DriverIRQHandler
AUDIO_XCVR1_DriverIRQHandler
AUD2HTX_DriverIRQHandler
EDMA1_ERR_DriverIRQHandler
EDMA1_0_15_DriverIRQHandler
EDMA1_16_31_DriverIRQHandler
ENET_QOS_PMT_DriverIRQHandler
ENET_QOS_DriverIRQHandler
MU2_A53_DriverIRQHandler
MU2_AUDIO_DriverIRQHandler
MU3_M7_DriverIRQHandler
MU3_AUDIO_DriverIRQHandler
PCIE_CTRL1_DriverIRQHandler
PCIE_CTRL1_ERR_DriverIRQHandler
CAN_FD1_DriverIRQHandler
CAN_FD1_ERROR_DriverIRQHandler
CAN_FD2_DriverIRQHandler
CAN_FD2_ERROR_DriverIRQHandler
AUDIO_XCVR_DriverIRQHandler
DDR_ERR_DriverIRQHandler
USB1_WAKEUP_DriverIRQHandler
USB2_WAKEUP_DriverIRQHandler
MECC_DriverIRQHandler
MECC_ERR_DriverIRQHandler
MECC_S_DriverIRQHandler
MECC_S_ERR_DriverIRQHandler
DefaultISR
        B DefaultISR

        END
