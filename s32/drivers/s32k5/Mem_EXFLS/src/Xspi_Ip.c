/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file Xspi_Ip.c
*
*   @addtogroup IPV_XSPI XSPI IPV Driver
*   @{
*/

/* implements Xspi_Ip.c_Artifact */

#ifdef __cplusplus
extern "C"{
#endif

#include "OsIf.h"
#include "Xspi_Ip_Controller.h"
#include "Xspi_Ip_Common.h"
#include "Xspi_Ip.h"
#include "Xspi_Ip_HyperRam.h"

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
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((XSPI_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (XSPI_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Xspi_Ip.c and Mcal.h are different"
    #endif

    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((XSPI_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (XSPI_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Xspi_Ip.c and OsIf.h are different"
    #endif
#endif

/* Check if current file and Xspi_Ip_Controller header file are of the same vendor */
#if (XSPI_IP_VENDOR_ID_C != XSPI_IP_CONTROLLER_VENDOR_ID_H)
    #error "Xspi_Ip.c and Xspi_Ip_Controller.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Controller header file are of the same Autosar version */
#if ((XSPI_IP_AR_RELEASE_MAJOR_VERSION_C    != XSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_AR_RELEASE_MINOR_VERSION_C    != XSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_AR_RELEASE_REVISION_VERSION_C != XSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip.c and Xspi_Ip_Controller.h are different"
#endif
/* Check if current file and Xspi_Ip_Controller header file are of the same Software version */
#if ((XSPI_IP_SW_MAJOR_VERSION_C != XSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_SW_MINOR_VERSION_C != XSPI_IP_CONTROLLER_SW_MINOR_VERSION_H) || \
     (XSPI_IP_SW_PATCH_VERSION_C != XSPI_IP_CONTROLLER_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip.c and Xspi_Ip_Controller.h are different"
#endif

/* Check if current file and Xspi_Ip_Common header file are of the same vendor */
#if (XSPI_IP_VENDOR_ID_C != XSPI_IP_COMMON_VENDOR_ID_H)
    #error "Xspi_Ip.c and Xspi_Ip_Common.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Common header file are of the same Autosar version */
#if ((XSPI_IP_AR_RELEASE_MAJOR_VERSION_C    != XSPI_IP_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_AR_RELEASE_MINOR_VERSION_C    != XSPI_IP_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_AR_RELEASE_REVISION_VERSION_C != XSPI_IP_COMMON_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip.c and Xspi_Ip_Common.h are different"
#endif
/* Check if current file and Xspi_Ip_Common header file are of the same Software version */
#if ((XSPI_IP_SW_MAJOR_VERSION_C != XSPI_IP_COMMON_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_SW_MINOR_VERSION_C != XSPI_IP_COMMON_SW_MINOR_VERSION_H) || \
     (XSPI_IP_SW_PATCH_VERSION_C != XSPI_IP_COMMON_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip.c and Xspi_Ip_Common.h are different"
#endif

/* Check if current file and Xspi_Ip header file are of the same vendor */
#if (XSPI_IP_VENDOR_ID_C != XSPI_IP_VENDOR_ID_H)
    #error "Xspi_Ip.c and Xspi_Ip.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip header file are of the same Autosar version */
#if ((XSPI_IP_AR_RELEASE_MAJOR_VERSION_C    != XSPI_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_AR_RELEASE_MINOR_VERSION_C    != XSPI_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_AR_RELEASE_REVISION_VERSION_C != XSPI_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip.c and Xspi_Ip.h are different"
#endif
/* Check if current file and Xspi_Ip header file are of the same Software version */
#if ((XSPI_IP_SW_MAJOR_VERSION_C != XSPI_IP_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_SW_MINOR_VERSION_C != XSPI_IP_SW_MINOR_VERSION_H) || \
     (XSPI_IP_SW_PATCH_VERSION_C != XSPI_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip.c and Xspi_Ip.h are different"
#endif

/* Check if current file and Xspi_Ip header file are of the same vendor */
#if (XSPI_IP_VENDOR_ID_C != XSPI_IP_HYPERRAM_VENDOR_ID_H)
    #error "Xspi_Ip.c and Xspi_Ip_HyperRam.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip header file are of the same Autosar version */
#if ((XSPI_IP_AR_RELEASE_MAJOR_VERSION_C    != XSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_AR_RELEASE_MINOR_VERSION_C    != XSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_AR_RELEASE_REVISION_VERSION_C != XSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip.c and Xspi_Ip_HyperRam.h are different"
#endif
/* Check if current file and Xspi_Ip header file are of the same Software version */
#if ((XSPI_IP_SW_MAJOR_VERSION_C != XSPI_IP_HYPERRAM_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_SW_MINOR_VERSION_C != XSPI_IP_HYPERRAM_SW_MINOR_VERSION_H) || \
     (XSPI_IP_SW_PATCH_VERSION_C != XSPI_IP_HYPERRAM_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip.c and Xspi_Ip_HyperRam.h are different"
#endif


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#if (XSPI_IP_MEM_INSTANCE_COUNT > 0)

#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"

/* Pointer to runtime state structures */
Xspi_Ip_StateType Xspi_Ip_MemoryStateStructure[XSPI_IP_MEM_INSTANCE_COUNT];

#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

static Xspi_Ip_StatusType Xspi_Ip_WriteEnable(uint32 instance,
                                              uint32 address
                                             );

static Xspi_Ip_StatusType Xspi_Ip_InitReset(uint32 instance,
                                            uint16 resetCmdLut,
                                            uint8 resetCmdCount,
                                            const Xspi_Ip_StateType *state
                                           );

static Xspi_Ip_StatusType Xspi_Ip_InitWriteReg(uint32 instance,
                                               const Xspi_Ip_InitOperationType *operation
                                              );

static Xspi_Ip_StatusType Xspi_Ip_InitRMWReg(uint32 instance,
                                             const Xspi_Ip_InitOperationType *operation
                                            );

static Xspi_Ip_StatusType Xspi_Ip_InitReadReg(uint32 instance,
                                              const Xspi_Ip_InitOperationType *operation
                                             );

static Xspi_Ip_StatusType Xspi_Ip_InitOperation(uint32 instance,
                                                const Xspi_Ip_StateType *state,
                                                uint8 initOp
                                               );

static Xspi_Ip_StatusType Xspi_Ip_CheckMemStatus(uint32 instance,
                                                 uint32 address,
                                                 uint32 srValue
                                                );


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SetValue
 * Description   : Converts a long value in data to be sent to flash
 * Xspi_Ip_SetValue_Activity */
static inline void Xspi_Ip_SetValue(uint8 *data,
                                    uint8 size,
                                    uint32 value
                                   )
{
    uint8 cnt;
    uint32 temp = value;

    /* Put value in the data buffer */
    for (cnt = 0U; cnt < size; cnt++)
    {
        data[cnt] = (uint8)(temp & 0xFFU);
        temp >>= 8U;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SetBitfield
 * Description   : Sets a new value in a register bitfield
 * Xspi_Ip_SetBitfield_Activity */
static void Xspi_Ip_SetBitfield(uint8 *data,
                                uint8 size,
                                uint8 shift,
                                uint8 width,
                                uint32 value
                               )
{
    uint8 cnt;
    uint32 longData = 0UL;
    uint32 mask;

    /* Pack data in a long value (data[0] is LSB, data[size-1] is MSB) */
    for (cnt = 0U; cnt < size; cnt++)
    {
        longData = (longData << 8U) + data[size - 1U - cnt];
    }
    /* Apply change */
    mask = ((1UL << (uint32)width) - 1UL) << (uint32)shift;
    longData &= ~mask;
    longData |= (value << shift) & mask;
    /* Put data back in the data buffer (data[0] is LSB, data[size-1] is MSB) */
    for (cnt = 0U; cnt < size; cnt++)
    {
        data[cnt] = (uint8)(longData & 0xFFU);
        longData >>= 8U;
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_GetBitfield
 * Description   : Extracts the value of a register bitfield
 * Xspi_Ip_GetBitfield_Activity */
static uint32 Xspi_Ip_GetBitfield(const uint8 *data,
                                  uint8 size,
                                  uint8 shift,
                                  uint8 width
                                 )
{
    uint8 cnt;
    uint32 longData = 0U;
    uint32 mask;
    uint32 value;

    /* Pack data in a long value (data[0] is LSB, data[size-1] is MSB) */
    for (cnt = 0U; cnt < size; cnt++)
    {
        longData = (longData << 8U) + data[size - 1U - cnt];
    }
    /* Extract field */
    mask = (1UL << (uint32)width) - 1UL;
    value = (longData >> shift) & mask;
    return value;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_GetHifAddr
 * Description   : Returns the base pointer of the assigned XSPI host interface
 */
static inline XSPI_Type *Xspi_Ip_GetHifAddr(const Xspi_Ip_MemoryConnectionType *connection)
{
    return Xspi_Ip_ControllerGetHifAdress(connection->xspiInstance, connection->hifInstance);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : getNextVlut
 * Description   : Returns the start of the next sequence in virtual lut
 */
static inline uint16 getNextVlut(const Xspi_Ip_StateType *state, uint16 virtualLut)
{
    uint16 vLutIdx = virtualLut;
    const Xspi_Ip_InstrOpType *virtualLutTable = state->configuration->lutSequences.lutOps;

    do
    {
        vLutIdx++;
    }
    while (virtualLutTable[vLutIdx] != XSPI_IP_LUT_SEQ_END);
    /* Advance to start of next sequence */
    vLutIdx++;
    return vLutIdx;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_RunInitCommand
 * Description   : Launches a simple command for the serial flash.
 *                 Used only during initialization, because it uses virtual LUT.
 **/
static Xspi_Ip_StatusType Xspi_Ip_RunInitCommand(uint32 instance,
                                                 uint16 virtualLut,
                                                 uint32 addr
                                                )
{
    Xspi_Ip_StatusType status;
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    const Xspi_Ip_InstrOpType *virtualLutTable = state->configuration->lutSequences.lutOps;

    /* Copy sequence from virtual lut table in LUT registers */
    Xspi_Ip_SetLutSeq(state->connection->xspiInstance, XSPI_IP_COMMAND_LUT, &(virtualLutTable[virtualLut]));
    /* Run XSPI command */
    status = Xspi_Ip_IpCommand(Xspi_Ip_GetHifAddr(state->connection), XSPI_IP_COMMAND_LUT, state->baseAddress + addr);

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_RunInitReadCommand
 * Description   : Launches a read command for the serial flash
 *                 Used only during initialization, because it uses virtual LUT.
 **/
static Xspi_Ip_StatusType Xspi_Ip_RunInitReadCommand(uint32 instance,
                                                     const Xspi_Ip_InitOperationType *operation,
                                                     uint8 * dataRead,
                                                     const uint8 * dataCmp
                                                    )
{
    Xspi_Ip_StatusType status;
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    const Xspi_Ip_InstrOpType *virtualLutTable = state->configuration->lutSequences.lutOps;

    /* Copy sequence from virtual lut table in LUT registers */
    Xspi_Ip_SetLutSeq(state->connection->xspiInstance, XSPI_IP_COMMAND_LUT, &(virtualLutTable[operation->command1Lut]));
    /* Run XSPI command */
    status = Xspi_Ip_IpRead(Xspi_Ip_GetHifAddr(state->connection), XSPI_IP_COMMAND_LUT, state->baseAddress + operation->addr, dataRead, dataCmp, operation->size);

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_RunInitWriteCommand
 * Description   : Launches a write command for the serial flash
 *                 Used only during initialization, because it uses virtual LUT.
 **/
static Xspi_Ip_StatusType Xspi_Ip_RunInitWriteCommand(uint32 instance,
                                                      uint16 virtualLut,
                                                      uint32 addr,
                                                      const uint8 * data,
                                                      uint32 size
                                                     )
{
    Xspi_Ip_StatusType status;
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    const Xspi_Ip_InstrOpType *virtualLutTable = state->configuration->lutSequences.lutOps;

    /* Copy sequence from virtual lut table in LUT registers */
    Xspi_Ip_SetLutSeq(state->connection->xspiInstance, XSPI_IP_COMMAND_LUT, &(virtualLutTable[virtualLut]));
    /* Run XSPI command */
    status = Xspi_Ip_IpWrite(Xspi_Ip_GetHifAddr(state->connection), XSPI_IP_COMMAND_LUT, state->baseAddress + addr, data, size);

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_CheckStatusReg
 * Description   : Checks a bitfield in the status register
 * Xspi_Ip_CheckStatusReg_Activity */
static Xspi_Ip_StatusType Xspi_Ip_CheckStatusReg(uint32 instance,
                                                 uint8 offset,
                                                 uint8 width,
                                                 uint8 *value,
                                                 uint32 address
                                                )
{
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    const Xspi_Ip_StatusConfigType *statusConfig = &(state->configuration->statusConfig);
    uint8 data[4];
    Xspi_Ip_StatusType status;

    /* Read status register */
    status = Xspi_Ip_RunReadCommand(instance, (uint16)XSPI_IP_LUT_PHYS_SEQ_READ_STATUS, address, data, NULL_PTR, statusConfig->regSize);
    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Extract bit-field */
        *value = (uint8)Xspi_Ip_GetBitfield(data, statusConfig->regSize, offset, width);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_WriteEnable
 * Description   : Enables the serial flash memory for a program or erase operation
 * Xspi_Ip_WriteEnable_Activity */
static Xspi_Ip_StatusType Xspi_Ip_WriteEnable(uint32 instance, uint32 address)
{
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    const Xspi_Ip_StatusConfigType *statusConfig = &(state->configuration->statusConfig);

    uint32 retries = XSPI_IP_MAX_RETRY + 1U;
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_TIMEOUT;
    Xspi_Ip_StatusType cmdStatus;
    uint8 welValue = 0U;

    MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_IPCOMMAND_WAIT_IN_WREN);

#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
    if (XSPI_IP_HYPER_RAM == state->configuration->memType)
    {
        /*Do nothing for HyperRam */
        status = STATUS_XSPI_IP_SUCCESS;
    }
    else
#endif
    {
        while (retries > 0UL)
        {
            /* send WREN command */
            cmdStatus = Xspi_Ip_RunCommand(instance, (uint16)XSPI_IP_LUT_PHYS_SEQ_WRITE_ENABLE, address);
            if (STATUS_XSPI_IP_SUCCESS == cmdStatus)
            {
                /* check WEL bit */
                cmdStatus = Xspi_Ip_CheckStatusReg(instance, statusConfig->writeEnableOffset, 1U, &welValue, address);
            }
            if (STATUS_XSPI_IP_SUCCESS == cmdStatus)
            {
                /* 1 == check WEL */
                if (1U == welValue)
                {
                    status = STATUS_XSPI_IP_SUCCESS;
                    break;
                }
            }
            else
            {
                /* record error */
                status = cmdStatus;
            }
            retries--;
        }
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_WaitResetComplete
 * Description   : Wait until external memory is available for operation after a reset
 * Xspi_Ip_WaitResetComplete_Activity */
static void Xspi_Ip_WaitResetComplete(void)
{
    uint32 ElapsedTicks = 0UL;
    uint32 TimeoutTicks;
    uint32 CurrentTicks;

    /* Prepare timeout counter */
    TimeoutTicks = OsIf_MicrosToTicks(XSPI_IP_RESET_TIMEOUT, XSPI_IP_TIMEOUT_TYPE);
    CurrentTicks = OsIf_GetCounter(XSPI_IP_TIMEOUT_TYPE);
    /* Wait for the specified time */
    do
    {
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, XSPI_IP_TIMEOUT_TYPE);
    }
    while (ElapsedTicks < TimeoutTicks);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_InitWriteReg
 * Description   : Write the configured value into a register of external flash device
 * Xspi_Ip_InitWriteReg_Activity */
static Xspi_Ip_StatusType Xspi_Ip_InitWriteReg(uint32 instance,
                                               const Xspi_Ip_InitOperationType * operation
                                              )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    uint8 value[4U]={0U,0U,0U,0U};

    /* write a value in a register */
    if (XSPI_IP_LUT_INVALID != operation->weLut)
    {
        /* send WREN command */
        status = Xspi_Ip_RunInitCommand(instance, operation->weLut, operation->addr);
    }
    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        Xspi_Ip_SetValue(value, operation->size, operation->value);
        status = Xspi_Ip_RunInitWriteCommand(instance, operation->command1Lut, operation->addr, value, operation->size);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_InitRMWReg
 * Description   : Change a bitfield in a register of external flash device
 * Xspi_Ip_InitRMWReg_Activity */
static Xspi_Ip_StatusType Xspi_Ip_InitRMWReg(uint32 instance,
                                             const Xspi_Ip_InitOperationType *operation
                                            )
{
    Xspi_Ip_StatusType status;
    uint32 fieldVal;
    uint8 value[4U];

    /* Read current register value */
    status = Xspi_Ip_RunInitReadCommand(instance, operation, value, NULL_PTR);
    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Retrieve target bitfield */
        fieldVal = Xspi_Ip_GetBitfield(value, operation->size, operation->shift, operation->width);
        if (fieldVal != operation->value)
        {
            /* Modify target bitfield */
            Xspi_Ip_SetBitfield(value, operation->size, operation->shift, operation->width, operation->value);
            if (XSPI_IP_LUT_INVALID != operation->weLut)
            {
                /* Send WREN command */
                status = Xspi_Ip_RunInitCommand(instance, operation->weLut, operation->addr);
            }
            if (STATUS_XSPI_IP_SUCCESS == status)
            {
                /* Write back register value; use second LUT command */
                status = Xspi_Ip_RunInitWriteCommand(instance, operation->command2Lut, operation->addr, (uint8 *)&value, operation->size);
            }
        }
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_InitReadReg
 * Description   : Read the register's value of external flash device and loop until matching the configured one
 * Xspi_Ip_InitReadReg_Activity */
static Xspi_Ip_StatusType Xspi_Ip_InitReadReg(uint32 instance,
                                              const Xspi_Ip_InitOperationType *operation
                                             )
{
    Xspi_Ip_StatusType status;
    uint32 fieldVal = 0xFFFFFFFFUL;  /* Invalid initial value */
    uint8 value[4U];
    uint32 ElapsedTicks = 0UL;
    uint32 TimeoutTicks;
    uint32 CurrentTicks;

    /* Prepare timeout counter */
    TimeoutTicks = OsIf_MicrosToTicks(XSPI_IP_FLS_INIT_TIMEOUT, XSPI_IP_TIMEOUT_TYPE);
    CurrentTicks = OsIf_GetCounter(XSPI_IP_TIMEOUT_TYPE);
    do
    {
        /* read current register value */
        status = Xspi_Ip_RunInitReadCommand(instance, operation, value, NULL_PTR);
        if (STATUS_XSPI_IP_SUCCESS == status)
        {
            /* retrieve target bitfield */
            fieldVal = Xspi_Ip_GetBitfield(value, operation->size, operation->shift, operation->width);
        }
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, XSPI_IP_TIMEOUT_TYPE);
        if (ElapsedTicks >= TimeoutTicks)
        {
            status = STATUS_XSPI_IP_TIMEOUT;
            break;
        }
    }
    while (fieldVal != operation->value);

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_InitOperation
 * Description   : Execute initialization sequence to get the serial flash memory in the target state for operation */
static Xspi_Ip_StatusType Xspi_Ip_InitOperation(uint32 instance,
                                                const Xspi_Ip_StateType *state,
                                                uint8 initOp
                                               )
{
    const Xspi_Ip_InitOperationType *initOperations = state->configuration->initConfiguration.operations;
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;

    switch (initOperations[initOp].opType)
    {
        case XSPI_IP_OP_TYPE_CMD:
            /* Execute a simple command */
            status = Xspi_Ip_RunInitCommand(instance, initOperations[initOp].command1Lut, initOperations[initOp].addr);
            break;

        case XSPI_IP_OP_TYPE_WRITE_REG:
            /* Write value into the register */
            status = Xspi_Ip_InitWriteReg(instance, &initOperations[initOp]);
            break;

        case XSPI_IP_OP_TYPE_RMW_REG:
            /* Change a bitfield in the register */
            status = Xspi_Ip_InitRMWReg(instance, &initOperations[initOp]);
            break;

        case XSPI_IP_OP_TYPE_READ_REG:
            /* Check a bitfield in the register */
            status = Xspi_Ip_InitReadReg(instance, &initOperations[initOp]);
            break;

        case XSPI_IP_OP_TYPE_XSPI_CFG:
            /* Re-initialize XSPI controller with the given configuration */
            (void)Xspi_Ip_ControllerDeinit(state->connection->xspiInstance);
            status = Xspi_Ip_ControllerInit(state->connection->xspiInstance, initOperations[initOp].ctrlCfgPtr);
            break;

        default:
            ; /* unknown operation */
            break;
    }   /* switch */

    return status;

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_InitDevice
 * Description   : Execute initialization sequence to get the serial flash memory in the target state for operation
*       Xspi_Ip_InitDevice_Activity */
static Xspi_Ip_StatusType Xspi_Ip_InitDevice(uint32 instance,
                                             const Xspi_Ip_StateType *state
                                            )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    uint8 initConfigOpCount = state->configuration->initConfiguration.opCount;
    uint8 initOp;

    MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_IPCOMMAND_INITDEVICE);

    /* Perform operations in initialization list (common) */
    for (initOp = 0; initOp < initConfigOpCount; initOp++)
    {
        status = Xspi_Ip_InitOperation(instance, state, initOp);

        if (STATUS_XSPI_IP_SUCCESS != status)
        {
            break;
        }
    }

#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
    /* Perform device initialization (specific) */
    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        if (XSPI_IP_HYPER_RAM == state->configuration->memType)
        {
            status = Xspi_Ip_HyperRamInit(instance);
        }
    }
#endif
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_InitReset
 * Description   : Perform the software reset sequence
*       Xspi_Ip_InitReset_Activity */
static Xspi_Ip_StatusType Xspi_Ip_InitReset(uint32 instance,
                                            uint16 resetCmdLut,
                                            uint8 resetCmdCount,
                                            const Xspi_Ip_StateType *state
                                           )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    uint16 virtualLut = resetCmdLut;
    uint8 cnt;

    if (XSPI_IP_LUT_INVALID != resetCmdLut)
    {
        for (cnt = 0U; cnt < resetCmdCount; cnt++)
        {
            if (cnt > 0U)
            {
                virtualLut = getNextVlut(state, virtualLut);
            }
            /* Run command */
            status = Xspi_Ip_RunInitCommand(instance, virtualLut, 0U);
            if (status != STATUS_XSPI_IP_SUCCESS)
            {
                break;
            }
        }
        if (STATUS_XSPI_IP_SUCCESS == status)
        {
            /* Ensure flash is ready after reset */
            Xspi_Ip_WaitResetComplete();
        }
    }

    return status;
}

void Xspi_Ip_ProcessErrors(uint32 instance)
{
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    if (0u == state->connection->hifInstance) /* master HIF */
    {
        if (Xspi_Ip_GotMasterErrors(Xspi_Ip_GetHifAddr(state->connection)))
        {
            /* TODO Callout */
            Xspi_Ip_ClearMasterErrors(Xspi_Ip_GetHifAddr(state->connection));
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_InitLuts
 * Description   : Perform the software reset sequence
*       Xspi_Ip_InitLuts_Activity */
void Xspi_Ip_InitLuts(const Xspi_Ip_StateType *state)
{
    const Xspi_Ip_InstrOpType *virtualLutTable = state->configuration->lutSequences.lutOps;
    const Xspi_Ip_MemoryConfigType *configuration = state->configuration;
    uint32 xspiInstance = state->connection->xspiInstance;
    uint8 eraseType;

    /* Read command  */
    Xspi_Ip_SetLutSeq(xspiInstance, (uint8)XSPI_IP_LUT_PHYS_SEQ_READ, &(virtualLutTable[configuration->readLut]));
    /* Write command */
    Xspi_Ip_SetLutSeq(xspiInstance, (uint8)XSPI_IP_LUT_PHYS_SEQ_WRITE, &(virtualLutTable[configuration->writeLut]));
    /* Erase commands */
    for (eraseType = 0U; eraseType < XSPI_IP_ERASE_TYPES; eraseType++)
    {
        if (XSPI_IP_LUT_INVALID != configuration->eraseSettings.eraseTypes[eraseType].eraseLut)
        {
            Xspi_Ip_SetLutSeq(xspiInstance, ((uint8)XSPI_IP_LUT_PHYS_SEQ_ERASE+eraseType), &(virtualLutTable[configuration->eraseSettings.eraseTypes[eraseType].eraseLut]));
        }
    }
    /* Read status register */
    Xspi_Ip_SetLutSeq(xspiInstance, (uint8)XSPI_IP_LUT_PHYS_SEQ_READ_STATUS, &(virtualLutTable[configuration->statusConfig.statusRegReadLut]));
    /* Write enable */
    Xspi_Ip_SetLutSeq(xspiInstance, (uint8)XSPI_IP_LUT_PHYS_SEQ_WRITE_ENABLE, &(virtualLutTable[configuration->statusConfig.writeEnableLut]));
    /* Clear error */
    if (XSPI_IP_LUT_INVALID != configuration->statusConfig.clearErrLut)
    {
        Xspi_Ip_SetLutSeq(xspiInstance, (uint8)XSPI_IP_LUT_PHYS_SEQ_CLEAR_ERR, &(virtualLutTable[configuration->statusConfig.clearErrLut]));
    }
    if (XSPI_IP_LUT_INVALID != configuration->readIdSettings.readIdLut)
    {
        /* Read deviceID command  */
        Xspi_Ip_SetLutSeq(xspiInstance, (uint8)XSPI_IP_LUT_PHYS_SEQ_READ_DEVICEID, &(virtualLutTable[configuration->readIdSettings.readIdLut]));
    }

    if (XSPI_IP_LUT_INVALID != configuration->suspendSettings.eraseSuspendLut)
    {
        /* Erase suspend command  */
        Xspi_Ip_SetLutSeq(xspiInstance, (uint8)XSPI_IP_LUT_PHYS_SEQ_ERASE_SUSPEND, &(virtualLutTable[configuration->suspendSettings.eraseSuspendLut]));
    }
    if (XSPI_IP_LUT_INVALID != configuration->suspendSettings.eraseResumeLut)
    {
        /* Erase resume command  */
        Xspi_Ip_SetLutSeq(xspiInstance, (uint8)XSPI_IP_LUT_PHYS_SEQ_ERASE_RESUME, &(virtualLutTable[configuration->suspendSettings.eraseResumeLut]));
    }
    if (XSPI_IP_LUT_INVALID != configuration->suspendSettings.programSuspendLut)
    {
        /* Write suspend command  */
        Xspi_Ip_SetLutSeq(xspiInstance, (uint8)XSPI_IP_LUT_PHYS_SEQ_PROGRAM_SUSPEND, &(virtualLutTable[configuration->suspendSettings.programSuspendLut]));
    }
    if (XSPI_IP_LUT_INVALID != configuration->suspendSettings.programResumeLut)
    {
        /* Write resume command  */
        Xspi_Ip_SetLutSeq(xspiInstance, (uint8)XSPI_IP_LUT_PHYS_SEQ_PROGRAM_RESUME, &(virtualLutTable[configuration->suspendSettings.programResumeLut]));
    }

    if (XSPI_IP_LUT_INVALID != configuration->optionalLuts.OptionalLut1)
    {
        Xspi_Ip_SetLutSeq(xspiInstance, (uint8)XSPI_IP_LUT_PHYS_SEQ_OPTIONAL_1, &(virtualLutTable[configuration->optionalLuts.OptionalLut1]));
    }
    if (XSPI_IP_LUT_INVALID != configuration->optionalLuts.OptionalLut2)
    {
        Xspi_Ip_SetLutSeq(xspiInstance, (uint8)XSPI_IP_LUT_PHYS_SEQ_OPTIONAL_2, &(virtualLutTable[configuration->optionalLuts.OptionalLut2]));
    }

    /* Enable AHB reads */
    Xspi_Ip_SetAhbSeqId(xspiInstance, (uint8)XSPI_IP_LUT_PHYS_SEQ_READ);

    /* Enable AHB writes */
    Xspi_Ip_SetAhbWriteSeqId(xspiInstance, (uint8)XSPI_IP_LUT_PHYS_SEQ_WRITE);

    /* Configure access rights of HIFs to LUTs */
    Xspi_Ip_SetLutAccess(xspiInstance, configuration->accessRights);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_BasicErase
 * Description   : Perform one of the supported erase types in the serial flash.
 * Xspi_Ip_BasicErase_Activity */
static Xspi_Ip_StatusType Xspi_Ip_BasicErase(uint32 instance,
                                             uint32 address,
                                             uint16 eraseLut
                                            )
{
    Xspi_Ip_StatusType status;

    /* enable write before erasing */
    status = Xspi_Ip_WriteEnable(instance, address);

    MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_IPCOMMAND_WAIT_IN_BASICERS);

    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        /* launch erase command */
        status = Xspi_Ip_RunCommand(instance, eraseLut, address);
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_CalcPaddingRead
 * Description   : Calculates the number of padding bytes to handle reading from unaligned addresses
 */
static inline uint32 Xspi_Ip_CalcPaddingRead(const Xspi_Ip_StateType *state,
                                             uint32 *address,
                                             uint32 *size
                                            )
{
    const uint32 readAlignment = state->connection->memAlignment;

    /* Checking for unaligned addresses */
    uint32 offset = *address & (readAlignment - 1U);
    if (offset != 0U)
    {
        /* The number of padding bytes to handle unaligned address */
        Xspi_Ip_MemoryPadding = (uint8)offset;
        /* Decreasing the address */
        *address -= offset;
        /* Increasing the size to compensate */
        *size += offset;
    }

    return offset;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ReadSync
 * Description   : Read data from serial flash
 * Xspi_Ip_ReadSync_Activity */
static Xspi_Ip_StatusType Xspi_Ip_ReadSync(uint32 instance,
                                           uint32 address,
                                           uint8 * data,
                                           uint32 size
                                          )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    uint32 crtAddress = address;
    uint8 * crtData = data;
    uint32 crtSize = size;
    uint32 chunkSize = XSPI_IP_MAX_READ_SIZE;
    uint32 offset;
    uint32 ElapsedTicks = 0UL;
    uint32 TimeoutTicks;
    uint32 CurrentTicks;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(crtAddress >= state->baseAddress);
    DEV_ASSERT_XSPI((crtAddress - state->baseAddress) < state->configuration->memSize);
    DEV_ASSERT_XSPI((crtSize > 0UL) && ((crtAddress - state->baseAddress + crtSize ) <= state->configuration->memSize));
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_XSPI(data != NULL_PTR);
#endif

    offset = Xspi_Ip_CalcPaddingRead(state, &crtAddress, &crtSize);

    /* Prepare timeout counter */
    TimeoutTicks = OsIf_MicrosToTicks(XSPI_IP_READ_TIMEOUT, XSPI_IP_TIMEOUT_TYPE);
    CurrentTicks = OsIf_GetCounter(XSPI_IP_TIMEOUT_TYPE);
    while ((crtSize > 0UL) && (STATUS_XSPI_IP_SUCCESS == status))
    {
        if (chunkSize > crtSize)
        {
            /* Adjust size for last chunk */
            chunkSize = crtSize;
        }
        /* Check timeout */
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, XSPI_IP_TIMEOUT_TYPE);
        if (ElapsedTicks >= TimeoutTicks)
        {
            status = STATUS_XSPI_IP_TIMEOUT;
            break;
        }

        /* Perform read*/
        status = Xspi_Ip_RunReadCommand(instance, (uint16)XSPI_IP_LUT_PHYS_SEQ_READ, crtAddress, crtData, NULL_PTR, chunkSize);
        /* Move to next chunk */
        crtSize    -= chunkSize;
        crtAddress += chunkSize;
        crtData     = &(crtData[chunkSize - offset]);  /* Handle alignment for the first read */
        offset      = 0U;

        /* Call user callout, if available, to check ECC or CRC status */
        if ( (STATUS_XSPI_IP_SUCCESS == status) && (NULL_PTR != state->configuration->eccCheckCallout) )
        {
            status = state->configuration->eccCheckCallout(instance, crtAddress, chunkSize);
        }
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ProgramVerifySync
 * Description   : Verifies data written in serial flash
 * Xspi_Ip_ProgramVerifySync_Activity */
static Xspi_Ip_StatusType Xspi_Ip_ProgramVerifySync(uint32 instance,
                                                    uint32 address,
                                                    const uint8 * data,
                                                    uint32 size
                                                   )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);

    uint32 crtAddress = address;
    const uint8 * crtData = data;
    uint32 crtSize = size;
    uint32 chunkSize = XSPI_IP_MAX_READ_SIZE;
    uint32 offset;
    uint32 ElapsedTicks = 0UL;
    uint32 TimeoutTicks;
    uint32 CurrentTicks;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(crtAddress >= state->baseAddress);
    DEV_ASSERT_XSPI((crtAddress - state->baseAddress) < state->configuration->memSize);
    DEV_ASSERT_XSPI((crtSize > 0UL) && ((crtAddress - state->baseAddress + crtSize ) <= state->configuration->memSize));
    DEV_ASSERT_XSPI(data != NULL_PTR);
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
#endif

    /* Checks and handles unaligned addresses */
    offset = Xspi_Ip_CalcPaddingRead(state, &crtAddress, &crtSize);

    /* Prepare timeout counter */
    TimeoutTicks = OsIf_MicrosToTicks(XSPI_IP_READ_TIMEOUT, XSPI_IP_TIMEOUT_TYPE);
    CurrentTicks = OsIf_GetCounter(XSPI_IP_TIMEOUT_TYPE);
    while ((crtSize > 0U) && (STATUS_XSPI_IP_SUCCESS == status))
    {
        if (chunkSize > crtSize)
        {
            /* Adjust size for last chunk */
            chunkSize = crtSize;
        }
        /* Check timeout */
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, XSPI_IP_TIMEOUT_TYPE);
        if (ElapsedTicks >= TimeoutTicks)
        {
            status = STATUS_XSPI_IP_TIMEOUT;
            break;
        }

        /*Perform read and verify*/
        status = Xspi_Ip_RunReadCommand(instance, (uint16)XSPI_IP_LUT_PHYS_SEQ_READ, crtAddress, NULL_PTR, crtData, chunkSize);
        /* Move to next chunk */
        crtSize    -= chunkSize;
        crtAddress += chunkSize;
        crtData = &(crtData[chunkSize - offset]);  /* Handle alignment for the first read */
        offset = 0U;
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_EraseVerifySync
 * Description   : Verifies that an area in serial flash is in erased state
 * Xspi_Ip_EraseVerifySync_Activity */
static Xspi_Ip_StatusType Xspi_Ip_EraseVerifySync(uint32 instance,
                                                  uint32 address,
                                                  uint32 size
                                                 )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    uint32 crtAddress = address;
    uint32 crtSize = size;
    uint32 chunkSize = XSPI_IP_MAX_READ_SIZE;
    uint32 ElapsedTicks = 0UL;
    uint32 TimeoutTicks;
    uint32 CurrentTicks;

    (void)Xspi_Ip_CalcPaddingRead(state, &crtAddress, &crtSize);

    /* Prepare timeout counter */
    TimeoutTicks = OsIf_MicrosToTicks(XSPI_IP_READ_TIMEOUT, XSPI_IP_TIMEOUT_TYPE);
    CurrentTicks = OsIf_GetCounter(XSPI_IP_TIMEOUT_TYPE);

    while ((crtSize > 0U) && (STATUS_XSPI_IP_SUCCESS == status))
    {
        if (chunkSize > crtSize)
        {
            /* Adjust size for last chunk */
            chunkSize = crtSize;
        }
        /* Check timeout */
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, XSPI_IP_TIMEOUT_TYPE);
        if (ElapsedTicks >= TimeoutTicks)
        {
            status = STATUS_XSPI_IP_TIMEOUT;
            break;
        }

        /*Perform read and verify*/
        status = Xspi_Ip_RunReadCommand(instance, (uint16)XSPI_IP_LUT_PHYS_SEQ_READ, crtAddress, NULL_PTR, NULL_PTR, chunkSize);
        /* Move to next chunk */
        crtSize    -= chunkSize;
        crtAddress += chunkSize;
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_CalcPaddingWrite
 * Description   : Calculates the number of padding bytes to handle writing to unaligned addresses
 */
static inline uint32 Xspi_Ip_CalcPaddingWrite(const Xspi_Ip_StateType *state,
                                              uint32 address,
                                              uint32 size
                                             )
{
    uint32 alignmentMask = (uint32)(state->connection->memAlignment) - 1UL;

    /* The number of pre-padding bytes */
    uint32 prePadding    = address & alignmentMask;

    /* The number of post-padding bytes */
    uint32 endAddr       = address + size - 1UL;
    uint32 postPadding   = alignmentMask - (endAddr & alignmentMask);

    /* Store padding information */
    Xspi_Ip_MemoryPadding = (uint8)((prePadding << 4UL) | postPadding);

    /* Decreasing the address */
    return ((uint32)(address - prePadding));
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ProgramSync
 * Description   : Writes data in serial flash
 * Xspi_Ip_ProgramSync_Activity */
static Xspi_Ip_StatusType Xspi_Ip_ProgramSync(uint32 instance,
                                              uint32 address,
                                              const uint8 * data,
                                              uint32 size
                                             )
{
    Xspi_Ip_StatusType status;
    uint32 alignedAddress;
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);

    /* enable write before programming */
    status = Xspi_Ip_WriteEnable(instance, address);
    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Perform alignment checking before write data */
        alignedAddress = Xspi_Ip_CalcPaddingWrite(state, address, size);
        /* Write data to serial flash */
        status = Xspi_Ip_RunWriteCommand(instance, (uint16)XSPI_IP_LUT_PHYS_SEQ_WRITE, alignedAddress, data, size);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_EraseBlockSync
 * Description   : Erase a sector in the serial flash.
 *                 The size must match one of the device's erase types.
 * Xspi_Ip_EraseBlockSync_Activity */
static Xspi_Ip_StatusType Xspi_Ip_EraseBlockSync(uint32 instance,
                                                 uint32 address,
                                                 uint32 size
                                                )
{
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;
    uint8 eraseType;

    /* find the suited erase type */
    for (eraseType = 0U; eraseType < XSPI_IP_ERASE_TYPES; eraseType++)
    {
        if ((state->configuration->eraseSettings.eraseTypes[eraseType].eraseLut != XSPI_IP_LUT_INVALID) &&
            (size == (uint32)((uint32)1U << (state->configuration->eraseSettings.eraseTypes[eraseType].size))))
        {
            break;
        }
    }
    /* if erase type was found, launch the erase */
    if (eraseType < XSPI_IP_ERASE_TYPES)
    {
        status = Xspi_Ip_BasicErase(instance, address, ((uint16)XSPI_IP_LUT_PHYS_SEQ_ERASE+eraseType));
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_EraseBlockSync
 * Description   : Erase a sector in the serial flash.
 *                 The size must match one of the device's erase types.
*/
static Xspi_Ip_StatusType Xspi_Ip_EraseHyperRamSync(uint32 instance,
                                                 uint32 address,
                                                 uint32 size
                                                )
{
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_XSPI(address >= state->baseAddress);
    DEV_ASSERT_XSPI((address - state->baseAddress) < state->configuration->memSize);
    DEV_ASSERT_XSPI((size > 0UL) && ((address - state->baseAddress + size) <= state->configuration->memSize));
#endif

    /* Run XSPI command */
    status = Xspi_Ip_IpHyperRamErase(Xspi_Ip_GetHifAddr(state->connection), (uint8)XSPI_IP_LUT_PHYS_SEQ_WRITE, address, size);
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ArbLock
 * Description   : Locks XSPI arbitration
 * Xspi_Ip_ArbLock_Activity */
static Xspi_Ip_StatusType Xspi_Ip_ArbLock(uint32 instance, uint32 address)
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
#endif

    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    const Xspi_Ip_StatusConfigType *statusConfig = &(state->configuration->statusConfig);

    /* Request arbitration lock - use status register read command to also check flash availability */
    status = Xspi_Ip_ControllerArbLock(Xspi_Ip_GetHifAddr(state->connection), (uint8)XSPI_IP_LUT_PHYS_SEQ_READ_STATUS, address, statusConfig->regSize);

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ArbUnlock
 * Description   : Unlocks XSPI arbitration
 * Xspi_Ip_ArbUnlock_Activity */
Xspi_Ip_StatusType Xspi_Ip_ArbUnlock(uint32 instance, uint32 address)
{
#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
#endif
    Xspi_Ip_StatusType status;
    Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    const Xspi_Ip_StatusConfigType *statusConfig = &(state->configuration->statusConfig);

    status = Xspi_Ip_ControllerArbUnlock(Xspi_Ip_GetHifAddr(state->connection), (uint8)XSPI_IP_LUT_PHYS_SEQ_READ_STATUS, address, (uint8 *)&(state->srValue), statusConfig->regSize);


    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_GetMemStatus
 * Description   : Read the flash status register to check the status of the last operation
 * Xspi_Ip_GetMemStatus_Activity */
static Xspi_Ip_StatusType Xspi_Ip_GetMemStatus(uint32 instance, uint32 address)
{
    Xspi_Ip_StatusType status;
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    const Xspi_Ip_StatusConfigType *statusConfig = &(state->configuration->statusConfig);
    uint32 srValue = 0x0;

    /* Read status register */
    status = Xspi_Ip_RunReadCommand(instance, (uint16)XSPI_IP_LUT_PHYS_SEQ_READ_STATUS, address, (uint8 *)&srValue, NULL_PTR, statusConfig->regSize);

    /* Check meaning of returned value */
    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        status = Xspi_Ip_CheckMemStatus(instance, address, srValue);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_CheckMemStatus
 * Description   : Checks the status of the last operation
 * Xspi_Ip_CheckMemStatus_Activity */
static Xspi_Ip_StatusType Xspi_Ip_CheckMemStatus(uint32 instance,
                                                 uint32 address,
                                                 uint32 srValue
                                                )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_BUSY;
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    const Xspi_Ip_StatusConfigType *statusConfig = &(state->configuration->statusConfig);

    if ((srValue & statusConfig->busyMask) == statusConfig->busyValue)
    {
        status = STATUS_XSPI_IP_BUSY;
    }
    else if ((srValue & statusConfig->busyMask) == statusConfig->idleValue)
    {
        status = STATUS_XSPI_IP_SUCCESS;
    }
    else
    {
        /* Neither busy nor idle means error. Try to clear it and then report it.  */
        (void)Xspi_Ip_RunCommand(instance, (uint16)XSPI_IP_LUT_PHYS_SEQ_CLEAR_ERR, address);
        status = STATUS_XSPI_IP_ERROR;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_CheckLastCommand
 * Description   : Checks last command
 * Xspi_Ip_CheckLastCommand_Activity */
static Xspi_Ip_StatusType Xspi_Ip_CheckLastCommand(uint32 instance,
                                                   Xspi_Ip_StateType * state
                                                  )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;

    switch(state->lastCommand)
    {
        case XSPI_IP_LAST_COMMAND_READ:
            status = Xspi_Ip_ReadSync(instance, state->lastAddress, state->lastRData, state->lastSize);
            break;

        case XSPI_IP_LAST_COMMAND_WRITE:
            status = Xspi_Ip_ProgramSync(instance, state->lastAddress, state->lastWData, state->lastSize);
            /* Write operation needs time to complete in flash */
            state->cmdState = XSPI_COMMAND_WAIT_EXT_DEVICE_BUSY;
            break;

        case XSPI_IP_LAST_COMMAND_ERASE:
#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
            if (XSPI_IP_HYPER_RAM == state->configuration->memType)
            {
                status = Xspi_Ip_EraseHyperRamSync(instance, state->lastAddress, state->lastSize);
            }
            else
#endif
            {
                status = Xspi_Ip_EraseBlockSync(instance, state->lastAddress, state->lastSize);
            }
            /* Erase operation needs time to complete in flash */
            state->cmdState = XSPI_COMMAND_WAIT_EXT_DEVICE_BUSY;
            break;

        case XSPI_IP_LAST_COMMAND_BLANK_CHECK:
            status = Xspi_Ip_EraseVerifySync(instance, state->lastAddress, state->lastSize);
            break;

        case XSPI_IP_LAST_COMMAND_PROGRAM_VERIFY:
            status = Xspi_Ip_ProgramVerifySync(instance, state->lastAddress, state->lastWData, state->lastSize);
            break;

        case XSPI_IP_LAST_COMMAND_ERASE_RESUME:
            /*Send command erase resume*/
            status = Xspi_Ip_RunCommand(instance, (uint16)XSPI_IP_LUT_PHYS_SEQ_ERASE_RESUME, state->baseAddress);

            /*Set command erase to continue job erase*/
            state->lastCommand = XSPI_IP_LAST_COMMAND_ERASE;

            /* Erase operation needs time to complete in flash */
            state->cmdState = XSPI_COMMAND_WAIT_EXT_DEVICE_BUSY;
            break;

        case XSPI_IP_LAST_COMMAND_PROGRAM_RESUME:
            /*Send command program resume STATUS_XSPI_IP_BUSY*/
            status = Xspi_Ip_RunCommand(instance, (uint16)XSPI_IP_LUT_PHYS_SEQ_PROGRAM_RESUME, state->baseAddress);

            /*Set command write to continue job write*/
            state->lastCommand = XSPI_IP_LAST_COMMAND_WRITE;

            /* Write operation needs time to complete in flash */
            state->cmdState = XSPI_COMMAND_WAIT_EXT_DEVICE_BUSY;
            break;

        default:
            /* unknown command */
            break;
    }
    return status;
}

/*******************************************************************************
 * Code
 ******************************************************************************/


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_RunCommand
 * Description   : Launches a simple command for the serial flash
* @implements      Xspi_Ip_RunCommand_Activity */
Xspi_Ip_StatusType Xspi_Ip_RunCommand(uint32 instance,
                                      uint16 lut,
                                      uint32 addr
                                     )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_XSPI(lut != XSPI_IP_LUT_INVALID);
    DEV_ASSERT_XSPI(addr >= state->baseAddress);
    DEV_ASSERT_XSPI((addr - state->baseAddress) < state->configuration->memSize);
#endif

    if (lut != XSPI_IP_LUT_INVALID)
    {
        /* Run XSPI command */
        status = Xspi_Ip_IpCommand(Xspi_Ip_GetHifAddr(state->connection), (uint8)lut, addr);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_RunReadCommand
 * Description   : Launches a read command for the serial flash
* @implements      Xspi_Ip_RunReadCommand_Activity */
Xspi_Ip_StatusType Xspi_Ip_RunReadCommand(uint32 instance,
                                          uint16 lut,
                                          uint32 addr,
                                          uint8 * dataRead,
                                          const uint8 * dataCmp,
                                          uint32 size
                                         )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_XSPI(lut != XSPI_IP_LUT_INVALID);
    DEV_ASSERT_XSPI(addr >= state->baseAddress);
    DEV_ASSERT_XSPI((addr - state->baseAddress) < state->configuration->memSize);
    DEV_ASSERT_XSPI((size > 0UL) && ((addr - state->baseAddress + size) <= state->configuration->memSize));
#endif

    if (lut != XSPI_IP_LUT_INVALID)
    {
        /* Run XSPI command */
        status = Xspi_Ip_IpRead(Xspi_Ip_GetHifAddr(state->connection), (uint8)lut, addr, dataRead, dataCmp, size);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_RunWriteCommand
 * Description   : Launches a write command for the serial flash
 * @implements     Xspi_Ip_RunWriteCommand_Activity */
Xspi_Ip_StatusType Xspi_Ip_RunWriteCommand(uint32 instance,
                                           uint16 lut,
                                           uint32 addr,
                                           const uint8 * data,
                                           uint32 size
                                          )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_XSPI(lut != XSPI_IP_LUT_INVALID);
    DEV_ASSERT_XSPI(addr >= state->baseAddress);
    DEV_ASSERT_XSPI((addr - state->baseAddress) < state->configuration->memSize);
    DEV_ASSERT_XSPI((size > 0UL) && ((addr - state->baseAddress + size) <= state->configuration->memSize));
    DEV_ASSERT_XSPI(data != NULL_PTR);
#endif

    if (lut != XSPI_IP_LUT_INVALID)
    {
        /* Run XSPI command */
        status = Xspi_Ip_IpWrite(Xspi_Ip_GetHifAddr(state->connection), (uint8)lut, addr, data, size);
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_GetJobStatus
 * Description   : Get the status of the last operation
 * @implements     Xspi_Ip_GetJobStatus_Activity */
Xspi_Ip_StatusType Xspi_Ip_GetJobStatus(uint32 instance)
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    Xspi_Ip_StatusType unlockStatus = STATUS_XSPI_IP_ERROR;
    Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    const Xspi_Ip_StatusConfigType *statusConfig = &(state->configuration->statusConfig);
    uint32 srValue = 0x0;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
#endif

    /* Check if arbitration lock was obtained */
    if (XSPI_COMMAND_LOCKING_ARBITRATION == state->cmdState)
    {
        status = Xspi_Ip_ControllerGetStatus(Xspi_Ip_GetHifAddr(state->connection));
        if (STATUS_XSPI_IP_SUCCESS == status)
        {
            Xspi_Ip_MemoryPadding = 0U;

#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
            if (XSPI_IP_HYPER_RAM == state->configuration->memType)
            {
                /*Dummy read*/
                status = Xspi_Ip_IpCompleteAsyncRead(Xspi_Ip_GetHifAddr(state->connection), (uint8 *)&srValue, 2U);
                /*bypass check for hyperram*/
                srValue = statusConfig->idleValue;
            }
            else
#endif
            {
                /* Get data from async read (status register value) */
                status = Xspi_Ip_IpCompleteAsyncRead(Xspi_Ip_GetHifAddr(state->connection), (uint8 *)&srValue, statusConfig->regSize);
            }
            if (STATUS_XSPI_IP_SUCCESS == status)
            {
                /* Confirm external memory is not busy */
                if (STATUS_XSPI_IP_SUCCESS != Xspi_Ip_CheckMemStatus(instance, state->lastAddress, srValue))
                {
                    /* Memory busy, unlock arbitration and return error */
                    status = STATUS_XSPI_IP_ERROR;
                }
                else
                {
                    /* Continue operation synchronously */
                    status = Xspi_Ip_CheckLastCommand(instance, state);
                }
            }
        }
    }
    else if( (state->lastSuspendCommand == XSPI_IP_LAST_COMMAND_PROGRAM_SUSPEND) || (state->lastSuspendCommand == XSPI_IP_LAST_COMMAND_ERASE_SUSPEND) )
    {
        /* suspend state, return busy */
        status = STATUS_XSPI_IP_BUSY;
    }
#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
    if (XSPI_IP_HYPER_RAM == state->configuration->memType)
    {
        /*Do nothing, Hyperram does not need read status */
    }
    else
#endif
    {
        if ((XSPI_COMMAND_WAIT_EXT_DEVICE_BUSY == state->cmdState) && ( STATUS_XSPI_IP_SUCCESS ==  status))
        {
            /* Poll status of operation in external flash */
            status = Xspi_Ip_GetMemStatus(instance, state->lastAddress);
        }
    }

    if (( status != STATUS_XSPI_IP_BUSY ) && (state->cmdState != XSPI_COMMAND_IDLE))
    {
#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
        if (XSPI_IP_HYPER_RAM == state->configuration->memType)
        {
            /* Command completed, unlock arbitration and return status */
            unlockStatus = Xspi_Ip_HyperRamArbUnlock(instance, state->lastAddress);
        }
        else
#endif
        {
            /* Command completed, unlock arbitration and return status */
            unlockStatus = Xspi_Ip_ArbUnlock(instance, state->lastAddress);
        }
        if (STATUS_XSPI_IP_SUCCESS == status)
        {
            status = unlockStatus;
        }
        state->cmdState = XSPI_COMMAND_IDLE;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ReadId
 * Description   : Read manufacturer ID from serial flash
 * Xspi_Ip_ReadId_Activity */
Xspi_Ip_StatusType Xspi_Ip_ReadId(uint32 instance,
                                  uint8 * data
                                 )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    const Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);

#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
    if (XSPI_IP_HYPER_RAM == state->configuration->memType)
    {
        status = Xspi_Ip_RunReadCommand(instance,
                                        (uint16)XSPI_IP_LUT_PHYS_SEQ_READ_DEVICEID,
                                        state->baseAddress + state->configuration->hrConfig->deviceIdWordAddress,
                                        data,
                                        NULL_PTR,
                                        state->configuration->readIdSettings.readIdSize
                                        );
    }
    else
#endif
    {
        status = Xspi_Ip_RunReadCommand(instance,
                                        (uint16)XSPI_IP_LUT_PHYS_SEQ_READ_DEVICEID,
                                        state->baseAddress,
                                        data,
                                        NULL_PTR,
                                        state->configuration->readIdSettings.readIdSize
                                        );
    }

    return status;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ProgramSuspend
 * Description   : Suspends a program operation. If there is no pending program operation, return error status
 * @implements     Xspi_Ip_ProgramSuspend_Activity */
Xspi_Ip_StatusType Xspi_Ip_ProgramSuspend(uint32 instance)
{
#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
#endif

    Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;

#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
    if (XSPI_IP_HYPER_RAM == state->configuration->memType)
    {
        /* Do nothing Hyperram does not supportt suspend/resume*/
    }
    else
#endif
    {
        if(state->cmdState == XSPI_COMMAND_WAIT_EXT_DEVICE_BUSY)
        {
            /* Issue the Program Suspend command */
            status = Xspi_Ip_RunCommand(instance, (uint16)XSPI_IP_LUT_PHYS_SEQ_PROGRAM_SUSPEND, state->baseAddress);

            if (STATUS_XSPI_IP_SUCCESS ==  status)
            {
                /* Unlock Arbitration*/
                status = Xspi_Ip_ArbUnlock(instance, state->lastAddress);
            }
            /* Change status to suspend*/
            state->lastSuspendCommand = XSPI_IP_LAST_COMMAND_PROGRAM_SUSPEND;
        }
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ProgramResume
 * Description   : Resumes a program operation. If there is no program suspend , return error status
 * @implements     Xspi_Ip_ProgramResume_Activity */
Xspi_Ip_StatusType Xspi_Ip_ProgramResume(uint32 instance)
{
#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
#endif

    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;
    Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);

#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
    if (XSPI_IP_HYPER_RAM == state->configuration->memType)
    {
        /* Do nothing Hyperram does not support suspend/resume*/
    }
    else
#endif
    {
        if(state->lastSuspendCommand == XSPI_IP_LAST_COMMAND_PROGRAM_SUSPEND)
        {
            /* Request lock arbitration*/
            if (STATUS_XSPI_IP_SUCCESS == Xspi_Ip_ArbLock(instance, state->lastAddress))
            {
                /*This lock will be checked in the Xspi_Ip_GetJobStatus function*/
                state->cmdState = XSPI_COMMAND_LOCKING_ARBITRATION;

                /*After locked arrbitration, erase resume comand will be sent*/
                state->lastCommand = XSPI_IP_LAST_COMMAND_PROGRAM_RESUME;

                /*Resumed, set SuspendCommand as XSPI_IP_LAST_COMMAND_NONE*/
                state->lastSuspendCommand = XSPI_IP_LAST_COMMAND_NONE;

                status = STATUS_XSPI_IP_SUCCESS;
            }
        }
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_EraseSuspend
 * Description   : Suspends an erase operation. If there is no pending erase operation, return error status
 * @implements     Xspi_Ip_EraseSuspend_Activity */
Xspi_Ip_StatusType Xspi_Ip_EraseSuspend(uint32 instance)
{
#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
#endif

    Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;

#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
    if (XSPI_IP_HYPER_RAM == state->configuration->memType)
    {
        /* Do nothing Hyperram does not support suspend/resume*/
    }
    else
#endif
    {
        if(state->cmdState == XSPI_COMMAND_WAIT_EXT_DEVICE_BUSY)
        {
            /* Issue the Erase Suspend command */
            status = Xspi_Ip_RunCommand(instance, (uint16)XSPI_IP_LUT_PHYS_SEQ_ERASE_SUSPEND, state->baseAddress);

            /* Unlock Arbitration*/
            if (STATUS_XSPI_IP_SUCCESS == status)
            {
                (void)Xspi_Ip_ArbUnlock(instance, state->lastAddress);
            }
            /* Change status to suspend*/
            state->lastSuspendCommand = XSPI_IP_LAST_COMMAND_ERASE_SUSPEND;
        }
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_EraseResume
 * Description   : Resumes an erase operation. If there is no erase suspend, return error status.
 * @implements     Xspi_Ip_EraseResume_Activity */
Xspi_Ip_StatusType Xspi_Ip_EraseResume(uint32 instance)
{
#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
#endif

    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;
    Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);

#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
    if (XSPI_IP_HYPER_RAM == state->configuration->memType)
    {
        /* Do nothing Hyperram does not support suspend/resume*/
    }
    else
#endif
    {
        if(state->lastSuspendCommand == XSPI_IP_LAST_COMMAND_ERASE_SUSPEND)
        {
            /* Request lock arbitration*/
            if (STATUS_XSPI_IP_SUCCESS == Xspi_Ip_ArbLock(instance, state->lastAddress))
            {
                /*the lock status will be check on the get status function*/
                state->cmdState = XSPI_COMMAND_LOCKING_ARBITRATION;

                /*After locked arrbitration, erase resume comand will be sent*/
                state->lastCommand = XSPI_IP_LAST_COMMAND_ERASE_RESUME;

                /*Resumed, set SuspendCommand as XSPI_IP_LAST_COMMAND_NONE*/
                state->lastSuspendCommand = XSPI_IP_LAST_COMMAND_NONE;

                status = STATUS_XSPI_IP_SUCCESS;
            }
        }
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Read
 * Description   : Read data from serial flash
 * @implements     Xspi_Ip_Read_Activity */
Xspi_Ip_StatusType Xspi_Ip_Read(uint32 instance,
                                uint32 address,
                                uint8 * data,
                                uint32 size
                               )
{
    Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(address >= state->baseAddress);
    DEV_ASSERT_XSPI((address - state->baseAddress) < state->configuration->memSize);
    DEV_ASSERT_XSPI((size > 0UL) && ((address - state->baseAddress + size) <= state->configuration->memSize));
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_XSPI(data != NULL_PTR);
#endif

#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
    if (XSPI_IP_HYPER_RAM == state->configuration->memType)
    {
        status = Xspi_Ip_HyperRamArbLock(instance, address);
    }
    else
#endif
    {
        status = Xspi_Ip_ArbLock(instance, address);
    }
    /* Request arbitration lock */
    if(STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Record job information */
        state->lastAddress = address;
        state->lastRData = data;
        state->lastWData = NULL_PTR;
        state->lastSize = size;
        state->cmdState = XSPI_COMMAND_LOCKING_ARBITRATION;
        state->lastCommand = XSPI_IP_LAST_COMMAND_READ;

        status = STATUS_XSPI_IP_SUCCESS;
    }

    return status;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ProgramVerify
 * Description   : Verifies data written in serial flash
 * @implements     Xspi_Ip_ProgramVerify_Activity */
Xspi_Ip_StatusType Xspi_Ip_ProgramVerify(uint32 instance,
                                         uint32 address,
                                         const uint8 * data,
                                         uint32 size
                                        )
{
    Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(address >= state->baseAddress);
    DEV_ASSERT_XSPI((address - state->baseAddress) < state->configuration->memSize);
    DEV_ASSERT_XSPI((size > 0UL) && ((address - state->baseAddress + size) <= state->configuration->memSize));
    DEV_ASSERT_XSPI(data != NULL_PTR);
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
#endif

#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
    if (XSPI_IP_HYPER_RAM == state->configuration->memType)
    {
        status = Xspi_Ip_HyperRamArbLock(instance, address);
    }
    else
#endif
    {
        status = Xspi_Ip_ArbLock(instance, address);
    }
    /* Request arbitration lock */
    if(STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Record job information */
        state->lastAddress = address;
        state->lastRData = NULL_PTR;
        state->lastWData = data;
        state->lastSize = size;
        state->cmdState = XSPI_COMMAND_LOCKING_ARBITRATION;
        state->lastCommand = XSPI_IP_LAST_COMMAND_PROGRAM_VERIFY;

        status = STATUS_XSPI_IP_SUCCESS;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_EraseVerify
 * Description   : Verifies that an area in serial flash is in erased state
 * @implements     Xspi_Ip_EraseVerify_Activity */
Xspi_Ip_StatusType Xspi_Ip_EraseVerify(uint32 instance,
                                       uint32 address,
                                       uint32 size
                                      )
{
    Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(address >= state->baseAddress);
    DEV_ASSERT_XSPI((address - state->baseAddress) < state->configuration->memSize);
    DEV_ASSERT_XSPI((size > 0UL) && ((address - state->baseAddress + size) <= state->configuration->memSize));
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
#endif

#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
    if (XSPI_IP_HYPER_RAM == state->configuration->memType)
    {

        status = Xspi_Ip_HyperRamArbLock(instance, address);
    }
    else
#endif
    {
        status = Xspi_Ip_ArbLock(instance, address);
    }
    /* Request arbitration lock */
    if(STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Record job information */
        state->lastAddress = address;
        state->lastRData = NULL_PTR;
        state->lastWData = NULL_PTR;
        state->lastSize = size;
        state->cmdState = XSPI_COMMAND_LOCKING_ARBITRATION;
        state->lastCommand = XSPI_IP_LAST_COMMAND_BLANK_CHECK;

        status = STATUS_XSPI_IP_SUCCESS;
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Program
 * Description   : Writes data in serial flash
 * @implements     Xspi_Ip_Program_Activity */
Xspi_Ip_StatusType Xspi_Ip_Program(uint32 instance,
                                   uint32 address,
                                   const uint8 * data,
                                   uint32 size
                                  )

{
    Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_XSPI(address >= state->baseAddress);
    DEV_ASSERT_XSPI((address - state->baseAddress) < state->configuration->memSize);
    DEV_ASSERT_XSPI(data != NULL_PTR);
    DEV_ASSERT_XSPI((size > 0UL) && ((address - state->baseAddress + size) <= state->configuration->memSize));
#endif

#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
    if (XSPI_IP_HYPER_RAM == state->configuration->memType)
    {
        status = Xspi_Ip_HyperRamArbLock(instance, address);
    }
    else
#endif
    {
        status = Xspi_Ip_ArbLock(instance, address);
    }
    /* Check Request arbitration lock success*/
    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Record job information */
        state->lastAddress = address;
        state->lastRData = NULL_PTR;
        state->lastWData = data;
        state->lastSize = size;
        state->cmdState = XSPI_COMMAND_LOCKING_ARBITRATION;
        state->lastCommand = XSPI_IP_LAST_COMMAND_WRITE;

        status = STATUS_XSPI_IP_SUCCESS;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_EraseBlock
 * Description   : Writes data in serial flash
 * @implements     Xspi_Ip_EraseBlock_Activity */
Xspi_Ip_StatusType Xspi_Ip_EraseBlock(uint32 instance,
                                      uint32 address,
                                      uint32 size
                                     )

{
    Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_XSPI(address >= state->baseAddress);
    DEV_ASSERT_XSPI((address - state->baseAddress) < state->configuration->memSize);
    DEV_ASSERT_XSPI((size > 0UL) && ((address - state->baseAddress + size) <= state->configuration->memSize));
#endif

#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
    if (XSPI_IP_HYPER_RAM == state->configuration->memType)
    {
        status = Xspi_Ip_HyperRamArbLock(instance, address);
    }
    else
#endif
    {
        status = Xspi_Ip_ArbLock(instance, address);
    }
    /* Check Request arbitration lock success*/
    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Record job information */
        state->lastAddress = address;
        state->lastRData = NULL_PTR;
        state->lastWData = NULL_PTR;
        state->lastSize = size;
        state->cmdState = XSPI_COMMAND_LOCKING_ARBITRATION;
        state->lastCommand = XSPI_IP_LAST_COMMAND_ERASE;
        status = STATUS_XSPI_IP_SUCCESS;
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Init
 * Description   : Initialize the serial flash memory driver
 *
 * @implements     Xspi_Ip_Init_Activity */
Xspi_Ip_StatusType Xspi_Ip_Init(uint32 instance,
                                const Xspi_Ip_MemoryConfigType * pConfig,
                                const Xspi_Ip_MemoryConnectionType * pConnect
                               )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_XSPI(pConfig != NULL_PTR);
    DEV_ASSERT_XSPI(pConnect != NULL_PTR);
    DEV_ASSERT_XSPI(NULL_PTR == state->configuration);
#endif

#if ((XSPI_IP_CHECK_CFG_CRC == STD_ON) && (XSPI_IP_USE_SFDP_CFG == STD_OFF))
    status = Xspi_Ip_ValidateMemConfigCRC(pConfig, pConnect);
    if (STATUS_XSPI_IP_SUCCESS == status)
#endif
    {
        /* Copy configuration information to state structure */
        state->configuration = pConfig;
        state->connection = pConnect;
        state->lastCommand = XSPI_IP_LAST_COMMAND_NONE;
        state->cmdState = XSPI_COMMAND_IDLE;
        state->baseAddress = Xspi_Ip_ControllerGetBaseAdress(pConnect->xspiInstance, pConnect->connectionType);

        if (pConnect->initDevice)
        {
            /* Initialize corresponding controller if required */
            if (pConfig->ctrlAutoCfgPtr != NULL_PTR)
            {
                status = Xspi_Ip_ControllerInit(pConnect->xspiInstance, pConfig->ctrlAutoCfgPtr);
            }
            if (STATUS_XSPI_IP_SUCCESS == status)
            {
            /* Perform initial reset */
                status = Xspi_Ip_InitReset(instance, pConfig->initResetSettings.resetCmdLut, pConfig->initResetSettings.resetCmdCount, state);
            }
            if (STATUS_XSPI_IP_SUCCESS == status)
            {
                /* Execute initial setup of external device */
                status = Xspi_Ip_InitDevice(instance, state);
            }
            if (STATUS_XSPI_IP_SUCCESS == status)
            {
                /* LUT configuration (LUTn, SFP_LUT_ENn ) ; AHB Read config (BFGENCR) */
                Xspi_Ip_InitLuts(state);

                /* Initialize controller security if auto-config is enabled */
                if (pConfig->ctrlAutoCfgPtr != NULL_PTR)
                {
                    status = Xspi_Ip_ControllerInitSecurity(pConnect->xspiInstance, pConfig->ctrlAutoCfgPtr);
                }
            }
            /* If enabled, call the init callout, for additional XSPI IP or external memory settings. */
            if ((STATUS_XSPI_IP_SUCCESS == status) && (NULL_PTR != pConfig->initCallout))
            {
                status = pConfig->initCallout(instance);
            }
        }
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Deinit
 * Description   : De-initialize the serial flash memory driver
 * @implements     Xspi_Ip_Deinit_Activity */
Xspi_Ip_StatusType Xspi_Ip_Deinit(uint32 instance)
{
    Xspi_Ip_StateType * state = &(Xspi_Ip_MemoryStateStructure[instance]);
#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_REG(INSTANCE_COUNT));
    DEV_ASSERT_XSPI(state->configuration != NULL_PTR);
#endif

    state->configuration = NULL_PTR;

    return STATUS_XSPI_IP_SUCCESS;
}

#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

#endif /* (XSPI_IP_MEM_INSTANCE_COUNT > 0) */


#ifdef __cplusplus
}
#endif

/** @} */
