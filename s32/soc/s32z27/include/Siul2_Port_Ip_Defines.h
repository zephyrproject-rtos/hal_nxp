/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIUL2_PORT_IP_DEFINES
#define SIUL2_PORT_IP_DEFINES

/**
*   @file    Siul2_Port_Ip_Defines.h
*
*   @addtogroup Port_CFG
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
#include "S32Z2_SIUL2.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_PORT_IP_DEFINES_VENDOR_ID_H                       43
#define SIUL2_PORT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_H        4
#define SIUL2_PORT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_H        7
#define SIUL2_PORT_IP_DEFINES_AR_RELEASE_REVISION_VERSION_H     0
#define SIUL2_PORT_IP_DEFINES_SW_MAJOR_VERSION_H                0
#define SIUL2_PORT_IP_DEFINES_SW_MINOR_VERSION_H                9
#define SIUL2_PORT_IP_DEFINES_SW_PATCH_VERSION_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* S32ZE */
#define SIUL2_PORT_IP_MULTIPLE_SIUL2_INSTANCES

/**
* @brief Number of SIUL2 instances present on the subderivative
*/
#define SIUL2_NUM_SIUL2_INSTANCES_U8 (5)

/**
* @brief Macros defined for the SIUL2 IPV that are protected.
*/
#define MCAL_SIUL2_REG_PROT_AVAILABLE   (STD_ON)

/**
* @brief Support for User mode.
* If this parameter has been configured to STD_ON, the PORT driver code can be executed from both supervisor and user mode.
*/
#define PORT_ENABLE_USER_MODE_SUPPORT   (STD_OFF)
/**
* @brief Support for REG_PROT in SIUL2 IP.
*        If the current platform implements REG_PROT for SIUL2 IP, this parameter will be defined, and will enable REG_PROT configuration for SIUL2 IP in PORT drvier
*/
#define PORT_SIUL2_REG_PROT_AVAILABLE   (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef PORT_ENABLE_USER_MODE_SUPPORT
        #if (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT)
            #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Port in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
        #endif /* (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT) */
    #endif /* ifdef PORT_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/* Pre-processor switch to enable/disable development error detection for Siul2 Ip API */
#define SIUL2_PORT_IP_DEV_ERROR_DETECT                         (STD_ON)

/*! @brief SIUL2 module has RCVR bit */
#define FEATURE_SIUL2_PORT_IP_HAS_RECEIVER_SELECT             (STD_ON)
/*! @brief SIUL2 module has ODE bit */
#define FEATURE_SIUL2_PORT_IP_HAS_OPEN_DRAIN                  (STD_ON)
/*! @brief SIUL2 module has TRC bit */
#define FEATURE_SIUL2_PORT_IP_HAS_TERMINATION_RESISTOR        (STD_ON)
/*! @brief SIUL2 module has CREF bit */
#define FEATURE_SIUL2_PORT_IP_HAS_CURRENT_REFERENCE_CONTROL   (STD_ON)
/*! @brief SIUL2 module has RXCB bit */
#define FEATURE_SIUL2_PORT_IP_HAS_RX_CURRENT_BOOST            (STD_ON)

/* Workaround when this define in header is incorrect */
/*! @name MSCR - SIUL2 Multiplexed Signal Configuration Register */
/*! @{ */
#ifdef SIUL2_MSCR_SRE_MASK
#undef SIUL2_MSCR_SRE_MASK
#undef SIUL2_MSCR_SRE_SHIFT
#undef SIUL2_MSCR_SRE_WIDTH
#undef SIUL2_MSCR_SRE
#define SIUL2_MSCR_SRE_MASK                      (0x1C000U)
#define SIUL2_MSCR_SRE_SHIFT                     (14U)
#define SIUL2_MSCR_SRE_WIDTH                     (3U)
#define SIUL2_MSCR_SRE(x)                        (((uint32_t)(((uint32_t)(x)) << SIUL2_MSCR_SRE_SHIFT)) & SIUL2_MSCR_SRE_MASK)
#endif /* SIUL2_MSCR_SRE_MASK */

#ifdef SIUL2_MSCR_PUE_MASK
#undef SIUL2_MSCR_PUE_MASK
#undef SIUL2_MSCR_PUE_SHIFT
#undef SIUL2_MSCR_PUE_WIDTH
#undef SIUL2_MSCR_PUE
#define SIUL2_MSCR_PUE_MASK                      (0x2000U)
#define SIUL2_MSCR_PUE_SHIFT                     (13U)
#define SIUL2_MSCR_PUE_WIDTH                     (1U)
#define SIUL2_MSCR_PUE(x)                        (((uint32_t)(((uint32_t)(x)) << SIUL2_MSCR_PUE_SHIFT)) & SIUL2_MSCR_PUE_MASK)
#endif /* SIUL2_MSCR_PUE_MASK */

#ifdef SIUL2_MSCR_PUS_MASK
#undef SIUL2_MSCR_PUS_MASK
#undef SIUL2_MSCR_PUS_SHIFT
#undef SIUL2_MSCR_PUS_WIDTH
#undef SIUL2_MSCR_PUS
#define SIUL2_MSCR_PUS_MASK                      (0x1000U)
#define SIUL2_MSCR_PUS_SHIFT                     (12U)
#define SIUL2_MSCR_PUS_WIDTH                     (1U)
#define SIUL2_MSCR_PUS(x)                        (((uint32_t)(((uint32_t)(x)) << SIUL2_MSCR_PUS_SHIFT)) & SIUL2_MSCR_PUS_MASK)
#endif /* SIUL2_MSCR_PUS_MASK */

#ifdef SIUL2_MSCR_OBE_MASK
#undef SIUL2_MSCR_OBE_MASK
#undef SIUL2_MSCR_OBE_SHIFT
#undef SIUL2_MSCR_OBE_WIDTH
#undef SIUL2_MSCR_OBE
#define SIUL2_MSCR_OBE_MASK                      (0x200000U)
#define SIUL2_MSCR_OBE_SHIFT                     (21U)
#define SIUL2_MSCR_OBE_WIDTH                     (1U)
#define SIUL2_MSCR_OBE(x)                        (((uint32_t)(((uint32_t)(x)) << SIUL2_MSCR_OBE_SHIFT)) & SIUL2_MSCR_OBE_MASK)
#endif /* SIUL2_MSCR_OBE_MASK */

/*! @} */

#define SIUL2_0_MSCR_BASE                (IP_SIUL2_0->MSCR)
#define SIUL2_1_MSCR_BASE                (IP_SIUL2_1->MSCR)
#define SIUL2_3_MSCR_BASE                (IP_SIUL2_3->MSCR)
#define SIUL2_4_MSCR_BASE                (IP_SIUL2_4->MSCR)
#define SIUL2_5_MSCR_BASE                (IP_SIUL2_5->MSCR)

/** SIUL2_0 */
/** Peripheral PORTA base pointer. Pins start from PAD_000 to PAD_015. */
#define PORTA                            ((Siul2_Port_Ip_PortType *)(SIUL2_0_MSCR_BASE + 0x00))
/** Peripheral PORTB base pointer. Pins start from PAD_016 to PAD_030. */
#define PORTB                            ((Siul2_Port_Ip_PortType *)(SIUL2_0_MSCR_BASE + 0x10))
/** SIUL2_1 */
/** Peripheral PORTC base pointer. Pins: PAD_031. */
#define PORTC                            ((Siul2_Port_Ip_PortType *)(SIUL2_1_MSCR_BASE + 0x10))
/** Peripheral PORTD base pointer. Pins start from PAD_032 to PAD_047. */
#define PORTD                            ((Siul2_Port_Ip_PortType *)(SIUL2_1_MSCR_BASE + 0x20))
/** Peripheral PORTE base pointer. Pins start from PAD_048 to PAD_063. */
#define PORTE                            ((Siul2_Port_Ip_PortType *)(SIUL2_1_MSCR_BASE + 0x30))
/** Peripheral PORTF base pointer. Pins start from PAD_064 to PAD_079. */
#define PORTF                            ((Siul2_Port_Ip_PortType *)(SIUL2_1_MSCR_BASE + 0x40))
/** Peripheral PORTG base pointer. Pins start from PAD_080 to PAD_091. */
#define PORTG                            ((Siul2_Port_Ip_PortType *)(SIUL2_1_MSCR_BASE + 0x50))
/** SIUL2_4 */
/** Peripheral PORTH base pointer. Pins start from PAD_092 to PAD_095. */
#define PORTH                            ((Siul2_Port_Ip_PortType *)(SIUL2_4_MSCR_BASE + 0x50))
/** Peripheral PORTI base pointer. Pins start from PAD_096 to PAD_111. */
#define PORTI                            ((Siul2_Port_Ip_PortType *)(SIUL2_4_MSCR_BASE + 0x60))
/** Peripheral PORTJ base pointer. Pins start from PAD_112 to PAD_127. */
#define PORTJ                            ((Siul2_Port_Ip_PortType *)(SIUL2_4_MSCR_BASE + 0x70))
/** Peripheral PORTK base pointer. Pins start from PAD_128 to PAD_143. */
#define PORTK                            ((Siul2_Port_Ip_PortType *)(SIUL2_4_MSCR_BASE + 0x80))
/** Peripheral PORTL base pointer. Pins start from PAD_144 to PAD_145. */
#define PORTL                            ((Siul2_Port_Ip_PortType *)(SIUL2_4_MSCR_BASE + 0x90))
/** SIUL2_5 */
/** Peripheral PORTM base pointer. Pins start from PAD_146 to PAD_159. */
#define PORTM                            ((Siul2_Port_Ip_PortType *)(SIUL2_5_MSCR_BASE + 0x90))
/** Peripheral PORTN base pointer. Pins start from PAD_160 to PAD_169. */
#define PORTN                            ((Siul2_Port_Ip_PortType *)(SIUL2_5_MSCR_BASE + 0xA0))
/** SIUL2_0 */
/** Peripheral PORTO base pointer. Pins start from PAD_170 to PAD_173. */
#define PORTO                            ((Siul2_Port_Ip_PortType *)(SIUL2_0_MSCR_BASE + 0xA0))

#define PORT_SIUL2_0_IMCRS_IDX_END_U16     ((uint16)89)
#define PORT_SIUL2_1_IMCRS_IDX_END_U16     ((uint16)209)
#define PORT_SIUL2_3_IMCRS_IDX_END_U16     ((uint16)23)
#define PORT_SIUL2_4_IMCRS_IDX_END_U16     ((uint16)371)
#define PORT_SIUL2_5_IMCRS_IDX_END_U16     ((uint16)474)

/* Pre-processor switch to enable/disable VirtWrapper support */
#define PORT_VIRTWRAPPER_SUPPORT                      (STD_OFF)


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SIUL2_PORT_IP_DEFINES */
