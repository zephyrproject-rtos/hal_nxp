/*
 * Copyright 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*==========================================================================
Interface Definitions for CM33-CE Driver
==========================================================================*/
#ifndef FSL_CE_IF_H
#define FSL_CE_IF_H

#define CE_CMD_MAX_ARGS     6
#define CE_CMD_MAX_CMDS_ZVQ 18

#define CE_STATUS_BUSY  0xB054U
#define CE_STATUS_IDLE  0xFF00U

/* CMD name definitions */
typedef enum
{
    kCE_CmdModeOneNonBlocking      = 0, /* one command non-blocking */
    kCE_CmdModeMultipleNonBlocking = 1, /* multi-command non-blocking */
    kCE_CmdModeOneBlocking         = 2, /* one command blocking */
    kCE_CmdModeMultipleBlocking    = 3  /* multi-command blocking */
} ce_cmd_mode_t;

/* CMD name definitions */
typedef enum
{
    /* Legacy PQ Matrix functions */
    kCE_Cmd_MAT_ADD_Q15,
    kCE_Cmd_MAT_ADD_Q31,
    kCE_Cmd_MAT_ADD_F32,
    kCE_Cmd_MAT_SUB_Q31,
    kCE_Cmd_MAT_SUB_F32,
    kCE_Cmd_MAT_MULT_Q15,
    kCE_Cmd_MAT_MULT_Q31,
    kCE_Cmd_MAT_MULT_F32,
    kCE_Cmd_MAT_MULT_CF32,
    kCE_Cmd_MAT_HADAMARDMULT_F32,
    kCE_Cmd_MAT_INV_F32,
    kCE_Cmd_MAT_TRANS_Q15,
    kCE_Cmd_MAT_TRANS_Q31,
    kCE_Cmd_MAT_TRANS_F32,
    kCE_Cmd_MAT_SCALE_Q15,
    kCE_Cmd_MAT_SCALE_Q31,
    kCE_Cmd_MAT_SCALE_F32,

    /* Legacy PQ Math functions */
    kCE_Cmd_SQRT_Q15,
    kCE_Cmd_SQRT_Q31,
    kCE_Cmd_SIN_Q15,
    kCE_Cmd_SIN_Q31,
    kCE_Cmd_SIN_F32,
    kCE_Cmd_COS_Q15,
    kCE_Cmd_COS_Q31,
    kCE_Cmd_COS_F32,

    /* Legacy PQ Filter functions */
    kCE_Cmd_FIR_Q15,
    kCE_Cmd_FIR_Q31,
    kCE_Cmd_FIR_F32,
    kCE_Cmd_CONV_Q15,
    kCE_Cmd_CONV_Q31,
    kCE_Cmd_CONV_F32,
    kCE_Cmd_CORR_Q15,
    kCE_Cmd_CORR_Q31,
    kCE_Cmd_CORR_F32,

    /* Legacy PQ Transform functions */
    kCE_Cmd_RFFT_Q15,
    kCE_Cmd_RFFT_Q31,
    kCE_Cmd_CFFT_Q15,
    kCE_Cmd_CFFT_Q31,
    kCE_Cmd_IFFT_Q15,
    kCE_Cmd_IFFT_Q31,
    kCE_Cmd_DCT4_Q15,
    kCE_Cmd_DCT4_Q31,

    /* New Transform functions */
    kCE_Cmd_RFFT_F16,
    kCE_Cmd_RFFT_F32,
    kCE_Cmd_CFFT_F16,
    kCE_Cmd_CFFT_F32,
    kCE_Cmd_IFFT_F16,
    kCE_Cmd_IFFT_F32,

    /* Advanced Linear Algebra */
    kCE_Cmd_MAT_INV_HERM_CF32,
    kCE_Cmd_MAT_INV_CF32,
    kCE_Cmd_MAT_INV_SYMM_F32,
    kCE_Cmd_MAT_EVD_HERM_CF32,
    kCE_Cmd_MAT_EVD_SYMM_F32,
    kCE_Cmd_MAT_EVD_CF32,
    kCE_Cmd_MAT_EVD_F32,
    kCE_Cmd_MAT_CHOL_CF32,

    /* Misc CMD */
    kCE_Cmd_NULLCMD = 0xAA, /* NULL command */
    kCE_Cmd_ZVCOPY  = 0xAB  /* COPY */
} ce_cmd_t;

/* structure defining the ce command buffer configuration */
typedef struct
{
    unsigned int *buffer_base_ptr;
    unsigned int *next_buffer_ptr;
    int *status_buffer_ptr;
    unsigned int n_cmd;
    ce_cmd_mode_t cmdmode;
} ce_cmdbuffer_t;

/* structure for a single zv/ce command */
typedef struct
{
    unsigned short n_ptr_args;            /* number of pointer arguments */
    unsigned short n_param_args;          /* number of integer arguments */
    void *arg_ptr_array[CE_CMD_MAX_ARGS]; /* array of pointer arguments */
    int arg_param_array[CE_CMD_MAX_ARGS]; /* array of integer arguments */
} ce_cmdstruct_t;

#endif /*FSL_CE_IF_H*/
