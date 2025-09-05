/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_romapi_otp.h"
#include "fsl_romapi.h"

#define OCOTP_API_TREE ((ocotp_driver_t *)(((uint32_t *)ROM_API_TREE_ADDR)[12]))

#define kStatus_Secure_Success         ((status_t)0x5ac3c35a)
#define kStatus_Secure_Fail            ((status_t)0xc35ac35a)
#define kStatus_Secure_InvalidArgument ((status_t)0xc35a5ac3)

/*!
 * @brief Initialize OCOTP controller
 */
uint32_t otp_version(void)
{
    return (OCOTP_API_TREE->version);
}

/*!
 * @brief Initialize OCOTP controller
 */
void otp_init(uint32_t src_clk_freq)
{
    assert(OCOTP_API_TREE);
    OCOTP_API_TREE->init(src_clk_freq);
}

/*!
 * @brief Deinitialize OCOTP controller
 */
status_t otp_deinit(void)
{
    status_t ret;
    assert(OCOTP_API_TREE);
    ret = OCOTP_API_TREE->deinit();

    if ((ret == kStatus_Secure_Success) || (ret == kStatus_Success))
    {
        return kStatus_Success;
    }
    else
    {
        return kStatus_Fail;
    }
}

/*!
 * @brief Reads a efuse word
 */
status_t otp_fuse_read(uint32_t addr, uint32_t *data)
{
    status_t ret;
    assert(OCOTP_API_TREE);
    ret = OCOTP_API_TREE->p_efuse_read(addr, data);

    if ((ret == kStatus_Secure_Success) || (ret == kStatus_Success))
    {
        return kStatus_Success;
    }
    else
    {
        return kStatus_Fail;
    }
}

/*!
 * @brief Programs a efuse word
 */
status_t otp_fuse_program(uint32_t addr, uint32_t data)
{
    status_t ret;

    assert(OCOTP_API_TREE);
    ret = OCOTP_API_TREE->p_efuse_program(addr, data);

    if ((ret == kStatus_Secure_Success) || (ret == kStatus_Success))
    {
        return kStatus_Success;
    }
    else
    {
        return kStatus_Fail;
    }
}
