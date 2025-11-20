/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_mipi_dsi.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.mipi_dsi2_dwc"
#endif

/* The timeout cycles to wait for DSI status. */
#ifndef FSL_MIPI_DSI_TIMEOUT
#define FSL_MIPI_DSI_TIMEOUT 0x1000U
#endif

typedef union _u32_f32
{
    float f32;
    uint32_t u32;
} u32_f32_t;

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to MIPI DSI bases for each instance. */
static DSI_V2_HOST_DSI_Type *const s_dsiBases[] = DSI_V2_HOST_DSI_BASE_PTRS;

static uint32_t Vco_Cpbias_Table[18][3] = {{49, 2, 1},   {65, 1, 1},   {75, 51, 0},  {98, 50, 0},   {131, 49, 0},
                                           {151, 35, 0}, {197, 34, 0}, {262, 33, 0}, {302, 19, 0},  {393, 18, 0},
                                           {525, 17, 0}, {603, 51, 1}, {787, 50, 1}, {1050, 49, 1}, {1207, 3, 0},
                                           {1575, 2, 0}, {2100, 1, 0}, {2250, 0, 0}};

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Gets how may bits in one pixel.
 *
 * @param config Pointer to the pixel format.
 * @return Bit count in one pixel.
 */
static uint8_t DSI_GetBitsPerPixel(const dsi_ipi_config_t *config);

/*!
 * @brief MIPI DSI check Fifo status.
 *
 * @param base MIPI DSI main peripheral base address.
 * @param config Pointer to dsi config .
 */
static uint8_t DSI_ApbCheckFifoState(DSI_V2_HOST_MAIN_Type *base, const dsi_config_t *config);
/*!
 * @brief Prepares and starts the DSI APB transfer.
 *
 * This function fills TX data to DSI TX FIFO, sets the packet control
 * register then start the trasnfer by writting the header.
 *
 * @param base MIPI DSI dsi peripheral base address.
 * @param base MIPI DSI int peripheral base address.
 * @param xfer The transfer definition.
 * @retval kStatus_Success It is ready to start transfer.
 * @retval kStatus_DSI_NotSupported The transfer format is not supported.
 */
static status_t DSI_PrepareApbTransfer(DSI_V2_HOST_DSI_Type *base, DSI_V2_HOST_INT_Type *inter, dsi_transfer_t *xfer);

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint8_t DSI_GetBitsPerPixel(const dsi_ipi_config_t *config)
{
    uint8_t bpp = 0U;
    switch (config->dsi_fmt)
    {
        case kDSI_Format_RGB565:
            bpp = 16U;
            break;
        case kDSI_Format_RGB666_PACKED:
            bpp = 18U;
        case kDSI_Format_RGB888:
        case kDSI_Format_RGB666:
            bpp = 24U;
            break;
        default:
            assert(false);
            break;
    }

    return bpp;
}

static uint8_t DSI_ApbCheckFifoState(DSI_V2_HOST_MAIN_Type *base, const dsi_config_t *config)
{
    uint32_t fifostatus;

    /* Set the MIPI DSI FIFO whose status you want to read. */
    base->OBS_FIFO_SEL = config->fifo;

    fifostatus = base->OBS_FIFO_STATUS;

    if ((fifostatus & DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_EMPTY_MASK) != 0)
    {
        return kDSI_FifoEmpty;
    }
    else if ((fifostatus & DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_ALMOST_EMPTY_MASK) != 0)
    {
        return kDSI_FifoAlmostEmpty;
    }
    else if ((fifostatus & DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_HALF_FULL_MASK) != 0)
    {
        return kDSI_FifoHalfFull;
    }
    else if ((fifostatus & DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_ALMOST_FULL_MASK) != 0)
    {
        return kDSI_FifoAlmostfFull;
    }
    else if ((fifostatus & DSI_V2_HOST_MAIN_OBS_FIFO_STATUS_FULL_MASK) != 0)
    {
        return kDSI_FifoFull;
    }

    return kStatus_Fail;
}

/*!
 * @brief Convert IEEE 754 float value to the value could be written to registers.
 *
 * This function converts the float value to integer value to set the scaler parameters.
 *
 * @param floatValue The float value to convert.
 * @param intBits Bits number of integer part in result.
 * @param fracBits Bits number of fractional part in result.
 * @return The value to set to register.
 */
uint32_t MIPI_ConvertFloat(float floatValue, uint8_t intBits, uint8_t fracBits)
{
    /* One bit reserved for sign bit. */
    assert(intBits + fracBits + 1U < 32U);

    u32_f32_t u32_f32;
    uint32_t ret;
    uint32_t expBits;

    u32_f32.f32        = floatValue;
    uint32_t floatBits = u32_f32.u32;
    expBits            = (floatBits & 0x7F800000U) >> 23U;
    int32_t expValue   = (int32_t)expBits - 127;

    ret = (floatBits & 0x007FFFFFU) | 0x00800000U;
    expValue += (int32_t)fracBits;

    if (expValue < 0)
    {
        return 0U;
    }
    else if (expValue > 23)
    {
        /* should not exceed 31-bit when left shift. */
        assert((expValue - 23) <= 7);
        ret <<= ((uint32_t)expValue - 23UL);
    }
    else
    {
        ret >>= (23UL - (uint32_t)expValue);
    }

    /* Set the sign bit. */
    if (0U != (floatBits & 0x80000000UL))
    {
        ret = ((~(uint32_t)ret) + 1U) & ~(0xFFFFFFFFU << (intBits + fracBits + 1U));
    }

    return ret;
}

/*!
 * @brief Updates the Horizontal timing parameter cycles.
 *
 * @param ipi MIPI DSI ipi host peripheral base address.
 * @param config Pointer to the IPI interface configuration.
 * @param ratio Ratio of frequencies of IPI / SYS clock.
 */
void DSI_ConfigHorizontalParams(DSI_V2_HOST_IPI_Type *ipi, const dsi_ipi_config_t *config, float ratio)
{
    /* Update and configure the horizontal timing parameters. */
    ipi->IPI_VID_HSA_MAN_CFG   = MIPI_ConvertFloat(ratio * config->hsa, 14, 16);
    ipi->IPI_VID_HBP_MAN_CFG   = MIPI_ConvertFloat(ratio * config->hbp, 14, 16);
    ipi->IPI_VID_HACT_MAN_CFG  = MIPI_ConvertFloat(ratio * config->hactive, 14, 16);
    ipi->IPI_VID_HLINE_MAN_CFG = MIPI_ConvertFloat(ratio * config->hline, 14, 16);
}

/*!
 * @brief Gets the MIPI DSI host controller instance from peripheral base address.
 *
 * @param base MIPI DSI dsi peripheral base address.
 * @return MIPI DSI instance.
 */
uint32_t DSI_GetInstance(DSI_V2_HOST_DSI_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_dsiBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_dsiBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_dsiBases));

    return instance;
}

/*!
 * @brief Initializes the MIPI DSI host with the user configuration.
 *
 * This function initializes the MIPI DSI host with the configuration, it should
 * be called before other MIPI DSI driver functions.
 *
 * @param main MIPI DSI main peripheral base address.
 * @param dsi  MIPI DSI dsi peripheral base address.
 * @param inter MIPI DSI int peripheral base address.
 * @param config Pointer to the dsi configuration structure.
 */
void DSI_Init(DSI_V2_HOST_MAIN_Type *base, DSI_V2_HOST_DSI_Type *dsi, DSI_V2_HOST_INT_Type *inter, const dsi_config_t *config)
{
    assert(config);

    /* Reset the module before configuration. */
    base->PWR_UP     = 0U;
    base->SOFT_RESET = 0U;
    /* Select manual mode as default. */
    base->MANUAL_MODE_CFG = config->manualmode;

    /*
     * Set the PHY timeout, timeout function is disabled if set into 0U.
     * Its basely about high-speed transmission, low-power data transmission, and turnaround.
     */
    base->TO_HSTX_CFG     = config->HsTxTimeout;
    base->TO_HSTXRDY_CFG  = config->HsTxReadyTimeout;
    base->TO_LPRX_CFG     = config->lpRxTimeout;
    base->TO_LPTXRDY_CFG  = config->lpTxDataReadyTimeout;
    base->TO_LPTXTRIG_CFG = config->lpTxTriggerTimeout;
    base->TO_LPTXULPS_CFG = config->lpTxUlpsEntryTimeout;
    base->TO_BTA_CFG      = config->BtaTimeout;

    /* Check and clear RX fifo into initial state. */
    while (DSI_ApbCheckFifoState(base, config) == kDSI_FifoFull)
    {
        base->OBS_FIFO_CTRL = DSI_V2_HOST_MAIN_OBS_FIFO_CTRL_FIFO_MANUAL_INIT_MASK;
    }

    /* Configure package flags, whether to enable BTA, EoTp. */
    dsi->DSI_GENERAL_CFG = (uint32_t)config->packageFlags;

    /* Disable dsi virtual channel */
    dsi->DSI_VCID_CFG |= config->dsivirtualchannel;

    /* Disable all interrupts by default, user could enable the desired interrupts later. */
    inter->INT_UNMASK_PHY = 0U;
    inter->INT_UNMASK_TO  = 0U;
    inter->INT_UNMASK_ACK = 0U;
    inter->INT_UNMASK_IPI = 0U;
    inter->INT_UNMASK_PRI = 0U;
    inter->INT_UNMASK_CRI = 0U;
}

/*!
 * @brief Deinitializes an MIPI DSI main host.
 *
 * This function should be called after all bother MIPI DSI driver functions.
 *
 * @param base MIPI DSI main peripheral base address.
 */
void DSI_Deinit(DSI_V2_HOST_MAIN_Type *base)
{
    base->PWR_UP     = 0U;
    base->SOFT_RESET = 0U;
}

/*!
 * @brief Gets the default configuration to initialize the MIPI DSI host.
 *
 * The default value is:
 * code
 * config->operatemode            = kDSI_CommandMode;
 * config->packageFlags           = kDSI_DisableAll;
 * config->HsTxTimeout            = 0U;
 * config->HsTxReadyTimeout       = 0U;
 * config->lpRxTimeout            = 0U;
 * config->lpTxDataReadyTimeout   = 0U;
 * config->lpTxTriggerTimeout     = 0U;
 * config->lpTxUlpsEntryTimeout   = 0U;
 * config->BtaTimeout             = 0U;
 * config->manualmode             = kDSI_ManualMode;
 * config->videoMode              = kDSI_IpiNonBurstWithSyncPulse;
 * endcode
 *
 * @param config Pointer to a user-defined configuration structure.
 */
void DSI_GetDefaultConfig(dsi_config_t *config)
{
    assert(config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->operatemode          = kDSI_CommandMode;
    config->packageFlags         = kDSI_DisableAll;
    config->HsTxTimeout          = 0U;
    config->HsTxReadyTimeout     = 0U;
    config->lpRxTimeout          = 0U;
    config->lpTxDataReadyTimeout = 0U;
    config->lpTxTriggerTimeout   = 0U;
    config->lpTxUlpsEntryTimeout = 0U;
    config->BtaTimeout           = 0U;
    config->manualmode           = kDSI_ManualMode;
    config->videoMode            = kDSI_IpiNonBurstWithSyncPulse;
}

/*!
 * @brief Configure the MIDPI DSI IPI interface.
 *
 * This function sets the IPI interface configuration, it should be used in
 * video mode.
 *
 * @param ipi MIPI DSI ipi peripheral base address.
 * @param config Pointer to the IPI configuration.
 *
 */
void DSI_SetIpiConfig(DSI_V2_HOST_IPI_Type *ipi, const dsi_ipi_config_t *config)
{
    assert(config);

    uint8_t ipi_format, ipi_depth;

    switch (config->dsi_fmt)
    {
        case kDSI_Format_RGB888:
            ipi_format = kDSI_IPIRGB;
            ipi_depth  = kDSI_IPIdepth8bits;
            break;
        case kDSI_Format_RGB565:
            ipi_format = kDSI_IPIRGB;
            ipi_depth  = kDSI_IPIDepth565bits;
            break;
        case kDSI_Format_RGB666_PACKED:
        case kDSI_Format_RGB666:
            ipi_format = kDSI_IPIRGB;
            ipi_depth  = kDSI_IPIDepth6bits;
            break;
        default:
            assert(false);
            break;
    }

    uint32_t reg = ipi->IPI_COLOR_MAN_CFG;

    reg &= ~(DSI_V2_HOST_IPI_IPI_COLOR_MAN_CFG_IPI_FORMAT_MASK | DSI_V2_HOST_IPI_IPI_COLOR_MAN_CFG_IPI_DEPTH_MASK);
    reg |= DSI_V2_HOST_IPI_IPI_COLOR_MAN_CFG_IPI_FORMAT(ipi_format) | DSI_V2_HOST_IPI_IPI_COLOR_MAN_CFG_IPI_DEPTH(ipi_depth);

    ipi->IPI_COLOR_MAN_CFG = reg;

    /* Set vertical timing config */
    ipi->IPI_VID_VSA_MAN_CFG  = config->vsa;
    ipi->IPI_VID_VBP_MAN_CFG  = config->vbp;
    ipi->IPI_VID_VACT_MAN_CFG = config->vactive;
    ipi->IPI_VID_VFP_MAN_CFG  = config->vfp;

    if (config->hibernateType == kDSI_IPIHibULPS)
    {
        ipi->IPI_HIBERNATE_CFG =
            (ipi->IPI_HIBERNATE_CFG & ~DSI_V2_HOST_IPI_IPI_HIBERNATE_CFG_HIB_ULPS_WAKEUP_TIME_MASK) |
            DSI_V2_HOST_IPI_IPI_HIBERNATE_CFG_HIB_ULPS_WAKEUP_TIME(config->dsi_ipi_hibtime);
    }

    ipi->IPI_HIBERNATE_CFG = (ipi->IPI_HIBERNATE_CFG & ~DSI_V2_HOST_IPI_IPI_HIBERNATE_CFG_HIB_TYPE_MASK) |
                             DSI_V2_HOST_IPI_IPI_HIBERNATE_CFG_HIB_TYPE(config->hibernateType);

    ipi->IPI_LANES_MAN_CFG  = config->dsi_ipi_lane;
    ipi->IPI_PIX_PKT_CFG    = config->hactive;
    ipi->IPI_MAPPING_CFG    = config->dsi_ipi_mapping;
    ipi->IPI_FIFO_DEPTH_CFG = config->ipi_fifo_depth_value;
}

/*!
 * @brief Set the operation mode configuration.
 *
 * This function configures the operation mode for DSI.
 *
 * @param base MIPI DSI main peripheral base address.
 * @param dsi MIPI DSI dsi peripheral base address.
 * @param config Pointer to the DSI configuration structure.
 */
void DSI_SetOperateMode(DSI_V2_HOST_MAIN_Type *base, DSI_V2_HOST_DSI_Type *dsi, const dsi_config_t *config)
{
    assert(config);

    if (config->operatemode == kDSI_VideoMode)
    {
        uint32_t reg = dsi->DSI_VID_TX_CFG;
        reg &= ~(DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HSA_HS_EN_MASK | DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HBP_HS_EN_MASK |
                 DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HFP_HS_EN_MASK | DSI_V2_HOST_DSI_DSI_VID_TX_CFG_VID_MODE_TYPE_MASK);
        reg |= DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HSA_HS_EN_MASK | DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HBP_HS_EN_MASK |
               DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HFP_HS_EN_MASK | (config->videoMode);

        /* Set video transmission options according into user configuration. */
        dsi->DSI_VID_TX_CFG = reg;
    }

    base->MODE_CTRL = DSI_V2_HOST_MAIN_MODE_CTRL_MODE_CTRL(config->operatemode);
}

/*!
 * @brief Set the MIPI DSI phy configuration.
 *
 * This function configures the phy register for DSI setting.
 *
 * @param base MIPI DSI phy peripheral base address.
 * @param phyConfig Pointer to the DSI phy configuration structure.
 */
void DSI_SetPhyConfig(DSI_V2_HOST_PHY_Type *dsi_phy, const dsi_phy_config_t *phyConfig)
{
    assert(phyConfig);

    dsi_phy->PHY_MODE_CFG = (dsi_phy->PHY_MODE_CFG & ~(DSI_V2_HOST_PHY_PHY_MODE_CFG_PHY_TYPE_MASK |
                                                       DSI_V2_HOST_PHY_PHY_MODE_CFG_PHY_LANES_MASK |
                                                       DSI_V2_HOST_PHY_PHY_MODE_CFG_PPI_WIDTH_MASK)) |
                            DSI_V2_HOST_PHY_PHY_MODE_CFG_PHY_TYPE(phyConfig->phymode) |
                            DSI_V2_HOST_PHY_PHY_MODE_CFG_PHY_LANES(phyConfig->numLanes) |
                            DSI_V2_HOST_PHY_PHY_MODE_CFG_PPI_WIDTH(phyConfig->ppiwidth);

    dsi_phy->PHY_CLK_CFG = DSI_V2_HOST_PHY_PHY_CLK_CFG_PHY_LPTX_CLK_DIV(phyConfig->lptx_clkdiv) |
                           DSI_V2_HOST_PHY_PHY_CLK_CFG_CLK_TYPE(phyConfig->enableNoncontinuousClk);

    dsi_phy->PHY_LP2HS_MAN_CFG = DSI_V2_HOST_PHY_PHY_LP2HS_MAN_CFG_PHY_LP2HS_TIME(phyConfig->lp2hs_time);

    dsi_phy->PHY_HS2LP_MAN_CFG = DSI_V2_HOST_PHY_PHY_HS2LP_MAN_CFG_PHY_HS2LP_TIME(phyConfig->hs2lp_time);

    dsi_phy->PHY_ESC_CMD_T_MAN_CFG = DSI_V2_HOST_PHY_PHY_ESC_CMD_T_MAN_CFG_PHY_ESC_CMD_TIME(phyConfig->esccmd_time);

    dsi_phy->PHY_ESC_BYTE_T_MAN_CFG = DSI_V2_HOST_PHY_PHY_ESC_BYTE_T_MAN_CFG_PHY_ESC_BYTE_TIME(phyConfig->escbyte_time);

    dsi_phy->PHY_TOLERANCE_CFG =
        (dsi_phy->PHY_TOLERANCE_CFG & ~(DSI_V2_HOST_PHY_PHY_TOLERANCE_CFG_PHY_HS2LP_LP2HS_MARGIN_MASK |
                                        DSI_V2_HOST_PHY_PHY_TOLERANCE_CFG_PHY_STOPSTATE_DELAY_MASK)) |
        DSI_V2_HOST_PHY_PHY_TOLERANCE_CFG_PHY_HS2LP_LP2HS_MARGIN(phyConfig->tolerance_time) |
        DSI_V2_HOST_PHY_PHY_TOLERANCE_CFG_PHY_STOPSTATE_DELAY(phyConfig->tolerance_time);

    dsi_phy->PRI_ULPS_CTRL = (dsi_phy->PRI_ULPS_CTRL & ~DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_WAKEUP_TIME_MASK) |
                             DSI_V2_HOST_PHY_PRI_ULPS_CTRL_PHY_WAKEUP_TIME(phyConfig->ulps_wakeuptime);

    dsi_phy->PRI_CAL_CTRL = DSI_V2_HOST_PHY_PRI_CAL_CTRL_PHY_CAL_TIME(phyConfig->cal_time);
}

/*!
 * @brief Calculates the D-PHY PLL dividers to generate the desired output frequency.
 *
 * The phy byte clock frequency(byte count per second) is generated by multiplying the refClkFreq_Hz,
 * the formula is as follows, m & n is configured by mediamix control block.
 *
 * desiredOutFreq_Hz = refClkFreq_Hz * M / N / P.
 * Feedback Multiplication Ratio M: phy_m[11:0] /4 , phy_m[11:0] range from 256 to 900
 * Input Frequency Division Ratio N:phy_n[3:0] + 1, phy_n[3:0] range  0 ~ 15
 * Output Division Factor P:[1, 2, 4, 8, 16, 32]
 *
 * @param config Pointer to the DSI D-phy PLL config structure containing m, n, p.
 * @param refClkFreq_Hz The D-PHY input reference clock frequency (REF_CLK).
 * @param desiredOutFreq_Hz Desired PLL output frequency.
 * @return The actually output frequency using the returned dividers. If can not
 * find suitable dividers, return 0.
 */
uint32_t DSI_DphyGetPllDivider(dsi_dphypll_config_t *config, uint32_t refClkFreq_Hz, uint32_t desiredOutFreq_Hz)
{
    uint32_t mCur, nCur, pCur;
    uint32_t curOutFreq;
    uint32_t diffCur;
    uint32_t diff     = 0xFFFFFFFFU;
    uint32_t bestFreq = 0U;

    const uint32_t pRange[] = {1U, 2U, 4U, 8U, 16U, 32U};

    for (uint32_t i = 0U; i < sizeof(pRange) / sizeof(pRange[0]); i++)
    {
        pCur = pRange[i];
        for (nCur = 0U; nCur < 16U; nCur++)
        {
            for (mCur = 256U; mCur <= 900U; mCur++)
            {
                curOutFreq = refClkFreq_Hz * (mCur / 4U) / (nCur + 1U) / pCur;
                diffCur    = (curOutFreq > desiredOutFreq_Hz) ? (curOutFreq - desiredOutFreq_Hz) :
                                                                (desiredOutFreq_Hz - curOutFreq);

                if (diffCur < diff)
                {
                    diff      = diffCur;
                    config->m = mCur;
                    config->n = nCur;
                    config->p = pCur;
                    bestFreq  = curOutFreq;

                    if (diff == 0U)
                    {
                        return bestFreq;
                    }
                }
            }
        }
    }

    return bestFreq;
}

/*!
 * @brief Power up the DSI
 *
 * @param base MIPI DSI main peripheral base address.
 * @param phy MIPI DSI phy peripheral base address.
 * @retval kStatus_Success Data transfer finished with no error.
 * @retval kStatus_Timeout Transfer failed because of timeout.
 */
status_t DSI_PowerUp(DSI_V2_HOST_MAIN_Type *base, DSI_V2_HOST_PHY_Type *phy)
{
    uint32_t waitTimes = FSL_MIPI_DSI_TIMEOUT;
    base->PWR_UP       = 1UL;
    base->SOFT_RESET   = DSI_V2_HOST_MAIN_SOFT_RESET_IPI_RSTN_MASK | DSI_V2_HOST_MAIN_SOFT_RESET_PHY_RSTN_MASK |
                       DSI_V2_HOST_MAIN_SOFT_RESET_SYS_RSTN_MASK;

    /* Wait for the core busy to set. */
    while (((base->CORE_STATUS & DSI_V2_HOST_MAIN_CORE_STATUS_CORE_BUSY_MASK) == 0U) && (0U != waitTimes))
    {
        waitTimes--;
    }

    if (waitTimes == 0U)
    {
        return kStatus_Timeout;
    }

    waitTimes = FSL_MIPI_DSI_TIMEOUT;
    /* Wait for the PHY stopstateclklane to set. */
    while (((phy->PHY_STATUS & DSI_V2_HOST_PHY_PHY_STATUS_PHY_CLK_STOPSTATE_MASK) == 0U) && (0U != waitTimes))
    {
        waitTimes--;
    }

    if (waitTimes == 0U)
    {
        return kStatus_Timeout;
    }
    else
    {
        return kStatus_Success;
    }
}

/*!
 * @brief Writes tx header to command FIFO. This will trigger the packet transfer.
 *
 * @param base MIPI DSI dsi peripheral base address.
 * @param wordCount For long packet, this is the byte count of the payload.
 *                 For short packet, this is (data1 << 8) | data0.
 * @param virtualChannel Virtual channel.
 * @param dataType The packet data type, (DI).
 */
void DSI_WriteTxHeader(DSI_V2_HOST_DSI_Type *base,
                       uint16_t wordCount,
                       uint8_t virtualChannel,
                       dsi_tx_data_type_t dataType)
{
    uint32_t header = DSI_V2_HOST_DSI_CRI_TX_HDR_DATA_TYPE(dataType) |
                      DSI_V2_HOST_DSI_CRI_TX_HDR_VIRTUAL_CHANNEL(virtualChannel) |
                      DSI_V2_HOST_DSI_CRI_TX_HDR_WC_LSB((uint8_t)wordCount) |
                      DSI_V2_HOST_DSI_CRI_TX_HDR_WC_MSB((uint8_t)(wordCount >> 8U));
    base->CRI_TX_HDR = header;
}

/*!
 * @brief Fills the long APB packet payload.
 *
 * Write the long packet payload to TX FIFO.
 *
 * @param base MIPI DSI dsi peripheral base address.
 * @param payload Pointer to the payload.
 * @param payloadSize Payload size in byte.
 */
void DSI_WriteTxPayload(DSI_V2_HOST_DSI_Type *base, const uint8_t *payload, uint16_t payloadSize)
{
    DSI_WriteTxPayloadExt(base, payload, payloadSize, false, 0U);
}

/*!
 * @brief Writes payload data to generic payload FIFO.
 *
 * Write the long packet payload to TX FIFO. This function could be used in two ways
 *
 * 1. Include the DCS command in the 1st byte of @p payload. In this case, the DCS command
 *    is the first byte of @p payload. The parameter @p sendDcsCmd is set to false,
 *    the @p dcsCmd is not used. This function is the same as @ref DSI_WriteTxPayload
 *    when used in this way.
 *
 * 2. The DCS command in not in @p payload, but specified by parameter @p dcsCmd.
 *    In this case, the parameter @p sendDcsCmd is set to true, the @p dcsCmd is the DCS
 *    command to send. The @p payload is sent after @p dcsCmd.
 *
 * @param base MIPI DSI dsi peripheral base address.
 * @param payload Pointer to the payload.
 * @param payloadSize Payload size in byte.
 * @param sendDcsCmd If set to true, the DCS command is specified by @p dcsCmd,
 *       otherwise the DCS command is included in the @p payload.
 * @param dcsCmd The DCS command to send, only used when @p sendDCSCmd is true.
 */
void DSI_WriteTxPayloadExt(
    DSI_V2_HOST_DSI_Type *base, const uint8_t *payload, uint16_t payloadSize, bool sendDcsCmd, uint8_t dcsCmd)
{
    uint8_t i;
    uint32_t wordToWrite;
    uint8_t byteEachWrite = (uint8_t)sizeof(uint32_t);

    payloadSize = sendDcsCmd ? payloadSize + 1U : payloadSize;

    /* Write the first 4-byte. */
    if (sendDcsCmd)
    {
        wordToWrite = dcsCmd;
    }
    else
    {
        wordToWrite = (uint32_t)(*payload);
        payload++;
    }

    payloadSize--;

    for (i = 1U; i < 4U; i++)
    {
        if (payloadSize > 0U)
        {
            wordToWrite |= ((uint32_t)(*payload) << (i << 3U));
            payload++;
            payloadSize--;
        }
        else
        {
            break;
        }
    }

    base->CRI_TX_PLD = wordToWrite;

    /* Write the rest payload data if any. */
    while (payloadSize != 0U)
    {
        if (payloadSize < byteEachWrite)
        {
            memcpy((void *)&wordToWrite, (const void *)payload, payloadSize);
            base->CRI_TX_PLD = wordToWrite;
            payloadSize      = 0U;
        }
        else
        {
            memcpy((void *)&wordToWrite, (const void *)payload, byteEachWrite);
            base->CRI_TX_PLD = wordToWrite;
            payloadSize -= byteEachWrite;
            payload += byteEachWrite;
        }
    }
}

/*!
 * @brief Reads the long APB packet payload.
 *
 * Read the long packet payload from RX FIFO. This function reads directly from
 * RX FIFO status. Upper layer should make sure the whole rx packet has been received.
 *
 * @param base MIPI DSI dsi peripheral base address.
 * @param payload Pointer to the payload buffer.
 * @param payloadSize Payload size in byte.
 */
void DSI_ReadRxData(DSI_V2_HOST_DSI_Type *base, uint8_t *payload, uint16_t payloadSize)
{
    uint32_t readWord;
    uint8_t byteEachRead = (uint8_t)sizeof(uint32_t);

    while (payloadSize != 0U)
    {
        readWord = base->CRI_RX_PLD;
        if (payloadSize < byteEachRead)
        {
            memcpy((void *)payload, (const void *)&readWord, payloadSize);
            payloadSize = 0U;
        }
        else
        {
            memcpy((void *)payload, (const void *)&readWord, byteEachRead);
            payloadSize -= byteEachRead;
            payload += byteEachRead;
        }
    }
}

static status_t DSI_PrepareApbTransfer(DSI_V2_HOST_DSI_Type *base, DSI_V2_HOST_INT_Type *inter, dsi_transfer_t *xfer)
{
    uint8_t txDataIndex;
    uint16_t wordCount;
    uint32_t phyFlags, toFlags, ackFlags, criFlags, txDataSize;

    if (xfer->rxDataSize != 0U)
    {
        xfer->flags |= (uint8_t)kDSI_TransferPerformBTA;
    }

    /* ========================== Prepare TX. ========================== */
    /* If xfer->sendDcsCmd is true, then the DCS command is not included in the
       xfer->txData, but specified by xfer->dcsCmd. */
    txDataSize = xfer->sendDcsCmd ? (uint32_t)xfer->txDataSize + 1U : (uint32_t)xfer->txDataSize;

    /* Short packet. */
    if (txDataSize <= 2U)
    {
        if (0U == txDataSize)
        {
            wordCount = 0U;
        }
        else /* txDataSize = 1 or 2 */
        {
            txDataIndex = 0;

            if (xfer->sendDcsCmd)
            {
                /* DCS command byte. */
                wordCount = xfer->dcsCmd;
            }
            else
            {
                /* The LSB byte in header. */
                wordCount = xfer->txData[txDataIndex++];
            }

            if (2U == txDataSize)
            {
                /* The DCS optional parameter byte or the MSB byte in header. */
                wordCount |= ((uint16_t)xfer->txData[txDataIndex] << 8U);
            }
        }
    }
    /* Long packet. */
    else
    {
        wordCount = (uint16_t)txDataSize;
        DSI_WriteTxPayloadExt(base, xfer->txData, xfer->txDataSize, xfer->sendDcsCmd, xfer->dcsCmd);
    }

    /* Clear the interrupt flags set by previous transfer. */
    DSI_GetAndClearInterruptStatus(inter, &phyFlags, &toFlags, &ackFlags, &criFlags);

    /* Write header to trigger the transfer. */
    DSI_WriteTxHeader(base, wordCount, xfer->virtualChannel, xfer->txDataType);

    return kStatus_Success;
}

/*
 * @brief APB data transfer using blocking method.
 *
 * Perform APB data transfer using blocking method. This function waits until all
 * data send or received, or timeout happens.
 *
 * @param base MIPI DSI main peripheral base address.
 * @param dsi MIPI DSI dsi peripheral base address.
 * @param inter MIPI DSI int peripheral base address.
 * @param xfer Pointer to the transfer structure.
 * @retval kStatus_Success Data transfer finished with no error.
 * @retval kStatus_Timeout Transfer failed because of timeout.
 * @retval kStatus_DSI_RxDataError RX data error, user could use ref DSI_GetRxErrorStatus
 *        to check the error details.
 * @retval kStatus_DSI_PhyError PHY error detected during transfer.
 * @retval kStatus_DSI_ErrorReportReceived Error Report packet received, user could use
 *        ref DSI_GetAndClearHostStatus to check the error report status.
 * @retval kStatus_DSI_NotSupported Transfer format not supported.
 * @retval kStatus_Fail Transfer failed for other reasons.
 */
status_t DSI_TransferBlocking(DSI_V2_HOST_MAIN_Type *base,
                              DSI_V2_HOST_DSI_Type *dsi,
                              DSI_V2_HOST_INT_Type *inter,
                              dsi_transfer_t *xfer)
{
    status_t status;
    uint32_t pktStatus;
    uint32_t phyFlags = 0U, toFlags = 0U, ackFlags = 0U, criFlags = 0U;

    status = DSI_PrepareApbTransfer(dsi, inter, xfer);

    if (status != kStatus_Success)
    {
        return status;
    }

    pktStatus = DSI_V2_HOST_MAIN_CORE_STATUS_CRI_WR_FIFOS_NOT_EMPTY_MASK;

    while (true)
    {
        /* Wait for CRI FIFO is empty */
        if ((base->CORE_STATUS & pktStatus) == 0)
        {
            break;
        }

        /* Hs forward tx time out. */
        DSI_GetAndClearInterruptStatus(inter, &phyFlags, &toFlags, &ackFlags, &criFlags);
        if ((toFlags & (uint32_t)kDSI_TimeoutErrorHstx) != 0U)
        {
            return kStatus_Timeout;
        }
    }

    /* No rx data, return directly. */
    if (0U == (xfer->flags & (uint32_t)kDSI_TransferPerformBTA))
    {
        return kStatus_Success;
    }

    pktStatus = DSI_V2_HOST_MAIN_CORE_STATUS_CRI_BUSY_MASK;
    while (true)
    {
        /* Wait for CRI is busy. */
        if ((base->CORE_STATUS & pktStatus) == pktStatus)
        {
            break;
        }

        /* Low power rx time out. */
        DSI_GetAndClearInterruptStatus(inter, &phyFlags, &toFlags, &ackFlags, &criFlags);
        if ((toFlags & (uint32_t)kDSI_TimeoutErrorLprx) != 0U)
        {
            return kStatus_Timeout;
        }
    }

    /* Process the received frame. */
    uint32_t rxPktHeader;
    uint16_t actualRxByteCount;
    uint32_t rxDataType;
    bool readRxDataFromPayload;

    /* If rx error detected in the received packet. */
    if (0U != ((uint32_t)kDSI_CriErrorEccMultiBit & criFlags))
    {
        return kStatus_DSI_EccMultiBitError;
    }

    if (0U != ((uint32_t)kDSI_CriErrorCrc & criFlags))
    {
        return kStatus_DSI_CrcError;
    }

    if (0U != ((uint32_t)kDSI_CriErrorRxLength & criFlags))
    {
        return kStatus_DSI_PacketSizeError;
    }

    /* If phy error detected in the received packet. */
    if (0U != ((uint32_t)kDSI_PhyErrorAll & phyFlags))
    {
        return kStatus_DSI_PhyError;
    }

    /* Read CRI RX header */
    rxPktHeader = dsi->CRI_RX_HDR;
    rxDataType  = rxPktHeader & 0x3FU;

    /* If received error report. */
    if ((uint32_t)kDSI_RxDataAckAndErrorReport == rxDataType)
    {
        /* The corresponding acknowledge and error report status should be set. */
        if (0U != ((uint32_t)kDSI_ErrorAckReportAll & ackFlags))
        {
            return kStatus_DSI_ErrorReportReceived;
        }
        else
        {
            return kStatus_Fail;
        }
    }
    else
    {
        if (((uint32_t)kDSI_RxDataGenShortRdResponseOneByte == rxDataType) ||
            ((uint32_t)kDSI_RxDataDcsShortRdResponseOneByte == rxDataType))
        {
            readRxDataFromPayload = false;
            actualRxByteCount     = 1U;
        }
        else if (((uint32_t)kDSI_RxDataGenShortRdResponseTwoByte == rxDataType) ||
                 ((uint32_t)kDSI_RxDataDcsShortRdResponseTwoByte == rxDataType))
        {
            readRxDataFromPayload = false;
            actualRxByteCount     = 2U;
        }
        else if (((uint32_t)kDSI_RxDataGenLongRdResponse == rxDataType) ||
                 ((uint32_t)kDSI_RxDataDcsLongRdResponse == rxDataType))
        {
            readRxDataFromPayload = true;
            actualRxByteCount     = (uint16_t)(rxPktHeader >> 8U);
        }
        else /* kDSI_RxDataEoTp */
        {
            readRxDataFromPayload = false;
            xfer->rxDataSize      = 0U;
            actualRxByteCount     = 0U;
        }

        xfer->rxDataSize = MIN(xfer->rxDataSize, actualRxByteCount);

        if (xfer->rxDataSize > 0U)
        {
            if (readRxDataFromPayload)
            {
                DSI_ReadRxData(dsi, xfer->rxData, xfer->rxDataSize);
            }
            else
            {
                xfer->rxData[0] = (uint8_t)((rxPktHeader >> 8U) & 0xFFU);

                if (2U == xfer->rxDataSize)
                {
                    xfer->rxData[1] = (uint8_t)((rxPktHeader >> 16U) & 0xFFU);
                }
            }
        }
    }

    return kStatus_Success;
}

/*!
 * @brief Lookup table method to obtain VCO parameter.
 *
 * @param pll_freq_sel PLL frequency in Mhz.
 * @return the phy_vco_cntrl[5:0] value based on video Pll frequency in Mhz.
 */
void Pll_Set_Pll_Vco_Param(uint32_t pll_freq_sel, dsi_dphypll_config_t *config)
{
    assert(config != NULL);
    uint8_t i;
    for (i = 0U; i < ARRAY_SIZE(Vco_Cpbias_Table); i++)
    {
        if (pll_freq_sel <= (Vco_Cpbias_Table[i][0U]))
        {
            break;
        }
    }

    config->vcoctrl = (uint16_t)Vco_Cpbias_Table[i][1U];
    config->cpbias  = (uint16_t)Vco_Cpbias_Table[i][2U];
}

/*!
 * @brief config to set Dphy.
 *
 * @param phyRefClkFreq_Hz Dphy reference clock frequency in Hz.
 * @param dataRateFreq_Hz line rate clock frequency.
 * @param config Pointer to dsi ipi configuration structure.
 */
void DSI_ConfigDphy(DISPLAY_DSI_CSR_Type *base,
                    uint32_t phyRefClkFreq_Hz,
                    uint32_t dataRateFreq_Hz,
                    const dsi_ipi_config_t *config)
{
    assert(config != NULL);
    uint16_t dphyClkFreq_Mhz;
    uint8_t dsi_csr_format;
    dsi_dphypll_config_t DphyPllCfg = {0};
    dphyClkFreq_Mhz                = dataRateFreq_Hz / 1000000U;
    DSI_DphyGetPllDivider(&DphyPllCfg, phyRefClkFreq_Hz, dataRateFreq_Hz);
    Pll_Set_Pll_Vco_Param(dphyClkFreq_Mhz, &DphyPllCfg);
    uint8_t bpp = DSI_GetBitsPerPixel(config);

    switch (bpp)
    {
        case 24:
            dsi_csr_format = kDSI_PixelFormatRGB24Bit;
            break;
        case 18:
            dsi_csr_format = kDSI_PixelFormatRGB18Bit;
            break;
        case 16:
            dsi_csr_format = kDSI_PixelFormatRGB16Bit;
        default:
            assert(false);
            break;
    }

    /* Reset & shutdown */
    base->DSI_PHY_MODE_CONTROL &=
        ~(DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_RST_N_MASK | DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_SHUTDOWN_N_MASK |
          DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_CLKSEL_MASK);

    base->DSI_PHY_MODE_CONTROL |= DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_CLKSEL(0x1U);

    /* clear value M and VCOCTRL */
    base->DSI_PLL_CTRL0 &=
        ~(DISPLAY_DSI_CSR_DSI_PLL_CTRL0_INT_CNTRL_MASK | DISPLAY_DSI_CSR_DSI_PLL_CTRL0_VCO_CNTRL_MASK |
          DISPLAY_DSI_CSR_DSI_PLL_CTRL0_M_MASK | DISPLAY_DSI_CSR_DSI_PLL_CTRL0_PROP_CNTRL_MASK);

    /* Set value M and VCOCTRL */
    base->DSI_PLL_CTRL0 |=
        DISPLAY_DSI_CSR_DSI_PLL_CTRL0_INT_CNTRL(0x1) | DISPLAY_DSI_CSR_DSI_PLL_CTRL0_VCO_CNTRL(DphyPllCfg.vcoctrl) |
        DISPLAY_DSI_CSR_DSI_PLL_CTRL0_M(DphyPllCfg.m) | DISPLAY_DSI_CSR_DSI_PLL_CTRL0_PROP_CNTRL(0x5);

    /* Clear cpbias and gmp ctrl */
    base->DSI_PLL_CTRL1 &=
        ~(DISPLAY_DSI_CSR_DSI_PLL_CTRL1_CPBIAS_CNTRL_MASK | DISPLAY_DSI_CSR_DSI_PLL_CTRL1_GMP_CNTRL_MASK);

    /* Set value P */
    base->DSI_PLL_CTRL1 |=
        DISPLAY_DSI_CSR_DSI_PLL_CTRL1_CPBIAS_CNTRL(DphyPllCfg.cpbias) | DISPLAY_DSI_CSR_DSI_PLL_CTRL1_GMP_CNTRL(0x1);

    /* Set value N */
    base->DSI_PLL_CTRL2 =
        (base->DSI_PLL_CTRL2 & ~DISPLAY_DSI_CSR_DSI_PLL_CTRL2_N_MASK) | DISPLAY_DSI_CSR_DSI_PLL_CTRL2_N(DphyPllCfg.n);

    /* Set Dsi pixel link format */
    base->DSI_HOST_CONFIGURATION =
        (base->DSI_HOST_CONFIGURATION & ~DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_Pixel_link_format_MASK) |
        DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_Pixel_link_format(dsi_csr_format);
}
