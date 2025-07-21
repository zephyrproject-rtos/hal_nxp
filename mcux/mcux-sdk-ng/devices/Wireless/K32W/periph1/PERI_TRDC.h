/*
** ###################################################################
**     Processor:           K32W1480VFTA
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TRDC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-01-18)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_TRDC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TRDC
 *
 * CMSIS Peripheral Access Layer for TRDC
 */

#if !defined(PERI_TRDC_H_)
#define PERI_TRDC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32W1480VFTA))
#include "K32W1480_COMMON.h"
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
#if !defined(TRDC_MASTER_T_)
#define TRDC_MASTER_T_
/*!
 * @addtogroup trdc_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the TRDC master mapping
 *
 * Defines the enumeration for the TRDC master resource collections.
 */

typedef enum _trdc_master
{
    kTRDC_MasterCM33                = 0U,          /**< CM33 */
    kTRDC_MasterDMA3                = 1U,          /**< DMA3 */
    kTRDC_MasterDataSteamBuffer     = 2U,          /**< Data stream buffer */
    kTRDC_MasterRadioNBU            = 3U,          /**< Radio NBU */
} trdc_master_t;

/* @} */
#endif /* TRDC_MASTER_T_ */

#if !defined(TRDC_MBC0_SLAVE_T_)
#define TRDC_MBC0_SLAVE_T_
/*!
 * @brief Enumeration for the TRDC MBC0 slave mapping
 *
 * Defines the enumeration for the TRDC MBC0 slave resource collections.
 */
typedef enum _trdc_mbc0_slave
{
    kTRDC_SlaveFlash                = 0U,          /**< Flash - 1MB */
    kTRDC_SlaveFlashIFR0            = 1U,          /**< Flash IFR0 - 32 KB */
    kTRDC_SlaveFlashIFR1            = 2U,          /**< Flash IFR1 - 8 KB */
    kTRDC_SlaveROM                  = 3U,          /**< ROM - 96KB */
} trdc_mbc0_slave_t;
#endif /* TRDC_MBC0_SLAVE_T_ */

#if !defined(TRDC_MBC1_SLAVE_T_)
#define TRDC_MBC1_SLAVE_T_
/*!
 * @brief Enumeration for the TRDC MBC1 slave mapping
 *
 * Defines the enumeration for the TRDC MBC1 slave resource collections.
 */
typedef enum _trdc_mbc1_slave
{
    kTRDC_SlaveCTCM0_1              = 0U,          /**< CTCM0,1 - 16 KB (with ECC) */
    kTRDC_SlaveSTCM0_1_2            = 1U,          /**< STCM0,1,2 - 16,16,32 KB (with ECC) */
    kTRDC_SlaveSTCM3_4              = 2U,          /**< STCM3,4 - 32,8 KB (with ECC) */
    kTRDC_SlaveSTCM5                = 3U,          /**< STCM5 - 8 KB (with ECC) */
} trdc_mbc1_slave_t;
#endif /* TRDC_MBC1_SLAVE_T_ */

#if !defined(TRDC_MBC2_SLAVE_T_)
#define TRDC_MBC2_SLAVE_T_
/*!
 * @brief Enumeration for the TRDC MBC2 slave mapping
 *
 * Defines the enumeration for the TRDC MBC2 slave resource collections.
 */
typedef enum _trdc_mbc2_slave
{
    kTRDC_SlavePBRIDGE2             = 0U,          /**< PBRIDGE2 */
    kTRDC_SlaveRadioPridge          = 1U,          /**< Radio Pridge in Fast Peripheral 1 */
    kTRDC_SlaveNBU                  = 2U,          /**< NBU part in Fast Peripheral 1 */
} trdc_mbc2_slave_t;
#endif /* TRDC_MBC2_SLAVE_T_ */


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
   -- TRDC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRDC_Peripheral_Access_Layer TRDC Peripheral Access Layer
 * @{
 */

/** TRDC - Size of Registers Arrays */
#define TRDC_DACFG_COUNT                          4u
#define TRDC_MBC_COUNT                            4u
#define TRDC_MBC_MBC_CFG_W_COUNT                  2u
#define TRDC_MRC_COUNT                            8u
#define TRDC_DERRLOC_COUNT                        3u
#define TRDC_MBC_DERR_COUNT                       3u
#define TRDC_MRC_DERR_COUNT                       1u
#define TRDC_MDA_W0_DFMT1_COUNT                   3u
#define TRDC_MBC_INDEX_MBC_MEM_GLBCFG_COUNT       4u
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_COUNT       8u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_COUNT 10u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_NSE_W_COUNT 3u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_COUNT 1u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_NSE_W_COUNT 1u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_COUNT 2u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_NSE_W_COUNT 1u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM3_BLK_CFG_W_COUNT 2u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM3_BLK_NSE_W_COUNT 1u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM1_MEM0_BLK_CFG_W_COUNT 10u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM1_MEM0_BLK_NSE_W_COUNT 3u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM1_MEM1_BLK_CFG_W_COUNT 1u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM1_MEM1_BLK_NSE_W_COUNT 1u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM1_MEM2_BLK_CFG_W_COUNT 2u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM1_MEM2_BLK_NSE_W_COUNT 1u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM1_MEM3_BLK_CFG_W_COUNT 2u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM1_MEM3_BLK_NSE_W_COUNT 1u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM2_MEM0_BLK_CFG_W_COUNT 10u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM2_MEM0_BLK_NSE_W_COUNT 3u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM2_MEM1_BLK_CFG_W_COUNT 1u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM2_MEM1_BLK_NSE_W_COUNT 1u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM2_MEM2_BLK_CFG_W_COUNT 2u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM2_MEM2_BLK_NSE_W_COUNT 1u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM2_MEM3_BLK_CFG_W_COUNT 2u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM2_MEM3_BLK_NSE_W_COUNT 1u
#define TRDC_MBC_INDEX_COUNT                      3u
#define TRDC_MRC_INDEX_MRC_GLBAC_COUNT            8u
#define TRDC_MRC_INDEX_MRC_INDEX_DOM0_RGD_COUNT   8u
#define TRDC_MRC_INDEX_MRC_INDEX_DOM0_RGD_MRC_INDEX_DOM0_RGD_W_COUNT 2u
#define TRDC_MRC_INDEX_MRC_INDEX_DOM1_RGD_COUNT   8u
#define TRDC_MRC_INDEX_MRC_INDEX_DOM1_RGD_MRC_INDEX_DOM1_RGD_W_COUNT 2u
#define TRDC_MRC_INDEX_MRC_INDEX_DOM2_RGD_COUNT   8u
#define TRDC_MRC_INDEX_MRC_INDEX_DOM2_RGD_MRC_INDEX_DOM2_RGD_W_COUNT 2u
#define TRDC_MRC_INDEX_COUNT                      1u

/** TRDC - Register Layout Typedef */
typedef struct {
  __IO uint32_t TRDC_CR;                           /**< TRDC Register, offset: 0x0 */
       uint8_t RESERVED_0[236];
  __I  uint32_t TRDC_HWCFG0;                       /**< Hardware Configuration Register 0, offset: 0xF0 */
  __I  uint32_t TRDC_HWCFG1;                       /**< TRDC Hardware Configuration Register 1, offset: 0xF4 */
       uint8_t RESERVED_1[8];
  __I  uint8_t DACFG[TRDC_DACFG_COUNT];            /**< Domain Assignment Configuration Register, array offset: 0x100, array step: 0x1 */
       uint8_t RESERVED_2[60];
  __I  uint32_t CFG[TRDC_MBC_COUNT][TRDC_MBC_MBC_CFG_W_COUNT]; /**< Memory Block Configuration Register, array offset: 0x140, array step: index*0x8, index2*0x4 */
  __I  uint8_t MRCFG[TRDC_MRC_COUNT];              /**< Memory Region Configuration Register, array offset: 0x160, array step: 0x1 */
       uint8_t RESERVED_3[88];
  __IO uint32_t TRDC_IDAU_CR;                      /**< TRDC IDAU Control Register, offset: 0x1C0 */
       uint8_t RESERVED_4[28];
  __IO uint32_t TRDC_FLW_CTL;                      /**< TRDC FLW Control, offset: 0x1E0 */
  __I  uint32_t TRDC_FLW_PBASE;                    /**< TRDC FLW Physical Base, offset: 0x1E4 */
  __IO uint32_t TRDC_FLW_ABASE;                    /**< TRDC FLW Array Base, offset: 0x1E8 */
  __IO uint32_t TRDC_FLW_BCNT;                     /**< TRDC FLW Block Count, offset: 0x1EC */
       uint8_t RESERVED_5[12];
  __IO uint32_t TRDC_FDID;                         /**< TRDC Fault Domain ID, offset: 0x1FC */
  __I  uint32_t TRDC_DERRLOC[TRDC_DERRLOC_COUNT];  /**< TRDC Domain Error Location Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_6[500];
  struct {                                         /* offset: 0x400, array step: 0x10 */
    __I  uint32_t W0;                                /**< MBC Domain Error Word0 Register, array offset: 0x400, array step: 0x10 */
    __I  uint32_t W1;                                /**< MBC Domain Error Word1 Register, array offset: 0x404, array step: 0x10 */
         uint8_t RESERVED_0[4];
    __IO uint32_t W3;                                /**< MBC Domain Error Word3 Register, array offset: 0x40C, array step: 0x10 */
  } MBC_DERR[TRDC_MBC_DERR_COUNT];
       uint8_t RESERVED_7[80];
  struct {                                         /* offset: 0x480, array step: 0x10 */
    __I  uint32_t W0;                                /**< MRC Domain Error Word0 Register, array offset: 0x480, array step: 0x10 */
    __I  uint32_t W1;                                /**< MRC Domain Error Word1 Register, array offset: 0x484, array step: 0x10 */
         uint8_t RESERVED_0[4];
    __IO uint32_t W3;                                /**< MRC Domain Error Word3 Register, array offset: 0x48C, array step: 0x10 */
  } MRC_DERR[TRDC_MRC_DERR_COUNT];
       uint8_t RESERVED_8[880];
  __IO uint32_t MDA_W0_0_DFMT0;                    /**< DAC Master Domain Assignment Register, offset: 0x800 */
       uint8_t RESERVED_9[28];
  struct {                                         /* offset: 0x820, array step: 0x20 */
    __IO uint32_t MDA_W0_x_DFMT1;                    /**< DAC Master Domain Assignment Register, array offset: 0x820, array step: 0x20 */
         uint8_t RESERVED_0[28];
  } MDA_W0_DFMT1[TRDC_MDA_W0_DFMT1_COUNT];
       uint8_t RESERVED_10[1920];
  struct {                                         /* offset: 0x1000, array step: 0x1000 */
    __I  uint32_t MBC_MEM_GLBCFG[TRDC_MBC_INDEX_MBC_MEM_GLBCFG_COUNT];   /**< MBC Global Configuration Register, array offset: 0x1000, array step: index*0x1000, index2*0x4 */
    __IO uint32_t MBC_NSE_BLK_INDEX;                 /**< MBC NonSecure Enable Block Index, array offset: 0x1010, array step: 0x1000 */
    __IO uint32_t MBC_NSE_BLK_SET;                   /**< MBC NonSecure Enable Block Set, array offset: 0x1014, array step: 0x1000 */
    __IO uint32_t MBC_NSE_BLK_CLR;                   /**< MBC NonSecure Enable Block Clear, array offset: 0x1018, array step: 0x1000 */
    __IO uint32_t MBC_NSE_BLK_CLR_ALL;               /**< MBC NonSecure Enable Block Clear All, array offset: 0x101C, array step: 0x1000 */
    __IO uint32_t MBC_MEMN_GLBAC[TRDC_MBC_INDEX_MBC_MEMN_GLBAC_COUNT];   /**< MBC Global Access Control, array offset: 0x1020, array step: index*0x1000, index2*0x4 */
    __IO uint32_t MBC_DOM0_MEM0_BLK_CFG_W[TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_COUNT];   /**< MBC Memory Block Configuration Word, array offset: 0x1040, array step: index*0x1000, index2*0x4, valid indices: [0][0-3], [1][0], [2][0-9] */
         uint8_t RESERVED_0[216];
    __IO uint32_t MBC_DOM0_MEM0_BLK_NSE_W[TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_NSE_W_COUNT];   /**< MBC Memory Block NonSecure Enable Word, array offset: 0x1140, array step: index*0x1000, index2*0x4, valid indices: [0-2][0], [2][1], [2][2] */
         uint8_t RESERVED_1[52];
    __IO uint32_t MBC_DOM0_MEM1_BLK_CFG_W[TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_COUNT];   /**< MBC Memory Block Configuration Word, array offset: 0x1180, array step: index*0x1000, index2*0x4 */
         uint8_t RESERVED_2[28];
    __IO uint32_t MBC_DOM0_MEM1_BLK_NSE_W[TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_NSE_W_COUNT];   /**< MBC Memory Block NonSecure Enable Word, array offset: 0x11A0, array step: index*0x1000, index2*0x4 */
         uint8_t RESERVED_3[4];
    __IO uint32_t MBC_DOM0_MEM2_BLK_CFG_W[TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_COUNT];   /**< MBC Memory Block Configuration Word, array offset: 0x11A8, array step: index*0x1000, index2*0x4, valid indices: [0-2][0], [2][1] */
         uint8_t RESERVED_4[24];
    __IO uint32_t MBC_DOM0_MEM2_BLK_NSE_W[TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_NSE_W_COUNT];   /**< MBC Memory Block NonSecure Enable Word, array offset: 0x11C8, array step: index*0x1000, index2*0x4 */
         uint8_t RESERVED_5[4];
    __IO uint32_t MBC_DOM0_MEM3_BLK_CFG_W[TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM3_BLK_CFG_W_COUNT];   /**< MBC Memory Block Configuration Word, array offset: 0x11D0, array step: index*0x1000, index2*0x4, valid indices: [0-1][0], [0][1] */
         uint8_t RESERVED_6[24];
    __IO uint32_t MBC_DOM0_MEM3_BLK_NSE_W[TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM3_BLK_NSE_W_COUNT];   /**< MBC Memory Block NonSecure Enable Word, array offset: 0x11F0, array step: index*0x1000, index2*0x4, valid indices: [0-1][0] */
         uint8_t RESERVED_7[76];
    __IO uint32_t MBC_DOM1_MEM0_BLK_CFG_W[TRDC_MBC_INDEX_MBC_INDEX_DOM1_MEM0_BLK_CFG_W_COUNT];   /**< MBC Memory Block Configuration Word, array offset: 0x1240, array step: index*0x1000, index2*0x4, valid indices: [0][0-3], [1][0], [2][0-9] */
         uint8_t RESERVED_8[216];
    __IO uint32_t MBC_DOM1_MEM0_BLK_NSE_W[TRDC_MBC_INDEX_MBC_INDEX_DOM1_MEM0_BLK_NSE_W_COUNT];   /**< MBC Memory Block NonSecure Enable Word, array offset: 0x1340, array step: index*0x1000, index2*0x4, valid indices: [0-2][0], [2][1], [2][2] */
         uint8_t RESERVED_9[52];
    __IO uint32_t MBC_DOM1_MEM1_BLK_CFG_W[TRDC_MBC_INDEX_MBC_INDEX_DOM1_MEM1_BLK_CFG_W_COUNT];   /**< MBC Memory Block Configuration Word, array offset: 0x1380, array step: index*0x1000, index2*0x4 */
         uint8_t RESERVED_10[28];
    __IO uint32_t MBC_DOM1_MEM1_BLK_NSE_W[TRDC_MBC_INDEX_MBC_INDEX_DOM1_MEM1_BLK_NSE_W_COUNT];   /**< MBC Memory Block NonSecure Enable Word, array offset: 0x13A0, array step: index*0x1000, index2*0x4 */
         uint8_t RESERVED_11[4];
    __IO uint32_t MBC_DOM1_MEM2_BLK_CFG_W[TRDC_MBC_INDEX_MBC_INDEX_DOM1_MEM2_BLK_CFG_W_COUNT];   /**< MBC Memory Block Configuration Word, array offset: 0x13A8, array step: index*0x1000, index2*0x4, valid indices: [0-2][0], [2][1] */
         uint8_t RESERVED_12[24];
    __IO uint32_t MBC_DOM1_MEM2_BLK_NSE_W[TRDC_MBC_INDEX_MBC_INDEX_DOM1_MEM2_BLK_NSE_W_COUNT];   /**< MBC Memory Block NonSecure Enable Word, array offset: 0x13C8, array step: index*0x1000, index2*0x4 */
         uint8_t RESERVED_13[4];
    __IO uint32_t MBC_DOM1_MEM3_BLK_CFG_W[TRDC_MBC_INDEX_MBC_INDEX_DOM1_MEM3_BLK_CFG_W_COUNT];   /**< MBC Memory Block Configuration Word, array offset: 0x13D0, array step: index*0x1000, index2*0x4, valid indices: [0-1][0], [0][1] */
         uint8_t RESERVED_14[24];
    __IO uint32_t MBC_DOM1_MEM3_BLK_NSE_W[TRDC_MBC_INDEX_MBC_INDEX_DOM1_MEM3_BLK_NSE_W_COUNT];   /**< MBC Memory Block NonSecure Enable Word, array offset: 0x13F0, array step: index*0x1000, index2*0x4, valid indices: [0-1][0] */
         uint8_t RESERVED_15[76];
    __IO uint32_t MBC_DOM2_MEM0_BLK_CFG_W[TRDC_MBC_INDEX_MBC_INDEX_DOM2_MEM0_BLK_CFG_W_COUNT];   /**< MBC Memory Block Configuration Word, array offset: 0x1440, array step: index*0x1000, index2*0x4, valid indices: [0][0-3], [1][0], [2][0-9] */
         uint8_t RESERVED_16[216];
    __IO uint32_t MBC_DOM2_MEM0_BLK_NSE_W[TRDC_MBC_INDEX_MBC_INDEX_DOM2_MEM0_BLK_NSE_W_COUNT];   /**< MBC Memory Block NonSecure Enable Word, array offset: 0x1540, array step: index*0x1000, index2*0x4, valid indices: [0-2][0], [2][1], [2][2] */
         uint8_t RESERVED_17[52];
    __IO uint32_t MBC_DOM2_MEM1_BLK_CFG_W[TRDC_MBC_INDEX_MBC_INDEX_DOM2_MEM1_BLK_CFG_W_COUNT];   /**< MBC Memory Block Configuration Word, array offset: 0x1580, array step: index*0x1000, index2*0x4 */
         uint8_t RESERVED_18[28];
    __IO uint32_t MBC_DOM2_MEM1_BLK_NSE_W[TRDC_MBC_INDEX_MBC_INDEX_DOM2_MEM1_BLK_NSE_W_COUNT];   /**< MBC Memory Block NonSecure Enable Word, array offset: 0x15A0, array step: index*0x1000, index2*0x4 */
         uint8_t RESERVED_19[4];
    __IO uint32_t MBC_DOM2_MEM2_BLK_CFG_W[TRDC_MBC_INDEX_MBC_INDEX_DOM2_MEM2_BLK_CFG_W_COUNT];   /**< MBC Memory Block Configuration Word, array offset: 0x15A8, array step: index*0x1000, index2*0x4, valid indices: [0-2][0], [2][1] */
         uint8_t RESERVED_20[24];
    __IO uint32_t MBC_DOM2_MEM2_BLK_NSE_W[TRDC_MBC_INDEX_MBC_INDEX_DOM2_MEM2_BLK_NSE_W_COUNT];   /**< MBC Memory Block NonSecure Enable Word, array offset: 0x15C8, array step: index*0x1000, index2*0x4 */
         uint8_t RESERVED_21[4];
    __IO uint32_t MBC_DOM2_MEM3_BLK_CFG_W[TRDC_MBC_INDEX_MBC_INDEX_DOM2_MEM3_BLK_CFG_W_COUNT];   /**< MBC Memory Block Configuration Word, array offset: 0x15D0, array step: index*0x1000, index2*0x4, valid indices: [0-1][0], [0][1] */
         uint8_t RESERVED_22[24];
    __IO uint32_t MBC_DOM2_MEM3_BLK_NSE_W[TRDC_MBC_INDEX_MBC_INDEX_DOM2_MEM3_BLK_NSE_W_COUNT];   /**< MBC Memory Block NonSecure Enable Word, array offset: 0x15F0, array step: index*0x1000, index2*0x4, valid indices: [0-1][0] */
         uint8_t RESERVED_23[2572];
  } MBC_INDEX[TRDC_MBC_INDEX_COUNT];
  struct {                                         /* offset: 0x4000, array step: 0x2C4 */
    __I  uint32_t MRC_GLBCFG;                        /**< MRC Global Configuration Register, array offset: 0x4000, array step: 0x2C4 */
         uint8_t RESERVED_0[12];
    __IO uint32_t MRC_NSE_RGN_INDIRECT;              /**< MRC NonSecure Enable Region Indirect, array offset: 0x4010, array step: 0x2C4 */
    __IO uint32_t MRC_NSE_RGN_SET;                   /**< MRC NonSecure Enable Region Set, array offset: 0x4014, array step: 0x2C4 */
    __IO uint32_t MRC_NSE_RGN_CLR;                   /**< MRC NonSecure Enable Region Clear, array offset: 0x4018, array step: 0x2C4 */
    __IO uint32_t MRC_NSE_RGN_CLR_ALL;               /**< MRC NonSecure Enable Region Clear All, array offset: 0x401C, array step: 0x2C4 */
    __IO uint32_t MRC_GLBAC[TRDC_MRC_INDEX_MRC_GLBAC_COUNT];   /**< MRC Global Access Control, array offset: 0x4020, array step: index*0x2C4, index2*0x4 */
    __IO uint32_t MRC_DOM0_RGD_W[TRDC_MRC_INDEX_MRC_INDEX_DOM0_RGD_COUNT][TRDC_MRC_INDEX_MRC_INDEX_DOM0_RGD_MRC_INDEX_DOM0_RGD_W_COUNT];   /**< MRC Region Descriptor Word 0..MRC Region Descriptor Word 1, array offset: 0x4040, array step: index*0x2C4, index2*0x8, index3*0x4 */
         uint8_t RESERVED_1[64];
    __IO uint32_t MRC_DOM0_RGD_NSE;                  /**< MRC Region Descriptor NonSecure Enable, array offset: 0x40C0, array step: 0x2C4 */
         uint8_t RESERVED_2[124];
    __IO uint32_t MRC_DOM1_RGD_W[TRDC_MRC_INDEX_MRC_INDEX_DOM1_RGD_COUNT][TRDC_MRC_INDEX_MRC_INDEX_DOM1_RGD_MRC_INDEX_DOM1_RGD_W_COUNT];   /**< MRC Region Descriptor Word 0..MRC Region Descriptor Word 1, array offset: 0x4140, array step: index*0x2C4, index2*0x8, index3*0x4 */
         uint8_t RESERVED_3[64];
    __IO uint32_t MRC_DOM1_RGD_NSE;                  /**< MRC Region Descriptor NonSecure Enable, array offset: 0x41C0, array step: 0x2C4 */
         uint8_t RESERVED_4[124];
    __IO uint32_t MRC_DOM2_RGD_W[TRDC_MRC_INDEX_MRC_INDEX_DOM2_RGD_COUNT][TRDC_MRC_INDEX_MRC_INDEX_DOM2_RGD_MRC_INDEX_DOM2_RGD_W_COUNT];   /**< MRC Region Descriptor Word 0..MRC Region Descriptor Word 1, array offset: 0x4240, array step: index*0x2C4, index2*0x8, index3*0x4 */
         uint8_t RESERVED_5[64];
    __IO uint32_t MRC_DOM2_RGD_NSE;                  /**< MRC Region Descriptor NonSecure Enable, array offset: 0x42C0, array step: 0x2C4 */
  } MRC_INDEX[TRDC_MRC_INDEX_COUNT];
} TRDC_Type;

/* ----------------------------------------------------------------------------
   -- TRDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRDC_Register_Masks TRDC Register Masks
 * @{
 */

/*! @name TRDC_CR - TRDC Register */
/*! @{ */

#define TRDC_TRDC_CR_GVLDM_MASK                  (0x1U)
#define TRDC_TRDC_CR_GVLDM_SHIFT                 (0U)
/*! GVLDM - Global Valid for Domain Assignment Controllers
 *  0b0..TRDC DACs are disabled.
 *  0b1..TRDC DACs are enabled.
 */
#define TRDC_TRDC_CR_GVLDM(x)                    (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_CR_GVLDM_SHIFT)) & TRDC_TRDC_CR_GVLDM_MASK)

#define TRDC_TRDC_CR_HRL_MASK                    (0x1EU)
#define TRDC_TRDC_CR_HRL_SHIFT                   (1U)
/*! HRL - Hardware Revision Level */
#define TRDC_TRDC_CR_HRL(x)                      (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_CR_HRL_SHIFT)) & TRDC_TRDC_CR_HRL_MASK)

#define TRDC_TRDC_CR_GVLDB_MASK                  (0x4000U)
#define TRDC_TRDC_CR_GVLDB_SHIFT                 (14U)
/*! GVLDB - Global Valid for Memory Block Checkers
 *  0b0..TRDC MBCs are disabled.
 *  0b1..TRDC MBCs are enabled.
 */
#define TRDC_TRDC_CR_GVLDB(x)                    (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_CR_GVLDB_SHIFT)) & TRDC_TRDC_CR_GVLDB_MASK)

#define TRDC_TRDC_CR_GVLDR_MASK                  (0x8000U)
#define TRDC_TRDC_CR_GVLDR_SHIFT                 (15U)
/*! GVLDR - Global Valid for Memory Region Checkers
 *  0b0..TRDC MRCs are disabled.
 *  0b1..TRDC MRCs are enabled.
 */
#define TRDC_TRDC_CR_GVLDR(x)                    (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_CR_GVLDR_SHIFT)) & TRDC_TRDC_CR_GVLDR_MASK)

#define TRDC_TRDC_CR_LK1_MASK                    (0x40000000U)
#define TRDC_TRDC_CR_LK1_SHIFT                   (30U)
/*! LK1 - Lock Status
 *  0b0..The CR can be written by any secure privileged write.
 *  0b1..The CR is locked (read-only) until the next reset.
 */
#define TRDC_TRDC_CR_LK1(x)                      (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_CR_LK1_SHIFT)) & TRDC_TRDC_CR_LK1_MASK)
/*! @} */

/*! @name TRDC_HWCFG0 - Hardware Configuration Register 0 */
/*! @{ */

#define TRDC_TRDC_HWCFG0_NDID_MASK               (0xFU)
#define TRDC_TRDC_HWCFG0_NDID_SHIFT              (0U)
/*! NDID - Number of domains */
#define TRDC_TRDC_HWCFG0_NDID(x)                 (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_HWCFG0_NDID_SHIFT)) & TRDC_TRDC_HWCFG0_NDID_MASK)

#define TRDC_TRDC_HWCFG0_NMSTR_MASK              (0xFF00U)
#define TRDC_TRDC_HWCFG0_NMSTR_SHIFT             (8U)
/*! NMSTR - Number of bus masters */
#define TRDC_TRDC_HWCFG0_NMSTR(x)                (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_HWCFG0_NMSTR_SHIFT)) & TRDC_TRDC_HWCFG0_NMSTR_MASK)

#define TRDC_TRDC_HWCFG0_NMBC_MASK               (0x70000U)
#define TRDC_TRDC_HWCFG0_NMBC_SHIFT              (16U)
/*! NMBC - Number of MBCs */
#define TRDC_TRDC_HWCFG0_NMBC(x)                 (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_HWCFG0_NMBC_SHIFT)) & TRDC_TRDC_HWCFG0_NMBC_MASK)

#define TRDC_TRDC_HWCFG0_NMRC_MASK               (0xF000000U)
#define TRDC_TRDC_HWCFG0_NMRC_SHIFT              (24U)
/*! NMRC - Number of MRCs */
#define TRDC_TRDC_HWCFG0_NMRC(x)                 (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_HWCFG0_NMRC_SHIFT)) & TRDC_TRDC_HWCFG0_NMRC_MASK)

#define TRDC_TRDC_HWCFG0_MID_MASK                (0xF0000000U)
#define TRDC_TRDC_HWCFG0_MID_SHIFT               (28U)
/*! MID - Module ID */
#define TRDC_TRDC_HWCFG0_MID(x)                  (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_HWCFG0_MID_SHIFT)) & TRDC_TRDC_HWCFG0_MID_MASK)
/*! @} */

/*! @name TRDC_HWCFG1 - TRDC Hardware Configuration Register 1 */
/*! @{ */

#define TRDC_TRDC_HWCFG1_DID_MASK                (0x7U)
#define TRDC_TRDC_HWCFG1_DID_SHIFT               (0U)
/*! DID - Domain identifier number */
#define TRDC_TRDC_HWCFG1_DID(x)                  (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_HWCFG1_DID_SHIFT)) & TRDC_TRDC_HWCFG1_DID_MASK)
/*! @} */

/*! @name DACFG - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_DACFG_NMDAR_MASK                    (0xFU)
#define TRDC_DACFG_NMDAR_SHIFT                   (0U)
/*! NMDAR - Number of master domain assignment registers for bus master m */
#define TRDC_DACFG_NMDAR(x)                      (((uint8_t)(((uint8_t)(x)) << TRDC_DACFG_NMDAR_SHIFT)) & TRDC_DACFG_NMDAR_MASK)

#define TRDC_DACFG_NCM_MASK                      (0x80U)
#define TRDC_DACFG_NCM_SHIFT                     (7U)
/*! NCM - Non-CPU Master
 *  0b0..Bus master is a processor.
 *  0b1..Bus master is a non-processor.
 */
#define TRDC_DACFG_NCM(x)                        (((uint8_t)(((uint8_t)(x)) << TRDC_DACFG_NCM_SHIFT)) & TRDC_DACFG_NCM_MASK)
/*! @} */

/*! @name CFG - Memory Block Configuration Register */
/*! @{ */

#define TRDC_CFG_SLV0_NMBLK_MASK                 (0x3FFU)
#define TRDC_CFG_SLV0_NMBLK_SHIFT                (0U)
/*! SLV0_NMBLK - Number of blocks in slave 0. */
#define TRDC_CFG_SLV0_NMBLK(x)                   (((uint32_t)(((uint32_t)(x)) << TRDC_CFG_SLV0_NMBLK_SHIFT)) & TRDC_CFG_SLV0_NMBLK_MASK)

#define TRDC_CFG_SLV2_NMBLK_MASK                 (0x3FFU)
#define TRDC_CFG_SLV2_NMBLK_SHIFT                (0U)
/*! SLV2_NMBLK - Number of blocks in slave 2. */
#define TRDC_CFG_SLV2_NMBLK(x)                   (((uint32_t)(((uint32_t)(x)) << TRDC_CFG_SLV2_NMBLK_SHIFT)) & TRDC_CFG_SLV2_NMBLK_MASK)

#define TRDC_CFG_SLV0_BLKSZL2_MASK               (0x7C00U)
#define TRDC_CFG_SLV0_BLKSZL2_SHIFT              (10U)
/*! SLV0_BLKSZL2 - Block size log2 in slave 0. */
#define TRDC_CFG_SLV0_BLKSZL2(x)                 (((uint32_t)(((uint32_t)(x)) << TRDC_CFG_SLV0_BLKSZL2_SHIFT)) & TRDC_CFG_SLV0_BLKSZL2_MASK)

#define TRDC_CFG_SLV2_BLKSZL2_MASK               (0x7C00U)
#define TRDC_CFG_SLV2_BLKSZL2_SHIFT              (10U)
/*! SLV2_BLKSZL2 - Block size log2 in slave 2. */
#define TRDC_CFG_SLV2_BLKSZL2(x)                 (((uint32_t)(((uint32_t)(x)) << TRDC_CFG_SLV2_BLKSZL2_SHIFT)) & TRDC_CFG_SLV2_BLKSZL2_MASK)

#define TRDC_CFG_SLV1_NMBLK_MASK                 (0x3FF0000U)
#define TRDC_CFG_SLV1_NMBLK_SHIFT                (16U)
/*! SLV1_NMBLK - Number of blocks in slave 1. */
#define TRDC_CFG_SLV1_NMBLK(x)                   (((uint32_t)(((uint32_t)(x)) << TRDC_CFG_SLV1_NMBLK_SHIFT)) & TRDC_CFG_SLV1_NMBLK_MASK)

#define TRDC_CFG_SLV3_NMBLK_MASK                 (0x3FF0000U)
#define TRDC_CFG_SLV3_NMBLK_SHIFT                (16U)
/*! SLV3_NMBLK - Number of blocks in slave 3. */
#define TRDC_CFG_SLV3_NMBLK(x)                   (((uint32_t)(((uint32_t)(x)) << TRDC_CFG_SLV3_NMBLK_SHIFT)) & TRDC_CFG_SLV3_NMBLK_MASK)

#define TRDC_CFG_SLV1_BLKSZL2_MASK               (0x7C000000U)
#define TRDC_CFG_SLV1_BLKSZL2_SHIFT              (26U)
/*! SLV1_BLKSZL2 - Block size log2 in slave 1. */
#define TRDC_CFG_SLV1_BLKSZL2(x)                 (((uint32_t)(((uint32_t)(x)) << TRDC_CFG_SLV1_BLKSZL2_SHIFT)) & TRDC_CFG_SLV1_BLKSZL2_MASK)

#define TRDC_CFG_SLV3_BLKSZL2_MASK               (0x7C000000U)
#define TRDC_CFG_SLV3_BLKSZL2_SHIFT              (26U)
/*! SLV3_BLKSZL2 - Block size log2 in slave 3. */
#define TRDC_CFG_SLV3_BLKSZL2(x)                 (((uint32_t)(((uint32_t)(x)) << TRDC_CFG_SLV3_BLKSZL2_SHIFT)) & TRDC_CFG_SLV3_BLKSZL2_MASK)
/*! @} */

/* The count of TRDC_CFG */
#define TRDC_CFG_COUNT                           (4U)

/* The count of TRDC_CFG */
#define TRDC_CFG_COUNT2                          (2U)

/*! @name MRCFG - Memory Region Configuration Register */
/*! @{ */

#define TRDC_MRCFG_NMRGD_MASK                    (0x1FU)
#define TRDC_MRCFG_NMRGD_SHIFT                   (0U)
/*! NMRGD - Number of memory region descriptors for memory region checker n */
#define TRDC_MRCFG_NMRGD(x)                      (((uint8_t)(((uint8_t)(x)) << TRDC_MRCFG_NMRGD_SHIFT)) & TRDC_MRCFG_NMRGD_MASK)
/*! @} */

/* The count of TRDC_MRCFG */
#define TRDC_MRCFG_COUNT                         (8U)

/*! @name TRDC_IDAU_CR - TRDC IDAU Control Register */
/*! @{ */

#define TRDC_TRDC_IDAU_CR_VLD_MASK               (0x1U)
#define TRDC_TRDC_IDAU_CR_VLD_SHIFT              (0U)
/*! VLD - Valid */
#define TRDC_TRDC_IDAU_CR_VLD(x)                 (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_IDAU_CR_VLD_SHIFT)) & TRDC_TRDC_IDAU_CR_VLD_MASK)

#define TRDC_TRDC_IDAU_CR_CFGSECEXT_MASK         (0x8U)
#define TRDC_TRDC_IDAU_CR_CFGSECEXT_SHIFT        (3U)
/*! CFGSECEXT - Configure Security Extension
 *  0b0..ARMv8M Security Extension is disabled
 *  0b1..ARMv8-M Security Extension is enabled
 */
#define TRDC_TRDC_IDAU_CR_CFGSECEXT(x)           (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_IDAU_CR_CFGSECEXT_SHIFT)) & TRDC_TRDC_IDAU_CR_CFGSECEXT_MASK)

#define TRDC_TRDC_IDAU_CR_MPUSDIS_MASK           (0x10U)
#define TRDC_TRDC_IDAU_CR_MPUSDIS_SHIFT          (4U)
/*! MPUSDIS - Secure Memory Protection Unit Disabled
 *  0b0..Secure MPU is enabled
 *  0b1..Secure MPU is disabled
 */
#define TRDC_TRDC_IDAU_CR_MPUSDIS(x)             (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_IDAU_CR_MPUSDIS_SHIFT)) & TRDC_TRDC_IDAU_CR_MPUSDIS_MASK)

#define TRDC_TRDC_IDAU_CR_MPUNSDIS_MASK          (0x20U)
#define TRDC_TRDC_IDAU_CR_MPUNSDIS_SHIFT         (5U)
/*! MPUNSDIS - NonSecure Memory Protection Unit Disabled
 *  0b0..Nonsecure MPU is enabled
 *  0b1..Nonsecure MPU is disabled
 */
#define TRDC_TRDC_IDAU_CR_MPUNSDIS(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_IDAU_CR_MPUNSDIS_SHIFT)) & TRDC_TRDC_IDAU_CR_MPUNSDIS_MASK)

#define TRDC_TRDC_IDAU_CR_SAUDIS_MASK            (0x40U)
#define TRDC_TRDC_IDAU_CR_SAUDIS_SHIFT           (6U)
/*! SAUDIS - Security Attribution Unit Disable
 *  0b0..SAU is enabled
 *  0b1..SAU is disabled
 */
#define TRDC_TRDC_IDAU_CR_SAUDIS(x)              (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_IDAU_CR_SAUDIS_SHIFT)) & TRDC_TRDC_IDAU_CR_SAUDIS_MASK)

#define TRDC_TRDC_IDAU_CR_LKSVTAIRCR_MASK        (0x100U)
#define TRDC_TRDC_IDAU_CR_LKSVTAIRCR_SHIFT       (8U)
/*! LKSVTAIRCR - Lock Secure VTOR, Application interrupt and Reset Control Registers
 *  0b0..Unlock these registers
 *  0b1..Disable writes to the VTOR_S, AIRCR[PRIS], and AIRCR[BFHFNMINS] registers
 */
#define TRDC_TRDC_IDAU_CR_LKSVTAIRCR(x)          (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_IDAU_CR_LKSVTAIRCR_SHIFT)) & TRDC_TRDC_IDAU_CR_LKSVTAIRCR_MASK)

#define TRDC_TRDC_IDAU_CR_LKNSVTOR_MASK          (0x200U)
#define TRDC_TRDC_IDAU_CR_LKNSVTOR_SHIFT         (9U)
/*! LKNSVTOR - Lock Nonsecure Vector Table Offset Register
 *  0b0..Unlock this register
 *  0b1..Disable writes to the VTOR_NS register
 */
#define TRDC_TRDC_IDAU_CR_LKNSVTOR(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_IDAU_CR_LKNSVTOR_SHIFT)) & TRDC_TRDC_IDAU_CR_LKNSVTOR_MASK)

#define TRDC_TRDC_IDAU_CR_LKSMPU_MASK            (0x400U)
#define TRDC_TRDC_IDAU_CR_LKSMPU_SHIFT           (10U)
/*! LKSMPU - Lock Secure MPU
 *  0b0..Unlock these registers
 *  0b1..Disable writes to the MPU_CTRL, MPU_RNR, MPU_RBAR, MPU_RLAR, MPU_RBAR_An and MPU_RLAR_An from software or
 *       from a debug agent connected to the processor in Secure state
 */
#define TRDC_TRDC_IDAU_CR_LKSMPU(x)              (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_IDAU_CR_LKSMPU_SHIFT)) & TRDC_TRDC_IDAU_CR_LKSMPU_MASK)

#define TRDC_TRDC_IDAU_CR_LKNSMPU_MASK           (0x800U)
#define TRDC_TRDC_IDAU_CR_LKNSMPU_SHIFT          (11U)
/*! LKNSMPU - Lock Nonsecure MPU
 *  0b0..Unlock these registers
 *  0b1..Disable writes to the MPU_CTRL_NS, MPU_RNR_NS, MPU_RBAR_NS, MPU_RLAR_NS, MPU_RBAR_A_NSn and
 *       MPU_RLAR_A_NSn from software or from a debug agent connected to the processor
 */
#define TRDC_TRDC_IDAU_CR_LKNSMPU(x)             (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_IDAU_CR_LKNSMPU_SHIFT)) & TRDC_TRDC_IDAU_CR_LKNSMPU_MASK)

#define TRDC_TRDC_IDAU_CR_LKSAU_MASK             (0x1000U)
#define TRDC_TRDC_IDAU_CR_LKSAU_SHIFT            (12U)
/*! LKSAU - Lock SAU
 *  0b0..Unlock these registers
 *  0b1..Disable writes to the SAU_CTRL, SAU_RNR, SAU_RBAR and SAU_RLAR registers from software or from a debug agent connected to the processor
 */
#define TRDC_TRDC_IDAU_CR_LKSAU(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_IDAU_CR_LKSAU_SHIFT)) & TRDC_TRDC_IDAU_CR_LKSAU_MASK)

#define TRDC_TRDC_IDAU_CR_PCURRNS_MASK           (0x80000000U)
#define TRDC_TRDC_IDAU_CR_PCURRNS_SHIFT          (31U)
/*! PCURRNS - Processor current security
 *  0b0..Processor is in Secure state
 *  0b1..Processor is in Nonsecure state
 */
#define TRDC_TRDC_IDAU_CR_PCURRNS(x)             (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_IDAU_CR_PCURRNS_SHIFT)) & TRDC_TRDC_IDAU_CR_PCURRNS_MASK)
/*! @} */

/*! @name TRDC_FLW_CTL - TRDC FLW Control */
/*! @{ */

#define TRDC_TRDC_FLW_CTL_LK_MASK                (0x40000000U)
#define TRDC_TRDC_FLW_CTL_LK_SHIFT               (30U)
/*! LK - Lock bit
 *  0b0..FLW registers may be modified.
 *  0b1..FLW registers are locked until the next reset.
 */
#define TRDC_TRDC_FLW_CTL_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_FLW_CTL_LK_SHIFT)) & TRDC_TRDC_FLW_CTL_LK_MASK)

#define TRDC_TRDC_FLW_CTL_V_MASK                 (0x80000000U)
#define TRDC_TRDC_FLW_CTL_V_SHIFT                (31U)
/*! V - Valid bit
 *  0b0..FLW function is disabled.
 *  0b1..FLW function is enabled.
 */
#define TRDC_TRDC_FLW_CTL_V(x)                   (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_FLW_CTL_V_SHIFT)) & TRDC_TRDC_FLW_CTL_V_MASK)
/*! @} */

/*! @name TRDC_FLW_PBASE - TRDC FLW Physical Base */
/*! @{ */

#define TRDC_TRDC_FLW_PBASE_PBASE_MASK           (0xFFFFFFFFU)
#define TRDC_TRDC_FLW_PBASE_PBASE_SHIFT          (0U)
/*! PBASE - Physical base address */
#define TRDC_TRDC_FLW_PBASE_PBASE(x)             (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_FLW_PBASE_PBASE_SHIFT)) & TRDC_TRDC_FLW_PBASE_PBASE_MASK)
/*! @} */

/*! @name TRDC_FLW_ABASE - TRDC FLW Array Base */
/*! @{ */

#define TRDC_TRDC_FLW_ABASE_ABASE_L_MASK         (0x3F8000U)
#define TRDC_TRDC_FLW_ABASE_ABASE_L_SHIFT        (15U)
/*! ABASE_L - Array base address low */
#define TRDC_TRDC_FLW_ABASE_ABASE_L(x)           (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_FLW_ABASE_ABASE_L_SHIFT)) & TRDC_TRDC_FLW_ABASE_ABASE_L_MASK)

#define TRDC_TRDC_FLW_ABASE_ABASE_H_MASK         (0xFFC00000U)
#define TRDC_TRDC_FLW_ABASE_ABASE_H_SHIFT        (22U)
/*! ABASE_H - Array base address high */
#define TRDC_TRDC_FLW_ABASE_ABASE_H(x)           (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_FLW_ABASE_ABASE_H_SHIFT)) & TRDC_TRDC_FLW_ABASE_ABASE_H_MASK)
/*! @} */

/*! @name TRDC_FLW_BCNT - TRDC FLW Block Count */
/*! @{ */

#define TRDC_TRDC_FLW_BCNT_BCNT_MASK             (0x7FFFU)
#define TRDC_TRDC_FLW_BCNT_BCNT_SHIFT            (0U)
/*! BCNT - Block Count */
#define TRDC_TRDC_FLW_BCNT_BCNT(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_FLW_BCNT_BCNT_SHIFT)) & TRDC_TRDC_FLW_BCNT_BCNT_MASK)
/*! @} */

/*! @name TRDC_FDID - TRDC Fault Domain ID */
/*! @{ */

#define TRDC_TRDC_FDID_FDID_MASK                 (0xFU)
#define TRDC_TRDC_FDID_FDID_SHIFT                (0U)
/*! FDID - Domain ID of Faulted Access */
#define TRDC_TRDC_FDID_FDID(x)                   (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_FDID_FDID_SHIFT)) & TRDC_TRDC_FDID_FDID_MASK)
/*! @} */

/*! @name TRDC_DERRLOC - TRDC Domain Error Location Register */
/*! @{ */

#define TRDC_TRDC_DERRLOC_mbc0_err_slv_MASK      (0xFU)
#define TRDC_TRDC_DERRLOC_mbc0_err_slv_SHIFT     (0U)
/*! mbc0_err_slv - MBC0 ERROR SLAVE */
#define TRDC_TRDC_DERRLOC_mbc0_err_slv(x)        (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_DERRLOC_mbc0_err_slv_SHIFT)) & TRDC_TRDC_DERRLOC_mbc0_err_slv_MASK)

#define TRDC_TRDC_DERRLOC_mbc1_err_slv_MASK      (0xF0U)
#define TRDC_TRDC_DERRLOC_mbc1_err_slv_SHIFT     (4U)
/*! mbc1_err_slv - MBC1 ERROR SLAVE */
#define TRDC_TRDC_DERRLOC_mbc1_err_slv(x)        (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_DERRLOC_mbc1_err_slv_SHIFT)) & TRDC_TRDC_DERRLOC_mbc1_err_slv_MASK)

#define TRDC_TRDC_DERRLOC_mbc2_err_slv_MASK      (0xF00U)
#define TRDC_TRDC_DERRLOC_mbc2_err_slv_SHIFT     (8U)
/*! mbc2_err_slv - MBC2 ERROR SLAVE */
#define TRDC_TRDC_DERRLOC_mbc2_err_slv(x)        (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_DERRLOC_mbc2_err_slv_SHIFT)) & TRDC_TRDC_DERRLOC_mbc2_err_slv_MASK)

#define TRDC_TRDC_DERRLOC_mbc3_err_slv_MASK      (0xF000U)
#define TRDC_TRDC_DERRLOC_mbc3_err_slv_SHIFT     (12U)
/*! mbc3_err_slv - MBC3 ERROR SLAVE */
#define TRDC_TRDC_DERRLOC_mbc3_err_slv(x)        (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_DERRLOC_mbc3_err_slv_SHIFT)) & TRDC_TRDC_DERRLOC_mbc3_err_slv_MASK)

#define TRDC_TRDC_DERRLOC_MRCINST_MASK           (0xFF0000U)
#define TRDC_TRDC_DERRLOC_MRCINST_SHIFT          (16U)
/*! MRCINST - MRC instance */
#define TRDC_TRDC_DERRLOC_MRCINST(x)             (((uint32_t)(((uint32_t)(x)) << TRDC_TRDC_DERRLOC_MRCINST_SHIFT)) & TRDC_TRDC_DERRLOC_MRCINST_MASK)
/*! @} */

/* The count of TRDC_TRDC_DERRLOC */
#define TRDC_TRDC_DERRLOC_COUNT                  (3U)

/*! @name W0 - MBC Domain Error Word0 Register */
/*! @{ */

#define TRDC_W0_EADDR_MASK                       (0xFFFFFFFFU)
#define TRDC_W0_EADDR_SHIFT                      (0U)
/*! EADDR - Error address */
#define TRDC_W0_EADDR(x)                         (((uint32_t)(((uint32_t)(x)) << TRDC_W0_EADDR_SHIFT)) & TRDC_W0_EADDR_MASK)
/*! @} */

/* The count of TRDC_W0 */
#define TRDC_W0_COUNT                            (3U)

/*! @name W1 - MBC Domain Error Word1 Register */
/*! @{ */

#define TRDC_W1_EDID_MASK                        (0xFU)
#define TRDC_W1_EDID_SHIFT                       (0U)
/*! EDID - Error domain identifier */
#define TRDC_W1_EDID(x)                          (((uint32_t)(((uint32_t)(x)) << TRDC_W1_EDID_SHIFT)) & TRDC_W1_EDID_MASK)

#define TRDC_W1_EATR_MASK                        (0x700U)
#define TRDC_W1_EATR_SHIFT                       (8U)
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
#define TRDC_W1_EATR(x)                          (((uint32_t)(((uint32_t)(x)) << TRDC_W1_EATR_SHIFT)) & TRDC_W1_EATR_MASK)

#define TRDC_W1_ERW_MASK                         (0x800U)
#define TRDC_W1_ERW_SHIFT                        (11U)
/*! ERW - Error read/write
 *  0b0..Read access
 *  0b1..Write access
 */
#define TRDC_W1_ERW(x)                           (((uint32_t)(((uint32_t)(x)) << TRDC_W1_ERW_SHIFT)) & TRDC_W1_ERW_MASK)

#define TRDC_W1_EPORT_MASK                       (0x7000000U)
#define TRDC_W1_EPORT_SHIFT                      (24U)
/*! EPORT - Error port
 *  0b000..mbcxslv0
 *  0b001..mbcxslv1
 *  0b010..mbcxslv2
 *  0b011..mbcxslv3
 */
#define TRDC_W1_EPORT(x)                         (((uint32_t)(((uint32_t)(x)) << TRDC_W1_EPORT_SHIFT)) & TRDC_W1_EPORT_MASK)

#define TRDC_W1_EST_MASK                         (0xC0000000U)
#define TRDC_W1_EST_SHIFT                        (30U)
/*! EST - Error state
 *  0b00..No access violation has been detected.
 *  0b01..No access violation has been detected.
 *  0b10..A single access violation has been detected.
 *  0b11..Multiple access violations for this domain have been detected by this submodule instance. Only the
 *        address and attribute information for the first error have been captured in DERR_W0_i and DERR_W1_i.
 */
#define TRDC_W1_EST(x)                           (((uint32_t)(((uint32_t)(x)) << TRDC_W1_EST_SHIFT)) & TRDC_W1_EST_MASK)
/*! @} */

/* The count of TRDC_W1 */
#define TRDC_W1_COUNT                            (3U)

/*! @name W3 - MBC Domain Error Word3 Register */
/*! @{ */

#define TRDC_W3_RECR_MASK                        (0xC0000000U)
#define TRDC_W3_RECR_SHIFT                       (30U)
/*! RECR - Rearm Error Capture Registers */
#define TRDC_W3_RECR(x)                          (((uint32_t)(((uint32_t)(x)) << TRDC_W3_RECR_SHIFT)) & TRDC_W3_RECR_MASK)
/*! @} */

/* The count of TRDC_W3 */
#define TRDC_W3_COUNT                            (3U)

/*! @name W0 - MRC Domain Error Word0 Register */
/*! @{ */

#define TRDC_W0_EADDR_MASK                       (0xFFFFFFFFU)
#define TRDC_W0_EADDR_SHIFT                      (0U)
/*! EADDR - Error address */
#define TRDC_W0_EADDR(x)                         (((uint32_t)(((uint32_t)(x)) << TRDC_W0_EADDR_SHIFT)) & TRDC_W0_EADDR_MASK)
/*! @} */

/* The count of TRDC_W0 */
#define TRDC_MRC_DERR_W0_COUNT                   (1U)

/*! @name W1 - MRC Domain Error Word1 Register */
/*! @{ */

#define TRDC_W1_EDID_MASK                        (0xFU)
#define TRDC_W1_EDID_SHIFT                       (0U)
/*! EDID - Error domain identifier */
#define TRDC_W1_EDID(x)                          (((uint32_t)(((uint32_t)(x)) << TRDC_W1_EDID_SHIFT)) & TRDC_W1_EDID_MASK)

#define TRDC_W1_EATR_MASK                        (0x700U)
#define TRDC_W1_EATR_SHIFT                       (8U)
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
#define TRDC_W1_EATR(x)                          (((uint32_t)(((uint32_t)(x)) << TRDC_W1_EATR_SHIFT)) & TRDC_W1_EATR_MASK)

#define TRDC_W1_ERW_MASK                         (0x800U)
#define TRDC_W1_ERW_SHIFT                        (11U)
/*! ERW - Error read/write
 *  0b0..Read access
 *  0b1..Write access
 */
#define TRDC_W1_ERW(x)                           (((uint32_t)(((uint32_t)(x)) << TRDC_W1_ERW_SHIFT)) & TRDC_W1_ERW_MASK)

#define TRDC_W1_EPORT_MASK                       (0x7000000U)
#define TRDC_W1_EPORT_SHIFT                      (24U)
/*! EPORT - Error port */
#define TRDC_W1_EPORT(x)                         (((uint32_t)(((uint32_t)(x)) << TRDC_W1_EPORT_SHIFT)) & TRDC_W1_EPORT_MASK)

#define TRDC_W1_EST_MASK                         (0xC0000000U)
#define TRDC_W1_EST_SHIFT                        (30U)
/*! EST - Error state
 *  0b00..No access violation has been detected.
 *  0b01..No access violation has been detected.
 *  0b10..A single access violation has been detected.
 *  0b11..Multiple access violations for this domain have been detected by this submodule instance. Only the
 *        address and attribute information for the first error have been captured in DERR_W0_i and DERR_W1_i.
 */
#define TRDC_W1_EST(x)                           (((uint32_t)(((uint32_t)(x)) << TRDC_W1_EST_SHIFT)) & TRDC_W1_EST_MASK)
/*! @} */

/* The count of TRDC_W1 */
#define TRDC_MRC_DERR_W1_COUNT                   (1U)

/*! @name W3 - MRC Domain Error Word3 Register */
/*! @{ */

#define TRDC_W3_RECR_MASK                        (0xC0000000U)
#define TRDC_W3_RECR_SHIFT                       (30U)
/*! RECR - Rearm Error Capture Registers */
#define TRDC_W3_RECR(x)                          (((uint32_t)(((uint32_t)(x)) << TRDC_W3_RECR_SHIFT)) & TRDC_W3_RECR_MASK)
/*! @} */

/* The count of TRDC_W3 */
#define TRDC_MRC_DERR_W3_COUNT                   (1U)

/*! @name MDA_W0_0_DFMT0 - DAC Master Domain Assignment Register */
/*! @{ */

#define TRDC_MDA_W0_0_DFMT0_DID_MASK             (0xFU)
#define TRDC_MDA_W0_0_DFMT0_DID_SHIFT            (0U)
/*! DID - Domain identifier */
#define TRDC_MDA_W0_0_DFMT0_DID(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MDA_W0_0_DFMT0_DID_SHIFT)) & TRDC_MDA_W0_0_DFMT0_DID_MASK)

#define TRDC_MDA_W0_0_DFMT0_DIDS_MASK            (0x30U)
#define TRDC_MDA_W0_0_DFMT0_DIDS_SHIFT           (4U)
/*! DIDS - DID Select
 *  0b00..Use MDAm[3:0] as the domain identifier.
 *  0b01..Use the input DID as the domain identifier.
 *  0b10..Use MDAm[3:2] concatenated with the low-order 2 bits of the input DID (DID_in[1:0]) as the domain identifier.
 *  0b11..Reserved for future use.
 */
#define TRDC_MDA_W0_0_DFMT0_DIDS(x)              (((uint32_t)(((uint32_t)(x)) << TRDC_MDA_W0_0_DFMT0_DIDS_SHIFT)) & TRDC_MDA_W0_0_DFMT0_DIDS_MASK)

#define TRDC_MDA_W0_0_DFMT0_DFMT_MASK            (0x20000000U)
#define TRDC_MDA_W0_0_DFMT0_DFMT_SHIFT           (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MDA_W0_0_DFMT0_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << TRDC_MDA_W0_0_DFMT0_DFMT_SHIFT)) & TRDC_MDA_W0_0_DFMT0_DFMT_MASK)

#define TRDC_MDA_W0_0_DFMT0_LK1_MASK             (0x40000000U)
#define TRDC_MDA_W0_0_DFMT0_LK1_SHIFT            (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MDA_W0_0_DFMT0_LK1(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MDA_W0_0_DFMT0_LK1_SHIFT)) & TRDC_MDA_W0_0_DFMT0_LK1_MASK)

#define TRDC_MDA_W0_0_DFMT0_VLD_MASK             (0x80000000U)
#define TRDC_MDA_W0_0_DFMT0_VLD_SHIFT            (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MDA_W0_0_DFMT0_VLD(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MDA_W0_0_DFMT0_VLD_SHIFT)) & TRDC_MDA_W0_0_DFMT0_VLD_MASK)
/*! @} */

/*! @name MDA_W0_x_DFMT1 - DAC Master Domain Assignment Register */
/*! @{ */

#define TRDC_MDA_W0_x_DFMT1_DID_MASK             (0xFU)
#define TRDC_MDA_W0_x_DFMT1_DID_SHIFT            (0U)
/*! DID - Domain identifier */
#define TRDC_MDA_W0_x_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MDA_W0_x_DFMT1_DID_SHIFT)) & TRDC_MDA_W0_x_DFMT1_DID_MASK)

#define TRDC_MDA_W0_x_DFMT1_PA_MASK              (0x30U)
#define TRDC_MDA_W0_x_DFMT1_PA_SHIFT             (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this master to user.
 *  0b01..Force the bus attribute for this master to privileged.
 *  0b10..Use the bus master's privileged/user attribute directly.
 *  0b11..Use the bus master's privileged/user attribute directly.
 */
#define TRDC_MDA_W0_x_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << TRDC_MDA_W0_x_DFMT1_PA_SHIFT)) & TRDC_MDA_W0_x_DFMT1_PA_MASK)

#define TRDC_MDA_W0_x_DFMT1_SA_MASK              (0xC0U)
#define TRDC_MDA_W0_x_DFMT1_SA_SHIFT             (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this master to secure.
 *  0b01..Force the bus attribute for this master to nonsecure.
 *  0b10..Use the bus master's secure/nonsecure attribute directly.
 *  0b11..Use the bus master's secure/nonsecure attribute directly.
 */
#define TRDC_MDA_W0_x_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << TRDC_MDA_W0_x_DFMT1_SA_SHIFT)) & TRDC_MDA_W0_x_DFMT1_SA_MASK)

#define TRDC_MDA_W0_x_DFMT1_DIDB_MASK            (0x100U)
#define TRDC_MDA_W0_x_DFMT1_DIDB_SHIFT           (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MDA_W0_x_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << TRDC_MDA_W0_x_DFMT1_DIDB_SHIFT)) & TRDC_MDA_W0_x_DFMT1_DIDB_MASK)

#define TRDC_MDA_W0_x_DFMT1_DFMT_MASK            (0x20000000U)
#define TRDC_MDA_W0_x_DFMT1_DFMT_SHIFT           (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MDA_W0_x_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << TRDC_MDA_W0_x_DFMT1_DFMT_SHIFT)) & TRDC_MDA_W0_x_DFMT1_DFMT_MASK)

#define TRDC_MDA_W0_x_DFMT1_LK1_MASK             (0x40000000U)
#define TRDC_MDA_W0_x_DFMT1_LK1_SHIFT            (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MDA_W0_x_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MDA_W0_x_DFMT1_LK1_SHIFT)) & TRDC_MDA_W0_x_DFMT1_LK1_MASK)

#define TRDC_MDA_W0_x_DFMT1_VLD_MASK             (0x80000000U)
#define TRDC_MDA_W0_x_DFMT1_VLD_SHIFT            (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MDA_W0_x_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MDA_W0_x_DFMT1_VLD_SHIFT)) & TRDC_MDA_W0_x_DFMT1_VLD_MASK)
/*! @} */

/* The count of TRDC_MDA_W0_x_DFMT1 */
#define TRDC_MDA_W0_x_DFMT1_COUNT                (3U)

/*! @name MBC_MEM_GLBCFG - MBC Global Configuration Register */
/*! @{ */

#define TRDC_MBC_MEM_GLBCFG_NBLKS_MASK           (0x3FFU)
#define TRDC_MBC_MEM_GLBCFG_NBLKS_SHIFT          (0U)
/*! NBLKS - Number of blocks in this memory */
#define TRDC_MBC_MEM_GLBCFG_NBLKS(x)             (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_MEM_GLBCFG_NBLKS_SHIFT)) & TRDC_MBC_MEM_GLBCFG_NBLKS_MASK)

#define TRDC_MBC_MEM_GLBCFG_SIZE_LOG2_MASK       (0x1F0000U)
#define TRDC_MBC_MEM_GLBCFG_SIZE_LOG2_SHIFT      (16U)
/*! SIZE_LOG2 - Log2 size per block */
#define TRDC_MBC_MEM_GLBCFG_SIZE_LOG2(x)         (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_MEM_GLBCFG_SIZE_LOG2_SHIFT)) & TRDC_MBC_MEM_GLBCFG_SIZE_LOG2_MASK)
/*! @} */

/* The count of TRDC_MBC_MEM_GLBCFG */
#define TRDC_MBC_MEM_GLBCFG_COUNT                (3U)

/* The count of TRDC_MBC_MEM_GLBCFG */
#define TRDC_MBC_MEM_GLBCFG_COUNT2               (4U)

/*! @name MBC_NSE_BLK_INDEX - MBC NonSecure Enable Block Index */
/*! @{ */

#define TRDC_MBC_NSE_BLK_INDEX_WNDX_MASK         (0x3CU)
#define TRDC_MBC_NSE_BLK_INDEX_WNDX_SHIFT        (2U)
/*! WNDX - Word index into the block NSE bitmap. It selects the BLK_NSE_Wn register, where WNDX determines the value of n. */
#define TRDC_MBC_NSE_BLK_INDEX_WNDX(x)           (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_NSE_BLK_INDEX_WNDX_SHIFT)) & TRDC_MBC_NSE_BLK_INDEX_WNDX_MASK)

#define TRDC_MBC_NSE_BLK_INDEX_MEM_SEL_MASK      (0xF00U)
#define TRDC_MBC_NSE_BLK_INDEX_MEM_SEL_SHIFT     (8U)
/*! MEM_SEL - Memory Select */
#define TRDC_MBC_NSE_BLK_INDEX_MEM_SEL(x)        (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_NSE_BLK_INDEX_MEM_SEL_SHIFT)) & TRDC_MBC_NSE_BLK_INDEX_MEM_SEL_MASK)

#define TRDC_MBC_NSE_BLK_INDEX_DID_SEL0_MASK     (0x10000U)
#define TRDC_MBC_NSE_BLK_INDEX_DID_SEL0_SHIFT    (16U)
/*! DID_SEL0 - DID Select
 *  0b0..No effect.
 *  0b1..Selects NSE bits for this domain.
 */
#define TRDC_MBC_NSE_BLK_INDEX_DID_SEL0(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_NSE_BLK_INDEX_DID_SEL0_SHIFT)) & TRDC_MBC_NSE_BLK_INDEX_DID_SEL0_MASK)

#define TRDC_MBC_NSE_BLK_INDEX_DID_SEL1_MASK     (0x20000U)
#define TRDC_MBC_NSE_BLK_INDEX_DID_SEL1_SHIFT    (17U)
/*! DID_SEL1 - DID Select
 *  0b0..No effect.
 *  0b1..Selects NSE bits for this domain.
 */
#define TRDC_MBC_NSE_BLK_INDEX_DID_SEL1(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_NSE_BLK_INDEX_DID_SEL1_SHIFT)) & TRDC_MBC_NSE_BLK_INDEX_DID_SEL1_MASK)

#define TRDC_MBC_NSE_BLK_INDEX_DID_SEL2_MASK     (0x40000U)
#define TRDC_MBC_NSE_BLK_INDEX_DID_SEL2_SHIFT    (18U)
/*! DID_SEL2 - DID Select
 *  0b0..No effect.
 *  0b1..Selects NSE bits for this domain.
 */
#define TRDC_MBC_NSE_BLK_INDEX_DID_SEL2(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_NSE_BLK_INDEX_DID_SEL2_SHIFT)) & TRDC_MBC_NSE_BLK_INDEX_DID_SEL2_MASK)

#define TRDC_MBC_NSE_BLK_INDEX_AI_MASK           (0x80000000U)
#define TRDC_MBC_NSE_BLK_INDEX_AI_SHIFT          (31U)
/*! AI - Auto Increment
 *  0b0..No effect.
 *  0b1..Add 1 to the WNDX field after the register write.
 */
#define TRDC_MBC_NSE_BLK_INDEX_AI(x)             (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_NSE_BLK_INDEX_AI_SHIFT)) & TRDC_MBC_NSE_BLK_INDEX_AI_MASK)
/*! @} */

/* The count of TRDC_MBC_NSE_BLK_INDEX */
#define TRDC_MBC_NSE_BLK_INDEX_COUNT             (3U)

/*! @name MBC_NSE_BLK_SET - MBC NonSecure Enable Block Set */
/*! @{ */

#define TRDC_MBC_NSE_BLK_SET_W1SET_MASK          (0xFFFFFFFFU)
#define TRDC_MBC_NSE_BLK_SET_W1SET_SHIFT         (0U)
/*! W1SET - Write-1 Set */
#define TRDC_MBC_NSE_BLK_SET_W1SET(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_NSE_BLK_SET_W1SET_SHIFT)) & TRDC_MBC_NSE_BLK_SET_W1SET_MASK)
/*! @} */

/* The count of TRDC_MBC_NSE_BLK_SET */
#define TRDC_MBC_NSE_BLK_SET_COUNT               (3U)

/*! @name MBC_NSE_BLK_CLR - MBC NonSecure Enable Block Clear */
/*! @{ */

#define TRDC_MBC_NSE_BLK_CLR_W1CLR_MASK          (0xFFFFFFFFU)
#define TRDC_MBC_NSE_BLK_CLR_W1CLR_SHIFT         (0U)
/*! W1CLR - Write-1 Clear */
#define TRDC_MBC_NSE_BLK_CLR_W1CLR(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_NSE_BLK_CLR_W1CLR_SHIFT)) & TRDC_MBC_NSE_BLK_CLR_W1CLR_MASK)
/*! @} */

/* The count of TRDC_MBC_NSE_BLK_CLR */
#define TRDC_MBC_NSE_BLK_CLR_COUNT               (3U)

/*! @name MBC_NSE_BLK_CLR_ALL - MBC NonSecure Enable Block Clear All */
/*! @{ */

#define TRDC_MBC_NSE_BLK_CLR_ALL_MEMSEL_MASK     (0xF00U)
#define TRDC_MBC_NSE_BLK_CLR_ALL_MEMSEL_SHIFT    (8U)
/*! MEMSEL - Memory Select */
#define TRDC_MBC_NSE_BLK_CLR_ALL_MEMSEL(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_NSE_BLK_CLR_ALL_MEMSEL_SHIFT)) & TRDC_MBC_NSE_BLK_CLR_ALL_MEMSEL_MASK)

#define TRDC_MBC_NSE_BLK_CLR_ALL_DID_SEL_MASK    (0x70000U)
#define TRDC_MBC_NSE_BLK_CLR_ALL_DID_SEL_SHIFT   (16U)
/*! DID_SEL - DID Select
 *  0b000..No effect.
 *  0b001..Clear all NSE bits for this domain.
 */
#define TRDC_MBC_NSE_BLK_CLR_ALL_DID_SEL(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_NSE_BLK_CLR_ALL_DID_SEL_SHIFT)) & TRDC_MBC_NSE_BLK_CLR_ALL_DID_SEL_MASK)
/*! @} */

/* The count of TRDC_MBC_NSE_BLK_CLR_ALL */
#define TRDC_MBC_NSE_BLK_CLR_ALL_COUNT           (3U)

/*! @name MBC_MEMN_GLBAC - MBC Global Access Control */
/*! @{ */

#define TRDC_MBC_MEMN_GLBAC_NUX_MASK             (0x1U)
#define TRDC_MBC_MEMN_GLBAC_NUX_SHIFT            (0U)
/*! NUX - NonsecureUser Execute
 *  0b0..Execute access is not allowed in Nonsecure User mode.
 *  0b1..Execute access is allowed in Nonsecure User mode.
 */
#define TRDC_MBC_MEMN_GLBAC_NUX(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_MEMN_GLBAC_NUX_SHIFT)) & TRDC_MBC_MEMN_GLBAC_NUX_MASK)

#define TRDC_MBC_MEMN_GLBAC_NUW_MASK             (0x2U)
#define TRDC_MBC_MEMN_GLBAC_NUW_SHIFT            (1U)
/*! NUW - NonsecureUser Write
 *  0b0..Write access is not allowed in Nonsecure User mode.
 *  0b1..Write access is allowed in Nonsecure User mode.
 */
#define TRDC_MBC_MEMN_GLBAC_NUW(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_MEMN_GLBAC_NUW_SHIFT)) & TRDC_MBC_MEMN_GLBAC_NUW_MASK)

#define TRDC_MBC_MEMN_GLBAC_NUR_MASK             (0x4U)
#define TRDC_MBC_MEMN_GLBAC_NUR_SHIFT            (2U)
/*! NUR - NonsecureUser Read
 *  0b0..Read access is not allowed in Nonsecure User mode.
 *  0b1..Read access is allowed in Nonsecure User mode.
 */
#define TRDC_MBC_MEMN_GLBAC_NUR(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_MEMN_GLBAC_NUR_SHIFT)) & TRDC_MBC_MEMN_GLBAC_NUR_MASK)

#define TRDC_MBC_MEMN_GLBAC_NPX_MASK             (0x10U)
#define TRDC_MBC_MEMN_GLBAC_NPX_SHIFT            (4U)
/*! NPX - NonsecurePriv Execute
 *  0b0..Execute access is not allowed in Nonsecure Privilege mode.
 *  0b1..Execute access is allowed in Nonsecure Privilege mode.
 */
#define TRDC_MBC_MEMN_GLBAC_NPX(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_MEMN_GLBAC_NPX_SHIFT)) & TRDC_MBC_MEMN_GLBAC_NPX_MASK)

#define TRDC_MBC_MEMN_GLBAC_NPW_MASK             (0x20U)
#define TRDC_MBC_MEMN_GLBAC_NPW_SHIFT            (5U)
/*! NPW - NonsecurePriv Write
 *  0b0..Write access is not allowed in Nonsecure Privilege mode.
 *  0b1..Write access is allowed in Nonsecure Privilege mode.
 */
#define TRDC_MBC_MEMN_GLBAC_NPW(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_MEMN_GLBAC_NPW_SHIFT)) & TRDC_MBC_MEMN_GLBAC_NPW_MASK)

#define TRDC_MBC_MEMN_GLBAC_NPR_MASK             (0x40U)
#define TRDC_MBC_MEMN_GLBAC_NPR_SHIFT            (6U)
/*! NPR - NonsecurePriv Read
 *  0b0..Read access is not allowed in Nonsecure Privilege mode.
 *  0b1..Read access is allowed in Nonsecure Privilege mode.
 */
#define TRDC_MBC_MEMN_GLBAC_NPR(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_MEMN_GLBAC_NPR_SHIFT)) & TRDC_MBC_MEMN_GLBAC_NPR_MASK)

#define TRDC_MBC_MEMN_GLBAC_SUX_MASK             (0x100U)
#define TRDC_MBC_MEMN_GLBAC_SUX_SHIFT            (8U)
/*! SUX - SecureUser Execute
 *  0b0..Execute access is not allowed in Secure User mode.
 *  0b1..Execute access is allowed in Secure User mode.
 */
#define TRDC_MBC_MEMN_GLBAC_SUX(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_MEMN_GLBAC_SUX_SHIFT)) & TRDC_MBC_MEMN_GLBAC_SUX_MASK)

#define TRDC_MBC_MEMN_GLBAC_SUW_MASK             (0x200U)
#define TRDC_MBC_MEMN_GLBAC_SUW_SHIFT            (9U)
/*! SUW - SecureUser Write
 *  0b0..Write access is not allowed in Secure User mode.
 *  0b1..Write access is allowed in Secure User mode.
 */
#define TRDC_MBC_MEMN_GLBAC_SUW(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_MEMN_GLBAC_SUW_SHIFT)) & TRDC_MBC_MEMN_GLBAC_SUW_MASK)

#define TRDC_MBC_MEMN_GLBAC_SUR_MASK             (0x400U)
#define TRDC_MBC_MEMN_GLBAC_SUR_SHIFT            (10U)
/*! SUR - SecureUser Read
 *  0b0..Read access is not allowed in Secure User mode.
 *  0b1..Read access is allowed in Secure User mode.
 */
#define TRDC_MBC_MEMN_GLBAC_SUR(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_MEMN_GLBAC_SUR_SHIFT)) & TRDC_MBC_MEMN_GLBAC_SUR_MASK)

#define TRDC_MBC_MEMN_GLBAC_SPX_MASK             (0x1000U)
#define TRDC_MBC_MEMN_GLBAC_SPX_SHIFT            (12U)
/*! SPX - SecurePriv Execute
 *  0b0..Execute access is not allowed in Secure Privilege mode.
 *  0b1..Execute access is allowed in Secure Privilege mode.
 */
#define TRDC_MBC_MEMN_GLBAC_SPX(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_MEMN_GLBAC_SPX_SHIFT)) & TRDC_MBC_MEMN_GLBAC_SPX_MASK)

#define TRDC_MBC_MEMN_GLBAC_SPW_MASK             (0x2000U)
#define TRDC_MBC_MEMN_GLBAC_SPW_SHIFT            (13U)
/*! SPW - SecurePriv Write
 *  0b0..Write access is not allowed in Secure Privilege mode.
 *  0b1..Write access is allowed in Secure Privilege mode.
 */
#define TRDC_MBC_MEMN_GLBAC_SPW(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_MEMN_GLBAC_SPW_SHIFT)) & TRDC_MBC_MEMN_GLBAC_SPW_MASK)

#define TRDC_MBC_MEMN_GLBAC_SPR_MASK             (0x4000U)
#define TRDC_MBC_MEMN_GLBAC_SPR_SHIFT            (14U)
/*! SPR - SecurePriv Read
 *  0b0..Read access is not allowed in Secure Privilege mode.
 *  0b1..Read access is allowed in Secure Privilege mode.
 */
#define TRDC_MBC_MEMN_GLBAC_SPR(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_MEMN_GLBAC_SPR_SHIFT)) & TRDC_MBC_MEMN_GLBAC_SPR_MASK)

#define TRDC_MBC_MEMN_GLBAC_LK_MASK              (0x80000000U)
#define TRDC_MBC_MEMN_GLBAC_LK_SHIFT             (31U)
/*! LK - LOCK
 *  0b0..This register is not locked and can be altered.
 *  0b1..This register is locked and cannot be altered.
 */
#define TRDC_MBC_MEMN_GLBAC_LK(x)                (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_MEMN_GLBAC_LK_SHIFT)) & TRDC_MBC_MEMN_GLBAC_LK_MASK)
/*! @} */

/* The count of TRDC_MBC_MEMN_GLBAC */
#define TRDC_MBC_MEMN_GLBAC_COUNT                (3U)

/* The count of TRDC_MBC_MEMN_GLBAC */
#define TRDC_MBC_MEMN_GLBAC_COUNT2               (8U)

/*! @name MBC_DOM0_MEM0_BLK_CFG_W - MBC Memory Block Configuration Word */
/*! @{ */

#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL0_MASK (0x7U)
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL0_SHIFT (0U)
/*! MBACSEL0 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL0_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL0_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE0_MASK   (0x8U)
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE0_SHIFT  (3U)
/*! NSE0 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE0_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE0_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL1_MASK (0x70U)
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL1_SHIFT (4U)
/*! MBACSEL1 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL1_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL1_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE1_MASK   (0x80U)
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE1_SHIFT  (7U)
/*! NSE1 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE1_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE1_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL2_MASK (0x700U)
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL2_SHIFT (8U)
/*! MBACSEL2 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL2_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL2_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE2_MASK   (0x800U)
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE2_SHIFT  (11U)
/*! NSE2 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE2_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE2_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL3_MASK (0x7000U)
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL3_SHIFT (12U)
/*! MBACSEL3 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL3_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL3_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE3_MASK   (0x8000U)
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE3_SHIFT  (15U)
/*! NSE3 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE3_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE3_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL4_MASK (0x70000U)
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL4_SHIFT (16U)
/*! MBACSEL4 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL4_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL4_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE4_MASK   (0x80000U)
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE4_SHIFT  (19U)
/*! NSE4 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE4_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE4_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL5_MASK (0x700000U)
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL5_SHIFT (20U)
/*! MBACSEL5 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL5_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL5_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE5_MASK   (0x800000U)
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE5_SHIFT  (23U)
/*! NSE5 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE5_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE5_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL6_MASK (0x7000000U)
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL6_SHIFT (24U)
/*! MBACSEL6 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL6_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL6_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE6_MASK   (0x8000000U)
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE6_SHIFT  (27U)
/*! NSE6 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE6_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE6_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL7_MASK (0x70000000U)
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL7_SHIFT (28U)
/*! MBACSEL7 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL7_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL7_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE7_MASK   (0x80000000U)
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE7_SHIFT  (31U)
/*! NSE7 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE7_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_CFG_W_NSE7_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM0_MEM0_BLK_CFG_W */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM0_MEM0_BLK_CFG_W */
#define TRDC_MBC_DOM0_MEM0_BLK_CFG_W_COUNT2      (10U)

/*! @name MBC_DOM0_MEM0_BLK_NSE_W - MBC Memory Block NonSecure Enable Word */
/*! @{ */

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT0_MASK   (0x1U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT0_SHIFT  (0U)
/*! BIT0 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT0_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT0_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT1_MASK   (0x2U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT1_SHIFT  (1U)
/*! BIT1 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT1_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT1_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT2_MASK   (0x4U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT2_SHIFT  (2U)
/*! BIT2 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT2_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT2_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT3_MASK   (0x8U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT3_SHIFT  (3U)
/*! BIT3 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT3_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT3_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT4_MASK   (0x10U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT4_SHIFT  (4U)
/*! BIT4 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT4_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT4_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT5_MASK   (0x20U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT5_SHIFT  (5U)
/*! BIT5 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT5_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT5_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT6_MASK   (0x40U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT6_SHIFT  (6U)
/*! BIT6 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT6_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT6_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT7_MASK   (0x80U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT7_SHIFT  (7U)
/*! BIT7 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT7_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT7_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT8_MASK   (0x100U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT8_SHIFT  (8U)
/*! BIT8 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT8(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT8_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT8_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT9_MASK   (0x200U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT9_SHIFT  (9U)
/*! BIT9 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT9(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT9_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT9_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT10_MASK  (0x400U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT10_SHIFT (10U)
/*! BIT10 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT10(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT10_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT10_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT11_MASK  (0x800U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT11_SHIFT (11U)
/*! BIT11 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT11(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT11_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT11_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT12_MASK  (0x1000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT12_SHIFT (12U)
/*! BIT12 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT12(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT12_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT12_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT13_MASK  (0x2000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT13_SHIFT (13U)
/*! BIT13 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT13(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT13_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT13_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT14_MASK  (0x4000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT14_SHIFT (14U)
/*! BIT14 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT14(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT14_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT14_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT15_MASK  (0x8000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT15_SHIFT (15U)
/*! BIT15 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT15(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT15_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT15_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT16_MASK  (0x10000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT16_SHIFT (16U)
/*! BIT16 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT16(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT16_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT16_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT17_MASK  (0x20000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT17_SHIFT (17U)
/*! BIT17 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT17(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT17_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT17_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT18_MASK  (0x40000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT18_SHIFT (18U)
/*! BIT18 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT18(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT18_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT18_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT19_MASK  (0x80000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT19_SHIFT (19U)
/*! BIT19 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT19(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT19_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT19_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT20_MASK  (0x100000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT20_SHIFT (20U)
/*! BIT20 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT20(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT20_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT20_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT21_MASK  (0x200000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT21_SHIFT (21U)
/*! BIT21 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT21(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT21_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT21_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT22_MASK  (0x400000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT22_SHIFT (22U)
/*! BIT22 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT22(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT22_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT22_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT23_MASK  (0x800000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT23_SHIFT (23U)
/*! BIT23 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT23(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT23_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT23_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT24_MASK  (0x1000000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT24_SHIFT (24U)
/*! BIT24 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT24(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT24_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT24_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT25_MASK  (0x2000000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT25_SHIFT (25U)
/*! BIT25 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT25(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT25_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT25_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT26_MASK  (0x4000000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT26_SHIFT (26U)
/*! BIT26 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT26(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT26_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT26_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT27_MASK  (0x8000000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT27_SHIFT (27U)
/*! BIT27 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT27(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT27_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT27_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT28_MASK  (0x10000000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT28_SHIFT (28U)
/*! BIT28 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT28(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT28_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT28_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT29_MASK  (0x20000000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT29_SHIFT (29U)
/*! BIT29 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT29(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT29_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT29_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT30_MASK  (0x40000000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT30_SHIFT (30U)
/*! BIT30 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT30(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT30_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT30_MASK)

#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT31_MASK  (0x80000000U)
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT31_SHIFT (31U)
/*! BIT31 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT31(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT31_SHIFT)) & TRDC_MBC_DOM0_MEM0_BLK_NSE_W_BIT31_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM0_MEM0_BLK_NSE_W */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM0_MEM0_BLK_NSE_W */
#define TRDC_MBC_DOM0_MEM0_BLK_NSE_W_COUNT2      (3U)

/*! @name MBC_DOM0_MEM1_BLK_CFG_W - MBC Memory Block Configuration Word */
/*! @{ */

#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL0_MASK (0x7U)
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL0_SHIFT (0U)
/*! MBACSEL0 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL0_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL0_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE0_MASK   (0x8U)
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE0_SHIFT  (3U)
/*! NSE0 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE0_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE0_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL1_MASK (0x70U)
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL1_SHIFT (4U)
/*! MBACSEL1 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL1_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL1_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE1_MASK   (0x80U)
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE1_SHIFT  (7U)
/*! NSE1 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE1_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE1_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL2_MASK (0x700U)
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL2_SHIFT (8U)
/*! MBACSEL2 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL2_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL2_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE2_MASK   (0x800U)
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE2_SHIFT  (11U)
/*! NSE2 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE2_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE2_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL3_MASK (0x7000U)
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL3_SHIFT (12U)
/*! MBACSEL3 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL3_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL3_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE3_MASK   (0x8000U)
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE3_SHIFT  (15U)
/*! NSE3 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE3_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE3_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL4_MASK (0x70000U)
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL4_SHIFT (16U)
/*! MBACSEL4 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL4_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL4_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE4_MASK   (0x80000U)
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE4_SHIFT  (19U)
/*! NSE4 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE4_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE4_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL5_MASK (0x700000U)
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL5_SHIFT (20U)
/*! MBACSEL5 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL5_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL5_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE5_MASK   (0x800000U)
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE5_SHIFT  (23U)
/*! NSE5 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE5_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE5_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL6_MASK (0x7000000U)
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL6_SHIFT (24U)
/*! MBACSEL6 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL6_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL6_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE6_MASK   (0x8000000U)
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE6_SHIFT  (27U)
/*! NSE6 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE6_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE6_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL7_MASK (0x70000000U)
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL7_SHIFT (28U)
/*! MBACSEL7 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL7_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL7_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE7_MASK   (0x80000000U)
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE7_SHIFT  (31U)
/*! NSE7 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE7_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_CFG_W_NSE7_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM0_MEM1_BLK_CFG_W */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM0_MEM1_BLK_CFG_W */
#define TRDC_MBC_DOM0_MEM1_BLK_CFG_W_COUNT2      (1U)

/*! @name MBC_DOM0_MEM1_BLK_NSE_W - MBC Memory Block NonSecure Enable Word */
/*! @{ */

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT0_MASK   (0x1U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT0_SHIFT  (0U)
/*! BIT0 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT0_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT0_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT1_MASK   (0x2U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT1_SHIFT  (1U)
/*! BIT1 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT1_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT1_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT2_MASK   (0x4U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT2_SHIFT  (2U)
/*! BIT2 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT2_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT2_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT3_MASK   (0x8U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT3_SHIFT  (3U)
/*! BIT3 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT3_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT3_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT4_MASK   (0x10U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT4_SHIFT  (4U)
/*! BIT4 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT4_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT4_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT5_MASK   (0x20U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT5_SHIFT  (5U)
/*! BIT5 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT5_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT5_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT6_MASK   (0x40U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT6_SHIFT  (6U)
/*! BIT6 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT6_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT6_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT7_MASK   (0x80U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT7_SHIFT  (7U)
/*! BIT7 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT7_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT7_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT8_MASK   (0x100U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT8_SHIFT  (8U)
/*! BIT8 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT8(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT8_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT8_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT9_MASK   (0x200U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT9_SHIFT  (9U)
/*! BIT9 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT9(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT9_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT9_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT10_MASK  (0x400U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT10_SHIFT (10U)
/*! BIT10 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT10(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT10_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT10_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT11_MASK  (0x800U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT11_SHIFT (11U)
/*! BIT11 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT11(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT11_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT11_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT12_MASK  (0x1000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT12_SHIFT (12U)
/*! BIT12 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT12(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT12_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT12_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT13_MASK  (0x2000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT13_SHIFT (13U)
/*! BIT13 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT13(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT13_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT13_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT14_MASK  (0x4000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT14_SHIFT (14U)
/*! BIT14 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT14(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT14_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT14_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT15_MASK  (0x8000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT15_SHIFT (15U)
/*! BIT15 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT15(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT15_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT15_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT16_MASK  (0x10000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT16_SHIFT (16U)
/*! BIT16 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT16(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT16_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT16_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT17_MASK  (0x20000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT17_SHIFT (17U)
/*! BIT17 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT17(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT17_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT17_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT18_MASK  (0x40000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT18_SHIFT (18U)
/*! BIT18 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT18(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT18_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT18_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT19_MASK  (0x80000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT19_SHIFT (19U)
/*! BIT19 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT19(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT19_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT19_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT20_MASK  (0x100000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT20_SHIFT (20U)
/*! BIT20 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT20(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT20_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT20_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT21_MASK  (0x200000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT21_SHIFT (21U)
/*! BIT21 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT21(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT21_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT21_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT22_MASK  (0x400000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT22_SHIFT (22U)
/*! BIT22 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT22(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT22_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT22_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT23_MASK  (0x800000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT23_SHIFT (23U)
/*! BIT23 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT23(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT23_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT23_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT24_MASK  (0x1000000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT24_SHIFT (24U)
/*! BIT24 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT24(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT24_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT24_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT25_MASK  (0x2000000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT25_SHIFT (25U)
/*! BIT25 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT25(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT25_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT25_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT26_MASK  (0x4000000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT26_SHIFT (26U)
/*! BIT26 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT26(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT26_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT26_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT27_MASK  (0x8000000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT27_SHIFT (27U)
/*! BIT27 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT27(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT27_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT27_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT28_MASK  (0x10000000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT28_SHIFT (28U)
/*! BIT28 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT28(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT28_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT28_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT29_MASK  (0x20000000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT29_SHIFT (29U)
/*! BIT29 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT29(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT29_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT29_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT30_MASK  (0x40000000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT30_SHIFT (30U)
/*! BIT30 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT30(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT30_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT30_MASK)

#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT31_MASK  (0x80000000U)
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT31_SHIFT (31U)
/*! BIT31 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT31(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT31_SHIFT)) & TRDC_MBC_DOM0_MEM1_BLK_NSE_W_BIT31_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM0_MEM1_BLK_NSE_W */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM0_MEM1_BLK_NSE_W */
#define TRDC_MBC_DOM0_MEM1_BLK_NSE_W_COUNT2      (1U)

/*! @name MBC_DOM0_MEM2_BLK_CFG_W - MBC Memory Block Configuration Word */
/*! @{ */

#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL0_MASK (0x7U)
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL0_SHIFT (0U)
/*! MBACSEL0 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL0_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL0_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE0_MASK   (0x8U)
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE0_SHIFT  (3U)
/*! NSE0 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE0_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE0_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL1_MASK (0x70U)
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL1_SHIFT (4U)
/*! MBACSEL1 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL1_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL1_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE1_MASK   (0x80U)
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE1_SHIFT  (7U)
/*! NSE1 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE1_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE1_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL2_MASK (0x700U)
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL2_SHIFT (8U)
/*! MBACSEL2 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL2_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL2_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE2_MASK   (0x800U)
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE2_SHIFT  (11U)
/*! NSE2 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE2_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE2_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL3_MASK (0x7000U)
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL3_SHIFT (12U)
/*! MBACSEL3 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL3_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL3_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE3_MASK   (0x8000U)
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE3_SHIFT  (15U)
/*! NSE3 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE3_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE3_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL4_MASK (0x70000U)
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL4_SHIFT (16U)
/*! MBACSEL4 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL4_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL4_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE4_MASK   (0x80000U)
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE4_SHIFT  (19U)
/*! NSE4 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE4_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE4_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL5_MASK (0x700000U)
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL5_SHIFT (20U)
/*! MBACSEL5 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL5_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL5_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE5_MASK   (0x800000U)
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE5_SHIFT  (23U)
/*! NSE5 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE5_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE5_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL6_MASK (0x7000000U)
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL6_SHIFT (24U)
/*! MBACSEL6 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL6_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL6_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE6_MASK   (0x8000000U)
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE6_SHIFT  (27U)
/*! NSE6 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE6_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE6_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL7_MASK (0x70000000U)
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL7_SHIFT (28U)
/*! MBACSEL7 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL7_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL7_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE7_MASK   (0x80000000U)
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE7_SHIFT  (31U)
/*! NSE7 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE7_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_CFG_W_NSE7_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM0_MEM2_BLK_CFG_W */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM0_MEM2_BLK_CFG_W */
#define TRDC_MBC_DOM0_MEM2_BLK_CFG_W_COUNT2      (2U)

/*! @name MBC_DOM0_MEM2_BLK_NSE_W - MBC Memory Block NonSecure Enable Word */
/*! @{ */

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT0_MASK   (0x1U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT0_SHIFT  (0U)
/*! BIT0 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT0_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT0_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT1_MASK   (0x2U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT1_SHIFT  (1U)
/*! BIT1 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT1_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT1_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT2_MASK   (0x4U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT2_SHIFT  (2U)
/*! BIT2 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT2_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT2_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT3_MASK   (0x8U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT3_SHIFT  (3U)
/*! BIT3 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT3_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT3_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT4_MASK   (0x10U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT4_SHIFT  (4U)
/*! BIT4 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT4_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT4_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT5_MASK   (0x20U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT5_SHIFT  (5U)
/*! BIT5 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT5_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT5_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT6_MASK   (0x40U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT6_SHIFT  (6U)
/*! BIT6 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT6_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT6_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT7_MASK   (0x80U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT7_SHIFT  (7U)
/*! BIT7 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT7_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT7_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT8_MASK   (0x100U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT8_SHIFT  (8U)
/*! BIT8 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT8(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT8_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT8_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT9_MASK   (0x200U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT9_SHIFT  (9U)
/*! BIT9 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT9(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT9_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT9_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT10_MASK  (0x400U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT10_SHIFT (10U)
/*! BIT10 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT10(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT10_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT10_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT11_MASK  (0x800U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT11_SHIFT (11U)
/*! BIT11 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT11(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT11_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT11_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT12_MASK  (0x1000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT12_SHIFT (12U)
/*! BIT12 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT12(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT12_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT12_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT13_MASK  (0x2000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT13_SHIFT (13U)
/*! BIT13 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT13(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT13_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT13_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT14_MASK  (0x4000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT14_SHIFT (14U)
/*! BIT14 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT14(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT14_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT14_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT15_MASK  (0x8000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT15_SHIFT (15U)
/*! BIT15 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT15(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT15_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT15_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT16_MASK  (0x10000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT16_SHIFT (16U)
/*! BIT16 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT16(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT16_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT16_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT17_MASK  (0x20000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT17_SHIFT (17U)
/*! BIT17 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT17(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT17_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT17_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT18_MASK  (0x40000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT18_SHIFT (18U)
/*! BIT18 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT18(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT18_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT18_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT19_MASK  (0x80000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT19_SHIFT (19U)
/*! BIT19 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT19(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT19_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT19_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT20_MASK  (0x100000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT20_SHIFT (20U)
/*! BIT20 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT20(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT20_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT20_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT21_MASK  (0x200000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT21_SHIFT (21U)
/*! BIT21 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT21(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT21_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT21_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT22_MASK  (0x400000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT22_SHIFT (22U)
/*! BIT22 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT22(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT22_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT22_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT23_MASK  (0x800000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT23_SHIFT (23U)
/*! BIT23 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT23(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT23_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT23_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT24_MASK  (0x1000000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT24_SHIFT (24U)
/*! BIT24 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT24(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT24_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT24_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT25_MASK  (0x2000000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT25_SHIFT (25U)
/*! BIT25 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT25(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT25_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT25_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT26_MASK  (0x4000000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT26_SHIFT (26U)
/*! BIT26 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT26(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT26_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT26_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT27_MASK  (0x8000000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT27_SHIFT (27U)
/*! BIT27 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT27(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT27_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT27_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT28_MASK  (0x10000000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT28_SHIFT (28U)
/*! BIT28 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT28(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT28_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT28_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT29_MASK  (0x20000000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT29_SHIFT (29U)
/*! BIT29 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT29(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT29_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT29_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT30_MASK  (0x40000000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT30_SHIFT (30U)
/*! BIT30 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT30(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT30_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT30_MASK)

#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT31_MASK  (0x80000000U)
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT31_SHIFT (31U)
/*! BIT31 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT31(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT31_SHIFT)) & TRDC_MBC_DOM0_MEM2_BLK_NSE_W_BIT31_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM0_MEM2_BLK_NSE_W */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM0_MEM2_BLK_NSE_W */
#define TRDC_MBC_DOM0_MEM2_BLK_NSE_W_COUNT2      (1U)

/*! @name MBC_DOM0_MEM3_BLK_CFG_W - MBC Memory Block Configuration Word */
/*! @{ */

#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL0_MASK (0x7U)
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL0_SHIFT (0U)
/*! MBACSEL0 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL0_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL0_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE0_MASK   (0x8U)
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE0_SHIFT  (3U)
/*! NSE0 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE0_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE0_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL1_MASK (0x70U)
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL1_SHIFT (4U)
/*! MBACSEL1 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL1_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL1_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE1_MASK   (0x80U)
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE1_SHIFT  (7U)
/*! NSE1 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE1_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE1_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL2_MASK (0x700U)
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL2_SHIFT (8U)
/*! MBACSEL2 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL2_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL2_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE2_MASK   (0x800U)
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE2_SHIFT  (11U)
/*! NSE2 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE2_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE2_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL3_MASK (0x7000U)
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL3_SHIFT (12U)
/*! MBACSEL3 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL3_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL3_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE3_MASK   (0x8000U)
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE3_SHIFT  (15U)
/*! NSE3 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE3_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE3_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL4_MASK (0x70000U)
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL4_SHIFT (16U)
/*! MBACSEL4 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL4_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL4_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE4_MASK   (0x80000U)
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE4_SHIFT  (19U)
/*! NSE4 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE4_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE4_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL5_MASK (0x700000U)
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL5_SHIFT (20U)
/*! MBACSEL5 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL5_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL5_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE5_MASK   (0x800000U)
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE5_SHIFT  (23U)
/*! NSE5 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE5_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE5_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL6_MASK (0x7000000U)
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL6_SHIFT (24U)
/*! MBACSEL6 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL6_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL6_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE6_MASK   (0x8000000U)
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE6_SHIFT  (27U)
/*! NSE6 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE6_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE6_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL7_MASK (0x70000000U)
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL7_SHIFT (28U)
/*! MBACSEL7 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL7_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_CFG_W_MBACSEL7_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE7_MASK   (0x80000000U)
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE7_SHIFT  (31U)
/*! NSE7 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE7_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_CFG_W_NSE7_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM0_MEM3_BLK_CFG_W */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM0_MEM3_BLK_CFG_W */
#define TRDC_MBC_DOM0_MEM3_BLK_CFG_W_COUNT2      (2U)

/*! @name MBC_DOM0_MEM3_BLK_NSE_W - MBC Memory Block NonSecure Enable Word */
/*! @{ */

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT0_MASK   (0x1U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT0_SHIFT  (0U)
/*! BIT0 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT0_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT0_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT1_MASK   (0x2U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT1_SHIFT  (1U)
/*! BIT1 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT1_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT1_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT2_MASK   (0x4U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT2_SHIFT  (2U)
/*! BIT2 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT2_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT2_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT3_MASK   (0x8U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT3_SHIFT  (3U)
/*! BIT3 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT3_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT3_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT4_MASK   (0x10U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT4_SHIFT  (4U)
/*! BIT4 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT4_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT4_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT5_MASK   (0x20U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT5_SHIFT  (5U)
/*! BIT5 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT5_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT5_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT6_MASK   (0x40U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT6_SHIFT  (6U)
/*! BIT6 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT6_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT6_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT7_MASK   (0x80U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT7_SHIFT  (7U)
/*! BIT7 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT7_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT7_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT8_MASK   (0x100U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT8_SHIFT  (8U)
/*! BIT8 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT8(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT8_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT8_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT9_MASK   (0x200U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT9_SHIFT  (9U)
/*! BIT9 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT9(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT9_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT9_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT10_MASK  (0x400U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT10_SHIFT (10U)
/*! BIT10 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT10(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT10_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT10_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT11_MASK  (0x800U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT11_SHIFT (11U)
/*! BIT11 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT11(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT11_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT11_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT12_MASK  (0x1000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT12_SHIFT (12U)
/*! BIT12 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT12(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT12_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT12_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT13_MASK  (0x2000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT13_SHIFT (13U)
/*! BIT13 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT13(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT13_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT13_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT14_MASK  (0x4000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT14_SHIFT (14U)
/*! BIT14 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT14(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT14_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT14_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT15_MASK  (0x8000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT15_SHIFT (15U)
/*! BIT15 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT15(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT15_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT15_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT16_MASK  (0x10000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT16_SHIFT (16U)
/*! BIT16 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT16(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT16_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT16_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT17_MASK  (0x20000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT17_SHIFT (17U)
/*! BIT17 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT17(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT17_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT17_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT18_MASK  (0x40000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT18_SHIFT (18U)
/*! BIT18 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT18(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT18_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT18_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT19_MASK  (0x80000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT19_SHIFT (19U)
/*! BIT19 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT19(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT19_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT19_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT20_MASK  (0x100000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT20_SHIFT (20U)
/*! BIT20 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT20(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT20_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT20_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT21_MASK  (0x200000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT21_SHIFT (21U)
/*! BIT21 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT21(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT21_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT21_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT22_MASK  (0x400000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT22_SHIFT (22U)
/*! BIT22 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT22(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT22_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT22_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT23_MASK  (0x800000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT23_SHIFT (23U)
/*! BIT23 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT23(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT23_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT23_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT24_MASK  (0x1000000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT24_SHIFT (24U)
/*! BIT24 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT24(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT24_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT24_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT25_MASK  (0x2000000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT25_SHIFT (25U)
/*! BIT25 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT25(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT25_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT25_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT26_MASK  (0x4000000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT26_SHIFT (26U)
/*! BIT26 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT26(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT26_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT26_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT27_MASK  (0x8000000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT27_SHIFT (27U)
/*! BIT27 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT27(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT27_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT27_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT28_MASK  (0x10000000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT28_SHIFT (28U)
/*! BIT28 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT28(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT28_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT28_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT29_MASK  (0x20000000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT29_SHIFT (29U)
/*! BIT29 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT29(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT29_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT29_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT30_MASK  (0x40000000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT30_SHIFT (30U)
/*! BIT30 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT30(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT30_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT30_MASK)

#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT31_MASK  (0x80000000U)
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT31_SHIFT (31U)
/*! BIT31 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT31(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT31_SHIFT)) & TRDC_MBC_DOM0_MEM3_BLK_NSE_W_BIT31_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM0_MEM3_BLK_NSE_W */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM0_MEM3_BLK_NSE_W */
#define TRDC_MBC_DOM0_MEM3_BLK_NSE_W_COUNT2      (1U)

/*! @name MBC_DOM1_MEM0_BLK_CFG_W - MBC Memory Block Configuration Word */
/*! @{ */

#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL0_MASK (0x7U)
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL0_SHIFT (0U)
/*! MBACSEL0 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL0_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL0_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE0_MASK   (0x8U)
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE0_SHIFT  (3U)
/*! NSE0 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE0_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE0_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL1_MASK (0x70U)
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL1_SHIFT (4U)
/*! MBACSEL1 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL1_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL1_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE1_MASK   (0x80U)
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE1_SHIFT  (7U)
/*! NSE1 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE1_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE1_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL2_MASK (0x700U)
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL2_SHIFT (8U)
/*! MBACSEL2 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL2_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL2_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE2_MASK   (0x800U)
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE2_SHIFT  (11U)
/*! NSE2 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE2_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE2_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL3_MASK (0x7000U)
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL3_SHIFT (12U)
/*! MBACSEL3 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL3_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL3_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE3_MASK   (0x8000U)
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE3_SHIFT  (15U)
/*! NSE3 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE3_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE3_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL4_MASK (0x70000U)
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL4_SHIFT (16U)
/*! MBACSEL4 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL4_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL4_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE4_MASK   (0x80000U)
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE4_SHIFT  (19U)
/*! NSE4 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE4_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE4_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL5_MASK (0x700000U)
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL5_SHIFT (20U)
/*! MBACSEL5 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL5_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL5_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE5_MASK   (0x800000U)
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE5_SHIFT  (23U)
/*! NSE5 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE5_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE5_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL6_MASK (0x7000000U)
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL6_SHIFT (24U)
/*! MBACSEL6 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL6_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL6_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE6_MASK   (0x8000000U)
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE6_SHIFT  (27U)
/*! NSE6 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE6_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE6_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL7_MASK (0x70000000U)
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL7_SHIFT (28U)
/*! MBACSEL7 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL7_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_CFG_W_MBACSEL7_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE7_MASK   (0x80000000U)
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE7_SHIFT  (31U)
/*! NSE7 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE7_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_CFG_W_NSE7_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM1_MEM0_BLK_CFG_W */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM1_MEM0_BLK_CFG_W */
#define TRDC_MBC_DOM1_MEM0_BLK_CFG_W_COUNT2      (10U)

/*! @name MBC_DOM1_MEM0_BLK_NSE_W - MBC Memory Block NonSecure Enable Word */
/*! @{ */

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT0_MASK   (0x1U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT0_SHIFT  (0U)
/*! BIT0 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT0_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT0_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT1_MASK   (0x2U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT1_SHIFT  (1U)
/*! BIT1 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT1_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT1_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT2_MASK   (0x4U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT2_SHIFT  (2U)
/*! BIT2 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT2_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT2_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT3_MASK   (0x8U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT3_SHIFT  (3U)
/*! BIT3 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT3_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT3_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT4_MASK   (0x10U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT4_SHIFT  (4U)
/*! BIT4 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT4_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT4_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT5_MASK   (0x20U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT5_SHIFT  (5U)
/*! BIT5 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT5_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT5_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT6_MASK   (0x40U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT6_SHIFT  (6U)
/*! BIT6 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT6_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT6_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT7_MASK   (0x80U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT7_SHIFT  (7U)
/*! BIT7 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT7_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT7_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT8_MASK   (0x100U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT8_SHIFT  (8U)
/*! BIT8 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT8(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT8_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT8_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT9_MASK   (0x200U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT9_SHIFT  (9U)
/*! BIT9 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT9(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT9_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT9_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT10_MASK  (0x400U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT10_SHIFT (10U)
/*! BIT10 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT10(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT10_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT10_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT11_MASK  (0x800U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT11_SHIFT (11U)
/*! BIT11 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT11(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT11_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT11_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT12_MASK  (0x1000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT12_SHIFT (12U)
/*! BIT12 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT12(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT12_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT12_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT13_MASK  (0x2000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT13_SHIFT (13U)
/*! BIT13 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT13(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT13_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT13_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT14_MASK  (0x4000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT14_SHIFT (14U)
/*! BIT14 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT14(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT14_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT14_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT15_MASK  (0x8000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT15_SHIFT (15U)
/*! BIT15 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT15(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT15_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT15_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT16_MASK  (0x10000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT16_SHIFT (16U)
/*! BIT16 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT16(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT16_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT16_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT17_MASK  (0x20000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT17_SHIFT (17U)
/*! BIT17 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT17(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT17_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT17_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT18_MASK  (0x40000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT18_SHIFT (18U)
/*! BIT18 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT18(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT18_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT18_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT19_MASK  (0x80000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT19_SHIFT (19U)
/*! BIT19 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT19(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT19_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT19_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT20_MASK  (0x100000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT20_SHIFT (20U)
/*! BIT20 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT20(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT20_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT20_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT21_MASK  (0x200000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT21_SHIFT (21U)
/*! BIT21 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT21(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT21_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT21_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT22_MASK  (0x400000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT22_SHIFT (22U)
/*! BIT22 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT22(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT22_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT22_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT23_MASK  (0x800000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT23_SHIFT (23U)
/*! BIT23 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT23(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT23_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT23_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT24_MASK  (0x1000000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT24_SHIFT (24U)
/*! BIT24 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT24(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT24_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT24_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT25_MASK  (0x2000000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT25_SHIFT (25U)
/*! BIT25 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT25(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT25_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT25_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT26_MASK  (0x4000000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT26_SHIFT (26U)
/*! BIT26 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT26(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT26_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT26_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT27_MASK  (0x8000000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT27_SHIFT (27U)
/*! BIT27 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT27(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT27_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT27_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT28_MASK  (0x10000000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT28_SHIFT (28U)
/*! BIT28 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT28(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT28_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT28_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT29_MASK  (0x20000000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT29_SHIFT (29U)
/*! BIT29 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT29(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT29_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT29_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT30_MASK  (0x40000000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT30_SHIFT (30U)
/*! BIT30 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT30(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT30_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT30_MASK)

#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT31_MASK  (0x80000000U)
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT31_SHIFT (31U)
/*! BIT31 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT31(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT31_SHIFT)) & TRDC_MBC_DOM1_MEM0_BLK_NSE_W_BIT31_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM1_MEM0_BLK_NSE_W */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM1_MEM0_BLK_NSE_W */
#define TRDC_MBC_DOM1_MEM0_BLK_NSE_W_COUNT2      (3U)

/*! @name MBC_DOM1_MEM1_BLK_CFG_W - MBC Memory Block Configuration Word */
/*! @{ */

#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL0_MASK (0x7U)
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL0_SHIFT (0U)
/*! MBACSEL0 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL0_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL0_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE0_MASK   (0x8U)
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE0_SHIFT  (3U)
/*! NSE0 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE0_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE0_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL1_MASK (0x70U)
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL1_SHIFT (4U)
/*! MBACSEL1 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL1_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL1_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE1_MASK   (0x80U)
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE1_SHIFT  (7U)
/*! NSE1 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE1_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE1_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL2_MASK (0x700U)
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL2_SHIFT (8U)
/*! MBACSEL2 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL2_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL2_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE2_MASK   (0x800U)
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE2_SHIFT  (11U)
/*! NSE2 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE2_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE2_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL3_MASK (0x7000U)
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL3_SHIFT (12U)
/*! MBACSEL3 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL3_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL3_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE3_MASK   (0x8000U)
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE3_SHIFT  (15U)
/*! NSE3 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE3_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE3_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL4_MASK (0x70000U)
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL4_SHIFT (16U)
/*! MBACSEL4 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL4_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL4_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE4_MASK   (0x80000U)
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE4_SHIFT  (19U)
/*! NSE4 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE4_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE4_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL5_MASK (0x700000U)
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL5_SHIFT (20U)
/*! MBACSEL5 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL5_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL5_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE5_MASK   (0x800000U)
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE5_SHIFT  (23U)
/*! NSE5 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE5_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE5_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL6_MASK (0x7000000U)
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL6_SHIFT (24U)
/*! MBACSEL6 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL6_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL6_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE6_MASK   (0x8000000U)
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE6_SHIFT  (27U)
/*! NSE6 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE6_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE6_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL7_MASK (0x70000000U)
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL7_SHIFT (28U)
/*! MBACSEL7 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL7_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_CFG_W_MBACSEL7_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE7_MASK   (0x80000000U)
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE7_SHIFT  (31U)
/*! NSE7 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE7_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_CFG_W_NSE7_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM1_MEM1_BLK_CFG_W */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM1_MEM1_BLK_CFG_W */
#define TRDC_MBC_DOM1_MEM1_BLK_CFG_W_COUNT2      (1U)

/*! @name MBC_DOM1_MEM1_BLK_NSE_W - MBC Memory Block NonSecure Enable Word */
/*! @{ */

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT0_MASK   (0x1U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT0_SHIFT  (0U)
/*! BIT0 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT0_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT0_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT1_MASK   (0x2U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT1_SHIFT  (1U)
/*! BIT1 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT1_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT1_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT2_MASK   (0x4U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT2_SHIFT  (2U)
/*! BIT2 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT2_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT2_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT3_MASK   (0x8U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT3_SHIFT  (3U)
/*! BIT3 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT3_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT3_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT4_MASK   (0x10U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT4_SHIFT  (4U)
/*! BIT4 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT4_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT4_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT5_MASK   (0x20U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT5_SHIFT  (5U)
/*! BIT5 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT5_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT5_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT6_MASK   (0x40U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT6_SHIFT  (6U)
/*! BIT6 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT6_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT6_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT7_MASK   (0x80U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT7_SHIFT  (7U)
/*! BIT7 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT7_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT7_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT8_MASK   (0x100U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT8_SHIFT  (8U)
/*! BIT8 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT8(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT8_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT8_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT9_MASK   (0x200U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT9_SHIFT  (9U)
/*! BIT9 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT9(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT9_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT9_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT10_MASK  (0x400U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT10_SHIFT (10U)
/*! BIT10 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT10(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT10_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT10_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT11_MASK  (0x800U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT11_SHIFT (11U)
/*! BIT11 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT11(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT11_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT11_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT12_MASK  (0x1000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT12_SHIFT (12U)
/*! BIT12 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT12(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT12_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT12_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT13_MASK  (0x2000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT13_SHIFT (13U)
/*! BIT13 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT13(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT13_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT13_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT14_MASK  (0x4000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT14_SHIFT (14U)
/*! BIT14 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT14(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT14_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT14_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT15_MASK  (0x8000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT15_SHIFT (15U)
/*! BIT15 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT15(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT15_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT15_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT16_MASK  (0x10000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT16_SHIFT (16U)
/*! BIT16 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT16(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT16_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT16_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT17_MASK  (0x20000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT17_SHIFT (17U)
/*! BIT17 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT17(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT17_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT17_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT18_MASK  (0x40000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT18_SHIFT (18U)
/*! BIT18 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT18(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT18_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT18_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT19_MASK  (0x80000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT19_SHIFT (19U)
/*! BIT19 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT19(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT19_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT19_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT20_MASK  (0x100000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT20_SHIFT (20U)
/*! BIT20 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT20(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT20_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT20_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT21_MASK  (0x200000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT21_SHIFT (21U)
/*! BIT21 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT21(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT21_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT21_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT22_MASK  (0x400000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT22_SHIFT (22U)
/*! BIT22 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT22(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT22_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT22_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT23_MASK  (0x800000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT23_SHIFT (23U)
/*! BIT23 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT23(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT23_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT23_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT24_MASK  (0x1000000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT24_SHIFT (24U)
/*! BIT24 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT24(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT24_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT24_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT25_MASK  (0x2000000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT25_SHIFT (25U)
/*! BIT25 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT25(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT25_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT25_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT26_MASK  (0x4000000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT26_SHIFT (26U)
/*! BIT26 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT26(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT26_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT26_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT27_MASK  (0x8000000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT27_SHIFT (27U)
/*! BIT27 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT27(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT27_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT27_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT28_MASK  (0x10000000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT28_SHIFT (28U)
/*! BIT28 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT28(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT28_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT28_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT29_MASK  (0x20000000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT29_SHIFT (29U)
/*! BIT29 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT29(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT29_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT29_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT30_MASK  (0x40000000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT30_SHIFT (30U)
/*! BIT30 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT30(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT30_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT30_MASK)

#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT31_MASK  (0x80000000U)
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT31_SHIFT (31U)
/*! BIT31 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT31(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT31_SHIFT)) & TRDC_MBC_DOM1_MEM1_BLK_NSE_W_BIT31_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM1_MEM1_BLK_NSE_W */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM1_MEM1_BLK_NSE_W */
#define TRDC_MBC_DOM1_MEM1_BLK_NSE_W_COUNT2      (1U)

/*! @name MBC_DOM1_MEM2_BLK_CFG_W - MBC Memory Block Configuration Word */
/*! @{ */

#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL0_MASK (0x7U)
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL0_SHIFT (0U)
/*! MBACSEL0 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL0_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL0_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE0_MASK   (0x8U)
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE0_SHIFT  (3U)
/*! NSE0 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE0_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE0_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL1_MASK (0x70U)
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL1_SHIFT (4U)
/*! MBACSEL1 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL1_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL1_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE1_MASK   (0x80U)
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE1_SHIFT  (7U)
/*! NSE1 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE1_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE1_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL2_MASK (0x700U)
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL2_SHIFT (8U)
/*! MBACSEL2 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL2_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL2_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE2_MASK   (0x800U)
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE2_SHIFT  (11U)
/*! NSE2 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE2_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE2_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL3_MASK (0x7000U)
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL3_SHIFT (12U)
/*! MBACSEL3 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL3_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL3_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE3_MASK   (0x8000U)
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE3_SHIFT  (15U)
/*! NSE3 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE3_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE3_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL4_MASK (0x70000U)
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL4_SHIFT (16U)
/*! MBACSEL4 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL4_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL4_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE4_MASK   (0x80000U)
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE4_SHIFT  (19U)
/*! NSE4 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE4_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE4_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL5_MASK (0x700000U)
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL5_SHIFT (20U)
/*! MBACSEL5 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL5_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL5_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE5_MASK   (0x800000U)
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE5_SHIFT  (23U)
/*! NSE5 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE5_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE5_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL6_MASK (0x7000000U)
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL6_SHIFT (24U)
/*! MBACSEL6 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL6_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL6_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE6_MASK   (0x8000000U)
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE6_SHIFT  (27U)
/*! NSE6 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE6_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE6_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL7_MASK (0x70000000U)
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL7_SHIFT (28U)
/*! MBACSEL7 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL7_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_CFG_W_MBACSEL7_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE7_MASK   (0x80000000U)
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE7_SHIFT  (31U)
/*! NSE7 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE7_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_CFG_W_NSE7_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM1_MEM2_BLK_CFG_W */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM1_MEM2_BLK_CFG_W */
#define TRDC_MBC_DOM1_MEM2_BLK_CFG_W_COUNT2      (2U)

/*! @name MBC_DOM1_MEM2_BLK_NSE_W - MBC Memory Block NonSecure Enable Word */
/*! @{ */

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT0_MASK   (0x1U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT0_SHIFT  (0U)
/*! BIT0 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT0_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT0_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT1_MASK   (0x2U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT1_SHIFT  (1U)
/*! BIT1 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT1_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT1_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT2_MASK   (0x4U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT2_SHIFT  (2U)
/*! BIT2 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT2_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT2_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT3_MASK   (0x8U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT3_SHIFT  (3U)
/*! BIT3 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT3_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT3_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT4_MASK   (0x10U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT4_SHIFT  (4U)
/*! BIT4 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT4_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT4_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT5_MASK   (0x20U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT5_SHIFT  (5U)
/*! BIT5 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT5_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT5_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT6_MASK   (0x40U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT6_SHIFT  (6U)
/*! BIT6 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT6_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT6_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT7_MASK   (0x80U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT7_SHIFT  (7U)
/*! BIT7 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT7_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT7_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT8_MASK   (0x100U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT8_SHIFT  (8U)
/*! BIT8 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT8(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT8_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT8_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT9_MASK   (0x200U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT9_SHIFT  (9U)
/*! BIT9 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT9(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT9_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT9_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT10_MASK  (0x400U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT10_SHIFT (10U)
/*! BIT10 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT10(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT10_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT10_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT11_MASK  (0x800U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT11_SHIFT (11U)
/*! BIT11 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT11(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT11_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT11_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT12_MASK  (0x1000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT12_SHIFT (12U)
/*! BIT12 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT12(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT12_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT12_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT13_MASK  (0x2000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT13_SHIFT (13U)
/*! BIT13 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT13(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT13_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT13_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT14_MASK  (0x4000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT14_SHIFT (14U)
/*! BIT14 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT14(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT14_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT14_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT15_MASK  (0x8000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT15_SHIFT (15U)
/*! BIT15 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT15(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT15_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT15_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT16_MASK  (0x10000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT16_SHIFT (16U)
/*! BIT16 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT16(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT16_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT16_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT17_MASK  (0x20000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT17_SHIFT (17U)
/*! BIT17 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT17(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT17_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT17_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT18_MASK  (0x40000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT18_SHIFT (18U)
/*! BIT18 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT18(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT18_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT18_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT19_MASK  (0x80000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT19_SHIFT (19U)
/*! BIT19 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT19(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT19_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT19_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT20_MASK  (0x100000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT20_SHIFT (20U)
/*! BIT20 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT20(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT20_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT20_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT21_MASK  (0x200000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT21_SHIFT (21U)
/*! BIT21 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT21(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT21_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT21_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT22_MASK  (0x400000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT22_SHIFT (22U)
/*! BIT22 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT22(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT22_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT22_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT23_MASK  (0x800000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT23_SHIFT (23U)
/*! BIT23 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT23(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT23_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT23_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT24_MASK  (0x1000000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT24_SHIFT (24U)
/*! BIT24 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT24(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT24_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT24_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT25_MASK  (0x2000000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT25_SHIFT (25U)
/*! BIT25 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT25(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT25_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT25_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT26_MASK  (0x4000000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT26_SHIFT (26U)
/*! BIT26 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT26(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT26_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT26_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT27_MASK  (0x8000000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT27_SHIFT (27U)
/*! BIT27 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT27(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT27_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT27_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT28_MASK  (0x10000000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT28_SHIFT (28U)
/*! BIT28 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT28(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT28_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT28_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT29_MASK  (0x20000000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT29_SHIFT (29U)
/*! BIT29 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT29(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT29_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT29_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT30_MASK  (0x40000000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT30_SHIFT (30U)
/*! BIT30 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT30(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT30_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT30_MASK)

#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT31_MASK  (0x80000000U)
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT31_SHIFT (31U)
/*! BIT31 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT31(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT31_SHIFT)) & TRDC_MBC_DOM1_MEM2_BLK_NSE_W_BIT31_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM1_MEM2_BLK_NSE_W */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM1_MEM2_BLK_NSE_W */
#define TRDC_MBC_DOM1_MEM2_BLK_NSE_W_COUNT2      (1U)

/*! @name MBC_DOM1_MEM3_BLK_CFG_W - MBC Memory Block Configuration Word */
/*! @{ */

#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL0_MASK (0x7U)
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL0_SHIFT (0U)
/*! MBACSEL0 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL0_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL0_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE0_MASK   (0x8U)
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE0_SHIFT  (3U)
/*! NSE0 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE0_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE0_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL1_MASK (0x70U)
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL1_SHIFT (4U)
/*! MBACSEL1 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL1_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL1_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE1_MASK   (0x80U)
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE1_SHIFT  (7U)
/*! NSE1 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE1_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE1_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL2_MASK (0x700U)
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL2_SHIFT (8U)
/*! MBACSEL2 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL2_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL2_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE2_MASK   (0x800U)
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE2_SHIFT  (11U)
/*! NSE2 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE2_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE2_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL3_MASK (0x7000U)
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL3_SHIFT (12U)
/*! MBACSEL3 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL3_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL3_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE3_MASK   (0x8000U)
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE3_SHIFT  (15U)
/*! NSE3 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE3_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE3_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL4_MASK (0x70000U)
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL4_SHIFT (16U)
/*! MBACSEL4 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL4_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL4_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE4_MASK   (0x80000U)
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE4_SHIFT  (19U)
/*! NSE4 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE4_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE4_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL5_MASK (0x700000U)
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL5_SHIFT (20U)
/*! MBACSEL5 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL5_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL5_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE5_MASK   (0x800000U)
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE5_SHIFT  (23U)
/*! NSE5 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE5_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE5_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL6_MASK (0x7000000U)
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL6_SHIFT (24U)
/*! MBACSEL6 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL6_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL6_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE6_MASK   (0x8000000U)
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE6_SHIFT  (27U)
/*! NSE6 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE6_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE6_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL7_MASK (0x70000000U)
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL7_SHIFT (28U)
/*! MBACSEL7 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL7_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_CFG_W_MBACSEL7_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE7_MASK   (0x80000000U)
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE7_SHIFT  (31U)
/*! NSE7 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE7_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_CFG_W_NSE7_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM1_MEM3_BLK_CFG_W */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM1_MEM3_BLK_CFG_W */
#define TRDC_MBC_DOM1_MEM3_BLK_CFG_W_COUNT2      (2U)

/*! @name MBC_DOM1_MEM3_BLK_NSE_W - MBC Memory Block NonSecure Enable Word */
/*! @{ */

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT0_MASK   (0x1U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT0_SHIFT  (0U)
/*! BIT0 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT0_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT0_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT1_MASK   (0x2U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT1_SHIFT  (1U)
/*! BIT1 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT1_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT1_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT2_MASK   (0x4U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT2_SHIFT  (2U)
/*! BIT2 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT2_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT2_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT3_MASK   (0x8U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT3_SHIFT  (3U)
/*! BIT3 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT3_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT3_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT4_MASK   (0x10U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT4_SHIFT  (4U)
/*! BIT4 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT4_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT4_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT5_MASK   (0x20U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT5_SHIFT  (5U)
/*! BIT5 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT5_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT5_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT6_MASK   (0x40U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT6_SHIFT  (6U)
/*! BIT6 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT6_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT6_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT7_MASK   (0x80U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT7_SHIFT  (7U)
/*! BIT7 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT7_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT7_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT8_MASK   (0x100U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT8_SHIFT  (8U)
/*! BIT8 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT8(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT8_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT8_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT9_MASK   (0x200U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT9_SHIFT  (9U)
/*! BIT9 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT9(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT9_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT9_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT10_MASK  (0x400U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT10_SHIFT (10U)
/*! BIT10 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT10(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT10_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT10_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT11_MASK  (0x800U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT11_SHIFT (11U)
/*! BIT11 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT11(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT11_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT11_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT12_MASK  (0x1000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT12_SHIFT (12U)
/*! BIT12 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT12(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT12_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT12_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT13_MASK  (0x2000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT13_SHIFT (13U)
/*! BIT13 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT13(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT13_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT13_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT14_MASK  (0x4000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT14_SHIFT (14U)
/*! BIT14 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT14(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT14_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT14_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT15_MASK  (0x8000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT15_SHIFT (15U)
/*! BIT15 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT15(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT15_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT15_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT16_MASK  (0x10000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT16_SHIFT (16U)
/*! BIT16 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT16(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT16_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT16_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT17_MASK  (0x20000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT17_SHIFT (17U)
/*! BIT17 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT17(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT17_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT17_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT18_MASK  (0x40000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT18_SHIFT (18U)
/*! BIT18 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT18(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT18_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT18_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT19_MASK  (0x80000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT19_SHIFT (19U)
/*! BIT19 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT19(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT19_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT19_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT20_MASK  (0x100000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT20_SHIFT (20U)
/*! BIT20 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT20(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT20_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT20_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT21_MASK  (0x200000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT21_SHIFT (21U)
/*! BIT21 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT21(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT21_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT21_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT22_MASK  (0x400000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT22_SHIFT (22U)
/*! BIT22 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT22(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT22_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT22_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT23_MASK  (0x800000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT23_SHIFT (23U)
/*! BIT23 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT23(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT23_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT23_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT24_MASK  (0x1000000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT24_SHIFT (24U)
/*! BIT24 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT24(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT24_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT24_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT25_MASK  (0x2000000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT25_SHIFT (25U)
/*! BIT25 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT25(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT25_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT25_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT26_MASK  (0x4000000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT26_SHIFT (26U)
/*! BIT26 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT26(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT26_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT26_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT27_MASK  (0x8000000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT27_SHIFT (27U)
/*! BIT27 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT27(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT27_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT27_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT28_MASK  (0x10000000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT28_SHIFT (28U)
/*! BIT28 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT28(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT28_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT28_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT29_MASK  (0x20000000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT29_SHIFT (29U)
/*! BIT29 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT29(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT29_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT29_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT30_MASK  (0x40000000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT30_SHIFT (30U)
/*! BIT30 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT30(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT30_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT30_MASK)

#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT31_MASK  (0x80000000U)
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT31_SHIFT (31U)
/*! BIT31 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT31(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT31_SHIFT)) & TRDC_MBC_DOM1_MEM3_BLK_NSE_W_BIT31_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM1_MEM3_BLK_NSE_W */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM1_MEM3_BLK_NSE_W */
#define TRDC_MBC_DOM1_MEM3_BLK_NSE_W_COUNT2      (1U)

/*! @name MBC_DOM2_MEM0_BLK_CFG_W - MBC Memory Block Configuration Word */
/*! @{ */

#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL0_MASK (0x7U)
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL0_SHIFT (0U)
/*! MBACSEL0 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL0_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL0_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE0_MASK   (0x8U)
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE0_SHIFT  (3U)
/*! NSE0 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE0_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE0_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL1_MASK (0x70U)
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL1_SHIFT (4U)
/*! MBACSEL1 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL1_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL1_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE1_MASK   (0x80U)
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE1_SHIFT  (7U)
/*! NSE1 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE1_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE1_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL2_MASK (0x700U)
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL2_SHIFT (8U)
/*! MBACSEL2 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL2_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL2_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE2_MASK   (0x800U)
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE2_SHIFT  (11U)
/*! NSE2 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE2_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE2_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL3_MASK (0x7000U)
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL3_SHIFT (12U)
/*! MBACSEL3 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL3_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL3_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE3_MASK   (0x8000U)
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE3_SHIFT  (15U)
/*! NSE3 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE3_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE3_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL4_MASK (0x70000U)
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL4_SHIFT (16U)
/*! MBACSEL4 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL4_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL4_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE4_MASK   (0x80000U)
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE4_SHIFT  (19U)
/*! NSE4 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE4_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE4_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL5_MASK (0x700000U)
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL5_SHIFT (20U)
/*! MBACSEL5 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL5_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL5_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE5_MASK   (0x800000U)
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE5_SHIFT  (23U)
/*! NSE5 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE5_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE5_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL6_MASK (0x7000000U)
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL6_SHIFT (24U)
/*! MBACSEL6 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL6_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL6_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE6_MASK   (0x8000000U)
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE6_SHIFT  (27U)
/*! NSE6 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE6_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE6_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL7_MASK (0x70000000U)
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL7_SHIFT (28U)
/*! MBACSEL7 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL7_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_CFG_W_MBACSEL7_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE7_MASK   (0x80000000U)
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE7_SHIFT  (31U)
/*! NSE7 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE7_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_CFG_W_NSE7_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM2_MEM0_BLK_CFG_W */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM2_MEM0_BLK_CFG_W */
#define TRDC_MBC_DOM2_MEM0_BLK_CFG_W_COUNT2      (10U)

/*! @name MBC_DOM2_MEM0_BLK_NSE_W - MBC Memory Block NonSecure Enable Word */
/*! @{ */

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT0_MASK   (0x1U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT0_SHIFT  (0U)
/*! BIT0 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT0_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT0_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT1_MASK   (0x2U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT1_SHIFT  (1U)
/*! BIT1 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT1_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT1_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT2_MASK   (0x4U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT2_SHIFT  (2U)
/*! BIT2 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT2_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT2_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT3_MASK   (0x8U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT3_SHIFT  (3U)
/*! BIT3 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT3_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT3_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT4_MASK   (0x10U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT4_SHIFT  (4U)
/*! BIT4 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT4_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT4_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT5_MASK   (0x20U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT5_SHIFT  (5U)
/*! BIT5 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT5_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT5_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT6_MASK   (0x40U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT6_SHIFT  (6U)
/*! BIT6 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT6_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT6_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT7_MASK   (0x80U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT7_SHIFT  (7U)
/*! BIT7 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT7_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT7_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT8_MASK   (0x100U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT8_SHIFT  (8U)
/*! BIT8 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT8(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT8_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT8_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT9_MASK   (0x200U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT9_SHIFT  (9U)
/*! BIT9 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT9(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT9_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT9_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT10_MASK  (0x400U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT10_SHIFT (10U)
/*! BIT10 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT10(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT10_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT10_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT11_MASK  (0x800U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT11_SHIFT (11U)
/*! BIT11 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT11(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT11_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT11_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT12_MASK  (0x1000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT12_SHIFT (12U)
/*! BIT12 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT12(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT12_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT12_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT13_MASK  (0x2000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT13_SHIFT (13U)
/*! BIT13 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT13(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT13_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT13_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT14_MASK  (0x4000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT14_SHIFT (14U)
/*! BIT14 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT14(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT14_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT14_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT15_MASK  (0x8000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT15_SHIFT (15U)
/*! BIT15 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT15(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT15_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT15_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT16_MASK  (0x10000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT16_SHIFT (16U)
/*! BIT16 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT16(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT16_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT16_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT17_MASK  (0x20000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT17_SHIFT (17U)
/*! BIT17 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT17(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT17_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT17_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT18_MASK  (0x40000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT18_SHIFT (18U)
/*! BIT18 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT18(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT18_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT18_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT19_MASK  (0x80000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT19_SHIFT (19U)
/*! BIT19 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT19(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT19_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT19_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT20_MASK  (0x100000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT20_SHIFT (20U)
/*! BIT20 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT20(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT20_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT20_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT21_MASK  (0x200000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT21_SHIFT (21U)
/*! BIT21 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT21(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT21_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT21_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT22_MASK  (0x400000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT22_SHIFT (22U)
/*! BIT22 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT22(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT22_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT22_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT23_MASK  (0x800000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT23_SHIFT (23U)
/*! BIT23 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT23(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT23_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT23_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT24_MASK  (0x1000000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT24_SHIFT (24U)
/*! BIT24 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT24(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT24_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT24_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT25_MASK  (0x2000000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT25_SHIFT (25U)
/*! BIT25 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT25(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT25_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT25_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT26_MASK  (0x4000000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT26_SHIFT (26U)
/*! BIT26 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT26(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT26_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT26_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT27_MASK  (0x8000000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT27_SHIFT (27U)
/*! BIT27 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT27(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT27_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT27_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT28_MASK  (0x10000000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT28_SHIFT (28U)
/*! BIT28 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT28(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT28_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT28_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT29_MASK  (0x20000000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT29_SHIFT (29U)
/*! BIT29 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT29(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT29_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT29_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT30_MASK  (0x40000000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT30_SHIFT (30U)
/*! BIT30 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT30(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT30_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT30_MASK)

#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT31_MASK  (0x80000000U)
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT31_SHIFT (31U)
/*! BIT31 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT31(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT31_SHIFT)) & TRDC_MBC_DOM2_MEM0_BLK_NSE_W_BIT31_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM2_MEM0_BLK_NSE_W */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM2_MEM0_BLK_NSE_W */
#define TRDC_MBC_DOM2_MEM0_BLK_NSE_W_COUNT2      (3U)

/*! @name MBC_DOM2_MEM1_BLK_CFG_W - MBC Memory Block Configuration Word */
/*! @{ */

#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL0_MASK (0x7U)
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL0_SHIFT (0U)
/*! MBACSEL0 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL0_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL0_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE0_MASK   (0x8U)
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE0_SHIFT  (3U)
/*! NSE0 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE0_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE0_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL1_MASK (0x70U)
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL1_SHIFT (4U)
/*! MBACSEL1 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL1_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL1_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE1_MASK   (0x80U)
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE1_SHIFT  (7U)
/*! NSE1 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE1_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE1_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL2_MASK (0x700U)
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL2_SHIFT (8U)
/*! MBACSEL2 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL2_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL2_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE2_MASK   (0x800U)
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE2_SHIFT  (11U)
/*! NSE2 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE2_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE2_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL3_MASK (0x7000U)
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL3_SHIFT (12U)
/*! MBACSEL3 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL3_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL3_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE3_MASK   (0x8000U)
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE3_SHIFT  (15U)
/*! NSE3 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE3_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE3_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL4_MASK (0x70000U)
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL4_SHIFT (16U)
/*! MBACSEL4 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL4_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL4_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE4_MASK   (0x80000U)
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE4_SHIFT  (19U)
/*! NSE4 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE4_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE4_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL5_MASK (0x700000U)
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL5_SHIFT (20U)
/*! MBACSEL5 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL5_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL5_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE5_MASK   (0x800000U)
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE5_SHIFT  (23U)
/*! NSE5 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE5_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE5_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL6_MASK (0x7000000U)
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL6_SHIFT (24U)
/*! MBACSEL6 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL6_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL6_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE6_MASK   (0x8000000U)
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE6_SHIFT  (27U)
/*! NSE6 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE6_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE6_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL7_MASK (0x70000000U)
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL7_SHIFT (28U)
/*! MBACSEL7 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL7_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_CFG_W_MBACSEL7_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE7_MASK   (0x80000000U)
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE7_SHIFT  (31U)
/*! NSE7 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE7_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_CFG_W_NSE7_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM2_MEM1_BLK_CFG_W */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM2_MEM1_BLK_CFG_W */
#define TRDC_MBC_DOM2_MEM1_BLK_CFG_W_COUNT2      (1U)

/*! @name MBC_DOM2_MEM1_BLK_NSE_W - MBC Memory Block NonSecure Enable Word */
/*! @{ */

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT0_MASK   (0x1U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT0_SHIFT  (0U)
/*! BIT0 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT0_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT0_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT1_MASK   (0x2U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT1_SHIFT  (1U)
/*! BIT1 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT1_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT1_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT2_MASK   (0x4U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT2_SHIFT  (2U)
/*! BIT2 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT2_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT2_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT3_MASK   (0x8U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT3_SHIFT  (3U)
/*! BIT3 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT3_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT3_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT4_MASK   (0x10U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT4_SHIFT  (4U)
/*! BIT4 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT4_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT4_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT5_MASK   (0x20U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT5_SHIFT  (5U)
/*! BIT5 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT5_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT5_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT6_MASK   (0x40U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT6_SHIFT  (6U)
/*! BIT6 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT6_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT6_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT7_MASK   (0x80U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT7_SHIFT  (7U)
/*! BIT7 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT7_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT7_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT8_MASK   (0x100U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT8_SHIFT  (8U)
/*! BIT8 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT8(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT8_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT8_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT9_MASK   (0x200U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT9_SHIFT  (9U)
/*! BIT9 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT9(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT9_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT9_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT10_MASK  (0x400U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT10_SHIFT (10U)
/*! BIT10 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT10(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT10_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT10_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT11_MASK  (0x800U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT11_SHIFT (11U)
/*! BIT11 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT11(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT11_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT11_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT12_MASK  (0x1000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT12_SHIFT (12U)
/*! BIT12 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT12(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT12_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT12_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT13_MASK  (0x2000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT13_SHIFT (13U)
/*! BIT13 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT13(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT13_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT13_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT14_MASK  (0x4000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT14_SHIFT (14U)
/*! BIT14 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT14(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT14_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT14_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT15_MASK  (0x8000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT15_SHIFT (15U)
/*! BIT15 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT15(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT15_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT15_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT16_MASK  (0x10000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT16_SHIFT (16U)
/*! BIT16 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT16(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT16_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT16_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT17_MASK  (0x20000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT17_SHIFT (17U)
/*! BIT17 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT17(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT17_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT17_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT18_MASK  (0x40000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT18_SHIFT (18U)
/*! BIT18 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT18(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT18_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT18_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT19_MASK  (0x80000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT19_SHIFT (19U)
/*! BIT19 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT19(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT19_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT19_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT20_MASK  (0x100000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT20_SHIFT (20U)
/*! BIT20 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT20(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT20_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT20_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT21_MASK  (0x200000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT21_SHIFT (21U)
/*! BIT21 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT21(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT21_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT21_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT22_MASK  (0x400000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT22_SHIFT (22U)
/*! BIT22 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT22(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT22_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT22_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT23_MASK  (0x800000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT23_SHIFT (23U)
/*! BIT23 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT23(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT23_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT23_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT24_MASK  (0x1000000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT24_SHIFT (24U)
/*! BIT24 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT24(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT24_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT24_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT25_MASK  (0x2000000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT25_SHIFT (25U)
/*! BIT25 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT25(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT25_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT25_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT26_MASK  (0x4000000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT26_SHIFT (26U)
/*! BIT26 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT26(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT26_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT26_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT27_MASK  (0x8000000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT27_SHIFT (27U)
/*! BIT27 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT27(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT27_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT27_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT28_MASK  (0x10000000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT28_SHIFT (28U)
/*! BIT28 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT28(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT28_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT28_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT29_MASK  (0x20000000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT29_SHIFT (29U)
/*! BIT29 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT29(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT29_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT29_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT30_MASK  (0x40000000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT30_SHIFT (30U)
/*! BIT30 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT30(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT30_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT30_MASK)

#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT31_MASK  (0x80000000U)
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT31_SHIFT (31U)
/*! BIT31 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT31(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT31_SHIFT)) & TRDC_MBC_DOM2_MEM1_BLK_NSE_W_BIT31_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM2_MEM1_BLK_NSE_W */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM2_MEM1_BLK_NSE_W */
#define TRDC_MBC_DOM2_MEM1_BLK_NSE_W_COUNT2      (1U)

/*! @name MBC_DOM2_MEM2_BLK_CFG_W - MBC Memory Block Configuration Word */
/*! @{ */

#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL0_MASK (0x7U)
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL0_SHIFT (0U)
/*! MBACSEL0 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL0_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL0_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE0_MASK   (0x8U)
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE0_SHIFT  (3U)
/*! NSE0 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE0_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE0_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL1_MASK (0x70U)
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL1_SHIFT (4U)
/*! MBACSEL1 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL1_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL1_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE1_MASK   (0x80U)
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE1_SHIFT  (7U)
/*! NSE1 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE1_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE1_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL2_MASK (0x700U)
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL2_SHIFT (8U)
/*! MBACSEL2 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL2_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL2_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE2_MASK   (0x800U)
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE2_SHIFT  (11U)
/*! NSE2 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE2_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE2_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL3_MASK (0x7000U)
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL3_SHIFT (12U)
/*! MBACSEL3 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL3_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL3_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE3_MASK   (0x8000U)
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE3_SHIFT  (15U)
/*! NSE3 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE3_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE3_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL4_MASK (0x70000U)
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL4_SHIFT (16U)
/*! MBACSEL4 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL4_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL4_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE4_MASK   (0x80000U)
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE4_SHIFT  (19U)
/*! NSE4 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE4_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE4_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL5_MASK (0x700000U)
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL5_SHIFT (20U)
/*! MBACSEL5 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL5_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL5_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE5_MASK   (0x800000U)
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE5_SHIFT  (23U)
/*! NSE5 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE5_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE5_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL6_MASK (0x7000000U)
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL6_SHIFT (24U)
/*! MBACSEL6 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL6_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL6_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE6_MASK   (0x8000000U)
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE6_SHIFT  (27U)
/*! NSE6 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE6_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE6_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL7_MASK (0x70000000U)
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL7_SHIFT (28U)
/*! MBACSEL7 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL7_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_CFG_W_MBACSEL7_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE7_MASK   (0x80000000U)
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE7_SHIFT  (31U)
/*! NSE7 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE7_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_CFG_W_NSE7_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM2_MEM2_BLK_CFG_W */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM2_MEM2_BLK_CFG_W */
#define TRDC_MBC_DOM2_MEM2_BLK_CFG_W_COUNT2      (2U)

/*! @name MBC_DOM2_MEM2_BLK_NSE_W - MBC Memory Block NonSecure Enable Word */
/*! @{ */

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT0_MASK   (0x1U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT0_SHIFT  (0U)
/*! BIT0 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT0_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT0_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT1_MASK   (0x2U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT1_SHIFT  (1U)
/*! BIT1 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT1_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT1_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT2_MASK   (0x4U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT2_SHIFT  (2U)
/*! BIT2 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT2_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT2_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT3_MASK   (0x8U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT3_SHIFT  (3U)
/*! BIT3 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT3_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT3_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT4_MASK   (0x10U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT4_SHIFT  (4U)
/*! BIT4 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT4_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT4_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT5_MASK   (0x20U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT5_SHIFT  (5U)
/*! BIT5 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT5_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT5_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT6_MASK   (0x40U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT6_SHIFT  (6U)
/*! BIT6 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT6_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT6_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT7_MASK   (0x80U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT7_SHIFT  (7U)
/*! BIT7 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT7_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT7_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT8_MASK   (0x100U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT8_SHIFT  (8U)
/*! BIT8 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT8(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT8_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT8_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT9_MASK   (0x200U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT9_SHIFT  (9U)
/*! BIT9 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT9(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT9_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT9_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT10_MASK  (0x400U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT10_SHIFT (10U)
/*! BIT10 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT10(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT10_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT10_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT11_MASK  (0x800U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT11_SHIFT (11U)
/*! BIT11 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT11(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT11_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT11_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT12_MASK  (0x1000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT12_SHIFT (12U)
/*! BIT12 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT12(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT12_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT12_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT13_MASK  (0x2000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT13_SHIFT (13U)
/*! BIT13 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT13(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT13_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT13_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT14_MASK  (0x4000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT14_SHIFT (14U)
/*! BIT14 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT14(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT14_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT14_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT15_MASK  (0x8000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT15_SHIFT (15U)
/*! BIT15 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT15(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT15_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT15_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT16_MASK  (0x10000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT16_SHIFT (16U)
/*! BIT16 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT16(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT16_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT16_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT17_MASK  (0x20000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT17_SHIFT (17U)
/*! BIT17 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT17(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT17_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT17_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT18_MASK  (0x40000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT18_SHIFT (18U)
/*! BIT18 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT18(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT18_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT18_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT19_MASK  (0x80000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT19_SHIFT (19U)
/*! BIT19 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT19(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT19_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT19_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT20_MASK  (0x100000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT20_SHIFT (20U)
/*! BIT20 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT20(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT20_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT20_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT21_MASK  (0x200000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT21_SHIFT (21U)
/*! BIT21 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT21(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT21_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT21_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT22_MASK  (0x400000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT22_SHIFT (22U)
/*! BIT22 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT22(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT22_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT22_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT23_MASK  (0x800000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT23_SHIFT (23U)
/*! BIT23 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT23(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT23_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT23_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT24_MASK  (0x1000000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT24_SHIFT (24U)
/*! BIT24 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT24(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT24_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT24_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT25_MASK  (0x2000000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT25_SHIFT (25U)
/*! BIT25 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT25(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT25_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT25_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT26_MASK  (0x4000000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT26_SHIFT (26U)
/*! BIT26 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT26(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT26_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT26_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT27_MASK  (0x8000000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT27_SHIFT (27U)
/*! BIT27 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT27(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT27_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT27_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT28_MASK  (0x10000000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT28_SHIFT (28U)
/*! BIT28 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT28(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT28_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT28_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT29_MASK  (0x20000000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT29_SHIFT (29U)
/*! BIT29 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT29(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT29_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT29_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT30_MASK  (0x40000000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT30_SHIFT (30U)
/*! BIT30 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT30(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT30_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT30_MASK)

#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT31_MASK  (0x80000000U)
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT31_SHIFT (31U)
/*! BIT31 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT31(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT31_SHIFT)) & TRDC_MBC_DOM2_MEM2_BLK_NSE_W_BIT31_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM2_MEM2_BLK_NSE_W */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM2_MEM2_BLK_NSE_W */
#define TRDC_MBC_DOM2_MEM2_BLK_NSE_W_COUNT2      (1U)

/*! @name MBC_DOM2_MEM3_BLK_CFG_W - MBC Memory Block Configuration Word */
/*! @{ */

#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL0_MASK (0x7U)
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL0_SHIFT (0U)
/*! MBACSEL0 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL0_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL0_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE0_MASK   (0x8U)
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE0_SHIFT  (3U)
/*! NSE0 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE0_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE0_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL1_MASK (0x70U)
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL1_SHIFT (4U)
/*! MBACSEL1 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL1_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL1_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE1_MASK   (0x80U)
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE1_SHIFT  (7U)
/*! NSE1 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE1_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE1_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL2_MASK (0x700U)
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL2_SHIFT (8U)
/*! MBACSEL2 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL2_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL2_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE2_MASK   (0x800U)
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE2_SHIFT  (11U)
/*! NSE2 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE2_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE2_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL3_MASK (0x7000U)
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL3_SHIFT (12U)
/*! MBACSEL3 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL3_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL3_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE3_MASK   (0x8000U)
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE3_SHIFT  (15U)
/*! NSE3 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE3_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE3_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL4_MASK (0x70000U)
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL4_SHIFT (16U)
/*! MBACSEL4 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL4_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL4_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE4_MASK   (0x80000U)
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE4_SHIFT  (19U)
/*! NSE4 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE4_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE4_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL5_MASK (0x700000U)
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL5_SHIFT (20U)
/*! MBACSEL5 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL5_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL5_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE5_MASK   (0x800000U)
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE5_SHIFT  (23U)
/*! NSE5 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE5_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE5_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL6_MASK (0x7000000U)
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL6_SHIFT (24U)
/*! MBACSEL6 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL6_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL6_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE6_MASK   (0x8000000U)
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE6_SHIFT  (27U)
/*! NSE6 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE6_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE6_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL7_MASK (0x70000000U)
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL7_SHIFT (28U)
/*! MBACSEL7 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL7_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_CFG_W_MBACSEL7_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE7_MASK   (0x80000000U)
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE7_SHIFT  (31U)
/*! NSE7 - NonSecure Enable for block B
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE7_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_CFG_W_NSE7_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM2_MEM3_BLK_CFG_W */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM2_MEM3_BLK_CFG_W */
#define TRDC_MBC_DOM2_MEM3_BLK_CFG_W_COUNT2      (2U)

/*! @name MBC_DOM2_MEM3_BLK_NSE_W - MBC Memory Block NonSecure Enable Word */
/*! @{ */

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT0_MASK   (0x1U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT0_SHIFT  (0U)
/*! BIT0 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT0(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT0_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT0_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT1_MASK   (0x2U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT1_SHIFT  (1U)
/*! BIT1 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT1_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT1_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT2_MASK   (0x4U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT2_SHIFT  (2U)
/*! BIT2 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT2(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT2_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT2_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT3_MASK   (0x8U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT3_SHIFT  (3U)
/*! BIT3 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT3(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT3_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT3_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT4_MASK   (0x10U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT4_SHIFT  (4U)
/*! BIT4 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT4(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT4_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT4_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT5_MASK   (0x20U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT5_SHIFT  (5U)
/*! BIT5 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT5(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT5_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT5_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT6_MASK   (0x40U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT6_SHIFT  (6U)
/*! BIT6 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT6(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT6_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT6_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT7_MASK   (0x80U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT7_SHIFT  (7U)
/*! BIT7 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT7(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT7_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT7_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT8_MASK   (0x100U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT8_SHIFT  (8U)
/*! BIT8 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT8(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT8_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT8_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT9_MASK   (0x200U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT9_SHIFT  (9U)
/*! BIT9 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT9(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT9_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT9_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT10_MASK  (0x400U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT10_SHIFT (10U)
/*! BIT10 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT10(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT10_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT10_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT11_MASK  (0x800U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT11_SHIFT (11U)
/*! BIT11 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT11(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT11_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT11_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT12_MASK  (0x1000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT12_SHIFT (12U)
/*! BIT12 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT12(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT12_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT12_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT13_MASK  (0x2000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT13_SHIFT (13U)
/*! BIT13 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT13(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT13_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT13_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT14_MASK  (0x4000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT14_SHIFT (14U)
/*! BIT14 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT14(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT14_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT14_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT15_MASK  (0x8000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT15_SHIFT (15U)
/*! BIT15 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT15(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT15_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT15_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT16_MASK  (0x10000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT16_SHIFT (16U)
/*! BIT16 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT16(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT16_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT16_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT17_MASK  (0x20000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT17_SHIFT (17U)
/*! BIT17 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT17(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT17_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT17_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT18_MASK  (0x40000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT18_SHIFT (18U)
/*! BIT18 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT18(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT18_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT18_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT19_MASK  (0x80000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT19_SHIFT (19U)
/*! BIT19 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT19(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT19_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT19_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT20_MASK  (0x100000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT20_SHIFT (20U)
/*! BIT20 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT20(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT20_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT20_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT21_MASK  (0x200000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT21_SHIFT (21U)
/*! BIT21 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT21(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT21_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT21_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT22_MASK  (0x400000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT22_SHIFT (22U)
/*! BIT22 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT22(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT22_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT22_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT23_MASK  (0x800000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT23_SHIFT (23U)
/*! BIT23 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT23(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT23_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT23_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT24_MASK  (0x1000000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT24_SHIFT (24U)
/*! BIT24 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT24(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT24_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT24_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT25_MASK  (0x2000000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT25_SHIFT (25U)
/*! BIT25 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT25(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT25_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT25_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT26_MASK  (0x4000000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT26_SHIFT (26U)
/*! BIT26 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT26(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT26_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT26_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT27_MASK  (0x8000000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT27_SHIFT (27U)
/*! BIT27 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT27(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT27_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT27_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT28_MASK  (0x10000000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT28_SHIFT (28U)
/*! BIT28 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT28(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT28_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT28_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT29_MASK  (0x20000000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT29_SHIFT (29U)
/*! BIT29 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT29(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT29_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT29_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT30_MASK  (0x40000000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT30_SHIFT (30U)
/*! BIT30 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT30(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT30_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT30_MASK)

#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT31_MASK  (0x80000000U)
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT31_SHIFT (31U)
/*! BIT31 - Bit b NonSecure Enable [b = 0 - 31]
 *  0b0..Secure accesses to block B are based on corresponding MBACSEL field in register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT31(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT31_SHIFT)) & TRDC_MBC_DOM2_MEM3_BLK_NSE_W_BIT31_MASK)
/*! @} */

/* The count of TRDC_MBC_DOM2_MEM3_BLK_NSE_W */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_COUNT       (3U)

/* The count of TRDC_MBC_DOM2_MEM3_BLK_NSE_W */
#define TRDC_MBC_DOM2_MEM3_BLK_NSE_W_COUNT2      (1U)

/*! @name MRC_GLBCFG - MRC Global Configuration Register */
/*! @{ */

#define TRDC_MRC_GLBCFG_NRGNS_MASK               (0x1FU)
#define TRDC_MRC_GLBCFG_NRGNS_SHIFT              (0U)
/*! NRGNS - Number of regions [1-16] */
#define TRDC_MRC_GLBCFG_NRGNS(x)                 (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_GLBCFG_NRGNS_SHIFT)) & TRDC_MRC_GLBCFG_NRGNS_MASK)
/*! @} */

/* The count of TRDC_MRC_GLBCFG */
#define TRDC_MRC_GLBCFG_COUNT                    (1U)

/*! @name MRC_NSE_RGN_INDIRECT - MRC NonSecure Enable Region Indirect */
/*! @{ */

#define TRDC_MRC_NSE_RGN_INDIRECT_DID_SEL_MASK   (0xFF0000U)
#define TRDC_MRC_NSE_RGN_INDIRECT_DID_SEL_SHIFT  (16U)
/*! DID_SEL - DID Select */
#define TRDC_MRC_NSE_RGN_INDIRECT_DID_SEL(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_NSE_RGN_INDIRECT_DID_SEL_SHIFT)) & TRDC_MRC_NSE_RGN_INDIRECT_DID_SEL_MASK)
/*! @} */

/* The count of TRDC_MRC_NSE_RGN_INDIRECT */
#define TRDC_MRC_NSE_RGN_INDIRECT_COUNT          (1U)

/*! @name MRC_NSE_RGN_SET - MRC NonSecure Enable Region Set */
/*! @{ */

#define TRDC_MRC_NSE_RGN_SET_W1SET_MASK          (0xFFFFU)
#define TRDC_MRC_NSE_RGN_SET_W1SET_SHIFT         (0U)
/*! W1SET - Write-1 Set */
#define TRDC_MRC_NSE_RGN_SET_W1SET(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_NSE_RGN_SET_W1SET_SHIFT)) & TRDC_MRC_NSE_RGN_SET_W1SET_MASK)
/*! @} */

/* The count of TRDC_MRC_NSE_RGN_SET */
#define TRDC_MRC_NSE_RGN_SET_COUNT               (1U)

/*! @name MRC_NSE_RGN_CLR - MRC NonSecure Enable Region Clear */
/*! @{ */

#define TRDC_MRC_NSE_RGN_CLR_W1CLR_MASK          (0xFFFFU)
#define TRDC_MRC_NSE_RGN_CLR_W1CLR_SHIFT         (0U)
/*! W1CLR - Write-1 Clear */
#define TRDC_MRC_NSE_RGN_CLR_W1CLR(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_NSE_RGN_CLR_W1CLR_SHIFT)) & TRDC_MRC_NSE_RGN_CLR_W1CLR_MASK)
/*! @} */

/* The count of TRDC_MRC_NSE_RGN_CLR */
#define TRDC_MRC_NSE_RGN_CLR_COUNT               (1U)

/*! @name MRC_NSE_RGN_CLR_ALL - MRC NonSecure Enable Region Clear All */
/*! @{ */

#define TRDC_MRC_NSE_RGN_CLR_ALL_DID_SEL_MASK    (0xFF0000U)
#define TRDC_MRC_NSE_RGN_CLR_ALL_DID_SEL_SHIFT   (16U)
/*! DID_SEL - DID Select */
#define TRDC_MRC_NSE_RGN_CLR_ALL_DID_SEL(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_NSE_RGN_CLR_ALL_DID_SEL_SHIFT)) & TRDC_MRC_NSE_RGN_CLR_ALL_DID_SEL_MASK)
/*! @} */

/* The count of TRDC_MRC_NSE_RGN_CLR_ALL */
#define TRDC_MRC_NSE_RGN_CLR_ALL_COUNT           (1U)

/*! @name MRC_GLBAC - MRC Global Access Control */
/*! @{ */

#define TRDC_MRC_GLBAC_NUX_MASK                  (0x1U)
#define TRDC_MRC_GLBAC_NUX_SHIFT                 (0U)
/*! NUX - NonsecureUser Execute
 *  0b0..Execute access is not allowed in Nonsecure User mode.
 *  0b1..Execute access is allowed in Nonsecure User mode.
 */
#define TRDC_MRC_GLBAC_NUX(x)                    (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_GLBAC_NUX_SHIFT)) & TRDC_MRC_GLBAC_NUX_MASK)

#define TRDC_MRC_GLBAC_NUW_MASK                  (0x2U)
#define TRDC_MRC_GLBAC_NUW_SHIFT                 (1U)
/*! NUW - NonsecureUser Write
 *  0b0..Write access is not allowed in Nonsecure User mode.
 *  0b1..Write access is allowed in Nonsecure User mode.
 */
#define TRDC_MRC_GLBAC_NUW(x)                    (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_GLBAC_NUW_SHIFT)) & TRDC_MRC_GLBAC_NUW_MASK)

#define TRDC_MRC_GLBAC_NUR_MASK                  (0x4U)
#define TRDC_MRC_GLBAC_NUR_SHIFT                 (2U)
/*! NUR - NonsecureUser Read
 *  0b0..Read access is not allowed in Nonsecure User mode.
 *  0b1..Read access is allowed in Nonsecure User mode.
 */
#define TRDC_MRC_GLBAC_NUR(x)                    (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_GLBAC_NUR_SHIFT)) & TRDC_MRC_GLBAC_NUR_MASK)

#define TRDC_MRC_GLBAC_NPX_MASK                  (0x10U)
#define TRDC_MRC_GLBAC_NPX_SHIFT                 (4U)
/*! NPX - NonsecurePriv Execute
 *  0b0..Execute access is not allowed in Nonsecure Privilege mode.
 *  0b1..Execute access is allowed in Nonsecure Privilege mode.
 */
#define TRDC_MRC_GLBAC_NPX(x)                    (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_GLBAC_NPX_SHIFT)) & TRDC_MRC_GLBAC_NPX_MASK)

#define TRDC_MRC_GLBAC_NPW_MASK                  (0x20U)
#define TRDC_MRC_GLBAC_NPW_SHIFT                 (5U)
/*! NPW - NonsecurePriv Write
 *  0b0..Write access is not allowed in Nonsecure Privilege mode.
 *  0b1..Write access is allowed in Nonsecure Privilege mode.
 */
#define TRDC_MRC_GLBAC_NPW(x)                    (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_GLBAC_NPW_SHIFT)) & TRDC_MRC_GLBAC_NPW_MASK)

#define TRDC_MRC_GLBAC_NPR_MASK                  (0x40U)
#define TRDC_MRC_GLBAC_NPR_SHIFT                 (6U)
/*! NPR - NonsecurePriv Read
 *  0b0..Read access is not allowed in Nonsecure Privilege mode.
 *  0b1..Read access is allowed in Nonsecure Privilege mode.
 */
#define TRDC_MRC_GLBAC_NPR(x)                    (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_GLBAC_NPR_SHIFT)) & TRDC_MRC_GLBAC_NPR_MASK)

#define TRDC_MRC_GLBAC_SUX_MASK                  (0x100U)
#define TRDC_MRC_GLBAC_SUX_SHIFT                 (8U)
/*! SUX - SecureUser Execute
 *  0b0..Execute access is not allowed in Secure User mode.
 *  0b1..Execute access is allowed in Secure User mode.
 */
#define TRDC_MRC_GLBAC_SUX(x)                    (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_GLBAC_SUX_SHIFT)) & TRDC_MRC_GLBAC_SUX_MASK)

#define TRDC_MRC_GLBAC_SUW_MASK                  (0x200U)
#define TRDC_MRC_GLBAC_SUW_SHIFT                 (9U)
/*! SUW - SecureUser Write
 *  0b0..Write access is not allowed in Secure User mode.
 *  0b1..Write access is allowed in Secure User mode.
 */
#define TRDC_MRC_GLBAC_SUW(x)                    (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_GLBAC_SUW_SHIFT)) & TRDC_MRC_GLBAC_SUW_MASK)

#define TRDC_MRC_GLBAC_SUR_MASK                  (0x400U)
#define TRDC_MRC_GLBAC_SUR_SHIFT                 (10U)
/*! SUR - SecureUser Read
 *  0b0..Read access is not allowed in Secure User mode.
 *  0b1..Read access is allowed in Secure User mode.
 */
#define TRDC_MRC_GLBAC_SUR(x)                    (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_GLBAC_SUR_SHIFT)) & TRDC_MRC_GLBAC_SUR_MASK)

#define TRDC_MRC_GLBAC_SPX_MASK                  (0x1000U)
#define TRDC_MRC_GLBAC_SPX_SHIFT                 (12U)
/*! SPX - SecurePriv Execute
 *  0b0..Execute access is not allowed in Secure Privilege mode.
 *  0b1..Execute access is allowed in Secure Privilege mode.
 */
#define TRDC_MRC_GLBAC_SPX(x)                    (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_GLBAC_SPX_SHIFT)) & TRDC_MRC_GLBAC_SPX_MASK)

#define TRDC_MRC_GLBAC_SPW_MASK                  (0x2000U)
#define TRDC_MRC_GLBAC_SPW_SHIFT                 (13U)
/*! SPW - SecurePriv Write
 *  0b0..Write access is not allowed in Secure Privilege mode.
 *  0b1..Write access is allowed in Secure Privilege mode.
 */
#define TRDC_MRC_GLBAC_SPW(x)                    (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_GLBAC_SPW_SHIFT)) & TRDC_MRC_GLBAC_SPW_MASK)

#define TRDC_MRC_GLBAC_SPR_MASK                  (0x4000U)
#define TRDC_MRC_GLBAC_SPR_SHIFT                 (14U)
/*! SPR - SecurePriv Read
 *  0b0..Read access is not allowed in Secure Privilege mode.
 *  0b1..Read access is allowed in Secure Privilege mode.
 */
#define TRDC_MRC_GLBAC_SPR(x)                    (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_GLBAC_SPR_SHIFT)) & TRDC_MRC_GLBAC_SPR_MASK)

#define TRDC_MRC_GLBAC_LK_MASK                   (0x80000000U)
#define TRDC_MRC_GLBAC_LK_SHIFT                  (31U)
/*! LK - LOCK
 *  0b0..This register is not locked and can be altered.
 *  0b1..This register is locked (read-only) and cannot be altered.
 */
#define TRDC_MRC_GLBAC_LK(x)                     (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_GLBAC_LK_SHIFT)) & TRDC_MRC_GLBAC_LK_MASK)
/*! @} */

/* The count of TRDC_MRC_GLBAC */
#define TRDC_MRC_GLBAC_COUNT                     (1U)

/* The count of TRDC_MRC_GLBAC */
#define TRDC_MRC_GLBAC_COUNT2                    (8U)

/*! @name MRC_DOM0_RGD_W - MRC Region Descriptor Word 0..MRC Region Descriptor Word 1 */
/*! @{ */

#define TRDC_MRC_DOM0_RGD_W_MRACSEL_MASK         (0x7U)
#define TRDC_MRC_DOM0_RGD_W_MRACSEL_SHIFT        (0U)
/*! MRACSEL - Memory Region Access Control Select
 *  0b000..Select MRC_GLBAC0 access control policy
 *  0b001..Select MRC_GLBAC1 access control policy
 *  0b010..Select MRC_GLBAC2 access control policy
 *  0b011..Select MRC_GLBAC3 access control policy
 *  0b100..Select MRC_GLBAC4 access control policy
 *  0b101..Select MRC_GLBAC5 access control policy
 *  0b110..Select MRC_GLBAC6 access control policy
 *  0b111..Select MRC_GLBAC7 access control policy
 */
#define TRDC_MRC_DOM0_RGD_W_MRACSEL(x)           (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM0_RGD_W_MRACSEL_SHIFT)) & TRDC_MRC_DOM0_RGD_W_MRACSEL_MASK)

#define TRDC_MRC_DOM0_RGD_W_VLD_MASK             (0x1U)
#define TRDC_MRC_DOM0_RGD_W_VLD_SHIFT            (0U)
/*! VLD - Valid */
#define TRDC_MRC_DOM0_RGD_W_VLD(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM0_RGD_W_VLD_SHIFT)) & TRDC_MRC_DOM0_RGD_W_VLD_MASK)

#define TRDC_MRC_DOM0_RGD_W_NSE_MASK             (0x10U)
#define TRDC_MRC_DOM0_RGD_W_NSE_SHIFT            (4U)
/*! NSE - NonSecure Enable
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in this register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in this register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM0_RGD_W_NSE(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM0_RGD_W_NSE_SHIFT)) & TRDC_MRC_DOM0_RGD_W_NSE_MASK)

#define TRDC_MRC_DOM0_RGD_W_END_ADDR_MASK        (0xFFFFF000U)
#define TRDC_MRC_DOM0_RGD_W_END_ADDR_SHIFT       (12U)
/*! END_ADDR - End Address */
#define TRDC_MRC_DOM0_RGD_W_END_ADDR(x)          (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM0_RGD_W_END_ADDR_SHIFT)) & TRDC_MRC_DOM0_RGD_W_END_ADDR_MASK)

#define TRDC_MRC_DOM0_RGD_W_STRT_ADDR_MASK       (0xFFFFF000U)
#define TRDC_MRC_DOM0_RGD_W_STRT_ADDR_SHIFT      (12U)
/*! STRT_ADDR - Start Address */
#define TRDC_MRC_DOM0_RGD_W_STRT_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM0_RGD_W_STRT_ADDR_SHIFT)) & TRDC_MRC_DOM0_RGD_W_STRT_ADDR_MASK)
/*! @} */

/* The count of TRDC_MRC_DOM0_RGD_W */
#define TRDC_MRC_DOM0_RGD_W_COUNT                (1U)

/* The count of TRDC_MRC_DOM0_RGD_W */
#define TRDC_MRC_DOM0_RGD_W_COUNT2               (8U)

/* The count of TRDC_MRC_DOM0_RGD_W */
#define TRDC_MRC_DOM0_RGD_W_COUNT3               (2U)

/*! @name MRC_DOM0_RGD_NSE - MRC Region Descriptor NonSecure Enable */
/*! @{ */

#define TRDC_MRC_DOM0_RGD_NSE_BIT0_MASK          (0x1U)
#define TRDC_MRC_DOM0_RGD_NSE_BIT0_SHIFT         (0U)
/*! BIT0 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM0_RGD_NSE_BIT0(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM0_RGD_NSE_BIT0_SHIFT)) & TRDC_MRC_DOM0_RGD_NSE_BIT0_MASK)

#define TRDC_MRC_DOM0_RGD_NSE_BIT1_MASK          (0x2U)
#define TRDC_MRC_DOM0_RGD_NSE_BIT1_SHIFT         (1U)
/*! BIT1 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM0_RGD_NSE_BIT1(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM0_RGD_NSE_BIT1_SHIFT)) & TRDC_MRC_DOM0_RGD_NSE_BIT1_MASK)

#define TRDC_MRC_DOM0_RGD_NSE_BIT2_MASK          (0x4U)
#define TRDC_MRC_DOM0_RGD_NSE_BIT2_SHIFT         (2U)
/*! BIT2 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM0_RGD_NSE_BIT2(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM0_RGD_NSE_BIT2_SHIFT)) & TRDC_MRC_DOM0_RGD_NSE_BIT2_MASK)

#define TRDC_MRC_DOM0_RGD_NSE_BIT3_MASK          (0x8U)
#define TRDC_MRC_DOM0_RGD_NSE_BIT3_SHIFT         (3U)
/*! BIT3 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM0_RGD_NSE_BIT3(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM0_RGD_NSE_BIT3_SHIFT)) & TRDC_MRC_DOM0_RGD_NSE_BIT3_MASK)

#define TRDC_MRC_DOM0_RGD_NSE_BIT4_MASK          (0x10U)
#define TRDC_MRC_DOM0_RGD_NSE_BIT4_SHIFT         (4U)
/*! BIT4 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM0_RGD_NSE_BIT4(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM0_RGD_NSE_BIT4_SHIFT)) & TRDC_MRC_DOM0_RGD_NSE_BIT4_MASK)

#define TRDC_MRC_DOM0_RGD_NSE_BIT5_MASK          (0x20U)
#define TRDC_MRC_DOM0_RGD_NSE_BIT5_SHIFT         (5U)
/*! BIT5 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM0_RGD_NSE_BIT5(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM0_RGD_NSE_BIT5_SHIFT)) & TRDC_MRC_DOM0_RGD_NSE_BIT5_MASK)

#define TRDC_MRC_DOM0_RGD_NSE_BIT6_MASK          (0x40U)
#define TRDC_MRC_DOM0_RGD_NSE_BIT6_SHIFT         (6U)
/*! BIT6 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM0_RGD_NSE_BIT6(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM0_RGD_NSE_BIT6_SHIFT)) & TRDC_MRC_DOM0_RGD_NSE_BIT6_MASK)

#define TRDC_MRC_DOM0_RGD_NSE_BIT7_MASK          (0x80U)
#define TRDC_MRC_DOM0_RGD_NSE_BIT7_SHIFT         (7U)
/*! BIT7 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM0_RGD_NSE_BIT7(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM0_RGD_NSE_BIT7_SHIFT)) & TRDC_MRC_DOM0_RGD_NSE_BIT7_MASK)
/*! @} */

/* The count of TRDC_MRC_DOM0_RGD_NSE */
#define TRDC_MRC_DOM0_RGD_NSE_COUNT              (1U)

/*! @name MRC_DOM1_RGD_W - MRC Region Descriptor Word 0..MRC Region Descriptor Word 1 */
/*! @{ */

#define TRDC_MRC_DOM1_RGD_W_MRACSEL_MASK         (0x7U)
#define TRDC_MRC_DOM1_RGD_W_MRACSEL_SHIFT        (0U)
/*! MRACSEL - Memory Region Access Control Select
 *  0b000..Select MRC_GLBAC0 access control policy
 *  0b001..Select MRC_GLBAC1 access control policy
 *  0b010..Select MRC_GLBAC2 access control policy
 *  0b011..Select MRC_GLBAC3 access control policy
 *  0b100..Select MRC_GLBAC4 access control policy
 *  0b101..Select MRC_GLBAC5 access control policy
 *  0b110..Select MRC_GLBAC6 access control policy
 *  0b111..Select MRC_GLBAC7 access control policy
 */
#define TRDC_MRC_DOM1_RGD_W_MRACSEL(x)           (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM1_RGD_W_MRACSEL_SHIFT)) & TRDC_MRC_DOM1_RGD_W_MRACSEL_MASK)

#define TRDC_MRC_DOM1_RGD_W_VLD_MASK             (0x1U)
#define TRDC_MRC_DOM1_RGD_W_VLD_SHIFT            (0U)
/*! VLD - Valid */
#define TRDC_MRC_DOM1_RGD_W_VLD(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM1_RGD_W_VLD_SHIFT)) & TRDC_MRC_DOM1_RGD_W_VLD_MASK)

#define TRDC_MRC_DOM1_RGD_W_NSE_MASK             (0x10U)
#define TRDC_MRC_DOM1_RGD_W_NSE_SHIFT            (4U)
/*! NSE - NonSecure Enable
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in this register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in this register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM1_RGD_W_NSE(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM1_RGD_W_NSE_SHIFT)) & TRDC_MRC_DOM1_RGD_W_NSE_MASK)

#define TRDC_MRC_DOM1_RGD_W_END_ADDR_MASK        (0xFFFFF000U)
#define TRDC_MRC_DOM1_RGD_W_END_ADDR_SHIFT       (12U)
/*! END_ADDR - End Address */
#define TRDC_MRC_DOM1_RGD_W_END_ADDR(x)          (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM1_RGD_W_END_ADDR_SHIFT)) & TRDC_MRC_DOM1_RGD_W_END_ADDR_MASK)

#define TRDC_MRC_DOM1_RGD_W_STRT_ADDR_MASK       (0xFFFFF000U)
#define TRDC_MRC_DOM1_RGD_W_STRT_ADDR_SHIFT      (12U)
/*! STRT_ADDR - Start Address */
#define TRDC_MRC_DOM1_RGD_W_STRT_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM1_RGD_W_STRT_ADDR_SHIFT)) & TRDC_MRC_DOM1_RGD_W_STRT_ADDR_MASK)
/*! @} */

/* The count of TRDC_MRC_DOM1_RGD_W */
#define TRDC_MRC_DOM1_RGD_W_COUNT                (1U)

/* The count of TRDC_MRC_DOM1_RGD_W */
#define TRDC_MRC_DOM1_RGD_W_COUNT2               (8U)

/* The count of TRDC_MRC_DOM1_RGD_W */
#define TRDC_MRC_DOM1_RGD_W_COUNT3               (2U)

/*! @name MRC_DOM1_RGD_NSE - MRC Region Descriptor NonSecure Enable */
/*! @{ */

#define TRDC_MRC_DOM1_RGD_NSE_BIT0_MASK          (0x1U)
#define TRDC_MRC_DOM1_RGD_NSE_BIT0_SHIFT         (0U)
/*! BIT0 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM1_RGD_NSE_BIT0(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM1_RGD_NSE_BIT0_SHIFT)) & TRDC_MRC_DOM1_RGD_NSE_BIT0_MASK)

#define TRDC_MRC_DOM1_RGD_NSE_BIT1_MASK          (0x2U)
#define TRDC_MRC_DOM1_RGD_NSE_BIT1_SHIFT         (1U)
/*! BIT1 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM1_RGD_NSE_BIT1(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM1_RGD_NSE_BIT1_SHIFT)) & TRDC_MRC_DOM1_RGD_NSE_BIT1_MASK)

#define TRDC_MRC_DOM1_RGD_NSE_BIT2_MASK          (0x4U)
#define TRDC_MRC_DOM1_RGD_NSE_BIT2_SHIFT         (2U)
/*! BIT2 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM1_RGD_NSE_BIT2(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM1_RGD_NSE_BIT2_SHIFT)) & TRDC_MRC_DOM1_RGD_NSE_BIT2_MASK)

#define TRDC_MRC_DOM1_RGD_NSE_BIT3_MASK          (0x8U)
#define TRDC_MRC_DOM1_RGD_NSE_BIT3_SHIFT         (3U)
/*! BIT3 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM1_RGD_NSE_BIT3(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM1_RGD_NSE_BIT3_SHIFT)) & TRDC_MRC_DOM1_RGD_NSE_BIT3_MASK)

#define TRDC_MRC_DOM1_RGD_NSE_BIT4_MASK          (0x10U)
#define TRDC_MRC_DOM1_RGD_NSE_BIT4_SHIFT         (4U)
/*! BIT4 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM1_RGD_NSE_BIT4(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM1_RGD_NSE_BIT4_SHIFT)) & TRDC_MRC_DOM1_RGD_NSE_BIT4_MASK)

#define TRDC_MRC_DOM1_RGD_NSE_BIT5_MASK          (0x20U)
#define TRDC_MRC_DOM1_RGD_NSE_BIT5_SHIFT         (5U)
/*! BIT5 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM1_RGD_NSE_BIT5(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM1_RGD_NSE_BIT5_SHIFT)) & TRDC_MRC_DOM1_RGD_NSE_BIT5_MASK)

#define TRDC_MRC_DOM1_RGD_NSE_BIT6_MASK          (0x40U)
#define TRDC_MRC_DOM1_RGD_NSE_BIT6_SHIFT         (6U)
/*! BIT6 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM1_RGD_NSE_BIT6(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM1_RGD_NSE_BIT6_SHIFT)) & TRDC_MRC_DOM1_RGD_NSE_BIT6_MASK)

#define TRDC_MRC_DOM1_RGD_NSE_BIT7_MASK          (0x80U)
#define TRDC_MRC_DOM1_RGD_NSE_BIT7_SHIFT         (7U)
/*! BIT7 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM1_RGD_NSE_BIT7(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM1_RGD_NSE_BIT7_SHIFT)) & TRDC_MRC_DOM1_RGD_NSE_BIT7_MASK)
/*! @} */

/* The count of TRDC_MRC_DOM1_RGD_NSE */
#define TRDC_MRC_DOM1_RGD_NSE_COUNT              (1U)

/*! @name MRC_DOM2_RGD_W - MRC Region Descriptor Word 0..MRC Region Descriptor Word 1 */
/*! @{ */

#define TRDC_MRC_DOM2_RGD_W_MRACSEL_MASK         (0x7U)
#define TRDC_MRC_DOM2_RGD_W_MRACSEL_SHIFT        (0U)
/*! MRACSEL - Memory Region Access Control Select
 *  0b000..Select MRC_GLBAC0 access control policy
 *  0b001..Select MRC_GLBAC1 access control policy
 *  0b010..Select MRC_GLBAC2 access control policy
 *  0b011..Select MRC_GLBAC3 access control policy
 *  0b100..Select MRC_GLBAC4 access control policy
 *  0b101..Select MRC_GLBAC5 access control policy
 *  0b110..Select MRC_GLBAC6 access control policy
 *  0b111..Select MRC_GLBAC7 access control policy
 */
#define TRDC_MRC_DOM2_RGD_W_MRACSEL(x)           (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM2_RGD_W_MRACSEL_SHIFT)) & TRDC_MRC_DOM2_RGD_W_MRACSEL_MASK)

#define TRDC_MRC_DOM2_RGD_W_VLD_MASK             (0x1U)
#define TRDC_MRC_DOM2_RGD_W_VLD_SHIFT            (0U)
/*! VLD - Valid */
#define TRDC_MRC_DOM2_RGD_W_VLD(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM2_RGD_W_VLD_SHIFT)) & TRDC_MRC_DOM2_RGD_W_VLD_MASK)

#define TRDC_MRC_DOM2_RGD_W_NSE_MASK             (0x10U)
#define TRDC_MRC_DOM2_RGD_W_NSE_SHIFT            (4U)
/*! NSE - NonSecure Enable
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in this register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in this register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM2_RGD_W_NSE(x)               (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM2_RGD_W_NSE_SHIFT)) & TRDC_MRC_DOM2_RGD_W_NSE_MASK)

#define TRDC_MRC_DOM2_RGD_W_END_ADDR_MASK        (0xFFFFF000U)
#define TRDC_MRC_DOM2_RGD_W_END_ADDR_SHIFT       (12U)
/*! END_ADDR - End Address */
#define TRDC_MRC_DOM2_RGD_W_END_ADDR(x)          (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM2_RGD_W_END_ADDR_SHIFT)) & TRDC_MRC_DOM2_RGD_W_END_ADDR_MASK)

#define TRDC_MRC_DOM2_RGD_W_STRT_ADDR_MASK       (0xFFFFF000U)
#define TRDC_MRC_DOM2_RGD_W_STRT_ADDR_SHIFT      (12U)
/*! STRT_ADDR - Start Address */
#define TRDC_MRC_DOM2_RGD_W_STRT_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM2_RGD_W_STRT_ADDR_SHIFT)) & TRDC_MRC_DOM2_RGD_W_STRT_ADDR_MASK)
/*! @} */

/* The count of TRDC_MRC_DOM2_RGD_W */
#define TRDC_MRC_DOM2_RGD_W_COUNT                (1U)

/* The count of TRDC_MRC_DOM2_RGD_W */
#define TRDC_MRC_DOM2_RGD_W_COUNT2               (8U)

/* The count of TRDC_MRC_DOM2_RGD_W */
#define TRDC_MRC_DOM2_RGD_W_COUNT3               (2U)

/*! @name MRC_DOM2_RGD_NSE - MRC Region Descriptor NonSecure Enable */
/*! @{ */

#define TRDC_MRC_DOM2_RGD_NSE_BIT0_MASK          (0x1U)
#define TRDC_MRC_DOM2_RGD_NSE_BIT0_SHIFT         (0U)
/*! BIT0 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM2_RGD_NSE_BIT0(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM2_RGD_NSE_BIT0_SHIFT)) & TRDC_MRC_DOM2_RGD_NSE_BIT0_MASK)

#define TRDC_MRC_DOM2_RGD_NSE_BIT1_MASK          (0x2U)
#define TRDC_MRC_DOM2_RGD_NSE_BIT1_SHIFT         (1U)
/*! BIT1 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM2_RGD_NSE_BIT1(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM2_RGD_NSE_BIT1_SHIFT)) & TRDC_MRC_DOM2_RGD_NSE_BIT1_MASK)

#define TRDC_MRC_DOM2_RGD_NSE_BIT2_MASK          (0x4U)
#define TRDC_MRC_DOM2_RGD_NSE_BIT2_SHIFT         (2U)
/*! BIT2 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM2_RGD_NSE_BIT2(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM2_RGD_NSE_BIT2_SHIFT)) & TRDC_MRC_DOM2_RGD_NSE_BIT2_MASK)

#define TRDC_MRC_DOM2_RGD_NSE_BIT3_MASK          (0x8U)
#define TRDC_MRC_DOM2_RGD_NSE_BIT3_SHIFT         (3U)
/*! BIT3 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM2_RGD_NSE_BIT3(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM2_RGD_NSE_BIT3_SHIFT)) & TRDC_MRC_DOM2_RGD_NSE_BIT3_MASK)

#define TRDC_MRC_DOM2_RGD_NSE_BIT4_MASK          (0x10U)
#define TRDC_MRC_DOM2_RGD_NSE_BIT4_SHIFT         (4U)
/*! BIT4 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM2_RGD_NSE_BIT4(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM2_RGD_NSE_BIT4_SHIFT)) & TRDC_MRC_DOM2_RGD_NSE_BIT4_MASK)

#define TRDC_MRC_DOM2_RGD_NSE_BIT5_MASK          (0x20U)
#define TRDC_MRC_DOM2_RGD_NSE_BIT5_SHIFT         (5U)
/*! BIT5 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM2_RGD_NSE_BIT5(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM2_RGD_NSE_BIT5_SHIFT)) & TRDC_MRC_DOM2_RGD_NSE_BIT5_MASK)

#define TRDC_MRC_DOM2_RGD_NSE_BIT6_MASK          (0x40U)
#define TRDC_MRC_DOM2_RGD_NSE_BIT6_SHIFT         (6U)
/*! BIT6 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM2_RGD_NSE_BIT6(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM2_RGD_NSE_BIT6_SHIFT)) & TRDC_MRC_DOM2_RGD_NSE_BIT6_MASK)

#define TRDC_MRC_DOM2_RGD_NSE_BIT7_MASK          (0x80U)
#define TRDC_MRC_DOM2_RGD_NSE_BIT7_SHIFT         (7U)
/*! BIT7 - Bit n NonSecure Enable [n = 0 - 15]
 *  0b0..Secure accesses to region r are not allowed, nonsecure accesses to region r are based on corresponding
 *       MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 *  0b1..Secure accesses to region r are are not allowed, nonsecure accesses to region r are based on
 *       corresponding MRACSEL field in register (MRCm_DOMd_RGDr_Ww[MRACSEL]).
 */
#define TRDC_MRC_DOM2_RGD_NSE_BIT7(x)            (((uint32_t)(((uint32_t)(x)) << TRDC_MRC_DOM2_RGD_NSE_BIT7_SHIFT)) & TRDC_MRC_DOM2_RGD_NSE_BIT7_MASK)
/*! @} */

/* The count of TRDC_MRC_DOM2_RGD_NSE */
#define TRDC_MRC_DOM2_RGD_NSE_COUNT              (1U)


/*!
 * @}
 */ /* end of group TRDC_Register_Masks */


/*!
 * @}
 */ /* end of group TRDC_Peripheral_Access_Layer */


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


#endif  /* PERI_TRDC_H_ */

