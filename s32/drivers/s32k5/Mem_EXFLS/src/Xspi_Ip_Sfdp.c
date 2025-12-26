/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file Xspi_Ip_Sfdp.c
*
*   @addtogroup IPV_XSPI
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

#include "OsIf.h"
#include "Xspi_Ip_Controller.h"
#include "Xspi_Ip.h"
#include "Xspi_Ip_Common.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define XSPI_IP_VENDOR_ID_C                    43
#define XSPI_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define XSPI_IP_AR_RELEASE_MINOR_VERSION_C     9
#define XSPI_IP_AR_RELEASE_REVISION_VERSION_C  0
#define XSPI_IP_SW_MAJOR_VERSION_C             0
#define XSPI_IP_SW_MINOR_VERSION_C             8
#define XSPI_IP_SW_PATCH_VERSION_C             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((XSPI_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (XSPI_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Xspi_Ip_Sfdp.c and OsIf.h are different"
    #endif
#endif

/* Check if current file and Xspi_Ip_Controller header file are of the same vendor */
#if (XSPI_IP_VENDOR_ID_C != XSPI_IP_CONTROLLER_VENDOR_ID_H)
    #error "Xspi_Ip_Sfdp.c and Xspi_Ip_Controller.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Controller header file are of the same Autosar version */
#if ((XSPI_IP_AR_RELEASE_MAJOR_VERSION_C    != XSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_AR_RELEASE_MINOR_VERSION_C    != XSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_AR_RELEASE_REVISION_VERSION_C != XSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_Sfdp.c and Xspi_Ip_Controller.h are different"
#endif
/* Check if current file and Xspi_Ip_Controller header file are of the same Software version */
#if ((XSPI_IP_SW_MAJOR_VERSION_C != XSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_SW_MINOR_VERSION_C != XSPI_IP_CONTROLLER_SW_MINOR_VERSION_H) || \
     (XSPI_IP_SW_PATCH_VERSION_C != XSPI_IP_CONTROLLER_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip_Sfdp.c and Xspi_Ip_Controller.h are different"
#endif

/* Check if current file and Xspi_Ip_Common header file are of the same vendor */
#if (XSPI_IP_VENDOR_ID_C != XSPI_IP_COMMON_VENDOR_ID_H)
    #error "Xspi_Ip_Sfdp.c and Xspi_Ip_Common.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Common header file are of the same Autosar version */
#if ((XSPI_IP_AR_RELEASE_MAJOR_VERSION_C    != XSPI_IP_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_AR_RELEASE_MINOR_VERSION_C    != XSPI_IP_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_AR_RELEASE_REVISION_VERSION_C != XSPI_IP_COMMON_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_Sfdp.c and Xspi_Ip_Common.h are different"
#endif
/* Check if current file and Xspi_Ip_Common header file are of the same Software version */
#if ((XSPI_IP_SW_MAJOR_VERSION_C != XSPI_IP_COMMON_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_SW_MINOR_VERSION_C != XSPI_IP_COMMON_SW_MINOR_VERSION_H) || \
     (XSPI_IP_SW_PATCH_VERSION_C != XSPI_IP_COMMON_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip_Sfdp.c and Xspi_Ip_Common.h are different"
#endif

/* Check if current file and Xspi_Ip header file are of the same vendor */
#if (XSPI_IP_VENDOR_ID_C != XSPI_IP_VENDOR_ID_H)
    #error "Xspi_Ip_Sfdp.c and Xspi_Ip.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip header file are of the same Autosar version */
#if ((XSPI_IP_AR_RELEASE_MAJOR_VERSION_C    != XSPI_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_AR_RELEASE_MINOR_VERSION_C    != XSPI_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_AR_RELEASE_REVISION_VERSION_C != XSPI_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_Sfdp.c and Xspi_Ip.h are different"
#endif
/* Check if current file and Xspi_Ip header file are of the same Software version */
#if ((XSPI_IP_SW_MAJOR_VERSION_C != XSPI_IP_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_SW_MINOR_VERSION_C != XSPI_IP_SW_MINOR_VERSION_H) || \
     (XSPI_IP_SW_PATCH_VERSION_C != XSPI_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip_Sfdp.c and Xspi_Ip.h are different"
#endif


/*******************************************************************************
 * Definitions.
 ******************************************************************************/
#if (XSPI_IP_USE_SFDP_CFG == STD_ON)

#define XSPI_IP_CMD_SFDP_READ            0x5AU    /* Instruction for Read SFDP command */
#define XSPI_IP_CMD_BASIC_READ           0x03U    /* Basic read instruction  */
#define XSPI_IP_CMD_BASIC_READ_4B        0x13U    /* Basic read instruction - 4 bytes address */
#define XSPI_IP_CMD_BASIC_WRITE          0x02U    /* Basic write (page program) instruction  */
#define XSPI_IP_CMD_BASIC_READ_SR        0x05U    /* Basic instruction for read status reg. command */
#define XSPI_IP_CMD_BASIC_WRITE_SR       0x01U    /* Basic instruction for write status reg. command */
#define XSPI_IP_CMD_BASIC_WRITE_ENABLE   0x06U    /* Basic instruction for write enable command */
#define XSPI_IP_CMD_BASIC_CHIP_ERASE     0x60U    /* Basic instruction for chip erase command */
#define XSPI_IP_CMD_XSPI_WRITE           0x12U    /* XSPI profile 1.0 Instruction for Program command */
#define XSPI_IP_CMD_XSPI_CHIP_ERASE      0xC7U    /* XSPI profile 1.0 Instruction for Chip Erase command */
#define XSPI_IP_CMD_XSPI_READ_SR         0x05U    /* XSPI profile 1.0 Instruction for read status reg. command */
#define XSPI_IP_CMD_XSPI_WRITE_SR        0x01U    /* XSPI profile 1.0 Instruction for write status reg. command */
#define XSPI_IP_CMD_XSPI_WRITE_ENABLE    0x06U    /* XSPI profile 1.0 Instruction for write enable command */
#define XSPI_IP_CMD_XSPI_RESET           0xF0U    /* XSPI profile 1.0 Instruction for soft reset command */
#define XSPI_IP_CMD_XSPI_RESET_ENABLE    0x66U    /* XSPI profile 1.0 Instruction for reset enable command */
#define XSPI_IP_CMD_XSPI_RESET_DEF       0x99U    /* XSPI profile 1.0 Instruction for soft reset and enter default protocol mode command */

#define XSPI_IP_TABLE_SIZE_BASIC     20U     /* Max basic flash parameter table length                      */
#define XSPI_IP_TABLE_SIZE_4BADD     2U      /* Max 4-byte address instruction table length                 */
#define XSPI_IP_TABLE_SIZE_XSPI1     5U      /* Max extended serial peripheral interface table length       */
#define XSPI_IP_TABLE_SIZE_SRMAP     28U     /* Max status, control and configuration register map length   */
#define XSPI_IP_TABLE_SIZE_2DOPI     8U      /* Max command sequence to change to octal ddr length          */

#define XSPI_IP_SFDP_MAJOR_REVISION              1U
#define XSPI_IP_SFDP_MINOR_REVISION_REV_0        0U
#define XSPI_IP_SFDP_MINOR_REVISION_REV_A        5U

#define XSPI_IP_SFDP_ACCESS_PROTOCOL_HYPERBUS    0xFAU  /* xSPI NOR Profile 2 HYPERBUS, (8D, 8D, 8D) operation */
#define XSPI_IP_SFDP_ACCESS_PROTOCOL_LEGACY      0xFFU  /* Legacy option (1S-1S-1S), (2S-2S-2S) or (4S-4S-4S) operation, 3-byte addressing for SFDP */

    /**** Constants for retrieving SFDP parameters - Basic flash parameters table *****/

    /* Flash Size */
#define XSPI_IP_SFDP_BASIC_MEM_SIZE_DWORD         2U
#define XSPI_IP_SFDP_BASIC_MEM_SIZE_SHIFT         0U
#define XSPI_IP_SFDP_BASIC_MEM_SIZE_WIDTH         32U
    /* Page Size */
#define XSPI_IP_SFDP_BASIC_PAGE_SIZE_DWORD        11U
#define XSPI_IP_SFDP_BASIC_PAGE_SIZE_SHIFT        4U
#define XSPI_IP_SFDP_BASIC_PAGE_SIZE_WIDTH        4U
    /* Octal DTR (8D-8D-8D) Command and Command Extension */
#define XSPI_IP_SFDP_BASIC_CMD_EXT_DWORD          18U
#define XSPI_IP_SFDP_BASIC_CMD_EXT_SHIFT          29U
#define XSPI_IP_SFDP_BASIC_CMD_EXT_WIDTH          2U
    /* Erase type 1 - instruction and size */
#define XSPI_IP_SFDP_BASIC_ERASE1_INST_DWORD          8U
#define XSPI_IP_SFDP_BASIC_ERASE1_INST_SHIFT          8U
#define XSPI_IP_SFDP_BASIC_ERASE1_INST_WIDTH          8U
#define XSPI_IP_SFDP_BASIC_ERASE1_SIZE_DWORD          8U
#define XSPI_IP_SFDP_BASIC_ERASE1_SIZE_SHIFT          0U
#define XSPI_IP_SFDP_BASIC_ERASE1_SIZE_WIDTH          8U
    /* Erase type 2 - instruction and size */
#define XSPI_IP_SFDP_BASIC_ERASE2_INST_DWORD          8U
#define XSPI_IP_SFDP_BASIC_ERASE2_INST_SHIFT          24U
#define XSPI_IP_SFDP_BASIC_ERASE2_INST_WIDTH          8U
#define XSPI_IP_SFDP_BASIC_ERASE2_SIZE_DWORD          8U
#define XSPI_IP_SFDP_BASIC_ERASE2_SIZE_SHIFT          16U
#define XSPI_IP_SFDP_BASIC_ERASE2_SIZE_WIDTH          8U
    /* Erase type 3 - instruction and size */
#define XSPI_IP_SFDP_BASIC_ERASE3_INST_DWORD          9U
#define XSPI_IP_SFDP_BASIC_ERASE3_INST_SHIFT          8U
#define XSPI_IP_SFDP_BASIC_ERASE3_INST_WIDTH          8U
#define XSPI_IP_SFDP_BASIC_ERASE3_SIZE_DWORD          9U
#define XSPI_IP_SFDP_BASIC_ERASE3_SIZE_SHIFT          0U
#define XSPI_IP_SFDP_BASIC_ERASE3_SIZE_WIDTH          8U
    /* Erase type 4 - instruction and size */
#define XSPI_IP_SFDP_BASIC_ERASE4_INST_DWORD          9U
#define XSPI_IP_SFDP_BASIC_ERASE4_INST_SHIFT          24U
#define XSPI_IP_SFDP_BASIC_ERASE4_INST_WIDTH          8U
#define XSPI_IP_SFDP_BASIC_ERASE4_SIZE_DWORD          9U
#define XSPI_IP_SFDP_BASIC_ERASE4_SIZE_SHIFT          16U
#define XSPI_IP_SFDP_BASIC_ERASE4_SIZE_WIDTH          8U
    /* Erase suspend instruction */
#define XSPI_IP_SFDP_BASIC_ESUS_INSTR_DWORD          13U
#define XSPI_IP_SFDP_BASIC_ESUS_INSTR_SHIFT          24U
#define XSPI_IP_SFDP_BASIC_ESUS_INSTR_WIDTH          8U
    /* Erase resume instruction */
#define XSPI_IP_SFDP_BASIC_ERES_INSTR_DWORD          13U
#define XSPI_IP_SFDP_BASIC_ERES_INSTR_SHIFT          16U
#define XSPI_IP_SFDP_BASIC_ERES_INSTR_WIDTH          8U
    /* Program suspend instruction */
#define XSPI_IP_SFDP_BASIC_PSUS_INSTR_DWORD          13U
#define XSPI_IP_SFDP_BASIC_PSUS_INSTR_SHIFT          8U
#define XSPI_IP_SFDP_BASIC_PSUS_INSTR_WIDTH          8U
    /* Program resume instruction */
#define XSPI_IP_SFDP_BASIC_PRES_INSTR_DWORD          13U
#define XSPI_IP_SFDP_BASIC_PRES_INSTR_SHIFT          0U
#define XSPI_IP_SFDP_BASIC_PRES_INSTR_WIDTH          8U
    /* Quad Enable Requirements */
#define XSPI_IP_SFDP_BASIC_QE_REQ_DWORD              15U
#define XSPI_IP_SFDP_BASIC_QE_REQ_SHIFT              20U
#define XSPI_IP_SFDP_BASIC_QE_REQ_WIDTH              3U
    /* Soft Reset */
#define XSPI_IP_SFDP_BASIC_SW_RESET_DWORD            16U
#define XSPI_IP_SFDP_BASIC_SW_RESET_SHIFT            8U
#define XSPI_IP_SFDP_BASIC_SW_RESET_WIDTH            6U
    /* Write Enable Instruction Select for Writing to Volatile Status Register */
#define XSPI_IP_SFDP_BASIC_WREN_SR_DWORD             1U
#define XSPI_IP_SFDP_BASIC_WREN_SR_SHIFT             3U
#define XSPI_IP_SFDP_BASIC_WREN_SR_WIDTH             2U
    /* 4-4-4 mode enable sequences */
#define XSPI_IP_SFDP_BASIC_444_SWITCH_DWORD          15U
#define XSPI_IP_SFDP_BASIC_444_SWITCH_SHIFT          4U
#define XSPI_IP_SFDP_BASIC_444_SWITCH_WIDTH          5U

    /* Fast read instructions/mode bits/dummy bits */
#define  XSPI_IP_SFDP_BASIC_READ112_SUP_DWORD           1U
#define  XSPI_IP_SFDP_BASIC_READ122_SUP_DWORD           1U
#define  XSPI_IP_SFDP_BASIC_READ114_SUP_DWORD           1U
#define  XSPI_IP_SFDP_BASIC_READ144_SUP_DWORD           1U
#define  XSPI_IP_SFDP_BASIC_READ444_SUP_DWORD           5U
#define  XSPI_IP_SFDP_BASIC_READ118_SUP_DWORD           17U
#define  XSPI_IP_SFDP_BASIC_READ188_SUP_DWORD           17U

#define  XSPI_IP_SFDP_BASIC_READ112_SUP_SHIFT           16U
#define  XSPI_IP_SFDP_BASIC_READ122_SUP_SHIFT           20U
#define  XSPI_IP_SFDP_BASIC_READ114_SUP_SHIFT           22U
#define  XSPI_IP_SFDP_BASIC_READ144_SUP_SHIFT           21U
#define  XSPI_IP_SFDP_BASIC_READ444_SUP_SHIFT           4U
#define  XSPI_IP_SFDP_BASIC_READ118_SUP_SHIFT           24U
#define  XSPI_IP_SFDP_BASIC_READ188_SUP_SHIFT           8U

#define  XSPI_IP_SFDP_BASIC_READ112_SUP_WIDTH           1U
#define  XSPI_IP_SFDP_BASIC_READ122_SUP_WIDTH           1U
#define  XSPI_IP_SFDP_BASIC_READ114_SUP_WIDTH           1U
#define  XSPI_IP_SFDP_BASIC_READ144_SUP_WIDTH           1U
#define  XSPI_IP_SFDP_BASIC_READ444_SUP_WIDTH           1U
#define  XSPI_IP_SFDP_BASIC_READ118_SUP_WIDTH           8U
#define  XSPI_IP_SFDP_BASIC_READ188_SUP_WIDTH           8U

#define  XSPI_IP_SFDP_BASIC_READ112_INST_DWORD           4U
#define  XSPI_IP_SFDP_BASIC_READ122_INST_DWORD           4U
#define  XSPI_IP_SFDP_BASIC_READ114_INST_DWORD           3U
#define  XSPI_IP_SFDP_BASIC_READ144_INST_DWORD           3U
#define  XSPI_IP_SFDP_BASIC_READ444_INST_DWORD           7U
#define  XSPI_IP_SFDP_BASIC_READ118_INST_DWORD           17U
#define  XSPI_IP_SFDP_BASIC_READ188_INST_DWORD           17U

#define  XSPI_IP_SFDP_BASIC_READ112_INST_SHIFT           8U
#define  XSPI_IP_SFDP_BASIC_READ122_INST_SHIFT           24U
#define  XSPI_IP_SFDP_BASIC_READ114_INST_SHIFT           24U
#define  XSPI_IP_SFDP_BASIC_READ144_INST_SHIFT           8U
#define  XSPI_IP_SFDP_BASIC_READ444_INST_SHIFT           24U
#define  XSPI_IP_SFDP_BASIC_READ118_INST_SHIFT           24U
#define  XSPI_IP_SFDP_BASIC_READ188_INST_SHIFT           8U

#define  XSPI_IP_SFDP_BASIC_READ112_INST_WIDTH           8U
#define  XSPI_IP_SFDP_BASIC_READ122_INST_WIDTH           8U
#define  XSPI_IP_SFDP_BASIC_READ114_INST_WIDTH           8U
#define  XSPI_IP_SFDP_BASIC_READ144_INST_WIDTH           8U
#define  XSPI_IP_SFDP_BASIC_READ444_INST_WIDTH           8U
#define  XSPI_IP_SFDP_BASIC_READ118_INST_WIDTH           8U
#define  XSPI_IP_SFDP_BASIC_READ188_INST_WIDTH           8U

#define  XSPI_IP_SFDP_BASIC_READ112_MODE_DWORD           4U
#define  XSPI_IP_SFDP_BASIC_READ122_MODE_DWORD           4U
#define  XSPI_IP_SFDP_BASIC_READ114_MODE_DWORD           3U
#define  XSPI_IP_SFDP_BASIC_READ144_MODE_DWORD           3U
#define  XSPI_IP_SFDP_BASIC_READ444_MODE_DWORD           7U
#define  XSPI_IP_SFDP_BASIC_READ118_MODE_DWORD           17U
#define  XSPI_IP_SFDP_BASIC_READ188_MODE_DWORD           17U

#define  XSPI_IP_SFDP_BASIC_READ112_MODE_SHIFT           5U
#define  XSPI_IP_SFDP_BASIC_READ122_MODE_SHIFT           21U
#define  XSPI_IP_SFDP_BASIC_READ114_MODE_SHIFT           21U
#define  XSPI_IP_SFDP_BASIC_READ144_MODE_SHIFT           5U
#define  XSPI_IP_SFDP_BASIC_READ444_MODE_SHIFT           21U
#define  XSPI_IP_SFDP_BASIC_READ118_MODE_SHIFT           21U
#define  XSPI_IP_SFDP_BASIC_READ188_MODE_SHIFT           5U

#define  XSPI_IP_SFDP_BASIC_READ112_MODE_WIDTH           3U
#define  XSPI_IP_SFDP_BASIC_READ122_MODE_WIDTH           3U
#define  XSPI_IP_SFDP_BASIC_READ114_MODE_WIDTH           3U
#define  XSPI_IP_SFDP_BASIC_READ144_MODE_WIDTH           3U
#define  XSPI_IP_SFDP_BASIC_READ444_MODE_WIDTH           3U
#define  XSPI_IP_SFDP_BASIC_READ118_MODE_WIDTH           3U
#define  XSPI_IP_SFDP_BASIC_READ188_MODE_WIDTH           3U

#define  XSPI_IP_SFDP_BASIC_READ112_DUMMY_DWORD           4U
#define  XSPI_IP_SFDP_BASIC_READ122_DUMMY_DWORD           4U
#define  XSPI_IP_SFDP_BASIC_READ114_DUMMY_DWORD           3U
#define  XSPI_IP_SFDP_BASIC_READ144_DUMMY_DWORD           3U
#define  XSPI_IP_SFDP_BASIC_READ444_DUMMY_DWORD           7U
#define  XSPI_IP_SFDP_BASIC_READ118_DUMMY_DWORD           17U
#define  XSPI_IP_SFDP_BASIC_READ188_DUMMY_DWORD           17U

#define  XSPI_IP_SFDP_BASIC_READ112_DUMMY_SHIFT           0U
#define  XSPI_IP_SFDP_BASIC_READ122_DUMMY_SHIFT           16U
#define  XSPI_IP_SFDP_BASIC_READ114_DUMMY_SHIFT           16U
#define  XSPI_IP_SFDP_BASIC_READ144_DUMMY_SHIFT           0U
#define  XSPI_IP_SFDP_BASIC_READ444_DUMMY_SHIFT           16U
#define  XSPI_IP_SFDP_BASIC_READ118_DUMMY_SHIFT           16U
#define  XSPI_IP_SFDP_BASIC_READ188_DUMMY_SHIFT           0U

#define  XSPI_IP_SFDP_BASIC_READ112_DUMMY_WIDTH           5U
#define  XSPI_IP_SFDP_BASIC_READ122_DUMMY_WIDTH           5U
#define  XSPI_IP_SFDP_BASIC_READ114_DUMMY_WIDTH           5U
#define  XSPI_IP_SFDP_BASIC_READ144_DUMMY_WIDTH           5U
#define  XSPI_IP_SFDP_BASIC_READ444_DUMMY_WIDTH           5U
#define  XSPI_IP_SFDP_BASIC_READ118_DUMMY_WIDTH           5U
#define  XSPI_IP_SFDP_BASIC_READ188_DUMMY_WIDTH           5U

#define  XSPI_IP_SFDP_BASIC_ADDR_BYTES_DWORD           1U
#define  XSPI_IP_SFDP_BASIC_ADDR_BYTES_SHIFT           17U
#define  XSPI_IP_SFDP_BASIC_ADDR_BYTES_WIDTH           2U

#define  XSPI_IP_SFDP_BASIC_ADDR_SWITCH_DWORD          16U
#define  XSPI_IP_SFDP_BASIC_ADDR_SWITCH_SHIFT          24U
#define  XSPI_IP_SFDP_BASIC_ADDR_SWITCH_WIDTH          8U


    /**** Constants for retrieving SFDP parameters - xSPI 1.0 table *****/

    /* Read fast command */
#define XSPI_IP_SFDP_XSPI1_READ_FAST_DWORD          1U
#define XSPI_IP_SFDP_XSPI1_READ_FAST_SHIFT          8U
#define XSPI_IP_SFDP_XSPI1_READ_FAST_WIDTH          8U
    /* Max. number of dummy cycles */
#define XSPI_IP_SFDP_XSPI1_DUMMY_DWORD              4U
#define XSPI_IP_SFDP_XSPI1_DUMMY_SHIFT              7U
#define XSPI_IP_SFDP_XSPI1_DUMMY_WIDTH              5U
    /* Chip erase support */
#define XSPI_IP_SFDP_XSPI1_CHIP_ERASE_DWORD         3U
#define XSPI_IP_SFDP_XSPI1_CHIP_ERASE_SHIFT         26U
#define XSPI_IP_SFDP_XSPI1_CHIP_ERASE_WIDTH         1U
    /* Soft Reset support */
#define XSPI_IP_SFDP_XSPI1_RESET_DWORD              3U
#define XSPI_IP_SFDP_XSPI1_RESET_SHIFT              13U
#define XSPI_IP_SFDP_XSPI1_RESET_WIDTH              1U
    /* Reset Enable support */
#define XSPI_IP_SFDP_XSPI1_RESET_EN_DWORD           3U
#define XSPI_IP_SFDP_XSPI1_RESET_EN_SHIFT           12U
#define XSPI_IP_SFDP_XSPI1_RESET_EN_WIDTH           1U
    /* Soft Reset and Enter default protocol mode support */
#define XSPI_IP_SFDP_XSPI1_RESET_DEF_DWORD          3U
#define XSPI_IP_SFDP_XSPI1_RESET_DEF_SHIFT          11U
#define XSPI_IP_SFDP_XSPI1_RESET_DEF_WIDTH          1U
    /* SR local address */
#define XSPI_IP_SFDP_XSPI1_NBYTES_DWORD          1U
#define XSPI_IP_SFDP_XSPI1_NBYTES_SHIFT          31U
#define XSPI_IP_SFDP_XSPI1_NBYTES_WIDTH          1U
    /**** Constants for retrieving SFDP parameters - Status, Control and Configuration Register Map *****/

    /* Busy (WIP) flag offset */
#define XSPI_IP_SFDP_SRMAP_WIP_OFFSET_DWORD         5U
#define XSPI_IP_SFDP_SRMAP_WIP_OFFSET_SHIFT         24U
#define XSPI_IP_SFDP_SRMAP_WIP_OFFSET_WIDTH         3U

    /* Busy (WIP) flag value */
#define XSPI_IP_SFDP_SRMAP_WIP_VALUE_DWORD          5U
#define XSPI_IP_SFDP_SRMAP_WIP_VALUE_SHIFT          30U
#define XSPI_IP_SFDP_SRMAP_WIP_VALUE_WIDTH          1U

    /* Write Enable (WEL) flag offset */
#define XSPI_IP_SFDP_SRMAP_WEL_OFFSET_DWORD         6U
#define XSPI_IP_SFDP_SRMAP_WEL_OFFSET_SHIFT         24U
#define XSPI_IP_SFDP_SRMAP_WEL_OFFSET_WIDTH         3U

    /* Program error flag offset */
#define XSPI_IP_SFDP_SRMAP_PER_OFFSET_DWORD         7U
#define XSPI_IP_SFDP_SRMAP_PER_OFFSET_SHIFT         24U
#define XSPI_IP_SFDP_SRMAP_PER_OFFSET_WIDTH         3U

    /* Program error flag value */
#define XSPI_IP_SFDP_SRMAP_PER_VALUE_DWORD          7U
#define XSPI_IP_SFDP_SRMAP_PER_VALUE_SHIFT          30U
#define XSPI_IP_SFDP_SRMAP_PER_VALUE_WIDTH          1U

    /* Erase error flag offset */
#define XSPI_IP_SFDP_SRMAP_EER_OFFSET_DWORD         8U
#define XSPI_IP_SFDP_SRMAP_EER_OFFSET_SHIFT         24U
#define XSPI_IP_SFDP_SRMAP_EER_OFFSET_WIDTH         3U

    /* Dummy cycles in 8D-8D-8D mode */
#define XSPI_IP_SFDP_SRMAP_DUMMY_8D_DWORD          3U
#define XSPI_IP_SFDP_SRMAP_DUMMY_8D_SHIFT          6U
#define XSPI_IP_SFDP_SRMAP_DUMMY_8D_WIDTH          4U
    /* SR read is direct command (not using address) */
#define XSPI_IP_SFDP_SRMAP_USE_ADDR_DWORD          5U
#define XSPI_IP_SFDP_SRMAP_USE_ADDR_SHIFT          28U
#define XSPI_IP_SFDP_SRMAP_USE_ADDR_WIDTH          1U
    /* Address offset for volatile registers */
#define XSPI_IP_SFDP_SRMAP_OFFSET_DWORD          1U
#define XSPI_IP_SFDP_SRMAP_OFFSET_SHIFT          0U
#define XSPI_IP_SFDP_SRMAP_OFFSET_WIDTH          32U
    /* Number of address bytes used for Generic Addressable Read/Write Status/Control register commands for volatile registers */
#define XSPI_IP_SFDP_SRMAP_NBYTES_DWORD          3U
#define XSPI_IP_SFDP_SRMAP_NBYTES_SHIFT          28U
#define XSPI_IP_SFDP_SRMAP_NBYTES_WIDTH          2U
    /* SR local address */
#define XSPI_IP_SFDP_SRMAP_SR_ADDR_DWORD          5U
#define XSPI_IP_SFDP_SRMAP_SR_ADDR_SHIFT          16U
#define XSPI_IP_SFDP_SRMAP_SR_ADDR_WIDTH          8U

    /* SR read command */
#define XSPI_IP_SFDP_SRMAP_READ_CMD_DWORD          5U
#define XSPI_IP_SFDP_SRMAP_READ_CMD_SHIFT          8U
#define XSPI_IP_SFDP_SRMAP_READ_CMD_WIDTH          8U

/*Define for dummy cycle information*/
#define XSPI_IP_SFDP_SRMAP_SR_DUMMY_CYCLE_PATTERN_02_10_DWORD    13U
#define XSPI_IP_SFDP_SRMAP_SR_DUMMY_CYCLE_SUPPORT_WIDTH           1U
#define XSPI_IP_SFDP_SRMAP_SR_DUMMY_CYCLE_PATTERN_WIDTH           5U
#define XSPI_IP_SFDP_SRMAP_SR_02_DUMMY_CYCLE_PATTERN_SHIFT        2U

#define XSPI_IP_SFDP_SRMAP_DWORD_9_OFFSET                         9U
#define XSPI_IP_SFDP_SRMAP_DWORD_9_SUPPORTED_VAR_DUMMY_SHIFT     31U
#define XSPI_IP_SFDP_SRMAP_DWORD_9_SUPPORTED_VAR_DUMMY_WIDTH      1U
#define XSPI_IP_SFDP_SRMAP_DWORD_9_NUMBER_OF_BITS_SHIFT          29U
#define XSPI_IP_SFDP_SRMAP_DWORD_9_NUMBER_OF_BITS_WIDTH           2U
#define XSPI_IP_SFDP_SRMAP_DWORD_9_REG_ADDRESS_SHIFT             16U
#define XSPI_IP_SFDP_SRMAP_DWORD_9_REG_ADDRESS_WIDTH              8U
#define XSPI_IP_SFDP_SRMAP_DWORD_9_BYTE_ADDRESS_SHIFT            27U
#define XSPI_IP_SFDP_SRMAP_DWORD_9_BYTE_ADDRESS_WIDTH             1U
#define XSPI_IP_SFDP_SRMAP_DWORD_9_BIT_LOCATION_SHIFT            24U
#define XSPI_IP_SFDP_SRMAP_DWORD_9_BIT_LOCATION_WIDTH             3U
#define XSPI_IP_SFDP_SRMAP_DWORD_9_CMD_READ_SHIFT                 8U
#define XSPI_IP_SFDP_SRMAP_DWORD_9_CMD_READ_WIDTH                 8U
#define XSPI_IP_SFDP_SRMAP_DWORD_9_CMD_WRITE_SHIFT                0U
#define XSPI_IP_SFDP_SRMAP_DWORD_9_CMD_WRITE_WIDTH                8U

/* SR address shift (before adding to the offset) */
#define XSPI_IP_SFDP_SRMAP_SR_SHIFT_DWORD          5U
#define XSPI_IP_SFDP_SRMAP_SR_SHIFT_SHIFT          27U
#define XSPI_IP_SFDP_SRMAP_SR_SHIFT_WIDTH          1U

    /**** Constants for retrieving SFDP parameters - Command Sequences to Change to Octal DDR (8D-8D-8D) mode *****/

    /* Length of command sequence */
#define XSPI_IP_SFDP_2DOPI_CMD_LEN_SHIFT          24U
#define XSPI_IP_SFDP_2DOPI_CMD_LEN_WIDTH          8U
    /* Bytes of command sequence */
#define XSPI_IP_SFDP_2DOPI_CMD_BYTE1_SHIFT          16U
#define XSPI_IP_SFDP_2DOPI_CMD_BYTE2_SHIFT          8U
#define XSPI_IP_SFDP_2DOPI_CMD_BYTE3_SHIFT          0U
#define XSPI_IP_SFDP_2DOPI_CMD_BYTE4_SHIFT          24U
#define XSPI_IP_SFDP_2DOPI_CMD_BYTE5_SHIFT          16U
#define XSPI_IP_SFDP_2DOPI_CMD_BYTE6_SHIFT          8U
#define XSPI_IP_SFDP_2DOPI_CMD_BYTE7_SHIFT          0U

    /**** Constants for retrieving SFDP parameters - 4-byte Address Instructions *****/

#define XSPI_IP_SFDP_4BADD_INSTR_SUP_DWORD           1U
#define XSPI_IP_SFDP_4BADD_INSTR_SUP_WIDTH           1U
#define XSPI_IP_SFDP_4BADD_ERASE_INST_DWORD          2U
#define XSPI_IP_SFDP_4BADD_ERASE_INST_WIDTH          8U
#define XSPI_IP_SFDP_4BADD_ERASE1_SUP_SHIFT          9U
#define XSPI_IP_SFDP_4BADD_ERASE2_SUP_SHIFT          10U
#define XSPI_IP_SFDP_4BADD_ERASE3_SUP_SHIFT          11U
#define XSPI_IP_SFDP_4BADD_ERASE4_SUP_SHIFT          12U
#define XSPI_IP_SFDP_4BADD_ERASE1_INST_SHIFT         0U
#define XSPI_IP_SFDP_4BADD_ERASE2_INST_SHIFT         8U
#define XSPI_IP_SFDP_4BADD_ERASE3_INST_SHIFT         16U
#define XSPI_IP_SFDP_4BADD_ERASE4_INST_SHIFT         24U

#define  XSPI_IP_SFDP_4BADD_READ112_SUP_DWORD           1U
#define  XSPI_IP_SFDP_4BADD_READ122_SUP_DWORD           1U
#define  XSPI_IP_SFDP_4BADD_READ114_SUP_DWORD           1U
#define  XSPI_IP_SFDP_4BADD_READ144_SUP_DWORD           1U
#define  XSPI_IP_SFDP_4BADD_READ444_SUP_DWORD           0xFFU     /* invalid */
#define  XSPI_IP_SFDP_4BADD_READ118_SUP_DWORD           1U
#define  XSPI_IP_SFDP_4BADD_READ188_SUP_DWORD           1U

#define  XSPI_IP_SFDP_4BADD_READ111_SUP_SHIFT           0U
#define  XSPI_IP_SFDP_4BADD_READ112_SUP_SHIFT           2U
#define  XSPI_IP_SFDP_4BADD_READ122_SUP_SHIFT           3U
#define  XSPI_IP_SFDP_4BADD_READ114_SUP_SHIFT           4U
#define  XSPI_IP_SFDP_4BADD_READ144_SUP_SHIFT           5U
#define  XSPI_IP_SFDP_4BADD_READ444_SUP_SHIFT           1U       /* use 1-1-1 fast read */
#define  XSPI_IP_SFDP_4BADD_READ118_SUP_SHIFT           20U
#define  XSPI_IP_SFDP_4BADD_READ188_SUP_SHIFT           21U


#define  XSPI_IP_SFDP_4BADD_WRITE112_SUP_DWORD           0xFFU     /* invalid */
#define  XSPI_IP_SFDP_4BADD_WRITE122_SUP_DWORD           0xFFU     /* invalid */
#define  XSPI_IP_SFDP_4BADD_WRITE114_SUP_DWORD           1U
#define  XSPI_IP_SFDP_4BADD_WRITE144_SUP_DWORD           1U
#define  XSPI_IP_SFDP_4BADD_WRITE444_SUP_DWORD           1U
#define  XSPI_IP_SFDP_4BADD_WRITE118_SUP_DWORD           1U
#define  XSPI_IP_SFDP_4BADD_WRITE188_SUP_DWORD           1U

#define  XSPI_IP_SFDP_4BADD_WRITE112_SUP_SHIFT           0U
#define  XSPI_IP_SFDP_4BADD_WRITE122_SUP_SHIFT           0U
#define  XSPI_IP_SFDP_4BADD_WRITE114_SUP_SHIFT           7U
#define  XSPI_IP_SFDP_4BADD_WRITE144_SUP_SHIFT           8U
#define  XSPI_IP_SFDP_4BADD_WRITE444_SUP_SHIFT           6U      /* use 1-1-1 write */
#define  XSPI_IP_SFDP_4BADD_WRITE118_SUP_SHIFT           23U
#define  XSPI_IP_SFDP_4BADD_WRITE188_SUP_SHIFT           24U

/* fast read modes */
#define  XSPI_IP_SFDP_READ_MODE_444                      0x04U  /* 4-4-4 fast read mode            */
#define  XSPI_IP_SFDP_READ_MODE_MAX                      0x07U  /* Number of read modes            */


/*******************************************************************************
 * Enumerations.
 ******************************************************************************/

#if (XSPI_IP_MEM_INSTANCE_COUNT > 0)

/* sfdp modes */
typedef enum
{
    XSPI_IP_SFDP_1S_1S_1S  = 0x00U,   /*!< 1S-1S-1S mode */
    XSPI_IP_SFDP_2S_2S_2S  = 0x01U,   /*!< 2S-2S-2S mode */
    XSPI_IP_SFDP_4S_4S_4S  = 0x02U,   /*!< 4S-4S-4S mode */
    XSPI_IP_SFDP_4S_4D_4D  = 0x03U,   /*!< 4S-4D-4D mode */
    XSPI_IP_SFDP_8D_8D_8D  = 0x04U,   /*!< 8D-8D-8D mode */
    XSPI_IP_SFDP_INVALID   = 0xFFU,   /*!< Invalid mode */
} Xspi_Ip_SfdpModes;

/* sfdp table types */
typedef enum
{
    XSPI_IP_SFDP_TABLE_BASIC   = 0x00U,   /*!< Basic flash parameter table                               */
    XSPI_IP_SFDP_TABLE_4BADD   = 0x84U,   /*!< 4-byte Address Instruction Table                          */
    XSPI_IP_SFDP_TABLE_XSPI1   = 0x05U,   /*!< eXtended Serial Peripheral Interface (xSPI) Profile 1.0   */
    XSPI_IP_SFDP_TABLE_SRMAP   = 0x87U,   /*!< Status, Control and Configuration Register Map            */
    XSPI_IP_SFDP_TABLE_2DOPI   = 0x0AU,   /*!< Command Sequences to change to DOPI (8D-8D-8D) mode       */
} Xspi_Ip_SfdpTables;

/* structure containing sfdp tables */
typedef struct
{
    uint32 paramTable_basic[XSPI_IP_TABLE_SIZE_BASIC];
    uint32 paramTable_4badd[XSPI_IP_TABLE_SIZE_4BADD];
    uint32 paramTable_xspi1[XSPI_IP_TABLE_SIZE_XSPI1];
    uint32 paramTable_srmap[XSPI_IP_TABLE_SIZE_SRMAP];
    uint32 paramTable_2dopi[XSPI_IP_TABLE_SIZE_2DOPI];
    uint8 paramTableLength_basic;
    uint8 paramTableLength_4badd;
    uint8 paramTableLength_xspi1;
    uint8 paramTableLength_srmap;
    uint8 paramTableLength_2dopi;
} Xspi_Ip_SfdpTablesContainer;

/*******************************************************************************
 * Local Variables
 ******************************************************************************/

#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_16
#include "Mem_43_EXFLS_MemMap.h"

static uint16 lutCount;                     /* Current number of operations in the LUT table                               */

#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_16
#include "Mem_43_EXFLS_MemMap.h"


#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_8
#include "Mem_43_EXFLS_MemMap.h"

static uint8 initOpCount;                  /* Current number of operations in the initial operations list                 */
static uint8 basicAddrBits;                /* Current number of operations in the initial operations list                 */
static uint8 modeIndex;                    /* Index of the selected read mode                                             */

#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_8
#include "Mem_43_EXFLS_MemMap.h"


#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"

static Xspi_Ip_SfdpModes   cmdSfdpMode;     /* Current mode of the external memory (e.g. 0x02U if the current mode is 4S-4S-4S mode)   */
static Xspi_Ip_LutPadsType cmdPads;         /* Pads to use for commands (e.g. 4 if the selected operation mode is 4-4-4)   */
static Xspi_Ip_LutPadsType cmdPadsInit;     /* Number of pads used for commands in the initial state                       */

#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"


#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_BOOLEAN
#include "Mem_43_EXFLS_MemMap.h"

static boolean overflow;                    /* Either LUT or initial operations list was not big enough                    */
static boolean quadAvailable;               /* Quad mode can be used                                                       */

#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Mem_43_EXFLS_MemMap.h"


#define MEM_43_EXFLS_START_SEC_VAR_INIT_BOOLEAN
#include "Mem_43_EXFLS_MemMap.h"

static boolean bootModeLegacyXPI = (boolean)TRUE;    /* Memory device boots up in xSPI or HyperBus mode (default is XPI)   */

#define MEM_43_EXFLS_STOP_SEC_VAR_INIT_BOOLEAN
#include "Mem_43_EXFLS_MemMap.h"

/* tables for extracting parameters from SFDP table */

#define MEM_43_EXFLS_START_SEC_VAR_INIT_8
#include "Mem_43_EXFLS_MemMap.h"

static uint8 eraseInstDword[4U] = {
    XSPI_IP_SFDP_BASIC_ERASE1_INST_DWORD,
    XSPI_IP_SFDP_BASIC_ERASE2_INST_DWORD,
    XSPI_IP_SFDP_BASIC_ERASE3_INST_DWORD,
    XSPI_IP_SFDP_BASIC_ERASE4_INST_DWORD
};
static uint8 eraseInstShift[4U] = {
    XSPI_IP_SFDP_BASIC_ERASE1_INST_SHIFT,
    XSPI_IP_SFDP_BASIC_ERASE2_INST_SHIFT,
    XSPI_IP_SFDP_BASIC_ERASE3_INST_SHIFT,
    XSPI_IP_SFDP_BASIC_ERASE4_INST_SHIFT
};
static uint8 eraseInstWidth[4U] = {
    XSPI_IP_SFDP_BASIC_ERASE1_INST_WIDTH,
    XSPI_IP_SFDP_BASIC_ERASE2_INST_WIDTH,
    XSPI_IP_SFDP_BASIC_ERASE3_INST_WIDTH,
    XSPI_IP_SFDP_BASIC_ERASE4_INST_WIDTH
};
static uint8 eraseSizeDword[4U] = {
    XSPI_IP_SFDP_BASIC_ERASE1_SIZE_DWORD,
    XSPI_IP_SFDP_BASIC_ERASE2_SIZE_DWORD,
    XSPI_IP_SFDP_BASIC_ERASE3_SIZE_DWORD,
    XSPI_IP_SFDP_BASIC_ERASE4_SIZE_DWORD
};
static uint8 eraseSizeShift[4U] = {
    XSPI_IP_SFDP_BASIC_ERASE1_SIZE_SHIFT,
    XSPI_IP_SFDP_BASIC_ERASE2_SIZE_SHIFT,
    XSPI_IP_SFDP_BASIC_ERASE3_SIZE_SHIFT,
    XSPI_IP_SFDP_BASIC_ERASE4_SIZE_SHIFT
};
static uint8 eraseSizeWidth[4U] = {
    XSPI_IP_SFDP_BASIC_ERASE1_SIZE_WIDTH,
    XSPI_IP_SFDP_BASIC_ERASE2_SIZE_WIDTH,
    XSPI_IP_SFDP_BASIC_ERASE3_SIZE_WIDTH,
    XSPI_IP_SFDP_BASIC_ERASE4_SIZE_WIDTH
};

static uint8 erase4ByteSupShift[4U] = {
    XSPI_IP_SFDP_4BADD_ERASE1_SUP_SHIFT,
    XSPI_IP_SFDP_4BADD_ERASE2_SUP_SHIFT,
    XSPI_IP_SFDP_4BADD_ERASE3_SUP_SHIFT,
    XSPI_IP_SFDP_4BADD_ERASE4_SUP_SHIFT
};

static uint8 erase4ByteInstShift[4U] = {
    XSPI_IP_SFDP_4BADD_ERASE1_INST_SHIFT,
    XSPI_IP_SFDP_4BADD_ERASE2_INST_SHIFT,
    XSPI_IP_SFDP_4BADD_ERASE3_INST_SHIFT,
    XSPI_IP_SFDP_4BADD_ERASE4_INST_SHIFT
};

/* Erase instruction with 4-Byte Address, specified by JESD216D */
static uint8 erase4ByteInst[4U] = {
    0x21U,                                  /*   4-KB erase */
    0x5CU,                                  /*  32-KB erase */
    0xDCU,                                  /*  64-KB erase */
    0xDCU                                   /* 256-KB erase */
};

static uint8 dopiSwitchShift[7U] = {
    XSPI_IP_SFDP_2DOPI_CMD_BYTE1_SHIFT,
    XSPI_IP_SFDP_2DOPI_CMD_BYTE2_SHIFT,
    XSPI_IP_SFDP_2DOPI_CMD_BYTE3_SHIFT,
    XSPI_IP_SFDP_2DOPI_CMD_BYTE4_SHIFT,
    XSPI_IP_SFDP_2DOPI_CMD_BYTE5_SHIFT,
    XSPI_IP_SFDP_2DOPI_CMD_BYTE6_SHIFT,
    XSPI_IP_SFDP_2DOPI_CMD_BYTE7_SHIFT,
};
static uint8 dopiSwitchWord[7U] = {
    0U,
    0U,
    0U,
    1U,
    1U,
    1U,
    1U,
};

static uint8 readSupDword[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_SFDP_BASIC_READ112_SUP_DWORD,
    XSPI_IP_SFDP_BASIC_READ122_SUP_DWORD,
    XSPI_IP_SFDP_BASIC_READ114_SUP_DWORD,
    XSPI_IP_SFDP_BASIC_READ144_SUP_DWORD,
    XSPI_IP_SFDP_BASIC_READ444_SUP_DWORD,
    XSPI_IP_SFDP_BASIC_READ118_SUP_DWORD,
    XSPI_IP_SFDP_BASIC_READ188_SUP_DWORD
};

static uint8 readSupShift[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_SFDP_BASIC_READ112_SUP_SHIFT,
    XSPI_IP_SFDP_BASIC_READ122_SUP_SHIFT,
    XSPI_IP_SFDP_BASIC_READ114_SUP_SHIFT,
    XSPI_IP_SFDP_BASIC_READ144_SUP_SHIFT,
    XSPI_IP_SFDP_BASIC_READ444_SUP_SHIFT,
    XSPI_IP_SFDP_BASIC_READ118_SUP_SHIFT,
    XSPI_IP_SFDP_BASIC_READ188_SUP_SHIFT
};

static uint8 readSupWitdh[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_SFDP_BASIC_READ112_SUP_WIDTH,
    XSPI_IP_SFDP_BASIC_READ122_SUP_WIDTH,
    XSPI_IP_SFDP_BASIC_READ114_SUP_WIDTH,
    XSPI_IP_SFDP_BASIC_READ144_SUP_WIDTH,
    XSPI_IP_SFDP_BASIC_READ444_SUP_WIDTH,
    XSPI_IP_SFDP_BASIC_READ118_SUP_WIDTH,
    XSPI_IP_SFDP_BASIC_READ188_SUP_WIDTH
};

static uint8 read4ByteSupDword[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_SFDP_4BADD_READ112_SUP_DWORD,
    XSPI_IP_SFDP_4BADD_READ122_SUP_DWORD,
    XSPI_IP_SFDP_4BADD_READ114_SUP_DWORD,
    XSPI_IP_SFDP_4BADD_READ144_SUP_DWORD,
    XSPI_IP_SFDP_4BADD_READ444_SUP_DWORD,
    XSPI_IP_SFDP_4BADD_READ118_SUP_DWORD,
    XSPI_IP_SFDP_4BADD_READ188_SUP_DWORD
};

static uint8 read4ByteSupShift[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_SFDP_4BADD_READ112_SUP_SHIFT,
    XSPI_IP_SFDP_4BADD_READ122_SUP_SHIFT,
    XSPI_IP_SFDP_4BADD_READ114_SUP_SHIFT,
    XSPI_IP_SFDP_4BADD_READ144_SUP_SHIFT,
    XSPI_IP_SFDP_4BADD_READ444_SUP_SHIFT,
    XSPI_IP_SFDP_4BADD_READ118_SUP_SHIFT,
    XSPI_IP_SFDP_4BADD_READ188_SUP_SHIFT
};

static uint8 write4ByteSupDword[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_SFDP_4BADD_WRITE112_SUP_DWORD,
    XSPI_IP_SFDP_4BADD_WRITE122_SUP_DWORD,
    XSPI_IP_SFDP_4BADD_WRITE114_SUP_DWORD,
    XSPI_IP_SFDP_4BADD_WRITE144_SUP_DWORD,
    XSPI_IP_SFDP_4BADD_WRITE444_SUP_DWORD,
    XSPI_IP_SFDP_4BADD_WRITE118_SUP_DWORD,
    XSPI_IP_SFDP_4BADD_WRITE188_SUP_DWORD
};

static uint8 write4ByteSupShift[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_SFDP_4BADD_WRITE112_SUP_SHIFT,
    XSPI_IP_SFDP_4BADD_WRITE122_SUP_SHIFT,
    XSPI_IP_SFDP_4BADD_WRITE114_SUP_SHIFT,
    XSPI_IP_SFDP_4BADD_WRITE144_SUP_SHIFT,
    XSPI_IP_SFDP_4BADD_WRITE444_SUP_SHIFT,
    XSPI_IP_SFDP_4BADD_WRITE118_SUP_SHIFT,
    XSPI_IP_SFDP_4BADD_WRITE188_SUP_SHIFT
};

static uint8 read4ByteInst[XSPI_IP_SFDP_READ_MODE_MAX] = {
    0x3CU,
    0xBCU,
    0x6CU,
    0xECU,
    0x13U,
    0x7CU,
    0xCCU
};

static uint8 write4ByteInst[XSPI_IP_SFDP_READ_MODE_MAX] = {
    0x00U,
    0x00U,
    0x34U,
    0x3EU,
    0x12U,
    0x84U,
    0x8EU
};

static uint8 readInstDword[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_SFDP_BASIC_READ112_INST_DWORD,
    XSPI_IP_SFDP_BASIC_READ122_INST_DWORD,
    XSPI_IP_SFDP_BASIC_READ114_INST_DWORD,
    XSPI_IP_SFDP_BASIC_READ144_INST_DWORD,
    XSPI_IP_SFDP_BASIC_READ444_INST_DWORD,
    XSPI_IP_SFDP_BASIC_READ118_INST_DWORD,
    XSPI_IP_SFDP_BASIC_READ188_INST_DWORD
};

static uint8 readInstShift[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_SFDP_BASIC_READ112_INST_SHIFT,
    XSPI_IP_SFDP_BASIC_READ122_INST_SHIFT,
    XSPI_IP_SFDP_BASIC_READ114_INST_SHIFT,
    XSPI_IP_SFDP_BASIC_READ144_INST_SHIFT,
    XSPI_IP_SFDP_BASIC_READ444_INST_SHIFT,
    XSPI_IP_SFDP_BASIC_READ118_INST_SHIFT,
    XSPI_IP_SFDP_BASIC_READ188_INST_SHIFT
};

static uint8 readInstWidth[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_SFDP_BASIC_READ112_INST_WIDTH,
    XSPI_IP_SFDP_BASIC_READ122_INST_WIDTH,
    XSPI_IP_SFDP_BASIC_READ114_INST_WIDTH,
    XSPI_IP_SFDP_BASIC_READ144_INST_WIDTH,
    XSPI_IP_SFDP_BASIC_READ444_INST_WIDTH,
    XSPI_IP_SFDP_BASIC_READ118_INST_WIDTH,
    XSPI_IP_SFDP_BASIC_READ188_INST_WIDTH
};

static uint8 readModeDword[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_SFDP_BASIC_READ112_MODE_DWORD,
    XSPI_IP_SFDP_BASIC_READ122_MODE_DWORD,
    XSPI_IP_SFDP_BASIC_READ114_MODE_DWORD,
    XSPI_IP_SFDP_BASIC_READ144_MODE_DWORD,
    XSPI_IP_SFDP_BASIC_READ444_MODE_DWORD,
    XSPI_IP_SFDP_BASIC_READ118_MODE_DWORD,
    XSPI_IP_SFDP_BASIC_READ188_MODE_DWORD
};

static uint8 readModeShift[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_SFDP_BASIC_READ112_MODE_SHIFT,
    XSPI_IP_SFDP_BASIC_READ122_MODE_SHIFT,
    XSPI_IP_SFDP_BASIC_READ114_MODE_SHIFT,
    XSPI_IP_SFDP_BASIC_READ144_MODE_SHIFT,
    XSPI_IP_SFDP_BASIC_READ444_MODE_SHIFT,
    XSPI_IP_SFDP_BASIC_READ118_MODE_SHIFT,
    XSPI_IP_SFDP_BASIC_READ188_MODE_SHIFT
};

static uint8 readModeWidth[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_SFDP_BASIC_READ112_MODE_WIDTH,
    XSPI_IP_SFDP_BASIC_READ122_MODE_WIDTH,
    XSPI_IP_SFDP_BASIC_READ114_MODE_WIDTH,
    XSPI_IP_SFDP_BASIC_READ144_MODE_WIDTH,
    XSPI_IP_SFDP_BASIC_READ444_MODE_WIDTH,
    XSPI_IP_SFDP_BASIC_READ118_MODE_WIDTH,
    XSPI_IP_SFDP_BASIC_READ188_MODE_WIDTH
};

static uint8 readDummyDword[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_SFDP_BASIC_READ112_DUMMY_DWORD,
    XSPI_IP_SFDP_BASIC_READ122_DUMMY_DWORD,
    XSPI_IP_SFDP_BASIC_READ114_DUMMY_DWORD,
    XSPI_IP_SFDP_BASIC_READ144_DUMMY_DWORD,
    XSPI_IP_SFDP_BASIC_READ444_DUMMY_DWORD,
    XSPI_IP_SFDP_BASIC_READ118_DUMMY_DWORD,
    XSPI_IP_SFDP_BASIC_READ188_DUMMY_DWORD
};

static uint8 readDummyShift[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_SFDP_BASIC_READ112_DUMMY_SHIFT,
    XSPI_IP_SFDP_BASIC_READ122_DUMMY_SHIFT,
    XSPI_IP_SFDP_BASIC_READ114_DUMMY_SHIFT,
    XSPI_IP_SFDP_BASIC_READ144_DUMMY_SHIFT,
    XSPI_IP_SFDP_BASIC_READ444_DUMMY_SHIFT,
    XSPI_IP_SFDP_BASIC_READ118_DUMMY_SHIFT,
    XSPI_IP_SFDP_BASIC_READ188_DUMMY_SHIFT
};

static uint8 readDummyWidth[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_SFDP_BASIC_READ112_DUMMY_WIDTH,
    XSPI_IP_SFDP_BASIC_READ122_DUMMY_WIDTH,
    XSPI_IP_SFDP_BASIC_READ114_DUMMY_WIDTH,
    XSPI_IP_SFDP_BASIC_READ144_DUMMY_WIDTH,
    XSPI_IP_SFDP_BASIC_READ444_DUMMY_WIDTH,
    XSPI_IP_SFDP_BASIC_READ118_DUMMY_WIDTH,
    XSPI_IP_SFDP_BASIC_READ188_DUMMY_WIDTH
};

#define MEM_43_EXFLS_STOP_SEC_VAR_INIT_8
#include "Mem_43_EXFLS_MemMap.h"


#define MEM_43_EXFLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"
/*Store Hif base address for call Xspi_Ip_IpCommand, Xspi_Ip_IpRead */
static XSPI_Type * HifBaseAddr;

static Xspi_Ip_LutPadsType readModeInstPads[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_LUT_PADS_1,
    XSPI_IP_LUT_PADS_1,
    XSPI_IP_LUT_PADS_1,
    XSPI_IP_LUT_PADS_1,
    XSPI_IP_LUT_PADS_4,
    XSPI_IP_LUT_PADS_1,
    XSPI_IP_LUT_PADS_1
};

static Xspi_Ip_LutPadsType readModeAddrPads[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_LUT_PADS_1,
    XSPI_IP_LUT_PADS_2,
    XSPI_IP_LUT_PADS_1,
    XSPI_IP_LUT_PADS_4,
    XSPI_IP_LUT_PADS_4,
    XSPI_IP_LUT_PADS_1,
    XSPI_IP_LUT_PADS_8
};

static Xspi_Ip_LutPadsType readModeDataPads[XSPI_IP_SFDP_READ_MODE_MAX] = {
    XSPI_IP_LUT_PADS_2,
    XSPI_IP_LUT_PADS_2,
    XSPI_IP_LUT_PADS_4,
    XSPI_IP_LUT_PADS_4,
    XSPI_IP_LUT_PADS_4,
    XSPI_IP_LUT_PADS_8,
    XSPI_IP_LUT_PADS_8
};

#define MEM_43_EXFLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"


/*==================================================================================================
 *LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

static inline Xspi_Ip_InstrOpType Xspi_Ip_PackLut(Xspi_Ip_LutCommandsType cmd,
                                                  Xspi_Ip_LutPadsType pad,
                                                  uint8 op
                                                 );

static inline void Xspi_Ip_SfdpLutInit(void);

static inline void Xspi_Ip_SfdpLutAdd(const Xspi_Ip_LutConfigType *lutSequences,
                                      Xspi_Ip_InstrOpType instr
                                     );

static inline uint32 Xspi_Ip_SfdpGetBasicParam(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                               uint8 dword,
                                               uint8 shift,
                                               uint8 width,
                                               uint32 defaultValue
                                              );

static inline uint32 Xspi_Ip_SfdpGet4BAddParam(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                               uint8 dword,
                                               uint8 shift,
                                               uint8 width,
                                               uint32 defaultValue
                                              );

static inline uint32 Xspi_Ip_SfdpGetXspi1Param(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                               uint8 dword,
                                               uint8 shift,
                                               uint8 width,
                                               uint32 defaultValue
                                              );

static inline uint32 Xspi_Ip_SfdpGetSRMapParam(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                               uint8 dword,
                                               uint8 shift,
                                               uint8 width,
                                               uint32 defaultValue
                                              );

static inline uint32 Xspi_Ip_SfdpGet2DopiParam(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                               uint8 dword,
                                               uint8 shift,
                                               uint8 width,
                                               uint32 defaultValue
                                              );

static void Xspi_Ip_SfdpLutAddSrAddr(const Xspi_Ip_LutConfigType *lutSequences,
                                     const Xspi_Ip_SfdpTablesContainer *sfdpTables
                                    );

static inline boolean Xspi_Ip_SfdpSignatureCheck(const uint8 *data);

static inline void Xspi_Ip_SfdpInitLut(uint32 instance,
                                       Xspi_Ip_SfdpModes mode
                                      );

static void Xspi_Ip_WaitAfterReset(void);

static void Xspi_Ip_SfdpInitReset(uint32 instance,
                                  uint32 baseAddress
                                 );

static void Xspi_Ip_SfdpInitReset_4S4S4S(uint32 instance,
                                         uint32 baseAddress
                                        );

static void Xspi_Ip_SfdpExitQPI(uint32 instance,
                                uint32 baseAddress
                               );


static void Xspi_Ip_SfdpInitReset_8D8D8D(uint32 instance,
                                         uint32 baseAddress
                                        );

static void Xspi_Ip_SfdpPackLutEnterLegacySPI(uint32 sequenceIndex,
                                              Xspi_Ip_InstrOpType *lutData
                                             );

static void Xspi_Ip_SfdpLutInitEnterLegacySPI(Xspi_Ip_MemoryConfigType const *pConfig);

static void Xspi_Ip_SfdpEnterLegacySPI(uint32 instance);

static void Xspi_Ip_SfdpExitDOPI(uint32 instance,
                                 uint32 baseAddress
                                );

static Xspi_Ip_StatusType Xspi_Ip_SfdpCheck(uint32 instance,
                                            uint32 baseAddress
                                           );

static Xspi_Ip_SfdpModes Xspi_Ip_SfdpFindWorkingMode(uint32 instance,
                                                      uint32 baseAddress
                                                     );

static inline boolean Xspi_Ip_SfdpCheckMinorRevision(uint8 minorRevision);

static inline uint8 Xspi_Ip_SfdpGetCmdExt(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                          uint8 instruction
                                         );

static inline uint32 Xspi_Ip_SfdpGetParamTableAddress(const uint8 * paramHeader,
                                                      uint8 accessProtocol
                                                     );

static inline boolean Xspi_Ip_SfdpCheckNewerRevision(uint8 paramIdLSB,
                                                     uint8 tableType,
                                                     uint8 majorRevision,
                                                     uint8 minorRevision,
                                                     sint16 minorRevisionMax
                                                    );

static Xspi_Ip_StatusType Xspi_Ip_SfdpFindTable(uint32 baseAddress,
                                                Xspi_Ip_SfdpTables tableType,
                                                uint32 * paramTable,
                                                uint8 * paramTableLength
                                               );

static Xspi_Ip_StatusType Xspi_Ip_SfdpReadTables(uint32 baseAddress,
                                                 Xspi_Ip_SfdpTablesContainer *sfdpTables
                                                );

static void Xspi_Ip_SfdpInitSimpleCmd(uint8 cmd,
                                      const Xspi_Ip_MemoryConfigType *pConfig
                                     );

static uint8 Xspi_Ip_SfdpGetWeSrInstr(const Xspi_Ip_SfdpTablesContainer *sfdpTables);

static void Xspi_Ip_SfdpInitWriteReg(uint8 cmd,
                                     uint8 wrenCmd,
                                     uint8 size,
                                     uint32 value,
                                     const Xspi_Ip_MemoryConfigType *pConfig
                                    );

static Xspi_Ip_StatusType Xspi_Ip_Sfdp4byteAddrSwitch_01(const Xspi_Ip_MemoryConfigType * pConfig);
static Xspi_Ip_StatusType Xspi_Ip_Sfdp4byteAddrSwitch_02(const Xspi_Ip_MemoryConfigType * pConfig);
static Xspi_Ip_StatusType Xspi_Ip_Sfdp4byteAddrSwitch_08(const Xspi_Ip_MemoryConfigType * pConfig);
static Xspi_Ip_StatusType Xspi_Ip_Sfdp4byteAddrSwitch_16(const Xspi_Ip_MemoryConfigType * pConfig);

static Xspi_Ip_StatusType Xspi_Ip_Sfdp4byteAddrSwitch(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                                      const Xspi_Ip_MemoryConfigType *pConfig
                                                     );

static void Xspi_Ip_SfdpGetBasicAddrBits(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                         const Xspi_Ip_MemoryConfigType *pConfig
                                        );

static void Xspi_Ip_SfdpConfigureQE(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                    const Xspi_Ip_MemoryConfigType *pConfig
                                   );

static Xspi_Ip_LutCommandsType Xspi_Ip_SfdpGetModeInstr(uint8 modeClocks,
                                                        Xspi_Ip_LutPadsType addrPads
                                                       );

static void Xspi_Ip_SfdpGetSpiReadInstr(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                        uint8 cnt,
                                        uint8 *instruction,
                                        uint8 *addrBits
                                       );

static void Xspi_Ip_SfdpConfigBasicRead(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                        Xspi_Ip_MemoryConfigType *pConfig
                                       );

static Xspi_Ip_StatusType Xspi_Ip_Sfdp444Switch_01(const Xspi_Ip_MemoryConfigType * pConfig);
static Xspi_Ip_StatusType Xspi_Ip_Sfdp444Switch_04(const Xspi_Ip_MemoryConfigType * pConfig);
static Xspi_Ip_StatusType Xspi_Ip_Sfdp444Switch_08(const Xspi_Ip_MemoryConfigType * pConfig);
static Xspi_Ip_StatusType Xspi_Ip_Sfdp444Switch_16(const Xspi_Ip_MemoryConfigType * pConfig);

static Xspi_Ip_StatusType Xspi_Ip_Sfdp444Switch(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                                const Xspi_Ip_MemoryConfigType *pConfig
                                               );

static void Xspi_Ip_SfdpGetBasicFastReadInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                         Xspi_Ip_MemoryConfigType *pConfig
                                        );

static void Xspi_Ip_SfdpGetBasicWriteInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                          Xspi_Ip_MemoryConfigType *pConfig
                                         );

static void Xspi_Ip_SfdpGetXspi1ReadInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                         Xspi_Ip_MemoryConfigType * pConfig,
                                         uint32 instance,
                                         uint32 baseAddress
                                        );

static void Xspi_Ip_SfdpGetXspi1WriteInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                          Xspi_Ip_MemoryConfigType *pConfig
                                         );

static uint8 Xspi_Ip_SfdpGetBasicEraseInstr(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                            uint8 cnt,
                                            uint8 *addrbits
                                           );

static uint8 Xspi_Ip_SfdpGetXspi1EraseInstr(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                            uint8 cnt);

static void Xspi_Ip_SfdpGetBasicEraseInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                          Xspi_Ip_MemoryConfigType *pConfig
                                         );

static void Xspi_Ip_SfdpGetXspi1EraseInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                          Xspi_Ip_MemoryConfigType *pConfig
                                         );

static void Xspi_Ip_SfdpConfigureReadStatus(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                                Xspi_Ip_MemoryConfigType *pConfig
                                               );

static void Xspi_Ip_SfdpGetBasicStatusInfo(Xspi_Ip_MemoryConfigType *pConfig);

static void Xspi_Ip_SfdpGetXspi1StatusInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                           Xspi_Ip_MemoryConfigType *pConfig
                                          );

static void Xspi_Ip_SfdpConfigReset1(const Xspi_Ip_MemoryConfigType *pConfig,
                                     const Xspi_Ip_ResetConfigType *resetSettings,
                                     Xspi_Ip_LutPadsType pads
                                    );

static void Xspi_Ip_SfdpConfigReset2(const Xspi_Ip_MemoryConfigType *pConfig,
                                     const Xspi_Ip_ResetConfigType *resetSettings,
                                     Xspi_Ip_LutPadsType pads
                                    );

static void Xspi_Ip_SfdpConfigReset4(const Xspi_Ip_MemoryConfigType *pConfig,
                                     const Xspi_Ip_ResetConfigType *resetSettings,
                                     Xspi_Ip_LutPadsType pads
                                    );

static void Xspi_Ip_SfdpConfigReset8(const Xspi_Ip_MemoryConfigType *pConfig,
                                     Xspi_Ip_ResetConfigType *resetSettings,
                                     Xspi_Ip_LutPadsType pads
                                    );

static void Xspi_Ip_SfdpConfigReset16(const Xspi_Ip_MemoryConfigType *pConfig,
                                      Xspi_Ip_ResetConfigType *resetSettings,
                                      Xspi_Ip_LutPadsType pads
                                     );

static void Xspi_Ip_SfdpConfigResetOthers(uint8 resetOption,
                                          const Xspi_Ip_MemoryConfigType * pConfig,
                                          Xspi_Ip_ResetConfigType *resetSettings,
                                          Xspi_Ip_LutPadsType pads
                                         );

static void Xspi_Ip_SfdpGetBasicResetInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                          const Xspi_Ip_MemoryConfigType *pConfig,
                                          Xspi_Ip_ResetConfigType *resetSettings,
                                          Xspi_Ip_LutPadsType pads
                                         );

static void Xspi_Ip_SfdpGetXspi1InitResetInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                              Xspi_Ip_MemoryConfigType *pConfig
                                             );

static void Xspi_Ip_SfdpGetBasicSuspendInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                            Xspi_Ip_MemoryConfigType *pConfig
                                           );

static void Xspi_Ip_SfdpGetXspi1SuspendInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                            Xspi_Ip_MemoryConfigType *pConfig
                                           );

static void Xspi_Ip_SfdpAdd2dopiOperation(const Xspi_Ip_MemoryConfigType *pConfig,
                                          uint8 seqSize,
                                          const uint32 *words
                                         );

static void Xspi_Ip_SfdpAddCheckBusyOperation(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                           const Xspi_Ip_MemoryConfigType *pConfig);

static void Xspi_Ip_SfdpGetXspi1InitOpInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                           Xspi_Ip_MemoryConfigType *pConfig
                                          );

static void Xspi_Ip_SfdpGetBasicInitOpInfo(Xspi_Ip_MemoryConfigType *pConfig);

static void Xspi_Ip_SfdpGet0xxInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                   Xspi_Ip_MemoryConfigType *pConfig
                                  );

static void Xspi_Ip_SfdpConfigureOther(Xspi_Ip_MemoryConfigType *pConfig);

static void Xspi_Ip_SfdpGetSize(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                Xspi_Ip_MemoryConfigType *pConfig
                               );

static Xspi_Ip_StatusType Xspi_Ip_ConfigureBasic(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                                 Xspi_Ip_MemoryConfigType *pConfig
                                                );

static Xspi_Ip_StatusType Xspi_Ip_ConfigureXspi1(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                                 Xspi_Ip_MemoryConfigType *pConfig,
                                                 uint32 instance,
                                                 uint32 baseAddress
                                                );

static inline void Xspi_Ip_SfdpGetBasicInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                            Xspi_Ip_MemoryConfigType *pConfig
                                           );

static inline void Xspi_Ip_SfdpGetXspi1Info(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                            Xspi_Ip_MemoryConfigType *pConfig,
                                            uint32 instance,
                                            uint32 baseAddress
                                           );

void Xspi_Ip_Sfdp_Set_LutPhysical(Xspi_Ip_MemoryConfigType *pConfig);

#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"


/*******************************************************************************
 * Private Functions
 ******************************************************************************/

#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_PackLut
 * Description   : Packs command, pads count and operand in a LUT entry
 */
static inline Xspi_Ip_InstrOpType Xspi_Ip_PackLut(Xspi_Ip_LutCommandsType cmd,
                                                  Xspi_Ip_LutPadsType pad,
                                                  uint8 op
                                                 )
{
    return (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)cmd | (Xspi_Ip_InstrOpType)pad | (Xspi_Ip_InstrOpType)op);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpLutInit
 * Description   : Initializes LUT and init operations counters
 */
static inline void Xspi_Ip_SfdpLutInit(void)
{
    lutCount = 0U;
    initOpCount = 0U;
    overflow = FALSE;
    quadAvailable = TRUE;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpLutAdd
 * Description   : Initializes LUT and init operations counters
 */
static inline void Xspi_Ip_SfdpLutAdd(const Xspi_Ip_LutConfigType *lutSequences,
                                      Xspi_Ip_InstrOpType instr
                                     )
{
    if (lutCount < lutSequences->opCount)
    {
        lutSequences->lutOps[lutCount] = instr;
        lutCount++;
    }
    else
    {
        overflow = TRUE;
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetBasicParam
 * Description   : Returns a bitfield from the SFDP tables
 */
static inline uint32 Xspi_Ip_SfdpGetBasicParam(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                               uint8 dword,
                                               uint8 shift,
                                               uint8 width,
                                               uint32 defaultValue
                                              )
{
    const uint32* tablePtr  = NULL_PTR;
    uint8 tableSize         = 0U;
    volatile uint32 mask    = 0UL;
    volatile uint32 result  = 0UL;

    tablePtr  = sfdpTables->paramTable_basic;
    tableSize = sfdpTables->paramTableLength_basic;

    if ((NULL_PTR != tablePtr) && (dword <= tableSize) && (dword > 0U))
    {
        /* get required field */
        if(width < 32U)
        {
            mask   = (1UL << (uint32)(width)) - 1UL;
        }
        else
        {
            mask = 0xFFFFFFFFU;
        }

        if(shift < 32U)
        {
            result = ((uint32)(tablePtr[dword - 1U] >> shift)) & mask;
        }
    }
    else
    {
        /* table too short, use default */
        result = defaultValue;
    }

    return result;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGet4BAddParam
 * Description   : Returns a bitfield from the SFDP tables
 */
static inline uint32 Xspi_Ip_SfdpGet4BAddParam(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                               uint8 dword,
                                               uint8 shift,
                                               uint8 width,
                                               uint32 defaultValue
                                              )
{
    const uint32* tablePtr  = NULL_PTR;
    uint8 tableSize         = 0U;
    volatile uint32 mask    = 0UL;
    volatile uint32 result  = 0UL;

    tablePtr  = sfdpTables->paramTable_4badd;
    tableSize = sfdpTables->paramTableLength_4badd;

    if ((NULL_PTR != tablePtr) && (dword <= tableSize) && (dword > 0U))
    {
        /* get required field */
        if(width < 32U)
        {
            mask   = (1UL << (uint32)(width)) - 1UL;
        }
        else
        {
            mask = 0xFFFFFFFFU;
        }

        if(shift < 32U)
        {
            result = ((uint32)(tablePtr[dword - 1U] >> shift)) & mask;
        }
    }
    else
    {
        /* table too short, use default */
        result = defaultValue;
    }

    return result;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetXspi1Param
 * Description   : Returns a bitfield from the SFDP tables
 */
static inline uint32 Xspi_Ip_SfdpGetXspi1Param(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                               uint8 dword,
                                               uint8 shift,
                                               uint8 width,
                                               uint32 defaultValue
                                              )
{
    const uint32* tablePtr  = NULL_PTR;
    uint8 tableSize         = 0U;
    volatile uint32 mask    = 0UL;
    volatile uint32 result  = 0UL;

    tablePtr  = sfdpTables->paramTable_xspi1;
    tableSize = sfdpTables->paramTableLength_xspi1;

    if ((NULL_PTR != tablePtr) && (dword <= tableSize) )
    {
        /* get required field */
        mask   = (1UL << (uint32)(width)) - 1UL;
        result = ((uint32)(tablePtr[dword - 1U] >> shift)) & mask;
    }
    else
    {
        /* table too short, use default */
        result = defaultValue;
    }

    return result;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetSRMapParam
 * Description   : Returns a bitfield from the SFDP tables
 */
static inline uint32 Xspi_Ip_SfdpGetSRMapParam(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                               uint8 dword,
                                               uint8 shift,
                                               uint8 width,
                                               uint32 defaultValue
                                              )
{
    const uint32* tablePtr  = NULL_PTR;
    uint8 tableSize         = 0U;
    volatile uint32 mask    = 0UL;
    volatile uint32 result  = 0UL;

    tablePtr  = sfdpTables->paramTable_srmap;
    tableSize = sfdpTables->paramTableLength_srmap;

    if ((NULL_PTR != tablePtr) && (dword <= tableSize) && (dword > 0U))
    {
        /* get required field */
        if(width < 32U)
        {
            mask   = (1UL << (uint32)(width)) - 1UL;
        }
        else
        {
            mask = 0xFFFFFFFFU;
        }

        if(shift < 32U)
        {
            result = ((uint32)(tablePtr[dword - 1U] >> shift)) & mask;
        }
    }
    else
    {
        /* table too short, use default */
        result = defaultValue;
    }

    return result;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGet2DopiParam
 * Description   : Returns a bitfield from the SFDP tables
 */
static inline uint32 Xspi_Ip_SfdpGet2DopiParam(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                               uint8 dword,
                                               uint8 shift,
                                               uint8 width,
                                               uint32 defaultValue
                                              )
{
    const uint32* tablePtr  = NULL_PTR;
    uint8 tableSize         = 0U;
    volatile uint32 mask    = 0UL;
    volatile uint32 result  = 0UL;

    tablePtr  = sfdpTables->paramTable_2dopi;
    tableSize = sfdpTables->paramTableLength_2dopi;

    if ((NULL_PTR != tablePtr) && (dword <= tableSize) && (dword > 0U))
    {
        /* get required field */
        if(width < 32U)
        {
            mask   = (1UL << (uint32)(width)) - 1UL;
        }
        else
        {
            mask = 0xFFFFFFFFU;
        }

        if(shift < 32U)
        {
            result = ((uint32)(tablePtr[dword - 1U] >> shift)) & mask;
        }
    }
    else
    {
        /* table too short, use default */
        result = defaultValue;
    }

    return result;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpLutAddSrAddr
 * Description   : Initializes LUT and init operations counters
 */
static void Xspi_Ip_SfdpLutAddSrAddr(const Xspi_Ip_LutConfigType *lutSequences,
                                     const Xspi_Ip_SfdpTablesContainer *sfdpTables
                                    )
{
    uint32 addrOffset;
    uint8 srAddr;
    uint8 srShift;
    uint8 nBytes;
    uint8 cnt;
    uint8 directCmd;

    /* SR read is direct command (not using address */
    directCmd = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_USE_ADDR_DWORD,
                                                 XSPI_IP_SFDP_SRMAP_USE_ADDR_SHIFT, XSPI_IP_SFDP_SRMAP_USE_ADDR_WIDTH, 0x0U);
    if (directCmd == 0U)
    {
        /* direct command - nothing to do */
    }
    else
    {
        /* Address offset for volatile registers */
        addrOffset = (uint32)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_OFFSET_DWORD,
                                                       XSPI_IP_SFDP_SRMAP_OFFSET_SHIFT, XSPI_IP_SFDP_SRMAP_OFFSET_WIDTH, 0x0U);


        /* SR local address */
        srAddr = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_SR_ADDR_DWORD,
                                                  XSPI_IP_SFDP_SRMAP_SR_ADDR_SHIFT, XSPI_IP_SFDP_SRMAP_SR_ADDR_WIDTH, 0x0U);

        /* SR address shift (before adding to the offset) */
        srShift = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_SR_SHIFT_DWORD,
                                                   XSPI_IP_SFDP_SRMAP_SR_SHIFT_SHIFT, XSPI_IP_SFDP_SRMAP_SR_SHIFT_WIDTH, 0x0U);

        /* compute SR address */
        addrOffset = addrOffset + ((uint32)srAddr << (srShift * 8U));

        /* Number of address bytes used for */
        nBytes = 4U -(uint8)Xspi_Ip_SfdpGetXspi1Param(sfdpTables, XSPI_IP_SFDP_XSPI1_NBYTES_DWORD,
                                                  XSPI_IP_SFDP_XSPI1_NBYTES_SHIFT, XSPI_IP_SFDP_XSPI1_NBYTES_WIDTH, 0x0U);

        /* add address to LUT sequence. Use CMD in case addr is out of range */
        for (cnt = nBytes; cnt > 0U; cnt--)
        {
            srAddr = (uint8)((addrOffset >> ((cnt - 1U) * 8U)) & 0xFFU);
            Xspi_Ip_SfdpLutAdd(lutSequences, Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, srAddr));
        }
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpSignatureCheck
 * Description   : Checks SFDP signature
 */
static inline boolean Xspi_Ip_SfdpSignatureCheck(const uint8 *data)
{
    boolean retCode = FALSE;

    if ((data[0] == 0x53U) && (data[1] == 0x46U) && (data[2] == 0x44U) && (data[3] == 0x50U))
    {
        retCode = TRUE;
    }

    return retCode;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpInitLut
 * Description   : Initializes LUT table for reading SFDP information, using the specified format
 */
static inline void Xspi_Ip_SfdpInitLut(uint32 instance,
                                       Xspi_Ip_SfdpModes mode
                                      )
{
    Xspi_Ip_LutCommandsType instCmd;
    Xspi_Ip_LutCommandsType addrCmd;
    Xspi_Ip_LutCommandsType dataCmd;
    Xspi_Ip_LutPadsType pads;
    Xspi_Ip_InstrOpType lutData[6U];  /* Data to be written to the physical LUTs */

    /* Set command parameters according to mode */
    instCmd = XSPI_IP_LUT_INSTR_CMD;
    addrCmd = XSPI_IP_LUT_INSTR_ADDR;
    dataCmd = XSPI_IP_LUT_INSTR_READ;
    if (XSPI_IP_SFDP_8D_8D_8D == mode)
    {
        pads = XSPI_IP_LUT_PADS_8;
        instCmd = XSPI_IP_LUT_INSTR_CMD_DDR;
        addrCmd = XSPI_IP_LUT_INSTR_ADDR_DDR;
        dataCmd = XSPI_IP_LUT_INSTR_READ_DDR;
    }
    else if (XSPI_IP_SFDP_4S_4D_4D == mode)
    {
        pads = XSPI_IP_LUT_PADS_4;
        addrCmd = XSPI_IP_LUT_INSTR_ADDR_DDR;
        dataCmd = XSPI_IP_LUT_INSTR_READ_DDR;
    }
    else if (XSPI_IP_SFDP_4S_4S_4S == mode)
    {
        pads = XSPI_IP_LUT_PADS_4;
    }
    else if (XSPI_IP_SFDP_2S_2S_2S == mode)
    {
        pads = XSPI_IP_LUT_PADS_2;
    }
    else
    {
        pads = XSPI_IP_LUT_PADS_1;
    }

    if (XSPI_IP_SFDP_8D_8D_8D == mode)
    {
            /* Build SFDP Read Sequence */
        lutData[0] = Xspi_Ip_PackLut(instCmd, pads, XSPI_IP_CMD_SFDP_READ);  /* READ SFDP command on 1 data line */
        lutData[1] = Xspi_Ip_PackLut(instCmd, pads, XSPI_IP_CMD_SFDP_READ);  /* READ SFDP command on 1 data line */
        lutData[2] = Xspi_Ip_PackLut(addrCmd, pads, 32U);                    /* 32-bit address on 1 data line */
        lutData[3] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_DUMMY, pads, 8U);     /* 8 Dummy cycles */
        lutData[4] = Xspi_Ip_PackLut(dataCmd, pads, 0x10U);                  /* Read data on "pads" data lines */
        lutData[5] = XSPI_IP_LUT_SEQ_END;                                    /* End of sequence */

    }
    else
    {
        lutData[0] = Xspi_Ip_PackLut(instCmd, pads, XSPI_IP_CMD_SFDP_READ);  /* READ SFDP command on 1 data line */
        lutData[1] = Xspi_Ip_PackLut(addrCmd, pads, 24U);                    /* 24-bit address on 1 data line */
        lutData[2] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_DUMMY, pads, 8U);     /* 8 Dummy cycles */
        lutData[3] = Xspi_Ip_PackLut(dataCmd, pads, 0x10U);                  /* Read data on "pads" data lines */

        lutData[4] = XSPI_IP_LUT_SEQ_END;              /* End of sequence */
        lutData[5] = XSPI_IP_LUT_SEQ_END;              /* End of sequence */
    }
    /* Write the SFDP Read Sequence into physical LUT registers */
    Xspi_Ip_SetLutSeq(instance, XSPI_IP_COMMAND_LUT, lutData);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_WaitAfterReset
 * Description   : Wait until external memory is available for operation after a reset
 */
static void Xspi_Ip_WaitAfterReset(void)
{
    uint32  u32ElapsedTicks = 0U;
    uint32  u32TimeoutTicks;
    uint32  u32CurrentTicks;

    /* Prepare timeout counter */
    u32TimeoutTicks = OsIf_MicrosToTicks(XSPI_IP_RESET_TIMEOUT, (OsIf_CounterType)XSPI_IP_TIMEOUT_TYPE);
    u32CurrentTicks = OsIf_GetCounter((OsIf_CounterType)XSPI_IP_TIMEOUT_TYPE);
    /* Wait for the specified time */
    do
    {
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, (OsIf_CounterType)XSPI_IP_TIMEOUT_TYPE);
    }
    while (u32ElapsedTicks < u32TimeoutTicks);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpInitReset_4S4S4S
 * Description   : Sends 4S-4S-4S reset commands to force device to exit the QPI mode.
 */
static void Xspi_Ip_SfdpInitReset_4S4S4S(uint32 instance,
                                         uint32 baseAddress
                                        )
{
    /* Data to be written to the physical LUTs */
    Xspi_Ip_InstrOpType lutData[2U] =
    {
        XSPI_IP_LUT_SEQ_END,
        XSPI_IP_LUT_SEQ_END
    };

    const Xspi_Ip_LutCommandsType cmd = XSPI_IP_LUT_INSTR_CMD;
    const Xspi_Ip_LutPadsType     pad = XSPI_IP_LUT_PADS_4;

    /* Send Reset Enable Command */
    lutData[0] = Xspi_Ip_PackLut(cmd, pad, (uint8)XSPI_IP_CMD_XSPI_RESET_ENABLE);
    Xspi_Ip_SetLutSeq(instance, XSPI_IP_COMMAND_LUT, lutData);
    (void)Xspi_Ip_IpCommand(HifBaseAddr, XSPI_IP_COMMAND_LUT, baseAddress);

    /* Send Reset Command */
    lutData[0] = Xspi_Ip_PackLut(cmd, pad, (uint8)XSPI_IP_CMD_XSPI_RESET_DEF);
    Xspi_Ip_SetLutSeq(instance, XSPI_IP_COMMAND_LUT, lutData);
    (void)Xspi_Ip_IpCommand(HifBaseAddr, XSPI_IP_COMMAND_LUT, baseAddress);

    /* Wait for reset to complete */
    Xspi_Ip_WaitAfterReset();
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpExitQPI
 * Description   : Attempt to exit the memory device from QPI (4-4-4) mode.
 */
static void Xspi_Ip_SfdpExitQPI(uint32 instance,
                                uint32 baseAddress
                               )
{
    /* Workaround: send 4S-4S-4S reset command */
    Xspi_Ip_SfdpInitReset_4S4S4S(instance, baseAddress);
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpInitReset_8D8D8D
 * Description   : Sends 8D-8D-8D reset commands to force device to enter SPI mode.
 */
static void Xspi_Ip_SfdpInitReset_8D8D8D(uint32 instance,
                                         uint32 baseAddress
                                        )
{
    /* Data to be written to the physical LUTs */
    Xspi_Ip_InstrOpType lutData[4U] =
    {
        XSPI_IP_LUT_SEQ_END,
        XSPI_IP_LUT_SEQ_END,
        XSPI_IP_LUT_SEQ_END,
        XSPI_IP_LUT_SEQ_END,
    };

    const Xspi_Ip_LutCommandsType cmd = XSPI_IP_LUT_INSTR_CMD_DDR;
    const Xspi_Ip_LutPadsType     pad = XSPI_IP_LUT_PADS_8;

    /* As we don't know yet the command extension convention of the device, try both ways */
    /* 1. Command Extension is the inverse of the Command */
    /* Send Reset Enable Command */
    lutData[0] = Xspi_Ip_PackLut(cmd, pad, (uint8)XSPI_IP_CMD_XSPI_RESET_ENABLE);    /* Reset Enable command in DOPI Mode */
    lutData[1] = Xspi_Ip_PackLut(cmd, pad, (uint8)~XSPI_IP_CMD_XSPI_RESET_ENABLE);   /* command extension */
    Xspi_Ip_SetLutSeq(instance, XSPI_IP_COMMAND_LUT, lutData);
    (void)Xspi_Ip_IpCommand(HifBaseAddr, XSPI_IP_COMMAND_LUT, baseAddress);

    /* Send Reset Command */
    lutData[0] = Xspi_Ip_PackLut(cmd, pad, (uint8)XSPI_IP_CMD_XSPI_RESET_DEF);       /* Reset command in DOPI Mode */
    lutData[1] = Xspi_Ip_PackLut(cmd, pad, (uint8)~XSPI_IP_CMD_XSPI_RESET_DEF);      /* command extension */
    Xspi_Ip_SetLutSeq(instance, XSPI_IP_COMMAND_LUT, lutData);
    (void)Xspi_Ip_IpCommand(HifBaseAddr, XSPI_IP_COMMAND_LUT, baseAddress);

    /* 2. Command Extension is the same as the Command */
    /* Send Reset Enable Command */
    lutData[0] = Xspi_Ip_PackLut(cmd, pad, (uint8)XSPI_IP_CMD_XSPI_RESET_ENABLE);    /* Reset Enable command in DOPI Mode */
    lutData[1] = Xspi_Ip_PackLut(cmd, pad, (uint8)XSPI_IP_CMD_XSPI_RESET_ENABLE);   /* command extension */
    Xspi_Ip_SetLutSeq(instance, XSPI_IP_COMMAND_LUT, lutData);
    (void)Xspi_Ip_IpCommand(HifBaseAddr, XSPI_IP_COMMAND_LUT, baseAddress);

    /* Send Reset Command */
    lutData[0] = Xspi_Ip_PackLut(cmd, pad, (uint8)XSPI_IP_CMD_XSPI_RESET_DEF);      /* Reset command in DOPI Mode */
    lutData[1] = Xspi_Ip_PackLut(cmd, pad, (uint8)XSPI_IP_CMD_XSPI_RESET_DEF);      /* command extension */
    Xspi_Ip_SetLutSeq(instance, XSPI_IP_COMMAND_LUT, lutData);
    (void)Xspi_Ip_IpCommand(HifBaseAddr, XSPI_IP_COMMAND_LUT, baseAddress);

    /* Wait for reset to complete */
    Xspi_Ip_WaitAfterReset();
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpPackLutEnterLegacySPI
 * Description   : Pack the Enter Default Protocol Mode command is a sequence of three Write Register Linear commands.
 */
static void Xspi_Ip_SfdpPackLutEnterLegacySPI(uint32 sequenceIndex, Xspi_Ip_InstrOpType *lutData)
{
    /* - Hyperbus Write Transaction: 6-byte Command/Address + 2-byte Data
       - The address is split into 2 parts: half-page address and word address
       - With DDR timing, using four clock cycles (eight clock edges) to send 8-byte

                    ____    Address=555h, Data=00AAh     ___
            CS#         \_______________________________/

                           ___     ___     ___     ___
            CK      ______/ 1 \___/ 2 \___/ 3 \___/ 4 \_____

                         __  __  __  __  __  __  __  __
            DQ[7-0] ____/00\/00\/00\/AA\/00\/05\/00\/AA\____
                        \__/\__/\__/\__/\__/\__/\__/\__/
    */

    if (0U == sequenceIndex)
    {
        /* First command: Write Register Linear with Address=555h, Data=00AAh */
        lutData[0] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x00U);
        lutData[1] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x00U);

        lutData[2] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x00U);
        lutData[3] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0xAAU);

        lutData[4] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x00U);
        lutData[5] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x05U);

        lutData[6] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x00U);
        lutData[7] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0xAAU);
    }
    else if (1U == sequenceIndex)
    {
        /* Second command: Write Register Linear with Address=2AAh, Data=0055h */
        lutData[0] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x00U);
        lutData[1] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x00U);

        lutData[2] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x00U);
        lutData[3] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x55U);

        lutData[4] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x00U);
        lutData[5] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x02U);

        lutData[6] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x00U);
        lutData[7] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x55U);
    }
    else  /* sequenceIndex is 2U */
    {
        /* Third command: Write Register Linear with Address=555h, Data=00F5h */
        lutData[0] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x00U);
        lutData[1] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x00U);

        lutData[2] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x00U);
        lutData[3] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0xAAU);

        lutData[4] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x00U);
        lutData[5] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x05U);

        lutData[6] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0x00U);
        lutData[7] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, 0xF5U);
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpLutInitEnterLegacySPI
 * Description   : Builds the enter XPI protocol initial operations (needed for devices booting-up in Hyperbus mode)
 */
static void Xspi_Ip_SfdpLutInitEnterLegacySPI(Xspi_Ip_MemoryConfigType const *pConfig)
{
    Xspi_Ip_InitOperationType *operation;
    Xspi_Ip_InstrOpType lutData[8U];  /* Data to be written to the physical LUTs */
    uint32 sequenceIndex;

    /* Only needed for devices do not boot in legacy XPI mode */
    if ((boolean)FALSE == bootModeLegacyXPI)
    {
        for (sequenceIndex = 0U; sequenceIndex < 3U; sequenceIndex++)
        {
            operation = &(pConfig->initConfiguration.operations[initOpCount]);
            initOpCount++;

            /* Build operation */
            operation->opType      = XSPI_IP_OP_TYPE_CMD;
            operation->command1Lut = lutCount;
            operation->addr        = 0U;

            /* Pack the command sequence */
            Xspi_Ip_SfdpPackLutEnterLegacySPI(sequenceIndex, lutData);

            /* Build LUT sequence (copy into the virtual LUT table of the configuration) */
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), lutData[0]);
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), lutData[1]);
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), lutData[2]);
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), lutData[3]);
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), lutData[4]);
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), lutData[5]);
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), lutData[6]);
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), lutData[7]);
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), XSPI_IP_LUT_SEQ_END);  /* End of sequence */

            /* Other operation fields are unused */
            operation->command2Lut = XSPI_IP_LUT_INVALID;
            operation->weLut       = XSPI_IP_LUT_INVALID;
            operation->size        = 0U;
            operation->shift       = 0U;
            operation->width       = 0U;
            operation->value       = 0U;
            operation->ctrlCfgPtr  = NULL_PTR;
        }
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpEnterLegacySPI
 * Description   : The Enter Default Protocol Mode command is a sequence of three Write Register Linear commands.
 */
static void Xspi_Ip_SfdpEnterLegacySPI(uint32 instance)
{
    uint32 sequenceIndex;
    Xspi_Ip_InstrOpType lutData[10U];  /* Data to be written to the physical LUTs */
    lutData[8] = XSPI_IP_LUT_SEQ_END;  /* End of sequence */
    lutData[9] = XSPI_IP_LUT_SEQ_END;  /* End of sequence */

    /* We need 5 LUT registers: 4 for the command sequence, plus 1 for the end of sequence.
       - For platforms that have 4 LUT registers that make up a LUT sequence:
            only the first 4 LUT registers will be written to avoid overwriting the next sequence

       - For platforms that have 5 LUT registers that make up a LUT sequence:
            all 5 LUT registers will be written

       Because: The instructions are executed sequentially until the last instruction or the STOP instruction is encountered.

       Note:
           - This will not work if FEATURE_XSPI_LUT_SEQUENCE_SIZE is less than 4
           - In that case, XSPI_IP_LUT_INSTR_WRITE_DDR must be used (data will be placed in the TBDR to save the number of LUTs)
    */

    /* Issue the three command sequences */
    for (sequenceIndex = 0U; sequenceIndex < 3U; sequenceIndex++)
    {
        Xspi_Ip_SfdpPackLutEnterLegacySPI(sequenceIndex, lutData);              /* Pack the command sequence                     */
        Xspi_Ip_SetLutSeq(instance, XSPI_IP_COMMAND_LUT, lutData);              /* Write them to physical hardware LUT registers */
        (void)Xspi_Ip_IpCommand(HifBaseAddr, XSPI_IP_COMMAND_LUT, 0U);          /* Issue the command sequence                    */
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpExitDOPI
 * Description   : Attempt to exit the memory device from DTR-Octal (8D-8D-8D) mode.
 */
static void Xspi_Ip_SfdpExitDOPI(uint32 instance,
                                 uint32 baseAddress
                                )
{
    /* Workaround 1: send 8D-8D-8D reset commands as specified by xSPI Profile 1.0 */
    Xspi_Ip_SfdpInitReset_8D8D8D(instance, baseAddress);

    /* Workaround 2: send Enter Default Protocol Mode command sequence (1S-1S-1S) as specified by xSPI Profile 2.0 */
    Xspi_Ip_SfdpEnterLegacySPI(instance);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpInitReset
 * Description   : Sends reset commands to force device to enter SPI mode.
 */
static void Xspi_Ip_SfdpInitReset(uint32 instance,
                                  uint32 baseAddress
                                 )
{
    /* Attempt to read SFDP in DOPI mode */
    Xspi_Ip_SfdpExitDOPI(instance, baseAddress);

    /* Attempt to read SFDP in QPI mode */
    Xspi_Ip_SfdpExitQPI(instance, baseAddress);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpFindWorkingMode
 * Description   : Tries each mode to find the mode in which the flash device is working.
 */
static Xspi_Ip_SfdpModes Xspi_Ip_SfdpFindWorkingMode(uint32 instance,
                                                      uint32 baseAddress
                                                     )
{
    /* List of sfdp modes attempt to read and the corresponding pad return values */
    const Xspi_Ip_SfdpModes  modes[5U] = {XSPI_IP_SFDP_8D_8D_8D, XSPI_IP_SFDP_1S_1S_1S, XSPI_IP_SFDP_4S_4D_4D, XSPI_IP_SFDP_4S_4S_4S, XSPI_IP_SFDP_2S_2S_2S};
    const Xspi_Ip_LutPadsType pads[5U] = {XSPI_IP_LUT_PADS_8, XSPI_IP_LUT_PADS_1, XSPI_IP_LUT_PADS_4,    XSPI_IP_LUT_PADS_4,    XSPI_IP_LUT_PADS_2};
    const uint32 maxAttempts = 5U;
    Xspi_Ip_StatusType status;
    uint8 data[4U];
    uint32 idx;
    Xspi_Ip_SfdpModes CurrentMode= XSPI_IP_SFDP_INVALID;

    /* Attempt to read SFDP modes */
    for (idx = 0U; idx < maxAttempts; idx++)
    {
        Xspi_Ip_SfdpInitLut(instance, modes[idx]);
        status = Xspi_Ip_IpRead(HifBaseAddr, XSPI_IP_COMMAND_LUT, baseAddress, data, NULL_PTR, 4U);
        if ((STATUS_XSPI_IP_SUCCESS == status) && Xspi_Ip_SfdpSignatureCheck(data))
        {
            /* Found a supported mode */
            cmdPadsInit = pads[idx];
            CurrentMode = modes[idx];
            break;
        }
        if(STATUS_XSPI_IP_SUCCESS != status)
        {
            /*Read fail abort curent job.*/
            (void)Xspi_Ip_Abort(instance);
        }
    }
    return CurrentMode;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpCheck
 * Description   : Checks the existence of SFDP support.
 */
static Xspi_Ip_StatusType Xspi_Ip_SfdpCheck(uint32 instance,
                                            uint32 baseAddress
                                           )
{
    Xspi_Ip_StatusType status;
    /* First attempt to check if SFDP is supported or not */
    cmdSfdpMode = Xspi_Ip_SfdpFindWorkingMode(instance, baseAddress);
    if (XSPI_IP_SFDP_INVALID == cmdSfdpMode)
    {
        /* The first check has failed, try to issue reset commands in various modes */
        Xspi_Ip_SfdpInitReset(instance, baseAddress);
        /* Then try for the second attempt */
        cmdSfdpMode = Xspi_Ip_SfdpFindWorkingMode(instance, baseAddress);
    }
    if (XSPI_IP_SFDP_INVALID == cmdSfdpMode)
    {
        status = STATUS_XSPI_IP_ERROR;
    }
    else
    {
        status = STATUS_XSPI_IP_SUCCESS;
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpCheckMinorRevision
 * Description   : Verifies validity of sfdp minor revision
 *
 *END**************************************************************************/
static inline boolean Xspi_Ip_SfdpCheckMinorRevision(uint8 minorRevision)
{
    /* Revision and size must match the specifications of JESD216, JESD216A or JESD216B; also accept newer revisions */
    return ((XSPI_IP_SFDP_MINOR_REVISION_REV_0 == minorRevision) ||
            (minorRevision >= XSPI_IP_SFDP_MINOR_REVISION_REV_A));
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetCmdExt
 * Description   : Builds configuration for octal DDR (DOPI) mode.
 */
static inline uint8 Xspi_Ip_SfdpGetCmdExt(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                          uint8 instruction
                                         )
{
    uint8 cmdExt;

    /* Get Command Extension */
    cmdExt = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, XSPI_IP_SFDP_BASIC_CMD_EXT_DWORD,
                                              XSPI_IP_SFDP_BASIC_CMD_EXT_SHIFT, XSPI_IP_SFDP_BASIC_CMD_EXT_WIDTH, 0x1U);
    if (cmdExt == 0U)
    {
        cmdExt = instruction;
    }
    else
    {
        cmdExt = ~instruction;
    }
    return cmdExt;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpClearTable
 * Description   : Clears parameter table before reading it. This is to avoid MISRA non-initialized value errors.
 */
static void Xspi_Ip_SfdpClearTable(uint32 * paramTable,
                                   uint8 paramTableLength
                                  )
{
    uint8 count;
    for (count = 0U; count < paramTableLength; count++)
    {
        paramTable[count] = 0U;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpCheckNewerRevision
 * Description   : Check SFDP Parameter Table revision is newer or not
 */
static inline boolean Xspi_Ip_SfdpCheckNewerRevision(uint8 paramIdLSB,
                                                     uint8 tableType,
                                                     uint8 majorRevision,
                                                     uint8 minorRevision,
                                                     sint16 minorRevisionMax
                                                    )
{
    boolean retVal;

    if ((paramIdLSB == (uint8)tableType) &&
        (XSPI_IP_SFDP_MAJOR_REVISION == majorRevision) &&
        ((sint16)minorRevision > minorRevisionMax))
    {
        retVal = TRUE;
    }
    else
    {
        retVal = FALSE;
    }

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetParamTableAddress
 * Description   : Gets the address of parameter table from the parameter header.
 *                 Converts to byte address if the device is hyperbus.
 */
static inline uint32 Xspi_Ip_SfdpGetParamTableAddress(const uint8 * paramHeader,
                                                      uint8 accessProtocol
                                                     )
{
    /* Get the table address from pointer byte 2, 1 and 0 */
    uint32 paramTableAddress = ((uint32)paramHeader[6U] << 16U) | ((uint32)paramHeader[5U] << 8U) | (uint32)paramHeader[4U];

    /* The memory is a hyperbus device, convert from word address to byte address */
    if (accessProtocol == XSPI_IP_SFDP_ACCESS_PROTOCOL_HYPERBUS)
    {
        bootModeLegacyXPI = (boolean)FALSE;  /* The memory device booting up in xSPI NOR Profile 2 HYPERBUS */
        paramTableAddress <<= 1U;
    }

    return paramTableAddress;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpFindTable
 * Description   : Finds requested parameters table in SFDP table, if it exists.
 */
static Xspi_Ip_StatusType Xspi_Ip_SfdpFindTable(uint32 baseAddress,
                                                Xspi_Ip_SfdpTables tableType,
                                                uint32 * paramTable,
                                                uint8 * paramTableLength
                                               )
{
    Xspi_Ip_StatusType status;
    uint8 data[8U];
    uint8 paramHeaders = 0U;
    uint8 majorRevision;
    uint8 minorRevision;
    sint16 minorRevisionMax = -1;
    uint8 paramIdLSB;
    uint32 currAddr;
    uint32 paramTableBaseAddr = 0U;
    uint8 tableLength;
    uint8 tableLengthMax = 0U;
    boolean minorVerFlag = FALSE;
    uint8 accessProtocol = XSPI_IP_SFDP_ACCESS_PROTOCOL_LEGACY;  /* default value as Legacy option */

    Xspi_Ip_SfdpClearTable(paramTable, *paramTableLength);
    /* read second part of SFDP header to check version and get number of parameter headers */
    status = Xspi_Ip_IpRead(HifBaseAddr, XSPI_IP_COMMAND_LUT, baseAddress + 4U, data, NULL_PTR, 4U);
    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        /* check SFDP revision; minor revision can be greater than expected, because backward compatibility is guaranteed */
        majorRevision = data[1];
        minorRevision = data[0];
        paramHeaders = (uint8)(data[2] + 1U);
        accessProtocol = data[3];  /* [31:24] SFDP Access Protocol field */
        minorVerFlag = Xspi_Ip_SfdpCheckMinorRevision(minorRevision);
        if ((XSPI_IP_SFDP_MAJOR_REVISION != majorRevision) || (TRUE != minorVerFlag))
        {
            paramHeaders = 0U;
            status = STATUS_XSPI_IP_ERROR;
        }
    }

    /* If paramHeaders is greater than zero means the SFDP revision is correct */
    /* iterate through parameter headers */
    currAddr = 8U;
    for (; paramHeaders > (uint8)0U; paramHeaders--)
    {
        /* read current parameter header */
        status = Xspi_Ip_IpRead(HifBaseAddr, XSPI_IP_COMMAND_LUT, baseAddress + currAddr, data, NULL_PTR, 8U);
        if (status != STATUS_XSPI_IP_SUCCESS)
        {
            break;
        }
        majorRevision = data[2];
        minorRevision = data[1];
        paramIdLSB = data[0];
        tableLength = data[3];
        if (TRUE == Xspi_Ip_SfdpCheckNewerRevision(paramIdLSB, (uint8)tableType, majorRevision, minorRevision, minorRevisionMax))
        {
            /* Found SFDP Basic Parameter Table with newer revision */
            paramTableBaseAddr = Xspi_Ip_SfdpGetParamTableAddress(data, accessProtocol);
            minorRevisionMax = (sint16)minorRevision;
            tableLengthMax = tableLength;
        }
        currAddr += 8U;
    }

    /* If minorRevisionMax is not negative, it means that a SFDP table was found */
    if (minorRevisionMax >= 0)
    {
        /* Adjust table length in case of newer revisions */
        if (tableLengthMax > *paramTableLength)
        {
            tableLengthMax = *paramTableLength;
        }
        /* Read parameter table */
        status = Xspi_Ip_IpRead(HifBaseAddr, XSPI_IP_COMMAND_LUT, baseAddress + paramTableBaseAddr, (uint8 *)paramTable, NULL_PTR, (uint32)tableLengthMax * 4U);
        if (STATUS_XSPI_IP_SUCCESS == status)
        {
            *paramTableLength = tableLengthMax;
        }
    }
    else
    {
        /* Could not find a table of the requested kind */
        *paramTableLength = 0U;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpReadTables
 * Description   : Finds requested parameters table in SFDP table, if it exists.
 */
static Xspi_Ip_StatusType Xspi_Ip_SfdpReadTables(uint32 baseAddress,
                                                 Xspi_Ip_SfdpTablesContainer *sfdpTables
                                                )
{
    Xspi_Ip_StatusType status;

    /* Initialize each table length to max specified by JESD216 rev. D */
    sfdpTables->paramTableLength_basic = XSPI_IP_TABLE_SIZE_BASIC;
    sfdpTables->paramTableLength_4badd = XSPI_IP_TABLE_SIZE_4BADD;
    sfdpTables->paramTableLength_xspi1 = XSPI_IP_TABLE_SIZE_XSPI1;
    sfdpTables->paramTableLength_srmap = XSPI_IP_TABLE_SIZE_SRMAP;
    sfdpTables->paramTableLength_2dopi = XSPI_IP_TABLE_SIZE_2DOPI;

    /* Search Basic Flash Parameter Table */
    status = Xspi_Ip_SfdpFindTable(baseAddress, XSPI_IP_SFDP_TABLE_BASIC,
                                   sfdpTables->paramTable_basic, &(sfdpTables->paramTableLength_basic));
    if ((status != STATUS_XSPI_IP_SUCCESS) || (sfdpTables->paramTableLength_basic == 0U))
    {
        status = STATUS_XSPI_IP_ERROR;
    }

    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Search 4-byte Address Instruction Table */
        status = Xspi_Ip_SfdpFindTable(baseAddress, XSPI_IP_SFDP_TABLE_4BADD,
                                       sfdpTables->paramTable_4badd, &(sfdpTables->paramTableLength_4badd));
    }

    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Search eXtended Serial Peripheral Interface (xSPI) Profile 1.0 Table */
        status = Xspi_Ip_SfdpFindTable(baseAddress, XSPI_IP_SFDP_TABLE_XSPI1,
                                       sfdpTables->paramTable_xspi1, &(sfdpTables->paramTableLength_xspi1));
    }

    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Search Status, Control and Configuration Register Map Table */
        status = Xspi_Ip_SfdpFindTable(baseAddress, XSPI_IP_SFDP_TABLE_SRMAP,
                                       sfdpTables->paramTable_srmap, &(sfdpTables->paramTableLength_srmap));
    }

    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Command Sequences to change to DOPI (8D-8D-8D) mode */
        status = Xspi_Ip_SfdpFindTable(baseAddress, XSPI_IP_SFDP_TABLE_2DOPI,
                                       sfdpTables->paramTable_2dopi, &(sfdpTables->paramTableLength_2dopi));
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpInitSimpleCmd
 * Description   : Builds an initial operation containing a simple command.
 */
static void Xspi_Ip_SfdpInitSimpleCmd(uint8 cmd,
                                      const Xspi_Ip_MemoryConfigType *pConfig
                                     )
{
    Xspi_Ip_InitOperationType *operation;

    if (initOpCount >= pConfig->initConfiguration.opCount)
    {
        /* operations list not big enough */
        overflow = TRUE;
    }
    else
    {
        operation = &(pConfig->initConfiguration.operations[initOpCount]);
        initOpCount++;
        /* Build operation */
        operation->opType = XSPI_IP_OP_TYPE_CMD;
        operation->command1Lut = lutCount;
        operation->addr = 0U;
        /* Build LUT sequence */
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, XSPI_IP_LUT_PADS_1, cmd));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
        /* Other operation fields are unused */
        operation->command2Lut = XSPI_IP_LUT_INVALID;
        operation->weLut = XSPI_IP_LUT_INVALID;
        operation->size  = 0U;
        operation->shift = 0U;
        operation->width = 0U;
        operation->value = 0U;
        operation->ctrlCfgPtr = NULL_PTR;
    }

    return;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetWeSrInstr
 * Description   : Returns instruction for write enable on SR register.
 */
static uint8 Xspi_Ip_SfdpGetWeSrInstr(const Xspi_Ip_SfdpTablesContainer *sfdpTables)
{
    uint8 wrEnSr;

    /* Check "Write Enable Instruction Select for Writing to Volatile Status Register" bitfield */
    wrEnSr = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, XSPI_IP_SFDP_BASIC_WREN_SR_DWORD,
                                              XSPI_IP_SFDP_BASIC_WREN_SR_SHIFT, XSPI_IP_SFDP_BASIC_WREN_SR_WIDTH, 0x1U);
    if (wrEnSr == 1U)
    {
        wrEnSr = 0x50U;
    }
    else
    {
        wrEnSr = 0x06U;
    }
    return wrEnSr;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpInitWriteReg
 * Description   : Builds an initial operation containing a register write command.
 */
static void Xspi_Ip_SfdpInitWriteReg(uint8 cmd,
                                     uint8 wrenCmd,
                                     uint8 size,
                                     uint32 value,
                                     const Xspi_Ip_MemoryConfigType *pConfig
                                    )
{
    Xspi_Ip_InitOperationType *operation;

    if (initOpCount >= pConfig->initConfiguration.opCount)
    {
        /* operations list not big enough */
        overflow = TRUE;
    }
    else
    {
        operation = &(pConfig->initConfiguration.operations[initOpCount]);
        initOpCount++;
        /* Build operation */
        operation->opType = XSPI_IP_OP_TYPE_WRITE_REG;
        operation->addr = 0U;
        operation->weLut = lutCount;
        operation->size = size;
        operation->value = value;
        /* Build WE LUT sequence */
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, XSPI_IP_LUT_PADS_1, wrenCmd));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
        operation->command1Lut = lutCount;
        /* Build write SR LUT sequence */
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, XSPI_IP_LUT_PADS_1, cmd));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_WRITE, XSPI_IP_LUT_PADS_1, 0x1U));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));

        /* Other operation fields are unused */
        operation->command2Lut = XSPI_IP_LUT_INVALID;
        operation->shift = 0U;
        operation->width = 0U;
        operation->ctrlCfgPtr = NULL_PTR;
    }

    return;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Sfdp4byteAddrSwitch_01
 * Description   : Switch to 4-byte addressing mode.
 */
static Xspi_Ip_StatusType Xspi_Ip_Sfdp4byteAddrSwitch_01(const Xspi_Ip_MemoryConfigType * pConfig)
{
    /* issue instruction B7h (preceding write enable not required) */
    Xspi_Ip_SfdpInitSimpleCmd(0xB7U, pConfig);
    return STATUS_XSPI_IP_SUCCESS;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Sfdp4byteAddrSwitch_02
 * Description   : Switch to 4-byte addressing mode.
 */
static Xspi_Ip_StatusType Xspi_Ip_Sfdp4byteAddrSwitch_02(const Xspi_Ip_MemoryConfigType * pConfig)
{
    /* issue write enable instruction 06h, then issue instruction B7h */
    Xspi_Ip_SfdpInitSimpleCmd(0x06U, pConfig);
    Xspi_Ip_SfdpInitSimpleCmd(0xB7U, pConfig);
    return STATUS_XSPI_IP_SUCCESS;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Sfdp4byteAddrSwitch_08
 * Description   : Switch to 4-byte addressing mode.
 */
static Xspi_Ip_StatusType Xspi_Ip_Sfdp4byteAddrSwitch_08(const Xspi_Ip_MemoryConfigType * pConfig)
{
    /* 8-bit volatile bank register used to define A[30:A24] bits. MSB (bit[7]) is used to enable/disable 4-byte address mode.
       When MSB is set to ‘1’, 4-byte address mode is active and A[30:24] bits are don’t care. Read with instruction 16h.
       Write instruction is 17h with 1 byte of data. When MSB is cleared to ‘0’, select the active 128 Mbit segment by setting
       the appropriate A[30:24] bits and use 3-Byte addressing */
    /* Not implemented */
    (void)pConfig;
    return STATUS_XSPI_IP_ERROR;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Sfdp4byteAddrSwitch_16
 * Description   : Switch to 4-byte addressing mode.
 */
static Xspi_Ip_StatusType Xspi_Ip_Sfdp4byteAddrSwitch_16(const Xspi_Ip_MemoryConfigType * pConfig)
{
    /* A 16-bit nonvolatile configuration register controls 3-Byte/4-Byte address mode. Read instruction is B5h.
       Bit[0] controls address mode [0=3-Byte; 1=4-Byte]. Write configuration register instruction is B1h, data length is 2 bytes */
    /* Not implemented */
    (void)pConfig;
    return STATUS_XSPI_IP_ERROR;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Sfdp4byteAddrSwitch
 * Description   : Switch to 4-byte addressing mode.
 */
static Xspi_Ip_StatusType Xspi_Ip_Sfdp4byteAddrSwitch(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                                      const Xspi_Ip_MemoryConfigType * pConfig
                                                     )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    uint8 addrSwitch;

    /* Check 4-byte addr enable mode */
    addrSwitch = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, XSPI_IP_SFDP_BASIC_ADDR_SWITCH_DWORD,
                                                  XSPI_IP_SFDP_BASIC_ADDR_SWITCH_SHIFT, XSPI_IP_SFDP_BASIC_ADDR_SWITCH_WIDTH, 0x0U);
    if ((addrSwitch & 0x01U) != 0U)
    {
        /* issue instruction B7h (preceding write enable not required) */
        status = Xspi_Ip_Sfdp4byteAddrSwitch_01(pConfig);
    }
    else if ((addrSwitch & 0x02U) != 0U)
    {
        /* issue write enable instruction 06h, then issue instruction B7h */
        status = Xspi_Ip_Sfdp4byteAddrSwitch_02(pConfig);
    }
    else if ((addrSwitch & 0x08U) != 0U)
    {
        /* 8-bit volatile bank register used to define A[30:A24] bits. MSB (bit[7]) is used to enable/disable 4-byte address mode */
        status = Xspi_Ip_Sfdp4byteAddrSwitch_08(pConfig);
    }
    else if ((addrSwitch & 0x10U) != 0U)
    {
        /* A 16-bit nonvolatile configuration register controls 3-Byte/4-Byte address mode. */
        status = Xspi_Ip_Sfdp4byteAddrSwitch_16(pConfig);
    }
    else
    {
        /* Can't switch to 4-byte addr. mode */
        status = STATUS_XSPI_IP_ERROR;
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetBasicAddrBits
 * Description   : Returns number of address bits.
 */
static void Xspi_Ip_SfdpGetBasicAddrBits(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                         const Xspi_Ip_MemoryConfigType * pConfig
                                        )
{
    uint8 addrBytes;
    Xspi_Ip_StatusType status;

    /* Check number of address bytes */
    addrBytes = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, XSPI_IP_SFDP_BASIC_ADDR_BYTES_DWORD,
                                                 XSPI_IP_SFDP_BASIC_ADDR_BYTES_SHIFT, XSPI_IP_SFDP_BASIC_ADDR_BYTES_WIDTH, 0x0U);
    switch (addrBytes)
    {
        case 0U:
            /* 3-Byte only addressing */
            basicAddrBits = 24U;
            break;
        case 1U:
            /* 3 or 4 byte addressing, try to switch to 4 */
            status = Xspi_Ip_Sfdp4byteAddrSwitch(sfdpTables, pConfig);
            if (STATUS_XSPI_IP_SUCCESS == status)
            {
                basicAddrBits = 32U;
            }
            else
            {
                basicAddrBits = 24U;
            }
            break;
        case 2U:
            /* 4-Byte only addressing */
            basicAddrBits = 32U;
            break;
        default:
            /* reseved, should not happen, default to 3-byte */
            basicAddrBits = 24U;
            break;
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpConfigureQE
 * Description   : Adds initial operation to set QE bit, if required.
 */
static void Xspi_Ip_SfdpConfigureQE(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                    const Xspi_Ip_MemoryConfigType *pConfig
                                   )
{
    uint8 qeReq;
    uint8 wrenCmd;
    boolean qeBit = TRUE;

    /* Check "Quad Enable Requirements (QER)" field */
    qeReq = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, XSPI_IP_SFDP_BASIC_QE_REQ_DWORD,
                                             XSPI_IP_SFDP_BASIC_QE_REQ_SHIFT, XSPI_IP_SFDP_BASIC_QE_REQ_WIDTH, 0x7U);
    wrenCmd = Xspi_Ip_SfdpGetWeSrInstr(sfdpTables);
    switch (qeReq)
    {
        case 0U:
            /* Device does not have a QE bit. Device detects 1-1-4 and 1-4-4 reads based on instruction.
              (the quad commands are available without setting any bits) */
            qeBit = FALSE;
            break;
        case 1U:
            /* QE is bit 1 of status register 2. It is set via Write Status with two data bytes where bit 1 of the second byte is one. It is cleared via
               Write Status with two data bytes where bit 1 of the second byte is zero. Writing only one byte to the status register has the side-effect
               of clearing status register 2, including the QE bit */
            Xspi_Ip_SfdpInitWriteReg(0x01U, wrenCmd, 2U, 0x0200U, pConfig);
            break;
        case 2U:
            /* QE is bit 6 of status register 1. It is set via Write Status with one data byte where bit 6 is one.
               It is cleared via Write Status with one data byte where bit 6 is zero. */
            Xspi_Ip_SfdpInitWriteReg(0x01U, wrenCmd, 1U, 0x40U, pConfig);
            break;
        case 3U:
            /* QE is bit 7 of status register 2. It is set via Write status register 2 instruction 3Eh with one data byte where bit 7 is one.
               It is cleared via Write status register 2 instruction 3Eh with one data byte where bit 7 is zero. The status register 2 is read using instruction 3Fh. */
            Xspi_Ip_SfdpInitWriteReg(0x3EU, wrenCmd, 1U, 0x80U, pConfig);
            break;
        case 4U:
            /* QE is bit 1 of status register 2. It is set via Write Status with two data bytes where bit 1 of the second byte is one. It is cleared via
               Write Status with two data bytes where bit 1 of the second byte is zero. In contrast to the 001b code, writing one byte to the status
               register does not modify status register 2. */
            Xspi_Ip_SfdpInitWriteReg(0x01U, wrenCmd, 2U, 0x0200U, pConfig);
            break;
        case 5U:
            /* QE is bit 1 of the status register 2. Status register 1 is read using Read Status instruction 05h. Status register 2 is read using instruction 35h.
               QE is set via Write Status instruction 01h with two data bytes where bit 1 of the second byte is one. It is cleared via Write Status with
               two data bytes where bit 1 of the second byte is zero. */
            Xspi_Ip_SfdpInitWriteReg(0x01U, wrenCmd, 2U, 0x0200U, pConfig);
            break;
        case 6U:
            /* QE is bit 1 of the status register 2. Status register 1 is read using Read Status instruction 05h. Status register 2 is read using instruction
               35h, and status register 3 is read using instruction 15h. QE is set via Write Status Register instruction 31h with one data byte where
               bit 1 is one. It is cleared via Write Status Register instruction 31h with one data byte where bit 1 is zero. */
            Xspi_Ip_SfdpInitWriteReg(0x31U, wrenCmd, 1U, 0x02U, pConfig);
            break;
        default:
            /* Unknown QE bit setting procedure or table too short, disable quad commands */
            quadAvailable = FALSE;
            qeBit = FALSE;
            break;
    }

    if (TRUE == qeBit)
    {
        /* Add a wait operation to ensure the write to non-volatile QE bit is completed */
        Xspi_Ip_SfdpAddCheckBusyOperation(sfdpTables, pConfig);
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetModeInstr
 * Description   : Returns MODE instructions to use for read commands.
 */
static Xspi_Ip_LutCommandsType Xspi_Ip_SfdpGetModeInstr(uint8 modeClocks,
                                                        Xspi_Ip_LutPadsType addrPads
                                                       )
{
    uint8 modeBits;
    Xspi_Ip_LutCommandsType mode = XSPI_IP_LUT_INSTR_MODE;

    /* compute the number of mode bits from pads and mode clocks */
    modeBits = modeClocks * (1U << (uint8)((uint32)addrPads >> 8U));
    switch (modeBits)
    {
        case 2U:
            mode = XSPI_IP_LUT_INSTR_MODE2;
            break;
        case 4U:
            mode = XSPI_IP_LUT_INSTR_MODE4;
            break;
        case 8U:
            mode = XSPI_IP_LUT_INSTR_MODE;
            break;
        default:
            /* unsupported mode */
            break;
    }
    return mode;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetSpiReadInstr
 * Description   : Returns instructions for read type <cnt>.
 */
static void Xspi_Ip_SfdpGetSpiReadInstr(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                        uint8 cnt,
                                        uint8 *instruction,
                                        uint8 *addrBits
                                       )
{
    uint8 sup4badd;

    /* Check 4-byte instr. support */
    sup4badd = (uint8)Xspi_Ip_SfdpGet4BAddParam(sfdpTables, read4ByteSupDword[cnt],
                                                read4ByteSupShift[cnt], XSPI_IP_SFDP_4BADD_INSTR_SUP_WIDTH, 0x0U);
    if (sup4badd == 1U)
    {
        /* Use 4-byte address instruction specified in SFDP standard */
        *instruction = read4ByteInst[cnt];
        *addrBits = 32U;
    }
    else
    {
        /* Get instruction from basic parameters table */
        *instruction = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, readInstDword[cnt],
                                                        readInstShift[cnt], readInstWidth[cnt], 0x0U);
        *addrBits = basicAddrBits;
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpConfigBasicRead
 * Description   : Configures basic 1-1-1 read.
 */
static void Xspi_Ip_SfdpConfigBasicRead(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                        Xspi_Ip_MemoryConfigType *pConfig
                                       )
{
    uint8 addrBits;
    uint8 instruction;

    /* Check 4-byte instr. support */
    addrBits = (uint8)Xspi_Ip_SfdpGet4BAddParam(sfdpTables, XSPI_IP_SFDP_4BADD_INSTR_SUP_DWORD,
                                                XSPI_IP_SFDP_4BADD_READ111_SUP_SHIFT, XSPI_IP_SFDP_4BADD_INSTR_SUP_WIDTH, 0x0U);
    if (addrBits == 0U)
    {
        instruction = XSPI_IP_CMD_BASIC_READ;
        addrBits = basicAddrBits;
    }
    else
    {
        instruction = XSPI_IP_CMD_BASIC_READ_4B;
        addrBits = 32U;
    }
    /* Get LUT index */
    pConfig->readLut = lutCount;
    /* Build LUT */
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, XSPI_IP_LUT_PADS_1, instruction));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_ADDR, XSPI_IP_LUT_PADS_1, addrBits));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_READ, XSPI_IP_LUT_PADS_1, 0x10U));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Sfdp444Switch
 * Description   : Add commands to switch to 4-4-4 mode in operations list
 */
static Xspi_Ip_StatusType Xspi_Ip_Sfdp444Switch_01(const Xspi_Ip_MemoryConfigType * pConfig)
{
        /* 01: set QE per QER description above, then issue instruction 38h */
        /* 02: issue instruction 38h */
    Xspi_Ip_SfdpInitSimpleCmd(0x38U, pConfig);
    return STATUS_XSPI_IP_SUCCESS;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Sfdp444Switch
 * Description   : Add commands to switch to 4-4-4 mode in operations list
 */
static Xspi_Ip_StatusType Xspi_Ip_Sfdp444Switch_04(const Xspi_Ip_MemoryConfigType * pConfig)
{
        /* issue instruction 35h */
    Xspi_Ip_SfdpInitSimpleCmd(0x35U, pConfig);
    return STATUS_XSPI_IP_SUCCESS;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Sfdp444Switch
 * Description   : Add commands to switch to 4-4-4 mode in operations list
 */
static Xspi_Ip_StatusType Xspi_Ip_Sfdp444Switch_08(const Xspi_Ip_MemoryConfigType * pConfig)
{
        /* device uses a read-modify-write sequence of operations: read configuration using instruction 65h followed by address 800003h, set bit 6,
           write configuration using instruction 71h followed by address 800003h. This configuration is volatile. */
    /* Not implemented */
    (void)pConfig;
    return STATUS_XSPI_IP_ERROR;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Sfdp444Switch
 * Description   : Add commands to switch to 4-4-4 mode in operations list
 */
static Xspi_Ip_StatusType Xspi_Ip_Sfdp444Switch_16(const Xspi_Ip_MemoryConfigType * pConfig)
{
        /* Device uses a read-modify-write sequence of operations: Read Volatile Enhanced Configuration Register using instruction 65h,
           no address is required, reset bit 7 to 0. Write Volatile Enhanced Configuration Register using instruction 61h,
           no address is required. This configuration is volatile. */
    /* Not implemented */
    (void)pConfig;
    return STATUS_XSPI_IP_ERROR;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Sfdp444Switch
 * Description   : Add commands to switch to 4-4-4 mode in operations list
 */
static Xspi_Ip_StatusType Xspi_Ip_Sfdp444Switch(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                                const Xspi_Ip_MemoryConfigType * pConfig
                                               )
{
    uint8 quadSwitch;
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;

    /* Check 4-4-4 mode enable sequences */
    quadSwitch = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, XSPI_IP_SFDP_BASIC_444_SWITCH_DWORD,
                                                  XSPI_IP_SFDP_BASIC_444_SWITCH_SHIFT, XSPI_IP_SFDP_BASIC_444_SWITCH_WIDTH, 0x0U);
    if ((quadSwitch & 0x3U) != 0U)
    {
        /* 01: set QE per QER description above, then issue instruction 38h */
        /* 02: issue instruction 38h */
        status = Xspi_Ip_Sfdp444Switch_01(pConfig);
    }
    else if ((quadSwitch & 0x4U) != 0U)
    {
        /* issue instruction 35h */
        status = Xspi_Ip_Sfdp444Switch_04(pConfig);
    }
    else if ((quadSwitch & 0x8U) != 0U)
    {   /* device uses a read-modify-write sequence of operations */
        status = Xspi_Ip_Sfdp444Switch_08(pConfig);
    }
    else if ((quadSwitch & 0x10U) != 0U)
    {   /* device uses a read-modify-write sequence of operations */
        status = Xspi_Ip_Sfdp444Switch_16(pConfig);
    }
    else
    {
        /* can't do the switch to 4-4-4 mode */
        status = STATUS_XSPI_IP_ERROR;
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetBasicFastReadInfo
 * Description   : Builds configuration for basic (SPI) read.
 */
static void Xspi_Ip_SfdpGetBasicFastReadInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                         Xspi_Ip_MemoryConfigType * pConfig
                                        )
{
    uint8 modeClocks;
    uint8 dummyClocks;
    Xspi_Ip_LutPadsType instPads;
    Xspi_Ip_LutPadsType addrPads;
    Xspi_Ip_LutPadsType dataPads;
    uint8 addrBits;
    uint8 instruction;
    Xspi_Ip_LutCommandsType modeInstr;
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;

    if ((uint8)XSPI_IP_SFDP_READ_MODE_444 == modeIndex)
    {
        /* 4-4-4 read mode, add commands to switch to this mode in operation list */
        status = Xspi_Ip_Sfdp444Switch(sfdpTables, pConfig);
        /* Will use 4 cmd pads for all commands */
        cmdPads = XSPI_IP_LUT_PADS_4;
    }
    else
    {
        status = STATUS_XSPI_IP_SUCCESS;
        cmdPads = XSPI_IP_LUT_PADS_1;
    }
    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Get read instruction */
        Xspi_Ip_SfdpGetSpiReadInstr(sfdpTables, modeIndex, &instruction, &addrBits);
        /* Get mode and dummy clocks */
        modeClocks = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, readModeDword[modeIndex],
                                                        readModeShift[modeIndex], readModeWidth[modeIndex], 0x0U);
        dummyClocks = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, readDummyDword[modeIndex],
                                                        readDummyShift[modeIndex], readDummyWidth[modeIndex], 0x0U);
        /* Get other command parameters */
        instPads = readModeInstPads[modeIndex];
        addrPads = readModeAddrPads[modeIndex];
        dataPads = readModeDataPads[modeIndex];
        /* Build LUT */
        pConfig->readLut = lutCount;
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, instPads, instruction));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_ADDR, addrPads, addrBits));
        if (modeClocks > 0U)
        {
            modeInstr = Xspi_Ip_SfdpGetModeInstr(modeClocks, addrPads);
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(modeInstr, addrPads, 0x0U));
        }
        if (dummyClocks > 0U)
        {
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_DUMMY, dataPads, dummyClocks));
        }
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_READ, dataPads, 0x10U));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetBasicWriteInfo
 * Description   : Builds configuration for basic (SPI) write
 */
static void Xspi_Ip_SfdpGetBasicWriteInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                          Xspi_Ip_MemoryConfigType * pConfig
                                         )
{
    uint8 supported;
    Xspi_Ip_LutPadsType instPads;
    Xspi_Ip_LutPadsType addrPads;
    Xspi_Ip_LutPadsType dataPads;
    uint8 addrBits;
    uint8 instruction;

    /* check if 4-byte write corresponding to the current read mode is supported */
    supported = (uint8)Xspi_Ip_SfdpGet4BAddParam(sfdpTables, write4ByteSupDword[modeIndex],
                                                 write4ByteSupShift[modeIndex], XSPI_IP_SFDP_4BADD_INSTR_SUP_DWORD, 0x0);
    if (supported == 1U)
    {
        addrBits = 32U;
        instruction = write4ByteInst[modeIndex];
        instPads = readModeInstPads[modeIndex];
        addrPads = readModeAddrPads[modeIndex];
        dataPads = readModeDataPads[modeIndex];
    }
    else
    {
        /* No 4-byte write support, use basic write since SFDP does not specify other write modes */
        addrBits = basicAddrBits;
        instruction = XSPI_IP_CMD_BASIC_WRITE;
        instPads = cmdPads;
        addrPads = cmdPads;
        dataPads = cmdPads;
    }
    /* Get LUT index */
    pConfig->writeLut = lutCount;
    /* Build LUT */
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, instPads, instruction));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_ADDR, addrPads, addrBits));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_WRITE, dataPads, 0x10U));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpInitLutReadCfgReg
 * Description   : Init LUT to get DummyCycles setting of the external memory.
 */
static inline void Xspi_Ip_SfdpInitLutReadCfgReg(const Xspi_Ip_SfdpTablesContainer *sfdpTables, uint32 instance, uint8 Cmd)
{
    uint8 nBytes;
    uint8 cmdExt;
    uint8 dummy;
    Xspi_Ip_LutCommandsType instCmd;
    Xspi_Ip_LutCommandsType addrCmd;
    Xspi_Ip_LutCommandsType dataCmd;
    Xspi_Ip_LutPadsType pads;
    Xspi_Ip_InstrOpType lutData[6U];  /* Data to be written to the physical LUTs */

    /* Set command parameters according to mode */
    instCmd = XSPI_IP_LUT_INSTR_CMD;
    addrCmd = XSPI_IP_LUT_INSTR_ADDR;
    dataCmd = XSPI_IP_LUT_INSTR_READ;
    if (XSPI_IP_SFDP_8D_8D_8D == cmdSfdpMode)
    {
        pads = XSPI_IP_LUT_PADS_8;
        instCmd = XSPI_IP_LUT_INSTR_CMD_DDR;
        addrCmd = XSPI_IP_LUT_INSTR_ADDR_DDR;
        dataCmd = XSPI_IP_LUT_INSTR_READ_DDR;
    }
    else if (XSPI_IP_SFDP_4S_4D_4D == cmdSfdpMode)
    {
        pads = XSPI_IP_LUT_PADS_4;
        addrCmd = XSPI_IP_LUT_INSTR_ADDR_DDR;
        dataCmd = XSPI_IP_LUT_INSTR_READ_DDR;
    }
    else if (XSPI_IP_SFDP_4S_4S_4S == cmdSfdpMode)
    {
        pads = XSPI_IP_LUT_PADS_4;
    }
    else if (XSPI_IP_SFDP_2S_2S_2S == cmdSfdpMode)
    {
        pads = XSPI_IP_LUT_PADS_2;
    }
    else
    {
        pads = XSPI_IP_LUT_PADS_1;
    }

    dummy = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_DUMMY_8D_DWORD,
                                             XSPI_IP_SFDP_SRMAP_DUMMY_8D_SHIFT, XSPI_IP_SFDP_SRMAP_DUMMY_8D_WIDTH, 0x0U);

    if (XSPI_IP_SFDP_8D_8D_8D == cmdSfdpMode)
    {
        cmdExt = Xspi_Ip_SfdpGetCmdExt(sfdpTables, Cmd);
        /* Number of address bytes used for */
        nBytes = 4U -(uint8)Xspi_Ip_SfdpGetXspi1Param(sfdpTables, XSPI_IP_SFDP_XSPI1_NBYTES_DWORD,
                                                      XSPI_IP_SFDP_XSPI1_NBYTES_SHIFT, XSPI_IP_SFDP_XSPI1_NBYTES_WIDTH, 0x0U);

        /* Build SFDP Read Sequence */
        lutData[0] = Xspi_Ip_PackLut(instCmd, pads, Cmd);                       /* Command on 8 data line */
        lutData[1] = Xspi_Ip_PackLut(instCmd, pads, cmdExt);                    /* Command on 8 data line */
        lutData[2] = Xspi_Ip_PackLut(addrCmd, pads, nBytes * 8U);               /* 24-bit/32-bit address on 8 data line */
        lutData[3] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_DUMMY, pads, dummy);     /* Dummy cycles */
        lutData[4] = Xspi_Ip_PackLut(dataCmd, pads, 0x10U);                     /* Read data on "pads" data lines */
        lutData[5] = XSPI_IP_LUT_SEQ_END;                                       /* End of sequence */
    }
    else
    {
        /* Number of address bytes used for Generic Addressable Read/Write Status/Control register commands for volatile registers */
        nBytes = 1U + (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_NBYTES_DWORD,
                                                       XSPI_IP_SFDP_SRMAP_NBYTES_SHIFT, XSPI_IP_SFDP_SRMAP_NBYTES_WIDTH, 0x0U);

        lutData[0] = Xspi_Ip_PackLut(instCmd, pads, Cmd);                       /* READ command on 1 data line */
        lutData[1] = Xspi_Ip_PackLut(addrCmd, pads, nBytes * 8U);               /* 24-bit/32-bit address on 1 data line */
        lutData[2] = Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_DUMMY, pads, dummy);     /* Dummy cycles */
        lutData[3] = Xspi_Ip_PackLut(dataCmd, pads, 0x10U);                     /* Read data on "pads" data lines */
        lutData[4] = XSPI_IP_LUT_SEQ_END;                                       /* End of sequence */
        lutData[5] = XSPI_IP_LUT_SEQ_END;                                       /* End of sequence */
    }
    /* Write the Read Cfg register Sequence into physical LUT registers */
    Xspi_Ip_SetLutSeq(instance, XSPI_IP_COMMAND_LUT, lutData);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpInitLutSetDummyCycle
 * Description   : Init LUT to set DummyCycles for the external memory.
 */
static void Xspi_Ip_SfdpInitLutSetDummyCycle(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                             const Xspi_Ip_MemoryConfigType *pConfig,
                                             uint32 address,
                                             uint32 value
                                            )
{
    uint8 wrenCmd;
    Xspi_Ip_LutCommandsType instCmd;
    Xspi_Ip_LutCommandsType addrCmd;
    Xspi_Ip_LutCommandsType writeCmd;
    Xspi_Ip_LutCommandsType dataCmd;
    Xspi_Ip_LutPadsType pads;
    uint8 CmdRead;
    uint8 Dummy;
    uint8 NumberOfBits;
    uint8 BitLocation;
    uint8 nBytes;
    Xspi_Ip_InitOperationType *operation;

    /* Command used for write access */
    uint8 cmd            = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_OFFSET,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_CMD_WRITE_SHIFT,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_CMD_WRITE_WIDTH,0U);
    /* Set command parameters according to mode */
    instCmd = XSPI_IP_LUT_INSTR_CMD;
    addrCmd = XSPI_IP_LUT_INSTR_ADDR;
    writeCmd = XSPI_IP_LUT_INSTR_WRITE;
    dataCmd = XSPI_IP_LUT_INSTR_READ;

    if (XSPI_IP_SFDP_8D_8D_8D == cmdSfdpMode)
    {
        pads = XSPI_IP_LUT_PADS_8;
        instCmd = XSPI_IP_LUT_INSTR_CMD_DDR;
        writeCmd = XSPI_IP_LUT_INSTR_WRITE_DDR;
        addrCmd = XSPI_IP_LUT_INSTR_ADDR_DDR;
        dataCmd = XSPI_IP_LUT_INSTR_READ_DDR;
    }
    else if (XSPI_IP_SFDP_4S_4D_4D == cmdSfdpMode)
    {
        pads = XSPI_IP_LUT_PADS_4;
        writeCmd = XSPI_IP_LUT_INSTR_WRITE_DDR;
        addrCmd = XSPI_IP_LUT_INSTR_ADDR_DDR;
        dataCmd = XSPI_IP_LUT_INSTR_READ_DDR;
    }
    else if (XSPI_IP_SFDP_4S_4S_4S == cmdSfdpMode)
    {
        pads = XSPI_IP_LUT_PADS_4;
    }
    else if (XSPI_IP_SFDP_2S_2S_2S == cmdSfdpMode)
    {
        pads = XSPI_IP_LUT_PADS_2;
    }
    else
    {
        pads = XSPI_IP_LUT_PADS_1;
    }

    if (initOpCount >= pConfig->initConfiguration.opCount)
    {
        /* operations list not big enough */
        overflow = TRUE;
    }
    else
    {
        operation         = &(pConfig->initConfiguration.operations[initOpCount]);
        initOpCount++;
        /* Build operation */
        operation->opType = XSPI_IP_OP_TYPE_RMW_REG;
        operation->weLut  = lutCount;

        wrenCmd = Xspi_Ip_SfdpGetWeSrInstr(sfdpTables);

        /* Build WE LUT sequence */
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(instCmd, pads, wrenCmd));

        if (XSPI_IP_SFDP_8D_8D_8D == cmdSfdpMode)
        {
            /*Add ext comand for DDR mode*/
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(instCmd, pads, Xspi_Ip_SfdpGetCmdExt(sfdpTables, wrenCmd)));
        }
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));


        /* Build Read LUT sequence*/
        operation->command1Lut = lutCount;
        /* Command used for read access */
        CmdRead          = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_DWORD_9_OFFSET,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_CMD_READ_SHIFT,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_CMD_READ_WIDTH,0);

        /*Number of physical bits used to set wait states   00: 2 bits, 01: 3 bits, 10: 4 bits, 11: 5 bits*/
        NumberOfBits     = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_DWORD_9_OFFSET,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_NUMBER_OF_BITS_SHIFT,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_NUMBER_OF_BITS_WIDTH,0U);
        /*Bit location of LSB of physical bits in register*/
        BitLocation      = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_DWORD_9_OFFSET,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_BIT_LOCATION_SHIFT,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_BIT_LOCATION_WIDTH,0U);
        /*Dummy cycle for read register*/
        Dummy            = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_DUMMY_8D_DWORD,
                                                            XSPI_IP_SFDP_SRMAP_DUMMY_8D_SHIFT,
                                                            XSPI_IP_SFDP_SRMAP_DUMMY_8D_WIDTH, 0x0U);

        operation->shift = BitLocation;
        operation->width = NumberOfBits + 2U;
        operation->addr  = address;
        operation->value = value;

        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(instCmd, pads, CmdRead));
        if (XSPI_IP_SFDP_8D_8D_8D == cmdSfdpMode)
        {
            /* Number of address bytes used for
               read from XSPI1_NBYTES_DWORD: 0b - 4 bytes,  1b - 3 bytes*/
            nBytes = 4U -(uint8)Xspi_Ip_SfdpGetXspi1Param(sfdpTables, XSPI_IP_SFDP_XSPI1_NBYTES_DWORD,
                                                          XSPI_IP_SFDP_XSPI1_NBYTES_SHIFT, XSPI_IP_SFDP_XSPI1_NBYTES_WIDTH, 0x0U);

            /*Add ext comand for DDR mode*/
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(instCmd, pads, Xspi_Ip_SfdpGetCmdExt(sfdpTables, CmdRead)));
            /*in DDR mode, minimum of data is 2 byte.*/
            operation->size = 2U;
        }
        else
        {
            /* Number of address bytes used for Generic Addressable Read/Write Status/Control register commands for volatile registers
               read from SRMAP_NBYTES_DWORD 00b - 1 bytes, 01b - 2 bytes, 10b - 3bytes, 11b - 4 bytes */
            nBytes = 1U + (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_NBYTES_DWORD,
                                                           XSPI_IP_SFDP_SRMAP_NBYTES_SHIFT, XSPI_IP_SFDP_SRMAP_NBYTES_WIDTH, 0x0U);

            operation->size = 1U;
        }

        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(addrCmd, pads, nBytes * 8U));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_DUMMY, pads, Dummy));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(dataCmd, pads, 4U));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));


        /* Build Write LUT sequence */
        operation->command2Lut = lutCount;

        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(instCmd, pads, cmd));
        if (XSPI_IP_SFDP_8D_8D_8D == cmdSfdpMode)
        {
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(instCmd, pads, Xspi_Ip_SfdpGetCmdExt(sfdpTables, cmd)));
        }

        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(addrCmd, pads, nBytes * 8U));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(writeCmd, pads, 0x1U));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));

        /* Other operation fields are unused */
        operation->ctrlCfgPtr = NULL_PTR;


        /*Create an initial operation for read again the value.*/
        operation         = &(pConfig->initConfiguration.operations[initOpCount]);
        initOpCount++;

        operation->opType = XSPI_IP_OP_TYPE_READ_REG;
        operation->addr   = address;
        operation->value  = value;
        operation->shift  = BitLocation;
        operation->width  = NumberOfBits + 2U;
        operation->command2Lut = XSPI_IP_LUT_INVALID;
        operation->ctrlCfgPtr = NULL_PTR;

        operation->command1Lut = lutCount;
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(instCmd, pads, CmdRead));
        if (XSPI_IP_SFDP_8D_8D_8D == cmdSfdpMode)
        {
            /*Add ext comand for DDR mode*/
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(instCmd, pads, Xspi_Ip_SfdpGetCmdExt(sfdpTables, CmdRead)));
            /*in DDR mode, minimum of data is 2 byte.*/
            operation->size = 2U;
        }
        else
        {
            operation->size = 1U;
        }

        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(addrCmd, pads, nBytes * 8U));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_DUMMY, pads, Dummy));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(dataCmd, pads, 4U));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetDummyCycles
 * Description   : Get dummy cycle value..
 */
uint8 Xspi_Ip_SfdpGetDummyCycles(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                        Xspi_Ip_MemoryConfigType *pConfig,
                                        uint32 instance,
                                        uint32 baseAddress
                                )
{
    Xspi_Ip_StatusType status;
    uint8 Dword;
    uint8 DummyCyclePattern      = 0xFFU;
    uint8 DummyCyclePatternExt;
    uint8 CyclePatternShift;
    uint8 CycleSupportShift;
    uint8 CycleSupport;
    uint8 DummyCycle             = 0U;
    uint8 DummyCycleSet          = 0U;
    uint8 NumberOfBits;
    uint8 BitMask                = 0x1FU;             /*5 bit mask*/
    uint8 RegAddress;
    uint8 ByteAddress;
    uint8 BitLocation;
    uint32 AddrOffset;
    uint8 CmdRead;
    uint8 Data[4];
    uint8 SupportedVariableDummy = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_DWORD_9_OFFSET,
                                                                    XSPI_IP_SFDP_SRMAP_DWORD_9_SUPPORTED_VAR_DUMMY_SHIFT,
                                                                    XSPI_IP_SFDP_SRMAP_DWORD_9_SUPPORTED_VAR_DUMMY_WIDTH,0U);

    if(SupportedVariableDummy != 0U)
    {
        /*Number of physical bits used to set wait states   00: 2 bits, 01: 3 bits, 10: 4 bits, 11: 5 bits*/
        NumberOfBits     = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_DWORD_9_OFFSET,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_NUMBER_OF_BITS_SHIFT,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_NUMBER_OF_BITS_WIDTH,0U);

        BitMask          = (BitMask >> (3U - NumberOfBits));

        /*Address of register where wait states bits are located */
        RegAddress       = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_DWORD_9_OFFSET,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_REG_ADDRESS_SHIFT,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_REG_ADDRESS_WIDTH,0U);

        /*Local address for Variable Dummy Cycle Settings bits is found in last byte of the address */
        ByteAddress      = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_DWORD_9_OFFSET,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_BYTE_ADDRESS_SHIFT,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_BYTE_ADDRESS_WIDTH,0U);

        /* Bit location of LSB of physical bits in register*/
        BitLocation      = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_DWORD_9_OFFSET,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_BIT_LOCATION_SHIFT,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_BIT_LOCATION_WIDTH,0U);
        /* Command used for read access */
        CmdRead          = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_DWORD_9_OFFSET,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_CMD_READ_SHIFT,
                                                            XSPI_IP_SFDP_SRMAP_DWORD_9_CMD_READ_WIDTH,0);

        /* Address offset for volatile registers */
        AddrOffset       = (uint32)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_OFFSET_DWORD,
                                                             XSPI_IP_SFDP_SRMAP_OFFSET_SHIFT, XSPI_IP_SFDP_SRMAP_OFFSET_WIDTH, 0x0U);

        /* Write the config register read Sequence into physical LUT registers */
        Xspi_Ip_SfdpInitLutReadCfgReg(sfdpTables, instance, CmdRead);

        status = Xspi_Ip_IpRead(HifBaseAddr, XSPI_IP_COMMAND_LUT, baseAddress + AddrOffset + RegAddress, Data, NULL_PTR, 4U);
        if (STATUS_XSPI_IP_SUCCESS == status)
        {
            DummyCyclePatternExt = (((Data[ByteAddress]) >> BitLocation) & BitMask);
            /*Check dummy cycle from 2, 4, 6 ..., 30 if pattern is same with the parttern of external memory above -> return the dummy cycle*/
            for (DummyCycle = 2U; DummyCycle <= 30U; DummyCycle += 2U)
            {
                /* 02-10 on Dword 13*/
                /* 12-20 on Dword 12*/
                /* 22-30 on Dword 11*/
                Dword             = XSPI_IP_SFDP_SRMAP_SR_DUMMY_CYCLE_PATTERN_02_10_DWORD - (DummyCycle/11U);
                CyclePatternShift = XSPI_IP_SFDP_SRMAP_SR_02_DUMMY_CYCLE_PATTERN_SHIFT + (((DummyCycle-2U)/2U * 6U) % 30U);
                CycleSupportShift = CyclePatternShift + XSPI_IP_SFDP_SRMAP_SR_DUMMY_CYCLE_PATTERN_WIDTH;
                CycleSupport      = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, Dword, CycleSupportShift,XSPI_IP_SFDP_SRMAP_SR_DUMMY_CYCLE_SUPPORT_WIDTH , 0U);

                if (CycleSupport == 1U)
                {
                    DummyCyclePattern = ((uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, Dword, CyclePatternShift, XSPI_IP_SFDP_SRMAP_SR_DUMMY_CYCLE_PATTERN_WIDTH , 0U) & BitMask);
                    DummyCycleSet = DummyCycle;
                    if (DummyCyclePattern == DummyCyclePatternExt)
                    {
                        /*Found DummyCycle and exit*/
                        break;
                    }
                }
            }
            /*DummyCycle > 30 that mean no mapped pattern is found, need to write configuration for dummy cycle*/
            if ((DummyCycle > 30U) && (DummyCyclePattern != 0xFFU))
            {
                /*Create a init operation for set dummy cycle value to the external memory */
                Xspi_Ip_SfdpInitLutSetDummyCycle(sfdpTables,pConfig,AddrOffset + RegAddress, DummyCyclePattern);

                /*Used latest value which is support by the external memory*/
                DummyCycle = DummyCycleSet;
            }
        }
    }
    /*Dummy cycle out of range -> does not support*/
    if ((DummyCycle == 0U) || (DummyCycle > 30U))
    {
        /*The memory does not support Variable nunber of dummy cycles
          Get default value with 200Mhz*/
        DummyCycle = (uint8)Xspi_Ip_SfdpGetXspi1Param(sfdpTables, XSPI_IP_SFDP_XSPI1_DUMMY_DWORD,
                                                      XSPI_IP_SFDP_XSPI1_DUMMY_SHIFT, XSPI_IP_SFDP_XSPI1_DUMMY_WIDTH, 20U);
    }

    return DummyCycle;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetXspi1ReadInfo
 * Description   : Builds configuration for octal DDR (DOPI) mode.
 */
static void Xspi_Ip_SfdpGetXspi1ReadInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                         Xspi_Ip_MemoryConfigType *pConfig,
                                         uint32 instance,
                                         uint32 baseAddress
                                        )
{
    uint8 readInst;
    uint8 cmdExt;
    uint8 dummy;

    /* Get fast read instruction */
    readInst = (uint8)Xspi_Ip_SfdpGetXspi1Param(sfdpTables, XSPI_IP_SFDP_XSPI1_READ_FAST_DWORD,
                                                XSPI_IP_SFDP_XSPI1_READ_FAST_SHIFT, XSPI_IP_SFDP_XSPI1_READ_FAST_WIDTH, 0xEEU);
    /* Get Command Extension */
    cmdExt = Xspi_Ip_SfdpGetCmdExt(sfdpTables, readInst);
    /* Get Dummy cycles */
    dummy = Xspi_Ip_SfdpGetDummyCycles(sfdpTables,pConfig, instance, baseAddress);

    /* Get LUT index */
    pConfig->readLut = lutCount;
    /* Build LUT command */
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, readInst));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, cmdExt));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_ADDR_DDR, XSPI_IP_LUT_PADS_8, (uint8)32U));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_DUMMY, XSPI_IP_LUT_PADS_8, dummy));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_READ_DDR, XSPI_IP_LUT_PADS_8, 0x10U));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetXspi1WriteInfo
 * Description   : Builds configuration for octal DDR (DOPI) mode.
 */
static void Xspi_Ip_SfdpGetXspi1WriteInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                          Xspi_Ip_MemoryConfigType *pConfig
                                         )
{
    uint8 writeInst;
    uint8 cmdExt;

    /* Page program instruction - not in SFDP table */
    writeInst = XSPI_IP_CMD_XSPI_WRITE;
    /* Get Command Extension */
    cmdExt = Xspi_Ip_SfdpGetCmdExt(sfdpTables, writeInst);

    /* Get LUT index */
    pConfig->writeLut = lutCount;
    /* Build LUT command */
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, writeInst));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, cmdExt));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_ADDR_DDR, XSPI_IP_LUT_PADS_8, (uint8)32U));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_WRITE_DDR, XSPI_IP_LUT_PADS_8, 0x10U));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetBasicEraseInstr
 * Description   : Returns instructions for erase type <cnt>.
 */
static uint8 Xspi_Ip_SfdpGetBasicEraseInstr(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                            uint8 cnt,
                                            uint8 *addrbits
                                           )
{
    uint8 addr4;
    uint8 eraseInst;

    /* Check 4-byte instr. support */
    addr4 = (uint8)Xspi_Ip_SfdpGet4BAddParam(sfdpTables, XSPI_IP_SFDP_4BADD_INSTR_SUP_DWORD,
                                             erase4ByteSupShift[cnt], XSPI_IP_SFDP_4BADD_INSTR_SUP_WIDTH, 0x0U);
    if (addr4 == 1U)
    {
        /* Get erase instruction from 4-byte address instructions table */
        eraseInst = (uint8)Xspi_Ip_SfdpGet4BAddParam(sfdpTables, XSPI_IP_SFDP_4BADD_ERASE_INST_DWORD,
                                                     erase4ByteInstShift[cnt], XSPI_IP_SFDP_4BADD_ERASE_INST_WIDTH, 0x0U);
        *addrbits = 32U;
    }
    else
    {
        /* Get erase instruction from basic parameters table */
        eraseInst = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, eraseInstDword[cnt],
                                                     eraseInstShift[cnt], eraseInstWidth[cnt], 0x0U);

        /* No matter the device is operating in 3-Byte or 4-byte Address Mode,
           the Erase with 4-Byte Address instruction will always require 32-bit address */
        if (eraseInst == erase4ByteInst[cnt])
        {
            *addrbits = 32U;
        }
        else
        {
            *addrbits = basicAddrBits;
        }
    }
    return eraseInst;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetXspi1EraseInstr
 * Description   : Returns instructions for erase type <cnt>.
 */
static uint8 Xspi_Ip_SfdpGetXspi1EraseInstr(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                            uint8 cnt
                                           )
{
    uint8 addr4;
    uint8 eraseInst;

    /* Check 4-byte instr. support */
    addr4 = (uint8)Xspi_Ip_SfdpGet4BAddParam(sfdpTables, XSPI_IP_SFDP_4BADD_INSTR_SUP_DWORD,
                                             erase4ByteSupShift[cnt], XSPI_IP_SFDP_4BADD_INSTR_SUP_WIDTH, 0x0U);
    if (addr4 == 1U)
    {
        /* Get erase instruction from 4-byte address instructions table */
        eraseInst = (uint8)Xspi_Ip_SfdpGet4BAddParam(sfdpTables, XSPI_IP_SFDP_4BADD_ERASE_INST_DWORD,
                                                     erase4ByteInstShift[cnt], XSPI_IP_SFDP_4BADD_ERASE_INST_WIDTH, 0x0U);
    }
    else
    {
        /* Get erase instruction from basic parameters table */
        eraseInst = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, eraseInstDword[cnt],
                                                     eraseInstShift[cnt], eraseInstWidth[cnt], 0x0U);
    }
    return eraseInst;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetBasicEraseInfo
 * Description   : Builds configuration for SPI mode.
 */
static void Xspi_Ip_SfdpGetBasicEraseInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                          Xspi_Ip_MemoryConfigType * pConfig
                                         )
{
    uint8 eraseInst;
    uint8 eraseSize;
    uint8 addrbits;
    uint8 cnt;

    /* Loop through the 4 possible erase types */
    for (cnt = 0U; cnt < 4U; cnt++)
    {
        /* Get erase size */
        eraseSize = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, eraseSizeDword[cnt],
                                                     eraseSizeShift[cnt], eraseSizeWidth[cnt], 0x0U);
        pConfig->eraseSettings.eraseTypes[cnt].size = eraseSize;
        if (eraseSize > 0U)
        {
            /* Get erase instruction */
            eraseInst = Xspi_Ip_SfdpGetBasicEraseInstr(sfdpTables, cnt, &addrbits);
            /* Get LUT index */
            pConfig->eraseSettings.eraseTypes[cnt].eraseLut = lutCount;
            /* Build LUT command */
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, cmdPads, eraseInst));
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_ADDR, cmdPads, (uint8)addrbits));
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
        }
        else
        {
            /* Erase type not supported */
            pConfig->eraseSettings.eraseTypes[cnt].eraseLut = XSPI_IP_LUT_INVALID;
        }
    }

    /* Chip erase */
    eraseInst = XSPI_IP_CMD_BASIC_CHIP_ERASE;
    pConfig->eraseSettings.chipEraseLut = lutCount;
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, cmdPads, eraseInst));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetXspi1EraseInfo
 * Description   : Builds configuration for octal DDR (DOPI) mode.
 */
static void Xspi_Ip_SfdpGetXspi1EraseInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                          Xspi_Ip_MemoryConfigType *pConfig
                                         )
{
    uint8 eraseInst;
    uint8 eraseSize;
    uint8 eraseExt;
    uint8 cnt;

    /* Loop through the 4 possible erase types */
    for (cnt = 0U; cnt < 4U; cnt++)
    {
        /* Get erase size */
        eraseSize = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, eraseSizeDword[cnt],
                                                     eraseSizeShift[cnt], eraseSizeWidth[cnt], 0x0U);
        pConfig->eraseSettings.eraseTypes[cnt].size = eraseSize;
        if (eraseSize > 0U)
        {
            /* Get erase instruction */
            eraseInst = Xspi_Ip_SfdpGetXspi1EraseInstr(sfdpTables, cnt);
            eraseExt = Xspi_Ip_SfdpGetCmdExt(sfdpTables, eraseInst);
            /* Get LUT index */
            pConfig->eraseSettings.eraseTypes[cnt].eraseLut = lutCount;
            /* Build LUT command */
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, eraseInst));
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, eraseExt));
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_ADDR_DDR, XSPI_IP_LUT_PADS_8, (uint8)32U));
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
        }
        else
        {
            /* Erase type not supported */
            pConfig->eraseSettings.eraseTypes[cnt].eraseLut = XSPI_IP_LUT_INVALID;
        }
    }

    /* Check chip erase support */
    eraseInst = (uint8)Xspi_Ip_SfdpGetXspi1Param(sfdpTables, XSPI_IP_SFDP_XSPI1_CHIP_ERASE_DWORD,
                                                 XSPI_IP_SFDP_XSPI1_CHIP_ERASE_SHIFT, XSPI_IP_SFDP_XSPI1_CHIP_ERASE_WIDTH, 0x0U);
    if (eraseInst == 0U)
    {
        pConfig->eraseSettings.chipEraseLut = XSPI_IP_LUT_INVALID;
    }
    else
    {
        pConfig->eraseSettings.chipEraseLut = lutCount;
        /* Build LUT command */
        eraseInst = XSPI_IP_CMD_XSPI_CHIP_ERASE;
        eraseExt = Xspi_Ip_SfdpGetCmdExt(sfdpTables, eraseInst);
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, eraseInst));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, eraseExt));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetBasicStatusInfo
 * Description   : Builds configuration for SPI mode.
 */
static void Xspi_Ip_SfdpGetBasicStatusInfo(Xspi_Ip_MemoryConfigType *pConfig)
{
    uint8 instruction;
    Xspi_Ip_StatusConfigType *statusConfig;

    statusConfig = &(pConfig->statusConfig);

    /* Build LUT sequence for read status reg. */

    statusConfig->statusRegReadLut = lutCount;
    instruction = XSPI_IP_CMD_BASIC_READ_SR;
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, cmdPads, instruction));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_READ, cmdPads, 0x10));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));


    /* Build LUT sequence for write status reg. */
    statusConfig->statusRegWriteLut = lutCount;
    instruction = XSPI_IP_CMD_BASIC_WRITE_SR;
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, cmdPads, instruction));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_WRITE, cmdPads, 0x1U));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));

    /* Build LUT sequence for write enable */
    statusConfig->writeEnableLut = lutCount;
    instruction = XSPI_IP_CMD_BASIC_WRITE_ENABLE;
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, cmdPads, instruction));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetXspi1StatusInfo
 * Description   : Builds configuration for octal DDR (DOPI) mode.
 */
static void Xspi_Ip_SfdpGetXspi1StatusInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                           Xspi_Ip_MemoryConfigType *pConfig
                                          )
{
    uint8 instruction;
    uint8 cmdExt;
    uint8 dummy;
    Xspi_Ip_StatusConfigType *statusConfig;

    statusConfig = &(pConfig->statusConfig);

    /* Build LUT sequence for read status reg. */
    statusConfig->statusRegReadLut = lutCount;

    instruction = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_READ_CMD_DWORD,
                                             XSPI_IP_SFDP_SRMAP_READ_CMD_SHIFT, XSPI_IP_SFDP_SRMAP_READ_CMD_WIDTH, XSPI_IP_CMD_XSPI_READ_SR);
    cmdExt = Xspi_Ip_SfdpGetCmdExt(sfdpTables, instruction);
    dummy = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_DUMMY_8D_DWORD,
                                             XSPI_IP_SFDP_SRMAP_DUMMY_8D_SHIFT, XSPI_IP_SFDP_SRMAP_DUMMY_8D_WIDTH, 0x0U);
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, instruction));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, cmdExt));
    Xspi_Ip_SfdpLutAddSrAddr(&(pConfig->lutSequences), sfdpTables);
    if (dummy != 0U)
    {
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_DUMMY, XSPI_IP_LUT_PADS_8, dummy));
    }
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_READ_DDR, XSPI_IP_LUT_PADS_8, 0x10));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));

    /* Build LUT sequence for write status reg. */
    statusConfig->statusRegWriteLut = lutCount;
    instruction = XSPI_IP_CMD_XSPI_WRITE_SR;
    cmdExt = Xspi_Ip_SfdpGetCmdExt(sfdpTables, instruction);
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, instruction));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, cmdExt));
    Xspi_Ip_SfdpLutAddSrAddr(&(pConfig->lutSequences), sfdpTables);
    /* Use SDR write because reg. size is 1 */
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_WRITE, XSPI_IP_LUT_PADS_8, 0x2U));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));

    /* Build LUT sequence for write enable */
    statusConfig->writeEnableLut = lutCount;
    instruction = XSPI_IP_CMD_XSPI_WRITE_ENABLE;
    cmdExt = Xspi_Ip_SfdpGetCmdExt(sfdpTables, instruction);
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, instruction));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, cmdExt));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpConfigReset1
 * Description   : Configure reset settings - option 1.
 */
static void Xspi_Ip_SfdpConfigReset1(const Xspi_Ip_MemoryConfigType * pConfig,
                                     const Xspi_Ip_ResetConfigType *resetSettings,
                                     Xspi_Ip_LutPadsType pads
                                    )
{
    /* drive Fh on all 4 data wires for 8 clocks */
    /* Not implemented */
    (void)pConfig;
    (void)resetSettings;
    (void)pads;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpConfigReset2
 * Description   : Configure reset settings - option 2.
 */
static void Xspi_Ip_SfdpConfigReset2(const Xspi_Ip_MemoryConfigType * pConfig,
                                     const Xspi_Ip_ResetConfigType *resetSettings,
                                     Xspi_Ip_LutPadsType pads
                                    )
{
    /* drive Fh on all 4 data wires for 10 clocks if device is operating in 4-byte address mode */
    /* Not implemented */
    (void)pConfig;
    (void)resetSettings;
    (void)pads;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpConfigReset4
 * Description   : Configure reset settings - option 4.
 */
static void Xspi_Ip_SfdpConfigReset4(const Xspi_Ip_MemoryConfigType * pConfig,
                                     const Xspi_Ip_ResetConfigType *resetSettings,
                                     Xspi_Ip_LutPadsType pads
                                    )
{
    /* drive Fh on all 4 data wires for 16 clocks */
    /* Not implemented */
    (void)pConfig;
    (void)resetSettings;
    (void)pads;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpConfigReset8
 * Description   : Configure reset settings - option 8.
 */
static void Xspi_Ip_SfdpConfigReset8(const Xspi_Ip_MemoryConfigType * pConfig,
                                     Xspi_Ip_ResetConfigType *resetSettings,
                                     Xspi_Ip_LutPadsType pads
                                    )
{
    /* issue instruction F0h */
    resetSettings->resetCmdLut = lutCount;
    resetSettings->resetCmdCount = 1U;
    /* Build LUT sequence */
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, pads, 0xF0U));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpConfigReset16
 * Description   : Configure reset settings - option 16.
 */
static void Xspi_Ip_SfdpConfigReset16(const Xspi_Ip_MemoryConfigType * pConfig,
                                      Xspi_Ip_ResetConfigType *resetSettings,
                                      Xspi_Ip_LutPadsType pads
                                     )
{
    /* issue reset enable instruction 66h, then issue reset instruction 99h.
       The reset enable, reset sequence may be issued on 1, 2, 4, or 8 wires depending on the device operating mode. */
    resetSettings->resetCmdLut = lutCount;
    resetSettings->resetCmdCount = 2U;
    /* 1st LUT sequence - 0x66 */
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, pads, 0x66U));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
    /* 2nd LUT sequence - 0x99 */
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, pads, 0x99U));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpConfigResetOthers
 * Description   : Configure reset settings for 1, 2, 4 wires
 */
static void Xspi_Ip_SfdpConfigResetOthers(uint8 resetOption,
                                          const Xspi_Ip_MemoryConfigType * pConfig,
                                          Xspi_Ip_ResetConfigType *resetSettings,
                                          Xspi_Ip_LutPadsType pads
                                         )
{
    if ((resetOption & 0x1U) != 0U)
    {
        Xspi_Ip_SfdpConfigReset1(pConfig, resetSettings, pads);
        /* drive Fh on all 4 data wires for 8 clocks */
    }
    else if ((resetOption & 0x2U) != 0U)
    {
        Xspi_Ip_SfdpConfigReset2(pConfig, resetSettings, pads);
        /* drive Fh on all 4 data wires for 10 clocks if device is operating in 4-byte address mode */
    }
    else if ((resetOption & 0x4U) != 0U)
    {
        Xspi_Ip_SfdpConfigReset4(pConfig, resetSettings, pads);
        /* drive Fh on all 4 data wires for 16 clocks */
    }
    else
    {
        /* unknown reset sequence */
        resetSettings->resetCmdLut = XSPI_IP_LUT_INVALID;
        resetSettings->resetCmdCount = 0U;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetBasicResetInfo
 * Description   : Configure reset settings - XPI mode.
 */
static void Xspi_Ip_SfdpGetBasicResetInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                          const Xspi_Ip_MemoryConfigType *pConfig,
                                          Xspi_Ip_ResetConfigType *resetSettings,
                                          Xspi_Ip_LutPadsType pads
                                         )
{
    uint8 resetOption;

    resetOption = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, XSPI_IP_SFDP_BASIC_SW_RESET_DWORD,
                                                   XSPI_IP_SFDP_BASIC_SW_RESET_SHIFT, XSPI_IP_SFDP_BASIC_SW_RESET_WIDTH, 0x0U);
    if ((resetOption & 0x10U) != 0U)
    {
        /* issue reset enable instruction 66h, then issue reset instruction 99h.
           The reset enable, reset sequence may be issued on 1, 2, 4, or 8 wires depending on the device operating mode. */
        Xspi_Ip_SfdpConfigReset16(pConfig, resetSettings, pads);
    }
    else if ((resetOption & 0x8U) != 0U)
    {
        Xspi_Ip_SfdpConfigReset8(pConfig, resetSettings, pads);
        /* issue instruction F0h */
    }
    else
    {
        Xspi_Ip_SfdpConfigResetOthers(resetOption, pConfig, resetSettings, pads);
    }
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetXspi1InitResetInfo
 * Description   : Configure initial reset settings - XPI mode
 */
static void Xspi_Ip_SfdpGetXspi1InitResetInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                              Xspi_Ip_MemoryConfigType *pConfig
                                             )
{
    uint8 rSup;
    uint8 rEnSup;
    uint8 instruction;

    /* Set the default value to be disabled */
    pConfig->initResetSettings.resetCmdLut = XSPI_IP_LUT_INVALID;
    pConfig->initResetSettings.resetCmdCount = 0U;

    rEnSup = (uint8)Xspi_Ip_SfdpGetXspi1Param(sfdpTables, XSPI_IP_SFDP_XSPI1_RESET_EN_DWORD,
                                              XSPI_IP_SFDP_XSPI1_RESET_EN_SHIFT, XSPI_IP_SFDP_XSPI1_RESET_EN_WIDTH, 0x0U);
    rSup = (uint8)Xspi_Ip_SfdpGetXspi1Param(sfdpTables, XSPI_IP_SFDP_XSPI1_RESET_DEF_DWORD,
                                            XSPI_IP_SFDP_XSPI1_RESET_DEF_SHIFT, XSPI_IP_SFDP_XSPI1_RESET_DEF_WIDTH, 0x0U);
    if ((rEnSup == 1U) && (rSup == 1U))
    {
        /* 0x66, 0x99 reset sequence */
        pConfig->initResetSettings.resetCmdLut = lutCount;
        pConfig->initResetSettings.resetCmdCount = 2U;
        instruction = XSPI_IP_CMD_XSPI_RESET_ENABLE;
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, cmdPadsInit, instruction));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, cmdPadsInit, 0x0U));

        instruction = XSPI_IP_CMD_XSPI_RESET_DEF;
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, cmdPadsInit, instruction));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, cmdPadsInit, 0x0U));
    }
    else
    {
        rSup = (uint8)Xspi_Ip_SfdpGetXspi1Param(sfdpTables, XSPI_IP_SFDP_XSPI1_RESET_DWORD,
                                                XSPI_IP_SFDP_XSPI1_RESET_SHIFT, XSPI_IP_SFDP_XSPI1_RESET_WIDTH, 0x0U);
        if (rSup == 1U)
        {
            /* 0xF0 reset command */
            pConfig->initResetSettings.resetCmdLut = lutCount;
            pConfig->initResetSettings.resetCmdCount = 1U;
            instruction = XSPI_IP_CMD_XSPI_RESET;
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, cmdPadsInit, instruction));
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, cmdPadsInit, 0x0U));
        }
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetBasicSuspendInfo
 * Description   : Configure  suspend settings - SPI mode
 */
static void Xspi_Ip_SfdpGetBasicSuspendInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                            Xspi_Ip_MemoryConfigType * pConfig
                                           )
{
    uint8 esus;
    uint8 eres;
    uint8 psus;
    uint8 pres;

    esus = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, XSPI_IP_SFDP_BASIC_ESUS_INSTR_DWORD,
                                            XSPI_IP_SFDP_BASIC_ESUS_INSTR_SHIFT, XSPI_IP_SFDP_BASIC_ESUS_INSTR_WIDTH, 0xB0U);
    eres = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, XSPI_IP_SFDP_BASIC_ERES_INSTR_DWORD,
                                            XSPI_IP_SFDP_BASIC_ERES_INSTR_SHIFT, XSPI_IP_SFDP_BASIC_ERES_INSTR_WIDTH, 0x30U);
    psus = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, XSPI_IP_SFDP_BASIC_PSUS_INSTR_DWORD,
                                            XSPI_IP_SFDP_BASIC_PSUS_INSTR_SHIFT, XSPI_IP_SFDP_BASIC_PSUS_INSTR_WIDTH, 0xB0U);
    pres = (uint8)Xspi_Ip_SfdpGetBasicParam(sfdpTables, XSPI_IP_SFDP_BASIC_PRES_INSTR_DWORD,
                                            XSPI_IP_SFDP_BASIC_PRES_INSTR_SHIFT, XSPI_IP_SFDP_BASIC_PRES_INSTR_WIDTH, 0x30U);

    /* Erase suspend sequence */
    pConfig->suspendSettings.eraseSuspendLut = lutCount;
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, cmdPads, esus));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
    /* Erase resume sequence */
    pConfig->suspendSettings.eraseResumeLut = lutCount;
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, cmdPads, eres));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
    /* Program suspend sequence */
    if (esus == psus)
    {
        pConfig->suspendSettings.programSuspendLut = pConfig->suspendSettings.eraseSuspendLut;
    }
    else
    {
        pConfig->suspendSettings.programSuspendLut = lutCount;
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, cmdPads, psus));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
    }
    /* Program resume sequence */
    if (eres == pres)
    {
        pConfig->suspendSettings.programResumeLut = pConfig->suspendSettings.eraseResumeLut;
    }
    else
    {
        pConfig->suspendSettings.programResumeLut = lutCount;
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, cmdPads, pres));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetXspi1SuspendInfo
 * Description   : Configure  suspend settings - XPI mode
 */
static void Xspi_Ip_SfdpGetXspi1SuspendInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                            Xspi_Ip_MemoryConfigType *pConfig
                                           )
{
    uint8 esus;
    uint8 eres;
    uint8 psus;
    uint8 pres;
    uint8 cmdExt;

    esus = (uint8)Xspi_Ip_SfdpGetXspi1Param(sfdpTables, XSPI_IP_SFDP_BASIC_ESUS_INSTR_DWORD,
                                            XSPI_IP_SFDP_BASIC_ESUS_INSTR_SHIFT, XSPI_IP_SFDP_BASIC_ESUS_INSTR_WIDTH, 0xB0U);
    eres = (uint8)Xspi_Ip_SfdpGetXspi1Param(sfdpTables, XSPI_IP_SFDP_BASIC_ERES_INSTR_DWORD,
                                            XSPI_IP_SFDP_BASIC_ERES_INSTR_SHIFT, XSPI_IP_SFDP_BASIC_ERES_INSTR_WIDTH, 0x30U);
    psus = (uint8)Xspi_Ip_SfdpGetXspi1Param(sfdpTables, XSPI_IP_SFDP_BASIC_PSUS_INSTR_DWORD,
                                            XSPI_IP_SFDP_BASIC_PSUS_INSTR_SHIFT, XSPI_IP_SFDP_BASIC_PSUS_INSTR_WIDTH, 0xB0U);
    pres = (uint8)Xspi_Ip_SfdpGetXspi1Param(sfdpTables, XSPI_IP_SFDP_BASIC_PRES_INSTR_DWORD,
                                            XSPI_IP_SFDP_BASIC_PRES_INSTR_SHIFT, XSPI_IP_SFDP_BASIC_PRES_INSTR_WIDTH, 0x30U);

    /* Erase suspend sequence */
    pConfig->suspendSettings.eraseSuspendLut = lutCount;
    cmdExt = Xspi_Ip_SfdpGetCmdExt(sfdpTables, esus);
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, esus));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, cmdExt));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
    /* Erase resume sequence */
    pConfig->suspendSettings.eraseResumeLut = lutCount;
    cmdExt = Xspi_Ip_SfdpGetCmdExt(sfdpTables, eres);
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, eres));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, cmdExt));
    Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
    /* Program suspend sequence */
    if (esus == psus)
    {
        pConfig->suspendSettings.programSuspendLut = pConfig->suspendSettings.eraseSuspendLut;
    }
    else
    {
        pConfig->suspendSettings.programSuspendLut = lutCount;
        cmdExt = Xspi_Ip_SfdpGetCmdExt(sfdpTables, psus);
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, psus));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, cmdExt));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
    }
    /* Program resume sequence */
    if (eres == pres)
    {
        pConfig->suspendSettings.programResumeLut = pConfig->suspendSettings.eraseResumeLut;
    }
    else
    {
        pConfig->suspendSettings.programResumeLut = lutCount;
        cmdExt = Xspi_Ip_SfdpGetCmdExt(sfdpTables, pres);
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, pres));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD_DDR, XSPI_IP_LUT_PADS_8, cmdExt));
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpAdd2dopiOperation
 * Description   : Add a DOPI switch command to the operation list
 */
static void Xspi_Ip_SfdpAdd2dopiOperation(const Xspi_Ip_MemoryConfigType *pConfig,
                                          uint8 seqSize,
                                          const uint32 *words
                                         )
{
    Xspi_Ip_InitOperationType *operation;
    uint8 nextByte;
    uint8 cnt;

    if (initOpCount >= pConfig->initConfiguration.opCount)
    {
        /* operations list not big enough */
        overflow = TRUE;
    }
    else
    {
        operation = &(pConfig->initConfiguration.operations[initOpCount]);
        initOpCount++;
        operation->opType = XSPI_IP_OP_TYPE_CMD;
        operation->command1Lut = lutCount;
        operation->addr = 0U;
        /* Build LUT sequence for this command */
        for (cnt = 0U; cnt < seqSize; cnt++)
        {
            nextByte = (uint8)((words[dopiSwitchWord[cnt]] >> dopiSwitchShift[cnt]) & 0xFFU);
            Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_CMD, XSPI_IP_LUT_PADS_1, nextByte));
        }
        /* Add STOP instruction */
        Xspi_Ip_SfdpLutAdd(&(pConfig->lutSequences), Xspi_Ip_PackLut(XSPI_IP_LUT_INSTR_STOP, XSPI_IP_LUT_PADS_1, 0x0U));
        /* Other operation fields are unused */
        operation->command2Lut = XSPI_IP_LUT_INVALID;
        operation->weLut = XSPI_IP_LUT_INVALID;
        operation->size  = 0U;
        operation->shift = 0U;
        operation->width = 0U;
        operation->value = 0U;
        operation->ctrlCfgPtr = NULL_PTR;
    }

    return;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpAddCheckBusyOperation
 * Description   : Add a READ_REG operation to check the BUSY flag of the status register.
 */
static void Xspi_Ip_SfdpAddCheckBusyOperation(const Xspi_Ip_SfdpTablesContainer *sfdpTables, const Xspi_Ip_MemoryConfigType *pConfig)
{
    Xspi_Ip_InitOperationType *operation;
    if (initOpCount >= pConfig->initConfiguration.opCount)
    {
        /* operations list not big enough */
        overflow = TRUE;
    }
    else
    {
        /* Build a read operation to check the BUSY flag of the status register */
        operation = &(pConfig->initConfiguration.operations[initOpCount]);
        initOpCount++;

        operation->opType      = XSPI_IP_OP_TYPE_READ_REG;
        operation->command1Lut = pConfig->statusConfig.statusRegReadLut;
        operation->size        = 4U;
        operation->shift       = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_WIP_OFFSET_DWORD,
                                                                XSPI_IP_SFDP_SRMAP_WIP_OFFSET_SHIFT, XSPI_IP_SFDP_SRMAP_WIP_OFFSET_WIDTH, 0x0U);
        operation->value       = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_WIP_VALUE_DWORD,
                                                                     XSPI_IP_SFDP_SRMAP_WIP_VALUE_SHIFT, XSPI_IP_SFDP_SRMAP_WIP_VALUE_WIDTH, 0x0U);/* Reverse: wait until not busy */
        operation->width       = 1U;

        /* Other operation fields are unused */
        operation->command2Lut = XSPI_IP_LUT_INVALID;
        operation->weLut       = XSPI_IP_LUT_INVALID;
        operation->addr        = 0U;
        operation->ctrlCfgPtr  = NULL_PTR;
    }
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetXspi1InitOpInfo
 * Description   : Configure initial operations list - XPI mode
 */
static void Xspi_Ip_SfdpGetXspi1InitOpInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                           Xspi_Ip_MemoryConfigType *pConfig
                                          )
{
    uint8 cnt;
    uint8 seqSize;

    if (sfdpTables->paramTableLength_2dopi > 0U)
    {
        for (cnt = 0U; cnt < (sfdpTables->paramTableLength_2dopi - 1U); cnt += 2U)
        {
            seqSize = (uint8)Xspi_Ip_SfdpGet2DopiParam(sfdpTables, cnt + 1U,
                                                       XSPI_IP_SFDP_2DOPI_CMD_LEN_SHIFT, XSPI_IP_SFDP_2DOPI_CMD_LEN_WIDTH, 0x0U);
            if (seqSize == 0U)
            {
                /* No more commands */
                break;
            }
            /* Add a wait operation to ensure the previous command is completed, needed for write in a non-volatile register */
            Xspi_Ip_SfdpAddCheckBusyOperation(sfdpTables, pConfig);

            Xspi_Ip_SfdpAdd2dopiOperation(pConfig, seqSize, &sfdpTables->paramTable_2dopi[cnt]);
        }
    }
    /* Update operations count */
    pConfig->initConfiguration.opCount = initOpCount;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetBasicInitOpInfo
 * Description   : Configure initial operations list - XPI mode
 */
static void Xspi_Ip_SfdpGetBasicInitOpInfo(Xspi_Ip_MemoryConfigType * pConfig)
{
    /* Init operations already added, update operations count */
    pConfig->initConfiguration.opCount = initOpCount;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGet0xxInfo
 * Description   : Configure 0xx capabilities - XPI mode
 */
static void Xspi_Ip_SfdpGet0xxInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                   Xspi_Ip_MemoryConfigType * pConfig
                                  )
{
    /* Not implemented */
    (void)sfdpTables;
    (void)pConfig;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpConfigureOther
 * Description   : Configure unsupported features
 */
static void Xspi_Ip_SfdpConfigureOther(Xspi_Ip_MemoryConfigType * pConfig)
{
    pConfig->readIdSettings.readIdLut = XSPI_IP_LUT_INVALID;
    pConfig->initCallout = NULL_PTR;
    pConfig->resetCallout = NULL_PTR;
    pConfig->errorCheckCallout = NULL_PTR;
    pConfig->ctrlAutoCfgPtr = NULL_PTR;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetSize
 * Description   : Builds configuration for octal DDR (DOPI) mode.
 */
static void Xspi_Ip_SfdpGetSize(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                Xspi_Ip_MemoryConfigType *pConfig
                               )
{
    uint32 size;

    /* Dword 2 of parameter table: Flash Memory Density */
    size = Xspi_Ip_SfdpGetBasicParam(sfdpTables, XSPI_IP_SFDP_BASIC_MEM_SIZE_DWORD,
                                     XSPI_IP_SFDP_BASIC_MEM_SIZE_SHIFT, XSPI_IP_SFDP_BASIC_MEM_SIZE_WIDTH, 0xFFFFFU);
    /* check MSB */
    if ((size & 0x80000000U) == 0U)
    {
        pConfig->memSize = (size + 1U) >> 3U;
    }
    else
    {
        pConfig->memSize = ((uint32)1U << ((size & (~(uint32)0x80000000U)) - (uint32)3U));
    }

    /* Dword 11 of parameter table: Page Size */
    size = Xspi_Ip_SfdpGetBasicParam(sfdpTables, XSPI_IP_SFDP_BASIC_PAGE_SIZE_DWORD,
                                     XSPI_IP_SFDP_BASIC_PAGE_SIZE_SHIFT, XSPI_IP_SFDP_BASIC_PAGE_SIZE_WIDTH, 8U);
    pConfig->pageSize = ((uint32)1U << size);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_GetBasicInfo
 * Description   : Builds basic configurations
 */
static inline void Xspi_Ip_SfdpGetBasicInfo(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                            Xspi_Ip_MemoryConfigType * pConfig
                                           )
{
    /* Configure read command */
    if (XSPI_IP_SFDP_READ_MODE_1S_1S_1S == modeIndex)
    {
        Xspi_Ip_SfdpConfigBasicRead(sfdpTables, pConfig);
    }
    else
    {
        Xspi_Ip_SfdpGetBasicFastReadInfo(sfdpTables, pConfig);
    }
    /* Configure write command */
    Xspi_Ip_SfdpGetBasicWriteInfo(sfdpTables, pConfig);
    /* Configure erase commands */
    Xspi_Ip_SfdpGetBasicEraseInfo(sfdpTables, pConfig);
    /* Configure status register */
    Xspi_Ip_SfdpGetBasicStatusInfo(pConfig);

    /* Configure initial reset settings */
    Xspi_Ip_SfdpGetBasicResetInfo(sfdpTables, pConfig, &(pConfig->initResetSettings), cmdPadsInit);

    /* Configure suspend settings */
    Xspi_Ip_SfdpGetBasicSuspendInfo(sfdpTables, pConfig);
    /* Configure initial operations list */
    Xspi_Ip_SfdpGetBasicInitOpInfo(pConfig);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpConfigureReadStatus
 * Description   : Builds configuration for initial read status reg.
 */
static void Xspi_Ip_SfdpConfigureReadStatus(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                                Xspi_Ip_MemoryConfigType *pConfig
                                               )
{
    Xspi_Ip_StatusConfigType *statusConfig;
    uint32 busyMask       = 0U;
    uint32 ProgramErrorValue  = 0U;
    uint32 ProgramErrorOffset = 0U;
    uint32 EraseErrorValue  = 0U;
    uint32 EraseErrorOffset = 0U;
    uint32 BusyOffset       = 0U;
    statusConfig = &(pConfig->statusConfig);

    statusConfig->regSize = 4U;
    statusConfig->blockProtectionOffset = 0U;
    statusConfig->blockProtectionWidth = 0U;
    statusConfig->blockProtectionValue = 0U;

    /* Busy bit meaning is reversed (0: Positive (WIP=1 means write is in progress); 1: Inverted (WIP=0 means write is in progress) */
    statusConfig->busyValue = (uint8)(1U - Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_WIP_VALUE_DWORD,
                                                                     XSPI_IP_SFDP_SRMAP_WIP_VALUE_SHIFT, XSPI_IP_SFDP_SRMAP_WIP_VALUE_WIDTH, 0x0U));

    statusConfig->idleValue = 1U - statusConfig->busyValue;

    BusyOffset = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_WIP_OFFSET_DWORD,
                                                                XSPI_IP_SFDP_SRMAP_WIP_OFFSET_SHIFT, XSPI_IP_SFDP_SRMAP_WIP_OFFSET_WIDTH, 0x0U);
    /*add mask for Busy bit*/
    busyMask = (uint32)1U << BusyOffset;

    ProgramErrorValue = (1U - Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_PER_VALUE_DWORD,
                                                                XSPI_IP_SFDP_SRMAP_PER_VALUE_SHIFT, XSPI_IP_SFDP_SRMAP_PER_VALUE_WIDTH, 0x0U));

    if (ProgramErrorValue != 0U)
    {
        ProgramErrorOffset = Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_PER_OFFSET_DWORD,
                                                                XSPI_IP_SFDP_SRMAP_PER_OFFSET_SHIFT, XSPI_IP_SFDP_SRMAP_PER_OFFSET_WIDTH, 0x0U);
        /*Add mask for Program Error bit when the bit = 1 means an error*/
        busyMask |= ((uint32)1U << ProgramErrorOffset);
    }
    EraseErrorValue = (1U - Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_PER_VALUE_DWORD,
                                                                XSPI_IP_SFDP_SRMAP_PER_VALUE_SHIFT, XSPI_IP_SFDP_SRMAP_PER_VALUE_WIDTH, 0x0U));
    if (EraseErrorValue != 0U)
    {
        EraseErrorOffset = Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_EER_OFFSET_DWORD,
                                                                XSPI_IP_SFDP_SRMAP_EER_OFFSET_SHIFT, XSPI_IP_SFDP_SRMAP_EER_OFFSET_WIDTH, 0x0U);
        /*Add mask for Erase Error bit when the bit = 1 means an error*/
        busyMask |= ((uint32)1U << EraseErrorOffset);
    }
    statusConfig->busyMask = busyMask;

    statusConfig->writeEnableOffset = (uint8)Xspi_Ip_SfdpGetSRMapParam(sfdpTables, XSPI_IP_SFDP_SRMAP_WEL_OFFSET_DWORD,
                                                                       XSPI_IP_SFDP_SRMAP_WEL_OFFSET_SHIFT, XSPI_IP_SFDP_SRMAP_WEL_OFFSET_WIDTH, 0x1U);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ConfigureBasic
 * Description   : Builds configuration for basic mode.
 */
static Xspi_Ip_StatusType Xspi_Ip_ConfigureBasic(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                                 Xspi_Ip_MemoryConfigType *pConfig
                                                )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;

    /* Get size, page size */
    Xspi_Ip_SfdpGetSize(sfdpTables, pConfig);
    /* Get addres size for read/write commands */
    Xspi_Ip_SfdpGetBasicAddrBits(sfdpTables, pConfig);

    /* Configure initial read status register */
    Xspi_Ip_SfdpConfigureReadStatus(sfdpTables, pConfig);
    if(XSPI_IP_LUT_PADS_4 == readModeDataPads[modeIndex])
    {
        /* Check QE bit */
        Xspi_Ip_SfdpConfigureQE(sfdpTables, pConfig);
    }

    /* Get basic info: read, write, erase, reset, suspend */
    Xspi_Ip_SfdpGetBasicInfo(sfdpTables, pConfig);

    /* Configure 0xx capabilities */
    Xspi_Ip_SfdpGet0xxInfo(sfdpTables, pConfig);
    /* Configure unsupported features */
    Xspi_Ip_SfdpConfigureOther(pConfig);

    /* Check for LUT or Init operations overflow */
    if (overflow == TRUE)
    {
        status = STATUS_XSPI_IP_ERROR;
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetXspi1ResetConfig
 * Description   : Builds Xspi1 configure reset settings and initial reset settings.
 */
static void Xspi_Ip_SfdpGetXspi1ResetConfig(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                            Xspi_Ip_MemoryConfigType * pConfig
                                           )
{
    /* Configure initial reset settings */
    Xspi_Ip_SfdpGetXspi1InitResetInfo(sfdpTables, pConfig);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpGetXspi1Info
 * Description   : Builds Xspi1 configurations.
 */
static inline void Xspi_Ip_SfdpGetXspi1Info(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                            Xspi_Ip_MemoryConfigType * pConfig,
                                            uint32 instance,
                                            uint32 baseAddress
                                           )
{

    /* Configure status register */
    Xspi_Ip_SfdpGetXspi1StatusInfo(sfdpTables, pConfig);
    /* Configure read command */
    Xspi_Ip_SfdpGetXspi1ReadInfo(sfdpTables, pConfig, instance, baseAddress);
    /* Configure write command */
    Xspi_Ip_SfdpGetXspi1WriteInfo(sfdpTables, pConfig);
    /* Configure erase commands */
    Xspi_Ip_SfdpGetXspi1EraseInfo(sfdpTables, pConfig);

    /* Configure reset settings and initial reset settings */
    Xspi_Ip_SfdpGetXspi1ResetConfig(sfdpTables, pConfig);
    /* Configure suspend settings */
    Xspi_Ip_SfdpGetXspi1SuspendInfo(sfdpTables, pConfig);
    if(XSPI_IP_SFDP_8D_8D_8D != cmdSfdpMode)
    {
        /* Configure initial operations list */
        Xspi_Ip_SfdpGetXspi1InitOpInfo(sfdpTables, pConfig);
    }
    pConfig->initConfiguration.opCount = initOpCount;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ConfigureXspi1
 * Description   : Builds octal DDR (DOPI) configuration for xSPI 1.0 devices.
 */
static Xspi_Ip_StatusType Xspi_Ip_ConfigureXspi1(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                                 Xspi_Ip_MemoryConfigType *pConfig,
                                                 uint32 instance,
                                                 uint32 baseAddress
                                                )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;

    /* Get size, page size */
    Xspi_Ip_SfdpGetSize(sfdpTables, pConfig);

    /* Configure initial read status register */
    Xspi_Ip_SfdpConfigureReadStatus(sfdpTables, pConfig);

    /* Get Xspi1 info: read, write, erase, reset, suspend */
    Xspi_Ip_SfdpGetXspi1Info(sfdpTables, pConfig, instance, baseAddress);

    /* Configure 0xx capabilities */
    Xspi_Ip_SfdpGet0xxInfo(sfdpTables, pConfig);
    /* Configure unsupported features */
    Xspi_Ip_SfdpConfigureOther(pConfig);

    /* Check for LUT or Init operations overflow */
    if (overflow == TRUE)
    {
        status = STATUS_XSPI_IP_ERROR;
    }
    return status;
}


/*******************************************************************************
 * Code
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SfdpConfigure
 * Description   : Check xSPI 1.0 support
 */
static Xspi_Ip_StatusType Xspi_Ip_SfdpConfigure(const Xspi_Ip_SfdpTablesContainer *sfdpTables,
                                                 Xspi_Ip_MemoryConfigType *pConfig,
                                                 const Xspi_Ip_MemoryConnectionType * pConnect,
                                                 uint32 baseAddress
                                                )
{
    uint32 Idx = 0U;
    uint8 supported = 0U;
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;

    for(Idx = 0; Idx < pConnect->sfdpReadModeCount; Idx++)
    {
        modeIndex = (uint8)pConnect->pSfdpReadModeList[Idx];
        if ((uint8)XSPI_IP_SFDP_READ_MODE_8D_8D_8D == modeIndex)
        {
            if (sfdpTables->paramTableLength_xspi1 > 0U)
            {
                status = Xspi_Ip_ConfigureXspi1(sfdpTables, pConfig, pConnect->xspiInstance, baseAddress);
            }
        }
        else if ((uint8)XSPI_IP_SFDP_READ_MODE_1S_1S_1S == modeIndex)
        {
            status = Xspi_Ip_ConfigureBasic(sfdpTables, pConfig);
        }
        else
        {
            supported = (uint8)(Xspi_Ip_SfdpGetBasicParam(sfdpTables, readSupDword[modeIndex],
                                                          readSupShift[modeIndex], readSupWitdh[modeIndex], 0x0U) & 0xFFU);
            if (supported != 0U)
            {
                status = Xspi_Ip_ConfigureBasic(sfdpTables, pConfig);
            }
        }
        if (STATUS_XSPI_IP_SUCCESS == status)
        {
            /*Found the mode, configured success, break */
            break;
        }
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ReadSfdp
 * Description   : Auto-fills configuration from SFDP information
 *                 Xspi_Ip_ReadSfdp_Activity */
Xspi_Ip_StatusType Xspi_Ip_ReadSfdp(Xspi_Ip_MemoryConfigType * pConfig,
                                    const Xspi_Ip_MemoryConnectionType * pConnect
                                   )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    uint32 baseAddress;
    /* SFDP Tables */
    Xspi_Ip_SfdpTablesContainer sfdpTables;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check for valid parameters */
    DEV_ASSERT_XSPI(pConnect != NULL_PTR);
    DEV_ASSERT_XSPI(pConfig != NULL_PTR);
    DEV_ASSERT_XSPI((pConfig->lutSequences.lutOps != NULL_PTR) && (pConfig->lutSequences.opCount > 0U));
#endif
    /* Get device base address */
    baseAddress = Xspi_Ip_ControllerGetBaseAdress(pConnect->xspiInstance, pConnect->connectionType);
    /* Get Hif base address */
    HifBaseAddr = Xspi_Ip_ControllerGetHifAdress(pConnect->xspiInstance, pConnect->hifInstance);
    /* Initiate communication with flash, check SFDP support */
    status = Xspi_Ip_SfdpCheck(pConnect->xspiInstance, baseAddress);
    if (status != STATUS_XSPI_IP_SUCCESS)
    {
        /* direct command - nothing to do */
    }
    else
    {
        /* Read SFDP tables of interest */
        status = Xspi_Ip_SfdpReadTables(baseAddress, &sfdpTables);
        if (status != STATUS_XSPI_IP_SUCCESS)
        {
            /* direct command - nothing to do */
        }
        else
        {
            /* Initialize LUT and init operations count */
            Xspi_Ip_SfdpLutInit();
            /* Build the enter legacy XPI protocol initial operation */
            Xspi_Ip_SfdpLutInitEnterLegacySPI(pConfig);
            /* Check xSPI 1.0 support */
            status = Xspi_Ip_SfdpConfigure(&sfdpTables, pConfig, pConnect, baseAddress);
        }
    }
    return status;
}



#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

#endif /* (XSPI_IP_MEM_INSTANCE_COUNT > 0) */
#endif /* (XSPI_IP_USE_SFDP_CFG == STD_ON) */


#ifdef __cplusplus
}
#endif

/** @} */
