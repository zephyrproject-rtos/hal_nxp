/*
 * Copyright 2025-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_CLOCK_H_
#define _FSL_CLOCK_H_

#include "fsl_common.h"

/*! @addtogroup clock */
/*! @{ */

/*! @file */

/*******************************************************************************
 * Configurations
 ******************************************************************************/

/*! @brief Configure whether driver controls clock
 *
 * When set to 0, peripheral drivers will enable clock in initialize function
 * and disable clock in de-initialize function. When set to 1, peripheral
 * driver will not control the clock, application could control the clock out of
 * the driver.
 *
 * @note All drivers share this feature switcher. If it is set to 1, application
 * should handle clock enable and disable for all drivers.
 */
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL))
#define FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL 0
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#ifndef SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY
#define SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY (1000000000UL)
#endif

/*! @name Driver version */
/*@{*/
/*! @brief CLOCK driver version 1.1.0. */
#define FSL_CLOCK_DRIVER_VERSION (MAKE_VERSION(1, 1, 0))
/*! @} */

/*! @name FREQME-based frequency measurement configuration (set via Kconfig, or override before including this header) */
/*@{*/
/*! @brief Reference clock scaling exponent used by CLOCK_Measure*Freq().
 *
 * One measurement counts target-clock edges during 2^REF_SCALE reference
 * cycles. With the 24 MHz crystal reference this gives ~2.73 ms per
 * measurement and 24 MHz / 2^16 = 366 Hz resolution. Valid range 0..24
 * (enforced at compile time); values above 24 could overflow the 31-bit
 * result counter with a 2 GHz target and 24 MHz reference
 * (2 GHz / 24 MHz * 2^25 > 2^31). */
#ifndef FSL_CLOCK_FREQME_REF_SCALE
#ifdef CONFIG_FSL_CLOCK_FREQME_REF_SCALE
#define FSL_CLOCK_FREQME_REF_SCALE (CONFIG_FSL_CLOCK_FREQME_REF_SCALE)
#else
#define FSL_CLOCK_FREQME_REF_SCALE (16U)
#endif
#endif
/*! @brief Bounded polling loop count for one FREQME measurement (CPU-frequency
 * independent busy-wait bound; measurement never completes if the reference
 * clock is dead). */
#ifndef FSL_CLOCK_FREQME_TIMEOUT_LOOPS
#ifdef CONFIG_FSL_CLOCK_FREQME_TIMEOUT_LOOPS
#define FSL_CLOCK_FREQME_TIMEOUT_LOOPS (CONFIG_FSL_CLOCK_FREQME_TIMEOUT_LOOPS)
#else
#define FSL_CLOCK_FREQME_TIMEOUT_LOOPS (1000000U)
#endif
#endif
/*@}*/

/*! @name PLL frequency macros (project defaults; override before including this header) */
/*@{*/
#ifndef FSL_CLOCK_USBPLL_OUT_FREQ_HZ
#define FSL_CLOCK_USBPLL_OUT_FREQ_HZ   (480000000U)
#endif
#ifndef FSL_CLOCK_USBPLL_48M_FREQ_HZ
#define FSL_CLOCK_USBPLL_48M_FREQ_HZ   (48000000U)
#endif
#ifndef FSL_CLOCK_MIPIPLL_DIV8_FREQ_HZ
#define FSL_CLOCK_MIPIPLL_DIV8_FREQ_HZ (54000000U)
#endif
#ifndef FSL_CLOCK_MEDIAPLL_FREQ_HZ
#define FSL_CLOCK_MEDIAPLL_FREQ_HZ     (108000000U)
#endif
/*! @} */

/*! @brief Clock gate name arrays */


/*! @brief Clock ip name array for ACMP. */
#define CMP_CLOCKS                                                                 \
    {                                                                               \
        kCLOCK_WAKE_acmp0, kCLOCK_WAKE_acmp1, kCLOCK_WAKE_acmp2, kCLOCK_WAKE_acmp3  \
    }

/*! @brief Clock ip name array for ADC. */
#define LPADC_CLOCKS                                  \
    {                                               \
        kCLOCK_MAIN_hsp_adc0, kCLOCK_MAIN_hsp_adc1  \
    }

/*! @brief Clock ip name array for SRAMC. */
#define SRAMC_CLOCKS        \
    {                       \
        kCLOCK_MAIN_sramc   \
    }

/*! @brief Clock ip name array for ASRC. */
#define ASRC_CLOCKS         \
    {                       \
        kCLOCK_AUDIO_asrc   \
    }

/*! @brief Clock ip name array for AXBS. */
#define AXBS_CLOCKS         \
    {                       \
        MAIN_AXBS_BASE      \
    }

/*! @brief Clock ip name array for FLEXCAN. */
#define FLEXCAN_CLOCKS                                                      \
    {                                                                       \
        kCLOCK_MAIN_hsp_can0, kCLOCK_MAIN_hsp_can1, kCLOCK_MAIN_hsp_can2    \
    }

/*! @brief Clock ip name array for CCM. */
#define CCM_CLOCKS                                                                                  \
    {                                                                                               \
        AUDIO_CCM_BASE, CMPT_CCM_BASE, COMM_CCM_BASE, MAIN_CCM_BASE, MEDIA_CCM_BASE, WAKE_CCM_BASE  \
    }

/*! @brief Clock ip name array for CRC. */
#define CRC_CLOCKS          \
    {                       \
        kCLOCK_MAIN_hsp_crc \
    }

/*! @brief Clock ip name array for CSI. */
#define CSI_CLOCKS          \
    {                       \
        kCLOCK_MEDIA_csi    \
    }

/*! @brief Clock ip name array for DCIF. */
#define DCIF_CLOCKS         \
    {                       \
        kCLOCK_MEDIA_dcif   \
    }

/*! @brief Clock ip name array for DSI2_HOST. */
#define DSI2_HOST_CLOCKS    \
    {                       \
        kCLOCK_MEDIA_mipi_dsi   \
    }

/*! @brief Clock ip name array for EDMA, indexed to match EDMA_BASE_PTRS
 * {MAIN__EDMA3, MAIN__EDMA5, AUDIO__EDMA3, WAKE__EDMA3}. Note the crossed
 * MAIN gate naming per RM rev.1 Draft M Table 65 (ch.20.4 System clocks):
 * gate main_edma0 (CGC_ROOT6) clocks MAIN_EDMA5, and gate main_edma1
 * (CGC_ROOT7) clocks MAIN_EDMA3. Verified on silicon: edma3/edma5
 * memory_to_memory examples bus-fault with the gates swapped and pass with
 * this mapping. */
#define EDMA_CLOCKS                                                               \
    {                                                                             \
        kCLOCK_MAIN_edma1, kCLOCK_MAIN_edma0, kCLOCK_AUDIO_edma, kCLOCK_WAKE_edma \
    }

/*! @brief Clock ip name array for ENET. Note the crossed gate naming per RM
 * Table 65 (ch.20.4): gate comm_eth1 (CGC_ROOT2) clocks COMM_ENET, while
 * gate comm_eth0 (CGC_ROOT1) clocks COMM_ENET_QOS. */
#define ENET_CLOCKS      \
    {                    \
        kCLOCK_COMM_eth1 \
    }

/*! @brief Clock ip name array for ENETQOS. Gate comm_eth0 (CGC_ROOT1)
 * clocks COMM_ENET_QOS per RM Table 65 -- see ENET_CLOCKS note. */
#define ENETQOS_CLOCKS   \
    {                    \
        kCLOCK_COMM_eth0 \
    }

/*! @brief Clock ip name array for QDC. */
#define QDC_CLOCKS                                                                                 \
    {                                                                                              \
        kCLOCK_MAIN_hsp_qdc0, kCLOCK_MAIN_hsp_qdc1, kCLOCK_MAIN_hsp_qdc2, kCLOCK_MAIN_hsp_qdc3 \
    }

/*! @brief Clock ip name array for EWM. */
#define EWM_CLOCKS      \
    {                   \
        kCLOCK_Ewm0 \
    }

/*! @brief Clock ip name array for FLEXIO. */
#define FLEXIO_CLOCKS                                                             \
    {                                                                             \
        kCLOCK_MAIN_hsp_flexio0, kCLOCK_MAIN_hsp_flexio1, kCLOCK_MAIN_hsp_flexio2 \
    }

/*! @brief Clock ip name array for FLEXSPI. */
#define FLEXSPI_SLV_CLOCKS \
    {                      \
        kCLOCK_COMM_xspir  \
    }

/*! @brief Clock ip name array for FREQME. */
#define FREQME_CLOCKS                                                                                                                                  \
    {                                                                                                                                                  \
        kCLOCK_AUDIO_freqme, kCLOCK_CMPT_freqme, kCLOCK_COMM_freqme, kCLOCK_MAIN_freqme, kCLOCK_MEDIA_freqme, kCLOCK_SYSCON_freqme, kCLOCK_WAKE_freqme \
    }

#define INPUTMUX_CLOCKS                                                                                                                                \
    {                                                                                                                                                  \
        kCLOCK_AUDIO_freqme, kCLOCK_CMPT_freqme, kCLOCK_COMM_freqme, kCLOCK_MAIN_freqme, kCLOCK_MEDIA_freqme, kCLOCK_SYSCON_freqme, kCLOCK_WAKE_freqme \
    }

/*! @brief Clock ip name array for GPIO, indexed to match GPIO_BASE_PTRS
 * {HSP__GPIO_0..4, VBAT__GPIO, WAKE__GPIO} (7 entries). VBAT__GPIO has no
 * LPCG (clocked directly from wake_clk per RM Table 65), so its slot is
 * kCLOCK_IpInvalid. */
#define GPIO_CLOCKS                                                                                                    \
    {                                                                                                                  \
        kCLOCK_MAIN_hsp_rgpio0, kCLOCK_MAIN_hsp_rgpio1, kCLOCK_MAIN_hsp_rgpio2, kCLOCK_MAIN_hsp_rgpio3,               \
        kCLOCK_MAIN_hsp_rgpio4, kCLOCK_IpInvalid, kCLOCK_WAKE_rgpio0                                                   \
    }

/*! @brief Clock ip name array for SAI. */
#define SAI_CLOCKS                                              \
    {                                                           \
        kCLOCK_AUDIO_sai0, kCLOCK_AUDIO_sai1, kCLOCK_AUDIO_sai2 \
    }

/*! @brief Clock ip name array for I3C. */
#define I3C_CLOCKS                             \
    {                                          \
        kCLOCK_MAIN_hsp_i3c0, kCLOCK_WAKE_i3c0 \
    }

/*! @brief Clock ip name array for ISI. */
#define ISI_CLOCKS       \
    {                    \
        kCLOCK_MEDIA_isi \
    }

/*! @brief Clock ip name array for JPEGDEC. */
#define JPEGDEC_CLOCKS            \
    {                             \
        kCLOCK_MEDIA_jpeg_decoder \
    }

/*! @brief Clock ip name array for LLC. */
#define LLC_CLOCKS      \
    {                   \
        kCLOCK_CMPT_llc \
    }

/*! @brief Clock ip name array for DAC. */
#define LPDAC_CLOCKS          \
    {                       \
        kCLOCK_MAIN_hsp_dac \
    }

/*! @brief Clock ip name array for LPI2C. */
#define LPI2C_CLOCKS                                                                           \
    {                                                                                          \
        kCLOCK_MAIN_hsp_lpi2c0, kCLOCK_MAIN_hsp_lpi2c1, kCLOCK_WAKE_lpi2c0, kCLOCK_WAKE_lpi2c1 \
    }

/*! @brief Clock ip name array for LPIT. */
#define LPIT_CLOCKS                                  \
    {                                                \
        kCLOCK_MAIN_hsp_lpit0, kCLOCK_MAIN_hsp_lpit1 \
    }

/*! @brief Clock ip name array for LPSPI. */
#define LPSPI_CLOCKS                                                                                                                              \
    {                                                                                                                                             \
        kCLOCK_MAIN_hsp_lpspi0, kCLOCK_MAIN_hsp_lpspi1, kCLOCK_MAIN_hsp_lpspi2, kCLOCK_MAIN_hsp_lpspi3, kCLOCK_MAIN_hsp_lpspi4, kCLOCK_WAKE_lpspi \
    }

/*! @brief Clock ip name array for LPTMR. */
#define LPTMR_CLOCKS                                                 \
    {                                                                \
        kCLOCK_IpInvalid, kCLOCK_WAKE_lptimer0, kCLOCK_WAKE_lptimer1 \
    }

/*! @brief Clock ip name array for LPUART. */
#define LPUART_CLOCKS                                                                                                                                                                                                    \
    {                                                                                                                                                                                                                    \
        kCLOCK_MAIN_hsp_lpuart0, kCLOCK_MAIN_hsp_lpuart1, kCLOCK_MAIN_hsp_lpuart2, kCLOCK_MAIN_hsp_lpuart3, kCLOCK_MAIN_hsp_lpuart4, kCLOCK_MAIN_hsp_lpuart5, kCLOCK_WAKE_lpuart0, kCLOCK_WAKE_lpuart1 \
    }

/*! @brief Clock ip name array for MMU. */
#define MMU_CLOCKS       \
    {                    \
        kCLOCK_MAIN_mmu0 \
    }

/*! @brief Clock ip name array for MODCON. */
#define MODCON_CLOCKS                                                                                                            \
    {                                                                                                                            \
        kCLOCK_AUDIO_modcon, kCLOCK_CMPT_modcon, kCLOCK_COMM_modcon, kCLOCK_MAIN_modcon, kCLOCK_MEDIA_modcon, kCLOCK_WAKE_modcon \
    }

/*! @brief Clock ip name array for NIC. */
#define NIC_CLOCKS                                                                               \
    {                                                                                            \
        kCLOCK_CMPT_nic_gpv, kCLOCK_COMM_nic_gpv, kCLOCK_MAIN_nic_main_gpv, kCLOCK_MEDIA_nic_gpv \
    }

/*! @brief Clock ip name array for NPU. */
#define NPU_CORE_CLOCKS \
    { \
        kCLOCK_CMPT_npu_core \
    }

/*! @brief Clock ip name array for NPU. */
#define NPU_MEM_CLOCKS      \
    {                       \
        kCLOCK_CMPT_npu_mem \
    } 

/*! @brief Clock ip name array for PDCON. */
#define PDCON_CLOCKS             \
    {                            \
        kCLOCK_WAKE_syscon_pdcon \
    }

/*! @brief Clock ip name array for PDM. */
#define PDM_CLOCKS                              \
    {                                           \
        kCLOCK_AUDIO_micfil, kCLOCK_WAKE_micfil \
    }

/*! @brief Clock ip name array for PMU. */
#define PMU_CLOCKS             \
    {                          \
        kCLOCK_WAKE_syscon_pmu \
    }

/*! @brief Clock ip name array for PWM. */
#define PWM_CLOCKS                                                                                                \
    {                                                                                                             \
        {kCLOCK_MAIN_hsp_flexpwm0, kCLOCK_MAIN_hsp_flexpwm0, kCLOCK_MAIN_hsp_flexpwm0, kCLOCK_MAIN_hsp_flexpwm0}, \
        {kCLOCK_MAIN_hsp_flexpwm1, kCLOCK_MAIN_hsp_flexpwm1, kCLOCK_MAIN_hsp_flexpwm1, kCLOCK_MAIN_hsp_flexpwm1}, \
        {kCLOCK_MAIN_hsp_flexpwm2, kCLOCK_MAIN_hsp_flexpwm2, kCLOCK_MAIN_hsp_flexpwm2, kCLOCK_MAIN_hsp_flexpwm2}, \
        {kCLOCK_MAIN_hsp_flexpwm3, kCLOCK_MAIN_hsp_flexpwm3, kCLOCK_MAIN_hsp_flexpwm3, kCLOCK_MAIN_hsp_flexpwm3}  \
    }

/*! @brief Clock ip name array for REFORMATTER. */
#define REFORMATTER_CLOCKS       \
    {                            \
        kCLOCK_MEDIA_reformatter \
    }

/*! @brief Clock ip name array for RESETCON. */
#define RESETCON_CLOCKS             \
    {                               \
        kCLOCK_WAKE_syscon_resetcon \
    }

/*! @brief Clock ip name array for ROMCP. */
#define ROMCP_CLOCKS      \
    {                     \
        kCLOCK_CMPT_romcp \
    }

/*! @brief Clock ip name array for RTC. */
#define RTC_CLOCKS              \
    {                           \
        kCLOCK_WAKE_vbat_rtc_hp \
    }

/*! @brief Clock ip name array for SINC. */
#define SINC_CLOCKS                                  \
    {                                                \
        kCLOCK_MAIN_hsp_sinc0, kCLOCK_MAIN_hsp_sinc1 \
    }

/*! @brief Clock ip name array for SPDIF. */
#define SPDIF_CLOCKS            \
    {                           \
        kCLOCK_AUDIO_spdif_xcvr \
    }

/*! @brief Clock ip name array for SRAM. */
#define SRAM_CTRL_CLOCKS                                                       \
    {                                                                          \
        kCLOCK_CMPT_sram_ctrl0, kCLOCK_CMPT_sram_ctrl1, kCLOCK_CMPT_sram_ctrl2 \
    }

/*! @brief Clock ip name array for STM. */
#define STM_CLOCKS          \
    {                       \
        kCLOCK_MAIN_hsp_stm \
    }

/*! @brief Clock ip name array for SWT. */
#define SWT_CLOCKS                         \
    {                                      \
        kCLOCK_WAKE_swt0, kCLOCK_WAKE_swt1 \
    }

/*! @brief Clock ip name array for TENBASET. */
#define TENBASET_PHY_CLOCKS                        \
    {                                              \
        kCLOCK_COMM_xenophy0, kCLOCK_COMM_xenophy1 \
    }

/*! @brief Clock ip name array for TINGPU. */
#define TINGPU_CLOCKS    \
    {                    \
        kCLOCK_MEDIA_gpu \
    }

/*! @brief Clock ip name array for TMR. */
#define TMR_CLOCKS                                                                                         \
    {                                                                                                      \
        kCLOCK_MAIN_hsp_qtimer0, kCLOCK_MAIN_hsp_qtimer1, kCLOCK_MAIN_hsp_qtimer2, kCLOCK_MAIN_hsp_qtimer3 \
    }

/*! @brief Clock ip name array for TPM. */
#define TPM_CLOCKS                                                                                                                                                          \
    {                                                                                                                                                                       \
        kCLOCK_MAIN_hsp_qtpm0, kCLOCK_MAIN_hsp_qtpm0, kCLOCK_MAIN_hsp_qtpm0, kCLOCK_MAIN_hsp_qtpm0, kCLOCK_WAKE_qtpm, kCLOCK_WAKE_qtpm , kCLOCK_WAKE_qtpm, kCLOCK_WAKE_qtpm \
    }

/*! @brief Clock ip name array for TRDC. */
#define TRDC_CLOCKS                                                                                \
    {                                                                                              \
        kCLOCK_AUDIO_trdc, kCLOCK_COMM_trdc, kCLOCK_MAIN_trdc, kCLOCK_MEDIA_trdc, kCLOCK_WAKE_trdc \
    }

/*! @brief Clock ip name array for CMPT. */
#define CMPT_TRDC_CLOCKS \
    {                    \
        kCLOCK_CMPT_trdc \
    }

/*! @brief Clock ip name array for TRGSYNC. */
#define TRGSYNC_CLOCKS                                                                \
    {                                                                                 \
        kCLOCK_MAIN_hsp_trig_sync0, kCLOCK_MAIN_hsp_trig_sync1, kCLOCK_WAKE_trig_sync \
    }

/*! @brief Clock ip name array for USB. */
#define USB_CLOCKS                         \
    {                                      \
        kCLOCK_COMM_usb0, kCLOCK_COMM_usb1 \
    }

/*! @brief Clock ip name array for USDHC. */
#define USDHC_CLOCKS                           \
    {                                          \
        kCLOCK_COMM_usdhc0, kCLOCK_COMM_usdhc1 \
    }

/*! @brief Clock ip name array for XBARs. */
#define XBAR_CLOCKS             \
    {                           \
        kCLOCK_IpInvalid,       \
        kCLOCK_AUDIO_xbar0,     \
        kCLOCK_MAIN_hsp_xbar0,  \
        kCLOCK_MAIN_hsp_xbar1,  \
        kCLOCK_MAIN_hsp_xbar2,  \
        kCLOCK_WAKE_xbar0       \
    }

/*! @brief Clock ip name array for XSPI. */
#define XSPI_CLOCKS                          \
    {                                        \
        kCLOCK_MAIN_xspi0, kCLOCK_MAIN_xspi1 \
    }

/*!
 * @brief Clock LPCG index
 */
typedef enum _clock_lpcg {
  // Clock LPCG for SYSCON SS [0]
  kCLOCK_SYSCON_START                          = 0,
  kCLOCK_SYSCON_freqme                         = 0,   /*!< Clock LPCG SYSCON SS 0 syscon_freqme       */
  kCLOCK_SYSCON_END                            = 0,
  // Clock LPCG for Cmpt Subsystem [16..29]
  kCLOCK_CMPT_START                            = 16,
  kCLOCK_CMPT_romcp                            = 16,  /*!< Clock LPCG Cmpt SS index 0  cmpt_romcp     */
  kCLOCK_CMPT_cm85_clkin                       = 17,  /*!< Clock LPCG Cmpt SS index 1  cm85_clkin     */
  kCLOCK_CMPT_cm85_dbgclk                      = 18,  /*!< Clock LPCG Cmpt SS index 2  cm85_dbgclk    */
  kCLOCK_CMPT_cm85_iwic                        = 19,  /*!< Clock LPCG Cmpt SS index 3  cm85_iwic      */
  kCLOCK_CMPT_npu_core                         = 20,  /*!< Clock LPCG Cmpt SS index 4  npu_core       */
  kCLOCK_CMPT_npu_mem                          = 21,  /*!< Clock LPCG Cmpt SS index 5  npu_mem        */
  kCLOCK_CMPT_freqme                           = 22,  /*!< Clock LPCG Cmpt SS index 6  cmpt_freqme    */
  kCLOCK_CMPT_modcon                           = 23,  /*!< Clock LPCG Cmpt SS index 7  cmpt_modcon    */
  kCLOCK_CMPT_trdc                             = 24,  /*!< Clock LPCG Cmpt SS index 8  cmpt_trdc      */
  kCLOCK_CMPT_sram_ctrl0                       = 25,  /*!< Clock LPCG Cmpt SS index 9  cmpt_sram_ctrl0*/
  kCLOCK_CMPT_sram_ctrl1                       = 26,  /*!< Clock LPCG Cmpt SS index 10 cmpt_sram_ctrl1*/
  kCLOCK_CMPT_sram_ctrl2                       = 27,  /*!< Clock LPCG Cmpt SS index 11 cmpt_sram_ctrl2*/
  kCLOCK_CMPT_nic_gpv                          = 28,  /*!< Clock LPCG Cmpt SS index 12 cmpt_nic_gpv   */
  kCLOCK_CMPT_llc                              = 29,  /*!< Clock LPCG Cmpt SS index 13 cmpt_llc       */
  kCLOCK_CMPT_END                              = 29,
  // Clock LPCG for Main Subsystem [32..106]
  kCLOCK_MAIN_START                            = 32,
  kCLOCK_MAIN_trace_rt2660                     = 32,  /*!< Clock LPCG Main SS index 0  trace_rt2660   */
  kCLOCK_MAIN_tsclk                            = 33,  /*!< Clock LPCG Main SS index 1 tsclk           */
  kCLOCK_MAIN_tpiu_traceclkin                  = 34,  /*!< Clock LPCG Main SS index 2 tpiu_traceclkin */
  kCLOCK_MAIN_swo_traceclkin                   = 35,  /*!< Clock LPCG Main SS index 3  swo_traceclkin */
  kCLOCK_MAIN_xspi0                            = 36, /*!< Clock LPCG Main SS index 4 xspi0           */
  kCLOCK_MAIN_xspi1                            = 37, /*!< Clock LPCG Main SS index 5 xspi1           */
  kCLOCK_MAIN_edma0                            = 38, /*!< Clock LPCG Main SS index 6 edma0           */
  kCLOCK_MAIN_edma1                            = 39, /*!< Clock LPCG Main SS index 7 edma1           */
  kCLOCK_MAIN_freqme                           = 40, /*!< Clock LPCG Main SS index 8 freqme          */
  kCLOCK_MAIN_modcon                           = 41, /*!< Clock LPCG Main SS index 9 modcon          */
  kCLOCK_MAIN_hsp_crc                          = 42, /*!< Clock LPCG Main SS index 10 hsp_crc        */
  kCLOCK_MAIN_hsp_dac                          = 43, /*!< Clock LPCG Main SS index 11 hsp_dac        */
  kCLOCK_MAIN_hsp_adc0                         = 44, /*!< Clock LPCG Main SS index 12 hsp_adc0       */
  kCLOCK_MAIN_hsp_adc1                         = 45, /*!< Clock LPCG Main SS index 13 hsp_adc1       */
  kCLOCK_MAIN_hsp_evtg0                        = 46, /*!< Clock LPCG Main SS index 14 hsp_evtg0      */
  kCLOCK_MAIN_hsp_evtg1                        = 47, /*!< Clock LPCG Main SS index 15 hsp_evtg1      */
  kCLOCK_MAIN_hsp_evtg2                        = 48, /*!< Clock LPCG Main SS index 16 hsp_evtg2      */
  kCLOCK_MAIN_hsp_evtg3                        = 49, /*!< Clock LPCG Main SS index 17 hsp_evtg3      */
  kCLOCK_MAIN_hsp_xbar0                        = 50, /*!< Clock LPCG Main SS index 18 hsp_xbar0      */
  kCLOCK_MAIN_hsp_xbar1                        = 51, /*!< Clock LPCG Main SS index 19 hsp_xbar1      */
  kCLOCK_MAIN_hsp_xbar2                        = 52, /*!< Clock LPCG Main SS index 20 hsp_xbar2      */
  kCLOCK_MAIN_sramc                            = 53, /*!< Clock LPCG Main SS index 21 sramc          */
  kCLOCK_MAIN_trdc                             = 54, /*!< Clock LPCG Main SS index 22 trdc           */
  kCLOCK_MAIN_hsp_lpspi0                       = 55, /*!< Clock LPCG Main SS index 23 hsp_lpspi0     */
  kCLOCK_MAIN_hsp_lpspi1                       = 56, /*!< Clock LPCG Main SS index 24 hsp_lpspi1     */
  kCLOCK_MAIN_hsp_lpspi2                       = 57, /*!< Clock LPCG Main SS index 25 hsp_lpspi2     */
  kCLOCK_MAIN_hsp_lpspi3                       = 58, /*!< Clock LPCG Main SS index 26 hsp_lpspi3     */
  kCLOCK_MAIN_hsp_lpspi4                       = 59, /*!< Clock LPCG Main SS index 27 hsp_lpspi4     */
  kCLOCK_MAIN_hsp_lpi2c0                       = 60, /*!< Clock LPCG Main SS index 28 hsp_lpi2c0     */
  kCLOCK_MAIN_hsp_lpi2c1                       = 61, /*!< Clock LPCG Main SS index 29 hsp_lpi2c1     */
  kCLOCK_MAIN_hsp_lpuart0                      = 62, /*!< Clock LPCG Main SS index 30 hsp_lpuart0    */
  kCLOCK_MAIN_hsp_lpuart1                      = 63, /*!< Clock LPCG Main SS index 31 hsp_lpuart1    */
  kCLOCK_MAIN_hsp_lpuart2                      = 64, /*!< Clock LPCG Main SS index 32 hsp_lpuart2    */
  kCLOCK_MAIN_hsp_lpuart3                      = 65, /*!< Clock LPCG Main SS index 33 hsp_lpuart3    */
  kCLOCK_MAIN_hsp_lpuart4                      = 66, /*!< Clock LPCG Main SS index 34 hsp_lpuart4    */
  kCLOCK_MAIN_hsp_lpuart5                      = 67, /*!< Clock LPCG Main SS index 35 hsp_lpuart5    */
  kCLOCK_MAIN_hsp_flexpwm0                     = 68, /*!< Clock LPCG Main SS index 36 hsp_flexpwm0   */
  kCLOCK_MAIN_hsp_flexpwm1                     = 69, /*!< Clock LPCG Main SS index 37 hsp_flexpwm1   */
  kCLOCK_MAIN_hsp_flexpwm2                     = 70, /*!< Clock LPCG Main SS index 38 hsp_flexpwm2   */
  kCLOCK_MAIN_hsp_flexpwm3                     = 71, /*!< Clock LPCG Main SS index 39 hsp_flexpwm3   */
  kCLOCK_MAIN_hsp_lpit0                        = 72, /*!< Clock LPCG Main SS index 40 hsp_lpit0      */
  kCLOCK_MAIN_hsp_lpit1                        = 73, /*!< Clock LPCG Main SS index 41 hsp_lpit1      */
  kCLOCK_MAIN_hsp_qtpm0                        = 74, /*!< Clock LPCG Main SS index 42 hsp_qtpm0      */
  kCLOCK_MAIN_hsp_qtimer0                      = 75, /*!< Clock LPCG Main SS index 43 hsp_qtimer0    */
  kCLOCK_MAIN_hsp_qtimer1                      = 76, /*!< Clock LPCG Main SS index 44 hsp_qtimer1    */
  kCLOCK_MAIN_hsp_qtimer2                      = 77, /*!< Clock LPCG Main SS index 45 hsp_qtimer2    */
  kCLOCK_MAIN_hsp_qtimer3                      = 78, /*!< Clock LPCG Main SS index 46 hsp_qtimer3    */
  kCLOCK_MAIN_hsp_can0                         = 79, /*!< Clock LPCG Main SS index 47 hsp_can0       */
  kCLOCK_MAIN_hsp_can1                         = 80, /*!< Clock LPCG Main SS index 48 hsp_can1       */
  kCLOCK_MAIN_hsp_can2                         = 81, /*!< Clock LPCG Main SS index 49 hsp_can2       */
  kCLOCK_MAIN_hsp_qdc0                         = 82, /*!< Clock LPCG Main SS index 50 hsp_qdc0       */
  kCLOCK_MAIN_hsp_qdc1                         = 83, /*!< Clock LPCG Main SS index 51 hsp_qdc1       */
  kCLOCK_MAIN_hsp_qdc2                         = 84, /*!< Clock LPCG Main SS index 52 hsp_qdc2       */
  kCLOCK_MAIN_hsp_qdc3                         = 85, /*!< Clock LPCG Main SS index 53 hsp_qdc3       */
  kCLOCK_MAIN_hsp_rgpio0                       = 86, /*!< Clock LPCG Main SS index 54 hsp_rgpio0     */
  kCLOCK_MAIN_hsp_rgpio1                       = 87, /*!< Clock LPCG Main SS index 55 hsp_rgpio1     */
  kCLOCK_MAIN_hsp_rgpio2                       = 88, /*!< Clock LPCG Main SS index 56 hsp_rgpio2     */
  kCLOCK_MAIN_hsp_rgpio3                       = 89, /*!< Clock LPCG Main SS index 57 hsp_rgpio3     */
  kCLOCK_MAIN_hsp_rgpio4                       = 90, /*!< Clock LPCG Main SS index 58 hsp_rgpio4     */
  kCLOCK_MAIN_hsp_i3c0                         = 91, /*!< Clock LPCG Main SS index 59 hsp_i3c0       */
  kCLOCK_MAIN_hsp_flexio0                      = 92, /*!< Clock LPCG Main SS index 60 hsp_flexio0    */
  kCLOCK_MAIN_hsp_flexio1                      = 93, /*!< Clock LPCG Main SS index 61 hsp_flexio1    */
  kCLOCK_MAIN_hsp_flexio2                      = 94, /*!< Clock LPCG Main SS index 62 hsp_flexio2    */
  kCLOCK_MAIN_hsp_sinc0                        = 95, /*!< Clock LPCG Main SS index 63 hsp_sinc0      */
  kCLOCK_MAIN_hsp_sinc1                        = 96, /*!< Clock LPCG Main SS index 64 hsp_sinc1      */
  kCLOCK_MAIN_mtr_master                       = 97,  /*!< Clock LPCG Main SS index 65 mtr_master     */
  kCLOCK_MAIN_iomuxc                           = 98,  /*!< Clock LPCG Main SS index 66 main_iomuxc    */
  kCLOCK_MAIN_hsp_trig_sync0                   = 99,  /*!< Clock LPCG Main SS index 67 hsp_trig_sync0 */
  kCLOCK_MAIN_hsp_trig_sync1                   = 100, /*!< Clock LPCG Main SS index 68 hsp_trig_sync1 */
  kCLOCK_MAIN_hsp_stm                          = 101, /*!< Clock LPCG Main SS index 69 hsp_stm        */
  kCLOCK_MAIN_hsp_nic_main_gpv                 = 102, /*!< Clock LPCG Main SS index 70 hsp_nic_main_gpv*/
  kCLOCK_MAIN_prince0                          = 103, /*!< Clock LPCG Main SS index 71 main_prince0   */
  kCLOCK_MAIN_prince1                          = 104, /*!< Clock LPCG Main SS index 72 main_prince1   */
  kCLOCK_MAIN_cssi                             = 105, /*!< Clock LPCG Main SS index 73 main_cssi      */
  kCLOCK_MAIN_mmu0                             = 106, /*!< Clock LPCG Main SS index 74 main_mmu0      */
  kCLOCK_MAIN_END                              = 106,
  // Clock LPCG for Wake SS [112..144]
  kCLOCK_WAKE_START                            = 112,
  kCLOCK_WAKE_syscon_pmu                       = 112, /*!< Clock LPCG Wake SS index 0 syscon_pmu      */
  kCLOCK_WAKE_dap_rt2660                       = 113, /*!< Clock LPCG Wake SS index 1 dap_rt2660      */
  kCLOCK_WAKE_edma                             = 114, /*!< Clock LPCG Wake SS index 2 edma            */
  kCLOCK_WAKE_freqme                           = 115, /*!< Clock LPCG Wake SS index 3 freqme          */
  kCLOCK_WAKE_modcon                           = 116, /*!< Clock LPCG Wake SS index 4 modcon          */
  kCLOCK_WAKE_xbar0                            = 117, /*!< Clock LPCG Wake SS index 5 xbar0           */
  kCLOCK_WAKE_trdc                             = 118, /*!< Clock LPCG Wake SS index 6 trdc            */
  kCLOCK_WAKE_syscon_resetcon                  = 119, /*!< Clock LPCG Wake SS index 7 syscon_resetcon */
  kCLOCK_WAKE_syscon_pdcon                     = 120, /*!< Clock LPCG Wake SS index 8 syscon_pdcon    */
  kCLOCK_WAKE_syscon_powercon                  = 121, /*!< Clock LPCG Wake SS index 9 syscon_powercon */
  kCLOCK_WAKE_syscon_memcon                    = 122, /*!< Clock LPCG Wake SS index 10 syscon_memcon  */
  kCLOCK_WAKE_micfil                           = 123, /*!< Clock LPCG Wake SS index 11 micfil         */
  kCLOCK_WAKE_lpspi                            = 124, /*!< Clock LPCG Wake SS index 12 lpspi          */
  kCLOCK_WAKE_lpi2c0                           = 125, /*!< Clock LPCG Wake SS index 13 lpi2c0         */
  kCLOCK_WAKE_lpi2c1                           = 126, /*!< Clock LPCG Wake SS index 14 lpi2c1         */
  kCLOCK_WAKE_lpuart0                          = 127, /*!< Clock LPCG Wake SS index 15 lpuart0        */
  kCLOCK_WAKE_lpuart1                          = 128, /*!< Clock LPCG Wake SS index 16 lpuart1        */
  kCLOCK_WAKE_acmp0                            = 129, /*!< Clock LPCG Wake SS index 17 acmp0          */
  kCLOCK_WAKE_acmp1                            = 130, /*!< Clock LPCG Wake SS index 18 acmp1          */
  kCLOCK_WAKE_acmp2                            = 131, /*!< Clock LPCG Wake SS index 19 acmp2          */
  kCLOCK_WAKE_acmp3                            = 132, /*!< Clock LPCG Wake SS index 20 acmp3          */
  kCLOCK_WAKE_swt0                             = 133, /*!< Clock LPCG Wake SS index 21 swt0           */
  kCLOCK_WAKE_swt1                             = 134, /*!< Clock LPCG Wake SS index 22 swt1           */
  kCLOCK_WAKE_lptimer0                         = 135, /*!< Clock LPCG Wake SS index 23 lptimer0       */
  kCLOCK_WAKE_lptimer1                         = 136, /*!< Clock LPCG Wake SS index 24 lptimer1       */
  kCLOCK_WAKE_qtpm                             = 137, /*!< Clock LPCG Wake SS index 25 qtpm           */
  kCLOCK_WAKE_ewm                              = 138, /*!< Clock LPCG Wake SS index 26 ewm            */
  kCLOCK_WAKE_rgpio0                           = 139, /*!< Clock LPCG Wake SS index 27 rgpio0         */
  kCLOCK_WAKE_i3c0                             = 140, /*!< Clock LPCG Wake SS index 28 i3c0           */
  kCLOCK_WAKE_ram_ctrl                         = 141, /*!< Clock LPCG Wake SS index 29 ram_ctrl       */
  kCLOCK_WAKE_iomuxc                           = 142, /*!< Clock LPCG Wake SS index 30 iomuxc         */
  kCLOCK_WAKE_vbat_rtc_hp                      = 143, /*!< Clock LPCG Wake SS index 31 vbat_rtc_hp    */
  kCLOCK_WAKE_trig_sync                        = 144, /*!< Clock LPCG Wake SS index 32 trig_sync      */
  kCLOCK_WAKE_END                              = 144,
  // Clock LPCG for Comm Subsystem [160..172]
  kCLOCK_COMM_START                            = 160,
  kCLOCK_COMM_xspir                            = 160,  /*!< Clock LPCG Comm SS index 0 xspir           */
  kCLOCK_COMM_eth0                             = 161,  /*!< Clock LPCG Comm SS index 1 eth0            */
  kCLOCK_COMM_eth1                             = 162,  /*!< Clock LPCG Comm SS index 2 eth1            */
  kCLOCK_COMM_usdhc0                           = 163,  /*!< Clock LPCG Comm SS index 3 usdhc0          */
  kCLOCK_COMM_usdhc1                           = 164,  /*!< Clock LPCG Comm SS index 4 usdhc1          */
  kCLOCK_COMM_usb0                             = 165,  /*!< Clock LPCG Comm SS index 5 usb0            */
  kCLOCK_COMM_usb1                             = 166,  /*!< Clock LPCG Comm SS index 6 usb1            */
  kCLOCK_COMM_xenophy0                         = 167,  /*!< Clock LPCG Comm SS index 7 xenophy0        */
  kCLOCK_COMM_xenophy1                         = 168,  /*!< Clock LPCG Comm SS index 8 xenophy1        */
  kCLOCK_COMM_freqme                           = 169,  /*!< Clock LPCG Comm SS index 9 freqme          */
  kCLOCK_COMM_modcon                           = 170,  /*!< Clock LPCG Comm SS index 10 modcon         */
  kCLOCK_COMM_trdc                             = 171,  /*!< Clock LPCG Comm SS index 11 trdc           */
  kCLOCK_COMM_nic_gpv                          = 172,  /*!< Clock LPCG Comm SS index 12 nic_gpv        */
  kCLOCK_COMM_END                              = 172,
  // Clock LPCG for Audio Subsystem [176..188]
  kCLOCK_AUDIO_START                           = 176,
  kCLOCK_AUDIO_edma                            = 176,  /*!< Clock LPCG Audio SS index 0 edma           */
  kCLOCK_AUDIO_freqme                          = 177,  /*!< Clock LPCG Audio SS index 1 freqme         */
  kCLOCK_AUDIO_modcon                          = 178,  /*!< Clock LPCG Audio SS index 2 modcon         */
  kCLOCK_AUDIO_xbar0                           = 179,  /*!< Clock LPCG Audio SS index 3 xbar0          */
  kCLOCK_AUDIO_trdc                            = 180,  /*!< Clock LPCG Audio SS index 4 trdc           */
  kCLOCK_AUDIO_sai0                            = 181,  /*!< Clock LPCG Audio SS index 5 sai0           */
  kCLOCK_AUDIO_sai1                            = 182,  /*!< Clock LPCG Audio SS index 6 sai1           */
  kCLOCK_AUDIO_sai2                            = 183,  /*!< Clock LPCG Audio SS index 7 sai2           */
  kCLOCK_AUDIO_micfil                          = 184,  /*!< Clock LPCG Audio SS index 8 micfil         */
  kCLOCK_AUDIO_asrc                            = 185,  /*!< Clock LPCG Audio SS index 9 asrc           */
  kCLOCK_AUDIO_spdif_xcvr                      = 186,  /*!< Clock LPCG Audio SS index 10 spdif_xcvr    */
  kCLOCK_AUDIO_mqs                             = 187,  /*!< Clock LPCG Audio SS index 11 mqs           */
  kCLOCK_AUDIO_ram_ctrl                        = 188,  /*!< Clock LPCG Audio SS index 12 ram_ctrl      */
  kCLOCK_AUDIO_END                             = 188,
  // Clock LPCG for Media Subsystem [192..203]
  kCLOCK_MEDIA_START                           = 192,
  kCLOCK_MEDIA_jpeg_decoder                    = 192, /*!< Clock LPCG Media SS index 0 jpeg_decoder   */
  kCLOCK_MEDIA_isi                             = 193, /*!< Clock LPCG Media SS index 1 isi            */
  kCLOCK_MEDIA_reformatter                     = 194, /*!< Clock LPCG Media SS index 2 reformatter    */
  kCLOCK_MEDIA_csi                             = 195, /*!< Clock LPCG Media SS index 3 csi            */
  kCLOCK_MEDIA_mipi_csi                        = 196, /*!< Clock LPCG Media SS index 4 mipi_csi       */
  kCLOCK_MEDIA_gpu                             = 197, /*!< Clock LPCG Media SS index 5 gpu            */
  kCLOCK_MEDIA_dcif                            = 198, /*!< Clock LPCG Media SS index 6 dcif           */
  kCLOCK_MEDIA_mipi_dsi                        = 199, /*!< Clock LPCG Media SS index 7 mipi_dsi       */
  kCLOCK_MEDIA_freqme                          = 200, /*!< Clock LPCG Media SS index 8 freqme         */
  kCLOCK_MEDIA_modcon                          = 201, /*!< Clock LPCG Media SS index 9 modcon         */
  kCLOCK_MEDIA_trdc                            = 202, /*!< Clock LPCG Media SS index 10 trdc          */
  kCLOCK_MEDIA_nic_gpv                         = 203, /*!< Clock LPCG Media SS index 11 nic_gpv       */
  kCLOCK_MEDIA_END                             = 203,
  // Clock LPCG for NA Nodes
  kCLOCK_IpInvalid, /*!< Invalid value. */
} clock_lpcg_t;

#define kCLOCK_Ewm0     kCLOCK_WAKE_ewm

/*!
 * @brief Root clock index
 *
 */
typedef enum _clock_root {
  // Clock Root for CGU SS
  kCLOCK_Root_CGU_START                    = 0,
  kCLOCK_Root_CGU_SXOSC_ROOTCLK            = 0,   /*!< Clock Root CGU SS index 0 SXOSC_ROOTCLK */
  kCLOCK_Root_CGU_BASE_CLK                 = 1,   /*!< Clock Root CGU SS index 1 BASE_CLK */
  kCLOCK_Root_CGU_LOW_CLK                  = 2,   /*!< Clock Root CGU SS index 2 LOW_CLK */
  kCLOCK_Root_CGU_MAINPLL_DIVX             = 3,   /*!< Clock Root CGU SS index 3 MAINPLL_DIVX */
  kCLOCK_Root_CGU_SYSPLL_DIVX              = 4,   /*!< Clock Root CGU SS index 4 SYSPLL_DIVX */
  kCLOCK_Root_CGU_PLL_PFDX                 = 5,   /*!< Clock Root CGU SS index 5 PLL_PFDX */
  kCLOCK_Root_CGU_MEDIA_PFDX               = 6,   /*!< Clock Root CGU SS index 6 MEDIA_PFDX */
  kCLOCK_Root_CGU_MAINPFDX_ROOTCLK         = 7,   /*!< Clock Root CGU SS index 7 MAINPFDX_ROOTCLK */
  kCLOCK_Root_CGU_COMMPFDX_ROOTCLK         = 8,   /*!< Clock Root CGU SS index 8 COMMPFDX_ROOTCLK */
  kCLOCK_Root_CGU_MAINDIVX_ROOTCLK         = 9,   /*!< Clock Root CGU SS index 9 MAINDIVX_ROOTCLK */
  kCLOCK_Root_CGU_SAIMCLK_ROOTCLK          = 10,  /*!< Clock Root CGU SS index 10 SAIMCLK_ROOTCLK */
  kCLOCK_Root_CGU_SAIMCLK0_ROOTCLK         = 11,  /*!< Clock Root CGU SS index 11 SAIMCLK0_ROOTCLK */
  kCLOCK_Root_CGU_SAIMCLK1_ROOTCLK         = 12,  /*!< Clock Root CGU SS index 12 SAIMCLK1_ROOTCLK */
  kCLOCK_Root_CGU_SAIMCLK2_ROOTCLK         = 13,  /*!< Clock Root CGU SS index 13 SAIMCLK2_ROOTCLK */
  kCLOCK_Root_CGU_LP12M_CORE_ROOTCLK       = 14,  /*!< Clock Root CGU SS index 14 LP12M_CORE_ROOTCLK */
  kCLOCK_Root_CGU_LP1M_CORE_ROOTCLK        = 15,  /*!< Clock Root CGU SS index 15 LP1M_CORE_ROOTCLK */
  kCLOCK_Root_CGU_ULP32K_ROOTCLK           = 16,  /*!< Clock Root CGU SS index 16 ULP32K_ROOTCLK */
  kCLOCK_Root_CGU_FRO192M_ROOTCLK          = 17,  /*!< Clock Root CGU SS index 17 FRO192M_ROOTCLK */
  kCLOCK_Root_CGU_FRO96M_ROOTCLK           = 18,  /*!< Clock Root CGU SS index 18 FRO96M_ROOTCLK */
  kCLOCK_Root_CGU_FRO48M_ROOTCLK           = 19,  /*!< Clock Root CGU SS index 19 FRO48M_ROOTCLK */
  kCLOCK_Root_CGU_FRO24M_ROOTCLK           = 20,  /*!< Clock Root CGU SS index 20 FRO24M_ROOTCLK */
  kCLOCK_Root_CGU_SYSPLLDIV4_ROOTCLK       = 21,  /*!< Clock Root CGU SS index 21 SYSPLLDIV4_ROOTCLK */
  kCLOCK_Root_CGU_SYSPLLDIV5_ROOTCLK       = 22,  /*!< Clock Root CGU SS index 22 SYSPLLDIV5_ROOTCLK */
  kCLOCK_Root_CGU_SYSPLLDIVX_ROOTCLK       = 23,  /*!< Clock Root CGU SS index 23 SYSPLLDIVX_ROOTCLK */
  kCLOCK_Root_CGU_MAINPLLDIVX_ROOTCLK      = 24,  /*!< Clock Root CGU SS index 24 MAINPLLDIVX_ROOTCLK */
  kCLOCK_Root_CGU_MAINPLLDIV8_ROOTCLK      = 25,  /*!< Clock Root CGU SS index 25 MAINPLLDIV8_ROOTCLK */
  kCLOCK_Root_CGU_MAINPLLDIV10_ROOTCLK     = 26,  /*!< Clock Root CGU SS index 26 MAINPLLDIV10_ROOTCLK */
  kCLOCK_Root_CGU_MAINPLLDIV20_ROOTCLK     = 27,  /*!< Clock Root CGU SS index 27 MAINPLLDIV20_ROOTCLK */
  kCLOCK_Root_CGU_AUDIOPLL_ROOTCLK         = 28,  /*!< Clock Root CGU SS index 28 AUDIOPLL_ROOTCLK */
  kCLOCK_Root_CGU_VIDEOPLL_ROOTCLK         = 29,  /*!< Clock Root CGU SS index 29 VIDEOPLL_ROOTCLK */
  kCLOCK_Root_CGU_MAIN_ROOTCLK             = 30,  /*!< Clock Root CGU SS index 30 MAIN_ROOTCLK (renamed from CPU_ROOTCLK; CGU ROOT 30 feeds both CMPT ROOT 0 MAIN (after div+sndDiv) and CMPT ROOT 1 CPU (after div only) -- see CLOCK_GetClockSrcFreq sndDiv special case for kCLOCK_SRC_CPU) */
  kCLOCK_Root_CGU_NPU_ROOTCLK              = 31,  /*!< Clock Root CGU SS index 31 NPU_ROOTCLK */
  kCLOCK_Root_CGU_MEDIABUS_ROOTCLK         = 32,  /*!< Clock Root CGU SS index 32 MEDIABUS_ROOTCLK */
  kCLOCK_Root_CGU_AUDIOBUS_ROOTCLK         = 33,  /*!< Clock Root CGU SS index 33 AUDIOBUS_ROOTCLK */
  kCLOCK_Root_CGU_COMMBUS_ROOTCLK          = 34,  /*!< Clock Root CGU SS index 34 COMMBUS_ROOTCLK */
  kCLOCK_Root_CGU_WAKEBUS_ROOTCLK          = 35,  /*!< Clock Root CGU SS index 35 WAKEBUS_ROOTCLK */
  kCLOCK_Root_CGU_SYSCON_PDMAIN_CLK        = 36,  /*!< Clock Root CGU SS index 36 SYSCON_PDMAIN_CLK */
  kCLOCK_Root_CGU_PERI_ROOTCLK0            = 37,  /*!< Clock Root CGU SS index 37 PERI_ROOTCLK0 */
  kCLOCK_Root_CGU_PERI_ROOTCLK1            = 38,  /*!< Clock Root CGU SS index 38 PERI_ROOTCLK1 */
  kCLOCK_Root_CGU_PERI_ROOTCLK2            = 39,  /*!< Clock Root CGU SS index 39 PERI_ROOTCLK2 */
  kCLOCK_Root_CGU_PERI_ROOTCLK3            = 40,  /*!< Clock Root CGU SS index 40 PERI_ROOTCLK3 */
  kCLOCK_Root_CGU_PERI_ROOTCLK4            = 41,  /*!< Clock Root CGU SS index 41 PERI_ROOTCLK4 */
  kCLOCK_Root_CGU_PERI_ROOTCLK5            = 42,  /*!< Clock Root CGU SS index 42 PERI_ROOTCLK5 */
  kCLOCK_Root_CGU_PERI_ROOTCLK6            = 43,  /*!< Clock Root CGU SS index 43 PERI_ROOTCLK6 */
  kCLOCK_Root_CGU_PERI_ROOTCLK7            = 44,  /*!< Clock Root CGU SS index 44 PERI_ROOTCLK7 */
  kCLOCK_Root_CGU_AUDIO_ROOTCLK            = 45,  /*!< Clock Root CGU SS index 45 AUDIO_ROOTCLK */
  kCLOCK_Root_CGU_VIDEO_ROOTCLK            = 46,  /*!< Clock Root CGU SS index 46 VIDEO_ROOTCLK */
  kCLOCK_Root_CGU_USB1_ROOTCLK             = 47,  /*!< Clock Root CGU SS index 47 USB1_ROOTCLK */
  kCLOCK_Root_CGU_ETH_ROOTCLK              = 48,  /*!< Clock Root CGU SS index 48 ETH_ROOTCLK */
#if 0
  kCLOCK_Root_CGU_TEST_ROOTCLK             = 49,  /*!< Clock Root CGU SS index 49 TEST_ROOTCLK */
  kCLOCK_Root_CGU_CLKOUT                   = 50,  /*!< Clock Root CGU SS index 50 CLKOUT */
  kCLOCK_Root_CGU_MAIN_FRO192M             = 51,  /*!< Clock Root CGU SS index 51 MAIN_FRO192M */
  kCLOCK_Root_CGU_MAIN_ULP32K              = 52,  /*!< Clock Root CGU SS index 52 MAIN_ULP32K */
  kCLOCK_Root_CGU_END                      = 52,
#else
  kCLOCK_Root_CGU_END                      = 48,
#endif
  // Clock Root for Cmpt SS
  kCLOCK_Root_CMPT_START                   = 64,
  kCLOCK_Root_CMPT_cmpt_clk                = 64,  /*!< Clock Root Cmpt SS index 0 cmpt_clk (MAIN_ROOTCLK) */
  kCLOCK_Root_CMPT_cpu_clk                 = 65,  /*!< Clock Root Cmpt SS index 1 cpu_clk (CPU_ROOTCLK)   */
  kCLOCK_Root_CMPT_npu_clk                 = 66,  /*!< Clock Root Cmpt SS index 2 npu_clk (NPU_ROOTCLK)   */
  kCLOCK_Root_CMPT_systick_clk0            = 67,  /*!< Clock Root Cmpt SS index 3 systick_clk0            */
  kCLOCK_Root_CMPT_systick_clk1            = 68,  /*!< Clock Root Cmpt SS index 4 systick_clk1            */
  kCLOCK_Root_CMPT_END                     = 68,
  // Clock Root for Main SS
  kCLOCK_Root_MAIN_START                   = 80,
  kCLOCK_Root_MAIN_main_clk_divided        = 80, /*!< Clock Root Main SS index 0 main_clk_divided        */
  kCLOCK_Root_MAIN_xspi0_fclk_divided      = 81, /*!< Clock Root Main SS index 1 xspi0_fclk_divided      */
  kCLOCK_Root_MAIN_xspi1_fclk_divided      = 82, /*!< Clock Root Main SS index 2 xspi1_fclk_divided      */
  kCLOCK_Root_MAIN_i3c0_fclk               = 83, /*!< Clock Root Main SS index 3 i3c0_fclk               */
  kCLOCK_Root_MAIN_lpi2c0_fclk             = 84, /*!< Clock Root Main SS index 4 lpi2c0_fclk             */
  kCLOCK_Root_MAIN_lpi2c1_fclk             = 85, /*!< Clock Root Main SS index 5 lpi2c1_fclk             */
  kCLOCK_Root_MAIN_lpspi0_fclk             = 86, /*!< Clock Root Main SS index 6 lpspi0_fclk             */
  kCLOCK_Root_MAIN_lpspi1_fclk             = 87, /*!< Clock Root Main SS index 7 lpspi1_fclk             */
  kCLOCK_Root_MAIN_lpspi2_fclk             = 88, /*!< Clock Root Main SS index 8 lpspi2_fclk             */
  kCLOCK_Root_MAIN_lpspi3_fclk             = 89, /*!< Clock Root Main SS index 9 lpspi3_fclk             */
  kCLOCK_Root_MAIN_lpspi4_fclk             = 90, /*!< Clock Root Main SS index 10 lpspi4_fclk            */
  kCLOCK_Root_MAIN_lpuart0_fclk            = 91, /*!< Clock Root Main SS index 11 lpuart0_fclk           */
  kCLOCK_Root_MAIN_lpuart1_fclk            = 92, /*!< Clock Root Main SS index 12 lpuart1_fclk           */
  kCLOCK_Root_MAIN_lpuart2_fclk            = 93, /*!< Clock Root Main SS index 13 lpuart2_fclk           */
  kCLOCK_Root_MAIN_lpuart3_fclk            = 94, /*!< Clock Root Main SS index 14 lpuart3_fclk           */
  kCLOCK_Root_MAIN_lpuart4_fclk            = 95, /*!< Clock Root Main SS index 15 lpuart4_fclk           */
  kCLOCK_Root_MAIN_lpuart5_fclk            = 96, /*!< Clock Root Main SS index 16 lpuart5_fclk           */
  kCLOCK_Root_MAIN_flexcan0_fclk           = 97, /*!< Clock Root Main SS index 17 flexcan0_fclk          */
  kCLOCK_Root_MAIN_flexcan1_fclk           = 98, /*!< Clock Root Main SS index 18 flexcan1_fclk          */
  kCLOCK_Root_MAIN_flexcan2_fclk           = 99, /*!< Clock Root Main SS index 19 flexcan2_fclk          */
  kCLOCK_Root_MAIN_flexcan_gfclk           = 100, /*!< Clock Root Main SS index 20 flexcan_gfclk         */
  kCLOCK_Root_MAIN_qtpm0_fclk              = 101, /*!< Clock Root Main SS index 21 TBD0                  */
  kCLOCK_Root_MAIN_lpit0_fclk              = 102, /*!< Clock Root Main SS index 22 lpit0_fclk            */
  kCLOCK_Root_MAIN_lpit1_fclk              = 103, /*!< Clock Root Main SS index 23 lpit1_fclk            */
  kCLOCK_Root_MAIN_adc0_fclk               = 104, /*!< Clock Root Main SS index 24 adc0_fclk             */
  kCLOCK_Root_MAIN_adc1_fclk               = 105, /*!< Clock Root Main SS index 25 adc1_fclk             */
  kCLOCK_Root_MAIN_sinc0_fclk              = 106, /*!< Clock Root Main SS index 26 sinc0_fclk            */
  kCLOCK_Root_MAIN_sinc1_fclk              = 107, /*!< Clock Root Main SS index 27 sinc1_fclk            */
  kCLOCK_Root_MAIN_flexio0_fclk            = 108, /*!< Clock Root Main SS index 28 flexio0_fclk          */
  kCLOCK_Root_MAIN_flexio1_fclk            = 109, /*!< Clock Root Main SS index 29 flexio1_fclk          */
  kCLOCK_Root_MAIN_flexio2_fclk            = 110, /*!< Clock Root Main SS index 30 flexio2_fclk          */
  kCLOCK_Root_MAIN_tpiu_clk                = 111, /*!< Clock Root Main SS index 31 tpiu_clk              */
  kCLOCK_Root_MAIN_cssi_refclk             = 112, /*!< Clock Root Main SS index 32 cssi_refclk           */
  kCLOCK_Root_MAIN_otp_clk                 = 113, /*!< Clock Root Main SS index 33 otp_clk               */
  kCLOCK_Root_MAIN_clkout	               = 114, /*!< Clock Root Main SS index 34 clkout                */
  kCLOCK_Root_MAIN_fro192m	               = 115, /*!< Clock Root Main SS index 35 clkout                */
  kCLOCK_Root_MAIN_ulp32k                  = 116, /*!< Clock Root Main SS index 36 clkout                */
  kCLOCK_Root_MAIN_END                     = 116,
  // Clock Root for Wake SS
  kCLOCK_Root_WAKE_START                   = 128,
  kCLOCK_Root_WAKE_wake_clk                = 128, /*!< Clock Root Wake SS index 0 wake_clk                */
  kCLOCK_Root_WAKE_wake_sxosc              = 129, /*!< Clock Root Wake SS index 1 wake_sxosc              */
  kCLOCK_Root_WAKE_wake_lp1m               = 130, /*!< Clock Root Wake SS index 2 wake_lp1m               */
  kCLOCK_Root_WAKE_wake_lp12m              = 131, /*!< Clock Root Wake SS index 3 wake_lp12m              */
  kCLOCK_Root_WAKE_wake_ulp32k             = 132, /*!< Clock Root Wake SS index 4 wake_ulp32k             */
  kCLOCK_Root_WAKE_wake_lpclk              = 133, /*!< Clock Root Wake SS index 5 wake_lpclk              */
  kCLOCK_Root_WAKE_i3c0_fclk               = 134, /*!< Clock Root Wake SS index 6 i3c0_fclk               */
  kCLOCK_Root_WAKE_lpi2c0_fclk             = 135, /*!< Clock Root Wake SS index 7 lpi2c0_fclk             */
  kCLOCK_Root_WAKE_lpi2c1_fclk             = 136, /*!< Clock Root Wake SS index 8 lpi2c1_fclk             */
  kCLOCK_Root_WAKE_lpspi0_fclk             = 137, /*!< Clock Root Wake SS index 9 lpspi0_fclk             */
  kCLOCK_Root_WAKE_lpuart0_fclk            = 138, /*!< Clock Root Wake SS index 10 lpuart0_fclk           */
  kCLOCK_Root_WAKE_lpuart1_fclk            = 139, /*!< Clock Root Wake SS index 11 lpuart1_fclk           */
  kCLOCK_Root_WAKE_dmic1_appclk            = 140, /*!< Clock Root Wake SS index 12 dmic1_appclk           */
  kCLOCK_Root_WAKE_qtpm0_fclk              = 141, /*!< Clock Root Wake SS index 13 qtpm0_fclk             */
  kCLOCK_Root_WAKE_lptmr0_fclk             = 142, /*!< Clock Root Wake SS index 14 lptmr0_fclk            */
  kCLOCK_Root_WAKE_lptmr1_fclk             = 143, /*!< Clock Root Wake SS index 15 lptmr1_fclk            */
  kCLOCK_Root_WAKE_swt0_fclk               = 144, /*!< Clock Root Wake SS index 16 swt0_fclk              */
  kCLOCK_Root_WAKE_swt1_fclk               = 145, /*!< Clock Root Wake SS index 17 swt1_fclk              */
  kCLOCK_Root_WAKE_ewm_fclk                = 146, /*!< Clock Root Wake SS index 18 ewm_fclk               */
  kCLOCK_Root_WAKE_acmp0_fclk              = 147, /*!< Clock Root Wake SS index 19 acmp0_fclk             */
  kCLOCK_Root_WAKE_acmp1_fclk              = 148, /*!< Clock Root Wake SS index 20 acmp1_fclk             */
  kCLOCK_Root_WAKE_acmp2_fclk              = 149, /*!< Clock Root Wake SS index 21 acmp2_fclk             */
  kCLOCK_Root_WAKE_acmp3_fclk              = 150, /*!< Clock Root Wake SS index 22 acmp3_fclk             */
  kCLOCK_Root_WAKE_acmp0_rrclk             = 151, /*!< Clock Root Wake SS index 23 acmp0_rrclk            */
  kCLOCK_Root_WAKE_acmp1_rrclk             = 152, /*!< Clock Root Wake SS index 24 acmp1_rrclk            */
  kCLOCK_Root_WAKE_acmp2_rrclk             = 153, /*!< Clock Root Wake SS index 25 acmp2_rrclk            */
  kCLOCK_Root_WAKE_acmp3_rrclk             = 154, /*!< Clock Root Wake SS index 26 acmp3_rrclk            */
  kCLOCK_Root_WAKE_END                     = 154,
  // Clock Root for Comm SS
  kCLOCK_Root_COMM_START                   = 160,
  kCLOCK_Root_COMM_comm_clk                = 160, /*!< Clock Root Comm SS index 0 comm_clk                */
  kCLOCK_Root_COMM_comm_ulp32k             = 161, /*!< Clock Root Comm SS index 1 comm_ulp32k             */
  kCLOCK_Root_COMM_usdhc0_fclk             = 162, /*!< Clock Root Comm SS index 2 usdhc0_fclk             */
  kCLOCK_Root_COMM_usdhc1_fclk             = 163, /*!< Clock Root Comm SS index 3 usdhc1_fclk             */
  kCLOCK_Root_COMM_xspir_rootclk           = 164, /*!< Clock Root Comm SS index 4 xspir_rootclk           */
  kCLOCK_Root_COMM_usb0_phyclk             = 165, /*!< Clock Root Comm SS index 5 usb0_phyclk             */
  kCLOCK_Root_COMM_usb0_fro48m             = 166, /*!< Clock Root Comm SS index 6 usb0_fro48m             */
  kCLOCK_Root_COMM_usb1_fclk               = 167, /*!< Clock Root Comm SS index 7 usb1_fclk               */
  kCLOCK_Root_COMM_usb0_wakeclk            = 168, /*!< Clock Root Comm SS index 8 usb0_wakeclk            */
  kCLOCK_Root_COMM_eth0_trxclk             = 169, /*!< Clock Root Comm SS index 9 eth0_trxclk             */
  kCLOCK_Root_COMM_eth0_timerclk           = 170, /*!< Clock Root Comm SS index 10 eth0_timerclk          */
  kCLOCK_Root_COMM_eth1_trxclk             = 171, /*!< Clock Root Comm SS index 11 eth1_trxclk            */
  kCLOCK_Root_COMM_eth1_timerclk           = 172, /*!< Clock Root Comm SS index 12 eth1_timerclk          */
  kCLOCK_Root_COMM_eth_refclk              = 173, /*!< Clock Root Comm SS index 13 eth_refclk             */
  kCLOCK_Root_COMM_xeno0_liwclk            = 174, /*!< Clock Root Comm SS index 14 xeno0_liwclk           */
  kCLOCK_Root_COMM_xeno1_liwclk            = 175, /*!< Clock Root Comm SS index 15 xeno1_liwclk           */
  kCLOCK_Root_COMM_dll_refclk              = 176, /*!< Clock Root Comm SS index 16 dll_refclk             */
  kCLOCK_Root_COMM_END                     = 176,
  // Clock Root for Audio SS
  kCLOCK_Root_AUDIO_START                  = 192,
  kCLOCK_Root_AUDIO_audio_clk              = 192,  /*!< Clock Root Audio SS index 0 audio_clk              */
  kCLOCK_Root_AUDIO_dmic0_appclk           = 193,  /*!< Clock Root Audio SS index 1 dmic0_appclk           */
  kCLOCK_Root_AUDIO_sai0_mclk0             = 194,  /*!< Clock Root Audio SS index 2 sai0_mclk0             */
  kCLOCK_Root_AUDIO_sai0_mclk1             = 195,  /*!< Clock Root Audio SS index 3 sai0_mclk1             */
  kCLOCK_Root_AUDIO_sai1_mclk0             = 196,  /*!< Clock Root Audio SS index 4 sai1_mclk0             */
  kCLOCK_Root_AUDIO_sai1_mclk1             = 197,  /*!< Clock Root Audio SS index 5 sai1_mclk1             */
  kCLOCK_Root_AUDIO_sai2_mclk0             = 198,  /*!< Clock Root Audio SS index 6 sai2_mclk0             */
  kCLOCK_Root_AUDIO_sai2_mclk1             = 199,  /*!< Clock Root Audio SS index 7 sai2_mclk1             */
  kCLOCK_Root_AUDIO_spdif_txclk            = 200,  /*!< Clock Root Audio SS index 8 spdif_txclk            */
  kCLOCK_Root_AUDIO_spdif_cdrclk           = 201,  /*!< Clock Root Audio SS index 9 spdif_cdrclk           */
  kCLOCK_Root_AUDIO_asrc_clk               = 202,  /*!< Clock Root Audio SS index 10 asrc_clk              */
  kCLOCK_Root_AUDIO_END                    = 202,
  // Clock Root for Media SS
  kCLOCK_Root_MEDIA_START                  = 208,
  kCLOCK_Root_MEDIA_media_clk              = 208, /*!< Clock Root Media SS index 0 media_clk              */
  kCLOCK_Root_MEDIA_mediapll_clk           = 209, /*!< Clock Root Media SS index 1 mediapll_clk           */
  kCLOCK_Root_MEDIA_mipicsi_escclk         = 210, /*!< Clock Root Media SS index 2 mipicsi_escclk         */
  kCLOCK_Root_MEDIA_mipicsi_clk            = 211, /*!< Clock Root Media SS index 3 mipicsi_clk            */
  kCLOCK_Root_MEDIA_mipidsi_escclk_divided = 212, /*!< Clock Root Media SS index 4 mipidsi_escclk_divided */
  kCLOCK_Root_MEDIA_mipidsi_refclk         = 213, /*!< Clock Root Media SS index 5 mipidsi_refclk         */
  kCLOCK_Root_MEDIA_mipidsi_clk            = 214, /*!< Clock Root Media SS index 6 mipidsi_clk            */
  kCLOCK_Root_MEDIA_reformat_fclk          = 215, /*!< Clock Root Media SS index 7 reformat_fclk          */
  kCLOCK_Root_MEDIA_dcpixel_fclk           = 216, /*!< Clock Root Media SS index 8 dcpixel_fclk           */
  kCLOCK_Root_MEDIA_csi_mclkout            = 217, /*!< Clock Root Media SS index 9 csi_mclkout            */
  kCLOCK_Root_MEDIA_END                    = 217,

  kCLOCK_Root_Invalid                      = 0xFFU, /*!< Sentinel: not a real root. Used by the frequency
                                                         resolver to mark an empty slot in s_clockSrcRootMap. */
} clock_root_t;

/*!
 * @brief The enumerator of clock roots' clock source mux value.
 */
typedef enum _clock_root_mux_source {
    /*
     * CGU Clock Roots
     */
    /* CGU ROOT 0 SXOSC */
    kCLOCK_SXOSC_ClockRoot_OSC_24M               = 0U, /*!< SXOSC mux from OSC_24M               */

    /* CGU ROOT 1 BASE */
    kCLOCK_BASE_ClockRoot_FRO_192M               = 0U, /*!< BASE mux from FRO_192M               */
    kCLOCK_BASE_ClockRoot_OSC_24M                = 1U, /*!< BASE mux from OSC_24M                */
    kCLOCK_BASE_ClockRoot_LPOSC_12M_CORE         = 2U, /*!< BASE mux from LPOSC_12M_CORE         */
    kCLOCK_BASE_ClockRoot_LPOSC_1M_CORE          = 3U, /*!< BASE mux from LPOSC_1M_CORE          */

    /* CGU ROOT 2 LOW */
    kCLOCK_LOW_ClockRoot_FRO_24M                 = 0U, /*!< LOW mux from FRO_24M                 */
    kCLOCK_LOW_ClockRoot_OSC_24M                 = 1U, /*!< LOW mux from OSC_24M                 */
    kCLOCK_LOW_ClockRoot_LPOSC_12M_CORE          = 2U, /*!< LOW mux from LPOSC_12M_CORE          */
    kCLOCK_LOW_ClockRoot_LPOSC_1M_CORE           = 3U, /*!< LOW mux from LPOSC_1M_CORE           */

    /* CGU ROOT 3 MAINPLL_DIVX */
    kCLOCK_MAINPLL_DIVX_ClockRoot_MAINPLL_DIV4   = 0U, /*!< MAINPLL_DIVX mux from MAINPLL_DIV4   */
    kCLOCK_MAINPLL_DIVX_ClockRoot_MAINPLL_DIV5   = 1U, /*!< MAINPLL_DIVX mux from MAINPLL_DIV5   */

    /* CGU ROOT 4 SYSPLL_DIVX */
    kCLOCK_SYSPLL_DIVX_ClockRoot_SYSPLL_DIV4     = 0U, /*!< SYSPLL_DIVX mux from SYSPLL_DIV4     */
    kCLOCK_SYSPLL_DIVX_ClockRoot_SYSPLL_DIV5     = 1U, /*!< SYSPLL_DIVX mux from SYSPLL_DIV5     */

    /* CGU ROOT 5 PLL_PFDX */
    kCLOCK_PLL_PFDX_ClockRoot_MAINPLL_DIVOUT1    = 0U, /*!< PLL_PFDX mux from MAINPLL_DIVOUT1    */
    kCLOCK_PLL_PFDX_ClockRoot_MAINPLL_DIVOUT2    = 1U, /*!< PLL_PFDX mux from MAINPLL_DIVOUT2    */
    kCLOCK_PLL_PFDX_ClockRoot_SYSPLL_DIVOUT1     = 2U, /*!< PLL_PFDX mux from SYSPLL_DIVOUT1     */
    kCLOCK_PLL_PFDX_ClockRoot_SYSPLL_DIVOUT2     = 3U, /*!< PLL_PFDX mux from SYSPLL_DIVOUT2     */

    /* CGU ROOT 6 MEDIA_PFDX */
    kCLOCK_MEDIA_PFDX_ClockRoot_MAINPLL_DIVOUT1  = 0U, /*!< MEDIA_PFDX mux from MAINPLL_DIVOUT1  */
    kCLOCK_MEDIA_PFDX_ClockRoot_MAINPLL_DIVOUT2  = 1U, /*!< MEDIA_PFDX mux from MAINPLL_DIVOUT2  */
    kCLOCK_MEDIA_PFDX_ClockRoot_SYSPLL_DIVOUT1   = 2U, /*!< MEDIA_PFDX mux from SYSPLL_DIVOUT1   */
    kCLOCK_MEDIA_PFDX_ClockRoot_SYSPLL_DIVOUT2   = 3U, /*!< MEDIA_PFDX mux from SYSPLL_DIVOUT2   */

    /* CGU ROOT 7 MAINPFDX */
    kCLOCK_MAINPFDX_ClockRoot_COREPLL_OUT        = 0U, /*!< MAINPFDX mux from COREPLL_OUT        */
    kCLOCK_MAINPFDX_ClockRoot_MAINPLL_DIVOUT2    = 1U, /*!< MAINPFDX mux from MAINPLL_DIVOUT2    */
    kCLOCK_MAINPFDX_ClockRoot_SYSPLL_DIVOUT1     = 2U, /*!< MAINPFDX mux from SYSPLL_DIVOUT1     */
    kCLOCK_MAINPFDX_ClockRoot_SYSPLL_DIVOUT2     = 3U, /*!< MAINPFDX mux from SYSPLL_DIVOUT2     */

    /* CGU ROOT 8 COMMPFDX */
    kCLOCK_COMMPFDX_ClockRoot_COREPLL_OUT        = 0U, /*!< COMMPFDX mux from COREPLL_OUT        */
    kCLOCK_COMMPFDX_ClockRoot_MAINPLL_DIVOUT2    = 1U, /*!< COMMPFDX mux from MAINPLL_DIVOUT2    */
    kCLOCK_COMMPFDX_ClockRoot_SYSPLL_DIVOUT1     = 2U, /*!< COMMPFDX mux from SYSPLL_DIVOUT1     */
    kCLOCK_COMMPFDX_ClockRoot_SYSPLL_DIVOUT2     = 3U, /*!< COMMPFDX mux from SYSPLL_DIVOUT2     */

    /* CGU ROOT 9 MAINDIVX */
    kCLOCK_MAINDIVX_ClockRoot_MAINPLL_DIV4       = 0U, /*!< MAINDIVX mux from MAINPLL_DIV4       */
    kCLOCK_MAINDIVX_ClockRoot_MAINPLL_DIV5       = 1U, /*!< MAINDIVX mux from MAINPLL_DIV5       */
    kCLOCK_MAINDIVX_ClockRoot_SYSPLL_DIV4        = 2U, /*!< MAINDIVX mux from SYSPLL_DIV4        */
    kCLOCK_MAINDIVX_ClockRoot_SYSPLL_DIV5        = 3U, /*!< MAINDIVX mux from SYSPLL_DIV5        */

    /* CGU ROOT 10 SAIMCLK */
    kCLOCK_SAIMCLK_ClockRoot_SAI0_MCLK           = 0U, /*!< SAIMCLK mux from SAI0_MCLK           */
    kCLOCK_SAIMCLK_ClockRoot_SAI1_MCLK           = 1U, /*!< SAIMCLK mux from SAI1_MCLK           */
    kCLOCK_SAIMCLK_ClockRoot_SAI2_MCLK           = 2U, /*!< SAIMCLK mux from SAI2_MCLK           */
    kCLOCK_SAIMCLK_ClockRoot_LPOSC_12M_CORE      = 3U, /*!< SAIMCLK mux from LPOSC_12M_CORE      */

    /* CGU ROOT 11 SAIMCLK0 */
    kCLOCK_SAIMCLK0_ClockRoot_SAI0_MCLK          = 0U, /*!< SAIMCLK0 mux from SAI0_MCLK          */

    /* CGU ROOT 12 SAIMCLK1 */
    kCLOCK_SAIMCLK1_ClockRoot_SAI1_MCLK          = 0U, /*!< SAIMCLK1 mux from SAI1_MCLK          */

    /* CGU ROOT 13 SAIMCLK2 */
    kCLOCK_SAIMCLK2_ClockRoot_SAI2_MCLK          = 0U, /*!< SAIMCLK2 mux from SAI2_MCLK          */

    /* CGU ROOT 14 LP12M_CORE */
    kCLOCK_LP12M_CORE_ClockRoot_LPOSC_12M_CORE   = 0U, /*!< LP12M_CORE mux from LPOSC_12M_CORE   */

    /* CGU ROOT 15 LP1M_CORE */
    kCLOCK_LP1M_CORE_ClockRoot_LPOSC_1M_CORE     = 0U, /*!< LP1M_CORE mux from LPOSC_1M_CORE     */

    /*CGU ROOT 16 ULP32K */
    kCLOCK_ULP32K_ClockRoot_LPOSC32K             = 0U, /*!< ULP32K mux from LPOSC32K             */

    /*CGU ROOT 17 FRO192M */
    kCLOCK_FRO192M_ClockRoot_FRO_192M            = 0U, /*!< FRO192M mux from FRO_192M            */

    /*CGU ROOT 18 FRO96M */
    kCLOCK_FRO96M_ClockRoot_FRO_96M              = 0U, /*!< FRO96M mux from FRO_96M              */

    /*CGU ROOT 19 FRO48M */
    kCLOCK_FRO48M_ClockRoot_FRO_48M              = 0U, /*!< FRO48M mux from FRO_48M              */

    /*CGU ROOT 20 FRO24M */
    kCLOCK_FRO24M_ClockRoot_FRO_24M              = 0U, /*!< FRO24M mux from FRO_24M              */

    /*CGU ROOT 21 SYSPLLDIV4 */
    kCLOCK_SYSPLLDIV4_ClockRoot_SYSPLL_DIV4      = 0U, /*!< SYSPLLDIV4 mux from SYSPLL_DIV4      */

    /*CGU ROOT 22 SYSPLLDIV5 */
    kCLOCK_SYSPLLDIV5_ClockRoot_SYSPLL_DIV5      = 0U, /*!< SYSPLLDIV5 mux from SYSPLL_DIV5      */

    /*CGU ROOT 23 SYSPLLDIVX */
    kCLOCK_SYSPLLDIVX_ClockRoot_SYSPLL_DIV4      = 0U, /*!< SYSPLLDIVX mux from SYSPLL_DIV4      */
    kCLOCK_SYSPLLDIVX_ClockRoot_SYSPLL_DIV5      = 1U, /*!< SYSPLLDIVX mux from SYSPLL_DIV5      */

    /*CGU ROOT 24 MAINPLLDIVX */
    kCLOCK_MAINPLLDIVX_ClockRoot_MAINPLL_DIV4    = 0U, /*!< MAINPLLDIVX mux from MAINPLL_DIV4    */
    kCLOCK_MAINPLLDIVX_ClockRoot_MAINPLL_DIV5    = 1U, /*!< MAINPLLDIVX mux from MAINPLL_DIV5    */

    /*CGU ROOT 25 MAINPLLDIV8 */
    kCLOCK_MAINPLLDIV8_ClockRoot_MAINPLL_DIV8    = 0U, /*!< MAINPLLDIV8 mux from MAINPLL_DIV8    */

    /*CGU ROOT 26 MAINPLLDIV10 */
    kCLOCK_MAINPLLDIV10_ClockRoot_MAINPLL_DIV10  = 0U, /*!< MAINPLLDIV10 mux from MAINPLL_DIV10  */

    /*CGU ROOT 27 MAINPLLDIV20 */
    kCLOCK_MAINPLLDIV20_ClockRoot_MAINPLL_DIV20  = 0U, /*!< MAINPLLDIV20 mux from MAINPLL_DIV20  */

    /*CGU ROOT 28 AUDIOPLL */
    kCLOCK_AUDIOPLL_ClockRoot_AUDIOPLL_DIVOUT    = 0U, /*!< AUDIOPLL mux from AUDIOPLL_DIVOUT    */

    /*CGU ROOT 29 VIDEOPLL */
    kCLOCK_VIDEOPLL_ClockRoot_VIDEOPLL_DIVOUT    = 0U, /*!< VIDEOPLL mux from VIDEOPLL_DIVOUT    */

    /*CGU ROOT 30 MAIN (was "CPU"; renamed -- this slice feeds both CMPT MAIN and CMPT CPU) */
    kCLOCK_CGU_MAIN_ClockRoot_BASE               = 0U, /*!< CGU MAIN mux from BASE               */
    kCLOCK_CGU_MAIN_ClockRoot_COREPLL_OUT        = 1U, /*!< CGU MAIN mux from COREPLL_OUT        */
    kCLOCK_CGU_MAIN_ClockRoot_MAINPLL_DIVX       = 2U, /*!< CGU MAIN mux from MAINPLL_DIVX       */
    kCLOCK_CGU_MAIN_ClockRoot_PLL_PFDX           = 3U, /*!< CGU MAIN mux from PLL_PFDX           */

    /*CGU ROOT 31 NPU */
    kCLOCK_NPU_ClockRoot_BASE                    = 0U, /*!< NPU mux from BASE                    */
    kCLOCK_NPU_ClockRoot_COREPLL_OUT             = 1U, /*!< NPU mux from COREPLL_OUT             */
    kCLOCK_NPU_ClockRoot_MAINPLL_DIVOUT1         = 2U, /*!< NPU mux from MAINPLL_DIVOUT1         */
    kCLOCK_NPU_ClockRoot_PLL_PFDX                = 3U, /*!< NPU mux from PLL_PFDX                */

    /*CGU ROOT 32 MEDIABUS */
    kCLOCK_MEDIABUS_ClockRoot_BASE               = 0U, /*!< MEDIABUS mux from BASE               */
    kCLOCK_MEDIABUS_ClockRoot_COREPLL_OUT        = 1U, /*!< MEDIABUS mux from COREPLL_OUT        */
    kCLOCK_MEDIABUS_ClockRoot_SYSPLL_DIVOUT2     = 2U, /*!< MEDIABUS mux from SYSPLL_DIVOUT2     */
    kCLOCK_MEDIABUS_ClockRoot_PLL_PFDX           = 3U, /*!< MEDIABUS mux from PLL_PFDX           */

    /*CGU ROOT 33 AUDIOBUS */
    kCLOCK_AUDIOBUS_ClockRoot_BASE               = 0U, /*!< AUDIOBUS mux from BASE               */
    kCLOCK_AUDIOBUS_ClockRoot_SYSPLL_DIVOUT2     = 1U, /*!< AUDIOBUS mux from SYSPLL_DIVOUT2     */
    kCLOCK_AUDIOBUS_ClockRoot_MAINPLL_DIVX       = 2U, /*!< AUDIOBUS mux from MAINPLL_DIVX       */
    kCLOCK_AUDIOBUS_ClockRoot_SYSPLL_DIVX        = 3U, /*!< AUDIOBUS mux from SYSPLL_DIVX        */

    /*CGU ROOT 34 COMMBUS */
    kCLOCK_COMMBUS_ClockRoot_BASE                = 0U, /*!< COMMBUS mux from BASE                */
    kCLOCK_COMMBUS_ClockRoot_SYSPLL_DIVOUT2      = 1U, /*!< COMMBUS mux from SYSPLL_DIVOUT2      */
    kCLOCK_COMMBUS_ClockRoot_MAINPLL_DIVX        = 2U, /*!< COMMBUS mux from MAINPLL_DIVX        */
    kCLOCK_COMMBUS_ClockRoot_SYSPLL_DIVX         = 3U, /*!< COMMBUS mux from SYSPLL_DIVX         */

    /*CGU ROOT 35 WAKEBUS */
    kCLOCK_WAKEBUS_ClockRoot_LOW                 = 0U, /*!< WAKEBUS mux from LOW                 */
    kCLOCK_WAKEBUS_ClockRoot_FRO_192M            = 1U, /*!< WAKEBUS mux from FRO_192M            */
    kCLOCK_WAKEBUS_ClockRoot_MAINPLL_DIVX        = 2U, /*!< WAKEBUS mux from MAINPLL_DIVX        */
    kCLOCK_WAKEBUS_ClockRoot_SYSPLL_DIVOUT2      = 3U, /*!< WAKEBUS mux from SYSPLL_DIVOUT2      */

    /*CGU ROOT 36 SYSCON_PDMAIN */
    kCLOCK_SYSCON_PDMAIN_ClockRoot_LOW           = 0U, /*!< SYSCON_PDMAIN mux from LOW           */
    kCLOCK_SYSCON_PDMAIN_ClockRoot_FRO_48M       = 1U, /*!< SYSCON_PDMAIN mux from FRO_48M       */
    kCLOCK_SYSCON_PDMAIN_ClockRoot_MAINPLL_DIV10 = 2U, /*!< SYSCON_PDMAIN mux from MAINPLL_DIV10 */
    kCLOCK_SYSCON_PDMAIN_ClockRoot_SYSPLL_DIV10  = 3U, /*!< SYSCON_PDMAIN mux from SYSPLL_DIV10  */

    /*CGU ROOT 37 PERI0 */
    kCLOCK_PERI0_ClockRoot_BASE                  = 0U, /*!< PERI0 mux from BASE                  */
    kCLOCK_PERI0_ClockRoot_MAINPLL_DIVOUT0       = 1U, /*!< PERI0 mux from MAINPLL_DIVOUT0       */
    kCLOCK_PERI0_ClockRoot_SYSPLL_DIVOUT0        = 2U, /*!< PERI0 mux from SYSPLL_DIVOUT0        */
    kCLOCK_PERI0_ClockRoot_SYSPLL_DIVOUT1        = 3U, /*!< PERI0 mux from SYSPLL_DIVOUT1        */

    /*CGU ROOT 38 PERI1 */
    kCLOCK_PERI1_ClockRoot_BASE                  = 0U, /*!< PERI1 mux from BASE                  */
    kCLOCK_PERI1_ClockRoot_MAINPLL_DIVOUT1       = 1U, /*!< PERI1 mux from MAINPLL_DIVOUT1       */
    kCLOCK_PERI1_ClockRoot_SYSPLL_DIVOUT0        = 2U, /*!< PERI1 mux from SYSPLL_DIVOUT0        */
    kCLOCK_PERI1_ClockRoot_SYSPLL_DIVOUT1        = 3U, /*!< PERI1 mux from SYSPLL_DIVOUT1        */

    /*CGU ROOT 39 PERI2 */
    kCLOCK_PERI2_ClockRoot_BASE                  = 0U, /*!< PERI2 mux from BASE                  */
    kCLOCK_PERI2_ClockRoot_MAINPLL_DIVOUT2       = 1U, /*!< PERI2 mux from MAINPLL_DIVOUT2       */
    kCLOCK_PERI2_ClockRoot_SYSPLL_DIVOUT0        = 2U, /*!< PERI2 mux from SYSPLL_DIVOUT0        */
    kCLOCK_PERI2_ClockRoot_SYSPLL_DIVOUT2        = 3U, /*!< PERI2 mux from SYSPLL_DIVOUT2        */

    /*CGU ROOT 40 PERI3 */
    kCLOCK_PERI3_ClockRoot_BASE                  = 0U, /*!< PERI3 mux from BASE                  */
    kCLOCK_PERI3_ClockRoot_MAINPLL_DIVOUT2       = 1U, /*!< PERI3 mux from MAINPLL_DIVOUT2       */
    kCLOCK_PERI3_ClockRoot_MAINPLL_DIVX          = 2U, /*!< PERI3 mux from MAINPLL_DIVX          */
    kCLOCK_PERI3_ClockRoot_SYSPLL_DIVOUT2        = 3U, /*!< PERI3 mux from SYSPLL_DIVOUT2        */

    /*CGU ROOT 41 PERI4 */
    kCLOCK_PERI4_ClockRoot_BASE                  = 0U, /*!< PERI4 mux from BASE                  */
    kCLOCK_PERI4_ClockRoot_MAINPLL_DIVOUT0       = 1U, /*!< PERI4 mux from MAINPLL_DIVOUT0       */
    kCLOCK_PERI4_ClockRoot_MAINPLL_DIVX          = 2U, /*!< PERI4 mux from MAINPLL_DIVX          */
    kCLOCK_PERI4_ClockRoot_SYSPLL_DIVOUT2        = 3U, /*!< PERI4 mux from SYSPLL_DIVOUT2        */

    /*CGU ROOT 42 PERI5 */
    kCLOCK_PERI5_ClockRoot_BASE                  = 0U, /*!< PERI5 mux from BASE                  */
    kCLOCK_PERI5_ClockRoot_MAINPLL_DIVOUT0       = 1U, /*!< PERI5 mux from MAINPLL_DIVOUT0       */
    kCLOCK_PERI5_ClockRoot_MAINPLL_DIVX          = 2U, /*!< PERI5 mux from MAINPLL_DIVX          */
    kCLOCK_PERI5_ClockRoot_SYSPLL_DIVOUT2        = 3U, /*!< PERI5 mux from SYSPLL_DIVOUT2        */

    /*CGU ROOT 43 PERI6 */
    kCLOCK_PERI6_ClockRoot_BASE                  = 0U, /*!< PERI6 mux from BASE                  */
    kCLOCK_PERI6_ClockRoot_MAINPLL_DIVOUT1       = 1U, /*!< PERI6 mux from MAINPLL_DIVOUT1       */
    kCLOCK_PERI6_ClockRoot_MAINPLL_DIVX          = 2U, /*!< PERI6 mux from MAINPLL_DIVX          */
    kCLOCK_PERI6_ClockRoot_SYSPLL_DIVOUT2        = 3U, /*!< PERI6 mux from SYSPLL_DIVOUT2        */

    /*CGU ROOT 44 PERI7 */
    kCLOCK_PERI7_ClockRoot_LOW                   = 0U, /*!< PERI7 mux from LOW                   */
    kCLOCK_PERI7_ClockRoot_FRO_192M              = 1U, /*!< PERI7 mux from FRO_192M              */
    kCLOCK_PERI7_ClockRoot_MAINPLL_DIVOUT2       = 2U, /*!< PERI7 mux from MAINPLL_DIVOUT2       */
    kCLOCK_PERI7_ClockRoot_SYSPLL_DIVOUT2        = 3U, /*!< PERI7 mux from SYSPLL_DIVOUT2        */

    /*CGU ROOT 45 AUDIO */
    kCLOCK_AUDIO_ClockRoot_LOW                   = 0U, /*!< AUDIO mux from LOW                   */
    kCLOCK_AUDIO_ClockRoot_AUDIOPLL_DIVOUT       = 1U, /*!< AUDIO mux from AUDIOPLL_DIVOUT       */
    kCLOCK_AUDIO_ClockRoot_VIDEOPLL_DIVOUT       = 2U, /*!< AUDIO mux from VIDEOPLL_DIVOUT       */
    kCLOCK_AUDIO_ClockRoot_SYSPLL_DIVOUT2        = 3U, /*!< AUDIO mux from SYSPLL_DIVOUT2        */

    /*CGU ROOT 46 VIDEO */
    kCLOCK_VIDEO_ClockRoot_BASE                  = 0U, /*!< VIDEO mux from BASE                  */
    kCLOCK_VIDEO_ClockRoot_AUDIOPLL_DIVOUT       = 1U, /*!< VIDEO mux from AUDIOPLL_DIVOUT       */
    kCLOCK_VIDEO_ClockRoot_VIDEOPLL_DIVOUT       = 2U, /*!< VIDEO mux from VIDEOPLL_DIVOUT       */
    kCLOCK_VIDEO_ClockRoot_MEDIA_PFDX            = 3U, /*!< VIDEO mux from MEDIA_PFDX            */

    /*CGU ROOT 47 USB1 */
    kCLOCK_USB1_ClockRoot_FRO_48M                = 0U, /*!< USB1 mux from FRO_48M                */
    kCLOCK_USB1_ClockRoot_MAINPLL_DIVOUT1        = 1U, /*!< USB1 mux from MAINPLL_DIVOUT1        */
    kCLOCK_USB1_ClockRoot_MAINPLL_DIVOUT2        = 2U, /*!< USB1 mux from MAINPLL_DIVOUT2        */
    kCLOCK_USB1_ClockRoot_SYSPLL_DIVOUT2         = 3U, /*!< USB1 mux from SYSPLL_DIVOUT2         */

    /*CGU ROOT 48 ETH */
    kCLOCK_ETH_ClockRoot_BASE                    = 0U, /*!< ETH mux from BASE                    */
    kCLOCK_ETH_ClockRoot_MAINPLL_DIV8            = 1U, /*!< ETH mux from MAINPLL_DIV8            */
    kCLOCK_ETH_ClockRoot_MAINPLL_DIV20           = 2U, /*!< ETH mux from MAINPLL_DIV20           */
    kCLOCK_ETH_ClockRoot_SYSPLL_DIV20            = 3U, /*!< ETH mux from SYSPLL_DIV20            */

#if 0
    /*CGU ROOT 49 TEST */
    kCLOCK_TEST_ClockRoot_TIE_LOW                = 0U, /*!< TEST mux from TIE_LOW                */
    kCLOCK_TEST_ClockRoot_COREPLL_OUT            = 1U, /*!< TEST mux from COREPLL_OUT            */
    kCLOCK_TEST_ClockRoot_MAINPLL_DIVOUT0        = 2U, /*!< TEST mux from MAINPLL_DIVOUT0        */
    kCLOCK_TEST_ClockRoot_SYSPLL_DIVOUT0         = 3U, /*!< TEST mux from SYSPLL_DIVOUT0         */

    /*CGU ROOT 50 CLKOUT */
    kCLOCK_CLKOUT_ClockRoot_PERI3                = 0U, /*!< CLKOUT mux from PERI3                */
    kCLOCK_CLKOUT_ClockRoot_PERI5                = 1U, /*!< CLKOUT mux from PERI5                */
    kCLOCK_CLKOUT_ClockRoot_FRO192M              = 2U, /*!< CLKOUT mux from FRO192M              */
    kCLOCK_CLKOUT_ClockRoot_MAINPLLDIV10         = 3U, /*!< CLKOUT mux from MAINPLLDIV10         */

    /*CGU ROOT 51 MAIN_FRO192M */
    kCLOCK_MAIN_FRO192M_ClockRoot_FRO192M        = 0U, /*!< MAIN_FRO192M mux from FRO192M        */

    /*CGU ROOT 52 MAIN_ULP32K */
    kCLOCK_MAIN_ULP32K_ClockRoot_ULP32K          = 0U, /*!< MAIN_ULP32K mux from ULP32K          */
#endif

    /*
     * CMPT Clock Roots
     */
    /* CMPT ROOT 0 CMPT */
    kCLOCK_CMPT_ClockRoot_MAIN                   = 0U, /*!< CMPT mux from MAIN                   */

    /* CMPT ROOT 1 CPU */
    kCLOCK_CPU_ClockRoot_CPU                     = 0U, /*!< CPU mux from CPU                     */

    /* CMPT ROOT 2 NPU */
    kCLOCK_NPU_ClockRoot_NPU                     = 0U, /*!< NPU mux from NPU                     */

    /* CMPT ROOT 3 SYSTICK0 */
    kCLOCK_SYSTICK0_ClockRoot_LP1M_CORE          = 0U, /*!< SYSTICK0 mux from LP1M_CORE          */
    kCLOCK_SYSTICK0_ClockRoot_SXOSC              = 1U, /*!< SYSTICK0 mux from SXOSC              */
    kCLOCK_SYSTICK0_ClockRoot_PERI4              = 2U, /*!< SYSTICK0 mux from PERI4              */
    kCLOCK_SYSTICK0_ClockRoot_MAINPLLDIV10       = 3U, /*!< SYSTICK0 mux from MAINPLLDIV10       */

    /* CMPT ROOT 4 SYSTICK1 */
    kCLOCK_SYSTICK1_ClockRoot_LP1M_CORE          = 0U, /*!< SYSTICK1 mux from LP1M_CORE          */
    kCLOCK_SYSTICK1_ClockRoot_SXOSC              = 1U, /*!< SYSTICK1 mux from SXOSC              */
    kCLOCK_SYSTICK1_ClockRoot_PERI4              = 2U, /*!< SYSTICK1 mux from PERI4              */
    kCLOCK_SYSTICK1_ClockRoot_MAINPLLDIV10       = 3U, /*!< SYSTICK1 mux from MAINPLLDIV10       */

    /*
     * MAIN Clock Roots
     */
    /* MAIN ROOT 0 MAIN/MAIN_DIV */
    kCLOCK_MAIN_ClockRoot_MAIN                   = 0U, /*!< MAIN mux from MAIN                   */
    kCLOCK_MAIN_ClockRoot_TIE_LOW                = 1U, /*!< MAIN mux from TIE_LOW                */

    /* MAIN ROOT 1 XSPI0 */
    kCLOCK_XSPI0_ClockRoot_MAIN_PERI0_DIV2       = 0U, /*!< XSPI0 mux from MAIN_PERI0_DIV2       */
    kCLOCK_XSPI0_ClockRoot_MAINPFDX_DIV2         = 1U, /*!< XSPI0 mux from MAINPFDX_DIV2         */
    kCLOCK_XSPI0_ClockRoot_SYSPLLDIV4            = 2U, /*!< XSPI0 mux from SYSPLLDIV4            */
    kCLOCK_XSPI0_ClockRoot_SYSPLLDIV5            = 3U, /*!< XSPI0 mux from SYSPLLDIV5            */

    /* MAIN ROOT 2 XSPI1 */
    kCLOCK_XSPI1_ClockRoot_MAIN_PERI1_DIV2       = 0U, /*!< XSPI1 mux from MAIN_PERI1_DIV2       */
    kCLOCK_XSPI1_ClockRoot_MAINPFDX_DIV2         = 1U, /*!< XSPI1 mux from MAINPFDX_DIV2         */
    kCLOCK_XSPI1_ClockRoot_SYSPLLDIV4            = 2U, /*!< XSPI1 mux from SYSPLLDIV4            */
    kCLOCK_XSPI1_ClockRoot_SYSPLLDIV5            = 3U, /*!< XSPI1 mux from SYSPLLDIV5            */

    /* MAIN ROOT 3 I3C0 */
    kCLOCK_I3C0_ClockRoot_PERI3                  = 0U, /*!< I3C0 mux from PERI3                  */
    kCLOCK_I3C0_ClockRoot_PERI4                  = 1U, /*!< I3C0 mux from PERI4                  */
    kCLOCK_I3C0_ClockRoot_FRO192M                = 2U, /*!< I3C0 mux from FRO192M                */
    kCLOCK_I3C0_ClockRoot_SXOSC                  = 3U, /*!< I3C0 mux from SXOSC                  */

    /* MAIN ROOT 4 LPI2C0 */
    kCLOCK_LPI2C0_ClockRoot_PERI3                = 0U, /*!< LPI2C0 mux from PERI3                */
    kCLOCK_LPI2C0_ClockRoot_PERI4                = 1U, /*!< LPI2C0 mux from PERI4                */
    kCLOCK_LPI2C0_ClockRoot_FRO192M              = 2U, /*!< LPI2C0 mux from FRO192M              */
    kCLOCK_LPI2C0_ClockRoot_SXOSC                = 3U, /*!< LPI2C0 mux from SXOSC                */

    /* MAIN ROOT 5 LPI2C1 */
    kCLOCK_LPI2C1_ClockRoot_PERI3                = 0U, /*!< LPI2C1 mux from PERI3                */
    kCLOCK_LPI2C1_ClockRoot_PERI4                = 1U, /*!< LPI2C1 mux from PERI4                */
    kCLOCK_LPI2C1_ClockRoot_FRO192M              = 2U, /*!< LPI2C1 mux from FRO192M              */
    kCLOCK_LPI2C1_ClockRoot_SXOSC                = 3U, /*!< LPI2C1 mux from SXOSC                */

    /* MAIN ROOT 6 LPSPI0 */
    kCLOCK_LPSPI0_ClockRoot_PERI2                = 0U, /*!< LPSPI0 mux from PERI2                */
    kCLOCK_LPSPI0_ClockRoot_PERI4                = 1U, /*!< LPSPI0 mux from PERI4                */
    kCLOCK_LPSPI0_ClockRoot_FRO192M              = 2U, /*!< LPSPI0 mux from FRO192M              */
    kCLOCK_LPSPI0_ClockRoot_MAINDIVX             = 3U, /*!< LPSPI0 mux from MAINDIVX             */

    /* MAIN ROOT 7 LPSPI1 */
    kCLOCK_LPSPI1_ClockRoot_PERI2                = 0U, /*!< LPSPI1 mux from PERI2                */
    kCLOCK_LPSPI1_ClockRoot_PERI4                = 1U, /*!< LPSPI1 mux from PERI4                */
    kCLOCK_LPSPI1_ClockRoot_FRO192M              = 2U, /*!< LPSPI1 mux from FRO192M              */
    kCLOCK_LPSPI1_ClockRoot_MAINDIVX             = 3U, /*!< LPSPI1 mux from MAINDIVX             */

    /* MAIN ROOT 8 LPSPI2 */
    kCLOCK_LPSPI2_ClockRoot_PERI2                = 0U, /*!< LPSPI2 mux from PERI2                */
    kCLOCK_LPSPI2_ClockRoot_PERI4                = 1U, /*!< LPSPI2 mux from PERI4                */
    kCLOCK_LPSPI2_ClockRoot_FRO192M              = 2U, /*!< LPSPI2 mux from FRO192M              */
    kCLOCK_LPSPI2_ClockRoot_MAINDIVX             = 3U, /*!< LPSPI2 mux from MAINDIVX             */

    /* MAIN ROOT 9 LPSPI3 */
    kCLOCK_LPSPI3_ClockRoot_PERI2                = 0U, /*!< LPSPI3 mux from PERI2                */
    kCLOCK_LPSPI3_ClockRoot_PERI4                = 1U, /*!< LPSPI3 mux from PERI4                */
    kCLOCK_LPSPI3_ClockRoot_FRO192M              = 2U, /*!< LPSPI3 mux from FRO192M              */
    kCLOCK_LPSPI3_ClockRoot_MAINDIVX             = 3U, /*!< LPSPI3 mux from MAINDIVX             */

    /* MAIN ROOT 10 LPSPI4 */
    kCLOCK_LPSPI4_ClockRoot_PERI2                = 0U, /*!< LPSPI4 mux from PERI2                */
    kCLOCK_LPSPI4_ClockRoot_PERI4                = 1U, /*!< LPSPI4 mux from PERI4                */
    kCLOCK_LPSPI4_ClockRoot_FRO192M              = 2U, /*!< LPSPI4 mux from FRO192M              */
    kCLOCK_LPSPI4_ClockRoot_MAINDIVX             = 3U, /*!< LPSPI4 mux from MAINDIVX             */

    /* MAIN ROOT 11 LPUART0 */
    kCLOCK_LPUART0_ClockRoot_PERI3               = 0U, /*!< LPUART0 mux from PERI3               */
    kCLOCK_LPUART0_ClockRoot_PERI4               = 1U, /*!< LPUART0 mux from PERI4               */
    kCLOCK_LPUART0_ClockRoot_FRO192M             = 2U, /*!< LPUART0 mux from FRO192M             */
    kCLOCK_LPUART0_ClockRoot_SXOSC               = 3U, /*!< LPUART0 mux from SXOSC               */

    /* MAIN ROOT 12 LPUART1 */
    kCLOCK_LPUART1_ClockRoot_PERI3               = 0U, /*!< LPUART1 mux from PERI3               */
    kCLOCK_LPUART1_ClockRoot_PERI4               = 1U, /*!< LPUART1 mux from PERI4               */
    kCLOCK_LPUART1_ClockRoot_FRO192M             = 2U, /*!< LPUART1 mux from FRO192M             */
    kCLOCK_LPUART1_ClockRoot_SXOSC               = 3U, /*!< LPUART1 mux from SXOSC               */

    /* MAIN ROOT 13 LPUART2 */
    kCLOCK_LPUART2_ClockRoot_PERI3               = 0U, /*!< LPUART2 mux from PERI3               */
    kCLOCK_LPUART2_ClockRoot_PERI4               = 1U, /*!< LPUART2 mux from PERI4               */
    kCLOCK_LPUART2_ClockRoot_FRO192M             = 2U, /*!< LPUART2 mux from FRO192M             */
    kCLOCK_LPUART2_ClockRoot_SXOSC               = 3U, /*!< LPUART2 mux from SXOSC               */

    /* MAIN ROOT 14 LPUART3 */
    kCLOCK_LPUART3_ClockRoot_PERI3               = 0U, /*!< LPUART3 mux from PERI3               */
    kCLOCK_LPUART3_ClockRoot_PERI4               = 1U, /*!< LPUART3 mux from PERI4               */
    kCLOCK_LPUART3_ClockRoot_FRO192M             = 2U, /*!< LPUART3 mux from FRO192M             */
    kCLOCK_LPUART3_ClockRoot_SXOSC               = 3U, /*!< LPUART3 mux from SXOSC               */

    /* MAIN ROOT 15 LPUART4 */
    kCLOCK_LPUART4_ClockRoot_PERI3               = 0U, /*!< LPUART4 mux from PERI3               */
    kCLOCK_LPUART4_ClockRoot_PERI4               = 1U, /*!< LPUART4 mux from PERI4               */
    kCLOCK_LPUART4_ClockRoot_FRO192M             = 2U, /*!< LPUART4 mux from FRO192M             */
    kCLOCK_LPUART4_ClockRoot_SXOSC               = 3U, /*!< LPUART4 mux from SXOSC               */

    /* MAIN ROOT 16 LPUART5 */
    kCLOCK_LPUART5_ClockRoot_PERI3               = 0U, /*!< LPUART5 mux from PERI3               */
    kCLOCK_LPUART5_ClockRoot_PERI4               = 1U, /*!< LPUART5 mux from PERI4               */
    kCLOCK_LPUART5_ClockRoot_FRO192M             = 2U, /*!< LPUART5 mux from FRO192M             */
    kCLOCK_LPUART5_ClockRoot_SXOSC               = 3U, /*!< LPUART5 mux from SXOSC               */

    /* MAIN ROOT 17 FLEXCAN0 */
    kCLOCK_FLEXCAN0_ClockRoot_PERI1              = 0U, /*!< FLEXCAN0 mux from PERI1              */
    kCLOCK_FLEXCAN0_ClockRoot_PERI4              = 1U, /*!< FLEXCAN0 mux from PERI4              */
    kCLOCK_FLEXCAN0_ClockRoot_FRO192M            = 2U, /*!< FLEXCAN0 mux from FRO192M            */
    kCLOCK_FLEXCAN0_ClockRoot_SXOSC              = 3U, /*!< FLEXCAN0 mux from SXOSC              */

    /* MAIN ROOT 18 FLEXCAN1 */
    kCLOCK_FLEXCAN1_ClockRoot_PERI1              = 0U, /*!< FLEXCAN1 mux from PERI1              */
    kCLOCK_FLEXCAN1_ClockRoot_PERI4              = 1U, /*!< FLEXCAN1 mux from PERI4              */
    kCLOCK_FLEXCAN1_ClockRoot_FRO192M            = 2U, /*!< FLEXCAN1 mux from FRO192M            */
    kCLOCK_FLEXCAN1_ClockRoot_SXOSC              = 3U, /*!< FLEXCAN1 mux from SXOSC              */

    /* MAIN ROOT 19 FLEXCAN2 */
    kCLOCK_FLEXCAN2_ClockRoot_PERI1              = 0U, /*!< FLEXCAN2 mux from PERI1              */
    kCLOCK_FLEXCAN2_ClockRoot_PERI4              = 1U, /*!< FLEXCAN2 mux from PERI4              */
    kCLOCK_FLEXCAN2_ClockRoot_FRO192M            = 2U, /*!< FLEXCAN2 mux from FRO192M            */
    kCLOCK_FLEXCAN2_ClockRoot_SXOSC              = 3U, /*!< FLEXCAN2 mux from SXOSC              */

    /* MAIN ROOT 20 FLEXCAN_GFCLK */
    kCLOCK_FLEXCAN_GFCLK_ClockRoot_PERI1         = 0U, /*!< FLEXCAN_GFCLK mux from PERI1         */
    kCLOCK_FLEXCAN_GFCLK_ClockRoot_PERI4         = 1U, /*!< FLEXCAN_GFCLK mux from PERI4         */
    kCLOCK_FLEXCAN_GFCLK_ClockRoot_FRO192M       = 2U, /*!< FLEXCAN_GFCLK mux from FRO192M       */
    kCLOCK_FLEXCAN_GFCLK_ClockRoot_SXOSC         = 3U, /*!< FLEXCAN_GFCLK mux from SXOSC         */

    /* MAIN ROOT 21 QTPM0 */
    kCLOCK_QTPM0_ClockRoot_PERI3                 = 0U, /*!< QTPM0 mux from PERI3                 */
    kCLOCK_QTPM0_ClockRoot_PERI5                 = 1U, /*!< QTPM0 mux from PERI5                 */
    kCLOCK_QTPM0_ClockRoot_FRO192M               = 2U, /*!< QTPM0 mux from FRO192M               */
    kCLOCK_QTPM0_ClockRoot_SXOSC                 = 3U, /*!< QTPM0 mux from SXOSC                 */

    /* MAIN ROOT 22 LPIT0 */
    kCLOCK_LPIT0_ClockRoot_PERI3                 = 0U, /*!< LPIT0 mux from PERI3                 */
    kCLOCK_LPIT0_ClockRoot_PERI5                 = 1U, /*!< LPIT0 mux from PERI5                 */
    kCLOCK_LPIT0_ClockRoot_FRO192M               = 2U, /*!< LPIT0 mux from FRO192M               */
    kCLOCK_LPIT0_ClockRoot_MAINPLLDIV10          = 3U, /*!< LPIT0 mux from MAINPLLDIV10          */

    /* MAIN ROOT 23 LPIT1 */
    kCLOCK_LPIT1_ClockRoot_PERI3                 = 0U, /*!< LPIT1 mux from PERI3                 */
    kCLOCK_LPIT1_ClockRoot_PERI5                 = 1U, /*!< LPIT1 mux from PERI5                 */
    kCLOCK_LPIT1_ClockRoot_FRO192M               = 2U, /*!< LPIT1 mux from FRO192M               */
    kCLOCK_LPIT1_ClockRoot_MAINPLLDIV10          = 3U, /*!< LPIT1 mux from MAINPLLDIV10          */

    /* MAIN ROOT 24 ADC0 */
    kCLOCK_ADC0_ClockRoot_PERI3                  = 0U, /*!< ADC0 mux from PERI3                  */
    kCLOCK_ADC0_ClockRoot_PERI5                  = 1U, /*!< ADC0 mux from PERI5                  */
    kCLOCK_ADC0_ClockRoot_FRO192M                = 2U, /*!< ADC0 mux from FRO192M                */
    kCLOCK_ADC0_ClockRoot_MAINPLLDIV10           = 3U, /*!< ADC0 mux from MAINPLLDIV10           */

    /* MAIN ROOT 25 ADC1 */
    kCLOCK_ADC1_ClockRoot_PERI3                  = 0U, /*!< ADC1 mux from PERI3                  */
    kCLOCK_ADC1_ClockRoot_PERI5                  = 1U, /*!< ADC1 mux from PERI5                  */
    kCLOCK_ADC1_ClockRoot_FRO192M                = 2U, /*!< ADC1 mux from FRO192M                */
    kCLOCK_ADC1_ClockRoot_MAINPLLDIV10           = 3U, /*!< ADC1 mux from MAINPLLDIV10           */

    /* MAIN ROOT 26 SINC0 */
    kCLOCK_SINC0_ClockRoot_PERI3                 = 0U, /*!< SINC0 mux from PERI3                 */
    kCLOCK_SINC0_ClockRoot_PERI5                 = 1U, /*!< SINC0 mux from PERI5                 */
    kCLOCK_SINC0_ClockRoot_FRO192M               = 2U, /*!< SINC0 mux from FRO192M               */
    kCLOCK_SINC0_ClockRoot_MAINPLLDIV10          = 3U, /*!< SINC0 mux from MAINPLLDIV10          */

    /* MAIN ROOT 27 SINC1 */
    kCLOCK_SINC1_ClockRoot_PERI3                 = 0U, /*!< SINC1 mux from PERI3                 */
    kCLOCK_SINC1_ClockRoot_PERI5                 = 1U, /*!< SINC1 mux from PERI5                 */
    kCLOCK_SINC1_ClockRoot_FRO192M               = 2U, /*!< SINC1 mux from FRO192M               */
    kCLOCK_SINC1_ClockRoot_MAINPLLDIV10          = 3U, /*!< SINC1 mux from MAINPLLDIV10          */

    /* MAIN ROOT 28 FLEXIO0 */
    kCLOCK_FLEXIO0_ClockRoot_PERI0               = 0U, /*!< FLEXIO0 mux from PERI0               */
    kCLOCK_FLEXIO0_ClockRoot_PERI5               = 1U, /*!< FLEXIO0 mux from PERI5               */
    kCLOCK_FLEXIO0_ClockRoot_FRO192M             = 2U, /*!< FLEXIO0 mux from FRO192M             */
    kCLOCK_FLEXIO0_ClockRoot_MAINDIVX            = 3U, /*!< FLEXIO0 mux from MAINDIVX            */

    /* MAIN ROOT 29 FLEXIO1 */
    kCLOCK_FLEXIO1_ClockRoot_PERI0               = 0U, /*!< FLEXIO1 mux from PERI0               */
    kCLOCK_FLEXIO1_ClockRoot_PERI5               = 1U, /*!< FLEXIO1 mux from PERI5               */
    kCLOCK_FLEXIO1_ClockRoot_FRO192M             = 2U, /*!< FLEXIO1 mux from FRO192M             */
    kCLOCK_FLEXIO1_ClockRoot_MAINDIVX            = 3U, /*!< FLEXIO1 mux from MAINDIVX            */

    /* MAIN ROOT 30 FLEXIO2 */
    kCLOCK_FLEXIO2_ClockRoot_PERI0               = 0U, /*!< FLEXIO2 mux from PERI0               */
    kCLOCK_FLEXIO2_ClockRoot_PERI5               = 1U, /*!< FLEXIO2 mux from PERI5               */
    kCLOCK_FLEXIO2_ClockRoot_FRO192M             = 2U, /*!< FLEXIO2 mux from FRO192M             */
    kCLOCK_FLEXIO2_ClockRoot_MAINDIVX            = 3U, /*!< FLEXIO2 mux from MAINDIVX            */

    /* MAIN ROOT 31 TPIU */
    kCLOCK_TPIU_ClockRoot_PERI3                  = 0U, /*!< TPIU mux from PERI3                  */
    kCLOCK_TPIU_ClockRoot_SYSPLLDIV4             = 1U, /*!< TPIU mux from SYSPLLDIV4             */
    kCLOCK_TPIU_ClockRoot_FRO192M                = 2U, /*!< TPIU mux from FRO192M                */
    kCLOCK_TPIU_ClockRoot_MAINDIVX               = 3U, /*!< TPIU mux from MAINDIVX               */

    /* MAIN ROOT 32 CSSI_REFCLK */
    kCLOCK_CSSI_REFCLK_ClockRoot_FRO96M          = 0U, /*!< CSSI_REFCLK mux from FRO96M          */
    kCLOCK_CSSI_REFCLK_ClockRoot_MAINPLLDIV10    = 1U, /*!< CSSI_REFCLK mux from MAINPLLDIV10    */
    kCLOCK_CSSI_REFCLK_ClockRoot_TIE_LOW         = 2U, /*!< CSSI_REFCLK mux from TIE_LOW         */

    /* MAIN ROOT 33 OTP */
    kCLOCK_OTP_ClockRoot_SXOSC                   = 0U, /*!< OTP mux from SXOSC                   */
    kCLOCK_OTP_ClockRoot_MAINPLLDIV10            = 1U, /*!< OTP mux from MAINPLLDIV10            */
    kCLOCK_OTP_ClockRoot_FRO192M                 = 2U, /*!< OTP mux from FRO192M                 */
    kCLOCK_OTP_ClockRoot_FRO24M                  = 3U, /*!< OTP mux from FRO24M                  */

    /* MAIN ROOT 34 CLKOUT */
    kCLOCK_MAIN_CLKOUT_ClockRoot_PERI3           = 0U, /*!< MAIN_CLKOUT mux from PERI3           */
    kCLOCK_MAIN_CLKOUT_ClockRoot_PERI5           = 1U, /*!< MAIN_CLKOUT mux from PERI5           */
    kCLOCK_MAIN_CLKOUT_ClockRoot_FRO192M         = 2U, /*!< MAIN_CLKOUT mux from FRO192M         */
    kCLOCK_MAIN_CLKOUT_ClockRoot_MAINPLLDIV10    = 3U, /*!< MAIN_CLKOUT mux from MAINPLLDIV10    */

    /* MAIN ROOT 35 MAIN_FRO192M */
    kCLOCK_MAIN_MAIN_FRO192M_ClockRoot_FRO192M   = 0U, /*!< MAIN_MAIN_FRO192M mux from FRO192M   */

    /* MAIN ROOT 36 MAIN_ULP32K */
    kCLOCK_MAIN_MAIN_ULP32K_ClockRoot_ULP32K     = 0U, /*!< MAIN_MAIN_ULP32K mux from ULP32K     */

    /*
     * WAKE Clock Roots
     */
    /* WAKE ROOT 0 WAKE */
    kCLOCK_WAKE_ClockRoot_WAKEBUS                = 0U, /*!< WAKE mux from WAKEBUS                */
    kCLOCK_WAKE_ClockRoot_LP12M_WAKE             = 1U, /*!< WAKE mux from LP12M_WAKE             */
    kCLOCK_WAKE_ClockRoot_LP2M_WAKE              = 2U, /*!< WAKE mux from LP2M_WAKE              */

    /* WAKE ROOT 1 WAKE_SXOSC */
    kCLOCK_WAKE_SXOSC_ClockRoot_SXOSC            = 0U, /*!< WAKE_SXOSC mux from SXOSC            */

    /* WAKE ROOT 2 WAKE_LP1M */
    kCLOCK_WAKE_LP1M_ClockRoot_LP1M_WAKE         = 0U, /*!< WAKE_LP1M mux from LP1M_WAKE         */

    /* WAKE ROOT 3 WAKE_LP12M */
    kCLOCK_WAKE_LP12M_ClockRoot_LP12M_WAKE       = 0U, /*!< WAKE_LP12M mux from LP12M_WAKE       */

    /* WAKE ROOT 4 WAKE_ULP32K */
    kCLOCK_WAKE_ULP32K_ClockRoot_ULP32K          = 0U, /*!< WAKE_ULP32K mux from ULP32K          */

    /* WAKE ROOT 5 WAKE_LPCLK */
    kCLOCK_WAKE_LPCLK_ClockRoot_LP1M_WAKE        = 0U, /*!< WAKE_LPCLK mux from LP1M_WAKE        */
    kCLOCK_WAKE_LPCLK_ClockRoot_LP12M_WAKE       = 1U, /*!< WAKE_LPCLK mux from LP12M_WAKE       */
    kCLOCK_WAKE_LPCLK_ClockRoot_LP2M_WAKE        = 2U, /*!< WAKE_LPCLK mux from LP2M_WAKE        */

    /* WAKE ROOT 6 I3C0 (WAKE domain) */
    kCLOCK_WAKE_I3C0_ClockRoot_PERI7             = 0U, /*!< WAKE I3C0 mux from PERI7             */
    kCLOCK_WAKE_I3C0_ClockRoot_FRO24M            = 1U, /*!< WAKE I3C0 mux from FRO24M            */
    kCLOCK_WAKE_I3C0_ClockRoot_WAKE_LPCLK        = 2U, /*!< WAKE I3C0 mux from WAKE_LPCLK        */
    kCLOCK_WAKE_I3C0_ClockRoot_SXOSC             = 3U, /*!< WAKE I3C0 mux from SXOSC             */

    /* WAKE ROOT 7 LPI2C0 (WAKE domain) */
    kCLOCK_WAKE_LPI2C0_ClockRoot_PERI7           = 0U, /*!< WAKE LPI2C0 mux from PERI7           */
    kCLOCK_WAKE_LPI2C0_ClockRoot_FRO24M          = 1U, /*!< WAKE LPI2C0 mux from FRO24M          */
    kCLOCK_WAKE_LPI2C0_ClockRoot_WAKE_LPCLK      = 2U, /*!< WAKE LPI2C0 mux from WAKE_LPCLK      */
    kCLOCK_WAKE_LPI2C0_ClockRoot_SXOSC           = 3U, /*!< WAKE LPI2C0 mux from SXOSC           */

    /* WAKE ROOT 8 LPI2C1 (WAKE domain) */
    kCLOCK_WAKE_LPI2C1_ClockRoot_PERI7           = 0U, /*!< WAKE LPI2C1 mux from PERI7           */
    kCLOCK_WAKE_LPI2C1_ClockRoot_FRO24M          = 1U, /*!< WAKE LPI2C1 mux from FRO24M          */
    kCLOCK_WAKE_LPI2C1_ClockRoot_WAKE_LPCLK      = 2U, /*!< WAKE LPI2C1 mux from WAKE_LPCLK      */
    kCLOCK_WAKE_LPI2C1_ClockRoot_SXOSC           = 3U, /*!< WAKE LPI2C1 mux from SXOSC           */

    /* WAKE ROOT 9 LPSPI0 (WAKE domain) */
    kCLOCK_WAKE_LPSPI0_ClockRoot_PERI7           = 0U, /*!< WAKE LPSPI0 mux from PERI7           */
    kCLOCK_WAKE_LPSPI0_ClockRoot_FRO24M          = 1U, /*!< WAKE LPSPI0 mux from FRO24M          */
    kCLOCK_WAKE_LPSPI0_ClockRoot_WAKE_LPCLK      = 2U, /*!< WAKE LPSPI0 mux from WAKE_LPCLK      */
    kCLOCK_WAKE_LPSPI0_ClockRoot_SXOSC           = 3U, /*!< WAKE LPSPI0 mux from SXOSC           */

    /* WAKE ROOT 10 LPUART0 (WAKE domain) */
    kCLOCK_WAKE_LPUART0_ClockRoot_PERI7          = 0U, /*!< WAKE LPUART0 mux from PERI7          */
    kCLOCK_WAKE_LPUART0_ClockRoot_FRO24M         = 1U, /*!< WAKE LPUART0 mux from FRO24M         */
    kCLOCK_WAKE_LPUART0_ClockRoot_WAKE_LPCLK     = 2U, /*!< WAKE LPUART0 mux from WAKE_LPCLK     */
    kCLOCK_WAKE_LPUART0_ClockRoot_ULP32K         = 3U, /*!< WAKE LPUART0 mux from ULP32K         */

    /* WAKE ROOT 11 LPUART1 (WAKE domain) */
    kCLOCK_WAKE_LPUART1_ClockRoot_PERI7          = 0U, /*!< WAKE LPUART1 mux from PERI7          */
    kCLOCK_WAKE_LPUART1_ClockRoot_FRO24M         = 1U, /*!< WAKE LPUART1 mux from FRO24M         */
    kCLOCK_WAKE_LPUART1_ClockRoot_WAKE_LPCLK     = 2U, /*!< WAKE LPUART1 mux from WAKE_LPCLK     */
    kCLOCK_WAKE_LPUART1_ClockRoot_ULP32K         = 3U, /*!< WAKE LPUART1 mux from ULP32K         */

    /* WAKE ROOT 12 DMIC1_APPCLK */
    kCLOCK_DMIC1_APPCLK_ClockRoot_PERI7          = 0U, /*!< DMIC1_APPCLK mux from PERI7          */
    kCLOCK_DMIC1_APPCLK_ClockRoot_AUDIO          = 1U, /*!< DMIC1_APPCLK mux from AUDIO          */
    kCLOCK_DMIC1_APPCLK_ClockRoot_WAKE_LPCLK     = 2U, /*!< DMIC1_APPCLK mux from WAKE_LPCLK     */
    kCLOCK_DMIC1_APPCLK_ClockRoot_SAIMCLK        = 3U, /*!< DMIC1_APPCLK mux from SAIMCLK        */

    /* WAKE ROOT 13 QTPM0 */
    kCLOCK_QTPM0_ClockRoot_PERI7                 = 0U, /*!< QTPM0 mux from PERI7                 */
    kCLOCK_QTPM0_ClockRoot_AUDIO                 = 1U, /*!< QTPM0 mux from AUDIO                 */
    kCLOCK_QTPM0_ClockRoot_WAKE_LPCLK            = 2U, /*!< QTPM0 mux from WAKE_LPCLK            */
    kCLOCK_QTPM0_ClockRoot_ULP32K                = 3U, /*!< QTPM0 mux from ULP32K                */

    /* WAKE ROOT 14 LPTMR0 */
    kCLOCK_LPTMR0_ClockRoot_ULP32K               = 0U, /*!< LPTMR0 mux from ULP32K               */
    kCLOCK_LPTMR0_ClockRoot_LP1M_WAKE            = 1U, /*!< LPTMR0 mux from LP1M_WAKE            */
    kCLOCK_LPTMR0_ClockRoot_WAKE_LPCLK           = 2U, /*!< LPTMR0 mux from WAKE_LPCLK           */
    kCLOCK_LPTMR0_ClockRoot_SXOSC                = 3U, /*!< LPTMR0 mux from SXOSC                */

    /* WAKE ROOT 15 LPTMR1 */
    kCLOCK_LPTMR1_ClockRoot_ULP32K               = 0U, /*!< LPTMR1 mux from ULP32K               */
    kCLOCK_LPTMR1_ClockRoot_LP1M_WAKE            = 1U, /*!< LPTMR1 mux from LP1M_WAKE            */
    kCLOCK_LPTMR1_ClockRoot_WAKE_LPCLK           = 2U, /*!< LPTMR1 mux from WAKE_LPCLK           */
    kCLOCK_LPTMR1_ClockRoot_SXOSC                = 3U, /*!< LPTMR1 mux from SXOSC                */

    /* WAKE ROOT 16 SWT0 */
    kCLOCK_SWT0_ClockRoot_ULP32K                 = 0U, /*!< SWT0 mux from ULP32K                 */
    kCLOCK_SWT0_ClockRoot_LP1M_WAKE              = 1U, /*!< SWT0 mux from LP1M_WAKE              */
    kCLOCK_SWT0_ClockRoot_TIE_LOW                = 2U, /*!< SWT0 mux from TIE_LOW                */

    /* WAKE ROOT 17 SWT1 */
    kCLOCK_SWT1_ClockRoot_ULP32K                 = 0U, /*!< SWT1 mux from ULP32K                 */
    kCLOCK_SWT1_ClockRoot_LP1M_WAKE              = 1U, /*!< SWT1 mux from LP1M_WAKE              */
    kCLOCK_SWT1_ClockRoot_TIE_LOW                = 2U, /*!< SWT1 mux from TIE_LOW                */

    /* WAKE ROOT 18 EWM */
    kCLOCK_EWM_ClockRoot_ULP32K                  = 0U, /*!< EWM mux from ULP32K                  */
    kCLOCK_EWM_ClockRoot_LP1M_WAKE               = 1U, /*!< EWM mux from LP1M_WAKE               */
    kCLOCK_EWM_ClockRoot_TIE_LOW                 = 2U, /*!< EWM mux from TIE_LOW                 */

    /* WAKE ROOT 19 ACMP0 */
    kCLOCK_ACMP0_ClockRoot_PERI7                 = 0U, /*!< ACMP0 mux from PERI7                 */
    kCLOCK_ACMP0_ClockRoot_FRO24M                = 1U, /*!< ACMP0 mux from FRO24M                */
    kCLOCK_ACMP0_ClockRoot_WAKE_LPCLK            = 2U, /*!< ACMP0 mux from WAKE_LPCLK            */
    kCLOCK_ACMP0_ClockRoot_SXOSC                 = 3U, /*!< ACMP0 mux from SXOSC                 */

    /* WAKE ROOT 20 ACMP1 */
    kCLOCK_ACMP1_ClockRoot_PERI7                 = 0U, /*!< ACMP1 mux from PERI7                 */
    kCLOCK_ACMP1_ClockRoot_FRO24M                = 1U, /*!< ACMP1 mux from FRO24M                */
    kCLOCK_ACMP1_ClockRoot_WAKE_LPCLK            = 2U, /*!< ACMP1 mux from WAKE_LPCLK            */
    kCLOCK_ACMP1_ClockRoot_SXOSC                 = 3U, /*!< ACMP1 mux from SXOSC                 */

    /* WAKE ROOT 21 ACMP2 */
    kCLOCK_ACMP2_ClockRoot_PERI7                 = 0U, /*!< ACMP2 mux from PERI7                 */
    kCLOCK_ACMP2_ClockRoot_FRO24M                = 1U, /*!< ACMP2 mux from FRO24M                */
    kCLOCK_ACMP2_ClockRoot_WAKE_LPCLK            = 2U, /*!< ACMP2 mux from WAKE_LPCLK            */
    kCLOCK_ACMP2_ClockRoot_SXOSC                 = 3U, /*!< ACMP2 mux from SXOSC                 */

    /* WAKE ROOT 22 ACMP3 */
    kCLOCK_ACMP3_ClockRoot_PERI7                 = 0U, /*!< ACMP3 mux from PERI7                 */
    kCLOCK_ACMP3_ClockRoot_FRO24M                = 1U, /*!< ACMP3 mux from FRO24M                */
    kCLOCK_ACMP3_ClockRoot_WAKE_LPCLK            = 2U, /*!< ACMP3 mux from WAKE_LPCLK            */
    kCLOCK_ACMP3_ClockRoot_SXOSC                 = 3U, /*!< ACMP3 mux from SXOSC                 */

    /* WAKE ROOT 23 ACMP0_RRCLK */
    kCLOCK_ACMP0_RRCLK_ClockRoot_ULP32K          = 0U, /*!< ACMP0_RRCLK mux from ULP32K          */
    kCLOCK_ACMP0_RRCLK_ClockRoot_FRO24M          = 1U, /*!< ACMP0_RRCLK mux from FRO24M          */
    kCLOCK_ACMP0_RRCLK_ClockRoot_WAKE_LPCLK      = 2U, /*!< ACMP0_RRCLK mux from WAKE_LPCLK      */
    kCLOCK_ACMP0_RRCLK_ClockRoot_LP1M_WAKE       = 3U, /*!< ACMP0_RRCLK mux from LP1M_WAKE       */

    /* WAKE ROOT 24 ACMP1_RRCLK */
    kCLOCK_ACMP1_RRCLK_ClockRoot_ULP32K          = 0U, /*!< ACMP1_RRCLK mux from ULP32K          */
    kCLOCK_ACMP1_RRCLK_ClockRoot_FRO24M          = 1U, /*!< ACMP1_RRCLK mux from FRO24M          */
    kCLOCK_ACMP1_RRCLK_ClockRoot_WAKE_LPCLK      = 2U, /*!< ACMP1_RRCLK mux from WAKE_LPCLK      */
    kCLOCK_ACMP1_RRCLK_ClockRoot_LP1M_WAKE       = 3U, /*!< ACMP1_RRCLK mux from LP1M_WAKE       */

    /* WAKE ROOT 25 ACMP2_RRCLK */
    kCLOCK_ACMP2_RRCLK_ClockRoot_ULP32K          = 0U, /*!< ACMP2_RRCLK mux from ULP32K          */
    kCLOCK_ACMP2_RRCLK_ClockRoot_FRO24M          = 1U, /*!< ACMP2_RRCLK mux from FRO24M          */
    kCLOCK_ACMP2_RRCLK_ClockRoot_WAKE_LPCLK      = 2U, /*!< ACMP2_RRCLK mux from WAKE_LPCLK      */
    kCLOCK_ACMP2_RRCLK_ClockRoot_LP1M_WAKE       = 3U, /*!< ACMP2_RRCLK mux from LP1M_WAKE       */

    /* WAKE ROOT 26 ACMP3_RRCLK */
    kCLOCK_ACMP3_RRCLK_ClockRoot_ULP32K          = 0U, /*!< ACMP3_RRCLK mux from ULP32K          */
    kCLOCK_ACMP3_RRCLK_ClockRoot_FRO24M          = 1U, /*!< ACMP3_RRCLK mux from FRO24M          */
    kCLOCK_ACMP3_RRCLK_ClockRoot_WAKE_LPCLK      = 2U, /*!< ACMP3_RRCLK mux from WAKE_LPCLK      */
    kCLOCK_ACMP3_RRCLK_ClockRoot_LP1M_WAKE       = 3U, /*!< ACMP3_RRCLK mux from LP1M_WAKE       */

    /*
     * COMM Clock Roots
     */
    /* COMM ROOT 0 COMM */
    kCLOCK_COMM_ClockRoot_COMMBUS                = 0U, /*!< COMM mux from COMMBUS                */

    /* COMM ROOT 1 COMM_ULP32K */
    kCLOCK_COMM_ULP32K_ClockRoot_ULP32K          = 0U, /*!< COMM_ULP32K mux from ULP32K          */

    /* COMM ROOT 2 USDHC0 */
    kCLOCK_USDHC0_ClockRoot_COMM_PERI1_DIV2      = 0U, /*!< USDHC0 mux from COMM_PERI1_DIV2      */
    kCLOCK_USDHC0_ClockRoot_COMMPFDX_DIV2        = 1U, /*!< USDHC0 mux from COMMPFDX_DIV2        */
    kCLOCK_USDHC0_ClockRoot_SYSPLLDIV4           = 2U, /*!< USDHC0 mux from SYSPLLDIV4           */
    kCLOCK_USDHC0_ClockRoot_SYSPLLDIV5           = 3U, /*!< USDHC0 mux from SYSPLLDIV5           */

    /* COMM ROOT 3 USDHC1 */
    kCLOCK_USDHC1_ClockRoot_COMM_PERI2_DIV2      = 0U, /*!< USDHC1 mux from COMM_PERI2_DIV2      */
    kCLOCK_USDHC1_ClockRoot_COMMPFDX_DIV2        = 1U, /*!< USDHC1 mux from COMMPFDX_DIV2        */
    kCLOCK_USDHC1_ClockRoot_SYSPLLDIV4           = 2U, /*!< USDHC1 mux from SYSPLLDIV4           */
    kCLOCK_USDHC1_ClockRoot_SYSPLLDIV5           = 3U, /*!< USDHC1 mux from SYSPLLDIV5           */

    /* COMM ROOT 4 XSPIR */
    kCLOCK_XSPIR_ClockRoot_PERI1                 = 0U, /*!< XSPIR mux from PERI1                 */
    kCLOCK_XSPIR_ClockRoot_PERI2                 = 1U, /*!< XSPIR mux from PERI2                 */
    kCLOCK_XSPIR_ClockRoot_SYSPLLDIV4            = 2U, /*!< XSPIR mux from SYSPLLDIV4            */
    kCLOCK_XSPIR_ClockRoot_SYSPLLDIV5            = 3U, /*!< XSPIR mux from SYSPLLDIV5            */

    /* COMM ROOT 5 USB0_PHYCLK */
    kCLOCK_USB0_PHYCLK_ClockRoot_SXOSC           = 0U, /*!< USB0_PHYCLK mux from SXOSC           */

    /* COMM ROOT 6 USB0_FRO48M */
    kCLOCK_USB0_FRO48M_ClockRoot_FRO48M          = 0U, /*!< USB0_FRO48M mux from FRO48M          */

    /* COMM ROOT 7 USB1 */
    kCLOCK_USB1_ClockRoot_USB1                   = 0U, /*!< USB1 mux from USB1                   */
    kCLOCK_USB1_ClockRoot_USBPLL_OUT             = 1U, /*!< USB1 mux from USBPLL_OUT             */
    kCLOCK_USB1_ClockRoot_USBPLL_48M             = 2U, /*!< USB1 mux from USBPLL_48M             */
    kCLOCK_USB1_ClockRoot_FRO48M                 = 3U, /*!< USB1 mux from FRO48M                 */

    /* COMM ROOT 8 USB0_WAKECLK */
    kCLOCK_USB0_WAKECLK_ClockRoot_ULP32K         = 0U, /*!< USB0_WAKECLK mux from ULP32K         */
    kCLOCK_USB0_WAKECLK_ClockRoot_LP1M_CORE      = 1U, /*!< USB0_WAKECLK mux from LP1M_CORE      */
    kCLOCK_USB0_WAKECLK_ClockRoot_SXOSC          = 2U, /*!< USB0_WAKECLK mux from SXOSC          */
    kCLOCK_USB0_WAKECLK_ClockRoot_TIE_LOW        = 3U, /*!< USB0_WAKECLK mux from TIE_LOW        */

    /* COMM ROOT 9 ETH0_TRXCLK */
    kCLOCK_ETH0_TRXCLK_ClockRoot_COMMBUS         = 0U, /*!< ETH0_TRXCLK mux from COMMBUS         */
    kCLOCK_ETH0_TRXCLK_ClockRoot_ETH             = 1U, /*!< ETH0_TRXCLK mux from ETH             */
    kCLOCK_ETH0_TRXCLK_ClockRoot_SYSPLLDIV4      = 2U, /*!< ETH0_TRXCLK mux from SYSPLLDIV4      */
    kCLOCK_ETH0_TRXCLK_ClockRoot_MAINPLLDIV8     = 3U, /*!< ETH0_TRXCLK mux from MAINPLLDIV8     */

    /* COMM ROOT 10 ETH0_TIMERCLK */
    kCLOCK_ETH0_TIMERCLK_ClockRoot_COMMBUS       = 0U, /*!< ETH0_TIMERCLK mux from COMMBUS       */
    kCLOCK_ETH0_TIMERCLK_ClockRoot_ETH           = 1U, /*!< ETH0_TIMERCLK mux from ETH           */
    kCLOCK_ETH0_TIMERCLK_ClockRoot_SXOSC         = 2U, /*!< ETH0_TIMERCLK mux from SXOSC         */
    kCLOCK_ETH0_TIMERCLK_ClockRoot_MAINPLLDIV8   = 3U, /*!< ETH0_TIMERCLK mux from MAINPLLDIV8   */

    /* COMM ROOT 11 ETH1_TRXCLK */
    kCLOCK_ETH1_TRXCLK_ClockRoot_COMMBUS         = 0U, /*!< ETH1_TRXCLK mux from COMMBUS         */
    kCLOCK_ETH1_TRXCLK_ClockRoot_ETH             = 1U, /*!< ETH1_TRXCLK mux from ETH             */
    kCLOCK_ETH1_TRXCLK_ClockRoot_SYSPLLDIV4      = 2U, /*!< ETH1_TRXCLK mux from SYSPLLDIV4      */
    kCLOCK_ETH1_TRXCLK_ClockRoot_MAINPLLDIV8     = 3U, /*!< ETH1_TRXCLK mux from MAINPLLDIV8     */

    /* COMM ROOT 12 ETH1_TIMERCLK */
    kCLOCK_ETH1_TIMERCLK_ClockRoot_COMMBUS       = 0U, /*!< ETH1_TIMERCLK mux from COMMBUS       */
    kCLOCK_ETH1_TIMERCLK_ClockRoot_ETH           = 1U, /*!< ETH1_TIMERCLK mux from ETH           */
    kCLOCK_ETH1_TIMERCLK_ClockRoot_SXOSC         = 2U, /*!< ETH1_TIMERCLK mux from SXOSC         */
    kCLOCK_ETH1_TIMERCLK_ClockRoot_MAINPLLDIV8   = 3U, /*!< ETH1_TIMERCLK mux from MAINPLLDIV8   */

    /* COMM ROOT 13 ETH_REFCLK */
    kCLOCK_ETH_REFCLK_ClockRoot_COMMBUS          = 0U, /*!< ETH_REFCLK mux from COMMBUS          */
    kCLOCK_ETH_REFCLK_ClockRoot_ETH              = 1U, /*!< ETH_REFCLK mux from ETH              */
    kCLOCK_ETH_REFCLK_ClockRoot_SXOSC            = 2U, /*!< ETH_REFCLK mux from SXOSC            */
    kCLOCK_ETH_REFCLK_ClockRoot_MAINPLLDIV8      = 3U, /*!< ETH_REFCLK mux from MAINPLLDIV8      */

    /* COMM ROOT 14 XENO0_LIWCLK */
    kCLOCK_XENO0_LIWCLK_ClockRoot_COMMBUS        = 0U, /*!< XENO0_LIWCLK mux from COMMBUS        */
    kCLOCK_XENO0_LIWCLK_ClockRoot_MAINPLLDIV10   = 1U, /*!< XENO0_LIWCLK mux from MAINPLLDIV10   */
    kCLOCK_XENO0_LIWCLK_ClockRoot_SYSPLLDIV4     = 2U, /*!< XENO0_LIWCLK mux from SYSPLLDIV4     */
    kCLOCK_XENO0_LIWCLK_ClockRoot_SYSPLLDIV5     = 3U, /*!< XENO0_LIWCLK mux from SYSPLLDIV5     */

    /* COMM ROOT 15 XENO1_LIWCLK */
    kCLOCK_XENO1_LIWCLK_ClockRoot_COMMBUS        = 0U, /*!< XENO1_LIWCLK mux from COMMBUS        */
    kCLOCK_XENO1_LIWCLK_ClockRoot_MAINPLLDIV10   = 1U, /*!< XENO1_LIWCLK mux from MAINPLLDIV10   */
    kCLOCK_XENO1_LIWCLK_ClockRoot_SYSPLLDIV4     = 2U, /*!< XENO1_LIWCLK mux from SYSPLLDIV4     */
    kCLOCK_XENO1_LIWCLK_ClockRoot_SYSPLLDIV5     = 3U, /*!< XENO1_LIWCLK mux from SYSPLLDIV5     */

    /* COMM ROOT 16 DLL_REFCLK */
    kCLOCK_DLL_REFCLK_ClockRoot_MAINPLLDIV10     = 0U, /*!< DLL_REFCLK mux from MAINPLLDIV10     */

    /*
     * AUDIO Clock Roots
     */
    /* AUDIO ROOT 0 audio_clk */
    kCLOCK_AUDIO_CLK_ClockRoot_AUDIOBUS          = 0U, /*!< audio_clk mux from AUDIOBUS          */

    /* AUDIO ROOT 1 dmic0_appclk */
    kCLOCK_DMIC0_APPCLK_ClockRoot_PERI6          = 0U, /*!< DMIC0_APPCLK mux from PERI6          */
    kCLOCK_DMIC0_APPCLK_ClockRoot_AUDIOPLL       = 1U, /*!< DMIC0_APPCLK mux from AUDIOPLL       */
    kCLOCK_DMIC0_APPCLK_ClockRoot_AUDIO          = 2U, /*!< DMIC0_APPCLK mux from AUDIO          */
    kCLOCK_DMIC0_APPCLK_ClockRoot_SAIMCLK        = 3U, /*!< DMIC0_APPCLK mux from SAIMCLK        */

    /* AUDIO ROOT 2 sai0_mclk0 */
    kCLOCK_SAI0_MCLK0_ClockRoot_PERI6            = 0U, /*!< sai0_mclk0 mux from PERI6            */
    kCLOCK_SAI0_MCLK0_ClockRoot_AUDIOPLL         = 1U, /*!< sai0_mclk0 mux from AUDIOPLL         */
    kCLOCK_SAI0_MCLK0_ClockRoot_AUDIO            = 2U, /*!< sai0_mclk0 mux from AUDIO            */
    kCLOCK_SAI0_MCLK0_ClockRoot_SAIMCLK0         = 3U, /*!< sai0_mclk0 mux from SAIMCLK0         */

    /* AUDIO ROOT 3 sai0_mclk1 */
    kCLOCK_SAI0_MCLK1_ClockRoot_PERI6            = 0U, /*!< sai0_mclk1 mux from PERI6            */
    kCLOCK_SAI0_MCLK1_ClockRoot_AUDIOPLL         = 1U, /*!< sai0_mclk1 mux from AUDIOPLL         */
    kCLOCK_SAI0_MCLK1_ClockRoot_AUDIO            = 2U, /*!< sai0_mclk1 mux from AUDIO            */
    kCLOCK_SAI0_MCLK1_ClockRoot_SAIMCLK          = 3U, /*!< sai0_mclk1 mux from SAIMCLK          */

    /* AUDIO ROOT 4 sai1_mclk0 */
    kCLOCK_SAI1_MCLK0_ClockRoot_PERI6            = 0U, /*!< sai1_mclk0 mux from PERI6            */
    kCLOCK_SAI1_MCLK0_ClockRoot_AUDIOPLL         = 1U, /*!< sai1_mclk0 mux from AUDIOPLL         */
    kCLOCK_SAI1_MCLK0_ClockRoot_AUDIO            = 2U, /*!< sai1_mclk0 mux from AUDIO            */
    kCLOCK_SAI1_MCLK0_ClockRoot_SAIMCLK1         = 3U, /*!< sai1_mclk0 mux from SAIMCLK1         */

    /* AUDIO ROOT 5 sai1_mclk1 */
    kCLOCK_SAI1_MCLK1_ClockRoot_PERI6            = 0U, /*!< sai1_mclk1 mux from PERI6            */
    kCLOCK_SAI1_MCLK1_ClockRoot_AUDIOPLL         = 1U, /*!< sai1_mclk1 mux from AUDIOPLL         */
    kCLOCK_SAI1_MCLK1_ClockRoot_AUDIO            = 2U, /*!< sai1_mclk1 mux from AUDIO            */
    kCLOCK_SAI1_MCLK1_ClockRoot_SAIMCLK          = 3U, /*!< sai1_mclk1 mux from SAIMCLK          */

    /* AUDIO ROOT 6 sai2_mclk0 */
    kCLOCK_SAI2_MCLK0_ClockRoot_PERI6            = 0U, /*!< sai2_mclk0 mux from PERI6            */
    kCLOCK_SAI2_MCLK0_ClockRoot_AUDIOPLL         = 1U, /*!< sai2_mclk0 mux from AUDIOPLL         */
    kCLOCK_SAI2_MCLK0_ClockRoot_AUDIO            = 2U, /*!< sai2_mclk0 mux from AUDIO            */
    kCLOCK_SAI2_MCLK0_ClockRoot_SAIMCLK2         = 3U, /*!< sai2_mclk0 mux from SAIMCLK2         */

    /* AUDIO ROOT 7 SAI2_MCLK1 */
    kCLOCK_SAI2_MCLK1_ClockRoot_PERI6            = 0U, /*!< SAI2_MCLK1 mux from PERI6            */
    kCLOCK_SAI2_MCLK1_ClockRoot_AUDIOPLL         = 1U, /*!< SAI2_MCLK1 mux from AUDIOPLL         */
    kCLOCK_SAI2_MCLK1_ClockRoot_AUDIO            = 2U, /*!< SAI2_MCLK1 mux from AUDIO            */
    kCLOCK_SAI2_MCLK1_ClockRoot_SAIMCLK          = 3U, /*!< SAI2_MCLK1 mux from SAIMCLK          */

    /* AUDIO ROOT 8 SPDIF_TXCLK */
    kCLOCK_SPDIF_TXCLK_ClockRoot_PERI6           = 0U, /*!< SPDIF_TXCLK mux from PERI6           */
    kCLOCK_SPDIF_TXCLK_ClockRoot_AUDIOPLL        = 1U, /*!< SPDIF_TXCLK mux from AUDIOPLL        */
    kCLOCK_SPDIF_TXCLK_ClockRoot_AUDIO           = 2U, /*!< SPDIF_TXCLK mux from AUDIO           */
    kCLOCK_SPDIF_TXCLK_ClockRoot_SAIMCLK         = 3U, /*!< SPDIF_TXCLK mux from SAIMCLK         */

    /* AUDIO ROOT 9 SPDIF_CDRCLK */
    kCLOCK_SPDIF_CDRCLK_ClockRoot_PERI6          = 0U, /*!< SPDIF_CDRCLK mux from PERI6          */
    kCLOCK_SPDIF_CDRCLK_ClockRoot_AUDIOPLL       = 1U, /*!< SPDIF_CDRCLK mux from AUDIOPLL       */
    kCLOCK_SPDIF_CDRCLK_ClockRoot_MAINPLLDIV10   = 2U, /*!< SPDIF_CDRCLK mux from MAINPLLDIV10   */
    kCLOCK_SPDIF_CDRCLK_ClockRoot_AUDIOBUS       = 3U, /*!< SPDIF_CDRCLK mux from AUDIOBUS       */

    /* AUDIO ROOT 10 ASRC */
    kCLOCK_ASRC_ClockRoot_PERI6                  = 0U, /*!< ASRC mux from PERI6                  */
    kCLOCK_ASRC_ClockRoot_AUDIOPLL               = 1U, /*!< ASRC mux from AUDIOPLL               */
    kCLOCK_ASRC_ClockRoot_MAINPLLDIV10           = 2U, /*!< ASRC mux from MAINPLLDIV10           */
    kCLOCK_ASRC_ClockRoot_AUDIOBUS               = 3U, /*!< ASRC mux from AUDIOBUS               */

    /*
     * MEDIA Clock Roots
     */
    /* MEDIA ROOT 0 MEDIA */
    kCLOCK_MEDIA_ClockRoot_MEDIABUS              = 0U, /*!< MEDIA mux from MEDIABUS              */

    /* MEDIA ROOT 1 MEDIAPLL */
    kCLOCK_MEDIAPLL_ClockRoot_MAINPLLDIV10       = 0U, /*!< MEDIAPLL mux from MAINPLLDIV10       */
    kCLOCK_MEDIAPLL_ClockRoot_MIPIPLL_DIV8       = 1U, /*!< MEDIAPLL mux from MIPIPLL_DIV8       */

    /* MEDIA ROOT 2 MIPICSI_ESCCLK */
    kCLOCK_MIPICSI_ESCCLK_ClockRoot_PERI5        = 0U, /*!< MIPICSI_ESCCLK mux from PERI5        */
    kCLOCK_MIPICSI_ESCCLK_ClockRoot_VIDEOPLL     = 1U, /*!< MIPICSI_ESCCLK mux from VIDEOPLL     */
    kCLOCK_MIPICSI_ESCCLK_ClockRoot_VIDEO        = 2U, /*!< MIPICSI_ESCCLK mux from VIDEO        */
    kCLOCK_MIPICSI_ESCCLK_ClockRoot_MEDIAPLL     = 3U, /*!< MIPICSI_ESCCLK mux from MEDIAPLL     */

    /* MEDIA ROOT 3 MIPICSI */
    kCLOCK_MIPICSI_ClockRoot_PERI5               = 0U, /*!< MIPICSI mux from PERI5               */
    kCLOCK_MIPICSI_ClockRoot_VIDEOPLL            = 1U, /*!< MIPICSI mux from VIDEOPLL            */
    kCLOCK_MIPICSI_ClockRoot_VIDEO               = 2U, /*!< MIPICSI mux from VIDEO               */
    kCLOCK_MIPICSI_ClockRoot_MEDIAPLL            = 3U, /*!< MIPICSI mux from MEDIAPLL            */

    /* MEDIA ROOT 4 MIPIDSI_ESCCLK */
    kCLOCK_MIPIDSI_ESCCLK_ClockRoot_PERI5        = 0U, /*!< MIPIDSI_ESCCLK mux from PERI5        */
    kCLOCK_MIPIDSI_ESCCLK_ClockRoot_VIDEOPLL     = 1U, /*!< MIPIDSI_ESCCLK mux from VIDEOPLL     */
    kCLOCK_MIPIDSI_ESCCLK_ClockRoot_VIDEO        = 2U, /*!< MIPIDSI_ESCCLK mux from VIDEO        */
    kCLOCK_MIPIDSI_ESCCLK_ClockRoot_MEDIAPLL     = 3U, /*!< MIPIDSI_ESCCLK mux from MEDIAPLL     */

    /* MEDIA ROOT 5 MIPIDSI_REFCLK */
    kCLOCK_MIPIDSI_REFCLK_ClockRoot_SXOSC        = 0U, /*!< MIPIDSI_REFCLK mux from SXOSC        */

    /* MEDIA ROOT 6 MIPIDSI */
    kCLOCK_MIPIDSI_ClockRoot_PERI5               = 0U, /*!< MIPIDSI mux from PERI5               */
    kCLOCK_MIPIDSI_ClockRoot_VIDEOPLL            = 1U, /*!< MIPIDSI mux from VIDEOPLL            */
    kCLOCK_MIPIDSI_ClockRoot_VIDEO               = 2U, /*!< MIPIDSI mux from VIDEO               */
    kCLOCK_MIPIDSI_ClockRoot_MEDIAPLL            = 3U, /*!< MIPIDSI mux from MEDIAPLL            */

    /* MEDIA ROOT 7 REFORMAT */
    kCLOCK_REFORMAT_ClockRoot_PERI5              = 0U, /*!< REFORMAT mux from PERI5              */
    kCLOCK_REFORMAT_ClockRoot_VIDEOPLL           = 1U, /*!< REFORMAT mux from VIDEOPLL           */
    kCLOCK_REFORMAT_ClockRoot_VIDEO              = 2U, /*!< REFORMAT mux from VIDEO              */
    kCLOCK_REFORMAT_ClockRoot_MEDIAPLL           = 3U, /*!< REFORMAT mux from MEDIAPLL           */

    /* MEDIA ROOT 8 DCPIXEL */
    kCLOCK_DCPIXEL_ClockRoot_PERI5               = 0U, /*!< DCPIXEL mux from PERI5               */
    kCLOCK_DCPIXEL_ClockRoot_VIDEOPLL            = 1U, /*!< DCPIXEL mux from VIDEOPLL            */
    kCLOCK_DCPIXEL_ClockRoot_VIDEO               = 2U, /*!< DCPIXEL mux from VIDEO               */
    kCLOCK_DCPIXEL_ClockRoot_MEDIAPLL            = 3U, /*!< DCPIXEL mux from MEDIAPLL            */

    /* MEDIA ROOT 9 CSI_MCLKOUT */
    kCLOCK_CSI_MCLKOUT_ClockRoot_PERI5           = 0U, /*!< CSI_MCLKOUT mux from PERI5           */
    kCLOCK_CSI_MCLKOUT_ClockRoot_SXOSC           = 1U, /*!< CSI_MCLKOUT mux from SXOSC           */
    kCLOCK_CSI_MCLKOUT_ClockRoot_VIDEO           = 2U, /*!< CSI_MCLKOUT mux from VIDEO           */
    kCLOCK_CSI_MCLKOUT_ClockRoot_MEDIAPLL        = 3U, /*!< CSI_MCLKOUT mux from MEDIAPLL        */
} clock_root_mux_source_t;

/*! @brief CCM gate control value. */
typedef enum _clock_gate_value
{
    kCLOCK_BusOFF_FuncOFF         = 0x0U,    /*!< bus clock OFF, functional clock OFF.*/
    kCLOCK_BusON_FuncON_SLEEP     = 0x1U,    /*!< bus clock ON(OFF in Sleep),functional clock ON(OFF in Sleep).*/
    kCLOCK_BusON_FuncON_DEEPSLEEP = 0x2U,    /*!< bus clock ON(OFF in DeepSleep),functional clock ON(OFF in DeepSleep).*/
    kCLOCK_BusON_FuncON           = 0x3U,    /*!< bus clock ON(OFF in DeepSleep),functional clock ON.*/
} clock_gate_value_t;

#define clock_ip_name_t clock_lpcg_t

/*!
 * @brief Clock name.
 */
typedef enum _clock_name
{
    /* ========================================================================
     * Section A: in-map srcs -- routed through s_clockSrcRootMap[name].
     * Values [0, 48) -- 48 entries: 38 Ox + 1 Case 4 (MAIN) + 1 Lx + 6 Mx.
     *
     * Each row's "Level X ?#" trailing comment is the source's location label
     * in the L1 / L2 clock-tree mux mapping. Sources that only appear at the
     * L0 level have no annotation.
     * ====================================================================== */

    /* --- A.1: L1 Ox CGU passthrough/mux outputs (38) --- */
    kCLOCK_SRC_BASE              = 0,     /*Level 1 O1 */
    kCLOCK_SRC_LOW               = 1,     /*Level 1 O2 */
    kCLOCK_SRC_MAINPLL_DIVX      = 2,     /*Level 1 O3 */
    kCLOCK_SRC_SYSPLL_DIVX       = 3,     /*Level 1 O4 */
    kCLOCK_SRC_PLL_PFDX          = 4,     /*Level 1 O5 */
    kCLOCK_SRC_MEDIA_PFDX        = 5,     /*Level 1 O6 */
    kCLOCK_SRC_MAINDIVX          = 6,     /*Level 1 O9 */
    kCLOCK_SRC_SAIMCLK           = 7,     /*Level 1 O10*/
    kCLOCK_SRC_SAIMCLK0          = 8,     /*Level 1 O11*/
    kCLOCK_SRC_SAIMCLK1          = 9,     /*Level 1 O12*/
    kCLOCK_SRC_SAIMCLK2          = 10,    /*Level 1 O13*/
    kCLOCK_SRC_ULP32K            = 11,    /*Level 1 O16*/
    kCLOCK_SRC_FRO192M           = 12,    /*Level 1 O17*/
    kCLOCK_SRC_FRO96M            = 13,    /*Level 1 O18*/
    kCLOCK_SRC_FRO48M            = 14,    /*Level 1 O19*/
    kCLOCK_SRC_FRO24M            = 15,    /*Level 1 O20*/
    kCLOCK_SRC_SYSPLLDIV4        = 16,    /*Level 1 O21*/
    kCLOCK_SRC_SYSPLLDIV5        = 17,    /*Level 1 O22*/
    kCLOCK_SRC_MAINPLLDIV8       = 18,    /*Level 1 O25*/
    kCLOCK_SRC_MAINPLLDIV10      = 19,    /*Level 1 O26*/
    kCLOCK_SRC_AUDIOPLL          = 20,    /*Level 1 O28*/
    kCLOCK_SRC_VIDEOPLL          = 21,    /*Level 1 O29*/
    kCLOCK_SRC_CPU               = 22,    /*Level 1 O30*/
    kCLOCK_SRC_NPU               = 23,    /*Level 1 O31*/
    kCLOCK_SRC_MEDIABUS          = 24,    /*Level 1 O32*/
    kCLOCK_SRC_AUDIOBUS          = 25,    /*Level 1 O33*/
    kCLOCK_SRC_COMMBUS           = 26,    /*Level 1 O34*/
    kCLOCK_SRC_WAKEBUS           = 27,    /*Level 1 O35*/
    kCLOCK_SRC_PERI0             = 28,    /*Level 1 O37*/
    kCLOCK_SRC_PERI1             = 29,    /*Level 1 O38*/
    kCLOCK_SRC_PERI2             = 30,    /*Level 1 O39*/
    kCLOCK_SRC_PERI3             = 31,    /*Level 1 O40*/
    kCLOCK_SRC_PERI4             = 32,    /*Level 1 O41*/
    kCLOCK_SRC_PERI5             = 33,    /*Level 1 O42*/
    kCLOCK_SRC_PERI6             = 34,    /*Level 1 O43*/
    kCLOCK_SRC_PERI7             = 35,    /*Level 1 O44*/
    kCLOCK_SRC_AUDIO             = 36,    /*Level 1 O45*/
    kCLOCK_SRC_VIDEO             = 37,    /*Level 1 O46*/
    kCLOCK_SRC_USB1              = 38,    /*Level 1 O47*/
    kCLOCK_SRC_ETH               = 39,    /*Level 1 O48*/

    /* --- A.2: Case 4 special alias (1) ---
     * MAIN is labeled O36 (SYSCON_PDMAIN) in the L1 mux mapping, but the
     * runtime resolver routes it to O30 (CGU MAIN root) to match the actual
     * silicon clock topology -- see CLOCK_GetClockSrcFreq. */
    kCLOCK_SRC_MAIN              = 40,    /*Level 1 O36*/ /* resolver routes to O30 */

    /* --- A.3: L2 Lx WAKE-domain SS-output feedback (1) --- */
    kCLOCK_SRC_WAKE_LPCLK        = 41,    /*Level 2 L0 */

    /* --- A.4: Mx MODCON-controlled /2 (6) ---
     * Each entry recurses through its parent root; the /2 selection is read
     * inside CLOCK_GetClockSrcFreq from the canonical MODCON instance. */
    kCLOCK_SRC_MAIN_PERI0_DIV2   = 42,    /*Level 2 M0 */
    kCLOCK_SRC_MAIN_PERI1_DIV2   = 43,    /*Level 2 M2 */
    kCLOCK_SRC_MAINPFDX_DIV2     = 44,    /*Level 2 M1 */
    kCLOCK_SRC_COMM_PERI1_DIV2   = 45,    /*Level 2 M3 */
    kCLOCK_SRC_COMM_PERI2_DIV2   = 46,    /*Level 2 M5 */
    kCLOCK_SRC_COMMPFDX_DIV2     = 47,    /*Level 2 M4 */

    /* ========================================================================
     * Section B: reserved future-in-map slots -- [48, 64), 16 entries.
     * s_clockSrcRootMap[48..63] is implicitly kCLOCK_Root_Invalid; the resolver
     * short-circuits to 0 if any of those values shows up at runtime. When
     * adding a new src that needs root routing (Ox / Lx / Mx / special alias),
     * give it the next free value in [48, 64) and add the matching row to
     * s_clockSrcRootMap -- no other enum values move. When this segment fills
     * up, raise kCLOCK_SRC_BOUNDARY and shift Section C / Invalid values up.
     * ====================================================================== */

    kCLOCK_SRC_BOUNDARY          = 64,    /*!< NOT a real src. Marks the end of
                                               the s_clockSrcRootMap-indexed
                                               segment. Used by the resolver. */

    /* ========================================================================
     * Section C: terminal srcs -- routed by the Case 2 switch in
     * CLOCK_GetClockSrcFreq. L0 fundamentals (no L1/L2 mux annotation),
     * PLL helpers, macro-backed PLLs, external sources, TIE_LOW.
     *
     * A few sources here are Level 1 outputs in the mux mapping but treated
     * as terminal constants in code (cycle breakers / simplification); flagged.
     * ====================================================================== */

    /* --- C.1: L0 fixed analog / oscillators (mostly Level-0-only -- no L1/L2 label) --- */
    kCLOCK_SRC_OSC_24M           = 64,    /* L0 only, MODCON-routed */
    kCLOCK_SRC_SXOSC             = 65,    /*Level 1 O0 */ /* cycle breaker, Case 2 const 24M */
    kCLOCK_SRC_FRO_192M          = 66,    /* L0 only */
    kCLOCK_SRC_FRO_96M           = 67,    /* L0 only */
    kCLOCK_SRC_FRO_48M           = 68,    /* L0 only */
    kCLOCK_SRC_FRO_24M           = 69,    /* L0 only */
    kCLOCK_SRC_LPOSC_12M_CORE    = 70,    /* L0 only */
    kCLOCK_SRC_LPOSC_1M_CORE     = 71,    /* L0 only */
    kCLOCK_SRC_LP1M_CORE         = 72,    /*Level 1 O15*/ /* treated as Case 2 const 1M */
    kCLOCK_SRC_LP12M_WAKE        = 73,    /*Level 2 A0 */ /* cycle breaker const 12M */
    kCLOCK_SRC_LP1M_WAKE         = 74,    /*Level 2 A2 */ /* cycle breaker const 1M */
    kCLOCK_SRC_LP2M_WAKE         = 75,    /*Level 2 A1 */
    kCLOCK_SRC_LPOSC32K          = 76,    /* L0 only */

    /* --- C.2: PLL outputs via dedicated helpers (L0 only, no L1/L2 label) --- */
    kCLOCK_SRC_COREPLL_OUT       = 77,    /* L0 only */
    kCLOCK_SRC_AUDIOPLL_DIVOUT   = 78,    /* L0 only */
    kCLOCK_SRC_VIDEOPLL_DIVOUT   = 79,    /* L0 only */
    kCLOCK_SRC_MAINPLL_DIV4      = 80,    /* L0 only */
    kCLOCK_SRC_MAINPLL_DIV5      = 81,    /* L0 only */
    kCLOCK_SRC_MAINPLL_DIV8      = 82,    /* L0 only */
    kCLOCK_SRC_MAINPLL_DIV10     = 83,    /* L0 only */
    kCLOCK_SRC_MAINPLL_DIV20     = 84,    /* L0 only */
    kCLOCK_SRC_MAINPLL_DIVOUT0   = 85,    /* L0 only */
    kCLOCK_SRC_MAINPLL_DIVOUT1   = 86,    /* L0 only */
    kCLOCK_SRC_MAINPLL_DIVOUT2   = 87,    /* L0 only */
    kCLOCK_SRC_SYSPLL_DIV4       = 88,    /* L0 only */
    kCLOCK_SRC_SYSPLL_DIV5       = 89,    /* L0 only */
    kCLOCK_SRC_SYSPLL_DIV10      = 90,    /* L0 only */
    kCLOCK_SRC_SYSPLL_DIV20      = 91,    /* L0 only */
    kCLOCK_SRC_SYSPLL_DIVOUT0    = 92,    /* L0 only */
    kCLOCK_SRC_SYSPLL_DIVOUT1    = 93,    /* L0 only */
    kCLOCK_SRC_SYSPLL_DIVOUT2    = 94,    /* L0 only */

    /* --- C.3: macro-backed PLLs (#ifndef-overridable in this header) --- */
    kCLOCK_SRC_USBPLL_OUT        = 95,    /*Level 2 D0 */
    kCLOCK_SRC_USBPLL_48M        = 96,    /*Level 2 D1 */
    kCLOCK_SRC_MIPIPLL_DIV8      = 97,    /*Level 2 D2 */
    kCLOCK_SRC_MEDIAPLL          = 98,    /*Level 2 L1 */

    /* --- C.4: external -- board override via CLOCK_GetExternalSrcFreq --- */
    kCLOCK_SRC_SAI0_MCLK         = 99,    /* L0 only, EXT */
    kCLOCK_SRC_SAI1_MCLK         = 100,   /* L0 only, EXT */
    kCLOCK_SRC_SAI2_MCLK         = 101,   /* L0 only, EXT */

    /* --- C.5: hardwired zero input --- */
    kCLOCK_SRC_TIE_LOW           = 102,   /* L0 only */

    kCLOCK_SRC_Invalid           = 127,   /* sentinel; not in the L1/L2 mapping */
} clock_name_t;

typedef struct _clock_root_config_t
{
    bool clockShutdown;
    uint8_t mux; /*!< See #clock_root_mux_source_t for details. */
    uint8_t div; /*!< it's the actual divider */
    uint8_t sndDiv; /*!< Second divider, if applicable */
} clock_root_config_t;

/*******************************************************************************
 * CGUANA Definitions
 ******************************************************************************/

/*!
 * @defgroup cguana_fsm_resource CGUANA FSM resource bits
 * @{
 * These bits are used in CGUAD_CTRL_REG.CGUAD_FSM_SW_ON_REQ[8:0],
 * CGUAD_CTRL_REG.CGUAD_FSM_SW_OFF_REQ[8:0], and
 * CGUAD_CTRL_STS.CGUAD_FSM_RDY[7:0] (FRO12M_WAKE has no RDY bit).
 */
#define CLOCK_CGUANA_FSM_LDOA         (1U << 0U)  /*!< LDOA 0.8 V */
#define CLOCK_CGUANA_FSM_FRO192M      (1U << 1U)  /*!< FRO 192 MHz */
#define CLOCK_CGUANA_FSM_FRO12M       (1U << 2U)  /*!< FRO 12 MHz */
#define CLOCK_CGUANA_FSM_MAINPLL      (1U << 3U)  /*!< Main PLL */
#define CLOCK_CGUANA_FSM_COREPLL      (1U << 4U)  /*!< Core PLL */
#define CLOCK_CGUANA_FSM_SYSPLL       (1U << 5U)  /*!< System PLL */
#define CLOCK_CGUANA_FSM_LDOQ         (1U << 6U)  /*!< LDOQ 0.8 V */
#define CLOCK_CGUANA_FSM_SXOSC        (1U << 7U)  /*!< SXOSC crystal oscillator */
#define CLOCK_CGUANA_FSM_FRO12M_WAKE  (1U << 8U)  /*!< FRO 12 MHz wake path (ON_REQ only) */
/*! @} */

/*! @brief CGUANA PLL reference clock frequency selection. */
typedef enum _clock_cguana_ref_freq
{
    kCLOCK_CguanaRefFreq19p2M = 0U, /*!< 19.2 MHz */
    kCLOCK_CguanaRefFreq24M   = 1U, /*!< 24 MHz */
    kCLOCK_CguanaRefFreq32M   = 2U, /*!< 32 MHz */
    kCLOCK_CguanaRefFreq40M   = 3U, /*!< 40 MHz */
} clock_cguana_ref_freq_t;

/*!
 * @brief PLL reference clock source selector.
 *
 * Maps to CGUANA CGUA_CTRL_REG bits CGUA_CLKGEN_CMS_PLL_CKIN_SEL (bit 22, Core/
 * Main/Sys PLLs) and CGUA_CLKGEN_AV_PLL_CKIN_SEL (bit 23, Audio/Video PLLs).
 * Both legs are nominally 24 MHz on RT2660.
 */
typedef enum _clock_pll_ref_src
{
    kCLOCK_PllRefSrc_FRO192M_24M = 0U, /*!< 24 MHz output of FRO192M */
    kCLOCK_PllRefSrc_SXOSC       = 1U, /*!< SXOSC output clock */
} clock_pll_ref_src_t;

/*! @brief CGUANA PLL starting (calibration) mode. */
typedef enum _clock_cguana_pll_start_mode
{
    kCLOCK_CguanaPllStartFull    = 0U, /*!< Full auto with VCO calibration */
    kCLOCK_CguanaPllStartSkipCal = 3U, /*!< Skip VCO calibration (reuses stored cal value) */
} clock_cguana_pll_start_mode_t;

/*! @brief SXOSC oscillator mode selection. */
typedef enum _clock_cguana_sxosc_mode
{
    kCLOCK_CguanaSxoscModeCrystal       = 0U, /*!< Crystal (differential) mode */
    kCLOCK_CguanaSxoscModeAcSlave       = 1U, /*!< AC-coupled slave mode */
    kCLOCK_CguanaSxoscModeDcBypass      = 2U, /*!< DC-bypass mode */
    kCLOCK_CguanaSxoscModeDcBypassNoDet = 3U, /*!< DC-bypass without level detector */
} clock_cguana_sxosc_mode_t;

/*! @brief FRO 192 MHz oscillator trimming word band (OTWB) selection. */
typedef enum _clock_cguana_fro192m_otwb
{
    kCLOCK_CguanaFro192mOtwb96M  = 0U, /*!<  96 MHz band */
    kCLOCK_CguanaFro192mOtwb120M = 1U, /*!< 120 MHz band */
    kCLOCK_CguanaFro192mOtwb144M = 2U, /*!< 144 MHz band */
    kCLOCK_CguanaFro192mOtwb192M = 3U, /*!< 192 MHz band */
    kCLOCK_CguanaFro192mOtwb240M = 4U, /*!< 240 MHz band */
    kCLOCK_CguanaFro192mOtwb288M = 5U, /*!< 288 MHz band */
    kCLOCK_CguanaFro192mOtwb384M = 6U, /*!< 384 MHz band */
    kCLOCK_CguanaFro192mOtwb480M = 7U, /*!< 480 MHz band */
} clock_cguana_fro192m_otwb_t;

/*! @brief FRO 12 MHz oscillator trimming word band (OTWB) selection. */
typedef enum _clock_cguana_fro12m_otwb
{
    kCLOCK_CguanaFro12mOtwb8M      = 0U, /*!<  8 MHz band */
    kCLOCK_CguanaFro12mOtwb10M     = 1U, /*!< 10 MHz band */
    kCLOCK_CguanaFro12mOtwb12M     = 2U, /*!< 12 MHz band */
    kCLOCK_CguanaFro12mOtwb12p288M = 3U, /*!< 12.288 MHz band */
    kCLOCK_CguanaFro12mOtwb16M     = 4U, /*!< 16 MHz band */
    kCLOCK_CguanaFro12mOtwb20M     = 5U, /*!< 20 MHz band */
    kCLOCK_CguanaFro12mOtwb24M     = 6U, /*!< 24 MHz band */
    kCLOCK_CguanaFro12mOtwb32M     = 7U, /*!< 32 MHz band */
} clock_cguana_fro12m_otwb_t;

/*! @brief Main/System fractional PLL VCO frequency selection. */
typedef enum _clock_cguana_frac_pll_vco_freq
{
    kCLOCK_CguanaFracPllVco2000M = 0U, /*!< 2000 MHz */
    kCLOCK_CguanaFracPllVco1950M = 1U, /*!< 1950 MHz */
    kCLOCK_CguanaFracPllVco1900M = 2U, /*!< 1900 MHz */
    kCLOCK_CguanaFracPllVco1850M = 3U, /*!< 1850 MHz */
} clock_cguana_frac_pll_vco_freq_t;

/*! @brief Spread-spectrum (SSCG) configuration, shared by frac PLLs and AV PLLs. */
typedef struct _clock_cguana_sscg_config
{
    uint16_t stop;        /*!< Modulation frequency setting (SSCG_STOP) */
    uint16_t step;        /*!< Modulation amplitude setting (SSCG_STEP) */
    bool     centerSpread; /*!< false=downspread, true=centerspread */
} clock_cguana_sscg_config_t;

/*! @brief SXOSC crystal oscillator configuration. */
typedef struct _clock_cguana_sxosc_config
{
    clock_cguana_sxosc_mode_t modeSel; /*!< Oscillator operating mode */
    uint8_t                   gmSel;        /*!< Oscillator GM selection [2:0] */
    uint8_t                   xtal1CapTrim; /*!< XTAL1 pad capacitor trim [5:0] */
    uint8_t                   xtal2CapTrim; /*!< XTAL2 pad capacitor trim [5:0] */
    uint8_t                   detTrim;      /*!< Level detector trim [1:0] */
    bool                      clkDiv2En;    /*!< Enable divide-by-2 on output clock */
} clock_cguana_sxosc_config_t;

/*! @brief FRO 192 MHz configuration. */
typedef struct _clock_cguana_fro192m_config
{
    clock_cguana_fro192m_otwb_t otwb; /*!< Target frequency band selection */
} clock_cguana_fro192m_config_t;

/*! @brief FRO 12 MHz configuration. */
typedef struct _clock_cguana_fro12m_config
{
    clock_cguana_fro12m_otwb_t otwb; /*!< Target frequency band selection */
} clock_cguana_fro12m_config_t;

/*! @brief Core PLL configuration. */
typedef struct _clock_cguana_core_pll_config
{
    clock_cguana_pll_start_mode_t startMode;  /*!< Calibration/start mode */
    bool                          vcoSelHf;   /*!< false=LF VCO (600-858 MHz), true=HF VCO (858-1200 MHz) */
    clock_cguana_ref_freq_t       refFreq;    /*!< Reference clock frequency */
    uint8_t                       loopDivNint; /*!< Integer feedback division ratio [6:0] */
    bool                          postDivBy2; /*!< false=600-1200 MHz output, true=300-600 MHz output */
} clock_cguana_core_pll_config_t;

/*! @brief Fractional output divider configuration for Main/Sys PLL. */
typedef struct _clock_cguana_frac_div_config
{
    bool    en;    /*!< Enable this fractional divider output */
    bool    range; /*!< Extended range: when true, effective_div = (sel+32)/4 */
    uint8_t sel;   /*!< 5-bit division ratio: N = sel/4, output = VCO*4/sel */
} clock_cguana_frac_div_config_t;

/*! @brief Main/System PLL (fractional-N) configuration. */
typedef struct _clock_cguana_frac_pll_config
{
    clock_cguana_pll_start_mode_t    startMode; /*!< Calibration/start mode */
    clock_cguana_ref_freq_t          refFreq;   /*!< Reference clock frequency */
    clock_cguana_frac_pll_vco_freq_t lowFreq;  /*!< VCO frequency selection */
    bool                             div5En;    /*!< Enable divide-by-5 output */
    bool                             div8En;    /*!< Enable divide-by-8 output */
    bool                             div10En;   /*!< Enable divide-by-10 output */
    bool                             div20En;   /*!< Enable divide-by-20 output */
    clock_cguana_frac_div_config_t   fracDiv[3]; /*!< Three programmable fractional divider outputs */
    bool                             sscgEn;   /*!< Enable spread-spectrum clock generation */
    const                            clock_cguana_sscg_config_t *sscg;  /*!< SSCG config (may be NULL when sscgEn is false) */
} clock_cguana_frac_pll_config_t;

/*! @brief Audio/Video PLL (AV PLL) configuration.
 *
 *  The AV PLL VCO frequency is determined by:
 *    F_VCO = F_REF * DNUM / 2^24   (DNUM is 30-bit, upper 6 bits are integer part)
 *  Output frequency:
 *    F_OUT = F_VCO / postDivRatio
 */
typedef struct _clock_cguana_avpll_config
{
    clock_cguana_pll_start_mode_t startMode;   /*!< Calibration/start mode */
    clock_cguana_ref_freq_t       refFreq;     /*!< Reference clock frequency */
    uint8_t                       ccoBandSel;  /*!< CCO_FREQ_BAND_SEL [2:0] for VCO band */
    uint8_t                       postDivRatio; /*!< POSTDIV_DIVRATIO_SEL [6:0], minimum value 8 */
    uint32_t                      dnum;        /*!< 30-bit DNUM value [29:0]; F_VCO = F_REF * dnum / 2^24 */
    bool                          sscgEn;     /*!< Enable SSCG */
    const                         clock_cguana_sscg_config_t *sscg;   /*!< SSCG config (may be NULL when sscgEn is false) */
} clock_cguana_avpll_config_t;

/*! @brief USB FS (USBFS/KHCI) functional clock source (COMM usb1_fclk root mux). */
typedef enum _clock_usb_fs_src
{
    kCLOCK_UsbFsSrcUsb1Root  = kCLOCK_USB1_ClockRoot_USB1,       /*!< usb1_rootclk (root47 output, configured in clock_config) */
    kCLOCK_UsbFsSrcUsbPllOut = kCLOCK_USB1_ClockRoot_USBPLL_OUT, /*!< USB PHY PLL 480M direct out (needs /10 in root -> 48M) */
    kCLOCK_UsbFsSrcUsbPll48M = kCLOCK_USB1_ClockRoot_USBPLL_48M, /*!< USB PHY PLL 480M/10 = 48M (recommended, exact) */
    kCLOCK_UsbFsSrcFro48M    = kCLOCK_USB1_ClockRoot_FRO48M,     /*!< Free-running FRO 48M (RC accuracy, may not meet USB FS) */
} clock_usb_fs_src_t;

/*!
 * @brief FRO tuner (FLL) reference-clock source.
 *
 * Selects the reference against which the tuner locks an FRO. The first five
 * values use the SXOSC crystal path (CKREF_SOURCE_SEL == 0) and differ only by
 * the SXOSC frequency; the last two use a USB Start-Of-Frame pulse as the
 * reference. The enumerators are ordered to match the reference manual
 * FRO_TUNER settings tables and are used to index the internal parameter
 * tables in fsl_clock.c, so do not reorder them.
 */
typedef enum _clock_fro_tuner_src
{
    kCLOCK_FroTunerRefSxosc19M2 = 0U, /*!< SXOSC crystal at 19.2 MHz. */
    kCLOCK_FroTunerRefSxosc24M,       /*!< SXOSC crystal at 24 MHz. */
    kCLOCK_FroTunerRefSxosc32M,       /*!< SXOSC crystal at 32 MHz. */
    kCLOCK_FroTunerRefSxosc40M,       /*!< SXOSC crystal at 40 MHz. */
    kCLOCK_FroTunerRefSxosc32768Hz,   /*!< SXOSC crystal at 32.768 kHz. */
    kCLOCK_FroTunerRefUsbFsSof1kHz,   /*!< USB Full-/Low-Speed 1 kHz Start-Of-Frame. */
    kCLOCK_FroTunerRefUsbHsSof8kHz,   /*!< USB High-Speed 8 kHz Start-Of-Frame. */
} clock_fro_tuner_src_t;

/*! @brief Which FRO the tuner (FLL) locks. */
typedef enum _clock_fro_tuner_target
{
    kCLOCK_FroTuner12M = 0U, /*!< Tune the 12 MHz FRO. */
    kCLOCK_FroTuner192M,     /*!< Tune the 192 MHz FRO. */
} clock_fro_tuner_target_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @brief Enable the clock for specific IP.
 *
 * @param name  Which clock to enable, see \ref clock_lpcg_t.
 */
void CLOCK_EnableClock(clock_ip_name_t name);

/*!
 * @brief Disable the clock for specific IP.
 *
 * @param name  Which clock to disable, see \ref clock_lpcg_t.
 */
void CLOCK_DisableClock(clock_ip_name_t name);

/*!
 * @brief Program the LPCG_CFG, HSK_SEL, and HSK_BYPASS fields of a peripheral
 *        clock gate in one update.
 *
 * Writes bits[1:0] (LPCG_CFG), bits[18:16] (HSK_SEL), and bit[8] (HSK_BYPASS)
 * of the CCM SLICE_CONTROL register that owns @p name. Other bits of
 * SLICE_CONTROL are preserved. Use this when a peripheral requires more than
 * the simple on/off behavior provided by CLOCK_EnableClock / CLOCK_DisableClock,
 * for example to gate the clock automatically in Sleep / Deep Sleep or to
 * select which CMC instance(s) drive the clock-gate handshake.
 *
 * @param name             Clock IP identifier, see \ref clock_lpcg_t.
 * @param mode             Desired LPCG_CFG value (see \ref clock_gate_value_t).
 * @param hskSel           HSK_SEL value (3 bits) selecting the CMC instance(s)
 *                         that drive the clock-gate handshake for this LPCG.
 * @param bypassHandshake  If true, set HSK_BYPASS to bypass the clock-gate
 *                         handshake.  Use only for early bring-up when the
 *                         downstream CMC partner is not yet functional.
 */
void CLOCK_SetClockGateMode(clock_ip_name_t name, clock_gate_value_t mode, uint8_t hskSel,
                            bool bypassHandshake);

/*!
 * @brief Gets the clock frequency for a specific root clock name.
 *
 * This function walks the 3-layer RT2660 clock tree (L0 analog roots -> L1
 * CGUDIG mux -> L2 subsystem mux) using the current mux/divider/MODCON state
 * and returns the actual frequency for the requested root. Returns 0U for
 * out-of-range roots, invalid sources, or divider-by-zero (REQ-006). ISR-safe
 * and reentrant (REQ-009) - read-only, no locks, no critical sections.
 *
 * @param root Clock root defined in clock_root_t
 * @return Clock frequency in hertz, or 0 if it cannot be resolved.
 */
uint32_t CLOCK_GetRootClockFreq(clock_root_t root);

/*!
 * @brief Gets the frequency of an upstream clock source identified by clock_name_t.
 *
 * Resolves L0 analog roots (constants and PLL helpers), L1 CGUDIG aliases
 * (recursing into the owning root), L1/L2 SS feedback sources, MODCON-controlled
 * (Mx) values, and macro-backed PLLs (USBPLL/MEDIAPLL/MIPIPLL). Returns 0U for
 * kCLOCK_SRC_Invalid, kCLOCK_SRC_TIE_LOW, and unrecognized enum values. ISR-safe
 * and reentrant.
 *
 * @param name Source name, see clock_name_t.
 * @return Source frequency in hertz, or 0 if it cannot be resolved.
 */
uint32_t CLOCK_GetClockSrcFreq(clock_name_t name);

/*!
 * @brief Board-overridable hook returning the frequency of an external source.
 *
 * Used by CLOCK_GetClockSrcFreq to resolve external (Dx) sources whose
 * frequency the SoC cannot know on its own, including kCLOCK_SRC_SAI0_MCLK,
 * kCLOCK_SRC_SAI1_MCLK, kCLOCK_SRC_SAI2_MCLK, and any future EXT source. The
 * default weak implementation returns 0U. Board ports override it to declare
 * the actually-wired external frequency.
 *
 * @param name External source name, see clock_name_t.
 * @return External source frequency in hertz, or 0 if unknown.
 */
uint32_t CLOCK_GetExternalSrcFreq(clock_name_t name);

/*!
 * @brief Measures the actual frequency of a clock root using the FREQME hardware.
 *
 * Unlike CLOCK_GetRootClockFreq(), which computes a theoretical value from the
 * clock-tree configuration, this function measures the real signal with the
 * FREQME instance of the subsystem the root belongs to. This matters while the
 * internal FROs are untrimmed (e.g. FRO192M configured as 192 MHz may actually
 * run near 220 MHz). INPUTMUX routing, FREQME instance selection, and the
 * reference-clock chain are handled internally:
 *   - CGU and WAKE roots measure against the 24 MHz crystal (SXOSC) directly.
 *   - Roots in the CMPT/MAIN/COMM/AUDIO/MEDIA subsystems are measured by that
 *     subsystem's FREQME; its reference clock is itself first measured against
 *     SXOSC by the SYSCON FREQME, so accuracy always derives from the crystal.
 *
 * @note Preconditions: the clock under test must be enabled/running (this
 *       function never enables the measured clock; a gated target reads as a
 *       failure). The FREQME/INPUTMUX access clocks are enabled internally and
 *       restored afterwards. OSC_24M must be sourced from the SXOSC crystal
 *       (see CLOCK_SetOsc24mSource()); if it is sourced from the untrimmed
 *       FRO_24M the returned values are only as accurate as that FRO.
 * @note Blocking: one measurement takes 2^FSL_CLOCK_FREQME_REF_SCALE reference
 *       cycles (~2.73 ms at the 24 MHz reference with the default scale of 16;
 *       a two-level measurement roughly doubles that). If the target is too
 *       slow (or gated) the measurement is automatically retried with a larger
 *       scale, up to 2^24 cycles (~0.7 s) worst case before returning 0. A
 *       dead *reference* clock is detected by a bounded polling loop whose
 *       worst-case detection time at the maximum scale can reach several
 *       seconds (CPU-speed dependent) -- this only occurs in the double-fault
 *       case of an escalated retry with a dead reference.
 * @note Not ISR-safe and not reentrant: the FREQME and INPUTMUX FREQMEAS
 *       muxes of the involved subsystems are reprogrammed (those muxes serve
 *       only the FREQME and are not restored), and the FREQME access gate
 *       save/restore is a non-atomic read-modify-write.
 *
 * @param root Clock root defined in clock_root_t.
 * @return Measured frequency in hertz, or 0 on failure: root out of range,
 *         measurement timeout (reference dead), or result under/overflow
 *         (target dead/gated, or outside the 2 GHz ceiling).
 */
uint32_t CLOCK_MeasureRootClockFreq(clock_root_t root);

/*!
 * @brief Measures the actual frequency of a clock source using the FREQME hardware.
 *
 * Companion of CLOCK_GetClockSrcFreq() that returns a measured value instead
 * of a computed one; see CLOCK_MeasureRootClockFreq() for the measurement
 * chain, preconditions, and blocking behavior.
 *
 * Supported are the in-map sources (below kCLOCK_SRC_BOUNDARY): each resolves
 * to its owning clock root and is measured there, with the MODCON /2 of the
 * six kCLOCK_SRC_*_DIV2 sources applied afterwards (the /2 is a deterministic
 * divider, so halving the measured parent is exact). kCLOCK_SRC_CPU is
 * measured at its dedicated hardware tap (SYSCON tar cpu_rootclk) rather than
 * derived from the MAIN tap.
 *
 * @note Terminal analog sources (kCLOCK_SRC_FRO_192M, PLL taps, external SAI
 *       MCLKs, ...) have no FREQME tap and return 0; measure the corresponding
 *       root alias instead. Beware the one-underscore difference:
 *       kCLOCK_SRC_FRO_192M (raw analog source, returns 0) vs
 *       kCLOCK_SRC_FRO192M (CGU root alias, measurable) -- use the latter, or
 *       kCLOCK_Root_CGU_FRO192M_ROOTCLK, for the FRO 192 MHz output. The same
 *       applies to the FRO_96M/FRO_48M/FRO_24M vs FRO96M/FRO48M/FRO24M pairs.
 * @note To measure the CPU clock, kCLOCK_SRC_CPU is the most direct choice
 *       (dedicated hardware tap).
 *
 * @param name Source name, see clock_name_t.
 * @return Measured frequency in hertz, or 0 if the source is not measurable,
 *         the measurement times out, or the result is out of range.
 */
uint32_t CLOCK_MeasureClockSrcFreq(clock_name_t name);

/*!
 * @brief Set the mux source for a clock root.
 * @param root  Clock root, see \ref clock_root_t.
 * @param src   Mux selection, see \ref clock_root_mux_source_t. Range 0..3.
 */
void CLOCK_SetRootClockMux(clock_root_t root, clock_root_mux_source_t src);

/*!
 * @brief Get the current mux source value of a clock root.
 * @param root  Clock root, see \ref clock_root_t.
 * @return mux selection value (0..3).
 */
uint32_t CLOCK_GetRootClockMux(clock_root_t root);

/*!
 * @brief Resolve the clock_name_t source feeding a root for the given mux selection.
 * @param root  Clock root, see \ref clock_root_t.
 * @param src   Mux selection value (0..3).
 * @return Upstream clock_name_t for that root/mux pair.
 */
clock_name_t CLOCK_GetRootClockSource(clock_root_t root, uint32_t src);

/*!
 * @brief Set the integer post-divider for a clock root.
 * @param root  Clock root, see \ref clock_root_t.
 * @param div   Divider value (1-based; must be >= 1).
 */
void CLOCK_SetRootClockDiv(clock_root_t root, uint32_t div);

/*!
 * @brief Get the current post-divider for a clock root.
 * @param root  Clock root, see \ref clock_root_t.
 * @return Divider value (1-based).
 */
uint32_t CLOCK_GetRootClockDiv(clock_root_t root);

/*!
 * @brief Power off a clock root (clockShutdown=1).
 * @param root  Clock root, see \ref clock_root_t.
 */
void CLOCK_PowerOffRootClock(clock_root_t root);

/*!
 * @brief Power on a clock root (clockShutdown=0).
 * @param root  Clock root, see \ref clock_root_t.
 */
void CLOCK_PowerOnRootClock(clock_root_t root);

/*!
 * @brief Program a clock root's mux, divider and (optional) second divider in one call.
 * @param root    Clock root, see \ref clock_root_t.
 * @param config  Pointer to the root configuration (mux/div/sndDiv/clockShutdown).
 */
void CLOCK_SetRootClock(clock_root_t root, const clock_root_config_t *config);

/* =========================================================================
 * MODCON-controlled clock-tree muxes (MCUX-88602)
 *
 * Seven L0/L2 clock-tree muxes are controlled by MODCON registers rather than
 * by CCM SLICE_CONTROL. CLOCK_GetClockSrcFreq already consumes them on the
 * Get side; the APIs below are the matching Set side so callers do not need
 * to poke MODCON_SetCFG with raw bit masks.
 * ========================================================================= */

/*!
 * @brief CLK24M_SEL MODCON selection for the OSC_24M (L0) clock.
 *
 * Maps to MAIN MODCON CLK24M_SEL_CFG.SEL (offset 0x8810).
 */
typedef enum _clock_osc_24m_src
{
    kCLOCK_Osc24mSrc_FRO_24M = 0U, /*!< OSC_24M driven by FRO 24 MHz */
    kCLOCK_Osc24mSrc_SXOSC   = 1U, /*!< OSC_24M driven by SXOSC crystal */
} clock_osc_24m_src_t;

/*!
 * @brief Select the source driving the OSC_24M L0 clock.
 *
 * @param src Source selection, see ::clock_osc_24m_src_t.
 */
void CLOCK_SetOsc24mSource(clock_osc_24m_src_t src);

/*!
 * @brief Get the current source driving the OSC_24M L0 clock.
 *
 * @return Current selection, see ::clock_osc_24m_src_t.
 */
clock_osc_24m_src_t CLOCK_GetOsc24mSource(void);

/*!
 * @brief Program one of the six MODCON-controlled /2 clock selects (Mx).
 *
 * Selects pass-through or divide-by-two for the L2 Mx sources defined in the
 * MCUX-88602 MODCON control table:
 *   - kCLOCK_SRC_MAIN_PERI0_DIV2 : MAIN  XSPI0 MODCON.CFG[PERI_ROOTCLK0]
 *   - kCLOCK_SRC_MAIN_PERI1_DIV2 : MAIN  XSPI1 MODCON.CFG[PERI_ROOTCLK1]
 *   - kCLOCK_SRC_MAINPFDX_DIV2   : MAIN  XSPI0 MODCON.CFG[MAINPFDX_ROOTCLK]
 *   - kCLOCK_SRC_COMM_PERI1_DIV2 : COMM  USDHC0 MODCON.CFG[PERI_ROOTCLK1_SEL_DIV2]
 *   - kCLOCK_SRC_COMM_PERI2_DIV2 : COMM  USDHC1 MODCON.CFG[PERI_ROOTCLK2_SEL_DIV2]
 *   - kCLOCK_SRC_COMMPFDX_DIV2   : COMM  USDHC0 MODCON.CFG[COMMPFDX_ROOTCLK_SEL_DIV2]
 *
 * SW invariant: all consumers of the same Mx source program identical /2
 * selections. CLOCK_GetClockSrcFreq reads from one canonical MODCON instance
 * per Mx; CLOCK_SetClockSrcDiv2 writes to the same instance.
 *
 * No-op for any other ::clock_name_t value.
 *
 * @param src     One of the six kCLOCK_SRC_*_DIV2 sources above.
 * @param useDiv2 false = pass-through (/1); true = divide by 2 (/2).
 */
void CLOCK_SetClockSrcDiv2(clock_name_t src, bool useDiv2);

/*!
 * @brief Read the current /2 selection of a MODCON-controlled Mx source.
 *
 * @param src One of the six kCLOCK_SRC_*_DIV2 sources accepted by
 *            ::CLOCK_SetClockSrcDiv2.
 * @return false = pass-through (/1); true = divide by 2 (/2). Returns false
 *         for sources that are not MODCON-controlled.
 */
bool CLOCK_GetClockSrcDiv2(clock_name_t src);

/* =========================================================================
 * CGUANA clock source APIs
 * ========================================================================= */

/*!
 * @brief Initialize the SXOSC crystal oscillator.
 *
 * Configures SXOSC analog parameters and requests the CGUANA FSM to power on
 * and enable SXOSC. Blocks until the FSM reports SXOSC ready.
 *
 * @param config  Pointer to SXOSC configuration; must not be NULL.
 */
void CLOCK_InitSxosc(const clock_cguana_sxosc_config_t *config);

/*!
 * @brief De-initialize the SXOSC crystal oscillator.
 *
 * Requests the CGUANA FSM to power off SXOSC.
 */
void CLOCK_DeinitSxosc(void);

/*!
 * @brief Initialize the FRO 192 MHz oscillator.
 *
 * Configures the oscillator band and requests FSM enable. Blocks until ready.
 *
 * @param config  Pointer to FRO192M configuration; must not be NULL.
 */
void CLOCK_InitFro192M(const clock_cguana_fro192m_config_t *config);

/*!
 * @brief De-initialize the FRO 192 MHz oscillator.
 */
void CLOCK_DeinitFro192M(void);

/*!
 * @brief Initialize the FRO 12 MHz oscillator.
 *
 * @param config  Pointer to FRO12M configuration; must not be NULL.
 */
void CLOCK_InitFro12M(const clock_cguana_fro12m_config_t *config);

/*!
 * @brief De-initialize the FRO 12 MHz oscillator.
 */
void CLOCK_DeinitFro12M(void);

/* =========================================================================
 * CGUANA PLL APIs
 * ========================================================================= */

/*!
 * @brief Initialize the Core PLL.
 *
 * Configures Core PLL registers and requests FSM enable. Blocks until ready.
 *
 * @param config  Pointer to Core PLL configuration; must not be NULL.
 */
void CLOCK_InitCorePll(const clock_cguana_core_pll_config_t *config);

/*!
 * @brief De-initialize the Core PLL.
 */
void CLOCK_DeinitCorePll(void);

/*!
 * @brief Get the Core PLL output frequency.
 *
 * Reads the current FREF, LOOPDIV_NINT, and POSTDIV register settings.
 *
 * @return Core PLL output frequency in Hz, or 0 if PLL is not ready.
 */
uint32_t CLOCK_GetCorePllFreq(void);

/*!
 * @brief Initialize the Main PLL.
 *
 * Configures Main PLL fractional-N registers and requests FSM enable. Blocks until ready.
 *
 * @param config  Pointer to Main PLL configuration; must not be NULL.
 */
void CLOCK_InitMainPll(const clock_cguana_frac_pll_config_t *config);

/*!
 * @brief De-initialize the Main PLL.
 */
void CLOCK_DeinitMainPll(void);

/*!
 * @brief Get the Main PLL VCO frequency.
 *
 * Reads the LOWFREQ band-select field and returns the base VCO frequency,
 * one of 2 GHz / 1.95 GHz / 1.90 GHz / 1.85 GHz. The integer-divider outputs
 * DIV4/DIV5/DIV8/DIV10/DIV20 are simply VCO / N at the call site.
 *
 * @return VCO frequency in Hz.
 */
uint32_t CLOCK_GetMainPllVcoFreq(void);

/*!
 * @brief Get the Main PLL fractional output frequency (DIVOUT0 / DIVOUT1 / DIVOUT2).
 *
 * @param fracIdx  Fractional output index: 0 = DIVOUT0, 1 = DIVOUT1, 2 = DIVOUT2.
 * @return Output frequency in Hz, or 0 if the output is disabled.
 */
uint32_t CLOCK_GetMainPllFreq(uint8_t fracIdx);

/*!
 * @brief Initialize the System PLL.
 *
 * @param config  Pointer to System PLL configuration; must not be NULL.
 */
void CLOCK_InitSysPll(const clock_cguana_frac_pll_config_t *config);

/*!
 * @brief De-initialize the System PLL.
 */
void CLOCK_DeinitSysPll(void);

/*!
 * @brief Get the System PLL VCO frequency.
 *
 * See CLOCK_GetMainPllVcoFreq -- same VCO/integer-divider relationship.
 *
 * @return VCO frequency in Hz.
 */
uint32_t CLOCK_GetSysPllVcoFreq(void);

/*!
 * @brief Get the System PLL fractional output frequency (DIVOUT0 / DIVOUT1 / DIVOUT2).
 *
 * @param fracIdx  Fractional output index: 0 = DIVOUT0, 1 = DIVOUT1, 2 = DIVOUT2.
 * @return Output frequency in Hz, or 0 if disabled.
 */
uint32_t CLOCK_GetSysPllFreq(uint8_t fracIdx);

/*!
 * @brief Initialize the Audio PLL.
 *
 * Configures Audio PLL registers and performs the direct enable sequence
 * (PWREN -> PWRACK -> RSTN -> PLL_EN -> READY -> CLKOUT_EN).
 *
 * @param config  Pointer to Audio PLL configuration; must not be NULL.
 */
void CLOCK_InitAudioPll(const clock_cguana_avpll_config_t *config);

/*!
 * @brief De-initialize the Audio PLL.
 */
void CLOCK_DeinitAudioPll(void);

/*!
 * @brief Get the Audio PLL output frequency.
 *
 * @return Audio PLL output frequency in Hz. Uses DNUM as 6.24 fixed-point
 *         (F_VCO = F_REF * DNUM / 2^24) divided by POSTDIV.
 */
uint32_t CLOCK_GetAudioPllFreq(void);

/*!
 * @brief Update the Audio PLL output frequency via DNUM.
 *
 * Issues a DNUM update request and waits for the acknowledgement.
 *
 * @param dnum  New 30-bit DNUM value [29:0].
 */
void CLOCK_UpdateAudioPllDnum(uint32_t dnum);

/*!
 * @brief Initialize the Video PLL.
 *
 * @param config  Pointer to Video PLL configuration; must not be NULL.
 */
void CLOCK_InitVideoPll(const clock_cguana_avpll_config_t *config);

/*!
 * @brief De-initialize the Video PLL.
 */
void CLOCK_DeinitVideoPll(void);

/*!
 * @brief Get the Video PLL output frequency.
 *
 * @return Video PLL output frequency in Hz.
 */
uint32_t CLOCK_GetVideoPllFreq(void);

/*!
 * @brief Update the Video PLL output frequency via DNUM.
 *
 * @param dnum  New 30-bit DNUM value [29:0].
 */
void CLOCK_UpdateVideoPllDnum(uint32_t dnum);

/*!
 * @brief Select the reference clock source feeding the Core, Main and System PLLs.
 *
 * Writes CGUANA CGUA_CTRL_REG.CGUA_CLKGEN_CMS_PLL_CKIN_SEL (bit 22).
 *
 * @param src Source selection, see ::clock_pll_ref_src_t.
 */
void CLOCK_SetCmsPllRefSource(clock_pll_ref_src_t src);

/*!
 * @brief Get the current reference clock source feeding the Core, Main and System PLLs.
 *
 * @return Current selection, see ::clock_pll_ref_src_t.
 */
clock_pll_ref_src_t CLOCK_GetCmsPllRefSource(void);

/*!
 * @brief Select the reference clock source feeding the Audio and Video PLLs.
 *
 * Writes CGUANA CGUA_CTRL_REG.CGUA_CLKGEN_AV_PLL_CKIN_SEL (bit 23).
 *
 * @param src Source selection, see ::clock_pll_ref_src_t.
 */
void CLOCK_SetAvPllRefSource(clock_pll_ref_src_t src);

/*!
 * @brief Get the current reference clock source feeding the Audio and Video PLLs.
 *
 * @return Current selection, see ::clock_pll_ref_src_t.
 */
clock_pll_ref_src_t CLOCK_GetAvPllRefSource(void);

/*!
 * @brief Fractional-N PLL identifier (Main or System PLL).
 *
 * The two fractional-N PLLs on RT2660 (Main and System) share an identical
 * register layout in PERI_CGUANA.h: PLLn_PLL1_REG holds the integer divider
 * enables (DIV5/8/10/20 at bits 3/5/7/9) and PLLn_PLL2_REG holds the
 * fractional divider enables (DIVFRAC0/1/2 at bits 0/8/16). The identical
 * layout is exploited by CLOCK_EnableMainSysPllOutput and peers to keep the
 * per-output mapping table single-copy.
 */
typedef enum _clock_main_sys_pll
{
    kCLOCK_MainSysPll_Main = 0U, /*!< Main PLL   (CGUA_MAINPLL_PLL1_REG / CGUA_MAINPLL_PLL2_REG). */
    kCLOCK_MainSysPll_Sys  = 1U, /*!< System PLL (CGUA_SYSPLL_PLL1_REG  / CGUA_SYSPLL_PLL2_REG).  */

    kCLOCK_MainSysPll_Count      /*!< Sentinel — not a valid PLL identifier. */
} clock_main_sys_pll_t;

/*!
 * @brief Fractional-N PLL divider output identifier.
 *
 * Each enumerator names one divider output tap of a Main/System PLL. The
 * physical bit position in the PLL's PLL1_REG / PLL2_REG is documented in
 * the trailing comment. Because Main and System PLLs share the same bit
 * layout, one enumerator value is valid for either PLL — the target PLL
 * is selected by the ::clock_main_sys_pll_t argument to the API.
 */
typedef enum _clock_main_sys_pll_output
{
    /* PLL1_REG divider outputs */
    kCLOCK_MainSysPllOutput_Div5,     /*!< PLL1_REG bit 3  — MAINPLL_DIV5_EN / SYSPLL_DIV5_EN. */
    kCLOCK_MainSysPllOutput_Div8,     /*!< PLL1_REG bit 5  — MAINPLL_DIV8_EN / SYSPLL_DIV8_EN. */
    kCLOCK_MainSysPllOutput_Div10,    /*!< PLL1_REG bit 7  — MAINPLL_DIV10_EN / SYSPLL_DIV10_EN. */
    kCLOCK_MainSysPllOutput_Div20,    /*!< PLL1_REG bit 9  — MAINPLL_DIV20_EN / SYSPLL_DIV20_EN. */
    /* PLL2_REG fractional divider outputs */
    kCLOCK_MainSysPllOutput_Divfrac0, /*!< PLL2_REG bit 0  — MAINPLL_DIVFRAC0_EN / SYSPLL_DIVFRAC0_EN. */
    kCLOCK_MainSysPllOutput_Divfrac1, /*!< PLL2_REG bit 8  — MAINPLL_DIVFRAC1_EN / SYSPLL_DIVFRAC1_EN. */
    kCLOCK_MainSysPllOutput_Divfrac2, /*!< PLL2_REG bit 16 — MAINPLL_DIVFRAC2_EN / SYSPLL_DIVFRAC2_EN. */

    kCLOCK_MainSysPllOutput_All,      /*!< All 7 outputs at once — see the Enable/Disable/IsEnabled contracts. */

    kCLOCK_MainSysPllOutput_Count     /*!< Sentinel — not a valid output identifier. */
} clock_main_sys_pll_output_t;

/*!
 * @brief Enable one or all divider outputs of a Main/System PLL.
 *
 * If @p out names a single output (Div5/8/10/20/Divfrac0/1/2), sets the
 * single bit that gates it in the selected @p pll; every other bit of the
 * containing register is preserved. If @p out is ::kCLOCK_MainSysPllOutput_All,
 * sets all seven output-enable bits in one pass — Div5/8/10/20 in PLL1_REG
 * and Divfrac0/1/2 in PLL2_REG; every other bit of PLL1_REG and PLL2_REG is
 * preserved.
 *
 * @note This function does not poll a "ready" status bit — the caller is
 *       responsible for waiting on CGUA_MAINPLL_STS / CGUA_SYSPLL_STS if
 *       the downstream consumer needs the output to be settled.
 * @note This function does not run PLL bring-up. Use CLOCK_InitMainPll /
 *       CLOCK_InitSysPll to bring the PLL up for the first time.
 *
 * @param pll One of ::kCLOCK_MainSysPll_Main or ::kCLOCK_MainSysPll_Sys.
 * @param out One of the ::clock_main_sys_pll_output_t values, or
 *            ::kCLOCK_MainSysPllOutput_All to enable every output at once.
 */
void CLOCK_EnableMainSysPllOutput(clock_main_sys_pll_t pll, clock_main_sys_pll_output_t out);

/*!
 * @brief Disable one or all divider outputs of a Main/System PLL.
 *
 * Symmetric with CLOCK_EnableMainSysPllOutput: clears the single bit for a
 * named output, or clears all seven output-enable bits across PLL1_REG and
 * PLL2_REG when @p out is ::kCLOCK_MainSysPllOutput_All.
 *
 * @note This function does not poll a "ready" status bit.
 *
 * @param pll One of ::kCLOCK_MainSysPll_Main or ::kCLOCK_MainSysPll_Sys.
 * @param out One of the ::clock_main_sys_pll_output_t values, or
 *            ::kCLOCK_MainSysPllOutput_All to disable every output at once.
 */
void CLOCK_DisableMainSysPllOutput(clock_main_sys_pll_t pll, clock_main_sys_pll_output_t out);

/*!
 * @brief Query whether Main/System PLL divider outputs are enabled.
 *
 * If @p out names a single output, reads the corresponding PLL1_REG or
 * PLL2_REG bit and returns whether it is set. If @p out is
 * ::kCLOCK_MainSysPllOutput_All, returns @c true only when every one of
 * the seven output-enable bits is currently set (AND semantics — "are all
 * enabled?").
 *
 * @param pll One of ::kCLOCK_MainSysPll_Main or ::kCLOCK_MainSysPll_Sys.
 * @param out One of the ::clock_main_sys_pll_output_t values, or
 *            ::kCLOCK_MainSysPllOutput_All to query "all outputs enabled".
 * @return true  for a single output: its enable bit is currently 1.
 * @return true  for ::kCLOCK_MainSysPllOutput_All: all seven output-enable
 *               bits are currently 1.
 * @return false the enable bit(s) not fully set, or an argument is out of range.
 */
bool CLOCK_IsMainSysPllOutputEnabled(clock_main_sys_pll_t pll, clock_main_sys_pll_output_t out);

/*!
 * @brief Audio/Video PLL identifier.
 *
 * The two AV PLLs on RT2660 (Audio and Video) share an identical CLKOUT_EN
 * bit layout in PERI_CGUANA.h — both at bit 3 of PLLn_PLL1_REG.
 */
typedef enum _clock_av_pll
{
    kCLOCK_AvPll_Audio = 0U, /*!< Audio PLL (CGUA_AUDIOPLL_PLL1_REG bit 3). */
    kCLOCK_AvPll_Video = 1U, /*!< Video PLL (CGUA_VIDEOPLL_PLL1_REG bit 3). */

    kCLOCK_AvPll_Count       /*!< Sentinel — not a valid PLL identifier. */
} clock_av_pll_t;

/*!
 * @brief Enable the CLKOUT output of an Audio or Video PLL.
 *
 * Sets AUDIOPLL_CLKOUT_EN (or VIDEOPLL_CLKOUT_EN) in the selected PLL's
 * PLL1_REG. Every other bit of the register is preserved.
 *
 * @note This function does not poll a "ready" status bit.
 * @note This function does not run PLL bring-up. Use CLOCK_InitAudioPll /
 *       CLOCK_InitVideoPll to bring the PLL up for the first time.
 *
 * @param pll One of ::kCLOCK_AvPll_Audio or ::kCLOCK_AvPll_Video.
 */
void CLOCK_EnableAvPllClkout(clock_av_pll_t pll);

/*!
 * @brief Disable the CLKOUT output of an Audio or Video PLL.
 *
 * Clears AUDIOPLL_CLKOUT_EN (or VIDEOPLL_CLKOUT_EN) in the selected PLL's
 * PLL1_REG.
 *
 * @param pll One of ::kCLOCK_AvPll_Audio or ::kCLOCK_AvPll_Video.
 */
void CLOCK_DisableAvPllClkout(clock_av_pll_t pll);

/*!
 * @brief Query whether the CLKOUT output of an Audio or Video PLL is enabled.
 *
 * @param pll One of ::kCLOCK_AvPll_Audio or ::kCLOCK_AvPll_Video.
 * @return true  if the CLKOUT_EN bit is currently 1.
 * @return false if it is 0 or @p pll is out of range.
 */
bool CLOCK_IsAvPllClkoutEnabled(clock_av_pll_t pll);

/*!
 * @brief Enable and select the USB FS (USBFS/KHCI) functional clock source.
 *
 * Configures the USB FS SIE clock from the requested source. For PLL-based
 * sources this powers up and locks the shared USB PHY PLL (480 MHz), which also
 * ungates the USB PHY (COMM usb0) internally. The usb1_fclk clock root is
 * expected to be pre-configured in clock_config.
 *
 * For crystal-less operation (trimming an FRO from the USB frame timing), call
 * CLOCK_EnableFroTuner with ::kCLOCK_FroTunerRefUsbFsSof1kHz as the reference
 * source after this function.
 *
 * @param src One of ::clock_usb_fs_src_t selecting the USB FS clocking path.
 * @retval true  USB FS clock configured (PHY PLL locked for PLL-based sources).
 * @retval false The USB PHY PLL failed to lock (invalid reference/multiplier).
 */
bool CLOCK_EnableUsbFsClock(clock_usb_fs_src_t src);

/*!
 * @brief Disable the USB FS (USBFS/KHCI) functional clock.
 *
 * Powers down the shared USB PHY PLL (which also gates the USB PHY, COMM usb0)
 * and powers off the usb1_fclk clock root. Call this only after all USB HS
 * consumers of the shared PHY PLL have been disabled.
 */
void CLOCK_DisableUsbFsClock(void);

/*!
 * @brief Enable and configure the USB HS (USBHS/EHCI) clocks.
 *
 * Selects FRO48M on the usb0_fro48m root as the HS reference, powers up and
 * locks the shared USB PHY PLL (480 MHz), then releases the USB HS controller
 * from reset and issues the controller-level soft reset. The USB PHY (COMM
 * usb0) is ungated inside CLOCK_EnableUsbPhyPllClock.
 *
 * For crystal-less operation (trimming an FRO from the USB frame timing), call
 * CLOCK_EnableFroTuner with ::kCLOCK_FroTunerRefUsbHsSof8kHz as the reference
 * source after this function.
 *
 * @retval true  USB HS clocks configured and the PHY PLL locked.
 * @retval false The USB PHY PLL failed to lock; the controller is left in reset.
 */
bool CLOCK_EnableUsbHsClock(void);

/*!
 * @brief Disable the USB HS (USBHS/EHCI) clocks.
 *
 * Reverses CLOCK_EnableUsbHsClock: powers down the shared USB PHY PLL (which
 * also gates the USB PHY, COMM usb0) and powers off the usb0_fro48m clock root.
 */
void CLOCK_DisableUsbHsClock(void);

/*!
 * @brief Power up and lock the USB PHY PLL (shared by USB FS and USB HS).
 *
 * The single COMM USB PHY PLL produces the 480MHz output (and its /10 = 48MHz
 * tap) that feeds both the USB HS PHY and the USB FS SIE (via the USBPLL_OUT /
 * USBPLL_48M clock roots). The reference frequency is read internally from the
 * usb0_phyclk clock root; the multiplier (480MHz / reference) must be one of the
 * hardware-supported values (15, 16, 20, 22, 24, 25, 30, 40). This function
 * blocks until the PLL reports lock.
 *
 * @retval true  USB PHY PLL powered up and locked.
 * @retval false The reference is zero or yields an unsupported multiplier.
 */
bool CLOCK_EnableUsbPhyPllClock(void);

/*!
 * @brief Power down the USB PHY PLL (shared by USB FS and USB HS).
 *
 * Reverses CLOCK_EnableUsbPhyPllClock: gates the PHY clocks, stops the USB
 * clock taps (the 480MHz output and its /10 = 48MHz tap), then powers down the
 * PLL and its regulator. Call this only after all USB FS / USB HS consumers of
 * the PLL have been disabled, as the PLL is shared between them.
 */
void CLOCK_DisableUsbPhyPllClock(void);

/*!
 * @brief Enable the FRO tuner (FLL) of the selected FRO against a reference source.
 *
 * Configures and enables the CGUANA FLL that tunes either the 12 MHz FRO or the
 * 192 MHz FRO (selected by @p target ) against the chosen reference window.
 *
 * @param target Which FRO to tune, see \ref clock_fro_tuner_target_t.
 * @param src Which reference source tunes the FRO, see \ref clock_fro_tuner_src_t.
 * @param lockCriteria Number of consecutive in-window results required to declare
 *                     lock (FROxxM_LOCK_CRITERIA field, 2 bits, range 0..3). A
 *                     larger value is more robust to jitter but slower to lock; 2
 *                     is the typical default.
 *
 * @note The selected reference source must already be running before the tuner
 *       is enabled. TUNE_EN is asserted last, after all configuration fields are
 *       programmed. Call ::CLOCK_DisableFroTuner to stop tuning.
 * @note The FRO12M and FRO192M tuners share the reference-source selection
 *       (CKREF_SOURCE_SEL and SXOSC_FREF_SEL are common fields), so enabling one
 *       reprograms the reference selection for both. The two FROs can therefore
 *       only be tuned against the same reference source at the same time.
 */
void CLOCK_EnableFroTuner(clock_fro_tuner_target_t target, clock_fro_tuner_src_t src, uint16_t lockCriteria);

/*!
 * @brief Disable the FRO tuner (FLL) of the selected FRO.
 *
 * Clears the selected FRO's TUNE_EN to stop tuning; the other tuner
 * configuration fields are left untouched so a subsequent ::CLOCK_EnableFroTuner
 * can re-enable with the same or a new reference source.
 *
 * @param target Which FRO tuner to disable, see \ref clock_fro_tuner_target_t.
 */
void CLOCK_DisableFroTuner(clock_fro_tuner_target_t target);

/*!
 * @brief Dump a clock-root capability table to the debug console.
 *
 * Iterates every CCM clock root from kCLOCK_Root_CGU_START to
 * kCLOCK_Root_MEDIA_END, reads STATUS1, and prints a formatted table with
 * one row per valid root.  Each row contains:
 *   - id            : numeric clock_root_t value
 *   - name          : human-readable root name string
 *   - glitch_free   : 1 if the root supports glitch-free mux switching (STATUS1.GLITCH_FREE)
 *   - divPresent    : 1 if a primary post-divider field is present (STATUS1.DIV_PRESENT)
 *   - divWidth      : bit width of the primary divider field
 *   - sndDivPresent : 1 if a secondary post-divider is available (STATUS1.SECOND_DIVIDER_PRESENT)
 *   - sndDivWidth   : bit width of the secondary divider field
 *
 * @note Compiled only when BOARD_ENABLE_CLOCK_INFO_DUMP is defined and non-zero.
 *       Requires the debug console (PRINTF) to be initialized before calling.
 */
#if defined(CLOCK_ENABLE_INFO_DUMP) && CLOCK_ENABLE_INFO_DUMP
void CLOCK_InfoDump(void);
#endif

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* _FSL_CLOCK_H_ */
