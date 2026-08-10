/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_MAU_H_
#define FSL_MAU_H_

#include "fsl_common.h"

/*!
 * @defgroup dsc_mau MAU: Math Acceleration Unit Driver
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief MAU driver version. */
#define FSL_MAU_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*******************************************************************************
 * MAU peripheral driver Change log
 ******************************************************************************/
/*!
 * @defgroup dsc_mau_driver_log The Driver Change Log
 * @ingroup dsc_mau
 * @{
 * The current MAU driver version is 2.0.0.
 *
 * - 2.0.0
 *    - Initial version.
 * @}
 */

/*******************************************************************************
 * Introduction
 ******************************************************************************/
/*!
 * @defgroup mau_intro MAU Peripheral and Driver Overview
 * @ingroup mau
 * @brief Content including 1) peripheral features; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Peripheral features
 * ==================================================
 * The Math Acceleration Unit (MAU) is a hardware accelerator that provides fast computation of
 * common math functions: sine, cosine, arctangent, square root, inverse square root, and
 * reciprocal. The MAU operates via memory-mapped indirect addresses and supports four result
 * registers (REG0..REG3), enabling pipelined or parallel computations.
 *
 * Supported operations and input data types:
 *  - SIN, COS, ATAN: Float32, Frac32 (Q1.31), Frac16 (Q1.15)
 *  - SQRT: Float32, Frac32 (Q1.31), Frac16 (Q1.15), Int32
 *  - Inverse square root (ISQRT): Float32
 *  - Reciprocal (RECIP): Float32
 *
 * How this driver is designed to make this peripheral work
 * ===========================================================
 * All driver APIs are implemented as static inline functions for maximum efficiency on the DSC
 * architecture. Each function encodes the operation, data type, and result register selection
 * into the MAU indirect address, writes the operand via inline assembly, and reads back the
 * result from the corresponding result register.
 *
 * Functions are provided for each combination of operation, data type, and result register
 * (REG0..REG3). This flat layout avoids runtime parameter dispatch and preserves the full
 * performance benefit of the MAU hardware.
 *
 * Typical Use Case
 * ================
 * + Compute sine of a float32 angle using result register 0:
 *   @code
 *       float fltResult = MAU_SinFlt32Reg0(fltAngle);
 *   @endcode
 *
 * @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief MAU indirect address base. */
#define MAU_BASE_ADDR (MAUWRAP_BASE)

/*! @name MAU data type selectors */
/*! @{ */
#define MAU_DT_UINT 0U /*!< Unsigned integer data type. */
#define MAU_DT_INT  1U /*!< Signed integer data type. */
#define MAU_DT_FRAC 2U /*!< Fractional data type. */
#define MAU_DT_FLT  3U /*!< Float data type. */
/*! @} */

/*! @name MAU result register selectors */
/*! @{ */
#define MAU_RESSEL_0 0U /*!< Result register 0. */
#define MAU_RESSEL_1 1U /*!< Result register 1. */
#define MAU_RESSEL_2 2U /*!< Result register 2. */
#define MAU_RESSEL_3 3U /*!< Result register 3. */
/*! @} */

/*! @name MAU operation code selectors */
/*! @{ */
#define MAU_MOPC_BYPASS 0U  /*!< Bypass operation. */
#define MAU_MOPC_RECIP  1U  /*!< Reciprocal operation. */
#define MAU_MOPC_SQRT   2U  /*!< Square root operation. */
#define MAU_MOPC_ISQRT  3U  /*!< Inverse (reciprocal) square root operation. */
#define MAU_MOPC_COS    8U  /*!< Cosine operation. */
#define MAU_MOPC_SIN    9U  /*!< Sine operation. */
#define MAU_MOPC_ATAN   12U /*!< Arctangent operation. */
/*! @} */

/*! @name MAU indirect address field offsets */
/*! @{ */
#define MAU_DT_OFFSET     9U /*!< Data type field bit offset. */
#define MAU_RESSEL_OFFSET 7U /*!< Result register select field bit offset. */
#define MAU_MOPC_OFFSET   2U /*!< Operation code field bit offset. */
/*! @} */

/*! @name MAU result register addresses */
/*! @{ */
#define MAU_RESULT0_ADDR 0xA420U /*!< Result register 0 word address. */
#define MAU_RESULT1_ADDR 0xA422U /*!< Result register 1 word address. */
#define MAU_RESULT2_ADDR 0xA424U /*!< Result register 2 word address. */
#define MAU_RESULT3_ADDR 0xA426U /*!< Result register 3 word address. */
/*! @} */

/*! @name MAU indirect address helper macros */

/*!
 * @brief Build a MAU word indirect address from data-type, operation-code, and result-register selectors.
 * @param dt     Data type selector (MAU_DT_FRAC, MAU_DT_FLT, MAU_DT_INT, MAU_DT_UINT).
 * @param mopc   Operation code selector (MAU_MOPC_*).
 * @param ressel Result register selector (MAU_RESSEL_0 .. MAU_RESSEL_3).
 */
#define MAU_IADDR_WORD(dt, mopc, ressel)  \
    (MAU_BASE_ADDR                       |\
    ((dt) << (MAU_DT_OFFSET - 1U))       |\
    ((mopc) << (MAU_MOPC_OFFSET - 1U))   |\
    ((ressel) << (MAU_RESSEL_OFFSET - 1U)))
/*! @} */

/*! @name MAU reciprocal indirect addresses */
/*! @{ */
#define MAU_RECIP_FRAC_WORD_REG0  MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_RECIP, MAU_RESSEL_0)
#define MAU_RECIP_FLT_WORD_REG0   MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_RECIP, MAU_RESSEL_0)

#define MAU_RECIP_FRAC_WORD_REG1  MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_RECIP, MAU_RESSEL_1)
#define MAU_RECIP_FLT_WORD_REG1   MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_RECIP, MAU_RESSEL_1)

#define MAU_RECIP_FRAC_WORD_REG2  MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_RECIP, MAU_RESSEL_2)
#define MAU_RECIP_FLT_WORD_REG2   MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_RECIP, MAU_RESSEL_2)

#define MAU_RECIP_FRAC_WORD_REG3  MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_RECIP, MAU_RESSEL_3)
#define MAU_RECIP_FLT_WORD_REG3   MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_RECIP, MAU_RESSEL_3)
/*! @} */

/*! @name MAU inverse square root indirect addresses */
/*! @{ */
#define MAU_ISQRT_FRAC_WORD_REG0  MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_ISQRT, MAU_RESSEL_0)
#define MAU_ISQRT_FLT_WORD_REG0   MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_ISQRT, MAU_RESSEL_0)
#define MAU_ISQRT_INT_WORD_REG0   MAU_IADDR_WORD(MAU_DT_INT,  MAU_MOPC_ISQRT, MAU_RESSEL_0)

#define MAU_ISQRT_FRAC_WORD_REG1  MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_ISQRT, MAU_RESSEL_1)
#define MAU_ISQRT_FLT_WORD_REG1   MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_ISQRT, MAU_RESSEL_1)
#define MAU_ISQRT_INT_WORD_REG1   MAU_IADDR_WORD(MAU_DT_INT,  MAU_MOPC_ISQRT, MAU_RESSEL_1)

#define MAU_ISQRT_FRAC_WORD_REG2  MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_ISQRT, MAU_RESSEL_2)
#define MAU_ISQRT_FLT_WORD_REG2   MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_ISQRT, MAU_RESSEL_2)
#define MAU_ISQRT_INT_WORD_REG2   MAU_IADDR_WORD(MAU_DT_INT,  MAU_MOPC_ISQRT, MAU_RESSEL_2)

#define MAU_ISQRT_FRAC_WORD_REG3  MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_ISQRT, MAU_RESSEL_3)
#define MAU_ISQRT_FLT_WORD_REG3   MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_ISQRT, MAU_RESSEL_3)
#define MAU_ISQRT_INT_WORD_REG3   MAU_IADDR_WORD(MAU_DT_INT,  MAU_MOPC_ISQRT, MAU_RESSEL_3)
/*! @} */

/*! @name MAU square root indirect addresses */
/*! @{ */
#define MAU_SQRT_FRAC_WORD_REG0   MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_SQRT, MAU_RESSEL_0)
#define MAU_SQRT_INT_WORD_REG0    MAU_IADDR_WORD(MAU_DT_INT,  MAU_MOPC_SQRT, MAU_RESSEL_0)
#define MAU_SQRT_FLT_WORD_REG0    MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_SQRT, MAU_RESSEL_0)

#define MAU_SQRT_FRAC_WORD_REG1   MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_SQRT, MAU_RESSEL_1)
#define MAU_SQRT_INT_WORD_REG1    MAU_IADDR_WORD(MAU_DT_INT,  MAU_MOPC_SQRT, MAU_RESSEL_1)
#define MAU_SQRT_FLT_WORD_REG1    MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_SQRT, MAU_RESSEL_1)

#define MAU_SQRT_FRAC_WORD_REG2   MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_SQRT, MAU_RESSEL_2)
#define MAU_SQRT_INT_WORD_REG2    MAU_IADDR_WORD(MAU_DT_INT,  MAU_MOPC_SQRT, MAU_RESSEL_2)
#define MAU_SQRT_FLT_WORD_REG2    MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_SQRT, MAU_RESSEL_2)

#define MAU_SQRT_FRAC_WORD_REG3   MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_SQRT, MAU_RESSEL_3)
#define MAU_SQRT_INT_WORD_REG3    MAU_IADDR_WORD(MAU_DT_INT,  MAU_MOPC_SQRT, MAU_RESSEL_3)
#define MAU_SQRT_FLT_WORD_REG3    MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_SQRT, MAU_RESSEL_3)
/*! @} */

/*! @name MAU sine indirect addresses */
/*! @{ */
#define MAU_SIN_FRAC_WORD_REG0    MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_SIN, MAU_RESSEL_0)
#define MAU_SIN_FLT_WORD_REG0     MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_SIN, MAU_RESSEL_0)

#define MAU_SIN_FRAC_WORD_REG1    MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_SIN, MAU_RESSEL_1)
#define MAU_SIN_FLT_WORD_REG1     MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_SIN, MAU_RESSEL_1)

#define MAU_SIN_FRAC_WORD_REG2    MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_SIN, MAU_RESSEL_2)
#define MAU_SIN_FLT_WORD_REG2     MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_SIN, MAU_RESSEL_2)

#define MAU_SIN_FRAC_WORD_REG3    MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_SIN, MAU_RESSEL_3)
#define MAU_SIN_FLT_WORD_REG3     MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_SIN, MAU_RESSEL_3)
/*! @} */

/*! @name MAU cosine indirect addresses */
/*! @{ */
#define MAU_COS_FRAC_WORD_REG0    MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_COS, MAU_RESSEL_0)
#define MAU_COS_FLT_WORD_REG0     MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_COS, MAU_RESSEL_0)

#define MAU_COS_FRAC_WORD_REG1    MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_COS, MAU_RESSEL_1)
#define MAU_COS_FLT_WORD_REG1     MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_COS, MAU_RESSEL_1)

#define MAU_COS_FRAC_WORD_REG2    MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_COS, MAU_RESSEL_2)
#define MAU_COS_FLT_WORD_REG2     MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_COS, MAU_RESSEL_2)

#define MAU_COS_FRAC_WORD_REG3    MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_COS, MAU_RESSEL_3)
#define MAU_COS_FLT_WORD_REG3     MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_COS, MAU_RESSEL_3)
/*! @} */

/*! @name MAU arctangent indirect addresses */
/*! @{ */
#define MAU_ATAN_FRAC_WORD_REG0   MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_ATAN, MAU_RESSEL_0)
#define MAU_ATAN_FLT_WORD_REG0    MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_ATAN, MAU_RESSEL_0)

#define MAU_ATAN_FRAC_WORD_REG1   MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_ATAN, MAU_RESSEL_1)
#define MAU_ATAN_FLT_WORD_REG1    MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_ATAN, MAU_RESSEL_1)

#define MAU_ATAN_FRAC_WORD_REG2   MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_ATAN, MAU_RESSEL_2)
#define MAU_ATAN_FLT_WORD_REG2    MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_ATAN, MAU_RESSEL_2)

#define MAU_ATAN_FRAC_WORD_REG3   MAU_IADDR_WORD(MAU_DT_FRAC, MAU_MOPC_ATAN, MAU_RESSEL_3)
#define MAU_ATAN_FLT_WORD_REG3    MAU_IADDR_WORD(MAU_DT_FLT,  MAU_MOPC_ATAN, MAU_RESSEL_3)
/*! @} */

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and De-initialization
 * @{
 */

/*!
 * @brief Enables the MAU peripheral clock.
 *
 * Enables the clock gate in the SIM module for the MAU peripheral.
 * Call this before using any MAU computation functions.
 * Clock control can be disabled at build time by defining
 * FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL.
 */
void MAU_Init(void);

/*!
 * @brief Disables the MAU peripheral clock.
 *
 * Disables the clock gate in the SIM module for the MAU peripheral.
 */
void MAU_Deinit(void);

/*! @} */

/*!
 * @name Sine (SIN) — Float32
 * @{
 */

/*!
 * @brief Computes sine of a float32 input, result in register 0.
 * @param fltPos Input angle in float32 format (full scale 1.0 = pi radians).
 * @return Sine result as float32.
 */
static inline float MAU_SinFlt32Reg0(register float fltPos)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_SIN_FLT_WORD_REG0,ptr
        moveu.w #MAU_RESULT0_ADDR,ptr_result

        fsmst.l fltPos,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes sine of a float32 input, result in register 1.
 * @param fltPos Input angle in float32 format (full scale 1.0 = pi radians).
 * @return Sine result as float32.
 */
static inline float MAU_SinFlt32Reg1(register float fltPos)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_SIN_FLT_WORD_REG1,ptr
        moveu.w #MAU_RESULT1_ADDR,ptr_result

        fsmst.l fltPos,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes sine of a float32 input, result in register 2.
 * @param fltPos Input angle in float32 format (full scale 1.0 = pi radians).
 * @return Sine result as float32.
 */
static inline float MAU_SinFlt32Reg2(register float fltPos)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_SIN_FLT_WORD_REG2,ptr
        moveu.w #MAU_RESULT2_ADDR,ptr_result

        fsmst.l fltPos,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes sine of a float32 input, result in register 3.
 * @param fltPos Input angle in float32 format (full scale 1.0 = pi radians).
 * @return Sine result as float32.
 */
static inline float MAU_SinFlt32Reg3(register float fltPos)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_SIN_FLT_WORD_REG3,ptr
        moveu.w #MAU_RESULT3_ADDR,ptr_result

        fsmst.l fltPos,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}
/*! @} */

/*!
 * @name Sine (SIN) — Frac32 (Q1.31)
 * @{
 */

/*!
 * @brief Computes sine of a frac32 (Q1.31) input, result in register 0.
 * @param i32Pos Input angle in Q1.31 format (full scale 0x7FFFFFFF = pi radians).
 * @return Sine result as int32_t in Q1.31 format.
 */
static inline int32_t MAU_SinFrac32Reg0(register int32_t i32Pos)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32Pos.10,x:MAU_SIN_FRAC_WORD_REG0
        move.l x:MAU_RESULT0_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}

/*!
 * @brief Computes sine of a frac32 (Q1.31) input, result in register 1.
 * @param i32Pos Input angle in Q1.31 format (full scale 0x7FFFFFFF = pi radians).
 * @return Sine result as int32_t in Q1.31 format.
 */
static inline int32_t MAU_SinFrac32Reg1(register int32_t i32Pos)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32Pos.10,x:MAU_SIN_FRAC_WORD_REG1
        move.l x:MAU_RESULT1_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}

/*!
 * @brief Computes sine of a frac32 (Q1.31) input, result in register 2.
 * @param i32Pos Input angle in Q1.31 format (full scale 0x7FFFFFFF = pi radians).
 * @return Sine result as int32_t in Q1.31 format.
 */
static inline int32_t MAU_SinFrac32Reg2(register int32_t i32Pos)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32Pos.10,x:MAU_SIN_FRAC_WORD_REG2
        move.l x:MAU_RESULT2_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}

/*!
 * @brief Computes sine of a frac32 (Q1.31) input, result in register 3.
 * @param i32Pos Input angle in Q1.31 format (full scale 0x7FFFFFFF = pi radians).
 * @return Sine result as int32_t in Q1.31 format.
 */
static inline int32_t MAU_SinFrac32Reg3(register int32_t i32Pos)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32Pos.10,x:MAU_SIN_FRAC_WORD_REG3
        move.l x:MAU_RESULT3_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}
/*! @} */

/*!
 * @name Sine (SIN) — Frac16 (Q1.15)
 * @{
 */

/*!
 * @brief Computes sine of a frac16 (Q1.15) input, result in register 0.
 * @param i16Pos Input angle in Q1.15 format (full scale 0x7FFF = pi radians).
 * @return Sine result as int16_t in Q1.15 format.
 */
static inline int16_t MAU_SinFrac16Reg0(register int16_t i16Pos)
{
    register int16_t i16Out;
    asm(.optimize_iasm on);
    asm{
        move.w i16Pos,x:MAU_SIN_FRAC_WORD_REG0
        move.w x:MAU_RESULT0_ADDR,i16Out
    }
    asm(.optimize_iasm off);
    return i16Out;
}

/*!
 * @brief Computes sine of a frac16 (Q1.15) input, result in register 1.
 * @param i16Pos Input angle in Q1.15 format (full scale 0x7FFF = pi radians).
 * @return Sine result as int16_t in Q1.15 format.
 */
static inline int16_t MAU_SinFrac16Reg1(register int16_t i16Pos)
{
    register int16_t i16Out;
    asm(.optimize_iasm on);
    asm{
        move.w i16Pos,x:MAU_SIN_FRAC_WORD_REG1
        move.w x:MAU_RESULT1_ADDR,i16Out
    }
    asm(.optimize_iasm off);
    return i16Out;
}

/*!
 * @brief Computes sine of a frac16 (Q1.15) input, result in register 2.
 * @param i16Pos Input angle in Q1.15 format (full scale 0x7FFF = pi radians).
 * @return Sine result as int16_t in Q1.15 format.
 */
static inline int16_t MAU_SinFrac16Reg2(register int16_t i16Pos)
{
    register int16_t i16Out;
    asm(.optimize_iasm on);
    asm{
        move.w i16Pos,x:MAU_SIN_FRAC_WORD_REG2
        move.w x:MAU_RESULT2_ADDR,i16Out
    }
    asm(.optimize_iasm off);
    return i16Out;
}

/*!
 * @brief Computes sine of a frac16 (Q1.15) input, result in register 3.
 * @param i16Pos Input angle in Q1.15 format (full scale 0x7FFF = pi radians).
 * @return Sine result as int16_t in Q1.15 format.
 */
static inline int16_t MAU_SinFrac16Reg3(register int16_t i16Pos)
{
    register int16_t i16Out;
    asm(.optimize_iasm on);
    asm{
        move.w i16Pos,x:MAU_SIN_FRAC_WORD_REG3
        move.w x:MAU_RESULT3_ADDR,i16Out
    }
    asm(.optimize_iasm off);
    return i16Out;
}
/*! @} */

/*!
 * @name Cosine (COS) — Float32
 * @{
 */

/*!
 * @brief Computes cosine of a float32 input, result in register 0.
 * @param fltPos Input angle in float32 format (full scale 1.0 = pi radians).
 * @return Cosine result as float32.
 */
static inline float MAU_CosFlt32Reg0(register float fltPos)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_COS_FLT_WORD_REG0,ptr
        moveu.w #MAU_RESULT0_ADDR,ptr_result

        fsmst.l fltPos,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes cosine of a float32 input, result in register 1.
 * @param fltPos Input angle in float32 format (full scale 1.0 = pi radians).
 * @return Cosine result as float32.
 */
static inline float MAU_CosFlt32Reg1(register float fltPos)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_COS_FLT_WORD_REG1,ptr
        moveu.w #MAU_RESULT1_ADDR,ptr_result

        fsmst.l fltPos,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes cosine of a float32 input, result in register 2.
 * @param fltPos Input angle in float32 format (full scale 1.0 = pi radians).
 * @return Cosine result as float32.
 */
static inline float MAU_CosFlt32Reg2(register float fltPos)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_COS_FLT_WORD_REG2,ptr
        moveu.w #MAU_RESULT2_ADDR,ptr_result

        fsmst.l fltPos,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes cosine of a float32 input, result in register 3.
 * @param fltPos Input angle in float32 format (full scale 1.0 = pi radians).
 * @return Cosine result as float32.
 */
static inline float MAU_CosFlt32Reg3(register float fltPos)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_COS_FLT_WORD_REG3,ptr
        moveu.w #MAU_RESULT3_ADDR,ptr_result

        fsmst.l fltPos,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}
/*! @} */

/*!
 * @name Cosine (COS) — Frac32 (Q1.31)
 * @{
 */

/*!
 * @brief Computes cosine of a frac32 (Q1.31) input, result in register 0.
 * @param i32Pos Input angle in Q1.31 format (full scale 0x7FFFFFFF = pi radians).
 * @return Cosine result as int32_t in Q1.31 format.
 */
static inline int32_t MAU_CosFrac32Reg0(register int32_t i32Pos)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32Pos.10,x:MAU_COS_FRAC_WORD_REG0
        move.l x:MAU_RESULT0_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}

/*!
 * @brief Computes cosine of a frac32 (Q1.31) input, result in register 1.
 * @param i32Pos Input angle in Q1.31 format (full scale 0x7FFFFFFF = pi radians).
 * @return Cosine result as int32_t in Q1.31 format.
 */
static inline int32_t MAU_CosFrac32Reg1(register int32_t i32Pos)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32Pos.10,x:MAU_COS_FRAC_WORD_REG1
        move.l x:MAU_RESULT1_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}

/*!
 * @brief Computes cosine of a frac32 (Q1.31) input, result in register 2.
 * @param i32Pos Input angle in Q1.31 format (full scale 0x7FFFFFFF = pi radians).
 * @return Cosine result as int32_t in Q1.31 format.
 */
static inline int32_t MAU_CosFrac32Reg2(register int32_t i32Pos)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32Pos.10,x:MAU_COS_FRAC_WORD_REG2
        move.l x:MAU_RESULT2_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}

/*!
 * @brief Computes cosine of a frac32 (Q1.31) input, result in register 3.
 * @param i32Pos Input angle in Q1.31 format (full scale 0x7FFFFFFF = pi radians).
 * @return Cosine result as int32_t in Q1.31 format.
 */
static inline int32_t MAU_CosFrac32Reg3(register int32_t i32Pos)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32Pos.10,x:MAU_COS_FRAC_WORD_REG3
        move.l x:MAU_RESULT3_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}
/*! @} */

/*!
 * @name Cosine (COS) — Frac16 (Q1.15)
 * @{
 */

/*!
 * @brief Computes cosine of a frac16 (Q1.15) input, result in register 0.
 * @param i16Pos Input angle in Q1.15 format (full scale 0x7FFF = pi radians).
 * @return Cosine result as int16_t in Q1.15 format.
 */
static inline int16_t MAU_CosFrac16Reg0(register int16_t i16Pos)
{
    register int16_t i16Out;
    asm(.optimize_iasm on);
    asm{
        move.w i16Pos,x:MAU_COS_FRAC_WORD_REG0
        move.w x:MAU_RESULT0_ADDR,i16Out
    }
    asm(.optimize_iasm off);
    return i16Out;
}

/*!
 * @brief Computes cosine of a frac16 (Q1.15) input, result in register 1.
 * @param i16Pos Input angle in Q1.15 format (full scale 0x7FFF = pi radians).
 * @return Cosine result as int16_t in Q1.15 format.
 */
static inline int16_t MAU_CosFrac16Reg1(register int16_t i16Pos)
{
    register int16_t i16Out;
    asm(.optimize_iasm on);
    asm{
        move.w i16Pos,x:MAU_COS_FRAC_WORD_REG1
        move.w x:MAU_RESULT1_ADDR,i16Out
    }
    asm(.optimize_iasm off);
    return i16Out;
}

/*!
 * @brief Computes cosine of a frac16 (Q1.15) input, result in register 2.
 * @param i16Pos Input angle in Q1.15 format (full scale 0x7FFF = pi radians).
 * @return Cosine result as int16_t in Q1.15 format.
 */
static inline int16_t MAU_CosFrac16Reg2(register int16_t i16Pos)
{
    register int16_t i16Out;
    asm(.optimize_iasm on);
    asm{
        move.w i16Pos,x:MAU_COS_FRAC_WORD_REG2
        move.w x:MAU_RESULT2_ADDR,i16Out
    }
    asm(.optimize_iasm off);
    return i16Out;
}

/*!
 * @brief Computes cosine of a frac16 (Q1.15) input, result in register 3.
 * @param i16Pos Input angle in Q1.15 format (full scale 0x7FFF = pi radians).
 * @return Cosine result as int16_t in Q1.15 format.
 */
static inline int16_t MAU_CosFrac16Reg3(register int16_t i16Pos)
{
    register int16_t i16Out;
    asm(.optimize_iasm on);
    asm{
        move.w i16Pos,x:MAU_COS_FRAC_WORD_REG3
        move.w x:MAU_RESULT3_ADDR,i16Out
    }
    asm(.optimize_iasm off);
    return i16Out;
}
/*! @} */

/*!
 * @name Arctangent (ATAN) — Float32
 * @{
 */

/*!
 * @brief Computes arctangent of a float32 input, result in register 0.
 * @param fltIn Input value as float32.
 * @return Arctangent result as float32 (full scale 1.0 = pi radians).
 */
static inline float MAU_AtanFlt32Reg0(register float fltIn)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_ATAN_FLT_WORD_REG0,ptr
        moveu.w #MAU_RESULT0_ADDR,ptr_result

        fsmst.l fltIn,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes arctangent of a float32 input, result in register 1.
 * @param fltIn Input value as float32.
 * @return Arctangent result as float32 (full scale 1.0 = pi radians).
 */
static inline float MAU_AtanFlt32Reg1(register float fltIn)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_ATAN_FLT_WORD_REG1,ptr
        moveu.w #MAU_RESULT1_ADDR,ptr_result

        fsmst.l fltIn,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes arctangent of a float32 input, result in register 2.
 * @param fltIn Input value as float32.
 * @return Arctangent result as float32 (full scale 1.0 = pi radians).
 */
static inline float MAU_AtanFlt32Reg2(register float fltIn)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_ATAN_FLT_WORD_REG2,ptr
        moveu.w #MAU_RESULT2_ADDR,ptr_result

        fsmst.l fltIn,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes arctangent of a float32 input, result in register 3.
 * @param fltIn Input value as float32.
 * @return Arctangent result as float32 (full scale 1.0 = pi radians).
 */
static inline float MAU_AtanFlt32Reg3(register float fltIn)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_ATAN_FLT_WORD_REG3,ptr
        moveu.w #MAU_RESULT3_ADDR,ptr_result

        fsmst.l fltIn,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}
/*! @} */

/*!
 * @name Arctangent (ATAN) — Frac32 (Q1.31)
 * @{
 */

/*!
 * @brief Computes arctangent of a frac32 (Q1.31) input, result in register 0.
 * @param i32In Input value as int32_t in Q1.31 format.
 * @return Arctangent result as int32_t in Q1.31 format (full scale 0x7FFFFFFF = pi radians).
 */
static inline int32_t MAU_AtanFrac32Reg0(register int32_t i32In)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32In.10,x:MAU_ATAN_FRAC_WORD_REG0
        move.l x:MAU_RESULT0_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}

/*!
 * @brief Computes arctangent of a frac32 (Q1.31) input, result in register 1.
 * @param i32In Input value as int32_t in Q1.31 format.
 * @return Arctangent result as int32_t in Q1.31 format (full scale 0x7FFFFFFF = pi radians).
 */
static inline int32_t MAU_AtanFrac32Reg1(register int32_t i32In)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32In.10,x:MAU_ATAN_FRAC_WORD_REG1
        move.l x:MAU_RESULT1_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}

/*!
 * @brief Computes arctangent of a frac32 (Q1.31) input, result in register 2.
 * @param i32In Input value as int32_t in Q1.31 format.
 * @return Arctangent result as int32_t in Q1.31 format (full scale 0x7FFFFFFF = pi radians).
 */
static inline int32_t MAU_AtanFrac32Reg2(register int32_t i32In)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32In.10,x:MAU_ATAN_FRAC_WORD_REG2
        move.l x:MAU_RESULT2_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}

/*!
 * @brief Computes arctangent of a frac32 (Q1.31) input, result in register 3.
 * @param i32In Input value as int32_t in Q1.31 format.
 * @return Arctangent result as int32_t in Q1.31 format (full scale 0x7FFFFFFF = pi radians).
 */
static inline int32_t MAU_AtanFrac32Reg3(register int32_t i32In)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32In.10,x:MAU_ATAN_FRAC_WORD_REG3
        move.l x:MAU_RESULT3_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}
/*! @} */

/*!
 * @name Arctangent (ATAN) — Frac16 (Q1.15)
 * @{
 */

/*!
 * @brief Computes arctangent of a frac16 (Q1.15) input, result in register 0.
 * @param i16In Input value as int16_t in Q1.15 format.
 * @return Arctangent result as int16_t in Q1.15 format (full scale 0x7FFF = pi radians).
 */
static inline int16_t MAU_AtanFrac16Reg0(register int16_t i16In)
{
    register int16_t i16Out;
    asm(.optimize_iasm on);
    asm{
        move.w i16In,x:MAU_ATAN_FRAC_WORD_REG0
        move.w x:MAU_RESULT0_ADDR,i16Out
    }
    asm(.optimize_iasm off);
    return i16Out;
}

/*!
 * @brief Computes arctangent of a frac16 (Q1.15) input, result in register 1.
 * @param i16In Input value as int16_t in Q1.15 format.
 * @return Arctangent result as int16_t in Q1.15 format (full scale 0x7FFF = pi radians).
 */
static inline int16_t MAU_AtanFrac16Reg1(register int16_t i16In)
{
    register int16_t i16Out;
    asm(.optimize_iasm on);
    asm{
        move.w i16In,x:MAU_ATAN_FRAC_WORD_REG1
        move.w x:MAU_RESULT1_ADDR,i16Out
    }
    asm(.optimize_iasm off);
    return i16Out;
}

/*!
 * @brief Computes arctangent of a frac16 (Q1.15) input, result in register 2.
 * @param i16In Input value as int16_t in Q1.15 format.
 * @return Arctangent result as int16_t in Q1.15 format (full scale 0x7FFF = pi radians).
 */
static inline int16_t MAU_AtanFrac16Reg2(register int16_t i16In)
{
    register int16_t i16Out;
    asm(.optimize_iasm on);
    asm{
        move.w i16In,x:MAU_ATAN_FRAC_WORD_REG2
        move.w x:MAU_RESULT2_ADDR,i16Out
    }
    asm(.optimize_iasm off);
    return i16Out;
}

/*!
 * @brief Computes arctangent of a frac16 (Q1.15) input, result in register 3.
 * @param i16In Input value as int16_t in Q1.15 format.
 * @return Arctangent result as int16_t in Q1.15 format (full scale 0x7FFF = pi radians).
 */
static inline int16_t MAU_AtanFrac16Reg3(register int16_t i16In)
{
    register int16_t i16Out;
    asm(.optimize_iasm on);
    asm{
        move.w i16In,x:MAU_ATAN_FRAC_WORD_REG3
        move.w x:MAU_RESULT3_ADDR,i16Out
    }
    asm(.optimize_iasm off);
    return i16Out;
}
/*! @} */

/*!
 * @name Square Root (SQRT) — Float32
 * @{
 */

/*!
 * @brief Computes square root of a float32 input, result in register 0.
 * @param fltIn Input value as float32.
 * @return Square root result as float32.
 */
static inline float MAU_SqrtFlt32Reg0(register float fltIn)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_SQRT_FLT_WORD_REG0,ptr
        moveu.w #MAU_RESULT0_ADDR,ptr_result

        fsmst.l fltIn,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes square root of a float32 input, result in register 1.
 * @param fltIn Input value as float32.
 * @return Square root result as float32.
 */
static inline float MAU_SqrtFlt32Reg1(register float fltIn)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_SQRT_FLT_WORD_REG1,ptr
        moveu.w #MAU_RESULT1_ADDR,ptr_result

        fsmst.l fltIn,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes square root of a float32 input, result in register 2.
 * @param fltIn Input value as float32.
 * @return Square root result as float32.
 */
static inline float MAU_SqrtFlt32Reg2(register float fltIn)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_SQRT_FLT_WORD_REG2,ptr
        moveu.w #MAU_RESULT2_ADDR,ptr_result

        fsmst.l fltIn,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes square root of a float32 input, result in register 3.
 * @param fltIn Input value as float32.
 * @return Square root result as float32.
 */
static inline float MAU_SqrtFlt32Reg3(register float fltIn)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_SQRT_FLT_WORD_REG3,ptr
        moveu.w #MAU_RESULT3_ADDR,ptr_result

        fsmst.l fltIn,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}
/*! @} */

/*!
 * @name Square Root (SQRT) — Frac32 (Q1.31)
 * @{
 */

/*!
 * @brief Computes square root of a frac32 (Q1.31) input, result in register 0.
 * @param i32In Input value as int32_t in Q1.31 format.
 * @return Square root result as int32_t in Q1.31 format.
 */
static inline int32_t MAU_SqrtFrac32Reg0(register int32_t i32In)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32In.10,x:MAU_SQRT_FRAC_WORD_REG0
        move.l x:MAU_RESULT0_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}

/*!
 * @brief Computes square root of a frac32 (Q1.31) input, result in register 1.
 * @param i32In Input value as int32_t in Q1.31 format.
 * @return Square root result as int32_t in Q1.31 format.
 */
static inline int32_t MAU_SqrtFrac32Reg1(register int32_t i32In)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32In.10,x:MAU_SQRT_FRAC_WORD_REG1
        move.l x:MAU_RESULT1_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}

/*!
 * @brief Computes square root of a frac32 (Q1.31) input, result in register 2.
 * @param i32In Input value as int32_t in Q1.31 format.
 * @return Square root result as int32_t in Q1.31 format.
 */
static inline int32_t MAU_SqrtFrac32Reg2(register int32_t i32In)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32In.10,x:MAU_SQRT_FRAC_WORD_REG2
        move.l x:MAU_RESULT2_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}

/*!
 * @brief Computes square root of a frac32 (Q1.31) input, result in register 3.
 * @param i32In Input value as int32_t in Q1.31 format.
 * @return Square root result as int32_t in Q1.31 format.
 */
static inline int32_t MAU_SqrtFrac32Reg3(register int32_t i32In)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32In.10,x:MAU_SQRT_FRAC_WORD_REG3
        move.l x:MAU_RESULT3_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}
/*! @} */

/*!
 * @name Square Root (SQRT) — Frac16 (Q1.15)
 * @{
 */

/*!
 * @brief Computes square root of a frac16 (Q1.15) input, result in register 0.
 * @param i16In Input value as int16_t in Q1.15 format.
 * @return Square root result as int16_t in Q1.15 format.
 */
static inline int16_t MAU_SqrtFrac16Reg0(register int16_t i16In)
{
    register int16_t i16Out;
    asm(.optimize_iasm on);
    asm{
        move.w i16In,x:MAU_SQRT_FRAC_WORD_REG0
        move.w x:MAU_RESULT0_ADDR,i16Out
    }
    asm(.optimize_iasm off);
    return i16Out;
}

/*!
 * @brief Computes square root of a frac16 (Q1.15) input, result in register 1.
 * @param i16In Input value as int16_t in Q1.15 format.
 * @return Square root result as int16_t in Q1.15 format.
 */
static inline int16_t MAU_SqrtFrac16Reg1(register int16_t i16In)
{
    register int16_t i16Out;
    asm(.optimize_iasm on);
    asm{
        move.w i16In,x:MAU_SQRT_FRAC_WORD_REG1
        move.w x:MAU_RESULT1_ADDR,i16Out
    }
    asm(.optimize_iasm off);
    return i16Out;
}

/*!
 * @brief Computes square root of a frac16 (Q1.15) input, result in register 2.
 * @param i16In Input value as int16_t in Q1.15 format.
 * @return Square root result as int16_t in Q1.15 format.
 */
static inline int16_t MAU_SqrtFrac16Reg2(register int16_t i16In)
{
    register int16_t i16Out;
    asm(.optimize_iasm on);
    asm{
        move.w i16In,x:MAU_SQRT_FRAC_WORD_REG2
        move.w x:MAU_RESULT2_ADDR,i16Out
    }
    asm(.optimize_iasm off);
    return i16Out;
}

/*!
 * @brief Computes square root of a frac16 (Q1.15) input, result in register 3.
 * @param i16In Input value as int16_t in Q1.15 format.
 * @return Square root result as int16_t in Q1.15 format.
 */
static inline int16_t MAU_SqrtFrac16Reg3(register int16_t i16In)
{
    register int16_t i16Out;
    asm(.optimize_iasm on);
    asm{
        move.w i16In,x:MAU_SQRT_FRAC_WORD_REG3
        move.w x:MAU_RESULT3_ADDR,i16Out
    }
    asm(.optimize_iasm off);
    return i16Out;
}
/*! @} */

/*!
 * @name Square Root (SQRT) — Int32
 * @{
 */

/*!
 * @brief Computes square root of an int32 input, result in register 0.
 * @param i32In Input value as int32_t.
 * @return Square root result as int32_t.
 */
static inline int32_t MAU_SqrtInt32Reg0(register int32_t i32In)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32In.10,x:MAU_SQRT_INT_WORD_REG0
        move.l x:MAU_RESULT0_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}

/*!
 * @brief Computes square root of an int32 input, result in register 1.
 * @param i32In Input value as int32_t.
 * @return Square root result as int32_t.
 */
static inline int32_t MAU_SqrtInt32Reg1(register int32_t i32In)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32In.10,x:MAU_SQRT_INT_WORD_REG1
        move.l x:MAU_RESULT1_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}

/*!
 * @brief Computes square root of an int32 input, result in register 2.
 * @param i32In Input value as int32_t.
 * @return Square root result as int32_t.
 */
static inline int32_t MAU_SqrtInt32Reg2(register int32_t i32In)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32In.10,x:MAU_SQRT_INT_WORD_REG2
        move.l x:MAU_RESULT2_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}

/*!
 * @brief Computes square root of an int32 input, result in register 3.
 * @param i32In Input value as int32_t.
 * @return Square root result as int32_t.
 */
static inline int32_t MAU_SqrtInt32Reg3(register int32_t i32In)
{
    register int32_t i32Out;
    asm(.optimize_iasm on);
    asm{
        move.l i32In.10,x:MAU_SQRT_INT_WORD_REG3
        move.l x:MAU_RESULT3_ADDR,i32Out
    }
    asm(.optimize_iasm off);
    return i32Out;
}
/*! @} */

/*!
 * @name Inverse Square Root (ISQRT) — Float32
 * @{
 */

/*!
 * @brief Computes inverse (reciprocal) square root of a float32 input, result in register 0.
 * @param fltIn Input value as float32.
 * @return Inverse square root result as float32 (1/sqrt(fltIn)).
 */
static inline float MAU_InvSqrtFlt32Reg0(register float fltIn)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_ISQRT_FLT_WORD_REG0,ptr
        moveu.w #MAU_RESULT0_ADDR,ptr_result

        fsmst.l fltIn,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes inverse (reciprocal) square root of a float32 input, result in register 1.
 * @param fltIn Input value as float32.
 * @return Inverse square root result as float32 (1/sqrt(fltIn)).
 */
static inline float MAU_InvSqrtFlt32Reg1(register float fltIn)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_ISQRT_FLT_WORD_REG1,ptr
        moveu.w #MAU_RESULT1_ADDR,ptr_result

        fsmst.l fltIn,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes inverse (reciprocal) square root of a float32 input, result in register 2.
 * @param fltIn Input value as float32.
 * @return Inverse square root result as float32 (1/sqrt(fltIn)).
 */
static inline float MAU_InvSqrtFlt32Reg2(register float fltIn)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_ISQRT_FLT_WORD_REG2,ptr
        moveu.w #MAU_RESULT2_ADDR,ptr_result

        fsmst.l fltIn,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes inverse (reciprocal) square root of a float32 input, result in register 3.
 * @param fltIn Input value as float32.
 * @return Inverse square root result as float32 (1/sqrt(fltIn)).
 */
static inline float MAU_InvSqrtFlt32Reg3(register float fltIn)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_ISQRT_FLT_WORD_REG3,ptr
        moveu.w #MAU_RESULT3_ADDR,ptr_result

        fsmst.l fltIn,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}
/*! @} */

/*!
 * @name Reciprocal (RECIP) — Float32
 * @{
 */

/*!
 * @brief Computes reciprocal of a float32 input, result in register 0.
 * @param fltIn Input value as float32.
 * @return Reciprocal result as float32 (1/fltIn).
 */
static inline float MAU_RecipFlt32Reg0(register float fltIn)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_RECIP_FLT_WORD_REG0,ptr
        moveu.w #MAU_RESULT0_ADDR,ptr_result

        fsmst.l fltIn,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes reciprocal of a float32 input, result in register 1.
 * @param fltIn Input value as float32.
 * @return Reciprocal result as float32 (1/fltIn).
 */
static inline float MAU_RecipFlt32Reg1(register float fltIn)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_RECIP_FLT_WORD_REG1,ptr
        moveu.w #MAU_RESULT1_ADDR,ptr_result

        fsmst.l fltIn,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes reciprocal of a float32 input, result in register 2.
 * @param fltIn Input value as float32.
 * @return Reciprocal result as float32 (1/fltIn).
 */
static inline float MAU_RecipFlt32Reg2(register float fltIn)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_RECIP_FLT_WORD_REG2,ptr
        moveu.w #MAU_RESULT2_ADDR,ptr_result

        fsmst.l fltIn,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}

/*!
 * @brief Computes reciprocal of a float32 input, result in register 3.
 * @param fltIn Input value as float32.
 * @return Reciprocal result as float32 (1/fltIn).
 */
static inline float MAU_RecipFlt32Reg3(register float fltIn)
{
    register float fltOut;
    register float *ptr;
    register float *ptr_result;
    asm(.optimize_iasm on);
    asm{
        moveu.w #MAU_RECIP_FLT_WORD_REG3,ptr
        moveu.w #MAU_RESULT3_ADDR,ptr_result

        fsmst.l fltIn,x:(ptr+0)
        fsmld.l x:(ptr_result),fltOut

    }
    asm(.optimize_iasm off);
    return fltOut;
}
/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_MAU_H_ */
