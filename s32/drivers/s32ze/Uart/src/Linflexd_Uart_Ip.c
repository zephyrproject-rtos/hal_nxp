/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file     Linflexd_Uart_Ip.c
*   @defgroup linflexd_uart_ip Linflexd UART IPL
*   @addtogroup  linflexd_uart_ip Linflexd UART IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Linflexd_Uart_Ip.h"
#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
    #include "Dma_Ip.h"
#endif

#ifdef LINFLEXD_UART_IP_DEV_ERROR_DETECT
    #if (LINFLEXD_UART_IP_DEV_ERROR_DETECT == STD_ON)
        #include "Devassert.h"
    #endif /* (STD_ON == LINFLEXD_UART_IP_DEV_ERROR_DETECT) */
#endif /* ifdef LINFLEXD_UART_IP_DEV_ERROR_DETECT */

#if (STD_ON == LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE)
    #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
    #include "RegLockMacros.h"
#endif
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LINFLEXD_UART_IP_VENDOR_ID_C                      43
#define LINFLEXD_UART_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define LINFLEXD_UART_IP_AR_RELEASE_MINOR_VERSION_C       7
#define LINFLEXD_UART_IP_AR_RELEASE_REVISION_VERSION_C    0
#define LINFLEXD_UART_IP_SW_MAJOR_VERSION_C               0
#define LINFLEXD_UART_IP_SW_MINOR_VERSION_C               9
#define LINFLEXD_UART_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Linflexd_Uart_Ip.h */
#if (LINFLEXD_UART_IP_VENDOR_ID_C != LINFLEXD_UART_IP_VENDOR_ID)
    #error "Linflexd_Uart_Ip.c and Linflexd_Uart_Ip.h have different vendor ids"
#endif
#if ((LINFLEXD_UART_IP_AR_RELEASE_MAJOR_VERSION_C    != LINFLEXD_UART_IP_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_AR_RELEASE_MINOR_VERSION_C    != LINFLEXD_UART_IP_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_AR_RELEASE_REVISION_VERSION_C != LINFLEXD_UART_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Linflexd_Uart_Ip.c and Linflexd_Uart_Ip.h are different"
#endif
#if ((LINFLEXD_UART_IP_SW_MAJOR_VERSION_C != LINFLEXD_UART_IP_SW_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_SW_MINOR_VERSION_C != LINFLEXD_UART_IP_SW_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_SW_PATCH_VERSION_C != LINFLEXD_UART_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Linflexd_Uart_Ip.c and Linflexd_Uart_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Dma_Ip.h */
    #if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
        #if ((LINFLEXD_UART_IP_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
             (LINFLEXD_UART_IP_AR_RELEASE_MINOR_VERSION_C != DMA_IP_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Linflexd_Uart_Ip.c and Dma_Ip.h are different"
        #endif
    #endif

    /* Checks against RegLockMacros.h */
    #if (STD_ON == LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE)
        #if ((LINFLEXD_UART_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
             (LINFLEXD_UART_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Linflexd_Uart_Ip.c and RegLockMacros.h are different"
        #endif
    #endif

    /* Checks against Devassert.h */
    #ifdef LINFLEXD_UART_IP_DEV_ERROR_DETECT
        #if (LINFLEXD_UART_IP_DEV_ERROR_DETECT == STD_ON)
            #if ((LINFLEXD_UART_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
                 (LINFLEXD_UART_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Linflexd_Uart_Ip.c and Devassert.h are different"
        #endif
        #endif /* (STD_ON == LINFLEXD_UART_IP_DEV_ERROR_DETECT) */
    #endif /* idfef LINFLEXD_UART_IP_DEV_ERROR_DETECT */
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

#ifdef LINFLEXD_UART_IP_DEV_ERROR_DETECT
    #if (LINFLEXD_UART_IP_DEV_ERROR_DETECT == STD_ON)
        #define LINFLEXD_UART_IP_DEV_ASSERT(x)      DevAssert(x)
    #else
        #define LINFLEXD_UART_IP_DEV_ASSERT(x)      (void)(x)
    #endif
#endif

/* @brief Address of the least significant byte or word in a 32-bit register (depends on endianness) */
#define LINFLEXD_UART_IP_LSBW_ADDR(reg)  ((uint32)(&(reg)))

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
    #define LINFLEXD_UART_IP_DMA_CONFIG_LIST_DIMENSION             (10U)
    #define LINFLEXD_UART_DMA_LEAST_CONFIG_LIST_DIMENSION       (2U)
#endif

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define UART_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Uart_MemMap.h"

/** @brief Array of UART driver runtime state structures */
VAR_SEC_NOCACHE(Linflexd_Uart_Ip_apStateStructure) Linflexd_Uart_Ip_StateStructureType Linflexd_Uart_Ip_apStateStructure[LINFLEXD_UART_IP_NUMBER_OF_INSTANCES];

#define UART_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Uart_MemMap.h"

#define UART_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Uart_MemMap.h"

/** @brief User config structure. */
static const Linflexd_Uart_Ip_UserConfigType* Linflexd_Uart_Ip_apUserConfig[LINFLEXD_INSTANCE_COUNT];

#define UART_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Uart_MemMap.h"

#define UART_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Uart_MemMap.h"

/** @brief Array of pointers to UART driver runtime state structures */
static Linflexd_Uart_Ip_StateStructureType* Linflexd_Uart_Ip_apStateStructuresArray[LINFLEXD_INSTANCE_COUNT];

#define UART_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Uart_MemMap.h"

#define UART_START_SEC_CONST_UNSPECIFIED
#include "Uart_MemMap.h"

/** @brief Table of base addresses for LINFLEXD instances. */
static LINFLEXD_Type* const Linflexd_Uart_Ip_apBases[LINFLEXD_INSTANCE_COUNT] = IP_LINFLEXD_BASE_PTRS;

#define UART_STOP_SEC_CONST_UNSPECIFIED
#include "Uart_MemMap.h"

#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
#define UART_START_SEC_CONST_BOOLEAN
#include "Uart_MemMap.h"

/** @brief Table storing DMA capabilities for LINFLEXD instances. */
static const boolean Linflexd_Uart_Ip_InstHasDma[LINFLEXD_INSTANCE_COUNT] = LINFLEXD_UART_IP_INST_HAS_DMA;

#define UART_STOP_SEC_CONST_BOOLEAN
#include "Uart_MemMap.h"
#endif

#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
#define UART_START_SEC_CONST_BOOLEAN
#include "Uart_MemMap.h"

/** @brief Table storing timeout interrupt capabilities for LINFLEXD instances. */
static const boolean Linflexd_Uart_Ip_InstHasTimeoutInterruptEnabled[LINFLEXD_INSTANCE_COUNT] = LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT_PER_INSTANCE;

#define UART_STOP_SEC_CONST_BOOLEAN
#include "Uart_MemMap.h"
#endif

#if (LINFLEXD_UART_IP_ENABLE_INTERNAL_LOOPBACK == STD_ON)
#define UART_START_SEC_CONST_BOOLEAN
#include "Uart_MemMap.h"

/** @brief Table storing internal loopback capabilities for LINFLEXD instances. */
static const boolean Linflexd_Uart_Ip_InstHasLoopbackEnabled[LINFLEXD_INSTANCE_COUNT] = LINFLEXD_UART_IP_ENABLE_INTERNAL_LOOPBACK_PER_INSTANCE;

#define UART_STOP_SEC_CONST_BOOLEAN
#include "Uart_MemMap.h"
#endif
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#define UART_START_SEC_CODE
#include "Uart_MemMap.h"

static Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_StartSendUsingInterrupts(const uint8 Instance,
                                                                             const uint8 * TxBuff,
                                                                             const uint32 TxSize);
static Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_StartReceiveUsingInterrupts(const uint8 Instance,
                                                                                uint8 * RxBuff,
                                                                                const uint32 RxSize);
static void Linflexd_Uart_Ip_CompleteSendUsingInterrupts(const uint8 Instance);
static void Linflexd_Uart_Ip_CompleteReceiveUsingInterrupts(const uint8 Instance);
#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
static Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_StartSendUsingDma(const uint8 Instance,
                                                                      const uint8 * TxBuff,
                                                                      const uint32 TxSize);
static Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_StartReceiveUsingDma(const uint8 Instance,
                                                                         uint8 * RxBuff,
                                                                         const uint32 RxSize);
static void Linflexd_Uart_Ip_FlushRxFifo(const LINFLEXD_Type *Base,const Linflexd_Uart_Ip_WordLengthType WordLength);
#endif
static void Linflexd_Uart_Ip_PutData(const uint8 Instance);
static void Linflexd_Uart_Ip_GetData(const uint8 Instance);
static void Linflexd_Uart_Ip_SetWordLength(const uint8 Instance);
static void Linflexd_Uart_Ip_SetUp_Init(const uint8 Instance);
static void Linflexd_Uart_Ip_SetUp_Receiver(const uint8 Instance);
static void Linflexd_Uart_Ip_UpdateReceiver(const uint8 Instance, uint32 * StartTime, uint32 * ElapsedTicks, uint32 TimeoutTicks);
static void Linflexd_Uart_Ip_GetRemainingBytes(const uint8 Instance, uint32 * BytesRemaining, Linflexd_Uart_Ip_DataDirectionType Direction);
#if (STD_ON == LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE)
void Linflexd_Uart_Ip_SetUserAccess(const uint8 Instance);
static void Linflexd_Uart_Ip_SetUserAccessAllowed(const uint8 Instance);
#endif /* LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE */

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/* implements     Linflexd_Uart_Ip_SetBaudrate_Activity*/
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_SetBaudrate(const uint8 Instance,
                                                         const Linflexd_Uart_Ip_BaudrateType DesiredBaudRate,
                                                         const uint32 ClockFrequency)
{

    LINFLEXD_UART_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);

    LINFLEXD_Type * Base;
    float32 Prescaler;
    float32 Fraction;
    float32 Numerator;
    uint32 Mantissa;
    uint32 FractionDenominator;
    uint32 StartTime;
    uint32 TimeoutTicks;
    uint32 ElapsedTicks = 0;
    boolean ResetIdle = FALSE;
    boolean IsReturn = FALSE;
    Linflexd_Uart_Ip_StateStructureType * UartState;
    Linflexd_Uart_Ip_StatusType Status = LINFLEXD_UART_IP_STATUS_ERROR;
    uint8 FractionNumerator;

    Base = Linflexd_Uart_Ip_apBases[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];

    LINFLEXD_UART_IP_DEV_ASSERT(UartState != NULL_PTR);

    if ((TRUE == UartState->IsTxBusy) || (TRUE == UartState->IsRxBusy))
    {
        Status = LINFLEXD_UART_IP_STATUS_BUSY;
    }
    else
    {
        /* Compute the values for baud rate divider Mantissa and Fraction */
        Prescaler = (float32)ClockFrequency / ((float32)DesiredBaudRate * (float32)DEFAULT_OSR);
        Mantissa = (uint32)Prescaler;
        Fraction = Prescaler - (float32)Mantissa;
        FractionDenominator = ((uint32)1U << (uint32)BAUDRATE_FRACTION_WIDTH);
        Numerator = ((float32)Fraction * (float32)FractionDenominator) + (float32)0.5F;
        FractionNumerator = (uint8)(Numerator);

        if (FractionNumerator == FractionDenominator)
        {
            FractionNumerator = 0;
            Mantissa++;
        }

        if (Linflexd_Uart_Ip_GetLinState(Base) != LINFLEXD_STATE_INIT_MODE)
        {
            /* Request init mode and wait until the mode entry is complete */
            Linflexd_Uart_Ip_EnterInitMode(Base);

            Linflexd_Uart_Ip_StartTimeout(&StartTime, &TimeoutTicks, (uint32)LINFLEXD_UART_IP_TIMEOUT_VALUE_US, LINFLEXD_UART_IP_TIMEOUT_TYPE);

            while (!Linflexd_Uart_Ip_CheckTimeout(&StartTime, &ElapsedTicks, TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_TYPE) &&
                   (Linflexd_Uart_Ip_GetLinState(Base) != LINFLEXD_STATE_INIT_MODE)) {}

            /* Init mode error */
            if (Linflexd_Uart_Ip_GetLinState(Base) != LINFLEXD_STATE_INIT_MODE)
            {
                Status = LINFLEXD_UART_IP_STATUS_ERROR;
                IsReturn = TRUE;
            }
            else
            {
                ResetIdle = TRUE;
            }
        }
        if (!IsReturn)
        {
            /* Write the computed values to registers */
            Linflexd_Uart_Ip_SetIntegerBaudRate(Base, Mantissa);
            Linflexd_Uart_Ip_SetFractionalBaudRate(Base, FractionNumerator);

            if (TRUE == ResetIdle)
            {
                /* Enter normal mode */
                Linflexd_Uart_Ip_EnterNormalMode(Base);
            }
            /* Save current baudrate value */
            UartState->Baudrate = (uint32)DesiredBaudRate;
            Status = LINFLEXD_UART_IP_STATUS_SUCCESS;
        }
    }
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_GetBaudrate
 * Description   : This function retrieves the baud rate for UART communication.
 *
*END**************************************************************************/
/* implements     Linflexd_Uart_Ip_GetBaudrate_Activity*/
void Linflexd_Uart_Ip_GetBaudrate(const uint8 Instance, uint32 * ConfiguredBaudRate)
{
    LINFLEXD_UART_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
    LINFLEXD_UART_IP_DEV_ASSERT(ConfiguredBaudRate != NULL_PTR);

    const Linflexd_Uart_Ip_StateStructureType *UartStatePtr;
    UartStatePtr = Linflexd_Uart_Ip_apStateStructuresArray[Instance];

    LINFLEXD_UART_IP_DEV_ASSERT(UartStatePtr != NULL_PTR);

    *ConfiguredBaudRate = UartStatePtr->Baudrate;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_Init
 * Description   : This function initializes a LINFLEXD instance for UART
 * operation.
 * This function will initialize the run-time state structure to keep track of
 * the on-going transfers, initialize the module to user defined settings and
 * default settings, enable the module-level interrupt to the core, and enable
 * the UART module transmitter and receiver.
 *
 *END**************************************************************************/
/* implements     Linflexd_Uart_Ip_Init_Activity*/
void Linflexd_Uart_Ip_Init(const uint8 Instance, const Linflexd_Uart_Ip_UserConfigType * UserConfig)
{
    uint32 Index;
    uint32 StartTime;
    uint32 TimeoutTicks;
    uint32 ElapsedTicks = 0;
    uint8 *ClearStructPtr;

    LINFLEXD_UART_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
    LINFLEXD_UART_IP_DEV_ASSERT(NULL_PTR == Linflexd_Uart_Ip_apStateStructuresArray[Instance]);
    LINFLEXD_UART_IP_DEV_ASSERT(UserConfig != NULL_PTR);
#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
    /* Check if an instance with no DMA support is configured in DMA mode */
    LINFLEXD_UART_IP_DEV_ASSERT((UserConfig->TransferType != LINFLEXD_UART_IP_USING_DMA) || Linflexd_Uart_Ip_InstHasDma[Instance]);
#endif
    LINFLEXD_Type * Base = Linflexd_Uart_Ip_apBases[Instance];
    Linflexd_Uart_Ip_apStateStructuresArray[Instance] = UserConfig->StateStruct;

    Linflexd_Uart_Ip_StateStructureType *UartStatePtr = Linflexd_Uart_Ip_apStateStructuresArray[Instance];
    Linflexd_Uart_Ip_apUserConfig[Instance] = UserConfig;
    ClearStructPtr = (uint8 *)UartStatePtr;

    /* Clear the state struct for this Instance. */
    for (Index = 0; Index < sizeof(Linflexd_Uart_Ip_StateStructureType); Index++)
    {
        ClearStructPtr[Index] = 0U;
    }
#if (STD_ON == LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE)
    Linflexd_Uart_Ip_SetUserAccessAllowed(Instance);
#endif
    /* Request init mode and wait until the mode entry is complete */
    Linflexd_Uart_Ip_EnterInitMode(Base);

    UartStatePtr->IsDriverInitialized = FALSE;

    Linflexd_Uart_Ip_StartTimeout(&StartTime, &TimeoutTicks, (uint32)LINFLEXD_UART_IP_TIMEOUT_VALUE_US, LINFLEXD_UART_IP_TIMEOUT_TYPE);
    while (!Linflexd_Uart_Ip_CheckTimeout(&StartTime, &ElapsedTicks, TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_TYPE) &&
           (Linflexd_Uart_Ip_GetLinState(Base) != LINFLEXD_STATE_INIT_MODE)) {}

    if (LINFLEXD_STATE_INIT_MODE == Linflexd_Uart_Ip_GetLinState(Base))
    {
        UartStatePtr->IsDriverInitialized = TRUE;
    }

    /* Set up UART mode, baud rate, word length, parity, stop bits count and enable FIFO. */
    Linflexd_Uart_Ip_SetUp_Init(Instance);

    /* Enter normal mode */
    Linflexd_Uart_Ip_EnterNormalMode(Base);

    Linflexd_Uart_Ip_SetTransmitterState(Base, FALSE);
    Linflexd_Uart_Ip_SetReceiverState(Base, FALSE);

    /* initialize last driver operation status */
    UartStatePtr->TransmitStatus = LINFLEXD_UART_IP_STATUS_SUCCESS;
    UartStatePtr->ReceiveStatus = LINFLEXD_UART_IP_STATUS_SUCCESS;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_Deinit
 * Description   : This function shuts down the UART by disabling interrupts and
 *                 transmitter/receiver.
 *
*END**************************************************************************/
/* implements     Linflexd_Uart_Ip_Deinit_Activity */
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_Deinit(const uint8 Instance)
{
    LINFLEXD_UART_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);

    LINFLEXD_Type * Base;
    Linflexd_Uart_Ip_StatusType RetVal;
    const Linflexd_Uart_Ip_StateStructureType * UartState;
    uint32 StartTime;
    uint32 TimeoutTicks;
    uint32 ElapsedTicks = 0;

    Base = Linflexd_Uart_Ip_apBases[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];

    Linflexd_Uart_Ip_StartTimeout(&StartTime, &TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_VALUE_US, LINFLEXD_UART_IP_TIMEOUT_TYPE);
    /* Wait until the data is completely shifted out of shift register */
    while ((UartState->IsTxBusy || UartState->IsRxBusy) && \
           !Linflexd_Uart_Ip_CheckTimeout(&StartTime, &ElapsedTicks, TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_TYPE))
    {}
    /* Disable Tx data register empty and transmission complete interrupt */
    if (Linflexd_Uart_Ip_CheckTimeout(&StartTime, &ElapsedTicks, TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_TYPE))
    {
        RetVal = LINFLEXD_UART_IP_STATUS_ERROR;
    }
    else
    {
        /* Calling Linflexd_Uart_Ip_Deinit shall disable the transmitter and reciever. */
        /* Disable transmission complete interrupt */
        Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_DATA_TRANSMITTED_INT, FALSE);
        /* Disable receive data full interrupt. */
        Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_DATA_RECEPTION_COMPLETE_INT, FALSE);

        /* Calling Linflexd_Uart_Ip_Deinit shall disable error interrupts (rx overrun and framing error).*/
        /* Disable error interrupts */
        Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_FRAME_ERROR_INT, FALSE);
        Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_BUFFER_OVERRUN_INT, FALSE);
#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
    if (Linflexd_Uart_Ip_InstHasTimeoutInterruptEnabled[Instance])
    {
        /* Disable timeout interrupt */
        Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_TIMEOUT_INT, FALSE);
    }
#endif

        /* Clear the saved pointer to the state structure */
        Linflexd_Uart_Ip_apStateStructuresArray[Instance] = NULL_PTR;

        RetVal = LINFLEXD_UART_IP_STATUS_SUCCESS;
    }
    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_SetTxBuffer
 * Description   : Sets the driver internal reference to the tx buffer.
 *                 Can be called from the tx callback to provide a different
 *                 buffer for continuous transmission.
 *
*END**************************************************************************/
/* implements     Linflexd_Uart_Ip_SetTxBuffer_Activity */
void Linflexd_Uart_Ip_SetTxBuffer(const uint8 Instance,
                                  const uint8 * TxBuff,
                                  const uint32 TxSize)
{
    LINFLEXD_UART_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
    LINFLEXD_UART_IP_DEV_ASSERT(TxBuff != NULL_PTR);
    LINFLEXD_UART_IP_DEV_ASSERT(TxSize > 0U);

    Linflexd_Uart_Ip_StateStructureType * UartState;

    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];

    LINFLEXD_UART_IP_DEV_ASSERT(UartState != NULL_PTR);

    UartState->TxBuff = TxBuff;
    UartState->TxSize = TxSize;

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_SetRxBuffer
 * Description   : Sets the driver internal reference to the rx buffer.
 *                 Can be called from the rx callback to provide a different
 *                 buffer for continuous reception.
 *
*END**************************************************************************/
/* implements     Linflexd_Uart_Ip_SetRxBuffer_Activity */
void Linflexd_Uart_Ip_SetRxBuffer(const uint8 Instance,
                                  uint8 * RxBuff,
                                  const uint32 RxSize)
{
    LINFLEXD_UART_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
    LINFLEXD_UART_IP_DEV_ASSERT(RxBuff != NULL_PTR);
    LINFLEXD_UART_IP_DEV_ASSERT(RxSize > 0U);

    Linflexd_Uart_Ip_StateStructureType * UartState;

    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];

    LINFLEXD_UART_IP_DEV_ASSERT(UartState != NULL_PTR);

    UartState->RxBuff = RxBuff;
    UartState->RxSize = RxSize;

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_PutData
 * Description   : Write data to the buffer register, according to configured
 * word length.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void Linflexd_Uart_Ip_PutData(const uint8 Instance)
{
    Linflexd_Uart_Ip_StateStructureType * UartState;
    LINFLEXD_Type * Base;
    const Linflexd_Uart_Ip_UserConfigType *UartUserCfg;
    Base = Linflexd_Uart_Ip_apBases[Instance];

    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];

    if ((LINFLEXD_UART_IP_7_BITS == UartUserCfg->WordLength) || (LINFLEXD_UART_IP_8_BITS == UartUserCfg->WordLength))
    {
        uint8 Data = *(UartState->TxBuff);
        /* Update the state structure */
        ++UartState->TxBuff;
        --UartState->TxSize;
        /* Transmit the Data */
        Linflexd_Uart_Ip_SetTxDataBuffer1Byte(Base, Data);
    }
    else
    {
        /* Transmit the Data and update state structure */
        if (1U == UartState->TxSize)
        {
            uint16 Data = (uint16)(*UartState->TxBuff);
            ++UartState->TxBuff;
            --UartState->TxSize;
            Linflexd_Uart_Ip_SetTxDataBuffer2Bytes(Base, Data);
        }
        else
        {
            uint16 Data = *((const uint16*)UartState->TxBuff);
            /* Move the pointer twice */
            ++UartState->TxBuff;
            ++UartState->TxBuff;
            UartState->TxSize -= 2U;
            Linflexd_Uart_Ip_SetTxDataBuffer2Bytes(Base, Data);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_CompleteSendUsingInterrupts
 * Description   : Finish up a transmit by completing the process of sending
 * Data and disabling the interrupt.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void Linflexd_Uart_Ip_CompleteSendUsingInterrupts(const uint8 Instance)
{
    Linflexd_Uart_Ip_StateStructureType * UartState;
    LINFLEXD_Type * Base;
    uint32 StartTime;
    uint32 TimeoutTicks = 0;
    uint32 ElapsedTicks = 0;

    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];
    Base = Linflexd_Uart_Ip_apBases[Instance];

    /* Disable transmission complete interrupt */
    Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_DATA_TRANSMITTED_INT, FALSE);
    /* In Abort case, the transmission need to stop instantly */
    /* In case the Abort function is called when the last byte is transmited
       checking the Data Transmission Complete flag in the while function will result in Timeout Error
       so the TxSize needs to be greater than zero. */
    if ((LINFLEXD_UART_IP_STATUS_ABORTED == UartState->TransmitStatus) && (UartState->TxSize > 0U))
    {
        Linflexd_Uart_Ip_StartTimeout(&StartTime, &TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_VALUE_US, LINFLEXD_UART_IP_TIMEOUT_TYPE);
        /* Wait until the data is completely shifted out of shift register */
        while (!Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_DATA_TRANSMITTED_FLAG) && \
               !Linflexd_Uart_Ip_CheckTimeout(&StartTime, &ElapsedTicks, TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_TYPE))
        {}
        if (Linflexd_Uart_Ip_CheckTimeout(&StartTime, &ElapsedTicks, TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_TYPE))
        {
            /* In case timeout occur */
            UartState->TransmitStatus = LINFLEXD_UART_IP_STATUS_TIMEOUT;
        }
        /* Clear data transmission completed flag */
        Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_DATA_TRANSMITTED_FLAG);
    }
    /* Disable the transmitter */
    Linflexd_Uart_Ip_SetTransmitterState(Base, FALSE);

    /* Update the information of the module driver state */
    UartState->IsTxBusy = FALSE;

    /* If the current transmission hasn't been aborted, update the status */
    if (LINFLEXD_UART_IP_STATUS_BUSY == UartState->TransmitStatus)
    {
        UartState->TransmitStatus = LINFLEXD_UART_IP_STATUS_SUCCESS;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_CompleteReceiveUsingInterrupts
 * Description   : Finish up a receive by completing the process of receiving data
 * and disabling the interrupt.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void Linflexd_Uart_Ip_CompleteReceiveUsingInterrupts(const uint8 Instance)
{
    Linflexd_Uart_Ip_StateStructureType * UartState;
    LINFLEXD_Type * Base;
    uint32 StartTime;
    uint32 TimeoutTicks;
    uint32 ElapsedTicks = 0;

    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];
    Base = Linflexd_Uart_Ip_apBases[Instance];

    /* Disable receive data full interrupt. */
    Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_DATA_RECEPTION_COMPLETE_INT, FALSE);

    /* Disable error interrupts */
    Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_FRAME_ERROR_INT, FALSE);
    Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_BUFFER_OVERRUN_INT, FALSE);
#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
    if (Linflexd_Uart_Ip_InstHasTimeoutInterruptEnabled[Instance])
    {
        /* Disable timeout interrupt */
        Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_TIMEOUT_INT, FALSE);
    }
#endif
    /* In Abort case, the transmission need to stop instantly */
    /* In case the Abort function is called when the last byte is received
       checking the Data Reception Complete flag in the while function will result in Timeout Error
       so the RxSize needs to be greater than zero. */
    if ((LINFLEXD_UART_IP_STATUS_ABORTED == UartState->ReceiveStatus) && (UartState->RxSize > 0U))
    {
        Linflexd_Uart_Ip_StartTimeout(&StartTime, &TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_VALUE_US, LINFLEXD_UART_IP_TIMEOUT_TYPE);
        /* Wait until the data is completely received */
        while (!Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_DATA_RECEPTION_COMPLETE_FLAG) && \
               !Linflexd_Uart_Ip_CheckTimeout(&StartTime, &ElapsedTicks, TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_TYPE))
        {}

        if (Linflexd_Uart_Ip_CheckTimeout(&StartTime, &ElapsedTicks, TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_TYPE))
        {
          /* In case timeout occur */
            UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_TIMEOUT;
        }
        /* Read dummy to get all data remaning */
        Linflexd_Uart_Ip_GetData(Instance);
        /* Clear data reception completed flag  */
        Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_DATA_RECEPTION_COMPLETE_FLAG);
    }
#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
    if (LINFLEXD_UART_IP_STATUS_RX_IDLE_STATE != UartState->ReceiveStatus)
#endif
    {
        /* Disable the receiver */
        Linflexd_Uart_Ip_SetReceiverState(Base, FALSE);
    }

    /* Update the information of the module driver state */
    UartState->IsRxBusy = FALSE;

    /* If the current reception hasn't been aborted and no error occurred, update the status */
    if (LINFLEXD_UART_IP_STATUS_BUSY == UartState->ReceiveStatus)
    {
        UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_SUCCESS;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_SyncSend
 * Description   : Send out multiple bytes of data using polling method.
 *
 *END**************************************************************************/
 /* implements    Linflexd_Uart_Ip_SyncSend_Activity */
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_SyncSend(const uint8 Instance,
                                                      const uint8 *TxBuff,
                                                      const uint32 TxSize,
                                                      const uint32 Timeout)
{

    /* Check the validity of the parameters */
    LINFLEXD_UART_IP_DEV_ASSERT(TxSize > 0U);
    LINFLEXD_UART_IP_DEV_ASSERT(TxBuff != NULL_PTR);
    LINFLEXD_UART_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);

    Linflexd_Uart_Ip_StateStructureType * UartState;
    LINFLEXD_Type * Base;
    uint32 StartTime;
    uint32 TimeoutTicks;
    uint32 ElapsedTicks = 0;
    Linflexd_Uart_Ip_StatusType Status = LINFLEXD_UART_IP_STATUS_TIMEOUT;
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];
    Base = Linflexd_Uart_Ip_apBases[Instance];

    LINFLEXD_UART_IP_DEV_ASSERT(UartState != NULL_PTR);

    SchM_Enter_Uart_UART_EXCLUSIVE_AREA_03();
    /* Check driver is not busy transmitting data from a previous asynchronous call */
    if (UartState->IsTxBusy)
    {
        SchM_Exit_Uart_UART_EXCLUSIVE_AREA_03();
        Status = LINFLEXD_UART_IP_STATUS_BUSY;
    }
    else
    {
         /* Initialize the module driver state structure */
        UartState->IsTxBusy = TRUE;
        SchM_Exit_Uart_UART_EXCLUSIVE_AREA_03();
        UartState->TxBuff = TxBuff;
        UartState->TxSize = TxSize;

        UartState->TransmitStatus = LINFLEXD_UART_IP_STATUS_BUSY;

        /* The interrupts shall be disabled when the Linflexd_Uart_Ip_SyncReceive and Linflexd_Uart_Ip_SyncSend are called. */
        /* Disble transmission complete interrupt */
        Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_DATA_TRANSMITTED_INT, FALSE);
        /* Disable receive data full interrupt. */
        Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_DATA_RECEPTION_COMPLETE_INT, FALSE);

        /* Disable error interrupts */
        Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_FRAME_ERROR_INT, FALSE);
        Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_BUFFER_OVERRUN_INT, FALSE);

        /* Enable the transmitter */
        Linflexd_Uart_Ip_SetTransmitterState(Base, TRUE);

        Linflexd_Uart_Ip_StartTimeout(&StartTime, &TimeoutTicks, Timeout, LINFLEXD_UART_IP_TIMEOUT_TYPE);

        while ((UartState->TxSize > 0U) && !Linflexd_Uart_Ip_CheckTimeout(&StartTime, &ElapsedTicks, TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_TYPE))
        {
            Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_DATA_TRANSMITTED_FLAG);
            Linflexd_Uart_Ip_PutData(Instance);
            /* Wait until data transmited flag is set or timeout occurs if there is an error during transmission */
            while (!Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_DATA_TRANSMITTED_FLAG) && \
                   !Linflexd_Uart_Ip_CheckTimeout(&StartTime, &ElapsedTicks, TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_TYPE))
            {}
        }
        Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_DATA_TRANSMITTED_FLAG);

        /* Disable the transmitter */
        Linflexd_Uart_Ip_SetTransmitterState(Base, FALSE);

        /* Check if Timeout occur */
        if (UartState->TxSize > 0U)
        {
            UartState->TransmitStatus = LINFLEXD_UART_IP_STATUS_TIMEOUT;
        }else /* The transmit process is complete */
        {
            UartState->TransmitStatus = LINFLEXD_UART_IP_STATUS_SUCCESS;
        }
        UartState->IsTxBusy = FALSE;
        Status = UartState->TransmitStatus;
    }
    return Status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_GetData
 * Description   : Read data from the buffer register, according to configured
 * word length.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void Linflexd_Uart_Ip_GetData(const uint8 Instance)
{
    const Linflexd_Uart_Ip_UserConfigType * UartUserCfg;
    Linflexd_Uart_Ip_StateStructureType * UartState;
    const LINFLEXD_Type * Base;

    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];
    Base = Linflexd_Uart_Ip_apBases[Instance];


    if ((LINFLEXD_UART_IP_7_BITS == UartUserCfg->WordLength) || (LINFLEXD_UART_IP_8_BITS == UartUserCfg->WordLength))
    {
        /* Get the data */
        *(UartState->RxBuff) = Linflexd_Uart_Ip_GetRxDataBuffer1Byte(Base);
        /* Update the state structure */
        ++UartState->RxBuff;
        --UartState->RxSize;
    }
    else
    {
        /* Get the data and update state structure */
        if (1U == UartState->RxSize)
        {
            *(UartState->RxBuff) = (uint8)(Linflexd_Uart_Ip_GetRxDataBuffer2Bytes(Base));
            ++UartState->RxBuff;
            --UartState->RxSize;
        }
        else
        {
            *((uint16*)(UartState->RxBuff)) = Linflexd_Uart_Ip_GetRxDataBuffer2Bytes(Base);
            /* Move the pointer twice */
            ++UartState->RxBuff;
            ++UartState->RxBuff;
            UartState->RxSize -= 2U;
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_SyncReceive
 * Description   : Retrieves data from the LINFLEXD module in UART mode with
 * polling method.
 *
*END**************************************************************************/
/* implements     Linflexd_Uart_Ip_SyncReceive_Activity*/
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_SyncReceive(const uint8 Instance,
                                                         uint8 * RxBuff,
                                                         const uint32 RxSize,
                                                         const uint32 Timeout)
{
    /* Check the validity of the parameters */
    LINFLEXD_UART_IP_DEV_ASSERT(RxSize > 0U);
    LINFLEXD_UART_IP_DEV_ASSERT(RxBuff != NULL_PTR);
    LINFLEXD_UART_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);

    Linflexd_Uart_Ip_StateStructureType * UartState;
    LINFLEXD_Type * Base;
    uint32 StartTime;
    uint32 TimeoutTicks;
    uint32 ElapsedTicks = 0;
    Linflexd_Uart_Ip_StatusType Status = LINFLEXD_UART_IP_STATUS_TIMEOUT;

    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];
    Base = Linflexd_Uart_Ip_apBases[Instance];

    LINFLEXD_UART_IP_DEV_ASSERT(UartState != NULL_PTR);

    SchM_Enter_Uart_UART_EXCLUSIVE_AREA_06();
    /* Check driver is not busy transmitting data from a previous asynchronous call */
    if (UartState->IsRxBusy)
    {
        SchM_Exit_Uart_UART_EXCLUSIVE_AREA_06();
        Status = LINFLEXD_UART_IP_STATUS_BUSY;
    }
    else
    {
         /* Initialize the module driver state structure */
        UartState->IsRxBusy = TRUE;
        SchM_Exit_Uart_UART_EXCLUSIVE_AREA_06();
        UartState->RxBuff = RxBuff;
        UartState->RxSize = RxSize;
        UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_BUSY;

        /*The interrupts shall be disabled when the Linflexd_Uart_Ip_SyncReceive and Linflexd_Uart_Ip_SyncSend are called.*/
        Linflexd_Uart_Ip_SetUp_Receiver(Instance);

        Linflexd_Uart_Ip_StartTimeout(&StartTime, &TimeoutTicks, Timeout, LINFLEXD_UART_IP_TIMEOUT_TYPE);

        /* Update status and clear the flag according to the error occurred */
        Linflexd_Uart_Ip_UpdateReceiver(Instance, &StartTime, &ElapsedTicks, TimeoutTicks);

        /* Check if Timeout occur */
        if (Linflexd_Uart_Ip_CheckTimeout(&StartTime, &ElapsedTicks, TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_TYPE))
        {
            UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_TIMEOUT;
        }

        if (LINFLEXD_UART_IP_STATUS_BUSY == UartState->ReceiveStatus)
        {
            UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_SUCCESS;
        }

        /* Disable the receiver */
        Linflexd_Uart_Ip_SetReceiverState(Base, FALSE);
        UartState->IsRxBusy = FALSE;
        Status = UartState->ReceiveStatus;
    }
    return Status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_AbortReceivingData
 * Description   : Terminates a non-blocking receive early.
 *
 *END**************************************************************************/
/* implements     Linflexd_Uart_Ip_AbortReceivingData_Activity*/
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_AbortReceivingData(const uint8 Instance)
{
    LINFLEXD_UART_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);

    Linflexd_Uart_Ip_StateStructureType * UartState;
    const Linflexd_Uart_Ip_UserConfigType * UartUserCfg;

    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];
    Linflexd_Uart_Ip_StatusType Status = LINFLEXD_UART_IP_STATUS_SUCCESS;

    LINFLEXD_UART_IP_DEV_ASSERT(UartState != NULL_PTR);
    LINFLEXD_UART_IP_DEV_ASSERT(UartUserCfg != NULL_PTR);

    /* Check if a transfer is running. */
    if (!UartState->IsRxBusy)
    {
        Status = LINFLEXD_UART_IP_STATUS_SUCCESS;
    }
    else
    {
        /* Update the rx status */
        UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_ABORTED;

        /* Stop the running transfer. */
        if (LINFLEXD_UART_IP_USING_INTERRUPTS == UartUserCfg->TransferType)
        {
            Linflexd_Uart_Ip_CompleteReceiveUsingInterrupts(Instance);
        }
#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
        else
        {
            /* Release the DMA channel */
            (void)Dma_Ip_SetLogicChannelCommand(UartUserCfg->RxDMAChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
            Linflexd_Uart_Ip_CompleteReceiveUsingDma(Instance);
        }
#endif
    }
    if (LINFLEXD_UART_IP_STATUS_TIMEOUT == UartState->ReceiveStatus)
    {
        Status = LINFLEXD_UART_IP_STATUS_ERROR;
    }
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_AbortSendingData
 * Description   : This function terminates an non-blocking UART transmission
 * early. During a non-blocking UART transmission, the user has the option to
 * terminate the transmission early if the transmission is still in progress.
 *
 *END**************************************************************************/
/* implements     Linflexd_Uart_Ip_AbortSendingData_Activity */
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_AbortSendingData(const uint8 Instance)
{
    LINFLEXD_UART_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);

    Linflexd_Uart_Ip_StateStructureType * UartState;
    const Linflexd_Uart_Ip_UserConfigType * UartUserCfg;

    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];
    Linflexd_Uart_Ip_StatusType Status = LINFLEXD_UART_IP_STATUS_SUCCESS;

    LINFLEXD_UART_IP_DEV_ASSERT(UartState != NULL_PTR);
    LINFLEXD_UART_IP_DEV_ASSERT(UartUserCfg != NULL_PTR);

    /* Check if a transfer is running. */
    if (!UartState->IsTxBusy)
    {
        Status = LINFLEXD_UART_IP_STATUS_SUCCESS;
    }
    else
    {
        /* Update the tx status */
        UartState->TransmitStatus = LINFLEXD_UART_IP_STATUS_ABORTED;

        /* Stop the running transfer. */
        if (LINFLEXD_UART_IP_USING_INTERRUPTS == UartUserCfg->TransferType)
        {
            Linflexd_Uart_Ip_CompleteSendUsingInterrupts(Instance);
        }
#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
        else
        {
            /* Release the DMA channel */
            Linflexd_Uart_Ip_CompleteSendUsingDma(Instance);
            (void)Dma_Ip_SetLogicChannelCommand(UartUserCfg->TxDMAChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
        }
#endif
    }
    if (LINFLEXD_UART_IP_STATUS_TIMEOUT == UartState->TransmitStatus)
    {
        Status = LINFLEXD_UART_IP_STATUS_ERROR;
    }
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_StartReceiveUsingInterrupts
 * Description   : Initiate (start) a receive by beginning the process of
 * receiving data and enabling the interrupt.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_StartReceiveUsingInterrupts(const uint8 Instance,
                                                                                uint8 * RxBuff,
                                                                                const uint32 RxSize)
{
    LINFLEXD_UART_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
    LINFLEXD_UART_IP_DEV_ASSERT(RxBuff != NULL_PTR);

    Linflexd_Uart_Ip_StateStructureType * UartState;
    const Linflexd_Uart_Ip_UserConfigType * UartUserCfg;
    LINFLEXD_Type * Base;

    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];
    Base = Linflexd_Uart_Ip_apBases[Instance];
    Linflexd_Uart_Ip_StatusType Status = LINFLEXD_UART_IP_STATUS_ERROR;

    SchM_Enter_Uart_UART_EXCLUSIVE_AREA_07();
    /* Check it's not busy receiving data from a previous function call */
    if ((UartState->IsRxBusy) && (UartUserCfg->Callback != NULL_PTR))
    {
        SchM_Exit_Uart_UART_EXCLUSIVE_AREA_07();
        Status = LINFLEXD_UART_IP_STATUS_BUSY;
    }
    else
    {
        /* Initialize the module driver state struct to indicate transfer in progress
         * and with the buffer and byte count data. */
        UartState->IsRxBusy = TRUE;
        SchM_Exit_Uart_UART_EXCLUSIVE_AREA_07();
        UartState->RxBuff = RxBuff;
        LINFLEXD_UART_IP_DEV_ASSERT(RxSize > 0U);
        UartState->RxSize = RxSize;
        UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_BUSY;

        /* Clear the flag */
        Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_DATA_RECEPTION_COMPLETE_FLAG);
        Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_MESSAGE_BUFFER_FULL_FLAG);
        Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_FRAME_ERROR_FLAG);
        Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_BUFFER_OVERRUN_FLAG);

        /* Enable the receiver */
        Linflexd_Uart_Ip_SetReceiverState(Base, TRUE);

        /* Enable receive data full interrupt */
        Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_DATA_RECEPTION_COMPLETE_INT, TRUE);
        Status = LINFLEXD_UART_IP_STATUS_SUCCESS;
    }
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_GetReceiveStatus
 * Description   : This function returns whether the previous UART receive is
 * complete. When performing a non-blocking receive, the user can call this
 * function to ascertain the state of the current receive progress: in progress
 * or complete. In addition, if the receive is still in progress, the user can
 * obtain the number of words that have not yet been received.
 *
 *END**************************************************************************/
/* implements     Linflexd_Uart_Ip_GetReceiveStatus_Activity */
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_GetReceiveStatus(const uint8 Instance, uint32 * BytesRemaining)
{
    LINFLEXD_UART_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);

    const Linflexd_Uart_Ip_StateStructureType * UartState;
    const Linflexd_Uart_Ip_UserConfigType *UartUserCfg;
    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];

    LINFLEXD_UART_IP_DEV_ASSERT(UartState != NULL_PTR);
    LINFLEXD_UART_IP_DEV_ASSERT(UartUserCfg != NULL_PTR);

    if (BytesRemaining != NULL_PTR)
    {
        if (UartState->IsRxBusy)
        {
            Linflexd_Uart_Ip_GetRemainingBytes(Instance, BytesRemaining, LINFLEXD_UART_IP_RECEIVE);
        }
        else
        {
#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
            if (LINFLEXD_UART_IP_STATUS_RX_IDLE_STATE == UartState->ReceiveStatus)
            {
                Linflexd_Uart_Ip_GetRemainingBytes(Instance, BytesRemaining, LINFLEXD_UART_IP_RECEIVE);
            }
            else
#endif
            {
                *BytesRemaining = 0;
            }
        }
    }

    return UartState->ReceiveStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_GetTransmitStatus
 * Description   : This function returns whether the previous UART transmit has
 * finished. When performing non-blocking transmit, the user can call this
 * function to ascertain the state of the current transmission:
 * in progress (or busy) or complete (success). In addition, if the transmission
 * is still in progress, the user can obtain the number of words that have been
 * currently transferred.
 *
 *END**************************************************************************/
 /* implements     Linflexd_Uart_Ip_GetTransmitStatus_Activity */
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_GetTransmitStatus(const uint8 Instance, uint32 * BytesRemaining)
{
    LINFLEXD_UART_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);

    const Linflexd_Uart_Ip_StateStructureType * UartState;
    const Linflexd_Uart_Ip_UserConfigType * UartUserCfg;
    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];

    LINFLEXD_UART_IP_DEV_ASSERT(UartState != NULL_PTR);
    LINFLEXD_UART_IP_DEV_ASSERT(UartUserCfg != NULL_PTR);

    if (BytesRemaining != NULL_PTR)
    {
        /* Fill in the number of bytes yet to be transferred and update the return value if needed */
        if (UartState->IsTxBusy)
        {
            Linflexd_Uart_Ip_GetRemainingBytes(Instance, BytesRemaining, LINFLEXD_UART_IP_SEND);
        }
        else
        {
            *BytesRemaining = 0;
        }
    }
    return UartState->TransmitStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_AsyncReceive
 * Description   : Retrieves data from the LINFLEXD module in UART mode with
 * non-blocking method.
 *
 *END**************************************************************************/
 /* implements     Linflexd_Uart_Ip_AsyncReceive_Activity*/
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_AsyncReceive(const uint8 Instance,
                                                          uint8 * RxBuff,
                                                          const uint32 RxSize)
{
    LINFLEXD_UART_IP_DEV_ASSERT(RxBuff != NULL_PTR);
    LINFLEXD_UART_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
    LINFLEXD_Type * Base;
    Linflexd_Uart_Ip_StatusType RetVal = LINFLEXD_UART_IP_STATUS_ERROR;
    const Linflexd_Uart_Ip_UserConfigType * UartUserCfg;

    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];
    Base = Linflexd_Uart_Ip_apBases[Instance];

    LINFLEXD_UART_IP_DEV_ASSERT(UartUserCfg != NULL_PTR);

    /* Enable error interrupts */
    Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_FRAME_ERROR_INT, TRUE);
    Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_BUFFER_OVERRUN_INT, TRUE);

#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
    if (Linflexd_Uart_Ip_InstHasTimeoutInterruptEnabled[Instance])
    {
        Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_TIMEOUT_INT, TRUE);
    }
#endif

    if (LINFLEXD_UART_IP_USING_INTERRUPTS == UartUserCfg->TransferType)
    {
        /* Start the transmission process using interrupts */
        RetVal = Linflexd_Uart_Ip_StartReceiveUsingInterrupts(Instance, RxBuff, RxSize);
    }
#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
    else
    {
        /* Start the transmission process using DMA */
        RetVal = Linflexd_Uart_Ip_StartReceiveUsingDma(Instance, RxBuff, RxSize);
    }
#endif
    return RetVal;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_StartSendUsingInterrupts
 * Description   : Initiate (start) a transmit by beginning the process of
 * sending data and enabling the interrupt.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_StartSendUsingInterrupts(const uint8 Instance,
                                                                             const uint8 * TxBuff,
                                                                             const uint32 TxSize)
{
    LINFLEXD_Type * Base;
    Linflexd_Uart_Ip_StateStructureType * UartState;
    Linflexd_Uart_Ip_StatusType Status = LINFLEXD_UART_IP_STATUS_ERROR;
    Base = Linflexd_Uart_Ip_apBases[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];

    SchM_Enter_Uart_UART_EXCLUSIVE_AREA_04();
    /* Check it's not busy transmitting data from a previous function call */
    if (UartState->IsTxBusy)
    {
        SchM_Exit_Uart_UART_EXCLUSIVE_AREA_04();
        Status = LINFLEXD_UART_IP_STATUS_BUSY;
    }
    else
    {
        /* Initialize the module driver state structure */
        UartState->IsTxBusy = TRUE;
        SchM_Exit_Uart_UART_EXCLUSIVE_AREA_04();
        UartState->TxBuff = TxBuff;

        LINFLEXD_UART_IP_DEV_ASSERT(TxSize > 0U);
        UartState->TxSize = TxSize;

        UartState->TransmitStatus = LINFLEXD_UART_IP_STATUS_BUSY;

        /* Enable the transmitter */
        Linflexd_Uart_Ip_SetTransmitterState(Base, TRUE);

        /* Clear the tx empty flag to make sure the transmission of the first byte
         * doesn't occur right after enabling the tx interrupt
         */
        Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_DATA_TRANSMITTED_FLAG);

        /* Enable transmission complete interrupt */
        Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_DATA_TRANSMITTED_INT, TRUE);

        /* Transmit the first word */
        Linflexd_Uart_Ip_PutData(Instance);
        Status = LINFLEXD_UART_IP_STATUS_SUCCESS;
    }
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_AsyncSend
 * Description   : This function sends data using LINFLEXD module in UART mode
 * with non-blocking method.
 *
 *END**************************************************************************/
 /* implements     Linflexd_Uart_Ip_AsyncSend_Activity */
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_AsyncSend(const uint8 Instance,
                                                       const uint8 * TxBuff,
                                                       const uint32 TxSize)
{
    LINFLEXD_UART_IP_DEV_ASSERT(TxBuff != NULL_PTR);
    LINFLEXD_UART_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);

    Linflexd_Uart_Ip_StatusType RetVal = LINFLEXD_UART_IP_STATUS_ERROR;
    const Linflexd_Uart_Ip_UserConfigType *UartUserCfg;

    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];

    LINFLEXD_UART_IP_DEV_ASSERT(UartUserCfg != NULL_PTR);
    LINFLEXD_UART_IP_DEV_ASSERT((LINFLEXD_UART_IP_USING_INTERRUPTS == UartUserCfg->TransferType) ||
                                (LINFLEXD_UART_IP_USING_DMA == UartUserCfg->TransferType));

    if (LINFLEXD_UART_IP_USING_INTERRUPTS == UartUserCfg->TransferType)
    {
        /* Start the transmission process using interrupts */
        RetVal = Linflexd_Uart_Ip_StartSendUsingInterrupts(Instance, TxBuff, TxSize);
    }
#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
    else
    {
        /* Start the transmission process using DMA */
        RetVal = Linflexd_Uart_Ip_StartSendUsingDma(Instance, TxBuff, TxSize);
    }
#endif
    /* Start the transmission process */
    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_RxIRQHandler
 * Description   : Rx interrupt handler for UART.
 * This handler uses the rx buffer stored in the state structure to receive
 * data. This is not a public API as it is called by IRQ whenever an interrupt
 * occurs.
 *
 *END**************************************************************************/
static void Linflexd_Uart_Ip_RxIRQHandler(uint8 Instance)
{
    const Linflexd_Uart_Ip_StateStructureType * UartState;
    const Linflexd_Uart_Ip_UserConfigType * UartUserCfg;
    LINFLEXD_Type * Base;

    Base = Linflexd_Uart_Ip_apBases[Instance];
    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];

    if (UartState != NULL_PTR)
    {
        if ((UartState->IsDriverInitialized) && (UartState->IsRxBusy))
        {

            /* Retrieve the data */
            Linflexd_Uart_Ip_GetData(Instance);

            /* Clear the flags */
            Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_DATA_RECEPTION_COMPLETE_FLAG);
            Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_MESSAGE_BUFFER_FULL_FLAG);

            /* Check if this was the last byte in the current buffer */
            if (0U == UartState->RxSize)
            {
                /* Invoke the callback when the buffer is finished;
                * Application can provide another buffer inside the callback by calling Linflexd_Uart_Ip_SetRxBuffer */
                if (UartUserCfg->Callback != NULL_PTR)
                {
                    UartUserCfg->Callback(Instance, LINFLEXD_UART_IP_EVENT_RX_FULL, UartUserCfg->CallbackParam);
                }
            }

            /* Finish reception if this was the last byte received */
            if (0U == UartState->RxSize)
            {
                /* Complete transfer (disable rx logic) */
                Linflexd_Uart_Ip_CompleteReceiveUsingInterrupts(Instance);

                /* Invoke callback if there is one */
                if (UartUserCfg->Callback != NULL_PTR)
                {
                    UartUserCfg->Callback(Instance, LINFLEXD_UART_IP_EVENT_END_TRANSFER, UartUserCfg->CallbackParam);
                }
            }
        }
        /* Case of spurious interrupt when driver had an error in initialization */
        else
        {
            /* Clear the flags */
            Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_DATA_RECEPTION_COMPLETE_FLAG);
            Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_MESSAGE_BUFFER_FULL_FLAG);
        }
    }
    /* Case of spurious interrupt when driver is not at all initialized*/
    else
    {
        /* Clear the flags */
        Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_DATA_RECEPTION_COMPLETE_FLAG);
        Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_MESSAGE_BUFFER_FULL_FLAG);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_TxIRQHandler
 * Description   : Tx interrupt handler for UART.
 * This handler uses the tx buffer stored in the state structure to transmit
 * data. This is not a public API as it is called by IRQ whenever an interrupt
 * occurs.
 *
 *END**************************************************************************/
static void Linflexd_Uart_Ip_TxIRQHandler(uint8 Instance)
{
    const Linflexd_Uart_Ip_StateStructureType * UartState;
    const Linflexd_Uart_Ip_UserConfigType * UartUserCfg;
    LINFLEXD_Type * Base;

    Base = Linflexd_Uart_Ip_apBases[Instance];
    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];

    if (UartState != NULL_PTR)
    {
        if ((UartState->IsDriverInitialized) && (UartState->IsTxBusy))
        {
            /* Check if there are any more bytes to send */
            if (UartState->TxSize > 0U)
            {
                /* Clear the flag */
                Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_DATA_TRANSMITTED_FLAG);

                /* Send data */
                Linflexd_Uart_Ip_PutData(Instance);
            }
            else
            {
                /* Invoke the callback when the buffer is finished;
                * Application can provide another buffer inside the callback by calling Linflexd_Uart_Ip_SetTxBuffer */
                if (UartUserCfg->Callback != NULL_PTR)
                {
                    UartUserCfg->Callback(Instance, LINFLEXD_UART_IP_EVENT_TX_EMPTY, UartUserCfg->CallbackParam);
                }

                /* If there is no more data to send, complete the transmission */
                if (0U == UartState->TxSize)
                {
                    Linflexd_Uart_Ip_CompleteSendUsingInterrupts(Instance);

                    /* Call the callback to notify application that the transfer is complete */
                    if (UartUserCfg->Callback != NULL_PTR)
                    {
                        UartUserCfg->Callback(Instance, LINFLEXD_UART_IP_EVENT_END_TRANSFER, UartUserCfg->CallbackParam);
                    }

                    /* Clear the flag */
                    Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_DATA_TRANSMITTED_FLAG);
                }
            }
        }
        /* Case of spurious interrupt when driver had an error in initialization */
        else
        {
            Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_DATA_TRANSMITTED_FLAG);
        }
    }
    /* Case of spurious interrupt when driver is not at all initialized*/
    else
    {
        Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_DATA_TRANSMITTED_FLAG);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_ErrIRQHandler
 * Description   : Error interrupt handler for UART.
 * This handler calls the user callback to treat error conditions.
 *
 *END**************************************************************************/
static void Linflexd_Uart_Ip_ErrIRQHandler(uint8 Instance)
{
    Linflexd_Uart_Ip_StateStructureType * UartState;
    const Linflexd_Uart_Ip_UserConfigType * UartUserCfg;
    LINFLEXD_Type * Base;

    Base = Linflexd_Uart_Ip_apBases[Instance];
    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];

    if (UartState != NULL_PTR)
    {
        if (UartState->IsDriverInitialized)
        {
            /* Update the receive status according to the error occurred */
            if (Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_BUFFER_OVERRUN_FLAG))
            {
                /* Update the status */
                UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_RX_OVERRUN;
                /* The read dummy data not apply for DMA
                   because reading the BDRM register in this mode IPS operation result will returns IPS transfer error status*/
                if(LINFLEXD_UART_IP_USING_INTERRUPTS == UartUserCfg->TransferType)
                {
                    /* Read dummy to take the byte that caused the overrun error and shifts it to the buffer */
                    Linflexd_Uart_Ip_GetData(Instance);
                }
                /* Clear the flag */
                Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_BUFFER_OVERRUN_FLAG);
            }
            else if (Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_FRAME_ERROR_FLAG))
            {
                /* Update the status */
                UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_FRAMING_ERROR;
                /* The read dummy data not apply for DMA
                   because reading the BDRM register in this mode IPS operation result will returns IPS transfer error status*/
                if(LINFLEXD_UART_IP_USING_INTERRUPTS == UartUserCfg->TransferType)
                {
                    /* Read dummy to take the byte that caused the framing error and shifts it to the buffer */
                    Linflexd_Uart_Ip_GetData(Instance);
                }
                /* Clear the flag */
                Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_FRAME_ERROR_FLAG);
            }
#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
            else if (Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_TIMEOUT_INTERRUPT_FLAG))
            {
                /* Disable the receiver to stop timer counter */
                Linflexd_Uart_Ip_SetReceiverState(Base, FALSE);
                /* Update the status */
                UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_RX_IDLE_STATE;
                /* Clear Timeout Interrupt Error flag */
                Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_TIMEOUT_INTERRUPT_FLAG);
                /* Reset Reset Value to default */
                Linflexd_Uart_Ip_SetPresetValue(Base, 0xFFF);
            }
#endif
            else
            {
                /* This branch should never be reached - avoid MISRA violations */
                UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_ERROR;
            }

            /* Terminate the current reception */
            if (LINFLEXD_UART_IP_USING_INTERRUPTS == UartUserCfg->TransferType)
            {
                Linflexd_Uart_Ip_CompleteReceiveUsingInterrupts(Instance);
            }
#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
            else
            {
                /* Release the DMA channel */
                (void)Dma_Ip_SetLogicChannelCommand(UartUserCfg->RxDMAChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
                Linflexd_Uart_Ip_CompleteReceiveUsingDma(Instance);
            }
#endif

            /* Invoke the callback, if any */
            if (UartUserCfg->Callback != NULL_PTR)
            {
#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
                if (LINFLEXD_UART_IP_STATUS_RX_IDLE_STATE == UartState->ReceiveStatus)
                {
                    UartUserCfg->Callback(Instance, LINFLEXD_UART_IP_EVENT_IDLE_STATE, UartUserCfg->CallbackParam);
                }
                else
#endif
                {
                    UartUserCfg->Callback(Instance, LINFLEXD_UART_IP_EVENT_ERROR, UartUserCfg->CallbackParam);
                }
            }
        }
        /* Case of spurious interrupt when driver had an error in initialization */
        else
        {
            Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_BUFFER_OVERRUN_FLAG);
            Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_FRAME_ERROR_FLAG);
        }
    }
    /* Case of spurious interrupt when driver is not at all initialized*/
    else
    {
        Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_BUFFER_OVERRUN_FLAG);
        Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_FRAME_ERROR_FLAG);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_IRQHandler
 * Description   : Interrupt handler for UART.
 * This handler uses the buffers stored in the state structure to transfer
 * data. This is not a public API as it is called by IRQ whenever an interrupt
 * occurs.
 *
 *END**************************************************************************/
/* implements     Linflexd_Uart_Ip_IRQHandler_Activity*/
void Linflexd_Uart_Ip_IRQHandler(uint8 Instance)
{
    const LINFLEXD_Type * Base;

    Base = Linflexd_Uart_Ip_apBases[Instance];

    /* Handle receive data full interrupt */
    if (Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_DATA_RECEPTION_COMPLETE_FLAG))
    {
        if (Linflexd_Uart_Ip_IsInterruptEnabled(Base, LINFLEXD_DATA_RECEPTION_COMPLETE_INT))
        {
            Linflexd_Uart_Ip_RxIRQHandler(Instance);
        }
        else
        {
            /* CPR_RTD_00664.uart Spurious interrupt*/
            /* Do nothing - Return immediately */
        }
    }

    /* Handle transmitter data register empty interrupt */
    if (Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_DATA_TRANSMITTED_FLAG))
    {
        if (Linflexd_Uart_Ip_IsInterruptEnabled(Base, LINFLEXD_DATA_TRANSMITTED_INT))
        {
            Linflexd_Uart_Ip_TxIRQHandler(Instance);
        }
        else
        {
            /* CPR_RTD_00664.uart Spurious interrupt*/
            /* Do nothing - Return immediately */
        }
    }

    /* Handle the error interrupts if no rx/tx interrupt was triggered */
    if (Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_FRAME_ERROR_FLAG))
    {
        if (Linflexd_Uart_Ip_IsInterruptEnabled(Base, LINFLEXD_FRAME_ERROR_INT))
        {
            Linflexd_Uart_Ip_ErrIRQHandler(Instance);
        }
        else
        {
            /* CPR_RTD_00664.uart Spurious interrupt*/
            /* Do nothing - Return immediately */
        }
    }

    if (Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_BUFFER_OVERRUN_FLAG))
    {
        if (Linflexd_Uart_Ip_IsInterruptEnabled(Base, LINFLEXD_BUFFER_OVERRUN_INT))
        {
            Linflexd_Uart_Ip_ErrIRQHandler(Instance);
        }
        else
        {
            /* CPR_RTD_00664.uart Spurious interrupt*/
            /* Do nothing - Return immediately */
        }
    }
#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
        /* Handle the error interrupts if timeout error */
    if (Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_TIMEOUT_INTERRUPT_FLAG))
    {
        /* This checking also ensures that the feature is activated for the current instance
         * because the Interrupt can be enabled only in this case.
         */
        if (Linflexd_Uart_Ip_IsInterruptEnabled(Base, LINFLEXD_TIMEOUT_INT))
        {
            Linflexd_Uart_Ip_ErrIRQHandler(Instance);
        }
        else
        {
            /* CPR_RTD_00664.uart Spurious interrupt*/
            /* Do nothing - Return immediately */
        }
    }
#endif
}

#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_StartSendUsingDma
 * Description   : Initiate (start) a transmit by beginning the process of
 * sending data using DMA transfers.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_StartSendUsingDma(const uint8 Instance,
                                                                      const uint8 * TxBuff,
                                                                      const uint32 TxSize)
{
    LINFLEXD_Type * Base;
    Linflexd_Uart_Ip_StatusType RetVal;
    Linflexd_Uart_Ip_StateStructureType * UartState;
    const Linflexd_Uart_Ip_UserConfigType *UartUserCfg;
    Dma_Ip_LogicChannelTransferListType DmaTransferList[LINFLEXD_UART_IP_DMA_CONFIG_LIST_DIMENSION];
    Dma_Ip_ReturnType DmaReturnStatus;

    Base = Linflexd_Uart_Ip_apBases[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];
    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];

    SchM_Enter_Uart_UART_EXCLUSIVE_AREA_05();
    /* Check it's not busy transmitting data from a previous function call */
    if(!UartState->IsTxBusy)
    {
        /* Update state structure */
        UartState->IsTxBusy = TRUE;
        SchM_Exit_Uart_UART_EXCLUSIVE_AREA_05();
        UartState->TxBuff = TxBuff;

        /* Check the validity of the parameters */
        LINFLEXD_UART_IP_DEV_ASSERT(TxSize > 0U);
        if (!((LINFLEXD_UART_IP_7_BITS == UartUserCfg->WordLength) || (LINFLEXD_UART_IP_8_BITS == UartUserCfg->WordLength)))
        {
            /* The size of the buffer should be an even number for DMA transfers with 15/16 bits word length */
            LINFLEXD_UART_IP_DEV_ASSERT(0U == (TxSize & 1U));
        }
        UartState->TxSize = 0U;
        UartState->TransmitStatus = LINFLEXD_UART_IP_STATUS_BUSY;

        /* Set up parameters for Dma_Ip_LogicChannelTransferListType */
        DmaTransferList[0].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
        DmaTransferList[0].Value = (uint32)TxBuff;
        DmaTransferList[1].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
        DmaTransferList[1].Value = LINFLEXD_UART_IP_LSBW_ADDR(Base->BDRL);
        DmaTransferList[2].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
        DmaTransferList[3].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
        DmaTransferList[3].Value = 0;
        DmaTransferList[4].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
        DmaTransferList[5].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
        DmaTransferList[6].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
        DmaTransferList[7].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
        if ((LINFLEXD_UART_IP_7_BITS == UartUserCfg->WordLength) || (LINFLEXD_UART_IP_8_BITS == UartUserCfg->WordLength))
        {
            DmaTransferList[2].Value = 1;
            DmaTransferList[4].Value = TxSize;
            DmaTransferList[5].Value = 1;
            DmaTransferList[6].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
            DmaTransferList[7].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
        }
        else
        {
            DmaTransferList[2].Value = 2;
            DmaTransferList[4].Value = TxSize/(uint32)2;
            DmaTransferList[5].Value = 2;
            DmaTransferList[6].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;
            DmaTransferList[7].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;
        }

        DmaTransferList[8].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
        DmaTransferList[8].Value = 1;
        DmaTransferList[9].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
        DmaTransferList[9].Value = 1;

        /* Configure the transfer control descriptor for the DMA channel */
        DmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(UartUserCfg->TxDMAChannel, DmaTransferList, LINFLEXD_UART_IP_DMA_CONFIG_LIST_DIMENSION);
        LINFLEXD_UART_IP_DEV_ASSERT(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);

        /* Start the DMA channel */
        DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(UartUserCfg->TxDMAChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
        LINFLEXD_UART_IP_DEV_ASSERT(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
        /* Enable the transmitter */
        Linflexd_Uart_Ip_SetTransmitterState(Base, TRUE);

        /* Enable tx DMA requests for the current instance */
        Linflexd_Uart_Ip_SetDmaTxEnable(Base, TRUE);

        RetVal = LINFLEXD_UART_IP_STATUS_SUCCESS;
    }
    else
    {
        SchM_Exit_Uart_UART_EXCLUSIVE_AREA_05();
        RetVal = LINFLEXD_UART_IP_STATUS_BUSY;
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_StartReceiveUsingDma
 * Description   : Initiate (start) a receive by beginning the process of
 * receiving data using DMA transfers.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_StartReceiveUsingDma(const uint8 Instance,
                                                                         uint8 * RxBuff,
                                                                         const uint32 RxSize)
{
    LINFLEXD_Type * Base;
    Linflexd_Uart_Ip_StatusType RetVal;
    Linflexd_Uart_Ip_StateStructureType * UartState;
    const Linflexd_Uart_Ip_UserConfigType * UartUserCfg;
    Dma_Ip_LogicChannelTransferListType DmaTransferList[LINFLEXD_UART_IP_DMA_CONFIG_LIST_DIMENSION];
    Dma_Ip_ReturnType DmaReturnStatus;

    Base = Linflexd_Uart_Ip_apBases[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];
    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];


    SchM_Enter_Uart_UART_EXCLUSIVE_AREA_08();
    /* Check it's not busy transmitting data from a previous function call */
    if (!UartState->IsRxBusy)
    {
        /* Update the state structure */
        UartState->IsRxBusy = TRUE;
        SchM_Exit_Uart_UART_EXCLUSIVE_AREA_08();

        LINFLEXD_UART_IP_DEV_ASSERT(RxSize > 0U);
        if (!((LINFLEXD_UART_IP_7_BITS == UartUserCfg->WordLength) || (LINFLEXD_UART_IP_8_BITS == UartUserCfg->WordLength)))
        {
            /* The size of the buffer should be an even number for DMA transfers with 15/16 bits word length */
            LINFLEXD_UART_IP_DEV_ASSERT(0U == (RxSize & 1U));
        }
        UartState->RxBuff = RxBuff;
        UartState->RxSize = 0U;
        UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_BUSY;

        /* Set up parameters for Dma_Ip_LogicChannelTransferListType */
        DmaTransferList[0].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
        DmaTransferList[0].Value = LINFLEXD_UART_IP_LSBW_ADDR(Base->BDRM);
        DmaTransferList[1].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
        DmaTransferList[1].Value = (uint32)RxBuff;
        DmaTransferList[2].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
        DmaTransferList[2].Value = 0;
        DmaTransferList[3].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
        DmaTransferList[4].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
        DmaTransferList[5].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
        DmaTransferList[6].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
        DmaTransferList[7].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
        if ((LINFLEXD_UART_IP_7_BITS == UartUserCfg->WordLength) || (LINFLEXD_UART_IP_8_BITS == UartUserCfg->WordLength))
        {
            DmaTransferList[3].Value = 1;
            DmaTransferList[4].Value = RxSize;
            DmaTransferList[5].Value = 1;
            DmaTransferList[6].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
            DmaTransferList[7].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
        }
        else
        {
            DmaTransferList[3].Value = 2;
            DmaTransferList[4].Value = RxSize/(uint32)2;
            DmaTransferList[5].Value = 2;
            DmaTransferList[6].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;
            DmaTransferList[7].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;
        }
        DmaTransferList[8].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
        DmaTransferList[8].Value = 1;
        DmaTransferList[9].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
        DmaTransferList[9].Value = 1;

        /* Configure the transfer control descriptor for the DMA channel */
        DmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(UartUserCfg->RxDMAChannel, DmaTransferList, LINFLEXD_UART_IP_DMA_CONFIG_LIST_DIMENSION);
        LINFLEXD_UART_IP_DEV_ASSERT(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);

        /* Start the DMA channel */
        DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(UartUserCfg->RxDMAChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);

        LINFLEXD_UART_IP_DEV_ASSERT(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
        /* Flush the rx FIFO to discard any junk data received while the driver was idle */
        Linflexd_Uart_Ip_FlushRxFifo(Base, UartUserCfg->WordLength);

        /* Enable the receiver */
        Linflexd_Uart_Ip_SetReceiverState(Base, TRUE);

        /* Enable rx DMA requests for the current instance */
        Linflexd_Uart_Ip_SetDmaRxEnable(Base, TRUE);

        RetVal = LINFLEXD_UART_IP_STATUS_SUCCESS;
    }
    else
    {
        SchM_Exit_Uart_UART_EXCLUSIVE_AREA_08();
        RetVal = LINFLEXD_UART_IP_STATUS_BUSY;
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_CompleteSendUsingDma
 * Description   : Finish up a transmit by completing the process of sending
 * data and disabling the DMA requests. This is a callback for DMA major loop
 * completion, so it must match the DMA callback signature.
 *
 *END**************************************************************************/
void Linflexd_Uart_Ip_CompleteSendUsingDma(uint8 Instance)
{
    LINFLEXD_Type * Base;
    Linflexd_Uart_Ip_StateStructureType * UartState;
    const Linflexd_Uart_Ip_UserConfigType *UartUserCfg;
    Dma_Ip_LogicChannelTransferListType DmaTransferList[LINFLEXD_UART_DMA_LEAST_CONFIG_LIST_DIMENSION];
    Dma_Ip_ReturnType DmaReturnStatus;
    Dma_Ip_LogicChannelStatusType DmaStatus;

    Base = Linflexd_Uart_Ip_apBases[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];
    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];

    /* Get Dma Ip Logic Channel Status */
    (void)Dma_Ip_GetLogicChannelStatus(UartUserCfg->TxDMAChannel, &DmaStatus);
    if (DMA_IP_CH_ERROR_STATE == DmaStatus.ChStateValue)
    {
        /* Reset the Dma Channel Error status. */
        DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(UartUserCfg->TxDMAChannel, DMA_IP_CH_CLEAR_ERROR);

        LINFLEXD_UART_IP_DEV_ASSERT(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
        /* Update transmit status */
        UartState->TransmitStatus = LINFLEXD_UART_IP_STATUS_DMA_ERROR;
        /* Invoke callback if there is one */
        if (UartUserCfg->Callback != NULL_PTR)
        {
            UartUserCfg->Callback(Instance, LINFLEXD_UART_IP_EVENT_ERROR, UartUserCfg->CallbackParam);
        }
    }

    /* Invoke the callback when the buffer is finished;
     * Application can provide another buffer inside the callback by calling Linflexd_Uart_Ip_SetTxBuffer */
    if (LINFLEXD_UART_IP_STATUS_BUSY == UartState->TransmitStatus)
    {
        if (UartUserCfg->Callback != NULL_PTR)
        {
            /* Pass the state structure as parameter for internal information retrieval */
            UartUserCfg->Callback(Instance, LINFLEXD_UART_IP_EVENT_TX_EMPTY, UartUserCfg->CallbackParam);
        }
    }

    /* If the callback has updated the tx buffer, update the DMA descriptor to continue the transfer;
     * otherwise, stop the current transfer.
     */
    if (UartState->TxSize > 0U)
    {
        /* Set up parameters for Dma_Ip_LogicChannelTransferListType */
        DmaTransferList[0].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
        DmaTransferList[1].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
        /* Update tx size and major loop count parameters for Dma_Ip_LogicChannelTransferListType */
        DmaTransferList[0].Value = (uint32)(UartState->TxBuff);
        if (!((LINFLEXD_UART_IP_7_BITS == UartUserCfg->WordLength) || (LINFLEXD_UART_IP_8_BITS == UartUserCfg->WordLength)))
        {
            /* The size of the buffer should be an even number for DMA transfers with 15/16 bits word length */
            LINFLEXD_UART_IP_DEV_ASSERT(0U == (UartState->TxSize & 1U));
        }
        if ((LINFLEXD_UART_IP_7_BITS == UartUserCfg->WordLength) || (LINFLEXD_UART_IP_8_BITS == UartUserCfg->WordLength))
        {
            DmaTransferList[1].Value = UartState->TxSize;
        }
        else
        {
            DmaTransferList[1].Value = (UartState->TxSize)/(uint32)2;
        }

        /* Re-configure the transfer control descriptor for the DMA channel */
        DmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(UartUserCfg->TxDMAChannel, DmaTransferList, LINFLEXD_UART_DMA_LEAST_CONFIG_LIST_DIMENSION);
        LINFLEXD_UART_IP_DEV_ASSERT(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);

        /* Now that this tx is set up, clear remaining bytes count */
        UartState->TxSize = 0U;

        /* Re-start the channel */
        DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(UartUserCfg->TxDMAChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
        LINFLEXD_UART_IP_DEV_ASSERT(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
    }
    else
    {
        /* Disable the transmitter */
        Linflexd_Uart_Ip_SetTransmitterState(Base, FALSE);

        /* Disable tx DMA requests for the current instance */
        Linflexd_Uart_Ip_SetDmaTxEnable(Base, FALSE);

        /* Update the busy flag */
        UartState->IsTxBusy = FALSE;

        /* If the current reception hasn't been aborted, update the status */
        if (LINFLEXD_UART_IP_STATUS_BUSY == UartState->TransmitStatus)
        {
            UartState->TransmitStatus = LINFLEXD_UART_IP_STATUS_SUCCESS;
            /* Call the callback to notify application that the transfer is complete */
            if (UartUserCfg->Callback != NULL_PTR)
            {
                UartUserCfg->Callback(Instance, LINFLEXD_UART_IP_EVENT_END_TRANSFER, UartUserCfg->CallbackParam);
            }
        }
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_CompleteReceiveUsingDma
 * Description   : Finish up a receive by completing the process of receiving data
 * and disabling the DMA requests. This is a callback for DMA major loop
 * completion, so it must match the DMA callback signature.
 *
 *END**************************************************************************/
void Linflexd_Uart_Ip_CompleteReceiveUsingDma(uint8 Instance)
{
    LINFLEXD_Type * Base;
    Linflexd_Uart_Ip_StateStructureType * UartState;
    const Linflexd_Uart_Ip_UserConfigType *UartUserCfg;
    Dma_Ip_LogicChannelTransferListType DmaTransferList[LINFLEXD_UART_DMA_LEAST_CONFIG_LIST_DIMENSION];
    Dma_Ip_ReturnType DmaReturnStatus;
    Dma_Ip_LogicChannelStatusType DmaStatus;
    uint32 StartTime;
    uint32 TimeoutTicks;
    uint32 ElapsedTicks = 0;

    Base = Linflexd_Uart_Ip_apBases[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];
    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];

    /* Get Dma Ip Logic Channel Status */
    (void)Dma_Ip_GetLogicChannelStatus(UartUserCfg->RxDMAChannel, &DmaStatus);

    if (DMA_IP_CH_ERROR_STATE == DmaStatus.ChStateValue)
    {
        /* Reset the Dma Channel Error status. */
        DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(UartUserCfg->RxDMAChannel, DMA_IP_CH_CLEAR_ERROR);

        LINFLEXD_UART_IP_DEV_ASSERT(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
        /* Update transmit status */
        UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_DMA_ERROR;
        /* Invoke callback if there is one */
        if (UartUserCfg->Callback != NULL_PTR)
        {
            UartUserCfg->Callback(Instance, LINFLEXD_UART_IP_EVENT_ERROR, UartUserCfg->CallbackParam);
        }
    }

    /* Invoke the callback when the buffer is finished */
    if (LINFLEXD_UART_IP_STATUS_BUSY == UartState->ReceiveStatus)
    {
        /* Application can provide another buffer inside the callback by calling Linflexd_Uart_Ip_SetRxBuffer */
        if (UartUserCfg->Callback != NULL_PTR)
        {
            UartUserCfg->Callback(Instance, LINFLEXD_UART_IP_EVENT_RX_FULL, UartUserCfg->CallbackParam);
        }
    }

    /* If the callback has updated the rx buffer, update the DMA descriptor to continue the transfer;
     * otherwise, stop the current transfer.
     */
    if (UartState->RxSize > 0U)
    {
        /* Set up parameters for Dma_Ip_LogicChannelTransferListType */
        DmaTransferList[0].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
        DmaTransferList[1].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
        DmaTransferList[0].Value = (uint32)(UartState->RxBuff);
        if ((LINFLEXD_UART_IP_7_BITS == UartUserCfg->WordLength) || (LINFLEXD_UART_IP_8_BITS == UartUserCfg->WordLength))
        {
            DmaTransferList[1].Value = UartState->RxSize;
        }
        else
        {
            DmaTransferList[1].Value = (UartState->RxSize)/(uint32)2;
        }
        /* Re-configure the transfer control descriptor for the DMA channel */
        DmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(UartUserCfg->RxDMAChannel, DmaTransferList, LINFLEXD_UART_DMA_LEAST_CONFIG_LIST_DIMENSION);
        LINFLEXD_UART_IP_DEV_ASSERT(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
        /* Now that this rx is set up, clear remaining bytes count */
        UartState->RxSize = 0U;
        /* Re-start the channel */
        DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(UartUserCfg->RxDMAChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
        LINFLEXD_UART_IP_DEV_ASSERT(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
    }
    else
    {
        /* Disable rx DMA requests for the current instance */
        Linflexd_Uart_Ip_SetDmaRxEnable(Base, FALSE);

        /* In Abort case, the transmission need to stop instantly */
        if (LINFLEXD_UART_IP_STATUS_ABORTED == UartState->ReceiveStatus)
        {
            /* Wait until the last transmission complete */
            Linflexd_Uart_Ip_StartTimeout(&StartTime, &TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_VALUE_US, LINFLEXD_UART_IP_TIMEOUT_TYPE);
            while (!Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_DATA_RECEPTION_COMPLETE_FLAG) && \
               !Linflexd_Uart_Ip_CheckTimeout(&StartTime, &ElapsedTicks, TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_TYPE))
            {}
            if (Linflexd_Uart_Ip_CheckTimeout(&StartTime, &ElapsedTicks, TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_TYPE))
            {
              /* In case timeout occur */
                UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_TIMEOUT;
            }
        }
        /* Disable the receiver */
        Linflexd_Uart_Ip_SetReceiverState(Base, FALSE);

        /* Update the information of the module driver state */
        UartState->IsRxBusy = FALSE;

        /* If the current reception hasn't been aborted, update the status and call the callback */
        if (LINFLEXD_UART_IP_STATUS_BUSY == UartState->ReceiveStatus)
        {
            UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_SUCCESS;

            /* Call the callback to notify application that the transfer is complete */
            if (UartUserCfg->Callback != NULL_PTR)
            {
                UartUserCfg->Callback(Instance, LINFLEXD_UART_IP_EVENT_END_TRANSFER, UartUserCfg->CallbackParam);
            }
        }
        /* Disable error interrupts */
        Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_FRAME_ERROR_INT, FALSE);
        Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_BUFFER_OVERRUN_INT, FALSE);
#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
        if (Linflexd_Uart_Ip_InstHasTimeoutInterruptEnabled[Instance])
        {
            /* Disable timeout interrupt */
            Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_TIMEOUT_INT, FALSE);
        }
#endif
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_FlushRxFifo
 * Description   : Flushes the rx FIFO.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void Linflexd_Uart_Ip_FlushRxFifo(const LINFLEXD_Type *Base,const Linflexd_Uart_Ip_WordLengthType WordLength)
{
    uint16 DummyData;

    if ((LINFLEXD_UART_IP_7_BITS == WordLength) || (LINFLEXD_UART_IP_8_BITS == WordLength))
    {
        volatile const uint8 *FifoBase;

        /* Get the address of the FIFO */
        FifoBase = (volatile const uint8 *)(&(Base->BDRM));
#ifdef CORE_BIG_ENDIAN
        FifoBase = &FifoBase[3];
#endif

        /* Four dummy reads, to flush the FIFO contents */
        DummyData = (uint16)(*FifoBase);
        DummyData = (uint16)(*FifoBase);
        DummyData = (uint16)(*FifoBase);
        DummyData = (uint16)(*FifoBase);
        (void)DummyData;
    }
    else
    {
        volatile const uint16 *u16FifoBase;

        /* Get the address of the FIFO */
        u16FifoBase = (volatile const uint16 *)(&(Base->BDRM));
#ifdef CORE_BIG_ENDIAN
        u16FifoBase = &u16FifoBase[1];
#endif

        /* Four dummy reads, to flush the FIFO contents */
        DummyData = *u16FifoBase;
        DummyData = *u16FifoBase;
        DummyData = *u16FifoBase;
        DummyData = *u16FifoBase;
        (void)DummyData;
    }
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_SetUp_Init
 * Description   : Set up Linflexd Uart to Init Privileged.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void Linflexd_Uart_Ip_SetUp_Init(const uint8 Instance)
{
    const Linflexd_Uart_Ip_UserConfigType * UartUserCfg;
    LINFLEXD_Type * Base = Linflexd_Uart_Ip_apBases[Instance];
    Linflexd_Uart_Ip_StateStructureType * UartStatePtr;
    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];
    UartStatePtr = Linflexd_Uart_Ip_apStateStructuresArray[Instance];

    /* Set UART mode */
    Linflexd_Uart_Ip_SetMode(Base, LINFLEXD_UART_MODE);

    /* Set the baud rate */
    Linflexd_Uart_Ip_SetIntegerBaudRate(Base, UartUserCfg->BaudRateMantissa);
    Linflexd_Uart_Ip_SetFractionalBaudRate(Base, UartUserCfg->BaudRateFractionalDivisor);

    UartStatePtr->Baudrate = UartUserCfg->BaudRate;

#if (LINFLEXD_UART_IP_ENABLE_INTERNAL_LOOPBACK == STD_ON)
    if (Linflexd_Uart_Ip_InstHasLoopbackEnabled[Instance])
    {
        Base->LINCR1 |= LINFLEXD_LINCR1_LBKM(1);
    }
#endif

#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
    if (Linflexd_Uart_Ip_InstHasTimeoutInterruptEnabled[Instance])
    {
        Linflexd_Uart_Ip_EnableTimerReset(Base, TRUE);
        Linflexd_Uart_Ip_EnableMonitorIdleState(Base, TRUE);
        Linflexd_Uart_Ip_SetPresetValue(Base, (uint16)UartUserCfg->WordLength + 2U);
    }
#endif

    /* Set word length */
    Linflexd_Uart_Ip_SetWordLength(Instance);

    /* Set parity */
    if (UartUserCfg->ParityCheck)
    {
        Linflexd_Uart_Ip_SetParityControl(Base, TRUE);
        Linflexd_Uart_Ip_SetParityType(Base, UartUserCfg->ParityType);
    }
    else
    {
        Linflexd_Uart_Ip_SetParityControl(Base, FALSE);
    }

    /* Set stop bits count */
    Linflexd_Uart_Ip_SetRxStopBitsCount(Base, UartUserCfg->StopBitsCount);
    Linflexd_Uart_Ip_SetTxStopBitsCount(Base, UartUserCfg->StopBitsCount, TRUE);

    /* Enable FIFO for DMA based communication, or buffer mode for interrupt based communication */
    if (LINFLEXD_UART_IP_USING_DMA == UartUserCfg->TransferType)
    {
        Linflexd_Uart_Ip_SetTxMode(Base, LINFLEXD_UART_RXTX_FIFO_MODE);
        Linflexd_Uart_Ip_SetRxMode(Base, LINFLEXD_UART_RXTX_FIFO_MODE);
    }
    else
    {
        Linflexd_Uart_Ip_SetTxMode(Base, LINFLEXD_UART_RXTX_BUFFER_MODE);
        Linflexd_Uart_Ip_SetRxMode(Base, LINFLEXD_UART_RXTX_BUFFER_MODE);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_SetWordLength
 * Description   : Set up word length for Linflexd Uart.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void Linflexd_Uart_Ip_SetWordLength(const uint8 Instance)
{
    const Linflexd_Uart_Ip_UserConfigType *UartUserCfg;
    LINFLEXD_Type * Base = Linflexd_Uart_Ip_apBases[Instance];

    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];
    Linflexd_Uart_Ip_SetUartWordLength(Base, UartUserCfg->WordLength);
    Linflexd_Uart_Ip_SetTxDataFieldLength(Base, (uint8)((uint8)UartUserCfg->WordLength >> 1U));
    Linflexd_Uart_Ip_SetRxDataFieldLength(Base, (uint8)((uint8)UartUserCfg->WordLength >> 1U));
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_UpdateReceiver
 * Description   : Update status and clear the flag according to the error occurred.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void Linflexd_Uart_Ip_UpdateReceiver(const uint8 Instance, uint32 * StartTime, uint32 * ElapsedTicks, uint32 TimeoutTicks)
{
        LINFLEXD_Type * Base;
        Linflexd_Uart_Ip_StateStructureType * UartState;
        Base = Linflexd_Uart_Ip_apBases[Instance];
        UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];
        boolean IsError = FALSE;

        /* To be updated with timeout when aProach is defined*/
        while ((UartState->RxSize > 0U) && !Linflexd_Uart_Ip_CheckTimeout(StartTime, ElapsedTicks, TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_TYPE))
        {
            /* Wait until data reception flag is set or timeout occurs if there is an error during reception */
            while (!Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_DATA_RECEPTION_COMPLETE_FLAG) && \
                   !Linflexd_Uart_Ip_CheckTimeout(StartTime, ElapsedTicks, TimeoutTicks, LINFLEXD_UART_IP_TIMEOUT_TYPE))
            {}
            /* Update the receive status according to the error occurred */
            if (Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_BUFFER_OVERRUN_FLAG))
            {
                /* Update the status */
                UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_RX_OVERRUN;
                /* Clear the flag */
                Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_BUFFER_OVERRUN_FLAG);
                IsError = TRUE;
            }
            if (Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_FRAME_ERROR_FLAG))
            {
                /* Update the status */
                UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_FRAMING_ERROR;
                /* Clear the flag */
                Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_FRAME_ERROR_FLAG);
                IsError = TRUE;
            }
            if (Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_PARITY_ERROR_FLAG))
            {
                /* Update the status */
                UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_PARITY_ERROR;
                /* Clear the flag */
                Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_PARITY_ERROR_FLAG);
                IsError = TRUE;
            }
            if (Linflexd_Uart_Ip_GetStatusFlag(Base, LINFLEXD_UART_NOISE_FLAG))
            {
                /* Update the status */
                UartState->ReceiveStatus = LINFLEXD_UART_IP_STATUS_NOISE_ERROR;
                /* Clear the flag */
                Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_NOISE_FLAG);
                IsError = TRUE;
            }

            if (!IsError)
            {
                /* Retrieve the data */
                Linflexd_Uart_Ip_GetData(Instance);
                /* Clear the flags */
                Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_DATA_RECEPTION_COMPLETE_FLAG);
                Linflexd_Uart_Ip_ClearStatusFlag(Base, LINFLEXD_UART_MESSAGE_BUFFER_FULL_FLAG);
            }
            else
            {
                break;
            }
        }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_SetUp_Receiver
 * Description   : Disble transmission complete interrupt, Disable receive data full interrupt.
                   and Disable error interrupts to Enable the receiver.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void Linflexd_Uart_Ip_SetUp_Receiver(const uint8 Instance)
{
    LINFLEXD_Type * Base;
    Base = Linflexd_Uart_Ip_apBases[Instance];

    /* Disble transmission complete interrupt */
    Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_DATA_TRANSMITTED_INT, FALSE);
    /* Disable receive data full interrupt. */
    Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_DATA_RECEPTION_COMPLETE_INT, FALSE);
    /* Disable error interrupts */
    Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_FRAME_ERROR_INT, FALSE);
    Linflexd_Uart_Ip_SetInterruptMode(Base, LINFLEXD_BUFFER_OVERRUN_INT, FALSE);

    /* Enable the receiver */
    Linflexd_Uart_Ip_SetReceiverState(Base, TRUE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Uart_Ip_GetRemainingBytes
 * Description   : Get the Remaining Bytes
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void Linflexd_Uart_Ip_GetRemainingBytes(const uint8 Instance, uint32 * BytesRemaining, Linflexd_Uart_Ip_DataDirectionType Direction)
{
    const Linflexd_Uart_Ip_UserConfigType *UartUserCfg;
    const Linflexd_Uart_Ip_StateStructureType * UartState;
    UartUserCfg = Linflexd_Uart_Ip_apUserConfig[Instance];
    UartState = (Linflexd_Uart_Ip_StateStructureType *)Linflexd_Uart_Ip_apStateStructuresArray[Instance];
#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
    const Dma_Ip_LogicChannelInfoParamType DmaLogicChnParam = DMA_IP_CH_GET_CURRENT_ITER_COUNT;
#endif

    /* Fill in the number of bytes yet to be received or transferred and update the return value if needed */
    if (LINFLEXD_UART_IP_USING_INTERRUPTS == UartUserCfg->TransferType)
    {
        /* In interrupt-based communication, the remaining bytes are retrieved
         * from the state structure
         */
        if (LINFLEXD_UART_IP_RECEIVE == Direction)
        {
            *BytesRemaining = UartState->RxSize;
        }
        else
        {
            *BytesRemaining = UartState->TxSize;
        }
    }
#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
    else
    {
        /* In DMA-based communication, the remaining bytes are retrieved
         * from the current DMA major loop count
         */
        if (LINFLEXD_UART_IP_RECEIVE == Direction)
        {
            (void)Dma_Ip_GetLogicChannelParam(UartUserCfg->RxDMAChannel, DmaLogicChnParam, BytesRemaining);
        }
        else
        {
            (void)Dma_Ip_GetLogicChannelParam(UartUserCfg->TxDMAChannel, DmaLogicChnParam, BytesRemaining);
        }
    }
#endif
}

#if (STD_ON == LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE)
/**
* @brief This function will set UAA bit in REG_PROT for UART unit
*/
void Linflexd_Uart_Ip_SetUserAccess(const uint8 Instance)
{
    LINFLEXD_Type * Base;
    Base = Linflexd_Uart_Ip_apBases[Instance];

    SET_USER_ACCESS_ALLOWED((uint32)Base, LINFLEX_PROT_MEM_U32);
}

/**
* @brief This function will enable writing all UART registers under protection in User mode by configuring REG_PROT
*/
static void Linflexd_Uart_Ip_SetUserAccessAllowed(const uint8 Instance)
{
    OsIf_Trusted_Call1param(Linflexd_Uart_Ip_SetUserAccess, Instance);
}
#endif /* LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE */

#define UART_STOP_SEC_CODE
#include "Uart_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
