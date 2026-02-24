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
**         CMSIS Peripheral Access Layer for VPU_VPU_ENC
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
 * @file PERI_VPU_VPU_ENC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VPU_VPU_ENC
 *
 * CMSIS Peripheral Access Layer for VPU_VPU_ENC
 */

#if !defined(PERI_VPU_VPU_ENC_H_)
#define PERI_VPU_VPU_ENC_H_                      /**< Symbol preventing repeated inclusion */

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
   -- VPU_VPU_ENC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_VPU_ENC_Peripheral_Access_Layer VPU_VPU_ENC Peripheral Access Layer
 * @{
 */

/** VPU_VPU_ENC - Register Layout Typedef */
typedef struct {
  __O  uint32_t BIT_CODE_RUN;                      /**< BIT_CODE_RUN, offset: 0x0 */
  __O  uint32_t BIT_CODE_DOWN;                     /**< BIT_CODE_DOWN, offset: 0x4 */
  __O  uint32_t BIT_INT_REQ;                       /**< BIT_INT_REQ, offset: 0x8 */
  __O  uint32_t BIT_INT_CLEAR;                     /**< BIT_INT_CLEAR, offset: 0xC */
  __I  uint32_t BIT_INT_STS;                       /**< BIT_INT_STS, offset: 0x10 */
  __O  uint32_t BIT_CODE_RESET;                    /**< BIT_CODE_RESET, offset: 0x14 */
  __I  uint32_t BIT_CUR_PC;                        /**< BIT_CUR_PC, offset: 0x18 */
       uint8_t RESERVED_0[4];
  __IO uint32_t BIT_CODEC_BUSY;                    /**< BIT_CODEC_BUSY, offset: 0x20 */
  __O  uint32_t BIT_SW_RESET;                      /**< BIT_SW_RESET, offset: 0x24 */
       uint8_t RESERVED_1[12];
  __I  uint32_t BIT_SW_RESET_STATUS;               /**< BIT_SW_RESET_STATUS, offset: 0x34 */
       uint8_t RESERVED_2[8];
  __IO uint32_t BIT_BIT_STOP_CMD;                  /**< STOP_CMD, offset: 0x40 */
  __IO uint32_t BIT_RESUME_CMD;                    /**< RESUME_CMD, offset: 0x44 */
  __IO uint32_t BIT_STOP_MB_STS;                   /**< STOP_MB_STS, offset: 0x48 */
  __IO uint32_t BIT_STOP_MB_EN;                    /**< STOP_MB_EN, offset: 0x4C */
  __IO uint32_t BIT_STOP_MB_ADDR;                  /**< STOP_MB_ADDR, offset: 0x50 */
  __IO uint32_t BIT_FRAME_DONE_CTRL;               /**< FRAME_DONE_CTRL, offset: 0x54 */
  __IO uint32_t BIT_AXI_HIGH_ADDR;                 /**< BIT_AXI_HIGH_ADDR, offset: 0x58 */
       uint8_t RESERVED_3[164];
  __IO uint32_t BIT_CODE_BUF_ADDR;                 /**< BIT_CODE_BUF_ADDR, offset: 0x100 */
  __IO uint32_t BIT_WORK_BUF_ADDR;                 /**< BIT_WORK_BUF_ADDR, offset: 0x104 */
  __IO uint32_t BIT_PARA_BUF_ADDR;                 /**< BIT_PARA_BUF_ADDR, offset: 0x108 */
  __IO uint32_t BIT_BIT_STREAM_CTRL;               /**< BIT_BIT_STREAM_CTRL, offset: 0x10C */
  __IO uint32_t BIT_FRAME_MEM_CTRL;                /**< BIT_FRAME_MEM_CTRL, offset: 0x110 */
  __IO uint32_t BIT_BIT_STREAM_PARAM;              /**< BIT_BIT_STREAM_PARAM, offset: 0x114 */
  __IO uint32_t BIT_TEMP_BUF_ADDR;                 /**< BIT_TEMP_BUF_ADDR, offset: 0x118 */
       uint8_t RESERVED_4[4];
  __IO uint32_t BIT_RD_PTR;                        /**< BIT_RD_PTR, offset: 0x120 */
  __IO uint32_t BIT_WR_PTR;                        /**< BIT_WR_PTR, offset: 0x124 */
  __IO uint32_t BIT_RESET_CTRL;                    /**< BIT_RESET_CTRL, offset: 0x128 */
       uint8_t RESERVED_5[20];
  __IO uint32_t BIT_AXI_SRAM_USE;                  /**< BIT_AXI_SRAM_USE, offset: 0x140 */
  __IO uint32_t BIT_BYTE_POS_FRAME_START;          /**< BIT_BYTE_POS_FRAME_START, offset: 0x144 */
  __IO uint32_t BIT_BYTE_POS_FRAME_END;            /**< BIT_BYTE_POS_FRAME_END, offset: 0x148 */
       uint8_t RESERVED_6[4];
  __IO uint32_t BIT_FRM_DIS_FLG;                   /**< BIT_FRM_DIS_FLG, offset: 0x150 */
       uint8_t RESERVED_7[12];
  __IO uint32_t BIT_BUSY_FLAG;                     /**< BIT_BUSY_FLAG, offset: 0x160 */
  __IO uint32_t BIT_RUN_COMMAND;                   /**< BIT_RUN_COMMAND, offset: 0x164 */
  __IO uint32_t BIT_RUN_INDEX;                     /**< BIT_RUN_INDEX, offset: 0x168 */
  __IO uint32_t BIT_RUN_COD_STD;                   /**< BIT_RUN_COD_STD, offset: 0x16C */
  __IO uint32_t BIT_INT_ENABLE;                    /**< BIT_INT_ENABLE, offset: 0x170 */
  __IO uint32_t BIT_INT_REASON;                    /**< BIT_INT_REASON, offset: 0x174 */
  __IO uint32_t BIT_RUN_AUX_STD;                   /**< BIT_RUN_AUX_STD, offset: 0x178 */
       uint8_t RESERVED_8[4];
  union {                                          /* offset: 0x180 */
    __IO uint32_t CMD_ENC_HEADER_CODE;               /**< CMD_ENC_HEADER_CODE, offset: 0x180 */
    __IO uint32_t CMD_ENC_PARAM_CHANGE_ENABLE;       /**< CMD_ENC_PARAM_CHANGE_ENABLE, offset: 0x180 */
    __IO uint32_t CMD_ENC_PARA_SET_TYPE;             /**< CMD_ENC_PARA_SET_TYPE, offset: 0x180 */
    __IO uint32_t CMD_ENC_PIC_SRC_INDEX;             /**< CMD_ENC_PIC_SRC_INDEX, offset: 0x180 */
    __IO uint32_t CMD_ENC_ROI_INFO;                  /**< CMD_ENC_ROI_INFO, offset: 0x180 */
    __IO uint32_t CMD_ENC_SEQ_BB_START;              /**< CMD_ENC_SEQ_BB_START, offset: 0x180 */
    __IO uint32_t CMD_SET_FRAME_BUF_NUM;             /**< CMD_SET_FRAME_BUF_NUM, offset: 0x180 */
  };
  union {                                          /* offset: 0x184 */
    __IO uint32_t CMD_ENC_HEADER_BB_START;           /**< CMD_ENC_HEADER_BB_START, offset: 0x184 */
    __IO uint32_t CMD_ENC_PARAM_CHANGE_GOP_NUM;      /**< CMD_ENC_PARAM_CHANGE_GOP_NUM, offset: 0x184 */
    __IO uint32_t CMD_ENC_PIC_SRC_STRIDE;            /**< CMD_ENC_PIC_SRC_STRIDE, offset: 0x184 */
    __IO uint32_t CMD_ENC_ROI_QP_MAP_ADDR;           /**< CMD_ENC_ROI_QP_MAP_ADDR, offset: 0x184 */
    __IO uint32_t CMD_ENC_SEQ_BB_SIZE;               /**< CMD_ENC_SEQ_BB_SIZE, offset: 0x184 */
    __IO uint32_t CMD_SET_FRAME_BUF_STRIDE;          /**< CMD_SET_FRAME_BUF_STRIDE, offset: 0x184 */
  };
  union {                                          /* offset: 0x188 */
    __IO uint32_t CMD_ENC_HEADER_BB_SIZE;            /**< CMD_ENC_HEADER_BB_SIZE, offset: 0x188 */
    __IO uint32_t CMD_ENC_PARAM_CHANGE_INTRA_QP;     /**< CMD_ENC_PARAM_CHANGE_INTRA_QP, offset: 0x188 */
    __IO uint32_t CMD_ENC_SEQ_OPTION;                /**< CMD_ENC_SEQ_OPTION, offset: 0x188 */
    __IO uint32_t CMD_SET_FRAME_SLICE_BB_START;      /**< CMD_SET_FRAME_SLICE_BB_START, offset: 0x188 */
  };
  union {                                          /* offset: 0x18C */
    __IO uint32_t CMD_ENC_HEADER_FRAME_CROP_H;       /**< CMD_ENC_HEADER_FRAME_CROP_H, offset: 0x18C */
    __IO uint32_t CMD_ENC_PARAM_CHANGE_BITRATE;      /**< CMD_ENC_PARAM_CHANGE_BITRATE, offset: 0x18C */
    __IO uint32_t CMD_ENC_PARA_FRAME_CROP_H;         /**< CMD_ENC_PARA_FRAME_CROP_H, offset: 0x18C */
    __IO uint32_t CMD_ENC_PIC_QS;                    /**< CMD_ENC_PIC_QS, offset: 0x18C */
    __IO uint32_t CMD_ENC_SEQ_COD_STD;               /**< CMD_ENC_SEQ_COD_STD, offset: 0x18C */
    __IO uint32_t CMD_SET_FRAME_SLICE_BB_SIZE;       /**< CMD_SET_FRAME_SLICE_BB_SIZE, offset: 0x18C */
  };
  union {                                          /* offset: 0x190 */
    __IO uint32_t CMD_ENC_HEADER_FRAME_CROP_V;       /**< CMD_ENC_HEADER_FRAME_CROP_V, offset: 0x190 */
    __IO uint32_t CMD_ENC_PARAM_CHANGE_F_RATE;       /**< CMD_ENC_PARAM_CHANGE_F_RATE, offset: 0x190 */
    __IO uint32_t CMD_ENC_PARA_FRAME_CROP_V;         /**< CMD_ENC_PARA_FRAME_CROP_V, offset: 0x190 */
    __IO uint32_t CMD_ENC_PIC_ROT_MODE;              /**< CMD_ENC_PIC_ROT_MODE, offset: 0x190 */
    __IO uint32_t CMD_ENC_SEQ_SRC_SIZE;              /**< CMD_ENC_SEQ_SRC_SIZE, offset: 0x190 */
    __IO uint32_t CMD_SET_FRAME_AXI_BIT_ADDR;        /**< CMD_SET_FRAME_AXI_BIT_ADDR, offset: 0x190 */
  };
  union {                                          /* offset: 0x194 */
    __IO uint32_t CMD_ENC_HEADER_CABAC_MODE;         /**< CMD_ENC_HEADER_CABAC_MODE, offset: 0x194 */
    __IO uint32_t CMD_ENC_PARAM_CHANGE_INTRA_REFRESH;   /**< CMD_ENC_PARAM_CHANGE_INTRA_REFRESH, offset: 0x194 */
    __IO uint32_t CMD_ENC_PARA_SET_CABAC_MODE;       /**< CMD_ENC_PARA_SET_CABAC_MODE, offset: 0x194 */
    __IO uint32_t CMD_ENC_PIC_OPTION;                /**< CMD_ENC_PIC_OPTION, offset: 0x194 */
    __IO uint32_t CMD_ENC_SEQ_SRC_F_RATE;            /**< CMD_ENC_SEQ_SRC_F_RATE, offset: 0x194 */
    __IO uint32_t CMD_SET_FRAME_AXI_IPACDC_ADDR;     /**< CMD_SET_FRAME_AXI_IPACDC_ADDR, offset: 0x194 */
  };
  union {                                          /* offset: 0x198 */
    __IO uint32_t CMD_ENC_HEADER_CABAC_INIT_IDC;     /**< CMD_ENC_HEADER_CABAC_INIT_IDC, offset: 0x198 */
    __IO uint32_t CMD_ENC_PARAM_CHANGE_SLICE_MODE;   /**< CMD_ENC_PARAM_CHANGE_SLICE_MODE, offset: 0x198 */
    __IO uint32_t CMD_ENC_PARA_SET_CABAC_INIT_IDC;   /**< CMD_ENC_PARA_SET_CABAC_INIT_IDC, offset: 0x198 */
    __IO uint32_t CMD_ENC_PIC_BB_START;              /**< CMD_ENC_PIC_BB_START, offset: 0x198 */
    __IO uint32_t CMD_ENC_SEQ_MP4_PARA;              /**< CMD_ENC_SEQ_MP4_PARA, offset: 0x198 */
    __IO uint32_t CMD_SET_FRAME_AXI_DBKY_ADDR;       /**< CMD_SET_FRAME_AXI_DBKY_ADDR, offset: 0x198 */
  };
  union {                                          /* offset: 0x19C */
    __IO uint32_t CMD_ENC_HEADER_TRANSFORM_8X8;      /**< CMD_ENC_HEADER_TRANSFORM_8X8, offset: 0x19C */
    __IO uint32_t CMD_ENC_PARAM_CHANGE_HEC_MODE;     /**< CMD_ENC_PARAM_CHANGE_HEC_MODE, offset: 0x19C */
    __IO uint32_t CMD_ENC_PARA_SET_TRANSFORM_8X8;    /**< CMD_ENC_PARA_SET_TRANSFORM_8X8, offset: 0x19C */
    __IO uint32_t CMD_ENC_PIC_BB_SIZE;               /**< CMD_ENC_PIC_BB_SIZE, offset: 0x19C */
    __IO uint32_t CMD_ENC_SEQ_263_PARA;              /**< CMD_ENC_SEQ_263_PARA, offset: 0x19C */
    __IO uint32_t CMD_SET_FRAME_AXI_DBKC_ADDR;       /**< CMD_SET_FRAME_AXI_DBKC_ADDR, offset: 0x19C */
  };
  union {                                          /* offset: 0x1A0 */
    __IO uint32_t CMD_ENC_HEADER_CHROMA_FORMAT;      /**< CMD_ENC_HEADER_CHROMA_FORMAT, offset: 0x1A0 */
    __IO uint32_t CMD_ENC_PARAM_CHANGE_CABAC_MODE;   /**< CMD_ENC_PARAM_CHANGE_CABAC_MODE, offset: 0x1A0 */
    __IO uint32_t CMD_ENC_PARA_SET_CHROMA_FORMAT;    /**< CMD_ENC_PARA_SET_CHROMA_FORMAT, offset: 0x1A0 */
    __IO uint32_t CMD_ENC_PIC_PARA_BASE_ADDR;        /**< CMD_ENC_PIC_PARA_BASE_ADDR, offset: 0x1A0 */
    __IO uint32_t CMD_ENC_SEQ_264_PARA;              /**< CMD_ENC_SEQ_264_PARA, offset: 0x1A0 */
  };
  union {                                          /* offset: 0x1A4 */
    __IO uint32_t CMD_ENC_HEADER_FIELD_FLAG;         /**< CMD_ENC_HEADER_FIELD_FLAG, offset: 0x1A4 */
    __IO uint32_t CMD_ENC_PARA_SET_FIELD_FLAG;       /**< CMD_ENC_PARA_SET_FIELD_FLAG, offset: 0x1A4 */
    __IO uint32_t CMD_ENC_SEQ_SLICE_MODE;            /**< CMD_ENC_SEQ_SLICE_MODE, offset: 0x1A4 */
  };
  union {                                          /* offset: 0x1A8 */
    __IO uint32_t CMD_ENC_HEADER_PROFILE;            /**< CMD_ENC_HEADER_PROFILE, offset: 0x1A8 */
    __IO uint32_t CMD_ENC_PARA_SET_PROFILE;          /**< CMD_ENC_PARA_SET_PROFILE, offset: 0x1A8 */
    __IO uint32_t CMD_ENC_PIC_SRC_ADDR_Y;            /**< CMD_ENC_PIC_SRC_ADDR_Y, offset: 0x1A8 */
    __IO uint32_t CMD_ENC_SEQ_GOP_NUM;               /**< CMD_ENC_SEQ_GOP_NUM, offset: 0x1A8 */
    __IO uint32_t CMD_SET_FRAME_CACHE_SIZE;          /**< CMD_SET_FRAME_CACHE_SIZE, offset: 0x1A8 */
  };
  union {                                          /* offset: 0x1AC */
    __IO uint32_t CMD_ENC_HEADER_SCALING_LIST;       /**< CMD_ENC_HEADER_SCALING_LIST, offset: 0x1AC */
    __IO uint32_t CMD_ENC_PARA_SET_SCALING_LIST;     /**< CMD_ENC_PARA_SET_SCALING_LIST, offset: 0x1AC */
    __IO uint32_t CMD_ENC_PIC_SRC_ADDR_CB;           /**< CMD_ENC_PIC_SRC_ADDR_CB, offset: 0x1AC */
    __IO uint32_t CMD_ENC_SEQ_RC_PARA;               /**< CMD_ENC_SEQ_RC_PARA, offset: 0x1AC */
    __IO uint32_t CMD_SET_FRAME_CACHE_CONFIG;        /**< CMD_SET_FRAME_CACHE_CONFIG, offset: 0x1AC */
  };
  union {                                          /* offset: 0x1B0 */
    __IO uint32_t CMD_ENC_HEADER_QMAT_BASE;          /**< CMD_ENC_HEADER_QMAT_BASE, offset: 0x1B0 */
    __IO uint32_t CMD_ENC_PARA_SET_QMAT_BASE;        /**< CMD_ENC_PARA_SET_QMAT_BASE, offset: 0x1B0 */
    __IO uint32_t CMD_ENC_PIC_SRC_ADDR_CR;           /**< CMD_ENC_PIC_SRC_ADDR_CR, offset: 0x1B0 */
    __IO uint32_t CMD_ENC_SEQ_RC_BUF_SIZE;           /**< CMD_ENC_SEQ_RC_BUF_SIZE, offset: 0x1B0 */
    __IO uint32_t CMD_SET_FRAME_MB_BUF_BASE;         /**< CMD_SET_FRAME_MB_BUF_BASE, offset: 0x1B0 */
  };
  union {                                          /* offset: 0x1B4 */
    __IO uint32_t CMD_ENC_PARAM_CHANGE_PPS_ID;       /**< CMD_ENC_PARAM_CHANGE_PPS_ID, offset: 0x1B4 */
    __IO uint32_t CMD_ENC_SEQ_INTRA_REFRESH;         /**< CMD_ENC_SEQ_INTRA_REFRESH, offset: 0x1B4 */
  };
  __IO uint32_t CMD_SET_FRAME_MAX_DEC_SIZE;        /**< CMD_SET_FRAME_MAX_DEC_SIZE, offset: 0x1B8 */
  union {                                          /* offset: 0x1BC */
    __IO uint32_t CMD_ENC_PARAM_CHANGE_MIN_MAX_QP;   /**< CMD_ENC_PARAM_CHANGE_MIN_MAX_QP, offset: 0x1BC */
    __IO uint32_t CMD_SET_FRAME_DELAY;               /**< CMD_SET_FRAME_DELAY, offset: 0x1BC */
  };
  union {                                          /* offset: 0x1C0 */
    __I  uint32_t RET_ENC_HEADER_SUCCESS;            /**< RET_ENC_HEADER_SUCCESS, offset: 0x1C0 */
    __I  uint32_t RET_ENC_PAPAM_CHANGE_SUCCESS;      /**< RET_ENC_PAPAM_CHANGE_SUCCESS, offset: 0x1C0 */
    __I  uint32_t RET_ENC_PARA_SET_SIZE;             /**< RET_ENC_PARA_SET_SIZE, offset: 0x1C0 */
    __I  uint32_t RET_ENC_PIC_FRAME_NUM;             /**< RET_ENC_PIC_FRAME_NUM, offset: 0x1C0 */
    __I  uint32_t RET_ENC_SEQ_END_SUCCESS;           /**< RET_ENC_SEQ_END_SUCCESS, offset: 0x1C0 */
    __I  uint32_t RET_FW_VER_NUM;                    /**< RET_FW_VER_NUM, offset: 0x1C0 */
    __I  uint32_t RET_SET_FRAME_SUCCESS;             /**< RET_SET_FRAME_SUCCESS, offset: 0x1C0 */
  };
  union {                                          /* offset: 0x1C4 */
    __IO uint32_t CMD_ENC_SEQ_INTRA_QP;              /**< CMD_ENC_SEQ_INTRA_QP, offset: 0x1C4 */
    __I  uint32_t RET_ENC_PARA_SET_SUCCESS;          /**< RET_ENC_PARA_SET_SUCCESS, offset: 0x1C4 */
    __I  uint32_t RET_ENC_PIC_TYPE;                  /**< RET_ENC_PIC_TYPE, offset: 0x1C4 */
    __I  uint32_t RET_FW_CODE_REV;                   /**< RET_FW_CODE_REV, offset: 0x1C4 */
  };
  union {                                          /* offset: 0x1C8 */
    __IO uint32_t CMD_ENC_SEQ_RC_QP_MAX;             /**< CMD_ENC_SEQ_RC_QP_MAX, offset: 0x1C8 */
    __I  uint32_t RET_ENC_PIC_FRAME_IDX;             /**< RET_ENC_PIC_FRAME_IDX, offset: 0x1C8 */
  };
  union {                                          /* offset: 0x1CC */
    __IO uint32_t CMD_ENC_SEQ_RC_GAMMA;              /**< CMD_ENC_SEQ_RC_GAMMA, offset: 0x1CC */
    __I  uint32_t RET_ENC_PIC_SLICE_NUM;             /**< RET_ENC_PIC_SLICE_NUM, offset: 0x1CC */
  };
  union {                                          /* offset: 0x1D0 */
    __IO uint32_t CMD_ENC_SEQ_RC_INTERVAL_MODE;      /**< CMD_ENC_SEQ_RC_INTERVAL_MODE, offset: 0x1D0 */
    __I  uint32_t RET_ENC_PIC_FLAG;                  /**< RET_ENC_PIC_FLAG, offset: 0x1D0 */
  };
  __IO uint32_t CMD_ENC_SEQ_INTRA_WEIGHT;          /**< CMD_ENC_SEQ_INTRA_WEIGHT, offset: 0x1D4 */
  union {                                          /* offset: 0x1D8 */
    __IO uint32_t CMD_ENC_SEQ_ME_OPTION;             /**< CMD_ENC_SEQ_ME_OPTION, offset: 0x1D8 */
    __I  uint32_t RET_ENC_PIC_SUCCESS;               /**< RET_ENC_PIC_SUCCESS, offset: 0x1D8 */
    __I  uint32_t RET_ENC_ROI_SUCCESS;               /**< RET_ENC_ROI_SUCCESS, offset: 0x1D8 */
  };
  union {                                          /* offset: 0x1DC */
    __IO uint32_t CMD_ENC_SEQ_RC_PARA2;              /**< CMD_ENC_SEQ_RC_PARA2, offset: 0x1DC */
    __I  uint32_t RET_ENC_PIC_INTRA_MB_NUM;          /**< RET_ENC_PIC_INTRA_MB_NUM, offset: 0x1DC */
  };
  union {                                          /* offset: 0x1E0 */
    __IO uint32_t CMD_ENC_SEQ_QP_RANGE_SET;          /**< CMD_ENC_SEQ_QP_RANGE_SET, offset: 0x1E0 */
    __I  uint32_t RET_ENC_PIC_SKIPPED_MB_NUM;        /**< RET_ENC_PIC_SKIPPED_MB_NUM, offset: 0x1E0 */
  };
  __I  uint32_t RET_ENC_PIC_SUM_QP;                /**< RET_ENC_PIC_SUM_QP, offset: 0x1E4 */
  __IO uint32_t CMD_ENC_PIC_SRC_BOTTOM_Y;          /**< CMD_ENC_PIC_SRC_BOTTOM_Y, offset: 0x1E8 */
  __IO uint32_t CMD_ENC_PIC_SRC_BOTTOM_CB;         /**< CMD_ENC_PIC_SRC_BOTTOM_CB, offset: 0x1EC */
  union {                                          /* offset: 0x1F0 */
    __IO uint32_t CMD_ENC_PIC_SRC_BOTTOM_CR;         /**< CMD_ENC_PIC_SRC_BOTTOM_CR, offset: 0x1F0 */
    __IO uint32_t CMD_ENC_SEQ_RC_MAX_INTRA_SIZE;     /**< CMD_ENC_SEQ_RC_MAX_INTRA_SIZE, offset: 0x1F0 */
  };
  __IO uint32_t CMD_ENC_SEQ_QP_DELTA_QP;           /**< CMD_ENC_SEQ_QP_DELTA_QP, offset: 0x1F4 */
       uint8_t RESERVED_9[3592];
  __IO uint32_t GDI_PRI_RD_PRIOR_L;                /**< GDI_PRI_RD_PRIOR_L, offset: 0x1000 */
  __IO uint32_t GDI_PRI_RD_PRIOR_H;                /**< GDI_PRI_RD_PRIOR_H, offset: 0x1004 */
  __IO uint32_t GDI_PRI_WR_PRIOR_L;                /**< GDI_PRI_WR_PRIOR_L, offset: 0x1008 */
  __IO uint32_t GDI_PRI_WR_PRIOR_H;                /**< GDI_PRI_WR_PRIOR_H, offset: 0x100C */
  __IO uint32_t GDI_PRI_RD_LOCK_CNT;               /**< GDI_PRI_RD_LOCK_CNT, offset: 0x1010 */
  __IO uint32_t GDI_PRI_WR_LOCK_CNT;               /**< GDI_PRI_WR_LOCK_CNT, offset: 0x1014 */
  __IO uint32_t GDI_SEC_RD_PRIOR_L;                /**< GDI_SEC_RD_PRIOR_L, offset: 0x1018 */
  __IO uint32_t GDI_SEC_RD_PRIOR_H;                /**< GDI_SEC_RD_PRIOR_H, offset: 0x101C */
  __IO uint32_t GDI_SEC_WR_PRIOR_L;                /**< GDI_SEC_WR_PRIOR_L, offset: 0x1020 */
  __IO uint32_t GDI_SEC_WR_PRIOR_H;                /**< GDI_SEC_WR_PRIOR_H, offset: 0x1024 */
  __IO uint32_t GDI_SEC_RD_LOCK_CNT;               /**< GDI_SEC_RD_LOCK_CNT, offset: 0x1028 */
  __IO uint32_t GDI_SEC_WR_LOCK_CNT;               /**< GDI_SEC_WR_LOCK_CNT, offset: 0x102C */
  __IO uint32_t GDI_SEC_CLIENT_EN;                 /**< GDI_SEC_CLIENT_EN, offset: 0x1030 */
       uint8_t RESERVED_10[4];
  __O  uint32_t GDI_PIC_INIT_HOST;                 /**< GDI_PIC_INIT_HOST, offset: 0x1038 */
       uint8_t RESERVED_11[4];
  __I  uint32_t GDI_CONFIG_REPORT_0;               /**< GDI_CONFIG_REPORT_0, offset: 0x1040 */
  __I  uint32_t GDI_CONFIG_REPORT_1;               /**< GDI_CONFIG_REPORT_1, offset: 0x1044 */
  __I  uint32_t GDI_CONFIG_REPORT_2;               /**< GDI_CONFIG_REPORT_2, offset: 0x1048 */
  __I  uint32_t GDI_CONFIG_REPORT_3;               /**< GDI_CONFIG_REPORT_3, offset: 0x104C */
  __I  uint32_t GDI_CONFIG_REPORT_4;               /**< GDI_CONFIG_REPORT_4, offset: 0x1050 */
  __I  uint32_t GDI_CONFIG_REPORT_5;               /**< GDI_CONFIG_REPORT_5, offset: 0x1054 */
  __I  uint32_t GDI_CONFIG_REPORT_6;               /**< GDI_CONFIG_REPORT_6, offset: 0x1058 */
  __I  uint32_t GDI_CONFIG_REPORT_7;               /**< GDI_CONFIG_REPORT_7, offset: 0x105C */
  __O  uint32_t GDI_PINFO_REQ;                     /**< GDI_PINFO_REQ, offset: 0x1060 */
  __I  uint32_t GDI_PINFO_ACK;                     /**< GDI_PINFO_ACK, offset: 0x1064 */
  __IO uint32_t GDI_PINFO_ADDR;                    /**< GDI_PINFO_ADDR, offset: 0x1068 */
  __IO uint32_t GDI_PINFO_DATA;                    /**< GDI_PINFO_DATA, offset: 0x106C */
  __IO uint32_t GDI_BWB_ENABLE;                    /**< GDI_BWB_ENABLE, offset: 0x1070 */
  __IO uint32_t GDI_BWB_SIZE;                      /**< GDI_BWB_SIZE, offset: 0x1074 */
  __IO uint32_t GDI_BWB_STD_STRUCT;                /**< GDI_BWB_STD_STRUCT, offset: 0x1078 */
  __I  uint32_t GDI_BWB_STATUS;                    /**< GDI_BWB_STATUS, offset: 0x107C */
       uint8_t RESERVED_12[32];
  __IO uint32_t GDI_WPROT_ERR_CLEAR;               /**< GDI_WPROT_ERR_CLEAR, offset: 0x10A0 */
  __I  uint32_t GDI_WPROT_ERR_RSN;                 /**< GDI_WPROT_ERR_RSN, offset: 0x10A4 */
  __I  uint32_t GDI_WPROT_ERR_ADR;                 /**< GDI_WPROT_ERR_ADR, offset: 0x10A8 */
  __IO uint32_t GDI_WPROT_RGN_EN;                  /**< GDI_WPROT_RGN_EN, offset: 0x10AC */
  __IO uint32_t GDI_WPROT_RGN0_STA;                /**< GDI_WPROT_RGN0_STA, offset: 0x10B0 */
  __IO uint32_t GDI_WPROT_RGN0_END;                /**< GDI_WPROT_RGN0_END, offset: 0x10B4 */
  __IO uint32_t GDI_WPROT_RGN1_STA;                /**< GDI_WPROT_RGN1_STA, offset: 0x10B8 */
  __IO uint32_t GDI_WPROT_RGN1_END;                /**< GDI_WPROT_RGN1_END, offset: 0x10BC */
  __IO uint32_t GDI_WPROT_RGN2_STA;                /**< GDI_WPROT_RGN2_STA, offset: 0x10C0 */
  __IO uint32_t GDI_WPROT_RGN2_END;                /**< GDI_WPROT_RGN2_END, offset: 0x10C4 */
  __IO uint32_t GDI_WPROT_RGN3_STA;                /**< GDI_WPROT_RGN3_STA, offset: 0x10C8 */
  __IO uint32_t GDI_WPROT_RGN3_END;                /**< GDI_WPROT_RGN3_END, offset: 0x10CC */
  __IO uint32_t GDI_WPROT_RGN4_STA;                /**< GDI_WPROT_RGN4_STA, offset: 0x10D0 */
  __IO uint32_t GDI_WPROT_RGN4_END;                /**< GDI_WPROT_RGN4_END, offset: 0x10D4 */
  __IO uint32_t GDI_WPROT_RGN5_STA;                /**< GDI_WPROT_RGN5_STA, offset: 0x10D8 */
  __IO uint32_t GDI_WPROT_RGN5_END;                /**< GDI_WPROT_RGN5_END, offset: 0x10DC */
       uint8_t RESERVED_13[4];
  __IO uint32_t GDI_SRC_IDX_REPORT;                /**< GDI_SRC_IDX_REPORT, offset: 0x10E4 */
  __IO uint32_t GDI_DEC_IDX_REPORT;                /**< GDI_DEC_IDX_REPORT, offset: 0x10E8 */
  __IO uint32_t GDI_DISP_IDX_REPORT;               /**< GDI_DISP_IDX_REPORT, offset: 0x10EC */
  __IO uint32_t GDI_BUS_CTRL;                      /**< GDI_BUS_CTRL, offset: 0x10F0 */
  __I  uint32_t GDI_BUS_STATUS;                    /**< GDI_BUS_STATUS, offset: 0x10F4 */
       uint8_t RESERVED_14[776];
  __IO uint32_t GDI_PIC_INFO_00_0;                 /**< GDI_PIC_INFO_00_0, offset: 0x1400 */
  __IO uint32_t GDI_PIC_INFO_00_1;                 /**< GDI_PIC_INFO_00_1, offset: 0x1404 */
  __IO uint32_t GDI_PIC_INFO_00_2;                 /**< GDI_PIC_INFO_00_2, offset: 0x1408 */
  __IO uint32_t GDI_PIC_INFO_00_3;                 /**< GDI_PIC_INFO_00_3, offset: 0x140C */
  __IO uint32_t GDI_PIC_INFO_00_4;                 /**< GDI_PIC_INFO_00_4, offset: 0x1410 */
  __IO uint32_t GDI_PIC_INFO_00_5;                 /**< GDI_PIC_INFO_00_5, offset: 0x1414 */
  __IO uint32_t GDI_PIC_INFO_00_6;                 /**< GDI_PIC_INFO_00_6, offset: 0x1418 */
  __IO uint32_t GDI_PIC_INFO_00_7;                 /**< GDI_PIC_INFO_00_7, offset: 0x141C */
  __IO uint32_t GDI_PIC_INFO_01_0;                 /**< GDI_PIC_INFO_01_0, offset: 0x1420 */
  __IO uint32_t GDI_PIC_INFO_01_1;                 /**< GDI_PIC_INFO_01_1, offset: 0x1424 */
  __IO uint32_t GDI_PIC_INFO_01_2;                 /**< GDI_PIC_INFO_01_2, offset: 0x1428 */
  __IO uint32_t GDI_PIC_INFO_01_3;                 /**< GDI_PIC_INFO_01_3, offset: 0x142C */
  __IO uint32_t GDI_PIC_INFO_01_4;                 /**< GDI_PIC_INFO_01_4, offset: 0x1430 */
  __IO uint32_t GDI_PIC_INFO_01_5;                 /**< GDI_PIC_INFO_01_5, offset: 0x1434 */
  __IO uint32_t GDI_PIC_INFO_01_6;                 /**< GDI_PIC_INFO_01_6, offset: 0x1438 */
  __IO uint32_t GDI_PIC_INFO_01_7;                 /**< GDI_PIC_INFO_01_7, offset: 0x143C */
  __IO uint32_t GDI_PIC_INFO_02_0;                 /**< GDI_PIC_INFO_02_0, offset: 0x1440 */
  __IO uint32_t GDI_PIC_INFO_02_1;                 /**< GDI_PIC_INFO_02_1, offset: 0x1444 */
  __IO uint32_t GDI_PIC_INFO_02_2;                 /**< GDI_PIC_INFO_02_2, offset: 0x1448 */
  __IO uint32_t GDI_PIC_INFO_02_3;                 /**< GDI_PIC_INFO_02_3, offset: 0x144C */
  __IO uint32_t GDI_PIC_INFO_02_4;                 /**< GDI_PIC_INFO_02_4, offset: 0x1450 */
  __IO uint32_t GDI_PIC_INFO_02_5;                 /**< GDI_PIC_INFO_02_5, offset: 0x1454 */
  __IO uint32_t GDI_PIC_INFO_02_6;                 /**< GDI_PIC_INFO_02_6, offset: 0x1458 */
  __IO uint32_t GDI_PIC_INFO_02_7;                 /**< GDI_PIC_INFO_02_7, offset: 0x145C */
  __IO uint32_t GDI_PIC_INFO_03_0;                 /**< GDI_PIC_INFO_03_0, offset: 0x1460 */
  __IO uint32_t GDI_PIC_INFO_03_1;                 /**< GDI_PIC_INFO_03_1, offset: 0x1464 */
  __IO uint32_t GDI_PIC_INFO_03_2;                 /**< GDI_PIC_INFO_03_2, offset: 0x1468 */
  __IO uint32_t GDI_PIC_INFO_03_3;                 /**< GDI_PIC_INFO_03_3, offset: 0x146C */
  __IO uint32_t GDI_PIC_INFO_03_4;                 /**< GDI_PIC_INFO_03_4, offset: 0x1470 */
  __IO uint32_t GDI_PIC_INFO_03_5;                 /**< GDI_PIC_INFO_03_5, offset: 0x1474 */
  __IO uint32_t GDI_PIC_INFO_03_6;                 /**< GDI_PIC_INFO_03_6, offset: 0x1478 */
  __IO uint32_t GDI_PIC_INFO_03_7;                 /**< GDI_PIC_INFO_03_7, offset: 0x147C */
  __IO uint32_t GDI_PIC_INFO_04_0;                 /**< GDI_PIC_INFO_04_0, offset: 0x1480 */
  __IO uint32_t GDI_PIC_INFO_04_1;                 /**< GDI_PIC_INFO_04_1, offset: 0x1484 */
  __IO uint32_t GDI_PIC_INFO_04_2;                 /**< GDI_PIC_INFO_04_2, offset: 0x1488 */
  __IO uint32_t GDI_PIC_INFO_04_3;                 /**< GDI_PIC_INFO_04_3, offset: 0x148C */
  __IO uint32_t GDI_PIC_INFO_04_4;                 /**< GDI_PIC_INFO_04_4, offset: 0x1490 */
  __IO uint32_t GDI_PIC_INFO_04_5;                 /**< GDI_PIC_INFO_04_5, offset: 0x1494 */
  __IO uint32_t GDI_PIC_INFO_04_6;                 /**< GDI_PIC_INFO_04_6, offset: 0x1498 */
  __IO uint32_t GDI_PIC_INFO_04_7;                 /**< GDI_PIC_INFO_04_7, offset: 0x149C */
  __IO uint32_t GDI_PIC_INFO_05_0;                 /**< GDI_PIC_INFO_05_0, offset: 0x14A0 */
  __IO uint32_t GDI_PIC_INFO_05_1;                 /**< GDI_PIC_INFO_05_1, offset: 0x14A4 */
  __IO uint32_t GDI_PIC_INFO_05_2;                 /**< GDI_PIC_INFO_05_2, offset: 0x14A8 */
  __IO uint32_t GDI_PIC_INFO_05_3;                 /**< GDI_PIC_INFO_05_3, offset: 0x14AC */
  __IO uint32_t GDI_PIC_INFO_05_4;                 /**< GDI_PIC_INFO_05_4, offset: 0x14B0 */
  __IO uint32_t GDI_PIC_INFO_05_5;                 /**< GDI_PIC_INFO_05_5, offset: 0x14B4 */
  __IO uint32_t GDI_PIC_INFO_05_6;                 /**< GDI_PIC_INFO_05_6, offset: 0x14B8 */
  __IO uint32_t GDI_PIC_INFO_05_7;                 /**< GDI_PIC_INFO_05_7, offset: 0x14BC */
  __IO uint32_t GDI_PIC_INFO_06_0;                 /**< GDI_PIC_INFO_06_0, offset: 0x14C0 */
  __IO uint32_t GDI_PIC_INFO_06_1;                 /**< GDI_PIC_INFO_06_1, offset: 0x14C4 */
  __IO uint32_t GDI_PIC_INFO_06_2;                 /**< GDI_PIC_INFO_06_2, offset: 0x14C8 */
  __IO uint32_t GDI_PIC_INFO_06_3;                 /**< GDI_PIC_INFO_06_3, offset: 0x14CC */
  __IO uint32_t GDI_PIC_INFO_06_4;                 /**< GDI_PIC_INFO_06_4, offset: 0x14D0 */
  __IO uint32_t GDI_PIC_INFO_06_5;                 /**< GDI_PIC_INFO_06_5, offset: 0x14D4 */
  __IO uint32_t GDI_PIC_INFO_06_6;                 /**< GDI_PIC_INFO_06_6, offset: 0x14D8 */
  __IO uint32_t GDI_PIC_INFO_06_7;                 /**< GDI_PIC_INFO_06_7, offset: 0x14DC */
  __IO uint32_t GDI_PIC_INFO_07_0;                 /**< GDI_PIC_INFO_07_0, offset: 0x14E0 */
  __IO uint32_t GDI_PIC_INFO_07_1;                 /**< GDI_PIC_INFO_07_1, offset: 0x14E4 */
  __IO uint32_t GDI_PIC_INFO_07_2;                 /**< GDI_PIC_INFO_07_2, offset: 0x14E8 */
  __IO uint32_t GDI_PIC_INFO_07_3;                 /**< GDI_PIC_INFO_07_3, offset: 0x14EC */
  __IO uint32_t GDI_PIC_INFO_07_4;                 /**< GDI_PIC_INFO_07_4, offset: 0x14F0 */
  __IO uint32_t GDI_PIC_INFO_07_5;                 /**< GDI_PIC_INFO_07_5, offset: 0x14F4 */
  __IO uint32_t GDI_PIC_INFO_07_6;                 /**< GDI_PIC_INFO_07_6, offset: 0x14F8 */
  __IO uint32_t GDI_PIC_INFO_07_7;                 /**< GDI_PIC_INFO_07_7, offset: 0x14FC */
  __IO uint32_t GDI_PIC_INFO_08_0;                 /**< GDI_PIC_INFO_08_0, offset: 0x1500 */
  __IO uint32_t GDI_PIC_INFO_08_1;                 /**< GDI_PIC_INFO_08_1, offset: 0x1504 */
  __IO uint32_t GDI_PIC_INFO_08_2;                 /**< GDI_PIC_INFO_08_2, offset: 0x1508 */
  __IO uint32_t GDI_PIC_INFO_08_3;                 /**< GDI_PIC_INFO_08_3, offset: 0x150C */
  __IO uint32_t GDI_PIC_INFO_08_4;                 /**< GDI_PIC_INFO_08_4, offset: 0x1510 */
  __IO uint32_t GDI_PIC_INFO_08_5;                 /**< GDI_PIC_INFO_08_5, offset: 0x1514 */
  __IO uint32_t GDI_PIC_INFO_08_6;                 /**< GDI_PIC_INFO_08_6, offset: 0x1518 */
  __IO uint32_t GDI_PIC_INFO_08_7;                 /**< GDI_PIC_INFO_08_7, offset: 0x151C */
  __IO uint32_t GDI_PIC_INFO_09_0;                 /**< GDI_PIC_INFO_09_0, offset: 0x1520 */
  __IO uint32_t GDI_PIC_INFO_09_1;                 /**< GDI_PIC_INFO_09_1, offset: 0x1524 */
  __IO uint32_t GDI_PIC_INFO_09_2;                 /**< GDI_PIC_INFO_09_2, offset: 0x1528 */
  __IO uint32_t GDI_PIC_INFO_09_3;                 /**< GDI_PIC_INFO_09_3, offset: 0x152C */
  __IO uint32_t GDI_PIC_INFO_09_4;                 /**< GDI_PIC_INFO_09_4, offset: 0x1530 */
  __IO uint32_t GDI_PIC_INFO_09_5;                 /**< GDI_PIC_INFO_09_5, offset: 0x1534 */
  __IO uint32_t GDI_PIC_INFO_09_6;                 /**< GDI_PIC_INFO_09_6, offset: 0x1538 */
  __IO uint32_t GDI_PIC_INFO_09_7;                 /**< GDI_PIC_INFO_09_7, offset: 0x153C */
  __IO uint32_t GDI_PIC_INFO_10_0;                 /**< GDI_PIC_INFO_10_0, offset: 0x1540 */
  __IO uint32_t GDI_PIC_INFO_10_1;                 /**< GDI_PIC_INFO_10_1, offset: 0x1544 */
  __IO uint32_t GDI_PIC_INFO_10_2;                 /**< GDI_PIC_INFO_10_2, offset: 0x1548 */
  __IO uint32_t GDI_PIC_INFO_10_3;                 /**< GDI_PIC_INFO_10_3, offset: 0x154C */
  __IO uint32_t GDI_PIC_INFO_10_4;                 /**< GDI_PIC_INFO_10_4, offset: 0x1550 */
  __IO uint32_t GDI_PIC_INFO_10_5;                 /**< GDI_PIC_INFO_10_5, offset: 0x1554 */
  __IO uint32_t GDI_PIC_INFO_10_6;                 /**< GDI_PIC_INFO_10_6, offset: 0x1558 */
  __IO uint32_t GDI_PIC_INFO_10_7;                 /**< GDI_PIC_INFO_10_7, offset: 0x155C */
  __IO uint32_t GDI_PIC_INFO_11_0;                 /**< GDI_PIC_INFO_11_0, offset: 0x1560 */
  __IO uint32_t GDI_PIC_INFO_11_1;                 /**< GDI_PIC_INFO_11_1, offset: 0x1564 */
  __IO uint32_t GDI_PIC_INFO_11_2;                 /**< GDI_PIC_INFO_11_2, offset: 0x1568 */
  __IO uint32_t GDI_PIC_INFO_11_3;                 /**< GDI_PIC_INFO_11_3, offset: 0x156C */
  __IO uint32_t GDI_PIC_INFO_11_4;                 /**< GDI_PIC_INFO_11_4, offset: 0x1570 */
  __IO uint32_t GDI_PIC_INFO_11_5;                 /**< GDI_PIC_INFO_11_5, offset: 0x1574 */
  __IO uint32_t GDI_PIC_INFO_11_6;                 /**< GDI_PIC_INFO_11_6, offset: 0x1578 */
  __IO uint32_t GDI_PIC_INFO_11_7;                 /**< GDI_PIC_INFO_11_7, offset: 0x157C */
  __IO uint32_t GDI_PIC_INFO_12_0;                 /**< GDI_PIC_INFO_12_0, offset: 0x1580 */
  __IO uint32_t GDI_PIC_INFO_12_1;                 /**< GDI_PIC_INFO_12_1, offset: 0x1584 */
  __IO uint32_t GDI_PIC_INFO_12_2;                 /**< GDI_PIC_INFO_12_2, offset: 0x1588 */
  __IO uint32_t GDI_PIC_INFO_12_3;                 /**< GDI_PIC_INFO_12_3, offset: 0x158C */
  __IO uint32_t GDI_PIC_INFO_12_4;                 /**< GDI_PIC_INFO_12_4, offset: 0x1590 */
  __IO uint32_t GDI_PIC_INFO_12_5;                 /**< GDI_PIC_INFO_12_5, offset: 0x1594 */
  __IO uint32_t GDI_PIC_INFO_12_6;                 /**< GDI_PIC_INFO_12_6, offset: 0x1598 */
  __IO uint32_t GDI_PIC_INFO_12_7;                 /**< GDI_PIC_INFO_12_7, offset: 0x159C */
  __IO uint32_t GDI_PIC_INFO_13_0;                 /**< GDI_PIC_INFO_13_0, offset: 0x15A0 */
  __IO uint32_t GDI_PIC_INFO_13_1;                 /**< GDI_PIC_INFO_13_1, offset: 0x15A4 */
  __IO uint32_t GDI_PIC_INFO_13_2;                 /**< GDI_PIC_INFO_13_2, offset: 0x15A8 */
  __IO uint32_t GDI_PIC_INFO_13_3;                 /**< GDI_PIC_INFO_13_3, offset: 0x15AC */
  __IO uint32_t GDI_PIC_INFO_13_4;                 /**< GDI_PIC_INFO_13_4, offset: 0x15B0 */
  __IO uint32_t GDI_PIC_INFO_13_5;                 /**< GDI_PIC_INFO_13_5, offset: 0x15B4 */
  __IO uint32_t GDI_PIC_INFO_13_6;                 /**< GDI_PIC_INFO_13_6, offset: 0x15B8 */
  __IO uint32_t GDI_PIC_INFO_13_7;                 /**< GDI_PIC_INFO_13_7, offset: 0x15BC */
  __IO uint32_t GDI_PIC_INFO_14_0;                 /**< GDI_PIC_INFO_14_0, offset: 0x15C0 */
  __IO uint32_t GDI_PIC_INFO_14_1;                 /**< GDI_PIC_INFO_14_1, offset: 0x15C4 */
  __IO uint32_t GDI_PIC_INFO_14_2;                 /**< GDI_PIC_INFO_14_2, offset: 0x15C8 */
  __IO uint32_t GDI_PIC_INFO_14_3;                 /**< GDI_PIC_INFO_14_3, offset: 0x15CC */
  __IO uint32_t GDI_PIC_INFO_14_4;                 /**< GDI_PIC_INFO_14_4, offset: 0x15D0 */
  __IO uint32_t GDI_PIC_INFO_14_5;                 /**< GDI_PIC_INFO_14_5, offset: 0x15D4 */
  __IO uint32_t GDI_PIC_INFO_14_6;                 /**< GDI_PIC_INFO_14_6, offset: 0x15D8 */
  __IO uint32_t GDI_PIC_INFO_14_7;                 /**< GDI_PIC_INFO_14_7, offset: 0x15DC */
  __IO uint32_t GDI_PIC_INFO_15_0;                 /**< GDI_PIC_INFO_15_0, offset: 0x15E0 */
  __IO uint32_t GDI_PIC_INFO_15_1;                 /**< GDI_PIC_INFO_15_1, offset: 0x15E4 */
  __IO uint32_t GDI_PIC_INFO_15_2;                 /**< GDI_PIC_INFO_15_2, offset: 0x15E8 */
  __IO uint32_t GDI_PIC_INFO_15_3;                 /**< GDI_PIC_INFO_15_3, offset: 0x15EC */
  __IO uint32_t GDI_PIC_INFO_15_4;                 /**< GDI_PIC_INFO_15_4, offset: 0x15F0 */
  __IO uint32_t GDI_PIC_INFO_15_5;                 /**< GDI_PIC_INFO_15_5, offset: 0x15F4 */
  __IO uint32_t GDI_PIC_INFO_15_6;                 /**< GDI_PIC_INFO_15_6, offset: 0x15F8 */
  __IO uint32_t GDI_PIC_INFO_15_7;                 /**< GDI_PIC_INFO_15_7, offset: 0x15FC */
  __IO uint32_t GDI_PIC_INFO_16_0;                 /**< GDI_PIC_INFO_16_0, offset: 0x1600 */
  __IO uint32_t GDI_PIC_INFO_16_1;                 /**< GDI_PIC_INFO_16_1, offset: 0x1604 */
  __IO uint32_t GDI_PIC_INFO_16_2;                 /**< GDI_PIC_INFO_16_2, offset: 0x1608 */
  __IO uint32_t GDI_PIC_INFO_16_3;                 /**< GDI_PIC_INFO_16_3, offset: 0x160C */
  __IO uint32_t GDI_PIC_INFO_16_4;                 /**< GDI_PIC_INFO_16_4, offset: 0x1610 */
  __IO uint32_t GDI_PIC_INFO_16_5;                 /**< GDI_PIC_INFO_16_5, offset: 0x1614 */
  __IO uint32_t GDI_PIC_INFO_16_6;                 /**< GDI_PIC_INFO_16_6, offset: 0x1618 */
  __IO uint32_t GDI_PIC_INFO_16_7;                 /**< GDI_PIC_INFO_16_7, offset: 0x161C */
  __IO uint32_t GDI_PIC_INFO_17_0;                 /**< GDI_PIC_INFO_17_0, offset: 0x1620 */
  __IO uint32_t GDI_PIC_INFO_17_1;                 /**< GDI_PIC_INFO_17_1, offset: 0x1624 */
  __IO uint32_t GDI_PIC_INFO_17_2;                 /**< GDI_PIC_INFO_17_2, offset: 0x1628 */
  __IO uint32_t GDI_PIC_INFO_17_3;                 /**< GDI_PIC_INFO_17_3, offset: 0x162C */
  __IO uint32_t GDI_PIC_INFO_17_4;                 /**< GDI_PIC_INFO_17_4, offset: 0x1630 */
  __IO uint32_t GDI_PIC_INFO_17_5;                 /**< GDI_PIC_INFO_17_5, offset: 0x1634 */
  __IO uint32_t GDI_PIC_INFO_17_6;                 /**< GDI_PIC_INFO_17_6, offset: 0x1638 */
  __IO uint32_t GDI_PIC_INFO_17_7;                 /**< GDI_PIC_INFO_17_7, offset: 0x163C */
  __IO uint32_t GDI_PIC_INFO_18_0;                 /**< GDI_PIC_INFO_18_0, offset: 0x1640 */
  __IO uint32_t GDI_PIC_INFO_18_1;                 /**< GDI_PIC_INFO_18_1, offset: 0x1644 */
  __IO uint32_t GDI_PIC_INFO_18_2;                 /**< GDI_PIC_INFO_18_2, offset: 0x1648 */
  __IO uint32_t GDI_PIC_INFO_18_3;                 /**< GDI_PIC_INFO_18_3, offset: 0x164C */
  __IO uint32_t GDI_PIC_INFO_18_4;                 /**< GDI_PIC_INFO_18_4, offset: 0x1650 */
  __IO uint32_t GDI_PIC_INFO_18_5;                 /**< GDI_PIC_INFO_18_5, offset: 0x1654 */
  __IO uint32_t GDI_PIC_INFO_18_6;                 /**< GDI_PIC_INFO_18_6, offset: 0x1658 */
  __IO uint32_t GDI_PIC_INFO_18_7;                 /**< GDI_PIC_INFO_18_7, offset: 0x165C */
  __IO uint32_t GDI_PIC_INFO_19_0;                 /**< GDI_PIC_INFO_19_0, offset: 0x1660 */
  __IO uint32_t GDI_PIC_INFO_19_1;                 /**< GDI_PIC_INFO_19_1, offset: 0x1664 */
  __IO uint32_t GDI_PIC_INFO_19_2;                 /**< GDI_PIC_INFO_19_2, offset: 0x1668 */
  __IO uint32_t GDI_PIC_INFO_19_3;                 /**< GDI_PIC_INFO_19_3, offset: 0x166C */
  __IO uint32_t GDI_PIC_INFO_19_4;                 /**< GDI_PIC_INFO_19_4, offset: 0x1670 */
  __IO uint32_t GDI_PIC_INFO_19_5;                 /**< GDI_PIC_INFO_19_5, offset: 0x1674 */
  __IO uint32_t GDI_PIC_INFO_19_6;                 /**< GDI_PIC_INFO_19_6, offset: 0x1678 */
  __IO uint32_t GDI_PIC_INFO_19_7;                 /**< GDI_PIC_INFO_19_7, offset: 0x167C */
  __IO uint32_t GDI_PIC_INFO_20_0;                 /**< GDI_PIC_INFO_20_0, offset: 0x1680 */
  __IO uint32_t GDI_PIC_INFO_20_1;                 /**< GDI_PIC_INFO_20_1, offset: 0x1684 */
  __IO uint32_t GDI_PIC_INFO_20_2;                 /**< GDI_PIC_INFO_20_2, offset: 0x1688 */
  __IO uint32_t GDI_PIC_INFO_20_3;                 /**< GDI_PIC_INFO_20_3, offset: 0x168C */
  __IO uint32_t GDI_PIC_INFO_20_4;                 /**< GDI_PIC_INFO_20_4, offset: 0x1690 */
  __IO uint32_t GDI_PIC_INFO_20_5;                 /**< GDI_PIC_INFO_20_5, offset: 0x1694 */
  __IO uint32_t GDI_PIC_INFO_20_6;                 /**< GDI_PIC_INFO_20_6, offset: 0x1698 */
  __IO uint32_t GDI_PIC_INFO_20_7;                 /**< GDI_PIC_INFO_20_7, offset: 0x169C */
  __IO uint32_t GDI_PIC_INFO_21_0;                 /**< GDI_PIC_INFO_21_0, offset: 0x16A0 */
  __IO uint32_t GDI_PIC_INFO_21_1;                 /**< GDI_PIC_INFO_21_1, offset: 0x16A4 */
  __IO uint32_t GDI_PIC_INFO_21_2;                 /**< GDI_PIC_INFO_21_2, offset: 0x16A8 */
  __IO uint32_t GDI_PIC_INFO_21_3;                 /**< GDI_PIC_INFO_21_3, offset: 0x16AC */
  __IO uint32_t GDI_PIC_INFO_21_4;                 /**< GDI_PIC_INFO_21_4, offset: 0x16B0 */
  __IO uint32_t GDI_PIC_INFO_21_5;                 /**< GDI_PIC_INFO_21_5, offset: 0x16B4 */
  __IO uint32_t GDI_PIC_INFO_21_6;                 /**< GDI_PIC_INFO_21_6, offset: 0x16B8 */
  __IO uint32_t GDI_PIC_INFO_21_7;                 /**< GDI_PIC_INFO_21_7, offset: 0x16BC */
  __IO uint32_t GDI_PIC_INFO_22_0;                 /**< GDI_PIC_INFO_22_0, offset: 0x16C0 */
  __IO uint32_t GDI_PIC_INFO_22_1;                 /**< GDI_PIC_INFO_22_1, offset: 0x16C4 */
  __IO uint32_t GDI_PIC_INFO_22_2;                 /**< GDI_PIC_INFO_22_2, offset: 0x16C8 */
  __IO uint32_t GDI_PIC_INFO_22_3;                 /**< GDI_PIC_INFO_22_3, offset: 0x16CC */
  __IO uint32_t GDI_PIC_INFO_22_4;                 /**< GDI_PIC_INFO_22_4, offset: 0x16D0 */
  __IO uint32_t GDI_PIC_INFO_22_5;                 /**< GDI_PIC_INFO_22_5, offset: 0x16D4 */
  __IO uint32_t GDI_PIC_INFO_22_6;                 /**< GDI_PIC_INFO_22_6, offset: 0x16D8 */
  __IO uint32_t GDI_PIC_INFO_22_7;                 /**< GDI_PIC_INFO_22_7, offset: 0x16DC */
  __IO uint32_t GDI_PIC_INFO_23_0;                 /**< GDI_PIC_INFO_23_0, offset: 0x16E0 */
  __IO uint32_t GDI_PIC_INFO_23_1;                 /**< GDI_PIC_INFO_23_1, offset: 0x16E4 */
  __IO uint32_t GDI_PIC_INFO_23_2;                 /**< GDI_PIC_INFO_23_2, offset: 0x16E8 */
  __IO uint32_t GDI_PIC_INFO_23_3;                 /**< GDI_PIC_INFO_23_3, offset: 0x16EC */
  __IO uint32_t GDI_PIC_INFO_23_4;                 /**< GDI_PIC_INFO_23_4, offset: 0x16F0 */
  __IO uint32_t GDI_PIC_INFO_23_5;                 /**< GDI_PIC_INFO_23_5, offset: 0x16F4 */
  __IO uint32_t GDI_PIC_INFO_23_6;                 /**< GDI_PIC_INFO_23_6, offset: 0x16F8 */
  __IO uint32_t GDI_PIC_INFO_23_7;                 /**< GDI_PIC_INFO_23_7, offset: 0x16FC */
  __IO uint32_t GDI_PIC_INFO_24_0;                 /**< GDI_PIC_INFO_24_0, offset: 0x1700 */
  __IO uint32_t GDI_PIC_INFO_24_1;                 /**< GDI_PIC_INFO_24_1, offset: 0x1704 */
  __IO uint32_t GDI_PIC_INFO_24_2;                 /**< GDI_PIC_INFO_24_2, offset: 0x1708 */
  __IO uint32_t GDI_PIC_INFO_24_3;                 /**< GDI_PIC_INFO_24_3, offset: 0x170C */
  __IO uint32_t GDI_PIC_INFO_24_4;                 /**< GDI_PIC_INFO_24_4, offset: 0x1710 */
  __IO uint32_t GDI_PIC_INFO_24_5;                 /**< GDI_PIC_INFO_24_5, offset: 0x1714 */
  __IO uint32_t GDI_PIC_INFO_24_6;                 /**< GDI_PIC_INFO_24_6, offset: 0x1718 */
  __IO uint32_t GDI_PIC_INFO_24_7;                 /**< GDI_PIC_INFO_24_7, offset: 0x171C */
  __IO uint32_t GDI_PIC_INFO_25_0;                 /**< GDI_PIC_INFO_25_0, offset: 0x1720 */
  __IO uint32_t GDI_PIC_INFO_25_1;                 /**< GDI_PIC_INFO_25_1, offset: 0x1724 */
  __IO uint32_t GDI_PIC_INFO_25_2;                 /**< GDI_PIC_INFO_25_2, offset: 0x1728 */
  __IO uint32_t GDI_PIC_INFO_25_3;                 /**< GDI_PIC_INFO_25_3, offset: 0x172C */
  __IO uint32_t GDI_PIC_INFO_25_4;                 /**< GDI_PIC_INFO_25_4, offset: 0x1730 */
  __IO uint32_t GDI_PIC_INFO_25_5;                 /**< GDI_PIC_INFO_25_5, offset: 0x1734 */
  __IO uint32_t GDI_PIC_INFO_25_6;                 /**< GDI_PIC_INFO_25_6, offset: 0x1738 */
  __IO uint32_t GDI_PIC_INFO_25_7;                 /**< GDI_PIC_INFO_25_7, offset: 0x173C */
  __IO uint32_t GDI_PIC_INFO_26_0;                 /**< GDI_PIC_INFO_26_0, offset: 0x1740 */
  __IO uint32_t GDI_PIC_INFO_26_1;                 /**< GDI_PIC_INFO_26_1, offset: 0x1744 */
  __IO uint32_t GDI_PIC_INFO_26_2;                 /**< GDI_PIC_INFO_26_2, offset: 0x1748 */
  __IO uint32_t GDI_PIC_INFO_26_3;                 /**< GDI_PIC_INFO_26_3, offset: 0x174C */
  __IO uint32_t GDI_PIC_INFO_26_4;                 /**< GDI_PIC_INFO_26_4, offset: 0x1750 */
  __IO uint32_t GDI_PIC_INFO_26_5;                 /**< GDI_PIC_INFO_26_5, offset: 0x1754 */
  __IO uint32_t GDI_PIC_INFO_26_6;                 /**< GDI_PIC_INFO_26_6, offset: 0x1758 */
  __IO uint32_t GDI_PIC_INFO_26_7;                 /**< GDI_PIC_INFO_26_7, offset: 0x175C */
  __IO uint32_t GDI_PIC_INFO_27_0;                 /**< GDI_PIC_INFO_27_0, offset: 0x1760 */
  __IO uint32_t GDI_PIC_INFO_27_1;                 /**< GDI_PIC_INFO_27_1, offset: 0x1764 */
  __IO uint32_t GDI_PIC_INFO_27_2;                 /**< GDI_PIC_INFO_27_2, offset: 0x1768 */
  __IO uint32_t GDI_PIC_INFO_27_3;                 /**< GDI_PIC_INFO_27_3, offset: 0x176C */
  __IO uint32_t GDI_PIC_INFO_27_4;                 /**< GDI_PIC_INFO_27_4, offset: 0x1770 */
  __IO uint32_t GDI_PIC_INFO_27_5;                 /**< GDI_PIC_INFO_27_5, offset: 0x1774 */
  __IO uint32_t GDI_PIC_INFO_27_6;                 /**< GDI_PIC_INFO_27_6, offset: 0x1778 */
  __IO uint32_t GDI_PIC_INFO_27_7;                 /**< GDI_PIC_INFO_27_7, offset: 0x177C */
  __IO uint32_t GDI_PIC_INFO_28_0;                 /**< GDI_PIC_INFO_28_0, offset: 0x1780 */
  __IO uint32_t GDI_PIC_INFO_28_1;                 /**< GDI_PIC_INFO_28_1, offset: 0x1784 */
  __IO uint32_t GDI_PIC_INFO_28_2;                 /**< GDI_PIC_INFO_28_2, offset: 0x1788 */
  __IO uint32_t GDI_PIC_INFO_28_3;                 /**< GDI_PIC_INFO_28_3, offset: 0x178C */
  __IO uint32_t GDI_PIC_INFO_28_4;                 /**< GDI_PIC_INFO_28_4, offset: 0x1790 */
  __IO uint32_t GDI_PIC_INFO_28_5;                 /**< GDI_PIC_INFO_28_5, offset: 0x1794 */
  __IO uint32_t GDI_PIC_INFO_28_6;                 /**< GDI_PIC_INFO_28_6, offset: 0x1798 */
  __IO uint32_t GDI_PIC_INFO_28_7;                 /**< GDI_PIC_INFO_28_7, offset: 0x179C */
  __IO uint32_t GDI_PIC_INFO_29_0;                 /**< GDI_PIC_INFO_29_0, offset: 0x17A0 */
  __IO uint32_t GDI_PIC_INFO_29_1;                 /**< GDI_PIC_INFO_29_1, offset: 0x17A4 */
  __IO uint32_t GDI_PIC_INFO_29_2;                 /**< GDI_PIC_INFO_29_2, offset: 0x17A8 */
  __IO uint32_t GDI_PIC_INFO_29_3;                 /**< GDI_PIC_INFO_29_3, offset: 0x17AC */
  __IO uint32_t GDI_PIC_INFO_29_4;                 /**< GDI_PIC_INFO_29_4, offset: 0x17B0 */
  __IO uint32_t GDI_PIC_INFO_29_5;                 /**< GDI_PIC_INFO_29_5, offset: 0x17B4 */
  __IO uint32_t GDI_PIC_INFO_29_6;                 /**< GDI_PIC_INFO_29_6, offset: 0x17B8 */
  __IO uint32_t GDI_PIC_INFO_29_7;                 /**< GDI_PIC_INFO_29_7, offset: 0x17BC */
  __IO uint32_t GDI_PIC_INFO_30_0;                 /**< GDI_PIC_INFO_30_0, offset: 0x17C0 */
  __IO uint32_t GDI_PIC_INFO_30_1;                 /**< GDI_PIC_INFO_30_1, offset: 0x17C4 */
  __IO uint32_t GDI_PIC_INFO_30_2;                 /**< GDI_PIC_INFO_30_2, offset: 0x17C8 */
  __IO uint32_t GDI_PIC_INFO_30_3;                 /**< GDI_PIC_INFO_30_3, offset: 0x17CC */
  __IO uint32_t GDI_PIC_INFO_30_4;                 /**< GDI_PIC_INFO_30_4, offset: 0x17D0 */
  __IO uint32_t GDI_PIC_INFO_30_5;                 /**< GDI_PIC_INFO_30_5, offset: 0x17D4 */
  __IO uint32_t GDI_PIC_INFO_30_6;                 /**< GDI_PIC_INFO_30_6, offset: 0x17D8 */
  __IO uint32_t GDI_PIC_INFO_30_7;                 /**< GDI_PIC_INFO_30_7, offset: 0x17DC */
  __IO uint32_t GDI_PIC_INFO_31_0;                 /**< GDI_PIC_INFO_31_0, offset: 0x17E0 */
  __IO uint32_t GDI_PIC_INFO_31_1;                 /**< GDI_PIC_INFO_31_1, offset: 0x17E4 */
  __IO uint32_t GDI_PIC_INFO_31_2;                 /**< GDI_PIC_INFO_31_2, offset: 0x17E8 */
  __IO uint32_t GDI_PIC_INFO_31_3;                 /**< GDI_PIC_INFO_31_3, offset: 0x17EC */
  __IO uint32_t GDI_PIC_INFO_31_4;                 /**< GDI_PIC_INFO_31_4, offset: 0x17F0 */
  __IO uint32_t GDI_PIC_INFO_31_5;                 /**< GDI_PIC_INFO_31_5, offset: 0x17F4 */
  __IO uint32_t GDI_PIC_INFO_31_6;                 /**< GDI_PIC_INFO_31_6, offset: 0x17F8 */
  __IO uint32_t GDI_PIC_INFO_31_7;                 /**< GDI_PIC_INFO_31_7, offset: 0x17FC */
  __IO uint32_t GDI_XY2AXI_LUM_BIT00;              /**< GDI_XY2AXI_LUM_BIT00, offset: 0x1800 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT01;              /**< GDI_XY2AXI_LUM_BIT01, offset: 0x1804 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT02;              /**< GDI_XY2AXI_LUM_BIT02, offset: 0x1808 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT03;              /**< GDI_XY2AXI_LUM_BIT03, offset: 0x180C */
  __IO uint32_t GDI_XY2AXI_LUM_BIT04;              /**< GDI_XY2AXI_LUM_BIT04, offset: 0x1810 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT05;              /**< GDI_XY2AXI_LUM_BIT05, offset: 0x1814 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT06;              /**< GDI_XY2AXI_LUM_BIT06, offset: 0x1818 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT07;              /**< GDI_XY2AXI_LUM_BIT07, offset: 0x181C */
  __IO uint32_t GDI_XY2AXI_LUM_BIT08;              /**< GDI_XY2AXI_LUM_BIT08, offset: 0x1820 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT09;              /**< GDI_XY2AXI_LUM_BIT09, offset: 0x1824 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT0A;              /**< GDI_XY2AXI_LUM_BIT0A, offset: 0x1828 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT0B;              /**< GDI_XY2AXI_LUM_BIT0B, offset: 0x182C */
  __IO uint32_t GDI_XY2AXI_LUM_BIT0C;              /**< GDI_XY2AXI_LUM_BIT0C, offset: 0x1830 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT0D;              /**< GDI_XY2AXI_LUM_BIT0D, offset: 0x1834 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT0E;              /**< GDI_XY2AXI_LUM_BIT0E, offset: 0x1838 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT0F;              /**< GDI_XY2AXI_LUM_BIT0F, offset: 0x183C */
  __IO uint32_t GDI_XY2AXI_LUM_BIT10;              /**< GDI_XY2AXI_LUM_BIT10, offset: 0x1840 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT11;              /**< GDI_XY2AXI_LUM_BIT11, offset: 0x1844 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT12;              /**< GDI_XY2AXI_LUM_BIT12, offset: 0x1848 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT13;              /**< GDI_XY2AXI_LUM_BIT13, offset: 0x184C */
  __IO uint32_t GDI_XY2AXI_LUM_BIT14;              /**< GDI_XY2AXI_LUM_BIT14, offset: 0x1850 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT15;              /**< GDI_XY2AXI_LUM_BIT15, offset: 0x1854 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT16;              /**< GDI_XY2AXI_LUM_BIT16, offset: 0x1858 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT17;              /**< GDI_XY2AXI_LUM_BIT17, offset: 0x185C */
  __IO uint32_t GDI_XY2AXI_LUM_BIT18;              /**< GDI_XY2AXI_LUM_BIT18, offset: 0x1860 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT19;              /**< GDI_XY2AXI_LUM_BIT19, offset: 0x1864 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT1A;              /**< GDI_XY2AXI_LUM_BIT1A, offset: 0x1868 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT1B;              /**< GDI_XY2AXI_LUM_BIT1B, offset: 0x186C */
  __IO uint32_t GDI_XY2AXI_LUM_BIT1C;              /**< GDI_XY2AXI_LUM_BIT1C, offset: 0x1870 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT1D;              /**< GDI_XY2AXI_LUM_BIT1D, offset: 0x1874 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT1E;              /**< GDI_XY2AXI_LUM_BIT1E, offset: 0x1878 */
  __IO uint32_t GDI_XY2AXI_LUM_BIT1F;              /**< GDI_XY2AXI_LUM_BIT1F, offset: 0x187C */
  __IO uint32_t GDI_XY2AXI_CHR_BIT00;              /**< GDI_XY2AXI_CHR_BIT00, offset: 0x1880 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT01;              /**< GDI_XY2AXI_CHR_BIT01, offset: 0x1884 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT02;              /**< GDI_XY2AXI_CHR_BIT02, offset: 0x1888 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT03;              /**< GDI_XY2AXI_CHR_BIT03, offset: 0x188C */
  __IO uint32_t GDI_XY2AXI_CHR_BIT04;              /**< GDI_XY2AXI_CHR_BIT04, offset: 0x1890 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT05;              /**< GDI_XY2AXI_CHR_BIT05, offset: 0x1894 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT06;              /**< GDI_XY2AXI_CHR_BIT06, offset: 0x1898 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT07;              /**< GDI_XY2AXI_CHR_BIT07, offset: 0x189C */
  __IO uint32_t GDI_XY2AXI_CHR_BIT08;              /**< GDI_XY2AXI_CHR_BIT08, offset: 0x18A0 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT09;              /**< GDI_XY2AXI_CHR_BIT09, offset: 0x18A4 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT0A;              /**< GDI_XY2AXI_CHR_BIT0A, offset: 0x18A8 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT0B;              /**< GDI_XY2AXI_CHR_BIT0B, offset: 0x18AC */
  __IO uint32_t GDI_XY2AXI_CHR_BIT0C;              /**< GDI_XY2AXI_CHR_BIT0C, offset: 0x18B0 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT0D;              /**< GDI_XY2AXI_CHR_BIT0D, offset: 0x18B4 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT0E;              /**< GDI_XY2AXI_CHR_BIT0E, offset: 0x18B8 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT0F;              /**< GDI_XY2AXI_CHR_BIT0F, offset: 0x18BC */
  __IO uint32_t GDI_XY2AXI_CHR_BIT10;              /**< GDI_XY2AXI_CHR_BIT10, offset: 0x18C0 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT11;              /**< GDI_XY2AXI_CHR_BIT11, offset: 0x18C4 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT12;              /**< GDI_XY2AXI_CHR_BIT12, offset: 0x18C8 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT13;              /**< GDI_XY2AXI_CHR_BIT13, offset: 0x18CC */
  __IO uint32_t GDI_XY2AXI_CHR_BIT14;              /**< GDI_XY2AXI_CHR_BIT14, offset: 0x18D0 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT15;              /**< GDI_XY2AXI_CHR_BIT15, offset: 0x18D4 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT16;              /**< GDI_XY2AXI_CHR_BIT16, offset: 0x18D8 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT17;              /**< GDI_XY2AXI_CHR_BIT17, offset: 0x18DC */
  __IO uint32_t GDI_XY2AXI_CHR_BIT18;              /**< GDI_XY2AXI_CHR_BIT18, offset: 0x18E0 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT19;              /**< GDI_XY2AXI_CHR_BIT19, offset: 0x18E4 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT1A;              /**< GDI_XY2AXI_CHR_BIT1A, offset: 0x18E8 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT1B;              /**< GDI_XY2AXI_CHR_BIT1B, offset: 0x18EC */
  __IO uint32_t GDI_XY2AXI_CHR_BIT1C;              /**< GDI_XY2AXI_CHR_BIT1C, offset: 0x18F0 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT1D;              /**< GDI_XY2AXI_CHR_BIT1D, offset: 0x18F4 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT1E;              /**< GDI_XY2AXI_CHR_BIT1E, offset: 0x18F8 */
  __IO uint32_t GDI_XY2AXI_CHR_BIT1F;              /**< GDI_XY2AXI_CHR_BIT1F, offset: 0x18FC */
  __IO uint32_t GDI_XY2AXI_CFG;                    /**< GDI_XY2AXI_CFG, offset: 0x1900 */
  __O  uint32_t GDI_AXI_BASE_EXTEND;               /**< GDI_AXI_BASE_EXTEND, offset: 0x1904 */
} VPU_VPU_ENC_Type;

/* ----------------------------------------------------------------------------
   -- VPU_VPU_ENC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_VPU_ENC_Register_Masks VPU_VPU_ENC Register Masks
 * @{
 */

/*! @name BIT_CODE_RUN - BIT_CODE_RUN */
/*! @{ */

#define VPU_VPU_ENC_BIT_CODE_RUN_BIT_CODE_RUN_MASK (0x1U)
#define VPU_VPU_ENC_BIT_CODE_RUN_BIT_CODE_RUN_SHIFT (0U)
#define VPU_VPU_ENC_BIT_CODE_RUN_BIT_CODE_RUN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_CODE_RUN_BIT_CODE_RUN_SHIFT)) & VPU_VPU_ENC_BIT_CODE_RUN_BIT_CODE_RUN_MASK)
/*! @} */

/*! @name BIT_CODE_DOWN - BIT_CODE_DOWN */
/*! @{ */

#define VPU_VPU_ENC_BIT_CODE_DOWN_CodeData_MASK  (0xFFFFU)
#define VPU_VPU_ENC_BIT_CODE_DOWN_CodeData_SHIFT (0U)
#define VPU_VPU_ENC_BIT_CODE_DOWN_CodeData(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_CODE_DOWN_CodeData_SHIFT)) & VPU_VPU_ENC_BIT_CODE_DOWN_CodeData_MASK)

#define VPU_VPU_ENC_BIT_CODE_DOWN_CodeAddr_MASK  (0x1FFF0000U)
#define VPU_VPU_ENC_BIT_CODE_DOWN_CodeAddr_SHIFT (16U)
#define VPU_VPU_ENC_BIT_CODE_DOWN_CodeAddr(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_CODE_DOWN_CodeAddr_SHIFT)) & VPU_VPU_ENC_BIT_CODE_DOWN_CodeAddr_MASK)
/*! @} */

/*! @name BIT_INT_REQ - BIT_INT_REQ */
/*! @{ */

#define VPU_VPU_ENC_BIT_INT_REQ_IntReq_MASK      (0x1U)
#define VPU_VPU_ENC_BIT_INT_REQ_IntReq_SHIFT     (0U)
#define VPU_VPU_ENC_BIT_INT_REQ_IntReq(x)        (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_INT_REQ_IntReq_SHIFT)) & VPU_VPU_ENC_BIT_INT_REQ_IntReq_MASK)
/*! @} */

/*! @name BIT_INT_CLEAR - BIT_INT_CLEAR */
/*! @{ */

#define VPU_VPU_ENC_BIT_INT_CLEAR_IntClear_MASK  (0x1U)
#define VPU_VPU_ENC_BIT_INT_CLEAR_IntClear_SHIFT (0U)
#define VPU_VPU_ENC_BIT_INT_CLEAR_IntClear(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_INT_CLEAR_IntClear_SHIFT)) & VPU_VPU_ENC_BIT_INT_CLEAR_IntClear_MASK)
/*! @} */

/*! @name BIT_INT_STS - BIT_INT_STS */
/*! @{ */

#define VPU_VPU_ENC_BIT_INT_STS_IntSts_MASK      (0x1U)
#define VPU_VPU_ENC_BIT_INT_STS_IntSts_SHIFT     (0U)
#define VPU_VPU_ENC_BIT_INT_STS_IntSts(x)        (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_INT_STS_IntSts_SHIFT)) & VPU_VPU_ENC_BIT_INT_STS_IntSts_MASK)
/*! @} */

/*! @name BIT_CODE_RESET - BIT_CODE_RESET */
/*! @{ */

#define VPU_VPU_ENC_BIT_CODE_RESET_CodeReset_MASK (0x1U)
#define VPU_VPU_ENC_BIT_CODE_RESET_CodeReset_SHIFT (0U)
#define VPU_VPU_ENC_BIT_CODE_RESET_CodeReset(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_CODE_RESET_CodeReset_SHIFT)) & VPU_VPU_ENC_BIT_CODE_RESET_CodeReset_MASK)
/*! @} */

/*! @name BIT_CUR_PC - BIT_CUR_PC */
/*! @{ */

#define VPU_VPU_ENC_BIT_CUR_PC_CurPc_MASK        (0x3FFFU)
#define VPU_VPU_ENC_BIT_CUR_PC_CurPc_SHIFT       (0U)
#define VPU_VPU_ENC_BIT_CUR_PC_CurPc(x)          (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_CUR_PC_CurPc_SHIFT)) & VPU_VPU_ENC_BIT_CUR_PC_CurPc_MASK)
/*! @} */

/*! @name BIT_CODEC_BUSY - BIT_CODEC_BUSY */
/*! @{ */

#define VPU_VPU_ENC_BIT_CODEC_BUSY_CodecBusy_MASK (0x1U)
#define VPU_VPU_ENC_BIT_CODEC_BUSY_CodecBusy_SHIFT (0U)
#define VPU_VPU_ENC_BIT_CODEC_BUSY_CodecBusy(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_CODEC_BUSY_CodecBusy_SHIFT)) & VPU_VPU_ENC_BIT_CODEC_BUSY_CodecBusy_MASK)
/*! @} */

/*! @name BIT_SW_RESET - BIT_SW_RESET */
/*! @{ */

#define VPU_VPU_ENC_BIT_SW_RESET_Reserved0_MASK  (0x7U)
#define VPU_VPU_ENC_BIT_SW_RESET_Reserved0_SHIFT (0U)
#define VPU_VPU_ENC_BIT_SW_RESET_Reserved0(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_SW_RESET_Reserved0_SHIFT)) & VPU_VPU_ENC_BIT_SW_RESET_Reserved0_MASK)

#define VPU_VPU_ENC_BIT_SW_RESET_RESET_BPU_CORE_MASK (0x8U)
#define VPU_VPU_ENC_BIT_SW_RESET_RESET_BPU_CORE_SHIFT (3U)
#define VPU_VPU_ENC_BIT_SW_RESET_RESET_BPU_CORE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_SW_RESET_RESET_BPU_CORE_SHIFT)) & VPU_VPU_ENC_BIT_SW_RESET_RESET_BPU_CORE_MASK)

#define VPU_VPU_ENC_BIT_SW_RESET_RESET_BPU_BUS_MASK (0x10U)
#define VPU_VPU_ENC_BIT_SW_RESET_RESET_BPU_BUS_SHIFT (4U)
#define VPU_VPU_ENC_BIT_SW_RESET_RESET_BPU_BUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_SW_RESET_RESET_BPU_BUS_SHIFT)) & VPU_VPU_ENC_BIT_SW_RESET_RESET_BPU_BUS_MASK)

#define VPU_VPU_ENC_BIT_SW_RESET_RESET_VCE_CORE_MASK (0x20U)
#define VPU_VPU_ENC_BIT_SW_RESET_RESET_VCE_CORE_SHIFT (5U)
#define VPU_VPU_ENC_BIT_SW_RESET_RESET_VCE_CORE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_SW_RESET_RESET_VCE_CORE_SHIFT)) & VPU_VPU_ENC_BIT_SW_RESET_RESET_VCE_CORE_MASK)

#define VPU_VPU_ENC_BIT_SW_RESET_RESET_VCE_BUS_MASK (0x40U)
#define VPU_VPU_ENC_BIT_SW_RESET_RESET_VCE_BUS_SHIFT (6U)
#define VPU_VPU_ENC_BIT_SW_RESET_RESET_VCE_BUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_SW_RESET_RESET_VCE_BUS_SHIFT)) & VPU_VPU_ENC_BIT_SW_RESET_RESET_VCE_BUS_MASK)

#define VPU_VPU_ENC_BIT_SW_RESET_RESET_GDI_CORE_MASK (0x80U)
#define VPU_VPU_ENC_BIT_SW_RESET_RESET_GDI_CORE_SHIFT (7U)
#define VPU_VPU_ENC_BIT_SW_RESET_RESET_GDI_CORE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_SW_RESET_RESET_GDI_CORE_SHIFT)) & VPU_VPU_ENC_BIT_SW_RESET_RESET_GDI_CORE_MASK)

#define VPU_VPU_ENC_BIT_SW_RESET_RESET_GDI_BUS_MASK (0x100U)
#define VPU_VPU_ENC_BIT_SW_RESET_RESET_GDI_BUS_SHIFT (8U)
#define VPU_VPU_ENC_BIT_SW_RESET_RESET_GDI_BUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_SW_RESET_RESET_GDI_BUS_SHIFT)) & VPU_VPU_ENC_BIT_SW_RESET_RESET_GDI_BUS_MASK)

#define VPU_VPU_ENC_BIT_SW_RESET_Reserved1_MASK  (0xFFFFFE00U)
#define VPU_VPU_ENC_BIT_SW_RESET_Reserved1_SHIFT (9U)
#define VPU_VPU_ENC_BIT_SW_RESET_Reserved1(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_SW_RESET_Reserved1_SHIFT)) & VPU_VPU_ENC_BIT_SW_RESET_Reserved1_MASK)
/*! @} */

/*! @name BIT_SW_RESET_STATUS - BIT_SW_RESET_STATUS */
/*! @{ */

#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_BPU_CORE_MASK (0x1U)
#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_BPU_CORE_SHIFT (0U)
#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_BPU_CORE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_BPU_CORE_SHIFT)) & VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_BPU_CORE_MASK)

#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_BPU_BUS_MASK (0x2U)
#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_BPU_BUS_SHIFT (1U)
#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_BPU_BUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_BPU_BUS_SHIFT)) & VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_BPU_BUS_MASK)

#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_VCE_CORE_MASK (0x4U)
#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_VCE_CORE_SHIFT (2U)
#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_VCE_CORE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_VCE_CORE_SHIFT)) & VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_VCE_CORE_MASK)

#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_VCE_BUS_MASK (0x8U)
#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_VCE_BUS_SHIFT (3U)
#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_VCE_BUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_VCE_BUS_SHIFT)) & VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_VCE_BUS_MASK)

#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_GDI_CORE_MASK (0x10U)
#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_GDI_CORE_SHIFT (4U)
#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_GDI_CORE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_GDI_CORE_SHIFT)) & VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_GDI_CORE_MASK)

#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_GDI_BUS_MASK (0x20U)
#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_GDI_BUS_SHIFT (5U)
#define VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_GDI_BUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_GDI_BUS_SHIFT)) & VPU_VPU_ENC_BIT_SW_RESET_STATUS_RST_STATE_GDI_BUS_MASK)
/*! @} */

/*! @name BIT_BIT_STOP_CMD - STOP_CMD */
/*! @{ */

#define VPU_VPU_ENC_BIT_BIT_STOP_CMD_BIT_BIT_STOP_CMD_MASK (0x1U)
#define VPU_VPU_ENC_BIT_BIT_STOP_CMD_BIT_BIT_STOP_CMD_SHIFT (0U)
#define VPU_VPU_ENC_BIT_BIT_STOP_CMD_BIT_BIT_STOP_CMD(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_BIT_STOP_CMD_BIT_BIT_STOP_CMD_SHIFT)) & VPU_VPU_ENC_BIT_BIT_STOP_CMD_BIT_BIT_STOP_CMD_MASK)
/*! @} */

/*! @name BIT_RESUME_CMD - RESUME_CMD */
/*! @{ */

#define VPU_VPU_ENC_BIT_RESUME_CMD_BIT_RESUME_CMD_MASK (0x1U)
#define VPU_VPU_ENC_BIT_RESUME_CMD_BIT_RESUME_CMD_SHIFT (0U)
#define VPU_VPU_ENC_BIT_RESUME_CMD_BIT_RESUME_CMD(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_RESUME_CMD_BIT_RESUME_CMD_SHIFT)) & VPU_VPU_ENC_BIT_RESUME_CMD_BIT_RESUME_CMD_MASK)
/*! @} */

/*! @name BIT_STOP_MB_STS - STOP_MB_STS */
/*! @{ */

#define VPU_VPU_ENC_BIT_STOP_MB_STS_BIT_STOP_MB_STS_MASK (0x1U)
#define VPU_VPU_ENC_BIT_STOP_MB_STS_BIT_STOP_MB_STS_SHIFT (0U)
#define VPU_VPU_ENC_BIT_STOP_MB_STS_BIT_STOP_MB_STS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_STOP_MB_STS_BIT_STOP_MB_STS_SHIFT)) & VPU_VPU_ENC_BIT_STOP_MB_STS_BIT_STOP_MB_STS_MASK)
/*! @} */

/*! @name BIT_STOP_MB_EN - STOP_MB_EN */
/*! @{ */

#define VPU_VPU_ENC_BIT_STOP_MB_EN_BIT_STOP_MB_EN_MASK (0x1U)
#define VPU_VPU_ENC_BIT_STOP_MB_EN_BIT_STOP_MB_EN_SHIFT (0U)
#define VPU_VPU_ENC_BIT_STOP_MB_EN_BIT_STOP_MB_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_STOP_MB_EN_BIT_STOP_MB_EN_SHIFT)) & VPU_VPU_ENC_BIT_STOP_MB_EN_BIT_STOP_MB_EN_MASK)
/*! @} */

/*! @name BIT_STOP_MB_ADDR - STOP_MB_ADDR */
/*! @{ */

#define VPU_VPU_ENC_BIT_STOP_MB_ADDR_BIT_STOP_MB_ADDR_MASK (0x1U)
#define VPU_VPU_ENC_BIT_STOP_MB_ADDR_BIT_STOP_MB_ADDR_SHIFT (0U)
#define VPU_VPU_ENC_BIT_STOP_MB_ADDR_BIT_STOP_MB_ADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_STOP_MB_ADDR_BIT_STOP_MB_ADDR_SHIFT)) & VPU_VPU_ENC_BIT_STOP_MB_ADDR_BIT_STOP_MB_ADDR_MASK)
/*! @} */

/*! @name BIT_FRAME_DONE_CTRL - FRAME_DONE_CTRL */
/*! @{ */

#define VPU_VPU_ENC_BIT_FRAME_DONE_CTRL_BIT_FRAME_DONE_CTRL_MASK (0x1U)
#define VPU_VPU_ENC_BIT_FRAME_DONE_CTRL_BIT_FRAME_DONE_CTRL_SHIFT (0U)
#define VPU_VPU_ENC_BIT_FRAME_DONE_CTRL_BIT_FRAME_DONE_CTRL(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_FRAME_DONE_CTRL_BIT_FRAME_DONE_CTRL_SHIFT)) & VPU_VPU_ENC_BIT_FRAME_DONE_CTRL_BIT_FRAME_DONE_CTRL_MASK)
/*! @} */

/*! @name BIT_AXI_HIGH_ADDR - BIT_AXI_HIGH_ADDR */
/*! @{ */

#define VPU_VPU_ENC_BIT_AXI_HIGH_ADDR_AXI_HIGH_ADDR_MASK (0xFFU)
#define VPU_VPU_ENC_BIT_AXI_HIGH_ADDR_AXI_HIGH_ADDR_SHIFT (0U)
#define VPU_VPU_ENC_BIT_AXI_HIGH_ADDR_AXI_HIGH_ADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_AXI_HIGH_ADDR_AXI_HIGH_ADDR_SHIFT)) & VPU_VPU_ENC_BIT_AXI_HIGH_ADDR_AXI_HIGH_ADDR_MASK)
/*! @} */

/*! @name BIT_CODE_BUF_ADDR - BIT_CODE_BUF_ADDR */
/*! @{ */

#define VPU_VPU_ENC_BIT_CODE_BUF_ADDR_CodeBufAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_BIT_CODE_BUF_ADDR_CodeBufAddr_SHIFT (0U)
#define VPU_VPU_ENC_BIT_CODE_BUF_ADDR_CodeBufAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_CODE_BUF_ADDR_CodeBufAddr_SHIFT)) & VPU_VPU_ENC_BIT_CODE_BUF_ADDR_CodeBufAddr_MASK)
/*! @} */

/*! @name BIT_WORK_BUF_ADDR - BIT_WORK_BUF_ADDR */
/*! @{ */

#define VPU_VPU_ENC_BIT_WORK_BUF_ADDR_WorkBufAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_BIT_WORK_BUF_ADDR_WorkBufAddr_SHIFT (0U)
#define VPU_VPU_ENC_BIT_WORK_BUF_ADDR_WorkBufAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_WORK_BUF_ADDR_WorkBufAddr_SHIFT)) & VPU_VPU_ENC_BIT_WORK_BUF_ADDR_WorkBufAddr_MASK)
/*! @} */

/*! @name BIT_PARA_BUF_ADDR - BIT_PARA_BUF_ADDR */
/*! @{ */

#define VPU_VPU_ENC_BIT_PARA_BUF_ADDR_ParaBufAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_BIT_PARA_BUF_ADDR_ParaBufAddr_SHIFT (0U)
#define VPU_VPU_ENC_BIT_PARA_BUF_ADDR_ParaBufAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_PARA_BUF_ADDR_ParaBufAddr_SHIFT)) & VPU_VPU_ENC_BIT_PARA_BUF_ADDR_ParaBufAddr_MASK)
/*! @} */

/*! @name BIT_BIT_STREAM_CTRL - BIT_BIT_STREAM_CTRL */
/*! @{ */

#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_SelBigEndian_MASK (0x1U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_SelBigEndian_SHIFT (0U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_SelBigEndian(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_SelBigEndian_SHIFT)) & VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_SelBigEndian_MASK)

#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_Sel64BitsEndian_MASK (0x2U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_Sel64BitsEndian_SHIFT (1U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_Sel64BitsEndian(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_Sel64BitsEndian_SHIFT)) & VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_Sel64BitsEndian_MASK)

#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_BufStsCheckDis_MASK (0x4U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_BufStsCheckDis_SHIFT (2U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_BufStsCheckDis(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_BufStsCheckDis_SHIFT)) & VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_BufStsCheckDis_MASK)

#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncBufPicFlush_MASK (0x8U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncBufPicFlush_SHIFT (3U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncBufPicFlush(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncBufPicFlush_SHIFT)) & VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncBufPicFlush_MASK)

#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncBufPicReset_MASK (0x10U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncBufPicReset_SHIFT (4U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncBufPicReset(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncBufPicReset_SHIFT)) & VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncBufPicReset_MASK)

#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncDynBufAllocEn_MASK (0x20U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncDynBufAllocEn_SHIFT (5U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncDynBufAllocEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncDynBufAllocEn_SHIFT)) & VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncDynBufAllocEn_MASK)

#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncLineBufIntEn_MASK (0x40U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncLineBufIntEn_SHIFT (6U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncLineBufIntEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncLineBufIntEn_SHIFT)) & VPU_VPU_ENC_BIT_BIT_STREAM_CTRL_EncLineBufIntEn_MASK)
/*! @} */

/*! @name BIT_FRAME_MEM_CTRL - BIT_FRAME_MEM_CTRL */
/*! @{ */

#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_SelBigEndian_MASK (0x1U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_SelBigEndian_SHIFT (0U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_SelBigEndian(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_SelBigEndian_SHIFT)) & VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_SelBigEndian_MASK)

#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_Sel64BitsEndian_MASK (0x2U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_Sel64BitsEndian_SHIFT (1U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_Sel64BitsEndian(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_Sel64BitsEndian_SHIFT)) & VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_Sel64BitsEndian_MASK)

#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_SelCInterleave_MASK (0x4U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_SelCInterleave_SHIFT (2U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_SelCInterleave(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_SelCInterleave_SHIFT)) & VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_SelCInterleave_MASK)

#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_SelNV21_MASK (0x8U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_SelNV21_SHIFT (3U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_SelNV21(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_SelNV21_SHIFT)) & VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_SelNV21_MASK)

#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_ChromaFormat400_MASK (0x1C0U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_ChromaFormat400_SHIFT (6U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_ChromaFormat400(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_ChromaFormat400_SHIFT)) & VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_ChromaFormat400_MASK)

#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_TiledMapEn_MASK (0x1E00U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_TiledMapEn_SHIFT (9U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_TiledMapEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_TiledMapEn_SHIFT)) & VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_TiledMapEn_MASK)

#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_TiledToLinearEn_MASK (0x6000U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_TiledToLinearEn_SHIFT (13U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_TiledToLinearEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_TiledToLinearEn_SHIFT)) & VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_TiledToLinearEn_MASK)

#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_Burstwritebacken_MASK (0x8000U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_Burstwritebacken_SHIFT (15U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_Burstwritebacken(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_Burstwritebacken_SHIFT)) & VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_Burstwritebacken_MASK)

#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_RotBufGdiDirect_MASK (0x10000U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_RotBufGdiDirect_SHIFT (16U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_RotBufGdiDirect(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_RotBufGdiDirect_SHIFT)) & VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_RotBufGdiDirect_MASK)

#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_TiledToLinearOnTheFlyEn_MASK (0x60000U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_TiledToLinearOnTheFlyEn_SHIFT (17U)
#define VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_TiledToLinearOnTheFlyEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_TiledToLinearOnTheFlyEn_SHIFT)) & VPU_VPU_ENC_BIT_FRAME_MEM_CTRL_TiledToLinearOnTheFlyEn_MASK)
/*! @} */

/*! @name BIT_BIT_STREAM_PARAM - BIT_BIT_STREAM_PARAM */
/*! @{ */

#define VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_SeqInitEscape_MASK (0x1U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_SeqInitEscape_SHIFT (0U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_SeqInitEscape(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_SeqInitEscape_SHIFT)) & VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_SeqInitEscape_MASK)

#define VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_Reserved0_MASK (0x2U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_Reserved0_SHIFT (1U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_Reserved0_SHIFT)) & VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_Reserved0_MASK)

#define VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_StreamEnd_MASK (0x4U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_StreamEnd_SHIFT (2U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_StreamEnd(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_StreamEnd_SHIFT)) & VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_StreamEnd_MASK)

#define VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_StreamMode_MASK (0x18U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_StreamMode_SHIFT (3U)
#define VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_StreamMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_StreamMode_SHIFT)) & VPU_VPU_ENC_BIT_BIT_STREAM_PARAM_StreamMode_MASK)
/*! @} */

/*! @name BIT_TEMP_BUF_ADDR - BIT_TEMP_BUF_ADDR */
/*! @{ */

#define VPU_VPU_ENC_BIT_TEMP_BUF_ADDR_TempBufAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_BIT_TEMP_BUF_ADDR_TempBufAddr_SHIFT (0U)
#define VPU_VPU_ENC_BIT_TEMP_BUF_ADDR_TempBufAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_TEMP_BUF_ADDR_TempBufAddr_SHIFT)) & VPU_VPU_ENC_BIT_TEMP_BUF_ADDR_TempBufAddr_MASK)
/*! @} */

/*! @name BIT_RD_PTR - BIT_RD_PTR */
/*! @{ */

#define VPU_VPU_ENC_BIT_RD_PTR_StreamRdPtr_MASK  (0xFFFFFFFFU)
#define VPU_VPU_ENC_BIT_RD_PTR_StreamRdPtr_SHIFT (0U)
#define VPU_VPU_ENC_BIT_RD_PTR_StreamRdPtr(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_RD_PTR_StreamRdPtr_SHIFT)) & VPU_VPU_ENC_BIT_RD_PTR_StreamRdPtr_MASK)
/*! @} */

/*! @name BIT_WR_PTR - BIT_WR_PTR */
/*! @{ */

#define VPU_VPU_ENC_BIT_WR_PTR_StreamWrPtr_MASK  (0xFFFFFFFFU)
#define VPU_VPU_ENC_BIT_WR_PTR_StreamWrPtr_SHIFT (0U)
#define VPU_VPU_ENC_BIT_WR_PTR_StreamWrPtr(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_WR_PTR_StreamWrPtr_SHIFT)) & VPU_VPU_ENC_BIT_WR_PTR_StreamWrPtr_MASK)
/*! @} */

/*! @name BIT_RESET_CTRL - BIT_RESET_CTRL */
/*! @{ */

#define VPU_VPU_ENC_BIT_RESET_CTRL_ResetCtrl_MASK (0x1U)
#define VPU_VPU_ENC_BIT_RESET_CTRL_ResetCtrl_SHIFT (0U)
#define VPU_VPU_ENC_BIT_RESET_CTRL_ResetCtrl(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_RESET_CTRL_ResetCtrl_SHIFT)) & VPU_VPU_ENC_BIT_RESET_CTRL_ResetCtrl_MASK)
/*! @} */

/*! @name BIT_AXI_SRAM_USE - BIT_AXI_SRAM_USE */
/*! @{ */

#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_BitAxiSecEn_MASK (0x1U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_BitAxiSecEn_SHIFT (0U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_BitAxiSecEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_AXI_SRAM_USE_BitAxiSecEn_SHIFT)) & VPU_VPU_ENC_BIT_AXI_SRAM_USE_BitAxiSecEn_MASK)

#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_IpAxiSecEn_MASK (0x2U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_IpAxiSecEn_SHIFT (1U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_IpAxiSecEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_AXI_SRAM_USE_IpAxiSecEn_SHIFT)) & VPU_VPU_ENC_BIT_AXI_SRAM_USE_IpAxiSecEn_MASK)

#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkYAxiSecEn_MASK (0x4U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkYAxiSecEn_SHIFT (2U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkYAxiSecEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkYAxiSecEn_SHIFT)) & VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkYAxiSecEn_MASK)

#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkCAxiSecEn_MASK (0x8U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkCAxiSecEn_SHIFT (3U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkCAxiSecEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkCAxiSecEn_SHIFT)) & VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkCAxiSecEn_MASK)

#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_OvlAxiSecEn_MASK (0x10U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_OvlAxiSecEn_SHIFT (4U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_OvlAxiSecEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_AXI_SRAM_USE_OvlAxiSecEn_SHIFT)) & VPU_VPU_ENC_BIT_AXI_SRAM_USE_OvlAxiSecEn_MASK)

#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_BtpAxiSecEn_MASK (0x20U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_BtpAxiSecEn_SHIFT (5U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_BtpAxiSecEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_AXI_SRAM_USE_BtpAxiSecEn_SHIFT)) & VPU_VPU_ENC_BIT_AXI_SRAM_USE_BtpAxiSecEn_MASK)

#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_Reserved0_MASK (0xC0U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_Reserved0_SHIFT (6U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_AXI_SRAM_USE_Reserved0_SHIFT)) & VPU_VPU_ENC_BIT_AXI_SRAM_USE_Reserved0_MASK)

#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_BitUseHostAddr_MASK (0x100U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_BitUseHostAddr_SHIFT (8U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_BitUseHostAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_AXI_SRAM_USE_BitUseHostAddr_SHIFT)) & VPU_VPU_ENC_BIT_AXI_SRAM_USE_BitUseHostAddr_MASK)

#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_IpUseHostAddr_MASK (0x200U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_IpUseHostAddr_SHIFT (9U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_IpUseHostAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_AXI_SRAM_USE_IpUseHostAddr_SHIFT)) & VPU_VPU_ENC_BIT_AXI_SRAM_USE_IpUseHostAddr_MASK)

#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkYHostAddr_MASK (0x400U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkYHostAddr_SHIFT (10U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkYHostAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkYHostAddr_SHIFT)) & VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkYHostAddr_MASK)

#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkCUseHostAddr_MASK (0x800U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkCUseHostAddr_SHIFT (11U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkCUseHostAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkCUseHostAddr_SHIFT)) & VPU_VPU_ENC_BIT_AXI_SRAM_USE_DbkCUseHostAddr_MASK)

#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_OvlUseHostAddr_MASK (0x1000U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_OvlUseHostAddr_SHIFT (12U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_OvlUseHostAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_AXI_SRAM_USE_OvlUseHostAddr_SHIFT)) & VPU_VPU_ENC_BIT_AXI_SRAM_USE_OvlUseHostAddr_MASK)

#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_BtpUseHostAddr_MASK (0x2000U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_BtpUseHostAddr_SHIFT (13U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_BtpUseHostAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_AXI_SRAM_USE_BtpUseHostAddr_SHIFT)) & VPU_VPU_ENC_BIT_AXI_SRAM_USE_BtpUseHostAddr_MASK)

#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_Reserved1_MASK (0xFFFFC000U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_Reserved1_SHIFT (14U)
#define VPU_VPU_ENC_BIT_AXI_SRAM_USE_Reserved1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_AXI_SRAM_USE_Reserved1_SHIFT)) & VPU_VPU_ENC_BIT_AXI_SRAM_USE_Reserved1_MASK)
/*! @} */

/*! @name BIT_BYTE_POS_FRAME_START - BIT_BYTE_POS_FRAME_START */
/*! @{ */

#define VPU_VPU_ENC_BIT_BYTE_POS_FRAME_START_BytePosFrameStart_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_BIT_BYTE_POS_FRAME_START_BytePosFrameStart_SHIFT (0U)
#define VPU_VPU_ENC_BIT_BYTE_POS_FRAME_START_BytePosFrameStart(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_BYTE_POS_FRAME_START_BytePosFrameStart_SHIFT)) & VPU_VPU_ENC_BIT_BYTE_POS_FRAME_START_BytePosFrameStart_MASK)
/*! @} */

/*! @name BIT_BYTE_POS_FRAME_END - BIT_BYTE_POS_FRAME_END */
/*! @{ */

#define VPU_VPU_ENC_BIT_BYTE_POS_FRAME_END_BytePosFrameEnd_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_BIT_BYTE_POS_FRAME_END_BytePosFrameEnd_SHIFT (0U)
#define VPU_VPU_ENC_BIT_BYTE_POS_FRAME_END_BytePosFrameEnd(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_BYTE_POS_FRAME_END_BytePosFrameEnd_SHIFT)) & VPU_VPU_ENC_BIT_BYTE_POS_FRAME_END_BytePosFrameEnd_MASK)
/*! @} */

/*! @name BIT_FRM_DIS_FLG - BIT_FRM_DIS_FLG */
/*! @{ */

#define VPU_VPU_ENC_BIT_FRM_DIS_FLG_Display_Use_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_BIT_FRM_DIS_FLG_Display_Use_SHIFT (0U)
#define VPU_VPU_ENC_BIT_FRM_DIS_FLG_Display_Use(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_FRM_DIS_FLG_Display_Use_SHIFT)) & VPU_VPU_ENC_BIT_FRM_DIS_FLG_Display_Use_MASK)
/*! @} */

/*! @name BIT_BUSY_FLAG - BIT_BUSY_FLAG */
/*! @{ */

#define VPU_VPU_ENC_BIT_BUSY_FLAG_BusyFlag_MASK  (0x1U)
#define VPU_VPU_ENC_BIT_BUSY_FLAG_BusyFlag_SHIFT (0U)
#define VPU_VPU_ENC_BIT_BUSY_FLAG_BusyFlag(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_BUSY_FLAG_BusyFlag_SHIFT)) & VPU_VPU_ENC_BIT_BUSY_FLAG_BusyFlag_MASK)
/*! @} */

/*! @name BIT_RUN_COMMAND - BIT_RUN_COMMAND */
/*! @{ */

#define VPU_VPU_ENC_BIT_RUN_COMMAND_RunCommand_MASK (0xFU)
#define VPU_VPU_ENC_BIT_RUN_COMMAND_RunCommand_SHIFT (0U)
#define VPU_VPU_ENC_BIT_RUN_COMMAND_RunCommand(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_RUN_COMMAND_RunCommand_SHIFT)) & VPU_VPU_ENC_BIT_RUN_COMMAND_RunCommand_MASK)
/*! @} */

/*! @name BIT_RUN_INDEX - BIT_RUN_INDEX */
/*! @{ */

#define VPU_VPU_ENC_BIT_RUN_INDEX_RunIndex_MASK  (0xFFFFU)
#define VPU_VPU_ENC_BIT_RUN_INDEX_RunIndex_SHIFT (0U)
#define VPU_VPU_ENC_BIT_RUN_INDEX_RunIndex(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_RUN_INDEX_RunIndex_SHIFT)) & VPU_VPU_ENC_BIT_RUN_INDEX_RunIndex_MASK)
/*! @} */

/*! @name BIT_RUN_COD_STD - BIT_RUN_COD_STD */
/*! @{ */

#define VPU_VPU_ENC_BIT_RUN_COD_STD_CodStd_MASK  (0xFU)
#define VPU_VPU_ENC_BIT_RUN_COD_STD_CodStd_SHIFT (0U)
#define VPU_VPU_ENC_BIT_RUN_COD_STD_CodStd(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_RUN_COD_STD_CodStd_SHIFT)) & VPU_VPU_ENC_BIT_RUN_COD_STD_CodStd_MASK)
/*! @} */

/*! @name BIT_INT_ENABLE - BIT_INT_ENABLE */
/*! @{ */

#define VPU_VPU_ENC_BIT_INT_ENABLE_IntEnable_MASK (0xFFFFU)
#define VPU_VPU_ENC_BIT_INT_ENABLE_IntEnable_SHIFT (0U)
#define VPU_VPU_ENC_BIT_INT_ENABLE_IntEnable(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_INT_ENABLE_IntEnable_SHIFT)) & VPU_VPU_ENC_BIT_INT_ENABLE_IntEnable_MASK)
/*! @} */

/*! @name BIT_INT_REASON - BIT_INT_REASON */
/*! @{ */

#define VPU_VPU_ENC_BIT_INT_REASON_IntReason_MASK (0xFFFFU)
#define VPU_VPU_ENC_BIT_INT_REASON_IntReason_SHIFT (0U)
#define VPU_VPU_ENC_BIT_INT_REASON_IntReason(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_INT_REASON_IntReason_SHIFT)) & VPU_VPU_ENC_BIT_INT_REASON_IntReason_MASK)
/*! @} */

/*! @name BIT_RUN_AUX_STD - BIT_RUN_AUX_STD */
/*! @{ */

#define VPU_VPU_ENC_BIT_RUN_AUX_STD_RunAuxStd_MASK (0x3U)
#define VPU_VPU_ENC_BIT_RUN_AUX_STD_RunAuxStd_SHIFT (0U)
#define VPU_VPU_ENC_BIT_RUN_AUX_STD_RunAuxStd(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_BIT_RUN_AUX_STD_RunAuxStd_SHIFT)) & VPU_VPU_ENC_BIT_RUN_AUX_STD_RunAuxStd_MASK)
/*! @} */

/*! @name CMD_ENC_HEADER_CODE - CMD_ENC_HEADER_CODE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_HeaderCode_MASK (0x3U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_HeaderCode_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_HeaderCode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_CODE_HeaderCode_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_CODE_HeaderCode_MASK)

#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_FrameCroppingFlag_MASK (0x4U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_FrameCroppingFlag_SHIFT (2U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_FrameCroppingFlag(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_CODE_FrameCroppingFlag_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_CODE_FrameCroppingFlag_MASK)

#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_UserProfileLevelEnable_MASK (0x10U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_UserProfileLevelEnable_SHIFT (4U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_UserProfileLevelEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_CODE_UserProfileLevelEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_CODE_UserProfileLevelEnable_MASK)

#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_Reserved0_MASK (0xE0U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_Reserved0_SHIFT (5U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_CODE_Reserved0_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_CODE_Reserved0_MASK)

#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_Levelldc_MASK (0xFF00U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_Levelldc_SHIFT (8U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_Levelldc(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_CODE_Levelldc_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_CODE_Levelldc_MASK)

#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_PpsId_MASK (0xFF0000U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_PpsId_SHIFT (16U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_PpsId(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_CODE_PpsId_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_CODE_PpsId_MASK)

#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_SpsId_MASK (0x1F000000U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_SpsId_SHIFT (24U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_SpsId(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_CODE_SpsId_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_CODE_SpsId_MASK)

#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_ZeroPaddingFlag_MASK (0x80000000U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_ZeroPaddingFlag_SHIFT (31U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CODE_ZeroPaddingFlag(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_CODE_ZeroPaddingFlag_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_CODE_ZeroPaddingFlag_MASK)
/*! @} */

/*! @name CMD_ENC_PARAM_CHANGE_ENABLE - CMD_ENC_PARAM_CHANGE_ENABLE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_GopNumChangeEn_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_GopNumChangeEn_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_GopNumChangeEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_GopNumChangeEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_GopNumChangeEn_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_ConstIntraQpChangeEn_MASK (0x2U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_ConstIntraQpChangeEn_SHIFT (1U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_ConstIntraQpChangeEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_ConstIntraQpChangeEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_ConstIntraQpChangeEn_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_BitRateChangeEn_MASK (0x4U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_BitRateChangeEn_SHIFT (2U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_BitRateChangeEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_BitRateChangeEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_BitRateChangeEn_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_FrameRateChangeEn_MASK (0x8U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_FrameRateChangeEn_SHIFT (3U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_FrameRateChangeEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_FrameRateChangeEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_FrameRateChangeEn_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_IntraRefreshNumChangeEn_MASK (0x10U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_IntraRefreshNumChangeEn_SHIFT (4U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_IntraRefreshNumChangeEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_IntraRefreshNumChangeEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_IntraRefreshNumChangeEn_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_Reserved0_MASK (0x20U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_Reserved0_SHIFT (5U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_Reserved0_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_Reserved0_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_HECModeChangeEn_MinMaxQPChangeEn_MASK (0x40U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_HECModeChangeEn_MinMaxQPChangeEn_SHIFT (6U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_HECModeChangeEn_MinMaxQPChangeEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_HECModeChangeEn_MinMaxQPChangeEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_ENABLE_HECModeChangeEn_MinMaxQPChangeEn_MASK)
/*! @} */

/*! @name CMD_ENC_PARA_SET_TYPE - CMD_ENC_PARA_SET_TYPE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_EncParaSetType_MASK (0x3U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_EncParaSetType_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_EncParaSetType(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_EncParaSetType_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_EncParaSetType_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_FrameCroppingFlag_MASK (0x4U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_FrameCroppingFlag_SHIFT (2U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_FrameCroppingFlag(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_FrameCroppingFlag_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_FrameCroppingFlag_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_Levelldc_MASK (0xFF00U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_Levelldc_SHIFT (8U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_Levelldc(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_Levelldc_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_Levelldc_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_PpsId_MASK (0xFF0000U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_PpsId_SHIFT (16U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_PpsId(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_PpsId_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_PpsId_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_SpsId_MASK (0x1F000000U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_SpsId_SHIFT (24U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_SpsId(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_SpsId_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_SET_TYPE_SpsId_MASK)
/*! @} */

/*! @name CMD_ENC_PIC_SRC_INDEX - CMD_ENC_PIC_SRC_INDEX */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_INDEX_EncSrcFrameIndex_MASK (0x1FU)
#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_INDEX_EncSrcFrameIndex_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_INDEX_EncSrcFrameIndex(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_SRC_INDEX_EncSrcFrameIndex_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_SRC_INDEX_EncSrcFrameIndex_MASK)
/*! @} */

/*! @name CMD_ENC_ROI_INFO - CMD_ENC_ROI_INFO */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_ROI_INFO_RoiEn_MASK  (0x1U)
#define VPU_VPU_ENC_CMD_ENC_ROI_INFO_RoiEn_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_ROI_INFO_RoiEn(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_ROI_INFO_RoiEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_ROI_INFO_RoiEn_MASK)

#define VPU_VPU_ENC_CMD_ENC_ROI_INFO_RoiPicAverageQp_MASK (0xFEU)
#define VPU_VPU_ENC_CMD_ENC_ROI_INFO_RoiPicAverageQp_SHIFT (1U)
#define VPU_VPU_ENC_CMD_ENC_ROI_INFO_RoiPicAverageQp(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_ROI_INFO_RoiPicAverageQp_SHIFT)) & VPU_VPU_ENC_CMD_ENC_ROI_INFO_RoiPicAverageQp_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_BB_START - CMD_ENC_SEQ_BB_START */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_BB_START_BitBufAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_BB_START_BitBufAddr_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_BB_START_BitBufAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_BB_START_BitBufAddr_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_BB_START_BitBufAddr_MASK)
/*! @} */

/*! @name CMD_SET_FRAME_BUF_NUM - CMD_SET_FRAME_BUF_NUM */
/*! @{ */

#define VPU_VPU_ENC_CMD_SET_FRAME_BUF_NUM_FrameBufNum_MASK (0x1FU)
#define VPU_VPU_ENC_CMD_SET_FRAME_BUF_NUM_FrameBufNum_SHIFT (0U)
#define VPU_VPU_ENC_CMD_SET_FRAME_BUF_NUM_FrameBufNum(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_BUF_NUM_FrameBufNum_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_BUF_NUM_FrameBufNum_MASK)
/*! @} */

/*! @name CMD_ENC_HEADER_BB_START - CMD_ENC_HEADER_BB_START */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_HEADER_BB_START_EncHdrBitBufStart_MASK (0xFFFFU)
#define VPU_VPU_ENC_CMD_ENC_HEADER_BB_START_EncHdrBitBufStart_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_BB_START_EncHdrBitBufStart(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_BB_START_EncHdrBitBufStart_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_BB_START_EncHdrBitBufStart_MASK)
/*! @} */

/*! @name CMD_ENC_PARAM_CHANGE_GOP_NUM - CMD_ENC_PARAM_CHANGE_GOP_NUM */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_GOP_NUM_GopNum_MASK (0xFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_GOP_NUM_GopNum_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_GOP_NUM_GopNum(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_GOP_NUM_GopNum_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_GOP_NUM_GopNum_MASK)
/*! @} */

/*! @name CMD_ENC_PIC_SRC_STRIDE - CMD_ENC_PIC_SRC_STRIDE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_STRIDE_EncSrcStride_MASK (0xFFFU)
#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_STRIDE_EncSrcStride_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_STRIDE_EncSrcStride(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_SRC_STRIDE_EncSrcStride_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_SRC_STRIDE_EncSrcStride_MASK)
/*! @} */

/*! @name CMD_ENC_ROI_QP_MAP_ADDR - CMD_ENC_ROI_QP_MAP_ADDR */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_ROI_QP_MAP_ADDR_RoiQpMapAddr_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_ROI_QP_MAP_ADDR_RoiQpMapAddr_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_ROI_QP_MAP_ADDR_RoiQpMapAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_ROI_QP_MAP_ADDR_RoiQpMapAddr_SHIFT)) & VPU_VPU_ENC_CMD_ENC_ROI_QP_MAP_ADDR_RoiQpMapAddr_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_BB_SIZE - CMD_ENC_SEQ_BB_SIZE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_BB_SIZE_BitBufSize_MASK (0x3FFFU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_BB_SIZE_BitBufSize_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_BB_SIZE_BitBufSize(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_BB_SIZE_BitBufSize_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_BB_SIZE_BitBufSize_MASK)
/*! @} */

/*! @name CMD_SET_FRAME_BUF_STRIDE - CMD_SET_FRAME_BUF_STRIDE */
/*! @{ */

#define VPU_VPU_ENC_CMD_SET_FRAME_BUF_STRIDE_LineStride_MASK (0x7FFU)
#define VPU_VPU_ENC_CMD_SET_FRAME_BUF_STRIDE_LineStride_SHIFT (0U)
#define VPU_VPU_ENC_CMD_SET_FRAME_BUF_STRIDE_LineStride(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_BUF_STRIDE_LineStride_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_BUF_STRIDE_LineStride_MASK)
/*! @} */

/*! @name CMD_ENC_HEADER_BB_SIZE - CMD_ENC_HEADER_BB_SIZE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_HEADER_BB_SIZE_EncHdrBitBufSize_MASK (0xFFFFU)
#define VPU_VPU_ENC_CMD_ENC_HEADER_BB_SIZE_EncHdrBitBufSize_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_BB_SIZE_EncHdrBitBufSize(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_BB_SIZE_EncHdrBitBufSize_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_BB_SIZE_EncHdrBitBufSize_MASK)
/*! @} */

/*! @name CMD_ENC_PARAM_CHANGE_INTRA_QP - CMD_ENC_PARAM_CHANGE_INTRA_QP */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_INTRA_QP_IntraQp_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_INTRA_QP_IntraQp_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_INTRA_QP_IntraQp(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_INTRA_QP_IntraQp_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_INTRA_QP_IntraQp_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_OPTION - CMD_ENC_SEQ_OPTION */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_Reserved0_MASK (0x3U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_Reserved0_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_Reserved0_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_Reserved0_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_AUDEnable_MASK (0x4U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_AUDEnable_SHIFT (2U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_AUDEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_AUDEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_AUDEnable_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_Reserved1_MASK (0x8U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_Reserved1_SHIFT (3U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_Reserved1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_Reserved1_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_Reserved1_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_InterviewEn_MASK (0x10U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_InterviewEn_SHIFT (4U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_InterviewEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_InterviewEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_InterviewEn_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_RcConstIntraQpEnable_MASK (0x20U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_RcConstIntraQpEnable_SHIFT (5U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_RcConstIntraQpEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_RcConstIntraQpEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_RcConstIntraQpEnable_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_Reserved2_MASK (0x40U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_Reserved2_SHIFT (6U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_Reserved2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_Reserved2_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_Reserved2_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_RcGammaSetEnable_MASK (0x80U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_RcGammaSetEnable_SHIFT (7U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_RcGammaSetEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_RcGammaSetEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_RcGammaSetEnable_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_ParasetRefreshEn_MASK (0x100U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_ParasetRefreshEn_SHIFT (8U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_ParasetRefreshEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_ParasetRefreshEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_ParasetRefreshEn_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_PrefixNalEn_MASK (0x200U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_PrefixNalEn_SHIFT (9U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_PrefixNalEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_PrefixNalEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_PrefixNalEn_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_FieldFlag_MASK (0x400U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_FieldFlag_SHIFT (10U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_FieldFlag(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_FieldFlag_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_FieldFlag_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_FieldReferenceMode_MASK (0x800U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_FieldReferenceMode_SHIFT (11U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_FieldReferenceMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_FieldReferenceMode_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_OPTION_FieldReferenceMode_MASK)
/*! @} */

/*! @name CMD_SET_FRAME_SLICE_BB_START - CMD_SET_FRAME_SLICE_BB_START */
/*! @{ */

#define VPU_VPU_ENC_CMD_SET_FRAME_SLICE_BB_START_BitBufAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_SET_FRAME_SLICE_BB_START_BitBufAddr_SHIFT (0U)
#define VPU_VPU_ENC_CMD_SET_FRAME_SLICE_BB_START_BitBufAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_SLICE_BB_START_BitBufAddr_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_SLICE_BB_START_BitBufAddr_MASK)
/*! @} */

/*! @name CMD_ENC_HEADER_FRAME_CROP_H - CMD_ENC_HEADER_FRAME_CROP_H */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_H_EncHdrFrameCropRight_MASK (0xFFFFU)
#define VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_H_EncHdrFrameCropRight_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_H_EncHdrFrameCropRight(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_H_EncHdrFrameCropRight_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_H_EncHdrFrameCropRight_MASK)

#define VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_H_EncHdrFrameCropLeft_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_H_EncHdrFrameCropLeft_SHIFT (16U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_H_EncHdrFrameCropLeft(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_H_EncHdrFrameCropLeft_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_H_EncHdrFrameCropLeft_MASK)
/*! @} */

/*! @name CMD_ENC_PARAM_CHANGE_BITRATE - CMD_ENC_PARAM_CHANGE_BITRATE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_BITRATE_BitRate_MASK (0x3FFFFU)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_BITRATE_BitRate_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_BITRATE_BitRate(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_BITRATE_BitRate_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_BITRATE_BitRate_MASK)
/*! @} */

/*! @name CMD_ENC_PARA_FRAME_CROP_H - CMD_ENC_PARA_FRAME_CROP_H */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARA_FRAME_CROP_H_EncParaFrameCropHorizontal_MASK (0xFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PARA_FRAME_CROP_H_EncParaFrameCropHorizontal_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARA_FRAME_CROP_H_EncParaFrameCropHorizontal(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_FRAME_CROP_H_EncParaFrameCropHorizontal_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_FRAME_CROP_H_EncParaFrameCropHorizontal_MASK)
/*! @} */

/*! @name CMD_ENC_PIC_QS - CMD_ENC_PIC_QS */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PIC_QS_PictureQs_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PIC_QS_PictureQs_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PIC_QS_PictureQs(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_QS_PictureQs_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_QS_PictureQs_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_COD_STD - CMD_ENC_SEQ_COD_STD */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_COD_STD_EncCodStd_MASK (0xFU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_COD_STD_EncCodStd_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_COD_STD_EncCodStd(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_COD_STD_EncCodStd_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_COD_STD_EncCodStd_MASK)
/*! @} */

/*! @name CMD_SET_FRAME_SLICE_BB_SIZE - CMD_SET_FRAME_SLICE_BB_SIZE */
/*! @{ */

#define VPU_VPU_ENC_CMD_SET_FRAME_SLICE_BB_SIZE_BitBufSize_MASK (0xFFFFU)
#define VPU_VPU_ENC_CMD_SET_FRAME_SLICE_BB_SIZE_BitBufSize_SHIFT (0U)
#define VPU_VPU_ENC_CMD_SET_FRAME_SLICE_BB_SIZE_BitBufSize(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_SLICE_BB_SIZE_BitBufSize_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_SLICE_BB_SIZE_BitBufSize_MASK)
/*! @} */

/*! @name CMD_ENC_HEADER_FRAME_CROP_V - CMD_ENC_HEADER_FRAME_CROP_V */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_V_EncHdrFrameCropBottom_MASK (0xFFFFU)
#define VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_V_EncHdrFrameCropBottom_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_V_EncHdrFrameCropBottom(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_V_EncHdrFrameCropBottom_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_V_EncHdrFrameCropBottom_MASK)

#define VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_V_EncHdrFrameCropTop_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_V_EncHdrFrameCropTop_SHIFT (16U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_V_EncHdrFrameCropTop(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_V_EncHdrFrameCropTop_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_FRAME_CROP_V_EncHdrFrameCropTop_MASK)
/*! @} */

/*! @name CMD_ENC_PARAM_CHANGE_F_RATE - CMD_ENC_PARAM_CHANGE_F_RATE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_F_RATE_FrameRateRes_MASK (0xFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_F_RATE_FrameRateRes_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_F_RATE_FrameRateRes(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_F_RATE_FrameRateRes_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_F_RATE_FrameRateRes_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_F_RATE_FrameRateDiv_Minus1_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_F_RATE_FrameRateDiv_Minus1_SHIFT (16U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_F_RATE_FrameRateDiv_Minus1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_F_RATE_FrameRateDiv_Minus1_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_F_RATE_FrameRateDiv_Minus1_MASK)
/*! @} */

/*! @name CMD_ENC_PARA_FRAME_CROP_V - CMD_ENC_PARA_FRAME_CROP_V */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARA_FRAME_CROP_V_EncParaFrameCropVertical_MASK (0xFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PARA_FRAME_CROP_V_EncParaFrameCropVertical_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARA_FRAME_CROP_V_EncParaFrameCropVertical(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_FRAME_CROP_V_EncParaFrameCropVertical_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_FRAME_CROP_V_EncParaFrameCropVertical_MASK)
/*! @} */

/*! @name CMD_ENC_PIC_ROT_MODE - CMD_ENC_PIC_ROT_MODE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_PreRotMode_MASK (0xFU)
#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_PreRotMode_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_PreRotMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_PreRotMode_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_PreRotMode_MASK)

#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_LongBurstMode_MASK (0x10U)
#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_LongBurstMode_SHIFT (4U)
#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_LongBurstMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_LongBurstMode_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_LongBurstMode_MASK)

#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_DmaMode_MASK (0x60U)
#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_DmaMode_SHIFT (5U)
#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_DmaMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_DmaMode_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_DmaMode_MASK)

#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_SelBigEndian_MASK (0x10000U)
#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_SelBigEndian_SHIFT (16U)
#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_SelBigEndian(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_SelBigEndian_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_SelBigEndian_MASK)

#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_Sel32bit_MASK (0x20000U)
#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_Sel32bit_SHIFT (17U)
#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_Sel32bit(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_Sel32bit_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_Sel32bit_MASK)

#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_CbCrInterleave_MASK (0x40000U)
#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_CbCrInterleave_SHIFT (18U)
#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_CbCrInterleave(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_CbCrInterleave_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_CbCrInterleave_MASK)

#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_Reserved0_MASK (0x180000U)
#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_Reserved0_SHIFT (19U)
#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_Reserved0_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_Reserved0_MASK)

#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_SelNV21_MASK (0x200000U)
#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_SelNV21_SHIFT (21U)
#define VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_SelNV21(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_SelNV21_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_ROT_MODE_SelNV21_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_SRC_SIZE - CMD_ENC_SEQ_SRC_SIZE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_SRC_SIZE_PictureHeight_MASK (0xFFFFU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_SRC_SIZE_PictureHeight_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_SRC_SIZE_PictureHeight(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_SRC_SIZE_PictureHeight_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_SRC_SIZE_PictureHeight_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_SRC_SIZE_PictureWidth_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_SRC_SIZE_PictureWidth_SHIFT (16U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_SRC_SIZE_PictureWidth(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_SRC_SIZE_PictureWidth_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_SRC_SIZE_PictureWidth_MASK)
/*! @} */

/*! @name CMD_SET_FRAME_AXI_BIT_ADDR - CMD_SET_FRAME_AXI_BIT_ADDR */
/*! @{ */

#define VPU_VPU_ENC_CMD_SET_FRAME_AXI_BIT_ADDR_AxiSecAddrBit_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_SET_FRAME_AXI_BIT_ADDR_AxiSecAddrBit_SHIFT (0U)
#define VPU_VPU_ENC_CMD_SET_FRAME_AXI_BIT_ADDR_AxiSecAddrBit(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_AXI_BIT_ADDR_AxiSecAddrBit_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_AXI_BIT_ADDR_AxiSecAddrBit_MASK)
/*! @} */

/*! @name CMD_ENC_HEADER_CABAC_MODE - CMD_ENC_HEADER_CABAC_MODE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_HEADER_CABAC_MODE_CabacMode_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CABAC_MODE_CabacMode_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CABAC_MODE_CabacMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_CABAC_MODE_CabacMode_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_CABAC_MODE_CabacMode_MASK)
/*! @} */

/*! @name CMD_ENC_PARAM_CHANGE_INTRA_REFRESH - CMD_ENC_PARAM_CHANGE_INTRA_REFRESH */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_INTRA_REFRESH_IntraMbRefresh_Num_MASK (0xFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_INTRA_REFRESH_IntraMbRefresh_Num_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_INTRA_REFRESH_IntraMbRefresh_Num(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_INTRA_REFRESH_IntraMbRefresh_Num_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_INTRA_REFRESH_IntraMbRefresh_Num_MASK)
/*! @} */

/*! @name CMD_ENC_PARA_SET_CABAC_MODE - CMD_ENC_PARA_SET_CABAC_MODE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARA_SET_CABAC_MODE_CabacMode_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_CABAC_MODE_CabacMode_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_CABAC_MODE_CabacMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_SET_CABAC_MODE_CabacMode_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_SET_CABAC_MODE_CabacMode_MASK)
/*! @} */

/*! @name CMD_ENC_PIC_OPTION - CMD_ENC_PIC_OPTION */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_PicSkipEn_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_PicSkipEn_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_PicSkipEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_OPTION_PicSkipEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_OPTION_PicSkipEn_MASK)

#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_IdrPic_MASK (0x2U)
#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_IdrPic_SHIFT (1U)
#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_IdrPic(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_OPTION_IdrPic_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_OPTION_IdrPic_MASK)

#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_Reserved0_MASK (0x4U)
#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_Reserved0_SHIFT (2U)
#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_OPTION_Reserved0_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_OPTION_Reserved0_MASK)

#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_enReportMBInfo_MASK (0x8U)
#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_enReportMBInfo_SHIFT (3U)
#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_enReportMBInfo(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_OPTION_enReportMBInfo_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_OPTION_enReportMBInfo_MASK)

#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_enReportMVInfo_MASK (0x10U)
#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_enReportMVInfo_SHIFT (4U)
#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_enReportMVInfo(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_OPTION_enReportMVInfo_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_OPTION_enReportMVInfo_MASK)

#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_enReportSliceInfo_MASK (0x20U)
#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_enReportSliceInfo_SHIFT (5U)
#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_enReportSliceInfo(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_OPTION_enReportSliceInfo_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_OPTION_enReportSliceInfo_MASK)

#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_FieldRunMode_MASK (0x100U)
#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_FieldRunMode_SHIFT (8U)
#define VPU_VPU_ENC_CMD_ENC_PIC_OPTION_FieldRunMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_OPTION_FieldRunMode_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_OPTION_FieldRunMode_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_SRC_F_RATE - CMD_ENC_SEQ_SRC_F_RATE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_SRC_F_RATE_FrameRateRes_MASK (0xFFFFU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_SRC_F_RATE_FrameRateRes_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_SRC_F_RATE_FrameRateRes(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_SRC_F_RATE_FrameRateRes_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_SRC_F_RATE_FrameRateRes_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_SRC_F_RATE_FrameRateDiv_Minus1_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_SRC_F_RATE_FrameRateDiv_Minus1_SHIFT (16U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_SRC_F_RATE_FrameRateDiv_Minus1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_SRC_F_RATE_FrameRateDiv_Minus1_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_SRC_F_RATE_FrameRateDiv_Minus1_MASK)
/*! @} */

/*! @name CMD_SET_FRAME_AXI_IPACDC_ADDR - CMD_SET_FRAME_AXI_IPACDC_ADDR */
/*! @{ */

#define VPU_VPU_ENC_CMD_SET_FRAME_AXI_IPACDC_ADDR_AxiSecAddrIpAcDc_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_SET_FRAME_AXI_IPACDC_ADDR_AxiSecAddrIpAcDc_SHIFT (0U)
#define VPU_VPU_ENC_CMD_SET_FRAME_AXI_IPACDC_ADDR_AxiSecAddrIpAcDc(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_AXI_IPACDC_ADDR_AxiSecAddrIpAcDc_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_AXI_IPACDC_ADDR_AxiSecAddrIpAcDc_MASK)
/*! @} */

/*! @name CMD_ENC_HEADER_CABAC_INIT_IDC - CMD_ENC_HEADER_CABAC_INIT_IDC */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_HEADER_CABAC_INIT_IDC_CabacInitIdc_MASK (0x3U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CABAC_INIT_IDC_CabacInitIdc_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CABAC_INIT_IDC_CabacInitIdc(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_CABAC_INIT_IDC_CabacInitIdc_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_CABAC_INIT_IDC_CabacInitIdc_MASK)
/*! @} */

/*! @name CMD_ENC_PARAM_CHANGE_SLICE_MODE - CMD_ENC_PARAM_CHANGE_SLICE_MODE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_SLICE_MODE_SliceMode_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_SLICE_MODE_SliceMode_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_SLICE_MODE_SliceMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_SLICE_MODE_SliceMode_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_SLICE_MODE_SliceMode_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_SLICE_MODE_SliceSizeMode_MASK (0x2U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_SLICE_MODE_SliceSizeMode_SHIFT (1U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_SLICE_MODE_SliceSizeMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_SLICE_MODE_SliceSizeMode_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_SLICE_MODE_SliceSizeMode_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_SLICE_MODE_SliceSizeNum_MASK (0xFFFCU)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_SLICE_MODE_SliceSizeNum_SHIFT (2U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_SLICE_MODE_SliceSizeNum(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_SLICE_MODE_SliceSizeNum_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_SLICE_MODE_SliceSizeNum_MASK)
/*! @} */

/*! @name CMD_ENC_PARA_SET_CABAC_INIT_IDC - CMD_ENC_PARA_SET_CABAC_INIT_IDC */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARA_SET_CABAC_INIT_IDC_CabacInitIdc_MASK (0x3U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_CABAC_INIT_IDC_CabacInitIdc_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_CABAC_INIT_IDC_CabacInitIdc(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_SET_CABAC_INIT_IDC_CabacInitIdc_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_SET_CABAC_INIT_IDC_CabacInitIdc_MASK)
/*! @} */

/*! @name CMD_ENC_PIC_BB_START - CMD_ENC_PIC_BB_START */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PIC_BB_START_EncPicBitBufStart_MASK (0xFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PIC_BB_START_EncPicBitBufStart_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PIC_BB_START_EncPicBitBufStart(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_BB_START_EncPicBitBufStart_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_BB_START_EncPicBitBufStart_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_MP4_PARA - CMD_ENC_SEQ_MP4_PARA */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_DataPartEn_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_DataPartEn_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_DataPartEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_DataPartEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_DataPartEn_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_RevVlcEn_MASK (0x2U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_RevVlcEn_SHIFT (1U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_RevVlcEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_RevVlcEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_RevVlcEn_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_IntraDcVlcThr_MASK (0x1CU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_IntraDcVlcThr_SHIFT (2U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_IntraDcVlcThr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_IntraDcVlcThr_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_IntraDcVlcThr_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_mp4HecEnable_MASK (0x20U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_mp4HecEnable_SHIFT (5U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_mp4HecEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_mp4HecEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_mp4HecEnable_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_mp4Verid_MASK (0x40U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_mp4Verid_SHIFT (6U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_mp4Verid(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_mp4Verid_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_MP4_PARA_mp4Verid_MASK)
/*! @} */

/*! @name CMD_SET_FRAME_AXI_DBKY_ADDR - CMD_SET_FRAME_AXI_DBKY_ADDR */
/*! @{ */

#define VPU_VPU_ENC_CMD_SET_FRAME_AXI_DBKY_ADDR_AxiSecAddrDbkY_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_SET_FRAME_AXI_DBKY_ADDR_AxiSecAddrDbkY_SHIFT (0U)
#define VPU_VPU_ENC_CMD_SET_FRAME_AXI_DBKY_ADDR_AxiSecAddrDbkY(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_AXI_DBKY_ADDR_AxiSecAddrDbkY_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_AXI_DBKY_ADDR_AxiSecAddrDbkY_MASK)
/*! @} */

/*! @name CMD_ENC_HEADER_TRANSFORM_8X8 - CMD_ENC_HEADER_TRANSFORM_8X8 */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_HEADER_TRANSFORM_8X8_Transform8x8_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_TRANSFORM_8X8_Transform8x8_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_TRANSFORM_8X8_Transform8x8(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_TRANSFORM_8X8_Transform8x8_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_TRANSFORM_8X8_Transform8x8_MASK)
/*! @} */

/*! @name CMD_ENC_PARAM_CHANGE_HEC_MODE - CMD_ENC_PARAM_CHANGE_HEC_MODE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_HEC_MODE_HECModeEnable_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_HEC_MODE_HECModeEnable_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_HEC_MODE_HECModeEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_HEC_MODE_HECModeEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_HEC_MODE_HECModeEnable_MASK)
/*! @} */

/*! @name CMD_ENC_PARA_SET_TRANSFORM_8X8 - CMD_ENC_PARA_SET_TRANSFORM_8X8 */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TRANSFORM_8X8_Transform8x8_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TRANSFORM_8X8_Transform8x8_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_TRANSFORM_8X8_Transform8x8(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_SET_TRANSFORM_8X8_Transform8x8_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_SET_TRANSFORM_8X8_Transform8x8_MASK)
/*! @} */

/*! @name CMD_ENC_PIC_BB_SIZE - CMD_ENC_PIC_BB_SIZE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PIC_BB_SIZE_EncPicBitBufSize_MASK (0xFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PIC_BB_SIZE_EncPicBitBufSize_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PIC_BB_SIZE_EncPicBitBufSize(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_BB_SIZE_EncPicBitBufSize_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_BB_SIZE_EncPicBitBufSize_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_263_PARA - CMD_ENC_SEQ_263_PARA */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_T_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_T_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_T(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_T_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_T_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_K_MASK (0x2U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_K_SHIFT (1U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_K(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_K_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_K_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_J_MASK (0x4U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_J_SHIFT (2U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_J(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_J_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_J_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_I_MASK (0x8U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_I_SHIFT (3U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_I(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_I_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_263_PARA_Annex_I_MASK)
/*! @} */

/*! @name CMD_SET_FRAME_AXI_DBKC_ADDR - CMD_SET_FRAME_AXI_DBKC_ADDR */
/*! @{ */

#define VPU_VPU_ENC_CMD_SET_FRAME_AXI_DBKC_ADDR_AxiSecAddrDbkC_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_SET_FRAME_AXI_DBKC_ADDR_AxiSecAddrDbkC_SHIFT (0U)
#define VPU_VPU_ENC_CMD_SET_FRAME_AXI_DBKC_ADDR_AxiSecAddrDbkC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_AXI_DBKC_ADDR_AxiSecAddrDbkC_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_AXI_DBKC_ADDR_AxiSecAddrDbkC_MASK)
/*! @} */

/*! @name CMD_ENC_HEADER_CHROMA_FORMAT - CMD_ENC_HEADER_CHROMA_FORMAT */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_HEADER_CHROMA_FORMAT_ChromaFormat_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CHROMA_FORMAT_ChromaFormat_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_CHROMA_FORMAT_ChromaFormat(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_CHROMA_FORMAT_ChromaFormat_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_CHROMA_FORMAT_ChromaFormat_MASK)
/*! @} */

/*! @name CMD_ENC_PARAM_CHANGE_CABAC_MODE - CMD_ENC_PARAM_CHANGE_CABAC_MODE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_CABAC_MODE_CabacMode_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_CABAC_MODE_CabacMode_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_CABAC_MODE_CabacMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_CABAC_MODE_CabacMode_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_CABAC_MODE_CabacMode_MASK)
/*! @} */

/*! @name CMD_ENC_PARA_SET_CHROMA_FORMAT - CMD_ENC_PARA_SET_CHROMA_FORMAT */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARA_SET_CHROMA_FORMAT_ChromaFormat_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_CHROMA_FORMAT_ChromaFormat_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_CHROMA_FORMAT_ChromaFormat(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_SET_CHROMA_FORMAT_ChromaFormat_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_SET_CHROMA_FORMAT_ChromaFormat_MASK)
/*! @} */

/*! @name CMD_ENC_PIC_PARA_BASE_ADDR - CMD_ENC_PIC_PARA_BASE_ADDR */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PIC_PARA_BASE_ADDR_EncPicParaBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PIC_PARA_BASE_ADDR_EncPicParaBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PIC_PARA_BASE_ADDR_EncPicParaBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_PARA_BASE_ADDR_EncPicParaBaseAddr_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_PARA_BASE_ADDR_EncPicParaBaseAddr_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_264_PARA - CMD_ENC_SEQ_264_PARA */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_ChromaQpOffset_MASK (0x1FU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_ChromaQpOffset_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_ChromaQpOffset(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_ChromaQpOffset_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_ChromaQpOffset_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_ConstIntraFlag_MASK (0x20U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_ConstIntraFlag_SHIFT (5U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_ConstIntraFlag(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_ConstIntraFlag_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_ConstIntraFlag_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_DisableDeblk_MASK (0xC0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_DisableDeblk_SHIFT (6U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_DisableDeblk(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_DisableDeblk_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_DisableDeblk_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_DeblkAlphaOffset_MASK (0xF00U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_DeblkAlphaOffset_SHIFT (8U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_DeblkAlphaOffset(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_DeblkAlphaOffset_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_DeblkAlphaOffset_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_DeblkBetaOffset_MASK (0xF000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_DeblkBetaOffset_SHIFT (12U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_DeblkBetaOffset(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_DeblkBetaOffset_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_264_PARA_DeblkBetaOffset_MASK)
/*! @} */

/*! @name CMD_ENC_HEADER_FIELD_FLAG - CMD_ENC_HEADER_FIELD_FLAG */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_HEADER_FIELD_FLAG_FieldFlag_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_FIELD_FLAG_FieldFlag_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_FIELD_FLAG_FieldFlag(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_FIELD_FLAG_FieldFlag_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_FIELD_FLAG_FieldFlag_MASK)

#define VPU_VPU_ENC_CMD_ENC_HEADER_FIELD_FLAG_FieldReferenceMode_MASK (0x2U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_FIELD_FLAG_FieldReferenceMode_SHIFT (1U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_FIELD_FLAG_FieldReferenceMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_FIELD_FLAG_FieldReferenceMode_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_FIELD_FLAG_FieldReferenceMode_MASK)
/*! @} */

/*! @name CMD_ENC_PARA_SET_FIELD_FLAG - CMD_ENC_PARA_SET_FIELD_FLAG */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARA_SET_FIELD_FLAG_FieldFlag_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_FIELD_FLAG_FieldFlag_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_FIELD_FLAG_FieldFlag(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_SET_FIELD_FLAG_FieldFlag_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_SET_FIELD_FLAG_FieldFlag_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARA_SET_FIELD_FLAG_FieldReferenceMode_MASK (0x2U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_FIELD_FLAG_FieldReferenceMode_SHIFT (1U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_FIELD_FLAG_FieldReferenceMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_SET_FIELD_FLAG_FieldReferenceMode_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_SET_FIELD_FLAG_FieldReferenceMode_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_SLICE_MODE - CMD_ENC_SEQ_SLICE_MODE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_SLICE_MODE_SliceMode_MASK (0x3U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_SLICE_MODE_SliceMode_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_SLICE_MODE_SliceMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_SLICE_MODE_SliceMode_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_SLICE_MODE_SliceMode_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_SLICE_MODE_SliceSizeNum_MASK (0xFFFFFFFCU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_SLICE_MODE_SliceSizeNum_SHIFT (2U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_SLICE_MODE_SliceSizeNum(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_SLICE_MODE_SliceSizeNum_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_SLICE_MODE_SliceSizeNum_MASK)
/*! @} */

/*! @name CMD_ENC_HEADER_PROFILE - CMD_ENC_HEADER_PROFILE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_HEADER_PROFILE_ProfileIdc_MASK (0x3U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_PROFILE_ProfileIdc_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_PROFILE_ProfileIdc(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_PROFILE_ProfileIdc_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_PROFILE_ProfileIdc_MASK)
/*! @} */

/*! @name CMD_ENC_PARA_SET_PROFILE - CMD_ENC_PARA_SET_PROFILE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARA_SET_PROFILE_ProfileIdc_MASK (0x3U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_PROFILE_ProfileIdc_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_PROFILE_ProfileIdc(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_SET_PROFILE_ProfileIdc_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_SET_PROFILE_ProfileIdc_MASK)
/*! @} */

/*! @name CMD_ENC_PIC_SRC_ADDR_Y - CMD_ENC_PIC_SRC_ADDR_Y */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_ADDR_Y_SrcAddrY_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_ADDR_Y_SrcAddrY_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_ADDR_Y_SrcAddrY(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_SRC_ADDR_Y_SrcAddrY_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_SRC_ADDR_Y_SrcAddrY_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_GOP_NUM - CMD_ENC_SEQ_GOP_NUM */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_EncGopNum_MASK (0x3FFU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_EncGopNum_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_EncGopNum(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_EncGopNum_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_EncGopNum_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_RcGopIQpOffset_MASK (0xF0000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_RcGopIQpOffset_SHIFT (16U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_RcGopIQpOffset(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_RcGopIQpOffset_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_RcGopIQpOffset_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_RcGopIQpOffsetEn_MASK (0x100000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_RcGopIQpOffsetEn_SHIFT (20U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_RcGopIQpOffsetEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_RcGopIQpOffsetEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_RcGopIQpOffsetEn_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_IDRInterval_MASK (0x1FE00000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_IDRInterval_SHIFT (21U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_IDRInterval(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_IDRInterval_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_GOP_NUM_IDRInterval_MASK)
/*! @} */

/*! @name CMD_SET_FRAME_CACHE_SIZE - CMD_SET_FRAME_CACHE_SIZE */
/*! @{ */

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaCacheSizeY_MASK (0xFU)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaCacheSizeY_SHIFT (0U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaCacheSizeY(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaCacheSizeY_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaCacheSizeY_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaCacheSizeX_MASK (0xF0U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaCacheSizeX_SHIFT (4U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaCacheSizeX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaCacheSizeX_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaCacheSizeX_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaPageSizeY_MASK (0xF00U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaPageSizeY_SHIFT (8U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaPageSizeY(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaPageSizeY_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaPageSizeY_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaPageSizeX_MASK (0xF000U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaPageSizeX_SHIFT (12U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaPageSizeX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaPageSizeX_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_ChromaPageSizeX_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaCacheSizeY_MASK (0xF0000U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaCacheSizeY_SHIFT (16U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaCacheSizeY(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaCacheSizeY_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaCacheSizeY_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaCacheSizeX_MASK (0xF00000U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaCacheSizeX_SHIFT (20U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaCacheSizeX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaCacheSizeX_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaCacheSizeX_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaPageSizeY_MASK (0xF000000U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaPageSizeY_SHIFT (24U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaPageSizeY(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaPageSizeY_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaPageSizeY_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaPageSizeX_MASK (0xF0000000U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaPageSizeX_SHIFT (28U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaPageSizeX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaPageSizeX_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_SIZE_LumaPageSizeX_MASK)
/*! @} */

/*! @name CMD_ENC_HEADER_SCALING_LIST - CMD_ENC_HEADER_SCALING_LIST */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_HEADER_SCALING_LIST_ScalingMatrixPresent_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_SCALING_LIST_ScalingMatrixPresent_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_SCALING_LIST_ScalingMatrixPresent(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_SCALING_LIST_ScalingMatrixPresent_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_SCALING_LIST_ScalingMatrixPresent_MASK)

#define VPU_VPU_ENC_CMD_ENC_HEADER_SCALING_LIST_ScalingListPresent_MASK (0xFF00U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_SCALING_LIST_ScalingListPresent_SHIFT (8U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_SCALING_LIST_ScalingListPresent(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_SCALING_LIST_ScalingListPresent_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_SCALING_LIST_ScalingListPresent_MASK)

#define VPU_VPU_ENC_CMD_ENC_HEADER_SCALING_LIST_ScalingListDefault_MASK (0xFF0000U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_SCALING_LIST_ScalingListDefault_SHIFT (16U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_SCALING_LIST_ScalingListDefault(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_SCALING_LIST_ScalingListDefault_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_SCALING_LIST_ScalingListDefault_MASK)
/*! @} */

/*! @name CMD_ENC_PARA_SET_SCALING_LIST - CMD_ENC_PARA_SET_SCALING_LIST */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARA_SET_SCALING_LIST_ScalingMatrixPresent_MASK (0x1U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_SCALING_LIST_ScalingMatrixPresent_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_SCALING_LIST_ScalingMatrixPresent(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_SET_SCALING_LIST_ScalingMatrixPresent_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_SET_SCALING_LIST_ScalingMatrixPresent_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARA_SET_SCALING_LIST_ScalingListPresent_MASK (0xFF00U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_SCALING_LIST_ScalingListPresent_SHIFT (8U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_SCALING_LIST_ScalingListPresent(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_SET_SCALING_LIST_ScalingListPresent_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_SET_SCALING_LIST_ScalingListPresent_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARA_SET_SCALING_LIST_ScalingListDefault_MASK (0xFF0000U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_SCALING_LIST_ScalingListDefault_SHIFT (16U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_SCALING_LIST_ScalingListDefault(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_SET_SCALING_LIST_ScalingListDefault_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_SET_SCALING_LIST_ScalingListDefault_MASK)
/*! @} */

/*! @name CMD_ENC_PIC_SRC_ADDR_CB - CMD_ENC_PIC_SRC_ADDR_CB */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_ADDR_CB_SrcAddrCb_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_ADDR_CB_SrcAddrCb_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_ADDR_CB_SrcAddrCb(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_SRC_ADDR_CB_SrcAddrCb_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_SRC_ADDR_CB_SrcAddrCb_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_RC_PARA - CMD_ENC_SEQ_RC_PARA */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_HvsMaxDeltaQp_MASK (0xFU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_HvsMaxDeltaQp_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_HvsMaxDeltaQp(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_HvsMaxDeltaQp_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_HvsMaxDeltaQp_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_Reserved0_MASK (0xFFF0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_Reserved0_SHIFT (4U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_Reserved0_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_Reserved0_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_InitDelay_MASK (0x7FFF0000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_InitDelay_SHIFT (16U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_InitDelay(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_InitDelay_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_InitDelay_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_SkipDisable_MASK (0x80000000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_SkipDisable_SHIFT (31U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_SkipDisable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_SkipDisable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA_SkipDisable_MASK)
/*! @} */

/*! @name CMD_SET_FRAME_CACHE_CONFIG - CMD_SET_FRAME_CACHE_CONFIG */
/*! @{ */

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheBypassMC_MASK (0x1U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheBypassMC_SHIFT (0U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheBypassMC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheBypassMC_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheBypassMC_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_Reserved0_MASK (0x2U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_Reserved0_SHIFT (1U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_Reserved0_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_Reserved0_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheMapType_MASK (0x4U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheMapType_SHIFT (2U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheMapType(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheMapType_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheMapType_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheBurstMode_MASK (0x8U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheBurstMode_SHIFT (3U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheBurstMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheBurstMode_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheBurstMode_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_Reserved1_MASK (0x10U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_Reserved1_SHIFT (4U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_Reserved1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_Reserved1_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_Reserved1_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheWayChroma_MASK (0x60U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheWayChroma_SHIFT (5U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheWayChroma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheWayChroma_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheWayChroma_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheWayLuma_MASK (0x180U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheWayLuma_SHIFT (7U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheWayLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheWayLuma_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheWayLuma_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheLineMerge_MASK (0x600U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheLineMerge_SHIFT (9U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheLineMerge(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheLineMerge_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_CacheLineMerge_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_Reserved2_MASK (0xFFFFF800U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_Reserved2_SHIFT (11U)
#define VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_Reserved2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_Reserved2_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_CACHE_CONFIG_Reserved2_MASK)
/*! @} */

/*! @name CMD_ENC_HEADER_QMAT_BASE - CMD_ENC_HEADER_QMAT_BASE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_HEADER_QMAT_BASE_ScalingListParamBase_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_HEADER_QMAT_BASE_ScalingListParamBase_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_HEADER_QMAT_BASE_ScalingListParamBase(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_HEADER_QMAT_BASE_ScalingListParamBase_SHIFT)) & VPU_VPU_ENC_CMD_ENC_HEADER_QMAT_BASE_ScalingListParamBase_MASK)
/*! @} */

/*! @name CMD_ENC_PARA_SET_QMAT_BASE - CMD_ENC_PARA_SET_QMAT_BASE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARA_SET_QMAT_BASE_ScalingListParamBase_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_QMAT_BASE_ScalingListParamBase_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARA_SET_QMAT_BASE_ScalingListParamBase(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARA_SET_QMAT_BASE_ScalingListParamBase_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARA_SET_QMAT_BASE_ScalingListParamBase_MASK)
/*! @} */

/*! @name CMD_ENC_PIC_SRC_ADDR_CR - CMD_ENC_PIC_SRC_ADDR_CR */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_ADDR_CR_SrcAddrCr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_ADDR_CR_SrcAddrCr_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_ADDR_CR_SrcAddrCr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_SRC_ADDR_CR_SrcAddrCr_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_SRC_ADDR_CR_SrcAddrCr_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_RC_BUF_SIZE - CMD_ENC_SEQ_RC_BUF_SIZE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_BUF_SIZE_VbvBufSize_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_BUF_SIZE_VbvBufSize_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_BUF_SIZE_VbvBufSize(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_BUF_SIZE_VbvBufSize_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_BUF_SIZE_VbvBufSize_MASK)
/*! @} */

/*! @name CMD_SET_FRAME_MB_BUF_BASE - CMD_SET_FRAME_MB_BUF_BASE */
/*! @{ */

#define VPU_VPU_ENC_CMD_SET_FRAME_MB_BUF_BASE_MbDataBufBase_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_SET_FRAME_MB_BUF_BASE_MbDataBufBase_SHIFT (0U)
#define VPU_VPU_ENC_CMD_SET_FRAME_MB_BUF_BASE_MbDataBufBase(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_MB_BUF_BASE_MbDataBufBase_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_MB_BUF_BASE_MbDataBufBase_MASK)
/*! @} */

/*! @name CMD_ENC_PARAM_CHANGE_PPS_ID - CMD_ENC_PARAM_CHANGE_PPS_ID */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_PPS_ID_PpsId_MASK (0xFFU)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_PPS_ID_PpsId_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_PPS_ID_PpsId(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_PPS_ID_PpsId_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_PPS_ID_PpsId_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_INTRA_REFRESH - CMD_ENC_SEQ_INTRA_REFRESH */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_IntraMbRefresh_Num_MASK (0xFFFFU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_IntraMbRefresh_Num_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_IntraMbRefresh_Num(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_IntraMbRefresh_Num_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_IntraMbRefresh_Num_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_ConscIntraRefreshEn_MASK (0x10000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_ConscIntraRefreshEn_SHIFT (16U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_ConscIntraRefreshEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_ConscIntraRefreshEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_ConscIntraRefreshEn_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_CountIntraMbEn_MASK (0x20000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_CountIntraMbEn_SHIFT (17U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_CountIntraMbEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_CountIntraMbEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_CountIntraMbEn_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_FieldSeqIntraRefreshEn_MASK (0x40000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_FieldSeqIntraRefreshEn_SHIFT (18U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_FieldSeqIntraRefreshEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_FieldSeqIntraRefreshEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_REFRESH_FieldSeqIntraRefreshEn_MASK)
/*! @} */

/*! @name CMD_SET_FRAME_MAX_DEC_SIZE - CMD_SET_FRAME_MAX_DEC_SIZE */
/*! @{ */

#define VPU_VPU_ENC_CMD_SET_FRAME_MAX_DEC_SIZE_MaxMBY_MASK (0xFFU)
#define VPU_VPU_ENC_CMD_SET_FRAME_MAX_DEC_SIZE_MaxMBY_SHIFT (0U)
#define VPU_VPU_ENC_CMD_SET_FRAME_MAX_DEC_SIZE_MaxMBY(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_MAX_DEC_SIZE_MaxMBY_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_MAX_DEC_SIZE_MaxMBY_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_MAX_DEC_SIZE_MaxMBX_MASK (0xFF00U)
#define VPU_VPU_ENC_CMD_SET_FRAME_MAX_DEC_SIZE_MaxMBX_SHIFT (8U)
#define VPU_VPU_ENC_CMD_SET_FRAME_MAX_DEC_SIZE_MaxMBX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_MAX_DEC_SIZE_MaxMBX_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_MAX_DEC_SIZE_MaxMBX_MASK)

#define VPU_VPU_ENC_CMD_SET_FRAME_MAX_DEC_SIZE_MaxMBs_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_CMD_SET_FRAME_MAX_DEC_SIZE_MaxMBs_SHIFT (16U)
#define VPU_VPU_ENC_CMD_SET_FRAME_MAX_DEC_SIZE_MaxMBs(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_MAX_DEC_SIZE_MaxMBs_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_MAX_DEC_SIZE_MaxMBs_MASK)
/*! @} */

/*! @name CMD_ENC_PARAM_CHANGE_MIN_MAX_QP - CMD_ENC_PARAM_CHANGE_MIN_MAX_QP */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpI_MASK (0x3FU)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpI_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpI(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpI_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpI_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpIEnable_MASK (0x40U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpIEnable_SHIFT (6U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpIEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpIEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpIEnable_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved0_MASK (0x80U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved0_SHIFT (7U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved0_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved0_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpI_MASK (0x3F00U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpI_SHIFT (8U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpI(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpI_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpI_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpIEnable_MASK (0x4000U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpIEnable_SHIFT (14U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpIEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpIEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpIEnable_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved1_MASK (0x8000U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved1_SHIFT (15U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved1_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved1_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpP_MASK (0x3F0000U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpP_SHIFT (16U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpP(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpP_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpP_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpPEnable_MASK (0x400000U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpPEnable_SHIFT (22U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpPEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpPEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MaxQpPEnable_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved2_MASK (0x800000U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved2_SHIFT (23U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved2_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved2_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpP_MASK (0x3F000000U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpP_SHIFT (24U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpP(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpP_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpP_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpPEnable_MASK (0x40000000U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpPEnable_SHIFT (30U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpPEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpPEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_MinQpPEnable_MASK)

#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved3_MASK (0x80000000U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved3_SHIFT (31U)
#define VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved3_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PARAM_CHANGE_MIN_MAX_QP_Reserved3_MASK)
/*! @} */

/*! @name CMD_SET_FRAME_DELAY - CMD_SET_FRAME_DELAY */
/*! @{ */

#define VPU_VPU_ENC_CMD_SET_FRAME_DELAY_FrameDelay_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_SET_FRAME_DELAY_FrameDelay_SHIFT (0U)
#define VPU_VPU_ENC_CMD_SET_FRAME_DELAY_FrameDelay(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_SET_FRAME_DELAY_FrameDelay_SHIFT)) & VPU_VPU_ENC_CMD_SET_FRAME_DELAY_FrameDelay_MASK)
/*! @} */

/*! @name RET_ENC_HEADER_SUCCESS - RET_ENC_HEADER_SUCCESS */
/*! @{ */

#define VPU_VPU_ENC_RET_ENC_HEADER_SUCCESS_RetStatus_MASK (0x1U)
#define VPU_VPU_ENC_RET_ENC_HEADER_SUCCESS_RetStatus_SHIFT (0U)
#define VPU_VPU_ENC_RET_ENC_HEADER_SUCCESS_RetStatus(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_HEADER_SUCCESS_RetStatus_SHIFT)) & VPU_VPU_ENC_RET_ENC_HEADER_SUCCESS_RetStatus_MASK)

#define VPU_VPU_ENC_RET_ENC_HEADER_SUCCESS_Reserved0_MASK (0x7FFFFFFEU)
#define VPU_VPU_ENC_RET_ENC_HEADER_SUCCESS_Reserved0_SHIFT (1U)
#define VPU_VPU_ENC_RET_ENC_HEADER_SUCCESS_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_HEADER_SUCCESS_Reserved0_SHIFT)) & VPU_VPU_ENC_RET_ENC_HEADER_SUCCESS_Reserved0_MASK)

#define VPU_VPU_ENC_RET_ENC_HEADER_SUCCESS_MemoryAccessViolation_MASK (0x80000000U)
#define VPU_VPU_ENC_RET_ENC_HEADER_SUCCESS_MemoryAccessViolation_SHIFT (31U)
#define VPU_VPU_ENC_RET_ENC_HEADER_SUCCESS_MemoryAccessViolation(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_HEADER_SUCCESS_MemoryAccessViolation_SHIFT)) & VPU_VPU_ENC_RET_ENC_HEADER_SUCCESS_MemoryAccessViolation_MASK)
/*! @} */

/*! @name RET_ENC_PAPAM_CHANGE_SUCCESS - RET_ENC_PAPAM_CHANGE_SUCCESS */
/*! @{ */

#define VPU_VPU_ENC_RET_ENC_PAPAM_CHANGE_SUCCESS_RetStatus_MASK (0x1U)
#define VPU_VPU_ENC_RET_ENC_PAPAM_CHANGE_SUCCESS_RetStatus_SHIFT (0U)
#define VPU_VPU_ENC_RET_ENC_PAPAM_CHANGE_SUCCESS_RetStatus(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_PAPAM_CHANGE_SUCCESS_RetStatus_SHIFT)) & VPU_VPU_ENC_RET_ENC_PAPAM_CHANGE_SUCCESS_RetStatus_MASK)

#define VPU_VPU_ENC_RET_ENC_PAPAM_CHANGE_SUCCESS_MemoryAccessViolation_MASK (0x80000000U)
#define VPU_VPU_ENC_RET_ENC_PAPAM_CHANGE_SUCCESS_MemoryAccessViolation_SHIFT (31U)
#define VPU_VPU_ENC_RET_ENC_PAPAM_CHANGE_SUCCESS_MemoryAccessViolation(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_PAPAM_CHANGE_SUCCESS_MemoryAccessViolation_SHIFT)) & VPU_VPU_ENC_RET_ENC_PAPAM_CHANGE_SUCCESS_MemoryAccessViolation_MASK)
/*! @} */

/*! @name RET_ENC_PARA_SET_SIZE - RET_ENC_PARA_SET_SIZE */
/*! @{ */

#define VPU_VPU_ENC_RET_ENC_PARA_SET_SIZE_EncParaSetSize_MASK (0x1FFU)
#define VPU_VPU_ENC_RET_ENC_PARA_SET_SIZE_EncParaSetSize_SHIFT (0U)
#define VPU_VPU_ENC_RET_ENC_PARA_SET_SIZE_EncParaSetSize(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_PARA_SET_SIZE_EncParaSetSize_SHIFT)) & VPU_VPU_ENC_RET_ENC_PARA_SET_SIZE_EncParaSetSize_MASK)
/*! @} */

/*! @name RET_ENC_PIC_FRAME_NUM - RET_ENC_PIC_FRAME_NUM */
/*! @{ */

#define VPU_VPU_ENC_RET_ENC_PIC_FRAME_NUM_EncFrameNum_MASK (0xFFFFU)
#define VPU_VPU_ENC_RET_ENC_PIC_FRAME_NUM_EncFrameNum_SHIFT (0U)
#define VPU_VPU_ENC_RET_ENC_PIC_FRAME_NUM_EncFrameNum(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_PIC_FRAME_NUM_EncFrameNum_SHIFT)) & VPU_VPU_ENC_RET_ENC_PIC_FRAME_NUM_EncFrameNum_MASK)
/*! @} */

/*! @name RET_ENC_SEQ_END_SUCCESS - RET_ENC_SEQ_END_SUCCESS */
/*! @{ */

#define VPU_VPU_ENC_RET_ENC_SEQ_END_SUCCESS_RetStatus_MASK (0x1U)
#define VPU_VPU_ENC_RET_ENC_SEQ_END_SUCCESS_RetStatus_SHIFT (0U)
#define VPU_VPU_ENC_RET_ENC_SEQ_END_SUCCESS_RetStatus(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_SEQ_END_SUCCESS_RetStatus_SHIFT)) & VPU_VPU_ENC_RET_ENC_SEQ_END_SUCCESS_RetStatus_MASK)

#define VPU_VPU_ENC_RET_ENC_SEQ_END_SUCCESS_MemoryAccessViolation_MASK (0x80000000U)
#define VPU_VPU_ENC_RET_ENC_SEQ_END_SUCCESS_MemoryAccessViolation_SHIFT (31U)
#define VPU_VPU_ENC_RET_ENC_SEQ_END_SUCCESS_MemoryAccessViolation(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_SEQ_END_SUCCESS_MemoryAccessViolation_SHIFT)) & VPU_VPU_ENC_RET_ENC_SEQ_END_SUCCESS_MemoryAccessViolation_MASK)
/*! @} */

/*! @name RET_FW_VER_NUM - RET_FW_VER_NUM */
/*! @{ */

#define VPU_VPU_ENC_RET_FW_VER_NUM_VersionID_MASK (0xFFFFU)
#define VPU_VPU_ENC_RET_FW_VER_NUM_VersionID_SHIFT (0U)
#define VPU_VPU_ENC_RET_FW_VER_NUM_VersionID(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_FW_VER_NUM_VersionID_SHIFT)) & VPU_VPU_ENC_RET_FW_VER_NUM_VersionID_MASK)

#define VPU_VPU_ENC_RET_FW_VER_NUM_ProductID_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_RET_FW_VER_NUM_ProductID_SHIFT (16U)
#define VPU_VPU_ENC_RET_FW_VER_NUM_ProductID(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_FW_VER_NUM_ProductID_SHIFT)) & VPU_VPU_ENC_RET_FW_VER_NUM_ProductID_MASK)
/*! @} */

/*! @name RET_SET_FRAME_SUCCESS - RET_SET_FRAME_SUCCESS */
/*! @{ */

#define VPU_VPU_ENC_RET_SET_FRAME_SUCCESS_RetStatus_MASK (0x1U)
#define VPU_VPU_ENC_RET_SET_FRAME_SUCCESS_RetStatus_SHIFT (0U)
#define VPU_VPU_ENC_RET_SET_FRAME_SUCCESS_RetStatus(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_SET_FRAME_SUCCESS_RetStatus_SHIFT)) & VPU_VPU_ENC_RET_SET_FRAME_SUCCESS_RetStatus_MASK)

#define VPU_VPU_ENC_RET_SET_FRAME_SUCCESS_MemoryAccessViolation_MASK (0x80000000U)
#define VPU_VPU_ENC_RET_SET_FRAME_SUCCESS_MemoryAccessViolation_SHIFT (31U)
#define VPU_VPU_ENC_RET_SET_FRAME_SUCCESS_MemoryAccessViolation(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_SET_FRAME_SUCCESS_MemoryAccessViolation_SHIFT)) & VPU_VPU_ENC_RET_SET_FRAME_SUCCESS_MemoryAccessViolation_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_INTRA_QP - CMD_ENC_SEQ_INTRA_QP */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_QP_IntraQp_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_QP_IntraQp_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_QP_IntraQp(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_QP_IntraQp_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_QP_IntraQp_MASK)
/*! @} */

/*! @name RET_ENC_PARA_SET_SUCCESS - RET_ENC_PARA_SET_SUCCESS */
/*! @{ */

#define VPU_VPU_ENC_RET_ENC_PARA_SET_SUCCESS_RetStatus_MASK (0x1U)
#define VPU_VPU_ENC_RET_ENC_PARA_SET_SUCCESS_RetStatus_SHIFT (0U)
#define VPU_VPU_ENC_RET_ENC_PARA_SET_SUCCESS_RetStatus(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_PARA_SET_SUCCESS_RetStatus_SHIFT)) & VPU_VPU_ENC_RET_ENC_PARA_SET_SUCCESS_RetStatus_MASK)

#define VPU_VPU_ENC_RET_ENC_PARA_SET_SUCCESS_MemoryAccessViolation_MASK (0x80000000U)
#define VPU_VPU_ENC_RET_ENC_PARA_SET_SUCCESS_MemoryAccessViolation_SHIFT (31U)
#define VPU_VPU_ENC_RET_ENC_PARA_SET_SUCCESS_MemoryAccessViolation(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_PARA_SET_SUCCESS_MemoryAccessViolation_SHIFT)) & VPU_VPU_ENC_RET_ENC_PARA_SET_SUCCESS_MemoryAccessViolation_MASK)
/*! @} */

/*! @name RET_ENC_PIC_TYPE - RET_ENC_PIC_TYPE */
/*! @{ */

#define VPU_VPU_ENC_RET_ENC_PIC_TYPE_EncPicType_MASK (0x1U)
#define VPU_VPU_ENC_RET_ENC_PIC_TYPE_EncPicType_SHIFT (0U)
#define VPU_VPU_ENC_RET_ENC_PIC_TYPE_EncPicType(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_PIC_TYPE_EncPicType_SHIFT)) & VPU_VPU_ENC_RET_ENC_PIC_TYPE_EncPicType_MASK)
/*! @} */

/*! @name RET_FW_CODE_REV - RET_FW_CODE_REV */
/*! @{ */

#define VPU_VPU_ENC_RET_FW_CODE_REV_CodeRevision_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_RET_FW_CODE_REV_CodeRevision_SHIFT (0U)
#define VPU_VPU_ENC_RET_FW_CODE_REV_CodeRevision(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_FW_CODE_REV_CodeRevision_SHIFT)) & VPU_VPU_ENC_RET_FW_CODE_REV_CodeRevision_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_RC_QP_MAX - CMD_ENC_SEQ_RC_QP_MAX */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_QP_MAX_RcQpMax_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_QP_MAX_RcQpMax_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_QP_MAX_RcQpMax(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_QP_MAX_RcQpMax_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_QP_MAX_RcQpMax_MASK)
/*! @} */

/*! @name RET_ENC_PIC_FRAME_IDX - RET_ENC_PIC_FRAME_IDX */
/*! @{ */

#define VPU_VPU_ENC_RET_ENC_PIC_FRAME_IDX_RecPicIdx_MASK (0xFFFFU)
#define VPU_VPU_ENC_RET_ENC_PIC_FRAME_IDX_RecPicIdx_SHIFT (0U)
#define VPU_VPU_ENC_RET_ENC_PIC_FRAME_IDX_RecPicIdx(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_PIC_FRAME_IDX_RecPicIdx_SHIFT)) & VPU_VPU_ENC_RET_ENC_PIC_FRAME_IDX_RecPicIdx_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_RC_GAMMA - CMD_ENC_SEQ_RC_GAMMA */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_GAMMA_RcGamma_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_GAMMA_RcGamma_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_GAMMA_RcGamma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_GAMMA_RcGamma_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_GAMMA_RcGamma_MASK)
/*! @} */

/*! @name RET_ENC_PIC_SLICE_NUM - RET_ENC_PIC_SLICE_NUM */
/*! @{ */

#define VPU_VPU_ENC_RET_ENC_PIC_SLICE_NUM_EncSliceNum_MASK (0x7FFFU)
#define VPU_VPU_ENC_RET_ENC_PIC_SLICE_NUM_EncSliceNum_SHIFT (0U)
#define VPU_VPU_ENC_RET_ENC_PIC_SLICE_NUM_EncSliceNum(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_PIC_SLICE_NUM_EncSliceNum_SHIFT)) & VPU_VPU_ENC_RET_ENC_PIC_SLICE_NUM_EncSliceNum_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_RC_INTERVAL_MODE - CMD_ENC_SEQ_RC_INTERVAL_MODE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_INTERVAL_MODE_RcIntervalMode_MASK (0x3U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_INTERVAL_MODE_RcIntervalMode_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_INTERVAL_MODE_RcIntervalMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_INTERVAL_MODE_RcIntervalMode_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_INTERVAL_MODE_RcIntervalMode_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_INTERVAL_MODE_RcMbInterval_MASK (0x3FFFCU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_INTERVAL_MODE_RcMbInterval_SHIFT (2U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_INTERVAL_MODE_RcMbInterval(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_INTERVAL_MODE_RcMbInterval_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_INTERVAL_MODE_RcMbInterval_MASK)
/*! @} */

/*! @name RET_ENC_PIC_FLAG - RET_ENC_PIC_FLAG */
/*! @{ */

#define VPU_VPU_ENC_RET_ENC_PIC_FLAG_EncPicFlag_MASK (0x1U)
#define VPU_VPU_ENC_RET_ENC_PIC_FLAG_EncPicFlag_SHIFT (0U)
#define VPU_VPU_ENC_RET_ENC_PIC_FLAG_EncPicFlag(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_PIC_FLAG_EncPicFlag_SHIFT)) & VPU_VPU_ENC_RET_ENC_PIC_FLAG_EncPicFlag_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_INTRA_WEIGHT - CMD_ENC_SEQ_INTRA_WEIGHT */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_WEIGHT_IntraCostWeight_MASK (0xFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_WEIGHT_IntraCostWeight_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_WEIGHT_IntraCostWeight(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_WEIGHT_IntraCostWeight_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_INTRA_WEIGHT_IntraCostWeight_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_ME_OPTION - CMD_ENC_SEQ_ME_OPTION */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeSearchRangeX_MASK (0x3U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeSearchRangeX_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeSearchRangeX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeSearchRangeX_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeSearchRangeX_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeSearchRangeY_MASK (0xCU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeSearchRangeY_SHIFT (2U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeSearchRangeY(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeSearchRangeY_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeSearchRangeY_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeUseZeroPmv_MASK (0x10U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeUseZeroPmv_SHIFT (4U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeUseZeroPmv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeUseZeroPmv_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeUseZeroPmv_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeBlkModeEnable_MASK (0x1E0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeBlkModeEnable_SHIFT (5U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeBlkModeEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeBlkModeEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeBlkModeEnable_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeLineBufMode_MASK (0x600U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeLineBufMode_SHIFT (9U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeLineBufMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeLineBufMode_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_ME_OPTION_MeLineBufMode_MASK)
/*! @} */

/*! @name RET_ENC_PIC_SUCCESS - RET_ENC_PIC_SUCCESS */
/*! @{ */

#define VPU_VPU_ENC_RET_ENC_PIC_SUCCESS_RetStatus_MASK (0x1U)
#define VPU_VPU_ENC_RET_ENC_PIC_SUCCESS_RetStatus_SHIFT (0U)
#define VPU_VPU_ENC_RET_ENC_PIC_SUCCESS_RetStatus(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_PIC_SUCCESS_RetStatus_SHIFT)) & VPU_VPU_ENC_RET_ENC_PIC_SUCCESS_RetStatus_MASK)

#define VPU_VPU_ENC_RET_ENC_PIC_SUCCESS_MemoryAccessViolation_MASK (0x80000000U)
#define VPU_VPU_ENC_RET_ENC_PIC_SUCCESS_MemoryAccessViolation_SHIFT (31U)
#define VPU_VPU_ENC_RET_ENC_PIC_SUCCESS_MemoryAccessViolation(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_PIC_SUCCESS_MemoryAccessViolation_SHIFT)) & VPU_VPU_ENC_RET_ENC_PIC_SUCCESS_MemoryAccessViolation_MASK)
/*! @} */

/*! @name RET_ENC_ROI_SUCCESS - RET_ENC_ROI_SUCCESS */
/*! @{ */

#define VPU_VPU_ENC_RET_ENC_ROI_SUCCESS_RetStatus_MASK (0x1U)
#define VPU_VPU_ENC_RET_ENC_ROI_SUCCESS_RetStatus_SHIFT (0U)
#define VPU_VPU_ENC_RET_ENC_ROI_SUCCESS_RetStatus(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_ROI_SUCCESS_RetStatus_SHIFT)) & VPU_VPU_ENC_RET_ENC_ROI_SUCCESS_RetStatus_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_RC_PARA2 - CMD_ENC_SEQ_RC_PARA2 */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_RateControlType_MASK (0xFU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_RateControlType_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_RateControlType(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_RateControlType_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_RateControlType_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_BitRateKBPS_MASK (0x3FFFF0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_BitRateKBPS_SHIFT (4U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_BitRateKBPS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_BitRateKBPS_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_BitRateKBPS_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_StrictCBR_MASK (0x400000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_StrictCBR_SHIFT (22U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_StrictCBR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_StrictCBR_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_StrictCBR_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_EnRowLevelRc_MASK (0x800000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_EnRowLevelRc_SHIFT (23U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_EnRowLevelRc(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_EnRowLevelRc_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_EnRowLevelRc_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_EnHvsQp_MASK (0x1000000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_EnHvsQp_SHIFT (24U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_EnHvsQp(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_EnHvsQp_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_EnHvsQp_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_HvsQpScaleDiv2_MASK (0x2000000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_HvsQpScaleDiv2_SHIFT (25U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_HvsQpScaleDiv2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_HvsQpScaleDiv2_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_PARA2_HvsQpScaleDiv2_MASK)
/*! @} */

/*! @name RET_ENC_PIC_INTRA_MB_NUM - RET_ENC_PIC_INTRA_MB_NUM */
/*! @{ */

#define VPU_VPU_ENC_RET_ENC_PIC_INTRA_MB_NUM_EncPicIntraMbNum_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_RET_ENC_PIC_INTRA_MB_NUM_EncPicIntraMbNum_SHIFT (0U)
#define VPU_VPU_ENC_RET_ENC_PIC_INTRA_MB_NUM_EncPicIntraMbNum(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_PIC_INTRA_MB_NUM_EncPicIntraMbNum_SHIFT)) & VPU_VPU_ENC_RET_ENC_PIC_INTRA_MB_NUM_EncPicIntraMbNum_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_QP_RANGE_SET - CMD_ENC_SEQ_QP_RANGE_SET */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpI_MASK (0x3FU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpI_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpI(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpI_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpI_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpIEnable_MASK (0x40U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpIEnable_SHIFT (6U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpIEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpIEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpIEnable_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved0_MASK (0x80U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved0_SHIFT (7U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved0_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved0_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpI_MASK (0x3F00U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpI_SHIFT (8U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpI(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpI_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpI_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpIEnable_MASK (0x4000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpIEnable_SHIFT (14U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpIEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpIEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpIEnable_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved1_MASK (0x8000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved1_SHIFT (15U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved1_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved1_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpP_MASK (0x3F0000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpP_SHIFT (16U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpP(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpP_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpP_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpPEnable_MASK (0x400000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpPEnable_SHIFT (22U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpPEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpPEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MaxQpPEnable_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved2_MASK (0x800000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved2_SHIFT (23U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved2_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved2_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpP_MASK (0x3F000000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpP_SHIFT (24U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpP(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpP_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpP_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpPEnable_MASK (0x40000000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpPEnable_SHIFT (30U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpPEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpPEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_MinQpPEnable_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved3_MASK (0x80000000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved3_SHIFT (31U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved3_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_RANGE_SET_Reserved3_MASK)
/*! @} */

/*! @name RET_ENC_PIC_SKIPPED_MB_NUM - RET_ENC_PIC_SKIPPED_MB_NUM */
/*! @{ */

#define VPU_VPU_ENC_RET_ENC_PIC_SKIPPED_MB_NUM_EncPicSkippedMbNum_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_RET_ENC_PIC_SKIPPED_MB_NUM_EncPicSkippedMbNum_SHIFT (0U)
#define VPU_VPU_ENC_RET_ENC_PIC_SKIPPED_MB_NUM_EncPicSkippedMbNum(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_PIC_SKIPPED_MB_NUM_EncPicSkippedMbNum_SHIFT)) & VPU_VPU_ENC_RET_ENC_PIC_SKIPPED_MB_NUM_EncPicSkippedMbNum_MASK)
/*! @} */

/*! @name RET_ENC_PIC_SUM_QP - RET_ENC_PIC_SUM_QP */
/*! @{ */

#define VPU_VPU_ENC_RET_ENC_PIC_SUM_QP_EncPicSumQp_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_RET_ENC_PIC_SUM_QP_EncPicSumQp_SHIFT (0U)
#define VPU_VPU_ENC_RET_ENC_PIC_SUM_QP_EncPicSumQp(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_RET_ENC_PIC_SUM_QP_EncPicSumQp_SHIFT)) & VPU_VPU_ENC_RET_ENC_PIC_SUM_QP_EncPicSumQp_MASK)
/*! @} */

/*! @name CMD_ENC_PIC_SRC_BOTTOM_Y - CMD_ENC_PIC_SRC_BOTTOM_Y */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_BOTTOM_Y_SrcBottomAddrY_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_BOTTOM_Y_SrcBottomAddrY_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_BOTTOM_Y_SrcBottomAddrY(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_SRC_BOTTOM_Y_SrcBottomAddrY_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_SRC_BOTTOM_Y_SrcBottomAddrY_MASK)
/*! @} */

/*! @name CMD_ENC_PIC_SRC_BOTTOM_CB - CMD_ENC_PIC_SRC_BOTTOM_CB */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_BOTTOM_CB_SrcBottomAddrCb_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_BOTTOM_CB_SrcBottomAddrCb_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_BOTTOM_CB_SrcBottomAddrCb(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_SRC_BOTTOM_CB_SrcBottomAddrCb_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_SRC_BOTTOM_CB_SrcBottomAddrCb_MASK)
/*! @} */

/*! @name CMD_ENC_PIC_SRC_BOTTOM_CR - CMD_ENC_PIC_SRC_BOTTOM_CR */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_BOTTOM_CR_SrcBottomAddrCr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_BOTTOM_CR_SrcBottomAddrCr_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_PIC_SRC_BOTTOM_CR_SrcBottomAddrCr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_PIC_SRC_BOTTOM_CR_SrcBottomAddrCr_SHIFT)) & VPU_VPU_ENC_CMD_ENC_PIC_SRC_BOTTOM_CR_SrcBottomAddrCr_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_RC_MAX_INTRA_SIZE - CMD_ENC_SEQ_RC_MAX_INTRA_SIZE */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_MAX_INTRA_SIZE_MaxIntraSize_MASK (0xFFFFU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_MAX_INTRA_SIZE_MaxIntraSize_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_MAX_INTRA_SIZE_MaxIntraSize(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_MAX_INTRA_SIZE_MaxIntraSize_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_MAX_INTRA_SIZE_MaxIntraSize_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_MAX_INTRA_SIZE_MaxIntraSizeEn_MASK (0x10000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_MAX_INTRA_SIZE_MaxIntraSizeEn_SHIFT (16U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_RC_MAX_INTRA_SIZE_MaxIntraSizeEn(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_RC_MAX_INTRA_SIZE_MaxIntraSizeEn_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_RC_MAX_INTRA_SIZE_MaxIntraSizeEn_MASK)
/*! @} */

/*! @name CMD_ENC_SEQ_QP_DELTA_QP - CMD_ENC_SEQ_QP_DELTA_QP */
/*! @{ */

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MaxDeltaQp_MASK (0x3FU)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MaxDeltaQp_SHIFT (0U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MaxDeltaQp(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MaxDeltaQp_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MaxDeltaQp_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MaxDeltaQpSetEnable_MASK (0x40U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MaxDeltaQpSetEnable_SHIFT (6U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MaxDeltaQpSetEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MaxDeltaQpSetEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MaxDeltaQpSetEnable_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_Reserved0_MASK (0x80U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_Reserved0_SHIFT (7U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_Reserved0_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_Reserved0_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MinDeltaQp_MASK (0x3F00U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MinDeltaQp_SHIFT (8U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MinDeltaQp(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MinDeltaQp_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MinDeltaQp_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MinDeltaQpSetEnable_MASK (0x4000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MinDeltaQpSetEnable_SHIFT (14U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MinDeltaQpSetEnable(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MinDeltaQpSetEnable_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_MinDeltaQpSetEnable_MASK)

#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_Reserved1_MASK (0xFFFF8000U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_Reserved1_SHIFT (15U)
#define VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_Reserved1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_Reserved1_SHIFT)) & VPU_VPU_ENC_CMD_ENC_SEQ_QP_DELTA_QP_Reserved1_MASK)
/*! @} */

/*! @name GDI_PRI_RD_PRIOR_L - GDI_PRI_RD_PRIOR_L */
/*! @{ */

#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_0_MASK (0xFU)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_0_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_0_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_0_MASK)

#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_1_MASK (0xF0U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_1_SHIFT (4U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_1_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_1_MASK)

#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_2_MASK (0xF00U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_2_SHIFT (8U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_2_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_2_MASK)

#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_3_MASK (0xF000U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_3_SHIFT (12U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_3_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_3_MASK)

#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_4_MASK (0xF0000U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_4_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_4(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_4_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_4_MASK)

#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_5_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_5_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_5(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_5_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_5_MASK)

#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_6_MASK (0xF000000U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_6_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_6(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_6_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_6_MASK)

#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_7_MASK (0xF0000000U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_7_SHIFT (28U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_7(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_7_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_PRIOR_L_PRI_RD_PRI_7_MASK)
/*! @} */

/*! @name GDI_PRI_RD_PRIOR_H - GDI_PRI_RD_PRIOR_H */
/*! @{ */

#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_8_MASK (0xFU)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_8_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_8(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_8_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_8_MASK)

#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_9_MASK (0xF0U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_9_SHIFT (4U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_9(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_9_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_9_MASK)

#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_10_MASK (0xF00U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_10_SHIFT (8U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_10(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_10_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_10_MASK)

#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_11_MASK (0xF000U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_11_SHIFT (12U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_11(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_11_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_11_MASK)

#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_12_MASK (0xF0000U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_12_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_12(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_12_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_12_MASK)

#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_13_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_13_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_13(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_13_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_13_MASK)

#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_14_MASK (0xF000000U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_14_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_14(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_14_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_14_MASK)

#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_15_MASK (0xF0000000U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_15_SHIFT (28U)
#define VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_15(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_15_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_PRIOR_H_PRI_RD_PRI_15_MASK)
/*! @} */

/*! @name GDI_PRI_WR_PRIOR_L - GDI_PRI_WR_PRIOR_L */
/*! @{ */

#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_0_MASK (0xFU)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_0_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_0_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_0_MASK)

#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_1_MASK (0xF0U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_1_SHIFT (4U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_1_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_1_MASK)

#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_2_MASK (0xF00U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_2_SHIFT (8U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_2_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_2_MASK)

#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_3_MASK (0xF000U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_3_SHIFT (12U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_3_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_3_MASK)

#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_4_MASK (0xF0000U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_4_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_4(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_4_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_4_MASK)

#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_5_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_5_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_5(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_5_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_5_MASK)

#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_6_MASK (0xF000000U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_6_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_6(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_6_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_6_MASK)

#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_7_MASK (0xF0000000U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_7_SHIFT (28U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_7(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_7_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_PRIOR_L_PRI_WR_PRI_7_MASK)
/*! @} */

/*! @name GDI_PRI_WR_PRIOR_H - GDI_PRI_WR_PRIOR_H */
/*! @{ */

#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_8_MASK (0xFU)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_8_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_8(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_8_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_8_MASK)

#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_9_MASK (0xF0U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_9_SHIFT (4U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_9(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_9_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_9_MASK)

#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_10_MASK (0xF00U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_10_SHIFT (8U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_10(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_10_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_10_MASK)

#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_11_MASK (0xF000U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_11_SHIFT (12U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_11(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_11_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_11_MASK)

#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_12_MASK (0xF0000U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_12_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_12(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_12_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_12_MASK)

#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_13_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_13_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_13(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_13_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_13_MASK)

#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_14_MASK (0xF000000U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_14_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_14(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_14_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_14_MASK)

#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_15_MASK (0xF0000000U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_15_SHIFT (28U)
#define VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_15(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_15_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_PRIOR_H_PRI_WR_PRI_15_MASK)
/*! @} */

/*! @name GDI_PRI_RD_LOCK_CNT - GDI_PRI_RD_LOCK_CNT */
/*! @{ */

#define VPU_VPU_ENC_GDI_PRI_RD_LOCK_CNT_PRI_RD_LOCK_CNT_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PRI_RD_LOCK_CNT_PRI_RD_LOCK_CNT_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PRI_RD_LOCK_CNT_PRI_RD_LOCK_CNT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_RD_LOCK_CNT_PRI_RD_LOCK_CNT_SHIFT)) & VPU_VPU_ENC_GDI_PRI_RD_LOCK_CNT_PRI_RD_LOCK_CNT_MASK)
/*! @} */

/*! @name GDI_PRI_WR_LOCK_CNT - GDI_PRI_WR_LOCK_CNT */
/*! @{ */

#define VPU_VPU_ENC_GDI_PRI_WR_LOCK_CNT_PRI_WR_LOCK_CNT_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PRI_WR_LOCK_CNT_PRI_WR_LOCK_CNT_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PRI_WR_LOCK_CNT_PRI_WR_LOCK_CNT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PRI_WR_LOCK_CNT_PRI_WR_LOCK_CNT_SHIFT)) & VPU_VPU_ENC_GDI_PRI_WR_LOCK_CNT_PRI_WR_LOCK_CNT_MASK)
/*! @} */

/*! @name GDI_SEC_RD_PRIOR_L - GDI_SEC_RD_PRIOR_L */
/*! @{ */

#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_0_MASK (0xFU)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_0_SHIFT (0U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_0_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_0_MASK)

#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_1_MASK (0xF0U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_1_SHIFT (4U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_1_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_1_MASK)

#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_2_MASK (0xF00U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_2_SHIFT (8U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_2_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_2_MASK)

#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_3_MASK (0xF000U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_3_SHIFT (12U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_3_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_3_MASK)

#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_4_MASK (0xF0000U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_4_SHIFT (16U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_4(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_4_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_4_MASK)

#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_5_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_5_SHIFT (20U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_5(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_5_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_5_MASK)

#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_6_MASK (0xF000000U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_6_SHIFT (24U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_6(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_6_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_6_MASK)

#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_7_MASK (0xF0000000U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_7_SHIFT (28U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_7(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_7_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_PRIOR_L_SEC_RD_PRI_7_MASK)
/*! @} */

/*! @name GDI_SEC_RD_PRIOR_H - GDI_SEC_RD_PRIOR_H */
/*! @{ */

#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_8_MASK (0xFU)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_8_SHIFT (0U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_8(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_8_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_8_MASK)

#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_9_MASK (0xF0U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_9_SHIFT (4U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_9(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_9_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_9_MASK)

#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_10_MASK (0xF00U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_10_SHIFT (8U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_10(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_10_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_10_MASK)

#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_11_MASK (0xF000U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_11_SHIFT (12U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_11(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_11_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_11_MASK)

#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_12_MASK (0xF0000U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_12_SHIFT (16U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_12(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_12_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_12_MASK)

#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_13_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_13_SHIFT (20U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_13(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_13_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_13_MASK)

#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_14_MASK (0xF000000U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_14_SHIFT (24U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_14(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_14_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_14_MASK)

#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_15_MASK (0xF0000000U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_15_SHIFT (28U)
#define VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_15(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_15_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_PRIOR_H_SEC_RD_PRI_15_MASK)
/*! @} */

/*! @name GDI_SEC_WR_PRIOR_L - GDI_SEC_WR_PRIOR_L */
/*! @{ */

#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_0_MASK (0xFU)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_0_SHIFT (0U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_0_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_0_MASK)

#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_1_MASK (0xF0U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_1_SHIFT (4U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_1_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_1_MASK)

#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_2_MASK (0xF00U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_2_SHIFT (8U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_2_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_2_MASK)

#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_3_MASK (0xF000U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_3_SHIFT (12U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_3_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_3_MASK)

#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_4_MASK (0xF0000U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_4_SHIFT (16U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_4(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_4_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_4_MASK)

#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_5_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_5_SHIFT (20U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_5(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_5_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_5_MASK)

#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_6_MASK (0xF000000U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_6_SHIFT (24U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_6(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_6_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_6_MASK)

#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_7_MASK (0xF0000000U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_7_SHIFT (28U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_7(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_7_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_PRIOR_L_SEC_WR_PRI_7_MASK)
/*! @} */

/*! @name GDI_SEC_WR_PRIOR_H - GDI_SEC_WR_PRIOR_H */
/*! @{ */

#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_8_MASK (0xFU)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_8_SHIFT (0U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_8(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_8_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_8_MASK)

#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_9_MASK (0xF0U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_9_SHIFT (4U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_9(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_9_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_9_MASK)

#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_10_MASK (0xF00U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_10_SHIFT (8U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_10(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_10_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_10_MASK)

#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_11_MASK (0xF000U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_11_SHIFT (12U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_11(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_11_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_11_MASK)

#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_12_MASK (0xF0000U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_12_SHIFT (16U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_12(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_12_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_12_MASK)

#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_13_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_13_SHIFT (20U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_13(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_13_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_13_MASK)

#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_14_MASK (0xF000000U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_14_SHIFT (24U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_14(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_14_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_14_MASK)

#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_15_MASK (0xF0000000U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_15_SHIFT (28U)
#define VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_15(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_15_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_PRIOR_H_SEC_WR_PRI_15_MASK)
/*! @} */

/*! @name GDI_SEC_RD_LOCK_CNT - GDI_SEC_RD_LOCK_CNT */
/*! @{ */

#define VPU_VPU_ENC_GDI_SEC_RD_LOCK_CNT_GDI_SEC_RD_LOCK_CNT_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_SEC_RD_LOCK_CNT_GDI_SEC_RD_LOCK_CNT_SHIFT (0U)
#define VPU_VPU_ENC_GDI_SEC_RD_LOCK_CNT_GDI_SEC_RD_LOCK_CNT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_RD_LOCK_CNT_GDI_SEC_RD_LOCK_CNT_SHIFT)) & VPU_VPU_ENC_GDI_SEC_RD_LOCK_CNT_GDI_SEC_RD_LOCK_CNT_MASK)
/*! @} */

/*! @name GDI_SEC_WR_LOCK_CNT - GDI_SEC_WR_LOCK_CNT */
/*! @{ */

#define VPU_VPU_ENC_GDI_SEC_WR_LOCK_CNT_GDI_SEC_WR_LOCK_CNT_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_SEC_WR_LOCK_CNT_GDI_SEC_WR_LOCK_CNT_SHIFT (0U)
#define VPU_VPU_ENC_GDI_SEC_WR_LOCK_CNT_GDI_SEC_WR_LOCK_CNT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_WR_LOCK_CNT_GDI_SEC_WR_LOCK_CNT_SHIFT)) & VPU_VPU_ENC_GDI_SEC_WR_LOCK_CNT_GDI_SEC_WR_LOCK_CNT_MASK)
/*! @} */

/*! @name GDI_SEC_CLIENT_EN - GDI_SEC_CLIENT_EN */
/*! @{ */

#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn0_MASK (0x1U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn0_SHIFT (0U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn0(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn0_SHIFT)) & VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn0_MASK)

#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn1_MASK (0x2U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn1_SHIFT (1U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn1(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn1_SHIFT)) & VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn1_MASK)

#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn2_MASK (0x4U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn2_SHIFT (2U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn2(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn2_SHIFT)) & VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn2_MASK)

#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn3_MASK (0x8U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn3_SHIFT (3U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn3(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn3_SHIFT)) & VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn3_MASK)

#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn4_MASK (0x10U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn4_SHIFT (4U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn4(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn4_SHIFT)) & VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn4_MASK)

#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn5_MASK (0x20U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn5_SHIFT (5U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn5(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn5_SHIFT)) & VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn5_MASK)

#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn6_MASK (0x40U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn6_SHIFT (6U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn6(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn6_SHIFT)) & VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn6_MASK)

#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn7_MASK (0x80U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn7_SHIFT (7U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn7(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn7_SHIFT)) & VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn7_MASK)

#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn8_MASK (0x100U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn8_SHIFT (8U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn8(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn8_SHIFT)) & VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn8_MASK)

#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn9_MASK (0x200U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn9_SHIFT (9U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn9(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn9_SHIFT)) & VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn9_MASK)

#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn10_MASK (0x400U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn10_SHIFT (10U)
#define VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn10(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn10_SHIFT)) & VPU_VPU_ENC_GDI_SEC_CLIENT_EN_SecEn10_MASK)
/*! @} */

/*! @name GDI_PIC_INIT_HOST - GDI_PIC_INIT_HOST */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INIT_HOST_GDI_PIC_INIT_MASK (0x1U)
#define VPU_VPU_ENC_GDI_PIC_INIT_HOST_GDI_PIC_INIT_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INIT_HOST_GDI_PIC_INIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INIT_HOST_GDI_PIC_INIT_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INIT_HOST_GDI_PIC_INIT_MASK)
/*! @} */

/*! @name GDI_CONFIG_REPORT_0 - GDI_CONFIG_REPORT_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_CONFIG_REPORT_0_GDI_CONFIG_REPORT_0_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_CONFIG_REPORT_0_GDI_CONFIG_REPORT_0_SHIFT (0U)
#define VPU_VPU_ENC_GDI_CONFIG_REPORT_0_GDI_CONFIG_REPORT_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_CONFIG_REPORT_0_GDI_CONFIG_REPORT_0_SHIFT)) & VPU_VPU_ENC_GDI_CONFIG_REPORT_0_GDI_CONFIG_REPORT_0_MASK)
/*! @} */

/*! @name GDI_CONFIG_REPORT_1 - GDI_CONFIG_REPORT_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_CONFIG_REPORT_1_GDI_CONFIG_REPORT_1_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_CONFIG_REPORT_1_GDI_CONFIG_REPORT_1_SHIFT (0U)
#define VPU_VPU_ENC_GDI_CONFIG_REPORT_1_GDI_CONFIG_REPORT_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_CONFIG_REPORT_1_GDI_CONFIG_REPORT_1_SHIFT)) & VPU_VPU_ENC_GDI_CONFIG_REPORT_1_GDI_CONFIG_REPORT_1_MASK)
/*! @} */

/*! @name GDI_CONFIG_REPORT_2 - GDI_CONFIG_REPORT_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_CONFIG_REPORT_2_GDI_CONFIG_REPORT_2_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_CONFIG_REPORT_2_GDI_CONFIG_REPORT_2_SHIFT (0U)
#define VPU_VPU_ENC_GDI_CONFIG_REPORT_2_GDI_CONFIG_REPORT_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_CONFIG_REPORT_2_GDI_CONFIG_REPORT_2_SHIFT)) & VPU_VPU_ENC_GDI_CONFIG_REPORT_2_GDI_CONFIG_REPORT_2_MASK)
/*! @} */

/*! @name GDI_CONFIG_REPORT_3 - GDI_CONFIG_REPORT_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_CONFIG_REPORT_3_GDI_CONFIG_REPORT_3_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_CONFIG_REPORT_3_GDI_CONFIG_REPORT_3_SHIFT (0U)
#define VPU_VPU_ENC_GDI_CONFIG_REPORT_3_GDI_CONFIG_REPORT_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_CONFIG_REPORT_3_GDI_CONFIG_REPORT_3_SHIFT)) & VPU_VPU_ENC_GDI_CONFIG_REPORT_3_GDI_CONFIG_REPORT_3_MASK)
/*! @} */

/*! @name GDI_CONFIG_REPORT_4 - GDI_CONFIG_REPORT_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_CONFIG_REPORT_4_GDI_CONFIG_REPORT_4_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_CONFIG_REPORT_4_GDI_CONFIG_REPORT_4_SHIFT (0U)
#define VPU_VPU_ENC_GDI_CONFIG_REPORT_4_GDI_CONFIG_REPORT_4(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_CONFIG_REPORT_4_GDI_CONFIG_REPORT_4_SHIFT)) & VPU_VPU_ENC_GDI_CONFIG_REPORT_4_GDI_CONFIG_REPORT_4_MASK)
/*! @} */

/*! @name GDI_CONFIG_REPORT_5 - GDI_CONFIG_REPORT_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_CONFIG_REPORT_5_GDI_CONFIG_REPORT_5_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_CONFIG_REPORT_5_GDI_CONFIG_REPORT_5_SHIFT (0U)
#define VPU_VPU_ENC_GDI_CONFIG_REPORT_5_GDI_CONFIG_REPORT_5(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_CONFIG_REPORT_5_GDI_CONFIG_REPORT_5_SHIFT)) & VPU_VPU_ENC_GDI_CONFIG_REPORT_5_GDI_CONFIG_REPORT_5_MASK)
/*! @} */

/*! @name GDI_CONFIG_REPORT_6 - GDI_CONFIG_REPORT_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_CONFIG_REPORT_6_GDI_CONFIG_REPORT_6_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_CONFIG_REPORT_6_GDI_CONFIG_REPORT_6_SHIFT (0U)
#define VPU_VPU_ENC_GDI_CONFIG_REPORT_6_GDI_CONFIG_REPORT_6(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_CONFIG_REPORT_6_GDI_CONFIG_REPORT_6_SHIFT)) & VPU_VPU_ENC_GDI_CONFIG_REPORT_6_GDI_CONFIG_REPORT_6_MASK)
/*! @} */

/*! @name GDI_CONFIG_REPORT_7 - GDI_CONFIG_REPORT_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_CONFIG_REPORT_7_GDI_CONFIG_REPORT_7_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_CONFIG_REPORT_7_GDI_CONFIG_REPORT_7_SHIFT (0U)
#define VPU_VPU_ENC_GDI_CONFIG_REPORT_7_GDI_CONFIG_REPORT_7(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_CONFIG_REPORT_7_GDI_CONFIG_REPORT_7_SHIFT)) & VPU_VPU_ENC_GDI_CONFIG_REPORT_7_GDI_CONFIG_REPORT_7_MASK)
/*! @} */

/*! @name GDI_PINFO_REQ - GDI_PINFO_REQ */
/*! @{ */

#define VPU_VPU_ENC_GDI_PINFO_REQ_PINFO_REQ_MASK (0x1U)
#define VPU_VPU_ENC_GDI_PINFO_REQ_PINFO_REQ_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PINFO_REQ_PINFO_REQ(x)   (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PINFO_REQ_PINFO_REQ_SHIFT)) & VPU_VPU_ENC_GDI_PINFO_REQ_PINFO_REQ_MASK)
/*! @} */

/*! @name GDI_PINFO_ACK - GDI_PINFO_ACK */
/*! @{ */

#define VPU_VPU_ENC_GDI_PINFO_ACK_PINFO_ACK_MASK (0x1U)
#define VPU_VPU_ENC_GDI_PINFO_ACK_PINFO_ACK_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PINFO_ACK_PINFO_ACK(x)   (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PINFO_ACK_PINFO_ACK_SHIFT)) & VPU_VPU_ENC_GDI_PINFO_ACK_PINFO_ACK_MASK)
/*! @} */

/*! @name GDI_PINFO_ADDR - GDI_PINFO_ADDR */
/*! @{ */

#define VPU_VPU_ENC_GDI_PINFO_ADDR_PINFO_ADDR_MASK (0x3FFU)
#define VPU_VPU_ENC_GDI_PINFO_ADDR_PINFO_ADDR_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PINFO_ADDR_PINFO_ADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PINFO_ADDR_PINFO_ADDR_SHIFT)) & VPU_VPU_ENC_GDI_PINFO_ADDR_PINFO_ADDR_MASK)
/*! @} */

/*! @name GDI_PINFO_DATA - GDI_PINFO_DATA */
/*! @{ */

#define VPU_VPU_ENC_GDI_PINFO_DATA_PINFO_DATA_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PINFO_DATA_PINFO_DATA_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PINFO_DATA_PINFO_DATA(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PINFO_DATA_PINFO_DATA_SHIFT)) & VPU_VPU_ENC_GDI_PINFO_DATA_PINFO_DATA_MASK)
/*! @} */

/*! @name GDI_BWB_ENABLE - GDI_BWB_ENABLE */
/*! @{ */

#define VPU_VPU_ENC_GDI_BWB_ENABLE_FRM_IDX_MASK  (0xFFU)
#define VPU_VPU_ENC_GDI_BWB_ENABLE_FRM_IDX_SHIFT (0U)
#define VPU_VPU_ENC_GDI_BWB_ENABLE_FRM_IDX(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BWB_ENABLE_FRM_IDX_SHIFT)) & VPU_VPU_ENC_GDI_BWB_ENABLE_FRM_IDX_MASK)

#define VPU_VPU_ENC_GDI_BWB_ENABLE_BWB_EN_MASK   (0x100U)
#define VPU_VPU_ENC_GDI_BWB_ENABLE_BWB_EN_SHIFT  (8U)
#define VPU_VPU_ENC_GDI_BWB_ENABLE_BWB_EN(x)     (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BWB_ENABLE_BWB_EN_SHIFT)) & VPU_VPU_ENC_GDI_BWB_ENABLE_BWB_EN_MASK)

#define VPU_VPU_ENC_GDI_BWB_ENABLE_PIC_INIT_MASK (0x200U)
#define VPU_VPU_ENC_GDI_BWB_ENABLE_PIC_INIT_SHIFT (9U)
#define VPU_VPU_ENC_GDI_BWB_ENABLE_PIC_INIT(x)   (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BWB_ENABLE_PIC_INIT_SHIFT)) & VPU_VPU_ENC_GDI_BWB_ENABLE_PIC_INIT_MASK)
/*! @} */

/*! @name GDI_BWB_SIZE - GDI_BWB_SIZE */
/*! @{ */

#define VPU_VPU_ENC_GDI_BWB_SIZE_BWB_YSIZE_MASK  (0xFFFU)
#define VPU_VPU_ENC_GDI_BWB_SIZE_BWB_YSIZE_SHIFT (0U)
#define VPU_VPU_ENC_GDI_BWB_SIZE_BWB_YSIZE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BWB_SIZE_BWB_YSIZE_SHIFT)) & VPU_VPU_ENC_GDI_BWB_SIZE_BWB_YSIZE_MASK)

#define VPU_VPU_ENC_GDI_BWB_SIZE_BWB_XSIZE_MASK  (0xFFF0000U)
#define VPU_VPU_ENC_GDI_BWB_SIZE_BWB_XSIZE_SHIFT (16U)
#define VPU_VPU_ENC_GDI_BWB_SIZE_BWB_XSIZE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BWB_SIZE_BWB_XSIZE_SHIFT)) & VPU_VPU_ENC_GDI_BWB_SIZE_BWB_XSIZE_MASK)
/*! @} */

/*! @name GDI_BWB_STD_STRUCT - GDI_BWB_STD_STRUCT */
/*! @{ */

#define VPU_VPU_ENC_GDI_BWB_STD_STRUCT_PIC_STRUCT_MASK (0x7U)
#define VPU_VPU_ENC_GDI_BWB_STD_STRUCT_PIC_STRUCT_SHIFT (0U)
#define VPU_VPU_ENC_GDI_BWB_STD_STRUCT_PIC_STRUCT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BWB_STD_STRUCT_PIC_STRUCT_SHIFT)) & VPU_VPU_ENC_GDI_BWB_STD_STRUCT_PIC_STRUCT_MASK)

#define VPU_VPU_ENC_GDI_BWB_STD_STRUCT_STD_AUX_MASK (0x18U)
#define VPU_VPU_ENC_GDI_BWB_STD_STRUCT_STD_AUX_SHIFT (3U)
#define VPU_VPU_ENC_GDI_BWB_STD_STRUCT_STD_AUX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BWB_STD_STRUCT_STD_AUX_SHIFT)) & VPU_VPU_ENC_GDI_BWB_STD_STRUCT_STD_AUX_MASK)

#define VPU_VPU_ENC_GDI_BWB_STD_STRUCT_CODEC_STD_MASK (0x1E0U)
#define VPU_VPU_ENC_GDI_BWB_STD_STRUCT_CODEC_STD_SHIFT (5U)
#define VPU_VPU_ENC_GDI_BWB_STD_STRUCT_CODEC_STD(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BWB_STD_STRUCT_CODEC_STD_SHIFT)) & VPU_VPU_ENC_GDI_BWB_STD_STRUCT_CODEC_STD_MASK)

#define VPU_VPU_ENC_GDI_BWB_STD_STRUCT_CBCR_INTLV_MASK (0x200U)
#define VPU_VPU_ENC_GDI_BWB_STD_STRUCT_CBCR_INTLV_SHIFT (9U)
#define VPU_VPU_ENC_GDI_BWB_STD_STRUCT_CBCR_INTLV(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BWB_STD_STRUCT_CBCR_INTLV_SHIFT)) & VPU_VPU_ENC_GDI_BWB_STD_STRUCT_CBCR_INTLV_MASK)

#define VPU_VPU_ENC_GDI_BWB_STD_STRUCT_LOOPFILT_EN_MASK (0x400U)
#define VPU_VPU_ENC_GDI_BWB_STD_STRUCT_LOOPFILT_EN_SHIFT (10U)
#define VPU_VPU_ENC_GDI_BWB_STD_STRUCT_LOOPFILT_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BWB_STD_STRUCT_LOOPFILT_EN_SHIFT)) & VPU_VPU_ENC_GDI_BWB_STD_STRUCT_LOOPFILT_EN_MASK)
/*! @} */

/*! @name GDI_BWB_STATUS - GDI_BWB_STATUS */
/*! @{ */

#define VPU_VPU_ENC_GDI_BWB_STATUS_OUT_RESP_MASK (0x1U)
#define VPU_VPU_ENC_GDI_BWB_STATUS_OUT_RESP_SHIFT (0U)
#define VPU_VPU_ENC_GDI_BWB_STATUS_OUT_RESP(x)   (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BWB_STATUS_OUT_RESP_SHIFT)) & VPU_VPU_ENC_GDI_BWB_STATUS_OUT_RESP_MASK)

#define VPU_VPU_ENC_GDI_BWB_STATUS_IN_RESP_MASK  (0x2U)
#define VPU_VPU_ENC_GDI_BWB_STATUS_IN_RESP_SHIFT (1U)
#define VPU_VPU_ENC_GDI_BWB_STATUS_IN_RESP(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BWB_STATUS_IN_RESP_SHIFT)) & VPU_VPU_ENC_GDI_BWB_STATUS_IN_RESP_MASK)

#define VPU_VPU_ENC_GDI_BWB_STATUS_V_FLUSH_MASK  (0x4U)
#define VPU_VPU_ENC_GDI_BWB_STATUS_V_FLUSH_SHIFT (2U)
#define VPU_VPU_ENC_GDI_BWB_STATUS_V_FLUSH(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BWB_STATUS_V_FLUSH_SHIFT)) & VPU_VPU_ENC_GDI_BWB_STATUS_V_FLUSH_MASK)

#define VPU_VPU_ENC_GDI_BWB_STATUS_U_FLUSH_MASK  (0x8U)
#define VPU_VPU_ENC_GDI_BWB_STATUS_U_FLUSH_SHIFT (3U)
#define VPU_VPU_ENC_GDI_BWB_STATUS_U_FLUSH(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BWB_STATUS_U_FLUSH_SHIFT)) & VPU_VPU_ENC_GDI_BWB_STATUS_U_FLUSH_MASK)

#define VPU_VPU_ENC_GDI_BWB_STATUS_Y_FLUSH_MASK  (0x10U)
#define VPU_VPU_ENC_GDI_BWB_STATUS_Y_FLUSH_SHIFT (4U)
#define VPU_VPU_ENC_GDI_BWB_STATUS_Y_FLUSH(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BWB_STATUS_Y_FLUSH_SHIFT)) & VPU_VPU_ENC_GDI_BWB_STATUS_Y_FLUSH_MASK)
/*! @} */

/*! @name GDI_WPROT_ERR_CLEAR - GDI_WPROT_ERR_CLEAR */
/*! @{ */

#define VPU_VPU_ENC_GDI_WPROT_ERR_CLEAR_CLEAR_MASK (0x1U)
#define VPU_VPU_ENC_GDI_WPROT_ERR_CLEAR_CLEAR_SHIFT (0U)
#define VPU_VPU_ENC_GDI_WPROT_ERR_CLEAR_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_ERR_CLEAR_CLEAR_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_ERR_CLEAR_CLEAR_MASK)
/*! @} */

/*! @name GDI_WPROT_ERR_RSN - GDI_WPROT_ERR_RSN */
/*! @{ */

#define VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_AWLEN_MASK (0xFU)
#define VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_AWLEN_SHIFT (0U)
#define VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_AWLEN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_AWLEN_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_AWLEN_MASK)

#define VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_AWID_MASK (0xF0U)
#define VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_AWID_SHIFT (4U)
#define VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_AWID(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_AWID_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_AWID_MASK)

#define VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_PRI_SEC_MASK (0x100U)
#define VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_PRI_SEC_SHIFT (8U)
#define VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_PRI_SEC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_PRI_SEC_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_PRI_SEC_MASK)

#define VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_FLAG_MASK (0x200U)
#define VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_FLAG_SHIFT (9U)
#define VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_FLAG_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_ERR_RSN_ERR_FLAG_MASK)
/*! @} */

/*! @name GDI_WPROT_ERR_ADR - GDI_WPROT_ERR_ADR */
/*! @{ */

#define VPU_VPU_ENC_GDI_WPROT_ERR_ADR_ERR_AWADDR_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_WPROT_ERR_ADR_ERR_AWADDR_SHIFT (0U)
#define VPU_VPU_ENC_GDI_WPROT_ERR_ADR_ERR_AWADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_ERR_ADR_ERR_AWADDR_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_ERR_ADR_ERR_AWADDR_MASK)
/*! @} */

/*! @name GDI_WPROT_RGN_EN - GDI_WPROT_RGN_EN */
/*! @{ */

#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN0_EN_MASK (0x1U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN0_EN_SHIFT (0U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN0_EN(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN0_EN_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN0_EN_MASK)

#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN1_EN_MASK (0x2U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN1_EN_SHIFT (1U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN1_EN(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN1_EN_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN1_EN_MASK)

#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN2_EN_MASK (0x4U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN2_EN_SHIFT (2U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN2_EN(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN2_EN_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN2_EN_MASK)

#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN3_EN_MASK (0x8U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN3_EN_SHIFT (3U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN3_EN(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN3_EN_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN3_EN_MASK)

#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN4_EN_MASK (0x10U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN4_EN_SHIFT (4U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN4_EN(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN4_EN_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN4_EN_MASK)

#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN5_EN_MASK (0x20U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN5_EN_SHIFT (5U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN5_EN(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN5_EN_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN5_EN_MASK)

#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN0_SEC_MASK (0x40U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN0_SEC_SHIFT (6U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN0_SEC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN0_SEC_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN0_SEC_MASK)

#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN1_SEC_MASK (0x80U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN1_SEC_SHIFT (7U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN1_SEC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN1_SEC_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN1_SEC_MASK)

#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN2_SEC_MASK (0x100U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN2_SEC_SHIFT (8U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN2_SEC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN2_SEC_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN2_SEC_MASK)

#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN3_SEC_MASK (0x200U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN3_SEC_SHIFT (9U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN3_SEC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN3_SEC_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN3_SEC_MASK)

#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN4_SEC_MASK (0x400U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN4_SEC_SHIFT (10U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN4_SEC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN4_SEC_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN4_SEC_MASK)

#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN5_SEC_MASK (0x800U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN5_SEC_SHIFT (11U)
#define VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN5_SEC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN5_SEC_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN_EN_RGN5_SEC_MASK)
/*! @} */

/*! @name GDI_WPROT_RGN0_STA - GDI_WPROT_RGN0_STA */
/*! @{ */

#define VPU_VPU_ENC_GDI_WPROT_RGN0_STA_RGN_STA_MASK (0xFFFFFU)
#define VPU_VPU_ENC_GDI_WPROT_RGN0_STA_RGN_STA_SHIFT (0U)
#define VPU_VPU_ENC_GDI_WPROT_RGN0_STA_RGN_STA(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN0_STA_RGN_STA_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN0_STA_RGN_STA_MASK)
/*! @} */

/*! @name GDI_WPROT_RGN0_END - GDI_WPROT_RGN0_END */
/*! @{ */

#define VPU_VPU_ENC_GDI_WPROT_RGN0_END_RGN_END_MASK (0xFFFFFU)
#define VPU_VPU_ENC_GDI_WPROT_RGN0_END_RGN_END_SHIFT (0U)
#define VPU_VPU_ENC_GDI_WPROT_RGN0_END_RGN_END(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN0_END_RGN_END_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN0_END_RGN_END_MASK)
/*! @} */

/*! @name GDI_WPROT_RGN1_STA - GDI_WPROT_RGN1_STA */
/*! @{ */

#define VPU_VPU_ENC_GDI_WPROT_RGN1_STA_RGN_STA_MASK (0xFFFFFU)
#define VPU_VPU_ENC_GDI_WPROT_RGN1_STA_RGN_STA_SHIFT (0U)
#define VPU_VPU_ENC_GDI_WPROT_RGN1_STA_RGN_STA(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN1_STA_RGN_STA_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN1_STA_RGN_STA_MASK)
/*! @} */

/*! @name GDI_WPROT_RGN1_END - GDI_WPROT_RGN1_END */
/*! @{ */

#define VPU_VPU_ENC_GDI_WPROT_RGN1_END_RGN_END_MASK (0xFFFFFU)
#define VPU_VPU_ENC_GDI_WPROT_RGN1_END_RGN_END_SHIFT (0U)
#define VPU_VPU_ENC_GDI_WPROT_RGN1_END_RGN_END(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN1_END_RGN_END_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN1_END_RGN_END_MASK)
/*! @} */

/*! @name GDI_WPROT_RGN2_STA - GDI_WPROT_RGN2_STA */
/*! @{ */

#define VPU_VPU_ENC_GDI_WPROT_RGN2_STA_RGN_STA_MASK (0xFFFFFU)
#define VPU_VPU_ENC_GDI_WPROT_RGN2_STA_RGN_STA_SHIFT (0U)
#define VPU_VPU_ENC_GDI_WPROT_RGN2_STA_RGN_STA(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN2_STA_RGN_STA_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN2_STA_RGN_STA_MASK)
/*! @} */

/*! @name GDI_WPROT_RGN2_END - GDI_WPROT_RGN2_END */
/*! @{ */

#define VPU_VPU_ENC_GDI_WPROT_RGN2_END_RGN_END_MASK (0xFFFFFU)
#define VPU_VPU_ENC_GDI_WPROT_RGN2_END_RGN_END_SHIFT (0U)
#define VPU_VPU_ENC_GDI_WPROT_RGN2_END_RGN_END(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN2_END_RGN_END_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN2_END_RGN_END_MASK)
/*! @} */

/*! @name GDI_WPROT_RGN3_STA - GDI_WPROT_RGN3_STA */
/*! @{ */

#define VPU_VPU_ENC_GDI_WPROT_RGN3_STA_RGN_STA_MASK (0xFFFFFU)
#define VPU_VPU_ENC_GDI_WPROT_RGN3_STA_RGN_STA_SHIFT (0U)
#define VPU_VPU_ENC_GDI_WPROT_RGN3_STA_RGN_STA(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN3_STA_RGN_STA_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN3_STA_RGN_STA_MASK)
/*! @} */

/*! @name GDI_WPROT_RGN3_END - GDI_WPROT_RGN3_END */
/*! @{ */

#define VPU_VPU_ENC_GDI_WPROT_RGN3_END_RGN_END_MASK (0xFFFFFU)
#define VPU_VPU_ENC_GDI_WPROT_RGN3_END_RGN_END_SHIFT (0U)
#define VPU_VPU_ENC_GDI_WPROT_RGN3_END_RGN_END(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN3_END_RGN_END_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN3_END_RGN_END_MASK)
/*! @} */

/*! @name GDI_WPROT_RGN4_STA - GDI_WPROT_RGN4_STA */
/*! @{ */

#define VPU_VPU_ENC_GDI_WPROT_RGN4_STA_RGN_STA_MASK (0xFFFFFU)
#define VPU_VPU_ENC_GDI_WPROT_RGN4_STA_RGN_STA_SHIFT (0U)
#define VPU_VPU_ENC_GDI_WPROT_RGN4_STA_RGN_STA(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN4_STA_RGN_STA_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN4_STA_RGN_STA_MASK)
/*! @} */

/*! @name GDI_WPROT_RGN4_END - GDI_WPROT_RGN4_END */
/*! @{ */

#define VPU_VPU_ENC_GDI_WPROT_RGN4_END_RGN_END_MASK (0xFFFFFU)
#define VPU_VPU_ENC_GDI_WPROT_RGN4_END_RGN_END_SHIFT (0U)
#define VPU_VPU_ENC_GDI_WPROT_RGN4_END_RGN_END(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN4_END_RGN_END_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN4_END_RGN_END_MASK)
/*! @} */

/*! @name GDI_WPROT_RGN5_STA - GDI_WPROT_RGN5_STA */
/*! @{ */

#define VPU_VPU_ENC_GDI_WPROT_RGN5_STA_RGN_STA_MASK (0xFFFFFU)
#define VPU_VPU_ENC_GDI_WPROT_RGN5_STA_RGN_STA_SHIFT (0U)
#define VPU_VPU_ENC_GDI_WPROT_RGN5_STA_RGN_STA(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN5_STA_RGN_STA_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN5_STA_RGN_STA_MASK)
/*! @} */

/*! @name GDI_WPROT_RGN5_END - GDI_WPROT_RGN5_END */
/*! @{ */

#define VPU_VPU_ENC_GDI_WPROT_RGN5_END_RGN_END_MASK (0xFFFFFU)
#define VPU_VPU_ENC_GDI_WPROT_RGN5_END_RGN_END_SHIFT (0U)
#define VPU_VPU_ENC_GDI_WPROT_RGN5_END_RGN_END(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_WPROT_RGN5_END_RGN_END_SHIFT)) & VPU_VPU_ENC_GDI_WPROT_RGN5_END_RGN_END_MASK)
/*! @} */

/*! @name GDI_SRC_IDX_REPORT - GDI_SRC_IDX_REPORT */
/*! @{ */

#define VPU_VPU_ENC_GDI_SRC_IDX_REPORT_GDI_SRC_IDX_REPORT_MASK (0xFFU)
#define VPU_VPU_ENC_GDI_SRC_IDX_REPORT_GDI_SRC_IDX_REPORT_SHIFT (0U)
#define VPU_VPU_ENC_GDI_SRC_IDX_REPORT_GDI_SRC_IDX_REPORT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_SRC_IDX_REPORT_GDI_SRC_IDX_REPORT_SHIFT)) & VPU_VPU_ENC_GDI_SRC_IDX_REPORT_GDI_SRC_IDX_REPORT_MASK)
/*! @} */

/*! @name GDI_DEC_IDX_REPORT - GDI_DEC_IDX_REPORT */
/*! @{ */

#define VPU_VPU_ENC_GDI_DEC_IDX_REPORT_GDI_DEC_IDX_REPORT_MASK (0xFFU)
#define VPU_VPU_ENC_GDI_DEC_IDX_REPORT_GDI_DEC_IDX_REPORT_SHIFT (0U)
#define VPU_VPU_ENC_GDI_DEC_IDX_REPORT_GDI_DEC_IDX_REPORT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_DEC_IDX_REPORT_GDI_DEC_IDX_REPORT_SHIFT)) & VPU_VPU_ENC_GDI_DEC_IDX_REPORT_GDI_DEC_IDX_REPORT_MASK)
/*! @} */

/*! @name GDI_DISP_IDX_REPORT - GDI_DISP_IDX_REPORT */
/*! @{ */

#define VPU_VPU_ENC_GDI_DISP_IDX_REPORT_GDI_DISP_IDX_REPORT_MASK (0xFFU)
#define VPU_VPU_ENC_GDI_DISP_IDX_REPORT_GDI_DISP_IDX_REPORT_SHIFT (0U)
#define VPU_VPU_ENC_GDI_DISP_IDX_REPORT_GDI_DISP_IDX_REPORT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_DISP_IDX_REPORT_GDI_DISP_IDX_REPORT_SHIFT)) & VPU_VPU_ENC_GDI_DISP_IDX_REPORT_GDI_DISP_IDX_REPORT_MASK)
/*! @} */

/*! @name GDI_BUS_CTRL - GDI_BUS_CTRL */
/*! @{ */

#define VPU_VPU_ENC_GDI_BUS_CTRL_NO_MORE_REQ_PRI_MASK (0x1U)
#define VPU_VPU_ENC_GDI_BUS_CTRL_NO_MORE_REQ_PRI_SHIFT (0U)
#define VPU_VPU_ENC_GDI_BUS_CTRL_NO_MORE_REQ_PRI(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BUS_CTRL_NO_MORE_REQ_PRI_SHIFT)) & VPU_VPU_ENC_GDI_BUS_CTRL_NO_MORE_REQ_PRI_MASK)

#define VPU_VPU_ENC_GDI_BUS_CTRL_NO_MORE_REQ_SEC_MASK (0x10U)
#define VPU_VPU_ENC_GDI_BUS_CTRL_NO_MORE_REQ_SEC_SHIFT (4U)
#define VPU_VPU_ENC_GDI_BUS_CTRL_NO_MORE_REQ_SEC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BUS_CTRL_NO_MORE_REQ_SEC_SHIFT)) & VPU_VPU_ENC_GDI_BUS_CTRL_NO_MORE_REQ_SEC_MASK)
/*! @} */

/*! @name GDI_BUS_STATUS - GDI_BUS_STATUS */
/*! @{ */

#define VPU_VPU_ENC_GDI_BUS_STATUS_RD_EMPTY_MASK (0x1U)
#define VPU_VPU_ENC_GDI_BUS_STATUS_RD_EMPTY_SHIFT (0U)
#define VPU_VPU_ENC_GDI_BUS_STATUS_RD_EMPTY(x)   (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BUS_STATUS_RD_EMPTY_SHIFT)) & VPU_VPU_ENC_GDI_BUS_STATUS_RD_EMPTY_MASK)

#define VPU_VPU_ENC_GDI_BUS_STATUS_WD_EMPTY_MASK (0x2U)
#define VPU_VPU_ENC_GDI_BUS_STATUS_WD_EMPTY_SHIFT (1U)
#define VPU_VPU_ENC_GDI_BUS_STATUS_WD_EMPTY(x)   (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BUS_STATUS_WD_EMPTY_SHIFT)) & VPU_VPU_ENC_GDI_BUS_STATUS_WD_EMPTY_MASK)

#define VPU_VPU_ENC_GDI_BUS_STATUS_WRESP_EMPTY_MASK (0x4U)
#define VPU_VPU_ENC_GDI_BUS_STATUS_WRESP_EMPTY_SHIFT (2U)
#define VPU_VPU_ENC_GDI_BUS_STATUS_WRESP_EMPTY(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BUS_STATUS_WRESP_EMPTY_SHIFT)) & VPU_VPU_ENC_GDI_BUS_STATUS_WRESP_EMPTY_MASK)

#define VPU_VPU_ENC_GDI_BUS_STATUS_RD_EMPTY_SEC_MASK (0x10U)
#define VPU_VPU_ENC_GDI_BUS_STATUS_RD_EMPTY_SEC_SHIFT (4U)
#define VPU_VPU_ENC_GDI_BUS_STATUS_RD_EMPTY_SEC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BUS_STATUS_RD_EMPTY_SEC_SHIFT)) & VPU_VPU_ENC_GDI_BUS_STATUS_RD_EMPTY_SEC_MASK)

#define VPU_VPU_ENC_GDI_BUS_STATUS_WD_EMPTY_SEC_MASK (0x20U)
#define VPU_VPU_ENC_GDI_BUS_STATUS_WD_EMPTY_SEC_SHIFT (5U)
#define VPU_VPU_ENC_GDI_BUS_STATUS_WD_EMPTY_SEC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BUS_STATUS_WD_EMPTY_SEC_SHIFT)) & VPU_VPU_ENC_GDI_BUS_STATUS_WD_EMPTY_SEC_MASK)

#define VPU_VPU_ENC_GDI_BUS_STATUS_WRESP_EMPTY_SEC_MASK (0x40U)
#define VPU_VPU_ENC_GDI_BUS_STATUS_WRESP_EMPTY_SEC_SHIFT (6U)
#define VPU_VPU_ENC_GDI_BUS_STATUS_WRESP_EMPTY_SEC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_BUS_STATUS_WRESP_EMPTY_SEC_SHIFT)) & VPU_VPU_ENC_GDI_BUS_STATUS_WRESP_EMPTY_SEC_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_00_0 - GDI_PIC_INFO_00_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_00_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_00_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_00_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_00_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_00_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_00_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_00_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_00_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_00_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_00_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_00_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_00_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_00_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_00_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_00_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_00_1 - GDI_PIC_INFO_00_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_00_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_00_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_00_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_00_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_00_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_00_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_00_2 - GDI_PIC_INFO_00_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_00_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_00_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_00_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_00_3 - GDI_PIC_INFO_00_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_00_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_00_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_00_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_00_4 - GDI_PIC_INFO_00_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_00_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_00_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_00_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_00_5 - GDI_PIC_INFO_00_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_00_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_00_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_00_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_00_6 - GDI_PIC_INFO_00_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_00_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_00_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_00_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_00_7 - GDI_PIC_INFO_00_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_00_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_00_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_00_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_00_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_01_0 - GDI_PIC_INFO_01_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_01_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_01_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_01_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_01_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_01_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_01_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_01_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_01_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_01_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_01_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_01_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_01_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_01_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_01_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_01_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_01_1 - GDI_PIC_INFO_01_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_01_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_01_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_01_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_01_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_01_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_01_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_01_2 - GDI_PIC_INFO_01_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_01_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_01_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_01_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_01_3 - GDI_PIC_INFO_01_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_01_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_01_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_01_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_01_4 - GDI_PIC_INFO_01_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_01_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_01_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_01_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_01_5 - GDI_PIC_INFO_01_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_01_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_01_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_01_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_01_6 - GDI_PIC_INFO_01_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_01_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_01_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_01_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_01_7 - GDI_PIC_INFO_01_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_01_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_01_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_01_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_01_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_02_0 - GDI_PIC_INFO_02_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_02_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_02_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_02_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_02_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_02_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_02_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_02_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_02_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_02_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_02_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_02_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_02_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_02_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_02_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_02_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_02_1 - GDI_PIC_INFO_02_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_02_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_02_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_02_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_02_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_02_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_02_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_02_2 - GDI_PIC_INFO_02_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_02_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_02_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_02_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_02_3 - GDI_PIC_INFO_02_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_02_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_02_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_02_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_02_4 - GDI_PIC_INFO_02_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_02_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_02_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_02_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_02_5 - GDI_PIC_INFO_02_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_02_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_02_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_02_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_02_6 - GDI_PIC_INFO_02_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_02_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_02_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_02_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_02_7 - GDI_PIC_INFO_02_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_02_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_02_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_02_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_02_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_03_0 - GDI_PIC_INFO_03_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_03_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_03_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_03_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_03_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_03_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_03_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_03_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_03_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_03_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_03_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_03_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_03_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_03_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_03_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_03_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_03_1 - GDI_PIC_INFO_03_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_03_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_03_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_03_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_03_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_03_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_03_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_03_2 - GDI_PIC_INFO_03_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_03_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_03_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_03_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_03_3 - GDI_PIC_INFO_03_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_03_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_03_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_03_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_03_4 - GDI_PIC_INFO_03_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_03_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_03_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_03_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_03_5 - GDI_PIC_INFO_03_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_03_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_03_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_03_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_03_6 - GDI_PIC_INFO_03_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_03_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_03_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_03_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_03_7 - GDI_PIC_INFO_03_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_03_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_03_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_03_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_03_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_04_0 - GDI_PIC_INFO_04_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_04_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_04_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_04_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_04_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_04_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_04_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_04_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_04_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_04_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_04_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_04_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_04_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_04_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_04_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_04_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_04_1 - GDI_PIC_INFO_04_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_04_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_04_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_04_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_04_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_04_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_04_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_04_2 - GDI_PIC_INFO_04_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_04_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_04_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_04_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_04_3 - GDI_PIC_INFO_04_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_04_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_04_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_04_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_04_4 - GDI_PIC_INFO_04_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_04_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_04_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_04_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_04_5 - GDI_PIC_INFO_04_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_04_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_04_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_04_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_04_6 - GDI_PIC_INFO_04_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_04_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_04_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_04_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_04_7 - GDI_PIC_INFO_04_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_04_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_04_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_04_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_04_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_05_0 - GDI_PIC_INFO_05_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_05_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_05_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_05_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_05_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_05_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_05_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_05_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_05_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_05_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_05_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_05_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_05_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_05_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_05_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_05_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_05_1 - GDI_PIC_INFO_05_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_05_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_05_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_05_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_05_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_05_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_05_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_05_2 - GDI_PIC_INFO_05_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_05_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_05_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_05_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_05_3 - GDI_PIC_INFO_05_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_05_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_05_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_05_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_05_4 - GDI_PIC_INFO_05_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_05_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_05_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_05_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_05_5 - GDI_PIC_INFO_05_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_05_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_05_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_05_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_05_6 - GDI_PIC_INFO_05_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_05_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_05_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_05_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_05_7 - GDI_PIC_INFO_05_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_05_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_05_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_05_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_05_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_06_0 - GDI_PIC_INFO_06_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_06_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_06_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_06_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_06_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_06_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_06_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_06_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_06_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_06_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_06_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_06_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_06_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_06_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_06_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_06_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_06_1 - GDI_PIC_INFO_06_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_06_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_06_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_06_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_06_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_06_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_06_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_06_2 - GDI_PIC_INFO_06_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_06_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_06_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_06_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_06_3 - GDI_PIC_INFO_06_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_06_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_06_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_06_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_06_4 - GDI_PIC_INFO_06_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_06_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_06_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_06_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_06_5 - GDI_PIC_INFO_06_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_06_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_06_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_06_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_06_6 - GDI_PIC_INFO_06_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_06_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_06_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_06_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_06_7 - GDI_PIC_INFO_06_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_06_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_06_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_06_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_06_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_07_0 - GDI_PIC_INFO_07_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_07_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_07_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_07_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_07_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_07_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_07_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_07_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_07_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_07_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_07_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_07_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_07_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_07_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_07_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_07_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_07_1 - GDI_PIC_INFO_07_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_07_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_07_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_07_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_07_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_07_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_07_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_07_2 - GDI_PIC_INFO_07_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_07_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_07_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_07_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_07_3 - GDI_PIC_INFO_07_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_07_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_07_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_07_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_07_4 - GDI_PIC_INFO_07_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_07_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_07_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_07_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_07_5 - GDI_PIC_INFO_07_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_07_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_07_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_07_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_07_6 - GDI_PIC_INFO_07_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_07_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_07_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_07_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_07_7 - GDI_PIC_INFO_07_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_07_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_07_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_07_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_07_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_08_0 - GDI_PIC_INFO_08_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_08_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_08_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_08_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_08_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_08_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_08_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_08_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_08_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_08_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_08_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_08_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_08_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_08_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_08_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_08_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_08_1 - GDI_PIC_INFO_08_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_08_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_08_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_08_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_08_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_08_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_08_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_08_2 - GDI_PIC_INFO_08_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_08_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_08_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_08_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_08_3 - GDI_PIC_INFO_08_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_08_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_08_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_08_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_08_4 - GDI_PIC_INFO_08_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_08_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_08_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_08_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_08_5 - GDI_PIC_INFO_08_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_08_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_08_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_08_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_08_6 - GDI_PIC_INFO_08_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_08_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_08_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_08_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_08_7 - GDI_PIC_INFO_08_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_08_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_08_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_08_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_08_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_09_0 - GDI_PIC_INFO_09_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_09_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_09_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_09_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_09_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_09_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_09_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_09_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_09_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_09_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_09_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_09_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_09_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_09_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_09_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_09_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_09_1 - GDI_PIC_INFO_09_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_09_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_09_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_09_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_09_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_09_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_09_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_09_2 - GDI_PIC_INFO_09_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_09_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_09_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_09_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_09_3 - GDI_PIC_INFO_09_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_09_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_09_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_09_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_09_4 - GDI_PIC_INFO_09_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_09_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_09_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_09_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_09_5 - GDI_PIC_INFO_09_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_09_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_09_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_09_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_09_6 - GDI_PIC_INFO_09_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_09_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_09_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_09_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_09_7 - GDI_PIC_INFO_09_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_09_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_09_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_09_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_09_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_10_0 - GDI_PIC_INFO_10_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_10_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_10_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_10_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_10_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_10_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_10_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_10_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_10_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_10_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_10_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_10_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_10_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_10_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_10_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_10_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_10_1 - GDI_PIC_INFO_10_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_10_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_10_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_10_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_10_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_10_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_10_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_10_2 - GDI_PIC_INFO_10_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_10_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_10_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_10_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_10_3 - GDI_PIC_INFO_10_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_10_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_10_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_10_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_10_4 - GDI_PIC_INFO_10_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_10_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_10_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_10_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_10_5 - GDI_PIC_INFO_10_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_10_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_10_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_10_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_10_6 - GDI_PIC_INFO_10_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_10_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_10_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_10_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_10_7 - GDI_PIC_INFO_10_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_10_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_10_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_10_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_10_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_11_0 - GDI_PIC_INFO_11_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_11_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_11_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_11_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_11_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_11_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_11_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_11_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_11_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_11_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_11_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_11_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_11_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_11_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_11_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_11_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_11_1 - GDI_PIC_INFO_11_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_11_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_11_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_11_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_11_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_11_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_11_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_11_2 - GDI_PIC_INFO_11_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_11_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_11_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_11_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_11_3 - GDI_PIC_INFO_11_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_11_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_11_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_11_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_11_4 - GDI_PIC_INFO_11_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_11_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_11_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_11_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_11_5 - GDI_PIC_INFO_11_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_11_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_11_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_11_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_11_6 - GDI_PIC_INFO_11_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_11_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_11_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_11_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_11_7 - GDI_PIC_INFO_11_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_11_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_11_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_11_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_11_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_12_0 - GDI_PIC_INFO_12_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_12_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_12_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_12_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_12_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_12_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_12_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_12_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_12_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_12_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_12_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_12_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_12_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_12_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_12_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_12_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_12_1 - GDI_PIC_INFO_12_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_12_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_12_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_12_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_12_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_12_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_12_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_12_2 - GDI_PIC_INFO_12_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_12_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_12_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_12_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_12_3 - GDI_PIC_INFO_12_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_12_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_12_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_12_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_12_4 - GDI_PIC_INFO_12_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_12_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_12_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_12_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_12_5 - GDI_PIC_INFO_12_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_12_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_12_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_12_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_12_6 - GDI_PIC_INFO_12_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_12_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_12_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_12_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_12_7 - GDI_PIC_INFO_12_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_12_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_12_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_12_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_12_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_13_0 - GDI_PIC_INFO_13_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_13_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_13_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_13_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_13_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_13_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_13_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_13_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_13_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_13_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_13_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_13_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_13_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_13_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_13_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_13_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_13_1 - GDI_PIC_INFO_13_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_13_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_13_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_13_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_13_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_13_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_13_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_13_2 - GDI_PIC_INFO_13_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_13_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_13_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_13_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_13_3 - GDI_PIC_INFO_13_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_13_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_13_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_13_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_13_4 - GDI_PIC_INFO_13_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_13_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_13_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_13_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_13_5 - GDI_PIC_INFO_13_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_13_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_13_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_13_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_13_6 - GDI_PIC_INFO_13_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_13_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_13_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_13_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_13_7 - GDI_PIC_INFO_13_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_13_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_13_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_13_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_13_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_14_0 - GDI_PIC_INFO_14_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_14_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_14_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_14_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_14_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_14_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_14_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_14_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_14_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_14_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_14_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_14_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_14_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_14_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_14_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_14_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_14_1 - GDI_PIC_INFO_14_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_14_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_14_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_14_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_14_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_14_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_14_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_14_2 - GDI_PIC_INFO_14_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_14_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_14_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_14_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_14_3 - GDI_PIC_INFO_14_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_14_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_14_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_14_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_14_4 - GDI_PIC_INFO_14_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_14_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_14_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_14_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_14_5 - GDI_PIC_INFO_14_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_14_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_14_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_14_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_14_6 - GDI_PIC_INFO_14_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_14_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_14_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_14_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_14_7 - GDI_PIC_INFO_14_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_14_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_14_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_14_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_14_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_15_0 - GDI_PIC_INFO_15_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_15_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_15_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_15_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_15_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_15_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_15_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_15_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_15_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_15_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_15_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_15_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_15_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_15_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_15_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_15_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_15_1 - GDI_PIC_INFO_15_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_15_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_15_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_15_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_15_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_15_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_15_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_15_2 - GDI_PIC_INFO_15_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_15_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_15_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_15_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_15_3 - GDI_PIC_INFO_15_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_15_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_15_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_15_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_15_4 - GDI_PIC_INFO_15_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_15_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_15_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_15_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_15_5 - GDI_PIC_INFO_15_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_15_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_15_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_15_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_15_6 - GDI_PIC_INFO_15_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_15_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_15_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_15_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_15_7 - GDI_PIC_INFO_15_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_15_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_15_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_15_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_15_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_16_0 - GDI_PIC_INFO_16_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_16_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_16_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_16_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_16_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_16_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_16_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_16_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_16_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_16_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_16_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_16_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_16_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_16_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_16_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_16_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_16_1 - GDI_PIC_INFO_16_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_16_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_16_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_16_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_16_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_16_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_16_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_16_2 - GDI_PIC_INFO_16_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_16_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_16_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_16_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_16_3 - GDI_PIC_INFO_16_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_16_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_16_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_16_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_16_4 - GDI_PIC_INFO_16_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_16_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_16_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_16_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_16_5 - GDI_PIC_INFO_16_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_16_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_16_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_16_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_16_6 - GDI_PIC_INFO_16_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_16_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_16_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_16_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_16_7 - GDI_PIC_INFO_16_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_16_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_16_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_16_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_16_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_17_0 - GDI_PIC_INFO_17_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_17_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_17_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_17_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_17_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_17_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_17_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_17_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_17_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_17_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_17_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_17_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_17_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_17_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_17_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_17_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_17_1 - GDI_PIC_INFO_17_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_17_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_17_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_17_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_17_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_17_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_17_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_17_2 - GDI_PIC_INFO_17_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_17_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_17_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_17_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_17_3 - GDI_PIC_INFO_17_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_17_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_17_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_17_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_17_4 - GDI_PIC_INFO_17_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_17_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_17_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_17_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_17_5 - GDI_PIC_INFO_17_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_17_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_17_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_17_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_17_6 - GDI_PIC_INFO_17_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_17_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_17_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_17_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_17_7 - GDI_PIC_INFO_17_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_17_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_17_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_17_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_17_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_18_0 - GDI_PIC_INFO_18_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_18_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_18_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_18_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_18_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_18_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_18_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_18_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_18_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_18_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_18_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_18_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_18_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_18_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_18_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_18_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_18_1 - GDI_PIC_INFO_18_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_18_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_18_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_18_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_18_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_18_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_18_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_18_2 - GDI_PIC_INFO_18_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_18_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_18_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_18_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_18_3 - GDI_PIC_INFO_18_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_18_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_18_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_18_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_18_4 - GDI_PIC_INFO_18_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_18_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_18_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_18_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_18_5 - GDI_PIC_INFO_18_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_18_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_18_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_18_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_18_6 - GDI_PIC_INFO_18_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_18_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_18_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_18_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_18_7 - GDI_PIC_INFO_18_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_18_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_18_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_18_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_18_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_19_0 - GDI_PIC_INFO_19_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_19_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_19_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_19_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_19_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_19_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_19_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_19_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_19_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_19_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_19_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_19_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_19_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_19_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_19_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_19_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_19_1 - GDI_PIC_INFO_19_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_19_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_19_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_19_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_19_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_19_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_19_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_19_2 - GDI_PIC_INFO_19_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_19_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_19_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_19_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_19_3 - GDI_PIC_INFO_19_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_19_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_19_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_19_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_19_4 - GDI_PIC_INFO_19_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_19_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_19_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_19_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_19_5 - GDI_PIC_INFO_19_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_19_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_19_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_19_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_19_6 - GDI_PIC_INFO_19_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_19_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_19_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_19_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_19_7 - GDI_PIC_INFO_19_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_19_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_19_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_19_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_19_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_20_0 - GDI_PIC_INFO_20_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_20_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_20_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_20_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_20_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_20_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_20_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_20_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_20_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_20_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_20_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_20_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_20_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_20_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_20_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_20_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_20_1 - GDI_PIC_INFO_20_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_20_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_20_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_20_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_20_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_20_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_20_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_20_2 - GDI_PIC_INFO_20_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_20_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_20_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_20_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_20_3 - GDI_PIC_INFO_20_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_20_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_20_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_20_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_20_4 - GDI_PIC_INFO_20_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_20_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_20_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_20_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_20_5 - GDI_PIC_INFO_20_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_20_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_20_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_20_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_20_6 - GDI_PIC_INFO_20_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_20_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_20_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_20_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_20_7 - GDI_PIC_INFO_20_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_20_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_20_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_20_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_20_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_21_0 - GDI_PIC_INFO_21_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_21_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_21_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_21_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_21_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_21_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_21_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_21_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_21_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_21_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_21_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_21_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_21_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_21_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_21_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_21_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_21_1 - GDI_PIC_INFO_21_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_21_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_21_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_21_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_21_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_21_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_21_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_21_2 - GDI_PIC_INFO_21_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_21_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_21_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_21_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_21_3 - GDI_PIC_INFO_21_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_21_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_21_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_21_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_21_4 - GDI_PIC_INFO_21_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_21_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_21_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_21_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_21_5 - GDI_PIC_INFO_21_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_21_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_21_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_21_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_21_6 - GDI_PIC_INFO_21_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_21_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_21_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_21_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_21_7 - GDI_PIC_INFO_21_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_21_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_21_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_21_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_21_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_22_0 - GDI_PIC_INFO_22_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_22_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_22_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_22_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_22_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_22_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_22_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_22_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_22_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_22_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_22_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_22_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_22_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_22_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_22_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_22_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_22_1 - GDI_PIC_INFO_22_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_22_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_22_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_22_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_22_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_22_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_22_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_22_2 - GDI_PIC_INFO_22_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_22_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_22_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_22_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_22_3 - GDI_PIC_INFO_22_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_22_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_22_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_22_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_22_4 - GDI_PIC_INFO_22_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_22_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_22_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_22_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_22_5 - GDI_PIC_INFO_22_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_22_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_22_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_22_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_22_6 - GDI_PIC_INFO_22_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_22_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_22_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_22_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_22_7 - GDI_PIC_INFO_22_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_22_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_22_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_22_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_22_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_23_0 - GDI_PIC_INFO_23_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_23_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_23_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_23_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_23_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_23_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_23_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_23_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_23_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_23_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_23_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_23_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_23_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_23_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_23_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_23_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_23_1 - GDI_PIC_INFO_23_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_23_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_23_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_23_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_23_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_23_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_23_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_23_2 - GDI_PIC_INFO_23_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_23_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_23_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_23_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_23_3 - GDI_PIC_INFO_23_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_23_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_23_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_23_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_23_4 - GDI_PIC_INFO_23_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_23_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_23_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_23_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_23_5 - GDI_PIC_INFO_23_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_23_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_23_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_23_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_23_6 - GDI_PIC_INFO_23_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_23_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_23_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_23_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_23_7 - GDI_PIC_INFO_23_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_23_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_23_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_23_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_23_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_24_0 - GDI_PIC_INFO_24_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_24_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_24_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_24_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_24_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_24_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_24_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_24_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_24_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_24_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_24_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_24_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_24_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_24_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_24_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_24_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_24_1 - GDI_PIC_INFO_24_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_24_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_24_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_24_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_24_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_24_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_24_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_24_2 - GDI_PIC_INFO_24_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_24_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_24_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_24_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_24_3 - GDI_PIC_INFO_24_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_24_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_24_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_24_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_24_4 - GDI_PIC_INFO_24_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_24_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_24_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_24_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_24_5 - GDI_PIC_INFO_24_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_24_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_24_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_24_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_24_6 - GDI_PIC_INFO_24_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_24_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_24_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_24_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_24_7 - GDI_PIC_INFO_24_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_24_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_24_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_24_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_24_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_25_0 - GDI_PIC_INFO_25_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_25_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_25_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_25_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_25_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_25_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_25_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_25_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_25_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_25_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_25_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_25_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_25_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_25_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_25_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_25_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_25_1 - GDI_PIC_INFO_25_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_25_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_25_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_25_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_25_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_25_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_25_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_25_2 - GDI_PIC_INFO_25_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_25_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_25_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_25_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_25_3 - GDI_PIC_INFO_25_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_25_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_25_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_25_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_25_4 - GDI_PIC_INFO_25_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_25_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_25_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_25_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_25_5 - GDI_PIC_INFO_25_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_25_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_25_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_25_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_25_6 - GDI_PIC_INFO_25_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_25_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_25_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_25_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_25_7 - GDI_PIC_INFO_25_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_25_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_25_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_25_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_25_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_26_0 - GDI_PIC_INFO_26_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_26_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_26_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_26_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_26_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_26_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_26_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_26_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_26_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_26_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_26_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_26_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_26_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_26_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_26_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_26_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_26_1 - GDI_PIC_INFO_26_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_26_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_26_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_26_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_26_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_26_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_26_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_26_2 - GDI_PIC_INFO_26_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_26_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_26_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_26_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_26_3 - GDI_PIC_INFO_26_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_26_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_26_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_26_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_26_4 - GDI_PIC_INFO_26_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_26_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_26_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_26_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_26_5 - GDI_PIC_INFO_26_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_26_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_26_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_26_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_26_6 - GDI_PIC_INFO_26_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_26_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_26_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_26_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_26_7 - GDI_PIC_INFO_26_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_26_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_26_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_26_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_26_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_27_0 - GDI_PIC_INFO_27_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_27_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_27_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_27_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_27_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_27_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_27_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_27_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_27_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_27_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_27_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_27_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_27_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_27_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_27_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_27_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_27_1 - GDI_PIC_INFO_27_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_27_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_27_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_27_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_27_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_27_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_27_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_27_2 - GDI_PIC_INFO_27_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_27_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_27_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_27_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_27_3 - GDI_PIC_INFO_27_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_27_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_27_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_27_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_27_4 - GDI_PIC_INFO_27_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_27_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_27_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_27_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_27_5 - GDI_PIC_INFO_27_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_27_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_27_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_27_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_27_6 - GDI_PIC_INFO_27_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_27_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_27_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_27_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_27_7 - GDI_PIC_INFO_27_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_27_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_27_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_27_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_27_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_28_0 - GDI_PIC_INFO_28_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_28_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_28_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_28_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_28_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_28_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_28_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_28_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_28_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_28_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_28_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_28_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_28_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_28_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_28_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_28_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_28_1 - GDI_PIC_INFO_28_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_28_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_28_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_28_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_28_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_28_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_28_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_28_2 - GDI_PIC_INFO_28_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_28_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_28_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_28_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_28_3 - GDI_PIC_INFO_28_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_28_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_28_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_28_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_28_4 - GDI_PIC_INFO_28_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_28_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_28_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_28_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_28_5 - GDI_PIC_INFO_28_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_28_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_28_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_28_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_28_6 - GDI_PIC_INFO_28_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_28_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_28_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_28_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_28_7 - GDI_PIC_INFO_28_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_28_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_28_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_28_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_28_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_29_0 - GDI_PIC_INFO_29_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_29_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_29_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_29_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_29_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_29_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_29_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_29_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_29_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_29_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_29_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_29_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_29_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_29_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_29_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_29_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_29_1 - GDI_PIC_INFO_29_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_29_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_29_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_29_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_29_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_29_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_29_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_29_2 - GDI_PIC_INFO_29_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_29_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_29_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_29_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_29_3 - GDI_PIC_INFO_29_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_29_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_29_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_29_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_29_4 - GDI_PIC_INFO_29_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_29_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_29_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_29_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_29_5 - GDI_PIC_INFO_29_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_29_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_29_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_29_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_29_6 - GDI_PIC_INFO_29_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_29_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_29_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_29_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_29_7 - GDI_PIC_INFO_29_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_29_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_29_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_29_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_29_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_30_0 - GDI_PIC_INFO_30_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_30_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_30_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_30_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_30_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_30_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_30_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_30_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_30_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_30_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_30_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_30_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_30_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_30_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_30_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_30_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_30_1 - GDI_PIC_INFO_30_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_30_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_30_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_30_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_30_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_30_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_30_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_30_2 - GDI_PIC_INFO_30_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_30_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_30_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_30_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_30_3 - GDI_PIC_INFO_30_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_30_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_30_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_30_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_30_4 - GDI_PIC_INFO_30_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_30_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_30_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_30_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_30_5 - GDI_PIC_INFO_30_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_30_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_30_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_30_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_30_6 - GDI_PIC_INFO_30_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_30_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_30_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_30_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_30_7 - GDI_PIC_INFO_30_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_30_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_30_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_30_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_30_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_31_0 - GDI_PIC_INFO_31_0 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_31_0_Stride_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_0_Stride_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_0_Stride(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_31_0_Stride_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_31_0_Stride_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_31_0_CbCrInterleaved_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_0_CbCrInterleaved_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_0_CbCrInterleaved(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_31_0_CbCrInterleaved_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_31_0_CbCrInterleaved_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_31_0_ColorMode_MASK (0xE0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_0_ColorMode_SHIFT (17U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_0_ColorMode(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_31_0_ColorMode_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_31_0_ColorMode_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_31_0_FrameMap_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_0_FrameMap_SHIFT (20U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_0_FrameMap(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_31_0_FrameMap_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_31_0_FrameMap_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_31_0_Reserved0_MASK (0xFF000000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_0_Reserved0_SHIFT (24U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_0_Reserved0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_31_0_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_31_0_Reserved0_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_31_1 - GDI_PIC_INFO_31_1 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_31_1_PicVerSizeLuma_MASK (0xFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_1_PicVerSizeLuma_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_1_PicVerSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_31_1_PicVerSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_31_1_PicVerSizeLuma_MASK)

#define VPU_VPU_ENC_GDI_PIC_INFO_31_1_PicHorSizeLuma_MASK (0xFFFF0000U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_1_PicHorSizeLuma_SHIFT (16U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_1_PicHorSizeLuma(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_31_1_PicHorSizeLuma_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_31_1_PicHorSizeLuma_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_31_2 - GDI_PIC_INFO_31_2 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_31_2_LumaTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_2_LumaTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_2_LumaTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_31_2_LumaTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_31_2_LumaTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_31_3 - GDI_PIC_INFO_31_3 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_31_3_CbTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_3_CbTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_3_CbTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_31_3_CbTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_31_3_CbTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_31_4 - GDI_PIC_INFO_31_4 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_31_4_CrTopBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_4_CrTopBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_4_CrTopBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_31_4_CrTopBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_31_4_CrTopBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_31_5 - GDI_PIC_INFO_31_5 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_31_5_LumaBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_5_LumaBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_5_LumaBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_31_5_LumaBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_31_5_LumaBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_31_6 - GDI_PIC_INFO_31_6 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_31_6_CbBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_6_CbBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_6_CbBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_31_6_CbBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_31_6_CbBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_PIC_INFO_31_7 - GDI_PIC_INFO_31_7 */
/*! @{ */

#define VPU_VPU_ENC_GDI_PIC_INFO_31_7_CrBotBaseAddr_MASK (0xFFFFFFFFU)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_7_CrBotBaseAddr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_PIC_INFO_31_7_CrBotBaseAddr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_PIC_INFO_31_7_CrBotBaseAddr_SHIFT)) & VPU_VPU_ENC_GDI_PIC_INFO_31_7_CrBotBaseAddr_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT00 - GDI_XY2AXI_LUM_BIT00 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT00_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT01 - GDI_XY2AXI_LUM_BIT01 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT01_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT02 - GDI_XY2AXI_LUM_BIT02 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT02_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT03 - GDI_XY2AXI_LUM_BIT03 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT03_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT04 - GDI_XY2AXI_LUM_BIT04 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT04_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT05 - GDI_XY2AXI_LUM_BIT05 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT05_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT06 - GDI_XY2AXI_LUM_BIT06 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT06_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT07 - GDI_XY2AXI_LUM_BIT07 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT07_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT08 - GDI_XY2AXI_LUM_BIT08 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT08_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT09 - GDI_XY2AXI_LUM_BIT09 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT09_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT0A - GDI_XY2AXI_LUM_BIT0A */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0A_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT0B - GDI_XY2AXI_LUM_BIT0B */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0B_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT0C - GDI_XY2AXI_LUM_BIT0C */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0C_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT0D - GDI_XY2AXI_LUM_BIT0D */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0D_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT0E - GDI_XY2AXI_LUM_BIT0E */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0E_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT0F - GDI_XY2AXI_LUM_BIT0F */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT0F_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT10 - GDI_XY2AXI_LUM_BIT10 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT10_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT11 - GDI_XY2AXI_LUM_BIT11 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT11_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT12 - GDI_XY2AXI_LUM_BIT12 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT12_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT13 - GDI_XY2AXI_LUM_BIT13 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT13_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT14 - GDI_XY2AXI_LUM_BIT14 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT14_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT15 - GDI_XY2AXI_LUM_BIT15 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT15_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT16 - GDI_XY2AXI_LUM_BIT16 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT16_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT17 - GDI_XY2AXI_LUM_BIT17 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT17_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT18 - GDI_XY2AXI_LUM_BIT18 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT18_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT19 - GDI_XY2AXI_LUM_BIT19 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT19_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT1A - GDI_XY2AXI_LUM_BIT1A */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1A_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT1B - GDI_XY2AXI_LUM_BIT1B */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1B_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT1C - GDI_XY2AXI_LUM_BIT1C */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1C_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT1D - GDI_XY2AXI_LUM_BIT1D */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1D_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT1E - GDI_XY2AXI_LUM_BIT1E */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1E_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_LUM_BIT1F - GDI_XY2AXI_LUM_BIT1F */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_LUM_BIT1F_LUMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT00 - GDI_XY2AXI_CHR_BIT00 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT00_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT01 - GDI_XY2AXI_CHR_BIT01 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT01_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT02 - GDI_XY2AXI_CHR_BIT02 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT02_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT03 - GDI_XY2AXI_CHR_BIT03 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT03_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT04 - GDI_XY2AXI_CHR_BIT04 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT04_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT05 - GDI_XY2AXI_CHR_BIT05 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT05_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT06 - GDI_XY2AXI_CHR_BIT06 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT06_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT07 - GDI_XY2AXI_CHR_BIT07 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT07_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT08 - GDI_XY2AXI_CHR_BIT08 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT08_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT09 - GDI_XY2AXI_CHR_BIT09 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT09_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT0A - GDI_XY2AXI_CHR_BIT0A */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0A_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT0B - GDI_XY2AXI_CHR_BIT0B */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0B_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT0C - GDI_XY2AXI_CHR_BIT0C */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0C_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT0D - GDI_XY2AXI_CHR_BIT0D */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0D_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT0E - GDI_XY2AXI_CHR_BIT0E */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0E_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT0F - GDI_XY2AXI_CHR_BIT0F */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT0F_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT10 - GDI_XY2AXI_CHR_BIT10 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT10_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT11 - GDI_XY2AXI_CHR_BIT11 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT11_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT12 - GDI_XY2AXI_CHR_BIT12 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT12_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT13 - GDI_XY2AXI_CHR_BIT13 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT13_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT14 - GDI_XY2AXI_CHR_BIT14 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT14_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT15 - GDI_XY2AXI_CHR_BIT15 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT15_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT16 - GDI_XY2AXI_CHR_BIT16 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT16_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT17 - GDI_XY2AXI_CHR_BIT17 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT17_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT18 - GDI_XY2AXI_CHR_BIT18 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT18_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT19 - GDI_XY2AXI_CHR_BIT19 */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT19_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT1A - GDI_XY2AXI_CHR_BIT1A */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1A_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT1B - GDI_XY2AXI_CHR_BIT1B */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1B_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT1C - GDI_XY2AXI_CHR_BIT1C */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1C_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT1D - GDI_XY2AXI_CHR_BIT1D */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1D_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT1E - GDI_XY2AXI_CHR_BIT1E */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1E_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CHR_BIT1F - GDI_XY2AXI_CHR_BIT1F */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_bit_sel_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_bit_sel_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_bit_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_bit_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_bit_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_xy_sel_MASK (0x10U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_xy_sel_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_xy_sel(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_xy_sel_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_xy_sel_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_tbxor_MASK (0x20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_tbxor_SHIFT (5U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_tbxor(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_tbxor_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_tbxor_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_zero_MASK (0x40U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_zero_SHIFT (6U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_zero(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_zero_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_zero_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_inv_MASK (0x80U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_inv_SHIFT (7U)
#define VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_inv(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_inv_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CHR_BIT1F_CHROMA_inv_MASK)
/*! @} */

/*! @name GDI_XY2AXI_CFG - GDI_XY2AXI_CFG */
/*! @{ */

#define VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_field_chr_MASK (0xFU)
#define VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_field_chr_SHIFT (0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_field_chr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_field_chr_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_field_chr_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_frame_chr_MASK (0xF0U)
#define VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_frame_chr_SHIFT (4U)
#define VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_frame_chr(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_frame_chr_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_frame_chr_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_field_lum_MASK (0xF00U)
#define VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_field_lum_SHIFT (8U)
#define VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_field_lum(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_field_lum_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_field_lum_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_frame_lum_MASK (0xF000U)
#define VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_frame_lum_SHIFT (12U)
#define VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_frame_lum(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_frame_lum_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CFG_granule_frame_lum_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CFG_burst_inc_dir_MASK (0x10000U)
#define VPU_VPU_ENC_GDI_XY2AXI_CFG_burst_inc_dir_SHIFT (16U)
#define VPU_VPU_ENC_GDI_XY2AXI_CFG_burst_inc_dir(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CFG_burst_inc_dir_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CFG_burst_inc_dir_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CFG_Reserved0_MASK (0x60000U)
#define VPU_VPU_ENC_GDI_XY2AXI_CFG_Reserved0_SHIFT (17U)
#define VPU_VPU_ENC_GDI_XY2AXI_CFG_Reserved0(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CFG_Reserved0_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CFG_Reserved0_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CFG_tb_seperate_map_MASK (0x80000U)
#define VPU_VPU_ENC_GDI_XY2AXI_CFG_tb_seperate_map_SHIFT (19U)
#define VPU_VPU_ENC_GDI_XY2AXI_CFG_tb_seperate_map(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CFG_tb_seperate_map_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CFG_tb_seperate_map_MASK)

#define VPU_VPU_ENC_GDI_XY2AXI_CFG_max_burst_1d_MASK (0xF00000U)
#define VPU_VPU_ENC_GDI_XY2AXI_CFG_max_burst_1d_SHIFT (20U)
#define VPU_VPU_ENC_GDI_XY2AXI_CFG_max_burst_1d(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_XY2AXI_CFG_max_burst_1d_SHIFT)) & VPU_VPU_ENC_GDI_XY2AXI_CFG_max_burst_1d_MASK)
/*! @} */

/*! @name GDI_AXI_BASE_EXTEND - GDI_AXI_BASE_EXTEND */
/*! @{ */

#define VPU_VPU_ENC_GDI_AXI_BASE_EXTEND_r_base_ext_MASK (0xFFU)
#define VPU_VPU_ENC_GDI_AXI_BASE_EXTEND_r_base_ext_SHIFT (0U)
#define VPU_VPU_ENC_GDI_AXI_BASE_EXTEND_r_base_ext(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_ENC_GDI_AXI_BASE_EXTEND_r_base_ext_SHIFT)) & VPU_VPU_ENC_GDI_AXI_BASE_EXTEND_r_base_ext_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VPU_VPU_ENC_Register_Masks */


/*!
 * @}
 */ /* end of group VPU_VPU_ENC_Peripheral_Access_Layer */


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


#endif  /* PERI_VPU_VPU_ENC_H_ */

