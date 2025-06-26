/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef QSPI_IP_HYPERFLASHREGS_H
#define QSPI_IP_HYPERFLASHREGS_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_HYPERFLASHREGS_VENDOR_ID_H                    43
#define QSPI_IP_HYPERFLASHREGS_AR_RELEASE_MAJOR_VERSION_H     4
#define QSPI_IP_HYPERFLASHREGS_AR_RELEASE_MINOR_VERSION_H     7
#define QSPI_IP_HYPERFLASHREGS_AR_RELEASE_REVISION_VERSION_H  0
#define QSPI_IP_HYPERFLASHREGS_SW_MAJOR_VERSION_H             2
#define QSPI_IP_HYPERFLASHREGS_SW_MINOR_VERSION_H             0
#define QSPI_IP_HYPERFLASHREGS_SW_PATCH_VERSION_H             1


/*******************************************************************************
 *                                       DEFINITIONS
 ******************************************************************************/

/* Macros for Status Register bits manipulation */

#define QSPI_IP_HF_SR_ESTAT_MASK           0x100u
#define QSPI_IP_HF_SR_ESTAT_SHIFT          8u
#define QSPI_IP_HF_SR_ESTAT(x)             (((uint16)(((uint16)(x)) << QSPI_IP_HF_SR_ESTAT_SHIFT))&QSPI_IP_HF_SR_ESTAT_MASK)

#define QSPI_IP_HF_SR_SLSB_MASK            0x200u
#define QSPI_IP_HF_SR_SLSB_SHIFT           9u
#define QSPI_IP_HF_SR_SLSB(x)              (((uint16)(((uint16)(x)) << QSPI_IP_HF_SR_SLSB_SHIFT))&QSPI_IP_HF_SR_SLSB_MASK)

#define QSPI_IP_HF_SR_PSSB_MASK            0x400u
#define QSPI_IP_HF_SR_PSSB_SHIFT           10u
#define QSPI_IP_HF_SR_PSSB(x)              (((uint16)(((uint16)(x)) << QSPI_IP_HF_SR_PSSB_SHIFT))&QSPI_IP_HF_SR_PSSB_MASK)

#define QSPI_IP_HF_SR_WBASB_MASK           0x800u
#define QSPI_IP_HF_SR_WBASB_SHIFT          11u
#define QSPI_IP_HF_SR_WBASB(x)             (((uint16)(((uint16)(x)) << QSPI_IP_HF_SR_WBASB_SHIFT))&QSPI_IP_HF_SR_WBASB_MASK)

#define QSPI_IP_HF_SR_PSB_MASK             0x1000u
#define QSPI_IP_HF_SR_PSB_SHIFT            12u
#define QSPI_IP_HF_SR_PSB(x)               (((uint16)(((uint16)(x)) << QSPI_IP_HF_SR_PSB_SHIFT))&QSPI_IP_HF_SR_PSB_MASK)

#define QSPI_IP_HF_SR_ESB_MASK             0x2000u
#define QSPI_IP_HF_SR_ESB_SHIFT            13u
#define QSPI_IP_HF_SR_ESB(x)               (((uint16)(((uint16)(x)) << QSPI_IP_HF_SR_ESB_SHIFT))&QSPI_IP_HF_SR_ESB_MASK)

#define QSPI_IP_HF_SR_ESSB_MASK            0x4000u
#define QSPI_IP_HF_SR_ESSB_SHIFT           14u
#define QSPI_IP_HF_SR_ESSB(x)              (((uint16)(((uint16)(x)) << QSPI_IP_HF_SR_ESSB_SHIFT))&QSPI_IP_HF_SR_ESSB_MASK)

#define QSPI_IP_HF_SR_DRB_MASK             0x8000u
#define QSPI_IP_HF_SR_DRB_SHIFT            15u
#define QSPI_IP_HF_SR_DRB(x)               (((uint16)(((uint16)(x)) << QSPI_IP_HF_SR_DRB_SHIFT))&QSPI_IP_HF_SR_DRB_MASK)

#define QSPI_IP_HF_SR_CRCSSB_MASK          0x1u
#define QSPI_IP_HF_SR_CRCSSB_SHIFT         1u
#define QSPI_IP_HF_SR_CRCSSB(x)            (((uint16)(((uint16)(x)) << QSPI_IP_HF_SR_CRCSSB_SHIFT))&QSPI_IP_HF_SR_CRCSSB_MASK)

 /* Macros for x-Volatile Configuration Register */

#define QSPI_IP_HF_xVCR_BL_MASK             0x300u
#define QSPI_IP_HF_xVCR_BL_SHIFT            8u
#define QSPI_IP_HF_xVCR_BL(x)               (((uint16)(((uint16)(x)) << QSPI_IP_HF_xVCR_BL_SHIFT))&QSPI_IP_HF_xVCR_BL_MASK)

#define QSPI_IP_HF_xVCR_RWDS_MASK           0x400u
#define QSPI_IP_HF_xVCR_RWDS_SHIFT          10u
#define QSPI_IP_HF_xVCR_RWDS(x)             (((uint16)(((uint16)(x)) << QSPI_IP_HF_xVCR_RWDS_SHIFT))&QSPI_IP_HF_xVCR_RWDS_MASK)

#define QSPI_IP_HF_xVCR_RL_MASK             0xF000u
#define QSPI_IP_HF_xVCR_RL_SHIFT            12u
#define QSPI_IP_HF_xVCR_RL(x)               (((uint16)(((uint16)(x)) << QSPI_IP_HF_xVCR_RL_SHIFT))&QSPI_IP_HF_xVCR_RL_MASK)

#define QSPI_IP_HF_xVCR_PSM_MASK            0x3u
#define QSPI_IP_HF_xVCR_PSM_SHIFT           0u
#define QSPI_IP_HF_xVCR_PSM(x)              (((uint16)(((uint16)(x)) << QSPI_IP_HF_xVCR_PSM_SHIFT))&QSPI_IP_HF_xVCR_PSM_MASK)

#define QSPI_IP_HF_xVCR_SSR_MASK            0x4u
#define QSPI_IP_HF_xVCR_SSR_SHIFT           2u
#define QSPI_IP_HF_xVCR_SSR(x)              (((uint16)(((uint16)(x)) << QSPI_IP_HF_xVCR_SSR_SHIFT))&QSPI_IP_HF_xVCR_SSR_MASK)

#define QSPI_IP_HF_xVCR_FRZ_MASK            0x8u
#define QSPI_IP_HF_xVCR_FRZ_SHIFT           3u
#define QSPI_IP_HF_xVCR_FRZ(x)              (((uint16)(((uint16)(x)) << QSPI_IP_HF_xVCR_FRZ_SHIFT))&QSPI_IP_HF_xVCR_FRZ_MASK)

#define QSPI_IP_HF_xVCR_DS_MASK             0x70u
#define QSPI_IP_HF_xVCR_DS_SHIFT            4u
#define QSPI_IP_HF_xVCR_DS(x)               (((uint16)(((uint16)(x)) << QSPI_IP_HF_xVCR_DS_SHIFT))&QSPI_IP_HF_xVCR_DS_MASK)

/* Reserved bits of the Volatile/Non-Volatile Configuration register */

#define QSPI_IP_HF_xVCR_RESERVED_BIT_3      0x800u
#define QSPI_IP_HF_xVCR_RESERVED_BIT_16     0x80

/* Macros for ASP Register bits manipulation */
#define QSPI_IP_HF_ASPR_READ_PASS_MODE_MASK  0x2000u
#define QSPI_IP_HF_ASPR_READ_PASS_MODE_SHIFT 13u
#define QSPI_IP_HF_ASPR_READ_PASS_MODE(x)    (((uint16)(((uint16)(x)) << QSPI_IP_HF_ASPR_READ_PASS_MODE_SHIFT))&QSPI_IP_HF_ASPR_READ_PASS_MODE_MASK)

#define QSPI_IP_HF_ASPR_PROTECT_MODE_MASK    0x600u
#define QSPI_IP_HF_ASPR_PROTECT_MODE_SHIFT   9u
#define QSPI_IP_HF_ASPR_PROTECT_MODE(x)      (((uint16)(((uint16)(x)) << QSPI_IP_HF_ASPR_PROTECT_MODE_SHIFT))&QSPI_IP_HF_ASPR_PROTECT_MODE_MASK)

#define QSPI_IP_HF_ASPR_HYB_BURST_MASK       0x8u
#define QSPI_IP_HF_ASPR_HYB_BURST_SHIFT      3u
#define QSPI_IP_HF_ASPR_HYB_BURST(x)         (((uint16)(((uint16)(x)) << QSPI_IP_HF_ASPR_HYB_BURST_SHIFT))&QSPI_IP_HF_ASPR_HYB_BURST_MASK)

#define QSPI_IP_HF_ASPR_DEC_ECC_MASK         0x2u
#define QSPI_IP_HF_ASPR_DEC_ECC_SHIFT        1u
#define QSPI_IP_HF_ASPR_DEC_ECC(x)           (((uint16)(((uint16)(x)) << QSPI_IP_HF_ASPR_DEC_ECC_SHIFT))&QSPI_IP_HF_ASPR_DEC_ECC_MASK)

#define QSPI_IP_HF_ASPR_RESERVED_MASK        0xD9F4u

/* Interrupt Configuration Register bits manipulation */

#define QSPI_IP_HF_ICR_IOE_MASK              0x80u
#define QSPI_IP_HF_ICR_IOE_SHIFT             7u
#define QSPI_IP_HF_ICR_IOE(x)                (((uint16)(((uint16)(x)) << QSPI_IP_HF_ICR_IOE_SHIFT))&QSPI_IP_HF_ICR_IOE_MASK)

#define QSPI_IP_HF_ICR_READY_MASK            0x1000u
#define QSPI_IP_HF_ICR_READY_SHIFT           12u
#define QSPI_IP_HF_ICR_READY(x)              (((uint16)(((uint16)(x)) << QSPI_IP_HF_ICR_READY_SHIFT))&QSPI_IP_HF_ICR_READY_MASK)

#define QSPI_IP_HF_ICR_2BIT_DET_MASK         0x200u
#define QSPI_IP_HF_ICR_2BIT_DET_SHIFT        9u
#define QSPI_IP_HF_ICR_2BIT_DET(x)           (((uint16)(((uint16)(x)) << QSPI_IP_HF_ICR_2BIT_DET_SHIFT))&QSPI_IP_HF_ICR_2BIT_DET_MASK)

#define QSPI_IP_HF_ICR_1BIT_DET_MASK         0x100u
#define QSPI_IP_HF_ICR_1BIT_DET_SHIFT        8u
#define QSPI_IP_HF_ICR_1BIT_DET(x)           (((uint16)(((uint16)(x)) << QSPI_IP_HF_ICR_1BIT_DET_SHIFT))&QSPI_IP_HF_ICR_1BIT_DET_MASK)

/* Interrupt Status Register bits manipulation       */

#define QSPI_IP_HF_ISR_IOE_MASK               0x80u
#define QSPI_IP_HF_ISR_IOE_SHIFT              7u
#define QSPI_IP_HF_ISR_IOE(x)                 (((uint16)(((uint16)(x)) << QSPI_IP_HF_ISR_IOE_SHIFT))&QSPI_IP_HF_ISR_IOE_MASK)

#define QSPI_IP_HF_ISR_POR_MASK               0x400u
#define QSPI_IP_HF_ISR_POR_SHIFT              10u
#define QSPI_IP_HF_ISR_POR(x)                 (((uint16)(((uint16)(x)) << QSPI_IP_HF_ISR_POR_SHIFT))&QSPI_IP_HF_ISR_POR_MASK)

#define QSPI_IP_HF_ISR_READY_MASK             0x1000u
#define QSPI_IP_HF_ISR_READY_SHIFT            12u
#define QSPI_IP_HF_ISR_READY(x)               (((uint16)(((uint16)(x)) << QSPI_IP_HF_ISR_READY_SHIFT))&QSPI_IP_HF_ISR_READY_MASK)

#define QSPI_IP_HF_ISR_2BIT_DET_MASK          0x200u
#define QSPI_IP_HF_ISR_2BIT_DET_SHIFT         9u
#define QSPI_IP_HF_ISR_2BIT_DET(x)            (((uint16)(((uint16)(x)) << QSPI_IP_HF_ISR_2BIT_DET_SHIFT))&QSPI_IP_HF_ISR_2BIT_DET_MASK)

#define QSPI_IP_HF_ISR_1BIT_DET_MASK          0x100u
#define QSPI_IP_HF_ISR_1BIT_DET_SHIFT         8u
#define QSPI_IP_HF_ISR_1BIT_DET(x)           (((uint16)(((uint16)(x)) << QSPI_IP_HF_ISR_1BIT_DET_SHIFT))&QSPI_IP_HF_ISR_1BIT_DET_MASK)

/* ECC Status Register bits manipulation */
#define QSPI_IP_HF_ECCSR_2BIT_DET_MASK        0x1000u
#define QSPI_IP_HF_ECCSR_2BIT_DET_SHIFT       12u
#define QSPI_IP_HF_ECCSR_2BIT_DET(x)          (((uint16)(((uint16)(x)) << QSPI_IP_HF_ECCSR_2BIT_DET_SHIFT))&QSPI_IP_HF_ECCSR_2BIT_DET_MASK)

#define QSPI_IP_HF_ECCSR_1BIT_CR_MASK        0x800u
#define QSPI_IP_HF_ECCSR_1BIT_CR_SHIFT       11u
#define QSPI_IP_HF_ECCSR_1BIT_CR(x)          (((uint16)(((uint16)(x)) << QSPI_IP_HF_ECCSR_1BIT_CR_SHIFT))&QSPI_IP_HF_ECCSR_1BIT_CR_MASK)

#define QSPI_IP_HF_ECCSR_ERR_ECC_MASK         0x400u
#define QSPI_IP_HF_ECCSR_ERR_ECC_SHIFT        10u
#define QSPI_IP_HF_ECCSR_ERR_ECC(x)           (((uint16)(((uint16)(x)) << QSPI_IP_HF_ECCSR_ERR_ECC_SHIFT))&QSPI_IP_HF_ECCSR_ERR_ECC_MASK)

#define QSPI_IP_HF_ECCSR_ERRECC_UNIT_MASK     0x200u
#define QSPI_IP_HF_ECCSR_ERRECC_UNIT_SHIFT    9u
#define QSPI_IP_HF_ECCSR_ERRECC_UNIT(x)       (((uint16)(((uint16)(x)) << QSPI_IP_HF_ECCSR_ERRECC_UNIT_SHIFT))&QSPI_IP_HF_ECCSR_ERRECC_UNIT_MASK)

#define QSPI_IP_HF_ECCSR_ECC_DISABLED_MASK    0x100u
#define QSPI_IP_HF_ECCSR_ECC_DISABLED_SHIFT   8u
#define QSPI_IP_HF_ECCSR_ECC_DISABLED(x)      (((uint16)(((uint16)(x)) << QSPI_IP_HF_ECCSR_ECC_DISABLED_SHIFT))&QSPI_IP_HF_ECCSR_ECC_DISABLED_MASK)

#ifdef __cplusplus
}
#endif


#endif /* QSPI_IP_HYPERFLASHREGS_H */
