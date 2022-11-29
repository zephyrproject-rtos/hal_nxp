/*
 * Copyright 2021-2022 NXP
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
#define NETC_ETH_IP_IRQ_SW_MAJOR_VERSION_C            0
#define NETC_ETH_IP_IRQ_SW_MINOR_VERSION_C            9
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

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
/* Pointers to NETC internal driver state for each Instance. */
extern Netc_Eth_Ip_StateType *Netc_Eth_Ip_apxState[FEATURE_NETC_ETH_NUMBER_OF_CTRLS];

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
 * @param CtrlIndex 
 */
static inline void Netc_Eth_Ip_MSIX_Rx(uint8 CtrlIndex);

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

static inline void Netc_Eth_Ip_MSIX_Tx(uint8 CtrlIndex)
{
    uint8  RingIndex;
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

        if (NULL_PTR != Netc_Eth_Ip_apxState[CtrlIndex])
        {
            for(RingIndex = 0U; RingIndex < Netc_Eth_Ip_apxState[CtrlIndex]->NumberOfTxBDR; RingIndex++)
            {
                /** TODO: Update this callback for both layers. */
                if ((1U == (TxRingIntStatus >> RingIndex)) && (NULL_PTR != Netc_Eth_Ip_apxState[CtrlIndex]->TxCallback[RingIndex]))
                {
                    Netc_Eth_Ip_apxState[CtrlIndex]->TxCallback[RingIndex](Netc_Eth_Ip_apxState[CtrlIndex]->CtrlLogicalIndex, RingIndex);
                }
            }
        }
    }
    else if(NETC_ETH_IP_TBIER_TXTIE_MASK == (netcSIsBase[CtrlIndex]->BDR_NUM[0U].TBIER & NETC_ETH_IP_TBIER_TXTIE_MASK))
    {
        /* Clear TX interrupt flag for all SIs. */
        netcSIsBase[CtrlIndex]->SITXIDR0 = TxRingIntStatus;
        /* Keep only coalescing interrupt status. */
        TxRingIntStatus &= 0x0000FFFFUL;

        if (NULL_PTR != Netc_Eth_Ip_apxState[CtrlIndex])
        {
            for(RingIndex = 0U; RingIndex < Netc_Eth_Ip_apxState[CtrlIndex]->NumberOfTxBDR; RingIndex++)
            {
                /** TODO: Update this callback for both layers. */
                if ((1U == (TxRingIntStatus >> RingIndex)) && (NULL_PTR != Netc_Eth_Ip_apxState[CtrlIndex]->TxCallback[RingIndex]))
                {
                    Netc_Eth_Ip_apxState[CtrlIndex]->TxCallback[RingIndex](Netc_Eth_Ip_apxState[CtrlIndex]->CtrlLogicalIndex, RingIndex);
                }
            }
        }
    }
    else
    {
        /*  MISRA C-2012 Rule 15.7 */
    }
       
}

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

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
void Netc_Eth_Ip_MSIX_SIMsgEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize)
{
    uint8 CounterRxMsgFromVsi;
    uint8 RxMsgFromVsiMask;
    uint8 HashValue;
    const Netc_Eth_Ip_VsiToPsiMsgType *CmdMacReceivedAddr;
    Netc_Eth_Ip_VsiToPsiMsgActionType CommandType;

    /*Check if the Interrupt for PSI is enabled*/
    if ((netcSIsBase[NETC_ETH_IP_PSI_INDEX]->INTERRUPT.PSI.PSIIER & 0xFEU) != (uint32)0U)
    {
        /* Status of received messages. */
        RxMsgFromVsiMask = (uint8)(netcSIsBase[NETC_ETH_IP_PSI_INDEX]->INTERRUPT.PSI.PSIIDR & 0xFEU);
        /* Clear status for messages that will be addressed. */
        netcSIsBase[NETC_ETH_IP_PSI_INDEX]->INTERRUPT.PSI.PSIIDR = (uint32)RxMsgFromVsiMask;
        /*Check if driver is initialized on the current controller */
        if (NULL_PTR != Netc_Eth_Ip_apxState[NETC_ETH_IP_PSI_INDEX])
        {
            for(CounterRxMsgFromVsi = 1U; CounterRxMsgFromVsi < FEATURE_NETC_ETH_NUMBER_OF_CTRLS; CounterRxMsgFromVsi++)
            {
                if(((1U << CounterRxMsgFromVsi) & (uint32)RxMsgFromVsiMask) != (uint32)0U)
                {
                    CmdMacReceivedAddr =(const Netc_Eth_Ip_VsiToPsiMsgType *)(netcSIsBase[NETC_ETH_IP_PSI_INDEX]->MSGSR.PSI_A.VSI_NUM[CounterRxMsgFromVsi - 1U].PSIVMSGRCVAR0 & \
                                        NETC_F3_SI0_PSIVMSGRCVAR0_ADDRL_MASK);
                    CommandType = (Netc_Eth_Ip_VsiToPsiMsgActionType)((uint16)((uint32)CmdMacReceivedAddr->Class << 8U) + ((uint32)CmdMacReceivedAddr->Command));

                    switch(CommandType)
                    {
                        case NETC_ETH_IP_VSITOPSI_MAC_ADDR_SET:
                        {
                            /* For the VSIs write the MAC address in the PSIaMAR0 and PSIaMAR1 registers. */
                            IP_NETC__ENETC0_BASE->NUM_SI[CounterRxMsgFromVsi].PSIPMAR0 =  CmdMacReceivedAddr->Data[2U]         | \
                                                                                        (CmdMacReceivedAddr->Data[3U] << 8U ) | \
                                                                                        (CmdMacReceivedAddr->Data[4U] << 16U) | \
                                                                                        (CmdMacReceivedAddr->Data[5U] << 24U);
                            IP_NETC__ENETC0_BASE->NUM_SI[CounterRxMsgFromVsi].PSIPMAR1 =  CmdMacReceivedAddr->Data[6U]         | \
                                                                                        (CmdMacReceivedAddr->Data[7U] << 8U);
                            break;
                        }
                        case NETC_ETH_IP_VSITOPSI_ADD_RX_MAC_ADDR_FILTER:
                        {
                            HashValue = CmdMacReceivedAddr->Data[0U];
                            if((HashValue & NETC_ETH_IP_SELECT_HASH_REGISTER) != (uint8)0U)
                            {
                                IP_NETC__ENETC0_BASE->NUM_SI[CounterRxMsgFromVsi].PSIMMHFR1 |= (uint32)((uint32)1U << (HashValue & NETC_ETH_IP_HASH_VALUE));
                            }
                            else
                            {
                                IP_NETC__ENETC0_BASE->NUM_SI[CounterRxMsgFromVsi].PSIMMHFR0 |= (uint32)((uint32)1U << (HashValue & NETC_ETH_IP_HASH_VALUE));
                            }
                            break;
                        }
                        case NETC_ETH_IP_VSITOPSI_DELETE_RX_MAC_ADDR_FILTER:
                        {
                            HashValue = CmdMacReceivedAddr->Data[0U];
                            if((HashValue & NETC_ETH_IP_SELECT_HASH_REGISTER) != (uint8)0U)
                            {
                                IP_NETC__ENETC0_BASE->NUM_SI[CounterRxMsgFromVsi].PSIMMHFR1 &= ~(uint32)((uint32)1U << (HashValue & NETC_ETH_IP_HASH_VALUE));
                            }
                            else
                            {
                                IP_NETC__ENETC0_BASE->NUM_SI[CounterRxMsgFromVsi].PSIMMHFR0 &= ~(uint32)((uint32)1U << (HashValue & NETC_ETH_IP_HASH_VALUE));
                            }
                            break;
                        }
                        case NETC_ETH_IP_VSITOPSI_ENABLE_MULTICAST:
                        {
                            /* Enable MAC multicast promiscuous mode. */
                            IP_NETC__ENETC0_BASE->PSIPMMR |= ((uint32)((uint32)1U << ((uint8)CounterRxMsgFromVsi + NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT)));
                            break;
                        }
                        case NETC_ETH_IP_VSITOPSI_DISABLE_MULTICAST:
                        {
                            /* Disable MAC multicast promiscuous mode. */
                            IP_NETC__ENETC0_BASE->PSIPMMR &= ~((uint32) ((uint32)1U << ((uint8)CounterRxMsgFromVsi + NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT)));
                            break;
                        }
                        case NETC_ETH_IP_VSITOPSI_CLOSE_FILTER:
                        {
                            /* Disable MAC multicast promiscuous mode. */
                            IP_NETC__ENETC0_BASE->PSIPMMR &= ~((uint32)((uint32)1U << ((uint8)CounterRxMsgFromVsi + NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT)));
                            /* Clear all entries in filter. */
                            IP_NETC__ENETC0_BASE->NUM_SI[CounterRxMsgFromVsi].PSIMMHFR1 = (uint32)0x0U;
                            IP_NETC__ENETC0_BASE->NUM_SI[CounterRxMsgFromVsi].PSIMMHFR0 = (uint32)0x0U;
                            break;
                        }
                        default:
                        {
                            /* Do nothing. */
                            break;
                        }
                    }
                    /*  Mark the processing as complete by clearing the MR bit from PSIMSGRR. */
                    IP_NETC__ENETC0_SI0->MSGSR.PSI_A.PSIMSGRR = (uint32)((uint32)1U << CounterRxMsgFromVsi);
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

#ifdef __cplusplus
}
#endif

/** @} */
