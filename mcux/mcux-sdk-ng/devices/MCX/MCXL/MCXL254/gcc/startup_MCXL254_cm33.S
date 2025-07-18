/* ------------------------------------------------------------------------- */
/*  @file:    startup_MCXL254_cm33.s                                         */
/*  @purpose: CMSIS Cortex-M33 Core Device Startup File                      */
/*            MCXL254_cm33                                                   */
/*  @version: 1.0                                                            */
/*  @date:    2023-1-9                                                       */
/*  @build:   b250422                                                        */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Copyright 1997-2016 Freescale Semiconductor, Inc.                         */
/* Copyright 2016-2025 NXP                                                   */
/* SPDX-License-Identifier: BSD-3-Clause                                     */
/*****************************************************************************/
/* Version: GCC for ARM Embedded Processors                                  */
/*****************************************************************************/
    .syntax unified
    .arch armv8-m.main

    .section .isr_vector, "a"
    .align 2
    .globl __Vectors
__Vectors:
    .long   __StackTop                                      /* Top of Stack */
    .long   Reset_Handler                                   /* Reset Handler */
    .long   NMI_Handler                                     /* NMI Handler*/
    .long   HardFault_Handler                               /* Hard Fault Handler*/
    .long   MemManage_Handler                               /* MPU Fault Handler*/
    .long   BusFault_Handler                                /* Bus Fault Handler*/
    .long   UsageFault_Handler                              /* Usage Fault Handler*/
    .long   SecureFault_Handler                             /* Secure Fault Handler*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   SVC_Handler                                     /* SVCall Handler*/
    .long   DebugMon_Handler                                /* Debug Monitor Handler*/
    .long   0                                               /* Reserved*/
    .long   PendSV_Handler                                  /* PendSV Handler*/
    .long   SysTick_Handler                                 /* SysTick Handler*/

                                                            /* External Interrupts*/
    .long   Reserved16_IRQHandler                           /* OR IRQ1 to IRQ79*/
    .long   CMC_IRQHandler                                  /* Core Mode Controller interrupt*/
    .long   DMA0_CH0_IRQHandler                             /* DMA3_0_CH0 error or transfer complete*/
    .long   DMA0_CH1_IRQHandler                             /* DMA3_0_CH1 error or transfer complete*/
    .long   DMA0_CH2_IRQHandler                             /* DMA3_0_CH2 error or transfer complete*/
    .long   DMA0_CH3_IRQHandler                             /* DMA3_0_CH3 error or transfer complete*/
    .long   Reserved22_IRQHandler                           /* xxx Interrupt 22*/
    .long   Reserved23_IRQHandler                           /* xxx Interrupt 23*/
    .long   Reserved24_IRQHandler                           /* xxx Interrupt 24*/
    .long   Reserved25_IRQHandler                           /* xxx Interrupt 25*/
    .long   ERM0_IRQHandler                                 /* ERM Single Bit error interrupt*/
    .long   Reserved27_IRQHandler                           /* xxx Interrupt 27*/
    .long   FMU0_IRQHandler                                 /* Flash Management Unit interrupt*/
    .long   GLIKEY0_IRQHandler                              /* GLIKEY Interrupt */
    .long   MBC0_IRQHandler                                 /* MBC secure violation interrupt*/
    .long   SCG0_IRQHandler                                 /* System Clock Generator interrupt*/
    .long   Reserved32_IRQHandler                           /* xxx Interrupt 32*/
    .long   Reserved33_IRQHandler                           /* xxx Interrupt 33*/
    .long   WUU0_IRQHandler                                 /* Wake Up Unit interrupt*/
    .long   Reserved35_IRQHandler                           /* xxx Interrupt 35*/
    .long   Reserved36_IRQHandler                           /* xxx Interrupt 36*/
    .long   Reserved37_IRQHandler                           /* xxx Interrupt 37*/
    .long   Reserved38_IRQHandler                           /* xxx Interrupt 38*/
    .long   Reserved39_IRQHandler                           /* xxx Interrupt 39*/
    .long   Reserved40_IRQHandler                           /* xxx Interrupt 40*/
    .long   Reserved41_IRQHandler                           /* xxx Interrupt 41*/
    .long   LPI2C0_IRQHandler                               /* Low-Power Inter Integrated Circuit interrupt*/
    .long   LPI2C1_IRQHandler                               /* Low-Power Inter Integrated Circuit interrupt*/
    .long   LPSPI0_IRQHandler                               /* Low-Power Serial Peripheral Interface interrupt*/
    .long   LPSPI1_IRQHandler                               /* Low-Power Serial Peripheral Interface interrupt*/
    .long   Reserved46_IRQHandler                           /* xxx Interrupt 46*/
    .long   LPUART0_IRQHandler                              /* Low-Power Universal Asynchronous Receive/Transmit interrupt*/
    .long   LPUART1_IRQHandler                              /* Low-Power Universal Asynchronous Receive/Transmit interrupt*/
    .long   Reserved49_IRQHandler                           /* xxx Interrupt 49*/
    .long   Reserved50_IRQHandler                           /* xxx Interrupt 50*/
    .long   Reserved51_IRQHandler                           /* xxx Interrupt 51*/
    .long   Reserved52_IRQHandler                           /* xxx Interrupt 52*/
    .long   Reserved53_IRQHandler                           /* xxx Interrupt 53*/
    .long   CDOG0_IRQHandler                                /* Code Watchdog Timer 0 interrupt*/
    .long   CTIMER0_IRQHandler                              /* Standard counter/timer 0 interrupt*/
    .long   CTIMER1_IRQHandler                              /* Standard counter/timer 1 interrupt*/
    .long   CTIMER2_IRQHandler                              /* Standard counter/timer 2 interrupt*/
    .long   Reserved58_IRQHandler                           /* xxx Interrupt 58*/
    .long   Reserved59_IRQHandler                           /* xxx Interrupt 59*/
    .long   Reserved60_IRQHandler                           /* xxx Interrupt 60*/
    .long   Reserved61_IRQHandler                           /* xxx Interrupt 61*/
    .long   Reserved62_IRQHandler                           /* xxx Interrupt 62*/
    .long   Reserved63_IRQHandler                           /* xxx Interrupt 63*/
    .long   Reserved64_IRQHandler                           /* xxx Interrupt 64*/
    .long   Reserved65_IRQHandler                           /* xxx Interrupt 65*/
    .long   Reserved66_IRQHandler                           /* xxx Interrupt 66*/
    .long   Reserved67_IRQHandler                           /* xxx Interrupt 67*/
    .long   Reserved68_IRQHandler                           /* xxx Interrupt 68*/
    .long   Reserved69_IRQHandler                           /* xxx Interrupt 69*/
    .long   FREQME0_IRQHandler                              /* Frequency Measurement interrupt*/
    .long   Reserved71_IRQHandler                           /* xxx Interrupt 71*/
    .long   Reserved72_IRQHandler                           /* xxx Interrupt 72*/
    .long   OS_EVENT_IRQHandler                             /* OS event timer interrupt*/
    .long   Reserved74_IRQHandler                           /* xxx Interrupt 74*/
    .long   UTICK0_IRQHandler                               /* Micro-Tick Timer interrupt*/
    .long   WWDT0_IRQHandler                                /* Windowed Watchdog Timer 0 interrupt*/
    .long   Reserved77_IRQHandler                           /* xxx Interrupt 77*/
    .long   ADC0_IRQHandler                                 /* Analog-to-Digital Converter interrupt*/
    .long   Reserved79_IRQHandler                           /* xxx Interrupt 79*/
    .long   CMP0_IRQHandler                                 /* Comparator interrupt*/
    .long   Reserved81_IRQHandler                           /* xxx Interrupt 81*/
    .long   Reserved82_IRQHandler                           /* xxx Interrupt 82*/
    .long   Reserved83_IRQHandler                           /* xxx Interrupt 83*/
    .long   Reserved84_IRQHandler                           /* xxx Interrupt 84*/
    .long   Reserved85_IRQHandler                           /* xxx Interrupt 85*/
    .long   Reserved86_IRQHandler                           /* xxx Interrupt 86*/
    .long   GPIO10_IRQHandler                               /* General Purpose Input/Output 1 interrupt 0*/
    .long   GPIO11_IRQHandler                               /* General Purpose Input/Output 1 interrupt 1*/
    .long   GPIO20_IRQHandler                               /* General Purpose Input/Output 2 interrupt 0*/
    .long   GPIO21_IRQHandler                               /* General Purpose Input/Output 2 interrupt 1*/
    .long   GPIO30_IRQHandler                               /* General Purpose Input/Output 3 interrupt 0*/
    .long   GPIO31_IRQHandler                               /* General Purpose Input/Output 3 interrupt 1*/
    .long   Reserved93_IRQHandler                           /* xxx Interrupt 93*/
    .long   Reserved94_IRQHandler                           /* xxx Interrupt 94*/
    .long   Reserved95_IRQHandler                           /* xxx Interrupt 95*/
    .long   MU_A_TX_IRQHandler                              /* Ored tx interrupt to MUA*/
    .long   MU_A_RX_IRQHandler                              /* Ored rx interrupt to MUA*/
    .long   MU_A_INT_IRQHandler                             /* ORed general purpose interrupt request to MUA*/
    .long   CDOG1_IRQHandler                                /* Code Watchdog Timer 1 interrupt*/
    .long   Reserved100_IRQHandler                          /* xxx Interrupt 100*/
    .long   Reserved101_IRQHandler                          /* xxx Interrupt 101*/
    .long   Reserved102_IRQHandler                          /* xxx Interrupt 102*/
    .long   Reserved103_IRQHandler                          /* xxx Interrupt 103*/
    .long   Reserved104_IRQHandler                          /* xxx Interrupt 104*/
    .long   Reserved105_IRQHandler                          /* xxx Interrupt 105*/
    .long   Reserved106_IRQHandler                          /* xxx Interrupt 106*/
    .long   Reserved107_IRQHandler                          /* xxx Interrupt 107*/
    .long   Reserved108_IRQHandler                          /* xxx Interrupt 108*/
    .long   Reserved109_IRQHandler                          /* xxx Interrupt 109*/
    .long   Reserved110_IRQHandler                          /* xxx Interrupt 110*/
    .long   Reserved111_IRQHandler                          /* xxx Interrupt 111*/
    .long   DMA1_CH0_IRQHandler                             /* DMA3_1_CH0 error or transfer complete*/
    .long   DMA1_CH1_IRQHandler                             /* DMA3_1_CH1 error or transfer complete*/
    .long   DMA1_CH2_IRQHandler                             /* DMA3_1_CH2 error or transfer complete*/
    .long   DMA1_CH3_IRQHandler                             /* DMA3_1_CH3 error or transfer complete*/
    .long   Reserved116_IRQHandler                          /* xxx Interrupt 116*/
    .long   Reserved117_IRQHandler                          /* xxx Interrupt 117*/
    .long   Reserved118_IRQHandler                          /* xxx Interrupt 118*/
    .long   Reserved119_IRQHandler                          /* xxx Interrupt 119*/
    .long   Reserved120_IRQHandler                          /* xxx Interrupt 120*/
    .long   Reserved121_IRQHandler                          /* xxx Interrupt 121*/
    .long   Reserved122_IRQHandler                          /* xxx Interrupt 122*/
    .long   Reserved123_IRQHandler                          /* xxx Interrupt 123*/
    .long   Reserved124_IRQHandler                          /* xxx Interrupt 124*/
    .long   Reserved125_IRQHandler                          /* xxx Interrupt 125*/
    .long   PKC_IRQHandler                                  /* PKC interrupt*/
    .long   SGI_IRQHandler                                  /* SGI interrupt*/
    .long   TRNG_IRQHandler                                 /* TRNG interrupt*/
    .long   ERR_SGI_UDF_TRNG_PKC_IRQHandler                 /* ORed Error Interrupt from SGI, UDF,TRNG and PKC*/
    .long   HYPERVISOR_IRQHandler                           /* Hypervisor interrupt*/
    .long   Reserved131_IRQHandler                          /* xxx Interrupt 131*/
    .long   Reserved132_IRQHandler                          /* xxx Interrupt 132*/
    .long   Reserved133_IRQHandler                          /* xxx Interrupt 133*/
    .long   Reserved134_IRQHandler                          /* xxx Interrupt 134*/
    .long   Reserved135_IRQHandler                          /* xxx Interrupt 135*/
    .long   Reserved136_IRQHandler                          /* xxx Interrupt 136*/
    .long   Reserved137_IRQHandler                          /* xxx Interrupt 137*/
    .long   Reserved138_IRQHandler                          /* xxx Interrupt 138*/
    .long   Reserved139_IRQHandler                          /* xxx Interrupt 139*/
    .long   Reserved140_IRQHandler                          /* xxx Interrupt 140*/
    .long   Reserved141_IRQHandler                          /* xxx Interrupt 141*/
    .long   Reserved142_IRQHandler                          /* xxx Interrupt 142*/
    .long   Reserved143_IRQHandler                          /* xxx Interrupt 143*/
    .long   LPI2C0_AON_IRQHandler                           /* Low-Power Inter Integrated Circuit interrupt*/
    .long   Reserved145_IRQHandler                          /* xxx Interrupt 145*/
    .long   LPUART0_AON_IRQHandler                          /* Low-Power Universal Asynchronous Receive/Transmit interrupt*/
    .long   Reserved147_IRQHandler                          /* xxx Interrupt 147*/
    .long   GPIO00_AON_IRQHandler                           /* General Purpose Input/Output interrupt 0*/
    .long   GPIO01_AON_IRQHandler                           /* General Purpose Input/Output interrupt 1*/
    .long   Reserved150_IRQHandler                          /* xxx Interrupt 150*/
    .long   Reserved151_IRQHandler                          /* xxx Interrupt 151*/
    .long   Reserved152_IRQHandler                          /* xxx Interrupt 152*/
    .long   Reserved153_IRQHandler                          /* xxx Interrupt 153*/
    .long   Reserved154_IRQHandler                          /* xxx Interrupt 154*/
    .long   LPCMP_IRQHandler                                /* Comparator*/
    .long   RTC_ALARM0_IRQHandler                           /* RTC alarm 0*/
    .long   RTC_ALARM1_IRQHandler                           /* RTC alarm 1*/
    .long   RTC_ALARM2_IRQHandler                           /* RTC alarm 2*/
    .long   RTC_WDT_IRQHandler                              /* RTC watchdog*/
    .long   RTC_XTAL_IRQHandler                             /* RTC XTAL Fail*/
    .long   Reserved161_IRQHandler                          /* xxx Interrupt 161*/
    .long   Reserved162_IRQHandler                          /* xxx Interrupt 162*/
    .long   Reserved163_IRQHandler                          /* xxx Interrupt 163*/
    .long   KPP_IRQHandler                                  /* Keypad Interrupt*/
    .long   LPADC_AON_IRQHandler                            /* ADC Summary Interrupt*/
    .long   Reserved166_IRQHandler                          /* xxx Interrupt 166*/
    .long   TMR0_AON_IRQHandler                             /* ORed QTMR Interrupts*/
    .long   TMR1_AON_IRQHandler                             /* ORed QTMR Interrupts*/
    .long   Reserved169_IRQHandler                          /* xxx Interrupt 169*/
    .long   LCSENSE_IRQHandler                              /* LCSense Fault/Tamper Interrupt*/
    .long   LPTMR_AON_IRQHandler                            /* Low Power Timer 0 interrupt*/
    .long   Reserved172_IRQHandler                          /* xxx Interrupt 172*/
    .long   CMP0_AON_IRQHandler                             /* Comparator interrupt*/
    .long   ADVC_IRQHandler                                 /* ADVC_2.0 Controller Interrupt*/
    .long   Reserved175_IRQHandler                          /* xxx Interrupt 175*/
    .long   SGLCD_FRAME_AON_IRQHandler                      /* Frame Update Interrupt*/
    .long   SGLCD_FFAULT_AON_IRQHandler                     /* Fault Detect Interrupt*/

    .size   __Vectors, . - __Vectors

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
    ldr     r1, =__Vectors
    str     r1, [r0]
    ldr     r2, [r1]
    msr     msp, r2
    ldr     r0, =__StackLimit
    msr     msplim, r0
#ifndef __NO_SYSTEM_INIT
    ldr   r0,=SystemInit
    blx   r0
#endif
/*     Loop to copy data from read only memory to RAM. The ranges
 *      of copy from/to are specified by following symbols evaluated in
 *      linker script.
 *      __etext: End of code section, i.e., begin of data sections to copy from.
 *      __data_start__/__data_end__: RAM address range that data should be
 *      copied to. Both must be aligned to 4 bytes boundary.  */

    ldr    r1, =__etext
    ldr    r2, =__data_start__
    ldr    r3, =__data_end__

#if 1
/* Here are two copies of loop implemenations. First one favors code size
 * and the second one favors performance. Default uses the first one.
 * Change to "#if 0" to use the second one */
.LC0:
    cmp     r2, r3
    ittt    lt
    ldrlt   r0, [r1], #4
    strlt   r0, [r2], #4
    blt    .LC0
#else
    subs    r3, r2
    ble    .LC1
.LC0:
    subs    r3, #4
    ldr    r0, [r1, r3]
    str    r0, [r2, r3]
    bgt    .LC0
.LC1:
#endif

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
.LC2:
    cmp     r1, r2
    itt    lt
    strlt   r0, [r1], #4
    blt    .LC2
#endif /* __STARTUP_CLEAR_BSS */

/* Add stack / heap initializaiton */
    movs    r0, 0
    ldr     r1, =__HeapBase
    ldr     r2, =__HeapLimit
.LC3:
    cmp     r1, r2
    itt     lt
    strlt   r0, [r1], #4
    blt     .LC3

    ldr     r1, =__StackLimit
    ldr     r2, =__StackTop
.LC4:
    cmp     r1, r2
    itt     lt
    strlt   r0, [r1], #4
    blt     .LC4

/*End of stack / heap initializaiton */
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
    .weak Reserved16_IRQHandler
    .type Reserved16_IRQHandler, %function
Reserved16_IRQHandler:
    ldr   r0,=Reserved16_DriverIRQHandler
    bx    r0
    .size Reserved16_IRQHandler, . - Reserved16_IRQHandler

    .align 1
    .thumb_func
    .weak CMC_IRQHandler
    .type CMC_IRQHandler, %function
CMC_IRQHandler:
    ldr   r0,=CMC_DriverIRQHandler
    bx    r0
    .size CMC_IRQHandler, . - CMC_IRQHandler

    .align 1
    .thumb_func
    .weak DMA0_CH0_IRQHandler
    .type DMA0_CH0_IRQHandler, %function
DMA0_CH0_IRQHandler:
    ldr   r0,=DMA0_CH0_DriverIRQHandler
    bx    r0
    .size DMA0_CH0_IRQHandler, . - DMA0_CH0_IRQHandler

    .align 1
    .thumb_func
    .weak DMA0_CH1_IRQHandler
    .type DMA0_CH1_IRQHandler, %function
DMA0_CH1_IRQHandler:
    ldr   r0,=DMA0_CH1_DriverIRQHandler
    bx    r0
    .size DMA0_CH1_IRQHandler, . - DMA0_CH1_IRQHandler

    .align 1
    .thumb_func
    .weak DMA0_CH2_IRQHandler
    .type DMA0_CH2_IRQHandler, %function
DMA0_CH2_IRQHandler:
    ldr   r0,=DMA0_CH2_DriverIRQHandler
    bx    r0
    .size DMA0_CH2_IRQHandler, . - DMA0_CH2_IRQHandler

    .align 1
    .thumb_func
    .weak DMA0_CH3_IRQHandler
    .type DMA0_CH3_IRQHandler, %function
DMA0_CH3_IRQHandler:
    ldr   r0,=DMA0_CH3_DriverIRQHandler
    bx    r0
    .size DMA0_CH3_IRQHandler, . - DMA0_CH3_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved22_IRQHandler
    .type Reserved22_IRQHandler, %function
Reserved22_IRQHandler:
    ldr   r0,=Reserved22_DriverIRQHandler
    bx    r0
    .size Reserved22_IRQHandler, . - Reserved22_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved23_IRQHandler
    .type Reserved23_IRQHandler, %function
Reserved23_IRQHandler:
    ldr   r0,=Reserved23_DriverIRQHandler
    bx    r0
    .size Reserved23_IRQHandler, . - Reserved23_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved24_IRQHandler
    .type Reserved24_IRQHandler, %function
Reserved24_IRQHandler:
    ldr   r0,=Reserved24_DriverIRQHandler
    bx    r0
    .size Reserved24_IRQHandler, . - Reserved24_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved25_IRQHandler
    .type Reserved25_IRQHandler, %function
Reserved25_IRQHandler:
    ldr   r0,=Reserved25_DriverIRQHandler
    bx    r0
    .size Reserved25_IRQHandler, . - Reserved25_IRQHandler

    .align 1
    .thumb_func
    .weak ERM0_IRQHandler
    .type ERM0_IRQHandler, %function
ERM0_IRQHandler:
    ldr   r0,=ERM0_DriverIRQHandler
    bx    r0
    .size ERM0_IRQHandler, . - ERM0_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved27_IRQHandler
    .type Reserved27_IRQHandler, %function
Reserved27_IRQHandler:
    ldr   r0,=Reserved27_DriverIRQHandler
    bx    r0
    .size Reserved27_IRQHandler, . - Reserved27_IRQHandler

    .align 1
    .thumb_func
    .weak FMU0_IRQHandler
    .type FMU0_IRQHandler, %function
FMU0_IRQHandler:
    ldr   r0,=FMU0_DriverIRQHandler
    bx    r0
    .size FMU0_IRQHandler, . - FMU0_IRQHandler

    .align 1
    .thumb_func
    .weak GLIKEY0_IRQHandler
    .type GLIKEY0_IRQHandler, %function
GLIKEY0_IRQHandler:
    ldr   r0,=GLIKEY0_DriverIRQHandler
    bx    r0
    .size GLIKEY0_IRQHandler, . - GLIKEY0_IRQHandler

    .align 1
    .thumb_func
    .weak MBC0_IRQHandler
    .type MBC0_IRQHandler, %function
MBC0_IRQHandler:
    ldr   r0,=MBC0_DriverIRQHandler
    bx    r0
    .size MBC0_IRQHandler, . - MBC0_IRQHandler

    .align 1
    .thumb_func
    .weak SCG0_IRQHandler
    .type SCG0_IRQHandler, %function
SCG0_IRQHandler:
    ldr   r0,=SCG0_DriverIRQHandler
    bx    r0
    .size SCG0_IRQHandler, . - SCG0_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved32_IRQHandler
    .type Reserved32_IRQHandler, %function
Reserved32_IRQHandler:
    ldr   r0,=Reserved32_DriverIRQHandler
    bx    r0
    .size Reserved32_IRQHandler, . - Reserved32_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved33_IRQHandler
    .type Reserved33_IRQHandler, %function
Reserved33_IRQHandler:
    ldr   r0,=Reserved33_DriverIRQHandler
    bx    r0
    .size Reserved33_IRQHandler, . - Reserved33_IRQHandler

    .align 1
    .thumb_func
    .weak WUU0_IRQHandler
    .type WUU0_IRQHandler, %function
WUU0_IRQHandler:
    ldr   r0,=WUU0_DriverIRQHandler
    bx    r0
    .size WUU0_IRQHandler, . - WUU0_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved35_IRQHandler
    .type Reserved35_IRQHandler, %function
Reserved35_IRQHandler:
    ldr   r0,=Reserved35_DriverIRQHandler
    bx    r0
    .size Reserved35_IRQHandler, . - Reserved35_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved36_IRQHandler
    .type Reserved36_IRQHandler, %function
Reserved36_IRQHandler:
    ldr   r0,=Reserved36_DriverIRQHandler
    bx    r0
    .size Reserved36_IRQHandler, . - Reserved36_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved37_IRQHandler
    .type Reserved37_IRQHandler, %function
Reserved37_IRQHandler:
    ldr   r0,=Reserved37_DriverIRQHandler
    bx    r0
    .size Reserved37_IRQHandler, . - Reserved37_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved38_IRQHandler
    .type Reserved38_IRQHandler, %function
Reserved38_IRQHandler:
    ldr   r0,=Reserved38_DriverIRQHandler
    bx    r0
    .size Reserved38_IRQHandler, . - Reserved38_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved39_IRQHandler
    .type Reserved39_IRQHandler, %function
Reserved39_IRQHandler:
    ldr   r0,=Reserved39_DriverIRQHandler
    bx    r0
    .size Reserved39_IRQHandler, . - Reserved39_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved40_IRQHandler
    .type Reserved40_IRQHandler, %function
Reserved40_IRQHandler:
    ldr   r0,=Reserved40_DriverIRQHandler
    bx    r0
    .size Reserved40_IRQHandler, . - Reserved40_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved41_IRQHandler
    .type Reserved41_IRQHandler, %function
Reserved41_IRQHandler:
    ldr   r0,=Reserved41_DriverIRQHandler
    bx    r0
    .size Reserved41_IRQHandler, . - Reserved41_IRQHandler

    .align 1
    .thumb_func
    .weak LPI2C0_IRQHandler
    .type LPI2C0_IRQHandler, %function
LPI2C0_IRQHandler:
    ldr   r0,=LPI2C0_DriverIRQHandler
    bx    r0
    .size LPI2C0_IRQHandler, . - LPI2C0_IRQHandler

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
    .weak LPSPI0_IRQHandler
    .type LPSPI0_IRQHandler, %function
LPSPI0_IRQHandler:
    ldr   r0,=LPSPI0_DriverIRQHandler
    bx    r0
    .size LPSPI0_IRQHandler, . - LPSPI0_IRQHandler

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
    .weak Reserved46_IRQHandler
    .type Reserved46_IRQHandler, %function
Reserved46_IRQHandler:
    ldr   r0,=Reserved46_DriverIRQHandler
    bx    r0
    .size Reserved46_IRQHandler, . - Reserved46_IRQHandler

    .align 1
    .thumb_func
    .weak LPUART0_IRQHandler
    .type LPUART0_IRQHandler, %function
LPUART0_IRQHandler:
    ldr   r0,=LPUART0_DriverIRQHandler
    bx    r0
    .size LPUART0_IRQHandler, . - LPUART0_IRQHandler

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
    .weak Reserved49_IRQHandler
    .type Reserved49_IRQHandler, %function
Reserved49_IRQHandler:
    ldr   r0,=Reserved49_DriverIRQHandler
    bx    r0
    .size Reserved49_IRQHandler, . - Reserved49_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved50_IRQHandler
    .type Reserved50_IRQHandler, %function
Reserved50_IRQHandler:
    ldr   r0,=Reserved50_DriverIRQHandler
    bx    r0
    .size Reserved50_IRQHandler, . - Reserved50_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved51_IRQHandler
    .type Reserved51_IRQHandler, %function
Reserved51_IRQHandler:
    ldr   r0,=Reserved51_DriverIRQHandler
    bx    r0
    .size Reserved51_IRQHandler, . - Reserved51_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved52_IRQHandler
    .type Reserved52_IRQHandler, %function
Reserved52_IRQHandler:
    ldr   r0,=Reserved52_DriverIRQHandler
    bx    r0
    .size Reserved52_IRQHandler, . - Reserved52_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved53_IRQHandler
    .type Reserved53_IRQHandler, %function
Reserved53_IRQHandler:
    ldr   r0,=Reserved53_DriverIRQHandler
    bx    r0
    .size Reserved53_IRQHandler, . - Reserved53_IRQHandler

    .align 1
    .thumb_func
    .weak CDOG0_IRQHandler
    .type CDOG0_IRQHandler, %function
CDOG0_IRQHandler:
    ldr   r0,=CDOG0_DriverIRQHandler
    bx    r0
    .size CDOG0_IRQHandler, . - CDOG0_IRQHandler

    .align 1
    .thumb_func
    .weak CTIMER0_IRQHandler
    .type CTIMER0_IRQHandler, %function
CTIMER0_IRQHandler:
    ldr   r0,=CTIMER0_DriverIRQHandler
    bx    r0
    .size CTIMER0_IRQHandler, . - CTIMER0_IRQHandler

    .align 1
    .thumb_func
    .weak CTIMER1_IRQHandler
    .type CTIMER1_IRQHandler, %function
CTIMER1_IRQHandler:
    ldr   r0,=CTIMER1_DriverIRQHandler
    bx    r0
    .size CTIMER1_IRQHandler, . - CTIMER1_IRQHandler

    .align 1
    .thumb_func
    .weak CTIMER2_IRQHandler
    .type CTIMER2_IRQHandler, %function
CTIMER2_IRQHandler:
    ldr   r0,=CTIMER2_DriverIRQHandler
    bx    r0
    .size CTIMER2_IRQHandler, . - CTIMER2_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved58_IRQHandler
    .type Reserved58_IRQHandler, %function
Reserved58_IRQHandler:
    ldr   r0,=Reserved58_DriverIRQHandler
    bx    r0
    .size Reserved58_IRQHandler, . - Reserved58_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved59_IRQHandler
    .type Reserved59_IRQHandler, %function
Reserved59_IRQHandler:
    ldr   r0,=Reserved59_DriverIRQHandler
    bx    r0
    .size Reserved59_IRQHandler, . - Reserved59_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved60_IRQHandler
    .type Reserved60_IRQHandler, %function
Reserved60_IRQHandler:
    ldr   r0,=Reserved60_DriverIRQHandler
    bx    r0
    .size Reserved60_IRQHandler, . - Reserved60_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved61_IRQHandler
    .type Reserved61_IRQHandler, %function
Reserved61_IRQHandler:
    ldr   r0,=Reserved61_DriverIRQHandler
    bx    r0
    .size Reserved61_IRQHandler, . - Reserved61_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved62_IRQHandler
    .type Reserved62_IRQHandler, %function
Reserved62_IRQHandler:
    ldr   r0,=Reserved62_DriverIRQHandler
    bx    r0
    .size Reserved62_IRQHandler, . - Reserved62_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved63_IRQHandler
    .type Reserved63_IRQHandler, %function
Reserved63_IRQHandler:
    ldr   r0,=Reserved63_DriverIRQHandler
    bx    r0
    .size Reserved63_IRQHandler, . - Reserved63_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved64_IRQHandler
    .type Reserved64_IRQHandler, %function
Reserved64_IRQHandler:
    ldr   r0,=Reserved64_DriverIRQHandler
    bx    r0
    .size Reserved64_IRQHandler, . - Reserved64_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved65_IRQHandler
    .type Reserved65_IRQHandler, %function
Reserved65_IRQHandler:
    ldr   r0,=Reserved65_DriverIRQHandler
    bx    r0
    .size Reserved65_IRQHandler, . - Reserved65_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved66_IRQHandler
    .type Reserved66_IRQHandler, %function
Reserved66_IRQHandler:
    ldr   r0,=Reserved66_DriverIRQHandler
    bx    r0
    .size Reserved66_IRQHandler, . - Reserved66_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved67_IRQHandler
    .type Reserved67_IRQHandler, %function
Reserved67_IRQHandler:
    ldr   r0,=Reserved67_DriverIRQHandler
    bx    r0
    .size Reserved67_IRQHandler, . - Reserved67_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved68_IRQHandler
    .type Reserved68_IRQHandler, %function
Reserved68_IRQHandler:
    ldr   r0,=Reserved68_DriverIRQHandler
    bx    r0
    .size Reserved68_IRQHandler, . - Reserved68_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved69_IRQHandler
    .type Reserved69_IRQHandler, %function
Reserved69_IRQHandler:
    ldr   r0,=Reserved69_DriverIRQHandler
    bx    r0
    .size Reserved69_IRQHandler, . - Reserved69_IRQHandler

    .align 1
    .thumb_func
    .weak FREQME0_IRQHandler
    .type FREQME0_IRQHandler, %function
FREQME0_IRQHandler:
    ldr   r0,=FREQME0_DriverIRQHandler
    bx    r0
    .size FREQME0_IRQHandler, . - FREQME0_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved71_IRQHandler
    .type Reserved71_IRQHandler, %function
Reserved71_IRQHandler:
    ldr   r0,=Reserved71_DriverIRQHandler
    bx    r0
    .size Reserved71_IRQHandler, . - Reserved71_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved72_IRQHandler
    .type Reserved72_IRQHandler, %function
Reserved72_IRQHandler:
    ldr   r0,=Reserved72_DriverIRQHandler
    bx    r0
    .size Reserved72_IRQHandler, . - Reserved72_IRQHandler

    .align 1
    .thumb_func
    .weak OS_EVENT_IRQHandler
    .type OS_EVENT_IRQHandler, %function
OS_EVENT_IRQHandler:
    ldr   r0,=OS_EVENT_DriverIRQHandler
    bx    r0
    .size OS_EVENT_IRQHandler, . - OS_EVENT_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved74_IRQHandler
    .type Reserved74_IRQHandler, %function
Reserved74_IRQHandler:
    ldr   r0,=Reserved74_DriverIRQHandler
    bx    r0
    .size Reserved74_IRQHandler, . - Reserved74_IRQHandler

    .align 1
    .thumb_func
    .weak UTICK0_IRQHandler
    .type UTICK0_IRQHandler, %function
UTICK0_IRQHandler:
    ldr   r0,=UTICK0_DriverIRQHandler
    bx    r0
    .size UTICK0_IRQHandler, . - UTICK0_IRQHandler

    .align 1
    .thumb_func
    .weak WWDT0_IRQHandler
    .type WWDT0_IRQHandler, %function
WWDT0_IRQHandler:
    ldr   r0,=WWDT0_DriverIRQHandler
    bx    r0
    .size WWDT0_IRQHandler, . - WWDT0_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved77_IRQHandler
    .type Reserved77_IRQHandler, %function
Reserved77_IRQHandler:
    ldr   r0,=Reserved77_DriverIRQHandler
    bx    r0
    .size Reserved77_IRQHandler, . - Reserved77_IRQHandler

    .align 1
    .thumb_func
    .weak ADC0_IRQHandler
    .type ADC0_IRQHandler, %function
ADC0_IRQHandler:
    ldr   r0,=ADC0_DriverIRQHandler
    bx    r0
    .size ADC0_IRQHandler, . - ADC0_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved79_IRQHandler
    .type Reserved79_IRQHandler, %function
Reserved79_IRQHandler:
    ldr   r0,=Reserved79_DriverIRQHandler
    bx    r0
    .size Reserved79_IRQHandler, . - Reserved79_IRQHandler

    .align 1
    .thumb_func
    .weak CMP0_IRQHandler
    .type CMP0_IRQHandler, %function
CMP0_IRQHandler:
    ldr   r0,=CMP0_DriverIRQHandler
    bx    r0
    .size CMP0_IRQHandler, . - CMP0_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved81_IRQHandler
    .type Reserved81_IRQHandler, %function
Reserved81_IRQHandler:
    ldr   r0,=Reserved81_DriverIRQHandler
    bx    r0
    .size Reserved81_IRQHandler, . - Reserved81_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved82_IRQHandler
    .type Reserved82_IRQHandler, %function
Reserved82_IRQHandler:
    ldr   r0,=Reserved82_DriverIRQHandler
    bx    r0
    .size Reserved82_IRQHandler, . - Reserved82_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved83_IRQHandler
    .type Reserved83_IRQHandler, %function
Reserved83_IRQHandler:
    ldr   r0,=Reserved83_DriverIRQHandler
    bx    r0
    .size Reserved83_IRQHandler, . - Reserved83_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved84_IRQHandler
    .type Reserved84_IRQHandler, %function
Reserved84_IRQHandler:
    ldr   r0,=Reserved84_DriverIRQHandler
    bx    r0
    .size Reserved84_IRQHandler, . - Reserved84_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved85_IRQHandler
    .type Reserved85_IRQHandler, %function
Reserved85_IRQHandler:
    ldr   r0,=Reserved85_DriverIRQHandler
    bx    r0
    .size Reserved85_IRQHandler, . - Reserved85_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved86_IRQHandler
    .type Reserved86_IRQHandler, %function
Reserved86_IRQHandler:
    ldr   r0,=Reserved86_DriverIRQHandler
    bx    r0
    .size Reserved86_IRQHandler, . - Reserved86_IRQHandler

    .align 1
    .thumb_func
    .weak GPIO10_IRQHandler
    .type GPIO10_IRQHandler, %function
GPIO10_IRQHandler:
    ldr   r0,=GPIO10_DriverIRQHandler
    bx    r0
    .size GPIO10_IRQHandler, . - GPIO10_IRQHandler

    .align 1
    .thumb_func
    .weak GPIO11_IRQHandler
    .type GPIO11_IRQHandler, %function
GPIO11_IRQHandler:
    ldr   r0,=GPIO11_DriverIRQHandler
    bx    r0
    .size GPIO11_IRQHandler, . - GPIO11_IRQHandler

    .align 1
    .thumb_func
    .weak GPIO20_IRQHandler
    .type GPIO20_IRQHandler, %function
GPIO20_IRQHandler:
    ldr   r0,=GPIO20_DriverIRQHandler
    bx    r0
    .size GPIO20_IRQHandler, . - GPIO20_IRQHandler

    .align 1
    .thumb_func
    .weak GPIO21_IRQHandler
    .type GPIO21_IRQHandler, %function
GPIO21_IRQHandler:
    ldr   r0,=GPIO21_DriverIRQHandler
    bx    r0
    .size GPIO21_IRQHandler, . - GPIO21_IRQHandler

    .align 1
    .thumb_func
    .weak GPIO30_IRQHandler
    .type GPIO30_IRQHandler, %function
GPIO30_IRQHandler:
    ldr   r0,=GPIO30_DriverIRQHandler
    bx    r0
    .size GPIO30_IRQHandler, . - GPIO30_IRQHandler

    .align 1
    .thumb_func
    .weak GPIO31_IRQHandler
    .type GPIO31_IRQHandler, %function
GPIO31_IRQHandler:
    ldr   r0,=GPIO31_DriverIRQHandler
    bx    r0
    .size GPIO31_IRQHandler, . - GPIO31_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved93_IRQHandler
    .type Reserved93_IRQHandler, %function
Reserved93_IRQHandler:
    ldr   r0,=Reserved93_DriverIRQHandler
    bx    r0
    .size Reserved93_IRQHandler, . - Reserved93_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved94_IRQHandler
    .type Reserved94_IRQHandler, %function
Reserved94_IRQHandler:
    ldr   r0,=Reserved94_DriverIRQHandler
    bx    r0
    .size Reserved94_IRQHandler, . - Reserved94_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved95_IRQHandler
    .type Reserved95_IRQHandler, %function
Reserved95_IRQHandler:
    ldr   r0,=Reserved95_DriverIRQHandler
    bx    r0
    .size Reserved95_IRQHandler, . - Reserved95_IRQHandler

    .align 1
    .thumb_func
    .weak MU_A_TX_IRQHandler
    .type MU_A_TX_IRQHandler, %function
MU_A_TX_IRQHandler:
    ldr   r0,=MU_A_TX_DriverIRQHandler
    bx    r0
    .size MU_A_TX_IRQHandler, . - MU_A_TX_IRQHandler

    .align 1
    .thumb_func
    .weak MU_A_RX_IRQHandler
    .type MU_A_RX_IRQHandler, %function
MU_A_RX_IRQHandler:
    ldr   r0,=MU_A_RX_DriverIRQHandler
    bx    r0
    .size MU_A_RX_IRQHandler, . - MU_A_RX_IRQHandler

    .align 1
    .thumb_func
    .weak MU_A_INT_IRQHandler
    .type MU_A_INT_IRQHandler, %function
MU_A_INT_IRQHandler:
    ldr   r0,=MU_A_INT_DriverIRQHandler
    bx    r0
    .size MU_A_INT_IRQHandler, . - MU_A_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CDOG1_IRQHandler
    .type CDOG1_IRQHandler, %function
CDOG1_IRQHandler:
    ldr   r0,=CDOG1_DriverIRQHandler
    bx    r0
    .size CDOG1_IRQHandler, . - CDOG1_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved100_IRQHandler
    .type Reserved100_IRQHandler, %function
Reserved100_IRQHandler:
    ldr   r0,=Reserved100_DriverIRQHandler
    bx    r0
    .size Reserved100_IRQHandler, . - Reserved100_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved101_IRQHandler
    .type Reserved101_IRQHandler, %function
Reserved101_IRQHandler:
    ldr   r0,=Reserved101_DriverIRQHandler
    bx    r0
    .size Reserved101_IRQHandler, . - Reserved101_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved102_IRQHandler
    .type Reserved102_IRQHandler, %function
Reserved102_IRQHandler:
    ldr   r0,=Reserved102_DriverIRQHandler
    bx    r0
    .size Reserved102_IRQHandler, . - Reserved102_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved103_IRQHandler
    .type Reserved103_IRQHandler, %function
Reserved103_IRQHandler:
    ldr   r0,=Reserved103_DriverIRQHandler
    bx    r0
    .size Reserved103_IRQHandler, . - Reserved103_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved104_IRQHandler
    .type Reserved104_IRQHandler, %function
Reserved104_IRQHandler:
    ldr   r0,=Reserved104_DriverIRQHandler
    bx    r0
    .size Reserved104_IRQHandler, . - Reserved104_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved105_IRQHandler
    .type Reserved105_IRQHandler, %function
Reserved105_IRQHandler:
    ldr   r0,=Reserved105_DriverIRQHandler
    bx    r0
    .size Reserved105_IRQHandler, . - Reserved105_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved106_IRQHandler
    .type Reserved106_IRQHandler, %function
Reserved106_IRQHandler:
    ldr   r0,=Reserved106_DriverIRQHandler
    bx    r0
    .size Reserved106_IRQHandler, . - Reserved106_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved107_IRQHandler
    .type Reserved107_IRQHandler, %function
Reserved107_IRQHandler:
    ldr   r0,=Reserved107_DriverIRQHandler
    bx    r0
    .size Reserved107_IRQHandler, . - Reserved107_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved108_IRQHandler
    .type Reserved108_IRQHandler, %function
Reserved108_IRQHandler:
    ldr   r0,=Reserved108_DriverIRQHandler
    bx    r0
    .size Reserved108_IRQHandler, . - Reserved108_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved109_IRQHandler
    .type Reserved109_IRQHandler, %function
Reserved109_IRQHandler:
    ldr   r0,=Reserved109_DriverIRQHandler
    bx    r0
    .size Reserved109_IRQHandler, . - Reserved109_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved110_IRQHandler
    .type Reserved110_IRQHandler, %function
Reserved110_IRQHandler:
    ldr   r0,=Reserved110_DriverIRQHandler
    bx    r0
    .size Reserved110_IRQHandler, . - Reserved110_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved111_IRQHandler
    .type Reserved111_IRQHandler, %function
Reserved111_IRQHandler:
    ldr   r0,=Reserved111_DriverIRQHandler
    bx    r0
    .size Reserved111_IRQHandler, . - Reserved111_IRQHandler

    .align 1
    .thumb_func
    .weak DMA1_CH0_IRQHandler
    .type DMA1_CH0_IRQHandler, %function
DMA1_CH0_IRQHandler:
    ldr   r0,=DMA1_CH0_DriverIRQHandler
    bx    r0
    .size DMA1_CH0_IRQHandler, . - DMA1_CH0_IRQHandler

    .align 1
    .thumb_func
    .weak DMA1_CH1_IRQHandler
    .type DMA1_CH1_IRQHandler, %function
DMA1_CH1_IRQHandler:
    ldr   r0,=DMA1_CH1_DriverIRQHandler
    bx    r0
    .size DMA1_CH1_IRQHandler, . - DMA1_CH1_IRQHandler

    .align 1
    .thumb_func
    .weak DMA1_CH2_IRQHandler
    .type DMA1_CH2_IRQHandler, %function
DMA1_CH2_IRQHandler:
    ldr   r0,=DMA1_CH2_DriverIRQHandler
    bx    r0
    .size DMA1_CH2_IRQHandler, . - DMA1_CH2_IRQHandler

    .align 1
    .thumb_func
    .weak DMA1_CH3_IRQHandler
    .type DMA1_CH3_IRQHandler, %function
DMA1_CH3_IRQHandler:
    ldr   r0,=DMA1_CH3_DriverIRQHandler
    bx    r0
    .size DMA1_CH3_IRQHandler, . - DMA1_CH3_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved116_IRQHandler
    .type Reserved116_IRQHandler, %function
Reserved116_IRQHandler:
    ldr   r0,=Reserved116_DriverIRQHandler
    bx    r0
    .size Reserved116_IRQHandler, . - Reserved116_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved117_IRQHandler
    .type Reserved117_IRQHandler, %function
Reserved117_IRQHandler:
    ldr   r0,=Reserved117_DriverIRQHandler
    bx    r0
    .size Reserved117_IRQHandler, . - Reserved117_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved118_IRQHandler
    .type Reserved118_IRQHandler, %function
Reserved118_IRQHandler:
    ldr   r0,=Reserved118_DriverIRQHandler
    bx    r0
    .size Reserved118_IRQHandler, . - Reserved118_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved119_IRQHandler
    .type Reserved119_IRQHandler, %function
Reserved119_IRQHandler:
    ldr   r0,=Reserved119_DriverIRQHandler
    bx    r0
    .size Reserved119_IRQHandler, . - Reserved119_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved120_IRQHandler
    .type Reserved120_IRQHandler, %function
Reserved120_IRQHandler:
    ldr   r0,=Reserved120_DriverIRQHandler
    bx    r0
    .size Reserved120_IRQHandler, . - Reserved120_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved121_IRQHandler
    .type Reserved121_IRQHandler, %function
Reserved121_IRQHandler:
    ldr   r0,=Reserved121_DriverIRQHandler
    bx    r0
    .size Reserved121_IRQHandler, . - Reserved121_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved122_IRQHandler
    .type Reserved122_IRQHandler, %function
Reserved122_IRQHandler:
    ldr   r0,=Reserved122_DriverIRQHandler
    bx    r0
    .size Reserved122_IRQHandler, . - Reserved122_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved123_IRQHandler
    .type Reserved123_IRQHandler, %function
Reserved123_IRQHandler:
    ldr   r0,=Reserved123_DriverIRQHandler
    bx    r0
    .size Reserved123_IRQHandler, . - Reserved123_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved124_IRQHandler
    .type Reserved124_IRQHandler, %function
Reserved124_IRQHandler:
    ldr   r0,=Reserved124_DriverIRQHandler
    bx    r0
    .size Reserved124_IRQHandler, . - Reserved124_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved125_IRQHandler
    .type Reserved125_IRQHandler, %function
Reserved125_IRQHandler:
    ldr   r0,=Reserved125_DriverIRQHandler
    bx    r0
    .size Reserved125_IRQHandler, . - Reserved125_IRQHandler

    .align 1
    .thumb_func
    .weak PKC_IRQHandler
    .type PKC_IRQHandler, %function
PKC_IRQHandler:
    ldr   r0,=PKC_DriverIRQHandler
    bx    r0
    .size PKC_IRQHandler, . - PKC_IRQHandler

    .align 1
    .thumb_func
    .weak SGI_IRQHandler
    .type SGI_IRQHandler, %function
SGI_IRQHandler:
    ldr   r0,=SGI_DriverIRQHandler
    bx    r0
    .size SGI_IRQHandler, . - SGI_IRQHandler

    .align 1
    .thumb_func
    .weak TRNG_IRQHandler
    .type TRNG_IRQHandler, %function
TRNG_IRQHandler:
    ldr   r0,=TRNG_DriverIRQHandler
    bx    r0
    .size TRNG_IRQHandler, . - TRNG_IRQHandler

    .align 1
    .thumb_func
    .weak ERR_SGI_UDF_TRNG_PKC_IRQHandler
    .type ERR_SGI_UDF_TRNG_PKC_IRQHandler, %function
ERR_SGI_UDF_TRNG_PKC_IRQHandler:
    ldr   r0,=ERR_SGI_UDF_TRNG_PKC_DriverIRQHandler
    bx    r0
    .size ERR_SGI_UDF_TRNG_PKC_IRQHandler, . - ERR_SGI_UDF_TRNG_PKC_IRQHandler

    .align 1
    .thumb_func
    .weak HYPERVISOR_IRQHandler
    .type HYPERVISOR_IRQHandler, %function
HYPERVISOR_IRQHandler:
    ldr   r0,=HYPERVISOR_DriverIRQHandler
    bx    r0
    .size HYPERVISOR_IRQHandler, . - HYPERVISOR_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved131_IRQHandler
    .type Reserved131_IRQHandler, %function
Reserved131_IRQHandler:
    ldr   r0,=Reserved131_DriverIRQHandler
    bx    r0
    .size Reserved131_IRQHandler, . - Reserved131_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved132_IRQHandler
    .type Reserved132_IRQHandler, %function
Reserved132_IRQHandler:
    ldr   r0,=Reserved132_DriverIRQHandler
    bx    r0
    .size Reserved132_IRQHandler, . - Reserved132_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved133_IRQHandler
    .type Reserved133_IRQHandler, %function
Reserved133_IRQHandler:
    ldr   r0,=Reserved133_DriverIRQHandler
    bx    r0
    .size Reserved133_IRQHandler, . - Reserved133_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved134_IRQHandler
    .type Reserved134_IRQHandler, %function
Reserved134_IRQHandler:
    ldr   r0,=Reserved134_DriverIRQHandler
    bx    r0
    .size Reserved134_IRQHandler, . - Reserved134_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved135_IRQHandler
    .type Reserved135_IRQHandler, %function
Reserved135_IRQHandler:
    ldr   r0,=Reserved135_DriverIRQHandler
    bx    r0
    .size Reserved135_IRQHandler, . - Reserved135_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved136_IRQHandler
    .type Reserved136_IRQHandler, %function
Reserved136_IRQHandler:
    ldr   r0,=Reserved136_DriverIRQHandler
    bx    r0
    .size Reserved136_IRQHandler, . - Reserved136_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved137_IRQHandler
    .type Reserved137_IRQHandler, %function
Reserved137_IRQHandler:
    ldr   r0,=Reserved137_DriverIRQHandler
    bx    r0
    .size Reserved137_IRQHandler, . - Reserved137_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved138_IRQHandler
    .type Reserved138_IRQHandler, %function
Reserved138_IRQHandler:
    ldr   r0,=Reserved138_DriverIRQHandler
    bx    r0
    .size Reserved138_IRQHandler, . - Reserved138_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved139_IRQHandler
    .type Reserved139_IRQHandler, %function
Reserved139_IRQHandler:
    ldr   r0,=Reserved139_DriverIRQHandler
    bx    r0
    .size Reserved139_IRQHandler, . - Reserved139_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved140_IRQHandler
    .type Reserved140_IRQHandler, %function
Reserved140_IRQHandler:
    ldr   r0,=Reserved140_DriverIRQHandler
    bx    r0
    .size Reserved140_IRQHandler, . - Reserved140_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved141_IRQHandler
    .type Reserved141_IRQHandler, %function
Reserved141_IRQHandler:
    ldr   r0,=Reserved141_DriverIRQHandler
    bx    r0
    .size Reserved141_IRQHandler, . - Reserved141_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved142_IRQHandler
    .type Reserved142_IRQHandler, %function
Reserved142_IRQHandler:
    ldr   r0,=Reserved142_DriverIRQHandler
    bx    r0
    .size Reserved142_IRQHandler, . - Reserved142_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved143_IRQHandler
    .type Reserved143_IRQHandler, %function
Reserved143_IRQHandler:
    ldr   r0,=Reserved143_DriverIRQHandler
    bx    r0
    .size Reserved143_IRQHandler, . - Reserved143_IRQHandler

    .align 1
    .thumb_func
    .weak LPI2C0_AON_IRQHandler
    .type LPI2C0_AON_IRQHandler, %function
LPI2C0_AON_IRQHandler:
    ldr   r0,=LPI2C0_AON_DriverIRQHandler
    bx    r0
    .size LPI2C0_AON_IRQHandler, . - LPI2C0_AON_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved145_IRQHandler
    .type Reserved145_IRQHandler, %function
Reserved145_IRQHandler:
    ldr   r0,=Reserved145_DriverIRQHandler
    bx    r0
    .size Reserved145_IRQHandler, . - Reserved145_IRQHandler

    .align 1
    .thumb_func
    .weak LPUART0_AON_IRQHandler
    .type LPUART0_AON_IRQHandler, %function
LPUART0_AON_IRQHandler:
    ldr   r0,=LPUART0_AON_DriverIRQHandler
    bx    r0
    .size LPUART0_AON_IRQHandler, . - LPUART0_AON_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved147_IRQHandler
    .type Reserved147_IRQHandler, %function
Reserved147_IRQHandler:
    ldr   r0,=Reserved147_DriverIRQHandler
    bx    r0
    .size Reserved147_IRQHandler, . - Reserved147_IRQHandler

    .align 1
    .thumb_func
    .weak GPIO00_AON_IRQHandler
    .type GPIO00_AON_IRQHandler, %function
GPIO00_AON_IRQHandler:
    ldr   r0,=GPIO00_AON_DriverIRQHandler
    bx    r0
    .size GPIO00_AON_IRQHandler, . - GPIO00_AON_IRQHandler

    .align 1
    .thumb_func
    .weak GPIO01_AON_IRQHandler
    .type GPIO01_AON_IRQHandler, %function
GPIO01_AON_IRQHandler:
    ldr   r0,=GPIO01_AON_DriverIRQHandler
    bx    r0
    .size GPIO01_AON_IRQHandler, . - GPIO01_AON_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved150_IRQHandler
    .type Reserved150_IRQHandler, %function
Reserved150_IRQHandler:
    ldr   r0,=Reserved150_DriverIRQHandler
    bx    r0
    .size Reserved150_IRQHandler, . - Reserved150_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved151_IRQHandler
    .type Reserved151_IRQHandler, %function
Reserved151_IRQHandler:
    ldr   r0,=Reserved151_DriverIRQHandler
    bx    r0
    .size Reserved151_IRQHandler, . - Reserved151_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved152_IRQHandler
    .type Reserved152_IRQHandler, %function
Reserved152_IRQHandler:
    ldr   r0,=Reserved152_DriverIRQHandler
    bx    r0
    .size Reserved152_IRQHandler, . - Reserved152_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved153_IRQHandler
    .type Reserved153_IRQHandler, %function
Reserved153_IRQHandler:
    ldr   r0,=Reserved153_DriverIRQHandler
    bx    r0
    .size Reserved153_IRQHandler, . - Reserved153_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved154_IRQHandler
    .type Reserved154_IRQHandler, %function
Reserved154_IRQHandler:
    ldr   r0,=Reserved154_DriverIRQHandler
    bx    r0
    .size Reserved154_IRQHandler, . - Reserved154_IRQHandler

    .align 1
    .thumb_func
    .weak LPCMP_IRQHandler
    .type LPCMP_IRQHandler, %function
LPCMP_IRQHandler:
    ldr   r0,=LPCMP_DriverIRQHandler
    bx    r0
    .size LPCMP_IRQHandler, . - LPCMP_IRQHandler

    .align 1
    .thumb_func
    .weak RTC_ALARM0_IRQHandler
    .type RTC_ALARM0_IRQHandler, %function
RTC_ALARM0_IRQHandler:
    ldr   r0,=RTC_ALARM0_DriverIRQHandler
    bx    r0
    .size RTC_ALARM0_IRQHandler, . - RTC_ALARM0_IRQHandler

    .align 1
    .thumb_func
    .weak RTC_ALARM1_IRQHandler
    .type RTC_ALARM1_IRQHandler, %function
RTC_ALARM1_IRQHandler:
    ldr   r0,=RTC_ALARM1_DriverIRQHandler
    bx    r0
    .size RTC_ALARM1_IRQHandler, . - RTC_ALARM1_IRQHandler

    .align 1
    .thumb_func
    .weak RTC_ALARM2_IRQHandler
    .type RTC_ALARM2_IRQHandler, %function
RTC_ALARM2_IRQHandler:
    ldr   r0,=RTC_ALARM2_DriverIRQHandler
    bx    r0
    .size RTC_ALARM2_IRQHandler, . - RTC_ALARM2_IRQHandler

    .align 1
    .thumb_func
    .weak RTC_WDT_IRQHandler
    .type RTC_WDT_IRQHandler, %function
RTC_WDT_IRQHandler:
    ldr   r0,=RTC_WDT_DriverIRQHandler
    bx    r0
    .size RTC_WDT_IRQHandler, . - RTC_WDT_IRQHandler

    .align 1
    .thumb_func
    .weak RTC_XTAL_IRQHandler
    .type RTC_XTAL_IRQHandler, %function
RTC_XTAL_IRQHandler:
    ldr   r0,=RTC_XTAL_DriverIRQHandler
    bx    r0
    .size RTC_XTAL_IRQHandler, . - RTC_XTAL_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved161_IRQHandler
    .type Reserved161_IRQHandler, %function
Reserved161_IRQHandler:
    ldr   r0,=Reserved161_DriverIRQHandler
    bx    r0
    .size Reserved161_IRQHandler, . - Reserved161_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved162_IRQHandler
    .type Reserved162_IRQHandler, %function
Reserved162_IRQHandler:
    ldr   r0,=Reserved162_DriverIRQHandler
    bx    r0
    .size Reserved162_IRQHandler, . - Reserved162_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved163_IRQHandler
    .type Reserved163_IRQHandler, %function
Reserved163_IRQHandler:
    ldr   r0,=Reserved163_DriverIRQHandler
    bx    r0
    .size Reserved163_IRQHandler, . - Reserved163_IRQHandler

    .align 1
    .thumb_func
    .weak KPP_IRQHandler
    .type KPP_IRQHandler, %function
KPP_IRQHandler:
    ldr   r0,=KPP_DriverIRQHandler
    bx    r0
    .size KPP_IRQHandler, . - KPP_IRQHandler

    .align 1
    .thumb_func
    .weak LPADC_AON_IRQHandler
    .type LPADC_AON_IRQHandler, %function
LPADC_AON_IRQHandler:
    ldr   r0,=LPADC_AON_DriverIRQHandler
    bx    r0
    .size LPADC_AON_IRQHandler, . - LPADC_AON_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved166_IRQHandler
    .type Reserved166_IRQHandler, %function
Reserved166_IRQHandler:
    ldr   r0,=Reserved166_DriverIRQHandler
    bx    r0
    .size Reserved166_IRQHandler, . - Reserved166_IRQHandler

    .align 1
    .thumb_func
    .weak TMR0_AON_IRQHandler
    .type TMR0_AON_IRQHandler, %function
TMR0_AON_IRQHandler:
    ldr   r0,=TMR0_AON_DriverIRQHandler
    bx    r0
    .size TMR0_AON_IRQHandler, . - TMR0_AON_IRQHandler

    .align 1
    .thumb_func
    .weak TMR1_AON_IRQHandler
    .type TMR1_AON_IRQHandler, %function
TMR1_AON_IRQHandler:
    ldr   r0,=TMR1_AON_DriverIRQHandler
    bx    r0
    .size TMR1_AON_IRQHandler, . - TMR1_AON_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved169_IRQHandler
    .type Reserved169_IRQHandler, %function
Reserved169_IRQHandler:
    ldr   r0,=Reserved169_DriverIRQHandler
    bx    r0
    .size Reserved169_IRQHandler, . - Reserved169_IRQHandler

    .align 1
    .thumb_func
    .weak LCSENSE_IRQHandler
    .type LCSENSE_IRQHandler, %function
LCSENSE_IRQHandler:
    ldr   r0,=LCSENSE_DriverIRQHandler
    bx    r0
    .size LCSENSE_IRQHandler, . - LCSENSE_IRQHandler

    .align 1
    .thumb_func
    .weak LPTMR_AON_IRQHandler
    .type LPTMR_AON_IRQHandler, %function
LPTMR_AON_IRQHandler:
    ldr   r0,=LPTMR_AON_DriverIRQHandler
    bx    r0
    .size LPTMR_AON_IRQHandler, . - LPTMR_AON_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved172_IRQHandler
    .type Reserved172_IRQHandler, %function
Reserved172_IRQHandler:
    ldr   r0,=Reserved172_DriverIRQHandler
    bx    r0
    .size Reserved172_IRQHandler, . - Reserved172_IRQHandler

    .align 1
    .thumb_func
    .weak CMP0_AON_IRQHandler
    .type CMP0_AON_IRQHandler, %function
CMP0_AON_IRQHandler:
    ldr   r0,=CMP0_AON_DriverIRQHandler
    bx    r0
    .size CMP0_AON_IRQHandler, . - CMP0_AON_IRQHandler

    .align 1
    .thumb_func
    .weak ADVC_IRQHandler
    .type ADVC_IRQHandler, %function
ADVC_IRQHandler:
    ldr   r0,=ADVC_DriverIRQHandler
    bx    r0
    .size ADVC_IRQHandler, . - ADVC_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved175_IRQHandler
    .type Reserved175_IRQHandler, %function
Reserved175_IRQHandler:
    ldr   r0,=Reserved175_DriverIRQHandler
    bx    r0
    .size Reserved175_IRQHandler, . - Reserved175_IRQHandler

    .align 1
    .thumb_func
    .weak SGLCD_FRAME_AON_IRQHandler
    .type SGLCD_FRAME_AON_IRQHandler, %function
SGLCD_FRAME_AON_IRQHandler:
    ldr   r0,=SGLCD_FRAME_AON_DriverIRQHandler
    bx    r0
    .size SGLCD_FRAME_AON_IRQHandler, . - SGLCD_FRAME_AON_IRQHandler

    .align 1
    .thumb_func
    .weak SGLCD_FFAULT_AON_IRQHandler
    .type SGLCD_FFAULT_AON_IRQHandler, %function
SGLCD_FFAULT_AON_IRQHandler:
    ldr   r0,=SGLCD_FFAULT_AON_DriverIRQHandler
    bx    r0
    .size SGLCD_FFAULT_AON_IRQHandler, . - SGLCD_FFAULT_AON_IRQHandler


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
    def_irq_handler    SecureFault_Handler
    def_irq_handler    DebugMon_Handler
    def_irq_handler    Reserved16_DriverIRQHandler
    def_irq_handler    CMC_DriverIRQHandler
    def_irq_handler    DMA0_CH0_DriverIRQHandler
    def_irq_handler    DMA0_CH1_DriverIRQHandler
    def_irq_handler    DMA0_CH2_DriverIRQHandler
    def_irq_handler    DMA0_CH3_DriverIRQHandler
    def_irq_handler    Reserved22_DriverIRQHandler
    def_irq_handler    Reserved23_DriverIRQHandler
    def_irq_handler    Reserved24_DriverIRQHandler
    def_irq_handler    Reserved25_DriverIRQHandler
    def_irq_handler    ERM0_DriverIRQHandler
    def_irq_handler    Reserved27_DriverIRQHandler
    def_irq_handler    FMU0_DriverIRQHandler
    def_irq_handler    GLIKEY0_DriverIRQHandler
    def_irq_handler    MBC0_DriverIRQHandler
    def_irq_handler    SCG0_DriverIRQHandler
    def_irq_handler    Reserved32_DriverIRQHandler
    def_irq_handler    Reserved33_DriverIRQHandler
    def_irq_handler    WUU0_DriverIRQHandler
    def_irq_handler    Reserved35_DriverIRQHandler
    def_irq_handler    Reserved36_DriverIRQHandler
    def_irq_handler    Reserved37_DriverIRQHandler
    def_irq_handler    Reserved38_DriverIRQHandler
    def_irq_handler    Reserved39_DriverIRQHandler
    def_irq_handler    Reserved40_DriverIRQHandler
    def_irq_handler    Reserved41_DriverIRQHandler
    def_irq_handler    LPI2C0_DriverIRQHandler
    def_irq_handler    LPI2C1_DriverIRQHandler
    def_irq_handler    LPSPI0_DriverIRQHandler
    def_irq_handler    LPSPI1_DriverIRQHandler
    def_irq_handler    Reserved46_DriverIRQHandler
    def_irq_handler    LPUART0_DriverIRQHandler
    def_irq_handler    LPUART1_DriverIRQHandler
    def_irq_handler    Reserved49_DriverIRQHandler
    def_irq_handler    Reserved50_DriverIRQHandler
    def_irq_handler    Reserved51_DriverIRQHandler
    def_irq_handler    Reserved52_DriverIRQHandler
    def_irq_handler    Reserved53_DriverIRQHandler
    def_irq_handler    CDOG0_DriverIRQHandler
    def_irq_handler    CTIMER0_DriverIRQHandler
    def_irq_handler    CTIMER1_DriverIRQHandler
    def_irq_handler    CTIMER2_DriverIRQHandler
    def_irq_handler    Reserved58_DriverIRQHandler
    def_irq_handler    Reserved59_DriverIRQHandler
    def_irq_handler    Reserved60_DriverIRQHandler
    def_irq_handler    Reserved61_DriverIRQHandler
    def_irq_handler    Reserved62_DriverIRQHandler
    def_irq_handler    Reserved63_DriverIRQHandler
    def_irq_handler    Reserved64_DriverIRQHandler
    def_irq_handler    Reserved65_DriverIRQHandler
    def_irq_handler    Reserved66_DriverIRQHandler
    def_irq_handler    Reserved67_DriverIRQHandler
    def_irq_handler    Reserved68_DriverIRQHandler
    def_irq_handler    Reserved69_DriverIRQHandler
    def_irq_handler    FREQME0_DriverIRQHandler
    def_irq_handler    Reserved71_DriverIRQHandler
    def_irq_handler    Reserved72_DriverIRQHandler
    def_irq_handler    OS_EVENT_DriverIRQHandler
    def_irq_handler    Reserved74_DriverIRQHandler
    def_irq_handler    UTICK0_DriverIRQHandler
    def_irq_handler    WWDT0_DriverIRQHandler
    def_irq_handler    Reserved77_DriverIRQHandler
    def_irq_handler    ADC0_DriverIRQHandler
    def_irq_handler    Reserved79_DriverIRQHandler
    def_irq_handler    CMP0_DriverIRQHandler
    def_irq_handler    Reserved81_DriverIRQHandler
    def_irq_handler    Reserved82_DriverIRQHandler
    def_irq_handler    Reserved83_DriverIRQHandler
    def_irq_handler    Reserved84_DriverIRQHandler
    def_irq_handler    Reserved85_DriverIRQHandler
    def_irq_handler    Reserved86_DriverIRQHandler
    def_irq_handler    GPIO10_DriverIRQHandler
    def_irq_handler    GPIO11_DriverIRQHandler
    def_irq_handler    GPIO20_DriverIRQHandler
    def_irq_handler    GPIO21_DriverIRQHandler
    def_irq_handler    GPIO30_DriverIRQHandler
    def_irq_handler    GPIO31_DriverIRQHandler
    def_irq_handler    Reserved93_DriverIRQHandler
    def_irq_handler    Reserved94_DriverIRQHandler
    def_irq_handler    Reserved95_DriverIRQHandler
    def_irq_handler    MU_A_TX_DriverIRQHandler
    def_irq_handler    MU_A_RX_DriverIRQHandler
    def_irq_handler    MU_A_INT_DriverIRQHandler
    def_irq_handler    CDOG1_DriverIRQHandler
    def_irq_handler    Reserved100_DriverIRQHandler
    def_irq_handler    Reserved101_DriverIRQHandler
    def_irq_handler    Reserved102_DriverIRQHandler
    def_irq_handler    Reserved103_DriverIRQHandler
    def_irq_handler    Reserved104_DriverIRQHandler
    def_irq_handler    Reserved105_DriverIRQHandler
    def_irq_handler    Reserved106_DriverIRQHandler
    def_irq_handler    Reserved107_DriverIRQHandler
    def_irq_handler    Reserved108_DriverIRQHandler
    def_irq_handler    Reserved109_DriverIRQHandler
    def_irq_handler    Reserved110_DriverIRQHandler
    def_irq_handler    Reserved111_DriverIRQHandler
    def_irq_handler    DMA1_CH0_DriverIRQHandler
    def_irq_handler    DMA1_CH1_DriverIRQHandler
    def_irq_handler    DMA1_CH2_DriverIRQHandler
    def_irq_handler    DMA1_CH3_DriverIRQHandler
    def_irq_handler    Reserved116_DriverIRQHandler
    def_irq_handler    Reserved117_DriverIRQHandler
    def_irq_handler    Reserved118_DriverIRQHandler
    def_irq_handler    Reserved119_DriverIRQHandler
    def_irq_handler    Reserved120_DriverIRQHandler
    def_irq_handler    Reserved121_DriverIRQHandler
    def_irq_handler    Reserved122_DriverIRQHandler
    def_irq_handler    Reserved123_DriverIRQHandler
    def_irq_handler    Reserved124_DriverIRQHandler
    def_irq_handler    Reserved125_DriverIRQHandler
    def_irq_handler    PKC_DriverIRQHandler
    def_irq_handler    SGI_DriverIRQHandler
    def_irq_handler    TRNG_DriverIRQHandler
    def_irq_handler    ERR_SGI_UDF_TRNG_PKC_DriverIRQHandler
    def_irq_handler    HYPERVISOR_DriverIRQHandler
    def_irq_handler    Reserved131_DriverIRQHandler
    def_irq_handler    Reserved132_DriverIRQHandler
    def_irq_handler    Reserved133_DriverIRQHandler
    def_irq_handler    Reserved134_DriverIRQHandler
    def_irq_handler    Reserved135_DriverIRQHandler
    def_irq_handler    Reserved136_DriverIRQHandler
    def_irq_handler    Reserved137_DriverIRQHandler
    def_irq_handler    Reserved138_DriverIRQHandler
    def_irq_handler    Reserved139_DriverIRQHandler
    def_irq_handler    Reserved140_DriverIRQHandler
    def_irq_handler    Reserved141_DriverIRQHandler
    def_irq_handler    Reserved142_DriverIRQHandler
    def_irq_handler    Reserved143_DriverIRQHandler
    def_irq_handler    LPI2C0_AON_DriverIRQHandler
    def_irq_handler    Reserved145_DriverIRQHandler
    def_irq_handler    LPUART0_AON_DriverIRQHandler
    def_irq_handler    Reserved147_DriverIRQHandler
    def_irq_handler    GPIO00_AON_DriverIRQHandler
    def_irq_handler    GPIO01_AON_DriverIRQHandler
    def_irq_handler    Reserved150_DriverIRQHandler
    def_irq_handler    Reserved151_DriverIRQHandler
    def_irq_handler    Reserved152_DriverIRQHandler
    def_irq_handler    Reserved153_DriverIRQHandler
    def_irq_handler    Reserved154_DriverIRQHandler
    def_irq_handler    LPCMP_DriverIRQHandler
    def_irq_handler    RTC_ALARM0_DriverIRQHandler
    def_irq_handler    RTC_ALARM1_DriverIRQHandler
    def_irq_handler    RTC_ALARM2_DriverIRQHandler
    def_irq_handler    RTC_WDT_DriverIRQHandler
    def_irq_handler    RTC_XTAL_DriverIRQHandler
    def_irq_handler    Reserved161_DriverIRQHandler
    def_irq_handler    Reserved162_DriverIRQHandler
    def_irq_handler    Reserved163_DriverIRQHandler
    def_irq_handler    KPP_DriverIRQHandler
    def_irq_handler    LPADC_AON_DriverIRQHandler
    def_irq_handler    Reserved166_DriverIRQHandler
    def_irq_handler    TMR0_AON_DriverIRQHandler
    def_irq_handler    TMR1_AON_DriverIRQHandler
    def_irq_handler    Reserved169_DriverIRQHandler
    def_irq_handler    LCSENSE_DriverIRQHandler
    def_irq_handler    LPTMR_AON_DriverIRQHandler
    def_irq_handler    Reserved172_DriverIRQHandler
    def_irq_handler    CMP0_AON_DriverIRQHandler
    def_irq_handler    ADVC_DriverIRQHandler
    def_irq_handler    Reserved175_DriverIRQHandler
    def_irq_handler    SGLCD_FRAME_AON_DriverIRQHandler
    def_irq_handler    SGLCD_FFAULT_AON_DriverIRQHandler

    .end
