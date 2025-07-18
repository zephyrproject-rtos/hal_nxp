/* ------------------------------------------------------------------------- */
/*  @file:    startup_MIMX94398_cm7_core1.s                                  */
/*  @purpose: CMSIS Cortex-M7 Core Device Startup File                       */
/*            MIMX94398_cm7_core1                                            */
/*  @version: 1.0                                                            */
/*  @date:    2023-11-1                                                      */
/*  @build:   b250109                                                        */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Copyright 1997-2016 Freescale Semiconductor, Inc.                         */
/* Copyright 2016-2025 NXP                                                   */
/* SPDX-License-Identifier: BSD-3-Clause                                     */
/*****************************************************************************/
/* Version: GCC for ARM Embedded Processors                                  */
/*****************************************************************************/
    .syntax unified
    .arch armv7-m

    .section .isr_vector, "a"
    .align 2
    .globl __isr_vector
__isr_vector:
    .long   __StackTop                                      /* Top of Stack */
    .long   Reset_Handler                                   /* Reset Handler */
    .long   NMI_Handler                                     /* NMI Handler*/
    .long   HardFault_Handler                               /* Hard Fault Handler*/
    .long   MemManage_Handler                               /* MPU Fault Handler*/
    .long   BusFault_Handler                                /* Bus Fault Handler*/
    .long   UsageFault_Handler                              /* Usage Fault Handler*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   SVC_Handler                                     /* SVCall Handler*/
    .long   DebugMon_Handler                                /* Debug Monitor Handler*/
    .long   0                                               /* Reserved*/
    .long   PendSV_Handler                                  /* PendSV Handler*/
    .long   SysTick_Handler                                 /* SysTick Handler*/

                                                            /* External Interrupts*/
    .long   Reserved16_IRQHandler                           /* Reserved interrupt*/
    .long   Reserved17_IRQHandler                           /* DAP interrupt*/
    .long   Reserved18_IRQHandler                           /* CTI trigger outputs from CM7 platform*/
    .long   Reserved19_IRQHandler                           /* CTI trigger outputs from CM33 platform*/
    .long   Reserved20_IRQHandler                           /* CTI trigger outputs from CA55 platform*/
    .long   Reserved21_IRQHandler                           /* Performance Unit Interrupts from CA55 platform*/
    .long   Reserved22_IRQHandler                           /* ECC error from CA55 platform cache*/
    .long   Reserved23_IRQHandler                           /* 1-bit or 2-bit ECC or Parity error from CA55 platform cache*/
    .long   Reserved24_IRQHandler                           /* CTI trigger outputs from CM7_1 platform*/
    .long   Reserved25_IRQHandler                           /* CTI trigger outputs from CM33_sync platform*/
    .long   CAN1_IRQHandler                                 /* CAN1 interrupt*/
    .long   CAN1_ERROR_IRQHandler                           /* CAN1 error interrupt*/
    .long   GPIO1_INT0_IRQHandler                           /* General Purpose Input/Output 1 interrupt 0*/
    .long   GPIO1_INT1_IRQHandler                           /* General Purpose Input/Output 1 interrupt 1*/
    .long   I3C1_IRQHandler                                 /* Improved Inter-Integrated Circuit 1 interrupt*/
    .long   LPI2C1_IRQHandler                               /* Low Power Inter-Integrated Circuit module 1*/
    .long   LPI2C2_IRQHandler                               /* Low Power Inter-Integrated Circuit module 2*/
    .long   LPIT1_IRQHandler                                /* Low Power Periodic Interrupt Timer 1*/
    .long   LPSPI1_IRQHandler                               /* Low Power Serial Peripheral Interface 1*/
    .long   LPSPI2_IRQHandler                               /* Low Power Serial Peripheral Interface 2*/
    .long   LPTMR1_IRQHandler                               /* Low Power Timer 1*/
    .long   LPUART1_IRQHandler                              /* Low Power UART 1*/
    .long   LPUART2_IRQHandler                              /* Low Power UART 2*/
    .long   Reserved39_IRQHandler                           /* AONMIX Sentinel MU0 SideA interrupt*/
    .long   Reserved40_IRQHandler                           /* AONMIX Sentinel MU1 SideA interrupt*/
    .long   Reserved41_IRQHandler                           /* AONMIX Sentinel MU2 SideA interrupt*/
    .long   Reserved42_IRQHandler                           /* AONMIX Sentinel MU3 SideA interrupt*/
    .long   Reserved43_IRQHandler                           /* AONMIX Sentinel MU4 SideA interrupt*/
    .long   Reserved44_IRQHandler                           /* AONMIX Sentinel MU5 SideA interrupt*/
    .long   Reserved45_IRQHandler                           /* AONMIX Sentinel MU6 SideA interrupt*/
    .long   Reserved46_IRQHandler                           /* AONMIX Sentinel MU7 SideA interrupt*/
    .long   Reserved47_IRQHandler                           /* AONMIX Sentinel MU8 SideA interrupt*/
    .long   V2X_FH_APCH0_IRQHandler                         /* V2X-FH MU APCH0 (APP0) interrupt*/
    .long   V2X_FH_APHSM1_IRQHandler                        /* V2X-FH MU APHSM1 (HSM1) interrupt*/
    .long   TPM1_IRQHandler                                 /* Timer PWM module 1*/
    .long   TPM2_IRQHandler                                 /* Timer PWM module 2*/
    .long   WDOG1_IRQHandler                                /* Watchdog 1 Interrupt*/
    .long   WDOG2_IRQHandler                                /* Watchdog 2 Interrupt*/
    .long   SAI1_IRQHandler                                 /* Serial Audio Interface 1*/
    .long   GPT1_IRQHandler                                 /* AONMIX GPT1*/
    .long   CAN2_IRQHandler                                 /* WAKEUPMIX CAN2 interrupt*/
    .long   CAN2_ERROR_IRQHandler                           /* WAKEUPMIX CAN2 error interrupt*/
    .long   CAN3_IRQHandler                                 /* WAKEUPMIX CAN3 interrupt*/
    .long   CAN3_ERROR_IRQHandler                           /* WAKEUPMIX CAN3 error interrupt*/
    .long   CAN4_IRQHandler                                 /* WAKEUPMIX CAN4 interrupt*/
    .long   CAN4_ERROR_IRQHandler                           /* WAKEUPMIX CAN4 error interrupt*/
    .long   CAN5_IRQHandler                                 /* WAKEUPMIX CAN5 interrupt*/
    .long   CAN5_ERROR_IRQHandler                           /* WAKEUPMIX CAN5 error interrupt*/
    .long   FLEXIO1_IRQHandler                              /* WAKEUPMIX Flexible IO 1 interrupt*/
    .long   FLEXIO2_IRQHandler                              /* WAKEUPMIX Flexible IO 2 interrupt*/
    .long   FLEXIO3_IRQHandler                              /* NETCMIX Flexible IO 3 interrupt*/
    .long   FLEXIO4_IRQHandler                              /* NETCMIX Flexible IO 4 interrupt*/
    .long   Reserved68_IRQHandler                           /* Earlier assigned for WAKEUPMIX XSPI1 interrupt*/
    .long   Reserved69_IRQHandler                           /* Earlier assigned for WAKEUPMIX XSPI2 interrupt*/
    .long   GPIO2_INT0_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 2 interrupt 0*/
    .long   GPIO2_INT1_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 2 interrupt 1*/
    .long   GPIO3_INT0_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 3 interrupt 0*/
    .long   GPIO3_INT1_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 3 interrupt 1*/
    .long   GPIO4_INT0_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 4 interrupt 0*/
    .long   GPIO4_INT1_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 4 interrupt 1*/
    .long   GPIO5_INT0_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 5 interrupt 0*/
    .long   GPIO5_INT1_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 5 interrupt 1*/
    .long   GPIO6_INT0_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 6 interrupt 0*/
    .long   GPIO6_INT1_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 6 interrupt 1*/
    .long   GPIO7_INT0_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 7 interrupt 0*/
    .long   GPIO7_INT1_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 7 interrupt 1*/
    .long   I3C2_IRQHandler                                 /* WAKEUPMIX Improved Inter-Integrated Circuit 2 interrupt*/
    .long   LPI2C3_IRQHandler                               /* WAKEUPMIX Low Power Inter-Integrated Circuit module 3*/
    .long   LPI2C4_IRQHandler                               /* WAKEUPMIX Low Power Inter-Integrated Circuit module 4*/
    .long   LPIT2_IRQHandler                                /* WAKEUPMIX Low Power Periodic Interrupt Timer 2*/
    .long   LPIT3_IRQHandler                                /* WAKEUPMIX Low Power Periodic Interrupt Timer 3*/
    .long   LPSPI3_IRQHandler                               /* WAKEUPMIX Low Power Serial Peripheral Interface 3*/
    .long   LPSPI4_IRQHandler                               /* WAKEUPMIX Low Power Serial Peripheral Interface 4*/
    .long   LPTMR2_IRQHandler                               /* WAKEUPMIX Low Power Timer 2*/
    .long   LPUART3_IRQHandler                              /* WAKEUPMIX Low Power UART 3*/
    .long   LPUART4_IRQHandler                              /* WAKEUPMIX Low Power UART 4*/
    .long   LPUART5_IRQHandler                              /* WAKEUPMIX Low Power UART 5*/
    .long   LPUART6_IRQHandler                              /* WAKEUPMIX Low Power UART 6*/
    .long   LPUART7_IRQHandler                              /* WAKEUPMIX Low Power UART 7*/
    .long   LPUART8_IRQHandler                              /* WAKEUPMIX Low Power UART 8*/
    .long   LPUART9_IRQHandler                              /* WAKEUPMIX Low Power UART 9*/
    .long   LPUART10_IRQHandler                             /* WAKEUPMIX Low Power UART 10*/
    .long   LPUART11_IRQHandler                             /* WAKEUPMIX Low Power UART 11*/
    .long   LPUART12_IRQHandler                             /* WAKEUPMIX Low Power UART 12*/
    .long   BBNSM_IRQHandler                                /* BBNSM Non-Secure interrupt*/
    .long   SYSCTR1_IRQHandler                              /* AONMIX System Counter compare interrupt*/
    .long   TPM3_IRQHandler                                 /* WAKEUPMIX Timer PWM module 3*/
    .long   TPM4_IRQHandler                                 /* WAKEUPMIX Timer PWM module 4*/
    .long   TPM5_IRQHandler                                 /* WAKEUPMIX Timer PWM module 5*/
    .long   TPM6_IRQHandler                                 /* WAKEUPMIX Timer PWM module 6*/
    .long   WDOG3_IRQHandler                                /* WAKEUPMIX Watchdog 3 Interrupt*/
    .long   WDOG4_IRQHandler                                /* WAKEUPMIX Watchdog 4 Interrupt*/
    .long   WDOG5_IRQHandler                                /* WAKEUPMIX Watchdog 5 Interrupt*/
    .long   WDOG6_IRQHandler                                /* WAKEUPMIX Watchdog 6 Interrupt*/
    .long   WDOG7_IRQHandler                                /* NETCMIX Watchdog 7 Interrupt*/
    .long   WDOG8_IRQHandler                                /* NETCMIX Watchdog 8 Interrupt*/
    .long   USDHC1_IRQHandler                               /* MEGAMIX uSDHC1 Enhanced SDHC Interrupt Request*/
    .long   USDHC2_IRQHandler                               /* MEGAMIX uSDHC2 Enhanced SDHC Interrupt Request*/
    .long   EDMA2_ERROR_IRQHandler                          /* WAKEUPMIX EDMA2 error interrupt*/
    .long   Reserved115_IRQHandler                          /* JTAGSW DAP MDM-AP SRC reset source*/
    .long   Reserved116_IRQHandler                          /* JTAGC SRC reset source (the JTAGC used for boundary scan, not JTAGC used for password authentication)*/
    .long   SAI2_IRQHandler                                 /* WAKEUPMIX SAI2 interrupt*/
    .long   SAI3_IRQHandler                                 /* WAKEUPMIX SAI3 interrupt*/
    .long   SAI4_IRQHandler                                 /* WAKEUPMIX SAI4 interrupt*/
    .long   LPSPI5_IRQHandler                               /* WAKEUPMIX LPSPI5 interrupt*/
    .long   LPSPI6_IRQHandler                               /* WAKEUPMIX LPSPI6 interrupt*/
    .long   LPSPI7_IRQHandler                               /* WAKEUPMIX LPSPI7 interrupt*/
    .long   LPSPI8_IRQHandler                               /* WAKEUPMIX LPSPI8 interrupt*/
    .long   LPI2C5_IRQHandler                               /* WAKEUPMIX LPI2C5 interrupt*/
    .long   LPI2C6_IRQHandler                               /* WAKEUPMIX LPI2C6 interrupt*/
    .long   LPI2C7_IRQHandler                               /* WAKEUPMIX LPI2C7 interrupt*/
    .long   LPI2C8_IRQHandler                               /* WAKEUPMIX LPI2C8 interrupt*/
    .long   PDM_HWVAD_ERROR_IRQHandler                      /* WAKEUPMIX PDM interrupt(hwvad err)*/
    .long   PDM_HWVAD_EVENT_IRQHandler                      /* WAKEUPMIX PDM interrupt(hwvad event)*/
    .long   PDM_ERROR_IRQHandler                            /* WAKEUPMIX PDM interrupt(mic err)*/
    .long   PDM_EVENT_IRQHandler                            /* WAKEUPMIX PDM interrupt(mic event)*/
    .long   USDHC3_IRQHandler                               /* MEGAMIX uSDHC3 Enhanced SDHC Interrupt Request*/
    .long   ADC_ER_IRQHandler                               /* WAKEUPMIX ADC1 interrupt(er)*/
    .long   ADC_WD_IRQHandler                               /* WAKEUPMIX ADC1 interrupt(wd)*/
    .long   ADC_EOC_IRQHandler                              /* WAKEUPMIX ADC1 interrupt(eoc)*/
    .long   Reserved136_IRQHandler                          /* I3C1 wakeup irq after double sync*/
    .long   Reserved137_IRQHandler                          /* I3C2 wakeup irq after double sync*/
    .long   MU5_A_IRQHandler                                /* AONMIX MU5 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU6_A_IRQHandler                                /* AONMIX MU6 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU7_A_IRQHandler                                /* AONMIX MU7 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU10_B_IRQHandler                               /* WAKEUPMIX MU10 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU11_B_IRQHandler                               /* WAKEUPMIX MU11 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU12_A_IRQHandler                               /* WAKEUPMIX MU12 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU13_A_IRQHandler                               /* WAKEUPMIX MU13 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU18_A_IRQHandler                               /* WAKEUPMIX MU18 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU18_B_IRQHandler                               /* WAKEUPMIX MU18 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU_E1_A_IRQHandler                              /* NETCMIX MU E1 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU_E2_A_IRQHandler                              /* NETCMIX MU E2 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU_E3_A_IRQHandler                              /* NETCMIX MU E3 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU_E4_A_IRQHandler                              /* NETCMIX MU E4 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   XSPI_SLV_IRQHandler                             /* WAKEUPMIX XSPI Responder*/
    .long   FCCU_INT0_IRQHandler                            /* AONMIX FCCU Interrupt Reaction 0*/
    .long   FCCU_INT1_IRQHandler                            /* AONMIX FCCU Interrupt Reaction 1*/
    .long   FCCU_INT2_IRQHandler                            /* AONMIX FCCU Interrupt Reaction 2*/
    .long   FCCU_INT3_IRQHandler                            /* AONMIX FCCU Interrupt Reaction 3(new interrupt for CM33_sync)*/
    .long   FCCU_INT4_IRQHandler                            /* AONMIX FCCU Interrupt Reaction 4(new interrupt for CM7_1)*/
    .long   STCU_IRQHandler                                 /* AONMIX STCU Selftest end Interrupt*/
    .long   XBAR1_CH0_CH1_IRQHandler                        /* XBAR1 interrupt 0 and 1*/
    .long   XBAR1_CH2_CH3_IRQHandler                        /* XBAR1 interrupt 2 and 3*/
    .long   GPT2_IRQHandler                                 /* WAKEUPMIX GPT2 interrupt*/
    .long   GPT3_IRQHandler                                 /* WAKEUPMIX GPT3 interrupt*/
    .long   GPT4_IRQHandler                                 /* WAKEUPMIX GPT4 interrupt*/
    .long   Reserved163_IRQHandler                          /* Endat2_1 interrupt/Hiperface1-DSL interrupt for safe events logged in EVENT_S register/Endat3 interrupt for background communication*/
    .long   Reserved164_IRQHandler                          /* Hiperface1-DSL interrupt for events logged in EVENT_H or EVENT_L register/Endat3 interrupt*/
    .long   Reserved165_IRQHandler                          /* Endat2_2  interrupt/Hiperface2-DSL interrupt for safe events logged in EVENT_S register/Biss interrupt for start of frame transmission*/
    .long   Reserved166_IRQHandler                          /* Hiperface2-DSL interrupt for events logged in EVENT_H or EVENT_L register/Biss interrupt for end of frame transmission*/
    .long   Reserved167_IRQHandler                          /* Flexpwm1(reload error, fault condition)*/
    .long   Reserved168_IRQHandler                          /* Flexpwm1(capt0, comp0, reload0)*/
    .long   Reserved169_IRQHandler                          /* Flexpwm1(capt1, comp1, reload1)*/
    .long   Reserved170_IRQHandler                          /* Flexpwm1(capt2, comp2, reload2)*/
    .long   Reserved171_IRQHandler                          /* Flexpwm1(capt3, comp3, reload3)*/
    .long   Reserved172_IRQHandler                          /* Flexpwm2(reload error, fault condition)*/
    .long   Reserved173_IRQHandler                          /* Flexpwm2(capt0, comp0, reload0)*/
    .long   Reserved174_IRQHandler                          /* Flexpwm2(capt1, comp1, reload1)*/
    .long   Reserved175_IRQHandler                          /* Flexpwm2(capt2, comp2, reload2)*/
    .long   Reserved176_IRQHandler                          /* Flexpwm2(capt3, comp3, reload3)*/
    .long   Reserved177_IRQHandler                          /* Flexpwm3(reload error, fault condition)*/
    .long   Reserved178_IRQHandler                          /* Flexpwm3(capt0, comp0, reload0)*/
    .long   Reserved179_IRQHandler                          /* Flexpwm3(capt1, comp1, reload1)*/
    .long   Reserved180_IRQHandler                          /* Flexpwm3(capt2, comp2, reload2)*/
    .long   Reserved181_IRQHandler                          /* Flexpwm3(capt3, comp3, reload3)*/
    .long   Reserved182_IRQHandler                          /* Flexpwm4(reload error, fault condition)*/
    .long   Reserved183_IRQHandler                          /* Flexpwm4(capt0, comp0, reload0)*/
    .long   Reserved184_IRQHandler                          /* Flexpwm4(capt1, comp1, reload1)*/
    .long   Reserved185_IRQHandler                          /* Flexpwm4(capt2, comp2, reload2)*/
    .long   Reserved186_IRQHandler                          /* Flexpwm4(capt3, comp3, reload3)*/
    .long   ENC1_IRQHandler                                 /* Quad dec1 interrupt*/
    .long   ENC2_IRQHandler                                 /* Quad dec2 interrupt*/
    .long   ENC3_IRQHandler                                 /* Quad dec3 interrupt*/
    .long   ENC4_IRQHandler                                 /* Quad dec4 interrupt*/
    .long   EWM_IRQHandler                                  /* Ewm out interrupt*/
    .long   Reserved192_IRQHandler                          /* Ethercat interrupt(PDI_OPB)*/
    .long   Reserved193_IRQHandler                          /* Ethercat interrupt(RESET_OUT)*/
    .long   Reserved194_IRQHandler                          /* Ethercat interrupt(SYNC_OUT0)*/
    .long   Reserved195_IRQHandler                          /* Ethercat interrupt(SYNC_OUT1)*/
    .long   USB1_IRQHandler                                 /* USB-1(USB 3.0 Controller) interrupt*/
    .long   USB2_IRQHandler                                 /* USB-2(USB 2.0 Controller) interrupt*/
    .long   SINC1_CH0_IRQHandler                            /* SINC Filter1(sinc filter glue1) Channel 0 interrupt*/
    .long   SINC1_CH1_IRQHandler                            /* SINC Filter1(sinc filter glue1) Channel 1 interrupt*/
    .long   SINC1_CH2_IRQHandler                            /* SINC Filter1(sinc filter glue1) Channel 2 interrupt*/
    .long   SINC1_CH3_IRQHandler                            /* SINC Filter1(sinc filter glue1) Channel 3 interrupt*/
    .long   SINC2_CH0_IRQHandler                            /* SINC Filter2(sinc filter glue2) Channel 0 interrupt*/
    .long   SINC2_CH1_IRQHandler                            /* SINC Filter2(sinc filter glue2) Channel 1 interrupt*/
    .long   SINC2_CH2_IRQHandler                            /* SINC Filter2(sinc filter glue2) Channel 2 interrupt*/
    .long   SINC2_CH3_IRQHandler                            /* SINC Filter2(sinc filter glue2) Channel 3 interrupt*/
    .long   SINC3_CH0_IRQHandler                            /* SINC Filter3(sinc filter glue3 Channel 0 interrupt*/
    .long   SINC3_CH1_IRQHandler                            /* SINC Filter3(sinc filter glue3) Channel 1 interrupt*/
    .long   SINC3_CH2_IRQHandler                            /* SINC Filter3(sinc filter glue3) Channel 2 interrupt*/
    .long   SINC3_CH3_IRQHandler                            /* SINC Filter3(sinc filter glue3) Channel 3 interrupt*/
    .long   SINC4_CH0_IRQHandler                            /* SINC Filter4(sinc filter glue4 Channel 0 interrupt*/
    .long   SINC4_CH1_IRQHandler                            /* SINC Filter4(sinc filter glue4) Channel 1 interrupt*/
    .long   SINC4_CH2_IRQHandler                            /* SINC Filter4(sinc filter glue4) Channel 2 interrupt*/
    .long   SINC4_CH3_IRQHandler                            /* SINC Filter4(sinc filter glue4) Channel 3 interrupt*/
    .long   TMR1_IRQHandler                                 /* QTIMER1 interrupt*/
    .long   TMR2_IRQHandler                                 /* QTIMER2 interrupt*/
    .long   TMR3_IRQHandler                                 /* QTIMER3 interrupt*/
    .long   TMR4_IRQHandler                                 /* QTIMER4 interrupt*/
    .long   TMR5_IRQHandler                                 /* QTIMER5 interrupt*/
    .long   TMR6_IRQHandler                                 /* QTIMER6 interrupt*/
    .long   TMR7_IRQHandler                                 /* QTIMER7 interrupt*/
    .long   TMR8_IRQHandler                                 /* QTIMER8 interrupt*/
    .long   EDMA4_ERROR_IRQHandler                          /* EDMA4 error interrupt*/
    .long   Reserved223_IRQHandler                          /* Anamix Gllitch Detector output (da_ip_voltage_glitch_detector_cln16ffc). It's a latch signal. It can be cleared.*/
    .long   Reserved224_IRQHandler                          /* Anamix VDET output (da_ip_vdetect_c16ffc). Detects high threshold on Core supply. It's a latch signal. It can be cleared.*/
    .long   Reserved225_IRQHandler                          /* Anamix VDET output (da_ip_vdetect_c16ffc). Detects Low threshold on Core supply. It's a latch signal. It can be cleared*/
    .long   Reserved226_IRQHandler                          /* LPCG Timeout interrupt generated by CCGR (CCM)*/
    .long   Reserved227_IRQHandler                          /* Reserved227*/
    .long   Reserved228_IRQHandler                          /* Reserved228*/
    .long   Reserved229_IRQHandler                          /* Reserved229*/
    .long   Reserved230_IRQHandler                          /* Reserved230*/
    .long   Reserved231_IRQHandler                          /* Reserved231*/
    .long   Reserved232_IRQHandler                          /* Reserved232*/
    .long   Reserved233_IRQHandler                          /* Reserved233*/
    .long   Reserved234_IRQHandler                          /* Reserved234*/
    .long   Reserved235_IRQHandler                          /* Reserved235*/
    .long   Reserved236_IRQHandler                          /* Reserved236*/
    .long   Reserved237_IRQHandler                          /* Reserved237*/
    .long   Reserved238_IRQHandler                          /* Reserved238*/
    .long   Reserved239_IRQHandler                          /* Reserved239*/
    .long   IRQSTEERM7_CH0_IRQHandler                       /* IRQSTEERM7 output channel 0 interrupt*/
    .long   IRQSTEERM7_CH1_IRQHandler                       /* IRQSTEERM7 output channel 1 interrupt*/
    .long   IRQSTEERM7_CH2_IRQHandler                       /* IRQSTEERM7 output channel 2 interrupt*/
    .long   IRQSTEERM7_CH3_IRQHandler                       /* IRQSTEERM7 output channel 3 interrupt*/
    .long   IRQSTEERM7_CH4_IRQHandler                       /* IRQSTEERM7 output channel 4 interrupt*/
    .long   IRQSTEERM7_CH5_IRQHandler                       /* IRQSTEERM7 output channel 5 interrupt*/
    .long   IRQSTEERM7_CH6_IRQHandler                       /* IRQSTEERM7 output channel 6 interrupt*/
    .long   IRQSTEERM7_CH7_IRQHandler                       /* IRQSTEERM7 output channel 7 interrupt*/
    .long   IRQSTEERM7_CH8_IRQHandler                       /* IRQSTEERM7 output channel 8 interrupt*/
    .long   IRQSTEERM7_CH9_IRQHandler                       /* IRQSTEERM7 output channel 9 interrupt*/
    .long   IRQSTEERM7_CH10_IRQHandler                      /* IRQSTEERM7 output channel 10 interrupt*/
    .long   IRQSTEERM7_CH11_IRQHandler                      /* IRQSTEERM7 output channel 11 interrupt*/
    .long   IRQSTEERM7_CH12_IRQHandler                      /* IRQSTEERM7 output channel 12 interrupt*/
    .long   Reserved253_IRQHandler                          /* Global fault event Module=NETC IRQ=237*/
    .long   EDMA2_CH0_IRQHandler                            /* WAKEUPMIX EDMA2 channel 0 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[0] - inputs[0]) IRQ=238*/
    .long   EDMA2_CH1_IRQHandler                            /* WAKEUPMIX EDMA2 channel 1 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[1] - inputs[1]) IRQ=239*/
    .long   EDMA2_CH2_IRQHandler                            /* WAKEUPMIX EDMA2 channel 2 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[2] - inputs[2]) IRQ=240*/
    .long   EDMA2_CH3_IRQHandler                            /* WAKEUPMIX EDMA2 channel 3 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[3] - inputs[3]) IRQ=241*/
    .long   EDMA2_CH4_IRQHandler                            /* WAKEUPMIX EDMA2 channel 4 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[4] - inputs[4]) IRQ=242*/
    .long   EDMA2_CH5_IRQHandler                            /* WAKEUPMIX EDMA2 channel 5 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[5] - inputs[5]) IRQ=243*/
    .long   EDMA2_CH6_IRQHandler                            /* WAKEUPMIX EDMA2 channel 6 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[6] - inputs[6]) IRQ=244*/
    .long   EDMA2_CH7_IRQHandler                            /* WAKEUPMIX EDMA2 channel 7 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[7] - inputs[7]) IRQ=245*/
    .long   EDMA2_CH8_IRQHandler                            /* WAKEUPMIX EDMA2 channel 8 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[8] - inputs[8]) IRQ=246*/
    .long   EDMA2_CH9_IRQHandler                            /* WAKEUPMIX EDMA2 channel 9 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[9] - inputs[9]) IRQ=247*/
    .long   EDMA2_CH10_IRQHandler                           /* WAKEUPMIX EDMA2 channel 10 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[10] - inputs[10]) IRQ=248*/
    .long   EDMA2_CH11_IRQHandler                           /* WAKEUPMIX EDMA2 channel 11 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[11] - inputs[11]) IRQ=249*/
    .long   EDMA2_CH12_IRQHandler                           /* WAKEUPMIX EDMA2 channel 12 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[12] - inputs[12]) IRQ=250*/
    .long   EDMA2_CH13_IRQHandler                           /* WAKEUPMIX EDMA2 channel 13 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[13] - inputs[13]) IRQ=251*/
    .long   EDMA2_CH14_IRQHandler                           /* WAKEUPMIX EDMA2 channel 14 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[14] - inputs[14]) IRQ=252*/
    .long   EDMA2_CH15_IRQHandler                           /* WAKEUPMIX EDMA2 channel 15 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[15] - inputs[15]) IRQ=253*/
    .long   EDMA2_CH16_IRQHandler                           /* WAKEUPMIX EDMA2 channel 16 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[16] - inputs[16]) IRQ=254*/
    .long   EDMA2_CH17_IRQHandler                           /* WAKEUPMIX EDMA2 channel 17 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[17] - inputs[17]) IRQ=255*/
    .long   EDMA2_CH18_IRQHandler                           /* WAKEUPMIX EDMA2 channel 18 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[18] - inputs[18]) IRQ=256*/
    .long   EDMA2_CH19_IRQHandler                           /* WAKEUPMIX EDMA2 channel 19 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[19] - inputs[19]) IRQ=257*/
    .long   EDMA2_CH20_IRQHandler                           /* WAKEUPMIX EDMA2 channel 20 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[20] - inputs[20]) IRQ=258*/
    .long   EDMA2_CH21_IRQHandler                           /* WAKEUPMIX EDMA2 channel 21 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[21] - inputs[21]) IRQ=259*/
    .long   EDMA2_CH22_IRQHandler                           /* WAKEUPMIX EDMA2 channel 22 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[22] - inputs[22]) IRQ=260*/
    .long   EDMA2_CH23_IRQHandler                           /* WAKEUPMIX EDMA2 channel 23 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[23] - inputs[23]) IRQ=261*/
    .long   EDMA2_CH24_IRQHandler                           /* WAKEUPMIX EDMA2 channel 24 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[24] - inputs[24]) IRQ=262*/
    .long   EDMA2_CH25_IRQHandler                           /* WAKEUPMIX EDMA2 channel 25 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[25] - inputs[25]) IRQ=263*/
    .long   EDMA2_CH26_IRQHandler                           /* WAKEUPMIX EDMA2 channel 26 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[26] - inputs[26]) IRQ=264*/
    .long   EDMA2_CH27_IRQHandler                           /* WAKEUPMIX EDMA2 channel 27 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[27] - inputs[27]) IRQ=265*/
    .long   EDMA2_CH28_IRQHandler                           /* WAKEUPMIX EDMA2 channel 28 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[28] - inputs[28]) IRQ=266*/
    .long   EDMA2_CH29_IRQHandler                           /* WAKEUPMIX EDMA2 channel 29 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[29] - inputs[29]) IRQ=267*/
    .long   EDMA2_CH30_IRQHandler                           /* WAKEUPMIX EDMA2 channel 30 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[30] - inputs[30]) IRQ=268*/
    .long   EDMA2_CH31_IRQHandler                           /* WAKEUPMIX EDMA2 channel 31 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[31] - inputs[31]) IRQ=269*/
    .long   EDMA2_CH32_IRQHandler                           /* WAKEUPMIX EDMA2 channel 32 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[32] - inputs[32]) IRQ=270*/
    .long   EDMA2_CH33_IRQHandler                           /* WAKEUPMIX EDMA2 channel 33 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[33] - inputs[33]) IRQ=271*/
    .long   EDMA2_CH34_IRQHandler                           /* WAKEUPMIX EDMA2 channel 34 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[34] - inputs[34]) IRQ=272*/
    .long   EDMA2_CH35_IRQHandler                           /* WAKEUPMIX EDMA2 channel 35 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[35] - inputs[35]) IRQ=273*/
    .long   EDMA2_CH36_IRQHandler                           /* WAKEUPMIX EDMA2 channel 36 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[36] - inputs[36]) IRQ=274*/
    .long   EDMA2_CH37_IRQHandler                           /* WAKEUPMIX EDMA2 channel 37 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[37] - inputs[37]) IRQ=275*/
    .long   EDMA2_CH38_IRQHandler                           /* WAKEUPMIX EDMA2 channel 38 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[38] - inputs[38]) IRQ=276*/
    .long   EDMA2_CH39_IRQHandler                           /* WAKEUPMIX EDMA2 channel 39 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[39] - inputs[39]) IRQ=277*/
    .long   EDMA2_CH40_IRQHandler                           /* WAKEUPMIX EDMA2 channel 40 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[40] - inputs[40]) IRQ=278*/
    .long   EDMA2_CH41_IRQHandler                           /* WAKEUPMIX EDMA2 channel 41 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[41] - inputs[41]) IRQ=279*/
    .long   EDMA2_CH42_IRQHandler                           /* WAKEUPMIX EDMA2 channel 42 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[42] - inputs[42]) IRQ=280*/
    .long   EDMA2_CH43_IRQHandler                           /* WAKEUPMIX EDMA2 channel 43 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[43] - inputs[43]) IRQ=281*/
    .long   EDMA2_CH44_IRQHandler                           /* WAKEUPMIX EDMA2 channel 44 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[44] - inputs[44]) IRQ=282*/
    .long   EDMA2_CH45_IRQHandler                           /* WAKEUPMIX EDMA2 channel 45 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[45] - inputs[45]) IRQ=283*/
    .long   EDMA2_CH46_IRQHandler                           /* WAKEUPMIX EDMA2 channel 46 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[46] - inputs[46]) IRQ=284*/
    .long   EDMA2_CH47_IRQHandler                           /* WAKEUPMIX EDMA2 channel 47 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[47] - inputs[47]) IRQ=285*/
    .long   EDMA2_CH48_IRQHandler                           /* WAKEUPMIX EDMA2 channel 48 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[48] - inputs[48]) IRQ=286*/
    .long   EDMA2_CH49_IRQHandler                           /* WAKEUPMIX EDMA2 channel 49 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[49] - inputs[49]) IRQ=287*/
    .long   EDMA2_CH50_IRQHandler                           /* WAKEUPMIX EDMA2 channel 50 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[50] - inputs[50]) IRQ=288*/
    .long   EDMA2_CH51_IRQHandler                           /* WAKEUPMIX EDMA2 channel 51 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[51] - inputs[51]) IRQ=289*/
    .long   EDMA2_CH52_IRQHandler                           /* WAKEUPMIX EDMA2 channel 52 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[52] - inputs[52]) IRQ=290*/
    .long   EDMA2_CH53_IRQHandler                           /* WAKEUPMIX EDMA2 channel 53 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[53] - inputs[53]) IRQ=291*/
    .long   EDMA2_CH54_IRQHandler                           /* WAKEUPMIX EDMA2 channel 54 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[54] - inputs[54]) IRQ=292*/
    .long   EDMA2_CH55_IRQHandler                           /* WAKEUPMIX EDMA2 channel 55 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[55] - inputs[55]) IRQ=293*/
    .long   EDMA2_CH56_IRQHandler                           /* WAKEUPMIX EDMA2 channel 56 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[56] - inputs[56]) IRQ=294*/
    .long   EDMA2_CH57_IRQHandler                           /* WAKEUPMIX EDMA2 channel 57 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[57] - inputs[57]) IRQ=295*/
    .long   EDMA2_CH58_IRQHandler                           /* WAKEUPMIX EDMA2 channel 58 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[58] - inputs[58]) IRQ=296*/
    .long   EDMA2_CH59_IRQHandler                           /* WAKEUPMIX EDMA2 channel 59 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[59] - inputs[59]) IRQ=297*/
    .long   EDMA2_CH60_IRQHandler                           /* WAKEUPMIX EDMA2 channel 60 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[60] - inputs[60]) IRQ=298*/
    .long   EDMA2_CH61_IRQHandler                           /* WAKEUPMIX EDMA2 channel 61 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[61] - inputs[61]) IRQ=299*/
    .long   EDMA2_CH62_IRQHandler                           /* WAKEUPMIX EDMA2 channel 62 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[62] - inputs[62]) IRQ=300*/
    .long   EDMA2_CH63_IRQHandler                           /* WAKEUPMIX EDMA2 channel 63 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[63] - inputs[63]) IRQ=301*/
    .long   EDMA4_CH0_IRQHandler                            /* WAKEUPMIX EDMA4 channel 0 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[0] - inputs[64]) IRQ=302*/
    .long   EDMA4_CH1_IRQHandler                            /* WAKEUPMIX EDMA4 channel 1 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[1] - inputs[65]) IRQ=303*/
    .long   EDMA4_CH2_IRQHandler                            /* WAKEUPMIX EDMA4 channel 2 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[2] - inputs[66]) IRQ=304*/
    .long   EDMA4_CH3_IRQHandler                            /* WAKEUPMIX EDMA4 channel 3 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[3] - inputs[67]) IRQ=305*/
    .long   EDMA4_CH4_IRQHandler                            /* WAKEUPMIX EDMA4 channel 4 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[4] - inputs[68]) IRQ=306*/
    .long   EDMA4_CH5_IRQHandler                            /* WAKEUPMIX EDMA4 channel 5 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[5] - inputs[69]) IRQ=307*/
    .long   EDMA4_CH6_IRQHandler                            /* WAKEUPMIX EDMA4 channel 6 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[6] - inputs[70]) IRQ=308*/
    .long   EDMA4_CH7_IRQHandler                            /* WAKEUPMIX EDMA4 channel 7 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[7] - inputs[71]) IRQ=309*/
    .long   EDMA4_CH8_IRQHandler                            /* WAKEUPMIX EDMA4 channel 8 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[8] - inputs[72]) IRQ=310*/
    .long   EDMA4_CH9_IRQHandler                            /* WAKEUPMIX EDMA4 channel 9 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[9] - inputs[73]) IRQ=311*/
    .long   EDMA4_CH10_IRQHandler                           /* WAKEUPMIX EDMA4 channel 10 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[10] - inputs[74]) IRQ=312*/
    .long   EDMA4_CH11_IRQHandler                           /* WAKEUPMIX EDMA4 channel 11 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[11] - inputs[75]) IRQ=313*/
    .long   EDMA4_CH12_IRQHandler                           /* WAKEUPMIX EDMA4 channel 12 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[12] - inputs[76]) IRQ=314*/
    .long   EDMA4_CH13_IRQHandler                           /* WAKEUPMIX EDMA4 channel 13 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[13] - inputs[77]) IRQ=315*/
    .long   EDMA4_CH14_IRQHandler                           /* WAKEUPMIX EDMA4 channel 14 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[14] - inputs[78]) IRQ=316*/
    .long   EDMA4_CH15_IRQHandler                           /* WAKEUPMIX EDMA4 channel 15 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[15] - inputs[79]) IRQ=317*/
    .long   EDMA4_CH16_IRQHandler                           /* WAKEUPMIX EDMA4 channel 16 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[16] - inputs[80]) IRQ=318*/
    .long   EDMA4_CH17_IRQHandler                           /* WAKEUPMIX EDMA4 channel 17 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[17] - inputs[81]) IRQ=319*/
    .long   EDMA4_CH18_IRQHandler                           /* WAKEUPMIX EDMA4 channel 18 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[18] - inputs[82]) IRQ=320*/
    .long   EDMA4_CH19_IRQHandler                           /* WAKEUPMIX EDMA4 channel 19 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[19] - inputs[83]) IRQ=321*/
    .long   EDMA4_CH20_IRQHandler                           /* WAKEUPMIX EDMA4 channel 20 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[20] - inputs[84]) IRQ=322*/
    .long   EDMA4_CH21_IRQHandler                           /* WAKEUPMIX EDMA4 channel 21 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[21] - inputs[85]) IRQ=323*/
    .long   EDMA4_CH22_IRQHandler                           /* WAKEUPMIX EDMA4 channel 22 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[22] - inputs[86]) IRQ=324*/
    .long   EDMA4_CH23_IRQHandler                           /* WAKEUPMIX EDMA4 channel 23 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[23] - inputs[87]) IRQ=325*/
    .long   EDMA4_CH24_IRQHandler                           /* WAKEUPMIX EDMA4 channel 24 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[24] - inputs[88]) IRQ=326*/
    .long   EDMA4_CH25_IRQHandler                           /* WAKEUPMIX EDMA4 channel 25 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[25] - inputs[89]) IRQ=327*/
    .long   EDMA4_CH26_IRQHandler                           /* WAKEUPMIX EDMA4 channel 26 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[26] - inputs[90]) IRQ=328*/
    .long   EDMA4_CH27_IRQHandler                           /* WAKEUPMIX EDMA4 channel 27 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[27] - inputs[91]) IRQ=329*/
    .long   EDMA4_CH28_IRQHandler                           /* WAKEUPMIX EDMA4 channel 28 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[28] - inputs[92]) IRQ=330*/
    .long   EDMA4_CH29_IRQHandler                           /* WAKEUPMIX EDMA4 channel 29 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[29] - inputs[93]) IRQ=331*/
    .long   EDMA4_CH30_IRQHandler                           /* WAKEUPMIX EDMA4 channel 30 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[30] - inputs[94]) IRQ=332*/
    .long   EDMA4_CH31_IRQHandler                           /* WAKEUPMIX EDMA4 channel 31 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[31] - inputs[95]) IRQ=333*/
    .long   EDMA4_CH32_IRQHandler                           /* WAKEUPMIX EDMA4 channel 32 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[32] - inputs[96]) IRQ=334*/
    .long   EDMA4_CH33_IRQHandler                           /* WAKEUPMIX EDMA4 channel 33 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[33] - inputs[97]) IRQ=335*/
    .long   EDMA4_CH34_IRQHandler                           /* WAKEUPMIX EDMA4 channel 34 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[34] - inputs[98]) IRQ=336*/
    .long   EDMA4_CH35_IRQHandler                           /* WAKEUPMIX EDMA4 channel 35 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[35] - inputs[99]) IRQ=337*/
    .long   EDMA4_CH36_IRQHandler                           /* WAKEUPMIX EDMA4 channel 36 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[36] - inputs[100]) IRQ=338*/
    .long   EDMA4_CH37_IRQHandler                           /* WAKEUPMIX EDMA4 channel 37 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[37] - inputs[101]) IRQ=339*/
    .long   EDMA4_CH38_IRQHandler                           /* WAKEUPMIX EDMA4 channel 38 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[38] - inputs[102]) IRQ=340*/
    .long   EDMA4_CH39_IRQHandler                           /* WAKEUPMIX EDMA4 channel 39 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[39] - inputs[103]) IRQ=341*/
    .long   EDMA4_CH40_IRQHandler                           /* WAKEUPMIX EDMA4 channel 40 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[40] - inputs[104]) IRQ=342*/
    .long   EDMA4_CH41_IRQHandler                           /* WAKEUPMIX EDMA4 channel 41 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[41] - inputs[105]) IRQ=343*/
    .long   EDMA4_CH42_IRQHandler                           /* WAKEUPMIX EDMA4 channel 42 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[42] - inputs[106]) IRQ=344*/
    .long   EDMA4_CH43_IRQHandler                           /* WAKEUPMIX EDMA4 channel 43 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[43] - inputs[107]) IRQ=345*/
    .long   EDMA4_CH44_IRQHandler                           /* WAKEUPMIX EDMA4 channel 44 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[44] - inputs[108]) IRQ=346*/
    .long   EDMA4_CH45_IRQHandler                           /* WAKEUPMIX EDMA4 channel 45 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[45] - inputs[109]) IRQ=347*/
    .long   EDMA4_CH46_IRQHandler                           /* WAKEUPMIX EDMA4 channel 46 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[46] - inputs[110]) IRQ=348*/
    .long   EDMA4_CH47_IRQHandler                           /* WAKEUPMIX EDMA4 channel 47 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[47] - inputs[111]) IRQ=349*/
    .long   EDMA4_CH48_IRQHandler                           /* WAKEUPMIX EDMA4 channel 48 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[48] - inputs[112]) IRQ=350*/
    .long   EDMA4_CH49_IRQHandler                           /* WAKEUPMIX EDMA4 channel 49 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[49] - inputs[113]) IRQ=351*/
    .long   EDMA4_CH50_IRQHandler                           /* WAKEUPMIX EDMA4 channel 50 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[50] - inputs[114]) IRQ=352*/
    .long   EDMA4_CH51_IRQHandler                           /* WAKEUPMIX EDMA4 channel 51 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[51] - inputs[115]) IRQ=353*/
    .long   EDMA4_CH52_IRQHandler                           /* WAKEUPMIX EDMA4 channel 52 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[52] - inputs[116]) IRQ=354*/
    .long   EDMA4_CH53_IRQHandler                           /* WAKEUPMIX EDMA4 channel 53 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[53] - inputs[117]) IRQ=355*/
    .long   EDMA4_CH54_IRQHandler                           /* WAKEUPMIX EDMA4 channel 54 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[54] - inputs[118]) IRQ=356*/
    .long   EDMA4_CH55_IRQHandler                           /* WAKEUPMIX EDMA4 channel 55 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[55] - inputs[119]) IRQ=357*/
    .long   EDMA4_CH56_IRQHandler                           /* WAKEUPMIX EDMA4 channel 56 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[56] - inputs[120]) IRQ=358*/
    .long   EDMA4_CH57_IRQHandler                           /* WAKEUPMIX EDMA4 channel 57 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[57] - inputs[121]) IRQ=359*/
    .long   EDMA4_CH58_IRQHandler                           /* WAKEUPMIX EDMA4 channel 58 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[58] - inputs[122]) IRQ=360*/
    .long   EDMA4_CH59_IRQHandler                           /* WAKEUPMIX EDMA4 channel 59 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[59] - inputs[123]) IRQ=361*/
    .long   EDMA4_CH60_IRQHandler                           /* WAKEUPMIX EDMA4 channel 60 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[60] - inputs[124]) IRQ=362*/
    .long   EDMA4_CH61_IRQHandler                           /* WAKEUPMIX EDMA4 channel 61 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[61] - inputs[125]) IRQ=363*/
    .long   EDMA4_CH62_IRQHandler                           /* WAKEUPMIX EDMA4 channel 62 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[62] - inputs[126]) IRQ=364*/
    .long   EDMA4_CH63_IRQHandler                           /* WAKEUPMIX EDMA4 channel 63 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[63] - inputs[127]) IRQ=365*/
    .long   EDMA3_CH0_IRQHandler                            /* WAKEUPMIX ACP EDMA channel 0 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[0] - inputs[128]) IRQ=366*/
    .long   EDMA3_CH1_IRQHandler                            /* WAKEUPMIX ACP EDMA channel 1 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[1] - inputs[129]) IRQ=367*/
    .long   EDMA3_CH2_IRQHandler                            /* WAKEUPMIX ACP EDMA channel 2 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[2] - inputs[130]) IRQ=368*/
    .long   EDMA3_CH3_IRQHandler                            /* WAKEUPMIX ACP EDMA channel 3 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[3] - inputs[131]) IRQ=369*/
    .long   EDMA3_CH4_IRQHandler                            /* WAKEUPMIX ACP EDMA channel 4 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[4] - inputs[132]) IRQ=370*/
    .long   EDMA3_CH5_IRQHandler                            /* WAKEUPMIX ACP EDMA channel 5 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[5] - inputs[133]) IRQ=371*/
    .long   EDMA3_CH6_IRQHandler                            /* WAKEUPMIX ACP EDMA channel 6 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[6] - inputs[134]) IRQ=372*/
    .long   EDMA3_CH7_IRQHandler                            /* WAKEUPMIX ACP EDMA channel 7 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[7] - inputs[135]) IRQ=373*/
    .long   EDMA3_CH8_IRQHandler                            /* WAKEUPMIX ACP EDMA channel 8 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[8] - inputs[136]) IRQ=374*/
    .long   EDMA3_CH9_IRQHandler                            /* WAKEUPMIX ACP EDMA channel 9 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[9] - inputs[137]) IRQ=375*/
    .long   EDMA3_CH10_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 10 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[10] - inputs[138]) IRQ=376*/
    .long   EDMA3_CH11_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 11 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[11] - inputs[139]) IRQ=377*/
    .long   EDMA3_CH12_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 12 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[12] - inputs[140]) IRQ=378*/
    .long   EDMA3_CH13_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 13 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[13] - inputs[141]) IRQ=379*/
    .long   EDMA3_CH14_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 14 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[14] - inputs[142]) IRQ=380*/
    .long   EDMA3_CH15_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 15 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[15] - inputs[143]) IRQ=381*/
    .long   EDMA3_CH16_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 16 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[16] - inputs[144]) IRQ=382*/
    .long   EDMA3_CH17_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 17 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[17] - inputs[145]) IRQ=383*/
    .long   EDMA3_CH18_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 18 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[18] - inputs[146]) IRQ=384*/
    .long   EDMA3_CH19_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 19 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[19] - inputs[147]) IRQ=385*/
    .long   EDMA3_CH20_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 20 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[20] - inputs[148]) IRQ=386*/
    .long   EDMA3_CH21_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 21 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[21] - inputs[149]) IRQ=387*/
    .long   EDMA3_CH22_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 22 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[22] - inputs[150]) IRQ=388*/
    .long   EDMA3_CH23_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 23 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[23] - inputs[151]) IRQ=389*/
    .long   EDMA3_CH24_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 24 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[24] - inputs[152]) IRQ=390*/
    .long   EDMA3_CH25_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 25 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[25] - inputs[153]) IRQ=391*/
    .long   EDMA3_CH26_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 26 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[26] - inputs[154]) IRQ=392*/
    .long   EDMA3_CH27_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 27 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[27] - inputs[155]) IRQ=393*/
    .long   EDMA3_CH28_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 28 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[28] - inputs[156]) IRQ=394*/
    .long   EDMA3_CH29_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 29 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[29] - inputs[157]) IRQ=395*/
    .long   EDMA3_CH30_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 30 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[30] - inputs[158]) IRQ=396*/
    .long   EDMA3_CH31_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 31 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[31] - inputs[159]) IRQ=397*/
    .long   EDMA3_CH32_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 32 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[32] - inputs[160]) IRQ=398*/
    .long   EDMA3_CH33_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 33 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[33] - inputs[161]) IRQ=399*/
    .long   EDMA3_CH34_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 34 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[34] - inputs[162]) IRQ=400*/
    .long   EDMA3_CH35_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 35 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[35] - inputs[163]) IRQ=401*/
    .long   EDMA3_CH36_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 36 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[36] - inputs[164]) IRQ=402*/
    .long   EDMA3_CH37_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 37 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[37] - inputs[165]) IRQ=403*/
    .long   EDMA3_CH38_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 38 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[38] - inputs[166]) IRQ=404*/
    .long   EDMA3_CH39_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 39 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[39] - inputs[167]) IRQ=405*/
    .long   EDMA3_CH40_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 40 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[40] - inputs[168]) IRQ=406*/
    .long   EDMA3_CH41_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 41 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[41] - inputs[169]) IRQ=407*/
    .long   EDMA3_CH42_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 42 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[42] - inputs[170]) IRQ=408*/
    .long   EDMA3_CH43_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 43 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[43] - inputs[171]) IRQ=409*/
    .long   EDMA3_CH44_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 44 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[44] - inputs[172]) IRQ=410*/
    .long   EDMA3_CH45_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 45 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[45] - inputs[173]) IRQ=411*/
    .long   EDMA3_CH46_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 46 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[46] - inputs[174]) IRQ=412*/
    .long   EDMA3_CH47_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 47 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[47] - inputs[175]) IRQ=413*/
    .long   EDMA3_CH48_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 48 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[48] - inputs[176]) IRQ=414*/
    .long   EDMA3_CH49_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 49 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[49] - inputs[177]) IRQ=415*/
    .long   EDMA3_CH50_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 50 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[50] - inputs[178]) IRQ=416*/
    .long   EDMA3_CH51_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 51 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[51] - inputs[179]) IRQ=417*/
    .long   EDMA3_CH52_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 52 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[52] - inputs[180]) IRQ=418*/
    .long   EDMA3_CH53_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 53 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[53] - inputs[181]) IRQ=419*/
    .long   EDMA3_CH54_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 54 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[54] - inputs[182]) IRQ=420*/
    .long   EDMA3_CH55_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 55 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[55] - inputs[183]) IRQ=421*/
    .long   EDMA3_CH56_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 56 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[56] - inputs[184]) IRQ=422*/
    .long   EDMA3_CH57_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 57 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[57] - inputs[185]) IRQ=423*/
    .long   EDMA3_CH58_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 58 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[58] - inputs[186]) IRQ=424*/
    .long   EDMA3_CH59_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 59 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[59] - inputs[187]) IRQ=425*/
    .long   EDMA3_CH60_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 60 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[60] - inputs[188]) IRQ=426*/
    .long   EDMA3_CH61_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 61 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[61] - inputs[189]) IRQ=427*/
    .long   EDMA3_CH62_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 62 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[62] - inputs[190]) IRQ=428*/
    .long   EDMA3_CH63_IRQHandler                           /*  WAKEUPMIX ACP EDMA channel 63 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[63] - inputs[191]) IRQ=429*/
    .long   EDMA1_CH0_IRQHandler                            /* AONMIX EDMA channel 0 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[0] - inputs[192]) IRQ=430*/
    .long   EDMA1_CH1_IRQHandler                            /* AONMIX EDMA channel 1 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[1] - inputs[193]) IRQ=431*/
    .long   EDMA1_CH2_IRQHandler                            /* AONMIX EDMA channel 2 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[2] - inputs[194]) IRQ=432*/
    .long   EDMA1_CH3_IRQHandler                            /* AONMIX EDMA channel 3 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[3] - inputs[195]) IRQ=433*/
    .long   EDMA1_CH4_IRQHandler                            /* AONMIX EDMA channel 4 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[4] - inputs[196]) IRQ=434*/
    .long   EDMA1_CH5_IRQHandler                            /* AONMIX EDMA channel 5 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[5] - inputs[197]) IRQ=435*/
    .long   EDMA1_CH6_IRQHandler                            /* AONMIX EDMA channel 6 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[6] - inputs[198]) IRQ=436*/
    .long   EDMA1_CH7_IRQHandler                            /* AONMIX EDMA channel 7 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[7] - inputs[199]) IRQ=437*/
    .long   EDMA1_CH8_IRQHandler                            /* AONMIX EDMA channel 8 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[8] - inputs[200]) IRQ=438*/
    .long   EDMA1_CH9_IRQHandler                            /* AONMIX EDMA channel 9 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[9] - inputs[201]) IRQ=439*/
    .long   EDMA1_CH10_IRQHandler                           /* AONMIX EDMA channel 10 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[10] - inputs[202]) IRQ=440*/
    .long   EDMA1_CH11_IRQHandler                           /* AONMIX EDMA channel 11 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[11] - inputs[203]) IRQ=441*/
    .long   EDMA1_CH12_IRQHandler                           /* AONMIX EDMA channel 12 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[12] - inputs[204]) IRQ=442*/
    .long   EDMA1_CH13_IRQHandler                           /* AONMIX EDMA channel 13 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[13] - inputs[205]) IRQ=443*/
    .long   EDMA1_CH14_IRQHandler                           /* AONMIX EDMA channel 14 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[14] - inputs[206]) IRQ=444*/
    .long   EDMA1_CH15_IRQHandler                           /* AONMIX EDMA channel 15 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[15] - inputs[207]) IRQ=445*/
    .long   EDMA1_CH16_IRQHandler                           /* AONMIX EDMA channel 16 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[16] - inputs[208]) IRQ=446*/
    .long   EDMA1_CH17_IRQHandler                           /* AONMIX EDMA channel 17 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[17] - inputs[209]) IRQ=447*/
    .long   EDMA1_CH18_IRQHandler                           /* AONMIX EDMA channel 18 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[18] - inputs[210]) IRQ=448*/
    .long   EDMA1_CH19_IRQHandler                           /* AONMIX EDMA channel 19 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[19] - inputs[211]) IRQ=449*/
    .long   EDMA1_CH20_IRQHandler                           /* AONMIX EDMA channel 20 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[20] - inputs[212]) IRQ=450*/
    .long   EDMA1_CH21_IRQHandler                           /* AONMIX EDMA channel 21 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[21] - inputs[213]) IRQ=451*/
    .long   EDMA1_CH22_IRQHandler                           /* AONMIX EDMA channel 22 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[22] - inputs[214]) IRQ=452*/
    .long   EDMA1_CH23_IRQHandler                           /* AONMIX EDMA channel 23 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[23] - inputs[215]) IRQ=453*/
    .long   EDMA1_CH24_IRQHandler                           /* AONMIX EDMA channel 24 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[24] - inputs[216]) IRQ=454*/
    .long   EDMA1_CH25_IRQHandler                           /* AONMIX EDMA channel 25 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[25] - inputs[217]) IRQ=455*/
    .long   EDMA1_CH26_IRQHandler                           /* AONMIX EDMA channel 26 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[26] - inputs[218]) IRQ=456*/
    .long   EDMA1_CH27_IRQHandler                           /* AONMIX EDMA channel 27 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[27] - inputs[219]) IRQ=457*/
    .long   EDMA1_CH28_IRQHandler                           /* AONMIX EDMA channel 28 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[28] - inputs[220]) IRQ=458*/
    .long   EDMA1_CH29_IRQHandler                           /* AONMIX EDMA channel 29 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[29] - inputs[221]) IRQ=459*/
    .long   EDMA1_CH30_IRQHandler                           /* AONMIX EDMA channel 30 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[30] - inputs[222]) IRQ=460*/
    .long   EDMA1_CH31_IRQHandler                           /* AONMIX EDMA channel 31 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[31] - inputs[223]) IRQ=461*/
    .long   Reserved478_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[224]) IRQ=462*/
    .long   Reserved479_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[225]) IRQ=463*/
    .long   Reserved480_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[226]) IRQ=464*/
    .long   Reserved481_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[227]) IRQ=465*/
    .long   Reserved482_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[228]) IRQ=466*/
    .long   Reserved483_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[229]) IRQ=467*/
    .long   Reserved484_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[230]) IRQ=468*/
    .long   Reserved485_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[231]) IRQ=469*/
    .long   Reserved486_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[232]) IRQ=470*/
    .long   Reserved487_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[233]) IRQ=471*/
    .long   Reserved488_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[234]) IRQ=472*/
    .long   Reserved489_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[235]) IRQ=473*/
    .long   Reserved490_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[236]) IRQ=474*/
    .long   Reserved491_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[237]) IRQ=475*/
    .long   Reserved492_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[238]) IRQ=476*/
    .long   Reserved493_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[239]) IRQ=477*/
    .long   Reserved494_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[240]) IRQ=478*/
    .long   Reserved495_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[241]) IRQ=479*/
    .long   Reserved496_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[242]) IRQ=480*/
    .long   Reserved497_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[243]) IRQ=481*/
    .long   Reserved498_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[244]) IRQ=482*/
    .long   Reserved499_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[245]) IRQ=483*/
    .long   Reserved500_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[246]) IRQ=484*/
    .long   Reserved501_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[247]) IRQ=485*/
    .long   Reserved502_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[248]) IRQ=486*/
    .long   Reserved503_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[249]) IRQ=487*/
    .long   Reserved504_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[250]) IRQ=488*/
    .long   Reserved505_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[251]) IRQ=489*/
    .long   Reserved506_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[252]) IRQ=490*/
    .long   Reserved507_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[253]) IRQ=491*/
    .long   Reserved508_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[254]) IRQ=492*/
    .long   Reserved509_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[255]) IRQ=493*/
    .long   MU1_A_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU1 IRQSTEERM7 extend(bitoffset[0] - inputs[256]) IRQ=494*/
    .long   MU1_B_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU1 IRQSTEERM7 extend(bitoffset[1] - inputs[257]) IRQ=495*/
    .long   MU2_A_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU2 IRQSTEERM7 extend(bitoffset[2] - inputs[258]) IRQ=496*/
    .long   MU2_B_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU2 IRQSTEERM7 extend(bitoffset[3] - inputs[259]) IRQ=497*/
    .long   MU3_A_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU3 IRQSTEERM7 extend(bitoffset[4] - inputs[260]) IRQ=498*/
    .long   MU3_B_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU3 IRQSTEERM7 extend(bitoffset[5] - inputs[261]) IRQ=499*/
    .long   MU4_A_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU4 IRQSTEERM7 extend(bitoffset[6] - inputs[262]) IRQ=500*/
    .long   MU4_B_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU4 IRQSTEERM7 extend(bitoffset[7] - inputs[263]) IRQ=501*/
    .long   MU5_B_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU5 IRQSTEERM7 extend(bitoffset[8] - inputs[264]) IRQ=502*/
    .long   MU6_B_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU6 IRQSTEERM7 extend(bitoffset[9] - inputs[265]) IRQ=503*/
    .long   MU7_B_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU7 IRQSTEERM7 extend(bitoffset[10] - inputs[266]) IRQ=504*/
    .long   MU8_A_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU8 IRQSTEERM7 extend(bitoffset[11] - inputs[267]) IRQ=505*/
    .long   MU8_B_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU1 IRQSTEERM7 extend(bitoffset[12] - inputs[268]) IRQ=506*/
    .long   MU9_A_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU9 IRQSTEERM7 extend(bitoffset[13] - inputs[269]) IRQ=507*/
    .long   MU9_B_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU9 IRQSTEERM7 extend(bitoffset[14] - inputs[270]) IRQ=508*/
    .long   MU10_A_IRQHandler                               /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU10 IRQSTEERM7 extend(bitoffset[15] - inputs[271]) IRQ=509*/
    .long   Reserved526_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[272]) IRQ=510*/
    .long   Reserved527_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[273]) IRQ=511*/
    .long   Reserved528_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[274]) IRQ=512*/
    .long   Reserved529_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[275]) IRQ=513*/
    .long   Reserved530_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[276]) IRQ=514*/
    .long   Reserved531_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[277]) IRQ=515*/
    .long   Reserved532_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[278]) IRQ=516*/
    .long   Reserved533_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[279]) IRQ=517*/
    .long   Reserved534_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[280]) IRQ=518*/
    .long   Reserved535_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[281]) IRQ=519*/
    .long   Reserved536_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[282]) IRQ=520*/
    .long   Reserved537_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[283]) IRQ=521*/
    .long   Reserved538_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[284]) IRQ=522*/
    .long   Reserved539_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[285]) IRQ=523*/
    .long   Reserved540_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[286]) IRQ=524*/
    .long   Reserved541_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[287]) IRQ=525*/
    .long   Reserved542_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[288]) IRQ=526*/
    .long   Reserved543_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[289]) IRQ=527*/
    .long   Reserved544_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[290]) IRQ=528*/
    .long   Reserved545_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[291]) IRQ=529*/
    .long   Reserved546_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[292]) IRQ=530*/
    .long   Reserved547_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[293]) IRQ=531*/
    .long   Reserved548_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[294]) IRQ=532*/
    .long   Reserved549_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[295]) IRQ=533*/
    .long   Reserved550_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[296]) IRQ=534*/
    .long   Reserved551_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[297]) IRQ=535*/
    .long   Reserved552_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[298]) IRQ=536*/
    .long   Reserved553_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[299]) IRQ=537*/
    .long   Reserved554_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[300]) IRQ=538*/
    .long   Reserved555_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[301]) IRQ=539*/
    .long   Reserved556_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[302]) IRQ=540*/
    .long   Reserved557_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[303]) IRQ=541*/
    .long   Reserved558_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[304]) IRQ=542*/
    .long   Reserved559_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[305]) IRQ=543*/
    .long   Reserved560_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[306]) IRQ=544*/
    .long   Reserved561_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[307]) IRQ=545*/
    .long   Reserved562_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[308]) IRQ=546*/
    .long   Reserved563_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[309]) IRQ=547*/
    .long   Reserved564_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[310]) IRQ=548*/
    .long   Reserved565_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[311]) IRQ=549*/
    .long   Reserved566_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[312]) IRQ=550*/
    .long   Reserved567_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[313]) IRQ=551*/
    .long   Reserved568_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[314]) IRQ=552*/
    .long   Reserved569_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[315]) IRQ=553*/
    .long   Reserved570_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[316]) IRQ=554*/
    .long   Reserved571_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[317]) IRQ=555*/
    .long   Reserved572_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[318]) IRQ=556*/
    .long   Reserved573_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[319]) IRQ=557*/
    .long   MU11_A_IRQHandler                               /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU11 IRQSTEERM7 extend(bitoffset[0] - inputs[320]) IRQ=558*/
    .long   MU12_B_IRQHandler                               /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU12 IRQSTEERM7 extend(bitoffset[1] - inputs[321]) IRQ=559*/
    .long   MU13_B_IRQHandler                               /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU13 IRQSTEERM7 extend(bitoffset[2] - inputs[322]) IRQ=560*/
    .long   MU14_A_IRQHandler                               /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU14 IRQSTEERM7 extend(bitoffset[3] - inputs[323]) IRQ=561*/
    .long   MU14_B_IRQHandler                               /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU14 IRQSTEERM7 extend(bitoffset[4] - inputs[324]) IRQ=562*/
    .long   MU15_A_IRQHandler                               /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU15 IRQSTEERM7 extend(bitoffset[5] - inputs[325]) IRQ=563*/
    .long   MU15_B_IRQHandler                               /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU15 IRQSTEERM7 extend(bitoffset[6] - inputs[326]) IRQ=564*/
    .long   MU16_A_IRQHandler                               /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU16 IRQSTEERM7 extend(bitoffset[7] - inputs[327]) IRQ=565*/
    .long   MU16_B_IRQHandler                               /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU16 IRQSTEERM7 extend(bitoffset[8] - inputs[328]) IRQ=566*/
    .long   MU17_A_IRQHandler                               /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU17 IRQSTEERM7 extend(bitoffset[9] - inputs[329]) IRQ=567*/
    .long   MU17_B_IRQHandler                               /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU17 IRQSTEERM7 extend(bitoffset[10] - inputs[330]) IRQ=568*/
    .long   MU_E1_B_IRQHandler                              /* NETCMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU_E1 IRQSTEERM7 extend(bitoffset[11] - inputs[331]) IRQ=569*/
    .long   MU_E2_B_IRQHandler                              /* NETCMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU_E2 IRQSTEERM7 extend(bitoffset[12] - inputs[332]) IRQ=570*/
    .long   MU_E3_B_IRQHandler                              /* NETCMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU_E3 IRQSTEERM7 extend(bitoffset[13] - inputs[333]) IRQ=571*/
    .long   MU_E4_B_IRQHandler                              /* NETCMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU_E4 IRQSTEERM7 extend(bitoffset[14] - inputs[334]) IRQ=572*/
    .long   MSGINTR1_IRQHandler                             /* MSGINTR Instance 1, Interrupt 1, MSGINTR Instance 1, Interrupt 2, MSGINTR Instance 1, Interrupt 3 Module=MSGINTR1 IRQSTEERM7 extend(bitoffset[15] - inputs[335]) IRQ=573*/
    .long   Reserved590_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[336]) IRQ=574*/
    .long   Reserved591_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[337]) IRQ=575*/
    .long   Reserved592_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[338]) IRQ=576*/
    .long   Reserved593_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[339]) IRQ=577*/
    .long   Reserved594_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[340]) IRQ=578*/
    .long   Reserved595_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[341]) IRQ=579*/
    .long   Reserved596_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[342]) IRQ=580*/
    .long   Reserved597_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[343]) IRQ=581*/
    .long   Reserved598_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[344]) IRQ=582*/
    .long   Reserved599_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[345]) IRQ=583*/
    .long   Reserved600_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[346]) IRQ=584*/
    .long   Reserved601_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[347]) IRQ=585*/
    .long   Reserved602_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[348]) IRQ=586*/
    .long   Reserved603_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[349]) IRQ=587*/
    .long   Reserved604_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[350]) IRQ=588*/
    .long   Reserved605_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[351]) IRQ=589*/
    .long   Reserved606_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[352]) IRQ=590*/
    .long   Reserved607_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[353]) IRQ=591*/
    .long   Reserved608_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[354]) IRQ=592*/
    .long   Reserved609_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[355]) IRQ=593*/
    .long   Reserved610_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[356]) IRQ=594*/
    .long   Reserved611_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[357]) IRQ=595*/
    .long   Reserved612_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[358]) IRQ=596*/
    .long   Reserved613_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[359]) IRQ=597*/
    .long   Reserved614_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[360]) IRQ=598*/
    .long   Reserved615_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[361]) IRQ=599*/
    .long   Reserved616_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[362]) IRQ=600*/
    .long   Reserved617_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[363]) IRQ=601*/
    .long   Reserved618_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[364]) IRQ=602*/
    .long   Reserved619_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[365]) IRQ=603*/
    .long   Reserved620_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[366]) IRQ=604*/
    .long   Reserved621_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[367]) IRQ=605*/
    .long   Reserved622_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[368]) IRQ=606*/
    .long   Reserved623_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[369]) IRQ=607*/
    .long   Reserved624_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[370]) IRQ=608*/
    .long   Reserved625_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[371]) IRQ=609*/
    .long   Reserved626_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[372]) IRQ=610*/
    .long   Reserved627_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[373]) IRQ=611*/
    .long   Reserved628_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[374]) IRQ=612*/
    .long   Reserved629_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[375]) IRQ=613*/
    .long   Reserved630_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[376]) IRQ=614*/
    .long   Reserved631_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[377]) IRQ=615*/
    .long   Reserved632_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[378]) IRQ=616*/
    .long   Reserved633_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[379]) IRQ=617*/
    .long   Reserved634_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[380]) IRQ=618*/
    .long   Reserved635_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[381]) IRQ=619*/
    .long   Reserved636_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[382]) IRQ=620*/
    .long   Reserved637_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[383]) IRQ=621*/
    .long   MSGINTR2_IRQHandler                             /* MSGINTR Instance 2, Interrupt 1, MSGINTR Instance 2, Interrupt 2, MSGINTR Instance 2, Interrupt 3 Module=MSGINTR2 IRQSTEERM7 extend(bitoffset[0] - inputs[384]) IRQ=622*/
    .long   MSGINTR3_IRQHandler                             /* MSGINTR Instance 3, Interrupt 1, MSGINTR Instance 3, Interrupt 2, MSGINTR Instance 3, Interrupt 3 Module=MSGINTR3 IRQSTEERM7 extend(bitoffset[1] - inputs[385]) IRQ=623*/
    .long   MSGINTR4_IRQHandler                             /* MSGINTR Instance 4, Interrupt 1, MSGINTR Instance 4, Interrupt 2, MSGINTR Instance 4, Interrupt 3 Module=MSGINTR4 IRQSTEERM7 extend(bitoffset[2] - inputs[386]) IRQ=624*/
    .long   MSGINTR5_IRQHandler                             /* MSGINTR Instance 5, Interrupt 1, MSGINTR Instance 5, Interrupt 2, MSGINTR Instance 5, Interrupt 3 Module=MSGINTR5 IRQSTEERM7 extend(bitoffset[3] - inputs[387]) IRQ=625*/
    .long   MSGINTR6_IRQHandler                             /* MSGINTR Instance 6, Interrupt 1, MSGINTR Instance 6, Interrupt 2, MSGINTR Instance 6, Interrupt 3 Module=MSGINTR6 IRQSTEERM7 extend(bitoffset[4] - inputs[388]) IRQ=626*/
    .long   MSGINTR7_IRQHandler                             /* MSGINTR Instance 7, Interrupt 1, MSGINTR Instance 7, Interrupt 2, MSGINTR Instance 7, Interrupt 3 Module=MSGINTR7 IRQSTEERM7 extend(bitoffset[5] - inputs[389]) IRQ=627*/
    .long   MSGINTR8_IRQHandler                             /* MSGINTR Instance 8, Interrupt 1, MSGINTR Instance 8, Interrupt 2, MSGINTR Instance 8, Interrupt 3 Module=MSGINTR8 IRQSTEERM7 extend(bitoffset[6] - inputs[390]) IRQ=628*/
    .long   V2X_FH_APP1_IRQHandler                          /* V2X-FH MU APCH1 (APP1) A_TX interrupt, V2X-FH MU APCH1 (APP1) A_RX interrupt Module=V2X_FH IRQSTEERM7 extend(bitoffset[7] - inputs[391]) IRQ=629*/
    .long   V2X_FH_HSM2_IRQHandler                          /* V2X-FH MU APHSM2 (HSM2) A_TX interrupt, V2X-FH MU APHSM2 (HSM2) A_RX interrupt Module=V2X_FH IRQSTEERM7 extend(bitoffset[8] - inputs[392]) IRQ=630*/
    .long   S500_REQ1_IRQHandler                            /* Sentinel Group 1 reset source if no s500 reference clock is detected.  Output synchronized to 32khz clk. New signal name for i.MX943 is s4v1_fdet0_tclk_err_irq. (Cause Reset) Module=S500 IRQSTEERM7 extend(bitoffset[9] - inputs[393]) IRQ=631*/
    .long   S500_REQ2_IRQHandler                            /* Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk the S500 clock. New signal name for i.MX943 is s4v1_fdet2_tclk_err_irq.  (Reset Request in CM33 domain) Module=S500 IRQSTEERM7 extend(bitoffset[10] - inputs[394]) IRQ=632*/
    .long   S500_REQ3_IRQHandler                            /* Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk. New signal name for i.MX943 is s4v1_fdet3_tclk_err_irq Module=S500 IRQSTEERM7 extend(bitoffset[11] - inputs[395]) IRQ=633*/
    .long   S500_REQ4_IRQHandler                            /* Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to S500 clock domain. New signal name for i.MX943 is s4v1_fdet1_tclk_err_irq Module=S500 IRQSTEERM7 extend(bitoffset[12] - inputs[396]) IRQ=634*/
    .long   S500_GLUE_IRQHandler                            /* s500 glue logic IRQ Module=SENTINEL_IRQ_GLUE IRQSTEERM7 extend(bitoffset[13] - inputs[397]) IRQ=635*/
    .long   GPC_SM_REQ_IRQHandler                           /* SRC/GPC Low Power Handshake Gasket interrupt request for system management Module=LP_HDSK_GSKT IRQSTEERM7 extend(bitoffset[14] - inputs[398]) IRQ=636*/
    .long   EDMA1_ERROR_IRQHandler                          /* AONMIX EDMA error interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[15] - inputs[399]) IRQ=637*/
    .long   Reserved654_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[400]) IRQ=638*/
    .long   Reserved655_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[401]) IRQ=639*/
    .long   Reserved656_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[402]) IRQ=640*/
    .long   Reserved657_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[403]) IRQ=641*/
    .long   Reserved658_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[404]) IRQ=642*/
    .long   Reserved659_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[405]) IRQ=643*/
    .long   Reserved660_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[406]) IRQ=644*/
    .long   Reserved661_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[407]) IRQ=645*/
    .long   Reserved662_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[408]) IRQ=646*/
    .long   Reserved663_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[409]) IRQ=647*/
    .long   Reserved664_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[410]) IRQ=648*/
    .long   Reserved665_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[411]) IRQ=649*/
    .long   Reserved666_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[412]) IRQ=650*/
    .long   Reserved667_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[413]) IRQ=651*/
    .long   Reserved668_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[414]) IRQ=652*/
    .long   Reserved669_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[415]) IRQ=653*/
    .long   Reserved670_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[416]) IRQ=654*/
    .long   Reserved671_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[417]) IRQ=655*/
    .long   Reserved672_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[418]) IRQ=656*/
    .long   Reserved673_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[419]) IRQ=657*/
    .long   Reserved674_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[420]) IRQ=658*/
    .long   Reserved675_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[421]) IRQ=659*/
    .long   Reserved676_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[422]) IRQ=660*/
    .long   Reserved677_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[423]) IRQ=661*/
    .long   Reserved678_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[424]) IRQ=662*/
    .long   Reserved679_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[425]) IRQ=663*/
    .long   Reserved680_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[426]) IRQ=664*/
    .long   Reserved681_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[427]) IRQ=665*/
    .long   Reserved682_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[428]) IRQ=666*/
    .long   Reserved683_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[429]) IRQ=667*/
    .long   Reserved684_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[430]) IRQ=668*/
    .long   Reserved685_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[431]) IRQ=669*/
    .long   Reserved686_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[432]) IRQ=670*/
    .long   Reserved687_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[433]) IRQ=671*/
    .long   Reserved688_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[434]) IRQ=672*/
    .long   Reserved689_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[435]) IRQ=673*/
    .long   Reserved690_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[436]) IRQ=674*/
    .long   Reserved691_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[437]) IRQ=675*/
    .long   Reserved692_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[438]) IRQ=676*/
    .long   Reserved693_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[439]) IRQ=677*/
    .long   Reserved694_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[440]) IRQ=678*/
    .long   Reserved695_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[441]) IRQ=679*/
    .long   Reserved696_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[442]) IRQ=680*/
    .long   Reserved697_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[443]) IRQ=681*/
    .long   Reserved698_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[444]) IRQ=682*/
    .long   Reserved699_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[445]) IRQ=683*/
    .long   Reserved700_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[446]) IRQ=684*/
    .long   Reserved701_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[447]) IRQ=685*/
    .long   Reserved702_IRQHandler                          /* AONMIX TRDC transfer error interrupt Module=TRDC_MGR_A IRQSTEERM7 extend(bitoffset[0] - inputs[448]) IRQ=686*/
    .long   Reserved703_IRQHandler                          /* WAKEUPMIX TRDC-MGR1 transfer error interrupt Module=TRDC_MGR_W1 IRQSTEERM7 extend(bitoffset[1] - inputs[449]) IRQ=687*/
    .long   Reserved704_IRQHandler                          /* MEGAMIX TRDC transfer error interrupt Module=TRDC_MGR_M IRQSTEERM7 extend(bitoffset[2] - inputs[450]) IRQ=688*/
    .long   Reserved705_IRQHandler                          /* NOCMIX TRDC transfer error interrupt Module=TRDC_MGR_N IRQSTEERM7 extend(bitoffset[3] - inputs[451]) IRQ=689*/
    .long   Reserved706_IRQHandler                          /* DISPLAYMIX TRDC transfer error interrupt Module=TRDC_MGR_D IRQSTEERM7 extend(bitoffset[4] - inputs[452]) IRQ=690*/
    .long   Reserved707_IRQHandler                          /* NETCMIX TRDC transfer error interrupt, NET_CM33_Sync Platform TRDC transfer error interrupt Module=TRDC_MGR_S IRQSTEERM7 extend(bitoffset[5] - inputs[453]) IRQ=691*/
    .long   Reserved708_IRQHandler                          /* HSIOMIX TRDC transfer error interrupt Module=TRDC_MGR_H IRQSTEERM7 extend(bitoffset[6] - inputs[454]) IRQ=692*/
    .long   Reserved709_IRQHandler                          /* WAKEUPMIX TRDC-MGR2 transfer error interrupt Module=TRDC_MGR_W2 IRQSTEERM7 extend(bitoffset[7] - inputs[455]) IRQ=693*/
    .long   Reserved710_IRQHandler                          /* AONMIX ERM Single bit corrected ECC Error Module=ERM_A IRQSTEERM7 extend(bitoffset[8] - inputs[456]) IRQ=694*/
    .long   Reserved711_IRQHandler                          /* M7MIX0 ERM Single bit corrected ECC Error Module=ERM_M7_0 IRQSTEERM7 extend(bitoffset[9] - inputs[457]) IRQ=695*/
    .long   Reserved712_IRQHandler                          /* M7MIX1 ERM Single bit corrected ECC Error Module=ERM_M7_1 IRQSTEERM7 extend(bitoffset[10] - inputs[458]) IRQ=696*/
    .long   Reserved713_IRQHandler                          /* WAKEUPMIX ERM Single bit corrected ECC Error Module=ERM_W IRQSTEERM7 extend(bitoffset[11] - inputs[459]) IRQ=697*/
    .long   Reserved714_IRQHandler                          /* NPUMIX ERM Single bit corrected ECC Error Module=ERM_ML IRQSTEERM7 extend(bitoffset[12] - inputs[460]) IRQ=698*/
    .long   Reserved715_IRQHandler                          /* NETCMIX ERM Single bit corrected ECC Error Module=ERM_NETC IRQSTEERM7 extend(bitoffset[13] - inputs[461]) IRQ=699*/
    .long   Reserved716_IRQHandler                          /* OCRAM ECC multi bit error Module=OCRAM IRQSTEERM7 extend(bitoffset[14] - inputs[462]) IRQ=700*/
    .long   Reserved717_IRQHandler                          /* AONMIX MTR Master error interrupt Module=MTR_MSTR IRQSTEERM7 extend(bitoffset[15] - inputs[463]) IRQ=701*/
    .long   Reserved718_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[464]) IRQ=702*/
    .long   Reserved719_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[465]) IRQ=703*/
    .long   Reserved720_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[466]) IRQ=704*/
    .long   Reserved721_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[467]) IRQ=705*/
    .long   Reserved722_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[468]) IRQ=706*/
    .long   Reserved723_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[469]) IRQ=707*/
    .long   Reserved724_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[470]) IRQ=708*/
    .long   Reserved725_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[471]) IRQ=709*/
    .long   Reserved726_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[472]) IRQ=710*/
    .long   Reserved727_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[473]) IRQ=711*/
    .long   Reserved728_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[474]) IRQ=712*/
    .long   Reserved729_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[475]) IRQ=713*/
    .long   Reserved730_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[476]) IRQ=714*/
    .long   Reserved731_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[477]) IRQ=715*/
    .long   Reserved732_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[478]) IRQ=716*/
    .long   Reserved733_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[479]) IRQ=717*/
    .long   Reserved734_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[480]) IRQ=718*/
    .long   Reserved735_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[481]) IRQ=719*/
    .long   Reserved736_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[482]) IRQ=720*/
    .long   Reserved737_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[483]) IRQ=721*/
    .long   Reserved738_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[484]) IRQ=722*/
    .long   Reserved739_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[485]) IRQ=723*/
    .long   Reserved740_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[486]) IRQ=724*/
    .long   Reserved741_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[487]) IRQ=725*/
    .long   Reserved742_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[488]) IRQ=726*/
    .long   Reserved743_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[489]) IRQ=727*/
    .long   Reserved744_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[490]) IRQ=728*/
    .long   Reserved745_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[491]) IRQ=729*/
    .long   Reserved746_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[492]) IRQ=730*/
    .long   Reserved747_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[493]) IRQ=731*/
    .long   Reserved748_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[494]) IRQ=732*/
    .long   Reserved749_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[495]) IRQ=733*/
    .long   Reserved750_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[496]) IRQ=734*/
    .long   Reserved751_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[497]) IRQ=735*/
    .long   Reserved752_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[498]) IRQ=736*/
    .long   Reserved753_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[499]) IRQ=737*/
    .long   Reserved754_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[500]) IRQ=738*/
    .long   Reserved755_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[501]) IRQ=739*/
    .long   Reserved756_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[502]) IRQ=740*/
    .long   Reserved757_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[503]) IRQ=741*/
    .long   Reserved758_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[504]) IRQ=742*/
    .long   Reserved759_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[505]) IRQ=743*/
    .long   Reserved760_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[506]) IRQ=744*/
    .long   Reserved761_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[507]) IRQ=745*/
    .long   Reserved762_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[508]) IRQ=746*/
    .long   Reserved763_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[509]) IRQ=747*/
    .long   Reserved764_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[510]) IRQ=748*/
    .long   Reserved765_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[511]) IRQ=749*/
    .long   Reserved766_IRQHandler                          /* EDMA3 DMA error interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[0] - inputs[512]) IRQ=750*/
    .long   Reserved767_IRQHandler                          /* AONMIX M33 PS Tag Parity Error, AONMIX M33 PS Data Parity Error Module=CM33 IRQSTEERM7 extend(bitoffset[1] - inputs[513]) IRQ=751*/
    .long   Reserved768_IRQHandler                          /* AONMIX M33 TCM Error interrupt Module=CM33_ECC_MCM IRQSTEERM7 extend(bitoffset[2] - inputs[514]) IRQ=752*/
    .long   Reserved769_IRQHandler                          /* M7MIX ECC Multi-bit error Module=ERM_M7_0 IRQSTEERM7 extend(bitoffset[3] - inputs[515]) IRQ=753*/
    .long   Reserved770_IRQHandler                          /* NETCMIX M33 PS Tag Parity Error, NETCMIX M33 PS Data Parity Error Module=CM33_SYNC IRQSTEERM7 extend(bitoffset[4] - inputs[516]) IRQ=754*/
    .long   Reserved771_IRQHandler                          /* NETCMIX M33 TCM Error interrupt Module=CM33_SYNC_ECC_MCM IRQSTEERM7 extend(bitoffset[5] - inputs[517]) IRQ=755*/
    .long   Reserved772_IRQHandler                          /* NETCMIX 1.5MB OCSRAM  Error interrupt Module=NETCMIX_ECC_MCM IRQSTEERM7 extend(bitoffset[6] - inputs[518]) IRQ=756*/
    .long   Reserved773_IRQHandler                          /* M7MIX1 ECC Multi-bit error Module=ERM_M7_1 IRQSTEERM7 extend(bitoffset[7] - inputs[519]) IRQ=757*/
    .long   Reserved774_IRQHandler                          /* GIC700 Fault (Uncorrectable ECC errors) Module=GIC700 IRQSTEERM7 extend(bitoffset[8] - inputs[520]) IRQ=758*/
    .long   Reserved775_IRQHandler                          /* CM33 MCM interrupt Module=CM33 IRQSTEERM7 extend(bitoffset[9] - inputs[521]) IRQ=759*/
    .long   Reserved776_IRQHandler                          /* CM33_sync MCM interrupt Module=CM33_SYNC IRQSTEERM7 extend(bitoffset[10] - inputs[522]) IRQ=760*/
    .long   Reserved777_IRQHandler                          /* NETCMIX 1.5 MB SRAM  MCM interrupt Module=NETCMIX IRQSTEERM7 extend(bitoffset[11] - inputs[523]) IRQ=761*/
    .long   Reserved778_IRQHandler                          /* M7MIX0 MCM interrupt Module=M7MIX0 IRQSTEERM7 extend(bitoffset[12] - inputs[524]) IRQ=762*/
    .long   Reserved779_IRQHandler                          /* M7MIX1 MCM interrupt Module=M7MIX1 IRQSTEERM7 extend(bitoffset[13] - inputs[525]) IRQ=763*/
    .long   Reserved780_IRQHandler                          /* OCRAM ECC single bit error Module=OCRAM IRQSTEERM7 extend(bitoffset[14] - inputs[526]) IRQ=764*/
    .long   Reserved781_IRQHandler                          /* GIC700 Error (Correctable ECC errors) Module=GIC700 IRQSTEERM7 extend(bitoffset[15] - inputs[527]) IRQ=765*/
    .long   Reserved782_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[528]) IRQ=766*/
    .long   Reserved783_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[529]) IRQ=767*/
    .long   Reserved784_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[530]) IRQ=768*/
    .long   Reserved785_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[531]) IRQ=769*/
    .long   Reserved786_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[532]) IRQ=770*/
    .long   Reserved787_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[533]) IRQ=771*/
    .long   Reserved788_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[534]) IRQ=772*/
    .long   Reserved789_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[535]) IRQ=773*/
    .long   Reserved790_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[536]) IRQ=774*/
    .long   Reserved791_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[537]) IRQ=775*/
    .long   Reserved792_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[538]) IRQ=776*/
    .long   Reserved793_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[539]) IRQ=777*/
    .long   Reserved794_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[540]) IRQ=778*/
    .long   Reserved795_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[541]) IRQ=779*/
    .long   Reserved796_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[542]) IRQ=780*/
    .long   Reserved797_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[543]) IRQ=781*/
    .long   Reserved798_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[544]) IRQ=782*/
    .long   Reserved799_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[545]) IRQ=783*/
    .long   Reserved800_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[546]) IRQ=784*/
    .long   Reserved801_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[547]) IRQ=785*/
    .long   Reserved802_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[548]) IRQ=786*/
    .long   Reserved803_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[549]) IRQ=787*/
    .long   Reserved804_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[550]) IRQ=788*/
    .long   Reserved805_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[551]) IRQ=789*/
    .long   Reserved806_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[552]) IRQ=790*/
    .long   Reserved807_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[553]) IRQ=791*/
    .long   Reserved808_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[554]) IRQ=792*/
    .long   Reserved809_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[555]) IRQ=793*/
    .long   Reserved810_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[556]) IRQ=794*/
    .long   Reserved811_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[557]) IRQ=795*/
    .long   Reserved812_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[558]) IRQ=796*/
    .long   Reserved813_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[559]) IRQ=797*/
    .long   Reserved814_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[560]) IRQ=798*/
    .long   Reserved815_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[561]) IRQ=799*/
    .long   Reserved816_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[562]) IRQ=800*/
    .long   Reserved817_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[563]) IRQ=801*/
    .long   Reserved818_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[564]) IRQ=802*/
    .long   Reserved819_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[565]) IRQ=803*/
    .long   Reserved820_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[566]) IRQ=804*/
    .long   Reserved821_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[567]) IRQ=805*/
    .long   Reserved822_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[568]) IRQ=806*/
    .long   Reserved823_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[569]) IRQ=807*/
    .long   Reserved824_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[570]) IRQ=808*/
    .long   Reserved825_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[571]) IRQ=809*/
    .long   Reserved826_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[572]) IRQ=810*/
    .long   Reserved827_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[573]) IRQ=811*/
    .long   Reserved828_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[574]) IRQ=812*/
    .long   Reserved829_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[575]) IRQ=813*/
    .long   Reserved830_IRQHandler                          /* ANAMIX SFA(Signal Frequency Analyzer) interrupt Module=ANAMIX IRQSTEERM7 extend(bitoffset[0] - inputs[576]) IRQ=814*/
    .long   TMPSNS_THR1_IRQHandler                          /* ANAMIX TempSensor non-secure interrupt from Threshold 1 Module=ANAMIX IRQSTEERM7 extend(bitoffset[1] - inputs[577]) IRQ=815*/
    .long   TMPSNS_THR2_IRQHandler                          /* ANAMIX TempSensor non-secure interrupt from Threshold 2 Module=ANAMIX IRQSTEERM7 extend(bitoffset[2] - inputs[578]) IRQ=816*/
    .long   Reserved833_IRQHandler                          /* ANAMIX TempSensor non-secure data ready interrupt Module=ANAMIX IRQSTEERM7 extend(bitoffset[3] - inputs[579]) IRQ=817*/
    .long   Reserved834_IRQHandler                          /* CORTEXAMIX TempSensor non-secure interrupt from Threshold 1 Module=CORTEXAMIX IRQSTEERM7 extend(bitoffset[4] - inputs[580]) IRQ=818*/
    .long   Reserved835_IRQHandler                          /* CORTEXAMIX TempSensor non-secure interrupt from Threshold 2 Module=CORTEXAMIX IRQSTEERM7 extend(bitoffset[5] - inputs[581]) IRQ=819*/
    .long   Reserved836_IRQHandler                          /* CORTEXAMIX TempSensor non-secure data ready interrupt Module=CORTEXAMIX IRQSTEERM7 extend(bitoffset[6] - inputs[582]) IRQ=820*/
    .long   CM33_0_SYSRESETREQ_IRQHandler                   /* AONMIX CM33 SYSREQRST SRC reset source Module=CM33 IRQSTEERM7 extend(bitoffset[7] - inputs[583]) IRQ=821*/
    .long   CM33_0_LOCKUP_IRQHandler                        /* AONMIX CM33 LOCKUP SRC reset source Module=CM33 IRQSTEERM7 extend(bitoffset[8] - inputs[584]) IRQ=822*/
    .long   CM7_0_SYSRESETREQ_IRQHandler                    /* CM7_0 SYSREQRST SRC reset source Module=CM7_0 IRQSTEERM7 extend(bitoffset[9] - inputs[585]) IRQ=823*/
    .long   CM7_0_LOCKUP_IRQHandler                         /* CM7_0 LOCKUP SRC reset source Module=CM7_0 IRQSTEERM7 extend(bitoffset[10] - inputs[586]) IRQ=824*/
    .long   CM33_1_SYSRESETREQ_IRQHandler                   /* NETCMIX CM33_sync SYSREQRST SRC reset source Module=CM33_SYNC IRQSTEERM7 extend(bitoffset[11] - inputs[587]) IRQ=825*/
    .long   CM33_1_LOCKUP_IRQHandler                        /* NETCMIX CM33_sync LOCKUP SRC reset source Module=CM33_SYNC IRQSTEERM7 extend(bitoffset[12] - inputs[588]) IRQ=826*/
    .long   CM7_1_SYSRESETREQ_IRQHandler                    /* CM7_1 SYSREQRST SRC reset source Module=CM7_1 IRQSTEERM7 extend(bitoffset[13] - inputs[589]) IRQ=827*/
    .long   CM7_1_LOCKUP_IRQHandler                         /* CM7_1 LOCKUP SRC reset source Module=CM7_1 IRQSTEERM7 extend(bitoffset[14] - inputs[590]) IRQ=828*/
    .long   Reserved845_IRQHandler                          /* soc_reset_wo_netc_int Module=NETC_PLAT IRQSTEERM7 extend(bitoffset[15] - inputs[591]) IRQ=829*/
    .long   Reserved846_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[592]) IRQ=830*/
    .long   Reserved847_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[593]) IRQ=831*/
    .long   Reserved848_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[594]) IRQ=832*/
    .long   Reserved849_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[595]) IRQ=833*/
    .long   Reserved850_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[596]) IRQ=834*/
    .long   Reserved851_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[597]) IRQ=835*/
    .long   Reserved852_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[598]) IRQ=836*/
    .long   Reserved853_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[599]) IRQ=837*/
    .long   Reserved854_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[600]) IRQ=838*/
    .long   Reserved855_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[601]) IRQ=839*/
    .long   Reserved856_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[602]) IRQ=840*/
    .long   Reserved857_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[603]) IRQ=841*/
    .long   Reserved858_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[604]) IRQ=842*/
    .long   Reserved859_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[605]) IRQ=843*/
    .long   Reserved860_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[606]) IRQ=844*/
    .long   Reserved861_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[607]) IRQ=845*/
    .long   Reserved862_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[608]) IRQ=846*/
    .long   Reserved863_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[609]) IRQ=847*/
    .long   Reserved864_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[610]) IRQ=848*/
    .long   Reserved865_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[611]) IRQ=849*/
    .long   Reserved866_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[612]) IRQ=850*/
    .long   Reserved867_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[613]) IRQ=851*/
    .long   Reserved868_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[614]) IRQ=852*/
    .long   Reserved869_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[615]) IRQ=853*/
    .long   Reserved870_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[616]) IRQ=854*/
    .long   Reserved871_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[617]) IRQ=855*/
    .long   Reserved872_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[618]) IRQ=856*/
    .long   Reserved873_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[619]) IRQ=857*/
    .long   Reserved874_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[620]) IRQ=858*/
    .long   Reserved875_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[621]) IRQ=859*/
    .long   Reserved876_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[622]) IRQ=860*/
    .long   Reserved877_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[623]) IRQ=861*/
    .long   Reserved878_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[624]) IRQ=862*/
    .long   Reserved879_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[625]) IRQ=863*/
    .long   Reserved880_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[626]) IRQ=864*/
    .long   Reserved881_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[627]) IRQ=865*/
    .long   Reserved882_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[628]) IRQ=866*/
    .long   Reserved883_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[629]) IRQ=867*/
    .long   Reserved884_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[630]) IRQ=868*/
    .long   Reserved885_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[631]) IRQ=869*/
    .long   Reserved886_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[632]) IRQ=870*/
    .long   Reserved887_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[633]) IRQ=871*/
    .long   Reserved888_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[634]) IRQ=872*/
    .long   Reserved889_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[635]) IRQ=873*/
    .long   Reserved890_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[636]) IRQ=874*/
    .long   Reserved891_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[637]) IRQ=875*/
    .long   Reserved892_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[638]) IRQ=876*/
    .long   Reserved893_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[639]) IRQ=877*/
    .long   Reserved894_IRQHandler                          /* NETC iEPRC PCI INT (one per each of two RC-EC) Module=NETC IRQSTEERM7 extend(bitoffset[0] - inputs[640]) IRQ=878*/
    .long   Reserved895_IRQHandler                          /* NETC iEPRC PCI INT (one per each of two RC-EC) Module=NETC IRQSTEERM7 extend(bitoffset[1] - inputs[641]) IRQ=879*/
    .long   Reserved896_IRQHandler                          /* PCIe Controller 1 INTA Module=PCIE_CTRL1 IRQSTEERM7 extend(bitoffset[2] - inputs[642]) IRQ=880*/
    .long   Reserved897_IRQHandler                          /* PCIe Controller 1 INTB Module=PCIE_CTRL1 IRQSTEERM7 extend(bitoffset[3] - inputs[643]) IRQ=881*/
    .long   Reserved898_IRQHandler                          /* PCIe Controller 1 INTC Module=PCIE_CTRL1 IRQSTEERM7 extend(bitoffset[4] - inputs[644]) IRQ=882*/
    .long   Reserved899_IRQHandler                          /* PCIe Controller 1 INTD Module=PCIE_CTRL1 IRQSTEERM7 extend(bitoffset[5] - inputs[645]) IRQ=883*/
    .long   Reserved900_IRQHandler                          /* PCIe miscellaneous interrupts, PCIe MSI reception interrupt for RC mode, PCIe Link reset request interrupt Module=PCIE_CTRL1 IRQSTEERM7 extend(bitoffset[6] - inputs[646]) IRQ=884*/
    .long   Reserved901_IRQHandler                          /* PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt Module=PCIE_CTRL1 IRQSTEERM7 extend(bitoffset[7] - inputs[647]) IRQ=885*/
    .long   Reserved902_IRQHandler                          /* PCIe Controller 1 INTA Module=PCIE_CTRL2 IRQSTEERM7 extend(bitoffset[8] - inputs[648]) IRQ=886*/
    .long   Reserved903_IRQHandler                          /* PCIe Controller 1 INTB Module=PCIE_CTRL2 IRQSTEERM7 extend(bitoffset[9] - inputs[649]) IRQ=887*/
    .long   Reserved904_IRQHandler                          /* PCIe Controller 1 INTC Module=PCIE_CTRL2 IRQSTEERM7 extend(bitoffset[10] - inputs[650]) IRQ=888*/
    .long   Reserved905_IRQHandler                          /* PCIe Controller 1 INTD Module=PCIE_CTRL2 IRQSTEERM7 extend(bitoffset[11] - inputs[651]) IRQ=889*/
    .long   Reserved906_IRQHandler                          /* PCIe miscellaneous interrupts, PCIe MSI reception interrupt for RC mode, PCIe Link reset request interrupt Module=PCIE_CTRL2 IRQSTEERM7 extend(bitoffset[12] - inputs[652]) IRQ=890*/
    .long   Reserved907_IRQHandler                          /* PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt Module=PCIE_CTRL2 IRQSTEERM7 extend(bitoffset[13] - inputs[653]) IRQ=891*/
    .long   Reserved908_IRQHandler                          /* Wakeup interrupt from CLKREQ#, WAKEUP#, BEACON_DET Module=NPU IRQSTEERM7 extend(bitoffset[14] - inputs[654]) IRQ=892*/
    .long   Reserved909_IRQHandler                          /* NPUMIX Functional interrupt Module=NPU IRQSTEERM7 extend(bitoffset[15] - inputs[655]) IRQ=893*/
    .long   Reserved910_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[656]) IRQ=894*/
    .long   Reserved911_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[657]) IRQ=895*/
    .long   Reserved912_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[658]) IRQ=896*/
    .long   Reserved913_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[659]) IRQ=897*/
    .long   Reserved914_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[660]) IRQ=898*/
    .long   Reserved915_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[661]) IRQ=899*/
    .long   Reserved916_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[662]) IRQ=900*/
    .long   Reserved917_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[663]) IRQ=901*/
    .long   Reserved918_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[664]) IRQ=902*/
    .long   Reserved919_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[665]) IRQ=903*/
    .long   Reserved920_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[666]) IRQ=904*/
    .long   Reserved921_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[667]) IRQ=905*/
    .long   Reserved922_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[668]) IRQ=906*/
    .long   Reserved923_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[669]) IRQ=907*/
    .long   Reserved924_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[670]) IRQ=908*/
    .long   Reserved925_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[671]) IRQ=909*/
    .long   Reserved926_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[672]) IRQ=910*/
    .long   Reserved927_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[673]) IRQ=911*/
    .long   Reserved928_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[674]) IRQ=912*/
    .long   Reserved929_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[675]) IRQ=913*/
    .long   Reserved930_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[676]) IRQ=914*/
    .long   Reserved931_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[677]) IRQ=915*/
    .long   Reserved932_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[678]) IRQ=916*/
    .long   Reserved933_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[679]) IRQ=917*/
    .long   Reserved934_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[680]) IRQ=918*/
    .long   Reserved935_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[681]) IRQ=919*/
    .long   Reserved936_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[682]) IRQ=920*/
    .long   Reserved937_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[683]) IRQ=921*/
    .long   Reserved938_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[684]) IRQ=922*/
    .long   Reserved939_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[685]) IRQ=923*/
    .long   Reserved940_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[686]) IRQ=924*/
    .long   Reserved941_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[687]) IRQ=925*/
    .long   Reserved942_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[688]) IRQ=926*/
    .long   Reserved943_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[689]) IRQ=927*/
    .long   Reserved944_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[690]) IRQ=928*/
    .long   Reserved945_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[691]) IRQ=929*/
    .long   Reserved946_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[692]) IRQ=930*/
    .long   Reserved947_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[693]) IRQ=931*/
    .long   Reserved948_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[694]) IRQ=932*/
    .long   Reserved949_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[695]) IRQ=933*/
    .long   Reserved950_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[696]) IRQ=934*/
    .long   Reserved951_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[697]) IRQ=935*/
    .long   Reserved952_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[698]) IRQ=936*/
    .long   Reserved953_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[699]) IRQ=937*/
    .long   Reserved954_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[700]) IRQ=938*/
    .long   Reserved955_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[701]) IRQ=939*/
    .long   Reserved956_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[702]) IRQ=940*/
    .long   Reserved957_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[703]) IRQ=941*/
    .long   Reserved958_IRQHandler                          /* DRAM controller Performance Monitor Interrupt Module=DDR_TOP IRQSTEERM7 extend(bitoffset[0] - inputs[704]) IRQ=942*/
    .long   Reserved959_IRQHandler                          /* DRAM controller Critical Interrupt Module=DDR_TOP IRQSTEERM7 extend(bitoffset[1] - inputs[705]) IRQ=943*/
    .long   Reserved960_IRQHandler                          /* DRAM Phy Critical Interrupt 0, DRAM Phy Critical Interrupt 1, DRAM Phy Critical Interrupt 2, DRAM Phy Critical Interrupt 3, DRAM Phy Critical Interrupt 4, DRAM Phy Critical Interrupt 5, DRAM Phy Critical Interrupt 6, DRAM Phy Critical Interrupt 7, DRAM Phy Critical Interrupt 8, DRAM Phy Critical Interrupt 9, DRAM Phy Critical Interrupt 10, DRAM Phy Critical Interrupt 11, DRAM Phy Critical Interrupt 12, DRAM Phy Critical Interrupt 13, DRAM Phy Critical Interrupt 14, DRAM Phy Critical Interrupt 15 Module=DDR_TOP IRQSTEERM7 extend(bitoffset[2] - inputs[706]) IRQ=944*/
    .long   DCIF_CPU_DOMAIN0_IRQHandler                     /* DISPLAYMIX DCIF: Interrupt output for CPU domain0 (Controlled by common registers group) Module=DCIF1 IRQSTEERM7 extend(bitoffset[3] - inputs[707]) IRQ=945*/
    .long   DCIF_CPU_DOMAIN1_IRQHandler                     /* DISPLAYMIX DCIF: Interrupt output for CPU domain1 (Controlled by background layer registers group) Module=DCIF1 IRQSTEERM7 extend(bitoffset[4] - inputs[708]) IRQ=946*/
    .long   DCIF_CPU_DOMAIN2_IRQHandler                     /* DISPLAYMIX DCIF: Interrupt output for CPU domain2 (Controlled by foreground layer registers group) Module=DCIF1 IRQSTEERM7 extend(bitoffset[5] - inputs[709]) IRQ=947*/
    .long   Reserved964_IRQHandler                          /* Reserved for DCIF/PXP, IP is under development Module=NAN IRQSTEERM7 extend(bitoffset[6] - inputs[710]) IRQ=948*/
    .long   Reserved965_IRQHandler                          /* Reserved for DCIF/PXP, IP is under development Module=NAN IRQSTEERM7 extend(bitoffset[7] - inputs[711]) IRQ=949*/
    .long   PXP_0_IRQHandler                                /* DISPLAYMIX PXP Module=PXP IRQSTEERM7 extend(bitoffset[8] - inputs[712]) IRQ=950*/
    .long   PXP_1_IRQHandler                                /* DISPLAYMIX PXP Module=PXP IRQSTEERM7 extend(bitoffset[9] - inputs[713]) IRQ=951*/
    .long   Reserved968_IRQHandler                          /* V2X-FH MU APSHE (SHE) A_TX interrupt, V2X-FH MU APSHE (SHE) A_RX interrupt Module=V2X_FH IRQSTEERM7 extend(bitoffset[10] - inputs[714]) IRQ=952*/
    .long   Reserved969_IRQHandler                          /* V2X-FH MU SCU/APDEBUG (DEBUG) B_TX interrupt, V2X-FH MU SCU/APDEBUG (DEBUG) B_RX interrupt Module=V2X_FH IRQSTEERM7 extend(bitoffset[11] - inputs[715]) IRQ=953*/
    .long   Reserved970_IRQHandler                          /* USB-1 (USB 3.0) Wake-up Interrupt Module=USB1 IRQSTEERM7 extend(bitoffset[12] - inputs[716]) IRQ=954*/
    .long   Reserved971_IRQHandler                          /* USB-2 (USB 2.0) Wake-up Interrupt Module=USB2 IRQSTEERM7 extend(bitoffset[13] - inputs[717]) IRQ=955*/
    .long   Reserved972_IRQHandler                          /* GIC700 PMU Counter Overflow Module=GIC700 IRQSTEERM7 extend(bitoffset[14] - inputs[718]) IRQ=956*/
    .long   Reserved973_IRQHandler                          /* cdbgpwrupreq_irq Module=INTG_BOOTROM_DEBUG_CTRL IRQSTEERM7 extend(bitoffset[15] - inputs[719]) IRQ=957*/
    .long   Reserved974_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[720]) IRQ=958*/
    .long   Reserved975_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[721]) IRQ=959*/
    .long   Reserved976_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[722]) IRQ=960*/
    .long   Reserved977_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[723]) IRQ=961*/
    .long   Reserved978_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[724]) IRQ=962*/
    .long   Reserved979_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[725]) IRQ=963*/
    .long   Reserved980_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[726]) IRQ=964*/
    .long   Reserved981_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[727]) IRQ=965*/
    .long   Reserved982_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[728]) IRQ=966*/
    .long   Reserved983_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[729]) IRQ=967*/
    .long   Reserved984_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[730]) IRQ=968*/
    .long   Reserved985_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[731]) IRQ=969*/
    .long   Reserved986_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[732]) IRQ=970*/
    .long   Reserved987_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[733]) IRQ=971*/
    .long   Reserved988_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[734]) IRQ=972*/
    .long   Reserved989_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[735]) IRQ=973*/
    .long   Reserved990_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[736]) IRQ=974*/
    .long   Reserved991_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[737]) IRQ=975*/
    .long   Reserved992_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[738]) IRQ=976*/
    .long   Reserved993_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[739]) IRQ=977*/
    .long   Reserved994_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[740]) IRQ=978*/
    .long   Reserved995_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[741]) IRQ=979*/
    .long   Reserved996_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[742]) IRQ=980*/
    .long   Reserved997_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[743]) IRQ=981*/
    .long   Reserved998_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[744]) IRQ=982*/
    .long   Reserved999_IRQHandler                          /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[745]) IRQ=983*/
    .long   Reserved1000_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[746]) IRQ=984*/
    .long   Reserved1001_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[747]) IRQ=985*/
    .long   Reserved1002_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[748]) IRQ=986*/
    .long   Reserved1003_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[749]) IRQ=987*/
    .long   Reserved1004_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[750]) IRQ=988*/
    .long   Reserved1005_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[751]) IRQ=989*/
    .long   Reserved1006_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[752]) IRQ=990*/
    .long   Reserved1007_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[753]) IRQ=991*/
    .long   Reserved1008_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[754]) IRQ=992*/
    .long   Reserved1009_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[755]) IRQ=993*/
    .long   Reserved1010_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[756]) IRQ=994*/
    .long   Reserved1011_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[757]) IRQ=995*/
    .long   Reserved1012_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[758]) IRQ=996*/
    .long   Reserved1013_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[759]) IRQ=997*/
    .long   Reserved1014_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[760]) IRQ=998*/
    .long   Reserved1015_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[761]) IRQ=999*/
    .long   Reserved1016_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[762]) IRQ=1000*/
    .long   Reserved1017_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[763]) IRQ=1001*/
    .long   Reserved1018_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[764]) IRQ=1002*/
    .long   Reserved1019_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[765]) IRQ=1003*/
    .long   Reserved1020_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[766]) IRQ=1004*/
    .long   Reserved1021_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[767]) IRQ=1005*/
    .long   XSPI1_IRQHandler                                /* xspi1 all interrupts ORed output for EENV0 (MEENV), xspi1 arbitration lock timeout interrupt for EENV0, xspi1 arbitration win interrupt for EENV0, xspi1 FlashA error interrupt for EENV0 Module=XSPI1 IRQSTEERM7 extend(bitoffset[0] - inputs[768]) IRQ=1006*/
    .long   Reserved1023_IRQHandler                         /* xspi1 all interrupts ORed output for EENV1 (MEENV), xspi1 arbitration lock timeout interrupt for EENV1, xspi1 arbitration win interrupt for EENV1, xspi1 FlashA error interrupt for EENV1 Module=XSPI1 IRQSTEERM7 extend(bitoffset[1] - inputs[769]) IRQ=1007*/
    .long   Reserved1024_IRQHandler                         /* xspi1 all interrupts ORed output for EENV2 (MEENV), xspi1 arbitration lock timeout interrupt for EENV2, xspi1 arbitration win interrupt for EENV2, xspi1 FlashA error interrupt for EENV2 Module=XSPI1 IRQSTEERM7 extend(bitoffset[2] - inputs[770]) IRQ=1008*/
    .long   Reserved1025_IRQHandler                         /* xspi1 all interrupts ORed output for EENV3 (MEENV), xspi1 arbitration lock timeout interrupt for EENV3, xspi1 arbitration win interrupt for EENV3, xspi1 FlashA error interrupt for EENV3 Module=XSPI1 IRQSTEERM7 extend(bitoffset[3] - inputs[771]) IRQ=1009*/
    .long   Reserved1026_IRQHandler                         /* xspi1 all interrupts ORed output for EENV4 (MEENV), xspi1 arbitration lock timeout interrupt for EENV4, xspi1 arbitration win interrupt for EENV4, xspi1 FlashA error interrupt for EENV4 Module=XSPI1 IRQSTEERM7 extend(bitoffset[4] - inputs[772]) IRQ=1010*/
    .long   XSPI2_IRQHandler                                /* xspi2 all interrupts ORed output for EENV0 (MEENV), xspi2 arbitration lock timeout interrupt for EENV0, xspi2 arbitration win interrupt for EENV0, xspi2 FlashA error interrupt for EENV0 Module=XSPI2 IRQSTEERM7 extend(bitoffset[5] - inputs[773]) IRQ=1011*/
    .long   Reserved1028_IRQHandler                         /* xspi2 all interrupts ORed output for EENV1 (MEENV), xspi2 arbitration lock timeout interrupt for EENV1, xspi2 arbitration win interrupt for EENV1, xspi2 FlashA error interrupt for EENV1 Module=XSPI2 IRQSTEERM7 extend(bitoffset[6] - inputs[774]) IRQ=1012*/
    .long   Reserved1029_IRQHandler                         /* xspi2 all interrupts ORed output for EENV2 (MEENV), xspi2 arbitration lock timeout interrupt for EENV2, xspi2 arbitration win interrupt for EENV2, xspi2 FlashA error interrupt for EENV2 Module=XSPI2 IRQSTEERM7 extend(bitoffset[7] - inputs[775]) IRQ=1013*/
    .long   Reserved1030_IRQHandler                         /* xspi2 all interrupts ORed output for EENV3 (MEENV), xspi2 arbitration lock timeout interrupt for EENV3, xspi2 arbitration win interrupt for EENV3, xspi2 FlashA error interrupt for EENV3 Module=XSPI2 IRQSTEERM7 extend(bitoffset[8] - inputs[776]) IRQ=1014*/
    .long   Reserved1031_IRQHandler                         /* xspi2 all interrupts ORed output for EENV4 (MEENV), xspi2 arbitration lock timeout interrupt for EENV4, xspi2 arbitration win interrupt for EENV4, xspi2 FlashA error interrupt for EENV4 Module=XSPI2 IRQSTEERM7 extend(bitoffset[9] - inputs[777]) IRQ=1015*/
    .long   Reserved1032_IRQHandler                         /* Reserved Module=NAN IRQSTEERM7 extend(bitoffset[10] - inputs[778]) IRQ=1016*/
    .long   Reserved1033_IRQHandler                         /* Reserved Module=NAN IRQSTEERM7 extend(bitoffset[11] - inputs[779]) IRQ=1017*/
    .long   Reserved1034_IRQHandler                         /* Reserved Module=NAN IRQSTEERM7 extend(bitoffset[12] - inputs[780]) IRQ=1018*/
    .long   Reserved1035_IRQHandler                         /* Reserved Module=NAN IRQSTEERM7 extend(bitoffset[13] - inputs[781]) IRQ=1019*/
    .long   Reserved1036_IRQHandler                         /* Reserved Module=NAN IRQSTEERM7 extend(bitoffset[14] - inputs[782]) IRQ=1020*/
    .long   Reserved1037_IRQHandler                         /* Reserved Module=NAN IRQSTEERM7 extend(bitoffset[15] - inputs[783]) IRQ=1021*/
    .long   Reserved1038_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[784]) IRQ=1022*/
    .long   Reserved1039_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[785]) IRQ=1023*/
    .long   Reserved1040_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[786]) IRQ=1024*/
    .long   Reserved1041_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[787]) IRQ=1025*/
    .long   Reserved1042_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[788]) IRQ=1026*/
    .long   Reserved1043_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[789]) IRQ=1027*/
    .long   Reserved1044_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[790]) IRQ=1028*/
    .long   Reserved1045_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[791]) IRQ=1029*/
    .long   Reserved1046_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[792]) IRQ=1030*/
    .long   Reserved1047_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[793]) IRQ=1031*/
    .long   Reserved1048_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[794]) IRQ=1032*/
    .long   Reserved1049_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[795]) IRQ=1033*/
    .long   Reserved1050_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[796]) IRQ=1034*/
    .long   Reserved1051_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[797]) IRQ=1035*/
    .long   Reserved1052_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[798]) IRQ=1036*/
    .long   Reserved1053_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[799]) IRQ=1037*/
    .long   Reserved1054_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[800]) IRQ=1038*/
    .long   Reserved1055_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[801]) IRQ=1039*/
    .long   Reserved1056_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[802]) IRQ=1040*/
    .long   Reserved1057_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[803]) IRQ=1041*/
    .long   Reserved1058_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[804]) IRQ=1042*/
    .long   Reserved1059_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[805]) IRQ=1043*/
    .long   Reserved1060_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[806]) IRQ=1044*/
    .long   Reserved1061_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[807]) IRQ=1045*/
    .long   Reserved1062_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[808]) IRQ=1046*/
    .long   Reserved1063_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[809]) IRQ=1047*/
    .long   Reserved1064_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[810]) IRQ=1048*/
    .long   Reserved1065_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[811]) IRQ=1049*/
    .long   Reserved1066_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[812]) IRQ=1050*/
    .long   Reserved1067_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[813]) IRQ=1051*/
    .long   Reserved1068_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[814]) IRQ=1052*/
    .long   Reserved1069_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[815]) IRQ=1053*/
    .long   Reserved1070_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[816]) IRQ=1054*/
    .long   Reserved1071_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[817]) IRQ=1055*/
    .long   Reserved1072_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[818]) IRQ=1056*/
    .long   Reserved1073_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[819]) IRQ=1057*/
    .long   Reserved1074_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[820]) IRQ=1058*/
    .long   Reserved1075_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[821]) IRQ=1059*/
    .long   Reserved1076_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[822]) IRQ=1060*/
    .long   Reserved1077_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[823]) IRQ=1061*/
    .long   Reserved1078_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[824]) IRQ=1062*/
    .long   Reserved1079_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[825]) IRQ=1063*/
    .long   Reserved1080_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[826]) IRQ=1064*/
    .long   Reserved1081_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[827]) IRQ=1065*/
    .long   Reserved1082_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[828]) IRQ=1066*/
    .long   Reserved1083_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[829]) IRQ=1067*/
    .long   Reserved1084_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[830]) IRQ=1068*/
    .long   Reserved1085_IRQHandler                         /* Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[831]) IRQ=1069*/
    .long   0xFFFFFFFF                                      /*  Reserved for user TRIM value*/

    .size   __isr_vector, . - __isr_vector

    .text
    .thumb

#if defined (__cplusplus)
#ifdef __REDLIB__
#error Redlib does not support C++
#endif
#endif
/* Reset Handler */

    .thumb_func
    .align 2
    .globl   Reset_Handler
    .weak    Reset_Handler
    .type    Reset_Handler, %function
Reset_Handler:
    cpsid   i               /* Mask interrupts */
    .equ    VTOR, 0xE000ED08
    ldr     r0, =VTOR
    ldr     r1, =__isr_vector
    str     r1, [r0]
    ldr     r2, [r1]
    msr     msp, r2

    /* Add stack / heap initializaiton */
    movs    r0, 0
    ldr     r1, =__HeapBase
    ldr     r2, =__HeapLimit
.heap_init:
    cmp     r1, r2
    itt     lt
    strlt   r0, [r1], #4
    blt     .heap_init

    ldr     r1, =__StackLimit
    ldr     r2, =__StackTop
.stack_init:
    cmp     r1, r2
    itt     lt
    strlt   r0, [r1], #4
    blt     .stack_init
    /*End of stack / heap initializaiton */

#ifndef __NO_SYSTEM_INIT
    ldr   r0,=SystemInit
    blx   r0
#endif
/*     Loop to copy data from read only memory to RAM. The ranges
 *      of copy from/to are specified by following symbols evaluated in
 *      linker script.
 *      __etext: End of code section, i.e., begin of data sections to copy from.
 *      __data_start__/__data_end__: RAM address range that data should be
 *      __noncachedata_start__/__noncachedata_end__ : none cachable region
 *      copied to. Both must be aligned to 4 bytes boundary.  */

    ldr    r1, =__etext
    ldr    r2, =__data_start__
    ldr    r3, =__data_end__

#ifdef __PERFORMANCE_IMPLEMENTATION
/* Here are two copies of loop implementations. First one favors performance
 * and the second one favors code size. Default uses the second one.
 * Define macro "__PERFORMANCE_IMPLEMENTATION" in project to use the first one */
    subs    r3, r2
    ble    .LC1
.LC0:
    subs    r3, #4
    ldr    r0, [r1, r3]
    str    r0, [r2, r3]
    bgt    .LC0
.LC1:
#else  /* code size implemenation */
.LC0:
    cmp     r2, r3
    ittt    lt
    ldrlt   r0, [r1], #4
    strlt   r0, [r2], #4
    blt    .LC0
#endif
#ifdef __STARTUP_INITIALIZE_NONCACHEDATA
    ldr    r2, =__noncachedata_start__
    ldr    r3, =__noncachedata_init_end__
#ifdef __PERFORMANCE_IMPLEMENTATION
/* Here are two copies of loop implementations. First one favors performance
 * and the second one favors code size. Default uses the second one.
 * Define macro "__PERFORMANCE_IMPLEMENTATION" in project to use the first one */
    subs    r3, r2
    ble    .LC3
.LC2:
    subs    r3, #4
    ldr    r0, [r1, r3]
    str    r0, [r2, r3]
    bgt    .LC2
.LC3:
#else  /* code size implemenation */
.LC2:
    cmp     r2, r3
    ittt    lt
    ldrlt   r0, [r1], #4
    strlt   r0, [r2], #4
    blt    .LC2
#endif
/* zero inited ncache section initialization */
    ldr r3, =__noncachedata_end__
    movs    r0,0
.LC4:
    cmp    r2,r3
    itt    lt
    strlt   r0,[r2],#4
    blt    .LC4
#endif /* __STARTUP_INITIALIZE_NONCACHEDATA */

#ifdef __STARTUP_CLEAR_BSS
/*     This part of work usually is done in C library startup code. Otherwise,
 *     define this macro to enable it in this startup.
 *
 *     Loop to zero out BSS section, which uses following symbols
 *     in linker script:
 *      __bss_start__: start of BSS section. Must align to 4
 *      __bss_end__: end of BSS section. Must align to 4
 */
    ldr r1, =__bss_start__
    ldr r2, =__bss_end__

    movs    r0, 0
.LC5:
    cmp     r1, r2
    itt    lt
    strlt   r0, [r1], #4
    blt    .LC5
#endif /* __STARTUP_CLEAR_BSS */

    cpsie   i               /* Unmask interrupts */
#ifndef __START
#ifdef __REDLIB__
#define __START __main
#else
#define __START _start
#endif
#endif
#ifndef __ATOLLIC__
    ldr   r0,=__START
    blx   r0
#else
    ldr   r0,=__libc_init_array
    blx   r0
    ldr   r0,=main
    bx    r0
#endif
    .pool
    .size Reset_Handler, . - Reset_Handler

    .align  1
    .thumb_func
    .weak DefaultISR
    .type DefaultISR, %function
DefaultISR:
    b DefaultISR
    .size DefaultISR, . - DefaultISR

    .align 1
    .thumb_func
    .weak NMI_Handler
    .type NMI_Handler, %function
NMI_Handler:
    ldr   r0,=NMI_Handler
    bx    r0
    .size NMI_Handler, . - NMI_Handler

    .align 1
    .thumb_func
    .weak HardFault_Handler
    .type HardFault_Handler, %function
HardFault_Handler:
    ldr   r0,=HardFault_Handler
    bx    r0
    .size HardFault_Handler, . - HardFault_Handler

    .align 1
    .thumb_func
    .weak SVC_Handler
    .type SVC_Handler, %function
SVC_Handler:
    ldr   r0,=SVC_Handler
    bx    r0
    .size SVC_Handler, . - SVC_Handler

    .align 1
    .thumb_func
    .weak PendSV_Handler
    .type PendSV_Handler, %function
PendSV_Handler:
    ldr   r0,=PendSV_Handler
    bx    r0
    .size PendSV_Handler, . - PendSV_Handler

    .align 1
    .thumb_func
    .weak SysTick_Handler
    .type SysTick_Handler, %function
SysTick_Handler:
    ldr   r0,=SysTick_Handler
    bx    r0
    .size SysTick_Handler, . - SysTick_Handler

    .align 1
    .thumb_func
    .weak CAN1_IRQHandler
    .type CAN1_IRQHandler, %function
CAN1_IRQHandler:
    ldr   r0,=CAN1_DriverIRQHandler
    bx    r0
    .size CAN1_IRQHandler, . - CAN1_IRQHandler

    .align 1
    .thumb_func
    .weak CAN1_ERROR_IRQHandler
    .type CAN1_ERROR_IRQHandler, %function
CAN1_ERROR_IRQHandler:
    ldr   r0,=CAN1_ERROR_DriverIRQHandler
    bx    r0
    .size CAN1_ERROR_IRQHandler, . - CAN1_ERROR_IRQHandler

    .align 1
    .thumb_func
    .weak I3C1_IRQHandler
    .type I3C1_IRQHandler, %function
I3C1_IRQHandler:
    ldr   r0,=I3C1_DriverIRQHandler
    bx    r0
    .size I3C1_IRQHandler, . - I3C1_IRQHandler

    .align 1
    .thumb_func
    .weak LPI2C1_IRQHandler
    .type LPI2C1_IRQHandler, %function
LPI2C1_IRQHandler:
    ldr   r0,=LPI2C1_DriverIRQHandler
    bx    r0
    .size LPI2C1_IRQHandler, . - LPI2C1_IRQHandler

    .align 1
    .thumb_func
    .weak LPI2C2_IRQHandler
    .type LPI2C2_IRQHandler, %function
LPI2C2_IRQHandler:
    ldr   r0,=LPI2C2_DriverIRQHandler
    bx    r0
    .size LPI2C2_IRQHandler, . - LPI2C2_IRQHandler

    .align 1
    .thumb_func
    .weak LPSPI1_IRQHandler
    .type LPSPI1_IRQHandler, %function
LPSPI1_IRQHandler:
    ldr   r0,=LPSPI1_DriverIRQHandler
    bx    r0
    .size LPSPI1_IRQHandler, . - LPSPI1_IRQHandler

    .align 1
    .thumb_func
    .weak LPSPI2_IRQHandler
    .type LPSPI2_IRQHandler, %function
LPSPI2_IRQHandler:
    ldr   r0,=LPSPI2_DriverIRQHandler
    bx    r0
    .size LPSPI2_IRQHandler, . - LPSPI2_IRQHandler

    .align 1
    .thumb_func
    .weak LPUART1_IRQHandler
    .type LPUART1_IRQHandler, %function
LPUART1_IRQHandler:
    ldr   r0,=LPUART1_DriverIRQHandler
    bx    r0
    .size LPUART1_IRQHandler, . - LPUART1_IRQHandler

    .align 1
    .thumb_func
    .weak LPUART2_IRQHandler
    .type LPUART2_IRQHandler, %function
LPUART2_IRQHandler:
    ldr   r0,=LPUART2_DriverIRQHandler
    bx    r0
    .size LPUART2_IRQHandler, . - LPUART2_IRQHandler

    .align 1
    .thumb_func
    .weak SAI1_IRQHandler
    .type SAI1_IRQHandler, %function
SAI1_IRQHandler:
    ldr   r0,=SAI1_DriverIRQHandler
    bx    r0
    .size SAI1_IRQHandler, . - SAI1_IRQHandler

    .align 1
    .thumb_func
    .weak CAN2_IRQHandler
    .type CAN2_IRQHandler, %function
CAN2_IRQHandler:
    ldr   r0,=CAN2_DriverIRQHandler
    bx    r0
    .size CAN2_IRQHandler, . - CAN2_IRQHandler

    .align 1
    .thumb_func
    .weak CAN2_ERROR_IRQHandler
    .type CAN2_ERROR_IRQHandler, %function
CAN2_ERROR_IRQHandler:
    ldr   r0,=CAN2_ERROR_DriverIRQHandler
    bx    r0
    .size CAN2_ERROR_IRQHandler, . - CAN2_ERROR_IRQHandler

    .align 1
    .thumb_func
    .weak CAN3_IRQHandler
    .type CAN3_IRQHandler, %function
CAN3_IRQHandler:
    ldr   r0,=CAN3_DriverIRQHandler
    bx    r0
    .size CAN3_IRQHandler, . - CAN3_IRQHandler

    .align 1
    .thumb_func
    .weak CAN3_ERROR_IRQHandler
    .type CAN3_ERROR_IRQHandler, %function
CAN3_ERROR_IRQHandler:
    ldr   r0,=CAN3_ERROR_DriverIRQHandler
    bx    r0
    .size CAN3_ERROR_IRQHandler, . - CAN3_ERROR_IRQHandler

    .align 1
    .thumb_func
    .weak CAN4_IRQHandler
    .type CAN4_IRQHandler, %function
CAN4_IRQHandler:
    ldr   r0,=CAN4_DriverIRQHandler
    bx    r0
    .size CAN4_IRQHandler, . - CAN4_IRQHandler

    .align 1
    .thumb_func
    .weak CAN4_ERROR_IRQHandler
    .type CAN4_ERROR_IRQHandler, %function
CAN4_ERROR_IRQHandler:
    ldr   r0,=CAN4_ERROR_DriverIRQHandler
    bx    r0
    .size CAN4_ERROR_IRQHandler, . - CAN4_ERROR_IRQHandler

    .align 1
    .thumb_func
    .weak CAN5_IRQHandler
    .type CAN5_IRQHandler, %function
CAN5_IRQHandler:
    ldr   r0,=CAN5_DriverIRQHandler
    bx    r0
    .size CAN5_IRQHandler, . - CAN5_IRQHandler

    .align 1
    .thumb_func
    .weak CAN5_ERROR_IRQHandler
    .type CAN5_ERROR_IRQHandler, %function
CAN5_ERROR_IRQHandler:
    ldr   r0,=CAN5_ERROR_DriverIRQHandler
    bx    r0
    .size CAN5_ERROR_IRQHandler, . - CAN5_ERROR_IRQHandler

    .align 1
    .thumb_func
    .weak FLEXIO1_IRQHandler
    .type FLEXIO1_IRQHandler, %function
FLEXIO1_IRQHandler:
    ldr   r0,=FLEXIO1_DriverIRQHandler
    bx    r0
    .size FLEXIO1_IRQHandler, . - FLEXIO1_IRQHandler

    .align 1
    .thumb_func
    .weak FLEXIO2_IRQHandler
    .type FLEXIO2_IRQHandler, %function
FLEXIO2_IRQHandler:
    ldr   r0,=FLEXIO2_DriverIRQHandler
    bx    r0
    .size FLEXIO2_IRQHandler, . - FLEXIO2_IRQHandler

    .align 1
    .thumb_func
    .weak FLEXIO3_IRQHandler
    .type FLEXIO3_IRQHandler, %function
FLEXIO3_IRQHandler:
    ldr   r0,=FLEXIO3_DriverIRQHandler
    bx    r0
    .size FLEXIO3_IRQHandler, . - FLEXIO3_IRQHandler

    .align 1
    .thumb_func
    .weak FLEXIO4_IRQHandler
    .type FLEXIO4_IRQHandler, %function
FLEXIO4_IRQHandler:
    ldr   r0,=FLEXIO4_DriverIRQHandler
    bx    r0
    .size FLEXIO4_IRQHandler, . - FLEXIO4_IRQHandler

    .align 1
    .thumb_func
    .weak I3C2_IRQHandler
    .type I3C2_IRQHandler, %function
I3C2_IRQHandler:
    ldr   r0,=I3C2_DriverIRQHandler
    bx    r0
    .size I3C2_IRQHandler, . - I3C2_IRQHandler

    .align 1
    .thumb_func
    .weak LPI2C3_IRQHandler
    .type LPI2C3_IRQHandler, %function
LPI2C3_IRQHandler:
    ldr   r0,=LPI2C3_DriverIRQHandler
    bx    r0
    .size LPI2C3_IRQHandler, . - LPI2C3_IRQHandler

    .align 1
    .thumb_func
    .weak LPI2C4_IRQHandler
    .type LPI2C4_IRQHandler, %function
LPI2C4_IRQHandler:
    ldr   r0,=LPI2C4_DriverIRQHandler
    bx    r0
    .size LPI2C4_IRQHandler, . - LPI2C4_IRQHandler

    .align 1
    .thumb_func
    .weak LPSPI3_IRQHandler
    .type LPSPI3_IRQHandler, %function
LPSPI3_IRQHandler:
    ldr   r0,=LPSPI3_DriverIRQHandler
    bx    r0
    .size LPSPI3_IRQHandler, . - LPSPI3_IRQHandler

    .align 1
    .thumb_func
    .weak LPSPI4_IRQHandler
    .type LPSPI4_IRQHandler, %function
LPSPI4_IRQHandler:
    ldr   r0,=LPSPI4_DriverIRQHandler
    bx    r0
    .size LPSPI4_IRQHandler, . - LPSPI4_IRQHandler

    .align 1
    .thumb_func
    .weak LPUART3_IRQHandler
    .type LPUART3_IRQHandler, %function
LPUART3_IRQHandler:
    ldr   r0,=LPUART3_DriverIRQHandler
    bx    r0
    .size LPUART3_IRQHandler, . - LPUART3_IRQHandler

    .align 1
    .thumb_func
    .weak LPUART4_IRQHandler
    .type LPUART4_IRQHandler, %function
LPUART4_IRQHandler:
    ldr   r0,=LPUART4_DriverIRQHandler
    bx    r0
    .size LPUART4_IRQHandler, . - LPUART4_IRQHandler

    .align 1
    .thumb_func
    .weak LPUART5_IRQHandler
    .type LPUART5_IRQHandler, %function
LPUART5_IRQHandler:
    ldr   r0,=LPUART5_DriverIRQHandler
    bx    r0
    .size LPUART5_IRQHandler, . - LPUART5_IRQHandler

    .align 1
    .thumb_func
    .weak LPUART6_IRQHandler
    .type LPUART6_IRQHandler, %function
LPUART6_IRQHandler:
    ldr   r0,=LPUART6_DriverIRQHandler
    bx    r0
    .size LPUART6_IRQHandler, . - LPUART6_IRQHandler

    .align 1
    .thumb_func
    .weak LPUART7_IRQHandler
    .type LPUART7_IRQHandler, %function
LPUART7_IRQHandler:
    ldr   r0,=LPUART7_DriverIRQHandler
    bx    r0
    .size LPUART7_IRQHandler, . - LPUART7_IRQHandler

    .align 1
    .thumb_func
    .weak LPUART8_IRQHandler
    .type LPUART8_IRQHandler, %function
LPUART8_IRQHandler:
    ldr   r0,=LPUART8_DriverIRQHandler
    bx    r0
    .size LPUART8_IRQHandler, . - LPUART8_IRQHandler

    .align 1
    .thumb_func
    .weak LPUART9_IRQHandler
    .type LPUART9_IRQHandler, %function
LPUART9_IRQHandler:
    ldr   r0,=LPUART9_DriverIRQHandler
    bx    r0
    .size LPUART9_IRQHandler, . - LPUART9_IRQHandler

    .align 1
    .thumb_func
    .weak LPUART10_IRQHandler
    .type LPUART10_IRQHandler, %function
LPUART10_IRQHandler:
    ldr   r0,=LPUART10_DriverIRQHandler
    bx    r0
    .size LPUART10_IRQHandler, . - LPUART10_IRQHandler

    .align 1
    .thumb_func
    .weak LPUART11_IRQHandler
    .type LPUART11_IRQHandler, %function
LPUART11_IRQHandler:
    ldr   r0,=LPUART11_DriverIRQHandler
    bx    r0
    .size LPUART11_IRQHandler, . - LPUART11_IRQHandler

    .align 1
    .thumb_func
    .weak LPUART12_IRQHandler
    .type LPUART12_IRQHandler, %function
LPUART12_IRQHandler:
    ldr   r0,=LPUART12_DriverIRQHandler
    bx    r0
    .size LPUART12_IRQHandler, . - LPUART12_IRQHandler

    .align 1
    .thumb_func
    .weak USDHC1_IRQHandler
    .type USDHC1_IRQHandler, %function
USDHC1_IRQHandler:
    ldr   r0,=USDHC1_DriverIRQHandler
    bx    r0
    .size USDHC1_IRQHandler, . - USDHC1_IRQHandler

    .align 1
    .thumb_func
    .weak USDHC2_IRQHandler
    .type USDHC2_IRQHandler, %function
USDHC2_IRQHandler:
    ldr   r0,=USDHC2_DriverIRQHandler
    bx    r0
    .size USDHC2_IRQHandler, . - USDHC2_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_ERROR_IRQHandler
    .type EDMA2_ERROR_IRQHandler, %function
EDMA2_ERROR_IRQHandler:
    ldr   r0,=EDMA2_ERROR_DriverIRQHandler
    bx    r0
    .size EDMA2_ERROR_IRQHandler, . - EDMA2_ERROR_IRQHandler

    .align 1
    .thumb_func
    .weak SAI2_IRQHandler
    .type SAI2_IRQHandler, %function
SAI2_IRQHandler:
    ldr   r0,=SAI2_DriverIRQHandler
    bx    r0
    .size SAI2_IRQHandler, . - SAI2_IRQHandler

    .align 1
    .thumb_func
    .weak SAI3_IRQHandler
    .type SAI3_IRQHandler, %function
SAI3_IRQHandler:
    ldr   r0,=SAI3_DriverIRQHandler
    bx    r0
    .size SAI3_IRQHandler, . - SAI3_IRQHandler

    .align 1
    .thumb_func
    .weak SAI4_IRQHandler
    .type SAI4_IRQHandler, %function
SAI4_IRQHandler:
    ldr   r0,=SAI4_DriverIRQHandler
    bx    r0
    .size SAI4_IRQHandler, . - SAI4_IRQHandler

    .align 1
    .thumb_func
    .weak LPSPI5_IRQHandler
    .type LPSPI5_IRQHandler, %function
LPSPI5_IRQHandler:
    ldr   r0,=LPSPI5_DriverIRQHandler
    bx    r0
    .size LPSPI5_IRQHandler, . - LPSPI5_IRQHandler

    .align 1
    .thumb_func
    .weak LPSPI6_IRQHandler
    .type LPSPI6_IRQHandler, %function
LPSPI6_IRQHandler:
    ldr   r0,=LPSPI6_DriverIRQHandler
    bx    r0
    .size LPSPI6_IRQHandler, . - LPSPI6_IRQHandler

    .align 1
    .thumb_func
    .weak LPSPI7_IRQHandler
    .type LPSPI7_IRQHandler, %function
LPSPI7_IRQHandler:
    ldr   r0,=LPSPI7_DriverIRQHandler
    bx    r0
    .size LPSPI7_IRQHandler, . - LPSPI7_IRQHandler

    .align 1
    .thumb_func
    .weak LPSPI8_IRQHandler
    .type LPSPI8_IRQHandler, %function
LPSPI8_IRQHandler:
    ldr   r0,=LPSPI8_DriverIRQHandler
    bx    r0
    .size LPSPI8_IRQHandler, . - LPSPI8_IRQHandler

    .align 1
    .thumb_func
    .weak LPI2C5_IRQHandler
    .type LPI2C5_IRQHandler, %function
LPI2C5_IRQHandler:
    ldr   r0,=LPI2C5_DriverIRQHandler
    bx    r0
    .size LPI2C5_IRQHandler, . - LPI2C5_IRQHandler

    .align 1
    .thumb_func
    .weak LPI2C6_IRQHandler
    .type LPI2C6_IRQHandler, %function
LPI2C6_IRQHandler:
    ldr   r0,=LPI2C6_DriverIRQHandler
    bx    r0
    .size LPI2C6_IRQHandler, . - LPI2C6_IRQHandler

    .align 1
    .thumb_func
    .weak LPI2C7_IRQHandler
    .type LPI2C7_IRQHandler, %function
LPI2C7_IRQHandler:
    ldr   r0,=LPI2C7_DriverIRQHandler
    bx    r0
    .size LPI2C7_IRQHandler, . - LPI2C7_IRQHandler

    .align 1
    .thumb_func
    .weak LPI2C8_IRQHandler
    .type LPI2C8_IRQHandler, %function
LPI2C8_IRQHandler:
    ldr   r0,=LPI2C8_DriverIRQHandler
    bx    r0
    .size LPI2C8_IRQHandler, . - LPI2C8_IRQHandler

    .align 1
    .thumb_func
    .weak PDM_EVENT_IRQHandler
    .type PDM_EVENT_IRQHandler, %function
PDM_EVENT_IRQHandler:
    ldr   r0,=PDM_EVENT_DriverIRQHandler
    bx    r0
    .size PDM_EVENT_IRQHandler, . - PDM_EVENT_IRQHandler

    .align 1
    .thumb_func
    .weak USDHC3_IRQHandler
    .type USDHC3_IRQHandler, %function
USDHC3_IRQHandler:
    ldr   r0,=USDHC3_DriverIRQHandler
    bx    r0
    .size USDHC3_IRQHandler, . - USDHC3_IRQHandler

    .align 1
    .thumb_func
    .weak XSPI_SLV_IRQHandler
    .type XSPI_SLV_IRQHandler, %function
XSPI_SLV_IRQHandler:
    ldr   r0,=XSPI_SLV_DriverIRQHandler
    bx    r0
    .size XSPI_SLV_IRQHandler, . - XSPI_SLV_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_ERROR_IRQHandler
    .type EDMA4_ERROR_IRQHandler, %function
EDMA4_ERROR_IRQHandler:
    ldr   r0,=EDMA4_ERROR_DriverIRQHandler
    bx    r0
    .size EDMA4_ERROR_IRQHandler, . - EDMA4_ERROR_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEERM7_CH0_IRQHandler
    .type IRQSTEERM7_CH0_IRQHandler, %function
IRQSTEERM7_CH0_IRQHandler:
    ldr   r0,=IRQSTEERM7_CH0_DriverIRQHandler
    bx    r0
    .size IRQSTEERM7_CH0_IRQHandler, . - IRQSTEERM7_CH0_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEERM7_CH1_IRQHandler
    .type IRQSTEERM7_CH1_IRQHandler, %function
IRQSTEERM7_CH1_IRQHandler:
    ldr   r0,=IRQSTEERM7_CH1_DriverIRQHandler
    bx    r0
    .size IRQSTEERM7_CH1_IRQHandler, . - IRQSTEERM7_CH1_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEERM7_CH2_IRQHandler
    .type IRQSTEERM7_CH2_IRQHandler, %function
IRQSTEERM7_CH2_IRQHandler:
    ldr   r0,=IRQSTEERM7_CH2_DriverIRQHandler
    bx    r0
    .size IRQSTEERM7_CH2_IRQHandler, . - IRQSTEERM7_CH2_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEERM7_CH3_IRQHandler
    .type IRQSTEERM7_CH3_IRQHandler, %function
IRQSTEERM7_CH3_IRQHandler:
    ldr   r0,=IRQSTEERM7_CH3_DriverIRQHandler
    bx    r0
    .size IRQSTEERM7_CH3_IRQHandler, . - IRQSTEERM7_CH3_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEERM7_CH4_IRQHandler
    .type IRQSTEERM7_CH4_IRQHandler, %function
IRQSTEERM7_CH4_IRQHandler:
    ldr   r0,=IRQSTEERM7_CH4_DriverIRQHandler
    bx    r0
    .size IRQSTEERM7_CH4_IRQHandler, . - IRQSTEERM7_CH4_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEERM7_CH5_IRQHandler
    .type IRQSTEERM7_CH5_IRQHandler, %function
IRQSTEERM7_CH5_IRQHandler:
    ldr   r0,=IRQSTEERM7_CH5_DriverIRQHandler
    bx    r0
    .size IRQSTEERM7_CH5_IRQHandler, . - IRQSTEERM7_CH5_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEERM7_CH6_IRQHandler
    .type IRQSTEERM7_CH6_IRQHandler, %function
IRQSTEERM7_CH6_IRQHandler:
    ldr   r0,=IRQSTEERM7_CH6_DriverIRQHandler
    bx    r0
    .size IRQSTEERM7_CH6_IRQHandler, . - IRQSTEERM7_CH6_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEERM7_CH7_IRQHandler
    .type IRQSTEERM7_CH7_IRQHandler, %function
IRQSTEERM7_CH7_IRQHandler:
    ldr   r0,=IRQSTEERM7_CH7_DriverIRQHandler
    bx    r0
    .size IRQSTEERM7_CH7_IRQHandler, . - IRQSTEERM7_CH7_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEERM7_CH8_IRQHandler
    .type IRQSTEERM7_CH8_IRQHandler, %function
IRQSTEERM7_CH8_IRQHandler:
    ldr   r0,=IRQSTEERM7_CH8_DriverIRQHandler
    bx    r0
    .size IRQSTEERM7_CH8_IRQHandler, . - IRQSTEERM7_CH8_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEERM7_CH9_IRQHandler
    .type IRQSTEERM7_CH9_IRQHandler, %function
IRQSTEERM7_CH9_IRQHandler:
    ldr   r0,=IRQSTEERM7_CH9_DriverIRQHandler
    bx    r0
    .size IRQSTEERM7_CH9_IRQHandler, . - IRQSTEERM7_CH9_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEERM7_CH10_IRQHandler
    .type IRQSTEERM7_CH10_IRQHandler, %function
IRQSTEERM7_CH10_IRQHandler:
    ldr   r0,=IRQSTEERM7_CH10_DriverIRQHandler
    bx    r0
    .size IRQSTEERM7_CH10_IRQHandler, . - IRQSTEERM7_CH10_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEERM7_CH11_IRQHandler
    .type IRQSTEERM7_CH11_IRQHandler, %function
IRQSTEERM7_CH11_IRQHandler:
    ldr   r0,=IRQSTEERM7_CH11_DriverIRQHandler
    bx    r0
    .size IRQSTEERM7_CH11_IRQHandler, . - IRQSTEERM7_CH11_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEERM7_CH12_IRQHandler
    .type IRQSTEERM7_CH12_IRQHandler, %function
IRQSTEERM7_CH12_IRQHandler:
    ldr   r0,=IRQSTEERM7_CH12_DriverIRQHandler
    bx    r0
    .size IRQSTEERM7_CH12_IRQHandler, . - IRQSTEERM7_CH12_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH0_IRQHandler
    .type EDMA2_CH0_IRQHandler, %function
EDMA2_CH0_IRQHandler:
    ldr   r0,=EDMA2_CH0_DriverIRQHandler
    bx    r0
    .size EDMA2_CH0_IRQHandler, . - EDMA2_CH0_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH1_IRQHandler
    .type EDMA2_CH1_IRQHandler, %function
EDMA2_CH1_IRQHandler:
    ldr   r0,=EDMA2_CH1_DriverIRQHandler
    bx    r0
    .size EDMA2_CH1_IRQHandler, . - EDMA2_CH1_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH2_IRQHandler
    .type EDMA2_CH2_IRQHandler, %function
EDMA2_CH2_IRQHandler:
    ldr   r0,=EDMA2_CH2_DriverIRQHandler
    bx    r0
    .size EDMA2_CH2_IRQHandler, . - EDMA2_CH2_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH3_IRQHandler
    .type EDMA2_CH3_IRQHandler, %function
EDMA2_CH3_IRQHandler:
    ldr   r0,=EDMA2_CH3_DriverIRQHandler
    bx    r0
    .size EDMA2_CH3_IRQHandler, . - EDMA2_CH3_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH4_IRQHandler
    .type EDMA2_CH4_IRQHandler, %function
EDMA2_CH4_IRQHandler:
    ldr   r0,=EDMA2_CH4_DriverIRQHandler
    bx    r0
    .size EDMA2_CH4_IRQHandler, . - EDMA2_CH4_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH5_IRQHandler
    .type EDMA2_CH5_IRQHandler, %function
EDMA2_CH5_IRQHandler:
    ldr   r0,=EDMA2_CH5_DriverIRQHandler
    bx    r0
    .size EDMA2_CH5_IRQHandler, . - EDMA2_CH5_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH6_IRQHandler
    .type EDMA2_CH6_IRQHandler, %function
EDMA2_CH6_IRQHandler:
    ldr   r0,=EDMA2_CH6_DriverIRQHandler
    bx    r0
    .size EDMA2_CH6_IRQHandler, . - EDMA2_CH6_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH7_IRQHandler
    .type EDMA2_CH7_IRQHandler, %function
EDMA2_CH7_IRQHandler:
    ldr   r0,=EDMA2_CH7_DriverIRQHandler
    bx    r0
    .size EDMA2_CH7_IRQHandler, . - EDMA2_CH7_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH8_IRQHandler
    .type EDMA2_CH8_IRQHandler, %function
EDMA2_CH8_IRQHandler:
    ldr   r0,=EDMA2_CH8_DriverIRQHandler
    bx    r0
    .size EDMA2_CH8_IRQHandler, . - EDMA2_CH8_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH9_IRQHandler
    .type EDMA2_CH9_IRQHandler, %function
EDMA2_CH9_IRQHandler:
    ldr   r0,=EDMA2_CH9_DriverIRQHandler
    bx    r0
    .size EDMA2_CH9_IRQHandler, . - EDMA2_CH9_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH10_IRQHandler
    .type EDMA2_CH10_IRQHandler, %function
EDMA2_CH10_IRQHandler:
    ldr   r0,=EDMA2_CH10_DriverIRQHandler
    bx    r0
    .size EDMA2_CH10_IRQHandler, . - EDMA2_CH10_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH11_IRQHandler
    .type EDMA2_CH11_IRQHandler, %function
EDMA2_CH11_IRQHandler:
    ldr   r0,=EDMA2_CH11_DriverIRQHandler
    bx    r0
    .size EDMA2_CH11_IRQHandler, . - EDMA2_CH11_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH12_IRQHandler
    .type EDMA2_CH12_IRQHandler, %function
EDMA2_CH12_IRQHandler:
    ldr   r0,=EDMA2_CH12_DriverIRQHandler
    bx    r0
    .size EDMA2_CH12_IRQHandler, . - EDMA2_CH12_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH13_IRQHandler
    .type EDMA2_CH13_IRQHandler, %function
EDMA2_CH13_IRQHandler:
    ldr   r0,=EDMA2_CH13_DriverIRQHandler
    bx    r0
    .size EDMA2_CH13_IRQHandler, . - EDMA2_CH13_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH14_IRQHandler
    .type EDMA2_CH14_IRQHandler, %function
EDMA2_CH14_IRQHandler:
    ldr   r0,=EDMA2_CH14_DriverIRQHandler
    bx    r0
    .size EDMA2_CH14_IRQHandler, . - EDMA2_CH14_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH15_IRQHandler
    .type EDMA2_CH15_IRQHandler, %function
EDMA2_CH15_IRQHandler:
    ldr   r0,=EDMA2_CH15_DriverIRQHandler
    bx    r0
    .size EDMA2_CH15_IRQHandler, . - EDMA2_CH15_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH16_IRQHandler
    .type EDMA2_CH16_IRQHandler, %function
EDMA2_CH16_IRQHandler:
    ldr   r0,=EDMA2_CH16_DriverIRQHandler
    bx    r0
    .size EDMA2_CH16_IRQHandler, . - EDMA2_CH16_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH17_IRQHandler
    .type EDMA2_CH17_IRQHandler, %function
EDMA2_CH17_IRQHandler:
    ldr   r0,=EDMA2_CH17_DriverIRQHandler
    bx    r0
    .size EDMA2_CH17_IRQHandler, . - EDMA2_CH17_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH18_IRQHandler
    .type EDMA2_CH18_IRQHandler, %function
EDMA2_CH18_IRQHandler:
    ldr   r0,=EDMA2_CH18_DriverIRQHandler
    bx    r0
    .size EDMA2_CH18_IRQHandler, . - EDMA2_CH18_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH19_IRQHandler
    .type EDMA2_CH19_IRQHandler, %function
EDMA2_CH19_IRQHandler:
    ldr   r0,=EDMA2_CH19_DriverIRQHandler
    bx    r0
    .size EDMA2_CH19_IRQHandler, . - EDMA2_CH19_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH20_IRQHandler
    .type EDMA2_CH20_IRQHandler, %function
EDMA2_CH20_IRQHandler:
    ldr   r0,=EDMA2_CH20_DriverIRQHandler
    bx    r0
    .size EDMA2_CH20_IRQHandler, . - EDMA2_CH20_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH21_IRQHandler
    .type EDMA2_CH21_IRQHandler, %function
EDMA2_CH21_IRQHandler:
    ldr   r0,=EDMA2_CH21_DriverIRQHandler
    bx    r0
    .size EDMA2_CH21_IRQHandler, . - EDMA2_CH21_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH22_IRQHandler
    .type EDMA2_CH22_IRQHandler, %function
EDMA2_CH22_IRQHandler:
    ldr   r0,=EDMA2_CH22_DriverIRQHandler
    bx    r0
    .size EDMA2_CH22_IRQHandler, . - EDMA2_CH22_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH23_IRQHandler
    .type EDMA2_CH23_IRQHandler, %function
EDMA2_CH23_IRQHandler:
    ldr   r0,=EDMA2_CH23_DriverIRQHandler
    bx    r0
    .size EDMA2_CH23_IRQHandler, . - EDMA2_CH23_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH24_IRQHandler
    .type EDMA2_CH24_IRQHandler, %function
EDMA2_CH24_IRQHandler:
    ldr   r0,=EDMA2_CH24_DriverIRQHandler
    bx    r0
    .size EDMA2_CH24_IRQHandler, . - EDMA2_CH24_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH25_IRQHandler
    .type EDMA2_CH25_IRQHandler, %function
EDMA2_CH25_IRQHandler:
    ldr   r0,=EDMA2_CH25_DriverIRQHandler
    bx    r0
    .size EDMA2_CH25_IRQHandler, . - EDMA2_CH25_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH26_IRQHandler
    .type EDMA2_CH26_IRQHandler, %function
EDMA2_CH26_IRQHandler:
    ldr   r0,=EDMA2_CH26_DriverIRQHandler
    bx    r0
    .size EDMA2_CH26_IRQHandler, . - EDMA2_CH26_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH27_IRQHandler
    .type EDMA2_CH27_IRQHandler, %function
EDMA2_CH27_IRQHandler:
    ldr   r0,=EDMA2_CH27_DriverIRQHandler
    bx    r0
    .size EDMA2_CH27_IRQHandler, . - EDMA2_CH27_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH28_IRQHandler
    .type EDMA2_CH28_IRQHandler, %function
EDMA2_CH28_IRQHandler:
    ldr   r0,=EDMA2_CH28_DriverIRQHandler
    bx    r0
    .size EDMA2_CH28_IRQHandler, . - EDMA2_CH28_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH29_IRQHandler
    .type EDMA2_CH29_IRQHandler, %function
EDMA2_CH29_IRQHandler:
    ldr   r0,=EDMA2_CH29_DriverIRQHandler
    bx    r0
    .size EDMA2_CH29_IRQHandler, . - EDMA2_CH29_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH30_IRQHandler
    .type EDMA2_CH30_IRQHandler, %function
EDMA2_CH30_IRQHandler:
    ldr   r0,=EDMA2_CH30_DriverIRQHandler
    bx    r0
    .size EDMA2_CH30_IRQHandler, . - EDMA2_CH30_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH31_IRQHandler
    .type EDMA2_CH31_IRQHandler, %function
EDMA2_CH31_IRQHandler:
    ldr   r0,=EDMA2_CH31_DriverIRQHandler
    bx    r0
    .size EDMA2_CH31_IRQHandler, . - EDMA2_CH31_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH32_IRQHandler
    .type EDMA2_CH32_IRQHandler, %function
EDMA2_CH32_IRQHandler:
    ldr   r0,=EDMA2_CH32_DriverIRQHandler
    bx    r0
    .size EDMA2_CH32_IRQHandler, . - EDMA2_CH32_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH33_IRQHandler
    .type EDMA2_CH33_IRQHandler, %function
EDMA2_CH33_IRQHandler:
    ldr   r0,=EDMA2_CH33_DriverIRQHandler
    bx    r0
    .size EDMA2_CH33_IRQHandler, . - EDMA2_CH33_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH34_IRQHandler
    .type EDMA2_CH34_IRQHandler, %function
EDMA2_CH34_IRQHandler:
    ldr   r0,=EDMA2_CH34_DriverIRQHandler
    bx    r0
    .size EDMA2_CH34_IRQHandler, . - EDMA2_CH34_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH35_IRQHandler
    .type EDMA2_CH35_IRQHandler, %function
EDMA2_CH35_IRQHandler:
    ldr   r0,=EDMA2_CH35_DriverIRQHandler
    bx    r0
    .size EDMA2_CH35_IRQHandler, . - EDMA2_CH35_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH36_IRQHandler
    .type EDMA2_CH36_IRQHandler, %function
EDMA2_CH36_IRQHandler:
    ldr   r0,=EDMA2_CH36_DriverIRQHandler
    bx    r0
    .size EDMA2_CH36_IRQHandler, . - EDMA2_CH36_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH37_IRQHandler
    .type EDMA2_CH37_IRQHandler, %function
EDMA2_CH37_IRQHandler:
    ldr   r0,=EDMA2_CH37_DriverIRQHandler
    bx    r0
    .size EDMA2_CH37_IRQHandler, . - EDMA2_CH37_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH38_IRQHandler
    .type EDMA2_CH38_IRQHandler, %function
EDMA2_CH38_IRQHandler:
    ldr   r0,=EDMA2_CH38_DriverIRQHandler
    bx    r0
    .size EDMA2_CH38_IRQHandler, . - EDMA2_CH38_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH39_IRQHandler
    .type EDMA2_CH39_IRQHandler, %function
EDMA2_CH39_IRQHandler:
    ldr   r0,=EDMA2_CH39_DriverIRQHandler
    bx    r0
    .size EDMA2_CH39_IRQHandler, . - EDMA2_CH39_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH40_IRQHandler
    .type EDMA2_CH40_IRQHandler, %function
EDMA2_CH40_IRQHandler:
    ldr   r0,=EDMA2_CH40_DriverIRQHandler
    bx    r0
    .size EDMA2_CH40_IRQHandler, . - EDMA2_CH40_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH41_IRQHandler
    .type EDMA2_CH41_IRQHandler, %function
EDMA2_CH41_IRQHandler:
    ldr   r0,=EDMA2_CH41_DriverIRQHandler
    bx    r0
    .size EDMA2_CH41_IRQHandler, . - EDMA2_CH41_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH42_IRQHandler
    .type EDMA2_CH42_IRQHandler, %function
EDMA2_CH42_IRQHandler:
    ldr   r0,=EDMA2_CH42_DriverIRQHandler
    bx    r0
    .size EDMA2_CH42_IRQHandler, . - EDMA2_CH42_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH43_IRQHandler
    .type EDMA2_CH43_IRQHandler, %function
EDMA2_CH43_IRQHandler:
    ldr   r0,=EDMA2_CH43_DriverIRQHandler
    bx    r0
    .size EDMA2_CH43_IRQHandler, . - EDMA2_CH43_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH44_IRQHandler
    .type EDMA2_CH44_IRQHandler, %function
EDMA2_CH44_IRQHandler:
    ldr   r0,=EDMA2_CH44_DriverIRQHandler
    bx    r0
    .size EDMA2_CH44_IRQHandler, . - EDMA2_CH44_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH45_IRQHandler
    .type EDMA2_CH45_IRQHandler, %function
EDMA2_CH45_IRQHandler:
    ldr   r0,=EDMA2_CH45_DriverIRQHandler
    bx    r0
    .size EDMA2_CH45_IRQHandler, . - EDMA2_CH45_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH46_IRQHandler
    .type EDMA2_CH46_IRQHandler, %function
EDMA2_CH46_IRQHandler:
    ldr   r0,=EDMA2_CH46_DriverIRQHandler
    bx    r0
    .size EDMA2_CH46_IRQHandler, . - EDMA2_CH46_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH47_IRQHandler
    .type EDMA2_CH47_IRQHandler, %function
EDMA2_CH47_IRQHandler:
    ldr   r0,=EDMA2_CH47_DriverIRQHandler
    bx    r0
    .size EDMA2_CH47_IRQHandler, . - EDMA2_CH47_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH48_IRQHandler
    .type EDMA2_CH48_IRQHandler, %function
EDMA2_CH48_IRQHandler:
    ldr   r0,=EDMA2_CH48_DriverIRQHandler
    bx    r0
    .size EDMA2_CH48_IRQHandler, . - EDMA2_CH48_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH49_IRQHandler
    .type EDMA2_CH49_IRQHandler, %function
EDMA2_CH49_IRQHandler:
    ldr   r0,=EDMA2_CH49_DriverIRQHandler
    bx    r0
    .size EDMA2_CH49_IRQHandler, . - EDMA2_CH49_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH50_IRQHandler
    .type EDMA2_CH50_IRQHandler, %function
EDMA2_CH50_IRQHandler:
    ldr   r0,=EDMA2_CH50_DriverIRQHandler
    bx    r0
    .size EDMA2_CH50_IRQHandler, . - EDMA2_CH50_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH51_IRQHandler
    .type EDMA2_CH51_IRQHandler, %function
EDMA2_CH51_IRQHandler:
    ldr   r0,=EDMA2_CH51_DriverIRQHandler
    bx    r0
    .size EDMA2_CH51_IRQHandler, . - EDMA2_CH51_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH52_IRQHandler
    .type EDMA2_CH52_IRQHandler, %function
EDMA2_CH52_IRQHandler:
    ldr   r0,=EDMA2_CH52_DriverIRQHandler
    bx    r0
    .size EDMA2_CH52_IRQHandler, . - EDMA2_CH52_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH53_IRQHandler
    .type EDMA2_CH53_IRQHandler, %function
EDMA2_CH53_IRQHandler:
    ldr   r0,=EDMA2_CH53_DriverIRQHandler
    bx    r0
    .size EDMA2_CH53_IRQHandler, . - EDMA2_CH53_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH54_IRQHandler
    .type EDMA2_CH54_IRQHandler, %function
EDMA2_CH54_IRQHandler:
    ldr   r0,=EDMA2_CH54_DriverIRQHandler
    bx    r0
    .size EDMA2_CH54_IRQHandler, . - EDMA2_CH54_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH55_IRQHandler
    .type EDMA2_CH55_IRQHandler, %function
EDMA2_CH55_IRQHandler:
    ldr   r0,=EDMA2_CH55_DriverIRQHandler
    bx    r0
    .size EDMA2_CH55_IRQHandler, . - EDMA2_CH55_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH56_IRQHandler
    .type EDMA2_CH56_IRQHandler, %function
EDMA2_CH56_IRQHandler:
    ldr   r0,=EDMA2_CH56_DriverIRQHandler
    bx    r0
    .size EDMA2_CH56_IRQHandler, . - EDMA2_CH56_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH57_IRQHandler
    .type EDMA2_CH57_IRQHandler, %function
EDMA2_CH57_IRQHandler:
    ldr   r0,=EDMA2_CH57_DriverIRQHandler
    bx    r0
    .size EDMA2_CH57_IRQHandler, . - EDMA2_CH57_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH58_IRQHandler
    .type EDMA2_CH58_IRQHandler, %function
EDMA2_CH58_IRQHandler:
    ldr   r0,=EDMA2_CH58_DriverIRQHandler
    bx    r0
    .size EDMA2_CH58_IRQHandler, . - EDMA2_CH58_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH59_IRQHandler
    .type EDMA2_CH59_IRQHandler, %function
EDMA2_CH59_IRQHandler:
    ldr   r0,=EDMA2_CH59_DriverIRQHandler
    bx    r0
    .size EDMA2_CH59_IRQHandler, . - EDMA2_CH59_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH60_IRQHandler
    .type EDMA2_CH60_IRQHandler, %function
EDMA2_CH60_IRQHandler:
    ldr   r0,=EDMA2_CH60_DriverIRQHandler
    bx    r0
    .size EDMA2_CH60_IRQHandler, . - EDMA2_CH60_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH61_IRQHandler
    .type EDMA2_CH61_IRQHandler, %function
EDMA2_CH61_IRQHandler:
    ldr   r0,=EDMA2_CH61_DriverIRQHandler
    bx    r0
    .size EDMA2_CH61_IRQHandler, . - EDMA2_CH61_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH62_IRQHandler
    .type EDMA2_CH62_IRQHandler, %function
EDMA2_CH62_IRQHandler:
    ldr   r0,=EDMA2_CH62_DriverIRQHandler
    bx    r0
    .size EDMA2_CH62_IRQHandler, . - EDMA2_CH62_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA2_CH63_IRQHandler
    .type EDMA2_CH63_IRQHandler, %function
EDMA2_CH63_IRQHandler:
    ldr   r0,=EDMA2_CH63_DriverIRQHandler
    bx    r0
    .size EDMA2_CH63_IRQHandler, . - EDMA2_CH63_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH0_IRQHandler
    .type EDMA4_CH0_IRQHandler, %function
EDMA4_CH0_IRQHandler:
    ldr   r0,=EDMA4_CH0_DriverIRQHandler
    bx    r0
    .size EDMA4_CH0_IRQHandler, . - EDMA4_CH0_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH1_IRQHandler
    .type EDMA4_CH1_IRQHandler, %function
EDMA4_CH1_IRQHandler:
    ldr   r0,=EDMA4_CH1_DriverIRQHandler
    bx    r0
    .size EDMA4_CH1_IRQHandler, . - EDMA4_CH1_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH2_IRQHandler
    .type EDMA4_CH2_IRQHandler, %function
EDMA4_CH2_IRQHandler:
    ldr   r0,=EDMA4_CH2_DriverIRQHandler
    bx    r0
    .size EDMA4_CH2_IRQHandler, . - EDMA4_CH2_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH3_IRQHandler
    .type EDMA4_CH3_IRQHandler, %function
EDMA4_CH3_IRQHandler:
    ldr   r0,=EDMA4_CH3_DriverIRQHandler
    bx    r0
    .size EDMA4_CH3_IRQHandler, . - EDMA4_CH3_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH4_IRQHandler
    .type EDMA4_CH4_IRQHandler, %function
EDMA4_CH4_IRQHandler:
    ldr   r0,=EDMA4_CH4_DriverIRQHandler
    bx    r0
    .size EDMA4_CH4_IRQHandler, . - EDMA4_CH4_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH5_IRQHandler
    .type EDMA4_CH5_IRQHandler, %function
EDMA4_CH5_IRQHandler:
    ldr   r0,=EDMA4_CH5_DriverIRQHandler
    bx    r0
    .size EDMA4_CH5_IRQHandler, . - EDMA4_CH5_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH6_IRQHandler
    .type EDMA4_CH6_IRQHandler, %function
EDMA4_CH6_IRQHandler:
    ldr   r0,=EDMA4_CH6_DriverIRQHandler
    bx    r0
    .size EDMA4_CH6_IRQHandler, . - EDMA4_CH6_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH7_IRQHandler
    .type EDMA4_CH7_IRQHandler, %function
EDMA4_CH7_IRQHandler:
    ldr   r0,=EDMA4_CH7_DriverIRQHandler
    bx    r0
    .size EDMA4_CH7_IRQHandler, . - EDMA4_CH7_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH8_IRQHandler
    .type EDMA4_CH8_IRQHandler, %function
EDMA4_CH8_IRQHandler:
    ldr   r0,=EDMA4_CH8_DriverIRQHandler
    bx    r0
    .size EDMA4_CH8_IRQHandler, . - EDMA4_CH8_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH9_IRQHandler
    .type EDMA4_CH9_IRQHandler, %function
EDMA4_CH9_IRQHandler:
    ldr   r0,=EDMA4_CH9_DriverIRQHandler
    bx    r0
    .size EDMA4_CH9_IRQHandler, . - EDMA4_CH9_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH10_IRQHandler
    .type EDMA4_CH10_IRQHandler, %function
EDMA4_CH10_IRQHandler:
    ldr   r0,=EDMA4_CH10_DriverIRQHandler
    bx    r0
    .size EDMA4_CH10_IRQHandler, . - EDMA4_CH10_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH11_IRQHandler
    .type EDMA4_CH11_IRQHandler, %function
EDMA4_CH11_IRQHandler:
    ldr   r0,=EDMA4_CH11_DriverIRQHandler
    bx    r0
    .size EDMA4_CH11_IRQHandler, . - EDMA4_CH11_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH12_IRQHandler
    .type EDMA4_CH12_IRQHandler, %function
EDMA4_CH12_IRQHandler:
    ldr   r0,=EDMA4_CH12_DriverIRQHandler
    bx    r0
    .size EDMA4_CH12_IRQHandler, . - EDMA4_CH12_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH13_IRQHandler
    .type EDMA4_CH13_IRQHandler, %function
EDMA4_CH13_IRQHandler:
    ldr   r0,=EDMA4_CH13_DriverIRQHandler
    bx    r0
    .size EDMA4_CH13_IRQHandler, . - EDMA4_CH13_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH14_IRQHandler
    .type EDMA4_CH14_IRQHandler, %function
EDMA4_CH14_IRQHandler:
    ldr   r0,=EDMA4_CH14_DriverIRQHandler
    bx    r0
    .size EDMA4_CH14_IRQHandler, . - EDMA4_CH14_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH15_IRQHandler
    .type EDMA4_CH15_IRQHandler, %function
EDMA4_CH15_IRQHandler:
    ldr   r0,=EDMA4_CH15_DriverIRQHandler
    bx    r0
    .size EDMA4_CH15_IRQHandler, . - EDMA4_CH15_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH16_IRQHandler
    .type EDMA4_CH16_IRQHandler, %function
EDMA4_CH16_IRQHandler:
    ldr   r0,=EDMA4_CH16_DriverIRQHandler
    bx    r0
    .size EDMA4_CH16_IRQHandler, . - EDMA4_CH16_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH17_IRQHandler
    .type EDMA4_CH17_IRQHandler, %function
EDMA4_CH17_IRQHandler:
    ldr   r0,=EDMA4_CH17_DriverIRQHandler
    bx    r0
    .size EDMA4_CH17_IRQHandler, . - EDMA4_CH17_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH18_IRQHandler
    .type EDMA4_CH18_IRQHandler, %function
EDMA4_CH18_IRQHandler:
    ldr   r0,=EDMA4_CH18_DriverIRQHandler
    bx    r0
    .size EDMA4_CH18_IRQHandler, . - EDMA4_CH18_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH19_IRQHandler
    .type EDMA4_CH19_IRQHandler, %function
EDMA4_CH19_IRQHandler:
    ldr   r0,=EDMA4_CH19_DriverIRQHandler
    bx    r0
    .size EDMA4_CH19_IRQHandler, . - EDMA4_CH19_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH20_IRQHandler
    .type EDMA4_CH20_IRQHandler, %function
EDMA4_CH20_IRQHandler:
    ldr   r0,=EDMA4_CH20_DriverIRQHandler
    bx    r0
    .size EDMA4_CH20_IRQHandler, . - EDMA4_CH20_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH21_IRQHandler
    .type EDMA4_CH21_IRQHandler, %function
EDMA4_CH21_IRQHandler:
    ldr   r0,=EDMA4_CH21_DriverIRQHandler
    bx    r0
    .size EDMA4_CH21_IRQHandler, . - EDMA4_CH21_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH22_IRQHandler
    .type EDMA4_CH22_IRQHandler, %function
EDMA4_CH22_IRQHandler:
    ldr   r0,=EDMA4_CH22_DriverIRQHandler
    bx    r0
    .size EDMA4_CH22_IRQHandler, . - EDMA4_CH22_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH23_IRQHandler
    .type EDMA4_CH23_IRQHandler, %function
EDMA4_CH23_IRQHandler:
    ldr   r0,=EDMA4_CH23_DriverIRQHandler
    bx    r0
    .size EDMA4_CH23_IRQHandler, . - EDMA4_CH23_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH24_IRQHandler
    .type EDMA4_CH24_IRQHandler, %function
EDMA4_CH24_IRQHandler:
    ldr   r0,=EDMA4_CH24_DriverIRQHandler
    bx    r0
    .size EDMA4_CH24_IRQHandler, . - EDMA4_CH24_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH25_IRQHandler
    .type EDMA4_CH25_IRQHandler, %function
EDMA4_CH25_IRQHandler:
    ldr   r0,=EDMA4_CH25_DriverIRQHandler
    bx    r0
    .size EDMA4_CH25_IRQHandler, . - EDMA4_CH25_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH26_IRQHandler
    .type EDMA4_CH26_IRQHandler, %function
EDMA4_CH26_IRQHandler:
    ldr   r0,=EDMA4_CH26_DriverIRQHandler
    bx    r0
    .size EDMA4_CH26_IRQHandler, . - EDMA4_CH26_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH27_IRQHandler
    .type EDMA4_CH27_IRQHandler, %function
EDMA4_CH27_IRQHandler:
    ldr   r0,=EDMA4_CH27_DriverIRQHandler
    bx    r0
    .size EDMA4_CH27_IRQHandler, . - EDMA4_CH27_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH28_IRQHandler
    .type EDMA4_CH28_IRQHandler, %function
EDMA4_CH28_IRQHandler:
    ldr   r0,=EDMA4_CH28_DriverIRQHandler
    bx    r0
    .size EDMA4_CH28_IRQHandler, . - EDMA4_CH28_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH29_IRQHandler
    .type EDMA4_CH29_IRQHandler, %function
EDMA4_CH29_IRQHandler:
    ldr   r0,=EDMA4_CH29_DriverIRQHandler
    bx    r0
    .size EDMA4_CH29_IRQHandler, . - EDMA4_CH29_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH30_IRQHandler
    .type EDMA4_CH30_IRQHandler, %function
EDMA4_CH30_IRQHandler:
    ldr   r0,=EDMA4_CH30_DriverIRQHandler
    bx    r0
    .size EDMA4_CH30_IRQHandler, . - EDMA4_CH30_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH31_IRQHandler
    .type EDMA4_CH31_IRQHandler, %function
EDMA4_CH31_IRQHandler:
    ldr   r0,=EDMA4_CH31_DriverIRQHandler
    bx    r0
    .size EDMA4_CH31_IRQHandler, . - EDMA4_CH31_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH32_IRQHandler
    .type EDMA4_CH32_IRQHandler, %function
EDMA4_CH32_IRQHandler:
    ldr   r0,=EDMA4_CH32_DriverIRQHandler
    bx    r0
    .size EDMA4_CH32_IRQHandler, . - EDMA4_CH32_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH33_IRQHandler
    .type EDMA4_CH33_IRQHandler, %function
EDMA4_CH33_IRQHandler:
    ldr   r0,=EDMA4_CH33_DriverIRQHandler
    bx    r0
    .size EDMA4_CH33_IRQHandler, . - EDMA4_CH33_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH34_IRQHandler
    .type EDMA4_CH34_IRQHandler, %function
EDMA4_CH34_IRQHandler:
    ldr   r0,=EDMA4_CH34_DriverIRQHandler
    bx    r0
    .size EDMA4_CH34_IRQHandler, . - EDMA4_CH34_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH35_IRQHandler
    .type EDMA4_CH35_IRQHandler, %function
EDMA4_CH35_IRQHandler:
    ldr   r0,=EDMA4_CH35_DriverIRQHandler
    bx    r0
    .size EDMA4_CH35_IRQHandler, . - EDMA4_CH35_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH36_IRQHandler
    .type EDMA4_CH36_IRQHandler, %function
EDMA4_CH36_IRQHandler:
    ldr   r0,=EDMA4_CH36_DriverIRQHandler
    bx    r0
    .size EDMA4_CH36_IRQHandler, . - EDMA4_CH36_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH37_IRQHandler
    .type EDMA4_CH37_IRQHandler, %function
EDMA4_CH37_IRQHandler:
    ldr   r0,=EDMA4_CH37_DriverIRQHandler
    bx    r0
    .size EDMA4_CH37_IRQHandler, . - EDMA4_CH37_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH38_IRQHandler
    .type EDMA4_CH38_IRQHandler, %function
EDMA4_CH38_IRQHandler:
    ldr   r0,=EDMA4_CH38_DriverIRQHandler
    bx    r0
    .size EDMA4_CH38_IRQHandler, . - EDMA4_CH38_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH39_IRQHandler
    .type EDMA4_CH39_IRQHandler, %function
EDMA4_CH39_IRQHandler:
    ldr   r0,=EDMA4_CH39_DriverIRQHandler
    bx    r0
    .size EDMA4_CH39_IRQHandler, . - EDMA4_CH39_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH40_IRQHandler
    .type EDMA4_CH40_IRQHandler, %function
EDMA4_CH40_IRQHandler:
    ldr   r0,=EDMA4_CH40_DriverIRQHandler
    bx    r0
    .size EDMA4_CH40_IRQHandler, . - EDMA4_CH40_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH41_IRQHandler
    .type EDMA4_CH41_IRQHandler, %function
EDMA4_CH41_IRQHandler:
    ldr   r0,=EDMA4_CH41_DriverIRQHandler
    bx    r0
    .size EDMA4_CH41_IRQHandler, . - EDMA4_CH41_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH42_IRQHandler
    .type EDMA4_CH42_IRQHandler, %function
EDMA4_CH42_IRQHandler:
    ldr   r0,=EDMA4_CH42_DriverIRQHandler
    bx    r0
    .size EDMA4_CH42_IRQHandler, . - EDMA4_CH42_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH43_IRQHandler
    .type EDMA4_CH43_IRQHandler, %function
EDMA4_CH43_IRQHandler:
    ldr   r0,=EDMA4_CH43_DriverIRQHandler
    bx    r0
    .size EDMA4_CH43_IRQHandler, . - EDMA4_CH43_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH44_IRQHandler
    .type EDMA4_CH44_IRQHandler, %function
EDMA4_CH44_IRQHandler:
    ldr   r0,=EDMA4_CH44_DriverIRQHandler
    bx    r0
    .size EDMA4_CH44_IRQHandler, . - EDMA4_CH44_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH45_IRQHandler
    .type EDMA4_CH45_IRQHandler, %function
EDMA4_CH45_IRQHandler:
    ldr   r0,=EDMA4_CH45_DriverIRQHandler
    bx    r0
    .size EDMA4_CH45_IRQHandler, . - EDMA4_CH45_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH46_IRQHandler
    .type EDMA4_CH46_IRQHandler, %function
EDMA4_CH46_IRQHandler:
    ldr   r0,=EDMA4_CH46_DriverIRQHandler
    bx    r0
    .size EDMA4_CH46_IRQHandler, . - EDMA4_CH46_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH47_IRQHandler
    .type EDMA4_CH47_IRQHandler, %function
EDMA4_CH47_IRQHandler:
    ldr   r0,=EDMA4_CH47_DriverIRQHandler
    bx    r0
    .size EDMA4_CH47_IRQHandler, . - EDMA4_CH47_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH48_IRQHandler
    .type EDMA4_CH48_IRQHandler, %function
EDMA4_CH48_IRQHandler:
    ldr   r0,=EDMA4_CH48_DriverIRQHandler
    bx    r0
    .size EDMA4_CH48_IRQHandler, . - EDMA4_CH48_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH49_IRQHandler
    .type EDMA4_CH49_IRQHandler, %function
EDMA4_CH49_IRQHandler:
    ldr   r0,=EDMA4_CH49_DriverIRQHandler
    bx    r0
    .size EDMA4_CH49_IRQHandler, . - EDMA4_CH49_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH50_IRQHandler
    .type EDMA4_CH50_IRQHandler, %function
EDMA4_CH50_IRQHandler:
    ldr   r0,=EDMA4_CH50_DriverIRQHandler
    bx    r0
    .size EDMA4_CH50_IRQHandler, . - EDMA4_CH50_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH51_IRQHandler
    .type EDMA4_CH51_IRQHandler, %function
EDMA4_CH51_IRQHandler:
    ldr   r0,=EDMA4_CH51_DriverIRQHandler
    bx    r0
    .size EDMA4_CH51_IRQHandler, . - EDMA4_CH51_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH52_IRQHandler
    .type EDMA4_CH52_IRQHandler, %function
EDMA4_CH52_IRQHandler:
    ldr   r0,=EDMA4_CH52_DriverIRQHandler
    bx    r0
    .size EDMA4_CH52_IRQHandler, . - EDMA4_CH52_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH53_IRQHandler
    .type EDMA4_CH53_IRQHandler, %function
EDMA4_CH53_IRQHandler:
    ldr   r0,=EDMA4_CH53_DriverIRQHandler
    bx    r0
    .size EDMA4_CH53_IRQHandler, . - EDMA4_CH53_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH54_IRQHandler
    .type EDMA4_CH54_IRQHandler, %function
EDMA4_CH54_IRQHandler:
    ldr   r0,=EDMA4_CH54_DriverIRQHandler
    bx    r0
    .size EDMA4_CH54_IRQHandler, . - EDMA4_CH54_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH55_IRQHandler
    .type EDMA4_CH55_IRQHandler, %function
EDMA4_CH55_IRQHandler:
    ldr   r0,=EDMA4_CH55_DriverIRQHandler
    bx    r0
    .size EDMA4_CH55_IRQHandler, . - EDMA4_CH55_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH56_IRQHandler
    .type EDMA4_CH56_IRQHandler, %function
EDMA4_CH56_IRQHandler:
    ldr   r0,=EDMA4_CH56_DriverIRQHandler
    bx    r0
    .size EDMA4_CH56_IRQHandler, . - EDMA4_CH56_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH57_IRQHandler
    .type EDMA4_CH57_IRQHandler, %function
EDMA4_CH57_IRQHandler:
    ldr   r0,=EDMA4_CH57_DriverIRQHandler
    bx    r0
    .size EDMA4_CH57_IRQHandler, . - EDMA4_CH57_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH58_IRQHandler
    .type EDMA4_CH58_IRQHandler, %function
EDMA4_CH58_IRQHandler:
    ldr   r0,=EDMA4_CH58_DriverIRQHandler
    bx    r0
    .size EDMA4_CH58_IRQHandler, . - EDMA4_CH58_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH59_IRQHandler
    .type EDMA4_CH59_IRQHandler, %function
EDMA4_CH59_IRQHandler:
    ldr   r0,=EDMA4_CH59_DriverIRQHandler
    bx    r0
    .size EDMA4_CH59_IRQHandler, . - EDMA4_CH59_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH60_IRQHandler
    .type EDMA4_CH60_IRQHandler, %function
EDMA4_CH60_IRQHandler:
    ldr   r0,=EDMA4_CH60_DriverIRQHandler
    bx    r0
    .size EDMA4_CH60_IRQHandler, . - EDMA4_CH60_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH61_IRQHandler
    .type EDMA4_CH61_IRQHandler, %function
EDMA4_CH61_IRQHandler:
    ldr   r0,=EDMA4_CH61_DriverIRQHandler
    bx    r0
    .size EDMA4_CH61_IRQHandler, . - EDMA4_CH61_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH62_IRQHandler
    .type EDMA4_CH62_IRQHandler, %function
EDMA4_CH62_IRQHandler:
    ldr   r0,=EDMA4_CH62_DriverIRQHandler
    bx    r0
    .size EDMA4_CH62_IRQHandler, . - EDMA4_CH62_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA4_CH63_IRQHandler
    .type EDMA4_CH63_IRQHandler, %function
EDMA4_CH63_IRQHandler:
    ldr   r0,=EDMA4_CH63_DriverIRQHandler
    bx    r0
    .size EDMA4_CH63_IRQHandler, . - EDMA4_CH63_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH0_IRQHandler
    .type EDMA3_CH0_IRQHandler, %function
EDMA3_CH0_IRQHandler:
    ldr   r0,=EDMA3_CH0_DriverIRQHandler
    bx    r0
    .size EDMA3_CH0_IRQHandler, . - EDMA3_CH0_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH1_IRQHandler
    .type EDMA3_CH1_IRQHandler, %function
EDMA3_CH1_IRQHandler:
    ldr   r0,=EDMA3_CH1_DriverIRQHandler
    bx    r0
    .size EDMA3_CH1_IRQHandler, . - EDMA3_CH1_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH2_IRQHandler
    .type EDMA3_CH2_IRQHandler, %function
EDMA3_CH2_IRQHandler:
    ldr   r0,=EDMA3_CH2_DriverIRQHandler
    bx    r0
    .size EDMA3_CH2_IRQHandler, . - EDMA3_CH2_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH3_IRQHandler
    .type EDMA3_CH3_IRQHandler, %function
EDMA3_CH3_IRQHandler:
    ldr   r0,=EDMA3_CH3_DriverIRQHandler
    bx    r0
    .size EDMA3_CH3_IRQHandler, . - EDMA3_CH3_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH4_IRQHandler
    .type EDMA3_CH4_IRQHandler, %function
EDMA3_CH4_IRQHandler:
    ldr   r0,=EDMA3_CH4_DriverIRQHandler
    bx    r0
    .size EDMA3_CH4_IRQHandler, . - EDMA3_CH4_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH5_IRQHandler
    .type EDMA3_CH5_IRQHandler, %function
EDMA3_CH5_IRQHandler:
    ldr   r0,=EDMA3_CH5_DriverIRQHandler
    bx    r0
    .size EDMA3_CH5_IRQHandler, . - EDMA3_CH5_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH6_IRQHandler
    .type EDMA3_CH6_IRQHandler, %function
EDMA3_CH6_IRQHandler:
    ldr   r0,=EDMA3_CH6_DriverIRQHandler
    bx    r0
    .size EDMA3_CH6_IRQHandler, . - EDMA3_CH6_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH7_IRQHandler
    .type EDMA3_CH7_IRQHandler, %function
EDMA3_CH7_IRQHandler:
    ldr   r0,=EDMA3_CH7_DriverIRQHandler
    bx    r0
    .size EDMA3_CH7_IRQHandler, . - EDMA3_CH7_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH8_IRQHandler
    .type EDMA3_CH8_IRQHandler, %function
EDMA3_CH8_IRQHandler:
    ldr   r0,=EDMA3_CH8_DriverIRQHandler
    bx    r0
    .size EDMA3_CH8_IRQHandler, . - EDMA3_CH8_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH9_IRQHandler
    .type EDMA3_CH9_IRQHandler, %function
EDMA3_CH9_IRQHandler:
    ldr   r0,=EDMA3_CH9_DriverIRQHandler
    bx    r0
    .size EDMA3_CH9_IRQHandler, . - EDMA3_CH9_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH10_IRQHandler
    .type EDMA3_CH10_IRQHandler, %function
EDMA3_CH10_IRQHandler:
    ldr   r0,=EDMA3_CH10_DriverIRQHandler
    bx    r0
    .size EDMA3_CH10_IRQHandler, . - EDMA3_CH10_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH11_IRQHandler
    .type EDMA3_CH11_IRQHandler, %function
EDMA3_CH11_IRQHandler:
    ldr   r0,=EDMA3_CH11_DriverIRQHandler
    bx    r0
    .size EDMA3_CH11_IRQHandler, . - EDMA3_CH11_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH12_IRQHandler
    .type EDMA3_CH12_IRQHandler, %function
EDMA3_CH12_IRQHandler:
    ldr   r0,=EDMA3_CH12_DriverIRQHandler
    bx    r0
    .size EDMA3_CH12_IRQHandler, . - EDMA3_CH12_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH13_IRQHandler
    .type EDMA3_CH13_IRQHandler, %function
EDMA3_CH13_IRQHandler:
    ldr   r0,=EDMA3_CH13_DriverIRQHandler
    bx    r0
    .size EDMA3_CH13_IRQHandler, . - EDMA3_CH13_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH14_IRQHandler
    .type EDMA3_CH14_IRQHandler, %function
EDMA3_CH14_IRQHandler:
    ldr   r0,=EDMA3_CH14_DriverIRQHandler
    bx    r0
    .size EDMA3_CH14_IRQHandler, . - EDMA3_CH14_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH15_IRQHandler
    .type EDMA3_CH15_IRQHandler, %function
EDMA3_CH15_IRQHandler:
    ldr   r0,=EDMA3_CH15_DriverIRQHandler
    bx    r0
    .size EDMA3_CH15_IRQHandler, . - EDMA3_CH15_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH16_IRQHandler
    .type EDMA3_CH16_IRQHandler, %function
EDMA3_CH16_IRQHandler:
    ldr   r0,=EDMA3_CH16_DriverIRQHandler
    bx    r0
    .size EDMA3_CH16_IRQHandler, . - EDMA3_CH16_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH17_IRQHandler
    .type EDMA3_CH17_IRQHandler, %function
EDMA3_CH17_IRQHandler:
    ldr   r0,=EDMA3_CH17_DriverIRQHandler
    bx    r0
    .size EDMA3_CH17_IRQHandler, . - EDMA3_CH17_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH18_IRQHandler
    .type EDMA3_CH18_IRQHandler, %function
EDMA3_CH18_IRQHandler:
    ldr   r0,=EDMA3_CH18_DriverIRQHandler
    bx    r0
    .size EDMA3_CH18_IRQHandler, . - EDMA3_CH18_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH19_IRQHandler
    .type EDMA3_CH19_IRQHandler, %function
EDMA3_CH19_IRQHandler:
    ldr   r0,=EDMA3_CH19_DriverIRQHandler
    bx    r0
    .size EDMA3_CH19_IRQHandler, . - EDMA3_CH19_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH20_IRQHandler
    .type EDMA3_CH20_IRQHandler, %function
EDMA3_CH20_IRQHandler:
    ldr   r0,=EDMA3_CH20_DriverIRQHandler
    bx    r0
    .size EDMA3_CH20_IRQHandler, . - EDMA3_CH20_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH21_IRQHandler
    .type EDMA3_CH21_IRQHandler, %function
EDMA3_CH21_IRQHandler:
    ldr   r0,=EDMA3_CH21_DriverIRQHandler
    bx    r0
    .size EDMA3_CH21_IRQHandler, . - EDMA3_CH21_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH22_IRQHandler
    .type EDMA3_CH22_IRQHandler, %function
EDMA3_CH22_IRQHandler:
    ldr   r0,=EDMA3_CH22_DriverIRQHandler
    bx    r0
    .size EDMA3_CH22_IRQHandler, . - EDMA3_CH22_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH23_IRQHandler
    .type EDMA3_CH23_IRQHandler, %function
EDMA3_CH23_IRQHandler:
    ldr   r0,=EDMA3_CH23_DriverIRQHandler
    bx    r0
    .size EDMA3_CH23_IRQHandler, . - EDMA3_CH23_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH24_IRQHandler
    .type EDMA3_CH24_IRQHandler, %function
EDMA3_CH24_IRQHandler:
    ldr   r0,=EDMA3_CH24_DriverIRQHandler
    bx    r0
    .size EDMA3_CH24_IRQHandler, . - EDMA3_CH24_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH25_IRQHandler
    .type EDMA3_CH25_IRQHandler, %function
EDMA3_CH25_IRQHandler:
    ldr   r0,=EDMA3_CH25_DriverIRQHandler
    bx    r0
    .size EDMA3_CH25_IRQHandler, . - EDMA3_CH25_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH26_IRQHandler
    .type EDMA3_CH26_IRQHandler, %function
EDMA3_CH26_IRQHandler:
    ldr   r0,=EDMA3_CH26_DriverIRQHandler
    bx    r0
    .size EDMA3_CH26_IRQHandler, . - EDMA3_CH26_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH27_IRQHandler
    .type EDMA3_CH27_IRQHandler, %function
EDMA3_CH27_IRQHandler:
    ldr   r0,=EDMA3_CH27_DriverIRQHandler
    bx    r0
    .size EDMA3_CH27_IRQHandler, . - EDMA3_CH27_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH28_IRQHandler
    .type EDMA3_CH28_IRQHandler, %function
EDMA3_CH28_IRQHandler:
    ldr   r0,=EDMA3_CH28_DriverIRQHandler
    bx    r0
    .size EDMA3_CH28_IRQHandler, . - EDMA3_CH28_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH29_IRQHandler
    .type EDMA3_CH29_IRQHandler, %function
EDMA3_CH29_IRQHandler:
    ldr   r0,=EDMA3_CH29_DriverIRQHandler
    bx    r0
    .size EDMA3_CH29_IRQHandler, . - EDMA3_CH29_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH30_IRQHandler
    .type EDMA3_CH30_IRQHandler, %function
EDMA3_CH30_IRQHandler:
    ldr   r0,=EDMA3_CH30_DriverIRQHandler
    bx    r0
    .size EDMA3_CH30_IRQHandler, . - EDMA3_CH30_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH31_IRQHandler
    .type EDMA3_CH31_IRQHandler, %function
EDMA3_CH31_IRQHandler:
    ldr   r0,=EDMA3_CH31_DriverIRQHandler
    bx    r0
    .size EDMA3_CH31_IRQHandler, . - EDMA3_CH31_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH32_IRQHandler
    .type EDMA3_CH32_IRQHandler, %function
EDMA3_CH32_IRQHandler:
    ldr   r0,=EDMA3_CH32_DriverIRQHandler
    bx    r0
    .size EDMA3_CH32_IRQHandler, . - EDMA3_CH32_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH33_IRQHandler
    .type EDMA3_CH33_IRQHandler, %function
EDMA3_CH33_IRQHandler:
    ldr   r0,=EDMA3_CH33_DriverIRQHandler
    bx    r0
    .size EDMA3_CH33_IRQHandler, . - EDMA3_CH33_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH34_IRQHandler
    .type EDMA3_CH34_IRQHandler, %function
EDMA3_CH34_IRQHandler:
    ldr   r0,=EDMA3_CH34_DriverIRQHandler
    bx    r0
    .size EDMA3_CH34_IRQHandler, . - EDMA3_CH34_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH35_IRQHandler
    .type EDMA3_CH35_IRQHandler, %function
EDMA3_CH35_IRQHandler:
    ldr   r0,=EDMA3_CH35_DriverIRQHandler
    bx    r0
    .size EDMA3_CH35_IRQHandler, . - EDMA3_CH35_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH36_IRQHandler
    .type EDMA3_CH36_IRQHandler, %function
EDMA3_CH36_IRQHandler:
    ldr   r0,=EDMA3_CH36_DriverIRQHandler
    bx    r0
    .size EDMA3_CH36_IRQHandler, . - EDMA3_CH36_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH37_IRQHandler
    .type EDMA3_CH37_IRQHandler, %function
EDMA3_CH37_IRQHandler:
    ldr   r0,=EDMA3_CH37_DriverIRQHandler
    bx    r0
    .size EDMA3_CH37_IRQHandler, . - EDMA3_CH37_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH38_IRQHandler
    .type EDMA3_CH38_IRQHandler, %function
EDMA3_CH38_IRQHandler:
    ldr   r0,=EDMA3_CH38_DriverIRQHandler
    bx    r0
    .size EDMA3_CH38_IRQHandler, . - EDMA3_CH38_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH39_IRQHandler
    .type EDMA3_CH39_IRQHandler, %function
EDMA3_CH39_IRQHandler:
    ldr   r0,=EDMA3_CH39_DriverIRQHandler
    bx    r0
    .size EDMA3_CH39_IRQHandler, . - EDMA3_CH39_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH40_IRQHandler
    .type EDMA3_CH40_IRQHandler, %function
EDMA3_CH40_IRQHandler:
    ldr   r0,=EDMA3_CH40_DriverIRQHandler
    bx    r0
    .size EDMA3_CH40_IRQHandler, . - EDMA3_CH40_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH41_IRQHandler
    .type EDMA3_CH41_IRQHandler, %function
EDMA3_CH41_IRQHandler:
    ldr   r0,=EDMA3_CH41_DriverIRQHandler
    bx    r0
    .size EDMA3_CH41_IRQHandler, . - EDMA3_CH41_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH42_IRQHandler
    .type EDMA3_CH42_IRQHandler, %function
EDMA3_CH42_IRQHandler:
    ldr   r0,=EDMA3_CH42_DriverIRQHandler
    bx    r0
    .size EDMA3_CH42_IRQHandler, . - EDMA3_CH42_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH43_IRQHandler
    .type EDMA3_CH43_IRQHandler, %function
EDMA3_CH43_IRQHandler:
    ldr   r0,=EDMA3_CH43_DriverIRQHandler
    bx    r0
    .size EDMA3_CH43_IRQHandler, . - EDMA3_CH43_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH44_IRQHandler
    .type EDMA3_CH44_IRQHandler, %function
EDMA3_CH44_IRQHandler:
    ldr   r0,=EDMA3_CH44_DriverIRQHandler
    bx    r0
    .size EDMA3_CH44_IRQHandler, . - EDMA3_CH44_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH45_IRQHandler
    .type EDMA3_CH45_IRQHandler, %function
EDMA3_CH45_IRQHandler:
    ldr   r0,=EDMA3_CH45_DriverIRQHandler
    bx    r0
    .size EDMA3_CH45_IRQHandler, . - EDMA3_CH45_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH46_IRQHandler
    .type EDMA3_CH46_IRQHandler, %function
EDMA3_CH46_IRQHandler:
    ldr   r0,=EDMA3_CH46_DriverIRQHandler
    bx    r0
    .size EDMA3_CH46_IRQHandler, . - EDMA3_CH46_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH47_IRQHandler
    .type EDMA3_CH47_IRQHandler, %function
EDMA3_CH47_IRQHandler:
    ldr   r0,=EDMA3_CH47_DriverIRQHandler
    bx    r0
    .size EDMA3_CH47_IRQHandler, . - EDMA3_CH47_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH48_IRQHandler
    .type EDMA3_CH48_IRQHandler, %function
EDMA3_CH48_IRQHandler:
    ldr   r0,=EDMA3_CH48_DriverIRQHandler
    bx    r0
    .size EDMA3_CH48_IRQHandler, . - EDMA3_CH48_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH49_IRQHandler
    .type EDMA3_CH49_IRQHandler, %function
EDMA3_CH49_IRQHandler:
    ldr   r0,=EDMA3_CH49_DriverIRQHandler
    bx    r0
    .size EDMA3_CH49_IRQHandler, . - EDMA3_CH49_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH50_IRQHandler
    .type EDMA3_CH50_IRQHandler, %function
EDMA3_CH50_IRQHandler:
    ldr   r0,=EDMA3_CH50_DriverIRQHandler
    bx    r0
    .size EDMA3_CH50_IRQHandler, . - EDMA3_CH50_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH51_IRQHandler
    .type EDMA3_CH51_IRQHandler, %function
EDMA3_CH51_IRQHandler:
    ldr   r0,=EDMA3_CH51_DriverIRQHandler
    bx    r0
    .size EDMA3_CH51_IRQHandler, . - EDMA3_CH51_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH52_IRQHandler
    .type EDMA3_CH52_IRQHandler, %function
EDMA3_CH52_IRQHandler:
    ldr   r0,=EDMA3_CH52_DriverIRQHandler
    bx    r0
    .size EDMA3_CH52_IRQHandler, . - EDMA3_CH52_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH53_IRQHandler
    .type EDMA3_CH53_IRQHandler, %function
EDMA3_CH53_IRQHandler:
    ldr   r0,=EDMA3_CH53_DriverIRQHandler
    bx    r0
    .size EDMA3_CH53_IRQHandler, . - EDMA3_CH53_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH54_IRQHandler
    .type EDMA3_CH54_IRQHandler, %function
EDMA3_CH54_IRQHandler:
    ldr   r0,=EDMA3_CH54_DriverIRQHandler
    bx    r0
    .size EDMA3_CH54_IRQHandler, . - EDMA3_CH54_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH55_IRQHandler
    .type EDMA3_CH55_IRQHandler, %function
EDMA3_CH55_IRQHandler:
    ldr   r0,=EDMA3_CH55_DriverIRQHandler
    bx    r0
    .size EDMA3_CH55_IRQHandler, . - EDMA3_CH55_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH56_IRQHandler
    .type EDMA3_CH56_IRQHandler, %function
EDMA3_CH56_IRQHandler:
    ldr   r0,=EDMA3_CH56_DriverIRQHandler
    bx    r0
    .size EDMA3_CH56_IRQHandler, . - EDMA3_CH56_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH57_IRQHandler
    .type EDMA3_CH57_IRQHandler, %function
EDMA3_CH57_IRQHandler:
    ldr   r0,=EDMA3_CH57_DriverIRQHandler
    bx    r0
    .size EDMA3_CH57_IRQHandler, . - EDMA3_CH57_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH58_IRQHandler
    .type EDMA3_CH58_IRQHandler, %function
EDMA3_CH58_IRQHandler:
    ldr   r0,=EDMA3_CH58_DriverIRQHandler
    bx    r0
    .size EDMA3_CH58_IRQHandler, . - EDMA3_CH58_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH59_IRQHandler
    .type EDMA3_CH59_IRQHandler, %function
EDMA3_CH59_IRQHandler:
    ldr   r0,=EDMA3_CH59_DriverIRQHandler
    bx    r0
    .size EDMA3_CH59_IRQHandler, . - EDMA3_CH59_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH60_IRQHandler
    .type EDMA3_CH60_IRQHandler, %function
EDMA3_CH60_IRQHandler:
    ldr   r0,=EDMA3_CH60_DriverIRQHandler
    bx    r0
    .size EDMA3_CH60_IRQHandler, . - EDMA3_CH60_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH61_IRQHandler
    .type EDMA3_CH61_IRQHandler, %function
EDMA3_CH61_IRQHandler:
    ldr   r0,=EDMA3_CH61_DriverIRQHandler
    bx    r0
    .size EDMA3_CH61_IRQHandler, . - EDMA3_CH61_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH62_IRQHandler
    .type EDMA3_CH62_IRQHandler, %function
EDMA3_CH62_IRQHandler:
    ldr   r0,=EDMA3_CH62_DriverIRQHandler
    bx    r0
    .size EDMA3_CH62_IRQHandler, . - EDMA3_CH62_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA3_CH63_IRQHandler
    .type EDMA3_CH63_IRQHandler, %function
EDMA3_CH63_IRQHandler:
    ldr   r0,=EDMA3_CH63_DriverIRQHandler
    bx    r0
    .size EDMA3_CH63_IRQHandler, . - EDMA3_CH63_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH0_IRQHandler
    .type EDMA1_CH0_IRQHandler, %function
EDMA1_CH0_IRQHandler:
    ldr   r0,=EDMA1_CH0_DriverIRQHandler
    bx    r0
    .size EDMA1_CH0_IRQHandler, . - EDMA1_CH0_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH1_IRQHandler
    .type EDMA1_CH1_IRQHandler, %function
EDMA1_CH1_IRQHandler:
    ldr   r0,=EDMA1_CH1_DriverIRQHandler
    bx    r0
    .size EDMA1_CH1_IRQHandler, . - EDMA1_CH1_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH2_IRQHandler
    .type EDMA1_CH2_IRQHandler, %function
EDMA1_CH2_IRQHandler:
    ldr   r0,=EDMA1_CH2_DriverIRQHandler
    bx    r0
    .size EDMA1_CH2_IRQHandler, . - EDMA1_CH2_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH3_IRQHandler
    .type EDMA1_CH3_IRQHandler, %function
EDMA1_CH3_IRQHandler:
    ldr   r0,=EDMA1_CH3_DriverIRQHandler
    bx    r0
    .size EDMA1_CH3_IRQHandler, . - EDMA1_CH3_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH4_IRQHandler
    .type EDMA1_CH4_IRQHandler, %function
EDMA1_CH4_IRQHandler:
    ldr   r0,=EDMA1_CH4_DriverIRQHandler
    bx    r0
    .size EDMA1_CH4_IRQHandler, . - EDMA1_CH4_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH5_IRQHandler
    .type EDMA1_CH5_IRQHandler, %function
EDMA1_CH5_IRQHandler:
    ldr   r0,=EDMA1_CH5_DriverIRQHandler
    bx    r0
    .size EDMA1_CH5_IRQHandler, . - EDMA1_CH5_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH6_IRQHandler
    .type EDMA1_CH6_IRQHandler, %function
EDMA1_CH6_IRQHandler:
    ldr   r0,=EDMA1_CH6_DriverIRQHandler
    bx    r0
    .size EDMA1_CH6_IRQHandler, . - EDMA1_CH6_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH7_IRQHandler
    .type EDMA1_CH7_IRQHandler, %function
EDMA1_CH7_IRQHandler:
    ldr   r0,=EDMA1_CH7_DriverIRQHandler
    bx    r0
    .size EDMA1_CH7_IRQHandler, . - EDMA1_CH7_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH8_IRQHandler
    .type EDMA1_CH8_IRQHandler, %function
EDMA1_CH8_IRQHandler:
    ldr   r0,=EDMA1_CH8_DriverIRQHandler
    bx    r0
    .size EDMA1_CH8_IRQHandler, . - EDMA1_CH8_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH9_IRQHandler
    .type EDMA1_CH9_IRQHandler, %function
EDMA1_CH9_IRQHandler:
    ldr   r0,=EDMA1_CH9_DriverIRQHandler
    bx    r0
    .size EDMA1_CH9_IRQHandler, . - EDMA1_CH9_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH10_IRQHandler
    .type EDMA1_CH10_IRQHandler, %function
EDMA1_CH10_IRQHandler:
    ldr   r0,=EDMA1_CH10_DriverIRQHandler
    bx    r0
    .size EDMA1_CH10_IRQHandler, . - EDMA1_CH10_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH11_IRQHandler
    .type EDMA1_CH11_IRQHandler, %function
EDMA1_CH11_IRQHandler:
    ldr   r0,=EDMA1_CH11_DriverIRQHandler
    bx    r0
    .size EDMA1_CH11_IRQHandler, . - EDMA1_CH11_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH12_IRQHandler
    .type EDMA1_CH12_IRQHandler, %function
EDMA1_CH12_IRQHandler:
    ldr   r0,=EDMA1_CH12_DriverIRQHandler
    bx    r0
    .size EDMA1_CH12_IRQHandler, . - EDMA1_CH12_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH13_IRQHandler
    .type EDMA1_CH13_IRQHandler, %function
EDMA1_CH13_IRQHandler:
    ldr   r0,=EDMA1_CH13_DriverIRQHandler
    bx    r0
    .size EDMA1_CH13_IRQHandler, . - EDMA1_CH13_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH14_IRQHandler
    .type EDMA1_CH14_IRQHandler, %function
EDMA1_CH14_IRQHandler:
    ldr   r0,=EDMA1_CH14_DriverIRQHandler
    bx    r0
    .size EDMA1_CH14_IRQHandler, . - EDMA1_CH14_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH15_IRQHandler
    .type EDMA1_CH15_IRQHandler, %function
EDMA1_CH15_IRQHandler:
    ldr   r0,=EDMA1_CH15_DriverIRQHandler
    bx    r0
    .size EDMA1_CH15_IRQHandler, . - EDMA1_CH15_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH16_IRQHandler
    .type EDMA1_CH16_IRQHandler, %function
EDMA1_CH16_IRQHandler:
    ldr   r0,=EDMA1_CH16_DriverIRQHandler
    bx    r0
    .size EDMA1_CH16_IRQHandler, . - EDMA1_CH16_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH17_IRQHandler
    .type EDMA1_CH17_IRQHandler, %function
EDMA1_CH17_IRQHandler:
    ldr   r0,=EDMA1_CH17_DriverIRQHandler
    bx    r0
    .size EDMA1_CH17_IRQHandler, . - EDMA1_CH17_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH18_IRQHandler
    .type EDMA1_CH18_IRQHandler, %function
EDMA1_CH18_IRQHandler:
    ldr   r0,=EDMA1_CH18_DriverIRQHandler
    bx    r0
    .size EDMA1_CH18_IRQHandler, . - EDMA1_CH18_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH19_IRQHandler
    .type EDMA1_CH19_IRQHandler, %function
EDMA1_CH19_IRQHandler:
    ldr   r0,=EDMA1_CH19_DriverIRQHandler
    bx    r0
    .size EDMA1_CH19_IRQHandler, . - EDMA1_CH19_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH20_IRQHandler
    .type EDMA1_CH20_IRQHandler, %function
EDMA1_CH20_IRQHandler:
    ldr   r0,=EDMA1_CH20_DriverIRQHandler
    bx    r0
    .size EDMA1_CH20_IRQHandler, . - EDMA1_CH20_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH21_IRQHandler
    .type EDMA1_CH21_IRQHandler, %function
EDMA1_CH21_IRQHandler:
    ldr   r0,=EDMA1_CH21_DriverIRQHandler
    bx    r0
    .size EDMA1_CH21_IRQHandler, . - EDMA1_CH21_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH22_IRQHandler
    .type EDMA1_CH22_IRQHandler, %function
EDMA1_CH22_IRQHandler:
    ldr   r0,=EDMA1_CH22_DriverIRQHandler
    bx    r0
    .size EDMA1_CH22_IRQHandler, . - EDMA1_CH22_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH23_IRQHandler
    .type EDMA1_CH23_IRQHandler, %function
EDMA1_CH23_IRQHandler:
    ldr   r0,=EDMA1_CH23_DriverIRQHandler
    bx    r0
    .size EDMA1_CH23_IRQHandler, . - EDMA1_CH23_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH24_IRQHandler
    .type EDMA1_CH24_IRQHandler, %function
EDMA1_CH24_IRQHandler:
    ldr   r0,=EDMA1_CH24_DriverIRQHandler
    bx    r0
    .size EDMA1_CH24_IRQHandler, . - EDMA1_CH24_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH25_IRQHandler
    .type EDMA1_CH25_IRQHandler, %function
EDMA1_CH25_IRQHandler:
    ldr   r0,=EDMA1_CH25_DriverIRQHandler
    bx    r0
    .size EDMA1_CH25_IRQHandler, . - EDMA1_CH25_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH26_IRQHandler
    .type EDMA1_CH26_IRQHandler, %function
EDMA1_CH26_IRQHandler:
    ldr   r0,=EDMA1_CH26_DriverIRQHandler
    bx    r0
    .size EDMA1_CH26_IRQHandler, . - EDMA1_CH26_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH27_IRQHandler
    .type EDMA1_CH27_IRQHandler, %function
EDMA1_CH27_IRQHandler:
    ldr   r0,=EDMA1_CH27_DriverIRQHandler
    bx    r0
    .size EDMA1_CH27_IRQHandler, . - EDMA1_CH27_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH28_IRQHandler
    .type EDMA1_CH28_IRQHandler, %function
EDMA1_CH28_IRQHandler:
    ldr   r0,=EDMA1_CH28_DriverIRQHandler
    bx    r0
    .size EDMA1_CH28_IRQHandler, . - EDMA1_CH28_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH29_IRQHandler
    .type EDMA1_CH29_IRQHandler, %function
EDMA1_CH29_IRQHandler:
    ldr   r0,=EDMA1_CH29_DriverIRQHandler
    bx    r0
    .size EDMA1_CH29_IRQHandler, . - EDMA1_CH29_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH30_IRQHandler
    .type EDMA1_CH30_IRQHandler, %function
EDMA1_CH30_IRQHandler:
    ldr   r0,=EDMA1_CH30_DriverIRQHandler
    bx    r0
    .size EDMA1_CH30_IRQHandler, . - EDMA1_CH30_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_CH31_IRQHandler
    .type EDMA1_CH31_IRQHandler, %function
EDMA1_CH31_IRQHandler:
    ldr   r0,=EDMA1_CH31_DriverIRQHandler
    bx    r0
    .size EDMA1_CH31_IRQHandler, . - EDMA1_CH31_IRQHandler

    .align 1
    .thumb_func
    .weak EDMA1_ERROR_IRQHandler
    .type EDMA1_ERROR_IRQHandler, %function
EDMA1_ERROR_IRQHandler:
    ldr   r0,=EDMA1_ERROR_DriverIRQHandler
    bx    r0
    .size EDMA1_ERROR_IRQHandler, . - EDMA1_ERROR_IRQHandler

    .align 1
    .thumb_func
    .weak XSPI1_IRQHandler
    .type XSPI1_IRQHandler, %function
XSPI1_IRQHandler:
    ldr   r0,=XSPI1_DriverIRQHandler
    bx    r0
    .size XSPI1_IRQHandler, . - XSPI1_IRQHandler

    .align 1
    .thumb_func
    .weak XSPI2_IRQHandler
    .type XSPI2_IRQHandler, %function
XSPI2_IRQHandler:
    ldr   r0,=XSPI2_DriverIRQHandler
    bx    r0
    .size XSPI2_IRQHandler, . - XSPI2_IRQHandler


/*    Macro to define default handlers. Default handler
 *    will be weak symbol and just dead loops. They can be
 *    overwritten by other handlers */
    .macro def_irq_handler  handler_name
    .weak \handler_name
    .set  \handler_name, DefaultISR
    .endm
/* Exception Handlers */
    def_irq_handler    MemManage_Handler
    def_irq_handler    BusFault_Handler
    def_irq_handler    UsageFault_Handler
    def_irq_handler    DebugMon_Handler
    def_irq_handler    Reserved16_IRQHandler
    def_irq_handler    Reserved17_IRQHandler
    def_irq_handler    Reserved18_IRQHandler
    def_irq_handler    Reserved19_IRQHandler
    def_irq_handler    Reserved20_IRQHandler
    def_irq_handler    Reserved21_IRQHandler
    def_irq_handler    Reserved22_IRQHandler
    def_irq_handler    Reserved23_IRQHandler
    def_irq_handler    Reserved24_IRQHandler
    def_irq_handler    Reserved25_IRQHandler
    def_irq_handler    CAN1_DriverIRQHandler
    def_irq_handler    CAN1_ERROR_DriverIRQHandler
    def_irq_handler    GPIO1_INT0_IRQHandler
    def_irq_handler    GPIO1_INT1_IRQHandler
    def_irq_handler    I3C1_DriverIRQHandler
    def_irq_handler    LPI2C1_DriverIRQHandler
    def_irq_handler    LPI2C2_DriverIRQHandler
    def_irq_handler    LPIT1_IRQHandler
    def_irq_handler    LPSPI1_DriverIRQHandler
    def_irq_handler    LPSPI2_DriverIRQHandler
    def_irq_handler    LPTMR1_IRQHandler
    def_irq_handler    LPUART1_DriverIRQHandler
    def_irq_handler    LPUART2_DriverIRQHandler
    def_irq_handler    Reserved39_IRQHandler
    def_irq_handler    Reserved40_IRQHandler
    def_irq_handler    Reserved41_IRQHandler
    def_irq_handler    Reserved42_IRQHandler
    def_irq_handler    Reserved43_IRQHandler
    def_irq_handler    Reserved44_IRQHandler
    def_irq_handler    Reserved45_IRQHandler
    def_irq_handler    Reserved46_IRQHandler
    def_irq_handler    Reserved47_IRQHandler
    def_irq_handler    V2X_FH_APCH0_IRQHandler
    def_irq_handler    V2X_FH_APHSM1_IRQHandler
    def_irq_handler    TPM1_IRQHandler
    def_irq_handler    TPM2_IRQHandler
    def_irq_handler    WDOG1_IRQHandler
    def_irq_handler    WDOG2_IRQHandler
    def_irq_handler    SAI1_DriverIRQHandler
    def_irq_handler    GPT1_IRQHandler
    def_irq_handler    CAN2_DriverIRQHandler
    def_irq_handler    CAN2_ERROR_DriverIRQHandler
    def_irq_handler    CAN3_DriverIRQHandler
    def_irq_handler    CAN3_ERROR_DriverIRQHandler
    def_irq_handler    CAN4_DriverIRQHandler
    def_irq_handler    CAN4_ERROR_DriverIRQHandler
    def_irq_handler    CAN5_DriverIRQHandler
    def_irq_handler    CAN5_ERROR_DriverIRQHandler
    def_irq_handler    FLEXIO1_DriverIRQHandler
    def_irq_handler    FLEXIO2_DriverIRQHandler
    def_irq_handler    FLEXIO3_DriverIRQHandler
    def_irq_handler    FLEXIO4_DriverIRQHandler
    def_irq_handler    Reserved68_IRQHandler
    def_irq_handler    Reserved69_IRQHandler
    def_irq_handler    GPIO2_INT0_IRQHandler
    def_irq_handler    GPIO2_INT1_IRQHandler
    def_irq_handler    GPIO3_INT0_IRQHandler
    def_irq_handler    GPIO3_INT1_IRQHandler
    def_irq_handler    GPIO4_INT0_IRQHandler
    def_irq_handler    GPIO4_INT1_IRQHandler
    def_irq_handler    GPIO5_INT0_IRQHandler
    def_irq_handler    GPIO5_INT1_IRQHandler
    def_irq_handler    GPIO6_INT0_IRQHandler
    def_irq_handler    GPIO6_INT1_IRQHandler
    def_irq_handler    GPIO7_INT0_IRQHandler
    def_irq_handler    GPIO7_INT1_IRQHandler
    def_irq_handler    I3C2_DriverIRQHandler
    def_irq_handler    LPI2C3_DriverIRQHandler
    def_irq_handler    LPI2C4_DriverIRQHandler
    def_irq_handler    LPIT2_IRQHandler
    def_irq_handler    LPIT3_IRQHandler
    def_irq_handler    LPSPI3_DriverIRQHandler
    def_irq_handler    LPSPI4_DriverIRQHandler
    def_irq_handler    LPTMR2_IRQHandler
    def_irq_handler    LPUART3_DriverIRQHandler
    def_irq_handler    LPUART4_DriverIRQHandler
    def_irq_handler    LPUART5_DriverIRQHandler
    def_irq_handler    LPUART6_DriverIRQHandler
    def_irq_handler    LPUART7_DriverIRQHandler
    def_irq_handler    LPUART8_DriverIRQHandler
    def_irq_handler    LPUART9_DriverIRQHandler
    def_irq_handler    LPUART10_DriverIRQHandler
    def_irq_handler    LPUART11_DriverIRQHandler
    def_irq_handler    LPUART12_DriverIRQHandler
    def_irq_handler    BBNSM_IRQHandler
    def_irq_handler    SYSCTR1_IRQHandler
    def_irq_handler    TPM3_IRQHandler
    def_irq_handler    TPM4_IRQHandler
    def_irq_handler    TPM5_IRQHandler
    def_irq_handler    TPM6_IRQHandler
    def_irq_handler    WDOG3_IRQHandler
    def_irq_handler    WDOG4_IRQHandler
    def_irq_handler    WDOG5_IRQHandler
    def_irq_handler    WDOG6_IRQHandler
    def_irq_handler    WDOG7_IRQHandler
    def_irq_handler    WDOG8_IRQHandler
    def_irq_handler    USDHC1_DriverIRQHandler
    def_irq_handler    USDHC2_DriverIRQHandler
    def_irq_handler    EDMA2_ERROR_DriverIRQHandler
    def_irq_handler    Reserved115_IRQHandler
    def_irq_handler    Reserved116_IRQHandler
    def_irq_handler    SAI2_DriverIRQHandler
    def_irq_handler    SAI3_DriverIRQHandler
    def_irq_handler    SAI4_DriverIRQHandler
    def_irq_handler    LPSPI5_DriverIRQHandler
    def_irq_handler    LPSPI6_DriverIRQHandler
    def_irq_handler    LPSPI7_DriverIRQHandler
    def_irq_handler    LPSPI8_DriverIRQHandler
    def_irq_handler    LPI2C5_DriverIRQHandler
    def_irq_handler    LPI2C6_DriverIRQHandler
    def_irq_handler    LPI2C7_DriverIRQHandler
    def_irq_handler    LPI2C8_DriverIRQHandler
    def_irq_handler    PDM_HWVAD_ERROR_IRQHandler
    def_irq_handler    PDM_HWVAD_EVENT_IRQHandler
    def_irq_handler    PDM_ERROR_IRQHandler
    def_irq_handler    PDM_EVENT_DriverIRQHandler
    def_irq_handler    USDHC3_DriverIRQHandler
    def_irq_handler    ADC_ER_IRQHandler
    def_irq_handler    ADC_WD_IRQHandler
    def_irq_handler    ADC_EOC_IRQHandler
    def_irq_handler    Reserved136_IRQHandler
    def_irq_handler    Reserved137_IRQHandler
    def_irq_handler    MU5_A_IRQHandler
    def_irq_handler    MU6_A_IRQHandler
    def_irq_handler    MU7_A_IRQHandler
    def_irq_handler    MU10_B_IRQHandler
    def_irq_handler    MU11_B_IRQHandler
    def_irq_handler    MU12_A_IRQHandler
    def_irq_handler    MU13_A_IRQHandler
    def_irq_handler    MU18_A_IRQHandler
    def_irq_handler    MU18_B_IRQHandler
    def_irq_handler    MU_E1_A_IRQHandler
    def_irq_handler    MU_E2_A_IRQHandler
    def_irq_handler    MU_E3_A_IRQHandler
    def_irq_handler    MU_E4_A_IRQHandler
    def_irq_handler    XSPI_SLV_DriverIRQHandler
    def_irq_handler    FCCU_INT0_IRQHandler
    def_irq_handler    FCCU_INT1_IRQHandler
    def_irq_handler    FCCU_INT2_IRQHandler
    def_irq_handler    FCCU_INT3_IRQHandler
    def_irq_handler    FCCU_INT4_IRQHandler
    def_irq_handler    STCU_IRQHandler
    def_irq_handler    XBAR1_CH0_CH1_IRQHandler
    def_irq_handler    XBAR1_CH2_CH3_IRQHandler
    def_irq_handler    GPT2_IRQHandler
    def_irq_handler    GPT3_IRQHandler
    def_irq_handler    GPT4_IRQHandler
    def_irq_handler    Reserved163_IRQHandler
    def_irq_handler    Reserved164_IRQHandler
    def_irq_handler    Reserved165_IRQHandler
    def_irq_handler    Reserved166_IRQHandler
    def_irq_handler    Reserved167_IRQHandler
    def_irq_handler    Reserved168_IRQHandler
    def_irq_handler    Reserved169_IRQHandler
    def_irq_handler    Reserved170_IRQHandler
    def_irq_handler    Reserved171_IRQHandler
    def_irq_handler    Reserved172_IRQHandler
    def_irq_handler    Reserved173_IRQHandler
    def_irq_handler    Reserved174_IRQHandler
    def_irq_handler    Reserved175_IRQHandler
    def_irq_handler    Reserved176_IRQHandler
    def_irq_handler    Reserved177_IRQHandler
    def_irq_handler    Reserved178_IRQHandler
    def_irq_handler    Reserved179_IRQHandler
    def_irq_handler    Reserved180_IRQHandler
    def_irq_handler    Reserved181_IRQHandler
    def_irq_handler    Reserved182_IRQHandler
    def_irq_handler    Reserved183_IRQHandler
    def_irq_handler    Reserved184_IRQHandler
    def_irq_handler    Reserved185_IRQHandler
    def_irq_handler    Reserved186_IRQHandler
    def_irq_handler    ENC1_IRQHandler
    def_irq_handler    ENC2_IRQHandler
    def_irq_handler    ENC3_IRQHandler
    def_irq_handler    ENC4_IRQHandler
    def_irq_handler    EWM_IRQHandler
    def_irq_handler    Reserved192_IRQHandler
    def_irq_handler    Reserved193_IRQHandler
    def_irq_handler    Reserved194_IRQHandler
    def_irq_handler    Reserved195_IRQHandler
    def_irq_handler    USB1_IRQHandler
    def_irq_handler    USB2_IRQHandler
    def_irq_handler    SINC1_CH0_IRQHandler
    def_irq_handler    SINC1_CH1_IRQHandler
    def_irq_handler    SINC1_CH2_IRQHandler
    def_irq_handler    SINC1_CH3_IRQHandler
    def_irq_handler    SINC2_CH0_IRQHandler
    def_irq_handler    SINC2_CH1_IRQHandler
    def_irq_handler    SINC2_CH2_IRQHandler
    def_irq_handler    SINC2_CH3_IRQHandler
    def_irq_handler    SINC3_CH0_IRQHandler
    def_irq_handler    SINC3_CH1_IRQHandler
    def_irq_handler    SINC3_CH2_IRQHandler
    def_irq_handler    SINC3_CH3_IRQHandler
    def_irq_handler    SINC4_CH0_IRQHandler
    def_irq_handler    SINC4_CH1_IRQHandler
    def_irq_handler    SINC4_CH2_IRQHandler
    def_irq_handler    SINC4_CH3_IRQHandler
    def_irq_handler    TMR1_IRQHandler
    def_irq_handler    TMR2_IRQHandler
    def_irq_handler    TMR3_IRQHandler
    def_irq_handler    TMR4_IRQHandler
    def_irq_handler    TMR5_IRQHandler
    def_irq_handler    TMR6_IRQHandler
    def_irq_handler    TMR7_IRQHandler
    def_irq_handler    TMR8_IRQHandler
    def_irq_handler    EDMA4_ERROR_DriverIRQHandler
    def_irq_handler    Reserved223_IRQHandler
    def_irq_handler    Reserved224_IRQHandler
    def_irq_handler    Reserved225_IRQHandler
    def_irq_handler    Reserved226_IRQHandler
    def_irq_handler    Reserved227_IRQHandler
    def_irq_handler    Reserved228_IRQHandler
    def_irq_handler    Reserved229_IRQHandler
    def_irq_handler    Reserved230_IRQHandler
    def_irq_handler    Reserved231_IRQHandler
    def_irq_handler    Reserved232_IRQHandler
    def_irq_handler    Reserved233_IRQHandler
    def_irq_handler    Reserved234_IRQHandler
    def_irq_handler    Reserved235_IRQHandler
    def_irq_handler    Reserved236_IRQHandler
    def_irq_handler    Reserved237_IRQHandler
    def_irq_handler    Reserved238_IRQHandler
    def_irq_handler    Reserved239_IRQHandler
    def_irq_handler    IRQSTEERM7_CH0_DriverIRQHandler
    def_irq_handler    IRQSTEERM7_CH1_DriverIRQHandler
    def_irq_handler    IRQSTEERM7_CH2_DriverIRQHandler
    def_irq_handler    IRQSTEERM7_CH3_DriverIRQHandler
    def_irq_handler    IRQSTEERM7_CH4_DriverIRQHandler
    def_irq_handler    IRQSTEERM7_CH5_DriverIRQHandler
    def_irq_handler    IRQSTEERM7_CH6_DriverIRQHandler
    def_irq_handler    IRQSTEERM7_CH7_DriverIRQHandler
    def_irq_handler    IRQSTEERM7_CH8_DriverIRQHandler
    def_irq_handler    IRQSTEERM7_CH9_DriverIRQHandler
    def_irq_handler    IRQSTEERM7_CH10_DriverIRQHandler
    def_irq_handler    IRQSTEERM7_CH11_DriverIRQHandler
    def_irq_handler    IRQSTEERM7_CH12_DriverIRQHandler
    def_irq_handler    Reserved253_IRQHandler
    def_irq_handler    EDMA2_CH0_DriverIRQHandler
    def_irq_handler    EDMA2_CH1_DriverIRQHandler
    def_irq_handler    EDMA2_CH2_DriverIRQHandler
    def_irq_handler    EDMA2_CH3_DriverIRQHandler
    def_irq_handler    EDMA2_CH4_DriverIRQHandler
    def_irq_handler    EDMA2_CH5_DriverIRQHandler
    def_irq_handler    EDMA2_CH6_DriverIRQHandler
    def_irq_handler    EDMA2_CH7_DriverIRQHandler
    def_irq_handler    EDMA2_CH8_DriverIRQHandler
    def_irq_handler    EDMA2_CH9_DriverIRQHandler
    def_irq_handler    EDMA2_CH10_DriverIRQHandler
    def_irq_handler    EDMA2_CH11_DriverIRQHandler
    def_irq_handler    EDMA2_CH12_DriverIRQHandler
    def_irq_handler    EDMA2_CH13_DriverIRQHandler
    def_irq_handler    EDMA2_CH14_DriverIRQHandler
    def_irq_handler    EDMA2_CH15_DriverIRQHandler
    def_irq_handler    EDMA2_CH16_DriverIRQHandler
    def_irq_handler    EDMA2_CH17_DriverIRQHandler
    def_irq_handler    EDMA2_CH18_DriverIRQHandler
    def_irq_handler    EDMA2_CH19_DriverIRQHandler
    def_irq_handler    EDMA2_CH20_DriverIRQHandler
    def_irq_handler    EDMA2_CH21_DriverIRQHandler
    def_irq_handler    EDMA2_CH22_DriverIRQHandler
    def_irq_handler    EDMA2_CH23_DriverIRQHandler
    def_irq_handler    EDMA2_CH24_DriverIRQHandler
    def_irq_handler    EDMA2_CH25_DriverIRQHandler
    def_irq_handler    EDMA2_CH26_DriverIRQHandler
    def_irq_handler    EDMA2_CH27_DriverIRQHandler
    def_irq_handler    EDMA2_CH28_DriverIRQHandler
    def_irq_handler    EDMA2_CH29_DriverIRQHandler
    def_irq_handler    EDMA2_CH30_DriverIRQHandler
    def_irq_handler    EDMA2_CH31_DriverIRQHandler
    def_irq_handler    EDMA2_CH32_DriverIRQHandler
    def_irq_handler    EDMA2_CH33_DriverIRQHandler
    def_irq_handler    EDMA2_CH34_DriverIRQHandler
    def_irq_handler    EDMA2_CH35_DriverIRQHandler
    def_irq_handler    EDMA2_CH36_DriverIRQHandler
    def_irq_handler    EDMA2_CH37_DriverIRQHandler
    def_irq_handler    EDMA2_CH38_DriverIRQHandler
    def_irq_handler    EDMA2_CH39_DriverIRQHandler
    def_irq_handler    EDMA2_CH40_DriverIRQHandler
    def_irq_handler    EDMA2_CH41_DriverIRQHandler
    def_irq_handler    EDMA2_CH42_DriverIRQHandler
    def_irq_handler    EDMA2_CH43_DriverIRQHandler
    def_irq_handler    EDMA2_CH44_DriverIRQHandler
    def_irq_handler    EDMA2_CH45_DriverIRQHandler
    def_irq_handler    EDMA2_CH46_DriverIRQHandler
    def_irq_handler    EDMA2_CH47_DriverIRQHandler
    def_irq_handler    EDMA2_CH48_DriverIRQHandler
    def_irq_handler    EDMA2_CH49_DriverIRQHandler
    def_irq_handler    EDMA2_CH50_DriverIRQHandler
    def_irq_handler    EDMA2_CH51_DriverIRQHandler
    def_irq_handler    EDMA2_CH52_DriverIRQHandler
    def_irq_handler    EDMA2_CH53_DriverIRQHandler
    def_irq_handler    EDMA2_CH54_DriverIRQHandler
    def_irq_handler    EDMA2_CH55_DriverIRQHandler
    def_irq_handler    EDMA2_CH56_DriverIRQHandler
    def_irq_handler    EDMA2_CH57_DriverIRQHandler
    def_irq_handler    EDMA2_CH58_DriverIRQHandler
    def_irq_handler    EDMA2_CH59_DriverIRQHandler
    def_irq_handler    EDMA2_CH60_DriverIRQHandler
    def_irq_handler    EDMA2_CH61_DriverIRQHandler
    def_irq_handler    EDMA2_CH62_DriverIRQHandler
    def_irq_handler    EDMA2_CH63_DriverIRQHandler
    def_irq_handler    EDMA4_CH0_DriverIRQHandler
    def_irq_handler    EDMA4_CH1_DriverIRQHandler
    def_irq_handler    EDMA4_CH2_DriverIRQHandler
    def_irq_handler    EDMA4_CH3_DriverIRQHandler
    def_irq_handler    EDMA4_CH4_DriverIRQHandler
    def_irq_handler    EDMA4_CH5_DriverIRQHandler
    def_irq_handler    EDMA4_CH6_DriverIRQHandler
    def_irq_handler    EDMA4_CH7_DriverIRQHandler
    def_irq_handler    EDMA4_CH8_DriverIRQHandler
    def_irq_handler    EDMA4_CH9_DriverIRQHandler
    def_irq_handler    EDMA4_CH10_DriverIRQHandler
    def_irq_handler    EDMA4_CH11_DriverIRQHandler
    def_irq_handler    EDMA4_CH12_DriverIRQHandler
    def_irq_handler    EDMA4_CH13_DriverIRQHandler
    def_irq_handler    EDMA4_CH14_DriverIRQHandler
    def_irq_handler    EDMA4_CH15_DriverIRQHandler
    def_irq_handler    EDMA4_CH16_DriverIRQHandler
    def_irq_handler    EDMA4_CH17_DriverIRQHandler
    def_irq_handler    EDMA4_CH18_DriverIRQHandler
    def_irq_handler    EDMA4_CH19_DriverIRQHandler
    def_irq_handler    EDMA4_CH20_DriverIRQHandler
    def_irq_handler    EDMA4_CH21_DriverIRQHandler
    def_irq_handler    EDMA4_CH22_DriverIRQHandler
    def_irq_handler    EDMA4_CH23_DriverIRQHandler
    def_irq_handler    EDMA4_CH24_DriverIRQHandler
    def_irq_handler    EDMA4_CH25_DriverIRQHandler
    def_irq_handler    EDMA4_CH26_DriverIRQHandler
    def_irq_handler    EDMA4_CH27_DriverIRQHandler
    def_irq_handler    EDMA4_CH28_DriverIRQHandler
    def_irq_handler    EDMA4_CH29_DriverIRQHandler
    def_irq_handler    EDMA4_CH30_DriverIRQHandler
    def_irq_handler    EDMA4_CH31_DriverIRQHandler
    def_irq_handler    EDMA4_CH32_DriverIRQHandler
    def_irq_handler    EDMA4_CH33_DriverIRQHandler
    def_irq_handler    EDMA4_CH34_DriverIRQHandler
    def_irq_handler    EDMA4_CH35_DriverIRQHandler
    def_irq_handler    EDMA4_CH36_DriverIRQHandler
    def_irq_handler    EDMA4_CH37_DriverIRQHandler
    def_irq_handler    EDMA4_CH38_DriverIRQHandler
    def_irq_handler    EDMA4_CH39_DriverIRQHandler
    def_irq_handler    EDMA4_CH40_DriverIRQHandler
    def_irq_handler    EDMA4_CH41_DriverIRQHandler
    def_irq_handler    EDMA4_CH42_DriverIRQHandler
    def_irq_handler    EDMA4_CH43_DriverIRQHandler
    def_irq_handler    EDMA4_CH44_DriverIRQHandler
    def_irq_handler    EDMA4_CH45_DriverIRQHandler
    def_irq_handler    EDMA4_CH46_DriverIRQHandler
    def_irq_handler    EDMA4_CH47_DriverIRQHandler
    def_irq_handler    EDMA4_CH48_DriverIRQHandler
    def_irq_handler    EDMA4_CH49_DriverIRQHandler
    def_irq_handler    EDMA4_CH50_DriverIRQHandler
    def_irq_handler    EDMA4_CH51_DriverIRQHandler
    def_irq_handler    EDMA4_CH52_DriverIRQHandler
    def_irq_handler    EDMA4_CH53_DriverIRQHandler
    def_irq_handler    EDMA4_CH54_DriverIRQHandler
    def_irq_handler    EDMA4_CH55_DriverIRQHandler
    def_irq_handler    EDMA4_CH56_DriverIRQHandler
    def_irq_handler    EDMA4_CH57_DriverIRQHandler
    def_irq_handler    EDMA4_CH58_DriverIRQHandler
    def_irq_handler    EDMA4_CH59_DriverIRQHandler
    def_irq_handler    EDMA4_CH60_DriverIRQHandler
    def_irq_handler    EDMA4_CH61_DriverIRQHandler
    def_irq_handler    EDMA4_CH62_DriverIRQHandler
    def_irq_handler    EDMA4_CH63_DriverIRQHandler
    def_irq_handler    EDMA3_CH0_DriverIRQHandler
    def_irq_handler    EDMA3_CH1_DriverIRQHandler
    def_irq_handler    EDMA3_CH2_DriverIRQHandler
    def_irq_handler    EDMA3_CH3_DriverIRQHandler
    def_irq_handler    EDMA3_CH4_DriverIRQHandler
    def_irq_handler    EDMA3_CH5_DriverIRQHandler
    def_irq_handler    EDMA3_CH6_DriverIRQHandler
    def_irq_handler    EDMA3_CH7_DriverIRQHandler
    def_irq_handler    EDMA3_CH8_DriverIRQHandler
    def_irq_handler    EDMA3_CH9_DriverIRQHandler
    def_irq_handler    EDMA3_CH10_DriverIRQHandler
    def_irq_handler    EDMA3_CH11_DriverIRQHandler
    def_irq_handler    EDMA3_CH12_DriverIRQHandler
    def_irq_handler    EDMA3_CH13_DriverIRQHandler
    def_irq_handler    EDMA3_CH14_DriverIRQHandler
    def_irq_handler    EDMA3_CH15_DriverIRQHandler
    def_irq_handler    EDMA3_CH16_DriverIRQHandler
    def_irq_handler    EDMA3_CH17_DriverIRQHandler
    def_irq_handler    EDMA3_CH18_DriverIRQHandler
    def_irq_handler    EDMA3_CH19_DriverIRQHandler
    def_irq_handler    EDMA3_CH20_DriverIRQHandler
    def_irq_handler    EDMA3_CH21_DriverIRQHandler
    def_irq_handler    EDMA3_CH22_DriverIRQHandler
    def_irq_handler    EDMA3_CH23_DriverIRQHandler
    def_irq_handler    EDMA3_CH24_DriverIRQHandler
    def_irq_handler    EDMA3_CH25_DriverIRQHandler
    def_irq_handler    EDMA3_CH26_DriverIRQHandler
    def_irq_handler    EDMA3_CH27_DriverIRQHandler
    def_irq_handler    EDMA3_CH28_DriverIRQHandler
    def_irq_handler    EDMA3_CH29_DriverIRQHandler
    def_irq_handler    EDMA3_CH30_DriverIRQHandler
    def_irq_handler    EDMA3_CH31_DriverIRQHandler
    def_irq_handler    EDMA3_CH32_DriverIRQHandler
    def_irq_handler    EDMA3_CH33_DriverIRQHandler
    def_irq_handler    EDMA3_CH34_DriverIRQHandler
    def_irq_handler    EDMA3_CH35_DriverIRQHandler
    def_irq_handler    EDMA3_CH36_DriverIRQHandler
    def_irq_handler    EDMA3_CH37_DriverIRQHandler
    def_irq_handler    EDMA3_CH38_DriverIRQHandler
    def_irq_handler    EDMA3_CH39_DriverIRQHandler
    def_irq_handler    EDMA3_CH40_DriverIRQHandler
    def_irq_handler    EDMA3_CH41_DriverIRQHandler
    def_irq_handler    EDMA3_CH42_DriverIRQHandler
    def_irq_handler    EDMA3_CH43_DriverIRQHandler
    def_irq_handler    EDMA3_CH44_DriverIRQHandler
    def_irq_handler    EDMA3_CH45_DriverIRQHandler
    def_irq_handler    EDMA3_CH46_DriverIRQHandler
    def_irq_handler    EDMA3_CH47_DriverIRQHandler
    def_irq_handler    EDMA3_CH48_DriverIRQHandler
    def_irq_handler    EDMA3_CH49_DriverIRQHandler
    def_irq_handler    EDMA3_CH50_DriverIRQHandler
    def_irq_handler    EDMA3_CH51_DriverIRQHandler
    def_irq_handler    EDMA3_CH52_DriverIRQHandler
    def_irq_handler    EDMA3_CH53_DriverIRQHandler
    def_irq_handler    EDMA3_CH54_DriverIRQHandler
    def_irq_handler    EDMA3_CH55_DriverIRQHandler
    def_irq_handler    EDMA3_CH56_DriverIRQHandler
    def_irq_handler    EDMA3_CH57_DriverIRQHandler
    def_irq_handler    EDMA3_CH58_DriverIRQHandler
    def_irq_handler    EDMA3_CH59_DriverIRQHandler
    def_irq_handler    EDMA3_CH60_DriverIRQHandler
    def_irq_handler    EDMA3_CH61_DriverIRQHandler
    def_irq_handler    EDMA3_CH62_DriverIRQHandler
    def_irq_handler    EDMA3_CH63_DriverIRQHandler
    def_irq_handler    EDMA1_CH0_DriverIRQHandler
    def_irq_handler    EDMA1_CH1_DriverIRQHandler
    def_irq_handler    EDMA1_CH2_DriverIRQHandler
    def_irq_handler    EDMA1_CH3_DriverIRQHandler
    def_irq_handler    EDMA1_CH4_DriverIRQHandler
    def_irq_handler    EDMA1_CH5_DriverIRQHandler
    def_irq_handler    EDMA1_CH6_DriverIRQHandler
    def_irq_handler    EDMA1_CH7_DriverIRQHandler
    def_irq_handler    EDMA1_CH8_DriverIRQHandler
    def_irq_handler    EDMA1_CH9_DriverIRQHandler
    def_irq_handler    EDMA1_CH10_DriverIRQHandler
    def_irq_handler    EDMA1_CH11_DriverIRQHandler
    def_irq_handler    EDMA1_CH12_DriverIRQHandler
    def_irq_handler    EDMA1_CH13_DriverIRQHandler
    def_irq_handler    EDMA1_CH14_DriverIRQHandler
    def_irq_handler    EDMA1_CH15_DriverIRQHandler
    def_irq_handler    EDMA1_CH16_DriverIRQHandler
    def_irq_handler    EDMA1_CH17_DriverIRQHandler
    def_irq_handler    EDMA1_CH18_DriverIRQHandler
    def_irq_handler    EDMA1_CH19_DriverIRQHandler
    def_irq_handler    EDMA1_CH20_DriverIRQHandler
    def_irq_handler    EDMA1_CH21_DriverIRQHandler
    def_irq_handler    EDMA1_CH22_DriverIRQHandler
    def_irq_handler    EDMA1_CH23_DriverIRQHandler
    def_irq_handler    EDMA1_CH24_DriverIRQHandler
    def_irq_handler    EDMA1_CH25_DriverIRQHandler
    def_irq_handler    EDMA1_CH26_DriverIRQHandler
    def_irq_handler    EDMA1_CH27_DriverIRQHandler
    def_irq_handler    EDMA1_CH28_DriverIRQHandler
    def_irq_handler    EDMA1_CH29_DriverIRQHandler
    def_irq_handler    EDMA1_CH30_DriverIRQHandler
    def_irq_handler    EDMA1_CH31_DriverIRQHandler
    def_irq_handler    Reserved478_IRQHandler
    def_irq_handler    Reserved479_IRQHandler
    def_irq_handler    Reserved480_IRQHandler
    def_irq_handler    Reserved481_IRQHandler
    def_irq_handler    Reserved482_IRQHandler
    def_irq_handler    Reserved483_IRQHandler
    def_irq_handler    Reserved484_IRQHandler
    def_irq_handler    Reserved485_IRQHandler
    def_irq_handler    Reserved486_IRQHandler
    def_irq_handler    Reserved487_IRQHandler
    def_irq_handler    Reserved488_IRQHandler
    def_irq_handler    Reserved489_IRQHandler
    def_irq_handler    Reserved490_IRQHandler
    def_irq_handler    Reserved491_IRQHandler
    def_irq_handler    Reserved492_IRQHandler
    def_irq_handler    Reserved493_IRQHandler
    def_irq_handler    Reserved494_IRQHandler
    def_irq_handler    Reserved495_IRQHandler
    def_irq_handler    Reserved496_IRQHandler
    def_irq_handler    Reserved497_IRQHandler
    def_irq_handler    Reserved498_IRQHandler
    def_irq_handler    Reserved499_IRQHandler
    def_irq_handler    Reserved500_IRQHandler
    def_irq_handler    Reserved501_IRQHandler
    def_irq_handler    Reserved502_IRQHandler
    def_irq_handler    Reserved503_IRQHandler
    def_irq_handler    Reserved504_IRQHandler
    def_irq_handler    Reserved505_IRQHandler
    def_irq_handler    Reserved506_IRQHandler
    def_irq_handler    Reserved507_IRQHandler
    def_irq_handler    Reserved508_IRQHandler
    def_irq_handler    Reserved509_IRQHandler
    def_irq_handler    MU1_A_IRQHandler
    def_irq_handler    MU1_B_IRQHandler
    def_irq_handler    MU2_A_IRQHandler
    def_irq_handler    MU2_B_IRQHandler
    def_irq_handler    MU3_A_IRQHandler
    def_irq_handler    MU3_B_IRQHandler
    def_irq_handler    MU4_A_IRQHandler
    def_irq_handler    MU4_B_IRQHandler
    def_irq_handler    MU5_B_IRQHandler
    def_irq_handler    MU6_B_IRQHandler
    def_irq_handler    MU7_B_IRQHandler
    def_irq_handler    MU8_A_IRQHandler
    def_irq_handler    MU8_B_IRQHandler
    def_irq_handler    MU9_A_IRQHandler
    def_irq_handler    MU9_B_IRQHandler
    def_irq_handler    MU10_A_IRQHandler
    def_irq_handler    Reserved526_IRQHandler
    def_irq_handler    Reserved527_IRQHandler
    def_irq_handler    Reserved528_IRQHandler
    def_irq_handler    Reserved529_IRQHandler
    def_irq_handler    Reserved530_IRQHandler
    def_irq_handler    Reserved531_IRQHandler
    def_irq_handler    Reserved532_IRQHandler
    def_irq_handler    Reserved533_IRQHandler
    def_irq_handler    Reserved534_IRQHandler
    def_irq_handler    Reserved535_IRQHandler
    def_irq_handler    Reserved536_IRQHandler
    def_irq_handler    Reserved537_IRQHandler
    def_irq_handler    Reserved538_IRQHandler
    def_irq_handler    Reserved539_IRQHandler
    def_irq_handler    Reserved540_IRQHandler
    def_irq_handler    Reserved541_IRQHandler
    def_irq_handler    Reserved542_IRQHandler
    def_irq_handler    Reserved543_IRQHandler
    def_irq_handler    Reserved544_IRQHandler
    def_irq_handler    Reserved545_IRQHandler
    def_irq_handler    Reserved546_IRQHandler
    def_irq_handler    Reserved547_IRQHandler
    def_irq_handler    Reserved548_IRQHandler
    def_irq_handler    Reserved549_IRQHandler
    def_irq_handler    Reserved550_IRQHandler
    def_irq_handler    Reserved551_IRQHandler
    def_irq_handler    Reserved552_IRQHandler
    def_irq_handler    Reserved553_IRQHandler
    def_irq_handler    Reserved554_IRQHandler
    def_irq_handler    Reserved555_IRQHandler
    def_irq_handler    Reserved556_IRQHandler
    def_irq_handler    Reserved557_IRQHandler
    def_irq_handler    Reserved558_IRQHandler
    def_irq_handler    Reserved559_IRQHandler
    def_irq_handler    Reserved560_IRQHandler
    def_irq_handler    Reserved561_IRQHandler
    def_irq_handler    Reserved562_IRQHandler
    def_irq_handler    Reserved563_IRQHandler
    def_irq_handler    Reserved564_IRQHandler
    def_irq_handler    Reserved565_IRQHandler
    def_irq_handler    Reserved566_IRQHandler
    def_irq_handler    Reserved567_IRQHandler
    def_irq_handler    Reserved568_IRQHandler
    def_irq_handler    Reserved569_IRQHandler
    def_irq_handler    Reserved570_IRQHandler
    def_irq_handler    Reserved571_IRQHandler
    def_irq_handler    Reserved572_IRQHandler
    def_irq_handler    Reserved573_IRQHandler
    def_irq_handler    MU11_A_IRQHandler
    def_irq_handler    MU12_B_IRQHandler
    def_irq_handler    MU13_B_IRQHandler
    def_irq_handler    MU14_A_IRQHandler
    def_irq_handler    MU14_B_IRQHandler
    def_irq_handler    MU15_A_IRQHandler
    def_irq_handler    MU15_B_IRQHandler
    def_irq_handler    MU16_A_IRQHandler
    def_irq_handler    MU16_B_IRQHandler
    def_irq_handler    MU17_A_IRQHandler
    def_irq_handler    MU17_B_IRQHandler
    def_irq_handler    MU_E1_B_IRQHandler
    def_irq_handler    MU_E2_B_IRQHandler
    def_irq_handler    MU_E3_B_IRQHandler
    def_irq_handler    MU_E4_B_IRQHandler
    def_irq_handler    MSGINTR1_IRQHandler
    def_irq_handler    Reserved590_IRQHandler
    def_irq_handler    Reserved591_IRQHandler
    def_irq_handler    Reserved592_IRQHandler
    def_irq_handler    Reserved593_IRQHandler
    def_irq_handler    Reserved594_IRQHandler
    def_irq_handler    Reserved595_IRQHandler
    def_irq_handler    Reserved596_IRQHandler
    def_irq_handler    Reserved597_IRQHandler
    def_irq_handler    Reserved598_IRQHandler
    def_irq_handler    Reserved599_IRQHandler
    def_irq_handler    Reserved600_IRQHandler
    def_irq_handler    Reserved601_IRQHandler
    def_irq_handler    Reserved602_IRQHandler
    def_irq_handler    Reserved603_IRQHandler
    def_irq_handler    Reserved604_IRQHandler
    def_irq_handler    Reserved605_IRQHandler
    def_irq_handler    Reserved606_IRQHandler
    def_irq_handler    Reserved607_IRQHandler
    def_irq_handler    Reserved608_IRQHandler
    def_irq_handler    Reserved609_IRQHandler
    def_irq_handler    Reserved610_IRQHandler
    def_irq_handler    Reserved611_IRQHandler
    def_irq_handler    Reserved612_IRQHandler
    def_irq_handler    Reserved613_IRQHandler
    def_irq_handler    Reserved614_IRQHandler
    def_irq_handler    Reserved615_IRQHandler
    def_irq_handler    Reserved616_IRQHandler
    def_irq_handler    Reserved617_IRQHandler
    def_irq_handler    Reserved618_IRQHandler
    def_irq_handler    Reserved619_IRQHandler
    def_irq_handler    Reserved620_IRQHandler
    def_irq_handler    Reserved621_IRQHandler
    def_irq_handler    Reserved622_IRQHandler
    def_irq_handler    Reserved623_IRQHandler
    def_irq_handler    Reserved624_IRQHandler
    def_irq_handler    Reserved625_IRQHandler
    def_irq_handler    Reserved626_IRQHandler
    def_irq_handler    Reserved627_IRQHandler
    def_irq_handler    Reserved628_IRQHandler
    def_irq_handler    Reserved629_IRQHandler
    def_irq_handler    Reserved630_IRQHandler
    def_irq_handler    Reserved631_IRQHandler
    def_irq_handler    Reserved632_IRQHandler
    def_irq_handler    Reserved633_IRQHandler
    def_irq_handler    Reserved634_IRQHandler
    def_irq_handler    Reserved635_IRQHandler
    def_irq_handler    Reserved636_IRQHandler
    def_irq_handler    Reserved637_IRQHandler
    def_irq_handler    MSGINTR2_IRQHandler
    def_irq_handler    MSGINTR3_IRQHandler
    def_irq_handler    MSGINTR4_IRQHandler
    def_irq_handler    MSGINTR5_IRQHandler
    def_irq_handler    MSGINTR6_IRQHandler
    def_irq_handler    MSGINTR7_IRQHandler
    def_irq_handler    MSGINTR8_IRQHandler
    def_irq_handler    V2X_FH_APP1_IRQHandler
    def_irq_handler    V2X_FH_HSM2_IRQHandler
    def_irq_handler    S500_REQ1_IRQHandler
    def_irq_handler    S500_REQ2_IRQHandler
    def_irq_handler    S500_REQ3_IRQHandler
    def_irq_handler    S500_REQ4_IRQHandler
    def_irq_handler    S500_GLUE_IRQHandler
    def_irq_handler    GPC_SM_REQ_IRQHandler
    def_irq_handler    EDMA1_ERROR_DriverIRQHandler
    def_irq_handler    Reserved654_IRQHandler
    def_irq_handler    Reserved655_IRQHandler
    def_irq_handler    Reserved656_IRQHandler
    def_irq_handler    Reserved657_IRQHandler
    def_irq_handler    Reserved658_IRQHandler
    def_irq_handler    Reserved659_IRQHandler
    def_irq_handler    Reserved660_IRQHandler
    def_irq_handler    Reserved661_IRQHandler
    def_irq_handler    Reserved662_IRQHandler
    def_irq_handler    Reserved663_IRQHandler
    def_irq_handler    Reserved664_IRQHandler
    def_irq_handler    Reserved665_IRQHandler
    def_irq_handler    Reserved666_IRQHandler
    def_irq_handler    Reserved667_IRQHandler
    def_irq_handler    Reserved668_IRQHandler
    def_irq_handler    Reserved669_IRQHandler
    def_irq_handler    Reserved670_IRQHandler
    def_irq_handler    Reserved671_IRQHandler
    def_irq_handler    Reserved672_IRQHandler
    def_irq_handler    Reserved673_IRQHandler
    def_irq_handler    Reserved674_IRQHandler
    def_irq_handler    Reserved675_IRQHandler
    def_irq_handler    Reserved676_IRQHandler
    def_irq_handler    Reserved677_IRQHandler
    def_irq_handler    Reserved678_IRQHandler
    def_irq_handler    Reserved679_IRQHandler
    def_irq_handler    Reserved680_IRQHandler
    def_irq_handler    Reserved681_IRQHandler
    def_irq_handler    Reserved682_IRQHandler
    def_irq_handler    Reserved683_IRQHandler
    def_irq_handler    Reserved684_IRQHandler
    def_irq_handler    Reserved685_IRQHandler
    def_irq_handler    Reserved686_IRQHandler
    def_irq_handler    Reserved687_IRQHandler
    def_irq_handler    Reserved688_IRQHandler
    def_irq_handler    Reserved689_IRQHandler
    def_irq_handler    Reserved690_IRQHandler
    def_irq_handler    Reserved691_IRQHandler
    def_irq_handler    Reserved692_IRQHandler
    def_irq_handler    Reserved693_IRQHandler
    def_irq_handler    Reserved694_IRQHandler
    def_irq_handler    Reserved695_IRQHandler
    def_irq_handler    Reserved696_IRQHandler
    def_irq_handler    Reserved697_IRQHandler
    def_irq_handler    Reserved698_IRQHandler
    def_irq_handler    Reserved699_IRQHandler
    def_irq_handler    Reserved700_IRQHandler
    def_irq_handler    Reserved701_IRQHandler
    def_irq_handler    Reserved702_IRQHandler
    def_irq_handler    Reserved703_IRQHandler
    def_irq_handler    Reserved704_IRQHandler
    def_irq_handler    Reserved705_IRQHandler
    def_irq_handler    Reserved706_IRQHandler
    def_irq_handler    Reserved707_IRQHandler
    def_irq_handler    Reserved708_IRQHandler
    def_irq_handler    Reserved709_IRQHandler
    def_irq_handler    Reserved710_IRQHandler
    def_irq_handler    Reserved711_IRQHandler
    def_irq_handler    Reserved712_IRQHandler
    def_irq_handler    Reserved713_IRQHandler
    def_irq_handler    Reserved714_IRQHandler
    def_irq_handler    Reserved715_IRQHandler
    def_irq_handler    Reserved716_IRQHandler
    def_irq_handler    Reserved717_IRQHandler
    def_irq_handler    Reserved718_IRQHandler
    def_irq_handler    Reserved719_IRQHandler
    def_irq_handler    Reserved720_IRQHandler
    def_irq_handler    Reserved721_IRQHandler
    def_irq_handler    Reserved722_IRQHandler
    def_irq_handler    Reserved723_IRQHandler
    def_irq_handler    Reserved724_IRQHandler
    def_irq_handler    Reserved725_IRQHandler
    def_irq_handler    Reserved726_IRQHandler
    def_irq_handler    Reserved727_IRQHandler
    def_irq_handler    Reserved728_IRQHandler
    def_irq_handler    Reserved729_IRQHandler
    def_irq_handler    Reserved730_IRQHandler
    def_irq_handler    Reserved731_IRQHandler
    def_irq_handler    Reserved732_IRQHandler
    def_irq_handler    Reserved733_IRQHandler
    def_irq_handler    Reserved734_IRQHandler
    def_irq_handler    Reserved735_IRQHandler
    def_irq_handler    Reserved736_IRQHandler
    def_irq_handler    Reserved737_IRQHandler
    def_irq_handler    Reserved738_IRQHandler
    def_irq_handler    Reserved739_IRQHandler
    def_irq_handler    Reserved740_IRQHandler
    def_irq_handler    Reserved741_IRQHandler
    def_irq_handler    Reserved742_IRQHandler
    def_irq_handler    Reserved743_IRQHandler
    def_irq_handler    Reserved744_IRQHandler
    def_irq_handler    Reserved745_IRQHandler
    def_irq_handler    Reserved746_IRQHandler
    def_irq_handler    Reserved747_IRQHandler
    def_irq_handler    Reserved748_IRQHandler
    def_irq_handler    Reserved749_IRQHandler
    def_irq_handler    Reserved750_IRQHandler
    def_irq_handler    Reserved751_IRQHandler
    def_irq_handler    Reserved752_IRQHandler
    def_irq_handler    Reserved753_IRQHandler
    def_irq_handler    Reserved754_IRQHandler
    def_irq_handler    Reserved755_IRQHandler
    def_irq_handler    Reserved756_IRQHandler
    def_irq_handler    Reserved757_IRQHandler
    def_irq_handler    Reserved758_IRQHandler
    def_irq_handler    Reserved759_IRQHandler
    def_irq_handler    Reserved760_IRQHandler
    def_irq_handler    Reserved761_IRQHandler
    def_irq_handler    Reserved762_IRQHandler
    def_irq_handler    Reserved763_IRQHandler
    def_irq_handler    Reserved764_IRQHandler
    def_irq_handler    Reserved765_IRQHandler
    def_irq_handler    Reserved766_IRQHandler
    def_irq_handler    Reserved767_IRQHandler
    def_irq_handler    Reserved768_IRQHandler
    def_irq_handler    Reserved769_IRQHandler
    def_irq_handler    Reserved770_IRQHandler
    def_irq_handler    Reserved771_IRQHandler
    def_irq_handler    Reserved772_IRQHandler
    def_irq_handler    Reserved773_IRQHandler
    def_irq_handler    Reserved774_IRQHandler
    def_irq_handler    Reserved775_IRQHandler
    def_irq_handler    Reserved776_IRQHandler
    def_irq_handler    Reserved777_IRQHandler
    def_irq_handler    Reserved778_IRQHandler
    def_irq_handler    Reserved779_IRQHandler
    def_irq_handler    Reserved780_IRQHandler
    def_irq_handler    Reserved781_IRQHandler
    def_irq_handler    Reserved782_IRQHandler
    def_irq_handler    Reserved783_IRQHandler
    def_irq_handler    Reserved784_IRQHandler
    def_irq_handler    Reserved785_IRQHandler
    def_irq_handler    Reserved786_IRQHandler
    def_irq_handler    Reserved787_IRQHandler
    def_irq_handler    Reserved788_IRQHandler
    def_irq_handler    Reserved789_IRQHandler
    def_irq_handler    Reserved790_IRQHandler
    def_irq_handler    Reserved791_IRQHandler
    def_irq_handler    Reserved792_IRQHandler
    def_irq_handler    Reserved793_IRQHandler
    def_irq_handler    Reserved794_IRQHandler
    def_irq_handler    Reserved795_IRQHandler
    def_irq_handler    Reserved796_IRQHandler
    def_irq_handler    Reserved797_IRQHandler
    def_irq_handler    Reserved798_IRQHandler
    def_irq_handler    Reserved799_IRQHandler
    def_irq_handler    Reserved800_IRQHandler
    def_irq_handler    Reserved801_IRQHandler
    def_irq_handler    Reserved802_IRQHandler
    def_irq_handler    Reserved803_IRQHandler
    def_irq_handler    Reserved804_IRQHandler
    def_irq_handler    Reserved805_IRQHandler
    def_irq_handler    Reserved806_IRQHandler
    def_irq_handler    Reserved807_IRQHandler
    def_irq_handler    Reserved808_IRQHandler
    def_irq_handler    Reserved809_IRQHandler
    def_irq_handler    Reserved810_IRQHandler
    def_irq_handler    Reserved811_IRQHandler
    def_irq_handler    Reserved812_IRQHandler
    def_irq_handler    Reserved813_IRQHandler
    def_irq_handler    Reserved814_IRQHandler
    def_irq_handler    Reserved815_IRQHandler
    def_irq_handler    Reserved816_IRQHandler
    def_irq_handler    Reserved817_IRQHandler
    def_irq_handler    Reserved818_IRQHandler
    def_irq_handler    Reserved819_IRQHandler
    def_irq_handler    Reserved820_IRQHandler
    def_irq_handler    Reserved821_IRQHandler
    def_irq_handler    Reserved822_IRQHandler
    def_irq_handler    Reserved823_IRQHandler
    def_irq_handler    Reserved824_IRQHandler
    def_irq_handler    Reserved825_IRQHandler
    def_irq_handler    Reserved826_IRQHandler
    def_irq_handler    Reserved827_IRQHandler
    def_irq_handler    Reserved828_IRQHandler
    def_irq_handler    Reserved829_IRQHandler
    def_irq_handler    Reserved830_IRQHandler
    def_irq_handler    TMPSNS_THR1_IRQHandler
    def_irq_handler    TMPSNS_THR2_IRQHandler
    def_irq_handler    Reserved833_IRQHandler
    def_irq_handler    Reserved834_IRQHandler
    def_irq_handler    Reserved835_IRQHandler
    def_irq_handler    Reserved836_IRQHandler
    def_irq_handler    CM33_0_SYSRESETREQ_IRQHandler
    def_irq_handler    CM33_0_LOCKUP_IRQHandler
    def_irq_handler    CM7_0_SYSRESETREQ_IRQHandler
    def_irq_handler    CM7_0_LOCKUP_IRQHandler
    def_irq_handler    CM33_1_SYSRESETREQ_IRQHandler
    def_irq_handler    CM33_1_LOCKUP_IRQHandler
    def_irq_handler    CM7_1_SYSRESETREQ_IRQHandler
    def_irq_handler    CM7_1_LOCKUP_IRQHandler
    def_irq_handler    Reserved845_IRQHandler
    def_irq_handler    Reserved846_IRQHandler
    def_irq_handler    Reserved847_IRQHandler
    def_irq_handler    Reserved848_IRQHandler
    def_irq_handler    Reserved849_IRQHandler
    def_irq_handler    Reserved850_IRQHandler
    def_irq_handler    Reserved851_IRQHandler
    def_irq_handler    Reserved852_IRQHandler
    def_irq_handler    Reserved853_IRQHandler
    def_irq_handler    Reserved854_IRQHandler
    def_irq_handler    Reserved855_IRQHandler
    def_irq_handler    Reserved856_IRQHandler
    def_irq_handler    Reserved857_IRQHandler
    def_irq_handler    Reserved858_IRQHandler
    def_irq_handler    Reserved859_IRQHandler
    def_irq_handler    Reserved860_IRQHandler
    def_irq_handler    Reserved861_IRQHandler
    def_irq_handler    Reserved862_IRQHandler
    def_irq_handler    Reserved863_IRQHandler
    def_irq_handler    Reserved864_IRQHandler
    def_irq_handler    Reserved865_IRQHandler
    def_irq_handler    Reserved866_IRQHandler
    def_irq_handler    Reserved867_IRQHandler
    def_irq_handler    Reserved868_IRQHandler
    def_irq_handler    Reserved869_IRQHandler
    def_irq_handler    Reserved870_IRQHandler
    def_irq_handler    Reserved871_IRQHandler
    def_irq_handler    Reserved872_IRQHandler
    def_irq_handler    Reserved873_IRQHandler
    def_irq_handler    Reserved874_IRQHandler
    def_irq_handler    Reserved875_IRQHandler
    def_irq_handler    Reserved876_IRQHandler
    def_irq_handler    Reserved877_IRQHandler
    def_irq_handler    Reserved878_IRQHandler
    def_irq_handler    Reserved879_IRQHandler
    def_irq_handler    Reserved880_IRQHandler
    def_irq_handler    Reserved881_IRQHandler
    def_irq_handler    Reserved882_IRQHandler
    def_irq_handler    Reserved883_IRQHandler
    def_irq_handler    Reserved884_IRQHandler
    def_irq_handler    Reserved885_IRQHandler
    def_irq_handler    Reserved886_IRQHandler
    def_irq_handler    Reserved887_IRQHandler
    def_irq_handler    Reserved888_IRQHandler
    def_irq_handler    Reserved889_IRQHandler
    def_irq_handler    Reserved890_IRQHandler
    def_irq_handler    Reserved891_IRQHandler
    def_irq_handler    Reserved892_IRQHandler
    def_irq_handler    Reserved893_IRQHandler
    def_irq_handler    Reserved894_IRQHandler
    def_irq_handler    Reserved895_IRQHandler
    def_irq_handler    Reserved896_IRQHandler
    def_irq_handler    Reserved897_IRQHandler
    def_irq_handler    Reserved898_IRQHandler
    def_irq_handler    Reserved899_IRQHandler
    def_irq_handler    Reserved900_IRQHandler
    def_irq_handler    Reserved901_IRQHandler
    def_irq_handler    Reserved902_IRQHandler
    def_irq_handler    Reserved903_IRQHandler
    def_irq_handler    Reserved904_IRQHandler
    def_irq_handler    Reserved905_IRQHandler
    def_irq_handler    Reserved906_IRQHandler
    def_irq_handler    Reserved907_IRQHandler
    def_irq_handler    Reserved908_IRQHandler
    def_irq_handler    Reserved909_IRQHandler
    def_irq_handler    Reserved910_IRQHandler
    def_irq_handler    Reserved911_IRQHandler
    def_irq_handler    Reserved912_IRQHandler
    def_irq_handler    Reserved913_IRQHandler
    def_irq_handler    Reserved914_IRQHandler
    def_irq_handler    Reserved915_IRQHandler
    def_irq_handler    Reserved916_IRQHandler
    def_irq_handler    Reserved917_IRQHandler
    def_irq_handler    Reserved918_IRQHandler
    def_irq_handler    Reserved919_IRQHandler
    def_irq_handler    Reserved920_IRQHandler
    def_irq_handler    Reserved921_IRQHandler
    def_irq_handler    Reserved922_IRQHandler
    def_irq_handler    Reserved923_IRQHandler
    def_irq_handler    Reserved924_IRQHandler
    def_irq_handler    Reserved925_IRQHandler
    def_irq_handler    Reserved926_IRQHandler
    def_irq_handler    Reserved927_IRQHandler
    def_irq_handler    Reserved928_IRQHandler
    def_irq_handler    Reserved929_IRQHandler
    def_irq_handler    Reserved930_IRQHandler
    def_irq_handler    Reserved931_IRQHandler
    def_irq_handler    Reserved932_IRQHandler
    def_irq_handler    Reserved933_IRQHandler
    def_irq_handler    Reserved934_IRQHandler
    def_irq_handler    Reserved935_IRQHandler
    def_irq_handler    Reserved936_IRQHandler
    def_irq_handler    Reserved937_IRQHandler
    def_irq_handler    Reserved938_IRQHandler
    def_irq_handler    Reserved939_IRQHandler
    def_irq_handler    Reserved940_IRQHandler
    def_irq_handler    Reserved941_IRQHandler
    def_irq_handler    Reserved942_IRQHandler
    def_irq_handler    Reserved943_IRQHandler
    def_irq_handler    Reserved944_IRQHandler
    def_irq_handler    Reserved945_IRQHandler
    def_irq_handler    Reserved946_IRQHandler
    def_irq_handler    Reserved947_IRQHandler
    def_irq_handler    Reserved948_IRQHandler
    def_irq_handler    Reserved949_IRQHandler
    def_irq_handler    Reserved950_IRQHandler
    def_irq_handler    Reserved951_IRQHandler
    def_irq_handler    Reserved952_IRQHandler
    def_irq_handler    Reserved953_IRQHandler
    def_irq_handler    Reserved954_IRQHandler
    def_irq_handler    Reserved955_IRQHandler
    def_irq_handler    Reserved956_IRQHandler
    def_irq_handler    Reserved957_IRQHandler
    def_irq_handler    Reserved958_IRQHandler
    def_irq_handler    Reserved959_IRQHandler
    def_irq_handler    Reserved960_IRQHandler
    def_irq_handler    DCIF_CPU_DOMAIN0_IRQHandler
    def_irq_handler    DCIF_CPU_DOMAIN1_IRQHandler
    def_irq_handler    DCIF_CPU_DOMAIN2_IRQHandler
    def_irq_handler    Reserved964_IRQHandler
    def_irq_handler    Reserved965_IRQHandler
    def_irq_handler    PXP_0_IRQHandler
    def_irq_handler    PXP_1_IRQHandler
    def_irq_handler    Reserved968_IRQHandler
    def_irq_handler    Reserved969_IRQHandler
    def_irq_handler    Reserved970_IRQHandler
    def_irq_handler    Reserved971_IRQHandler
    def_irq_handler    Reserved972_IRQHandler
    def_irq_handler    Reserved973_IRQHandler
    def_irq_handler    Reserved974_IRQHandler
    def_irq_handler    Reserved975_IRQHandler
    def_irq_handler    Reserved976_IRQHandler
    def_irq_handler    Reserved977_IRQHandler
    def_irq_handler    Reserved978_IRQHandler
    def_irq_handler    Reserved979_IRQHandler
    def_irq_handler    Reserved980_IRQHandler
    def_irq_handler    Reserved981_IRQHandler
    def_irq_handler    Reserved982_IRQHandler
    def_irq_handler    Reserved983_IRQHandler
    def_irq_handler    Reserved984_IRQHandler
    def_irq_handler    Reserved985_IRQHandler
    def_irq_handler    Reserved986_IRQHandler
    def_irq_handler    Reserved987_IRQHandler
    def_irq_handler    Reserved988_IRQHandler
    def_irq_handler    Reserved989_IRQHandler
    def_irq_handler    Reserved990_IRQHandler
    def_irq_handler    Reserved991_IRQHandler
    def_irq_handler    Reserved992_IRQHandler
    def_irq_handler    Reserved993_IRQHandler
    def_irq_handler    Reserved994_IRQHandler
    def_irq_handler    Reserved995_IRQHandler
    def_irq_handler    Reserved996_IRQHandler
    def_irq_handler    Reserved997_IRQHandler
    def_irq_handler    Reserved998_IRQHandler
    def_irq_handler    Reserved999_IRQHandler
    def_irq_handler    Reserved1000_IRQHandler
    def_irq_handler    Reserved1001_IRQHandler
    def_irq_handler    Reserved1002_IRQHandler
    def_irq_handler    Reserved1003_IRQHandler
    def_irq_handler    Reserved1004_IRQHandler
    def_irq_handler    Reserved1005_IRQHandler
    def_irq_handler    Reserved1006_IRQHandler
    def_irq_handler    Reserved1007_IRQHandler
    def_irq_handler    Reserved1008_IRQHandler
    def_irq_handler    Reserved1009_IRQHandler
    def_irq_handler    Reserved1010_IRQHandler
    def_irq_handler    Reserved1011_IRQHandler
    def_irq_handler    Reserved1012_IRQHandler
    def_irq_handler    Reserved1013_IRQHandler
    def_irq_handler    Reserved1014_IRQHandler
    def_irq_handler    Reserved1015_IRQHandler
    def_irq_handler    Reserved1016_IRQHandler
    def_irq_handler    Reserved1017_IRQHandler
    def_irq_handler    Reserved1018_IRQHandler
    def_irq_handler    Reserved1019_IRQHandler
    def_irq_handler    Reserved1020_IRQHandler
    def_irq_handler    Reserved1021_IRQHandler
    def_irq_handler    XSPI1_DriverIRQHandler
    def_irq_handler    Reserved1023_IRQHandler
    def_irq_handler    Reserved1024_IRQHandler
    def_irq_handler    Reserved1025_IRQHandler
    def_irq_handler    Reserved1026_IRQHandler
    def_irq_handler    XSPI2_DriverIRQHandler
    def_irq_handler    Reserved1028_IRQHandler
    def_irq_handler    Reserved1029_IRQHandler
    def_irq_handler    Reserved1030_IRQHandler
    def_irq_handler    Reserved1031_IRQHandler
    def_irq_handler    Reserved1032_IRQHandler
    def_irq_handler    Reserved1033_IRQHandler
    def_irq_handler    Reserved1034_IRQHandler
    def_irq_handler    Reserved1035_IRQHandler
    def_irq_handler    Reserved1036_IRQHandler
    def_irq_handler    Reserved1037_IRQHandler
    def_irq_handler    Reserved1038_IRQHandler
    def_irq_handler    Reserved1039_IRQHandler
    def_irq_handler    Reserved1040_IRQHandler
    def_irq_handler    Reserved1041_IRQHandler
    def_irq_handler    Reserved1042_IRQHandler
    def_irq_handler    Reserved1043_IRQHandler
    def_irq_handler    Reserved1044_IRQHandler
    def_irq_handler    Reserved1045_IRQHandler
    def_irq_handler    Reserved1046_IRQHandler
    def_irq_handler    Reserved1047_IRQHandler
    def_irq_handler    Reserved1048_IRQHandler
    def_irq_handler    Reserved1049_IRQHandler
    def_irq_handler    Reserved1050_IRQHandler
    def_irq_handler    Reserved1051_IRQHandler
    def_irq_handler    Reserved1052_IRQHandler
    def_irq_handler    Reserved1053_IRQHandler
    def_irq_handler    Reserved1054_IRQHandler
    def_irq_handler    Reserved1055_IRQHandler
    def_irq_handler    Reserved1056_IRQHandler
    def_irq_handler    Reserved1057_IRQHandler
    def_irq_handler    Reserved1058_IRQHandler
    def_irq_handler    Reserved1059_IRQHandler
    def_irq_handler    Reserved1060_IRQHandler
    def_irq_handler    Reserved1061_IRQHandler
    def_irq_handler    Reserved1062_IRQHandler
    def_irq_handler    Reserved1063_IRQHandler
    def_irq_handler    Reserved1064_IRQHandler
    def_irq_handler    Reserved1065_IRQHandler
    def_irq_handler    Reserved1066_IRQHandler
    def_irq_handler    Reserved1067_IRQHandler
    def_irq_handler    Reserved1068_IRQHandler
    def_irq_handler    Reserved1069_IRQHandler
    def_irq_handler    Reserved1070_IRQHandler
    def_irq_handler    Reserved1071_IRQHandler
    def_irq_handler    Reserved1072_IRQHandler
    def_irq_handler    Reserved1073_IRQHandler
    def_irq_handler    Reserved1074_IRQHandler
    def_irq_handler    Reserved1075_IRQHandler
    def_irq_handler    Reserved1076_IRQHandler
    def_irq_handler    Reserved1077_IRQHandler
    def_irq_handler    Reserved1078_IRQHandler
    def_irq_handler    Reserved1079_IRQHandler
    def_irq_handler    Reserved1080_IRQHandler
    def_irq_handler    Reserved1081_IRQHandler
    def_irq_handler    Reserved1082_IRQHandler
    def_irq_handler    Reserved1083_IRQHandler
    def_irq_handler    Reserved1084_IRQHandler
    def_irq_handler    Reserved1085_IRQHandler

    .end
