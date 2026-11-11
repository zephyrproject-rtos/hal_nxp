/*! *********************************************************************************
* Copyright (c) 2004 - 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2024 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef SMAC_CONFIG_H_
#define SMAC_CONFIG_H_

/* BEGIN SMAC Config Options Definition */
#define CCA_BEFORE_TX              (FALSE)
#define gMaxRetriesAllowed_c       ( 0x05 )
//Make sure gMaxBackoffTime_c is of value (1<<n)-1. Ex: (1<<3)-1 = 7, (1<<4)-1 = 15;
#define gMaxBackoffTime_c          ( 0x1F )
#define gMinBackoffTime_c          ( 0x00 )
/* END SMAC Config Options Definition */
#endif /* SMAC_CONFIG_H_ */
