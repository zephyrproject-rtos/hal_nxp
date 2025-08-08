/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_MAU_H_
#define FSL_MAU_H_

#include "fsl_common.h"

/*!
 * @addtogroup mau
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */

/*! @brief MAU driver version. */
#define FSL_MAU_DRIVER_VERSION (MAKE_VERSION(2, 2, 0))
/*! @} */

/*! @brief MAU Q15 type. */
typedef int16_t mau_q15_t;
/*! @brief MAU Q31 type. */
typedef int32_t mau_q31_t;

/*! @brief MAU data type. */
typedef enum _mau_data_type
{
    kMAU_DT_UINT  = 0,
    kMAU_DT_INT   = 1,
    kMAU_DT_Q1X   = 2,
    kMAU_DT_FLOAT = 3
} mau_data_type_t;

/*! @brief MAU result register. */
typedef enum _mau_result
{
    kMAU_RES0 = 0,
    kMAU_RES1 = 1,
    kMAU_RES2 = 2,
    kMAU_RES3 = 3
} mau_result_t;

/*! @brief MAU calculation code. */
typedef enum _mau_mopc
{
    kMAU_MOPC_BYPASS     = (0U),
    kMAU_MOPC_RECIP      = (1U),
    kMAU_MOPC_SQRT       = (2U),
    kMAU_MOPC_SQRT_RECIP = (3U),
    kMAU_MOPC_COS        = (8U),
    kMAU_MOPC_SIN        = (9U),
    kMAU_MOPC_ATAN       = (12U)
} mau_mopc_t;

/*! @brief MAU result register status flag. */
typedef enum _mau_flags
{
    kMAU_FLAG_NX   = MAU_RES_STATUS_RES0_NX_MASK,
    kMAU_FLAG_UF   = MAU_RES_STATUS_RES0_UF_MASK,
    kMAU_FLAG_OF   = MAU_RES_STATUS_RES0_OF_MASK,
    kMAU_FLAG_DZ   = MAU_RES_STATUS_RES0_DZ_MASK,
    kMAU_FLAG_NV   = MAU_RES_STATUS_RES0_NV_MASK,
    kMAU_FLAG_ERR  = MAU_RES_STATUS_RES0_ERR_MASK,
    kMAU_FLAG_OVWR = MAU_RES_STATUS_RES0_OVWR_MASK,
    kMAU_FLAG_FULL = MAU_RES_STATUS_RES0_FULL_MASK,
} mau_flags_t;

/*! @brief MAU configuration structure. */
typedef struct _mau_config
{
    bool enableRes0Interrupt; /*!< Enable RES0 interrupt. */
    bool enableRes1Interrupt; /*!< Enable RES1 interrupt. */
    bool enableRes2Interrupt; /*!< Enable RES2 interrupt. */
    bool enableRes3Interrupt; /*!< Enable RES3 interrupt. */
} mau_config_t;

#define MAU_MATH_PI        (3.1415926535898f)
#define MAU_DT_SET(dt)     ((dt) << 9U)
#define MAU_RES_SET(res)   ((res) << 7U)
#define MAU_MOPC_SET(mopc) ((mopc) << 2U)

#if defined(FSL_FEATURE_MAU_INDIRECT_IS_LOW_ADDR) && (FSL_FEATURE_MAU_INDIRECT_IS_LOW_ADDR == 1U)
#define MAU_INDIRECT_ADDR(base, dt, ds, mopc) ((base) | MAU_DT_SET(dt) | MAU_RES_SET(ds) | MAU_MOPC_SET(mopc))
#else
#define MAU_INDIRECT_ADDR(base, dt, ds, mopc) ((base) | 0x800U | MAU_DT_SET(dt) | MAU_RES_SET(ds) | MAU_MOPC_SET(mopc))
#endif

#define MAU_REG_UINT32(addr) (*((volatile uint32_t *)(addr)))
#define MAU_REG_Q15(addr)    (*((volatile mau_q15_t *)(addr)))
#define MAU_REG_Q31(addr)    (*((volatile mau_q31_t *)(addr)))
#define MAU_REG_FLOAT(addr)  (*((volatile float *)(addr)))

/*! @brief Enable the MAU CMSIS DSP function. */
#ifndef CONFIG_MAU_ENABLE_CMSIS_DSP_API
#define CONFIG_MAU_ENABLE_CMSIS_DSP_API (0)
#endif

/*! @brief Enable the MAU arm_sqrt_f32 function. */
#ifndef CONFIG_MAU_ENABLE_CMSIS_DSP_ARM_SQRT_F32_API
#define CONFIG_MAU_ENABLE_CMSIS_DSP_ARM_SQRT_F32_API (0)
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @name Initialization
 * @{
 */

/**
 * @brief Gets the default configuration structure.
 *
 * This function initializes the MAU configuration structure to a default value.
 */
static inline __attribute__((always_inline)) void MAU_GetDefaultConfig(mau_config_t *config)
{
    config->enableRes0Interrupt = false;
    config->enableRes1Interrupt = false;
    config->enableRes2Interrupt = false;
    config->enableRes3Interrupt = false;
}

/**
 * @brief Initializes MAU instance with the user configuration structure
 *
 * @param base MAU peripheral base address.
 * @param config Pointer to a user-defined configuration structure.
 */
void MAU_Init(MAU_Type *base, mau_config_t *config);

/**
 * @brief Deinitializes MAU instance.
 *
 * @param base MAU peripheral base address.
 */
void MAU_Deinit(MAU_Type *base);

/*! @} */

/*!
 * @name Status
 * @{
 */

/**
 * @brief Gets the result register status flag.
 *
 * @param base MAU peripheral base address.
 * @param res MAU result register. see #mau_result_t.
 * @return uint32_t MAU result register flags, see #mau_flags_t.
 */
static inline __attribute__((always_inline)) uint32_t MAU_GetResStatusFlags(MAU_Type *base, mau_result_t res)
{
    return (base->RES_STATUS >> (8 << (uint8_t)(res))) & 0xFF;
}

/**
 * @brief Clears the result register status flag.
 *
 * @param base MAU peripheral base address.
 * @param res MAU result register. see #mau_result_t.
 * @param mask MAU result register flag mask, see #mau_flags_t.
 */
static inline __attribute__((always_inline)) void MAU_ClearResStatusFlags(MAU_Type *base,
                                                                          mau_result_t res,
                                                                          uint32_t mask)
{
    /* Write 0 to clear the flag */
    base->RES_STATUS &= ~((mask & 0xFF) << (8 << (uint8_t)(res)));
}

/*! @} */

/*!
 * @name UInt32 Calculation
 * @{
 */

/**
 * @brief Calculate the square root for uint32
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return uint32_t
 */
static inline __attribute__((always_inline)) uint32_t MAU_SqrtUint32(MAU_Type *base, uint32_t input, mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_UINT, res, kMAU_MOPC_SQRT);
    MAU_REG_UINT32(addr)   = input;
    return MAU_REG_UINT32((uint32_t)(&MAU0->RES0) + (res << 2));
}

/*! @} */

/*!
 * @name Float Calculation
 * @{
 */

/**
 * @brief Calculate the reciprocal for float
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return float
 */
static inline __attribute__((always_inline)) float MAU_RecipFloat(MAU_Type *base, float input, mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_FLOAT, res, kMAU_MOPC_RECIP);
    MAU_REG_FLOAT(addr)    = input;
    return MAU_REG_FLOAT((uint32_t)(&MAU0->RES0) + (res << 2));
}

/**
 * @brief Calculate the square root for float
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return float
 */
static inline __attribute__((always_inline)) float MAU_SqrtFloat(MAU_Type *base, float input, mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_FLOAT, res, kMAU_MOPC_SQRT);
    MAU_REG_FLOAT(addr)    = input;
    return MAU_REG_FLOAT((uint32_t)(&MAU0->RES0) + (res << 2));
}

/**
 * @brief Calculate the reciprocal square root for float
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return float
 */
static inline __attribute__((always_inline)) float MAU_SqrtRecipFloat(MAU_Type *base, float input, mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_FLOAT, res, kMAU_MOPC_SQRT_RECIP);
    MAU_REG_FLOAT(addr)    = input;
    return MAU_REG_FLOAT((uint32_t)(&MAU0->RES0) + (res << 2));
}

/**
 * @brief Calculate the sine(PI*X) for float
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return float
 */
static inline __attribute__((always_inline)) float MAU_SinPIXFloat(MAU_Type *base, float input, mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_FLOAT, res, kMAU_MOPC_SIN);
    MAU_REG_FLOAT(addr)    = input;
    return MAU_REG_FLOAT((uint32_t)(&MAU0->RES0) + (res << 2));
}

/**
 * @brief Calculate the cosine(PI*X) for float
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return float
 */
static inline __attribute__((always_inline)) float MAU_CosPIXFloat(MAU_Type *base, float input, mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_FLOAT, res, kMAU_MOPC_COS);
    MAU_REG_FLOAT(addr)    = input;
    return MAU_REG_FLOAT((uint32_t)(&MAU0->RES0) + (res << 2));
}

/**
 * @brief Calculate the sine(PI*X) and cosine(PI*X) for float
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param pSin Points to the block of sine output data
 * @param pCos Points to the block of cosine output data
 * @param sin_res MAU result register for sine. see #mau_result_t.
 * @param cos_res MAU result register for cosine. see #mau_result_t.
 */
static inline __attribute__((always_inline)) void MAU_SinCosPIXFloat(
    MAU_Type *base, float input, float *pSin, float *pCos, mau_result_t sin_res, mau_result_t cos_res)
{
    uint32_t sin_addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_FLOAT, sin_res, kMAU_MOPC_SIN);
    uint32_t cos_addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_FLOAT, cos_res, kMAU_MOPC_COS);
    float input_value = input;

    MAU_REG_FLOAT(sin_addr) = input_value;
    MAU_REG_FLOAT(cos_addr) = input_value;
    *pSin                   = MAU_REG_FLOAT((uint32_t)(&MAU0->RES0) + (sin_res << 2));
    *pCos                   = MAU_REG_FLOAT((uint32_t)(&MAU0->RES0) + (cos_res << 2));
}

/**
 * @brief Calculate the arctangent(X)/PI for float
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return float
 */
static inline __attribute__((always_inline)) float MAU_AtanXDivPIFloat(MAU_Type *base, float input, mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_FLOAT, res, kMAU_MOPC_ATAN);
    MAU_REG_FLOAT(addr)    = input;
    return MAU_REG_FLOAT((uint32_t)(&MAU0->RES0) + (res << 2));
}

/*! @} */

/*!
 * @name Q31 Calculation
 * @{
 */

/**
 * @brief Calculate the reciprocal for Q31
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return mau_q31_t
 */
static inline __attribute__((always_inline)) mau_q31_t MAU_RecipQ31(MAU_Type *base, mau_q31_t input, mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_Q1X, res, kMAU_MOPC_RECIP);
    MAU_REG_Q31(addr)      = input;
    return MAU_REG_Q31((uint32_t)(&MAU0->RES0) + (res << 2));
}

/**
 * @brief Calculate the square root for Q31
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return mau_q31_t
 */
static inline __attribute__((always_inline)) mau_q31_t MAU_SqrtQ31(MAU_Type *base, mau_q31_t input, mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_Q1X, res, kMAU_MOPC_SQRT);
    MAU_REG_Q31(addr)      = input;
    return MAU_REG_Q31((uint32_t)(&MAU0->RES0) + (res << 2));
}

/**
 * @brief Calculate the reciprocal square root for Q31
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return mau_q31_t
 */
static inline __attribute__((always_inline)) mau_q31_t MAU_SqrtRecipQ31(MAU_Type *base,
                                                                        mau_q31_t input,
                                                                        mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_Q1X, res, kMAU_MOPC_SQRT_RECIP);
    MAU_REG_Q31(addr)      = input;
    return MAU_REG_Q31((uint32_t)(&MAU0->RES0) + (res << 2));
}

/**
 * @brief Calculate the sine(PI*X) for Q31
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return mau_q31_t
 */
static inline __attribute__((always_inline)) mau_q31_t MAU_SinPIXQ31(MAU_Type *base, mau_q31_t input, mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_Q1X, res, kMAU_MOPC_SIN);
    MAU_REG_Q31(addr)      = input;
    return MAU_REG_Q31((uint32_t)(&MAU0->RES0) + (res << 2));
}

/**
 * @brief Calculate the cosine(PI*X) for Q31
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return mau_q31_t
 */
static inline __attribute__((always_inline)) mau_q31_t MAU_CosPIXQ31(MAU_Type *base, mau_q31_t input, mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_Q1X, res, kMAU_MOPC_COS);
    MAU_REG_Q31(addr)      = input;
    return MAU_REG_Q31((uint32_t)(&MAU0->RES0) + (res << 2));
}

/**
 * @brief Calculate the sine(PI*X) and cosine(PI*X) for Q31
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param pSin Points to the block of sine output data
 * @param pCos Points to the block of cosine output data
 * @param sin_res MAU result register for sine. see #mau_result_t.
 * @param cos_res MAU result register for cosine. see #mau_result_t.
 */
static inline __attribute__((always_inline)) void MAU_SinCosPIXQ31(
    MAU_Type *base, mau_q31_t input, mau_q31_t *pSin, mau_q31_t *pCos, mau_result_t sin_res, mau_result_t cos_res)
{
    uint32_t sin_addr     = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_Q1X, sin_res, kMAU_MOPC_SIN);
    uint32_t cos_addr     = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_Q1X, cos_res, kMAU_MOPC_COS);
    mau_q31_t input_value = input;

    MAU_REG_Q31(sin_addr) = input_value;
    MAU_REG_Q31(cos_addr) = input_value;
    *pSin                 = MAU_REG_Q31((uint32_t)(&MAU0->RES0) + (sin_res << 2));
    *pCos                 = MAU_REG_Q31((uint32_t)(&MAU0->RES0) + (cos_res << 2));
}

/**
 * @brief Calculate the arctangent(X)/PI for Q31
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return mau_q31_t
 */
static inline __attribute__((always_inline)) mau_q31_t MAU_AtanXDivPIQ31(MAU_Type *base,
                                                                         mau_q31_t input,
                                                                         mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_Q1X, res, kMAU_MOPC_ATAN);
    MAU_REG_Q31(addr)      = input;
    return MAU_REG_Q31((uint32_t)(&MAU0->RES0) + (res << 2));
}

/*! @} */

/*!
 * @name Q15 Calculation
 * @{
 */

/**
 * @brief Calculate the reciprocal for Q15
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return mau_q15_t
 */
static inline __attribute__((always_inline)) mau_q15_t MAU_RecipQ15(MAU_Type *base, mau_q15_t input, mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_Q1X, res, kMAU_MOPC_RECIP);
    MAU_REG_Q15(addr)      = input;
    return MAU_REG_Q15((uint32_t)(&MAU0->RES0) + (res << 2));
}

/**
 * @brief Calculate the square root for Q15
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return mau_q15_t
 */
static inline __attribute__((always_inline)) mau_q15_t MAU_SqrtQ15(MAU_Type *base, mau_q15_t input, mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_Q1X, res, kMAU_MOPC_SQRT);
    MAU_REG_Q15(addr)      = input;
    return MAU_REG_Q15((uint32_t)(&MAU0->RES0) + (res << 2));
}

/**
 * @brief Calculate the reciprocal square root for Q15
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return mau_q15_t
 */
static inline __attribute__((always_inline)) mau_q15_t MAU_SqrtRecipQ15(MAU_Type *base,
                                                                        mau_q15_t input,
                                                                        mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_Q1X, res, kMAU_MOPC_SQRT_RECIP);
    MAU_REG_Q15(addr)      = input;
    return MAU_REG_Q15((uint32_t)(&MAU0->RES0) + (res << 2));
}

/**
 * @brief Calculate the sine(PI*X) for Q15
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return mau_q15_t
 */
static inline __attribute__((always_inline)) mau_q15_t MAU_SinPIXQ15(MAU_Type *base, mau_q15_t input, mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_Q1X, res, kMAU_MOPC_SIN);
    MAU_REG_Q15(addr)      = input;
    return MAU_REG_Q15((uint32_t)(&MAU0->RES0) + (res << 2));
}

/**
 * @brief Calculate the cosine(PI*X) for Q15
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return mau_q15_t
 */
static inline __attribute__((always_inline)) mau_q15_t MAU_CosPIXQ15(MAU_Type *base, mau_q15_t input, mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_Q1X, res, kMAU_MOPC_COS);
    MAU_REG_Q15(addr)      = input;
    return MAU_REG_Q15((uint32_t)(&MAU0->RES0) + (res << 2));
}

/**
 * @brief Calculate the sine(PI*X) and cosine(PI*X) for Q15
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param pSin Points to the block of sine output data
 * @param pCos Points to the block of cosine output data
 * @param sin_res MAU result register for sine. see #mau_result_t.
 * @param cos_res MAU result register for cosine. see #mau_result_t.
 */
static inline __attribute__((always_inline)) void MAU_SinCosPIXQ15(
    MAU_Type *base, mau_q15_t input, mau_q15_t *pSin, mau_q15_t *pCos, mau_result_t sin_res, mau_result_t cos_res)
{
    uint32_t sin_addr     = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_Q1X, sin_res, kMAU_MOPC_SIN);
    uint32_t cos_addr     = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_Q1X, cos_res, kMAU_MOPC_COS);
    mau_q15_t input_value = input;

    MAU_REG_Q15(sin_addr) = input_value;
    MAU_REG_Q15(cos_addr) = input_value;
    *pSin                 = MAU_REG_Q15((uint32_t)(&MAU0->RES0) + (sin_res << 2));
    *pCos                 = MAU_REG_Q15((uint32_t)(&MAU0->RES0) + (cos_res << 2));
}

/**
 * @brief Calculate the arctangent(X)/PI for Q15
 *
 * @param base MAU peripheral base address.
 * @param input Input data.
 * @param res MAU result register. see #mau_result_t.
 * @return mau_q15_t
 */
static inline __attribute__((always_inline)) mau_q15_t MAU_AtanXDivPIQ15(MAU_Type *base,
                                                                         mau_q15_t input,
                                                                         mau_result_t res)
{
    register uint32_t addr = MAU_INDIRECT_ADDR((uint32_t)base, kMAU_DT_Q1X, res, kMAU_MOPC_ATAN);
    MAU_REG_Q15(addr)      = input;
    return MAU_REG_Q15((uint32_t)(&MAU0->RES0) + (res << 2));
}

#if defined(CONFIG_MAU_ENABLE_CMSIS_DSP_API) && CONFIG_MAU_ENABLE_CMSIS_DSP_API
/*!
 * @brief Calculates sine and cosine of a floating-point number simultaneously.
 *
 * @param input Input floating-point value in radians.
 * @param sin_val Pointer to store the sine result in the range [-1,1].
 * @param cos_val Pointer to store the cosine result in the range [-1,1].
 */
void arm_sin_cos_f32(float input, float *sin_val, float *cos_val);

/*!
 * @brief Calculates sine and cosine of a Q31 fixed-point number simultaneously.
 *
 * @param input Input Q31 value in radians.
 * @param sin_val Pointer to store the sine result in the range [-1,1].
 * @param cos_val Pointer to store the cosine result in the range [-1,1].
 */
void arm_sin_cos_q31(mau_q31_t input, mau_q31_t *sin_val, mau_q31_t *cos_val);

/*!
 * @brief Calculates sine and cosine of a Q15 fixed-point number simultaneously.
 *
 * @param input Input Q15 value in radians.
 * @param sin_val Pointer to store the sine result in the range [-1,1].
 * @param cos_val Pointer to store the cosine result in the range [-1,1].
 */
void arm_sin_cos_q15(mau_q15_t input, mau_q15_t *sin_val, mau_q15_t *cos_val);

#endif

/*! @} */

#if defined(__cplusplus)
}
#endif
/*!
 * @}
 */
#endif /* FSL_MAU_H_ */
