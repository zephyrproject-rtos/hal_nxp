//*****************************************************************************
// MCXC161 startup code
//
// Version : 210126
//*****************************************************************************
//
// Copyright 2016-2026 NXP
//
// SPDX-License-Identifier: BSD-3-Clause
//*****************************************************************************
#include <stdint.h>

#if defined(DEBUG)
#if defined(__GNUC__)
#pragma GCC push_options
#pragma GCC optimize("Og")
#endif //(__GNUC__)
#endif //(DEBUG)

#if defined(__cplusplus)
#if defined(__MCUXPRESSO)
#if defined(__REDLIB__)
#error Redlib does not support C++
#else
//*****************************************************************************
//
// The entry point for the C++ library startup
//
//*****************************************************************************
extern "C" {
extern void __libc_init_array(void);
}
#endif //(__REDLIB__)
#endif //(__MCUXPRESSO)
#endif //(__cplusplus)

#define WEAK __attribute__((weak))
#if defined(__MCUXPRESSO)
#define WEAK_AV __attribute__((weak, section(".after_vectors")))
#else
#define WEAK_AV __attribute__((weak))
#endif //(__MCUXPRESSO)
#define ALIAS(f) __attribute__((weak, alias(#f)))

//*****************************************************************************
#if defined(__cplusplus)
extern "C" {
#endif //(__cplusplus)

//*****************************************************************************
// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
//*****************************************************************************
//*****************************************************************************
// Declaration of external SystemInit function
//*****************************************************************************
extern void SystemInit(void);

//*****************************************************************************
// Forward declaration of the core exception handlers.
// When the application defines a handler (with the same name), this will
// automatically take precedence over these weak definitions.
// If your application is a C++ one, then any interrupt handlers defined
// in C++ files within in your main application will need to have C linkage
// rather than C++ linkage. To do this, make sure that you are using extern "C"
// { .... } around the interrupt handler within your main application code.
//*****************************************************************************
#if defined(__MCUXPRESSO)
void ResetISR(void);
#else
void Reset_Handler(void);
#endif //(__MCUXPRESSO)
void Reset_Handler_C(void);
WEAK void NMI_Handler(void);
WEAK void HardFault_Handler(void);
WEAK void SVC_Handler(void);
WEAK void PendSV_Handler(void);
WEAK void SysTick_Handler(void);
WEAK void DefaultISR(void);

//*****************************************************************************
// Forward declaration of the application IRQ handlers. When the application
// defines a handler (with the same name), this will automatically take
// precedence over weak definitions below
//*****************************************************************************
WEAK void Reserved16_IRQHandler(void);
WEAK void CMC_IRQHandler(void);
WEAK void DMA_CH0_IRQHandler(void);
WEAK void DMA_CH1_IRQHandler(void);
WEAK void DMA_CH2_IRQHandler(void);
WEAK void DMA_CH3_IRQHandler(void);
WEAK void Reserved22_IRQHandler(void);
WEAK void Reserved23_IRQHandler(void);
WEAK void Reserved24_IRQHandler(void);
WEAK void Reserved25_IRQHandler(void);
WEAK void ERM0_SINGLE_BIT_IRQHandler(void);
WEAK void ERM0_MULTI_BIT_IRQHandler(void);
WEAK void FMU0_IRQHandler(void);
WEAK void Reserved29_IRQHandler(void);
WEAK void MBC0_IRQHandler(void);
WEAK void SCG0_IRQHandler(void);
WEAK void SPC0_IRQHandler(void);
WEAK void Reserved33_IRQHandler(void);
WEAK void WUU0_IRQHandler(void);
WEAK void Reserved35_IRQHandler(void);
WEAK void Reserved36_IRQHandler(void);
WEAK void Reserved37_IRQHandler(void);
WEAK void Reserved38_IRQHandler(void);
WEAK void Reserved39_IRQHandler(void);
WEAK void Reserved40_IRQHandler(void);
WEAK void Reserved41_IRQHandler(void);
WEAK void LPI2C0_IRQHandler(void);
WEAK void Reserved43_IRQHandler(void);
WEAK void LPSPI0_IRQHandler(void);
WEAK void Reserved45_IRQHandler(void);
WEAK void Reserved46_IRQHandler(void);
WEAK void LPUART0_IRQHandler(void);
WEAK void LPUART1_IRQHandler(void);
WEAK void LPUART2_IRQHandler(void);
WEAK void LPUART3_IRQHandler(void);
WEAK void LPUART4_IRQHandler(void);
WEAK void Reserved52_IRQHandler(void);
WEAK void Reserved53_IRQHandler(void);
WEAK void Reserved54_IRQHandler(void);
WEAK void CTIMER0_IRQHandler(void);
WEAK void CTIMER1_IRQHandler(void);
WEAK void Reserved57_IRQHandler(void);
WEAK void Reserved58_IRQHandler(void);
WEAK void Reserved59_IRQHandler(void);
WEAK void FLEXPWM0_RELOAD_ERROR_IRQHandler(void);
WEAK void FLEXPWM0_FAULT_IRQHandler(void);
WEAK void FLEXPWM0_SUBMODULE0_IRQHandler(void);
WEAK void FLEXPWM0_SUBMODULE1_IRQHandler(void);
WEAK void FLEXPWM0_SUBMODULE2_IRQHandler(void);
WEAK void Reserved65_IRQHandler(void);
WEAK void EQDC0_COMPARE_IRQHandler(void);
WEAK void EQDC0_HOME_IRQHandler(void);
WEAK void EQDC0_WATCHDOG_IRQHandler(void);
WEAK void EQDC0_INDEX_IRQHandler(void);
WEAK void FREQME0_IRQHandler(void);
WEAK void LPTMR0_IRQHandler(void);
WEAK void Reserved72_IRQHandler(void);
WEAK void Reserved73_IRQHandler(void);
WEAK void RTC_IRQHandler(void);
WEAK void RTC_1HZ_IRQHandler(void);
WEAK void WWDT0_IRQHandler(void);
WEAK void WWDT1_IRQHandler(void);
WEAK void ADC0_IRQHandler(void);
WEAK void Reserved79_IRQHandler(void);
WEAK void CMP0_IRQHandler(void);
WEAK void Reserved81_IRQHandler(void);
WEAK void Reserved82_IRQHandler(void);
WEAK void Reserved83_IRQHandler(void);
WEAK void Reserved84_IRQHandler(void);
WEAK void Reserved85_IRQHandler(void);
WEAK void Reserved86_IRQHandler(void);
WEAK void GPIO0_IRQHandler(void);
WEAK void GPIO1_IRQHandler(void);
WEAK void GPIO2_IRQHandler(void);
WEAK void GPIO3_IRQHandler(void);

//*****************************************************************************
// Forward declaration of the driver IRQ handlers. These are aliased
// to the DefaultISR, which is a 'forever' loop. When the driver
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//*****************************************************************************
void Reserved16_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMC_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA_CH2_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA_CH3_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved22_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved23_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved24_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved25_DriverIRQHandler(void) ALIAS(DefaultISR);
void ERM0_SINGLE_BIT_DriverIRQHandler(void) ALIAS(DefaultISR);
void ERM0_MULTI_BIT_DriverIRQHandler(void) ALIAS(DefaultISR);
void FMU0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved29_DriverIRQHandler(void) ALIAS(DefaultISR);
void MBC0_DriverIRQHandler(void) ALIAS(DefaultISR);
void SCG0_DriverIRQHandler(void) ALIAS(DefaultISR);
void SPC0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved33_DriverIRQHandler(void) ALIAS(DefaultISR);
void WUU0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved35_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved36_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved37_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved38_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved39_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved40_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved41_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPI2C0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved43_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPSPI0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved45_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved46_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPUART0_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPUART1_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPUART2_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPUART3_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPUART4_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved52_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved53_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved54_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER0_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER1_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved57_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved58_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved59_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLEXPWM0_RELOAD_ERROR_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLEXPWM0_FAULT_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLEXPWM0_SUBMODULE0_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLEXPWM0_SUBMODULE1_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLEXPWM0_SUBMODULE2_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved65_DriverIRQHandler(void) ALIAS(DefaultISR);
void EQDC0_COMPARE_DriverIRQHandler(void) ALIAS(DefaultISR);
void EQDC0_HOME_DriverIRQHandler(void) ALIAS(DefaultISR);
void EQDC0_WATCHDOG_DriverIRQHandler(void) ALIAS(DefaultISR);
void EQDC0_INDEX_DriverIRQHandler(void) ALIAS(DefaultISR);
void FREQME0_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPTMR0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved72_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved73_DriverIRQHandler(void) ALIAS(DefaultISR);
void RTC_DriverIRQHandler(void) ALIAS(DefaultISR);
void RTC_1HZ_DriverIRQHandler(void) ALIAS(DefaultISR);
void WWDT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void WWDT1_DriverIRQHandler(void) ALIAS(DefaultISR);
void ADC0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved79_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMP0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved81_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved82_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved83_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved84_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved85_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved86_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO0_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO1_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO2_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO3_DriverIRQHandler(void) ALIAS(DefaultISR);

//*****************************************************************************
// The entry point for the application.
// __main() is the entry point for Redlib based applications
// main() is the entry point for Newlib based applications
//*****************************************************************************
#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
extern void __main(void);
#elif defined(__MCUXPRESSO)
#if defined(__REDLIB__)
extern void __main(void);
#else
extern int main(void);
#endif //(__REDLIB__)
#elif defined(__ICCARM__)
extern void __iar_program_start(void);
#elif defined(__GNUC__)
#if defined(__REDLIB__)
extern void __main(void);
#else
extern void _start(void);
#endif //(__REDLIB__)
#else
#error Unsupported toolchain!
#endif //(__MCUXPRESSO)

//*****************************************************************************
// External declaration for the pointer from the Linker Script
//*****************************************************************************
#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
extern uint32_t Image$$ARM_LIB_STACK$$ZI$$Base[];
extern uint32_t Image$$ARM_LIB_STACK$$ZI$$Limit[];
#define _vStackTop  Image$$ARM_LIB_STACK$$ZI$$Limit
#define _vStackBase Image$$ARM_LIB_STACK$$ZI$$Base
#elif defined(__MCUXPRESSO)
extern void _vStackTop(void);
extern void _vStackBase(void);
#define Reset_Handler ResetISR // To be compatible with other compilers
#elif defined(__ICCARM__)
#pragma segment = "CSTACK"
#define _vStackTop  __section_end("CSTACK")
#define _vStackBase __section_begin("CSTACK")
#elif defined(__GNUC__)
extern uint32_t __StackTop[];
extern uint32_t __StackLimit[];

#define _vStackTop  __StackTop
#define _vStackBase __StackLimit

/*
 * Data section ROM and RAM addresses
 */
extern uint32_t __etext[];
extern uint32_t __data_start__[];
extern uint32_t __data_end__[];
extern uint32_t __bss_start__[];
extern uint32_t __bss_end__[];

#else
#error Unsupported toolchain!
#endif //(__CC_ARM) || (__ARMCC_VERSION)

//*****************************************************************************
#if defined(__cplusplus)
} // extern "C"
#endif //(__cplusplus)
//*****************************************************************************
// The vector table.
// This relies on the linker script to place at correct location in memory.
//*****************************************************************************
#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
extern void (*const __Vectors[])(void);
#define __vector_table __Vectors
__attribute__((used, section(".isr_vector"))) void (*const __Vectors[])(void) = {
#elif defined(__MCUXPRESSO)
extern void (*const g_pfnVectors[])(void);
extern void *__Vectors __attribute__((alias("g_pfnVectors")));
#define __vector_table g_pfnVectors
__attribute__((used, section(".isr_vector"))) void (*const g_pfnVectors[])(void) = {
#elif defined(__ICCARM__)
extern void (*const __vector_table[])(void);
/* The vector table is not needed for initialization. */
extern void (*const __iar_init$$done[])(void) __attribute__((alias("__vector_table")));
__attribute__((used, section(".intvec"))) void (*const __vector_table[])(void) = {
#elif defined(__GNUC__)
extern void (*const __isr_vector[])(void);
#define __vector_table __isr_vector
__attribute__((used, section(".isr_vector"))) void (*const __isr_vector[])(void) = {
#else
#error Unsupported toolchain!
#endif //(__CC_ARM) || (__ARMCC_VERSION)
    // Core Level - CM23
    (void (*)())((uint32_t)_vStackTop), // The initial stack pointer
    Reset_Handler,                      // The reset handler

    NMI_Handler,                        // NMI Handler
    HardFault_Handler,                  // Hard Fault Handler
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    SVC_Handler,                        // SVCall Handler
    0,                                  // Reserved
    0,                                  // Reserved
    PendSV_Handler,                     // PendSV Handler
    SysTick_Handler,                    // SysTick Handler

    // Chip Level - MCXC161
    Reserved16_IRQHandler,            // 16: Reserved interrupt
    CMC_IRQHandler,                   // 17: Core Mode Controller interrupt
    DMA_CH0_IRQHandler,               // 18: DMA3_0_CH0 error or transfer complete
    DMA_CH1_IRQHandler,               // 19: DMA3_0_CH1 error or transfer complete
    DMA_CH2_IRQHandler,               // 20: DMA3_0_CH2 error or transfer complete
    DMA_CH3_IRQHandler,               // 21: DMA3_0_CH3 error or transfer complete
    Reserved22_IRQHandler,            // 22: Reserved interrupt
    Reserved23_IRQHandler,            // 23: Reserved interrupt
    Reserved24_IRQHandler,            // 24: Reserved interrupt
    Reserved25_IRQHandler,            // 25: Reserved interrupt
    ERM0_SINGLE_BIT_IRQHandler,       // 26: ERM Single Bit error interrupt
    ERM0_MULTI_BIT_IRQHandler,        // 27: ERM Multi Bit error interrupt
    FMU0_IRQHandler,                  // 28: Flash Management Unit interrupt
    Reserved29_IRQHandler,            // 29: Reserved interrupt
    MBC0_IRQHandler,                  // 30: MBC secure violation interrupt
    SCG0_IRQHandler,                  // 31: System Clock Generator interrupt
    SPC0_IRQHandler,                  // 32: System Power Controller interrupt
    Reserved33_IRQHandler,            // 33: Reserved interrupt
    WUU0_IRQHandler,                  // 34: Wake Up Unit interrupt
    Reserved35_IRQHandler,            // 35: Reserved interrupt
    Reserved36_IRQHandler,            // 36: Reserved interrupt
    Reserved37_IRQHandler,            // 37: Reserved interrupt
    Reserved38_IRQHandler,            // 38: Reserved interrupt
    Reserved39_IRQHandler,            // 39: Reserved interrupt
    Reserved40_IRQHandler,            // 40: Reserved interrupt
    Reserved41_IRQHandler,            // 41: Reserved interrupt
    LPI2C0_IRQHandler,                // 42: Low-Power Inter Integrated Circuit 0 interrupt
    Reserved43_IRQHandler,            // 43: Reserved interrupt
    LPSPI0_IRQHandler,                // 44: Low-Power Serial Peripheral Interface 0 interrupt
    Reserved45_IRQHandler,            // 45: Reserved interrupt
    Reserved46_IRQHandler,            // 46: Reserved interrupt
    LPUART0_IRQHandler,               // 47: Low-Power Universal Asynchronous Receive/Transmit 0 interrupt
    LPUART1_IRQHandler,               // 48: Low-Power Universal Asynchronous Receive/Transmit 1 interrupt
    LPUART2_IRQHandler,               // 49: Low-Power Universal Asynchronous Receive/Transmit 2 interrupt
    LPUART3_IRQHandler,               // 50: Low-Power Universal Asynchronous Receive/Transmit 3 interrupt
    LPUART4_IRQHandler,               // 51: Low-Power Universal Asynchronous Receive/Transmit 4 interrupt
    Reserved52_IRQHandler,            // 52: Reserved interrupt
    Reserved53_IRQHandler,            // 53: Reserved interrupt
    Reserved54_IRQHandler,            // 54: Reserved interrupt
    CTIMER0_IRQHandler,               // 55: Standard counter/timer 0 interrupt
    CTIMER1_IRQHandler,               // 56: Standard counter/timer 1 interrupt
    Reserved57_IRQHandler,            // 57: Reserved interrupt
    Reserved58_IRQHandler,            // 58: Reserved interrupt
    Reserved59_IRQHandler,            // 59: Reserved interrupt
    FLEXPWM0_RELOAD_ERROR_IRQHandler, // 60: FlexPWM0_reload_error interrupt
    FLEXPWM0_FAULT_IRQHandler,        // 61: FlexPWM0_fault interrupt
    FLEXPWM0_SUBMODULE0_IRQHandler,   // 62: FlexPWM0 Submodule 0 capture/compare/reload interrupt
    FLEXPWM0_SUBMODULE1_IRQHandler,   // 63: FlexPWM0 Submodule 1 capture/compare/reload interrupt
    FLEXPWM0_SUBMODULE2_IRQHandler,   // 64: FlexPWM0 Submodule 2 capture/compare/reload interrupt
    Reserved65_IRQHandler,            // 65: Reserved interrupt
    EQDC0_COMPARE_IRQHandler,         // 66: Compare
    EQDC0_HOME_IRQHandler,            // 67: Home
    EQDC0_WATCHDOG_IRQHandler,        // 68: Watchdog / Simultaneous A and B Change
    EQDC0_INDEX_IRQHandler,           // 69: Index / Roll Over / Roll Under
    FREQME0_IRQHandler,               // 70: Frequency Measurement interrupt
    LPTMR0_IRQHandler,                // 71: Low Power Timer 0 interrupt
    Reserved72_IRQHandler,            // 72: Reserved interrupt
    Reserved73_IRQHandler,            // 73: Reserved interrupt
    RTC_IRQHandler,                   // 74: RTC alarm interrupt
    RTC_1HZ_IRQHandler,               // 75: RTC 1Hz interrupt
    WWDT0_IRQHandler,                 // 76: Windowed Watchdog Timer 0 interrupt
    WWDT1_IRQHandler,                 // 77: Windowed Watchdog Timer 1 interrupt
    ADC0_IRQHandler,                  // 78: Analog-to-Digital Converter 0 interrupt
    Reserved79_IRQHandler,            // 79: Reserved interrupt
    CMP0_IRQHandler,                  // 80: Comparator 0 interrupt
    Reserved81_IRQHandler,            // 81: Reserved interrupt
    Reserved82_IRQHandler,            // 82: Reserved interrupt
    Reserved83_IRQHandler,            // 83: Reserved interrupt
    Reserved84_IRQHandler,            // 84: Reserved interrupt
    Reserved85_IRQHandler,            // 85: Reserved interrupt
    Reserved86_IRQHandler,            // 86: Reserved interrupt
    GPIO0_IRQHandler,                 // 87: General Purpose Input/Output interrupt 0
    GPIO1_IRQHandler,                 // 88: General Purpose Input/Output interrupt 1
    GPIO2_IRQHandler,                 // 89: General Purpose Input/Output interrupt 2
    GPIO3_IRQHandler,                 // 90: General Purpose Input/Output interrupt 3
};                                     /* End of __vector_table */

#if defined(__MCUXPRESSO)
#if defined(ENABLE_RAM_VECTOR_TABLE)
extern void *__VECTOR_TABLE __attribute__((alias("g_pfnVectors")));
void (*__VECTOR_RAM[sizeof(g_pfnVectors) / 4])(void) __attribute__((aligned(128)));
unsigned int __RAM_VECTOR_TABLE_SIZE_BYTES = sizeof(g_pfnVectors);
#endif //(ENABLE_RAM_VECTOR_TABLE)

//*****************************************************************************
// Functions to carry out the initialization of RW and BSS data sections. These
// are written as separate functions rather than being inlined within the
// ResetISR() function in order to cope with MCUs with multiple banks of
// memory.
//*****************************************************************************
__attribute__((section(".after_vectors.init_data"))) void data_init(unsigned int romstart,
                                                                    unsigned int start,
                                                                    unsigned int len)
{
    unsigned int *pulDest = (unsigned int *)start;
    unsigned int *pulSrc  = (unsigned int *)romstart;
    unsigned int loop;
    for (loop = 0; loop < len; loop = loop + 4)
        *pulDest++ = *pulSrc++;
}

__attribute__((section(".after_vectors.init_bss"))) void bss_init(unsigned int start, unsigned int len)
{
    unsigned int *pulDest = (unsigned int *)start;
    unsigned int loop;
    for (loop = 0; loop < len; loop = loop + 4)
        *pulDest++ = 0;
}

//*****************************************************************************
// The following symbols are constructs generated by the linker, indicating
// the location of various points in the "Global Section Table". This table is
// created by the linker via the Code Red managed linker script mechanism. It
// contains the load address, execution address and length of each RW data
// section and the execution and length of each BSS (zero initialized) section.
//*****************************************************************************
extern unsigned int __data_section_table;
extern unsigned int __data_section_table_end;
extern unsigned int __bss_section_table;
extern unsigned int __bss_section_table_end;
#endif //(__MCUXPRESSO)

//*****************************************************************************
// Reset entry point for your code.
// Sets up a simple runtime environment and initializes the C/C++
// library.
//*****************************************************************************
void Reset_Handler_C(void)
{
#if !defined(__NO_SYSTEM_INIT)
    SystemInit();
#endif //(__NO_SYSTEM_INIT)

#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
    __asm volatile ("cpsie i");
    __main();
#elif defined(__MCUXPRESSO)
    //
    // Copy the data sections from flash to SRAM.
    //
    unsigned int LoadAddr, ExeAddr, SectionLen;
    unsigned int *SectionTableAddr;

    // Load base address of Global Section Table
    SectionTableAddr = &__data_section_table;

    // Copy the data sections from flash to SRAM.
    while (SectionTableAddr < &__data_section_table_end)
    {
        LoadAddr   = *SectionTableAddr++;
        ExeAddr    = *SectionTableAddr++;
        SectionLen = *SectionTableAddr++;
        data_init(LoadAddr, ExeAddr, SectionLen);
    }

    // At this point, SectionTableAddr = &__bss_section_table;
    // Zero fill the bss segment
    while (SectionTableAddr < &__bss_section_table_end)
    {
        ExeAddr    = *SectionTableAddr++;
        SectionLen = *SectionTableAddr++;
        bss_init(ExeAddr, SectionLen);
    }

#if defined(__cplusplus)
    //
    // Call C++ library initialisation
    //
    __libc_init_array();
#endif //(__cplusplus)

    // Reenable interrupts
    __asm volatile("cpsie i");

#if defined(__REDLIB__)
    // Call the Redlib library, which in turn calls main()
    __main();
#else
    main();
#endif //(__REDLIB__)
#elif defined(__ICCARM__)
    // Reenable interrupts
    __asm volatile("cpsie i");

    __iar_program_start();
#elif defined(__GNUC__)
    /*     Loop to copy data from read only memory to RAM. The ranges
     *      of copy from/to are specified by following symbols evaluated in
     *      linker script.
     *      *. __etext/_data_start__/__data_end__
     *      Note: All must be aligned to 4 bytes boundary.
     */
    uint32_t *pDataSrc, *pDataDest;

    pDataSrc  = (uint32_t *)__etext;
    pDataDest = (uint32_t *)__data_start__;
    while (pDataDest < __data_end__)
    {
        *pDataDest++ = *pDataSrc++;
    }
#if defined(__STARTUP_CLEAR_BSS)
    /*     This part of work usually is done in C library startup code. Otherwise,
     *     define this macro to enable it in this startup.
     *
     *     Loop to zero out BSS section, which uses following symbols
     *     in linker script:
     *      __bss_start__: start of BSS section. Must align to 4
     *      __bss_end__: end of BSS section. Must align to 4
     */
    pDataDest = (uint32_t *)__bss_start__;
    while (pDataDest < __bss_end__)
    {
        *pDataDest++ = 0U;
    }
#endif //(__STARTUP_CLEAR_BSS)

    __asm volatile("cpsie i");

#if !defined(__START)
#if defined(__REDLIB__)
#define __START __main
#else
#define __START _start
#endif //(__REDLIB__)
#endif //(__START)

    __START();

#endif //(__GNUC__)

    //
    // main() shouldn't return, but if it does, we'll just enter an infinite loop
    //
#if !defined(__ARMCC_VERSION) && !defined(__CC_ARM)
    while (1)
    {
        ;
    }
#endif //!(__ARMCC_VERSION) && !(__CC_ARM)
}

#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
__attribute__ ((used, section("InRoot$$Sections")))
__attribute__ ((naked))
#elif defined(__MCUXPRESSO)
__attribute__ ((naked, section(".after_vectors.reset")))
#elif defined(__ICCARM__)
__stackless
#elif defined(__GNUC__)
__attribute__ ((naked))
#endif //(__CC_ARM) || (__ARMCC_VERSION)
void Reset_Handler(void)
{
    // Disable interrupts
    __asm volatile("cpsid i");
    // Config VTOR & MSP register
    __asm volatile(
        "LDR R0, =0xE000ED08  \n"
        "STR %0, [R0]         \n"
        "LDR R1, [%0]         \n"
        "MSR MSP, R1          \n"
                    :
                    : "r"(__vector_table)
                    : "r0");

    // Call Reset_Handler_C
    __asm volatile ("LDR R0, =Reset_Handler_C \n"
                    "BLX R0                   \n"
                    );
}

//*****************************************************************************
// Default core exception handlers. Override the ones here by defining your own
// handler routines in your application code.
//*****************************************************************************
WEAK_AV void NMI_Handler(void)
{
    while (1)
    {
    }
}

WEAK_AV void HardFault_Handler(void)
{
    while (1)
    {
    }
}

WEAK_AV void SVC_Handler(void)
{
    while (1)
    {
    }
}

WEAK_AV void PendSV_Handler(void)
{
    while (1)
    {
    }
}

WEAK_AV void SysTick_Handler(void)
{
    while (1)
    {
    }
}

//*****************************************************************************
// Processor ends up here if an unexpected interrupt occurs or a specific
// handler is not present in the application code.
//*****************************************************************************
WEAK_AV void DefaultISR(void)
{
    while (1)
    {
    }
}

//*****************************************************************************
// Default application exception handlers. Override the ones here by defining
// your own handler routines in your application code. These routines call
// driver exception handlers or DefaultISR() if no driver exception
// handler is included.
//*****************************************************************************
WEAK void Reserved16_IRQHandler(void)
{
    Reserved16_DriverIRQHandler();
}

WEAK void CMC_IRQHandler(void)
{
    CMC_DriverIRQHandler();
}

WEAK void DMA_CH0_IRQHandler(void)
{
    DMA_CH0_DriverIRQHandler();
}

WEAK void DMA_CH1_IRQHandler(void)
{
    DMA_CH1_DriverIRQHandler();
}

WEAK void DMA_CH2_IRQHandler(void)
{
    DMA_CH2_DriverIRQHandler();
}

WEAK void DMA_CH3_IRQHandler(void)
{
    DMA_CH3_DriverIRQHandler();
}

WEAK void Reserved22_IRQHandler(void)
{
    Reserved22_DriverIRQHandler();
}

WEAK void Reserved23_IRQHandler(void)
{
    Reserved23_DriverIRQHandler();
}

WEAK void Reserved24_IRQHandler(void)
{
    Reserved24_DriverIRQHandler();
}

WEAK void Reserved25_IRQHandler(void)
{
    Reserved25_DriverIRQHandler();
}

WEAK void ERM0_SINGLE_BIT_IRQHandler(void)
{
    ERM0_SINGLE_BIT_DriverIRQHandler();
}

WEAK void ERM0_MULTI_BIT_IRQHandler(void)
{
    ERM0_MULTI_BIT_DriverIRQHandler();
}

WEAK void FMU0_IRQHandler(void)
{
    FMU0_DriverIRQHandler();
}

WEAK void Reserved29_IRQHandler(void)
{
    Reserved29_DriverIRQHandler();
}

WEAK void MBC0_IRQHandler(void)
{
    MBC0_DriverIRQHandler();
}

WEAK void SCG0_IRQHandler(void)
{
    SCG0_DriverIRQHandler();
}

WEAK void SPC0_IRQHandler(void)
{
    SPC0_DriverIRQHandler();
}

WEAK void Reserved33_IRQHandler(void)
{
    Reserved33_DriverIRQHandler();
}

WEAK void WUU0_IRQHandler(void)
{
    WUU0_DriverIRQHandler();
}

WEAK void Reserved35_IRQHandler(void)
{
    Reserved35_DriverIRQHandler();
}

WEAK void Reserved36_IRQHandler(void)
{
    Reserved36_DriverIRQHandler();
}

WEAK void Reserved37_IRQHandler(void)
{
    Reserved37_DriverIRQHandler();
}

WEAK void Reserved38_IRQHandler(void)
{
    Reserved38_DriverIRQHandler();
}

WEAK void Reserved39_IRQHandler(void)
{
    Reserved39_DriverIRQHandler();
}

WEAK void Reserved40_IRQHandler(void)
{
    Reserved40_DriverIRQHandler();
}

WEAK void Reserved41_IRQHandler(void)
{
    Reserved41_DriverIRQHandler();
}

WEAK void LPI2C0_IRQHandler(void)
{
    LPI2C0_DriverIRQHandler();
}

WEAK void Reserved43_IRQHandler(void)
{
    Reserved43_DriverIRQHandler();
}

WEAK void LPSPI0_IRQHandler(void)
{
    LPSPI0_DriverIRQHandler();
}

WEAK void Reserved45_IRQHandler(void)
{
    Reserved45_DriverIRQHandler();
}

WEAK void Reserved46_IRQHandler(void)
{
    Reserved46_DriverIRQHandler();
}

WEAK void LPUART0_IRQHandler(void)
{
    LPUART0_DriverIRQHandler();
}

WEAK void LPUART1_IRQHandler(void)
{
    LPUART1_DriverIRQHandler();
}

WEAK void LPUART2_IRQHandler(void)
{
    LPUART2_DriverIRQHandler();
}

WEAK void LPUART3_IRQHandler(void)
{
    LPUART3_DriverIRQHandler();
}

WEAK void LPUART4_IRQHandler(void)
{
    LPUART4_DriverIRQHandler();
}

WEAK void Reserved52_IRQHandler(void)
{
    Reserved52_DriverIRQHandler();
}

WEAK void Reserved53_IRQHandler(void)
{
    Reserved53_DriverIRQHandler();
}

WEAK void Reserved54_IRQHandler(void)
{
    Reserved54_DriverIRQHandler();
}

WEAK void CTIMER0_IRQHandler(void)
{
    CTIMER0_DriverIRQHandler();
}

WEAK void CTIMER1_IRQHandler(void)
{
    CTIMER1_DriverIRQHandler();
}

WEAK void Reserved57_IRQHandler(void)
{
    Reserved57_DriverIRQHandler();
}

WEAK void Reserved58_IRQHandler(void)
{
    Reserved58_DriverIRQHandler();
}

WEAK void Reserved59_IRQHandler(void)
{
    Reserved59_DriverIRQHandler();
}

WEAK void FLEXPWM0_RELOAD_ERROR_IRQHandler(void)
{
    FLEXPWM0_RELOAD_ERROR_DriverIRQHandler();
}

WEAK void FLEXPWM0_FAULT_IRQHandler(void)
{
    FLEXPWM0_FAULT_DriverIRQHandler();
}

WEAK void FLEXPWM0_SUBMODULE0_IRQHandler(void)
{
    FLEXPWM0_SUBMODULE0_DriverIRQHandler();
}

WEAK void FLEXPWM0_SUBMODULE1_IRQHandler(void)
{
    FLEXPWM0_SUBMODULE1_DriverIRQHandler();
}

WEAK void FLEXPWM0_SUBMODULE2_IRQHandler(void)
{
    FLEXPWM0_SUBMODULE2_DriverIRQHandler();
}

WEAK void Reserved65_IRQHandler(void)
{
    Reserved65_DriverIRQHandler();
}

WEAK void EQDC0_COMPARE_IRQHandler(void)
{
    EQDC0_COMPARE_DriverIRQHandler();
}

WEAK void EQDC0_HOME_IRQHandler(void)
{
    EQDC0_HOME_DriverIRQHandler();
}

WEAK void EQDC0_WATCHDOG_IRQHandler(void)
{
    EQDC0_WATCHDOG_DriverIRQHandler();
}

WEAK void EQDC0_INDEX_IRQHandler(void)
{
    EQDC0_INDEX_DriverIRQHandler();
}

WEAK void FREQME0_IRQHandler(void)
{
    FREQME0_DriverIRQHandler();
}

WEAK void LPTMR0_IRQHandler(void)
{
    LPTMR0_DriverIRQHandler();
}

WEAK void Reserved72_IRQHandler(void)
{
    Reserved72_DriverIRQHandler();
}

WEAK void Reserved73_IRQHandler(void)
{
    Reserved73_DriverIRQHandler();
}

WEAK void RTC_IRQHandler(void)
{
    RTC_DriverIRQHandler();
}

WEAK void RTC_1HZ_IRQHandler(void)
{
    RTC_1HZ_DriverIRQHandler();
}

WEAK void WWDT0_IRQHandler(void)
{
    WWDT0_DriverIRQHandler();
}

WEAK void WWDT1_IRQHandler(void)
{
    WWDT1_DriverIRQHandler();
}

WEAK void ADC0_IRQHandler(void)
{
    ADC0_DriverIRQHandler();
}

WEAK void Reserved79_IRQHandler(void)
{
    Reserved79_DriverIRQHandler();
}

WEAK void CMP0_IRQHandler(void)
{
    CMP0_DriverIRQHandler();
}

WEAK void Reserved81_IRQHandler(void)
{
    Reserved81_DriverIRQHandler();
}

WEAK void Reserved82_IRQHandler(void)
{
    Reserved82_DriverIRQHandler();
}

WEAK void Reserved83_IRQHandler(void)
{
    Reserved83_DriverIRQHandler();
}

WEAK void Reserved84_IRQHandler(void)
{
    Reserved84_DriverIRQHandler();
}

WEAK void Reserved85_IRQHandler(void)
{
    Reserved85_DriverIRQHandler();
}

WEAK void Reserved86_IRQHandler(void)
{
    Reserved86_DriverIRQHandler();
}

WEAK void GPIO0_IRQHandler(void)
{
    GPIO0_DriverIRQHandler();
}

WEAK void GPIO1_IRQHandler(void)
{
    GPIO1_DriverIRQHandler();
}

WEAK void GPIO2_IRQHandler(void)
{
    GPIO2_DriverIRQHandler();
}

WEAK void GPIO3_IRQHandler(void)
{
    GPIO3_DriverIRQHandler();
}

//*****************************************************************************

#if defined(DEBUG)
#if defined(__GNUC__)
#pragma GCC pop_options
#endif //(__GNUC__)
#endif //(DEBUG)
