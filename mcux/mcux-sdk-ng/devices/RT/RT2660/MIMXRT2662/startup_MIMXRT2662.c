//*****************************************************************************
// MIMXRT2662_cm85 startup code
//
// Version : 180826
//*****************************************************************************
//
// Copyright 2016-2026 NXP
//
// SPDX-License-Identifier: BSD-3-Clause
//*****************************************************************************

#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#endif

//*****************************************************************************
// Section 1: Toolchain specific
//*****************************************************************************

#if defined(__ICCARM__)
//==============================================================================
// IAR
//==============================================================================

// Mark vector table as not init-needed; the exclusion propagates to all
// VT-reachable IRQ handlers, the functions they call, and the files
// containing them.
extern void (*const __iar_init$$done[])(void) __attribute__((alias("__vector_table")));

extern void __iar_program_start(void);

#define WEAK_AV                 __attribute__((weak))

#define STARTUP_PRAGMA_PUSH
#define STARTUP_PRAGMA_POP

#define STARTUP_RESET_ATTR      __stackless
#define STARTUP_RESET_C_ATTR    __root

#define STARTUP_VT_SECTION      __attribute__((used, section(".intvec")))
#define STARTUP_VT_SYMBOL       __vector_table

#pragma segment = "CSTACK"
#define _vStackTop              __section_end("CSTACK")
#define _vStackBase             __section_begin("CSTACK")

#define STARTUP_RUNTIME_PROLOG()
#define STARTUP_RUNTIME_ENTER()    do { \
    __asm volatile("cpsie i"); \
    __iar_program_start(); \
} while (0)


#elif defined(__ARMCC_VERSION)
//==============================================================================
// MDK
//==============================================================================

extern uint32_t Image$$ARM_LIB_STACK$$ZI$$Base[];
extern uint32_t Image$$ARM_LIB_STACK$$ZI$$Limit[];

extern void __main(void);

#define WEAK_AV                 __attribute__((weak))

#define STARTUP_PRAGMA_PUSH
#define STARTUP_PRAGMA_POP

#define STARTUP_RESET_ATTR      __attribute__((used, section("InRoot$$Sections"))) \
                                __attribute__((naked))
#define STARTUP_RESET_C_ATTR    __attribute__((used, section("InRoot$$Sections"), noinline))

#define STARTUP_VT_SECTION      __attribute__((used, section(".isr_vector")))
#define STARTUP_VT_SYMBOL       __Vectors

#define _vStackTop              Image$$ARM_LIB_STACK$$ZI$$Limit
#define _vStackBase             Image$$ARM_LIB_STACK$$ZI$$Base

#define STARTUP_RUNTIME_PROLOG()
#define STARTUP_RUNTIME_ENTER()    do { \
    __asm volatile("cpsie i"); \
    __main(); \
} while (0)


#elif defined(__GNUC__)
//==============================================================================
// ARMGCC
//==============================================================================

extern uint32_t __StackTop[];
extern uint32_t __StackLimit[];

/* Sections that need Flash-LMA -> RAM-VMA copy. Target-specific pairs
 * (TEXT / QACODE / QADATA) resolve to 0 via linker PROVIDE fallback when
 * absent, so their loops are no-ops without a build-time macro. */
extern uint32_t __DATA_ROM[];
extern uint32_t __data_start__[];
extern uint32_t __data_end__[];

extern uint32_t __CACHELINE_ROM[];
extern uint32_t __cacheline_data_start__[];
extern uint32_t __cacheline_data_end__[];

extern uint32_t __NDATA_ROM[];
extern uint32_t __noncache_data_start__[];
extern uint32_t __noncache_data_end__[];

extern uint32_t __APP_QACODE_ROM[];
extern uint32_t __app_qacode_start__[];
extern uint32_t __app_qacode_end__[];

extern uint32_t __TEXT_ROM[];
extern uint32_t __text_start__[];
extern uint32_t __text_end__[];

extern uint32_t __QACODE_ROM[];
extern uint32_t __qacode_start__[];
extern uint32_t __qacode_end__[];

extern uint32_t __QADATA_ROM[];
extern uint32_t __qadata_start__[];
extern uint32_t __qadata_end__[];

extern uint32_t __DATAEXT_ROM[];
extern uint32_t __dataext_data_start__[];
extern uint32_t __dataext_data_end__[];

/* Zero-init (BSS-like) sections */
extern uint32_t __bss_start__[];
extern uint32_t __bss_end__[];
extern uint32_t __cacheline_bss_start__[];
extern uint32_t __cacheline_bss_end__[];
extern uint32_t __noncache_bss_start__[];
extern uint32_t __noncache_bss_end__[];
extern uint32_t __dataext_bss_start__[];
extern uint32_t __dataext_bss_end__[];

extern void _start(void);

/* This routine performs the scatter-copy, so it MUST live in Flash pre-scatter.
 * Without .text.startup, -ffunction-sections would put it in .text (VMA=RAM for
 * ram/psram/psram_txt targets), and Reset_Handler_C would branch to unloaded
 * RAM and HardFault. */
__attribute__((used, noinline, section(".text.startup")))
static void toolchain_manual_init(void)
{
    uint32_t *src, *dst;

    src = __DATA_ROM;        dst = __data_start__;
    while (dst < __data_end__)           *dst++ = *src++;

    src = __CACHELINE_ROM;   dst = __cacheline_data_start__;
    while (dst < __cacheline_data_end__) *dst++ = *src++;

    src = __NDATA_ROM;       dst = __noncache_data_start__;
    while (dst < __noncache_data_end__)  *dst++ = *src++;

    src = __APP_QACODE_ROM;  dst = __app_qacode_start__;
    while (dst < __app_qacode_end__)     *dst++ = *src++;

    src = __TEXT_ROM;        dst = __text_start__;
    while (dst < __text_end__)           *dst++ = *src++;

    src = __QACODE_ROM;      dst = __qacode_start__;
    while (dst < __qacode_end__)         *dst++ = *src++;

    src = __QADATA_ROM;      dst = __qadata_start__;
    while (dst < __qadata_end__)         *dst++ = *src++;

    src = __DATAEXT_ROM;     dst = __dataext_data_start__;
    while (dst < __dataext_data_end__)   *dst++ = *src++;

    dst = __bss_start__;
    while (dst < __bss_end__)            *dst++ = 0U;

    dst = __cacheline_bss_start__;
    while (dst < __cacheline_bss_end__)  *dst++ = 0U;

    dst = __noncache_bss_start__;
    while (dst < __noncache_bss_end__)   *dst++ = 0U;

    dst = __dataext_bss_start__;
    while (dst < __dataext_bss_end__)    *dst++ = 0U;
}

#define WEAK_AV                 __attribute__((weak))

#if defined(DEBUG)
#define STARTUP_PRAGMA_PUSH      _Pragma("GCC push_options") _Pragma("GCC optimize(\"Og\")")
#define STARTUP_PRAGMA_POP       _Pragma("GCC pop_options")
#else
#define STARTUP_PRAGMA_PUSH
#define STARTUP_PRAGMA_POP
#endif

#define STARTUP_RESET_ATTR      __attribute__((naked, used, section(".text.startup")))
#define STARTUP_RESET_C_ATTR    __attribute__((used, noinline, section(".text.startup")))

#define STARTUP_VT_SECTION      __attribute__((used, section(".isr_vector")))
#define STARTUP_VT_SYMBOL       __isr_vector

#define _vStackTop              __StackTop
#define _vStackBase             __StackLimit

#define STARTUP_RUNTIME_PROLOG()   do { \
    toolchain_manual_init(); \
} while (0)
#define STARTUP_RUNTIME_ENTER()    do { \
    __asm volatile("cpsie i"); \
    _start(); \
} while (0)


#else
#error "Unsupported toolchain"
#endif

STARTUP_PRAGMA_PUSH

//*****************************************************************************
// Section 2: Common macros
//*****************************************************************************

#define WEAK            __attribute__((weak))
#define ALIAS(target)   __attribute__((weak, alias(#target)))

//*****************************************************************************
// Section 3: Common declarations
//*****************************************************************************

extern void SystemInit(void);

STARTUP_RESET_ATTR   void Reset_Handler(void);
STARTUP_RESET_C_ATTR void Reset_Handler_C(void);

//*****************************************************************************
// Section 4: IRQ function declarations
//*****************************************************************************
WEAK_AV void NMI_Handler(void);
WEAK_AV void HardFault_Handler(void);
WEAK_AV void MemManage_Handler(void);
WEAK_AV void BusFault_Handler(void);
WEAK_AV void UsageFault_Handler(void);
WEAK_AV void SVC_Handler(void);
WEAK_AV void DebugMon_Handler(void);
WEAK_AV void PendSV_Handler(void);
WEAK_AV void SysTick_Handler(void);
WEAK_AV void DefaultISR(void);
WEAK_AV void DefaultISR2(uint32_t instance, uint32_t channel);
WEAK_AV void DefaultISR1(uint32_t instance);

WEAK void CMPT_CM85_CTI_IRQHandler(void);
WEAK void Reserved17_IRQHandler(void);
WEAK void Reserved18_IRQHandler(void);
WEAK void CMPT_CM85_ECC_ERROR_IRQHandler(void);
WEAK void Reserved20_IRQHandler(void);
WEAK void Reserved21_IRQHandler(void);
WEAK void CMPT_CM85_MCM_IRQHandler(void);
WEAK void CMPT_TRDC_IRQHandler(void);
WEAK void Reserved24_IRQHandler(void);
WEAK void CMPT_SRAMCTL_0_IRQHandler(void);
WEAK void CMPT_SRAMCTL_1_IRQHandler(void);
WEAK void CMPT_SRAMCTL_2_IRQHandler(void);
WEAK void Reserved28_IRQHandler(void);
WEAK void Reserved29_IRQHandler(void);
WEAK void Reserved30_IRQHandler(void);
WEAK void Reserved31_IRQHandler(void);
WEAK void CMPT_FREQME_IRQHandler(void);
WEAK void Reserved33_IRQHandler(void);
WEAK void Reserved34_IRQHandler(void);
WEAK void Reserved35_IRQHandler(void);
WEAK void CMPT_LLC_IRQHandler(void);
WEAK void Reserved37_IRQHandler(void);
WEAK void Reserved38_IRQHandler(void);
WEAK void Reserved39_IRQHandler(void);
WEAK void CMPT_DAP_IRQHandler(void);
WEAK void MAIN_TRDC_IRQHandler(void);
WEAK void MAIN_AHB2AXI_IRQHandler(void);
WEAK void Reserved43_IRQHandler(void);
WEAK void MAIN_MMU_IRQHandler(void);
WEAK void MAIN_EDMA3_CH0_IRQHandler(void);
WEAK void MAIN_EDMA3_CH1_IRQHandler(void);
WEAK void MAIN_EDMA3_CH2_IRQHandler(void);
WEAK void MAIN_EDMA3_CH3_IRQHandler(void);
WEAK void MAIN_EDMA3_CH4_IRQHandler(void);
WEAK void MAIN_EDMA3_CH5_IRQHandler(void);
WEAK void MAIN_EDMA3_CH6_IRQHandler(void);
WEAK void MAIN_EDMA3_CH7_IRQHandler(void);
WEAK void MAIN_EDMA3_CH8_IRQHandler(void);
WEAK void MAIN_EDMA3_CH9_IRQHandler(void);
WEAK void MAIN_EDMA3_CH10_IRQHandler(void);
WEAK void MAIN_EDMA3_CH11_IRQHandler(void);
WEAK void MAIN_EDMA3_CH12_IRQHandler(void);
WEAK void MAIN_EDMA3_CH13_IRQHandler(void);
WEAK void MAIN_EDMA3_CH14_IRQHandler(void);
WEAK void MAIN_EDMA3_CH15_IRQHandler(void);
WEAK void MAIN_EDMA3_CH16_IRQHandler(void);
WEAK void MAIN_EDMA3_CH17_IRQHandler(void);
WEAK void MAIN_EDMA3_CH18_IRQHandler(void);
WEAK void MAIN_EDMA3_CH19_IRQHandler(void);
WEAK void MAIN_EDMA3_CH20_IRQHandler(void);
WEAK void MAIN_EDMA3_CH21_IRQHandler(void);
WEAK void MAIN_EDMA3_CH22_IRQHandler(void);
WEAK void MAIN_EDMA3_CH23_IRQHandler(void);
WEAK void MAIN_EDMA3_CH24_IRQHandler(void);
WEAK void MAIN_EDMA3_CH25_IRQHandler(void);
WEAK void MAIN_EDMA3_CH26_IRQHandler(void);
WEAK void MAIN_EDMA3_CH27_IRQHandler(void);
WEAK void MAIN_EDMA3_CH28_IRQHandler(void);
WEAK void MAIN_EDMA3_CH29_IRQHandler(void);
WEAK void MAIN_EDMA3_CH30_IRQHandler(void);
WEAK void MAIN_EDMA3_CH31_IRQHandler(void);
WEAK void MAIN_EDMA5_CH0_IRQHandler(void);
WEAK void MAIN_EDMA5_CH1_IRQHandler(void);
WEAK void MAIN_EDMA5_CH2_IRQHandler(void);
WEAK void MAIN_EDMA5_CH3_IRQHandler(void);
WEAK void MAIN_EDMA5_CH4_IRQHandler(void);
WEAK void MAIN_EDMA5_CH5_IRQHandler(void);
WEAK void MAIN_EDMA5_CH6_IRQHandler(void);
WEAK void MAIN_EDMA5_CH7_IRQHandler(void);
WEAK void MAIN_EDMA5_CH8_IRQHandler(void);
WEAK void MAIN_EDMA5_CH9_IRQHandler(void);
WEAK void MAIN_EDMA5_CH10_IRQHandler(void);
WEAK void MAIN_EDMA5_CH11_IRQHandler(void);
WEAK void MAIN_EDMA5_CH12_IRQHandler(void);
WEAK void MAIN_EDMA5_CH13_IRQHandler(void);
WEAK void MAIN_EDMA5_CH14_IRQHandler(void);
WEAK void MAIN_EDMA5_CH15_IRQHandler(void);
WEAK void MAIN_FREQME_IRQHandler(void);
WEAK void HSP_STM_IRQHandler(void);
WEAK void Reserved95_IRQHandler(void);
WEAK void Reserved96_IRQHandler(void);
WEAK void Reserved97_IRQHandler(void);
WEAK void MAIN_XSPI0_IRQHandler(void);
WEAK void MAIN_XSPI1_IRQHandler(void);
WEAK void Reserved100_IRQHandler(void);
WEAK void Reserved101_IRQHandler(void);
WEAK void SYSCON_CGU_INT0_IRQHandler(void);
WEAK void SYSCON_CGU_INT1_IRQHandler(void);
WEAK void SYSCON_CGU_INT2_IRQHandler(void);
WEAK void MAIN_CSSI_IRQHandler(void);
WEAK void MAIN_CSSI_SENTMU0A_IRQHandler(void);
WEAK void MAIN_CSSI_SENTMU1A_IRQHandler(void);
WEAK void Reserved108_IRQHandler(void);
WEAK void SYSCON_PMU_INT0_IRQHandler(void);
WEAK void SYSCON_PMU_INT1_IRQHandler(void);
WEAK void SYSCON_RESETCON_IRQHandler(void);
WEAK void SYSCON_FREQME_IRQHandler(void);
WEAK void Reserved113_IRQHandler(void);
WEAK void Reserved114_IRQHandler(void);
WEAK void Reserved115_IRQHandler(void);
WEAK void HSP_XBAR0_CH0_IRQHandler(void);
WEAK void HSP_XBAR0_CH1_IRQHandler(void);
WEAK void HSP_XBAR0_CH2_IRQHandler(void);
WEAK void HSP_XBAR0_CH3_IRQHandler(void);
WEAK void HSP_XBAR0_CH4_IRQHandler(void);
WEAK void HSP_XBAR0_CH5_IRQHandler(void);
WEAK void HSP_XBAR0_CH6_IRQHandler(void);
WEAK void HSP_XBAR0_CH7_IRQHandler(void);
WEAK void Reserved124_IRQHandler(void);
WEAK void Reserved125_IRQHandler(void);
WEAK void Reserved126_IRQHandler(void);
WEAK void Reserved127_IRQHandler(void);
WEAK void HSP_ADC0_IRQHandler(void);
WEAK void HSP_ADC1_IRQHandler(void);
WEAK void HSP_DAC_IRQHandler(void);
WEAK void HSP_LPIT0_IRQHandler(void);
WEAK void HSP_LPIT1_IRQHandler(void);
WEAK void HSP_EFLEXPWM0_CH0_IRQHandler(void);
WEAK void HSP_EFLEXPWM0_CH1_IRQHandler(void);
WEAK void HSP_EFLEXPWM0_CH2_IRQHandler(void);
WEAK void HSP_EFLEXPWM0_CH3_IRQHandler(void);
WEAK void HSP_EFLEXPWM0_ERROR_IRQHandler(void);
WEAK void HSP_EFLEXPWM1_CH0_IRQHandler(void);
WEAK void HSP_EFLEXPWM1_CH1_IRQHandler(void);
WEAK void HSP_EFLEXPWM1_CH2_IRQHandler(void);
WEAK void HSP_EFLEXPWM1_CH3_IRQHandler(void);
WEAK void HSP_EFLEXPWM1_ERROR_IRQHandler(void);
WEAK void HSP_EFLEXPWM2_CH0_IRQHandler(void);
WEAK void HSP_EFLEXPWM2_CH1_IRQHandler(void);
WEAK void HSP_EFLEXPWM2_CH2_IRQHandler(void);
WEAK void HSP_EFLEXPWM2_CH3_IRQHandler(void);
WEAK void HSP_EFLEXPWM2_ERROR_IRQHandler(void);
WEAK void HSP_EFLEXPWM3_CH0_IRQHandler(void);
WEAK void HSP_EFLEXPWM3_CH1_IRQHandler(void);
WEAK void HSP_EFLEXPWM3_CH2_IRQHandler(void);
WEAK void HSP_EFLEXPWM3_CH3_IRQHandler(void);
WEAK void HSP_EFLEXPWM3_ERROR_IRQHandler(void);
WEAK void HSP_QTPM0_IRQHandler(void);
WEAK void HSP_QTPM1_IRQHandler(void);
WEAK void HSP_QTPM2_IRQHandler(void);
WEAK void HSP_QTPM3_IRQHandler(void);
WEAK void Reserved157_IRQHandler(void);
WEAK void Reserved158_IRQHandler(void);
WEAK void Reserved159_IRQHandler(void);
WEAK void Reserved160_IRQHandler(void);
WEAK void Reserved161_IRQHandler(void);
WEAK void Reserved162_IRQHandler(void);
WEAK void Reserved163_IRQHandler(void);
WEAK void Reserved164_IRQHandler(void);
WEAK void HSP_QTMR0_IRQHandler(void);
WEAK void HSP_QTMR1_IRQHandler(void);
WEAK void HSP_QTMR2_IRQHandler(void);
WEAK void HSP_QTMR3_IRQHandler(void);
WEAK void HSP_EQDC0_IRQHandler(void);
WEAK void HSP_EQDC1_IRQHandler(void);
WEAK void HSP_EQDC2_IRQHandler(void);
WEAK void HSP_EQDC3_IRQHandler(void);
WEAK void HSP_SINC0_CH0_IRQHandler(void);
WEAK void HSP_SINC0_CH1_IRQHandler(void);
WEAK void HSP_SINC0_CH2_IRQHandler(void);
WEAK void HSP_SINC0_CH3_IRQHandler(void);
WEAK void HSP_SINC1_CH0_IRQHandler(void);
WEAK void HSP_SINC1_CH1_IRQHandler(void);
WEAK void HSP_SINC1_CH2_IRQHandler(void);
WEAK void HSP_SINC1_CH3_IRQHandler(void);
WEAK void HSP_FLEXCAN0_IRQHandler(void);
WEAK void HSP_FLEXCAN0_ERROR_IRQHandler(void);
WEAK void HSP_FLEXCAN1_IRQHandler(void);
WEAK void HSP_FLEXCAN1_ERROR_IRQHandler(void);
WEAK void HSP_FLEXCAN2_IRQHandler(void);
WEAK void HSP_FLEXCAN2_ERROR_IRQHandler(void);
WEAK void HSP_FLEXIO0_IRQHandler(void);
WEAK void HSP_FLEXIO1_IRQHandler(void);
WEAK void HSP_FLEXIO2_IRQHandler(void);
WEAK void HSP_I3C_IRQHandler(void);
WEAK void HSP_LPI2C0_IRQHandler(void);
WEAK void HSP_LPI2C1_IRQHandler(void);
WEAK void Reserved193_IRQHandler(void);
WEAK void Reserved194_IRQHandler(void);
WEAK void HSP_LPSPI0_IRQHandler(void);
WEAK void HSP_LPSPI1_IRQHandler(void);
WEAK void HSP_LPSPI2_IRQHandler(void);
WEAK void HSP_LPSPI3_IRQHandler(void);
WEAK void HSP_LPSPI4_IRQHandler(void);
WEAK void HSP_LPUART0_IRQHandler(void);
WEAK void HSP_LPUART1_IRQHandler(void);
WEAK void HSP_LPUART2_IRQHandler(void);
WEAK void HSP_LPUART3_IRQHandler(void);
WEAK void HSP_LPUART4_IRQHandler(void);
WEAK void HSP_LPUART5_IRQHandler(void);
WEAK void HSP_GPIO0_CH0_IRQHandler(void);
WEAK void HSP_GPIO0_CH1_IRQHandler(void);
WEAK void HSP_GPIO1_CH0_IRQHandler(void);
WEAK void HSP_GPIO1_CH1_IRQHandler(void);
WEAK void HSP_GPIO2_CH0_IRQHandler(void);
WEAK void HSP_GPIO2_CH1_IRQHandler(void);
WEAK void HSP_GPIO3_CH0_IRQHandler(void);
WEAK void HSP_GPIO3_CH1_IRQHandler(void);
WEAK void HSP_GPIO4_CH0_IRQHandler(void);
WEAK void HSP_GPIO4_CH1_IRQHandler(void);
WEAK void Reserved216_IRQHandler(void);
WEAK void Reserved217_IRQHandler(void);
WEAK void Reserved218_IRQHandler(void);
WEAK void Reserved219_IRQHandler(void);
WEAK void Reserved220_IRQHandler(void);
WEAK void WAKE_TRDC_IRQHandler(void);
WEAK void WAKE_XBAR_CH0_IRQHandler(void);
WEAK void WAKE_XBAR_CH1_IRQHandler(void);
WEAK void WAKE_EDMA3_CH0_IRQHandler(void);
WEAK void WAKE_EDMA3_CH1_IRQHandler(void);
WEAK void WAKE_EDMA3_CH2_IRQHandler(void);
WEAK void WAKE_EDMA3_CH3_IRQHandler(void);
WEAK void WAKE_EDMA3_CH4_IRQHandler(void);
WEAK void WAKE_EDMA3_CH5_IRQHandler(void);
WEAK void WAKE_EDMA3_CH6_IRQHandler(void);
WEAK void WAKE_EDMA3_CH7_IRQHandler(void);
WEAK void WAKE_ACMP0_IRQHandler(void);
WEAK void WAKE_ACMP1_IRQHandler(void);
WEAK void WAKE_ACMP2_IRQHandler(void);
WEAK void WAKE_ACMP3_IRQHandler(void);
WEAK void WAKE_EWM_IRQHandler(void);
WEAK void WAKE_FREQME_IRQHandler(void);
WEAK void WAKE_LPTMR0_IRQHandler(void);
WEAK void WAKE_LPTMR1_IRQHandler(void);
WEAK void WAKE_QTPM0_IRQHandler(void);
WEAK void WAKE_QTPM1_IRQHandler(void);
WEAK void WAKE_QTPM2_IRQHandler(void);
WEAK void WAKE_QTPM3_IRQHandler(void);
WEAK void WAKE_SWT0_IRQHandler(void);
WEAK void WAKE_SWT1_IRQHandler(void);
WEAK void Reserved246_IRQHandler(void);
WEAK void Reserved247_IRQHandler(void);
WEAK void Reserved248_IRQHandler(void);
WEAK void Reserved249_IRQHandler(void);
WEAK void WAKE_I3C_IRQHandler(void);
WEAK void WAKE_LPI2C0_IRQHandler(void);
WEAK void WAKE_LPI2C1_IRQHandler(void);
WEAK void WAKE_LPSPI_IRQHandler(void);
WEAK void WAKE_LPUART0_IRQHandler(void);
WEAK void WAKE_LPUART1_IRQHandler(void);
WEAK void WAKE_GPIO_CH0_IRQHandler(void);
WEAK void WAKE_GPIO_CH1_IRQHandler(void);
WEAK void WAKE_PDM_EVENT_IRQHandler(void);
WEAK void WAKE_PDM_ERROR_IRQHandler(void);
WEAK void WAKE_PDM_HWVAD_EVENT_IRQHandler(void);
WEAK void WAKE_PDM_HWVAD_ERROR_IRQHandler(void);
WEAK void Reserved262_IRQHandler(void);
WEAK void VBAT_BBSM_INT0_IRQHandler(void);
WEAK void Reserved264_IRQHandler(void);
WEAK void VBAT_TDET_IRQHandler(void);
WEAK void VBAT_LPTMR_IRQHandler(void);
WEAK void VBAT_RTC_IRQHandler(void);
WEAK void VBAT_GPIO_CH0_IRQHandler(void);
WEAK void VBAT_GPIO_CH1_IRQHandler(void);
WEAK void VBAT_VBATCON_IRQHandler(void);
WEAK void AUDIO_TRDC_IRQHandler(void);
WEAK void AUDIO_SAI0_IRQHandler(void);
WEAK void AUDIO_SAI1_IRQHandler(void);
WEAK void AUDIO_SAI2_IRQHandler(void);
WEAK void Reserved275_IRQHandler(void);
WEAK void Reserved276_IRQHandler(void);
WEAK void Reserved277_IRQHandler(void);
WEAK void AUDIO_PDM_EVENT_IRQHandler(void);
WEAK void AUDIO_PDM_ERROR_IRQHandler(void);
WEAK void Reserved280_IRQHandler(void);
WEAK void Reserved281_IRQHandler(void);
WEAK void Reserved282_IRQHandler(void);
WEAK void Reserved283_IRQHandler(void);
WEAK void Reserved284_IRQHandler(void);
WEAK void Reserved285_IRQHandler(void);
WEAK void AUDIO_SPDIF_IRQHandler(void);
WEAK void AUDIO_EDMA3_CH0_IRQHandler(void);
WEAK void AUDIO_EDMA3_CH1_IRQHandler(void);
WEAK void AUDIO_EDMA3_CH2_IRQHandler(void);
WEAK void AUDIO_EDMA3_CH3_IRQHandler(void);
WEAK void AUDIO_EDMA3_CH4_IRQHandler(void);
WEAK void AUDIO_EDMA3_CH5_IRQHandler(void);
WEAK void AUDIO_EDMA3_CH6_IRQHandler(void);
WEAK void AUDIO_EDMA3_CH7_IRQHandler(void);
WEAK void Reserved295_IRQHandler(void);
WEAK void Reserved296_IRQHandler(void);
WEAK void Reserved297_IRQHandler(void);
WEAK void Reserved298_IRQHandler(void);
WEAK void Reserved299_IRQHandler(void);
WEAK void Reserved300_IRQHandler(void);
WEAK void Reserved301_IRQHandler(void);
WEAK void Reserved302_IRQHandler(void);
WEAK void Reserved303_IRQHandler(void);
WEAK void AUDIO_ASRC_IRQHandler(void);
WEAK void AUDIO_FREQME_IRQHandler(void);
WEAK void Reserved306_IRQHandler(void);
WEAK void Reserved307_IRQHandler(void);
WEAK void Reserved308_IRQHandler(void);
WEAK void Reserved309_IRQHandler(void);
WEAK void Reserved310_IRQHandler(void);
WEAK void COMM_TRDC_IRQHandler(void);
WEAK void COMM_ENET_QOS_IRQHandler(void);
WEAK void COMM_ENET_QOS_TX_IRQHandler(void);
WEAK void COMM_ENET_QOS_RX_IRQHandler(void);
WEAK void COMM_ENET_TX_IRQHandler(void);
WEAK void COMM_ENET_RX_IRQHandler(void);
WEAK void COMM_ENET_OTHER_IRQHandler(void);
WEAK void COMM_ENET_1588_IRQHandler(void);
WEAK void COMM_FLEXSPI_SLV_IRQHandler(void);
WEAK void COMM_USB0_IRQHandler(void);
WEAK void COMM_USBPHY_IRQHandler(void);
WEAK void COMM_USB1_IRQHandler(void);
WEAK void COMM_USDHC0_IRQHandler(void);
WEAK void COMM_USDHC1_IRQHandler(void);
WEAK void Reserved325_IRQHandler(void);
WEAK void COMM_TENBASET_PHY0_IRQHandler(void);
WEAK void Reserved327_IRQHandler(void);
WEAK void COMM_TENBASET_PHY1_IRQHandler(void);
WEAK void Reserved329_IRQHandler(void);
WEAK void COMM_FREQME_IRQHandler(void);
WEAK void MEDIA_TRDC_IRQHandler(void);
WEAK void Reserved332_IRQHandler(void);
WEAK void MEDIA_DCIF_CH0_IRQHandler(void);
WEAK void MEDIA_DCIF_CH1_IRQHandler(void);
WEAK void MEDIA_DCIF_CH2_IRQHandler(void);
WEAK void MEDIA_DCIF_CH3_IRQHandler(void);
WEAK void MEDIA_DCIF_CH4_IRQHandler(void);
WEAK void MEDIA_DCIF_CH5_IRQHandler(void);
WEAK void MEDIA_DCIF_CH6_IRQHandler(void);
WEAK void MEDIA_DCIF_CH7_IRQHandler(void);
WEAK void MEDIA_DCIF_CH8_IRQHandler(void);
WEAK void MEDIA_CSI_IRQHandler(void);
WEAK void MEDIA_REFORMATTER_IRQHandler(void);
WEAK void MEDIA_ISI_IRQHandler(void);
WEAK void MEDIA_TINGPU_IRQHandler(void);
WEAK void MEDIA_JPEGDEC_IRQHandler(void);
WEAK void MEDIA_MIPI_CSI_IRQHandler(void);
WEAK void MEDIA_MIPI_DSI_IRQHandler(void);
WEAK void MEDIA_FREQME_IRQHandler(void);

//*****************************************************************************
// Section 5: IRQ function implementations
//*****************************************************************************
void CMPT_CM85_CTI_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved17_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved18_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMPT_CM85_ECC_ERROR_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved20_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved21_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMPT_CM85_MCM_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMPT_TRDC_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved24_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMPT_SRAMCTL_0_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMPT_SRAMCTL_1_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMPT_SRAMCTL_2_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved28_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved29_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved30_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved31_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMPT_FREQME_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved33_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved34_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved35_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMPT_LLC_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved37_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved38_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved39_DriverIRQHandler(void) ALIAS(DefaultISR);
void CMPT_DAP_DriverIRQHandler(void) ALIAS(DefaultISR);
void MAIN_TRDC_DriverIRQHandler(void) ALIAS(DefaultISR);
void MAIN_AHB2AXI_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved43_DriverIRQHandler(void) ALIAS(DefaultISR);
void MAIN_MMU_DriverIRQHandler(void) ALIAS(DefaultISR);
void EDMA_DriverIRQHandler(uint32_t instance, uint32_t channel) ALIAS(DefaultISR2);
void MAIN_FREQME_DriverIRQHandler(void) ALIAS(DefaultISR);
void STM_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void Reserved95_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved96_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved97_DriverIRQHandler(void) ALIAS(DefaultISR);
void XSPI_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void Reserved100_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved101_DriverIRQHandler(void) ALIAS(DefaultISR);
void SYSCON_CGU_INT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void SYSCON_CGU_INT1_DriverIRQHandler(void) ALIAS(DefaultISR);
void SYSCON_CGU_INT2_DriverIRQHandler(void) ALIAS(DefaultISR);
void MAIN_CSSI_DriverIRQHandler(void) ALIAS(DefaultISR);
void MAIN_CSSI_SENTMU0A_DriverIRQHandler(void) ALIAS(DefaultISR);
void MAIN_CSSI_SENTMU1A_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved108_DriverIRQHandler(void) ALIAS(DefaultISR);
void SYSCON_PMU_INT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void SYSCON_PMU_INT1_DriverIRQHandler(void) ALIAS(DefaultISR);
void SYSCON_RESETCON_DriverIRQHandler(void) ALIAS(DefaultISR);
void SYSCON_FREQME_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved113_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved114_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved115_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_XBAR0_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_XBAR0_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_XBAR0_CH2_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_XBAR0_CH3_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_XBAR0_CH4_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_XBAR0_CH5_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_XBAR0_CH6_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_XBAR0_CH7_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved124_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved125_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved126_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved127_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_ADC0_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_ADC1_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_DAC_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_LPIT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_LPIT1_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM0_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM0_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM0_CH2_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM0_CH3_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM0_ERROR_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM1_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM1_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM1_CH2_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM1_CH3_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM1_ERROR_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM2_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM2_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM2_CH2_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM2_CH3_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM2_ERROR_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM3_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM3_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM3_CH2_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM3_CH3_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EFLEXPWM3_ERROR_DriverIRQHandler(void) ALIAS(DefaultISR);
void TPM_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void Reserved157_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved158_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved159_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved160_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved161_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved162_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved163_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved164_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_QTMR0_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_QTMR1_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_QTMR2_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_QTMR3_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EQDC0_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EQDC1_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EQDC2_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_EQDC3_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_SINC0_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_SINC0_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_SINC0_CH2_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_SINC0_CH3_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_SINC1_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_SINC1_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_SINC1_CH2_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_SINC1_CH3_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLEXCAN_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void HSP_FLEXCAN0_ERROR_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_FLEXCAN1_ERROR_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_FLEXCAN2_ERROR_DriverIRQHandler(void) ALIAS(DefaultISR);
void FLEXIO_CommonDriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void I3C_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void LPI2C_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void Reserved193_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved194_DriverIRQHandler(void) ALIAS(DefaultISR);
void LPSPI_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void LPUART_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void HSP_GPIO0_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_GPIO0_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_GPIO1_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_GPIO1_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_GPIO2_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_GPIO2_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_GPIO3_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_GPIO3_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_GPIO4_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void HSP_GPIO4_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved216_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved217_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved218_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved219_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved220_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_TRDC_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_XBAR_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_XBAR_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_ACMP0_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_ACMP1_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_ACMP2_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_ACMP3_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_EWM_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_FREQME_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_LPTMR0_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_LPTMR1_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_SWT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_SWT1_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved246_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved247_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved248_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved249_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_GPIO_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void WAKE_GPIO_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void PDM_EventHandleIRQ(uint32_t instance) ALIAS(DefaultISR1);
void PDM_ErrorHandleIRQ(uint32_t instance) ALIAS(DefaultISR1);
void PDM_HwvadEventHandleIRQ(uint32_t instance) ALIAS(DefaultISR1);
void PDM_HwvadErrorHandleIRQ(uint32_t instance) ALIAS(DefaultISR1);
void Reserved262_DriverIRQHandler(void) ALIAS(DefaultISR);
void VBAT_BBSM_INT0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved264_DriverIRQHandler(void) ALIAS(DefaultISR);
void VBAT_TDET_DriverIRQHandler(void) ALIAS(DefaultISR);
void VBAT_LPTMR_DriverIRQHandler(void) ALIAS(DefaultISR);
void VBAT_RTC_DriverIRQHandler(void) ALIAS(DefaultISR);
void VBAT_GPIO_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void VBAT_GPIO_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void VBAT_VBATCON_DriverIRQHandler(void) ALIAS(DefaultISR);
void AUDIO_TRDC_DriverIRQHandler(void) ALIAS(DefaultISR);
void SAI_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void Reserved275_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved276_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved277_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved280_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved281_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved282_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved283_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved284_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved285_DriverIRQHandler(void) ALIAS(DefaultISR);
void AUDIO_SPDIF_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved295_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved296_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved297_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved298_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved299_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved300_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved301_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved302_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved303_DriverIRQHandler(void) ALIAS(DefaultISR);
void ASRC_CommonDriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void AUDIO_FREQME_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved306_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved307_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved308_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved309_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved310_DriverIRQHandler(void) ALIAS(DefaultISR);
void COMM_TRDC_DriverIRQHandler(void) ALIAS(DefaultISR);
void COMM_ENET_QOS_DriverIRQHandler(void) ALIAS(DefaultISR);
void COMM_ENET_QOS_TX_DriverIRQHandler(void) ALIAS(DefaultISR);
void COMM_ENET_QOS_RX_DriverIRQHandler(void) ALIAS(DefaultISR);
void ENET_CommonFrame0DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void ENET_Ptp1588DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void FLEXSPI_SLV_CommonDriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void COMM_USB0_DriverIRQHandler(void) ALIAS(DefaultISR);
void COMM_USBPHY_DriverIRQHandler(void) ALIAS(DefaultISR);
void COMM_USB1_DriverIRQHandler(void) ALIAS(DefaultISR);
void USDHC_DriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void Reserved325_DriverIRQHandler(void) ALIAS(DefaultISR);
void COMM_TENBASET_PHY0_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved327_DriverIRQHandler(void) ALIAS(DefaultISR);
void COMM_TENBASET_PHY1_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved329_DriverIRQHandler(void) ALIAS(DefaultISR);
void COMM_FREQME_DriverIRQHandler(void) ALIAS(DefaultISR);
void MEDIA_TRDC_DriverIRQHandler(void) ALIAS(DefaultISR);
void Reserved332_DriverIRQHandler(void) ALIAS(DefaultISR);
void MEDIA_DCIF_CH0_DriverIRQHandler(void) ALIAS(DefaultISR);
void MEDIA_DCIF_CH1_DriverIRQHandler(void) ALIAS(DefaultISR);
void MEDIA_DCIF_CH2_DriverIRQHandler(void) ALIAS(DefaultISR);
void MEDIA_DCIF_CH3_DriverIRQHandler(void) ALIAS(DefaultISR);
void MEDIA_DCIF_CH4_DriverIRQHandler(void) ALIAS(DefaultISR);
void MEDIA_DCIF_CH5_DriverIRQHandler(void) ALIAS(DefaultISR);
void MEDIA_DCIF_CH6_DriverIRQHandler(void) ALIAS(DefaultISR);
void MEDIA_DCIF_CH7_DriverIRQHandler(void) ALIAS(DefaultISR);
void MEDIA_DCIF_CH8_DriverIRQHandler(void) ALIAS(DefaultISR);
void CSI_CommonDriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void MEDIA_REFORMATTER_DriverIRQHandler(void) ALIAS(DefaultISR);
void MEDIA_ISI_DriverIRQHandler(void) ALIAS(DefaultISR);
void MEDIA_TINGPU_DriverIRQHandler(void) ALIAS(DefaultISR);
void MEDIA_JPEGDEC_DriverIRQHandler(void) ALIAS(DefaultISR);
void MEDIA_MIPI_CSI_DriverIRQHandler(void) ALIAS(DefaultISR);
void MIPI_DSI_CommonDriverIRQHandler(uint32_t instance) ALIAS(DefaultISR1);
void MEDIA_FREQME_DriverIRQHandler(void) ALIAS(DefaultISR);

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

WEAK_AV void DefaultISR2(uint32_t instance, uint32_t channel)
{
    while (1)
    {
    }
}

WEAK_AV void DefaultISR1(uint32_t instance)
{
    while (1)
    {
    }
}

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

WEAK void CMPT_CM85_CTI_IRQHandler(void)
{
    CMPT_CM85_CTI_DriverIRQHandler();
}

WEAK void Reserved17_IRQHandler(void)
{
    Reserved17_DriverIRQHandler();
}

WEAK void Reserved18_IRQHandler(void)
{
    Reserved18_DriverIRQHandler();
}

WEAK void CMPT_CM85_ECC_ERROR_IRQHandler(void)
{
    CMPT_CM85_ECC_ERROR_DriverIRQHandler();
}

WEAK void Reserved20_IRQHandler(void)
{
    Reserved20_DriverIRQHandler();
}

WEAK void Reserved21_IRQHandler(void)
{
    Reserved21_DriverIRQHandler();
}

WEAK void CMPT_CM85_MCM_IRQHandler(void)
{
    CMPT_CM85_MCM_DriverIRQHandler();
}

WEAK void CMPT_TRDC_IRQHandler(void)
{
    CMPT_TRDC_DriverIRQHandler();
}

WEAK void Reserved24_IRQHandler(void)
{
    Reserved24_DriverIRQHandler();
}

WEAK void CMPT_SRAMCTL_0_IRQHandler(void)
{
    CMPT_SRAMCTL_0_DriverIRQHandler();
}

WEAK void CMPT_SRAMCTL_1_IRQHandler(void)
{
    CMPT_SRAMCTL_1_DriverIRQHandler();
}

WEAK void CMPT_SRAMCTL_2_IRQHandler(void)
{
    CMPT_SRAMCTL_2_DriverIRQHandler();
}

WEAK void Reserved28_IRQHandler(void)
{
    Reserved28_DriverIRQHandler();
}

WEAK void Reserved29_IRQHandler(void)
{
    Reserved29_DriverIRQHandler();
}

WEAK void Reserved30_IRQHandler(void)
{
    Reserved30_DriverIRQHandler();
}

WEAK void Reserved31_IRQHandler(void)
{
    Reserved31_DriverIRQHandler();
}

WEAK void CMPT_FREQME_IRQHandler(void)
{
    CMPT_FREQME_DriverIRQHandler();
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

WEAK void CMPT_LLC_IRQHandler(void)
{
    CMPT_LLC_DriverIRQHandler();
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

WEAK void CMPT_DAP_IRQHandler(void)
{
    CMPT_DAP_DriverIRQHandler();
}

WEAK void MAIN_TRDC_IRQHandler(void)
{
    MAIN_TRDC_DriverIRQHandler();
}

WEAK void MAIN_AHB2AXI_IRQHandler(void)
{
    MAIN_AHB2AXI_DriverIRQHandler();
}

WEAK void Reserved43_IRQHandler(void)
{
    Reserved43_DriverIRQHandler();
}

WEAK void MAIN_MMU_IRQHandler(void)
{
    MAIN_MMU_DriverIRQHandler();
}

WEAK void MAIN_EDMA3_CH0_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 0U);
}

WEAK void MAIN_EDMA3_CH1_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 1U);
}

WEAK void MAIN_EDMA3_CH2_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 2U);
}

WEAK void MAIN_EDMA3_CH3_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 3U);
}

WEAK void MAIN_EDMA3_CH4_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 4U);
}

WEAK void MAIN_EDMA3_CH5_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 5U);
}

WEAK void MAIN_EDMA3_CH6_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 6U);
}

WEAK void MAIN_EDMA3_CH7_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 7U);
}

WEAK void MAIN_EDMA3_CH8_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 8U);
}

WEAK void MAIN_EDMA3_CH9_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 9U);
}

WEAK void MAIN_EDMA3_CH10_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 10U);
}

WEAK void MAIN_EDMA3_CH11_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 11U);
}

WEAK void MAIN_EDMA3_CH12_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 12U);
}

WEAK void MAIN_EDMA3_CH13_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 13U);
}

WEAK void MAIN_EDMA3_CH14_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 14U);
}

WEAK void MAIN_EDMA3_CH15_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 15U);
}

WEAK void MAIN_EDMA3_CH16_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 16U);
}

WEAK void MAIN_EDMA3_CH17_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 17U);
}

WEAK void MAIN_EDMA3_CH18_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 18U);
}

WEAK void MAIN_EDMA3_CH19_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 19U);
}

WEAK void MAIN_EDMA3_CH20_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 20U);
}

WEAK void MAIN_EDMA3_CH21_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 21U);
}

WEAK void MAIN_EDMA3_CH22_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 22U);
}

WEAK void MAIN_EDMA3_CH23_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 23U);
}

WEAK void MAIN_EDMA3_CH24_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 24U);
}

WEAK void MAIN_EDMA3_CH25_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 25U);
}

WEAK void MAIN_EDMA3_CH26_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 26U);
}

WEAK void MAIN_EDMA3_CH27_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 27U);
}

WEAK void MAIN_EDMA3_CH28_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 28U);
}

WEAK void MAIN_EDMA3_CH29_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 29U);
}

WEAK void MAIN_EDMA3_CH30_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 30U);
}

WEAK void MAIN_EDMA3_CH31_IRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 31U);
}

WEAK void MAIN_EDMA5_CH0_IRQHandler(void)
{
    EDMA_DriverIRQHandler(1U, 0U);
}

WEAK void MAIN_EDMA5_CH1_IRQHandler(void)
{
    EDMA_DriverIRQHandler(1U, 1U);
}

WEAK void MAIN_EDMA5_CH2_IRQHandler(void)
{
    EDMA_DriverIRQHandler(1U, 2U);
}

WEAK void MAIN_EDMA5_CH3_IRQHandler(void)
{
    EDMA_DriverIRQHandler(1U, 3U);
}

WEAK void MAIN_EDMA5_CH4_IRQHandler(void)
{
    EDMA_DriverIRQHandler(1U, 4U);
}

WEAK void MAIN_EDMA5_CH5_IRQHandler(void)
{
    EDMA_DriverIRQHandler(1U, 5U);
}

WEAK void MAIN_EDMA5_CH6_IRQHandler(void)
{
    EDMA_DriverIRQHandler(1U, 6U);
}

WEAK void MAIN_EDMA5_CH7_IRQHandler(void)
{
    EDMA_DriverIRQHandler(1U, 7U);
}

WEAK void MAIN_EDMA5_CH8_IRQHandler(void)
{
    EDMA_DriverIRQHandler(1U, 8U);
}

WEAK void MAIN_EDMA5_CH9_IRQHandler(void)
{
    EDMA_DriverIRQHandler(1U, 9U);
}

WEAK void MAIN_EDMA5_CH10_IRQHandler(void)
{
    EDMA_DriverIRQHandler(1U, 10U);
}

WEAK void MAIN_EDMA5_CH11_IRQHandler(void)
{
    EDMA_DriverIRQHandler(1U, 11U);
}

WEAK void MAIN_EDMA5_CH12_IRQHandler(void)
{
    EDMA_DriverIRQHandler(1U, 12U);
}

WEAK void MAIN_EDMA5_CH13_IRQHandler(void)
{
    EDMA_DriverIRQHandler(1U, 13U);
}

WEAK void MAIN_EDMA5_CH14_IRQHandler(void)
{
    EDMA_DriverIRQHandler(1U, 14U);
}

WEAK void MAIN_EDMA5_CH15_IRQHandler(void)
{
    EDMA_DriverIRQHandler(1U, 15U);
}

WEAK void MAIN_FREQME_IRQHandler(void)
{
    MAIN_FREQME_DriverIRQHandler();
}

WEAK void HSP_STM_IRQHandler(void)
{
    STM_DriverIRQHandler(0U);
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

WEAK void MAIN_XSPI0_IRQHandler(void)
{
    XSPI_DriverIRQHandler(0U);
}

WEAK void MAIN_XSPI1_IRQHandler(void)
{
    XSPI_DriverIRQHandler(1U);
}

WEAK void Reserved100_IRQHandler(void)
{
    Reserved100_DriverIRQHandler();
}

WEAK void Reserved101_IRQHandler(void)
{
    Reserved101_DriverIRQHandler();
}

WEAK void SYSCON_CGU_INT0_IRQHandler(void)
{
    SYSCON_CGU_INT0_DriverIRQHandler();
}

WEAK void SYSCON_CGU_INT1_IRQHandler(void)
{
    SYSCON_CGU_INT1_DriverIRQHandler();
}

WEAK void SYSCON_CGU_INT2_IRQHandler(void)
{
    SYSCON_CGU_INT2_DriverIRQHandler();
}

WEAK void MAIN_CSSI_IRQHandler(void)
{
    MAIN_CSSI_DriverIRQHandler();
}

WEAK void MAIN_CSSI_SENTMU0A_IRQHandler(void)
{
    MAIN_CSSI_SENTMU0A_DriverIRQHandler();
}

WEAK void MAIN_CSSI_SENTMU1A_IRQHandler(void)
{
    MAIN_CSSI_SENTMU1A_DriverIRQHandler();
}

WEAK void Reserved108_IRQHandler(void)
{
    Reserved108_DriverIRQHandler();
}

WEAK void SYSCON_PMU_INT0_IRQHandler(void)
{
    SYSCON_PMU_INT0_DriverIRQHandler();
}

WEAK void SYSCON_PMU_INT1_IRQHandler(void)
{
    SYSCON_PMU_INT1_DriverIRQHandler();
}

WEAK void SYSCON_RESETCON_IRQHandler(void)
{
    SYSCON_RESETCON_DriverIRQHandler();
}

WEAK void SYSCON_FREQME_IRQHandler(void)
{
    SYSCON_FREQME_DriverIRQHandler();
}

WEAK void Reserved113_IRQHandler(void)
{
    Reserved113_DriverIRQHandler();
}

WEAK void Reserved114_IRQHandler(void)
{
    Reserved114_DriverIRQHandler();
}

WEAK void Reserved115_IRQHandler(void)
{
    Reserved115_DriverIRQHandler();
}

WEAK void HSP_XBAR0_CH0_IRQHandler(void)
{
    HSP_XBAR0_CH0_DriverIRQHandler();
}

WEAK void HSP_XBAR0_CH1_IRQHandler(void)
{
    HSP_XBAR0_CH1_DriverIRQHandler();
}

WEAK void HSP_XBAR0_CH2_IRQHandler(void)
{
    HSP_XBAR0_CH2_DriverIRQHandler();
}

WEAK void HSP_XBAR0_CH3_IRQHandler(void)
{
    HSP_XBAR0_CH3_DriverIRQHandler();
}

WEAK void HSP_XBAR0_CH4_IRQHandler(void)
{
    HSP_XBAR0_CH4_DriverIRQHandler();
}

WEAK void HSP_XBAR0_CH5_IRQHandler(void)
{
    HSP_XBAR0_CH5_DriverIRQHandler();
}

WEAK void HSP_XBAR0_CH6_IRQHandler(void)
{
    HSP_XBAR0_CH6_DriverIRQHandler();
}

WEAK void HSP_XBAR0_CH7_IRQHandler(void)
{
    HSP_XBAR0_CH7_DriverIRQHandler();
}

WEAK void Reserved124_IRQHandler(void)
{
    Reserved124_DriverIRQHandler();
}

WEAK void Reserved125_IRQHandler(void)
{
    Reserved125_DriverIRQHandler();
}

WEAK void Reserved126_IRQHandler(void)
{
    Reserved126_DriverIRQHandler();
}

WEAK void Reserved127_IRQHandler(void)
{
    Reserved127_DriverIRQHandler();
}

WEAK void HSP_ADC0_IRQHandler(void)
{
    HSP_ADC0_DriverIRQHandler();
}

WEAK void HSP_ADC1_IRQHandler(void)
{
    HSP_ADC1_DriverIRQHandler();
}

WEAK void HSP_DAC_IRQHandler(void)
{
    HSP_DAC_DriverIRQHandler();
}

WEAK void HSP_LPIT0_IRQHandler(void)
{
    HSP_LPIT0_DriverIRQHandler();
}

WEAK void HSP_LPIT1_IRQHandler(void)
{
    HSP_LPIT1_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM0_CH0_IRQHandler(void)
{
    HSP_EFLEXPWM0_CH0_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM0_CH1_IRQHandler(void)
{
    HSP_EFLEXPWM0_CH1_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM0_CH2_IRQHandler(void)
{
    HSP_EFLEXPWM0_CH2_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM0_CH3_IRQHandler(void)
{
    HSP_EFLEXPWM0_CH3_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM0_ERROR_IRQHandler(void)
{
    HSP_EFLEXPWM0_ERROR_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM1_CH0_IRQHandler(void)
{
    HSP_EFLEXPWM1_CH0_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM1_CH1_IRQHandler(void)
{
    HSP_EFLEXPWM1_CH1_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM1_CH2_IRQHandler(void)
{
    HSP_EFLEXPWM1_CH2_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM1_CH3_IRQHandler(void)
{
    HSP_EFLEXPWM1_CH3_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM1_ERROR_IRQHandler(void)
{
    HSP_EFLEXPWM1_ERROR_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM2_CH0_IRQHandler(void)
{
    HSP_EFLEXPWM2_CH0_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM2_CH1_IRQHandler(void)
{
    HSP_EFLEXPWM2_CH1_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM2_CH2_IRQHandler(void)
{
    HSP_EFLEXPWM2_CH2_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM2_CH3_IRQHandler(void)
{
    HSP_EFLEXPWM2_CH3_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM2_ERROR_IRQHandler(void)
{
    HSP_EFLEXPWM2_ERROR_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM3_CH0_IRQHandler(void)
{
    HSP_EFLEXPWM3_CH0_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM3_CH1_IRQHandler(void)
{
    HSP_EFLEXPWM3_CH1_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM3_CH2_IRQHandler(void)
{
    HSP_EFLEXPWM3_CH2_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM3_CH3_IRQHandler(void)
{
    HSP_EFLEXPWM3_CH3_DriverIRQHandler();
}

WEAK void HSP_EFLEXPWM3_ERROR_IRQHandler(void)
{
    HSP_EFLEXPWM3_ERROR_DriverIRQHandler();
}

WEAK void HSP_QTPM0_IRQHandler(void)
{
    TPM_DriverIRQHandler(0U);
}

WEAK void HSP_QTPM1_IRQHandler(void)
{
    TPM_DriverIRQHandler(1U);
}

WEAK void HSP_QTPM2_IRQHandler(void)
{
    TPM_DriverIRQHandler(2U);
}

WEAK void HSP_QTPM3_IRQHandler(void)
{
    TPM_DriverIRQHandler(3U);
}

WEAK void Reserved157_IRQHandler(void)
{
    Reserved157_DriverIRQHandler();
}

WEAK void Reserved158_IRQHandler(void)
{
    Reserved158_DriverIRQHandler();
}

WEAK void Reserved159_IRQHandler(void)
{
    Reserved159_DriverIRQHandler();
}

WEAK void Reserved160_IRQHandler(void)
{
    Reserved160_DriverIRQHandler();
}

WEAK void Reserved161_IRQHandler(void)
{
    Reserved161_DriverIRQHandler();
}

WEAK void Reserved162_IRQHandler(void)
{
    Reserved162_DriverIRQHandler();
}

WEAK void Reserved163_IRQHandler(void)
{
    Reserved163_DriverIRQHandler();
}

WEAK void Reserved164_IRQHandler(void)
{
    Reserved164_DriverIRQHandler();
}

WEAK void HSP_QTMR0_IRQHandler(void)
{
    HSP_QTMR0_DriverIRQHandler();
}

WEAK void HSP_QTMR1_IRQHandler(void)
{
    HSP_QTMR1_DriverIRQHandler();
}

WEAK void HSP_QTMR2_IRQHandler(void)
{
    HSP_QTMR2_DriverIRQHandler();
}

WEAK void HSP_QTMR3_IRQHandler(void)
{
    HSP_QTMR3_DriverIRQHandler();
}

WEAK void HSP_EQDC0_IRQHandler(void)
{
    HSP_EQDC0_DriverIRQHandler();
}

WEAK void HSP_EQDC1_IRQHandler(void)
{
    HSP_EQDC1_DriverIRQHandler();
}

WEAK void HSP_EQDC2_IRQHandler(void)
{
    HSP_EQDC2_DriverIRQHandler();
}

WEAK void HSP_EQDC3_IRQHandler(void)
{
    HSP_EQDC3_DriverIRQHandler();
}

WEAK void HSP_SINC0_CH0_IRQHandler(void)
{
    HSP_SINC0_CH0_DriverIRQHandler();
}

WEAK void HSP_SINC0_CH1_IRQHandler(void)
{
    HSP_SINC0_CH1_DriverIRQHandler();
}

WEAK void HSP_SINC0_CH2_IRQHandler(void)
{
    HSP_SINC0_CH2_DriverIRQHandler();
}

WEAK void HSP_SINC0_CH3_IRQHandler(void)
{
    HSP_SINC0_CH3_DriverIRQHandler();
}

WEAK void HSP_SINC1_CH0_IRQHandler(void)
{
    HSP_SINC1_CH0_DriverIRQHandler();
}

WEAK void HSP_SINC1_CH1_IRQHandler(void)
{
    HSP_SINC1_CH1_DriverIRQHandler();
}

WEAK void HSP_SINC1_CH2_IRQHandler(void)
{
    HSP_SINC1_CH2_DriverIRQHandler();
}

WEAK void HSP_SINC1_CH3_IRQHandler(void)
{
    HSP_SINC1_CH3_DriverIRQHandler();
}

WEAK void HSP_FLEXCAN0_IRQHandler(void)
{
    FLEXCAN_DriverIRQHandler(0U);
}

WEAK void HSP_FLEXCAN0_ERROR_IRQHandler(void)
{
    HSP_FLEXCAN0_ERROR_DriverIRQHandler();
}

WEAK void HSP_FLEXCAN1_IRQHandler(void)
{
    FLEXCAN_DriverIRQHandler(1U);
}

WEAK void HSP_FLEXCAN1_ERROR_IRQHandler(void)
{
    HSP_FLEXCAN1_ERROR_DriverIRQHandler();
}

WEAK void HSP_FLEXCAN2_IRQHandler(void)
{
    FLEXCAN_DriverIRQHandler(2U);
}

WEAK void HSP_FLEXCAN2_ERROR_IRQHandler(void)
{
    HSP_FLEXCAN2_ERROR_DriverIRQHandler();
}

WEAK void HSP_FLEXIO0_IRQHandler(void)
{
    FLEXIO_CommonDriverIRQHandler(0U);
}

WEAK void HSP_FLEXIO1_IRQHandler(void)
{
    FLEXIO_CommonDriverIRQHandler(1U);
}

WEAK void HSP_FLEXIO2_IRQHandler(void)
{
    FLEXIO_CommonDriverIRQHandler(2U);
}

WEAK void HSP_I3C_IRQHandler(void)
{
    I3C_DriverIRQHandler(0U);
}

WEAK void HSP_LPI2C0_IRQHandler(void)
{
    LPI2C_DriverIRQHandler(0U);
}

WEAK void HSP_LPI2C1_IRQHandler(void)
{
    LPI2C_DriverIRQHandler(1U);
}

WEAK void Reserved193_IRQHandler(void)
{
    Reserved193_DriverIRQHandler();
}

WEAK void Reserved194_IRQHandler(void)
{
    Reserved194_DriverIRQHandler();
}

WEAK void HSP_LPSPI0_IRQHandler(void)
{
    LPSPI_DriverIRQHandler(0U);
}

WEAK void HSP_LPSPI1_IRQHandler(void)
{
    LPSPI_DriverIRQHandler(1U);
}

WEAK void HSP_LPSPI2_IRQHandler(void)
{
    LPSPI_DriverIRQHandler(2U);
}

WEAK void HSP_LPSPI3_IRQHandler(void)
{
    LPSPI_DriverIRQHandler(3U);
}

WEAK void HSP_LPSPI4_IRQHandler(void)
{
    LPSPI_DriverIRQHandler(4U);
}

WEAK void HSP_LPUART0_IRQHandler(void)
{
    LPUART_DriverIRQHandler(0U);
}

WEAK void HSP_LPUART1_IRQHandler(void)
{
    LPUART_DriverIRQHandler(1U);
}

WEAK void HSP_LPUART2_IRQHandler(void)
{
    LPUART_DriverIRQHandler(2U);
}

WEAK void HSP_LPUART3_IRQHandler(void)
{
    LPUART_DriverIRQHandler(3U);
}

WEAK void HSP_LPUART4_IRQHandler(void)
{
    LPUART_DriverIRQHandler(4U);
}

WEAK void HSP_LPUART5_IRQHandler(void)
{
    LPUART_DriverIRQHandler(5U);
}

WEAK void HSP_GPIO0_CH0_IRQHandler(void)
{
    HSP_GPIO0_CH0_DriverIRQHandler();
}

WEAK void HSP_GPIO0_CH1_IRQHandler(void)
{
    HSP_GPIO0_CH1_DriverIRQHandler();
}

WEAK void HSP_GPIO1_CH0_IRQHandler(void)
{
    HSP_GPIO1_CH0_DriverIRQHandler();
}

WEAK void HSP_GPIO1_CH1_IRQHandler(void)
{
    HSP_GPIO1_CH1_DriverIRQHandler();
}

WEAK void HSP_GPIO2_CH0_IRQHandler(void)
{
    HSP_GPIO2_CH0_DriverIRQHandler();
}

WEAK void HSP_GPIO2_CH1_IRQHandler(void)
{
    HSP_GPIO2_CH1_DriverIRQHandler();
}

WEAK void HSP_GPIO3_CH0_IRQHandler(void)
{
    HSP_GPIO3_CH0_DriverIRQHandler();
}

WEAK void HSP_GPIO3_CH1_IRQHandler(void)
{
    HSP_GPIO3_CH1_DriverIRQHandler();
}

WEAK void HSP_GPIO4_CH0_IRQHandler(void)
{
    HSP_GPIO4_CH0_DriverIRQHandler();
}

WEAK void HSP_GPIO4_CH1_IRQHandler(void)
{
    HSP_GPIO4_CH1_DriverIRQHandler();
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

WEAK void WAKE_TRDC_IRQHandler(void)
{
    WAKE_TRDC_DriverIRQHandler();
}

WEAK void WAKE_XBAR_CH0_IRQHandler(void)
{
    WAKE_XBAR_CH0_DriverIRQHandler();
}

WEAK void WAKE_XBAR_CH1_IRQHandler(void)
{
    WAKE_XBAR_CH1_DriverIRQHandler();
}

WEAK void WAKE_EDMA3_CH0_IRQHandler(void)
{
    EDMA_DriverIRQHandler(3U, 0U);
}

WEAK void WAKE_EDMA3_CH1_IRQHandler(void)
{
    EDMA_DriverIRQHandler(3U, 1U);
}

WEAK void WAKE_EDMA3_CH2_IRQHandler(void)
{
    EDMA_DriverIRQHandler(3U, 2U);
}

WEAK void WAKE_EDMA3_CH3_IRQHandler(void)
{
    EDMA_DriverIRQHandler(3U, 3U);
}

WEAK void WAKE_EDMA3_CH4_IRQHandler(void)
{
    EDMA_DriverIRQHandler(3U, 4U);
}

WEAK void WAKE_EDMA3_CH5_IRQHandler(void)
{
    EDMA_DriverIRQHandler(3U, 5U);
}

WEAK void WAKE_EDMA3_CH6_IRQHandler(void)
{
    EDMA_DriverIRQHandler(3U, 6U);
}

WEAK void WAKE_EDMA3_CH7_IRQHandler(void)
{
    EDMA_DriverIRQHandler(3U, 7U);
}

WEAK void WAKE_ACMP0_IRQHandler(void)
{
    WAKE_ACMP0_DriverIRQHandler();
}

WEAK void WAKE_ACMP1_IRQHandler(void)
{
    WAKE_ACMP1_DriverIRQHandler();
}

WEAK void WAKE_ACMP2_IRQHandler(void)
{
    WAKE_ACMP2_DriverIRQHandler();
}

WEAK void WAKE_ACMP3_IRQHandler(void)
{
    WAKE_ACMP3_DriverIRQHandler();
}

WEAK void WAKE_EWM_IRQHandler(void)
{
    WAKE_EWM_DriverIRQHandler();
}

WEAK void WAKE_FREQME_IRQHandler(void)
{
    WAKE_FREQME_DriverIRQHandler();
}

WEAK void WAKE_LPTMR0_IRQHandler(void)
{
    WAKE_LPTMR0_DriverIRQHandler();
}

WEAK void WAKE_LPTMR1_IRQHandler(void)
{
    WAKE_LPTMR1_DriverIRQHandler();
}

WEAK void WAKE_QTPM0_IRQHandler(void)
{
    TPM_DriverIRQHandler(4U);
}

WEAK void WAKE_QTPM1_IRQHandler(void)
{
    TPM_DriverIRQHandler(5U);
}

WEAK void WAKE_QTPM2_IRQHandler(void)
{
    TPM_DriverIRQHandler(6U);
}

WEAK void WAKE_QTPM3_IRQHandler(void)
{
    TPM_DriverIRQHandler(7U);
}

WEAK void WAKE_SWT0_IRQHandler(void)
{
    WAKE_SWT0_DriverIRQHandler();
}

WEAK void WAKE_SWT1_IRQHandler(void)
{
    WAKE_SWT1_DriverIRQHandler();
}

WEAK void Reserved246_IRQHandler(void)
{
    Reserved246_DriverIRQHandler();
}

WEAK void Reserved247_IRQHandler(void)
{
    Reserved247_DriverIRQHandler();
}

WEAK void Reserved248_IRQHandler(void)
{
    Reserved248_DriverIRQHandler();
}

WEAK void Reserved249_IRQHandler(void)
{
    Reserved249_DriverIRQHandler();
}

WEAK void WAKE_I3C_IRQHandler(void)
{
    I3C_DriverIRQHandler(1U);
}

WEAK void WAKE_LPI2C0_IRQHandler(void)
{
    LPI2C_DriverIRQHandler(2U);
}

WEAK void WAKE_LPI2C1_IRQHandler(void)
{
    LPI2C_DriverIRQHandler(3U);
}

WEAK void WAKE_LPSPI_IRQHandler(void)
{
    LPSPI_DriverIRQHandler(5U);
}

WEAK void WAKE_LPUART0_IRQHandler(void)
{
    LPUART_DriverIRQHandler(6U);
}

WEAK void WAKE_LPUART1_IRQHandler(void)
{
    LPUART_DriverIRQHandler(7U);
}

WEAK void WAKE_GPIO_CH0_IRQHandler(void)
{
    WAKE_GPIO_CH0_DriverIRQHandler();
}

WEAK void WAKE_GPIO_CH1_IRQHandler(void)
{
    WAKE_GPIO_CH1_DriverIRQHandler();
}

WEAK void WAKE_PDM_EVENT_IRQHandler(void)
{
    PDM_EventHandleIRQ(1U);
}

WEAK void WAKE_PDM_ERROR_IRQHandler(void)
{
    PDM_ErrorHandleIRQ(1U);
}

WEAK void WAKE_PDM_HWVAD_EVENT_IRQHandler(void)
{
    PDM_HwvadEventHandleIRQ(1U);
}

WEAK void WAKE_PDM_HWVAD_ERROR_IRQHandler(void)
{
    PDM_HwvadErrorHandleIRQ(1U);
}

WEAK void Reserved262_IRQHandler(void)
{
    Reserved262_DriverIRQHandler();
}

WEAK void VBAT_BBSM_INT0_IRQHandler(void)
{
    VBAT_BBSM_INT0_DriverIRQHandler();
}

WEAK void Reserved264_IRQHandler(void)
{
    Reserved264_DriverIRQHandler();
}

WEAK void VBAT_TDET_IRQHandler(void)
{
    VBAT_TDET_DriverIRQHandler();
}

WEAK void VBAT_LPTMR_IRQHandler(void)
{
    VBAT_LPTMR_DriverIRQHandler();
}

WEAK void VBAT_RTC_IRQHandler(void)
{
    VBAT_RTC_DriverIRQHandler();
}

WEAK void VBAT_GPIO_CH0_IRQHandler(void)
{
    VBAT_GPIO_CH0_DriverIRQHandler();
}

WEAK void VBAT_GPIO_CH1_IRQHandler(void)
{
    VBAT_GPIO_CH1_DriverIRQHandler();
}

WEAK void VBAT_VBATCON_IRQHandler(void)
{
    VBAT_VBATCON_DriverIRQHandler();
}

WEAK void AUDIO_TRDC_IRQHandler(void)
{
    AUDIO_TRDC_DriverIRQHandler();
}

WEAK void AUDIO_SAI0_IRQHandler(void)
{
    SAI_DriverIRQHandler(0U);
}

WEAK void AUDIO_SAI1_IRQHandler(void)
{
    SAI_DriverIRQHandler(1U);
}

WEAK void AUDIO_SAI2_IRQHandler(void)
{
    SAI_DriverIRQHandler(2U);
}

WEAK void Reserved275_IRQHandler(void)
{
    Reserved275_DriverIRQHandler();
}

WEAK void Reserved276_IRQHandler(void)
{
    Reserved276_DriverIRQHandler();
}

WEAK void Reserved277_IRQHandler(void)
{
    Reserved277_DriverIRQHandler();
}

WEAK void AUDIO_PDM_EVENT_IRQHandler(void)
{
    PDM_EventHandleIRQ(0U);
}

WEAK void AUDIO_PDM_ERROR_IRQHandler(void)
{
    PDM_ErrorHandleIRQ(0U);
}

WEAK void Reserved280_IRQHandler(void)
{
    Reserved280_DriverIRQHandler();
}

WEAK void Reserved281_IRQHandler(void)
{
    Reserved281_DriverIRQHandler();
}

WEAK void Reserved282_IRQHandler(void)
{
    Reserved282_DriverIRQHandler();
}

WEAK void Reserved283_IRQHandler(void)
{
    Reserved283_DriverIRQHandler();
}

WEAK void Reserved284_IRQHandler(void)
{
    Reserved284_DriverIRQHandler();
}

WEAK void Reserved285_IRQHandler(void)
{
    Reserved285_DriverIRQHandler();
}

WEAK void AUDIO_SPDIF_IRQHandler(void)
{
    AUDIO_SPDIF_DriverIRQHandler();
}

WEAK void AUDIO_EDMA3_CH0_IRQHandler(void)
{
    EDMA_DriverIRQHandler(2U, 0U);
}

WEAK void AUDIO_EDMA3_CH1_IRQHandler(void)
{
    EDMA_DriverIRQHandler(2U, 1U);
}

WEAK void AUDIO_EDMA3_CH2_IRQHandler(void)
{
    EDMA_DriverIRQHandler(2U, 2U);
}

WEAK void AUDIO_EDMA3_CH3_IRQHandler(void)
{
    EDMA_DriverIRQHandler(2U, 3U);
}

WEAK void AUDIO_EDMA3_CH4_IRQHandler(void)
{
    EDMA_DriverIRQHandler(2U, 4U);
}

WEAK void AUDIO_EDMA3_CH5_IRQHandler(void)
{
    EDMA_DriverIRQHandler(2U, 5U);
}

WEAK void AUDIO_EDMA3_CH6_IRQHandler(void)
{
    EDMA_DriverIRQHandler(2U, 6U);
}

WEAK void AUDIO_EDMA3_CH7_IRQHandler(void)
{
    EDMA_DriverIRQHandler(2U, 7U);
}

WEAK void Reserved295_IRQHandler(void)
{
    Reserved295_DriverIRQHandler();
}

WEAK void Reserved296_IRQHandler(void)
{
    Reserved296_DriverIRQHandler();
}

WEAK void Reserved297_IRQHandler(void)
{
    Reserved297_DriverIRQHandler();
}

WEAK void Reserved298_IRQHandler(void)
{
    Reserved298_DriverIRQHandler();
}

WEAK void Reserved299_IRQHandler(void)
{
    Reserved299_DriverIRQHandler();
}

WEAK void Reserved300_IRQHandler(void)
{
    Reserved300_DriverIRQHandler();
}

WEAK void Reserved301_IRQHandler(void)
{
    Reserved301_DriverIRQHandler();
}

WEAK void Reserved302_IRQHandler(void)
{
    Reserved302_DriverIRQHandler();
}

WEAK void Reserved303_IRQHandler(void)
{
    Reserved303_DriverIRQHandler();
}

WEAK void AUDIO_ASRC_IRQHandler(void)
{
    ASRC_CommonDriverIRQHandler(0U);
}

WEAK void AUDIO_FREQME_IRQHandler(void)
{
    AUDIO_FREQME_DriverIRQHandler();
}

WEAK void Reserved306_IRQHandler(void)
{
    Reserved306_DriverIRQHandler();
}

WEAK void Reserved307_IRQHandler(void)
{
    Reserved307_DriverIRQHandler();
}

WEAK void Reserved308_IRQHandler(void)
{
    Reserved308_DriverIRQHandler();
}

WEAK void Reserved309_IRQHandler(void)
{
    Reserved309_DriverIRQHandler();
}

WEAK void Reserved310_IRQHandler(void)
{
    Reserved310_DriverIRQHandler();
}

WEAK void COMM_TRDC_IRQHandler(void)
{
    COMM_TRDC_DriverIRQHandler();
}

WEAK void COMM_ENET_QOS_IRQHandler(void)
{
    COMM_ENET_QOS_DriverIRQHandler();
}

WEAK void COMM_ENET_QOS_TX_IRQHandler(void)
{
    COMM_ENET_QOS_TX_DriverIRQHandler();
}

WEAK void COMM_ENET_QOS_RX_IRQHandler(void)
{
    COMM_ENET_QOS_RX_DriverIRQHandler();
}

WEAK void COMM_ENET_TX_IRQHandler(void)
{
    ENET_CommonFrame0DriverIRQHandler(0U);
}

WEAK void COMM_ENET_RX_IRQHandler(void)
{
    ENET_CommonFrame0DriverIRQHandler(0U);
}

WEAK void COMM_ENET_OTHER_IRQHandler(void)
{
    ENET_CommonFrame0DriverIRQHandler(0U);
}

WEAK void COMM_ENET_1588_IRQHandler(void)
{
    ENET_Ptp1588DriverIRQHandler(0U);
}

WEAK void COMM_FLEXSPI_SLV_IRQHandler(void)
{
    FLEXSPI_SLV_CommonDriverIRQHandler(0U);
}

WEAK void COMM_USB0_IRQHandler(void)
{
    COMM_USB0_DriverIRQHandler();
}

WEAK void COMM_USBPHY_IRQHandler(void)
{
    COMM_USBPHY_DriverIRQHandler();
}

WEAK void COMM_USB1_IRQHandler(void)
{
    COMM_USB1_DriverIRQHandler();
}

WEAK void COMM_USDHC0_IRQHandler(void)
{
    USDHC_DriverIRQHandler(0U);
}

WEAK void COMM_USDHC1_IRQHandler(void)
{
    USDHC_DriverIRQHandler(1U);
}

WEAK void Reserved325_IRQHandler(void)
{
    Reserved325_DriverIRQHandler();
}

WEAK void COMM_TENBASET_PHY0_IRQHandler(void)
{
    COMM_TENBASET_PHY0_DriverIRQHandler();
}

WEAK void Reserved327_IRQHandler(void)
{
    Reserved327_DriverIRQHandler();
}

WEAK void COMM_TENBASET_PHY1_IRQHandler(void)
{
    COMM_TENBASET_PHY1_DriverIRQHandler();
}

WEAK void Reserved329_IRQHandler(void)
{
    Reserved329_DriverIRQHandler();
}

WEAK void COMM_FREQME_IRQHandler(void)
{
    COMM_FREQME_DriverIRQHandler();
}

WEAK void MEDIA_TRDC_IRQHandler(void)
{
    MEDIA_TRDC_DriverIRQHandler();
}

WEAK void Reserved332_IRQHandler(void)
{
    Reserved332_DriverIRQHandler();
}

WEAK void MEDIA_DCIF_CH0_IRQHandler(void)
{
    MEDIA_DCIF_CH0_DriverIRQHandler();
}

WEAK void MEDIA_DCIF_CH1_IRQHandler(void)
{
    MEDIA_DCIF_CH1_DriverIRQHandler();
}

WEAK void MEDIA_DCIF_CH2_IRQHandler(void)
{
    MEDIA_DCIF_CH2_DriverIRQHandler();
}

WEAK void MEDIA_DCIF_CH3_IRQHandler(void)
{
    MEDIA_DCIF_CH3_DriverIRQHandler();
}

WEAK void MEDIA_DCIF_CH4_IRQHandler(void)
{
    MEDIA_DCIF_CH4_DriverIRQHandler();
}

WEAK void MEDIA_DCIF_CH5_IRQHandler(void)
{
    MEDIA_DCIF_CH5_DriverIRQHandler();
}

WEAK void MEDIA_DCIF_CH6_IRQHandler(void)
{
    MEDIA_DCIF_CH6_DriverIRQHandler();
}

WEAK void MEDIA_DCIF_CH7_IRQHandler(void)
{
    MEDIA_DCIF_CH7_DriverIRQHandler();
}

WEAK void MEDIA_DCIF_CH8_IRQHandler(void)
{
    MEDIA_DCIF_CH8_DriverIRQHandler();
}

WEAK void MEDIA_CSI_IRQHandler(void)
{
    CSI_CommonDriverIRQHandler(0U);
}

WEAK void MEDIA_REFORMATTER_IRQHandler(void)
{
    MEDIA_REFORMATTER_DriverIRQHandler();
}

WEAK void MEDIA_ISI_IRQHandler(void)
{
    MEDIA_ISI_DriverIRQHandler();
}

WEAK void MEDIA_TINGPU_IRQHandler(void)
{
    MEDIA_TINGPU_DriverIRQHandler();
}

WEAK void MEDIA_JPEGDEC_IRQHandler(void)
{
    MEDIA_JPEGDEC_DriverIRQHandler();
}

WEAK void MEDIA_MIPI_CSI_IRQHandler(void)
{
    MEDIA_MIPI_CSI_DriverIRQHandler();
}

WEAK void MEDIA_MIPI_DSI_IRQHandler(void)
{
    MIPI_DSI_CommonDriverIRQHandler(0U);
}

WEAK void MEDIA_FREQME_IRQHandler(void)
{
    MEDIA_FREQME_DriverIRQHandler();
}

STARTUP_VT_SECTION
void (*const STARTUP_VT_SYMBOL[])(void) = {
    // Core Level - CM85
    (void (*)())((uint32_t)_vStackTop), // The initial stack pointer
    Reset_Handler,                      // The reset handler

    NMI_Handler,                        // NMI Handler
    HardFault_Handler,                  // Hard Fault Handler
    MemManage_Handler,                  // MPU Fault Handler
    BusFault_Handler,                   // Bus Fault Handler
    UsageFault_Handler,                 // Usage Fault Handler
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    SVC_Handler,                        // SVCall Handler
    DebugMon_Handler,                   // Debug Monitor Handler
    0,                                  // Reserved
    PendSV_Handler,                     // PendSV Handler
    SysTick_Handler,                    // SysTick Handler

    // Chip Level - MIMXRT2662_cm85
    CMPT_CM85_CTI_IRQHandler,        // 16 : CM85: Cti Interrupt Request 0/Cti Interrupt Request 1
    Reserved17_IRQHandler,           // 17 : Reserved interrupt
    Reserved18_IRQHandler,           // 18 : Reserved interrupt
    CMPT_CM85_ECC_ERROR_IRQHandler,  // 19 : CM85: Single / Multi Bit Ecc Error From L1$ Or Tcm
    Reserved20_IRQHandler,           // 20 : Reserved interrupt
    Reserved21_IRQHandler,           // 21 : Reserved interrupt
    CMPT_CM85_MCM_IRQHandler,        // 22 : CMPT CM85 MCM: Interrupt request
    CMPT_TRDC_IRQHandler,            // 23 : CMPT TRDC: Interrupt request
    Reserved24_IRQHandler,           // 24 : Reserved interrupt
    CMPT_SRAMCTL_0_IRQHandler,       // 25 : CMPT SRAMCTL0: Interrupt request
    CMPT_SRAMCTL_1_IRQHandler,       // 26 : CMPT SRAMCTL1: Interrupt request
    CMPT_SRAMCTL_2_IRQHandler,       // 27 : CMPT SRAMCTL2: Interrupt request
    Reserved28_IRQHandler,           // 28 : Reserved interrupt
    Reserved29_IRQHandler,           // 29 : Reserved interrupt
    Reserved30_IRQHandler,           // 30 : Reserved interrupt
    Reserved31_IRQHandler,           // 31 : Reserved interrupt
    CMPT_FREQME_IRQHandler,          // 32 : CMPT FREQME: Interrupt request
    Reserved33_IRQHandler,           // 33 : Reserved interrupt
    Reserved34_IRQHandler,           // 34 : Reserved interrupt
    Reserved35_IRQHandler,           // 35 : Reserved interrupt
    CMPT_LLC_IRQHandler,             // 36 : CMPT LLC: Interrupt request
    Reserved37_IRQHandler,           // 37 : Reserved interrupt
    Reserved38_IRQHandler,           // 38 : Reserved interrupt
    Reserved39_IRQHandler,           // 39 : Reserved interrupt
    CMPT_DAP_IRQHandler,             // 40 : CMPT DAP: Interrupt request
    MAIN_TRDC_IRQHandler,            // 41 : MAIN TRDC: Interrupt request
    MAIN_AHB2AXI_IRQHandler,         // 42 : XHB500: Interrupt On Error Response for a Buffered Or Early Terminated Write
    Reserved43_IRQHandler,           // 43 : Reserved interrupt
    MAIN_MMU_IRQHandler,             // 44 : MMU: Interrupt request
    MAIN_EDMA3_CH0_IRQHandler,       // 45 : MAIN EDMA3: Channel 0 interrupt
    MAIN_EDMA3_CH1_IRQHandler,       // 46 : MAIN EDMA3: Channel 1 interrupt
    MAIN_EDMA3_CH2_IRQHandler,       // 47 : MAIN EDMA3: Channel 2 interrupt
    MAIN_EDMA3_CH3_IRQHandler,       // 48 : MAIN EDMA3: Channel 3 interrupt
    MAIN_EDMA3_CH4_IRQHandler,       // 49 : MAIN EDMA3: Channel 4 interrupt
    MAIN_EDMA3_CH5_IRQHandler,       // 50 : MAIN EDMA3: Channel 5 interrupt
    MAIN_EDMA3_CH6_IRQHandler,       // 51 : MAIN EDMA3: Channel 6 interrupt
    MAIN_EDMA3_CH7_IRQHandler,       // 52 : MAIN EDMA3: Channel 7 interrupt
    MAIN_EDMA3_CH8_IRQHandler,       // 53 : MAIN EDMA3: Channel 8 interrupt
    MAIN_EDMA3_CH9_IRQHandler,       // 54 : MAIN EDMA3: Channel 9 interrupt
    MAIN_EDMA3_CH10_IRQHandler,      // 55 : MAIN EDMA3: Channel 10 interrupt
    MAIN_EDMA3_CH11_IRQHandler,      // 56 : MAIN EDMA3: Channel 11 interrupt
    MAIN_EDMA3_CH12_IRQHandler,      // 57 : MAIN EDMA3: Channel 12 interrupt
    MAIN_EDMA3_CH13_IRQHandler,      // 58 : MAIN EDMA3: Channel 13 interrupt
    MAIN_EDMA3_CH14_IRQHandler,      // 59 : MAIN EDMA3: Channel 14 interrupt
    MAIN_EDMA3_CH15_IRQHandler,      // 60 : MAIN EDMA3: Channel 15 interrupt
    MAIN_EDMA3_CH16_IRQHandler,      // 61 : MAIN EDMA3: Channel 16 interrupt
    MAIN_EDMA3_CH17_IRQHandler,      // 62 : MAIN EDMA3: Channel 17 interrupt
    MAIN_EDMA3_CH18_IRQHandler,      // 63 : MAIN EDMA3: Channel 18 interrupt
    MAIN_EDMA3_CH19_IRQHandler,      // 64 : MAIN EDMA3: Channel 19 interrupt
    MAIN_EDMA3_CH20_IRQHandler,      // 65 : MAIN EDMA3: Channel 20 interrupt
    MAIN_EDMA3_CH21_IRQHandler,      // 66 : MAIN EDMA3: Channel 21 interrupt
    MAIN_EDMA3_CH22_IRQHandler,      // 67 : MAIN EDMA3: Channel 22 interrupt
    MAIN_EDMA3_CH23_IRQHandler,      // 68 : MAIN EDMA3: Channel 23 interrupt
    MAIN_EDMA3_CH24_IRQHandler,      // 69 : MAIN EDMA3: Channel 24 interrupt
    MAIN_EDMA3_CH25_IRQHandler,      // 70 : MAIN EDMA3: Channel 25 interrupt
    MAIN_EDMA3_CH26_IRQHandler,      // 71 : MAIN EDMA3: Channel 26 interrupt
    MAIN_EDMA3_CH27_IRQHandler,      // 72 : MAIN EDMA3: Channel 27 interrupt
    MAIN_EDMA3_CH28_IRQHandler,      // 73 : MAIN EDMA3: Channel 28 interrupt
    MAIN_EDMA3_CH29_IRQHandler,      // 74 : MAIN EDMA3: Channel 29 interrupt
    MAIN_EDMA3_CH30_IRQHandler,      // 75 : MAIN EDMA3: Channel 30 interrupt
    MAIN_EDMA3_CH31_IRQHandler,      // 76 : MAIN EDMA3: Channel 31 interrupt
    MAIN_EDMA5_CH0_IRQHandler,       // 77 : MAIN EDMA5: Channel 0 interrupt
    MAIN_EDMA5_CH1_IRQHandler,       // 78 : MAIN EDMA5: Channel 1 interrupt
    MAIN_EDMA5_CH2_IRQHandler,       // 79 : MAIN EDMA5: Channel 2 interrupt
    MAIN_EDMA5_CH3_IRQHandler,       // 80 : MAIN EDMA5: Channel 3 interrupt
    MAIN_EDMA5_CH4_IRQHandler,       // 81 : MAIN EDMA5: Channel 4 interrupt
    MAIN_EDMA5_CH5_IRQHandler,       // 82 : MAIN EDMA5: Channel 5 interrupt
    MAIN_EDMA5_CH6_IRQHandler,       // 83 : MAIN EDMA5: Channel 6 interrupt
    MAIN_EDMA5_CH7_IRQHandler,       // 84 : MAIN EDMA5: Channel 7 interrupt
    MAIN_EDMA5_CH8_IRQHandler,       // 85 : MAIN EDMA5: Channel 8 interrupt
    MAIN_EDMA5_CH9_IRQHandler,       // 86 : MAIN EDMA5: Channel 9 interrupt
    MAIN_EDMA5_CH10_IRQHandler,      // 87 : MAIN EDMA5: Channel 10 interrupt
    MAIN_EDMA5_CH11_IRQHandler,      // 88 : MAIN EDMA5: Channel 11 interrupt
    MAIN_EDMA5_CH12_IRQHandler,      // 89 : MAIN EDMA5: Channel 12 interrupt
    MAIN_EDMA5_CH13_IRQHandler,      // 90 : MAIN EDMA5: Channel 13 interrupt
    MAIN_EDMA5_CH14_IRQHandler,      // 91 : MAIN EDMA5: Channel 14 interrupt
    MAIN_EDMA5_CH15_IRQHandler,      // 92 : MAIN EDMA5: Channel 15 interrupt
    MAIN_FREQME_IRQHandler,          // 93 : MAIN FREQME: interrupt request
    HSP_STM_IRQHandler,              // 94 : HSP STM: Interrupt request
    Reserved95_IRQHandler,           // 95 : Reserved interrupt
    Reserved96_IRQHandler,           // 96 : Reserved interrupt
    Reserved97_IRQHandler,           // 97 : Reserved interrupt
    MAIN_XSPI0_IRQHandler,           // 98 : MAIN XSPI0: interrupt request
    MAIN_XSPI1_IRQHandler,           // 99 : MAIN XSPI1: interrupt request
    Reserved100_IRQHandler,          // 100: Reserved interrupt
    Reserved101_IRQHandler,          // 101: Reserved interrupt
    SYSCON_CGU_INT0_IRQHandler,      // 102: CGU: Vdda 0V8 Status Interrupt
    SYSCON_CGU_INT1_IRQHandler,      // 103: CGU: Audiopll Dnum Update Done Interrupt
    SYSCON_CGU_INT2_IRQHandler,      // 104: CGU: Videopll Dnum Update Done Interrupt
    MAIN_CSSI_IRQHandler,            // 105: CSSI:Status/Error Interrupt/Active Interrupt
    MAIN_CSSI_SENTMU0A_IRQHandler,   // 106: CSSI_MU: MU0A Ored Tx Interrupt To Mua
    MAIN_CSSI_SENTMU1A_IRQHandler,   // 107: CSSI_MU: Mu1A Ored Tx Interrupt To Mua
    Reserved108_IRQHandler,          // 108: Reserved interrupt
    SYSCON_PMU_INT0_IRQHandler,      // 109: PMU: Ored All Sensor And Monitor Interrupts
    SYSCON_PMU_INT1_IRQHandler,      // 110: PMU: Body Bias Interrupt
    SYSCON_RESETCON_IRQHandler,      // 111: SYSCON RESETCON: Interrupt request
    SYSCON_FREQME_IRQHandler,        // 112: SYSCON FREQME: Interrupt request
    Reserved113_IRQHandler,          // 113: Reserved interrupt
    Reserved114_IRQHandler,          // 114: Reserved interrupt
    Reserved115_IRQHandler,          // 115: Reserved interrupt
    HSP_XBAR0_CH0_IRQHandler,        // 116: HSP XBAR0 Channel 0 interrupt
    HSP_XBAR0_CH1_IRQHandler,        // 117: HSP XBAR0 Channel 1 interrupt
    HSP_XBAR0_CH2_IRQHandler,        // 118: HSP XBAR0 Channel 2 interrupt
    HSP_XBAR0_CH3_IRQHandler,        // 119: HSP XBAR0 Channel 3 interrupt
    HSP_XBAR0_CH4_IRQHandler,        // 120: HSP XBAR0 Channel 4 interrupt
    HSP_XBAR0_CH5_IRQHandler,        // 121: HSP XBAR0 Channel 5 interrupt
    HSP_XBAR0_CH6_IRQHandler,        // 122: HSP XBAR0 Channel 6 interrupt
    HSP_XBAR0_CH7_IRQHandler,        // 123: HSP XBAR0 Channel 7 interrupt
    Reserved124_IRQHandler,          // 124: Reserved interrupt
    Reserved125_IRQHandler,          // 125: Reserved interrupt
    Reserved126_IRQHandler,          // 126: Reserved interrupt
    Reserved127_IRQHandler,          // 127: Reserved interrupt
    HSP_ADC0_IRQHandler,             // 128: HSP ADC0 interrupt
    HSP_ADC1_IRQHandler,             // 129: HSP ADC1 interrupt
    HSP_DAC_IRQHandler,              // 130: HSP DAC interrupt
    HSP_LPIT0_IRQHandler,            // 131: HSP LPIT0 interrupt
    HSP_LPIT1_IRQHandler,            // 132: HSP LPIT1 interrupt
    HSP_EFLEXPWM0_CH0_IRQHandler,    // 133: HSP EFLEXPWM0 channel 0 interrupt
    HSP_EFLEXPWM0_CH1_IRQHandler,    // 134: HSP EFLEXPWM0 channel 1 interrupt
    HSP_EFLEXPWM0_CH2_IRQHandler,    // 135: HSP EFLEXPWM0 channel 2 interrupt
    HSP_EFLEXPWM0_CH3_IRQHandler,    // 136: HSP EFLEXPWM0 channel 3 interrupt
    HSP_EFLEXPWM0_ERROR_IRQHandler,  // 137: HSP EFLEXPWM0 fault interrupt
    HSP_EFLEXPWM1_CH0_IRQHandler,    // 138: HSP EFLEXPWM1 channel 0 interrupt
    HSP_EFLEXPWM1_CH1_IRQHandler,    // 139: HSP EFLEXPWM1 channel 1 interrupt
    HSP_EFLEXPWM1_CH2_IRQHandler,    // 140: HSP EFLEXPWM1 channel 2 interrupt
    HSP_EFLEXPWM1_CH3_IRQHandler,    // 141: HSP EFLEXPWM1 channel 3 interrupt
    HSP_EFLEXPWM1_ERROR_IRQHandler,  // 142: HSP EFLEXPWM1 fault interrupt
    HSP_EFLEXPWM2_CH0_IRQHandler,    // 143: HSP EFLEXPWM2 channel 0 interrupt
    HSP_EFLEXPWM2_CH1_IRQHandler,    // 144: HSP EFLEXPWM2 channel 1 interrupt
    HSP_EFLEXPWM2_CH2_IRQHandler,    // 145: HSP EFLEXPWM2 channel 2 interrupt
    HSP_EFLEXPWM2_CH3_IRQHandler,    // 146: HSP EFLEXPWM2 channel 3 interrupt
    HSP_EFLEXPWM2_ERROR_IRQHandler,  // 147: HSP EFLEXPWM2 fault interrupt
    HSP_EFLEXPWM3_CH0_IRQHandler,    // 148: HSP EFLEXPWM3 channel 0 interrupt
    HSP_EFLEXPWM3_CH1_IRQHandler,    // 149: HSP EFLEXPWM3 channel 1 interrupt
    HSP_EFLEXPWM3_CH2_IRQHandler,    // 150: HSP EFLEXPWM3 channel 2 interrupt
    HSP_EFLEXPWM3_CH3_IRQHandler,    // 151: HSP EFLEXPWM3 channel 3 interrupt
    HSP_EFLEXPWM3_ERROR_IRQHandler,  // 152: HSP EFLEXPWM3 fault interrupt
    HSP_QTPM0_IRQHandler,            // 153: HSP QUADTPM0 interrupt
    HSP_QTPM1_IRQHandler,            // 154: HSP QUADTPM1 interrupt
    HSP_QTPM2_IRQHandler,            // 155: HSP QUADTPM2 interrupt
    HSP_QTPM3_IRQHandler,            // 156: HSP QUADTPM3 interrupt
    Reserved157_IRQHandler,          // 157: Reserved interrupt
    Reserved158_IRQHandler,          // 158: Reserved interrupt
    Reserved159_IRQHandler,          // 159: Reserved interrupt
    Reserved160_IRQHandler,          // 160: Reserved interrupt
    Reserved161_IRQHandler,          // 161: Reserved interrupt
    Reserved162_IRQHandler,          // 162: Reserved interrupt
    Reserved163_IRQHandler,          // 163: Reserved interrupt
    Reserved164_IRQHandler,          // 164: Reserved interrupt
    HSP_QTMR0_IRQHandler,            // 165: HSP QUADTMR0 interrupt
    HSP_QTMR1_IRQHandler,            // 166: HSP QUADTMR1 interrupt
    HSP_QTMR2_IRQHandler,            // 167: HSP QUADTMR2 interrupt
    HSP_QTMR3_IRQHandler,            // 168: HSP QUADTMR3 interrupt
    HSP_EQDC0_IRQHandler,            // 169: HSP EQDC0 interrupt
    HSP_EQDC1_IRQHandler,            // 170: HSP EQDC1 interrupt
    HSP_EQDC2_IRQHandler,            // 171: HSP EQDC2 interrupt
    HSP_EQDC3_IRQHandler,            // 172: HSP EQDC3 interrupt
    HSP_SINC0_CH0_IRQHandler,        // 173: HSP SINC0 channel 0 interrupt
    HSP_SINC0_CH1_IRQHandler,        // 174: HSP SINC0 channel 1 interrupt
    HSP_SINC0_CH2_IRQHandler,        // 175: HSP SINC0 channel 2 interrupt
    HSP_SINC0_CH3_IRQHandler,        // 176: HSP SINC0 channel 3 interrupt
    HSP_SINC1_CH0_IRQHandler,        // 177: HSP SINC1 channel 0 interrupt
    HSP_SINC1_CH1_IRQHandler,        // 178: HSP SINC1 channel 1 interrupt
    HSP_SINC1_CH2_IRQHandler,        // 179: HSP SINC1 channel 2 interrupt
    HSP_SINC1_CH3_IRQHandler,        // 180: HSP SINC1 channel 3 interrupt
    HSP_FLEXCAN0_IRQHandler,         // 181: HSP FLEXCAN0 interrupt
    HSP_FLEXCAN0_ERROR_IRQHandler,   // 182: HSP FLEXCAN0 error interrupt
    HSP_FLEXCAN1_IRQHandler,         // 183: HSP FLEXCAN1 interrupt
    HSP_FLEXCAN1_ERROR_IRQHandler,   // 184: HSP FLEXCAN1 error interrupt
    HSP_FLEXCAN2_IRQHandler,         // 185: HSP FLEXCAN2 interrupt
    HSP_FLEXCAN2_ERROR_IRQHandler,   // 186: HSP FLEXCAN2 error interrupt
    HSP_FLEXIO0_IRQHandler,          // 187: HSP FLEXIO0 interrupt
    HSP_FLEXIO1_IRQHandler,          // 188: HSP FLEXIO1 interrupt
    HSP_FLEXIO2_IRQHandler,          // 189: HSP FLEXIO2 interrupt
    HSP_I3C_IRQHandler,              // 190: HSP I3C interrupt
    HSP_LPI2C0_IRQHandler,           // 191: HSP LPI2C0 interrupt
    HSP_LPI2C1_IRQHandler,           // 192: HSP LPI2C1 interrupt
    Reserved193_IRQHandler,          // 193: Reserved interrupt
    Reserved194_IRQHandler,          // 194: Reserved interrupt
    HSP_LPSPI0_IRQHandler,           // 195: HSP LPSPI0 interrupt
    HSP_LPSPI1_IRQHandler,           // 196: HSP LPSPI1 interrupt
    HSP_LPSPI2_IRQHandler,           // 197: HSP LPSPI2 interrupt
    HSP_LPSPI3_IRQHandler,           // 198: HSP LPSPI3 interrupt
    HSP_LPSPI4_IRQHandler,           // 199: HSP LPSPI4 interrupt
    HSP_LPUART0_IRQHandler,          // 200: HSP LPUART0 interrupt
    HSP_LPUART1_IRQHandler,          // 201: HSP LPUART1 interrupt
    HSP_LPUART2_IRQHandler,          // 202: HSP LPUART2 interrupt
    HSP_LPUART3_IRQHandler,          // 203: HSP LPUART3 interrupt
    HSP_LPUART4_IRQHandler,          // 204: HSP LPUART4 interrupt
    HSP_LPUART5_IRQHandler,          // 205: HSP LPUART5 interrupt
    HSP_GPIO0_CH0_IRQHandler,        // 206: HSP GPIO0 channel 0 interrupt
    HSP_GPIO0_CH1_IRQHandler,        // 207: HSP GPIO0 channel 1 interrupt
    HSP_GPIO1_CH0_IRQHandler,        // 208: HSP GPIO1 channel 0 interrupt
    HSP_GPIO1_CH1_IRQHandler,        // 209: HSP GPIO1 channel 1 interrupt
    HSP_GPIO2_CH0_IRQHandler,        // 210: HSP GPIO2 channel 0 interrupt
    HSP_GPIO2_CH1_IRQHandler,        // 211: HSP GPIO2 channel 1 interrupt
    HSP_GPIO3_CH0_IRQHandler,        // 212: HSP GPIO3 channel 0 interrupt
    HSP_GPIO3_CH1_IRQHandler,        // 213: HSP GPIO3 channel 1 interrupt
    HSP_GPIO4_CH0_IRQHandler,        // 214: HSP GPIO4 channel 0 interrupt
    HSP_GPIO4_CH1_IRQHandler,        // 215: HSP GPIO4 channel 1 interrupt
    Reserved216_IRQHandler,          // 216: Reserved interrupt
    Reserved217_IRQHandler,          // 217: Reserved interrupt
    Reserved218_IRQHandler,          // 218: Reserved interrupt
    Reserved219_IRQHandler,          // 219: Reserved interrupt
    Reserved220_IRQHandler,          // 220: Reserved interrupt
    WAKE_TRDC_IRQHandler,            // 221: WAKE TRDC interrupt
    WAKE_XBAR_CH0_IRQHandler,        // 222: WAKE XBAR channel 0 interrupt
    WAKE_XBAR_CH1_IRQHandler,        // 223: WAKE XBAR channel 1 interrupt
    WAKE_EDMA3_CH0_IRQHandler,       // 224: WAKE EDMA3: Channel 0 interrupt
    WAKE_EDMA3_CH1_IRQHandler,       // 225: WAKE EDMA3: Channel 1 interrupt
    WAKE_EDMA3_CH2_IRQHandler,       // 226: WAKE EDMA3: Channel 2 interrupt
    WAKE_EDMA3_CH3_IRQHandler,       // 227: WAKE EDMA3: Channel 3 interrupt
    WAKE_EDMA3_CH4_IRQHandler,       // 228: WAKE EDMA3: Channel 4 interrupt
    WAKE_EDMA3_CH5_IRQHandler,       // 229: WAKE EDMA3: Channel 5 interrupt
    WAKE_EDMA3_CH6_IRQHandler,       // 230: WAKE EDMA3: Channel 6 interrupt
    WAKE_EDMA3_CH7_IRQHandler,       // 231: WAKE EDMA3: Channel 7 interrupt
    WAKE_ACMP0_IRQHandler,           // 232: WAKE CMP0 interrupt
    WAKE_ACMP1_IRQHandler,           // 233: WAKE CMP1 interrupt
    WAKE_ACMP2_IRQHandler,           // 234: WAKE CMP2 interrupt
    WAKE_ACMP3_IRQHandler,           // 235: WAKE CMP3 interrupt
    WAKE_EWM_IRQHandler,             // 236: WAKE EWM interrupt
    WAKE_FREQME_IRQHandler,          // 237: WAKE FREQME interrupt
    WAKE_LPTMR0_IRQHandler,          // 238: WAKE LPTMR0 interrupt
    WAKE_LPTMR1_IRQHandler,          // 239: WAKE LPTMR1 interrupt
    WAKE_QTPM0_IRQHandler,           // 240: WAKE QTPM0 interrupt
    WAKE_QTPM1_IRQHandler,           // 241: WAKE QTPM1 interrupt
    WAKE_QTPM2_IRQHandler,           // 242: WAKE QTPM2 interrupt
    WAKE_QTPM3_IRQHandler,           // 243: WAKE QTPM3 interrupt
    WAKE_SWT0_IRQHandler,            // 244: WAKE SWT0 interrupt
    WAKE_SWT1_IRQHandler,            // 245: WAKE SWT1 interrupt
    Reserved246_IRQHandler,          // 246: Reserved interrupt
    Reserved247_IRQHandler,          // 247: Reserved interrupt
    Reserved248_IRQHandler,          // 248: Reserved interrupt
    Reserved249_IRQHandler,          // 249: Reserved interrupt
    WAKE_I3C_IRQHandler,             // 250: WAKE I3C interrupt
    WAKE_LPI2C0_IRQHandler,          // 251: WAKE LPI2C0 interrupt
    WAKE_LPI2C1_IRQHandler,          // 252: WAKE LPI2C1 interrupt
    WAKE_LPSPI_IRQHandler,           // 253: WAKE LPSPI interrupt
    WAKE_LPUART0_IRQHandler,         // 254: WAKE LPUART0 interrupt
    WAKE_LPUART1_IRQHandler,         // 255: WAKE LPUART1 interrupt
    WAKE_GPIO_CH0_IRQHandler,        // 256: WAKE GPIO channel 0 interrupt
    WAKE_GPIO_CH1_IRQHandler,        // 257: WAKE GPIO channel 1 interrupt
    WAKE_PDM_EVENT_IRQHandler,       // 258: WAKE MICIFL  Filter Results Available (Fifo) Interrupt/
    WAKE_PDM_ERROR_IRQHandler,       // 259: WAKE MICIFL Error interrupt
    WAKE_PDM_HWVAD_EVENT_IRQHandler, // 260: WAKE MICIFL Hwvad Activation interrupt
    WAKE_PDM_HWVAD_ERROR_IRQHandler, // 261: WAKE MICIFL Hwvad Exception Interrupt
    Reserved262_IRQHandler,          // 262: Reserved interrupt
    VBAT_BBSM_INT0_IRQHandler,       // 263: BBSM: Alarm interrupt0
    Reserved264_IRQHandler,          // 264: Reserved interrupt
    VBAT_TDET_IRQHandler,            // 265: VBAT TDET interrupt
    VBAT_LPTMR_IRQHandler,           // 266: VBAT LPTMR interrupt
    VBAT_RTC_IRQHandler,             // 267: VBAT RTC interrupt
    VBAT_GPIO_CH0_IRQHandler,        // 268: VBAT GPIO channel 0 interrupt
    VBAT_GPIO_CH1_IRQHandler,        // 269: VBAT GPIO channel 1 interrupt
    VBAT_VBATCON_IRQHandler,         // 270: vbatcon Interrupt Request
    AUDIO_TRDC_IRQHandler,           // 271: AUDIO TRDC interrupt
    AUDIO_SAI0_IRQHandler,           // 272: AUDIO SAI0 interrupt
    AUDIO_SAI1_IRQHandler,           // 273: AUDIO SAI1 interrupt
    AUDIO_SAI2_IRQHandler,           // 274: AUDIO SAI2 interrupt
    Reserved275_IRQHandler,          // 275: Reserved interrupt
    Reserved276_IRQHandler,          // 276: Reserved interrupt
    Reserved277_IRQHandler,          // 277: Reserved interrupt
    AUDIO_PDM_EVENT_IRQHandler,      // 278: AUDIO MICDIL Filter Results Available (Fifo) Interrupt
    AUDIO_PDM_ERROR_IRQHandler,      // 279: AUDIO MICDIL Error interrupt
    Reserved280_IRQHandler,          // 280: Reserved interrupt
    Reserved281_IRQHandler,          // 281: Reserved interrupt
    Reserved282_IRQHandler,          // 282: Reserved interrupt
    Reserved283_IRQHandler,          // 283: Reserved interrupt
    Reserved284_IRQHandler,          // 284: Reserved interrupt
    Reserved285_IRQHandler,          // 285: Reserved interrupt
    AUDIO_SPDIF_IRQHandler,          // 286: AUDIO SPDIF interrupt
    AUDIO_EDMA3_CH0_IRQHandler,      // 287: AUDIO EDMA3: Channel 0 interrupt
    AUDIO_EDMA3_CH1_IRQHandler,      // 288: AUDIO EDMA3: Channel 1 interrupt
    AUDIO_EDMA3_CH2_IRQHandler,      // 289: AUDIO EDMA3: Channel 2 interrupt
    AUDIO_EDMA3_CH3_IRQHandler,      // 290: AUDIO EDMA3: Channel 3 interrupt
    AUDIO_EDMA3_CH4_IRQHandler,      // 291: AUDIO EDMA3: Channel 4 interrupt
    AUDIO_EDMA3_CH5_IRQHandler,      // 292: AUDIO EDMA3: Channel 5 interrupt
    AUDIO_EDMA3_CH6_IRQHandler,      // 293: AUDIO EDMA3: Channel 6 interrupt
    AUDIO_EDMA3_CH7_IRQHandler,      // 294: AUDIO EDMA3: Channel 7 interrupt
    Reserved295_IRQHandler,          // 295: Reserved interrupt
    Reserved296_IRQHandler,          // 296: Reserved interrupt
    Reserved297_IRQHandler,          // 297: Reserved interrupt
    Reserved298_IRQHandler,          // 298: Reserved interrupt
    Reserved299_IRQHandler,          // 299: Reserved interrupt
    Reserved300_IRQHandler,          // 300: Reserved interrupt
    Reserved301_IRQHandler,          // 301: Reserved interrupt
    Reserved302_IRQHandler,          // 302: Reserved interrupt
    Reserved303_IRQHandler,          // 303: Reserved interrupt
    AUDIO_ASRC_IRQHandler,           // 304: AUDIO ASRC interrupt
    AUDIO_FREQME_IRQHandler,         // 305: AUDIO FREQME interrupt
    Reserved306_IRQHandler,          // 306: Reserved interrupt
    Reserved307_IRQHandler,          // 307: Reserved interrupt
    Reserved308_IRQHandler,          // 308: Reserved interrupt
    Reserved309_IRQHandler,          // 309: Reserved interrupt
    Reserved310_IRQHandler,          // 310: Reserved interrupt
    COMM_TRDC_IRQHandler,            // 311: COMM TRDC interrupt
    COMM_ENET_QOS_IRQHandler,        // 312: COMM ENET_QOS interrupt
    COMM_ENET_QOS_TX_IRQHandler,     // 313: ENET_QOS: Per Channel Transmit Interrupt Signal To Host System
    COMM_ENET_QOS_RX_IRQHandler,     // 314: ENET_QOS: Per Channel Receive Interrupt Signal To Host System
    COMM_ENET_TX_IRQHandler,         // 315: COMM ENET TX interrupt
    COMM_ENET_RX_IRQHandler,         // 316: COMM ENET RX interrupt
    COMM_ENET_OTHER_IRQHandler,      // 317: ENET_1G_MAC: ETH OTHER_INT0_17
    COMM_ENET_1588_IRQHandler,       // 318: ENET_1G_MAC: IEEE-1588 Timer Interrupt
    COMM_FLEXSPI_SLV_IRQHandler,     // 319: COMM FlexSPI follower interrupt
    COMM_USB0_IRQHandler,            // 320: COMM USBHS interrupt
    COMM_USBPHY_IRQHandler,          // 321: COMM USBPHY interrupt
    COMM_USB1_IRQHandler,            // 322: COMM USBFS interrupt
    COMM_USDHC0_IRQHandler,          // 323: COMM USDHC0 interrupt
    COMM_USDHC1_IRQHandler,          // 324: COMM USDHC1 interrupt
    Reserved325_IRQHandler,          // 325: Reserved interrupt
    COMM_TENBASET_PHY0_IRQHandler,   // 326: XENO_PHY0:Functional IRQ1 interrupt request
    Reserved327_IRQHandler,          // 327: Reserved interrupt
    COMM_TENBASET_PHY1_IRQHandler,   // 328: XENO_PHY1:Functional IRQ1 interrupt request
    Reserved329_IRQHandler,          // 329: Reserved interrupt
    COMM_FREQME_IRQHandler,          // 330: COMM FREQME interrupt
    MEDIA_TRDC_IRQHandler,           // 331: MEDIA TRDC interrupt
    Reserved332_IRQHandler,          // 332: Reserved interrupt
    MEDIA_DCIF_CH0_IRQHandler,       // 333: MEDIA DCIF channel 0 interrupt
    MEDIA_DCIF_CH1_IRQHandler,       // 334: MEDIA DCIF channel 1 interrupt
    MEDIA_DCIF_CH2_IRQHandler,       // 335: MEDIA DCIF channel 2 interrupt
    MEDIA_DCIF_CH3_IRQHandler,       // 336: MEDIA DCIF channel 3 interrupt
    MEDIA_DCIF_CH4_IRQHandler,       // 337: MEDIA DCIF channel 4 interrupt
    MEDIA_DCIF_CH5_IRQHandler,       // 338: MEDIA DCIF channel 5 interrupt
    MEDIA_DCIF_CH6_IRQHandler,       // 339: MEDIA DCIF channel 6 interrupt
    MEDIA_DCIF_CH7_IRQHandler,       // 340: MEDIA DCIF channel 7 interrupt
    MEDIA_DCIF_CH8_IRQHandler,       // 341: MEDIA DCIF channel 8 interrupt
    MEDIA_CSI_IRQHandler,            // 342: CSI:CSI Interrupt Request
    MEDIA_REFORMATTER_IRQHandler,    // 343: MEDIA REFORMATTER interrupt
    MEDIA_ISI_IRQHandler,            // 344: MEDIA ISI interrupt
    MEDIA_TINGPU_IRQHandler,         // 345: MEDIA TINGPU interrupt
    MEDIA_JPEGDEC_IRQHandler,        // 346: MEDIA JPEGDEC interrupt
    MEDIA_MIPI_CSI_IRQHandler,       // 347: MIPI_CSI: Interrupt Request
    MEDIA_MIPI_DSI_IRQHandler,       // 348: MIPI_DSI: Interrupt Request
    MEDIA_FREQME_IRQHandler,         // 349: MEDIA FREQME interrupt
};                                     /* End of vector table */

//*****************************************************************************
// Section 6: Reset_Handler
//*****************************************************************************

STARTUP_RESET_ATTR
void Reset_Handler(void)
{
    // Disable interrupts
    __asm volatile("cpsid i");

    // Enable CP10/CP11 (FPU/MVE) before any C code runs. With the hard-float
    // ABI the compiler may use FP/MVE registers in function prologues (e.g.
    // vpush in Reset_Handler_C at high optimization levels), which raises a
    // NOCP UsageFault if the coprocessors are still disabled at that point.
    __asm volatile(
        "LDR R0, =0xE000ED88  \n"
        "LDR R1, [R0]         \n"
        "ORR R1, R1, #0xF00000\n"
        "STR R1, [R0]         \n"
        "DSB                  \n"
        "ISB                  \n"
                    :
                    :
                    : "r0", "r1");

    // Config VTOR, MSP, MSPLIM (ARMv8-M hardware stack overflow guard).
    // Order: clear MSPLIM to 0 first (in case ROM left it set), then update
    // MSP to the new top, then set MSPLIM to the real stack base. This
    // ensures the hardware invariant MSP >= MSPLIM holds throughout.
    __asm volatile(
        "LDR R0, =0xE000ED08  \n"
        "STR %0, [R0]         \n"
        "MOVS R1, #0          \n"
        "MSR MSPLIM, R1       \n"
        "LDR R1, [%0]         \n"
        "MSR MSP, R1          \n"
        "MSR MSPLIM, %1       \n"
                    :
                    : "r"(STARTUP_VT_SYMBOL), "r"(_vStackBase)
                    : "r0", "r1");

    // Call Reset_Handler_C; trap here if it unexpectedly returns.
    __asm volatile ("LDR R0, =Reset_Handler_C \n"
                    "BLX R0                   \n"
                    "1: B 1b                  \n"
                    );
}

//*****************************************************************************
// Section 7: Reset_Handler_C
//*****************************************************************************

STARTUP_RESET_C_ATTR
void Reset_Handler_C(void)
{
#if !defined(__NO_SYSTEM_INIT)
    SystemInit();
#endif
    STARTUP_RUNTIME_PROLOG();
    STARTUP_RUNTIME_ENTER();
}

//*****************************************************************************
// Section 8: End scaffolding
//*****************************************************************************

#if defined(__cplusplus)
} // extern "C"
#endif

STARTUP_PRAGMA_POP
