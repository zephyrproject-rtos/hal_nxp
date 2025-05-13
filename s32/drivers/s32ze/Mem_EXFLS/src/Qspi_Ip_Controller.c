/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file Qspi_Ip_Controller.c
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
#include "Qspi_Ip.h"
#include "Qspi_Ip_Controller.h"
#include "Qspi_Ip_HwAccess.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_CONTROLLER_VENDOR_ID_C                       43
#define QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C        4
#define QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C        7
#define QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_C     0
#define QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_C                2
#define QSPI_IP_CONTROLLER_SW_MINOR_VERSION_C                0
#define QSPI_IP_CONTROLLER_SW_PATCH_VERSION_C                1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Qspi_Ip_Controller.c and Mcal.h are different"
    #endif

    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Qspi_Ip_Controller.c and OsIf.h are different"
    #endif
#endif

/* Check if current file and Qspi_Ip_Controller header file are of the same vendor */
#if (QSPI_IP_CONTROLLER_VENDOR_ID_C != QSPI_IP_CONTROLLER_VENDOR_ID_H)
    #error "Qspi_Ip_Controller.c and Qspi_Ip_Controller.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Controller header file are of the same Autosar version */
#if ((QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Controller.c and Qspi_Ip_Controller.h are different"
#endif
/* Check if current file and Qspi_Ip_Controller header file are of the same Software version */
#if ((QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_C != QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_SW_MINOR_VERSION_C != QSPI_IP_CONTROLLER_SW_MINOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_SW_PATCH_VERSION_C != QSPI_IP_CONTROLLER_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Controller.c and Qspi_Ip_Controller.h are different"
#endif

/* Check if current file and Qspi_Ip_HwAccess header file are of the same vendor */
#if (QSPI_IP_CONTROLLER_VENDOR_ID_C != QSPI_IP_HW_ACCESS_VENDOR_ID_H)
    #error "Qspi_Ip_Controller.c and Qspi_Ip_HwAccess.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_HwAccess header file are of the same Autosar version */
#if ((QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Controller.c and Qspi_Ip_HwAccess.h are different"
#endif
/* Check if current file and Qspi_Ip_HwAccess header file are of the same Software version */
#if ((QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_C != QSPI_IP_HW_ACCESS_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_SW_MINOR_VERSION_C != QSPI_IP_HW_ACCESS_SW_MINOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_SW_PATCH_VERSION_C != QSPI_IP_HW_ACCESS_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Controller.c and Qspi_Ip_HwAccess.h are different"
#endif

/* Check if current file and Qspi_Ip header file are of the same vendor */
#if (QSPI_IP_CONTROLLER_VENDOR_ID_C != QSPI_IP_VENDOR_ID_H)
    #error "Qspi_Ip_Controller.c and Qspi_Ip.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip header file are of the same Autosar version */
#if ((QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Controller.c and Qspi_Ip.h are different"
#endif
/* Check if current file and Qspi_Ip header file are of the same Software version */
#if ((QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_C != QSPI_IP_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_SW_MINOR_VERSION_C != QSPI_IP_SW_MINOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_SW_PATCH_VERSION_C != QSPI_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Controller.c and Qspi_Ip.h are different"
#endif

#if (QSPI_IP_MEM_INSTANCE_COUNT > 0)

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#if (FEATURE_QSPI_HAS_SFP == 1)

#if (QSPI_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)

#define Qspi_Ip_Sfp_Configure(baseAddr, userConfigPtr)    OsIf_Trusted_Call2params(Qspi_Ip_Sfp_Configure_Privileged, baseAddr, userConfigPtr)
#define Qspi_Ip_ResetPrivilegedRegisters(baseAddr)        OsIf_Trusted_Call1param(Qspi_Ip_ResetPrivilegedRegisters_Privileged, baseAddr)
#define Qspi_Ip_Sfp_ClearLatchedErrors(baseAddr)          OsIf_Trusted_Call1param(Qspi_Ip_Sfp_ClearLatchedErrors_Privileged, baseAddr)

#else /* QSPI_IP_ENABLE_USER_MODE_SUPPORT */

#define Qspi_Ip_Sfp_Configure(baseAddr, userConfigPtr)    Qspi_Ip_Sfp_Configure_Privileged(baseAddr, userConfigPtr)
#define Qspi_Ip_ResetPrivilegedRegisters(baseAddr)        Qspi_Ip_ResetPrivilegedRegisters_Privileged(baseAddr)
#define Qspi_Ip_Sfp_ClearLatchedErrors(baseAddr)          Qspi_Ip_Sfp_ClearLatchedErrors_Privileged(baseAddr)

#endif /* QSPI_IP_ENABLE_USER_MODE_SUPPORT */

#endif /* FEATURE_QSPI_HAS_SFP */

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @cond DRIVER_INTERNAL_USE_ONLY */

/* Mask of QuadSPI IP-related error flags */
#ifndef QuadSPI_FR_IPAEF_MASK
    #define QuadSPI_FR_IPAEF_MASK  (0U)
#endif

#define QSPI_ERR_FLAGS_MASK    (QuadSPI_FR_TBUF_MASK | \
                                QuadSPI_FR_ILLINE_MASK | \
                                QuadSPI_FR_RBOF_MASK | \
                                QuadSPI_FR_IPAEF_MASK | \
                                QuadSPI_FR_IPIEF_MASK)


#define MEM_43_EXFLS_START_SEC_CONST_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"

/* Table of base addresses for QuadSPI instances. */
static QuadSPI_Type * const Qspi_Ip_BaseAddress[QuadSPI_INSTANCE_COUNT] = IP_QuadSPI_BASE_PTRS;
/* Table of AHB addresses for QuadSPI instances. */
static const uint32 Qspi_Ip_AhbAddress[QuadSPI_INSTANCE_COUNT] = QuadSPI_AHB_PTRS;

#define MEM_43_EXFLS_STOP_SEC_CONST_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"


#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_8
#include "Mem_43_EXFLS_MemMap.h"

/* The padding bytes information to handle unaligned read/write operation for QuadSPI instances:
   - For read:
        [7:0] the number of padding bytes to handle read from unaligned address
   - For write:
        [7:4] the number of pre-padding bytes to handle write from unaligned start address
        [3:0] the number of post-padding bytes to handle write from unaligned end address
 */
uint8 Qspi_Ip_MemoryPadding[QuadSPI_INSTANCE_COUNT];

#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_8
#include "Mem_43_EXFLS_MemMap.h"

#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_32
#include "Mem_43_EXFLS_MemMap.h"

/* Pointer to runtime configuration structures (storing the DLL configuration for runtime usage) */
static const Qspi_Ip_ControllerConfigType * Qspi_Ip_ControllerConfig[QuadSPI_INSTANCE_COUNT];

#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_32
#include "Mem_43_EXFLS_MemMap.h"

#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_32
#include "Mem_43_EXFLS_MemMap.h"

#if (QSPI_IP_CHECK_CFG_CRC == STD_ON)
/**
 * Pointer to current module configuration set
 */
static uint32 u32AccCRCremainder;
#endif /* QSPI_IP_CHECK_CFG_CRC */

#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_32
#include "Mem_43_EXFLS_MemMap.h"

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

static inline uint32 Qspi_Ip_GetWordSize(uint32 sizeRemaining);

#if (FEATURE_QSPI_HAS_SFP == 1)

void Qspi_Ip_Sfp_Configure_Privileged(QuadSPI_Type * baseAddr,
                                      Qspi_Ip_ControllerConfigType const * userConfigPtr
                                     );
void Qspi_Ip_ResetPrivilegedRegisters_Privileged(QuadSPI_Type *BaseAddr);
void Qspi_Ip_Sfp_ClearLatchedErrors_Privileged(QuadSPI_Type * BaseAddr);

#endif /* FEATURE_QSPI_HAS_SFP */

static inline void Qspi_Ip_ResetAllRegisters(QuadSPI_Type *BaseAddr);

static Qspi_Ip_StatusType Qspi_Ip_CmdWaitComplete(uint32 instance);

#if (QSPI_IP_CHECK_CFG_CRC == STD_ON)
static void Qspi_Ip_AccumulateCRC(uint32 InputData);
static void Qspi_Ip_ResetCRC(void);
static uint32 Qspi_Ip_FinalizeCRC(void);
static void Qspi_Ip_UpdateCRCreminder(Qspi_Ip_CrcDataSizeType DataSize);

static Qspi_Ip_CrcType Qspi_Ip_CalcMemCfgCRC(const Qspi_Ip_MemoryConfigType * pConfig);
static Qspi_Ip_CrcType Qspi_Ip_CalcCntCfgCRC(const Qspi_Ip_MemoryConnectionType * pConnect);
static Qspi_Ip_StatusType Qspi_Ip_ValidateCtrlCfgCRC(const Qspi_Ip_ControllerConfigType *userConfigPtr);

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_WaitResetComplete
 */
static void Qspi_Ip_AccumulateCRC(uint32 InputData)
{
    if (0xFFFFU < InputData)
    {
        /* preparation for accumulation of higher 16 bits of the InputData */
        u32AccCRCremainder = (u32AccCRCremainder << 16U) | (InputData >> 16U);
        /* make 16-bit accumulated result (in lower 16-bits of u32AccCRCremainder) */
        Qspi_Ip_UpdateCRCreminder(QSPI_IP_CRC_16_BITS);
    }

    if (0xFFU < InputData)
    {
        /* preparation for accumulation of lower 16 bits of the InputData */
        u32AccCRCremainder = (u32AccCRCremainder << 16U) | (InputData & 0x0000FFFFU);
        /* make 16-bit accumulated result (in lower 16-bits of u32AccCRCremainder) */
        Qspi_Ip_UpdateCRCreminder(QSPI_IP_CRC_16_BITS);
    }
    else
    {
        /* optimization: only 8 LSB bits are processed */
        /* preparation for accumulation of lower 8 bits of the InputData */
        u32AccCRCremainder = (u32AccCRCremainder << 8U) | InputData;
        /* make 16-bit accumulated result (in lower 16-bits of u32AccCRCremainder) */
        Qspi_Ip_UpdateCRCreminder(QSPI_IP_CRC_8_BITS);
    }
}

/**
 * @brief        Function to reset CRC calculation.
 *
 */
static void Qspi_Ip_ResetCRC(void)
{
    u32AccCRCremainder = 0U;
}


static uint32 Qspi_Ip_FinalizeCRC(void)
{
    /* add the final 0x0000 to the remainder */
    u32AccCRCremainder = (u32AccCRCremainder << 16U);
    /* make the final 16-bit CRC */
    Qspi_Ip_UpdateCRCreminder(QSPI_IP_CRC_16_BITS);

    return u32AccCRCremainder;
}


static void Qspi_Ip_UpdateCRCreminder(Qspi_Ip_CrcDataSizeType DataSize)
{
    uint32 CrcPolynomSft;
    uint32 LeadingOne;
    uint32 AccDataLoc;
    uint32 LeadingOneInitial;

    switch (DataSize)
    {
        case QSPI_IP_CRC_8_BITS:
            CrcPolynomSft = 0x11021U << 7U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            LeadingOneInitial = 0x10000U << 7U;
            break;

        case QSPI_IP_CRC_16_BITS:
        default:
            CrcPolynomSft = 0x11021U << 15U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            LeadingOneInitial = 0x10000U << 15U;
            break;
    }

    /* copy static variable to auto (computation over static may be slow) */
    AccDataLoc = u32AccCRCremainder;

    /* CRC computation */
    for (LeadingOne = LeadingOneInitial; LeadingOne >= 0x00010000U; LeadingOne >>= 1U)
    {
        if (0U != (AccDataLoc & LeadingOne))
        {
            AccDataLoc ^= CrcPolynomSft;
        }
        CrcPolynomSft >>= 1U;
    }

    /* copy back to static variable */
    u32AccCRCremainder = AccDataLoc;
}

static Qspi_Ip_CrcType Qspi_Ip_CalcMemCfgCRC(const Qspi_Ip_MemoryConfigType * pConfig)
{
    uint32 Index;
    uint32 readIdXor = 0U;

    /* Reset the accumulated CRC value */
    Qspi_Ip_ResetCRC();

    switch (pConfig->memType)
    {
        case QSPI_IP_HYPER_FLASH:
            if (NULL_PTR != pConfig->hfConfig)
            {
                Qspi_Ip_AccumulateCRC((uint32) pConfig->memSize);
                Qspi_Ip_AccumulateCRC((uint32) pConfig->pageSize);
                Qspi_Ip_AccumulateCRC((uint32) pConfig->hfConfig->outputDriverStrength);
                Qspi_Ip_AccumulateCRC((uint32) pConfig->hfConfig->RWDSLowOnDualError);
                Qspi_Ip_AccumulateCRC((uint32) pConfig->hfConfig->secureRegionUnlocked);
                Qspi_Ip_AccumulateCRC((uint32) pConfig->hfConfig->readLatency);
                Qspi_Ip_AccumulateCRC((uint32) pConfig->hfConfig->paramSectorMap);
                Qspi_Ip_AccumulateCRC((uint32) pConfig->hfConfig->deviceIdWordAddress);
            }
            break;
        case QSPI_IP_SERIAL_FLASH:
            /* CRC - Accumulate LUT settings */
            Qspi_Ip_AccumulateCRC((uint32) pConfig->memSize);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->pageSize);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->readLut);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->writeLut);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->read0xxLut);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->read0xxLutAHB);

            Qspi_Ip_AccumulateCRC((uint32) pConfig->readIdSettings.readIdLut);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->readIdSettings.readIdSize);
            for (Index = 0; Index < pConfig->readIdSettings.readIdSize; Index++)
            {
                readIdXor ^= pConfig->readIdSettings.readIdExpected[Index];
            }
            Qspi_Ip_AccumulateCRC(readIdXor);

            for (Index = 0; Index < QSPI_IP_ERASE_TYPES; Index++)
            {
                Qspi_Ip_AccumulateCRC((uint32) pConfig->eraseSettings.eraseTypes[Index].eraseLut);
                Qspi_Ip_AccumulateCRC((uint32) pConfig->eraseSettings.eraseTypes[Index].size);
            }
            Qspi_Ip_AccumulateCRC((uint32) pConfig->eraseSettings.chipEraseLut);

            Qspi_Ip_AccumulateCRC((uint32) pConfig->statusConfig.statusRegInitReadLut);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->statusConfig.statusRegReadLut);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->statusConfig.statusRegWriteLut);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->statusConfig.writeEnableSRLut);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->statusConfig.writeEnableLut);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->statusConfig.regSize);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->statusConfig.busyOffset);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->statusConfig.busyValue);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->statusConfig.writeEnableOffset);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->statusConfig.blockProtectionOffset);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->statusConfig.blockProtectionWidth);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->statusConfig.blockProtectionValue);

            Qspi_Ip_AccumulateCRC((uint32) pConfig->suspendSettings.eraseSuspendLut);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->suspendSettings.eraseResumeLut);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->suspendSettings.programSuspendLut);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->suspendSettings.programResumeLut);

            Qspi_Ip_AccumulateCRC((uint32) pConfig->resetSettings.resetCmdLut);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->resetSettings.resetCmdCount);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->initResetSettings.resetCmdLut);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->initResetSettings.resetCmdCount);

            Qspi_Ip_AccumulateCRC((uint32) pConfig->initConfiguration.opCount);
            Qspi_Ip_AccumulateCRC((uint32) pConfig->lutSequences.opCount);
            break;

        default:
            ; /* Not possible */
            break;
    }

    return ((Qspi_Ip_CrcType)Qspi_Ip_FinalizeCRC());
}

static Qspi_Ip_CrcType Qspi_Ip_CalcCntCfgCRC(const Qspi_Ip_MemoryConnectionType * pConnect)
{
    /* Reset the accumulated CRC value */
    Qspi_Ip_ResetCRC();

    /* CRC - Accumulate MemConnectionCfg */
    Qspi_Ip_AccumulateCRC((uint32) pConnect->qspiInstance);
    Qspi_Ip_AccumulateCRC((uint32) pConnect->connectionType);
    Qspi_Ip_AccumulateCRC((uint32) pConnect->memAlignment);

    return ((Qspi_Ip_CrcType)Qspi_Ip_FinalizeCRC());
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ValidateConfigCRC
 * Description   : Caculate and check the CRC over configuration set
*/
Qspi_Ip_StatusType Qspi_Ip_ValidateMemConfigCRC(const Qspi_Ip_MemoryConfigType * pConfig,
                                                const Qspi_Ip_MemoryConnectionType * pConnect
                                               )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;

    if ((pConfig->memCfgCRC != Qspi_Ip_CalcMemCfgCRC(pConfig)) || (pConnect->memCntCfgCRC != Qspi_Ip_CalcCntCfgCRC(pConnect)))
    {
        status = STATUS_QSPI_IP_ERROR;
    }

    return status;
}

static Qspi_Ip_StatusType Qspi_Ip_ValidateCtrlCfgCRC(const Qspi_Ip_ControllerConfigType *userConfigPtr)
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;

    /* Reset the accumulated CRC value */
    Qspi_Ip_ResetCRC();

    /* CRC - Accumulate dataRate */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dataRate);
    /* CRC - Accumulate memSizeA1 */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->memSizeA1);
    /* CRC - Accumulate memSizeA2 */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->memSizeA2);
    /* CRC - Accumulate memSizeB1 */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->memSizeB1);
    /* CRC - Accumulate memSizeB2 */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->memSizeB2);
    /* CRC - Accumulate csHoldTime */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->csHoldTime);
    /* CRC - Accumulate csSetupTime */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->csSetupTime);
    /* CRC - Accumulate columnAddr */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->columnAddr);
    /* CRC - Accumulate wordAddresable */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->wordAddresable);
    /* CRC - Accumulate readModeA */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->readModeA);
    /* CRC - Accumulate readModeB */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->readModeB);
    /* CRC - Accumulate sampleDelay */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->sampleDelay);
    /* CRC - Accumulate samplePhase */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->samplePhase);
    /* CRC - Accumulate dllMode */
    /* CRC - dllMode side A */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dllSettingsA.dllMode);
    /* CRC - Accumulate freqEnable */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dllSettingsA.freqEnable);
    /* CRC - Accumulate referenceCounter */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dllSettingsA.referenceCounter);
    /* CRC - Accumulate resolution */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dllSettingsA.resolution);
    /* CRC - Accumulate coarseDelay */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dllSettingsA.coarseDelay);
    /* CRC - Accumulate fineDelay */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dllSettingsA.fineDelay);
    /* CRC - Accumulate tapSelect */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dllSettingsA.tapSelect);
    /* CRC - dllMode side B */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dllSettingsB.dllMode);
    /* CRC - Accumulate freqEnable */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dllSettingsB.freqEnable);
    /* CRC - Accumulate referenceCounter */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dllSettingsB.referenceCounter);
    /* CRC - Accumulate resolution */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dllSettingsB.resolution);
    /* CRC - Accumulate coarseDelay */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dllSettingsB.coarseDelay);
    /* CRC - Accumulate fineDelay */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dllSettingsB.fineDelay);
    /* CRC - Accumulate tapSelect */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dllSettingsB.tapSelect);
    /* CRC - Accumulate centerAlignedStrobe */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->centerAlignedStrobeA);
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->centerAlignedStrobeB);
    /* CRC - Accumulate differentialClock */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->differentialClockA);
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->differentialClockB);
    /* CRC - Accumulate dataAlign */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dataAlign);
    /* CRC - Accumulate io2IdleValueA */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->io2IdleValueA);
    /* CRC - Accumulate io3IdleValueA */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->io3IdleValueA);
    /* CRC - Accumulate io2IdleValueA */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->io2IdleValueB);
    /* CRC - Accumulate io3IdleValueA */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->io3IdleValueB);
    /* CRC - Accumulate dqsAsAnOutput */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->dqsAsAnOutput);
    /* CRC - Accumulate byteSwap */
    Qspi_Ip_AccumulateCRC((uint32) userConfigPtr->byteSwap);

    if (userConfigPtr->memCtrlCfgCRC != (Qspi_Ip_CrcType)Qspi_Ip_FinalizeCRC())
    {
        status = STATUS_QSPI_IP_ERROR;
    }

    return status;
}

#endif /* QSPI_IP_CHECK_CFG_CRC */

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_GetWordSize
 * Description   : Calculates the word size for the up coming loop
 */
static inline uint32 Qspi_Ip_GetWordSize(uint32 sizeRemaining)
{
    return (sizeRemaining > 4U) ? 4U : sizeRemaining;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ProcessDataRead
 * Description   : Processes read data
 * @implements     Qspi_Ip_ProcessDataRead_Activity */
static inline Qspi_Ip_StatusType Qspi_Ip_ProcessDataRead(uint8 *dataRead,
                                                         uint32 size,
                                                         const QuadSPI_Type *baseAddr,
                                                         uint32 padding
                                                        )
{
    uint8 * data = dataRead;
    uint32 cnt = 0U;
    uint32 recvData;
    const uint8 *recvDataPtr = (uint8 *)(&recvData);
    uint32 wordSize;
    uint32 byteCnt;
    uint32 sizeRemaining = size;
    uint32 paddingBytes = padding;

    if (0U != paddingBytes)
    {
        /* Ignore all padding words, jump to the fist data */
        cnt            = paddingBytes >> 2U;
        sizeRemaining -= cnt << 2U;
        paddingBytes  &= 0x3U;

        /* Get first received word */
        recvData = baseAddr->RBDR[cnt];
        cnt++;
        /* Get wordSize for the loop */
        wordSize = Qspi_Ip_GetWordSize(sizeRemaining);

        /* Ignore padding bytes and copy the rest to buffer */
        for (byteCnt = paddingBytes; byteCnt < wordSize; byteCnt++)
        {
            #if (defined(CORE_BIG_ENDIAN))
            *data = recvDataPtr[3U - byteCnt];
            #else
            *data = recvDataPtr[byteCnt];
            #endif

            data++;
        }
        sizeRemaining -= wordSize;
    }

    /* Check user buffer alignment */
    if (((Qspi_Ip_UintPtrType)data & 0x3U) == 0U)
    {
        /* Process 4 bytes at a time to speed up read */
        while (sizeRemaining >= 4U)
        {
            *((uint32 *)((Qspi_Ip_UintPtrType)data)) = baseAddr->RBDR[cnt];  /* Casting through uint32 to avoid Misra 11.3 */
            data = &(data[4U]);
            cnt++;
            sizeRemaining -= 4U;
        }
    }

    /* Process remaining bytes one by one */
    while (sizeRemaining > 0U)
    {
        /* Get next received word */
        recvData = baseAddr->RBDR[cnt];
        /* get wordSize for the loop */
        wordSize = Qspi_Ip_GetWordSize(sizeRemaining);
        for (byteCnt = 0U; byteCnt < wordSize; byteCnt++)
        {
#if (defined(CORE_BIG_ENDIAN))
            *data = (uint8)(recvData >> 24U);
            recvData <<= 8U;
#else
            *data = (uint8)(recvData & 0xFFU);
            recvData >>= 8U;
#endif
            data++;
            sizeRemaining--;
        }
        cnt++;
    }
    return STATUS_QSPI_IP_SUCCESS;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ProcessDataVerify
 * Description   : Processes program verify data
 * @implements     Qspi_Ip_ProcessDataVerify_Activity */
static inline Qspi_Ip_StatusType Qspi_Ip_ProcessDataVerify(const uint8 *dataCmp,
                                                           uint32 size,
                                                           const QuadSPI_Type *baseAddr,
                                                           uint32 padding
                                                          )
{
    const uint8 * roData = dataCmp;
    uint32 cnt = 0U;
    uint32 recvData;
    uint8 recvByte;
    const uint8 *recvDataPtr = (uint8 *)(&recvData);
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint32 byteCnt;
    uint32 wordSize;
    uint32 paddingBytes = padding;
    uint32 sizeRemaining = size;

    if (0U != paddingBytes)
    {
        /* Ignore all padding words, jump to the fist data */
        cnt            = paddingBytes >> 2U;
        sizeRemaining -= cnt << 2U;
        paddingBytes  &= 0x3U;

        /* Get first received word */
        recvData = baseAddr->RBDR[cnt];
        cnt++;
        /* Get wordSize for the loop */
        wordSize = Qspi_Ip_GetWordSize(sizeRemaining);
        sizeRemaining -= wordSize;

        /* Ignore padding bytes and compare the rest with user buffer */
        for (byteCnt = paddingBytes; byteCnt < wordSize; byteCnt++)
        {
            #if (defined(CORE_BIG_ENDIAN))
            recvByte = recvDataPtr[3U - byteCnt];
            #else
            recvByte = recvDataPtr[byteCnt];
            #endif

            /* return STATUS_QSPI_IP_ERROR_PROGRAM_VERIFY if the data is not match */
            if (*roData != recvByte)
            {
                status = STATUS_QSPI_IP_ERROR_PROGRAM_VERIFY;
                sizeRemaining = 0U;
                break;
            }
            roData++;
        }
    }

    /* Check user buffer alignment */
    if (((Qspi_Ip_UintPtrType)roData & 0x3U) == 0U)
    {
        while (sizeRemaining >= 4U)
        {
            /* Process 4 bytes at a time to speed up read */
            if (*((const uint32 *)((Qspi_Ip_UintPtrType)roData)) != baseAddr->RBDR[cnt])
            {
                /* return STATUS_QSPI_IP_ERROR_PROGRAM_VERIFY if the data is not match */
                status = STATUS_QSPI_IP_ERROR_PROGRAM_VERIFY;
                sizeRemaining = 0U;
                break;
            }
            /* update the roData */
            roData = &(roData[4U]);
            cnt++;
            sizeRemaining -= 4U;
        }
    }

    /* Process remaining bytes one by one */
    while (sizeRemaining > 0U)
    {
        /* Get next received word */
        recvData = baseAddr->RBDR[cnt];
        /* get wordSize for the loop */
        wordSize = Qspi_Ip_GetWordSize(sizeRemaining);
        for (byteCnt = 0U; byteCnt < wordSize; byteCnt++)
        {
#if (defined(CORE_BIG_ENDIAN))
            recvByte = (uint8)(recvData >> 24U);
            recvData <<= 8U;
#else
            recvByte = (uint8)(recvData & 0xFFU);
            recvData >>= 8U;
#endif
            /* return STATUS_QSPI_IP_ERROR_PROGRAM_VERIFY if the data is not match */
            if (*roData != recvByte)
            {
                status = STATUS_QSPI_IP_ERROR_PROGRAM_VERIFY;
                sizeRemaining = 0U;
                break;
            }
            else
            {
                /* update the roData, sizeRemaining */
                roData++;
                sizeRemaining--;
            }
        }
        cnt++;
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ProcessDataBlankCheck
 * Description   : Processes blank check data
 * @implements     Qspi_Ip_ProcessDataBlankCheck_Activity */
static inline Qspi_Ip_StatusType Qspi_Ip_ProcessDataBlankCheck(uint32 size,
                                                               const QuadSPI_Type *baseAddr,
                                                               uint32 padding
                                                              )
{
    uint32 cnt = 0U;
    uint32 recvData = 0U;
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint32 dataSize;
    uint32 sizeRemaining = size;
    uint32 paddingBytes = padding;

    if (0U != paddingBytes)
    {
        /* Ignore all padding words, jump to the fist data */
        cnt            = paddingBytes >> 2U;
        sizeRemaining -= cnt << 2U;
        paddingBytes  &= 0x3U;

        /* Get first received word */
        recvData = ~(baseAddr->RBDR[cnt]);
        cnt++;
        /* Get wordSize for the blank check */
        dataSize = Qspi_Ip_GetWordSize(sizeRemaining);
        sizeRemaining -= dataSize;

        /* Mask data: ignore padding at the beginning and unused bytes at the end */
#if (defined(CORE_BIG_ENDIAN))
        recvData &= 0xFFFFFFFFUL << ((4UL - dataSize) * 8UL);
        recvData &= 0xFFFFFFFFUL >> (paddingBytes * 8UL);
#else
        recvData &= 0xFFFFFFFFUL >> ((4UL - dataSize) * 8UL);
        recvData &= 0xFFFFFFFFUL << (paddingBytes * 8UL);
#endif
        if (recvData != 0U)
        {
            /* The data is not blank */
            status = STATUS_QSPI_IP_ERROR_BLANK_CHECK;
            sizeRemaining = 0U;
        }
    }

    /* Blank check */
    while (sizeRemaining >= 4U)
    {
        if (baseAddr->RBDR[cnt] != 0xFFFFFFFFU)
        {
            /* The data is not blank */
            status = STATUS_QSPI_IP_ERROR_BLANK_CHECK;
            sizeRemaining = 0U;
            break;
        }
        cnt++;
        sizeRemaining -= 4U;
    }

    if (sizeRemaining != 0U)
    {
        /* Process last few bytes */
        recvData = baseAddr->RBDR[size >> 2U];
#if (defined(CORE_BIG_ENDIAN))
        if ((~recvData & ~(((uint32)1U << (((uint32)4U - sizeRemaining) * 8U)) - 1U)) != 0U)
#else
        if ((~recvData & (((uint32)1U << (sizeRemaining * 8U)) - 1U)) != 0U)
#endif
        {
            /* The data is not blank */
            status = STATUS_QSPI_IP_ERROR_BLANK_CHECK;
        }
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_FillTxBuf
 * Description   : Fill Tx buffer with the specified number of 4-byte entries
 *                 Qspi_Ip_FillTxBuf_Activity */
static void Qspi_Ip_FillTxBuf(QuadSPI_Type *baseAddr,
                              const uint8 *roData,
                              uint32 size,
                              uint32 paddingInfo
                             )
{
    uint32 sizeLeft = size;
    uint32 wordSize;
    uint32 data = 0xFFFFFFFFUL;
    uint8 *dataPtr = (uint8 *)(&data);
    uint32 byteCnt;
    const uint8 * roDataPtr = roData;

    uint32 prePadding   = paddingInfo >> 4U;
    uint32 postPadding  = paddingInfo & 0x0FU;

    /* Insert prePadding words */
    while (prePadding >= 4U)
    {
        Qspi_Ip_WriteTxData(baseAddr, 0xFFFFFFFFUL);
        prePadding -= 4U;
    }

    if (prePadding != 0U)
    {
        wordSize = prePadding + sizeLeft;

        if (wordSize > 4U)
        {
            wordSize  = 4U;
            sizeLeft -= (4U - prePadding);
        }
        else
        {
            /* Note for special case: prePadding + Data + postPadding are fit into a word
               Decreaseing postPadding is not needed because out of user data, all branches below will be skipped
             */
            sizeLeft = 0U;
        }

        /* Fill user data between prePadding and postPadding */
        for (byteCnt = prePadding; byteCnt < wordSize; byteCnt++)
        {
            #if (defined(CORE_BIG_ENDIAN))
            dataPtr[3U - byteCnt] = *roDataPtr;
            #else
            dataPtr[byteCnt] = *roDataPtr;
            #endif

            roDataPtr++;
        }
        Qspi_Ip_WriteTxData(baseAddr, data);
    }

    /* Check user buffer alignment */
    if (((Qspi_Ip_UintPtrType)roDataPtr & 0x3U) == 0U)
    {
        /* Process 4 bytes at a time to speed things up */
        while (sizeLeft >= 4U)
        {
            data = *(const uint32 *)((Qspi_Ip_UintPtrType)roDataPtr);  /* Casting through uint32 to avoid Misra 11.3 */
            sizeLeft -= 4U;
            roDataPtr = &(roDataPtr[4U]);
            Qspi_Ip_WriteTxData(baseAddr, data);
        }
    }

    /* Process remaining bytes one by one */
    while (sizeLeft > 0U)
    {
        /* Processes last few data bytes (less than 4) */
        data = 0xFFFFFFFFUL;
        wordSize = Qspi_Ip_GetWordSize(sizeLeft);

        for (byteCnt = 0U; byteCnt < wordSize; byteCnt++)
        {
            #if (defined(CORE_BIG_ENDIAN))
            dataPtr[3U - byteCnt] = *roDataPtr;
            #else
            dataPtr[byteCnt] = *roDataPtr;
            #endif

            roDataPtr++;
        }
        Qspi_Ip_WriteTxData(baseAddr, data);
        sizeLeft -= wordSize;
    }

    /* Insert postPadding words */
    while (postPadding >= 4U)
    {
        Qspi_Ip_WriteTxData(baseAddr, 0xFFFFFFFFUL);
        postPadding -= 4U;
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ErrorCheck
 * Description   : Checks if there were errors during IP command execution
* @implements      Qspi_Ip_ErrorCheck_Activity */
static inline Qspi_Ip_StatusType Qspi_Ip_ErrorCheck(QuadSPI_Type *baseAddr)
{
    Qspi_Ip_StatusType status;

    if ((baseAddr->FR & QSPI_ERR_FLAGS_MASK) != 0U)
    {
        /* clear error flags */
        baseAddr->FR = QSPI_ERR_FLAGS_MASK;
        status = STATUS_QSPI_IP_ERROR;
    }
#if (FEATURE_QSPI_HAS_SFP == 1)
    else if (baseAddr->ERRSTAT != 0UL)
    {
        status = STATUS_QSPI_IP_ERROR;
    }
#endif /* FEATURE_QSPI_HAS_SFP */
    else
    {
        status = STATUS_QSPI_IP_SUCCESS;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SwResetDelay
 * Description   : Insert waiting loops after changing the value of the software reset bits
 */
static inline void Qspi_Ip_SwResetDelay(void)
{
    /* Prepare timeout counter */
    volatile uint32 u32CurrentTicks = QSPI_IP_SOFTWARE_RESET_DELAY;
    /* Insert delay after changing the value of the software reset bits. */
    while (u32CurrentTicks > 0U)
    {
        u32CurrentTicks--;
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SwReset
 * Description   : Resets the QuadSPI device
* @implements      Qspi_Ip_SwReset_Activity */
static void Qspi_Ip_SwReset(QuadSPI_Type *baseAddr)
{
    /* Software reset AHB domain and Serial Flash domain at the same time. */
    Qspi_Ip_SwResetOn(baseAddr);
    /* Insert delay after changing the value of the reset bits. */
    Qspi_Ip_SwResetDelay();
    /* Disable QuadSPI module before de-asserting the reset bits. */
    Qspi_Ip_Disable(baseAddr);
    /* De-asset Software reset AHB domain and Serial Flash domain bits. */
    Qspi_Ip_SwResetOff(baseAddr);
    /* Re-enable QuadSPI module after reset. */
    Qspi_Ip_Enable(baseAddr);
    /* Insert delay after changing the value of the reset bits. */
    Qspi_Ip_SwResetDelay();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_AhbFlush
 * Description   : Reset AHB buffers
 */
static Qspi_Ip_StatusType Qspi_Ip_AhbFlush(QuadSPI_Type *baseAddr)
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;

#ifdef QuadSPI_SPTRCLR_ABRT_CLR_MASK
    uint32  u32ElapsedTicks = 0UL;
    uint32  u32TimeoutTicks;
    uint32  u32CurrentTicks;

    /* Use the AHB buffer clear bit to avoid losing the DLL lock */
    Qspi_Ip_ClearAhbBuf(baseAddr);

    /* Prepare timeout counter */
    u32TimeoutTicks = OsIf_MicrosToTicks(QSPI_IP_CMD_COMPLETE_TIMEOUT, QSPI_IP_TIMEOUT_TYPE);
    u32CurrentTicks = OsIf_GetCounter(QSPI_IP_TIMEOUT_TYPE);

    /* Wait for clearing the AHB buffer pointers */
    while (!Qspi_Ip_GetClrAhbStatus(baseAddr))
    {
        /* An exit point for safety purpose only, because this loop is not expected to happen in practice */
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, QSPI_IP_TIMEOUT_TYPE);
        if (u32ElapsedTicks >= u32TimeoutTicks)
        {
            status = STATUS_QSPI_IP_TIMEOUT;
            break;
        }
    }

#else
    /* Otherwise use the software reset */
    Qspi_Ip_SwReset(baseAddr);
#endif

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_WaitDLLASlaveLock
 * Description   : DLL side A - Wait for slave high lock status or DLL lock status
 */
static Qspi_Ip_StatusType Qspi_Ip_WaitDLLASlaveLock(const QuadSPI_Type *baseAddr,
                                                    boolean waitSlaveLock
                                                   )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    boolean LockStatus;

    /* Prepare timeout counter */
    uint32 u32ElapsedTicks = 0UL;
    uint32 u32TimeoutTicks = OsIf_MicrosToTicks(QSPI_IP_DLL_LOCK_TIMEOUT, QSPI_IP_TIMEOUT_TYPE);
    uint32 u32CurrentTicks = OsIf_GetCounter(QSPI_IP_TIMEOUT_TYPE);

    do
    {
        /* Wait for slave high lock status or DLL lock status */
        LockStatus = (waitSlaveLock) ? Qspi_Ip_DLLGetSlaveLockStatusA(baseAddr) : Qspi_Ip_DLLGetLockStatusA(baseAddr);

        /* Check for errors reported by DLL */
        if (Qspi_Ip_DLLGetErrorStatusA(baseAddr))
        {
            status = STATUS_QSPI_IP_ERROR;
        }
        else
        {
            /* Check for timeout */
            u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, QSPI_IP_TIMEOUT_TYPE);
            if (u32ElapsedTicks >= u32TimeoutTicks)
            {
                status = STATUS_QSPI_IP_TIMEOUT;
            }
        }

        if (STATUS_QSPI_IP_SUCCESS != status)
        {
            break;
        }
    }
    while (!LockStatus);

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureDLLAByPass
 * Description   : Configures DLL - Side A (bypass mode)
 */
static Qspi_Ip_StatusType Qspi_Ip_ConfigureDLLAByPass(QuadSPI_Type *baseAddr,
                                                      const Qspi_Ip_ControllerConfigType *userConfigPtr
                                                     )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;

    /* Set DLL in bypass mode and configure coarse and fine delays */
    Qspi_Ip_DLLSlaveBypassA    (baseAddr, TRUE);
    Qspi_Ip_DLLSlaveAutoUpdateA(baseAddr, FALSE);
    Qspi_Ip_DLLSetDelayCoarseA (baseAddr, userConfigPtr->dllSettingsA.coarseDelay);
    Qspi_Ip_DLLSetFineOffsetA  (baseAddr, userConfigPtr->dllSettingsA.fineDelay);
    Qspi_Ip_DLLFreqEnA         (baseAddr, userConfigPtr->dllSettingsA.freqEnable);

    /* Trigger slave chain update */
    Qspi_Ip_DLLSlaveUpdateA(baseAddr, TRUE);

    /* Wait for slave delay chain update */
    status = Qspi_Ip_WaitDLLASlaveLock(baseAddr, TRUE);
    /* Disable slave chain update */
    Qspi_Ip_DLLSlaveUpdateA(baseAddr, FALSE);

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureDLLASetup
 * Description   : Setup DLL side A before update
 */
static void Qspi_Ip_ConfigureDLLASetup(QuadSPI_Type *baseAddr,
                                       const Qspi_Ip_ControllerConfigType *userConfigPtr
                                      )
{
    /* Set DLL in auto update mode and configure coarse and fine delays */
    Qspi_Ip_DLLSlaveBypassA        (baseAddr, FALSE);
    Qspi_Ip_DLLSlaveAutoUpdateA    (baseAddr, (QSPI_IP_DLL_AUTO_UPDATE == userConfigPtr->dllSettingsA.dllMode));
#ifdef QuadSPI_DLLCRA_DLL_REFCNTR_MASK
    Qspi_Ip_DLLSetReferenceCounterA(baseAddr, userConfigPtr->dllSettingsA.referenceCounter);
#endif  /* QuadSPI_DLLCRA_DLL_REFCNTR_MASK */
#ifdef QuadSPI_DLLCRA_DLLRES_MASK
    Qspi_Ip_DLLSetResolutionA      (baseAddr, userConfigPtr->dllSettingsA.resolution);
#endif /* QuadSPI_DLLCRA_DLLRES_MASK */
    Qspi_Ip_DLLSetDelayOffsetA     (baseAddr, userConfigPtr->dllSettingsA.coarseDelay);
    Qspi_Ip_DLLSetFineOffsetA      (baseAddr, userConfigPtr->dllSettingsA.fineDelay);
    Qspi_Ip_DLLFreqEnA             (baseAddr, userConfigPtr->dllSettingsA.freqEnable);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureDLLAUpdate
 * Description   : Configures DLL - Side A (manual update or auto update mode)
 */
static Qspi_Ip_StatusType Qspi_Ip_ConfigureDLLAUpdate(QuadSPI_Type *baseAddr,
                                                      const Qspi_Ip_ControllerConfigType *userConfigPtr
                                                     )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;

    /* Setup DLL side A before update */
    Qspi_Ip_ConfigureDLLASetup(baseAddr, userConfigPtr);

    if (QSPI_IP_DLL_AUTO_UPDATE == userConfigPtr->dllSettingsA.dllMode)
    {
        /* For auto update mode, trigger slave chain update */
        Qspi_Ip_DLLSlaveUpdateA(baseAddr, TRUE);
    }
    /* Enable DLL */
    Qspi_Ip_DLLEnableA(baseAddr, TRUE);

    if (QSPI_IP_DLL_MANUAL_UPDATE == userConfigPtr->dllSettingsA.dllMode)
    {
        /* For manual update mode, wait for DLL lock before triggering slave chain update */
        status = Qspi_Ip_WaitDLLASlaveLock(baseAddr, (boolean)FALSE);

        Qspi_Ip_DLLSlaveUpdateA(baseAddr, TRUE);
    }

    /* Wait for slave delay chain update */
    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        status = Qspi_Ip_WaitDLLASlaveLock(baseAddr, (boolean)TRUE);
    }

    /* Disable slave chain update */
    Qspi_Ip_DLLSlaveUpdateA(baseAddr, FALSE);

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureDLLA
 * Description   : Configures DLL - Side A
 *                 Qspi_Ip_ConfigureDLLA_Activity
 */
static Qspi_Ip_StatusType Qspi_Ip_ConfigureDLLA(uint32 instance,
                                                QuadSPI_Type *baseAddr,
                                                const Qspi_Ip_ControllerConfigType *userConfigPtr
                                               )
{
    (void)instance;
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;

    /* Ensure DLL and slave chain update are off */
    Qspi_Ip_DLLSlaveUpdateA(baseAddr, FALSE);
    Qspi_Ip_DLLEnableA     (baseAddr, FALSE);

    /* Enable DQS slave delay chain before any settings take place */
    Qspi_Ip_DLLSlaveEnA(baseAddr, TRUE);

    if (QSPI_IP_DLL_BYPASSED == userConfigPtr->dllSettingsA.dllMode)
    {
        status = Qspi_Ip_ConfigureDLLAByPass(baseAddr, userConfigPtr);
    }
    else /* QSPI_DLL_MANUAL_UPDATE or QSPI_DLL_AUTO_UPDATE */
    {
        status = Qspi_Ip_ConfigureDLLAUpdate(baseAddr, userConfigPtr);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_WaitDLLBSlaveLock
 * Description   : DLL side B - Wait for slave high lock status or DLL lock status
 */
static Qspi_Ip_StatusType Qspi_Ip_WaitDLLBSlaveLock(const QuadSPI_Type *baseAddr,
                                                    boolean waitSlaveLock
                                                   )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    boolean LockStatus;

    /* Prepare timeout counter */
    uint32 u32ElapsedTicks = 0UL;
    uint32 u32TimeoutTicks = OsIf_MicrosToTicks(QSPI_IP_DLL_LOCK_TIMEOUT, QSPI_IP_TIMEOUT_TYPE);
    uint32 u32CurrentTicks = OsIf_GetCounter(QSPI_IP_TIMEOUT_TYPE);

    do
    {
        /* Wait for slave high lock status or DLL lock status */
        LockStatus = (waitSlaveLock) ? Qspi_Ip_DLLGetSlaveLockStatusB(baseAddr) : Qspi_Ip_DLLGetLockStatusB(baseAddr);

        /* Check for errors reported by DLL */
        if (Qspi_Ip_DLLGetErrorStatusB(baseAddr))
        {
            status = STATUS_QSPI_IP_ERROR;
        }
        else
        {
            /* Check for timeout */
            u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, QSPI_IP_TIMEOUT_TYPE);
            if (u32ElapsedTicks >= u32TimeoutTicks)
            {
                status = STATUS_QSPI_IP_TIMEOUT;
            }
        }

        if (STATUS_QSPI_IP_SUCCESS != status)
        {
            break;
        }
    }
    while (!LockStatus);

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureDLLBByPass
 * Description   : Configures DLL - Side B (bypass mode)
 */
static Qspi_Ip_StatusType Qspi_Ip_ConfigureDLLBByPass(QuadSPI_Type *baseAddr,
                                                      const Qspi_Ip_ControllerConfigType *userConfigPtr
                                                     )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;

    /* Set DLL in bypass mode and configure coarse and fine delays */
    Qspi_Ip_DLLSlaveBypassB    (baseAddr, TRUE);
    Qspi_Ip_DLLSlaveAutoUpdateB(baseAddr, FALSE);
    Qspi_Ip_DLLSetDelayCoarseB (baseAddr, userConfigPtr->dllSettingsB.coarseDelay);
    Qspi_Ip_DLLSetFineOffsetB  (baseAddr, userConfigPtr->dllSettingsB.fineDelay);
    Qspi_Ip_DLLFreqEnB         (baseAddr, userConfigPtr->dllSettingsB.freqEnable);

    /* Trigger slave chain update */
    Qspi_Ip_DLLSlaveUpdateB    (baseAddr, TRUE);

    /* Wait for slave delay chain update */
    status = Qspi_Ip_WaitDLLBSlaveLock(baseAddr, TRUE);
    /* Disable slave chain update */
    Qspi_Ip_DLLSlaveUpdateB(baseAddr, FALSE);

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureDLLBSetup
 * Description   : Setup DLL side B before update
 */
static void Qspi_Ip_ConfigureDLLBSetup(QuadSPI_Type *baseAddr,
                                       const Qspi_Ip_ControllerConfigType *userConfigPtr
                                      )
{
    /* Set DLL in auto update mode and configure coarse and fine delays */
    Qspi_Ip_DLLSlaveBypassB        (baseAddr, FALSE);
    Qspi_Ip_DLLSlaveAutoUpdateB    (baseAddr, (QSPI_IP_DLL_AUTO_UPDATE == userConfigPtr->dllSettingsB.dllMode));
    Qspi_Ip_DLLSetReferenceCounterB(baseAddr, userConfigPtr->dllSettingsB.referenceCounter);
    Qspi_Ip_DLLSetResolutionB      (baseAddr, userConfigPtr->dllSettingsB.resolution);
    Qspi_Ip_DLLSetDelayOffsetB     (baseAddr, userConfigPtr->dllSettingsB.coarseDelay);
    Qspi_Ip_DLLSetFineOffsetB      (baseAddr, userConfigPtr->dllSettingsB.fineDelay);
    Qspi_Ip_DLLFreqEnB             (baseAddr, userConfigPtr->dllSettingsB.freqEnable);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureDLLBUpdate
 * Description   : Configures DLL - Side B (manual update or auto update mode)
 */
static Qspi_Ip_StatusType Qspi_Ip_ConfigureDLLBUpdate(QuadSPI_Type *baseAddr,
                                                      const Qspi_Ip_ControllerConfigType *userConfigPtr
                                                     )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;

    /* Setup DLL side B before update */
    Qspi_Ip_ConfigureDLLBSetup(baseAddr, userConfigPtr);

    if (QSPI_IP_DLL_AUTO_UPDATE == userConfigPtr->dllSettingsB.dllMode)
    {
        /* For auto update mode, trigger slave chain update */
        Qspi_Ip_DLLSlaveUpdateB(baseAddr, TRUE);
    }
    /* Enable DLL */
    Qspi_Ip_DLLEnableB(baseAddr, TRUE);

    if (QSPI_IP_DLL_MANUAL_UPDATE == userConfigPtr->dllSettingsB.dllMode)
    {
        /* For manual update mode, wait for DLL lock before triggering slave chain update */
        status = Qspi_Ip_WaitDLLBSlaveLock(baseAddr, (boolean)FALSE);

        Qspi_Ip_DLLSlaveUpdateB(baseAddr, TRUE);
    }

    /* Wait for slave delay chain update */
    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        status = Qspi_Ip_WaitDLLBSlaveLock(baseAddr, (boolean)TRUE);
    }

    /* Disable slave chain update */
    Qspi_Ip_DLLSlaveUpdateB(baseAddr, FALSE);

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureDLLB
 * Description   : Configures DLL - Side B
 */
static Qspi_Ip_StatusType Qspi_Ip_ConfigureDLLB(uint32 instance,
                                                QuadSPI_Type *baseAddr,
                                                const Qspi_Ip_ControllerConfigType *userConfigPtr
                                               )
{
    (void)instance;
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;

    /* Ensure DLL and slave chain update are off */
    Qspi_Ip_DLLSlaveUpdateB(baseAddr, FALSE);
    Qspi_Ip_DLLEnableB     (baseAddr, FALSE);

    /* Enable DQS slave delay chain before any settings take place */
    Qspi_Ip_DLLSlaveEnB(baseAddr, TRUE);

    if (QSPI_IP_DLL_BYPASSED == userConfigPtr->dllSettingsB.dllMode)
    {
        status = Qspi_Ip_ConfigureDLLBByPass(baseAddr, userConfigPtr);
    }
    else /* QSPI_DLL_MANUAL_UPDATE or QSPI_DLL_AUTO_UPDATE */
    {
        status = Qspi_Ip_ConfigureDLLBUpdate(baseAddr, userConfigPtr);
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureDLL
 * Description   : Configure the DLL chain
 *
 *END**************************************************************************/
static Qspi_Ip_StatusType Qspi_Ip_ConfigureDLL(uint32 instance,
                                               const Qspi_Ip_ControllerConfigType * userConfigPtr
                                              )
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    QuadSPI_Type *baseAddr = Qspi_Ip_BaseAddress[instance];

    /* Configure DLL */
    if ((userConfigPtr->memSizeA1 + userConfigPtr->memSizeA2) > 0U)
    {
        status = Qspi_Ip_ConfigureDLLA(instance, baseAddr, userConfigPtr);
    }
    if ((userConfigPtr->memSizeB1 + userConfigPtr->memSizeB2) > 0U)
    {
        if (STATUS_QSPI_IP_SUCCESS == status)
        {
            status = Qspi_Ip_ConfigureDLLB(instance, baseAddr, userConfigPtr);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_IsSideAvailableB
 * Description   : Check support Side B in user configuration
 *
 *END**************************************************************************/
static inline boolean Qspi_Ip_IsSideAvailableB(const Qspi_Ip_ControllerConfigType *userConfigPtr)
{
    boolean Status = FALSE;

    if ((userConfigPtr->memSizeB1 + userConfigPtr->memSizeB2) > 0U)
    {
        Status = TRUE;
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureChipOptions
 * Description   : Configures chip-specific settings, e.g. SOCCR
 ***********************************************************************/


static void Qspi_Ip_ConfigureChipOptions(const QuadSPI_Type *baseAddr,
                                         const Qspi_Ip_ControllerConfigType * userConfigPtr
                                        )
{
    /* Do nothing */
    (void)userConfigPtr;
    (void)baseAddr;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_DdrConfig
 * Description   :
 */
static void Qspi_Ip_DdrConfig(QuadSPI_Type *baseAddr,
                              const Qspi_Ip_ControllerConfigType *userConfigPtr
                             )
{
    if (QSPI_IP_DATA_RATE_SDR == userConfigPtr->dataRate)
    {
        QSPI_DDR_Disable(baseAddr);
        /* Ignore output data align setting in SDR mode */
        Qspi_Ip_SetDataInHoldTime(baseAddr, QSPI_IP_FLASH_DATA_ALIGN_REFCLK);
    }
    else  /* QSPI_IP_DATA_RATE_DDR */
    {
        QSPI_DDR_Enable(baseAddr);
        Qspi_Ip_SetDataInHoldTime(baseAddr, userConfigPtr->dataAlign);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureReadOptions
 * Description   : Configures data read settings
 *                 Qspi_Ip_ConfigureReadOptions_Activity */
static void Qspi_Ip_ConfigureReadOptions(QuadSPI_Type *baseAddr,
                                         const Qspi_Ip_ControllerConfigType *userConfigPtr
                                        )
{
    /* Always enable DQS */
    QSPI_DQS_Enable(baseAddr);

    Qspi_Ip_DqsOutEnable(baseAddr, userConfigPtr->dqsAsAnOutput);

    Qspi_Ip_DdrConfig(baseAddr, userConfigPtr);

    /* select DQS A source (internal/loopback/external) */
    Qspi_Ip_SetDQSSourceA(baseAddr, userConfigPtr->readModeA);

    /* Select DLL tap in SMPR register */
    Qspi_Ip_SetRxDLLTapA(baseAddr, userConfigPtr->dllSettingsA.tapSelect);

    if (TRUE == Qspi_Ip_IsSideAvailableB(userConfigPtr))
    {
        /* Select DQS B source (internal/loopback/external) */
        Qspi_Ip_SetDQSSourceB(baseAddr, userConfigPtr->readModeB);

        /* Select DLL tap in SMPR register */
        Qspi_Ip_SetRxDLLTapB(baseAddr, userConfigPtr->dllSettingsB.tapSelect);
    }

    (void)userConfigPtr;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SetAhbBuf
 * Description   : Sets up AHB buffer 0 buffer 1 and buffer 2
 */
static void Qspi_Ip_SetAhbBuf(uint32 instance,
                              const Qspi_Ip_ControllerAhbConfigType *config
                             )
{
    QuadSPI_Type *baseAddr;
    /* Get base address of instance */
    baseAddr = Qspi_Ip_BaseAddress[instance];
    /* Set AHB buffer 0 */
    Qspi_Ip_SetAhbBuf0(baseAddr, config->sizes[0U], config->masters[0U]);
    /* Set AHB buffer 1 */
    Qspi_Ip_SetAhbBuf1(baseAddr, config->sizes[1U], config->masters[1U]);
    /* Set AHB buffer 2 */
    Qspi_Ip_SetAhbBuf2(baseAddr, config->sizes[2U], config->masters[2U]);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_AhbSetup
 * Description   : Sets up AHB accesses to the serial flash
 *                 Qspi_Ip_AhbSetup_Activity */
static Qspi_Ip_StatusType Qspi_Ip_AhbSetup(uint32 instance,
                                           const Qspi_Ip_ControllerAhbConfigType *config
                                          )
{
    QuadSPI_Type *baseAddr;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QuadSPI_INSTANCE_COUNT);
    DEV_ASSERT_QSPI(0U == (config->sizes[0U] & 7U));
    DEV_ASSERT_QSPI(((uint32)config->sizes[0U] +
               (uint32)config->sizes[1U] +
               (uint32)config->sizes[2U] +
               (uint32)config->sizes[3U]) <= FEATURE_QSPI_AHB_BUF_SIZE);
#endif

    /* Get base address of instance */
    baseAddr = Qspi_Ip_BaseAddress[instance];

    /* configure AHB transfer sizes to match the buffer sizes */
    /* Sets up AHB buffer 0 buffer 1 and buffer 2 */
    (void)Qspi_Ip_SetAhbBuf(instance, config);
    /* Set AHB buffer 3 */
    Qspi_Ip_SetAhbBuf3(baseAddr, config->sizes[3U], config->masters[3U], config->allMasters);
    /* Set AHB buffer index 0 */
    Qspi_Ip_SetAhbBuf0Ind(baseAddr, (uint32)config->sizes[0U]);
    /* Set AHB buffer index 1 */
    Qspi_Ip_SetAhbBuf1Ind(baseAddr, (uint32)config->sizes[0U] + (uint32)config->sizes[1U]);
    /* Set AHB buffer index 2 */
    Qspi_Ip_SetAhbBuf2Ind(baseAddr, (uint32)config->sizes[0U] + (uint32)config->sizes[1U] + (uint32)config->sizes[2U]);

    return STATUS_QSPI_IP_SUCCESS;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Program the SFAR & IPCR registers.
 *
 * @param[in] BaseAddress base address of the given QuadSPI instance
 * @param[in] Address address to be written into SFAR
 * @param[in] DataSize data size to be written into IPCR
 * @param[in] SeqId sequence id where the command is stored in the physical lut
 *
 * @retval STATUS_QSPI_IP_SUCCESS SFAR and IPCR writes passed the MDAD checks
 * @retval STATUS_QSPI_IP_ERROR a common or a queue error has occurred
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static void Qspi_Ip_NewIpsTransaction(QuadSPI_Type *BaseAddress,
                                      uint32 Address,
                                      uint16 DataSize,
                                      uint8 SeqId
                                     )
{
    #if (FEATURE_QSPI_HAS_SFP == 1)
    Qspi_Ip_Sfp_ClearLatchedErrors(BaseAddress);
    #endif

    Qspi_Ip_SetIpAddr(BaseAddress, Address);
    Qspi_Ip_IpTrigger(BaseAddress, SeqId, DataSize);
}

#if (FEATURE_QSPI_HAS_SFP == 1)

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Clear the errors latched in SFP registers.
 *
 * Error Status (ERRSTAT):
 * - FRADn Access Error (FRADnACC)
 * - No FRAD Match Error (FRADMTCH)
 * FlashSeq Request (FLSEQREQ):
 * - Clear (CLR)
 * IPS Error (IPSERROR):
 * - Clear (CLR)
 * Target Group n SFAR Status (TG0SFARS - TG1SFARS):
 * - Clear (CLR)
 * Target Group n IPCR Status (TG0IPCRS - TG1IPCRS):
 * - Clear (CLR)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Qspi_Ip_Sfp_ClearLatchedErrors_Privileged(QuadSPI_Type *BaseAddr)
{
    BaseAddr->ERRSTAT  |= 0x1FFUL;
    BaseAddr->FLSEQREQ |= QuadSPI_FLSEQREQ_CLR_MASK;
    BaseAddr->IPSERROR |= QuadSPI_IPSERROR_CLR_MASK;

    for (uint32 Mdad = 0U; Mdad < QuadSPI_MDAD_COUNT; Mdad++)
    {
        BaseAddr->MDAD[Mdad].TGSFARS |= QuadSPI_TGSFARS_CLR_MASK;
        BaseAddr->MDAD[Mdad].TGIPCRS |= QuadSPI_TGIPCRS_CLR_MASK;
    }
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Wait for the current transaction to reach a given state
 *
 * @param[in] BaseAddress base address of the given QuadSPI instance
 * @param[in] State the STATE field value that is to be expected
 *
 * @retval STATUS_QSPI_IP_SUCCESS
 * @retval STATUS_QSPI_IP_TIMEOUT
 * @retval STATUS_QSPI_IP_ERROR
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static Qspi_Ip_StatusType Qspi_Ip_Sfp_WaitFsmState(QuadSPI_Type const * BaseAddress,
                                                   uint32 State
                                                  )
{
    Qspi_Ip_StatusType Status = STATUS_QSPI_IP_ERROR;
    uint32 FsmStat;
    uint32 FsmStatValid;
    uint32 FsmStatState;

    uint32 ElapsedTicks = 0U;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(QSPI_IP_QSPI_IDLE_TIMEOUT, QSPI_IP_TIMEOUT_TYPE);;
    uint32 CurrentTicks = OsIf_GetCounter(QSPI_IP_TIMEOUT_TYPE);;

    do
    {
        FsmStat      = BaseAddress->FSMSTAT;
        FsmStatValid = (FsmStat & QuadSPI_FSMSTAT_VLD_MASK);
        FsmStatState = (FsmStat & QuadSPI_FSMSTAT_STATE_MASK) >> QuadSPI_FSMSTAT_STATE_SHIFT;
        if ((FsmStatValid != 0U) && (FsmStatState == State))
        {
            Status = STATUS_QSPI_IP_SUCCESS;
            break;
        }

        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, QSPI_IP_TIMEOUT_TYPE);
    } while (ElapsedTicks < TimeoutTicks);

    if (ElapsedTicks >= TimeoutTicks)
    {
        Status = STATUS_QSPI_IP_TIMEOUT;
    }

    return Status;
}

#endif /* FEATURE_QSPI_HAS_SFP */

/*! @endcond */

/*******************************************************************************
 * Code
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_WriteLuts_Privileged
 * Description   : Configures pairs of LUT commands from the specified LUT register
 *
 *END**************************************************************************/
void Qspi_Ip_WriteLuts_Privileged(uint32 Instance,
                                  uint8 StartLutRegister,
                                  const uint32 *Data,
                                  uint8 Size
                                 )
{
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(Instance < QuadSPI_INSTANCE_COUNT);
    DEV_ASSERT_QSPI(StartLutRegister < QuadSPI_LUT_COUNT);
    DEV_ASSERT_QSPI(Size <= FEATURE_QSPI_LUT_SEQUENCE_SIZE);
    DEV_ASSERT_QSPI((StartLutRegister + Size) <= QuadSPI_LUT_COUNT);
#endif

    QuadSPI_Type *BaseAddr = Qspi_Ip_BaseAddress[Instance];
    uint8 Idx;

    for (Idx = 0U; Idx < Size; Idx++)
    {
        BaseAddr->LUT[StartLutRegister + Idx] = Data[Idx];
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SetAhbSeqId_Privileged
 * Description   : Sets sequence ID for AHB operations
 *
 *END**************************************************************************/
void Qspi_Ip_SetAhbSeqId_Privileged(uint32 instance,
                                    uint8 seqID
                                   )
{
    QuadSPI_Type *baseAddr;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QuadSPI_INSTANCE_COUNT);
#endif

    baseAddr = Qspi_Ip_BaseAddress[instance];
    baseAddr->BFGENCR =  QuadSPI_BFGENCR_SEQID(seqID);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SetSerialFlashAddr
 * Description   : Configure the Serial Flash Memory Address
 *
 *END**************************************************************************/
static inline void Qspi_Ip_SetSerialFlashAddress(QuadSPI_Type *baseAddr,
                                                 const Qspi_Ip_ControllerConfigType * userConfigPtr
                                                )
{
    Qspi_Ip_SetAddrOptions(baseAddr, userConfigPtr->columnAddr, userConfigPtr->wordAddresable);

    Qspi_Ip_SetByteSwap(baseAddr, userConfigPtr->byteSwap);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SetCsTime
 * Description   : Configure the CS holdtime and CS setup time
 *
 *END**************************************************************************/
static inline void Qspi_Ip_SetCsTime(QuadSPI_Type *baseAddr,
                                     const Qspi_Ip_ControllerConfigType * userConfigPtr
                                    )
{
    /* Configure the CS holdtime and CS setup time */
    Qspi_Ip_SetCsHoldTime(baseAddr, userConfigPtr->csHoldTime);
    Qspi_Ip_SetCsSetupTime(baseAddr, userConfigPtr->csSetupTime);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureBuffers
 * Description   : Configure the Tx, Rx and AHB buffers
 *
 *END**************************************************************************/
static inline void Qspi_Ip_ConfigureBuffers(uint32 instance,
                                            QuadSPI_Type *baseAddr,
                                            const Qspi_Ip_ControllerConfigType * userConfigPtr
                                           )
{
    Qspi_Ip_SetRxCfg(baseAddr, userConfigPtr->sampleDelay, userConfigPtr->samplePhase);
#ifdef QuadSPI_RBCT_RXBRD_MASK
    /* Read Rx buffer through RBDR registers */
    Qspi_Ip_SetRxBufReadout(baseAddr, QSPI_IP_RX_READOUT_IP);
#endif
    /* Set watermarks */
    Qspi_Ip_SetTxWatermark(baseAddr, 1U);
    Qspi_Ip_SetRxWatermark(baseAddr, 1U);
    /* Configure AHB buffers settings */
    (void)Qspi_Ip_AhbSetup(instance, &(userConfigPtr->ahbConfig));
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureControllerA
 * Description   : Configure for side A
 *
 *END**************************************************************************/
static inline void Qspi_Ip_ConfigureControllerA(uint32 instance,
                                                const Qspi_Ip_ControllerConfigType *userConfigPtr
                                               )
{
    QuadSPI_Type *baseAddr = Qspi_Ip_BaseAddress[instance];
    uint32 AhbAddress = Qspi_Ip_AhbAddress[instance];

    /* Configure external flash memory map Size A */
    Qspi_Ip_SetMemMapSizeA(AhbAddress, baseAddr, userConfigPtr->memSizeA1, userConfigPtr->memSizeA2);

    /* Configure idle line value side A */
    Qspi_Ip_SetIdleLineValuesA(baseAddr, userConfigPtr->io2IdleValueA, userConfigPtr->io3IdleValueA);

    /* Configure the center aligned strobe side A */
    Qspi_Ip_SetCenterAlignedStrobeA(baseAddr, userConfigPtr->centerAlignedStrobeA);

    /* Configure the differential clock side A */
    Qspi_Ip_SetDifferentialClockA(baseAddr, userConfigPtr->differentialClockA);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureControllerB
 * Description   : Configure for side B
 *
 *END**************************************************************************/
static inline void Qspi_Ip_ConfigureControllerB(uint32 instance,
                                                const Qspi_Ip_ControllerConfigType *userConfigPtr
                                               )
{
    /* Check Size B is available */
    if (TRUE == Qspi_Ip_IsSideAvailableB(userConfigPtr))
    {
        QuadSPI_Type *baseAddr = Qspi_Ip_BaseAddress[instance];
        /* Configure external flash memory map Side B,
           the end address of side B must be greater than or equal to the end address of side A2
        */
        Qspi_Ip_SetMemMapSizeB(baseAddr, userConfigPtr->memSizeB1, userConfigPtr->memSizeB2);
        /* Unused side lines are "no matter" so just repeat idle settings on both sides */
        Qspi_Ip_SetIdleLineValuesB(baseAddr, userConfigPtr->io2IdleValueB, userConfigPtr->io3IdleValueB);

        /* Configure the center aligned strobe Side B */
        Qspi_Ip_SetCenterAlignedStrobeB(baseAddr, userConfigPtr->centerAlignedStrobeB);

        /* Configure the differential clock Side B */
        Qspi_Ip_SetDifferentialClockB(baseAddr, userConfigPtr->differentialClockB);
    }
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureControllerRegisters
 * Description   : Configure the controller A and B registers following user configurations
 *
 *END**************************************************************************/
static inline void Qspi_Ip_ConfigureControllerRegisters(uint32 instance,
                                                        const Qspi_Ip_ControllerConfigType *userConfigPtr
                                                       )
{
    Qspi_Ip_ConfigureControllerA(instance, userConfigPtr);

    Qspi_Ip_ConfigureControllerB(instance, userConfigPtr);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureController
 * Description   : Configure the controller register following user configurations
 *
 *END**************************************************************************/
static inline void Qspi_Ip_ConfigureController(uint32 instance,
                                               const Qspi_Ip_ControllerConfigType *userConfigPtr
                                              )
{
    QuadSPI_Type *baseAddr = Qspi_Ip_BaseAddress[instance];

    Qspi_Ip_ConfigureControllerRegisters(instance, userConfigPtr);
    /* Configure the Serial Flash Memory Address */
    Qspi_Ip_SetSerialFlashAddress(baseAddr, userConfigPtr);

    /* Configure the CS holdtime and CS setup time */
    Qspi_Ip_SetCsTime(baseAddr, userConfigPtr);

    /* Configure buffers */
    Qspi_Ip_ConfigureBuffers(instance, baseAddr, userConfigPtr);

    /* Configure read options */
    Qspi_Ip_ConfigureReadOptions(baseAddr, userConfigPtr);

    /* Configure chip-specific options */
    Qspi_Ip_ConfigureChipOptions(baseAddr, userConfigPtr);

    #if (FEATURE_QSPI_HAS_SFP == 1)
    Qspi_Ip_Sfp_Configure(baseAddr, userConfigPtr);
    #endif
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ControllerInit
 * Description   : Initializes the qspi controller
 * @implements     Qspi_Ip_ControllerInit_Activity */
Qspi_Ip_StatusType Qspi_Ip_ControllerInit(uint32 instance,
                                          const Qspi_Ip_ControllerConfigType * userConfigPtr
                                         )
{
    QuadSPI_Type *baseAddr;
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QuadSPI_INSTANCE_COUNT);
    DEV_ASSERT_QSPI(userConfigPtr != NULL_PTR);
#endif

    /* Start of exclusive area */
    SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_09();

#if (QSPI_IP_CHECK_CFG_CRC == STD_ON)
    status = Qspi_Ip_ValidateCtrlCfgCRC(userConfigPtr);
    if (STATUS_QSPI_IP_SUCCESS == status)
#endif
    {
        /* Initialize driver status structure */
        baseAddr = Qspi_Ip_BaseAddress[instance];

        /* Ensure module is disabled */
        Qspi_Ip_Disable(baseAddr);

        /* Ensure all registers contain their reset value */
        Qspi_Ip_ResetAllRegisters(baseAddr);

        /* Configure the controller following the user configurations */
        Qspi_Ip_ConfigureController(instance, userConfigPtr);

        /* Enable QuadSPI module */
        Qspi_Ip_Enable(baseAddr);

        /* Reset serial flash and AHB domains */
        Qspi_Ip_SwReset(baseAddr);

        /* Store user configuration for runtime usage */
        Qspi_Ip_ControllerConfig[instance] = userConfigPtr;
        /* Configure the DLL */
        status = Qspi_Ip_ConfigureDLL(instance, userConfigPtr);

        /* Workaround to clear CRC and ECC errors flags */
        baseAddr->FR = (uint32)0xFFFFFFFFUL;
    }
    /* End of exclusive area */
    SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_09();

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ControllerDeinit
 * Description   : De-initialize the qspi driver
 * @implements     Qspi_Ip_ControllerDeinit_Activity */
Qspi_Ip_StatusType Qspi_Ip_ControllerDeinit(uint32 instance)
{
    QuadSPI_Type *baseAddr;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QuadSPI_INSTANCE_COUNT);
#endif

    /* Start of exclusive area */
    SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_10();

    baseAddr = Qspi_Ip_BaseAddress[instance];

    /* Disable QuadSPI module */
    Qspi_Ip_Disable(baseAddr);

    /* Detach the configuration pointer */
    Qspi_Ip_ControllerConfig[instance] = NULL_PTR;

    /* End of exclusive area */
    SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_10();

    return STATUS_QSPI_IP_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_Abort
 * Description   : Force the Qspi controller to cancel any on-going transactions by performing the software reset requence.
 *                 This can be used to recover the hardware controller from being stuck in BUSY state.
 *                 Re-configure DLL is needed to avoid side-effects on the DLL after the S/W reset.
 */
Qspi_Ip_StatusType Qspi_Ip_Abort(uint32 instance)
{
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QuadSPI_INSTANCE_COUNT);
#endif

    QuadSPI_Type *baseAddr = Qspi_Ip_BaseAddress[instance];
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;

    /* Start of exclusive area */
    SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_07();

    /* Reset serial flash and AHB domains */
    Qspi_Ip_SwReset(baseAddr);

    /* S/W reset would also loose any Slave-chain upate, therefore re-configure DLL sequence is needed */
    if (Qspi_Ip_ControllerConfig[instance] != NULL_PTR)
    {
        /* Perform the DLL config only if the user configuration is available.
           Because there will be the case when user skip the controller configuration at initialization time.
         */
        status = Qspi_Ip_ConfigureDLL(instance, Qspi_Ip_ControllerConfig[instance]);
    }

    /* End of exclusive area */
    SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_07();

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_GetBaseAdress
 * Description   : Returns the physical base address of a flash device on the AHB bus.
 *                 The controller must be initialized prior to calling this function.
 * @implements     Qspi_Ip_GetBaseAdress_Activity */
uint32 Qspi_Ip_GetBaseAdress(uint32 instance,
                             Qspi_Ip_ConnectionType connectionType
                            )
{
    const QuadSPI_Type *baseAddr;
    uint32 address = 0U;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QuadSPI_INSTANCE_COUNT);
#endif

    /* get the base address base on the instance */
    baseAddr = Qspi_Ip_BaseAddress[instance];

    switch (connectionType)
    {
        case QSPI_IP_SIDE_A1:
            /* get base address of side A1 */
            address = Qspi_Ip_AhbAddress[instance];
            break;
        case QSPI_IP_SIDE_A2:
            /* get base address of side A2 */
            address = baseAddr->SFA1AD;
            break;
        case QSPI_IP_SIDE_B1:
            /* get base address of side B1 */
            address = baseAddr->SFA2AD;
            break;
        case QSPI_IP_SIDE_B2:
            /* get base address of side B2 */
            address = baseAddr->SFB1AD;
            break;
        default:
            ; /* Not possible */
            break;
    }

    return address;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_IpCommand
 * Description   : Launches a simple IP command
 * @implements     Qspi_Ip_IpCommand_Activity */
Qspi_Ip_StatusType Qspi_Ip_IpCommand(uint32 instance,
                                     uint8 SeqId,
                                     uint32 addr
                                    )
{
    QuadSPI_Type *baseAddr;
    Qspi_Ip_StatusType status;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QuadSPI_INSTANCE_COUNT);
    DEV_ASSERT_QSPI(SeqId < (QuadSPI_LUT_COUNT / FEATURE_QSPI_LUT_SEQUENCE_SIZE));
#endif

    baseAddr = Qspi_Ip_BaseAddress[instance];

    /* Reset AHB buffers to force re-read from memory after erase operation */
    status = Qspi_Ip_AhbFlush(baseAddr);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Launch the IP command */
        Qspi_Ip_NewIpsTransaction(baseAddr, addr, 0U, SeqId);

        /* Add Fault Injection point for FR_ILLINE flag */
        MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_IPCOMMAND);

        status = Qspi_Ip_CmdWaitComplete(instance);

        /* Make sure there is no garbage in Rx fifo in case of triggering a dummy READ instruction.
           This clears RBSR[RDBFL] to ensure QuadSPI is idle from SFP point of view and avoid the Master timeout error.
         */
        Qspi_Ip_ClearRxBuf(baseAddr);
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_CmdWaitComplete
 * Description   : Wait until Qspi controller is not busy or timeout
 */
static Qspi_Ip_StatusType Qspi_Ip_CmdWaitComplete(uint32 instance)
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint32  u32ElapsedTicks = 0UL;
    uint32  u32TimeoutTicks;
    uint32  u32CurrentTicks;

    /* Prepare timeout counter */
    u32TimeoutTicks = OsIf_MicrosToTicks(QSPI_IP_CMD_COMPLETE_TIMEOUT, QSPI_IP_TIMEOUT_TYPE);
    u32CurrentTicks = OsIf_GetCounter(QSPI_IP_TIMEOUT_TYPE);

    MCAL_FAULT_INJECTION_POINT(QSPI_IP_FMEA_WAIT_TRANSACTION_COMPLETE);

    /* Wait for command to be completed */
    do
    {
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, QSPI_IP_TIMEOUT_TYPE);
        status = Qspi_Ip_ControllerGetStatus(instance);
    }
    while ((u32ElapsedTicks < u32TimeoutTicks) && (STATUS_QSPI_IP_BUSY == status));

    if (STATUS_QSPI_IP_BUSY == status)
    {
        status = STATUS_QSPI_IP_TIMEOUT;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_IpRead
 * Description   : Launches an IP read command
 * @implements     Qspi_Ip_IpRead_Activity */
Qspi_Ip_StatusType Qspi_Ip_IpRead(uint32 instance,
                                  uint8 SeqId,
                                  uint32 addr,
                                  uint8 * dataRead,
                                  const uint8 * dataCmp,
                                  uint32 size
                                 )
{
    Qspi_Ip_StatusType status;
    QuadSPI_Type *baseAddr;
    uint32 padding;
    uint16 Idatsz = 0U;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QuadSPI_INSTANCE_COUNT);
    DEV_ASSERT_QSPI(SeqId < (QuadSPI_LUT_COUNT / FEATURE_QSPI_LUT_SEQUENCE_SIZE));
    DEV_ASSERT_QSPI(size <= FEATURE_QSPI_RX_BUF_SIZE);
#endif

    baseAddr = Qspi_Ip_BaseAddress[instance];
    padding  = (uint32)(Qspi_Ip_MemoryPadding[instance]);

    /* If size is odd, round up to even size; this is needed in octal DDR mode */
    Idatsz = (uint16)((size + 1U) & (~1U));

    /* Make sure there is no garbage in Rx fifo */
    Qspi_Ip_ClearRxBuf(baseAddr);

    Qspi_Ip_NewIpsTransaction(baseAddr, addr, Idatsz, SeqId);

    /* Add Fault Injection point for FR_ILLINE flag */
    MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_IPREAD);

    /* Wait until the command is sent */
    status = Qspi_Ip_CmdWaitComplete(instance);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Process received data */
        if (dataRead != NULL_PTR)
        {
            /* Normal read */
            status = Qspi_Ip_ProcessDataRead(dataRead, size, baseAddr, padding);
        }
        else if (dataCmp != NULL_PTR)
        {
            /* Verify */
            status = Qspi_Ip_ProcessDataVerify(dataCmp, size, baseAddr, padding);
        }
        else
        {
            /* Blank check */
            status = Qspi_Ip_ProcessDataBlankCheck(size, baseAddr, padding);
        }
    }

    /* Reset Rx fifo */
    Qspi_Ip_ClearRxBuf(baseAddr);

    /* Clear padding, only needed for the first read */
    Qspi_Ip_MemoryPadding[instance] = 0U;

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_InvalidateTxBuf
 * Description   : Invalidates the TX buffer content and wait until it is completed or timed out
 *                 Qspi_Ip_InvalidateTxBuf_Activity */
static inline void Qspi_Ip_InvalidateTxBuf(uint32 instance)
{
    QuadSPI_Type *baseAddr = Qspi_Ip_BaseAddress[instance];
    volatile uint32 u32CurrentTicks;

    /* Start TX FIFO reset */
    Qspi_Ip_ClearTxBuf(baseAddr);

    /* Prepare timeout counter */
    u32CurrentTicks = QSPI_IP_TX_BUFFER_RESET_DELAY;
    /* Insert delay to ensure TX FIFO reset is complete */
    while (u32CurrentTicks > 0U)
    {
        u32CurrentTicks--;
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_PadTxBuf
 * Description   : Pad Tx buffer up to a minimum number of entries required
 *                 by the device for transmission to start
 *
 *END**************************************************************************/
static void Qspi_Ip_PadTxBuf(const QuadSPI_Type *baseAddr)
{
    /* Remove unused variable */
    (void)baseAddr;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_IpWritePrepare
 * Description   : Reset AHB buffers and check no garbage in Tx
 */
static Qspi_Ip_StatusType Qspi_Ip_IpWritePrepare(uint32 instance)
{
    QuadSPI_Type *baseAddr;
    baseAddr = Qspi_Ip_BaseAddress[instance];
    Qspi_Ip_StatusType status;
    /* Reset AHB buffers to force re-read from memory after write operation */
    status = Qspi_Ip_AhbFlush(baseAddr);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Ensure there is no garbage in Tx FIFO */
        Qspi_Ip_InvalidateTxBuf(instance);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_TxBufPrepare
 * Description   : Fill Tx buffer and Pad Tx buffer up to the minimum number of entries required by the device.
 */
static void Qspi_Ip_TxBufPrepare(QuadSPI_Type *baseAddr,
                                 const uint8 *data,
                                 uint32 size,
                                 uint32 padding
                                )
{
    /* Fill Tx buffer */
    Qspi_Ip_FillTxBuf(baseAddr, data, size, padding);

    /* Pad Tx buffer up to the minimum number of entries required by the device */
    Qspi_Ip_PadTxBuf(baseAddr);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_IpWriteSfp
 * Description   : Launches an IP write command with sfp
 */
static Qspi_Ip_StatusType Qspi_Ip_IpWriteSfp(uint32 instance,
                                             uint8 SeqId,
                                             uint32 addr,
                                             const uint8 * data,
                                             uint32 size
                                            )
{
    QuadSPI_Type *baseAddr;
    Qspi_Ip_StatusType status;
    uint32 padding;
    uint16 TotalSize = 0U;

    baseAddr = Qspi_Ip_BaseAddress[instance];
    /* Reset AHB buffers and check no garbage in Tx */
    status = Qspi_Ip_IpWritePrepare(instance);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        padding = Qspi_Ip_MemoryPadding[instance];
        TotalSize = (uint16)(size + (padding >> 4U) + (padding & 0x0FU));
        /* Check total data size need to be written is aligned with 4-bytes to avoid invalid value when setup watermark */
        if (((TotalSize % 4U) != 0U) && (TotalSize > 4U))
        {
            TotalSize += (4U - (TotalSize % 4U));
        }
        Qspi_Ip_MemoryPadding[instance] = 0U;  /* Clear padding */

        /* Setup water mark according to the transfer size to avoid underrun issue. */
        Qspi_Ip_SetTxWatermark(baseAddr, (uint8)((FEATURE_QSPI_TX_BUF_SIZE / 4U) - ((TotalSize / 4U) - 1U)));

        Qspi_Ip_NewIpsTransaction(baseAddr, addr, TotalSize, SeqId);

        /* 01 - TBDR lock is open. QuadSPI considers IPS transfer. Master counter is started. */
        if (STATUS_QSPI_IP_SUCCESS == Qspi_Ip_Sfp_WaitFsmState(baseAddr, 1U))
        {
            /* Fill Tx buffer and Pad Tx buffer up to the minimum number of entries required by the device. */
            Qspi_Ip_TxBufPrepare(baseAddr, data, size, padding);

            MCAL_DATA_SYNC_BARRIER();
            MCAL_INSTRUCTION_SYNC_BARRIER();
            /* 10 - TX buffer filled above threshold. Write transfer is triggered. SEQID is written. */
            if (((baseAddr->FSMSTAT & QuadSPI_FSMSTAT_STATE_MASK) >> QuadSPI_FSMSTAT_STATE_SHIFT) == 2U)
            {
                /* Add Fault Injection point for FR_TBUF flag */
                MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_IPWRITE);

                /* Wait until the command is sent */
                status = Qspi_Ip_CmdWaitComplete(instance);
            }
        }
    }

    return status;
}




/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_IpWrite
 * Description   : Launches an IP write command
 * @implements     Qspi_Ip_IpWrite_Activity */
Qspi_Ip_StatusType Qspi_Ip_IpWrite(uint32 instance,
                                   uint8 SeqId,
                                   uint32 addr,
                                   const uint8 * data,
                                   uint32 size
                                  )
{
    Qspi_Ip_StatusType status;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI(instance < QuadSPI_INSTANCE_COUNT);
    DEV_ASSERT_QSPI(size <= (uint16)FEATURE_QSPI_TX_BUF_SIZE);
    DEV_ASSERT_QSPI(SeqId < (QuadSPI_LUT_COUNT / FEATURE_QSPI_LUT_SEQUENCE_SIZE));
    DEV_ASSERT_QSPI(data != NULL_PTR);
#endif

    /* Launches an IP write command with sfp */
    status = Qspi_Ip_IpWriteSfp(instance, SeqId, addr, data, size);

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ControllerGetStatus
 * Description   : Checks the status of the currently running IP command
 * @implements     Qspi_Ip_ControllerGetStatus_Activity */
Qspi_Ip_StatusType Qspi_Ip_ControllerGetStatus(uint32 instance)
{
    QuadSPI_Type *baseAddr;
    Qspi_Ip_StatusType status;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_QSPI((instance < QuadSPI_INSTANCE_COUNT));
#endif

    baseAddr = Qspi_Ip_BaseAddress[instance];

    MCAL_FAULT_INJECTION_POINT(QSPI_IP_FMEA_CONTROLLER_GET_STATUS);
    /* Check device for busy status */
    if (Qspi_Ip_GetBusyStatus(baseAddr))
    {
        status = STATUS_QSPI_IP_BUSY;
    }
    else
    {
        /* Check for errors reported by the QuadSPI */
        status = Qspi_Ip_ErrorCheck(baseAddr);
    }
    return status;
}

#if (FEATURE_QSPI_HAS_SFP == 1)

#if (QSPI_IP_SFP_ENABLE_GLOBAL == STD_ON)
#if (QSPI_IP_SFP_ENABLE_MDAD == STD_ON)
static void Qspi_Ip_Sfp_SetMdadConfig(QuadSPI_Type * baseAddr,
                                      uint8 MdadInstance,
                                      Qspi_Ip_ControllerConfigType const * userConfigPtr)
{
    /* Set Mdad config */
    Qspi_Ip_Sfp_SetTgSecureAttribute(baseAddr, MdadInstance, userConfigPtr->SfpCfg.Tg[MdadInstance].SecureAttribute);
    Qspi_Ip_Sfp_SetTgMaskType(baseAddr, MdadInstance, userConfigPtr->SfpCfg.Tg[MdadInstance].MaskType);
    Qspi_Ip_Sfp_SetTgMask(baseAddr, MdadInstance, userConfigPtr->SfpCfg.Tg[MdadInstance].Mask);
    Qspi_Ip_Sfp_SetTgDomainIdMatch(baseAddr, MdadInstance, userConfigPtr->SfpCfg.Tg[MdadInstance].DomainId);
    Qspi_Ip_Sfp_SetTgValid(baseAddr, MdadInstance, userConfigPtr->SfpCfg.Tg[MdadInstance].Valid);
}

#endif /* QSPI_IP_SFP_ENABLE_MDAD */
#if (QSPI_IP_SFP_ENABLE_FRAD == STD_ON)
static void Qspi_Ip_Sfp_SetFradConfig(QuadSPI_Type * baseAddr,
                                      uint8 MdadInstance,
                                      Qspi_Ip_ControllerConfigType const * userConfigPtr)
{
    /* Set Frad config */
    Qspi_Ip_Sfp_SetFradStartAddress(baseAddr, MdadInstance, userConfigPtr->SfpCfg.Frad[MdadInstance].StartAddress);
    Qspi_Ip_Sfp_SetFradEndAddress(baseAddr, MdadInstance, userConfigPtr->SfpCfg.Frad[MdadInstance].EndAddress);
    Qspi_Ip_Sfp_SetFradMd0Acp(baseAddr, MdadInstance, (uint8)userConfigPtr->SfpCfg.Frad[MdadInstance].Md0Acp);
    Qspi_Ip_Sfp_SetFradMd1Acp(baseAddr, MdadInstance, (uint8)userConfigPtr->SfpCfg.Frad[MdadInstance].Md1Acp);
    Qspi_Ip_Sfp_SetFradEaLock(baseAddr, MdadInstance, userConfigPtr->SfpCfg.Frad[MdadInstance].ExclusiveAccessLock);
    Qspi_Ip_Sfp_SetFradEaOwner(baseAddr, MdadInstance, userConfigPtr->SfpCfg.Frad[MdadInstance].ExclusiveAccessOwner);
    Qspi_Ip_Sfp_SetFradValid(baseAddr, MdadInstance, userConfigPtr->SfpCfg.Frad[MdadInstance].Valid);
}
#endif /* QSPI_IP_SFP_ENABLE_FRAD */
#endif /* QSPI_IP_SFP_ENABLE_GLOBAL */
/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Configure the SFP registers.
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] userConfigPtr QSPI controller configuration structure
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Qspi_Ip_Sfp_Configure_Privileged(QuadSPI_Type * baseAddr,
                                      Qspi_Ip_ControllerConfigType const * userConfigPtr)
{
    /* Workaround for K396: QSPI must be enabled in order to write into SFP registers */
    /* Enable QuadSPI module */
    Qspi_Ip_Enable(baseAddr);

    Qspi_Ip_Sfp_SetAccessControls(baseAddr, QSPI_IP_SFP_ALL, QSPI_IP_SFP_ENABLE_GLOBAL);
    Qspi_Ip_Sfp_SetAccessControls(baseAddr, QSPI_IP_SFP_MDAD, QSPI_IP_SFP_ENABLE_MDAD);
    Qspi_Ip_Sfp_SetAccessControls(baseAddr, QSPI_IP_SFP_FRAD, QSPI_IP_SFP_ENABLE_FRAD);

#if (QSPI_IP_SFP_ENABLE_GLOBAL == STD_ON)

#if (QSPI_IP_SFP_ENABLE_MDAD == STD_ON)
    for (uint8 Index = 0U; Index < QuadSPI_MDAD_COUNT; ++Index)
    {
        if (TRUE == userConfigPtr->SfpCfg.Tg[Index].Valid)
        {
            Qspi_Ip_Sfp_SetMdadConfig(baseAddr, Index, userConfigPtr);
        }
    }
#endif /* QSPI_IP_SFP_ENABLE_MDAD */

#if (QSPI_IP_SFP_ENABLE_FRAD == STD_ON)
    for (uint8 Index = 0U; Index < QuadSPI_FRAD_COUNT; ++Index)
    {
        if (TRUE == userConfigPtr->SfpCfg.Frad[Index].Valid)
        {
            Qspi_Ip_Sfp_SetFradConfig(baseAddr, Index, userConfigPtr);
        }
    }
#endif /* QSPI_IP_SFP_ENABLE_FRAD */

    Qspi_Ip_Sfp_SetMasterTimeout(baseAddr, userConfigPtr->SfpCfg.MasterTimeout);

#else
    (void)userConfigPtr;
#endif /* QSPI_IP_SFP_ENABLE_GLOBAL */

}

/**
 * Reset the registers the require privilege access for programming.
 */
void Qspi_Ip_ResetPrivilegedRegisters_Privileged(QuadSPI_Type *BaseAddr)
{
    uint8 cnt;

    /* reset BFGENCR register */
    BaseAddr->BFGENCR  = (uint32)0x00000000UL;

    /* reset LUT0 register */
    BaseAddr->LUT[0]   = (uint32)0x08180403UL;
    /* reset LUT1 register */
    BaseAddr->LUT[1]   = (uint32)0x24001C08UL;
    for (cnt = 2U; cnt < QuadSPI_LUT_COUNT; cnt++)
    {
        BaseAddr->LUT[cnt] = (uint32)0x00000000UL;
    }

    /* reset Secure Flash Protection registers */
    for (cnt = 0U; cnt < QuadSPI_FRAD_COUNT; ++cnt)
    {
        BaseAddr->FRAD[cnt].WORD0 = 0x00000000UL;
        BaseAddr->FRAD[cnt].WORD1 = 0x0000FFFFUL;
        BaseAddr->FRAD[cnt].WORD2 = 0x00000000UL;
        BaseAddr->FRAD[cnt].WORD3 = 0x00000000UL;
    }
    for (cnt = 0U; cnt < QuadSPI_MDAD_COUNT; ++cnt)
    {
        BaseAddr->MDAD[cnt].TGMDAD  = 0x00000000UL;
        BaseAddr->MDAD[cnt].TGSFARS = 0x00000000UL;
        BaseAddr->MDAD[cnt].TGIPCRS = 0x00000000UL;
    }
    BaseAddr->MGC      = 0xA8000000UL;
    BaseAddr->MRC      = 0x00000E07UL;
    BaseAddr->MTO      = 0x0000FFFFUL;
    BaseAddr->FLSEQREQ = 0x20000000UL;
    BaseAddr->IPSERROR = 0x20000000UL;
    BaseAddr->ERRSTAT  = 0x000001FFUL;
    BaseAddr->INT_EN   = 0x00000000UL;
}

#endif /* FEATURE_QSPI_HAS_SFP */

/*
 * Set all hardware registers to their reset value
 */
static inline void Qspi_Ip_ResetAllRegisters(QuadSPI_Type *BaseAddr)
{
    uint8 cnt = 0U;

    /* reset MCR register */
    BaseAddr->MCR      = (uint32)0x000F404CUL;
    /* reset FLSHCR register */
    BaseAddr->FLSHCR   = (uint32)0x00000303UL;
    /* reset BUF0CR register */
    BaseAddr->BUF0CR   = (uint32)0x00000000UL;
    /* reset BUF1CR register */
    BaseAddr->BUF1CR   = (uint32)0x00000001UL;
    /* reset BUF2CR register */
    BaseAddr->BUF2CR   = (uint32)0x00000002UL;
    /* reset BUF3CR register */
    BaseAddr->BUF3CR   = (uint32)0x80000003UL;
    /* reset BUF0IND register */
    BaseAddr->BUF0IND  = (uint32)0x00000000UL;
    /* reset BUF1IND register */
    BaseAddr->BUF1IND  = (uint32)0x00000000UL;
    /* reset BUF2IND register */
    BaseAddr->BUF2IND  = (uint32)0x00000000UL;
    /* reset AWRCR register */
    BaseAddr->AWRCR    = (uint32)0x00000000UL;
    /* reset DLLCRA register */
    BaseAddr->DLLCRA   = (uint32)0x01200000UL;
    /* reset DLLCRB register */
    BaseAddr->DLLCRB   = (uint32)0x01200000UL;
    /* reset PARITYCR register */
    BaseAddr->PARITYCR = (uint32)0x00000000UL;
    /* reset SFACR register */
    BaseAddr->SFACR    = (uint32)0x00000800UL;
    /* reset SMPR register */
    BaseAddr->SMPR     = (uint32)0x00000000UL;
    /* reset RBCT register */
    BaseAddr->RBCT     = (uint32)0x00000000UL;
    /* reset DLCR register */
    BaseAddr->DLCR     = (uint32)0x40FF40FFUL;
    /* reset TBCT register */
    BaseAddr->TBCT     = (uint32)0x00000000UL;
    /* reset FR register, Write 1 to clear */
    BaseAddr->FR       = (uint32)0x9D83FF41UL;
    /* reset RSER register */
    BaseAddr->RSER     = (uint32)0x00000000UL;
    /* reset SPTRCLR register and clear both IP and AHB sequence pointers */
    BaseAddr->SPTRCLR  = (uint32)0x01000000UL | (uint32)QuadSPI_SPTRCLR_BFPTRC_MASK | (uint32)QuadSPI_SPTRCLR_IPPTRC_MASK;
    /* reset SFA1AD register */
    BaseAddr->SFA1AD   = (IP_QUADSPI_0 == BaseAddr) ? ((uint32)0x08000000UL) : ((uint32)0x14000000UL);
    /* reset SFA2AD register */
    BaseAddr->SFA2AD   = (IP_QUADSPI_0 == BaseAddr) ? ((uint32)0x08000000UL) : ((uint32)0x14000000UL);
    /* On ZSE, QSPI_0 does not have side B */
    if (IP_QUADSPI_0 != BaseAddr)
    {
        /* reset SFB1AD register */
        BaseAddr->SFB1AD   = (uint32)0x18000000UL;
        /* reset SFB2AD register */
        BaseAddr->SFB2AD   = (uint32)0x18000000UL;
    }
    /* reset DLPR register */
    BaseAddr->DLPR     = (uint32)0xAA553443UL;
    /* reset LUTKEY register */
    BaseAddr->LUTKEY   = (uint32)0x5AF05AF0UL;
    /* reset LCKCR register */
    BaseAddr->LCKCR    = (uint32)0x00000002UL;

    Qspi_Ip_ResetPrivilegedRegisters(BaseAddr);

    /* avoid warning unused variable */
    (void)cnt;
}

#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

#endif /* (QSPI_IP_MEM_INSTANCE_COUNT > 0) */


#ifdef __cplusplus
}
#endif

/** @} */

