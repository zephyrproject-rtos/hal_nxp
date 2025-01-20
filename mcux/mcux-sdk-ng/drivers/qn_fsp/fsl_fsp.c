/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @addtogroup FSP
 * @{
 */
#include "fsl_fsp.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.qn_fsp"
#endif

#define kFSP
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/**
 * @details  Check FSP work mode(Interrupt or Polling)
 * @param base FSP peripheral base address.
 * @param mask interrupt source.
 * @return true or false.
 */
static inline bool FSP_CheckWorkMode(FSP_Type *base, uint32_t mask);

/**
 * @details  Processing function for the Matrix operation unit.
 * @brief    Check if the Matrix operation unit has finished calculation.
 * @param base FSP peripheral base address.
 * @return none.
 */
static inline void FSP_WaitMatOpDone(FSP_Type *base);

/**
 * @details  Processing function for the transfer engine.
 * @brief    Check if the transfer engine has finished calculation.
 * @param base FSP peripheral base address.
 * @return none.
 */
static inline void FSP_WaitTeOpDone(FSP_Type *base);

/**
 * @details  Processing function for the statistic engine.
 * @brief    Check if the statistic engine has finished calculation.
 * @param base FSP peripheral base address.
 * @return none.
 */
static inline void FSP_WaitSeOpDone(FSP_Type *base);

/**
 * @brief    Check if the correlation has finished or not.
 * @param base FSP peripheral base address.
 * @return none.
 */
static inline void FSP_WaitCorrOpDone(FSP_Type *base);

/*******************************************************************************
 * Code
 ******************************************************************************/
static inline bool FSP_CheckWorkMode(FSP_Type *base, uint32_t mask)
{
    return (base->INTEN & mask) ? false : true;
}

static inline void FSP_WaitMatOpDone(FSP_Type *base)
{
    if (FSP_CheckWorkMode(base, FSP_INTEN_MOU_DONE_INTEN_MASK))
    {
        while (!(FSP_GetStatusFlags(base) & FSP_INT_MOU_DONE_INT_MASK))
        {
        }
        FSP_ClearStatusFlags(base, FSP_INT_MOU_DONE_INT_MASK);
    }
}

static inline void FSP_WaitTeOpDone(FSP_Type *base)
{
    if (FSP_CheckWorkMode(base, FSP_INTEN_TE_DONE_INTEN_MASK))
    {
        while (!(FSP_GetStatusFlags(base) & FSP_INT_TE_DONE_INT_MASK))
        {
        }
        FSP_ClearStatusFlags(base, FSP_INT_TE_DONE_INT_MASK);
    }
}

static inline void FSP_WaitSeOpDone(FSP_Type *base)
{
    while (!(FSP_GetStatusFlags(base) & FSP_INT_SE_DONE_INT_MASK))
    {
    }
    FSP_ClearStatusFlags(base, FSP_INT_SE_DONE_INT_MASK);
}

static inline void FSP_WaitCorrOpDone(FSP_Type *base)
{
    if (FSP_CheckWorkMode(base, FSP_INTEN_COR_DONE_INTEN_MASK))
    {
        while (!(FSP_GetStatusFlags(base) & FSP_INT_COR_DONE_INT_MASK))
        {
        }
        FSP_ClearStatusFlags(base, FSP_INT_COR_DONE_INT_MASK);
    }
}

/*!
 * brief FSP configuration
 *
 * param base FSP peripheral base address.s
 */
void FSP_Init(FSP_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(kCLOCK_Fsp);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_FEATURE_FSP_HAS_NO_RESET) && FSL_FEATURE_FSP_HAS_NO_RESET)
    /* Reset the FSP module */
    RESET_PeripheralReset(kFSP_RST_SHIFT_RSTn);
#endif
}

/*!
 * brief Disables the FSP and gates the FSP clock.
 *
 * param base pointer to FLEXIO_UART_Type structure
 */
void FSP_Deinit(FSP_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(kCLOCK_Fsp);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/**
 * brief  Matrix initialization.
 *
 * param   *S points to an instance of the matrix structure.
 * param   n_rows number of rows in the matrix.
 * param   n_columns number of columns in the matrix.
 * param   *p_data points to the matrix data array.
 * return  none
 */
void FSP_MatInit(fsp_matrix_instance_t *S, uint16_t n_rows, uint16_t n_columns, void *p_data)
{
    /* Assign Number of Rows */
    S->num_rows = n_rows;

    /* Assign Number of Columns */
    S->num_cols = n_columns;

    /* Assign Data pointer */
    S->p_data = p_data;
}

/**
 * brief Floating-point matrix inverse.
 *
 * param   base FSP peripheral base address
 * param   *p_src points to input matrix structure
 * param   *p_dst points to output matrix structure
 * return  none
 */
void FSP_MatInverseF32(FSP_Type *base, const fsp_matrix_instance_t *p_src, const fsp_matrix_instance_t *p_dst)
{
    fsp_mat_op_instance_t S;
    S.mat_op_cfg  = MAT_OP_CONFIG(0, 0, 0, p_src->num_cols, p_src->num_rows, kFSP_MouDoutFpSelFloat,
                                 kFSP_MouDinFpSelFloat, kFSP_MouOpModeInv);
    S.scale_a_f32 = 1.0f;
    S.scale_b_f32 = 1.0f;

    FSP_MatOperateStart(base, &S, p_src->p_data, NULL, p_dst->p_data);

    FSP_WaitMatOpDone(base);
}

/**
 * brief q31 matrix inverse.
 *
 * param   base  FSP peripheral base address
 * param   *p_src points to input matrix structure
 * param   *p_dst points to output matrix structure
 * return  none
 */
void FSP_MatInverseQ31(FSP_Type *base, const fsp_matrix_instance_t *p_src, const fsp_matrix_instance_t *p_dst)
{
    fsp_mat_op_instance_t S;
    S.mat_op_cfg  = MAT_OP_CONFIG(0, 0, 0, p_src->num_cols, p_src->num_rows, kFSP_MouDoutFpSelFix, kFSP_MouDinFpSelFix,
                                 kFSP_MouOpModeInv);
    S.scale_a_f32 = 1.0f;
    S.scale_b_f32 = 1.0f;

    FSP_MatOperateStart(base, &S, p_src->p_data, NULL, p_dst->p_data);

    FSP_WaitMatOpDone(base);
}

/**
 * brief Floating-point matrix multiplication.
 *
 * param   base    FSP peripheral base address
 * param   *p_src_a points to the first input matrix structure
 * param   *p_src_b points to the second input matrix structure
 * param   *p_dst points to output matrix structure
 * return  none
 */
void FSP_MatMultF32(FSP_Type *base,
                    const fsp_matrix_instance_t *p_src_a,
                    const fsp_matrix_instance_t *p_src_b,
                    const fsp_matrix_instance_t *p_dst)
{
    fsp_mat_op_instance_t S;
    S.mat_op_cfg  = MAT_OP_CONFIG(0, 0, p_src_b->num_cols, p_src_a->num_cols, p_src_a->num_rows, kFSP_MouDoutFpSelFloat,
                                 kFSP_MouDinFpSelFloat, kFSP_MouOpModeMult);
    S.scale_a_f32 = 1.0f;
    S.scale_b_f32 = 1.0f;

    FSP_MatOperateStart(base, &S, p_src_a->p_data, p_src_b->p_data, p_dst->p_data);

    FSP_WaitMatOpDone(base);
}

/**
 * brief q31 matrix multiplication
 *
 * param   base    FSP peripheral base address
 * param   *p_src_a    points to the first input matrix structure
 * param   *p_src_b    points to the second input matrix structure
 * param   *p_dst  points to output matrix structure
 * return  none
 */
void FSP_MatMultQ31(FSP_Type *base,
                    const fsp_matrix_instance_t *p_src_a,
                    const fsp_matrix_instance_t *p_src_b,
                    const fsp_matrix_instance_t *p_dst)
{
    fsp_mat_op_instance_t S;
    S.mat_op_cfg  = MAT_OP_CONFIG(0, 0, p_src_b->num_cols, p_src_a->num_cols, p_src_a->num_rows, kFSP_MouDoutFpSelFix,
                                 kFSP_MouDinFpSelFix, kFSP_MouOpModeMult);
    S.scale_a_f32 = 1.0f;
    S.scale_b_f32 = 1.0f;

    FSP_MatOperateStart(base, &S, p_src_a->p_data, p_src_b->p_data, p_dst->p_data);

    FSP_WaitMatOpDone(base);
}

/**
 * brief Floating-point matrix dot multiplication.
 *
 * param   base FSP peripheral base address
 * param   *p_src_a points to the first input matrix structure
 * param   *p_src_b points to the second input matrix structure
 * param   *p_dst points to output matrix structure
 * return  none
 */
void FSP_MatDotMultF32(FSP_Type *base,
                       const fsp_matrix_instance_t *p_src_a,
                       const fsp_matrix_instance_t *p_src_b,
                       const fsp_matrix_instance_t *p_dst)

{
    fsp_mat_op_instance_t S;
    S.mat_op_cfg  = MAT_OP_CONFIG(0, 0, p_src_b->num_cols, p_src_a->num_cols, p_src_a->num_rows, kFSP_MouDoutFpSelFloat,
                                 kFSP_MouDinFpSelFloat, kFSP_MouOpModeDotMult);
    S.scale_a_f32 = 1.0f;
    S.scale_b_f32 = 1.0f;

    FSP_MatOperateStart(base, &S, p_src_a->p_data, p_src_b->p_data, p_dst->p_data);

    FSP_WaitMatOpDone(base);
}

/**
 * brief q31 matrix dot multiplication
 *
 * param   base FSP peripheral base address
 * param   *p_src_a points to the first input matrix structure
 * param   *p_src_b points to the second input matrix structure
 * param   *p_dst points to output matrix structure
 * return  none
 *
 */
void FSP_MatDotMultQ31(FSP_Type *base,
                       const fsp_matrix_instance_t *p_src_a,
                       const fsp_matrix_instance_t *p_src_b,
                       const fsp_matrix_instance_t *p_dst)
{
    fsp_mat_op_instance_t S;
    S.mat_op_cfg  = MAT_OP_CONFIG(0, 0, p_src_b->num_cols, p_src_a->num_cols, p_src_a->num_rows, kFSP_MouDoutFpSelFix,
                                 kFSP_MouDinFpSelFix, kFSP_MouOpModeDotMult);
    S.scale_a_f32 = 1.0f;
    S.scale_b_f32 = 1.0f;

    FSP_MatOperateStart(base, &S, p_src_a->p_data, p_src_b->p_data, p_dst->p_data);

    FSP_WaitMatOpDone(base);
}

/**
 * brief Floating-point matrix transpose.
 *
 * param  base FSP peripheral base address
 * param  *p_src points to the input matrix
 * param  *p_dst points to the output matrix
 * return    none
 */
void FSP_MatTransF32(FSP_Type *base, const fsp_matrix_instance_t *p_src, const fsp_matrix_instance_t *p_dst)

{
    fsp_mat_op_instance_t S;
    S.mat_op_cfg  = MAT_OP_CONFIG(0, 0, 0, p_src->num_cols, p_src->num_rows, kFSP_MouDoutFpSelFloat,
                                 kFSP_MouDinFpSelFloat, kFSP_MouOpModeTrans);
    S.scale_a_f32 = 1.0f;
    S.scale_b_f32 = 1.0f;

    FSP_MatOperateStart(base, &S, p_src->p_data, NULL, p_dst->p_data);

    FSP_WaitMatOpDone(base);
}

/*
 * brief q31 matrix transpose.
 *
 * param  base FSP peripheral base address
 * param  *p_src points to the input matrix
 * param  *p_dst points to the output matrix
 * return    The function returns either  <code>ARM_MATH_SIZE_MISMATCH</code>
 * or <code>ARM_MATH_SUCCESS</code> based on the outcome of size checking.
 */
void FSP_MatTransQ31(FSP_Type *base, const fsp_matrix_instance_t *p_src, const fsp_matrix_instance_t *p_dst)
{
    fsp_mat_op_instance_t S;
    S.mat_op_cfg  = MAT_OP_CONFIG(0, 0, 0, p_src->num_cols, p_src->num_rows, kFSP_MouDoutFpSelFix, kFSP_MouDinFpSelFix,
                                 kFSP_MouOpModeTrans);
    S.scale_a_f32 = 1.0f;
    S.scale_b_f32 = 1.0f;

    FSP_MatOperateStart(base, &S, p_src->p_data, NULL, p_dst->p_data);

    FSP_WaitMatOpDone(base);
}

/**
 * brief Floating-point matrix scaling(a*A + b*B).
 *
 * param   base FSP peripheral base address
 * param   *p_src_a points to the first input matrix structure
 * param   scale_a scale factor of matrix_a to be applied
 * param   *p_src_b points to the second input matrix structure
 * param   scale_b scale factor of matrix_b to be applied
 * param   *p_dst points to output matrix structure
 * return  None
 */
void FSP_MatScaleF32(FSP_Type *base,
                     const fsp_matrix_instance_t *p_src_a,
                     float32_t scale_a,
                     const fsp_matrix_instance_t *p_src_b,
                     float32_t scale_b,
                     const fsp_matrix_instance_t *p_dst)

{
    fsp_mat_op_instance_t S;
    S.mat_op_cfg  = MAT_OP_CONFIG(0, 0, 0, p_src_a->num_cols, p_src_a->num_rows, kFSP_MouDoutFpSelFloat,
                                 kFSP_MouDinFpSelFloat, kFSP_MouOpModeScale);
    S.scale_a_f32 = scale_a;
    S.scale_b_f32 = scale_b;

    FSP_MatOperateStart(base, &S, p_src_a->p_data, p_src_b->p_data, p_dst->p_data);

    FSP_WaitMatOpDone(base);
}

/**
 * brief q31 matrix scaling.
 *
 * param   base FSP peripheral base address
 * param   *p_src_a points to the first input matrix structure
 * param   scale_a scale factor of matrix_a to be applied
 * param   *p_src_b points to the second input matrix structure
 * param   scale_b scale factor of matrix_b to be applied
 * param   *p_dst points to output matrix structure
 * return            none
 */
void FSP_MatScaleQ31(FSP_Type *base,
                     const fsp_matrix_instance_t *p_src_a,
                     float32_t scale_a,
                     const fsp_matrix_instance_t *p_src_b,
                     float32_t scale_b,
                     const fsp_matrix_instance_t *p_dst)

{
    fsp_mat_op_instance_t S;
    S.mat_op_cfg  = MAT_OP_CONFIG(0, 0, 0, p_src_a->num_cols, p_src_a->num_rows, kFSP_MouDoutFpSelFix,
                                 kFSP_MouDinFpSelFix, kFSP_MouOpModeScale);
    S.scale_a_f32 = scale_a;
    S.scale_b_f32 = scale_b;

    FSP_MatOperateStart(base, &S, p_src_a->p_data, p_src_b->p_data, p_dst->p_data);

    FSP_WaitMatOpDone(base);
}

/**
 * brief Floating-point matrix addition.
 *
 * param   base FSP peripheral base address
 * param   *p_src_a points to the first input matrix structure
 * param   *p_src_b points to the second input matrix structure
 * param   *p_dst points to output matrix structure
 * return  none
 */
void FSP_MatAddF32(FSP_Type *base,
                   const fsp_matrix_instance_t *p_src_a,
                   const fsp_matrix_instance_t *p_src_b,
                   const fsp_matrix_instance_t *p_dst)

{
    fsp_mat_op_instance_t S;
    S.mat_op_cfg  = MAT_OP_CONFIG(0, 0, 0, p_src_a->num_cols, p_src_a->num_rows, kFSP_MouDoutFpSelFloat,
                                 kFSP_MouDinFpSelFloat, kFSP_MouOpModeScale);
    S.scale_a_f32 = 1.0f;
    S.scale_b_f32 = 1.0f;

    FSP_MatOperateStart(base, &S, p_src_a->p_data, p_src_b->p_data, p_dst->p_data);

    FSP_WaitMatOpDone(base);
}

/**
 * brief q31 matrix addition.
 *
 * param   base FSP peripheral base address
 * param   *p_src_a points to the first input matrix structure
 * param   *p_src_b points to the second input matrix structure
 * param   *p_dst points to output matrix structure
 * return            none
 * The function uses saturating arithmetic.
 * Results outside of the allowable q31 range [0x80000000 0x7FFFFFFF] will be saturated.
 */
void FSP_MatAddQ31(FSP_Type *base,
                   const fsp_matrix_instance_t *p_src_a,
                   const fsp_matrix_instance_t *p_src_b,
                   const fsp_matrix_instance_t *p_dst)

{
    fsp_mat_op_instance_t S;
    S.mat_op_cfg  = MAT_OP_CONFIG(0, 0, 0, p_src_a->num_cols, p_src_a->num_rows, kFSP_MouDoutFpSelFix,
                                 kFSP_MouDinFpSelFix, kFSP_MouOpModeScale);
    S.scale_a_f32 = 1.0f;
    S.scale_b_f32 = 1.0f;

    FSP_MatOperateStart(base, &S, p_src_a->p_data, p_src_b->p_data, p_dst->p_data);

    FSP_WaitMatOpDone(base);
}

/**
 * brief Floating-point matrix subtraction
 *
 * param   base FSP peripheral base address
 * param   *p_src_a points to the first input matrix structure
 * param   *p_src_b points to the second input matrix structure
 * param   *p_dst points to output matrix structure
 * return            none
 */
void FSP_MatSubF32(FSP_Type *base,
                   const fsp_matrix_instance_t *p_src_a,
                   const fsp_matrix_instance_t *p_src_b,
                   const fsp_matrix_instance_t *p_dst)
{
    fsp_mat_op_instance_t S;
    S.mat_op_cfg  = MAT_OP_CONFIG(0, 0, 0, p_src_a->num_cols, p_src_a->num_rows, kFSP_MouDoutFpSelFloat,
                                 kFSP_MouDinFpSelFloat, kFSP_MouOpModeScale);
    S.scale_a_f32 = 1.0f;
    S.scale_b_f32 = -1.0f;

    FSP_MatOperateStart(base, &S, p_src_a->p_data, p_src_b->p_data, p_dst->p_data);

    FSP_WaitMatOpDone(base);
}

/**
 * brief q31 matrix subtraction.
 *
 * param   base FSP peripheral base address
 * param   *p_src_a points to the first input matrix structure
 * param   *p_src_b points to the second input matrix structure
 * param   *p_dst points to output matrix structure
 * return  none
 * The function uses saturating arithmetic.
 * Results outside of the allowable q31 range [0x80000000 0x7FFFFFFF] will be saturated.
 */
void FSP_MatSubQ31(FSP_Type *base,
                   const fsp_matrix_instance_t *p_src_a,
                   const fsp_matrix_instance_t *p_src_b,
                   const fsp_matrix_instance_t *p_dst)

{
    fsp_mat_op_instance_t S;
    S.mat_op_cfg  = MAT_OP_CONFIG(0, 0, 0, p_src_a->num_cols, p_src_a->num_rows, kFSP_MouDoutFpSelFix,
                                 kFSP_MouDinFpSelFix, kFSP_MouOpModeScale);
    S.scale_a_f32 = 1.0f;
    S.scale_b_f32 = -1.0f;

    FSP_MatOperateStart(base, &S, p_src_a->p_data, p_src_b->p_data, p_dst->p_data);

    FSP_WaitMatOpDone(base);
}
/**
 * details  Pre-processing function for IDCT.
 * brief    Only for IDCT: Convert the input data

 * param   base FSP peripheral base address
 * param   *p_data points to input and output data.
 * return none.
 */
void FSP_TeIDCTPreProcess(FSP_Type *base, float32_t *p_data)
{
    (*p_data) *= FSP_SqrtF32(base, (float32_t)1 / 2);
}
/**
 * details  Post-processing function for the transfer engine.
 * brief    For FFT/IFFT/CFFT: Make the output of FSP match the ARM's
 *           For DCT/IDCT: Convert the output from DCT-II to DCT-IV
 * param   base FSP peripheral base address
 * param   *S points to an instance of the fsp_te_instance_t structure.
 * param   io_mode input and output mode defined by enum fsp_te_io_mode_t
 * param   te_mode transfer engine mode defined by enum fsp_te_mode_t
 * param   *p_data points to input and output data.
 * return none.
 */
void FSP_TePostProcess(
    FSP_Type *base, const fsp_te_instance_t *S, fsp_te_io_mode_t io_mode, fsp_te_mode_t te_mode, float32_t *p_data)
{
    uint32_t i           = 0;
    uint32_t num         = 1;
    float32_t post_mult1 = 1.0f;
    float32_t post_mult2 = 1.0f;
    float32_t *p         = p_data;

    if (S->te_point == kFSP_TePts64Points)
    {
        num = 64;
    }
    else if (S->te_point == kFSP_TePts128Points)
    {
        num = 128;
    }
    else if (S->te_point == kFSP_TePts256Points)
    {
        num = 256;
    }
    else
    {
        return;
    }
    switch (te_mode)
    {
        case kFSP_TeModeFft:
            post_mult1 = 256.0f;
            break;
        case kFSP_TeModeIfft:
            post_mult1 = 256.0f / num;
            break;
        case kFSP_TeModeDct:
            post_mult2 = FSP_SqrtF32(base, (float32_t)1 / num) * 256.0f;
            post_mult1 = FSP_SqrtF32(base, (float32_t)2 / num) * 256.0f;
            break;
        case kFSP_TeModeIdct:
            post_mult1 = FSP_SqrtF32(base, (float32_t)2 / num) * 256.0f;
            break;
        default:
            break;
    }
    if ((io_mode == kFSP_TeIoModeRealInputComplexOutput) || (io_mode == kFSP_TeIoModeComplexInputComplexOutput))
    {
        num *= 2;
    }
    for (i = 0; i < num; i++)
    {
        if ((te_mode == kFSP_TeModeDct) && (i == 0))
        {
            (*p++) *= post_mult2;
        }
        else
        {
            (*p++) *= post_mult1;
        }
    }
    if ((te_mode == kFSP_TeModeFft) && (io_mode == kFSP_TeIoModeRealInputComplexOutput))
    {
        *(p_data + 1) = *(p_data + num / 2);
    }
}
/**
 * brief Processing function for the floating-point real FFT.
 *
 * param   base FSP peripheral base address
 * param   *S points to an instance of the fsp_te_instance_t structure.
 * param   *p_src points to the input buffer.
 * param   *p_dst points to the output buffer.
 * return none.
 */
void FSP_RfftF32(FSP_Type *base, const fsp_te_instance_t *S, float32_t *p_src, float32_t *p_dst)

{
    FSP_TeStart(base,
                TE_CONFIG(S->te_point, S->te_scale, kFSP_TeDoutFpSelFloat, kFSP_TeDinFpSelFloat,
                          kFSP_TeIoModeRealInputComplexOutput, kFSP_TeModeFft),
                p_src, p_dst);

    FSP_WaitTeOpDone(base);
}

/**
 * brief Processing function for the floating-point real IFFT.
 *
 * param   base FSP peripheral base address
 * param   *S points to an instance of the fsp_te_instance_t structure.
 * param   *p_src points to the input buffer.
 * param   *p_dst points to the output buffer.
 * return none.
 */
void FSP_RifftF32(FSP_Type *base, const fsp_te_instance_t *S, float32_t *p_src, float32_t *p_dst)

{
    FSP_TeStart(base,
                TE_CONFIG(S->te_point, S->te_scale, kFSP_TeDoutFpSelFloat, kFSP_TeDinFpSelFloat,
                          kFSP_TeIoModeComplexInputRealOutput, kFSP_TeModeIfft),
                p_src, p_dst);

    FSP_WaitTeOpDone(base);
}

/**
 * brief Processing function for the q31 real FFT.
 *
 * param   base FSP peripheral base address
 * param   *S points to an instance of the fsp_te_instance_t structure.
 * param   *p_src points to the input buffer.
 * param   *p_dst points to the output buffer.
 * return none.
 */
void FSP_RfftQ31(FSP_Type *base, const fsp_te_instance_t *S, q31_t *p_src, q31_t *p_dst)

{
    FSP_TeStart(base,
                TE_CONFIG(S->te_point, S->te_scale, kFSP_TeDoutFpSelFix, kFSP_TeDinFpSelFix,
                          kFSP_TeIoModeRealInputComplexOutput, kFSP_TeModeFft),
                p_src, p_dst);

    FSP_WaitTeOpDone(base);
}

/**
 * brief Processing function for the q31 real IFFT.
 *
 * param   base FSP peripheral base address
 * param   *S points to an instance of the fsp_te_instance_t structure.
 * param   *p_src points to the input buffer.
 * param   *p_dst points to the output buffer.
 * return none.
 */
void FSP_RifftQ31(FSP_Type *base, const fsp_te_instance_t *S, q31_t *p_src, q31_t *p_dst)

{
    FSP_TeStart(base,
                TE_CONFIG(S->te_point, S->te_scale, kFSP_TeDoutFpSelFix, kFSP_TeDinFpSelFix,
                          kFSP_TeIoModeComplexInputRealOutput, kFSP_TeModeIfft),
                p_src, p_dst);

    FSP_WaitTeOpDone(base);
}

/**
 * brief Processing function for the floating-point complex FFT/IFFT.
 *
 * param  base FSP peripheral base address
 * param  *S points to an instance of the fsp_te_instance_t structure.
 * param  *p_src points to the input buffer.
 * param  *p_dst points to the output buffer.
 * param   ifft_flag flag that selects forward (ifft_flag=0) or inverse (ifft_flag=1) transform.
 * return none.
 */
void FSP_CfftF32(FSP_Type *base, const fsp_te_instance_t *S, float32_t *p_src, float32_t *p_dst, uint8_t ifft_flag)

{
    FSP_TeStart(base,
                TE_CONFIG(S->te_point, S->te_scale, kFSP_TeDoutFpSelFloat, kFSP_TeDinFpSelFloat,
                          kFSP_TeIoModeComplexInputComplexOutput, kFSP_TeModeFft | ifft_flag),
                p_src, p_dst);

    FSP_WaitTeOpDone(base);
}

/**
 * brief Processing function for the q31 complex FFT/IFFT.
 *
 * param   base FSP peripheral base address
 * param   *S points to an instance of the fsp_te_instance_t structure.
 * param   *p_src points to the input buffer.
 * param   *p_dst points to the output buffer.
 * param   ifft_flag flag that selects forward (ifft_flag=0) or inverse (ifft_flag=1) transform.
 * return none.
 */
void FSP_CfftQ31(FSP_Type *base, const fsp_te_instance_t *S, q31_t *p_src, q31_t *p_dst, uint8_t ifft_flag)

{
    FSP_TeStart(base,
                TE_CONFIG(S->te_point, S->te_scale, kFSP_TeDoutFpSelFix, kFSP_TeDinFpSelFix,
                          kFSP_TeIoModeComplexInputComplexOutput, kFSP_TeModeFft | ifft_flag),
                p_src, p_dst);

    FSP_WaitTeOpDone(base);
}

/**
 * brief Processing function for the floating-point DCT/IDCT.
 *
 * param   base FSP peripheral base address
 * param   *S points to an instance of the fsp_te_instance_t structure.
 * param   *p_src points to the input buffer.
 * param   *p_dst points to the output buffer.
 * param   idct_flag flag that selects forward (idct_flag=0) or inverse (idct_flag=1) transform.
 * return none.
 */
void FSP_DctF32(FSP_Type *base, const fsp_te_instance_t *S, float32_t *p_src, float32_t *p_dst, uint8_t idct_flag)

{
    FSP_TeStart(base,
                TE_CONFIG(S->te_point, S->te_scale, kFSP_TeDoutFpSelFloat, kFSP_TeDinFpSelFloat,
                          kFSP_TeIoModeRealInputRealOutput, kFSP_TeModeDct | idct_flag),
                p_src, p_dst);

    FSP_WaitTeOpDone(base);
}

/**
 * brief Processing function for the q31 DCT/IDCT.
 *
 * param  base FSP peripheral base address
 * param  *S  points to an instance of the fsp_te_instance_t structure.
 * param  *p_src  points to the input buffer.
 * param  *p_dst  points to the output buffer.
 * param  idct_flag   flag that selects forward (idct_flag=0) or inverse (idct_flag=1) transform.
 * return none.
 */
void FSP_DctQ31(FSP_Type *base, const fsp_te_instance_t *S, q31_t *p_src, q31_t *p_dst, uint8_t idct_flag)

{
    FSP_TeStart(base,
                TE_CONFIG(S->te_point, S->te_scale, kFSP_TeDoutFpSelFix, kFSP_TeDinFpSelFix,
                          kFSP_TeIoModeRealInputRealOutput, kFSP_TeModeDct | idct_flag),
                p_src, p_dst);

    FSP_WaitTeOpDone(base);
}

/**
 * brief Get Maximum and Minimum values of a floating-point vector.
 *
 * param  *p_src points to the input vector
 * param  block_size length of the input vector
 * param  *p_max  maximum value returned here
 * param  *p_min  Minimum value returned here
 * return none.
 */
void FSP_MaxMinF32(FSP_Type *base, float32_t *p_src, uint32_t block_size, float32_t *p_max, float32_t *p_min)
{
    uint32_t p_index = 0;

    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFloat, kFSP_SeDinFpSelFloat, 0, 0, 1, 1, 0, 0), p_src);

    FSP_WaitSeOpDone(base);
    p_index = base->SE_IDX >> FSP_SE_IDX_SE_MAX_IDX_SHIFT;
    *p_max  = p_src[p_index];
    p_index = base->SE_IDX & FSP_SE_IDX_SE_MIN_IDX_MASK;
    *p_min  = p_src[p_index];
}

/**
 * brief Get the Maximum and Minimum values of a floating-point vector.
 * brief  Interrupt-mode interface
 *
 * param  *p_src points to the input vector
 * param  *p_max  maximum value returned here
 * param  *p_min  Minimum value returned here
 * return none.
 */
void FSP_GetMaxMinIntResultF32(FSP_Type *base, float32_t *p_src, float32_t *p_max, float32_t *p_min)
{
    uint32_t p_index = 0;
    p_index          = base->SE_IDX >> FSP_SE_IDX_SE_MAX_IDX_SHIFT;
    *p_max           = p_src[p_index];
    p_index          = base->SE_IDX & FSP_SE_IDX_SE_MIN_IDX_MASK;
    *p_min           = p_src[p_index];
}

/**
 * brief Get Maximum and Minimum values of a q31 vector.
 *
 * param  *p_src points to the input vector
 * param  block_size length of the input vector
 * param  *p_max  maximum value returned here
 * param  *p_min  Minimum value returned here
 * return none.
 */
void FSP_MaxMinQ31(FSP_Type *base, q31_t *p_src, uint32_t block_size, q31_t *p_max, q31_t *p_min)
{
    uint32_t p_index = 0;
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFix, kFSP_SeDinFpSelFix, 0, 0, 1, 1, 0, 0), p_src);

    FSP_WaitSeOpDone(base);
    p_index = base->SE_IDX >> FSP_SE_IDX_SE_MAX_IDX_SHIFT;
    *p_max  = p_src[p_index];
    p_index = base->SE_IDX & FSP_SE_IDX_SE_MIN_IDX_MASK;
    *p_min  = p_src[p_index];
}

/**
 * brief Get the Maximum and Minimum values of a q31 vector vector.
 * brief  Interrupt-mode interface
 *
 * param  *p_src points to the input vector
 * param  *p_max  maximum value returned here
 * param  *p_min  Minimum value returned here
 * return none.
 */
void FSP_GetMaxMinIntResultQ31(FSP_Type *base, q31_t *p_src, q31_t *p_max, q31_t *p_min)
{
    uint32_t p_index = 0;
    p_index          = base->SE_IDX >> FSP_SE_IDX_SE_MAX_IDX_SHIFT;
    *p_max           = p_src[p_index];
    p_index          = base->SE_IDX & FSP_SE_IDX_SE_MIN_IDX_MASK;
    *p_min           = p_src[p_index];
}

/**
 * brief Maximum value of a floating-point vector.
 *
 * param  base FSP peripheral base address
 * param  *p_src points to the input vector
 * param  block_size length of the input vector
 * param  *p_result maximum value returned here
 * param  *p_index index of maximum value returned here
 * return none.
 */
void FSP_MaxF32(FSP_Type *base, float32_t *p_src, uint32_t block_size, float32_t *p_result, uint32_t *p_index)

{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFloat, kFSP_SeDinFpSelFloat, 0, 0, 1, 0, 0, 0), p_src);

    FSP_WaitSeOpDone(base);
    *p_index  = base->SE_IDX >> FSP_SE_IDX_SE_MAX_IDX_SHIFT;
    *p_result = p_src[*p_index];
}

/**
 * brief Get the Maximum value of a floating-point vector.
 * brief  Interrupt-mode interface
 *
 * param  *p_src points to the input vector
 * param  *p_result maximum value returned here
 * param  *p_index index of maximum value returned here
 * return none.
 */
void FSP_GetMaxIntResultF32(FSP_Type *base, float32_t *p_src, float32_t *p_result, uint32_t *p_index)
{
    *p_index  = base->SE_IDX >> FSP_SE_IDX_SE_MAX_IDX_SHIFT;
    *p_result = p_src[*p_index];
}

/**
 * brief Maximum value of a q31 vector.
 *
 * param   base FSP peripheral base address
 * param   *p_src points to the input vector
 * param   block_size length of the input vector
 * param   *p_result maximum value returned here
 * param   *p_index index of maximum value returned here
 * return none.
 */
void FSP_MaxQ31(FSP_Type *base, q31_t *p_src, uint32_t block_size, q31_t *p_result, uint32_t *p_index)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFix, kFSP_SeDinFpSelFix, 0, 0, 1, 0, 0, 0), p_src);

    FSP_WaitSeOpDone(base);
    *p_index  = base->SE_IDX >> FSP_SE_IDX_SE_MAX_IDX_SHIFT;
    *p_result = p_src[*p_index];
}

/**
 * brief Get the Maximum value of a q31 vector.
 * brief  Interrupt-mode interface
 *
 * param  *p_src points to the input vector
 * param  *p_result maximum value returned here
 * param  *p_index index of maximum value returned here
 * return none.
 */
void FSP_GetMaxIntResultQ31(FSP_Type *base, q31_t *p_src, q31_t *p_result, uint32_t *p_index)
{
    *p_index  = base->SE_IDX >> FSP_SE_IDX_SE_MAX_IDX_SHIFT;
    *p_result = p_src[*p_index];
}

/**
 * brief Minimum value of a floating-point vector.
 *
 * param   base FSP peripheral base address
 * param   *p_src points to the input vector
 * param   block_size length of the input vector
 * param   *p_result minimum value returned here
 * param   *p_index index of minimum value returned here
 * return none.
 */
void FSP_MinF32(FSP_Type *base, float32_t *p_src, uint32_t block_size, float32_t *p_result, uint32_t *p_index)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFloat, kFSP_SeDinFpSelFloat, 0, 0, 0, 1, 0, 0), p_src);

    FSP_WaitSeOpDone(base);
    *p_index  = base->SE_IDX & FSP_SE_IDX_SE_MIN_IDX_MASK;
    *p_result = p_src[*p_index];
}

/**
 * brief Get the Minimum value of a floating-point vector.
 * brief  Interrupt-mode interface
 *
 * param  *p_src points to the input vector
 * param  *p_result minimum value returned here
 * param  *p_index index of minimum value returned here
 * return none.
 */
void FSP_GetMinIntResultF32(FSP_Type *base, float32_t *p_src, float32_t *p_result, uint32_t *p_index)
{
    *p_index  = base->SE_IDX & FSP_SE_IDX_SE_MIN_IDX_MASK;
    *p_result = p_src[*p_index];
}

/**
 * brief Minimum value of a q31 vector.
 *
 * param   base FSP peripheral base address
 * param   *p_src points to the input vector
 * param   block_size length of the input vector
 * param   *p_result minimum value returned here
 * param   *p_index index of minimum value returned here
 * return none.
 */
void FSP_MinQ31(FSP_Type *base, q31_t *p_src, uint32_t block_size, q31_t *p_result, uint32_t *p_index)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFix, kFSP_SeDinFpSelFix, 0, 0, 0, 1, 0, 0), p_src);

    FSP_WaitSeOpDone(base);
    *p_index  = base->SE_IDX & FSP_SE_IDX_SE_MIN_IDX_MASK;
    *p_result = p_src[*p_index];
}

/**
 * brief Get the Minimum value of a q31 vector.
 * brief  Interrupt-mode interface
 *
 * param  *p_src points to the input vector
 * param  *p_result minimum value returned here
 * param  *p_index index of minimum value returned here
 * return none.
 */
void FSP_GetMinIntResultQ31(FSP_Type *base, q31_t *p_src, q31_t *p_result, uint32_t *p_index)
{
    *p_index  = base->SE_IDX & FSP_SE_IDX_SE_MIN_IDX_MASK;
    *p_result = p_src[*p_index];
}

/**
 * brief Sum value of a floating-point vector.
 *
 * param   base FSP peripheral base address
 * param   *p_src points to the input vector
 * param   block_size length of the input vector
 * param   *p_result Sum value returned here
 * return none.
 */
void FSP_SumF32(FSP_Type *base, float32_t *p_src, uint32_t block_size, float32_t *p_result)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFloat, kFSP_SeDinFpSelFloat, 0, 1, 0, 0, 0, 0), p_src);

    FSP_WaitSeOpDone(base);
    *(uint32_t *)p_result = base->SE_SUM;
}

/**
 * brief Sum value of a q31 vector.
 *
 * param   base FSP peripheral base address
 * param   *p_src points to the input vector
 * param   block_size length of the input vector
 * param   *p_result Sum value returned here
 * return none.
 *
 */
void FSP_SumQ31(FSP_Type *base, q31_t *p_src, uint32_t block_size, q31_t *p_result)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFix, kFSP_SeDinFpSelFix, 0, 1, 0, 0, 0, 0), p_src);

    FSP_WaitSeOpDone(base);
    *p_result = base->SE_SUM;
}

/**
 * brief Sum of the squares of the elements of a floating-point vector.
 *
 * param   base FSP peripheral base address
 * param   *p_src points to the input vector
 * param   block_size length of the input vector
 * param   *p_result sum of the squares value returned here
 * return none.
 *
 */
void FSP_PowerF32(FSP_Type *base, float32_t *p_src, uint32_t block_size, float32_t *p_result)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFloat, kFSP_SeDinFpSelFloat, 1, 0, 0, 0, 0, 0), p_src);

    FSP_WaitSeOpDone(base);
    *(uint32_t *)p_result = base->SE_PWR;
}

/**
 * brief Sum of the squares of the elements of a q31 vector.
 *
 * param   base FSP peripheral base address
 * param   *p_src points to the input vector
 * param   block_size length of the input vector
 * param   *p_result sum of the squares value returned here
 * return none.
 */
void FSP_PowerQ31(FSP_Type *base, q31_t *p_src, uint32_t block_size, q31_t *p_result)
{
    FSP_SeStart(base, SE_CONFIG(block_size, kFSP_SeDoutFpSelFix, kFSP_SeDinFpSelFix, 1, 0, 0, 0, 0, 0), p_src);

    FSP_WaitSeOpDone(base);
    *p_result = base->SE_PWR;
}

/**
 * brief Correlation of floating-point sequences.
 *
 * param   base FSP peripheral base address
 * param   *p_src_a points to the long input sequence.
 * param   srcALen length of the long input sequence, srcALen < 2 ^(Kx).
 * param   *p_src_b points to the short input sequence.
 * param   srcBLen length of the short input sequence, srcALen < 2 ^(Ky).
 * param  *p_dst points to the location where the output result is written, Length  = srcALen - srcBLen + 1.
 * return none.
 */

void FSP_CorrelateF32(
    FSP_Type *base, float32_t *p_src_a, uint32_t srcALen, float32_t *p_src_b, uint32_t srcBLen, float32_t *p_dst)
{
    FSP_CorrelationStart(base, CORR_CONFIG(srcBLen, srcALen, kFSP_CorDoutFpSelFloat, kFSP_CorDinFpSelFloat), 0, 0,
                         p_src_a, p_src_b, p_dst);

    FSP_WaitCorrOpDone(base);
}

/**
 * brief Correlation of q31 sequences.
 *
 * param   base FSP peripheral base address
 * param  *p_src_a points to the long input sequence.
 * param  srcALen length of the long input sequence, srcALen < 2 ^(Kx).
 * param  *p_src_b points to the short input sequence.
 * param  srcBLen length of the short input sequence, srcALen < 2 ^(Ky).
 * param  *p_dst points to the location where the output result is written, Length  = srcALen - srcBLen + 1.
 * return none.
 */
void FSP_CorrelateQ31(FSP_Type *base, q31_t *p_src_a, uint32_t srcALen, q31_t *p_src_b, uint32_t srcBLen, q31_t *p_dst)
{
    FSP_CorrelationStart(base, CORR_CONFIG(srcBLen, srcALen, kFSP_CorDoutFpSelFix, kFSP_CorDinFpSelFix), 0, 0, p_src_a,
                         p_src_b, p_dst);

    FSP_WaitCorrOpDone(base);
}

/**
 * brief FIR (Finite Impulse Response) filter function of floating-point sequences.
 *
 * param   base FSP peripheral base address
 * param   *S points to an instance of the FIR filter structure.
 * param   *p_src points to the block of input floating-point data.
 * param  *p_dst points to the block of output floating-point data.
 * param   block_size  number of samples to process per call, this value should bigger than 2.
 * return     none.
 *
 */
void FSP_FirF32(FSP_Type *base, const fsp_fir_instance_t *S, float32_t *p_src, float32_t *p_dst, uint32_t block_size)
{
    uint32_t addr                                         = (uint32_t)base + ((uint32_t)S->ch_idx << 2);
    *((volatile uint32_t *)(addr + kFSP_FirCfgCh0Offset)) = S->fir_cfg;
    while (base->STATUS & FSP_STATUS_FPU0_BUSY_MASK)
    {
    }
    addr += kFSP_FirDat0FlOffset;

    *((volatile uint32_t *)(addr)) = *(uint32_t *)p_src++;
    for (uint32_t i = 0; i < block_size - 1; i++)
    {
        *((volatile uint32_t *)(addr)) = *(uint32_t *)p_src++;
        while (!(FSP_GetBusyStatusFlags(base) & FSP_STATUS_FIR_READY_MASK))
        {
        }
        *(uint32_t *)p_dst++ = (*((volatile uint32_t *)(addr)));
    }
    while (!(FSP_GetBusyStatusFlags(base) & FSP_STATUS_FIR_READY_MASK))
    {
    }
    *(uint32_t *)p_dst++ = (*((volatile uint32_t *)(addr)));
}

/**
 * brief FIR (Finite Impulse Response) filter function of q31 sequences.
 *
 * param   base FSP peripheral base address
 * param   *S points to an instance of the FIR filter structure.
 * param   *p_src points to the block of input q31 data.
 * param  *p_dst points to the block of output q31 data.
 * param   block_size  number of samples to process per call.
 * return     none.
 */
void FSP_FirQ31(FSP_Type *base, const fsp_fir_instance_t *S, q31_t *p_src, q31_t *p_dst, uint32_t block_size)
{
    uint32_t addr                                         = (uint32_t)base + ((uint32_t)S->ch_idx << 2);
    *((volatile uint32_t *)(addr + kFSP_FirCfgCh0Offset)) = S->fir_cfg;
    while (FSP_GetBusyStatusFlags(base) & FSP_STATUS_FPU0_BUSY_MASK)
    {
    }
    addr += kFSP_FirDat0FxOffset;
    *((volatile uint32_t *)(addr)) = *(uint32_t *)p_src++;
    for (uint32_t i = 0; i < block_size - 1; i++)
    {
        *((volatile uint32_t *)(addr)) = *(uint32_t *)p_src++;
        while (!(FSP_GetBusyStatusFlags(base) & FSP_STATUS_FIR_READY_MASK))
        {
        }
        *p_dst++ = (*((volatile uint32_t *)(addr)));
    }
    while (!(FSP_GetBusyStatusFlags(base) & FSP_STATUS_FIR_READY_MASK))
    {
    }
    *p_dst++ = (*((volatile uint32_t *)(addr)));
}
