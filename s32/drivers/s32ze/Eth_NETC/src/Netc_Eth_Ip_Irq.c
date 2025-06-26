/*
 * Copyright 2021-2025 NXP
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
#define NETC_ETH_IP_IRQ_SW_PATCH_VERSION_C            1

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

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/


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
void Netc_Eth_Ip_MSIX_Rx(uint8 CtrlIndex);

/**
 * @brief Local function used to process PSI Message Receive event
 *
 * @param CmdMacReceivedAddr
 * @param VSIIndex
 */
static inline Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType Netc_Eth_Ip_VsiToPsi_Mac_Addr_Set(const Netc_Eth_Ip_VsiToPsiMsgType* CmdMacReceivedAddr, uint8 VSIIndex);

/**
 * @brief Local function used to process PSI Message Receive event
 *
 * @param CmdMacReceivedAddr
 * @param VSIIndex
 */
static inline Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType Netc_Eth_Ip_VsiToPsi_Add_Rx_Mac_Addr_Hash_Filter(const Netc_Eth_Ip_VsiToPsiMsgType* const CmdMacReceivedAddr, uint8 VSIIndex);

/**
 * @brief Local function used to process PSI Message Receive event
 *
 * @param VSIIndex
 */
static inline Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType Netc_Eth_Ip_VsiToPsi_Delete_All_Rx_Mac_Addr_Hash_Filter(const Netc_Eth_Ip_VsiToPsiMsgType* const CmdMacReceivedAddr, uint8 VSIIndex);

/**
 * @brief Local function used to process PSI Message Receive event
 *
 * @param CmdMacReceivedAddr
 * @param VSIIndex
 */
static inline Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType Netc_Eth_Ip_VsiToPsi_Delete_Single_Rx_Mac_Addr_Hash_Filter(uint8 VSIIndex, uint8 HashValue);

/**
 * @brief Local function used to process PSI Message Receive event
 *
 * @param VSIIndex
 */
static inline Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType Netc_Eth_Ip_VsiToPsi_Enable_Multicast_Promiscuous(uint8 VSIIndex);

/**
 * @brief Local function used to process PSI Message Receive event
 *
 * @param VSIIndex
 */
static inline Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType Netc_Eth_Ip_VsiToPsi_Disable_Multicast_Promiscuous(uint8 VSIIndex);

/**
 * @brief Local function used to process PSI Message Receive event
 *
 * @param VSIIndex
 */
static inline Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType Netc_Eth_Ip_VsiToPsi_Close_Filter(uint8 VSIIndex);

/**
 * @brief Local function used to process PSI Message Receive event
 *
 * @param
 */
static inline Netc_Eth_Ip_GetTimerSyncClassProtocolStatusType Netc_Eth_Ip_Get_Sync_State(void);


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
void Netc_Eth_Ip_MSIX_Rx(uint8 CtrlIndex)
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

static inline Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType Netc_Eth_Ip_VsiToPsi_Mac_Addr_Set(const Netc_Eth_Ip_VsiToPsiMsgType* CmdMacReceivedAddr, uint8 VSIIndex)
{
    const Netc_Eth_Ip_GeneralSIConfigType* SIConfig;
    Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType PSIResponseStatus;
    const uint8 *updatedMac = &CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_SET_PRIMARY_MAC_FIELD_MACADDR0];
    uint8 existentMac[6U];

    /* Check if the MAC address has already been set. */
    existentMac[0U] = (uint8)(IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIPMAR0 & (uint32)0x000000FFU);
    existentMac[1U] = (uint8)((IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIPMAR0 >> 8U) & (uint32)0x000000FFU);
    existentMac[2U] = (uint8)((IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIPMAR0 >> 16U) & (uint32)0x000000FFU);
    existentMac[3U] = (uint8)((IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIPMAR0 >> 24U) & (uint32)0x000000FFU);
    existentMac[4U] = (uint8)(IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIPMAR1 & (uint32)0x000000FFU);
    existentMac[5U] = (uint8)((IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIPMAR1 >> 8U) & (uint32)0x000000FFU);

    if(NETC_MAC_ADDR_MATCH(existentMac,updatedMac) == FALSE)
    {
        /*Get the SI general configuration */
        SIConfig = &(*Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->SIGeneralConfig)[VSIIndex];
        if (SIConfig->changeMACAllowed == TRUE)
        {
            /* For the VSIs write the MAC address in the PSIaMAR0 and PSIaMAR1 registers. */
            IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIPMAR0 = (uint32)(CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_SET_PRIMARY_MAC_FIELD_MACADDR0])              | \
                                                             ((uint32)(CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_SET_PRIMARY_MAC_FIELD_MACADDR0 + 1U]) << 8U ) | \
                                                             ((uint32)(CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_SET_PRIMARY_MAC_FIELD_MACADDR0 + 2U]) << 16U) | \
                                                             ((uint32)(CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_SET_PRIMARY_MAC_FIELD_MACADDR0 + 3U]) << 24U);
            IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIPMAR1 = (uint32)(CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_SET_PRIMARY_MAC_FIELD_MACADDR0 + 4U])         | \
                                                             ((uint32)(CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_SET_PRIMARY_MAC_FIELD_MACADDR0 + 5U]) << 8U);
            PSIResponseStatus = NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_CMD_SUCCESFUL;
        }
        else
        {
            PSIResponseStatus = NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_PERMISION_DENIED;
        }
    }
    else
    {
        /* This MAC address is already being used. */
        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_DUPLICATE_MAC;

    }

    return PSIResponseStatus;
}

static inline Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType Netc_Eth_Ip_VsiToPsi_Add_Rx_Mac_Addr_Hash_Filter(const Netc_Eth_Ip_VsiToPsiMsgType* const CmdMacReceivedAddr, uint8 VSIIndex)
{
    const Netc_Eth_Ip_GeneralSIConfigType* SIConfig;
    Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType PSIResponseStatus;
    uint8 MacAddress[6];
    uint8 HashValue;

    /*Get the SI general configuration */
    SIConfig = &(*Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->SIGeneralConfig)[VSIIndex];
    if (SIConfig->hashFilterUpdateAllowed == TRUE)
    {
        MacAddress[0U] = CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_SET_HASH_TABLE_FIELD_MAC_HASH_FLT_T0_W1 + 1U];
        MacAddress[1U] = CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_SET_HASH_TABLE_FIELD_MAC_HASH_FLT_T0_W1];
        MacAddress[2U] = CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_SET_HASH_TABLE_FIELD_MAC_HASH_FLT_T0_W0 + 3U];
        MacAddress[3U] = CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_SET_HASH_TABLE_FIELD_MAC_HASH_FLT_T0_W0 + 2U];
        MacAddress[4U] = CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_SET_HASH_TABLE_FIELD_MAC_HASH_FLT_T0_W0 + 1U];
        MacAddress[5U] = CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_SET_HASH_TABLE_FIELD_MAC_HASH_FLT_T0_W0];

        HashValue = Netc_Eth_Ip_ComputeMACHashValue(MacAddress);

        /* Multicast MAC hash table */
        /* PSIMMHFR - Port station interface a multicast MAC hash filter register. */
        if ((uint8)0U != (HashValue & NETC_ETH_IP_SELECT_HASH_REGISTER))
        {
            IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIMMHFR1 |= (uint32)((uint32)1U << (HashValue & NETC_ETH_IP_HASH_VALUE));
        }
        else
        {
            IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIMMHFR0 |= (uint32)((uint32)1U << (HashValue & NETC_ETH_IP_HASH_VALUE));
        }
        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_CMD_SUCCESFUL;
    }
    else
    {
        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_PERMISION_DENIED;
    }
    return PSIResponseStatus;
}

static inline Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType Netc_Eth_Ip_VsiToPsi_Delete_All_Rx_Mac_Addr_Hash_Filter(const Netc_Eth_Ip_VsiToPsiMsgType* const CmdMacReceivedAddr, uint8 VSIIndex)
{
    const Netc_Eth_Ip_GeneralSIConfigType* SIConfig;
    Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType PSIResponseStatus = NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_PERMISION_DENIED;

    /*Get the SI general configuration */
    SIConfig = &(*Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->SIGeneralConfig)[VSIIndex];
    if (SIConfig->hashFilterUpdateAllowed == TRUE)
    {
        if(NETC_ETH_IP_VSITOPSI_FLUSH_FIELD_TYPE_ACTION(NETC_ETH_IP_VSITOPSI_FLUSH_MC_ACTION) \
            == CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_FLUSH_FIELD_TYPE])
        {
            IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIMMHFR1 = (uint32)(0x00000000U);
            IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIMMHFR0 = (uint32)(0x00000000U);
            PSIResponseStatus = NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_CMD_SUCCESFUL;
        }
    }

    return PSIResponseStatus;
}

static inline Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType Netc_Eth_Ip_VsiToPsi_Delete_Single_Rx_Mac_Addr_Hash_Filter(uint8 VSIIndex, uint8 HashValue)
{

    const Netc_Eth_Ip_GeneralSIConfigType* SIConfig;
    Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType PSIResponseStatus = NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_PERMISION_DENIED;

    /*Get the SI general configuration */
    SIConfig = &(*Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->SIGeneralConfig)[VSIIndex];
    if (SIConfig->hashFilterUpdateAllowed == TRUE)
    {
        if ((HashValue & NETC_ETH_IP_SELECT_HASH_REGISTER) != (uint8)0U)
        {
            IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIMMHFR1 &= ~(uint32)((uint32)1U << (HashValue & NETC_ETH_IP_HASH_VALUE));
        }
        else
        {
            IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIMMHFR0 &= ~(uint32)((uint32)1U << (HashValue & NETC_ETH_IP_HASH_VALUE));
        }

        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_CMD_SUCCESFUL;
    }

    return PSIResponseStatus;
}

static inline Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType Netc_Eth_Ip_VsiToPsi_Enable_Multicast_Promiscuous(uint8 VSIIndex)
{
    const Netc_Eth_Ip_GeneralSIConfigType* SIConfig;
    Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType PSIResponseStatus;

    /*Get the SI general configuration */
    SIConfig = &(*Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->SIGeneralConfig)[VSIIndex];
    if (SIConfig->multicastPromiscuousChangeAllowed == TRUE)
    {
        /* Enable MAC multicast promiscuous mode. */
        IP_NETC__ENETC0_BASE->PSIPMMR |= ((uint32)((uint32)1U << ((uint8)VSIIndex + NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT)));

        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_CMD_SUCCESFUL;
    }
    else
    {
        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_PERMISION_DENIED;
    }
    return PSIResponseStatus;
}

static inline Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType Netc_Eth_Ip_VsiToPsi_Disable_Multicast_Promiscuous(uint8 VSIIndex)
{
    const Netc_Eth_Ip_GeneralSIConfigType* SIConfig;
    Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType PSIResponseStatus;

    /*Get the SI general configuration */
    SIConfig = &(*Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->SIGeneralConfig)[VSIIndex];
    if (SIConfig->multicastPromiscuousChangeAllowed == TRUE)
    {
        /* Disable MAC multicast promiscuous mode. */
        IP_NETC__ENETC0_BASE->PSIPMMR &= ~((uint32) ((uint32)1U << ((uint8)VSIIndex + NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT)));

        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_CMD_SUCCESFUL;
    }
    else
    {
        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_PERMISION_DENIED;
    }
    return PSIResponseStatus;
}

static inline Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType Netc_Eth_Ip_VsiToPsi_Close_Filter(uint8 VSIIndex)
{
    Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType PSIResponseStatus = NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_PERMISION_DENIED;
    const Netc_Eth_Ip_GeneralSIConfigType* SIConfig;
    /*Get the SI general configuration */
    SIConfig = &(*Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX]->SIGeneralConfig)[VSIIndex];
    if (SIConfig->multicastPromiscuousChangeAllowed == TRUE)
    {
        /* Disable MAC multicast promiscuous mode. */
        IP_NETC__ENETC0_BASE->PSIPMMR &= ~((uint32)((uint32)1U << ((uint8)VSIIndex + NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT)));
        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_CMD_SUCCESFUL;
    }

    if (SIConfig->hashFilterUpdateAllowed == TRUE)
    {
        /* Clear all entries in filter. */
        IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIMMHFR1 = (uint32)0x0U;
        IP_NETC__ENETC0_BASE->NUM_SI[VSIIndex].PSIMMHFR0 = (uint32)0x0U;
        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_CMD_SUCCESFUL;
    }

    return PSIResponseStatus;
}

static inline Netc_Eth_Ip_GetTimerSyncClassProtocolStatusType Netc_Eth_Ip_Get_Sync_State(void)
{
    Netc_Eth_Ip_GetTimerSyncClassProtocolStatusType PSIResponseStatus = NETC_ETH_IP_PSITOVSI_PROTOCOL_TIMER_SYNC_STATUS_NOT_SYNCHRONIZED;

    if ((IP_NETC__ENETC0_SI0->SITSR & NETC_F3_SI0_SITSR_SYNC_MASK) != 0U)
    {
        PSIResponseStatus = NETC_ETH_IP_PSITOVSI_PROTOCOL_TIMER_SYNC_STATUS_SYNCHRONIZED;
    }
    else
    {
        /* Timer sync status = Not synchronized. */
    }

    return PSIResponseStatus;
}

static inline void Netc_Eth_Ip_ProcessMsgRcv(uint8 VSIIndex)
{
    const Netc_Eth_Ip_VsiToPsiMsgType *CmdMacReceivedAddr;
    Netc_Eth_Ip_VsiToPsiMsgActionType CommandType;
    uint8 CommandResponse = (uint8)NETC_ETH_IP_PSITOVSI_PROTOCOL_PERMISSION_DENIED;
    Netc_Eth_Ip_StatusType Status;
    uint16 PSIResponse = NETC_ETH_IP_PSITOVSI_REPLY_SET_RETURN_CODE(CommandResponse);
    const uint8 *MacAddr_msg;
    uint8 MacAddr[6];
    uint8 HashValue;

    CmdMacReceivedAddr =(Netc_Eth_Ip_VsiToPsiMsgType *)(netcSIsBase[NETC_ETH_IP_PSI_INDEX]->MSGSR.PSI_A.VSI_NUM[VSIIndex].PSIVMSGRCVAR0 & \
                        NETC_F3_SI0_PSIVMSGRCVAR0_ADDRL_MASK);

#if defined(ERR_IPV_NETC_051247)
    #if (STD_ON == ERR_IPV_NETC_051247)
    /* Verify data integrity for the received msg. Number of VSI written bytes is unknown here, the CRC must be calculated on the whole msg buffer, minus the transmitted CRC byte*/
    if(Netc_Eth_Ip_VsiMsgCalculateCRC16(CmdMacReceivedAddr, (uint8)sizeof(Netc_Eth_Ip_VsiToPsiMsgType) * (uint8)NETC_ETH_IP_VSITOPSI_MSG_SIZE) == CmdMacReceivedAddr->CRC16)
    {
    #endif
#endif
        CommandType = (Netc_Eth_Ip_VsiToPsiMsgActionType)((uint16)((((uint16)CmdMacReceivedAddr->Class << 8U) & (uint16)0xFF00U) | ((uint16)CmdMacReceivedAddr->Command & (uint16)0x00FFU)));

        /*Get the SI general configuration */
        switch(CommandType)
        {
            case NETC_ETH_IP_VSITOPSI_MAC_ADDR_SET:
            {
                CommandResponse = (uint8)Netc_Eth_Ip_VsiToPsi_Mac_Addr_Set(CmdMacReceivedAddr, (VSIIndex + 1U));
                PSIResponse = NETC_ETH_IP_PSITOVSI_REPLY_SET_RETURN_CODE(NETC_ETH_IP_VSITOPSI_MAC_ADDR_FILTERING_CLASS_CODE);
                break;
            }
            case NETC_ETH_IP_VSITOPSI_ADD_RX_MAC_ADDR_HASH_FILTER:
            {
                /* Reverse the MacAddr_W0 back to Big Endian order of bytes. */
                MacAddr_msg = &CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_SET_HASH_TABLE_FIELD_MAC_HASH_FLT_T0_W0];
                MacAddr[0U] = MacAddr_msg[5U];
                MacAddr[1U] = MacAddr_msg[4U];
                MacAddr[2U] = MacAddr_msg[3U];
                MacAddr[3U] = MacAddr_msg[2U];
                MacAddr[4U] = MacAddr_msg[1U];
                MacAddr[5U] = MacAddr_msg[0U];

                HashValue = Netc_Eth_Ip_ComputeMACHashValue(MacAddr);
                Status = Netc_Eth_Ip_AddMACHashFilterEntry((VSIIndex + 1U), HashValue, MacAddr);
                if(Status == NETC_ETH_IP_STATUS_SUCCESS) /* If it was successfuly added, use generic statuses. */
                {
                    CommandResponse = (uint8)Netc_Eth_Ip_VsiToPsi_Add_Rx_Mac_Addr_Hash_Filter(CmdMacReceivedAddr, (VSIIndex + 1U));
                }
                else if (Status == NETC_ETH_IP_PSITOVSI_PERMISSION_DENIED)
                {
                    CommandResponse = (uint8)NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_DUPLICATE_MAC;
                }
                else
                {
                    CommandResponse = (uint8)NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_PERMISION_DENIED;
                }

                PSIResponse = NETC_ETH_IP_PSITOVSI_REPLY_SET_RETURN_CODE(NETC_ETH_IP_VSITOPSI_MAC_ADDR_FILTERING_CLASS_CODE);

                break;
            }
            case NETC_ETH_IP_VSITOPSI_DELETE_ALL_RX_MAC_ADDR_HASH_FILTER:
            {
                /* 2nd and 3rd parameters won't matter because every existent Hash value will be deleted for a specific VSI */
                Status = Netc_Eth_Ip_DeleteMACHashFilterEntry((VSIIndex + 1U), 0U, NULL_PTR, TRUE);
                if((Status == NETC_ETH_IP_STATUS_DELETE_MAC_ADDR) || (Status == NETC_ETH_IP_STATUS_SUCCESS))
                {
                    CommandResponse = (uint8)Netc_Eth_Ip_VsiToPsi_Delete_All_Rx_Mac_Addr_Hash_Filter(CmdMacReceivedAddr, (VSIIndex + 1U));
                    PSIResponse = NETC_ETH_IP_PSITOVSI_REPLY_SET_RETURN_CODE(NETC_ETH_IP_VSITOPSI_MAC_ADDR_FILTERING_CLASS_CODE);
                }
                else
                {
                    CommandResponse = (uint8)NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_MAC_ADDR_NOT_FOUND;
                }

                break;
            }
            case NETC_ETH_IP_VSITOPSI_DELETE_SINGLE_RX_MAC_ADDR_HASH_FILTER:
            {
                MacAddr_msg = &CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_DELETE_SINGLE_FIELD_MACADDR];
                MacAddr[0U] = MacAddr_msg[0U];
                MacAddr[1U] = MacAddr_msg[1U];
                MacAddr[2U] = MacAddr_msg[2U];
                MacAddr[3U] = MacAddr_msg[3U];
                MacAddr[4U] = MacAddr_msg[4U];
                MacAddr[5U] = MacAddr_msg[5U];
                HashValue = Netc_Eth_Ip_ComputeMACHashValue(MacAddr);
                Status = Netc_Eth_Ip_DeleteMACHashFilterEntry((VSIIndex + 1U), HashValue, MacAddr, FALSE);
                if((Status == NETC_ETH_IP_STATUS_DELETE_MAC_ADDR) || (Status == NETC_ETH_IP_STATUS_SUCCESS))
                {
                    CommandResponse = (uint8)Netc_Eth_Ip_VsiToPsi_Delete_Single_Rx_Mac_Addr_Hash_Filter((VSIIndex + 1U), HashValue);
                    PSIResponse = NETC_ETH_IP_PSITOVSI_REPLY_SET_RETURN_CODE(NETC_ETH_IP_VSITOPSI_MAC_ADDR_FILTERING_CLASS_CODE);
                }
                else
                {
                    CommandResponse = (uint8)NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_MAC_ADDR_NOT_FOUND;
                }
                break;
            }
            case NETC_ETH_IP_VSITOPSI_MULTICAST_ACTIONS:
            {
                switch(CmdMacReceivedAddr->Data[NETC_ETH_IP_VSITOPSI_PROMISCUOUS_FIELD_TYPE_AND_OP])
                {
                    case (uint8)NETC_ETH_IP_VSITOPSI_ENABLE_MULTICAST_PROMISCUOS:
                    {
                        CommandResponse = (uint8)Netc_Eth_Ip_VsiToPsi_Enable_Multicast_Promiscuous(VSIIndex + 1U);
                        PSIResponse = NETC_ETH_IP_PSITOVSI_REPLY_SET_RETURN_CODE(NETC_ETH_IP_VSITOPSI_MAC_ADDR_FILTERING_CLASS_CODE);
                        break;
                    }
                    case (uint8)NETC_ETH_IP_VSITOPSI_DISABLE_MULTICAST_PROMISCUOUS:
                    {
                        CommandResponse = (uint8)Netc_Eth_Ip_VsiToPsi_Disable_Multicast_Promiscuous(VSIIndex + 1U);
                        PSIResponse = NETC_ETH_IP_PSITOVSI_REPLY_SET_RETURN_CODE(NETC_ETH_IP_VSITOPSI_MAC_ADDR_FILTERING_CLASS_CODE);
                        break;
                    }
                    case (uint8)NETC_ETH_IP_VSITOPSI_CLOSE_FILTER:
                    {
                        (void)Netc_Eth_Ip_DeleteMACHashFilterEntry((VSIIndex + 1U), 0U, NULL_PTR, TRUE);
                        /* A positive response is expected by current IPW implementation*/
                        CommandResponse = (uint8)Netc_Eth_Ip_VsiToPsi_Close_Filter(VSIIndex + 1U);
                        PSIResponse = NETC_ETH_IP_PSITOVSI_REPLY_SET_RETURN_CODE(NETC_ETH_IP_VSITOPSI_MAC_ADDR_FILTERING_CLASS_CODE);
                        break;
                    }
                    default:
                    {
                        /* Do nothing. */
                        break;
                    }
                }
                break;
            }
            case NETC_ETH_IP_VSITOPSI_GET_TIMER_SYNC_STATE:
            {
                CommandResponse = (uint8)Netc_Eth_Ip_Get_Sync_State();
                PSIResponse = NETC_ETH_IP_PSITOVSI_REPLY_SET_RETURN_CODE(NETC_ETH_IP_VSITOPSI_GET_TIMER_SYNC_STATUS_CLASS_CODE);
                break;
            }
            default:
            {
                /* Do nothing. */
                break;
            }
        }

        /* Allign the statuses with linux protocol. */
        /* Command generic response */
        if(CommandResponse == (uint8)NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_CMD_SUCCESFUL)
        {
            PSIResponse = NETC_ETH_IP_PSITOVSI_REPLY_SET_CLASS_CODE(0x0U)                                        |
                          NETC_ETH_IP_PSITOVSI_REPLY_SET_RETURN_CODE(NETC_ETH_IP_PSITOVSI_PROTOCOL_CMD_SUCCESFUL);
            /* Cookie is allways 1 due to all operations being asynchronously executed. */
            PSIResponse |= NETC_ETH_IP_PSITOVSI_REPLY_SET_COOKIE(CmdMacReceivedAddr->Cookie);
        }
        else if(CommandResponse == (uint8)NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_PERMISION_DENIED)
        {
            PSIResponse = NETC_ETH_IP_PSITOVSI_REPLY_SET_CLASS_CODE(0x0U)                                            |
                          NETC_ETH_IP_PSITOVSI_REPLY_SET_RETURN_CODE(NETC_ETH_IP_PSITOVSI_PROTOCOL_PERMISSION_DENIED);
            /* Cookie is allways 1 due to all operations being asynchronously executed. */
            PSIResponse |= NETC_ETH_IP_PSITOVSI_REPLY_SET_COOKIE(CmdMacReceivedAddr->Cookie);
        }
        else if(NETC_ETH_IP_PSITOVSI_REPLY_GET_RETURN_CODE(PSIResponse) == NETC_ETH_IP_VSITOPSI_GET_TIMER_SYNC_STATUS_CLASS_CODE)
        {
            /* In this case the least significant bit of the message will represent the status of the VSIn's timer based
               on the value from SITSR register, which can be provided only by the PSI. */
            PSIResponse |= CommandResponse;
        }
        else /* If the response is not a generic one, then use the already set RETURN_CODE, then just apply the specific class operation code. */
        {
            PSIResponse |= NETC_ETH_IP_PSITOVSI_REPLY_SET_CLASS_CODE(CommandResponse);
            /* Cookie is allways 1 due to all operations being asynchronously executed. */
            PSIResponse |= NETC_ETH_IP_PSITOVSI_REPLY_SET_COOKIE(CmdMacReceivedAddr->Cookie);
        }

#if defined(ERR_IPV_NETC_051247)
    #if (STD_ON == ERR_IPV_NETC_051247)
    } /* data integrity check passed */
    else
    {
        PSIResponse = (uint16)NETC_ETH_IP_PSITOVSI_MSG_INTEGRITY_ERROR;
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
            IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR0 |= NETC_F3_PSICFGR0_SPE((SIConfig->enableSIPruning) ? 1U : 0U);

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

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_0_MSIX_TxEvent
 * Description   :Function used for the TX interrupt from SI 0.
 *
 *END**************************************************************************/
void Netc_Eth_Ip_0_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Tx(0U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_1_MSIX_TxEvent
 * Description   :Function used for the TX interrupt from SI 1.
 *
 *END**************************************************************************/
void Netc_Eth_Ip_1_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Tx(1U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_2_MSIX_TxEvent
 * Description   :Function used for the TX interrupt from SI 2.
 *
 *END**************************************************************************/
void Netc_Eth_Ip_2_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Tx(2U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_3_MSIX_TxEvent
 * Description   :Function used for the TX interrupt from SI 3.
 *
 *END**************************************************************************/
void Netc_Eth_Ip_3_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Tx(3U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_4_MSIX_TxEvent
 * Description   :Function used for the TX interrupt from SI 4.
 *
 *END**************************************************************************/
void Netc_Eth_Ip_4_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Tx(4U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_5_MSIX_TxEvent
 * Description   :Function used for the TX interrupt from SI 5.
 *
 *END**************************************************************************/
void Netc_Eth_Ip_5_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Tx(5U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_6_MSIX_TxEvent
 * Description   :Function used for the TX interrupt from SI 6.
 *
 *END**************************************************************************/
void Netc_Eth_Ip_6_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Tx(6U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_7_MSIX_TxEvent
 * Description   :Function used for the TX interrupt from SI 7.
 *
 *END**************************************************************************/
void Netc_Eth_Ip_7_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Tx(7U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_0_MSIX_RxEvent
 * Description   :Function used for the RX interrupt from SI 0.
 *
 *END**************************************************************************/
void Netc_Eth_Ip_0_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Rx(0U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_1_MSIX_RxEvent
 * Description   :Function used for the RX interrupt from SI 1.
 *
 *END**************************************************************************/
void Netc_Eth_Ip_1_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Rx(1U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_2_MSIX_RxEvent
 * Description   :Function used for the RX interrupt from SI 2.
 *
 *END**************************************************************************/
void Netc_Eth_Ip_2_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Rx(2U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_3_MSIX_RxEvent
 * Description   :Function used for the RX interrupt from SI 3.
 *
 *END**************************************************************************/
void Netc_Eth_Ip_3_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Rx(3U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_4_MSIX_RxEvent
 * Description   :Function used for the RX interrupt from SI 4.
 *
 *END**************************************************************************/
void Netc_Eth_Ip_4_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Rx(4U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_5_MSIX_RxEvent
 * Description   :Function used for the RX interrupt from SI 5.
 *
 *END**************************************************************************/
void Netc_Eth_Ip_5_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Rx(5U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_6_MSIX_RxEvent
 * Description   :Function used for the RX interrupt from SI 6.
 *
 *END**************************************************************************/
void Netc_Eth_Ip_6_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Rx(6U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_7_MSIX_RxEvent
 * Description   :Function used for the RX interrupt from SI 7.
 *
 *END**************************************************************************/
void Netc_Eth_Ip_7_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    Netc_Eth_Ip_MSIX_Rx(7U);
    (void)RxChannelId;
    (void)RxBuffer;
    (void)BufferSize;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_ErrorReporting
 * Description   : Function used for the Error Reporting
 *
 *END**************************************************************************/
ISR(Netc_Eth_Ip_ErrorReporting)
{
    Netc_Eth_Ip_PCIe_AER_Handler(0u);
}

#ifdef __cplusplus
}
#endif

/** @} */
