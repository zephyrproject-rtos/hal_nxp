//*****************************************************************************
// MCXW235 startup code
//
// Version : 130525
//*****************************************************************************
//
// Copyright 2016-2025 NXP
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
WEAK void NMI_Handler(void);
WEAK void HardFault_Handler(void);
WEAK void MemManage_Handler(void);
WEAK void BusFault_Handler(void);
WEAK void UsageFault_Handler(void);
WEAK void SecureFault_Handler(void);
WEAK void SVC_Handler(void);
WEAK void DebugMon_Handler(void);
WEAK void PendSV_Handler(void);
WEAK void SysTick_Handler(void);
WEAK void DefaultISR(void);

//*****************************************************************************
// Forward declaration of the application IRQ handlers. When the application
// defines a handler (with the same name), this will automatically take
// precedence over weak definitions below
//*****************************************************************************
WEAK void WDT_BOD_IRQHandler(void);
WEAK void DMA0_IRQHandler(void);
WEAK void GINT0_IRQHandler(void);
WEAK void Reserved19_IRQHandler(void);
WEAK void PIN_INT0_IRQHandler(void);
WEAK void PIN_INT1_IRQHandler(void);
WEAK void PIN_INT2_IRQHandler(void);
WEAK void PIN_INT3_IRQHandler(void);
WEAK void UTICK0_IRQHandler(void);
WEAK void MRT0_IRQHandler(void);
WEAK void CTIMER0_IRQHandler(void);
WEAK void CTIMER1_IRQHandler(void);
WEAK void SCT0_IRQHandler(void);
WEAK void CTIMER3_IRQHandler(void);
WEAK void FLEXCOMM0_IRQHandler(void);
WEAK void FLEXCOMM1_IRQHandler(void);
WEAK void FLEXCOMM2_IRQHandler(void);
WEAK void Reserved33_IRQHandler(void);
WEAK void Reserved34_IRQHandler(void);
WEAK void Reserved35_IRQHandler(void);
WEAK void Reserved36_IRQHandler(void);
WEAK void Reserved37_IRQHandler(void);
WEAK void BLE_LL_IRQHandler(void);
WEAK void BLE_SLP_TMR_IRQHandler(void);
WEAK void WDT_IRQHandler(void);
WEAK void Reserved41_IRQHandler(void);
WEAK void Reserved42_IRQHandler(void);
WEAK void BOD1_IRQHandler(void);
WEAK void BOD2_IRQHandler(void);
WEAK void RTC_IRQHandler(void);
WEAK void Reserved46_IRQHandler(void);
WEAK void WAKE_DSLP_IRQHandler(void);
WEAK void PIN_INT4_IRQHandler(void);
WEAK void PIN_INT5_IRQHandler(void);
WEAK void PIN_INT6_IRQHandler(void);
WEAK void PIN_INT7_IRQHandler(void);
WEAK void CTIMER2_IRQHandler(void);
WEAK void CTIMER4_IRQHandler(void);
WEAK void OS_EVENT_IRQHandler(void);
WEAK void SPIFI_IRQHandler(void);
WEAK void Reserved56_IRQHandler(void);
WEAK void Reserved57_IRQHandler(void);
WEAK void Reserved58_IRQHandler(void);
WEAK void FLASH_CCIF_IRQHandler(void);
WEAK void FLASH_DFIF_IRQHandler(void);
WEAK void Reserved61_IRQHandler(void);
WEAK void Reserved62_IRQHandler(void);
WEAK void Reserved63_IRQHandler(void);
WEAK void Reserved64_IRQHandler(void);
WEAK void SEC_HYPERVISOR_CALL_IRQHandler(void);
WEAK void SEC_GPIO_INT0_IRQ0_IRQHandler(void);
WEAK void SEC_GPIO_INT0_IRQ1_IRQHandler(void);
WEAK void PLU_IRQHandler(void);
WEAK void SEC_VIO_IRQHandler(void);
WEAK void HASHCRYPT_IRQHandler(void);
WEAK void CASPER_IRQHandler(void);
WEAK void PUF_IRQHandler(void);
WEAK void TRNG_IRQHandler(void);
WEAK void DMA1_IRQHandler(void);
WEAK void Reserved75_IRQHandler(void);
WEAK void CDOG_IRQHandler(void);
WEAK void Reserved77_IRQHandler(void);
WEAK void Reserved78_IRQHandler(void);
WEAK void WAKE_PAD_IRQHandler(void);

//*****************************************************************************
// Forward declaration of the driver IRQ handlers. These are aliased
// to the DefaultISR, which is a 'forever' loop. When the driver
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//*****************************************************************************
void WDT_BOD_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA0_DriverIRQHandler(void) ALIAS(DefaultISR);
void GINT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved19_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIN_INT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIN_INT1_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIN_INT2_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIN_INT3_DriverIRQHandler(void) ALIAS(DefaultISR);
void UTICK0_DriverIRQHandler(void) ALIAS(DefaultISR);
void MRT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER0_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER1_DriverIRQHandler(void) ALIAS(DefaultISR);
void SCT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER3_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLEXCOMM0_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLEXCOMM1_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLEXCOMM2_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved33_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved34_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved35_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved36_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved37_DriverIRQHandler(void) ALIAS(DefaultISR);
void BLE_LL_DriverIRQHandler(void) ALIAS(DefaultISR);
void BLE_SLP_TMR_DriverIRQHandler(void) ALIAS(DefaultISR);
void WDT_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved41_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved42_DriverIRQHandler(void) ALIAS(DefaultISR);
void BOD1_DriverIRQHandler(void) ALIAS(DefaultISR);
void BOD2_DriverIRQHandler(void) ALIAS(DefaultISR);
void RTC_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved46_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_DSLP_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIN_INT4_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIN_INT5_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIN_INT6_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIN_INT7_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER2_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER4_DriverIRQHandler(void) ALIAS(DefaultISR);
void OS_EVENT_DriverIRQHandler(void) ALIAS(DefaultISR);
void SPIFI_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved56_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved57_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved58_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLASH_CCIF_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLASH_DFIF_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved61_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved62_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved63_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved64_DriverIRQHandler(void) ALIAS(DefaultISR);
void SEC_HYPERVISOR_CALL_DriverIRQHandler(void) ALIAS(DefaultISR);
void SEC_GPIO_INT0_IRQ0_DriverIRQHandler(void) ALIAS(DefaultISR);
void SEC_GPIO_INT0_IRQ1_DriverIRQHandler(void) ALIAS(DefaultISR);
void PLU_DriverIRQHandler(void) ALIAS(DefaultISR);
void SEC_VIO_DriverIRQHandler(void) ALIAS(DefaultISR);
void HASHCRYPT_DriverIRQHandler(void) ALIAS(DefaultISR);
void CASPER_DriverIRQHandler(void) ALIAS(DefaultISR);
void PUF_DriverIRQHandler(void) ALIAS(DefaultISR);
void TRNG_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA1_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved75_DriverIRQHandler(void) ALIAS(DefaultISR);
void CDOG_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved77_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved78_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_PAD_DriverIRQHandler(void) ALIAS(DefaultISR);

//*****************************************************************************
// The entry point for the application.
// __main() is the entry point for Redlib based applications
// main() is the entry point for Newlib based applications
//*****************************************************************************
#if defined(__MCUXPRESSO)
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
    // Core Level - CM33
    (void (*)())((uint32_t)_vStackTop), // The initial stack pointer
    Reset_Handler,                      // The reset handler

    NMI_Handler,                        // NMI Handler
    HardFault_Handler,                  // Hard Fault Handler
    MemManage_Handler,                  // MPU Fault Handler
    BusFault_Handler,                   // Bus Fault Handler
    UsageFault_Handler,                 // Usage Fault Handler
    SecureFault_Handler,                // Secure Fault Handler
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    SVC_Handler,                        // SVCall Handler
    DebugMon_Handler,                   // Debug Monitor Handler
    0,                                  // Reserved
    PendSV_Handler,                     // PendSV Handler
    SysTick_Handler,                    // SysTick Handler

    // Chip Level - MCXW235
    WDT_BOD_IRQHandler,             // 16: Windowed watchdog timer, Brownout detect, Flash interrupt
    DMA0_IRQHandler,                // 17: DMA0 controller
    GINT0_IRQHandler,               // 18: GPIO group 0
    Reserved19_IRQHandler,          // 19: Reserved interrupt
    PIN_INT0_IRQHandler,            // 20: Pin interrupt 0 or pattern match engine slice 0
    PIN_INT1_IRQHandler,            // 21: Pin interrupt 1or pattern match engine slice 1
    PIN_INT2_IRQHandler,            // 22: Pin interrupt 2 or pattern match engine slice 2
    PIN_INT3_IRQHandler,            // 23: Pin interrupt 3 or pattern match engine slice 3
    UTICK0_IRQHandler,              // 24: Micro-tick Timer
    MRT0_IRQHandler,                // 25: Multi-rate timer
    CTIMER0_IRQHandler,             // 26: Standard counter/timer CTIMER0
    CTIMER1_IRQHandler,             // 27: Standard counter/timer CTIMER1
    SCT0_IRQHandler,                // 28: SCTimer/PWM
    CTIMER3_IRQHandler,             // 29: Standard counter/timer CTIMER3
    FLEXCOMM0_IRQHandler,           // 30: Flexcomm Interface 0 (USART, SPI, I2C, FLEXCOMM)
    FLEXCOMM1_IRQHandler,           // 31: Flexcomm Interface 1 (USART, SPI, I2C, FLEXCOMM)
    FLEXCOMM2_IRQHandler,           // 32: Flexcomm Interface 2 (USART, SPI, I2C, FLEXCOMM)
    Reserved33_IRQHandler,          // 33: Reserved interrupt
    Reserved34_IRQHandler,          // 34: Reserved interrupt
    Reserved35_IRQHandler,          // 35: Reserved interrupt
    Reserved36_IRQHandler,          // 36: Reserved interrupt
    Reserved37_IRQHandler,          // 37: Reserved interrupt
    BLE_LL_IRQHandler,              // 38: BLE Link Layer interrupt
    BLE_SLP_TMR_IRQHandler,         // 39: BLE Sleep Timer interrupt
    WDT_IRQHandler,                 // 40: Windowed Watchdog interrupt
    Reserved41_IRQHandler,          // 41: Reserved interrupt
    Reserved42_IRQHandler,          // 42: Reserved interrupt
    BOD1_IRQHandler,                // 43: Brown-out detector 1 interrupt
    BOD2_IRQHandler,                // 44: Brown-out detector 2 interrupt
    RTC_IRQHandler,                 // 45: RTC alarm and wake-up interrupts
    Reserved46_IRQHandler,          // 46: Reserved interrupt
    WAKE_DSLP_IRQHandler,           // 47: Wakeup from deepsleep interrupt
    PIN_INT4_IRQHandler,            // 48: Pin interrupt 4 or pattern match engine slice 4 int
    PIN_INT5_IRQHandler,            // 49: Pin interrupt 5 or pattern match engine slice 5 int
    PIN_INT6_IRQHandler,            // 50: Pin interrupt 6 or pattern match engine slice 6 int
    PIN_INT7_IRQHandler,            // 51: Pin interrupt 7 or pattern match engine slice 7 int
    CTIMER2_IRQHandler,             // 52: Standard counter/timer CTIMER2
    CTIMER4_IRQHandler,             // 53: Standard counter/timer CTIMER4
    OS_EVENT_IRQHandler,            // 54: OS_EVENT_TIMER and OS_EVENT_WAKEUP interrupts
    SPIFI_IRQHandler,               // 55: QuadSPI Flash interface interrupt
    Reserved56_IRQHandler,          // 56: Reserved interrupt
    Reserved57_IRQHandler,          // 57: Reserved interrupt
    Reserved58_IRQHandler,          // 58: Reserved interrupt
    FLASH_CCIF_IRQHandler,          // 59: Flash command complete interrupt
    FLASH_DFIF_IRQHandler,          // 60: Flash ECC double-bit error detect interrupt
    Reserved61_IRQHandler,          // 61: Reserved interrupt
    Reserved62_IRQHandler,          // 62: Reserved interrupt
    Reserved63_IRQHandler,          // 63: Reserved interrupt
    Reserved64_IRQHandler,          // 64: Reserved interrupt
    SEC_HYPERVISOR_CALL_IRQHandler, // 65: SEC_HYPERVISOR_CALL interrupt
    SEC_GPIO_INT0_IRQ0_IRQHandler,  // 66: SEC_GPIO_INT0_IRQ0 interrupt
    SEC_GPIO_INT0_IRQ1_IRQHandler,  // 67: SEC_GPIO_INT0_IRQ1 interrupt
    PLU_IRQHandler,                 // 68: PLU interrupt
    SEC_VIO_IRQHandler,             // 69: SEC_VIO interrupt
    HASHCRYPT_IRQHandler,           // 70: SHA interrupt
    CASPER_IRQHandler,              // 71: CASPER interrupt
    PUF_IRQHandler,                 // 72: PUF interrupt
    TRNG_IRQHandler,                // 73: TRNG interrupt
    DMA1_IRQHandler,                // 74: DMA1 interrupt
    Reserved75_IRQHandler,          // 75: Reserved interrupt
    CDOG_IRQHandler,                // 76: CDOG interrupt
    Reserved77_IRQHandler,          // 77: Reserved interrupt
    Reserved78_IRQHandler,          // 78: Reserved interrupt
    WAKE_PAD_IRQHandler,            // 79: Wakeup from pin interrupt
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
        "MSR MSPLIM, %1       \n"
        :
        : "r"(__vector_table), "r"(_vStackBase)
        : "r0", "r1");

#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
    __asm volatile(
        "LDR R0, =SystemInit \n"
        "BLX R0              \n"
        "cpsie i             \n"
        "LDR R0, =__main     \n"
        "BX  R0              \n");
#elif defined(__MCUXPRESSO)
    SystemInit();

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
    SystemInit();
    // Reenable interrupts
    __asm volatile("cpsie i");

    __iar_program_start();
#elif defined(__GNUC__)
#if !defined(__NO_SYSTEM_INIT)
    SystemInit();
#endif //(__NO_SYSTEM_INIT)
    /*     Loop to copy data from read only memory to RAM. The ranges
     *      of copy from/to are specified by following symbols evaluated in
     *      linker script.
     *      1. __etext/_data_start__/__data_end__
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

WEAK_AV void MemManage_Handler(void)
{
    while (1)
    {
    }
}

WEAK_AV void BusFault_Handler(void)
{
    while (1)
    {
    }
}

WEAK_AV void UsageFault_Handler(void)
{
    while (1)
    {
    }
}

WEAK_AV void SecureFault_Handler(void)
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

WEAK_AV void DebugMon_Handler(void)
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
WEAK void WDT_BOD_IRQHandler(void)
{
    WDT_BOD_DriverIRQHandler();
}

WEAK void DMA0_IRQHandler(void)
{
    DMA0_DriverIRQHandler();
}

WEAK void GINT0_IRQHandler(void)
{
    GINT0_DriverIRQHandler();
}

WEAK void Reserved19_IRQHandler(void)
{
    Reserved19_DriverIRQHandler();
}

WEAK void PIN_INT0_IRQHandler(void)
{
    PIN_INT0_DriverIRQHandler();
}

WEAK void PIN_INT1_IRQHandler(void)
{
    PIN_INT1_DriverIRQHandler();
}

WEAK void PIN_INT2_IRQHandler(void)
{
    PIN_INT2_DriverIRQHandler();
}

WEAK void PIN_INT3_IRQHandler(void)
{
    PIN_INT3_DriverIRQHandler();
}

WEAK void UTICK0_IRQHandler(void)
{
    UTICK0_DriverIRQHandler();
}

WEAK void MRT0_IRQHandler(void)
{
    MRT0_DriverIRQHandler();
}

WEAK void CTIMER0_IRQHandler(void)
{
    CTIMER0_DriverIRQHandler();
}

WEAK void CTIMER1_IRQHandler(void)
{
    CTIMER1_DriverIRQHandler();
}

WEAK void SCT0_IRQHandler(void)
{
    SCT0_DriverIRQHandler();
}

WEAK void CTIMER3_IRQHandler(void)
{
    CTIMER3_DriverIRQHandler();
}

WEAK void FLEXCOMM0_IRQHandler(void)
{
    FLEXCOMM0_DriverIRQHandler();
}

WEAK void FLEXCOMM1_IRQHandler(void)
{
    FLEXCOMM1_DriverIRQHandler();
}

WEAK void FLEXCOMM2_IRQHandler(void)
{
    FLEXCOMM2_DriverIRQHandler();
}

WEAK void Reserved33_IRQHandler(void)
{
    Reserved33_DriverIRQHandler();
}

WEAK void Reserved34_IRQHandler(void)
{
    Reserved34_DriverIRQHandler();
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

WEAK void BLE_LL_IRQHandler(void)
{
    BLE_LL_DriverIRQHandler();
}

WEAK void BLE_SLP_TMR_IRQHandler(void)
{
    BLE_SLP_TMR_DriverIRQHandler();
}

WEAK void WDT_IRQHandler(void)
{
    WDT_DriverIRQHandler();
}

WEAK void Reserved41_IRQHandler(void)
{
    Reserved41_DriverIRQHandler();
}

WEAK void Reserved42_IRQHandler(void)
{
    Reserved42_DriverIRQHandler();
}

WEAK void BOD1_IRQHandler(void)
{
    BOD1_DriverIRQHandler();
}

WEAK void BOD2_IRQHandler(void)
{
    BOD2_DriverIRQHandler();
}

WEAK void RTC_IRQHandler(void)
{
    RTC_DriverIRQHandler();
}

WEAK void Reserved46_IRQHandler(void)
{
    Reserved46_DriverIRQHandler();
}

WEAK void WAKE_DSLP_IRQHandler(void)
{
    WAKE_DSLP_DriverIRQHandler();
}

WEAK void PIN_INT4_IRQHandler(void)
{
    PIN_INT4_DriverIRQHandler();
}

WEAK void PIN_INT5_IRQHandler(void)
{
    PIN_INT5_DriverIRQHandler();
}

WEAK void PIN_INT6_IRQHandler(void)
{
    PIN_INT6_DriverIRQHandler();
}

WEAK void PIN_INT7_IRQHandler(void)
{
    PIN_INT7_DriverIRQHandler();
}

WEAK void CTIMER2_IRQHandler(void)
{
    CTIMER2_DriverIRQHandler();
}

WEAK void CTIMER4_IRQHandler(void)
{
    CTIMER4_DriverIRQHandler();
}

WEAK void OS_EVENT_IRQHandler(void)
{
    OS_EVENT_DriverIRQHandler();
}

WEAK void SPIFI_IRQHandler(void)
{
    SPIFI_DriverIRQHandler();
}

WEAK void Reserved56_IRQHandler(void)
{
    Reserved56_DriverIRQHandler();
}

WEAK void Reserved57_IRQHandler(void)
{
    Reserved57_DriverIRQHandler();
}

WEAK void Reserved58_IRQHandler(void)
{
    Reserved58_DriverIRQHandler();
}

WEAK void FLASH_CCIF_IRQHandler(void)
{
    FLASH_CCIF_DriverIRQHandler();
}

WEAK void FLASH_DFIF_IRQHandler(void)
{
    FLASH_DFIF_DriverIRQHandler();
}

WEAK void Reserved61_IRQHandler(void)
{
    Reserved61_DriverIRQHandler();
}

WEAK void Reserved62_IRQHandler(void)
{
    Reserved62_DriverIRQHandler();
}

WEAK void Reserved63_IRQHandler(void)
{
    Reserved63_DriverIRQHandler();
}

WEAK void Reserved64_IRQHandler(void)
{
    Reserved64_DriverIRQHandler();
}

WEAK void SEC_HYPERVISOR_CALL_IRQHandler(void)
{
    SEC_HYPERVISOR_CALL_DriverIRQHandler();
}

WEAK void SEC_GPIO_INT0_IRQ0_IRQHandler(void)
{
    SEC_GPIO_INT0_IRQ0_DriverIRQHandler();
}

WEAK void SEC_GPIO_INT0_IRQ1_IRQHandler(void)
{
    SEC_GPIO_INT0_IRQ1_DriverIRQHandler();
}

WEAK void PLU_IRQHandler(void)
{
    PLU_DriverIRQHandler();
}

WEAK void SEC_VIO_IRQHandler(void)
{
    SEC_VIO_DriverIRQHandler();
}

WEAK void HASHCRYPT_IRQHandler(void)
{
    HASHCRYPT_DriverIRQHandler();
}

WEAK void CASPER_IRQHandler(void)
{
    CASPER_DriverIRQHandler();
}

WEAK void PUF_IRQHandler(void)
{
    PUF_DriverIRQHandler();
}

WEAK void TRNG_IRQHandler(void)
{
    TRNG_DriverIRQHandler();
}

WEAK void DMA1_IRQHandler(void)
{
    DMA1_DriverIRQHandler();
}

WEAK void Reserved75_IRQHandler(void)
{
    Reserved75_DriverIRQHandler();
}

WEAK void CDOG_IRQHandler(void)
{
    CDOG_DriverIRQHandler();
}

WEAK void Reserved77_IRQHandler(void)
{
    Reserved77_DriverIRQHandler();
}

WEAK void Reserved78_IRQHandler(void)
{
    Reserved78_DriverIRQHandler();
}

WEAK void WAKE_PAD_IRQHandler(void)
{
    WAKE_PAD_DriverIRQHandler();
}

//*****************************************************************************

#if defined(DEBUG)
#if defined(__GNUC__)
#pragma GCC pop_options
#endif //(__GNUC__)
#endif //(DEBUG)
