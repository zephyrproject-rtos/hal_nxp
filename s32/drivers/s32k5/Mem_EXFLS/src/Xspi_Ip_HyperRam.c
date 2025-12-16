/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file Xspi_Ip_HyperRam.c
*
*   @addtogroup IPV_XSPI
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "OsIf.h"
#include "Xspi_Ip.h"
#include "Xspi_Ip_Common.h"
#include "Xspi_Ip_Controller.h"
#include "Xspi_Ip_HyperRam.h"
#include "Xspi_Ip_HyperRamRegs.h"


/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define XSPI_IP_HYPERRAM_VENDOR_ID_C                    43
#define XSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_C     4
#define XSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_C     9
#define XSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_C  0
#define XSPI_IP_HYPERRAM_SW_MAJOR_VERSION_C             0
#define XSPI_IP_HYPERRAM_SW_MINOR_VERSION_C             8
#define XSPI_IP_HYPERRAM_SW_PATCH_VERSION_C             0

#if (XSPI_IP_MEM_INSTANCE_COUNT > 0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((XSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (XSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Xspi_Ip_HyperRam.c and OsIf.h are different"
    #endif
#endif

/* Check if current file and Xspi_Ip header file are of the same vendor */
#if (XSPI_IP_HYPERRAM_VENDOR_ID_C != XSPI_IP_VENDOR_ID_H)
    #error "Xspi_Ip_HyperRam.c and Xspi_Ip.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip header file are of the same Autosar version */
#if ((XSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_C    != XSPI_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_C    != XSPI_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_C != XSPI_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_HyperRam.c and Xspi_Ip.h are different"
#endif
/* Check if current file and Xspi_Ip header file are of the same Software version */
#if ((XSPI_IP_HYPERRAM_SW_MAJOR_VERSION_C != XSPI_IP_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_SW_MINOR_VERSION_C != XSPI_IP_SW_MINOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_SW_PATCH_VERSION_C != XSPI_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip_HyperRam.c and Xspi_Ip.h are different"
#endif

/* Check if current file and Xspi_Ip_Common header file are of the same vendor */
#if (XSPI_IP_HYPERRAM_VENDOR_ID_C != XSPI_IP_COMMON_VENDOR_ID_H)
    #error "Xspi_Ip_HyperRam.c and Xspi_Ip_Common.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Common header file are of the same Autosar version */
#if ((XSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_C    != XSPI_IP_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_C    != XSPI_IP_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_C != XSPI_IP_COMMON_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_HyperRam.c and Xspi_Ip_Common.h are different"
#endif
/* Check if current file and Xspi_Ip_Common header file are of the same Software version */
#if ((XSPI_IP_HYPERRAM_SW_MAJOR_VERSION_C != XSPI_IP_COMMON_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_SW_MINOR_VERSION_C != XSPI_IP_COMMON_SW_MINOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_SW_PATCH_VERSION_C != XSPI_IP_COMMON_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip_HyperRam.c and Xspi_Ip_Common.h are different"
#endif

/* Check if current file and Xspi_Ip_Controller header file are of the same vendor */
#if (XSPI_IP_HYPERRAM_VENDOR_ID_C != XSPI_IP_CONTROLLER_VENDOR_ID_H)
    #error "Xspi_Ip_HyperRam.c and Xspi_Ip_Controller.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Controller header file are of the same Autosar version */
#if ((XSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_C    != XSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_C    != XSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_C != XSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_HyperRam.c and Xspi_Ip_Controller.h are different"
#endif
/* Check if current file and Xspi_Ip_Controller header file are of the same Software version */
#if ((XSPI_IP_HYPERRAM_SW_MAJOR_VERSION_C != XSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_SW_MINOR_VERSION_C != XSPI_IP_CONTROLLER_SW_MINOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_SW_PATCH_VERSION_C != XSPI_IP_CONTROLLER_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip_HyperRam.c and Xspi_Ip_Controller.h are different"
#endif

/* Check if current file and Xspi_Ip_HyperRam header file are of the same vendor */
#if (XSPI_IP_HYPERRAM_VENDOR_ID_C != XSPI_IP_HYPERRAM_VENDOR_ID_H)
    #error "Xspi_Ip_HyperRam.c and Xspi_Ip_HyperRam.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_HyperRam header file are of the same Autosar version */
#if ((XSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_C    != XSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_C    != XSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_C != XSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_HyperRam.c and Xspi_Ip_HyperRam.h are different"
#endif
/* Check if current file and Xspi_Ip_HyperRam header file are of the same Software version */
#if ((XSPI_IP_HYPERRAM_SW_MAJOR_VERSION_C != XSPI_IP_HYPERRAM_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_SW_MINOR_VERSION_C != XSPI_IP_HYPERRAM_SW_MINOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_SW_PATCH_VERSION_C != XSPI_IP_HYPERRAM_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip_HyperRam.c and Xspi_Ip_HyperRam.h are different"
#endif

/* Check if current file and Xspi_Ip_HyperRam header file are of the same vendor */
#if (XSPI_IP_HYPERRAM_VENDOR_ID_C != XSPI_IP_HYPERRAMREGS_VENDOR_ID_H)
    #error "Xspi_Ip_HyperRam.c and Xspi_Ip_HyperRamRegs.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_HyperRamRegs header file are of the same Autosar version */
#if ((XSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_C    != XSPI_IP_HYPERRAMREGS_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_C    != XSPI_IP_HYPERRAMREGS_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_C != XSPI_IP_HYPERRAMREGS_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_HyperRam.c and Xspi_Ip_HyperRamRegs.h are different"
#endif
/* Check if current file and Xspi_Ip_HyperRamRegs header file are of the same Software version */
#if ((XSPI_IP_HYPERRAM_SW_MAJOR_VERSION_C != XSPI_IP_HYPERRAMREGS_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_SW_MINOR_VERSION_C != XSPI_IP_HYPERRAMREGS_SW_MINOR_VERSION_H) || \
     (XSPI_IP_HYPERRAM_SW_PATCH_VERSION_C != XSPI_IP_HYPERRAMREGS_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip_HyperRam.c and Xspi_Ip_HyperRamRegs.h are different"
#endif

 /*******************************************************************************
 * Variables
 ******************************************************************************/

#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)

/* HyperFlash commands */
/* Read command with continuous burst type */
#define XSPI_IP_HR_READ           0xA0
/* Write command with continuous burst type */
#define XSPI_IP_HR_WRITE          0x20
/* READ reg command with continuous burst type */
#define XSPI_IP_HR_READ_REG       0xE0
/* Write reg command with continuous burst type */
#define XSPI_IP_HR_WRITE_REG      0x60

#define MEM_43_EXFLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"


/* Hyperflash virtual LUT */
Xspi_Ip_InstrOpType Xspi_Ip_HyperRamLutTable[XSPI_IP_HR_LUT_SIZE] =
{
    /* 0: XSPI_IP_HR_LUT_READ: Read command */
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_CMD_DDR   | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)XSPI_IP_HR_READ),
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_ADDR_DDR  | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)24U),
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_CADDR_DDR | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)16U),
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_DUMMY     | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)0x00),  /* dummy cycles to be patched in before use*/
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_READ_DDR  | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)0x20),
    (Xspi_Ip_InstrOpType)(XSPI_IP_LUT_INSTR_STOP),
    /* 6: XSPI_IP_HR_LUT_WRITE: write command */
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_CMD_DDR   | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)XSPI_IP_HR_WRITE),
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_ADDR_DDR  | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)24U),
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_CADDR_DDR | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)16U),
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_DUMMY     | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)0x00),  /* dummy cycles to be patched in before use*/
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_WRITE_DDR | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)0x20),
    (Xspi_Ip_InstrOpType)(XSPI_IP_LUT_INSTR_STOP),
    /* 12: XSPI_IP_HR_LUT_READ_REG: Read register */
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_CMD_DDR   | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)XSPI_IP_HR_READ_REG),
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_ADDR_DDR  | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)24U),
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_CADDR_DDR | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)16U),
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_DUMMY     | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)0x4),  /* dummy cycles to be patched in before use*/
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_READ_DDR  | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)0x2),
    (Xspi_Ip_InstrOpType)(XSPI_IP_LUT_INSTR_STOP),
    /* 18: XSPI_IP_HR_LUT_WRITE_REG: Write to register  */
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_CMD_DDR   | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)XSPI_IP_HR_WRITE_REG),
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_ADDR_DDR  | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)24U),
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_CADDR_DDR | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)16U),
    (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_WRITE_DDR | (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 | (Xspi_Ip_InstrOpType)0x2),
    (Xspi_Ip_InstrOpType)(XSPI_IP_LUT_INSTR_STOP)
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
 * Function Name : Xspi_Ip_HyperRamWriteConfigurationRegister
 * Description   : Write configuration registers
 *
 *END**************************************************************************/
static Xspi_Ip_StatusType Xspi_Ip_HyperRamWriteConfigurationRegister(uint32 instance, uint32 RegAddress, const uint16 *data )
{
    Xspi_Ip_StatusType status;
    XSPI_Type *baseAddr;
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);

    /* Copy sequence from virtual lut table in LUT registers */
    Xspi_Ip_SetLutSeq(instance, XSPI_IP_COMMAND_LUT, &(Xspi_Ip_HyperRamLutTable[XSPI_IP_HR_LUT_WRITE_REG]));

    baseAddr = Xspi_Ip_ControllerGetHifAdress(state->connection->xspiInstance, state->connection->hifInstance);

    /* Run XSPI command */
    status = Xspi_Ip_IpWrite(baseAddr, XSPI_IP_COMMAND_LUT, state->baseAddress + RegAddress, (const uint8 *)data, 2U);

    return status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_HyperRamReadConfigurationRegister
 * Description   : Read configuration registers
 *
 *END**************************************************************************/
static Xspi_Ip_StatusType Xspi_Ip_HyperRamReadConfigurationRegister(uint32 instance, uint32 RegAddress, uint16 *data )
{
    Xspi_Ip_StatusType status;
    XSPI_Type *baseAddr;
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);

    baseAddr = Xspi_Ip_ControllerGetHifAdress(state->connection->xspiInstance, state->connection->hifInstance);

    /* Copy sequence from virtual lut table in LUT registers */
    Xspi_Ip_SetLutSeq(state->connection->xspiInstance, XSPI_IP_COMMAND_LUT, &(Xspi_Ip_HyperRamLutTable[XSPI_IP_HR_LUT_READ_REG]));

    /* Run XSPI command */
    status = Xspi_Ip_IpRead(baseAddr, XSPI_IP_COMMAND_LUT, state->baseAddress + RegAddress, (uint8 *)data, NULL_PTR, 2U);

    return status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_HyperRamInitConfigurationRegister
 * Description   : Sets up configuration registers
 *
 *END**************************************************************************/
static Xspi_Ip_StatusType Xspi_Ip_HyperRamInitConfigurationRegister(uint32 instance)
{
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    uint16 regWriteValue = 0U;
    uint16 regReadValue = 0U;

    const Xspi_Ip_HyperRamConfigType *hrConfig = state->configuration->hrConfig;

    /*Calculate the value to write to register configuartion 0*/
    regWriteValue = (XSPI_IP_HR_CR0_DEFAULT_VALUE) | XSPI_IP_HR_CR0_DRIVE_STRENGTH(hrConfig->driveStrength) | XSPI_IP_HR_CR0_INITIAL_LATENCY(hrConfig->initialLatency);

    /*Write to register configuartion 0*/
    status = Xspi_Ip_HyperRamWriteConfigurationRegister(instance, XSPI_IP_HR_REGCFG0_ADDR, &regWriteValue);

    if(STATUS_XSPI_IP_SUCCESS == status)
    {
        status = Xspi_Ip_HyperRamReadConfigurationRegister(instance, XSPI_IP_HR_REGCFG0_ADDR, &regReadValue);
        if ( (status == STATUS_XSPI_IP_SUCCESS) && (regReadValue != regWriteValue) )
        {
            status = STATUS_XSPI_IP_ERROR;
        }
    }

    if(STATUS_XSPI_IP_SUCCESS == status)
    {
        /*Calculate the value to write to register configuartion 1*/
        regWriteValue = (XSPI_IP_HR_CR1_DEFAULT_VALUE) | XSPI_IP_HR_CR1_MASTER_CLOCK_TYPE(hrConfig->masterClockType) | XSPI_IP_HR_CR1_PARTIAL_REFRESH(hrConfig->arrayRefresh);

        /*Write to register configuartion 1*/
        status = Xspi_Ip_HyperRamWriteConfigurationRegister(instance, XSPI_IP_HR_REGCFG1_ADDR, &regWriteValue);
        if(STATUS_XSPI_IP_SUCCESS == status)
        {
            status = Xspi_Ip_HyperRamReadConfigurationRegister(instance, XSPI_IP_HR_REGCFG1_ADDR, &regReadValue);
            if ( (status == STATUS_XSPI_IP_SUCCESS) && (regReadValue != regWriteValue) )
            {
                status = STATUS_XSPI_IP_ERROR;
            }
        }
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_HyperRamInit
 * Description   : Initializes the hyper ram memory
 *
 *END**************************************************************************/
Xspi_Ip_StatusType Xspi_Ip_HyperRamInit(uint32 instance)
{
    Xspi_Ip_StatusType status;
    const Xspi_Ip_StateType *state = &Xspi_Ip_MemoryStateStructure[instance];
    uint8 dummyCycles;

    /* Set up Volatile and Non-Volatile Configuration Registers */
    status = Xspi_Ip_HyperRamInitConfigurationRegister(instance);
    if(STATUS_XSPI_IP_SUCCESS == status)
    {
        /*dummyCycles = initialLatency*2 - 1*/
        switch (state->configuration->hrConfig->initialLatency)
        {
            case XSPI_IP_HR_INITIAL_LATENCY_3_CLOCKS:
                dummyCycles = 5U;
                break;
            case XSPI_IP_HR_INITIAL_LATENCY_4_CLOCKS:
                dummyCycles = 7U;
                break;
            case XSPI_IP_HR_INITIAL_LATENCY_5_CLOCKS:
                dummyCycles = 9U;
                break;
            case XSPI_IP_HR_INITIAL_LATENCY_6_CLOCKS:
                dummyCycles = 11U;
                break;
            case XSPI_IP_HR_INITIAL_LATENCY_7_CLOCKS:
                dummyCycles = 13U;
                break;
            default:
                dummyCycles = 13U;
                break;
        }
        /* Patch command - set dummy cycles */
        Xspi_Ip_HyperRamLutTable[XSPI_IP_HR_LUT_READ + 3U]  =   (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_DUMMY |
                                                                (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 |
                                                                (Xspi_Ip_InstrOpType)dummyCycles);
        /* Patch command - set dummy cycles */
        Xspi_Ip_HyperRamLutTable[XSPI_IP_HR_LUT_WRITE + 3U] =   (Xspi_Ip_InstrOpType)((Xspi_Ip_InstrOpType)XSPI_IP_LUT_INSTR_DUMMY |
                                                                (Xspi_Ip_InstrOpType)XSPI_IP_LUT_PADS_8 |
                                                                (Xspi_Ip_InstrOpType)dummyCycles);
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ArbUnlock
 * Description   : Unlocks XSPI arbitration
 *END**************************************************************************/
Xspi_Ip_StatusType Xspi_Ip_HyperRamArbUnlock(uint32 instance, uint32 address)
{
#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
#endif
    Xspi_Ip_StatusType status;
    Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    XSPI_Type *baseAddr;
    uint32 DummyData;

    baseAddr = Xspi_Ip_ControllerGetHifAdress(state->connection->xspiInstance, state->connection->hifInstance);

    status = Xspi_Ip_ControllerArbUnlock(baseAddr, (uint8)XSPI_IP_LUT_PHYS_SEQ_READ, address, (uint8 *)&(DummyData), 2U);


    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_HyperRamArbLock
 * Description   : Locks XSPI arbitration
 *END**************************************************************************/
Xspi_Ip_StatusType Xspi_Ip_HyperRamArbLock(uint32 instance, uint32 address)
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
#endif

    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    XSPI_Type *baseAddr;

    baseAddr = Xspi_Ip_ControllerGetHifAdress(state->connection->xspiInstance, state->connection->hifInstance);
    /* Request arbitration lock - dummy read command to also check ram availability */
    status = Xspi_Ip_ControllerArbLock(baseAddr, (uint8)XSPI_IP_LUT_PHYS_SEQ_READ, address,2U);

    return status;
}
#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

#endif /* XSPI_IP_HYPERRAM_ENABLED == STD_ON */
#endif /* XSPI_IP_MEM_INSTANCE_COUNT */

#ifdef __cplusplus
}
#endif

/** @} */

