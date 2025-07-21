/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_mau.h"
#if defined(CONFIG_MAU_ENABLE_CMSIS_DSP_API) && CONFIG_MAU_ENABLE_CMSIS_DSP_API
#include "arm_math.h"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static uint32_t MAU_GetInstance(MAU_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to MAU bases for each instance. */
static MAU_Type *const s_mauBases[] = MAU_BASE_PTRS;
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to MAU clocks for each instance. */
static const clock_ip_name_t s_mauClocks[] = MAU_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
#if defined(MAU_RSTS)
/* Reset array */
static const reset_ip_name_t s_mauResets[] = MAU_RSTS;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
void MAU_Init(MAU_Type *base, mau_config_t *config)
{
    uint32_t enable_interrupt = 0;
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock for MAU instance. */
    (void)CLOCK_EnableClock(s_mauClocks[MAU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(MAU_RSTS)
    RESET_ReleasePeripheralReset(s_mauResets[MAU_GetInstance(base)]);
#endif
    if (config->enableRes0Interrupt)
    {
        enable_interrupt |= MAU_RES_STATUS_IE_RES0_IE_MASK;
    }
    if (config->enableRes1Interrupt)
    {
        enable_interrupt |= MAU_RES_STATUS_IE_RES1_IE_MASK;
    }
    if (config->enableRes2Interrupt)
    {
        enable_interrupt |= MAU_RES_STATUS_IE_RES2_IE_MASK;
    }
    if (config->enableRes3Interrupt)
    {
        enable_interrupt |= MAU_RES_STATUS_IE_RES3_IE_MASK;
    }

    base->RES_STATUS_IE = enable_interrupt;
}
void MAU_Deinit(MAU_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Gate the clock. */
    (void)CLOCK_DisableClock(s_mauClocks[MAU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

static uint32_t MAU_GetInstance(MAU_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    /*
     * $Branch Coverage Justification$
     * (instance >= ARRAY_SIZE(s_mauBases)) not covered. The peripheral base
     * address is always valid and checked by assert.
     */
    for (instance = 0; instance < ARRAY_SIZE(s_mauBases); instance++)
    {
        /*
         * $Branch Coverage Justification$
         * (s_mauBases[instance] != base) not covered. The peripheral base
         * address is always valid and checked by assert.
         */
        if (MSDK_REG_SECURE_ADDR(s_mauBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_mauBases));

    return instance;
}

#if defined(CONFIG_MAU_ENABLE_CMSIS_DSP_API) && CONFIG_MAU_ENABLE_CMSIS_DSP_API

#if defined(CONFIG_MAU_ENABLE_CMSIS_DSP_ARM_SQRT_F32_API) && CONFIG_MAU_ENABLE_CMSIS_DSP_ARM_SQRT_F32_API
/*!
 * brief Calculates square root of a floating-point number.
 *
 * param input Input floating-point value, must be non-negative.
 * param output Pointer to store the square root result.
 * return Returns ARM_MATH_SUCCESS for success.
 */
arm_status arm_sqrt_f32(float input, float *output)
{
    assert(input >= 0);
    float result = 0;
    result       = MAU_SqrtFloat(MAU0, input, kMAU_RES0);
    *output      = result;
    return ARM_MATH_SUCCESS;
}
#endif

/*!
 * brief Calculates square root of a Q31 fixed-point number.
 *
 * param input Input Q31 value, must be non-negative.
 * param output Pointer to store the square root result.
 * return Returns ARM_MATH_SUCCESS for successful operation.
 */
arm_status arm_sqrt_q31(mau_q31_t input, mau_q31_t *output)
{
    assert(input >= 0);
    mau_q31_t result = 0;
    result           = MAU_SqrtQ31(MAU0, input, kMAU_RES0);
    *output          = result;
    return ARM_MATH_SUCCESS;
}

/*!
 * brief Calculates square root of a Q15 fixed-point number.
 *
 * param input Input Q15 value, must be non-negative.
 * param output Pointer to store the square root result.
 * return Returns ARM_MATH_SUCCESS for successful operation.
 */
arm_status arm_sqrt_q15(mau_q15_t input, mau_q15_t *output)
{
    assert(input >= 0);
    mau_q31_t result = 0;
    result           = MAU_SqrtQ15(MAU0, input, kMAU_RES0);
    *output          = result;
    return ARM_MATH_SUCCESS;
}

/*!
 * brief Calculates sine of a floating-point number.
 *
 * param input Input floating-point value in radians.
 * return Returns the sine result as float in the range [-1,1].
 */
float arm_sin_f32(float input)
{
    return MAU_SinPIXFloat(MAU0, input / MAU_MATH_PI, kMAU_RES0);
}

/*!
 * brief Calculates sine of a Q31 fixed-point number.
 *
 * param input Input Q31 value in radians.
 * return Returns the sine result as Q31 in the range [-1,1].
 */
mau_q31_t arm_sin_q31(mau_q31_t input)
{
    return MAU_SinPIXQ31(MAU0, (input * 2), kMAU_RES0);
}

/*!
 * brief Calculates sine of a Q15 fixed-point number.
 *
 * param input Input Q15 value in radians.
 * return Returns the sine result as Q15 in the range [-1,1].
 */
mau_q15_t arm_sin_q15(mau_q15_t input)
{
    return MAU_SinPIXQ15(MAU0, (input * 2), kMAU_RES0);
}

/*!
 * brief Calculates cosine of a floating-point number.
 *
 * param input Input floating-point value in radians.
 * return Returns the cosine result as float in the range [-1,1].
 */
float arm_cos_f32(float input)
{
    return MAU_CosPIXFloat(MAU0, input / MAU_MATH_PI, kMAU_RES0);
}

/*!
 * brief Calculates cosine of a Q31 fixed-point number.
 *
 * param input Input Q31 value in radians.
 * return Returns the cosine result as Q31 in the range [-1,1].
 */
mau_q31_t arm_cos_q31(mau_q31_t input)
{
    return MAU_CosPIXQ31(MAU0, (input * 2), kMAU_RES0);
}

/*!
 * brief Calculates cosine of a Q15 fixed-point number.
 *
 * param input Input Q15 value in radians.
 * return Returns the cosine result as Q15 in the range [-1,1].
 */
mau_q15_t arm_cos_q15(mau_q15_t input)
{
    return MAU_CosPIXQ15(MAU0, (input * 2), kMAU_RES0);
}

/*!
 * brief Calculates sine and cosine of a floating-point number simultaneously.
 *
 * param input Input floating-point value in radians.
 * param sin_val Pointer to store the sine result in the range [-1,1].
 * param cos_val Pointer to store the cosine result in the range [-1,1].
 */
void arm_sin_cos_f32(float input, float *sin_val, float *cos_val)
{
    MAU_SinCosPIXFloat(MAU0, input / MAU_MATH_PI, sin_val, cos_val, kMAU_RES0, kMAU_RES1);
}

/*!
 * brief Calculates sine and cosine of a Q31 fixed-point number simultaneously.
 *
 * param input Input Q31 value in radians.
 * param sin_val Pointer to store the sine result in the range [-1,1].
 * param cos_val Pointer to store the cosine result in the range [-1,1].
 */
void arm_sin_cos_q31(mau_q31_t input, mau_q31_t *sin_val, mau_q31_t *cos_val)
{
    MAU_SinCosPIXQ31(MAU0, (input * 2), sin_val, cos_val, kMAU_RES0, kMAU_RES1);
}

/*!
 * brief Calculates sine and cosine of a Q15 fixed-point number simultaneously.
 *
 * param input Input Q15 value in radians.
 * param sin_val Pointer to store the sine result in the range [-1,1].
 * param cos_val Pointer to store the cosine result in the range [-1,1].
 */
void arm_sin_cos_q15(mau_q15_t input, mau_q15_t *sin_val, mau_q15_t *cos_val)
{
    MAU_SinCosPIXQ15(MAU0, (input * 2), sin_val, cos_val, kMAU_RES0, kMAU_RES1);
}
#endif
