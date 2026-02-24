/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_POWERQUAD_CMSIS_H_
#define FSL_POWERQUAD_CMSIS_H_

#include "fsl_common.h"
#include "arm_math.h"

/*!
 * @addtogroup powerquad
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define FSL_POWERQUAD_CMSIS_DRIVER_VERSION (MAKE_VERSION(2, 1, 0)) /*!< Version. */

/*
 * PowerQuad driver implemented some CMSIS DSP APIs.
 *
 * There are two ways to use these APIs, take API `arm_cos_f32` as an example:
 * 1. If you want do use PowerQuad implementation instead of CMSIS DSP implementation,
 *    and don't want to change your existing code, you can define macro
 *    `CONFIG_PQ_ARM_COS_F32` to 0 or don't define it at all. PowerQuad
 *    implementation will replace the original CMSIS DSP implementation.
 *    This is the default behavior.
 * 2. If you want to use PowerQuad implemention together with CMSIS DSP implementation,
 *    please define macro `CONFIG_PQ_ARM_COS_F32` to 1, and include this header.
 *    Then you can use `pq_arm_cos_f32` to call PowerQuad implementation,
 *
 * Each CMSIS DSP API has a macro to control the behavior.
 */

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

#if defined(CONFIG_PQ_ARM_COS_F32) && CONFIG_PQ_ARM_COS_F32
float32_t pq_arm_cos_f32(float32_t x);
#else
#define pq_arm_cos_f32 arm_cos_f32
#endif

#if defined(CONFIG_PQ_ARM_COS_Q31) && CONFIG_PQ_ARM_COS_Q31
q31_t pq_arm_cos_q31(q31_t x);
#else
#define pq_arm_cos_q31 arm_cos_q31
#endif

#if defined(CONFIG_PQ_ARM_COS_Q15) && CONFIG_PQ_ARM_COS_Q15
q15_t pq_arm_cos_q15(q15_t x);
#else
#define pq_arm_cos_q15 arm_cos_q15
#endif

#if defined(CONFIG_PQ_ARM_SIN_F32) && CONFIG_PQ_ARM_SIN_F32
float32_t pq_arm_sin_f32(float32_t x);
#else
#define pq_arm_sin_f32 arm_sin_f32
#endif

#if defined(CONFIG_PQ_ARM_SIN_Q31) && CONFIG_PQ_ARM_SIN_Q31
q31_t pq_arm_sin_q31(q31_t x);
#else
#define pq_arm_sin_q31 arm_sin_q31
#endif

#if defined(CONFIG_PQ_ARM_SIN_Q15) && CONFIG_PQ_ARM_SIN_Q15
q15_t pq_arm_sin_q15(q15_t x);
#else
#define pq_arm_sin_q15 arm_sin_q15
#endif

#if defined(CONFIG_PQ_ARM_SQRT_Q31) && CONFIG_PQ_ARM_SQRT_Q31
arm_status pq_arm_sqrt_q31(q31_t in, q31_t *pOut);
#else
#define pq_arm_sqrt_q31 arm_sqrt_q31
#endif

#if defined(CONFIG_PQ_ARM_SQRT_Q15) && CONFIG_PQ_ARM_SQRT_Q15
arm_status pq_arm_sqrt_q15(q15_t in, q15_t *pOut);
#else
#define pq_arm_sqrt_q15 arm_sqrt_q15
#endif

#if defined(CONFIG_PQ_ARM_CFFT_Q31) && CONFIG_PQ_ARM_CFFT_Q31
void pq_arm_cfft_q31(const arm_cfft_instance_q31 *S, q31_t *p1, uint8_t ifftFlag, uint8_t bitReverseFlag);
#else
#define pq_arm_cfft_q31 arm_cfft_q31
#endif

#if defined(CONFIG_PQ_ARM_CFFT_Q15) && CONFIG_PQ_ARM_CFFT_Q15
void pq_arm_cfft_q15(const arm_cfft_instance_q15 *S, q15_t *p1, uint8_t ifftFlag, uint8_t bitReverseFlag);
#else
#define pq_arm_cfft_q15 arm_cfft_q15
#endif

#if defined(CONFIG_PQ_ARM_RFFT_INIT_Q31) && CONFIG_PQ_ARM_RFFT_INIT_Q31
arm_status pq_arm_rfft_init_q31(arm_rfft_instance_q31 *S, uint32_t fftLenReal, uint32_t ifftFlagR, uint32_t bitReverseFlag);
#else
#define pq_arm_rfft_init_q31 arm_rfft_init_q31
#endif

#if defined(CONFIG_PQ_ARM_RFFT_Q31) && CONFIG_PQ_ARM_RFFT_Q31
void pq_arm_rfft_q31(const arm_rfft_instance_q31 *S, q31_t *pSrc, q31_t *pDst);
#else
#define pq_arm_rfft_q31 arm_rfft_q31
#endif

#if defined(CONFIG_PQ_ARM_RFFT_INIT_Q15) && CONFIG_PQ_ARM_RFFT_INIT_Q15
arm_status pq_arm_rfft_init_q15(arm_rfft_instance_q15 *S, uint32_t fftLenReal, uint32_t ifftFlagR, uint32_t bitReverseFlag);
#else
#define pq_arm_rfft_init_q15 arm_rfft_init_q15
#endif

#if defined(CONFIG_PQ_ARM_RFFT_Q15) && CONFIG_PQ_ARM_RFFT_Q15
void pq_arm_rfft_q15(const arm_rfft_instance_q15 *S, q15_t *pSrc, q15_t *pDst);
#else
#define pq_arm_rfft_q15 arm_rfft_q15
#endif

#if defined(CONFIG_PQ_ARM_DCT4_INIT_Q31) && CONFIG_PQ_ARM_DCT4_INIT_Q31
arm_status pq_arm_dct4_init_q31(arm_dct4_instance_q31 *S,
                             arm_rfft_instance_q31 *S_RFFT,
                             arm_cfft_radix4_instance_q31 *S_CFFT,
                             uint16_t N,
                             uint16_t Nby2,
                             q31_t normalize);
#else
#define pq_arm_dct4_init_q31 arm_dct4_init_q31
#endif

#if defined(CONFIG_PQ_ARM_DCT4_Q31) && CONFIG_PQ_ARM_DCT4_Q31
void pq_arm_dct4_q31(const arm_dct4_instance_q31 *S, q31_t *pState, q31_t *pInlineBuffer);
#else
#define pq_arm_dct4_q31 arm_dct4_q31
#endif

#if defined(CONFIG_PQ_ARM_DCT4_INIT_Q15) && CONFIG_PQ_ARM_DCT4_INIT_Q15
arm_status pq_arm_dct4_init_q15(arm_dct4_instance_q15 *S,
                             arm_rfft_instance_q15 *S_RFFT,
                             arm_cfft_radix4_instance_q15 *S_CFFT,
                             uint16_t N,
                             uint16_t Nby2,
                             q15_t normalize);
#else
#define pq_arm_dct4_init_q15 arm_dct4_init_q15
#endif

#if defined(CONFIG_PQ_ARM_DCT4_Q15) && CONFIG_PQ_ARM_DCT4_Q15
void pq_arm_dct4_q15(const arm_dct4_instance_q15 *S, q15_t *pState, q15_t *pInlineBuffer);
#else
#define pq_arm_dct4_q15 arm_dct4_q15
#endif

#if defined(CONFIG_PQ_ARM_FIR_INIT_F32) && CONFIG_PQ_ARM_FIR_INIT_F32
void pq_arm_fir_init_f32(
    arm_fir_instance_f32 *S, uint16_t numTaps, const float32_t *pCoeffs, float32_t *pState, uint32_t blockSize);
#else
#define pq_arm_fir_init_f32 arm_fir_init_f32
#endif

#if defined(CONFIG_PQ_ARM_FIR_INIT_Q31) && CONFIG_PQ_ARM_FIR_INIT_Q31
void pq_arm_fir_init_q31(
    arm_fir_instance_q31 *S, uint16_t numTaps, const q31_t *pCoeffs, q31_t *pState, uint32_t blockSize);
#else
#define pq_arm_fir_init_q31 arm_fir_init_q31
#endif

#if defined(CONFIG_PQ_ARM_FIR_INIT_Q15) && CONFIG_PQ_ARM_FIR_INIT_Q15
arm_status pq_arm_fir_init_q15(
    arm_fir_instance_q15 *S, uint16_t numTaps, const q15_t *pCoeffs, q15_t *pState, uint32_t blockSize);
#else
#define pq_arm_fir_init_q15 arm_fir_init_q15
#endif

#if defined(CONFIG_PQ_ARM_FIR_F32) && CONFIG_PQ_ARM_FIR_F32
void pq_arm_fir_f32(const arm_fir_instance_f32 *S, const float32_t *pSrc, float32_t *pDst, uint32_t blockSize);
#else
#define pq_arm_fir_f32 arm_fir_f32
#endif

#if defined(CONFIG_PQ_ARM_FIR_Q31) && CONFIG_PQ_ARM_FIR_Q31
void pq_arm_fir_q31(const arm_fir_instance_q31 *S, const q31_t *pSrc, q31_t *pDst, uint32_t blockSize);
#else
#define pq_arm_fir_q31 arm_fir_q31
#endif

#if defined(CONFIG_PQ_ARM_FIR_Q15) && CONFIG_PQ_ARM_FIR_Q15
void pq_arm_fir_q15(const arm_fir_instance_q15 *S, const q15_t *pSrc, q15_t *pDst, uint32_t blockSize);
#else
#define pq_arm_fir_q15 arm_fir_q15
#endif

#if defined(CONFIG_PQ_ARM_CONV_F32) && CONFIG_PQ_ARM_CONV_F32
void pq_arm_conv_f32(const float32_t *pSrcA, uint32_t srcALen, const float32_t *pSrcB, uint32_t srcBLen, float32_t *pDst);
#else
#define pq_arm_conv_f32 arm_conv_f32
#endif

#if defined(CONFIG_PQ_ARM_CONV_Q31) && CONFIG_PQ_ARM_CONV_Q31
void pq_arm_conv_q31(const q31_t *pSrcA, uint32_t srcALen, const q31_t *pSrcB, uint32_t srcBLen, q31_t *pDst);
#else
#define pq_arm_conv_q31 arm_conv_q31
#endif

#if defined(CONFIG_PQ_ARM_CONV_Q15) && CONFIG_PQ_ARM_CONV_Q15
void pq_arm_conv_q15(const q15_t *pSrcA, uint32_t srcALen, const q15_t *pSrcB, uint32_t srcBLen, q15_t *pDst);
#else
#define pq_arm_conv_q15 arm_conv_q15
#endif

#if defined(CONFIG_PQ_ARM_CORRELATE_F32) && CONFIG_PQ_ARM_CORRELATE_F32
void pq_arm_correlate_f32(
    const float32_t *pSrcA, uint32_t srcALen, const float32_t *pSrcB, uint32_t srcBLen, float32_t *pDst);
#else
#define pq_arm_correlate_f32 arm_correlate_f32
#endif

#if defined(CONFIG_PQ_ARM_CORRELATE_Q31) && CONFIG_PQ_ARM_CORRELATE_Q31
void pq_arm_correlate_q31(const q31_t *pSrcA, uint32_t srcALen, const q31_t *pSrcB, uint32_t srcBLen, q31_t *pDst);
#else
#define pq_arm_correlate_q31 arm_correlate_q31
#endif

#if defined(CONFIG_PQ_ARM_CORRELATE_Q15) && CONFIG_PQ_ARM_CORRELATE_Q15
void pq_arm_correlate_q15(const q15_t *pSrcA, uint32_t srcALen, const q15_t *pSrcB, uint32_t srcBLen, q15_t *pDst);
#else
#define pq_arm_correlate_q15 arm_correlate_q15
#endif

#if defined(CONFIG_PQ_ARM_MAT_INIT_F32) && CONFIG_PQ_ARM_MAT_INIT_F32
void pq_arm_mat_init_f32(arm_matrix_instance_f32 *S, uint16_t nRows, uint16_t nColumns, float32_t *pData);
#else
#define pq_arm_mat_init_f32 arm_mat_init_f32
#endif

#if defined(CONFIG_PQ_ARM_MAT_INIT_Q31) && CONFIG_PQ_ARM_MAT_INIT_Q31
void pq_arm_mat_init_q31(arm_matrix_instance_q31 *S, uint16_t nRows, uint16_t nColumns, q31_t *pData);
#else
#define pq_arm_mat_init_q31 arm_mat_init_q31
#endif

#if defined(CONFIG_PQ_ARM_MAT_INIT_Q15) && CONFIG_PQ_ARM_MAT_INIT_Q15
void pq_arm_mat_init_q15(arm_matrix_instance_q15 *S, uint16_t nRows, uint16_t nColumns, q15_t *pData);
#else
#define pq_arm_mat_init_q15 arm_mat_init_q15
#endif

#if defined(CONFIG_PQ_ARM_MAT_ADD_F32) && CONFIG_PQ_ARM_MAT_ADD_F32
arm_status pq_arm_mat_add_f32(const arm_matrix_instance_f32 *pSrcA,
                           const arm_matrix_instance_f32 *pSrcB,
                           arm_matrix_instance_f32 *pDst);
#else
#define pq_arm_mat_add_f32 arm_mat_add_f32
#endif

#if defined(CONFIG_PQ_ARM_MAT_ADD_Q31) && CONFIG_PQ_ARM_MAT_ADD_Q31
arm_status pq_arm_mat_add_q31(const arm_matrix_instance_q31 *pSrcA,
                           const arm_matrix_instance_q31 *pSrcB,
                           arm_matrix_instance_q31 *pDst);
#else
#define pq_arm_mat_add_q31 arm_mat_add_q31
#endif

#if defined(CONFIG_PQ_ARM_MAT_ADD_Q15) && CONFIG_PQ_ARM_MAT_ADD_Q15
arm_status pq_arm_mat_add_q15(const arm_matrix_instance_q15 *pSrcA,
                           const arm_matrix_instance_q15 *pSrcB,
                           arm_matrix_instance_q15 *pDst);
#else
#define pq_arm_mat_add_q15 arm_mat_add_q15
#endif

#if defined(CONFIG_PQ_ARM_MAT_SUB_F32) && CONFIG_PQ_ARM_MAT_SUB_F32
arm_status pq_arm_mat_sub_f32(const arm_matrix_instance_f32 *pSrcA,
                           const arm_matrix_instance_f32 *pSrcB,
                           arm_matrix_instance_f32 *pDst);
#else
#define pq_arm_mat_sub_f32 arm_mat_sub_f32
#endif

#if defined(CONFIG_PQ_ARM_MAT_SUB_Q31) && CONFIG_PQ_ARM_MAT_SUB_Q31
arm_status pq_arm_mat_sub_q31(const arm_matrix_instance_q31 *pSrcA,
                           const arm_matrix_instance_q31 *pSrcB,
                           arm_matrix_instance_q31 *pDst);
#else
#define pq_arm_mat_sub_q31 arm_mat_sub_q31
#endif

#if defined(CONFIG_PQ_ARM_MAT_SUB_Q15) && CONFIG_PQ_ARM_MAT_SUB_Q15
arm_status pq_arm_mat_sub_q15(const arm_matrix_instance_q15 *pSrcA,
                           const arm_matrix_instance_q15 *pSrcB,
                           arm_matrix_instance_q15 *pDst);
#else
#define pq_arm_mat_sub_q15 arm_mat_sub_q15
#endif

#if defined(CONFIG_PQ_ARM_MAT_MULT_F32) && CONFIG_PQ_ARM_MAT_MULT_F32
arm_status pq_arm_mat_mult_f32(const arm_matrix_instance_f32 *pSrcA,
                            const arm_matrix_instance_f32 *pSrcB,
                            arm_matrix_instance_f32 *pDst);
#else
#define pq_arm_mat_mult_f32 arm_mat_mult_f32
#endif

#if defined(CONFIG_PQ_ARM_MAT_MULT_Q31) && CONFIG_PQ_ARM_MAT_MULT_Q31
arm_status pq_arm_mat_mult_q31(const arm_matrix_instance_q31 *pSrcA,
                            const arm_matrix_instance_q31 *pSrcB,
                            arm_matrix_instance_q31 *pDst);
#else
#define pq_arm_mat_mult_q31 arm_mat_mult_q31
#endif

#if defined(CONFIG_PQ_ARM_MAT_MULT_Q15) && CONFIG_PQ_ARM_MAT_MULT_Q15
arm_status pq_arm_mat_mult_q15(const arm_matrix_instance_q15 *pSrcA,
                            const arm_matrix_instance_q15 *pSrcB,
                            arm_matrix_instance_q15 *pDst,
                            q15_t *pState);
#else
#define pq_arm_mat_mult_q15 arm_mat_mult_q15
#endif

#if defined(CONFIG_PQ_ARM_MAT_INVERSE_F32) && CONFIG_PQ_ARM_MAT_INVERSE_F32
arm_status pq_arm_mat_inverse_f32(const arm_matrix_instance_f32 *src, arm_matrix_instance_f32 *dst);
#else
#define pq_arm_mat_inverse_f32 arm_mat_inverse_f32
#endif

#if defined(CONFIG_PQ_ARM_MAT_TRANS_F32) && CONFIG_PQ_ARM_MAT_TRANS_F32
arm_status pq_arm_mat_trans_f32(const arm_matrix_instance_f32 *pSrc, arm_matrix_instance_f32 *pDst);
#else
#define pq_arm_mat_trans_f32 arm_mat_trans_f32
#endif

#if defined(CONFIG_PQ_ARM_MAT_TRANS_Q31) && CONFIG_PQ_ARM_MAT_TRANS_Q31
arm_status pq_arm_mat_trans_q31(const arm_matrix_instance_q31 *pSrc, arm_matrix_instance_q31 *pDst);
#else
#define pq_arm_mat_trans_q31 arm_mat_trans_q31
#endif

#if defined(CONFIG_PQ_ARM_MAT_TRANS_Q15) && CONFIG_PQ_ARM_MAT_TRANS_Q15
arm_status pq_arm_mat_trans_q15(const arm_matrix_instance_q15 *pSrc, arm_matrix_instance_q15 *pDst);
#else
#define pq_arm_mat_trans_q15 arm_mat_trans_q15
#endif

#if defined(CONFIG_PQ_ARM_MAT_SCALE_F32) && CONFIG_PQ_ARM_MAT_SCALE_F32
arm_status pq_arm_mat_scale_f32(const arm_matrix_instance_f32 *pSrc, float32_t scale, arm_matrix_instance_f32 *pDst);
#else
#define pq_arm_mat_scale_f32 arm_mat_scale_f32
#endif

#if defined(CONFIG_PQ_ARM_MAT_SCALE_Q31) && CONFIG_PQ_ARM_MAT_SCALE_Q31
arm_status pq_arm_mat_scale_q31(const arm_matrix_instance_q31 *pSrc,
                             q31_t scaleFract,
                             int32_t shift,
                             arm_matrix_instance_q31 *pDst);
#else
#define pq_arm_mat_scale_q31 arm_mat_scale_q31
#endif

#if defined(CONFIG_PQ_ARM_MAT_SCALE_Q15) && CONFIG_PQ_ARM_MAT_SCALE_Q15
arm_status pq_arm_mat_scale_q15(const arm_matrix_instance_q15 *pSrc,
                             q15_t scaleFract,
                             int32_t shift,
                             arm_matrix_instance_q15 *pDst);
#else
#define pq_arm_mat_scale_q15 arm_mat_scale_q15
#endif

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @}*/

#endif /* FSL_POWERQUAD_CMSIS_H_ */
