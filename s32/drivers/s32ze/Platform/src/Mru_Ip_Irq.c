/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    Mru_Ip_Irq.c
*
*   @version 1.0.0
*
*   @brief   ISR handler file.
*   @details Declaration APIs for Mru ISR.
*
*   @addtogroup MRU_IP_DRIVER Mru Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mru_Ip.h"

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MRU_IP_VENDOR_ID_IRQ_C                      43
#define CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION_IRQ_C       7
#define CDD_PLATFORM_MRU_IP_AR_RELEASE_REVISION_VERSION_IRQ_C    0
#define CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION_IRQ_C               2
#define CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION_IRQ_C               0
#define CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION_IRQ_C               1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Mru_Ip.h and Mru_Ip_Irq.c are of the same vendor */
#if (CDD_PLATFORM_MRU_IP_VENDOR_ID != CDD_PLATFORM_MRU_IP_VENDOR_ID_IRQ_C)
    #error "Mru_Ip.h and Mru_Ip_Irq.c have different vendor ids"
#endif
/* Check if Mru_Ip.h file and Mru_Ip_Irq.c file are of the same Autosar version */
#if ((CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C) || \
     (CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION_IRQ_C) || \
     (CDD_PLATFORM_MRU_IP_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_REVISION_VERSION_IRQ_C))
#error "AutoSar Version Numbers of Mru_Ip.h and Mru_Ip_Irq.c are different"
#endif
#if ((CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION_IRQ_C) || \
     (CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION != CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION_IRQ_C) || \
     (CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION != CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION_IRQ_C))
#error "Software Version Numbers of Mru_Ip.h and Mru_Ip_Irq.c are different"
#endif
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#ifdef PLATFORM_IP_ENABLE_MRU
#if (PLATFORM_IP_ENABLE_MRU == STD_ON)

#define PLATFORM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Platform_MemMap.h"

extern Mru_Ip_StateStructureType* Mru_Ip_apxStateStructureArray[MRU_IP_NUMBER_OF_INSTANCES];

#define PLATFORM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Platform_MemMap.h"
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

#ifdef SMU_MRU_ENABLED
    #if (!defined MRU_IP_SKIP_SMU_MRU_INT0_HANDLER)
ISR(Mru_Ip_SMU_MRU_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_SMU_MRU_INT1_HANDLER)
ISR(Mru_Ip_SMU_MRU_Int1_IRQHandler);
    #endif
#endif

#ifdef RTU0_MRU0_ENABLED
    #if (!defined MRU_IP_SKIP_RTU0_MRU0_INT0_HANDLER)
ISR(Mru_Ip_RTU0_MRU0_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_RTU0_MRU0_INT1_HANDLER)
ISR(Mru_Ip_RTU0_MRU0_Int1_IRQHandler);
    #endif
#endif

#ifdef RTU0_MRU1_ENABLED
    #if (!defined MRU_IP_SKIP_RTU0_MRU1_INT0_HANDLER)
ISR(Mru_Ip_RTU0_MRU1_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_RTU0_MRU1_INT1_HANDLER)
ISR(Mru_Ip_RTU0_MRU1_Int1_IRQHandler);
    #endif
#endif

#ifdef RTU0_MRU2_ENABLED
    #if (!defined MRU_IP_SKIP_RTU0_MRU2_INT0_HANDLER)
ISR(Mru_Ip_RTU0_MRU2_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_RTU0_MRU2_INT1_HANDLER)
ISR(Mru_Ip_RTU0_MRU2_Int1_IRQHandler);
    #endif
#endif

#ifdef RTU0_MRU3_ENABLED
    #if (!defined MRU_IP_SKIP_RTU0_MRU3_INT0_HANDLER)
ISR(Mru_Ip_RTU0_MRU3_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_RTU0_MRU3_INT1_HANDLER)
ISR(Mru_Ip_RTU0_MRU3_Int1_IRQHandler);
    #endif
#endif

#ifdef RTU1_MRU4_ENABLED
    #if (!defined MRU_IP_SKIP_RTU1_MRU4_INT0_HANDLER)
ISR(Mru_Ip_RTU1_MRU4_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_RTU1_MRU4_INT1_HANDLER)
ISR(Mru_Ip_RTU1_MRU4_Int1_IRQHandler);
    #endif
#endif

#ifdef RTU1_MRU5_ENABLED
    #if (!defined MRU_IP_SKIP_RTU1_MRU5_INT0_HANDLER)
ISR(Mru_Ip_RTU1_MRU5_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_RTU1_MRU5_INT1_HANDLER)
ISR(Mru_Ip_RTU1_MRU5_Int1_IRQHandler);
    #endif
#endif

#ifdef RTU1_MRU6_ENABLED
    #if (!defined MRU_IP_SKIP_RTU1_MRU6_INT0_HANDLER)
ISR(Mru_Ip_RTU1_MRU6_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_RTU1_MRU6_INT1_HANDLER)
ISR(Mru_Ip_RTU1_MRU6_Int1_IRQHandler);
    #endif
#endif

#ifdef RTU1_MRU7_ENABLED
    #if (!defined MRU_IP_SKIP_RTU1_MRU7_INT0_HANDLER)
ISR(Mru_Ip_RTU1_MRU7_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_RTU1_MRU7_INT1_HANDLER)
ISR(Mru_Ip_RTU1_MRU7_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU0_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU0_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU0_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU0_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU0_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU1_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU1_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU1_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU1_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU1_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU2_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU2_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU2_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU2_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU2_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU3_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU3_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU3_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU3_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU3_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU4_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU4_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU4_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU4_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU4_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU5_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU5_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU5_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU5_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU5_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU6_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU6_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU6_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU6_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU6_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU7_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU7_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU7_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU7_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU7_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU8_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU8_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU8_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU8_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU8_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU9_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU9_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU9_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU9_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU9_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU10_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU10_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU10_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU10_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU10_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU11_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU11_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU11_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU11_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU11_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU12_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU12_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU12_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU12_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU12_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU13_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU13_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU13_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU13_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU13_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU14_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU14_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU14_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU14_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU14_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU15_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU15_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU15_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU15_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU15_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU16_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU16_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU16_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU16_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU16_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU17_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU17_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU17_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU17_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU17_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU18_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU18_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU18_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU18_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU18_Int1_IRQHandler);
    #endif
#endif

#ifdef CE_MRU19_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU19_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU19_Int0_IRQHandler);
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU19_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU19_Int1_IRQHandler);
    #endif
#endif

#if ((defined CE_MRU6_ENABLED && (!defined MRU_IP_SKIP_CE_MRU6_INT0_HANDLER)) || (defined CE_MRU7_ENABLED && (!defined MRU_IP_SKIP_CE_MRU7_INT0_HANDLER)) || (defined CE_MRU8_ENABLED && (!defined MRU_IP_SKIP_CE_MRU8_INT0_HANDLER)) || \
     (defined CE_MRU9_ENABLED && (!defined MRU_IP_SKIP_CE_MRU9_INT0_HANDLER)) || (defined CE_MRU10_ENABLED && (!defined MRU_IP_SKIP_CE_MRU10_INT0_HANDLER)) || (defined CE_MRU11_ENABLED && (!defined MRU_IP_SKIP_CE_MRU11_INT0_HANDLER)))
ISR(Mru_Ip_CE_MRU6_TO_MRU11_Int0_IRQHandler);
#endif
#if ((defined CE_MRU6_ENABLED && (!defined MRU_IP_SKIP_CE_MRU6_INT1_HANDLER)) || (defined CE_MRU7_ENABLED && (!defined MRU_IP_SKIP_CE_MRU7_INT1_HANDLER)) || (defined CE_MRU8_ENABLED && (!defined MRU_IP_SKIP_CE_MRU8_INT1_HANDLER)) || \
     (defined CE_MRU9_ENABLED && (!defined MRU_IP_SKIP_CE_MRU9_INT1_HANDLER)) || (defined CE_MRU10_ENABLED && (!defined MRU_IP_SKIP_CE_MRU10_INT1_HANDLER)) || (defined CE_MRU11_ENABLED && (!defined MRU_IP_SKIP_CE_MRU11_INT1_HANDLER)))
ISR(Mru_Ip_CE_MRU6_TO_MRU11_Int1_IRQHandler);
#endif
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef SMU_MRU_ENABLED
    #if (!defined MRU_IP_SKIP_SMU_MRU_INT0_HANDLER)
ISR(Mru_Ip_SMU_MRU_Int0_IRQHandler)
{
    SMU_MRU_Type* Base = Mru_Ip_apxSMU_Bases[MRU_IP_SMU_MRU_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_SMU_MRU_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_SMU_MRU_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < SMU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_SMU_MRU_INT1_HANDLER)
ISR(Mru_Ip_SMU_MRU_Int1_IRQHandler)
{
    SMU_MRU_Type* Base = Mru_Ip_apxSMU_Bases[MRU_IP_SMU_MRU_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_SMU_MRU_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_SMU_MRU_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < SMU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef RTU0_MRU0_ENABLED
    #if (!defined MRU_IP_SKIP_RTU0_MRU0_INT0_HANDLER)
ISR(Mru_Ip_RTU0_MRU0_Int0_IRQHandler)
{
    RTU_MRU_Type* Base = Mru_Ip_apxRTU_Bases[MRU_IP_RTU0_MRU0_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_RTU0_MRU0_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_RTU0_MRU0_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < RTU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_RTU0_MRU0_INT1_HANDLER)
ISR(Mru_Ip_RTU0_MRU0_Int1_IRQHandler)
{
    RTU_MRU_Type* Base = Mru_Ip_apxRTU_Bases[MRU_IP_RTU0_MRU0_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_RTU0_MRU0_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_RTU0_MRU0_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < RTU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef RTU0_MRU1_ENABLED
    #if (!defined MRU_IP_SKIP_RTU0_MRU1_INT0_HANDLER)
ISR(Mru_Ip_RTU0_MRU1_Int0_IRQHandler)
{
    RTU_MRU_Type* Base = Mru_Ip_apxRTU_Bases[MRU_IP_RTU0_MRU1_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_RTU0_MRU1_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_RTU0_MRU1_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < RTU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_RTU0_MRU1_INT1_HANDLER)
ISR(Mru_Ip_RTU0_MRU1_Int1_IRQHandler)
{
    RTU_MRU_Type* Base = Mru_Ip_apxRTU_Bases[MRU_IP_RTU0_MRU1_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_RTU0_MRU1_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_RTU0_MRU1_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < RTU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef RTU0_MRU2_ENABLED
    #if (!defined MRU_IP_SKIP_RTU0_MRU2_INT0_HANDLER)
ISR(Mru_Ip_RTU0_MRU2_Int0_IRQHandler)
{
    RTU_MRU_Type* Base = Mru_Ip_apxRTU_Bases[MRU_IP_RTU0_MRU2_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_RTU0_MRU2_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_RTU0_MRU2_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < RTU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_RTU0_MRU2_INT1_HANDLER)
ISR(Mru_Ip_RTU0_MRU2_Int1_IRQHandler)
{
    RTU_MRU_Type* Base = Mru_Ip_apxRTU_Bases[MRU_IP_RTU0_MRU2_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_RTU0_MRU2_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_RTU0_MRU2_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < RTU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef RTU0_MRU3_ENABLED
    #if (!defined MRU_IP_SKIP_RTU0_MRU3_INT0_HANDLER)
ISR(Mru_Ip_RTU0_MRU3_Int0_IRQHandler)
{
    RTU_MRU_Type* Base = Mru_Ip_apxRTU_Bases[MRU_IP_RTU0_MRU3_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_RTU0_MRU3_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_RTU0_MRU3_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < RTU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_RTU0_MRU3_INT1_HANDLER)
ISR(Mru_Ip_RTU0_MRU3_Int1_IRQHandler)
{
    RTU_MRU_Type* Base = Mru_Ip_apxRTU_Bases[MRU_IP_RTU0_MRU3_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_RTU0_MRU3_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_RTU0_MRU3_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < RTU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef RTU1_MRU4_ENABLED
    #if (!defined MRU_IP_SKIP_RTU1_MRU4_INT0_HANDLER)
ISR(Mru_Ip_RTU1_MRU4_Int0_IRQHandler)
{
    RTU_MRU_Type* Base = Mru_Ip_apxRTU_Bases[MRU_IP_RTU1_MRU4_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_RTU1_MRU4_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_RTU1_MRU4_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < RTU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_RTU1_MRU4_INT1_HANDLER)
ISR(Mru_Ip_RTU1_MRU4_Int1_IRQHandler)
{
    RTU_MRU_Type* Base = Mru_Ip_apxRTU_Bases[MRU_IP_RTU1_MRU4_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_RTU1_MRU4_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_RTU1_MRU4_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < RTU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef RTU1_MRU5_ENABLED
    #if (!defined MRU_IP_SKIP_RTU1_MRU5_INT0_HANDLER)
ISR(Mru_Ip_RTU1_MRU5_Int0_IRQHandler)
{
    RTU_MRU_Type* Base = Mru_Ip_apxRTU_Bases[MRU_IP_RTU1_MRU5_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_RTU1_MRU5_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_RTU1_MRU5_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < RTU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_RTU1_MRU5_INT1_HANDLER)
ISR(Mru_Ip_RTU1_MRU5_Int1_IRQHandler)
{
    RTU_MRU_Type* Base = Mru_Ip_apxRTU_Bases[MRU_IP_RTU1_MRU5_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_RTU1_MRU5_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_RTU1_MRU5_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < RTU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef RTU1_MRU6_ENABLED
    #if (!defined MRU_IP_SKIP_RTU1_MRU6_INT0_HANDLER)
ISR(Mru_Ip_RTU1_MRU6_Int0_IRQHandler)
{
    RTU_MRU_Type* Base = Mru_Ip_apxRTU_Bases[MRU_IP_RTU1_MRU6_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_RTU1_MRU6_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_RTU1_MRU6_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < RTU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_RTU1_MRU6_INT1_HANDLER)
ISR(Mru_Ip_RTU1_MRU6_Int1_IRQHandler)
{
    RTU_MRU_Type* Base = Mru_Ip_apxRTU_Bases[MRU_IP_RTU1_MRU6_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_RTU1_MRU6_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_RTU1_MRU6_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < RTU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef RTU1_MRU7_ENABLED
    #if (!defined MRU_IP_SKIP_RTU1_MRU7_INT0_HANDLER)
ISR(Mru_Ip_RTU1_MRU7_Int0_IRQHandler)
{
    RTU_MRU_Type* Base = Mru_Ip_apxRTU_Bases[MRU_IP_RTU1_MRU7_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_RTU1_MRU7_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_RTU1_MRU7_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < RTU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_RTU1_MRU7_INT1_HANDLER)
ISR(Mru_Ip_RTU1_MRU7_Int1_IRQHandler)
{
    RTU_MRU_Type* Base = Mru_Ip_apxRTU_Bases[MRU_IP_RTU1_MRU7_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_RTU1_MRU7_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_RTU1_MRU7_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < RTU_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU0_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU0_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU0_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU0_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU0_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU0_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU0_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU0_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU0_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU0_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU0_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU0_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU0_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU1_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU1_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU1_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU1_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU1_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU1_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU1_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU1_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU1_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU1_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU1_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU1_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU1_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU2_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU2_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU2_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU2_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU2_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU2_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU2_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU2_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU2_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU2_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU2_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU2_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU2_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU3_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU3_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU3_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU3_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU3_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU3_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU3_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU3_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU3_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU3_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU3_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU3_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU3_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU4_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU4_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU4_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU4_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU4_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU4_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU4_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU4_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU4_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU4_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU4_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU4_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU4_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU5_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU5_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU5_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU5_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU5_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU5_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU5_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU5_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU5_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU5_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU5_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU5_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU5_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU6_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU6_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU6_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU6_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU6_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU6_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU6_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU6_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU6_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU6_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU6_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU6_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU6_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU7_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU7_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU7_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU7_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU7_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU7_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU7_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU7_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU7_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU7_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU7_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU7_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU7_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU8_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU8_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU8_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU8_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU8_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU8_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU8_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU8_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU8_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU8_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU8_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU8_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU8_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU9_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU9_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU9_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU9_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU9_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU9_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU9_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU9_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU9_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU9_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU9_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU9_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU9_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU10_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU10_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU10_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU10_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU10_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU10_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU10_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU10_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU10_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU10_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU10_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU10_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU10_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU11_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU11_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU11_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU11_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU11_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU11_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU11_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU11_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU11_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU11_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU11_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU11_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU11_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU12_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU12_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU12_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU12_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU12_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU12_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU12_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU12_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU12_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU12_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU12_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU12_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU12_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU13_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU13_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU13_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU13_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU13_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU13_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU13_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU13_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU13_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU13_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU13_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU13_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU13_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU14_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU14_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU14_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU14_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU14_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU14_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU14_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU14_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU14_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU14_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU14_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU14_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU14_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU15_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU15_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU15_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU15_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU15_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU15_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU15_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU15_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU15_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU15_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU15_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU15_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU15_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU16_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU16_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU16_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU16_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU16_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU16_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU16_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU16_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU16_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU16_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU16_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU16_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU16_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU17_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU17_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU17_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU17_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU17_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU17_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU17_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU17_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU17_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU17_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU17_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU17_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU17_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU18_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU18_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU18_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU18_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU18_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU18_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU18_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU18_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU18_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU18_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU18_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU18_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU18_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#ifdef CE_MRU19_ENABLED
    #if (!defined MRU_IP_SKIP_CE_MRU19_INT0_HANDLER)
ISR(Mru_Ip_CE_MRU19_Int0_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU19_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU19_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU19_ID, MRU_IP_INT_GROUP_0);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU19_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
    #if (!defined MRU_IP_SKIP_CE_MRU19_INT1_HANDLER)
ISR(Mru_Ip_CE_MRU19_Int1_IRQHandler)
{
    CE_MRU_Type* Base = Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU19_INSTANCE];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU19_ID];
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU19_ID, MRU_IP_INT_GROUP_1);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU19_CH_NUM; ChannelIdx++)
        {
            Base->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
        }
    }
}
    #endif
#endif

#if ((defined CE_MRU6_ENABLED && (!defined MRU_IP_SKIP_CE_MRU6_INT0_HANDLER)) || (defined CE_MRU7_ENABLED && (!defined MRU_IP_SKIP_CE_MRU7_INT0_HANDLER)) || (defined CE_MRU8_ENABLED && (!defined MRU_IP_SKIP_CE_MRU8_INT0_HANDLER)) || \
     (defined CE_MRU9_ENABLED && (!defined MRU_IP_SKIP_CE_MRU9_INT0_HANDLER)) || (defined CE_MRU10_ENABLED && (!defined MRU_IP_SKIP_CE_MRU10_INT0_HANDLER)) || (defined CE_MRU11_ENABLED && (!defined MRU_IP_SKIP_CE_MRU11_INT0_HANDLER)))
ISR(Mru_Ip_CE_MRU6_TO_MRU11_Int0_IRQHandler)
{
#if defined CE_MRU6_ENABLED
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU6_ID];
#elif defined CE_MRU7_ENABLED
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU7_ID];
#elif defined CE_MRU8_ENABLED
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU8_ID];
#elif defined CE_MRU9_ENABLED
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU9_ID];
#elif defined CE_MRU10_ENABLED
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU10_ID];
#elif defined CE_MRU11_ENABLED
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU11_ID];
#endif
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        #if defined CE_MRU6_ENABLED
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU6_ID, MRU_IP_INT_GROUP_0);
        #endif
        #if defined CE_MRU7_ENABLED
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU7_ID, MRU_IP_INT_GROUP_0);
        #endif
        #if defined CE_MRU8_ENABLED
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU8_ID, MRU_IP_INT_GROUP_0);
        #endif
        #if defined CE_MRU9_ENABLED
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU9_ID, MRU_IP_INT_GROUP_0);
        #endif
        #if defined CE_MRU10_ENABLED
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU10_ID, MRU_IP_INT_GROUP_0);
        #endif
        #if defined CE_MRU11_ENABLED
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU11_ID, MRU_IP_INT_GROUP_0);
        #endif
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            #if defined CE_MRU6_ENABLED
            Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU6_INSTANCE]->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
            #endif
            #if defined CE_MRU7_ENABLED
            Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU7_INSTANCE]->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
            #endif
            #if defined CE_MRU8_ENABLED
            Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU8_INSTANCE]->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
            #endif
            #if defined CE_MRU9_ENABLED
            Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU9_INSTANCE]->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
            #endif
            #if defined CE_MRU10_ENABLED
            Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU10_INSTANCE]->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
            #endif
            #if defined CE_MRU11_ENABLED
            Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU11_INSTANCE]->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
            #endif
        }
    }
}
#endif
#if ((defined CE_MRU6_ENABLED && (!defined MRU_IP_SKIP_CE_MRU6_INT1_HANDLER)) || (defined CE_MRU7_ENABLED && (!defined MRU_IP_SKIP_CE_MRU7_INT1_HANDLER)) || (defined CE_MRU8_ENABLED && (!defined MRU_IP_SKIP_CE_MRU8_INT1_HANDLER)) || \
     (defined CE_MRU9_ENABLED && (!defined MRU_IP_SKIP_CE_MRU9_INT1_HANDLER)) || (defined CE_MRU10_ENABLED && (!defined MRU_IP_SKIP_CE_MRU10_INT1_HANDLER)) || (defined CE_MRU11_ENABLED && (!defined MRU_IP_SKIP_CE_MRU11_INT1_HANDLER)))
ISR(Mru_Ip_CE_MRU6_TO_MRU11_Int1_IRQHandler)
{
#if defined CE_MRU6_ENABLED
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU6_ID];
#elif defined CE_MRU7_ENABLED
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU7_ID];
#elif defined CE_MRU8_ENABLED
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU8_ID];
#elif defined CE_MRU9_ENABLED
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU9_ID];
#elif defined CE_MRU10_ENABLED
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU10_ID];
#elif defined CE_MRU11_ENABLED
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[MRU_IP_CE_MRU11_ID];
#endif
    uint8 ChannelIdx;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        /* Processing IRQ */
        #if defined CE_MRU6_ENABLED
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU6_ID, MRU_IP_INT_GROUP_1);
        #endif
        #if defined CE_MRU7_ENABLED
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU7_ID, MRU_IP_INT_GROUP_1);
        #endif
        #if defined CE_MRU8_ENABLED
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU8_ID, MRU_IP_INT_GROUP_1);
        #endif
        #if defined CE_MRU9_ENABLED
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU9_ID, MRU_IP_INT_GROUP_1);
        #endif
        #if defined CE_MRU10_ENABLED
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU10_ID, MRU_IP_INT_GROUP_1);
        #endif
        #if defined CE_MRU11_ENABLED
        Mru_Ip_IrqHandler(MRU_IP_CE_MRU11_ID, MRU_IP_INT_GROUP_1);
        #endif
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags for all channels */
        for(ChannelIdx = 0u; ChannelIdx < CE_MRU_CHXCONFIG_COUNT; ChannelIdx++)
        {
            #if defined CE_MRU6_ENABLED
            Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU6_INSTANCE]->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
            #endif
            #if defined CE_MRU7_ENABLED
            Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU7_INSTANCE]->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
            #endif
            #if defined CE_MRU8_ENABLED
            Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU8_INSTANCE]->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
            #endif
            #if defined CE_MRU9_ENABLED
            Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU9_INSTANCE]->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
            #endif
            #if defined CE_MRU10_ENABLED
            Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU10_INSTANCE]->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
            #endif
            #if defined CE_MRU11_ENABLED
            Mru_Ip_apxCE_Bases[MRU_IP_CE_MRU11_INSTANCE]->CHXCONFIG[ChannelIdx].CH_MBSTAT &= (uint32)0xFFFFFFFFu;
            #endif
        }
    }
}
#endif

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#endif /* PLATFORM_IP_ENABLE_MRU == STD_ON)*/
#endif /* PLATFORM_IP_ENABLE_MRU */

#ifdef __cplusplus
}
#endif

/** @} */



