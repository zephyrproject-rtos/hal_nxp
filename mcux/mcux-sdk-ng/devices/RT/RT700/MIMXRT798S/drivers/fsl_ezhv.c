/*
 * Copyright 2023-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_clock.h"
#include "fsl_power.h"
#include "fsl_ezhv.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.ezhv"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/
static ezhv_callback_t s_ezhvCallback[EZHV_INT_CHAN_NUM] = {NULL};
static void *s_ezhvCallbackParam[EZHV_INT_CHAN_NUM]      = {NULL};

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
void EZHV_Init(ezhv_copy_image_t *ezhvCopyImage)
{
    EZHV_InitWithoutFirmware();
    EZHV_InstallFirmware(ezhvCopyImage);
}

void EZHV_InitWithoutFirmware(void)
{
    CLOCK_EnableClock(kCLOCK_Ezhv);
    CLOCK_EnableClock(kCLOCK_AxbsEzh);

    POWER_DisablePD(kPDRUNCFG_APD_EZHV_TCM);
    POWER_DisablePD(kPDRUNCFG_PPD_EZHV_TCM);
    POWER_ApplyPD();
}

void EZHV_InstallFirmware(ezhv_copy_image_t *ezhvCopyImage)
{
    uint32_t dstAddr;
    uint32_t srcAddr;
    uint32_t size;

    assert(ezhvCopyImage != NULL);
    assert(ezhvCopyImage->srcAddr != 0U);
    assert(ezhvCopyImage->destAddr != 0U);
    assert(ezhvCopyImage->size != 0U);

    dstAddr = ezhvCopyImage->destAddr;
    srcAddr = ezhvCopyImage->srcAddr;
    size = ezhvCopyImage->size;

    memcpy((void*)(uint32_t*)dstAddr, (const void*)(uint32_t*)srcAddr, size);
}

void EZHV_Boot(uint32_t bootAddr)
{
    SYSCON4->EZHV_RSTBASE = bootAddr >> 2;
    SYSCON4->EZHV_RSTMTVEC = bootAddr;
    SYSCON4->EZHV_VOFFSET_T = EZHV_M_EXT_INT;
    /* reset to start ezhv */
    RESET_PeripheralReset(kEZHV_RST_SHIFT_RSTn);
}

void EZHV_SetPara(ezhv_param_t *para)
{
    assert(para != NULL);
    memcpy((void*)EZHV_SHARED_DATA_ADDR, para, sizeof(ezhv_param_t));
}

uint32_t *EZHV_GetParaAddr(void)
{
    return (uint32_t *)EZHV_SHARED_DATA_ADDR;
}

void EZHV_Deinit(void)
{
    CLOCK_DisableClock(kCLOCK_Ezhv);
    CLOCK_DisableClock(kCLOCK_AxbsEzh);

    POWER_EnablePD(kPDRUNCFG_APD_EZHV_TCM);
    POWER_EnablePD(kPDRUNCFG_PPD_EZHV_TCM);
    POWER_ApplyPD();
}

void EZHV_WakeUpEzhv(arm2ezhv_intctl_t arm2ezhvInt)
{
    volatile bool tmp = false;
    while(!tmp)
    {
        tmp = EZHV_GetEzhvWaitStatusFlag();
    }
    EZHV_EnableArm2EzhvInt(arm2ezhvInt);
}

void EZHV_SetCallback(ezhv_callback_t callback,
                    uint16_t channel,
                    void *userData)
{
	assert(channel < EZHV_INT_CHAN_NUM);
    s_ezhvCallback[channel]       = callback;
    s_ezhvCallbackParam[channel]  = userData;
}

static void EZHV_HandleIRQ(void)
{
    uint32_t intFlag = EZHV_GetEzhv2ArmIntChan();

    if (0U != intFlag)
    {
        for (uint32_t id = 0U; id < EZHV_INT_CHAN_NUM; id++)
        {
            if ((0U != (intFlag & (1U << id))) && (NULL != s_ezhvCallback[id]))
            {
                s_ezhvCallback[id](s_ezhvCallbackParam[id]);
            }
        }
        EZHV_ClearEzhv2ArmIntChan((ezhv2arm_int_chan_t)intFlag);
    }
}

void EZHV_DriverIRQHandler(void)
{
    EZHV_HandleIRQ();
}
