/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_evtg.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_evtg"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*!
 * brief Initialize EVTG with a user configuration structure.
 *
 * param base       EVTG base address.
 * param eEvtgIndex EVTG instance index.
 * param psConfig   EVTG initial configuration structure pointer.
 */
void EVTG_Init(EVTG_Type *base, evtg_index_t eEvtgIndex, evtg_config_t *psConfig)

{
    /* Configure Flip-Flop as expected mode. */
    base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_CTRL = EVTG_EVTG_CTRL_MODE_SEL((uint16_t)psConfig->eFlipflopMode);

    if (kEVTG_FFMode_JKFF == psConfig->eFlipflopMode)
    {
        /* When FF Mode is configured as JK-FF mode, need EVTG_OUTA feedback to EVTG input and replace one of the four
         * inputs.*/
        base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_CTRL |=
            EVTG_EVTG_CTRL_FB_OVRD((uint16_t)psConfig->eOutfdbkOverideinput);
    }

    if (psConfig->bEnableFlipflopInitOutput == true)
    {
        EVTG_ForceFlipflopInitOutput(base, eEvtgIndex, psConfig->eFlipflopInitOutputValue);
    }

#if defined(FSL_FEATURE_EVTG_HAS_FORCE_BYPASS_FLIPFLOP) && FSL_FEATURE_EVTG_HAS_FORCE_BYPASS_FLIPFLOP
    base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_CTRL |= EVTG_EVTG_CTRL_FORCE_BYPASS(psConfig->bEnableForceBypassFlipFlopAOI1 << 1U) |
    		                                                            (psConfig->bEnableForceBypassFlipFlopAOI0));
#endif

    /* Configure EVTG input sync. */
    base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_CTRL |=
        EVTG_EVTG_CTRL_SYNC_CTRL((uint8_t)((psConfig->bEnableInputDSync << 3U) | (psConfig->bEnableInputCSync << 2U) |
                                           (psConfig->bEnableInputBSync << 1U) | (psConfig->bEnableInputASync)));

    /* Configure AOI0. */
    base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI0_BFT01 =
        (EVTG_EVTG_AOI0_BFT01_PT0_AC((uint8_t)psConfig->sAOI0Config.sProductTerm0.eAInput) |
         EVTG_EVTG_AOI0_BFT01_PT0_BC((uint8_t)psConfig->sAOI0Config.sProductTerm0.eBInput) |
         EVTG_EVTG_AOI0_BFT01_PT0_CC((uint8_t)psConfig->sAOI0Config.sProductTerm0.eCInput) |
         EVTG_EVTG_AOI0_BFT01_PT0_DC((uint8_t)psConfig->sAOI0Config.sProductTerm0.eDInput) |
         EVTG_EVTG_AOI0_BFT01_PT1_AC((uint8_t)psConfig->sAOI0Config.sProductTerm1.eAInput) |
         EVTG_EVTG_AOI0_BFT01_PT1_BC((uint8_t)psConfig->sAOI0Config.sProductTerm1.eBInput) |
         EVTG_EVTG_AOI0_BFT01_PT1_CC((uint8_t)psConfig->sAOI0Config.sProductTerm1.eCInput) |
         EVTG_EVTG_AOI0_BFT01_PT1_DC((uint8_t)psConfig->sAOI0Config.sProductTerm1.eDInput));

    base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI0_BFT23 =
        (EVTG_EVTG_AOI0_BFT23_PT2_AC((uint8_t)psConfig->sAOI0Config.sProductTerm2.eAInput) |
         EVTG_EVTG_AOI0_BFT23_PT2_BC((uint8_t)psConfig->sAOI0Config.sProductTerm2.eBInput) |
         EVTG_EVTG_AOI0_BFT23_PT2_CC((uint8_t)psConfig->sAOI0Config.sProductTerm2.eCInput) |
         EVTG_EVTG_AOI0_BFT23_PT2_DC((uint8_t)psConfig->sAOI0Config.sProductTerm2.eDInput) |
         EVTG_EVTG_AOI0_BFT23_PT3_AC((uint8_t)psConfig->sAOI0Config.sProductTerm3.eAInput) |
         EVTG_EVTG_AOI0_BFT23_PT3_BC((uint8_t)psConfig->sAOI0Config.sProductTerm3.eBInput) |
         EVTG_EVTG_AOI0_BFT23_PT3_CC((uint8_t)psConfig->sAOI0Config.sProductTerm3.eCInput) |
         EVTG_EVTG_AOI0_BFT23_PT3_DC((uint8_t)psConfig->sAOI0Config.sProductTerm3.eDInput));

    base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI0_FILT |=
        (EVTG_EVTG_AOI0_FILT_FILT_CNT((uint16_t)psConfig->sAOI0Config.sAOIOutFilterConfig.eSampleCount) |
         EVTG_EVTG_AOI0_FILT_FILT_PER(psConfig->sAOI0Config.sAOIOutFilterConfig.u8SamplePeriod));

    /* Configure AOI1. */
    base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI1_BFT01 =
        (EVTG_EVTG_AOI1_BFT01_PT0_AC((uint8_t)psConfig->sAOI1Config.sProductTerm0.eAInput) |
         EVTG_EVTG_AOI1_BFT01_PT0_BC((uint8_t)psConfig->sAOI1Config.sProductTerm0.eBInput) |
         EVTG_EVTG_AOI1_BFT01_PT0_CC((uint8_t)psConfig->sAOI1Config.sProductTerm0.eCInput) |
         EVTG_EVTG_AOI1_BFT01_PT0_DC((uint8_t)psConfig->sAOI1Config.sProductTerm0.eDInput) |
         EVTG_EVTG_AOI1_BFT01_PT1_AC((uint8_t)psConfig->sAOI1Config.sProductTerm1.eAInput) |
         EVTG_EVTG_AOI1_BFT01_PT1_BC((uint8_t)psConfig->sAOI1Config.sProductTerm1.eBInput) |
         EVTG_EVTG_AOI1_BFT01_PT1_CC((uint8_t)psConfig->sAOI1Config.sProductTerm1.eCInput) |
         EVTG_EVTG_AOI1_BFT01_PT1_DC((uint8_t)psConfig->sAOI1Config.sProductTerm1.eDInput));

    base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI1_BFT23 =
        (EVTG_EVTG_AOI1_BFT23_PT2_AC((uint8_t)psConfig->sAOI1Config.sProductTerm2.eAInput) |
         EVTG_EVTG_AOI1_BFT23_PT2_BC((uint8_t)psConfig->sAOI1Config.sProductTerm2.eBInput) |
         EVTG_EVTG_AOI1_BFT23_PT2_CC((uint8_t)psConfig->sAOI1Config.sProductTerm2.eCInput) |
         EVTG_EVTG_AOI1_BFT23_PT2_DC((uint8_t)psConfig->sAOI1Config.sProductTerm2.eDInput) |
         EVTG_EVTG_AOI1_BFT23_PT3_AC((uint8_t)psConfig->sAOI1Config.sProductTerm3.eAInput) |
         EVTG_EVTG_AOI1_BFT23_PT3_BC((uint8_t)psConfig->sAOI1Config.sProductTerm3.eBInput) |
         EVTG_EVTG_AOI1_BFT23_PT3_CC((uint8_t)psConfig->sAOI1Config.sProductTerm3.eCInput) |
         EVTG_EVTG_AOI1_BFT23_PT3_DC((uint8_t)psConfig->sAOI1Config.sProductTerm3.eDInput));

    base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI1_FILT |=
        (EVTG_EVTG_AOI1_FILT_FILT_CNT((uint16_t)psConfig->sAOI1Config.sAOIOutFilterConfig.eSampleCount) |
         EVTG_EVTG_AOI1_FILT_FILT_PER(psConfig->sAOI1Config.sAOIOutFilterConfig.u8SamplePeriod));
}

/*!
 * brief Configure AOI product term by initializing the product term
 *       configuration structure.
 *
 * param base                EVTG base address.
 * param eEvtgIndex          EVTG instance index.
 * param eAOIIndex           EVTG AOI index. see enum ref evtg_aoi_index_t
 * param eProductTerm        EVTG AOI product term index.
 * param psProductTermConfig Pointer to EVTG product term configuration structure.
 *                           see ref _evtg_product_term_config
 */
void EVTG_ConfigAOIProductTerm(EVTG_Type *base,
                               evtg_index_t eEvtgIndex,
                               evtg_aoi_index_t eAOIIndex,
                               evtg_aoi_product_term_t eProductTerm,
                               evtg_aoi_product_term_config_t *psProductTermConfig)

{
    volatile uint16_t *pu16AOIPT01Config;
    volatile uint16_t *pu16AOIPT23Config;

    if (kEVTG_AOI0 == eAOIIndex)
    {
        pu16AOIPT01Config = &base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI0_BFT01;
        pu16AOIPT23Config = &base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI0_BFT23;
    }
    else
    {
        pu16AOIPT01Config = &base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI1_BFT01;
        pu16AOIPT23Config = &base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI1_BFT23;
    }

    if (kEVTG_ProductTerm0 == eProductTerm)
    {
        *pu16AOIPT01Config &= ~(EVTG_EVTG_AOI0_BFT01_PT0_AC_MASK | EVTG_EVTG_AOI0_BFT01_PT0_BC_MASK |
                                EVTG_EVTG_AOI0_BFT01_PT0_CC_MASK | EVTG_EVTG_AOI0_BFT01_PT0_DC_MASK);
        *pu16AOIPT01Config |= (EVTG_EVTG_AOI0_BFT01_PT0_AC((uint8_t)psProductTermConfig->eAInput) |
                               EVTG_EVTG_AOI0_BFT01_PT0_BC((uint8_t)psProductTermConfig->eBInput) |
                               EVTG_EVTG_AOI0_BFT01_PT0_CC((uint8_t)psProductTermConfig->eCInput) |
                               EVTG_EVTG_AOI0_BFT01_PT0_DC((uint8_t)psProductTermConfig->eDInput));
    }
    else if (kEVTG_ProductTerm1 == eProductTerm)
    {
        *pu16AOIPT01Config &= ~(EVTG_EVTG_AOI0_BFT01_PT1_AC_MASK | EVTG_EVTG_AOI0_BFT01_PT1_BC_MASK |
                                EVTG_EVTG_AOI0_BFT01_PT1_CC_MASK | EVTG_EVTG_AOI0_BFT01_PT1_DC_MASK);
        *pu16AOIPT01Config |= (EVTG_EVTG_AOI0_BFT01_PT1_AC((uint8_t)psProductTermConfig->eAInput) |
                               EVTG_EVTG_AOI0_BFT01_PT1_BC((uint8_t)psProductTermConfig->eBInput) |
                               EVTG_EVTG_AOI0_BFT01_PT1_CC((uint8_t)psProductTermConfig->eCInput) |
                               EVTG_EVTG_AOI0_BFT01_PT1_DC((uint8_t)psProductTermConfig->eDInput));
    }
    else if (kEVTG_ProductTerm2 == eProductTerm)
    {
        *pu16AOIPT23Config &= ~(EVTG_EVTG_AOI0_BFT23_PT2_AC_MASK | EVTG_EVTG_AOI0_BFT23_PT2_BC_MASK |
                                EVTG_EVTG_AOI0_BFT23_PT2_CC_MASK | EVTG_EVTG_AOI0_BFT23_PT2_DC_MASK);
        *pu16AOIPT23Config |= (EVTG_EVTG_AOI0_BFT23_PT2_AC((uint8_t)psProductTermConfig->eAInput) |
                               EVTG_EVTG_AOI0_BFT23_PT2_BC((uint8_t)psProductTermConfig->eBInput) |
                               EVTG_EVTG_AOI0_BFT23_PT2_CC((uint8_t)psProductTermConfig->eCInput) |
                               EVTG_EVTG_AOI0_BFT23_PT2_DC((uint8_t)psProductTermConfig->eDInput));
    }
    else
    {
        *pu16AOIPT23Config &= ~(EVTG_EVTG_AOI0_BFT23_PT3_AC_MASK | EVTG_EVTG_AOI0_BFT23_PT3_BC_MASK |
                                EVTG_EVTG_AOI0_BFT23_PT3_CC_MASK | EVTG_EVTG_AOI0_BFT23_PT3_DC_MASK);
        *pu16AOIPT23Config |= (EVTG_EVTG_AOI0_BFT23_PT3_AC((uint8_t)psProductTermConfig->eAInput) |
                               EVTG_EVTG_AOI0_BFT23_PT3_BC((uint8_t)psProductTermConfig->eBInput) |
                               EVTG_EVTG_AOI0_BFT23_PT3_CC((uint8_t)psProductTermConfig->eCInput) |
                               EVTG_EVTG_AOI0_BFT23_PT3_DC((uint8_t)psProductTermConfig->eDInput));
    }
}
