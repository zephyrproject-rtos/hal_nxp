/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef GMAC_IP_DEVICE_REGISTERS_H
#define GMAC_IP_DEVICE_REGISTERS_H

/**
*   @file
*
*   @addtogroup GMAC_DRIVER_CONFIGURATION GMAC Driver Configuration
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
#include "Mcal.h"
#include "S32K344_EMAC.h"
#include "Emac_Ip_Wrapper.h"
#include "S32K344_DCM_GPR.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GMAC_IP_DEVICE_REGISTERS_VENDOR_ID                    43
#define GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION     4
#define GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION     7
#define GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION  0
#define GMAC_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION             3
#define GMAC_IP_DEVICE_REGISTERS_SW_MINOR_VERSION             0
#define GMAC_IP_DEVICE_REGISTERS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
    /* Checks against Emac_Ip_Wrapper.h */
    #if (GMAC_IP_DEVICE_REGISTERS_VENDOR_ID != EMAC_IP_WRAPPER_VENDOR_ID)
        #error "Gmac_Ip_Device_Registers.h and Emac_Ip_Wrapper.h have different vendor ids"
    #endif
    #if (( GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION    != EMAC_IP_WRAPPER_AR_RELEASE_MAJOR_VERSION) || \
        ( GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION    != EMAC_IP_WRAPPER_AR_RELEASE_MINOR_VERSION) || \
        ( GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION != EMAC_IP_WRAPPER_AR_RELEASE_REVISION_VERSION))
        #error "AUTOSAR Version Numbers of Gmac_Ip_Device_Registers.h and Emac_Ip_Wrapper.h are different"
    #endif
    #if (( GMAC_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION != EMAC_IP_WRAPPER_SW_MAJOR_VERSION) || \
        ( GMAC_IP_DEVICE_REGISTERS_SW_MINOR_VERSION != EMAC_IP_WRAPPER_SW_MINOR_VERSION) || \
        ( GMAC_IP_DEVICE_REGISTERS_SW_PATCH_VERSION != EMAC_IP_WRAPPER_SW_PATCH_VERSION))
        #error "Software Version Numbers of Gmac_Ip_Device_Registers.h and Emac_Ip_Wrapper.h are different"
    #endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Gmac_Ip_Device_Registers.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/** @cond DRIVER_INTERNAL_USE_ONLY */
#define DMA_CH0_CONTROL_ADDR16              0x1100U
#define DMA_CH1_CONTROL_ADDR16              0x1180U
#define DMA_CH2_CONTROL_ADDR16              0x1200U
#define DMA_CH3_CONTROL_ADDR16              0x1280U
#define DMA_CH4_CONTROL_ADDR16              0x1300U

#define MTL_TXQ0_OPERATION_MODE_ADDR16      0x0D00U
#define MTL_TXQ1_OPERATION_MODE_ADDR16      0x0D40U
#define MTL_TXQ2_OPERATION_MODE_ADDR16      0x0D80U
#define MTL_TXQ3_OPERATION_MODE_ADDR16      0x0DC0U
#define MTL_TXQ4_OPERATION_MODE_ADDR16      0x0E00U

typedef struct
{
  volatile uint32 DMA_CONTROL;
  volatile uint32 DMA_TX_CONTROL;
  volatile uint32 DMA_RX_CONTROL;
  volatile uint8 RESERVED_1[8];
  volatile uint32 DMA_TXDESC_LIST_ADDRESS;
  volatile uint8 RESERVED_2[4];
  volatile uint32 DMA_RXDESC_LIST_ADDRESS;
  volatile uint32 DMA_TXDESC_TAIL_POINTER;
  volatile uint8 RESERVED_3[4];
  volatile uint32 DMA_RXDESC_TAIL_POINTER;
  volatile uint32 DMA_TXDESC_RING_LENGTH;
  volatile uint32 DMA_RXDESC_RING_LENGTH;
  volatile uint32 DMA_INTERRUPT_ENABLE;
  volatile uint32 DMA_RX_INTERRUPT_WATCHDOG_TIMER;
  volatile uint32 DMA_SLOT_FUNCTION_CONTROL_STATUS;
  volatile uint8 RESERVED_4[4];
  volatile uint32 DMA_CURRENT_APP_TXDESC;
  volatile uint8 RESERVED_5[4];
  volatile uint32 DMA_CURRENT_APP_RXDESC;
  volatile uint8 RESERVED_6[4];
  volatile uint32 DMA_CURRENT_APP_TXBUFFER;
  volatile uint8 RESERVED_7[4];
  volatile uint32 DMA_CURRENT_APP_RXBUFFER;
  volatile uint32 DMA_STATUS;
  volatile uint32 DMA_MISS_FRAME_CNT;
  volatile uint32 DMA_RXP_ACCEPT_CNT;
  volatile uint32 DMA_RX_ERI_CNT;
  volatile uint8 RESERVED_8[16];
} Gmac_Ip_ChannelType;
/** @endcond */

/* @internal @brief Macro for different between header files */
    #define MAC_VLAN_TAG_DATA_REG       MAC_VLAN_TAG.MAC_VLAN_TAG_DATA
    #define MAC_VLAN_TAG_CTRL_REG       MAC_VLAN.MAC_VLAN_TAG_CTRL
    #define MAC_VLAN_INCL_REG           MAC_VLAN_INCL.MAC_VLAN_INCL

/* @internal @brief Base addresses for the DMA channels */
    #define DEV_REG_GMAC_CH_BASE \
    { { \
        (Gmac_Ip_ChannelType *)(IP_GMAC_0_BASE + (uint32)DMA_CH0_CONTROL_ADDR16), \
        (Gmac_Ip_ChannelType *)(IP_GMAC_0_BASE + (uint32)DMA_CH1_CONTROL_ADDR16)  \
    } } \


/** @cond DRIVER_INTERNAL_USE_ONLY */
typedef struct
{
  volatile uint32 MTL_TXQ_OPERATION_MODE;
  volatile const uint32 MTL_TXQ_UNDERFLOW;
  volatile const uint32 MTL_TXQ_DEBUG;
  uint8 RESERVED_1[4];
  volatile uint32 MTL_TXQ_ETS_CONTROL;        /* Not available for Q0 */
  volatile const uint32 MTL_TXQ_ETS_STATUS;
  volatile uint32 MTL_TXQ_QUANTUM_WEIGHT;
  volatile uint32 MTL_TXQ_SENDSLOPECREDIT;    /* Not available for Q0 */
  volatile uint32 MTL_TXQ_HICREDIT;           /* Not available for Q0 */
  volatile uint32 MTL_TXQ_LOCREDIT;           /* Not available for Q0 */
  uint8 RESERVED_2[4];
  volatile uint32 MTL_Q_INTERRUPT_CONTROL_STATUS;
  volatile uint32 MTL_RXQ_OPERATION_MODE;
  volatile const uint32 MTL_RXQ_MISSED_PACKET_OVERFLOW_CNT;
  volatile const uint32 MTL_RXQ_DEBUG;
  volatile uint32 MTL_RXQ_CONTROL;
} Gmac_Ip_QueueType;
/** @endcond */

/*! @internal @brief Base addresses for the MTL queues */
    #define DEV_REG_GMAC_QUEUE_BASE \
    { { \
        (Gmac_Ip_QueueType *)(IP_GMAC_0_BASE + (uint32)MTL_TXQ0_OPERATION_MODE_ADDR16), \
        (Gmac_Ip_QueueType *)(IP_GMAC_0_BASE + (uint32)MTL_TXQ1_OPERATION_MODE_ADDR16)  \
    } } \

    /*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* GMAC_IP_DEVICE_REGISTERS_H */
