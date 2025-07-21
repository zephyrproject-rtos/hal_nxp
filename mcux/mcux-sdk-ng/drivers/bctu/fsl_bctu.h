/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_BCTU_H_
#define FSL_BCTU_H_

#include "fsl_common.h"

/*!
 * @addtogroup bctu
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*! @{ */
/*! @brief BCTU driver version 2.1.0. */
#define FSL_BCTU_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
/*! @} */

/*! @brief BCTU interrupt mask. */
enum _bctu_int
{
    /*! Enables an interrupt request when BCTU writes a new conversion result to ADC data register 0. */
    kBCTU_NewDataInt_0 = BCTU_MCR_IEN0_MASK,
    /*! Enables an interrupt request when BCTU writes a new conversion result to ADC data register 1. */
    kBCTU_NewDataInt_1 = BCTU_MCR_IEN1_MASK,
#if defined(FSL_FEATURE_BCTU_ADCDR_COUNT) && (FSL_FEATURE_BCTU_ADCDR_COUNT == 3U)
    /*! Enables an interrupt request when BCTU writes a new conversion result to ADC data register 2. */
    kBCTU_NewDataInt_2 = BCTU_MCR_IEN2_MASK,
#endif /* FSL_FEATURE_BCTU_ADCDR_COUNT */

    /*! Enables an interrupt request for the last conversion in a conversion list. */
    kBCTU_ConvListInt = BCTU_MCR_LIST_IEN_MASK,

    /*! Enables an interrupt request on a trigger flag. */
    kBCTU_TrigIn = BCTU_MCR_TRGEN_MASK,
};

/*! @brief BCTU status flags. */
enum _bctu_status_flags
{
     /*! Indicates that new conversion data is available in ADC data register 0. */
     kBCTU_NewData_0_Ready = BCTU_MSR_NDATA0_MASK,
     /*! Indicates that new conversion data is available in ADC data register 1. */
     kBCTU_NewData_1_Ready = BCTU_MSR_NDATA1_MASK,
#if defined(FSL_FEATURE_BCTU_ADCDR_COUNT) && (FSL_FEATURE_BCTU_ADCDR_COUNT == 3U)
     /*! Indicates that new conversion data is available in ADC data register 2. */
     kBCTU_NewData_2_Ready = BCTU_MSR_NDATA2_MASK,
#endif /* FSL_FEATURE_BCTU_ADCDR_COUNT */

     /*! Indicates that the data in ADC data register 0 has been overwritten with new data. */
     kBCTU_NewData_0_OverWrite = BCTU_MSR_DATAOVR0_MASK,
     /*! Indicates that the data in ADC data register 1 has been overwritten with new data. */
     kBCTU_NewData_1_OverWrite = BCTU_MSR_DATAOVR1_MASK,
#if defined(FSL_FEATURE_BCTU_ADCDR_COUNT) && (FSL_FEATURE_BCTU_ADCDR_COUNT == 3U)
     /*! Indicates that the data in ADC data register 2 has been overwritten with new data. */
     kBCTU_NewData_2_OverWrite = BCTU_MSR_DATAOVR2_MASK,
#endif /* FSL_FEATURE_BCTU_ADCDR_COUNT */

     /*! Indicates that ADC0 has executed the last conversion in a conversion list. */
     kBCTU_ConvList_0_LastConvExecuted = BCTU_MSR_LIST0_Last_MASK,
     /*! Indicates that ADC1 has executed the last conversion in a conversion list. */
     kBCTU_ConvList_1_LastConvExecuted = BCTU_MSR_LIST1_Last_MASK,
#if defined(FSL_FEATURE_BCTU_ADCDR_COUNT) && (FSL_FEATURE_BCTU_ADCDR_COUNT == 3U)
     /*! Indicates that ADC2 has executed the last conversion in a conversion list. */
     kBCTU_ConvList_2_LastConvExecuted = BCTU_MSR_LIST2_Last_MASK,
#endif /* FSL_FEATURE_BCTU_ADCDR_COUNT */

     /*! Indicates at least one ADC was triggered. */
     kBCTU_Trig = BCTU_MSR_TRGF_MASK,
};

/*! @brief BCTU FIFO Interrupt mask. */
enum _bctu_fifo_int
{
    /*! Enables FIFO1 interrupt. */
    kBCTU_FIfo_1_Int = BCTU_FIFOCR_IEN_FIFO1_MASK,
    /*! Enables FIFO2 interrupt. */
    kBCTU_FIfo_2_Int = BCTU_FIFOCR_IEN_FIFO2_MASK,
};

/*! @brief BCTU FIFO status flags. */
enum _bctu_fifo_status_flags
{
     /*! Indicates the number of active entries in FIFO1 exceeds the watermark level. */
     kBCTU_Fifo_1_Int = BCTU_FIFOERR_WM_INT_FIFO1_MASK,
     /*! Indicates the number of active entries in FIFO2 exceeds the watermark level. */
     kBCTU_Fifo_2_Int = BCTU_FIFOERR_WM_INT_FIFO2_MASK,

     /*! Indicates you have attempted to write to full FIFO1. */
     kBCTU_Fifo_1_OverRun = BCTU_FIFOERR_OVR_ERR_FIFO1_MASK,
     /*! Indicates you have attempted to write to full FIFO2. */
     kBCTU_Fifo_2_OverRun = BCTU_FIFOERR_OVR_ERR_FIFO2_MASK,

     /*! Indicates you have attempted to read from empty FIFO1. */
     kBCTU_Fifo_1_UnderRun = BCTU_FIFOERR_UNDR_ERR_FIFO1_MASK,
     /*! Indicates you have attempted to read from empty FIFO2. */
     kBCTU_Fifo_2_UnderRun = BCTU_FIFOERR_UNDR_ERR_FIFO2_MASK,
};

/*! @brief BCTU trigger ADCn to convert. */
enum _bctu_trig_adc
{
    kBCTU_TrigAdc_0 = 1U << 0U, /*!< Trigger ADC 0 to convert. */
    kBCTU_TrigAdc_1 = 1U << 1U, /*!< Trigger ADC 1 to convert. */
#if defined(FSL_FEATURE_BCTU_ADCDR_COUNT) && (FSL_FEATURE_BCTU_ADCDR_COUNT == 3U)
    kBCTU_TrigAdc_2 = 1U << 2U, /*!< Trigger ADC 2 to convert. */
#endif /* FSL_FEATURE_BCTU_ADCDR_COUNT */
};

/*! @brief BCTU software trigger mask. */
enum _bctu_trig_mask
{
    kBCTU_TrigMask_0 = BCTU_SFTRGR1_SFTRG0_MASK,        /*!< Trigger mask 0. */
    kBCTU_TrigMask_1 = kBCTU_TrigMask_0 << 1U,          /*!< Trigger mask 1. */
    kBCTU_TrigMask_2 = kBCTU_TrigMask_0 << 2U,          /*!< Trigger mask 2. */
    kBCTU_TrigMask_3 = kBCTU_TrigMask_0 << 3U,          /*!< Trigger mask 3. */
    kBCTU_TrigMask_4 = kBCTU_TrigMask_0 << 4U,          /*!< Trigger mask 4. */
    kBCTU_TrigMask_5 = kBCTU_TrigMask_0 << 5U,          /*!< Trigger mask 5. */
    kBCTU_TrigMask_6 = kBCTU_TrigMask_0 << 6U,          /*!< Trigger mask 6. */
    kBCTU_TrigMask_7 = kBCTU_TrigMask_0 << 7U,          /*!< Trigger mask 7. */
    kBCTU_TrigMask_8 = kBCTU_TrigMask_0 << 8U,          /*!< Trigger mask 8. */
    kBCTU_TrigMask_9 = kBCTU_TrigMask_0 << 9U,          /*!< Trigger mask 9. */
    kBCTU_TrigMask_10 = kBCTU_TrigMask_0 << 10U,        /*!< Trigger mask 10. */
    kBCTU_TrigMask_11 = kBCTU_TrigMask_0 << 11U,        /*!< Trigger mask 11. */
    kBCTU_TrigMask_12 = kBCTU_TrigMask_0 << 12U,        /*!< Trigger mask 12. */
    kBCTU_TrigMask_13 = kBCTU_TrigMask_0 << 13U,        /*!< Trigger mask 13. */
    kBCTU_TrigMask_14 = kBCTU_TrigMask_0 << 14U,        /*!< Trigger mask 14. */
    kBCTU_TrigMask_15 = kBCTU_TrigMask_0 << 15U,        /*!< Trigger mask 15. */
    kBCTU_TrigMask_16 = kBCTU_TrigMask_0 << 16U,        /*!< Trigger mask 16. */
    kBCTU_TrigMask_17 = kBCTU_TrigMask_0 << 17U,        /*!< Trigger mask 17. */
    kBCTU_TrigMask_18 = kBCTU_TrigMask_0 << 18U,        /*!< Trigger mask 18. */
    kBCTU_TrigMask_19 = kBCTU_TrigMask_0 << 19U,        /*!< Trigger mask 19. */
    kBCTU_TrigMask_20 = kBCTU_TrigMask_0 << 20U,        /*!< Trigger mask 20. */
    kBCTU_TrigMask_21 = kBCTU_TrigMask_0 << 21U,        /*!< Trigger mask 21. */
    kBCTU_TrigMask_22 = kBCTU_TrigMask_0 << 22U,        /*!< Trigger mask 22. */
    kBCTU_TrigMask_23 = kBCTU_TrigMask_0 << 23U,        /*!< Trigger mask 23. */
    kBCTU_TrigMask_24 = kBCTU_TrigMask_0 << 24U,        /*!< Trigger mask 24. */
    kBCTU_TrigMask_25 = kBCTU_TrigMask_0 << 25U,        /*!< Trigger mask 25. */
    kBCTU_TrigMask_26 = kBCTU_TrigMask_0 << 26U,        /*!< Trigger mask 26. */
    kBCTU_TrigMask_27 = kBCTU_TrigMask_0 << 27U,        /*!< Trigger mask 27. */
    kBCTU_TrigMask_28 = kBCTU_TrigMask_0 << 28U,        /*!< Trigger mask 28. */
    kBCTU_TrigMask_29 = kBCTU_TrigMask_0 << 29U,        /*!< Trigger mask 29. */
    kBCTU_TrigMask_30 = kBCTU_TrigMask_0 << 30U,        /*!< Trigger mask 30. */
    kBCTU_TrigMask_31 = kBCTU_TrigMask_0 << 31U,        /*!< Trigger mask 31. */
};

/*! @brief BCTU software trigger group. */
typedef enum _bctu_trig_group
{
    kBCTU_TrigGroup_0 = 0U, /*!< Trigger group 0. */
    kBCTU_TrigGroup_1 = 1U, /*!< Trigger group 1. */
#if defined(FSL_FEATURE_BCTU_ADCDR_COUNT) && (FSL_FEATURE_BCTU_ADCDR_COUNT == 3U)
    kBCTU_TrigGroup_2 = 2U, /*!< Trigger group 2. */
#endif /* FSL_FEATURE_BCTU_ADCDR_COUNT */
} bctu_trig_group_t;

/*! @brief BCTU FIFO index. */
typedef enum _bctu_fifo
{
    kBCTU_Fifo_1 = 0x0U,    /*!< FIFO1 */
    kBCTU_Fifo_2 = 0x1U,    /*!< FIFO2 */
} bctu_fifo_t;

/*! @brief The destination for storing the conversion results. */
typedef enum _bctu_adc_data_dest
{
    kBCTU_DataDest_AdcReg = 0x0U, /*!< ADC-specific data registers. */
    kBCTU_DataDest_Fifo1 = 0x1U,  /*!< FIFO1. */
    kBCTU_DataDest_Fifo2 = 0x2U,  /*!< FIFO2. */
} bctu_adc_data_dest_t;

/*! @brief BCTU trigger conversion type. */
typedef enum _bctu_trig_conv_type
{
    kBCTU_TrigRes_SingleConv = 0x0U,    /*!< Single conversion. */
    kBCTU_TrigRes_ConvList = 0x1U,      /*!< Conversion list conversions. */
} bctu_trig_conv_type_t;

/*! @brief Controls the protection of write-protected registers. */
typedef enum _bctu_write_protect
{
    kBCTU_ProtectEn = 0x0U,                 /*!< Enable protection. */
    kBCTU_ProtectDis_OneWriteCycle = 0x9U,  /*!< Disable protection for one write cycle. */
    kBCTU_ProtectDis_Permanent = 0xAU,      /*!< Disable protection permanently. */
} bctu_write_protect_t;

/*! @brief BCTU configuration. */
typedef struct _bctu_config
{
    bool debugFreezeEn;                 /*!< Disables all hardware trigger inputs but leaves
                                          the software trigger enabled. Debug Freeze isolates
                                          BCTU from external triggers and allows you to manually
                                          trigger a conversion and read the conversion result. */
    bctu_write_protect_t writeProtect;  /*!< Specify the write protect mode. */
} bctu_config_t;

/*! @brief BCTU trigger configuration. */
typedef struct _bctu_trig_config
{
    bool enableLoop;                    /*!< Decides whether to enable current trigger executes in a loop. */
    uint8_t chanAddr;                   /*!< Sets ADC channel or a conversion list address. */
    uint8_t trigIndex;                  /*!< Specify trigger index. For hardware trigger, please use the member
                                             of enumeration @_bctu_trig_source. For software trigger, please
                                             specify a value directly and make sure that the value is within
                                             the allowed range. Generally speaking, the number of software triggers
                                             is the same as the number of hardware triggers. */
    uint32_t targetAdc;                 /*!< Sets which ADCs for conversion, @ref _bctu_trig_adc. */
    bctu_trig_conv_type_t trigRes;      /*!< Specify the trigger resolution. */
    bctu_adc_data_dest_t dataDest;      /*!< Specify the destination for storing the conversion results. */
} bctu_trig_config_t;

/*! @brief BCTU conversion list configuration. */
typedef struct _bctu_convlist_config
{
    bool lastChan;              /*!< Specifies this element as the last channel in the conversion list. */
    bool lastChanPlusOne;       /*!< Specifies this element as the next-to-last channel in the conversion list. */
    bool waitTrig;              /*!< Instructs conversion list execution to stop after executing the current ADC channel.
                                  Execution begins again when the same trigger, which started the conversion list, reoccurs. */
    bool waitTrigPlusOne;       /*!< Next Channel Wait For Trigger Plus 1. */
    uint8_t adcChan;            /*!< Specifies the ADC channel to use. */
    uint8_t adcChanPlusOne;     /*!< ADC Channel Selection Plus 1. */
} bctu_convlist_config_t;

/*! @brief ADC conversion result. */
typedef struct _bctu_adc_conv_result
{
    bool trigConvType;      /*!< Indicates whether the conversion was part of a conversion list (0x1U)or a single conversion trigger (0x0U). */
    bool lastConv;      /*!< For conversion list conversions, indicates this conversion result is the last conversion of the conversion list. */
    uint8_t trigSrc;    /*!< Contains the trigger number used to trigger the conversion. */
    uint8_t chanNum;    /*!< Contains the ADC channel used for the conversion. */
    uint16_t data;      /*!< Contains the data from the conversion. */
} bctu_adc_conv_result_t;

/*! @brief BCTU fifo result. */
typedef struct _bctu_fifo_res
{
    uint8_t trigSrc;    /*!< Indicates the trigger number used to trigger the conversion.. */
    uint8_t chanNum;    /*!< Indicates the ADC channel used for the conversion. */
    uint8_t adcNum;     /*!< Indicates the ADC used for conversion. */
    uint16_t convRes;   /*!< Contains the data from the conversion. */
} bctu_fifo_res_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name BCTU Initialization, De-Initialization, and Configuration.
 * @{
 */
/*!
 * @brief Gets the default configuration for BCTU.
 *
 * @param config Pointer to BCTU configuration structure.
 */
void BCTU_GetDefaultConfig(bctu_config_t *config);

/*!
 * @brief Initializes the BCTU.
 *
 * @param base BCTU peripheral base address.
 * @param config Pointer to BCTU configuration structure.
 */
void BCTU_Init(BCTU_Type *base, const bctu_config_t *config);

/*!
 * @brief Deinitializes the BCTU.
 *
 * @param base BCTU peripheral base address.
 */
void BCTU_Deinit(BCTU_Type *base);

/*!
 * @brief BCTU conversion list configuration.
 *
 * @param base BCTU peripheral base address.
 * @param config Pointer to BCTU conversion list configuration structure.
 * @param convListIndex conversion list index.
 */
void BCTU_SetConvListConfig(BCTU_Type *base, const bctu_convlist_config_t *config, uint8_t convListIndex);

/*!
 * @brief Assert/Deassert BCTU software reset.
 *
 * @param base BCTU peripheral base address.
 * @param enable Indicates whether to assert or deassert BCTU software reset.
 * - \b true Assert BCTU software reset.
 * - \b false Deassert BCTU software reset.
 */
static inline void BCTU_AssertSoftwareReset(BCTU_Type *base, bool enable)
{
    if (enable)
    {
        base->MCR |= BCTU_MCR_Software_Reset_MASK;
    }
    else
    {
        base->MCR &= ~BCTU_MCR_Software_Reset_MASK;
    }
}

/*!
 * @brief Enable/Disable BCTU.
 *
 * @param base BCTU peripheral base address.
 * @param enable Indicates whether to enable or disable the BCTU module.
 * - \b true Enable BCTU module.
 * - \b false Disable BCTU module.
 */
static inline void BCTU_EnableModule(BCTU_Type *base, bool enable)
{
    if (enable)
    {
        base->MCR &= ~BCTU_MCR_MDIS_MASK;
    }
    else
    {
        base->MCR |= BCTU_MCR_MDIS_MASK;
    }
}

/*!
 * @brief Enable/Disable DMA operation when new data is available in data result register.
 *
 * @param base BCTU peripheral base address.
 * @param instance ADC instance @ref _bctu_trig_adc.
 * @param enable Indicates whether to enable or disable the DMA operation.
 * - \b true Enable the DMA operation.
 * - \b false Disable the DMA operation.
 */
static inline void BCTU_EnableDmaTrans(BCTU_Type *base, enum _bctu_trig_adc instance, bool enable)
{
    if (enable)
    {
        base->MCR |= (BCTU_MCR_DMA0_MASK << ((uint32_t)instance / 2U));
    }
    else
    {
        base->MCR &= ~(BCTU_MCR_DMA0_MASK << ((uint32_t)instance / 2U));
    }
}
/*!
 * @}
 */

/*!
 * @name BCTU Interrupts Enable/Disable and Status Flags Get/Clear.
 * @{
 */
/*!
 * @brief Enable/Disable BCTU interrupts.
 *
 * @param base BCTU peripheral base address.
 * @param mask BCTU interrupt mask, @ref _bctu_int.
 * @param enable Indicates whether to enable or disable the data interrupt.
 * - \b true Enable interrupt.
 * - \b false Disable interrupt.
 */
static inline void BCTU_EnableInt(BCTU_Type *base, uint32_t mask, bool enable)
{
    if (enable)
    {
        base->MCR |= mask;
    }
    else
    {
        base->MCR &= ~mask;
    }
}

/*!
 * @brief Get BCTU status flags.
 *
 * @param base BCTU peripheral base address._bctu_status_flags.
 * @return BCTU status flags, @ref _bctu_status_flags.
 */
static inline uint32_t BCTU_GetStatusFlags(BCTU_Type *base)
{
    return base->MSR;
}

/*!
 * @brief Clear BCTU status flags.
 *
 * @param base BCTU peripheral base address.
 * @param mask Mask value for flags to be cleared, refer @ref _bctu_status_flags.
 */
static inline void BCTU_ClearStatusFlags(BCTU_Type *base, uint32_t mask)
{
    base->MSR = (mask << 16U);
}
/*!
 * @}
 */

/*!
 * @name BCTU Trigger Configuration.
 * @{
 */
/*!
 * @brief BCTU trigger configuration.
 *
 * @param base BCTU peripheral base address.
 * @param config Pointer to BCTU trigger configuration structure.
 */
void BCTU_SetTrigConfig(BCTU_Type *base, const bctu_trig_config_t *config);

/*!
 * @brief Enable/Disable global trigger.
 *
 * @param base BCTU peripheral base address.
 * @param enable Indicates whether to enable or disable the global trigger.
 * - \b true Enable global trigger.
 * - \b false Disable global trigger.
 */
static inline void BCTU_EnableGlobalTrig(BCTU_Type *base, bool enable)
{
    if (enable)
    {
        base->MCR |= BCTU_MCR_GTRGEN_MASK;
    }
    else
    {
        base->MCR &= ~BCTU_MCR_GTRGEN_MASK;
    }
}

/*!
 * @brief Enable BCTU hardware trigger.
 *
 * @param base BCTU peripheral base address.
 * @param trigIndex Trigger index, @ref _bctu_trig_source
 * @param enable Indicates whether to enable or disable the hardware trigger.
 * - \b true Enable hardware trigger.
 * - \b false Disable hardware trigger.
 */
static inline void BCTU_EnableHardwareTrig(BCTU_Type *base, enum _bctu_trig_source trigIndex, bool enable)
{
    if (enable)
    {
        base->TRGCFG[trigIndex] |= BCTU_TRGCFG_TRIGEN_MASK;
    }
    else
    {
        base->TRGCFG[trigIndex] &= ~ BCTU_TRGCFG_TRIGEN_MASK;
    }
}

/*!
 * @brief Enable BCTU software trigger.
 *
 * @param base BCTU peripheral base address.
 * @param trigGroup Trigger group, @ref bctu_trig_group_t
 * @param trigMask Trigger mask, @ref _bctu_trig_mask
 */
static inline void BCTU_EnableSoftwareTrig(BCTU_Type *base, bctu_trig_group_t trigGroup, uint32_t trigMask)
{
    (*((volatile uint32_t *)(&(base->SFTRGR1)) + (uint32_t)trigGroup)) = trigMask;
}
/*!
 * @}
 */

/*!
 * @name BCTU FIFO Operation.
 * @{
 */
/*!
 * @brief Get BCTU FIFO result data.
 *
 * @param base BCTU peripheral base address.
 * @param fifoIndex FIFO index @ref bctu_fifo_t.
 * @param result Structure to obtain BCTU FIFO result, @ref bctu_fifo_res_t.
 */
static inline void BCTU_GetFifoResult(BCTU_Type *base, bctu_fifo_t fifoIndex, bctu_fifo_res_t *result)
{
    assert(result != NULL);
    
    uint32_t tmp = *((volatile const uint32_t *)(&(base->FIFO1DR)) + (uint8_t)fifoIndex);

    result->trigSrc = (uint8_t)((tmp & BCTU_FIFO1DR_TRG_SRC_MASK) >> BCTU_FIFO1DR_TRG_SRC_SHIFT);
    result->chanNum = (uint8_t)((tmp & BCTU_FIFO1DR_CH_MASK) >> BCTU_FIFO1DR_CH_SHIFT);
    result->adcNum  = (uint8_t)((tmp & BCTU_FIFO1DR_ADC_NUM_MASK) >> BCTU_FIFO1DR_ADC_NUM_SHIFT);
    result->convRes = (uint16_t)((tmp & BCTU_FIFO1DR_ADC_DATA_MASK) >> BCTU_FIFO1DR_ADC_DATA_SHIFT);
}

/*!
 * @brief Set BCTU FIFO watermark.
 *
 * @param base BCTU peripheral base address.
 * @param fifoIndex FIfo index @ref bctu_fifo_t.
 * @param watermark FIFO watermark.
 */
static inline void BCTU_SetFifoWaterMark(BCTU_Type *base, bctu_fifo_t fifoIndex, uint8_t watermark)
{
    base->FIFOWM = ((base->FIFOWM & ~((uint32_t)BCTU_FIFOWM_WM_FIFO1_MASK << (8U * (uint8_t)fifoIndex))) |
                                        ((uint32_t)watermark << (8U * (uint8_t)fifoIndex)));
}

/*!
 * @brief Enable/Disable FIFO DMA transfer.
 *
 * @param base BCTU peripheral base address.
 * @param fifoIndex FIFO index @ref bctu_fifo_t.
 * @param enable Indicates whether to enable or disable the FIFO DMA transfer.
 * - \b true Enable the FIFO DMA transfer.
 * - \b false Disable the FIFO DMA transfer.
 */
static inline void BCTU_EnableFifoDma(BCTU_Type *base, bctu_fifo_t fifoIndex, bool enable)
{
    if (enable)
    {
        base->FIFOCR |= (BCTU_FIFOCR_DMA_EN_FIFO1_MASK << (uint8_t)fifoIndex);
    }
    else
    {
        base->FIFOCR &= ~(BCTU_FIFOCR_DMA_EN_FIFO1_MASK << (uint8_t)fifoIndex);
    }
}

/*!
 * @brief Enable/Disable FIFO interrupt.
 *
 * @param base BCTU peripheral base address.
 * @param mask BCTU FIFO interrupt mask, @ref _bctu_fifo_int.
 * @param enable Indicates whether to enable or disable the FIFO interrupt.
 * - \b true Enable the FIFO interrupt.
 * - \b false Disable the FIFO interrupt.
 */
static inline void BCTU_EnableFifoInt(BCTU_Type *base, uint32_t mask, bool enable)
{
    if (enable)
    {
        base->FIFOCR |= mask;
    }
    else
    {
        base->FIFOCR &= ~mask;
    }
}

/*!
 * @brief Get BCTU FIFO status flag.
 *
 * @param base BCTU peripheral base address.
 * @return FIFO status flags, @ref _bctu_fifo_status_flags.
 */
static inline uint32_t BCTU_GetFifoStatusFlags(BCTU_Type *base)
{
    return base->FIFOERR;
}

/*!
 * @brief Clear BCTU status flags.
 *
 * @param base BCTU peripheral base address.
 * @param mask Mask value for flags to be cleared, refer @ref _bctu_fifo_status_flags.
 */
static inline void BCTU_ClearFifoStatusFlags(BCTU_Type *base, uint32_t mask)
{
    base->FIFOERR = mask;
}

/*!
 * @brief Get BCTU FIFO full flag.
 *
 * @param base BCTU peripheral base address.
 * @param fifoIndex FIFO index @ref bctu_fifo_t.
 * @return FIFO full flag.
 * - \b true FIFO full.
 * - \b false FIFO not full.
 */
static inline bool BCTU_GetFifoFullFlag(BCTU_Type *base, bctu_fifo_t fifoIndex)
{
    return (0U != (base->FIFOSR & ((uint32_t)BCTU_FIFOSR_FULL_FIFO1_MASK << (uint8_t)fifoIndex)));
}

/*!
 * @brief Get BCTU FIFO counter.
 *
 * @param base BCTU peripheral base address.
 * @param fifoIndex FIFO index @ref bctu_fifo_t.
 * @return FIFO counter.
 */
static inline uint8_t BCTU_GetFifoCounter(BCTU_Type *base, bctu_fifo_t fifoIndex)
{
    return (uint8_t)(uint32_t)((base->FIFOCNTR & (BCTU_FIFOCNTR_CNTR_FIFO1_MASK << ((uint32_t)fifoIndex * 8U)))
                                >> (BCTU_FIFOCNTR_CNTR_FIFO1_SHIFT + ((uint32_t)fifoIndex * 8U)));
}
/*!
 * @}
 */

/*!
 * @name BCTU trigger result.
 * @{
 */
/*!
 * @brief Get ADC conversion result.
 *
 * @param base BCTU peripheral base address.
 * @param instance ADC instance @ref _bctu_trig_adc.
 * @param result Structure to obtain ADC conversion result, @ref bctu_adc_conv_result_t.
 */
static inline void BCTU_GetConvResult(BCTU_Type *base, enum _bctu_trig_adc instance, bctu_adc_conv_result_t *result)
{
    assert(result != NULL);
    
    uint32_t tmp = base->ADCDR[(uint32_t)instance / 2U];

    result->trigConvType = (bool)(uint32_t)((tmp & BCTU_ADCDR_LIST_MASK) >> BCTU_ADCDR_LIST_SHIFT);
    result->lastConv = (bool)(uint32_t)((tmp & BCTU_ADCDR_LAST_MASK) >> BCTU_ADCDR_LAST_SHIFT);
    result->trigSrc  = (uint8_t)(uint32_t)((tmp & BCTU_ADCDR_TRG_SRC_MASK) >> BCTU_ADCDR_TRG_SRC_SHIFT);
    result->chanNum  = (uint8_t)(uint32_t)((tmp & BCTU_ADCDR_CH_MASK) >> BCTU_ADCDR_CH_SHIFT);
    result->data     = (uint16_t)(uint32_t)((tmp & BCTU_ADCDR_ADC_DATA_MASK) >> BCTU_ADCDR_ADC_DATA_SHIFT);
}
/*!
 * @}
 */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_BCTU_H_ */
