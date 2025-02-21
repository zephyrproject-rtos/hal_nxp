/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_FSP_H_
#define FSL_FSP_H_

#include "fsl_common.h"

/*!
 * @addtogroup qn_fsp
 * @{
 */

/*! @file */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

/*!
 * @addtogroup fsp_driver
 * @{
 */
#ifndef _ARM_MATH_H
/**
 * @brief 32-bit fractional data type in 1.31 format.
 */
typedef int32_t q31_t;

/**
 * @brief 32-bit floating-point type definition.
 */
typedef float float32_t;
#endif

#if defined(__CC_ARM)
#pragma anon_unions
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief Fsp driver version 2.0.2. */
#define FSL_FSP_DRIVER_VERSION (MAKE_VERSION(2, 0, 2))
/*! @} */

#define toWordAddr(addr) ((uint32_t)(addr) >> 2)
/**
 * @brief Macros to config the FSP Matrix operation unit.
 */
#define MAT_OP_CONFIG(inv_stop, lu_stop, mat_k, mat_n, mat_m, o_format, i_format, op_mode)            \
    (FSP_MOU_CTRL_UINV_STOP(inv_stop) | FSP_MOU_CTRL_LU_STOP(lu_stop) | FSP_MOU_CTRL_MAT_K(mat_k) |   \
     FSP_MOU_CTRL_MAT_N(mat_n) | FSP_MOU_CTRL_MAT_M(mat_m) | FSP_MOU_CTRL_MOU_DOUT_FP_SEL(o_format) | \
     FSP_MOU_CTRL_MOU_DIN_FP_SEL(i_format) | FSP_MOU_CTRL_OP_MODE(op_mode))

/**
 * @brief Macros to config the FSP transfer engine.
 */
#define TE_CONFIG(te_point, te_scale, o_format, i_format, io_mode, type)                                    \
    (FSP_TE_CTRL_TE_PTS(te_point) | FSP_TE_CTRL_TE_SCALE(te_scale) | FSP_TE_CTRL_TE_DOUT_FP_SEL(o_format) | \
     FSP_TE_CTRL_TE_DIN_FP_SEL(i_format) | FSP_TE_CTRL_TE_IO_MODE(io_mode) | type)

/**
 * @brief Macros to config the FSP statistic engine module.
 */

#define SE_CONFIG(se_point, o_format, i_format, pwr_en, sum_en, max_idx_en, min_idx_en, max_sel, min_sel)            \
    (FSP_SE_CTRL_SE_LEN(se_point - 1) | FSP_SE_CTRL_SE_DOUT_FP_SEL(o_format) | FSP_SE_CTRL_SE_DIN_FP_SEL(i_format) | \
     FSP_SE_CTRL_PWR_EN(pwr_en) | FSP_SE_CTRL_SUM_EN(sum_en) | FSP_SE_CTRL_MAX_IDX_EN(max_idx_en) |                  \
     FSP_SE_CTRL_MIN_IDX_EN(min_idx_en) | FSP_SE_CTRL_MAX_SEL(max_sel) | FSP_SE_CTRL_MIN_SEL(min_sel))

/**
 * @brief Macros to config the FSP Correlation module.
 */

#define CORR_CONFIG(corr_y_len, corr_x_len, o_format, i_format)                        \
    (FSP_COR_CTRL_COR_Y_LEN(corr_y_len - 1) | FSP_COR_CTRL_COR_X_LEN(corr_x_len - 1) | \
     FSP_COR_CTRL_COR_DOUT_FP_SEL(o_format) | FSP_COR_CTRL_COR_DOUT_FP_SEL(i_format))

/**
 * @brief Macros to config the FSP FIR filter module.
 */

#define FIR_CONFIG(buf_clr_en, num_taps, p_coeffs)                                                   \
    (FSP_FIR_CFG_CH0_FIR_CH0_BUF_CLR(buf_clr_en) | FSP_FIR_CFG_CH0_FIR_CH0_TAP_LEN((num_taps - 1)) | \
     ((uint32_t)p_coeffs & FSP_FIR_CFG_CH0_FIR_CH0_COEF_BASE_MASK))

typedef enum _fsp_mou_dout_fp_sel
{
    kFSP_MouDoutFpSelFloat = 0x0U, /*!< float */
    kFSP_MouDoutFpSelFix   = 0x1U, /*!< fix */
} fsp_mou_dout_fp_sel_t;

typedef enum _fsp_mou_din_fp_sel
{
    kFSP_MouDinFpSelFloat = 0x0U, /*!< float */
    kFSP_MouDinFpSelFix   = 0x1U, /*!< fix */
} fsp_mou_din_fp_sel_t;

typedef enum _fsp_mou_op_mode
{
    kFSP_MouOpModeInv     = 0x0U,
    kFSP_MouOpModeMult    = 0x1U,
    kFSP_MouOpModeTrans   = 0x2U,
    kFSP_MouOpModeScale   = 0x3U,
    kFSP_MouOpModeDotMult = 0x4U,
} fsp_mou_op_mode_t;

typedef enum _fsp_te_dout_fp_sel
{
    kFSP_TeDoutFpSelFix   = 0x0U, /*!< fix */
    kFSP_TeDoutFpSelFloat = 0x1U, /*!< float */
} fsp_te_dout_fp_sel_t;

typedef enum _fsp_te_din_fp_sel
{
    kFSP_TeDinFpSelFix   = 0x0U, /*!< fix */
    kFSP_TeDinFpSelFloat = 0x1U, /*!< float */
} fsp_te_din_fp_sel_t;

typedef enum _fsp_te_pts
{
    kFSP_TePts64Points  = 0x0U, /*!< 64 points */
    kFSP_TePts128Points = 0x1U, /*!< 128 points */
    kFSP_TePts256Points = 0x2U, /*!< 256 points */
    kFSP_TePtsReserved  = 0x3U, /*!< reserved */
} fsp_te_pts_t;

typedef enum _fsp_te_io_mode
{
    kFSP_TeIoModeRealInputComplexOutput    = 0x0U, /*!< real input, complex output */
    kFSP_TeIoModeComplexInputComplexOutput = 0x1U, /*!< complex input, complex output */
    kFSP_TeIoModeRealInputRealOutput       = 0x2U, /*!< real input, real output */
    kFSP_TeIoModeComplexInputRealOutput    = 0x3U, /*!< complex input, real output */
} fsp_te_io_mode_t;

typedef enum _fsp_te_mode
{
    kFSP_TeModeFft  = 0x0U, /*!< FFT */
    kFSP_TeModeIfft = 0x1U, /*!< IFFT */
    kFSP_TeModeDct  = 0x2U, /*!< DCT */
    kFSP_TeModeIdct = 0x3U, /*!< IDCT */
} fsp_te_mode_t;

typedef enum _fsp_se_dout_fp_sel
{
    kFSP_SeDoutFpSelFloat = 0x00U, /*!< float */
    kFSP_SeDoutFpSelFix   = 0x01U, /*!< fix */
} fsp_se_dout_fp_sel_t;

typedef enum _fsp_se_din_fp_sel
{
    kFSP_SeDinFpSelFloat = 0x00U, /*!< float */
    kFSP_SeDinFpSelFix   = 0x01U, /*!< fix */
} fsp_se_din_fp_sel_t;

typedef enum _fsp_cor_dout_fp_sel
{
    kFSP_CorDoutFpSelFloat = 0x00U, /*!< float */
    kFSP_CorDoutFpSelFix   = 0x01U, /*!< fix */
} fsp_cor_dout_fp_sel_t;

typedef enum _fsp_cor_din_fp_sel
{
    kFSP_CorDinFpSelFloat = 0x00U, /*!< float */
    kFSP_CorDinFpSelFix   = 0x01U, /*!< fix */
} fsp_cor_din_fp_sel_t;

/**
 * @brief Enum type for the FSP module FIR output data type (float or q31).
 */
typedef enum _fir_dout_fp_sel
{
    kFSP_FirDoutFpSelFloat = 0x0U, /*!< float */
    kFSP_FirDoutFpSelFix   = 0x1U, /*!< fix */
} fir_dout_fp_sel_t;

/**
 * @brief Enum type for the FSP module FIR input data type (float or q31).
 */
typedef enum _fir_din_fp_sel
{
    kFSP_FirDinFpSelFloat = 0x0U, /*!< float */
    kFSP_FirDinFpSelFix   = 0x1U, /*!< fix */
} fir_din_fp_sel_t;

typedef enum _fsp_module_offset
{
    kFSP_FirCfgCh0Offset = 0x0A0U,
    kFSP_FirDat0FxOffset = 0x0D0U,
    kFSP_FirDat0FlOffset = 0x100U,

} fsp_module_offset_t;

typedef enum _fsp_mode
{
    kFSP_NullMode      = 0x0U,
    kFSP_InterruptMode = 0x1U,
    kFSP_PollingMode   = 0x2U
} fsp_mode;

/**
 * @brief Instance structure for the matrix.
 */
typedef struct _fsp_matrix_instance
{
    uint8_t num_rows; /**< number of rows of the matrix.     */
    uint8_t num_cols; /**< number of columns of the matrix.  */
    void *p_data;     /**< points to the data of the matrix. */

} fsp_matrix_instance_t;

/**
 * @brief Instance structure for the matrix operation.
 */

typedef struct _fsp_mat_op_instance
{
    uint32_t mat_op_cfg; /**< configuration of matrix operation. */
    union
    {
        uint32_t scale_a_u32; /**< scale coefficient a for the matrix A(a*A). */
        float32_t scale_a_f32;
    };
    union
    {
        uint32_t scale_b_u32; /**< scale coefficient b for the matrix B(b*B). */
        float32_t scale_b_f32;
    };
} fsp_mat_op_instance_t;

typedef struct _fsp_te_instance
{
    fsp_te_pts_t te_point; /**< points of the transform(64/128/256). */
    int8_t te_scale; /**< The value of te_scale will add to 2 exponent bits of input float-pointing to make sure that
                        the input data range become in [-1,1). */
} fsp_te_instance_t;

/**
 * @brief Instance structure for the FIR filter.
 */

typedef struct _fsp_fir_instance
{
    uint8_t ch_idx;   /**< channel index. */
    uint32_t fir_cfg; /**< FIR configuration. */
} fsp_fir_instance_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* _cplusplus */

/*!
 * @brief FSP configuration
 *
 * @param base FSP peripheral base address.s
 */
void FSP_Init(FSP_Type *base);

/*!
 * @brief Disables the FSP and gates the FSP clock.
 *
 * @param base pointer to FLEXIO_UART_Type structure
 */
void FSP_Deinit(FSP_Type *base);

/*!
 * @brief Enables the FSP interrupt.
 *
 * This function enables the FSP interrupt.
 *
 * @param base FSP peripheral base address.
 * @param mask interrupt source.
 */
static inline void FSP_EnableInterrupts(FSP_Type *base, uint32_t mask)
{
    FSP->INTEN |= mask;
}
/*!
 * @brief Disables the FSP interrupt.
 *
 * This function disables the FSP interrupt.
 *
 * @param base FSP peripheral base address.
 * @param mask interrupt source.
 */
static inline void FSP_DisableInterrupts(FSP_Type *base, uint32_t mask)
{
    FSP->INTEN &= ~mask;
}

/*!
 * @brief Clears status flags with the provided mask.
 *
 * @param base FSP peripheral base address.
 * @param mask The status flags to be cleared
 * @retval None
 */
static inline void FSP_ClearStatusFlags(FSP_Type *base, uint32_t mask)
{
    base->INT = mask;
}

/*!
 * @brief Get FSP status flags.
 *
 * @param base FSP peripheral base address.
 * @return FSP status flags.
 */

static inline uint32_t FSP_GetStatusFlags(FSP_Type *base)
{
    return base->INT;
}

/*!
 * @brief Get FSP busy status flags.
 *
 * @param base FSP peripheral base address.
 * @return FSP busy status flags.
 */

static inline uint32_t FSP_GetBusyStatusFlags(FSP_Type *base)
{
    return base->STATUS;
}

/*! @brief Cordic */

/*!
 * @brief  Fast approximation to the trigonometric sine and cosine function for floating-point data.
 *
 * @param  base    FSP peripheral base address
 * @param x Input value in radians/pi.
 * @return  sin(x) in floating-point format.
 */
static inline float32_t FSP_SinF32(FSP_Type *base, float32_t x)
{
    float32_t result[2];

    base->SIN_COS_ILOL =
        FSP_SIN_COS_ILOL_SIN_COS_ILOL_SRC(toWordAddr(&x)) | FSP_SIN_COS_ILOL_SIN_COS_ILOL_DST(toWordAddr(result));

    return result[1];
}

/**
 * @brief Fast approximation to the trigonometric sine function for Q31 data.
 *
 * @param  base    FSP peripheral base address
 * @param x Input value in radians/pi.
 * @return  sin(x)in Q31 format.
 */
static inline float32_t FSP_SinQ31(FSP_Type *base, q31_t x)
{
    float32_t result[2];

    base->SIN_COS_IXOX =
        FSP_SIN_COS_IXOX_SIN_COS_IXOX_SRC(toWordAddr(&x)) | FSP_SIN_COS_IXOX_SIN_COS_IXOX_DST(toWordAddr(result));

    return result[1];
}

/*!
 * @brief  Fast approximation to the trigonometric sine and cosine function for floating-point data.
 *
 * @param  base    FSP peripheral base address
 * @param   x Input value in radians/pi.
 * @return  cos(x) in floating-point format.
 */
static inline float32_t FSP_CosF32(FSP_Type *base, float32_t x)
{
    float32_t result[2];

    base->SIN_COS_ILOL =
        FSP_SIN_COS_ILOL_SIN_COS_ILOL_SRC(toWordAddr(&x)) | FSP_SIN_COS_ILOL_SIN_COS_ILOL_DST(toWordAddr(result));

    return result[0];
}

/**
 * @brief Fast approximation to the trigonometric sine function for Q31 data.
 *
 * @param  base    FSP peripheral base address
 * @param   x Input value in radians/pi.
 * @return  cos(x) in Q31 format.
 *
 * The Q31 input value is in the range [0 +0.9999] and is mapped to a radian
 * value in the range [0 2*pi).
 */
static inline q31_t FSP_CosQ31(FSP_Type *base, q31_t x)
{
    q31_t result[2];

    base->SIN_COS_IXOX =
        FSP_SIN_COS_IXOX_SIN_COS_IXOX_SRC(toWordAddr(&x)) | FSP_SIN_COS_IXOX_SIN_COS_IXOX_DST(toWordAddr(result));

    return result[0];
}

/**
 * @brief Floating-point log function.
 *
 * @param  base    FSP peripheral base address
 * @param   x    input value, the range of the input value is [0 +1) or 0x00000000 to 0x7FFFFFFF.
 * @return   return in floating-point format, for negative inputs, the function returns 0.
 */
static inline float32_t FSP_LnF32(FSP_Type *base, float32_t x)
{
    float32_t result[2];

    base->LN_SQRT_ILOL =
        FSP_LN_SQRT_ILOL_LN_SQRT_ILOL_SRC(toWordAddr(&x)) | FSP_LN_SQRT_ILOL_LN_SQRT_ILOL_DST(toWordAddr(result));
    return result[1];
}

/**
 * @brief Q31 log function.
 *
 * @param  base    FSP peripheral base address
 * @param   x    input value, the range of the input value is [0 +1) or 0x00000000 to 0x7FFFFFFF.
 * @return   return in Q31 format, for negative inputs, the function returns 0.
 */
static inline q31_t FSP_LnQ31(FSP_Type *base, q31_t x)
{
    q31_t result[2];

    base->LN_SQRT_IXOX =
        FSP_LN_SQRT_IXOX_LN_SQRT_IXOX_SRC(toWordAddr(&x)) | FSP_LN_SQRT_IXOX_LN_SQRT_IXOX_DST(toWordAddr(result));

    return result[1];
}

/**
 * @brief Floating-point root function.
 *
 * @param  base    FSP peripheral base address
 * @param   x    input value, the range of the input value is [0 +1) or 0x00000000 to 0x7FFFFFFF.
 * @return   return square root of input value in floating-point format, for negative input, the function returns 0.
 */
static inline float32_t FSP_SqrtF32(FSP_Type *base, float32_t x)
{
    float32_t result[2];

    base->LN_SQRT_ILOL =
        FSP_LN_SQRT_ILOL_LN_SQRT_ILOL_SRC(toWordAddr(&x)) | FSP_LN_SQRT_ILOL_LN_SQRT_ILOL_DST(toWordAddr(result));
    return result[0];
}

/**
 * @brief Q31 square root function.
 *
 * @param  base    FSP peripheral base address
 * @param   x    input value, the range of the input value is [0 +1) or 0x00000000 to 0x7FFFFFFF.
 * @return  return square root of input value in Q31 format, for negative input, the function returns 0.
 */
static inline q31_t FSP_SqrtQ31(FSP_Type *base, q31_t x)
{
    q31_t result[2];

    base->LN_SQRT_IXOX =
        FSP_LN_SQRT_IXOX_LN_SQRT_IXOX_SRC(toWordAddr(&x)) | FSP_LN_SQRT_IXOX_LN_SQRT_IXOX_DST(toWordAddr(result));

    return result[0];
}

/*! @brief Matrix Operation Unit & Transform Engine */

/**
 * @details  Processing function for the Matrix operation unit.
 * @brief    Matrix operation start.
 *
 * @param   base FSP peripheral base address
 * @param   ins points to the matrix operation structure.
 * @param   *p_src_mat_a points to the input matrix A.
 * @param   *p_src_mat_b points to the input matrix B.
 * @param   *p_dst points to output matrix structure.
 * @return none.
 */
static inline void FSP_MatOperateStart(FSP_Type *base,
                                       const fsp_mat_op_instance_t *ins,
                                       const void *p_dat_mat_a,
                                       const void *p_dat_mat_b,
                                       const void *p_dat_dst)
{
    base->MA_SRC_BASE = FSP_MA_SRC_BASE_MA_SRC_BASE(p_dat_mat_a);
    base->MB_SRC_BASE = FSP_MB_SRC_BASE_MB_SRC_BASE(p_dat_mat_b);
    base->MOU_SCALEA  = FSP_MOU_SCALEA_MOU_SCALEA(ins->scale_a_u32);
    base->MOU_SCALEB  = FSP_MOU_SCALEB_MOU_SCALEB(ins->scale_b_u32);
    base->MO_DST_BASE = FSP_MO_DST_BASE_MO_DST_BASE(p_dat_dst);
    base->MOU_CTRL    = ins->mat_op_cfg;
}

/**
 * @brief  Matrix initialization.
 *
 * @param   *S points to an instance of the matrix structure.
 * @param   n_rows number of rows in the matrix.
 * @param   n_columns number of columns in the matrix.
 * @param   *p_data points to the matrix data array.
 * @return  none
 */
void FSP_MatInit(fsp_matrix_instance_t *S, uint16_t n_rows, uint16_t n_columns, void *p_data);

/**
 * @brief Floating-point matrix inverse.
 *
 * @param   base FSP peripheral base address
 * @param   *p_src points to input matrix structure
 * @param   *p_dst points to output matrix structure
 * @return  none
 */
void FSP_MatInverseF32(FSP_Type *base, const fsp_matrix_instance_t *p_src, const fsp_matrix_instance_t *p_dst);

/**
 * @brief q31 matrix inverse.
 *
 * @param   base  FSP peripheral base address
 * @param   *p_src points to input matrix structure
 * @param   *p_dst points to output matrix structure
 * @return  none
 */
void FSP_MatInverseQ31(FSP_Type *base, const fsp_matrix_instance_t *p_src, const fsp_matrix_instance_t *p_dst);

/**
 * @brief Floating-point matrix multiplication.
 *
 * @param   base    FSP peripheral base address
 * @param   *p_src_a points to the first input matrix structure
 * @param   *p_src_b points to the second input matrix structure
 * @param   *p_dst points to output matrix structure
 * @return  none
 */
void FSP_MatMultF32(FSP_Type *base,
                    const fsp_matrix_instance_t *p_src_a,
                    const fsp_matrix_instance_t *p_src_b,
                    const fsp_matrix_instance_t *p_dst);

/**
 * @brief q31 matrix multiplication
 *
 * @param   base    FSP peripheral base address
 * @param   *p_src_a    points to the first input matrix structure
 * @param   *p_src_b    points to the second input matrix structure
 * @param   *p_dst  points to output matrix structure
 * @return  none
 */
void FSP_MatMultQ31(FSP_Type *base,
                    const fsp_matrix_instance_t *p_src_a,
                    const fsp_matrix_instance_t *p_src_b,
                    const fsp_matrix_instance_t *p_dst);

/**
 * @brief Floating-point matrix dot multiplication.
 *
 * @param   base FSP peripheral base address
 * @param   *p_src_a points to the first input matrix structure
 * @param   *p_src_b points to the second input matrix structure
 * @param   *p_dst points to output matrix structure
 * @return  none
 */
void FSP_MatDotMultF32(FSP_Type *base,
                       const fsp_matrix_instance_t *p_src_a,
                       const fsp_matrix_instance_t *p_src_b,
                       const fsp_matrix_instance_t *p_dst);

/**
 * @brief q31 matrix dot multiplication
 *
 * @param   base FSP peripheral base address
 * @param   *p_src_a points to the first input matrix structure
 * @param   *p_src_b points to the second input matrix structure
 * @param   *p_dst points to output matrix structure
 * @return  none
 *
 */
void FSP_MatDotMultQ31(FSP_Type *base,
                       const fsp_matrix_instance_t *p_src_a,
                       const fsp_matrix_instance_t *p_src_b,
                       const fsp_matrix_instance_t *p_dst);

/**
 * @brief Floating-point matrix transpose.
 *
 * @param  base FSP peripheral base address
 * @param  *p_src points to the input matrix
 * @param  *p_dst points to the output matrix
 * @return    none
 */
void FSP_MatTransF32(FSP_Type *base, const fsp_matrix_instance_t *p_src, const fsp_matrix_instance_t *p_dst);

/*
 * @brief q31 matrix transpose.
 *
 * @param  base FSP peripheral base address
 * @param  *p_src points to the input matrix
 * @param  *p_dst points to the output matrix
 * @return    The function returns either  <code>ARM_MATH_SIZE_MISMATCH</code>
 * or <code>ARM_MATH_SUCCESS</code> based on the outcome of size checking.
 */
void FSP_MatTransQ31(FSP_Type *base, const fsp_matrix_instance_t *p_src, const fsp_matrix_instance_t *p_dst);

/**
 * @brief Floating-point matrix scaling(a*A + b*B).
 *
 * @param   base FSP peripheral base address
 * @param   *p_src_a points to the first input matrix structure
 * @param   scale_a scale factor of matrix_a to be applied
 * @param   *p_src_b points to the second input matrix structure
 * @param   scale_b scale factor of matrix_b to be applied
 * @param   *p_dst points to output matrix structure
 * @return  None
 */
void FSP_MatScaleF32(FSP_Type *base,
                     const fsp_matrix_instance_t *p_src_a,
                     float32_t scale_a,
                     const fsp_matrix_instance_t *p_src_b,
                     float32_t scale_b,
                     const fsp_matrix_instance_t *p_dst);

/**
 * @brief q31 matrix scaling.
 *
 * @param   base FSP peripheral base address
 * @param   *p_src_a points to the first input matrix structure
 * @param   scale_a scale factor of matrix_a to be applied
 * @param   *p_src_b points to the second input matrix structure
 * @param   scale_b scale factor of matrix_b to be applied
 * @param   *p_dst points to output matrix structure
 * @return            none
 */
void FSP_MatScaleQ31(FSP_Type *base,
                     const fsp_matrix_instance_t *p_src_a,
                     float32_t scale_a,
                     const fsp_matrix_instance_t *p_src_b,
                     float32_t scale_b,
                     const fsp_matrix_instance_t *p_dst);

/**
 * @brief Floating-point matrix addition.
 *
 * @param   base FSP peripheral base address
 * @param   *p_src_a points to the first input matrix structure
 * @param   *p_src_b points to the second input matrix structure
 * @param   *p_dst points to output matrix structure
 * @return  none
 */
void FSP_MatAddF32(FSP_Type *base,
                   const fsp_matrix_instance_t *p_src_a,
                   const fsp_matrix_instance_t *p_src_b,
                   const fsp_matrix_instance_t *p_dst);

/**
 * @brief q31 matrix addition.
 *
 * @param   base FSP peripheral base address
 * @param   *p_src_a points to the first input matrix structure
 * @param   *p_src_b points to the second input matrix structure
 * @param   *p_dst points to output matrix structure
 * @return            none
 * The function uses saturating arithmetic.
 * Results outside of the allowable q31 range [0x80000000 0x7FFFFFFF] will be saturated.
 */
void FSP_MatAddQ31(FSP_Type *base,
                   const fsp_matrix_instance_t *p_src_a,
                   const fsp_matrix_instance_t *p_src_b,
                   const fsp_matrix_instance_t *p_dst);

/**
 * @brief Floating-point matrix subtraction
 *
 * @param   base FSP peripheral base address
 * @param   *p_src_a points to the first input matrix structure
 * @param   *p_src_b points to the second input matrix structure
 * @param   *p_dst points to output matrix structure
 * @return            none
 */
void FSP_MatSubF32(FSP_Type *base,
                   const fsp_matrix_instance_t *p_src_a,
                   const fsp_matrix_instance_t *p_src_b,
                   const fsp_matrix_instance_t *p_dst);

/**
 * @brief q31 matrix subtraction.
 *
 * @param   base FSP peripheral base address
 * @param   *p_src_a points to the first input matrix structure
 * @param   *p_src_b points to the second input matrix structure
 * @param   *p_dst points to output matrix structure
 * @return  none
 * The function uses saturating arithmetic.
 * Results outside of the allowable q31 range [0x80000000 0x7FFFFFFF] will be saturated.
 */
void FSP_MatSubQ31(FSP_Type *base,
                   const fsp_matrix_instance_t *p_src_a,
                   const fsp_matrix_instance_t *p_src_b,
                   const fsp_matrix_instance_t *p_dst);

/**
 * @details  Processing function for the transfer engine.
 * @brief    Transfer engine start
 *
 * @param   base FSP peripheral base address
 * @param   te_cfg config value of the transfer engine.
 * @param   *p_src points to the input data buffer.
 * @param   *p_dst points to the output data buffer.
 * @return none.
 */
static inline void FSP_TeStart(FSP_Type *base, uint32_t te_cfg, const void *p_src, const void *p_dst)
{
    base->TE_SRC_BASE = FSP_TE_SRC_BASE_TE_SRC_BASE(p_src);
    base->TE_DST_BASE = FSP_TE_DST_BASE_TE_DST_BASE(p_dst);
    base->TE_CTRL     = te_cfg;
}
/**
 * @details  Pre-processing function for IDCT.
 * @brief    Only for IDCT: Convert the input data

 * @param   base FSP peripheral base address
 * @param   *p_data points to input and output data.
 * @return none.
 */
void FSP_TeIDCTPreProcess(FSP_Type *base, float32_t *p_data);
/**
 * @details  Post-processing function for the transfer engine.
 * @brief    For FFT/IFFT/CFFT: Make the output of FSP match the ARM's
 *           For DCT/IDCT: Convert the output from DCT-II to DCT-IV
 * @param   base FSP peripheral base address
 * @param   *S points to an instance of the fsp_te_instance_t structure.
 * @param   io_mode input and output mode defined by enum @fsp_te_io_mode_t
 * @param   te_mode transfer engine mode defined by enum @fsp_te_mode_t
 * @param   *p_data points to input and output data.
 * @return none.
 */
void FSP_TePostProcess(
    FSP_Type *base, const fsp_te_instance_t *S, fsp_te_io_mode_t io_mode, fsp_te_mode_t te_mode, float32_t *p_data);
/**
 * @brief Processing function for the floating-point real FFT.
 *
 * @param   base FSP peripheral base address
 * @param   *S points to an instance of the fsp_te_instance_t structure.
 * @param   *p_src points to the input buffer.
 * @param   *p_dst points to the output buffer.
 * @return none.
 */
void FSP_RfftF32(FSP_Type *base, const fsp_te_instance_t *S, float32_t *p_src, float32_t *p_dst);

/**
 * @brief Processing function for the floating-point real IFFT.
 *
 * @param   base FSP peripheral base address
 * @param   *S points to an instance of the fsp_te_instance_t structure.
 * @param   *p_src points to the input buffer.
 * @param   *p_dst points to the output buffer.
 * @return none.
 */
void FSP_RifftF32(FSP_Type *base, const fsp_te_instance_t *S, float32_t *p_src, float32_t *p_dst);

/**
 * @brief Processing function for the q31 real FFT.
 *
 * @param   base FSP peripheral base address
 * @param   *S points to an instance of the fsp_te_instance_t structure.
 * @param   *p_src points to the input buffer.
 * @param   *p_dst points to the output buffer.
 * @return none.
 */
void FSP_RfftQ31(FSP_Type *base, const fsp_te_instance_t *S, q31_t *p_src, q31_t *p_dst);

/**
 * @brief Processing function for the q31 real IFFT.
 *
 * @param   base FSP peripheral base address
 * @param   *S points to an instance of the fsp_te_instance_t structure.
 * @param   *p_src points to the input buffer.
 * @param   *p_dst points to the output buffer.
 * @return none.
 */
void FSP_RifftQ31(FSP_Type *base, const fsp_te_instance_t *S, q31_t *p_src, q31_t *p_dst);

/**
 * @brief Processing function for the floating-point complex FFT/IFFT.
 *
 * @param  base FSP peripheral base address
 * @param  *S points to an instance of the fsp_te_instance_t structure.
 * @param  *p_src points to the input buffer.
 * @param  *p_dst points to the output buffer.
 * @param   ifft_flag flag that selects forward (ifft_flag=0) or inverse (ifft_flag=1) transform.
 * @return none.
 */
void FSP_CfftF32(FSP_Type *base, const fsp_te_instance_t *S, float32_t *p_src, float32_t *p_dst, uint8_t ifft_flag);

/**
 * @brief Processing function for the q31 complex FFT/IFFT.
 *
 * @param   base FSP peripheral base address
 * @param   *S points to an instance of the fsp_te_instance_t structure.
 * @param   *p_src points to the input buffer.
 * @param   *p_dst points to the output buffer.
 * @param   ifft_flag flag that selects forward (ifft_flag=0) or inverse (ifft_flag=1) transform.
 * @return none.
 */
void FSP_CfftQ31(FSP_Type *base, const fsp_te_instance_t *S, q31_t *p_src, q31_t *p_dst, uint8_t ifft_flag);

/**
 * @brief Processing function for the floating-point DCT/IDCT.
 *
 * @param   base FSP peripheral base address
 * @param   *S points to an instance of the fsp_te_instance_t structure.
 * @param   *p_src points to the input buffer.
 * @param   *p_dst points to the output buffer.
 * @param   idct_flag flag that selects forward (idct_flag=0) or inverse (idct_flag=1) transform.
 * @return none.
 */
void FSP_DctF32(FSP_Type *base, const fsp_te_instance_t *S, float32_t *p_src, float32_t *p_dst, uint8_t idct_flag);

/**
 * @brief Processing function for the q31 DCT/IDCT.
 *
 * @param  base FSP peripheral base address
 * @param  *S  points to an instance of the fsp_te_instance_t structure.
 * @param  *p_src  points to the input buffer.
 * @param  *p_dst  points to the output buffer.
 * @param  idct_flag   flag that selects forward (idct_flag=0) or inverse (idct_flag=1) transform.
 * @return none.
 */
void FSP_DctQ31(FSP_Type *base, const fsp_te_instance_t *S, q31_t *p_src, q31_t *p_dst, uint8_t idct_flag);

/**
 * @details   Processing function for the statistic engine.
 *
 * @brief     Statistic engine start
 * @param   base FSP peripheral base address
 * @param   *S points to an instance of the statistic engine structure.
 * @param   *p_src points to the input data buffer.
 * @return none.
 */
static inline void FSP_SeStart(FSP_Type *base, uint32_t se_cfg, const void *p_src)
{
    base->SE_SRC_BASE = FSP_SE_SRC_BASE_SE_SRC_BASE(p_src);
    base->SE_CTRL     = se_cfg;
}
/**
 * @brief Get Maximum and Minimum values of a floating-point vector.
 *
 * @param  *p_src points to the input vector
 * @param  block_size length of the input vector
 * @param  *p_max  maximum value returned here
 * @param  *p_min  Minimum value returned here
 * @return none.
 */
void FSP_MaxMinF32(FSP_Type *base, float32_t *p_src, uint32_t block_size, float32_t *p_max, float32_t *p_min);

/**
 * @brief  Calculate Maximum and Minimum values of a floating-point vector.
 * @brief  Interrupt-mode interface
 *
 * @param  *p_src points to the input vector
 * @param  block_size length of the input vector
 * @return none.
 */
static inline void FSP_MaxMinIntF32(FSP_Type *base, float32_t *p_src, uint32_t block_size)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFloat, kFSP_SeDinFpSelFloat, 0, 0, 1, 1, 0, 0), p_src);
}

/**
 * @brief Get the Maximum and Minimum values of a floating-point vector.
 * @brief  Interrupt-mode interface
 *
 * @param  *p_src points to the input vector
 * @param  *p_max  maximum value returned here
 * @param  *p_min  Minimum value returned here
 * @return none.
 */
void FSP_GetMaxMinIntResultF32(FSP_Type *base, float32_t *p_src, float32_t *p_max, float32_t *p_min);

/**
 * @brief Get Maximum and Minimum values of a q31 vector.
 *
 * @param  *p_src points to the input vector
 * @param  block_size length of the input vector
 * @param  *p_max  maximum value returned here
 * @param  *p_min  Minimum value returned here
 * @return none.
 */
void FSP_MaxMinQ31(FSP_Type *base, q31_t *p_src, uint32_t block_size, q31_t *p_max, q31_t *p_min);

/**
 * @brief  Calculate Maximum and Minimum values of a q31 vector.
 * @brief  Interrupt-mode interface
 *
 * @param  *p_src points to the input vector
 * @param  block_size length of the input vector
 * @return none.
 */
static inline void FSP_MaxMinIntQ31(FSP_Type *base, q31_t *p_src, uint32_t block_size)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFix, kFSP_SeDinFpSelFix, 0, 0, 1, 1, 0, 0), p_src);
}
/**
 * @brief Get the Maximum and Minimum values of a q31 vector vector.
 * @brief  Interrupt-mode interface
 *
 * @param  *p_src points to the input vector
 * @param  *p_max  maximum value returned here
 * @param  *p_min  Minimum value returned here
 * @return none.
 */
void FSP_GetMaxMinIntResultQ31(FSP_Type *base, q31_t *p_src, q31_t *p_max, q31_t *p_min);

/**
 * @brief Maximum value of a floating-point vector.
 *
 * @param  base FSP peripheral base address
 * @param  *p_src points to the input vector
 * @param  block_size length of the input vector
 * @param  *p_result maximum value returned here
 * @param  *p_index index of maximum value returned here
 * @return none.
 */
void FSP_MaxF32(FSP_Type *base, float32_t *p_src, uint32_t block_size, float32_t *p_result, uint32_t *p_index);

/**
 * @brief  Calculate Maximum value of a floating-point vector.
 * @brief  Interrupt-mode interface
 *
 * @param  *p_src points to the input vector
 * @param  block_size length of the input vector
 * @return none.
 */
static inline void FSP_MaxIntF32(FSP_Type *base, float32_t *p_src, uint32_t block_size)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFloat, kFSP_SeDinFpSelFloat, 0, 0, 1, 0, 0, 0), p_src);
}

/**
 * @brief Get the Maximum value of a floating-point vector.
 * @brief  Interrupt-mode interface
 *
 * @param  *p_src points to the input vector
 * @param  *p_result maximum value returned here
 * @param  *p_index index of maximum value returned here
 * @return none.
 */
void FSP_GetMaxIntResultF32(FSP_Type *base, float32_t *p_src, float32_t *p_result, uint32_t *p_index);
/**
 * @brief Maximum value of a q31 vector.
 *
 * @param   base FSP peripheral base address
 * @param   *p_src points to the input vector
 * @param   block_size length of the input vector
 * @param   *p_result maximum value returned here
 * @param   *p_index index of maximum value returned here
 * @return none.
 */
void FSP_MaxQ31(FSP_Type *base, q31_t *p_src, uint32_t block_size, q31_t *p_result, uint32_t *p_index);

/**
 * @brief  Calculate Maximum value of a q31 vector.
 * @brief  Interrupt-mode interface
 *
 * @param  *p_src points to the input vector
 * @param  block_size length of the input vector
 * @return none.
 */
static inline void FSP_MaxIntQ31(FSP_Type *base, q31_t *p_src, uint32_t block_size)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFix, kFSP_SeDinFpSelFix, 0, 0, 1, 0, 0, 0), p_src);
}

/**
 * @brief Get the Maximum value of a q31 vector.
 * @brief  Interrupt-mode interface
 *
 * @param  *p_src points to the input vector
 * @param  *p_result maximum value returned here
 * @param  *p_index index of maximum value returned here
 * @return none.
 */
void FSP_GetMaxIntResultQ31(FSP_Type *base, q31_t *p_src, q31_t *p_result, uint32_t *p_index);

/**
 * @brief Minimum value of a floating-point vector.
 *
 * @param   base FSP peripheral base address
 * @param   *p_src points to the input vector
 * @param   block_size length of the input vector
 * @param   *p_result minimum value returned here
 * @param   *p_index index of minimum value returned here
 * @return none.
 */
void FSP_MinF32(FSP_Type *base, float32_t *p_src, uint32_t block_size, float32_t *p_result, uint32_t *p_index);

/**
 * @brief  Calculate Minimum value of a floating-point vector.
 * @brief  Interrupt-mode interface
 *
 * @param  *p_src points to the input vector
 * @param  block_size length of the input vector
 * @return none.
 */
static inline void FSP_MinIntF32(FSP_Type *base, float32_t *p_src, uint32_t block_size)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFloat, kFSP_SeDinFpSelFloat, 0, 0, 0, 1, 0, 0), p_src);
}

/**
 * @brief Get the Minimum value of a floating-point vector.
 * @brief  Interrupt-mode interface
 *
 * @param  *p_src points to the input vector
 * @param  *p_result minimum value returned here
 * @param  *p_index index of minimum value returned here
 * @return none.
 */
void FSP_GetMinIntResultF32(FSP_Type *base, float32_t *p_src, float32_t *p_result, uint32_t *p_index);

/**
 * @brief Minimum value of a q31 vector.
 *
 * @param   base FSP peripheral base address
 * @param   *p_src points to the input vector
 * @param   block_size length of the input vector
 * @param   *p_result minimum value returned here
 * @param   *p_index index of minimum value returned here
 * @return none.
 */
void FSP_MinQ31(FSP_Type *base, q31_t *p_src, uint32_t block_size, q31_t *p_result, uint32_t *p_index);

/**
 * @brief  Calculate Minimum value of a q31 vector.
 * @brief  Interrupt-mode interface
 *
 * @param  *p_src points to the input vector
 * @param  block_size length of the input vector
 * @return none.
 */
static inline void FSP_MinIntQ31(FSP_Type *base, q31_t *p_src, uint32_t block_size)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFix, kFSP_SeDinFpSelFix, 0, 0, 0, 1, 0, 0), p_src);
}

/**
 * @brief Get the Minimum value of a q31 vector.
 * @brief  Interrupt-mode interface
 *
 * @param  *p_src points to the input vector
 * @param  *p_result minimum value returned here
 * @param  *p_index index of minimum value returned here
 * @return none.
 */
void FSP_GetMinIntResultQ31(FSP_Type *base, q31_t *p_src, q31_t *p_result, uint32_t *p_index);

/**
 * @defgroup sum Sum
 * @{
 * Calculates the sum of the input vector. Sum is defined as the sum of the elements in the vector.
 * The underlying algorithm is used:
 *
 * <pre>
 *    Result = (p_src[0] + p_src[1] + p_src[2] + ... + p_src[block_size-1]);
 * </pre>
 *
 * There are separate functions for floating-point, q31 data types.
 */

/**
 * @brief Sum value of a floating-point vector.
 *
 * @param   base FSP peripheral base address
 * @param   *p_src points to the input vector
 * @param   block_size length of the input vector
 * @param   *p_result Sum value returned here
 * @return none.
 */
void FSP_SumF32(FSP_Type *base, float32_t *p_src, uint32_t block_size, float32_t *p_result);

/**
 * @brief  Calculate Sum value of a floating-point vector.
 * @brief  Interrupt-mode interface
 *
 * @param   base FSP peripheral base address
 * @param   *p_src points to the input vector
 * @param   block_size length of the input vector
 * @return none.
 */
static inline void FSP_SumIntF32(FSP_Type *base, float32_t *p_src, uint32_t block_size)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFloat, kFSP_SeDinFpSelFloat, 0, 1, 0, 0, 0, 0), p_src);
}

/**
 * @brief Get the Sum value of a floating-point vector.
 * @brief  Interrupt-mode interface
 *
 * @param   base FSP peripheral base address
 * @param   *p_result Sum value returned here
 * @return none.
 */
static inline void FSP_GetSumIntResultF32(FSP_Type *base, float32_t *p_result)
{
    *(uint32_t *)p_result = base->SE_SUM;
}
/**
 * @brief Sum value of a q31 vector.
 *
 * @param   base FSP peripheral base address
 * @param   *p_src points to the input vector
 * @param   block_size length of the input vector
 * @param   *p_result Sum value returned here
 * @return none.
 *
 */
void FSP_SumQ31(FSP_Type *base, q31_t *p_src, uint32_t block_size, q31_t *p_result);

/**
 * @brief  Calculate Sum value of a q31 vector.
 * @brief  Interrupt-mode interface
 *
 * @param   base FSP peripheral base address
 * @param   *p_src points to the input vector
 * @param   block_size length of the input vector
 * @return none.
 */
static inline void FSP_SumIntQ31(FSP_Type *base, float32_t *p_src, uint32_t block_size)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFix, kFSP_SeDinFpSelFix, 0, 1, 0, 0, 0, 0), p_src);
}

/**
 * @brief Get the Sum value of a q31 vector.
 * @brief  Interrupt-mode interface
 *
 * @param   base FSP peripheral base address
 * @param   *p_result Sum value returned here
 * @return none.
 */
static inline void FSP_GetSumIntResultQ31(FSP_Type *base, float32_t *p_result)
{
    *p_result = base->SE_SUM;
}
/*! @}*/
/**
 * @defgroup power Power
 * @{
 * Calculates the sum of the squares of the elements in the input vector.
 * The underlying algorithm is used:
 *
 * <pre>
 *    Result = p_src[0] * p_src[0] + p_src[1] * p_src[1] + p_src[2] * p_src[2] + ... + p_src[block_size-1] *
 * p_src[block_size-1];
 * </pre>
 *
 * There are separate functions for floating point, q31 data types.
 */

/**
 * @brief Sum of the squares of the elements of a floating-point vector.
 *
 * @param   base FSP peripheral base address
 * @param   *p_src points to the input vector
 * @param   block_size length of the input vector
 * @param   *p_result sum of the squares value returned here
 * @return none.
 *
 */
void FSP_PowerF32(FSP_Type *base, float32_t *p_src, uint32_t block_size, float32_t *p_result);

/**
 * @brief  Calculate Sum of the squares of the elements of a floating-point vector.
 * @brief  Interrupt-mode interface
 *
 * @param   base FSP peripheral base address
 * @param   *p_src points to the input vector
 * @param   block_size length of the input vector
 * @return none.
 */
static inline void FSP_PowerIntF32(FSP_Type *base, float32_t *p_src, uint32_t block_size)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFloat, kFSP_SeDinFpSelFloat, 1, 0, 0, 0, 0, 0), p_src);
}

/**
 * @brief Get the Sum of the squares of the elements value of a floating-point vector.
 * @brief  Interrupt-mode interface
 *
 * @param   base FSP peripheral base address
 * @param   *p_result sum of the squares value returned here
 * @return none.
 */
static inline void FSP_GetPowerIntResultF32(FSP_Type *base, float32_t *p_result)
{
    *(uint32_t *)p_result = base->SE_PWR;
}
/**
 * @brief Sum of the squares of the elements of a q31 vector.
 *
 * @param   base FSP peripheral base address
 * @param   *p_src points to the input vector
 * @param   block_size length of the input vector
 * @param   *p_result sum of the squares value returned here
 * @return none.
 */
void FSP_PowerQ31(FSP_Type *base, q31_t *p_src, uint32_t block_size, q31_t *p_result);

/**
 * @brief  Calculate Sum of the squares of the elements of a q31 vector.
 * @brief  Interrupt-mode interface
 *
 * @param   base FSP peripheral base address
 * @param   *p_src points to the input vector
 * @param   block_size length of the input vector
 * @return none.
 */
static inline void FSP_PowerIntQ31(FSP_Type *base, q31_t *p_src, uint32_t block_size)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFix, kFSP_SeDinFpSelFix, 1, 0, 0, 0, 0, 0), p_src);
}

/**
 * @brief Get the Sum of the squares of the elements value of a q31 vector.
 * @brief  Interrupt-mode interface
 *
 * @param   base FSP peripheral base address
 * @param   *p_result sum of the squares value returned here
 * @return none.
 */
static inline void FSP_GetPowerIntResultQ31(FSP_Type *base, q31_t *p_result)
{
    *p_result = base->SE_PWR;
}
/**
 * @brief Correlation of real sequences.
 *
 * @param   base FSP peripheral base address
 * @param   *p_src_x points to the first input sequence.
 * @param   *p_src_y points to the second input sequence.
 * @param   *p_dst points to the location where the output result is written.
 * @return none.
 */

static inline void FSP_CorrelationStart(FSP_Type *base,
                                        uint32_t corr_cfg,
                                        uint8_t x_offset,
                                        uint8_t y_offset,
                                        const void *p_src_x,
                                        const void *p_src_y,
                                        const void *p_dst)
{
    base->CX_SRC_BASE = FSP_CX_SRC_BASE_COR_X_ADDR(p_src_x);
    base->CY_SRC_BASE = FSP_CY_SRC_BASE_COR_Y_ADDR(p_src_y);
    base->CO_DST_BASE = FSP_CO_DST_BASE_COR_DST_BASE(p_dst);
    base->COR_OFFSET  = FSP_COR_OFFSET_COR_X_OFFSET(x_offset) | FSP_COR_OFFSET_COR_Y_OFFSET(y_offset);
    base->COR_CTRL    = corr_cfg;
}
/*! @}*/
/**
 * @defgroup Corr Correlation
 * @{
 */
/**
 * @brief Correlation of floating-point sequences.
 *
 * @param   base FSP peripheral base address
 * @param   *p_src_a points to the long input sequence.
 * @param   srcALen length of the long input sequence, srcALen < 2 ^(Kx).
 * @param   *p_src_b points to the short input sequence.
 * @param   srcBLen length of the short input sequence, srcALen < 2 ^(Ky).
 * @param  *p_dst points to the location where the output result is written, Length  = srcALen - srcBLen + 1.
 * @return none.
 */

void FSP_CorrelateF32(
    FSP_Type *base, float32_t *p_src_a, uint32_t srcALen, float32_t *p_src_b, uint32_t srcBLen, float32_t *p_dst);

/**
 * @brief Correlation of q31 sequences.
 *
 * @param   base FSP peripheral base address
 * @param  *p_src_a points to the long input sequence.
 * @param  srcALen length of the long input sequence, srcALen < 2 ^(Kx).
 * @param  *p_src_b points to the short input sequence.
 * @param  srcBLen length of the short input sequence, srcALen < 2 ^(Ky).
 * @param  *p_dst points to the location where the output result is written, Length  = srcALen - srcBLen + 1.
 * @return none.
 */
void FSP_CorrelateQ31(FSP_Type *base, q31_t *p_src_a, uint32_t srcALen, q31_t *p_src_b, uint32_t srcBLen, q31_t *p_dst);
/*! @}*/
/**
 * @brief Clear FIR buffer.
 * @param   idx       channel index.
 * @return none.
 */
static inline void FSP_FirBufferClear(FSP_Type *base, uint32_t ch_idx)
{
    uint32_t reg;

    reg = *((volatile uint32_t *)(base + kFSP_FirCfgCh0Offset + (ch_idx << 2)));
    reg &= ~FSP_FIR_CFG_CH0_FIR_CH0_BUF_CLR_MASK;
    reg |= FSP_FIR_CFG_CH0_FIR_CH0_BUF_CLR_MASK;

    *((volatile uint32_t *)(base + kFSP_FirCfgCh0Offset + (ch_idx << 2))) = reg;
}

/**
 * @brief Clear All FIR buffer.
 * @return none.
 */
static inline void FSP_FirBufferClearAll(FSP_Type *base)
{
    (*((volatile uint32_t *)(base + kFSP_FirCfgCh0Offset)) = FSP_FIR_CFG_CH0_FIR_BUF_CLR_ALL_MASK);
}

/*FIR API*/

/**
 * @brief FIR (Finite Impulse Response) filter function of floating-point sequences.
 *
 * @param   base FSP peripheral base address
 * @param   *S points to an instance of the FIR filter structure.
 * @param   *p_src points to the block of input floating-point data.
 * @param  *p_dst points to the block of output floating-point data.
 * @param   block_size  number of samples to process per call, this value should bigger than 2.
 * @return     none.
 *
 */
void FSP_FirF32(FSP_Type *base, const fsp_fir_instance_t *S, float32_t *p_src, float32_t *p_dst, uint32_t block_size);

/**
 * @brief FIR (Finite Impulse Response) filter function of q31 sequences.
 *
 * @param   base FSP peripheral base address
 * @param   *S points to an instance of the FIR filter structure.
 * @param   *p_src points to the block of input q31 data.
 * @param  *p_dst points to the block of output q31 data.
 * @param   block_size  number of samples to process per call.
 * @return     none.
 */
void FSP_FirQ31(FSP_Type *base, const fsp_fir_instance_t *S, q31_t *p_src, q31_t *p_dst, uint32_t block_size);

#if defined(__CC_ARM)
#pragma no_anon_unions
#endif

#ifdef __cplusplus
}
#endif

#endif /* FSL_FSP_H_ */

/**
 * @}
 */
