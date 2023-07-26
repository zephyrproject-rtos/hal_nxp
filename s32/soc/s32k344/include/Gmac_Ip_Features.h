/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef GMAC_IP_FEATURES_H
#define GMAC_IP_FEATURES_H

/**
*   @file
*
*   @addtogroup GMAC_DRIVER_CONFIGURATION GMAC Driver Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*
* @page misra_violations MISRA-C:2012 violations
*
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GMAC_IP_FEATURES_VENDOR_ID                    43
#define GMAC_IP_FEATURES_AR_RELEASE_MAJOR_VERSION     4
#define GMAC_IP_FEATURES_AR_RELEASE_MINOR_VERSION     7
#define GMAC_IP_FEATURES_AR_RELEASE_REVISION_VERSION  0
#define GMAC_IP_FEATURES_SW_MAJOR_VERSION             3
#define GMAC_IP_FEATURES_SW_MINOR_VERSION             0
#define GMAC_IP_FEATURES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


    #define GMAC_IP_FEATURE_ORIGIN              (0U)/* EMAC */

    /*! @brief Number of instances */
    #define FEATURE_GMAC_NUM_INSTANCES              (1)
    /*! @brief Number of DMA channels (Assumption: DmaChannels = TxQueues = Rx Queues) */
    #define FEATURE_GMAC_NUM_CHANNELS               (2U)
    /*! @brief Number of MTL queues (Assumption: TxQueues = Rx Queues) */
    #define FEATURE_GMAC_NUM_QUEUES                 (2U)

    /*! @brief The common interrupt */
    #define FEATURE_GMAC_COMMON_IRQS                { EMAC_0_IRQn }
    /*! @brief The transmission interrupts */
    #define FEATURE_GMAC_TX_IRQS                    { {EMAC_1_IRQn, EMAC_1_IRQn} }
    /*! @brief The reception interrupts */
    #define FEATURE_GMAC_RX_IRQS                    { {EMAC_2_IRQn, EMAC_2_IRQn} }
    /*! @brief The safety interrupt */
    #define FEATURE_GMAC_SAFETY_IRQS                { EMAC_3_IRQn }


    /*! @brief The common interrupt handler */
    #define FEATURE_GMAC_COMMON_IRQ_HDLRS           { GMAC0_Common_IRQHandler }
    /*! @brief The transmission interrupt handlers */
    #define FEATURE_GMAC_TX_IRQ_HDLRS               { {GMAC0_CH_TX_IRQHandler, GMAC0_CH_TX_IRQHandler} }
    /*! @brief The reception interrupts handlers */
    #define FEATURE_GMAC_RX_IRQ_HDLRS               { {GMAC0_CH_RX_IRQHandler, GMAC0_CH_RX_IRQHandler} }
    /*! @brief The safety interrupt handler */
    #define FEATURE_GMAC_SAFETY_IRQ_HDLRS           { GMAC0_Safety_IRQHandler }


    /*! @brief Definitions used for the different IRQ configurations */
    #define FEATURE_GMAC_UNIFIED_CH_IRQS            (1U)
    #define FEATURE_GMAC_INDIVIDUAL_CH_IRQS         (0U)

    /*! @brief Definition used for aligning the buffer pools and buffer descriptors */
    #define FEATURE_GMAC_DATA_BUS_WIDTH_BITS        (32UL)
    #define FEATURE_GMAC_DATA_BUS_WIDTH_BYTES       (FEATURE_GMAC_DATA_BUS_WIDTH_BITS / 8UL)
    #define FEATURE_GMAC_LOG2_DATA_BUS_WIDTH_BYTES  (2UL)
    /*! @brief Maximum number of beats in a a data-bus (AXI/AHB) burst */
    #define FEATURE_GMAC_MAX_DATA_BUS_BURST_LENGTH  (16UL)
    /*! @brief Definitions used for setting descriptor skip length */
    #define FEATURE_GMAC_HW_BUFFDESCR_SIZE_BYTES    (16UL)
    #define FEATURE_GMAC_SW_BUFFDESCR_SIZE_BYTES    (sizeof(Gmac_Ip_BufferDescriptorType))
    /*! @brief Definition used for aligning the buffer descriptors */
    #define FEATURE_GMAC_BUFFDESCR_ALIGNMENT_BITS   (FEATURE_GMAC_DATA_BUS_WIDTH_BITS)
    #define FEATURE_GMAC_BUFFDESCR_ALIGNMENT_BYTES  (FEATURE_GMAC_DATA_BUS_WIDTH_BYTES)
    /*! @brief Definition used for aligning the buffer pools */
    #define FEATURE_GMAC_BUFF_ALIGNMENT_BITS        (FEATURE_GMAC_MAX_DATA_BUS_BURST_LENGTH * FEATURE_GMAC_DATA_BUS_WIDTH_BITS)
    #define FEATURE_GMAC_BUFF_ALIGNMENT_BYTES       (FEATURE_GMAC_MAX_DATA_BUS_BURST_LENGTH * FEATURE_GMAC_DATA_BUS_WIDTH_BYTES)
    /*! @brief Definition used for aligning the buffer length */
    #define FEATURE_GMAC_BUFFLEN_ALIGNMENT_BYTES    (FEATURE_GMAC_DATA_BUS_WIDTH_BYTES)

    /*! @brief Minimum allocatable unit in a Tx FIFO */
    #define FEATURE_GMAC_MTL_TX_FIFO_BLOCK_SIZE     (256U)
    /*! @brief Minimum allocatable unit in an Rx FIFO */
    #define FEATURE_GMAC_MTL_RX_FIFO_BLOCK_SIZE     (256U)

    /*! @brief MTL Transmit FIFO Pool Size */
    #define FEATURE_GMAC_MTL_RX_POOL_SIZE           (8192U)
    /*! @brief MTL Receive FIFO Pool Size */
    #define FEATURE_GMAC_MTL_TX_POOL_SIZE           (8192U)

    /*! @brief Definition used for aligning the total ring length (ringSize * buffLen) */
    #define FEATURE_GMAC_TXRINGLEN_ALIGNMENT_BYTES  (FEATURE_GMAC_MTL_TX_FIFO_BLOCK_SIZE)
    /*! @brief Definition used for aligning the total ring length (ringSize * buffLen) */
    #define FEATURE_GMAC_RXRINGLEN_ALIGNMENT_BYTES  (FEATURE_GMAC_MTL_RX_FIFO_BLOCK_SIZE)

    /*! @brief Definitions used for the Application Interface Parameters */
    #define FEATURE_GMAC_DATA_BUS_AXI               (0U)
    #define FEATURE_GMAC_DATA_BUS_AHB               (1U)

    /*! @brief Definitions used for the PHY Interface Parameters */
    #define FEATURE_GMAC_RGMII_EN                   (0U)
    #define FEATURE_GMAC_SGMII_EN                   (0U)
    #define FEATURE_GMAC_SMII_EN                    (0U)

    /*! @brief Definitions used for the Low Power Management Parameters */
    #define FEATURE_GMAC_PMT_EN                     (0U)

    /*! @brief Definitions used for the Overclock 50 MHz and 200 Mbps supported */
    #define FEATURE_OVERCLOCKED_EN                  (0U)

    /*! @brief Definitions used for the TCPIP Offloading Parameters */
    #define FEATURE_GMAC_ARP_EN                     (0U)

    /*! @brief Definitions used for the Automotive Safety Parameters */
    #define FEATURE_GMAC_ASP_ALL                    (1U)
    #define FEATURE_GMAC_ASP_ECC                    (1U)

    /*! @brief Definitions used for the Filtering Parameters */
    #define FEATURE_GMAC_HASH_EN                    (1U)
    #define FEATURE_GMAC_HASH_TABLE_SZ              (64U)
    #define FEATURE_GMAC_HASH_TABLE_MSB_SHIFT       (26U)

    /*! @brief Number of VLAN Rx filters */
    #define FEATURE_GMAC_VLAN_RX_FILTERS_NUM        (4U)
        /*! @brief Generate the type of cache IP on the platform used for the cacheable buffers feature */
    #define FEATURE_GMAC_CACHABLE_BUFFERS_LMEM      (0U)
    #define FEATURE_GMAC_CACHABLE_BUFFERS_CORE      (1U)

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

#endif /* GMAC_IP_FEATURES_H */
