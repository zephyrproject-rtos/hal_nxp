/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for HDMI_TX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_HDMI_TX.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for HDMI_TX
 *
 * CMSIS Peripheral Access Layer for HDMI_TX
 */

#if !defined(PERI_HDMI_TX_H_)
#define PERI_HDMI_TX_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- HDMI_TX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HDMI_TX_Peripheral_Access_Layer HDMI_TX Peripheral Access Layer
 * @{
 */

/** HDMI_TX - Register Layout Typedef */
typedef struct {
  __IO uint32_t APB_CTRL;                          /**< offset: 0x0 */
  __IO uint32_t XT_INT_CTRL;                       /**< offset: 0x4 */
  __I  uint32_t MAILBOX_FULL_ADDR;                 /**< offset: 0x8 */
  __I  uint32_t MAILBOX_EMPTY_ADDR;                /**< offset: 0xC */
  __IO uint32_t MAILBOX0_WR_DATA;                  /**< offset: 0x10 */
  __I  uint32_t MAILBOX0_RD_DATA;                  /**< offset: 0x14 */
  __I  uint32_t KEEP_ALIVE;                        /**< offset: 0x18 */
  __I  uint32_t VER_L;                             /**< offset: 0x1C */
  __I  uint32_t VER_H;                             /**< offset: 0x20 */
  __I  uint32_t VER_LIB_L_ADDR;                    /**< offset: 0x24 */
  __I  uint32_t VER_LIB_H_ADDR;                    /**< offset: 0x28 */
  __I  uint32_t SW_DEBUG_L;                        /**< offset: 0x2C */
  __I  uint32_t SW_DEBUG_H;                        /**< offset: 0x30 */
  __IO uint32_t MAILBOX_INT_MASK;                  /**< offset: 0x34 */
  __I  uint32_t MAILBOX_INT_STATUS;                /**< offset: 0x38 */
  __IO uint32_t SW_CLK_L;                          /**< offset: 0x3C */
  __IO uint32_t SW_CLK_H;                          /**< offset: 0x40 */
  __I  uint32_t SW_EVENTS0;                        /**< offset: 0x44 */
  __I  uint32_t SW_EVENTS1;                        /**< offset: 0x48 */
  __I  uint32_t SW_EVENTS2;                        /**< offset: 0x4C */
  __I  uint32_t SW_EVENTS3;                        /**< offset: 0x50 */
       uint8_t RESERVED_0[12];
  __IO uint32_t XT_OCD_CTRL;                       /**< offset: 0x60 */
  __I  uint32_t XT_OCD_CTRL_RO;                    /**< offset: 0x64 */
       uint8_t RESERVED_1[4];
  __IO uint32_t APB_INT_MASK;                      /**< offset: 0x6C */
  __I  uint32_t APB_STATUS_MASK;                   /**< offset: 0x70 */
       uint8_t RESERVED_2[196492];
  __IO uint32_t AUDIO_SRC_CNTL;                    /**< offset: 0x30000 */
  __IO uint32_t AUDIO_SRC_CNFG;                    /**< offset: 0x30004 */
  __IO uint32_t COM_CH_STTS_BITS;                  /**< offset: 0x30008 */
  __IO uint32_t STTS_BIT_CH01;                     /**< offset: 0x3000C */
  __IO uint32_t STTS_BIT_CH23;                     /**< offset: 0x30010 */
  __IO uint32_t STTS_BIT_CH45;                     /**< offset: 0x30014 */
  __IO uint32_t STTS_BIT_CH67;                     /**< offset: 0x30018 */
  __IO uint32_t STTS_BIT_CH89;                     /**< offset: 0x3001C */
  __IO uint32_t STTS_BIT_CH1011;                   /**< offset: 0x30020 */
  __IO uint32_t STTS_BIT_CH1213;                   /**< offset: 0x30024 */
  __IO uint32_t STTS_BIT_CH1415;                   /**< offset: 0x30028 */
  __IO uint32_t STTS_BIT_CH1617;                   /**< offset: 0x3002C */
  __IO uint32_t STTS_BIT_CH1819;                   /**< offset: 0x30030 */
  __IO uint32_t STTS_BIT_CH2021;                   /**< offset: 0x30034 */
  __IO uint32_t STTS_BIT_CH2223;                   /**< offset: 0x30038 */
  __IO uint32_t STTS_BIT_CH2425;                   /**< offset: 0x3003C */
  __IO uint32_t STTS_BIT_CH2627;                   /**< offset: 0x30040 */
  __IO uint32_t STTS_BIT_CH2829;                   /**< offset: 0x30044 */
  __IO uint32_t STTS_BIT_CH3031;                   /**< offset: 0x30048 */
  __IO uint32_t SPDIF_CTRL_ADDR;                   /**< offset: 0x3004C */
  __I  uint32_t SPDIF_CH1_CS_3100_ADDR;            /**< offset: 0x30050 */
  __I  uint32_t SPDIF_CH1_CS_6332_ADDR;            /**< offset: 0x30054 */
  __I  uint32_t SPDIF_CH1_CS_9564_ADDR;            /**< offset: 0x30058 */
  __I  uint32_t SPDIF_CH1_CS_12796_ADDR;           /**< offset: 0x3005C */
  __I  uint32_t SPDIF_CH1_CS_159128_ADDR;          /**< offset: 0x30060 */
  __I  uint32_t SPDIF_CH1_CS_191160_ADDR;          /**< offset: 0x30064 */
  __I  uint32_t SPDIF_CH2_CS_3100_ADDR;            /**< offset: 0x30068 */
  __I  uint32_t SPDIF_CH2_CS_6332_ADDR;            /**< offset: 0x3006C */
  __I  uint32_t SPDIF_CH2_CS_9564_ADDR;            /**< offset: 0x30070 */
  __I  uint32_t SPDIF_CH2_CS_12796_ADDR;           /**< offset: 0x30074 */
  __I  uint32_t SPDIF_CH2_CS_159128_ADDR;          /**< offset: 0x30078 */
  __I  uint32_t SPDIF_CH2_CS_191160_ADDR;          /**< offset: 0x3007C */
  __IO uint32_t SMPL2PKT_CNTL;                     /**< offset: 0x30080 */
  __IO uint32_t SMPL2PKT_CNFG;                     /**< offset: 0x30084 */
  __IO uint32_t FIFO_CNTL;                         /**< offset: 0x30088 */
  __I  uint32_t FIFO_STTS;                         /**< offset: 0x3008C */
  __IO uint32_t SUB_PCKT_THRSH;                    /**< offset: 0x30090 */
       uint8_t RESERVED_3[1900];
  __IO uint32_t SOURCE_PIF_WR_ADDR;                /**< offset: 0x30800 */
  __IO uint32_t SOURCE_PIF_WR_REQ;                 /**< offset: 0x30804 */
  __IO uint32_t SOURCE_PIF_RD_ADDR;                /**< offset: 0x30808 */
  __IO uint32_t SOURCE_PIF_RD_REQ;                 /**< offset: 0x3080C */
  __IO uint32_t SOURCE_PIF_DATA_WR;                /**< offset: 0x30810 */
  __I  uint32_t SOURCE_PIF_DATA_RD;                /**< offset: 0x30814 */
  __IO uint32_t SOURCE_PIF_FIFO1_FLUSH;            /**< offset: 0x30818 */
  __IO uint32_t SOURCE_PIF_FIFO2_FLUSH;            /**< offset: 0x3081C */
  __I  uint32_t SOURCE_PIF_STATUS;                 /**< offset: 0x30820 */
  __I  uint32_t SOURCE_PIF_INTERRUPT_SOURCE;       /**< offset: 0x30824 */
  __IO uint32_t SOURCE_PIF_INTERRUPT_MASK;         /**< offset: 0x30828 */
  __IO uint32_t SOURCE_PIF_PKT_ALLOC_REG;          /**< offset: 0x3082C */
  __IO uint32_t SOURCE_PIF_PKT_ALLOC_WR_EN;        /**< offset: 0x30830 */
  __IO uint32_t SOURCE_PIF_SW_RESET;               /**< offset: 0x30834 */
} HDMI_TX_Type;

/* ----------------------------------------------------------------------------
   -- HDMI_TX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HDMI_TX_Register_Masks HDMI_TX Register Masks
 * @{
 */

/*! @name APB_CTRL -  */
/*! @{ */

#define HDMI_TX_APB_CTRL_apb_xt_reset_MASK       (0x1U)
#define HDMI_TX_APB_CTRL_apb_xt_reset_SHIFT      (0U)
/*! apb_xt_reset - APB Control on the CPU reset active High */
#define HDMI_TX_APB_CTRL_apb_xt_reset(x)         (((uint32_t)(((uint32_t)(x)) << HDMI_TX_APB_CTRL_apb_xt_reset_SHIFT)) & HDMI_TX_APB_CTRL_apb_xt_reset_MASK)

#define HDMI_TX_APB_CTRL_apb_dram_path_MASK      (0x2U)
#define HDMI_TX_APB_CTRL_apb_dram_path_SHIFT     (1U)
/*! apb_dram_path - When 1 enable APB to R/W the DRAM */
#define HDMI_TX_APB_CTRL_apb_dram_path(x)        (((uint32_t)(((uint32_t)(x)) << HDMI_TX_APB_CTRL_apb_dram_path_SHIFT)) & HDMI_TX_APB_CTRL_apb_dram_path_MASK)

#define HDMI_TX_APB_CTRL_apb_iram_path_MASK      (0x4U)
#define HDMI_TX_APB_CTRL_apb_iram_path_SHIFT     (2U)
/*! apb_iram_path - When 1 enable APB to R/W the IRAM */
#define HDMI_TX_APB_CTRL_apb_iram_path(x)        (((uint32_t)(((uint32_t)(x)) << HDMI_TX_APB_CTRL_apb_iram_path_SHIFT)) & HDMI_TX_APB_CTRL_apb_iram_path_MASK)

#define HDMI_TX_APB_CTRL_reserved_0_MASK         (0xFFFFFFF8U)
#define HDMI_TX_APB_CTRL_reserved_0_SHIFT        (3U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_APB_CTRL_reserved_0(x)           (((uint32_t)(((uint32_t)(x)) << HDMI_TX_APB_CTRL_reserved_0_SHIFT)) & HDMI_TX_APB_CTRL_reserved_0_MASK)
/*! @} */

/*! @name XT_INT_CTRL -  */
/*! @{ */

#define HDMI_TX_XT_INT_CTRL_xt_int_polarity_MASK (0x3U)
#define HDMI_TX_XT_INT_CTRL_xt_int_polarity_SHIFT (0U)
/*! xt_int_polarity - xt_int_polarity */
#define HDMI_TX_XT_INT_CTRL_xt_int_polarity(x)   (((uint32_t)(((uint32_t)(x)) << HDMI_TX_XT_INT_CTRL_xt_int_polarity_SHIFT)) & HDMI_TX_XT_INT_CTRL_xt_int_polarity_MASK)

#define HDMI_TX_XT_INT_CTRL_reserved_0_MASK      (0xFFFFFFFCU)
#define HDMI_TX_XT_INT_CTRL_reserved_0_SHIFT     (2U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_XT_INT_CTRL_reserved_0(x)        (((uint32_t)(((uint32_t)(x)) << HDMI_TX_XT_INT_CTRL_reserved_0_SHIFT)) & HDMI_TX_XT_INT_CTRL_reserved_0_MASK)
/*! @} */

/*! @name MAILBOX_FULL_ADDR -  */
/*! @{ */

#define HDMI_TX_MAILBOX_FULL_ADDR_mailbox_full_MASK (0x1U)
#define HDMI_TX_MAILBOX_FULL_ADDR_mailbox_full_SHIFT (0U)
/*! mailbox_full - Mailboxes full indication */
#define HDMI_TX_MAILBOX_FULL_ADDR_mailbox_full(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_MAILBOX_FULL_ADDR_mailbox_full_SHIFT)) & HDMI_TX_MAILBOX_FULL_ADDR_mailbox_full_MASK)

#define HDMI_TX_MAILBOX_FULL_ADDR_reserved_0_MASK (0xFFFFFFFEU)
#define HDMI_TX_MAILBOX_FULL_ADDR_reserved_0_SHIFT (1U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_MAILBOX_FULL_ADDR_reserved_0(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_MAILBOX_FULL_ADDR_reserved_0_SHIFT)) & HDMI_TX_MAILBOX_FULL_ADDR_reserved_0_MASK)
/*! @} */

/*! @name MAILBOX_EMPTY_ADDR -  */
/*! @{ */

#define HDMI_TX_MAILBOX_EMPTY_ADDR_mailbox_empty_MASK (0x1U)
#define HDMI_TX_MAILBOX_EMPTY_ADDR_mailbox_empty_SHIFT (0U)
/*! mailbox_empty - Mailboxes Empty indication */
#define HDMI_TX_MAILBOX_EMPTY_ADDR_mailbox_empty(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_MAILBOX_EMPTY_ADDR_mailbox_empty_SHIFT)) & HDMI_TX_MAILBOX_EMPTY_ADDR_mailbox_empty_MASK)

#define HDMI_TX_MAILBOX_EMPTY_ADDR_reserved_0_MASK (0xFFFFFFFEU)
#define HDMI_TX_MAILBOX_EMPTY_ADDR_reserved_0_SHIFT (1U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_MAILBOX_EMPTY_ADDR_reserved_0(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_MAILBOX_EMPTY_ADDR_reserved_0_SHIFT)) & HDMI_TX_MAILBOX_EMPTY_ADDR_reserved_0_MASK)
/*! @} */

/*! @name MAILBOX0_WR_DATA -  */
/*! @{ */

#define HDMI_TX_MAILBOX0_WR_DATA_mailbox0_wr_data_MASK (0xFFU)
#define HDMI_TX_MAILBOX0_WR_DATA_mailbox0_wr_data_SHIFT (0U)
/*! mailbox0_wr_data - Write Data to Mailbox */
#define HDMI_TX_MAILBOX0_WR_DATA_mailbox0_wr_data(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_MAILBOX0_WR_DATA_mailbox0_wr_data_SHIFT)) & HDMI_TX_MAILBOX0_WR_DATA_mailbox0_wr_data_MASK)

#define HDMI_TX_MAILBOX0_WR_DATA_reserved_0_MASK (0xFFFFFF00U)
#define HDMI_TX_MAILBOX0_WR_DATA_reserved_0_SHIFT (8U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_MAILBOX0_WR_DATA_reserved_0(x)   (((uint32_t)(((uint32_t)(x)) << HDMI_TX_MAILBOX0_WR_DATA_reserved_0_SHIFT)) & HDMI_TX_MAILBOX0_WR_DATA_reserved_0_MASK)
/*! @} */

/*! @name MAILBOX0_RD_DATA -  */
/*! @{ */

#define HDMI_TX_MAILBOX0_RD_DATA_mailbox0_rd_data_MASK (0xFFU)
#define HDMI_TX_MAILBOX0_RD_DATA_mailbox0_rd_data_SHIFT (0U)
/*! mailbox0_rd_data - Mailbox Read data */
#define HDMI_TX_MAILBOX0_RD_DATA_mailbox0_rd_data(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_MAILBOX0_RD_DATA_mailbox0_rd_data_SHIFT)) & HDMI_TX_MAILBOX0_RD_DATA_mailbox0_rd_data_MASK)

#define HDMI_TX_MAILBOX0_RD_DATA_reserved_0_MASK (0xFFFFFF00U)
#define HDMI_TX_MAILBOX0_RD_DATA_reserved_0_SHIFT (8U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_MAILBOX0_RD_DATA_reserved_0(x)   (((uint32_t)(((uint32_t)(x)) << HDMI_TX_MAILBOX0_RD_DATA_reserved_0_SHIFT)) & HDMI_TX_MAILBOX0_RD_DATA_reserved_0_MASK)
/*! @} */

/*! @name KEEP_ALIVE -  */
/*! @{ */

#define HDMI_TX_KEEP_ALIVE_keep_alive_cnt_MASK   (0xFFU)
#define HDMI_TX_KEEP_ALIVE_keep_alive_cnt_SHIFT  (0U)
/*! keep_alive_cnt - Software keep alive counter */
#define HDMI_TX_KEEP_ALIVE_keep_alive_cnt(x)     (((uint32_t)(((uint32_t)(x)) << HDMI_TX_KEEP_ALIVE_keep_alive_cnt_SHIFT)) & HDMI_TX_KEEP_ALIVE_keep_alive_cnt_MASK)

#define HDMI_TX_KEEP_ALIVE_reserved_0_MASK       (0xFFFFFF00U)
#define HDMI_TX_KEEP_ALIVE_reserved_0_SHIFT      (8U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_KEEP_ALIVE_reserved_0(x)         (((uint32_t)(((uint32_t)(x)) << HDMI_TX_KEEP_ALIVE_reserved_0_SHIFT)) & HDMI_TX_KEEP_ALIVE_reserved_0_MASK)
/*! @} */

/*! @name VER_L -  */
/*! @{ */

#define HDMI_TX_VER_L_ver_lsb_MASK               (0xFFU)
#define HDMI_TX_VER_L_ver_lsb_SHIFT              (0U)
/*! ver_lsb - Software Version LSB */
#define HDMI_TX_VER_L_ver_lsb(x)                 (((uint32_t)(((uint32_t)(x)) << HDMI_TX_VER_L_ver_lsb_SHIFT)) & HDMI_TX_VER_L_ver_lsb_MASK)

#define HDMI_TX_VER_L_reserved_0_MASK            (0xFFFFFF00U)
#define HDMI_TX_VER_L_reserved_0_SHIFT           (8U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_VER_L_reserved_0(x)              (((uint32_t)(((uint32_t)(x)) << HDMI_TX_VER_L_reserved_0_SHIFT)) & HDMI_TX_VER_L_reserved_0_MASK)
/*! @} */

/*! @name VER_H -  */
/*! @{ */

#define HDMI_TX_VER_H_ver_msb_MASK               (0xFFU)
#define HDMI_TX_VER_H_ver_msb_SHIFT              (0U)
/*! ver_msb - Software Version MSB */
#define HDMI_TX_VER_H_ver_msb(x)                 (((uint32_t)(((uint32_t)(x)) << HDMI_TX_VER_H_ver_msb_SHIFT)) & HDMI_TX_VER_H_ver_msb_MASK)

#define HDMI_TX_VER_H_reserved_0_MASK            (0xFFFFFF00U)
#define HDMI_TX_VER_H_reserved_0_SHIFT           (8U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_VER_H_reserved_0(x)              (((uint32_t)(((uint32_t)(x)) << HDMI_TX_VER_H_reserved_0_SHIFT)) & HDMI_TX_VER_H_reserved_0_MASK)
/*! @} */

/*! @name VER_LIB_L_ADDR -  */
/*! @{ */

#define HDMI_TX_VER_LIB_L_ADDR_sw_lib_ver_l_MASK (0xFFU)
#define HDMI_TX_VER_LIB_L_ADDR_sw_lib_ver_l_SHIFT (0U)
/*! sw_lib_ver_l - Software Lib version written by CPU */
#define HDMI_TX_VER_LIB_L_ADDR_sw_lib_ver_l(x)   (((uint32_t)(((uint32_t)(x)) << HDMI_TX_VER_LIB_L_ADDR_sw_lib_ver_l_SHIFT)) & HDMI_TX_VER_LIB_L_ADDR_sw_lib_ver_l_MASK)

#define HDMI_TX_VER_LIB_L_ADDR_reserved_0_MASK   (0xFFFFFF00U)
#define HDMI_TX_VER_LIB_L_ADDR_reserved_0_SHIFT  (8U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_VER_LIB_L_ADDR_reserved_0(x)     (((uint32_t)(((uint32_t)(x)) << HDMI_TX_VER_LIB_L_ADDR_reserved_0_SHIFT)) & HDMI_TX_VER_LIB_L_ADDR_reserved_0_MASK)
/*! @} */

/*! @name VER_LIB_H_ADDR -  */
/*! @{ */

#define HDMI_TX_VER_LIB_H_ADDR_sw_lib_ver_h_MASK (0xFFU)
#define HDMI_TX_VER_LIB_H_ADDR_sw_lib_ver_h_SHIFT (0U)
/*! sw_lib_ver_h - Software Lib version written by CPU */
#define HDMI_TX_VER_LIB_H_ADDR_sw_lib_ver_h(x)   (((uint32_t)(((uint32_t)(x)) << HDMI_TX_VER_LIB_H_ADDR_sw_lib_ver_h_SHIFT)) & HDMI_TX_VER_LIB_H_ADDR_sw_lib_ver_h_MASK)

#define HDMI_TX_VER_LIB_H_ADDR_reserved_0_MASK   (0xFFFFFF00U)
#define HDMI_TX_VER_LIB_H_ADDR_reserved_0_SHIFT  (8U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_VER_LIB_H_ADDR_reserved_0(x)     (((uint32_t)(((uint32_t)(x)) << HDMI_TX_VER_LIB_H_ADDR_reserved_0_SHIFT)) & HDMI_TX_VER_LIB_H_ADDR_reserved_0_MASK)
/*! @} */

/*! @name SW_DEBUG_L -  */
/*! @{ */

#define HDMI_TX_SW_DEBUG_L_sw_debug_7_0_MASK     (0xFFU)
#define HDMI_TX_SW_DEBUG_L_sw_debug_7_0_SHIFT    (0U)
/*! sw_debug_7_0 - sw_debug_7_0 */
#define HDMI_TX_SW_DEBUG_L_sw_debug_7_0(x)       (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SW_DEBUG_L_sw_debug_7_0_SHIFT)) & HDMI_TX_SW_DEBUG_L_sw_debug_7_0_MASK)

#define HDMI_TX_SW_DEBUG_L_reserved_0_MASK       (0xFFFFFF00U)
#define HDMI_TX_SW_DEBUG_L_reserved_0_SHIFT      (8U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SW_DEBUG_L_reserved_0(x)         (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SW_DEBUG_L_reserved_0_SHIFT)) & HDMI_TX_SW_DEBUG_L_reserved_0_MASK)
/*! @} */

/*! @name SW_DEBUG_H -  */
/*! @{ */

#define HDMI_TX_SW_DEBUG_H_sw_debug_15_8_MASK    (0xFFU)
#define HDMI_TX_SW_DEBUG_H_sw_debug_15_8_SHIFT   (0U)
/*! sw_debug_15_8 - sw_debug_15_8 */
#define HDMI_TX_SW_DEBUG_H_sw_debug_15_8(x)      (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SW_DEBUG_H_sw_debug_15_8_SHIFT)) & HDMI_TX_SW_DEBUG_H_sw_debug_15_8_MASK)

#define HDMI_TX_SW_DEBUG_H_reserved_0_MASK       (0xFFFFFF00U)
#define HDMI_TX_SW_DEBUG_H_reserved_0_SHIFT      (8U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SW_DEBUG_H_reserved_0(x)         (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SW_DEBUG_H_reserved_0_SHIFT)) & HDMI_TX_SW_DEBUG_H_reserved_0_MASK)
/*! @} */

/*! @name MAILBOX_INT_MASK -  */
/*! @{ */

#define HDMI_TX_MAILBOX_INT_MASK_mailbox_int_mask_MASK (0x3U)
#define HDMI_TX_MAILBOX_INT_MASK_mailbox_int_mask_SHIFT (0U)
/*! mailbox_int_mask - Mailbox Interupt mask Bit[0] - Empty Bit[1] - Full */
#define HDMI_TX_MAILBOX_INT_MASK_mailbox_int_mask(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_MAILBOX_INT_MASK_mailbox_int_mask_SHIFT)) & HDMI_TX_MAILBOX_INT_MASK_mailbox_int_mask_MASK)

#define HDMI_TX_MAILBOX_INT_MASK_reserved_0_MASK (0xFFFFFFFCU)
#define HDMI_TX_MAILBOX_INT_MASK_reserved_0_SHIFT (2U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_MAILBOX_INT_MASK_reserved_0(x)   (((uint32_t)(((uint32_t)(x)) << HDMI_TX_MAILBOX_INT_MASK_reserved_0_SHIFT)) & HDMI_TX_MAILBOX_INT_MASK_reserved_0_MASK)
/*! @} */

/*! @name MAILBOX_INT_STATUS -  */
/*! @{ */

#define HDMI_TX_MAILBOX_INT_STATUS_mailbox_int_status_MASK (0x3U)
#define HDMI_TX_MAILBOX_INT_STATUS_mailbox_int_status_SHIFT (0U)
/*! mailbox_int_status - Mailbox Interupt Status Bit[0] - Empty Bit[1] - Full */
#define HDMI_TX_MAILBOX_INT_STATUS_mailbox_int_status(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_MAILBOX_INT_STATUS_mailbox_int_status_SHIFT)) & HDMI_TX_MAILBOX_INT_STATUS_mailbox_int_status_MASK)

#define HDMI_TX_MAILBOX_INT_STATUS_reserved_0_MASK (0xFFFFFFFCU)
#define HDMI_TX_MAILBOX_INT_STATUS_reserved_0_SHIFT (2U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_MAILBOX_INT_STATUS_reserved_0(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_MAILBOX_INT_STATUS_reserved_0_SHIFT)) & HDMI_TX_MAILBOX_INT_STATUS_reserved_0_MASK)
/*! @} */

/*! @name SW_CLK_L -  */
/*! @{ */

#define HDMI_TX_SW_CLK_L_sw_clock_val_l_MASK     (0xFFU)
#define HDMI_TX_SW_CLK_L_sw_clock_val_l_SHIFT    (0U)
/*! sw_clock_val_l - Fractial of the clock decimal value */
#define HDMI_TX_SW_CLK_L_sw_clock_val_l(x)       (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SW_CLK_L_sw_clock_val_l_SHIFT)) & HDMI_TX_SW_CLK_L_sw_clock_val_l_MASK)

#define HDMI_TX_SW_CLK_L_reserved_0_MASK         (0xFFFFFF00U)
#define HDMI_TX_SW_CLK_L_reserved_0_SHIFT        (8U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SW_CLK_L_reserved_0(x)           (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SW_CLK_L_reserved_0_SHIFT)) & HDMI_TX_SW_CLK_L_reserved_0_MASK)
/*! @} */

/*! @name SW_CLK_H -  */
/*! @{ */

#define HDMI_TX_SW_CLK_H_sw_clock_val_h_MASK     (0xFFU)
#define HDMI_TX_SW_CLK_H_sw_clock_val_h_SHIFT    (0U)
/*! sw_clock_val_h - Clock frequency in decimal values */
#define HDMI_TX_SW_CLK_H_sw_clock_val_h(x)       (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SW_CLK_H_sw_clock_val_h_SHIFT)) & HDMI_TX_SW_CLK_H_sw_clock_val_h_MASK)

#define HDMI_TX_SW_CLK_H_reserved_0_MASK         (0xFFFFFF00U)
#define HDMI_TX_SW_CLK_H_reserved_0_SHIFT        (8U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SW_CLK_H_reserved_0(x)           (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SW_CLK_H_reserved_0_SHIFT)) & HDMI_TX_SW_CLK_H_reserved_0_MASK)
/*! @} */

/*! @name SW_EVENTS0 -  */
/*! @{ */

#define HDMI_TX_SW_EVENTS0_sw_events7_0_MASK     (0xFFU)
#define HDMI_TX_SW_EVENTS0_sw_events7_0_SHIFT    (0U)
/*! sw_events7_0 - When SW writes it updted just the extra event bits When Host read it is cleared */
#define HDMI_TX_SW_EVENTS0_sw_events7_0(x)       (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SW_EVENTS0_sw_events7_0_SHIFT)) & HDMI_TX_SW_EVENTS0_sw_events7_0_MASK)

#define HDMI_TX_SW_EVENTS0_reserved_0_MASK       (0xFFFFFF00U)
#define HDMI_TX_SW_EVENTS0_reserved_0_SHIFT      (8U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SW_EVENTS0_reserved_0(x)         (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SW_EVENTS0_reserved_0_SHIFT)) & HDMI_TX_SW_EVENTS0_reserved_0_MASK)
/*! @} */

/*! @name SW_EVENTS1 -  */
/*! @{ */

#define HDMI_TX_SW_EVENTS1_sw_events15_8_MASK    (0xFFU)
#define HDMI_TX_SW_EVENTS1_sw_events15_8_SHIFT   (0U)
/*! sw_events15_8 - When SW writes it updted just the extra event bits When Host read it is cleared */
#define HDMI_TX_SW_EVENTS1_sw_events15_8(x)      (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SW_EVENTS1_sw_events15_8_SHIFT)) & HDMI_TX_SW_EVENTS1_sw_events15_8_MASK)

#define HDMI_TX_SW_EVENTS1_reserved_0_MASK       (0xFFFFFF00U)
#define HDMI_TX_SW_EVENTS1_reserved_0_SHIFT      (8U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SW_EVENTS1_reserved_0(x)         (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SW_EVENTS1_reserved_0_SHIFT)) & HDMI_TX_SW_EVENTS1_reserved_0_MASK)
/*! @} */

/*! @name SW_EVENTS2 -  */
/*! @{ */

#define HDMI_TX_SW_EVENTS2_sw_events23_16_MASK   (0xFFU)
#define HDMI_TX_SW_EVENTS2_sw_events23_16_SHIFT  (0U)
/*! sw_events23_16 - When SW writes it updted just the extra event bits When Host read it is cleared */
#define HDMI_TX_SW_EVENTS2_sw_events23_16(x)     (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SW_EVENTS2_sw_events23_16_SHIFT)) & HDMI_TX_SW_EVENTS2_sw_events23_16_MASK)

#define HDMI_TX_SW_EVENTS2_reserved_0_MASK       (0xFFFFFF00U)
#define HDMI_TX_SW_EVENTS2_reserved_0_SHIFT      (8U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SW_EVENTS2_reserved_0(x)         (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SW_EVENTS2_reserved_0_SHIFT)) & HDMI_TX_SW_EVENTS2_reserved_0_MASK)
/*! @} */

/*! @name SW_EVENTS3 -  */
/*! @{ */

#define HDMI_TX_SW_EVENTS3_sw_events31_24_MASK   (0xFFU)
#define HDMI_TX_SW_EVENTS3_sw_events31_24_SHIFT  (0U)
/*! sw_events31_24 - When SW writes it updted just the extra event bits When Host read it is cleared */
#define HDMI_TX_SW_EVENTS3_sw_events31_24(x)     (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SW_EVENTS3_sw_events31_24_SHIFT)) & HDMI_TX_SW_EVENTS3_sw_events31_24_MASK)

#define HDMI_TX_SW_EVENTS3_reserved_0_MASK       (0xFFFFFF00U)
#define HDMI_TX_SW_EVENTS3_reserved_0_SHIFT      (8U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SW_EVENTS3_reserved_0(x)         (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SW_EVENTS3_reserved_0_SHIFT)) & HDMI_TX_SW_EVENTS3_reserved_0_MASK)
/*! @} */

/*! @name XT_OCD_CTRL -  */
/*! @{ */

#define HDMI_TX_XT_OCD_CTRL_xt_dreset_MASK       (0x1U)
#define HDMI_TX_XT_OCD_CTRL_xt_dreset_SHIFT      (0U)
/*! xt_dreset - Xtensa Dreset control register */
#define HDMI_TX_XT_OCD_CTRL_xt_dreset(x)         (((uint32_t)(((uint32_t)(x)) << HDMI_TX_XT_OCD_CTRL_xt_dreset_SHIFT)) & HDMI_TX_XT_OCD_CTRL_xt_dreset_MASK)

#define HDMI_TX_XT_OCD_CTRL_xt_ocdhaltonreset_MASK (0x2U)
#define HDMI_TX_XT_OCD_CTRL_xt_ocdhaltonreset_SHIFT (1U)
/*! xt_ocdhaltonreset - Xtensa Halt On Reget configuration register */
#define HDMI_TX_XT_OCD_CTRL_xt_ocdhaltonreset(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_XT_OCD_CTRL_xt_ocdhaltonreset_SHIFT)) & HDMI_TX_XT_OCD_CTRL_xt_ocdhaltonreset_MASK)

#define HDMI_TX_XT_OCD_CTRL_reserved_0_MASK      (0xFFFFFFFCU)
#define HDMI_TX_XT_OCD_CTRL_reserved_0_SHIFT     (2U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_XT_OCD_CTRL_reserved_0(x)        (((uint32_t)(((uint32_t)(x)) << HDMI_TX_XT_OCD_CTRL_reserved_0_SHIFT)) & HDMI_TX_XT_OCD_CTRL_reserved_0_MASK)
/*! @} */

/*! @name XT_OCD_CTRL_RO -  */
/*! @{ */

#define HDMI_TX_XT_OCD_CTRL_RO_xt_xocdmode_MASK  (0x1U)
#define HDMI_TX_XT_OCD_CTRL_RO_xt_xocdmode_SHIFT (0U)
/*! xt_xocdmode - Xtensa OCD mode configuration */
#define HDMI_TX_XT_OCD_CTRL_RO_xt_xocdmode(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_XT_OCD_CTRL_RO_xt_xocdmode_SHIFT)) & HDMI_TX_XT_OCD_CTRL_RO_xt_xocdmode_MASK)

#define HDMI_TX_XT_OCD_CTRL_RO_reserved_0_MASK   (0xFFFFFFFEU)
#define HDMI_TX_XT_OCD_CTRL_RO_reserved_0_SHIFT  (1U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_XT_OCD_CTRL_RO_reserved_0(x)     (((uint32_t)(((uint32_t)(x)) << HDMI_TX_XT_OCD_CTRL_RO_reserved_0_SHIFT)) & HDMI_TX_XT_OCD_CTRL_RO_reserved_0_MASK)
/*! @} */

/*! @name APB_INT_MASK -  */
/*! @{ */

#define HDMI_TX_APB_INT_MASK_apb_intr_mask_MASK  (0x7U)
#define HDMI_TX_APB_INT_MASK_apb_intr_mask_SHIFT (0U)
/*! apb_intr_mask - Mask the APB interupt Bit0 - Mailbox Interupt Bit1 - PIF Interupt Bit2 - CEC Interupt */
#define HDMI_TX_APB_INT_MASK_apb_intr_mask(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_APB_INT_MASK_apb_intr_mask_SHIFT)) & HDMI_TX_APB_INT_MASK_apb_intr_mask_MASK)

#define HDMI_TX_APB_INT_MASK_reserved_0_MASK     (0xFFFFFFF8U)
#define HDMI_TX_APB_INT_MASK_reserved_0_SHIFT    (3U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_APB_INT_MASK_reserved_0(x)       (((uint32_t)(((uint32_t)(x)) << HDMI_TX_APB_INT_MASK_reserved_0_SHIFT)) & HDMI_TX_APB_INT_MASK_reserved_0_MASK)
/*! @} */

/*! @name APB_STATUS_MASK -  */
/*! @{ */

#define HDMI_TX_APB_STATUS_MASK_apb_intr_status_MASK (0x7U)
#define HDMI_TX_APB_STATUS_MASK_apb_intr_status_SHIFT (0U)
/*! apb_intr_status - APB interupt STATUS Bit0 - Mailbox Interupt Bit1 - PIF Interupt Bit2 - CEC Interupt */
#define HDMI_TX_APB_STATUS_MASK_apb_intr_status(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_APB_STATUS_MASK_apb_intr_status_SHIFT)) & HDMI_TX_APB_STATUS_MASK_apb_intr_status_MASK)

#define HDMI_TX_APB_STATUS_MASK_reserved_0_MASK  (0xFFFFFFF8U)
#define HDMI_TX_APB_STATUS_MASK_reserved_0_SHIFT (3U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_APB_STATUS_MASK_reserved_0(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_APB_STATUS_MASK_reserved_0_SHIFT)) & HDMI_TX_APB_STATUS_MASK_reserved_0_MASK)
/*! @} */

/*! @name AUDIO_SRC_CNTL -  */
/*! @{ */

#define HDMI_TX_AUDIO_SRC_CNTL_sw_rst_MASK       (0x1U)
#define HDMI_TX_AUDIO_SRC_CNTL_sw_rst_SHIFT      (0U)
/*! sw_rst - Software reset. Active high. */
#define HDMI_TX_AUDIO_SRC_CNTL_sw_rst(x)         (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNTL_sw_rst_SHIFT)) & HDMI_TX_AUDIO_SRC_CNTL_sw_rst_MASK)

#define HDMI_TX_AUDIO_SRC_CNTL_i2s_dec_start_MASK (0x2U)
#define HDMI_TX_AUDIO_SRC_CNTL_i2s_dec_start_SHIFT (1U)
/*! i2s_dec_start - When high Source Decoder starts. */
#define HDMI_TX_AUDIO_SRC_CNTL_i2s_dec_start(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNTL_i2s_dec_start_SHIFT)) & HDMI_TX_AUDIO_SRC_CNTL_i2s_dec_start_MASK)

#define HDMI_TX_AUDIO_SRC_CNTL_i2s_block_start_force_MASK (0x4U)
#define HDMI_TX_AUDIO_SRC_CNTL_i2s_block_start_force_SHIFT (2U)
/*! i2s_block_start_force - Force a "Block Start" in the audio stream. */
#define HDMI_TX_AUDIO_SRC_CNTL_i2s_block_start_force(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNTL_i2s_block_start_force_SHIFT)) & HDMI_TX_AUDIO_SRC_CNTL_i2s_block_start_force_MASK)

#define HDMI_TX_AUDIO_SRC_CNTL_spdif_ts_en_MASK  (0x8U)
#define HDMI_TX_AUDIO_SRC_CNTL_spdif_ts_en_SHIFT (3U)
/*! spdif_ts_en - Enble SPDIF Time Stamp when decoders are disabled */
#define HDMI_TX_AUDIO_SRC_CNTL_spdif_ts_en(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNTL_spdif_ts_en_SHIFT)) & HDMI_TX_AUDIO_SRC_CNTL_spdif_ts_en_MASK)

#define HDMI_TX_AUDIO_SRC_CNTL_i2s_ts_en_MASK    (0x10U)
#define HDMI_TX_AUDIO_SRC_CNTL_i2s_ts_en_SHIFT   (4U)
/*! i2s_ts_en - Enble I2S Time Stamp when decoders are disabled */
#define HDMI_TX_AUDIO_SRC_CNTL_i2s_ts_en(x)      (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNTL_i2s_ts_en_SHIFT)) & HDMI_TX_AUDIO_SRC_CNTL_i2s_ts_en_MASK)

#define HDMI_TX_AUDIO_SRC_CNTL_valid_bits_force_MASK (0x20U)
#define HDMI_TX_AUDIO_SRC_CNTL_valid_bits_force_SHIFT (5U)
/*! valid_bits_force - Force valid bits of the channels */
#define HDMI_TX_AUDIO_SRC_CNTL_valid_bits_force(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNTL_valid_bits_force_SHIFT)) & HDMI_TX_AUDIO_SRC_CNTL_valid_bits_force_MASK)

#define HDMI_TX_AUDIO_SRC_CNTL_valid_all_MASK    (0x40U)
#define HDMI_TX_AUDIO_SRC_CNTL_valid_all_SHIFT   (6U)
/*! valid_all - valid bit for all samples */
#define HDMI_TX_AUDIO_SRC_CNTL_valid_all(x)      (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNTL_valid_all_SHIFT)) & HDMI_TX_AUDIO_SRC_CNTL_valid_all_MASK)

#define HDMI_TX_AUDIO_SRC_CNTL_reserved_0_MASK   (0xFFFFFF80U)
#define HDMI_TX_AUDIO_SRC_CNTL_reserved_0_SHIFT  (7U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_AUDIO_SRC_CNTL_reserved_0(x)     (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNTL_reserved_0_SHIFT)) & HDMI_TX_AUDIO_SRC_CNTL_reserved_0_MASK)
/*! @} */

/*! @name AUDIO_SRC_CNFG -  */
/*! @{ */

#define HDMI_TX_AUDIO_SRC_CNFG_low_index_msb_MASK (0x1U)
#define HDMI_TX_AUDIO_SRC_CNFG_low_index_msb_SHIFT (0U)
/*! low_index_msb - When low MSB is transmitted first. When high LSB is transmitted first. */
#define HDMI_TX_AUDIO_SRC_CNFG_low_index_msb(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNFG_low_index_msb_SHIFT)) & HDMI_TX_AUDIO_SRC_CNFG_low_index_msb_MASK)

#define HDMI_TX_AUDIO_SRC_CNFG_ws_polarity_MASK  (0x2U)
#define HDMI_TX_AUDIO_SRC_CNFG_ws_polarity_SHIFT (1U)
/*! ws_polarity - Word Select Polarity. 0: No change, 1: Inverted. */
#define HDMI_TX_AUDIO_SRC_CNFG_ws_polarity(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNFG_ws_polarity_SHIFT)) & HDMI_TX_AUDIO_SRC_CNFG_ws_polarity_MASK)

#define HDMI_TX_AUDIO_SRC_CNFG_audio_ch_num_MASK (0x7CU)
#define HDMI_TX_AUDIO_SRC_CNFG_audio_ch_num_SHIFT (2U)
/*! audio_ch_num - Number of channels to decode */
#define HDMI_TX_AUDIO_SRC_CNFG_audio_ch_num(x)   (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNFG_audio_ch_num_SHIFT)) & HDMI_TX_AUDIO_SRC_CNFG_audio_ch_num_MASK)

#define HDMI_TX_AUDIO_SRC_CNFG_audio_sample_just_MASK (0x180U)
#define HDMI_TX_AUDIO_SRC_CNFG_audio_sample_just_SHIFT (7U)
/*! audio_sample_just - Data justification setting:00 left-justified, 01 right-justified */
#define HDMI_TX_AUDIO_SRC_CNFG_audio_sample_just(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNFG_audio_sample_just_SHIFT)) & HDMI_TX_AUDIO_SRC_CNFG_audio_sample_just_MASK)

#define HDMI_TX_AUDIO_SRC_CNFG_audio_sample_width_MASK (0x600U)
#define HDMI_TX_AUDIO_SRC_CNFG_audio_sample_width_SHIFT (9U)
/*! audio_sample_width - Decoder sample width:00-16 bit, 01-24 bit, 10-32 bit */
#define HDMI_TX_AUDIO_SRC_CNFG_audio_sample_width(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNFG_audio_sample_width_SHIFT)) & HDMI_TX_AUDIO_SRC_CNFG_audio_sample_width_MASK)

#define HDMI_TX_AUDIO_SRC_CNFG_trans_smpl_width_MASK (0x1800U)
#define HDMI_TX_AUDIO_SRC_CNFG_trans_smpl_width_SHIFT (11U)
/*! trans_smpl_width - Decoder Word Select width: 00-16 bit, 01-24 bit, 10-32 bit */
#define HDMI_TX_AUDIO_SRC_CNFG_trans_smpl_width(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNFG_trans_smpl_width_SHIFT)) & HDMI_TX_AUDIO_SRC_CNFG_trans_smpl_width_MASK)

#define HDMI_TX_AUDIO_SRC_CNFG_audio_channel_type_MASK (0x1E000U)
#define HDMI_TX_AUDIO_SRC_CNFG_audio_channel_type_SHIFT (13U)
/*! audio_channel_type - Set the transmission type. */
#define HDMI_TX_AUDIO_SRC_CNFG_audio_channel_type(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNFG_audio_channel_type_SHIFT)) & HDMI_TX_AUDIO_SRC_CNFG_audio_channel_type_MASK)

#define HDMI_TX_AUDIO_SRC_CNFG_i2s_dec_port_en_MASK (0x1E0000U)
#define HDMI_TX_AUDIO_SRC_CNFG_i2s_dec_port_en_SHIFT (17U)
/*! i2s_dec_port_en - Enables the I2S Decoder ports. Allowed values are:0001 - I2S port 0 is
 *    enabled.0011 - I2S ports 0,1 are enabled.1111 - I2S ports 0,1,2,3 are enabled. No other values are
 *    allowed.
 */
#define HDMI_TX_AUDIO_SRC_CNFG_i2s_dec_port_en(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNFG_i2s_dec_port_en_SHIFT)) & HDMI_TX_AUDIO_SRC_CNFG_i2s_dec_port_en_MASK)

#define HDMI_TX_AUDIO_SRC_CNFG_reserved_0_MASK   (0xFFE00000U)
#define HDMI_TX_AUDIO_SRC_CNFG_reserved_0_SHIFT  (21U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_AUDIO_SRC_CNFG_reserved_0(x)     (((uint32_t)(((uint32_t)(x)) << HDMI_TX_AUDIO_SRC_CNFG_reserved_0_SHIFT)) & HDMI_TX_AUDIO_SRC_CNFG_reserved_0_MASK)
/*! @} */

/*! @name COM_CH_STTS_BITS -  */
/*! @{ */

#define HDMI_TX_COM_CH_STTS_BITS_Byte0_MASK      (0xFFU)
#define HDMI_TX_COM_CH_STTS_BITS_Byte0_SHIFT     (0U)
/*! Byte0 - Byte 0 of transmitted channel. Same for all channels. */
#define HDMI_TX_COM_CH_STTS_BITS_Byte0(x)        (((uint32_t)(((uint32_t)(x)) << HDMI_TX_COM_CH_STTS_BITS_Byte0_SHIFT)) & HDMI_TX_COM_CH_STTS_BITS_Byte0_MASK)

#define HDMI_TX_COM_CH_STTS_BITS_Category_Code_MASK (0xFF00U)
#define HDMI_TX_COM_CH_STTS_BITS_Category_Code_SHIFT (8U)
/*! Category_Code - Category Code of transmitted channel. Same for all channels. */
#define HDMI_TX_COM_CH_STTS_BITS_Category_Code(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_COM_CH_STTS_BITS_Category_Code_SHIFT)) & HDMI_TX_COM_CH_STTS_BITS_Category_Code_MASK)

#define HDMI_TX_COM_CH_STTS_BITS_Sampling_Freq_MASK (0xF0000U)
#define HDMI_TX_COM_CH_STTS_BITS_Sampling_Freq_SHIFT (16U)
/*! Sampling_Freq - Sampling Frequency of transmitted channel. Same for all channels. */
#define HDMI_TX_COM_CH_STTS_BITS_Sampling_Freq(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_COM_CH_STTS_BITS_Sampling_Freq_SHIFT)) & HDMI_TX_COM_CH_STTS_BITS_Sampling_Freq_MASK)

#define HDMI_TX_COM_CH_STTS_BITS_Clock_accuracy_MASK (0xF00000U)
#define HDMI_TX_COM_CH_STTS_BITS_Clock_accuracy_SHIFT (20U)
/*! Clock_accuracy - Clock Accuracy of transmitted channel. Same for all channels. */
#define HDMI_TX_COM_CH_STTS_BITS_Clock_accuracy(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_COM_CH_STTS_BITS_Clock_accuracy_SHIFT)) & HDMI_TX_COM_CH_STTS_BITS_Clock_accuracy_MASK)

#define HDMI_TX_COM_CH_STTS_BITS_Original_samp_freq_MASK (0xF000000U)
#define HDMI_TX_COM_CH_STTS_BITS_Original_samp_freq_SHIFT (24U)
/*! Original_samp_freq - Original Sampling Freq. of transmitted channel. Same for all channels. */
#define HDMI_TX_COM_CH_STTS_BITS_Original_samp_freq(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_COM_CH_STTS_BITS_Original_samp_freq_SHIFT)) & HDMI_TX_COM_CH_STTS_BITS_Original_samp_freq_MASK)

#define HDMI_TX_COM_CH_STTS_BITS_reserved_0_MASK (0xF0000000U)
#define HDMI_TX_COM_CH_STTS_BITS_reserved_0_SHIFT (28U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_COM_CH_STTS_BITS_reserved_0(x)   (((uint32_t)(((uint32_t)(x)) << HDMI_TX_COM_CH_STTS_BITS_reserved_0_SHIFT)) & HDMI_TX_COM_CH_STTS_BITS_reserved_0_MASK)
/*! @} */

/*! @name STTS_BIT_CH01 -  */
/*! @{ */

#define HDMI_TX_STTS_BIT_CH01_source_num_ch0_MASK (0xFU)
#define HDMI_TX_STTS_BIT_CH01_source_num_ch0_SHIFT (0U)
/*! source_num_ch0 - Channel 0 Source number. */
#define HDMI_TX_STTS_BIT_CH01_source_num_ch0(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH01_source_num_ch0_SHIFT)) & HDMI_TX_STTS_BIT_CH01_source_num_ch0_MASK)

#define HDMI_TX_STTS_BIT_CH01_channel_num_ch0_MASK (0xF0U)
#define HDMI_TX_STTS_BIT_CH01_channel_num_ch0_SHIFT (4U)
/*! channel_num_ch0 - Channel 0 channel number. */
#define HDMI_TX_STTS_BIT_CH01_channel_num_ch0(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH01_channel_num_ch0_SHIFT)) & HDMI_TX_STTS_BIT_CH01_channel_num_ch0_MASK)

#define HDMI_TX_STTS_BIT_CH01_word_length_ch0_MASK (0xF00U)
#define HDMI_TX_STTS_BIT_CH01_word_length_ch0_SHIFT (8U)
/*! word_length_ch0 - Channel 0 word length. */
#define HDMI_TX_STTS_BIT_CH01_word_length_ch0(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH01_word_length_ch0_SHIFT)) & HDMI_TX_STTS_BIT_CH01_word_length_ch0_MASK)

#define HDMI_TX_STTS_BIT_CH01_source_num_ch1_MASK (0xF000U)
#define HDMI_TX_STTS_BIT_CH01_source_num_ch1_SHIFT (12U)
/*! source_num_ch1 - Channel 1 Source number. */
#define HDMI_TX_STTS_BIT_CH01_source_num_ch1(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH01_source_num_ch1_SHIFT)) & HDMI_TX_STTS_BIT_CH01_source_num_ch1_MASK)

#define HDMI_TX_STTS_BIT_CH01_channel_num_ch1_MASK (0xF0000U)
#define HDMI_TX_STTS_BIT_CH01_channel_num_ch1_SHIFT (16U)
/*! channel_num_ch1 - Channel 1 channel number. */
#define HDMI_TX_STTS_BIT_CH01_channel_num_ch1(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH01_channel_num_ch1_SHIFT)) & HDMI_TX_STTS_BIT_CH01_channel_num_ch1_MASK)

#define HDMI_TX_STTS_BIT_CH01_word_length_ch1_MASK (0xF00000U)
#define HDMI_TX_STTS_BIT_CH01_word_length_ch1_SHIFT (20U)
/*! word_length_ch1 - Channel 1 word length. */
#define HDMI_TX_STTS_BIT_CH01_word_length_ch1(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH01_word_length_ch1_SHIFT)) & HDMI_TX_STTS_BIT_CH01_word_length_ch1_MASK)

#define HDMI_TX_STTS_BIT_CH01_valid_bits1_0_MASK (0x3000000U)
#define HDMI_TX_STTS_BIT_CH01_valid_bits1_0_SHIFT (24U)
/*! valid_bits1_0 - Valid Bits for channel 1 and 0 if force is enabled */
#define HDMI_TX_STTS_BIT_CH01_valid_bits1_0(x)   (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH01_valid_bits1_0_SHIFT)) & HDMI_TX_STTS_BIT_CH01_valid_bits1_0_MASK)

#define HDMI_TX_STTS_BIT_CH01_reserved_0_MASK    (0xFC000000U)
#define HDMI_TX_STTS_BIT_CH01_reserved_0_SHIFT   (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_STTS_BIT_CH01_reserved_0(x)      (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH01_reserved_0_SHIFT)) & HDMI_TX_STTS_BIT_CH01_reserved_0_MASK)
/*! @} */

/*! @name STTS_BIT_CH23 -  */
/*! @{ */

#define HDMI_TX_STTS_BIT_CH23_source_num_ch2_MASK (0xFU)
#define HDMI_TX_STTS_BIT_CH23_source_num_ch2_SHIFT (0U)
/*! source_num_ch2 - Channel 2 Source number. */
#define HDMI_TX_STTS_BIT_CH23_source_num_ch2(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH23_source_num_ch2_SHIFT)) & HDMI_TX_STTS_BIT_CH23_source_num_ch2_MASK)

#define HDMI_TX_STTS_BIT_CH23_channel_num_ch2_MASK (0xF0U)
#define HDMI_TX_STTS_BIT_CH23_channel_num_ch2_SHIFT (4U)
/*! channel_num_ch2 - Channel 2 channel number. */
#define HDMI_TX_STTS_BIT_CH23_channel_num_ch2(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH23_channel_num_ch2_SHIFT)) & HDMI_TX_STTS_BIT_CH23_channel_num_ch2_MASK)

#define HDMI_TX_STTS_BIT_CH23_word_length_ch2_MASK (0xF00U)
#define HDMI_TX_STTS_BIT_CH23_word_length_ch2_SHIFT (8U)
/*! word_length_ch2 - Channel 2 word length. */
#define HDMI_TX_STTS_BIT_CH23_word_length_ch2(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH23_word_length_ch2_SHIFT)) & HDMI_TX_STTS_BIT_CH23_word_length_ch2_MASK)

#define HDMI_TX_STTS_BIT_CH23_source_num_ch3_MASK (0xF000U)
#define HDMI_TX_STTS_BIT_CH23_source_num_ch3_SHIFT (12U)
/*! source_num_ch3 - Channel 3 Source number. */
#define HDMI_TX_STTS_BIT_CH23_source_num_ch3(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH23_source_num_ch3_SHIFT)) & HDMI_TX_STTS_BIT_CH23_source_num_ch3_MASK)

#define HDMI_TX_STTS_BIT_CH23_channel_num_ch3_MASK (0xF0000U)
#define HDMI_TX_STTS_BIT_CH23_channel_num_ch3_SHIFT (16U)
/*! channel_num_ch3 - Channel 3 channel number. */
#define HDMI_TX_STTS_BIT_CH23_channel_num_ch3(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH23_channel_num_ch3_SHIFT)) & HDMI_TX_STTS_BIT_CH23_channel_num_ch3_MASK)

#define HDMI_TX_STTS_BIT_CH23_word_length_ch3_MASK (0xF00000U)
#define HDMI_TX_STTS_BIT_CH23_word_length_ch3_SHIFT (20U)
/*! word_length_ch3 - Channel 3 word length. */
#define HDMI_TX_STTS_BIT_CH23_word_length_ch3(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH23_word_length_ch3_SHIFT)) & HDMI_TX_STTS_BIT_CH23_word_length_ch3_MASK)

#define HDMI_TX_STTS_BIT_CH23_valid_bits3_2_MASK (0x3000000U)
#define HDMI_TX_STTS_BIT_CH23_valid_bits3_2_SHIFT (24U)
/*! valid_bits3_2 - Valid Bits for channel 3 and 2 if force is enabled */
#define HDMI_TX_STTS_BIT_CH23_valid_bits3_2(x)   (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH23_valid_bits3_2_SHIFT)) & HDMI_TX_STTS_BIT_CH23_valid_bits3_2_MASK)

#define HDMI_TX_STTS_BIT_CH23_reserved_0_MASK    (0xFC000000U)
#define HDMI_TX_STTS_BIT_CH23_reserved_0_SHIFT   (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_STTS_BIT_CH23_reserved_0(x)      (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH23_reserved_0_SHIFT)) & HDMI_TX_STTS_BIT_CH23_reserved_0_MASK)
/*! @} */

/*! @name STTS_BIT_CH45 -  */
/*! @{ */

#define HDMI_TX_STTS_BIT_CH45_source_num_ch4_MASK (0xFU)
#define HDMI_TX_STTS_BIT_CH45_source_num_ch4_SHIFT (0U)
/*! source_num_ch4 - Channel 4 Source number. */
#define HDMI_TX_STTS_BIT_CH45_source_num_ch4(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH45_source_num_ch4_SHIFT)) & HDMI_TX_STTS_BIT_CH45_source_num_ch4_MASK)

#define HDMI_TX_STTS_BIT_CH45_channel_num_ch4_MASK (0xF0U)
#define HDMI_TX_STTS_BIT_CH45_channel_num_ch4_SHIFT (4U)
/*! channel_num_ch4 - Channel 4 channel number. */
#define HDMI_TX_STTS_BIT_CH45_channel_num_ch4(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH45_channel_num_ch4_SHIFT)) & HDMI_TX_STTS_BIT_CH45_channel_num_ch4_MASK)

#define HDMI_TX_STTS_BIT_CH45_word_length_ch4_MASK (0xF00U)
#define HDMI_TX_STTS_BIT_CH45_word_length_ch4_SHIFT (8U)
/*! word_length_ch4 - Channel 4 word length. */
#define HDMI_TX_STTS_BIT_CH45_word_length_ch4(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH45_word_length_ch4_SHIFT)) & HDMI_TX_STTS_BIT_CH45_word_length_ch4_MASK)

#define HDMI_TX_STTS_BIT_CH45_source_num_ch5_MASK (0xF000U)
#define HDMI_TX_STTS_BIT_CH45_source_num_ch5_SHIFT (12U)
/*! source_num_ch5 - Channel 5 Source number. */
#define HDMI_TX_STTS_BIT_CH45_source_num_ch5(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH45_source_num_ch5_SHIFT)) & HDMI_TX_STTS_BIT_CH45_source_num_ch5_MASK)

#define HDMI_TX_STTS_BIT_CH45_channel_num_ch5_MASK (0xF0000U)
#define HDMI_TX_STTS_BIT_CH45_channel_num_ch5_SHIFT (16U)
/*! channel_num_ch5 - Channel 5 channel number. */
#define HDMI_TX_STTS_BIT_CH45_channel_num_ch5(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH45_channel_num_ch5_SHIFT)) & HDMI_TX_STTS_BIT_CH45_channel_num_ch5_MASK)

#define HDMI_TX_STTS_BIT_CH45_word_length_ch5_MASK (0xF00000U)
#define HDMI_TX_STTS_BIT_CH45_word_length_ch5_SHIFT (20U)
/*! word_length_ch5 - Channel 5 word length. */
#define HDMI_TX_STTS_BIT_CH45_word_length_ch5(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH45_word_length_ch5_SHIFT)) & HDMI_TX_STTS_BIT_CH45_word_length_ch5_MASK)

#define HDMI_TX_STTS_BIT_CH45_valid_bits5_4_MASK (0x3000000U)
#define HDMI_TX_STTS_BIT_CH45_valid_bits5_4_SHIFT (24U)
/*! valid_bits5_4 - Valid Bits for channel 5 and 4 if force is enabled */
#define HDMI_TX_STTS_BIT_CH45_valid_bits5_4(x)   (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH45_valid_bits5_4_SHIFT)) & HDMI_TX_STTS_BIT_CH45_valid_bits5_4_MASK)

#define HDMI_TX_STTS_BIT_CH45_reserved_0_MASK    (0xFC000000U)
#define HDMI_TX_STTS_BIT_CH45_reserved_0_SHIFT   (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_STTS_BIT_CH45_reserved_0(x)      (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH45_reserved_0_SHIFT)) & HDMI_TX_STTS_BIT_CH45_reserved_0_MASK)
/*! @} */

/*! @name STTS_BIT_CH67 -  */
/*! @{ */

#define HDMI_TX_STTS_BIT_CH67_source_num_ch6_MASK (0xFU)
#define HDMI_TX_STTS_BIT_CH67_source_num_ch6_SHIFT (0U)
/*! source_num_ch6 - Channel 6 Source number. */
#define HDMI_TX_STTS_BIT_CH67_source_num_ch6(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH67_source_num_ch6_SHIFT)) & HDMI_TX_STTS_BIT_CH67_source_num_ch6_MASK)

#define HDMI_TX_STTS_BIT_CH67_channel_num_ch6_MASK (0xF0U)
#define HDMI_TX_STTS_BIT_CH67_channel_num_ch6_SHIFT (4U)
/*! channel_num_ch6 - Channel 6 channel number. */
#define HDMI_TX_STTS_BIT_CH67_channel_num_ch6(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH67_channel_num_ch6_SHIFT)) & HDMI_TX_STTS_BIT_CH67_channel_num_ch6_MASK)

#define HDMI_TX_STTS_BIT_CH67_word_length_ch6_MASK (0xF00U)
#define HDMI_TX_STTS_BIT_CH67_word_length_ch6_SHIFT (8U)
/*! word_length_ch6 - Channel 6 word length. */
#define HDMI_TX_STTS_BIT_CH67_word_length_ch6(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH67_word_length_ch6_SHIFT)) & HDMI_TX_STTS_BIT_CH67_word_length_ch6_MASK)

#define HDMI_TX_STTS_BIT_CH67_source_num_ch7_MASK (0xF000U)
#define HDMI_TX_STTS_BIT_CH67_source_num_ch7_SHIFT (12U)
/*! source_num_ch7 - Channel 7 Source number. */
#define HDMI_TX_STTS_BIT_CH67_source_num_ch7(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH67_source_num_ch7_SHIFT)) & HDMI_TX_STTS_BIT_CH67_source_num_ch7_MASK)

#define HDMI_TX_STTS_BIT_CH67_channel_num_ch7_MASK (0xF0000U)
#define HDMI_TX_STTS_BIT_CH67_channel_num_ch7_SHIFT (16U)
/*! channel_num_ch7 - Channel 7 channel number. */
#define HDMI_TX_STTS_BIT_CH67_channel_num_ch7(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH67_channel_num_ch7_SHIFT)) & HDMI_TX_STTS_BIT_CH67_channel_num_ch7_MASK)

#define HDMI_TX_STTS_BIT_CH67_word_length_ch7_MASK (0xF00000U)
#define HDMI_TX_STTS_BIT_CH67_word_length_ch7_SHIFT (20U)
/*! word_length_ch7 - Channel 7 word length. */
#define HDMI_TX_STTS_BIT_CH67_word_length_ch7(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH67_word_length_ch7_SHIFT)) & HDMI_TX_STTS_BIT_CH67_word_length_ch7_MASK)

#define HDMI_TX_STTS_BIT_CH67_valid_bits7_6_MASK (0x3000000U)
#define HDMI_TX_STTS_BIT_CH67_valid_bits7_6_SHIFT (24U)
/*! valid_bits7_6 - Valid Bits for channel 7 and 6 if force is enabled */
#define HDMI_TX_STTS_BIT_CH67_valid_bits7_6(x)   (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH67_valid_bits7_6_SHIFT)) & HDMI_TX_STTS_BIT_CH67_valid_bits7_6_MASK)

#define HDMI_TX_STTS_BIT_CH67_reserved_0_MASK    (0xFC000000U)
#define HDMI_TX_STTS_BIT_CH67_reserved_0_SHIFT   (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_STTS_BIT_CH67_reserved_0(x)      (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH67_reserved_0_SHIFT)) & HDMI_TX_STTS_BIT_CH67_reserved_0_MASK)
/*! @} */

/*! @name STTS_BIT_CH89 -  */
/*! @{ */

#define HDMI_TX_STTS_BIT_CH89_source_num_ch8_MASK (0xFU)
#define HDMI_TX_STTS_BIT_CH89_source_num_ch8_SHIFT (0U)
/*! source_num_ch8 - Channel 8 Source number. */
#define HDMI_TX_STTS_BIT_CH89_source_num_ch8(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH89_source_num_ch8_SHIFT)) & HDMI_TX_STTS_BIT_CH89_source_num_ch8_MASK)

#define HDMI_TX_STTS_BIT_CH89_channel_num_ch8_MASK (0xF0U)
#define HDMI_TX_STTS_BIT_CH89_channel_num_ch8_SHIFT (4U)
/*! channel_num_ch8 - Channel 8 channel number. */
#define HDMI_TX_STTS_BIT_CH89_channel_num_ch8(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH89_channel_num_ch8_SHIFT)) & HDMI_TX_STTS_BIT_CH89_channel_num_ch8_MASK)

#define HDMI_TX_STTS_BIT_CH89_word_length_ch8_MASK (0xF00U)
#define HDMI_TX_STTS_BIT_CH89_word_length_ch8_SHIFT (8U)
/*! word_length_ch8 - Channel 8 word length. */
#define HDMI_TX_STTS_BIT_CH89_word_length_ch8(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH89_word_length_ch8_SHIFT)) & HDMI_TX_STTS_BIT_CH89_word_length_ch8_MASK)

#define HDMI_TX_STTS_BIT_CH89_source_num_ch9_MASK (0xF000U)
#define HDMI_TX_STTS_BIT_CH89_source_num_ch9_SHIFT (12U)
/*! source_num_ch9 - Channel 9 Source number. */
#define HDMI_TX_STTS_BIT_CH89_source_num_ch9(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH89_source_num_ch9_SHIFT)) & HDMI_TX_STTS_BIT_CH89_source_num_ch9_MASK)

#define HDMI_TX_STTS_BIT_CH89_channel_num_ch9_MASK (0xF0000U)
#define HDMI_TX_STTS_BIT_CH89_channel_num_ch9_SHIFT (16U)
/*! channel_num_ch9 - Channel 9 channel number. */
#define HDMI_TX_STTS_BIT_CH89_channel_num_ch9(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH89_channel_num_ch9_SHIFT)) & HDMI_TX_STTS_BIT_CH89_channel_num_ch9_MASK)

#define HDMI_TX_STTS_BIT_CH89_word_length_ch9_MASK (0xF00000U)
#define HDMI_TX_STTS_BIT_CH89_word_length_ch9_SHIFT (20U)
/*! word_length_ch9 - Channel 9 word length. */
#define HDMI_TX_STTS_BIT_CH89_word_length_ch9(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH89_word_length_ch9_SHIFT)) & HDMI_TX_STTS_BIT_CH89_word_length_ch9_MASK)

#define HDMI_TX_STTS_BIT_CH89_valid_bits9_8_MASK (0x3000000U)
#define HDMI_TX_STTS_BIT_CH89_valid_bits9_8_SHIFT (24U)
/*! valid_bits9_8 - Valid Bits for channel 9 and 8 if force is enabled */
#define HDMI_TX_STTS_BIT_CH89_valid_bits9_8(x)   (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH89_valid_bits9_8_SHIFT)) & HDMI_TX_STTS_BIT_CH89_valid_bits9_8_MASK)

#define HDMI_TX_STTS_BIT_CH89_reserved_0_MASK    (0xFC000000U)
#define HDMI_TX_STTS_BIT_CH89_reserved_0_SHIFT   (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_STTS_BIT_CH89_reserved_0(x)      (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH89_reserved_0_SHIFT)) & HDMI_TX_STTS_BIT_CH89_reserved_0_MASK)
/*! @} */

/*! @name STTS_BIT_CH1011 -  */
/*! @{ */

#define HDMI_TX_STTS_BIT_CH1011_source_num_ch10_MASK (0xFU)
#define HDMI_TX_STTS_BIT_CH1011_source_num_ch10_SHIFT (0U)
/*! source_num_ch10 - Channel 10 Source number. */
#define HDMI_TX_STTS_BIT_CH1011_source_num_ch10(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1011_source_num_ch10_SHIFT)) & HDMI_TX_STTS_BIT_CH1011_source_num_ch10_MASK)

#define HDMI_TX_STTS_BIT_CH1011_channel_num_ch10_MASK (0xF0U)
#define HDMI_TX_STTS_BIT_CH1011_channel_num_ch10_SHIFT (4U)
/*! channel_num_ch10 - Channel 10 channel number. */
#define HDMI_TX_STTS_BIT_CH1011_channel_num_ch10(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1011_channel_num_ch10_SHIFT)) & HDMI_TX_STTS_BIT_CH1011_channel_num_ch10_MASK)

#define HDMI_TX_STTS_BIT_CH1011_word_length_ch10_MASK (0xF00U)
#define HDMI_TX_STTS_BIT_CH1011_word_length_ch10_SHIFT (8U)
/*! word_length_ch10 - Channel 10 word length. */
#define HDMI_TX_STTS_BIT_CH1011_word_length_ch10(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1011_word_length_ch10_SHIFT)) & HDMI_TX_STTS_BIT_CH1011_word_length_ch10_MASK)

#define HDMI_TX_STTS_BIT_CH1011_source_num_ch11_MASK (0xF000U)
#define HDMI_TX_STTS_BIT_CH1011_source_num_ch11_SHIFT (12U)
/*! source_num_ch11 - Channel 11 Source number. */
#define HDMI_TX_STTS_BIT_CH1011_source_num_ch11(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1011_source_num_ch11_SHIFT)) & HDMI_TX_STTS_BIT_CH1011_source_num_ch11_MASK)

#define HDMI_TX_STTS_BIT_CH1011_channel_num_ch11_MASK (0xF0000U)
#define HDMI_TX_STTS_BIT_CH1011_channel_num_ch11_SHIFT (16U)
/*! channel_num_ch11 - Channel 11 channel number. */
#define HDMI_TX_STTS_BIT_CH1011_channel_num_ch11(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1011_channel_num_ch11_SHIFT)) & HDMI_TX_STTS_BIT_CH1011_channel_num_ch11_MASK)

#define HDMI_TX_STTS_BIT_CH1011_word_length_ch11_MASK (0xF00000U)
#define HDMI_TX_STTS_BIT_CH1011_word_length_ch11_SHIFT (20U)
/*! word_length_ch11 - Channel 11 word length. */
#define HDMI_TX_STTS_BIT_CH1011_word_length_ch11(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1011_word_length_ch11_SHIFT)) & HDMI_TX_STTS_BIT_CH1011_word_length_ch11_MASK)

#define HDMI_TX_STTS_BIT_CH1011_valid_bits11_10_MASK (0x3000000U)
#define HDMI_TX_STTS_BIT_CH1011_valid_bits11_10_SHIFT (24U)
/*! valid_bits11_10 - Valid Bits for channel 11 and 10 if force is enabled */
#define HDMI_TX_STTS_BIT_CH1011_valid_bits11_10(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1011_valid_bits11_10_SHIFT)) & HDMI_TX_STTS_BIT_CH1011_valid_bits11_10_MASK)

#define HDMI_TX_STTS_BIT_CH1011_reserved_0_MASK  (0xFC000000U)
#define HDMI_TX_STTS_BIT_CH1011_reserved_0_SHIFT (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_STTS_BIT_CH1011_reserved_0(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1011_reserved_0_SHIFT)) & HDMI_TX_STTS_BIT_CH1011_reserved_0_MASK)
/*! @} */

/*! @name STTS_BIT_CH1213 -  */
/*! @{ */

#define HDMI_TX_STTS_BIT_CH1213_source_num_ch12_MASK (0xFU)
#define HDMI_TX_STTS_BIT_CH1213_source_num_ch12_SHIFT (0U)
/*! source_num_ch12 - Channel 12 Source number. */
#define HDMI_TX_STTS_BIT_CH1213_source_num_ch12(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1213_source_num_ch12_SHIFT)) & HDMI_TX_STTS_BIT_CH1213_source_num_ch12_MASK)

#define HDMI_TX_STTS_BIT_CH1213_channel_num_ch12_MASK (0xF0U)
#define HDMI_TX_STTS_BIT_CH1213_channel_num_ch12_SHIFT (4U)
/*! channel_num_ch12 - Channel 12 channel number. */
#define HDMI_TX_STTS_BIT_CH1213_channel_num_ch12(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1213_channel_num_ch12_SHIFT)) & HDMI_TX_STTS_BIT_CH1213_channel_num_ch12_MASK)

#define HDMI_TX_STTS_BIT_CH1213_word_length_ch12_MASK (0xF00U)
#define HDMI_TX_STTS_BIT_CH1213_word_length_ch12_SHIFT (8U)
/*! word_length_ch12 - Channel 12 word length. */
#define HDMI_TX_STTS_BIT_CH1213_word_length_ch12(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1213_word_length_ch12_SHIFT)) & HDMI_TX_STTS_BIT_CH1213_word_length_ch12_MASK)

#define HDMI_TX_STTS_BIT_CH1213_source_num_ch13_MASK (0xF000U)
#define HDMI_TX_STTS_BIT_CH1213_source_num_ch13_SHIFT (12U)
/*! source_num_ch13 - Channel 13 Source number. */
#define HDMI_TX_STTS_BIT_CH1213_source_num_ch13(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1213_source_num_ch13_SHIFT)) & HDMI_TX_STTS_BIT_CH1213_source_num_ch13_MASK)

#define HDMI_TX_STTS_BIT_CH1213_channel_num_ch13_MASK (0xF0000U)
#define HDMI_TX_STTS_BIT_CH1213_channel_num_ch13_SHIFT (16U)
/*! channel_num_ch13 - Channel 13 channel number. */
#define HDMI_TX_STTS_BIT_CH1213_channel_num_ch13(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1213_channel_num_ch13_SHIFT)) & HDMI_TX_STTS_BIT_CH1213_channel_num_ch13_MASK)

#define HDMI_TX_STTS_BIT_CH1213_word_length_ch13_MASK (0xF00000U)
#define HDMI_TX_STTS_BIT_CH1213_word_length_ch13_SHIFT (20U)
/*! word_length_ch13 - Channel 13 word length. */
#define HDMI_TX_STTS_BIT_CH1213_word_length_ch13(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1213_word_length_ch13_SHIFT)) & HDMI_TX_STTS_BIT_CH1213_word_length_ch13_MASK)

#define HDMI_TX_STTS_BIT_CH1213_valid_bits13_12_MASK (0x3000000U)
#define HDMI_TX_STTS_BIT_CH1213_valid_bits13_12_SHIFT (24U)
/*! valid_bits13_12 - Valid Bits for channel 13 and 12 if force is enabled */
#define HDMI_TX_STTS_BIT_CH1213_valid_bits13_12(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1213_valid_bits13_12_SHIFT)) & HDMI_TX_STTS_BIT_CH1213_valid_bits13_12_MASK)

#define HDMI_TX_STTS_BIT_CH1213_reserved_0_MASK  (0xFC000000U)
#define HDMI_TX_STTS_BIT_CH1213_reserved_0_SHIFT (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_STTS_BIT_CH1213_reserved_0(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1213_reserved_0_SHIFT)) & HDMI_TX_STTS_BIT_CH1213_reserved_0_MASK)
/*! @} */

/*! @name STTS_BIT_CH1415 -  */
/*! @{ */

#define HDMI_TX_STTS_BIT_CH1415_source_num_ch14_MASK (0xFU)
#define HDMI_TX_STTS_BIT_CH1415_source_num_ch14_SHIFT (0U)
/*! source_num_ch14 - Channel 14 Source number. */
#define HDMI_TX_STTS_BIT_CH1415_source_num_ch14(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1415_source_num_ch14_SHIFT)) & HDMI_TX_STTS_BIT_CH1415_source_num_ch14_MASK)

#define HDMI_TX_STTS_BIT_CH1415_channel_num_ch14_MASK (0xF0U)
#define HDMI_TX_STTS_BIT_CH1415_channel_num_ch14_SHIFT (4U)
/*! channel_num_ch14 - Channel 14 channel number. */
#define HDMI_TX_STTS_BIT_CH1415_channel_num_ch14(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1415_channel_num_ch14_SHIFT)) & HDMI_TX_STTS_BIT_CH1415_channel_num_ch14_MASK)

#define HDMI_TX_STTS_BIT_CH1415_word_length_ch14_MASK (0xF00U)
#define HDMI_TX_STTS_BIT_CH1415_word_length_ch14_SHIFT (8U)
/*! word_length_ch14 - Channel 14 word length. */
#define HDMI_TX_STTS_BIT_CH1415_word_length_ch14(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1415_word_length_ch14_SHIFT)) & HDMI_TX_STTS_BIT_CH1415_word_length_ch14_MASK)

#define HDMI_TX_STTS_BIT_CH1415_source_num_ch15_MASK (0xF000U)
#define HDMI_TX_STTS_BIT_CH1415_source_num_ch15_SHIFT (12U)
/*! source_num_ch15 - Channel 15 Source number. */
#define HDMI_TX_STTS_BIT_CH1415_source_num_ch15(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1415_source_num_ch15_SHIFT)) & HDMI_TX_STTS_BIT_CH1415_source_num_ch15_MASK)

#define HDMI_TX_STTS_BIT_CH1415_channel_num_ch15_MASK (0xF0000U)
#define HDMI_TX_STTS_BIT_CH1415_channel_num_ch15_SHIFT (16U)
/*! channel_num_ch15 - Channel 15 channel number. */
#define HDMI_TX_STTS_BIT_CH1415_channel_num_ch15(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1415_channel_num_ch15_SHIFT)) & HDMI_TX_STTS_BIT_CH1415_channel_num_ch15_MASK)

#define HDMI_TX_STTS_BIT_CH1415_word_length_ch15_MASK (0xF00000U)
#define HDMI_TX_STTS_BIT_CH1415_word_length_ch15_SHIFT (20U)
/*! word_length_ch15 - Channel 15 word length. */
#define HDMI_TX_STTS_BIT_CH1415_word_length_ch15(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1415_word_length_ch15_SHIFT)) & HDMI_TX_STTS_BIT_CH1415_word_length_ch15_MASK)

#define HDMI_TX_STTS_BIT_CH1415_valid_bits15_14_MASK (0x3000000U)
#define HDMI_TX_STTS_BIT_CH1415_valid_bits15_14_SHIFT (24U)
/*! valid_bits15_14 - Valid Bits for channel 15 and 14 if force is enabled */
#define HDMI_TX_STTS_BIT_CH1415_valid_bits15_14(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1415_valid_bits15_14_SHIFT)) & HDMI_TX_STTS_BIT_CH1415_valid_bits15_14_MASK)

#define HDMI_TX_STTS_BIT_CH1415_reserved_0_MASK  (0xFC000000U)
#define HDMI_TX_STTS_BIT_CH1415_reserved_0_SHIFT (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_STTS_BIT_CH1415_reserved_0(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1415_reserved_0_SHIFT)) & HDMI_TX_STTS_BIT_CH1415_reserved_0_MASK)
/*! @} */

/*! @name STTS_BIT_CH1617 -  */
/*! @{ */

#define HDMI_TX_STTS_BIT_CH1617_source_num_ch16_MASK (0xFU)
#define HDMI_TX_STTS_BIT_CH1617_source_num_ch16_SHIFT (0U)
/*! source_num_ch16 - Channel 16 Source number. */
#define HDMI_TX_STTS_BIT_CH1617_source_num_ch16(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1617_source_num_ch16_SHIFT)) & HDMI_TX_STTS_BIT_CH1617_source_num_ch16_MASK)

#define HDMI_TX_STTS_BIT_CH1617_channel_num_ch16_MASK (0xF0U)
#define HDMI_TX_STTS_BIT_CH1617_channel_num_ch16_SHIFT (4U)
/*! channel_num_ch16 - Channel 16 channel number. */
#define HDMI_TX_STTS_BIT_CH1617_channel_num_ch16(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1617_channel_num_ch16_SHIFT)) & HDMI_TX_STTS_BIT_CH1617_channel_num_ch16_MASK)

#define HDMI_TX_STTS_BIT_CH1617_word_length_ch16_MASK (0xF00U)
#define HDMI_TX_STTS_BIT_CH1617_word_length_ch16_SHIFT (8U)
/*! word_length_ch16 - Channel 16 word length. */
#define HDMI_TX_STTS_BIT_CH1617_word_length_ch16(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1617_word_length_ch16_SHIFT)) & HDMI_TX_STTS_BIT_CH1617_word_length_ch16_MASK)

#define HDMI_TX_STTS_BIT_CH1617_source_num_ch17_MASK (0xF000U)
#define HDMI_TX_STTS_BIT_CH1617_source_num_ch17_SHIFT (12U)
/*! source_num_ch17 - Channel 17 Source number. */
#define HDMI_TX_STTS_BIT_CH1617_source_num_ch17(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1617_source_num_ch17_SHIFT)) & HDMI_TX_STTS_BIT_CH1617_source_num_ch17_MASK)

#define HDMI_TX_STTS_BIT_CH1617_channel_num_ch17_MASK (0xF0000U)
#define HDMI_TX_STTS_BIT_CH1617_channel_num_ch17_SHIFT (16U)
/*! channel_num_ch17 - Channel 17 channel number. */
#define HDMI_TX_STTS_BIT_CH1617_channel_num_ch17(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1617_channel_num_ch17_SHIFT)) & HDMI_TX_STTS_BIT_CH1617_channel_num_ch17_MASK)

#define HDMI_TX_STTS_BIT_CH1617_word_length_ch17_MASK (0xF00000U)
#define HDMI_TX_STTS_BIT_CH1617_word_length_ch17_SHIFT (20U)
/*! word_length_ch17 - Channel 17 word length. */
#define HDMI_TX_STTS_BIT_CH1617_word_length_ch17(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1617_word_length_ch17_SHIFT)) & HDMI_TX_STTS_BIT_CH1617_word_length_ch17_MASK)

#define HDMI_TX_STTS_BIT_CH1617_valid_bits17_16_MASK (0x3000000U)
#define HDMI_TX_STTS_BIT_CH1617_valid_bits17_16_SHIFT (24U)
/*! valid_bits17_16 - Valid Bits for channel 17 and 16 if force is enabled */
#define HDMI_TX_STTS_BIT_CH1617_valid_bits17_16(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1617_valid_bits17_16_SHIFT)) & HDMI_TX_STTS_BIT_CH1617_valid_bits17_16_MASK)

#define HDMI_TX_STTS_BIT_CH1617_reserved_0_MASK  (0xFC000000U)
#define HDMI_TX_STTS_BIT_CH1617_reserved_0_SHIFT (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_STTS_BIT_CH1617_reserved_0(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1617_reserved_0_SHIFT)) & HDMI_TX_STTS_BIT_CH1617_reserved_0_MASK)
/*! @} */

/*! @name STTS_BIT_CH1819 -  */
/*! @{ */

#define HDMI_TX_STTS_BIT_CH1819_source_num_ch18_MASK (0xFU)
#define HDMI_TX_STTS_BIT_CH1819_source_num_ch18_SHIFT (0U)
/*! source_num_ch18 - Channel 18 Source number. */
#define HDMI_TX_STTS_BIT_CH1819_source_num_ch18(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1819_source_num_ch18_SHIFT)) & HDMI_TX_STTS_BIT_CH1819_source_num_ch18_MASK)

#define HDMI_TX_STTS_BIT_CH1819_channel_num_ch18_MASK (0xF0U)
#define HDMI_TX_STTS_BIT_CH1819_channel_num_ch18_SHIFT (4U)
/*! channel_num_ch18 - Channel 18 channel number. */
#define HDMI_TX_STTS_BIT_CH1819_channel_num_ch18(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1819_channel_num_ch18_SHIFT)) & HDMI_TX_STTS_BIT_CH1819_channel_num_ch18_MASK)

#define HDMI_TX_STTS_BIT_CH1819_word_length_ch18_MASK (0xF00U)
#define HDMI_TX_STTS_BIT_CH1819_word_length_ch18_SHIFT (8U)
/*! word_length_ch18 - Channel 18 word length. */
#define HDMI_TX_STTS_BIT_CH1819_word_length_ch18(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1819_word_length_ch18_SHIFT)) & HDMI_TX_STTS_BIT_CH1819_word_length_ch18_MASK)

#define HDMI_TX_STTS_BIT_CH1819_source_num_ch19_MASK (0xF000U)
#define HDMI_TX_STTS_BIT_CH1819_source_num_ch19_SHIFT (12U)
/*! source_num_ch19 - Channel 19 Source number. */
#define HDMI_TX_STTS_BIT_CH1819_source_num_ch19(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1819_source_num_ch19_SHIFT)) & HDMI_TX_STTS_BIT_CH1819_source_num_ch19_MASK)

#define HDMI_TX_STTS_BIT_CH1819_channel_num_ch19_MASK (0xF0000U)
#define HDMI_TX_STTS_BIT_CH1819_channel_num_ch19_SHIFT (16U)
/*! channel_num_ch19 - Channel 19 channel number. */
#define HDMI_TX_STTS_BIT_CH1819_channel_num_ch19(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1819_channel_num_ch19_SHIFT)) & HDMI_TX_STTS_BIT_CH1819_channel_num_ch19_MASK)

#define HDMI_TX_STTS_BIT_CH1819_word_length_ch19_MASK (0xF00000U)
#define HDMI_TX_STTS_BIT_CH1819_word_length_ch19_SHIFT (20U)
/*! word_length_ch19 - Channel 19 word length. */
#define HDMI_TX_STTS_BIT_CH1819_word_length_ch19(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1819_word_length_ch19_SHIFT)) & HDMI_TX_STTS_BIT_CH1819_word_length_ch19_MASK)

#define HDMI_TX_STTS_BIT_CH1819_valid_bits19_18_MASK (0x3000000U)
#define HDMI_TX_STTS_BIT_CH1819_valid_bits19_18_SHIFT (24U)
/*! valid_bits19_18 - Valid Bits for channel 19 and 18 if force is enabled */
#define HDMI_TX_STTS_BIT_CH1819_valid_bits19_18(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1819_valid_bits19_18_SHIFT)) & HDMI_TX_STTS_BIT_CH1819_valid_bits19_18_MASK)

#define HDMI_TX_STTS_BIT_CH1819_reserved_0_MASK  (0xFC000000U)
#define HDMI_TX_STTS_BIT_CH1819_reserved_0_SHIFT (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_STTS_BIT_CH1819_reserved_0(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH1819_reserved_0_SHIFT)) & HDMI_TX_STTS_BIT_CH1819_reserved_0_MASK)
/*! @} */

/*! @name STTS_BIT_CH2021 -  */
/*! @{ */

#define HDMI_TX_STTS_BIT_CH2021_source_num_ch20_MASK (0xFU)
#define HDMI_TX_STTS_BIT_CH2021_source_num_ch20_SHIFT (0U)
/*! source_num_ch20 - Channel 20 Source number. */
#define HDMI_TX_STTS_BIT_CH2021_source_num_ch20(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2021_source_num_ch20_SHIFT)) & HDMI_TX_STTS_BIT_CH2021_source_num_ch20_MASK)

#define HDMI_TX_STTS_BIT_CH2021_channel_num_ch20_MASK (0xF0U)
#define HDMI_TX_STTS_BIT_CH2021_channel_num_ch20_SHIFT (4U)
/*! channel_num_ch20 - Channel 20 channel number. */
#define HDMI_TX_STTS_BIT_CH2021_channel_num_ch20(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2021_channel_num_ch20_SHIFT)) & HDMI_TX_STTS_BIT_CH2021_channel_num_ch20_MASK)

#define HDMI_TX_STTS_BIT_CH2021_word_length_ch20_MASK (0xF00U)
#define HDMI_TX_STTS_BIT_CH2021_word_length_ch20_SHIFT (8U)
/*! word_length_ch20 - Channel 20 word length. */
#define HDMI_TX_STTS_BIT_CH2021_word_length_ch20(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2021_word_length_ch20_SHIFT)) & HDMI_TX_STTS_BIT_CH2021_word_length_ch20_MASK)

#define HDMI_TX_STTS_BIT_CH2021_source_num_ch21_MASK (0xF000U)
#define HDMI_TX_STTS_BIT_CH2021_source_num_ch21_SHIFT (12U)
/*! source_num_ch21 - Channel 21 Source number. */
#define HDMI_TX_STTS_BIT_CH2021_source_num_ch21(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2021_source_num_ch21_SHIFT)) & HDMI_TX_STTS_BIT_CH2021_source_num_ch21_MASK)

#define HDMI_TX_STTS_BIT_CH2021_channel_num_ch21_MASK (0xF0000U)
#define HDMI_TX_STTS_BIT_CH2021_channel_num_ch21_SHIFT (16U)
/*! channel_num_ch21 - Channel 21 channel number. */
#define HDMI_TX_STTS_BIT_CH2021_channel_num_ch21(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2021_channel_num_ch21_SHIFT)) & HDMI_TX_STTS_BIT_CH2021_channel_num_ch21_MASK)

#define HDMI_TX_STTS_BIT_CH2021_word_length_ch21_MASK (0xF00000U)
#define HDMI_TX_STTS_BIT_CH2021_word_length_ch21_SHIFT (20U)
/*! word_length_ch21 - Channel 21 word length. */
#define HDMI_TX_STTS_BIT_CH2021_word_length_ch21(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2021_word_length_ch21_SHIFT)) & HDMI_TX_STTS_BIT_CH2021_word_length_ch21_MASK)

#define HDMI_TX_STTS_BIT_CH2021_valid_bits21_20_MASK (0x3000000U)
#define HDMI_TX_STTS_BIT_CH2021_valid_bits21_20_SHIFT (24U)
/*! valid_bits21_20 - Valid Bits for channel 21 and 20 if force is enabled */
#define HDMI_TX_STTS_BIT_CH2021_valid_bits21_20(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2021_valid_bits21_20_SHIFT)) & HDMI_TX_STTS_BIT_CH2021_valid_bits21_20_MASK)

#define HDMI_TX_STTS_BIT_CH2021_reserved_0_MASK  (0xFC000000U)
#define HDMI_TX_STTS_BIT_CH2021_reserved_0_SHIFT (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_STTS_BIT_CH2021_reserved_0(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2021_reserved_0_SHIFT)) & HDMI_TX_STTS_BIT_CH2021_reserved_0_MASK)
/*! @} */

/*! @name STTS_BIT_CH2223 -  */
/*! @{ */

#define HDMI_TX_STTS_BIT_CH2223_source_num_ch22_MASK (0xFU)
#define HDMI_TX_STTS_BIT_CH2223_source_num_ch22_SHIFT (0U)
/*! source_num_ch22 - Channel 22 Source number. */
#define HDMI_TX_STTS_BIT_CH2223_source_num_ch22(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2223_source_num_ch22_SHIFT)) & HDMI_TX_STTS_BIT_CH2223_source_num_ch22_MASK)

#define HDMI_TX_STTS_BIT_CH2223_channel_num_ch22_MASK (0xF0U)
#define HDMI_TX_STTS_BIT_CH2223_channel_num_ch22_SHIFT (4U)
/*! channel_num_ch22 - Channel 22 channel number. */
#define HDMI_TX_STTS_BIT_CH2223_channel_num_ch22(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2223_channel_num_ch22_SHIFT)) & HDMI_TX_STTS_BIT_CH2223_channel_num_ch22_MASK)

#define HDMI_TX_STTS_BIT_CH2223_word_length_ch22_MASK (0xF00U)
#define HDMI_TX_STTS_BIT_CH2223_word_length_ch22_SHIFT (8U)
/*! word_length_ch22 - Channel 22 word length. */
#define HDMI_TX_STTS_BIT_CH2223_word_length_ch22(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2223_word_length_ch22_SHIFT)) & HDMI_TX_STTS_BIT_CH2223_word_length_ch22_MASK)

#define HDMI_TX_STTS_BIT_CH2223_source_num_ch23_MASK (0xF000U)
#define HDMI_TX_STTS_BIT_CH2223_source_num_ch23_SHIFT (12U)
/*! source_num_ch23 - Channel 23 Source number. */
#define HDMI_TX_STTS_BIT_CH2223_source_num_ch23(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2223_source_num_ch23_SHIFT)) & HDMI_TX_STTS_BIT_CH2223_source_num_ch23_MASK)

#define HDMI_TX_STTS_BIT_CH2223_channel_num_ch23_MASK (0xF0000U)
#define HDMI_TX_STTS_BIT_CH2223_channel_num_ch23_SHIFT (16U)
/*! channel_num_ch23 - Channel 23 channel number. */
#define HDMI_TX_STTS_BIT_CH2223_channel_num_ch23(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2223_channel_num_ch23_SHIFT)) & HDMI_TX_STTS_BIT_CH2223_channel_num_ch23_MASK)

#define HDMI_TX_STTS_BIT_CH2223_word_length_ch23_MASK (0xF00000U)
#define HDMI_TX_STTS_BIT_CH2223_word_length_ch23_SHIFT (20U)
/*! word_length_ch23 - Channel 23 word length. */
#define HDMI_TX_STTS_BIT_CH2223_word_length_ch23(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2223_word_length_ch23_SHIFT)) & HDMI_TX_STTS_BIT_CH2223_word_length_ch23_MASK)

#define HDMI_TX_STTS_BIT_CH2223_valid_bits23_22_MASK (0x3000000U)
#define HDMI_TX_STTS_BIT_CH2223_valid_bits23_22_SHIFT (24U)
/*! valid_bits23_22 - Valid Bits for channel 23 and 22 if force is enabled */
#define HDMI_TX_STTS_BIT_CH2223_valid_bits23_22(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2223_valid_bits23_22_SHIFT)) & HDMI_TX_STTS_BIT_CH2223_valid_bits23_22_MASK)

#define HDMI_TX_STTS_BIT_CH2223_reserved_0_MASK  (0xFC000000U)
#define HDMI_TX_STTS_BIT_CH2223_reserved_0_SHIFT (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_STTS_BIT_CH2223_reserved_0(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2223_reserved_0_SHIFT)) & HDMI_TX_STTS_BIT_CH2223_reserved_0_MASK)
/*! @} */

/*! @name STTS_BIT_CH2425 -  */
/*! @{ */

#define HDMI_TX_STTS_BIT_CH2425_source_num_ch24_MASK (0xFU)
#define HDMI_TX_STTS_BIT_CH2425_source_num_ch24_SHIFT (0U)
/*! source_num_ch24 - Channel 24 Source number. */
#define HDMI_TX_STTS_BIT_CH2425_source_num_ch24(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2425_source_num_ch24_SHIFT)) & HDMI_TX_STTS_BIT_CH2425_source_num_ch24_MASK)

#define HDMI_TX_STTS_BIT_CH2425_channel_num_ch24_MASK (0xF0U)
#define HDMI_TX_STTS_BIT_CH2425_channel_num_ch24_SHIFT (4U)
/*! channel_num_ch24 - Channel 24 channel number. */
#define HDMI_TX_STTS_BIT_CH2425_channel_num_ch24(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2425_channel_num_ch24_SHIFT)) & HDMI_TX_STTS_BIT_CH2425_channel_num_ch24_MASK)

#define HDMI_TX_STTS_BIT_CH2425_word_length_ch24_MASK (0xF00U)
#define HDMI_TX_STTS_BIT_CH2425_word_length_ch24_SHIFT (8U)
/*! word_length_ch24 - Channel 24 word length. */
#define HDMI_TX_STTS_BIT_CH2425_word_length_ch24(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2425_word_length_ch24_SHIFT)) & HDMI_TX_STTS_BIT_CH2425_word_length_ch24_MASK)

#define HDMI_TX_STTS_BIT_CH2425_source_num_ch25_MASK (0xF000U)
#define HDMI_TX_STTS_BIT_CH2425_source_num_ch25_SHIFT (12U)
/*! source_num_ch25 - Channel 25 Source number. */
#define HDMI_TX_STTS_BIT_CH2425_source_num_ch25(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2425_source_num_ch25_SHIFT)) & HDMI_TX_STTS_BIT_CH2425_source_num_ch25_MASK)

#define HDMI_TX_STTS_BIT_CH2425_channel_num_ch25_MASK (0xF0000U)
#define HDMI_TX_STTS_BIT_CH2425_channel_num_ch25_SHIFT (16U)
/*! channel_num_ch25 - Channel 25 channel number. */
#define HDMI_TX_STTS_BIT_CH2425_channel_num_ch25(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2425_channel_num_ch25_SHIFT)) & HDMI_TX_STTS_BIT_CH2425_channel_num_ch25_MASK)

#define HDMI_TX_STTS_BIT_CH2425_word_length_ch25_MASK (0xF00000U)
#define HDMI_TX_STTS_BIT_CH2425_word_length_ch25_SHIFT (20U)
/*! word_length_ch25 - Channel 25 word length. */
#define HDMI_TX_STTS_BIT_CH2425_word_length_ch25(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2425_word_length_ch25_SHIFT)) & HDMI_TX_STTS_BIT_CH2425_word_length_ch25_MASK)

#define HDMI_TX_STTS_BIT_CH2425_valid_bits25_24_MASK (0x3000000U)
#define HDMI_TX_STTS_BIT_CH2425_valid_bits25_24_SHIFT (24U)
/*! valid_bits25_24 - Valid Bits for channel 25 and 24 if force is enabled */
#define HDMI_TX_STTS_BIT_CH2425_valid_bits25_24(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2425_valid_bits25_24_SHIFT)) & HDMI_TX_STTS_BIT_CH2425_valid_bits25_24_MASK)

#define HDMI_TX_STTS_BIT_CH2425_reserved_0_MASK  (0xFC000000U)
#define HDMI_TX_STTS_BIT_CH2425_reserved_0_SHIFT (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_STTS_BIT_CH2425_reserved_0(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2425_reserved_0_SHIFT)) & HDMI_TX_STTS_BIT_CH2425_reserved_0_MASK)
/*! @} */

/*! @name STTS_BIT_CH2627 -  */
/*! @{ */

#define HDMI_TX_STTS_BIT_CH2627_source_num_ch26_MASK (0xFU)
#define HDMI_TX_STTS_BIT_CH2627_source_num_ch26_SHIFT (0U)
/*! source_num_ch26 - Channel 26 Source number. */
#define HDMI_TX_STTS_BIT_CH2627_source_num_ch26(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2627_source_num_ch26_SHIFT)) & HDMI_TX_STTS_BIT_CH2627_source_num_ch26_MASK)

#define HDMI_TX_STTS_BIT_CH2627_channel_num_ch26_MASK (0xF0U)
#define HDMI_TX_STTS_BIT_CH2627_channel_num_ch26_SHIFT (4U)
/*! channel_num_ch26 - Channel 26 channel number. */
#define HDMI_TX_STTS_BIT_CH2627_channel_num_ch26(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2627_channel_num_ch26_SHIFT)) & HDMI_TX_STTS_BIT_CH2627_channel_num_ch26_MASK)

#define HDMI_TX_STTS_BIT_CH2627_word_length_ch26_MASK (0xF00U)
#define HDMI_TX_STTS_BIT_CH2627_word_length_ch26_SHIFT (8U)
/*! word_length_ch26 - Channel 26 word length. */
#define HDMI_TX_STTS_BIT_CH2627_word_length_ch26(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2627_word_length_ch26_SHIFT)) & HDMI_TX_STTS_BIT_CH2627_word_length_ch26_MASK)

#define HDMI_TX_STTS_BIT_CH2627_source_num_ch27_MASK (0xF000U)
#define HDMI_TX_STTS_BIT_CH2627_source_num_ch27_SHIFT (12U)
/*! source_num_ch27 - Channel 27 Source number. */
#define HDMI_TX_STTS_BIT_CH2627_source_num_ch27(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2627_source_num_ch27_SHIFT)) & HDMI_TX_STTS_BIT_CH2627_source_num_ch27_MASK)

#define HDMI_TX_STTS_BIT_CH2627_channel_num_ch27_MASK (0xF0000U)
#define HDMI_TX_STTS_BIT_CH2627_channel_num_ch27_SHIFT (16U)
/*! channel_num_ch27 - Channel 27 channel number. */
#define HDMI_TX_STTS_BIT_CH2627_channel_num_ch27(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2627_channel_num_ch27_SHIFT)) & HDMI_TX_STTS_BIT_CH2627_channel_num_ch27_MASK)

#define HDMI_TX_STTS_BIT_CH2627_word_length_ch27_MASK (0xF00000U)
#define HDMI_TX_STTS_BIT_CH2627_word_length_ch27_SHIFT (20U)
/*! word_length_ch27 - Channel 27 word length. */
#define HDMI_TX_STTS_BIT_CH2627_word_length_ch27(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2627_word_length_ch27_SHIFT)) & HDMI_TX_STTS_BIT_CH2627_word_length_ch27_MASK)

#define HDMI_TX_STTS_BIT_CH2627_valid_bits27_26_MASK (0x3000000U)
#define HDMI_TX_STTS_BIT_CH2627_valid_bits27_26_SHIFT (24U)
/*! valid_bits27_26 - Valid Bits for channel 27 and 26 if force is enabled */
#define HDMI_TX_STTS_BIT_CH2627_valid_bits27_26(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2627_valid_bits27_26_SHIFT)) & HDMI_TX_STTS_BIT_CH2627_valid_bits27_26_MASK)

#define HDMI_TX_STTS_BIT_CH2627_reserved_0_MASK  (0xFC000000U)
#define HDMI_TX_STTS_BIT_CH2627_reserved_0_SHIFT (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_STTS_BIT_CH2627_reserved_0(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2627_reserved_0_SHIFT)) & HDMI_TX_STTS_BIT_CH2627_reserved_0_MASK)
/*! @} */

/*! @name STTS_BIT_CH2829 -  */
/*! @{ */

#define HDMI_TX_STTS_BIT_CH2829_source_num_ch28_MASK (0xFU)
#define HDMI_TX_STTS_BIT_CH2829_source_num_ch28_SHIFT (0U)
/*! source_num_ch28 - Channel 28 Source number. */
#define HDMI_TX_STTS_BIT_CH2829_source_num_ch28(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2829_source_num_ch28_SHIFT)) & HDMI_TX_STTS_BIT_CH2829_source_num_ch28_MASK)

#define HDMI_TX_STTS_BIT_CH2829_channel_num_ch28_MASK (0xF0U)
#define HDMI_TX_STTS_BIT_CH2829_channel_num_ch28_SHIFT (4U)
/*! channel_num_ch28 - Channel 28 channel number. */
#define HDMI_TX_STTS_BIT_CH2829_channel_num_ch28(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2829_channel_num_ch28_SHIFT)) & HDMI_TX_STTS_BIT_CH2829_channel_num_ch28_MASK)

#define HDMI_TX_STTS_BIT_CH2829_word_length_ch28_MASK (0xF00U)
#define HDMI_TX_STTS_BIT_CH2829_word_length_ch28_SHIFT (8U)
/*! word_length_ch28 - Channel 28 word length. */
#define HDMI_TX_STTS_BIT_CH2829_word_length_ch28(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2829_word_length_ch28_SHIFT)) & HDMI_TX_STTS_BIT_CH2829_word_length_ch28_MASK)

#define HDMI_TX_STTS_BIT_CH2829_source_num_ch29_MASK (0xF000U)
#define HDMI_TX_STTS_BIT_CH2829_source_num_ch29_SHIFT (12U)
/*! source_num_ch29 - Channel 29 Source number. */
#define HDMI_TX_STTS_BIT_CH2829_source_num_ch29(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2829_source_num_ch29_SHIFT)) & HDMI_TX_STTS_BIT_CH2829_source_num_ch29_MASK)

#define HDMI_TX_STTS_BIT_CH2829_channel_num_ch29_MASK (0xF0000U)
#define HDMI_TX_STTS_BIT_CH2829_channel_num_ch29_SHIFT (16U)
/*! channel_num_ch29 - Channel 29 channel number. */
#define HDMI_TX_STTS_BIT_CH2829_channel_num_ch29(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2829_channel_num_ch29_SHIFT)) & HDMI_TX_STTS_BIT_CH2829_channel_num_ch29_MASK)

#define HDMI_TX_STTS_BIT_CH2829_word_length_ch29_MASK (0xF00000U)
#define HDMI_TX_STTS_BIT_CH2829_word_length_ch29_SHIFT (20U)
/*! word_length_ch29 - Channel 29 word length. */
#define HDMI_TX_STTS_BIT_CH2829_word_length_ch29(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2829_word_length_ch29_SHIFT)) & HDMI_TX_STTS_BIT_CH2829_word_length_ch29_MASK)

#define HDMI_TX_STTS_BIT_CH2829_valid_bits29_28_MASK (0x3000000U)
#define HDMI_TX_STTS_BIT_CH2829_valid_bits29_28_SHIFT (24U)
/*! valid_bits29_28 - Valid Bits for channel 29 and 28 if force is enabled */
#define HDMI_TX_STTS_BIT_CH2829_valid_bits29_28(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2829_valid_bits29_28_SHIFT)) & HDMI_TX_STTS_BIT_CH2829_valid_bits29_28_MASK)

#define HDMI_TX_STTS_BIT_CH2829_reserved_0_MASK  (0xFC000000U)
#define HDMI_TX_STTS_BIT_CH2829_reserved_0_SHIFT (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_STTS_BIT_CH2829_reserved_0(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH2829_reserved_0_SHIFT)) & HDMI_TX_STTS_BIT_CH2829_reserved_0_MASK)
/*! @} */

/*! @name STTS_BIT_CH3031 -  */
/*! @{ */

#define HDMI_TX_STTS_BIT_CH3031_source_num_ch30_MASK (0xFU)
#define HDMI_TX_STTS_BIT_CH3031_source_num_ch30_SHIFT (0U)
/*! source_num_ch30 - Channel 30 Source number. */
#define HDMI_TX_STTS_BIT_CH3031_source_num_ch30(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH3031_source_num_ch30_SHIFT)) & HDMI_TX_STTS_BIT_CH3031_source_num_ch30_MASK)

#define HDMI_TX_STTS_BIT_CH3031_channel_num_ch30_MASK (0xF0U)
#define HDMI_TX_STTS_BIT_CH3031_channel_num_ch30_SHIFT (4U)
/*! channel_num_ch30 - Channel 30 channel number. */
#define HDMI_TX_STTS_BIT_CH3031_channel_num_ch30(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH3031_channel_num_ch30_SHIFT)) & HDMI_TX_STTS_BIT_CH3031_channel_num_ch30_MASK)

#define HDMI_TX_STTS_BIT_CH3031_word_length_ch30_MASK (0xF00U)
#define HDMI_TX_STTS_BIT_CH3031_word_length_ch30_SHIFT (8U)
/*! word_length_ch30 - Channel 30 word length. */
#define HDMI_TX_STTS_BIT_CH3031_word_length_ch30(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH3031_word_length_ch30_SHIFT)) & HDMI_TX_STTS_BIT_CH3031_word_length_ch30_MASK)

#define HDMI_TX_STTS_BIT_CH3031_source_num_ch31_MASK (0xF000U)
#define HDMI_TX_STTS_BIT_CH3031_source_num_ch31_SHIFT (12U)
/*! source_num_ch31 - Channel 31 Source number. */
#define HDMI_TX_STTS_BIT_CH3031_source_num_ch31(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH3031_source_num_ch31_SHIFT)) & HDMI_TX_STTS_BIT_CH3031_source_num_ch31_MASK)

#define HDMI_TX_STTS_BIT_CH3031_channel_num_ch31_MASK (0xF0000U)
#define HDMI_TX_STTS_BIT_CH3031_channel_num_ch31_SHIFT (16U)
/*! channel_num_ch31 - Channel 31 channel number. */
#define HDMI_TX_STTS_BIT_CH3031_channel_num_ch31(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH3031_channel_num_ch31_SHIFT)) & HDMI_TX_STTS_BIT_CH3031_channel_num_ch31_MASK)

#define HDMI_TX_STTS_BIT_CH3031_word_length_ch31_MASK (0xF00000U)
#define HDMI_TX_STTS_BIT_CH3031_word_length_ch31_SHIFT (20U)
/*! word_length_ch31 - Channel 31 word length. */
#define HDMI_TX_STTS_BIT_CH3031_word_length_ch31(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH3031_word_length_ch31_SHIFT)) & HDMI_TX_STTS_BIT_CH3031_word_length_ch31_MASK)

#define HDMI_TX_STTS_BIT_CH3031_valid_bits31_30_MASK (0x3000000U)
#define HDMI_TX_STTS_BIT_CH3031_valid_bits31_30_SHIFT (24U)
/*! valid_bits31_30 - Valid Bits for channel 31 and 30 if force is enabled */
#define HDMI_TX_STTS_BIT_CH3031_valid_bits31_30(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH3031_valid_bits31_30_SHIFT)) & HDMI_TX_STTS_BIT_CH3031_valid_bits31_30_MASK)

#define HDMI_TX_STTS_BIT_CH3031_reserved_0_MASK  (0xFC000000U)
#define HDMI_TX_STTS_BIT_CH3031_reserved_0_SHIFT (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_STTS_BIT_CH3031_reserved_0(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_STTS_BIT_CH3031_reserved_0_SHIFT)) & HDMI_TX_STTS_BIT_CH3031_reserved_0_MASK)
/*! @} */

/*! @name SPDIF_CTRL_ADDR -  */
/*! @{ */

#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_avg_win_MASK (0x7U)
#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_avg_win_SHIFT (0U)
/*! spdif_jitter_avg_win - Spdif Jitter AVG Window */
#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_avg_win(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_avg_win_SHIFT)) & HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_avg_win_MASK)

#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_thrsh_MASK (0x7F8U)
#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_thrsh_SHIFT (3U)
/*! spdif_jitter_thrsh - SPDIF Jitter threshold */
#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_thrsh(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_thrsh_SHIFT)) & HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_thrsh_MASK)

#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_fifo_mid_range_MASK (0x7F800U)
#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_fifo_mid_range_SHIFT (11U)
/*! spdif_fifo_mid_range - SPDIF fifo mid range */
#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_fifo_mid_range(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CTRL_ADDR_spdif_fifo_mid_range_SHIFT)) & HDMI_TX_SPDIF_CTRL_ADDR_spdif_fifo_mid_range_MASK)

#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_bypass_MASK (0x80000U)
#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_bypass_SHIFT (19U)
/*! spdif_jitter_bypass - SPDIF Jitter Bypass */
#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_bypass(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_bypass_SHIFT)) & HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_bypass_MASK)

#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_avg_sel_MASK (0x100000U)
#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_avg_sel_SHIFT (20U)
/*! spdif_avg_sel - SPDIF average Select */
#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_avg_sel(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CTRL_ADDR_spdif_avg_sel_SHIFT)) & HDMI_TX_SPDIF_CTRL_ADDR_spdif_avg_sel_MASK)

#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_enable_MASK (0x200000U)
#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_enable_SHIFT (21U)
/*! spdif_enable - SPDIF Enable */
#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_enable(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CTRL_ADDR_spdif_enable_SHIFT)) & HDMI_TX_SPDIF_CTRL_ADDR_spdif_enable_MASK)

#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_status_MASK (0x3C00000U)
#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_status_SHIFT (22U)
/*! spdif_jitter_status - SPDIF Jitter Status */
#define HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_status(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_status_SHIFT)) & HDMI_TX_SPDIF_CTRL_ADDR_spdif_jitter_status_MASK)

#define HDMI_TX_SPDIF_CTRL_ADDR_reserved_0_MASK  (0xFC000000U)
#define HDMI_TX_SPDIF_CTRL_ADDR_reserved_0_SHIFT (26U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SPDIF_CTRL_ADDR_reserved_0(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CTRL_ADDR_reserved_0_SHIFT)) & HDMI_TX_SPDIF_CTRL_ADDR_reserved_0_MASK)
/*! @} */

/*! @name SPDIF_CH1_CS_3100_ADDR -  */
/*! @{ */

#define HDMI_TX_SPDIF_CH1_CS_3100_ADDR_spdif_ch1_st_stts_bits3100_MASK (0xFFFFFFFFU)
#define HDMI_TX_SPDIF_CH1_CS_3100_ADDR_spdif_ch1_st_stts_bits3100_SHIFT (0U)
/*! spdif_ch1_st_stts_bits3100 - SPDIF Channel 1 Status bits[31:0] */
#define HDMI_TX_SPDIF_CH1_CS_3100_ADDR_spdif_ch1_st_stts_bits3100(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CH1_CS_3100_ADDR_spdif_ch1_st_stts_bits3100_SHIFT)) & HDMI_TX_SPDIF_CH1_CS_3100_ADDR_spdif_ch1_st_stts_bits3100_MASK)
/*! @} */

/*! @name SPDIF_CH1_CS_6332_ADDR -  */
/*! @{ */

#define HDMI_TX_SPDIF_CH1_CS_6332_ADDR_spdif_ch1_st_stts_bits6332_MASK (0xFFFFFFFFU)
#define HDMI_TX_SPDIF_CH1_CS_6332_ADDR_spdif_ch1_st_stts_bits6332_SHIFT (0U)
/*! spdif_ch1_st_stts_bits6332 - SPDIF Channel 1 Status bits[63:32] */
#define HDMI_TX_SPDIF_CH1_CS_6332_ADDR_spdif_ch1_st_stts_bits6332(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CH1_CS_6332_ADDR_spdif_ch1_st_stts_bits6332_SHIFT)) & HDMI_TX_SPDIF_CH1_CS_6332_ADDR_spdif_ch1_st_stts_bits6332_MASK)
/*! @} */

/*! @name SPDIF_CH1_CS_9564_ADDR -  */
/*! @{ */

#define HDMI_TX_SPDIF_CH1_CS_9564_ADDR_spdif_ch1_st_stts_bits9564_MASK (0xFFFFFFFFU)
#define HDMI_TX_SPDIF_CH1_CS_9564_ADDR_spdif_ch1_st_stts_bits9564_SHIFT (0U)
/*! spdif_ch1_st_stts_bits9564 - SPDIF Channel 1 Status bits[95:64] */
#define HDMI_TX_SPDIF_CH1_CS_9564_ADDR_spdif_ch1_st_stts_bits9564(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CH1_CS_9564_ADDR_spdif_ch1_st_stts_bits9564_SHIFT)) & HDMI_TX_SPDIF_CH1_CS_9564_ADDR_spdif_ch1_st_stts_bits9564_MASK)
/*! @} */

/*! @name SPDIF_CH1_CS_12796_ADDR -  */
/*! @{ */

#define HDMI_TX_SPDIF_CH1_CS_12796_ADDR_spdif_ch1_st_stts_bits12796_MASK (0xFFFFFFFFU)
#define HDMI_TX_SPDIF_CH1_CS_12796_ADDR_spdif_ch1_st_stts_bits12796_SHIFT (0U)
/*! spdif_ch1_st_stts_bits12796 - SPDIF Channel 1 Status bits[127:96] */
#define HDMI_TX_SPDIF_CH1_CS_12796_ADDR_spdif_ch1_st_stts_bits12796(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CH1_CS_12796_ADDR_spdif_ch1_st_stts_bits12796_SHIFT)) & HDMI_TX_SPDIF_CH1_CS_12796_ADDR_spdif_ch1_st_stts_bits12796_MASK)
/*! @} */

/*! @name SPDIF_CH1_CS_159128_ADDR -  */
/*! @{ */

#define HDMI_TX_SPDIF_CH1_CS_159128_ADDR_spdif_ch1_st_stts_bits159128_MASK (0xFFFFFFFFU)
#define HDMI_TX_SPDIF_CH1_CS_159128_ADDR_spdif_ch1_st_stts_bits159128_SHIFT (0U)
/*! spdif_ch1_st_stts_bits159128 - SPDIF Channel 1 Status bits[159:128] */
#define HDMI_TX_SPDIF_CH1_CS_159128_ADDR_spdif_ch1_st_stts_bits159128(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CH1_CS_159128_ADDR_spdif_ch1_st_stts_bits159128_SHIFT)) & HDMI_TX_SPDIF_CH1_CS_159128_ADDR_spdif_ch1_st_stts_bits159128_MASK)
/*! @} */

/*! @name SPDIF_CH1_CS_191160_ADDR -  */
/*! @{ */

#define HDMI_TX_SPDIF_CH1_CS_191160_ADDR_spdif_ch1_st_stts_bits191160_MASK (0xFFFFFFFFU)
#define HDMI_TX_SPDIF_CH1_CS_191160_ADDR_spdif_ch1_st_stts_bits191160_SHIFT (0U)
/*! spdif_ch1_st_stts_bits191160 - SPDIF Channel 1 Status bits[191160] */
#define HDMI_TX_SPDIF_CH1_CS_191160_ADDR_spdif_ch1_st_stts_bits191160(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CH1_CS_191160_ADDR_spdif_ch1_st_stts_bits191160_SHIFT)) & HDMI_TX_SPDIF_CH1_CS_191160_ADDR_spdif_ch1_st_stts_bits191160_MASK)
/*! @} */

/*! @name SPDIF_CH2_CS_3100_ADDR -  */
/*! @{ */

#define HDMI_TX_SPDIF_CH2_CS_3100_ADDR_spdif_ch2_st_stts_bits3100_MASK (0xFFFFFFFFU)
#define HDMI_TX_SPDIF_CH2_CS_3100_ADDR_spdif_ch2_st_stts_bits3100_SHIFT (0U)
/*! spdif_ch2_st_stts_bits3100 - SPDIF Channel 2 Status bits[31:0] */
#define HDMI_TX_SPDIF_CH2_CS_3100_ADDR_spdif_ch2_st_stts_bits3100(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CH2_CS_3100_ADDR_spdif_ch2_st_stts_bits3100_SHIFT)) & HDMI_TX_SPDIF_CH2_CS_3100_ADDR_spdif_ch2_st_stts_bits3100_MASK)
/*! @} */

/*! @name SPDIF_CH2_CS_6332_ADDR -  */
/*! @{ */

#define HDMI_TX_SPDIF_CH2_CS_6332_ADDR_spdif_ch2_st_stts_bits6332_MASK (0xFFFFFFFFU)
#define HDMI_TX_SPDIF_CH2_CS_6332_ADDR_spdif_ch2_st_stts_bits6332_SHIFT (0U)
/*! spdif_ch2_st_stts_bits6332 - SPDIF Channel 2 Status bits[63:32] */
#define HDMI_TX_SPDIF_CH2_CS_6332_ADDR_spdif_ch2_st_stts_bits6332(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CH2_CS_6332_ADDR_spdif_ch2_st_stts_bits6332_SHIFT)) & HDMI_TX_SPDIF_CH2_CS_6332_ADDR_spdif_ch2_st_stts_bits6332_MASK)
/*! @} */

/*! @name SPDIF_CH2_CS_9564_ADDR -  */
/*! @{ */

#define HDMI_TX_SPDIF_CH2_CS_9564_ADDR_spdif_ch2_st_stts_bits9564_MASK (0xFFFFFFFFU)
#define HDMI_TX_SPDIF_CH2_CS_9564_ADDR_spdif_ch2_st_stts_bits9564_SHIFT (0U)
/*! spdif_ch2_st_stts_bits9564 - SPDIF Channel 2 Status bits[95:64] */
#define HDMI_TX_SPDIF_CH2_CS_9564_ADDR_spdif_ch2_st_stts_bits9564(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CH2_CS_9564_ADDR_spdif_ch2_st_stts_bits9564_SHIFT)) & HDMI_TX_SPDIF_CH2_CS_9564_ADDR_spdif_ch2_st_stts_bits9564_MASK)
/*! @} */

/*! @name SPDIF_CH2_CS_12796_ADDR -  */
/*! @{ */

#define HDMI_TX_SPDIF_CH2_CS_12796_ADDR_spdif_ch2_st_stts_bits12796_MASK (0xFFFFFFFFU)
#define HDMI_TX_SPDIF_CH2_CS_12796_ADDR_spdif_ch2_st_stts_bits12796_SHIFT (0U)
/*! spdif_ch2_st_stts_bits12796 - SPDIF Channel 2 Status bits[127:96] */
#define HDMI_TX_SPDIF_CH2_CS_12796_ADDR_spdif_ch2_st_stts_bits12796(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CH2_CS_12796_ADDR_spdif_ch2_st_stts_bits12796_SHIFT)) & HDMI_TX_SPDIF_CH2_CS_12796_ADDR_spdif_ch2_st_stts_bits12796_MASK)
/*! @} */

/*! @name SPDIF_CH2_CS_159128_ADDR -  */
/*! @{ */

#define HDMI_TX_SPDIF_CH2_CS_159128_ADDR_spdif_ch2_st_stts_bits159128_MASK (0xFFFFFFFFU)
#define HDMI_TX_SPDIF_CH2_CS_159128_ADDR_spdif_ch2_st_stts_bits159128_SHIFT (0U)
/*! spdif_ch2_st_stts_bits159128 - SPDIF Channel 2 Status bits[159:128] */
#define HDMI_TX_SPDIF_CH2_CS_159128_ADDR_spdif_ch2_st_stts_bits159128(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CH2_CS_159128_ADDR_spdif_ch2_st_stts_bits159128_SHIFT)) & HDMI_TX_SPDIF_CH2_CS_159128_ADDR_spdif_ch2_st_stts_bits159128_MASK)
/*! @} */

/*! @name SPDIF_CH2_CS_191160_ADDR -  */
/*! @{ */

#define HDMI_TX_SPDIF_CH2_CS_191160_ADDR_spdif_ch2_st_stts_bits191160_MASK (0xFFFFFFFFU)
#define HDMI_TX_SPDIF_CH2_CS_191160_ADDR_spdif_ch2_st_stts_bits191160_SHIFT (0U)
/*! spdif_ch2_st_stts_bits191160 - SPDIF Channel 2 Status bits[191160] */
#define HDMI_TX_SPDIF_CH2_CS_191160_ADDR_spdif_ch2_st_stts_bits191160(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SPDIF_CH2_CS_191160_ADDR_spdif_ch2_st_stts_bits191160_SHIFT)) & HDMI_TX_SPDIF_CH2_CS_191160_ADDR_spdif_ch2_st_stts_bits191160_MASK)
/*! @} */

/*! @name SMPL2PKT_CNTL -  */
/*! @{ */

#define HDMI_TX_SMPL2PKT_CNTL_sw_rst_MASK        (0x1U)
#define HDMI_TX_SMPL2PKT_CNTL_sw_rst_SHIFT       (0U)
/*! sw_rst - Software reset. Active high. */
#define HDMI_TX_SMPL2PKT_CNTL_sw_rst(x)          (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SMPL2PKT_CNTL_sw_rst_SHIFT)) & HDMI_TX_SMPL2PKT_CNTL_sw_rst_MASK)

#define HDMI_TX_SMPL2PKT_CNTL_smpl2pkt_en_MASK   (0x2U)
#define HDMI_TX_SMPL2PKT_CNTL_smpl2pkt_en_SHIFT  (1U)
/*! smpl2pkt_en - When high Sample to Packets Block starts. */
#define HDMI_TX_SMPL2PKT_CNTL_smpl2pkt_en(x)     (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SMPL2PKT_CNTL_smpl2pkt_en_SHIFT)) & HDMI_TX_SMPL2PKT_CNTL_smpl2pkt_en_MASK)

#define HDMI_TX_SMPL2PKT_CNTL_reserved_0_MASK    (0xFFFFFFFCU)
#define HDMI_TX_SMPL2PKT_CNTL_reserved_0_SHIFT   (2U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SMPL2PKT_CNTL_reserved_0(x)      (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SMPL2PKT_CNTL_reserved_0_SHIFT)) & HDMI_TX_SMPL2PKT_CNTL_reserved_0_MASK)
/*! @} */

/*! @name SMPL2PKT_CNFG -  */
/*! @{ */

#define HDMI_TX_SMPL2PKT_CNFG_max_num_ch_MASK    (0x1FU)
#define HDMI_TX_SMPL2PKT_CNFG_max_num_ch_SHIFT   (0U)
/*! max_num_ch - Number of channels to decode. 0: 1 channel, 31: 32 channels */
#define HDMI_TX_SMPL2PKT_CNFG_max_num_ch(x)      (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SMPL2PKT_CNFG_max_num_ch_SHIFT)) & HDMI_TX_SMPL2PKT_CNFG_max_num_ch_MASK)

#define HDMI_TX_SMPL2PKT_CNFG_num_of_i2s_ports_MASK (0x60U)
#define HDMI_TX_SMPL2PKT_CNFG_num_of_i2s_ports_SHIFT (5U)
/*! num_of_i2s_ports - Number ofactive I2S ports. 00- 1 port, 01-2 ports, 11- 4 ports, 11 -NA. */
#define HDMI_TX_SMPL2PKT_CNFG_num_of_i2s_ports(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SMPL2PKT_CNFG_num_of_i2s_ports_SHIFT)) & HDMI_TX_SMPL2PKT_CNFG_num_of_i2s_ports_MASK)

#define HDMI_TX_SMPL2PKT_CNFG_audio_type_MASK    (0x780U)
#define HDMI_TX_SMPL2PKT_CNFG_audio_type_SHIFT   (7U)
/*! audio_type - Audio Type setting. Packet is structured according to audio type. */
#define HDMI_TX_SMPL2PKT_CNFG_audio_type(x)      (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SMPL2PKT_CNFG_audio_type_SHIFT)) & HDMI_TX_SMPL2PKT_CNFG_audio_type_MASK)

#define HDMI_TX_SMPL2PKT_CNFG_cfg_sub_pckt_num_MASK (0x3800U)
#define HDMI_TX_SMPL2PKT_CNFG_cfg_sub_pckt_num_SHIFT (11U)
/*! cfg_sub_pckt_num - Number of sub-packets in HDMI audio 2-ch packet. 00: 1-SP, 01: 2-SP, 10: 3-SP, 11: 4-SP.100-111: NA. */
#define HDMI_TX_SMPL2PKT_CNFG_cfg_sub_pckt_num(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SMPL2PKT_CNFG_cfg_sub_pckt_num_SHIFT)) & HDMI_TX_SMPL2PKT_CNFG_cfg_sub_pckt_num_MASK)

#define HDMI_TX_SMPL2PKT_CNFG_cfg_block_lpcm_first_pkt_MASK (0x4000U)
#define HDMI_TX_SMPL2PKT_CNFG_cfg_block_lpcm_first_pkt_SHIFT (14U)
/*! cfg_block_lpcm_first_pkt - 0 - All packets behave the same. 1- First lpcm audio packet is sent with 1 - SP. */
#define HDMI_TX_SMPL2PKT_CNFG_cfg_block_lpcm_first_pkt(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SMPL2PKT_CNFG_cfg_block_lpcm_first_pkt_SHIFT)) & HDMI_TX_SMPL2PKT_CNFG_cfg_block_lpcm_first_pkt_MASK)

#define HDMI_TX_SMPL2PKT_CNFG_cfg_en_auto_sub_pckt_num_MASK (0x8000U)
#define HDMI_TX_SMPL2PKT_CNFG_cfg_en_auto_sub_pckt_num_SHIFT (15U)
/*! cfg_en_auto_sub_pckt_num - Enable automatics sub packet number. When enabled number of
 *    sub-packts will be set according to MEM FIFO number of samples.
 */
#define HDMI_TX_SMPL2PKT_CNFG_cfg_en_auto_sub_pckt_num(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SMPL2PKT_CNFG_cfg_en_auto_sub_pckt_num_SHIFT)) & HDMI_TX_SMPL2PKT_CNFG_cfg_en_auto_sub_pckt_num_MASK)

#define HDMI_TX_SMPL2PKT_CNFG_cfg_sample_present_MASK (0xF0000U)
#define HDMI_TX_SMPL2PKT_CNFG_cfg_sample_present_SHIFT (16U)
/*! cfg_sample_present - Sample present bits if force them is active */
#define HDMI_TX_SMPL2PKT_CNFG_cfg_sample_present(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SMPL2PKT_CNFG_cfg_sample_present_SHIFT)) & HDMI_TX_SMPL2PKT_CNFG_cfg_sample_present_MASK)

#define HDMI_TX_SMPL2PKT_CNFG_cfg_sample_present_force_MASK (0x100000U)
#define HDMI_TX_SMPL2PKT_CNFG_cfg_sample_present_force_SHIFT (20U)
/*! cfg_sample_present_force - Force sample present bits */
#define HDMI_TX_SMPL2PKT_CNFG_cfg_sample_present_force(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SMPL2PKT_CNFG_cfg_sample_present_force_SHIFT)) & HDMI_TX_SMPL2PKT_CNFG_cfg_sample_present_force_MASK)

#define HDMI_TX_SMPL2PKT_CNFG_reserved_0_MASK    (0xFFE00000U)
#define HDMI_TX_SMPL2PKT_CNFG_reserved_0_SHIFT   (21U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SMPL2PKT_CNFG_reserved_0(x)      (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SMPL2PKT_CNFG_reserved_0_SHIFT)) & HDMI_TX_SMPL2PKT_CNFG_reserved_0_MASK)
/*! @} */

/*! @name FIFO_CNTL -  */
/*! @{ */

#define HDMI_TX_FIFO_CNTL_fifo_sw_rst_MASK       (0x1U)
#define HDMI_TX_FIFO_CNTL_fifo_sw_rst_SHIFT      (0U)
/*! fifo_sw_rst - Resets Fifo's write and read pointers. When FIFO configuration bits change this
 *    signal should be high (due to synchronization issues).
 */
#define HDMI_TX_FIFO_CNTL_fifo_sw_rst(x)         (((uint32_t)(((uint32_t)(x)) << HDMI_TX_FIFO_CNTL_fifo_sw_rst_SHIFT)) & HDMI_TX_FIFO_CNTL_fifo_sw_rst_MASK)

#define HDMI_TX_FIFO_CNTL_sync_wr_to_ch_zero_MASK (0x2U)
#define HDMI_TX_FIFO_CNTL_sync_wr_to_ch_zero_SHIFT (1U)
/*! sync_wr_to_ch_zero - When high the last channel index synchronizes the write addresses (to the next channel group) */
#define HDMI_TX_FIFO_CNTL_sync_wr_to_ch_zero(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_FIFO_CNTL_sync_wr_to_ch_zero_SHIFT)) & HDMI_TX_FIFO_CNTL_sync_wr_to_ch_zero_MASK)

#define HDMI_TX_FIFO_CNTL_fifo_dir_MASK          (0x4U)
#define HDMI_TX_FIFO_CNTL_fifo_dir_SHIFT         (2U)
/*! fifo_dir - 0 - smpl2pkt (inc_step=number of I2S ports), 1 - pkt2smpl (inc_step=num_ch_per_port) */
#define HDMI_TX_FIFO_CNTL_fifo_dir(x)            (((uint32_t)(((uint32_t)(x)) << HDMI_TX_FIFO_CNTL_fifo_dir_SHIFT)) & HDMI_TX_FIFO_CNTL_fifo_dir_MASK)

#define HDMI_TX_FIFO_CNTL_fifo_empty_calc_MASK   (0x8U)
#define HDMI_TX_FIFO_CNTL_fifo_empty_calc_SHIFT  (3U)
/*! fifo_empty_calc - 0- Empty is a function of read address. 1 - Empty is a function of BASE read address. */
#define HDMI_TX_FIFO_CNTL_fifo_empty_calc(x)     (((uint32_t)(((uint32_t)(x)) << HDMI_TX_FIFO_CNTL_fifo_empty_calc_SHIFT)) & HDMI_TX_FIFO_CNTL_fifo_empty_calc_MASK)

#define HDMI_TX_FIFO_CNTL_cfg_dis_port3_MASK     (0x10U)
#define HDMI_TX_FIFO_CNTL_cfg_dis_port3_SHIFT    (4U)
/*! cfg_dis_port3 - 0 - Normal Operation. 1 - I2S port 3 is disabled (user should ignore its
 *    outputs). This allows for 24-ch, 12-ch, 6-ch transfer.
 */
#define HDMI_TX_FIFO_CNTL_cfg_dis_port3(x)       (((uint32_t)(((uint32_t)(x)) << HDMI_TX_FIFO_CNTL_cfg_dis_port3_SHIFT)) & HDMI_TX_FIFO_CNTL_cfg_dis_port3_MASK)

#define HDMI_TX_FIFO_CNTL_reserved_0_MASK        (0xFFFFFFE0U)
#define HDMI_TX_FIFO_CNTL_reserved_0_SHIFT       (5U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_FIFO_CNTL_reserved_0(x)          (((uint32_t)(((uint32_t)(x)) << HDMI_TX_FIFO_CNTL_reserved_0_SHIFT)) & HDMI_TX_FIFO_CNTL_reserved_0_MASK)
/*! @} */

/*! @name FIFO_STTS -  */
/*! @{ */

#define HDMI_TX_FIFO_STTS_wfull_MASK             (0x1U)
#define HDMI_TX_FIFO_STTS_wfull_SHIFT            (0U)
/*! wfull - Indicates FIFO Full - indication comes with delay caused by Synchronization. */
#define HDMI_TX_FIFO_STTS_wfull(x)               (((uint32_t)(((uint32_t)(x)) << HDMI_TX_FIFO_STTS_wfull_SHIFT)) & HDMI_TX_FIFO_STTS_wfull_MASK)

#define HDMI_TX_FIFO_STTS_rempty_MASK            (0x2U)
#define HDMI_TX_FIFO_STTS_rempty_SHIFT           (1U)
/*! rempty - Indicates FIFO Empty - indication comes with delay caused by Synchronization. */
#define HDMI_TX_FIFO_STTS_rempty(x)              (((uint32_t)(((uint32_t)(x)) << HDMI_TX_FIFO_STTS_rempty_SHIFT)) & HDMI_TX_FIFO_STTS_rempty_MASK)

#define HDMI_TX_FIFO_STTS_overrun_MASK           (0x4U)
#define HDMI_TX_FIFO_STTS_overrun_SHIFT          (2U)
/*! overrun - Indicates a FIFO overrun error has occured - FIFO written to when it was full. */
#define HDMI_TX_FIFO_STTS_overrun(x)             (((uint32_t)(((uint32_t)(x)) << HDMI_TX_FIFO_STTS_overrun_SHIFT)) & HDMI_TX_FIFO_STTS_overrun_MASK)

#define HDMI_TX_FIFO_STTS_underrun_MASK          (0x8U)
#define HDMI_TX_FIFO_STTS_underrun_SHIFT         (3U)
/*! underrun - Indicates a FIFO underrun error has occured - FIFO read when it was empty. */
#define HDMI_TX_FIFO_STTS_underrun(x)            (((uint32_t)(((uint32_t)(x)) << HDMI_TX_FIFO_STTS_underrun_SHIFT)) & HDMI_TX_FIFO_STTS_underrun_MASK)

#define HDMI_TX_FIFO_STTS_reserved_0_MASK        (0xFFFFFFF0U)
#define HDMI_TX_FIFO_STTS_reserved_0_SHIFT       (4U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_FIFO_STTS_reserved_0(x)          (((uint32_t)(((uint32_t)(x)) << HDMI_TX_FIFO_STTS_reserved_0_SHIFT)) & HDMI_TX_FIFO_STTS_reserved_0_MASK)
/*! @} */

/*! @name SUB_PCKT_THRSH -  */
/*! @{ */

#define HDMI_TX_SUB_PCKT_THRSH_cfg_mem_fifo_thrsh1_MASK (0xFFU)
#define HDMI_TX_SUB_PCKT_THRSH_cfg_mem_fifo_thrsh1_SHIFT (0U)
/*! cfg_mem_fifo_thrsh1 - If number of samples in MEM FIFO is below Threshold 1: Each Packet will contain only 1 subpacket. */
#define HDMI_TX_SUB_PCKT_THRSH_cfg_mem_fifo_thrsh1(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SUB_PCKT_THRSH_cfg_mem_fifo_thrsh1_SHIFT)) & HDMI_TX_SUB_PCKT_THRSH_cfg_mem_fifo_thrsh1_MASK)

#define HDMI_TX_SUB_PCKT_THRSH_cfg_mem_fifo_thrsh2_MASK (0xFF00U)
#define HDMI_TX_SUB_PCKT_THRSH_cfg_mem_fifo_thrsh2_SHIFT (8U)
/*! cfg_mem_fifo_thrsh2 - If number of samples in MEM FIFO is below Threshold2: Each Packet will contain only 2 subpacket. */
#define HDMI_TX_SUB_PCKT_THRSH_cfg_mem_fifo_thrsh2(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SUB_PCKT_THRSH_cfg_mem_fifo_thrsh2_SHIFT)) & HDMI_TX_SUB_PCKT_THRSH_cfg_mem_fifo_thrsh2_MASK)

#define HDMI_TX_SUB_PCKT_THRSH_cfg_mem_fifo_thrsh3_MASK (0xFF0000U)
#define HDMI_TX_SUB_PCKT_THRSH_cfg_mem_fifo_thrsh3_SHIFT (16U)
/*! cfg_mem_fifo_thrsh3 - If number of samples in MEM FIFO is below Threshold 3: Each Packet will contain only 3 subpacket. */
#define HDMI_TX_SUB_PCKT_THRSH_cfg_mem_fifo_thrsh3(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SUB_PCKT_THRSH_cfg_mem_fifo_thrsh3_SHIFT)) & HDMI_TX_SUB_PCKT_THRSH_cfg_mem_fifo_thrsh3_MASK)

#define HDMI_TX_SUB_PCKT_THRSH_reserved_0_MASK   (0xFF000000U)
#define HDMI_TX_SUB_PCKT_THRSH_reserved_0_SHIFT  (24U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SUB_PCKT_THRSH_reserved_0(x)     (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SUB_PCKT_THRSH_reserved_0_SHIFT)) & HDMI_TX_SUB_PCKT_THRSH_reserved_0_MASK)
/*! @} */

/*! @name SOURCE_PIF_WR_ADDR -  */
/*! @{ */

#define HDMI_TX_SOURCE_PIF_WR_ADDR_wr_addr_MASK  (0xFU)
#define HDMI_TX_SOURCE_PIF_WR_ADDR_wr_addr_SHIFT (0U)
/*! wr_addr - 4 MSB of the packet memory address in which the data is written. */
#define HDMI_TX_SOURCE_PIF_WR_ADDR_wr_addr(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_WR_ADDR_wr_addr_SHIFT)) & HDMI_TX_SOURCE_PIF_WR_ADDR_wr_addr_MASK)

#define HDMI_TX_SOURCE_PIF_WR_ADDR_reserved_0_MASK (0xFFFFFFF0U)
#define HDMI_TX_SOURCE_PIF_WR_ADDR_reserved_0_SHIFT (4U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SOURCE_PIF_WR_ADDR_reserved_0(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_WR_ADDR_reserved_0_SHIFT)) & HDMI_TX_SOURCE_PIF_WR_ADDR_reserved_0_MASK)
/*! @} */

/*! @name SOURCE_PIF_WR_REQ -  */
/*! @{ */

#define HDMI_TX_SOURCE_PIF_WR_REQ_host_wr_MASK   (0x1U)
#define HDMI_TX_SOURCE_PIF_WR_REQ_host_wr_SHIFT  (0U)
/*! host_wr - Write request bit for the host write transaction. */
#define HDMI_TX_SOURCE_PIF_WR_REQ_host_wr(x)     (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_WR_REQ_host_wr_SHIFT)) & HDMI_TX_SOURCE_PIF_WR_REQ_host_wr_MASK)

#define HDMI_TX_SOURCE_PIF_WR_REQ_reserved_0_MASK (0xFFFFFFFEU)
#define HDMI_TX_SOURCE_PIF_WR_REQ_reserved_0_SHIFT (1U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SOURCE_PIF_WR_REQ_reserved_0(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_WR_REQ_reserved_0_SHIFT)) & HDMI_TX_SOURCE_PIF_WR_REQ_reserved_0_MASK)
/*! @} */

/*! @name SOURCE_PIF_RD_ADDR -  */
/*! @{ */

#define HDMI_TX_SOURCE_PIF_RD_ADDR_rd_addr_MASK  (0xFU)
#define HDMI_TX_SOURCE_PIF_RD_ADDR_rd_addr_SHIFT (0U)
/*! rd_addr - 4 MSB of the packet memory address from which the data is read. */
#define HDMI_TX_SOURCE_PIF_RD_ADDR_rd_addr(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_RD_ADDR_rd_addr_SHIFT)) & HDMI_TX_SOURCE_PIF_RD_ADDR_rd_addr_MASK)

#define HDMI_TX_SOURCE_PIF_RD_ADDR_reserved_0_MASK (0xFFFFFFF0U)
#define HDMI_TX_SOURCE_PIF_RD_ADDR_reserved_0_SHIFT (4U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SOURCE_PIF_RD_ADDR_reserved_0(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_RD_ADDR_reserved_0_SHIFT)) & HDMI_TX_SOURCE_PIF_RD_ADDR_reserved_0_MASK)
/*! @} */

/*! @name SOURCE_PIF_RD_REQ -  */
/*! @{ */

#define HDMI_TX_SOURCE_PIF_RD_REQ_host_rd_MASK   (0x1U)
#define HDMI_TX_SOURCE_PIF_RD_REQ_host_rd_SHIFT  (0U)
/*! host_rd - Read request bit for the host read transaction */
#define HDMI_TX_SOURCE_PIF_RD_REQ_host_rd(x)     (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_RD_REQ_host_rd_SHIFT)) & HDMI_TX_SOURCE_PIF_RD_REQ_host_rd_MASK)

#define HDMI_TX_SOURCE_PIF_RD_REQ_reserved_0_MASK (0xFFFFFFFEU)
#define HDMI_TX_SOURCE_PIF_RD_REQ_reserved_0_SHIFT (1U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SOURCE_PIF_RD_REQ_reserved_0(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_RD_REQ_reserved_0_SHIFT)) & HDMI_TX_SOURCE_PIF_RD_REQ_reserved_0_MASK)
/*! @} */

/*! @name SOURCE_PIF_DATA_WR -  */
/*! @{ */

#define HDMI_TX_SOURCE_PIF_DATA_WR_data_wr_MASK  (0xFFFFFFFFU)
#define HDMI_TX_SOURCE_PIF_DATA_WR_data_wr_SHIFT (0U)
/*! data_wr - The 32 bits of the data to be written to the packet memory. When written to this
 *    register fifo1_wr_enable will be asserted.
 */
#define HDMI_TX_SOURCE_PIF_DATA_WR_data_wr(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_DATA_WR_data_wr_SHIFT)) & HDMI_TX_SOURCE_PIF_DATA_WR_data_wr_MASK)
/*! @} */

/*! @name SOURCE_PIF_DATA_RD -  */
/*! @{ */

#define HDMI_TX_SOURCE_PIF_DATA_RD_fifo2_data_out_MASK (0xFFFFFFFFU)
#define HDMI_TX_SOURCE_PIF_DATA_RD_fifo2_data_out_SHIFT (0U)
/*! fifo2_data_out - The 32 bits of the data to be read from the packet memory. When read from this
 *    register fifo2_rd_enable will be asserted.
 */
#define HDMI_TX_SOURCE_PIF_DATA_RD_fifo2_data_out(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_DATA_RD_fifo2_data_out_SHIFT)) & HDMI_TX_SOURCE_PIF_DATA_RD_fifo2_data_out_MASK)
/*! @} */

/*! @name SOURCE_PIF_FIFO1_FLUSH -  */
/*! @{ */

#define HDMI_TX_SOURCE_PIF_FIFO1_FLUSH_fifo1_flush_MASK (0x1U)
#define HDMI_TX_SOURCE_PIF_FIFO1_FLUSH_fifo1_flush_SHIFT (0U)
/*! fifo1_flush - Fifo1 flush bit */
#define HDMI_TX_SOURCE_PIF_FIFO1_FLUSH_fifo1_flush(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_FIFO1_FLUSH_fifo1_flush_SHIFT)) & HDMI_TX_SOURCE_PIF_FIFO1_FLUSH_fifo1_flush_MASK)

#define HDMI_TX_SOURCE_PIF_FIFO1_FLUSH_reserved_0_MASK (0xFFFFFFFEU)
#define HDMI_TX_SOURCE_PIF_FIFO1_FLUSH_reserved_0_SHIFT (1U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SOURCE_PIF_FIFO1_FLUSH_reserved_0(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_FIFO1_FLUSH_reserved_0_SHIFT)) & HDMI_TX_SOURCE_PIF_FIFO1_FLUSH_reserved_0_MASK)
/*! @} */

/*! @name SOURCE_PIF_FIFO2_FLUSH -  */
/*! @{ */

#define HDMI_TX_SOURCE_PIF_FIFO2_FLUSH_fifo2_flush_MASK (0x1U)
#define HDMI_TX_SOURCE_PIF_FIFO2_FLUSH_fifo2_flush_SHIFT (0U)
/*! fifo2_flush - Fifo2 flush bit */
#define HDMI_TX_SOURCE_PIF_FIFO2_FLUSH_fifo2_flush(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_FIFO2_FLUSH_fifo2_flush_SHIFT)) & HDMI_TX_SOURCE_PIF_FIFO2_FLUSH_fifo2_flush_MASK)

#define HDMI_TX_SOURCE_PIF_FIFO2_FLUSH_reserved_0_MASK (0xFFFFFFFEU)
#define HDMI_TX_SOURCE_PIF_FIFO2_FLUSH_reserved_0_SHIFT (1U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SOURCE_PIF_FIFO2_FLUSH_reserved_0(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_FIFO2_FLUSH_reserved_0_SHIFT)) & HDMI_TX_SOURCE_PIF_FIFO2_FLUSH_reserved_0_MASK)
/*! @} */

/*! @name SOURCE_PIF_STATUS -  */
/*! @{ */

#define HDMI_TX_SOURCE_PIF_STATUS_source_pkt_mem_ctrl_fsm_state_MASK (0x3U)
#define HDMI_TX_SOURCE_PIF_STATUS_source_pkt_mem_ctrl_fsm_state_SHIFT (0U)
/*! source_pkt_mem_ctrl_fsm_state - State of the FSM that controls packet memory transactions. */
#define HDMI_TX_SOURCE_PIF_STATUS_source_pkt_mem_ctrl_fsm_state(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_STATUS_source_pkt_mem_ctrl_fsm_state_SHIFT)) & HDMI_TX_SOURCE_PIF_STATUS_source_pkt_mem_ctrl_fsm_state_MASK)

#define HDMI_TX_SOURCE_PIF_STATUS_fifo1_full_MASK (0x4U)
#define HDMI_TX_SOURCE_PIF_STATUS_fifo1_full_SHIFT (2U)
/*! fifo1_full - Fifo1 full indication */
#define HDMI_TX_SOURCE_PIF_STATUS_fifo1_full(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_STATUS_fifo1_full_SHIFT)) & HDMI_TX_SOURCE_PIF_STATUS_fifo1_full_MASK)

#define HDMI_TX_SOURCE_PIF_STATUS_fifo2_empty_MASK (0x8U)
#define HDMI_TX_SOURCE_PIF_STATUS_fifo2_empty_SHIFT (3U)
/*! fifo2_empty - Fifo2 empty indication */
#define HDMI_TX_SOURCE_PIF_STATUS_fifo2_empty(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_STATUS_fifo2_empty_SHIFT)) & HDMI_TX_SOURCE_PIF_STATUS_fifo2_empty_MASK)

#define HDMI_TX_SOURCE_PIF_STATUS_reserved_0_MASK (0xFFFFFFF0U)
#define HDMI_TX_SOURCE_PIF_STATUS_reserved_0_SHIFT (4U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SOURCE_PIF_STATUS_reserved_0(x)  (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_STATUS_reserved_0_SHIFT)) & HDMI_TX_SOURCE_PIF_STATUS_reserved_0_MASK)
/*! @} */

/*! @name SOURCE_PIF_INTERRUPT_SOURCE -  */
/*! @{ */

#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_host_wr_done_int_MASK (0x1U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_host_wr_done_int_SHIFT (0U)
/*! host_wr_done_int - Indication that the host write transaction finished. */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_host_wr_done_int(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_host_wr_done_int_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_host_wr_done_int_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_host_rd_done_int_MASK (0x2U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_host_rd_done_int_SHIFT (1U)
/*! host_rd_done_int - Indication that the host read transaction finished. */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_host_rd_done_int(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_host_rd_done_int_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_host_rd_done_int_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_nonvalid_type_requested_int_MASK (0x4U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_nonvalid_type_requested_int_SHIFT (2U)
/*! nonvalid_type_requested_int - Indication that nonvalid type of packet is requested by the packet interface. */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_nonvalid_type_requested_int(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_nonvalid_type_requested_int_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_nonvalid_type_requested_int_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_pslverr_MASK (0x8U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_pslverr_SHIFT (3U)
/*! pslverr - APB slave error interrupt */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_pslverr(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_pslverr_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_pslverr_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_alloc_wr_done_MASK (0x10U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_alloc_wr_done_SHIFT (4U)
/*! alloc_wr_done - Successful write to the allocation table. */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_alloc_wr_done(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_alloc_wr_done_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_alloc_wr_done_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_alloc_wr_error_MASK (0x20U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_alloc_wr_error_SHIFT (5U)
/*! alloc_wr_error - Error happened, invalid write to the allocation table. */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_alloc_wr_error(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_alloc_wr_error_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_alloc_wr_error_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo1_overflow_MASK (0x40U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo1_overflow_SHIFT (6U)
/*! fifo1_overflow - Fifo1 overflow indication */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo1_overflow(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo1_overflow_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo1_overflow_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo1_underflow_MASK (0x80U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo1_underflow_SHIFT (7U)
/*! fifo1_underflow - Fifo1 underflow indication */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo1_underflow(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo1_underflow_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo1_underflow_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo2_overflow_MASK (0x100U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo2_overflow_SHIFT (8U)
/*! fifo2_overflow - Fifo2 overflow indication */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo2_overflow(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo2_overflow_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo2_overflow_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo2_underflow_MASK (0x200U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo2_underflow_SHIFT (9U)
/*! fifo2_underflow - Fifo2 underflow indication */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo2_underflow(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo2_underflow_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_fifo2_underflow_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_reserved_0_MASK (0xFFFFFC00U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_reserved_0_SHIFT (10U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_reserved_0(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_reserved_0_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_SOURCE_reserved_0_MASK)
/*! @} */

/*! @name SOURCE_PIF_INTERRUPT_MASK -  */
/*! @{ */

#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_host_wr_done_int_mask_MASK (0x1U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_host_wr_done_int_mask_SHIFT (0U)
/*! host_wr_done_int_mask - Masks the host_wr_done_int interrupt */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_host_wr_done_int_mask(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_host_wr_done_int_mask_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_host_wr_done_int_mask_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_host_rd_done_int_mask_MASK (0x2U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_host_rd_done_int_mask_SHIFT (1U)
/*! host_rd_done_int_mask - Masks the host_rd_done_int interrupt */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_host_rd_done_int_mask(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_host_rd_done_int_mask_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_host_rd_done_int_mask_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_nonvalid_type_requested_int_mask_MASK (0x4U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_nonvalid_type_requested_int_mask_SHIFT (2U)
/*! nonvalid_type_requested_int_mask - Masks the nonvalid_type_requested_int interrupt */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_nonvalid_type_requested_int_mask(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_nonvalid_type_requested_int_mask_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_nonvalid_type_requested_int_mask_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_pslverr_mask_MASK (0x8U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_pslverr_mask_SHIFT (3U)
/*! pslverr_mask - Masks the pslverr interrupt */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_pslverr_mask(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_pslverr_mask_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_pslverr_mask_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_alloc_wr_done_mask_MASK (0x10U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_alloc_wr_done_mask_SHIFT (4U)
/*! alloc_wr_done_mask - Masks the alloc_wr_done interrupt */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_alloc_wr_done_mask(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_alloc_wr_done_mask_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_alloc_wr_done_mask_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_alloc_wr_error_mask_MASK (0x20U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_alloc_wr_error_mask_SHIFT (5U)
/*! alloc_wr_error_mask - Masks the alloc_wr_error interrupt */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_alloc_wr_error_mask(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_alloc_wr_error_mask_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_alloc_wr_error_mask_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo1_overflow_mask_MASK (0x40U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo1_overflow_mask_SHIFT (6U)
/*! fifo1_overflow_mask - Masks the fifo1_overflow interrupt */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo1_overflow_mask(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo1_overflow_mask_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo1_overflow_mask_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo1_underflow_mask_MASK (0x80U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo1_underflow_mask_SHIFT (7U)
/*! fifo1_underflow_mask - Masks the fifo1_underflow interrupt */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo1_underflow_mask(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo1_underflow_mask_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo1_underflow_mask_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo2_overflow_mask_MASK (0x100U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo2_overflow_mask_SHIFT (8U)
/*! fifo2_overflow_mask - Masks the fifo2_overflow interrupt */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo2_overflow_mask(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo2_overflow_mask_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo2_overflow_mask_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo2_underflow_mask_MASK (0x200U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo2_underflow_mask_SHIFT (9U)
/*! fifo2_underflow_mask - Masks the fifo2_underflow interrupt */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo2_underflow_mask(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo2_underflow_mask_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_fifo2_underflow_mask_MASK)

#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_reserved_0_MASK (0xFFFFFC00U)
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_reserved_0_SHIFT (10U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_reserved_0(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_reserved_0_SHIFT)) & HDMI_TX_SOURCE_PIF_INTERRUPT_MASK_reserved_0_MASK)
/*! @} */

/*! @name SOURCE_PIF_PKT_ALLOC_REG -  */
/*! @{ */

#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_pkt_alloc_address_MASK (0xFU)
#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_pkt_alloc_address_SHIFT (0U)
/*! pkt_alloc_address - Address of the register in the source allocation table */
#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_pkt_alloc_address(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_pkt_alloc_address_SHIFT)) & HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_pkt_alloc_address_MASK)

#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_reserved_0_MASK (0xF0U)
#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_reserved_0_SHIFT (4U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_reserved_0(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_reserved_0_SHIFT)) & HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_reserved_0_MASK)

#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_packet_type_MASK (0xFF00U)
#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_packet_type_SHIFT (8U)
/*! packet_type - Type of packet */
#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_packet_type(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_packet_type_SHIFT)) & HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_packet_type_MASK)

#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_type_valid_MASK (0x10000U)
#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_type_valid_SHIFT (16U)
/*! type_valid - 1 for valid, 0 for nonvalid */
#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_type_valid(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_type_valid_SHIFT)) & HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_type_valid_MASK)

#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_active_idle_type_MASK (0x20000U)
#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_active_idle_type_SHIFT (17U)
/*! active_idle_type - active_idle_type */
#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_active_idle_type(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_active_idle_type_SHIFT)) & HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_active_idle_type_MASK)

#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_reserved_1_MASK (0xFFFC0000U)
#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_reserved_1_SHIFT (18U)
/*! reserved_1 - reserved_1 */
#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_reserved_1(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_reserved_1_SHIFT)) & HDMI_TX_SOURCE_PIF_PKT_ALLOC_REG_reserved_1_MASK)
/*! @} */

/*! @name SOURCE_PIF_PKT_ALLOC_WR_EN -  */
/*! @{ */

#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_WR_EN_pkt_alloc_wr_en_MASK (0x1U)
#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_WR_EN_pkt_alloc_wr_en_SHIFT (0U)
/*! pkt_alloc_wr_en - Enable bit for writing to the allocation table */
#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_WR_EN_pkt_alloc_wr_en(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_PKT_ALLOC_WR_EN_pkt_alloc_wr_en_SHIFT)) & HDMI_TX_SOURCE_PIF_PKT_ALLOC_WR_EN_pkt_alloc_wr_en_MASK)

#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_WR_EN_reserved_0_MASK (0xFFFFFFFEU)
#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_WR_EN_reserved_0_SHIFT (1U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SOURCE_PIF_PKT_ALLOC_WR_EN_reserved_0(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_PKT_ALLOC_WR_EN_reserved_0_SHIFT)) & HDMI_TX_SOURCE_PIF_PKT_ALLOC_WR_EN_reserved_0_MASK)
/*! @} */

/*! @name SOURCE_PIF_SW_RESET -  */
/*! @{ */

#define HDMI_TX_SOURCE_PIF_SW_RESET_sw_rst_MASK  (0x1U)
#define HDMI_TX_SOURCE_PIF_SW_RESET_sw_rst_SHIFT (0U)
/*! sw_rst - Software reset */
#define HDMI_TX_SOURCE_PIF_SW_RESET_sw_rst(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_SW_RESET_sw_rst_SHIFT)) & HDMI_TX_SOURCE_PIF_SW_RESET_sw_rst_MASK)

#define HDMI_TX_SOURCE_PIF_SW_RESET_reserved_0_MASK (0xFFFFFFFEU)
#define HDMI_TX_SOURCE_PIF_SW_RESET_reserved_0_SHIFT (1U)
/*! reserved_0 - reserved_0 */
#define HDMI_TX_SOURCE_PIF_SW_RESET_reserved_0(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_SOURCE_PIF_SW_RESET_reserved_0_SHIFT)) & HDMI_TX_SOURCE_PIF_SW_RESET_reserved_0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group HDMI_TX_Register_Masks */


/*!
 * @}
 */ /* end of group HDMI_TX_Peripheral_Access_Layer */


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


#endif  /* PERI_HDMI_TX_H_ */

