/*
 * Copyright 2021-2025 NXP
*
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file
*
*   @addtogroup CRYPTO_43_HSE
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
#include "Hse_Ip.h"
#include "Mu_Ip.h"
#include "SchM_Crypto_43_HSE.h"
#if (STD_ON == HSE_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif /* (STD_ON == HSE_IP_DEV_ERROR_DETECT) */

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define HSE_IP_VENDOR_ID_C                    43
#define HSE_IP_SW_MAJOR_VERSION_C             2
#define HSE_IP_SW_MINOR_VERSION_C             0
#define HSE_IP_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Hse_Ip source file and Hse_Ip header file are of the same vendor */
#if (HSE_IP_VENDOR_ID_C != HSE_IP_VENDOR_ID_H)
    #error "Hse_Ip.c and Hse_Ip.h have different vendor ids"
#endif

/* Check if Hse_Ip source file and Hse_Ip header file are of the same Software version */
#if ((HSE_IP_SW_MAJOR_VERSION_C != HSE_IP_SW_MAJOR_VERSION_H) || \
     (HSE_IP_SW_MINOR_VERSION_C != HSE_IP_SW_MINOR_VERSION_H) || \
     (HSE_IP_SW_PATCH_VERSION_C != HSE_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Hse_Ip.c and Hse_Ip.h are different"
#endif


/* Check if Hse_Ip source file and Mu_Ip header file are of the same vendor */
#if (HSE_IP_VENDOR_ID_C != MU_IP_VENDOR_ID_H)
    #error "Hse_Ip.c and Mu_Ip.h have different vendor ids"
#endif

/* Check if Hse_Ip source file and Mu_Ip header file are of the same Software version */
#if ((HSE_IP_SW_MAJOR_VERSION_C != MU_IP_SW_MAJOR_VERSION_H) || \
     (HSE_IP_SW_MINOR_VERSION_C != MU_IP_SW_MINOR_VERSION_H) || \
     (HSE_IP_SW_PATCH_VERSION_C != MU_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Hse_Ip.c and Mu_Ip.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
/*! @brief Mask for HSE status bits. */
#define HSE_IP_HSE_STATUS_MASK_U32           (0xFFFF0000UL)

/*! @brief Shift for HSE status bits. */
#define HSE_IP_HSE_STATUS_SHIFT_U8           (16U)

/*! @brief Mask for GSR error flag bits. */
#define HSE_IP_HSE_ALL_ERROR_FLAGS_MASK_U32  (0xFFFFFFFFUL)

/*! @brief Mask for channel busy bits. */
#define HSE_IP_HSE_CHANNEL_BUSY_MASK_U32     (0x0000FFFFUL)

/*! @brief Identifier of the MU_0 instance. */
#define HSE_IP_MU_0_INSTANCE_U8              (0U)


/* Macro for calling OsIf_MicrosToTicks */
#define CRYPTO_HSE_IP_10_OSIF_MICROS_TO_TICKS_CALL          (uint8)(10u)
/* Macro for calling OsIf_GetCounter function */
#define CRYPTO_HSE_IP_11_OSIF_GET_COUNTER_CALL              (uint8)(11u)
/* Macro for calling OsIf_GetElapsed function*/
#define CRYPTO_HSE_IP_12_OSIF_GET_ELAPSED_CALL              (uint8)(12u)

/* Convert Hse IP pointer MU (32-bit) register value */
#if(CPU_TYPE_64 == CPU_TYPE)
    #define HSE_IP_PTR_TO_REG32 (uint32)(uint64)
#else
    #define HSE_IP_PTR_TO_REG32 (uint32)
#endif

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/
#define CRYPTO_43_HSE_START_SEC_CONST_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

/*! @brief Array of MU base pointers */
static MU_Type* const Hse_Ip_apMuBase[HSE_IP_NUM_OF_MU_INSTANCES] = MU_HOST_BASE_PTRS;

#define CRYPTO_43_HSE_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

#define CRYPTO_43_HSE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

/*! @brief Array of state structures per MU instance */
static Hse_Ip_MuStateType* Hse_Ip_apMuState[HSE_IP_NUM_OF_MU_INSTANCES];

#define CRYPTO_43_HSE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_43_HSE_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define CRYPTO_43_HSE_START_SEC_CODE
#include "Crypto_43_HSE_MemMap.h"

/*!
 * @brief       Finds a channel with a HSE response.
 * @details     Searches through channels until finds the first one with a HSE response having the requested type and returns its index.
 *
 * @param[in]   u8MuInstance    MU Instance number
 * @param[in]   eReqType        Request type
 *
 * @return      HSE channel index or HSE_IP_INVALID_MU_CHANNEL_U8
 */
static uint8 Hse_Ip_GetFirstChannelWithResponseReady
(
    uint8              u8MuInstance,
    Hse_Ip_ReqTypeType eReqType
);

/*!
 * @brief       Processes the HSE responses.
 * @details     Processes all the responses found having the specified request type.
 *
 * @param[in]   u8MuInstance    MU Instance number
 * @param[in]   eReqType        Request type
 *
 * @return      void
 */
static void Hse_Ip_ProcessReceivedResponses
(
    uint8              u8MuInstance,
    Hse_Ip_ReqTypeType eReqType
);

/*!
 * @brief       Enables the Rx interrupt for the specified MU instance and channel.
 *
 * @param[in]   u8MuInstance    MU Instance number
 * @param[in]   u8MuChannel     MU channel number
 *
 * @return      void
 */
static inline void Hse_Ip_EnableRxIrq
(
    uint8 u8MuInstance,
    uint8 u8MuChannel
);

/*!
 * @brief       Clears the interrupt status flags.
 *
 * @param[in]   u8MuInstance    MU Instance number
 * @param[in]   u32IrqMask      IRQ mask of interrupt status flags
 *
 * @return      void
 */
static inline void Hse_Ip_ClearInterruptFlags
(
    uint8  u8MuInstance,
    uint32 u32IrqMask
);

/*!
 * @brief       Function for calling OsIf_MicrosToTicks, OsIf_GetCounter or OsIf_GetElapsed function
 *
 * @param[in]   u32Micros             microseconds value
 * @param[in]   pu32CurrentRef        current time
 * @param[in]   u8OsIfFnctSelection   parameter used for choosing which function to be called
 *
 * @return      uint32
 */
static inline uint32 Hse_Ip_MicrosToTicks_GetCounter_GetElapsed
(
    uint32         u32Micros, 
    uint32 * const pu32CurrentRef, 
    uint8          u8OsIfFnctSelection
);

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
static uint8 Hse_Ip_GetFirstChannelWithResponseReady
(
    uint8              u8MuInstance,
    Hse_Ip_ReqTypeType eReqType
)
{
    uint8                 u8MuChannel   = 0U;
    boolean               bChannelFound = FALSE;
    uint32                u32ReceiveStatus;
    const Hse_Ip_ReqType* pChannelRequest;

    u32ReceiveStatus = Mu_Ip_GetRxStatusRegister(Hse_Ip_apMuBase[u8MuInstance]);

    while (0U != u32ReceiveStatus)
    {
        pChannelRequest = Hse_Ip_apMuState[u8MuInstance]->apChannelRequest[u8MuChannel];

        if (((uint32)0x01U == (u32ReceiveStatus & (uint32)0x01U)) &&
            ((NULL_PTR != pChannelRequest) && (pChannelRequest->eReqType == eReqType)))
        {
            bChannelFound = TRUE;
            break;
        }
        else
        {
            u32ReceiveStatus = u32ReceiveStatus >> 1U;
            u8MuChannel++;
        }
    }

    if (FALSE == bChannelFound)
    {
        u8MuChannel = HSE_IP_INVALID_MU_CHANNEL_U8;
    }
    return u8MuChannel;
}

static void Hse_Ip_ProcessReceivedResponses
(
    uint8              u8MuInstance,
    Hse_Ip_ReqTypeType eReqType
)
{
    hseSrvResponse_t              HseResponse;
    const Hse_Ip_MuStateType*     pHseIpMuState;
    uint8                         u8MuChannel;
    Hse_Ip_pfResponseCallbackType pfCallback;
    void*                         pCallbackParam;

    pHseIpMuState = Hse_Ip_apMuState[u8MuInstance];
    u8MuChannel   = Hse_Ip_GetFirstChannelWithResponseReady(u8MuInstance, eReqType);

    while (HSE_IP_INVALID_MU_CHANNEL_U8 != u8MuChannel)
    {
        /* Disable Rx interrupt for the channel where the message was received */
        if (HSE_IP_REQTYPE_ASYNC_IRQ == pHseIpMuState->apChannelRequest[u8MuChannel]->eReqType)
        {
            Mu_Ip_SetRxIrqEnable(Hse_Ip_apMuBase[u8MuInstance], u8MuChannel, FALSE);
        }
        /* Read the response from HSE */
        HseResponse = ((hseSrvResponse_t)Mu_Ip_GetRxRegister(Hse_Ip_apMuBase[u8MuInstance], u8MuChannel));
        /* Prepare the callback and its parameter */
        pfCallback     = pHseIpMuState->apChannelRequest[u8MuChannel]->pfCallback;
        pCallbackParam = pHseIpMuState->apChannelRequest[u8MuChannel]->pCallbackParam;
        /* Release the allocated channel */
        Hse_Ip_ReleaseChannel(u8MuInstance, u8MuChannel);
        /* Check if this channel has an associated callback */
        if (NULL_PTR != pfCallback)
        {
            /* Call the callback provided when the request was made */
            pfCallback(u8MuInstance, u8MuChannel, HseResponse, pCallbackParam);
        }
        /* Check again if new messages have been received from HSE */
        u8MuChannel = Hse_Ip_GetFirstChannelWithResponseReady(u8MuInstance, eReqType);
    }
}

static inline void Hse_Ip_EnableRxIrq
(
    uint8 u8MuInstance,
    uint8 u8MuChannel
)
{
    SchM_Enter_Crypto_43_HSE_CRYPTO_EXCLUSIVE_AREA_11();
    /* Enable irq for the requested MU and channel */
    Mu_Ip_SetRxIrqEnable(Hse_Ip_apMuBase[u8MuInstance], u8MuChannel, TRUE);
    SchM_Exit_Crypto_43_HSE_CRYPTO_EXCLUSIVE_AREA_11();
}

static inline uint32 Hse_Ip_MicrosToTicks_GetCounter_GetElapsed
(
    uint32         u32Micros, 
    uint32 * const pu32CurrentRef, 
    uint8          u8OsIfFnctSelection
)
{
    uint32 u32RetVal;
    
    switch (u8OsIfFnctSelection)
    {
        case CRYPTO_HSE_IP_10_OSIF_MICROS_TO_TICKS_CALL:
            u32RetVal = OsIf_MicrosToTicks(u32Micros, (OsIf_CounterType)HSE_IP_TIMEOUT_OSIF_COUNTER_TYPE);
        break;

        case CRYPTO_HSE_IP_11_OSIF_GET_COUNTER_CALL:
            u32RetVal = OsIf_GetCounter((OsIf_CounterType)HSE_IP_TIMEOUT_OSIF_COUNTER_TYPE);
        break;

        case CRYPTO_HSE_IP_12_OSIF_GET_ELAPSED_CALL:
            u32RetVal = OsIf_GetElapsed(pu32CurrentRef, (OsIf_CounterType)HSE_IP_TIMEOUT_OSIF_COUNTER_TYPE);
        break;

        default:
            /* u8OsIfFnctSelection is out of range, therefore return an invalid value*/
            u32RetVal = 0xFFFFFFFFu;
        break;
    }

    return u32RetVal;
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @implements     Hse_Ip_Init_Activity
*/
Hse_Ip_StatusType Hse_Ip_Init
(
    uint8               u8MuInstance,
    Hse_Ip_MuStateType* pHseIpMuState
)
{
    uint8 u8MuChannel;

#if (STD_ON == HSE_IP_DEV_ERROR_DETECT)
    /* Check the validity of the input parameters */
    DevAssert((u8MuInstance  <  HSE_IP_NUM_OF_MU_INSTANCES));
    DevAssert((pHseIpMuState != NULL_PTR));
    /* Check that the driver is not already initialized */
    DevAssert((Hse_Ip_apMuState[u8MuInstance] == NULL_PTR));
#endif /* (STD_ON == HSE_IP_DEV_ERROR_DETECT) */

    /* Fill the state structure with default values */
    pHseIpMuState->pfGenericPurposeCallback = NULL_PTR;

    for (u8MuChannel = 0U; u8MuChannel < HSE_IP_NUM_OF_CHANNELS_PER_MU; u8MuChannel++)
    {
        /* Perform a dummy read of the channel Rx register in order to clear any pending responses not yet processed */
        (void)Mu_Ip_GetRxRegister(Hse_Ip_apMuBase[u8MuInstance], u8MuChannel);
        /* Mark the channel as not allocated */
        pHseIpMuState->abChannelAllocated[u8MuChannel] = FALSE;
        /* Initialize the pointer to async request on this channel to NULL */
        pHseIpMuState->apChannelRequest[u8MuChannel] = NULL_PTR;
    }

    /* Save the reference to the state structure allocated by the application */
    Hse_Ip_apMuState[u8MuInstance] = pHseIpMuState;

    return HSE_IP_STATUS_SUCCESS;
}

/**
 * @implements     Hse_Ip_Deinit_Activity
 */
Hse_Ip_StatusType Hse_Ip_Deinit
(
    uint8 u8MuInstance
)
{
#if (STD_ON == HSE_IP_DEV_ERROR_DETECT)
   /* Check the validity of the input parameters */
    DevAssert((u8MuInstance < HSE_IP_NUM_OF_MU_INSTANCES));
    /* Check that the driver is initialized */
    DevAssert((Hse_Ip_apMuState[u8MuInstance] != NULL_PTR));
#endif /* (STD_ON == HSE_IP_DEV_ERROR_DETECT) */

    /* Drop the state structure reference */
    Hse_Ip_apMuState[u8MuInstance] = NULL_PTR;

    return HSE_IP_STATUS_SUCCESS;
}

/**
 * implements    Hse_Ip_GetFreeChannel_Activity
 */
uint8 Hse_Ip_GetFreeChannel
(
    uint8 u8MuInstance
)
{
    uint8  u8RetVal = HSE_IP_INVALID_MU_CHANNEL_U8;
    uint32 u32ChannelBusyBitmap;
    uint32 u32ChannelMask;
    uint8  u8MuChannel;
    uint32 u32RsrReg;
    uint32 u32TsrReg;

#if (STD_ON == HSE_IP_DEV_ERROR_DETECT)
    /* Check the validity of the input parameters */
    DevAssert((u8MuInstance  <  HSE_IP_NUM_OF_MU_INSTANCES));
    /* Check that the driver is initialized */
    DevAssert((Hse_Ip_apMuState[u8MuInstance] != NULL_PTR));
#endif /* (STD_ON == HSE_IP_DEV_ERROR_DETECT) */

    SchM_Enter_Crypto_43_HSE_CRYPTO_EXCLUSIVE_AREA_10();

    u32ChannelBusyBitmap = Mu_Ip_GetFlagStatusRegister(Hse_Ip_apMuBase[u8MuInstance]) & HSE_IP_HSE_CHANNEL_BUSY_MASK_U32;
    u32RsrReg            = Mu_Ip_GetRxStatusRegister(Hse_Ip_apMuBase[u8MuInstance]);
    u32TsrReg            = Mu_Ip_GetTxStatusRegister(Hse_Ip_apMuBase[u8MuInstance]);
    /* Finds the first unallocated channel, channel 0 is reserved for administrative services */
    for (u8MuChannel = 1U; u8MuChannel < HSE_IP_NUM_OF_CHANNELS_PER_MU; u8MuChannel++)
    {
        /* Checking if the channel is allocated */
        if (!Hse_Ip_apMuState[u8MuInstance]->abChannelAllocated[u8MuChannel])
        {
            u32ChannelMask = ((uint32)1U << u8MuChannel);
            /* Checking the corresponding bits of FSR(processing ongoing) and TSR(request was read) for the current channel */
            if ((0U == (u32ChannelBusyBitmap & u32ChannelMask)) &&
                (0U != (u32TsrReg            & u32ChannelMask))
                )
            {
                /* Check if the RR was not read */
                if(0U != (u32RsrReg & u32ChannelMask))
                {
                    /* Read thr RR register to clear RSR channel bit */
                    (void)Mu_Ip_GetRxRegister(Hse_Ip_apMuBase[u8MuInstance], u8MuChannel);
                }
                Hse_Ip_apMuState[u8MuInstance]->abChannelAllocated[u8MuChannel] = TRUE;
                u8RetVal = u8MuChannel;
                break;
            }
        }
    }

    SchM_Exit_Crypto_43_HSE_CRYPTO_EXCLUSIVE_AREA_10();

    return u8RetVal;
}

/**
 * @implements    Hse_Ip_ReleaseChannel_Activity
 */
void Hse_Ip_ReleaseChannel
(
    uint8 u8MuInstance,
    uint8 u8MuChannel
)
{
#if (STD_ON == HSE_IP_DEV_ERROR_DETECT)
    /* Check the validity of the input parameters */
    DevAssert((u8MuInstance < HSE_IP_NUM_OF_MU_INSTANCES));
    DevAssert((u8MuChannel  < HSE_IP_NUM_OF_CHANNELS_PER_MU));
#endif /* (STD_ON == HSE_IP_DEV_ERROR_DETECT) */

    /* Release the channel */
    Hse_Ip_apMuState[u8MuInstance]->abChannelAllocated[u8MuChannel] = FALSE;
    /* Mark the channel as not processing any request */
    Hse_Ip_apMuState[u8MuInstance]->apChannelRequest[u8MuChannel]   = NULL_PTR;
}

/**
 * @implements     Hse_Ip_ToAHBAddress_Activity
 */
HOST_ADDR Hse_Ip_ToAHBAddress
(
    HOST_ADDR Address
)
{
    HOST_ADDR RetVal = Address;

#if (STD_ON == HSE_IP_ENABLE_TCM_SUPPORT)
    /* Get Partition ID to determine which address offset to apply */
    uint8 PartitionId = OsIf_GetUserId();

    /* If HSE_IP_ITCM_ADDR_END_U32 == 0U, the device only has general TCM memory, treated as DTCM */
    /* Check if the address is in ITCM range */
#if ((0U < HSE_IP_ITCM_ADDR_END_U32) && (HSE_IP_ITCM_ADDR_END_U32 > HSE_IP_ITCM_ADDR_START_U32))
    if((Address <  HSE_IP_ITCM_ADDR_END_U32)
    #if (0U < HSE_IP_ITCM_ADDR_START_U32)
    && (Address >= HSE_IP_ITCM_ADDR_START_U32)
    #endif /* (0U < HSE_IP_ITCM_ADDR_END_U32) */
    )
    {
        RetVal = (HOST_ADDR)(Address + Hse_Ip_aItcmAddrOffset[PartitionId]);
    }
    else
#endif /* ((0U < HSE_IP_ITCM_ADDR_END_U32) && (HSE_IP_ITCM_ADDR_END_U32 > HSE_IP_ITCM_ADDR_START_U32)) */
    /* Check if the address is in DTCM range */
#if ((0U < HSE_IP_DTCM_ADDR_END_U32) && (HSE_IP_DTCM_ADDR_END_U32 > HSE_IP_DTCM_ADDR_START_U32))
    if((Address >= HSE_IP_DTCM_ADDR_START_U32) && (Address < HSE_IP_DTCM_ADDR_END_U32))
    {
        RetVal = (HOST_ADDR)(Address + Hse_Ip_aDtcmAddrOffset[PartitionId]);
    }
    else
#endif /* ((0U < HSE_IP_DTCM_ADDR_END_U32) && (HSE_IP_DTCM_ADDR_END_U32 > HSE_IP_DTCM_ADDR_START_U32)) */
    {
        /* Do nothing - Address is not in TCM range */
    }

    /* Avoid compiler warnings */
    (void) PartitionId;
#endif /* (STD_ON == HSE_IP_ENABLE_TCM_SUPPORT) */

    return RetVal;
}

/**
 * @implements     Hse_Ip_ServiceRequest_Activity
 */
hseSrvResponse_t Hse_Ip_ServiceRequest
(
    uint8               u8MuInstance,
    uint8               u8MuChannel,
    Hse_Ip_ReqType*     pRequest,
    hseSrvDescriptor_t* pHseSrvDesc
)
{
    hseSrvResponse_t    HseResponse     = HSE_SRV_RSP_OK;
    uint32              u32ElapsedTicks = 0U;
    Hse_Ip_MuStateType* pHseIpMuState;
    uint32              u32TimeoutTicks;
    uint32              u32CurrentTicks;

#if (STD_ON == HSE_IP_DEV_ERROR_DETECT)
    /* Check the validity of the input parameters */
    DevAssert((u8MuInstance < HSE_IP_NUM_OF_MU_INSTANCES));
#endif /* (STD_ON == HSE_IP_DEV_ERROR_DETECT) */

    /* Keep a pointer to MuState to optimize a bit the code for accessing it */
    pHseIpMuState = Hse_Ip_apMuState[u8MuInstance];

#if (STD_ON == HSE_IP_DEV_ERROR_DETECT)
    DevAssert((u8MuChannel  < HSE_IP_NUM_OF_CHANNELS_PER_MU));
    DevAssert((pRequest    != NULL_PTR));
    DevAssert((pHseSrvDesc != NULL_PTR));
    DevAssert(((HSE_IP_REQTYPE_SYNC       == pRequest->eReqType) || \
                     (HSE_IP_REQTYPE_ASYNC_IRQ  == pRequest->eReqType) || \
                     (HSE_IP_REQTYPE_ASYNC_POLL == pRequest->eReqType)));
    /* For HSE_IP_REQTYPE_ASYNC_IRQ and HSE_IP_REQTYPE_ASYNC_POLL requests, there should always be a callback */
    DevAssert(((pRequest->eReqType == HSE_IP_REQTYPE_SYNC) || (NULL_PTR != pRequest->pfCallback)));
    /* Check that the driver is initialized */
    DevAssert((pHseIpMuState != NULL_PTR));
    /* Check that the channel is allocated */
    DevAssert(((0U == u8MuChannel) || (TRUE == pHseIpMuState->abChannelAllocated[u8MuChannel])));
#endif /* (STD_ON == HSE_IP_DEV_ERROR_DETECT) */

    /* Check if the used channel is channel 0 and if it is already in use */
    if ((0U == u8MuChannel) && (TRUE == pHseIpMuState->abChannelAllocated[u8MuChannel]))
    {
        /* Channel 0 is in use, return error and exit the function */
        HseResponse = HSE_IP_SRV_RSP_BUSY;
    }
    else
    {
        /* Check if the used channel is channel 0 */
        if(0U == u8MuChannel)
        {
            /* Allocate channel 0 */
            pHseIpMuState->abChannelAllocated[u8MuChannel] = TRUE;
        }

        /* Save the reference to the request. This is used to mark the channel as processing a request and is also used to filter out spurious interrupts */
        pHseIpMuState->apChannelRequest[u8MuChannel] = pRequest;

        if (HSE_IP_REQTYPE_SYNC == pRequest->eReqType)
        {
            /* Convert from microseconds to ticks */
            u32TimeoutTicks = Hse_Ip_MicrosToTicks_GetCounter_GetElapsed(pRequest->u32Timeout, NULL_PTR, CRYPTO_HSE_IP_10_OSIF_MICROS_TO_TICKS_CALL);
            /* Send the service request to HSE */
            Mu_Ip_SetTxRegister(Hse_Ip_apMuBase[u8MuInstance], u8MuChannel, HSE_IP_PTR_TO_REG32(pHseSrvDesc));
            /* Read the current value of the counter */
            u32CurrentTicks = Hse_Ip_MicrosToTicks_GetCounter_GetElapsed(0u, NULL_PTR, CRYPTO_HSE_IP_11_OSIF_GET_COUNTER_CALL);
            /* Wait for the HSE response */
            while ((FALSE == Mu_Ip_IsResponseReady(Hse_Ip_apMuBase[u8MuInstance], u8MuChannel)) && (u32ElapsedTicks < u32TimeoutTicks))
            {
                /* Update the elapsed ticks, current ticks will be updated too by the OsIf function */
                u32ElapsedTicks += Hse_Ip_MicrosToTicks_GetCounter_GetElapsed(0u, &u32CurrentTicks, CRYPTO_HSE_IP_12_OSIF_GET_ELAPSED_CALL);
            }
            /* If timeout expired - return timeout error in case no response detected */
            if (u32ElapsedTicks >= u32TimeoutTicks)
            {
                /* Check if HSE response is ready in case timeout happens because of interupt */
                if(TRUE == Mu_Ip_IsResponseReady(Hse_Ip_apMuBase[u8MuInstance], u8MuChannel))
                {
                    HseResponse = Mu_Ip_GetRxRegister(Hse_Ip_apMuBase[u8MuInstance], u8MuChannel);
                }
                else
                {
                    HseResponse = HSE_IP_SRV_RSP_NO_RESPONSE;
                }
            }
            else
            {
                /* Read the response */
                HseResponse = Mu_Ip_GetRxRegister(Hse_Ip_apMuBase[u8MuInstance], u8MuChannel);
            }
            /* Release the allocated channel */
            Hse_Ip_ReleaseChannel(u8MuInstance, u8MuChannel);
        }
        else
        {
            /* Enable the Rx interrupt if the request is async irq */
            if (HSE_IP_REQTYPE_ASYNC_IRQ == pRequest->eReqType)
            {
                /* Perform a dummy read of the channel Rx register in order to clear any pending responses from spurious events */
                (void)Mu_Ip_GetRxRegister(Hse_Ip_apMuBase[u8MuInstance], u8MuChannel);

                Hse_Ip_EnableRxIrq(u8MuInstance, u8MuChannel);
            }
            /* Send the service request to HSE */
            Mu_Ip_SetTxRegister(Hse_Ip_apMuBase[u8MuInstance], u8MuChannel, HSE_IP_PTR_TO_REG32(pHseSrvDesc));
        }
    }
    return HseResponse;
}

/**
 * @implements     Hse_Ip_MainFunction_Activity
 */
void Hse_Ip_MainFunction
(
    uint8 u8MuInstance
)
{
#if (STD_ON == HSE_IP_DEV_ERROR_DETECT)
    /* Check the validity of the input parameters */
    DevAssert((u8MuInstance < HSE_IP_NUM_OF_MU_INSTANCES));
#endif /* (STD_ON == HSE_IP_DEV_ERROR_DETECT) */

    Hse_Ip_ProcessReceivedResponses(u8MuInstance, HSE_IP_REQTYPE_ASYNC_POLL);
}

/**
 * @implements     Hse_Ip_GetHseStatus_Activity
 */
hseStatus_t Hse_Ip_GetHseStatus
(
    uint8 u8MuInstance
)
{
#if (STD_ON == HSE_IP_DEV_ERROR_DETECT)
    /* Check the validity of the input parameters */
    DevAssert((u8MuInstance < HSE_IP_NUM_OF_MU_INSTANCES));
#endif /* (STD_ON == HSE_IP_DEV_ERROR_DETECT) */

    uint32 u32Status = Mu_Ip_GetFlagStatusRegister(Hse_Ip_apMuBase[u8MuInstance]);

    return ((hseStatus_t)((u32Status & HSE_IP_HSE_STATUS_MASK_U32) >> HSE_IP_HSE_STATUS_SHIFT_U8));
}

/**
 * @implements     Hse_Ip_RegisterGenericCallback_Activity
 */
void Hse_Ip_RegisterGenericCallback
(
    uint8                               u8MuInstance,
    uint32                              u32NotifEventsMask,
    Hse_Ip_pfGenericPurposeCallbackType pfCallback
)
{
#if (STD_ON == HSE_IP_DEV_ERROR_DETECT)
    /* Check the validity of the input parameters */
    DevAssert((u8MuInstance < HSE_IP_NUM_OF_MU_INSTANCES));
    DevAssert((pfCallback  != NULL_PTR));
    /* Check that the driver is initialized */
    DevAssert((Hse_Ip_apMuState[u8MuInstance] != NULL_PTR));
#endif /* (STD_ON == HSE_IP_DEV_ERROR_DETECT) */

    Hse_Ip_apMuState[u8MuInstance]->pfGenericPurposeCallback = pfCallback;
    Mu_Ip_SetGlobalIrqEnable(Hse_Ip_apMuBase[u8MuInstance], u32NotifEventsMask);
}

/**
 * @implements     Hse_Ip_SendHseEvent_Activity
 */
void Hse_Ip_SendHseEvent
(
    hseHostEvent_t HseHostEvent
)
{
    Mu_Ip_SetGlobalConfigRegister(Hse_Ip_apMuBase[HSE_IP_MU_0_INSTANCE_U8], (uint32)HseHostEvent);
}


static inline void Hse_Ip_ClearInterruptFlags
(
    uint8  u8MuInstance,
    uint32 u32IrqMask
)
{
    uint8 u8MuChannel;
    const MU_Type* pMuBase = Hse_Ip_apMuBase[u8MuInstance];

    /* Loop through each of the channels in the MU instance */
    for (u8MuChannel = 0U; u8MuChannel < HSE_IP_NUM_OF_CHANNELS_PER_MU; u8MuChannel++)
    {
        /* Check if a spurious interrupt was detected on the currently looped MU channel by seeing if the channel does not have any request at this point in time */
        if (0U != (((uint32)(1UL << u8MuChannel)) & u32IrqMask))
        {
            if(NULL_PTR == Hse_Ip_apMuState[u8MuInstance]->apChannelRequest[u8MuChannel])
            {
                /* Disabling interrupt in case of spurious interrupt when no request is configured */
                Mu_Ip_SetRxIrqEnable(Hse_Ip_apMuBase[u8MuInstance], u8MuChannel, FALSE);
                
                /* Perform a dummy read on the looped channel. This will clear the interrupt flag */
                (void)Mu_Ip_GetRxRegister(pMuBase, u8MuChannel);
            }
            else if (HSE_IP_REQTYPE_SYNC == Hse_Ip_apMuState[u8MuInstance]->apChannelRequest[u8MuChannel]->eReqType)
            {
                /* Disabling interrupt in case of spurious interrupt, and no asynchronous request is configured */
                Mu_Ip_SetRxIrqEnable(Hse_Ip_apMuBase[u8MuInstance], u8MuChannel, FALSE);
            }
            else
            {
                /* to avoid Misra violations*/
            }
        }
    }
}

/**
 * @implements     Hse_Ip_RxIrqHandler_Activity
 */
void Hse_Ip_RxIrqHandler
(
    uint8 u8MuInstance
)
{
    const MU_Type* pMuBase       = Hse_Ip_apMuBase[u8MuInstance];
    uint32         u32ControlReg;
    uint32         u32StatusReg;
    uint32         u32IrqMask;
    uint8          u8MuChannel;

    /* Check if HseIp layer has been initialized for the current MU instance */
    if (NULL_PTR == Hse_Ip_apMuState[u8MuInstance])
    {
        /* MU instance not initialized. Loop through each of the channels in the MU instance and perform a dummy read on the looped channel.
           This will clear the interrupt flags of every MU channel */
        for (u8MuChannel = 0U; u8MuChannel < HSE_IP_NUM_OF_CHANNELS_PER_MU; u8MuChannel++)
        {
            (void)Mu_Ip_GetRxRegister(pMuBase, u8MuChannel);
        }
    }
    else
    {
        u32ControlReg = Mu_Ip_GetRxControlRegister(pMuBase);
        u32StatusReg  = Mu_Ip_GetRxStatusRegister(pMuBase);
        u32IrqMask    = (u32ControlReg & u32StatusReg);

        if (0U != u32IrqMask)
        {
            /* Start processing the interrupt */
            Hse_Ip_ProcessReceivedResponses(u8MuInstance, HSE_IP_REQTYPE_ASYNC_IRQ);

            u32StatusReg  = Mu_Ip_GetRxStatusRegister(pMuBase);
            u32IrqMask    = (u32ControlReg & u32StatusReg);

            /* There should be no channels with Control bit = 1 and Status bit = 1, if they are, this means that Hse_Ip_ProcessReceivedResponses() did not service the interrupt
              because it did not find a Hse_Ip_apMuState[u8MuInstance]->apChannelRequest[u8MuChannel] != NULL thus a spurious interrupt occurred.
              In order to avoid the interrupt to trigger again and enter an infinite loop, the status interrupt flag must cleared. */
            if (0U != u32IrqMask)
            {
                Hse_Ip_ClearInterruptFlags(u8MuInstance, u32IrqMask);
            }
        }
    }
}

/**
 * @implements     Hse_Ip_GeneralPurposeIrqHandler_Activity
 */
void Hse_Ip_GeneralPurposeIrqHandler
(
    uint8 u8MuInstance
)
{
    uint32 u32EnabledIrqsBitmap;
    uint32 u32ActiveIrqsBitmap;
    uint32 u32ValidIrqsMask;

    /* Check if HseIp layer has been initialized for the current MU instance */
    if (NULL_PTR == Hse_Ip_apMuState[u8MuInstance])
    {
        /* Clear interrupt flags for all errors */
        Mu_Ip_ClearGlobalIrqFlags(Hse_Ip_apMuBase[u8MuInstance], HSE_IP_HSE_ALL_ERROR_FLAGS_MASK_U32);
    }
    else
    {
        /* HseIp layer has been initialized for the current MU instance
           Read the interrupt status and interrupt enable bits from the corresponding registers */
        u32ActiveIrqsBitmap  = Mu_Ip_GetGlobalIrqFlags(Hse_Ip_apMuBase[u8MuInstance]);
        u32EnabledIrqsBitmap = Mu_Ip_GetGlobalIrqEnable(Hse_Ip_apMuBase[u8MuInstance]);
        /* Get the list of valid irqs: must have both status and interrupt enable bits set */
        u32ValidIrqsMask     = u32EnabledIrqsBitmap & u32ActiveIrqsBitmap;

        /* Check if there are any valid irqs */
        if(0U != u32ValidIrqsMask)
        {
            /* Clear interrupt flags for all valid irqs */
            Mu_Ip_ClearGlobalIrqFlags(Hse_Ip_apMuBase[u8MuInstance], u32ValidIrqsMask);

            /* Call the generic purpose callback, if the handler is not NULL */
            if (Hse_Ip_apMuState[u8MuInstance]->pfGenericPurposeCallback != NULL_PTR)
            {
                Hse_Ip_apMuState[u8MuInstance]->pfGenericPurposeCallback(u8MuInstance, u32ValidIrqsMask);
            }
        }
    }
}


#define CRYPTO_43_HSE_STOP_SEC_CODE
#include "Crypto_43_HSE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

