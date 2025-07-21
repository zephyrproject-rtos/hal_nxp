/*
** ###################################################################
**     Processors:          MIMX94398AVKE_cm33_core1
**                          MIMX94398AVKJ_cm33_core1
**                          MIMX94398AVKM_cm33_core1
**                          MIMX94398AVME_cm33_core1
**                          MIMX94398AVMJ_cm33_core1
**                          MIMX94398AVMM_cm33_core1
**                          MIMX94398CVKE_cm33_core1
**                          MIMX94398CVKJ_cm33_core1
**                          MIMX94398CVKM_cm33_core1
**                          MIMX94398CVME_cm33_core1
**                          MIMX94398CVMJ_cm33_core1
**                          MIMX94398CVMM_cm33_core1
**                          MIMX94398DVKE_cm33_core1
**                          MIMX94398DVKJ_cm33_core1
**                          MIMX94398DVKM_cm33_core1
**                          MIMX94398DVME_cm33_core1
**                          MIMX94398DVMJ_cm33_core1
**                          MIMX94398DVMM_cm33_core1
**                          MIMX94398XVKE_cm33_core1
**                          MIMX94398XVKJ_cm33_core1
**                          MIMX94398XVKM_cm33_core1
**                          MIMX94398XVME_cm33_core1
**                          MIMX94398XVMJ_cm33_core1
**                          MIMX94398XVMM_cm33_core1
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    iMX943RM rev1 draftK
**     Version:             rev. 1.0, 2023-11-01
**     Build:               b250109
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-11-01)
**         Initial version.
**         core name and core alias name
**         +---------------------------------------------------------------------+
**         | core name  |                  core alias name                       |
**         +---------------------------------------------------------------------+
**         | cm33_core0 | m33, cm33                                              |
**         +---------------------------------------------------------------------+
**         | cm33_core1 | m33_2, cm33_2, cm33_sync, netcmix_cm33                 |
**         +---------------------------------------------------------------------+
**         | cm7_core0  | m7, cm7                                                |
**         +---------------------------------------------------------------------+
**         | cm7_core1  | m7_2, cm7_2                                            |
**         +---------------------------------------------------------------------+
**         | ca55_core0 | a55, ca55, a55_0, ca55_0                               |
**         +---------------------------------------------------------------------+
**         | ca55_core1 | a55, ca55, a55_1, ca55_1                               |
**         +---------------------------------------------------------------------+
**         | ca55_core2 | a55, ca55, a55_2, ca55_2                               |
**         +---------------------------------------------------------------------+
**         | ca55_core3 | a55, ca55, a55_3, ca55_3                               |
**         +---------------------------------------------------------------------+
**
** ###################################################################
*/


#include "fsl_common.h"
#include "fsl_debug_console.h"
#include "system_MIMX94398_cm33_core1.h"
#include "fsl_cache.h"
#include "fsl_mu.h"
#include "scmi.h"
#include "scmi_internal.h"
#include "smt.h"

#define NETC_OCRAM_START_ADDR (0x20800000U)
#define NETC_OCRAM_END_ADDR (0x2097FFFFU)

/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */
uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

static MU_Type *const s_muBases[] = MU_BASE_PTRS;
static IRQn_Type const s_muIrqs[] = MU_IRQS;
static uint32_t g_systemState = 0xFFFFFFFF;

/* ----------------------------------------------------------------------------
   -- SystemInitNetcOcram()
   ---------------------------------------------------------------------------- */
static void SystemInitNetcOcram(void)
{
    uint32_t addr = 0U;

    for (addr = NETC_OCRAM_START_ADDR; addr <= NETC_OCRAM_END_ADDR; )
    {
        /* Need to use str(32 bits access) instruction to initialize netc ocram. Cannot use memset(it will be converted to strb instruction by compiler, it's 8 bits access) to initialize netc ocram. */
        *(uint32_t *)addr = 0U;
	addr = addr + 4;
    }
}

/* ----------------------------------------------------------------------------
   -- SystemInitMemoryRegions()
   ---------------------------------------------------------------------------- */

void SystemInitMemoryRegions(void)
{
#if SYSTEM_INIT_MEMORY_REGIONS
    /* Note: Assume these memory regions are accessable */
#if defined(__ICCARM__)
    extern void __RscTblShareWithMpuStart;
    extern void __RscTblShareWithMpuEnd;
#elif defined(__GNUC__)
    extern const void __RscTblShareWithMpuStart;
    extern const void __RscTblShareWithMpuEnd;
#else
#error Not support the compiler.
#endif
    uint32_t start_addr[] = {(uint32_t)&__RscTblShareWithMpuStart};
    uint32_t end_addr[] = {(uint32_t)&__RscTblShareWithMpuEnd};
    int i = 0;

    for (i = 0; i < ARRAY_SIZE(start_addr); i++)
    {
        memset((void *)start_addr[i], 0, end_addr[i] - start_addr[i] + 1);
    }
#endif
}

/* ----------------------------------------------------------------------------
   -- SystemInit()
   ---------------------------------------------------------------------------- */
__attribute__((weak)) void SystemInit(void)
{
#if ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
    SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));    /* set CP10, CP11 Full Access in Secure mode */
    #if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    SCB_NS->CPACR |= ((3UL << 10*2) | (3UL << 11*2));    /* set CP10, CP11 Full Access in Non-secure mode */
    #endif /* (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */
#endif /* ((__FPU_PRESENT == 1) && (__FPU_USED == 1)) */

    SystemInitNetcOcram();

    SystemInitMemoryRegions();

    XCACHE_EnableCache(M33S_CACHE_CTRLPC); /* enable code bus cache(I-Cache) */

    SystemInitHook();
}

/* ----------------------------------------------------------------------------
   -- SystemInitHook()
   ---------------------------------------------------------------------------- */

__attribute__((weak)) void SystemInitHook(void)
{
    /* Void implementation of the weak function. */
}

/* ----------------------------------------------------------------------------
   -- SystemCoreClockUpdate()
   ---------------------------------------------------------------------------- */

void SystemCoreClockUpdate(void)
{
    SystemCoreClock = CLOCK_GetRate(kCLOCK_M33sync);
}

/* ----------------------------------------------------------------------------
   -- SystemTimeDelay(usec)
   ---------------------------------------------------------------------------- */
void SystemTimeDelay(uint32_t usec)
{
    SDK_DelayAtLeastUs(usec, SystemCoreClock);
}

/*!
 * @brief Initialize channel and MU interface for communication with SM.
 */
void SystemPlatformInit(void)
{
    MU_Type *base = s_muBases[SYSTEM_PLATFORM_MU_INST];
    IRQn_Type irq = s_muIrqs[SYSTEM_PLATFORM_MU_INST];

    /* Configure SMT */
    SMT_ChannelConfig(SCMI_A2P, SYSTEM_PLATFORM_MU_INST, SCMI_DBIR_A2P, SYSTEM_PLATFORM_SMA_ADDR);
    SMT_ChannelConfig(SCMI_NOTIFY, SYSTEM_PLATFORM_MU_INST, SCMI_DBIR_NOTIFY, SYSTEM_PLATFORM_SMA_ADDR);
    SMT_ChannelConfig(SCMI_PRIORITY, SYSTEM_PLATFORM_MU_INST, SCMI_DBIR_PRIORITY, SYSTEM_PLATFORM_SMA_ADDR);

    /* Configure MU */
    MU_Init(base);
    EnableIRQ(irq);
    MU_EnableInterrupts(base, kMU_GenInt1InterruptEnable);
    MU_EnableInterrupts(base, kMU_GenInt2InterruptEnable);

    /* Enable system notifications */
    SCMI_SystemPowerStateNotify(SCMI_A2P, SCMI_SYS_NOTIFY_ENABLE(1U));

    /* Enable LMM notifications from AP(cortex-A55) */
    SCMI_LmmNotify(SCMI_A2P, SYSTEM_PLATFORM_LMID_A55,
                   SCMI_LMM_NOTIFY_BOOT(1U) | SCMI_LMM_NOTIFY_SHUTDOWN(1U) | SCMI_LMM_NOTIFY_SUSPEND(1U) |
                       SCMI_LMM_NOTIFY_WAKE(1U));
#if defined(SYSTEM_PLATFORM_RTC_NOTIFY) && SYSTEM_PLATFORM_RTC_NOTIFY
    /* Enable BBM notifications */
    SCMI_BbmRtcNotify(
        SCMI_A2P, SM_PLATFORM_RTC_ID,
        SCMI_BBM_NOTIFY_RTC_UPDATED(1U) | SCMI_BBM_NOTIFY_RTC_ROLLOVER(1U) | SCMI_BBM_NOTIFY_RTC_ALARM(1U));
#endif
    SCMI_BbmButtonNotify(SCMI_A2P, SCMI_BBM_NOTIFY_BUTTON_DETECT(1U));

    /* Enable FuSa notifications */
    SCMI_FusaFaultGroupNotify(SCMI_A2P, SYSTEM_PLATFORM_FAULT_ID_FIRST, SYSTEM_PLATFORM_FAULT_MASK,
                              SYSTEM_PLATFORM_NOTIFY_ENABLE, NULL, NULL);

    SCMI_PowerStateSet(SCMI_A2P, SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_NETC, 0U, SCMI_POWER_DOMAIN_STATE_ON);
}

/*!
 * @brief Deinitialize MU interface.
 */
void SystemPlatformDeinit(void)
{
}

/*!
 * @brief System Platform Set System State
 */
void SystemPlatformSetSystemState(uint32_t systemState)
{
    g_systemState = systemState;
}

/*!
 * @brief System Platform Get System State
 */
uint32_t SystemPlatformGetSystemState(void)
{
    return g_systemState;
}

/*!
 * @brief SM Platform Handler.
 */
void SystemPlatformHandler(void)
{
    MU_Type *base = s_muBases[SYSTEM_PLATFORM_MU_INST];
    uint32_t flags;

    /* Get interrupt status flags */
    flags = MU_GetStatusFlags(base);

    /* Clear interrupts */
    MU_ClearStatusFlags(base, flags);

    /* Notification pending? */
    if (flags & kMU_GenInt1Flag)
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
                        SystemPlatformSetSystemState(systemState);
                        switch (systemState)
                        {
                            case SCMI_SYS_STATE_FULL_SHUTDOWN:
                            case SCMI_SYS_STATE_SHUTDOWN:
                                PRINTF("shutdown\r\n");
                                break;
                            case SCMI_SYS_STATE_FULL_RESET:
                            case SCMI_SYS_STATE_COLD_RESET:
                            case SCMI_SYS_STATE_WARM_RESET:
                                PRINTF("reset\r\n");
                                break;
                            case SCMI_SYS_STATE_FULL_SUSPEND:
                            case SCMI_SYS_STATE_SUSPEND:
                                PRINTF("suspend\r\n");
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
                    PRINTF("\nSCMI LMM notification: LM %u, flags=0x%08X\r\n", eventLm, notifyFlags);
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
            else
            {
                PRINTF("\nSCMI unknown notification: 0x%X, 0x%X\r\n", protocolId, messageId);
            }
        }
    }

    /* Priority notification pending? */
    if (flags & kMU_GenInt2Flag)
    {
        uint32_t protocolId, messageId;

        /* Get pending info */
        if (SCMI_P2aPending(SCMI_PRIORITY, &protocolId, &messageId) == SCMI_ERR_SUCCESS)
        {
            if (messageId == SCMI_MSG_FUSA_FEENV_STATE_EVENT)
            {
                uint32_t state, mSel;

                if (SCMI_FusaFeenvStateEvent(SCMI_PRIORITY, &state, &mSel) == SCMI_ERR_SUCCESS)
                {
                    PRINTF("\nSCMI FuSa F-EENV notification: state=%u, mSel=%u\r\n", state, mSel);
                }
            }
            else if (messageId == SCMI_MSG_FUSA_SEENV_STATE_REQ_EVENT)
            {
                uint32_t cookie;

                if (SCMI_FusaSeenvStateReqEvent(SCMI_PRIORITY, &cookie) == SCMI_ERR_SUCCESS)
                {
                    PRINTF("\nSCMI FuSa S-EENV notification: cookie=%u\r\n", cookie);
                }
            }
            else
            {
                uint32_t faultId, flag;

                if (SCMI_FusaFaultEvent(SCMI_PRIORITY, &faultId, &flag) == SCMI_ERR_SUCCESS)
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
 * @brief MU8_A IRQ Handler
 */
void MU8_A_IRQHandler(void)
{
    SystemPlatformHandler();
}
