/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_aoi.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_aoi"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Initializes an AOI instance for operation.
 *
 * This function is to make the initialization for using AOI module.
 *
 * Reserved function, enable clock preparation.
 *
 * param base AOI peripheral address.
 */
void AOI_Init(AOI_Type *base)
{
}

/*!
 *@brief De-initializes an AOI instance for operation.
 *
 * This function shutdowns AOI module.
 *
 * Reserved function, disable clock preparation.
 *
 * param  base AOI peripheral address.
 */
void AOI_Deinit(AOI_Type *base)
{
}
/*!
 * @brief Gets the Boolean evaluation associated.
 *
 * This function returns the Boolean evaluation associated.
 *
 * Example:
  code
    aoi_event_config_t demoEventLogicStruct;

    AOI_GetEventLogicConfig(AOI, kAOI_Event0, &demoEventLogicStruct);
  endcode
 *
 * param  base            AOI peripheral address.
 * param  eEvent          Index of the event which will be set of type aoi_event_t.
 * param  psEventconfig   Selected input configuration .
 */
void AOI_GetEventLogicConfig(AOI_Type *base, aoi_event_t eEvent, aoi_event_config_t *psEventconfig)
{
    assert((uint32_t)eEvent < (uint32_t)KAOI_EventMax);
    assert(psEventconfig != NULL);

    uint16_t value;
    uint16_t temp;
    /* Set the config memory to 0. */
    (void)memset(psEventconfig, 0, sizeof(aoi_event_config_t));

    /* Read BFCRT01 register at eEvent index. */
    value = base->BFCRT[(uint8_t)eEvent].BFCRT01;

    temp                 = (value & AOI_BFCRT01_PT0_AC_MASK) >> AOI_BFCRT01_PT0_AC_SHIFT;
    psEventconfig->PT0AC = (aoi_input_config_t)temp;
    temp                 = (value & AOI_BFCRT01_PT0_BC_MASK) >> AOI_BFCRT01_PT0_BC_SHIFT;
    psEventconfig->PT0BC = (aoi_input_config_t)temp;
    temp                 = (value & AOI_BFCRT01_PT0_CC_MASK) >> AOI_BFCRT01_PT0_CC_SHIFT;
    psEventconfig->PT0CC = (aoi_input_config_t)temp;
    temp                 = (value & AOI_BFCRT01_PT0_DC_MASK) >> AOI_BFCRT01_PT0_DC_SHIFT;
    psEventconfig->PT0DC = (aoi_input_config_t)temp;

    temp                 = (value & AOI_BFCRT01_PT1_AC_MASK) >> AOI_BFCRT01_PT1_AC_SHIFT;
    psEventconfig->PT1AC = (aoi_input_config_t)temp;
    temp                 = (value & AOI_BFCRT01_PT1_BC_MASK) >> AOI_BFCRT01_PT1_BC_SHIFT;
    psEventconfig->PT1BC = (aoi_input_config_t)temp;
    temp                 = (value & AOI_BFCRT01_PT1_CC_MASK) >> AOI_BFCRT01_PT1_CC_SHIFT;
    psEventconfig->PT1CC = (aoi_input_config_t)temp;
    temp                 = (value & AOI_BFCRT01_PT1_DC_MASK) >> AOI_BFCRT01_PT1_DC_SHIFT;
    psEventconfig->PT1DC = (aoi_input_config_t)temp;

    /* Read BFCRT23 register at eEvent index. */
    value = base->BFCRT[(uint8_t)eEvent].BFCRT23;

    temp                 = (value & AOI_BFCRT23_PT2_AC_MASK) >> AOI_BFCRT23_PT2_AC_SHIFT;
    psEventconfig->PT2AC = (aoi_input_config_t)temp;
    temp                 = (value & AOI_BFCRT23_PT2_BC_MASK) >> AOI_BFCRT23_PT2_BC_SHIFT;
    psEventconfig->PT2BC = (aoi_input_config_t)temp;
    temp                 = (value & AOI_BFCRT23_PT2_CC_MASK) >> AOI_BFCRT23_PT2_CC_SHIFT;
    psEventconfig->PT2CC = (aoi_input_config_t)temp;
    temp                 = (value & AOI_BFCRT23_PT2_DC_MASK) >> AOI_BFCRT23_PT2_DC_SHIFT;
    psEventconfig->PT2DC = (aoi_input_config_t)temp;

    temp                 = (value & AOI_BFCRT23_PT3_AC_MASK) >> AOI_BFCRT23_PT3_AC_SHIFT;
    psEventconfig->PT3AC = (aoi_input_config_t)temp;
    temp                 = (value & AOI_BFCRT23_PT3_BC_MASK) >> AOI_BFCRT23_PT3_BC_SHIFT;
    psEventconfig->PT3BC = (aoi_input_config_t)temp;
    temp                 = (value & AOI_BFCRT23_PT3_CC_MASK) >> AOI_BFCRT23_PT3_CC_SHIFT;
    psEventconfig->PT3CC = (aoi_input_config_t)temp;
    temp                 = (value & AOI_BFCRT23_PT3_DC_MASK) >> AOI_BFCRT23_PT3_DC_SHIFT;
    psEventconfig->PT3DC = (aoi_input_config_t)temp;
}

/*!
 * brief Configures an AOI event.
 *
 * This function configures an AOI event according
 * to the aoiEventConfig structure. This function configures all  inputs (A, B, C, and D)
 * of all  product terms (0, 1, 2, and 3) of a desired event.
 *
 * Example:
  code
    aoi_event_config_t demoEventLogicStruct;

    demoEventLogicStruct.PT0AC = kAOI_InvInputSignal;
    demoEventLogicStruct.PT0BC = kAOI_InputSignal;
    demoEventLogicStruct.PT0CC = kAOI_LogicOne;
    demoEventLogicStruct.PT0DC = kAOI_LogicOne;

    demoEventLogicStruct.PT1AC = kAOI_LogicZero;
    demoEventLogicStruct.PT1BC = kAOI_LogicOne;
    demoEventLogicStruct.PT1CC = kAOI_LogicOne;
    demoEventLogicStruct.PT1DC = kAOI_LogicOne;

    demoEventLogicStruct.PT2AC = kAOI_LogicZero;
    demoEventLogicStruct.PT2BC = kAOI_LogicOne;
    demoEventLogicStruct.PT2CC = kAOI_LogicOne;
    demoEventLogicStruct.PT2DC = kAOI_LogicOne;

    demoEventLogicStruct.PT3AC = kAOI_LogicZero;
    demoEventLogicStruct.PT3BC = kAOI_LogicOne;
    demoEventLogicStruct.PT3CC = kAOI_LogicOne;
    demoEventLogicStruct.PT3DC = kAOI_LogicOne;

    AOI_SetEventLogicConfig(AOI, kAOI_Event0,&demoEventLogicStruct);
  endcode
 *
 * param  base              AOI peripheral address.
 * param  eEvent            which will be configured of type aoi_event_t.
 * param  psEventconfig     Pointer to type aoi_event_config_t structure. The user is responsible for
 * filling out the members of this structure and passing the pointer to this function.
 */
void AOI_SetEventLogicConfig(AOI_Type *base, aoi_event_t eEvent, const aoi_event_config_t *psEventconfig)
{
    assert(psEventconfig != NULL);
    assert((uint32_t)eEvent < (uint32_t)KAOI_EventMax);

    uint16_t value;
    /* Calculate value to configure product term 0, 1 */
    value = AOI_BFCRT01_PT0_AC(psEventconfig->PT0AC) | AOI_BFCRT01_PT0_BC(psEventconfig->PT0BC) |
            AOI_BFCRT01_PT0_CC(psEventconfig->PT0CC) | AOI_BFCRT01_PT0_DC(psEventconfig->PT0DC) |
            AOI_BFCRT01_PT1_AC(psEventconfig->PT1AC) | AOI_BFCRT01_PT1_BC(psEventconfig->PT1BC) |
            AOI_BFCRT01_PT1_CC(psEventconfig->PT1CC) | AOI_BFCRT01_PT1_DC(psEventconfig->PT1DC);
    /* Write value to register */
    base->BFCRT[(uint8_t)eEvent].BFCRT01 = value;

    /* Reset and calculate value to configure product term 2, 3 */
    value = AOI_BFCRT23_PT2_AC(psEventconfig->PT2AC) | AOI_BFCRT23_PT2_BC(psEventconfig->PT2BC) |
            AOI_BFCRT23_PT2_CC(psEventconfig->PT2CC) | AOI_BFCRT23_PT2_DC(psEventconfig->PT2DC) |
            AOI_BFCRT23_PT3_AC(psEventconfig->PT3AC) | AOI_BFCRT23_PT3_BC(psEventconfig->PT3BC) |
            AOI_BFCRT23_PT3_CC(psEventconfig->PT3CC) | AOI_BFCRT23_PT3_DC(psEventconfig->PT3DC);
    /* Write value to register */
    base->BFCRT[(uint8_t)eEvent].BFCRT23 = value;
}
