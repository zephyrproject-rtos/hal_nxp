/******************************************************************************************
    MC56F84442 startup code, default ISR and vector table for use with DSC compiler

    Version : 200525
******************************************************************************************/

/******************************************************************************************
    Copyright 2016-2025 NXP

    SPDX-License-Identifier: BSD-3-Clause
******************************************************************************************/

#include "Cpu.h"
#include "fsl_device_registers.h"
#include "fsl_clock.h"

#ifndef _lint

extern void init_56800_(void); /* Forward declaration of external startup function declared in startup file */

void Cpu_Interrupt(void);
#pragma interrupt alignsp saveall
void Cpu_Interrupt(void)
{
    asm(DEBUGHLT);
    /* Halt the core and placing it in the debug processing state. */
    /* Here should be two NOPs if DEBUGHLT is removed.
    asm(nop);
    asm(nop); */
}
#pragma interrupt off

static void default_interrupt(void)
{
    asm(DEBUGHLT);
    /* Halt the core and placing it in the debug processing state. */
    /* Here should be two NOPs if DEBUGHLT is removed.
    asm(nop);
    asm(nop); */
}

/*
 * CAUTION: _EntryPoint is called out of reset, .data, .bss, stack are not initiated
 * at this point, be careful to add/modify code in _EntryPoint. Say
 * 1. Don't call other functions,
 * 2. Don't use global or local variables.
 * 3. ...
 */
void _EntryPoint(void);
void _EntryPoint(void)
{
/* Disable constant to array reallocation compiler optimization before RAM is filled in startup */
#pragma constarray off

    COP->CTRL &= ~COP_CTRL_CEN_MASK; /* Disable COP */
    __DI();                          /* Disable interrupts of level 0,1,2 */

    /* PMC trim */
    PMC->CTRL &= ~PMC_CTRL_TRIM_MASK;
    PMC->CTRL |= SIM->NVMOPT2L & SIM_NVMOPT2L_PMC_BGTRIM_MASK;

    /* load factory trimming value of the internal relaxation oscillator */
    OCCS->OSCTL1 &= ~OCCS_OSCTL1_FREQ_TRIM8M_MASK;
    OCCS->OSCTL1 |= SIM->NVMOPT2H & SIM_NVMOPT2H_ROSC_8M_FTRIM_MASK;

    OCCS->OSCTL2 &= ~(OCCS_OSCTL2_FREQ_TRIM32K_MASK | OCCS_OSCTL2_TEMP_TRIM8M_MASK);
    OCCS->OSCTL2 |=
        (SIM->NVMOPT2H & SIM_NVMOPT2H_ROSC_8M_TTRIM_MASK) | (SIM->NVMOPT2L & SIM_NVMOPT2L_ROSC_32K_FTRIM_MASK);

    /* PLL is not enabled by default */
#if 0
    /* use internal 8M clock for PLL */
    OCCS->OSCTL1 &= ~(OCCS_OSCTL1_ROPD_MASK | OCCS_OSCTL1_ROSB_MASK); /* Enable internal 8M RC */
    OCCS->CTRL &= ~OCCS_CTRL_PRECS_MASK; /* Select internal 8M/400K RC OSC as MSTR_OSC */
    asm(NOP);
    asm(NOP);
    asm(NOP);
    asm(NOP);
    asm(NOP);
    asm(NOP);
    /* Output of PLL is SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY * 4, postscaler = 1 */
    OCCS->DIVBY = 0x2000U + (SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY*4UL/8000000UL-1U);
    OCCS->CTRL &= ~OCCS_CTRL_PLLPD_MASK; /* Power up PLL */
    OCCS->CTRL |= OCCS_CTRL_LCKON_MASK;  /* Enable LCKON */
    while ((OCCS->STAT & OCCS_STAT_LCK0_MASK) == 0) {}
    while ((OCCS->STAT & OCCS_STAT_LCK1_MASK) == 0) {}
    OCCS->CTRL |= OCCS_CTRL_ZSRC_MASK; /* Select PLL/2 as sys_clk_x2 to SIM */
    while((OCCS->STAT & OCCS_STAT_ZSRCS_MASK) != OCCS_STAT_ZSRCS(1U)) {}
#endif

    asm {
    swap shadows
    nop
    nop
    move.l #0, R0
    move.l #0, R1
    move.l #0, R2
    move.l #0, R3
    move.l #0, R4
    move.l #0, R5
    move.l #0, N
    moveu.w #65535, N3
    moveu.w #65535, M01
    nop
    nop
    swap shadows
    }

    asm(JMP init_56800_);
    /* Jump to C startup code */
}

/******************* Default ISR for ILLEGAL_OP **********************/

/* User could redefine ivINT_ILLEGAL_OP.
Please be noted that ivINT_ILLEGAL_OP can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_ILLEGAL_OP definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_ILLEGAL_OP(void);
__attribute__((weak)) void ivINT_ILLEGAL_OP(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for SWI3 **********************/

/* User could redefine ivINT_SWI3.
Please be noted that ivINT_SWI3 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_SWI3 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_SWI3(void);
__attribute__((weak)) void ivINT_SWI3(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for OVERFLOW **********************/

/* User could redefine ivINT_OVERFLOW.
Please be noted that ivINT_OVERFLOW can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_OVERFLOW definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_OVERFLOW(void);
__attribute__((weak)) void ivINT_OVERFLOW(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for MISALIGNED **********************/

/* User could redefine ivINT_MISALIGNED.
Please be noted that ivINT_MISALIGNED can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_MISALIGNED definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_MISALIGNED(void);
__attribute__((weak)) void ivINT_MISALIGNED(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for STPCNT **********************/

/* User could redefine ivINT_STPCNT.
Please be noted that ivINT_STPCNT can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_STPCNT definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_STPCNT(void);
__attribute__((weak)) void ivINT_STPCNT(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for BKPT **********************/

/* User could redefine ivINT_BKPT.
Please be noted that ivINT_BKPT can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_BKPT definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_BKPT(void);
__attribute__((weak)) void ivINT_BKPT(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for TRBUF **********************/

/* User could redefine ivINT_TRBUF.
Please be noted that ivINT_TRBUF can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_TRBUF definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_TRBUF(void);
__attribute__((weak)) void ivINT_TRBUF(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for TX_REG **********************/

/* User could redefine ivINT_TX_REG.
Please be noted that ivINT_TX_REG can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_TX_REG definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_TX_REG(void);
__attribute__((weak)) void ivINT_TX_REG(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for RX_REG **********************/

/* User could redefine ivINT_RX_REG.
Please be noted that ivINT_RX_REG can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_RX_REG definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_RX_REG(void);
__attribute__((weak)) void ivINT_RX_REG(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for BUS_ERR **********************/

/* User could redefine ivINT_BUS_ERR.
Please be noted that ivINT_BUS_ERR can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_BUS_ERR definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_BUS_ERR(void);
__attribute__((weak)) void ivINT_BUS_ERR(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for SWI2 **********************/

/* User could redefine ivINT_SWI2.
Please be noted that ivINT_SWI2 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_SWI2 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_SWI2(void);
__attribute__((weak)) void ivINT_SWI2(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for SWI1 **********************/

/* User could redefine ivINT_SWI1.
Please be noted that ivINT_SWI1 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_SWI1 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_SWI1(void);
__attribute__((weak)) void ivINT_SWI1(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for SWI0 **********************/

/* User could redefine ivINT_SWI0.
Please be noted that ivINT_SWI0 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_SWI0 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_SWI0(void);
__attribute__((weak)) void ivINT_SWI0(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for XBARA **********************/

/* User could redefine ivINT_XBARA.
Please be noted that ivINT_XBARA can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_XBARA definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_XBARA(void);
__attribute__((weak)) void ivINT_XBARA(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for LVI1 **********************/

/* User could redefine ivINT_LVI1.
Please be noted that ivINT_LVI1 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_LVI1 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_LVI1(void);
__attribute__((weak)) void ivINT_LVI1(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for OCCS **********************/

/* User could redefine ivINT_OCCS.
Please be noted that ivINT_OCCS can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_OCCS definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_OCCS(void);
__attribute__((weak)) void ivINT_OCCS(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for TMRB_3 **********************/

/* User could redefine ivINT_TMRB_3.
Please be noted that ivINT_TMRB_3 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_TMRB_3 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_TMRB_3(void);
__attribute__((weak)) void ivINT_TMRB_3(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for TMRB_2 **********************/

/* User could redefine ivINT_TMRB_2.
Please be noted that ivINT_TMRB_2 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_TMRB_2 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_TMRB_2(void);
__attribute__((weak)) void ivINT_TMRB_2(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for TMRB_1 **********************/

/* User could redefine ivINT_TMRB_1.
Please be noted that ivINT_TMRB_1 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_TMRB_1 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_TMRB_1(void);
__attribute__((weak)) void ivINT_TMRB_1(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for TMRB_0 **********************/

/* User could redefine ivINT_TMRB_0.
Please be noted that ivINT_TMRB_0 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_TMRB_0 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_TMRB_0(void);
__attribute__((weak)) void ivINT_TMRB_0(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for TMRA_3 **********************/

/* User could redefine ivINT_TMRA_3.
Please be noted that ivINT_TMRA_3 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_TMRA_3 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_TMRA_3(void);
__attribute__((weak)) void ivINT_TMRA_3(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for TMRA_2 **********************/

/* User could redefine ivINT_TMRA_2.
Please be noted that ivINT_TMRA_2 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_TMRA_2 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_TMRA_2(void);
__attribute__((weak)) void ivINT_TMRA_2(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for TMRA_1 **********************/

/* User could redefine ivINT_TMRA_1.
Please be noted that ivINT_TMRA_1 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_TMRA_1 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_TMRA_1(void);
__attribute__((weak)) void ivINT_TMRA_1(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for TMRA_0 **********************/

/* User could redefine ivINT_TMRA_0.
Please be noted that ivINT_TMRA_0 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_TMRA_0 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_TMRA_0(void);
__attribute__((weak)) void ivINT_TMRA_0(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for ADC_CC1 **********************/

/* User could redefine ivINT_ADC_CC1.
Please be noted that ivINT_ADC_CC1 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_ADC_CC1 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_ADC_CC1(void);
__attribute__((weak)) void ivINT_ADC_CC1(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for ADC_CC0 **********************/

/* User could redefine ivINT_ADC_CC0.
Please be noted that ivINT_ADC_CC0 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_ADC_CC0 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_ADC_CC0(void);
__attribute__((weak)) void ivINT_ADC_CC0(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for ADC_ERR **********************/

/* User could redefine ivINT_ADC_ERR.
Please be noted that ivINT_ADC_ERR can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_ADC_ERR definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_ADC_ERR(void);
__attribute__((weak)) void ivINT_ADC_ERR(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for COCO **********************/

/* User could redefine ivINT_COCO.
Please be noted that ivINT_COCO can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_COCO definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_COCO(void);
__attribute__((weak)) void ivINT_COCO(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for DMA3 **********************/
/* Double weak ISR mechanism for DMA3 to facilitate SDK usage. */

/* User could redefine the DMA3_DriverIRQHandler as normal function to implement their own ISR. */
__attribute__((weak)) static void DMA3_DriverIRQHandler(void)
{
    default_interrupt();
}

/* User could redefine ivINT_DMA3.
Please be noted that ivINT_DMA3 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_DMA3 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_DMA3(void);
__attribute__((weak)) void ivINT_DMA3(void)
{
    DMA3_DriverIRQHandler();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for DMA2 **********************/
/* Double weak ISR mechanism for DMA2 to facilitate SDK usage. */

/* User could redefine the DMA2_DriverIRQHandler as normal function to implement their own ISR. */
__attribute__((weak)) static void DMA2_DriverIRQHandler(void)
{
    default_interrupt();
}

/* User could redefine ivINT_DMA2.
Please be noted that ivINT_DMA2 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_DMA2 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_DMA2(void);
__attribute__((weak)) void ivINT_DMA2(void)
{
    DMA2_DriverIRQHandler();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for DMA1 **********************/
/* Double weak ISR mechanism for DMA1 to facilitate SDK usage. */

/* User could redefine the DMA1_DriverIRQHandler as normal function to implement their own ISR. */
__attribute__((weak)) static void DMA1_DriverIRQHandler(void)
{
    default_interrupt();
}

/* User could redefine ivINT_DMA1.
Please be noted that ivINT_DMA1 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_DMA1 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_DMA1(void);
__attribute__((weak)) void ivINT_DMA1(void)
{
    DMA1_DriverIRQHandler();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for DMA0 **********************/
/* Double weak ISR mechanism for DMA0 to facilitate SDK usage. */

/* User could redefine the DMA0_DriverIRQHandler as normal function to implement their own ISR. */
__attribute__((weak)) static void DMA0_DriverIRQHandler(void)
{
    default_interrupt();
}

/* User could redefine ivINT_DMA0.
Please be noted that ivINT_DMA0 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_DMA0 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_DMA0(void);
__attribute__((weak)) void ivINT_DMA0(void)
{
    DMA0_DriverIRQHandler();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for QSCI1_RERR **********************/
/* Double weak ISR mechanism for QSCI1_RERR to facilitate SDK usage. */

/* User could redefine the QSCI1_RERR_DriverIRQHandler as normal function to implement their own ISR. */
__attribute__((weak)) static void QSCI1_RERR_DriverIRQHandler(void)
{
    default_interrupt();
}

/* User could redefine ivINT_QSCI1_RERR.
Please be noted that ivINT_QSCI1_RERR can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_QSCI1_RERR definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_QSCI1_RERR(void);
__attribute__((weak)) void ivINT_QSCI1_RERR(void)
{
    QSCI1_RERR_DriverIRQHandler();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for QSCI1_RCV **********************/
/* Double weak ISR mechanism for QSCI1_RCV to facilitate SDK usage. */

/* User could redefine the QSCI1_RCV_DriverIRQHandler as normal function to implement their own ISR. */
__attribute__((weak)) static void QSCI1_RCV_DriverIRQHandler(void)
{
    default_interrupt();
}

/* User could redefine ivINT_QSCI1_RCV.
Please be noted that ivINT_QSCI1_RCV can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_QSCI1_RCV definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_QSCI1_RCV(void);
__attribute__((weak)) void ivINT_QSCI1_RCV(void)
{
    QSCI1_RCV_DriverIRQHandler();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for QSCI1_TIDLE **********************/
/* Double weak ISR mechanism for QSCI1_TIDLE to facilitate SDK usage. */

/* User could redefine the QSCI1_TIDLE_DriverIRQHandler as normal function to implement their own ISR. */
__attribute__((weak)) static void QSCI1_TIDLE_DriverIRQHandler(void)
{
    default_interrupt();
}

/* User could redefine ivINT_QSCI1_TIDLE.
Please be noted that ivINT_QSCI1_TIDLE can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_QSCI1_TIDLE definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_QSCI1_TIDLE(void);
__attribute__((weak)) void ivINT_QSCI1_TIDLE(void)
{
    QSCI1_TIDLE_DriverIRQHandler();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for QSCI1_TDRE **********************/
/* Double weak ISR mechanism for QSCI1_TDRE to facilitate SDK usage. */

/* User could redefine the QSCI1_TDRE_DriverIRQHandler as normal function to implement their own ISR. */
__attribute__((weak)) static void QSCI1_TDRE_DriverIRQHandler(void)
{
    default_interrupt();
}

/* User could redefine ivINT_QSCI1_TDRE.
Please be noted that ivINT_QSCI1_TDRE can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_QSCI1_TDRE definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_QSCI1_TDRE(void);
__attribute__((weak)) void ivINT_QSCI1_TDRE(void)
{
    QSCI1_TDRE_DriverIRQHandler();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for QSCI0_RERR **********************/
/* Double weak ISR mechanism for QSCI0_RERR to facilitate SDK usage. */

/* User could redefine the QSCI0_RERR_DriverIRQHandler as normal function to implement their own ISR. */
__attribute__((weak)) static void QSCI0_RERR_DriverIRQHandler(void)
{
    default_interrupt();
}

/* User could redefine ivINT_QSCI0_RERR.
Please be noted that ivINT_QSCI0_RERR can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_QSCI0_RERR definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_QSCI0_RERR(void);
__attribute__((weak)) void ivINT_QSCI0_RERR(void)
{
    QSCI0_RERR_DriverIRQHandler();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for QSCI0_RCV **********************/
/* Double weak ISR mechanism for QSCI0_RCV to facilitate SDK usage. */

/* User could redefine the QSCI0_RCV_DriverIRQHandler as normal function to implement their own ISR. */
__attribute__((weak)) static void QSCI0_RCV_DriverIRQHandler(void)
{
    default_interrupt();
}

/* User could redefine ivINT_QSCI0_RCV.
Please be noted that ivINT_QSCI0_RCV can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_QSCI0_RCV definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_QSCI0_RCV(void);
__attribute__((weak)) void ivINT_QSCI0_RCV(void)
{
    QSCI0_RCV_DriverIRQHandler();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for QSCI0_TIDLE **********************/
/* Double weak ISR mechanism for QSCI0_TIDLE to facilitate SDK usage. */

/* User could redefine the QSCI0_TIDLE_DriverIRQHandler as normal function to implement their own ISR. */
__attribute__((weak)) static void QSCI0_TIDLE_DriverIRQHandler(void)
{
    default_interrupt();
}

/* User could redefine ivINT_QSCI0_TIDLE.
Please be noted that ivINT_QSCI0_TIDLE can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_QSCI0_TIDLE definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_QSCI0_TIDLE(void);
__attribute__((weak)) void ivINT_QSCI0_TIDLE(void)
{
    QSCI0_TIDLE_DriverIRQHandler();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for QSCI0_TDRE **********************/
/* Double weak ISR mechanism for QSCI0_TDRE to facilitate SDK usage. */

/* User could redefine the QSCI0_TDRE_DriverIRQHandler as normal function to implement their own ISR. */
__attribute__((weak)) static void QSCI0_TDRE_DriverIRQHandler(void)
{
    default_interrupt();
}

/* User could redefine ivINT_QSCI0_TDRE.
Please be noted that ivINT_QSCI0_TDRE can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_QSCI0_TDRE definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_QSCI0_TDRE(void);
__attribute__((weak)) void ivINT_QSCI0_TDRE(void)
{
    QSCI0_TDRE_DriverIRQHandler();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for QSPI0_XMIT **********************/
/* Double weak ISR mechanism for QSPI0_XMIT to facilitate SDK usage. */

/* User could redefine the QSPI0_XMIT_DriverIRQHandler as normal function to implement their own ISR. */
__attribute__((weak)) static void QSPI0_XMIT_DriverIRQHandler(void)
{
    default_interrupt();
}

/* User could redefine ivINT_QSPI0_XMIT.
Please be noted that ivINT_QSPI0_XMIT can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_QSPI0_XMIT definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_QSPI0_XMIT(void);
__attribute__((weak)) void ivINT_QSPI0_XMIT(void)
{
    QSPI0_XMIT_DriverIRQHandler();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for QSPI0_RCV **********************/
/* Double weak ISR mechanism for QSPI0_RCV to facilitate SDK usage. */

/* User could redefine the QSPI0_RCV_DriverIRQHandler as normal function to implement their own ISR. */
__attribute__((weak)) static void QSPI0_RCV_DriverIRQHandler(void)
{
    default_interrupt();
}

/* User could redefine ivINT_QSPI0_RCV.
Please be noted that ivINT_QSPI0_RCV can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_QSPI0_RCV definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_QSPI0_RCV(void);
__attribute__((weak)) void ivINT_QSPI0_RCV(void)
{
    QSPI0_RCV_DriverIRQHandler();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for I2C1 **********************/
/* Double weak ISR mechanism for I2C1 to facilitate SDK usage. */

/* User could redefine the I2C1_DriverIRQHandler as normal function to implement their own ISR. */
__attribute__((weak)) static void I2C1_DriverIRQHandler(void)
{
    default_interrupt();
}

/* User could redefine ivINT_I2C1.
Please be noted that ivINT_I2C1 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_I2C1 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_I2C1(void);
__attribute__((weak)) void ivINT_I2C1(void)
{
    I2C1_DriverIRQHandler();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for I2C0 **********************/
/* Double weak ISR mechanism for I2C0 to facilitate SDK usage. */

/* User could redefine the I2C0_DriverIRQHandler as normal function to implement their own ISR. */
__attribute__((weak)) static void I2C0_DriverIRQHandler(void)
{
    default_interrupt();
}

/* User could redefine ivINT_I2C0.
Please be noted that ivINT_I2C0 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_I2C0 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_I2C0(void);
__attribute__((weak)) void ivINT_I2C0(void)
{
    I2C0_DriverIRQHandler();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for eFlexPWMA_FAULT **********************/

/* User could redefine ivINT_eFlexPWMA_FAULT.
Please be noted that ivINT_eFlexPWMA_FAULT can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_eFlexPWMA_FAULT definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_eFlexPWMA_FAULT(void);
__attribute__((weak)) void ivINT_eFlexPWMA_FAULT(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for eFlexPWMA_RERR **********************/

/* User could redefine ivINT_eFlexPWMA_RERR.
Please be noted that ivINT_eFlexPWMA_RERR can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_eFlexPWMA_RERR definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_eFlexPWMA_RERR(void);
__attribute__((weak)) void ivINT_eFlexPWMA_RERR(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for eFlexPWMA_RELOAD3 **********************/

/* User could redefine ivINT_eFlexPWMA_RELOAD3.
Please be noted that ivINT_eFlexPWMA_RELOAD3 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_eFlexPWMA_RELOAD3 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_eFlexPWMA_RELOAD3(void);
__attribute__((weak)) void ivINT_eFlexPWMA_RELOAD3(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for eFlexPWMA_CAP **********************/

/* User could redefine ivINT_eFlexPWMA_CAP.
Please be noted that ivINT_eFlexPWMA_CAP can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_eFlexPWMA_CAP definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_eFlexPWMA_CAP(void);
__attribute__((weak)) void ivINT_eFlexPWMA_CAP(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for eFlexPWMA_CMP3 **********************/

/* User could redefine ivINT_eFlexPWMA_CMP3.
Please be noted that ivINT_eFlexPWMA_CMP3 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_eFlexPWMA_CMP3 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_eFlexPWMA_CMP3(void);
__attribute__((weak)) void ivINT_eFlexPWMA_CMP3(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for eFlexPWMA_RELOAD2 **********************/

/* User could redefine ivINT_eFlexPWMA_RELOAD2.
Please be noted that ivINT_eFlexPWMA_RELOAD2 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_eFlexPWMA_RELOAD2 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_eFlexPWMA_RELOAD2(void);
__attribute__((weak)) void ivINT_eFlexPWMA_RELOAD2(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for eFlexPWMA_CMP2 **********************/

/* User could redefine ivINT_eFlexPWMA_CMP2.
Please be noted that ivINT_eFlexPWMA_CMP2 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_eFlexPWMA_CMP2 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_eFlexPWMA_CMP2(void);
__attribute__((weak)) void ivINT_eFlexPWMA_CMP2(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for eFlexPWMA_RELOAD1 **********************/

/* User could redefine ivINT_eFlexPWMA_RELOAD1.
Please be noted that ivINT_eFlexPWMA_RELOAD1 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_eFlexPWMA_RELOAD1 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_eFlexPWMA_RELOAD1(void);
__attribute__((weak)) void ivINT_eFlexPWMA_RELOAD1(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for eFlexPWMA_CMP1 **********************/

/* User could redefine ivINT_eFlexPWMA_CMP1.
Please be noted that ivINT_eFlexPWMA_CMP1 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_eFlexPWMA_CMP1 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_eFlexPWMA_CMP1(void);
__attribute__((weak)) void ivINT_eFlexPWMA_CMP1(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for eFlexPWMA_RELOAD0 **********************/

/* User could redefine ivINT_eFlexPWMA_RELOAD0.
Please be noted that ivINT_eFlexPWMA_RELOAD0 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_eFlexPWMA_RELOAD0 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_eFlexPWMA_RELOAD0(void);
__attribute__((weak)) void ivINT_eFlexPWMA_RELOAD0(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for eFlexPWMA_CMP0 **********************/

/* User could redefine ivINT_eFlexPWMA_CMP0.
Please be noted that ivINT_eFlexPWMA_CMP0 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_eFlexPWMA_CMP0 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_eFlexPWMA_CMP0(void);
__attribute__((weak)) void ivINT_eFlexPWMA_CMP0(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for FTFL_RDCOL **********************/

/* User could redefine ivINT_FTFL_RDCOL.
Please be noted that ivINT_FTFL_RDCOL can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_FTFL_RDCOL definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_FTFL_RDCOL(void);
__attribute__((weak)) void ivINT_FTFL_RDCOL(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for FTFL_CC **********************/

/* User could redefine ivINT_FTFL_CC.
Please be noted that ivINT_FTFL_CC can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_FTFL_CC definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_FTFL_CC(void);
__attribute__((weak)) void ivINT_FTFL_CC(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for CMPD **********************/

/* User could redefine ivINT_CMPD.
Please be noted that ivINT_CMPD can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_CMPD definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_CMPD(void);
__attribute__((weak)) void ivINT_CMPD(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for CMPC **********************/

/* User could redefine ivINT_CMPC.
Please be noted that ivINT_CMPC can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_CMPC definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_CMPC(void);
__attribute__((weak)) void ivINT_CMPC(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for CMPB **********************/

/* User could redefine ivINT_CMPB.
Please be noted that ivINT_CMPB can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_CMPB definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_CMPB(void);
__attribute__((weak)) void ivINT_CMPB(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for CMPA **********************/

/* User could redefine ivINT_CMPA.
Please be noted that ivINT_CMPA can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_CMPA definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_CMPA(void);
__attribute__((weak)) void ivINT_CMPA(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for PIT1_ROLLOVR **********************/

/* User could redefine ivINT_PIT1_ROLLOVR.
Please be noted that ivINT_PIT1_ROLLOVR can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_PIT1_ROLLOVR definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_PIT1_ROLLOVR(void);
__attribute__((weak)) void ivINT_PIT1_ROLLOVR(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for PIT0_ROLLOVR **********************/

/* User could redefine ivINT_PIT0_ROLLOVR.
Please be noted that ivINT_PIT0_ROLLOVR can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_PIT0_ROLLOVR definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_PIT0_ROLLOVR(void);
__attribute__((weak)) void ivINT_PIT0_ROLLOVR(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for PDB1 **********************/

/* User could redefine ivINT_PDB1.
Please be noted that ivINT_PDB1 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_PDB1 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_PDB1(void);
__attribute__((weak)) void ivINT_PDB1(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for PDB0 **********************/

/* User could redefine ivINT_PDB0.
Please be noted that ivINT_PDB0 can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_PDB0 definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_PDB0(void);
__attribute__((weak)) void ivINT_PDB0(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for QDC_INDEX_RO_RU **********************/

/* User could redefine ivINT_QDC_INDEX_RO_RU.
Please be noted that ivINT_QDC_INDEX_RO_RU can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_QDC_INDEX_RO_RU definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_QDC_INDEX_RO_RU(void);
__attribute__((weak)) void ivINT_QDC_INDEX_RO_RU(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for QDC_HOME_DOG **********************/

/* User could redefine ivINT_QDC_HOME_DOG.
Please be noted that ivINT_QDC_HOME_DOG can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_QDC_HOME_DOG definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_QDC_HOME_DOG(void);
__attribute__((weak)) void ivINT_QDC_HOME_DOG(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for QDC_COMPARE **********************/

/* User could redefine ivINT_QDC_COMPARE.
Please be noted that ivINT_QDC_COMPARE can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_QDC_COMPARE definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_QDC_COMPARE(void);
__attribute__((weak)) void ivINT_QDC_COMPARE(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for GPIOG **********************/

/* User could redefine ivINT_GPIOG.
Please be noted that ivINT_GPIOG can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_GPIOG definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_GPIOG(void);
__attribute__((weak)) void ivINT_GPIOG(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for GPIOF **********************/

/* User could redefine ivINT_GPIOF.
Please be noted that ivINT_GPIOF can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_GPIOF definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_GPIOF(void);
__attribute__((weak)) void ivINT_GPIOF(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for GPIOE **********************/

/* User could redefine ivINT_GPIOE.
Please be noted that ivINT_GPIOE can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_GPIOE definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_GPIOE(void);
__attribute__((weak)) void ivINT_GPIOE(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for GPIOD **********************/

/* User could redefine ivINT_GPIOD.
Please be noted that ivINT_GPIOD can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_GPIOD definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_GPIOD(void);
__attribute__((weak)) void ivINT_GPIOD(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for GPIOC **********************/

/* User could redefine ivINT_GPIOC.
Please be noted that ivINT_GPIOC can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_GPIOC definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_GPIOC(void);
__attribute__((weak)) void ivINT_GPIOC(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for GPIOB **********************/

/* User could redefine ivINT_GPIOB.
Please be noted that ivINT_GPIOB can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_GPIOB definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_GPIOB(void);
__attribute__((weak)) void ivINT_GPIOB(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for GPIOA **********************/

/* User could redefine ivINT_GPIOA.
Please be noted that ivINT_GPIOA can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_GPIOA definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_GPIOA(void);
__attribute__((weak)) void ivINT_GPIOA(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for COP_INT **********************/

/* User could redefine ivINT_COP_INT.
Please be noted that ivINT_COP_INT can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_COP_INT definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_COP_INT(void);
__attribute__((weak)) void ivINT_COP_INT(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for EWM_INT **********************/

/* User could redefine ivINT_EWM_INT.
Please be noted that ivINT_EWM_INT can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_EWM_INT definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_EWM_INT(void);
__attribute__((weak)) void ivINT_EWM_INT(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/******************* Default ISR for SWILP **********************/

/* User could redefine ivINT_SWILP.
Please be noted that ivINT_SWILP can't be defined as normal function,
it should be protected by #pragma interrupt xxx, refer to below ivINT_SWILP definition. */
#pragma interrupt alignsp saveall
__attribute__((weak)) void ivINT_SWILP(void);
__attribute__((weak)) void ivINT_SWILP(void)
{
    default_interrupt();
}
#pragma interrupt off
/********************************************************************/

/* clang-format off */

volatile asm void _vect(void);
#pragma define_section interrupt_vectors "interrupt_vectors.text" RX
#pragma section interrupt_vectors begin
volatile asm void _vect(void) {
    JMP >_EntryPoint              /* Interrupt no. 0 (Used)*/
    JMP >_EntryPoint              /* Interrupt no. 1 (Used)*/
    JSR >ivINT_ILLEGAL_OP         /* Interrupt no. 2*/
    JSR >ivINT_SWI3               /* Interrupt no. 3*/
    JSR >ivINT_OVERFLOW           /* Interrupt no. 4*/
    JSR >ivINT_MISALIGNED         /* Interrupt no. 5*/
    JSR >ivINT_STPCNT             /* Interrupt no. 6*/
    JSR >ivINT_BKPT               /* Interrupt no. 7*/
    JSR >ivINT_TRBUF              /* Interrupt no. 8*/
    JSR >ivINT_TX_REG             /* Interrupt no. 9*/
    JSR >ivINT_RX_REG             /* Interrupt no. 10*/
    JSR >ivINT_BUS_ERR            /* Interrupt no. 11*/
    JSR >Cpu_Interrupt            /* Interrupt no. 12*/
    JSR >Cpu_Interrupt            /* Interrupt no. 13*/
    JSR >Cpu_Interrupt            /* Interrupt no. 14*/
    JSR >ivINT_SWI2               /* Interrupt no. 15*/
    JSR >ivINT_SWI1               /* Interrupt no. 16*/
    JSR >ivINT_SWI0               /* Interrupt no. 17*/
    JSR >ivINT_XBARA              /* Interrupt no. 18*/
    JSR >ivINT_LVI1               /* Interrupt no. 19*/
    JSR >ivINT_OCCS               /* Interrupt no. 20*/
    JSR >ivINT_TMRB_3             /* Interrupt no. 21*/
    JSR >ivINT_TMRB_2             /* Interrupt no. 22*/
    JSR >ivINT_TMRB_1             /* Interrupt no. 23*/
    JSR >ivINT_TMRB_0             /* Interrupt no. 24*/
    JSR >ivINT_TMRA_3             /* Interrupt no. 25*/
    JSR >ivINT_TMRA_2             /* Interrupt no. 26*/
    JSR >ivINT_TMRA_1             /* Interrupt no. 27*/
    JSR >ivINT_TMRA_0             /* Interrupt no. 28*/
    JSR >ivINT_ADC_CC1            /* Interrupt no. 29*/
    JSR >ivINT_ADC_CC0            /* Interrupt no. 30*/
    JSR >ivINT_ADC_ERR            /* Interrupt no. 31*/
    JSR >ivINT_COCO               /* Interrupt no. 32*/
    JSR >ivINT_DMA3               /* Interrupt no. 33*/
    JSR >ivINT_DMA2               /* Interrupt no. 34*/
    JSR >ivINT_DMA1               /* Interrupt no. 35*/
    JSR >ivINT_DMA0               /* Interrupt no. 36*/
    JSR >Cpu_Interrupt            /* Interrupt no. 37*/
    JSR >Cpu_Interrupt            /* Interrupt no. 38*/
    JSR >Cpu_Interrupt            /* Interrupt no. 39*/
    JSR >Cpu_Interrupt            /* Interrupt no. 40*/
    JSR >Cpu_Interrupt            /* Interrupt no. 41*/
    JSR >Cpu_Interrupt            /* Interrupt no. 42*/
    JSR >Cpu_Interrupt            /* Interrupt no. 43*/
    JSR >Cpu_Interrupt            /* Interrupt no. 44*/
    JSR >Cpu_Interrupt            /* Interrupt no. 45*/
    JSR >Cpu_Interrupt            /* Interrupt no. 46*/
    JSR >ivINT_QSCI1_RERR         /* Interrupt no. 47*/
    JSR >ivINT_QSCI1_RCV          /* Interrupt no. 48*/
    JSR >ivINT_QSCI1_TIDLE        /* Interrupt no. 49*/
    JSR >ivINT_QSCI1_TDRE         /* Interrupt no. 50*/
    JSR >ivINT_QSCI0_RERR         /* Interrupt no. 51*/
    JSR >ivINT_QSCI0_RCV          /* Interrupt no. 52*/
    JSR >ivINT_QSCI0_TIDLE        /* Interrupt no. 53*/
    JSR >ivINT_QSCI0_TDRE         /* Interrupt no. 54*/
    JSR >Cpu_Interrupt            /* Interrupt no. 55*/
    JSR >Cpu_Interrupt            /* Interrupt no. 56*/
    JSR >Cpu_Interrupt            /* Interrupt no. 57*/
    JSR >Cpu_Interrupt            /* Interrupt no. 58*/
    JSR >ivINT_QSPI0_XMIT         /* Interrupt no. 59*/
    JSR >ivINT_QSPI0_RCV          /* Interrupt no. 60*/
    JSR >ivINT_I2C1               /* Interrupt no. 61*/
    JSR >ivINT_I2C0               /* Interrupt no. 62*/
    JSR >Cpu_Interrupt            /* Interrupt no. 63*/
    JSR >Cpu_Interrupt            /* Interrupt no. 64*/
    JSR >Cpu_Interrupt            /* Interrupt no. 65*/
    JSR >Cpu_Interrupt            /* Interrupt no. 66*/
    JSR >Cpu_Interrupt            /* Interrupt no. 67*/
    JSR >Cpu_Interrupt            /* Interrupt no. 68*/
    JSR >Cpu_Interrupt            /* Interrupt no. 69*/
    JSR >Cpu_Interrupt            /* Interrupt no. 70*/
    JSR >Cpu_Interrupt            /* Interrupt no. 71*/
    JSR >Cpu_Interrupt            /* Interrupt no. 72*/
    JSR >Cpu_Interrupt            /* Interrupt no. 73*/
    JSR >Cpu_Interrupt            /* Interrupt no. 74*/
    JSR >Cpu_Interrupt            /* Interrupt no. 75*/
    JSR >Cpu_Interrupt            /* Interrupt no. 76*/
    JSR >ivINT_eFlexPWMA_FAULT    /* Interrupt no. 77*/
    JSR >ivINT_eFlexPWMA_RERR     /* Interrupt no. 78*/
    JSR >ivINT_eFlexPWMA_RELOAD3  /* Interrupt no. 79*/
    JSR >ivINT_eFlexPWMA_CAP      /* Interrupt no. 80*/
    JSR >ivINT_eFlexPWMA_CMP3     /* Interrupt no. 81*/
    JSR >ivINT_eFlexPWMA_RELOAD2  /* Interrupt no. 82*/
    JSR >ivINT_eFlexPWMA_CMP2     /* Interrupt no. 83*/
    JSR >ivINT_eFlexPWMA_RELOAD1  /* Interrupt no. 84*/
    JSR >ivINT_eFlexPWMA_CMP1     /* Interrupt no. 85*/
    JSR >ivINT_eFlexPWMA_RELOAD0  /* Interrupt no. 86*/
    JSR >ivINT_eFlexPWMA_CMP0     /* Interrupt no. 87*/
    JSR >ivINT_FTFL_RDCOL         /* Interrupt no. 88*/
    JSR >ivINT_FTFL_CC            /* Interrupt no. 89*/
    JSR >ivINT_CMPD               /* Interrupt no. 90*/
    JSR >ivINT_CMPC               /* Interrupt no. 91*/
    JSR >ivINT_CMPB               /* Interrupt no. 92*/
    JSR >ivINT_CMPA               /* Interrupt no. 93*/
    JSR >ivINT_PIT1_ROLLOVR       /* Interrupt no. 94*/
    JSR >ivINT_PIT0_ROLLOVR       /* Interrupt no. 95*/
    JSR >ivINT_PDB1               /* Interrupt no. 96*/
    JSR >ivINT_PDB0               /* Interrupt no. 97*/
    JSR >ivINT_QDC_INDEX_RO_RU    /* Interrupt no. 98*/
    JSR >ivINT_QDC_HOME_DOG       /* Interrupt no. 99*/
    JSR >ivINT_QDC_COMPARE        /* Interrupt no. 100*/
    JSR >ivINT_GPIOG              /* Interrupt no. 101*/
    JSR >ivINT_GPIOF              /* Interrupt no. 102*/
    JSR >ivINT_GPIOE              /* Interrupt no. 103*/
    JSR >ivINT_GPIOD              /* Interrupt no. 104*/
    JSR >ivINT_GPIOC              /* Interrupt no. 105*/
    JSR >ivINT_GPIOB              /* Interrupt no. 106*/
    JSR >ivINT_GPIOA              /* Interrupt no. 107*/
    JSR >ivINT_COP_INT            /* Interrupt no. 108*/
    JSR >ivINT_EWM_INT            /* Interrupt no. 109*/
    JSR >ivINT_SWILP              /* Interrupt no. 110*/
}

#pragma section interrupt_vectors end

/* clang-format on */

#endif _lint

/* Disable MISRA rules for interurupt routines */
/*lint -esym(765,Cpu_Interrupt) Disable MISRA rule (8.10) checking for symbols (Cpu_Interrupt). */
/*lint -esym(765,default_interrupt) Disable MISRA rule (8.10) checking for symbols (default_interrupt). */
