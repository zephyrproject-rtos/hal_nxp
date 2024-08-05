/*
 * Copyright 2021-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 *  @file Netc_Eth_Ip_Irq.c
 *  @internal
 *
 *  @addtogroup NETC_ETH_DRIVER NETC_ETH Driver
 *  @{
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
#include "Netc_Eth_Ip.h"
#include "Netc_Eth_Ip_Irq.h"
#if(NETC_ETH_IP_DEV_ERROR_DETECT == STD_ON)
    #include "Devassert.h"
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETH_IP_IRQ_VENDOR_ID_C                   43
#define NETC_ETH_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    4
#define NETC_ETH_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    7
#define NETC_ETH_IP_IRQ_AR_RELEASE_REVISION_VERSION_C 0
#define NETC_ETH_IP_IRQ_SW_MAJOR_VERSION_C            2
#define NETC_ETH_IP_IRQ_SW_MINOR_VERSION_C            0
#define NETC_ETH_IP_IRQ_SW_PATCH_VERSION_C            0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against NETC_ETH_IP_IRQ.h */
#if (NETC_ETH_IP_IRQ_VENDOR_ID_C != NETC_ETH_IP_VENDOR_ID)
    #error "Netc_Eth_Ip.c and Netc_Eth_Ip.h have different vendor ids"
#endif
#if ((NETC_ETH_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != NETC_ETH_IP_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETH_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != NETC_ETH_IP_AR_RELEASE_MINOR_VERSION) || \
     (NETC_ETH_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != NETC_ETH_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Netc_Eth_Ip.c and Netc_Eth_Ip.h are different"
#endif
#if ((NETC_ETH_IP_IRQ_SW_MAJOR_VERSION_C != NETC_ETH_IP_SW_MAJOR_VERSION) || \
     (NETC_ETH_IP_IRQ_SW_MINOR_VERSION_C != NETC_ETH_IP_SW_MINOR_VERSION) || \
     (NETC_ETH_IP_IRQ_SW_PATCH_VERSION_C != NETC_ETH_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Netc_Eth_Ip.c and Netc_Eth_Ip.h are different"
#endif

/* Checks against NETC_ETH_IP_IRQ.h */
#if (NETC_ETH_IP_IRQ_VENDOR_ID_C != NETC_ETH_IP_IRQ_VENDOR_ID)
    #error "Netc_Eth_Ip.c and Netc_Eth_Ip.h have different vendor ids"
#endif
#if ((NETC_ETH_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != NETC_ETH_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETH_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != NETC_ETH_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (NETC_ETH_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != NETC_ETH_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Netc_Eth_Ip.c and Netc_Eth_Ip.h are different"
#endif
#if ((NETC_ETH_IP_IRQ_SW_MAJOR_VERSION_C != NETC_ETH_IP_IRQ_SW_MAJOR_VERSION) || \
     (NETC_ETH_IP_IRQ_SW_MINOR_VERSION_C != NETC_ETH_IP_IRQ_SW_MINOR_VERSION) || \
     (NETC_ETH_IP_IRQ_SW_PATCH_VERSION_C != NETC_ETH_IP_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Netc_Eth_Ip.c and Netc_Eth_Ip.h are different"
#endif
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define ETH_43_NETC_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"

extern Netc_Eth_Ip_VfBaseType *netcVFBase[FEATURE_NETC_ETH_NUMBER_OF_CTRLS];

#define ETH_43_NETC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/* Pointer to each SI base. */
extern Netc_Eth_Ip_SiBaseType *netcSIsBase[8U];

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/**
 * @brief
 *
 * @param CtrlIndex
 */
static inline void Netc_Eth_Ip_MSIX_Tx(uint8 CtrlIndex);

/**
 * @brief
 *
 * @param TxRingIntStatus
 * @param CtrlIndex
 */
static inline void Netc_Eth_Ip_MSIX_Tx_CheckAllRings(const uint32 TxRingIntStatus, const uint8 CtrlIndex);

/**
 * @brief
 *
 * @param CtrlIndex
 */
static inline void Netc_Eth_Ip_MSIX_Rx(uint8 CtrlIndex);

/**
 * @brief Local function used to process PSI Message Receive event
 *
 * @param CmdMacReceivedAddr
 * @param VSIIndex
 */
static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_VsiToPsi_Mac_Addr_Set(const Netc_Eth_Ip_VsiToPsiMsgType* const CmdMacReceivedAddr, uint8 VSIIndex);

/**
 * @brief Local function used to process PSI Message Receive event
 *
 * @param CmdMacReceivedAddr
 * @param VSIIndex
 */
static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_VsiToPsi_Add_Rx_Mac_Addr_Filter(const Netc_Eth_Ip_VsiToPsiMsgType* const CmdMacReceivedAddr, uint8 VSIIndex);

/**
 * @brief Local function used to process PSI Message Receive event
 *
 * @param CmdMacReceivedAddr
 * @param VSIIndex
 */
static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_VsiToPsi_Delete_Rx_Mac_Addr_Filter(const Netc_Eth_Ip_VsiToPsiMsgType* const CmdMacReceivedAddr, uint8 VSIIndex);


/**
 * @brief Local function used to process PSI Message Receive event
 *
 * @param VSIIndex
 */
static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_VsiToPsi_Enable_Multicast(uint8 VSIIndex);

/**
 * @brief Local function used to process PSI Message Receive event
 *
 * @param VSIIndex
 */
static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_VsiToPsi_Disable_Multicast(uint8 VSIIndex);

/**
 * @brief Local function used to process PSI Message Receive event
 *
 * @param VSIIndex
 */
static inline void Netc_Eth_Ip_VsiToPsi_Close_Filter(uint8 VSIIndex);

/**
 * @brief Local function used to process PSI Message Receive event
 *
 * @param
 */
static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_Get_Sync_State(void);


/**
 * @brief Local function used to process PSI Message Receive event
 *
 * @param VSIIndex
 */
static inline void Netc_Eth_Ip_ProcessMsgRcv(uint8 VSIIndex);

/**
 * @brief Local function used to re-initialize the VSI after a Function Level Reset event
 *
 * @param VSIIndex
 */
static inline void Netc_Eth_Ip_InitVSIAfterFlr(uint8 VSIIndex);

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
/***************************************************************************
 * implements     Netc_Eth_Ip_MSIX_Tx_Activity
 ***************************************************************************/
static inline void Netc_Eth_Ip_MSIX_Tx(uint8 CtrlIndex)
{
    uint32 TxRingIntStatus = netcSIsBase[CtrlIndex]->SITXIDR0;
    /*
    * Checking the first queue Interrupt Enable flag
    *  In order to fulfill requirement CPR_RTD_00664, the interrupt enable flag for the first queue is checked for the following reasons:
    * 1. The interrupts are enabled at controller level, therefore if one queue has the interrupt enabled, then all of the queues will have it.
    * 2. In ETH driver case, the queues are mandatory configured in order, so that the first queue enables the interrupt, then all of the queues will have the interrupt enable flag set
    * 3. Performance reason: one check vs no.of queues checks
    */
    if(NETC_ETH_IP_TBIER_TXFIE_MASK == (netcSIsBase[CtrlIndex]->BDR_NUM[0U].TBIER & NETC_ETH_IP_TBIER_TXFIE_MASK))
    {
        /* Clear TX interrupt flag for all SIs. */
        netcSIsBase[CtrlIndex]->SITXIDR0 = TxRingIntStatus;
        /* The flags for frame interrupt are allocated in the upper 16 bits of the register,
        shift them in the lower part. */
        TxRingIntStatus >>= 16UL;
        Netc_Eth_Ip_MSIX_Tx_CheckAllRings(TxRingIntStatus, CtrlIndex);
    }
    else if(NETC_ETH_IP_TBIER_TXTIE_MASK == (netcSIsBase[CtrlIndex]->BDR_NUM[0U].TBIER & NETC_ETH_IP_TBIER_TXTIE_MASK))
    {
        /* Clear TX interrupt flag for all SIs. */
        netcSIsBase[CtrlIndex]->SITXIDR0 = TxRingIntStatus;
        /* Keep only coalescing interrupt status. */
        TxRingIntStatus &= 0x0000FFFFUL;
        Netc_Eth_Ip_MSIX_Tx_CheckAllRings(TxRingIntStatus, CtrlIndex);
    }
    else
    {
        /*  MISRA C-2012 Rule 15.7 */
    }

}

/***************************************************************************
 * implements     Netc_Eth_Ip_MSIX_Rx_Activity
 ***************************************************************************/
static inline void Netc_Eth_Ip_MSIX_Rx(uint8 CtrlIndex)
{
    uint8  RingIndex;
    uint32 interruptStatus = netcSIsBase[CtrlIndex]->SIRXIDR0;
    /*
    * Checking the first queue Interrupt Enable flag
    *  In order to fulfill requirement CPR_RTD_00664, the interrupt enable flag for the first queue is checked for the following reasons:
    * 1. The interrupts are enabled at controller level, therefore if one queue has the interrupt enabled, then all of the queues will have it.
    * 2. In ETH driver case, the queues are mandatory configured in order, so that the first queue enables the interrupt, then all of the queues will have the interrupt enable flag set
    * 3. Performance reason: one check vs no.of queues checks
    */
    if (NETC_ETH_IP_RBIER_RXTIE_MASK == netcSIsBase[CtrlIndex]->BDR_NUM[0u].RBIER)
    {
        /* Clear RX interrupt flag for all SIs.*/
        netcSIsBase[CtrlIndex]->SIRXIDR0 = interruptStatus;

         /* Check is current controller was intialized.  Req CPR_RTD_00011 is fulfilled.*/
        if (NULL_PTR != Netc_Eth_Ip_apxState[CtrlIndex])
        {
             /* Check all rings of the current controller. */
            for(RingIndex = 0; RingIndex < Netc_Eth_Ip_apxState[CtrlIndex]->NumberOfRxBDR; RingIndex++)
            {
                if ((1U == (interruptStatus >> RingIndex)) && (NULL_PTR != Netc_Eth_Ip_apxState[CtrlIndex]->RxCallback[RingIndex]))
                {
                    Netc_Eth_Ip_apxState[CtrlIndex]->RxCallback[RingIndex](Netc_Eth_Ip_apxState[CtrlIndex]->CtrlLogicalIndex, RingIndex);
                }
            }
        }
    }
}


static inline void Netc_Eth_Ip_MSIX_Tx_CheckAllRings(const uint32 TxRingIntStatus, const uint8 CtrlIndex)
{
    uint8  RingIndex;
    if (NULL_PTR != Netc_Eth_Ip_apxState[CtrlIndex])
    {
        for(RingIndex = 0U; RingIndex < Netc_Eth_Ip_apxState[CtrlIndex]->NumberOfTxBDR; RingIndex++)
        {
            /* In non autosar the user needs to define his own callback */
            if ((1U == (TxRingIntStatus >> RingIndex)) && (NULL_PTR != Netc_Eth_Ip_apxState[CtrlIndex]->TxCallback[RingIndex]))
            {
                Netc_Eth_Ip_apxState[CtrlIndex]->TxCallback[RingIndex](Netc_Eth_Ip_apxState[CtrlIndex]->CtrlLogicalIndex, RingIndex);
            }
        }
    }
}

static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_VsiToPsi_Mac_Addr_Set(const Netc_Eth_Ip_VsiToPsiMsgType* const CmdMacReceivedAddr, uint8 VSIIndex)
{
    const Netc_Eth_Ip_GeneralSIConfigType* SIConfig;
    Netc_Eth_Ip_StatusType PSIResponseStatus;

    /*Get the SI general configuration */
    SIConfig = &(*Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->SIGeneralConfig)[VSIIndex];
    if (SIConfig->changeMACAllowed == TRUE)
    {
        /* For the VSIs write the MAC address in the PSIaMAR0 and PSIaMAR1 registers. */
        IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIPMAR0 =  (uint32)(CmdMacReceivedAddr->Data[2U])         | \
                                                          ((uint32)(CmdMacReceivedAddr->Data[3U]) << 8U ) | \
                                                          ((uint32)(CmdMacReceivedAddr->Data[4U]) << 16U) | \
                                                          ((uint32)(CmdMacReceivedAddr->Data[5U]) << 24U);
        IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIPMAR1 =  (uint32)(CmdMacReceivedAddr->Data[6U])         | \
                                                          ((uint32)(CmdMacReceivedAddr->Data[7U]) << 8U);
        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_CMD_SUCCESFUL;
    }
    else
    {
        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_PERMISSION_DENIED;
    }
    return PSIResponseStatus;
}


static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_VsiToPsi_Add_Rx_Mac_Addr_Filter(const Netc_Eth_Ip_VsiToPsiMsgType* const CmdMacReceivedAddr, uint8 VSIIndex)
{
    const Netc_Eth_Ip_GeneralSIConfigType* SIConfig;
    Netc_Eth_Ip_StatusType PSIResponseStatus;
    uint8 HashValue;

    /*Get the SI general configuration */
    SIConfig = &(*Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->SIGeneralConfig)[VSIIndex];
    if (SIConfig->hashFilterUpdateAllowed == TRUE)
    {
        HashValue = CmdMacReceivedAddr->Data[0U];
        if ((HashValue & NETC_ETH_IP_SELECT_HASH_REGISTER) != (uint8)0U)
        {
            IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIMMHFR1 |= (uint32)((uint32)1U << (HashValue & NETC_ETH_IP_HASH_VALUE));
        }
        else
        {
            IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIMMHFR0 |= (uint32)((uint32)1U << (HashValue & NETC_ETH_IP_HASH_VALUE));
        }

        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_CMD_SUCCESFUL;
    }
    else
    {
        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_PERMISSION_DENIED;
    }
    return PSIResponseStatus;
}

static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_VsiToPsi_Delete_Rx_Mac_Addr_Filter(const Netc_Eth_Ip_VsiToPsiMsgType* const CmdMacReceivedAddr, uint8 VSIIndex)
{
    const Netc_Eth_Ip_GeneralSIConfigType* SIConfig;
    Netc_Eth_Ip_StatusType PSIResponseStatus;
    uint8 HashValue;

    /*Get the SI general configuration */
    SIConfig = &(*Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->SIGeneralConfig)[VSIIndex];
    if (SIConfig->hashFilterUpdateAllowed == TRUE)
    {
        HashValue = CmdMacReceivedAddr->Data[0U];
        if ((HashValue & NETC_ETH_IP_SELECT_HASH_REGISTER) != (uint8)0U)
        {
            IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIMMHFR1 &= ~(uint32)((uint32)1U << (HashValue & NETC_ETH_IP_HASH_VALUE));
        }
        else
        {
            IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIMMHFR0 &= ~(uint32)((uint32)1U << (HashValue & NETC_ETH_IP_HASH_VALUE));
        }

        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_CMD_SUCCESFUL;
    }
    else
    {
        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_PERMISSION_DENIED;
    }
    return PSIResponseStatus;
}

static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_VsiToPsi_Enable_Multicast(uint8 VSIIndex)
{
    const Netc_Eth_Ip_GeneralSIConfigType* SIConfig;
    Netc_Eth_Ip_StatusType PSIResponseStatus;

    /*Get the SI general configuration */
    SIConfig = &(*Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->SIGeneralConfig)[VSIIndex];
    if (SIConfig->multicastPromiscuousChangeAllowed == TRUE)
    {
        /* Enable MAC multicast promiscuous mode. */
        IP_NETC__ENETC0_BASE->PSIPMMR |= ((uint32)((uint32)1U << ((uint8)VSIIndex + NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT)));

        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_CMD_SUCCESFUL;
    }
    else
    {
        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_PERMISSION_DENIED;
    }
    return PSIResponseStatus;
}


static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_VsiToPsi_Disable_Multicast(uint8 VSIIndex)
{
    const Netc_Eth_Ip_GeneralSIConfigType* SIConfig;
    Netc_Eth_Ip_StatusType PSIResponseStatus;

    /*Get the SI general configuration */
    SIConfig = &(*Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->SIGeneralConfig)[VSIIndex];
    if (SIConfig->multicastPromiscuousChangeAllowed == TRUE)
    {
        /* Disable MAC multicast promiscuous mode. */
        IP_NETC__ENETC0_BASE->PSIPMMR &= ~((uint32) ((uint32)1U << ((uint8)VSIIndex + NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT)));

        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_CMD_SUCCESFUL;
    }
    else
    {
        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_PERMISSION_DENIED;
    }
    return PSIResponseStatus;
}

static inline void Netc_Eth_Ip_VsiToPsi_Close_Filter(uint8 VSIIndex)
{
    const Netc_Eth_Ip_GeneralSIConfigType* SIConfig;
    /*Get the SI general configuration */
    SIConfig = &(*Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->SIGeneralConfig)[VSIIndex]; 
    if (SIConfig->multicastPromiscuousChangeAllowed == TRUE)
    {
        /* Disable MAC multicast promiscuous mode. */
        IP_NETC__ENETC0_BASE->PSIPMMR &= ~((uint32)((uint32)1U << ((uint8)VSIIndex + NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT)));
    }

    if (SIConfig->hashFilterUpdateAllowed == TRUE)
    {
        /* Clear all entries in filter. */
        IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIMMHFR1 = (uint32)0x0U;
        IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIMMHFR0 = (uint32)0x0U;
    }
}

static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_Get_Sync_State(void)
{
    Netc_Eth_Ip_StatusType PSIResponseStatus;

    if ((IP_NETC__ENETC0_SI0->SITSR & NETC_F3_SI0_SITSR_SYNC_MASK) != 0U)
    {
        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_SYNC_STATUS_TRUE;
    }
    else
    {
        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_SYNC_STATUS_FALSE;
    }
    return PSIResponseStatus;
}

static inline void Netc_Eth_Ip_ProcessMsgRcv(uint8 VSIIndex)
{
    const Netc_Eth_Ip_VsiToPsiMsgType *CmdMacReceivedAddr;
    Netc_Eth_Ip_VsiToPsiMsgActionType CommandType;
    Netc_Eth_Ip_StatusType PSIResponse = NETC_ETH_IP_STATUS_NOT_REAL_ERROR;

    CmdMacReceivedAddr =(const Netc_Eth_Ip_VsiToPsiMsgType *)(netcSIsBase[NETC_ETH_IP_PSI_INDEX]->MSGSR.PSI_A.VSI_NUM[VSIIndex].PSIVMSGRCVAR0 & \
                        NETC_F3_SI0_PSIVMSGRCVAR0_ADDRL_MASK);

#if defined(ERR_IPV_NETC_051247)
    #if (STD_ON == ERR_IPV_NETC_051247)
    /* Verify data integrity for the received msg. Number of VSI written bytes is unknown here, the CRC must be calculated on the whole msg buffer, minus the transmitted CRC byte*/
    if(Netc_Eth_Ip_VsiMsgCalculateCRC8( CmdMacReceivedAddr, (((uint8)sizeof(Netc_Eth_Ip_VsiToPsiMsgType) * (uint8)NETC_ETH_IP_VSITOPSI_MSG_SIZE) - (uint8)1U)) ==
                                                             CmdMacReceivedAddr->Data[NETC_ETH_IP_VSI_MSG_CRC_POS] )
    {
    #endif
#endif
        CommandType = (Netc_Eth_Ip_VsiToPsiMsgActionType)((uint16)((uint32)CmdMacReceivedAddr->Class << 8U) + ((uint32)CmdMacReceivedAddr->Command));

        /* Check if the driver was intialized.  Req CPR_RTD_00011 is fulfilled.*/
        if (NULL_PTR != Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX])
        {
            /*Get the SI general configuration */

            switch(CommandType)
            {
                case NETC_ETH_IP_VSITOPSI_MAC_ADDR_SET:
                {
                    PSIResponse = Netc_Eth_Ip_VsiToPsi_Mac_Addr_Set(CmdMacReceivedAddr, (VSIIndex + 1U));
                    break;
                }
                case NETC_ETH_IP_VSITOPSI_ADD_RX_MAC_ADDR_FILTER:
                {
                    PSIResponse = Netc_Eth_Ip_VsiToPsi_Add_Rx_Mac_Addr_Filter(CmdMacReceivedAddr, (VSIIndex + 1U));
                    break;
                }
                case NETC_ETH_IP_VSITOPSI_DELETE_RX_MAC_ADDR_FILTER:
                {
                    PSIResponse = Netc_Eth_Ip_VsiToPsi_Delete_Rx_Mac_Addr_Filter(CmdMacReceivedAddr, (VSIIndex + 1U));
                    break;
                }
                case NETC_ETH_IP_VSITOPSI_ENABLE_MULTICAST:
                {
                    PSIResponse = Netc_Eth_Ip_VsiToPsi_Enable_Multicast(VSIIndex + 1U);
                    break;
                }
                case NETC_ETH_IP_VSITOPSI_DISABLE_MULTICAST:
                {
                    PSIResponse = Netc_Eth_Ip_VsiToPsi_Disable_Multicast(VSIIndex + 1U);
                    break;
                }
                case NETC_ETH_IP_VSITOPSI_CLOSE_FILTER:
                {
                    Netc_Eth_Ip_VsiToPsi_Close_Filter(VSIIndex + 1U);
                    /* A positive response is expected by current IPW implementation*/
                    PSIResponse = NETC_ETH_IP_PSITOVSI_CMD_SUCCESFUL;
                    break;
                }
                case NETC_ETH_IP_VSITOPSI_GET_SYNC_STATE:
                {
                    PSIResponse = Netc_Eth_Ip_Get_Sync_State();
                    break;
                }
                default:
                {
                    /* Do nothing. */
                    break;
                }
            }
        } /* end of driver intialization check */

#if defined(ERR_IPV_NETC_051247)
    #if (STD_ON == ERR_IPV_NETC_051247)
    } /* data integrity check passed */
    else
    {
        PSIResponse = NETC_ETH_IP_PSITOVSI_MSG_INTEGRITY_ERROR;
    }/* data integrity check failed */
    #endif
#endif

    /* Write the PSI response to MC (Message Code) field and Set the MSn (Message Sent)  bit to the corresponding VSI */
    IP_NETC__ENETC0_SI0->MSGSR.PSI_A.PSIMSGSR = ((uint32)PSIResponse << NETC_ETH_IP_PSI_MSG_POS) | (NETC_ETH_IP_VSI_ENABLE << (VSIIndex + 1U));

    /*  Mark the processing as complete by clearing the MR bit from PSIMSGRR. */
    IP_NETC__ENETC0_SI0->MSGSR.PSI_A.PSIMSGRR = (uint32)((uint32)NETC_ETH_IP_MSG_RCV_COMPLETE << (VSIIndex + 1U));
}


static inline void Netc_Eth_Ip_InitVSIAfterFlr(uint8 VSIIndex)
{
    const Netc_Eth_Ip_GeneralSIConfigType * SIConfig;
    uint8  siHwId;

    /* Check if the driver was intialized.  Req CPR_RTD_00011 is fulfilled.*/
    if (NULL_PTR != Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX])
    {
        /*Get the SI general configuration */
        SIConfig = &(*Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->SIGeneralConfig)[VSIIndex];

        /* Identify the VSI in the list of SIs to configure */
        siHwId =  SIConfig->siId;

        /* Enable/disable MAC multicast/unicast promiscuous mode. */
        IP_NETC__ENETC0_BASE->PSIPMMR = ((uint32)(Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->generalConfig->maskMACPromiscuousMulticastEnable) << NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT) | \
                                        (uint32)(Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->generalConfig->maskMACPromiscuousUnicastEnable);

        if (TRUE == SIConfig->enableSi)
        {
            /** Assure that SI is not enabled. */
            netcSIsBase[siHwId]->SIMR &= ~(NETC_F3_SI0_SIMR_EN_MASK);

            /* Master enable for a station interface.*/
            IP_NETC__ENETC0_BASE->PMR = IP_NETC__ENETC0_BASE->PMR | (NETC_F3_PMR_SI0EN_MASK << siHwId);

            /* For the VSIs write the MAC address in the PSIaMAR0 and PSIaMAR1 registers */
            IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSIPMAR0 = ((uint32)SIConfig->primaryMACAddress[0U])          | \
                                                            (((uint32)SIConfig->primaryMACAddress[1U]) << 8U)  | \
                                                            (((uint32)SIConfig->primaryMACAddress[2U]) << 16U) | \
                                                            (((uint32)SIConfig->primaryMACAddress[3U]) << 24U);

            IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSIPMAR1 = ((uint32)SIConfig->primaryMACAddress[4U]) | \
                                                            (((uint32)SIConfig->primaryMACAddress[5U]) << 8U);

            /* Configure where the PSI receives the message for enabled VSIs. */
    /*                     if(NULL_PTR != config->generalConfig->RxVsiMsgCmdToPsi[siHwId - 1U])
            {
                IP_NETC__ENETC0_SI0->MSGSR.PSI_A.VSI_NUM[siHwId - 1U].PSIVMSGRCVAR0 = (uint32)config->generalConfig->RxVsiMsgCmdToPsi[siHwId - 1U] | \
                                                                                    NETC_ETH_IP_VSITOPSI_MSG_SIZE;
            }
    */

            /* Number of entries in a MSI table for the current SI. */
            IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR2 = NETC_ETH_IP_NUM_OF_ENTRIES_MSITABLE;

            /* Configure the number or TX and RX BD Rings for each SI */
            IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR0 &= ~(NETC_F3_PSICFGR0_NUM_TX_BDR_MASK | NETC_F3_PSICFGR0_NUM_RX_BDR_MASK);

            IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR0 |= NETC_F3_PSICFGR0_NUM_TX_BDR(SIConfig->NumberOfTxBDR) | \
                                                            NETC_F3_PSICFGR0_NUM_RX_BDR(SIConfig->NumberOfRxBDR);

            /* Configure the bandwidth weight for the current SI */
            IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR0 |= NETC_F3_PSICFGR0_SIBW(SIConfig->SIBandwidthWeight);

#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
        if (TRUE == SIConfig->EnableSIVlan)
        {
            /* Enable VLAN and select tag protocol, priority code point, drop eligible indicator and VLAN identifier */
            IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSIVLANR = NETC_F3_PSIVLANR_TPID(SIConfig->SiVLANConfig.ProtocolIdentifier) |
                                                            NETC_F3_PSIVLANR_PCP(SIConfig->SiVLANConfig.PriorityCodePoint) |
                                                            NETC_F3_PSIVLANR_VID(SIConfig->SiVLANConfig.VlanIdentifier) |
                                                            NETC_F3_PSIVLANR_E(1U) | NETC_F3_PSIVLANR_DEI((uint8)SIConfig->SiVLANConfig.DropIndicator);
        }
        else
        {
            /* Disable VLAN and select tag protocol */
            IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSIVLANR &= ~NETC_F3_PSIVLANR_E(1U);
        }
        IP_NETC__ENETC0_BASE->PSIPVMR =(uint32)(Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->generalConfig->maskMACVLANPromiscuousEnable)|
                                               (Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->generalConfig->maskVLANAllowUntaggedEnable) ;

        IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR0 &= ~(NETC_F3_PSICFGR0_SIVC_MASK | NETC_F3_PSICFGR0_SIVIE_MASK | NETC_F3_PSICFGR0_VTE_MASK);
        /* Insert VLAN Ethertype and enable insertion of the SI-based VLAN into frames sent by this SI. This config apply for generic */
        IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR0 |= NETC_F3_PSICFGR0_SIVC(SIConfig->SIVlanControl) |
                                                        NETC_F3_PSICFGR0_SIVIE((uint8)SIConfig->EnableSoftwareVlanInsert) |
                                                        NETC_F3_PSICFGR0_VTE((SIConfig->EnableVLANTagExtract) ? 1U : 0U); ;
#endif

            IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR0 |= NETC_F3_PSICFGR0_ASE((SIConfig->enableAntiSpoofing) ? 1U : 0U);

            /* Enable bus for virtual function. */
            netcVFBase[VSIIndex]->PCI_CFH_CMD |= NETC_VF1_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN(1U);

        }
    }

}


/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/***************************************************************************
 * implements     Netc_Eth_Ip_MSIX_SIMsgEvent_Activity
 ***************************************************************************/
void Netc_Eth_Ip_MSIX_SIMsgEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    uint8 CounterRxMsgFromVsi;
    uint8 RxMsgFromVsiMask;
    uint32 FlrMask;

    /*Check if the Interrupt for PSI is enabled*/
    if ((netcSIsBase[NETC_ETH_IP_PSI_INDEX]->INTERRUPT.PSI.PSIIER & NETC_ETH_IP_PSIIER_MASK) != (uint32)0U)
    {
        /* Status of received messages. */
        RxMsgFromVsiMask = (uint8)(netcSIsBase[NETC_ETH_IP_PSI_INDEX]->INTERRUPT.PSI.PSIIDR & NETC_ETH_IP_PSI_MR_EV_MASK);

        /* Function Level Reset Mask. */
        FlrMask = (uint32)(netcSIsBase[NETC_ETH_IP_PSI_INDEX]->INTERRUPT.PSI.PSIIDR & NETC_ETH_IP_FLR_EV_MASK);

        /* Clear status for messages that will be addressed and for the SI that will be reset at function level. */
        netcSIsBase[NETC_ETH_IP_PSI_INDEX]->INTERRUPT.PSI.PSIIDR = (uint32)RxMsgFromVsiMask | (uint32)FlrMask;
        /*Check if driver is initialized on the current controller */
        if (NULL_PTR != Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX])
        {
            for(CounterRxMsgFromVsi = 0U; CounterRxMsgFromVsi < FEATURE_NETC_ETH_NUM_OF_VIRTUAL_CTRLS; CounterRxMsgFromVsi++)
            {
                if((((uint32)1U << (CounterRxMsgFromVsi + 1U)) & (uint32)RxMsgFromVsiMask) != (uint32)0U)
                {
                    Netc_Eth_Ip_ProcessMsgRcv(CounterRxMsgFromVsi);
                }

                if((((uint32)1U << NETC_ETH_IP_PSI_IDR_FLR(CounterRxMsgFromVsi + 1U)) & (uint32)FlrMask) != (uint32)0U)
                {
                    Netc_Eth_Ip_InitVSIAfterFlr(CounterRxMsgFromVsi + 1U);
                }
            }
        }
    }

    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

void Netc_Eth_Ip_0_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Tx(0U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

void Netc_Eth_Ip_1_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Tx(1U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

void Netc_Eth_Ip_2_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Tx(2U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

void Netc_Eth_Ip_3_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Tx(3U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

void Netc_Eth_Ip_4_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Tx(4U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

void Netc_Eth_Ip_5_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Tx(5U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

void Netc_Eth_Ip_6_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Tx(6U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

void Netc_Eth_Ip_7_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Tx(7U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}


void Netc_Eth_Ip_0_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Rx(0U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

void Netc_Eth_Ip_1_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Rx(1U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

void Netc_Eth_Ip_2_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Rx(2U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

void Netc_Eth_Ip_3_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Rx(3U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

void Netc_Eth_Ip_4_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Rx(4U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

void Netc_Eth_Ip_5_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Rx(5U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

void Netc_Eth_Ip_6_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Rx(6U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

void Netc_Eth_Ip_7_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Rx(7U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

ISR(Netc_Eth_Ip_ErrorReporting)
{
    Netc_Eth_Ip_PCIe_AER_Handler(0u);
}

#ifdef __cplusplus
}
#endif

/** @} */
