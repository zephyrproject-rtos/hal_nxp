/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_sdioslv.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief SDIOSLV capability definition */
#define SDIOSLV_SDIOV2_COMMON_CAPABILITY()                                                                          \
    SDIOSLV_SLAVE_CCCR_CAPABILTIY(kSDIOSLV_CCCRVersion2_00, kSDIOSLV_SDIOVersion2_00, kSDIOSLV_SDVersion2_00, true, \
                                  true, true, true, true, true, false, true, true, true)
#define SDIOSLV_SDIOV2_IO_CAPABILITY() \
    SDIOSLV_SLAVE_IO_ACCESS_CAPABILITY(false, false, false, false, false, false, true)
#define SDIOSLV_SDIOV3_COMMON_CAPABILITY()                                                                          \
    SDIOSLV_SLAVE_CCCR_CAPABILTIY(kSDIOSLV_CCCRVersion2_00, kSDIOSLV_SDIOVersion3_00, kSDIOSLV_SDVersion3_00, true, \
                                  true, true, true, true, true, false, true, true, true)
#define SDIOSLV_SDIOV3_IO_CAPABILITY() SDIOSLV_SLAVE_IO_ACCESS_CAPABILITY(true, true, true, true, false, false, true)

/*! @brief SDIO slave argument parse macro */
#define SDIOSLV_ARGUMENT_BYTE_BLOCK_COUNT(argument) (argument & 0x1FFU)
#define SDIOSLV_ARGUMENT_REGISTER_ADDR(argument)    ((argument >> 9U) & 0x1FFFFU)
#define SDIOSLV_ARGUMENT_OP_CODE(argument)          ((argument >> 26U) & 0x1U)
#define SDIOSLV_ARGUMENT_IS_BLOCK_MODE(argument)    ((argument >> 27U) & 0x1U)
#define SDIOSLV_ARGUMENT_FUNCTION_NUM(argument)     ((argument >> 28U) & 0x7U)
#define SDIOSLV_ARGUMENT_IS_WRITE(argument)         ((argument >> 31U) & 0x1U)

/* Typedef for interrupt handler. */
typedef void (*sdioSLV_isr_t)(SDIOSLV_Type *base, sdioslv_handle_t *handle);
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Get the instance.
 *
 * @param base SDIO peripheral base address.
 * @return Instance number.
 */
static uint32_t SDIOSLV_GetInstance(SDIOSLV_Type *base);

/*!
 * @brief SDIO slave handle function 0 data interrupt.
 *
 * @param base SDIO peripheral base address.
 * @param handle sdio slave handler.
 * @param interruptFlags generated interrupt flags
 */
static void SDIOSLV_TransferHandleFunc0Data(SDIOSLV_Type *base, sdioslv_handle_t *handle, uint32_t interruptFlags);

/*!
 * @brief SDIO slave handle function 1 data interrupt.
 *
 * @param base SDIO peripheral base address.
 * @param handle sdio slave handler.
 * @param interruptFlags generated interrupt flags
 */
static void SDIOSLV_TransferHandleFunc1Data(SDIOSLV_Type *base, sdioslv_handle_t *handle, uint32_t interruptFlags);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static const uint8_t g_sdioslv_v2_default_func0_cis[] = {
    SDIOSLV_TPL_CODE_CISTPL_FUNCID,
    0x02U, /*!< Link to next tuple */
    0x0CU, /*!< Card function code */
    0x00U, /*!< Not used */
    SDIOSLV_TPL_CODE_CISTPL_FUNCE,
    0x04U, /*!< Link to next tuple */
    0x00U, /*!< Extended data */
    0x00U,
    0x08U, /*!< Maximum blocks function 0 can support, 2048 bytes */
    0x32U, /*!< Transfer rate, 25Mbit/Sec */
    SDIOSLV_TPL_CODE_CISTPL_MANFID,
    0x04U, /*!< Link to next tuple */
    0x96U,
    0x02U, /*!< SDIO manufacturer code, 0x00000296 */
    0x47U,
    0x53U, /*!< Part number / Revision number, 0x00005347 */
    SDIOSLV_TPL_CODE_CISTPL_END,
};

static const uint8_t g_sdioslv_v2_default_func1_cis[] = {
    SDIOSLV_TPL_CODE_CISTPL_FUNCID,
    0x02U, /*!< Link to next tuple */
    0x0CU, /*!< Card function code */
    0x00U, /*!< Not used */
    SDIOSLV_TPL_CODE_CISTPL_FUNCE,
    0x2AU, /*!< Link to next tuple */
    0x01U, /*!< Type of extended data */
    0x01U, /*!< Wakeup support */
    0x20U, /*!< The version of standard SDIO function is 2.0*/
    0x00U,
    0x00U,
    0x00U,
    0x00U, /*!< No serial number */
    0x00U,
    0x00U,
    0x02U,
    0x00U, /*!< The size of CSA space for this fucntion in bytes, 131K bytes*/
    0x03U, /*!< CSA property, write-protect and not reformatted */
    0x00U,
    0x08U, /*!< Maximum block size, 2048 bytes */
    0x00U,
    0x80U,
    0xFFU,
    0x00U, /*!< the OCR value of this function */
    0x08U, /*!< Minimum power required by this function, 8mA */
    0x0AU, /*!< Average power required by this function, 10mA */
    0x0FU, /*!< Maximum power required by this function, 15mA */
    0x01U, /*!< Minimum power required in the standby condition, 1mA */
    0x01U, /*!< Average power required in the standby condition, 1mA */
    0x01U, /*!< Maximum power required in the standby condition, 1mA */
    0x00U,
    0x00U, /*!< No minimum data transfer bandwidth */
    0x00U,
    0x00U, /*!< No optimum data transfer bandwidth */
    0x00U,
    0x00U, /*!< Card required no timeout */
    0x00U,
    0x00U, /*!< Average power required by this function, the same with previous config */
    0x00U,
    0x00U, /*!< Maximum power required by this function, the same with previous config */
    0x00U,
    0x00U, /*!< Average power required in the higher current mode. No supported */
    0x00U,
    0x00U, /*!< Maximum power required in the higher current mode. Not supported */
    0x00U,
    0x00U, /*!< Average power required in the lower current mode. No supported */
    0x00U,
    0x00U, /*!< Maximum power required in the lower current mode. No supported */
    SDIOSLV_TPL_CODE_CISTPL_END};

static uint8_t g_sdioslv_v3_default_func0_cis[] = {
    SDIOSLV_TPL_CODE_CISTPL_FUNCID,
    0x02U, /*!< Link to next tuple */
    0x0CU, /*!< Card function code */
    0x00U, /*!< Not used */
    SDIOSLV_TPL_CODE_CISTPL_FUNCE,
    0x04U, /*!< Link to next tuple */
    0x00U, /*!< Extended data */
    0x00U,
    0x08U, /*!< Maximum blocks function 0 can support, 2048 bytes */
    0x2bU, /*!< Transfer rate, 200Mbit/Sec */
    SDIOSLV_TPL_CODE_CISTPL_MANFID,
    0x04U, /*!< Link to next tuple */
    0x96U,
    0x02U, /*!< SDIO manufacturer code, 0x00000296 */
    0x47U,
    0x53U, /*!< Part number / Revision number, 0x00005347 */
    SDIOSLV_TPL_CODE_CISTPL_END,
};

static const uint8_t g_sdioslv_v3_default_func1_cis[] = {
    SDIOSLV_TPL_CODE_CISTPL_FUNCID,
    0x02U, /*!< Link to next tuple */
    0x0CU, /*!< Card function code */
    0x00U, /*!< Not used */
    SDIOSLV_TPL_CODE_CISTPL_FUNCE,
    0x2AU, /*!< Link to next tuple */
    0x01U, /*!< Type of extended data */
    0x01U, /*!< Wakeup support */
    0x30U, /*!< The version of standard SDIO function is 2.0*/
    0x00U,
    0x00U,
    0x00U,
    0x00U, /*!< No serial number */
    0x00U,
    0x00U,
    0x02U,
    0x00U, /*!< The size of CSA space for this fucntion in bytes, 131K bytes*/
    0x03U, /*!< CSA property, write-protect and not reformatted */
    0x00U,
    0x08U, /*!< Maximum block size, 2048 bytes */
    0x00U,
    0x80U,
    0xFFU,
    0x00U, /*!< the OCR value of this function */
    0x08U, /*!< Minimum power required by this function, 8mA */
    0x0AU, /*!< Average power required by this function, 10mA */
    0x0FU, /*!< Maximum power required by this function, 15mA */
    0x01U, /*!< Minimum power required in the standby condition, 1mA */
    0x01U, /*!< Average power required in the standby condition, 1mA */
    0x01U, /*!< Maximum power required in the standby condition, 1mA */
    0x00U,
    0x00U, /*!< No minimum data transfer bandwidth */
    0x00U,
    0x00U, /*!< No optimum data transfer bandwidth */
    0x00U,
    0x00U, /*!< Card required no timeout */
    0x00U,
    0x00U, /*!< Average power required by this function, the same with previous config */
    0x00U,
    0x00U, /*!< Maximum power required by this function, the same with previous config */
    0x00U,
    0x00U, /*!< Average power required in the higher current mode. No supported */
    0x00U,
    0x00U, /*!< Maximum power required in the higher current mode. Not supported */
    0x00U,
    0x00U, /*!< Average power required in the lower current mode. No supported */
    0x00U,
    0x00U, /*!< Maximum power required in the lower current mode. No supported */
    SDIOSLV_TPL_CODE_CISTPL_END};
/*! @brief SDIO internal handle pointer array */
static sdioslv_handle_t *s_sdioslvHandle[FSL_FEATURE_SOC_SDIOSLV_COUNT];
/*! @brief SDIO base pointer array */
static SDIOSLV_Type *const s_sdioslvBase[] = SDIOSLV_BASE_PTRS;
/*! @brief SDIO IRQ name array */
static const IRQn_Type s_sdioIRQ[] = SDIOSLV_IRQS;
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief SDHC clock array name */
static const clock_ip_name_t s_sdioClock[] = SDIOSLV_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
static const uint32_t s_sdioCisBase[] = SDIOSLV_CIS_BASE_PTRS;
/*! @brief SDIO ISR for transactional APIs. */
static sdioSLV_isr_t s_sdioslvIsr;
/*! @brief SDIO dummy data for ADMA pre-fetch operation. */
static const uint8_t s_sdioslvDummyData = 0U;
/*******************************************************************************
 * Code
 ******************************************************************************/
static inline uint32_t SDIOSLV_GetInstance(SDIOSLV_Type *base)
{
    uint8_t instance = 0;

    while ((instance < ARRAY_SIZE(s_sdioslvBase)) && (s_sdioslvBase[instance] != base))
    {
        instance++;
    }

    assert(instance < ARRAY_SIZE(s_sdioslvBase));

    return instance;
}

/*!
 * brief Sets the SDIO configuration structure to SDIO 2.0 default values.
 *
 * note calling this function will involve the default cis table in the sdio slave driver, it may increase
 * the ram cost.
 * param config A pointer to the user configuration structure.
 */
void SDIOSLV_GetSDIOV2Config(sdioslv_config_t *config)
{
    assert(config);

    memset(config, 0, sizeof(sdioslv_config_t));

    config->commonCapability = SDIOSLV_SDIOV2_COMMON_CAPABILITY();
    config->iocapability     = SDIOSLV_SDIOV2_IO_CAPABILITY();

    /*
     *kSDIOSLV_NullDevice, device code
     *true, support CSA
     *0, extend device code 0
     *false, not support high power
     */
    config->fbrRegConfig = SDIOSLV_SLAVE_FBR(kSDIOSLV_NullDevice, true, 0, false);

    config->supportUHS = false;                   /*!< Not support for UHS. */
    config->ddrDelay   = kSDIOSLV_DDRDelay3000ps; /*!< 3ns delay select value for DDR mode read transaction. */
    config->voltageSwitchDelayCount =
        0; /*!< Wait time for the Controller before releasing cmd, data line for cmd11 voltage switch. */
    config->ocr = 0x00ff8000; /*!< Support for 2.7-3.6V. */
    /* load default CIS table */
    config->cisRegConfig[0].length = sizeof(g_sdioslv_v2_default_func0_cis);
    config->cisRegConfig[0].base   = g_sdioslv_v2_default_func0_cis;
    config->cisRegConfig[1].length = sizeof(g_sdioslv_v2_default_func1_cis);
    config->cisRegConfig[1].base   = g_sdioslv_v2_default_func1_cis;
}

/*!
 * brief Sets the SDIO configuration structure to SDIO 3.0 default values.
 *
 * note calling this function will involve the default cis table in the sdio slave driver, it may increase
 * the ram cost.
 * param config A pointer to the user configuration structure.
 */
void SDIOSLV_GetSDIOV3Config(sdioslv_config_t *config)
{
    assert(config);

    memset(config, 0, sizeof(sdioslv_config_t));

    config->commonCapability = SDIOSLV_SDIOV3_COMMON_CAPABILITY();
    config->iocapability     = SDIOSLV_SDIOV3_IO_CAPABILITY();
    /*
     *kSDIOSLV_NullDevice, device code
     *true, support CSA
     *0, extend device code 0
     *false, not support high power
     */
    config->fbrRegConfig = SDIOSLV_SLAVE_FBR(kSDIOSLV_NullDevice, true, 0, false);

    config->supportUHS = true;                    /*!< Not support for UHS. */
    config->ddrDelay   = kSDIOSLV_DDRDelay3000ps; /*!< 3ns delay select value for DDR mode read transaction. */
    config->voltageSwitchDelayCount =
        0; /*!< Wait time for the Controller before releasing cmd, data line for cmd11 voltage switch. */
    config->ocr = 0x00ff8000; /*!< Support for 2.7-3.6V. */
    /* load default CIS table */
    config->cisRegConfig[0].length = sizeof(g_sdioslv_v3_default_func0_cis);
    config->cisRegConfig[0].base   = g_sdioslv_v3_default_func0_cis;
    config->cisRegConfig[1].length = sizeof(g_sdioslv_v3_default_func1_cis);
    config->cisRegConfig[1].base   = g_sdioslv_v3_default_func1_cis;
}

/*!
 * brief SDIO module initialization function.
 *
 * param base SDIO peripheral base address.
 * param config sdio slave configurations.
 */
void SDIOSLV_Init(SDIOSLV_Type *base, const sdioslv_config_t *config)
{
    assert(config);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable SDIO slave clock. */
    CLOCK_EnableClock(s_sdioClock[SDIOSLV_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Polling SDIOSLV ready status */
    while (!SDIOSLV_GetReadyStatus(SDIOSLV))
    {
    }

    /* Copy CIS configuration to CIS base. */
    for (int i = 0; i < ARRAY_SIZE(s_sdioCisBase); i++)
    {
        if ((config->cisRegConfig[i].base != NULL) && (config->cisRegConfig[i].length != 0))
        {
            memcpy((void *)s_sdioCisBase[i], config->cisRegConfig[i].base, config->cisRegConfig[i].length);
        }
    }

    /* disable all the interrupt */
    base->FNO_INT_EN     = 0U;
    base->GLB_INT_EN_REG = 0U;
    base->FN1_INT_EN     = 0U;

    /* SDIO card configuration. */
    base->SIG_CCCR_REG        = config->commonCapability;
    base->SIG_IO_ACCESS_MODE  = config->iocapability;
    base->SIG_UHS_SUPPORT_REG = SDIOSLV_SIG_UHS_SUPPORT_REG_UHS_SUPPORT(config->supportUHS) |
                                SDIOSLV_SIG_UHS_SUPPORT_REG_DDR_DLY_SELECT(config->ddrDelay);
    base->SIG_CLK_DELAY_TIMER_REG = config->voltageSwitchDelayCount;
    base->SIG_OCR                 = config->ocr;
    base->SIG_FBR_REG             = config->fbrRegConfig;

    /* set function ready bit */
    SDIOSLV_SetFunctionReady(base);
}

/*!
 * brief Reset the SDIO module.
 *
 * param base SDIO peripheral base address.
 */
void SDIOSLV_Deinit(SDIOSLV_Type *base)
{
    /* Disable SDIO slave interrupt*/
    DisableIRQ(s_sdioIRQ[SDIOSLV_GetInstance(base)]);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable SDIO slave clock. */
    CLOCK_DisableClock(s_sdioClock[SDIOSLV_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Sets the ADMA descriptor table configuration.
 *
 * param base SDIO peripheral base address.
 * param table ADMA table address.
 * param tableWords ADMA table buffer length united as Words.
 * param data Data buffer address.
 * param dataBytes Data length united as bytes.
 * retval kStatus_OutOfRange ADMA descriptor table length isn't enough to describe data.
 * retval kStatus_Success Operate successfully.
 */
static status_t SDIOSLV_SetAdmaTableConfig(
    SDIOSLV_Type *base, uint32_t *table, uint32_t tableWords, const uint8_t *data, uint32_t dataBytes)
{
    const uint8_t *startAddress = data;
    uint32_t entries;
    uint32_t i, dmaBufferLen = 0U;
    sdioslv_adma_descriptor_t *admaEntryAddress;

    if (((uint32_t)startAddress % SDIOSLV_ADMA_LENGTH_ALIGN) != 0U)
    {
        return kStatus_SDIOSLV_DMADataBufferAddrNotAlign;
    }

    /* Check if ADMA descriptor's number is enough. */
    if ((dataBytes % SDIOSLV_ADMA_DESCRIPTOR_MAX_LENGTH_PER_ENTRY) == 0U)
    {
        entries = dataBytes / SDIOSLV_ADMA_DESCRIPTOR_MAX_LENGTH_PER_ENTRY;
    }
    else
    {
        entries = ((dataBytes / SDIOSLV_ADMA_DESCRIPTOR_MAX_LENGTH_PER_ENTRY) + 1U);
    }

    if ((entries + 1U) > ((tableWords * sizeof(uint32_t)) / sizeof(sdioslv_adma_descriptor_t)))
    {
        return kStatus_OutOfRange;
    }

    admaEntryAddress = (sdioslv_adma_descriptor_t *)(table);
    for (i = 0U; i < entries; i++)
    {
        if (dataBytes > SDIOSLV_ADMA_DESCRIPTOR_MAX_LENGTH_PER_ENTRY)
        {
            dmaBufferLen = SDIOSLV_ADMA_DESCRIPTOR_MAX_LENGTH_PER_ENTRY;
            dataBytes -= dmaBufferLen;
        }
        else
        {
            dmaBufferLen = dataBytes;
        }

        /* Each descriptor for ADMA is 64-bit in length */
        admaEntryAddress[i].address = startAddress;
        /* It is 0x10000 bytes when length field is 0. Don't mind the overflow. */
        admaEntryAddress[i].attribute =
            ((dmaBufferLen & SDIOSLV_ADMA_DESCRIPTOR_LENGTH_MASK) << SDIOSLV_ADMA_DESCRIPTOR_LENGTH_SHIFT);
        admaEntryAddress[i].attribute |= kSDIOSLV_AdmaDescriptorTypeTransfer;
        startAddress += (dmaBufferLen / sizeof(uint32_t));
    }

    /* set the end bit */
    admaEntryAddress[i].attribute |= kSDIOSLV_AdmaDescriptorEndFlag | kSDIOSLV_AdmaDescriptorTypeTransfer |
                                     (1U << SDIOSLV_ADMA_DESCRIPTOR_LENGTH_SHIFT);
    admaEntryAddress[i].address   = &s_sdioslvDummyData;
    base->SIG_ADMA_SYSTEM_ADDRESS = (uint32_t)table;

    return kStatus_Success;
}

/*!
 * brief Enables the interrupt signal corresponding to the interrupt status flag.
 *
 * param base SDIO peripheral base address.
 * param func The specific function number.
 * param mask The function interrupt status flags mask(_sdioslv_function0_interrupt_status_flag or
 * _sdioslv_function1_interrupt_status_flag).
 */
void SDIOSLV_EnableFuncInterrupt(SDIOSLV_Type *base, sdioslv_func_t func, uint32_t mask)
{
    switch (func)
    {
        case kSDIOSLV_FunctionNum0:
            base->FNO_INT_EN |= mask;
            break;
        case kSDIOSLV_FunctionNum1:
            base->FN1_INT_EN |= mask;
            break;
        default:
            /* Invalid function number, or no-supported function number. Do nothing. */
            break;
    }
}

/*!
 * brief Disables the interrupt signal corresponding to the interrupt status flag.
 *
 * param base SDIO peripheral base address.
 * param func The specific function number.
 * param mask The function interrupt status flags mask(_sdioslv_function0_interrupt_status_flag or
 * _sdioslv_function1_interrupt_status_flag).
 */
void SDIOSLV_DisableFuncInterrupt(SDIOSLV_Type *base, sdioslv_func_t func, uint32_t mask)
{
    switch (func)
    {
        case kSDIOSLV_FunctionNum0:
            base->FNO_INT_EN &= ~mask;
            break;
        case kSDIOSLV_FunctionNum1:
            base->FN1_INT_EN &= ~mask;
            break;
        default:
            /* Invalid function number, or no-supported function number. Do nothing. */
            break;
    }
}

/*!
 * brief Gets the specific function interrupt status.
 *
 * param base SDIO peripheral base address.
 * param func The specific function number.
 * return The function interrupt status flags mask(_sdioslv_function0_interrupt_status_flag or
 * _sdioslv_function1_interrupt_status_flag).
 */
uint32_t SDIOSLV_GetFuncInterruptStatusFlags(SDIOSLV_Type *base, sdioslv_func_t func)
{
    uint32_t interruptFlags = 0;

    switch (func)
    {
        case kSDIOSLV_FunctionNum0:
            interruptFlags = base->FN0_INT_TO_ARM;
            break;
        case kSDIOSLV_FunctionNum1:
            interruptFlags = base->FN1_INT_STS;
            break;
        default:
            /* Invalid function number, or no-supported function number. Always return 0 */
            interruptFlags = 0;
            break;
    }

    return interruptFlags;
}

/*!
 * brief Clears a specified interrupt status of a specific function.
 *
 * param base SDIO peripheral base address.
 * param func the specific function number.
 * param mask The function interrupt status flags mask(_sdioslv_function0_interrupt_status_flag or
 * _sdioslv_function1_interrupt_status_flag).
 */
void SDIOSLV_ClearFuncInterruptStatusFlags(SDIOSLV_Type *base, sdioslv_func_t func, uint32_t mask)
{
    switch (func)
    {
        /* Write '1' to clear the interrupt status flag. */
        case kSDIOSLV_FunctionNum0:
            base->FN0_INT_TO_ARM = mask;
            break;
        case kSDIOSLV_FunctionNum1:
            base->FN1_INT_STS = mask;
            break;
        default:
            /* Invalid function number, or no-supported function number. Do nothing. */
            break;
    }
}

/*!
 * brief Set the SDIO function ready bit in CCCR.IOR[x].
 *
 * param base SDIO peripheral base address.
 * param func The specific function number.
 */
void SDIOSLV_SetIOReady(SDIOSLV_Type *base, sdioslv_func_t func)
{
    switch (func)
    {
        case kSDIOSLV_FunctionNum1:
            base->SIG_IOR_REG |= SDIOSLV_SIG_IOR_REG_IOR_REG_MASK;
            break;
        default:
            /* Invalid function number, or no-supported function number. Do nothing. */
            break;
    }
}

/*!
 * brief Clear the SDIO function ready bit in CCCR.IOR[x].
 *
 * param base SDIO peripheral base address.
 * param func The specific function number.
 */
void SDIOSLV_ClearIOReady(SDIOSLV_Type *base, sdioslv_func_t func)
{
    switch (func)
    {
        case kSDIOSLV_FunctionNum1:
            base->SIG_IOR_REG &= ~SDIOSLV_SIG_IOR_REG_IOR_REG_MASK;
            break;
        default:
            /* Invalid function number, or no-supported function number. Do nothing. */
            break;
    }
}

/*!
 * brief SDIO set function1 data ready to inform SD host to fetch data.
 *
 * param base SDIO peripheral base address.
 * param dataBytes Transfer data count.
 */
void SDIOSLV_SetIO1ReadDataReady(SDIOSLV_Type *base, uint32_t dataBytes)
{
    /* Program data databytes. */
    base->SIG_AHB_XFER_CNT = dataBytes;
    /* Set data ready bit, then SDIO-AHB controller will assert interrupt to SD host. */
    base->SIG_RDDATARDY_REG |= SDIOSLV_SIG_RDDATARDY_REG_FUNCTION_1_READ_DATA_READY_MASK;
}

/*!
 * brief Creates the SDIO handle.
 *
 * param base SDIO peripheral base address.
 * param handle SDIO handle pointer.
 * param callback Structure pointer to contain all callback functions.
 * param userData Callback function parameter.
 */
void SDIOSLV_TransferCreateHandle(SDIOSLV_Type *base,
                                  sdioslv_handle_t *handle,
                                  sdioslv_transfer_callback_t callback,
                                  void *userData)
{
    assert(handle);
    assert(callback);

    /* Zero the handle. */
    memset(handle, 0, sizeof(*handle));

    /* Set the callback. */
    handle->callback = callback;
    handle->userData = userData;

    /* Save the handle in global variables to support the double weak mechanism. */
    s_sdioslvHandle[SDIOSLV_GetInstance(base)] = handle;

    /* save IRQ handler */
    s_sdioslvIsr = SDIOSLV_TransferHandleIRQ;

    SDIOSLV_EnableFuncInterrupt(base, kSDIOSLV_FunctionNum1, kSDIOSLV_Func1AllInterruptFlag);
    SDIOSLV_EnableFuncInterrupt(base, kSDIOSLV_FunctionNum0, kSDIOSLV_Func0AllInterruptFlag);
    SDIOSLV_EnableGlobalInterrupts(base, kSDIOSLV_Func1InterruptFlag, true);
    SDIOSLV_EnableGlobalInterrupts(base, kSDIOSLV_Func0InterruptFlag, true);

    EnableIRQ(s_sdioIRQ[SDIOSLV_GetInstance(base)]);
}

/*!
 * brief SDIO Slave install ADMA descriptor memory.
 *
 * Note: A dummy descriptor is required for ADMA finished the ADMA pre-fetch operation, so application need to
 * provide desNum+1 descriptor memory.
 *
 * param handle SDIO slave handler.
 * param desAddr transmit descriptor address.
 * param desNum transmit descriptor number.
 */
void SDIOSLV_InstallADMADescriptorMemory(sdioslv_handle_t *handle, void *desAddr, uint32_t desNum)
{
    assert(((uint32_t)desAddr % SDIOSLV_ADMA_ADDRESS_ALIGN) == 0U);

    handle->descriptorBuffer = desAddr;
    handle->descriptorLen    = desNum * 2U;
}

/*!
 * brief SDIO Slave install ping pong buffer for host write transfer.
 *
 * Note: SDIOSLV driver assume the pingpong buffer size is pingpongBufferSize * 2U.
 *
 * param handle SDIO slave handler.
 * param pingpongBufferAddr ping pong buffer start address.
 * param pingpongBufferSize  buffer size of the ping pong buffer, total buffer size should be 2 * pingpongBufferSize.
 */
void SDIOSLV_InstallPingpongBuffer(sdioslv_handle_t *handle, void *pingpongBufferAddr, uint32_t pingpongBufferSize)
{
    assert(((uint32_t)pingpongBufferAddr % SDIOSLV_ADMA_ADDRESS_ALIGN) == 0U);

    handle->rxPingpongBuffer     = pingpongBufferAddr;
    handle->rxPingpongBufferSize = pingpongBufferSize;
    handle->rxPingpongBufferHead = pingpongBufferAddr;
}

/*!
 * brief SDIOSLV send transfers.
 *
 * Call this API after calling the SDIOSLV_Init() and SDIOSLV_TransferCreateHandle() ,
 * SDIOSLV_InstallADMADescriptorMemory() to start processing transactions driven by an SD Host. The slave monitors the
 * SDIO bus. The callback is always invoked from the interrupt context.
 *
 * param base SDIO peripheral base address.
 * param handle Pointer to #sdioslv_handle_t structure which stores the transfer state.
 * param transfer transfer configuration.
 * retval #kStatus_SDIOSLV_QueueFull transmit buffer queue is full, application should check and wait until queue is not
 * full.
 * retval #kStatus_SDIOSLV_DMADataBufferAddrNotAlign the transfer data address or data size is not word align.
 * retval #kStatus_Success transfer configuration add into queue successfully.
 */
status_t SDIOSLV_TransferSendNonBlocking(SDIOSLV_Type *base, sdioslv_handle_t *handle, sdioslv_transfer_t *transfer)
{
    assert(handle);

    /* Check if the queue is full */
    if (handle->txQueue[handle->txQueueUser].dataAddr)
    {
        return kStatus_SDIOSLV_QueueFull;
    }

    if ((((uint32_t)transfer->dataAddr % SDIOSLV_ADMA_ADDRESS_ALIGN) != 0U) ||
        (transfer->dataSize % SDIOSLV_ADMA_LENGTH_ALIGN != 0U))
    {
        return kStatus_SDIOSLV_DMADataBufferAddrNotAlign;
    }

    handle->txQueue[handle->txQueueUser].dataAddr = transfer->dataAddr;
    handle->txQueue[handle->txQueueUser].dataSize = transfer->dataSize;
    handle->txQueueUser                           = (handle->txQueueUser + 1U) % SDIOSLV_TRANSMIT_QUEUE_SIZE;

    if (handle->state != kStatus_SDIOSLV_Busy)
    {
        /* Set the state to busy */
        handle->state = kStatus_SDIOSLV_Busy;
        /* trigger sd host that the data is ready to read */
        SDIOSLV_SetIO1ReadDataReady(base, transfer->dataSize);
    }

    return kStatus_Success;
}

/*!
 * brief Starts accepting read transfers.
 *
 * This API should be called if pingpong buffer is not registered and kStatus_SDIOSLV_FuncWriteRequest callback is
 * received.
 *
 * param base SDIO peripheral base address.
 * param handle Pointer to #sdioslv_handle_t structure which stores the transfer state.
 * param transfer transfer configuration.
 * retval #kStatus_SDIOSLV_QueueFull transmit buffer queue is full, application should check and wait until queue is not
 * full. retval #kStatus_SDIOSLV_DMADataBufferAddrNotAlign the transfer data address or data size is not word align.
 * retval #kStatus_Success transfer configuration add into queue successfully.
 */
status_t SDIOSLV_TransferReceiveNonBlocking(SDIOSLV_Type *base, sdioslv_handle_t *handle, sdioslv_transfer_t *transfer)
{
    assert(handle);
    assert(handle->descriptorBuffer != NULL);

    if ((((uint32_t)transfer->dataAddr % SDIOSLV_ADMA_ADDRESS_ALIGN) != 0U) ||
        (transfer->dataSize % SDIOSLV_ADMA_LENGTH_ALIGN != 0U))
    {
        return kStatus_SDIOSLV_DMADataBufferAddrNotAlign;
    }

    SDIOSLV_SetAdmaTableConfig(base, handle->descriptorBuffer, handle->descriptorLen, transfer->dataAddr,
                               transfer->dataSize);

    return kStatus_Success;
}

static void SDIOSLV_TransferHandleFunc0Data(SDIOSLV_Type *base, sdioslv_handle_t *handle, uint32_t interruptFlags)
{
    uint32_t argument = base->ARG_REG_AHB;
    uint32_t blockSize =
        ((base->SIN_MUL_BLK_SIZE & SDIOSLV_SIN_MUL_BLK_SIZE_BLK_SIZE_MASK) >> SDIOSLV_SIN_MUL_BLK_SIZE_BLK_SIZE_SHIFT);
    const uint8_t *csaPointer = (const uint8_t *)base->CSA_POINTER_AHB;
    uint32_t dataSize = 0U, blockCount = SDIOSLV_ARGUMENT_BYTE_BLOCK_COUNT(argument);

    if (SDIOSLV_ARGUMENT_IS_BLOCK_MODE(argument))
    {
        if (blockCount == 0U)
        {
            blockCount = 0x1FFFFF;
        }
        dataSize = blockSize * blockCount;
    }
    else
    {
        if (blockCount == 0U)
        {
            blockCount = 512U;
        }
        dataSize = blockCount;
    }
    /* transfer CSA data */
    if (interruptFlags & (kSDIOSLV_Func0ReadStartFlag | kSDIOSLV_Func0WriteStartFlag | kSDIOSLV_Func0AdmaEndBitFlag))
    {
        dataSize -= handle->transferredFunc0Size;
        if (SDIOSLV_ADMA_DESCRIPTOR_MAX_LENGTH_PER_ENTRY * handle->descriptorLen < dataSize)
        {
            dataSize = SDIOSLV_ADMA_DESCRIPTOR_MAX_LENGTH_PER_ENTRY * handle->descriptorLen;
        }
        if (dataSize)
        {
            SDIOSLV_SetAdmaTableConfig(base, handle->descriptorBuffer, handle->descriptorLen, csaPointer, dataSize);
            handle->transferredFunc0Size += dataSize;
        }
    }

    if (interruptFlags & (kSDIOSLV_Func0ReadTransferOverFlag | kSDIOSLV_Func0WriteTransferOverFlag))
    {
        if (handle->callback != NULL)
        {
            handle->callback(base, kSDIOSLV_FunctionNum0,
                             interruptFlags & kSDIOSLV_Func0WriteTransferOverFlag ? kStatus_SDIOSLV_FuncWriteComplete :
                                                                                    kStatus_SDIOSLV_FuncReadComplete,
                             (void *)csaPointer, handle->transferredFunc0Size, handle->userData);
        }
        SDIOSLV_ClearWriteBlockCount(base);
        SDIOSLV_ClearReadBlockCount(base);
    }
}

static void SDIOSLV_TransferHandleFunc1Data(SDIOSLV_Type *base, sdioslv_handle_t *handle, uint32_t interruptFlags)
{
    uint32_t argument = base->ARG_REG_AHB;
    uint32_t blockSize =
        ((base->SIN_MUL_BLK_SIZE & SDIOSLV_SIN_MUL_BLK_SIZE_BLK_SIZE_MASK) >> SDIOSLV_SIN_MUL_BLK_SIZE_BLK_SIZE_SHIFT);
    uint32_t dataSize = 0U, blockCount = SDIOSLV_ARGUMENT_BYTE_BLOCK_COUNT(argument);

    if (SDIOSLV_ARGUMENT_IS_BLOCK_MODE(argument))
    {
        if (blockCount == 0U)
        {
            blockCount = 0x1FFFFF;
        }
        dataSize = blockSize * blockCount;
    }
    else
    {
        if (blockCount == 0U)
        {
            blockCount = 512U;
        }
        dataSize = blockCount;
    }

    if (interruptFlags & kSDIOSLV_Func1ReadStartFlag)
    {
        SDIOSLV_SetAdmaTableConfig(base, handle->descriptorBuffer, handle->descriptorLen,
                                   handle->txQueue[handle->txQueueDriver].dataAddr, dataSize);
        if (dataSize < handle->txQueue[handle->txQueueDriver].dataSize)
        {
            handle->txQueue[handle->txQueueDriver].dataSize -= dataSize;
            handle->txQueue[handle->txQueueDriver].dataAddr += dataSize;
        }
        else
        {
            handle->txQueue[handle->txQueueDriver].dataAddr = NULL;
        }
    }

    if (interruptFlags & kSDIOSLV_Func1ReadTransferOverFlag)
    {
        if (handle->txQueue[handle->txQueueDriver].dataAddr == NULL)
        {
            handle->txQueueDriver = (handle->txQueueDriver + 1) % SDIOSLV_TRANSMIT_QUEUE_SIZE;
        }

        if (handle->txQueue[handle->txQueueDriver].dataAddr == NULL)
        {
            if (handle->callback != NULL)
            {
                handle->callback(base, kSDIOSLV_FunctionNum1, kStatus_SDIOSLV_FuncReadComplete,
                                 (void *)handle->txQueue[handle->txQueueDriver].dataAddr, dataSize, handle->userData);
            }
            handle->state = kStatus_SDIOSLV_Idle;
        }
        else
        {
            /* trigger sd host that the data is ready to read */
            SDIOSLV_SetIO1ReadDataReady(base, handle->txQueue[handle->txQueueDriver].dataSize);
        }
    }

    if (interruptFlags & kSDIOSLV_Func1WriteStartFlag)
    {
        if (handle->rxPingpongBuffer != NULL)
        {
            SDIOSLV_SetAdmaTableConfig(base, handle->descriptorBuffer, handle->descriptorLen,
                                       (void *)handle->rxPingpongBufferHead, dataSize);
        }
        else
        {
            if (NULL != handle->callback)
            {
                handle->callback(base, kSDIOSLV_FunctionNum1, kStatus_SDIOSLV_FuncWriteRequest, NULL, dataSize,
                                 handle->userData);
            }
        }
    }

    if (interruptFlags & kSDIOSLV_Func1WriteTransferOverFlag)
    {
        handle->callback(base, kSDIOSLV_FunctionNum1, kStatus_SDIOSLV_FuncWriteComplete, NULL, dataSize,
                         handle->userData);
        SDIOSLV_ClearWriteBlockCount(base);
        /* switch ping pong buffer HEAD */
        if (handle->rxPingpongBuffer != NULL)
        {
            handle->rxPingpongBufferHead = handle->rxPingpongBufferHead == handle->rxPingpongBuffer ?
                                               (handle->rxPingpongBuffer + handle->rxPingpongBufferSize) :
                                               handle->rxPingpongBuffer;
        }
    }
}

void SDIOSLV_TransferHandleIRQ(SDIOSLV_Type *base, sdioslv_handle_t *handle)
{
    assert(handle);

    uint32_t globalInterruptStatus    = SDIOSLV_GetGlobalInterruptStatusFlags(base);
    uint32_t function0InterruptStatus = SDIOSLV_GetFuncInterruptStatusFlags(base, kSDIOSLV_FunctionNum0);
    uint32_t function1InterruptStatus = SDIOSLV_GetFuncInterruptStatusFlags(base, kSDIOSLV_FunctionNum1);
    SDIOSLV_EnableGlobalInterrupts(base, kSDIOSLV_GlobalAllInterruptFlag, false);
    SDIOSLV_ClearGlobalInterruptStatusFlags(base, globalInterruptStatus);

    /* Func0 interrupt. */
    if (globalInterruptStatus & kSDIOSLV_Func0InterruptFlag)
    {
        if (function0InterruptStatus & kSDIOSLV_AHBSoftResetFlag)
        {
            base->SIG_AHBSOFT_VALID |= SDIOSLV_SIG_AHBSOFT_VALID_SOFT_RST_AHB_REGISTER_MASK;
        }
        if (function0InterruptStatus & kSDIOSLV_Func0DataTransferInterruptFlag)
        {
            SDIOSLV_TransferHandleFunc0Data(base, handle, function0InterruptStatus);
        }

        SDIOSLV_ClearFuncInterruptStatusFlags(base, kSDIOSLV_FunctionNum0, function0InterruptStatus);
    }

    if (globalInterruptStatus & kSDIOSLV_Func1InterruptFlag)
    {
        if (function1InterruptStatus & kSDIOSLV_Func1DisableFlag)
        {
            /* Call user callback for funtion de-initialization. */
            if (handle->callback)
            {
                handle->callback(base, kSDIOSLV_FunctionNum1, kStatus_SDIOSLV_FuncDisabled, NULL, 0U, handle->userData);
            }
            /* Clear IO ready bit in CCCR. */
            SDIOSLV_ClearIOReady(base, kSDIOSLV_FunctionNum1);
        }

        if (function1InterruptStatus & kSDIOSLV_Func1EnableFlag)
        {
            if (handle->callback)
            {
                /* Call user callback for specific function initialization. */
                handle->callback(base, kSDIOSLV_FunctionNum1, kStatus_SDIOSLV_FuncEnabled, NULL, 0U, handle->userData);
                /* Set IO ready bit in CCCR after success of user initialization. */
                SDIOSLV_SetIOReady(base, kSDIOSLV_FunctionNum1);
            }
        }

        /* exchange message between host and slave */
        if (function1InterruptStatus & (kSDIOSLV_Func1HostMessageFlag | kSDIOSLV_Func1AckToArmFlag))
        {
            if (handle->callback)
            {
                handle->callback(base, kSDIOSLV_FunctionNum1,
                                 function1InterruptStatus & kSDIOSLV_Func1HostMessageFlag ?
                                     kStatus_SDIOSLV_FuncReceivedMSG :
                                     kStatus_SDIOSLV_FuncTransmittedMSG,
                                 NULL, 0U, handle->userData);
            }
        }

        /* function1 data interrupt */
        if (function1InterruptStatus & kSDIOSLV_Func1DataTransferInterruptFlag)
        {
            SDIOSLV_TransferHandleFunc1Data(base, handle, function1InterruptStatus);
        }

        SDIOSLV_ClearFuncInterruptStatusFlags(base, kSDIOSLV_FunctionNum1, function1InterruptStatus);
    }

    SDIOSLV_EnableGlobalInterrupts(base, kSDIOSLV_GlobalAllInterruptFlag, true);
}

#if defined(SDIOSLV)
void SDIOSLV_DriverIRQHandler(void);
void SDIOSLV_DriverIRQHandler(void)
{
    assert(s_sdioslvBase[0]);
    assert(s_sdioslvHandle[0]);

    s_sdioslvIsr(s_sdioslvBase[0], s_sdioslvHandle[0]);
}
#endif
