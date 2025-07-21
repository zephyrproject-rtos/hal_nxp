//*****************************************************************************
// MIMXRT735S_cm33_core0 startup code
//
// Version : 200525
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
WEAK void Reserved16_IRQHandler(void);
WEAK void UTICK0_IRQHandler(void);
WEAK void MRT0_IRQHandler(void);
WEAK void CTIMER0_IRQHandler(void);
WEAK void CTIMER1_IRQHandler(void);
WEAK void SCT0_IRQHandler(void);
WEAK void CTIMER3_IRQHandler(void);
WEAK void LP_FLEXCOMM0_IRQHandler(void);
WEAK void LP_FLEXCOMM1_IRQHandler(void);
WEAK void LP_FLEXCOMM2_IRQHandler(void);
WEAK void LP_FLEXCOMM3_IRQHandler(void);
WEAK void LP_FLEXCOMM4_IRQHandler(void);
WEAK void LP_FLEXCOMM5_IRQHandler(void);
WEAK void LPSPI14_IRQHandler(void);
WEAK void LPI2C15_IRQHandler(void);
WEAK void ADC_IRQHandler(void);
WEAK void SDADC_IRQHandler(void);
WEAK void ACMP_IRQHandler(void);
WEAK void PDM_EVENT_IRQHandler(void);
WEAK void PDM_HWVAD_EVENT_IRQHandler(void);
WEAK void HYPERVISOR_IRQHandler(void);
WEAK void SECURE_VIOLATION_IRQHandler(void);
WEAK void SENSE_HYPERVISOR_IRQHandler(void);
WEAK void SENSE_SECURE_VIOLATION_IRQHandler(void);
WEAK void MEDIA_HYPERVISOR_IRQHandler(void);
WEAK void MEDIA_SECURE_VIOLATION_IRQHandler(void);
WEAK void RTC0_ALARM_IRQHandler(void);
WEAK void RTC0_IRQHandler(void);
WEAK void Reserved44_IRQHandler(void);
WEAK void MU0_A_IRQHandler(void);
WEAK void MU1_A_IRQHandler(void);
WEAK void Reserved47_IRQHandler(void);
WEAK void CTIMER2_IRQHandler(void);
WEAK void CTIMER4_IRQHandler(void);
WEAK void OS_EVENT_IRQHandler(void);
WEAK void LP_FLEXCOMM6_IRQHandler(void);
WEAK void LP_FLEXCOMM7_IRQHandler(void);
WEAK void USDHC0_IRQHandler(void);
WEAK void USDHC1_IRQHandler(void);
WEAK void I3C0_IRQHandler(void);
WEAK void USB0_IRQHandler(void);
WEAK void USB1_IRQHandler(void);
WEAK void WDT0_IRQHandler(void);
WEAK void WDT1_IRQHandler(void);
WEAK void USBPHY0_IRQHandler(void);
WEAK void PUF_IRQHandler(void);
WEAK void Reserved62_IRQHandler(void);
WEAK void LP_FLEXCOMM8_IRQHandler(void);
WEAK void LP_FLEXCOMM9_IRQHandler(void);
WEAK void LP_FLEXCOMM10_IRQHandler(void);
WEAK void LP_FLEXCOMM11_IRQHandler(void);
WEAK void LP_FLEXCOMM12_IRQHandler(void);
WEAK void LP_FLEXCOMM13_IRQHandler(void);
WEAK void LPSPI16_IRQHandler(void);
WEAK void I3C1_IRQHandler(void);
WEAK void FLEXIO_IRQHandler(void);
WEAK void Reserved72_IRQHandler(void);
WEAK void Reserved73_IRQHandler(void);
WEAK void Reserved74_IRQHandler(void);
WEAK void EDMA0_CH0_IRQHandler(void);
WEAK void EDMA0_CH1_IRQHandler(void);
WEAK void EDMA0_CH2_IRQHandler(void);
WEAK void EDMA0_CH3_IRQHandler(void);
WEAK void EDMA0_CH4_IRQHandler(void);
WEAK void EDMA0_CH5_IRQHandler(void);
WEAK void EDMA0_CH6_IRQHandler(void);
WEAK void EDMA0_CH7_IRQHandler(void);
WEAK void EDMA0_CH8_IRQHandler(void);
WEAK void EDMA0_CH9_IRQHandler(void);
WEAK void EDMA0_CH10_IRQHandler(void);
WEAK void EDMA0_CH11_IRQHandler(void);
WEAK void EDMA0_CH12_IRQHandler(void);
WEAK void EDMA0_CH13_IRQHandler(void);
WEAK void EDMA0_CH14_IRQHandler(void);
WEAK void EDMA0_CH15_IRQHandler(void);
WEAK void EDMA1_CH0_IRQHandler(void);
WEAK void EDMA1_CH1_IRQHandler(void);
WEAK void EDMA1_CH2_IRQHandler(void);
WEAK void EDMA1_CH3_IRQHandler(void);
WEAK void EDMA1_CH4_IRQHandler(void);
WEAK void EDMA1_CH5_IRQHandler(void);
WEAK void EDMA1_CH6_IRQHandler(void);
WEAK void EDMA1_CH7_IRQHandler(void);
WEAK void EDMA1_CH8_IRQHandler(void);
WEAK void EDMA1_CH9_IRQHandler(void);
WEAK void EDMA1_CH10_IRQHandler(void);
WEAK void EDMA1_CH11_IRQHandler(void);
WEAK void EDMA1_CH12_IRQHandler(void);
WEAK void EDMA1_CH13_IRQHandler(void);
WEAK void EDMA1_CH14_IRQHandler(void);
WEAK void EDMA1_CH15_IRQHandler(void);
WEAK void GPIO00_IRQHandler(void);
WEAK void GPIO01_IRQHandler(void);
WEAK void GPIO10_IRQHandler(void);
WEAK void GPIO11_IRQHandler(void);
WEAK void GPIO20_IRQHandler(void);
WEAK void GPIO21_IRQHandler(void);
WEAK void GPIO30_IRQHandler(void);
WEAK void GPIO31_IRQHandler(void);
WEAK void GPIO40_IRQHandler(void);
WEAK void GPIO41_IRQHandler(void);
WEAK void GPIO50_IRQHandler(void);
WEAK void GPIO51_IRQHandler(void);
WEAK void GPIO60_IRQHandler(void);
WEAK void GPIO61_IRQHandler(void);
WEAK void GPIO70_IRQHandler(void);
WEAK void GPIO71_IRQHandler(void);
WEAK void PIN_INT0_IRQHandler(void);
WEAK void PIN_INT1_IRQHandler(void);
WEAK void PIN_INT2_IRQHandler(void);
WEAK void PIN_INT3_IRQHandler(void);
WEAK void PIN_INT4_IRQHandler(void);
WEAK void PIN_INT5_IRQHandler(void);
WEAK void PIN_INT6_IRQHandler(void);
WEAK void PIN_INT7_IRQHandler(void);
WEAK void SAI0_IRQHandler(void);
WEAK void SAI1_IRQHandler(void);
WEAK void SAI2_IRQHandler(void);
WEAK void XSPI0_IRQHandler(void);
WEAK void XSPI1_IRQHandler(void);
WEAK void XSPI2_IRQHandler(void);
WEAK void MMU0_IRQHandler(void);
WEAK void MMU1_IRQHandler(void);
WEAK void MMU2_IRQHandler(void);
WEAK void Freqme_IRQHandler(void);
WEAK void GDET0_IRQHandler(void);
WEAK void Reserved142_IRQHandler(void);
WEAK void Reserved143_IRQHandler(void);
WEAK void GDET3_IRQHandler(void);
WEAK void CDOG0_IRQHandler(void);
WEAK void CDOG1_IRQHandler(void);
WEAK void CDOG2_IRQHandler(void);
WEAK void ITRC0_IRQHandler(void);
WEAK void ELS_IRQHandler(void);
WEAK void PKC_IRQHandler(void);
WEAK void OSCCA_IRQHandler(void);
WEAK void SLEEPCON0_IRQHandler(void);
WEAK void CPU0_IRQHandler(void);
WEAK void PMC_IRQHandler(void);
WEAK void Reserved155_IRQHandler(void);
WEAK void Reserved156_IRQHandler(void);
WEAK void NPU_IRQHandler(void);
WEAK void TRNG_IRQHandler(void);
WEAK void TEMPDET0_IRQHandler(void);
WEAK void TEMPDET1_IRQHandler(void);
WEAK void EZHV_IRQHandler(void);
WEAK void GLIKEY0_IRQHandler(void);
WEAK void GLIKEY2_IRQHandler(void);
WEAK void GLIKEY3_IRQHandler(void);
WEAK void GLIKEY5_IRQHandler(void);
WEAK void PVTS0_CPU0_IRQHandler(void);
WEAK void Reserved167_IRQHandler(void);
WEAK void PVTS0_HIFI4_IRQHandler(void);
WEAK void Reserved169_IRQHandler(void);
WEAK void FRO0_IRQHandler(void);
WEAK void FRO1_IRQHandler(void);
WEAK void FRO2_IRQHandler(void);
WEAK void OCOTP_IRQHandler(void);

//*****************************************************************************
// Forward declaration of the driver IRQ handlers. These are aliased
// to the DefaultISR, which is a 'forever' loop. When the driver
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//*****************************************************************************
void Reserved16_DriverIRQHandler(void) ALIAS(DefaultISR);
void UTICK0_DriverIRQHandler(void) ALIAS(DefaultISR);
void MRT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER0_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER1_DriverIRQHandler(void) ALIAS(DefaultISR);
void SCT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER3_DriverIRQHandler(void) ALIAS(DefaultISR);
void LP_FLEXCOMM0_DriverIRQHandler(void) ALIAS(DefaultISR);
void LP_FLEXCOMM1_DriverIRQHandler(void) ALIAS(DefaultISR);
void LP_FLEXCOMM2_DriverIRQHandler(void) ALIAS(DefaultISR);
void LP_FLEXCOMM3_DriverIRQHandler(void) ALIAS(DefaultISR);
void LP_FLEXCOMM4_DriverIRQHandler(void) ALIAS(DefaultISR);
void LP_FLEXCOMM5_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPSPI14_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPI2C15_DriverIRQHandler(void) ALIAS(DefaultISR);
void ADC_DriverIRQHandler(void) ALIAS(DefaultISR);
void SDADC_DriverIRQHandler(void) ALIAS(DefaultISR);
void ACMP_DriverIRQHandler(void) ALIAS(DefaultISR);
void PDM_EVENT_DriverIRQHandler(void) ALIAS(DefaultISR);
void PDM_HWVAD_EVENT_DriverIRQHandler(void) ALIAS(DefaultISR);
void HYPERVISOR_DriverIRQHandler(void) ALIAS(DefaultISR);
void SECURE_VIOLATION_DriverIRQHandler(void) ALIAS(DefaultISR);
void SENSE_HYPERVISOR_DriverIRQHandler(void) ALIAS(DefaultISR);
void SENSE_SECURE_VIOLATION_DriverIRQHandler(void) ALIAS(DefaultISR);
void MEDIA_HYPERVISOR_DriverIRQHandler(void) ALIAS(DefaultISR);
void MEDIA_SECURE_VIOLATION_DriverIRQHandler(void) ALIAS(DefaultISR);
void RTC0_ALARM_DriverIRQHandler(void) ALIAS(DefaultISR);
void RTC0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved44_DriverIRQHandler(void) ALIAS(DefaultISR);
void MU0_A_DriverIRQHandler(void) ALIAS(DefaultISR);
void MU1_A_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved47_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER2_DriverIRQHandler(void) ALIAS(DefaultISR);
void CTIMER4_DriverIRQHandler(void) ALIAS(DefaultISR);
void OS_EVENT_DriverIRQHandler(void) ALIAS(DefaultISR);
void LP_FLEXCOMM6_DriverIRQHandler(void) ALIAS(DefaultISR);
void LP_FLEXCOMM7_DriverIRQHandler(void) ALIAS(DefaultISR);
void USDHC0_DriverIRQHandler(void) ALIAS(DefaultISR);
void USDHC1_DriverIRQHandler(void) ALIAS(DefaultISR);
void I3C0_DriverIRQHandler(void) ALIAS(DefaultISR);
void USB0_DriverIRQHandler(void) ALIAS(DefaultISR);
void USB1_DriverIRQHandler(void) ALIAS(DefaultISR);
void WDT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void WDT1_DriverIRQHandler(void) ALIAS(DefaultISR);
void USBPHY0_DriverIRQHandler(void) ALIAS(DefaultISR);
void PUF_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved62_DriverIRQHandler(void) ALIAS(DefaultISR);
void LP_FLEXCOMM8_DriverIRQHandler(void) ALIAS(DefaultISR);
void LP_FLEXCOMM9_DriverIRQHandler(void) ALIAS(DefaultISR);
void LP_FLEXCOMM10_DriverIRQHandler(void) ALIAS(DefaultISR);
void LP_FLEXCOMM11_DriverIRQHandler(void) ALIAS(DefaultISR);
void LP_FLEXCOMM12_DriverIRQHandler(void) ALIAS(DefaultISR);
void LP_FLEXCOMM13_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPSPI16_DriverIRQHandler(void) ALIAS(DefaultISR);
void I3C1_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLEXIO_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved72_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved73_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved74_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA0_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA0_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA0_CH2_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA0_CH3_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA0_CH4_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA0_CH5_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA0_CH6_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA0_CH7_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA0_CH8_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA0_CH9_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA0_CH10_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA0_CH11_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA0_CH12_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA0_CH13_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA0_CH14_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA0_CH15_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA1_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA1_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA1_CH2_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA1_CH3_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA1_CH4_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA1_CH5_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA1_CH6_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA1_CH7_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA1_CH8_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA1_CH9_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA1_CH10_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA1_CH11_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA1_CH12_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA1_CH13_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA1_CH14_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA1_CH15_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO00_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO01_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO10_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO11_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO20_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO21_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO30_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO31_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO40_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO41_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO50_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO51_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO60_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO61_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO70_DriverIRQHandler(void) ALIAS(DefaultISR);
void GPIO71_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIN_INT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIN_INT1_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIN_INT2_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIN_INT3_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIN_INT4_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIN_INT5_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIN_INT6_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIN_INT7_DriverIRQHandler(void) ALIAS(DefaultISR);
void SAI0_DriverIRQHandler(void) ALIAS(DefaultISR);
void SAI1_DriverIRQHandler(void) ALIAS(DefaultISR);
void SAI2_DriverIRQHandler(void) ALIAS(DefaultISR);
void XSPI0_DriverIRQHandler(void) ALIAS(DefaultISR);
void XSPI1_DriverIRQHandler(void) ALIAS(DefaultISR);
void XSPI2_DriverIRQHandler(void) ALIAS(DefaultISR);
void MMU0_DriverIRQHandler(void) ALIAS(DefaultISR);
void MMU1_DriverIRQHandler(void) ALIAS(DefaultISR);
void MMU2_DriverIRQHandler(void) ALIAS(DefaultISR);
void Freqme_DriverIRQHandler(void) ALIAS(DefaultISR);
void GDET0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved142_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved143_DriverIRQHandler(void) ALIAS(DefaultISR);
void GDET3_DriverIRQHandler(void) ALIAS(DefaultISR);
void CDOG0_DriverIRQHandler(void) ALIAS(DefaultISR);
void CDOG1_DriverIRQHandler(void) ALIAS(DefaultISR);
void CDOG2_DriverIRQHandler(void) ALIAS(DefaultISR);
void ITRC0_DriverIRQHandler(void) ALIAS(DefaultISR);
void ELS_DriverIRQHandler(void) ALIAS(DefaultISR);
void PKC_DriverIRQHandler(void) ALIAS(DefaultISR);
void OSCCA_DriverIRQHandler(void) ALIAS(DefaultISR);
void SLEEPCON0_DriverIRQHandler(void) ALIAS(DefaultISR);
void CPU0_DriverIRQHandler(void) ALIAS(DefaultISR);
void PMC_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved155_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved156_DriverIRQHandler(void) ALIAS(DefaultISR);
void NPU_DriverIRQHandler(void) ALIAS(DefaultISR);
void TRNG_DriverIRQHandler(void) ALIAS(DefaultISR);
void TEMPDET0_DriverIRQHandler(void) ALIAS(DefaultISR);
void TEMPDET1_DriverIRQHandler(void) ALIAS(DefaultISR);
void EZHV_DriverIRQHandler(void) ALIAS(DefaultISR);
void GLIKEY0_DriverIRQHandler(void) ALIAS(DefaultISR);
void GLIKEY2_DriverIRQHandler(void) ALIAS(DefaultISR);
void GLIKEY3_DriverIRQHandler(void) ALIAS(DefaultISR);
void GLIKEY5_DriverIRQHandler(void) ALIAS(DefaultISR);
void PVTS0_CPU0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved167_DriverIRQHandler(void) ALIAS(DefaultISR);
void PVTS0_HIFI4_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved169_DriverIRQHandler(void) ALIAS(DefaultISR);
void FRO0_DriverIRQHandler(void) ALIAS(DefaultISR);
void FRO1_DriverIRQHandler(void) ALIAS(DefaultISR);
void FRO2_DriverIRQHandler(void) ALIAS(DefaultISR);
void OCOTP_DriverIRQHandler(void) ALIAS(DefaultISR);

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
extern uint32_t Load$$LR$$LR_m_interrupts$$Length[];
#define _image_size Load$$LR$$LR_m_interrupts$$Length
#elif defined(__MCUXPRESSO)
extern void _vStackTop(void);
extern void _vStackBase(void);
extern void _image_size(void);
#define Reset_Handler ResetISR // To be compatible with other compilers
#elif defined(__ICCARM__)
#pragma segment = "CSTACK"
#define _vStackTop  __section_end("CSTACK")
#define _vStackBase __section_begin("CSTACK")
#pragma segment = "RO"
#define _image_size __section_size("RO")
#elif defined(__GNUC__)
extern uint32_t __StackTop[];
extern uint32_t __StackLimit[];

#define _vStackTop  __StackTop
#define _vStackBase __StackLimit

extern uint32_t _image_size[];

extern uint32_t __etext[];
extern uint32_t __data_start__[];
extern uint32_t __data_end__[];

extern uint32_t __NDATA_ROM[];
extern uint32_t __noncachedata_start__[];
extern uint32_t __noncachedata_init_end__[];
extern uint32_t __noncachedata_end__[];

extern uint32_t __bss_start__[];
extern uint32_t __bss_end__[];
#else
#error Unsupported toolchain!
#endif //(__CC_ARM) || (__ARMCC_VERSION)

//*****************************************************************************
// External declaration for image type and load address from  Linker Script
//*****************************************************************************
WEAK extern void __imghdr_loadaddress();
WEAK extern void __imghdr_imagetype();

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
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
    (void (*)())0x180000,               // Image length
#else
    (void (*)())((uint32_t)_image_size), // Image length
#endif                                  //(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)
    __imghdr_imagetype,                 // Image type
    0,                                  // Reserved
    SVC_Handler,                        // SVCall Handler
    DebugMon_Handler,                   // Debug Monitor Handler
    (void (*)())__vector_table,         // Image load address
    PendSV_Handler,                     // PendSV Handler
    SysTick_Handler,                    // SysTick Handler

    // Chip Level - MIMXRT735S_cm33_core0
    Reserved16_IRQHandler,             // 16 : Reserved interrupt
    UTICK0_IRQHandler,                 // 17 : Micro-tick Timer
    MRT0_IRQHandler,                   // 18 : MRT: Ored Interrupt request
    CTIMER0_IRQHandler,                // 19 : CTIMER: Interrupt request
    CTIMER1_IRQHandler,                // 20 : CTIMER: Interrupt request
    SCT0_IRQHandler,                   // 21 : SCT: Interrupt request
    CTIMER3_IRQHandler,                // 22 : CTIMER: Interrupt request
    LP_FLEXCOMM0_IRQHandler,           // 23 : FLEXCOMM: Interrupt request
    LP_FLEXCOMM1_IRQHandler,           // 24 : FLEXCOMM: Interrupt request
    LP_FLEXCOMM2_IRQHandler,           // 25 : FLEXCOMM: Interrupt request
    LP_FLEXCOMM3_IRQHandler,           // 26 : FLEXCOMM: Interrupt request
    LP_FLEXCOMM4_IRQHandler,           // 27 : FLEXCOMM: Interrupt request
    LP_FLEXCOMM5_IRQHandler,           // 28 : FLEXCOMM: Interrupt request
    LPSPI14_IRQHandler,                // 29 : LPSPI: Interrupt request
    LPI2C15_IRQHandler,                // 30 : LPI2C: Interrupt request
    ADC_IRQHandler,                    // 31 : ADC0: Interrupt request
    SDADC_IRQHandler,                  // 32 : SDADC0: Interrupt request
    ACMP_IRQHandler,                   // 33 : ACMP: interrupt request
    PDM_EVENT_IRQHandler,              // 34 : MIC: Interrupt request for read data or Error
    PDM_HWVAD_EVENT_IRQHandler,        // 35 : MIC: Hardware Voice Activity Detector interrupt or error interrupt
    HYPERVISOR_IRQHandler,             // 36 : SECURE: Compute domain P-Bus Hypervisor interrupt
    SECURE_VIOLATION_IRQHandler,       // 37 : SECURE: Compute domain P-Bus Secure violation interrupt
    SENSE_HYPERVISOR_IRQHandler,       // 38 : Sense domain Hypervisor interrupt
    SENSE_SECURE_VIOLATION_IRQHandler, // 39 : Sense domain Secure violation interrupt
    MEDIA_HYPERVISOR_IRQHandler,       // 40 : Media domain Hypervisor interrupt
    MEDIA_SECURE_VIOLATION_IRQHandler, // 41 : Media domain Secure violation interrupt
    RTC0_ALARM_IRQHandler,             // 42 : RTC: Alarm interrupt
    RTC0_IRQHandler,                   // 43 : RTC: wakeup interrupt to Compute domain
    Reserved44_IRQHandler,             // 44 : Reserved interrupt
    MU0_A_IRQHandler,                  // 45 : MU0: MUA, CPU0 to HiFi1
    MU1_A_IRQHandler,                  // 46 : MU1: MUA, CPU0 to CPU1
    Reserved47_IRQHandler,             // 47 : Reserved interrupt
    CTIMER2_IRQHandler,                // 48 : CTIMER: Interrupt request
    CTIMER4_IRQHandler,                // 49 : CTIMER: Interrupt request
    OS_EVENT_IRQHandler,               // 50 : OSEVENT: Event timer CPU0 Wakeup/interrupt
    LP_FLEXCOMM6_IRQHandler,           // 51 : FLEXCOMM: Interrupt request
    LP_FLEXCOMM7_IRQHandler,           // 52 : FLEXCOMM: Interrupt request
    USDHC0_IRQHandler,                 // 53 : USDHC: Interrupt request
    USDHC1_IRQHandler,                 // 54 : USDHC: Interrupt request
    I3C0_IRQHandler,                   // 55 : I3C: Interrupt Request
    USB0_IRQHandler,                   // 56 : USB: HSUSB Interrup request
    USB1_IRQHandler,                   // 57 : USB: eUSB Interrup request
    WDT0_IRQHandler,                   // 58 : WDT: Interrupt request
    WDT1_IRQHandler,                   // 59 : WDT: Interrupt request
    USBPHY0_IRQHandler,                // 60 : HSUSBPHY: UTM interrupt request
    PUF_IRQHandler,                    // 61 : PUF: Interrupt Request
    Reserved62_IRQHandler,             // 62 : Reserved interrupt
    LP_FLEXCOMM8_IRQHandler,           // 63 : FLEXCOMM: Interrupt request
    LP_FLEXCOMM9_IRQHandler,           // 64 : FLEXCOMM: Interrupt request
    LP_FLEXCOMM10_IRQHandler,          // 65 : FLEXCOMM: Interrupt request
    LP_FLEXCOMM11_IRQHandler,          // 66 : FLEXCOMM: Interrupt request
    LP_FLEXCOMM12_IRQHandler,          // 67 : FLEXCOMM: Interrupt request
    LP_FLEXCOMM13_IRQHandler,          // 68 : FLEXCOMM: Interrupt request
    LPSPI16_IRQHandler,                // 69 : LPSPI: Interrupt request
    I3C1_IRQHandler,                   // 70 : I3C: Interrupt Request
    FLEXIO_IRQHandler,                 // 71 : FLEXIO: Interrupt request
    Reserved72_IRQHandler,             // 72 : Reserved interrupt
    Reserved73_IRQHandler,             // 73 : Reserved interrupt
    Reserved74_IRQHandler,             // 74 : Reserved interrupt
    EDMA0_CH0_IRQHandler,              // 75 : EDMA: Channel 0 interrupt
    EDMA0_CH1_IRQHandler,              // 76 : EDMA: Channel 1 interrupt
    EDMA0_CH2_IRQHandler,              // 77 : EDMA: Channel 2 interrupt
    EDMA0_CH3_IRQHandler,              // 78 : EDMA: Channel 3 interrupt
    EDMA0_CH4_IRQHandler,              // 79 : EDMA: Channel 4 interrupt
    EDMA0_CH5_IRQHandler,              // 80 : EDMA: Channel 5 interrupt
    EDMA0_CH6_IRQHandler,              // 81 : EDMA: Channel 6 interrupt
    EDMA0_CH7_IRQHandler,              // 82 : EDMA: Channel 7 interrupt
    EDMA0_CH8_IRQHandler,              // 83 : EDMA: Channel 8 interrupt
    EDMA0_CH9_IRQHandler,              // 84 : EDMA: Channel 9 interrupt
    EDMA0_CH10_IRQHandler,             // 85 : EDMA: Channel 10 interrupt
    EDMA0_CH11_IRQHandler,             // 86 : EDMA: Channel 11 interrupt
    EDMA0_CH12_IRQHandler,             // 87 : EDMA: Channel 12 interrupt
    EDMA0_CH13_IRQHandler,             // 88 : EDMA: Channel 13 interrupt
    EDMA0_CH14_IRQHandler,             // 89 : EDMA: Channel 14 interrupt
    EDMA0_CH15_IRQHandler,             // 90 : EDMA: Channel 15 interrupt
    EDMA1_CH0_IRQHandler,              // 91 : EDMA: Channel 0 interrupt
    EDMA1_CH1_IRQHandler,              // 92 : EDMA: Channel 1 interrupt
    EDMA1_CH2_IRQHandler,              // 93 : EDMA: Channel 2 interrupt
    EDMA1_CH3_IRQHandler,              // 94 : EDMA: Channel 3 interrupt
    EDMA1_CH4_IRQHandler,              // 95 : EDMA: Channel 4 interrupt
    EDMA1_CH5_IRQHandler,              // 96 : EDMA: Channel 5 interrupt
    EDMA1_CH6_IRQHandler,              // 97 : EDMA: Channel 6 interrupt
    EDMA1_CH7_IRQHandler,              // 98 : EDMA: Channel 7 interrupt
    EDMA1_CH8_IRQHandler,              // 99 : EDMA: Channel 8 interrupt
    EDMA1_CH9_IRQHandler,              // 100: EDMA: Channel 9 interrupt
    EDMA1_CH10_IRQHandler,             // 101: EDMA: Channel 10 interrupt
    EDMA1_CH11_IRQHandler,             // 102: EDMA: Channel 11 interrupt
    EDMA1_CH12_IRQHandler,             // 103: EDMA: Channel 12 interrupt
    EDMA1_CH13_IRQHandler,             // 104: EDMA: Channel 13 interrupt
    EDMA1_CH14_IRQHandler,             // 105: EDMA: Channel 14 interrupt
    EDMA1_CH15_IRQHandler,             // 106: EDMA: Channel 15 interrupt
    GPIO00_IRQHandler,                 // 107: GPIO: Interupt request, channel 0
    GPIO01_IRQHandler,                 // 108: GPIO: Interupt request, channel 1
    GPIO10_IRQHandler,                 // 109: GPIO: Interupt request, channel 0
    GPIO11_IRQHandler,                 // 110: GPIO: Interupt request, channel 1
    GPIO20_IRQHandler,                 // 111: GPIO: Interupt request, channel 0
    GPIO21_IRQHandler,                 // 112: GPIO: Interupt request, channel 1
    GPIO30_IRQHandler,                 // 113: GPIO: Interupt request, channel 0
    GPIO31_IRQHandler,                 // 114: GPIO: Interupt request, channel 1
    GPIO40_IRQHandler,                 // 115: GPIO: Interupt request, channel 0
    GPIO41_IRQHandler,                 // 116: GPIO: Interupt request, channel 1
    GPIO50_IRQHandler,                 // 117: GPIO: Interupt request, channel 0
    GPIO51_IRQHandler,                 // 118: GPIO: Interupt request, channel 1
    GPIO60_IRQHandler,                 // 119: GPIO: Interupt request, channel 0
    GPIO61_IRQHandler,                 // 120: GPIO: Interupt request, channel 1
    GPIO70_IRQHandler,                 // 121: GPIO: Interupt request, channel 0
    GPIO71_IRQHandler,                 // 122: GPIO: Interupt request, channel 1
    PIN_INT0_IRQHandler,               // 123: PINT: Interupt request 0
    PIN_INT1_IRQHandler,               // 124: PINT: Interupt request 1
    PIN_INT2_IRQHandler,               // 125: PINT: Interupt request 2
    PIN_INT3_IRQHandler,               // 126: PINT: Interupt request 3
    PIN_INT4_IRQHandler,               // 127: PINT: Interupt request 4
    PIN_INT5_IRQHandler,               // 128: PINT: Interupt request 5
    PIN_INT6_IRQHandler,               // 129: PINT: Interupt request 6
    PIN_INT7_IRQHandler,               // 130: PINT: Interupt request 7
    SAI0_IRQHandler,                   // 131: SAI: TX/RX interrupt
    SAI1_IRQHandler,                   // 132: SAI: TX/RX interrupt
    SAI2_IRQHandler,                   // 133: SAI: TX/RX interrupt
    XSPI0_IRQHandler,                  // 134: xSPI: Ored interrupt
    XSPI1_IRQHandler,                  // 135: xSPI: Ored interrupt
    XSPI2_IRQHandler,                  // 136: xSPI: Ored interrupt
    MMU0_IRQHandler,                   // 137: MMU: Interrupt request
    MMU1_IRQHandler,                   // 138: MMU: Interrupt request
    MMU2_IRQHandler,                   // 139: MMU: Interrupt request
    Freqme_IRQHandler,                 // 140: FREQME: Interrupt request
    GDET0_IRQHandler,                  // 141: GDET0: Interrupt request
    Reserved142_IRQHandler,            // 142: Reserved interrupt
    Reserved143_IRQHandler,            // 143: Reserved interrupt
    GDET3_IRQHandler,                  // 144: GDET3: Interrupt request
    CDOG0_IRQHandler,                  // 145: CDOG: Interrupt request
    CDOG1_IRQHandler,                  // 146: CDOG: Interrupt request
    CDOG2_IRQHandler,                  // 147: CDOG: Interrupt request
    ITRC0_IRQHandler,                  // 148: ITRC: Interrupt, cleared by software
    ELS_IRQHandler,                    // 149: ELS Interrupt request
    PKC_IRQHandler,                    // 150: PKC: Public Key Cryptography Interrutp
    OSCCA_IRQHandler,                  // 151: OSCCA: OSCCA Interrupt request
    SLEEPCON0_IRQHandler,              // 152: WAKEUP: CPU0 wakeup event
    CPU0_IRQHandler,                   // 153: CTI0: interrupt request
    PMC_IRQHandler,                    // 154: PMC: Compute domain Interrupt
    Reserved155_IRQHandler,            // 155: Reserved interrupt
    Reserved156_IRQHandler,            // 156: Reserved interrupt
    NPU_IRQHandler,                    // 157: NPU: Interrupt request
    TRNG_IRQHandler,                   // 158: TRNG: interrupt
    TEMPDET0_IRQHandler,               // 159: TEMPDET0: Interrupt request 0
    TEMPDET1_IRQHandler,               // 160: TEMPDET1: Interrupt request 1
    EZHV_IRQHandler,                   // 161: EZH-V: Interrupt request
    GLIKEY0_IRQHandler,                // 162: GLIKEY: Interrupt
    GLIKEY2_IRQHandler,                // 163: GLIKEY: Interrupt
    GLIKEY3_IRQHandler,                // 164: GLIKEY: Interrupt
    GLIKEY5_IRQHandler,                // 165: GLIKEY: Interrupt
    PVTS0_CPU0_IRQHandler,             // 166: PVTS0 CPU0 interrupt
    Reserved167_IRQHandler,            // 167: Reserved interrupt
    PVTS0_HIFI4_IRQHandler,            // 168: PVTS0 HIFI4 interrupt
    Reserved169_IRQHandler,            // 169: Reserved interrupt
    FRO0_IRQHandler,                   // 170: FRO: 300MHz FRO in VDD2 domain Async interrupt
    FRO1_IRQHandler,                   // 171: FRO: 192MHz FRO in VDD2 domain Async interrupt
    FRO2_IRQHandler,                   // 172: FRO: 300MHz FRO in VDD1 domain Async interrupt
    OCOTP_IRQHandler,                  // 173: OCOTP warning and integrity error interrupt
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
     *      2. __NDATA_ROM/__noncachedata_start__/__noncachedata_init_end__
     *      Note: All must be aligned to 4 bytes boundary.
     */
    uint32_t *pDataSrc, *pDataDest;

    pDataSrc  = (uint32_t *)__etext;
    pDataDest = (uint32_t *)__data_start__;
    while (pDataDest < __data_end__)
    {
        *pDataDest++ = *pDataSrc++;
    }
#if defined(__STARTUP_INITIALIZE_NONCACHEDATA)
    pDataSrc  = (uint32_t *)__NDATA_ROM;
    pDataDest = (uint32_t *)__noncachedata_start__;
    while (pDataDest < __noncachedata_init_end__)
    {
        *pDataDest++ = *pDataSrc++;
    }
    while (pDataDest < __noncachedata_end__)
    {
        *pDataDest++ = 0U;
    }
#endif //(__STARTUP_INITIALIZE_NONCACHEDATA)
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
WEAK void Reserved16_IRQHandler(void)
{
    Reserved16_DriverIRQHandler();
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

WEAK void LP_FLEXCOMM0_IRQHandler(void)
{
    LP_FLEXCOMM0_DriverIRQHandler();
}

WEAK void LP_FLEXCOMM1_IRQHandler(void)
{
    LP_FLEXCOMM1_DriverIRQHandler();
}

WEAK void LP_FLEXCOMM2_IRQHandler(void)
{
    LP_FLEXCOMM2_DriverIRQHandler();
}

WEAK void LP_FLEXCOMM3_IRQHandler(void)
{
    LP_FLEXCOMM3_DriverIRQHandler();
}

WEAK void LP_FLEXCOMM4_IRQHandler(void)
{
    LP_FLEXCOMM4_DriverIRQHandler();
}

WEAK void LP_FLEXCOMM5_IRQHandler(void)
{
    LP_FLEXCOMM5_DriverIRQHandler();
}

WEAK void LPSPI14_IRQHandler(void)
{
    LPSPI14_DriverIRQHandler();
}

WEAK void LPI2C15_IRQHandler(void)
{
    LPI2C15_DriverIRQHandler();
}

WEAK void ADC_IRQHandler(void)
{
    ADC_DriverIRQHandler();
}

WEAK void SDADC_IRQHandler(void)
{
    SDADC_DriverIRQHandler();
}

WEAK void ACMP_IRQHandler(void)
{
    ACMP_DriverIRQHandler();
}

WEAK void PDM_EVENT_IRQHandler(void)
{
    PDM_EVENT_DriverIRQHandler();
}

WEAK void PDM_HWVAD_EVENT_IRQHandler(void)
{
    PDM_HWVAD_EVENT_DriverIRQHandler();
}

WEAK void HYPERVISOR_IRQHandler(void)
{
    HYPERVISOR_DriverIRQHandler();
}

WEAK void SECURE_VIOLATION_IRQHandler(void)
{
    SECURE_VIOLATION_DriverIRQHandler();
}

WEAK void SENSE_HYPERVISOR_IRQHandler(void)
{
    SENSE_HYPERVISOR_DriverIRQHandler();
}

WEAK void SENSE_SECURE_VIOLATION_IRQHandler(void)
{
    SENSE_SECURE_VIOLATION_DriverIRQHandler();
}

WEAK void MEDIA_HYPERVISOR_IRQHandler(void)
{
    MEDIA_HYPERVISOR_DriverIRQHandler();
}

WEAK void MEDIA_SECURE_VIOLATION_IRQHandler(void)
{
    MEDIA_SECURE_VIOLATION_DriverIRQHandler();
}

WEAK void RTC0_ALARM_IRQHandler(void)
{
    RTC0_ALARM_DriverIRQHandler();
}

WEAK void RTC0_IRQHandler(void)
{
    RTC0_DriverIRQHandler();
}

WEAK void Reserved44_IRQHandler(void)
{
    Reserved44_DriverIRQHandler();
}

WEAK void MU0_A_IRQHandler(void)
{
    MU0_A_DriverIRQHandler();
}

WEAK void MU1_A_IRQHandler(void)
{
    MU1_A_DriverIRQHandler();
}

WEAK void Reserved47_IRQHandler(void)
{
    Reserved47_DriverIRQHandler();
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

WEAK void LP_FLEXCOMM6_IRQHandler(void)
{
    LP_FLEXCOMM6_DriverIRQHandler();
}

WEAK void LP_FLEXCOMM7_IRQHandler(void)
{
    LP_FLEXCOMM7_DriverIRQHandler();
}

WEAK void USDHC0_IRQHandler(void)
{
    USDHC0_DriverIRQHandler();
}

WEAK void USDHC1_IRQHandler(void)
{
    USDHC1_DriverIRQHandler();
}

WEAK void I3C0_IRQHandler(void)
{
    I3C0_DriverIRQHandler();
}

WEAK void USB0_IRQHandler(void)
{
    USB0_DriverIRQHandler();
}

WEAK void USB1_IRQHandler(void)
{
    USB1_DriverIRQHandler();
}

WEAK void WDT0_IRQHandler(void)
{
    WDT0_DriverIRQHandler();
}

WEAK void WDT1_IRQHandler(void)
{
    WDT1_DriverIRQHandler();
}

WEAK void USBPHY0_IRQHandler(void)
{
    USBPHY0_DriverIRQHandler();
}

WEAK void PUF_IRQHandler(void)
{
    PUF_DriverIRQHandler();
}

WEAK void Reserved62_IRQHandler(void)
{
    Reserved62_DriverIRQHandler();
}

WEAK void LP_FLEXCOMM8_IRQHandler(void)
{
    LP_FLEXCOMM8_DriverIRQHandler();
}

WEAK void LP_FLEXCOMM9_IRQHandler(void)
{
    LP_FLEXCOMM9_DriverIRQHandler();
}

WEAK void LP_FLEXCOMM10_IRQHandler(void)
{
    LP_FLEXCOMM10_DriverIRQHandler();
}

WEAK void LP_FLEXCOMM11_IRQHandler(void)
{
    LP_FLEXCOMM11_DriverIRQHandler();
}

WEAK void LP_FLEXCOMM12_IRQHandler(void)
{
    LP_FLEXCOMM12_DriverIRQHandler();
}

WEAK void LP_FLEXCOMM13_IRQHandler(void)
{
    LP_FLEXCOMM13_DriverIRQHandler();
}

WEAK void LPSPI16_IRQHandler(void)
{
    LPSPI16_DriverIRQHandler();
}

WEAK void I3C1_IRQHandler(void)
{
    I3C1_DriverIRQHandler();
}

WEAK void FLEXIO_IRQHandler(void)
{
    FLEXIO_DriverIRQHandler();
}

WEAK void Reserved72_IRQHandler(void)
{
    Reserved72_DriverIRQHandler();
}

WEAK void Reserved73_IRQHandler(void)
{
    Reserved73_DriverIRQHandler();
}

WEAK void Reserved74_IRQHandler(void)
{
    Reserved74_DriverIRQHandler();
}

WEAK void EDMA0_CH0_IRQHandler(void)
{
    EDMA0_CH0_DriverIRQHandler();
}

WEAK void EDMA0_CH1_IRQHandler(void)
{
    EDMA0_CH1_DriverIRQHandler();
}

WEAK void EDMA0_CH2_IRQHandler(void)
{
    EDMA0_CH2_DriverIRQHandler();
}

WEAK void EDMA0_CH3_IRQHandler(void)
{
    EDMA0_CH3_DriverIRQHandler();
}

WEAK void EDMA0_CH4_IRQHandler(void)
{
    EDMA0_CH4_DriverIRQHandler();
}

WEAK void EDMA0_CH5_IRQHandler(void)
{
    EDMA0_CH5_DriverIRQHandler();
}

WEAK void EDMA0_CH6_IRQHandler(void)
{
    EDMA0_CH6_DriverIRQHandler();
}

WEAK void EDMA0_CH7_IRQHandler(void)
{
    EDMA0_CH7_DriverIRQHandler();
}

WEAK void EDMA0_CH8_IRQHandler(void)
{
    EDMA0_CH8_DriverIRQHandler();
}

WEAK void EDMA0_CH9_IRQHandler(void)
{
    EDMA0_CH9_DriverIRQHandler();
}

WEAK void EDMA0_CH10_IRQHandler(void)
{
    EDMA0_CH10_DriverIRQHandler();
}

WEAK void EDMA0_CH11_IRQHandler(void)
{
    EDMA0_CH11_DriverIRQHandler();
}

WEAK void EDMA0_CH12_IRQHandler(void)
{
    EDMA0_CH12_DriverIRQHandler();
}

WEAK void EDMA0_CH13_IRQHandler(void)
{
    EDMA0_CH13_DriverIRQHandler();
}

WEAK void EDMA0_CH14_IRQHandler(void)
{
    EDMA0_CH14_DriverIRQHandler();
}

WEAK void EDMA0_CH15_IRQHandler(void)
{
    EDMA0_CH15_DriverIRQHandler();
}

WEAK void EDMA1_CH0_IRQHandler(void)
{
    EDMA1_CH0_DriverIRQHandler();
}

WEAK void EDMA1_CH1_IRQHandler(void)
{
    EDMA1_CH1_DriverIRQHandler();
}

WEAK void EDMA1_CH2_IRQHandler(void)
{
    EDMA1_CH2_DriverIRQHandler();
}

WEAK void EDMA1_CH3_IRQHandler(void)
{
    EDMA1_CH3_DriverIRQHandler();
}

WEAK void EDMA1_CH4_IRQHandler(void)
{
    EDMA1_CH4_DriverIRQHandler();
}

WEAK void EDMA1_CH5_IRQHandler(void)
{
    EDMA1_CH5_DriverIRQHandler();
}

WEAK void EDMA1_CH6_IRQHandler(void)
{
    EDMA1_CH6_DriverIRQHandler();
}

WEAK void EDMA1_CH7_IRQHandler(void)
{
    EDMA1_CH7_DriverIRQHandler();
}

WEAK void EDMA1_CH8_IRQHandler(void)
{
    EDMA1_CH8_DriverIRQHandler();
}

WEAK void EDMA1_CH9_IRQHandler(void)
{
    EDMA1_CH9_DriverIRQHandler();
}

WEAK void EDMA1_CH10_IRQHandler(void)
{
    EDMA1_CH10_DriverIRQHandler();
}

WEAK void EDMA1_CH11_IRQHandler(void)
{
    EDMA1_CH11_DriverIRQHandler();
}

WEAK void EDMA1_CH12_IRQHandler(void)
{
    EDMA1_CH12_DriverIRQHandler();
}

WEAK void EDMA1_CH13_IRQHandler(void)
{
    EDMA1_CH13_DriverIRQHandler();
}

WEAK void EDMA1_CH14_IRQHandler(void)
{
    EDMA1_CH14_DriverIRQHandler();
}

WEAK void EDMA1_CH15_IRQHandler(void)
{
    EDMA1_CH15_DriverIRQHandler();
}

WEAK void GPIO00_IRQHandler(void)
{
    GPIO00_DriverIRQHandler();
}

WEAK void GPIO01_IRQHandler(void)
{
    GPIO01_DriverIRQHandler();
}

WEAK void GPIO10_IRQHandler(void)
{
    GPIO10_DriverIRQHandler();
}

WEAK void GPIO11_IRQHandler(void)
{
    GPIO11_DriverIRQHandler();
}

WEAK void GPIO20_IRQHandler(void)
{
    GPIO20_DriverIRQHandler();
}

WEAK void GPIO21_IRQHandler(void)
{
    GPIO21_DriverIRQHandler();
}

WEAK void GPIO30_IRQHandler(void)
{
    GPIO30_DriverIRQHandler();
}

WEAK void GPIO31_IRQHandler(void)
{
    GPIO31_DriverIRQHandler();
}

WEAK void GPIO40_IRQHandler(void)
{
    GPIO40_DriverIRQHandler();
}

WEAK void GPIO41_IRQHandler(void)
{
    GPIO41_DriverIRQHandler();
}

WEAK void GPIO50_IRQHandler(void)
{
    GPIO50_DriverIRQHandler();
}

WEAK void GPIO51_IRQHandler(void)
{
    GPIO51_DriverIRQHandler();
}

WEAK void GPIO60_IRQHandler(void)
{
    GPIO60_DriverIRQHandler();
}

WEAK void GPIO61_IRQHandler(void)
{
    GPIO61_DriverIRQHandler();
}

WEAK void GPIO70_IRQHandler(void)
{
    GPIO70_DriverIRQHandler();
}

WEAK void GPIO71_IRQHandler(void)
{
    GPIO71_DriverIRQHandler();
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

WEAK void SAI0_IRQHandler(void)
{
    SAI0_DriverIRQHandler();
}

WEAK void SAI1_IRQHandler(void)
{
    SAI1_DriverIRQHandler();
}

WEAK void SAI2_IRQHandler(void)
{
    SAI2_DriverIRQHandler();
}

WEAK void XSPI0_IRQHandler(void)
{
    XSPI0_DriverIRQHandler();
}

WEAK void XSPI1_IRQHandler(void)
{
    XSPI1_DriverIRQHandler();
}

WEAK void XSPI2_IRQHandler(void)
{
    XSPI2_DriverIRQHandler();
}

WEAK void MMU0_IRQHandler(void)
{
    MMU0_DriverIRQHandler();
}

WEAK void MMU1_IRQHandler(void)
{
    MMU1_DriverIRQHandler();
}

WEAK void MMU2_IRQHandler(void)
{
    MMU2_DriverIRQHandler();
}

WEAK void Freqme_IRQHandler(void)
{
    Freqme_DriverIRQHandler();
}

WEAK void GDET0_IRQHandler(void)
{
    GDET0_DriverIRQHandler();
}

WEAK void Reserved142_IRQHandler(void)
{
    Reserved142_DriverIRQHandler();
}

WEAK void Reserved143_IRQHandler(void)
{
    Reserved143_DriverIRQHandler();
}

WEAK void GDET3_IRQHandler(void)
{
    GDET3_DriverIRQHandler();
}

WEAK void CDOG0_IRQHandler(void)
{
    CDOG0_DriverIRQHandler();
}

WEAK void CDOG1_IRQHandler(void)
{
    CDOG1_DriverIRQHandler();
}

WEAK void CDOG2_IRQHandler(void)
{
    CDOG2_DriverIRQHandler();
}

WEAK void ITRC0_IRQHandler(void)
{
    ITRC0_DriverIRQHandler();
}

WEAK void ELS_IRQHandler(void)
{
    ELS_DriverIRQHandler();
}

WEAK void PKC_IRQHandler(void)
{
    PKC_DriverIRQHandler();
}

WEAK void OSCCA_IRQHandler(void)
{
    OSCCA_DriverIRQHandler();
}

WEAK void SLEEPCON0_IRQHandler(void)
{
    SLEEPCON0_DriverIRQHandler();
}

WEAK void CPU0_IRQHandler(void)
{
    CPU0_DriverIRQHandler();
}

WEAK void PMC_IRQHandler(void)
{
    PMC_DriverIRQHandler();
}

WEAK void Reserved155_IRQHandler(void)
{
    Reserved155_DriverIRQHandler();
}

WEAK void Reserved156_IRQHandler(void)
{
    Reserved156_DriverIRQHandler();
}

WEAK void NPU_IRQHandler(void)
{
    NPU_DriverIRQHandler();
}

WEAK void TRNG_IRQHandler(void)
{
    TRNG_DriverIRQHandler();
}

WEAK void TEMPDET0_IRQHandler(void)
{
    TEMPDET0_DriverIRQHandler();
}

WEAK void TEMPDET1_IRQHandler(void)
{
    TEMPDET1_DriverIRQHandler();
}

WEAK void EZHV_IRQHandler(void)
{
    EZHV_DriverIRQHandler();
}

WEAK void GLIKEY0_IRQHandler(void)
{
    GLIKEY0_DriverIRQHandler();
}

WEAK void GLIKEY2_IRQHandler(void)
{
    GLIKEY2_DriverIRQHandler();
}

WEAK void GLIKEY3_IRQHandler(void)
{
    GLIKEY3_DriverIRQHandler();
}

WEAK void GLIKEY5_IRQHandler(void)
{
    GLIKEY5_DriverIRQHandler();
}

WEAK void PVTS0_CPU0_IRQHandler(void)
{
    PVTS0_CPU0_DriverIRQHandler();
}

WEAK void Reserved167_IRQHandler(void)
{
    Reserved167_DriverIRQHandler();
}

WEAK void PVTS0_HIFI4_IRQHandler(void)
{
    PVTS0_HIFI4_DriverIRQHandler();
}

WEAK void Reserved169_IRQHandler(void)
{
    Reserved169_DriverIRQHandler();
}

WEAK void FRO0_IRQHandler(void)
{
    FRO0_DriverIRQHandler();
}

WEAK void FRO1_IRQHandler(void)
{
    FRO1_DriverIRQHandler();
}

WEAK void FRO2_IRQHandler(void)
{
    FRO2_DriverIRQHandler();
}

WEAK void OCOTP_IRQHandler(void)
{
    OCOTP_DriverIRQHandler();
}

//*****************************************************************************

#if defined(DEBUG)
#if defined(__GNUC__)
#pragma GCC pop_options
#endif //(__GNUC__)
#endif //(DEBUG)
