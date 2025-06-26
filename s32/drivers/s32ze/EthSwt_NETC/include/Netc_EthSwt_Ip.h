/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NETC_ETHSWT_IP_H
#define NETC_ETHSWT_IP_H

/**
 *   @file Netc_EthSwt_Ip.h
 *   @addtogroup NETC_ETHSWT_IP NETC_ETHSWT Driver
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
#include "Mcal.h"
#include "Netc_EthSwt_Ip_Types.h"
#include "Netc_EthSwt_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETHSWT_IP_VENDOR_ID                    43
#define NETC_ETHSWT_IP_MODULE_ID                    89
#define NETC_ETHSWT_IP_AR_RELEASE_MAJOR_VERSION     4
#define NETC_ETHSWT_IP_AR_RELEASE_MINOR_VERSION     7
#define NETC_ETHSWT_IP_AR_RELEASE_REVISION_VERSION  0
#define NETC_ETHSWT_IP_SW_MAJOR_VERSION             2
#define NETC_ETHSWT_IP_SW_MINOR_VERSION             0
#define NETC_ETHSWT_IP_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

/* Check if current file and Mcal.h header file are of the same Autosar version */
#if ((NETC_ETHSWT_IP_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETHSWT_IP_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Netc_EthSwt_Ip.h and Mcal.h are different"
#endif
#endif

/* Checks against Netc_EthSwt_Ip_Types.h */
#if (NETC_ETHSWT_IP_VENDOR_ID !=  NETC_ETHSWT_IP_TYPES_VENDOR_ID)
    #error "Netc_EthSwt_Ip.h and Netc_EthSwt_Ip_Types.h have different vendor ids"
#endif
#if (( NETC_ETHSWT_IP_AR_RELEASE_MAJOR_VERSION    !=  NETC_ETHSWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( NETC_ETHSWT_IP_AR_RELEASE_MINOR_VERSION    !=  NETC_ETHSWT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( NETC_ETHSWT_IP_AR_RELEASE_REVISION_VERSION !=  NETC_ETHSWT_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Netc_EthSwt_Ip.h and Netc_EthSwt_Ip_Types.h are different"
#endif
#if (( NETC_ETHSWT_IP_SW_MAJOR_VERSION !=  NETC_ETHSWT_IP_TYPES_SW_MAJOR_VERSION) || \
     ( NETC_ETHSWT_IP_SW_MINOR_VERSION !=  NETC_ETHSWT_IP_TYPES_SW_MINOR_VERSION) || \
     ( NETC_ETHSWT_IP_SW_PATCH_VERSION !=  NETC_ETHSWT_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Netc_EthSwt_Ip.h and Netc_EthSwt_Ip_Types.h are different"
#endif

/* Checks against Netc_EthSwt_Ip_Cfg.h */
#if (NETC_ETHSWT_IP_VENDOR_ID !=  NETC_ETHSWT_IP_CFG_VENDOR_ID)
    #error "Netc_EthSwt_Ip.h and Netc_EthSwt_Ip_Cfg.h have different vendor ids"
#endif
#if (( NETC_ETHSWT_IP_AR_RELEASE_MAJOR_VERSION    !=  NETC_ETHSWT_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     ( NETC_ETHSWT_IP_AR_RELEASE_MINOR_VERSION    !=  NETC_ETHSWT_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     ( NETC_ETHSWT_IP_AR_RELEASE_REVISION_VERSION !=  NETC_ETHSWT_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Netc_EthSwt_Ip.h and Netc_EthSwt_Ip_Cfg.h are different"
#endif
#if (( NETC_ETHSWT_IP_SW_MAJOR_VERSION !=  NETC_ETHSWT_IP_CFG_SW_MAJOR_VERSION) || \
     ( NETC_ETHSWT_IP_SW_MINOR_VERSION !=  NETC_ETHSWT_IP_CFG_SW_MINOR_VERSION) || \
     ( NETC_ETHSWT_IP_SW_PATCH_VERSION !=  NETC_ETHSWT_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Netc_EthSwt_Ip.h and Netc_EthSwt_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
#define NETC_ETHSWT_IP_NOMATCHEDPORTMACADDR                (255U)
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define ETHSWT_43_NETC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "EthSwt_43_NETC_MemMap.h"

/** @brief   Export NETC ETHSWT configurations. */
NETC_ETHSWT_CONFIG_EXT

#define ETHSWT_43_NETC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "EthSwt_43_NETC_MemMap.h"

extern SW_PORT0_Type *Netc_EthSwt_Ip_SW0_PortxBaseAddr[NETC_ETHSWT_IP_NUMBER_OF_PORTS];


#define NETC_ETHSWT_IP_MACADDRLEN  (6U)                             /*!< mac addr length */
#define NETC_ETHSWT_IP_BITMAPLEN   (24U)                            /*!< bit map length */
#define NETC_ETHSWT_IP_32BIT_SHIFT (32U)                            /*!< 32 bits shift */
#define NETC_ETHSWT_IP_24BIT_SHIFT (24U)                            /*!< 24 bits shift */
#define NETC_ETHSWT_IP_16BIT_SHIFT (16U)                            /*!< 16 bits shift */
#define NETC_ETHSWT_IP_8BIT_SHIFT  (8U)                             /*!< 8 bits shift */

#define NETC_ETHSWT_IP_16BIT_BYTE_SWAP(x)  ((((x) >> NETC_ETHSWT_IP_8BIT_SHIFT) & 0xFFU) | (((x) & 0xFFU) << NETC_ETHSWT_IP_8BIT_SHIFT))

#define NETC_ETHSWT_IP_0XFF_MASK                           (0xFFU)
#define NETC_ETHSWT_IP_0XFFFF_MASK                         (0xFFFFU)
#define NETC_ETHSWT_IP_0XFFFF0000_MASK                     (0xFFFF0000UL)

#define NETC_ETHSWT_IP_CBDR_NUM                            (2U)      /*!< number of switch commang ring */
#define NETC_ETHSWT_IP_CBDR_0                              (0U)      /*!< switch command ring 0 */
#define NETC_ETHSWT_IP_CBDR_1                              (1U)      /*!< switch command ring 1 */

#define NETC_ETHSWT_IP_CBDR0_LENGTH                        (2U)      /*!< size of command ring 0. 2 means the size is 16 because it is in sets of 8 BDs */
#define NETC_ETHSWT_IP_SET_OF_BD                           (8U)       /*!< set of BD */
#define NETC_ETHSWT_IP_ACTUAL_CBDR0_LENGTH                 ((NETC_ETHSWT_IP_CBDR0_LENGTH) * (NETC_ETHSWT_IP_SET_OF_BD)) /*!< CBDR0 length */
#define NETC_ETHSWT_IP_CBDR1_LENGTH                        (2U)      /*!< size of command ring 1. 2 means the size is 16 because it is in sets of 8 BDs */
#define NETC_ETHSWT_IP_ACTUAL_CBDR1_LENGTH                 ((NETC_ETHSWT_IP_CBDR1_LENGTH) * 8U) /*!< CBDR1 length */

#define NETC_ETHSWT_IP_CBD_ALIGNED_SIZE                    (128U)    /*!< 128-byte aligned memory for command buffer descriptors */
#define NETC_ETHSWT_IP_TABLE_ALIGNED_SIZE                  (16U)     /*!< 16-byte aligned memory for command tables */

/* Macros for NTMP request message header */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION       (2U)      /*!< protocol version = 0x2 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_NTMP_PROTOCOL_VERSION  (1U)      /*!< NTMP version is 2.0 */

/* MDIO related defines */
#define NETC_ETHSWT_IP_MDIO_CLK_DIV                        (200U)   /*!< MDIO clock divisor, it has to be set to 0x40 */
#define NETC_ETHSWT_IP_MDIO_REG_READ_FLAG                  (0x80000003U)    /*!< An MDIO transaction is occurring, and MDIO read error occurs */
#define NETC_ETHSWT_IP_MDIO_REG_WRITE_FLAG                 (0x80000001U)    /*!< An MDIO transaction is occurring  */
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define ETHSWT_43_NETC_START_SEC_CODE
#include "EthSwt_43_NETC_MemMap.h"

/**
* @brief            Ethernet Switch switch initialization function.
* @details          Initializes the indexed swtich with a given configuration for the switch index
*                   EthSwt_Ip_Init shall:
*                   - Configure all configuration parameters (e.g. port structure, VLAN configuration, ...)
*                     at all ports of the switch and the switch itself.
*                   - Perform a soft reset
*
* @param[in]        SwitchIdx   Index of the switch within the context of the Ethernet Switch Driver
*                   Config      Structure for the initialization
*
* @return           Result of the operation
* @retval           E_OK        success
* @retval           E_NOT_OK    switch could not be initialized
*/
Std_ReturnType Netc_EthSwt_Ip_Init(uint8 SwitchIdx, const Netc_EthSwt_Ip_ConfigType * Config);


/**
* @brief            Ethernet Switch switch function for starting TSN.
* @details          This function enables the statically configured TSN settings. If stream gating or time aware shaping is used, the API must be called after the clock is synchronized.
*                   EthSwt_Ip_StartTSN shall:
*                   - Populate all tables related to 802.1cb and 802.1qci .
*
* @param[in]        SwitchIdx   Index of the switch within the context of the Ethernet Switch Driver
*
* @return           Result of the operation
* @retval           E_OK        success
* @retval           E_NOT_OK    TSN could not be started
*/
Std_ReturnType Netc_EthSwt_Ip_StartTSN(uint8 SwitchIdx);

/**
* @brief            Ethernet Switch function to prepare the IPF table for PTP
* @details          Add hardcoded entries to the Ingress Port Filter table to redirect frames with PTP-specific DMACs
*
* @param[in]        SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
*
* @return           Result of the operation
* @retval           E_OK        success
* @retval           E_NOT_OK    entries could not be added
*/
Std_ReturnType Netc_EthSwt_Ip_ConfigIngressPortFilterForTimestamping(uint8 SwitchIdx);

/**
 * @brief   Ethernet Switch read transceiver register function.
 * @details Generic API for reading the content of a transceiver register.
 *
 * @param[in]  SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]  TrcvIdx         Index of the transceiver referenced by port
 * @param[in]  RegIdx          Index of the register
 * @param[out] RegVal          Pointer to the register content
 *
 * @return Result of the operation
 * @retval E_OK        success
 * @retval E_NOT_OK    Register could not be read
 */
Std_ReturnType Netc_EthSwt_Ip_ReadTrcvRegister( uint8 SwitchIdx, uint8 TrcvIdx, uint8 RegIdx, uint16 * RegVal );

/**
 * @brief   Ethernet Switch write transceiver reg function.
 * @details Generic API for writing the content of a transceiver register
 *
 * @param[in] SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
 * @param[in] TrcvIdx         Index of the transceiver referenced by port
 * @param[in] RegIdx          Index of the register
 * @param[in] RegVal          Content for the indexed register
 *
 * @return Result of the operation
 * @retval E_OK        success
 * @retval E_NOT_OK    Register could not be written to
 */
Std_ReturnType Netc_EthSwt_Ip_WriteTrcvRegister( uint8 SwitchIdx, uint8 TrcvIdx, uint8 RegIdx, uint16 RegVal );

/**
 * @brief   Ethernet Switch Set switch port mode function
 * @details Generic API for enabling/disabling ports
 *
    @param[in]      SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
*                   SwitchPortIdx   Index of the switch's port which is to be set
*                   PortEnable      FALSE: the port of the switch is disabled
*                                   TRUE: the port of the switch is enabled
 *
 * @return Result of the operation
 * @retval E_OK        success
 * @retval E_NOT_OK    The indexed switch port could not be set to PortMode
 */
Std_ReturnType Netc_EthSwt_Ip_SetPortMode(uint8 SwitchIdx,
                                          uint8 SwitchPortIdx,
                                          boolean PortEnable);

/**
* @brief            Ethernet Switch Get switch port mode function.
* @details          Obtains the mode of the indexed switch port
*                   The function EthSwt_GetPortMode shall read the mode of the indexed port of the switch.
*
* @param[in]        SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
*                   SwitchPortIdx   Index of the port at the addressed switch
*
* @param[out]       PortEnable     FALSE: the port of the switch is disabled
*                                  TRUE: the port of the switch is enabled
*
* @return           Result of the operation
* @retval           E_OK        success
* @retval           E_NOT_OK    The mode of the indexed switch port could not be obtained.
*/
Std_ReturnType Netc_EthSwt_Ip_GetPortMode( uint8 SwitchIdx,
                                           uint8 SwitchPortIdx,
                                           boolean *PortEnable
                                           );

/**
* @brief            Ethernet Switch get baud rate function.
* @details          Obtains the baud rate of the indexed switch port
*                   The function EthSwt_GetBaudRate shall read the current baud rate of the indexed switch port.
*
* @param[in]        SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
*                   SwitchPortIdx   Index of the port at the addressed switch
*
* @param[out]       BaudRate     ETHTRCV_BAUD_RATE_10MBIT: 10MBit connection
*                                ETHTRCV_BAUD_RATE_100MBIT: 100MBit connection
*                                ETHTRCV_BAUD_RATE_1000MBIT: 1000MBit connection
*
* @return           Result of the operation
* @retval           E_OK        success
* @retval           E_NOT_OK    Baud rate of the indexed switch port could not be obtained
*/
Std_ReturnType Netc_EthSwt_Ip_GetPortSpeed( uint8 SwitchIdx,
                                            uint8 SwitchPortIdx,
                                            EthTrcv_BaudRateType * BaudRate
                                          );

/**
* @brief            Ethernet Switch set baud rate function.
* @details          Set the baud rate of the indexed switch port
*                   The function EthSwt_SetBaudRate shall set the current baud rate of the indexed switch port.
*
* @param[in]        SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
*                   SwitchPortIdx   Index of the port at the addressed switch
*                   BaudRate     ETHTRCV_BAUD_RATE_10MBIT: 10MBit connection
*                                ETHTRCV_BAUD_RATE_100MBIT: 100MBit connection
*                                ETHTRCV_BAUD_RATE_1000MBIT: 1000MBit connection
*
* @return           Result of the operation
* @retval           E_OK        success
* @retval           E_NOT_OK    Baud rate of the indexed switch port could not be changed
*/
Std_ReturnType Netc_EthSwt_Ip_SetPortSpeed( uint8 SwitchIdx, uint8 SwitchPortIdx, EthTrcv_BaudRateType BaudRate);

/**
* @brief            Ethernet Switch get duplex mode function.
* @details          Obtains the duplex mode of the indexed switch port
*                   The function EthSwt_GetDuplexMode shall read the current duplex mode of the indexed switch
*                   port.
*
* @param[in]        SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
*                   SwitchPortIdx   Index of the port at the addressed switch
*
* @param[out]       DuplexModePtr   ETHTRCV_DUPLEX_MODE_HALF: half duplex connections
*                                   ETHTRCV_DUPLEXMODE_FULL: full duplex connection
*
* @return           Result of the operation
* @retval           E_OK        success
* @retval           E_NOT_OK    duplex mode of the indexed switch port could not be obtained
*/
Std_ReturnType Netc_EthSwt_Ip_GetDuplexMode( uint8 SwitchIdx,
                                             uint8 SwitchPortIdx,
                                             EthTrcv_DuplexModeType * DuplexMode
                                           );

/**
 * @brief       This function sets the MAC address of a certain
 * @details     This will be used to set the MAC address asignated to a certain port of the switch
 *
 * @param[in]  SwitchIndex  the index of the switch
 * @param[in]  PortIndex    the index of the port
 * @param[in]  MacAddr      The physical address of the port
 *
 * @return     Result of the operation
 * @retval     E_OK       Success
 * @retval     E_NOT_OK   MAC Address could not be changed
 */
Std_ReturnType Netc_EthSwt_Ip_SetMacAddr(uint8 SwitchIdx, uint8 PortIndex, const uint8 *MacAddr);

/**
 * @brief       This function reads the MAC address of a certain port
 * @details     This will be used to read the MAC address asignated to a certain port of the switch
 *
 * @param[in]  SwitchIndex  the index of the switch
 * @param[in]  PortIndex    the index of the port
 * @param[out] MacAddr      The physical address of the port
 */
void Netc_EthSwt_Ip_GetMacAddr(uint8 SwitchIdx, uint8 PortIndex, uint8 *MacAddr);

/**
* @brief            Ethernet Switch get port MAC address function.
* @details          Obtains the port over which this MAC-address at the indexed switch can be reached.
*                   The result might be used for a DHCP-server which will need the port - MAC-resolution.
*                   If for the PortIdxPtr the maximal possible value (255) is returned the given MAC address cannot
*                   be reached via a port of this switch. If multiple ports were found the API returns E_NOT_OK.
*
* @param[in]        SwitchIdx    The switch index
*                   cbdrIndex:   Index of switch command BD rings
*                   Fid:         Filtering ID
*                   MacAddr      MAC-address for which a switch port is searched over which the node with this
*                                MAC-address can be reached.
*
* @param[out]       PortIdxPtr      Pointer to the port index
*
* @return           Result of the operation
* @retval           E_OK        success
* @retval           E_NOT_OK    multiple ports were found
*/
Std_ReturnType Netc_EthSwt_Ip_GetPortMacAddr( uint8 SwitchIdx, uint16 Fid, const uint8 * MacAddr, uint8 * PortIdx);


/**
* @brief            Ethernet Switch get counter values function.
* @details          Reads a list with drop counter values of the corresponding port of the switch.
*                   The meaning of these values is described at Netc_EthSwt_Ip_CounterType.
*
* @param[in]        SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
*                   SwitchPortIdx   Index of the port at the addressed switch
*
* @param[out]       Counter      counter values. The meaning of these values is described at Netc_EthSwt_Ip_CounterType
*
* @return           Result of the operation
* @retval           E_OK        success
* @retval           E_NOT_OK    counter values read failure
*/
Std_ReturnType Netc_EthSwt_Ip_GetCounters( uint8 SwitchIdx, uint8 SwitchPortIdx, Netc_EthSwt_Ip_CounterType *Counter );

/**
* @brief            Ethernet Switch get counter values for each MAC function.
* @details          Reads a list with drop counter values for each MAC of the corresponding port of the switch.
*                   The meaning of these values is described at Netc_EthSwt_Ip_CounterType.
*                   For pseudoports with one pseduoMAC, only the first element of the counter array gets populated.
*
* @param[in]        SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
*                   SwitchPortIdx   Index of the port at the addressed switch
*
* @param[out]       Counter      Array for counter values. Position 0 contains counters for MAC0(EMAC) and position 1 for MAC1(PMAC).
*                                The meaning of these values is described at Netc_EthSwt_Ip_CounterType
*
* @return           Result of the operation
* @retval           E_OK        success
* @retval           E_NOT_OK    counter values read failure
*/
Std_ReturnType Netc_EthSwt_Ip_GetAllCounters( uint8 SwitchIdx, uint8 SwitchPortIdx, Netc_EthSwt_Ip_CounterType Counters[2U] );

/**
 * @brief         Ethernet Switch get single counter value function.
 * @details       Reads a single drop counter value from the corresponding port of the switch.
 *                The meaning of these values is described at Netc_EthSwt_Ip_SingleCounterType.
 *
 * @param[in]     SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
 *                SwitchPortIdx   Index of the port at the addressed switch
 *
 * @param[in]    Counter         single counter register offset
 *
 * @return       Single counter value. The meaning of these values is described at Netc_EthSwt_Ip_SingleCounterType.
 */
Netc_EthSwt_Ip_CounterValueType Netc_EthSwt_Ip_GetCounter( uint8 SwitchIdx, uint8 SwitchPortIdx, Netc_EthSwt_Ip_SingleCounterType Counter );

/**
* @brief            Ethernet switch enable VLAN function.
* @details          Enables or disables a pre-configured VLAN at a certain port of a switch.
*
* @param[in]        SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
*                   SwitchPortIdx   Index of the port at the addressed switch
*                   VlanId          VLAN-ID to a preconfigured configuration on the given ingress port
*                   Enable          1 = VLAN-configuration enabled
*                                   0 = VLAN-configuration disabled (frames with given VLAN-ID will be dropped)
*
* @return           Result of the operation
* @retval           E_OK        success
* @retval           E_NOT_OK    Query command error or no mached Vlan ID entry found
*/
Std_ReturnType Netc_EthSwt_Ip_EnableVlan( uint8 SwitchIdx, uint8 SwitchPortIdx, uint16 VlanId, boolean Enable );

/**
* @brief            Ethernet switch set MAC learning mode function.
* @details          Sets the MAC learning mode in one of the tree modes:
*                   1) HW learning enabled
*                   2) Hardware learning disabled
*
* @param[in]        SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
* @param[in]        MacLearningMode Defines whether MAC addresses shall be learned and if they shall be learned in software or hardware
*
* @return           Result of the operation
* @retval           E_OK        success
* @retval           E_NOT_OK    MAC learning mode could not be set
*/
Std_ReturnType Netc_EthSwt_Ip_SetMacLearningMode( uint8 SwitchIdx, Netc_EthSwt_Ip_MacLearningOptionType MacLearningMode );

/**
* @brief            Ethernet switch get MAC learning mode function.
* @details          Returns the MAC learning mode:
*                   1) HW learning enabled
*                   2) Hardware learning disabled
*
* @param[in]        SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
*
* @param[out]       MacLearningMode Defines whether MAC addresses shall be learned and if they shall be learned in software or hardware
*
* @return           Result of the operation
* @retval           E_OK        success
* @retval           E_NOT_OK    MAC learning mode could not be read
*/
Std_ReturnType Netc_EthSwt_Ip_GetMacLearningMode( uint8 SwitchIdx, Netc_EthSwt_Ip_MacLearningOptionType * MacLearningMode );

/**
* @brief            Ethernet switch get loopback state function.
* @details          Obtain the current status of the port loopback for the indexed external Ethernet switch port
*
* @param[in]        SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
* @param[in]        SwitchPortIdx   Index of the port at the addressed switch
*
* @param[out]       LoopbackEnable  Pointer to the memory where the port loopback mode true/false
*
* @return           Result of the operation
* @retval           E_OK        the requested port loopback state for the indexed Ethernet switch port was set successfully.
* @retval           E_NOT_OK    the port loopback configuration for the indexed Ethernet switch returned not successfully.
*                               (i.e. indexed ethernet switch is not available)
*/
Std_ReturnType Netc_EthSwt_Ip_PortGetLoopbackMode( uint8 SwitchIdx,
                                                   uint8 SwitchPortIdx,
                                                   boolean * LoopbackEnable
                                                  );

/**
* @brief            Ethernet switch set loopback state function.
* @details          Set the current state of port loopback for the indexed Ethernet external switch port
*
* @param[in]        SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
*                   SwitchPortIdx   Index of the port at the addressed switch
*                   LoopbackEnable  Contain the requested port loopback mode
*
* @return           Result of the operation
* @retval           E_OK        the port loopback state for the indexed Ethernet switch port was set successfully.
* @retval           E_NOT_OK    the port loopback configuration for the indexed Ethernet switch was not set successfully.
*                               (i.e. indexed ethernet switch is not available)
*/
Std_ReturnType Netc_EthSwt_Ip_PortSetLoopbackMode( uint8 SwitchIdx,
                                                   uint8 SwitchPortIdx,
                                                   boolean LoopbackEnable
                                                  );

/**
 * @brief            Reset configuration of switch
 * @details          External function for reseting the learned entries from the FDB table of the switch..
 *
 * @param[in]        SwitchIdx  Index of the switch within the context of the Ethernet Switch Driver
 *
 * @return           Result of the operation
 * @retval           E_OK :  reset dynamic FDB entries successfully
 * @retval           E_NOT_OK : fail to reset dynamic FDB entries
 */
Std_ReturnType Netc_EthSwt_Ip_ResetConfiguration(uint8 SwitchIdx);

/**
 * @brief            Get Fdb Table Entry List function
 * @details          External function for getting existing FDB table entries in command ring 0.
 *                   Provide the static entries first and then the dynamic entries if the value of NumberOfElements is not 0.
 *
 * @param[in]        SwitchIdx        Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        NumberOfElements Maximum number of entries which can be written into the FdbTableList
 * @param[out]       NumberOfElements Number of available entries which are currently be written into the FdbTableList
 * @param[out]       FdbTableList     A pointer points to a list of FDB entry structure Netc_EthSwt_Ip_FdbEntryDataType
 *
 * @return           Result of the operation
 * @retval           0 :  success
 * @retval           others : fail
 */
Std_ReturnType Netc_EthSwt_Ip_GetFdbTable(uint8 SwitchIdx, uint16 * NumberOfElements, Netc_EthSwt_Ip_FdbEntryDataType * FdbTableList);

/**
 * @brief            Search Fdb Table Entry function
 * @details          External function for searching existing FDB table entries one by one in command ring 0.
 *
 * @param[in]        SwitchIdx          Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        ResumeEntryId      To start the search, ResumeEntryId should be set to 0xFFFFFFFF
 * @param[in]        SearchCriteriaData The data of match criteria and match data. To start a specific search, you have to fill in SearchCriteriaData with Netc_EthSwt_Ip_FDBTableMatchCriteriaDataType
 *                                      and its corresponding match data (ACTE data, CFGE data or KEYE data).
 * @param[out]       ResumeEntryId      The next valid Entry ID that is used to continue the search. If ResumeEntryId equals 0xFFFFFFFF, then that means (a)the search is completed
 *                                      or (b)there is no matched entry found.
 * @param[out]       FdbTableEntry      A pointer points to a FDB entry structure Netc_EthSwt_Ip_FdbEntryDataType.
 *
 * @return           Result of the operation
 * @retval           0 :  success
 * @retval           others : fail
 */
Std_ReturnType Netc_EthSwt_Ip_SearchFdbTable( uint8 SwitchIdx,
                                              uint32 * ResumeEntryId,
                                              const Netc_EthSwt_Ip_FDBTableSearchCriteriaDataType * SearchCriteriaData,
                                              Netc_EthSwt_Ip_FdbEntryDataType * FdbTableEntry
                                            );

/**
 * @brief            Query Fdb Table Entry function
 * @details          External function for querying one FDB entry with "Exact Match Key Element Match" access method.
 *                   That means only "Exact Match Key Element Match" access method is supported.
 *
 * @param[in]        SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries  Number of matched entry
 * @param[in]        FdbTableEntry   Pointer points to a FDB entry structure Netc_EthSwt_Ip_FdbEntryDataType
 *                                   which provides the data for "query" operation
 * @param[out]       FdbTableEntry   A pointer that returns the data of a matched entry by "query" operation
 *                                   The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryFdbTableEntry( uint8 SwitchIdx,
                                                                 uint32 *MatchedEntries,
                                                                 Netc_EthSwt_Ip_FdbEntryDataType * FdbTableEntry
                                                               );

/**
 * @brief            Delete Fdb Table Entry function
 * @details          External function for deleting one FDB entry with "Exact Match Key Element Match" access method.
 *                   That means only "Exact Match Key Element Match" access method is supported.
 *
 * @param[in]        SwitchIdx       Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries  Number of matched entry
 * @param[in]        FdbTableEntry   Pointer points to a FDB entry structure Netc_EthSwt_Ip_FdbEntryDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteFdbTableEntry( uint8 SwitchIdx,
                                                                  uint32 *MatchedEntries,
                                                                  const Netc_EthSwt_Ip_FdbEntryDataType * FdbTableEntry
                                                                );

/**
 * @brief            Add or Update Fdb Table Entry function
 * @details          External function for adding or updating one FDB entry with "Exact Match Key Element Match" access method.
 *                   That means only "Exact Match Key Element Match" access method is supported.
 *
 * @param[in]        SwitchIdx        Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        Cmd              Add, Update and AddOrUpdate commands are supported
 * @param[out]       MatchedEntries   Number of matched entries
 * @param[in]        FdbTableEntry    Pointer points to a FDB entry structure Netc_EthSwt_Ip_FdbEntryDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateFdbTableEntry( uint8 SwitchIdx, Netc_EthSwt_Ip_CommandsType Cmd, uint32 *MatchedEntries, const Netc_EthSwt_Ip_FdbEntryDataType * FdbTableEntry);

/**
 * @brief   Query the Switch Hardware Version
 * @details External function for Query Switch Hardware Version
 *
 * @param[in]  SwitchIdx  Index of the switch within the context of the Ethernet Switch Driver
 * @param[out] HwVersion  The switch hardware version.
 *
 * @return Result of the operation
 * @retval E_OK : success
 */
Std_ReturnType Netc_EthSwt_Ip_GetSwitchIdentifier(uint8 SwitchIdx, uint32 *HwVersion);

/**
 * @brief            Get Vlan filter Table Entry List function
 * @details          External function for getting existing Vlan filter table entries in command ring 0.
 *
 * @param[in]        SwitchIdx               Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        NumberOfElements        Maximum number of entries which can be written into the VlanFilterTableList
 * @param[out]       NumberOfElements        Number of available entries which are currently be written into the VlanFilterTableList
 * @param[out]       VlanFilterTableList     A pointer points to a list of Vlan filter entry structure Netc_EthSwt_Ip_VlanFilterEntryDataType
 *
 * @return           Result of the operation
 * @retval           0 :  success
 * @retval           others : fail
 */
Std_ReturnType Netc_EthSwt_Ip_GetVlanFilterTable( uint8 SwitchIdx, uint16 * NumberOfElements, Netc_EthSwt_Ip_VlanFilterEntryDataType * VlanFilterTableList );

/**
 * @brief            Add or Update Vlan Filter Table Entry function
 * @details          External function for adding or updating one Vlan Filter entry to command ring with "Exact Match Key Element Match" access method.
 *                   That means only "Exact Match Key Element Match" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        Cmd                    Add, Update and AddOrUpdate commands are supported
 * @param[out]       MatchedEntries         Number of matched entries
 * @param[in]        VlanFilterTableEntry:  Pointer points to a Vlan Filter entry structure Netc_EthSwt_Ip_VlanFilterEntryDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateVlanFilterTableEntry( uint8 SwitchIdx,
                                                                              Netc_EthSwt_Ip_CommandsType Cmd,
                                                                              uint32 *MatchedEntries,
                                                                              const Netc_EthSwt_Ip_VlanFilterEntryDataType * VlanFilterTableEntry
                                                                            );

/**
 * @brief            Query Vlan Filter Table Entry function
 * @details          External function for querying one Vlan Filter entry with "full query" and "Exact Match Key Element Match" access method.
 *                   That means only "Exact Match Key Element Match" access method is supported.
 *
 * @param[in]        SwitchIdx                Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries           Number of matched entries
 * @param[in]        VlanFilterTableEntry:    A pointer that provides the data needed by "query" operation, like Vlan Filter entry Id
 * @param[out]       VlanFilterTableEntry:    A pointer that returns the data of a matched entry by "query" operation
 *                                            The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryVlanFilterTableEntry( uint8 SwitchIdx,
                                                                        uint32 *MatchedEntries,
                                                                        Netc_EthSwt_Ip_VlanFilterEntryDataType * VlanFilterTableEntry
                                                                      );

/**
 * @brief            Delete Vlan Filter Table Entry function
 * @details          External function for deleting one Vlan Filter entry with "Exact Match Key Element Match" access method.
 *
 * @param[in]        SwitchIdx                Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries           Number of matched entries
 * @param[in]        VlanFilterTableEntryId:  Vlan Filter entry Id
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteVlanFilterTableEntry( uint8 SwitchIdx,
                                                                         uint32 *MatchedEntries,
                                                                         uint32 VlanFilterTableEntryId
                                                                       );

/**
 * @brief            Query Egress Count Table Entry function
 * @details          External function for querying one Egress Count entry with "Entry Id Match" access method.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       EntryId                Egress Counter Entry ID (EC_EID), an index to an entry in Egress Count Table.
 *                                          The EC_EID is specified in the Egress Treatment table.
 * @param[out]       MatchedEntries         Number of matched entries
 * @param[out]       StatisticsData:        Pointer points to an Egress Count entry structure Netc_EthSwt_Ip_ECTableStatisticsDataType.
 *                                          It contains the data of Enqueued Frame Count and Rejected Frame Count.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryEgressCountTableEntry( uint8 SwitchIdx,
                                                                         uint32 EntryId,
                                                                         uint32 *MatchedEntries,
                                                                         Netc_EthSwt_Ip_ECTableStatisticsDataType *StatisticsData
                                                                       );

#if (NETC_ETHSWT_NUMBER_OF_EGRESSTREATMENT_ENTRIES > 0U)
/**
 * @brief            Get Egress Count Table function
 * @details          External function for retrieving the whole Egress Count table.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entries
 * @param[out]       EgressCountTable       Pointer points to an EgressCount table structure Netc_EthSwt_Ip_ECTableStatisticsDataType.
 *                                          It contains the data of Enqueued Frame Count and Rejected Frame Count for each table entry.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_GetEgressCountTable(uint8 SwitchIdx, uint32 * MatchedEntries, Netc_EthSwt_Ip_ECTableStatisticsDataType * EgressCountTable);
#endif

/**
 * @brief            Reset Egress Count Table Entry function
 * @details          External function for reseting one Egress Count entry with "Entry Id Match" access method.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       EntryId                Egress Counter Entry ID (EC_EID), an index to an entry in Egress Count Table.
 *                                          The EC_EID is specified in the Egress Treatment table.
 * @param[out]       MatchedEntries         Number of matched entries.
 *                                          1: found a matched entry and reset the statistics data of the entry successfully.
 *                                          0: no matched entry found.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_ResetEgressCountTableEntry( uint8 SwitchIdx,
                                                                         uint32 EntryId,
                                                                         uint32 *MatchedEntries
                                                                       );

/**
 * @brief            Add or Update Egress Treatment Table Entry function
 * @details          External function for adding or updating one Egress Treatment entry to command ring with "Entry Id Match" access method.
 *                   That means only "Entry Id Match" access method is supported.
 *
 * @param[in]        SwitchIdx                  Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        Cmd                        Add, Update and AddOrUpdate commands are supported
 * @param[out]       MatchedEntries             Number of matched entries
 * @param[in]        EgressTreatmentTableEntry: Pointer points to a Egress Treatment entry structure Netc_EthSwt_Ip_EgressTreatmentEntryDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateEgressTreatmentTableEntry( uint8 SwitchIdx,
                                                                                   Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                   uint32 *MatchedEntries,
                                                                                   const Netc_EthSwt_Ip_EgressTreatmentEntryDataType * EgressTreatmentTableEntry
                                                                                 );

/**
 * @brief            Query Egress Treatment Table Entry function
 * @details          External function for querying one Egress Treatment entry with "Entry Id Match" access method.
 *
 * @param[in]        SwitchIdx                      Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        EgressTreatmentTableEntry      A pointer that provides the data needed by "query" operation
 * @param[out]       MatchedEntries                 Number of matched entries
 * @param[out]       EgressTreatmentTableEntry      A pointer that returns the data of a matched entry by "query" operation
 *                                                  The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryEgressTreatmentTableEntry( uint8 SwitchIdx,
                                                                             uint32 *MatchedEntries,
                                                                             Netc_EthSwt_Ip_EgressTreatmentEntryDataType * EgressTreatmentTableEntry
                                                                           );

/**
 * @brief            Delete Egress Treatment Table Entry function
 * @details          External function for deleting one Egress Treatment entry with "Entry Id Match" access method.
 *
 * @param[in]        SwitchIdx                      Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        EgressTreatmentTableEntryId    Egress Treatment Entry ID, an index to an entry in Egress Treatment Table.
 * @param[out]       MatchedEntries                 Number of matched entries
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteEgressTreatmentTableEntry( uint8 SwitchIdx,
                                                                              uint32 EgressTreatmentTableEntryId,
                                                                              uint32 *MatchedEntries
                                                                            );
/**
 * @brief            Add or Update Frame Modification Table Entry function
 * @details          External function for adding or updating one Frame Modification entry to command ring with "Entry Id Match" access method.
 *                   That means only "Entry Id Match" access method is supported.
 *
 * @param[in]        SwitchIdx                  Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        Cmd                        Add, Update and AddOrUpdate commands are supported
 * @param[out]       MatchedEntries             Number of matched entries
 * @param[in]        FrmModificationTableEntry: Pointer points to a Frame Modification entry structure Netc_EthSwt_Ip_FrmModificationEntryDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateFrmModificationTableEntry( uint8 SwitchIdx,
                                                                                   Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                   uint32 *MatchedEntries,
                                                                                   const Netc_EthSwt_Ip_FrmModificationEntryDataType * FrmModificationTableEntry
                                                                                 );

/**
 * @brief            Query Frame Modification Table Entry function
 * @details          External function for querying one Frame Modification entry with "Entry Id Match" access method.
 *
 * @param[in]        SwitchIdx                      Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        FrmModificationTableEntry      A pointer that provides the data needed by "query" operation
 * @param[out]       MatchedEntries                 Number of matched entries
 * @param[out]       FrmModificationTableEntry      A pointer that returns the data of a matched entry by "query" operation
 *                                                  The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryFrmModificationTableEntry( uint8 SwitchIdx,
                                                                             uint32 *MatchedEntries,
                                                                             Netc_EthSwt_Ip_FrmModificationEntryDataType * FrmModificationTableEntry
                                                                            );

/**
 * @brief            Delete Frame Modification Table Entry function
 * @details          External function for deleting one Frame Modification entry with "Entry Id Match" access method.
 *
 * @param[in]        SwitchIdx                      Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        FrmModificationEntryID         Frame Modification Entry ID, an index to an entry in Frame Modification Table.
 * @param[out]       MatchedEntries                 Number of matched entries
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteFrmModificationTableEntry( uint8 SwitchIdx,
                                                                              uint32 FrmModificationEntryID,
                                                                              uint32 *MatchedEntries
                                                                            );

/**
 * @brief            Add Ingress Port Filter Table Entry function
 * @details          External function for adding ingress port filter table entry to command ring with "NETC_ETHSWT_TERNARY_MATCH_KEY_ELEMENT_MATCH" access method.
 *
 * @param[in]        SwitchIdx                    Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries               Number of matched entries
 * @param[in]        IngressPortFilterTableEntry  Pointer points to an ingress port filter table entry structure Netc_EthSwt_Ip_IngressPortFilterEntryDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddIngressPortFilterTableEntry( uint8 SwitchIdx,
                                                                             uint32 *MatchedEntries,
                                                                             Netc_EthSwt_Ip_IngressPortFilterEntryDataType * IngressPortFilterTableEntry
                                                                           );

/**
 * @brief            Query Ingress Port Filter Table Entry function
 * @details          External function for querying one Ingress Port Filter Table entry with "Entry Id Match" access method.
 *
 * @param[in]        SwitchIdx                        Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        IngressPortFilterTableEntry      A pointer that provides the data needed by "query" operation, Entry_ID specifically
 * @param[out]       MatchedEntries                   Number of matched entries
 * @param[out]       IngressPortFilterTableEntry      A pointer that returns the data of a matched entry by "query" operation
 *                                                    The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryIngressPortFilterTableEntry( uint8 SwitchIdx,
                                                                               uint32 *MatchedEntries,
                                                                               Netc_EthSwt_Ip_IngressPortFilterEntryDataType * IngressPortFilterTableEntry
                                                                             );

/**
 * @brief            Delete Ingress Port Filter Table Entry function
 * @details          External function for deleting one Ingress Port Filter entry with "Entry Id Match" access method.
 *
 * @param[in]        SwitchIdx                      Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        IngressPortFilterEntry         Ingress Port Filter Entry ID
 * @param[out]       MatchedEntries                 Number of matched entries
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteIngressPortFilterTableEntry( uint8 SwitchIdx,
                                                                                uint32 *MatchedEntries,
                                                                                uint32 IngressPortFilterEntry
                                                                              );

/**
 * @brief            Enable Ingress Port Filter Table Entry lookup function for ports
 * @details          External function for enabling Ingress Port Filter entry lookup functions for ports.
 *
 * @param[in]        SwitchIdx                      Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        SwitchPortIdx                  Index of the port at the addressed switch
 * @param[in]        Enable                         Enable or disable the lookup function
 *
 * @return           Result of the operation
 * @retval           E_OK : success
 * @retval           others : fail
 */
Std_ReturnType Netc_EthSwt_Ip_EnableIngressPortFiltering( uint8 SwitchIdx, uint8 SwitchPortIdx, boolean Enable );

/**
 * @brief            Enable/disable Switch mirroring
 * @details          External function for setting mirroring state for the switch.
 *
 * @param[in]        SwitchIdx                      Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        MirrorState                    0: switch mirroring disabled. 1: switch mirroring enabled.
 *
 * @return           Result of the operation
 * @retval           E_OK : success
 * @retval           others : fail
 */
Std_ReturnType Netc_EthSwt_Ip_SetMirrorState( uint8 SwitchIdx, Netc_EthSwt_Ip_SwitchMirrorStateType MirrorState );

/**
 * @brief            Obtain Switch mirroring state
 * @details          External function for obtaining mirroring state of the switch.
 *
 * @param[in]        SwitchIdx                      Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MirrorStatePtr                 0: switch mirroring disabled. 1: switch mirroring enabled.
 *
 * @return           Result of the operation
 * @retval           E_OK : success
 * @retval           others : fail
 */
Std_ReturnType Netc_EthSwt_Ip_GetMirrorState( uint8 SwitchIdx, Netc_EthSwt_Ip_SwitchMirrorStateType *MirrorStatePtr );

/**
 * @brief            Write mirror configuration
 * @details          External function for writing mirror configuration to the switch.
 *
 * @param[in]        MirroredSwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        MirrorConfigurationPtr         A Netc_EthSwt_Ip_SwitchMirrorCfgType pointer with the configuration data of mirroring
 *
 * @return           Result of the operation
 * @retval           E_OK : success
 * @retval           others : fail
 */
Std_ReturnType Netc_EthSwt_Ip_WriteMirrorConfiguration( uint8 MirroredSwitchIdx, const Netc_EthSwt_Ip_SwitchMirrorCfgType* MirrorConfigurationPtr );

/**
 * @brief            Read mirror configuration
 * @details          External function for obtaining mirror configuration of the switch.
 *
 * @param[in]        MirroredSwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MirrorConfigurationPtr         A Netc_EthSwt_Ip_SwitchMirrorCfgType pointer with the configuration data of mirroring
 *
 * @return           Result of the operation
 * @retval           E_OK : success
 * @retval           others : fail
 */
Std_ReturnType Netc_EthSwt_Ip_ReadMirrorConfiguration( uint8 MirroredSwitchIdx, Netc_EthSwt_Ip_SwitchMirrorCfgType* MirrorConfigurationPtr );

/**
 * @brief            Delete mirror configuration
 * @details          External function for deleting the mirror configuration of the switch.
 *
 * @param[in]        MirroredSwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 *
 * @return           Result of the operation
 * @retval           E_OK : success
 * @retval           others : fail
 */
Std_ReturnType Netc_EthSwt_Ip_DeleteMirrorConfiguration( uint8 MirroredSwitchIdx );

/**
 * @brief            Set the egress frame preemption feature for a port
 * @details          Set express and preemptive traffic classes for a port
 *
 * @param[in]         SwitchIdx                     Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]         SwitchPortIdx                 Index of the port at the addressed switch
 * @param[in]         TrafficClass                  Flags to mark traffic classes as express (0) or preemptive (1)
 *
 * @return           Result of the operation
 * @retval           E_OK : success
 * @retval           others : fail
 */
Std_ReturnType Netc_EthSwt_Ip_ConfigureEgressFramePreemption(uint8 SwitchIdx, const uint8 SwitchPortIdx, const boolean TrafficClass[8U]);

/**
 * @brief            Enable egress frame preemption for a port
 * @details          The egress frame preemption is Enable/Disable
 *
 * @param[in]         SwitchIdx                     Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]         SwitchPortIdx                 Index of the port at the addressed switch
 * @param[in]         Enable                        TRUE: enable egress frame preemption on the port. FALSE: disable egress frame preemption on the port.
 *
 * @return           Result of the operation
 * @retval           E_OK : success
 * @retval           others : fail
 */
Std_ReturnType Netc_EthSwt_Ip_EnableEgressFramePreemption(uint8 SwitchIdx, const uint8 SwitchPortIdx, const boolean Enable);

/**
 * @brief            Set the credit based shaper slope
 * @details          Set the idle slope for the credit based shaper
 *
 * Parameters:
 * -[in]     SwitchIdx           Index of the switch within the context of the Ethernet Switch Driver
 * -[in]     SwitchPortIdx   Index of the port at the addressed switch
 * -[in]     TrafficClass        The value range is 0 to 7
 * -[in]     idleSlope            Idleslope is the rate of credits that is accumulated (in bits per second)  when there  is  at  least  one packet waiting for transmission.
 *
 * @return           Result of the operation
 * @retval           E_OK : success
 * @retval           others : fail
 */
Std_ReturnType Netc_EthSwt_Ip_ConfigureCreditBasedShaper(uint8 SwitchIdx, const uint8 SwitchPortIdx, const uint8 TrafficClass, const uint64 idleSlope);

/**
 * @brief            Enable credit based shaper
 * @details          The credit base shaper TrafficClass is Enable/Disable
 *
 * Parameters:
 * -[in]     SwitchIdx            Index of the switch within the context of the Ethernet Switch Driver
 * -[in]     SwitchPortIdx    Index of the port at the addressed switch
 * -[in]     TrafficClass         The value range is 0 to 7
 * -[in]     Enable                  TRUE: enable credit based shaper on the port. FALSE: disable credit based shaper on the port.
 *
 * @return           Result of the operation
 * @retval           E_OK : success
 * @retval           others : fail
 */
Std_ReturnType Netc_EthSwt_Ip_EnableCreditBasedShaper(uint8 SwitchIdx, const uint8 SwitchPortIdx, const uint8 TrafficClass, const boolean Enable);

/**
 * @brief            Add or Update Time Gate Scheduling Table Entry function
 * @details          External function for adding/updating time gate scheduling table entry to command ring with "NETC_ETHSWT_ENTRY_ID_MATCH" access method.
 *
 * @param[in]        SwitchIdx                    Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        TimeGateSchedulingTableEntry Pointer points to an time gate scheduling table entry structure Netc_EthSwt_Ip_TimeGateSchedulingEntryDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateTimeGateSchedulingTableEntry( uint8 SwitchIdx,
                                                                                      const Netc_EthSwt_Ip_TimeGateSchedulingEntryDataType *TimeGateSchedulingTableEntry
                                                                                    );

/**
 * @brief            Enable or disable Time Gate Scheduling on a switch port.
 * @details          External function for enabling/disabling time gate scheduling on a switch port.
 *
 * @param[in]        SwitchIdx            Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        SwitchPortIdx        Index of the port at the addressed switch
 * @param[in]        Enable               Enable or disable the time gate scheduling
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_ConfigPortTimeGateScheduling( uint8 SwitchIdx,
                                                                           uint8 SwitchPortIdx,
                                                                           boolean Enable
                                                                         );

/**
 * @brief            Set the mac layer duplex mode on a switch port.
 * @details
 *
 * @param[in]        SwitchIdx                      Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        SwitchPortIdx                  Index of the port at the addressed switch
 * @param[in]        EthSwtPortMacLayerDuplexMode   1 : full duplex mode; 0 : half duplex mode
 *
 * @return          Result of the operation
 * @retval          E_OK        success
 * @retval          E_NOT_OK    fail to set the duplx mode
 */
Std_ReturnType Netc_EthSwt_Ip_SetPortMacLayerDuplexMode( uint8 SwitchIdx,
                                                         uint8 SwitchPortIdx,
                                                         Netc_EthSwt_Ip_PortDuplexType EthSwtPortMacLayerDuplexMode
                                                       );
/**
 * @brief            Periodically called function to age the FDB entries.
 * @details
 *
 * @param[in]        SwitchIdx                      Index of the switch within the context of the Ethernet Switch Driver
 *
 */
void Netc_EthSwt_Ip_MainFunction( uint8 SwitchIdx );

/*
 * @brief            Set the pruning mode on a switch port.
 * @details
 *
 * @param[in]        SwitchIdx                      Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        SwitchPortIdx                  Index of the port at the addressed switch
 * @param[in]        PruningEnable                  TRUE : pruning is enabled; FALSE : pruning is disabled;
 *
 * @return          Result of the operation
 * @retval          E_OK        success
 * @retval          E_NOT_OK    fail to set the pruning mode
 */
Std_ReturnType Netc_EthSwt_Ip_SetPruningMode(uint8 SwitchIdx, uint8 SwitchPortIdx, boolean PruningEnable);

/**
 * @brief            Get the pruning mode on a switch port.
 * @details
 *
 * @param[in]        SwitchIdx                      Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        SwitchPortIdx                  Index of the port at the addressed switch
 * @param[out]       PruningEnablePtr               TRUE : pruning is enabled; FALSE : pruning is disabled;
 *
 * @return          Result of the operation
 * @retval          E_OK        success
 * @retval          E_NOT_OK    fail to get the pruning mode
 */
Std_ReturnType Netc_EthSwt_Ip_GetPruningMode(uint8 SwitchIdx, uint8 SwitchPortIdx, boolean *PruningEnablePtr);

/**
 * @brief            Retrieve time of free-running clock in the switch.
 * @details
 *
 * @param[in]        SwitchIdx          Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       PtpTime            ptpTime Time of the free-running clock
 *
 * @return          Result of the operation
 * @retval          E_OK        success
 * @retval          E_NOT_OK    fail to get the time of free-running clock
 */
Std_ReturnType Netc_EthSwt_Ip_GetPtpTSClk( uint8 SwitchIdx, Netc_EthSwt_Ip_PtpTimeType *PtpTime );

/**
 * @brief            Retrieve time of corrected clock (synchronized time) in the switch.
 * @details
 *
 * @param[in]        SwitchIdx          Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       PtpTime            ptpTime Time of the corrected clock
 *
 * @return          Result of the operation
 * @retval          E_OK        success
 * @retval          E_NOT_OK    fail to get the time of corrected clock
 */
Std_ReturnType Netc_EthSwt_Ip_GetPtpClk( uint8 SwitchIdx, Netc_EthSwt_Ip_PtpTimeType *PtpTime );

/**
 * @brief            Retrieve both time of free-running clock and corrected clock (synchronized time) in the switch.
 * @details
 *
 * @param[in]        SwitchIdx          Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       FreeRunTime        Time of the free-running clock
 * @param[out]       CorrTime           Time of the corrected clock
 *
 * @return          Result of the operation
 * @retval          E_OK        success
 * @retval          E_NOT_OK    fail to get the time of free-running and corrected clock
 */
Std_ReturnType Netc_EthSwt_Ip_GetPtpTimes( uint8 SwitchIdx, Netc_EthSwt_Ip_PtpTimeType *FreeRunTime, Netc_EthSwt_Ip_PtpTimeType *CorrTime );

/**
 * @brief            Set a clk ratio for the corrected clock in the switch.
 * @details
 *
 * @param[in]        SwitchIdx          Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        ClkRatio           is a fixed-point clock rate value with a single-bit integer part and a 31-bit fractional part.
 *
 * @return          Result of the operation
 * @retval          E_OK        success
 * @retval          E_NOT_OK    fail to set the clk ratio
 */
Std_ReturnType Netc_EthSwt_Ip_SetPtpClkRatio( uint8 SwitchIdx, uint32 ClkRatio );

/**
 * @brief            Add/Subtract an offset to/from the corrected clock (PTP_CLK).
 * @details
 *
 * @param[in]        SwitchIdx          Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        Offset             signed value, to add or substract from the offset register.
 *
 * @return          Result of the operation
 * @retval          E_OK        success
 * @retval          E_NOT_OK    fail to correct the offset
 */
Std_ReturnType Netc_EthSwt_Ip_CorrectPtpClk( uint8 SwitchIdx, sint64 Offset );

/**
 * @brief            Add or Update Rate Policer Table Entry function
 * @details          External function for adding or updating one Rate Policer entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx        Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        Cmd              Add and Update commands are supported
 * @param[out]       MatchedEntries   Number of matched entries
 * @param[in]        RatePolicerTableEntry    Pointer points to a Rate policer entry structure Netc_EthSwt_Ip_RatePolicerEntryDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateRatePolicerTableEntry( uint8 SwitchIdx,
                                                                               Netc_EthSwt_Ip_CommandsType Cmd,
                                                                               uint32 *MatchedEntries,
                                                                               const Netc_EthSwt_Ip_RatePolicerEntryDataType * RatePolicerTableEntry
                                                                             );

/**
 * @brief            Query Rate Policer Table Entry function
 * @details          External function for querying one Rate Policer entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        RatePolicerEntryId     Rate Policer table entry ID
 * @param[out]       RatePolicerTableEntry  A pointer that returns the data of a matched entry by "query" operation
 *                                          The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryRatePolicerTableEntry( uint8 SwitchIdx,
                                                                         uint32 *MatchedEntries,
                                                                         uint32 RatePolicerEntryId,
                                                                         Netc_EthSwt_Ip_RatePolicerEntryRspDataType * RatePolicerTableEntry
                                                                       );

/**
 * @brief            Delete Rate Policer Table Entry function
 * @details          External function for deleting one Rate Policer entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        RatePolicerEntryId     Rate Policer entry ID
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteRatePolicerTableEntry( uint8 SwitchIdx,
                                                                          uint32 *MatchedEntries,
                                                                          uint32 RatePolicerEntryId
                                                                        );

/**
 * @brief            Add or Update Ingress Stream Table Entry function
 * @details          External function for adding or updating one Ingress Stream entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx        Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        Cmd              Add and Update commands are supported
 * @param[out]       MatchedEntries   Number of matched entries
 * @param[in]        IngressStreamTableEntry    Pointer points to a Ingress Stream entry structure Netc_EthSwt_Ip_IngressStreamEntryDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateIngressStreamTableEntry( uint8 SwitchIdx,
                                                                                 Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                 uint32 *MatchedEntries,
                                                                                 const Netc_EthSwt_Ip_IngressStreamEntryDataType * IngressStreamTableEntry
                                                                               );

/**
 * @brief            Query Ingress Stream Table Entry function
 * @details          External function for querying one Ingress Stream entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        IngressStreamEntryId     Ingress Stream table entry ID
 * @param[out]       IngressStreamTableEntry  A pointer that returns the data of a matched entry by "query" operation
 *                                            The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryIngressStreamTableEntry( uint8 SwitchIdx,
                                                                           uint32 *MatchedEntries,
                                                                           uint32 IngressStreamEntryId,
                                                                           Netc_EthSwt_Ip_IngressStreamEntryDataType * IngressStreamTableEntry
                                                                         );

/**
 * @brief            Delete Ingress Stream Table Entry function
 * @details          External function for deleting one Ingress Stream entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        IngressStreamEntryId     Ingress Stream entry ID
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteIngressStreamTableEntry( uint8 SwitchIdx,
                                                                            uint32 *MatchedEntries,
                                                                            uint32 IngressStreamEntryId
                                                                          );

/**
 * @brief            Add or Update Ingress Stream Count Table Entry function
 * @details          External function for adding or updating one Ingress Stream Count entry with "Exact Match Key Element Match" access method.
 *                   That means only "Exact Match Key Element Match" access method is supported.
 *
 * @param[in]        SwitchIdx                  Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        Cmd                        Add and Update commands are supported
 * @param[out]       MatchedEntries             Number of matched entries
 * @param[in]        IngressStreamCountEntryId  Index of the Ingress Stream Count Table Entry to be added or reset
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateIngressStreamCountTableEntry( uint8 SwitchIdx,
                                                                                       Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                       uint32 *MatchedEntries,
                                                                                       uint32 IngressStreamCountId
                                                                                     );

/**
 * @brief            Query Ingress Stream Count Table Entry function
 * @details          External function for querying one Ingress Stream Count entry with "Exact Match Key Element Match" access method.
 *                   That means only "Exact Match Key Element Match" access method is supported.
 *
 * @param[in]        SwitchIdx                       Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries                  Number of matched entry
 * @param[in]        IngressStreamCountEntryId       Index of the Ingress Stream Count Table Entry to be queried
 * @param[out]       IngressStreamCountTableEntry    A pointer that returns the data of a matched entry by "query" operation
 *                                                   The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryIngressStreamCountTableEntry( uint8 SwitchIdx,
                                                                                 uint32 *MatchedEntries,
                                                                                 uint32 IngressStreamCountEntryId,
                                                                                 Netc_EthSwt_Ip_IngressStreamCountTableRspDataType * IngressStreamCountTableEntry
                                                                               );

/**
 * @brief            Delete Ingress Stream Count Table Entry function
 * @details          External function for deleting one Ingress Stream Count entry with "Exact Match Key Element Match" access method.
 *                   That means only "Exact Match Key Element Match" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        IngressStreamCountId   Index of the Ingress Stream Count Table Entry to be deleted
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteIngressStreamCountTableEntry( uint8 SwitchIdx,
                                                                                  uint32 *MatchedEntries,
                                                                                  uint32 IngressStreamCountId
                                                                                );

/**
 * @brief            Add or Update Ingress Stream Filter Table Entry function
 * @details          External function for adding or updating one Ingress Stream Filter entry with "Exact Match Key Element Match" access method.
 *                   That means only "Exact Match Key Element Match" access method is supported.
 *
 * @param[in]        SwitchIdx        Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        Cmd              Add and Update commands are supported
 * @param[out]       MatchedEntries   Number of matched entries
 * @param[in]        IngressStreamFilterTableEntry    Pointer points to a Ingress Stream Filter entry structure Netc_EthSwt_Ip_IngressStreamFilterEntryDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateIngressStreamFilterTableEntry( uint8 SwitchIdx,
                                                                                       Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                       uint32 *MatchedEntries,
                                                                                       const Netc_EthSwt_Ip_IngressStreamFilterEntryDataType * IngressStreamFilterTableEntry
                                                                                     );

/**
 * @brief            Query Ingress Stream Filter Table Entry function
 * @details          External function for querying one Ingress Stream Filter entry with "Exact Match Key Element Match" access method.
 *                   That means only "Exact Match Key Element Match" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        IngressStreamFilterTableEntry  A pointer that provides the data of KEYE_DATA filed for "query" operation
 * @param[out]       IngressStreamFilterTableEntry  A pointer that returns the data of a matched entry by "query" operation
 *                                            The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryIngressStreamFilterTableEntry( uint8 SwitchIdx,
                                                                                 uint32 *MatchedEntries,
                                                                                 Netc_EthSwt_Ip_IngressStreamFilterEntryDataType * IngressStreamFilterTableEntry
                                                                               );

/**
 * @brief            Delete Ingress Stream Filter Table Entry function
 * @details          External function for deleting one Ingress Stream Filter entry with "Exact Match Key Element Match" access method.
 *                   That means only "Exact Match Key Element Match" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        IngressStreamFilterTableEntry     A pointer that provides the data of KEYE_DATA filed for "delete" operation
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteIngressStreamFilterTableEntry( uint8 SwitchIdx,
                                                                                  uint32 *MatchedEntries,
                                                                                  const Netc_EthSwt_Ip_IngressStreamFilterEntryDataType * IngressStreamFilterTableEntry
                                                                                );

/**
 * @brief            Query Ingress Stream Filter Table Entry function with Search method
 * @details          External function for searching Ingress Stream Filter entry one by one with Search method.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        ResumeEntryId          resume entry id for searching
 * @param[out]       MatchedEntry         Number of matched entry
 * @param[out]       IngressStreamTableEntry  A pointer that returns the data of a matched entry by "search" operation
 *                                            The data is valid only when MatchedEntry equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_SearchIngressStreamFilterTableEntry( uint8 SwitchIdx,
                                                                                  uint32 * ResumeEntryId,
                                                                                  uint32 * MatchedEntry,
                                                                                  Netc_EthSwt_Ip_IngressStreamFilterEntryDataType * IngressStreamFilterTableEntry
                                                                                );

/**
 * @brief            Dump Ingress Stream Filter Table Entry function
 * @details          External function for dumping all Ingress Stream Filter entries.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        NumberOfElements       Number of entries that want to be dumped
 * @param[out]       NumberOfElements       Number of entries that actually are dumped (number of existing entries)
 * @param[out]       IngressStreamFilterTableList  A pointer that returns the list of NumberOfElements entries
 *
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_GetIngressStreamFilterTable( uint8 SwitchIdx,
                                                                          uint16 * NumberOfElements,
                                                                          Netc_EthSwt_Ip_IngressStreamFilterEntryDataType * IngressStreamFilterTableList
                                                                        );

/**
 * @brief            Add or Update Stream Gate Instance Table Entry function
 * @details          External function for adding or updating one Stream Gate Instance entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx        Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        Cmd              Add and Update commands are supported
 * @param[out]       MatchedEntries   Number of matched entries
 * @param[in]        StreamGateInstanceTableEntry    Pointer points to a Stream Gate Instance entry structure Netc_EthSwt_Ip_StreamGateInstanceEntryDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateStreamGateInstanceTableEntry( uint8 SwitchIdx,
                                                                                      Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                      uint32 *MatchedEntries,
                                                                                      const Netc_EthSwt_Ip_StreamGateInstanceEntryDataType * StreamGateInstanceTableEntry
                                                                                    );

/**
 * @brief            Query Stream Gate Instance Table Entry function
 * @details          External function for querying one Stream Gate Instance entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        SGIEntryId             Stream Gate Instance entry ID
 * @param[out]       SGITableEntryRspData   A pointer that returns the data of a matched entry by "query" operation
 *                                          The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryStreamGateInstanceTableEntry( uint8 SwitchIdx,
                                                                                uint32 *MatchedEntries,
                                                                                uint32 SGIEntryId,
                                                                                Netc_EthSwt_Ip_StreamGateInstanceEntryRspDataType * SGITableEntryRspData
                                                                              );

/**
 * @brief            Delete Stream Gate Instance Table Entry function
 * @details          External function for deleting one Stream Gate Instance entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        SGIEntryId             Stream Gate Instance entry ID
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteStreamGateInstanceTableEntry( uint8 SwitchIdx,
                                                                                 uint32 *MatchedEntries,
                                                                                 uint32 SGIEntryId
                                                                               );

/**
 * @brief            Add Stream Gate Control List Table Entry function
 * @details          External function for adding one Stream Gate Control List entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx        Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        Cmd              Add and Update commands are supported
 * @param[out]       MatchedEntries   Number of matched entries
 * @param[in]        SGCLTableEntry   Pointer points to a Stream Gate Control List entry structure Netc_EthSwt_Ip_SGCLTableDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddStreamGateControlListTableEntry( uint8 SwitchIdx,
                                                                                 Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                 uint32 *MatchedEntries,
                                                                                 const Netc_EthSwt_Ip_SGCLTableDataType * SGCLTableEntry
                                                                                );

/**
 * @brief            Query Stream Gate Control List Table Entry function
 * @details          External function for querying one Stream Gate Control List entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        SGCLEntryId            Stream Gate Control List entry ID
 * @param[in]        ListLen                Stream Gate Control List entry length, it has to be set to the same value as LIST_LENGTH when adding the entry
 * @param[out]       SGCLTableEntryRspData  A pointer that returns the data of a matched entry by "query" operation
 *                                          The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryStreamGateControlListTableEntry( uint8 SwitchIdx,
                                                                                   uint32 *MatchedEntries,
                                                                                   uint32 SGCLEntryId,
                                                                                   uint8 ListLen,
                                                                                   Netc_EthSwt_Ip_SGCLTableDataType * SGCLTableEntryRspData
                                                                                 );

/**
 * @brief            Delete Stream Gate Control List Table Entry function
 * @details          External function for deleting one Stream Gate Control List entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        SGCLEntryId            Stream Gate Control List entry ID
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteStreamGateControlListTableEntry( uint8 SwitchIdx,
                                                                                    uint32 *MatchedEntries,
                                                                                    uint32 SGCLEntryId
                                                                                  );

/**
 * @brief            Add or Update Ingress Sequence Generation Table Entry function
 * @details          External function for adding or updating one Ingress Sequence Generation entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx        Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        Cmd              Add and Update commands are supported
 * @param[out]       MatchedEntries   Number of matched entries
 * @param[in]        ISQGTableEntry   Pointer points to a Stream Gate Instance entry structure Netc_EthSwt_Ip_ISQGTableDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateIngressSeqGenerationTableEntry( uint8 SwitchIdx,
                                                                                        Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                        uint32 *MatchedEntries,
                                                                                        const Netc_EthSwt_Ip_ISQGTableDataType * ISQGTableEntry
                                                                                      );

/**
 * @brief            Query Ingress Sequence Generation Table Entry function
 * @details          External function for querying one Ingress Sequence Generation entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        ISQGEntryId            Ingress Sequence Generation entry ID
 * @param[out]       ISQGRspData            A pointer that returns the data of a matched entry by "query" operation
 *                                          The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryIngressSeqGenerationTableEntry( uint8 SwitchIdx,
                                                                                  uint32 *MatchedEntries,
                                                                                  uint32 ISQGEntryId,
                                                                                  Netc_EthSwt_Ip_ISQGTableDataType * ISQGRspData
                                                                                );

/**
 * @brief            Delete Ingress Sequence Generation Table Entry function
 * @details          External function for deleting one Ingress Sequence Generation entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        ISQGEntryId            Ingress Sequence Generation entry ID
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteIngressSeqGenerationTableEntry( uint8 SwitchIdx,
                                                                                   uint32 *MatchedEntries,
                                                                                   uint32 ISQGEntryId
                                                                                 );

/**
 * @brief            Update Egress Sequence Recovery Table Entry function
 * @details          External function for updating one Egress Sequence Recovery entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx        Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries   Number of matched entries
 * @param[in]        EgrSQRTableEntry   Pointer points to an Egress Sequence Recovery entry structure Netc_EthSwt_Ip_EgrSeqRecoveryTableDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_UpdateEgressSeqRecoveryTableEntry( uint8 SwitchIdx,
                                                                                uint32 *MatchedEntries,
                                                                                const Netc_EthSwt_Ip_EgrSeqRecoveryTableDataType * EgrSQRTableEntry
                                                                              );

/**
 * @brief            Query Egress Sequence Recovery Table Entry function
 * @details          External function for querying one Egress Sequence Recovery entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        ESQREntryId            Egress Sequence Recovery entry ID
 * @param[out]       ESQRRspData            A pointer that returns the data of a matched entry by "query" operation
 *                                          The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryEgressSeqRecoveryTableEntry( uint8 SwitchIdx,
                                                                               uint32 *MatchedEntries,
                                                                               uint32 ESQREntryId,
                                                                               Netc_EthSwt_Ip_EgrSeqRecoveryTableRspDataType * ESQRRspData
                                                                             );

/**
 * @brief            Add or Update Ingress Stream Identification Table Entry function
 * @details          External function for adding or updating one Ingress Stream Identification entry with "KEY_ELEMENT" access method.
 *                   That means only "KEY_ELEMENT" access method is supported.
 *
 * @param[in]        SwitchIdx        Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        Cmd              Add and Update commands are supported
 * @param[out]       MatchedEntries   Number of matched entries
 * @param[in]        ISQGTableEntry   Pointer points to a Ingress Stream Identification entry structure Netc_EthSwt_Ip_IngrStremIdentificationTableDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateIngrStreamIdentificationTableEntry( uint8 SwitchIdx,
                                                                                            Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                            uint32 *MatchedEntries,
                                                                                            const Netc_EthSwt_Ip_IngrStremIdentificationTableDataType * ISITableEntry
                                                                                          );

/**
 * @brief            Query Ingress Stream Identification Table Entry function
 * @details          External function for querying one Ingress Stream Identification entry with "KEY_ELEMENT" access method.
 *                   That means only "KEY_ELEMENT" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        ISITableEntry          A pointer that provides the data with the "query" operation
 * @param[out]       ISITableEntry          A pointer that returns the data of a matched entry by "query" operation
 *                                          The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryIngrStreamIdentificationTableEntry( uint8 SwitchIdx,
                                                                                      uint32 *MatchedEntries,
                                                                                      Netc_EthSwt_Ip_IngrStremIdentificationTableDataType * ISITableEntry
                                                                                    );

/**
 * @brief            Delete Ingress Stream Identification Table Entry function
 * @details          External function for deleting one Ingress Stream Identification entry with "KEY_ELEMENT" access method.
 *                   That means only "KEY_ELEMENT" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        ISITableEntry          A pointer that provides the data with the "delete" operation
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteIngrStreamIdentificationTableEntry( uint8 SwitchIdx,
                                                                                       uint32 *MatchedEntries,
                                                                                       const Netc_EthSwt_Ip_IngrStremIdentificationTableDataType * ISITableEntry
                                                                                     );

/**
 * @brief            Dump all Ingress Stream Identification Table Entries function
 * @details          External function for dumping all Ingress Stream Identification entries with "SEARCH_CRITERIA" access method.
 *                   That means only "SEARCH_CRITERIA" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        NumberOfElements       Number of entries that want to be dumped
 * @param[out]       NumberOfElements       Number of entries that actually are dumped (number of existing entries)
 * @param[out]       ISITableList           A pointer that returns the list of NumberOfElements entries
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_GetIngrStreamIdentificationTable( uint8 SwitchIdx,
                                                                               uint16 * NumberOfElements,
                                                                               Netc_EthSwt_Ip_IngrStremIdentificationTableDataType * ISITableList
                                                                             );

                                                                             /**
 * @brief            Update Egress Scheduler Table Entry function
 * @details          External function for updating one Egress Scheduler Table entry with "ENTRY_ID" access method.
 *                   That means only "ENTRY_ID" access method is supported.
 *
 * @param[in]        SwitchIdx              Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        EntryId                Egress Scheduler entry ID
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        SchedulerTableEntry    A pointer that provides the data for the "update" operation
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_UpdateEgressSchedulerTableEntry( uint8 SwitchIdx,
                                                                            uint32 EntryId,
                                                                            uint32 *MatchedEntries,
                                                                            const Netc_EthSwt_Ip_PortSchedulerType * SchedulerTableEntry
                                                                        );

/**
 * @brief           Set Timer Synchronization State.
 * @details         This function sets the Timer Synchronization state.
 *
 * @param[in]       SwitchIdx Index of the switch
 * @param[in]       SyncState Timer synchronization state

 * @return          Std_ReturnType
 * @retval          E_OK: successful.
 * @retval          E_NOT_OK: failed
 *
 */
Std_ReturnType Netc_EthSwt_Ip_SetSyncState(uint8 SwitchIdx, boolean SyncState);

#define ETHSWT_43_NETC_STOP_SEC_CODE
#include "EthSwt_43_NETC_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif
