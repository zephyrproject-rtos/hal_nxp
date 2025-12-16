/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file Xspi_Ip_Controller.c
*
*   @addtogroup IPV_XSPI XSPI IPV Driver
*   @{
*/

/* implements Xspi_Ip_Controller.c_Artifact */

#ifdef __cplusplus
extern "C"{
#endif

#include "OsIf.h"
#include "Xspi_Ip.h"
#include "Xspi_Ip_Controller.h"
#include "Xspi_Ip_HwAccess.h"
#include "SchM_Mem_43_EXFLS.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define XSPI_IP_CONTROLLER_VENDOR_ID_C                       43
#define XSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C        4
#define XSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C        9
#define XSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_C     0
#define XSPI_IP_CONTROLLER_SW_MAJOR_VERSION_C                0
#define XSPI_IP_CONTROLLER_SW_MINOR_VERSION_C                8
#define XSPI_IP_CONTROLLER_SW_PATCH_VERSION_C                0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((XSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (XSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Xspi_Ip_Controller.c and Mcal.h are different"
    #endif

    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((XSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (XSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Xspi_Ip_Controller.c and OsIf.h are different"
    #endif
#endif

/* Check if current file and Xspi_Ip_Controller header file are of the same vendor */
#if (XSPI_IP_CONTROLLER_VENDOR_ID_C != XSPI_IP_CONTROLLER_VENDOR_ID_H)
    #error "Xspi_Ip_Controller.c and Xspi_Ip_Controller.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Controller header file are of the same Autosar version */
#if ((XSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C    != XSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C    != XSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_C != XSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_Controller.c and Xspi_Ip_Controller.h are different"
#endif
/* Check if current file and Xspi_Ip_Controller header file are of the same Software version */
#if ((XSPI_IP_CONTROLLER_SW_MAJOR_VERSION_C != XSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_CONTROLLER_SW_MINOR_VERSION_C != XSPI_IP_CONTROLLER_SW_MINOR_VERSION_H) || \
     (XSPI_IP_CONTROLLER_SW_PATCH_VERSION_C != XSPI_IP_CONTROLLER_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip_Controller.c and Xspi_Ip_Controller.h are different"
#endif

/* Check if current file and Xspi_Ip_HwAccess header file are of the same vendor */
#if (XSPI_IP_CONTROLLER_VENDOR_ID_C != XSPI_IP_HW_ACCESS_VENDOR_ID_H)
    #error "Xspi_Ip_Controller.c and Xspi_Ip_HwAccess.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_HwAccess header file are of the same Autosar version */
#if ((XSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C    != XSPI_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C    != XSPI_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_C != XSPI_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_Controller.c and Xspi_Ip_HwAccess.h are different"
#endif
/* Check if current file and Xspi_Ip_HwAccess header file are of the same Software version */
#if ((XSPI_IP_CONTROLLER_SW_MAJOR_VERSION_C != XSPI_IP_HW_ACCESS_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_CONTROLLER_SW_MINOR_VERSION_C != XSPI_IP_HW_ACCESS_SW_MINOR_VERSION_H) || \
     (XSPI_IP_CONTROLLER_SW_PATCH_VERSION_C != XSPI_IP_HW_ACCESS_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip_Controller.c and Xspi_Ip_HwAccess.h are different"
#endif

/* Check if current file and Xspi_Ip header file are of the same vendor */
#if (XSPI_IP_CONTROLLER_VENDOR_ID_C != XSPI_IP_VENDOR_ID_H)
    #error "Xspi_Ip_Controller.c and Xspi_Ip.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip header file are of the same Autosar version */
#if ((XSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C    != XSPI_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C    != XSPI_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_C != XSPI_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_Controller.c and Xspi_Ip.h are different"
#endif
/* Check if current file and Xspi_Ip header file are of the same Software version */
#if ((XSPI_IP_CONTROLLER_SW_MAJOR_VERSION_C != XSPI_IP_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_CONTROLLER_SW_MINOR_VERSION_C != XSPI_IP_SW_MINOR_VERSION_H) || \
     (XSPI_IP_CONTROLLER_SW_PATCH_VERSION_C != XSPI_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip_Controller.c and Xspi_Ip.h are different"
#endif

#if (XSPI_IP_MEM_INSTANCE_COUNT > 0)

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#if (XSPI_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)

#define Xspi_Ip_Sfp_Configure(instance, userConfigPtr)      OsIf_Trusted_Call2params(Xspi_Ip_Sfp_Configure_Privileged, instance, userConfigPtr)
#define Xspi_Ip_Sfp_Lock(instance, userConfigPtr)           OsIf_Trusted_Call2params(Xspi_Ip_Sfp_Lock_Privileged, instance, userConfigPtr)
#define Xspi_Ip_GlobaConfigurationLock(instance)            OsIf_Trusted_Call1param(Xspi_Ip_GlobaConfigurationLock_Privileged, instance)
#define Xspi_Ip_Sfp_Disable(instance)                       OsIf_Trusted_Call1param(Xspi_Ip_Sfp_Disable_Privileged, instance)
#define Xspi_Ip_ResetPrivilegedRegisters(baseAddr)          OsIf_Trusted_Call1param(Xspi_Ip_ResetPrivilegedRegisters_Privileged, baseAddr)
#define Xspi_Ip_ClearStatus(baseAddr)                       OsIf_Trusted_Call1param(Xspi_Ip_ClearStatus_Privileged, baseAddr)

#else /* XSPI_IP_ENABLE_USER_MODE_SUPPORT */

#define Xspi_Ip_Sfp_Configure(instance, userConfigPtr)      Xspi_Ip_Sfp_Configure_Privileged(instance, userConfigPtr)
#define Xspi_Ip_Sfp_Lock(instance, userConfigPtr)           Xspi_Ip_Sfp_Lock_Privileged(instance, userConfigPtr)
#define Xspi_Ip_GlobaConfigurationLock(instance)            Xspi_Ip_GlobaConfigurationLock_Privileged(instance)
#define Xspi_Ip_Sfp_Disable(instance)                       Xspi_Ip_Sfp_Disable_Privileged(instance)
#define Xspi_Ip_ResetPrivilegedRegisters(baseAddr)          Xspi_Ip_ResetPrivilegedRegisters_Privileged(baseAddr)
#define Xspi_Ip_ClearStatus(baseAddr)                       Xspi_Ip_ClearStatus_Privileged(baseAddr)

#endif /* XSPI_IP_ENABLE_USER_MODE_SUPPORT */

#define XSPI_FR_ERR_FLAGS_MASK     (XSPI_REG(FR_DLPFF_MASK) | \
                                    XSPI_REG(FR_DLLABRT_MASK) | \
                                    XSPI_REG(FR_TBUF_MASK) | \
                                    XSPI_REG(FR_RBOF_MASK) | \
                                    XSPI_REG(FR_CRCAEF_MASK) | \
                                    XSPI_REG(FR_IPIEF_MASK))

#define XSPI_ERRSTAT_ERR_FLAGS_MASK        (XSPI_REG(ERRSTAT_FRADMTCH_MASK)   | \
                                            XSPI_REG(ERRSTAT_FRAD0ACC_MASK)   | \
                                            XSPI_REG(ERRSTAT_FRAD1ACC_MASK)   | \
                                            XSPI_REG(ERRSTAT_FRAD2ACC_MASK)   | \
                                            XSPI_REG(ERRSTAT_FRAD3ACC_MASK)   | \
                                            XSPI_REG(ERRSTAT_FRAD4ACC_MASK)   | \
                                            XSPI_REG(ERRSTAT_FRAD5ACC_MASK)   | \
                                            XSPI_REG(ERRSTAT_FRAD6ACC_MASK)   | \
                                            XSPI_REG(ERRSTAT_FRAD7ACC_MASK)   | \
                                            XSPI_REG(ERRSTAT_IPS_ERR_MASK)    | \
                                            XSPI_REG(ERRSTAT_TG0SFAR_MASK)    | \
                                            XSPI_REG(ERRSTAT_TG0IPCR_MASK)    | \
                                            XSPI_REG(ERRSTAT_TO_ERR_MASK)     | \
                                            XSPI_REG(ERRSTAT_TG1SFAR_MASK)    | \
                                            XSPI_REG(ERRSTAT_TG1IPCR_MASK)    | \
                                            XSPI_REG(ERRSTAT_ARB_LOCK_TO_MASK))


#define XSPI_ERRSTAT_CLR_FLAGS_MASK        (XSPI_REG(ERRSTAT_FRADMTCH_MASK)   | \
                                            XSPI_REG(ERRSTAT_FRAD0ACC_MASK)   | \
                                            XSPI_REG(ERRSTAT_FRAD1ACC_MASK)   | \
                                            XSPI_REG(ERRSTAT_FRAD2ACC_MASK)   | \
                                            XSPI_REG(ERRSTAT_FRAD3ACC_MASK)   | \
                                            XSPI_REG(ERRSTAT_FRAD4ACC_MASK)   | \
                                            XSPI_REG(ERRSTAT_FRAD5ACC_MASK)   | \
                                            XSPI_REG(ERRSTAT_FRAD6ACC_MASK)   | \
                                            XSPI_REG(ERRSTAT_FRAD7ACC_MASK)   | \
                                            XSPI_REG(ERRSTAT_TO_ERR_MASK)     | \
                                            XSPI_REG(ERRSTAT_ARB_WIN_MASK))

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*! @cond DRIVER_INTERNAL_USE_ONLY */

#define MEM_43_EXFLS_START_SEC_CONST_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"

/* Table of base addresses for XSPI instances. */
XSPI_Type * const Xspi_Ip_BaseAddress[XSPI_REG(INSTANCE_COUNT)] = { IP_XSPI };
/* Table of AHB addresses for XSPI instances. */
const uint32 Xspi_Ip_AhbAddress[XSPI_REG(INSTANCE_COUNT)] = XSPI_AHB_PTRS;

#define MEM_43_EXFLS_STOP_SEC_CONST_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"

#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_32
#include "MEM_43_EXFLS_MemMap.h"

/* Pointer to runtime configuration structures (storing the DLL configuration for runtime usage) */
static const Xspi_Ip_ControllerConfigType * Xspi_Ip_ControllerConfigPtr[XSPI_REG(INSTANCE_COUNT)];

#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_32
#include "MEM_43_EXFLS_MemMap.h"

#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_8
#include "Mem_43_EXFLS_MemMap.h"

/*
  The padding bytes information to handle unaligned read/write operation for XSPI:
   - For read:
        [7:0] the number of padding bytes to handle read from unaligned address
   - For write:
        [7:4] the number of pre-padding bytes to handle write from unaligned start address
        [3:0] the number of post-padding bytes to handle write from unaligned end address

  **Note: For platform has multi-instance, this needs to be implemented in different way.
*/
uint8 Xspi_Ip_MemoryPadding;

#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_8
#include "Mem_43_EXFLS_MemMap.h"

#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_32
#include "Mem_43_EXFLS_MemMap.h"

#if (XSPI_IP_CHECK_CFG_CRC == STD_ON)
/**
 * Pointer to current module configuration set
 */
static uint32 u32IpAccCRCRemainder;
#endif /* XSPI_IP_CHECK_CFG_CRC */

#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_32
#include "Mem_43_EXFLS_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

static Xspi_Ip_StatusType Xspi_Ip_ControllerGetArbStatus(XSPI_Type *baseAddr);

void Xspi_Ip_Sfp_Configure_Privileged(uint32 instance,
                                      Xspi_Ip_SfpConfigType const * userConfigPtr
                                     );
void Xspi_Ip_Sfp_Lock_Privileged(uint32 instance,
                                 Xspi_Ip_SfpConfigType const * userConfigPtr
                                );
void Xspi_Ip_GlobaConfigurationLock_Privileged(uint32 instance);
void Xspi_Ip_Sfp_Disable_Privileged(uint32 instance);
void Xspi_Ip_ResetPrivilegedRegisters_Privileged(XSPI_Type *baseAddr);

#if (XSPI_IP_CHECK_CFG_CRC == STD_ON)
static void Xspi_Ip_AccumulateCRC(uint32 InputData);
static void Xspi_Ip_ResetCRC(void);
static uint32 Xspi_Ip_FinalizeCRC(void);
static void Xspi_Ip_UpdateCRCreminder(Xspi_Ip_CrcDataSizeType DataSize);

static Xspi_Ip_CrcType Xspi_Ip_CalcMemCfgCRC(const Xspi_Ip_MemoryConfigType * pxConfig);
static Xspi_Ip_CrcType Xspi_Ip_CalcCntCfgCRC(const Xspi_Ip_MemoryConnectionType * pxConnect);
static Xspi_Ip_StatusType Xspi_Ip_ValidateCtrlCfgCRC(const Xspi_Ip_ControllerConfigType *UserConfigPtr);

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_WaitResetComplete
 */
static void Xspi_Ip_AccumulateCRC(uint32 InputData)
{
    if (0xFFFFU < InputData)
    {
        /* preparation for accumulation of higher 16 bits of the InputData */
        u32IpAccCRCRemainder = (u32IpAccCRCRemainder << 16U) | (InputData >> 16U);
        /* make 16-bit accumulated result (in lower 16-bits of u32IpAccCRCRemainder) */
        Xspi_Ip_UpdateCRCreminder(XSPI_IP_CRC_16_BITS);
    }

    if (0xFFU < InputData)
    {
        /* preparation for accumulation of lower 16 bits of the InputData */
        u32IpAccCRCRemainder = (u32IpAccCRCRemainder << 16U) | (InputData & 0x0000FFFFU);
        /* make 16-bit accumulated result (in lower 16-bits of u32IpAccCRCRemainder) */
        Xspi_Ip_UpdateCRCreminder(XSPI_IP_CRC_16_BITS);
    }
    else
    {
        /* optimization: only 8 LSB bits are processed */
        /* preparation for accumulation of lower 8 bits of the InputData */
        u32IpAccCRCRemainder = (u32IpAccCRCRemainder << 8U) | InputData;
        /* make 16-bit accumulated result (in lower 16-bits of u32IpAccCRCRemainder) */
        Xspi_Ip_UpdateCRCreminder(XSPI_IP_CRC_8_BITS);
    }
}

/**
 * @brief        Function to reset CRC calculation.
 *
 */
static void Xspi_Ip_ResetCRC(void)
{
    u32IpAccCRCRemainder = 0U;
}


static uint32 Xspi_Ip_FinalizeCRC(void)
{
    /* add the final 0x0000 to the remainder */
    u32IpAccCRCRemainder = (u32IpAccCRCRemainder << 16U);
    /* make the final 16-bit CRC */
    Xspi_Ip_UpdateCRCreminder(XSPI_IP_CRC_16_BITS);

    return u32IpAccCRCRemainder;
}


static void Xspi_Ip_UpdateCRCreminder(Xspi_Ip_CrcDataSizeType DataSize)
{
    uint32 CrcPolynomSft;
    uint32 LeadingOne;
    uint32 AccDataLoc;
    uint32 LeadingOneInitial;

    switch (DataSize)
    {
        case XSPI_IP_CRC_8_BITS:
            CrcPolynomSft = 0x11021U << 7U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            LeadingOneInitial = 0x10000U << 7U;
            break;

        case XSPI_IP_CRC_16_BITS:
        default:
            CrcPolynomSft = 0x11021U << 15U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            LeadingOneInitial = 0x10000U << 15U;
            break;
    }

    /* copy static variable to auto (computation over static may be slow) */
    AccDataLoc = u32IpAccCRCRemainder;

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
    u32IpAccCRCRemainder = AccDataLoc;
}
/* MemSerialFlashCfg */
static Xspi_Ip_CrcType Xspi_Ip_CalcMemCfgCRC(const Xspi_Ip_MemoryConfigType * pxConfig)
{
    uint32 Index;
    uint32 readIdXor = 0U;

    /* Reset the accumulated CRC value */
    Xspi_Ip_ResetCRC();

#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
    if (XSPI_IP_HYPER_RAM == pxConfig->memType)
    {
        if (NULL_PTR != pxConfig->hrConfig)
        {
            Xspi_Ip_AccumulateCRC((uint32) pxConfig->memSize);
            Xspi_Ip_AccumulateCRC((uint32) pxConfig->hrConfig->driveStrength);
            Xspi_Ip_AccumulateCRC((uint32) pxConfig->hrConfig->initialLatency);
            Xspi_Ip_AccumulateCRC((uint32) pxConfig->hrConfig->masterClockType);
            Xspi_Ip_AccumulateCRC((uint32) pxConfig->hrConfig->arrayRefresh);
            Xspi_Ip_AccumulateCRC((uint32) pxConfig->hrConfig->deviceIdWordAddress);
        }
    }
    else
#endif
    {
        /* CRC - Accumulate LUT settings */
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->memSize);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->pageSize);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->readLut);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->writeLut);

        Xspi_Ip_AccumulateCRC((uint32) pxConfig->readIdSettings.readIdLut);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->readIdSettings.readIdSize);
        for (Index = 0; Index < pxConfig->readIdSettings.readIdSize; Index++)
        {
            readIdXor ^= pxConfig->readIdSettings.readIdExpected[Index];
        }
        Xspi_Ip_AccumulateCRC(readIdXor);

        for (Index = 0; Index < XSPI_IP_ERASE_TYPES; Index++)
        {
            Xspi_Ip_AccumulateCRC((uint32) pxConfig->eraseSettings.eraseTypes[Index].eraseLut);
            Xspi_Ip_AccumulateCRC((uint32) pxConfig->eraseSettings.eraseTypes[Index].size);
        }
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->eraseSettings.chipEraseLut);

        Xspi_Ip_AccumulateCRC((uint32) pxConfig->statusConfig.statusRegReadLut);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->statusConfig.statusRegWriteLut);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->statusConfig.writeEnableLut);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->statusConfig.regSize);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->statusConfig.busyMask);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->statusConfig.busyValue);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->statusConfig.idleValue);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->statusConfig.clearErrLut);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->statusConfig.writeEnableOffset);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->statusConfig.blockProtectionOffset);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->statusConfig.blockProtectionWidth);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->statusConfig.blockProtectionValue);

        Xspi_Ip_AccumulateCRC((uint32) pxConfig->suspendSettings.eraseSuspendLut);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->suspendSettings.eraseResumeLut);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->suspendSettings.programSuspendLut);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->suspendSettings.programResumeLut);

        Xspi_Ip_AccumulateCRC((uint32) pxConfig->initResetSettings.resetCmdLut);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->initResetSettings.resetCmdCount);

        Xspi_Ip_AccumulateCRC((uint32) pxConfig->optionalLuts.OptionalLut1);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->optionalLuts.OptionalLut2);

        Xspi_Ip_AccumulateCRC((uint32) pxConfig->initConfiguration.opCount);
        Xspi_Ip_AccumulateCRC((uint32) pxConfig->lutSequences.opCount);
    }

    return ((Xspi_Ip_CrcType)Xspi_Ip_FinalizeCRC());
}
/* MemCfg */
static Xspi_Ip_CrcType Xspi_Ip_CalcCntCfgCRC(const Xspi_Ip_MemoryConnectionType * pxConnect)
{
    /* Reset the accumulated CRC value */
    Xspi_Ip_ResetCRC();

    /* CRC - Accumulate MemConnectionCfg */
    Xspi_Ip_AccumulateCRC((uint32) pxConnect->xspiInstance);
    Xspi_Ip_AccumulateCRC((uint32) pxConnect->connectionType);
    Xspi_Ip_AccumulateCRC((uint32) pxConnect->memAlignment);
    Xspi_Ip_AccumulateCRC((uint32) pxConnect->hifInstance);
    Xspi_Ip_AccumulateCRC((uint32)(pxConnect->initDevice ? 1UL : 0UL));

    return ((Xspi_Ip_CrcType)Xspi_Ip_FinalizeCRC());
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ValidateConfigCRC
 * Description   : Caculate and check the CRC over configuration set
*/
Xspi_Ip_StatusType Xspi_Ip_ValidateMemConfigCRC(const Xspi_Ip_MemoryConfigType * pxConfig,
                                                const Xspi_Ip_MemoryConnectionType * pxConnect
                                               )
{
    Xspi_Ip_StatusType Status = STATUS_XSPI_IP_SUCCESS;
    Xspi_Ip_CrcType MemCfgCRC = Xspi_Ip_CalcMemCfgCRC(pxConfig);
    Xspi_Ip_CrcType CntCfgCRC = Xspi_Ip_CalcCntCfgCRC(pxConnect);

    if ((pxConfig->memCfgCRC != MemCfgCRC) || (pxConnect->memCntCfgCRC != CntCfgCRC))
    {
        Status = STATUS_XSPI_IP_ERROR;
    }

    return Status;
}

static Xspi_Ip_StatusType Xspi_Ip_ValidateCtrlCfgCRC(const Xspi_Ip_ControllerConfigType *UserConfigPtr)
{
    Xspi_Ip_StatusType Status = STATUS_XSPI_IP_SUCCESS;
    uint8 Cnt;
    /* Reset the accumulated CRC value */
    Xspi_Ip_ResetCRC();

    /* CRC - Accumulate dataRate */
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->dataRate);
    /* CRC - Accumulate memSizeA1 */
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->memSizeA1);
    /* CRC - Accumulate memSizeA2 */
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->memSizeA2);
    /* CRC - Accumulate csHoldTime */
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->csHoldTime);
    /* CRC - Accumulate csSetupTime */
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->csSetupTime);
    /* CRC - Accumulate columnAddr */
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->columnAddr);
    /* CRC - Accumulate wordAddresable */
    Xspi_Ip_AccumulateCRC((uint32)(UserConfigPtr->wordAddresable ? 1UL : 0UL));
    Xspi_Ip_AccumulateCRC((uint32)(UserConfigPtr->dWordAddresable ? 1UL : 0UL));
    /* CRC - Accumulate readModeA */
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->readModeA);
    /* CRC - Accumulate sampleDelay */
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->sampleDelay);
    /* CRC - Accumulate samplePhase */
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->samplePhase);
    /* CRC - Accumulate dllMode */
    for (Cnt = 0U; Cnt < XSPI_REG(DLLCR_COUNT); Cnt++)
    {
        /* CRC - dllMode side A */
        Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->dllSettings[Cnt].dllMode);
        /* CRC - Accumulate freqEnable */
        Xspi_Ip_AccumulateCRC((uint32)(UserConfigPtr->dllSettings[Cnt].freqEnable ? 1UL : 0UL));
        /* CRC - Accumulate referenceCounter */
        Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->dllSettings[Cnt].referenceCounter);
        /* CRC - Accumulate resolution */
        Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->dllSettings[Cnt].resolution);
        /* CRC - Accumulate coarseDelay */
        Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->dllSettings[Cnt].coarseDelay);
        /* CRC - Accumulate fineDelay */
        Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->dllSettings[Cnt].fineDelay);
        /* CRC - Accumulate tapSelect */
        Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->dllSettings[Cnt].tapSelect);
    }
    /* CRC - Accumulate differentialClock */
    Xspi_Ip_AccumulateCRC((uint32)(UserConfigPtr->differentialClockA ? 1UL : 0UL));
#if FEATURE_XSPI_EXT_DQS_LATENCY
    /* CRC - Accumulate dqsLatency */
    Xspi_Ip_AccumulateCRC((uint32)(UserConfigPtr->dqsLatency ? 1UL : 0UL));
#endif
    /* CRC - Accumulate dataAlign */
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->dataAlign);
    /* CRC - Accumulate io2IdleValueA */
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->io2IdleValueA);
    /* CRC - Accumulate io3IdleValueA */
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->io3IdleValueA);
    /* CRC - Accumulate byteSwap */
    Xspi_Ip_AccumulateCRC((uint32)(UserConfigPtr->byteSwap ? 1UL : 0UL));
    Xspi_Ip_AccumulateCRC((uint32)(UserConfigPtr->enableHrespMask ? 1UL : 0UL));
    Xspi_Ip_AccumulateCRC((uint32)(UserConfigPtr->Tg1FixPrio ? 1UL : 0UL));
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->errPayloadHigh);
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->errPayloadLow);
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->ahbTimeout);
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->transactionTimeout);
    Xspi_Ip_AccumulateCRC((uint32) UserConfigPtr->arbitrationTimeout);
    Xspi_Ip_AccumulateCRC((uint32)(UserConfigPtr->lockConfiguration ? 1UL : 0UL));

    if (UserConfigPtr->memCtrlCfgCRC != (Xspi_Ip_CrcType)Xspi_Ip_FinalizeCRC())
    {
        Status = STATUS_XSPI_IP_ERROR;
    }

    return Status;
}

#endif /* XSPI_IP_CHECK_CFG_CRC */

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Sfp_Configure_Privileged
 * Description   : Configure the SFP registers
 */
void Xspi_Ip_Sfp_Configure_Privileged(uint32 instance,
                                      Xspi_Ip_SfpConfigType const * userConfigPtr
                                     )
{
    XSPI_Type *baseAddr = Xspi_Ip_BaseAddress[instance];
    uint8 index;

    for (index = 0U; index < XSPI_MDAD_COUNT; index++)
    {
        if (TRUE == userConfigPtr->Mdad[index].Valid)
        {
            Xspi_Ip_Config_Mdad(baseAddr, index, &(userConfigPtr->Mdad[index]));
        }
    }
    for (index = 0U; index < XSPI_FRAD_COUNT; index++)
    {
        if (TRUE == userConfigPtr->Frad[index].Valid)
        {
            Xspi_Ip_Config_Frad(baseAddr, index, &(userConfigPtr->Frad[index]));
        }
    }
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Sfp_Lock_Privileged
 * Description   : Apply lock to the SFP registers, as required in config
 */
void Xspi_Ip_Sfp_Lock_Privileged(uint32 instance,
                                 Xspi_Ip_SfpConfigType const * userConfigPtr
                                )
{
    XSPI_Type *baseAddr = Xspi_Ip_BaseAddress[instance];
    uint8 index;

    for (index = 0U; index < XSPI_MDAD_COUNT; index++)
    {
        if ((TRUE == userConfigPtr->Mdad[index].Valid) && (TRUE == userConfigPtr->Mdad[index].Lock))
        {
            Xspi_Ip_Lock_Mdad(baseAddr, index);
        }
    }
    for (index = 0U; index < XSPI_FRAD_COUNT; index++)
    {
        if ((TRUE == userConfigPtr->Frad[index].Valid) && (TRUE == userConfigPtr->Frad[index].Lock))
        {
            Xspi_Ip_Lock_Frad(baseAddr, index);
        }
    }
    /* Activate FRADs and MDADs */
    if (userConfigPtr->SfpEnable == TRUE)
    {
        Xspi_Ip_EnableFradsMdads(baseAddr);
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Sfp_Disable_Privileged
 * Description   : Disables SFP registers (FRADs and MDADs)
 */
void Xspi_Ip_Sfp_Disable_Privileged(uint32 instance)
{
    XSPI_Type *baseAddr = Xspi_Ip_BaseAddress[instance];

    /* de-activate FRADs and MDADs */
    Xspi_Ip_DisableFradsMdads(baseAddr);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_GlobaConfigurationLock_Privileged
 * Description   : Activates global configuration lock
 */
void Xspi_Ip_GlobaConfigurationLock_Privileged(uint32 instance)
{
    XSPI_Type *baseAddr = Xspi_Ip_BaseAddress[instance];

    Xspi_Ip_GlobaConfigurationLockEnable(baseAddr);
}

boolean Xspi_Ip_GotMasterErrors(XSPI_Type *baseAddr)
{
    uint32 Errors = 0u;
    uint32 Errstat = baseAddr->ERRSTAT;

    /* TODO add FR[DLLUNLCK, PPWF, others fields?], ERRSTAT[LOCK_ERR] */
    Errors |= Errstat & XSPI_REG(ERRSTAT_ARB_LOCK_TO_MASK);
    Errors |= Errstat & XSPI_REG(ERRSTAT_TO_ERR_MASK);

    return Errors != 0u;
}

void Xspi_Ip_ClearMasterErrors(XSPI_Type *baseAddr)
{
    /* Start of exclusive area */
    SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_11();

    uint32 Errstat = baseAddr->ERRSTAT;

    if (Errstat & XSPI_REG(ERRSTAT_TO_ERR_MASK))
    {
        baseAddr->MCR |= XSPI_REG(MCR_CLR_TXF_MASK) | XSPI_REG(MCR_CLR_RXF_MASK);
        baseAddr->FR = XSPI_REG(FR_TBUF_MASK) | XSPI_REG(FR_RBDF_MASK);
        baseAddr->ERRSTAT = XSPI_REG(ERRSTAT_TO_ERR_MASK);
    }

    if (Errstat & XSPI_REG(ERRSTAT_ARB_LOCK_TO_MASK))
    {
        baseAddr->ERRSTAT = XSPI_REG(ERRSTAT_ARB_LOCK_TO_MASK);
    }
    /* End of exclusive area */
    SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_11();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ClearStatus_Privileged
 * Description   : Clear any status and error flags before starting a new command
 */
static inline void Xspi_Ip_ClearStatus_Privileged(XSPI_Type *baseAddr)
{
    baseAddr->FR = XSPI_FR_ERR_FLAGS_MASK | XSPI_REG(FR_TFF_MASK);
    baseAddr->ERRSTAT = XSPI_ERRSTAT_CLR_FLAGS_MASK;
    baseAddr->IPSERROR |= XSPI_REG(IPSERROR_CLR_MASK);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_CmdWaitComplete
 * Description   : Wait until Xspi controller completes a command
 */
static Xspi_Ip_StatusType Xspi_Ip_CmdWaitComplete(XSPI_Type *baseAddr)
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    uint32  u32ElapsedTicks = 0UL;
    uint32  u32TimeoutTicks;
    uint32  u32CurrentTicks;

    /* Prepare timeout counter */
    u32TimeoutTicks = OsIf_MicrosToTicks(XSPI_IP_CMD_COMPLETE_TIMEOUT, XSPI_IP_TIMEOUT_TYPE);
    u32CurrentTicks = OsIf_GetCounter(XSPI_IP_TIMEOUT_TYPE);

    MCAL_FAULT_INJECTION_POINT(XSPI_IP_FMEA_WAIT_TRANSACTION_COMPLETE);

    /* Wait for command to be completed */
    do
    {
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, XSPI_IP_TIMEOUT_TYPE);
        status = Xspi_Ip_ControllerGetStatus(baseAddr);
    }
    while ((u32ElapsedTicks < u32TimeoutTicks) && (STATUS_XSPI_IP_BUSY == status));

    if (STATUS_XSPI_IP_BUSY == status)
    {
        status = STATUS_XSPI_IP_TIMEOUT;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_CmdWaitArbitration
 * Description   : Wait until current TG wins arbitration for write commands (TBDR unlocked)
 */
static Xspi_Ip_StatusType Xspi_Ip_CmdWaitArbitration(XSPI_Type *baseAddr)
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    uint32  u32ElapsedTicks = 0UL;
    uint32  u32TimeoutTicks;
    uint32  u32CurrentTicks;

    /* Prepare timeout counter */
    u32TimeoutTicks = OsIf_MicrosToTicks(XSPI_IP_CMD_COMPLETE_TIMEOUT, XSPI_IP_TIMEOUT_TYPE);
    u32CurrentTicks = OsIf_GetCounter(XSPI_IP_TIMEOUT_TYPE);

    /* Wait for command to be completed */
    do
    {
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, XSPI_IP_TIMEOUT_TYPE);
        status = Xspi_Ip_ControllerGetArbStatus(baseAddr);
    }
    while ((u32ElapsedTicks < u32TimeoutTicks) && (STATUS_XSPI_IP_BUSY == status));

    if (STATUS_XSPI_IP_BUSY == status)
    {
        status = STATUS_XSPI_IP_TIMEOUT;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ProcessDataRead
 * Description   : Processes read data
 * Xspi_Ip_ProcessDataRead_Activity */
static inline Xspi_Ip_StatusType Xspi_Ip_ProcessDataRead(uint8 *dataRead,
                                                         uint32 size,
                                                         const XSPI_Type *baseAddr,
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
        wordSize = ((sizeRemaining > 4U) ? 4U : sizeRemaining);

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
    if (((uint32)data & 0x3U) == 0U)
    {
        /* Process 4 bytes at a time to speed up read */
        while (sizeRemaining >= 4U)
        {
            *((uint32 *)((uint32)data)) = baseAddr->RBDR[cnt];  /* Casting through uint32 to avoid Misra 11.3 */
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
        wordSize = ((sizeRemaining > 4U) ? 4U : sizeRemaining);
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
    return STATUS_XSPI_IP_SUCCESS;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ProcessDataVerify
 * Description   : Processes program verify data
 * Xspi_Ip_ProcessDataVerify_Activity */
static inline Xspi_Ip_StatusType Xspi_Ip_ProcessDataVerify(const uint8 *dataCmp,
                                                           uint32 size,
                                                           const XSPI_Type *baseAddr,
                                                           uint32 padding
                                                          )
{
    const uint8 * roData = dataCmp;
    uint32 cnt = 0U;
    uint32 recvData;
    uint8 recvByte;
    const uint8 *recvDataPtr = (uint8 *)(&recvData);
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
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
        wordSize = ((sizeRemaining > 4U) ? 4U : sizeRemaining);
        sizeRemaining -= wordSize;

        /* Ignore padding bytes and compare the rest with user buffer */
        for (byteCnt = paddingBytes; byteCnt < wordSize; byteCnt++)
        {
            #if (defined(CORE_BIG_ENDIAN))
            recvByte = recvDataPtr[3U - byteCnt];
            #else
            recvByte = recvDataPtr[byteCnt];
            #endif

            /* return STATUS_XSPI_IP_ERROR_PROGRAM_VERIFY if the data is not match */
            if (*roData != recvByte)
            {
                status = STATUS_XSPI_IP_ERROR_PROGRAM_VERIFY;
                sizeRemaining = 0U;
                break;
            }
            roData++;
        }
    }

    /* Check user buffer alignment */
    if (((uint32)&roData[0] & 0x3U) == 0U)
    {
        while (sizeRemaining >= 4U)
        {
            /* Process 4 bytes at a time to speed up read */
            if (*((const uint32 *)((uint32)roData)) != baseAddr->RBDR[cnt])
            {
                /* return STATUS_XSPI_IP_ERROR_PROGRAM_VERIFY if the data is not match */
                status = STATUS_XSPI_IP_ERROR_PROGRAM_VERIFY;
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
        wordSize = ((sizeRemaining > 4U) ? 4U : sizeRemaining);
        for (byteCnt = 0U; byteCnt < wordSize; byteCnt++)
        {
#if (defined(CORE_BIG_ENDIAN))
            recvByte = (uint8)(recvData >> 24U);
            recvData <<= 8U;
#else
            recvByte = (uint8)(recvData & 0xFFU);
            recvData >>= 8U;
#endif
            /* return STATUS_XSPI_IP_ERROR_PROGRAM_VERIFY if the data is not match */
            if (*roData != recvByte)
            {
                status = STATUS_XSPI_IP_ERROR_PROGRAM_VERIFY;
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
 * Function Name : Xspi_Ip_ProcessDataBlankCheck
 * Description   : Processes blank check data
 * Xspi_Ip_ProcessDataBlankCheck_Activity */
static inline Xspi_Ip_StatusType Xspi_Ip_ProcessDataBlankCheck(uint32 size,
                                                               const XSPI_Type *baseAddr,
                                                               uint32 padding
                                                              )
{
    uint32 cnt = 0U;
    uint32 recvData = 0U;
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
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
        dataSize = (sizeRemaining > 4U) ? 4U : sizeRemaining;
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
            status = STATUS_XSPI_IP_ERROR_BLANK_CHECK;
            sizeRemaining = 0U;
        }
    }

    /* Blank check */
    while (sizeRemaining >= 4U)
    {
        if (baseAddr->RBDR[cnt] != 0xFFFFFFFFU)
        {
            /* The data is not blank */
            status = STATUS_XSPI_IP_ERROR_BLANK_CHECK;
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
            status = STATUS_XSPI_IP_ERROR_BLANK_CHECK;
        }
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_FillTxBuf
 * Description   : Fill Tx buffer with the specified number of 4-byte entries
*  Xspi_Ip_FillTxBuf_Activity */
static void Xspi_Ip_FillTxBuf(XSPI_Type *baseAddr,
                              const uint8 *roData,
                              uint32 size,
                              uint32 padding
                             )
{
    uint32 sizeLeft = size;
    uint32 wordSize;
    uint32 data = 0xFFFFFFFFUL;
    uint8 *dataPtr = (uint8 *)(&data);
    uint32 byteCnt;
    const uint8 * roDataPtr = roData;

    uint32 prePadding   = padding >> 4U;
    uint32 postPadding  = padding & 0x0FU;

    /* Insert prePadding words */
    while (prePadding >= 4U)
    {
        Xspi_Ip_WriteTxData(baseAddr, 0xFFFFFFFFUL);
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
        Xspi_Ip_WriteTxData(baseAddr, data);
    }

    /* Check user buffer alignment */
    if (((uint32)&roDataPtr[0] & 0x3U) == 0U)
    {
        /* Process 4 bytes at a time to speed things up */
        while (sizeLeft >= 4U)
        {
            data = *(const uint32 *)((uint32)roDataPtr);  /* Casting through uint32 to avoid Misra 11.3 */
            sizeLeft -= 4U;
            roDataPtr = &(roDataPtr[4U]);
            Xspi_Ip_WriteTxData(baseAddr, data);
        }
    }

    /* Process remaining bytes one by one */
    while (sizeLeft > 0U)
    {
        data = 0xFFFFFFFFUL;
        wordSize = (sizeLeft > 4U) ? 4U : sizeLeft;
        for (byteCnt = 0U; byteCnt < wordSize; byteCnt++)
        {
            #if (defined(CORE_BIG_ENDIAN))
            dataPtr[3U - byteCnt] = *roDataPtr;
            #else
            dataPtr[byteCnt] = *roDataPtr;
            #endif

            roDataPtr++;
        }
        Xspi_Ip_WriteTxData(baseAddr, data);
        sizeLeft -= wordSize;
    }

    /* Insert postPadding words */
    while (postPadding >= 4U)
    {
        Xspi_Ip_WriteTxData(baseAddr, 0xFFFFFFFFUL);
        postPadding -= 4U;
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_InvalidateTxBuf
 * Description   : Invalidates the TX buffer content and wait until it is completed or timed out
 * Xspi_Ip_InvalidateTxBuf_Activity */
static inline void Xspi_Ip_InvalidateTxBuf(XSPI_Type *baseAddr)
{
    volatile uint32 u32CurrentTicks;

    /* Start TX FIFO reset */
    Xspi_Ip_ClearTxBuf(baseAddr);

    /* Prepare timeout counter */
    u32CurrentTicks = XSPI_IP_TX_BUFFER_RESET_DELAY;
    /* Insert delay to ensure TX FIFO reset is complete */
    while (u32CurrentTicks > 0U)
    {
        u32CurrentTicks--;
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_AhbSetup
 * Description   : Sets up AHB accesses to the serial flash
*  Xspi_Ip_AhbSetup_Activity */
static void Xspi_Ip_AhbSetup(uint32 instance,
                             const Xspi_Ip_ControllerAhbConfigType *config
                            )
{
    XSPI_Type *baseAddr = Xspi_Ip_BaseAddress[instance];
    uint8 buf;

    /* configure AHB transfer sizes to match the buffer sizes */
    /* Set AHB buffer 0 */
    Xspi_Ip_SetAhbBuf0(baseAddr, config->sizes[0U], config->masters[0U]);
    /* Set AHB buffer 1 */
    Xspi_Ip_SetAhbBuf1(baseAddr, config->sizes[1U], config->masters[1U]);
    /* Set AHB buffer 2 */
    Xspi_Ip_SetAhbBuf2(baseAddr, config->sizes[2U], config->masters[2U]);
    /* Set AHB buffer 3 */
    Xspi_Ip_SetAhbBuf3(baseAddr, config->sizes[3U], config->masters[3U], config->allMasters);
    /* Set AHB buffer index 0 */
    Xspi_Ip_SetAhbBufInd(baseAddr, 0U, (uint32)config->sizes[0U]);
    /* Set AHB buffer index 1 */
    Xspi_Ip_SetAhbBufInd(baseAddr, 1U, (uint32)config->sizes[0U] + (uint32)config->sizes[1U]);
    /* Set AHB buffer index 2 */
    Xspi_Ip_SetAhbBufInd(baseAddr, 2U, (uint32)config->sizes[0U] + (uint32)config->sizes[1U] + (uint32)config->sizes[2U]);
    /* Configure sub-buffers */
    for (buf = 0U; buf < XSPI_IP_AHB_BUFFERS; buf++)
    {
        Xspi_Ip_ConfigAhbSubBuf(baseAddr, buf, &(config->subbufs[buf]));
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ControllerBasicConfig
 * Description   : Configures basic XSPI controller settings
 * Xspi_Ip_ControllerBasicConfig_Activity */
static void Xspi_Ip_ControllerBasicConfig(uint32 instance,
                                          const Xspi_Ip_ControllerConfigType * userConfigPtr
                                         )
{
    XSPI_Type *baseAddr = Xspi_Ip_BaseAddress[instance];
    boolean ddrEnable = FALSE;

    if (XSPI_IP_DATA_RATE_DDR == (userConfigPtr->dataRate))
    {
        ddrEnable = TRUE;
    }
#if FEATURE_XSPI_EXT_DQS_LATENCY
    Xspi_Ip_SetDQS(baseAddr, userConfigPtr->dqsLatency, ddrEnable, TRUE);
#else
    Xspi_Ip_SetDQS(baseAddr, ddrEnable, TRUE);
#endif

    Xspi_Ip_DqsOutEnable(baseAddr, userConfigPtr->dqsAsAnOutput);

    Xspi_Ip_SetISD(baseAddr, userConfigPtr->io2IdleValueA, userConfigPtr->io3IdleValueA);
    Xspi_Ip_SetClk(baseAddr, userConfigPtr->readModeA, userConfigPtr->differentialClockA);
    /* configure FLSHCR */
    Xspi_Ip_SetOutTiming(baseAddr, userConfigPtr->dataAlign, userConfigPtr->csHoldTime, userConfigPtr->csSetupTime);
    /* configure SOCCR */
    Xspi_Ip_SetHrespMask(baseAddr, userConfigPtr->enableHrespMask);
    if (userConfigPtr->enableHrespMask)
    {
        /* configure Error Payload */
        Xspi_Ip_SetErrPayload(baseAddr, userConfigPtr->errPayloadHigh, userConfigPtr->errPayloadLow);
    }


    /* configure SMPR */
    Xspi_Ip_SetRxCfg(baseAddr, userConfigPtr->sampleDelay, userConfigPtr->samplePhase, userConfigPtr->dllSettings[0U].tapSelect);
    /* configure SFACR */
    Xspi_Ip_SetAddrCfg(baseAddr, userConfigPtr->columnAddr, userConfigPtr->wordAddresable, userConfigPtr->dWordAddresable, userConfigPtr->byteSwap);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ControllerTimeoutsConfig_Privileged
 * Description   : Configures the XSPI controller timeouts values
 * Xspi_Ip_ControllerTimeoutsConfig_Activity */
static void Xspi_Ip_ControllerTimeoutsConfig_Privileged(uint32 instance,
                                                        const Xspi_Ip_ControllerConfigType * userConfigPtr
                                                       )
{
    XSPI_Type *baseAddr = Xspi_Ip_BaseAddress[instance];

    /* AHB timeout (AHRDYTO) */
    Xspi_Ip_SetAhbTimeout(baseAddr, userConfigPtr->ahbTimeout);
    /* Transaction timeout (MTO) */
    Xspi_Ip_SetTransactionTimeout(baseAddr, userConfigPtr->transactionTimeout);
    /* Arbitration lock timeout (SFP_ARB_TIMEOUT) */
    Xspi_Ip_SetArbitrationTimeout(baseAddr, userConfigPtr->arbitrationTimeout);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_WaitDLLSlaveLock
 * Description   : DLL side A - Wait for slave high lock status or DLL lock status
 */
static Xspi_Ip_StatusType Xspi_Ip_WaitDLLSlaveLock(const XSPI_Type *baseAddr, uint8 dllIdx)
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    boolean LockStatus;

    /* Prepare timeout counter */
    uint32 u32ElapsedTicks = 0UL;
    uint32 u32TimeoutTicks = OsIf_MicrosToTicks(XSPI_IP_DLL_LOCK_TIMEOUT, XSPI_IP_TIMEOUT_TYPE);
    uint32 u32CurrentTicks = OsIf_GetCounter(XSPI_IP_TIMEOUT_TYPE);

    do
    {
        /* Check the slave delay chain update status */
        LockStatus = Xspi_Ip_DLLGetSlaveLockStatus(baseAddr, dllIdx);

        /* Check for errors reported by DLL */
        if (Xspi_Ip_DLLGetErrorStatus(baseAddr, dllIdx))
        {
            status = STATUS_XSPI_IP_ERROR;
        }
        else
        {
            /* Check for timeout */
            u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, XSPI_IP_TIMEOUT_TYPE);
            if (u32ElapsedTicks >= u32TimeoutTicks)
            {
                status = STATUS_XSPI_IP_TIMEOUT;
            }
        }

        if (STATUS_XSPI_IP_SUCCESS != status)
        {
            break;
        }
    }
    while (!LockStatus);

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ConfigureDLLBypass
 * Description   : Configures DLL in bypass mode
 */
static Xspi_Ip_StatusType Xspi_Ip_ConfigureDLLBypass(XSPI_Type *baseAddr,
                                                     uint8 dllIdx,
                                                     const Xspi_Ip_ControllerConfigType *userConfigPtr
                                                    )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;

    /* Set DLL in bypass mode and configure coarse and fine delays */
    Xspi_Ip_DLLSlaveDlyFine(baseAddr, dllIdx, 1U);
    Xspi_Ip_DLLSlaveBypass(baseAddr, dllIdx, TRUE);
    Xspi_Ip_DLLSlaveAutoUpdate(baseAddr, dllIdx, FALSE);
    Xspi_Ip_DLLSetDelayCoarse(baseAddr, dllIdx, userConfigPtr->dllSettings[dllIdx].coarseDelay);
    Xspi_Ip_DLLSetFineOffset(baseAddr, dllIdx, userConfigPtr->dllSettings[dllIdx].fineDelay);
    Xspi_Ip_DLLFreqEn(baseAddr, dllIdx, userConfigPtr->dllSettings[dllIdx].freqEnable);

    /* Trigger slave chain update */
    Xspi_Ip_DLLSlaveUpdate(baseAddr, dllIdx, TRUE);

    /* Wait for slave delay chain update */
    status = Xspi_Ip_WaitDLLSlaveLock(baseAddr, dllIdx);
    /* Disable slave chain update */
    Xspi_Ip_DLLSlaveUpdate(baseAddr, dllIdx, FALSE);

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ConfigureDLLAutoUpdate
 * Description   : Configures DLL in auto update mode
 */
static Xspi_Ip_StatusType Xspi_Ip_ConfigureDLLAutoUpdate(XSPI_Type *baseAddr,
                                                         uint8 dllIdx,
                                                         const Xspi_Ip_ControllerConfigType *userConfigPtr
                                                        )
{
    Xspi_Ip_StatusType status;

    /* Set DLL in auto update mode and configure coarse and fine delays */
    Xspi_Ip_DLLSlaveBypass(baseAddr, dllIdx, FALSE);
    Xspi_Ip_DLLSlaveAutoUpdate(baseAddr, dllIdx, (XSPI_IP_DLL_AUTO_UPDATE == userConfigPtr->dllSettings[dllIdx].dllMode));
    Xspi_Ip_DLLSetReferenceCounter(baseAddr, dllIdx, userConfigPtr->dllSettings[dllIdx].referenceCounter);
    Xspi_Ip_DLLSetResolution(baseAddr, dllIdx, userConfigPtr->dllSettings[dllIdx].resolution);
    Xspi_Ip_DLLSetDelayOffset(baseAddr, dllIdx, userConfigPtr->dllSettings[dllIdx].coarseDelay);
    Xspi_Ip_DLLSetFineOffset(baseAddr, dllIdx, userConfigPtr->dllSettings[dllIdx].fineDelay);
    Xspi_Ip_DLLFreqEn(baseAddr, dllIdx, userConfigPtr->dllSettings[dllIdx].freqEnable);

    if (XSPI_IP_DLL_AUTO_UPDATE == userConfigPtr->dllSettings[dllIdx].dllMode)
    {
        /* For auto update mode, trigger slave chain update */
        Xspi_Ip_DLLSlaveUpdate(baseAddr, dllIdx, TRUE);
    }
    /* Enable DLL */
    Xspi_Ip_DLLEnable(baseAddr, dllIdx, TRUE);

    /* Wait for slave delay chain update */
    status = Xspi_Ip_WaitDLLSlaveLock(baseAddr, dllIdx);

    /* Disable slave chain update */
    Xspi_Ip_DLLSlaveUpdate(baseAddr, dllIdx, FALSE);

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ConfigureDLL
 * Description   : Configures DLL
 **/
static Xspi_Ip_StatusType Xspi_Ip_ConfigureDLL(XSPI_Type *baseAddr,
                                               uint8 dllIdx,
                                               const Xspi_Ip_ControllerConfigType *userConfigPtr
                                              )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;

    /* Ensure DLL and slave chain update are off */
    Xspi_Ip_DLLSlaveUpdate(baseAddr, dllIdx, FALSE);
    Xspi_Ip_DLLEnable(baseAddr, dllIdx, FALSE);

    /* Enable DQS slave delay chain before any settings take place */
    Xspi_Ip_DLLSlaveEn(baseAddr, dllIdx, TRUE);

    if (XSPI_IP_DLL_BYPASSED == userConfigPtr->dllSettings[dllIdx].dllMode)
    {
        status = Xspi_Ip_ConfigureDLLBypass(baseAddr, dllIdx, userConfigPtr);
    }
    else
    {
        status = Xspi_Ip_ConfigureDLLAutoUpdate(baseAddr, dllIdx, userConfigPtr);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_DLLConfig
 * Description   : Initializes the DLL and delay chain
 */
static Xspi_Ip_StatusType Xspi_Ip_DLLConfig(uint32 instance,
                                            const Xspi_Ip_ControllerConfigType * userConfigPtr
                                           )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    XSPI_Type *baseAddr = Xspi_Ip_BaseAddress[instance];

    /* Configure DLL A */
    if ((userConfigPtr->memSizeA1 + userConfigPtr->memSizeA2) > 0U)
    {
        status = Xspi_Ip_ConfigureDLL(baseAddr, 0U, userConfigPtr);
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ControllerConfig
 * Description   : Initializes the Xspi controller
 * Xspi_Ip_ControllerConfig_Activity */
static void Xspi_Ip_ControllerConfig(uint32 instance,
                                     const Xspi_Ip_ControllerConfigType * userConfigPtr
                                    )
{
    XSPI_Type *baseAddr = Xspi_Ip_BaseAddress[instance];

    /* Basic communication settings (MCR, FLSHCR, SOCCR, SMPR, SFACR) */
    Xspi_Ip_ControllerBasicConfig(instance, userConfigPtr);
    /* Address ranges (SFAxAD, SFBxAD) */
    Xspi_Ip_SetMemMap(instance, baseAddr, userConfigPtr);
    /* Configure timeouts: AHB timeout (AHRDYTO), Transaction timeout (MTO), Arbitration lock timeout (SFP_ARB_TIMEOUT) */
    Xspi_Ip_ControllerTimeoutsConfig(instance, userConfigPtr);
    /* AHB buffers/sub-buffers */
    Xspi_Ip_AhbSetup(instance, &(userConfigPtr->ahbConfig));
    /* MDAD and FRAD config + lock */
    Xspi_Ip_Sfp_Configure(instance, &(userConfigPtr->SfpCfg));
    /* interrupts configuration (for all HIFs) (RSER, RSER_SUB_1 - RSER_SUB_4, INT_EN, INT_EN_SUB_1 - INT_EN_SUB_4) - TBD */
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SwResetDelay
 * Description   : Insert waiting loops after changing the value of the software reset bits
 */
static inline void Xspi_Ip_SwResetDelay(void)
{
    /* Prepare timeout counter */
    volatile uint32 u32CurrentTicks = XSPI_IP_SOFTWARE_RESET_DELAY;
    /* Insert delay after changing the value of the software reset bits. */
    while (u32CurrentTicks > 0U)
    {
        u32CurrentTicks--;
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SwReset
 * Description   : Resets the XSPI device
*  Xspi_Ip_SwReset_Activity */
static void Xspi_Ip_SwReset(XSPI_Type *baseAddr)
{
    /* Enable XSPI module before reset. */
    Xspi_Ip_Enable(baseAddr);
    /* Software reset AHB domain and Serial Flash domain at the same time. */
    Xspi_Ip_SwResetOn(baseAddr);
    /* Insert delay after changing the value of the reset bits. */
    Xspi_Ip_SwResetDelay();
    /* Disable XSPI module before de-asserting the reset bits. */
    Xspi_Ip_Disable(baseAddr);
    /* De-asset Software reset AHB domain and Serial Flash domain bits. */
    Xspi_Ip_SwResetOff(baseAddr);
    /* Insert delay after changing the value of the reset bits. */
    Xspi_Ip_SwResetDelay();
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ControllerGetArbStatus
 * Description   : Checks if arbitration was granted for a write command
 * Xspi_Ip_ControllerGetArbStatus_Activity */
static Xspi_Ip_StatusType Xspi_Ip_ControllerGetArbStatus(XSPI_Type *baseAddr)
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_BUSY;
    uint32 fsmState;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(baseAddr != NULL_PTR);
#endif

    if (Xspi_Ip_GetFsmValid(baseAddr))
    {
        fsmState = Xspi_Ip_GetFsmState(baseAddr);
        /* Check if transaction is stuck after winning arbitration because there is leftover data in Rx FIFO  */
        if (fsmState == 0U)
        {
            /* Clear Rx FIFO  */
            Xspi_Ip_ClearRxBuf(baseAddr);
        }
        /* Check if state 1 (TBDR lock is open) was reached  */
        else if (fsmState == 1U)
        {
            status = STATUS_XSPI_IP_SUCCESS;
        }
        else
        {
            /*empty statement*/
        }
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ResetPrivilegedRegisters_Privileged
 * Description   : Configures a LUT sequence
 */
void Xspi_Ip_ResetPrivilegedRegisters_Privileged(XSPI_Type *baseAddr)
{
    Xspi_Ip_SfpFradCfgType fradCfg;
    uint8 cnt;

    /* reset BFGENCR register */
    baseAddr->BFGENCR  = (uint32)0x00000000UL;

    /* reset LUT registers */
    baseAddr->LUT[0]   = (uint32)0x08180403UL;
    baseAddr->LUT[1]   = (uint32)0x24001C08UL;
    for (cnt = 2U; cnt < XSPI_REG(LUT_COUNT); cnt++)
    {
        baseAddr->LUT[cnt] = (uint32)0x00000000UL;
    }

    /* reset Secure Flash Protection registers */
    fradCfg.StartAddress = 0x10000000UL;
    fradCfg.EndAddress = 0x1FFFFFFFUL;
    fradCfg.Valid = FALSE;
    fradCfg.Lock = FALSE;
    for (cnt = 0U; cnt < XSPI_MDAD_COUNT; cnt++)
    {
        fradCfg.MdAcp[cnt] = XSPI_IP_SFP_ACP_ALL_R;
    }
    for (cnt = 0U; cnt < XSPI_FRAD_COUNT; cnt++)
    {
        Xspi_Ip_Config_Frad(baseAddr, cnt, &fradCfg);
    }
    baseAddr->TG0MDAD = 0x00000000UL;
    baseAddr->TG1MDAD = 0x00000000UL;
    baseAddr->MGC      = 0xA8000000UL;
    baseAddr->MRC      = 0x00500E07UL;
    baseAddr->MTO      = 0x0000FFFFUL;
    baseAddr->IPSERROR = 0x20000000UL;
    baseAddr->ERRSTAT  = 0x70FF41FFUL;
    baseAddr->INT_EN   = 0x00000000UL;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ResetAllRegisters
 * Description   : Bring registers to reset values
 **/
static void Xspi_Ip_ResetAllRegisters(XSPI_Type *baseAddr)

{
    (void)baseAddr;
    uint8 cnt;
    uint8 cnt2;

    baseAddr->ARDCR     = (uint32)0x00000000UL;
    baseAddr->MCR       = (uint32)0x000F404CUL;
    baseAddr->FLSHCR    = (uint32)0x00010303UL;
    baseAddr->BUF0CR    = (uint32)0x00000000UL;
    baseAddr->BUF1CR    = (uint32)0x00000001UL;
    baseAddr->BUF2CR    = (uint32)0x00000002UL;
    baseAddr->BUF3CR    = (uint32)0x80000003UL;
    baseAddr->BUFIND[0] = (uint32)0x00000000UL;
    baseAddr->BUFIND[1] = (uint32)0x00000000UL;
    baseAddr->BUFIND[2] = (uint32)0x00000000UL;
    baseAddr->AWRCR     = (uint32)0x00000000UL;
#if FEATURE_XSPI_HAS_DLL
    baseAddr->DLLCR[0]  = (uint32)0x01200000UL;
    baseAddr->DLCR      = (uint32)0x40FF40FFUL;
#endif
    baseAddr->PARITYCR  = (uint32)0x00000000UL;
    baseAddr->SFACR     = (uint32)0x00000800UL;
    baseAddr->SMPR      = (uint32)0x00000000UL;
    baseAddr->RBCT      = (uint32)0x00000000UL;
    baseAddr->TBCT      = (uint32)0x00000000UL;
    /* reset FR register, Write 1 to clear */
    baseAddr->FR        = (uint32)0x9D83FF47UL;
    baseAddr->RSER      = (uint32)0x00000000UL;
    /* reset SPTRCLR register and clear both IP and AHB sequence pointers */
    baseAddr->SPTRCLR   = (uint32)0x01000101UL;
    baseAddr->SFAD[0][0]    = (uint32)0x1FFFFC00UL;
    baseAddr->SFAD[0][1]    = (uint32)0x1FFFFC00UL;
#if FEATURE_XSPI_HAS_SIDE_B
    baseAddr->SFAD[1][0]    = (uint32)0x1FFFFC00UL;
    baseAddr->SFAD[1][1]    = (uint32)0x1FFFFC00UL;
#endif
    /* unlock LUT */
    baseAddr->LUTKEY   = (uint32)0x5AF05AF0UL;
    baseAddr->LCKCR    = (uint32)0x00000002UL;
    /* reset AHB subbuffer ranges */
    for (cnt = 0U; cnt < XSPI_REG(BUFN_M_ADDR_RANGE_COUNT); cnt ++ )
    {
        for (cnt2 = 0U; cnt2 < XSPI_REG(BUFN_M_ADDR_RANGE_BUFN_M_ADDR_RANGE_COUNT); cnt2 ++ )
        {
            baseAddr->BUF_ADDR_RANGE[cnt][cnt2] = (uint32)0x00000000UL;
        }
    }
    baseAddr->AHB_PERF_CTRL = (uint32)0x00000000UL;
    baseAddr->AHRDYTO = (uint32)0x00000003;
    baseAddr->AHB_ERR_PAYLOAD_HI = (uint32)0x00000000;
    baseAddr->AHB_ERR_PAYLOAD_LO = (uint32)0x00000000;
    baseAddr->PPWF_TCNT = (uint32)0x00FFFFFF;
    baseAddr->PPW_RDSR = (uint32)0x00000000;
    baseAddr->SFP_ARB_TIMEOUT = (uint32)0x000FFFFF;
    for (cnt = 0U; cnt < XSPI_REG(SFP_LUT_EN_ARRAY_COUNT); cnt ++ )
    {
        baseAddr->SFP_LUT_EN[cnt] = (uint32)0x00000000;
    }
#ifdef DERIVATIVE_S32N79
    for (cnt = 0U; cnt < XSPI_REG(SFP_LUT_EN_EXT_ARRAY_COUNT); cnt ++ )
    {
        baseAddr->SFP_LUT_EN_EXT[cnt] = (uint32)0x00000000;
    }
#endif

    Xspi_Ip_ResetPrivilegedRegisters(baseAddr);
}


/*! @endcond */

/*******************************************************************************
 * Code
 ******************************************************************************/


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SetLutSeq_Privileged
 * Description   : Configures a LUT sequence
 */
void Xspi_Ip_SetLutSeq_Privileged(uint32 instance,
                                  uint8 lutSeqNo,
                                  const Xspi_Ip_InstrOpType *opList
                                 )
{
    XSPI_Type *baseAddr = Xspi_Ip_BaseAddress[instance];
    uint8 lutIndex;
    const Xspi_Ip_InstrOpType *opIndex;
    Xspi_Ip_InstrOpType operation1;
    Xspi_Ip_InstrOpType operation2 = XSPI_IP_LUT_SEQ_END;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_REG(INSTANCE_COUNT));
    DEV_ASSERT_XSPI(lutSeqNo < (XSPI_REG(LUT_COUNT) / FEATURE_XSPI_LUT_SEQUENCE_SIZE));
#endif

    opIndex = opList;
    /* Go through the list until STOP instruction, then continue to add STOP instructions until the end of the sequence */
    for(lutIndex = lutSeqNo * FEATURE_XSPI_LUT_SEQUENCE_SIZE; lutIndex < ((lutSeqNo + 1U) * FEATURE_XSPI_LUT_SEQUENCE_SIZE); lutIndex++)
    {
        operation1 = *opIndex;
        if (operation1 != XSPI_IP_LUT_SEQ_END)
        {
            opIndex++;
        }
        operation2 = *opIndex;
        if (operation2 != XSPI_IP_LUT_SEQ_END)
        {
            opIndex++;
        }
        baseAddr->LUT[lutIndex] = XSPI_IP_PACK_LUT_REG(operation1, operation2);
    }
#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(operation2 == XSPI_IP_LUT_SEQ_END);
#endif
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SetAhbSeqId_Privileged
 * Description   : Sets sequence ID for AHB read operations
 */
void Xspi_Ip_SetAhbSeqId_Privileged(uint32 instance,
                                    uint8 seqID
                                   )
{
    XSPI_Type *baseAddr;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_REG(INSTANCE_COUNT));
#endif
    baseAddr = Xspi_Ip_BaseAddress[instance];
    Xspi_Ip_SetAhbReadSeq(baseAddr, seqID);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SetAhbWriteSeqId
 * Description   : Sets sequence ID for AHB write operations
 */
void Xspi_Ip_SetAhbWriteSeqId_Privileged(uint32 instance, uint8 seqID)
{
    XSPI_Type *baseAddr;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_REG(INSTANCE_COUNT));
#endif
    baseAddr = Xspi_Ip_BaseAddress[instance];
    Xspi_Ip_SetAhbWriteSeq(baseAddr, seqID);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_SetLutAccess_Privileged
 * Description   : Sets sequence ID for AHB read operations
 */
void Xspi_Ip_SetLutAccess_Privileged(uint32 instance,
                                     const uint16 *accessRights
                                    )
{
    XSPI_Type *baseAddr = Xspi_Ip_BaseAddress[instance];
    uint8 index;

    for (index = 0U; index < XSPI_REG(SFP_LUT_EN_ARRAY_COUNT); index++)
    {
        Xspi_Ip_Config_LutAccess(baseAddr, index, accessRights[index]);
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ControllerGetHifAdress
 * Description   : Returns the physical base address of a user interface.
 * Xspi_Ip_ControllerGetHifAdress_Activity */
XSPI_Type * Xspi_Ip_ControllerGetHifAdress(uint32 instance, uint8 hifNo)
{
    XSPI_Type * baseAddr = NULL_PTR;
    XSPI_Type * RetAddr = NULL_PTR;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_REG(INSTANCE_COUNT));
    DEV_ASSERT_XSPI(hifNo == 0u);
#endif

    baseAddr = Xspi_Ip_BaseAddress[instance];
    RetAddr = baseAddr;


    return RetAddr;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ControllerGetBaseAdress
 * Description   : Returns the physical base address of a flash device on the AHB bus.
 *                 The controller must be initialized prior to calling this function.
 * Xspi_Ip_ControllerGetBaseAdress_Activity */
uint32 Xspi_Ip_ControllerGetBaseAdress(uint32 instance,
                                       Xspi_Ip_ConnectionType connectionType
                                      )
{
    const XSPI_Type *baseAddr;
    uint32 address = 0U;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_REG(INSTANCE_COUNT));
#endif
    /* get the base address base on the instance */
    baseAddr = Xspi_Ip_BaseAddress[instance];

    switch (connectionType)
    {
        case XSPI_IP_SIDE_A1:
            /* get base address of side A1 */
            address = Xspi_Ip_AhbAddress[instance];
            break;
        case XSPI_IP_SIDE_A2:
            /* get base address of side A2 */
            address = baseAddr->SFAD[0][0];
            break;
#if FEATURE_XSPI_HAS_SIDE_B
        case XSPI_IP_SIDE_B1:
            /* get base address of side B1 */
            address = baseAddr->SFAD[0][1];
            break;
        case XSPI_IP_SIDE_B2:
            /* get base address of side B2 */
            address = baseAddr->SFAD[1][0];
            break;
#endif
        default:
            ; /* Not possible */
            break;
    }

    return address;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ControllerInit
 * Description   : Initializes the XSPI controller
 * @implements     Xspi_Ip_ControllerInit_Activity */
Xspi_Ip_StatusType Xspi_Ip_ControllerInit(uint32 instance,
                                          const Xspi_Ip_ControllerConfigType * userConfigPtr
                                         )
{
    XSPI_Type *baseAddr;
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;

#if (XSPI_IP_CHECK_CFG_CRC == STD_ON)
    status = Xspi_Ip_ValidateCtrlCfgCRC(userConfigPtr);
    if (STATUS_XSPI_IP_SUCCESS == status)
#endif
    {
        /* Initialize driver status structure */
        baseAddr = Xspi_Ip_BaseAddress[instance];
        /* Start of exclusive area */
        SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_04();
        /* Ensure module is disabled */
        Xspi_Ip_Disable(baseAddr);
        /* Bring registers to reset values  */
        Xspi_Ip_ResetAllRegisters(baseAddr);
        /* Disable MDADs and FRADs until configuration is complete */
        Xspi_Ip_Sfp_Disable(instance);
        /* Soft reset: MCR[IPS_TG_RST, SWRSTHD, SWRSTSD] */
        Xspi_Ip_SwReset(baseAddr);
        /* Apply configuration settings  */
        Xspi_Ip_ControllerConfig(instance, userConfigPtr);
        /* Enable controller */
        Xspi_Ip_Enable(baseAddr);
#if FEATURE_XSPI_HAS_DLL
        /* DLL configuration */
        status = Xspi_Ip_DLLConfig(instance, userConfigPtr);

        /* Store user configuration for runtime usage */
        Xspi_Ip_ControllerConfigPtr[instance] = userConfigPtr;
#endif
        /* End of exclusive area */
        SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_04();
    }


    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ControllerDeinit
 * Description   : De-initialize the XSPI driver
 * @implements     Xspi_Ip_ControllerDeinit_Activity */
Xspi_Ip_StatusType Xspi_Ip_ControllerDeinit(uint32 instance)
{
    /* Start of exclusive area */
    SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_05();

    XSPI_Type *baseAddr = Xspi_Ip_BaseAddress[instance];

    Xspi_Ip_Disable(baseAddr);

    /* End of exclusive area */
    SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_05();

    return STATUS_XSPI_IP_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_Abort
 * Description   : Force the Xspi controller to cancel any on-going transactions by performing the software reset requence.
 *                 This can be used to recover the hardware controller from being stuck in BUSY state.
 *                 Re-configure DLL is needed to avoid side-effects on the DLL after the S/W reset.
 */
Xspi_Ip_StatusType Xspi_Ip_Abort(uint32 instance)
{
    XSPI_Type *baseAddr = Xspi_Ip_BaseAddress[instance];
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
#endif

    /* Reset serial flash and AHB domains */
    Xspi_Ip_SwReset(baseAddr);

    /* S/W reset would also loose any Slave-chain upate, therefore re-configure DLL sequence is needed */
    if (Xspi_Ip_ControllerConfigPtr[instance] != NULL_PTR)
    {
        /* Start of exclusive area */
        SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_10();
        /* Perform the DLL config only if the user configuration is available.
           Because there will be the case when user skip the controller configuration at initialization time.
         */
        status = Xspi_Ip_DLLConfig(instance, Xspi_Ip_ControllerConfigPtr[instance]);
        /* End of exclusive area */
        SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_10();
    }

    return status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ControllerInitSecurity
 * Description   : Applies security settings
 *
 * @implements     Xspi_Ip_ControllerInitSecurity_Activity */
Xspi_Ip_StatusType Xspi_Ip_ControllerInitSecurity(uint32 instance,
                                                  const Xspi_Ip_ControllerConfigType * userConfigPtr
                                                 )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_SUCCESS;
    XSPI_Type *baseAddr = Xspi_Ip_BaseAddress[instance];

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(instance < XSPI_IP_MEM_INSTANCE_COUNT);
#endif

    /* MDADs and FRADs lock and enable */
    Xspi_Ip_Sfp_Lock(instance, &(userConfigPtr->SfpCfg));

    Xspi_Ip_CfgPrioTg1(baseAddr, userConfigPtr->Tg1FixPrio);

    if (userConfigPtr->lockConfiguration)
    {
        /* Lock global configuration and LUT-related registers (MGC[GCLCK] = 01b) */
        Xspi_Ip_GlobaConfigurationLock(instance);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_IpCommand
 * Description   : Launches a sync IP command
 * @implements     Xspi_Ip_IpCommand_Activity */
Xspi_Ip_StatusType Xspi_Ip_IpCommand(XSPI_Type *baseAddr,
                                     uint8 SeqId,
                                     uint32 addr
                                    )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(baseAddr != NULL_PTR);
    DEV_ASSERT_XSPI(SeqId < (XSPI_REG(LUT_COUNT) / FEATURE_XSPI_LUT_SEQUENCE_SIZE));
#endif

    /* Clear FR[TFF] and any error flags */
    Xspi_Ip_ClearStatus(baseAddr);

    if (STATUS_XSPI_IP_SUCCESS == Xspi_Ip_SetIpAddr(baseAddr, addr))
    {
        /* Set IPCR (SeqID, Size) */
        Xspi_Ip_IpTrigger(baseAddr, SeqId, 0U, FALSE, FALSE);

        MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_IPCOMMAND);

        /* Wait until the command is sent - poll for FR[TFF] = 1  */
        status = Xspi_Ip_CmdWaitComplete(baseAddr);
    }

    return status;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_IpRead
 * Description   : Launches a sync read command
 * @implements     Xspi_Ip_IpRead_Activity */
Xspi_Ip_StatusType Xspi_Ip_IpRead(XSPI_Type *baseAddr,
                                  uint8 SeqId,
                                  uint32 addr,
                                  uint8 * dataRead,
                                  const uint8 * dataCmp,
                                  uint32 size
                                 )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;
    uint32 padding;
    uint16 Idatsz = 0U;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(baseAddr != NULL_PTR);
    DEV_ASSERT_XSPI(SeqId < (XSPI_REG(LUT_COUNT) / FEATURE_XSPI_LUT_SEQUENCE_SIZE));
    DEV_ASSERT_XSPI(size <= FEATURE_XSPI_RX_BUF_SIZE);
#endif

    padding = (uint32)(Xspi_Ip_MemoryPadding);
    /* If size is odd, round up to even size; this is needed in octal DDR mode */
    Idatsz = (uint16)((size + 1U) & (~1U));

    /* Clear FR[TFF] and any error flags */
    Xspi_Ip_ClearStatus(baseAddr);

    if (STATUS_XSPI_IP_SUCCESS == Xspi_Ip_SetIpAddr(baseAddr, addr))
    {
        /* Set IPCR (SeqID, Size) */
        Xspi_Ip_IpTrigger(baseAddr, SeqId, Idatsz, FALSE, FALSE);

        MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_IPREAD);

        /* Wait until the command is sent - poll for FR[TFF] = 1  */
        status = Xspi_Ip_CmdWaitComplete(baseAddr);
    }

    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Read data from Rx buffer and process it */
        if (dataRead != NULL_PTR)
        {
            /* Normal read */
            status = Xspi_Ip_ProcessDataRead(dataRead, size, baseAddr, padding);
        }
        else if (dataCmp != NULL_PTR)
        {
            /* Verify */
            status = Xspi_Ip_ProcessDataVerify(dataCmp, size, baseAddr, padding);
        }
        else
        {
            /* Blank check */
            status = Xspi_Ip_ProcessDataBlankCheck(size, baseAddr, padding);
        }
    }
    /* Start of exclusive area */
    SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_06();
    /* Reset Rx fifo */
    Xspi_Ip_ClearRxBuf(baseAddr);
    /* End of exclusive area */
    SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_06();

    /* Clear padding, only needed for the first read */
    Xspi_Ip_MemoryPadding = (uint8)0U;

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ControllerArbLock
 * Description   : Launches an async read command with arbitration lock request
 * Xspi_Ip_ControllerArbLock_Activity */
Xspi_Ip_StatusType Xspi_Ip_ControllerArbLock(XSPI_Type *baseAddr,
                                             uint8 SeqId,
                                             uint32 addr,
                                             uint32 size
                                            )
{
    Xspi_Ip_StatusType Status = STATUS_XSPI_IP_ERROR;
    uint16 Idatsz = 0u;

    #if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(baseAddr != NULL_PTR);
    DEV_ASSERT_XSPI(SeqId < (XSPI_REG(LUT_COUNT) / FEATURE_XSPI_LUT_SEQUENCE_SIZE));
    DEV_ASSERT_XSPI(size <= FEATURE_XSPI_RX_BUF_SIZE);
    #endif

    /* If size is odd, round up to even size; this is needed in octal DDR mode */
    Idatsz = (uint16)((size + 1U) & (~1U));

    /* Clear FR[TFF] and any error flags */
    Xspi_Ip_ClearStatus(baseAddr);

    /* Dummy read with SFP_TG_IPCR[ARB_LOCK] set to request arbitration lock */
    if (STATUS_XSPI_IP_SUCCESS == Xspi_Ip_SetIpAddr(baseAddr, addr))
    {
        /* Set IPCR (SeqID, Size). Request arbitration lock */
        Xspi_Ip_IpTrigger(baseAddr, SeqId, Idatsz, TRUE, FALSE);

        Status = STATUS_XSPI_IP_SUCCESS;
    }

    return Status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ControllerGetStatus
 * Description   : Checks the completion status of an async IP command
 * @implements     Xspi_Ip_ControllerGetStatus_Activity */
Xspi_Ip_StatusType Xspi_Ip_ControllerGetStatus(XSPI_Type *baseAddr)
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_BUSY;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(baseAddr != NULL_PTR);
#endif

    MCAL_FAULT_INJECTION_POINT(XSPI_IP_FMEA_CONTROLLER_GET_STATUS);

    /* Check if transaction is stuck after winning arbitration because there is leftover data in Rx FIFO  */
    if (Xspi_Ip_GetFsmValid(baseAddr) && (Xspi_Ip_GetFsmState(baseAddr) == 0U))
    {
        /* Start of exclusive area */
        SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_08();
        /* Clear Rx FIFO  */
        Xspi_Ip_ClearRxBuf(baseAddr);
        /* End of exclusive area */
        SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_08();
    }
    /* Check if transaction is complete  */
    if (Xspi_Ip_GetTransactionFinished(baseAddr))
    {
        status = STATUS_XSPI_IP_SUCCESS;
    }

    /* Check for errors  */
    if (baseAddr->ERRSTAT & XSPI_ERRSTAT_ERR_FLAGS_MASK)
    {
        status = STATUS_XSPI_IP_ERROR;
    }
    if (baseAddr->FR & XSPI_FR_ERR_FLAGS_MASK)
    {
        status = STATUS_XSPI_IP_ERROR;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_IpCompleteAsyncRead
 * Description   : Completes an async read command
 * Xspi_Ip_IpCompleteAsyncRead_Activity */
Xspi_Ip_StatusType Xspi_Ip_IpCompleteAsyncRead(XSPI_Type *baseAddr,
                                               uint8 * dataRead,
                                               uint32 size
                                              )
{
    Xspi_Ip_StatusType status;
    uint32 padding = 0U;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(baseAddr != NULL_PTR);
#endif

    padding = (uint32)(Xspi_Ip_MemoryPadding);

    /* Read data from Rx buffer */
    /* Arbitration lock request is always normal read */
    status = Xspi_Ip_ProcessDataRead(dataRead, size, baseAddr, padding);

    /* Start of exclusive area */
    SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_09();
    /* Reset Rx fifo */
    Xspi_Ip_ClearRxBuf(baseAddr);
    /* End of exclusive area */
    SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_09();

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ControllerArbUnlock
 * Description   : Launches a sync read command with arbitration unlock request
 * Xspi_Ip_ControllerArbUnlock_Activity */
Xspi_Ip_StatusType Xspi_Ip_ControllerArbUnlock(XSPI_Type *baseAddr,
                                               uint8 SeqId,
                                               uint32 addr,
                                               uint8 * dataRead,
                                               uint32 size
                                              )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;
    uint16 Idatsz = 0u;

    #if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(baseAddr != NULL_PTR);
    DEV_ASSERT_XSPI(SeqId < (XSPI_REG(LUT_COUNT) / FEATURE_XSPI_LUT_SEQUENCE_SIZE));
    DEV_ASSERT_XSPI(size <= FEATURE_XSPI_RX_BUF_SIZE);
    #endif

    /* If size is odd, round up to even size; this is needed in octal DDR mode */
    Idatsz = (uint16)((size + 1U) & (~1U));

    /* Clear FR[TFF] and any error flags */
    Xspi_Ip_ClearStatus(baseAddr);

    if (STATUS_XSPI_IP_SUCCESS == Xspi_Ip_SetIpAddr(baseAddr, addr))
    {
        /* Dummy read with SFP_TG_IPCR[ARB_UNLOCK] set to request arbitration unlock */
        Xspi_Ip_IpTrigger(baseAddr, SeqId, Idatsz, FALSE, TRUE);

        /* Wait until the command is sent - poll for FR[TFF] = 1  */
        status = Xspi_Ip_CmdWaitComplete(baseAddr);
    }

    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Arbitration unlock request is always normal read */
        status = Xspi_Ip_ProcessDataRead(dataRead, size, baseAddr, 0U);
    }

    /* Reset Rx fifo */
    Xspi_Ip_ClearRxBuf(baseAddr);

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_IpWrite
 * Description   : Launches a sync write command
 * @implements     Xspi_Ip_IpWrite_Activity */
Xspi_Ip_StatusType Xspi_Ip_IpWrite(XSPI_Type *baseAddr,
                                   uint8 SeqId,
                                   uint32 addr,
                                   const uint8 * data,
                                   uint32 size
                                  )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;
    uint32 padding;
    uint16 TotalSize;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(baseAddr != NULL_PTR);
    DEV_ASSERT_XSPI(SeqId < (XSPI_REG(LUT_COUNT) / FEATURE_XSPI_LUT_SEQUENCE_SIZE));
    DEV_ASSERT_XSPI(size <= FEATURE_XSPI_TX_BUF_SIZE);
#endif
    /* Start of exclusive area */
    SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_07();
    /* Clear FR[TFF] and any error flags */
    Xspi_Ip_ClearStatus(baseAddr);

    padding = Xspi_Ip_MemoryPadding;
    TotalSize = (uint16)(size + (padding >> 4U) + (padding & 0x0FU));
/* Check total data size need to be written is aligned with 4-bytes to avoid invalid value when setup watermark */
    if (((TotalSize % 4U) != 0U) && (TotalSize > 4U))
    {
        TotalSize += (4U - (TotalSize % 4U));
    }
    Xspi_Ip_MemoryPadding = 0U;  /* Clear padding */

    if (STATUS_XSPI_IP_SUCCESS == Xspi_Ip_SetIpAddr(baseAddr, addr))
    {
        /* Set water mark in TBCT such that SR[TXWA] flag is de-asserted when all data is in the Tx FIFO */
        Xspi_Ip_SetTxWatermark(baseAddr, (uint8)((FEATURE_XSPI_TX_BUF_SIZE >> 2U) - ((TotalSize >> 2U) - 1U)));

        /* Set IPCR (SeqID, Size) */
        Xspi_Ip_IpTrigger(baseAddr, SeqId, TotalSize, FALSE, FALSE);

        /* Wait for arbitration win: Poll for FSMSTAT[VLD] = 1, FSMSTAT[MID] = MasterID, FSMSTAT[STATE] = 01 */
        status = Xspi_Ip_CmdWaitArbitration(baseAddr);
    }

    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Clear Tx buffer (MCR[CLR_TXF] + wait) */
        Xspi_Ip_InvalidateTxBuf(baseAddr);
        /* Fill Tx buffer */
        /* Command execution starts automatically when Tx FIFO is filled to watermark */
        Xspi_Ip_FillTxBuf(baseAddr, data, size, padding);

        MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_IPWRITE);

        /* Wait until the command is sent - poll for FR[TFF] = 1  */
        status = Xspi_Ip_CmdWaitComplete(baseAddr);
    }
    /* End of exclusive area */
    SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_07();

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_IpHyperRamErase
 * Description   : Launches a sync write command for erase on hyperram
*/
Xspi_Ip_StatusType Xspi_Ip_IpHyperRamErase(XSPI_Type *baseAddr,
                                   uint8 SeqId,
                                   uint32 addr,
                                   uint32 size
                                  )
{
    Xspi_Ip_StatusType status = STATUS_XSPI_IP_ERROR;
    uint16 TotalSize = size;

#if (XSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DEV_ASSERT_XSPI(baseAddr != NULL_PTR);
    DEV_ASSERT_XSPI(SeqId < (XSPI_REG(LUT_COUNT) / FEATURE_XSPI_LUT_SEQUENCE_SIZE));
    DEV_ASSERT_XSPI(size <= FEATURE_XSPI_TX_BUF_SIZE);
#endif

    /* Clear FR[TFF] and any error flags */
    Xspi_Ip_ClearStatus(baseAddr);

    if (STATUS_XSPI_IP_SUCCESS == Xspi_Ip_SetIpAddr(baseAddr, addr))
    {
        /* Set water mark in TBCT such that SR[TXWA] flag is de-asserted when all data is in the Tx FIFO */
        Xspi_Ip_SetTxWatermark(baseAddr, (uint8)((FEATURE_XSPI_TX_BUF_SIZE >> 2U) - ((TotalSize >> 2U) - 1U)));

        /* Set IPCR (SeqID, Size) */
        Xspi_Ip_IpTrigger(baseAddr, SeqId, TotalSize, FALSE, FALSE);

        /* Wait for arbitration win: Poll for FSMSTAT[VLD] = 1, FSMSTAT[MID] = MasterID, FSMSTAT[STATE] = 01 */
        status = Xspi_Ip_CmdWaitArbitration(baseAddr);
    }

    if (STATUS_XSPI_IP_SUCCESS == status)
    {
        /* Clear Tx buffer (MCR[CLR_TXF] + wait) */
        Xspi_Ip_InvalidateTxBuf(baseAddr);

        /* Fill Tx buffer 0xFFFFFFFF for errase*/
        while (TotalSize >= 4U)
        {
            Xspi_Ip_WriteTxData(baseAddr, 0xFFFFFFFFUL);
            TotalSize -= 4U;
        }
        /* Wait until the command is sent - poll for FR[TFF] = 1  */
        status = Xspi_Ip_CmdWaitComplete(baseAddr);
    }

    return status;
}

#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

#endif /* (XSPI_IP_MEM_INSTANCE_COUNT > 0) */


#ifdef __cplusplus
}
#endif

/** @} */
