/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file Qspi_Ip.c
*
*   @addtogroup IPV_QSPI
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

#include "Mcal.h"
#include "OsIf.h"
#include "SchM_Mem_43_EXFLS.h"
#include "Qspi_Ip_Controller.h"
#include "Qspi_Ip_Common.h"
#include "Qspi_Ip.h"
#include "Qspi_Ip_Hyperflash.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_VENDOR_ID_C                    43
#define QSPI_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define QSPI_IP_AR_RELEASE_MINOR_VERSION_C     7
#define QSPI_IP_AR_RELEASE_REVISION_VERSION_C  0
#define QSPI_IP_SW_MAJOR_VERSION_C             2
#define QSPI_IP_SW_MINOR_VERSION_C             0
#define QSPI_IP_SW_PATCH_VERSION_C             1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((QSPI_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (QSPI_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Qspi_Ip.c and Mcal.h are different"
    #endif

    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((QSPI_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (QSPI_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Qspi_Ip.c and OsIf.h are different"
    #endif
#endif

/* Check if current file and Qspi_Ip_Controller header file are of the same vendor */
#if (QSPI_IP_VENDOR_ID_C != QSPI_IP_CONTROLLER_VENDOR_ID_H)
    #error "Qspi_Ip.c and Qspi_Ip_Controller.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Controller header file are of the same Autosar version */
#if ((QSPI_IP_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip.c and Qspi_Ip_Controller.h are different"
#endif
/* Check if current file and Qspi_Ip_Controller header file are of the same Software version */
#if ((QSPI_IP_SW_MAJOR_VERSION_C != QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_SW_MINOR_VERSION_C != QSPI_IP_CONTROLLER_SW_MINOR_VERSION_H) || \
     (QSPI_IP_SW_PATCH_VERSION_C != QSPI_IP_CONTROLLER_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip.c and Qspi_Ip_Controller.h are different"
#endif

/* Check if current file and Qspi_Ip_Common header file are of the same vendor */
#if (QSPI_IP_VENDOR_ID_C != QSPI_IP_COMMON_VENDOR_ID_H)
    #error "Qspi_Ip.c and Qspi_Ip_Common.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Common header file are of the same Autosar version */
#if ((QSPI_IP_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_COMMON_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip.c and Qspi_Ip_Common.h are different"
#endif
/* Check if current file and Qspi_Ip_Common header file are of the same Software version */
#if ((QSPI_IP_SW_MAJOR_VERSION_C != QSPI_IP_COMMON_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_SW_MINOR_VERSION_C != QSPI_IP_COMMON_SW_MINOR_VERSION_H) || \
     (QSPI_IP_SW_PATCH_VERSION_C != QSPI_IP_COMMON_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip.c and Qspi_Ip_Common.h are different"
#endif

/* Check if current file and Qspi_Ip header file are of the same vendor */
#if (QSPI_IP_VENDOR_ID_C != QSPI_IP_VENDOR_ID_H)
    #error "Qspi_Ip.c and Qspi_Ip.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip header file are of the same Autosar version */
#if ((QSPI_IP_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip.c and Qspi_Ip.h are different"
#endif
/* Check if current file and Qspi_Ip header file are of the same Software version */
#if ((QSPI_IP_SW_MAJOR_VERSION_C != QSPI_IP_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_SW_MINOR_VERSION_C != QSPI_IP_SW_MINOR_VERSION_H) || \
     (QSPI_IP_SW_PATCH_VERSION_C != QSPI_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip.c and Qspi_Ip.h are different"
#endif

/* Check if current file and Qspi_Ip_Hyperflash header file are of the same vendor */
#if (QSPI_IP_VENDOR_ID_C != QSPI_IP_HYPERFLASH_VENDOR_ID_H)
    #error "Qspi_Ip.c and Qspi_Ip_Hyperflash.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Hyperflash header file are of the same Autosar version */
#if ((QSPI_IP_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_HYPERFLASH_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_HYPERFLASH_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_HYPERFLASH_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip.c and Qspi_Ip_Hyperflash.h are different"
#endif
/* Check if current file and Qspi_Ip_Hyperflash header file are of the same Software version */
#if ((QSPI_IP_SW_MAJOR_VERSION_C != QSPI_IP_HYPERFLASH_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_SW_MINOR_VERSION_C != QSPI_IP_HYPERFLASH_SW_MINOR_VERSION_H) || \
     (QSPI_IP_SW_PATCH_VERSION_C != QSPI_IP_HYPERFLASH_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip.c and Qspi_Ip_Hyperflash.h are different"
#endif


/*******************************************************************************
 * Variables
 ******************************************************************************/
#if (QSPI_IP_MEM_INSTANCE_COUNT > 0)

/*When multicore type3 is enabled on MemAcc, global variables must be allocated to share memory section */
#if (QSPI_IP_MULTICORE_ENABLED == STD_ON)
#define MEM_43_EXFLS_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Mem_43_EXFLS_MemMap.h"

/* Pointer to runtime state structures */
VAR_SEC_NOCACHE(Qspi_Ip_MemoryStateStructure) Qspi_Ip_StateType Qspi_Ip_MemoryStateStructure[QSPI_IP_MEM_INSTANCE_COUNT];

#if (QSPI_IP_MULTICORE_ENABLED == STD_ON)
#define MEM_43_EXFLS_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Mem_43_EXFLS_MemMap.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/


/*******************************************************************************
 * Private Functions
 ******************************************************************************/

#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

static Qspi_Ip_StatusType Qspi_Ip_WriteEnable(uint32 instance);

static Qspi_Ip_StatusType Qspi_Ip_InitReset(uint32 instance,
                                            uint16 resetCmdLut,
                                            uint8 resetCmdCount,
                                            const Qspi_Ip_StateType *state
                                           );

static Qspi_Ip_StatusType Qspi_Ip_InitWriteReg(uint32 instance,
                                               const Qspi_Ip_InitOperationType *operation
                                              );

static Qspi_Ip_StatusType Qspi_Ip_InitRMWReg(uint32 instance,
                                             const Qspi_Ip_InitOperationType *operation
                                            );

static Qspi_Ip_StatusType Qspi_Ip_InitReadReg(uint32 instance,
                                              const Qspi_Ip_InitOperationType *operation
                                             );

static Qspi_Ip_StatusType Qspi_Ip_InitProtection(uint32 instance,
                                                 const Qspi_Ip_StateType *state
                                                );

static Qspi_Ip_StatusType Qspi_Ip_InitOperation(uint32 instance,
                                                const Qspi_Ip_StateType *state,
                                                uint8 initOp
                                               );

static inline uint32 Qspi_Ip_CalcPaddingRead(const Qspi_Ip_StateType *state,
                                             uint32 *address,
                                             uint32 *size
                                            );

static uint16 Qspi_Ip_InitLutSeq(uint32 instance,
                                 uint16 VirtualLut,
                                 uint8 LutRegister
                                );

static void Qspi_Ip_DeinitLutSeq(uint32 instance,
                                 uint8 LutRegister
                                );

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_InitLutSeq
 * Description   : Initializes one sequence in the LUT table from a virtual table sequence. Returns start index of next sequence.
*/
static uint16 Qspi_Ip_InitLutSeq(uint32 instance,
                                 uint16 VirtualLut,
                                 uint8 LutRegister
                                )
{
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    const Qspi_Ip_InstrOpType *virtualLutTable = state->configuration->lutSequences.lutOps;
    Qspi_Ip_InstrOpType operation1, operation2;
    uint16 vLutIdx = VirtualLut;         /* Index in virtual LUT  */
    uint8  pLutIdx = 0U;                 /* Index in physical LUT */
    uint32 lutData[FEATURE_QSPI_LUT_SEQUENCE_SIZE];  /* Data to be written to the physical LUTs */

    do
    {
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
        DEV_ASSERT_QSPI(vLutIdx < state->configuration->lutSequences.opCount);
#endif
        operation1 = virtualLutTable[vLutIdx];
        vLutIdx++;
        operation2 = QSPI_IP_LUT_SEQ_END;
        if (operation1 != QSPI_IP_LUT_SEQ_END)
        {
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
            DEV_ASSERT_QSPI(vLutIdx < state->configuration->lutSequences.opCount);
#endif
            operation2 = virtualLutTable[vLutIdx];
            vLutIdx++;
        }
        /* Add two operations to lut sequence */
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
        DEV_ASSERT_QSPI(pLutIdx < FEATURE_QSPI_LUT_SEQUENCE_SIZE);
#endif
        lutData[pLutIdx] = QSPI_IP_PACK_LUT_REG(operation1, operation2);
        pLutIdx++;
    }
    while (operation2 != QSPI_IP_LUT_SEQ_END);

#if (FEATURE_QSPI_HAS_SFP == 1)
    /* Clear the rest of sequence to avoid the effect of the previous command.
       This prevent the SFP block from identifying the wrong type of transaction.
    */
    for (; pLutIdx < FEATURE_QSPI_LUT_SEQUENCE_SIZE; pLutIdx++)
    {
        lutData[pLutIdx] = QSPI_IP_PACK_LUT_REG(QSPI_IP_LUT_SEQ_END, QSPI_IP_LUT_SEQ_END);
    }
#endif

    /* Write data to physical LUT registers */
    Qspi_Ip_WriteLuts(state->connection->qspiInstance, FEATURE_QSPI_LUT_SEQUENCE_SIZE * LutRegister, lutData, pLutIdx);

    return vLutIdx;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_DeinitLutSeq
 * Description   : DeInitializes one sequence in the LUT table from a virtual table sequence.
*/
static void Qspi_Ip_DeinitLutSeq(uint32 instance,
                                 uint8 LutRegister
                                )
{
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    const uint32 lutData[FEATURE_QSPI_LUT_SEQUENCE_SIZE] = {0U};  /* Data to be written to the physical LUTs */

    /* Write data to physical LUT registers */
    Qspi_Ip_WriteLuts(state->connection->qspiInstance, FEATURE_QSPI_LUT_SEQUENCE_SIZE * LutRegister, lutData, FEATURE_QSPI_LUT_SEQUENCE_SIZE);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SetValue
 * Description   : Converts a long value in data to be sent to flash
 */
static inline void Qspi_Ip_SetValue(uint8 *data,
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
 * Function Name : Qspi_Ip_SetBitfield
 * Description   : Sets a new value in a register bitfield
 */
static void Qspi_Ip_SetBitfield(uint8 *data,
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
 * Function Name : Qspi_Ip_GetBitfield
 * Description   : Extracts the value of a register bitfield
 */
static uint32 Qspi_Ip_GetBitfield(const uint8 *data,
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
 * Function Name : Qspi_Ip_UpdateStatusReg
 * Description   : Updates a bitfield in the status register
 *                 Qspi_Ip_UpdateStatusReg_Activity */
static Qspi_Ip_StatusType Qspi_Ip_UpdateStatusReg(uint32 instance,
                                                  uint8 offset,
                                                  uint8 width,
                                                  uint8 value
                                                 )
{
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    const Qspi_Ip_StatusConfigType *statusConfig = &(state->configuration->statusConfig);
    uint8 data[4U];
    Qspi_Ip_StatusType status;

    /* Read status register */
    status = Qspi_Ip_RunReadCommand(instance, statusConfig->statusRegReadLut, 0U, data, NULL_PTR, statusConfig->regSize);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Check existing value, write status register only if needed */
        if (value != Qspi_Ip_GetBitfield(data, statusConfig->regSize, offset, width))
        {
            Qspi_Ip_SetBitfield(data, statusConfig->regSize, offset, width, value);
        }
        /* send WREN command for status register */
        if (statusConfig->writeEnableSRLut != QSPI_IP_LUT_INVALID)
        {
            status = Qspi_Ip_RunCommand(instance, statusConfig->writeEnableSRLut, 0U);
        }
        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            /* send write status register command */
            status = Qspi_Ip_RunWriteCommand(instance, statusConfig->statusRegWriteLut, 0U, data, statusConfig->regSize);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_CheckStatusReg
 * Description   : Checks a bitfield in the status register
 *                 Qspi_Ip_CheckStatusReg_Activity */
static Qspi_Ip_StatusType Qspi_Ip_CheckStatusReg(uint32 instance,
                                                 uint8 offset,
                                                 uint8 width,
                                                 uint8 *value
                                                )
{
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    const Qspi_Ip_StatusConfigType *statusConfig = &(state->configuration->statusConfig);
    uint8 data[4];
    Qspi_Ip_StatusType status;

    /* Read status register */
    status = Qspi_Ip_RunReadCommand(instance, statusConfig->statusRegReadLut, 0U, data, NULL_PTR, statusConfig->regSize);
    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Extract bit-field */
        *value = (uint8)Qspi_Ip_GetBitfield(data, statusConfig->regSize, offset, width);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_WriteEnable
 * Description   : Enables the serial flash memory for a program or erase operation
* @implements      Qspi_Ip_WriteEnable_Activity */
static Qspi_Ip_StatusType Qspi_Ip_WriteEnable(uint32 instance)
{
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    const Qspi_Ip_StatusConfigType *statusConfig = &(state->configuration->statusConfig);

    uint32 retries = QSPI_IP_MAX_RETRY + 1U;
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_TIMEOUT;
    Qspi_Ip_StatusType cmdStatus;
    uint8 welValue = 0U;

    MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_IPCOMMAND_WAIT_IN_WREN);

    while (retries > 0UL)
    {
        /* send WREN command */
        cmdStatus = Qspi_Ip_RunCommand(instance, statusConfig->writeEnableLut, 0U);
        if (cmdStatus != STATUS_QSPI_IP_SUCCESS)
        {
            status = cmdStatus;
        }
        else
        {
            /* check WEL bit */
            cmdStatus = Qspi_Ip_CheckStatusReg(instance, statusConfig->writeEnableOffset, 1U, &welValue);
        }
        if (STATUS_QSPI_IP_SUCCESS == cmdStatus)
        {
            /* 1 == check WEL */
            if (1U == welValue)
            {
                status = STATUS_QSPI_IP_SUCCESS;
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

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SerialflashSectorErase
 * Description   : Erase a sector in the serial flash.
 */
static Qspi_Ip_StatusType Qspi_Ip_SerialflashSectorErase(uint32 instance,
                                                         uint32 address,
                                                         uint16 eraseLut
                                                        )
{
    Qspi_Ip_StatusType status;

    /* enable write before erasing */
    status = Qspi_Ip_WriteEnable(instance);

    MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_IPCOMMAND_WAIT_IN_BASICERS);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* launch erase command and return */
        status = Qspi_Ip_RunCommand(instance, eraseLut, address);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_BasicErase
 * Description   : Perform one of the supported erase types in the serial flash.
 * @implements      Qspi_Ip_BasicErase_Activity */
static Qspi_Ip_StatusType Qspi_Ip_BasicErase(uint32 instance,
                                             uint32 address,
                                             uint16 eraseLut
                                            )
{
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    Qspi_Ip_StatusType status;

    /* Check device type */
    switch (state->configuration->memType)
    {
        case QSPI_IP_HYPER_FLASH:
            status = Qspi_Ip_HyperflashSectorErase(instance, address);
            break;

        case QSPI_IP_SERIAL_FLASH:
            status = Qspi_Ip_SerialflashSectorErase(instance, address, eraseLut);
            break;
        default:
            status = STATUS_QSPI_IP_ERROR; /* unknown operation */
            break;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_CheckMemoryStatus
 * Description   : Check that the memory is idle. Used internally by the driver during initialization
 */
static Qspi_Ip_StatusType Qspi_Ip_CheckMemoryStatus(uint32 instance,
                                                    uint16 virtualLut
                                                   )
{
    Qspi_Ip_StatusType status;
    uint8 busyValue;
    uint8 data[4];
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    const Qspi_Ip_StatusConfigType *statusConfig = &(state->configuration->statusConfig);

    /* Check if the QuadSPI controller is idle */
    status = Qspi_Ip_ControllerGetStatus(state->connection->qspiInstance);
    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Check if the operation has finished in the serial flash */
        /* Read status register */
        status = Qspi_Ip_RunReadCommand(instance, virtualLut, 0U, data, NULL_PTR, statusConfig->regSize);
        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            /* Extract bit-field */
            busyValue = (uint8)Qspi_Ip_GetBitfield(data, statusConfig->regSize, statusConfig->busyOffset, 1U);
            if (busyValue == statusConfig->busyValue)
            {
                /* Flash device is busy */
                status = STATUS_QSPI_IP_BUSY;
            }
            MCAL_FAULT_INJECTION_POINT(FLS_FIP_SR_BUSY_CHECKCOMMANDCOMPLETE);
        }
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_WaitCommandComplete
 * Description   : Wait until external memory is not busy
 */
static Qspi_Ip_StatusType Qspi_Ip_WaitCommandComplete(uint32 instance,
                                                      uint16 VirtualLut
                                                     )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint32  ElapsedTicks = 0UL;
    uint32  TimeoutTicks;
    uint32  CurrentTicks;

    /* Prepare timeout counter */
    TimeoutTicks = OsIf_MicrosToTicks(QSPI_IP_FLS_INIT_TIMEOUT, QSPI_IP_TIMEOUT_TYPE);
    CurrentTicks = OsIf_GetCounter(QSPI_IP_TIMEOUT_TYPE);
    /* Wait for the command to complete */
    do
    {
        /* Get memory status */
        status = Qspi_Ip_CheckMemoryStatus(instance, VirtualLut);
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, QSPI_IP_TIMEOUT_TYPE);
        /* Check timeout */
        if (ElapsedTicks >= TimeoutTicks)
        {
            status = STATUS_QSPI_IP_TIMEOUT;
            break;
        }
    }
    while (STATUS_QSPI_IP_BUSY == status);

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_WaitResetComplete
 * Description   : Wait until external memory is available for operation after a reset
 * Qspi_Ip_WaitResetComplete_Activity */
static void Qspi_Ip_WaitResetComplete(void)
{
    uint32 ElapsedTicks = 0UL;
    uint32 TimeoutTicks;
    uint32 CurrentTicks;

    /* Prepare timeout counter */
    TimeoutTicks = OsIf_MicrosToTicks(QSPI_IP_RESET_TIMEOUT, QSPI_IP_TIMEOUT_TYPE);
    CurrentTicks = OsIf_GetCounter(QSPI_IP_TIMEOUT_TYPE);
    /* Wait for the specified time */
    do
    {
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, QSPI_IP_TIMEOUT_TYPE);
    }
    while (ElapsedTicks < TimeoutTicks);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_InitWriteReg
 * Description   : Write the configured value into a register of external flash device
 *                 Qspi_Ip_InitWriteReg_Activity */
static Qspi_Ip_StatusType Qspi_Ip_InitWriteReg(uint32 instance,
                                               const Qspi_Ip_InitOperationType * operation
                                              )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_ERROR;
    uint8 value[4U];

    /* write a value in a register */
    if (QSPI_IP_LUT_INVALID != operation->weLut)
    {
        /* send WREN command */
        status = Qspi_Ip_RunCommand(instance, operation->weLut, operation->addr);
    }
    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        Qspi_Ip_SetValue(value, operation->size, operation->value);
        status = Qspi_Ip_RunWriteCommand(instance, operation->command1Lut, operation->addr, value, operation->size);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_InitRMWReg
 * Description   : Change a bitfield in a register of external flash device
 *                 Qspi_Ip_InitRMWReg_Activity */
static Qspi_Ip_StatusType Qspi_Ip_InitRMWReg(uint32 instance,
                                             const Qspi_Ip_InitOperationType *operation
                                            )
{
    Qspi_Ip_StatusType status;
    uint32 fieldVal;
    uint8 value[4U];

    /* Read current register value */
    status = Qspi_Ip_RunReadCommand(instance, operation->command1Lut, operation->addr, value, NULL_PTR, operation->size);
    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Retrieve target bitfield */
        fieldVal = Qspi_Ip_GetBitfield(value, operation->size, operation->shift, operation->width);
        if (fieldVal != operation->value)
        {
            /* Modify target bitfield */
            Qspi_Ip_SetBitfield(value, operation->size, operation->shift, operation->width, operation->value);
            if (QSPI_IP_LUT_INVALID != operation->weLut)
            {
                /* Send WREN command */
                status = Qspi_Ip_RunCommand(instance, operation->weLut, operation->addr);
            }
            if (STATUS_QSPI_IP_SUCCESS == status)
            {
                /* Write back register value; use second LUT command */
                status = Qspi_Ip_RunWriteCommand(instance, operation->command2Lut, operation->addr, (uint8 *)&value, operation->size);
            }
        }
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_InitReadReg
 * Description   : Read the register's value of external flash device and loop until matching the configured one
 *                 Qspi_Ip_InitReadReg_Activity */
static Qspi_Ip_StatusType Qspi_Ip_InitReadReg(uint32 instance,
                                              const Qspi_Ip_InitOperationType *operation
                                             )
{
    Qspi_Ip_StatusType status;
    uint32 fieldVal = 0xFFFFFFFFUL;  /* Invalid initial value */
    uint8 value[4U];
    uint32 ElapsedTicks = 0UL;
    uint32 TimeoutTicks;
    uint32 CurrentTicks;

    /* Prepare timeout counter */
    TimeoutTicks = OsIf_MicrosToTicks(QSPI_IP_FLS_INIT_TIMEOUT, QSPI_IP_TIMEOUT_TYPE);
    CurrentTicks = OsIf_GetCounter(QSPI_IP_TIMEOUT_TYPE);
    do
    {
        /* read current register value */
        status = Qspi_Ip_RunReadCommand(instance, operation->command1Lut, operation->addr, value, NULL_PTR, operation->size);
        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            /* retrieve target bitfield */
            fieldVal = Qspi_Ip_GetBitfield(value, operation->size, operation->shift, operation->width);
        }
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, QSPI_IP_TIMEOUT_TYPE);
        if (ElapsedTicks >= TimeoutTicks)
        {
            status = STATUS_QSPI_IP_TIMEOUT;
            break;
        }
    }
    while (fieldVal != operation->value);

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_InitOperation
 * Description   : Execute initialization sequence to get the serial flash memory in the target state for operation */
static Qspi_Ip_StatusType Qspi_Ip_InitOperation(uint32 instance,
                                                const Qspi_Ip_StateType *state,
                                                uint8 initOp
                                               )
{
    const Qspi_Ip_InitOperationType *initOperations = state->configuration->initConfiguration.operations;
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;

    switch (initOperations[initOp].opType)
    {
        case QSPI_IP_OP_TYPE_CMD:
            /* Execute a simple command */
            status = Qspi_Ip_RunCommand(instance, initOperations[initOp].command1Lut, initOperations[initOp].addr);
            break;

        case QSPI_IP_OP_TYPE_WRITE_REG:
            /* Write value into the register */
            status = Qspi_Ip_InitWriteReg(instance, &initOperations[initOp]);
            break;

        case QSPI_IP_OP_TYPE_RMW_REG:
            /* Change a bitfield in the register */
            status = Qspi_Ip_InitRMWReg(instance, &initOperations[initOp]);
            break;

        case QSPI_IP_OP_TYPE_READ_REG:
            /* Check a bitfield in the register */
            status = Qspi_Ip_InitReadReg(instance, &initOperations[initOp]);
            break;

        case QSPI_IP_OP_TYPE_QSPI_CFG:
            /* Re-initialize QSPI controller with the given configuration */
            (void)Qspi_Ip_ControllerDeinit(state->connection->qspiInstance);
            status = Qspi_Ip_ControllerInit(state->connection->qspiInstance, initOperations[initOp].ctrlCfgPtr);
            break;

        default:
            status = STATUS_QSPI_IP_ERROR; /* unknown operation */
            break;
    }   /* switch */

    return status;

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_InitDevice
 * Description   : Execute initialization sequence to get the serial flash memory in the target state for operation
* @implements      Qspi_Ip_InitDevice_Activity */
static Qspi_Ip_StatusType Qspi_Ip_InitDevice(uint32 instance,
                                             const Qspi_Ip_StateType *state
                                            )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint8 initConfigOpCount = state->configuration->initConfiguration.opCount;
    uint8 initOp;

    MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_IPCOMMAND_INITDEVICE);

    /* Perform operations in initialization list (common) */
    for (initOp = 0; initOp < initConfigOpCount; initOp++)
    {
        status = Qspi_Ip_InitOperation(instance, state, initOp);

        if (STATUS_QSPI_IP_SUCCESS != status)
        {
            break;
        }
    }

    /* Perform device initialization (specific) */
    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        if (QSPI_IP_HYPER_FLASH == state->configuration->memType)
        {
            status = Qspi_Ip_HyperflashInit(instance);
        }
    }
    else
    {
       status =  STATUS_QSPI_IP_ERROR;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_InitProtection
 * Description   : Update the protection configuration value if needed
* @implements      Qspi_Ip_InitProtection_Activity */
static Qspi_Ip_StatusType Qspi_Ip_InitProtection(uint32 instance,
                                                 const Qspi_Ip_StateType *state
                                                )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint8 configProtection = state->configuration->statusConfig.blockProtectionValue;
    uint8 getProtection = 0U;

    if (state->configuration->statusConfig.blockProtectionWidth != 0U)
    {
        /* Ensure the previous command is completed */
        status = Qspi_Ip_WaitCommandComplete(instance, state->configuration->statusConfig.statusRegReadLut);
        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            /* Read and check the current setting */
            status = Qspi_Ip_GetProtection(instance, &getProtection);
            if ((STATUS_QSPI_IP_SUCCESS == status) && (getProtection != configProtection))
            {
                /* Set new setting */
                status = Qspi_Ip_SetProtection(instance, configProtection);
                if (STATUS_QSPI_IP_SUCCESS == status)
                {
                    /* Ensure the write is completed  */
                    status = Qspi_Ip_WaitCommandComplete(instance, state->configuration->statusConfig.statusRegReadLut);
                }
            }
        }
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_InitReset
 * Description   : Perform the software reset sequence
* @implements      Qspi_Ip_InitReset_Activity */
static Qspi_Ip_StatusType Qspi_Ip_InitReset(uint32 instance,
                                            uint16 resetCmdLut,
                                            uint8 resetCmdCount,
                                            const Qspi_Ip_StateType *state
                                           )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint16 virtualLut = resetCmdLut;
    uint8 cnt;

    if (QSPI_IP_LUT_INVALID != resetCmdLut)
    {
        for (cnt = 0U; cnt < resetCmdCount; cnt++)
        {
            /* Copy sequence in LUT registers */
            virtualLut = Qspi_Ip_InitLutSeq(instance, virtualLut, QSPI_IP_COMMAND_LUT);

            /* Run QSPI command */
            status = Qspi_Ip_IpCommand(state->connection->qspiInstance, QSPI_IP_COMMAND_LUT, state->baseAddress);
            if (status != STATUS_QSPI_IP_SUCCESS)
            {
                break;
            }

            /* Clear sequence in LUT registers */
            Qspi_Ip_DeinitLutSeq(instance, QSPI_IP_COMMAND_LUT);
        }
        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            /* Ensure flash is ready after reset */
            Qspi_Ip_WaitResetComplete();
        }
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SerialflashEraseChip
 * Description   : Erase the entire serial flash
 */
static Qspi_Ip_StatusType Qspi_Ip_SerialflashEraseChip(uint32 instance)
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_ERROR;
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);

    if (state->configuration->eraseSettings.chipEraseLut != QSPI_IP_LUT_INVALID)
    {
        /* enable write before erasing */
        status = Qspi_Ip_WriteEnable(instance);
        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            /* launch erase command */
            status = Qspi_Ip_RunCommand(instance, state->configuration->eraseSettings.chipEraseLut, 0U);
        }
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SerialflashGetMemoryStatus
 * Description   : Get the status of the last operation
 */
static Qspi_Ip_StatusType Qspi_Ip_SerialflashGetMemoryStatus(uint32 instance)
{
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    const Qspi_Ip_StatusConfigType *statusConfig = &(state->configuration->statusConfig);
    uint8 busyValue = 0xFFU;  /* Invalid initial value */
    Qspi_Ip_StatusType status;

    /* Get the value of busy bit */
    status = Qspi_Ip_CheckStatusReg(instance, statusConfig->busyOffset, 1U, &busyValue);
    /* Check BUSY value */
    if (busyValue == statusConfig->busyValue)
    {
        /* Write/erase in progress */
        status = STATUS_QSPI_IP_BUSY;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_PatchReadCommand
 * Description   : Patch the command sequence before using
 */
static void Qspi_Ip_PatchReadCommand(uint32 instance,
                                     uint16 readLut
                                    )
{
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);

    /* Check device type */
    switch (state->configuration->memType)
    {
        case QSPI_IP_HYPER_FLASH:
            Qspi_Ip_HyperflashPatchReadCommand(instance, readLut);
            break;

        case QSPI_IP_SERIAL_FLASH:
            /* Nothing to do with Serial flash */
            (void)readLut;
            break;

        default:
            (void)readLut; /* unknown operation */
            break;
    }
}


/*******************************************************************************
 * Code
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_RunCommand
 * Description   : Launches a simple command for the serial flash
* @implements      Qspi_Ip_RunCommand_Activity */
Qspi_Ip_StatusType Qspi_Ip_RunCommand(uint32 instance,
                                      uint16 lut,
                                      uint32 addr
                                     )
{
    /* Start of exclusive area */
    SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_04();

    Qspi_Ip_StatusType status = STATUS_QSPI_IP_ERROR;
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_QSPI(lut != QSPI_IP_LUT_INVALID);
    DEV_ASSERT_QSPI(addr < state->configuration->memSize);
#endif

    if ((lut != QSPI_IP_LUT_INVALID) && (TRUE != state->isInXIPMode))
    {
        /* Copy sequence in LUT registers */
        (void)Qspi_Ip_InitLutSeq(instance, lut, QSPI_IP_COMMAND_LUT);

        /* Run QSPI command */
        status = Qspi_Ip_IpCommand(state->connection->qspiInstance, QSPI_IP_COMMAND_LUT, state->baseAddress + addr);

        /* Clear sequence in LUT registers */
        Qspi_Ip_DeinitLutSeq(instance, QSPI_IP_COMMAND_LUT);
    }

    /* End of exclusive area */
    SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_04();

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_RunReadCommand
 * Description   : Launches a read command for the serial flash
* @implements      Qspi_Ip_RunReadCommand_Activity */
Qspi_Ip_StatusType Qspi_Ip_RunReadCommand(uint32 instance,
                                          uint16 lut,
                                          uint32 addr,
                                          uint8 * dataRead,
                                          const uint8 * dataCmp,
                                          uint32 size
                                         )
{
    /* Start of exclusive area */
    SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_05();

    Qspi_Ip_StatusType status = STATUS_QSPI_IP_ERROR;
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_QSPI(lut != QSPI_IP_LUT_INVALID);
    DEV_ASSERT_QSPI(addr < state->configuration->memSize);
    DEV_ASSERT_QSPI((size > 0UL) && ((addr + size) <= state->configuration->memSize));
#endif

    if (((lut != QSPI_IP_LUT_INVALID) && (TRUE != state->isInXIPMode)) || (lut == state->activeReadLut))
    {
        /* Copy sequence in LUT registers */
        (void)Qspi_Ip_InitLutSeq(instance, lut, QSPI_IP_COMMAND_LUT);

        /* Run QSPI command */
        status = Qspi_Ip_IpRead(state->connection->qspiInstance, QSPI_IP_COMMAND_LUT, state->baseAddress + addr, dataRead, dataCmp, size);

        /* Clear sequence in LUT registers */
        Qspi_Ip_DeinitLutSeq(instance, QSPI_IP_COMMAND_LUT);
    }

    /* End of exclusive area */
    SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_05();

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_RunWriteCommand
 * Description   : Launches a write command for the serial flash
 * @implements     Qspi_Ip_RunWriteCommand_Activity */
Qspi_Ip_StatusType Qspi_Ip_RunWriteCommand(uint32 instance,
                                           uint16 lut,
                                           uint32 addr,
                                           const uint8 * data,
                                           uint32 size
                                          )
{
    /* Start of exclusive area */
    SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_06();

    Qspi_Ip_StatusType status = STATUS_QSPI_IP_ERROR;
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_QSPI(lut != QSPI_IP_LUT_INVALID);
    DEV_ASSERT_QSPI(addr < state->configuration->memSize);
    DEV_ASSERT_QSPI((size > 0UL) && ((addr + size) <= state->configuration->memSize));
    DEV_ASSERT_QSPI(data != NULL_PTR);
#endif

    if ((lut != QSPI_IP_LUT_INVALID) && (TRUE != state->isInXIPMode))
    {
        /* Copy sequence in LUT registers */
        (void)Qspi_Ip_InitLutSeq(instance, lut, QSPI_IP_COMMAND_LUT);

        /* Run QSPI command */
        status = Qspi_Ip_IpWrite(state->connection->qspiInstance, QSPI_IP_COMMAND_LUT, state->baseAddress + addr, data, size);

        /* Clear sequence in LUT registers */
        Qspi_Ip_DeinitLutSeq(instance, QSPI_IP_COMMAND_LUT);
    }

    /* End of exclusive area */
    SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_06();

    return status;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_EraseBlock
 * Description   : Erase a sector in the serial flash.
 *                 The size must match one of the device's erase types.
 * @implements     Qspi_Ip_EraseBlock_Activity */
Qspi_Ip_StatusType Qspi_Ip_EraseBlock(uint32 instance,
                                      uint32 address,
                                      uint32 size
                                     )
{
    Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_ERROR;
    uint8 eraseType;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_QSPI(address < state->configuration->memSize);
    DEV_ASSERT_QSPI((size > 0UL) && ((address + size) <= state->configuration->memSize));
#endif

    /* Check address range */
    if ((address < state->configuration->memSize) && (TRUE != state->isInXIPMode))
    {
        /* find the suited erase type */
        for (eraseType = 0U; eraseType < QSPI_IP_ERASE_TYPES; eraseType++)
        {
            if ((state->configuration->eraseSettings.eraseTypes[eraseType].eraseLut != QSPI_IP_LUT_INVALID) &&
                (size == (uint32)((uint32)1U << (state->configuration->eraseSettings.eraseTypes[eraseType].size))))
            {
                break;
            }
        }
        /* if erase type was found, launch the erase */
        if (eraseType < QSPI_IP_ERASE_TYPES)
        {
            status = Qspi_Ip_BasicErase(instance, address, state->configuration->eraseSettings.eraseTypes[eraseType].eraseLut);
            if (STATUS_QSPI_IP_SUCCESS == status)
            {
                state->lastCommand = QSPI_IP_LAST_COMMAND_ERASE;
            }
        }
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_EraseChip
 * Description   : Erase the entire serial flash
 * @implements     Qspi_Ip_EraseChip_Activity */
Qspi_Ip_StatusType Qspi_Ip_EraseChip(uint32 instance)
{
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
#endif

    Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    Qspi_Ip_StatusType status;

    if (TRUE != state->isInXIPMode)
    {
        /* Check device type */
        switch (state->configuration->memType)
        {
            case QSPI_IP_HYPER_FLASH:
                status = Qspi_Ip_HyperflashChipErase(instance);
                break;

            case QSPI_IP_SERIAL_FLASH:
                status = Qspi_Ip_SerialflashEraseChip(instance);
                break;

            default:
                status = STATUS_QSPI_IP_ERROR; /* unknown operation */
                break;
        }

        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            state->lastCommand = QSPI_IP_LAST_COMMAND_ERASE;
        }
    }
    else
    {
        status = STATUS_QSPI_IP_ERROR;
    }


    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ProgramSuspend
 * Description   : Suspends a program operation
 * @implements     Qspi_Ip_ProgramSuspend_Activity */
Qspi_Ip_StatusType Qspi_Ip_ProgramSuspend(uint32 instance)
{
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
#endif

    Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    Qspi_Ip_StatusType status;

    /* Issue the Program Suspend command */
    status = Qspi_Ip_RunCommand(instance, state->configuration->suspendSettings.programSuspendLut, 0U);
    state->lastCommand = QSPI_IP_LAST_COMMAND_WRITE_SUSPEND;

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ProgramResume
 * Description   : Resumes a program operation
 * @implements     Qspi_Ip_ProgramResume_Activity */
Qspi_Ip_StatusType Qspi_Ip_ProgramResume(uint32 instance)
{
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
#endif

    Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    Qspi_Ip_StatusType status;

    /* Issue the Program Resume command */
    status = Qspi_Ip_RunCommand(instance, state->configuration->suspendSettings.programResumeLut, 0U);
    state->lastCommand = QSPI_IP_LAST_COMMAND_WRITE;

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_EraseSuspend
 * Description   : Suspends an erase operation
 * @implements     Qspi_Ip_EraseSuspend_Activity */
Qspi_Ip_StatusType Qspi_Ip_EraseSuspend(uint32 instance)
{
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
#endif

    Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    Qspi_Ip_StatusType status;

    /* Issue the Erase Suspend command */
    status = Qspi_Ip_RunCommand(instance, state->configuration->suspendSettings.eraseSuspendLut, 0U);
    state->lastCommand = QSPI_IP_LAST_COMMAND_ERASE_SUSPEND;

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_EraseResume
 * Description   : Resumes an erase operation
 * @implements     Qspi_Ip_EraseResume_Activity */
Qspi_Ip_StatusType Qspi_Ip_EraseResume(uint32 instance)
{
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
#endif

    Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    Qspi_Ip_StatusType status;

    /* Issue the Erase Resume command */
    status = Qspi_Ip_RunCommand(instance, state->configuration->suspendSettings.eraseResumeLut, 0U);
    state->lastCommand = QSPI_IP_LAST_COMMAND_ERASE;

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_Reset
 * Description   : Issues a software reset command
 * @implements     Qspi_Ip_Reset_Activity */
Qspi_Ip_StatusType Qspi_Ip_Reset(uint32 instance)
{
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
#endif

    Qspi_Ip_StatusType status = STATUS_QSPI_IP_ERROR;
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    uint16 resetCmdLut;        /*!< First command in reset sequence            */
    uint8 resetCmdCount;       /*!< Number of commands in reset sequence       */

    resetCmdLut = state->configuration->resetSettings.resetCmdLut;
    if ((QSPI_IP_LUT_INVALID != resetCmdLut) && (TRUE != state->isInXIPMode))
    {
        resetCmdCount = state->configuration->resetSettings.resetCmdCount;
        /* Start of exclusive area */
        SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_08();
        /* Perform reset */
        status = Qspi_Ip_InitReset(instance, resetCmdLut, resetCmdCount, state);
        /* End of exclusive area */
        SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_08();
        /* Bring corresponding controller to initial configuration if required */
        if ((STATUS_QSPI_IP_SUCCESS == status) && (state->configuration->ctrlAutoCfgPtr != NULL_PTR))
        {
            status = Qspi_Ip_ControllerInit(state->connection->qspiInstance, state->configuration->ctrlAutoCfgPtr);
        }
        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            /* Execute initial setup of external device */
            status = Qspi_Ip_InitDevice(instance, state);
        }
    }

    /* If enabled, call the reset callout. */
    if ((NULL_PTR != state->configuration->resetCallout) && (TRUE != state->isInXIPMode))
    {
        status = state->configuration->resetCallout(instance);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_GetMemoryStatus
 * Description   : Get the status of the last operation
 * @implements     Qspi_Ip_GetMemoryStatus_Activity */
Qspi_Ip_StatusType Qspi_Ip_GetMemoryStatus(uint32 instance)
{
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
#endif

    Qspi_Ip_StatusType status;
    Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);

    if (TRUE != state->isInXIPMode)
    {
        /* Check if the QuadSPI command is complete */
        status = Qspi_Ip_ControllerGetStatus(state->connection->qspiInstance);

        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            /* Check device type */
            switch (state->configuration->memType)
            {
                case QSPI_IP_HYPER_FLASH:
                    /* Check if the operation has finished in the hyper flash */
                    status = Qspi_Ip_HyperflashGetMemoryStatus(instance);
                    break;

                case QSPI_IP_SERIAL_FLASH:
                    /* Check if the operation has finished in the serial flash */
                    status = Qspi_Ip_SerialflashGetMemoryStatus(instance);
                    break;
                default:
                    status = STATUS_QSPI_IP_ERROR; /* unknown operation */
                    break;
            }
        }

        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            /* Call user callout, if available, to check operation result */
            if ((state->lastCommand != QSPI_IP_LAST_COMMAND_NONE) && (NULL_PTR != state->configuration->errorCheckCallout))
            {
                status = state->configuration->errorCheckCallout(instance);
            }
            state->lastCommand = QSPI_IP_LAST_COMMAND_NONE;
        }
    }
    else
    {
        status = STATUS_QSPI_IP_ERROR;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_CalcPaddingRead
 * Description   : Calculates the number of padding bytes to handle reading from unaligned addresses
 */
static inline uint32 Qspi_Ip_CalcPaddingRead(const Qspi_Ip_StateType *state,
                                             uint32 *address,
                                             uint32 *size
                                            )
{
    const uint32 qspiInstance  = state->connection->qspiInstance;
    const uint32 readAlignment = state->connection->memAlignment;

    /* Checking for unaligned addresses */
    uint32 offset = *address & (readAlignment - 1U);
    if (offset != 0U)
    {
        /* The number of padding bytes to handle unaligned address */
        Qspi_Ip_MemoryPadding[qspiInstance] = (uint8)offset;
        /* Decreasing the address */
        *address -= offset;
        /* Increasing the size to compensate */
        *size += offset;
    }

    return offset;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_Read
 * Description   : Read data from serial flash
 * @implements     Qspi_Ip_Read_Activity */
Qspi_Ip_StatusType Qspi_Ip_Read(uint32 instance,
                                uint32 address,
                                uint8 * data,
                                uint32 size
                               )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    uint32 crtAddress = address;
    uint8 * crtData = data;
    uint32 crtSize = size;
    uint32 chunkSize = QSPI_IP_MAX_READ_SIZE;
    uint32 offset;
    uint32 ElapsedTicks = 0UL;
    uint32 TimeoutTicks;
    uint32 CurrentTicks;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(crtAddress < state->configuration->memSize);
    DEV_ASSERT_QSPI((crtSize > 0UL) && ((crtAddress + crtSize) <= state->configuration->memSize));
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_QSPI(data != NULL_PTR);
#endif

    /* Checks and handles unaligned addresses */
    offset = Qspi_Ip_CalcPaddingRead(state, &crtAddress, &crtSize);

    /* Prepare timeout counter */
    TimeoutTicks = OsIf_MicrosToTicks(QSPI_IP_READ_TIMEOUT, QSPI_IP_TIMEOUT_TYPE);
    CurrentTicks = OsIf_GetCounter(QSPI_IP_TIMEOUT_TYPE);
    while ((crtSize > 0UL) && (STATUS_QSPI_IP_SUCCESS == status))
    {
        if (chunkSize > crtSize)
        {
            /* Adjust size for last chunk */
            chunkSize = crtSize;
        }
        /* Check timeout */
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, QSPI_IP_TIMEOUT_TYPE);
        if (ElapsedTicks >= TimeoutTicks)
        {
            status = STATUS_QSPI_IP_TIMEOUT;
            break;
        }

        /* Patch the command sequence before using */
        Qspi_Ip_PatchReadCommand(instance, state->activeReadLut);
        status = Qspi_Ip_RunReadCommand(instance, state->activeReadLut, crtAddress, crtData, NULL_PTR, chunkSize);
        /* Move to next chunk */
        crtSize    -= chunkSize;
        crtAddress += chunkSize;
        crtData     = &(crtData[chunkSize - offset]);  /* Handle alignment for the first read */
        offset      = 0U;

        /* Call user callout, if available, to check ECC or CRC status */
        if ((STATUS_QSPI_IP_SUCCESS == status) && (NULL_PTR != state->configuration->eccCheckCallout))
        {
            status = state->configuration->eccCheckCallout(instance, crtAddress, chunkSize);
        }
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ReadId
 * Description   : Read manufacturer ID from serial flash
 * @implements     Qspi_Ip_ReadId_Activity */
Qspi_Ip_StatusType Qspi_Ip_ReadId(uint32 instance,
                                  uint8 * data
                                 )
{
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_QSPI(data != NULL_PTR);
#endif

    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    Qspi_Ip_StatusType status;

    if (TRUE != state->isInXIPMode)
    {
        /* Check device type */
        switch (state->configuration->memType)
        {
            case QSPI_IP_HYPER_FLASH:
                status = Qspi_Ip_HyperflashReadId(instance,
                                                state->configuration->hfConfig->deviceIdWordAddress,
                                                data,
                                                state->configuration->readIdSettings.readIdSize);
                break;

            case QSPI_IP_SERIAL_FLASH:
                status = Qspi_Ip_RunReadCommand(instance,
                                                state->configuration->readIdSettings.readIdLut,
                                                0U,
                                                data,
                                                NULL_PTR,
                                                state->configuration->readIdSettings.readIdSize);
                break;
            default:
                status = STATUS_QSPI_IP_ERROR; /* unknown operation */
                break;
        }
    }
    else
    {
        status = STATUS_QSPI_IP_ERROR;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ProgramVerify
 * Description   : Verifies data written in serial flash
 * @implements     Qspi_Ip_ProgramVerify_Activity */
Qspi_Ip_StatusType Qspi_Ip_ProgramVerify(uint32 instance,
                                         uint32 address,
                                         const uint8 * data,
                                         uint32 size
                                        )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    uint32 crtAddress = address;
    const uint8 * crtData = data;
    uint32 crtSize = size;
    uint32 chunkSize = QSPI_IP_MAX_READ_SIZE;
    uint32 offset;
    uint32 ElapsedTicks = 0UL;
    uint32 TimeoutTicks;
    uint32 CurrentTicks;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(crtAddress < state->configuration->memSize);
    DEV_ASSERT_QSPI((crtSize > 0UL) && ((crtAddress + crtSize) <= state->configuration->memSize));
    DEV_ASSERT_QSPI(data != NULL_PTR);
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
#endif

    /* Checks and handles unaligned addresses */
    offset = Qspi_Ip_CalcPaddingRead(state, &crtAddress, &crtSize);

    /* Prepare timeout counter */
    TimeoutTicks = OsIf_MicrosToTicks(QSPI_IP_READ_TIMEOUT, QSPI_IP_TIMEOUT_TYPE);
    CurrentTicks = OsIf_GetCounter(QSPI_IP_TIMEOUT_TYPE);
    while ((crtSize > 0U) && (STATUS_QSPI_IP_SUCCESS == status))
    {
        if (chunkSize > crtSize)
        {
            /* Adjust size for last chunk */
            chunkSize = crtSize;
        }
        /* Check timeout */
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, QSPI_IP_TIMEOUT_TYPE);
        if (ElapsedTicks >= TimeoutTicks)
        {
            status = STATUS_QSPI_IP_TIMEOUT;
            break;
        }

        /* Patch the command sequence before using */
        Qspi_Ip_PatchReadCommand(instance, state->activeReadLut);
        status = Qspi_Ip_RunReadCommand(instance, state->activeReadLut, crtAddress, NULL_PTR, crtData, chunkSize);
        /* Move to next chunk */
        crtSize    -= chunkSize;
        crtAddress += chunkSize;
        crtData     = &(crtData[chunkSize - offset]);  /* Handle alignment for the first read */
        offset      = 0U;
    }
    return status;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_EraseVerify
 * Description   : Verifies that an area in serial flash is in erased state
 * @implements     Qspi_Ip_EraseVerify_Activity */
Qspi_Ip_StatusType Qspi_Ip_EraseVerify(uint32 instance,
                                       uint32 address,
                                       uint32 size
                                      )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    uint32 crtAddress = address;
    uint32 crtSize = size;
    uint32 chunkSize = QSPI_IP_MAX_READ_SIZE;
    uint32  ElapsedTicks = 0UL;
    uint32  TimeoutTicks;
    uint32  CurrentTicks;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(crtAddress < state->configuration->memSize);
    DEV_ASSERT_QSPI((crtSize > 0UL) && ((crtAddress + crtSize) <= state->configuration->memSize));
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
#endif

    /* Checks and handles unaligned addresses */
    (void)Qspi_Ip_CalcPaddingRead(state, &crtAddress, &crtSize);

    /* Prepare timeout counter */
    TimeoutTicks = OsIf_MicrosToTicks(QSPI_IP_READ_TIMEOUT, QSPI_IP_TIMEOUT_TYPE);
    CurrentTicks = OsIf_GetCounter(QSPI_IP_TIMEOUT_TYPE);
    while ((crtSize > 0UL) && (STATUS_QSPI_IP_SUCCESS == status))
    {
        if (chunkSize > crtSize)
        {
            /* Adjust size for last chunk */
            chunkSize = crtSize;
        }
        /* Check timeout */
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, QSPI_IP_TIMEOUT_TYPE);
        if (ElapsedTicks >= TimeoutTicks)
        {
            status = STATUS_QSPI_IP_TIMEOUT;
            break;
        }

        /* Patch the command sequence before issuing */
        Qspi_Ip_PatchReadCommand(instance, state->activeReadLut);
        status = Qspi_Ip_RunReadCommand(instance, state->activeReadLut, crtAddress, NULL_PTR, NULL_PTR, chunkSize);
        /* Move to next chunk */
        crtSize    -= chunkSize;
        crtAddress += chunkSize;
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_CalcPaddingWrite
 * Description   : Calculates the number of padding bytes to handle writing to unaligned addresses
 */
static inline uint32 Qspi_Ip_CalcPaddingWrite(const Qspi_Ip_StateType *state,
                                              uint32 address,
                                              uint32 size
                                             )
{
    uint32 qspiInstance  = state->connection->qspiInstance;
    uint32 alignmentMask = (uint32)(state->connection->memAlignment) - 1UL;

    /* The number of pre-padding bytes */
    uint32 prePadding    = address & alignmentMask;

    /* The number of post-padding bytes */
    uint32 endAddr       = address + size - 1UL;
    uint32 postPadding   = alignmentMask - (endAddr & alignmentMask);

    /* Store padding information */
    Qspi_Ip_MemoryPadding[qspiInstance] = (uint8)((prePadding << 4UL) | postPadding);

    /* Decreasing the address */
    return (address - prePadding);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_Program
 * Description   : Writes data in serial flash
 * @implements     Qspi_Ip_Program_Activity */
Qspi_Ip_StatusType Qspi_Ip_Program(uint32 instance,
                                   uint32 address,
                                   const uint8 * data,
                                   uint32 size
                                  )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_ERROR;
    Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    uint32 alignedAddress;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_QSPI(address < state->configuration->memSize);
    DEV_ASSERT_QSPI(data != NULL_PTR);
    DEV_ASSERT_QSPI((size > 0UL) && ((address + size) <= state->configuration->memSize));
#endif

    /* Check address range and page size */
    if ((address < state->configuration->memSize) && ((size <= state->configuration->pageSize)) && (TRUE != state->isInXIPMode))
    {
        /* Write data to the flash device */
        switch (state->configuration->memType)
        {
            case QSPI_IP_HYPER_FLASH:
                /* Perform alignment checking before write data */
                alignedAddress = Qspi_Ip_CalcPaddingWrite(state, address, size);
                /* Write data to hyper flash */
                status = Qspi_Ip_HyperflashProgram(instance, alignedAddress, data, size);
                break;

            case QSPI_IP_SERIAL_FLASH:
                /* enable write before programming */
                status = Qspi_Ip_WriteEnable(instance);
                if (STATUS_QSPI_IP_SUCCESS == status)
                {
                    /* Perform alignment checking before write data */
                    alignedAddress = Qspi_Ip_CalcPaddingWrite(state, address, size);
                    /* Write data to serial flash */
                    status = Qspi_Ip_RunWriteCommand(instance, state->configuration->writeLut, alignedAddress, data, size);
                }
                break;
            default:
                status = STATUS_QSPI_IP_ERROR;
                break;
        }

        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            state->lastCommand = QSPI_IP_LAST_COMMAND_WRITE;
        }
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_Enter0XX
 * Description   : Enters 0-X-X mode (no command for read instructions)
 * @implements     Qspi_Ip_Enter0XX_Activity */
Qspi_Ip_StatusType Qspi_Ip_Enter0XX(uint32 instance)
{
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
#endif

    Qspi_Ip_StatusType status = STATUS_QSPI_IP_ERROR;
    Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    uint8 dummyData;

    if (state->configuration->read0xxLut != QSPI_IP_LUT_INVALID)
    {
        state->activeReadLut = state->configuration->read0xxLut;
        /* Perform a dummy read to activate 0-X-X mode */
        status = Qspi_Ip_RunReadCommand(instance, state->activeReadLut, 0U, &dummyData, NULL_PTR, 1U);
    }

    if (state->configuration->read0xxLutAHB != QSPI_IP_LUT_INVALID)
    {
        /* Set 0-x-x mode LUT sequence for AHB */
        (void)Qspi_Ip_InitLutSeq(instance, state->configuration->read0xxLutAHB, QSPI_IP_AHB_LUT);
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* XIP mode is enabled */
        state->isInXIPMode = TRUE;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_Exit0XX
 * Description   : Exits 0-X-X mode (no command for read instructions)
 * @implements     Qspi_Ip_Exit0XX_Activity */
Qspi_Ip_StatusType Qspi_Ip_Exit0XX(uint32 instance)
{
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
#endif

    Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_ERROR;
    uint8 dummyData;

    if (state->configuration->read0xxLut != QSPI_IP_LUT_INVALID)
    {
        state->activeReadLut = state->configuration->readLut;
        /* Perform a dummy read to disable 0-X-X mode */
        status = Qspi_Ip_RunReadCommand(instance, state->activeReadLut, 0U, &dummyData, NULL_PTR, 1U);
    }

    if (state->configuration->read0xxLutAHB != QSPI_IP_LUT_INVALID)
    {
        /* Set back to normal mode LUT sequence for AHB */
        (void)Qspi_Ip_InitLutSeq(instance, state->configuration->readLut, QSPI_IP_AHB_LUT);
    }

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* XIP mode is disabled */
        state->isInXIPMode = FALSE;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SetProtection
 * Description   : Sets the protection bits of the device
 * @implements     Qspi_Ip_SetProtection_Activity */
Qspi_Ip_StatusType Qspi_Ip_SetProtection(uint32 instance,
                                         uint8 value
                                        )
{
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
#endif

    Qspi_Ip_StatusType status;
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    const Qspi_Ip_StatusConfigType *statusConfig = &(state->configuration->statusConfig);

    if (TRUE != state->isInXIPMode)
    {
        status = Qspi_Ip_UpdateStatusReg(instance, statusConfig->blockProtectionOffset, statusConfig->blockProtectionWidth, value);
    }
    else
    {
        status = STATUS_QSPI_IP_ERROR;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_GetProtection
 * Description   : Returns the current protection bits of the device
 * @implements     Qspi_Ip_GetProtection_Activity */
Qspi_Ip_StatusType Qspi_Ip_GetProtection(uint32 instance,
                                         uint8 *value
                                        )
{
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_QSPI(value != NULL_PTR);
#endif

    Qspi_Ip_StatusType status;
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    const Qspi_Ip_StatusConfigType *statusConfig = &(state->configuration->statusConfig);

    if (TRUE != state->isInXIPMode)
    {
        status = Qspi_Ip_CheckStatusReg(instance, statusConfig->blockProtectionOffset, statusConfig->blockProtectionWidth, value);
    }
    else
    {
        status = STATUS_QSPI_IP_ERROR;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_AhbReadEnable
 * Description   : Enables AHB reads for the current flash device
 * @implements     Qspi_Ip_AhbReadEnable_Activity */
Qspi_Ip_StatusType Qspi_Ip_AhbReadEnable(uint32 instance)
{
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
#endif

    Qspi_Ip_StatusType status = STATUS_QSPI_IP_ERROR;
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);

    if ((state->activeReadLut != QSPI_IP_LUT_INVALID) && (TRUE != state->isInXIPMode))
    {
        /* Patch the command sequence before using */
        Qspi_Ip_PatchReadCommand(instance, state->activeReadLut);
        /* Copy sequence in LUT registers */
        (void)Qspi_Ip_InitLutSeq(instance, state->activeReadLut, QSPI_IP_AHB_LUT);
        /* Set sequence number */
        Qspi_Ip_SetAhbSeqId(state->connection->qspiInstance, QSPI_IP_AHB_LUT);
        status = STATUS_QSPI_IP_SUCCESS;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_Init
 * Description   : Initialize the serial flash memory driver
 *
 * @implements     Qspi_Ip_Init_Activity */
Qspi_Ip_StatusType Qspi_Ip_Init(uint32 instance,
                                const Qspi_Ip_MemoryConfigType * pConfig,
                                const Qspi_Ip_MemoryConnectionType * pConnect
                               )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QSPI_IP_MEM_INSTANCE_COUNT);
    DEV_ASSERT_QSPI(pConfig != NULL_PTR);
    DEV_ASSERT_QSPI(pConnect != NULL_PTR);
    DEV_ASSERT_QSPI(NULL_PTR == state->configuration);
#endif

#if (QSPI_IP_CHECK_CFG_CRC == STD_ON)
#if (QSPI_IP_USE_SFDP_CFG == STD_OFF)
    status = Qspi_Ip_ValidateMemConfigCRC(pConfig, pConnect);
    if (STATUS_QSPI_IP_SUCCESS == status)
#endif
#endif
    {
        /* Copy configuration information to state structure */
        state->configuration = pConfig;
        state->connection = pConnect;
        state->activeReadLut = pConfig->readLut;    /* 0-X-X mode disabled by default */
        state->lastCommand = QSPI_IP_LAST_COMMAND_NONE;
        state->isInXIPMode = FALSE;
        state->baseAddress = Qspi_Ip_GetBaseAdress(pConnect->qspiInstance, pConnect->connectionType);

#if (QSPI_IP_PERFORM_DEVICE_CONFIG == STD_ON)
        /* Initialize corresponding controller if required */
        if (pConfig->ctrlAutoCfgPtr != NULL_PTR)
        {
            status = Qspi_Ip_ControllerInit(pConnect->qspiInstance, pConfig->ctrlAutoCfgPtr);
        }
        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            /* Perform initial reset */
            status = Qspi_Ip_InitReset(instance, pConfig->initResetSettings.resetCmdLut, pConfig->initResetSettings.resetCmdCount, state);
        }
        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            /* Execute initial setup of external device */
            status = Qspi_Ip_InitDevice(instance, state);
        }

        /* If enabled, call the init callout, for additional QSPI IP or external memory settings. */
        if ((STATUS_QSPI_IP_SUCCESS == status) && (NULL_PTR != pConfig->initCallout))
        {
            status = pConfig->initCallout(instance);
        }

        /* Perform protection configuration */
        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            status = Qspi_Ip_InitProtection(instance, state);
        }
#endif
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_Deinit
 * Description   : De-initialize the serial flash memory driver
 * @implements     Qspi_Ip_Deinit_Activity */
Qspi_Ip_StatusType Qspi_Ip_Deinit(uint32 instance)
{
    Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QuadSPI_INSTANCE_COUNT);
    DEV_ASSERT_QSPI(state->configuration != NULL_PTR);
#endif

    state->configuration = NULL_PTR;
    state->connection = NULL_PTR;
    state->activeReadLut = QSPI_IP_LUT_INVALID;
    return STATUS_QSPI_IP_SUCCESS;
}

#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

#endif /* (QSPI_IP_MEM_INSTANCE_COUNT > 0) */


#ifdef __cplusplus
}
#endif

/** @} */

