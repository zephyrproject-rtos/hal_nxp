/*
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef RISCV_INTERRUPT_H_
#define RISCV_INTERRUPT_H_

#include "riscv_csr.h"

/*!
 * @ingroup RISCV_CoreFunc
 * @defgroup RISCV_CoreInt Definition For Interrupts
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @name Interrupts
 * @{
 */
#define RV_INT_U_SOFTWARE 0U  /*!< User software interrupt */
#define RV_INT_S_SOFTWARE 1U  /*!< Supervisor software interrupt */
#define RV_INT_H_SOFTWARE 2U  /*!< Reserved for HyperVisor mode */
#define RV_INT_M_SOFTWARE 3U  /*!< Machine software interrupt */
#define RV_INT_U_TIMER    4U  /*!< User timer interrupt */
#define RV_INT_S_TIMER    5U  /*!< Supervisor timer interrupt */
#define RV_INT_H_TIMER    6U  /*!< Reserved for HyperVisor mode */
#define RV_INT_M_TIMER    7U  /*!< Machine timer interrupt */
#define RV_INT_U_EXT      8U  /*!< User external interrupt */
#define RV_INT_S_EXT      9U  /*!< Supervisor external interrupt */
#define RV_INT_H_EXT      10U /*!< Reserved for Hypervisor mode */
#define RV_INT_M_EXT      11U /*!< Machine external interrupt */

/*!
 * @}
 */

/*!
 * @name Fault exceptions
 * @{
 */

#define RV_EXC_MISALIGNED_FETCH    0U   /*!< misaligned fetch */
#define RV_EXC_FETCH_ACCESS        1U   /*!< fetch access */
#define RV_EXC_ILLLEGAL_INS        2U   /*!< illegal instructions */
#define RV_EXC_BREAKPOINT          3U   /*!< Breakpoint */
#define RV_EXC_MISALIGNED_LOAD     4U   /*!< misaligned load */
#define RV_EXC_LOAD_ACCESS         5U   /*!< load access fault */
#define RV_EXC_MISALIGNED_STORE    6U   /*!< misaligned store */
#define RV_EXC_STORE_ACCESS        7U   /*!< sotre access fault */
#define RV_EXC_U_ECALL             8U   /*!< environment call from U-mode */
#define RV_EXC_S_ECALL             9U   /*!< environment call from S-mode */
#define RV_EXC_H_ECALL             10U  /*!< environment call from Hyper-mode*/
#define RV_EXC_M_ECALL             11U  /*!< environment call from machine */
#define RV_EXC_FETCH_PAGE_FAULT    12U  /*!< instruction page fault */
#define RV_EXC_LOAD_PAGE_FAULT     13U  /*!< load page fault */
#define RV_EXC_STORE_PAGE_FAULT    15U  /*!< store/AMO page fault */

/*!
 * @}
 */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief MIE bit mask. */
typedef enum _ezhv_mie_mask
{
    kEZHV_Mie_Ssie= CSR_MIE_SSIE,  /*! S-mode software interrupt */
    kEZHV_Mie_Msie = CSR_MIE_MSIE,  /*!< M-mode software interrupt */
    kEZHV_Mie_Stie = CSR_MIE_STIE,  /*!< S-mode timer interrupt */
    kEZHV_Mie_Mtie = CSR_MIE_MTIE,  /*!< M-mode timer interrupt */
    kEZHV_Mie_Seie = CSR_MIE_SEIE,  /*!< S-mode external interrupt */
    kEZHV_Mie_Meie = CSR_MIE_MEIE,  /*!< M-mode external interrupt */
    kEZHV_Mie_Miee = CSR_MIE_MIEE,  /*!< M-mode imprecise exception */
} ezhv_mie_mask_t;

/*! @brief MSTATUS bit mask. */
typedef enum _ezhv_mstatus_mask
{
    kEZHV_Status_Sie = CSR_MSTATUS_SIE, /*!< S-mode interrupt enable bit */
    kEZHV_Status_Mie = CSR_MSTATUS_MIE, /*!< M-mode interrupt enable bit */
    kEZHV_Status_Spie = CSR_MSTATUS_SPIE, /*!< S-mode previous interrupt enable bit */
    kEZHV_Status_Mpie = CSR_MSTATUS_MPIE,/*!< M-mode previous  interrupt enable bit */
    kEZHV_Status_Spp = CSR_MSTATUS_SPP,/*!< S-mode previous privilege */
    kEZHV_Status_Mpp = CSR_MSTATUS_MPP,/*!< M-mode previous privilege */
    kEZHV_Status_Mprv = CSR_MSTATUS_MPRV,
    kEZHV_Status_Sum = CSR_MSTATUS_SUM,
    kEZHV_Status_Mxr = CSR_MSTATUS_MXR,
    kEZHV_Status_Tvm = CSR_MSTATUS_TVM,
    kEZHV_Status_Tw  = CSR_MSTATUS_TW,
    kEZHV_Status_Tsr = CSR_MSTATUS_TSR,
    kEZHV_Status_Sd  = CSR_MSTATUS_SD,
} ezhv_mstatus_mask_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* End of group RISCV_CoreInt */

#endif /* RISCV_INTERRUPT_H_ */
