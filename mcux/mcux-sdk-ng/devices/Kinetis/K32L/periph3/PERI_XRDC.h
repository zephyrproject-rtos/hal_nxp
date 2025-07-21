/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
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
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_XRDC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for XRDC
 *
 * CMSIS Peripheral Access Layer for XRDC
 */

#if !defined(PERI_XRDC_H_)
#define PERI_XRDC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
    kXRDC_MasterCM4CodeBus          = 0U,          /**< CM4 C-BUS */
    kXRDC_MasterCM4SystemBus        = 1U,          /**< CM4 S-BUS */
    kXRDC_MasterEdma0               = 2U,          /**< EDMA0 */
    kXRDC_MasterUsdhc               = 3U,          /**< USDHC */
    kXRDC_MasterUsb                 = 4U,          /**< USB */
    kXRDC_MasterCM0P                = 32U,         /**< CM0P */
    kXRDC_MasterEdma1               = 33U,         /**< EDMA1 */
    kXRDC_MasterCau3                = 34U,         /**< CAU3 */
} xrdc_master_t;

/* @} */
#endif /* XRDC_MASTER_T_ */

#if !defined(XRDC_MEM_T_)
#define XRDC_MEM_T_
typedef enum _xrdc_mem
{
    kXRDC_MemMrc0_0                 = 0U,          /**< MRC0 Memory 0 */
    kXRDC_MemMrc0_1                 = 1U,          /**< MRC0 Memory 1 */
    kXRDC_MemMrc0_2                 = 2U,          /**< MRC0 Memory 2 */
    kXRDC_MemMrc0_3                 = 3U,          /**< MRC0 Memory 3 */
    kXRDC_MemMrc0_4                 = 4U,          /**< MRC0 Memory 4 */
    kXRDC_MemMrc0_5                 = 5U,          /**< MRC0 Memory 5 */
    kXRDC_MemMrc0_6                 = 6U,          /**< MRC0 Memory 6 */
    kXRDC_MemMrc0_7                 = 7U,          /**< MRC0 Memory 7 */
    kXRDC_MemMrc1_0                 = 16U,         /**< MRC1 Memory 0 */
    kXRDC_MemMrc1_1                 = 17U,         /**< MRC1 Memory 1 */
    kXRDC_MemMrc1_2                 = 18U,         /**< MRC1 Memory 2 */
    kXRDC_MemMrc1_3                 = 19U,         /**< MRC1 Memory 3 */
    kXRDC_MemMrc1_4                 = 20U,         /**< MRC1 Memory 4 */
    kXRDC_MemMrc1_5                 = 21U,         /**< MRC1 Memory 5 */
    kXRDC_MemMrc1_6                 = 22U,         /**< MRC1 Memory 6 */
    kXRDC_MemMrc1_7                 = 23U,         /**< MRC1 Memory 7 */
} xrdc_mem_t;
#endif /* XRDC_MEM_T_ */

#if !defined(XRDC_PERIPH_T_)
#define XRDC_PERIPH_T_
typedef enum _xrdc_periph
{
    kXRDC_PeriphMscm                = 1U,          /**< Miscellaneous System Control Module (MSCM) */
    kXRDC_PeriphMaxcore             = 4U,          /**< MAX CORE */
    kXRDC_PeriphDma0                = 8U,          /**< Direct Memory Access 0 (DMA0) controller */
    kXRDC_PeriphDma0Tcd             = 9U,          /**< Direct Memory Access 0 (DMA0) controller transfer control descriptors */
    kXRDC_PeriphFlexBus             = 12U,         /**< External Bus Interface(FlexBus) */
    kXRDC_PeriphXrdcMgr             = 20U,         /**< Extended Resource Domain Controller (XRDC) MGR */
    kXRDC_PeriphXrdcMdac            = 21U,         /**< Extended Resource Domain Controller (XRDC) MDAC */
    kXRDC_PeriphXrdcPac             = 22U,         /**< Extended Resource Domain Controller (XRDC) PAC */
    kXRDC_PeriphXrdcMrc             = 23U,         /**< Extended Resource Domain Controller (XRDC) MRC */
    kXRDC_PeriphSema420             = 27U,         /**< Semaphore Unit 0 (SEMA420) */
    kXRDC_PeriphSmc0                = 32U,         /**< System Mode Controller 0 (SMC0) */
    kXRDC_PeriphDmamux0             = 33U,         /**< Direct Memory Access Multiplexer 0 (DMAMUX0) */
    kXRDC_PeriphEwm                 = 34U,         /**< External Watchdog Monitor (EWM) */
    kXRDC_PeriphFtfe                = 35U,         /**< Flash Memory Module (FTFE) */
    kXRDC_PeriphLlwu0               = 36U,         /**< Low Leakage Wake-up Unit 0 (LLWU0) */
    kXRDC_PeriphMua                 = 37U,         /**< Message Unit Side A (MU-A) */
    kXRDC_PeriphSim                 = 38U,         /**< System Integration Module (SIM) */
    kXRDC_PeriphUsbVreg             = 39U,         /**< USB Voltage Regulator (USBVREG) */
    kXRDC_PeriphSpm                 = 40U,         /**< System Power Management (SPM) */
    kXRDC_PeriphTrgmux0             = 41U,         /**< Tirgger Multiplexer 0 (TRGMUX0) */
    kXRDC_PeriphWdog0               = 42U,         /**< Watchdog 0 (WDOG0) */
    kXRDC_PeriphPcc0                = 43U,         /**< Peripheral Clock Controller 0 (PCC0) */
    kXRDC_PeriphScg                 = 44U,         /**< System Clock Generator (SCG) */
    kXRDC_PeriphSrf                 = 45U,         /**< System Register File */
    kXRDC_PeriphVbat                = 46U,         /**< VBAT Register File */
    kXRDC_PeriphCrc0                = 47U,         /**< Cyclic Redundancy Check 0 (CRC0) */
    kXRDC_PeriphLpit0               = 48U,         /**< Low-Power Periodic Interrupt Timer 0 (LPIT0) */
    kXRDC_PeriphRtc                 = 49U,         /**< Real Time Clock (RTC) */
    kXRDC_PeriphLptmr0              = 50U,         /**< Low-Power Timer 0 (LPTMR0) */
    kXRDC_PeriphLptmr1              = 51U,         /**< Low-Power Timer 1 (LPTMR1) */
    kXRDC_PeriphTstmra              = 52U,         /**< Time Stamp Timer A (TSTMRA) */
    kXRDC_PeriphTpm0                = 53U,         /**< Timer / Pulse Width Modulator Module 0 (TPM0) - 6 channel */
    kXRDC_PeriphTpm1                = 54U,         /**< Timer / Pulse Width Modulator Module 1 (TPM1) - 2 channel */
    kXRDC_PeriphTpm2                = 55U,         /**< Timer / Pulse Width Modulator Module 2 (TPM2) - 6 channel */
    kXRDC_PeriphEmvsim0             = 56U,         /**< Euro Mastercard Visa Secure Identity Module 0 (EMVSIM0) */
    kXRDC_PeriphFlexio0             = 57U,         /**< Flexible Input / Output 0 (FlexIO0) */
    kXRDC_PeriphLpi2c0              = 58U,         /**< Low-Power Inter-Integrated Circuit 0 (LPI2C0) */
    kXRDC_PeriphLpi2c1              = 59U,         /**< Low-Power Inter-Integrated Circuit 1 (LPI2C1) */
    kXRDC_PeriphLpi2c2              = 60U,         /**< Low-Power Inter-Integrated Circuit 2 (LPI2C2) */
    kXRDC_PeriphI2s0                = 61U,         /**< Serial Audio Interface 0 (I2S0) */
    kXRDC_PeriphSdhc0               = 62U,         /**< Secure Digital Host Controller 0 (SDHC0) */
    kXRDC_PeriphLpspi0              = 63U,         /**< Low-Power Serial Peripheral Interface 0 (LPSPI0) */
    kXRDC_PeriphLpspi1              = 64U,         /**< Low-Power Serial Peripheral Interface 1 (LPSPI1) */
    kXRDC_PeriphLpspi2              = 65U,         /**< Low-Power Serial Peripheral Interface 2 (LPSPI2) */
    kXRDC_PeriphLpuart0             = 66U,         /**< Low-Power Universal Asynchronous Receive / Transmit 0 (LPUART0) */
    kXRDC_PeriphLpuart1             = 67U,         /**< Low-Power Universal Asynchronous Receive / Transmit 1 (LPUART1) */
    kXRDC_PeriphLpuart2             = 68U,         /**< Low-Power Universal Asynchronous Receive / Transmit 2 (LPUART2) */
    kXRDC_PeriphUsb0                = 69U,         /**< Universal Serial Bus 0 (USB0) - Full Speed, Device Only */
    kXRDC_PeriphPortA               = 70U,         /**< PORTA Multiplex Control */
    kXRDC_PeriphPortB               = 71U,         /**< PORTB Multiplex Control */
    kXRDC_PeriphPortC               = 72U,         /**< PORTC Multiplex Control */
    kXRDC_PeriphPortD               = 73U,         /**< PORTD Multiplex Control */
    kXRDC_PeriphLpadc0              = 74U,         /**< Low-Power Analog-to-Digital Converter 0 (LPADC0) */
    kXRDC_PeriphLpcmp0              = 75U,         /**< Low-Power Comparator 0 (LPCMP0) */
    kXRDC_PeriphLpdac0              = 76U,         /**< Low-Power Digital-to-Analog Converter 0 (LPDAC0) */
    kXRDC_PeriphVref                = 77U,         /**< Voltage Reference (VREF) */
    kXRDC_PeriphDma1                = 136U,        /**< Direct Memory Access 1 (DMA1) controller */
    kXRDC_PeriphDma1Tcd             = 137U,        /**< Direct Memory Access 1 (DMA1) controller trasfer control descriptors */
    kXRDC_PeriphFgpio1              = 143U,        /**< IO Port Alias */
    kXRDC_PeriphSema421             = 155U,        /**< Semaphore Unit 1 (SEMA421) */
    kXRDC_PeriphSmc1                = 160U,        /**< System Mode Controller 1(SMC1) */
    kXRDC_PeriphDmamux1             = 161U,        /**< Direct Memory Access Mutiplexer 1 (DMAMUX1) */
    kXRDC_PeriphIntmux0             = 162U,        /**< Interrupt Multiplexer 0 (INTMUX0) */
    kXRDC_Periphllwu1               = 163U,        /**< Low Leakage Wake-up Unit 1 (LLWU1) */
    kXRDC_PeriphMub                 = 164U,        /**< Messaging Unit - Side B (MU-B) */
    kXRDC_PeriphTrgmux1             = 165U,        /**< Trigger Multiplexer 1 (TRGMUX1) */
    kXRDC_PeriphWdog1               = 166U,        /**< Watchdog 1 (WDOG1) */
    kXRDC_PeriphPcc1                = 167U,        /**< Peripheral Clock Controller 1 (PCC1) */
    kXRDC_PeriphCau3                = 168U,        /**< Cryptographic Acceleration Unit (CAU3) */
    kXRDC_PeriphTrng                = 169U,        /**< True Random Number Generator (TRNG) */
    kXRDC_PeriphLpit1               = 170U,        /**< Low-Power Periodic Interrupt Timer 1 (LPIT1) */
    kXRDC_PeriphLptmr2              = 171U,        /**< Low-Power Timer 2 (LPTMR2) */
    kXRDC_PeriphTstmrb              = 172U,        /**< Time Stamp Timer B (TSTMRB) */
    kXRDC_PeriphTpm3                = 173U,        /**< Timer / Pulse Width Modulation Module 3 (TPM3) - 2 channel */
    kXRDC_PeriphLpi2c3              = 174U,        /**< Low-Power Inter-Integrated Circuit 3 (LPI2C3) */
    kXRDC_PeriphLpspi3              = 181U,        /**< Low-Power Serial Peripheral Interface 3 (LPSPI3) */
    kXRDC_PeriphLpuart3             = 182U,        /**< Low-Power Universal Asynchronous Receive / Transmit 3 (LPUART3) */
    kXRDC_PeriphPortE               = 183U,        /**< PORTE Multiplex Control */
    kXRDC_PeriphLpcmp1              = 184U,        /**< Low-Power Comparator 1 (LPCMP1) */
    kXRDC_PeriphUsbRam              = 272U,        /**< USB SRAM */
    kXRDC_PeriphRgpio               = 288U,        /**< Rapid GPIO */
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
#define XRDC_MDACFG_COUNT                         35u
#define XRDC_MRC_COUNT                            2u
#define XRDC_DERRLOC_COUNT                        3u
#define XRDC_DERR_Wx_COUNT                        19u
#define XRDC_DERR_Wx_DERR_W_COUNT                 4u
#define XRDC_PID_COUNT                            33u
#define XRDC_MDA_MDA_Wx_COUNT                     2u
#define XRDC_MDA_COUNT                            35u
#define XRDC_PDAC_COUNT                           289u
#define XRDC_PDAC_PDAC_Wx_COUNT                   2u
#define XRDC_MRGD_MRGD_Wx_COUNT                   5u
#define XRDC_MRGD_COUNT                           24u

/** XRDC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control Register, offset: 0x0 */
       uint8_t RESERVED_0[236];
  __I  uint32_t HWCFG0;                            /**< Hardware Configuration Register 0, offset: 0xF0 */
  __I  uint32_t HWCFG1;                            /**< Hardware Configuration Register 1, offset: 0xF4 */
  __I  uint32_t HWCFG2;                            /**< Hardware Configuration Register 2, offset: 0xF8 */
  __I  uint32_t HWCFG3;                            /**< Hardware Configuration Register 3, offset: 0xFC */
  __I  uint8_t MDACFG[XRDC_MDACFG_COUNT];          /**< Master Domain Assignment Configuration Register, array offset: 0x100, array step: 0x1, valid indices: [0-4, 32-34] */
       uint8_t RESERVED_1[29];
  __I  uint8_t MRCFG[XRDC_MRC_COUNT];              /**< Memory Region Configuration Register, array offset: 0x140, array step: 0x1 */
       uint8_t RESERVED_2[186];
  __IO uint32_t FDID;                              /**< Fault Domain ID, offset: 0x1FC */
  __I  uint32_t DERRLOC[XRDC_DERRLOC_COUNT];       /**< Domain Error Location Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_3[500];
  __IO uint32_t DERR_W[XRDC_DERR_Wx_COUNT][XRDC_DERR_Wx_DERR_W_COUNT]; /**< Domain Error Word0 Register..Domain Error Word3 Register, array offset: 0x400, array step: index*0x10, index2*0x4, valid indices: [0-1, 16-18][0], [0-1, 16-18][1], [0-1, 16-18][3] */
       uint8_t RESERVED_4[464];
  __IO uint32_t PID[XRDC_PID_COUNT];               /**< Process Identifier, array offset: 0x700, array step: 0x4, valid indices: [0-1, 32] */
       uint8_t RESERVED_5[124];
  struct {                                         /* offset: 0x800, array step: 0x20 */
    __IO uint32_t MDA_W[XRDC_MDA_MDA_Wx_COUNT];      /**< Master Domain Assignment, array offset: 0x800, array step: index*0x20, index2*0x4, valid indices: [0-4, 32-34][0], [0-1, 32][1] */
         uint8_t RESERVED_0[24];
  } MDA[XRDC_MDA_COUNT];
       uint8_t RESERVED_6[928];
  __IO uint32_t PDAC_W[XRDC_PDAC_COUNT][XRDC_PDAC_PDAC_Wx_COUNT]; /**< Peripheral Domain Access Control, array offset: 0x1000, array step: index*0x8, index2*0x4, irregular array, not all indices are valid */
       uint8_t RESERVED_7[1784];
  struct {                                         /* offset: 0x2000, array step: 0x20 */
    __IO uint32_t MRGD_W[XRDC_MRGD_MRGD_Wx_COUNT];   /**< Memory Region Descriptor, array offset: 0x2000, array step: index*0x20, index2*0x4, valid indices: [0-7, 16-23][0], [0-7, 16-23][1], [0-7, 16-23][2], [0-7, 16-23][3], [0-7, 16-23][4] */
         uint8_t RESERVED_0[12];
  } MRGD[XRDC_MRGD_COUNT];
} XRDC_Type;

/* ----------------------------------------------------------------------------
   -- XRDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XRDC_Register_Masks XRDC Register Masks
 * @{
 */

/*! @name CR - Control Register */
/*! @{ */

#define XRDC_CR_GVLDM_MASK                       (0x1U)
#define XRDC_CR_GVLDM_SHIFT                      (0U)
/*! GVLDM - Global Valid MDACs(XRDC global enable/disable).
 *  0b0..XRDC MDACs are disabled.
 *  0b1..XRDC MDACs are enabled.
 */
#define XRDC_CR_GVLDM(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC_CR_GVLDM_SHIFT)) & XRDC_CR_GVLDM_MASK)

#define XRDC_CR_HRL_MASK                         (0x1EU)
#define XRDC_CR_HRL_SHIFT                        (1U)
/*! HRL - Hardware Revision Level */
#define XRDC_CR_HRL(x)                           (((uint32_t)(((uint32_t)(x)) << XRDC_CR_HRL_SHIFT)) & XRDC_CR_HRL_MASK)

#define XRDC_CR_VAW_MASK                         (0x100U)
#define XRDC_CR_VAW_SHIFT                        (8U)
/*! VAW - Virtualization aware
 *  0b0..Implementation is not virtualization aware.
 *  0b1..Implementation is virtualization aware.
 */
#define XRDC_CR_VAW(x)                           (((uint32_t)(((uint32_t)(x)) << XRDC_CR_VAW_SHIFT)) & XRDC_CR_VAW_MASK)

#define XRDC_CR_GVLDP_MASK                       (0x4000U)
#define XRDC_CR_GVLDP_SHIFT                      (14U)
/*! GVLDP - Global Valid for PACs/MSCs
 *  0b0..XRDC PACs/MSCs are disabled.
 *  0b1..XRDC PACs/MSCs are enabled.
 */
#define XRDC_CR_GVLDP(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC_CR_GVLDP_SHIFT)) & XRDC_CR_GVLDP_MASK)

#define XRDC_CR_GVLDC_MASK                       (0x8000U)
#define XRDC_CR_GVLDC_SHIFT                      (15U)
/*! GVLDC - Global Valid for MRCs
 *  0b0..XRDC MRCs are disabled.
 *  0b1..XRDC MRCs are enabled.
 */
#define XRDC_CR_GVLDC(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC_CR_GVLDC_SHIFT)) & XRDC_CR_GVLDC_MASK)

#define XRDC_CR_LK1_MASK                         (0x40000000U)
#define XRDC_CR_LK1_SHIFT                        (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define XRDC_CR_LK1(x)                           (((uint32_t)(((uint32_t)(x)) << XRDC_CR_LK1_SHIFT)) & XRDC_CR_LK1_MASK)
/*! @} */

/*! @name HWCFG0 - Hardware Configuration Register 0 */
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

/*! @name HWCFG1 - Hardware Configuration Register 1 */
/*! @{ */

#define XRDC_HWCFG1_DID_MASK                     (0xFU)
#define XRDC_HWCFG1_DID_SHIFT                    (0U)
/*! DID - Domain identifier number */
#define XRDC_HWCFG1_DID(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG1_DID_SHIFT)) & XRDC_HWCFG1_DID_MASK)
/*! @} */

/*! @name HWCFG2 - Hardware Configuration Register 2 */
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

/*! @name HWCFG3 - Hardware Configuration Register 3 */
/*! @{ */

#define XRDC_HWCFG3_PIDPn_MASK                   (0xFFFFFFFFU)
#define XRDC_HWCFG3_PIDPn_SHIFT                  (0U)
/*! PIDPn - Process identifier */
#define XRDC_HWCFG3_PIDPn(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG3_PIDPn_SHIFT)) & XRDC_HWCFG3_PIDPn_MASK)
/*! @} */

/*! @name MDACFG - Master Domain Assignment Configuration Register */
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

/*! @name MRCFG - Memory Region Configuration Register */
/*! @{ */

#define XRDC_MRCFG_NMRGD_MASK                    (0x1FU)
#define XRDC_MRCFG_NMRGD_SHIFT                   (0U)
/*! NMRGD - Number of memory region descriptors for memory region controller n */
#define XRDC_MRCFG_NMRGD(x)                      (((uint8_t)(((uint8_t)(x)) << XRDC_MRCFG_NMRGD_SHIFT)) & XRDC_MRCFG_NMRGD_MASK)
/*! @} */

/* The count of XRDC_MRCFG */
#define XRDC_MRCFG_COUNT                         (2U)

/*! @name FDID - Fault Domain ID */
/*! @{ */

#define XRDC_FDID_FDID_MASK                      (0xFU)
#define XRDC_FDID_FDID_SHIFT                     (0U)
/*! FDID - Domain ID of Faulted Access */
#define XRDC_FDID_FDID(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_FDID_FDID_SHIFT)) & XRDC_FDID_FDID_MASK)
/*! @} */

/*! @name DERRLOC - Domain Error Location Register */
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

/*! @name DERR_W - Domain Error Word0 Register..Domain Error Word3 Register */
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
/*! RECR - Rearm Error Capture Registers */
#define XRDC_DERR_W_RECR(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W_RECR_SHIFT)) & XRDC_DERR_W_RECR_MASK)
/*! @} */

/* The count of XRDC_DERR_W */
#define XRDC_DERR_W_COUNT                        (19U)

/* The count of XRDC_DERR_W */
#define XRDC_DERR_W_COUNT2                       (4U)

/*! @name PID - Process Identifier */
/*! @{ */

#define XRDC_PID_PID_MASK                        (0x3FU)
#define XRDC_PID_PID_SHIFT                       (0U)
/*! PID - Process identifier */
#define XRDC_PID_PID(x)                          (((uint32_t)(((uint32_t)(x)) << XRDC_PID_PID_SHIFT)) & XRDC_PID_PID_MASK)

#define XRDC_PID_SP4SM_MASK                      (0x8000000U)
#define XRDC_PID_SP4SM_SHIFT                     (27U)
/*! SP4SM - Special 4-state model */
#define XRDC_PID_SP4SM(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_PID_SP4SM_SHIFT)) & XRDC_PID_SP4SM_MASK)

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

#define XRDC_MDA_W_DID_MASK                      (0xFU)
#define XRDC_MDA_W_DID_SHIFT                     (0U)
/*! DID - Domain identifier */
#define XRDC_MDA_W_DID(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_DID_SHIFT)) & XRDC_MDA_W_DID_MASK)

#define XRDC_MDA_W_DIDS_MASK                     (0x30U)
#define XRDC_MDA_W_DIDS_SHIFT                    (4U)
/*! DIDS - DID Select
 *  0b00..Use MDAm[3:0] as the domain identifier.
 *  0b01..Use the input DID as the domain identifier.
 *  0b10..Use MDAm[3:2] concatenated with the low-order 2 bits of the input DID (DID_in[1:0]) as the domain identifier.
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
 *        partial_domain_hit = (PE == 2) && ((PID & ~PIDM) == (XRDC_PIDn[PID] & ~PIDM))
 *  0b11..The process identifier is included in the domain hit evaluation as defined by the expression:
 *        partial_domain_hit = (PE == 3) && ~((PID & ~PIDM) == (XRDC_PIDn[PID] & ~PIDM))
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
#define XRDC_MDA_W_COUNT                         (35U)

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

#define XRDC_PDAC_W_EAL_MASK                     (0x3000000U)
#define XRDC_PDAC_W_EAL_SHIFT                    (24U)
/*! EAL - Exclusive Access Lock
 *  0b00..Lock disabled
 *  0b01..Lock disabled until next reset
 *  0b10..Lock enabled, lock state = available
 *  0b11..Lock enabled, lock state = not available
 */
#define XRDC_PDAC_W_EAL(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_EAL_SHIFT)) & XRDC_PDAC_W_EAL_MASK)

#define XRDC_PDAC_W_EALO_MASK                    (0xF000000U)
#define XRDC_PDAC_W_EALO_SHIFT                   (24U)
/*! EALO - Excessive Access Lock Owner */
#define XRDC_PDAC_W_EALO(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_EALO_SHIFT)) & XRDC_PDAC_W_EALO_MASK)

#define XRDC_PDAC_W_LK2_MASK                     (0x60000000U)
#define XRDC_PDAC_W_LK2_SHIFT                    (29U)
/*! LK2 - Lock
 *  0b00..Entire PDACs can be written.
 *  0b01..Entire PDACs can be written.
 *  0b10..Domain x can only update the DxACP field and the LK2 field; no other PDACs fields can be written.
 *  0b11..PDACs is locked (read-only) until the next reset.
 */
#define XRDC_PDAC_W_LK2(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_LK2_SHIFT)) & XRDC_PDAC_W_LK2_MASK)

#define XRDC_PDAC_W_VLD_MASK                     (0x80000000U)
#define XRDC_PDAC_W_VLD_SHIFT                    (31U)
/*! VLD - Valid
 *  0b0..The PDACs assignment is invalid.
 *  0b1..The PDACs assignment is valid.
 */
#define XRDC_PDAC_W_VLD(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_VLD_SHIFT)) & XRDC_PDAC_W_VLD_MASK)
/*! @} */

/* The count of XRDC_PDAC_W */
#define XRDC_PDAC_W_COUNT                        (289U)

/* The count of XRDC_PDAC_W */
#define XRDC_PDAC_W_COUNT2                       (2U)

/*! @name MRGD_W - Memory Region Descriptor */
/*! @{ */

#define XRDC_MRGD_W_ACCSET1_MASK                 (0xFFFU)
#define XRDC_MRGD_W_ACCSET1_SHIFT                (0U)
/*! ACCSET1 - SET 1 of Programmable access flags. */
#define XRDC_MRGD_W_ACCSET1(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_ACCSET1_SHIFT)) & XRDC_MRGD_W_ACCSET1_MASK)

#define XRDC_MRGD_W_D0SEL_MASK                   (0x7U)
#define XRDC_MRGD_W_D0SEL_SHIFT                  (0U)
/*! D0SEL - Domain 0 select */
#define XRDC_MRGD_W_D0SEL(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_D0SEL_SHIFT)) & XRDC_MRGD_W_D0SEL_MASK)

#define XRDC_MRGD_W_D1SEL_MASK                   (0x38U)
#define XRDC_MRGD_W_D1SEL_SHIFT                  (3U)
/*! D1SEL - Domain 1 select */
#define XRDC_MRGD_W_D1SEL(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_D1SEL_SHIFT)) & XRDC_MRGD_W_D1SEL_MASK)

#define XRDC_MRGD_W_ENDADDR_MASK                 (0xFFFFFFE0U)
#define XRDC_MRGD_W_ENDADDR_SHIFT                (5U)
/*! ENDADDR - End Address */
#define XRDC_MRGD_W_ENDADDR(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_ENDADDR_SHIFT)) & XRDC_MRGD_W_ENDADDR_MASK)

#define XRDC_MRGD_W_SRTADDR_MASK                 (0xFFFFFFE0U)
#define XRDC_MRGD_W_SRTADDR_SHIFT                (5U)
/*! SRTADDR - Start Address */
#define XRDC_MRGD_W_SRTADDR(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_SRTADDR_SHIFT)) & XRDC_MRGD_W_SRTADDR_MASK)

#define XRDC_MRGD_W_D2SEL_MASK                   (0x1C0U)
#define XRDC_MRGD_W_D2SEL_SHIFT                  (6U)
/*! D2SEL - Domain 2 select */
#define XRDC_MRGD_W_D2SEL(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_D2SEL_SHIFT)) & XRDC_MRGD_W_D2SEL_MASK)

#define XRDC_MRGD_W_LKAS1_MASK                   (0x1000U)
#define XRDC_MRGD_W_LKAS1_SHIFT                  (12U)
/*! LKAS1 - Lock ACCSET1
 *  0b0..Writes to ACCSET1 affect lesser modes
 *  0b1..ACCSET1 cannot be modified
 */
#define XRDC_MRGD_W_LKAS1(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_LKAS1_SHIFT)) & XRDC_MRGD_W_LKAS1_MASK)

#define XRDC_MRGD_W_ACCSET2_MASK                 (0xFFF0000U)
#define XRDC_MRGD_W_ACCSET2_SHIFT                (16U)
/*! ACCSET2 - SET 2 of Programmable access flags. */
#define XRDC_MRGD_W_ACCSET2(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_ACCSET2_SHIFT)) & XRDC_MRGD_W_ACCSET2_MASK)

#define XRDC_MRGD_W_EAL_MASK                     (0x3000000U)
#define XRDC_MRGD_W_EAL_SHIFT                    (24U)
/*! EAL - Exclusive Access Lock
 *  0b00..Lock disabled
 *  0b01..Lock disabled until next reset
 *  0b10..Lock enabled, lock state = available
 *  0b11..Lock enabled, lock state = not available
 */
#define XRDC_MRGD_W_EAL(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_EAL_SHIFT)) & XRDC_MRGD_W_EAL_MASK)

#define XRDC_MRGD_W_EALO_MASK                    (0xF000000U)
#define XRDC_MRGD_W_EALO_SHIFT                   (24U)
/*! EALO - Exclusive Access Lock Owner */
#define XRDC_MRGD_W_EALO(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_EALO_SHIFT)) & XRDC_MRGD_W_EALO_MASK)

#define XRDC_MRGD_W_LKAS2_MASK                   (0x10000000U)
#define XRDC_MRGD_W_LKAS2_SHIFT                  (28U)
/*! LKAS2 - Lock ACCSET2
 *  0b0..Writes to ACCSET2 affect lesser modes
 *  0b1..ACCSET2 cannot be modified
 */
#define XRDC_MRGD_W_LKAS2(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_LKAS2_SHIFT)) & XRDC_MRGD_W_LKAS2_MASK)

#define XRDC_MRGD_W_LK2_MASK                     (0x60000000U)
#define XRDC_MRGD_W_LK2_SHIFT                    (29U)
/*! LK2 - Lock
 *  0b00..Entire MRGDn can be written.
 *  0b01..Entire MRGDn can be written.
 *  0b10..Domain x can only update the DxACP field and the LK2 field; no other MRGDn fields can be written.
 *  0b11..MRGDn is locked (read-only) until the next reset.
 */
#define XRDC_MRGD_W_LK2(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_LK2_SHIFT)) & XRDC_MRGD_W_LK2_MASK)

#define XRDC_MRGD_W_CR_MASK                      (0x80000000U)
#define XRDC_MRGD_W_CR_SHIFT                     (31U)
/*! CR - Code Region Indicator */
#define XRDC_MRGD_W_CR(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_CR_SHIFT)) & XRDC_MRGD_W_CR_MASK)

#define XRDC_MRGD_W_VLD_MASK                     (0x80000000U)
#define XRDC_MRGD_W_VLD_SHIFT                    (31U)
/*! VLD - Valid
 *  0b0..The MRGDn assignment is invalid.
 *  0b1..The MRGDn assignment is valid.
 */
#define XRDC_MRGD_W_VLD(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_VLD_SHIFT)) & XRDC_MRGD_W_VLD_MASK)
/*! @} */

/* The count of XRDC_MRGD_W */
#define XRDC_MRGD_W_COUNT                        (24U)

/* The count of XRDC_MRGD_W */
#define XRDC_MRGD_W_COUNT2                       (5U)


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

