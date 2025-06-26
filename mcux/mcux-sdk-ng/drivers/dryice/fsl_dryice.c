/*
 * Copyright (c) 2015-2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_dryice.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dryice"
#endif

/* all bits defined in the Write Access Control Register. Same positions as Lock Register. */
#define DRYICE_ALL_WAC_MASK 0x00FF3FFFu

/* all bits defined in the Interrupt Enable Register. */
#define DRYICE_ALL_IER_MASK 0x00FF03FDu

/* all bits defined in the Tamper Enable Register. */
#define DRYICE_ALL_TER_MASK 0x00FF03FCu

/*******************************************************************************
 * Code
 ******************************************************************************/
static bool dryice_IsRegisterWriteAllowed(DRY_Type *base, uint32_t mask)
{
    bool retval;

    retval = false;
    mask   = mask & DRYICE_ALL_WAC_MASK;

    /* specified LR and WAC bit(s) must be set */
    if ((mask == (mask & base->LR)) && (mask == (mask & base->WAC)))
    {
        retval = true;
    }
    return retval;
}

static bool dryice_IsRegisterReadAllowed(DRY_Type *base, uint32_t mask)
{
    bool retval;

    retval = false;
    mask   = mask & DRYICE_ALL_WAC_MASK;

    /* specified RAC bit(s) must be set */
    if (mask == (mask & base->RAC))
    {
        retval = true;
    }
    return retval;
}

static bool dryice_IsKeyReadAllowed(DRY_Type *base, uint32_t keyRegisters)
{
    bool retval;
    uint32_t mask;
    uint32_t drySrac;
    uint32_t drySkrlr;
    uint32_t i;

    retval = true;
    mask   = 1u;

    /* limit argument to maximum */
    if (keyRegisters > ARRAY_SIZE(base->SKR))
    {
        keyRegisters = ARRAY_SIZE(base->SKR);
    }

    /* specified SRAC and SKRLR bit(s) must be set */
    drySrac  = base->SRAC;
    drySkrlr = base->SKRLR;
    for (i = 0; i < keyRegisters; i++)
    {
        if (((mask & drySrac) == 0U) || ((mask & drySkrlr) == 0U))
        {
            retval = false;
            break;
        }
    }

    return retval;
}

static bool dryice_IsKeyWriteAllowed(DRY_Type *base, uint32_t keyRegisters)
{
    bool retval;
    uint32_t mask;
    uint32_t drySwac;
    uint32_t drySkwlr;
    uint32_t i, j;

    retval = true;
    mask   = 1u;
    j      = (sizeof(base->SKR) / sizeof(uint32_t));
    /* limit argument to maximum */
    if (keyRegisters > j)
    {
        keyRegisters = j;
    }

    /* specified SWAC and SKWLR bit(s) must be set */
    drySwac  = base->SWAC;
    drySkwlr = base->SKWLR;
    for (i = 0; i < keyRegisters; i++)
    {
        if (((mask & drySwac) == 0U) || ((mask & drySkwlr) == 0U))
        {
            retval = false;
            break;
        }
    }

    /* if the DryIce tamper flag is set the secure key storage is held in reset and so cannot be written */
    if (retval && (0U != (base->SR & DRY_SR_DTF_MASK)))
    {
        retval = false;
    }

    return retval;
}

static status_t dryice_PinConfigure(DRY_Type *base, const dryice_pin_config_t *pinConfig, uint32_t pin)
{
    uint32_t temp;
    uint32_t mask;
    status_t status;

    if ((dryice_IsRegisterWriteAllowed(
            base, DRY_LR_PDL_MASK | DRY_LR_PPL_MASK | (((uint32_t)1u << DRY_LR_GFL_SHIFT) << pin))) &&
        (pinConfig != NULL))
    {
        /* pin 0 to 7 selects bit0 to bit7 */
        mask = ((uint32_t)1u << pin);

        /* Pin Direction Register */
        temp = base->PDR;
        temp &= ~mask; /* clear the bit */
        if (kDRYICE_TamperPinDirectionOut == pinConfig->pinDirection)
        {
            temp |= mask; /* set the bit, if configured */
        }
        base->PDR = temp;

        /* Pin Polarity Register */
        temp = base->PPR;
        temp &= ~mask; /* clear the bit */
        if (kDRYICE_TamperPinPolarityExpectInverted == pinConfig->pinPolarity)
        {
            temp |= mask; /* set the bit, if configured */
        }
        base->PPR = temp;

        /* compute and set the configured value to the glitch filter register */
        temp = 0;
        temp |= DRY_PGFR_GFW(pinConfig->glitchFilterWidth);
        temp |= DRY_PGFR_GFP(pinConfig->glitchFilterPrescaler);
#if defined(FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_SAMPLING) && (FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_SAMPLING > 0)
        temp |= DRY_PGFR_TPSW(pinConfig->tamperPinSampleWidth);
        temp |= DRY_PGFR_TPSF(pinConfig->tamperPinSampleFrequency);
#endif
        temp |= DRY_PGFR_TPEX(pinConfig->tamperPinExpected);
        temp |= DRY_PGFR_TPE(pinConfig->tamperPullEnable);
#if defined(FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_PULL_SELECT) && (FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_PULL_SELECT > 0)
        temp |= DRY_PGFR_TPS(pinConfig->tamperPullSelect);
#endif
        /* make sure the glitch filter is disabled when we configure glitch filter width */
        base->PGFR[pin] = temp;
        /* add glitch filter enabled */
        if (pinConfig->glitchFilterEnable)
        {
            temp |= DRY_PGFR_GFE(1u);
            base->PGFR[pin] = temp;
        }
        status = kStatus_Success;
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

static status_t dryice_ActiveTamperConfigure(DRY_Type *base,
                                             const dryice_active_tamper_config_t *activeTamperConfig,
                                             uint32_t activeTamperRegister)
{
    uint32_t temp;
    status_t status;

    /* check if writing to active tamper register is allowed */
    if ((dryice_IsRegisterWriteAllowed(base, ((uint32_t)1u << DRY_LR_ATL_SHIFT) << activeTamperRegister)) &&
        (activeTamperConfig != NULL))
    {
        /* compute and set the configured value to the active tamper register */
        temp = 0;
        temp |= DRY_ATR_ATSR(activeTamperConfig->activeTamperShift);
        temp |= DRY_ATR_ATP(activeTamperConfig->activeTamperPolynomial);
        base->ATR[activeTamperRegister] = temp;
        status                          = kStatus_Success;
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

/*!
 * brief Enables the clock gate for the DryIce.
 *
 * This function enables the clock gate for the DryIce peripheral.
 */
void DRYICE_Init(DRY_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* ungate clock */
    CLOCK_EnableClock(kCLOCK_Dryice0);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
    CLOCK_EnableClock(kCLOCK_Secreg0);
}

/*!
 * brief Disables the clock the DryIce peripheral.
 *
 * This function disables glitch filters and active tampers
 * This function disables the DryIce clock and prescaler in DryIce Control Register.
 * This function disables the clock gate for the DryIce peripheral.
 */
void DRYICE_Deinit(DRY_Type *base)
{
    uint32_t i, j, k;
    j = ARRAY_SIZE(base->PGFR);
    k = ARRAY_SIZE(base->ATR);
    /* disable all glitch filters and active tampers */
    for (i = 0; i < j; i++)
    {
        base->PGFR[i] = 0;
    }
    for (i = 0; i < k; i++)
    {
        base->ATR[i] = 0;
    }

    /* disable innter Dryice clock and prescaler */
    base->CR &= ~DRY_CR_DEN_MASK;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* gate clock */
    CLOCK_DisableClock(kCLOCK_Dryice0);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
    CLOCK_DisableClock(kCLOCK_Secreg0);
}

/*!
 * brief Gets default values for the DryIce Control Register.
 *
 * This function fills the given structure with default values for the DryIce Control Register.
 * The default values are:
 * code
 *     defaultConfig->innerClockAndPrescalerEnable = true
 *     defaultConfig->tamperForceSystemResetEnable = false
 *     defaultConfig->updateMode = kDRYICE_StatusLockWithTamper
 *     defaultConfig->clockSourceActiveTamper0 = kDRYICE_ClockType1Hz
 *     defaultConfig->clockSourceActiveTamper1 = kDRYICE_ClockType1Hz
 *     defaultConfig->tamperHysteresisSelect = kDRYICE_Hysteresis305mV
 *     defaultConfig->tamperPassiveFilterEnable = false
 *     defaultConfig->tamperDriveStrength = kDRYICE_DriveStrengthLow
 *     defaultConfig->tamperSlewRate = kDRYICE_SlewRateSlow
 *     defaultConfig->secureRegisterFile = kDRYICE_VbatRegisterResetWithTamperOrInterrupt
 *     defaultConfig->prescaler = 0
 * endcode
 * param base DryIce peripheral base address
 * param[out] defaultConfig Pointer to structure to be filled with default parameters
 */
void DRYICE_GetDefaultConfig(DRY_Type *base, dryice_config_t *defaultConfig)
{
    /* Initializes the configure structure to zero. */
    (void)memset(defaultConfig, 0, sizeof(*defaultConfig));

    struct _dryice_config myDefaultConfig =
    {
        true,                         /* innerClockAndPrescalerEnable */
        false,                        /* tamperForceSystemResetEnable */
        kDRYICE_StatusLockWithTamper, /* updateMode */
#if defined(FSL_FEATURE_DRYICE_HAS_ACTIVE_TAMPER_CLOCK_SOURCE_SELECT) && \
    (FSL_FEATURE_DRYICE_HAS_ACTIVE_TAMPER_CLOCK_SOURCE_SELECT > 0)
        kDRYICE_ClockType1Hz, /* clockSourceActiveTamper0 */
        kDRYICE_ClockType1Hz, /* clockSourceActiveTamper1 */
#endif
        kDRYICE_Hysteresis305mV,  /* tamperHysteresisSelect */
        false,                    /* tamperPassiveFilterEnable */
        kDRYICE_DriveStrengthLow, /* tamperDriveStrength */
        kDRYICE_SlewRateSlow,     /* tamperSlewRate */
#if defined(FSL_FEATURE_DRYICE_HAS_SECURE_REGISTER_FILE_SELECT) && \
    (FSL_FEATURE_DRYICE_HAS_SECURE_REGISTER_FILE_SELECT > 0)
        kDRYICE_VbatRegisterResetWithTamperOrInterrupt, /* secureRegisterFile */
#endif
        0, /* prescaler */
    };

    *defaultConfig = myDefaultConfig;
}

/*!
 * brief Writes to the DryIce Control Register.
 *
 * This function writes the given structure to the DryIce Control Register.
 * param base DryIce peripheral base address
 * param config Pointer to structure with DryIce peripheral configuration parameters
 * return kStatus_Fail when writing to DryIce Control Register is not allowed
 * return kStatus_Success when operation completes successfully
 */
status_t DRYICE_SetConfig(DRY_Type *base, const dryice_config_t *config)
{
    uint32_t dryCR;
#if defined(FSL_FEATURE_DRYICE_HAS_ACTIVE_TAMPER_CLOCK_SOURCE_SELECT) && \
    (FSL_FEATURE_DRYICE_HAS_ACTIVE_TAMPER_CLOCK_SOURCE_SELECT > 0)
    uint32_t crATCS;
#endif
    status_t retval;

    /* check if writing to CR is allowed */
    if ((dryice_IsRegisterWriteAllowed(base, DRY_LR_CRL_MASK)) && (config != NULL))
    {
        /* compute CR value */
        dryCR = 0;
        dryCR |= DRY_CR_TFSR(config->tamperForceSystemResetEnable);
        dryCR |= DRY_CR_UM(config->updateMode);
#if defined(FSL_FEATURE_DRYICE_HAS_ACTIVE_TAMPER_CLOCK_SOURCE_SELECT) && \
    (FSL_FEATURE_DRYICE_HAS_ACTIVE_TAMPER_CLOCK_SOURCE_SELECT > 0)
        crATCS = (uint32_t)config->clockSourceActiveTamper0;
        crATCS |= ((uint32_t)config->clockSourceActiveTamper1) << 1u;
        dryCR |= DRY_CR_ATCS(crATCS);
#endif
        dryCR |= DRY_CR_THYS(config->tamperHysteresisSelect);
        dryCR |= DRY_CR_TPFE(config->tamperPassiveFilterEnable);
        dryCR |= DRY_CR_TDSE(config->tamperDriveStrength);
        dryCR |= DRY_CR_TSRE(config->tamperSlewRate);
#if defined(FSL_FEATURE_DRYICE_HAS_SECURE_REGISTER_FILE_SELECT) && \
    (FSL_FEATURE_DRYICE_HAS_SECURE_REGISTER_FILE_SELECT > 0)
        dryCR |= DRY_CR_SRF(config->secureRegisterFile);
#endif
        dryCR |= DRY_CR_DPR(config->prescaler);
        /* write the computed value to the CR register */
        base->CR = dryCR;
        /* after the prescaler is written to CR register, enable the inner dryice clock and prescaler */
        if (config->innerClockAndPrescalerEnable)
        {
            base->CR = dryCR | DRY_CR_DEN_MASK;
        }
        retval = kStatus_Success;
    }
    else
    {
        retval = kStatus_Fail;
    }

    return retval;
}

/*!
 * brief Software reset.
 *
 * This function resets all DryIce registers except WAC, RAC, SRAC, and SWAC. The CR[SWR] field is also not affected;
 * it is reset by VBAT POR only.
 *
 * param base DryIce peripheral base address
 * return kStatus_Fail when writing to DryIce Control Register is not allowed
 * return kStatus_Success when operation completes successfully
 */
status_t DRYICE_SoftwareReset(DRY_Type *base)
{
    status_t retval;

    /* check if writing to CR is allowed */
    if (dryice_IsRegisterWriteAllowed(base, DRY_LR_CRL_MASK))
    {
        /* set the CR[SWR] */
        base->CR = DRY_CR_SWR_MASK;
        retval   = kStatus_Success;
    }
    else
    {
        retval = kStatus_Fail;
    }

    return retval;
}

/*!
 * brief Writes to the active tamper register(s).
 *
 * This function writes per active tamper register parameters to active tamper register(s).
 *
 * param base DryIce peripheral base address
 * param activeTamperConfig Pointer to structure with active tamper register parameters
 * param activeTamperRegisterSelect Bit mask for active tamper registers to be configured. The passed value is
 *                                   combination of dryice_active_tamper_register_t values (OR'ed).
 * return kStatus_Fail when writing to DryIce Active Tamper Register(s) is not allowed
 * return kStatus_Success when operation completes successfully
 */
status_t DRYICE_ActiveTamperSetConfig(DRY_Type *base,
                                      const dryice_active_tamper_config_t *activeTamperConfig,
                                      uint32_t activeTamperRegisterSelect)
{
    uint32_t mask;
    status_t status;
    uint32_t i, j;

    mask   = 1u;
    status = kStatus_Success;
    j      = ARRAY_SIZE(base->ATR);
    /* configure active tamper register by active tamper register, by moving through all active tamper registers */
    for (i = 0; i < j; i++)
    {
        if ((activeTamperRegisterSelect & mask) != 0U)
        {
            /* configure this active tamper register */
            status = dryice_ActiveTamperConfigure(base, activeTamperConfig, i);
            if (status != kStatus_Success)
            {
                break;
            }
        }
        mask = mask << 1u;
    }

    return status;
}

/*!
 * brief Gets default values for tamper pin configuration.
 *
 * This function fills the give structure with default values for the tamper pin and glitch filter configuration.
 * The default values are:
 * code
 *     pinConfig->pinDirection = kDRYICE_TamperPinDirectionIn;
 *     pinConfig->pinPolarity = kDRYICE_TamperPinPolarityExpectNormal;
 *     pinConfig->glitchFilterWidth = 0;
 *     pinConfig->glitchFilterPrescaler = kDRYICE_GlitchFilterClock512Hz;
 *     pinConfig->glitchFilterEnable = false;
 *     pinConfig->tamperPinSampleWidth = kDRYICE_GlitchFilterSampleDisable;
 *     pinConfig->tamperPinSampleFrequency = kDRYICE_GlitchFilterSamplingEveryCycle8;
 *     pinConfig->tamperPinExpected = kDRYICE_GlitchFilterExpectedLogicZero;
 *     pinConfig->tamperPullEnable = false;
 *     pinConfig->tamperPullSelect = kDRYICE_GlitchFilterPullTypeAssert;
 * endcode
 *
 * param base DryIce peripheral base address
 * param[out] pinConfig Pointer to structure to be filled with tamper pins default parameters
 */
void DRYICE_PinGetDefaultConfig(DRY_Type *base, dryice_pin_config_t *pinConfig)
{
    /* Initializes the configure structure to zero. */
    (void)memset(pinConfig, 0, sizeof(*pinConfig));

    struct _dryice_pin_config myPinDefaultConfig =
    {
        kDRYICE_TamperPinDirectionIn,          /* pinDirection */
        kDRYICE_TamperPinPolarityExpectNormal, /* pinPolarity */
        0,                                     /* glitchFilterWidth */
        kDRYICE_GlitchFilterClock512Hz,        /* glitchFilterPrescaler */
        false,                                 /* glitchFilterEnable */
#if defined(FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_SAMPLING) && (FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_SAMPLING > 0)
        kDRYICE_GlitchFilterSampleDisable,       /* tamperPinSampleWidth */
        kDRYICE_GlitchFilterSamplingEveryCycle8, /* tamperPinSampleFrequency */
#endif
        kDRYICE_GlitchFilterExpectedLogicZero, /* tamperPinExpected */
        false,                                 /* tamperPullEnable */
#if defined(FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_PULL_SELECT) && (FSL_FEATURE_DRYICE_HAS_TAMPER_PIN_PULL_SELECT > 0)
        kDRYICE_GlitchFilterPullTypeAssert, /* tamperPullSelect */
#endif
    };

    *pinConfig = myPinDefaultConfig;
}

/*!
 * brief Writes the tamper pin configuration.
 *
 * This function writes per pin parameters to tamper pin and glitch filter configuration registers.
 *
 * param base DryIce peripheral base address
 * param pinConfig Pointer to structure with tamper pin and glitch filter configuration parameters
 * param pinSelect Bit mask for tamper pins to be configured. The passed value is combination of
 *                  enum _dryice_tamper_pin (dryice_tamper_pin_t) values (OR'ed).
 * return kStatus_Fail when writing to DryIce Pin Direction, Pin Polarity or Glitch Filter Register(s) is not allowed
 * return kStatus_Success when operation completes successfully
 */
status_t DRYICE_PinSetConfig(DRY_Type *base, const dryice_pin_config_t *pinConfig, uint32_t pinSelect)
{
    uint32_t mask;
    status_t status;
    uint32_t i, j;

    mask   = 1u;
    status = kStatus_Success;
    j      = ARRAY_SIZE(base->PGFR);
    /* configure pin by pin, by moving through all selected pins */
    for (i = 0; i < j; i++)
    {
        if ((pinSelect & mask) != 0U)
        {
            /* clear this pin from pinSelect */
            pinSelect &= ~mask;

            /* configure this pin */
            status = dryice_PinConfigure(base, pinConfig, i);

            /* if pinSelect is zero, we have configured all pins selected by pinSelect, so skip */
            if ((status != kStatus_Success) || (0U == pinSelect))
            {
                break;
            }
        }
        mask = mask << 1u;
    }

    return status;
}

/*!
 * brief Reads the Secure Key Register(s).
 *
 * This function reads actual value from Secure Key Register(s).
 *
 * param base DryIce peripheral base address
 * param[out] key Pointer to storage array (application buffer)
 * param keySize Storage array size in bytes
 * return kStatus_Fail if reading is not allowed (read access disabled or key argument is NULL)
 * return kStatus_Success when secure keys have been written to input storage array
 */
status_t DRYICE_GetKey(DRY_Type *base, uint8_t *key, size_t keySize)
{
    status_t status;
    uint32_t keyRegisters;
    uint32_t readKey[ARRAY_SIZE(base->SKR)] = {0};
    void *pKey;
    uint32_t i;

    /* compute number of 32-bit secure key registers to cover keySize bytes */
    keyRegisters = keySize / sizeof(uint32_t);
    if ((keySize % sizeof(uint32_t)) != 0U)
    {
        keyRegisters++;
    }
    if (keyRegisters > ARRAY_SIZE(base->SKR))
    {
        keyRegisters = ARRAY_SIZE(base->SKR);
    }

    if ((dryice_IsKeyReadAllowed(base, keyRegisters)) && (key != NULL))
    {
        /* read locally the secure key registers */
        for (i = 0; i < keyRegisters; i++)
        {
            readKey[i] = base->SKR[i];
        }

        /* memcpy to user buffer */
        pKey = readKey;
        for (i = 0; i < keySize; i++)
        {
            key[i] = ((uint8_t *)pKey)[i];
        }

        status = kStatus_Success;
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

/*!
 * brief Writes the Secure Key Register(s).
 *
 * This function writes given data to Secure Key Register(s).
 *
 * param base DryIce peripheral base address
 * param key Pointer to key to be stored in the DryIce peripheral
 * param keySize Key size in bytes
 * return kStatus_Fail if writing is not allowed (locked or write access disabled or key argument is NULL)
 * return kStatus_Success when Secure Key Register(s) have been written with new values
 */
status_t DRYICE_WriteKey(DRY_Type *base, const uint8_t *key, size_t keySize)
{
    status_t status = kStatus_Fail;
    uint32_t keyRegisters;
    uint32_t writeKey[ARRAY_SIZE(base->SKR)] = {0};
    void *pKey;
    uint32_t i;

    /* compute number of 32-bit secure key registers to cover keySize bytes */
    keyRegisters = keySize / sizeof(uint32_t);
    if ((keySize % sizeof(uint32_t)) != 0U)
    {
        keyRegisters++;
    }
    if (keyRegisters > ARRAY_SIZE(base->SKR))
    {
        keyRegisters = ARRAY_SIZE(base->SKR);
    }

    /* invalidate secure key registers */
    if ((NULL != key) && (keyRegisters != 0U))
    {
        base->SKVR = 0xFFu;
        status     = kStatus_Success;
    }

    if ((kStatus_Success == status) && (dryice_IsKeyWriteAllowed(base, keyRegisters)))
    {
        /* memcpy to local buffer */
        pKey = writeKey;
        for (i = 0; i < keySize; i++)
        {
            ((uint8_t *)pKey)[i] = key[i];
        }

        /* write the secure key registers */
        for (i = 0; i < keyRegisters; i++)
        {
            base->SKR[i] = writeKey[i];
        }
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

/*!
 * brief Reads the Status Register.
 *
 * This function reads flag bits from DryIce Status Register.
 *
 * param base DryIce peripheral base address
 * param[out] result Pointer to uint32_t where to write Status Register read value. Use dryice_status_flag_t to decode
 *                    individual flags.
 * return kStatus_Fail when Status Register reading is not allowed
 * return kStatus_Success when result is written with the Status Register read value
 */
status_t DRYICE_GetStatusFlags(DRY_Type *base, uint32_t *result)
{
    status_t status;

    if ((dryice_IsRegisterReadAllowed(base, DRY_RAC_SRR_MASK)) && (result != NULL))
    {
        *result = base->SR;
        status  = kStatus_Success;
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

/*!
 * brief Writes to the Status Register.
 *
 * This function clears specified flag bits in DryIce Status Register.
 *
 * param base DryIce peripheral base address
 * param mask Bit mask for the flag bits to be cleared. Use dryice_status_flag_t to encode flags.
 * return kStatus_Fail when Status Register writing is not allowed
 * return kStatus_Success when mask is written to the Status Register
 */
status_t DRYICE_ClearStatusFlags(DRY_Type *base, uint32_t mask)
{
    status_t status;

    if (dryice_IsRegisterWriteAllowed(base, DRY_WAC_SRW_MASK))
    {
        base->SR = mask;
        status   = kStatus_Success;
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

/*!
 * brief Writes to the Interrupt Enable Register.
 *
 * This function sets specified interrupt enable bits in DryIce Interrupt Enable Register.
 *
 * param base DryIce peripheral base address
 * param mask Bit mask for the interrupt enable bits to be set.
 * return kStatus_Fail when Interrupt Enable Register writing is not allowed
 * return kStatus_Success when mask is written to the Interrupt Enable Register
 */
status_t DRYICE_EnableInterrupts(DRY_Type *base, uint32_t mask)
{
    status_t status;

    mask = mask & DRYICE_ALL_IER_MASK; /* only set the bits documented in Reference Manual. */
    if (dryice_IsRegisterWriteAllowed(base, DRY_WAC_IEW_MASK))
    {
        base->IER |= mask;
        status = kStatus_Success;
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

/*!
 * brief Writes to the Interrupt Enable Register.
 *
 * This function clears specified interrupt enable bits in DryIce Interrupt Enable Register.
 *
 * param base DryIce peripheral base address
 * param mask Bit mask for the interrupt enable bits to be cleared.
 * return kStatus_Fail when Interrupt Enable Register writing is not allowed
 * return kStatus_Success when specified bits are cleared in the Interrupt Enable Register
 */
status_t DRYICE_DisableInterrupts(DRY_Type *base, uint32_t mask)
{
    status_t status;

    mask = mask & DRYICE_ALL_IER_MASK; /* only clear the bits documented in Reference Manual.  */
    if (dryice_IsRegisterWriteAllowed(base, DRY_WAC_IEW_MASK))
    {
        base->IER &= ~mask;
        status = kStatus_Success;
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

/*!
 * brief Writes to the Tamper Enable Register.
 *
 * This function sets specified tamper enable bits in DryIce Tamper Enable Register.
 *
 * param base DryIce peripheral base address
 * param mask Bit mask for the tamper enable bits to be set.
 * return kStatus_Fail when Tamper Enable Register writing is not allowed
 * return kStatus_Success when mask is written to the Tamper Enable Register
 */
status_t DRYICE_EnableTampers(DRY_Type *base, uint32_t mask)
{
    status_t status;

    mask = mask & DRYICE_ALL_TER_MASK; /* only set the bits documented in Reference Manual */
    if (dryice_IsRegisterWriteAllowed(base, DRY_WAC_TEW_MASK))
    {
        base->TER |= mask;
        status = kStatus_Success;
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

/*!
 * brief Writes to the Tamper Enable Register.
 *
 * This function clears specified tamper enable bits in DryIce Tamper Enable Register.
 *
 * param base DryIce peripheral base address
 * param mask Bit mask for the tamper enable bits to be cleared.
 * return kStatus_Fail when Tamper Enable Register writing is not allowed
 * return kStatus_Success when specified bits are cleared in the Tamper Enable Register
 */
status_t DRYICE_DisableTampers(DRY_Type *base, uint32_t mask)
{
    status_t status;

    mask = mask & DRYICE_ALL_TER_MASK; /* only clear the bits documented in Reference Manual */
    if (dryice_IsRegisterWriteAllowed(base, DRY_WAC_TEW_MASK))
    {
        base->TER &= ~mask;
        status = kStatus_Success;
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

/*!
 * brief Writes to the Tamper Seconds Register.
 *
 * This function writes to DryIce Tamper Seconds Register. This causes Status Register DTF flag to be set (DryIce
 * tampering detected).
 *
 * param base DryIce peripheral base address
 * return kStatus_Fail when Tamper Seconds Register writing is not allowed
 * return kStatus_Success when Tamper Seconds Register is written
 */
status_t DRYICE_ForceTamper(DRY_Type *base)
{
    status_t status;

    if (dryice_IsRegisterWriteAllowed(base, DRY_WAC_TSRW_MASK))
    {
        base->TSR = 0;
        status    = kStatus_Success;
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

/*!
 * brief Reads the Tamper Seconds Register.
 *
 * This function reads DryIce Tamper Seconds Register. The read value returns the time in seconds at which the Status
 * Register DTF flag was set.
 *
 * param base DryIce peripheral base address
 * param tamperTimeSeconds Time in seconds at which the tamper detection SR[DTF] flag was set.
 * return kStatus_Fail when Tamper Seconds Register reading is not allowed
 * return kStatus_Success when Tamper Seconds Register is read
 */
status_t DRYICE_GetTamperTimeSeconds(DRY_Type *base, uint32_t *tamperTimeSeconds)
{
    status_t status;

    if ((dryice_IsRegisterReadAllowed(base, DRY_RAC_TSRR_MASK)) && (tamperTimeSeconds != NULL))
    {
        *tamperTimeSeconds = base->TSR;
        status             = kStatus_Success;
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

/*!
 * brief Writes to the DryIce Lock Register.
 *
 * This function clears specified lock bits in the DryIce Lock Register.
 * When a lock bit is clear, a write to corresponding DryIce Register is ignored.
 * Once cleared, these bits can only be set by VBAT POR or software reset.
 *
 * param base DryIce peripheral base address
 * param mask Bit mask for the lock bits to be cleared. Use dryice_register_t values to encode (OR'ed) which DryIce
 * Registers shall be locked.
 */
void DRYICE_LockRegisters(DRY_Type *base, uint32_t mask)
{
    mask &= (uint32_t)kDRYICE_AllRegisters; /* make sure only documented registers are selected by the mask */
    base->LR &= ~mask;                      /* clear the selected bits */
}

/*!
 * brief Writes to DryIce Secure Key Lock Registers.
 *
 * This function clears specified lock bits in the DryIce Secure Key Write or Secure Key Read Lock Registers.
 * When a lock bit is clear, a read/write from/to corresponding DryIce Secure Key Register is ignored.
 * Once cleared, these bits can only be set by VBAT POR or software reset.
 *
 * param base DryIce peripheral base address
 * param mask Bit mask for the lock bits to be cleared. Use dryice_secure_key_t values to encode (OR'ed) which DryIce
 *             Secure Key Registers shall be locked.
 * param readWrite Select Read or Write (or ReadWrite) lock.
 */
void DRYICE_LockSecureKeys(DRY_Type *base, uint32_t mask, dryice_readwrite_t readWrite)
{
    mask &=
        (uint32_t)kDRYICE_AllSecureKeys; /* make sure only documented secure key registers are selected by the mask */
    if ((readWrite == kDRYICE_Read) || (readWrite == kDRYICE_ReadWrite))
    {
        base->SKRLR &= ~mask;
    }
    if ((readWrite == kDRYICE_Write) || (readWrite == kDRYICE_ReadWrite))
    {
        base->SKWLR &= ~mask;
    }
}

/*!
 * brief Writes to DryIce Access Control Registers.
 *
 * This function clears specified access control bits in the DryIce Access Control Registers.
 * When an access control bit is clear, a read/write from/to corresponding DryIce Register or Secure Key Register is
 * ignored.
 * Once cleared, these bits can only be set by VBAT POR or software reset.
 *
 * param base DryIce peripheral base address
 * param maskRegisters Bit mask for the access control bits to be cleared. Use dryice_register_t values to encode
 *                      (OR'ed) which DryIce Registers shall be access controlled.
 * param maskKeys Bit mask for the access control bits to be cleared. Use dryice_secure_key_t values to encode (OR'ed)
 *                 which DryIce Secure Key Registers shall be access controlled.
 * param readWrite Disallow Read or Write (or ReadWrite).
 */
void DRYICE_DisableAccess(DRY_Type *base, uint32_t maskRegisters, uint32_t maskKeys, dryice_readwrite_t readWrite)
{
    maskRegisters &= (uint32_t)kDRYICE_AllRegisters; /* make sure only documented registers are selected by the mask */
    maskKeys &=
        (uint32_t)kDRYICE_AllSecureKeys; /* make sure only documented secure key registers are selected by the mask */

    if ((readWrite == kDRYICE_Read) || (readWrite == kDRYICE_ReadWrite))
    {
        base->RAC &= ~maskRegisters;
        base->SRAC &= ~maskKeys;
    }
    if ((readWrite == kDRYICE_Write) || (readWrite == kDRYICE_ReadWrite))
    {
        base->WAC &= ~maskRegisters;
        base->SWAC &= ~maskKeys;
    }
}
