/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_xbara.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_xbara"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Get the XBARA instance from peripheral base address.
 *
 * @param base XBARA peripheral base address.
 * @return XBARA instance.
 */
static uint32_t XBARA_GetInstance(XBARA_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/* Array of XBARA peripheral base address. */
static XBARA_Type *const s_xbaraBases[] = XBARA_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/* Array of XBARA clock name. */
static const clock_ip_name_t s_xbaraClock[] = XBARA_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/

static uint32_t XBARA_GetInstance(XBARA_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_xbaraBases); instance++)
    {
        if (s_xbaraBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_xbaraBases));

    return instance;
}

/*!
 * brief Initializes the XBARA module.
 *
 * This function un-gates the XBARA clock.
 *
 * param base XBARA peripheral address.
 */
void XBARA_Init(XBARA_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable XBARA module clock. */
    CLOCK_EnableClock(s_xbaraClock[XBARA_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Shuts down the XBARA module.
 *
 * This function disables XBARA clock.
 *
 * param base XBARA peripheral address.
 */
void XBARA_Deinit(XBARA_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable XBARA module clock. */
    CLOCK_DisableClock(s_xbaraClock[XBARA_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Gets the active edge detection status.
 *
 * This function gets the active edge detect status of all XBARA_OUTs. If the
 * active edge occurs, the return value is asserted. When the interrupt or the DMA
 * functionality is enabled for the XBARA_OUTx, this field is 1 when the interrupt
 * or DMA request is asserted and 0 when the interrupt or DMA request has been
 * cleared.
 *
 * param base XBARA peripheral address.
 * return ORed value from all status flag from @ref xbara_status_flag_t.
 */
uint16_t XBARA_GetStatusFlags(XBARA_Type *base)
{
    uint16_t flags = 0x0U;

    /* Get the status flags from CTRLx register. */
    flags |= ((base->CTRL0 & XBARA_CTRLx_STS_MASK) >> 4U);
    flags |= (uint16_t)((base->CTRL1 & XBARA_CTRLx_STS_MASK) >> 3U);

    return flags;
}

/*!
 * brief Configures the XBARA control register.
 *
 * This function configures an XBARA control register. The active edge detection
 * and the DMA/IRQ function on the corresponding XBARA output can be set.
 *
 * Example:
   code
   xbara_control_config_t userConfig;
   userConfig.activeEdge = kXBARA_EdgeRising;
   userConfig.requestType = kXBARA_RequestInterruptEnable;
   XBARA_SetOutputSignalConfig(XBARA, kXBARA_OutputDMAMUX18, &userConfig);
   endcode
 *
 * param base XBARA peripheral address.
 * param output XBARA output number.
 * param controlConfig Pointer to structure that keeps configuration of control register.
 */
void XBARA_SetOutputSignalConfig(XBARA_Type *base,
                                 xbar_output_signal_t eOutput,
                                 const xbara_control_config_t *psControlConfig)
{
    XBARA_SetActiveEdgeDetectMode(base, eOutput, psControlConfig->eActiveEdge);
    XBARA_SetInterruptDMARequestMode(base, eOutput, psControlConfig->eRequestType);
}
