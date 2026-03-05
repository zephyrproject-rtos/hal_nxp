/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "EmbeddedTypes.h"
#include "fwk_platform_definitions.h"
#include "fwk_platform_mcu_nbu_common.h"
#include "fwk_hal_macros.h"
/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */
#ifndef gPlatformTstmr0HasClkControl_d
#define gPlatformTstmr0HasClkControl_d 0 /* Unless otherwise defined , default to no clock control for 1MHz counter */
#endif

/* -------------------------------------------------------------------------- */
/*                         Private type definitions                           */
/* -------------------------------------------------------------------------- */

/*!
 * TSTMR_Peripheral_Access_Layer TSTMR Peripheral Access Layer
 *
 */

/** TSTMR - Register Layout Typedef */
typedef struct
{
    __I uint32_t L; /**< TIMESTAMP Low, offset: 0x0 */
    __I uint32_t H; /**< TIMESTAMP High, offset: 0x4 */
} FWK_TSTMR_Type;

/* -------------------------------------------------------------------------- */
/*                         Public memory declarations                         */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Private memory                               */
/* -------------------------------------------------------------------------- */
/*! \brief Pointers to Timer bases for each instance. */
static const uint32_t tstmrBases[FWK_TSTMR_NB_INST] = {
    FWK_TSRMR0_BASE,
#if (FWK_TSTMR_NB_INST > 1)
    FWK_TSRMR1_BASE,
#endif
};

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Returns TSTMR module base address per instance identifier
 *
 * \param tstmrId TSTMR instance id - 0 on all MCU/NBUs, 1 on KW43 only.
 *
 * \return FWK_TSTMR_Type * pointer on TSTMR instance
 */

STATIC uint32_t PLATFORM_TSTMR_GetBase(uint8_t tstmrId)
{
    uint32_t base = 0UL; /* NULL pointer if instance ID is invalid */
    if (tstmrId < FWK_TSTMR_NB_INST)
    {
        base = tstmrBases[tstmrId];
    }
    return base;
}

/*!
 * \brief Configure and enable TSTMR0 clock (1MHz instance only)
 *
 */
static void CLOCK_EnableTstmr0Clock(void)
{
#if defined gPlatformTstmr0HasClkControl_d && (gPlatformTstmr0HasClkControl_d > 0)
    uint32_t reg;
    reg = *FWK_MRCC_TSTMR0_REG;
    *FWK_MRCC_TSTMR0_REG |= FWK_MRCC_TSTMR0_RSTB_MASK;

    reg &= ~(FWK_MRCC_TSTMR0_MUX_MASK | FWK_MRCC_TSTMR0_CC_MASK);
    reg |= (FWK_MRCC_TSTMR0_MUX(FwkTSTMR0_ClkSel_1MHz) | FWK_MRCC_TSTMR0_CC(FWK_MRCC_TSTMR0_CLK_EN_NO_LP_STALL));

    /*
     * If clock is already enabled, first disable it, then set the clock
     * source and re-enable it.
     */
    *FWK_MRCC_TSTMR0_REG = reg & (~FWK_MRCC_TSTMR0_CC_MASK);
    *FWK_MRCC_TSTMR0_REG = reg;
    /* Make sure disable clock finished */
    __ISB();
    __DSB();

#else
    if (0x0u == (*FWK_MRCC_TSTMR0_REG & FWK_MRCC_TSTMR0_CC_MASK))
    {
        /* Not started yet */
        *FWK_MRCC_TSTMR0_REG &= (~FWK_MRCC_TSTMR0_CC_MASK);
        *FWK_MRCC_TSTMR0_REG |= FWK_MRCC_TSTMR0_CC(FWK_MRCC_TSTMR0_CLK_EN_NO_LP_STALL);

        *FWK_MRCC_TSTMR0_REG |= FWK_MRCC_TSTMR0_RSTB_MASK;
        /* Make sure disable clock finished */
        __ISB();
        __DSB();
    }
#endif
}

/*!
 * \brief Disable TSTMR0 clock (1MHz instance only)
 *
 */
static void CLOCK_DisableTstmr0Clock(void)
{
    if (0x0u != (*FWK_MRCC_TSTMR0_REG & FWK_MRCC_TSTMR0_CC_MASK))
    {
        /* Check if clock is currently enabled */
        *FWK_MRCC_TSTMR0_REG &= (~FWK_MRCC_TSTMR0_CC_MASK);
        *FWK_MRCC_TSTMR0_REG &= ~FWK_MRCC_TSTMR0_RSTB_MASK;
        /* Make sure disable clock finished */
        __ISB();
        __DSB();
    }
}

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

/*
 * Enable or disable TSTMR.
 *
 * This function initializes the TSTMR module.
 *
 */
void PLATFORM_TSTMR_Enable(uint8_t tstmrId, bool enablenDisable)
{
    if (tstmrId == 0u)
    {
        /* Only TSTMR0 has clock control capability */
        if (enablenDisable)
        {
            CLOCK_EnableTstmr0Clock();
        }
        else
        {
            CLOCK_DisableTstmr0Clock();
        }
    }
    else
    {
        /* TSTMR1 or other instances - no clock control needed */
    }
}

/*!
 *
 * Behavior depends on gPlatformTstmr32Bit_d configuration.
 * Use of gPlatformTstmr32Bit_d should be preferred because it allows a much simpler / faster
 * implementation, nonetheless the code performing the read of MSB bits [32..55] is kept in case it
 * becomes useful.
 * The  counter wrap around value to be considered depends whether the timestamp is 32-bit or 56-bit.
 *
 */
uint64_t PLATFORM_TSTMR_ReadTimeStamp(uint8_t tstmrId)
{
    FWK_TSTMR_Type *base = (FWK_TSTMR_Type *)PLATFORM_TSTMR_GetBase(tstmrId);
    uint64_t        timeStamp;

    if (base != NULL)
    {
#if defined gPlatformTstmr32Bit_d && (gPlatformTstmr32Bit_d > 0)
        /* LOW register can be read separately, however each read triggers the HW latch of the HIGH register */
        timeStamp = (uint64_t)base->L;
#else
        /* The actual implementation reading the full 56-bit timestamp */
        if (tstmrId < FWK_TSTMR_NB_INST)
        {
            TSTMR_Type *base    = tstmrBases[tstmrId];
            uint32_t    primask = DisableGlobalIRQ();

            /* Need to read LSB and MSB registers twice to ensure consistency,
             * indeed in some rare cases the MSB may get updated before the LSB has wrapped-around */
            uint32_t l1, l2;
            uint32_t h1, h2;
            l1 = base->L;
            __DMB();
            h1 = base->H & FWK_TSTMR_H_VALUE_MASK;

            __DMB();
            l2 = base->L;
            __DMB();
            h2 = base->H & FWK_TSTMR_H_VALUE_MASK;

            EnableGlobalIRQ(primask);

            if (l2 < l1)
            {
                /* Wrap (or early-carry window): use the pair that follows L2 */
                timeStamp = (((uint64_t)h2) << 32) | l2;
            }
            else
            {
                /* No wrap between L1 and L2: use the earlier consistent pair */
                timeStamp = (((uint64_t)h1) << 32) | l1;
            }
        }
#endif
    }
    else
    {
        timeStamp = 0ULL;
    }
    return timeStamp;
}

/*!
 *  Compute number of ticks between 2 timestamps expressed in number of TSTMR ticks
 *
 */
uint64_t PLATFORM_GetTstmrDeltaTicks(uint64_t timestamp0, uint64_t timestamp1)
{
    uint64_t delta_ticks;

    timestamp0 &= PLATFORM_TSTMR_MAX_VAL; /* sanitize arguments */
    timestamp1 &= PLATFORM_TSTMR_MAX_VAL;

    if (timestamp1 >= timestamp0)
    {
        delta_ticks = timestamp1 - timestamp0;
    }
    else
    {
        /* In case the 56-bit counter has wrapped */
        delta_ticks = PLATFORM_TSTMR_MAX_VAL - timestamp0 + timestamp1 + 1ULL;
    }
    return delta_ticks;
}
