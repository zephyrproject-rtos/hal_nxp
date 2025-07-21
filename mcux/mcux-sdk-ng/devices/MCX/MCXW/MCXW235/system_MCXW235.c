/*
** ###################################################################
**     Processors:          MCXW235BIHNAR
**                          MCXW235BIUKAR
**
**     Compilers:
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    MCXW23x User manual Rev.0.1  1 September 2022
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-03-08)
**         Initial version based on v0.1UM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MCXW235
 * @version 2.0
 * @date 2024-10-29
 * @brief Device specific configuration file for MCXW235 (implementation file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#include <stdint.h>
#include "fsl_device_registers.h"
#include "fsl_common.h"
#include "fsl_clock.h"

#ifdef SDK_DEBUGCONSOLE
#include "fsl_debug_console.h"
#endif

/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */

uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

/* ----------------------------------------------------------------------------
   -- SystemInit()
   ---------------------------------------------------------------------------- */

__attribute__ ((weak)) void SystemInit (void)
{
#if ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
    SCB->CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2)); /* set CP10, CP11 Full Access in Secure mode */
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    SCB_NS->CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2)); /* set CP10, CP11 Full Access in Non-secure mode */
#endif                                                    /* (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */
#endif                                                    /* ((__FPU_PRESENT == 1) && (__FPU_USED == 1)) */

    SCB->CPACR |= ((3UL << 0 * 2) | (3UL << 1 * 2)); /* set CP0, CP1 Full Access in Secure mode (enable PowerQuad) */
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    SCB_NS->CPACR |= ((3UL << 0 * 2) | (3UL << 1 * 2)); /* set CP0, CP1 Full Access in Normal mode (enable PowerQuad) */
#endif                                                  /* (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */

    SCB->NSACR |= ((3UL << 0) | (3UL << 10)); /* enable CP0, CP1, CP10, CP11 Non-secure Access */

    SYSCON->TRACECLKDIV = 0;
/* Optionally enable RAM banks that may be off by default at reset */
#if !defined(DONT_ENABLE_DISABLED_RAMBANKS)
    SYSCON->AHBCLKCTRLSET[0] = SYSCON_AHBCLKCTRL0_SRAM_CTRL1_MASK | SYSCON_AHBCLKCTRL0_SRAM_CTRL2_MASK;
#endif

#if defined(SUPPORT_MASTER_CONNECTION) || defined(SUPPORT_SLAVE_CONNECTION)
    /* Make sure BLE link layer interrupts have highest priority in the system (prerequisite of the system). */
    for (int irq = 0; irq <= WAKE_PAD_IRQn; irq++)
    {
        if (irq == BLE_LL_IRQn || irq == BLE_SLP_TMR_IRQn)
        {
            NVIC_SetPriority(irq, NVIC_LL_IRQ_PRIORITY);
        }
        else
        {
            NVIC_SetPriority(irq, NVIC_DEFAULT_PRIORITY);
        }
    }
#endif

    SystemInitHook();
}

/* ----------------------------------------------------------------------------
   -- SystemCoreClockUpdate()
   ---------------------------------------------------------------------------- */

void SystemCoreClockUpdate(void)
{
    SystemCoreClock = CLOCK_GetFreq(kCLOCK_CoreSysClk);
}

/* ----------------------------------------------------------------------------
   -- SystemInitHook()
   ---------------------------------------------------------------------------- */

__attribute__((weak)) void SystemInitHook(void)
{
    /* Void implementation of the weak function. */
}

/* ----------------------------------------------------------------------------
   -- __assert_equal_func()
   ---------------------------------------------------------------------------- */
#ifndef NDEBUG
void __assert_equal_func(uint32_t a, uint32_t b)
{
#ifdef SDK_DEBUGCONSOLE
#if SDK_DEBUGCONSOLE == DEBUGCONSOLE_DISABLE
    PRINTF("ASSERT_EQUAL ERROR: %ld==%ld\n", a, b);
#else
    (void)PRINTF("ASSERT_EQUAL ERROR: %ld==%ld\n", a, b);
#endif
#endif
}
#endif

/* ----------------------------------------------------------------------------
   -- Fault handlers
   ---------------------------------------------------------------------------- */
typedef struct __attribute__((packed)) HardFaultInfo
{
    uint32_t stacked_pc;
    uint32_t stacked_lr;
    uint32_t stacked_psr;
    uint32_t stacked_psp;
    uint32_t exec_return;
    uint32_t CFSR;
    uint32_t HFSR;
    uint32_t DFSR;
    uint32_t AFSR;
    uint32_t BFAR;
    uint32_t MMFAR;
    uint32_t ACTLR;
    uint32_t stacked_r0;
    uint32_t stacked_r1;
    uint32_t stacked_r2;
    uint32_t stacked_r3;
    uint32_t stacked_r4;
    uint32_t stacked_r5;
    uint32_t stacked_r6;
    uint32_t stacked_r7;
    uint32_t stacked_r8;
    uint32_t stacked_r9;
    uint32_t stacked_r10;
    uint32_t stacked_r11;
    uint32_t stacked_r12;
} HardFaultInfo_t;

static volatile HardFaultInfo_t gHardFaultInfo;

#define GET_CFSR_BITFIELD(val, field)  (val & SCB_CFSR_##field##_Msk) >> SCB_CFSR_##field##_Pos
#define GET_DHCSR_BITFIELD(val, field) (val & DCB_DHCSR_C_##field##_Msk) >> DCB_DHCSR_C_##field##_Pos

#ifndef SDK_DEBUGCONSOLE
#define SDK_DEBUGCONSOLE DEBUGCONSOLE_DISABLE
#endif

#if (SDK_DEBUGCONSOLE != DEBUGCONSOLE_DISABLE)

/* Initialization that needs to happen before PRINTF can be used. e.g. Hw initialization if coming from power down */
__attribute__((weak)) void PrintHardFaultPreHook(void)
{
}

static void PrintHardFault(void)
{
    PRINTF("HardFault_Handler\r\n");
    PRINTF("\r\n============\r\n");
    PRINTF("HardFault from pc    = 0x%08x (%d)\r\n", gHardFaultInfo.stacked_pc, gHardFaultInfo.stacked_pc);

    PRINTF("r0    = 0x%08x\r\n", gHardFaultInfo.stacked_r0);
    PRINTF("r1    = 0x%08x\r\n", gHardFaultInfo.stacked_r1);
    PRINTF("r2    = 0x%08x\r\n", gHardFaultInfo.stacked_r2);
    PRINTF("r3    = 0x%08x\r\n", gHardFaultInfo.stacked_r3);

    PRINTF("r4    = 0x%08x\r\n", gHardFaultInfo.stacked_r4);
    PRINTF("r5    = 0x%08x\r\n", gHardFaultInfo.stacked_r5);
    PRINTF("r6    = 0x%08x\r\n", gHardFaultInfo.stacked_r6);
    PRINTF("r7    = 0x%08x\r\n", gHardFaultInfo.stacked_r7);
    PRINTF("r8    = 0x%08x\r\n", gHardFaultInfo.stacked_r8);
    PRINTF("r9    = 0x%08x\r\n", gHardFaultInfo.stacked_r9);
    PRINTF("r10   = 0x%08x\r\n", gHardFaultInfo.stacked_r10);
    PRINTF("r11   = 0x%08x\r\n", gHardFaultInfo.stacked_r11);

    PRINTF("r12   = 0x%08x\r\n", gHardFaultInfo.stacked_r12);
    PRINTF("lr    = 0x%08x (%d)\r\n", gHardFaultInfo.stacked_lr, gHardFaultInfo.stacked_lr);
    PRINTF("psp   = 0x%08x\r\n", gHardFaultInfo.stacked_psp);
    PRINTF("psr   = 0x%08x\r\n\n", gHardFaultInfo.stacked_psr);

    PRINTF("CFSR = 0x%08x (Configurable Fault Status Register: UFSR|BFSR|MMSR)\r\n", gHardFaultInfo.CFSR);
    PRINTF("HFSR = 0x%08x (Hard Fault Status Register)\r\n", gHardFaultInfo.HFSR);
    PRINTF("DFSR = 0x%08x (Debug Fault Status Register)\r\n", gHardFaultInfo.DFSR);
    PRINTF("AFSR = 0x%08x (Auxiliary Fault Status Register)\r\n", gHardFaultInfo.AFSR);
    PRINTF("ACTLR= 0x%08x (Auxiliary Control Register)\r\n\n", gHardFaultInfo.ACTLR);

    PRINTF("_SHCSR= 0x%08x (System Handler Control and State Register)\r\n", (unsigned int)SCB->SHCSR);

    if (GET_CFSR_BITFIELD(gHardFaultInfo.CFSR, MEMFAULTSR))
    {
        PRINTF("_MMFAR = 0x%08x (MemManage Fault Address Register)\r\n", gHardFaultInfo.MMFAR);
    }
    if (GET_CFSR_BITFIELD(gHardFaultInfo.CFSR, BUSFAULTSR))
    {
        PRINTF("_BFAR = 0x%08x (Bus Fault Address Register)\r\n", gHardFaultInfo.BFAR);
    }
    if (GET_CFSR_BITFIELD(gHardFaultInfo.CFSR, DIVBYZERO))
    {
        PRINTF("Division by zero\r\n");
    }
    if (GET_CFSR_BITFIELD(gHardFaultInfo.CFSR, UNALIGNED))
    {
        PRINTF("Unaligned access\r\n");
    }

    PRINTF("EXEC_RETURN = 0x%08x (%d current lr)\r\n", gHardFaultInfo.exec_return, gHardFaultInfo.exec_return);
    PRINTF("coming from %s\r\n",
           (gHardFaultInfo.exec_return & 0x4) ? "Thread mode (Process stack)" : "Handler mode (Main Stack)");
}
#endif /* (SDK_DEBUGCONSOLE != DEBUGCONSOLE_DISABLE) */

/**
 * HardFaultHandler:
 * This is called from the HardFault_HandlerAsm with a pointer to the Fault stack
 * as the parameter. We can then read the values from the stack and place them
 * into a variable for ease of reading. The address of that variable can be found in the map file of the application.
 * The function ends with a BKPT instruction to force control back into the debugger
 * If the debug console is enabled the contents of the global variable storing the hard fault information is printed
 * in a loop.
 * Attribute used makes sure the function does not get optimized away by LTO
 **/
__attribute__((used)) void HardFaultHandler(uint32_t *hardfault_args)
{
    gHardFaultInfo.stacked_r0  = hardfault_args[0];
    gHardFaultInfo.stacked_r1  = hardfault_args[1];
    gHardFaultInfo.stacked_r2  = hardfault_args[2];
    gHardFaultInfo.stacked_r3  = hardfault_args[3];
    gHardFaultInfo.stacked_r12 = hardfault_args[4];
    gHardFaultInfo.stacked_lr  = hardfault_args[5];
    gHardFaultInfo.stacked_pc  = hardfault_args[6];
    gHardFaultInfo.stacked_psr = hardfault_args[7];

    __asm volatile(" mov %0, r4" : "=r"(gHardFaultInfo.stacked_r4));
    __asm volatile(" mov %0, r5" : "=r"(gHardFaultInfo.stacked_r5));
    __asm volatile(" mov %0, r6" : "=r"(gHardFaultInfo.stacked_r6));
    __asm volatile(" mov %0, r7" : "=r"(gHardFaultInfo.stacked_r7));
    __asm volatile(" mov %0, r8" : "=r"(gHardFaultInfo.stacked_r8));
    __asm volatile(" mov %0, r9" : "=r"(gHardFaultInfo.stacked_r9));
    __asm volatile(" mov %0, r10" : "=r"(gHardFaultInfo.stacked_r10));
    __asm volatile(" mov %0, r11" : "=r"(gHardFaultInfo.stacked_r11));

    __asm volatile(" mov %0, lr" : "=r"(gHardFaultInfo.exec_return));

    /* need to remove 8 stacked words from sp to get the initial SP value when the afault occured */
    gHardFaultInfo.stacked_psp = (unsigned int)hardfault_args + (8 * 4) + (18 * 4); // 18 * 4 to account for FPU saved info.
    // Stack pointers and CPU state / mod

    gHardFaultInfo.CFSR  = SCB->CFSR;
    gHardFaultInfo.HFSR  = SCB->HFSR;
    gHardFaultInfo.DFSR  = SCB->DFSR;
    gHardFaultInfo.AFSR  = SCB->AFSR;
    gHardFaultInfo.BFAR  = SCB->BFAR;
    gHardFaultInfo.MMFAR = SCB->MMFAR;
    gHardFaultInfo.ACTLR = SCnSCB->ACTLR;

    if (GET_DHCSR_BITFIELD(DCB->DHCSR, DEBUGEN))
    {
        __asm("bkpt 1");
    }
    while (1)
    {
#if (!defined(SDK_DEBUGCONSOLE) || (SDK_DEBUGCONSOLE != DEBUGCONSOLE_DISABLE))
        {
            /* Keep printing the fault in case UART console was not attached yet at the moment of the fault */
            PrintHardFaultPreHook();
            PrintHardFault();
#ifdef FAULT_HANDLER_REPEAT_PRINT
            SDK_DelayAtLeastUs(2000 * 1000, SystemCoreClock);
#else
            while (1)
            {
                ;
            }
#endif /* FAULT_HANDLER_REPEAT_PRINT */
        }
#endif /* (!defined(SDK_DEBUGCONSOLE) || (SDK_DEBUGCONSOLE != DEBUGCONSOLE_DISABLE)) */
    }
}

__attribute__((naked)) void HardFault_Handler(void)
{
    __asm volatile(
        "movs r0, #4\t\n"
        "mov  r1, lr\t\n"
        "tst  r0, r1\t\n" /* Check EXC_RETURN[2] */
        "beq 1f\t\n"
        "mrs r0, psp\t\n"
        "ldr r1,=HardFaultHandler\t\n"
        "bx r1\t\n"
        "1:mrs r0,msp\t\n"
        "ldr r1,=HardFaultHandler\t\n"
        "bx r1\t\n");
}

__attribute__((naked)) void MemManage_Handler(void)
{
    __asm volatile("  b HardFault_Handler \n");
}

__attribute__((naked)) void BusFault_Handler(void)
{
    __asm volatile(" b HardFault_Handler \n");
}

__attribute__((naked)) void UsageFault_Handler(void)
{
    __asm volatile(" b HardFault_Handler \n");
}
