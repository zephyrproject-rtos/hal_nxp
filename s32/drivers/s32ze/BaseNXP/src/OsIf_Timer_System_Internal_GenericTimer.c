/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file
*
*   @addtogroup osif_drv
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "OsIf_DeviceRegisters.h"
#include "OsIf_Cfg.h"
#include "OsIf_Timer_System_Internal_GenericTimer.h"
#include "Mcal.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OSIF_TIMER_SYS_INTER_GENERICTIMER_VENDOR_ID_C                    43
#define OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_MAJOR_VERSION_C     4
#define OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_MINOR_VERSION_C     7
#define OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_REVISION_VERSION_C  0
#define OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_MAJOR_VERSION_C             0
#define OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_MINOR_VERSION_C             9
#define OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against OsIf_DeviceRegisters.h */
#if (OSIF_TIMER_SYS_INTER_GENERICTIMER_VENDOR_ID_C != OSIF_DEVICE_REGISTERS_VENDOR_ID)
    #error "OsIf_Timer_System_Internal_GenericTimer.c and OsIf_DeviceRegisters.h have different vendor ids"
#endif
#if ((OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_MAJOR_VERSION_C    != OSIF_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_MINOR_VERSION_C    != OSIF_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_REVISION_VERSION_C != OSIF_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer_System_Internal_GenericTimer.c and OsIf_DeviceRegisters.h are different"
#endif
#if ((OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_MAJOR_VERSION_C != OSIF_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_MINOR_VERSION_C != OSIF_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_PATCH_VERSION_C != OSIF_DEVICE_REGISTERS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer_System_Internal_GenericTimer.c and OsIf_DeviceRegisters.h are different"
#endif

/* Checks against OsIf_Cfg.h */
#if (OSIF_TIMER_SYS_INTER_GENERICTIMER_VENDOR_ID_C != OSIF_CFG_VENDOR_ID)
    #error "OsIf_Timer_System_Internal_GenericTimer.c and OsIf_Cfg.h have different vendor ids"
#endif
#if ((OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_MAJOR_VERSION_C    != OSIF_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_MINOR_VERSION_C    != OSIF_CFG_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_REVISION_VERSION_C != OSIF_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer_System_Internal_GenericTimer.c and OsIf_Cfg.h are different"
#endif
#if ((OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_MAJOR_VERSION_C != OSIF_CFG_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_MINOR_VERSION_C != OSIF_CFG_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_PATCH_VERSION_C != OSIF_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer_System_Internal_GenericTimer.c and OsIf_Cfg.h are different"
#endif

/* Checks against OsIf_Timer_System_Internal_GenericTimer.h */
#if (OSIF_TIMER_SYS_INTER_GENERICTIMER_VENDOR_ID_C != OSIF_TIMER_SYS_INTER_GENERICTIMER_VENDOR_ID)
    #error "OsIf_Timer_System_Internal_GenericTimer.c and OsIf_Timer_System_Internal_GenericTimer.h have different vendor ids"
#endif
#if ((OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_MAJOR_VERSION_C    != OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_MINOR_VERSION_C    != OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_REVISION_VERSION_C != OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer_System_Internal_GenericTimer.c and OsIf_Timer_System_Internal_GenericTimer.h are different"
#endif
#if ((OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_MAJOR_VERSION_C != OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_MINOR_VERSION_C != OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_PATCH_VERSION_C != OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer_System_Internal_GenericTimer.c and OsIf_Timer_System_Internal_GenericTimer.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against OsIf_Timer_System_Internal_GenericTimer.h */
    #if ((OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of OsIf_Timer_System_Internal_GenericTimer.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#if defined(OSIF_USE_GENERICTIMER)
#if (OSIF_USE_GENERICTIMER == STD_ON)

#define CNTP_CTL_IMASK_MASK                         (0x2U)
#define CNTP_CTL_ENABLE_EN                          (0x1U)
#define CNTP_TVAL_TIMERVALUE_MASK                   (0xFFFFFFFFU)

#define GENERICTIMER_GET_COUNTER()                  ((read_CNTP_TVAL()) & CNTP_TVAL_TIMERVALUE_MASK)
#define GENERICTIMER_DELTA_OUTER(high, low, max)    ((max) - ((high) - (low)))
#define GENERICTIMER_DELTA_INNER(high, low)         ((high) - (low))
#define GENERICTIMER_TVAL_MAX                       (0xFFFFFFFFu)

#define GENERICTIMER_OVERFLOWED(curr, ref)          ((curr) > (ref))
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    #define WRITE_CNTFRQ_INSTR        "msr CNTFRQ_EL0, %[Rd]"
    #define WRITE_CNTP_CTL_INSTR      "msr CNTP_CTL_EL0, %[Rd]"
    #define WRITE_CNTP_TVAL_INSTR     "msr CNTP_TVAL_EL0, %[Rd]"
    #define READ_CNTP_TVAL_INSTR      "mrs %[Rd], CNTP_TVAL_EL0"
#elif ((MCAL_PLATFORM_ARM == MCAL_ARM_AARCH32) || (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH))
    #define WRITE_CNTFRQ_INSTR        "mcr p15,0,%[Rd],c14,c0,0"
    #define WRITE_CNTP_CTL_INSTR      "mcr p15,0,%[Rd],c14,c2,1"
    #define WRITE_CNTP_TVAL_INSTR     "mcr p15,0,%[Rd],c14,c2,0"
    #define READ_CNTP_TVAL_INSTR      "mrc p15,0,%[Rd],c14,c2,0"
#else
    #error "Unsupported architecture!"
#endif
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#define BASENXP_START_SEC_CODE
#include "BaseNXP_MemMap.h"

#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
static void write_CNTFRQ(uint32 val);
static void write_CNTFRQ(uint32 val)
{
    uint64 val64 = val; /* Force assembler to use a 64-bit register on AARCH64 */
/*LDRA_NOANALYSIS*/
    ASMV_KEYWORD(
        WRITE_CNTFRQ_INSTR
        : /* No Output */
        : [Rd]"r"(val64)
    );
/*LDRA_ANALYSIS*/
}

static void write_CNTP_CTL(uint32 val);
static void write_CNTP_CTL(uint32 val) 
{
    uint64 val64 = val; /* Force assembler to use a 64-bit register on AARCH64 */
/*LDRA_NOANALYSIS*/
    ASMV_KEYWORD(
        WRITE_CNTP_CTL_INSTR
        : /* No Output */
        : [Rd]"r"(val64)
    );
/*LDRA_ANALYSIS*/
}

static void write_CNTP_TVAL(uint32 val);
static void write_CNTP_TVAL(uint32 val) 
{
    uint64 val64 = val; /* Force assembler to use a 64-bit register on AARCH64 */
/*LDRA_NOANALYSIS*/
    ASMV_KEYWORD(
        WRITE_CNTP_TVAL_INSTR
        : /* No Output */
        : [Rd]"r"(val64)
    );
/*LDRA_ANALYSIS*/
}

static uint32 read_CNTP_TVAL(void);
static uint32 read_CNTP_TVAL(void) 
{
    uint64 cntp_tval = 0;
/*LDRA_NOANALYSIS*/
    ASMV_KEYWORD(
        READ_CNTP_TVAL_INSTR
        : [Rd]"=r"(cntp_tval)
    );
/*LDRA_ANALYSIS*/
    return cntp_tval;
}
#elif ((MCAL_PLATFORM_ARM == MCAL_ARM_AARCH32) || (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH))
static void write_CNTFRQ(uint32 val);
static void write_CNTFRQ(uint32 val)
{
    uint32 val32 = val; 
/*LDRA_NOANALYSIS*/
    ASMV_KEYWORD(
        WRITE_CNTFRQ_INSTR
        : /* No Output */
        : [Rd]"r"(val32)
    );
/*LDRA_ANALYSIS*/
}

static void write_CNTP_CTL(uint32 val);
static void write_CNTP_CTL(uint32 val) 
{
    uint32 val32 = val; 
/*LDRA_NOANALYSIS*/
    ASMV_KEYWORD(
        WRITE_CNTP_CTL_INSTR
        : /* No Output */
        : [Rd]"r"(val32)
    );
/*LDRA_ANALYSIS*/
}

static void write_CNTP_TVAL(uint32 val);
static void write_CNTP_TVAL(uint32 val) 
{
    uint32 val32 = val; 
/*LDRA_NOANALYSIS*/
    ASMV_KEYWORD(
        WRITE_CNTP_TVAL_INSTR
        : /* No Output */
        : [Rd]"r"(val32)
    );
/*LDRA_ANALYSIS*/
}

static uint32 read_CNTP_TVAL(void);
static uint32 read_CNTP_TVAL(void) 
{
    uint32 cntp_tval = 0;
/*LDRA_NOANALYSIS*/
    ASMV_KEYWORD(
        READ_CNTP_TVAL_INSTR
        : [Rd]"=r"(cntp_tval)
    );
/*LDRA_ANALYSIS*/
    return cntp_tval;
}
#endif
#define BASENXP_STOP_SEC_CODE
#include "BaseNXP_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define BASENXP_START_SEC_CODE
#include "BaseNXP_MemMap.h"

void OsIf_Timer_System_Internal_Init(uint32 SystemCounterFreq)
{
    /* The value of this register is not interpreted by hardware. It is provided
       so that software can discover the frequency of the system counter */
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    /*accessing register in T32 mode from R52 core is not possible. To be check later. Implementation now is only done for AArch64*/
    write_CNTFRQ(SystemCounterFreq);
#endif
    write_CNTP_CTL(CNTP_CTL_IMASK_MASK & ~CNTP_CTL_ENABLE_EN);
    write_CNTP_TVAL(GENERICTIMER_TVAL_MAX);
}

/* OsIf_Timer_System_Internal_GetCounter_Activity */
uint32 OsIf_Timer_System_Internal_GetCounter(void)
{
    return GENERICTIMER_GET_COUNTER();
}

uint32 OsIf_Timer_System_Internal_GetElapsed(uint32 * const CurrentRef)
{
    uint32 CurrentVal = GENERICTIMER_GET_COUNTER();
    uint32 dif = 0u;

    if (GENERICTIMER_OVERFLOWED(CurrentVal, *CurrentRef))
    {
        /* Overflow occurred */
        dif = GENERICTIMER_DELTA_OUTER(CurrentVal, *CurrentRef, GENERICTIMER_TVAL_MAX);
    }
    else
    {
        /* Overflow did not occur */
        dif = GENERICTIMER_DELTA_INNER(*CurrentRef, CurrentVal);
    }

    *CurrentRef = CurrentVal;

    return dif;
}

#define BASENXP_STOP_SEC_CODE
#include "BaseNXP_MemMap.h"

#endif /* OSIF_USE_GENERICTIMER == STD_ON */
#endif /* defined(OSIF_USE_GENERICTIMER) */

#ifdef __cplusplus
}
#endif

/** @} */
