/*! *********************************************************************************
* Copyright 2024 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

/*! *********************************************************************************
* \defgroup PlatInterface Mac Interface
*
*
* @{
********************************************************************************** */

#ifndef _PLAT_INTERFACE_H
#define _PLAT_INTERFACE_H

#ifdef __cplusplus
    extern "C" {
#endif

/************************************************************************************
*************************************************************************************
* Include
*************************************************************************************
************************************************************************************/
#if (gMacUsePackedStructs_d)
#define MAC_STRUCT PACKED_STRUCT
#define MAC_UNION PACKED_UNION
#else
#define MAC_STRUCT struct
#define MAC_UNION union
#endif

/************************************************************************************
*************************************************************************************
* Public macros
*************************************************************************************
************************************************************************************/
typedef enum
{
    gIeee64Get_c,         /*!<  payload is platformExtAdress_t*/
    gIeee64Set_c,         /*!<  payload is platformExtAdress_t */
    gAppToAspMessage_c,   /*!<  App2Asp message for FSCI need payload is AppToAspMessage_t*/
    gErrorResp_c,         /*!<  */

}platformMessageId_t;

#define EXT_ADDRESS_SIZE 8
typedef MAC_STRUCT platformExtAddress_tag
{
    uint8_t           m8[EXT_ADDRESS_SIZE]; /*!<  */
} platformExtAddress_t;

#ifdef __cplusplus
    }
#endif

#endif  /* _PLAT_INTERFACE_H */

/*! *********************************************************************************
* @}
********************************************************************************** */