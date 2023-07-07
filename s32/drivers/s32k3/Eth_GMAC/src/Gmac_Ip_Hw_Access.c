/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file
*
*   @addtogroup GMAC_DRIVER GMAC Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gmac_Ip_Hw_Access.h"
#include "OsIf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GMAC_IP_HW_ACCESS_VENDOR_ID_C                      43
#define GMAC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C       4
#define GMAC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C       7
#define GMAC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C    0
#define GMAC_IP_HW_ACCESS_SW_MAJOR_VERSION_C               3
#define GMAC_IP_HW_ACCESS_SW_MINOR_VERSION_C               0
#define GMAC_IP_HW_ACCESS_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Gmac_Ip_Hw_Access.h */
#if (GMAC_IP_HW_ACCESS_VENDOR_ID_C != GMAC_IP_HW_ACCESS_VENDOR_ID)
    #error "Gmac_Ip_Hw_Access.c and Gmac_Ip_Hw_Access.h have different vendor ids"
#endif
#if ((GMAC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C    != GMAC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (GMAC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C    != GMAC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (GMAC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C != GMAC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gmac_Ip_Hw_Access.c and Gmac_Ip_Hw_Access.h are different"
#endif
#if ((GMAC_IP_HW_ACCESS_SW_MAJOR_VERSION_C != GMAC_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (GMAC_IP_HW_ACCESS_SW_MINOR_VERSION_C != GMAC_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (GMAC_IP_HW_ACCESS_SW_PATCH_VERSION_C != GMAC_IP_HW_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gmac_Ip_Hw_Access.c and Gmac_Ip_Hw_Access.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against OsIf.h */
    #if (( GMAC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        ( GMAC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C    != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Gmac_Ip_Hw_Access.c and OsIf.h are different"
    #endif
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define GMAC_CRC32_BITS_31_28_MASK     (0xF0000000U)
#define GMAC_CRC32_BITS_31_28_SHIFT    28U

#define GMAC_HASH_TABLE_REG_MASK       0xE0U
#define GMAC_HASH_TABLE_BIT_MASK       0x1FU
#define GMAC_HASH_TABLE_GET_REG_SHIFT  5U

#define GMAC_HASH_TABLE_REG_IDX(revCrc32)   ((((uint32)(revCrc32) >> FEATURE_GMAC_HASH_TABLE_MSB_SHIFT) & (((uint32)FEATURE_GMAC_HASH_TABLE_SZ - 1U) & GMAC_HASH_TABLE_REG_MASK)) >> GMAC_HASH_TABLE_GET_REG_SHIFT)
#define GMAC_HASH_TABLE_BIT_IDX(revCrc32)   (((uint32)(revCrc32) >> FEATURE_GMAC_HASH_TABLE_MSB_SHIFT) & (((uint32)FEATURE_GMAC_HASH_TABLE_SZ - 1U) & GMAC_HASH_TABLE_BIT_MASK))

#define GMAC_RX_INTERRUPTS    (GMAC_DMA_CH0_STATUS_REB_MASK | GMAC_DMA_CH0_STATUS_ERI_MASK | GMAC_DMA_CH0_STATUS_RWT_MASK | GMAC_DMA_CH0_STATUS_RPS_MASK \
        | GMAC_DMA_CH0_STATUS_RBU_MASK | GMAC_DMA_CH0_STATUS_RI_MASK)
#define GMAC_TX_INTERRUPTS    (GMAC_DMA_CH0_STATUS_TEB_MASK | GMAC_DMA_CH0_STATUS_ETI_MASK | GMAC_DMA_CH0_STATUS_TBU_MASK | GMAC_DMA_CH0_STATUS_TPS_MASK \
        | GMAC_DMA_CH0_STATUS_TI_MASK)

#define FEATURE_GMAC_HASH_TABLE_DIM              (FEATURE_GMAC_HASH_TABLE_SZ / 32U)

/*******************************************************************************
 * Variables
 ******************************************************************************/
#define ETH_43_GMAC_START_SEC_CONST_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"


GMAC_Type * const Gmac_apxBases[FEATURE_GMAC_NUM_INSTANCES] = IP_GMAC_BASE_PTRS;

Gmac_Ip_ChannelType * const Gmac_apxChBases[FEATURE_GMAC_NUM_INSTANCES][FEATURE_GMAC_NUM_CHANNELS] = DEV_REG_GMAC_CH_BASE;

Gmac_Ip_QueueType * const Gmac_apxQueueBases[FEATURE_GMAC_NUM_INSTANCES][FEATURE_GMAC_NUM_QUEUES] = DEV_REG_GMAC_QUEUE_BASE;


#define ETH_43_GMAC_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

/*******************************************************************************
 * Private Functions
 ******************************************************************************/
#define ETH_43_GMAC_START_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : REV_BITS_32
 * Description   : Performs bitwise reversal on a 32 bit value.
 *
 *END**************************************************************************/
static inline uint32 REV_BITS_32(uint32 value)
{
    uint32 v;

    v = value;
    v = (((v & (0xAAAAAAAAU)) >> 1U) | ((v & (0x55555555U)) << 1U));
    v = (((v & (0xCCCCCCCCU)) >> 2U) | ((v & (0x33333333U)) << 2U));
    v = (((v & (0xF0F0F0F0U)) >> 4U) | ((v & (0x0F0F0F0FU)) << 4U));
    v = (((v & (0xFF00FF00U)) >> 8U) | ((v & (0x00FF00FFU)) << 8U));
    return ((v >> 16U) | (v << 16U));
}

#if (FEATURE_GMAC_ASP_ALL || FEATURE_GMAC_ASP_ECC)
static void GMAC_IrqFSMHandler( \
                                const uint8 Instance, \
                                uint32 ErrorStatusFlags, \
                                uint32 ErrorEnFlags \
                             );
static void GMAC_IrqFSMDPPHandler( \
                                const uint8 Instance, \
                                uint32 ErrorStatusFlags, \
                                uint32 ErrorEnFlags \
                             );
static void GMAC_IrqECCHandler( \
                                const uint8 Instance, \
                                uint32 ErrorStatusFlags, \
                                uint32 ErrorEnFlags \
                             );

#define GMAC_ECC_CTL_MASK           (GMAC_MTL_ECC_CONTROL_MTXEE_MASK | \
                                     GMAC_MTL_ECC_CONTROL_MRXEE_MASK | \
                                     GMAC_MTL_ECC_CONTROL_MESTEE_MASK)

#define GMAC_ECC_STS_MASK           (GMAC_MTL_ECC_INTERRUPT_STATUS_EUES_MASK  | GMAC_MTL_ECC_INTERRUPT_STATUS_EAMS_MASK  | \
                                     GMAC_MTL_ECC_INTERRUPT_STATUS_RXUES_MASK | GMAC_MTL_ECC_INTERRUPT_STATUS_RXAMS_MASK | \
                                     GMAC_MTL_ECC_INTERRUPT_STATUS_TXUES_MASK | GMAC_MTL_ECC_INTERRUPT_STATUS_TXAMS_MASK)


#define GMAC_CSR_TIMEOUT_CTL_MASK   (GMAC_MAC_FSM_CONTROL_TMOUTEN_MASK)

#define GMAC_CSR_TIMEOUT_STS_MASK   (GMAC_SAF_ERR_MASTER_INTERFACE_TIMEOUT)


#define GMAC_FSM_TIMEOUT_CTL_MASK   (GMAC_MAC_FSM_CONTROL_TMOUTEN_MASK)

#define GMAC_FSM_TIMEOUT_STS_MASK   (GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_PTES_MASK |  \
                                     GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ATES_MASK |  \
                                     GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RTES_MASK |  \
                                     GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_TTES_MASK)


#define GMAC_FSM_SPP_CTL_MASK       (GMAC_MAC_FSM_CONTROL_PRTYEN_MASK)

#define GMAC_FSM_SPP_STS_MASK       (GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES_MASK)


#define GMAC_DPP_CTL_MASK           (GMAC_MTL_DPP_CONTROL_EDPP_MASK)

#define GMAC_DPP_STS_MASK           (GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES_MASK  | \
                                     GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES_MASK | \
                                     GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MPES_MASK   | \
                                     GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES_MASK)
#if FEATURE_GMAC_ASP_ALL
static void GMAC_IrqFSMHandler( \
                                const uint8 Instance, \
                                uint32 ErrorStatusFlags, \
                                uint32 ErrorEnFlags \
                             )
{
    if (((ErrorStatusFlags & GMAC_FSM_SPP_STS_MASK) != 0U) && ((ErrorEnFlags & GMAC_FSM_SPP_CTL_MASK) != 0U))
    {
        Gmac_apxState[Instance]->SafetyCallback(Instance, GMAC_SAF_ERR_FSM_STATE_PARITY);
    }
    else if (((ErrorStatusFlags & GMAC_FSM_TIMEOUT_STS_MASK) != 0U) && ((ErrorEnFlags & GMAC_FSM_TIMEOUT_CTL_MASK) != 0U))
    {
        Gmac_apxState[Instance]->SafetyCallback(Instance, GMAC_SAF_ERR_FSM_TIMEOUT);
    }
    else if (((ErrorStatusFlags & (uint32)GMAC_CSR_TIMEOUT_STS_MASK) != 0U) && ((ErrorEnFlags & GMAC_CSR_TIMEOUT_CTL_MASK) != 0U))
    {
        Gmac_apxState[Instance]->SafetyCallback(Instance, GMAC_SAF_ERR_MASTER_INTERFACE_TIMEOUT);
    }
    else if (ErrorStatusFlags == 0U)
    {
        Gmac_apxState[Instance]->SafetyCallback(Instance, GMAC_SAF_ERR_CSR_EMPTY_DATA);
    }
    else
    {
        /* Do nothing */
    }
}

static void GMAC_IrqFSMDPPHandler( \
                                const uint8 Instance, \
                                uint32 ErrorStatusFlags, \
                                uint32 ErrorEnFlags \
                             )
{
    const GMAC_Type *Base = Gmac_apxBases[Instance];

    /* Check if driver is initialized */
    if (Gmac_apxState[Instance] != NULL_PTR)
    {
        /* Callback function. */
        if (Gmac_apxState[Instance]->SafetyCallback != NULL_PTR)
        {
            if (((ErrorStatusFlags & GMAC_DPP_STS_MASK) != 0U) && ((ErrorEnFlags & GMAC_DPP_CTL_MASK) != 0U))
            {
                Gmac_apxState[Instance]->SafetyCallback(Instance, GMAC_SAF_ERR_DATA_PATH_PARITY);
            }
            else
            {
                GMAC_IrqFSMHandler(Instance, ErrorStatusFlags, Base->MAC_FSM_CONTROL);
            }
        }
    }
}
#endif
static void GMAC_IrqECCHandler( \
                                const uint8 Instance, \
                                uint32 ErrorStatusFlags, \
                                uint32 ErrorEnFlags \
                             )
{
    /* Check if driver is initialized */
    if (Gmac_apxState[Instance] != NULL_PTR)
    {
        /* Check if IRQ is spurious */
        if (((ErrorStatusFlags & GMAC_ECC_STS_MASK) != 0U) && ((ErrorEnFlags & GMAC_ECC_CTL_MASK) != 0U))
        {
            /* Callback function. */
            if (Gmac_apxState[Instance]->SafetyCallback != NULL_PTR)
            {
                Gmac_apxState[Instance]->SafetyCallback(Instance, GMAC_SAF_ERR_ECC);
            }
        }
    }
}
#endif

static void GMAC_MACIRQHandler(uint8 Instance)
{
    const GMAC_Type *Base = Gmac_apxBases[Instance];
    uint32 Flags;

    if ((Base->DMA_INTERRUPT_STATUS & GMAC_DMA_INTERRUPT_STATUS_MACIS_MASK) != 0U)
    {
        /* Clear the interrupt events. */
        Flags = Base->MAC_INTERRUPT_STATUS;

        /* Callback function. */
        if (Gmac_apxState[Instance]->Callback != NULL_PTR)
        {
            Gmac_apxState[Instance]->Callback(Instance);
        }

    #if FEATURE_GMAC_RGMII_EN || FEATURE_GMAC_SMII_EN
        if ((Flags & GMAC_MAC_INTERRUPT_STATUS_RGSMIIIS_MASK) != 0U)
        {
            (void)Base->MAC_PHYIF_CONTROL_STATUS;
        }
    #endif
        if ((Flags & GMAC_MAC_INTERRUPT_STATUS_FPEIS_MASK) != 0U)
        {
            (void)Base->MAC_FPE_CTRL_STS;
        }
        if (((Flags & GMAC_MAC_INTERRUPT_STATUS_RXSTSIS_MASK) != 0U) ||
            ((Flags & GMAC_MAC_INTERRUPT_STATUS_TXSTSIS_MASK) != 0U))
        {
            (void)Base->MAC_RX_TX_STATUS;
        }
    }
}
/*******************************************************************************
 * Code
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_StartTimeout
 * Description   : Checks for timeout condition
 *
 *END**************************************************************************/
void GMAC_StartTimeOut(uint32 *StartTimeOut,
                       uint32 *ElapsedTimeOut,
                       uint32 *TimeoutTicksOut,
                       uint32 TimeoutUs)
{
    *StartTimeOut    = OsIf_GetCounter(GMAC_TIMEOUT_TYPE);
    *ElapsedTimeOut  = 0U;
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, GMAC_TIMEOUT_TYPE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_TimeoutExpired
 * Description   : Checks for timeout expiration condition
 *
 *END**************************************************************************/
boolean GMAC_TimeoutExpired(uint32 *StartTimeInOut,
                            uint32 *ElapsedTimeInOut,
                            uint32 TimeoutTicks)
{
    boolean RetVal = FALSE;
    *ElapsedTimeInOut += OsIf_GetElapsed(StartTimeInOut, GMAC_TIMEOUT_TYPE);

    if(*ElapsedTimeInOut >= TimeoutTicks)
    {
        RetVal = TRUE;
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_WriteManagementFrame
 * Description   : Writes a MII management frame.
 *
 *END**************************************************************************/
Gmac_Ip_StatusType GMAC_WriteManagementFrame(GMAC_Type * Base,
                                             const Gmac_Ip_ManagementInfo *ManageInfo,
                                             uint32 TimeoutUs)
{
    Gmac_Ip_StatusType Status = GMAC_STATUS_TIMEOUT;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    Base->MAC_MDIO_ADDRESS &= ~(GMAC_MAC_MDIO_ADDRESS_PA_MASK |
                                GMAC_MAC_MDIO_ADDRESS_RDA_MASK |
                                GMAC_MAC_MDIO_ADDRESS_GOC_0_MASK |
                                GMAC_MAC_MDIO_ADDRESS_GOC_1_MASK |
                                GMAC_MAC_MDIO_ADDRESS_C45E_MASK);
    Base->MAC_MDIO_DATA = GMAC_MAC_MDIO_DATA_RA(ManageInfo->SupportedClause45 ? ManageInfo->PhysReg : 0UL) |
                          GMAC_MAC_MDIO_DATA_GD(ManageInfo->FrameData);
    Base->MAC_MDIO_ADDRESS |= (ManageInfo->SupportedClause45 ? GMAC_MAC_MDIO_ADDRESS_C45E_MASK : 0UL) |
                               GMAC_MAC_MDIO_ADDRESS_GOC_1(ManageInfo->OpFrameType) |
                               GMAC_MAC_MDIO_ADDRESS_GOC_0_MASK |
                               GMAC_MAC_MDIO_ADDRESS_PA(ManageInfo->PhysAddr) |
                               GMAC_MAC_MDIO_ADDRESS_RDA(ManageInfo->SupportedClause45 ? (uint32)ManageInfo->MmdAddr : (uint32)ManageInfo->PhysReg) |
                               GMAC_MAC_MDIO_ADDRESS_GB_MASK;
    /* Add fault label for testing */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        MCAL_FAULT_INJECTION_POINT(ETH_MDIO_TIMEOUT);
    #endif

    /* Wait for completion */
    GMAC_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, TimeoutUs);
    do
    {
        if ((Base->MAC_MDIO_ADDRESS & GMAC_MAC_MDIO_ADDRESS_GB_MASK) == 0U)
        {
            Status = GMAC_STATUS_SUCCESS;
            break;
        }
    }
    while (!GMAC_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_CommonIRQHandler
 * Description   : Handler for GMAC common interrupt.
 * This handler invokes the installed callback (if available) and clears the
 * interrupt flags.
 *
 *END**************************************************************************/
void GMAC_CommonIRQHandler(uint8 Instance)
{
    const GMAC_Type *Base = Gmac_apxBases[Instance];
    uint8 i;
    uint32 Flags;

    GMAC_MACIRQHandler(Instance);

    for (i = 0; i < FEATURE_GMAC_NUM_CHANNELS; i++)
    {
        if ((Base->DMA_INTERRUPT_STATUS & (1UL << (uint32)i)) != 0U)
        {
            Gmac_Ip_ChannelType *ChBase = Gmac_apxChBases[Instance][i];
            Flags = ChBase->DMA_STATUS;

            /* Callback function. */
            if (((Flags & GMAC_RX_INTERRUPTS) != 0U) &&
                 (Gmac_apxState[Instance]->RxChCallback[i] != NULL_PTR))
            {
                Gmac_apxState[Instance]->RxChCallback[i](Instance, i);
            }

            /* Callback function. */
            if (((Flags & GMAC_TX_INTERRUPTS) != 0U) &&
                 (Gmac_apxState[Instance]->TxChCallback[i] != NULL_PTR))
            {
                Gmac_apxState[Instance]->TxChCallback[i](Instance, i);
            }

            /* Clear the interrupt event. */
            ChBase->DMA_STATUS = Flags;
            (void)ChBase->DMA_STATUS;
        }
    }
}


#if (FEATURE_GMAC_ASP_ALL || FEATURE_GMAC_ASP_ECC)
/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_SafetyIRQHandler
 * Description   : Handler for GMAC safety interrupt.
 * This handler invokes the installed callback (if available) and clears the
 * interrupt flags.
 *
 *END**************************************************************************/

void GMAC_SafetyIRQHandler(uint8 Instance)
{
    GMAC_Type *Base = Gmac_apxBases[Instance];
    uint32 SafetyStatusFlags;
    uint32 ErrorStatusFlags;

    SafetyStatusFlags = Base->DMA_SAFETY_INTERRUPT_STATUS;
    if ((SafetyStatusFlags & GMAC_DMA_SAFETY_INTERRUPT_STATUS_MSUIS_MASK) != 0U)
    {
        ErrorStatusFlags = Base->MTL_ECC_INTERRUPT_STATUS;

        /* Clear the ECC interrupt event(s) */
        Base->MTL_ECC_INTERRUPT_STATUS = ErrorStatusFlags;

        GMAC_IrqECCHandler(Instance, ErrorStatusFlags, Base->MTL_ECC_CONTROL);

    }
#if FEATURE_GMAC_ASP_ALL
    else if ((SafetyStatusFlags & GMAC_DMA_SAFETY_INTERRUPT_STATUS_MCSIS_MASK) != 0U)
    {
        ErrorStatusFlags = Base->MAC_DPP_FSM_INTERRUPT_STATUS;

        GMAC_IrqFSMDPPHandler(Instance, ErrorStatusFlags, Base->MTL_DPP_CONTROL);
    }
    else
    {
        /*Do nothing*/
    }
#endif
}
#endif /* #if (FEATURE_GMAC_ASP_ALL || FEATURE_GMAC_ASP_ECC) */

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_RxIRQHandler
 * Description   : Handler for GMAC receive interrupt.
 * This handler invokes the installed callback (if available) and clears the
 * interrupt flags.
 *
 *END**************************************************************************/
 /* implements GMAC_RxIRQHandler_Activity */
void GMAC_RxIRQHandler(uint8 Instance,
                       uint8 Channel)
{
    Gmac_Ip_ChannelType *ChBase = Gmac_apxChBases[Instance][Channel];
    uint32 StatusFlags   = ChBase->DMA_STATUS;
    uint32 IrqEnFlags    = ChBase->DMA_INTERRUPT_ENABLE;

    /* Check if driver is initialized */
    if (Gmac_apxState[Instance] != NULL_PTR)
    {
        /* Check if IRQ is spurious */
        if (((IrqEnFlags  & GMAC_DMA_CH0_INTERRUPT_ENABLE_RIE_MASK) != 0U) &&
            ((StatusFlags & GMAC_DMA_CH0_STATUS_RI_MASK) != 0U))
        {
            /* Clear the interrupt event. */
            ChBase->DMA_STATUS = GMAC_DMA_CH0_STATUS_RI_MASK;

            /* Callback function. */
            if (Gmac_apxState[Instance]->RxChCallback[Channel] != NULL_PTR)
            {
                Gmac_apxState[Instance]->RxChCallback[Channel](Instance, Channel);
            }
        }
    }
    else
    {
        /* Clear the interrupt event. */
        ChBase->DMA_STATUS = GMAC_DMA_CH0_STATUS_RI_MASK;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_TxIRQHandler
 * Description   : Handler for GMAC transmit interrupt.
 * This handler invokes the installed callback (if available) and clears the
 * interrupt flags.
 *
 *END**************************************************************************/
 /* implements GMAC_TxIRQHandler_Activity  */
void GMAC_TxIRQHandler(uint8 Instance,
                       uint8 Channel)
{
    Gmac_Ip_ChannelType *ChBase = Gmac_apxChBases[Instance][Channel];
    uint32 StatusFlags   = ChBase->DMA_STATUS;
    uint32 IrqEnFlags    = ChBase->DMA_INTERRUPT_ENABLE;

    /* Check if driver is initialized */
    if (Gmac_apxState[Instance] != NULL_PTR)
    {
        /* Check if IRQ is spurious */
        if (((IrqEnFlags  & GMAC_DMA_CH0_INTERRUPT_ENABLE_TIE_MASK) != 0U) &&
            ((StatusFlags & GMAC_DMA_CH0_STATUS_TI_MASK) != 0U))
        {
            /* Clear the interrupt event. */
            ChBase->DMA_STATUS = GMAC_DMA_CH0_STATUS_TI_MASK;

            /* Callback function. */
            if (Gmac_apxState[Instance]->TxChCallback[Channel] != NULL_PTR)
            {
                Gmac_apxState[Instance]->TxChCallback[Channel](Instance, Channel);
            }
        }
    }
    else
    {
        /* Clear the interrupt event. */
        ChBase->DMA_STATUS = GMAC_DMA_CH0_STATUS_TI_MASK;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_AddToHashTable
 * Description   : Adds an entry to the hash table filter.
 * This functions adds an entry to the hash table filter based on the CRC of a
 * hardware address.
 *
 *END**************************************************************************/
void GMAC_AddToHashTable(const GMAC_Type * Base,
                         uint32 Crc)
{
    uint32 Index;
    uint32 Hash_bit;
    volatile uint32 HashBaseAddr = (uint32)&Base->MAC_HASH_TABLE_REG0;
    volatile uint32 (*Hash_table)[FEATURE_GMAC_HASH_TABLE_DIM] = (volatile uint32 (*)[FEATURE_GMAC_HASH_TABLE_DIM])HashBaseAddr;

    Index    = GMAC_HASH_TABLE_REG_IDX(REV_BITS_32(Crc));
    Hash_bit = (uint32)1U << GMAC_HASH_TABLE_BIT_IDX(REV_BITS_32(Crc));

    (*Hash_table)[Index % FEATURE_GMAC_HASH_TABLE_DIM] |= Hash_bit;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_RemoveFromHashTable
 * Description   : Removes an entry from the hash table filter.
 * This functions removes an entry from the hash table filter based on the CRC
 * of a hardware address.
 *
 *END**************************************************************************/
void GMAC_RemoveFromHashTable(const GMAC_Type * Base,
                              uint32 Crc)
{
    uint32 Index;
    uint32 Hash_bit;
    volatile uint32 HashBaseAddr = (uint32)&Base->MAC_HASH_TABLE_REG0;
    volatile uint32 (*Hash_table)[FEATURE_GMAC_HASH_TABLE_DIM] = (volatile uint32 (*)[FEATURE_GMAC_HASH_TABLE_DIM])HashBaseAddr;

    Index    = GMAC_HASH_TABLE_REG_IDX(REV_BITS_32(Crc));
    Hash_bit = (uint32)1U << GMAC_HASH_TABLE_BIT_IDX(REV_BITS_32(Crc));

    (*Hash_table)[Index % FEATURE_GMAC_HASH_TABLE_DIM] &= ~Hash_bit;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_AddVlanToHashTable
 * Description   : Adds a VLAN tag to the VLAN hash table filter.
 *
 *END**************************************************************************/
void GMAC_AddVlanToHashTable(GMAC_Type * Base,
                             uint32 Crc)
{
    uint32 Index;

    Index = (REV_BITS_32(Crc) & GMAC_CRC32_BITS_31_28_MASK) >>
            GMAC_CRC32_BITS_31_28_SHIFT;

    if (GMAC_MAC_VLAN_TAG_DATA_ETV_MASK != (Base->MAC_VLAN_TAG_DATA_REG & GMAC_MAC_VLAN_TAG_DATA_ETV_MASK))
    {
        Index = Index - 1UL;
    }

    Base->MAC_VLAN_HASH_TABLE |= ((uint32)1U << Index);
}
/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_RemoveVlanFromHashTable
 * Description   : Removes a VLAN tag from the VLAN has0x00 0x64h table filter.
 *
 *END**************************************************************************/
void GMAC_RemoveVlanFromHashTable(GMAC_Type * Base,
                                  uint32 Crc)
{
    uint32 Index;

    Index = (REV_BITS_32(Crc) & GMAC_CRC32_BITS_31_28_MASK) >>
            GMAC_CRC32_BITS_31_28_SHIFT;

    if (GMAC_MAC_VLAN_TAG_DATA_ETV_MASK != (Base->MAC_VLAN_TAG_DATA_REG & GMAC_MAC_VLAN_TAG_DATA_ETV_MASK))
    {
        Index = Index - 1UL;
    }

    Base->MAC_VLAN_HASH_TABLE &= ~((uint32)1U << Index);
}
/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_GetPowerState
 * Description   : Gets the current power state
 *
 *END**************************************************************************/
Gmac_Ip_PowerStateType GMAC_GetPowerState(const GMAC_Type * Base)
{
    Gmac_Ip_PowerStateType PowerState = GMAC_PSTATE_RESET;

    /* The order is important to enforce RESET > SLEEP > ACTIVE > INACTIVE priority */
    if ((Base->DMA_MODE & GMAC_DMA_MODE_SWR_MASK) != 0U)
    {
        PowerState = GMAC_PSTATE_RESET;
    }
#if FEATURE_GMAC_PMT_EN
    else if ((Base->MAC_PMT_CONTROL_STATUS & GMAC_MAC_PMT_CONTROL_STATUS_PWRDWN_MASK) != 0U)
    {
        PowerState = GMAC_PSTATE_SLEEP;
    }
#endif
    else if ((Base->MAC_CONFIGURATION & (GMAC_MAC_CONFIGURATION_RE_MASK | GMAC_MAC_CONFIGURATION_TE_MASK)) != 0U)
    {
        PowerState = GMAC_PSTATE_ACTIVE;
    }
    else if ((Base->MAC_CONFIGURATION & (GMAC_MAC_CONFIGURATION_RE_MASK | GMAC_MAC_CONFIGURATION_TE_MASK)) == 0U)
    {
        PowerState = GMAC_PSTATE_INACTIVE;
    }
    else
    {
        /* Should not get here. */
    }

    return PowerState;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_SetPowerState
 * Description   : Sets the power state
 *
 *END**************************************************************************/
void GMAC_SetPowerState(GMAC_Type * Base, Gmac_Ip_PowerStateType PowerState)
{
    switch (PowerState)
    {
        case GMAC_PSTATE_INACTIVE:
        {
        #if FEATURE_GMAC_PMT_EN
            Base->MAC_PMT_CONTROL_STATUS &= ~GMAC_MAC_PMT_CONTROL_STATUS_PWRDWN_MASK;
        #endif
            Base->MAC_CONFIGURATION &= ~(GMAC_MAC_CONFIGURATION_RE_MASK | GMAC_MAC_CONFIGURATION_TE_MASK);
            break;
        }

        case GMAC_PSTATE_ACTIVE:
        {
        #if FEATURE_GMAC_PMT_EN
            Base->MAC_PMT_CONTROL_STATUS &= ~GMAC_MAC_PMT_CONTROL_STATUS_PWRDWN_MASK;
        #endif
            Base->MAC_CONFIGURATION |= (GMAC_MAC_CONFIGURATION_RE_MASK | GMAC_MAC_CONFIGURATION_TE_MASK);
            break;
        }

    #if FEATURE_GMAC_PMT_EN
        case GMAC_PSTATE_SLEEP:
        {
            Base->MAC_PMT_CONTROL_STATUS |= (GMAC_MAC_PMT_CONTROL_STATUS_GLBLUCAST_MASK | GMAC_MAC_PMT_CONTROL_STATUS_RWKPKTEN_MASK);
            Base->MAC_PMT_CONTROL_STATUS |= GMAC_MAC_PMT_CONTROL_STATUS_PWRDWN_MASK;
            Base->MAC_PMT_CONTROL_STATUS |= GMAC_MAC_PMT_CONTROL_STATUS_RWKPFE_MASK;
            break;
        }
    #endif

        case GMAC_PSTATE_RESET:
        {
            Base->DMA_MODE |= GMAC_DMA_MODE_SWR_MASK;
            break;
        }

        default:
        {
            /* Should not get here. */
            break;
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_SetSpeed
 * Description   : Sets the MII speed
 *
 *END**************************************************************************/
void GMAC_SetSpeed(GMAC_Type * Base, Gmac_Ip_SpeedType Speed)
{
    if (Speed == GMAC_SPEED_1G)
    {
        Base->MAC_CONFIGURATION &= ~(GMAC_MAC_CONFIGURATION_PS_MASK |
                                     GMAC_MAC_CONFIGURATION_FES_MASK);
    }
    else if (Speed == GMAC_SPEED_100M) /* The enum GMAC_SPEED_100M will work for both GMAC_SPEED_100M and GMAC_SPEED_200M because they are equal. */
    {
        Base->MAC_CONFIGURATION |= GMAC_MAC_CONFIGURATION_PS_MASK |
                                   GMAC_MAC_CONFIGURATION_FES_MASK;
    }
    else if (Speed == GMAC_SPEED_10M)
    {
        Base->MAC_CONFIGURATION |= GMAC_MAC_CONFIGURATION_PS_MASK;
        Base->MAC_CONFIGURATION &= ~GMAC_MAC_CONFIGURATION_FES_MASK;
    }
#if FEATURE_GMAC_SGMII_EN
    else if (Speed == GMAC_SPEED_2500M)
    {
        Base->MAC_CONFIGURATION &= ~GMAC_MAC_CONFIGURATION_PS_MASK;
        Base->MAC_CONFIGURATION |= GMAC_MAC_CONFIGURATION_FES_MASK;
    }
#endif
    else
    {
        /* Should not get here. */
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_SetSchedAlg
 * Description   : Sets the Tx scheduling algorithm
 *
 *END**************************************************************************/
void GMAC_SetSchedAlg(GMAC_Type * Base, Gmac_Ip_TxSchedAlgoType SchedAlgo)
{
    if (SchedAlgo == GMAC_SCHED_ALGO_WRR)
    {
        Base->MTL_OPERATION_MODE &= ~GMAC_MTL_OPERATION_MODE_SCHALG_MASK;
    }
    else if (SchedAlgo == GMAC_SCHED_ALGO_SP)
    {
        Base->MTL_OPERATION_MODE |= GMAC_MTL_OPERATION_MODE_SCHALG_MASK;
    }
    else
    {
        /* Should not get here. */
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_SetTxQueueQuantumWeight
 * Description   : Sets the weight or idle slope credit for a specific Tx Queue
 *
 *END**************************************************************************/
void GMAC_SetTxQueueQuantumWeight(Gmac_Ip_QueueType * QueueBase,
                                  uint32 Weight)
{
    QueueBase->MTL_TXQ_QUANTUM_WEIGHT = Weight;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_SetTxQueueCreditBasedShaper
 * Description   : Sets the send slope, high credit and low credit for a specific Tx Queue
 *
 *END**************************************************************************/
void GMAC_SetTxQueueCreditBasedShaper(Gmac_Ip_QueueType * QueueBase,
                                      uint32 SendSlopeCredit,
                                      uint32 HighCredit,
                                      sint32 LowCredit)
{
    QueueBase->MTL_TXQ_SENDSLOPECREDIT = SendSlopeCredit;
    QueueBase->MTL_TXQ_HICREDIT        = HighCredit;
    QueueBase->MTL_TXQ_LOCREDIT        = (uint32)LowCredit;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_SetTxQueueOperationMode
 * Description   : Sets the operation mode for a Tx Queue
 *
 *END**************************************************************************/
void GMAC_SetTxQueueOperationMode(Gmac_Ip_QueueType * QueueBase,
                                  Gmac_Ip_OperationModeType QueueMode,
                                  uint32 QueueSize)
{
    uint32 BlockNum;
    BlockNum = QueueSize / FEATURE_GMAC_MTL_TX_FIFO_BLOCK_SIZE;
    BlockNum = (BlockNum == 0U)? 0U : (BlockNum - 1UL);

    QueueBase->MTL_TXQ_OPERATION_MODE = GMAC_MTL_TXQ0_OPERATION_MODE_TXQEN((uint32)QueueMode) |
                                        GMAC_MTL_TXQ0_OPERATION_MODE_TSF_MASK |
                                        (((uint32)(BlockNum <<
                                        GMAC_MTL_TXQ0_OPERATION_MODE_TQS_SHIFT)) &
                                        GMAC_MTL_TXQ0_OPERATION_MODE_TQS_MASK);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_SetTxStoreAndForward
 * Description   : Enable store and forward for a specific Tx Queue.
 *
 *END**************************************************************************/
void GMAC_SetTxStoreAndForward(Gmac_Ip_QueueType * QueueBase)
{
    QueueBase->MTL_TXQ_OPERATION_MODE |= GMAC_MTL_TXQ0_OPERATION_MODE_TSF_MASK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_SetTxThreshold
 * Description   : Sets the Tx threshold value.
 *
 *END**************************************************************************/
void GMAC_SetTxThreshold(Gmac_Ip_QueueType * QueueBase,
                         Gmac_Ip_TxThresholdType ThresholdValue)
{
    QueueBase->MTL_TXQ_OPERATION_MODE &= ~(GMAC_MTL_TXQ0_OPERATION_MODE_TSF_MASK |
                                           GMAC_MTL_TXQ0_OPERATION_MODE_TTC_MASK);
    QueueBase->MTL_TXQ_OPERATION_MODE |= GMAC_MTL_TXQ0_OPERATION_MODE_TTC((uint32)ThresholdValue);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_EnableRxQueue
 * Description   : Enables the given Rx Queue for generic traffic with the given VLAN priorities.
 *
 *END**************************************************************************/
void GMAC_EnableRxQueue(GMAC_Type * Base,
                        uint8 PriorityMask,
                        uint8 QueueNum)
{
    /* Set Rx Queue's VLAN Priorities */
#if FEATURE_GMAC_NUM_QUEUES > 4
    if (QueueNum < 4U)
    {
#endif
        Base->MAC_RXQ_CTRL2 |= (uint32)((uint32)PriorityMask << (uint32)((uint32)QueueNum * GMAC_MAC_RXQ_CTRL2_PSRQ0_WIDTH));
#if FEATURE_GMAC_NUM_QUEUES > 4
    }
    else
    {
        Base->MAC_RXQ_CTRL3 |= (uint32)((uint32)PriorityMask << (uint32)(((uint32)QueueNum - 4U) * GMAC_MAC_RXQ_CTRL2_PSRQ0_WIDTH));
    }
#endif

    /* Enable the Rx Queue */
    Base->MAC_RXQ_CTRL0 |= (uint32)((uint32)GMAC_OP_MODE_DCB_GEN << (uint32)((uint32)QueueNum * GMAC_MAC_RXQ_CTRL0_RXQ0EN_WIDTH));
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_SetRxQueueOperationMode
 * Description   : Sets the operation mode for an Rx queue
 *
 *END**************************************************************************/
void GMAC_SetRxQueueOperationMode(Gmac_Ip_QueueType * QueueBase,
                                  uint32 QueueSize)
{
    uint32 BlockNum;
    BlockNum = QueueSize / FEATURE_GMAC_MTL_RX_FIFO_BLOCK_SIZE;
    BlockNum = (BlockNum == 0U)? 0U : (BlockNum - 1UL);

    QueueBase->MTL_RXQ_OPERATION_MODE = (((uint32)(BlockNum <<
                                        GMAC_MTL_RXQ0_OPERATION_MODE_RQS_SHIFT)) &
                                        GMAC_MTL_RXQ0_OPERATION_MODE_RQS_MASK);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_SetRxQueuesDmaChMap
 * Description   : Sets the DMA channel mapping for Rx queues
 *
 *END**************************************************************************/
void GMAC_SetRxQueuesDmaChMap(GMAC_Type * Base,
                              uint8 QueuesNum)
{
    if (QueuesNum > 0U)
    {
        Base->MTL_RXQ_DMA_MAP0 |= GMAC_MTL_RXQ_DMA_MAP0_Q0DDMACH(0U) |
                                  GMAC_MTL_RXQ_DMA_MAP0_Q0MDMACH(0U);
    }
#if FEATURE_GMAC_NUM_CHANNELS > 1U
    if (QueuesNum > 1U)
    {
        Base->MTL_RXQ_DMA_MAP0 |= GMAC_MTL_RXQ_DMA_MAP0_Q1DDMACH(0U) |
                                  GMAC_MTL_RXQ_DMA_MAP0_Q1MDMACH(1U);
    }
#endif
#if FEATURE_GMAC_NUM_CHANNELS > 2U
    if (QueuesNum > 2U)
    {
        Base->MTL_RXQ_DMA_MAP0 |= GMAC_MTL_RXQ_DMA_MAP0_Q2DDMACH(0U) |
                                  GMAC_MTL_RXQ_DMA_MAP0_Q2MDMACH(2U);
    }
#endif
#if FEATURE_GMAC_NUM_CHANNELS > 3U
    if (QueuesNum > 3U)
    {
        Base->MTL_RXQ_DMA_MAP0 |= GMAC_MTL_RXQ_DMA_MAP0_Q3DDMACH(0U) |
                                  GMAC_MTL_RXQ_DMA_MAP0_Q3MDMACH(3U);
    }
#endif
#if FEATURE_GMAC_NUM_CHANNELS > 4U
    if (QueuesNum > 4U)
    {
        Base->MTL_RXQ_DMA_MAP1 |= GMAC_MTL_RXQ_DMA_MAP1_Q4DDMACH(0U) |
                                  GMAC_MTL_RXQ_DMA_MAP1_Q4MDMACH(4U);
    }
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_SetVlanTagInvMatch
 * Description   : Sets VLAN Tag inverse match.
 *
 *END**************************************************************************/
void GMAC_SetVlanTagInvMatch(GMAC_Type * Base, boolean Enable)
{
    if (Enable)
    {
        Base->MAC_VLAN_TAG_CTRL_REG |= GMAC_MAC_VLAN_TAG_CTRL_VTIM_MASK;
    }
    else
    {
        Base->MAC_VLAN_TAG_CTRL_REG &= ~GMAC_MAC_VLAN_TAG_CTRL_VTIM_MASK;
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_SetVlanTagDataRxMatch
 * Description   : Sets MAC_VLAN_Tag_Data register with Rx matching relevant
 * data.
 *
 *END**************************************************************************/
void GMAC_SetVlanTagDataRxMatch(GMAC_Type * Base,
                                boolean EnInnerVlanMatch,
                                boolean EnSvlanMatch,
                                boolean DisVlanTypeMatch,
                                boolean En12bitMatch)
{
    if (EnInnerVlanMatch)
    {
        Base->MAC_VLAN_TAG_DATA_REG |= GMAC_MAC_VLAN_TAG_DATA_ERIVLT_MASK;
    }
    else
    {
        Base->MAC_VLAN_TAG_DATA_REG &= ~GMAC_MAC_VLAN_TAG_DATA_ERIVLT_MASK;
    }

    if (EnSvlanMatch)
    {
        Base->MAC_VLAN_TAG_DATA_REG |= GMAC_MAC_VLAN_TAG_DATA_ERSVLM_MASK;
    }
    else
    {
        Base->MAC_VLAN_TAG_DATA_REG &= ~GMAC_MAC_VLAN_TAG_DATA_ERSVLM_MASK;
    }

    if (DisVlanTypeMatch)
    {
        Base->MAC_VLAN_TAG_DATA_REG |= GMAC_MAC_VLAN_TAG_DATA_DOVLTC_MASK;
    }
    else
    {
        Base->MAC_VLAN_TAG_DATA_REG &= ~GMAC_MAC_VLAN_TAG_DATA_DOVLTC_MASK;
    }

    if (En12bitMatch)
    {
        Base->MAC_VLAN_TAG_DATA_REG |= GMAC_MAC_VLAN_TAG_DATA_ETV_MASK;
    }
    else
    {
        Base->MAC_VLAN_TAG_DATA_REG &= ~GMAC_MAC_VLAN_TAG_DATA_ETV_MASK;
    }

    Base->MAC_VLAN_TAG_DATA_REG |= GMAC_MAC_VLAN_TAG_DATA_VEN_MASK;
}
#if (FEATURE_GMAC_VLAN_RX_FILTERS_NUM > 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : GMAC_ReadVlanTagRxFilter
 * Description   : Read a VLAN Tag Rx filter.
 *
 *END**************************************************************************/
Gmac_Ip_StatusType GMAC_ReadVlanTagRxFilter(GMAC_Type * Base,
                                            uint8 FilterIdx,
                                            uint16 * VlanTag)
{
    Gmac_Ip_StatusType Status = GMAC_STATUS_TIMEOUT;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    /* Clear filter offset. */
    Base->MAC_VLAN_TAG_CTRL_REG &= ~GMAC_MAC_VLAN_TAG_CTRL_OFS_MASK;
    /* Set filter offset and enable write operation. */
    Base->MAC_VLAN_TAG_CTRL_REG |= ((uint32)(((uint32)FilterIdx) <<
                               GMAC_MAC_VLAN_TAG_CTRL_OFS_SHIFT)) |
                               GMAC_MAC_VLAN_TAG_CTRL_CT_MASK;
    /* Set busy bit. */
    Base->MAC_VLAN_TAG_CTRL_REG |= GMAC_MAC_VLAN_TAG_CTRL_OB_MASK;

#ifdef MCAL_ENABLE_FAULT_INJECTION
    MCAL_FAULT_INJECTION_POINT(ETH_READ_VLAN_TAG_RX_FILTER_TIMEOUT);
#endif

    GMAC_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, GMAC_TIMEOUT_VALUE_US);
    do
    {
        if ((Base->MAC_VLAN_TAG_CTRL_REG & GMAC_MAC_VLAN_TAG_CTRL_OB_MASK) == 0U)
        {
            Status = GMAC_STATUS_SUCCESS;
            break;
        }
    }
    while (!GMAC_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    if (Status == GMAC_STATUS_SUCCESS)
    {
        /* Read the VLAN tag. */
        *VlanTag = (uint16)(Base->MAC_VLAN_TAG_DATA_REG &
                   GMAC_MAC_VLAN_TAG_DATA_VID_MASK);
    }

    return Status;
}
#endif

#define ETH_43_GMAC_STOP_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
