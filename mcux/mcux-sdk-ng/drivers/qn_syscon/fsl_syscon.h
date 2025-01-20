/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_SYSCON_H_
#define FSL_SYSCON_H_

#include "fsl_common.h"

/*!
 * @addtogroup qn_syscon
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.qn_syscon"
#endif

/*! @name Driver version */
/*! @{ */
/*! @brief SYSCON driver version 2.0.0. */
#define FSL_SYSCON_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @brief   Sets load cap for on bard crystal
 * @param   base            The base of SYSCON peripheral on the chip
 * @param   xtalType        XTAL type (1 : 16/32MHz, 0: 32KHz)
 * @param   loadCap         load cap value
 * @return  Nothing
 */
__STATIC_INLINE void SYSCON_SetLoadCap(SYSCON_Type *base, uint8_t xtalType, uint8_t loadCap)
{
    if (xtalType)
    {
        base->ANA_CTRL0 =
            (SYSCON->ANA_CTRL0 & ~(SYSCON_ANA_CTRL0_XTAL_EXTRA_CAP_MASK | SYSCON_ANA_CTRL0_XTAL_LOAD_CAP_MASK |
                                   SYSCON_ANA_CTRL0_XTAL_AMP_MASK)) |
            ((loadCap & 0x7F) << SYSCON_ANA_CTRL0_XTAL_LOAD_CAP_SHIFT) | SYSCON_ANA_CTRL0_XTAL_AMP(0x2);
    }
    else
    {
        base->XTAL32K_CTRL = (SYSCON->XTAL32K_CTRL & ~(SYSCON_XTAL32K_CTRL_XTAL32K_EXTRA_CAP_MASK |
                                                       SYSCON_XTAL32K_CTRL_XTAL32K_LOAD_CAP_MASK)) |
                             ((loadCap & 0x7F) << SYSCON_XTAL32K_CTRL_XTAL32K_LOAD_CAP_SHIFT);
    }
}

/*! @} */

#if defined(__cplusplus)
}
#endif

#endif /* FSL_SYSCON_H_ */
