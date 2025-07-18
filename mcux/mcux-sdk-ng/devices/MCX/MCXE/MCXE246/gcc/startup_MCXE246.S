/* ------------------------------------------------------------------------- */
/*  @file:    startup_MCXE246.s                                              */
/*  @purpose: CMSIS Cortex-M4 Core Device Startup File                       */
/*            MCXE246                                                        */
/*  @version: 1.0                                                            */
/*  @date:    2025-2-21                                                      */
/*  @build:   b250424                                                        */
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
    .long   DMA0_IRQHandler                                 /* DMA channel 0 transfer complete*/
    .long   DMA1_IRQHandler                                 /* DMA channel 1 transfer complete*/
    .long   DMA2_IRQHandler                                 /* DMA channel 2 transfer complete*/
    .long   DMA3_IRQHandler                                 /* DMA channel 3 transfer complete*/
    .long   DMA4_IRQHandler                                 /* DMA channel 4 transfer complete*/
    .long   DMA5_IRQHandler                                 /* DMA channel 5 transfer complete*/
    .long   DMA6_IRQHandler                                 /* DMA channel 6 transfer complete*/
    .long   DMA7_IRQHandler                                 /* DMA channel 7 transfer complete*/
    .long   DMA8_IRQHandler                                 /* DMA channel 8 transfer complete*/
    .long   DMA9_IRQHandler                                 /* DMA channel 9 transfer complete*/
    .long   DMA10_IRQHandler                                /* DMA channel 10 transfer complete*/
    .long   DMA11_IRQHandler                                /* DMA channel 11 transfer complete*/
    .long   DMA12_IRQHandler                                /* DMA channel 12 transfer complete*/
    .long   DMA13_IRQHandler                                /* DMA channel 13 transfer complete*/
    .long   DMA14_IRQHandler                                /* DMA channel 14 transfer complete*/
    .long   DMA15_IRQHandler                                /* DMA channel 15 transfer complete*/
    .long   DMA_Error_IRQHandler                            /* DMA error interrupt channels 0-15*/
    .long   MCM_IRQHandler                                  /* FPU sources*/
    .long   FTFC_CMD_IRQHandler                             /* FTFC Command complete*/
    .long   FTFC_Read_Collision_IRQHandler                  /* FTFC Read collision*/
    .long   LVD_LVW_IRQHandler                              /* PMC Low voltage detect interrupt*/
    .long   FTFM_Fault_IRQHandler                           /* FTFM Double bit fault detect*/
    .long   WDOG_EWM_IRQHandler                             /* Interrupt request out before WDOG reset out, EWM output as interrupt*/
    .long   RCM_IRQHandler                                  /* RCM Asynchronous Interrupt*/
    .long   LPI2C0_Master_IRQHandler                        /* LPI2C0 Master Interrupt*/
    .long   LPI2C0_Slave_IRQHandler                         /* LPI2C0 Slave Interrupt*/
    .long   LPSPI0_IRQHandler                               /* LPSPI0 Interrupt*/
    .long   LPSPI1_IRQHandler                               /* LPSPI1 Interrupt*/
    .long   LPSPI2_IRQHandler                               /* LPSPI2 Interrupt*/
    .long   Reserved45_IRQHandler                           /* xxx Interrupt 45*/
    .long   Reserved46_IRQHandler                           /* xxx Interrupt 46*/
    .long   LPUART0_IRQHandler                              /* Low-Power Universal Asynchronous Receive/Transmit interrupt*/
    .long   Reserved48_IRQHandler                           /* xxx Interrupt 48*/
    .long   LPUART1_IRQHandler                              /* Low-Power Universal Asynchronous Receive/Transmit interrupt*/
    .long   Reserved50_IRQHandler                           /* xxx Interrupt 50*/
    .long   LPUART2_IRQHandler                              /* Low-Power Universal Asynchronous Receive/Transmit interrupt*/
    .long   Reserved52_IRQHandler                           /* xxx Interrupt 52*/
    .long   Reserved53_IRQHandler                           /* xxx Interrupt 53*/
    .long   Reserved54_IRQHandler                           /* xxx Interrupt 54*/
    .long   ADC0_IRQHandler                                 /* Analog-to-Digital Converter interrupt*/
    .long   ADC1_IRQHandler                                 /* Analog-to-Digital Converter interrupt*/
    .long   CMP0_IRQHandler                                 /* Comparator interrupt*/
    .long   Reserved58_IRQHandler                           /* xxx Interrupt 58*/
    .long   Reserved59_IRQHandler                           /* xxx Interrupt 59*/
    .long   ERM_single_fault_IRQHandler                     /* ERM single bit error correction*/
    .long   ERM_double_fault_IRQHandler                     /* ERM double bit error non-correctable*/
    .long   RTC_IRQHandler                                  /* RTC alarm interrupt*/
    .long   RTC_Seconds_IRQHandler                          /* RTC seconds interrupt*/
    .long   LPIT0_Ch0_IRQHandler                            /* LPIT0 channel 0 overflow interrupt*/
    .long   LPIT0_Ch1_IRQHandler                            /* LPIT0 channel 1 overflow interrupt*/
    .long   LPIT0_Ch2_IRQHandler                            /* LPIT0 channel 2 overflow interrupt*/
    .long   LPIT0_Ch3_IRQHandler                            /* LPIT0 channel 3 overflow interrupt*/
    .long   PDB0_IRQHandler                                 /* PDB0 interrupt*/
    .long   Reserved69_IRQHandler                           /* xxx Interrupt 69*/
    .long   Reserved70_IRQHandler                           /* xxx Interrupt 70*/
    .long   Reserved71_IRQHandler                           /* xxx Interrupt 71*/
    .long   Reserved72_IRQHandler                           /* xxx Interrupt 72*/
    .long   SCG_IRQHandler                                  /* SCG bus interrupt request*/
    .long   LPTMR0_IRQHandler                               /* LPTIMER interrupt request*/
    .long   PORTA_IRQHandler                                /* Port A pin detect interrupt*/
    .long   PORTB_IRQHandler                                /* Port B pin detect interrupt*/
    .long   PORTC_IRQHandler                                /* Port C pin detect interrupt*/
    .long   PORTD_IRQHandler                                /* Port D pin detect interrupt*/
    .long   PORTE_IRQHandler                                /* Port E pin detect interrupt*/
    .long   SWI_IRQHandler                                  /* Software interrupt*/
    .long   Reserved81_IRQHandler                           /* xxx Interrupt 81*/
    .long   Reserved82_IRQHandler                           /* xxx Interrupt 82*/
    .long   Reserved83_IRQHandler                           /* xxx Interrupt 83*/
    .long   PDB1_IRQHandler                                 /* PDB1 interrupt*/
    .long   FLEXIO_IRQHandler                               /* Software interrupt*/
    .long   Reserved86_IRQHandler                           /* xxx Interrupt 86*/
    .long   Reserved87_IRQHandler                           /* xxx Interrupt 87*/
    .long   Reserved88_IRQHandler                           /* xxx Interrupt 88*/
    .long   Reserved89_IRQHandler                           /* xxx Interrupt 89*/
    .long   Reserved90_IRQHandler                           /* xxx Interrupt 90*/
    .long   Reserved91_IRQHandler                           /* xxx Interrupt 91*/
    .long   Reserved92_IRQHandler                           /* xxx Interrupt 92*/
    .long   Reserved93_IRQHandler                           /* xxx Interrupt 93*/
    .long   CAN0_ORed_IRQHandler                            /* CAN0 OR'ed interrupt*/
    .long   CAN0_Error_IRQHandler                           /* CAN0 Interrupt indicating that errors were detected on the CAN bus*/
    .long   CAN0_Wake_Up_IRQHandler                         /* CAN0 Interrupt asserted when Pretended Networking operation is enabled, and a valid message matches the selected filter criteria during Low Power mode*/
    .long   CAN0_ORed_0_15_MB_IRQHandler                    /* CAN0 OR'ed Message buffer (0-15)*/
    .long   CAN0_ORed_16_31_MB_IRQHandler                   /* CAN0 OR'ed Message buffer (16-31)*/
    .long   Reserved99_IRQHandler                           /* xxx Interrupt 99*/
    .long   Reserved100_IRQHandler                          /* xxx Interrupt 100*/
    .long   CAN1_ORed_IRQHandler                            /* CAN1 OR'ed interrupt*/
    .long   CAN1_Error_IRQHandler                           /* CAN1 Interrupt indicating that errors were detected on the CAN bus*/
    .long   Reserved103_IRQHandler                          /* xxx Interrupt 103*/
    .long   CAN1_ORed_0_15_MB_IRQHandler                    /* CAN1 OR'ed Message buffer (0-15)*/
    .long   CAN1_ORed_16_31_MB_IRQHandler                   /* CAN1 OR'ed Message buffer (16-31)*/
    .long   Reserved106_IRQHandler                          /* xxx Interrupt 106*/
    .long   Reserved107_IRQHandler                          /* xxx Interrupt 107*/
    .long   CAN2_ORed_IRQHandler                            /* CAN2 OR'ed interrupt*/
    .long   CAN2_Error_IRQHandler                           /* CAN2 Interrupt indicating that errors were detected on the CAN bus*/
    .long   Reserved110_IRQHandler                          /* xxx Interrupt 110*/
    .long   CAN2_ORed_0_15_MB_IRQHandler                    /* CAN2 OR'ed Message buffer (0-15)*/
    .long   CAN2_ORed_16_31_MB_IRQHandler                   /* CAN2 OR'ed Message buffer (16-31)*/
    .long   Reserved113_IRQHandler                          /* xxx Interrupt 113*/
    .long   Reserved114_IRQHandler                          /* xxx Interrupt 114*/
    .long   FTM0_Ch0_Ch1_IRQHandler                         /* FTM0 Channel 0 and 1 interrupt*/
    .long   FTM0_Ch2_Ch3_IRQHandler                         /* FTM0 Channel 2 and 3 interrupt*/
    .long   FTM0_Ch4_Ch5_IRQHandler                         /* FTM0 Channel 4 and 5 interrupt*/
    .long   FTM0_Ch6_Ch7_IRQHandler                         /* FTM0 Channel 6 and 7 interrupt*/
    .long   FTM0_Fault_IRQHandler                           /* FTM0 Fault interrupt*/
    .long   FTM0_Ovf_Reload_IRQHandler                      /* FTM0 Counter overflow and Reload interrupt*/
    .long   FTM1_Ch0_Ch1_IRQHandler                         /* FTM1 Channel 0 and 1 interrupt*/
    .long   FTM1_Ch2_Ch3_IRQHandler                         /* FTM1 Channel 2 and 3 interrupt*/
    .long   FTM1_Ch4_Ch5_IRQHandler                         /* FTM1 Channel 4 and 5 interrupt*/
    .long   FTM1_Ch6_Ch7_IRQHandler                         /* FTM1 Channel 6 and 7 interrupt*/
    .long   FTM1_Fault_IRQHandler                           /* FTM1 Fault interrupt*/
    .long   FTM1_Ovf_Reload_IRQHandler                      /* FTM1 Counter overflow and Reload interrupt*/
    .long   FTM2_Ch0_Ch1_IRQHandler                         /* FTM2 Channel 0 and 1 interrupt*/
    .long   FTM2_Ch2_Ch3_IRQHandler                         /* FTM2 Channel 2 and 3 interrupt*/
    .long   FTM2_Ch4_Ch5_IRQHandler                         /* FTM2 Channel 4 and 5 interrupt*/
    .long   FTM2_Ch6_Ch7_IRQHandler                         /* FTM2 Channel 6 and 7 interrupt*/
    .long   FTM2_Fault_IRQHandler                           /* FTM2 Fault interrupt*/
    .long   FTM2_Ovf_Reload_IRQHandler                      /* FTM2 Counter overflow and Reload interrupt*/
    .long   FTM3_Ch0_Ch1_IRQHandler                         /* FTM3 Channel 0 and 1 interrupt*/
    .long   FTM3_Ch2_Ch3_IRQHandler                         /* FTM3 Channel 2 and 3 interrupt*/
    .long   FTM3_Ch4_Ch5_IRQHandler                         /* FTM3 Channel 4 and 5 interrupt*/
    .long   FTM3_Ch6_Ch7_IRQHandler                         /* FTM3 Channel 6 and 7 interrupt*/
    .long   FTM3_Fault_IRQHandler                           /* FTM3 Fault interrupt*/
    .long   FTM3_Ovf_Reload_IRQHandler                      /* FTM3 Counter overflow and Reload interrupt*/
    .long   FTM4_Ch0_Ch1_IRQHandler                         /* FTM4 Channel 0 and 1 interrupt*/
    .long   FTM4_Ch2_Ch3_IRQHandler                         /* FTM4 Channel 2 and 3 interrupt*/
    .long   FTM4_Ch4_Ch5_IRQHandler                         /* FTM4 Channel 4 and 5 interrupt*/
    .long   FTM4_Ch6_Ch7_IRQHandler                         /* FTM4 Channel 6 and 7 interrupt*/
    .long   FTM4_Fault_IRQHandler                           /* FTM4 Fault interrupt*/
    .long   FTM4_Ovf_Reload_IRQHandler                      /* FTM4 Counter overflow and Reload interrupt*/
    .long   FTM5_Ch0_Ch1_IRQHandler                         /* FTM5 Channel 0 and 1 interrupt*/
    .long   FTM5_Ch2_Ch3_IRQHandler                         /* FTM5 Channel 2 and 3 interrupt*/
    .long   FTM5_Ch4_Ch5_IRQHandler                         /* FTM5 Channel 4 and 5 interrupt*/
    .long   FTM5_Ch6_Ch7_IRQHandler                         /* FTM5 Channel 6 and 7 interrupt*/
    .long   FTM5_Fault_IRQHandler                           /* FTM5 Fault interrupt*/
    .long   FTM5_Ovf_Reload_IRQHandler                      /* FTM5 Counter overflow and Reload interrupt*/
    .long   DefaultISR                                      /* 151*/
    .long   DefaultISR                                      /* 152*/
    .long   DefaultISR                                      /* 153*/
    .long   DefaultISR                                      /* 154*/
    .long   DefaultISR                                      /* 155*/
    .long   DefaultISR                                      /* 156*/
    .long   DefaultISR                                      /* 157*/
    .long   DefaultISR                                      /* 158*/
    .long   DefaultISR                                      /* 159*/
    .long   DefaultISR                                      /* 160*/
    .long   DefaultISR                                      /* 161*/
    .long   DefaultISR                                      /* 162*/
    .long   DefaultISR                                      /* 163*/
    .long   DefaultISR                                      /* 164*/
    .long   DefaultISR                                      /* 165*/
    .long   DefaultISR                                      /* 166*/
    .long   DefaultISR                                      /* 167*/
    .long   DefaultISR                                      /* 168*/
    .long   DefaultISR                                      /* 169*/
    .long   DefaultISR                                      /* 170*/
    .long   DefaultISR                                      /* 171*/
    .long   DefaultISR                                      /* 172*/
    .long   DefaultISR                                      /* 173*/
    .long   DefaultISR                                      /* 174*/
    .long   DefaultISR                                      /* 175*/
    .long   DefaultISR                                      /* 176*/
    .long   DefaultISR                                      /* 177*/
    .long   DefaultISR                                      /* 178*/
    .long   DefaultISR                                      /* 179*/
    .long   DefaultISR                                      /* 180*/
    .long   DefaultISR                                      /* 181*/
    .long   DefaultISR                                      /* 182*/
    .long   DefaultISR                                      /* 183*/
    .long   DefaultISR                                      /* 184*/
    .long   DefaultISR                                      /* 185*/
    .long   DefaultISR                                      /* 186*/
    .long   DefaultISR                                      /* 187*/
    .long   DefaultISR                                      /* 188*/
    .long   DefaultISR                                      /* 189*/
    .long   DefaultISR                                      /* 190*/
    .long   DefaultISR                                      /* 191*/
    .long   DefaultISR                                      /* 192*/
    .long   DefaultISR                                      /* 193*/
    .long   DefaultISR                                      /* 194*/
    .long   DefaultISR                                      /* 195*/
    .long   DefaultISR                                      /* 196*/
    .long   DefaultISR                                      /* 197*/
    .long   DefaultISR                                      /* 198*/
    .long   DefaultISR                                      /* 199*/
    .long   DefaultISR                                      /* 200*/
    .long   DefaultISR                                      /* 201*/
    .long   DefaultISR                                      /* 202*/
    .long   DefaultISR                                      /* 203*/
    .long   DefaultISR                                      /* 204*/
    .long   DefaultISR                                      /* 205*/
    .long   DefaultISR                                      /* 206*/
    .long   DefaultISR                                      /* 207*/
    .long   DefaultISR                                      /* 208*/
    .long   DefaultISR                                      /* 209*/
    .long   DefaultISR                                      /* 210*/
    .long   DefaultISR                                      /* 211*/
    .long   DefaultISR                                      /* 212*/
    .long   DefaultISR                                      /* 213*/
    .long   DefaultISR                                      /* 214*/
    .long   DefaultISR                                      /* 215*/
    .long   DefaultISR                                      /* 216*/
    .long   DefaultISR                                      /* 217*/
    .long   DefaultISR                                      /* 218*/
    .long   DefaultISR                                      /* 219*/
    .long   DefaultISR                                      /* 220*/
    .long   DefaultISR                                      /* 221*/
    .long   DefaultISR                                      /* 222*/
    .long   DefaultISR                                      /* 223*/
    .long   DefaultISR                                      /* 224*/
    .long   DefaultISR                                      /* 225*/
    .long   DefaultISR                                      /* 226*/
    .long   DefaultISR                                      /* 227*/
    .long   DefaultISR                                      /* 228*/
    .long   DefaultISR                                      /* 229*/
    .long   DefaultISR                                      /* 230*/
    .long   DefaultISR                                      /* 231*/
    .long   DefaultISR                                      /* 232*/
    .long   DefaultISR                                      /* 233*/
    .long   DefaultISR                                      /* 234*/
    .long   DefaultISR                                      /* 235*/
    .long   DefaultISR                                      /* 236*/
    .long   DefaultISR                                      /* 237*/
    .long   DefaultISR                                      /* 238*/
    .long   DefaultISR                                      /* 239*/
    .long   DefaultISR                                      /* 240*/
    .long   DefaultISR                                      /* 241*/
    .long   DefaultISR                                      /* 242*/
    .long   DefaultISR                                      /* 243*/
    .long   DefaultISR                                      /* 244*/
    .long   DefaultISR                                      /* 245*/
    .long   DefaultISR                                      /* 246*/
    .long   DefaultISR                                      /* 247*/
    .long   DefaultISR                                      /* 248*/
    .long   DefaultISR                                      /* 249*/
    .long   DefaultISR                                      /* 250*/
    .long   DefaultISR                                      /* 251*/
    .long   DefaultISR                                      /* 252*/
    .long   DefaultISR                                      /* 253*/
    .long   DefaultISR                                      /* 254*/
    .long   0xFFFFFFFF                                      /*  Reserved for user TRIM value*/

    .size   __isr_vector, . - __isr_vector

/* Flash Configuration */
    .section .FlashConfig, "a"
    .long 0xFFFFFFFF
    .long 0xFFFFFFFF
    .long 0xFFFFFFFF
    .long 0xFFFFFFFE

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
    .weak DMA0_IRQHandler
    .type DMA0_IRQHandler, %function
DMA0_IRQHandler:
    ldr   r0,=DMA0_DriverIRQHandler
    bx    r0
    .size DMA0_IRQHandler, . - DMA0_IRQHandler

    .align 1
    .thumb_func
    .weak DMA1_IRQHandler
    .type DMA1_IRQHandler, %function
DMA1_IRQHandler:
    ldr   r0,=DMA1_DriverIRQHandler
    bx    r0
    .size DMA1_IRQHandler, . - DMA1_IRQHandler

    .align 1
    .thumb_func
    .weak DMA2_IRQHandler
    .type DMA2_IRQHandler, %function
DMA2_IRQHandler:
    ldr   r0,=DMA2_DriverIRQHandler
    bx    r0
    .size DMA2_IRQHandler, . - DMA2_IRQHandler

    .align 1
    .thumb_func
    .weak DMA3_IRQHandler
    .type DMA3_IRQHandler, %function
DMA3_IRQHandler:
    ldr   r0,=DMA3_DriverIRQHandler
    bx    r0
    .size DMA3_IRQHandler, . - DMA3_IRQHandler

    .align 1
    .thumb_func
    .weak DMA4_IRQHandler
    .type DMA4_IRQHandler, %function
DMA4_IRQHandler:
    ldr   r0,=DMA4_DriverIRQHandler
    bx    r0
    .size DMA4_IRQHandler, . - DMA4_IRQHandler

    .align 1
    .thumb_func
    .weak DMA5_IRQHandler
    .type DMA5_IRQHandler, %function
DMA5_IRQHandler:
    ldr   r0,=DMA5_DriverIRQHandler
    bx    r0
    .size DMA5_IRQHandler, . - DMA5_IRQHandler

    .align 1
    .thumb_func
    .weak DMA6_IRQHandler
    .type DMA6_IRQHandler, %function
DMA6_IRQHandler:
    ldr   r0,=DMA6_DriverIRQHandler
    bx    r0
    .size DMA6_IRQHandler, . - DMA6_IRQHandler

    .align 1
    .thumb_func
    .weak DMA7_IRQHandler
    .type DMA7_IRQHandler, %function
DMA7_IRQHandler:
    ldr   r0,=DMA7_DriverIRQHandler
    bx    r0
    .size DMA7_IRQHandler, . - DMA7_IRQHandler

    .align 1
    .thumb_func
    .weak DMA8_IRQHandler
    .type DMA8_IRQHandler, %function
DMA8_IRQHandler:
    ldr   r0,=DMA8_DriverIRQHandler
    bx    r0
    .size DMA8_IRQHandler, . - DMA8_IRQHandler

    .align 1
    .thumb_func
    .weak DMA9_IRQHandler
    .type DMA9_IRQHandler, %function
DMA9_IRQHandler:
    ldr   r0,=DMA9_DriverIRQHandler
    bx    r0
    .size DMA9_IRQHandler, . - DMA9_IRQHandler

    .align 1
    .thumb_func
    .weak DMA10_IRQHandler
    .type DMA10_IRQHandler, %function
DMA10_IRQHandler:
    ldr   r0,=DMA10_DriverIRQHandler
    bx    r0
    .size DMA10_IRQHandler, . - DMA10_IRQHandler

    .align 1
    .thumb_func
    .weak DMA11_IRQHandler
    .type DMA11_IRQHandler, %function
DMA11_IRQHandler:
    ldr   r0,=DMA11_DriverIRQHandler
    bx    r0
    .size DMA11_IRQHandler, . - DMA11_IRQHandler

    .align 1
    .thumb_func
    .weak DMA12_IRQHandler
    .type DMA12_IRQHandler, %function
DMA12_IRQHandler:
    ldr   r0,=DMA12_DriverIRQHandler
    bx    r0
    .size DMA12_IRQHandler, . - DMA12_IRQHandler

    .align 1
    .thumb_func
    .weak DMA13_IRQHandler
    .type DMA13_IRQHandler, %function
DMA13_IRQHandler:
    ldr   r0,=DMA13_DriverIRQHandler
    bx    r0
    .size DMA13_IRQHandler, . - DMA13_IRQHandler

    .align 1
    .thumb_func
    .weak DMA14_IRQHandler
    .type DMA14_IRQHandler, %function
DMA14_IRQHandler:
    ldr   r0,=DMA14_DriverIRQHandler
    bx    r0
    .size DMA14_IRQHandler, . - DMA14_IRQHandler

    .align 1
    .thumb_func
    .weak DMA15_IRQHandler
    .type DMA15_IRQHandler, %function
DMA15_IRQHandler:
    ldr   r0,=DMA15_DriverIRQHandler
    bx    r0
    .size DMA15_IRQHandler, . - DMA15_IRQHandler

    .align 1
    .thumb_func
    .weak DMA_Error_IRQHandler
    .type DMA_Error_IRQHandler, %function
DMA_Error_IRQHandler:
    ldr   r0,=DMA_Error_DriverIRQHandler
    bx    r0
    .size DMA_Error_IRQHandler, . - DMA_Error_IRQHandler

    .align 1
    .thumb_func
    .weak LPI2C0_Master_IRQHandler
    .type LPI2C0_Master_IRQHandler, %function
LPI2C0_Master_IRQHandler:
    ldr   r0,=LPI2C0_Master_DriverIRQHandler
    bx    r0
    .size LPI2C0_Master_IRQHandler, . - LPI2C0_Master_IRQHandler

    .align 1
    .thumb_func
    .weak LPI2C0_Slave_IRQHandler
    .type LPI2C0_Slave_IRQHandler, %function
LPI2C0_Slave_IRQHandler:
    ldr   r0,=LPI2C0_Slave_DriverIRQHandler
    bx    r0
    .size LPI2C0_Slave_IRQHandler, . - LPI2C0_Slave_IRQHandler

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
    .weak LPSPI2_IRQHandler
    .type LPSPI2_IRQHandler, %function
LPSPI2_IRQHandler:
    ldr   r0,=LPSPI2_DriverIRQHandler
    bx    r0
    .size LPSPI2_IRQHandler, . - LPSPI2_IRQHandler

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
    .weak LPUART2_IRQHandler
    .type LPUART2_IRQHandler, %function
LPUART2_IRQHandler:
    ldr   r0,=LPUART2_DriverIRQHandler
    bx    r0
    .size LPUART2_IRQHandler, . - LPUART2_IRQHandler

    .align 1
    .thumb_func
    .weak FLEXIO_IRQHandler
    .type FLEXIO_IRQHandler, %function
FLEXIO_IRQHandler:
    ldr   r0,=FLEXIO_DriverIRQHandler
    bx    r0
    .size FLEXIO_IRQHandler, . - FLEXIO_IRQHandler

    .align 1
    .thumb_func
    .weak CAN0_ORed_IRQHandler
    .type CAN0_ORed_IRQHandler, %function
CAN0_ORed_IRQHandler:
    ldr   r0,=CAN0_ORed_DriverIRQHandler
    bx    r0
    .size CAN0_ORed_IRQHandler, . - CAN0_ORed_IRQHandler

    .align 1
    .thumb_func
    .weak CAN0_Error_IRQHandler
    .type CAN0_Error_IRQHandler, %function
CAN0_Error_IRQHandler:
    ldr   r0,=CAN0_Error_DriverIRQHandler
    bx    r0
    .size CAN0_Error_IRQHandler, . - CAN0_Error_IRQHandler

    .align 1
    .thumb_func
    .weak CAN0_Wake_Up_IRQHandler
    .type CAN0_Wake_Up_IRQHandler, %function
CAN0_Wake_Up_IRQHandler:
    ldr   r0,=CAN0_Wake_Up_DriverIRQHandler
    bx    r0
    .size CAN0_Wake_Up_IRQHandler, . - CAN0_Wake_Up_IRQHandler

    .align 1
    .thumb_func
    .weak CAN0_ORed_0_15_MB_IRQHandler
    .type CAN0_ORed_0_15_MB_IRQHandler, %function
CAN0_ORed_0_15_MB_IRQHandler:
    ldr   r0,=CAN0_ORed_0_15_MB_DriverIRQHandler
    bx    r0
    .size CAN0_ORed_0_15_MB_IRQHandler, . - CAN0_ORed_0_15_MB_IRQHandler

    .align 1
    .thumb_func
    .weak CAN0_ORed_16_31_MB_IRQHandler
    .type CAN0_ORed_16_31_MB_IRQHandler, %function
CAN0_ORed_16_31_MB_IRQHandler:
    ldr   r0,=CAN0_ORed_16_31_MB_DriverIRQHandler
    bx    r0
    .size CAN0_ORed_16_31_MB_IRQHandler, . - CAN0_ORed_16_31_MB_IRQHandler

    .align 1
    .thumb_func
    .weak CAN1_ORed_IRQHandler
    .type CAN1_ORed_IRQHandler, %function
CAN1_ORed_IRQHandler:
    ldr   r0,=CAN1_ORed_DriverIRQHandler
    bx    r0
    .size CAN1_ORed_IRQHandler, . - CAN1_ORed_IRQHandler

    .align 1
    .thumb_func
    .weak CAN1_Error_IRQHandler
    .type CAN1_Error_IRQHandler, %function
CAN1_Error_IRQHandler:
    ldr   r0,=CAN1_Error_DriverIRQHandler
    bx    r0
    .size CAN1_Error_IRQHandler, . - CAN1_Error_IRQHandler

    .align 1
    .thumb_func
    .weak CAN1_ORed_0_15_MB_IRQHandler
    .type CAN1_ORed_0_15_MB_IRQHandler, %function
CAN1_ORed_0_15_MB_IRQHandler:
    ldr   r0,=CAN1_ORed_0_15_MB_DriverIRQHandler
    bx    r0
    .size CAN1_ORed_0_15_MB_IRQHandler, . - CAN1_ORed_0_15_MB_IRQHandler

    .align 1
    .thumb_func
    .weak CAN1_ORed_16_31_MB_IRQHandler
    .type CAN1_ORed_16_31_MB_IRQHandler, %function
CAN1_ORed_16_31_MB_IRQHandler:
    ldr   r0,=CAN1_ORed_16_31_MB_DriverIRQHandler
    bx    r0
    .size CAN1_ORed_16_31_MB_IRQHandler, . - CAN1_ORed_16_31_MB_IRQHandler

    .align 1
    .thumb_func
    .weak CAN2_ORed_IRQHandler
    .type CAN2_ORed_IRQHandler, %function
CAN2_ORed_IRQHandler:
    ldr   r0,=CAN2_ORed_DriverIRQHandler
    bx    r0
    .size CAN2_ORed_IRQHandler, . - CAN2_ORed_IRQHandler

    .align 1
    .thumb_func
    .weak CAN2_Error_IRQHandler
    .type CAN2_Error_IRQHandler, %function
CAN2_Error_IRQHandler:
    ldr   r0,=CAN2_Error_DriverIRQHandler
    bx    r0
    .size CAN2_Error_IRQHandler, . - CAN2_Error_IRQHandler

    .align 1
    .thumb_func
    .weak CAN2_ORed_0_15_MB_IRQHandler
    .type CAN2_ORed_0_15_MB_IRQHandler, %function
CAN2_ORed_0_15_MB_IRQHandler:
    ldr   r0,=CAN2_ORed_0_15_MB_DriverIRQHandler
    bx    r0
    .size CAN2_ORed_0_15_MB_IRQHandler, . - CAN2_ORed_0_15_MB_IRQHandler

    .align 1
    .thumb_func
    .weak CAN2_ORed_16_31_MB_IRQHandler
    .type CAN2_ORed_16_31_MB_IRQHandler, %function
CAN2_ORed_16_31_MB_IRQHandler:
    ldr   r0,=CAN2_ORed_16_31_MB_DriverIRQHandler
    bx    r0
    .size CAN2_ORed_16_31_MB_IRQHandler, . - CAN2_ORed_16_31_MB_IRQHandler


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
    def_irq_handler    DMA0_DriverIRQHandler
    def_irq_handler    DMA1_DriverIRQHandler
    def_irq_handler    DMA2_DriverIRQHandler
    def_irq_handler    DMA3_DriverIRQHandler
    def_irq_handler    DMA4_DriverIRQHandler
    def_irq_handler    DMA5_DriverIRQHandler
    def_irq_handler    DMA6_DriverIRQHandler
    def_irq_handler    DMA7_DriverIRQHandler
    def_irq_handler    DMA8_DriverIRQHandler
    def_irq_handler    DMA9_DriverIRQHandler
    def_irq_handler    DMA10_DriverIRQHandler
    def_irq_handler    DMA11_DriverIRQHandler
    def_irq_handler    DMA12_DriverIRQHandler
    def_irq_handler    DMA13_DriverIRQHandler
    def_irq_handler    DMA14_DriverIRQHandler
    def_irq_handler    DMA15_DriverIRQHandler
    def_irq_handler    DMA_Error_DriverIRQHandler
    def_irq_handler    MCM_IRQHandler
    def_irq_handler    FTFC_CMD_IRQHandler
    def_irq_handler    FTFC_Read_Collision_IRQHandler
    def_irq_handler    LVD_LVW_IRQHandler
    def_irq_handler    FTFM_Fault_IRQHandler
    def_irq_handler    WDOG_EWM_IRQHandler
    def_irq_handler    RCM_IRQHandler
    def_irq_handler    LPI2C0_Master_DriverIRQHandler
    def_irq_handler    LPI2C0_Slave_DriverIRQHandler
    def_irq_handler    LPSPI0_DriverIRQHandler
    def_irq_handler    LPSPI1_DriverIRQHandler
    def_irq_handler    LPSPI2_DriverIRQHandler
    def_irq_handler    Reserved45_IRQHandler
    def_irq_handler    Reserved46_IRQHandler
    def_irq_handler    LPUART0_DriverIRQHandler
    def_irq_handler    Reserved48_IRQHandler
    def_irq_handler    LPUART1_DriverIRQHandler
    def_irq_handler    Reserved50_IRQHandler
    def_irq_handler    LPUART2_DriverIRQHandler
    def_irq_handler    Reserved52_IRQHandler
    def_irq_handler    Reserved53_IRQHandler
    def_irq_handler    Reserved54_IRQHandler
    def_irq_handler    ADC0_IRQHandler
    def_irq_handler    ADC1_IRQHandler
    def_irq_handler    CMP0_IRQHandler
    def_irq_handler    Reserved58_IRQHandler
    def_irq_handler    Reserved59_IRQHandler
    def_irq_handler    ERM_single_fault_IRQHandler
    def_irq_handler    ERM_double_fault_IRQHandler
    def_irq_handler    RTC_IRQHandler
    def_irq_handler    RTC_Seconds_IRQHandler
    def_irq_handler    LPIT0_Ch0_IRQHandler
    def_irq_handler    LPIT0_Ch1_IRQHandler
    def_irq_handler    LPIT0_Ch2_IRQHandler
    def_irq_handler    LPIT0_Ch3_IRQHandler
    def_irq_handler    PDB0_IRQHandler
    def_irq_handler    Reserved69_IRQHandler
    def_irq_handler    Reserved70_IRQHandler
    def_irq_handler    Reserved71_IRQHandler
    def_irq_handler    Reserved72_IRQHandler
    def_irq_handler    SCG_IRQHandler
    def_irq_handler    LPTMR0_IRQHandler
    def_irq_handler    PORTA_IRQHandler
    def_irq_handler    PORTB_IRQHandler
    def_irq_handler    PORTC_IRQHandler
    def_irq_handler    PORTD_IRQHandler
    def_irq_handler    PORTE_IRQHandler
    def_irq_handler    SWI_IRQHandler
    def_irq_handler    Reserved81_IRQHandler
    def_irq_handler    Reserved82_IRQHandler
    def_irq_handler    Reserved83_IRQHandler
    def_irq_handler    PDB1_IRQHandler
    def_irq_handler    FLEXIO_DriverIRQHandler
    def_irq_handler    Reserved86_IRQHandler
    def_irq_handler    Reserved87_IRQHandler
    def_irq_handler    Reserved88_IRQHandler
    def_irq_handler    Reserved89_IRQHandler
    def_irq_handler    Reserved90_IRQHandler
    def_irq_handler    Reserved91_IRQHandler
    def_irq_handler    Reserved92_IRQHandler
    def_irq_handler    Reserved93_IRQHandler
    def_irq_handler    CAN0_ORed_DriverIRQHandler
    def_irq_handler    CAN0_Error_DriverIRQHandler
    def_irq_handler    CAN0_Wake_Up_DriverIRQHandler
    def_irq_handler    CAN0_ORed_0_15_MB_DriverIRQHandler
    def_irq_handler    CAN0_ORed_16_31_MB_DriverIRQHandler
    def_irq_handler    Reserved99_IRQHandler
    def_irq_handler    Reserved100_IRQHandler
    def_irq_handler    CAN1_ORed_DriverIRQHandler
    def_irq_handler    CAN1_Error_DriverIRQHandler
    def_irq_handler    Reserved103_IRQHandler
    def_irq_handler    CAN1_ORed_0_15_MB_DriverIRQHandler
    def_irq_handler    CAN1_ORed_16_31_MB_DriverIRQHandler
    def_irq_handler    Reserved106_IRQHandler
    def_irq_handler    Reserved107_IRQHandler
    def_irq_handler    CAN2_ORed_DriverIRQHandler
    def_irq_handler    CAN2_Error_DriverIRQHandler
    def_irq_handler    Reserved110_IRQHandler
    def_irq_handler    CAN2_ORed_0_15_MB_DriverIRQHandler
    def_irq_handler    CAN2_ORed_16_31_MB_DriverIRQHandler
    def_irq_handler    Reserved113_IRQHandler
    def_irq_handler    Reserved114_IRQHandler
    def_irq_handler    FTM0_Ch0_Ch1_IRQHandler
    def_irq_handler    FTM0_Ch2_Ch3_IRQHandler
    def_irq_handler    FTM0_Ch4_Ch5_IRQHandler
    def_irq_handler    FTM0_Ch6_Ch7_IRQHandler
    def_irq_handler    FTM0_Fault_IRQHandler
    def_irq_handler    FTM0_Ovf_Reload_IRQHandler
    def_irq_handler    FTM1_Ch0_Ch1_IRQHandler
    def_irq_handler    FTM1_Ch2_Ch3_IRQHandler
    def_irq_handler    FTM1_Ch4_Ch5_IRQHandler
    def_irq_handler    FTM1_Ch6_Ch7_IRQHandler
    def_irq_handler    FTM1_Fault_IRQHandler
    def_irq_handler    FTM1_Ovf_Reload_IRQHandler
    def_irq_handler    FTM2_Ch0_Ch1_IRQHandler
    def_irq_handler    FTM2_Ch2_Ch3_IRQHandler
    def_irq_handler    FTM2_Ch4_Ch5_IRQHandler
    def_irq_handler    FTM2_Ch6_Ch7_IRQHandler
    def_irq_handler    FTM2_Fault_IRQHandler
    def_irq_handler    FTM2_Ovf_Reload_IRQHandler
    def_irq_handler    FTM3_Ch0_Ch1_IRQHandler
    def_irq_handler    FTM3_Ch2_Ch3_IRQHandler
    def_irq_handler    FTM3_Ch4_Ch5_IRQHandler
    def_irq_handler    FTM3_Ch6_Ch7_IRQHandler
    def_irq_handler    FTM3_Fault_IRQHandler
    def_irq_handler    FTM3_Ovf_Reload_IRQHandler
    def_irq_handler    FTM4_Ch0_Ch1_IRQHandler
    def_irq_handler    FTM4_Ch2_Ch3_IRQHandler
    def_irq_handler    FTM4_Ch4_Ch5_IRQHandler
    def_irq_handler    FTM4_Ch6_Ch7_IRQHandler
    def_irq_handler    FTM4_Fault_IRQHandler
    def_irq_handler    FTM4_Ovf_Reload_IRQHandler
    def_irq_handler    FTM5_Ch0_Ch1_IRQHandler
    def_irq_handler    FTM5_Ch2_Ch3_IRQHandler
    def_irq_handler    FTM5_Ch4_Ch5_IRQHandler
    def_irq_handler    FTM5_Ch6_Ch7_IRQHandler
    def_irq_handler    FTM5_Fault_IRQHandler
    def_irq_handler    FTM5_Ovf_Reload_IRQHandler

    .end
