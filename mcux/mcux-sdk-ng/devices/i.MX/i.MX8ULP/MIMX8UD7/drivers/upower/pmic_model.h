/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted (subject to the limitations in the disclaimer
 * below) provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * o Neither the name of NXP nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY
 * THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT
 * NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef __PMIC_MODEL_H__
#define __PMIC_MODEL_H__

#include <stdint.h>

extern int pmic_get_ID(void);

extern int pmic_get_ver(void);

extern void pmic_init(void);

/**
 * This is a unified interface to adjust the voltage of one BUCK or LDO
 * For BUCK, DVS rail, can be adjusted according to different modes,
 * adjust several kinds of voltage
 * for example, refer to pca8460, BUCK2 and BUCK3, BUCK2OUT_DVS0 - BUCK2OUT_DVS7
 * So, when call this API, need pass argument mode
 *
 * @rail: the rail number need to be adjust
 * @mode: the value of PMIC mode pins MODE[2:0]
 *
 * Return: if success, return the voltage of rail at mode
 *         if failed, return -1, due to the wrong rail or other reasons.
 */
extern int pmic_get_rail_voltage(uint8_t rail, uint8_t mode);

/**
 * This is a unified interface to adjust the voltage of one BUCK or LDO
 * For BUCK, DVS rail, can be adjusted according to different modes,
 * adjust several kinds of voltage
 * for example, refer to pca8460, BUCK2 and BUCK3, BUCK2OUT_DVS0 - BUCK2OUT_DVS7
 * So, when call this API, need pass argument mode
 *
 * @rail: the rail number need to be adjust
 * @mode: the value of PMIC mode pins MODE[2:0]
 * @voltage: the target voltage
 *
 * Return: return 0 if success, return -1 if failed, due to wrong rail, wrong voltage or other reasons
 */
extern int pmic_set_rail_voltage(uint8_t rail, uint8_t mode, int voltage);

extern int pmic_get_rail_mode(uint8_t rail);

extern int pmic_set_rail_mode(uint8_t rail, uint8_t val);

/**
 * Because if configure pmic ic iomux on m33 side,
 * but because uPower enable I2C master very early,
 * if timing changes, the SDA/SCL level changes
 * may cause impact on I2C master
 * So, we need to configure pmic ic iomux on uPower side.
 * Customer shall maintain the pmic driver,
 * if customer re-design and change pmic iomux selection,
 * customer need to configure pmic ic iomux by themselve
 *
 * User have to implement this function.
 */
extern void configure_pmic_ic_iomux(void);

/**
 * M33/A35 user application shall configure pmic data
 * Actually, uPower firmware doesn't know the detail config data,
 * because customer may use different PMIC chip
 * So, pass a void * argument to pmic driver library
 *
 * @pmic_config_data: point to the memory of pmic data structure
 *
 * Return: return 0 if success
 *         if failed, return -1, due to wrong configuration data
 */
extern int pmic_config(void *pmic_config_data);

#define PMIC_CONFIG_TAG 0x706D6963U

#define MAX_PMIC_SET_REG_TABLE_SIZE 0x16U

struct pmic_reg_addr_data
{
    uint32_t reg;
    uint32_t data;
};

struct pmic_config_struct
{
    uint32_t cfg_tag;
    uint32_t cfg_reg_size;
    struct pmic_reg_addr_data reg_addr_data_array[MAX_PMIC_SET_REG_TABLE_SIZE];
};

/**
 * trigger pmic code reset
 */
extern int pmic_cold_reset(void);

#endif
