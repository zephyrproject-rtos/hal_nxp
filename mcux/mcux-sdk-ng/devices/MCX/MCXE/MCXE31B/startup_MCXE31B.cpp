
//*****************************************************************************
// MCXE31B startup code
//
// Version : 120525
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
#endif
#endif // DEBUG

#if defined(__cplusplus)
#if defined(__MCUXPRESSO)
#ifdef __REDLIB__
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
#endif // __REDLIB__
#endif // __MCUXPRESSO
#endif // __cplusplus

#define WEAK __attribute__ ((weak))
#if defined(__MCUXPRESSO)
#define WEAK_AV __attribute__ ((weak, section(".after_vectors")))
#else
#define WEAK_AV __attribute__ ((weak))
#endif // __MCUXPRESSO
#define ALIAS(f) __attribute__ ((weak, alias (#f)))

//*****************************************************************************
#if defined(__cplusplus)
extern "C" {
#endif

//*****************************************************************************
// Declaration of external function SystemInit function
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
#endif // __MCUXPRESSO
WEAK void NMI_Handler(void);
WEAK void HardFault_Handler(void);
WEAK void MemManage_Handler(void);
WEAK void BusFault_Handler(void);
WEAK void UsageFault_Handler(void);
WEAK void SVC_Handler(void);
WEAK void DebugMon_Handler(void);
WEAK void PendSV_Handler(void);
WEAK void SysTick_Handler(void);
WEAK void DefaultISR(void);
WEAK void DefaultISR1(uint32_t instance);
WEAK void DefaultISR4(uint32_t instance, uint32_t start, uint32_t end, uint32_t type);

//*****************************************************************************
// Forward declaration of the application IRQ handlers. When the application
// defines a handler (with the same name), this will automatically take
// precedence over weak definitions below
//*****************************************************************************
WEAK void Reserved16_IRQHandler(void);
WEAK void Reserved17_IRQHandler(void);
WEAK void Reserved18_IRQHandler(void);
WEAK void Reserved19_IRQHandler(void);
WEAK void DMATCD0_IRQHandler(void);
WEAK void DMATCD1_IRQHandler(void);
WEAK void DMATCD2_IRQHandler(void);
WEAK void DMATCD3_IRQHandler(void);
WEAK void DMATCD4_IRQHandler(void);
WEAK void DMATCD5_IRQHandler(void);
WEAK void DMATCD6_IRQHandler(void);
WEAK void DMATCD7_IRQHandler(void);
WEAK void DMATCD8_IRQHandler(void);
WEAK void DMATCD9_IRQHandler(void);
WEAK void DMATCD10_IRQHandler(void);
WEAK void DMATCD11_IRQHandler(void);
WEAK void DMATCD12_IRQHandler(void);
WEAK void DMATCD13_IRQHandler(void);
WEAK void DMATCD14_IRQHandler(void);
WEAK void DMATCD15_IRQHandler(void);
WEAK void DMATCD16_IRQHandler(void);
WEAK void DMATCD17_IRQHandler(void);
WEAK void DMATCD18_IRQHandler(void);
WEAK void DMATCD19_IRQHandler(void);
WEAK void DMATCD20_IRQHandler(void);
WEAK void DMATCD21_IRQHandler(void);
WEAK void DMATCD22_IRQHandler(void);
WEAK void DMATCD23_IRQHandler(void);
WEAK void DMATCD24_IRQHandler(void);
WEAK void DMATCD25_IRQHandler(void);
WEAK void DMATCD26_IRQHandler(void);
WEAK void DMATCD27_IRQHandler(void);
WEAK void DMATCD28_IRQHandler(void);
WEAK void DMATCD29_IRQHandler(void);
WEAK void DMATCD30_IRQHandler(void);
WEAK void DMATCD31_IRQHandler(void);
WEAK void ERM_0_IRQHandler(void);
WEAK void ERM_1_IRQHandler(void);
WEAK void MCM_IRQHandler(void);
WEAK void STM0_IRQHandler(void);
WEAK void STM1_IRQHandler(void);
WEAK void Reserved57_IRQHandler(void);
WEAK void SWT0_IRQHandler(void);
WEAK void Reserved59_IRQHandler(void);
WEAK void Reserved60_IRQHandler(void);
WEAK void Reserved61_IRQHandler(void);
WEAK void Reserved62_IRQHandler(void);
WEAK void Reserved63_IRQHandler(void);
WEAK void FLASH_0_IRQHandler(void);
WEAK void FLASH_1_IRQHandler(void);
WEAK void FLASH_2_IRQHandler(void);
WEAK void RGM_IRQHandler(void);
WEAK void PMC_IRQHandler(void);
WEAK void SIUL2_0_IRQHandler(void);
WEAK void SIUL2_1_IRQHandler(void);
WEAK void SIUL2_2_IRQHandler(void);
WEAK void SIUL2_3_IRQHandler(void);
WEAK void Reserved73_IRQHandler(void);
WEAK void Reserved74_IRQHandler(void);
WEAK void Reserved75_IRQHandler(void);
WEAK void Reserved76_IRQHandler(void);
WEAK void EMIOS0_2_IRQHandler(void);
WEAK void EMIOS0_3_IRQHandler(void);
WEAK void EMIOS0_4_IRQHandler(void);
WEAK void EMIOS0_5_IRQHandler(void);
WEAK void EMIOS0_6_IRQHandler(void);
WEAK void EMIOS0_7_IRQHandler(void);
WEAK void Reserved83_IRQHandler(void);
WEAK void Reserved84_IRQHandler(void);
WEAK void EMIOS1_2_IRQHandler(void);
WEAK void EMIOS1_3_IRQHandler(void);
WEAK void EMIOS1_4_IRQHandler(void);
WEAK void EMIOS1_5_IRQHandler(void);
WEAK void EMIOS1_6_IRQHandler(void);
WEAK void EMIOS1_7_IRQHandler(void);
WEAK void Reserved91_IRQHandler(void);
WEAK void Reserved92_IRQHandler(void);
WEAK void EMIOS2_2_IRQHandler(void);
WEAK void EMIOS2_3_IRQHandler(void);
WEAK void EMIOS2_4_IRQHandler(void);
WEAK void EMIOS2_5_IRQHandler(void);
WEAK void EMIOS2_6_IRQHandler(void);
WEAK void EMIOS2_7_IRQHandler(void);
WEAK void WKPU_IRQHandler(void);
WEAK void CMU0_IRQHandler(void);
WEAK void CMU1_IRQHandler(void);
WEAK void CMU2_IRQHandler(void);
WEAK void BCTU_IRQHandler(void);
WEAK void Reserved104_IRQHandler(void);
WEAK void Reserved105_IRQHandler(void);
WEAK void Reserved106_IRQHandler(void);
WEAK void Reserved107_IRQHandler(void);
WEAK void LCU0_IRQHandler(void);
WEAK void LCU1_IRQHandler(void);
WEAK void Reserved110_IRQHandler(void);
WEAK void Reserved111_IRQHandler(void);
WEAK void PIT0_IRQHandler(void);
WEAK void PIT1_IRQHandler(void);
WEAK void PIT2_IRQHandler(void);
WEAK void Reserved115_IRQHandler(void);
WEAK void Reserved116_IRQHandler(void);
WEAK void Reserved117_IRQHandler(void);
WEAK void RTC_IRQHandler(void);
WEAK void Reserved119_IRQHandler(void);
WEAK void Reserved120_IRQHandler(void);
WEAK void EMAC_0_IRQHandler(void);
WEAK void EMAC_1_IRQHandler(void);
WEAK void EMAC_2_IRQHandler(void);
WEAK void EMAC_3_IRQHandler(void);
WEAK void FlexCAN0_0_IRQHandler(void);
WEAK void FlexCAN0_1_IRQHandler(void);
WEAK void FlexCAN0_2_IRQHandler(void);
WEAK void FlexCAN0_3_IRQHandler(void);
WEAK void FlexCAN1_0_IRQHandler(void);
WEAK void FlexCAN1_1_IRQHandler(void);
WEAK void FlexCAN1_2_IRQHandler(void);
WEAK void FlexCAN2_0_IRQHandler(void);
WEAK void FlexCAN2_1_IRQHandler(void);
WEAK void FlexCAN2_2_IRQHandler(void);
WEAK void FlexCAN3_0_IRQHandler(void);
WEAK void FlexCAN3_1_IRQHandler(void);
WEAK void FlexCAN4_0_IRQHandler(void);
WEAK void FlexCAN4_1_IRQHandler(void);
WEAK void FlexCAN5_0_IRQHandler(void);
WEAK void FlexCAN5_1_IRQHandler(void);
WEAK void Reserved141_IRQHandler(void);
WEAK void Reserved142_IRQHandler(void);
WEAK void Reserved143_IRQHandler(void);
WEAK void Reserved144_IRQHandler(void);
WEAK void Reserved145_IRQHandler(void);
WEAK void Reserved146_IRQHandler(void);
WEAK void Reserved147_IRQHandler(void);
WEAK void Reserved148_IRQHandler(void);
WEAK void Reserved149_IRQHandler(void);
WEAK void Reserved150_IRQHandler(void);
WEAK void Reserved151_IRQHandler(void);
WEAK void Reserved152_IRQHandler(void);
WEAK void Reserved153_IRQHandler(void);
WEAK void Reserved154_IRQHandler(void);
WEAK void FLEXIO_IRQHandler(void);
WEAK void Reserved156_IRQHandler(void);
WEAK void LPUART_0_IRQHandler(void);
WEAK void LPUART_1_IRQHandler(void);
WEAK void LPUART_2_IRQHandler(void);
WEAK void LPUART_3_IRQHandler(void);
WEAK void LPUART_4_IRQHandler(void);
WEAK void LPUART_5_IRQHandler(void);
WEAK void LPUART_6_IRQHandler(void);
WEAK void LPUART_7_IRQHandler(void);
WEAK void LPUART_8_IRQHandler(void);
WEAK void LPUART_9_IRQHandler(void);
WEAK void LPUART_10_IRQHandler(void);
WEAK void LPUART_11_IRQHandler(void);
WEAK void LPUART_12_IRQHandler(void);
WEAK void LPUART_13_IRQHandler(void);
WEAK void LPUART_14_IRQHandler(void);
WEAK void LPUART_15_IRQHandler(void);
WEAK void Reserved173_IRQHandler(void);
WEAK void Reserved174_IRQHandler(void);
WEAK void Reserved175_IRQHandler(void);
WEAK void Reserved176_IRQHandler(void);
WEAK void LPI2C0_IRQHandler(void);
WEAK void LPI2C1_IRQHandler(void);
WEAK void Reserved179_IRQHandler(void);
WEAK void Reserved180_IRQHandler(void);
WEAK void LPSPI0_IRQHandler(void);
WEAK void LPSPI1_IRQHandler(void);
WEAK void LPSPI2_IRQHandler(void);
WEAK void LPSPI3_IRQHandler(void);
WEAK void LPSPI4_IRQHandler(void);
WEAK void LPSPI5_IRQHandler(void);
WEAK void Reserved187_IRQHandler(void);
WEAK void Reserved188_IRQHandler(void);
WEAK void QSPI_IRQHandler(void);
WEAK void SAI0_IRQHandler(void);
WEAK void SAI1_IRQHandler(void);
WEAK void Reserved192_IRQHandler(void);
WEAK void Reserved193_IRQHandler(void);
WEAK void JDC_IRQHandler(void);
WEAK void Reserved195_IRQHandler(void);
WEAK void ADC0_IRQHandler(void);
WEAK void ADC1_IRQHandler(void);
WEAK void ADC2_IRQHandler(void);
WEAK void CMP0_IRQHandler(void);
WEAK void CMP1_IRQHandler(void);
WEAK void CMP2_IRQHandler(void);
WEAK void Reserved202_IRQHandler(void);
WEAK void Reserved203_IRQHandler(void);
WEAK void Reserved204_IRQHandler(void);
WEAK void FCCU_0_IRQHandler(void);
WEAK void FCCU_1_IRQHandler(void);
WEAK void Reserved207_IRQHandler(void);
WEAK void MU0_B_TX_IRQHandler(void);
WEAK void MU0_B_RX_IRQHandler(void);
WEAK void MU0_B_IRQHandler(void);
WEAK void MU1_B_TX_IRQHandler(void);
WEAK void MU1_B_RX_IRQHandler(void);
WEAK void MU1_B_IRQHandler(void);
WEAK void Reserved214_IRQHandler(void);
WEAK void Reserved215_IRQHandler(void);
WEAK void Reserved216_IRQHandler(void);
WEAK void Reserved217_IRQHandler(void);
WEAK void Reserved218_IRQHandler(void);
WEAK void Reserved219_IRQHandler(void);
WEAK void Reserved220_IRQHandler(void);
WEAK void Reserved221_IRQHandler(void);
WEAK void Reserved222_IRQHandler(void);
WEAK void Reserved223_IRQHandler(void);
WEAK void Reserved224_IRQHandler(void);
WEAK void Reserved225_IRQHandler(void);
WEAK void Reserved226_IRQHandler(void);
WEAK void Reserved227_IRQHandler(void);
WEAK void PLL_LOL_IRQHandler(void);
WEAK void CORE_CLK_FAIL_IRQHandler(void);
WEAK void Reserved230_IRQHandler(void);
WEAK void AIPS_PLAT_CLK_FAIL_IRQHandler(void);
WEAK void Reserved232_IRQHandler(void);
WEAK void HSE_B_CLK_FAIL_IRQHandler(void);

//*****************************************************************************
// Forward declaration of the driver IRQ handlers. These are aliased
// to the DefaultISR, which is a 'forever' loop. When the driver
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//*****************************************************************************
void Reserved16_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved17_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved18_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved19_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD0_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD1_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD2_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD3_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD4_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD5_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD6_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD7_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD8_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD9_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD10_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD11_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD12_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD13_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD14_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD15_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD16_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD17_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD18_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD19_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD20_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD21_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD22_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD23_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD24_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD25_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD26_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD27_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD28_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD29_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD30_DriverIRQHandler(void) ALIAS(DefaultISR);
void DMATCD31_DriverIRQHandler(void) ALIAS(DefaultISR);
void ERM_0_DriverIRQHandler(void) ALIAS(DefaultISR);
void ERM_1_DriverIRQHandler(void) ALIAS(DefaultISR);
void MCM_DriverIRQHandler(void) ALIAS(DefaultISR);
void STM_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void Reserved57_DriverIRQHandler(void) ALIAS(DefaultISR);
void SWT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved59_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved60_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved61_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved62_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved63_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLASH_0_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLASH_1_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLASH_2_DriverIRQHandler(void) ALIAS(DefaultISR);
void RGM_DriverIRQHandler(void) ALIAS(DefaultISR);
void PMC_DriverIRQHandler(void) ALIAS(DefaultISR);
void SIUL2_0_DriverIRQHandler(void) ALIAS(DefaultISR);
void SIUL2_1_DriverIRQHandler(void) ALIAS(DefaultISR);
void SIUL2_2_DriverIRQHandler(void) ALIAS(DefaultISR);
void SIUL2_3_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved73_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved74_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved75_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved76_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS0_2_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS0_3_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS0_4_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS0_5_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS0_6_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS0_7_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved83_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved84_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS1_2_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS1_3_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS1_4_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS1_5_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS1_6_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS1_7_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved91_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved92_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS2_2_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS2_3_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS2_4_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS2_5_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS2_6_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMIOS2_7_DriverIRQHandler(void) ALIAS(DefaultISR);
void WKPU_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMU_FC_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void CMU_FM_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void BCTU_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved104_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved105_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved106_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved107_DriverIRQHandler(void) ALIAS(DefaultISR);
void LCU0_DriverIRQHandler(void) ALIAS(DefaultISR);
void LCU1_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved110_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved111_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIT1_DriverIRQHandler(void) ALIAS(DefaultISR);
void PIT2_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved115_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved116_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved117_DriverIRQHandler(void) ALIAS(DefaultISR);
void RTC_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved119_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved120_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMAC_0_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMAC_1_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMAC_2_DriverIRQHandler(void) ALIAS(DefaultISR);
void EMAC_3_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLEXCAN_DriverDataIRQHandler(uint32_t instance, uint32_t start, uint32_t end, uint32_t type) ALIAS(DefaultISR4);
void FLEXCAN_DriverEventIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void Reserved141_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved142_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved143_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved144_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved145_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved146_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved147_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved148_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved149_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved150_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved151_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved152_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved153_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved154_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLEXIO_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved156_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPUART_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void Reserved173_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved174_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved175_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved176_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPI2C_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void Reserved179_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved180_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPSPI_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void Reserved187_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved188_DriverIRQHandler(void) ALIAS(DefaultISR);
void QSPI_DriverIRQHandler(void) ALIAS(DefaultISR);
void SAI_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void Reserved192_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved193_DriverIRQHandler(void) ALIAS(DefaultISR);
void JDC_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved195_DriverIRQHandler(void) ALIAS(DefaultISR);
void ADC0_DriverIRQHandler(void) ALIAS(DefaultISR);
void ADC1_DriverIRQHandler(void) ALIAS(DefaultISR);
void ADC2_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMP0_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMP1_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMP2_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved202_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved203_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved204_DriverIRQHandler(void) ALIAS(DefaultISR);
void FCCU_0_DriverIRQHandler(void) ALIAS(DefaultISR);
void FCCU_1_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved207_DriverIRQHandler(void) ALIAS(DefaultISR);
void MU0_B_TX_DriverIRQHandler(void) ALIAS(DefaultISR);
void MU0_B_RX_DriverIRQHandler(void) ALIAS(DefaultISR);
void MU0_B_DriverIRQHandler(void) ALIAS(DefaultISR);
void MU1_B_TX_DriverIRQHandler(void) ALIAS(DefaultISR);
void MU1_B_RX_DriverIRQHandler(void) ALIAS(DefaultISR);
void MU1_B_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved214_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved215_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved216_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved217_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved218_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved219_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved220_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved221_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved222_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved223_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved224_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved225_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved226_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved227_DriverIRQHandler(void) ALIAS(DefaultISR);
void PLL_LOL_DriverIRQHandler(void) ALIAS(DefaultISR);
void CORE_CLK_FAIL_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved230_DriverIRQHandler(void) ALIAS(DefaultISR);
void AIPS_PLAT_CLK_FAIL_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved232_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSE_B_CLK_FAIL_DriverIRQHandler(void) ALIAS(DefaultISR);

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
#endif // __REDLIB__
#elif defined(__ICCARM__)
extern void __iar_program_start(void);
#elif defined(__GNUC__)
#if defined(__REDLIB__)
extern void __main(void);
#else
extern void _start(void);
#endif // __REDLIB
#else
#error Unsupported toolchain!
#endif

//*****************************************************************************
// External declaration for the pointer to the stack top from the Linker Script
//*****************************************************************************
#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
extern uint32_t Image$$ARM_LIB_STACK$$ZI$$Limit[];
#elif defined(__MCUXPRESSO)
extern void _vStackTop(void);
extern void _vStackBase(void);
#elif defined(__ICCARM__)
#pragma segment="CSTACK"
#define __StackTop __section_end("CSTACK")
#define __StackBase __section_begin("CSTACK")
#elif defined(__GNUC__)
extern uint32_t __StackTop[];

extern uint32_t __etext[];
extern uint32_t __data_start__[];
extern uint32_t __data_end__[];

extern uint32_t __ram_function_flash_start[];
extern uint32_t __ram_function_start__[];
extern uint32_t __ram_function_end__[];

extern uint32_t __noncache_data_flash_start[];
extern uint32_t __noncache_data_start__[];
extern uint32_t __noncache_data_end__[];

extern uint32_t __noncache_bss_start__[];
extern uint32_t __noncache_bss_end__[];

extern uint32_t __qadata_flash_start[];
extern uint32_t __qadata_start__[];
extern uint32_t __qadata_end__[];

extern uint32_t __bss_start__[];
extern uint32_t __bss_end__[];
#else
#error Unsupported toolchain!
#endif

//*****************************************************************************
#if defined (__cplusplus)
} // extern "C"
#endif

//*****************************************************************************
// The vector table.
// This relies on the linker script to place at correct location in memory.
//*****************************************************************************
#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
extern void (* const __Vectors[])(void);
__attribute__ ((used, section(".isr_vector")))
void (* const __Vectors[])(void) = {
    (void(*)())(uint32_t)Image$$ARM_LIB_STACK$$ZI$$Limit,   // The initial stack pointer
    Reset_Handler,                     // The reset handler
#elif defined(__MCUXPRESSO)
extern void (* const g_pfnVectors[])(void);
extern void * __Vectors __attribute__ ((alias ("g_pfnVectors")));

__attribute__ ((used, section(".isr_vector")))
void (* const g_pfnVectors[])(void) = {
    &_vStackTop,                       // The initial stack pointer
    ResetISR,                          // The reset handler
#elif defined (__ICCARM__)
extern void (* const __vector_table[])(void);
__attribute__ ((used, section(".intvec")))
void (* const __vector_table[])(void) = {
    (void(*)())(uint32_t)__StackTop,   // The initial stack pointer
    Reset_Handler,                     // The reset handler
#elif defined (__GNUC__)
extern void (* const __isr_vector[])(void);
__attribute__ ((used, section(".isr_vector")))
void (* const __isr_vector[])(void) = {
    (void(*)())(uint32_t)__StackTop,   // The initial stack pointer
    Reset_Handler,                     // The reset handler
#else
#error Unsupported toolchain!
#endif
    NMI_Handler,                       // NMI Handler
    HardFault_Handler,                 // Hard Fault Handler
    MemManage_Handler,                 // MPU Fault Handler
    BusFault_Handler,                  // Bus Fault Handler
    UsageFault_Handler,                // Usage Fault Handler
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    SVC_Handler,                       // SVCall Handler
    DebugMon_Handler,                  // Debug Monitor Handler
    0,                                 // Reserved
    PendSV_Handler,                    // PendSV Handler
    SysTick_Handler,                   // SysTick Handler

    // Chip Level
    Reserved16_IRQHandler,         // 16 : Reserved interrupt
    Reserved17_IRQHandler,         // 17 : Reserved interrupt
    Reserved18_IRQHandler,         // 18 : Reserved interrupt
    Reserved19_IRQHandler,         // 19 : Reserved interrupt
    DMATCD0_IRQHandler,            // 20 : DMA transfer complete and error CH0
    DMATCD1_IRQHandler,            // 21 : DMA transfer complete and error CH1
    DMATCD2_IRQHandler,            // 22 : DMA transfer complete and error CH2
    DMATCD3_IRQHandler,            // 23 : DMA transfer complete and error CH3
    DMATCD4_IRQHandler,            // 24 : DMA transfer complete and error CH4
    DMATCD5_IRQHandler,            // 25 : DMA transfer complete and error CH5
    DMATCD6_IRQHandler,            // 26 : DMA transfer complete and error CH6
    DMATCD7_IRQHandler,            // 27 : DMA transfer complete and error CH7
    DMATCD8_IRQHandler,            // 28 : DMA transfer complete and error CH8
    DMATCD9_IRQHandler,            // 29 : DMA transfer complete and error CH9
    DMATCD10_IRQHandler,           // 30 : DMA transfer complete and error CH10
    DMATCD11_IRQHandler,           // 31 : DMA transfer complete and error CH11
    DMATCD12_IRQHandler,           // 32 : DMA transfer complete and error CH12
    DMATCD13_IRQHandler,           // 33 : DMA transfer complete and error CH13
    DMATCD14_IRQHandler,           // 34 : DMA transfer complete and error CH14
    DMATCD15_IRQHandler,           // 35 : DMA transfer complete and error CH15
    DMATCD16_IRQHandler,           // 36 : DMA transfer complete and error CH16
    DMATCD17_IRQHandler,           // 37 : DMA transfer complete and error CH17
    DMATCD18_IRQHandler,           // 38 : DMA transfer complete and error CH18
    DMATCD19_IRQHandler,           // 39 : DMA transfer complete and error CH19
    DMATCD20_IRQHandler,           // 40 : DMA transfer complete and error CH20
    DMATCD21_IRQHandler,           // 41 : DMA transfer complete and error CH21
    DMATCD22_IRQHandler,           // 42 : DMA transfer complete and error CH22
    DMATCD23_IRQHandler,           // 43 : DMA transfer complete and error CH23
    DMATCD24_IRQHandler,           // 44 : DMA transfer complete and error CH24
    DMATCD25_IRQHandler,           // 45 : DMA transfer complete and error CH25
    DMATCD26_IRQHandler,           // 46 : DMA transfer complete and error CH26
    DMATCD27_IRQHandler,           // 47 : DMA transfer complete and error CH27
    DMATCD28_IRQHandler,           // 48 : DMA transfer complete and error CH28
    DMATCD29_IRQHandler,           // 49 : DMA transfer complete and error CH29
    DMATCD30_IRQHandler,           // 50 : DMA transfer complete and error CH30
    DMATCD31_IRQHandler,           // 51 : DMA transfer complete and error CH31
    ERM_0_IRQHandler,              // 52 : Single bit ECC error
    ERM_1_IRQHandler,              // 53 : Multi bit ECC error
    MCM_IRQHandler,                // 54 : FPU ORed sources ORed with MCM Write Abort interrupt
    STM0_IRQHandler,               // 55 : Single interrupt vector for all four channels
    STM1_IRQHandler,               // 56 : Single interrupt vector for all four channels
    Reserved57_IRQHandler,         // 57 : Reserved interrupt
    SWT0_IRQHandler,               // 58 : Platform watchdog initial time-out
    Reserved59_IRQHandler,         // 59 : Reserved interrupt
    Reserved60_IRQHandler,         // 60 : Reserved interrupt
    Reserved61_IRQHandler,         // 61 : Reserved interrupt
    Reserved62_IRQHandler,         // 62 : Reserved interrupt
    Reserved63_IRQHandler,         // 63 : Reserved interrupt
    FLASH_0_IRQHandler,            // 64 : Program or erase operation is completed
    FLASH_1_IRQHandler,            // 65 : Main watchdog timeout interrupt
    FLASH_2_IRQHandler,            // 66 : Alternate watchdog timeout interrupt
    RGM_IRQHandler,                // 67 : Interrupt request to the system
    PMC_IRQHandler,                // 68 : One interrupt for all LVDs, One interrupt for all HVDs
    SIUL2_0_IRQHandler,            // 69 : External Interrupt Vector 0
    SIUL2_1_IRQHandler,            // 70 : External Interrupt Vector 1
    SIUL2_2_IRQHandler,            // 71 : External Interrupt Vector 2
    SIUL2_3_IRQHandler,            // 72 : External Interrupt Vector 3
    Reserved73_IRQHandler,         // 73 : Reserved interrupt
    Reserved74_IRQHandler,         // 74 : Reserved interrupt
    Reserved75_IRQHandler,         // 75 : Reserved interrupt
    Reserved76_IRQHandler,         // 76 : Reserved interrupt
    EMIOS0_2_IRQHandler,           // 77 : Interrupt request 23,22,21,20
    EMIOS0_3_IRQHandler,           // 78 : Interrupt request 19,18,17,16
    EMIOS0_4_IRQHandler,           // 79 : Interrupt request 15,14,13,12
    EMIOS0_5_IRQHandler,           // 80 : Interrupt request 11,10,9,8
    EMIOS0_6_IRQHandler,           // 81 : Interrupt request 7,6,5,4
    EMIOS0_7_IRQHandler,           // 82 : Interrupt request 3,2,1,0
    Reserved83_IRQHandler,         // 83 : Reserved interrupt
    Reserved84_IRQHandler,         // 84 : Reserved interrupt
    EMIOS1_2_IRQHandler,           // 85 : Interrupt request 23,22,21,20
    EMIOS1_3_IRQHandler,           // 86 : Interrupt request 19,18,17,16
    EMIOS1_4_IRQHandler,           // 87 : Interrupt request 15,14,13,12
    EMIOS1_5_IRQHandler,           // 88 : Interrupt request 11,10,9,8
    EMIOS1_6_IRQHandler,           // 89 : Interrupt request 7,6,5,4
    EMIOS1_7_IRQHandler,           // 90 : Interrupt request 3,2,1,0
    Reserved91_IRQHandler,         // 91 : Reserved interrupt
    Reserved92_IRQHandler,         // 92 : Reserved interrupt
    EMIOS2_2_IRQHandler,           // 93 : Interrupt request 23,22,21,20
    EMIOS2_3_IRQHandler,           // 94 : Interrupt request 19,18,17,16
    EMIOS2_4_IRQHandler,           // 95 : Interrupt request 15,14,13,12
    EMIOS2_5_IRQHandler,           // 96 : Interrupt request 11,10,9,8
    EMIOS2_6_IRQHandler,           // 97 : Interrupt request 7,6,5,4
    EMIOS2_7_IRQHandler,           // 98 : Interrupt request 3,2,1,0
    WKPU_IRQHandler,               // 99 : Interrupts from pad group 0, 1, 2, 3, 0_64, 1_64, 2_64, 3_64
    CMU0_IRQHandler,               // 100: CMU0 interrupt
    CMU1_IRQHandler,               // 101: CMU1 interrupt
    CMU2_IRQHandler,               // 102: CMU2 interrupt
    BCTU_IRQHandler,               // 103: Ored interrupt for BCTU
    Reserved104_IRQHandler,        // 104: Reserved interrupt
    Reserved105_IRQHandler,        // 105: Reserved interrupt
    Reserved106_IRQHandler,        // 106: Reserved interrupt
    Reserved107_IRQHandler,        // 107: Reserved interrupt
    LCU0_IRQHandler,               // 108: Interrupt_0, 1, 2
    LCU1_IRQHandler,               // 109: Interrupt_0, 1, 2
    Reserved110_IRQHandler,        // 110: Reserved interrupt
    Reserved111_IRQHandler,        // 111: Reserved interrupt
    PIT0_IRQHandler,               // 112: Interrupt for Channel0,Interrupt for Channel1,Interrupt for Channel2,Interrupt for Channel3,Interrupt for Channel4
    PIT1_IRQHandler,               // 113: Interrupt for Channel0,Interrupt for Channel1,Interrupt for Channel2,Interrupt for Channel3
    PIT2_IRQHandler,               // 114: Interrupt for Channel0,Interrupt for Channel1,Interrupt for Channel2,Interrupt for Channel3
    Reserved115_IRQHandler,        // 115: Reserved interrupt
    Reserved116_IRQHandler,        // 116: Reserved interrupt
    Reserved117_IRQHandler,        // 117: Reserved interrupt
    RTC_IRQHandler,                // 118: RTCF or ROVRF interrupt to be serviced by the system controller
    Reserved119_IRQHandler,        // 119: Reserved interrupt
    Reserved120_IRQHandler,        // 120: Reserved interrupt
    EMAC_0_IRQHandler,             // 121: Common interrupt
    EMAC_1_IRQHandler,             // 122: Tx interrupt 0 and 1
    EMAC_2_IRQHandler,             // 123: rx interrupt 0 and 1
    EMAC_3_IRQHandler,             // 124: safety interrupt correctable
    FlexCAN0_0_IRQHandler,         // 125: Ored status and error
    FlexCAN0_1_IRQHandler,         // 126: Message Buffer Interrupt line 0-31
    FlexCAN0_2_IRQHandler,         // 127: Message Buffer Interrupt line 32-63
    FlexCAN0_3_IRQHandler,         // 128: Message Buffer Interrupt line 64-95
    FlexCAN1_0_IRQHandler,         // 129: Ored status and error
    FlexCAN1_1_IRQHandler,         // 130: Message Buffer Interrupt line 0-31
    FlexCAN1_2_IRQHandler,         // 131: Message Buffer Interrupt line 32-63
    FlexCAN2_0_IRQHandler,         // 132: Ored status and error
    FlexCAN2_1_IRQHandler,         // 133: Message Buffer Interrupt line 0-31
    FlexCAN2_2_IRQHandler,         // 134: Message Buffer Interrupt line 32-63
    FlexCAN3_0_IRQHandler,         // 135: Ored status and error
    FlexCAN3_1_IRQHandler,         // 136: Message Buffer Interrupt line 0-31
    FlexCAN4_0_IRQHandler,         // 137: Ored status and error
    FlexCAN4_1_IRQHandler,         // 138: Message Buffer Interrupt line 0-31
    FlexCAN5_0_IRQHandler,         // 139: Ored status and error
    FlexCAN5_1_IRQHandler,         // 140: Message Buffer Interrupt line 0-31
    Reserved141_IRQHandler,        // 141: Reserved interrupt
    Reserved142_IRQHandler,        // 142: Reserved interrupt
    Reserved143_IRQHandler,        // 143: Reserved interrupt
    Reserved144_IRQHandler,        // 144: Reserved interrupt
    Reserved145_IRQHandler,        // 145: Reserved interrupt
    Reserved146_IRQHandler,        // 146: Reserved interrupt
    Reserved147_IRQHandler,        // 147: Reserved interrupt
    Reserved148_IRQHandler,        // 148: Reserved interrupt
    Reserved149_IRQHandler,        // 149: Reserved interrupt
    Reserved150_IRQHandler,        // 150: Reserved interrupt
    Reserved151_IRQHandler,        // 151: Reserved interrupt
    Reserved152_IRQHandler,        // 152: Reserved interrupt
    Reserved153_IRQHandler,        // 153: Reserved interrupt
    Reserved154_IRQHandler,        // 154: Reserved interrupt
    FLEXIO_IRQHandler,             // 155: FlexIO Interrupt
    Reserved156_IRQHandler,        // 156: Reserved interrupt
    LPUART_0_IRQHandler,           // 157: TX and RX interrupt
    LPUART_1_IRQHandler,           // 158: TX and RX interrupt
    LPUART_2_IRQHandler,           // 159: TX and RX interrupt
    LPUART_3_IRQHandler,           // 160: TX and RX interrupt
    LPUART_4_IRQHandler,           // 161: TX and RX interrupt
    LPUART_5_IRQHandler,           // 162: TX and RX interrupt
    LPUART_6_IRQHandler,           // 163: TX and RX interrupt
    LPUART_7_IRQHandler,           // 164: TX and RX interrupt
    LPUART_8_IRQHandler,           // 165: TX and RX interrupt
    LPUART_9_IRQHandler,           // 166: TX and RX interrupt
    LPUART_10_IRQHandler,          // 167: TX and RX interrupt
    LPUART_11_IRQHandler,          // 168: TX and RX interrupt
    LPUART_12_IRQHandler,          // 169: TX and RX interrupt
    LPUART_13_IRQHandler,          // 170: TX and RX interrupt
    LPUART_14_IRQHandler,          // 171: TX and RX interrupt
    LPUART_15_IRQHandler,          // 172: TX and RX interrupt
    Reserved173_IRQHandler,        // 173: Reserved interrupt
    Reserved174_IRQHandler,        // 174: Reserved interrupt
    Reserved175_IRQHandler,        // 175: Reserved interrupt
    Reserved176_IRQHandler,        // 176: Reserved interrupt
    LPI2C0_IRQHandler,             // 177: LPI2C Master Interrupt
    LPI2C1_IRQHandler,             // 178: LPI2C Master Interrupt
    Reserved179_IRQHandler,        // 179: Reserved interrupt
    Reserved180_IRQHandler,        // 180: Reserved interrupt
    LPSPI0_IRQHandler,             // 181: LPSPI Interrupt
    LPSPI1_IRQHandler,             // 182: LPSPI Interrupt
    LPSPI2_IRQHandler,             // 183: LPSPI Interrupt
    LPSPI3_IRQHandler,             // 184: LPSPI Interrupt
    LPSPI4_IRQHandler,             // 185: LPSPI Interrupt
    LPSPI5_IRQHandler,             // 186: LPSPI Interrupt
    Reserved187_IRQHandler,        // 187: Reserved interrupt
    Reserved188_IRQHandler,        // 188: Reserved interrupt
    QSPI_IRQHandler,               // 189: All interrupts ORed output
    SAI0_IRQHandler,               // 190: RX and TX interrupt
    SAI1_IRQHandler,               // 191: RX and TX interrupt
    Reserved192_IRQHandler,        // 192: Reserved interrupt
    Reserved193_IRQHandler,        // 193: Reserved interrupt
    JDC_IRQHandler,                // 194: Indicates new data to be read from JIN_IPS register or can be written to JOUT_IPS register
    Reserved195_IRQHandler,        // 195: Reserved interrupt
    ADC0_IRQHandler,               // 196: End of conversion, Error interrupt, Watchdog interrupt
    ADC1_IRQHandler,               // 197: End of conversion, Error interrupt, Watchdog interrupt
    ADC2_IRQHandler,               // 198: End of conversion, Error interrupt, Watchdog interrupt
    CMP0_IRQHandler,               // 199: Async interrupt
    CMP1_IRQHandler,               // 200: Async interrupt
    CMP2_IRQHandler,               // 201: Async interrupt
    Reserved202_IRQHandler,        // 202: Reserved interrupt
    Reserved203_IRQHandler,        // 203: Reserved interrupt
    Reserved204_IRQHandler,        // 204: Reserved interrupt
    FCCU_0_IRQHandler,             // 205: Interrupt request(ALARM state)
    FCCU_1_IRQHandler,             // 206: Interrupt request(miscellaneous conditions)
    Reserved207_IRQHandler,        // 207: Reserved interrupt
    MU0_B_TX_IRQHandler,           // 208: ORed TX interrupt to MU-0
    MU0_B_RX_IRQHandler,           // 209: ORed RX interrupt to MU-0
    MU0_B_IRQHandler,              // 210: ORed general purpose interrupt request to MU-0
    MU1_B_TX_IRQHandler,           // 211: ORed TX interrupt to MU-1
    MU1_B_RX_IRQHandler,           // 212: ORed RX interrupt to MU-1
    MU1_B_IRQHandler,              // 213: ORed general purpose interrupt request to MU-1
    Reserved214_IRQHandler,        // 214: Reserved interrupt
    Reserved215_IRQHandler,        // 215: Reserved interrupt
    Reserved216_IRQHandler,        // 216: Reserved interrupt
    Reserved217_IRQHandler,        // 217: Reserved interrupt
    Reserved218_IRQHandler,        // 218: Reserved interrupt
    Reserved219_IRQHandler,        // 219: Reserved interrupt
    Reserved220_IRQHandler,        // 220: Reserved interrupt
    Reserved221_IRQHandler,        // 221: Reserved interrupt
    Reserved222_IRQHandler,        // 222: Reserved interrupt
    Reserved223_IRQHandler,        // 223: Reserved interrupt
    Reserved224_IRQHandler,        // 224: Reserved interrupt
    Reserved225_IRQHandler,        // 225: Reserved interrupt
    Reserved226_IRQHandler,        // 226: Reserved interrupt
    Reserved227_IRQHandler,        // 227: Reserved interrupt
    PLL_LOL_IRQHandler,            // 228: PLL LOL interrupt
    CORE_CLK_FAIL_IRQHandler,      // 229: CORE_CLK_FAIL CMU reset reaction interrupt
    Reserved230_IRQHandler,        // 230: Reserved interrupt
    AIPS_PLAT_CLK_FAIL_IRQHandler, // 231: AIPS_PLAT_CLK_FAIL CMU reset reaction interrupt
    Reserved232_IRQHandler,        // 232: Reserved interrupt
    HSE_B_CLK_FAIL_IRQHandler,     // 233: HSE_B_CLK_FAIL CMU reset reaction interrupt
};                                 /* End of __vector_table */

#if defined(__MCUXPRESSO)
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
#endif

//*****************************************************************************
// Reset entry point for your code.
// Sets up a simple runtime environment and initializes the C/C++
// library.
//*****************************************************************************
//  ITCM base and end addresses
#define ITCM_BASE_ADDR 0x00000000UL
#define ITCM_END_ADDR 0x00007fffUL

// DTCM base and end addresses
#define DTCM_BASE_ADDR 0x20000000UL
#define DTCM_END_ADDR 0x2000ffffUL

// Normal RAM base and end addresses
#define NRAM_BASE_ADDR 0x20408000UL
#define NRAM_END_ADDR 0x2044ffffUL

// Standby RAM base and end addresses
#define SRAM_BASE_ADDR 0x20400000UL
#define SRAM_END_ADDR  0x20407fffUL

// patterns for initial ecc, heap and stack sections initialization
#ifndef STARTUP_ECC_INITVALUE
#define STARTUP_ECC_INITVALUE   0xFEEDFACECAFEBEEFULL
#endif

#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
__attribute__ ((naked))
void Reset_Handler(void) {
    // Disable interrupts
    __asm volatile ("cpsid i");
    // Config VTOR & MSP register
    __asm volatile ("LDR R0, =0xE000ED08  \n"
                    "STR %0, [R0]         \n"
                    "LDR R1, [%0]         \n"
                    "MSR MSP, R1          \n"
                    :
                    : "r"(__Vectors)
                    : "r0");

#if !defined(BYPASS_ECC_ITCM_INIT)
    __asm volatile ("LDR     R0, =0x00000000     \n"
                    "LDR     R1, =0x00007FFF     \n"
                    "LDR     R2, =.ram_init_itcm \n"
                    "CMP.W   R1, R2              \n"
                    "BCS.N   .ram_init_itcm_done \n"
                    ".ram_init_itcm:             \n"
                    "LDR     R2, =0              \n"
                    "LDR     R3, =0              \n"
                    "LDR     R4, =0              \n"
                    "LDR     R5, =0              \n"
                    ".loop01:                    \n"
                    "STMIA   R0!, {R2 - R5}      \n"
                    "CMP     R0, R1              \n"
                    "BCC.N   .loop01             \n"
                    ".ram_init_itcm_done:        \n"
                    );
#endif

#if !defined(BYPASS_ECC_DTCM_INIT)
    __asm volatile ("LDR     R0, =0x20000000     \n"
                    "LDR     R1, =0x2000FFFF     \n"
                    "LDR     R2, =0              \n"
                    "LDR     R3, =0              \n"
                    "LDR     R4, =0              \n"
                    "LDR     R5, =0              \n"
                    ".loop02:                    \n"
                    "STMIA   R0!, {R2 - R5}      \n"
                    "CMP     R0, R1              \n"
                    "BCC.N   .loop02             \n"
                    );
#endif

#if !defined(BYPASS_ECC_SRAM_INIT)
    __asm volatile ("LDR     R0, =0x20408000     \n"
                    "LDR     R2, =0x4028C000     \n"
                    "LDR     R2, [R2]            \n"
                    "LSLS    R2, R2, #31         \n"
                    "BPL.N   .ram_init_start     \n"
                    "LDR     R0, =0x20400000     \n"
                    ".ram_init_start:            \n"
                    "LDR     R1, =0x2044FFFF     \n"
                    "LDR     R2, =0              \n"
                    "LDR     R3, =0              \n"
                    "LDR     R4, =0              \n"
                    "LDR     R5, =0              \n"
                    ".loop03:                    \n"
                    "STMIA   R0!, {R2 - R5}      \n"
                    "CMP     R0, R1              \n"
                    "BCC.N   .loop03             \n"
                    );
#endif

#elif defined(__MCUXPRESSO)
__attribute__ ((naked, section(".after_vectors.reset")))
void ResetISR(void) {
    // Disable interrupts
    __asm volatile ("cpsid i");
    // Config VTOR & MSP register
    __asm volatile ("LDR R0, =0xE000ED08  \n"
                    "STR %0, [R0]         \n"
                    "LDR R1, [%0]         \n"
                    "MSR MSP, R1          \n"
                    :
                    : "r"(g_pfnVectors)
                    : "r0");
#elif defined (__ICCARM__)
__stackless void Reset_Handler(void) {
    // Disable interrupts
    __asm volatile ("cpsid i");
    // Config VTOR & MSP register
    __asm volatile ("LDR R0, =0xE000ED08  \n"
                    "STR %0, [R0]         \n"
                    "LDR R1, [%0]         \n"
                    "MSR MSP, R1          \n"
                    :
                    : "r"(__vector_table)
                    : "r0");
#elif defined (__GNUC__)
__attribute__ ((naked))
void Reset_Handler(void) {
    // Disable interrupts
    __asm volatile ("cpsid i");
    // Config VTOR & MSP register
    __asm volatile ("LDR R0, =0xE000ED08  \n"
                    "STR %0, [R0]         \n"
                    "LDR R1, [%0]         \n"
                    "MSR MSP, R1          \n"
                    :
                    : "r"(__isr_vector)
                    : "r0");
#else
#error Unsupported toolchain!
#endif

#if !defined(__ARMCC_VERSION) && !defined(__CC_ARM) // ARM compiler does not allow C code in naked function.
    // TCM/SRAM controller must perform a read-modify-write for any access < 32-bit(ITCM) or 64-bit to keep the ECC updated.
    // The Software must ensure the TCM is ECC clean by initializing all memories that have the potential to be accessed as < 32-bit(ITCM) or 64-bit.
    uint64_t *pDest;

#if !defined(BYPASS_ECC_ITCM_INIT)
#if defined(__MCUXPRESSO)
    if ((uint32_t)ResetISR > ITCM_END_ADDR)
#elif defined (__ICCARM__) || defined (__GNUC__)
    if ((uint32_t)Reset_Handler > ITCM_END_ADDR) // Bypass ECC RAM initialization on ITCM target, debugger will do the initialization
#else
#error Unsupported toolchain!
#endif
    {
       pDest = (uint64_t *)ITCM_BASE_ADDR;
       while (pDest < (uint64_t*)ITCM_END_ADDR) { *pDest++ = STARTUP_ECC_INITVALUE; }
    }
#endif

#if !defined(BYPASS_ECC_DTCM_INIT)
    pDest = (uint64_t*)DTCM_BASE_ADDR;
    while (pDest < (uint64_t*)DTCM_END_ADDR) { *pDest++ = STARTUP_ECC_INITVALUE; }
#endif

#if !defined(BYPASS_ECC_SRAM_INIT)
    pDest = (uint64_t*)NRAM_BASE_ADDR;
    while (pDest < (uint64_t*)NRAM_END_ADDR) { *pDest++ = STARTUP_ECC_INITVALUE; }

    if (((*(volatile uint32_t *)(0x4028c000)) & 0x1U) != 0U)  // Skip standby SRAM if not POR, MC_RGM->DES & MC_RGM_DES_F_POR_MASK
    {
      pDest = (uint64_t*)SRAM_BASE_ADDR;
      while (pDest < (uint64_t*)SRAM_END_ADDR) { *pDest++ = STARTUP_ECC_INITVALUE; }
    }
#endif

    SystemInit();
#endif

#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
    __asm volatile ("LDR R0, =SystemInit \n"
                    "BLX R0              \n"
                    "cpsie i             \n"
                    "LDR R0, =__main     \n"
                    "BX  R0              \n"
                    );
#elif defined(__MCUXPRESSO)
    // Copy the data sections from flash to SRAM.
    unsigned int LoadAddr, ExeAddr, SectionLen;
    unsigned int *SectionTableAddr;

    // Load base address of Global Section Table
    SectionTableAddr = &__data_section_table;

    // Copy the data sections from flash to SRAM.
    while (SectionTableAddr < &__data_section_table_end) {
        LoadAddr = *SectionTableAddr++;
        ExeAddr = *SectionTableAddr++;
        SectionLen = *SectionTableAddr++;
        data_init(LoadAddr, ExeAddr, SectionLen);
    }

    // At this point, SectionTableAddr = &__bss_section_table;
    // Zero fill the bss segment
    while (SectionTableAddr < &__bss_section_table_end) {
        ExeAddr = *SectionTableAddr++;
        SectionLen = *SectionTableAddr++;
        bss_init(ExeAddr, SectionLen);
    }

#if defined (__cplusplus)
    // Call C++ library initialisation
    __libc_init_array();
#endif

    // Reenable interrupts
    __asm volatile ("cpsie i");

#if defined (__REDLIB__)
    // Call the Redlib library, which in turn calls main()
    __main();
#else
    main();
#endif // __REDLIB__

#elif defined(__ICCARM__)
    // Reenable interrupts
    __asm volatile ("cpsie i");

    __iar_program_start();
#elif defined(__GNUC__)
/*     Loop to copy data from read only memory to RAM. The ranges
 *      of copy from/to are specified by following symbols evaluated in
 *      linker script.
 *      1. __etext/_data_start__/__data_end__
 *      2. __ram_function_flash_start/__ram_function_start__/__ram_function_end__
 *      3. __qadata_flash_start/__qadata_start__/__qadata_end__
 *      4. __noncache_data_flash_start/__noncache_data_start__/__noncache_data_end__
 *      Note: All must be aligned to 4 bytes boundary.
 */
    uint32_t *pDataSrc, *pDataDest;

    pDataSrc = (uint32_t *)__etext;
    pDataDest = (uint32_t *)__data_start__;
    while (pDataDest < __data_end__)
    {
        *pDataDest ++ = *pDataSrc++;
    }
#ifdef __STARTUP_INITIALIZE_RAMFUNCTION
    pDataSrc = (uint32_t *)__ram_function_flash_start;
    pDataDest = (uint32_t *)__ram_function_start__;
    while (pDataDest < __ram_function_end__)
    {
        *pDataDest++ = *pDataSrc++;
    }
#endif // __STARTUP_INITIALIZE_RAMFUNCTION
#ifdef __STARTUP_INITIALIZE_NONCACHEDATA
    pDataSrc = (uint32_t *)__noncache_data_flash_start;
    pDataDest = (uint32_t *)__noncache_data_start__;
    while (pDataDest < __noncache_data_end__)
    {
        *pDataDest++ = *pDataSrc++;
    }

    // zero inited ncache section initialization
    pDataDest = (uint32_t *)__noncache_bss_start__;
    while (pDataDest < __noncache_bss_end__)
    {
        *pDataDest++ = 0;
    }
#endif // __STARTUP_INITIALIZE_NONCACHEDATA
#ifdef __STARTUP_INITIALIZE_QADATA
    pDataSrc = (uint32_t *)__qadata_flash_start;
    pDataDest = (uint32_t *)__qadata_start__;
    while (pDataDest < __qadata_end__)
    {
        *pDataDest++ = *pDataSrc++;
    }
#endif // __STARTUP_INITIALIZE_QADATA
#ifdef __STARTUP_CLEAR_BSS
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
        *pDataDest++ = 0;
    }
#endif // __STARTUP_CLEAR_BSS

    __asm volatile ("cpsie i");

#ifndef __START
#ifdef __REDLIB__
#define __START __main
#else
#define __START _start
#endif
#endif

    __START();

#endif

    //
    // main() shouldn't return, but if it does, we'll just enter an infinite loop
    //
#if !defined(__ARMCC_VERSION) && !defined(__CC_ARM)
    while (1)
    {
        ;
    }
#endif
}

//*****************************************************************************
// Default core exception handlers. Override the ones here by defining your own
// handler routines in your application code.
//*****************************************************************************
WEAK_AV void NMI_Handler(void)
{
    while(1)
    {
    }
}

WEAK_AV void HardFault_Handler(void)
{
    while(1)
    {
    }
}

WEAK_AV void MemManage_Handler(void)
{
    while(1)
    {
    }
}

WEAK_AV void BusFault_Handler(void)
{
    while(1)
    {
    }
}

WEAK_AV void UsageFault_Handler(void)
{
    while(1)
    {
    }
}

WEAK_AV void SVC_Handler(void)
{
    while(1)
    {
    }
}

WEAK_AV void DebugMon_Handler(void)
{
    while(1)
    {
    }
}

WEAK_AV void PendSV_Handler(void)
{
    while(1)
    {
    }
}

WEAK_AV void SysTick_Handler(void)
{
    while(1)
    {
    }
}

//*****************************************************************************
// Processor ends up here if an unexpected interrupt occurs or a specific
// handler is not present in the application code.
//*****************************************************************************
WEAK_AV void DefaultISR(void)
{
    while(1)
    {
    }
}

WEAK_AV void DefaultISR1(uint32_t instance)
{
    while(1)
    {
    }
}

WEAK_AV void DefaultISR4(uint32_t instance, uint32_t start, uint32_t end, uint32_t type)
{
    while(1)
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

WEAK void Reserved17_IRQHandler(void)
{
    Reserved17_DriverIRQHandler();
}

WEAK void Reserved18_IRQHandler(void)
{
    Reserved18_DriverIRQHandler();
}

WEAK void Reserved19_IRQHandler(void)
{
    Reserved19_DriverIRQHandler();
}

WEAK void DMATCD0_IRQHandler(void)
{
    DMATCD0_DriverIRQHandler();
}

WEAK void DMATCD1_IRQHandler(void)
{
    DMATCD1_DriverIRQHandler();
}

WEAK void DMATCD2_IRQHandler(void)
{
    DMATCD2_DriverIRQHandler();
}

WEAK void DMATCD3_IRQHandler(void)
{
    DMATCD3_DriverIRQHandler();
}

WEAK void DMATCD4_IRQHandler(void)
{
    DMATCD4_DriverIRQHandler();
}

WEAK void DMATCD5_IRQHandler(void)
{
    DMATCD5_DriverIRQHandler();
}

WEAK void DMATCD6_IRQHandler(void)
{
    DMATCD6_DriverIRQHandler();
}

WEAK void DMATCD7_IRQHandler(void)
{
    DMATCD7_DriverIRQHandler();
}

WEAK void DMATCD8_IRQHandler(void)
{
    DMATCD8_DriverIRQHandler();
}

WEAK void DMATCD9_IRQHandler(void)
{
    DMATCD9_DriverIRQHandler();
}

WEAK void DMATCD10_IRQHandler(void)
{
    DMATCD10_DriverIRQHandler();
}

WEAK void DMATCD11_IRQHandler(void)
{
    DMATCD11_DriverIRQHandler();
}

WEAK void DMATCD12_IRQHandler(void)
{
    DMATCD12_DriverIRQHandler();
}

WEAK void DMATCD13_IRQHandler(void)
{
    DMATCD13_DriverIRQHandler();
}

WEAK void DMATCD14_IRQHandler(void)
{
    DMATCD14_DriverIRQHandler();
}

WEAK void DMATCD15_IRQHandler(void)
{
    DMATCD15_DriverIRQHandler();
}

WEAK void DMATCD16_IRQHandler(void)
{
    DMATCD16_DriverIRQHandler();
}

WEAK void DMATCD17_IRQHandler(void)
{
    DMATCD17_DriverIRQHandler();
}

WEAK void DMATCD18_IRQHandler(void)
{
    DMATCD18_DriverIRQHandler();
}

WEAK void DMATCD19_IRQHandler(void)
{
    DMATCD19_DriverIRQHandler();
}

WEAK void DMATCD20_IRQHandler(void)
{
    DMATCD20_DriverIRQHandler();
}

WEAK void DMATCD21_IRQHandler(void)
{
    DMATCD21_DriverIRQHandler();
}

WEAK void DMATCD22_IRQHandler(void)
{
    DMATCD22_DriverIRQHandler();
}

WEAK void DMATCD23_IRQHandler(void)
{
    DMATCD23_DriverIRQHandler();
}

WEAK void DMATCD24_IRQHandler(void)
{
    DMATCD24_DriverIRQHandler();
}

WEAK void DMATCD25_IRQHandler(void)
{
    DMATCD25_DriverIRQHandler();
}

WEAK void DMATCD26_IRQHandler(void)
{
    DMATCD26_DriverIRQHandler();
}

WEAK void DMATCD27_IRQHandler(void)
{
    DMATCD27_DriverIRQHandler();
}

WEAK void DMATCD28_IRQHandler(void)
{
    DMATCD28_DriverIRQHandler();
}

WEAK void DMATCD29_IRQHandler(void)
{
    DMATCD29_DriverIRQHandler();
}

WEAK void DMATCD30_IRQHandler(void)
{
    DMATCD30_DriverIRQHandler();
}

WEAK void DMATCD31_IRQHandler(void)
{
    DMATCD31_DriverIRQHandler();
}

WEAK void ERM_0_IRQHandler(void)
{
    ERM_0_DriverIRQHandler();
}

WEAK void ERM_1_IRQHandler(void)
{
    ERM_1_DriverIRQHandler();
}

WEAK void MCM_IRQHandler(void)
{
    MCM_DriverIRQHandler();
}

WEAK void STM0_IRQHandler(void)
{
    STM_DriverIRQHandler(0U);
}

WEAK void STM1_IRQHandler(void)
{
    STM_DriverIRQHandler(1U);
}

WEAK void Reserved57_IRQHandler(void)
{
    Reserved57_DriverIRQHandler();
}

WEAK void SWT0_IRQHandler(void)
{
    SWT0_DriverIRQHandler();
}

WEAK void Reserved59_IRQHandler(void)
{
    Reserved59_DriverIRQHandler();
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

WEAK void FLASH_0_IRQHandler(void)
{
    FLASH_0_DriverIRQHandler();
}

WEAK void FLASH_1_IRQHandler(void)
{
    FLASH_1_DriverIRQHandler();
}

WEAK void FLASH_2_IRQHandler(void)
{
    FLASH_2_DriverIRQHandler();
}

WEAK void RGM_IRQHandler(void)
{
    RGM_DriverIRQHandler();
}

WEAK void PMC_IRQHandler(void)
{
    PMC_DriverIRQHandler();
}

WEAK void SIUL2_0_IRQHandler(void)
{
    SIUL2_0_DriverIRQHandler();
}

WEAK void SIUL2_1_IRQHandler(void)
{
    SIUL2_1_DriverIRQHandler();
}

WEAK void SIUL2_2_IRQHandler(void)
{
    SIUL2_2_DriverIRQHandler();
}

WEAK void SIUL2_3_IRQHandler(void)
{
    SIUL2_3_DriverIRQHandler();
}

WEAK void Reserved73_IRQHandler(void)
{
    Reserved73_DriverIRQHandler();
}

WEAK void Reserved74_IRQHandler(void)
{
    Reserved74_DriverIRQHandler();
}

WEAK void Reserved75_IRQHandler(void)
{
    Reserved75_DriverIRQHandler();
}

WEAK void Reserved76_IRQHandler(void)
{
    Reserved76_DriverIRQHandler();
}

WEAK void EMIOS0_2_IRQHandler(void)
{
    EMIOS0_2_DriverIRQHandler();
}

WEAK void EMIOS0_3_IRQHandler(void)
{
    EMIOS0_3_DriverIRQHandler();
}

WEAK void EMIOS0_4_IRQHandler(void)
{
    EMIOS0_4_DriverIRQHandler();
}

WEAK void EMIOS0_5_IRQHandler(void)
{
    EMIOS0_5_DriverIRQHandler();
}

WEAK void EMIOS0_6_IRQHandler(void)
{
    EMIOS0_6_DriverIRQHandler();
}

WEAK void EMIOS0_7_IRQHandler(void)
{
    EMIOS0_7_DriverIRQHandler();
}

WEAK void Reserved83_IRQHandler(void)
{
    Reserved83_DriverIRQHandler();
}

WEAK void Reserved84_IRQHandler(void)
{
    Reserved84_DriverIRQHandler();
}

WEAK void EMIOS1_2_IRQHandler(void)
{
    EMIOS1_2_DriverIRQHandler();
}

WEAK void EMIOS1_3_IRQHandler(void)
{
    EMIOS1_3_DriverIRQHandler();
}

WEAK void EMIOS1_4_IRQHandler(void)
{
    EMIOS1_4_DriverIRQHandler();
}

WEAK void EMIOS1_5_IRQHandler(void)
{
    EMIOS1_5_DriverIRQHandler();
}

WEAK void EMIOS1_6_IRQHandler(void)
{
    EMIOS1_6_DriverIRQHandler();
}

WEAK void EMIOS1_7_IRQHandler(void)
{
    EMIOS1_7_DriverIRQHandler();
}

WEAK void Reserved91_IRQHandler(void)
{
    Reserved91_DriverIRQHandler();
}

WEAK void Reserved92_IRQHandler(void)
{
    Reserved92_DriverIRQHandler();
}

WEAK void EMIOS2_2_IRQHandler(void)
{
    EMIOS2_2_DriverIRQHandler();
}

WEAK void EMIOS2_3_IRQHandler(void)
{
    EMIOS2_3_DriverIRQHandler();
}

WEAK void EMIOS2_4_IRQHandler(void)
{
    EMIOS2_4_DriverIRQHandler();
}

WEAK void EMIOS2_5_IRQHandler(void)
{
    EMIOS2_5_DriverIRQHandler();
}

WEAK void EMIOS2_6_IRQHandler(void)
{
    EMIOS2_6_DriverIRQHandler();
}

WEAK void EMIOS2_7_IRQHandler(void)
{
    EMIOS2_7_DriverIRQHandler();
}

WEAK void WKPU_IRQHandler(void)
{
    WKPU_DriverIRQHandler();
}

WEAK void CMU0_IRQHandler(void)
{
    CMU_FC_DriverIRQHandler(0U);
}

WEAK void CMU1_IRQHandler(void)
{
    CMU_FM_DriverIRQHandler(0U);
}

WEAK void CMU2_IRQHandler(void)
{
    CMU_FM_DriverIRQHandler(1U);
}

WEAK void BCTU_IRQHandler(void)
{
    BCTU_DriverIRQHandler();
}

WEAK void Reserved104_IRQHandler(void)
{
    Reserved104_DriverIRQHandler();
}

WEAK void Reserved105_IRQHandler(void)
{
    Reserved105_DriverIRQHandler();
}

WEAK void Reserved106_IRQHandler(void)
{
    Reserved106_DriverIRQHandler();
}

WEAK void Reserved107_IRQHandler(void)
{
    Reserved107_DriverIRQHandler();
}

WEAK void LCU0_IRQHandler(void)
{
    LCU0_DriverIRQHandler();
}

WEAK void LCU1_IRQHandler(void)
{
    LCU1_DriverIRQHandler();
}

WEAK void Reserved110_IRQHandler(void)
{
    Reserved110_DriverIRQHandler();
}

WEAK void Reserved111_IRQHandler(void)
{
    Reserved111_DriverIRQHandler();
}

WEAK void PIT0_IRQHandler(void)
{
    PIT0_DriverIRQHandler();
}

WEAK void PIT1_IRQHandler(void)
{
    PIT1_DriverIRQHandler();
}

WEAK void PIT2_IRQHandler(void)
{
    PIT2_DriverIRQHandler();
}

WEAK void Reserved115_IRQHandler(void)
{
    Reserved115_DriverIRQHandler();
}

WEAK void Reserved116_IRQHandler(void)
{
    Reserved116_DriverIRQHandler();
}

WEAK void Reserved117_IRQHandler(void)
{
    Reserved117_DriverIRQHandler();
}

WEAK void RTC_IRQHandler(void)
{
    RTC_DriverIRQHandler();
}

WEAK void Reserved119_IRQHandler(void)
{
    Reserved119_DriverIRQHandler();
}

WEAK void Reserved120_IRQHandler(void)
{
    Reserved120_DriverIRQHandler();
}

WEAK void EMAC_0_IRQHandler(void)
{
    EMAC_0_DriverIRQHandler();
}

WEAK void EMAC_1_IRQHandler(void)
{
    EMAC_1_DriverIRQHandler();
}

WEAK void EMAC_2_IRQHandler(void)
{
    EMAC_2_DriverIRQHandler();
}

WEAK void EMAC_3_IRQHandler(void)
{
    EMAC_3_DriverIRQHandler();
}

WEAK void FlexCAN0_0_IRQHandler(void)
{
    FLEXCAN_DriverEventIRQHandler(0U);
}

WEAK void FlexCAN0_1_IRQHandler(void)
{
    FLEXCAN_DriverDataIRQHandler(0U, 0U, 31U, 1U);
}

WEAK void FlexCAN0_2_IRQHandler(void)
{
    FLEXCAN_DriverDataIRQHandler(0U, 32U, 63U, 0U);
}

WEAK void FlexCAN0_3_IRQHandler(void)
{
    FLEXCAN_DriverDataIRQHandler(0U, 64U, 95U, 0U);
}

WEAK void FlexCAN1_0_IRQHandler(void)
{
    FLEXCAN_DriverEventIRQHandler(1U);
}

WEAK void FlexCAN1_1_IRQHandler(void)
{
    FLEXCAN_DriverDataIRQHandler(1U, 0U, 31U, 0U);
}

WEAK void FlexCAN1_2_IRQHandler(void)
{
    FLEXCAN_DriverDataIRQHandler(1U, 32U, 63U, 0U);
}

WEAK void FlexCAN2_0_IRQHandler(void)
{
    FLEXCAN_DriverEventIRQHandler(2U);
}

WEAK void FlexCAN2_1_IRQHandler(void)
{
    FLEXCAN_DriverDataIRQHandler(2U, 0U, 31U, 0U);
}

WEAK void FlexCAN2_2_IRQHandler(void)
{
    FLEXCAN_DriverDataIRQHandler(2U, 32U, 63U, 0U);
}

WEAK void FlexCAN3_0_IRQHandler(void)
{
    FLEXCAN_DriverEventIRQHandler(3U);
}

WEAK void FlexCAN3_1_IRQHandler(void)
{
    FLEXCAN_DriverDataIRQHandler(3U, 0U, 31U, 0U);
}

WEAK void FlexCAN4_0_IRQHandler(void)
{
    FLEXCAN_DriverEventIRQHandler(4U);
}

WEAK void FlexCAN4_1_IRQHandler(void)
{
    FLEXCAN_DriverDataIRQHandler(4U, 0U, 31U, 0U);
}

WEAK void FlexCAN5_0_IRQHandler(void)
{
    FLEXCAN_DriverEventIRQHandler(5U);
}

WEAK void FlexCAN5_1_IRQHandler(void)
{
    FLEXCAN_DriverDataIRQHandler(5U, 0U, 31U, 0U);
}

WEAK void Reserved141_IRQHandler(void)
{
    Reserved141_DriverIRQHandler();
}

WEAK void Reserved142_IRQHandler(void)
{
    Reserved142_DriverIRQHandler();
}

WEAK void Reserved143_IRQHandler(void)
{
    Reserved143_DriverIRQHandler();
}

WEAK void Reserved144_IRQHandler(void)
{
    Reserved144_DriverIRQHandler();
}

WEAK void Reserved145_IRQHandler(void)
{
    Reserved145_DriverIRQHandler();
}

WEAK void Reserved146_IRQHandler(void)
{
    Reserved146_DriverIRQHandler();
}

WEAK void Reserved147_IRQHandler(void)
{
    Reserved147_DriverIRQHandler();
}

WEAK void Reserved148_IRQHandler(void)
{
    Reserved148_DriverIRQHandler();
}

WEAK void Reserved149_IRQHandler(void)
{
    Reserved149_DriverIRQHandler();
}

WEAK void Reserved150_IRQHandler(void)
{
    Reserved150_DriverIRQHandler();
}

WEAK void Reserved151_IRQHandler(void)
{
    Reserved151_DriverIRQHandler();
}

WEAK void Reserved152_IRQHandler(void)
{
    Reserved152_DriverIRQHandler();
}

WEAK void Reserved153_IRQHandler(void)
{
    Reserved153_DriverIRQHandler();
}

WEAK void Reserved154_IRQHandler(void)
{
    Reserved154_DriverIRQHandler();
}

WEAK void FLEXIO_IRQHandler(void)
{
    FLEXIO_DriverIRQHandler();
}

WEAK void Reserved156_IRQHandler(void)
{
    Reserved156_DriverIRQHandler();
}

WEAK void LPUART_0_IRQHandler(void)
{
    LPUART_DriverIRQHandler(0U);
}

WEAK void LPUART_1_IRQHandler(void)
{
    LPUART_DriverIRQHandler(1U);
}

WEAK void LPUART_2_IRQHandler(void)
{
    LPUART_DriverIRQHandler(2U);
}

WEAK void LPUART_3_IRQHandler(void)
{
    LPUART_DriverIRQHandler(3U);
}

WEAK void LPUART_4_IRQHandler(void)
{
    LPUART_DriverIRQHandler(4U);
}

WEAK void LPUART_5_IRQHandler(void)
{
    LPUART_DriverIRQHandler(5U);
}

WEAK void LPUART_6_IRQHandler(void)
{
    LPUART_DriverIRQHandler(6U);
}

WEAK void LPUART_7_IRQHandler(void)
{
    LPUART_DriverIRQHandler(7U);
}

WEAK void LPUART_8_IRQHandler(void)
{
    LPUART_DriverIRQHandler(8U);
}

WEAK void LPUART_9_IRQHandler(void)
{
    LPUART_DriverIRQHandler(9U);
}

WEAK void LPUART_10_IRQHandler(void)
{
    LPUART_DriverIRQHandler(10U);
}

WEAK void LPUART_11_IRQHandler(void)
{
    LPUART_DriverIRQHandler(11U);
}

WEAK void LPUART_12_IRQHandler(void)
{
    LPUART_DriverIRQHandler(12U);
}

WEAK void LPUART_13_IRQHandler(void)
{
    LPUART_DriverIRQHandler(13U);
}

WEAK void LPUART_14_IRQHandler(void)
{
    LPUART_DriverIRQHandler(14U);
}

WEAK void LPUART_15_IRQHandler(void)
{
    LPUART_DriverIRQHandler(15U);
}

WEAK void Reserved173_IRQHandler(void)
{
    Reserved173_DriverIRQHandler();
}

WEAK void Reserved174_IRQHandler(void)
{
    Reserved174_DriverIRQHandler();
}

WEAK void Reserved175_IRQHandler(void)
{
    Reserved175_DriverIRQHandler();
}

WEAK void Reserved176_IRQHandler(void)
{
    Reserved176_DriverIRQHandler();
}

WEAK void LPI2C0_IRQHandler(void)
{
    LPI2C_DriverIRQHandler(0U);
}

WEAK void LPI2C1_IRQHandler(void)
{
    LPI2C_DriverIRQHandler(1U);
}

WEAK void Reserved179_IRQHandler(void)
{
    Reserved179_DriverIRQHandler();
}

WEAK void Reserved180_IRQHandler(void)
{
    Reserved180_DriverIRQHandler();
}

WEAK void LPSPI0_IRQHandler(void)
{
    LPSPI_DriverIRQHandler(0U);
}

WEAK void LPSPI1_IRQHandler(void)
{
    LPSPI_DriverIRQHandler(1U);
}

WEAK void LPSPI2_IRQHandler(void)
{
    LPSPI_DriverIRQHandler(2U);
}

WEAK void LPSPI3_IRQHandler(void)
{
    LPSPI_DriverIRQHandler(3U);
}

WEAK void LPSPI4_IRQHandler(void)
{
    LPSPI_DriverIRQHandler(4U);
}

WEAK void LPSPI5_IRQHandler(void)
{
    LPSPI_DriverIRQHandler(5U);
}

WEAK void Reserved187_IRQHandler(void)
{
    Reserved187_DriverIRQHandler();
}

WEAK void Reserved188_IRQHandler(void)
{
    Reserved188_DriverIRQHandler();
}

WEAK void QSPI_IRQHandler(void)
{
    QSPI_DriverIRQHandler();
}

WEAK void SAI0_IRQHandler(void)
{
    SAI_DriverIRQHandler(0U);
}

WEAK void SAI1_IRQHandler(void)
{
    SAI_DriverIRQHandler(1U);
}

WEAK void Reserved192_IRQHandler(void)
{
    Reserved192_DriverIRQHandler();
}

WEAK void Reserved193_IRQHandler(void)
{
    Reserved193_DriverIRQHandler();
}

WEAK void JDC_IRQHandler(void)
{
    JDC_DriverIRQHandler();
}

WEAK void Reserved195_IRQHandler(void)
{
    Reserved195_DriverIRQHandler();
}

WEAK void ADC0_IRQHandler(void)
{
    ADC0_DriverIRQHandler();
}

WEAK void ADC1_IRQHandler(void)
{
    ADC1_DriverIRQHandler();
}

WEAK void ADC2_IRQHandler(void)
{
    ADC2_DriverIRQHandler();
}

WEAK void CMP0_IRQHandler(void)
{
    CMP0_DriverIRQHandler();
}

WEAK void CMP1_IRQHandler(void)
{
    CMP1_DriverIRQHandler();
}

WEAK void CMP2_IRQHandler(void)
{
    CMP2_DriverIRQHandler();
}

WEAK void Reserved202_IRQHandler(void)
{
    Reserved202_DriverIRQHandler();
}

WEAK void Reserved203_IRQHandler(void)
{
    Reserved203_DriverIRQHandler();
}

WEAK void Reserved204_IRQHandler(void)
{
    Reserved204_DriverIRQHandler();
}

WEAK void FCCU_0_IRQHandler(void)
{
    FCCU_0_DriverIRQHandler();
}

WEAK void FCCU_1_IRQHandler(void)
{
    FCCU_1_DriverIRQHandler();
}

WEAK void Reserved207_IRQHandler(void)
{
    Reserved207_DriverIRQHandler();
}

WEAK void MU0_B_TX_IRQHandler(void)
{
    MU0_B_TX_DriverIRQHandler();
}

WEAK void MU0_B_RX_IRQHandler(void)
{
    MU0_B_RX_DriverIRQHandler();
}

WEAK void MU0_B_IRQHandler(void)
{
    MU0_B_DriverIRQHandler();
}

WEAK void MU1_B_TX_IRQHandler(void)
{
    MU1_B_TX_DriverIRQHandler();
}

WEAK void MU1_B_RX_IRQHandler(void)
{
    MU1_B_RX_DriverIRQHandler();
}

WEAK void MU1_B_IRQHandler(void)
{
    MU1_B_DriverIRQHandler();
}

WEAK void Reserved214_IRQHandler(void)
{
    Reserved214_DriverIRQHandler();
}

WEAK void Reserved215_IRQHandler(void)
{
    Reserved215_DriverIRQHandler();
}

WEAK void Reserved216_IRQHandler(void)
{
    Reserved216_DriverIRQHandler();
}

WEAK void Reserved217_IRQHandler(void)
{
    Reserved217_DriverIRQHandler();
}

WEAK void Reserved218_IRQHandler(void)
{
    Reserved218_DriverIRQHandler();
}

WEAK void Reserved219_IRQHandler(void)
{
    Reserved219_DriverIRQHandler();
}

WEAK void Reserved220_IRQHandler(void)
{
    Reserved220_DriverIRQHandler();
}

WEAK void Reserved221_IRQHandler(void)
{
    Reserved221_DriverIRQHandler();
}

WEAK void Reserved222_IRQHandler(void)
{
    Reserved222_DriverIRQHandler();
}

WEAK void Reserved223_IRQHandler(void)
{
    Reserved223_DriverIRQHandler();
}

WEAK void Reserved224_IRQHandler(void)
{
    Reserved224_DriverIRQHandler();
}

WEAK void Reserved225_IRQHandler(void)
{
    Reserved225_DriverIRQHandler();
}

WEAK void Reserved226_IRQHandler(void)
{
    Reserved226_DriverIRQHandler();
}

WEAK void Reserved227_IRQHandler(void)
{
    Reserved227_DriverIRQHandler();
}

WEAK void PLL_LOL_IRQHandler(void)
{
    PLL_LOL_DriverIRQHandler();
}

WEAK void CORE_CLK_FAIL_IRQHandler(void)
{
    CORE_CLK_FAIL_DriverIRQHandler();
}

WEAK void Reserved230_IRQHandler(void)
{
    Reserved230_DriverIRQHandler();
}

WEAK void AIPS_PLAT_CLK_FAIL_IRQHandler(void)
{
    AIPS_PLAT_CLK_FAIL_DriverIRQHandler();
}

WEAK void Reserved232_IRQHandler(void)
{
    Reserved232_DriverIRQHandler();
}

WEAK void HSE_B_CLK_FAIL_IRQHandler(void)
{
    HSE_B_CLK_FAIL_DriverIRQHandler();
}

//*****************************************************************************

#if defined(DEBUG)
#if defined(__GNUC__)
#pragma GCC pop_options
#endif
#endif // (DEBUG)
