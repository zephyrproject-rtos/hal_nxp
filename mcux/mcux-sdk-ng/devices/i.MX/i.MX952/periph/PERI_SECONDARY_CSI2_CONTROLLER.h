/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SECONDARY_CSI2_CONTROLLER
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SECONDARY_CSI2_CONTROLLER.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SECONDARY_CSI2_CONTROLLER
 *
 * CMSIS Peripheral Access Layer for SECONDARY_CSI2_CONTROLLER
 */

#if !defined(PERI_SECONDARY_CSI2_CONTROLLER_H_)
#define PERI_SECONDARY_CSI2_CONTROLLER_H_        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

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
   -- SECONDARY_CSI2_CONTROLLER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SECONDARY_CSI2_CONTROLLER_Peripheral_Access_Layer SECONDARY_CSI2_CONTROLLER Peripheral Access Layer
 * @{
 */

/** SECONDARY_CSI2_CONTROLLER - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERSION;                           /**< Core version., offset: 0x0 */
  __IO uint32_t N_LANES;                           /**< Number of lanes., offset: 0x4 */
  __IO uint32_t CSI2_RESETN;                       /**< Logic Reset., offset: 0x8 */
  __I  uint32_t INT_ST_MAIN;                       /**< Main interrupt status., offset: 0xC */
  __IO uint32_t DATA_IDS_1;                        /**< Data Type fields for Data ID Monitors 1., offset: 0x10 */
  __IO uint32_t DATA_IDS_2;                        /**< Data Type fields for Data ID Monitors 2., offset: 0x14 */
       uint8_t RESERVED_0[24];
  __IO uint32_t DATA_IDS_VC_1;                     /**< Virtual Channel fields for Data ID Monitors 1., offset: 0x30 */
  __IO uint32_t DATA_IDS_VC_2;                     /**< Virtual Channel fields for Data ID Monitors 2., offset: 0x34 */
       uint8_t RESERVED_1[8];
  __IO uint32_t PHY_SHUTDOWNZ;                     /**< PHY Shutdown., offset: 0x40 */
  __IO uint32_t DPHY_RSTZ;                         /**< D-PHY reset., offset: 0x44 */
  __I  uint32_t PHY_RX;                            /**< RX PHY status., offset: 0x48 */
  __I  uint32_t PHY_STOPSTATE;                     /**< STOPSTATE PHY status., offset: 0x4C */
  __IO uint32_t PHY_TEST_CTRL0;                    /**< D-PHY Test and Control Interface 0., offset: 0x50 */
  __IO uint32_t PHY_TEST_CTRL1;                    /**< D-PHY Test and Control interface 1., offset: 0x54 */
       uint8_t RESERVED_2[8];
  __IO uint32_t PPI_PG_PATTERN_VRES;               /**< PPI Pattern Generator vertical resolution., offset: 0x60 */
  __IO uint32_t PPI_PG_PATTERN_HRES;               /**< PPI Pattern Generator horizontal resolution., offset: 0x64 */
  __IO uint32_t PPI_PG_CONFIG;                     /**< PPI Pattern Generator Configuration., offset: 0x68 */
  __IO uint32_t PPI_PG_ENABLE;                     /**< PPI Pattern Generator Enable., offset: 0x6C */
  __I  uint32_t PPI_PG_STATUS;                     /**< PPI Pattern Generator status., offset: 0x70 */
       uint8_t RESERVED_3[84];
  __IO uint32_t VC_EXTENSION;                      /**< Virtual Channel Extension., offset: 0xC8 */
  __I  uint32_t PHY_CAL;                           /**< PHY Calibration., offset: 0xCC */
       uint8_t RESERVED_4[16];
  __I  uint32_t INT_ST_PHY_FATAL;                  /**< Fatal interruption caused by PHY., offset: 0xE0 */
  __IO uint32_t INT_MSK_PHY_FATAL;                 /**< Mask for fatal interruption caused by PHY., offset: 0xE4 */
  __IO uint32_t INT_FORCE_PHY_FATAL;               /**< Force for fatal interruption caused by PHY., offset: 0xE8 */
       uint8_t RESERVED_5[4];
  __I  uint32_t INT_ST_PKT_FATAL;                  /**< Fatal interruption caused during Packet Construction., offset: 0xF0 */
  __IO uint32_t INT_MSK_PKT_FATAL;                 /**< Mask for fatal interruption caused during Packet Construction., offset: 0xF4 */
  __IO uint32_t INT_FORCE_PKT_FATAL;               /**< Force for fatal interruption caused during Packet Construction., offset: 0xF8 */
       uint8_t RESERVED_6[20];
  __I  uint32_t INT_ST_PHY;                        /**< Interruption caused by PHY., offset: 0x110 */
  __IO uint32_t INT_MSK_PHY;                       /**< Mask for interruption caused by PHY., offset: 0x114 */
  __IO uint32_t INT_FORCE_PHY;                     /**< Force for interruption caused by PHY., offset: 0x118 */
       uint8_t RESERVED_7[20];
  __I  uint32_t INT_ST_LINE;                       /**< Interruption occurred during Line construction., offset: 0x130 */
  __IO uint32_t INT_MSK_LINE;                      /**< Mask for interruption occurred during Line construction., offset: 0x134 */
  __IO uint32_t INT_FORCE_LINE;                    /**< Force for interruption occurred during Line construction., offset: 0x138 */
       uint8_t RESERVED_8[324];
  __I  uint32_t INT_ST_BNDRY_FRAME_FATAL;          /**< Fatal Interruption caused by Frame Boundaries., offset: 0x280 */
  __IO uint32_t INT_MSK_BNDRY_FRAME_FATAL;         /**< Mask for fatal interruption caused by Frame Boundaries., offset: 0x284 */
  __IO uint32_t INT_FORCE_BNDRY_FRAME_FATAL;       /**< Force for fatal interruption caused by Frame Boundaries., offset: 0x288 */
       uint8_t RESERVED_9[4];
  __I  uint32_t INT_ST_SEQ_FRAME_FATAL;            /**< Fatal Interruption caused by Frame Sequence., offset: 0x290 */
  __IO uint32_t INT_MSK_SEQ_FRAME_FATAL;           /**< Mask for fatal interruption caused by Frame Sequence., offset: 0x294 */
  __IO uint32_t INT_FORCE_SEQ_FRAME_FATAL;         /**< Force for fatal interruption caused by Frame Sequence., offset: 0x298 */
       uint8_t RESERVED_10[4];
  __I  uint32_t INT_ST_CRC_FRAME_FATAL;            /**< Fatal Interruption caused by Frame CRC., offset: 0x2A0 */
  __IO uint32_t INT_MSK_CRC_FRAME_FATAL;           /**< Mask for fatal interruption caused by Frame CRC., offset: 0x2A4 */
  __IO uint32_t INT_FORCE_CRC_FRAME_FATAL;         /**< Force for fatal interruption caused by Frame CRC., offset: 0x2A8 */
       uint8_t RESERVED_11[4];
  __I  uint32_t INT_ST_PLD_CRC_FATAL;              /**< Fatal Interruption caused by Payload CRC., offset: 0x2B0 */
  __IO uint32_t INT_MSK_PLD_CRC_FATAL;             /**< Mask for fatal interruption caused by Payload CRC., offset: 0x2B4 */
  __IO uint32_t INT_FORCE_PLD_CRC_FATAL;           /**< Force for fatal interruption caused by Payload CRC., offset: 0x2B8 */
       uint8_t RESERVED_12[4];
  __I  uint32_t INT_ST_DATA_ID;                    /**< Interruption caused by Data Type., offset: 0x2C0 */
  __IO uint32_t INT_MSK_DATA_ID;                   /**< Mask for interruption caused by Data Type., offset: 0x2C4 */
  __IO uint32_t INT_FORCE_DATA_ID;                 /**< Force for interruption caused by Data Type., offset: 0x2C8 */
       uint8_t RESERVED_13[4];
  __I  uint32_t INT_ST_ECC_CORRECTED;              /**< Interruption caused by Header single bit errors., offset: 0x2D0 */
  __IO uint32_t INT_MSK_ECC_CORRECTED;             /**< Mask for interruption caused by Header single bit errors., offset: 0x2D4 */
  __IO uint32_t INT_FORCE_ECC_CORRECTED;           /**< Force for interruption caused by Header single bit errors., offset: 0x2D8 */
       uint8_t RESERVED_14[36];
  __IO uint32_t SCRAMBLING;                        /**< Data De-Scrambling., offset: 0x300 */
  __IO uint32_t SCRAMBLING_SEED1;                  /**< De-scrambler seed for lane1., offset: 0x304 */
  __IO uint32_t SCRAMBLING_SEED2;                  /**< De-scrambler seed for lane2., offset: 0x308 */
  __IO uint32_t SCRAMBLING_SEED3;                  /**< De-scrambler seed for lane3., offset: 0x30C */
  __IO uint32_t SCRAMBLING_SEED4;                  /**< De-scrambler seed for lane4., offset: 0x310 */
} SECONDARY_CSI2_CONTROLLER_Type;

/* ----------------------------------------------------------------------------
   -- SECONDARY_CSI2_CONTROLLER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SECONDARY_CSI2_CONTROLLER_Register_Masks SECONDARY_CSI2_CONTROLLER Register Masks
 * @{
 */

/*! @name VERSION - Core version. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_VERSION_version_MASK (0xFFFFFFFFU)
#define SECONDARY_CSI2_CONTROLLER_VERSION_version_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_VERSION_version(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_VERSION_version_SHIFT)) & SECONDARY_CSI2_CONTROLLER_VERSION_version_MASK)
/*! @} */

/*! @name N_LANES - Number of lanes. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_N_LANES_n_lanes_MASK (0x3U)
#define SECONDARY_CSI2_CONTROLLER_N_LANES_n_lanes_SHIFT (0U)
/*! n_lanes - Number of lanes
 *  0b00..1 Data Lane
 *  0b01..2 Data Lane
 *  0b10..Not Supported
 *  0b11..Not Supported
 */
#define SECONDARY_CSI2_CONTROLLER_N_LANES_n_lanes(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_N_LANES_n_lanes_SHIFT)) & SECONDARY_CSI2_CONTROLLER_N_LANES_n_lanes_MASK)
/*! @} */

/*! @name CSI2_RESETN - Logic Reset. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_SHIFT)) & SECONDARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK)
/*! @} */

/*! @name INT_ST_MAIN - Main interrupt status. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_phy_fatal_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_phy_fatal_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_phy_fatal(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_phy_fatal_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_phy_fatal_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_pkt_fatal_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_pkt_fatal_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_pkt_fatal(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_pkt_fatal_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_pkt_fatal_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_bndry_frame_fatal_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_bndry_frame_fatal_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_bndry_frame_fatal(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_bndry_frame_fatal_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_bndry_frame_fatal_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_seq_frame_fatal_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_seq_frame_fatal_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_seq_frame_fatal(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_seq_frame_fatal_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_seq_frame_fatal_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_crc_frame_fatal_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_crc_frame_fatal_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_crc_frame_fatal(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_crc_frame_fatal_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_crc_frame_fatal_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_pld_crc_fatal_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_pld_crc_fatal_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_pld_crc_fatal(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_pld_crc_fatal_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_pld_crc_fatal_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_data_id_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_data_id_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_data_id(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_data_id_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_data_id_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_ecc_corrected_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_ecc_corrected_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_ecc_corrected(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_ecc_corrected_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_ecc_corrected_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_phy_MASK (0x10000U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_phy_SHIFT (16U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_phy(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_phy_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_phy_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_line_MASK (0x20000U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_line_SHIFT (17U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_line(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_line_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_MAIN_status_int_st_line_MASK)
/*! @} */

/*! @name DATA_IDS_1 - Data Type fields for Data ID Monitors 1. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di0_dt_MASK (0x3FU)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di0_dt_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di0_dt(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di0_dt_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di0_dt_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di1_dt_MASK (0x3F00U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di1_dt_SHIFT (8U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di1_dt(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di1_dt_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di1_dt_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di2_dt_MASK (0x3F0000U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di2_dt_SHIFT (16U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di2_dt(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di2_dt_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di2_dt_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di3_dt_MASK (0x3F000000U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di3_dt_SHIFT (24U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di3_dt(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di3_dt_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_1_di3_dt_MASK)
/*! @} */

/*! @name DATA_IDS_2 - Data Type fields for Data ID Monitors 2. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di4_dt_MASK (0x3FU)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di4_dt_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di4_dt(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di4_dt_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di4_dt_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di5_dt_MASK (0x3F00U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di5_dt_SHIFT (8U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di5_dt(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di5_dt_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di5_dt_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di6_dt_MASK (0x3F0000U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di6_dt_SHIFT (16U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di6_dt(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di6_dt_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di6_dt_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di7_dt_MASK (0x3F000000U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di7_dt_SHIFT (24U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di7_dt(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di7_dt_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_2_di7_dt_MASK)
/*! @} */

/*! @name DATA_IDS_VC_1 - Virtual Channel fields for Data ID Monitors 1. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di0_vc_MASK (0x3U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di0_vc_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di0_vc(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di0_vc_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di0_vc_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di0_vcx_0_1_MASK (0xCU)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di0_vcx_0_1_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di0_vcx_0_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di0_vcx_0_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di0_vcx_0_1_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di1_vc_MASK (0x300U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di1_vc_SHIFT (8U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di1_vc(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di1_vc_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di1_vc_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di1_vcx_0_1_MASK (0xC00U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di1_vcx_0_1_SHIFT (10U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di1_vcx_0_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di1_vcx_0_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di1_vcx_0_1_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di2_vc_MASK (0x30000U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di2_vc_SHIFT (16U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di2_vc(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di2_vc_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di2_vc_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di2_vcx_0_1_MASK (0xC0000U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di2_vcx_0_1_SHIFT (18U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di2_vcx_0_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di2_vcx_0_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di2_vcx_0_1_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di3_vc_MASK (0x3000000U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di3_vc_SHIFT (24U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di3_vc(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di3_vc_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di3_vc_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di3_vcx_0_1_MASK (0xC000000U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di3_vcx_0_1_SHIFT (26U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di3_vcx_0_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di3_vcx_0_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_1_di3_vcx_0_1_MASK)
/*! @} */

/*! @name DATA_IDS_VC_2 - Virtual Channel fields for Data ID Monitors 2. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di4_vc_MASK (0x3U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di4_vc_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di4_vc(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di4_vc_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di4_vc_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di4_vcx_0_1_MASK (0xCU)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di4_vcx_0_1_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di4_vcx_0_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di4_vcx_0_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di4_vcx_0_1_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di5_vc_MASK (0x300U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di5_vc_SHIFT (8U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di5_vc(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di5_vc_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di5_vc_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di5_vcx_0_1_MASK (0xC00U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di5_vcx_0_1_SHIFT (10U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di5_vcx_0_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di5_vcx_0_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di5_vcx_0_1_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di6_vc_MASK (0x30000U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di6_vc_SHIFT (16U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di6_vc(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di6_vc_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di6_vc_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di6_vcx_0_1_MASK (0xC0000U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di6_vcx_0_1_SHIFT (18U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di6_vcx_0_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di6_vcx_0_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di6_vcx_0_1_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di7_vc_MASK (0x3000000U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di7_vc_SHIFT (24U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di7_vc(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di7_vc_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di7_vc_MASK)

#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di7_vcx_0_1_MASK (0xC000000U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di7_vcx_0_1_SHIFT (26U)
#define SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di7_vcx_0_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di7_vcx_0_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DATA_IDS_VC_2_di7_vcx_0_1_MASK)
/*! @} */

/*! @name PHY_SHUTDOWNZ - PHY Shutdown. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_SHIFT (0U)
/*! phy_shutdownz - PHY Shutdown */
#define SECONDARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK)
/*! @} */

/*! @name DPHY_RSTZ - D-PHY reset. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_SHIFT)) & SECONDARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK)
/*! @} */

/*! @name PHY_RX - RX PHY status. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxulpsesc_0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxulpsesc_0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxulpsesc_0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxulpsesc_0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxulpsesc_0_MASK)

#define SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxulpsesc_1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxulpsesc_1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxulpsesc_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxulpsesc_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxulpsesc_1_MASK)

#define SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxulpsclknot_MASK (0x10000U)
#define SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxulpsclknot_SHIFT (16U)
#define SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxulpsclknot(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxulpsclknot_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxulpsclknot_MASK)

#define SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxclkactivehs_MASK (0x20000U)
#define SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxclkactivehs_SHIFT (17U)
#define SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxclkactivehs(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxclkactivehs_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PHY_RX_phy_rxclkactivehs_MASK)
/*! @} */

/*! @name PHY_STOPSTATE - STOPSTATE PHY status. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstatedata_0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstatedata_0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstatedata_0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstatedata_0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstatedata_0_MASK)

#define SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstatedata_1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstatedata_1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstatedata_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstatedata_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstatedata_1_MASK)

#define SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstateclk_MASK (0x10000U)
#define SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstateclk_SHIFT (16U)
#define SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstateclk(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstateclk_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstateclk_MASK)
/*! @} */

/*! @name PHY_TEST_CTRL0 - D-PHY Test and Control Interface 0. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr_MASK)

#define SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk_MASK)
/*! @} */

/*! @name PHY_TEST_CTRL1 - D-PHY Test and Control interface 1. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdin_MASK (0xFFU)
#define SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdin_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdin(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdin_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdin_MASK)

#define SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdout_MASK (0xFF00U)
#define SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdout_SHIFT (8U)
#define SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdout(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdout_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdout_MASK)

#define SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen_MASK (0x10000U)
#define SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen_SHIFT (16U)
/*! phy_testen - PHY Testen */
#define SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen_MASK)
/*! @} */

/*! @name PPI_PG_PATTERN_VRES - PPI Pattern Generator vertical resolution. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_PPI_PG_PATTERN_VRES_ppi_pg_pattern_vres_MASK (0xFFFFU)
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_PATTERN_VRES_ppi_pg_pattern_vres_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_PATTERN_VRES_ppi_pg_pattern_vres(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PPI_PG_PATTERN_VRES_ppi_pg_pattern_vres_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PPI_PG_PATTERN_VRES_ppi_pg_pattern_vres_MASK)
/*! @} */

/*! @name PPI_PG_PATTERN_HRES - PPI Pattern Generator horizontal resolution. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_PPI_PG_PATTERN_HRES_ppi_pg_pattern_hres_MASK (0xFFFFU)
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_PATTERN_HRES_ppi_pg_pattern_hres_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_PATTERN_HRES_ppi_pg_pattern_hres(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PPI_PG_PATTERN_HRES_ppi_pg_pattern_hres_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PPI_PG_PATTERN_HRES_ppi_pg_pattern_hres_MASK)

#define SECONDARY_CSI2_CONTROLLER_PPI_PG_PATTERN_HRES_ppi_pg_pkt2pkt_time_MASK (0x3FF0000U)
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_PATTERN_HRES_ppi_pg_pkt2pkt_time_SHIFT (16U)
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_PATTERN_HRES_ppi_pg_pkt2pkt_time(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PPI_PG_PATTERN_HRES_ppi_pg_pkt2pkt_time_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PPI_PG_PATTERN_HRES_ppi_pg_pkt2pkt_time_MASK)
/*! @} */

/*! @name PPI_PG_CONFIG - PPI Pattern Generator Configuration. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_pattern_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_pattern_SHIFT (0U)
/*! ppi_pg_pattern
 *  0b0..Vertical Pattern
 *  0b1..Horizontal Pattern
 */
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_pattern(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_pattern_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_pattern_MASK)

#define SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_datatype_MASK (0x3F00U)
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_datatype_SHIFT (8U)
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_datatype(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_datatype_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_datatype_MASK)

#define SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_vc_MASK (0xC000U)
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_vc_SHIFT (14U)
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_vc(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_vc_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_vc_MASK)

#define SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_vcx_0_1_MASK (0x30000U)
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_vcx_0_1_SHIFT (16U)
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_vcx_0_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_vcx_0_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PPI_PG_CONFIG_ppi_pg_vcx_0_1_MASK)
/*! @} */

/*! @name PPI_PG_ENABLE - PPI Pattern Generator Enable. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_PPI_PG_ENABLE_ppi_pg_enable_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_ENABLE_ppi_pg_enable_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_ENABLE_ppi_pg_enable(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PPI_PG_ENABLE_ppi_pg_enable_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PPI_PG_ENABLE_ppi_pg_enable_MASK)
/*! @} */

/*! @name PPI_PG_STATUS - PPI Pattern Generator status. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_PPI_PG_STATUS_ppi_pg_status_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_STATUS_ppi_pg_status_SHIFT (0U)
/*! ppi_pg_status
 *  0b0..PPI PG is inactive
 *  0b1..PPI PG is running
 */
#define SECONDARY_CSI2_CONTROLLER_PPI_PG_STATUS_ppi_pg_status(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PPI_PG_STATUS_ppi_pg_status_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PPI_PG_STATUS_ppi_pg_status_MASK)
/*! @} */

/*! @name VC_EXTENSION - Virtual Channel Extension. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_VC_EXTENSION_vcx_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_VC_EXTENSION_vcx_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_VC_EXTENSION_vcx(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_VC_EXTENSION_vcx_SHIFT)) & SECONDARY_CSI2_CONTROLLER_VC_EXTENSION_vcx_MASK)
/*! @} */

/*! @name PHY_CAL - PHY Calibration. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_PHY_CAL_rxskewcalhs_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_PHY_CAL_rxskewcalhs_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_PHY_CAL_rxskewcalhs(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_PHY_CAL_rxskewcalhs_SHIFT)) & SECONDARY_CSI2_CONTROLLER_PHY_CAL_rxskewcalhs_MASK)
/*! @} */

/*! @name INT_ST_PHY_FATAL - Fatal interruption caused by PHY. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_FATAL_phy_errsotsynchs_0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_FATAL_phy_errsotsynchs_0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_FATAL_phy_errsotsynchs_0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_FATAL_phy_errsotsynchs_0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_FATAL_phy_errsotsynchs_0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_FATAL_phy_errsotsynchs_1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_FATAL_phy_errsotsynchs_1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_FATAL_phy_errsotsynchs_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_FATAL_phy_errsotsynchs_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_FATAL_phy_errsotsynchs_1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_FATAL_err_deskew_MASK (0x100U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_FATAL_err_deskew_SHIFT (8U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_FATAL_err_deskew(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_FATAL_err_deskew_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_FATAL_err_deskew_MASK)
/*! @} */

/*! @name INT_MSK_PHY_FATAL - Mask for fatal interruption caused by PHY. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_FATAL_err_deskew_MASK (0x100U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_FATAL_err_deskew_SHIFT (8U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_FATAL_err_deskew(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_FATAL_err_deskew_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_FATAL_err_deskew_MASK)
/*! @} */

/*! @name INT_FORCE_PHY_FATAL - Force for fatal interruption caused by PHY. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_FATAL_err_deskew_MASK (0x100U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_FATAL_err_deskew_SHIFT (8U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_FATAL_err_deskew(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_FATAL_err_deskew_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_FATAL_err_deskew_MASK)
/*! @} */

/*! @name INT_ST_PKT_FATAL - Fatal interruption caused during Packet Construction. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PKT_FATAL_err_ecc_double_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PKT_FATAL_err_ecc_double_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PKT_FATAL_err_ecc_double(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PKT_FATAL_err_ecc_double_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PKT_FATAL_err_ecc_double_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PKT_FATAL_shorter_payload_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PKT_FATAL_shorter_payload_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PKT_FATAL_shorter_payload(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PKT_FATAL_shorter_payload_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PKT_FATAL_shorter_payload_MASK)
/*! @} */

/*! @name INT_MSK_PKT_FATAL - Mask for fatal interruption caused during Packet Construction. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PKT_FATAL_mask_err_ecc_double_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PKT_FATAL_mask_err_ecc_double_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PKT_FATAL_mask_err_ecc_double(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PKT_FATAL_mask_err_ecc_double_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PKT_FATAL_mask_err_ecc_double_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PKT_FATAL_mask_shorter_payload_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PKT_FATAL_mask_shorter_payload_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PKT_FATAL_mask_shorter_payload(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PKT_FATAL_mask_shorter_payload_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PKT_FATAL_mask_shorter_payload_MASK)
/*! @} */

/*! @name INT_FORCE_PKT_FATAL - Force for fatal interruption caused during Packet Construction. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PKT_FATAL_force_err_ecc_double_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PKT_FATAL_force_err_ecc_double_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PKT_FATAL_force_err_ecc_double(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PKT_FATAL_force_err_ecc_double_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PKT_FATAL_force_err_ecc_double_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PKT_FATAL_force_shorter_payload_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PKT_FATAL_force_shorter_payload_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PKT_FATAL_force_shorter_payload(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PKT_FATAL_force_shorter_payload_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PKT_FATAL_force_shorter_payload_MASK)
/*! @} */

/*! @name INT_ST_PHY - Interruption caused by PHY. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_errsoths_0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_errsoths_0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_errsoths_0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_errsoths_0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_errsoths_0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_errsoths_1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_errsoths_1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_errsoths_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_errsoths_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_errsoths_1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_erresc_0_MASK (0x10000U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_erresc_0_SHIFT (16U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_erresc_0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_erresc_0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_erresc_0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_erresc_1_MASK (0x20000U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_erresc_1_SHIFT (17U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_erresc_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_erresc_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PHY_phy_erresc_1_MASK)
/*! @} */

/*! @name INT_MSK_PHY - Mask for interruption caused by PHY. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_errsoths_0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_errsoths_0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_errsoths_0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_errsoths_0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_errsoths_0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_errsoths_1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_errsoths_1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_errsoths_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_errsoths_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_errsoths_1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_erresc_0_MASK (0x10000U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_erresc_0_SHIFT (16U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_erresc_0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_erresc_0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_erresc_0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_erresc_1_MASK (0x20000U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_erresc_1_SHIFT (17U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_erresc_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_erresc_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PHY_mask_phy_erresc_1_MASK)
/*! @} */

/*! @name INT_FORCE_PHY - Force for interruption caused by PHY. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_errsoths_0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_errsoths_0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_errsoths_0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_errsoths_0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_errsoths_0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_errsoths_1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_errsoths_1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_errsoths_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_errsoths_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_errsoths_1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_erresc_0_MASK (0x10000U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_erresc_0_SHIFT (16U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_erresc_0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_erresc_0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_erresc_0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_erresc_1_MASK (0x20000U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_erresc_1_SHIFT (17U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_erresc_1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_erresc_1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PHY_force_phy_erresc_1_MASK)
/*! @} */

/*! @name INT_ST_LINE - Interruption occurred during Line construction. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_bndry_match_di7_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di0_MASK (0x10000U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di0_SHIFT (16U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di1_MASK (0x20000U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di1_SHIFT (17U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di2_MASK (0x40000U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di2_SHIFT (18U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di3_MASK (0x80000U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di3_SHIFT (19U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di4_MASK (0x100000U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di4_SHIFT (20U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di5_MASK (0x200000U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di5_SHIFT (21U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di6_MASK (0x400000U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di6_SHIFT (22U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di7_MASK (0x800000U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di7_SHIFT (23U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_LINE_err_l_seq_di7_MASK)
/*! @} */

/*! @name INT_MSK_LINE - Mask for interruption occurred during Line construction. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_bndry_match_di7_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di0_MASK (0x10000U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di0_SHIFT (16U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di1_MASK (0x20000U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di1_SHIFT (17U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di2_MASK (0x40000U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di2_SHIFT (18U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di3_MASK (0x80000U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di3_SHIFT (19U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di4_MASK (0x100000U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di4_SHIFT (20U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di5_MASK (0x200000U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di5_SHIFT (21U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di6_MASK (0x400000U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di6_SHIFT (22U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di7_MASK (0x800000U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di7_SHIFT (23U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_LINE_mask_err_l_seq_di7_MASK)
/*! @} */

/*! @name INT_FORCE_LINE - Force for interruption occurred during Line construction. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_bndry_match_di7_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di0_MASK (0x10000U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di0_SHIFT (16U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di1_MASK (0x20000U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di1_SHIFT (17U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di2_MASK (0x40000U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di2_SHIFT (18U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di3_MASK (0x80000U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di3_SHIFT (19U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di4_MASK (0x100000U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di4_SHIFT (20U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di5_MASK (0x200000U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di5_SHIFT (21U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di6_MASK (0x400000U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di6_SHIFT (22U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di7_MASK (0x800000U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di7_SHIFT (23U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_LINE_force_err_l_seq_di7_MASK)
/*! @} */

/*! @name INT_ST_BNDRY_FRAME_FATAL - Fatal Interruption caused by Frame Boundaries. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_BNDRY_FRAME_FATAL_err_f_bndry_match_vc7_MASK)
/*! @} */

/*! @name INT_MSK_BNDRY_FRAME_FATAL - Mask for fatal interruption caused by Frame Boundaries. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_BNDRY_FRAME_FATAL_err_f_bndry_match_vc7_MASK)
/*! @} */

/*! @name INT_FORCE_BNDRY_FRAME_FATAL - Force for fatal interruption caused by Frame Boundaries. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_BNDRY_FRAME_FATAL_err_f_bndry_match_vc7_MASK)
/*! @} */

/*! @name INT_ST_SEQ_FRAME_FATAL - Fatal Interruption caused by Frame Sequence. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_SEQ_FRAME_FATAL_err_f_seq_vc7_MASK)
/*! @} */

/*! @name INT_MSK_SEQ_FRAME_FATAL - Mask for fatal interruption caused by Frame Sequence. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_SEQ_FRAME_FATAL_err_f_seq_vc7_MASK)
/*! @} */

/*! @name INT_FORCE_SEQ_FRAME_FATAL - Force for fatal interruption caused by Frame Sequence. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_SEQ_FRAME_FATAL_err_f_seq_vc7_MASK)
/*! @} */

/*! @name INT_ST_CRC_FRAME_FATAL - Fatal Interruption caused by Frame CRC. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_CRC_FRAME_FATAL_err_frame_data_vc7_MASK)
/*! @} */

/*! @name INT_MSK_CRC_FRAME_FATAL - Mask for fatal interruption caused by Frame CRC. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_CRC_FRAME_FATAL_err_frame_data_vc7_MASK)
/*! @} */

/*! @name INT_FORCE_CRC_FRAME_FATAL - Force for fatal interruption caused by Frame CRC. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_CRC_FRAME_FATAL_err_frame_data_vc7_MASK)
/*! @} */

/*! @name INT_ST_PLD_CRC_FATAL - Fatal Interruption caused by Payload CRC. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_PLD_CRC_FATAL_err_crc_vc7_MASK)
/*! @} */

/*! @name INT_MSK_PLD_CRC_FATAL - Mask for fatal interruption caused by Payload CRC. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_PLD_CRC_FATAL_err_crc_vc7_MASK)
/*! @} */

/*! @name INT_FORCE_PLD_CRC_FATAL - Force for fatal interruption caused by Payload CRC. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_PLD_CRC_FATAL_err_crc_vc7_MASK)
/*! @} */

/*! @name INT_ST_DATA_ID - Interruption caused by Data Type. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_DATA_ID_err_id_vc7_MASK)
/*! @} */

/*! @name INT_MSK_DATA_ID - Mask for interruption caused by Data Type. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_DATA_ID_err_id_vc7_MASK)
/*! @} */

/*! @name INT_FORCE_DATA_ID - Force for interruption caused by Data Type. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_DATA_ID_err_id_vc7_MASK)
/*! @} */

/*! @name INT_ST_ECC_CORRECTED - Interruption caused by Header single bit errors. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_ST_ECC_CORRECTED_err_ecc_corrected_vc7_MASK)
/*! @} */

/*! @name INT_MSK_ECC_CORRECTED - Mask for interruption caused by Header single bit errors. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_MSK_ECC_CORRECTED_err_ecc_corrected_vc7_MASK)
/*! @} */

/*! @name INT_FORCE_ECC_CORRECTED - Force for interruption caused by Header single bit errors. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc0_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc0_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc0(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc0_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc0_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc1_MASK (0x2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc1_SHIFT (1U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc1_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc2_MASK (0x4U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc2_SHIFT (2U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc2_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc3_MASK (0x8U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc3_SHIFT (3U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc3_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc4_MASK (0x10U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc4_SHIFT (4U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc4_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc5_MASK (0x20U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc5_SHIFT (5U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc5(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc5_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc5_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc6_MASK (0x40U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc6_SHIFT (6U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc6(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc6_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc6_MASK)

#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc7_MASK (0x80U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc7_SHIFT (7U)
#define SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc7(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc7_SHIFT)) & SECONDARY_CSI2_CONTROLLER_INT_FORCE_ECC_CORRECTED_err_ecc_corrected_vc7_MASK)
/*! @} */

/*! @name SCRAMBLING - Data De-Scrambling. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_SCRAMBLING_scramble_enable_MASK (0x1U)
#define SECONDARY_CSI2_CONTROLLER_SCRAMBLING_scramble_enable_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_SCRAMBLING_scramble_enable(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_SCRAMBLING_scramble_enable_SHIFT)) & SECONDARY_CSI2_CONTROLLER_SCRAMBLING_scramble_enable_MASK)
/*! @} */

/*! @name SCRAMBLING_SEED1 - De-scrambler seed for lane1. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED1_scramble_seed_lane1_MASK (0xFFFFU)
#define SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED1_scramble_seed_lane1_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED1_scramble_seed_lane1(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED1_scramble_seed_lane1_SHIFT)) & SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED1_scramble_seed_lane1_MASK)
/*! @} */

/*! @name SCRAMBLING_SEED2 - De-scrambler seed for lane2. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED2_scramble_seed_lane2_MASK (0xFFFFU)
#define SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED2_scramble_seed_lane2_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED2_scramble_seed_lane2(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED2_scramble_seed_lane2_SHIFT)) & SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED2_scramble_seed_lane2_MASK)
/*! @} */

/*! @name SCRAMBLING_SEED3 - De-scrambler seed for lane3. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED3_scramble_seed_lane3_MASK (0xFFFFU)
#define SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED3_scramble_seed_lane3_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED3_scramble_seed_lane3(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED3_scramble_seed_lane3_SHIFT)) & SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED3_scramble_seed_lane3_MASK)
/*! @} */

/*! @name SCRAMBLING_SEED4 - De-scrambler seed for lane4. */
/*! @{ */

#define SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED4_scramble_seed_lane4_MASK (0xFFFFU)
#define SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED4_scramble_seed_lane4_SHIFT (0U)
#define SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED4_scramble_seed_lane4(x) (((uint32_t)(((uint32_t)(x)) << SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED4_scramble_seed_lane4_SHIFT)) & SECONDARY_CSI2_CONTROLLER_SCRAMBLING_SEED4_scramble_seed_lane4_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SECONDARY_CSI2_CONTROLLER_Register_Masks */


/*!
 * @}
 */ /* end of group SECONDARY_CSI2_CONTROLLER_Peripheral_Access_Layer */


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


#endif  /* PERI_SECONDARY_CSI2_CONTROLLER_H_ */

