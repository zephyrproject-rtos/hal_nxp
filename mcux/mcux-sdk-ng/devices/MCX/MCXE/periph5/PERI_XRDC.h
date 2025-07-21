/*
** ###################################################################
**     Processors:          MCXE315MLF
**                          MCXE315MPA
**                          MCXE316MLF
**                          MCXE316MPA
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
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
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_XRDC.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for XRDC
 *
 * CMSIS Peripheral Access Layer for XRDC
 */

#if !defined(PERI_XRDC_H_)
#define PERI_XRDC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE315MLF) || defined(CPU_MCXE315MPA))
#include "MCXE315_COMMON.h"
#elif (defined(CPU_MCXE316MLF) || defined(CPU_MCXE316MPA))
#include "MCXE316_COMMON.h"
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
    kXRDC_MasterCM7                 = 0U,          /**< CM7 AXI, AHBP */
    kXRDC_MasterEdma0               = 2U,          /**< EDMA0 AHB */
    kXRDC_MasterEmac                = 4U,          /**< EMAC AHB */
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
    kXRDC_MemMrc0_8                 = 8U,          /**< MRC0 Memory 8 */
    kXRDC_MemMrc0_9                 = 9U,          /**< MRC0 Memory 9 */
    kXRDC_MemMrc0_10                = 10U,         /**< MRC0 Memory 10 */
    kXRDC_MemMrc0_11                = 11U,         /**< MRC0 Memory 11 */
    kXRDC_MemMrc0_12                = 12U,         /**< MRC0 Memory 12 */
    kXRDC_MemMrc0_13                = 13U,         /**< MRC0 Memory 13 */
    kXRDC_MemMrc0_14                = 14U,         /**< MRC0 Memory 14 */
    kXRDC_MemMrc0_15                = 15U,         /**< MRC0 Memory 15 */
    kXRDC_MemMrc1_0                 = 16U,         /**< MRC1 Memory 0 */
    kXRDC_MemMrc1_1                 = 17U,         /**< MRC1 Memory 1 */
    kXRDC_MemMrc1_2                 = 18U,         /**< MRC1 Memory 2 */
    kXRDC_MemMrc1_3                 = 19U,         /**< MRC1 Memory 3 */
    kXRDC_MemMrc1_4                 = 20U,         /**< MRC1 Memory 4 */
    kXRDC_MemMrc1_5                 = 21U,         /**< MRC1 Memory 5 */
    kXRDC_MemMrc1_6                 = 22U,         /**< MRC1 Memory 6 */
    kXRDC_MemMrc1_7                 = 23U,         /**< MRC1 Memory 7 */
    kXRDC_MemMrc1_8                 = 24U,         /**< MRC1 Memory 8 */
    kXRDC_MemMrc1_9                 = 25U,         /**< MRC1 Memory 9 */
    kXRDC_MemMrc1_10                = 26U,         /**< MRC1 Memory 10 */
    kXRDC_MemMrc1_11                = 27U,         /**< MRC1 Memory 11 */
    kXRDC_MemMrc1_12                = 28U,         /**< MRC1 Memory 12 */
    kXRDC_MemMrc1_13                = 29U,         /**< MRC1 Memory 13 */
    kXRDC_MemMrc1_14                = 30U,         /**< MRC1 Memory 14 */
    kXRDC_MemMrc1_15                = 31U,         /**< MRC1 Memory 15 */
    kXRDC_MemMrc2_0                 = 32U,         /**< MRC2 Memory 0 */
    kXRDC_MemMrc2_1                 = 33U,         /**< MRC2 Memory 1 */
    kXRDC_MemMrc2_2                 = 34U,         /**< MRC2 Memory 2 */
    kXRDC_MemMrc2_3                 = 35U,         /**< MRC2 Memory 3 */
} xrdc_mem_t;
#endif /* XRDC_MEM_T_ */

#if !defined(XRDC_PERIPH_T_)
#define XRDC_PERIPH_T_
typedef enum _xrdc_periph
{
    kXRDC_PeriphTrgmux              = 32U,         /**< Trigger Multiplexing Control */
    kXRDC_PeriphBctu                = 33U,         /**< Body Cross Triggering Unit */
    kXRDC_PeriphEmios0              = 34U,         /**< eMIOS 0 */
    kXRDC_PeriphEmios1              = 35U,         /**< eMIOS 1 */
    kXRDC_PeriphEmios2              = 36U,         /**< eMIOS 2 */
    kXRDC_PeriphLcu0                = 38U,         /**< Logic Control Unit 0 */
    kXRDC_PeriphLcu1                = 39U,         /**< Logic Control Unit 1 */
    kXRDC_PeriphAdc0                = 40U,         /**< Analog-to-digital converter 0 */
    kXRDC_PeriphAdc1                = 41U,         /**< Analog-to-digital converter 1 */
    kXRDC_PeriphAdc2                = 42U,         /**< Analog-to-digital converter 2 */
    kXRDC_PeriphPit0                = 44U,         /**< Programmable Interrupt Timer 0 */
    kXRDC_PeriphPit1                = 45U,         /**< Programmable Interrupt Timer 1 */
    kXRDC_PeriphAxbs                = 128U,        /**< System crossbar switch */
    kXRDC_PeriphSystemXbic          = 129U,        /**< Crossbar Integrity Checker (System AXBS / AXBS Lite) */
    kXRDC_PeriphPeriphXbic          = 130U,        /**< Crossbar Integrity Checker (Peripheral AXBS-Lite) */
    kXRDC_PeriphEdma                = 131U,        /**< eDMA control and status (MP_CSR MP_ES MP_HRS) */
    kXRDC_PeriphEdmaTcd0            = 132U,        /**< eDMA transfer control descriptor 0 */
    kXRDC_PeriphEdmaTcd1            = 133U,        /**< eDMA transfer control descriptor 1 */
    kXRDC_PeriphEdmaTcd2            = 134U,        /**< eDMA transfer control descriptor 2 */
    kXRDC_PeriphEdmaTcd3            = 135U,        /**< eDMA transfer control descriptor 3 */
    kXRDC_PeriphEdmaTcd4            = 136U,        /**< eDMA transfer control descriptor 4 */
    kXRDC_PeriphEdmaTcd5            = 137U,        /**< eDMA transfer control descriptor 5 */
    kXRDC_PeriphEdmaTcd6            = 138U,        /**< eDMA transfer control descriptor 6 */
    kXRDC_PeriphEdmaTcd7            = 139U,        /**< eDMA transfer control descriptor 7 */
    kXRDC_PeriphEdmaTcd8            = 140U,        /**< eDMA transfer control descriptor 8 */
    kXRDC_PeriphEdmaTcd9            = 141U,        /**< eDMA transfer control descriptor 9 */
    kXRDC_PeriphEdmaTcd10           = 142U,        /**< eDMA transfer control descriptor 10 */
    kXRDC_PeriphEdmaTcd11           = 143U,        /**< eDMA transfer control descriptor 11 */
    kXRDC_PeriphDebug               = 149U,        /**< Debug APB Area, SDA-AP */
    kXRDC_PeriphEim0                = 150U,        /**< EIM0 */
    kXRDC_PeriphErm0                = 151U,        /**< ERM0 */
    kXRDC_PeriphMscm                = 152U,        /**< MSCM */
    kXRDC_PeriphPram0               = 153U,        /**< RAM controller 0 */
    kXRDC_PeriphPfc                 = 154U,        /**< Flash controller */
    kXRDC_PeriphPfcAlt              = 155U,        /**< Flash controller alternate */
    kXRDC_PeriphSwt0                = 156U,        /**< Software Watchdog 0 */
    kXRDC_PeriphStm0                = 157U,        /**< System Timer Module 0 */
    kXRDC_PeriphXrdc                = 158U,        /**< XRDC */
    kXRDC_PeriphIntm                = 159U,        /**< Interrupt Monitor */
    kXRDC_PeriphDmamux0             = 160U,        /**< DMA Channel Multiplexer 0 */
    kXRDC_PeriphDmamux1             = 161U,        /**< DMA Channel Multiplexer 1 */
    kXRDC_PeriphRtc                 = 162U,        /**< Real-time clock */
    kXRDC_PeriphMc_rgm              = 163U,        /**< Reset Generation Module */
    kXRDC_PeriphSiul2VwrapPdac0_0   = 164U,        /**< SIUL_VIRTWRAPPER_PDAC0 */
    kXRDC_PeriphSiul2VwrapPdac0_1   = 165U,        /**< SIUL_VIRTWRAPPER_PDAC0 */
    kXRDC_PeriphSiul2VwrapPdac1_0   = 166U,        /**< SIUL_VIRTWRAPPER_PDAC1 */
    kXRDC_PeriphSiul2VwrapPdac1_1   = 167U,        /**< SIUL_VIRTWRAPPER_PDAC1 */
    kXRDC_PeriphSiul2VwrapPdac3     = 170U,        /**< SIUL_VIRTWRAPPER_PDAC3 */
    kXRDC_PeriphDcm                 = 171U,        /**< System Status and Configuration Module */
    kXRDC_PeriphWkpu                = 173U,        /**< Wakeup Unit */
    kXRDC_PeriphCmu                 = 175U,        /**< CMU 0-5 */
    kXRDC_PeriphTspc                = 177U,        /**< Touch Sensing Coupling Controller */
    kXRDC_PeriphSirc                = 178U,        /**< 32 kHz Slow Internal RC Oscillator */
    kXRDC_PeriphSxosc               = 179U,        /**< 32 kHz Slow External Crystal Oscillator */
    kXRDC_PeriphFirc                = 180U,        /**< 48 MHz Fast Internal RC Oscillator */
    kXRDC_PeriphFxosc               = 181U,        /**< 8-40 MHz Fast External Crystal Oscillator */
    kXRDC_PeriphMc_cgm              = 182U,        /**< Clock Generation Module */
    kXRDC_PeriphMc_me               = 183U,        /**< Mode Entry Module */
    kXRDC_PeriphPll                 = 184U,        /**< Frequency Modulated Phase-Locked Loop */
    kXRDC_PeriphPmc                 = 186U,        /**< Power management controller */
    kXRDC_PeriphFmu                 = 187U,        /**< Flash memory */
    kXRDC_PeriphFmuAlt              = 188U,        /**< Flash memory alternate */
    kXRDC_PeriphPit2                = 191U,        /**< Programmable Interrupt Timer 2 */
    kXRDC_PeriphFlexcan0            = 193U,        /**< FlexCAN 0 */
    kXRDC_PeriphFlexcan1            = 194U,        /**< FlexCAN 1 */
    kXRDC_PeriphFlexcan2            = 195U,        /**< FlexCAN 2 */
    kXRDC_PeriphFlexcan3            = 196U,        /**< FlexCAN 3 */
    kXRDC_PeriphFlexcan4            = 197U,        /**< FlexCAN 4 */
    kXRDC_PeriphFlexcan5            = 198U,        /**< FlexCAN 5 */
    kXRDC_PeriphFlexio              = 201U,        /**< Flexible IO */
    kXRDC_PeriphLpuart0             = 202U,        /**< Low Power UART 0 */
    kXRDC_PeriphLpuart1             = 203U,        /**< Low Power UART 1 */
    kXRDC_PeriphLpuart2             = 204U,        /**< Low Power UART 2 */
    kXRDC_PeriphLpuart3             = 205U,        /**< Low Power UART 3 */
    kXRDC_PeriphLpuart4             = 206U,        /**< Low Power UART 4 */
    kXRDC_PeriphLpuart5             = 207U,        /**< Low Power UART 5 */
    kXRDC_PeriphLpuart6             = 208U,        /**< Low Power UART 6 */
    kXRDC_PeriphLpuart7             = 209U,        /**< Low Power UART 7 */
    kXRDC_PeriphLpi2c0              = 212U,        /**< Low Power I2C 0 */
    kXRDC_PeriphLpi2c1              = 213U,        /**< Low Power I2C 1 */
    kXRDC_PeriphLpspi0              = 214U,        /**< Low Power SPI 0 */
    kXRDC_PeriphLpspi1              = 215U,        /**< Low Power SPI 1 */
    kXRDC_PeriphLpspi2              = 216U,        /**< Low Power SPI 2 */
    kXRDC_PeriphLpspi3              = 217U,        /**< Low Power SPI 3 */
    kXRDC_PeriphSai0                = 219U,        /**< Synchronous Audio Interface 0 */
    kXRDC_PeriphLpcmp0              = 220U,        /**< Low Power Comparator 0 */
    kXRDC_PeriphLpcmp1              = 221U,        /**< Low Power Comparator 1 */
    kXRDC_PeriphTmu                 = 223U,        /**< TMU Temperature Sensor Unit  */
    kXRDC_PeriphCrc                 = 224U,        /**< CRC */
    kXRDC_PeriphFccu                = 225U,        /**< FCCU (and FOSU) */
    kXRDC_PeriphMu0B                = 227U,        /**< MU_0_MUB */
    kXRDC_PeriphJdc                 = 229U,        /**< JDC (JTAG Data Communication) */
    kXRDC_PeriphConfiguration_gpr   = 231U,        /**< Configuration GPR */
    kXRDC_PeriphStcu                = 232U,        /**< Self-Test Control Unit */
    kXRDC_PeriphSelftest_gpr        = 236U,        /**< Selftest GPR */
    kXRDC_PeriphTcmXbic             = 256U,        /**< Crossbar Integrity Checker (TCM backdoor AHB Splitter) */
    kXRDC_PeriphEdma_xbic           = 257U,        /**< Crossbar Integrity Checker (eDMA and STAM AXBS-Lite) */
    kXRDC_PeriphEdmaTcd12           = 260U,        /**< eDMA transfer control descriptor 12 */
    kXRDC_PeriphEdmaTcd13           = 261U,        /**< eDMA transfer control descriptor 13 */
    kXRDC_PeriphEdmaTcd14           = 262U,        /**< eDMA transfer control descriptor 14 */
    kXRDC_PeriphEdmaTcd15           = 263U,        /**< eDMA transfer control descriptor 15 */
    kXRDC_PeriphEdmaTcd16           = 264U,        /**< eDMA transfer control descriptor 16 */
    kXRDC_PeriphEdmaTcd17           = 265U,        /**< eDMA transfer control descriptor 17 */
    kXRDC_PeriphEdmaTcd18           = 266U,        /**< eDMA transfer control descriptor 18 */
    kXRDC_PeriphEdmaTcd19           = 267U,        /**< eDMA transfer control descriptor 19 */
    kXRDC_PeriphEdmaTcd20           = 268U,        /**< eDMA transfer control descriptor 20 */
    kXRDC_PeriphEdmaTcd21           = 269U,        /**< eDMA transfer control descriptor 21 */
    kXRDC_PeriphEdmaTcd22           = 270U,        /**< eDMA transfer control descriptor 22 */
    kXRDC_PeriphEdmaTcd23           = 271U,        /**< eDMA transfer control descriptor 23 */
    kXRDC_PeriphEdmaTcd24           = 272U,        /**< eDMA transfer control descriptor 24 */
    kXRDC_PeriphEdmaTcd25           = 273U,        /**< eDMA transfer control descriptor 25 */
    kXRDC_PeriphEdmaTcd26           = 274U,        /**< eDMA transfer control descriptor 26 */
    kXRDC_PeriphEdmaTcd27           = 275U,        /**< eDMA transfer control descriptor 27 */
    kXRDC_PeriphEdmaTcd28           = 276U,        /**< eDMA transfer control descriptor 28 */
    kXRDC_PeriphEdmaTcd29           = 277U,        /**< eDMA transfer control descriptor 29 */
    kXRDC_PeriphEdmaTcd30           = 278U,        /**< eDMA transfer control descriptor 30 */
    kXRDC_PeriphEdmaTcd31           = 279U,        /**< eDMA transfer control descriptor 31 */
    kXRDC_PeriphSema42              = 280U,        /**< Semaphores2 */
    kXRDC_PeriphPram1               = 281U,        /**< RAM controller 1 */
    kXRDC_PeriphStm1                = 285U,        /**< System Timer Module 1 */
    kXRDC_PeriphEmac                = 288U,        /**< EMAC */
    kXRDC_PeriphLpuart8             = 291U,        /**< Low Power UART 8 */
    kXRDC_PeriphLpuart9             = 292U,        /**< Low Power UART 9 */
    kXRDC_PeriphLpuart10            = 293U,        /**< Low Power UART 10 */
    kXRDC_PeriphLpuart11            = 294U,        /**< Low Power UART 11 */
    kXRDC_PeriphLpuart12            = 295U,        /**< Low Power UART 12 */
    kXRDC_PeriphLpuart13            = 296U,        /**< Low Power UART 13 */
    kXRDC_PeriphLpuart14            = 297U,        /**< Low Power UART 14 */
    kXRDC_PeriphLpuart15            = 298U,        /**< Low Power UART 15 */
    kXRDC_PeriphLpspi4              = 303U,        /**< Low Power SPI 4 */
    kXRDC_PeriphLpspi5              = 304U,        /**< Low Power SPI 5 */
    kXRDC_PeriphQuadspi             = 307U,        /**< QuadSPI */
    kXRDC_PeriphSai1                = 311U,        /**< Synchronous Audio Interface 1 */
    kXRDC_PeriphLpcmp2              = 314U,        /**< Low Power Comparator 2 */
    kXRDC_PeriphMu1B                = 315U,        /**< MU_1_MUB */
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
#define XRDC_MDACFG_COUNT                         4u
#define XRDC_MRC_COUNT                            2u
#define XRDC_DERRLOC_COUNT                        2u
#define XRDC_DERR_Wx_COUNT                        18u
#define XRDC_DERR_Wx_DERR_W_COUNT                 4u
#define XRDC_PID_COUNT                            4u
#define XRDC_MDA_MDA_Wx_COUNT                     1u
#define XRDC_MDA_COUNT                            4u
#define XRDC_PDAC_COUNT                           236u
#define XRDC_PDAC_PDAC_Wx_COUNT                   2u
#define XRDC_MRGD_MRGD_Wx_COUNT                   4u
#define XRDC_MRGD_COUNT                           24u

/** XRDC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control, offset: 0x0 */
       uint8_t RESERVED_0[236];
  __I  uint32_t HWCFG0;                            /**< Hardware Configuration 0, offset: 0xF0 */
  __I  uint32_t HWCFG1;                            /**< Hardware Configuration 1, offset: 0xF4 */
  __I  uint32_t HWCFG2;                            /**< Hardware Configuration 2, offset: 0xF8 */
       uint8_t RESERVED_1[4];
  __I  uint8_t MDACFG[XRDC_MDACFG_COUNT];          /**< Master Domain Assignment Configuration, array offset: 0x100, array step: 0x1 */
       uint8_t RESERVED_2[60];
  __I  uint8_t MRCFG[XRDC_MRC_COUNT];              /**< Memory Region Configuration, array offset: 0x140, array step: 0x1 */
       uint8_t RESERVED_3[190];
  __I  uint32_t DERRLOC[XRDC_DERRLOC_COUNT];       /**< Domain Error Location, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_4[504];
  __IO uint32_t DERR_W[XRDC_DERR_Wx_COUNT][XRDC_DERR_Wx_DERR_W_COUNT]; /**< Domain Error Word 0..Domain Error Word 3, array offset: 0x400, array step: index*0x10, index2*0x4, valid indices: [0-1, 16-17][0], [0-1, 16-17][1], [0-1, 16-17][3] */
       uint8_t RESERVED_5[480];
  __IO uint32_t PID[XRDC_PID_COUNT];               /**< Process Identifier, array offset: 0x700, array step: 0x4, valid indices: [0, 3] */
       uint8_t RESERVED_6[240];
  struct {                                         /* offset: 0x800, array step: 0x20 */
    __IO uint32_t MDA_W[XRDC_MDA_MDA_Wx_COUNT];      /**< Master Domain Assignment, array offset: 0x800, array step: index*0x20, index2*0x4 */
         uint8_t RESERVED_0[28];
  } MDA[XRDC_MDA_COUNT];
       uint8_t RESERVED_7[1920];
  __IO uint32_t PDAC_W[XRDC_PDAC_COUNT][XRDC_PDAC_PDAC_Wx_COUNT]; /**< Peripheral Domain Access Control Word 0..Peripheral Domain Access Control Word 1, array offset: 0x1000, array step: index*0x8, index2*0x4, irregular array, not all indices are valid */
       uint8_t RESERVED_8[2208];
  struct {                                         /* offset: 0x2000, array step: 0x20 */
    __IO uint32_t MRGD_W[XRDC_MRGD_MRGD_Wx_COUNT];   /**< Memory Region Descriptor Word 0..Memory Region Descriptor Word 3, array offset: 0x2000, array step: index*0x20, index2*0x4, valid indices: [0-7, 16-23][0], [0-7, 16-23][1], [0-7, 16-23][2], [0-7, 16-23][3] */
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
/*! GVLD - Global Valid (XRDC Global Enable/Disable)
 *  0b0..Disables
 *  0b1..Enables
 */
#define XRDC_CR_GVLD(x)                          (((uint32_t)(((uint32_t)(x)) << XRDC_CR_GVLD_SHIFT)) & XRDC_CR_GVLD_MASK)

#define XRDC_CR_HRL_MASK                         (0x1EU)
#define XRDC_CR_HRL_SHIFT                        (1U)
/*! HRL - Hardware Revision Level */
#define XRDC_CR_HRL(x)                           (((uint32_t)(((uint32_t)(x)) << XRDC_CR_HRL_SHIFT)) & XRDC_CR_HRL_MASK)

#define XRDC_CR_MRF_MASK                         (0x80U)
#define XRDC_CR_MRF_SHIFT                        (7U)
/*! MRF - Memory Region Format
 *  0b0..Reserved
 *  0b1..SMPU family format
 */
#define XRDC_CR_MRF(x)                           (((uint32_t)(((uint32_t)(x)) << XRDC_CR_MRF_SHIFT)) & XRDC_CR_MRF_MASK)

#define XRDC_CR_VAW_MASK                         (0x100U)
#define XRDC_CR_VAW_SHIFT                        (8U)
/*! VAW - Virtualization Aware
 *  0b0..Not virtualization-aware
 *  0b1..Virtualization-aware
 */
#define XRDC_CR_VAW(x)                           (((uint32_t)(((uint32_t)(x)) << XRDC_CR_VAW_SHIFT)) & XRDC_CR_VAW_MASK)

#define XRDC_CR_LK1_MASK                         (0x40000000U)
#define XRDC_CR_LK1_SHIFT                        (30U)
/*! LK1 - Lock
 *  0b0..No effect
 *  0b0..Unlocked
 *  0b1..Locks
 */
#define XRDC_CR_LK1(x)                           (((uint32_t)(((uint32_t)(x)) << XRDC_CR_LK1_SHIFT)) & XRDC_CR_LK1_MASK)
/*! @} */

/*! @name HWCFG0 - Hardware Configuration 0 */
/*! @{ */

#define XRDC_HWCFG0_NDID_MASK                    (0xFFU)
#define XRDC_HWCFG0_NDID_SHIFT                   (0U)
/*! NDID - Number Of DIDs */
#define XRDC_HWCFG0_NDID(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG0_NDID_SHIFT)) & XRDC_HWCFG0_NDID_MASK)

#define XRDC_HWCFG0_NMSTR_MASK                   (0xFF00U)
#define XRDC_HWCFG0_NMSTR_SHIFT                  (8U)
/*! NMSTR - Number Of Bus Masters */
#define XRDC_HWCFG0_NMSTR(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG0_NMSTR_SHIFT)) & XRDC_HWCFG0_NMSTR_MASK)

#define XRDC_HWCFG0_NMRC_MASK                    (0xFF0000U)
#define XRDC_HWCFG0_NMRC_SHIFT                   (16U)
/*! NMRC - Number of MRCs */
#define XRDC_HWCFG0_NMRC(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG0_NMRC_SHIFT)) & XRDC_HWCFG0_NMRC_MASK)

#define XRDC_HWCFG0_NPAC_MASK                    (0xF000000U)
#define XRDC_HWCFG0_NPAC_SHIFT                   (24U)
/*! NPAC - Number Of PACs */
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
/*! DID - Domain Identifier */
#define XRDC_HWCFG1_DID(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG1_DID_SHIFT)) & XRDC_HWCFG1_DID_MASK)
/*! @} */

/*! @name HWCFG2 - Hardware Configuration 2 */
/*! @{ */

#define XRDC_HWCFG2_PIDP0_MASK                   (0x1U)
#define XRDC_HWCFG2_PIDP0_SHIFT                  (0U)
/*! PIDP0 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP0(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP0_SHIFT)) & XRDC_HWCFG2_PIDP0_MASK)

#define XRDC_HWCFG2_PIDP1_MASK                   (0x2U)
#define XRDC_HWCFG2_PIDP1_SHIFT                  (1U)
/*! PIDP1 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP1(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP1_SHIFT)) & XRDC_HWCFG2_PIDP1_MASK)

#define XRDC_HWCFG2_PIDP2_MASK                   (0x4U)
#define XRDC_HWCFG2_PIDP2_SHIFT                  (2U)
/*! PIDP2 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP2(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP2_SHIFT)) & XRDC_HWCFG2_PIDP2_MASK)

#define XRDC_HWCFG2_PIDP3_MASK                   (0x8U)
#define XRDC_HWCFG2_PIDP3_SHIFT                  (3U)
/*! PIDP3 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP3(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP3_SHIFT)) & XRDC_HWCFG2_PIDP3_MASK)

#define XRDC_HWCFG2_PIDP4_MASK                   (0x10U)
#define XRDC_HWCFG2_PIDP4_SHIFT                  (4U)
/*! PIDP4 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP4(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP4_SHIFT)) & XRDC_HWCFG2_PIDP4_MASK)

#define XRDC_HWCFG2_PIDP5_MASK                   (0x20U)
#define XRDC_HWCFG2_PIDP5_SHIFT                  (5U)
/*! PIDP5 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP5(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP5_SHIFT)) & XRDC_HWCFG2_PIDP5_MASK)

#define XRDC_HWCFG2_PIDP6_MASK                   (0x40U)
#define XRDC_HWCFG2_PIDP6_SHIFT                  (6U)
/*! PIDP6 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP6(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP6_SHIFT)) & XRDC_HWCFG2_PIDP6_MASK)

#define XRDC_HWCFG2_PIDP7_MASK                   (0x80U)
#define XRDC_HWCFG2_PIDP7_SHIFT                  (7U)
/*! PIDP7 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP7(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP7_SHIFT)) & XRDC_HWCFG2_PIDP7_MASK)

#define XRDC_HWCFG2_PIDP8_MASK                   (0x100U)
#define XRDC_HWCFG2_PIDP8_SHIFT                  (8U)
/*! PIDP8 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP8(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP8_SHIFT)) & XRDC_HWCFG2_PIDP8_MASK)

#define XRDC_HWCFG2_PIDP9_MASK                   (0x200U)
#define XRDC_HWCFG2_PIDP9_SHIFT                  (9U)
/*! PIDP9 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP9(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP9_SHIFT)) & XRDC_HWCFG2_PIDP9_MASK)

#define XRDC_HWCFG2_PIDP10_MASK                  (0x400U)
#define XRDC_HWCFG2_PIDP10_SHIFT                 (10U)
/*! PIDP10 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP10(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP10_SHIFT)) & XRDC_HWCFG2_PIDP10_MASK)

#define XRDC_HWCFG2_PIDP11_MASK                  (0x800U)
#define XRDC_HWCFG2_PIDP11_SHIFT                 (11U)
/*! PIDP11 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP11(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP11_SHIFT)) & XRDC_HWCFG2_PIDP11_MASK)

#define XRDC_HWCFG2_PIDP12_MASK                  (0x1000U)
#define XRDC_HWCFG2_PIDP12_SHIFT                 (12U)
/*! PIDP12 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP12(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP12_SHIFT)) & XRDC_HWCFG2_PIDP12_MASK)

#define XRDC_HWCFG2_PIDP13_MASK                  (0x2000U)
#define XRDC_HWCFG2_PIDP13_SHIFT                 (13U)
/*! PIDP13 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP13(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP13_SHIFT)) & XRDC_HWCFG2_PIDP13_MASK)

#define XRDC_HWCFG2_PIDP14_MASK                  (0x4000U)
#define XRDC_HWCFG2_PIDP14_SHIFT                 (14U)
/*! PIDP14 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP14(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP14_SHIFT)) & XRDC_HWCFG2_PIDP14_MASK)

#define XRDC_HWCFG2_PIDP15_MASK                  (0x8000U)
#define XRDC_HWCFG2_PIDP15_SHIFT                 (15U)
/*! PIDP15 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP15(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP15_SHIFT)) & XRDC_HWCFG2_PIDP15_MASK)

#define XRDC_HWCFG2_PIDP16_MASK                  (0x10000U)
#define XRDC_HWCFG2_PIDP16_SHIFT                 (16U)
/*! PIDP16 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP16(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP16_SHIFT)) & XRDC_HWCFG2_PIDP16_MASK)

#define XRDC_HWCFG2_PIDP17_MASK                  (0x20000U)
#define XRDC_HWCFG2_PIDP17_SHIFT                 (17U)
/*! PIDP17 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP17(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP17_SHIFT)) & XRDC_HWCFG2_PIDP17_MASK)

#define XRDC_HWCFG2_PIDP18_MASK                  (0x40000U)
#define XRDC_HWCFG2_PIDP18_SHIFT                 (18U)
/*! PIDP18 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP18(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP18_SHIFT)) & XRDC_HWCFG2_PIDP18_MASK)

#define XRDC_HWCFG2_PIDP19_MASK                  (0x80000U)
#define XRDC_HWCFG2_PIDP19_SHIFT                 (19U)
/*! PIDP19 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP19(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP19_SHIFT)) & XRDC_HWCFG2_PIDP19_MASK)

#define XRDC_HWCFG2_PIDP20_MASK                  (0x100000U)
#define XRDC_HWCFG2_PIDP20_SHIFT                 (20U)
/*! PIDP20 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP20(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP20_SHIFT)) & XRDC_HWCFG2_PIDP20_MASK)

#define XRDC_HWCFG2_PIDP21_MASK                  (0x200000U)
#define XRDC_HWCFG2_PIDP21_SHIFT                 (21U)
/*! PIDP21 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP21(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP21_SHIFT)) & XRDC_HWCFG2_PIDP21_MASK)

#define XRDC_HWCFG2_PIDP22_MASK                  (0x400000U)
#define XRDC_HWCFG2_PIDP22_SHIFT                 (22U)
/*! PIDP22 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP22(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP22_SHIFT)) & XRDC_HWCFG2_PIDP22_MASK)

#define XRDC_HWCFG2_PIDP23_MASK                  (0x800000U)
#define XRDC_HWCFG2_PIDP23_SHIFT                 (23U)
/*! PIDP23 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP23(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP23_SHIFT)) & XRDC_HWCFG2_PIDP23_MASK)

#define XRDC_HWCFG2_PIDP24_MASK                  (0x1000000U)
#define XRDC_HWCFG2_PIDP24_SHIFT                 (24U)
/*! PIDP24 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP24(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP24_SHIFT)) & XRDC_HWCFG2_PIDP24_MASK)

#define XRDC_HWCFG2_PIDP25_MASK                  (0x2000000U)
#define XRDC_HWCFG2_PIDP25_SHIFT                 (25U)
/*! PIDP25 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP25(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP25_SHIFT)) & XRDC_HWCFG2_PIDP25_MASK)

#define XRDC_HWCFG2_PIDP26_MASK                  (0x4000000U)
#define XRDC_HWCFG2_PIDP26_SHIFT                 (26U)
/*! PIDP26 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP26(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP26_SHIFT)) & XRDC_HWCFG2_PIDP26_MASK)

#define XRDC_HWCFG2_PIDP27_MASK                  (0x8000000U)
#define XRDC_HWCFG2_PIDP27_SHIFT                 (27U)
/*! PIDP27 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP27(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP27_SHIFT)) & XRDC_HWCFG2_PIDP27_MASK)

#define XRDC_HWCFG2_PIDP28_MASK                  (0x10000000U)
#define XRDC_HWCFG2_PIDP28_SHIFT                 (28U)
/*! PIDP28 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP28(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP28_SHIFT)) & XRDC_HWCFG2_PIDP28_MASK)

#define XRDC_HWCFG2_PIDP29_MASK                  (0x20000000U)
#define XRDC_HWCFG2_PIDP29_SHIFT                 (29U)
/*! PIDP29 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP29(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP29_SHIFT)) & XRDC_HWCFG2_PIDP29_MASK)

#define XRDC_HWCFG2_PIDP30_MASK                  (0x40000000U)
#define XRDC_HWCFG2_PIDP30_SHIFT                 (30U)
/*! PIDP30 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP30(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP30_SHIFT)) & XRDC_HWCFG2_PIDP30_MASK)

#define XRDC_HWCFG2_PIDP31_MASK                  (0x80000000U)
#define XRDC_HWCFG2_PIDP31_SHIFT                 (31U)
/*! PIDP31 - Process Identifier Present
 *  0b0..Does not have PID register
 *  0b1..Has PID register
 */
#define XRDC_HWCFG2_PIDP31(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG2_PIDP31_SHIFT)) & XRDC_HWCFG2_PIDP31_MASK)
/*! @} */

/*! @name MDACFG - Master Domain Assignment Configuration */
/*! @{ */

#define XRDC_MDACFG_NMDAR_MASK                   (0xFU)
#define XRDC_MDACFG_NMDAR_SHIFT                  (0U)
/*! NMDAR - Number Of Master Domain Assignment Registers
 *  0b0000..Master does not exist
 *  0b0001-0b1000..Number of registers
 */
#define XRDC_MDACFG_NMDAR(x)                     (((uint8_t)(((uint8_t)(x)) << XRDC_MDACFG_NMDAR_SHIFT)) & XRDC_MDACFG_NMDAR_MASK)

#define XRDC_MDACFG_NCM_MASK                     (0x80U)
#define XRDC_MDACFG_NCM_SHIFT                    (7U)
/*! NCM - Noncore Master
 *  0b0..Core master or master does not exist
 *  0b1..Noncore master
 */
#define XRDC_MDACFG_NCM(x)                       (((uint8_t)(((uint8_t)(x)) << XRDC_MDACFG_NCM_SHIFT)) & XRDC_MDACFG_NCM_MASK)
/*! @} */

/*! @name MRCFG - Memory Region Configuration */
/*! @{ */

#define XRDC_MRCFG_NMRGD_MASK                    (0x1FU)
#define XRDC_MRCFG_NMRGD_SHIFT                   (0U)
/*! NMRGD - Number Of Memory Region Descriptors
 *  0b00000..MRC does not exist
 *  0b00100..4
 *  0b01000..8
 *  0b01100..12
 *  0b10000..16
 */
#define XRDC_MRCFG_NMRGD(x)                      (((uint8_t)(((uint8_t)(x)) << XRDC_MRCFG_NMRGD_SHIFT)) & XRDC_MRCFG_NMRGD_MASK)
/*! @} */

/* The count of XRDC_MRCFG */
#define XRDC_MRCFG_COUNT                         (2U)

/*! @name DERRLOC - Domain Error Location */
/*! @{ */

#define XRDC_DERRLOC_MRCINST_MASK                (0xFFFFU)
#define XRDC_DERRLOC_MRCINST_SHIFT               (0U)
/*! MRCINST - MRC Instance */
#define XRDC_DERRLOC_MRCINST(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_DERRLOC_MRCINST_SHIFT)) & XRDC_DERRLOC_MRCINST_MASK)

#define XRDC_DERRLOC_PACINST_MASK                (0xF0000U)
#define XRDC_DERRLOC_PACINST_SHIFT               (16U)
/*! PACINST - PAC Instance */
#define XRDC_DERRLOC_PACINST(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_DERRLOC_PACINST_SHIFT)) & XRDC_DERRLOC_PACINST_MASK)
/*! @} */

/*! @name DERR_W - Domain Error Word 0..Domain Error Word 3 */
/*! @{ */

#define XRDC_DERR_W_EADDR_MASK                   (0xFFFFFFFFU)
#define XRDC_DERR_W_EADDR_SHIFT                  (0U)
/*! EADDR - Error Address */
#define XRDC_DERR_W_EADDR(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W_EADDR_SHIFT)) & XRDC_DERR_W_EADDR_MASK)

#define XRDC_DERR_W_EDID_MASK                    (0xFU)
#define XRDC_DERR_W_EDID_SHIFT                   (0U)
/*! EDID - Error Domain Identifier */
#define XRDC_DERR_W_EDID(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W_EDID_SHIFT)) & XRDC_DERR_W_EDID_MASK)

#define XRDC_DERR_W_EATR_MASK                    (0x700U)
#define XRDC_DERR_W_EATR_SHIFT                   (8U)
/*! EATR - Error Attributes
 *  0b000..Secure user mode, instruction fetch access
 *  0b001..Secure user mode, data access
 *  0b010..Secure privileged mode, instruction fetch access
 *  0b011..Secure privileged mode, data access
 *  0b100..Nonsecure user mode, instruction fetch access
 *  0b101..Nonsecure user mode, data access
 *  0b110..Nonsecure privileged mode, instruction fetch access
 *  0b111..Nonsecure privileged mode, data access
 */
#define XRDC_DERR_W_EATR(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W_EATR_SHIFT)) & XRDC_DERR_W_EATR_MASK)

#define XRDC_DERR_W_ERW_MASK                     (0x800U)
#define XRDC_DERR_W_ERW_SHIFT                    (11U)
/*! ERW - Error Read Or Write
 *  0b0..Read access
 *  0b1..Write access
 */
#define XRDC_DERR_W_ERW(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W_ERW_SHIFT)) & XRDC_DERR_W_ERW_MASK)

#define XRDC_DERR_W_EPORT_MASK                   (0x7000000U)
#define XRDC_DERR_W_EPORT_SHIFT                  (24U)
/*! EPORT - Error Port */
#define XRDC_DERR_W_EPORT(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W_EPORT_SHIFT)) & XRDC_DERR_W_EPORT_MASK)

#define XRDC_DERR_W_EST_MASK                     (0xC0000000U)
#define XRDC_DERR_W_EST_SHIFT                    (30U)
/*! EST - Error State
 *  0b00-0b01..No access violations detected
 *  0b10..A single access violation has been detected
 *  0b11..Multiple access violations have been detected
 */
#define XRDC_DERR_W_EST(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W_EST_SHIFT)) & XRDC_DERR_W_EST_MASK)

#define XRDC_DERR_W_RECR_MASK                    (0xC0000000U)
#define XRDC_DERR_W_RECR_SHIFT                   (30U)
/*! RECR - Rearm Error Capture Registers
 *  0b00, 0b10, 0b11..No effect
 *  0b01..Rearms error capture, resets error capture registers, and deasserts instance bit in DERRLOCd
 */
#define XRDC_DERR_W_RECR(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W_RECR_SHIFT)) & XRDC_DERR_W_RECR_MASK)
/*! @} */

/* The count of XRDC_DERR_W */
#define XRDC_DERR_W_COUNT                        (18U)

/* The count of XRDC_DERR_W */
#define XRDC_DERR_W_COUNT2                       (4U)

/*! @name PID - Process Identifier */
/*! @{ */

#define XRDC_PID_PID_MASK                        (0x3FU)
#define XRDC_PID_PID_SHIFT                       (0U)
/*! PID - Process Identifier */
#define XRDC_PID_PID(x)                          (((uint32_t)(((uint32_t)(x)) << XRDC_PID_PID_SHIFT)) & XRDC_PID_PID_MASK)

#define XRDC_PID_TSM_MASK                        (0x10000000U)
#define XRDC_PID_TSM_SHIFT                       (28U)
/*! TSM - Three-State Model */
#define XRDC_PID_TSM(x)                          (((uint32_t)(((uint32_t)(x)) << XRDC_PID_TSM_SHIFT)) & XRDC_PID_TSM_MASK)

#define XRDC_PID_LK2_MASK                        (0x60000000U)
#define XRDC_PID_LK2_SHIFT                       (29U)
/*! LK2 - Lock
 *  0b00, 0b01..Any secure privileged write
 *  0b10..Secure privileged writes from master only
 *  0b11..Locks
 */
#define XRDC_PID_LK2(x)                          (((uint32_t)(((uint32_t)(x)) << XRDC_PID_LK2_SHIFT)) & XRDC_PID_LK2_MASK)
/*! @} */

/*! @name MDA_W - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W_DID_MASK                      (0x1U)
#define XRDC_MDA_W_DID_SHIFT                     (0U)
/*! DID - Domain Identifier */
#define XRDC_MDA_W_DID(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_DID_SHIFT)) & XRDC_MDA_W_DID_MASK)

#define XRDC_MDA_W_DIDS_MASK                     (0x30U)
#define XRDC_MDA_W_DIDS_SHIFT                    (4U)
/*! DIDS - DID Select
 *  0b00..Use the DID field of this register
 *  0b01..Use the input DID
 *  0b10..Concatenate bits 3-2 of this register with the least significant 2 bits of the input DID (DID_in[1:0])
 *  0b11..
 */
#define XRDC_MDA_W_DIDS(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_DIDS_SHIFT)) & XRDC_MDA_W_DIDS_MASK)

#define XRDC_MDA_W_PA_MASK                       (0x30U)
#define XRDC_MDA_W_PA_SHIFT                      (4U)
/*! PA - Privileged Attribute
 *  0b00..Force to user
 *  0b01..Force to privileged
 *  0b1x..Use privileged attribute from the master
 */
#define XRDC_MDA_W_PA(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_PA_SHIFT)) & XRDC_MDA_W_PA_MASK)

#define XRDC_MDA_W_PE_MASK                       (0xC0U)
#define XRDC_MDA_W_PE_SHIFT                      (6U)
/*! PE - Process Identifier Enable
 *  0b00-0b01..No PID is included
 *  0b10..Partial domain hit = (PID & ~PIDM) == (PIDm[PID] & ~PIDM)
 *  0b11..Partial domain hit = ~((PID & ~PIDM) == (PIDm[PID] & ~PIDM))
 */
#define XRDC_MDA_W_PE(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_PE_SHIFT)) & XRDC_MDA_W_PE_MASK)

#define XRDC_MDA_W_SA_MASK                       (0xC0U)
#define XRDC_MDA_W_SA_SHIFT                      (6U)
/*! SA - Secure Attribute
 *  0b00..Force to secure
 *  0b01..Force to nonsecure
 *  0b1x..Use secure attribute from the master
 */
#define XRDC_MDA_W_SA(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_SA_SHIFT)) & XRDC_MDA_W_SA_MASK)

#define XRDC_MDA_W_DIDB_MASK                     (0x100U)
#define XRDC_MDA_W_DIDB_SHIFT                    (8U)
/*! DIDB - DID Bypass
 *  0b0..Bypass DID input
 *  0b1..Use DID input
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
/*! DFMT - Domain Format
 *  0b0..Core bus master domain assignment (DFMT0)
 */
#define XRDC_MDA_W_DFMT(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_DFMT_SHIFT)) & XRDC_MDA_W_DFMT_MASK)

#define XRDC_MDA_W_LK1_MASK                      (0x40000000U)
#define XRDC_MDA_W_LK1_SHIFT                     (30U)
/*! LK1 - Lock
 *  0b0..No effect
 *  0b0..Unlocked
 *  0b1..Locks
 */
#define XRDC_MDA_W_LK1(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_LK1_SHIFT)) & XRDC_MDA_W_LK1_MASK)

#define XRDC_MDA_W_VLD_MASK                      (0x80000000U)
#define XRDC_MDA_W_VLD_SHIFT                     (31U)
/*! VLD - Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define XRDC_MDA_W_VLD(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W_VLD_SHIFT)) & XRDC_MDA_W_VLD_MASK)
/*! @} */

/* The count of XRDC_MDA_W */
#define XRDC_MDA_W_COUNT                         (4U)

/* The count of XRDC_MDA_W */
#define XRDC_MDA_W_COUNT2                        (1U)

/*! @name PDAC_W - Peripheral Domain Access Control Word 0..Peripheral Domain Access Control Word 1 */
/*! @{ */

#define XRDC_PDAC_W_D0ACP_MASK                   (0x7U)
#define XRDC_PDAC_W_D0ACP_SHIFT                  (0U)
/*! D0ACP - Domain Access Control Policy */
#define XRDC_PDAC_W_D0ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_D0ACP_SHIFT)) & XRDC_PDAC_W_D0ACP_MASK)

#define XRDC_PDAC_W_D1ACP_MASK                   (0x38U)
#define XRDC_PDAC_W_D1ACP_SHIFT                  (3U)
/*! D1ACP - Domain Access Control Policy */
#define XRDC_PDAC_W_D1ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_D1ACP_SHIFT)) & XRDC_PDAC_W_D1ACP_MASK)

#define XRDC_PDAC_W_SNUM_MASK                    (0xF000000U)
#define XRDC_PDAC_W_SNUM_SHIFT                   (24U)
/*! SNUM - Semaphore Number */
#define XRDC_PDAC_W_SNUM(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_SNUM_SHIFT)) & XRDC_PDAC_W_SNUM_MASK)

#define XRDC_PDAC_W_LK2_MASK                     (0x60000000U)
#define XRDC_PDAC_W_LK2_SHIFT                    (29U)
/*! LK2 - Lock
 *  0b00-0b01..Both words can be written to
 *  0b10..Domain d can update only its associated DdACP field-all other fields are read-only
 *  0b11..Locks (both words are read-only)
 */
#define XRDC_PDAC_W_LK2(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_LK2_SHIFT)) & XRDC_PDAC_W_LK2_MASK)

#define XRDC_PDAC_W_SE_MASK                      (0x40000000U)
#define XRDC_PDAC_W_SE_SHIFT                     (30U)
/*! SE - Semaphore Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XRDC_PDAC_W_SE(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_SE_SHIFT)) & XRDC_PDAC_W_SE_MASK)

#define XRDC_PDAC_W_VLD_MASK                     (0x80000000U)
#define XRDC_PDAC_W_VLD_SHIFT                    (31U)
/*! VLD - Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define XRDC_PDAC_W_VLD(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W_VLD_SHIFT)) & XRDC_PDAC_W_VLD_MASK)
/*! @} */

/* The count of XRDC_PDAC_W */
#define XRDC_PDAC_W_COUNT                        (236U)

/* The count of XRDC_PDAC_W */
#define XRDC_PDAC_W_COUNT2                       (2U)

/*! @name MRGD_W - Memory Region Descriptor Word 0..Memory Region Descriptor Word 3 */
/*! @{ */

#define XRDC_MRGD_W_D0ACP_MASK                   (0x7U)
#define XRDC_MRGD_W_D0ACP_SHIFT                  (0U)
/*! D0ACP - Domain Access Control Policy */
#define XRDC_MRGD_W_D0ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_D0ACP_SHIFT)) & XRDC_MRGD_W_D0ACP_MASK)

#define XRDC_MRGD_W_D1ACP_MASK                   (0x38U)
#define XRDC_MRGD_W_D1ACP_SHIFT                  (3U)
/*! D1ACP - Domain Access Control Policy */
#define XRDC_MRGD_W_D1ACP(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_D1ACP_SHIFT)) & XRDC_MRGD_W_D1ACP_MASK)

#define XRDC_MRGD_W_ENDADDR_MASK                 (0xFFFFFFE0U)
#define XRDC_MRGD_W_ENDADDR_SHIFT                (5U)
/*! ENDADDR - End Address */
#define XRDC_MRGD_W_ENDADDR(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_ENDADDR_SHIFT)) & XRDC_MRGD_W_ENDADDR_MASK)

#define XRDC_MRGD_W_SRTADDR_MASK                 (0xFFFFFFE0U)
#define XRDC_MRGD_W_SRTADDR_SHIFT                (5U)
/*! SRTADDR - Start Address */
#define XRDC_MRGD_W_SRTADDR(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_SRTADDR_SHIFT)) & XRDC_MRGD_W_SRTADDR_MASK)

#define XRDC_MRGD_W_SNUM_MASK                    (0xF000000U)
#define XRDC_MRGD_W_SNUM_SHIFT                   (24U)
/*! SNUM - Semaphore Number */
#define XRDC_MRGD_W_SNUM(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_SNUM_SHIFT)) & XRDC_MRGD_W_SNUM_MASK)

#define XRDC_MRGD_W_LK2_MASK                     (0x60000000U)
#define XRDC_MRGD_W_LK2_SHIFT                    (29U)
/*! LK2 - Lock
 *  0b00..All words in the set can be written to
 *  0b01..Reserved
 *  0b10..Domain d can update only its associated DdACP field; all other fields are read-only
 *  0b11..Locks (all words are read-only)
 */
#define XRDC_MRGD_W_LK2(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_LK2_SHIFT)) & XRDC_MRGD_W_LK2_MASK)

#define XRDC_MRGD_W_SE_MASK                      (0x40000000U)
#define XRDC_MRGD_W_SE_SHIFT                     (30U)
/*! SE - Semaphore Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XRDC_MRGD_W_SE(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_SE_SHIFT)) & XRDC_MRGD_W_SE_MASK)

#define XRDC_MRGD_W_VLD_MASK                     (0x80000000U)
#define XRDC_MRGD_W_VLD_SHIFT                    (31U)
/*! VLD - Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define XRDC_MRGD_W_VLD(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_MRGD_W_VLD_SHIFT)) & XRDC_MRGD_W_VLD_MASK)
/*! @} */

/* The count of XRDC_MRGD_W */
#define XRDC_MRGD_W_COUNT                        (24U)

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

