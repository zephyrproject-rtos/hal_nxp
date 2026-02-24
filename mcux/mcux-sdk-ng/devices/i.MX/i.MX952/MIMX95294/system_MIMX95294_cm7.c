/*
** ###################################################################
**     Processors:          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_cm7
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    iMX952RM rev1 draftM
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b241030
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file MIMX95294_cm7
 * @version 1.0
 * @date 2023-01-10
 * @brief Device specific configuration file for MIMX95294_cm7 (implementation
 *        file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#include <stdint.h>
#include "fsl_debug_console.h"
#include "fsl_device_registers.h"
#include "fsl_mu.h"
#include "scmi.h"
#include "scmi_internal.h"
#include "smt.h"
#if SCMI_LMM_POWER_CHANGE_PROCESSED
#include "app_srtm.h"
#endif

/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */

uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

static MU_Type *const s_muBases[] = MU_BASE_PTRS;
static IRQn_Type const s_muIrqs[] = MU_IRQS;
static uint32_t g_systemState = 0xFFFFFFFF;

/* ----------------------------------------------------------------------------
   -- SystemInit()
   ---------------------------------------------------------------------------- */

void SystemInit (void) {
#if ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
  SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));    /* set CP10, CP11 Full Access */
#endif /* ((__FPU_PRESENT == 1) && (__FPU_USED == 1)) */


  SystemInitHook();
}

/* ----------------------------------------------------------------------------
   -- SystemCoreClockUpdate()
   ---------------------------------------------------------------------------- */

void SystemCoreClockUpdate (void) {


}

/* ----------------------------------------------------------------------------
   -- SystemInitHook()
   ---------------------------------------------------------------------------- */

__attribute__ ((weak)) void SystemInitHook (void) {
  /* Void implementation of the weak function. */
}

/*!
 * @brief Initialize channel and MU interface for communication with SM.
 */
void SystemPlatformInit(void)
{
    MU_Type *base = s_muBases[SYSTEM_PLATFORM_MU_INST];
    IRQn_Type irq = s_muIrqs[SYSTEM_PLATFORM_MU_INST];

    /* Configure SMT */
    SMT_ChannelConfig(SCMI_A2P, SYSTEM_PLATFORM_MU_INST, SYSTEM_PLATFORM_DBIR_A2P, SYSTEM_PLATFORM_SMA_ADDR);
    SMT_ChannelConfig(SCMI_NOTIFY, SYSTEM_PLATFORM_MU_INST, SYSTEM_PLATFORM_DBIR_NOTIFY, SYSTEM_PLATFORM_SMA_ADDR);
    SMT_ChannelConfig(SCMI_P2A, SYSTEM_PLATFORM_MU_INST, SYSTEM_PLATFORM_DBIR_PRIORITY, SYSTEM_PLATFORM_SMA_ADDR);

    /* Configure MU */
    MU_Init(base);
    EnableIRQ(irq);
    NVIC_SetPriority(irq, SCMI_MU_IRQ_PRIORITY);
    MU_EnableInterrupts(base, (uint32_t)kMU_GenInt1InterruptEnable);
    MU_EnableInterrupts(base, (uint32_t)kMU_GenInt2InterruptEnable);

    /* Enable system notifications */
    SCMI_SystemPowerStateNotify(SCMI_A2P, SCMI_SYS_NOTIFY_ENABLE(1U));

    /* Enable LMM notifications from AP(cortex-A55) */
    SCMI_LmmNotify(SCMI_A2P, SYSTEM_PLATFORM_LMID_A55,
                   SCMI_LMM_NOTIFY_BOOT(1U) | SCMI_LMM_NOTIFY_SHUTDOWN(1U) | SCMI_LMM_NOTIFY_SUSPEND(1U) |
                       SCMI_LMM_NOTIFY_WAKE(1U));

#if defined(SCMI_BBSM_RTC_NOTIFICATIONS_ENABLE)
    /* Enable BBM notifications */
    SCMI_BbmRtcNotify(
        SCMI_A2P, SYSTEM_PLATFORM_RTC_ID,
        SCMI_BBM_NOTIFY_RTC_UPDATED(1U) | SCMI_BBM_NOTIFY_RTC_ROLLOVER(1U) | SCMI_BBM_NOTIFY_RTC_ALARM(1U));
#endif

    /* Enable bus expander notifications */
    SCMI_MiscControlNotify(SCMI_A2P, SCMI_MISC_CTRL_FLAG_BRD | SYSTEM_MISC_CTRL_BUTTON, SCMI_MSG_MISC_CONTROL_SET);

    SCMI_BbmButtonNotify(SCMI_A2P, SCMI_BBM_NOTIFY_BUTTON_DETECT(1U));

    /* Enable FuSa notifications */
    if (SCMI_ERR_SUCCESS != SCMI_FusaFaultGroupNotify(SCMI_A2P,
			    SYSTEM_PLATFORM_FAULT_ID_FIRST, SYSTEM_PLATFORM_FAULT_MASK,
                            SCMI_NOTIFY_ENABLE, NULL, NULL))
    {
	PRINTF("Failed to enable/disable fault notifications\r\n");
    }
}

/*!
 * @brief Deinitialize MU interface.
 */
void SystemPlatformDeinit(void)
{
}

/*!
 * @brief SM Platform Set System State
 */
void SM_Platform_SetSystemState(uint32_t systemState)
{
    g_systemState = systemState;
}

/*!
 * @brief SM Platform Get System State
 */
uint32_t SM_Platform_GetSystemState(void)
{
    return g_systemState;
}

/*!
 * @brief SM Platform Handler.
 */
static void SystemPlatformHandler(void)
{
    MU_Type *base = s_muBases[SYSTEM_PLATFORM_MU_INST];
    uint32_t flags;

    /* Get interrupt status flags */
    flags = MU_GetStatusFlags(base);

    /* Clear interrupts */
    MU_ClearStatusFlags(base, flags);

    /* Notification pending? */
    if ((flags & (uint32_t)kMU_GenInt1Flag) != 0U)
    {
        uint32_t protocolId, messageId;

        /* Get pending info */
        if (SCMI_P2aPending(SCMI_NOTIFY, &protocolId, &messageId) == SCMI_ERR_SUCCESS)
        {
            /* System event? */
            if (protocolId == SCMI_PROTOCOL_SYS)
            {
                uint32_t notifyFlags, systemState;

                if (SCMI_SystemPowerStateNotifier(SCMI_NOTIFY, NULL, &notifyFlags, &systemState, NULL) ==
                    SCMI_ERR_SUCCESS)
                {
                    bool graceful = (SCMI_SYS_NOTIFIER_GRACEFUL(notifyFlags) != 0U);

                    PRINTF("\nSCMI system notification: graceful=%u, state=0x%08X\r\n", graceful, systemState);

                    if (graceful)
                    {
                        SM_Platform_SetSystemState(systemState);
                        switch (systemState)
                        {
                            case SCMI_SYS_STATE_FULL_SHUTDOWN:
                            case SCMI_SYS_STATE_SHUTDOWN:
                                PRINTF("sm request M7 into shutdown\r\n");
                                break;
                            case SCMI_SYS_STATE_FULL_RESET:
                            case SCMI_SYS_STATE_COLD_RESET:
                            case SCMI_SYS_STATE_WARM_RESET:
                                PRINTF("sm request M7 into reset\r\n");
                                break;
                            case SCMI_SYS_STATE_FULL_SUSPEND:
                            case SCMI_SYS_STATE_SUSPEND:
                                PRINTF("sm request M7 into suspend\r\n");
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
            else if (protocolId == SCMI_PROTOCOL_LMM)
            {
                uint32_t notifyFlags, eventLm;

                if (SCMI_LmmEvent(SCMI_NOTIFY, NULL, &eventLm, &notifyFlags) == SCMI_ERR_SUCCESS)
                {
#if SCMI_LMM_POWER_CHANGE_PROCESSED
                   /* Handle peer acore power changes notification to assure right communication. */
                   APP_SRTM_HandleLmmPowerChange(eventLm, notifyFlags);
#endif
                }
            }
            else if (protocolId == SCMI_PROTOCOL_BBM)
            {
                if (messageId == SCMI_MSG_BBM_RTC_EVENT)
                {
                    uint32_t notifyFlags;

                    if (SCMI_BbmRtcEvent(SCMI_NOTIFY, &notifyFlags) == SCMI_ERR_SUCCESS)
                    {
                        PRINTF("\nSCMI BBM RTC notification: flags=0x%08X\r\n", flags);
                    }
                }
                else
                {
                    uint32_t notifyFlags;

                    if (SCMI_BbmButtonEvent(SCMI_NOTIFY, &notifyFlags) == SCMI_ERR_SUCCESS)
                    {
                        PRINTF("\nSCMI BBM button notification: flags=0x%08X\r\n", flags);
                    }
                }
            }
            else if (protocolId == SCMI_PROTOCOL_SENSOR)
            {
                uint32_t sensorId, desc;

                if (SCMI_SensorTripPointEvent(SCMI_NOTIFY, NULL, &sensorId, &desc) == SCMI_ERR_SUCCESS)
                {
                    PRINTF("\nSCMI sensor notification: sensor=%u, desc=0x%08X\r\n", sensorId, desc);
                }
            }
            else if (protocolId == SCMI_PROTOCOL_MISC)
            {
                uint32_t notifyFlags, ctrlId;

                if (SCMI_MiscControlEvent(SCMI_NOTIFY, &ctrlId, &notifyFlags) == SCMI_ERR_SUCCESS)
                {
                    PRINTF("\nSCMI misc notification: ctrl 0x%08X, flags=0x%08X\r\n", ctrlId, notifyFlags);
                }
            }
            else
            {
                PRINTF("\nSCMI unknown notification: 0x%X, 0x%X\r\n", protocolId, messageId);
            }
        }
    }

    /* Priority notification pending? */
    if ((flags & (uint32_t)kMU_GenInt2Flag) != 0U)
    {
        uint32_t protocolId, messageId;

        /* Get pending info */
        if (SCMI_P2aPending(SCMI_P2A, &protocolId, &messageId) == SCMI_ERR_SUCCESS)
        {
            if (messageId == SCMI_MSG_FUSA_FEENV_STATE_EVENT)
            {
                uint32_t state, mSel;

                if (SCMI_FusaFeenvStateEvent(SCMI_P2A, &state, &mSel) == SCMI_ERR_SUCCESS)
                {
                    PRINTF("\nSCMI FuSa F-EENV notification: state=%u, mSel=%u\r\n", state, mSel);
                }
            }
            else if (messageId == SCMI_MSG_FUSA_SEENV_STATE_REQ_EVENT)
            {
                uint32_t cookie;

                if (SCMI_FusaSeenvStateReqEvent(SCMI_P2A, &cookie) == SCMI_ERR_SUCCESS)
                {
                    PRINTF("\nSCMI FuSa S-EENV notification: cookie=%u\r\n", cookie);
                }
            }
            else
            {
                uint32_t faultId, flag;

                if (SCMI_FusaFaultEvent(SCMI_P2A, &faultId, &flag) == SCMI_ERR_SUCCESS)
                {
                    PRINTF("\nSCMI FuSa fault notification: faultId=%u, flags=%u\r\n", faultId, flag);

                    if (SCMI_FUSA_FAULT_FLAG_STATE(flag) != 0U)
                    {
                        SCMI_FusaFaultSet(SCMI_A2P, faultId, SCMI_FUSA_FAULT_SET_STATE(0U));
                    }
                }
            }
        }
    }
}

/*!
 * @brief MU5_A IRQ Handler
 */
void MU5_A_IRQHandler(void)
{
    SystemPlatformHandler();
}
