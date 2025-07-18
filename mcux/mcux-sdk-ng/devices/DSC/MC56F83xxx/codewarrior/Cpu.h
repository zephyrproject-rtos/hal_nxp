/*
 * Copyright 2019-2021 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* ###################################################################
**     Filename    : Cpu.h
**     Processor   : MC56F83xxx
**     Component   : MC56F83xxx
**     Version     : 0.1
**     Datasheet   : MC56F83xxx Reference Manual
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2019-09-12, 18:33
*/

#ifndef __Cpu_H
#define __Cpu_H

#ifdef SUPPORT_64BIT_DATA_TYPE
#pragma slld on
#endif

#include <stdint.h>

/* Explicit indicator for code stored in flash and executed from RAM mapping address in p space */
#pragma define_section CODES_IN_RAM "codesInRam.text" RX

/* Explicit indicator for variables stored in x(RAM) space and not initiated at startup */
#pragma define_section NONE_INIT_DATA "none_init.data" RW

/* Explicit indicator for const data stored in NVM flash and accessed from p(flash) space.
 * Note:
 *   To use this section, if nvm memory segment is located at p(flash)
 *     address > 64K, when code are compiled in LDM mode, please
 *     uncheck below setting in Codewarrior project properties:
 *     Project Properties -> C/C++ Build -> Settings -> Tool Settings ->
 *     DSC Compiler -> Processor -> Globals Live Lower Memory
 */
#pragma define_section NVM_DATA "nvm.data" RWX

/* Explicit indicator for const data stored in flash and accessed from p(flash) space.
 * Note:
 *   To use this section, if data located memory segment(p space)
 *     address > 64K, when code are compiled in LDM mode, please
 *     uncheck below setting in Codewarrior project properties:
 *     Project Properties -> C/C++ Build -> Settings -> Tool Settings ->
 *     DSC Compiler -> Processor -> Globals Live Lower Memory
 */
#define DATA_IN_PFLASH __pmem

/* Backward compatibility macro. In older SDK versions, the P-FLASH was primarily used */
#define DATA_IN_FLASH DATA_IN_PFLASH

#if (defined(__LDM__) || __has_feature(FE_POINTER_MODIFIERS))
/* Explicit indicator for const data put in flash and accessed from x(ram) space
 * Note:
 *   To use this section, since MC56F83xxx flash mapping address in x space is > 64K,
 *     when code are compiled in LDM mode, please uncheck below setting in
 *     Codewarrior project properties:
 *     Project Properties -> C/C++ Build -> Settings -> Tool Settings ->
 *     DSC Compiler -> Processor -> Globals Live Lower Memory
 */
#pragma define_section DATA_IN_XFLASH ".xflash.data" RW

/* User code may detect a support of the DATA_IN_XFLASH using #ifdef */
#define DATA_IN_XFLASH DATA_IN_XFLASH
#endif

/*
 * Example for use above sections:
 *
 * #pragma section CODES_IN_RAM begin
 * void fun(void)
 * {
 *     ...
 * }
 * #pragma section CODES_IN_RAM end
 *
 * #pragma section NONE_INIT_DATA begin
 * uint8_t Rxbuf[1024];
 * #pragma section NONE_INIT_DATA end
 *
 * #pragma section NVM_DATA begin
 * DATA_IN_FLASH uint8_t mapTable[1024] = {x, x, ...};
 * #pragma section NVM_DATA end
 *
 * #define XFLASH const __declspec(DATA_IN_XFLASH)
 * XFLASH uint16_t constValueInXFlash = 1;
 * XFLASH uint16_t constArrayInXFlash[10] = { 1, 2, ... };
 */

/* clang-format off */

#define __EI0()                 \
    do                          \
    {                           \
        asm {                   \
        .iasm_volatile on;      \
        bfclr #0x0300, SR;      \
        .iasm_volatile off;     \
        };                      \
    } while (0) /* Enable interrupts of level 0,1,2,3 */
#define __EI1()                 \
    do                          \
    {                           \
        asm {                   \
        .iasm_volatile on;      \
        bfset #0x0100, SR;      \
        bfclr #0x0200, SR;      \
        .iasm_volatile off;     \
        };                      \
    } while (0) /* Enable interrupts of level 1,2,3 */
#define __EI2()                 \
    do                          \
    {                           \
        asm {                   \
        .iasm_volatile on;      \
        bfset #0x0200, SR;      \
        bfclr #0x0100, SR;      \
        .iasm_volatile off;     \
        };                      \
    } while (0) /* Enable interrupts of level 2,3 */
#define __EI3()                 \
    do                          \
    {                           \
        asm {                   \
        .iasm_volatile on;      \
        bfset #0x0300, SR;      \
        .iasm_volatile off;     \
        };                      \
    } while (0) /* Enable interrupts of level 3 */

/* clang-format on */

/*lint -save  -esym(960,14.3) Disable MISRA rule (14.3) checking. */
#define __EI(level) __EI##level() /* Enable interrupts of the given level */
/*lint -restore  +esym(960,14.3) Enable MISRA rule (14.3) checking. */
#define __DI() __EI3() /* Disable interrupts, only level 3 is allowed */

#define Cpu_SetStopMode() asm(STOP) /* Set STOP mode */
#define __NOP()           asm(nop)
#define __DSB()           asm(nop)
#define __ISB()           asm(nop)
#define __WFI()           asm(WAIT)

/*
** ===================================================================
**     Method      :  Cpu_SetStopMode
**     Description :
**         Sets low power mode - Stop mode.
**         For more information about the stop mode see this CPU
**         documentation.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define Cpu_SetWaitMode() asm(WAIT) /* Set WAIT mode */
/*
** ===================================================================
**     Method      :  Cpu_SetWaitMode
**     Description :
**         Sets low power mode - Wait mode.
**         For more information about the wait mode see this CPU
**         documentation.
**         Release from wait mode: Reset or interrupt
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define Cpu_DisableInt() __DI() /* Disable interrupts */
/*
** ===================================================================
**     Method      :  Cpu_DisableInt
**     Description :
**         Disables all maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define Cpu_EnableInt() __EI(0) /* Enable interrupts */
/*
** ===================================================================
**     Method      :  Cpu_EnableInt
**     Description :
**         Enables all maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Cpu. */

#endif
/* __Cpu_H */
