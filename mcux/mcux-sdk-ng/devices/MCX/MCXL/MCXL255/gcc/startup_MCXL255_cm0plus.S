/* ------------------------------------------------------------------------- */
/*  @file:    startup_MCXL255_cm0plus.s                                      */
/*  @purpose: CMSIS Cortex-M0P Core Device Startup File                      */
/*            MCXL255_cm0plus                                                */
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
    .arch armv6-m

    .section .isr_vector, "a"
    .align 2
    .globl __Vectors
__Vectors:
    .long   __StackTop                                      /* Top of Stack */
    .long   Reset_Handler                                   /* Reset Handler */
    .long   NMI_Handler                                     /* NMI Handler*/
    .long   HardFault_Handler                               /* Hard Fault Handler*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   SVC_Handler                                     /* SVCall Handler*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   PendSV_Handler                                  /* PendSV Handler*/
    .long   SysTick_Handler                                 /* SysTick Handler*/

                                                            /* External Interrupts*/
    .long   Reserved16_IRQHandler                           /* xxx Interrupt 16*/
    .long   LPI2C0_AON_IRQHandler                           /* Low-Power Inter Integrated Circuit interrupt*/
    .long   Reserved18_IRQHandler                           /* xxx Interrupt 18*/
    .long   LPUART0_AON_IRQHandler                          /* Low-Power Universal Asynchronous Receive/Transmit interrupt*/
    .long   Reserved20_IRQHandler                           /* xxx Interrupt 20*/
    .long   GPIO00_AON_IRQHandler                           /* General Purpose Input/Output interrupt 0*/
    .long   Reserved22_IRQHandler                           /* xxx Interrupt 22*/
    .long   MU_B_TX_IRQHandler                              /* Ored tx interrupt to MUB*/
    .long   MU_B_RX_IRQHandler                              /* Ored rx interrupt to MUB*/
    .long   MU_B_INT_IRQHandler                             /* ORed general purpose interrupt request to MUB*/
    .long   SMM_IRQHandler                                  /* SMM IRQ*/
    .long   SNS_IRQHandler                                  /* SNS - first fail test finish*/
    .long   LPCMP_IRQHandler                                /* Comparator*/
    .long   RTC_ALARM0_IRQHandler                           /* RTC alarm 0*/
    .long   RTC_ALARM1_IRQHandler                           /* RTC alarm 1*/
    .long   RTC_ALARM2_IRQHandler                           /* RTC alarm 2*/
    .long   RTC_WDT_IRQHandler                              /* RTC watchdog*/
    .long   RTC_XTAL_IRQHandler                             /* RTC XTAL Fail*/
    .long   SMM_EXT_IRQHandler                              /* External interrupt*/
    .long   CGU_IRQHandler                                  /* CGU IRQ*/
    .long   PMU_IRQHandler                                  /* PMU IRQ*/
    .long   KPP_IRQHandler                                  /* Keypad Interrupt*/
    .long   LPADC_AON_IRQHandler                            /* Analog-to-Digital Converter interrupt*/
    .long   SGLCD_AON_IRQHandler                            /* SLCD frame start interrupt*/
    .long   TMR0_AON_IRQHandler                             /* ORed QTMR Interrupts*/
    .long   TMR1_AON_IRQHandler                             /* ORed QTMR Interrupts*/
    .long   Reserved42_IRQHandler                           /* xxx Interrupt 42*/
    .long   LCSENSE_IRQHandler                              /* LCSense Fault/Tamper Interrupt*/
    .long   LPTMR_AON_IRQHandler                            /* Low Power Timer 0 interrupt*/
    .long   Reserved45_IRQHandler                           /* xxx Interrupt 45*/
    .long   CMP0_AON_IRQHandler                             /* Comparator interrupt*/
    .long   ADVC_IRQHandler                                 /* ADVC_2.0 Controller Interrupt*/

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

    subs    r3, r2
    ble     .LC0

.LC1:
    subs    r3, 4
    ldr    r0, [r1,r3]
    str    r0, [r2,r3]
    bgt    .LC1
.LC0:

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

    subs    r2, r1
    ble .LC3

    movs    r0, 0
.LC2:
    subs    r2, 4
    str r0, [r1, r2]
    bgt .LC2
.LC3:
#endif
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
    ldr r0, =DefaultISR
    bx r0
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
    .weak LPI2C0_AON_IRQHandler
    .type LPI2C0_AON_IRQHandler, %function
LPI2C0_AON_IRQHandler:
    ldr   r0,=LPI2C0_AON_DriverIRQHandler
    bx    r0
    .size LPI2C0_AON_IRQHandler, . - LPI2C0_AON_IRQHandler

    .align 1
    .thumb_func
    .weak Reserved18_IRQHandler
    .type Reserved18_IRQHandler, %function
Reserved18_IRQHandler:
    ldr   r0,=Reserved18_DriverIRQHandler
    bx    r0
    .size Reserved18_IRQHandler, . - Reserved18_IRQHandler

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
    .weak Reserved20_IRQHandler
    .type Reserved20_IRQHandler, %function
Reserved20_IRQHandler:
    ldr   r0,=Reserved20_DriverIRQHandler
    bx    r0
    .size Reserved20_IRQHandler, . - Reserved20_IRQHandler

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
    .weak Reserved22_IRQHandler
    .type Reserved22_IRQHandler, %function
Reserved22_IRQHandler:
    ldr   r0,=Reserved22_DriverIRQHandler
    bx    r0
    .size Reserved22_IRQHandler, . - Reserved22_IRQHandler

    .align 1
    .thumb_func
    .weak MU_B_TX_IRQHandler
    .type MU_B_TX_IRQHandler, %function
MU_B_TX_IRQHandler:
    ldr   r0,=MU_B_TX_DriverIRQHandler
    bx    r0
    .size MU_B_TX_IRQHandler, . - MU_B_TX_IRQHandler

    .align 1
    .thumb_func
    .weak MU_B_RX_IRQHandler
    .type MU_B_RX_IRQHandler, %function
MU_B_RX_IRQHandler:
    ldr   r0,=MU_B_RX_DriverIRQHandler
    bx    r0
    .size MU_B_RX_IRQHandler, . - MU_B_RX_IRQHandler

    .align 1
    .thumb_func
    .weak MU_B_INT_IRQHandler
    .type MU_B_INT_IRQHandler, %function
MU_B_INT_IRQHandler:
    ldr   r0,=MU_B_INT_DriverIRQHandler
    bx    r0
    .size MU_B_INT_IRQHandler, . - MU_B_INT_IRQHandler

    .align 1
    .thumb_func
    .weak SMM_IRQHandler
    .type SMM_IRQHandler, %function
SMM_IRQHandler:
    ldr   r0,=SMM_DriverIRQHandler
    bx    r0
    .size SMM_IRQHandler, . - SMM_IRQHandler

    .align 1
    .thumb_func
    .weak SNS_IRQHandler
    .type SNS_IRQHandler, %function
SNS_IRQHandler:
    ldr   r0,=SNS_DriverIRQHandler
    bx    r0
    .size SNS_IRQHandler, . - SNS_IRQHandler

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
    .weak SMM_EXT_IRQHandler
    .type SMM_EXT_IRQHandler, %function
SMM_EXT_IRQHandler:
    ldr   r0,=SMM_EXT_DriverIRQHandler
    bx    r0
    .size SMM_EXT_IRQHandler, . - SMM_EXT_IRQHandler

    .align 1
    .thumb_func
    .weak CGU_IRQHandler
    .type CGU_IRQHandler, %function
CGU_IRQHandler:
    ldr   r0,=CGU_DriverIRQHandler
    bx    r0
    .size CGU_IRQHandler, . - CGU_IRQHandler

    .align 1
    .thumb_func
    .weak PMU_IRQHandler
    .type PMU_IRQHandler, %function
PMU_IRQHandler:
    ldr   r0,=PMU_DriverIRQHandler
    bx    r0
    .size PMU_IRQHandler, . - PMU_IRQHandler

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
    .weak SGLCD_AON_IRQHandler
    .type SGLCD_AON_IRQHandler, %function
SGLCD_AON_IRQHandler:
    ldr   r0,=SGLCD_AON_DriverIRQHandler
    bx    r0
    .size SGLCD_AON_IRQHandler, . - SGLCD_AON_IRQHandler

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
    .weak Reserved42_IRQHandler
    .type Reserved42_IRQHandler, %function
Reserved42_IRQHandler:
    ldr   r0,=Reserved42_DriverIRQHandler
    bx    r0
    .size Reserved42_IRQHandler, . - Reserved42_IRQHandler

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
    .weak Reserved45_IRQHandler
    .type Reserved45_IRQHandler, %function
Reserved45_IRQHandler:
    ldr   r0,=Reserved45_DriverIRQHandler
    bx    r0
    .size Reserved45_IRQHandler, . - Reserved45_IRQHandler

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


/*    Macro to define default handlers. Default handler
 *    will be weak symbol and just dead loops. They can be
 *    overwritten by other handlers */
    .macro def_irq_handler  handler_name
    .weak \handler_name
    .set  \handler_name, DefaultISR
    .endm
/* Exception Handlers */
    def_irq_handler    Reserved16_DriverIRQHandler
    def_irq_handler    LPI2C0_AON_DriverIRQHandler
    def_irq_handler    Reserved18_DriverIRQHandler
    def_irq_handler    LPUART0_AON_DriverIRQHandler
    def_irq_handler    Reserved20_DriverIRQHandler
    def_irq_handler    GPIO00_AON_DriverIRQHandler
    def_irq_handler    Reserved22_DriverIRQHandler
    def_irq_handler    MU_B_TX_DriverIRQHandler
    def_irq_handler    MU_B_RX_DriverIRQHandler
    def_irq_handler    MU_B_INT_DriverIRQHandler
    def_irq_handler    SMM_DriverIRQHandler
    def_irq_handler    SNS_DriverIRQHandler
    def_irq_handler    LPCMP_DriverIRQHandler
    def_irq_handler    RTC_ALARM0_DriverIRQHandler
    def_irq_handler    RTC_ALARM1_DriverIRQHandler
    def_irq_handler    RTC_ALARM2_DriverIRQHandler
    def_irq_handler    RTC_WDT_DriverIRQHandler
    def_irq_handler    RTC_XTAL_DriverIRQHandler
    def_irq_handler    SMM_EXT_DriverIRQHandler
    def_irq_handler    CGU_DriverIRQHandler
    def_irq_handler    PMU_DriverIRQHandler
    def_irq_handler    KPP_DriverIRQHandler
    def_irq_handler    LPADC_AON_DriverIRQHandler
    def_irq_handler    SGLCD_AON_DriverIRQHandler
    def_irq_handler    TMR0_AON_DriverIRQHandler
    def_irq_handler    TMR1_AON_DriverIRQHandler
    def_irq_handler    Reserved42_DriverIRQHandler
    def_irq_handler    LCSENSE_DriverIRQHandler
    def_irq_handler    LPTMR_AON_DriverIRQHandler
    def_irq_handler    Reserved45_DriverIRQHandler
    def_irq_handler    CMP0_AON_DriverIRQHandler
    def_irq_handler    ADVC_DriverIRQHandler

    .end
