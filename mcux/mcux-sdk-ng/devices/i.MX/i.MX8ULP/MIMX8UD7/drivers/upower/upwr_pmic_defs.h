/*
 * Copyright 2021 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __UPWR_PMIC_DEFS__
#define __UPWR_PMIC_DEFS__

#include <stdlib.h>
#include <assert.h>

#ifndef X86_TEST
#include <stdio.h>
#define printf(...) 
#endif

//===========================================================================
// PMIC initialization config
//===========================================================================

#define UPWR_PMIC_NAME_SIZE         16
#define UPWR_PMIC_VERS_SIZE         8
#define UPWR_PMIC_DRV_VERS_SIZE     8

typedef struct {
  // PMIC info
  char                      name[UPWR_PMIC_NAME_SIZE];
  char                      vers[UPWR_PMIC_VERS_SIZE];
  uint32_t                  feat;
  // Driver info
  char                      drv_vers[UPWR_PMIC_DRV_VERS_SIZE];
  uint32_t                  drv_feat;
  // I2C config
  uint16_t                  i2c_addr;
  uint32_t                  i2c_baud;
  // Smart mode config
  struct {                    
    uint32_t                  presc   : 8;
    uint32_t                  hi_time : 8;
    uint32_t                  lo_time : 8;
    uint32_t                  ena     : 1;
    uint32_t                  cntrl3  : 1;
  }                         smart_cfg; 
} upwr_pmic_generic_cfg_t;

typedef struct {
} upwr_pmic_custom_cfg_t;

typedef struct {
  upwr_pmic_generic_cfg_t        generic_cfg;
  upwr_pmic_custom_cfg_t         custom_cfg;
} upwr_pmic_init_cfg_t;

#endif /* __UPWR_PMIC_DEFS__ */
