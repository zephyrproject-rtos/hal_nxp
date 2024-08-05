/** @file wls_QR_algorithm.c
 *
 * @brief This file contains the QR algorithm processing code.
 *
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/************************************************************************
 * DFW code that defines the QR algorithm processing.
 ************************************************************************/

#include <osa.h>
#if CONFIG_WLS_CSI_PROC

// Standard includes.
#include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
#ifdef ARM_DS5
#include <arm_neon.h>
#else
#include <math.h>
// 5 sqrtf, 10 fabsf -> use hardware
#endif

// Specific includes.
#include "wls_QR_algorithm.h"

#define TOL_HH_SIG      1e-8f
#define TOL_QR_STEP     1e-5f
#define TOL_QR_STEP_LOW 1e-3f
#define WILK_IT_MAX     15

// #define DEBUG_OUTPUT

int house_holder_vec(float *x, float *v, float *betaPtr, float *muPtr, int len)
{
    int ii;
    float sigma = 0;
    float mu, xOne, vOne, vOneSqr;
#ifdef ARM_DS5
    float32x2_t sigmaVec, xVecf32;
    sigmaVec = vdup_n_f32(0.0f);
#endif
    xOne = x[0];
    v[0] = 1.0f;
    for (ii = 1; ii < len - 1; ii += 2)
    {
#ifdef ARM_DS5
        xVecf32  = vld1_f32((float32_t const *)(x + ii));
        sigmaVec = vmla_f32(sigmaVec, xVecf32, xVecf32);
        vst1_f32((float32_t *)(v + ii), xVecf32);
#else
        sigma += x[ii] * x[ii];
        sigma += x[ii + 1] * x[ii + 1];
        v[ii]     = x[ii];
        v[ii + 1] = x[ii + 1];
#endif
    }
#ifdef ARM_DS5
    sigmaVec = vpadd_f32(sigmaVec, sigmaVec);
    sigma    = vget_lane_f32(sigmaVec, 0);
#endif
    if (ii < len)
    {
        sigma += x[ii] * x[ii];
        v[ii] = x[ii];
    }
    if (sigma < TOL_HH_SIG)
    {
        *muPtr   = xOne;
        *betaPtr = 0;
        return 1;
    }

    mu = SQRTF(xOne * xOne + sigma);
    if (xOne <= 0)
    {
        vOne = xOne - mu;
    }
    else
    {
        vOne = -sigma / (xOne + mu);
    }
    vOneSqr  = vOne * vOne;
    *betaPtr = 2 * vOneSqr / (sigma + vOneSqr);
    *muPtr   = mu;
    for (ii = 1; ii < len; ii++)
    {
        v[ii] = v[ii] / vOne;
    }

    return 0;
}

int givens_rot(float a, float b, float *cosPtr, float *lenPtr)
{
    float r, temp, tempInv;

    if (b == 0)
    {
        cosPtr[0] = 1;
        cosPtr[1] = 0;
        return 1;
    }
    if (FABSF(b) > FABSF(a))
    {
        r         = -a / b;
        temp      = SQRTF(1 + r * r);
        tempInv   = 1 / temp;
        cosPtr[1] = tempInv;
        cosPtr[0] = tempInv * r;
        *lenPtr   = -b * temp;
    }
    else
    {
        r       = -b / a;
        temp    = SQRTF(1 + r * r);
        tempInv = 1 / temp;

        cosPtr[0] = tempInv;
        cosPtr[1] = tempInv * r;
        *lenPtr   = a * temp;
    }

    return 0;
}

int QR_step_Wilkinson(float *diagA, float *offDiagA, float *Qmat, int matSizeN, int kk)
{
#ifdef ARM_DS5
    int ii, jj;
    float a, b, c, d;
    float bSqr, dSqr;
    float mu, temp;
    float x, z;
    float lenVal, cosArray[2];
    float offDiagA2 = 0;
    float *ldPtr;

    float32x2_t cosVec, cosVec2, diagAVec, offDiagAVec;
    float32x2_t tempVec1, tempVec2, tempVec3;
    float32x2_t colVec0, colVec1, resVec0, resVec1;
    float32x2x2_t trnVec;

    a = diagA[kk - 1]; // second last diagonal
    b = offDiagA[kk];
    c = diagA[kk];     // last diagonal
    d = (a - c) / 2;

    bSqr = b * b;
    dSqr = d * d;
    temp = SQRTF(dSqr + bSqr);
    temp = (d > 0) ? (d + temp) : (d - temp);
    mu   = c - bSqr / temp;

    // first iteration
    x = diagA[0] - mu;
    z = offDiagA[1];

    givens_rot(x, z, &cosArray[0], &lenVal);

    cosVec = vld1_f32((float32_t const *)cosArray); // VLD1.32 {d0}, [r0]

    tempVec3 = vrev64_f32(cosVec);                  // VREV64.32 d0,d0
    tempVec3 = vneg_f32(tempVec3);
    trnVec   = vtrn_f32(tempVec3, cosVec);          // VTRN.32 d0,d0
    cosVec2  = trnVec.val[0];

    diagAVec    = vld1_f32((float32_t const *)diagA);
    offDiagAVec = vld1_f32((float32_t const *)(offDiagA + 1));

    tempVec1 = vmul_lane_f32(cosVec, diagAVec, 0);
    tempVec1 = vmla_lane_f32(tempVec1, cosVec2, offDiagAVec, 0);

    tempVec2 = vmul_lane_f32(cosVec, offDiagAVec, 0);
    tempVec2 = vmla_lane_f32(tempVec2, cosVec2, diagAVec, 1);

    resVec0 = vmul_f32(tempVec1, cosVec);
    resVec0 = vmla_f32(resVec0, tempVec2, cosVec2);

    tempVec3 = vmul_lane_f32(cosVec2, offDiagAVec, 1);

    vst1_f32((float32_t *)diagA, resVec0);

    resVec1 = vmul_lane_f32(tempVec1, cosVec, 1);
    resVec1 = vmla_lane_f32(resVec1, tempVec2, cosVec, 0);

    offDiagA[1] = vget_lane_f32(resVec1, 0);

    // update first two rows of Q
    ldPtr = Qmat;
    for (jj = 0; jj < matSizeN; jj += 2)
    {
        colVec0 = vld1_f32((float32_t const *)ldPtr);
        colVec1 = vld1_f32((float32_t const *)(ldPtr + MAX_MAT_SIZE));

        resVec0 = vmul_lane_f32(colVec0, cosVec, 0);
        resVec1 = vmul_lane_f32(colVec1, cosVec, 0);

        resVec0 = vmls_lane_f32(resVec0, colVec1, cosVec, 1);
        resVec1 = vmla_lane_f32(resVec1, colVec0, cosVec, 1);

        vst1_f32((float32_t *)ldPtr, resVec0); // VST1.32 {d0}, [r0]
        vst1_f32((float32_t *)(ldPtr + MAX_MAT_SIZE), resVec1);
        ldPtr += 2;
    }

    if (kk > 1)
    {
        offDiagA[2] = vget_lane_f32(tempVec3, 1); // VMOV.32 r0, d0[0]
        offDiagA2   = vget_lane_f32(tempVec3, 0);

        for (ii = 2; ii < kk; ii++)
        {
            x = offDiagA[ii - 1];
            z = offDiagA2;
            givens_rot(x, z, &cosArray[0], offDiagA + (ii - 1));
            // offDiagA[ii-1] = lenVal;
            cosVec = vld1_f32((float32_t const *)cosArray); // VLD1.32 {d0}, [r0]

            tempVec3 = vrev64_f32(cosVec);                  // VREV64.32 d0,d0
            tempVec3 = vneg_f32(tempVec3);
            trnVec   = vtrn_f32(tempVec3, cosVec);          // VTRN.32 d0,d0
            cosVec2  = trnVec.val[0];

            diagAVec    = vld1_f32((float32_t const *)(diagA + ii - 1));
            offDiagAVec = vld1_f32((float32_t const *)(offDiagA + ii));

            tempVec1 = vmul_lane_f32(cosVec, diagAVec, 0);
            tempVec1 = vmla_lane_f32(tempVec1, cosVec2, offDiagAVec, 0);

            tempVec2 = vmul_lane_f32(cosVec, offDiagAVec, 0);
            tempVec2 = vmla_lane_f32(tempVec2, cosVec2, diagAVec, 1);

            resVec0 = vmul_f32(tempVec1, cosVec);
            resVec0 = vmla_f32(resVec0, tempVec2, cosVec2);

            tempVec3 = vmul_lane_f32(cosVec2, offDiagAVec, 1);

            vst1_f32((float32_t *)(diagA + ii - 1), resVec0);

            resVec1 = vmul_lane_f32(tempVec1, cosVec, 1);
            resVec1 = vmla_lane_f32(resVec1, tempVec2, cosVec, 0);

            offDiagA[ii] = vget_lane_f32(resVec1, 0);

            offDiagA[ii + 1] = vget_lane_f32(tempVec3, 1);
            offDiagA2        = vget_lane_f32(tempVec3, 0);

            // update two rows of Q
            ldPtr = Qmat + (ii - 1) * MAX_MAT_SIZE;
            for (jj = 0; jj < matSizeN; jj += 2)
            {
                colVec0 = vld1_f32((float32_t const *)ldPtr);
                colVec1 = vld1_f32((float32_t const *)(ldPtr + MAX_MAT_SIZE));

                resVec0 = vmul_lane_f32(colVec0, cosVec, 0);
                resVec1 = vmul_lane_f32(colVec1, cosVec, 0);

                resVec0 = vmls_lane_f32(resVec0, colVec1, cosVec, 1);
                resVec1 = vmla_lane_f32(resVec1, colVec0, cosVec, 1);

                vst1_f32((float32_t *)ldPtr, resVec0); // VST1.32 {d0}, [r0]
                vst1_f32((float32_t *)(ldPtr + MAX_MAT_SIZE), resVec1);
                ldPtr += 2;
            }
        }

        // last iteration , ii=kk
        x = offDiagA[kk - 1];
        z = offDiagA2;
        givens_rot(x, z, &cosArray[0], offDiagA + (kk - 1));
        // offDiagA[kk-1] = lenVal;
        cosVec = vld1_f32((float32_t const *)cosArray); // VLD1.32 {d0}, [r0]

        tempVec3 = vrev64_f32(cosVec);                  // VREV64.32 d0,d0
        tempVec3 = vneg_f32(tempVec3);
        trnVec   = vtrn_f32(tempVec3, cosVec);          // VTRN.32 d0,d0
        cosVec2  = trnVec.val[0];

        diagAVec    = vld1_f32((float32_t const *)(diagA + kk - 1));
        offDiagAVec = vld1_f32((float32_t const *)(offDiagA + kk));

        tempVec1 = vmul_lane_f32(cosVec, diagAVec, 0);
        tempVec1 = vmla_lane_f32(tempVec1, cosVec2, offDiagAVec, 0);

        tempVec2 = vmul_lane_f32(cosVec, offDiagAVec, 0);
        tempVec2 = vmla_lane_f32(tempVec2, cosVec2, diagAVec, 1);

        resVec0 = vmul_f32(tempVec1, cosVec);
        resVec0 = vmla_f32(resVec0, tempVec2, cosVec2);

        vst1_f32((float32_t *)(diagA + kk - 1), resVec0);

        resVec1 = vmul_lane_f32(tempVec1, cosVec, 1);
        resVec1 = vmla_lane_f32(resVec1, tempVec2, cosVec, 0);

        offDiagA[kk] = vget_lane_f32(resVec1, 0);

        // update two rows of Q
        ldPtr = Qmat + (kk - 1) * MAX_MAT_SIZE;
        for (jj = 0; jj < matSizeN; jj += 2)
        {
            colVec0 = vld1_f32((float32_t const *)ldPtr);
            colVec1 = vld1_f32((float32_t const *)(ldPtr + MAX_MAT_SIZE));

            resVec0 = vmul_lane_f32(colVec0, cosVec, 0);
            resVec1 = vmul_lane_f32(colVec1, cosVec, 0);

            resVec0 = vmls_lane_f32(resVec0, colVec1, cosVec, 1);
            resVec1 = vmla_lane_f32(resVec1, colVec0, cosVec, 1);

            vst1_f32((float32_t *)ldPtr, resVec0); // VST1.32 {d0}, [r0]
            vst1_f32((float32_t *)(ldPtr + MAX_MAT_SIZE), resVec1);
            ldPtr += 2;
        }
    }

    return 0;
#else
    int ii, jj;
    float a, b, c, d;
    float bSqr, dSqr;
    float mu, temp;
    float x, z;
    float cosVal, sinVal, lenVal;
    float cosArray[2];
    float offDiagA2 = 0;
    float temp11, temp21, temp12, temp22, temp13, temp23;

    a = diagA[kk - 1]; // second last diagonal
    b = offDiagA[kk];
    c = diagA[kk];     // last diagonal
    d = (a - c) / 2;

    bSqr = b * b;
    dSqr = d * d;
    temp = sqrtf(dSqr + bSqr);
    temp = (d > 0) ? (d + temp) : (d - temp);
    mu   = c - bSqr / temp;

    // first iteration
    x = diagA[0] - mu;
    z = offDiagA[1];

    givens_rot(x, z, &cosArray[0], &lenVal);
    cosVal = cosArray[0];
    sinVal = cosArray[1];

    temp11 = cosVal * diagA[0] - sinVal * offDiagA[1];
    temp21 = sinVal * diagA[0] + cosVal * offDiagA[1];

    temp12 = cosVal * offDiagA[1] - sinVal * diagA[1];
    temp22 = sinVal * offDiagA[1] + cosVal * diagA[1];

    temp13 = -sinVal * offDiagA[2];
    temp23 = cosVal * offDiagA[2];

    diagA[0]    = cosVal * temp11 - sinVal * temp12;
    offDiagA[1] = sinVal * temp11 + cosVal * temp12;
    diagA[1]    = sinVal * temp21 + cosVal * temp22;

    // update first two rows of Q
    for (jj = 0; jj < matSizeN; jj++)
    {
        temp11 = Qmat[jj];
        temp21 = Qmat[jj + MAX_MAT_SIZE];

        Qmat[jj]                = cosVal * temp11 - sinVal * temp21;
        Qmat[jj + MAX_MAT_SIZE] = cosVal * temp21 + sinVal * temp11;
    }

    if (kk > 1)
    {
        offDiagA[2] = temp23;
        offDiagA2   = temp13;

        for (ii = 2; ii < kk; ii++)
        {
            x = offDiagA[ii - 1];
            z = offDiagA2;
            givens_rot(x, z, &cosArray[0], &lenVal);
            cosVal = cosArray[0];
            sinVal = cosArray[1];

            temp11 = cosVal * diagA[ii - 1] - sinVal * offDiagA[ii];
            temp21 = sinVal * diagA[ii - 1] + cosVal * offDiagA[ii];

            temp12 = cosVal * offDiagA[ii] - sinVal * diagA[ii];
            temp22 = sinVal * offDiagA[ii] + cosVal * diagA[ii];

            temp13 = -sinVal * offDiagA[ii + 1];
            temp23 = cosVal * offDiagA[ii + 1];

            offDiagA[ii - 1] = lenVal;

            diagA[ii - 1] = cosVal * temp11 - sinVal * temp12;
            offDiagA[ii]  = sinVal * temp11 + cosVal * temp12;
            diagA[ii]     = sinVal * temp21 + cosVal * temp22;

            offDiagA[ii + 1] = temp23;
            offDiagA2        = temp13;
            // update two rows of Q
            for (jj = 0; jj < matSizeN; jj++)
            {
                temp11 = Qmat[jj + (ii - 1) * MAX_MAT_SIZE];
                temp21 = Qmat[jj + ii * MAX_MAT_SIZE];

                Qmat[jj + (ii - 1) * MAX_MAT_SIZE] = cosVal * temp11 - sinVal * temp21;
                Qmat[jj + ii * MAX_MAT_SIZE]       = cosVal * temp21 + sinVal * temp11;
            }
        }

        // last iteration , ii=kk
        x = offDiagA[kk - 1];
        z = offDiagA2;
        givens_rot(x, z, &cosArray[0], &lenVal);
        cosVal = cosArray[0];
        sinVal = cosArray[1];

        temp11 = cosVal * diagA[kk - 1] - sinVal * offDiagA[kk];
        temp21 = sinVal * diagA[kk - 1] + cosVal * offDiagA[kk];

        temp12 = cosVal * offDiagA[kk] - sinVal * diagA[kk];
        temp22 = sinVal * offDiagA[kk] + cosVal * diagA[kk];

        offDiagA[kk - 1] = lenVal;
        diagA[kk - 1]    = cosVal * temp11 - sinVal * temp12;
        offDiagA[kk]     = sinVal * temp11 + cosVal * temp12;
        diagA[kk]        = sinVal * temp21 + cosVal * temp22;
        // update two rows of Q
        for (jj = 0; jj < matSizeN; jj++)
        {
            temp11 = Qmat[jj + (kk - 1) * MAX_MAT_SIZE];
            temp21 = Qmat[jj + kk * MAX_MAT_SIZE];

            Qmat[jj + (kk - 1) * MAX_MAT_SIZE] = cosVal * temp11 - sinVal * temp21;
            Qmat[jj + kk * MAX_MAT_SIZE]       = cosVal * temp21 + sinVal * temp11;
        }
    }

    return 0;
#endif
}

int unsym_QR_step_Wilkinson(float *matA, int matSizeN, int kk, int offset)
{
#ifdef ARM_DS5
    int ii, jj;
    float a, b, c, d;
    float bSqr, dSqr;
    float mu, temp;
    float x, z;
    float lenVal, cosArray[2];
    float *ldPtr;

    float32x2_t cosVec, cosVec2, tempVec3;
    float32x2_t colVec0, colVec1, resVec0, resVec1;
    float32x2x2_t trnVec;

    a = matA[(kk - 1) * (matSizeN + 1)];     // diagA[kk-1]; // second last diagonal
    b = matA[(kk - 1) * (matSizeN + 1) + 1]; // offDiagA[kk];
    c = matA[kk * (matSizeN + 1)];           // diagA[kk]; // last diagonal
    if (kk == 1 + offset)
    {
        float p, q;
        d = matA[kk * (matSizeN + 1) - 1];

        p = -a - c;
        q = a * c - b * d;
        if (p * p < 4 * q)
        {
            matA[offset * (matSizeN + 1)]       = -p / 2;
            matA[offset * (matSizeN + 1) + 1]   = 0;
            matA[(offset + 1) * (matSizeN + 1)] = -p / 2;

            return 1;
        }
    }
    d = (a - c) / 2;

    bSqr = b * b;
    dSqr = d * d;
    temp = SQRTF(dSqr + bSqr);
    temp = (d > 0) ? (d + temp) : (d - temp);
    mu   = c - bSqr / temp;

    // first iteration
    x = matA[offset * (matSizeN + 1)] - mu; // diagA[0]-mu;
    z = matA[offset * (matSizeN + 1) + 1];  // offDiagA[1];

    givens_rot(x, z, &cosArray[0], &lenVal);
    cosVec   = vld1_f32((float32_t const *)cosArray); // VLD1.32 {d0}, [r0]
    tempVec3 = vrev64_f32(cosVec);                    // VREV64.32 d0,d0
    tempVec3 = vneg_f32(tempVec3);
    trnVec   = vtrn_f32(tempVec3, cosVec);            // VTRN.32 d0,d0
    cosVec2  = trnVec.val[0];                         //[-sin cos]

    ldPtr = matA + offset;
    for (jj = offset; jj < matSizeN; jj++)
    { // apply Givens rotation on all columns
        colVec0 = vld1_f32((float32_t const *)ldPtr);
        resVec0 = vmul_lane_f32(cosVec, colVec0, 0);
        resVec0 = vmla_lane_f32(resVec0, cosVec2, colVec0, 1);
        vst1_f32((float32_t *)ldPtr, resVec0);
        ldPtr += matSizeN;
    }

    ldPtr = matA + offset * matSizeN;
    for (jj = offset; jj < kk; jj += 2)
    { // apply Givens rotation on all active rows
        colVec0 = vld1_f32((float32_t const *)ldPtr);
        colVec1 = vld1_f32((float32_t const *)(ldPtr + matSizeN));

        resVec0 = vmul_lane_f32(colVec0, cosVec, 0);
        resVec1 = vmul_lane_f32(colVec1, cosVec, 0);

        resVec0 = vmls_lane_f32(resVec0, colVec1, cosVec, 1);
        resVec1 = vmla_lane_f32(resVec1, colVec0, cosVec, 1);

        vst1_f32((float32_t *)ldPtr, resVec0);
        vst1_f32((float32_t *)(ldPtr + matSizeN), resVec1);
        ldPtr += 2;
    }
    if (jj == kk)
    { // one left
        colVec0 = vld1_f32((float32_t const *)ldPtr);
        colVec1 = vld1_f32((float32_t const *)(ldPtr + matSizeN));

        trnVec          = vtrn_f32(colVec0, colVec1); // VTRN.32 d0,d0
        colVec0         = trnVec.val[0];
        resVec0         = vmul_lane_f32(cosVec, colVec0, 0);
        resVec0         = vmla_lane_f32(resVec0, cosVec2, colVec0, 1);
        ldPtr[0]        = vget_lane_f32(resVec0, 0);
        ldPtr[matSizeN] = vget_lane_f32(resVec0, 1);
    }
    if (kk > 1)
    {
        for (ii = offset + 1; ii < kk; ii++)
        {
            x = matA[(ii - 1) * (matSizeN + 1) + 1];
            z = matA[(ii - 1) * (matSizeN + 1) + 2];
            givens_rot(x, z, &cosArray[0], &lenVal);

            cosVec   = vld1_f32((float32_t const *)cosArray); // VLD1.32 {d0}, [r0]
            tempVec3 = vrev64_f32(cosVec);                    // VREV64.32 d0,d0
            tempVec3 = vneg_f32(tempVec3);
            trnVec   = vtrn_f32(tempVec3, cosVec);            // VTRN.32 d0,d0
            cosVec2  = trnVec.val[0];                         //[-sin cos]

            ldPtr = matA + ii + offset * matSizeN;
            for (jj = offset; jj < matSizeN; jj++)
            { // apply Givens rotation on all columns
                colVec0 = vld1_f32((float32_t const *)ldPtr);
                resVec0 = vmul_lane_f32(cosVec, colVec0, 0);
                resVec0 = vmla_lane_f32(resVec0, cosVec2, colVec0, 1);
                vst1_f32((float32_t *)ldPtr, resVec0);
                ldPtr += matSizeN;
            }
            ldPtr = matA + offset + ii * matSizeN;
            for (jj = offset; jj < kk; jj += 2)
            { // apply Givens rotation on all active rows
                colVec0 = vld1_f32((float32_t const *)ldPtr);
                colVec1 = vld1_f32((float32_t const *)(ldPtr + matSizeN));

                resVec0 = vmul_lane_f32(colVec0, cosVec, 0);
                resVec1 = vmul_lane_f32(colVec1, cosVec, 0);

                resVec0 = vmls_lane_f32(resVec0, colVec1, cosVec, 1);
                resVec1 = vmla_lane_f32(resVec1, colVec0, cosVec, 1);

                vst1_f32((float32_t *)ldPtr, resVec0);
                vst1_f32((float32_t *)(ldPtr + matSizeN), resVec1);
                ldPtr += 2;
            }
            if (jj == kk)
            { // one left
                colVec0 = vld1_f32((float32_t const *)ldPtr);
                colVec1 = vld1_f32((float32_t const *)(ldPtr + matSizeN));

                trnVec          = vtrn_f32(colVec0, colVec1); // VTRN.32 d0,d0
                colVec0         = trnVec.val[0];
                resVec0         = vmul_lane_f32(cosVec, colVec0, 0);
                resVec0         = vmla_lane_f32(resVec0, cosVec2, colVec0, 1);
                ldPtr[0]        = vget_lane_f32(resVec0, 0);
                ldPtr[matSizeN] = vget_lane_f32(resVec0, 1);
            }
        }
    }

    return 0;
#else
    int ii, jj;
    float a, b, c, d;
    float bSqr, dSqr;
    float mu, temp;
    float x, z;
    float cosVal, sinVal, lenVal;
    float cosArray[2];
    float temp11, temp21;

    a = matA[(kk - 1) * (matSizeN + 1)];     // diagA[kk-1]; // second last diagonal
    b = matA[(kk - 1) * (matSizeN + 1) + 1]; // offDiagA[kk];
    c = matA[kk * (matSizeN + 1)];           // diagA[kk]; // last diagonal
    if (kk == 1 + offset)
    {
        float p, q;
        d = matA[kk * (matSizeN + 1) - 1];

        p = -a - c;
        q = a * c - b * d;
        if (p * p < 4 * q)
        {
            matA[offset * (matSizeN + 1)]       = -p / 2;
            matA[offset * (matSizeN + 1) + 1]   = 0;
            matA[(offset + 1) * (matSizeN + 1)] = -p / 2;

            return 1;
        }
    }
    // else{
    d = (a - c) / 2;
    //}

    bSqr = b * b;
    dSqr = d * d;
    temp = sqrtf(dSqr + bSqr);
    temp = (d > 0) ? (d + temp) : (d - temp);
    mu   = c - bSqr / temp;

    // first iteration
    x = matA[offset * (matSizeN + 1)] - mu; // diagA[0]-mu;
    z = matA[offset * (matSizeN + 1) + 1];  // offDiagA[1];

    givens_rot(x, z, &cosArray[0], &lenVal);
    cosVal = cosArray[0];
    sinVal = cosArray[1];

    for (jj = offset; jj < matSizeN; jj++)
    { // apply Givens rotation on all columns
        temp11 = matA[offset + jj * matSizeN];
        temp21 = matA[1 + offset + jj * matSizeN];

        matA[offset + jj * matSizeN]     = cosVal * temp11 - sinVal * temp21;
        matA[1 + offset + jj * matSizeN] = cosVal * temp21 + sinVal * temp11;
    }

    for (jj = offset; jj <= kk; jj++)
    { // apply Givens rotation on all active rows
        temp11 = matA[jj + offset * matSizeN];
        temp21 = matA[jj + (1 + offset) * matSizeN];

        matA[jj + offset * matSizeN]       = cosVal * temp11 - sinVal * temp21;
        matA[jj + (1 + offset) * matSizeN] = cosVal * temp21 + sinVal * temp11;
    }
    if (kk > 1)
    {
        for (ii = offset + 1; ii < kk; ii++)
        {
            x = matA[(ii - 1) * (matSizeN + 1) + 1];
            z = matA[(ii - 1) * (matSizeN + 1) + 2];
            givens_rot(x, z, &cosArray[0], &lenVal);
            cosVal = cosArray[0];
            sinVal = cosArray[1];

            for (jj = offset; jj < matSizeN; jj++)
            { // apply Givens rotation on all columns
                temp11 = matA[ii + jj * matSizeN];
                temp21 = matA[(ii + 1) + jj * matSizeN];

                matA[ii + jj * matSizeN]       = cosVal * temp11 - sinVal * temp21;
                matA[(ii + 1) + jj * matSizeN] = cosVal * temp21 + sinVal * temp11;
            }

            for (jj = offset; jj <= kk; jj++)
            { // apply Givens rotation on all active rows
                temp11 = matA[jj + ii * matSizeN];
                temp21 = matA[jj + (ii + 1) * matSizeN];

                matA[jj + ii * matSizeN]       = cosVal * temp11 - sinVal * temp21;
                matA[jj + (ii + 1) * matSizeN] = cosVal * temp21 + sinVal * temp11;
            }
        }
    }

    return 0;
#endif
}

// back substitution for LS via QR, solves R*X = Q'B = C for X, R is upper tri-angular
// R is NxM, X is MxM, C is NxM
void myBackSub(float *C_MATR, float *R_MATR, float *X_MAT, int matSizeN, int matSizeM)
{
#ifdef DEBUG_OUTPUT
    FILE *fpOut;
#endif
    int ii, jj, kk, row_idx;
    float tempVal;

    for (kk = 0; kk < matSizeM; kk++)
    {
        for (ii = 0; ii < matSizeM; ii++)
        {
            row_idx = matSizeM - 1 - ii;

            tempVal = C_MATR[row_idx + kk * MAX_MAT_SIZE];
            for (jj = matSizeM - ii; jj < matSizeM; jj++)
            {
                tempVal -= R_MATR[row_idx + jj * MAX_MAT_SIZE] * X_MAT[jj + kk * matSizeM];
            }
            X_MAT[row_idx + kk * matSizeM] = tempVal / R_MATR[(MAX_MAT_SIZE + 1) * row_idx];
        }
    }
#ifdef DEBUG_OUTPUT
    fpOut = fopen("Psi_hat_C.txt", "w");
    if (fpOut == NULL)
    {
        fprintf(stderr, "Cannot open output file %s for writing\n", "Psi_hat_C.txt");
        return;
    }

    for (ii = 0; ii < matSizeM * matSizeM; ii++)
    {
        fprintf(fpOut, "%f\n", X_MAT[ii]);
    }
    fclose(fpOut);
#endif
}

// regular QR decomposition
void QR_decomposition(float *inMatArr, float *resD, int matSizeN, int matSizeM)
{
#ifdef ARM_DS5
    int ii, jj, kk, hh_len;
    float *xVec;
    float beta, xNorm;

    float *R_MATR = inMatArr;
    float *Qmat   = resD;                           // Qmat[matSizeN*matSizeN]
    float *vVec   = Qmat + MAX_MAT_SIZE * matSizeN; // vVec[matSizeN]
    float *qVec   = vVec + MAX_MAT_SIZE;            // qVec[matSizeN]
    float *pVec   = qVec + MAX_MAT_SIZE;            // pVec[matSizeM]

    float *ldPtr, *strPtr;

    float32x2_t storeVec, resVec0, resVec1;
    float32x2_t colVec0, colVec1, pVecf32, qVecf32, vVecf32, sumVec;

    storeVec = vdup_n_f32(0.0f); // VDUP.32 d0,r0

    // initialize Q
    strPtr = Qmat;
    for (ii = 0; ii < matSizeN; ii++)
    {
        for (jj = 0; jj < MAX_MAT_SIZE; jj += 2)
        {
            vst1_f32((float32_t *)strPtr, storeVec); // VST1.32 {d0}, [r0]
            strPtr += 2;
        }
        strPtr[ii - MAX_MAT_SIZE] = 1.0f;
    }

    // Householder Tridiagonalization
    hh_len = matSizeN;
    xVec   = R_MATR;
    for (kk = 0; kk < matSizeM; kk++)
    { // A=V
        hh_len = matSizeN - kk;
        xVec   = R_MATR + kk * (MAX_MAT_SIZE + 1);

        if (!house_holder_vec(xVec, vVec, &beta, &xNorm, hh_len))
        {
            for (ii = hh_len; ii < MAX_MAT_SIZE; ii++)
            {
                vVec[ii] = 0;
            }
            // apply house holder iteration
            pVec[0] = 0;
            for (ii = 1; ii < matSizeM - kk; ii += 2)
            {                                                // calc. p = beta*A'*v
                resVec0 = vdup_n_f32(0.0f);                  // VDUP.32 d0,r0
                resVec1 = vdup_n_f32(0.0f);                  // VDUP.32 d0,r0
                ldPtr   = R_MATR + (ii + kk) * MAX_MAT_SIZE + kk;
                vVecf32 = vld1_f32((float32_t const *)vVec); // VLD1.32 {d0}, [r0]
                for (jj = 0; jj < hh_len; jj += 2)
                {
                    colVec0 = vld1_f32((float32_t const *)ldPtr);                  // VLD1.32 {d0}, [r0]
                    resVec0 = vmla_f32(resVec0, colVec0, vVecf32);
                    colVec1 = vld1_f32((float32_t const *)(ldPtr + MAX_MAT_SIZE)); // VLD1.32 {d0}, [r0]
                    ldPtr += 2;
                    resVec1 = vmla_f32(resVec1, colVec1, vVecf32);
                    vVecf32 = vld1_f32((float32_t const *)(vVec + jj + 2)); // VLD1.32 {d0}, [r0]
                }
                sumVec = vpadd_f32(resVec0, resVec1);
                sumVec = vmul_n_f32(sumVec, beta);          // VMUL.F32 d0,d0,d0[0]
                vst1_f32((float32_t *)(pVec + ii), sumVec); // VST1.32 {d0}, [r0]
            }
            pVec[matSizeM - kk] = 0;

            strPtr    = R_MATR + kk * (MAX_MAT_SIZE + 1);
            *strPtr++ = xNorm;
            for (ii = 1; ii < hh_len; ii++)
            {
                *strPtr++ = 0;
            }
            // R(index_col,index_row) = R(index_col,index_row)-v*p';
            for (ii = 1; ii < matSizeM - kk; ii += 2)
            {
                pVecf32 = vld1_f32((float32_t const *)(pVec + ii)); // VLD1.32 {d0}, [r0]
                ldPtr   = R_MATR + (ii + kk) * MAX_MAT_SIZE + kk;
                vVecf32 = vld1_f32((float32_t const *)vVec);        // VLD1.32 {d0}, [r0]
                for (jj = 0; jj < hh_len; jj += 2)
                {
                    colVec0 = vld1_f32((float32_t const *)ldPtr);                  // VLD1.32 {d0}, [r0]
                    colVec0 = vmls_lane_f32(colVec0, vVecf32, pVecf32, 0);
                    colVec1 = vld1_f32((float32_t const *)(ldPtr + MAX_MAT_SIZE)); // VLD1.32 {d0}, [r0]
                    vst1_f32((float32_t *)ldPtr, colVec0);
                    colVec1 = vmls_lane_f32(colVec1, vVecf32, pVecf32, 1);
                    vst1_f32((float32_t *)(ldPtr + MAX_MAT_SIZE), colVec1);
                    ldPtr += 2;
                    vVecf32 = vld1_f32((float32_t const *)(vVec + jj + 2)); // VLD1.32 {d0}, [r0]
                }
            }

            // update Q
            for (ii = 0; ii < matSizeN; ii += 2)
            {                                                // calc.  q= beta*Q(:,index_col)*v;
                sumVec  = vdup_n_f32(0.0f);                  // VDUP.32 d0,r0
                ldPtr   = Qmat + ii + kk * MAX_MAT_SIZE;
                vVecf32 = vld1_f32((float32_t const *)vVec); // VLD1.32 {d0}, [r0]
                for (jj = 0; jj < hh_len; jj += 2)
                {
                    colVec0 = vld1_f32((float32_t const *)ldPtr); // VLD1.32 {d0}, [r0]
                    ldPtr += MAX_MAT_SIZE;
                    sumVec  = vmla_lane_f32(sumVec, colVec0, vVecf32, 0);
                    colVec1 = vld1_f32((float32_t const *)ldPtr); // VLD1.32 {d0}, [r0]
                    ldPtr += MAX_MAT_SIZE;
                    sumVec  = vmla_lane_f32(sumVec, colVec1, vVecf32, 1);
                    vVecf32 = vld1_f32((float32_t const *)(vVec + jj + 2)); // VLD1.32 {d0}, [r0]
                }
                sumVec = vmul_n_f32(sumVec, beta);                          // VMUL.F32 d0,d0,d0[0]
                vst1_f32((float32_t *)(qVec + ii), sumVec);                 // VST1.32 {d0}, [r0]
            }
            qVec[matSizeN] = 0;
            // Q(:,index_col) = Q(:,index_col)-q*v';
            for (ii = 0; ii < matSizeN; ii += 2)
            {
                qVecf32 = vld1_f32((float32_t const *)(qVec + ii));
                ldPtr   = Qmat + ii + kk * MAX_MAT_SIZE;
                vVecf32 = vld1_f32((float32_t const *)vVec); // VLD1.32 {d0}, [r0]
                for (jj = 0; jj < hh_len; jj += 2)
                {
                    colVec0 = vld1_f32((float32_t const *)ldPtr);                  // VLD1.32 {d0}, [r0]
                    colVec0 = vmls_lane_f32(colVec0, qVecf32, vVecf32, 0);         // VMLS.F32 d0,
                    colVec1 = vld1_f32((float32_t const *)(ldPtr + MAX_MAT_SIZE)); // VLD1.32 {d0}, [r0]
                    colVec1 = vmls_lane_f32(colVec1, qVecf32, vVecf32, 1);         // VMLS.F32 d0,
                    vst1_f32((float32_t *)ldPtr, colVec0);                         // VST1.32 {d0}, [r0]
                    vst1_f32((float32_t *)(ldPtr + MAX_MAT_SIZE), colVec1);        // VST1.32 {d0}, [r0]
                    ldPtr += 2 * MAX_MAT_SIZE;
                    vVecf32 = vld1_f32((float32_t const *)(vVec + jj + 2));        // VLD1.32 {d0}, [r0]
                }
            }
        }
        hh_len--;
        xVec += MAX_MAT_SIZE + 1;
    }
#else
    int ii, jj, kk, hh_len;
    float *xVec;
    float beta, xNorm, sum;
    float tempVal;

    float *R_MATR = inMatArr;
    float *Qmat   = resD;                           // Qmat[matSizeN*matSizeN]
    float *vVec   = Qmat + MAX_MAT_SIZE * matSizeN; // vVec[matSizeN]
    float *qVec   = vVec + matSizeN;                // qVec[matSizeN]
    float *pVec   = qVec + matSizeN;                // pVec[matSizeM]

    // initialize Q
    for (ii = 0; ii < matSizeN; ii++)
    {
        for (jj = 0; jj < matSizeN; jj++)
        {
            Qmat[jj + MAX_MAT_SIZE * ii] = 0.0f;
        }
        Qmat[ii + MAX_MAT_SIZE * ii] = 1.0f;
    }

    // Householder Tridiagonalization
    for (kk = 0; kk < matSizeM; kk++)
    { // A=V
        hh_len = matSizeN - kk;
        xVec   = R_MATR + kk * (MAX_MAT_SIZE + 1);

        if (!house_holder_vec(xVec, vVec, &beta, &xNorm, hh_len))
        {
            // apply house holder iteration
            pVec[0] = 0;
            for (ii = 1; ii < matSizeM - kk; ii++)
            { // calc. p = beta*A'*v
                sum = 0;
                for (jj = 0; jj < hh_len; jj++)
                {
                    sum += R_MATR[(ii + kk) * MAX_MAT_SIZE + (jj + kk)] * vVec[jj];
                }
                pVec[ii] = beta * sum;
            }
            R_MATR[kk * (MAX_MAT_SIZE + 1)] = xNorm;
            for (ii = 1; ii < hh_len; ii++)
            {
                R_MATR[(ii + kk) + kk * MAX_MAT_SIZE] = 0;
            }
            // R(index_col,index_row) = R(index_col,index_row)-v*p';
            for (ii = 1; ii < matSizeM - kk; ii++)
            {
                tempVal = pVec[ii];
                for (jj = 0; jj < hh_len; jj++)
                {
                    R_MATR[(ii + kk) * MAX_MAT_SIZE + (jj + kk)] -= vVec[jj] * tempVal;
                }
            }

            // update Q
            for (ii = 0; ii < matSizeN; ii++)
            { // calc.  q= beta*Q(:,index_col)*v;
                sum = 0;
                for (jj = 0; jj < hh_len; jj++)
                {
                    sum += Qmat[ii + (jj + kk) * MAX_MAT_SIZE] * vVec[jj];
                }
                qVec[ii] = beta * sum;
            }
            // Q(:,index_col) = Q(:,index_col)-q*v';
            for (ii = 0; ii < matSizeN; ii++)
            {
                tempVal = qVec[ii];
                for (jj = 0; jj < hh_len; jj++)
                {
                    Qmat[ii + (jj + kk) * MAX_MAT_SIZE] -= vVec[jj] * tempVal;
                }
            }
        }
    }
#endif
}

// symmetric eigen(Shur) decomposition
int QR_algorithm(float *inMatArr, float *resD, int matSizeN, int low_accuracy)
{
    int kk, ii, jj, count, delta_count;
    int N_hh_it;

    float *xVec;
    float beta, sum, prod, xNorm;
    int startIdx, zeroIdx = 0;
    unsigned char indexArr[MAX_MAT_SIZE];
    float step;

    float *eigVals = resD;
    float *Qmat    = eigVals + MAX_MAT_SIZE;          // vVec[matSizeN*matSizeN]

    float *vVec = Qmat + MAX_MAT_SIZE * MAX_MAT_SIZE; // vVec[matSizeN]
    float *wVec = vVec + MAX_MAT_SIZE;                // wVec[matSizeN]
    float *pVec = wVec + MAX_MAT_SIZE;                // pVec[matSizeN]

    float *diagA    = vVec;                           // diagA[matSizeN]
    float *offDiagA = wVec;                           // offDiagA[matSizeN]

#ifdef ARM_DS5
    float *ldPtr, *strPtr, *strPtrTr;
    float32x2_t storeVec;
    float32x2x2_t storeVec2;
    float32x2_t colVec0, colVec1, pVecf32, vVecf32, wVecf32, vVecfTr, wVecfTr, sumVec;

    step     = (low_accuracy == 1) ? TOL_QR_STEP_LOW : TOL_QR_STEP;
    storeVec = vdup_n_f32(0.0f); // VDUP.32 d0,r0

    // initialize Q
    strPtr = Qmat;
    for (ii = 0; ii < MAX_MAT_SIZE; ii++)
    {
        for (jj = 0; jj < MAX_MAT_SIZE; jj += 2)
        {
            vst1_f32((float32_t *)strPtr, storeVec); // VST1.32 {d0}, [r0]
            strPtr += 2;
        }
        strPtr[ii - MAX_MAT_SIZE] = 1.0f;
    }

    // Householder Tridiagonalization
    xVec    = inMatArr + 1;
    N_hh_it = matSizeN - 1;
    for (kk = 1; kk < matSizeN - 1; kk++)
    {
        if (!house_holder_vec(xVec, vVec, &beta, &xNorm, N_hh_it))
        { // calculate house holder vector
            for (ii = N_hh_it; ii < MAX_MAT_SIZE; ii++)
            {
                vVec[ii] = 0;
            }
            // apply house holder iteration
            for (ii = 0; ii < N_hh_it; ii += 2)
            {                              // calc. p = beta*A*v and q = beta*Q'*v;
                sumVec = vdup_n_f32(0.0f); // VDUP.32 d0,r0
                ldPtr  = inMatArr + (kk * MAX_MAT_SIZE + (ii + kk));
                for (jj = 0; jj < N_hh_it; jj += 2)
                {
                    vVecf32 = vld1_f32((float32_t const *)(vVec + jj));  // VLD1.32 {d0}, [r0]
                    colVec0 = vld1_f32((float32_t const *)ldPtr);        // VLD1.32 {d0}, [r0]
                    ldPtr += MAX_MAT_SIZE;
                    sumVec = vmla_lane_f32(sumVec, colVec0, vVecf32, 0); // VMLA.F32 d0, d0, d0[0]

                    colVec1 = vld1_f32((float32_t const *)ldPtr);        // VLD1.32 {d0}, [r0]
                    ldPtr += MAX_MAT_SIZE;
                    sumVec = vmla_lane_f32(sumVec, colVec1, vVecf32, 1); // VMLA.F32 d0, d0, d0[0]
                }
                sumVec = vmul_n_f32(sumVec, beta);                       // VMUL.F32 d0,d0,d0[0]
                vst1_f32((float32_t *)(pVec + ii), sumVec);              // VST1.32 {d0}, [r0]
            }
            pVec[N_hh_it] = 0;

            sumVec = vdup_n_f32(0.0f);                              // VDUP.32 d0,r0
            for (jj = 0; jj < N_hh_it; jj += 2)
            {                                                       // calc. (beta*p'*v/2)
                pVecf32 = vld1_f32((float32_t const *)(pVec + jj)); // VLD1.32 {d0}, [r0]
                vVecf32 = vld1_f32((float32_t const *)(vVec + jj)); // VLD1.32 {d0}, [r0]
                sumVec  = vmla_f32(sumVec, pVecf32, vVecf32);       // VMLA.F32 d0,d0,d0
            }
            sumVec = vpadd_f32(sumVec, sumVec);                     // VPADD.F32 d0,d0,d0
            sum    = vget_lane_f32(sumVec, 0);                      // VMOV.32 r0, d0[0]
            prod   = beta * sum / 2;

            for (ii = 0; ii < N_hh_it; ii += 2)
            {                                                       // calc. w = p-(beta*p'*v/2)*v;
                vVecf32 = vld1_f32((float32_t const *)(vVec + ii)); // VLD1.32 {d0}, [r0]
                pVecf32 = vld1_f32((float32_t const *)(pVec + ii)); // VLD1.32 {d0}, [r0]
                pVecf32 = vmls_n_f32(pVecf32, vVecf32, prod);       // VMLS.F32 d0, d0, d0[0]
                vst1_f32((float32_t *)(wVec + ii), pVecf32);        // VST1.32 {d0}, [r0]
            }

            strPtr   = inMatArr + ((kk)*MAX_MAT_SIZE + (kk - 1));
            strPtrTr = strPtr - (MAX_MAT_SIZE - 1); // inMatArr + ((kk-1)*matSizeN+(kk));
            *strPtr  = xNorm;
            strPtr += MAX_MAT_SIZE;
            *strPtrTr++ = xNorm;
            for (ii = 1; ii < N_hh_it; ii++)
            {
                *strPtr = 0;
                strPtr += MAX_MAT_SIZE;
                *strPtrTr++ = 0;
            }

            // calc A(index_kk,index_kk)-v*w'-w*v';
            for (ii = 0; ii < N_hh_it; ii += 2)
            {
                ldPtr   = inMatArr + (ii + kk) * MAX_MAT_SIZE + (ii + kk);
                vVecf32 = vld1_f32((float32_t const *)(vVec + ii));            // VLD1.32 {d0}, [r0]
                wVecf32 = vld1_f32((float32_t const *)(wVec + ii));            // VLD1.32 {d0}, [r0]
                colVec0 = vld1_f32((float32_t const *)ldPtr);                  // VLD1.32 {d0}, [r0]
                colVec1 = vld1_f32((float32_t const *)(ldPtr + MAX_MAT_SIZE)); // VLD1.32 {d0}, [r0]
                colVec0 = vmls_lane_f32(colVec0, vVecf32, wVecf32, 0);         // VMLS.F32 d0,
                colVec1 = vmls_lane_f32(colVec1, vVecf32, wVecf32, 1);         // VMLS.F32 d0,
                colVec0 = vmls_lane_f32(colVec0, wVecf32, vVecf32, 0);         // VMLS.F32 d0,
                colVec1 = vmls_lane_f32(colVec1, wVecf32, vVecf32, 1);         // VMLS.F32 d0,
                vst1_f32((float32_t *)ldPtr, colVec0);                         // VST1.32 {d0}, [r0]
                vst1_f32((float32_t *)(ldPtr + MAX_MAT_SIZE), colVec1);        // VST1.32 {d0}, [r0]

                ldPtr -= ii; // ldPtr = inMatArr+ (ii+kk)*matSizeN + kk;
                strPtr = inMatArr + kk * MAX_MAT_SIZE + (ii + kk);
                for (jj = 0; jj < ii; jj += 2)
                {
                    wVecfTr = vld1_f32((float32_t const *)(wVec + jj));            // VLD1.32 {d0}, [r0]
                    colVec0 = vld1_f32((float32_t const *)ldPtr);                  // VLD1.32 {d0}, [r0]
                    colVec1 = vld1_f32((float32_t const *)(ldPtr + MAX_MAT_SIZE)); // VLD1.32 {d0}, [r0]
                    colVec0 = vmls_lane_f32(colVec0, wVecfTr, vVecf32, 0);         // VMLS.F32 d0,
                    colVec1 = vmls_lane_f32(colVec1, wVecfTr, vVecf32, 1);         // VMLS.F32 d0,
                    vVecfTr = vld1_f32((float32_t const *)(vVec + jj));            // VLD1.32 {d0}, [r0]
                    colVec0 = vmls_lane_f32(colVec0, vVecfTr, wVecf32, 0);         // VMLS.F32 d0,
                    colVec1 = vmls_lane_f32(colVec1, vVecfTr, wVecf32, 1);         // VMLS.F32 d0,
                    vst1_f32((float32_t *)ldPtr, colVec0);                         // VST1.32 {d0}, [r0]
                    vst1_f32((float32_t *)(ldPtr + MAX_MAT_SIZE), colVec1);        // VST1.32 {d0}, [r0]
                    ldPtr += 2;
                    storeVec2 = vtrn_f32(colVec0, colVec1);                        // VTRN.32 d0,d0
                    vst1_f32((float32_t *)strPtr, storeVec2.val[0]);               // VST1.32 {d0}, [r0]
                    strPtr += MAX_MAT_SIZE;
                    vst1_f32((float32_t *)strPtr, storeVec2.val[1]);               // VST1.32 {d0}, [r0]
                    strPtr += MAX_MAT_SIZE;
                }
            }

            // update Q
            for (ii = 0; ii < matSizeN; ii += 2)
            {                              // calc. p = beta*QQ0(index_kk,:)'*v;
                sumVec = vdup_n_f32(0.0f); // VDUP.32 d0,r0
                ldPtr  = Qmat + kk * MAX_MAT_SIZE + ii;
                for (jj = 0; jj < N_hh_it; jj += 2)
                {
                    colVec0 = vld1_f32((float32_t const *)ldPtr);       // VLD1.32 {d0}, [r0]
                    ldPtr += MAX_MAT_SIZE;
                    colVec1 = vld1_f32((float32_t const *)ldPtr);       // VLD1.32 {d0}, [r0]
                    ldPtr += MAX_MAT_SIZE;
                    vVecf32 = vld1_f32((float32_t const *)(vVec + jj)); // VLD1.32 {d0}, [r0]
                    sumVec  = vmla_lane_f32(sumVec, colVec0, vVecf32, 0);
                    sumVec  = vmla_lane_f32(sumVec, colVec1, vVecf32, 1);
                }
                sumVec = vmul_n_f32(sumVec, beta);          // VMUL.F32 d0,d0,d0[0]
                vst1_f32((float32_t *)(pVec + ii), sumVec); // VST1.32 {d0}, [r0]
            }
            // Q0(index_kk,:)-v*p';
            for (ii = 0; ii < N_hh_it; ii += 2)
            {
                vVecf32 = vld1_f32((float32_t const *)(vVec + ii)); // VLD1.32 {d0}, [r0]
                ldPtr   = Qmat + (ii + kk) * MAX_MAT_SIZE;
                for (jj = 0; jj < matSizeN; jj += 2)
                {
                    pVecf32 = vld1_f32((float32_t const *)(pVec + jj));            // VLD1.32 {d0}, [r0]
                    colVec0 = vld1_f32((float32_t const *)ldPtr);                  // VLD1.32 {d0}, [r0]
                    colVec1 = vld1_f32((float32_t const *)(ldPtr + MAX_MAT_SIZE)); // VLD1.32 {d0}, [r0]
                    colVec0 = vmls_lane_f32(colVec0, pVecf32, vVecf32, 0);         // VMLS.F32 d0,
                    colVec1 = vmls_lane_f32(colVec1, pVecf32, vVecf32, 1);         // VMLS.F32 d0,

                    vst1_f32((float32_t *)ldPtr, colVec0);                         // VST1.32 {d0}, [r0]
                    vst1_f32((float32_t *)(ldPtr + MAX_MAT_SIZE), colVec1);        // VST1.32 {d0}, [r0]
                    ldPtr += 2;
                }
            }
        }
        xVec += MAX_MAT_SIZE + 1;
        N_hh_it--;
    }
#else
    float temp, sum1, vTemp;

    if (low_accuracy == 1)
        step = TOL_QR_STEP_LOW;
    else
        step = TOL_QR_STEP;

    // initialize Q
    for (ii = 0; ii < MAX_MAT_SIZE; ii++)
    {
        for (jj = 0; jj < MAX_MAT_SIZE; jj++)
        {
            Qmat[jj + MAX_MAT_SIZE * ii] = 0.0f;
        }
        Qmat[ii + MAX_MAT_SIZE * ii] = 1.0f;
        vVec[ii]                     = 0;
    }

    // Householder Tridiagonalization
    for (kk = 1; kk < matSizeN - 1; kk++)
    {
        N_hh_it = matSizeN - kk;
        xVec    = inMatArr + kk + (kk - 1) * MAX_MAT_SIZE;
        // calculate house holder vector
        if (!house_holder_vec(xVec, vVec, &beta, &xNorm, N_hh_it))
        {
            // apply house holder iteration
            for (ii = 0; ii < N_hh_it; ii += 2)
            { // calc. p = beta*A*v and q = beta*Q'*v;
                sum  = 0;
                sum1 = 0;
                for (jj = 0; jj < N_hh_it; jj++)
                {
                    vTemp = vVec[jj];
                    temp  = inMatArr[(jj + kk) * MAX_MAT_SIZE + (ii + kk)];
                    sum += temp * vTemp;
                    temp = inMatArr[(jj + kk) * MAX_MAT_SIZE + (ii + 1 + kk)];
                    sum1 += temp * vTemp;
                }
                pVec[ii]     = beta * sum;
                pVec[ii + 1] = beta * sum1;
            }
            sum = 0; // calc. (beta*p'*v/2)
            for (jj = 0; jj < N_hh_it; jj++)
            {
                sum += pVec[jj] * vVec[jj];
            }
            prod = beta * sum / 2;
            for (ii = 0; ii < N_hh_it; ii++)
            { // calc. w = p-(beta*p'*v/2)*v;
                wVec[ii] = pVec[ii] - prod * vVec[ii];
            }
            inMatArr[(kk)*MAX_MAT_SIZE + (kk - 1)]   = xNorm;
            inMatArr[(kk - 1) * MAX_MAT_SIZE + (kk)] = xNorm;
            for (ii = 1; ii < N_hh_it; ii++)
            {
                inMatArr[(ii + kk) * MAX_MAT_SIZE + (kk - 1)] = 0;
                inMatArr[(kk - 1) * MAX_MAT_SIZE + (ii + kk)] = 0;
            }
            // calc A(index_kk,index_kk)-v*w'-w*v';
            for (ii = 0; ii < N_hh_it; ii++)
            {
                sum = vVec[ii] * wVec[ii] + wVec[ii] * vVec[ii];
                inMatArr[(ii + kk) * MAX_MAT_SIZE + (ii + kk)] -= sum;
                for (jj = 0; jj < ii; jj++)
                {
                    sum  = vVec[ii] * wVec[jj] + wVec[ii] * vVec[jj];
                    temp = inMatArr[(ii + kk) * MAX_MAT_SIZE + (jj + kk)];
                    temp -= sum;
                    inMatArr[(ii + kk) * MAX_MAT_SIZE + (jj + kk)] = temp;
                    inMatArr[(jj + kk) * MAX_MAT_SIZE + (ii + kk)] = temp;
                }
            }
            // update Q
            for (ii = N_hh_it; ii < matSizeN; ii++)
            {
                vVec[ii] = 0;
            }
            for (ii = 0; ii < matSizeN; ii += 2)
            { // calc. p = beta*QQ0(index_kk,:)'*v;
                sum  = 0;
                sum1 = 0;
                for (jj = 0; jj < N_hh_it; jj++)
                {
                    sum += Qmat[(jj + kk) * MAX_MAT_SIZE + ii] * vVec[jj];
                    sum1 += Qmat[(jj + kk) * MAX_MAT_SIZE + ii + 1] * vVec[jj];
                }
                pVec[ii]     = beta * sum;
                pVec[ii + 1] = beta * sum1;
            }
            // Q0(index_kk,:)-v*p';
            for (ii = 0; ii < N_hh_it; ii++)
            {
                for (jj = 0; jj < matSizeN; jj++)
                {
                    Qmat[(ii + kk) * MAX_MAT_SIZE + jj] -= vVec[ii] * pVec[jj];
                }
            }
        }
    }
#endif
    // Implicit Symmetric QR Step with Wilkinson Shift
    diagA[0]    = inMatArr[0]; // copy tridiagonal D
    offDiagA[0] = 0;
    indexArr[0] = 0;
    for (ii = 1; ii < matSizeN; ii++)
    {
        diagA[ii]    = inMatArr[ii * (MAX_MAT_SIZE + 1)];
        offDiagA[ii] = inMatArr[ii * (MAX_MAT_SIZE + 1) - 1];
        if (FABSF(offDiagA[ii]) < step)
        { // find decoupled blocks
            zeroIdx++;
            indexArr[zeroIdx] = ii;
        }
    }
    count = 0;

    startIdx = indexArr[zeroIdx--];
    for (kk = matSizeN - 1; kk > 0; kk--)
    {
        if (kk > startIdx)
        {
            delta_count = 0;
            while ((FABSF(offDiagA[kk]) > step * (FABSF(diagA[kk - 1]) + FABSF(diagA[kk]))) &&
                   (delta_count < WILK_IT_MAX))
            {
                QR_step_Wilkinson(diagA + startIdx, offDiagA + startIdx, Qmat + startIdx * MAX_MAT_SIZE, matSizeN,
                                  kk - startIdx);
                delta_count++;
            }
            count += delta_count;
            if (kk - startIdx > 2)
            {
                zeroIdx++;
                // check for newly diagonalized blocks
                for (ii = startIdx + 1; ii < kk; ii++)
                {
                    if (FABSF(offDiagA[ii]) < step)
                    { // find decoupled blocks
                        zeroIdx++;
                        indexArr[zeroIdx] = ii;
                    }
                }
                startIdx = indexArr[zeroIdx--];
            }
        }
        else
        {
            if (startIdx > 0)
            {
                startIdx = indexArr[zeroIdx--];
            }
        }
    }
    for (ii = 0; ii < matSizeN; ii++)
    {
        eigVals[ii] = diagA[ii];
    }

    return 0;
}

// unsymmetric eigen(Shur) decomposition, only solves for eigen values
int unsym_QR_algorithm(float *inMatArr, float *resD, int matSizeN)
{
    int kk, ii, jj, count, delta_count;
    int N_hh_it;
    float *xVec;
    float beta, sum, xNorm, tempVal;
    int startIdx, zeroIdx = 0;
    unsigned char indexArr[MAX_MAT_SIZE];

    float *eigVals = resD;
    float *vVec    = eigVals + MAX_MAT_SIZE; // vVec[matSizeN]
    float *pVec0   = vVec + MAX_MAT_SIZE;    // pVec0[matSizeN]
    float *pVec1   = pVec0 + MAX_MAT_SIZE;   // pVec1[matSizeN]

#ifdef ARM_DS5
    float *ldPtr, *strPtr;
    float32x2_t resVec0, resVec1;
    float32x2_t colVec0, colVec1, pVecf32, vVecf32, sumVec;

    // Householder Tridiagonalization
    N_hh_it = matSizeN - 1;
    xVec    = inMatArr + 1;
    for (kk = 1; kk < matSizeN - 1; kk++)
    {
        // calculate house holder vector
        if (!house_holder_vec(xVec, vVec, &beta, &xNorm, N_hh_it))
        {
            vVec[N_hh_it] = 0;

            // apply house holder iteration
            for (ii = 0; ii < N_hh_it; ii += 2)
            {                                                // calc. p0 = beta*A(index_kk,index_kk)'*v
                resVec0 = vdup_n_f32(0.0f);                  // VDUP.32 d0,r0
                resVec1 = vdup_n_f32(0.0f);                  // VDUP.32 d0,r0
                ldPtr   = inMatArr + kk + (ii + kk) * matSizeN;
                vVecf32 = vld1_f32((float32_t const *)vVec); // VLD1.32 {d0}, [r0]
                for (jj = 0; jj < N_hh_it; jj += 2)
                {
                    colVec0 = vld1_f32((float32_t const *)ldPtr);              // VLD1.32 {d0}, [r0]
                    resVec0 = vmla_f32(resVec0, colVec0, vVecf32);
                    colVec1 = vld1_f32((float32_t const *)(ldPtr + matSizeN)); // VLD1.32 {d0}, [r0]
                    resVec1 = vmla_f32(resVec1, colVec1, vVecf32);
                    ldPtr += 2;
                    vVecf32 = vld1_f32((float32_t const *)(vVec + jj + 2)); // VLD1.32 {d0}, [r0]
                }
                sumVec = vpadd_f32(resVec0, resVec1);
                sumVec = vmul_n_f32(sumVec, beta);           // VMUL.F32 d0,d0,d0[0]
                vst1_f32((float32_t *)(pVec0 + ii), sumVec); // VST1.32 {d0}, [r0]
            }
            pVec0[N_hh_it] = 0;
            strPtr         = inMatArr + (kk) + (kk - 1) * matSizeN;
            *strPtr++      = xNorm;
            for (ii = 1; ii < N_hh_it; ii++)
            {
                *strPtr++ = 0;
            }
            // calc A(index_kk,index_kk)-v*p0'
            for (ii = 0; ii < N_hh_it; ii += 2)
            {
                pVecf32 = vld1_f32((float32_t const *)(pVec0 + ii)); // VLD1.32 {d0}, [r0]
                vVecf32 = vld1_f32((float32_t const *)vVec);         // VLD1.32 {d0}, [r0]
                for (jj = 0; jj < N_hh_it; jj += 2)
                {
                    colVec0 = vld1_f32(
                        (float32_t const *)(inMatArr + (jj + kk) + (ii + kk) * matSizeN));         // VLD1.32 {d0}, [r0]
                    colVec0 = vmls_lane_f32(colVec0, vVecf32, pVecf32, 0);                         // VMLS.F32 d0,
                    colVec1 = vld1_f32(
                        (float32_t const *)(inMatArr + (jj + kk) + (ii + 1 + kk) * matSizeN));     // VLD1.32 {d0}, [r0]
                    colVec1 = vmls_lane_f32(colVec1, vVecf32, pVecf32, 1);                         // VMLS.F32 d0,
                    vst1_f32((float32_t *)(inMatArr + (jj + kk) + (ii + kk) * matSizeN), colVec0); // VST1.32 {d0}, [r0]
                    vst1_f32((float32_t *)(inMatArr + (jj + kk) + (ii + 1 + kk) * matSizeN),
                             colVec1);                                                             // VST1.32 {d0}, [r0]
                    vVecf32 = vld1_f32((float32_t const *)(vVec + jj + 2));                        // VLD1.32 {d0}, [r0]
                }
            }
            // second update
            for (ii = 0; ii < matSizeN; ii += 2)
            { // calc. p1 = beta*A(:,index_kk)*v
                sumVec  = vdup_n_f32(0.0f);
                ldPtr   = inMatArr + ii + kk * matSizeN;
                vVecf32 = vld1_f32((float32_t const *)vVec); // VLD1.32 {d0}, [r0]
                for (jj = 0; jj < N_hh_it; jj += 2)
                {
                    colVec0 = vld1_f32((float32_t const *)ldPtr); // VLD1.32 {d0}, [r0]
                    ldPtr += matSizeN;
                    sumVec  = vmla_lane_f32(sumVec, colVec0, vVecf32, 0);
                    colVec1 = vld1_f32((float32_t const *)ldPtr); // VLD1.32 {d0}, [r0]
                    ldPtr += matSizeN;
                    sumVec  = vmla_lane_f32(sumVec, colVec1, vVecf32, 1);
                    vVecf32 = vld1_f32((float32_t const *)(vVec + jj + 2)); // VLD1.32 {d0}, [r0]
                }
                sumVec = vmul_n_f32(sumVec, beta);                          // VMUL.F32 d0,d0,d0[0]
                vst1_f32((float32_t *)(pVec1 + ii), sumVec);
            }
            pVec1[matSizeN] = 0;

            // calc A(:,index_kk) -p1*v'
            for (ii = 0; ii < matSizeN; ii += 2)
            {
                pVecf32 = vld1_f32((float32_t const *)pVec1 + ii);
                ldPtr   = inMatArr + ii + kk * matSizeN;
                vVecf32 = vld1_f32((float32_t const *)vVec);
                for (jj = 0; jj < N_hh_it; jj += 2)
                {
                    colVec0 = vld1_f32((float32_t const *)ldPtr);
                    colVec0 = vmls_lane_f32(colVec0, pVecf32, vVecf32, 0); // VMLS.F32 d0,
                    colVec1 = vld1_f32((float32_t const *)(ldPtr + matSizeN));
                    colVec1 = vmls_lane_f32(colVec1, pVecf32, vVecf32, 1); // VMLS.F32 d0,
                    vst1_f32((float32_t *)ldPtr, colVec0);
                    ldPtr += matSizeN;
                    vst1_f32((float32_t *)ldPtr, colVec1);
                    ldPtr += matSizeN;
                    vVecf32 = vld1_f32((float32_t const *)(vVec + jj + 2));
                }
            }
        }
        N_hh_it--;
        xVec += matSizeN + 1;
    }
#else
    // Householder Tridiagonalization
    for (kk = 1; kk < matSizeN - 1; kk++)
    {
        N_hh_it = matSizeN - kk;
        xVec    = inMatArr + kk + (kk - 1) * matSizeN;
        // calculate house holder vector
        if (!house_holder_vec(xVec, vVec, &beta, &xNorm, N_hh_it))
        {
            // apply house holder iteration
            for (ii = 0; ii < N_hh_it; ii++)
            { // calc. p0 = beta*A(index_kk,index_kk)'*v
                sum = 0;
                for (jj = 0; jj < N_hh_it; jj++)
                {
                    sum += inMatArr[(jj + kk) + (ii + kk) * matSizeN] * vVec[jj];
                }
                pVec0[ii] = beta * sum;
            }
            inMatArr[(kk) + (kk - 1) * matSizeN] = xNorm;
            for (ii = 1; ii < N_hh_it; ii++)
            {
                inMatArr[(ii + kk) + (kk - 1) * matSizeN] = 0;
            }
            // calc A(index_kk,index_kk)-v*p0'
            for (ii = 0; ii < N_hh_it; ii++)
            {
                for (jj = 0; jj < N_hh_it; jj++)
                {
                    sum = vVec[jj] * pVec0[ii];
                    inMatArr[(jj + kk) + (ii + kk) * matSizeN] -= sum;
                }
            }
            // second update
            for (ii = 0; ii < matSizeN; ii++)
            { // calc. p1 = beta*A(:,index_kk)*v
                sum = 0;
                for (jj = 0; jj < N_hh_it; jj++)
                {
                    sum += inMatArr[ii + (jj + kk) * matSizeN] * vVec[jj];
                }
                pVec1[ii] = beta * sum;
            }
            // calc A(:,index_kk) -p1*v'
            for (ii = 0; ii < matSizeN; ii++)
            {
                for (jj = 0; jj < N_hh_it; jj++)
                {
                    sum = pVec1[ii] * vVec[jj];
                    inMatArr[ii + (jj + kk) * matSizeN] -= sum;
                }
            }
        }
    }
#endif

    // Implicit Symmetric QR Step with Wilkinson Shift
    indexArr[0] = 0;
    for (ii = 1; ii < matSizeN; ii++)
    {
        tempVal = FABSF(inMatArr[(ii - 1) * (matSizeN + 1) + 1]);
        sum     = FABSF(inMatArr[(ii - 1) * (matSizeN + 1)]) + FABSF(inMatArr[ii * (matSizeN + 1)]);
        if (tempVal < TOL_QR_STEP * sum)
        { // find decoupled blocks
            zeroIdx++;
            indexArr[zeroIdx] = ii;
        }
    }
    count = 0;

    startIdx = indexArr[zeroIdx--];
    for (kk = matSizeN - 1; kk > 0; kk--)
    {
        if (kk > startIdx)
        {
            tempVal     = FABSF(inMatArr[(kk - 1) * (matSizeN + 1) + 1]);
            sum         = FABSF(inMatArr[(kk - 1) * (matSizeN + 1)]) + FABSF(inMatArr[kk * (matSizeN + 1)]);
            delta_count = 0;
            while ((tempVal > TOL_QR_STEP * sum) && (delta_count < WILK_IT_MAX))
            {
                // while((tempVal > TOL_QR_STEP * sum)){
                unsym_QR_step_Wilkinson(inMatArr, matSizeN, kk, startIdx);
                delta_count++;
                tempVal = FABSF(inMatArr[(kk - 1) * (matSizeN + 1) + 1]);
                sum     = FABSF(inMatArr[(kk - 1) * (matSizeN + 1)]) + FABSF(inMatArr[kk * (matSizeN + 1)]);
            }
            count += delta_count;

            if (kk > 2)
            {
                // find newly decoupled blocks
                indexArr[0] = 0;
                zeroIdx     = 0;
                for (ii = 1; ii < kk; ii++)
                {
                    tempVal = FABSF(inMatArr[(ii - 1) * (matSizeN + 1) + 1]);
                    sum     = FABSF(inMatArr[(ii - 1) * (matSizeN + 1)]) + FABSF(inMatArr[ii * (matSizeN + 1)]);
                    if (tempVal < TOL_QR_STEP * sum)
                    { // find decoupled blocks
                        zeroIdx++;
                        indexArr[zeroIdx] = ii;
                    }
                }
                startIdx = indexArr[zeroIdx--];
            }
        }
        else
        {
            if (startIdx > 0)
            {
                startIdx = indexArr[zeroIdx--];
            }
        }
    }
    for (ii = 0; ii < matSizeN; ii++)
    {
        eigVals[ii] = inMatArr[ii * (matSizeN + 1)];
    }

    return 0;
}

#endif /* CONFIG_WLS_CSI_PROC */
