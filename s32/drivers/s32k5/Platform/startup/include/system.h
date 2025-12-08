/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*================================================================================================
*   @file    system.h
*   @version 0.8.0
*
*   @brief   AUTOSAR Platform - SYSTEM
*   @details SYSTEM
*            This file contains sample code only. It is not part of the production code deliverables.
*   @addtogroup PLATFORM
*   @{
*
==================================================================================================*/

#ifndef SYSTEM_H
#define SYSTEM_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"

#define Mode_USR  0x10U
#define Mode_FIQ  0x11U
#define Mode_IRQ  0x12U
#define Mode_SVC  0x13U
#define Mode_MNT  0x16U
#define Mode_ABT  0x17U
#define Mode_HYP  0x1AU
#define Mode_UND  0x1BU
#define Mode_SYS  0x1FU
#define Mode_THUMB  0x20U

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

void SystemInit(void);

/*
 * @brief Default IRQ handler
 * @param: None
 *
 * @return: None
 */

void default_interrupt_routine(void);

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
#ifdef MCAL_PLATFORM_ARM
#if (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH)
/*
 * @brief Switch to user mode and return the value passed by u32returnValue
 * @param: [in] u8SwitchToSupervisor - if 0, the function will return the value without switching to user mode,
 *                                     if 1, the function will go to user mode before returning the value
 * @param: [in] u32returnValue       - value to be returned
 *
 * @return: u32returnValue
 */
inline static __attribute__((always_inline)) uint32 Sys_GoToUser_Return(uint32 u32SwitchToSupervisor, uint32 u32returnValue)
{
    if (u32SwitchToSupervisor==1)
    {
        volatile uint32 cpsr_val =0;
        /*LDRA_NOANALYSIS*/
        ASMV_KEYWORD("mrs %0, cpsr\n" : "=r" (cpsr_val) );    /* get current cpsr */
        /*LDRA_ANALYSIS*/
        if ((cpsr_val & 0x1F) != Mode_USR)
        {
            ASM_KEYWORD(" svc 0x1");
        }
    }

    return u32returnValue;
}
/*
 * @brief Switch to supervisor mode
 * @param: None
 *
 * @return: operation result, 1 if switch was done, 0 if the CPU was already in supervisor mode or in handler mode
 */
inline static __attribute__((always_inline))  uint32 Sys_GoToSupervisor(void)

{

    volatile uint32 cpsr_val =0;
    volatile uint32 accepted_signal =0;
    /*LDRA_NOANALYSIS*/
    ASMV_KEYWORD("mrs %0, cpsr\n" : "=r" (cpsr_val) );    /* get current cpsr */
    /*LDRA_ANALYSIS*/
    if (((cpsr_val & 0x1F) != Mode_SVC) && ((cpsr_val & 0x1F) != Mode_SYS) && ((cpsr_val & 0x1F) != Mode_IRQ) && ((cpsr_val & 0x1F) != Mode_FIQ))
    {
        /*LDRA_NOANALYSIS*/
        ASMV_KEYWORD(" mov %0,#0x1\n" : "=r" (accepted_signal) ); /*move to value to scratch register indicate that request to priviledge mode is accepted from trusted sw*/
        /*LDRA_ANALYSIS*/
        ASM_KEYWORD(" svc 0x0");
    }
    else
    {
        /*LDRA_NOANALYSIS*/
       ASMV_KEYWORD(" mov %0,#0x0\n" : "=r" (accepted_signal) ); /*move to value to scratch register indicate that request to priviledge mode is not necessary */
        /*LDRA_ANALYSIS*/
    }
    return accepted_signal;
}
/*
 * @brief Switch to user mode
 * @param: None
 *
 * @return: 0
 */
inline static __attribute__((always_inline)) uint32 Sys_GoToUser(void)
{
    volatile uint32 cpsr_val =0;
    /*LDRA_NOANALYSIS*/
    ASMV_KEYWORD("mrs %0, cpsr\n" : "=r" (cpsr_val) );    /* get current cpsr */
    /*LDRA_ANALYSIS*/
    if ((cpsr_val & 0x1F) != Mode_USR)
    {
        ASM_KEYWORD(" svc 0x1");
    }

    return 0UL;
}
#else
/*
 * @brief Switch to user mode and return the value passed by u32returnValue
 * @param: [in] u8SwitchToSupervisor - if 0, the function will return the value without switching to user mode,
 *                                     if 1, the function will go to user mode before returning the value
 * @param: [in] u32returnValue       - value to be returned
 *
 * @return: u32returnValue
 */
uint32 Sys_GoToUser_Return(uint32 u32SwitchToSupervisor, uint32 u32returnValue);

/*
 * @brief Switch to supervisor mode
 * @param: None
 *
 * @return: operation result, 1 if switch was done, 0 if the CPU was already in supervisor mode or in handler mode
 */
uint32 Sys_GoToSupervisor(void);

/*
 * @brief Switch to user mode
 * @param: None
 *
 * @return: 0
 */
uint32 Sys_GoToUser(void);
#endif /* #if (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH) */

/*
 * @brief Sys_SuspendInterrupts
 * @param: None
 *
 * @return: none
 */
void Sys_SuspendInterrupts(void);
void Sys_ResumeInterrupts(void);
#endif /* #ifdef MCAL_PLATFORM_ARM */
#endif /* #ifdef MCAL_ENABLE_USER_MODE_SUPPORT */

/*
 * @brief Sys_EL1SuspendInterrupts
 * @param: None
 *
 * @return: none
 */
void Sys_EL1ResumeInterrupts(void);
void Sys_EL1SuspendInterrupts(void);

#ifdef MCAL_PLATFORM_ZENV
void Sys_SuspendInterrupts(void);
void Sys_ResumeInterrupts(void);
#endif /* #ifdef MCAL_PLATFORM_ZENV */

/*
 * @brief Get the hardware id of the currently executing core
 * @param: None
 *
 * @return: coreId
 */
uint8 Sys_GetCoreID(void);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_H */
