/* ------------------------------------------------------------------------- */
/*  @file:    startup_MIMXRT735S_zenv.S                                      */
/*  @purpose: ZENV Core Device Startup File                                  */
/*            MIMXRT735S_zenv                                                */
/*  @version: 1.0                                                            */
/*  @date:    2022-9-15                                                      */
/*  @build:   b240311                                                        */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Copyright 2024 NXP                                                        */
/* SPDX-License-Identifier: BSD-3-Clause                                     */
/*****************************************************************************/
/* Version: LLVM for RISCV Processors                                        */
/*****************************************************************************/

#ifndef ZENV_EM_USE_VECTOR_INTERRUPT
#define ZENV_EM_USE_VECTOR_INTERRUPT 1
#endif

    /* Arm To EZHv Interrupt Control register */
    .equ    ARM2EZH_INT_CTRL_REG, 0x400A20E8

    .text
    .section .vectors, "ax"
    .option norvc;

    j Reset_Handler                   /* 0: Reset Handler */
    j _SuperSoftInt_Handler           /* 1: supervisor software interrupt */
    j .                               /* 2: reserved */
    j _MachineSoftInt_Handler         /* 3: machine software interrupt */
    j .                               /* 4: reserved */
    j _SuperTimerInt_Handler          /* 5: supervisor timer interrupt */
    j .                               /* 6: reserved */
    j _MachineTimerInt_Handler        /* 7: machine timer interrupt */
    j .                               /* 8: reserved */
    j _SuperExtInt_Handler            /* 9: supervisior external interrupt */
    j .                               /*10: reserved */
    j _MachineExtInt_Handler          /*11: machine external interrupt */
    j .                               /*12: reserved */
    j .                               /*13: reserved */
    j .                               /*14: reserved */
    j .                               /*15: reserved */
    j _NMI_Handler                    /*16: non-mask interrupt NMI */
    j _ImpreciseExceptionInt_Handler  /*17: imprecise exception interrupt */

    .text
    .globl   Reset_Handler
    .type Reset_Handler, @function
Reset_Handler:
    /* Mask all interrupts */
    csrw mideleg, zero
    csrw medeleg, zero
    csrw mie, zero
    csrw mip, zero

    la a0, __VECTOR_TABLE
    add a0, a0, 1 /* Bit 0 is 1, means use vectored mode. */
    csrw mtvec, a0

    /* Initialize global pointer & Stack pointer registers */
    la sp, __StackTop
    .option push
    .option norelax
    la gp, __global_pointer$
    .option pop

#if ZENV_EM_USE_VECTOR_INTERRUPT
    call _InitEventManager
    /* Enable VIE in ez_em_cfg1 */
    lui	a0, (1 << (18 - 12))
    csrc 2085, a0
#else
    /* Disable VIE in ez_em_cfg1 */
    lui	a0, (1 << (18 - 12))
    csrs 2085, a0
#endif

    /* Copy Data */
    la a1, __etext
    la a2, __data_start__
    la a3, __data_end__

    bgeu a2, a3, .LC1
.LC0:
    lw    a0, 0(a1)
    sw    a0, 0(a2)
    addi a1, a1, 4
    addi a2, a2, 4
    bltu a2, a3, .LC0
.LC1:

    /* Clear bss */
    la a0, __bss_start__
    la a1, __bss_end__
.LC2:
    sw zero, 0(a1)
    addi a1, a1, -4
    bgeu a1, a0, .LC2

    call __libc_init_array

    csrsi mstatus, 8

    /* enter main. */
    call main
    ebreak
    j .

    .size Reset_Handler, . - Reset_Handler


#if ZENV_EM_USE_VECTOR_INTERRUPT
    .text
    .type _InitEventManager, @function
_InitEventManager:
    la a0, __VECTOR_TABLE
    /* initialize ez_em_voffs_01 */
    la a1, _EventManagerVector0_Handler
    la a2, _EventManagerVector1_Handler
    sub a1, a1, a0
    sub a2, a2, a0
    srli a1, a1, 2
    srli a2, a2, 2
    bfclri a1, a1, 17, 14
    bfclri a2, a2, 17, 14
    slli a2, a2, 16
    or a1, a2, a1
    csrw 2086, a1

    /* initialize ez_em_voffs_23 */
    la a1, _EventManagerVector2_Handler
    la a2, _EventManagerVector3_Handler
    sub a1, a1, a0
    sub a2, a2, a0
    srli a1, a1, 2
    srli a2, a2, 2
    bfclri a1, a1, 17, 14
    bfclri a2, a2, 17, 14
    slli a2, a2, 16
    or a1, a2, a1
    csrw 2087, a1

    /* initialize the VBASE[15:0] of ez_blc_patt CSR register */
    mv a1, zero
    srli a0, a0, 16
    bfinsi a1, a0, 15, 16
    csrw 2090, a1
    ret

    .size _InitEventManager, . - _InitEventManager
#endif /* ZENV_EM_USE_VECTOR_INTERRUPT */

.macro store_context
    addi sp, sp, -(17*4)
    sw ra, 1 *4(sp)
    sw t0, 2 *4(sp)
    sw t1, 3 *4(sp)
    sw t2, 4 *4(sp)
    sw a0, 5 *4(sp)
    sw a1, 6 *4(sp)
    sw a2, 7 *4(sp)
    sw a3, 8 *4(sp)
    sw a4, 9 *4(sp)
    sw a5, 10*4(sp)
    sw a6, 11*4(sp)
    sw a7, 12*4(sp)
    sw t3, 13*4(sp)
    sw t4, 14*4(sp)
    sw t5, 15*4(sp)
    sw t6, 16*4(sp)
.endm

.macro restore_context
    lw ra, 1 *4(sp)
    lw t0, 2 *4(sp)
    lw t1, 3 *4(sp)
    lw t2, 4 *4(sp)
    lw a0, 5 *4(sp)
    lw a1, 6 *4(sp)
    lw a2, 7 *4(sp)
    lw a3, 8 *4(sp)
    lw a4, 9 *4(sp)
    lw a5, 10*4(sp)
    lw a6, 11*4(sp)
    lw a7, 12*4(sp)
    lw t3, 13*4(sp)
    lw t4, 14*4(sp)
    lw t5, 15*4(sp)
    lw t6, 16*4(sp)
    addi sp, sp, (17*4)
.endm

    .weak DefaultISR
    .type DefaultISR, %function
DefaultISR:
    j .
    .size DefaultISR, . - DefaultISR

    /* machine-level external interrupt */
    .weak _MachineExtInt_Handler
    .type _MachineExtInt_Handler, %function
_MachineExtInt_Handler:
    store_context
    /* Clear the request in register ARM2EZHV_INT_CTRL */
    li a3, ARM2EZH_INT_CTRL_REG
    lw a4, 0(a3)
    andi a4, a4, 0xe
    sw a4, 0(a3)
    call MachineExtInt_Handler
    restore_context
    mret
    .size _MachineExtInt_Handler, . - _MachineExtInt_Handler

    /* supervisor-level external interrupt */
    .weak _SuperExtInt_Handler
    .type _SuperExtInt_Handler, %function
_SuperExtInt_Handler:
    store_context
    /* Clear the request in register ARM2EZHV_INT_CTRL */
    li a3, ARM2EZH_INT_CTRL_REG
    lw a4, 0(a3)
    andi a4, a4, 0xd
    sw a4, 0(a3)
    call SuperExtInt_Handler
    restore_context
    mret
    .size _SuperExtInt_Handler, . - _SuperExtInt_Handler

    /* machine-level software interrupt */
    .weak _MachineSoftInt_Handler
    .type _MachineSoftInt_Handler, %function
_MachineSoftInt_Handler:
    store_context
    /* Clear the request in register ARM2EZHV_INT_CTRL */
    li a3, ARM2EZH_INT_CTRL_REG
    lw a4, 0(a3)
    andi a4, a4, 0xb
    sw a4, 0(a3)
    call MachineSoftInt_Handler
    restore_context
    mret
    .size _MachineSoftInt_Handler, . - _MachineSoftInt_Handler

    /* supervisor-level software interrupt */
    .weak _SuperSoftInt_Handler
    .type _SuperSoftInt_Handler, %function
_SuperSoftInt_Handler:
    store_context
    /* Clear the request in register ARM2EZHV_INT_CTRL */
    li a3, ARM2EZH_INT_CTRL_REG
    lw a4, 0(a3)
    andi a4, a4, 0xb
    sw a4, 0(a3)
    call SuperSoftInt_Handler
    restore_context
    mret
    .size _SuperSoftInt_Handler, . - _SuperSoftInt_Handler

    /* machine-level timer interrupt */
    .weak _MachineTimerInt_Handler
    .type _MachineTimerInt_Handler, %function
_MachineTimerInt_Handler:
    store_context
    /* Clear the request in register ARM2EZHV_INT_CTRL */
    li a3, ARM2EZH_INT_CTRL_REG
    lw a4, 0(a3)
    andi a4, a4, 0x7
    sw a4, 0(a3)
    call MachineTimerInt_Handler
    restore_context
    mret
    .size _MachineTimerInt_Handler, . - _MachineTimerInt_Handler

    /* supervisor-level timer interrupt */
    .weak _SuperTimerInt_Handler
    .type _SuperTimerInt_Handler, %function
_SuperTimerInt_Handler:
    store_context
    call SuperTimerInt_Handler
    restore_context
    mret
    .size _SuperTimerInt_Handler, . - _SuperTimerInt_Handler

#if ZENV_EM_USE_VECTOR_INTERRUPT
    /* Event manager vector event 0 handler. */
    .section .em_vector0, "ax"
    .weak _EventManagerVector0_Handler
    .type _EventManagerVector0_Handler, %function
_EventManagerVector0_Handler:
    store_context
    call EventManagerVector0_Handler
    restore_context
    mret
    .size _EventManagerVector0_Handler, . - _EventManagerVector0_Handler

    /* Event manager vector event 1 handler. */
    .section .em_vector1, "ax"
    .weak _EventManagerVector1_Handler
    .type _EventManagerVector1_Handler, %function
_EventManagerVector1_Handler:
    store_context
    call EventManagerVector1_Handler
    restore_context
    mret
    .size _EventManagerVector1_Handler, . - _EventManagerVector1_Handler

    /* Event manager vector event 2 handler. */
    .section .em_vector2, "ax"
    .weak _EventManagerVector2_Handler
    .type _EventManagerVector2_Handler, %function
_EventManagerVector2_Handler:
    store_context
    call EventManagerVector2_Handler
    restore_context
    mret
    .size _EventManagerVector2_Handler, . - _EventManagerVector2_Handler

    /* Event manager vector event 3 handler. */
    .section .em_vector3, "ax"
    .weak _EventManagerVector3_Handler
    .type _EventManagerVector3_Handler, %function
_EventManagerVector3_Handler:
    store_context
    call EventManagerVector3_Handler
    restore_context
    mret
    .size _EventManagerVector3_Handler, . - _EventManagerVector3_Handler

#endif /* ZENV_EM_USE_VECTOR_INTERRUPT */

    /*
     * Macro to define default handlers. Default handler
     * will be weak symbol and just dead loops. They can be
     * overwritten by other handlers
     */
    .macro def_irq_handler  handler_name
    .weak \handler_name
    .set  \handler_name, DefaultISR
    .endm
    /* Exception Handlers */
    def_irq_handler    MachineExtInt_Handler
    def_irq_handler    MachineSoftInt_Handler
    def_irq_handler    MachineTimerInt_Handler
    def_irq_handler    SuperExtInt_Handler
    def_irq_handler    SuperSoftInt_Handler
    def_irq_handler    SuperTimerInt_Handler
    def_irq_handler    _NMI_Handler
    def_irq_handler    _ImpreciseExceptionInt_Handler
#if ZENV_EM_USE_VECTOR_INTERRUPT
    def_irq_handler    EventManagerVector0_Handler
    def_irq_handler    EventManagerVector1_Handler
    def_irq_handler    EventManagerVector2_Handler
    def_irq_handler    EventManagerVector3_Handler
#endif

    .end
