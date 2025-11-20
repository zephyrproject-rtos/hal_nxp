//*****************************************************************************
// MCXA286 startup code
//
// Version : 241125
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
void Reset_Handler_C(void);
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
WEAK void Reserved16_IRQHandler(void);
WEAK void CMC_IRQHandler(void);
WEAK void DMA0_CH0_IRQHandler(void);
WEAK void DMA0_CH1_IRQHandler(void);
WEAK void DMA0_CH2_IRQHandler(void);
WEAK void DMA0_CH3_IRQHandler(void);
WEAK void DMA0_CH4_IRQHandler(void);
WEAK void DMA0_CH5_IRQHandler(void);
WEAK void DMA0_CH6_IRQHandler(void);
WEAK void DMA0_CH7_IRQHandler(void);
WEAK void ERM0_SINGLE_BIT_IRQHandler(void);
WEAK void ERM0_MULTI_BIT_IRQHandler(void);
WEAK void FMU0_IRQHandler(void);
WEAK void GLIKEY0_IRQHandler(void);
WEAK void MBC0_IRQHandler(void);
WEAK void SCG0_IRQHandler(void);
WEAK void SPC0_IRQHandler(void);
WEAK void TDET_IRQHandler(void);
WEAK void WUU0_IRQHandler(void);
WEAK void CAN0_IRQHandler(void);
WEAK void CAN1_IRQHandler(void);
WEAK void Reserved37_IRQHandler(void);
WEAK void Reserved38_IRQHandler(void);
WEAK void FLEXIO_IRQHandler(void);
WEAK void I3C0_IRQHandler(void);
WEAK void I3C1_IRQHandler(void);
WEAK void LPI2C0_IRQHandler(void);
WEAK void LPI2C1_IRQHandler(void);
WEAK void LPSPI0_IRQHandler(void);
WEAK void LPSPI1_IRQHandler(void);
WEAK void LPSPI2_IRQHandler(void);
WEAK void LPUART0_IRQHandler(void);
WEAK void LPUART1_IRQHandler(void);
WEAK void LPUART2_IRQHandler(void);
WEAK void LPUART3_IRQHandler(void);
WEAK void LPUART4_IRQHandler(void);
WEAK void Reserved52_IRQHandler(void);
WEAK void Reserved53_IRQHandler(void);
WEAK void CDOG0_IRQHandler(void);
WEAK void CTIMER0_IRQHandler(void);
WEAK void CTIMER1_IRQHandler(void);
WEAK void CTIMER2_IRQHandler(void);
WEAK void CTIMER3_IRQHandler(void);
WEAK void CTIMER4_IRQHandler(void);
WEAK void Reserved60_IRQHandler(void);
WEAK void Reserved61_IRQHandler(void);
WEAK void Reserved62_IRQHandler(void);
WEAK void Reserved63_IRQHandler(void);
WEAK void Reserved64_IRQHandler(void);
WEAK void Reserved65_IRQHandler(void);
WEAK void Reserved66_IRQHandler(void);
WEAK void Reserved67_IRQHandler(void);
WEAK void Reserved68_IRQHandler(void);
WEAK void Reserved69_IRQHandler(void);
WEAK void FREQME0_IRQHandler(void);
WEAK void LPTMR0_IRQHandler(void);
WEAK void Reserved72_IRQHandler(void);
WEAK void OS_EVENT_IRQHandler(void);
WEAK void WAKETIMER0_IRQHandler(void);
WEAK void UTICK0_IRQHandler(void);
WEAK void WWDT0_IRQHandler(void);
WEAK void WWDT1_IRQHandler(void);
WEAK void ADC0_IRQHandler(void);
WEAK void ADC1_IRQHandler(void);
WEAK void CMP0_IRQHandler(void);
WEAK void Reserved81_IRQHandler(void);
WEAK void Reserved82_IRQHandler(void);
WEAK void DAC0_IRQHandler(void);
WEAK void DAC1_IRQHandler(void);
WEAK void Reserved85_IRQHandler(void);
WEAK void Reserved86_IRQHandler(void);
WEAK void GPIO0_IRQHandler(void);
WEAK void GPIO1_IRQHandler(void);
WEAK void GPIO2_IRQHandler(void);
WEAK void GPIO3_IRQHandler(void);
WEAK void GPIO4_IRQHandler(void);
WEAK void GPIO5_IRQHandler(void);
WEAK void LPI2C2_IRQHandler(void);
WEAK void LPI2C3_IRQHandler(void);
WEAK void Reserved95_IRQHandler(void);
WEAK void Reserved96_IRQHandler(void);
WEAK void Reserved97_IRQHandler(void);
WEAK void Reserved98_IRQHandler(void);
WEAK void Reserved99_IRQHandler(void);
WEAK void Reserved100_IRQHandler(void);
WEAK void Reserved101_IRQHandler(void);
WEAK void Reserved102_IRQHandler(void);
WEAK void Reserved103_IRQHandler(void);
WEAK void Reserved104_IRQHandler(void);
WEAK void ESPI_IRQHandler(void);
WEAK void ETHERNET_IRQHandler(void);
WEAK void ETHERNET_PMT_IRQHandler(void);
WEAK void Reserved108_IRQHandler(void);
WEAK void TENBASET_PHY0_IRQHandler(void);
WEAK void I3C2_IRQHandler(void);
WEAK void LPUART5_IRQHandler(void);
WEAK void Reserved112_IRQHandler(void);
WEAK void LPSPI3_IRQHandler(void);
WEAK void LPSPI4_IRQHandler(void);
WEAK void LPSPI5_IRQHandler(void);
WEAK void LPI2C4_IRQHandler(void);
WEAK void I3C3_IRQHandler(void);
WEAK void Reserved118_IRQHandler(void);
WEAK void USB1_HS_IRQHandler(void);
WEAK void USB1_HS_PHY_IRQHandler(void);
WEAK void Reserved121_IRQHandler(void);
WEAK void FLEXSPI0_IRQHandler(void);
WEAK void Reserved123_IRQHandler(void);
WEAK void SMARTDMA_IRQHandler(void);
WEAK void CDOG1_IRQHandler(void);
WEAK void PKC_IRQHandler(void);
WEAK void SGI_IRQHandler(void);
WEAK void SPI_FILTER_IRQHandler(void);
WEAK void TRNG0_IRQHandler(void);
WEAK void SECURE_ERR_IRQHandler(void);
WEAK void SEC_HYPERVISOR_CALL_IRQHandler(void);
WEAK void Reserved132_IRQHandler(void);
WEAK void Reserved133_IRQHandler(void);
WEAK void Reserved134_IRQHandler(void);
WEAK void RTC_IRQHandler(void);
WEAK void Reserved136_IRQHandler(void);
WEAK void Reserved137_IRQHandler(void);
WEAK void GDET_IRQHandler(void);
WEAK void EWM0_IRQHandler(void);
WEAK void TSI_END_OF_SCAN_IRQHandler(void);
WEAK void TSI_OUT_OF_SCAN_IRQHandler(void);
WEAK void GPIO0_1_IRQHandler(void);
WEAK void GPIO1_1_IRQHandler(void);
WEAK void GPIO2_1_IRQHandler(void);
WEAK void GPIO3_1_IRQHandler(void);
WEAK void GPIO4_1_IRQHandler(void);
WEAK void GPIO5_1_IRQHandler(void);
WEAK void Reserved148_IRQHandler(void);
WEAK void ITRC0_IRQHandler(void);
WEAK void DMA0_CH8_IRQHandler(void);
WEAK void DMA0_CH9_IRQHandler(void);
WEAK void DMA0_CH10_IRQHandler(void);
WEAK void DMA0_CH11_IRQHandler(void);
WEAK void Reserved154_IRQHandler(void);
WEAK void Reserved155_IRQHandler(void);
WEAK void Reserved156_IRQHandler(void);
WEAK void Reserved157_IRQHandler(void);
WEAK void DMA1_CH0_IRQHandler(void);
WEAK void DMA1_CH1_IRQHandler(void);
WEAK void DMA1_CH2_IRQHandler(void);
WEAK void DMA1_CH3_IRQHandler(void);

//*****************************************************************************
// Forward declaration of the driver IRQ handlers. These are aliased
// to the DefaultISR, which is a 'forever' loop. When the driver
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//*****************************************************************************
void Reserved16_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMC_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA0_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA0_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA0_CH2_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA0_CH3_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA0_CH4_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA0_CH5_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA0_CH6_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA0_CH7_DriverIRQHandler(void) ALIAS(DefaultISR);
void ERM0_SINGLE_BIT_DriverIRQHandler(void) ALIAS(DefaultISR);
void ERM0_MULTI_BIT_DriverIRQHandler(void) ALIAS(DefaultISR);
void FMU0_DriverIRQHandler(void) ALIAS(DefaultISR);
void GLIKEY0_DriverIRQHandler(void) ALIAS(DefaultISR);
void MBC0_DriverIRQHandler(void) ALIAS(DefaultISR);
void SCG0_DriverIRQHandler(void) ALIAS(DefaultISR);
void SPC0_DriverIRQHandler(void) ALIAS(DefaultISR);
void TDET_DriverIRQHandler(void) ALIAS(DefaultISR);
void WUU0_DriverIRQHandler(void) ALIAS(DefaultISR);
void CAN0_DriverIRQHandler(void) ALIAS(DefaultISR);
void CAN1_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved37_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved38_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLEXIO_DriverIRQHandler(void) ALIAS(DefaultISR);
void I3C0_DriverIRQHandler(void) ALIAS(DefaultISR);
void I3C1_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPI2C0_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPI2C1_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPSPI0_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPSPI1_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPSPI2_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPUART0_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPUART1_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPUART2_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPUART3_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPUART4_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved52_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved53_DriverIRQHandler(void) ALIAS(DefaultISR);
void CDOG0_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER0_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER1_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER2_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER3_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER4_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved60_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved61_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved62_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved63_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved64_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved65_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved66_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved67_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved68_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved69_DriverIRQHandler(void) ALIAS(DefaultISR);
void FREQME0_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPTMR0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved72_DriverIRQHandler(void) ALIAS(DefaultISR);
void OS_EVENT_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKETIMER0_DriverIRQHandler(void) ALIAS(DefaultISR);
void UTICK0_DriverIRQHandler(void) ALIAS(DefaultISR);
void WWDT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void WWDT1_DriverIRQHandler(void) ALIAS(DefaultISR);
void ADC0_DriverIRQHandler(void) ALIAS(DefaultISR);
void ADC1_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMP0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved81_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved82_DriverIRQHandler(void) ALIAS(DefaultISR);
void DAC0_DriverIRQHandler(void) ALIAS(DefaultISR);
void DAC1_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved85_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved86_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO0_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO1_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO2_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO3_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO4_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO5_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPI2C2_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPI2C3_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved95_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved96_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved97_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved98_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved99_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved100_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved101_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved102_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved103_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved104_DriverIRQHandler(void) ALIAS(DefaultISR);
void ESPI_DriverIRQHandler(void) ALIAS(DefaultISR);
void ETHERNET_DriverIRQHandler(void) ALIAS(DefaultISR);
void ETHERNET_PMT_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved108_DriverIRQHandler(void) ALIAS(DefaultISR);
void TENBASET_PHY0_DriverIRQHandler(void) ALIAS(DefaultISR);
void I3C2_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPUART5_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved112_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPSPI3_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPSPI4_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPSPI5_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPI2C4_DriverIRQHandler(void) ALIAS(DefaultISR);
void I3C3_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved118_DriverIRQHandler(void) ALIAS(DefaultISR);
void USB1_HS_DriverIRQHandler(void) ALIAS(DefaultISR);
void USB1_HS_PHY_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved121_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLEXSPI0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved123_DriverIRQHandler(void) ALIAS(DefaultISR);
void SMARTDMA_DriverIRQHandler(void) ALIAS(DefaultISR);
void CDOG1_DriverIRQHandler(void) ALIAS(DefaultISR);
void PKC_DriverIRQHandler(void) ALIAS(DefaultISR);
void SGI_DriverIRQHandler(void) ALIAS(DefaultISR);
void SPI_FILTER_DriverIRQHandler(void) ALIAS(DefaultISR);
void TRNG0_DriverIRQHandler(void) ALIAS(DefaultISR);
void SECURE_ERR_DriverIRQHandler(void) ALIAS(DefaultISR);
void SEC_HYPERVISOR_CALL_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved132_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved133_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved134_DriverIRQHandler(void) ALIAS(DefaultISR);
void RTC_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved136_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved137_DriverIRQHandler(void) ALIAS(DefaultISR);
void GDET_DriverIRQHandler(void) ALIAS(DefaultISR);
void EWM0_DriverIRQHandler(void) ALIAS(DefaultISR);
void TSI_END_OF_SCAN_DriverIRQHandler(void) ALIAS(DefaultISR);
void TSI_OUT_OF_SCAN_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO0_1_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO1_1_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO2_1_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO3_1_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO4_1_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO5_1_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved148_DriverIRQHandler(void) ALIAS(DefaultISR);
void ITRC0_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA0_CH8_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA0_CH9_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA0_CH10_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA0_CH11_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved154_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved155_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved156_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved157_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA1_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA1_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA1_CH2_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMA1_CH3_DriverIRQHandler(void) ALIAS(DefaultISR);

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

    // Chip Level - MCXA286
    Reserved16_IRQHandler,          // 16 : Reserved interrupt
    CMC_IRQHandler,                 // 17 : Core Mode Controller interrupt
    DMA0_CH0_IRQHandler,            // 18 : DMA3_0_CH0 error or transfer complete
    DMA0_CH1_IRQHandler,            // 19 : DMA3_0_CH1 error or transfer complete
    DMA0_CH2_IRQHandler,            // 20 : DMA3_0_CH2 error or transfer complete
    DMA0_CH3_IRQHandler,            // 21 : DMA3_0_CH3 error or transfer complete
    DMA0_CH4_IRQHandler,            // 22 : DMA3_0_CH4 error or transfer complete
    DMA0_CH5_IRQHandler,            // 23 : DMA3_0_CH5 error or transfer complete
    DMA0_CH6_IRQHandler,            // 24 : DMA3_0_CH6 error or transfer complete
    DMA0_CH7_IRQHandler,            // 25 : DMA3_0_CH7 error or transfer complete
    ERM0_SINGLE_BIT_IRQHandler,     // 26 : ERM Single Bit error interrupt
    ERM0_MULTI_BIT_IRQHandler,      // 27 : ERM Multi Bit error interrupt
    FMU0_IRQHandler,                // 28 : Flash Management Unit interrupt
    GLIKEY0_IRQHandler,             // 29 : GLIKEY Interrupt
    MBC0_IRQHandler,                // 30 : MBC secure violation interrupt
    SCG0_IRQHandler,                // 31 : System Clock Generator interrupt
    SPC0_IRQHandler,                // 32 : System Power Controller interrupt
    TDET_IRQHandler,                // 33 : TDET interrrupt
    WUU0_IRQHandler,                // 34 : Wake Up Unit interrupt
    CAN0_IRQHandler,                // 35 : Controller Area Network 0 interrupt
    CAN1_IRQHandler,                // 36 : Controller Area Network 1 interrupt
    Reserved37_IRQHandler,          // 37 : Reserved interrupt
    Reserved38_IRQHandler,          // 38 : Reserved interrupt
    FLEXIO_IRQHandler,              // 39 : Flexible Input/Output interrupt
    I3C0_IRQHandler,                // 40 : Improved Inter Integrated Circuit interrupt 0
    I3C1_IRQHandler,                // 41 : Improved Inter Integrated Circuit interrupt 1
    LPI2C0_IRQHandler,              // 42 : Low-Power Inter Integrated Circuit 0 interrupt
    LPI2C1_IRQHandler,              // 43 : Low-Power Inter Integrated Circuit 1 interrupt
    LPSPI0_IRQHandler,              // 44 : Low-Power Serial Peripheral Interface 0 interrupt
    LPSPI1_IRQHandler,              // 45 : Low-Power Serial Peripheral Interface 1 interrupt
    LPSPI2_IRQHandler,              // 46 : Low-Power Serial Peripheral Interface 2 interrupt
    LPUART0_IRQHandler,             // 47 : Low-Power Universal Asynchronous Receive/Transmit 0 interrupt
    LPUART1_IRQHandler,             // 48 : Low-Power Universal Asynchronous Receive/Transmit 1 interrupt
    LPUART2_IRQHandler,             // 49 : Low-Power Universal Asynchronous Receive/Transmit 2 interrupt
    LPUART3_IRQHandler,             // 50 : Low-Power Universal Asynchronous Receive/Transmit 3 interrupt
    LPUART4_IRQHandler,             // 51 : Low-Power Universal Asynchronous Receive/Transmit 4 interrupt
    Reserved52_IRQHandler,          // 52 : Reserved interrupt
    Reserved53_IRQHandler,          // 53 : Reserved interrupt
    CDOG0_IRQHandler,               // 54 : Code Watchdog Timer 0 interrupt
    CTIMER0_IRQHandler,             // 55 : Standard counter/timer 0 interrupt
    CTIMER1_IRQHandler,             // 56 : Standard counter/timer 1 interrupt
    CTIMER2_IRQHandler,             // 57 : Standard counter/timer 2 interrupt
    CTIMER3_IRQHandler,             // 58 : Standard counter/timer 3 interrupt
    CTIMER4_IRQHandler,             // 59 : Standard counter/timer 4 interrupt
    Reserved60_IRQHandler,          // 60 : Reserved interrupt
    Reserved61_IRQHandler,          // 61 : Reserved interrupt
    Reserved62_IRQHandler,          // 62 : Reserved interrupt
    Reserved63_IRQHandler,          // 63 : Reserved interrupt
    Reserved64_IRQHandler,          // 64 : Reserved interrupt
    Reserved65_IRQHandler,          // 65 : Reserved interrupt
    Reserved66_IRQHandler,          // 66 : Reserved interrupt
    Reserved67_IRQHandler,          // 67 : Reserved interrupt
    Reserved68_IRQHandler,          // 68 : Reserved interrupt
    Reserved69_IRQHandler,          // 69 : Reserved interrupt
    FREQME0_IRQHandler,             // 70 : Frequency Measurement interrupt
    LPTMR0_IRQHandler,              // 71 : Low Power Timer 0 interrupt
    Reserved72_IRQHandler,          // 72 : Reserved interrupt
    OS_EVENT_IRQHandler,            // 73 : OS event timer interrupt
    WAKETIMER0_IRQHandler,          // 74 : Wake Timer Interrupt
    UTICK0_IRQHandler,              // 75 : Micro-Tick Timer interrupt
    WWDT0_IRQHandler,               // 76 : Windowed Watchdog Timer 0 interrupt
    WWDT1_IRQHandler,               // 77 : Windowed Watchdog Timer 2 interrupt
    ADC0_IRQHandler,                // 78 : Analog-to-Digital Converter 0 interrupt
    ADC1_IRQHandler,                // 79 : Analog-to-Digital Converter 1 interrupt
    CMP0_IRQHandler,                // 80 : Comparator 0 interrupt
    Reserved81_IRQHandler,          // 81 : Reserved interrupt
    Reserved82_IRQHandler,          // 82 : Reserved interrupt
    DAC0_IRQHandler,                // 83 : Digital-to-Analog Converter 0 - General Purpose interrupt
    DAC1_IRQHandler,                // 84 : Digital-to-Analog Converter 1 - General Purpose interrupt
    Reserved85_IRQHandler,          // 85 : Reserved interrupt
    Reserved86_IRQHandler,          // 86 : Reserved interrupt
    GPIO0_IRQHandler,               // 87 : General Purpose Input/Output 0 interrupt 0
    GPIO1_IRQHandler,               // 88 : General Purpose Input/Output 1 interrupt 0
    GPIO2_IRQHandler,               // 89 : General Purpose Input/Output 2 interrupt 0
    GPIO3_IRQHandler,               // 90 : General Purpose Input/Output 3 interrupt 0
    GPIO4_IRQHandler,               // 91 : General Purpose Input/Output 4 interrupt 0
    GPIO5_IRQHandler,               // 92 : General Purpose Input/Output 5 interrupt 0
    LPI2C2_IRQHandler,              // 93 : Low-Power Inter Integrated Circuit 2 interrupt
    LPI2C3_IRQHandler,              // 94 : Low-Power Inter Integrated Circuit 3 interrupt
    Reserved95_IRQHandler,          // 95 : Reserved interrupt
    Reserved96_IRQHandler,          // 96 : Reserved interrupt
    Reserved97_IRQHandler,          // 97 : Reserved interrupt
    Reserved98_IRQHandler,          // 98 : Reserved interrupt
    Reserved99_IRQHandler,          // 99 : Reserved interrupt
    Reserved100_IRQHandler,         // 100: Reserved interrupt
    Reserved101_IRQHandler,         // 101: Reserved interrupt
    Reserved102_IRQHandler,         // 102: Reserved interrupt
    Reserved103_IRQHandler,         // 103: Reserved interrupt
    Reserved104_IRQHandler,         // 104: Reserved interrupt
    ESPI_IRQHandler,                // 105: eSPI interrupt
    ETHERNET_IRQHandler,            // 106: Ethernet QoS interrupt
    ETHERNET_PMT_IRQHandler,        // 107: Ethernet QoS power management interrupt
    Reserved108_IRQHandler,         // 108: Reserved interrupt
    TENBASET_PHY0_IRQHandler,       // 109: 10Base-T1S interrupt
    I3C2_IRQHandler,                // 110: Improved Inter Integrated Circuit interrupt 2
    LPUART5_IRQHandler,             // 111: Low-Power Universal Asynchronous Receive/Transmit interrupt
    Reserved112_IRQHandler,         // 112: Reserved interrupt
    LPSPI3_IRQHandler,              // 113: Low-Power Serial Peripheral Interface 3 interrupt
    LPSPI4_IRQHandler,              // 114: Low-Power Serial Peripheral Interface 4 interrupt
    LPSPI5_IRQHandler,              // 115: Low-Power Serial Peripheral Interface 5 interrupt
    LPI2C4_IRQHandler,              // 116: Low-Power Inter Integrated Circuit 4 interrupt
    I3C3_IRQHandler,                // 117: Improved Inter Integrated Circuit interrupt 3
    Reserved118_IRQHandler,         // 118: Reserved interrupt
    USB1_HS_IRQHandler,             // 119: USB High Speed OTG Controller interrupt
    USB1_HS_PHY_IRQHandler,         // 120: USBHS DCD or USBHS Phy interrupt
    Reserved121_IRQHandler,         // 121: Reserved interrupt
    FLEXSPI0_IRQHandler,            // 122: Flexible Serial Peripheral Interface interrupt
    Reserved123_IRQHandler,         // 123: Reserved interrupt
    SMARTDMA_IRQHandler,            // 124: SmartDMA interrupt
    CDOG1_IRQHandler,               // 125: Code Watchdog Timer 1 interrupt
    PKC_IRQHandler,                 // 126: PKC interrupt
    SGI_IRQHandler,                 // 127: SGI interrupt
    SPI_FILTER_IRQHandler,          // 128: Reserved interrupt
    TRNG0_IRQHandler,               // 129: True Random Number Generator interrupt
    SECURE_ERR_IRQHandler,          // 130: Secure IP Error interrupt. It OR SGI, PKC, TRNG error together.
    SEC_HYPERVISOR_CALL_IRQHandler, // 131: AHB Secure Controller hypervisor call interrupt
    Reserved132_IRQHandler,         // 132: Reserved interrupt
    Reserved133_IRQHandler,         // 133: Reserved interrupt
    Reserved134_IRQHandler,         // 134: Reserved interrupt
    RTC_IRQHandler,                 // 135: RTC alarm interrupt
    Reserved136_IRQHandler,         // 136: Reserved interrupt
    Reserved137_IRQHandler,         // 137: Reserved interrupt
    GDET_IRQHandler,                // 138: Digital Glitch Detect 0 interrupt
    EWM0_IRQHandler,                // 139: External Watchdog Monitor interrupt
    TSI_END_OF_SCAN_IRQHandler,     // 140: TSI End of Scan interrupt
    TSI_OUT_OF_SCAN_IRQHandler,     // 141: TSI Out of Scan interrupt
    GPIO0_1_IRQHandler,             // 142: General Purpose Input/Output 0 interrupt 1
    GPIO1_1_IRQHandler,             // 143: General Purpose Input/Output 1 interrupt 1
    GPIO2_1_IRQHandler,             // 144: General Purpose Input/Output 2 interrupt 1
    GPIO3_1_IRQHandler,             // 145: General Purpose Input/Output 3 interrupt 1
    GPIO4_1_IRQHandler,             // 146: General Purpose Input/Output 4 interrupt 1
    GPIO5_1_IRQHandler,             // 147: General Purpose Input/Output 5 interrupt 1
    Reserved148_IRQHandler,         // 148: Reserved interrupt
    ITRC0_IRQHandler,               // 149: Intrusion and Tamper Response Controller interrupt
    DMA0_CH8_IRQHandler,            // 150: DMA3_0_CH8 error or transfer complete
    DMA0_CH9_IRQHandler,            // 151: DMA3_0_CH9 error or transfer complete
    DMA0_CH10_IRQHandler,           // 152: DMA3_0_CH10 error or transfer complete
    DMA0_CH11_IRQHandler,           // 153: DMA3_0_CH11 error or transfer complete
    Reserved154_IRQHandler,         // 154: Reserved interrupt
    Reserved155_IRQHandler,         // 155: Reserved interrupt
    Reserved156_IRQHandler,         // 156: Reserved interrupt
    Reserved157_IRQHandler,         // 157: Reserved interrupt
    DMA1_CH0_IRQHandler,            // 158: DMA3_1_CH0 error or transfer complete
    DMA1_CH1_IRQHandler,            // 159: DMA3_1_CH1 error or transfer complete
    DMA1_CH2_IRQHandler,            // 160: DMA3_1_CH2 error or transfer complete
    DMA1_CH3_IRQHandler,            // 161: DMA3_1_CH3 error or transfer complete
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
WEAK void Reserved16_IRQHandler(void)
{
    Reserved16_DriverIRQHandler();
}

WEAK void CMC_IRQHandler(void)
{
    CMC_DriverIRQHandler();
}

WEAK void DMA0_CH0_IRQHandler(void)
{
    DMA0_CH0_DriverIRQHandler();
}

WEAK void DMA0_CH1_IRQHandler(void)
{
    DMA0_CH1_DriverIRQHandler();
}

WEAK void DMA0_CH2_IRQHandler(void)
{
    DMA0_CH2_DriverIRQHandler();
}

WEAK void DMA0_CH3_IRQHandler(void)
{
    DMA0_CH3_DriverIRQHandler();
}

WEAK void DMA0_CH4_IRQHandler(void)
{
    DMA0_CH4_DriverIRQHandler();
}

WEAK void DMA0_CH5_IRQHandler(void)
{
    DMA0_CH5_DriverIRQHandler();
}

WEAK void DMA0_CH6_IRQHandler(void)
{
    DMA0_CH6_DriverIRQHandler();
}

WEAK void DMA0_CH7_IRQHandler(void)
{
    DMA0_CH7_DriverIRQHandler();
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

WEAK void GLIKEY0_IRQHandler(void)
{
    GLIKEY0_DriverIRQHandler();
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

WEAK void TDET_IRQHandler(void)
{
    TDET_DriverIRQHandler();
}

WEAK void WUU0_IRQHandler(void)
{
    WUU0_DriverIRQHandler();
}

WEAK void CAN0_IRQHandler(void)
{
    CAN0_DriverIRQHandler();
}

WEAK void CAN1_IRQHandler(void)
{
    CAN1_DriverIRQHandler();
}

WEAK void Reserved37_IRQHandler(void)
{
    Reserved37_DriverIRQHandler();
}

WEAK void Reserved38_IRQHandler(void)
{
    Reserved38_DriverIRQHandler();
}

WEAK void FLEXIO_IRQHandler(void)
{
    FLEXIO_DriverIRQHandler();
}

WEAK void I3C0_IRQHandler(void)
{
    I3C0_DriverIRQHandler();
}

WEAK void I3C1_IRQHandler(void)
{
    I3C1_DriverIRQHandler();
}

WEAK void LPI2C0_IRQHandler(void)
{
    LPI2C0_DriverIRQHandler();
}

WEAK void LPI2C1_IRQHandler(void)
{
    LPI2C1_DriverIRQHandler();
}

WEAK void LPSPI0_IRQHandler(void)
{
    LPSPI0_DriverIRQHandler();
}

WEAK void LPSPI1_IRQHandler(void)
{
    LPSPI1_DriverIRQHandler();
}

WEAK void LPSPI2_IRQHandler(void)
{
    LPSPI2_DriverIRQHandler();
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

WEAK void CDOG0_IRQHandler(void)
{
    CDOG0_DriverIRQHandler();
}

WEAK void CTIMER0_IRQHandler(void)
{
    CTIMER0_DriverIRQHandler();
}

WEAK void CTIMER1_IRQHandler(void)
{
    CTIMER1_DriverIRQHandler();
}

WEAK void CTIMER2_IRQHandler(void)
{
    CTIMER2_DriverIRQHandler();
}

WEAK void CTIMER3_IRQHandler(void)
{
    CTIMER3_DriverIRQHandler();
}

WEAK void CTIMER4_IRQHandler(void)
{
    CTIMER4_DriverIRQHandler();
}

WEAK void Reserved60_IRQHandler(void)
{
    Reserved60_DriverIRQHandler();
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

WEAK void Reserved65_IRQHandler(void)
{
    Reserved65_DriverIRQHandler();
}

WEAK void Reserved66_IRQHandler(void)
{
    Reserved66_DriverIRQHandler();
}

WEAK void Reserved67_IRQHandler(void)
{
    Reserved67_DriverIRQHandler();
}

WEAK void Reserved68_IRQHandler(void)
{
    Reserved68_DriverIRQHandler();
}

WEAK void Reserved69_IRQHandler(void)
{
    Reserved69_DriverIRQHandler();
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

WEAK void OS_EVENT_IRQHandler(void)
{
    OS_EVENT_DriverIRQHandler();
}

WEAK void WAKETIMER0_IRQHandler(void)
{
    WAKETIMER0_DriverIRQHandler();
}

WEAK void UTICK0_IRQHandler(void)
{
    UTICK0_DriverIRQHandler();
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

WEAK void ADC1_IRQHandler(void)
{
    ADC1_DriverIRQHandler();
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

WEAK void DAC0_IRQHandler(void)
{
    DAC0_DriverIRQHandler();
}

WEAK void DAC1_IRQHandler(void)
{
    DAC1_DriverIRQHandler();
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

WEAK void GPIO4_IRQHandler(void)
{
    GPIO4_DriverIRQHandler();
}

WEAK void GPIO5_IRQHandler(void)
{
    GPIO5_DriverIRQHandler();
}

WEAK void LPI2C2_IRQHandler(void)
{
    LPI2C2_DriverIRQHandler();
}

WEAK void LPI2C3_IRQHandler(void)
{
    LPI2C3_DriverIRQHandler();
}

WEAK void Reserved95_IRQHandler(void)
{
    Reserved95_DriverIRQHandler();
}

WEAK void Reserved96_IRQHandler(void)
{
    Reserved96_DriverIRQHandler();
}

WEAK void Reserved97_IRQHandler(void)
{
    Reserved97_DriverIRQHandler();
}

WEAK void Reserved98_IRQHandler(void)
{
    Reserved98_DriverIRQHandler();
}

WEAK void Reserved99_IRQHandler(void)
{
    Reserved99_DriverIRQHandler();
}

WEAK void Reserved100_IRQHandler(void)
{
    Reserved100_DriverIRQHandler();
}

WEAK void Reserved101_IRQHandler(void)
{
    Reserved101_DriverIRQHandler();
}

WEAK void Reserved102_IRQHandler(void)
{
    Reserved102_DriverIRQHandler();
}

WEAK void Reserved103_IRQHandler(void)
{
    Reserved103_DriverIRQHandler();
}

WEAK void Reserved104_IRQHandler(void)
{
    Reserved104_DriverIRQHandler();
}

WEAK void ESPI_IRQHandler(void)
{
    ESPI_DriverIRQHandler();
}

WEAK void ETHERNET_IRQHandler(void)
{
    ETHERNET_DriverIRQHandler();
}

WEAK void ETHERNET_PMT_IRQHandler(void)
{
    ETHERNET_PMT_DriverIRQHandler();
}

WEAK void Reserved108_IRQHandler(void)
{
    Reserved108_DriverIRQHandler();
}

WEAK void TENBASET_PHY0_IRQHandler(void)
{
    TENBASET_PHY0_DriverIRQHandler();
}

WEAK void I3C2_IRQHandler(void)
{
    I3C2_DriverIRQHandler();
}

WEAK void LPUART5_IRQHandler(void)
{
    LPUART5_DriverIRQHandler();
}

WEAK void Reserved112_IRQHandler(void)
{
    Reserved112_DriverIRQHandler();
}

WEAK void LPSPI3_IRQHandler(void)
{
    LPSPI3_DriverIRQHandler();
}

WEAK void LPSPI4_IRQHandler(void)
{
    LPSPI4_DriverIRQHandler();
}

WEAK void LPSPI5_IRQHandler(void)
{
    LPSPI5_DriverIRQHandler();
}

WEAK void LPI2C4_IRQHandler(void)
{
    LPI2C4_DriverIRQHandler();
}

WEAK void I3C3_IRQHandler(void)
{
    I3C3_DriverIRQHandler();
}

WEAK void Reserved118_IRQHandler(void)
{
    Reserved118_DriverIRQHandler();
}

WEAK void USB1_HS_IRQHandler(void)
{
    USB1_HS_DriverIRQHandler();
}

WEAK void USB1_HS_PHY_IRQHandler(void)
{
    USB1_HS_PHY_DriverIRQHandler();
}

WEAK void Reserved121_IRQHandler(void)
{
    Reserved121_DriverIRQHandler();
}

WEAK void FLEXSPI0_IRQHandler(void)
{
    FLEXSPI0_DriverIRQHandler();
}

WEAK void Reserved123_IRQHandler(void)
{
    Reserved123_DriverIRQHandler();
}

WEAK void SMARTDMA_IRQHandler(void)
{
    SMARTDMA_DriverIRQHandler();
}

WEAK void CDOG1_IRQHandler(void)
{
    CDOG1_DriverIRQHandler();
}

WEAK void PKC_IRQHandler(void)
{
    PKC_DriverIRQHandler();
}

WEAK void SGI_IRQHandler(void)
{
    SGI_DriverIRQHandler();
}

WEAK void SPI_FILTER_IRQHandler(void)
{
    SPI_FILTER_DriverIRQHandler();
}

WEAK void TRNG0_IRQHandler(void)
{
    TRNG0_DriverIRQHandler();
}

WEAK void SECURE_ERR_IRQHandler(void)
{
    SECURE_ERR_DriverIRQHandler();
}

WEAK void SEC_HYPERVISOR_CALL_IRQHandler(void)
{
    SEC_HYPERVISOR_CALL_DriverIRQHandler();
}

WEAK void Reserved132_IRQHandler(void)
{
    Reserved132_DriverIRQHandler();
}

WEAK void Reserved133_IRQHandler(void)
{
    Reserved133_DriverIRQHandler();
}

WEAK void Reserved134_IRQHandler(void)
{
    Reserved134_DriverIRQHandler();
}

WEAK void RTC_IRQHandler(void)
{
    RTC_DriverIRQHandler();
}

WEAK void Reserved136_IRQHandler(void)
{
    Reserved136_DriverIRQHandler();
}

WEAK void Reserved137_IRQHandler(void)
{
    Reserved137_DriverIRQHandler();
}

WEAK void GDET_IRQHandler(void)
{
    GDET_DriverIRQHandler();
}

WEAK void EWM0_IRQHandler(void)
{
    EWM0_DriverIRQHandler();
}

WEAK void TSI_END_OF_SCAN_IRQHandler(void)
{
    TSI_END_OF_SCAN_DriverIRQHandler();
}

WEAK void TSI_OUT_OF_SCAN_IRQHandler(void)
{
    TSI_OUT_OF_SCAN_DriverIRQHandler();
}

WEAK void GPIO0_1_IRQHandler(void)
{
    GPIO0_1_DriverIRQHandler();
}

WEAK void GPIO1_1_IRQHandler(void)
{
    GPIO1_1_DriverIRQHandler();
}

WEAK void GPIO2_1_IRQHandler(void)
{
    GPIO2_1_DriverIRQHandler();
}

WEAK void GPIO3_1_IRQHandler(void)
{
    GPIO3_1_DriverIRQHandler();
}

WEAK void GPIO4_1_IRQHandler(void)
{
    GPIO4_1_DriverIRQHandler();
}

WEAK void GPIO5_1_IRQHandler(void)
{
    GPIO5_1_DriverIRQHandler();
}

WEAK void Reserved148_IRQHandler(void)
{
    Reserved148_DriverIRQHandler();
}

WEAK void ITRC0_IRQHandler(void)
{
    ITRC0_DriverIRQHandler();
}

WEAK void DMA0_CH8_IRQHandler(void)
{
    DMA0_CH8_DriverIRQHandler();
}

WEAK void DMA0_CH9_IRQHandler(void)
{
    DMA0_CH9_DriverIRQHandler();
}

WEAK void DMA0_CH10_IRQHandler(void)
{
    DMA0_CH10_DriverIRQHandler();
}

WEAK void DMA0_CH11_IRQHandler(void)
{
    DMA0_CH11_DriverIRQHandler();
}

WEAK void Reserved154_IRQHandler(void)
{
    Reserved154_DriverIRQHandler();
}

WEAK void Reserved155_IRQHandler(void)
{
    Reserved155_DriverIRQHandler();
}

WEAK void Reserved156_IRQHandler(void)
{
    Reserved156_DriverIRQHandler();
}

WEAK void Reserved157_IRQHandler(void)
{
    Reserved157_DriverIRQHandler();
}

WEAK void DMA1_CH0_IRQHandler(void)
{
    DMA1_CH0_DriverIRQHandler();
}

WEAK void DMA1_CH1_IRQHandler(void)
{
    DMA1_CH1_DriverIRQHandler();
}

WEAK void DMA1_CH2_IRQHandler(void)
{
    DMA1_CH2_DriverIRQHandler();
}

WEAK void DMA1_CH3_IRQHandler(void)
{
    DMA1_CH3_DriverIRQHandler();
}

//*****************************************************************************

#if defined(DEBUG)
#if defined(__GNUC__)
#pragma GCC pop_options
#endif //(__GNUC__)
#endif //(DEBUG)
