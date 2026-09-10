/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_TRDC_SOC_H_
#define _FSL_TRDC_SOC_H_

#include "fsl_common.h"

/*!
 * @addtogroup trdc_soc
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*@{*/
/*! @brief Driver version 2.0.0. */
#define FSL_TRDC_SOC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

#define TRDC_MBC_BLK(trdcInst, mbcInst, slvIdx, blkIdx) ((blkIdx) | ((slvIdx) << 8U) | ((mbcInst) << 16U) | (trdcInst << 24U))
/*!@brief Gets which TRDC instance does this MBC block belongs to. */
#define TRDC_MBC_GetTRDCInst(mbcBlk) (((mbcBlk) >> 24U) & 0xFFU)
/*!@brief Gets which MBC index does this MBC block belongs to. */
#define TRDC_MBC_GetMBCIdx(mbcBlk) (((mbcBlk) >> 16U) & 0xFFU)
/*!@brief Gets which slave index does this MBC block belongs to. */
#define TRDC_MBC_GetSlvIdx(mbcBlk) (((mbcBlk) >> 8U) & 0xFFU)
/*!@brief Gets which memory block index does this MBC block belongs to. */
#define TRDC_MBC_GetBlkIdx(mbcBlk) ((mbcBlk) & 0xFFU)

/*!
 * @brief Enumeration for TRDC master mapping
 *
 * Defines the enumeration for TRDC master resource collections.
 */
typedef enum _trdc_master
{
    kTRDC_MAIN_MasterEDMA5Ch0_1    = 0U,
    kTRDC_MAIN_MasterEDMA5Ch2_3    = 1U,
    kTRDC_MAIN_MasterEDMA5Ch4_5    = 2U,
    kTRDC_MAIN_MasterEDMA5Ch6_7    = 3U,
    kTRDC_MAIN_MasterEDMA5Ch8_9    = 4U,
    kTRDC_MAIN_MasterEDMA5Ch10_11  = 5U,
    kTRDC_MAIN_MasterEDMA5Ch12_13  = 6U,
    kTRDC_MAIN_MasterEDMA5Ch14_15  = 7U,
    kTRDC_MAIN_MasterMEDMA3Ch0_1   = 8U,
    kTRDC_MAIN_MasterMEDMA3Ch2_3   = 9U,
    kTRDC_MAIN_MasterMEDMA3Ch4_5   = 10U,
    kTRDC_MAIN_MasterMEDMA3Ch6_7   = 11U,
    kTRDC_MAIN_MasterMEDMA3Ch8_9   = 12U,
    kTRDC_MAIN_MasterMEDMA3Ch10_11 = 13U,
    kTRDC_MAIN_MasterMEDMA3Ch12_13 = 14U,
    kTRDC_MAIN_MasterMEDMA3Ch14_15 = 15U,
    kTRDC_MAIN_MasterMEDMA3Ch16_17 = 16U,
    kTRDC_MAIN_MasterMEDMA3Ch18_19 = 17U,
    kTRDC_MAIN_MasterMEDMA3Ch20_21 = 18U,
    kTRDC_MAIN_MasterMEDMA3Ch22_23 = 19U,
    kTRDC_MAIN_MasterMEDMA3Ch24_25 = 20U,
    kTRDC_MAIN_MasterMEDMA3Ch26_27 = 21U,
    kTRDC_MAIN_MasterMEDMA3Ch28_29 = 22U,
    kTRDC_MAIN_MasterMEDMA3Ch30_31 = 23U,
    kTRDC_MAIN_MasterReserved0     = 24U,
    kTRDC_MAIN_MasterReserved1     = 25U,
    kTRDC_MAIN_MasterDAP_AHBP      = 26U,
    kTRDC_MAIN_MasterETR           = 27U,
    kTRDC_MAIN_MasterReserved2     = 28U,
    kTRDC_MAIN_MasterReserved3     = 29U,
    kTRDC_MAIN_MasterWAKE_SS       = 30U,
    kTRDC_MAIN_MasterReserved4     = 31U,
    kTRDC_MAIN_MasterMTR           = 32U,
    kTRDC_MAIN_MasterTESTPORT      = 33U,

    kTRDC_CMPT_MasterCPU0_AXIM = 0U,
    kTRDC_CMPT_MasterCPU0_AHBP = 1U,
    kTRDC_CMPT_MasterReserved0 = 2U,
    kTRDC_CMPT_MasterReserved1 = 3U,
    kTRDC_CMPT_MasterLLC_RD    = 4U,
    kTRDC_CMPT_MasterLLC_WR    = 5U,
    kTRDC_CMPT_MasterNPU       = 6U,

    kTRDC_WAKE_MasterWEDMA3Ch0_1 = 0U,
    kTRDC_WAKE_MasterWEDMA3Ch0_2 = 1U,
    kTRDC_WAKE_MasterWEDMA3Ch0_3 = 2U,
    kTRDC_WAKE_MasterWEDMA3Ch0_4 = 3U,

    kTRDC_AUDIO_MasterAEDMA3Ch0_1 = 0U,
    kTRDC_AUDIO_MasterAEDMA3Ch0_2 = 1U,
    kTRDC_AUDIO_MasterAEDMA3Ch0_3 = 2U,
    kTRDC_AUDIO_MasterAEDMA3Ch0_4 = 3U,

    kTRDC_COMM_MasterSDHC0     = 0U,
    kTRDC_COMM_MasterSDHC1     = 1U,
    kTRDC_COMM_MasterUSB0      = 2U,
    kTRDC_COMM_MasterUSB1      = 3U,
    kTRDC_COMM_MasterENET0     = 4U,
    kTRDC_COMM_MasterENET1_M0R = 5U,
    kTRDC_COMM_MasterENET1_M0T = 6U,
    kTRDC_COMM_MasterXSPI_RESP = 7U,

    kTRDC_MEDIA_MasterDCIFLayer0 = 0U,
    kTRDC_MEDIA_MasterDCIFLayer1 = 1U,
    kTRDC_MEDIA_MasterDCIFLayer2 = 2U,
    kTRDC_MEDIA_MasterDCIFLayer3 = 3U,
    kTRDC_MEDIA_MasterDCIFLayer4 = 4U,
    kTRDC_MEDIA_MasterDCIFLayer5 = 5U,
    kTRDC_MEDIA_MasterDCIFLayer6 = 6U,
    kTRDC_MEDIA_MasterDCIFLayer7 = 7U,
    kTRDC_MEDIA_MasterISI        = 8U,
    kTRDC_MEDIA_MasterISI_U      = 9U,
    kTRDC_MEDIA_MasterISI_V      = 10U,
    kTRDC_MEDIA_MasterCSI        = 11U,
    kTRDC_MEDIA_MasterGPU_DMA    = 12U,
    kTRDC_MEDIA_MasterGPU_CCD    = 13U,
    kTRDC_MEDIA_MasterJPEG       = 14U,
} trdc_master_t;

/*!
 * @brief Enumeration for TRDC MRC mapping
 *
 * Defines the enumeration for TRDC MRC (Memory Region Controller) mapping.
 */
typedef enum _trdc_mrc
{
    kTRDC_MAIN_MrcXSPI0     = 0U,
    kTRDC_MAIN_MrcXSPI1     = 1U,
    kTRDC_MAIN_MrcSRAMC     = 2U,

    kTRDC_CMPT_MrcSRAM0_1_2 = 0U,
    kTRDC_CMPT_MrcCPU0_TCM  = 1U,
    kTRDC_CMPT_MrcROM       = 2U,
    kTRDC_CMPT_MrcNPU_TCM   = 3U,
    kTRDC_CMPT_MrcLLC       = 4U,
} trdc_mrc_t;

/*!
 * @brief Enumeration for TRDC MBC mapping
 *
 * Defines the enumeration for TRDC MBC (Memory Blocker Checker) mapping.
 * User Can use @ref TRDC_MBC_GetTRDCInst, @ref TRDC_MBC_GetMBCInst,
 * @ref TRDC_MBC_GetSlvIdx and @ref TRDC_MBC_GetBlkIdx to get details
 * about each block.
 */
typedef enum _trdc_mbc_block {
    // CMPT_TRDC.MBC[0][0], trdcInst = 0, mbcInst = 0, slvIdx = 0
    kTRDC_CMPT_MBC_MODCON            = TRDC_MBC_BLK(0, 0, 0, 0),    /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 0 */
    kTRDC_CMPT_MBC_MTR               = TRDC_MBC_BLK(0, 0, 0, 2),    /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 2 */
    kTRDC_CMPT_MBC_TCU               = TRDC_MBC_BLK(0, 0, 0, 3),    /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 3 */
    kTRDC_CMPT_MBC_TRDC_MGR          = TRDC_MBC_BLK(0, 0, 0, 4),    /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 4 */
    kTRDC_CMPT_MBC_TRDC_MC           = TRDC_MBC_BLK(0, 0, 0, 5),    /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 5 */
    kTRDC_CMPT_MBC_CCM               = TRDC_MBC_BLK(0, 0, 0, 6),    /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 6 */
    kTRDC_CMPT_MBC_SRAMCTL0          = TRDC_MBC_BLK(0, 0, 0, 8),    /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 8 */
    kTRDC_CMPT_MBC_SRAMCTL1          = TRDC_MBC_BLK(0, 0, 0, 9),    /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 9 */
    kTRDC_CMPT_MBC_SRAMCTL2          = TRDC_MBC_BLK(0, 0, 0, 10),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 10 */
    kTRDC_CMPT_MBC_SRAMCTL3          = TRDC_MBC_BLK(0, 0, 0, 11),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 11 */
    kTRDC_CMPT_MBC_SRAMCTL4          = TRDC_MBC_BLK(0, 0, 0, 12),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 12 */
    kTRDC_CMPT_MBC_SRAMCTL5          = TRDC_MBC_BLK(0, 0, 0, 13),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 13 */
    kTRDC_CMPT_MBC_SRAMCTL6          = TRDC_MBC_BLK(0, 0, 0, 14),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 14 */
    kTRDC_CMPT_MBC_SRAMCTL7          = TRDC_MBC_BLK(0, 0, 0, 15),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 15 */
    kTRDC_CMPT_MBC_SRAMCTL8          = TRDC_MBC_BLK(0, 0, 0, 16),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 16 */
    kTRDC_CMPT_MBC_SRAMCTL9          = TRDC_MBC_BLK(0, 0, 0, 17),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 17 */
    kTRDC_CMPT_MBC_SRAMCTL10         = TRDC_MBC_BLK(0, 0, 0, 18),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 18 */
    kTRDC_CMPT_MBC_SRAMCTL11         = TRDC_MBC_BLK(0, 0, 0, 19),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 19 */
    kTRDC_CMPT_MBC_SRAMCTL12         = TRDC_MBC_BLK(0, 0, 0, 20),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 20 */
    kTRDC_CMPT_MBC_SRAMCTL13         = TRDC_MBC_BLK(0, 0, 0, 21),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 21 */
    kTRDC_CMPT_MBC_SRAMCTL14         = TRDC_MBC_BLK(0, 0, 0, 22),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 22 */
    kTRDC_CMPT_MBC_SRAMCTL15         = TRDC_MBC_BLK(0, 0, 0, 23),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 23 */
    kTRDC_CMPT_MBC_LLC               = TRDC_MBC_BLK(0, 0, 0, 26),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 26 */
    kTRDC_CMPT_MBC_ROMCP             = TRDC_MBC_BLK(0, 0, 0, 27),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 27 */
    kTRDC_CMPT_MBC_NPU               = TRDC_MBC_BLK(0, 0, 0, 28),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 28 */
    kTRDC_CMPT_MBC_FREQME            = TRDC_MBC_BLK(0, 0, 0, 29),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 29 */
    kTRDC_CMPT_MBC_FREQME_MUX        = TRDC_MBC_BLK(0, 0, 0, 30),   /*!< CMPT_TRDC MBC0 Slave 0 Block Idx 30 */

    // CMPT_TRDC.MBC[0][1], trdcInst = 0, mbcInst = 0, slvIdx = 1
    kTRDC_CMPT_MBC_NIC_GPV           = TRDC_MBC_BLK(0, 0, 1, 0),    /*!< CMPT_TRDC MBC0 Slave 1 Block Idx 0 */
    
    // MAIN_MBC0_0, trdcInst = 1, mbcInst = 0, slvIdx = 0
    kTRDC_MAIN_MBC_MODCON            = TRDC_MBC_BLK(1, 0, 0, 0),    /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 0 */
    kTRDC_MAIN_MBC_MTR               = TRDC_MBC_BLK(1, 0, 0, 2),    /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 2 */
    kTRDC_MAIN_MBC_TCU               = TRDC_MBC_BLK(1, 0, 0, 3),    /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 3 */
    kTRDC_MAIN_MBC_TRDC_MGR          = TRDC_MBC_BLK(1, 0, 0, 4),    /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 4 */
    kTRDC_MAIN_MBC_TRDC_MC           = TRDC_MBC_BLK(1, 0, 0, 5),    /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 5 */
    kTRDC_MAIN_MBC_CCM               = TRDC_MBC_BLK(1, 0, 0, 6),    /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 6 */
    kTRDC_MAIN_MBC_AHB_SRAMC         = TRDC_MBC_BLK(1, 0, 0, 8),    /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 8 */
    kTRDC_MAIN_MBC_AXBS              = TRDC_MBC_BLK(1, 0, 0, 9),    /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 9 */
    kTRDC_MAIN_MBC_XBIC              = TRDC_MBC_BLK(1, 0, 0, 12),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 12 */
    kTRDC_MAIN_MBC_XBIC_TDBG         = TRDC_MBC_BLK(1, 0, 0, 13),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 13 */
    kTRDC_MAIN_MBC_EDMA3             = TRDC_MBC_BLK(1, 0, 0, 14),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 14 */
    kTRDC_MAIN_MBC_eDMA3_TCD0        = TRDC_MBC_BLK(1, 0, 0, 15),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 15 */
    kTRDC_MAIN_MBC_eDMA3_TCD1        = TRDC_MBC_BLK(1, 0, 0, 16),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 16 */
    kTRDC_MAIN_MBC_eDMA3_TCD2        = TRDC_MBC_BLK(1, 0, 0, 17),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 17 */
    kTRDC_MAIN_MBC_eDMA3_TCD3        = TRDC_MBC_BLK(1, 0, 0, 18),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 18 */
    kTRDC_MAIN_MBC_eDMA3_TCD4        = TRDC_MBC_BLK(1, 0, 0, 19),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 19 */
    kTRDC_MAIN_MBC_eDMA3_TCD5        = TRDC_MBC_BLK(1, 0, 0, 20),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 20 */
    kTRDC_MAIN_MBC_eDMA3_TCD6        = TRDC_MBC_BLK(1, 0, 0, 21),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 21 */
    kTRDC_MAIN_MBC_eDMA3_TCD7        = TRDC_MBC_BLK(1, 0, 0, 22),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 22 */
    kTRDC_MAIN_MBC_eDMA3_TCD8        = TRDC_MBC_BLK(1, 0, 0, 23),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 23 */
    kTRDC_MAIN_MBC_eDMA3_TCD9        = TRDC_MBC_BLK(1, 0, 0, 24),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 24 */
    kTRDC_MAIN_MBC_eDMA3_TCD10       = TRDC_MBC_BLK(1, 0, 0, 25),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 25 */
    kTRDC_MAIN_MBC_eDMA3_TCD11       = TRDC_MBC_BLK(1, 0, 0, 26),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 26 */
    kTRDC_MAIN_MBC_eDMA3_TCD12       = TRDC_MBC_BLK(1, 0, 0, 27),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 27 */
    kTRDC_MAIN_MBC_eDMA3_TCD13       = TRDC_MBC_BLK(1, 0, 0, 28),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 28 */
    kTRDC_MAIN_MBC_eDMA3_TCD14       = TRDC_MBC_BLK(1, 0, 0, 29),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 29 */
    kTRDC_MAIN_MBC_eDMA3_TCD15       = TRDC_MBC_BLK(1, 0, 0, 30),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 30 */
    kTRDC_MAIN_MBC_eDMA3_TCD16       = TRDC_MBC_BLK(1, 0, 0, 31),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 31 */
    kTRDC_MAIN_MBC_eDMA3_TCD17       = TRDC_MBC_BLK(1, 0, 0, 32),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 32 */
    kTRDC_MAIN_MBC_eDMA3_TCD18       = TRDC_MBC_BLK(1, 0, 0, 33),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 33 */
    kTRDC_MAIN_MBC_eDMA3_TCD19       = TRDC_MBC_BLK(1, 0, 0, 34),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 34 */
    kTRDC_MAIN_MBC_eDMA3_TCD20       = TRDC_MBC_BLK(1, 0, 0, 35),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 35 */
    kTRDC_MAIN_MBC_eDMA3_TCD21       = TRDC_MBC_BLK(1, 0, 0, 36),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 36 */
    kTRDC_MAIN_MBC_eDMA3_TCD22       = TRDC_MBC_BLK(1, 0, 0, 37),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 37 */
    kTRDC_MAIN_MBC_eDMA3_TCD23       = TRDC_MBC_BLK(1, 0, 0, 38),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 38 */
    kTRDC_MAIN_MBC_eDMA3_TCD24       = TRDC_MBC_BLK(1, 0, 0, 39),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 39 */
    kTRDC_MAIN_MBC_eDMA3_TCD25       = TRDC_MBC_BLK(1, 0, 0, 40),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 40 */
    kTRDC_MAIN_MBC_eDMA3_TCD26       = TRDC_MBC_BLK(1, 0, 0, 41),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 41 */
    kTRDC_MAIN_MBC_eDMA3_TCD27       = TRDC_MBC_BLK(1, 0, 0, 42),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 42 */
    kTRDC_MAIN_MBC_eDMA3_TCD28       = TRDC_MBC_BLK(1, 0, 0, 43),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 43 */
    kTRDC_MAIN_MBC_eDMA3_TCD29       = TRDC_MBC_BLK(1, 0, 0, 44),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 44 */
    kTRDC_MAIN_MBC_eDMA3_TCD30       = TRDC_MBC_BLK(1, 0, 0, 45),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 45 */
    kTRDC_MAIN_MBC_eDMA3_TCD31       = TRDC_MBC_BLK(1, 0, 0, 46),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 46 */
    kTRDC_MAIN_MBC_EDMA5             = TRDC_MBC_BLK(1, 0, 0, 48),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 48 */
    kTRDC_MAIN_MBC_eDMA5_TCD0        = TRDC_MBC_BLK(1, 0, 0, 49),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 49 */
    kTRDC_MAIN_MBC_eDMA5_TCD1        = TRDC_MBC_BLK(1, 0, 0, 50),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 50 */
    kTRDC_MAIN_MBC_eDMA5_TCD2        = TRDC_MBC_BLK(1, 0, 0, 51),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 51 */
    kTRDC_MAIN_MBC_eDMA5_TCD3        = TRDC_MBC_BLK(1, 0, 0, 52),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 52 */
    kTRDC_MAIN_MBC_eDMA5_TCD4        = TRDC_MBC_BLK(1, 0, 0, 53),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 53 */
    kTRDC_MAIN_MBC_eDMA5_TCD5        = TRDC_MBC_BLK(1, 0, 0, 54),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 54 */
    kTRDC_MAIN_MBC_eDMA5_TCD6        = TRDC_MBC_BLK(1, 0, 0, 55),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 55 */
    kTRDC_MAIN_MBC_eDMA5_TCD7        = TRDC_MBC_BLK(1, 0, 0, 56),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 56 */
    kTRDC_MAIN_MBC_eDMA5_TCD8        = TRDC_MBC_BLK(1, 0, 0, 57),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 57 */
    kTRDC_MAIN_MBC_eDMA5_TCD9        = TRDC_MBC_BLK(1, 0, 0, 58),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 58 */
    kTRDC_MAIN_MBC_eDMA5_TCD10       = TRDC_MBC_BLK(1, 0, 0, 59),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 59 */
    kTRDC_MAIN_MBC_eDMA5_TCD11       = TRDC_MBC_BLK(1, 0, 0, 60),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 60 */
    kTRDC_MAIN_MBC_eDMA5_TCD12       = TRDC_MBC_BLK(1, 0, 0, 61),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 61 */
    kTRDC_MAIN_MBC_eDMA5_TCD13       = TRDC_MBC_BLK(1, 0, 0, 62),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 62 */
    kTRDC_MAIN_MBC_eDMA5_TCD14       = TRDC_MBC_BLK(1, 0, 0, 63),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 63 */
    kTRDC_MAIN_MBC_eDMA5_TCD15       = TRDC_MBC_BLK(1, 0, 0, 64),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 64 */
    kTRDC_MAIN_MBC_FREQME            = TRDC_MBC_BLK(1, 0, 0, 65),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 65 */
    kTRDC_MAIN_MBC_FREQME_MUX        = TRDC_MBC_BLK(1, 0, 0, 66),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 66 */
    kTRDC_MAIN_MBC_XECC0             = TRDC_MBC_BLK(1, 0, 0, 67),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 67 */
    kTRDC_MAIN_MBC_XECC1             = TRDC_MBC_BLK(1, 0, 0, 68),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 68 */
    kTRDC_MAIN_MBC_XECC2             = TRDC_MBC_BLK(1, 0, 0, 69),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 69 */
    kTRDC_MAIN_MBC_XSPI0             = TRDC_MBC_BLK(1, 0, 0, 70),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 70 */
    kTRDC_MAIN_MBC_XSPI1             = TRDC_MBC_BLK(1, 0, 0, 71),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 71 */
    kTRDC_MAIN_MBC_XSPI2             = TRDC_MBC_BLK(1, 0, 0, 72),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 72 */
    kTRDC_MAIN_MBC_MMU0              = TRDC_MBC_BLK(1, 0, 0, 73),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 73 */
    kTRDC_MAIN_MBC_CP                = TRDC_MBC_BLK(1, 0, 0, 75),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 75 */
    kTRDC_MAIN_MBC_PVTM              = TRDC_MBC_BLK(1, 0, 0, 76),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 76 */
    kTRDC_MAIN_MBC_MTR_MSTR          = TRDC_MBC_BLK(1, 0, 0, 77),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 77 */
    kTRDC_MAIN_MBC_CGUANA            = TRDC_MBC_BLK(1, 0, 0, 80),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 80 */
    kTRDC_MAIN_MBC_CGUDIG            = TRDC_MBC_BLK(1, 0, 0, 81),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 81 */
    kTRDC_MAIN_MBC_PMU_CSR           = TRDC_MBC_BLK(1, 0, 0, 82),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 82 */
    kTRDC_MAIN_MBC_SYSCON_RESETCON   = TRDC_MBC_BLK(1, 0, 0, 83),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 83 */
    kTRDC_MAIN_MBC_SYSCON_POWERCON   = TRDC_MBC_BLK(1, 0, 0, 84),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 84 */
    kTRDC_MAIN_MBC_SYSCON_PDCON      = TRDC_MBC_BLK(1, 0, 0, 85),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 85 */
    kTRDC_MAIN_MBC_SYSCON_MEMCON     = TRDC_MBC_BLK(1, 0, 0, 86),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 86 */
    kTRDC_MAIN_MBC_SYSCON_MTR        = TRDC_MBC_BLK(1, 0, 0, 87),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 87 */
    kTRDC_MAIN_MBC_SYSCON_TCU        = TRDC_MBC_BLK(1, 0, 0, 88),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 88 */
    kTRDC_MAIN_MBC_SYSCON_FREQME     = TRDC_MBC_BLK(1, 0, 0, 89),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 89 */
    kTRDC_MAIN_MBC_SYSCON_FREQME_MUX = TRDC_MBC_BLK(1, 0, 0, 90),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 90 */
    kTRDC_MAIN_MBC_CSSI_FSB          = TRDC_MBC_BLK(1, 0, 0, 96),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 96 */
    kTRDC_MAIN_MBC_CSSI_MU0A         = TRDC_MBC_BLK(1, 0, 0, 97),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 97 */
    kTRDC_MAIN_MBC_CSSI_MU1A         = TRDC_MBC_BLK(1, 0, 0, 98),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 98 */
    kTRDC_MAIN_MBC_CSSI_MU2A         = TRDC_MBC_BLK(1, 0, 0, 99),   /*!< MAIN_TRDC MBC0 Slave 0 Block Idx 99 */

    // MAIN_TRDC.MBC[0][1], trdcInst = 1, mbcInst = 0, slvIdx = 1
    kTRDC_MAIN_MBC_NIC_GPV           = TRDC_MBC_BLK(1, 0, 1, 0),    /*!< MAIN_TRDC MBC0 Slave 1 Block Idx 0 */

    // MAIN_TRDC.MBC[0][2], trdcInst = 1, mbcInst = 0, slvIdx = 2
    kTRDC_MAIN_MBC_DBGMB             = TRDC_MBC_BLK(1, 0, 2, 0),    /*!< MAIN_TRDC MBC0 Slave 2 Block Idx 0 */

    // MAIN_TRDC.MBC[0][3], trdcInst = 1, mbcInst = 0, slvIdx = 3
    kTRDC_MAIN_MBC_CORESIGHT         = TRDC_MBC_BLK(1, 0, 3, 0),

    // MAIN_TRDC.MBC[1][0], trdcInst = 1, mbcInst = 1, slvIdx = 0
    kTRDC_MAIN_MBC_HSP_EVTG0         = TRDC_MBC_BLK(1, 1, 0, 0),    /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 0 */
    kTRDC_MAIN_MBC_HSP_EVTG1         = TRDC_MBC_BLK(1, 1, 0, 1),    /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 1 */
    kTRDC_MAIN_MBC_HSP_MUA0          = TRDC_MBC_BLK(1, 1, 0, 2),    /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 2 */
    kTRDC_MAIN_MBC_HSP_MUB0          = TRDC_MBC_BLK(1, 1, 0, 3),    /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 3 */
    kTRDC_MAIN_MBC_HSP_SEMA42        = TRDC_MBC_BLK(1, 1, 0, 4),    /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 4 */
    kTRDC_MAIN_MBC_HSP_ADC0          = TRDC_MBC_BLK(1, 1, 0, 5),    /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 5 */
    kTRDC_MAIN_MBC_HSP_DAC           = TRDC_MBC_BLK(1, 1, 0, 6),    /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 6 */
    kTRDC_MAIN_MBC_HSP_LPIT0         = TRDC_MBC_BLK(1, 1, 0, 7),    /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 7 */
    kTRDC_MAIN_MBC_HSP_EFLEXPWM0     = TRDC_MBC_BLK(1, 1, 0, 8),    /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 8 */
    kTRDC_MAIN_MBC_HSP_EFLEXPWM1     = TRDC_MBC_BLK(1, 1, 0, 9),    /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 9 */
    kTRDC_MAIN_MBC_HSP_QUADTPM       = TRDC_MBC_BLK(1, 1, 0, 10),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 10 */
    kTRDC_MAIN_MBC_HSP_QUADTPM1      = TRDC_MBC_BLK(1, 1, 0, 11),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 11 */
    kTRDC_MAIN_MBC_HSP_QDEC0         = TRDC_MBC_BLK(1, 1, 0, 12),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 12 */
    kTRDC_MAIN_MBC_HSP_QDEC1         = TRDC_MBC_BLK(1, 1, 0, 13),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 13 */
    kTRDC_MAIN_MBC_HSP_SINC0         = TRDC_MBC_BLK(1, 1, 0, 14),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 14 */
    kTRDC_MAIN_MBC_HSP_FLEXCAN0      = TRDC_MBC_BLK(1, 1, 0, 15),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 15 */
    kTRDC_MAIN_MBC_HSP_FLEXCAN1      = TRDC_MBC_BLK(1, 1, 0, 16),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 16 */
    kTRDC_MAIN_MBC_HSP_FlexIO0       = TRDC_MBC_BLK(1, 1, 0, 17),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 17 */
    kTRDC_MAIN_MBC_HSP_FlexIO1       = TRDC_MBC_BLK(1, 1, 0, 18),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 18 */
    kTRDC_MAIN_MBC_HSP_I3C           = TRDC_MBC_BLK(1, 1, 0, 19),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 19 */
    kTRDC_MAIN_MBC_HSP_LPI2C0        = TRDC_MBC_BLK(1, 1, 0, 20),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 20 */
    kTRDC_MAIN_MBC_WAKE_LPI2C2       = TRDC_MBC_BLK(1, 1, 0, 21),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 21 */
    kTRDC_MAIN_MBC_HSP_LPSPI0        = TRDC_MBC_BLK(1, 1, 0, 22),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 22 */
    kTRDC_MAIN_MBC_HSP_LPSPI1        = TRDC_MBC_BLK(1, 1, 0, 23),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 23 */
    kTRDC_MAIN_MBC_HSP_LPSPI2        = TRDC_MBC_BLK(1, 1, 0, 24),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 24 */
    kTRDC_MAIN_MBC_HSP_LPUART0       = TRDC_MBC_BLK(1, 1, 0, 25),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 25 */
    kTRDC_MAIN_MBC_HSP_LPUART1       = TRDC_MBC_BLK(1, 1, 0, 26),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 26 */
    kTRDC_MAIN_MBC_HSP_LPUART2       = TRDC_MBC_BLK(1, 1, 0, 27),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 27 */
    kTRDC_MAIN_MBC_HSP_IOMUXC        = TRDC_MBC_BLK(1, 1, 0, 28),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 28 */
    kTRDC_MAIN_MBC_HSP_QTIMER0       = TRDC_MBC_BLK(1, 1, 0, 30),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 30 */
    kTRDC_MAIN_MBC_HSP_QTIMER1       = TRDC_MBC_BLK(1, 1, 0, 31),   /*!< MAIN_TRDC MBC1 Slave 0 Block Idx 31 */

    // MAIN_TRDC.MBC[1][1], trdcInst = 1, mbcInst = 1, slvIdx = 1
    kTRDC_MAIN_MBC_HSP_EVTG2         = TRDC_MBC_BLK(1, 1, 1, 0),    /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 0 */
    kTRDC_MAIN_MBC_HSP_EVTG3         = TRDC_MBC_BLK(1, 1, 1, 1),    /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 1 */
    kTRDC_MAIN_MBC_HSP_XBAR0         = TRDC_MBC_BLK(1, 1, 1, 2),    /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 2 */
    kTRDC_MAIN_MBC_HSP_XBAR1         = TRDC_MBC_BLK(1, 1, 1, 3),    /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 3 */
    kTRDC_MAIN_MBC_HSP_XBAR2         = TRDC_MBC_BLK(1, 1, 1, 4),    /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 4 */
    kTRDC_MAIN_MBC_HSP_ADC1          = TRDC_MBC_BLK(1, 1, 1, 5),    /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 5 */
    kTRDC_MAIN_MBC_HSP_LPIT1         = TRDC_MBC_BLK(1, 1, 1, 6),    /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 6 */
    kTRDC_MAIN_MBC_HSP_EFLEXPWM2     = TRDC_MBC_BLK(1, 1, 1, 7),    /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 7 */
    kTRDC_MAIN_MBC_HSP_EFLEXPWM3     = TRDC_MBC_BLK(1, 1, 1, 8),    /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 8 */
    kTRDC_MAIN_MBC_HSP_QUADTPM2      = TRDC_MBC_BLK(1, 1, 1, 9),    /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 9 */
    kTRDC_MAIN_MBC_HSP_QUADTPM3      = TRDC_MBC_BLK(1, 1, 1, 10),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 10 */
    kTRDC_MAIN_MBC_HSP_QUADTPM4      = TRDC_MBC_BLK(1, 1, 1, 11),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 11 */
    kTRDC_MAIN_MBC_HSP_QDEC2         = TRDC_MBC_BLK(1, 1, 1, 12),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 12 */
    kTRDC_MAIN_MBC_HSP_QDEC3         = TRDC_MBC_BLK(1, 1, 1, 13),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 13 */
    kTRDC_MAIN_MBC_HSP_SINC1         = TRDC_MBC_BLK(1, 1, 1, 14),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 14 */
    kTRDC_MAIN_MBC_HSP_FLEXCAN2      = TRDC_MBC_BLK(1, 1, 1, 15),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 15 */
    kTRDC_MAIN_MBC_HSP_FlexIO2       = TRDC_MBC_BLK(1, 1, 1, 16),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 16 */
    kTRDC_MAIN_MBC_HSP_LPI2C1        = TRDC_MBC_BLK(1, 1, 1, 17),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 17 */
    kTRDC_MAIN_MBC_HSP_LPI2C3        = TRDC_MBC_BLK(1, 1, 1, 18),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 18 */
    kTRDC_MAIN_MBC_HSP_LPSPI3        = TRDC_MBC_BLK(1, 1, 1, 19),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 19 */
    kTRDC_MAIN_MBC_HSP_LPSPI4        = TRDC_MBC_BLK(1, 1, 1, 20),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 20 */
    kTRDC_MAIN_MBC_HSP_LPUART3       = TRDC_MBC_BLK(1, 1, 1, 21),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 21 */
    kTRDC_MAIN_MBC_HSP_LPUART4       = TRDC_MBC_BLK(1, 1, 1, 22),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 22 */
    kTRDC_MAIN_MBC_HSP_LPUART5       = TRDC_MBC_BLK(1, 1, 1, 23),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 23 */
    kTRDC_MAIN_MBC_HSP_CRC           = TRDC_MBC_BLK(1, 1, 1, 24),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 24 */
    kTRDC_MAIN_MBC_HSP_TRGSYNC0      = TRDC_MBC_BLK(1, 1, 1, 25),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 25 */
    kTRDC_MAIN_MBC_HSP_TRGSYNC1      = TRDC_MBC_BLK(1, 1, 1, 26),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 26 */
    kTRDC_MAIN_MBC_HSP_STM           = TRDC_MBC_BLK(1, 1, 1, 27),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 27 */
    kTRDC_MAIN_MBC_HSP_QTIMER2       = TRDC_MBC_BLK(1, 1, 1, 30),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 30 */
    kTRDC_MAIN_MBC_HSP_QTIMER3       = TRDC_MBC_BLK(1, 1, 1, 31),   /*!< MAIN_TRDC MBC1 Slave 1 Block Idx 31 */

    // MAIN_TRDC.MBC[1][2], trdcInst = 1, mbcInst = 1, slvIdx = 2
    kTRDC_MAIN_MBC_GPIO0             = TRDC_MBC_BLK(1, 1, 2, 0),    /*!< MAIN_TRDC MBC1 Slave 2 Block Idx 0 */
    kTRDC_MAIN_MBC_GPIO1             = TRDC_MBC_BLK(1, 1, 2, 1),    /*!< MAIN_TRDC MBC1 Slave 2 Block Idx 1 */
    kTRDC_MAIN_MBC_GPIO2             = TRDC_MBC_BLK(1, 1, 2, 2),    /*!< MAIN_TRDC MBC1 Slave 2 Block Idx 2 */
    kTRDC_MAIN_MBC_GPIO3             = TRDC_MBC_BLK(1, 1, 2, 3),    /*!< MAIN_TRDC MBC1 Slave 2 Block Idx 3 */
    kTRDC_MAIN_MBC_GPIO4             = TRDC_MBC_BLK(1, 1, 2, 4),    /*!< MAIN_TRDC MBC1 Slave 2 Block Idx 4 */

    // COMM_MBC[0][0], trdcInst = 2, mbcInst = 0, slvIdx = 0
    kTRDC_COMM_MBC_MODCON            = TRDC_MBC_BLK(2, 0, 0, 0),    /*!< COMM_TRDC MBC0 Slave 0 Block Idx 0 */
    kTRDC_COMM_MBC_MTR               = TRDC_MBC_BLK(2, 0, 0, 2),    /*!< COMM_TRDC MBC0 Slave 0 Block Idx 2 */
    kTRDC_COMM_MBC_TCU               = TRDC_MBC_BLK(2, 0, 0, 3),    /*!< COMM_TRDC MBC0 Slave 0 Block Idx 3 */
    kTRDC_COMM_MBC_TRDC_MGR          = TRDC_MBC_BLK(2, 0, 0, 4),    /*!< COMM_TRDC MBC0 Slave 0 Block Idx 4 */
    kTRDC_COMM_MBC_TRDC_MC           = TRDC_MBC_BLK(2, 0, 0, 5),    /*!< COMM_TRDC MBC0 Slave 0 Block Idx 5 */
    kTRDC_COMM_MBC_CCM               = TRDC_MBC_BLK(2, 0, 0, 6),    /*!< COMM_TRDC MBC0 Slave 0 Block Idx 6 */
    kTRDC_COMM_MBC_uSDHC0            = TRDC_MBC_BLK(2, 0, 0, 8),    /*!< COMM_TRDC MBC0 Slave 0 Block Idx 8 */
    kTRDC_COMM_MBC_uSDHC1            = TRDC_MBC_BLK(2, 0, 0, 9),    /*!< COMM_TRDC MBC0 Slave 0 Block Idx 9 */
    kTRDC_COMM_MBC_HSUSB             = TRDC_MBC_BLK(2, 0, 0, 10),   /*!< COMM_TRDC MBC0 Slave 0 Block Idx 10 */
    kTRDC_COMM_MBC_FSUSB             = TRDC_MBC_BLK(2, 0, 0, 11),   /*!< COMM_TRDC MBC0 Slave 0 Block Idx 11 */
    kTRDC_COMM_MBC_ETH0              = TRDC_MBC_BLK(2, 0, 0, 12),   /*!< COMM_TRDC MBC0 Slave 0 Block Idx 12 */
    kTRDC_COMM_MBC_ETH1              = TRDC_MBC_BLK(2, 0, 0, 13),   /*!< COMM_TRDC MBC0 Slave 0 Block Idx 13 */
    kTRDC_COMM_MBC_xSPIR             = TRDC_MBC_BLK(2, 0, 0, 14),   /*!< COMM_TRDC MBC0 Slave 0 Block Idx 14 */
    kTRDC_COMM_MBC_USB_PHY           = TRDC_MBC_BLK(2, 0, 0, 15),   /*!< COMM_TRDC MBC0 Slave 0 Block Idx 15 */
    kTRDC_COMM_MBC_XENO_PHY0         = TRDC_MBC_BLK(2, 0, 0, 16),   /*!< COMM_TRDC MBC0 Slave 0 Block Idx 16 */
    kTRDC_COMM_MBC_XENO_PHY1         = TRDC_MBC_BLK(2, 0, 0, 17),   /*!< COMM_TRDC MBC0 Slave 0 Block Idx 17 */
    kTRDC_COMM_MBC_FREQME            = TRDC_MBC_BLK(2, 0, 0, 18),   /*!< COMM_TRDC MBC0 Slave 0 Block Idx 18 */
    kTRDC_COMM_MBC_FREQME_MUX        = TRDC_MBC_BLK(2, 0, 0, 19),   /*!< COMM_TRDC MBC0 Slave 0 Block Idx 19 */

    // COMM_TRDC.MBC[0][1], trdcInst = 2, mbcInst = 0, slvIdx = 1
    kTRDC_COMM_MBC_NIC_GPV           = TRDC_MBC_BLK(2, 0, 1, 0),    /*!< COMM_TRDC MBC0 Slave 1 Block Idx 0 */
    
    // AUDIO_MBC[0][0], trdcInst = 3, mbcInst = 0, slvIdx = 0
    kTRDC_AUDIO_MBC_MODCON           = TRDC_MBC_BLK(3, 0, 0, 0),    /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 0 */
    kTRDC_AUDIO_MBC_MTR              = TRDC_MBC_BLK(3, 0, 0, 2),    /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 2 */
    kTRDC_AUDIO_MBC_TCU              = TRDC_MBC_BLK(3, 0, 0, 3),    /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 3 */
    kTRDC_AUDIO_MBC_TRDC_MGR         = TRDC_MBC_BLK(3, 0, 0, 4),    /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 4 */
    kTRDC_AUDIO_MBC_TRDC_MC          = TRDC_MBC_BLK(3, 0, 0, 5),    /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 5 */
    kTRDC_AUDIO_MBC_CCM              = TRDC_MBC_BLK(3, 0, 0, 6),    /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 6 */
    kTRDC_AUDIO_MBC_SLEEPCON         = TRDC_MBC_BLK(3, 0, 0, 7),    /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 7 */
    kTRDC_AUDIO_MBC_DMIC             = TRDC_MBC_BLK(3, 0, 0, 8),    /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 8 */
    kTRDC_AUDIO_MBC_FREQME           = TRDC_MBC_BLK(3, 0, 0, 9),    /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 9 */
    kTRDC_AUDIO_MBC_FREQME_MUX       = TRDC_MBC_BLK(3, 0, 0, 10),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 10 */
    kTRDC_AUDIO_MBC_LPIT             = TRDC_MBC_BLK(3, 0, 0, 11),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 11 */
    kTRDC_AUDIO_MBC_SAI0             = TRDC_MBC_BLK(3, 0, 0, 12),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 12 */
    kTRDC_AUDIO_MBC_SAI1             = TRDC_MBC_BLK(3, 0, 0, 13),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 13 */
    kTRDC_AUDIO_MBC_SAI2             = TRDC_MBC_BLK(3, 0, 0, 14),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 14 */
    kTRDC_AUDIO_MBC_SAI3             = TRDC_MBC_BLK(3, 0, 0, 15),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 15 */
    kTRDC_AUDIO_MBC_SAI4             = TRDC_MBC_BLK(3, 0, 0, 16),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 16 */
    kTRDC_AUDIO_MBC_SAI5             = TRDC_MBC_BLK(3, 0, 0, 17),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 17 */
    kTRDC_AUDIO_MBC_SAI6             = TRDC_MBC_BLK(3, 0, 0, 18),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 18 */
    kTRDC_AUDIO_MBC_SAI7             = TRDC_MBC_BLK(3, 0, 0, 19),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 19 */
    kTRDC_AUDIO_MBC_ASRC             = TRDC_MBC_BLK(3, 0, 0, 20),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 20 */
    kTRDC_AUDIO_MBC_XBAR             = TRDC_MBC_BLK(3, 0, 0, 22),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 22 */
    kTRDC_AUDIO_MBC_EDMA3            = TRDC_MBC_BLK(3, 0, 0, 23),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 23 */
    kTRDC_AUDIO_MBC_eDMA3_TCD0       = TRDC_MBC_BLK(3, 0, 0, 24),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 24 */
    kTRDC_AUDIO_MBC_eDMA3_TCD1       = TRDC_MBC_BLK(3, 0, 0, 25),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 25 */
    kTRDC_AUDIO_MBC_eDMA3_TCD2       = TRDC_MBC_BLK(3, 0, 0, 26),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 26 */
    kTRDC_AUDIO_MBC_eDMA3_TCD3       = TRDC_MBC_BLK(3, 0, 0, 27),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 27 */
    kTRDC_AUDIO_MBC_eDMA3_TCD4       = TRDC_MBC_BLK(3, 0, 0, 28),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 28 */
    kTRDC_AUDIO_MBC_eDMA3_TCD5       = TRDC_MBC_BLK(3, 0, 0, 29),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 29 */
    kTRDC_AUDIO_MBC_eDMA3_TCD6       = TRDC_MBC_BLK(3, 0, 0, 30),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 30 */
    kTRDC_AUDIO_MBC_eDMA3_TCD7       = TRDC_MBC_BLK(3, 0, 0, 31),   /*!< AUDIO_TRDC MBC0 Slave 0 Block Idx 31 */

    // AUDIO_TRDC.MBC[0][1], trdcInst = 3, mbcInst = 0, slvIdx = 1
    kTRDC_AUDIO_MBC_SPIDF            = TRDC_MBC_BLK(3, 0, 1, 0),    /*!< AUDIO_TRDC MBC0 Slave 1 Block Idx 0 */

    // AUDIO_TRDC.MBC[0][2], trdcInst = 3, mbcInst = 0, slvIdx = 2
    kTRDC_AUDIO_MBC_SRAM0            = TRDC_MBC_BLK(3, 0, 2, 0),    /*!< AUDIO_TRDC MBC0 Slave 2 Block Idx 0 */
    kTRDC_AUDIO_MBC_SRAM1            = TRDC_MBC_BLK(3, 0, 2, 1),    /*!< AUDIO_TRDC MBC0 Slave 2 Block Idx 1 */

    // MEDIA_MBC[0][0], trdcInst = 4, mbcInst = 0, slvIdx = 0
    kTRDC_MEDIA_MBC_MODCON           = TRDC_MBC_BLK(4, 0, 0, 0),    /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 0 */
    kTRDC_MEDIA_MBC_MTR              = TRDC_MBC_BLK(4, 0, 0, 2),    /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 2 */
    kTRDC_MEDIA_MBC_TCU              = TRDC_MBC_BLK(4, 0, 0, 3),    /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 3 */
    kTRDC_MEDIA_MBC_TRDC_MGR         = TRDC_MBC_BLK(4, 0, 0, 4),    /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 4 */
    kTRDC_MEDIA_MBC_TRDC_MC          = TRDC_MBC_BLK(4, 0, 0, 5),    /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 5 */
    kTRDC_MEDIA_MBC_CCM              = TRDC_MBC_BLK(4, 0, 0, 6),    /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 6 */
    kTRDC_MEDIA_MBC_CSI              = TRDC_MBC_BLK(4, 0, 0, 9),    /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 9 */
    kTRDC_MEDIA_MBC_DSI_REG          = TRDC_MBC_BLK(4, 0, 0, 10),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 10 */
    kTRDC_MEDIA_MBC_CSI_REG          = TRDC_MBC_BLK(4, 0, 0, 11),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 11 */
    kTRDC_MEDIA_MBC_JPEGDEC          = TRDC_MBC_BLK(4, 0, 0, 12),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 12 */
    kTRDC_MEDIA_MBC_PNGDEC           = TRDC_MBC_BLK(4, 0, 0, 13),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 13 */
    kTRDC_MEDIA_MBC_TINGPU           = TRDC_MBC_BLK(4, 0, 0, 14),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 14 */
    kTRDC_MEDIA_MBC_VIDEOMUX         = TRDC_MBC_BLK(4, 0, 0, 15),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 15 */
    kTRDC_MEDIA_MBC_FREQME           = TRDC_MBC_BLK(4, 0, 0, 16),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 16 */
    kTRDC_MEDIA_MBC_FREQME_MUX       = TRDC_MBC_BLK(4, 0, 0, 17),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 17 */
    kTRDC_MEDIA_MBC_ISI0             = TRDC_MBC_BLK(4, 0, 0, 18),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 18 */
    kTRDC_MEDIA_MBC_ISI1             = TRDC_MBC_BLK(4, 0, 0, 19),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 19 */
    kTRDC_MEDIA_MBC_MIPI_DSI_PHY     = TRDC_MBC_BLK(4, 0, 0, 22),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 22 */
    kTRDC_MEDIA_MBC_DCIF0            = TRDC_MBC_BLK(4, 0, 0, 32),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 32 */
    kTRDC_MEDIA_MBC_DCIF1            = TRDC_MBC_BLK(4, 0, 0, 33),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 33 */
    kTRDC_MEDIA_MBC_DCIF2            = TRDC_MBC_BLK(4, 0, 0, 34),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 34 */
    kTRDC_MEDIA_MBC_DCIF3            = TRDC_MBC_BLK(4, 0, 0, 35),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 35 */
    kTRDC_MEDIA_MBC_DCIF4            = TRDC_MBC_BLK(4, 0, 0, 36),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 36 */
    kTRDC_MEDIA_MBC_DCIF5            = TRDC_MBC_BLK(4, 0, 0, 37),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 37 */
    kTRDC_MEDIA_MBC_DCIF6            = TRDC_MBC_BLK(4, 0, 0, 38),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 38 */
    kTRDC_MEDIA_MBC_DCIF7            = TRDC_MBC_BLK(4, 0, 0, 39),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 39 */
    kTRDC_MEDIA_MBC_DCIF8            = TRDC_MBC_BLK(4, 0, 0, 40),   /*!< MEDIA_TRDC MBC0 Slave 0 Block Idx 40 */

    // MEDIA_TRDC.MBC[0][1], trdcInst = 4, mbcInst = 0, slvIdx = 1
    kTRDC_MEDIA_MBC_NIC_GPV          = TRDC_MBC_BLK(4, 0, 1, 0),    /*!< MEDIA_TRDC MBC0 Slave 1 Block Idx 0 */

    // MEDIA_TRDC.MBC[0][2], trdcInst = 4, mbcInst = 0, slvIdx = 2
    kTRDC_MEDIA_MBC_GPU_AHB          = TRDC_MBC_BLK(4, 0, 2, 0),    /*!< MEDIA_TRDC MBC0 Slave 2 Block Idx 0 */

    // WAKE_TRDC.MBC[0][0], trdcInst = 5, mbcInst = 0, slvIdx = 0
    kTRDC_WAKE_MBC_MODCON            = TRDC_MBC_BLK(5, 0, 0, 0),    /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 0 */
    kTRDC_WAKE_MBC_MTR               = TRDC_MBC_BLK(5, 0, 0, 2),    /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 2 */
    kTRDC_WAKE_MBC_TCU               = TRDC_MBC_BLK(5, 0, 0, 3),    /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 3 */
    kTRDC_WAKE_MBC_TRDC_MGR          = TRDC_MBC_BLK(5, 0, 0, 4),    /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 4 */
    kTRDC_WAKE_MBC_TRDC_MC           = TRDC_MBC_BLK(5, 0, 0, 5),    /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 5 */
    kTRDC_WAKE_MBC_CCM               = TRDC_MBC_BLK(5, 0, 0, 6),    /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 6 */
    kTRDC_WAKE_MBC_FREQME            = TRDC_MBC_BLK(5, 0, 0, 8),    /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 8 */
    kTRDC_WAKE_MBC_FREQME_MUX        = TRDC_MBC_BLK(5, 0, 0, 9),    /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 9 */
    kTRDC_WAKE_MBC_DMIC              = TRDC_MBC_BLK(5, 0, 0, 10),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 10 */
    kTRDC_WAKE_MBC_XBAR              = TRDC_MBC_BLK(5, 0, 0, 11),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 11 */
    kTRDC_WAKE_MBC_TRGSYNC           = TRDC_MBC_BLK(5, 0, 0, 12),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 12 */
    kTRDC_WAKE_MBC_CMP0              = TRDC_MBC_BLK(5, 0, 0, 13),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 13 */
    kTRDC_WAKE_MBC_CMP1              = TRDC_MBC_BLK(5, 0, 0, 14),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 14 */
    kTRDC_WAKE_MBC_CMP2              = TRDC_MBC_BLK(5, 0, 0, 15),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 15 */
    kTRDC_WAKE_MBC_CMP3              = TRDC_MBC_BLK(5, 0, 0, 16),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 16 */
    kTRDC_WAKE_MBC_EWM               = TRDC_MBC_BLK(5, 0, 0, 17),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 17 */
    kTRDC_WAKE_MBC_LPTMR0            = TRDC_MBC_BLK(5, 0, 0, 19),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 19 */
    kTRDC_WAKE_MBC_LPTMR1            = TRDC_MBC_BLK(5, 0, 0, 20),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 20 */
    kTRDC_WAKE_MBC_QUADTPM           = TRDC_MBC_BLK(5, 0, 0, 21),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 21 */
    kTRDC_WAKE_MBC_SWT0              = TRDC_MBC_BLK(5, 0, 0, 22),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 22 */
    kTRDC_WAKE_MBC_SWT1              = TRDC_MBC_BLK(5, 0, 0, 23),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 23 */
    kTRDC_WAKE_MBC_SWT2              = TRDC_MBC_BLK(5, 0, 0, 24),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 24 */
    kTRDC_WAKE_MBC_SWT3              = TRDC_MBC_BLK(5, 0, 0, 25),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 25 */
    kTRDC_WAKE_MBC_SYS_CTR           = TRDC_MBC_BLK(5, 0, 0, 26),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 26 */
    kTRDC_WAKE_MBC_I3C               = TRDC_MBC_BLK(5, 0, 0, 27),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 27 */
    kTRDC_WAKE_MBC_LPI2C0            = TRDC_MBC_BLK(5, 0, 0, 28),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 28 */
    kTRDC_WAKE_MBC_LPI2C1            = TRDC_MBC_BLK(5, 0, 0, 29),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 29 */
    kTRDC_WAKE_MBC_LPSPI             = TRDC_MBC_BLK(5, 0, 0, 30),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 30 */
    kTRDC_WAKE_MBC_LPUART0           = TRDC_MBC_BLK(5, 0, 0, 31),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 31 */
    kTRDC_WAKE_MBC_LPUART1           = TRDC_MBC_BLK(5, 0, 0, 32),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 32 */
    kTRDC_WAKE_MBC_RGPIO             = TRDC_MBC_BLK(5, 0, 0, 33),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 33 */
    kTRDC_WAKE_MBC_IOMUXC            = TRDC_MBC_BLK(5, 0, 0, 34),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 34 */
    kTRDC_WAKE_MBC_TSI               = TRDC_MBC_BLK(5, 0, 0, 35),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 35 */
    kTRDC_WAKE_MBC_EDMA3             = TRDC_MBC_BLK(5, 0, 0, 39),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 39 */
    kTRDC_WAKE_MBC_eDMA3_TCD0        = TRDC_MBC_BLK(5, 0, 0, 40),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 40 */
    kTRDC_WAKE_MBC_eDMA3_TCD1        = TRDC_MBC_BLK(5, 0, 0, 41),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 41 */
    kTRDC_WAKE_MBC_eDMA3_TCD2        = TRDC_MBC_BLK(5, 0, 0, 42),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 42 */
    kTRDC_WAKE_MBC_eDMA3_TCD3        = TRDC_MBC_BLK(5, 0, 0, 43),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 43 */
    kTRDC_WAKE_MBC_eDMA3_TCD4        = TRDC_MBC_BLK(5, 0, 0, 44),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 44 */
    kTRDC_WAKE_MBC_eDMA3_TCD5        = TRDC_MBC_BLK(5, 0, 0, 45),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 45 */
    kTRDC_WAKE_MBC_eDMA3_TCD6        = TRDC_MBC_BLK(5, 0, 0, 46),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 46 */
    kTRDC_WAKE_MBC_eDMA3_TCD7        = TRDC_MBC_BLK(5, 0, 0, 47),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 47 */
    kTRDC_WAKE_MBC_VBAT_SRAM         = TRDC_MBC_BLK(5, 0, 0, 48),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 48 */
    kTRDC_WAKE_MBC_VBAT_MTR          = TRDC_MBC_BLK(5, 0, 0, 49),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 49 */
    kTRDC_WAKE_MBC_VBAT_TDET         = TRDC_MBC_BLK(5, 0, 0, 50),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 50 */
    kTRDC_WAKE_MBC_VBAT_LPTMR        = TRDC_MBC_BLK(5, 0, 0, 51),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 51 */
    kTRDC_WAKE_MBC_VBAT_RTC          = TRDC_MBC_BLK(5, 0, 0, 52),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 52 */
    kTRDC_WAKE_MBC_VBAT_RGPIO        = TRDC_MBC_BLK(5, 0, 0, 53),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 53 */
    kTRDC_WAKE_MBC_VBAT_IOMUXC       = TRDC_MBC_BLK(5, 0, 0, 54),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 54 */
    kTRDC_WAKE_MBC_VBAT_VBATCON      = TRDC_MBC_BLK(5, 0, 0, 55),   /*!< WAKE_TRDC MBC0 Slave 0 Block Idx 55 */

    // WAKE_TRDC.MBC[0][1], trdcInst = 5, mbcInst = 0, slvIdx = 1
    kTRDC_WAKE_MBC_SRAM0             = TRDC_MBC_BLK(5, 0, 1, 0),    /*!< WAKE_TRDC MBC0 Slave 1 Block Idx 0 */
    kTRDC_WAKE_MBC_SRAM1             = TRDC_MBC_BLK(5, 0, 1, 1),    /*!< WAKE_TRDC MBC0 Slave 1 Block Idx 1 */
} trdc_mbc_block_t;

/* @} */

/*!@brief TRDC base address convert macro */
#define TRDC_GENERAL_OFFSET           0UL
#define TRDC_FLW_OFFSET               0x1E0UL
#define TRDC_DOMAIN_ERROR_OFFSET      0x1FCUL
#define TRDC_DOMAIN_ASSIGNMENT_OFFSET 0x700UL
#define TRDC_MBC_OFFSET(x)            0x10000UL /* Different TRDC instance may have different offset. */
#define TRDC_MBC_ARRAY_STEP           0x1000UL
#define TRDC_MRC_OFFSET(x)            (((x) == (void *)CMPT__TRDC) ? (0x11000UL) : (((x) == (void *)MAIN__TRDC) ? (0x12000UL) : 0U))
#define TRDC_MRC_ARRAY_STEP           0x800UL

/*!@brief Some macros are only defined for TRDC_SOC*/
#define TRDC_MDA_W_DFMT1_LK1(x)                  (((uint32_t)(((uint32_t)(x)) << TRDC_MDA_W_DFMT1_LK1_SHIFT)) & TRDC_MDA_W_DFMT1_LK1_MASK)

#define TRDC_MDA_W_DFMT0_LK1_MASK                (0x40000000U)
#define TRDC_MDA_W_DFMT0_LK1_SHIFT               (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MDA_W_DFMT0_LK1(x)                  (((uint32_t)(((uint32_t)(x)) << TRDC_MDA_W_DFMT1_LK1_SHIFT)) & TRDC_MDA_W_DFMT1_LK1_MASK)



#define TRDC_MDA_W_DFMT0_VLD_MASK                (0x80000000U)
#define TRDC_MDA_W_DFMT0_VLD_SHIFT               (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MDA_W_DFMT0_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << TRDC_MDA_W_DFMT1_VLD_SHIFT)) & TRDC_MDA_W_DFMT1_VLD_MASK)

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /* _FSL_TRDC_SOC_H_ */
