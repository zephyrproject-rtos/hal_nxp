/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XRDC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_XRDC.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for XRDC
 *
 * CMSIS Peripheral Access Layer for XRDC
 */

#if !defined(PERI_XRDC_H_)
#define PERI_XRDC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
#if !defined(XRDC_MASTER_T_)
#define XRDC_MASTER_T_
/*!
 * @addtogroup xrdc_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the XRDC mapping
 *
 * Defines the structure for the XRDC resource collections.
 */

typedef enum _xrdc_master
{
    kXRDC_MasterCM4Code             = 0U,          /**< Cortex-M4 Code Bus Master */
    kXRDC_MasterCM4System           = 1U,          /**< Cortex-M4 System Bus Master */
    kXRDC_MasterDma0                = 2U,          /**< DMA0 Bus Master */
    kXRDC_MasterCA7                 = 3U,          /**< Cortex-A7 Bus Master */
    kXRDC_MasterLcdif               = 4U,          /**< LCDIF Bus Master */
    kXRDC_MasterGpu3D               = 5U,          /**< GPU 3D Bus Master */
    kXRDC_MasterDma1                = 6U,          /**< DMA1 Bus Master */
    kXRDC_MasterAxbs2NIC1           = 7U,          /**< AXBS2NIC1 Bus Master */
    kXRDC_MasterCaam                = 8U,          /**< CAAM Bus Master */
    kXRDC_MasterUsb_0_1             = 9U,          /**< USB0/1 Bus Master */
    kXRDC_MasterViu                 = 10U,         /**< VIU Bus Master */
    kXRDC_MasterSdhc0               = 11U,         /**< SDHC0 Bus Master */
    kXRDC_MasterSdhc1               = 12U,         /**< SDHC1 Bus Master */
    kXRDC_MasterGpu2D               = 13U,         /**< GPU 2D Bus Master */
} xrdc_master_t;

/* @} */
#endif /* XRDC_MASTER_T_ */

#if !defined(XRDC_MEM_T_)
#define XRDC_MEM_T_
typedef enum _xrdc_mem
{
    kXRDC_MemMrc0_0                 = 0U,          /**< MRC0_0 Memory: Cortex-M4 TCMs */
    kXRDC_MemMrc0_1                 = 1U,          /**< MRC0_1 Memory: Cortex-M4 TCMs */
    kXRDC_MemMrc0_2                 = 2U,          /**< MRC0_2 Memory: Cortex-M4 TCMs */
    kXRDC_MemMrc0_3                 = 3U,          /**< MRC0_3 Memory: Cortex-M4 TCMs */
    kXRDC_MemMrc1_0                 = 16U,         /**< MRC1_0 Memory: QSPI Flash */
    kXRDC_MemMrc1_1                 = 17U,         /**< MRC1_1 Memory: QSPI Flash */
    kXRDC_MemMrc1_2                 = 18U,         /**< MRC1_2 Memory: QSPI Flash */
    kXRDC_MemMrc1_3                 = 19U,         /**< MRC1_3 Memory: QSPI Flash */
    kXRDC_MemMrc1_4                 = 20U,         /**< MRC1_4 Memory: QSPI Flash */
    kXRDC_MemMrc1_5                 = 21U,         /**< MRC1_5 Memory: QSPI Flash */
    kXRDC_MemMrc1_6                 = 22U,         /**< MRC1_6 Memory: QSPI Flash */
    kXRDC_MemMrc1_7                 = 23U,         /**< MRC1_7 Memory: QSPI Flash */
    kXRDC_MemMrc2_0                 = 32U,         /**< MRC2_0 Memory: SRAM0 */
    kXRDC_MemMrc2_1                 = 33U,         /**< MRC2_1 Memory: SRAM0 */
    kXRDC_MemMrc2_2                 = 34U,         /**< MRC2_2 Memory: SRAM0 */
    kXRDC_MemMrc2_3                 = 35U,         /**< MRC2_3 Memory: SRAM0 */
    kXRDC_MemMrc3_0                 = 48U,         /**< MRC3_0 Memory: SecRAM */
    kXRDC_MemMrc3_1                 = 49U,         /**< MRC3_1 Memory: SecRAM */
    kXRDC_MemMrc3_2                 = 50U,         /**< MRC3_2 Memory: SecRAM */
    kXRDC_MemMrc3_3                 = 51U,         /**< MRC3_3 Memory: SecRAM */
    kXRDC_MemMrc4_0                 = 64U,         /**< MRC4_0 Memory: FlexBus */
    kXRDC_MemMrc4_1                 = 65U,         /**< MRC4_1 Memory: FlexBus */
    kXRDC_MemMrc4_2                 = 66U,         /**< MRC4_2 Memory: FlexBus */
    kXRDC_MemMrc4_3                 = 67U,         /**< MRC4_3 Memory: FlexBus */
    kXRDC_MemMrc5_0                 = 80U,         /**< MRC5_0 Memory: SRAM1 */
    kXRDC_MemMrc5_1                 = 81U,         /**< MRC5_1 Memory: SRAM1 */
    kXRDC_MemMrc5_2                 = 82U,         /**< MRC5_2 Memory: SRAM1 */
    kXRDC_MemMrc5_3                 = 83U,         /**< MRC5_3 Memory: SRAM1 */
    kXRDC_MemMrc6_0                 = 96U,         /**< MRC6_0 Memory: MMDC Flash */
    kXRDC_MemMrc6_1                 = 97U,         /**< MRC6_1 Memory: MMDC Flash */
    kXRDC_MemMrc6_2                 = 98U,         /**< MRC6_2 Memory: MMDC Flash */
    kXRDC_MemMrc6_3                 = 99U,         /**< MRC6_3 Memory: MMDC Flash */
    kXRDC_MemMrc6_4                 = 100U,        /**< MRC6_4 Memory: MMDC Flash */
    kXRDC_MemMrc6_5                 = 101U,        /**< MRC6_5 Memory: MMDC Flash */
    kXRDC_MemMrc6_6                 = 102U,        /**< MRC6_6 Memory: MMDC Flash */
    kXRDC_MemMrc6_7                 = 103U,        /**< MRC6_7 Memory: MMDC Flash */
} xrdc_mem_t;
#endif /* XRDC_MEM_T_ */

#if !defined(XRDC_PERIPH_T_)
#define XRDC_PERIPH_T_
typedef enum _xrdc_periph
{
    kXRDC_PeriphEdma0               = 8U,          /**< Direct Memory Access Controller 0 */
    kXRDC_PeriphEdma0_tcd           = 9U,          /**< Direct Memory Access Controller 0 Transfer */
    kXRDC_PeriphRgpio0              = 15U,         /**< Rapid GPIO Controller 0 */
    kXRDC_PeriphXrdc0               = 20U,         /**< Extended Resource Domain Controller */
    kXRDC_PeriphXrdc1               = 21U,         /**< Extended Resource Domain Controller */
    kXRDC_PeriphXrdc2               = 22U,         /**< Extended Resource Domain Controller */
    kXRDC_PeriphXrdc3               = 23U,         /**< Extended Resource Domain Controller */
    kXRDC_PeriphSema42_0            = 27U,         /**< Hardware Semaphore Module 0 */
    kXRDC_PeriphDmamux0             = 32U,         /**< Direct Memory Access Multiplexer 0 */
    kXRDC_PeriphLlwu                = 33U,         /**< Low-Leakage Wakeup Unit */
    kXRDC_PeriphMu_A                = 34U,         /**< Messaging Unit - Side A */
    kXRDC_PeriphTrgmux0             = 36U,         /**< Trigger MUX Control 0 */
    kXRDC_PeriphWdog0               = 37U,         /**< Watchdog Timer 0 */
    kXRDC_PeriphPcc0                = 38U,         /**< Peripheral Clock Control 0 */
    kXRDC_PeriphScg0                = 39U,         /**< System Clock Generator 0 */
    kXRDC_PeriphCrc                 = 41U,         /**< Cyclic Redundancy Check */
    kXRDC_PeriphLtc                 = 42U,         /**< Low Power Trusted Cryptography */
    kXRDC_PeriphTrng                = 44U,         /**< True Random Number Generator */
    kXRDC_PeriphLpit0               = 45U,         /**< Low Power Interrupt Timer */
    kXRDC_PeriphLptmr0              = 46U,         /**< Low Power Timer 0 */
    kXRDC_PeriphLptmr1              = 47U,         /**< Low power Timer 1 */
    kXRDC_PeriphTpm0                = 48U,         /**< Timer/PWM Module 0 */
    kXRDC_PeriphTpm1                = 49U,         /**< Timer/PWM Module 1 */
    kXRDC_PeriphFlexio0             = 50U,         /**< Flexible IO Controller 0 */
    kXRDC_PeriphLpi2c0              = 51U,         /**< Low Power Inter-Integrated Circuit 0 */
    kXRDC_PeriphLpi2c1              = 52U,         /**< Low Power Inter-Integrated Circuit 1 */
    kXRDC_PeriphLpi2c2              = 53U,         /**< Low Power Inter-Integrated Circuit 2 */
    kXRDC_PeriphLpi2c3              = 54U,         /**< Low Power Inter-Integrated Circuit 3 */
    kXRDC_PeriphSai0                = 55U,         /**< Synchronous Audio Interface 0 */
    kXRDC_PeriphLpspi0              = 56U,         /**< Low Power Serial Peripheral Interface 0 */
    kXRDC_PeriphLpspi1              = 57U,         /**< Low Power Serial Peripheral Interface 1 */
    kXRDC_PeriphLpuart0             = 58U,         /**< Low Power Universal Asynchronous Receiver/Transmitter 0 */
    kXRDC_PeriphLpuart1             = 59U,         /**< Low Power Universal Asynchronous Receiver/Transmitter 1 */
    kXRDC_PeriphIomuxc0             = 61U,         /**< Input/Output Multiplexing Controller 0 */
    kXRDC_PeriphPctlA               = 63U,         /**< Port Interrupt Control A */
    kXRDC_PeriphPctlB               = 64U,         /**< Port Interrupt Control B */
    kXRDC_PeriphAdc0                = 65U,         /**< Analog to Digital Converter 0 */
    kXRDC_PeriphCmp0                = 66U,         /**< Analog Comparator 0 */
    kXRDC_PeriphCmp1                = 67U,         /**< Analog Comparator 1 */
    kXRDC_PeriphDac0                = 68U,         /**< Digital to Analog Converter 0 */
    kXRDC_PeriphDac1                = 69U,         /**< Digital to Analog Converter 1 */
    kXRDC_PeriphSnvs                = 112U,        /**< Secure Non-Volatile Storage */
    kXRDC_PeriphRomc0               = 144U,        /**< ROM Controller 0 */
    kXRDC_PeriphDaprom              = 145U,        /**< Debug Access Port ROM */
    kXRDC_PeriphFunnel              = 146U,        /**< Coresight Funnel */
    kXRDC_PeriphEtf                 = 147U,        /**< Embedded Trace FIFO */
    kXRDC_PeriphTpiu                = 148U,        /**< Trace Port Interface Unit */
    kXRDC_PeriphEtr                 = 149U,        /**< Embedded Trace Router */
    kXRDC_PeriphCti                 = 150U,        /**< Cross Trigger Interface */
    kXRDC_PeriphSwo                 = 151U,        /**< Single Wire Output */
    kXRDC_PeriphTimestampGen        = 152U,        /**< Timestamp Generator */
    kXRDC_PeriphA7_apb_rom          = 154U,        /**< Cortex-A7 APB ROM */
    kXRDC_PeriphA7_apb_cpu_dbg      = 155U,        /**< Cortex-A7 APB CPU Debug */
    kXRDC_PeriphA7_apb_pmu          = 156U,        /**< Cortex-A7 APB Performance Monitoring Unit */
    kXRDC_PeriphA7_apb_cti          = 157U,        /**< Cortex-A7 APB Cross Trigger Interface */
    kXRDC_PeriphA7_apb_etm          = 158U,        /**< Cortex-A7 APB Embedded Trace Module */
    kXRDC_PeriphEwm                 = 160U,        /**< External Watchdog Monitor */
    kXRDC_PeriphPmc0                = 161U,        /**< Power Management Controller 0 */
    kXRDC_PeriphSim                 = 163U,        /**< System Integration Module */
    kXRDC_PeriphCmc0                = 164U,        /**< Core Mode Controller 0 */
    kXRDC_PeriphQspi                = 165U,        /**< Quad Serial Peripheral Interface And Onthe-fly AES Decryptor */
    kXRDC_PeriphOcotp_ctrl          = 166U,        /**< On-chip One Time Programmable Controller */
    kXRDC_PeriphTpm2                = 168U,        /**< Timer/PWM Module 2 */
    kXRDC_PeriphTpm3                = 169U,        /**< Timer/PWM Module 3 */
    kXRDC_PeriphSai1                = 170U,        /**< Synchronous Audio Interface 1 */
    kXRDC_PeriphLpuart2             = 171U,        /**< Low Power Universal Asynchronous Receiver/Transmitter 2 */
    kXRDC_PeriphLpuart3             = 172U,        /**< Low Power Universal Asynchronous Receiver/Transmitter 3 */
    kXRDC_PeriphAdc1                = 173U,        /**< Analog to Digital Converter 1 */
    kXRDC_PeriphPcc1                = 178U,        /**< Peripheral Clock Control 1 */
    kXRDC_PeriphEdma1               = 264U,        /**< Direct Memory Access Controller 1 */
    kXRDC_PeriphEdma1_tcd           = 265U,        /**< Direct Memory Access Controller 1 Transfer */
    kXRDC_PeriphRgpio1              = 271U,        /**< Rapid GPIO Controller 1 */
    kXRDC_PeriphFlexbus             = 272U,        /**< External Bus Interface */
    kXRDC_PeriphSema42_1            = 283U,        /**< Hardware Semaphore Module 1 */
    kXRDC_PeriphDmamux1             = 289U,        /**< Direct Memory Access Multiplexer 1 */
    kXRDC_PeriphMu_B                = 290U,        /**< Messaging Unit - Side B */
    kXRDC_PeriphCaam                = 292U,        /**< Cryptographic Acceleration and Assurance Module */
    kXRDC_PeriphTpm4                = 293U,        /**< Timer/PWM Module 4 */
    kXRDC_PeriphTpm5                = 294U,        /**< Timer/PWM Module 5 */
    kXRDC_PeriphLpit1               = 295U,        /**< Low Power Periodic Interrupt Timer 1 */
    kXRDC_PeriphLpspi2              = 297U,        /**< Low Power Serial Peripheral Interface 2 */
    kXRDC_PeriphLpspi3              = 298U,        /**< Low Power Serial Peripheral Interface 3 */
    kXRDC_PeriphLpi2c4              = 299U,        /**< Low Power Inter-Integrated Circuit 4 */
    kXRDC_PeriphLpi2c5              = 300U,        /**< Low Power Inter-Integrated Circuit 5 */
    kXRDC_PeriphLpuart4             = 301U,        /**< Low Power Universal Asynchronous Receiver/Transmitter 4 */
    kXRDC_PeriphLpuart5             = 302U,        /**< Low Power Universal Asynchronous Receiver/Transmitter 5 */
    kXRDC_PeriphFlexio1             = 305U,        /**< Flexible Input/Ouput 1 */
    kXRDC_PeriphUsb0                = 307U,        /**< High Speed On-The-Go USB 1 */
    kXRDC_PeriphUsb1                = 308U,        /**< High Speed On-The-Go USB 2 */
    kXRDC_PeriphUsbPhy              = 309U,        /**< USB-PHY Control */
    kXRDC_PeriphUsb_pl301           = 310U,        /**< USB PL301 */
    kXRDC_PeriphUsdhc0              = 311U,        /**< ultra Secure Digital Host Controller 0 */
    kXRDC_PeriphUsdhc1              = 312U,        /**< ultra Secure Digital Host Controller 1 */
    kXRDC_PeriphTrgmux1             = 314U,        /**< Trigger Multiplexer 1 */
    kXRDC_PeriphWdog1               = 317U,        /**< Watchdog 1 */
    kXRDC_PeriphScg1                = 318U,        /**< System Clock Generator 1 */
    kXRDC_PeriphPcc2                = 319U,        /**< Peripheral Clock Control 2  */
    kXRDC_PeriphPmc1                = 320U,        /**< Power Management Control 1 */
    kXRDC_PeriphCmc1                = 321U,        /**< Core Mode Controller 1 */
    kXRDC_PeriphWdog2               = 323U,        /**< Watchdog2 */
    kXRDC_PeriphRomc1               = 400U,        /**< ROM Controller 1 */
    kXRDC_PeriphTpm6                = 417U,        /**< Timer/PWM Module 6 */
    kXRDC_PeriphTpm7                = 418U,        /**< Timer/PWM Module 7 */
    kXRDC_PeriphLpi2c6              = 420U,        /**< Low Power I2C 6 */
    kXRDC_PeriphLpi2c7              = 421U,        /**< Low Power I2C 7 */
    kXRDC_PeriphLpuart6             = 422U,        /**< Low Power UART 6 */
    kXRDC_PeriphLpuart7             = 423U,        /**< Low Power UART 7 */
    kXRDC_PeriphViu                 = 424U,        /**< Video-In Unit */
    kXRDC_PeriphDsi                 = 425U,        /**< MIPI Display Serial Interface */
    kXRDC_PeriphLcdif               = 426U,        /**< LCD Interface */
    kXRDC_PeriphMmdc                = 427U,        /**< Multi Mode DDR Controller */
    kXRDC_PeriphIomuxc1             = 428U,        /**< Input/Output Multiplexing Control 1 */
    kXRDC_PeriphIomuxc_ddr          = 429U,        /**< Input/Output Multiplexing Control DDR */
    kXRDC_PeriphPctlC               = 430U,        /**< Port Interupt Control C */
    kXRDC_PeriphPctlD               = 431U,        /**< Port Interupt Control D */
    kXRDC_PeriphPctlE               = 432U,        /**< Port Interupt Control E */
    kXRDC_PeriphPctlF               = 433U,        /**< Port Interupt Control F */
    kXRDC_PeriphPcc3                = 435U,        /**< Peripheral Clock Control 3 */
} xrdc_periph_t;
#endif /* XRDC_PERIPH_T_ */


/*!
 * @}
 */ /* end of group Mapping_Information */


/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- XRDC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XRDC_Peripheral_Access_Layer XRDC Peripheral Access Layer
 * @{
 */

/** XRDC - Size of Registers Arrays */
#define XRDC_MDACFG_COUNT                         14u
#define XRDC_MRCFG_COUNT                          7u
#define XRDC_DERRLOC_COUNT                        8u
#define XRDC_DERR_Wx_COUNT                        20u
#define XRDC_DERR_Wx_DERR_W_COUNT                 4u
#define XRDC_PID_COUNT                            4u
#define XRDC_MDA_MDA_Wx_COUNT                     2u
#define XRDC_MDA_COUNT                            14u
#define XRDC_PDAC_COUNT                           438u
#define XRDC_PDAC_PDAC_Wx_COUNT                   2u
#define XRDC_MRGD_MRGD_Wx_COUNT                   4u
#define XRDC_MRGD_COUNT                           104u

/** XRDC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control, offset: 0x0 */
       uint8_t RESERVED_0[236];
  __I  uint32_t HWCFG0;                            /**< Hardware Configuration 0, offset: 0xF0 */
  __I  uint32_t HWCFG1;                            /**< Hardware Configuration 1, offset: 0xF4 */
  __I  uint32_t HWCFG2;                            /**< Hardware Configuration 2, offset: 0xF8 */
       uint8_t RESERVED_1[4];
  __I  uint8_t MDACFG[XRDC_MDACFG_COUNT];          /**< Master Domain Assignment Configuration, array offset: 0x100, array step: 0x1 */
       uint8_t RESERVED_2[50];
  __I  uint8_t MRCFG[XRDC_MRCFG_COUNT];            /**< Memory Region Configuration, array offset: 0x140, array step: 0x1 */
       uint8_t RESERVED_3[185];
  __I  uint32_t DERRLOC[XRDC_DERRLOC_COUNT];       /**< Domain Error Location, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_4[480];
  __IO uint32_t DERR_W[XRDC_DERR_Wx_COUNT][XRDC_DERR_Wx_DERR_W_COUNT]; /**< Domain Error Word0..Domain Error Word3, array offset: 0x400, array step: index*0x10, index2*0x4, valid indices: [0-6, 16-19][0], [0-6, 16-19][1], [0-6, 16-19][3] */
       uint8_t RESERVED_5[448];
  __IO uint32_t PID[XRDC_PID_COUNT];               /**< Process Identifier, array offset: 0x700, array step: 0x4, valid indices: [0-1, 3] */
       uint8_t RESERVED_6[240];
  struct {                                         /* offset: 0x800, array step: 0x20 */
    __IO uint32_t MDA_W[XRDC_MDA_MDA_Wx_COUNT];      /**< Master Domain Assignment, array offset: 0x800, array step: index*0x20, index2*0x4, valid indices: [0-13][0], [0-1, 3][1] */
         uint8_t RESERVED_0[24];
  } MDA[XRDC_MDA_COUNT];
       uint8_t RESERVED_7[1600];
  __IO uint32_t PDAC_W[XRDC_PDAC_COUNT][XRDC_PDAC_PDAC_Wx_COUNT]; /**< Peripheral Domain Access Control, array offset: 0x1000, array step: index*0x8, index2*0x4, irregular array, not all indices are valid */
       uint8_t RESERVED_8[592];
  struct {                                         /* offset: 0x2000, array step: 0x20 */
    __IO uint32_t MRGD_W[XRDC_MRGD_MRGD_Wx_COUNT];   /**< Memory Region Descriptor, array offset: 0x2000, array step: index*0x20, index2*0x4, irregular array, not all indices are valid */
         uint8_t RESERVED_0[16];
  } MRGD[XRDC_MRGD_COUNT];
} XRDC_Type;

/* ----------------------------------------------------------------------------
   -- XRDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XRDC_Register_Masks XRDC Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define XRDC_CR_GVLD_MASK                        (0x1U)
#define XRDC_CR_GVLD_SHIFT                       (0U)
/*! GVLD - Global Valid (XRDC global enable/disable).
 *  0b0..XRDC is disabled. All accesses from all bus masters to all slaves are allowed.
 *  0b1..XRDC is enabled.
 */
#define XRDC_CR_GVLD(x)                          (((uint32_t)(((uint32_t)(x)) << XRDC_CR_GVLD_SHIFT)) & XRDC_CR_GVLD_MASK)

#define XRDC_CR_HRL_MASK                         (0x1EU)
#define XRDC_CR_HRL_SHIFT                        (1U)
/*! HRL - Hardware Revision Level */
#define XRDC_CR_HRL(x)                           (((uint32_t)(((uint32_t)(x)) << XRDC_CR_HRL_SHIFT)) & XRDC_CR_HRL_MASK)

#define XRDC_CR_MRF_MASK                         (0x80U)
#define XRDC_CR_MRF_SHIFT                        (7U)
/*! MRF - Memory Region Format
 *  0b0..Kinetis format based on ARM Cortex-M processor core definition.
 *  0b1..SMPU family format.
 */
#define XRDC_CR_MRF(x)                           (((uint32_t)(((uint32_t)(x)) << XRDC_CR_MRF_SHIFT)) & XRDC_CR_MRF_MASK)

#define XRDC_CR_VAW_MASK                         (0x100U)
#define XRDC_CR_VAW_SHIFT                        (8U)
/*! VAW - Virtualization aware
 *  0b0..Implementation is not virtualization aware.
 *  0b1..Implementation is virtualization aware.
 */
#define XRDC_CR_VAW(x)                           (((uint32_t)(((uint32_t)(x)) << XRDC_CR_VAW_SHIFT)) & XRDC_CR_VAW_MASK)

#define XRDC_CR_LK1_MASK                         (0x40000000U)
#define XRDC_CR_LK1_SHIFT                        (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define XRDC_CR_LK1(x)                           (((uint32_t)(((uint32_t)(x)) << XRDC_CR_LK1_SHIFT)) & XRDC_CR_LK1_MASK)
/*! @} */

/*! @name HWCFG0 - Hardware Configuration 0 */
/*! @{ */

#define XRDC_HWCFG0_NDID_MASK                    (0xFFU)
#define XRDC_HWCFG0_NDID_SHIFT                   (0U)
/*! NDID - Number of domains */
#define XRDC_HWCFG0_NDID(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG0_NDID_SHIFT)) & XRDC_HWCFG0_NDID_MASK)

#define XRDC_HWCFG0_NMSTR_MASK                   (0xFF00U)
#define XRDC_HWCFG0_NMSTR_SHIFT                  (8U)
/*! NMSTR - Number of bus masters */
#define XRDC_HWCFG0_NMSTR(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG0_NMSTR_SHIFT)) & XRDC_HWCFG0_NMSTR_MASK)

#define XRDC_HWCFG0_NMRC_MASK                    (0xFF0000U)
#define XRDC_HWCFG0_NMRC_SHIFT                   (16U)
/*! NMRC - Number of MRCs */
#define XRDC_HWCFG0_NMRC(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG0_NMRC_SHIFT)) & XRDC_HWCFG0_NMRC_MASK)

#define XRDC_HWCFG0_NPAC_MASK                    (0xF000000U)
#define XRDC_HWCFG0_NPAC_SHIFT                   (24U)
/*! NPAC - Number of PACs */
#define XRDC_HWCFG0_NPAC(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG0_NPAC_SHIFT)) & XRDC_HWCFG0_NPAC_MASK)

#define XRDC_HWCFG0_MID_MASK                     (0xF0000000U)
#define XRDC_HWCFG0_MID_SHIFT                    (28U)
/*! MID - Module ID */
#define XRDC_HWCFG0_MID(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG0_MID_SHIFT)) & XRDC_HWCFG0_MID_MASK)
/*! @} */

/*! @name HWCFG1 - Hardware Configuration 1 */
/*! @{ */

#define XRDC_HWCFG1_DID_MASK                     (0xFU)
#define XRDC_HWCFG1_DID_SHIFT                    (0U)
/*! DID - Domain identifier number */
#define XRDC_HWCFG1_DID(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG1_DID_SHIFT)) & XRDC_HWCFG1_DID_MASK)
/*! @} */

/*! @name HWCFG2 - Hardware Configuration 2 */
/*! @{ */

#define XRDC_HWCFG2_PIDP0_MASK                   (0x1U)
#define XRDC_HWCFG2_PIDP0_SHIFT                  (0U)
/*! PIDP0 - Process identifier
 *  0b0..Bus master 0 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 0 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP0(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP0_SHIFT)) & XRDC_HWCFG2_PIDP0_MASK)

#define XRDC_HWCFG2_PIDP1_MASK                   (0x2U)
#define XRDC_HWCFG2_PIDP1_SHIFT                  (1U)
/*! PIDP1 - Process identifier
 *  0b0..Bus master 1 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 1 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP1(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP1_SHIFT)) & XRDC_HWCFG2_PIDP1_MASK)

#define XRDC_HWCFG2_PIDP2_MASK                   (0x4U)
#define XRDC_HWCFG2_PIDP2_SHIFT                  (2U)
/*! PIDP2 - Process identifier
 *  0b0..Bus master 2 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 2 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP2(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP2_SHIFT)) & XRDC_HWCFG2_PIDP2_MASK)

#define XRDC_HWCFG2_PIDP3_MASK                   (0x8U)
#define XRDC_HWCFG2_PIDP3_SHIFT                  (3U)
/*! PIDP3 - Process identifier
 *  0b0..Bus master 3 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 3 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP3(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP3_SHIFT)) & XRDC_HWCFG2_PIDP3_MASK)

#define XRDC_HWCFG2_PIDP4_MASK                   (0x10U)
#define XRDC_HWCFG2_PIDP4_SHIFT                  (4U)
/*! PIDP4 - Process identifier
 *  0b0..Bus master 4 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 4 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP4(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP4_SHIFT)) & XRDC_HWCFG2_PIDP4_MASK)

#define XRDC_HWCFG2_PIDP5_MASK                   (0x20U)
#define XRDC_HWCFG2_PIDP5_SHIFT                  (5U)
/*! PIDP5 - Process identifier
 *  0b0..Bus master 5 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 5 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP5(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP5_SHIFT)) & XRDC_HWCFG2_PIDP5_MASK)

#define XRDC_HWCFG2_PIDP6_MASK                   (0x40U)
#define XRDC_HWCFG2_PIDP6_SHIFT                  (6U)
/*! PIDP6 - Process identifier
 *  0b0..Bus master 6 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 6 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP6(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP6_SHIFT)) & XRDC_HWCFG2_PIDP6_MASK)

#define XRDC_HWCFG2_PIDP7_MASK                   (0x80U)
#define XRDC_HWCFG2_PIDP7_SHIFT                  (7U)
/*! PIDP7 - Process identifier
 *  0b0..Bus master 7 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 7 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP7(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP7_SHIFT)) & XRDC_HWCFG2_PIDP7_MASK)

#define XRDC_HWCFG2_PIDP8_MASK                   (0x100U)
#define XRDC_HWCFG2_PIDP8_SHIFT                  (8U)
/*! PIDP8 - Process identifier
 *  0b0..Bus master 8 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 8 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP8(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP8_SHIFT)) & XRDC_HWCFG2_PIDP8_MASK)

#define XRDC_HWCFG2_PIDP9_MASK                   (0x200U)
#define XRDC_HWCFG2_PIDP9_SHIFT                  (9U)
/*! PIDP9 - Process identifier
 *  0b0..Bus master 9 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 9 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP9(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP9_SHIFT)) & XRDC_HWCFG2_PIDP9_MASK)

#define XRDC_HWCFG2_PIDP10_MASK                  (0x400U)
#define XRDC_HWCFG2_PIDP10_SHIFT                 (10U)
/*! PIDP10 - Process identifier
 *  0b0..Bus master 10 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 10 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP10(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP10_SHIFT)) & XRDC_HWCFG2_PIDP10_MASK)

#define XRDC_HWCFG2_PIDP11_MASK                  (0x800U)
#define XRDC_HWCFG2_PIDP11_SHIFT                 (11U)
/*! PIDP11 - Process identifier
 *  0b0..Bus master 11 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 11 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP11(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP11_SHIFT)) & XRDC_HWCFG2_PIDP11_MASK)

#define XRDC_HWCFG2_PIDP12_MASK                  (0x1000U)
#define XRDC_HWCFG2_PIDP12_SHIFT                 (12U)
/*! PIDP12 - Process identifier
 *  0b0..Bus master 12 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 12 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP12(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP12_SHIFT)) & XRDC_HWCFG2_PIDP12_MASK)

#define XRDC_HWCFG2_PIDP13_MASK                  (0x2000U)
#define XRDC_HWCFG2_PIDP13_SHIFT                 (13U)
/*! PIDP13 - Process identifier
 *  0b0..Bus master 13 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 13 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP13(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP13_SHIFT)) & XRDC_HWCFG2_PIDP13_MASK)

#define XRDC_HWCFG2_PIDP14_MASK                  (0x4000U)
#define XRDC_HWCFG2_PIDP14_SHIFT                 (14U)
/*! PIDP14 - Process identifier
 *  0b0..Bus master 14 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 14 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP14(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP14_SHIFT)) & XRDC_HWCFG2_PIDP14_MASK)

#define XRDC_HWCFG2_PIDP15_MASK                  (0x8000U)
#define XRDC_HWCFG2_PIDP15_SHIFT                 (15U)
/*! PIDP15 - Process identifier
 *  0b0..Bus master 15 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 15 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP15(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP15_SHIFT)) & XRDC_HWCFG2_PIDP15_MASK)

#define XRDC_HWCFG2_PIDP16_MASK                  (0x10000U)
#define XRDC_HWCFG2_PIDP16_SHIFT                 (16U)
/*! PIDP16 - Process identifier
 *  0b0..Bus master 16 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 16 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP16(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP16_SHIFT)) & XRDC_HWCFG2_PIDP16_MASK)

#define XRDC_HWCFG2_PIDP17_MASK                  (0x20000U)
#define XRDC_HWCFG2_PIDP17_SHIFT                 (17U)
/*! PIDP17 - Process identifier
 *  0b0..Bus master 17 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 17 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP17(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP17_SHIFT)) & XRDC_HWCFG2_PIDP17_MASK)

#define XRDC_HWCFG2_PIDP18_MASK                  (0x40000U)
#define XRDC_HWCFG2_PIDP18_SHIFT                 (18U)
/*! PIDP18 - Process identifier
 *  0b0..Bus master 18 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 18 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP18(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP18_SHIFT)) & XRDC_HWCFG2_PIDP18_MASK)

#define XRDC_HWCFG2_PIDP19_MASK                  (0x80000U)
#define XRDC_HWCFG2_PIDP19_SHIFT                 (19U)
/*! PIDP19 - Process identifier
 *  0b0..Bus master 19 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 19 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP19(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP19_SHIFT)) & XRDC_HWCFG2_PIDP19_MASK)

#define XRDC_HWCFG2_PIDP20_MASK                  (0x100000U)
#define XRDC_HWCFG2_PIDP20_SHIFT                 (20U)
/*! PIDP20 - Process identifier
 *  0b0..Bus master 20 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 20 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP20(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP20_SHIFT)) & XRDC_HWCFG2_PIDP20_MASK)

#define XRDC_HWCFG2_PIDP21_MASK                  (0x200000U)
#define XRDC_HWCFG2_PIDP21_SHIFT                 (21U)
/*! PIDP21 - Process identifier
 *  0b0..Bus master 21 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 21 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP21(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP21_SHIFT)) & XRDC_HWCFG2_PIDP21_MASK)

#define XRDC_HWCFG2_PIDP22_MASK                  (0x400000U)
#define XRDC_HWCFG2_PIDP22_SHIFT                 (22U)
/*! PIDP22 - Process identifier
 *  0b0..Bus master 22 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 22 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP22(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP22_SHIFT)) & XRDC_HWCFG2_PIDP22_MASK)

#define XRDC_HWCFG2_PIDP23_MASK                  (0x800000U)
#define XRDC_HWCFG2_PIDP23_SHIFT                 (23U)
/*! PIDP23 - Process identifier
 *  0b0..Bus master 23 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 23 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP23(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP23_SHIFT)) & XRDC_HWCFG2_PIDP23_MASK)

#define XRDC_HWCFG2_PIDP24_MASK                  (0x1000000U)
#define XRDC_HWCFG2_PIDP24_SHIFT                 (24U)
/*! PIDP24 - Process identifier
 *  0b0..Bus master 24 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 24 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP24(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP24_SHIFT)) & XRDC_HWCFG2_PIDP24_MASK)

#define XRDC_HWCFG2_PIDP25_MASK                  (0x2000000U)
#define XRDC_HWCFG2_PIDP25_SHIFT                 (25U)
/*! PIDP25 - Process identifier
 *  0b0..Bus master 25 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 25 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP25(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP25_SHIFT)) & XRDC_HWCFG2_PIDP25_MASK)

#define XRDC_HWCFG2_PIDP26_MASK                  (0x4000000U)
#define XRDC_HWCFG2_PIDP26_SHIFT                 (26U)
/*! PIDP26 - Process identifier
 *  0b0..Bus master 26 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 26 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP26(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP26_SHIFT)) & XRDC_HWCFG2_PIDP26_MASK)

#define XRDC_HWCFG2_PIDP27_MASK                  (0x8000000U)
#define XRDC_HWCFG2_PIDP27_SHIFT                 (27U)
/*! PIDP27 - Process identifier
 *  0b0..Bus master 27 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 27 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP27(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP27_SHIFT)) & XRDC_HWCFG2_PIDP27_MASK)

#define XRDC_HWCFG2_PIDP28_MASK                  (0x10000000U)
#define XRDC_HWCFG2_PIDP28_SHIFT                 (28U)
/*! PIDP28 - Process identifier
 *  0b0..Bus master 28 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 28 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP28(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP28_SHIFT)) & XRDC_HWCFG2_PIDP28_MASK)

#define XRDC_HWCFG2_PIDP29_MASK                  (0x20000000U)
#define XRDC_HWCFG2_PIDP29_SHIFT                 (29U)
/*! PIDP29 - Process identifier
 *  0b0..Bus master 29 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 29 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP29(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP29_SHIFT)) & XRDC_HWCFG2_PIDP29_MASK)

#define XRDC_HWCFG2_PIDP30_MASK                  (0x40000000U)
#define XRDC_HWCFG2_PIDP30_SHIFT                 (30U)
/*! PIDP30 - Process identifier
 *  0b0..Bus master 30 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 30 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP30(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP30_SHIFT)) & XRDC_HWCFG2_PIDP30_MASK)

#define XRDC_HWCFG2_PIDP31_MASK                  (0x80000000U)
#define XRDC_HWCFG2_PIDP31_SHIFT                 (31U)
/*! PIDP31 - Process identifier
 *  0b0..Bus master 31 does not source a process identifier register. The XRDC_MDAC logic provides the needed PID for processor cores.
 *  0b1..Bus master 31 sources a process identifier register to the XRDC_MDAC logic.
 */
#define XRDC_HWCFG2_PIDP31(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP31_SHIFT)) & XRDC_HWCFG2_PIDP31_MASK)
/*! @} */

/*! @name MDACFG - Master Domain Assignment Configuration */
/*! @{ */

#define XRDC_MDACFG_NMDAR_MASK                   (0xFU)
#define XRDC_MDACFG_NMDAR_SHIFT                  (0U)
/*! NMDAR - Number of master domain assignment registers for bus master m */
#define XRDC_MDACFG_NMDAR(x)                     (((uint8_t)(((uint8_t)(x)) << XRDC_MDACFG_NMDAR_SHIFT)) & XRDC_MDACFG_NMDAR_MASK)

#define XRDC_MDACFG_NCM_MASK                     (0x80U)
#define XRDC_MDACFG_NCM_SHIFT                    (7U)
/*! NCM - Non-CPU Master
 *  0b0..Bus master is a processor.
 *  0b1..Bus master is a non-processor.
 */
#define XRDC_MDACFG_NCM(x)                       (((uint8_t)(((uint8_t)(x)) << XRDC_MDACFG_NCM_SHIFT)) & XRDC_MDACFG_NCM_MASK)
/*! @} */

/*! @name MRCFG - Memory Region Configuration */
/*! @{ */

#define XRDC_MRCFG_NMRGD_MASK                    (0x1FU)
#define XRDC_MRCFG_NMRGD_SHIFT                   (0U)
/*! NMRGD - Number of memory region descriptors for memory region controller n */
#define XRDC_MRCFG_NMRGD(x)                      (((uint8_t)(((uint8_t)(x)) << XRDC_MRCFG_NMRGD_SHIFT)) & XRDC_MRCFG_NMRGD_MASK)
/*! @} */

/*! @name DERRLOC - Domain Error Location */
/*! @{ */

#define XRDC_DERRLOC_MRCINST_MASK                (0xFFFFU)
#define XRDC_DERRLOC_MRCINST_SHIFT               (0U)
/*! MRCINST - MRC instance */
#define XRDC_DERRLOC_MRCINST(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_DERRLOC_MRCINST_SHIFT)) & XRDC_DERRLOC_MRCINST_MASK)

#define XRDC_DERRLOC_PACINST_MASK                (0xF0000U)
#define XRDC_DERRLOC_PACINST_SHIFT               (16U)
/*! PACINST - PAC instance */
#define XRDC_DERRLOC_PACINST(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_DERRLOC_PACINST_SHIFT)) & XRDC_DERRLOC_PACINST_MASK)
/*! @} */

/*! @name DERR_W - Domain Error Word0..Domain Error Word3 */
/*! @{ */

#define XRDC_DERR_W_EADDR_MASK                   (0xFFFFFFFFU)
#define XRDC_DERR_W_EADDR_SHIFT                  (0U)
/*! EADDR - Error address */
#define XRDC_DERR_W_EADDR(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W_EADDR_SHIFT)) & XRDC_DERR_W_EADDR_MASK)

#define XRDC_DERR_W_EDID_MASK                    (0xFU)
#define XRDC_DERR_W_EDID_SHIFT                   (0U)
/*! EDID - Error domain identifier */
#define XRDC_DERR_W_EDID(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W_EDID_SHIFT)) & XRDC_DERR_W_EDID_MASK)

#define XRDC_DERR_W_EATR_MASK                    (0x700U)
#define XRDC_DERR_W_EATR_SHIFT                   (8U)
/*! EATR - Error attributes
 *  0b000..Secure user mode, instruction fetch access.
 *  0b001..Secure user mode, data access.
 *  0b010..Secure privileged mode, instruction fetch access.
 *  0b011..Secure privileged mode, data access.
 *  0b100..Nonsecure user mode, instruction fetch access.
 *  0b101..Nonsecure user mode, data access.
 *  0b110..Nonsecure privileged mode, instruction fetch access.
 *  0b111..Nonsecure privileged mode, data access.
 */
#define XRDC_DERR_W_EATR(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W_EATR_SHIFT)) & XRDC_DERR_W_EATR_MASK)

#define XRDC_DERR_W_ERW_MASK                     (0x800U)
#define XRDC_DERR_W_ERW_SHIFT                    (11U)
/*! ERW - Error read/write
 *  0b0..Read access
 *  0b1..Write access
 */
#define XRDC_DERR_W_ERW(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W_ERW_SHIFT)) & XRDC_DERR_W_ERW_MASK)

#define XRDC_DERR_W_EPORT_MASK                   (0x7000000U)
#define XRDC_DERR_W_EPORT_SHIFT                  (24U)
/*! EPORT - Error port */
#define XRDC_DERR_W_EPORT(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W_EPORT_SHIFT)) & XRDC_DERR_W_EPORT_MASK)

#define XRDC_DERR_W_EST_MASK                     (0xC0000000U)
#define XRDC_DERR_W_EST_SHIFT                    (30U)
/*! EST - Error state
 *  0b00..No access violation has been detected.
 *  0b01..No access violation has been detected.
 *  0b10..A single access violation has been detected.
 *  0b11..Multiple access violations for this domain have been detected by this submodule instance. Only the
 *        address and attribute information for the first error have been captured in DERR_W0_i and DERR_W1_i.
 */
#define XRDC_DERR_W_EST(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W_EST_SHIFT)) & XRDC_DERR_W_EST_MASK)

#define XRDC_DERR_W_RECR_MASK                    (0xC0000000U)
#define XRDC_DERR_W_RECR_SHIFT                   (30U)
/*! RECR - Rearm Error Capture registers */
#define XRDC_DERR_W_RECR(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W_RECR_SHIFT)) & XRDC_DERR_W_RECR_MASK)
/*! @} */

/* The count of XRDC_DERR_W */
#define XRDC_DERR_W_COUNT                        (20U)

/* The count of XRDC_DERR_W */
#define XRDC_DERR_W_COUNT2                       (4U)

/*! @name PID - Process Identifier */
/*! @{ */

#define XRDC_PID_PID_MASK                        (0x3FU)
#define XRDC_PID_PID_SHIFT                       (0U)
/*! PID - Process identifier */
#define XRDC_PID_PID(x)                          (((uint32_t)(((uint32_t)(x)) << XRDC_PID_PID_SHIFT)) & XRDC_PID_PID_MASK)

#define XRDC_PID_LMNUM_MASK                      (0x3F0000U)
#define XRDC_PID_LMNUM_SHIFT                     (16U)
/*! LMNUM - Locked Master NUMber */
#define XRDC_PID_LMNUM(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_PID_LMNUM_SHIFT)) & XRDC_PID_LMNUM_MASK)

#define XRDC_PID_ELK22H_MASK                     (0x1000000U)
#define XRDC_PID_ELK22H_SHIFT                    (24U)
/*! ELK22H - Enable (LK2 = 2) special handling */
#define XRDC_PID_ELK22H(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_PID_ELK22H_SHIFT)) & XRDC_PID_ELK22H_MASK)

#define XRDC_PID_TSM_MASK                        (0x10000000U)
#define XRDC_PID_TSM_SHIFT                       (28U)
/*! TSM - Three-state model */
#define XRDC_PID_TSM(x)                          (((uint32_t)(((uint32_t)(x)) << XRDC_PID_TSM_SHIFT)) & XRDC_PID_TSM_MASK)

#define XRDC_PID_LK2_MASK                        (0x60000000U)
#define XRDC_PID_LK2_SHIFT                       (29U)
/*! LK2 - Lock
 *  0b00..Register can be written by any secure privileged write.
 *  0b01..Register can be written by any secure privileged write.
 *  0b10..Register can only be written by a secure privileged write from bus master m.
 *  0b11..Register is locked (read-only) until the next reset.
 */
#define XRDC_PID_LK2(x)                          (((uint32_t)(((uint32_t)(x)) << XRDC_PID_LK2_SHIFT)) & XRDC_PID_LK2_MASK)
/*! @} */

/*! @name MDA_W - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W_DID_MASK                      (0x7U)
#define XRDC_MDA_W_DID_SHIFT                     (0U)
/*! DID - Domain identifier */
#define XRDC_MDA_W_DID(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_DID_SHIFT)) & XRDC_MDA_W_DID_MASK)

#define XRDC_MDA_W_DIDS_MASK                     (0x30U)
#define XRDC_MDA_W_DIDS_SHIFT                    (4U)
/*! DIDS - DID Select
 *  0b00..Use DID field of this register as the domain identifier.
 *  0b01..Use the input DID as the domain identifier.
 *  0b10..Use bits [3:2] of this register concatenated with the low-order 2 bits of the input DID (DID_in[1:0]) as the domain identifier.
 *  0b11..Reserved for future use.
 */
#define XRDC_MDA_W_DIDS(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_DIDS_SHIFT)) & XRDC_MDA_W_DIDS_MASK)

#define XRDC_MDA_W_PA_MASK                       (0x30U)
#define XRDC_MDA_W_PA_SHIFT                      (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this master to user.
 *  0b01..Force the bus attribute for this master to privileged.
 *  0b10..Use the bus master's privileged/user attribute directly.
 *  0b11..Use the bus master's privileged/user attribute directly.
 */
#define XRDC_MDA_W_PA(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_PA_SHIFT)) & XRDC_MDA_W_PA_MASK)

#define XRDC_MDA_W_PE_MASK                       (0xC0U)
#define XRDC_MDA_W_PE_SHIFT                      (6U)
/*! PE - Process identifier enable
 *  0b00..No process identifier is included in the domain hit evaluation.
 *  0b01..No process identifier is included in the domain hit evaluation.
 *  0b10..The process identifier is included in the domain hit evaluation as defined by the expression:
 *        partial_domain_hit = (PE == 10b) && ((PID & ~PIDM) == (XRDC_PIDn[PID] & ~PIDM))
 *  0b11..The process identifier is included in the domain hit evaluation as defined by the expression:
 *        partial_domain_hit = (PE == 11b) && ~((PID & ~PIDM) == (XRDC_PIDn[PID] & ~PIDM))
 */
#define XRDC_MDA_W_PE(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_PE_SHIFT)) & XRDC_MDA_W_PE_MASK)

#define XRDC_MDA_W_SA_MASK                       (0xC0U)
#define XRDC_MDA_W_SA_SHIFT                      (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this master to secure.
 *  0b01..Force the bus attribute for this master to nonsecure.
 *  0b10..Use the bus master's secure/nonsecure attribute directly.
 *  0b11..Use the bus master's secure/nonsecure attribute directly.
 */
#define XRDC_MDA_W_SA(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_SA_SHIFT)) & XRDC_MDA_W_SA_MASK)

#define XRDC_MDA_W_DIDB_MASK                     (0x100U)
#define XRDC_MDA_W_DIDB_SHIFT                    (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define XRDC_MDA_W_DIDB(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_DIDB_SHIFT)) & XRDC_MDA_W_DIDB_MASK)

#define XRDC_MDA_W_PIDM_MASK                     (0x3F00U)
#define XRDC_MDA_W_PIDM_SHIFT                    (8U)
/*! PIDM - Process Identifier Mask */
#define XRDC_MDA_W_PIDM(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_PIDM_SHIFT)) & XRDC_MDA_W_PIDM_MASK)

#define XRDC_MDA_W_PID_MASK                      (0x3F0000U)
#define XRDC_MDA_W_PID_SHIFT                     (16U)
/*! PID - Process Identifier */
#define XRDC_MDA_W_PID(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_PID_SHIFT)) & XRDC_MDA_W_PID_MASK)

#define XRDC_MDA_W_DFMT_MASK                     (0x20000000U)
#define XRDC_MDA_W_DFMT_SHIFT                    (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define XRDC_MDA_W_DFMT(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_DFMT_SHIFT)) & XRDC_MDA_W_DFMT_MASK)

#define XRDC_MDA_W_LK1_MASK                      (0x40000000U)
#define XRDC_MDA_W_LK1_SHIFT                     (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define XRDC_MDA_W_LK1(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_LK1_SHIFT)) & XRDC_MDA_W_LK1_MASK)

#define XRDC_MDA_W_VLD_MASK                      (0x80000000U)
#define XRDC_MDA_W_VLD_SHIFT                     (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define XRDC_MDA_W_VLD(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_VLD_SHIFT)) & XRDC_MDA_W_VLD_MASK)
/*! @} */

/* The count of XRDC_MDA_W */
#define XRDC_MDA_W_COUNT                         (14U)

/* The count of XRDC_MDA_W */
#define XRDC_MDA_W_COUNT2                        (2U)

/*! @name PDAC_W - Peripheral Domain Access Control */
/*! @{ */

#define XRDC_PDAC_W_D0ACP_MASK                   (0x7U)
#define XRDC_PDAC_W_D0ACP_SHIFT                  (0U)
/*! D0ACP - Domain 0 access control policy */
#define XRDC_PDAC_W_D0ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_D0ACP_SHIFT)) & XRDC_PDAC_W_D0ACP_MASK)

#define XRDC_PDAC_W_D1ACP_MASK                   (0x38U)
#define XRDC_PDAC_W_D1ACP_SHIFT                  (3U)
/*! D1ACP - Domain 1 access control policy */
#define XRDC_PDAC_W_D1ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_D1ACP_SHIFT)) & XRDC_PDAC_W_D1ACP_MASK)

#define XRDC_PDAC_W_D2ACP_MASK                   (0x1C0U)
#define XRDC_PDAC_W_D2ACP_SHIFT                  (6U)
/*! D2ACP - Domain 2 access control policy */
#define XRDC_PDAC_W_D2ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_D2ACP_SHIFT)) & XRDC_PDAC_W_D2ACP_MASK)

#define XRDC_PDAC_W_D3ACP_MASK                   (0xE00U)
#define XRDC_PDAC_W_D3ACP_SHIFT                  (9U)
/*! D3ACP - Domain 3 access control policy */
#define XRDC_PDAC_W_D3ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_D3ACP_SHIFT)) & XRDC_PDAC_W_D3ACP_MASK)

#define XRDC_PDAC_W_D4ACP_MASK                   (0x7000U)
#define XRDC_PDAC_W_D4ACP_SHIFT                  (12U)
/*! D4ACP - Domain 4 access control policy */
#define XRDC_PDAC_W_D4ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_D4ACP_SHIFT)) & XRDC_PDAC_W_D4ACP_MASK)

#define XRDC_PDAC_W_D5ACP_MASK                   (0x38000U)
#define XRDC_PDAC_W_D5ACP_SHIFT                  (15U)
/*! D5ACP - Domain 5 access control policy */
#define XRDC_PDAC_W_D5ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_D5ACP_SHIFT)) & XRDC_PDAC_W_D5ACP_MASK)

#define XRDC_PDAC_W_D6ACP_MASK                   (0x1C0000U)
#define XRDC_PDAC_W_D6ACP_SHIFT                  (18U)
/*! D6ACP - Domain 6 access control policy */
#define XRDC_PDAC_W_D6ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_D6ACP_SHIFT)) & XRDC_PDAC_W_D6ACP_MASK)

#define XRDC_PDAC_W_D7ACP_MASK                   (0xE00000U)
#define XRDC_PDAC_W_D7ACP_SHIFT                  (21U)
/*! D7ACP - Domain 7 access control policy */
#define XRDC_PDAC_W_D7ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_D7ACP_SHIFT)) & XRDC_PDAC_W_D7ACP_MASK)

#define XRDC_PDAC_W_SNUM_MASK                    (0xF000000U)
#define XRDC_PDAC_W_SNUM_SHIFT                   (24U)
/*! SNUM - Semaphore number */
#define XRDC_PDAC_W_SNUM(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_SNUM_SHIFT)) & XRDC_PDAC_W_SNUM_MASK)

#define XRDC_PDAC_W_LK2_MASK                     (0x60000000U)
#define XRDC_PDAC_W_LK2_SHIFT                    (29U)
/*! LK2 - Lock
 *  0b00..Entire PDACs can be written.
 *  0b01..Entire PDACs can be written.
 *  0b10..Domain x can only update the DxACP field; no other PDACs fields can be written.
 *  0b11..PDACs is locked (read-only) until the next reset.
 */
#define XRDC_PDAC_W_LK2(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_LK2_SHIFT)) & XRDC_PDAC_W_LK2_MASK)

#define XRDC_PDAC_W_SE_MASK                      (0x40000000U)
#define XRDC_PDAC_W_SE_SHIFT                     (30U)
/*! SE - Semaphore enable
 *  0b0..Do not include a semaphore in the DxACP evaluation.
 *  0b1..Include the semaphore defined by SNUM in the DxACP evaluation.
 */
#define XRDC_PDAC_W_SE(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_SE_SHIFT)) & XRDC_PDAC_W_SE_MASK)

#define XRDC_PDAC_W_VLD_MASK                     (0x80000000U)
#define XRDC_PDAC_W_VLD_SHIFT                    (31U)
/*! VLD - Valid
 *  0b0..The PDACs assignment is invalid.
 *  0b1..The PDACs assignment is valid.
 */
#define XRDC_PDAC_W_VLD(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_VLD_SHIFT)) & XRDC_PDAC_W_VLD_MASK)
/*! @} */

/* The count of XRDC_PDAC_W */
#define XRDC_PDAC_W_COUNT                        (438U)

/* The count of XRDC_PDAC_W */
#define XRDC_PDAC_W_COUNT2                       (2U)

/*! @name MRGD_W - Memory Region Descriptor */
/*! @{ */

#define XRDC_MRGD_W_D0ACP_MASK                   (0x7U)
#define XRDC_MRGD_W_D0ACP_SHIFT                  (0U)
/*! D0ACP - Domain 0 access control policy */
#define XRDC_MRGD_W_D0ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_D0ACP_SHIFT)) & XRDC_MRGD_W_D0ACP_MASK)

#define XRDC_MRGD_W_SRD_MASK                     (0xFFU)
#define XRDC_MRGD_W_SRD_SHIFT                    (0U)
/*! SRD - Subregion disable */
#define XRDC_MRGD_W_SRD(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_SRD_SHIFT)) & XRDC_MRGD_W_SRD_MASK)

#define XRDC_MRGD_W_D1ACP_MASK                   (0x38U)
#define XRDC_MRGD_W_D1ACP_SHIFT                  (3U)
/*! D1ACP - Domain 1 access control policy */
#define XRDC_MRGD_W_D1ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_D1ACP_SHIFT)) & XRDC_MRGD_W_D1ACP_MASK)

#define XRDC_MRGD_W_BASEADDR_MASK                (0xFFFFFFE0U)
#define XRDC_MRGD_W_BASEADDR_SHIFT               (5U)
/*! BASEADDR - Base Address */
#define XRDC_MRGD_W_BASEADDR(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_BASEADDR_SHIFT)) & XRDC_MRGD_W_BASEADDR_MASK)

#define XRDC_MRGD_W_D2ACP_MASK                   (0x1C0U)
#define XRDC_MRGD_W_D2ACP_SHIFT                  (6U)
/*! D2ACP - Domain 2 access control policy */
#define XRDC_MRGD_W_D2ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_D2ACP_SHIFT)) & XRDC_MRGD_W_D2ACP_MASK)

#define XRDC_MRGD_W_SZ_MASK                      (0x1F00U)
#define XRDC_MRGD_W_SZ_SHIFT                     (8U)
/*! SZ - Region Size */
#define XRDC_MRGD_W_SZ(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_SZ_SHIFT)) & XRDC_MRGD_W_SZ_MASK)

#define XRDC_MRGD_W_D3ACP_MASK                   (0xE00U)
#define XRDC_MRGD_W_D3ACP_SHIFT                  (9U)
/*! D3ACP - Domain 3 access control policy */
#define XRDC_MRGD_W_D3ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_D3ACP_SHIFT)) & XRDC_MRGD_W_D3ACP_MASK)

#define XRDC_MRGD_W_D4ACP_MASK                   (0x7000U)
#define XRDC_MRGD_W_D4ACP_SHIFT                  (12U)
/*! D4ACP - Domain 4 access control policy */
#define XRDC_MRGD_W_D4ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_D4ACP_SHIFT)) & XRDC_MRGD_W_D4ACP_MASK)

#define XRDC_MRGD_W_D5ACP_MASK                   (0x38000U)
#define XRDC_MRGD_W_D5ACP_SHIFT                  (15U)
/*! D5ACP - Domain 5 access control policy */
#define XRDC_MRGD_W_D5ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_D5ACP_SHIFT)) & XRDC_MRGD_W_D5ACP_MASK)

#define XRDC_MRGD_W_D6ACP_MASK                   (0x1C0000U)
#define XRDC_MRGD_W_D6ACP_SHIFT                  (18U)
/*! D6ACP - Domain 6 access control policy */
#define XRDC_MRGD_W_D6ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_D6ACP_SHIFT)) & XRDC_MRGD_W_D6ACP_MASK)

#define XRDC_MRGD_W_D7ACP_MASK                   (0xE00000U)
#define XRDC_MRGD_W_D7ACP_SHIFT                  (21U)
/*! D7ACP - Domain 7 access control policy */
#define XRDC_MRGD_W_D7ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_D7ACP_SHIFT)) & XRDC_MRGD_W_D7ACP_MASK)

#define XRDC_MRGD_W_SNUM_MASK                    (0xF000000U)
#define XRDC_MRGD_W_SNUM_SHIFT                   (24U)
/*! SNUM - Semaphore number */
#define XRDC_MRGD_W_SNUM(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_SNUM_SHIFT)) & XRDC_MRGD_W_SNUM_MASK)

#define XRDC_MRGD_W_LK2_MASK                     (0x60000000U)
#define XRDC_MRGD_W_LK2_SHIFT                    (29U)
/*! LK2 - Lock
 *  0b00..Entire MRGDn can be written.
 *  0b01..Reserved
 *  0b10..Domain x can only update the DxACP field for domain x; no other ACP fields can be written.
 *  0b11..MRGDn is locked (read-only) until the next reset.
 */
#define XRDC_MRGD_W_LK2(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_LK2_SHIFT)) & XRDC_MRGD_W_LK2_MASK)

#define XRDC_MRGD_W_SE_MASK                      (0x40000000U)
#define XRDC_MRGD_W_SE_SHIFT                     (30U)
/*! SE - Semaphore enable
 *  0b0..Do not include a semaphore in the DxACP evaluation.
 *  0b1..Include the semaphore defined by SNUM in the DxACP evaluation.
 */
#define XRDC_MRGD_W_SE(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_SE_SHIFT)) & XRDC_MRGD_W_SE_MASK)

#define XRDC_MRGD_W_VLD_MASK                     (0x80000000U)
#define XRDC_MRGD_W_VLD_SHIFT                    (31U)
/*! VLD - Valid
 *  0b0..The MRGDn assignment is invalid.
 *  0b1..The MRGDn assignment is valid.
 */
#define XRDC_MRGD_W_VLD(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_VLD_SHIFT)) & XRDC_MRGD_W_VLD_MASK)
/*! @} */

/* The count of XRDC_MRGD_W */
#define XRDC_MRGD_W_COUNT                        (104U)

/* The count of XRDC_MRGD_W */
#define XRDC_MRGD_W_COUNT2                       (4U)


/*!
 * @}
 */ /* end of group XRDC_Register_Masks */


/*!
 * @}
 */ /* end of group XRDC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_XRDC_H_ */

