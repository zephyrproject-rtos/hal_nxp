/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file Qspi_Ip_Hyperflash.c
*
*   @addtogroup IPV_QSPI
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Mcal.h"
#include "OsIf.h"
#include "Qspi_Ip.h"
#include "Qspi_Ip_Common.h"
#include "Qspi_Ip_Controller.h"
#include "Qspi_Ip_HyperflashRegs.h"
#include "Qspi_Ip_Hyperflash.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_HYPERFLASH_VENDOR_ID_C                    43
#define QSPI_IP_HYPERFLASH_AR_RELEASE_MAJOR_VERSION_C     4
#define QSPI_IP_HYPERFLASH_AR_RELEASE_MINOR_VERSION_C     7
#define QSPI_IP_HYPERFLASH_AR_RELEASE_REVISION_VERSION_C  0
#define QSPI_IP_HYPERFLASH_SW_MAJOR_VERSION_C             2
#define QSPI_IP_HYPERFLASH_SW_MINOR_VERSION_C             0
#define QSPI_IP_HYPERFLASH_SW_PATCH_VERSION_C             1

#if (QSPI_IP_MEM_INSTANCE_COUNT > 0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((QSPI_IP_HYPERFLASH_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (QSPI_IP_HYPERFLASH_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Qspi_Ip_Hyperflash.c and OsIf.h are different"
    #endif
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((QSPI_IP_HYPERFLASH_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (QSPI_IP_HYPERFLASH_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Qspi_Ip_Hyperflash.c and Mcal.h are different"
    #endif
#endif

/* Check if current file and Qspi_Ip header file are of the same vendor */
#if (QSPI_IP_HYPERFLASH_VENDOR_ID_C != QSPI_IP_VENDOR_ID_H)
    #error "Qspi_Ip_Hyperflash.c and Qspi_Ip.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip header file are of the same Autosar version */
#if ((QSPI_IP_HYPERFLASH_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Hyperflash.c and Qspi_Ip.h are different"
#endif
/* Check if current file and Qspi_Ip header file are of the same Software version */
#if ((QSPI_IP_HYPERFLASH_SW_MAJOR_VERSION_C != QSPI_IP_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_SW_MINOR_VERSION_C != QSPI_IP_SW_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_SW_PATCH_VERSION_C != QSPI_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Hyperflash.c and Qspi_Ip.h are different"
#endif

/* Check if current file and Qspi_Ip_Common header file are of the same vendor */
#if (QSPI_IP_HYPERFLASH_VENDOR_ID_C != QSPI_IP_COMMON_VENDOR_ID_H)
    #error "Qspi_Ip_Hyperflash.c and Qspi_Ip_Common.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Common header file are of the same Autosar version */
#if ((QSPI_IP_HYPERFLASH_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_COMMON_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Hyperflash.c and Qspi_Ip_Common.h are different"
#endif
/* Check if current file and Qspi_Ip_Common header file are of the same Software version */
#if ((QSPI_IP_HYPERFLASH_SW_MAJOR_VERSION_C != QSPI_IP_COMMON_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_SW_MINOR_VERSION_C != QSPI_IP_COMMON_SW_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_SW_PATCH_VERSION_C != QSPI_IP_COMMON_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Hyperflash.c and Qspi_Ip_Common.h are different"
#endif

/* Check if current file and Qspi_Ip_Controller header file are of the same vendor */
#if (QSPI_IP_HYPERFLASH_VENDOR_ID_C != QSPI_IP_CONTROLLER_VENDOR_ID_H)
    #error "Qspi_Ip_Hyperflash.c and Qspi_Ip_Controller.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Controller header file are of the same Autosar version */
#if ((QSPI_IP_HYPERFLASH_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Hyperflash.c and Qspi_Ip_Controller.h are different"
#endif
/* Check if current file and Qspi_Ip_Controller header file are of the same Software version */
#if ((QSPI_IP_HYPERFLASH_SW_MAJOR_VERSION_C != QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_SW_MINOR_VERSION_C != QSPI_IP_CONTROLLER_SW_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_SW_PATCH_VERSION_C != QSPI_IP_CONTROLLER_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Hyperflash.c and Qspi_Ip_Controller.h are different"
#endif

/* Check if current file and Qspi_Ip_HyperflashRegs header file are of the same vendor */
#if (QSPI_IP_HYPERFLASH_VENDOR_ID_C != QSPI_IP_HYPERFLASHREGS_VENDOR_ID_H)
    #error "Qspi_Ip_Hyperflash.c and Qspi_Ip_HyperflashRegs.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_HyperflashRegs header file are of the same Autosar version */
#if ((QSPI_IP_HYPERFLASH_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_HYPERFLASHREGS_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_HYPERFLASHREGS_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_HYPERFLASHREGS_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Hyperflash.c and Qspi_Ip_HyperflashRegs.h are different"
#endif
/* Check if current file and Qspi_Ip_HyperflashRegs header file are of the same Software version */
#if ((QSPI_IP_HYPERFLASH_SW_MAJOR_VERSION_C != QSPI_IP_HYPERFLASHREGS_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_SW_MINOR_VERSION_C != QSPI_IP_HYPERFLASHREGS_SW_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_SW_PATCH_VERSION_C != QSPI_IP_HYPERFLASHREGS_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Hyperflash.c and Qspi_Ip_HyperflashRegs.h are different"
#endif

/* Check if current file and Qspi_Ip_Hyperflash header file are of the same vendor */
#if (QSPI_IP_HYPERFLASH_VENDOR_ID_C != QSPI_IP_HYPERFLASH_VENDOR_ID_H)
    #error "Qspi_Ip_Hyperflash.c and Qspi_Ip_Hyperflash.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Hyperflash header file are of the same Autosar version */
#if ((QSPI_IP_HYPERFLASH_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_HYPERFLASH_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_HYPERFLASH_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_HYPERFLASH_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Hyperflash.c and Qspi_Ip_Hyperflash.h are different"
#endif
/* Check if current file and Qspi_Ip_Hyperflash header file are of the same Software version */
#if ((QSPI_IP_HYPERFLASH_SW_MAJOR_VERSION_C != QSPI_IP_HYPERFLASH_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_SW_MINOR_VERSION_C != QSPI_IP_HYPERFLASH_SW_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERFLASH_SW_PATCH_VERSION_C != QSPI_IP_HYPERFLASH_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Hyperflash.c and Qspi_Ip_Hyperflash.h are different"
#endif

 /*******************************************************************************
 * Variables
 ******************************************************************************/

/* HyperFlash commands */
typedef enum
{
    QSPI_IP_HF_READ      = 0xA0,   /* Read command with continuous burst type                   */
    QSPI_IP_HF_WRITE     = 0x00,   /* Write command with continuous burst type                  */
    QSPI_IP_HF_RDSR      = 0x70,   /* Status register read                                      */
    QSPI_IP_HF_SRC       = 0x71,   /* Status register clear                                     */
    QSPI_IP_HF_EDPD      = 0xB9,   /* Enter Deep Power-Down                                     */
    QSPI_IP_HF_PPORTR    = 0x34,   /* Program Power-On Reset Timer Register                     */
    QSPI_IP_HF_RPORTR    = 0x3C,   /* Read Power-On Reset Timer Register                        */
    QSPI_IP_HF_LDICR     = 0x36,   /* Load Interrupt Configuration Register                     */
    QSPI_IP_HF_RDICR     = 0xC4,   /* Read Interrupt Configuration Register                     */
    QSPI_IP_HF_LDISR     = 0x37,   /* Load Interrupt Status Register                            */
    QSPI_IP_HF_RDISR     = 0xC5,   /* Read Interrupt Status Register                            */
    QSPI_IP_HF_LDVCR     = 0x38,   /* Load Volatile Configuration Register                      */
    QSPI_IP_HF_RDVCR     = 0xC7,   /* Read Volatile Configuration Register                      */
    QSPI_IP_HF_PNVCR     = 0x39,   /* Program Non-Volatile Configuration Register               */
    QSPI_IP_HF_ENVCR     = 0xC8,   /* Erase Non-Volatile Configuration Register                 */
    QSPI_IP_HF_RDNVCR    = 0xC6,   /* Read Non-Volatile Configuration Register                  */
    QSPI_IP_HF_WP        = 0xA0,   /* Word Program                                              */
    QSPI_IP_HF_WB        = 0x25,   /* Write to Buffer                                           */
    QSPI_IP_HF_PBF       = 0x29,   /* Program Buffer to Flash                                   */
    QSPI_IP_HF_WBAR      = 0xF0,   /* Write to Buffer Abort Reset                               */
    QSPI_IP_HF_CE        = 0x10,   /* Chip erase                                                */
    QSPI_IP_HF_SE        = 0x30,   /* Sector Erase                                              */
    QSPI_IP_HF_BC        = 0x33,   /* Blank check                                               */
    QSPI_IP_HF_EES       = 0xD0,   /* Evaluate Erase Status                                     */
    QSPI_IP_HF_ES        = 0xB0,   /* Erase Suspend                                             */
    QSPI_IP_HF_ER        = 0x30,   /* Erase Resume                                              */
    QSPI_IP_HF_PS        = 0x51,   /* Program Suspend                                           */
    QSPI_IP_HF_PR        = 0x50,   /* Program Resume                                            */
    QSPI_IP_HF_RESET     = 0xF0,   /* Software reset                                            */
    QSPI_IP_HF_CFIE      = 0x98,   /* CIF enter                                                 */
} Qspi_Ip_HyperFlashCommandsType;


#define MEM_43_EXFLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"


/* Hyperflash virtual LUT */
Qspi_Ip_InstrOpType Qspi_Ip_HyperflashLutTable[QSPI_IP_HF_LUT_SIZE] =
{
    /* 0: QSPI_IP_HF_LUT_COMMON_555_AA: pre-read with operand AA */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0xAA),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 6: QSPI_IP_HF_LUT_COMMON_2AA_55: pre-read with operand 55 */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x55),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 12: QSPI_IP_HF_LUT_READ: Read command */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_READ),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)16U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_DUMMY     | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x4),  /* dummy cycles to be patched in before use*/
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_READ_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x4),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 18: QSPI_IP_HF_LUT_WRITE: write command */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)16U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_WRITE_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x2),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 23: QSPI_IP_HF_LUT_RDSR: Read status register */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_RDSR),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 29: QSPI_IP_HF_LUT_RDSR_SEQ2 */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_READ),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)16U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_DUMMY     | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x4),  /* dummy cycles to be patched in before use*/
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_READ_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x4),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 35: QSPI_IP_HF_LUT_WP: Word Program */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_WP),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 41: QSPI_IP_HF_LUT_WP_SEQ1: Last sequence word program */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x18),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_WRITE_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x2),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 46: QSPI_IP_HF_LUT_CMD_80: pre-read with operand 0x80 */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x80),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 52: QSPI_IP_HF_LUT_CMD_AA: pre-command with operand 0xAA */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0xAA),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 58: QSPI_IP_HF_LUT_CMD_55: pre-command with operand 0x55 */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x55),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 64: QSPI_IP_HF_LUT_SE: sector erase */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_SE),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 70: QSPI_IP_HF_LUT_CE: chip erase */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_CE),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 76: QSPI_IP_HF_LUT_RST: reset */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_RESET),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 82: QSPI_IP_HF_LUT_SRC: Clear Status Register Command */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_SRC),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 88: QSPI_IP_HF_LUT_BC: blank check command  */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_BC),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 94: QSPI_IP_HF_LUT_CMD_25: pre-read with operand 0x25 */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8) QSPI_IP_HF_WB),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 100: QSPI_IP_HF_LUT_WC: sector address and word count */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)(1U - 1U)),  /* wordCount to be patched in before use */
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 106: QSPI_IP_HF_LUT_WB: Write to buffer  */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x18),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_WRITE_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x2),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 111: QSPI_IP_HF_LUT_PBF: Write to buffer  */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_PBF),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 117: QSPI_IP_HF_LUT_PS: Program suspend  */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_PS),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 123: QSPI_IP_HF_LUT_PR: Program resume  */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_PR),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 129: QSPI_IP_HF_LUT_ES: Erase suspend  */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_ES),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 135: QSPI_IP_HF_LUT_ER: Erase resume  */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_ER),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 141:QSPI_IP_HF_LUT_RDNVCR: Read Non-Volatile Configuration Register */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8) QSPI_IP_HF_RDNVCR),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 147: QSPI_IP_HF_LUT_ENVCR: Erase Non-Volatile Configuration Register LUT */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_ENVCR),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 153: QSPI_IP_HF_LUT_PNVCR: Program Non-Volatile Configuration Register LUT */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_PNVCR),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 159: QSPI_IP_HF_LUT_LDVCR: Load Volatile Configuration Register LUT */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)(uint8)QSPI_IP_HF_LDVCR),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 165: QSPI_IP_HF_LUT_CMD_98: pre-command with operand 0x98 (Enter CFI) */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x10),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x00),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HF_CFIE),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP)
    /* Total LUT size: 171 */
};

#define MEM_43_EXFLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"


/*******************************************************************************
 * Functions
 ******************************************************************************/

#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashUnlockCycles12
 * Description   : Sends the unlock cycles 1 and 2 before erase and write commands
 *
 *END**************************************************************************/
static Qspi_Ip_StatusType Qspi_Ip_HyperflashSendUnlockCycles12(uint32 instance)
{
    Qspi_Ip_StatusType status;

    /* Send unlock cycle 1 */
    status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_COMMON_555_AA, 0xAAA);
    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Send unlock cycle 2 */
        status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_COMMON_2AA_55, 0x554);
    }
    MCAL_FAULT_INJECTION_POINT(QSPI_IP_UNLOCK_CYCLE12_SENT_COMPLETE);

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashPatchReadCommand
 * Description   : Patch a read command with the configured dummy cycles count
 *
 *END**************************************************************************/
void Qspi_Ip_HyperflashPatchReadCommand(uint32 instance,
                                        uint16 lut
                                       )
{
    const Qspi_Ip_StateType *state = &Qspi_Ip_MemoryStateStructure[instance];
    uint8 dummyCycles;

    /* Get dummy cycles */
    dummyCycles = (uint8)state->configuration->hfConfig->readLatency + 4U;
    /* Patch command - set dummy cycles */
    Qspi_Ip_HyperflashLutTable[lut + 3U] = (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_DUMMY |
                                                                 (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 |
                                                                 (Qspi_Ip_InstrOpType)dummyCycles);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashPatchRunReadCommand
 * Description   : Runs a read command after fixing the dummy cycles count
 *
 *END**************************************************************************/
static Qspi_Ip_StatusType Qspi_Ip_HyperflashPatchRunReadCommand(uint32 instance,
                                                                uint16 lut,
                                                                uint32 addr,
                                                                uint8 * data,
                                                                uint32 size
                                                               )
{
    /* Patch command - set dummy cycles */
    Qspi_Ip_HyperflashPatchReadCommand(instance, lut);

    /* Launch read command */
    return Qspi_Ip_RunReadCommand(instance, lut, addr, data, NULL_PTR, size);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashInitConfigRegister
 * Description   : Initializes configuration register
 *
 *END**************************************************************************/
static uint16 Qspi_Ip_HyperflashGetConfigurationValue(const Qspi_Ip_HyperFlashConfigType *config)
{
    uint16 regVal;

    const uint8 RWDSLowOnDualError   = (config->RWDSLowOnDualError)  ? 1U : 0U;
    const uint8 secureRegionUnlocked = (config->secureRegionUnlocked)? 1U : 0U;

    regVal = (uint16)((uint16)QSPI_IP_HF_xVCR_BL((uint8)0x3U) |
                      (uint16)QSPI_IP_HF_xVCR_RWDS(RWDSLowOnDualError) |
                      (uint16)QSPI_IP_HF_xVCR_RL((uint8)config->readLatency) |
                      (uint16)QSPI_IP_HF_xVCR_PSM((uint8)config->paramSectorMap) |
                      (uint16)QSPI_IP_HF_xVCR_SSR(secureRegionUnlocked) |
                      (uint16)QSPI_IP_HF_xVCR_FRZ(1U) |
                      (uint16)QSPI_IP_HF_xVCR_DS((uint8)config->outputDriverStrength) |
                      ((uint16)QSPI_IP_HF_xVCR_RESERVED_BIT_3) |
                      ((uint16)QSPI_IP_HF_xVCR_RESERVED_BIT_16));

    return regVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashGetStatusRegister
 * Description   : Reads status register of the flash device.
 *
 *END**************************************************************************/
static Qspi_Ip_StatusType Qspi_Ip_HyperflashGetStatusRegister(uint32 instance,
                                                              uint16 * readValue
                                                             )
{
    Qspi_Ip_StatusType status;

    /* Trigger pre-read command */
    status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_RDSR, 0xAAA);
    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        status = Qspi_Ip_HyperflashPatchRunReadCommand(instance, QSPI_IP_HF_LUT_RDSR_SEQ2, 0U, (uint8 *)readValue, 2U);
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashWaitDeviceReady
 * Description   : Waits device to be ready
 *
 *END**************************************************************************/
static Qspi_Ip_StatusType Qspi_Ip_HyperflashWaitDeviceReady(uint32 instance)
{
    uint16 readValue = 0U;  /* Initilize with busy state */
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint32 u32ElapsedTicks = 0U;
    uint32 u32TimeoutTicks;
    uint32 u32CurrentTicks;

    /* Prepare timeout counter */
    u32TimeoutTicks = OsIf_MicrosToTicks(QSPI_IP_FLS_INIT_TIMEOUT, (OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
    u32CurrentTicks = OsIf_GetCounter((OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);

    do
    {
        status = Qspi_Ip_HyperflashGetStatusRegister(instance, &readValue);
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, (OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);

        if ((status == STATUS_QSPI_IP_ERROR) || ((readValue & QSPI_IP_HF_SR_DRB_MASK) != 0U))
        {
            /* status == STATUS_QSPI_IP_ERROR or hardware is ready */
            break;
        }
    }
    while (u32ElapsedTicks < u32TimeoutTicks);

    if (((readValue & QSPI_IP_HF_SR_DRB_MASK) == 0U) && (STATUS_QSPI_IP_SUCCESS == status))
    {
        status = STATUS_QSPI_IP_BUSY;
    }

   return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashStatusRegisterClear
 * Description   : Clears the Status Register. This function clears the error status of an
 *                 embedded operation. It is necessary to clear the error status in order to
 *                 return to normal operation, ready for a new read or command write.
 *
 *END**************************************************************************/
static Qspi_Ip_StatusType Qspi_Ip_HyperflashStatusRegisterClear(uint32 instance)
{
    Qspi_Ip_StatusType status;

    /* Send Clear Status Register command */
    status =  Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_SRC, 0xAAA);

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashStatusRegisterDecode
 * Description   : Decodes the device status according to the last command executed
 *
 *END**************************************************************************/
static Qspi_Ip_StatusType Qspi_Ip_HyperflashStatusRegisterDecode(uint16 SRValue,
                                                                 Qspi_Ip_LastCommandType lastCommand
                                                                )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint16 checkValue = 0U;

    switch (lastCommand)
    {
        case QSPI_IP_LAST_COMMAND_ERASE:
            /* If ESB is set, last erase operation failed. Used also for blank check command */
            checkValue = SRValue & QSPI_IP_HF_SR_ESB_MASK;
            break;

        case QSPI_IP_LAST_COMMAND_WRITE:
            /* If PSB is set, last programming operation failed */
            checkValue = SRValue & QSPI_IP_HF_SR_PSB_MASK;
            break;

        case QSPI_IP_LAST_COMMAND_WRITE_BUFFER_ABORT:
            /* If WBASB 0, programming operation was not aborted */
            checkValue = (~SRValue) & QSPI_IP_HF_SR_WBASB_MASK;
            break;

        case QSPI_IP_LAST_COMMAND_WRITE_SUSPEND:
            /* If PSSB 0, no programming operation is suspended */
            checkValue = (~SRValue) & QSPI_IP_HF_SR_PSSB_MASK;
            break;

        case QSPI_IP_LAST_COMMAND_ERASE_SUSPEND:
            /* If ESSB 0, no erase operation is suspended */
            checkValue = (~SRValue) & QSPI_IP_HF_SR_ESSB_MASK;
            break;

        case QSPI_IP_LAST_COMMAND_CRC_SUSPEND:
            /* If CRCSSB 0, CRC operation is not suspended */
            checkValue = (~SRValue) & QSPI_IP_HF_SR_CRCSSB_MASK;
            break;

        case QSPI_IP_LAST_COMMAND_SECTOR_ERASE_STATUS:
            /* If ESTAT 0, previous erase did not complete successfully */
            checkValue = (~SRValue) & QSPI_IP_HF_SR_ESTAT_MASK;
            break;

        default:  /* QSPI_IP_LAST_COMMAND_NONE */
            /* Do nothing */
            break;
    }

    /* If the check different than zero, there is an error */
    if (checkValue != 0U)
    {
        status = STATUS_QSPI_IP_ERROR;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashGetMemoryStatus
 * Description   : Get the flash device status according to the last command executed
 *
 *END**************************************************************************/
Qspi_Ip_StatusType Qspi_Ip_HyperflashGetMemoryStatus(uint32 instance)
{
    const Qspi_Ip_StateType *state = &Qspi_Ip_MemoryStateStructure[instance];
    Qspi_Ip_StatusType status;
    uint16 SRValue = 0U;

    /* Read status register */
    status = Qspi_Ip_HyperflashGetStatusRegister(instance, &SRValue);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Check if device is busy */
        if ((SRValue & QSPI_IP_HF_SR_DRB_MASK) == 0U)
        {
            status = STATUS_QSPI_IP_BUSY;
        }
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Clear Status Register */
        status = Qspi_Ip_HyperflashStatusRegisterClear(instance);
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Decode Status Register */
        status = Qspi_Ip_HyperflashStatusRegisterDecode(SRValue, state->lastCommand);
    }

    return status;
}

/*FUNCTION******************************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashEraseNonVolatileConfigurationRegister
 * Description   : Erases the non-volatile configuration register.
 *
 *END***********************************************************************************/
 static Qspi_Ip_StatusType Qspi_Ip_HyperflashEraseNonVolatileConfigurationRegister(uint32 instance)
{
    Qspi_Ip_StateType *state = &Qspi_Ip_MemoryStateStructure[instance];
    Qspi_Ip_StatusType status;

    /* Send unclock cycles 1 & 2 */
    status = Qspi_Ip_HyperflashSendUnlockCycles12(instance);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Erase Nonvolatile Configuration Registers */
        status =  Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_ENVCR, 0xAAA);
        state->lastCommand = QSPI_IP_LAST_COMMAND_ERASE;
    }

    return status;
}


/*FUNCTION******************************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashProgramNonVolatileConfigurationRegister
 * Description   : Programs the Non-volatile configuration register of the flash device.
 *
 *END***********************************************************************************/
static Qspi_Ip_StatusType Qspi_Ip_HyperflashProgramNonVolatileConfigurationRegister(uint32 instance,
                                                                                    const uint16 *data
                                                                                   )
{
    Qspi_Ip_StateType *state = &Qspi_Ip_MemoryStateStructure[instance];
    Qspi_Ip_StatusType status;

    /* Send unclock cycles 1 & 2 */
    status = Qspi_Ip_HyperflashSendUnlockCycles12(instance);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Third cycle */
        status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_PNVCR, 0xAAA);
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Fourth cycle */
        status = Qspi_Ip_RunWriteCommand(instance, QSPI_IP_HF_LUT_WRITE, 0U, (const uint8 *)data, 2U);
        state->lastCommand = QSPI_IP_LAST_COMMAND_WRITE;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashGetNonVolatileConfigurationRegister
 * Description   : Reads the non-volatile configuration register
 *
 *END**************************************************************************/
static Qspi_Ip_StatusType Qspi_Ip_HyperflashGetNonVolatileConfigurationRegister(uint32 instance,
                                                                                uint16 * dataRead
                                                                               )
{
    Qspi_Ip_StateType *state = &Qspi_Ip_MemoryStateStructure[instance];
    Qspi_Ip_StatusType status;

    /* Send unclock cycles 1 & 2 */
    status = Qspi_Ip_HyperflashSendUnlockCycles12(instance);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_RDNVCR, 0xAAA);
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        status = Qspi_Ip_HyperflashPatchRunReadCommand(instance, QSPI_IP_HF_LUT_READ, 0U, (uint8 *)dataRead, 2U);
        state->lastCommand = QSPI_IP_LAST_COMMAND_NONE;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashLoadVolatileConfigurationRegister
 * Description   : Loads volatile configuration register with the data provided
 *
 *END**************************************************************************/
static Qspi_Ip_StatusType Qspi_Ip_HyperflashLoadVolatileConfigurationRegister(uint32 instance,
                                                                              const uint16 * data
                                                                             )
{
    Qspi_Ip_StateType *state = &Qspi_Ip_MemoryStateStructure[instance];
    Qspi_Ip_StatusType status;

    /* Send unclock cycles 1 & 2 */
    status = Qspi_Ip_HyperflashSendUnlockCycles12(instance);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Third cycle */
        status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_LDVCR, 0xAAA);
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Fourth cycle */
        status = Qspi_Ip_RunWriteCommand(instance, QSPI_IP_HF_LUT_WRITE, 0U, (const uint8 *)data, 2U);
        state->lastCommand = QSPI_IP_LAST_COMMAND_WRITE;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashSectorBlankCheck
 * Description   : Checks if a specified sector is erased
 *
 *END**************************************************************************/
Qspi_Ip_StatusType Qspi_Ip_HyperflashSectorBlankCheck(uint32 instance,
                                                      uint32 sectorAddress
                                                     )
{
    Qspi_Ip_StateType *state = &Qspi_Ip_MemoryStateStructure[instance];
    Qspi_Ip_StatusType status;
    uint32 startAddr;

    /* Calculate starting address of the address provided */
    startAddr = (uint32)(sectorAddress & ~(QSPI_IP_HYPERFLASH_SECTOR_SIZE - 1U));

    /* Write at address 0x555 of the sector specified */
    status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_BC, (startAddr + (uint32)0xAAA));
    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        state->lastCommand = QSPI_IP_LAST_COMMAND_ERASE;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashSectorErase
 * Description   : Erase a specified sector (4KB or 256KB) in hyperflash.
 *
 *END**************************************************************************/
Qspi_Ip_StatusType Qspi_Ip_HyperflashSectorErase(uint32 instance,
                                                 uint32 sectorAddress
                                                )
{
    Qspi_Ip_StatusType status;

    /* Send unclock cycles 1 & 2 */
    status = Qspi_Ip_HyperflashSendUnlockCycles12(instance);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Command Cycle 1 */
        status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_CMD_80, 0xAAA);
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Command Cycle 2 */
        status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_CMD_AA, 0xAAA);
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Command Cycle 3 */
        status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_CMD_55, 0x554);
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Specify the address for erasure */
        status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_SE, sectorAddress);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashProgramBufferToFlashConfirm
 * Description   : Program buffer to flash confirm command
 *END**************************************************************************/
static Qspi_Ip_StatusType Qspi_Ip_HyperflashProgramBufferToFlashConfirm(uint32 instance,
                                                                        uint32 sectorAddr
                                                                       )
{
    Qspi_Ip_StateType *state = &Qspi_Ip_MemoryStateStructure[instance];
    Qspi_Ip_StatusType status;

    status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_PBF, sectorAddr);
    state->lastCommand = QSPI_IP_LAST_COMMAND_NONE;

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashChipErase
 * Description   : Erases the entire chip
 *
 *END**************************************************************************/
Qspi_Ip_StatusType Qspi_Ip_HyperflashChipErase(uint32 instance)
{
    Qspi_Ip_StatusType status;

    /* Send unclock cycles 1 & 2 */
    status = Qspi_Ip_HyperflashSendUnlockCycles12(instance);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Send set-up command */
        status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_CMD_80, 0xAAA);
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Two additional unlock write cycles */
        status = Qspi_Ip_HyperflashSendUnlockCycles12(instance);
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Send Chip Erase command */
        status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_CE, 0xAAA);
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashProgram
 * Description   : Writes from 1 up to 512 bytes to write buffer.
 *                 The address provided should be in the same line buffer.
 *
 *END**************************************************************************/
Qspi_Ip_StatusType Qspi_Ip_HyperflashProgram(uint32 instance,
                                             uint32 address,
                                             const uint8 * data,
                                             uint32 size
                                            )
{
    Qspi_Ip_StatusType status;
    const uint32 sectorAddress = address & ~(QSPI_IP_HYPERFLASH_SECTOR_SIZE - 1U);
    uint32 selectAddress = address;
    const uint8 * dataPtr = data;

    /* Get the padding information */
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    const uint32 qspiInstance = state->connection->qspiInstance;
    const uint32 padding      = (uint32)Qspi_Ip_MemoryPadding[qspiInstance];
    const uint32 prePadding   = padding >> 4U;
    const uint32 postPadding  = padding & 0x0FU;
    Qspi_Ip_MemoryPadding[qspiInstance] = 0U;  /* Clear all padding*/

    /* Calculate the word count to program */
    uint32 byteCnt         = size;
    const uint32 byteTotal = byteCnt + prePadding + postPadding;
    const uint32 wordCnt   = (byteTotal >> 1U) - 1U;  /* minus 1 */

    /* Send unclock cycles 1 & 2 */
    status = Qspi_Ip_HyperflashSendUnlockCycles12(instance);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Send pre-read with operand 0x25, third cycle */
        status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_CMD_25, sectorAddress);
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Patch LUT sequence with number of words to program minus 1 */
        Qspi_Ip_HyperflashLutTable[QSPI_IP_HF_LUT_WC + 4U] =
            (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR |
                                  (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8        |
                                  (Qspi_Ip_InstrOpType)wordCnt);

        status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_WC, sectorAddress);
    }

    /* Load each Address/Data pair */
    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* The start address is unaligned */
        if (prePadding != 0U)
        {
            /* Set prePadding */
            Qspi_Ip_MemoryPadding[qspiInstance] = (uint8)(prePadding << 4UL);
            /* Load the first data byte */
            status = Qspi_Ip_RunWriteCommand(instance, QSPI_IP_HF_LUT_WB, selectAddress, dataPtr, 1U);
            /* Move to the next data */
            selectAddress += 2U;
            dataPtr        = &dataPtr[1U];
            byteCnt       -= 1U;
        }

        /* Loop for aligned cases */
        while ((byteCnt >= 2U) && (STATUS_QSPI_IP_SUCCESS == status))
        {
            /* Load each word */
            status = Qspi_Ip_RunWriteCommand(instance, QSPI_IP_HF_LUT_WB, selectAddress, dataPtr, 2U);
            /* Move to the next data */
            selectAddress += 2U;
            dataPtr        = &dataPtr[2U];
            byteCnt       -= 2U;
        }

        /* The end address is unaligned */
        if ((postPadding != 0U) && (STATUS_QSPI_IP_SUCCESS == status))
        {
            /* Set postPadding */
            Qspi_Ip_MemoryPadding[qspiInstance] = (uint8)postPadding;
            /* Load the last data byte */
            status = Qspi_Ip_RunWriteCommand(instance, QSPI_IP_HF_LUT_WB, selectAddress, dataPtr, 1U);
        }
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Write Program Buffer to Flash Confirm */
        status = Qspi_Ip_HyperflashProgramBufferToFlashConfirm(instance, sectorAddress);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashReadId
 * Description   : Read manufacturer ID from hyper flash.
 *
 *END**************************************************************************/
Qspi_Ip_StatusType Qspi_Ip_HyperflashReadId(uint32 instance,
                                            uint32 wordAddress,
                                            uint8 * data,
                                            uint32 size
                                           )
{
    Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    Qspi_Ip_StatusType status;

    /* CFI enter */
    status = Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_CMD_98, 0xAAA);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Read the ID at the designated word location (convert to byte address) */
        status = Qspi_Ip_HyperflashPatchRunReadCommand(instance,
                                                       QSPI_IP_HF_LUT_READ,
                                                       wordAddress << 1U,
                                                       data,
                                                       size);
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* ASO Exit: back to flash memory array */
        status =  Qspi_Ip_RunCommand(instance, QSPI_IP_HF_LUT_RST, 0U);
        state->lastCommand = QSPI_IP_LAST_COMMAND_NONE;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashInitConfigurationRegister
 * Description   : Sets up Volatile and Non-Volatile configuration registers
 *
 *END**************************************************************************/
static Qspi_Ip_StatusType Qspi_Ip_HyperflashInitConfigurationRegister(uint32 instance)
{
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    Qspi_Ip_StatusType status;
    uint16 readValue;
    uint16 writeVCR;

    /* Compute new configuration value */
    writeVCR = Qspi_Ip_HyperflashGetConfigurationValue(state->configuration->hfConfig);

    /* Read Non-Volatile Configuration Register */
    status = Qspi_Ip_HyperflashGetNonVolatileConfigurationRegister(instance, &readValue);

    if ((STATUS_QSPI_IP_SUCCESS == status) && (writeVCR != readValue))
    {
        /* Write the Non-Volatile register only if current configuration is different from the previous one */

        /* Erase the NVCR  */
        status = Qspi_Ip_HyperflashEraseNonVolatileConfigurationRegister(instance);
        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            /* Wait until Configuration register is erased */
            status = Qspi_Ip_HyperflashWaitDeviceReady(instance);
        }

        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            /* Loads value into non-volatile configuration register */
            status = Qspi_Ip_HyperflashProgramNonVolatileConfigurationRegister(instance, &writeVCR);
        }

        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            /* Wait until Configuration register is programmed */
            status = Qspi_Ip_HyperflashWaitDeviceReady(instance);
        }
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Load values into volatile configuration register */
        status = Qspi_Ip_HyperflashLoadVolatileConfigurationRegister(instance, &writeVCR);
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Wait until Configuration register is updated */
        status = Qspi_Ip_HyperflashWaitDeviceReady(instance);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperflashInit
 * Description   : Initializes the hyper flash memory
 *
 *END**************************************************************************/
Qspi_Ip_StatusType Qspi_Ip_HyperflashInit(uint32 instance)
{
    Qspi_Ip_StatusType status;
    uint16 readValue;

    /* Check status register */
    status = Qspi_Ip_HyperflashGetStatusRegister(instance, &readValue);
    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Check if device is ready */
        if ((readValue & QSPI_IP_HF_SR_DRB_MASK) == 0U)
        {
            status = STATUS_QSPI_IP_BUSY;
        }
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Set up Volatile and Non-Volatile Configuration Registers */
        status = Qspi_Ip_HyperflashInitConfigurationRegister(instance);
    }

    return status;
}


#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"


#endif /* QSPI_IP_MEM_INSTANCE_COUNT */

#ifdef __cplusplus
}
#endif

/** @} */


