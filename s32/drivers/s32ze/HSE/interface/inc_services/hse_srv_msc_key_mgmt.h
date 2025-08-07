/**
*   @file    hse_srv_msc_key_mgmt.h
*
*   @brief   Managed Security Component(MSC) key management services definition.
*   @details This file contains the MSC key management services definition.
*
*   @addtogroup hse_srv_msc_key_mgmt HSE MSC Key Management Services
*   @ingroup class_key_management
*   @{
*/
/*==================================================================================================
*
*   Copyright 2022-2024 NXP
*
*   Redistribution and use in source and binary forms, with or without modification,
*   are permitted provided that the following conditions are met:
*
*   1. Redistributions of source code must retain the above copyright notice, this list
*      of conditions and the following disclaimer.
*
*   2. Redistributions in binary form must reproduce the above copyright notice, this
*      list of conditions and the following disclaimer in the documentation and/or
*      other materials provided with the distribution.
*
*   3. Neither the name of the copyright holder nor the names of its
*      contributors may be used to endorse or promote products derived from this
*      software without specific prior written permission.
*
*   This software is owned or controlled by NXP and may only be used strictly in accordance with
*   the applicable license terms. By expressly accepting such terms or by downloading, installing,
*   activating and/or otherwise using the software, you are agreeing that you have read, and that
*   you agree to comply with and are bound by, such license terms. If you do not agree to
*   be bound by the applicable license terms, then you may not retain, install, activate or
*   otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef HSE_SRV_MSC_KEY_MGMT_H
#define HSE_SRV_MSC_KEY_MGMT_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "hse_common_types.h"

#define HSE_START_PRAGMA_PACK
#include "hse_compiler_abs.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** @brief The restriction flags for the Key Handle Translation Table (KHTT) entry.*/
typedef uint8_t hseKHTTRestrictFlags_t;
/** @brief The restriction used when more MSC keys are pushed at once:
 *         - If it is set 0, HSE loads the MSC key when the #hsePushMscKeySrv_t service is called with hseKeyHandle = HSE_INVALID_KEY_HANDLE.
 *         - If it is set 1, HSE does not load the MSC key when the #hsePushMscKeySrv_t service is called with hseKeyHandle = HSE_INVALID_KEY_HANDLE. */
#define HSE_KHTT_RESTRICT_PUSH_MANY             ((hseKHTTRestrictFlags_t)1U)

/** @brief The Key Handle Translation Table (KHTT) entry.
 *         Each KHTT entry contains the correspondence between HSE Key Handles and MSC key slots (e.g. ACE key slots).
 *         @note
 *         - The "Managed Security Component"(MSC) term is used bellow for any HW accelerator on host-side that uses keys managed by HSE FW.
 *         - Each MSC key inherit the properties of its corresponding key in HSE.
 *         - The only accepted values for keyInfo.keyFlags are HSE_KF_USAGE_ENCRYPT, HSE_KF_USAGE_DECRYPT, HSE_KF_USAGE_SIGN or HSE_KF_USAGE_VERIFY.
 *           Any other key usage flag set beside the accepted ones will lead to the key importing failure with HSE_SRV_RSP_NOT_ALLOWED status.
 *         - If keyInfo.keyFlags is set to any of the HSE_KF_USAGE_VERIFY and HSE_KF_USAGE_SIGN flags, the key can only be used with CMAC operation.
 *           The rest of the key flags are ignored. For SHE RAM keys, they can only be used with CMAC operation.
 *         - If the DID input received over ACE buses is not matching the DID flags configured for the entry, the key can not be used.
 *         - MSC key store must be statically partitioned per host (e.g. each host has its own key slots)
 * */
typedef struct
{
    /** @brief   INPUT: The key handle used with HSE keystore.
     *           @note
     *           The key bit length of HSE key can only be 128 or 256 bits (e.g. the 256 bit key group cannot get a key of 128 bit size). */
    hseKeyHandle_t      hseKeyHandle;
    /** @brief   INPUT: The MSC key slot index. The MSC/ACE subsystem accesses a key selecting a key slot in the range 0 to 127.
     *           @note
     *           - The MSC keystore (e.g. ACE keystore) contains 128 X key slots of 16 bytes and the associated key properties.
     *             Without considering the key properties, it can be seen as an array of 128 elements, the size of each element
     *             being 16 bytes (e.g keystore[128][16]).
     *           - An AES128 key occupies only one key slot. An AES256 key occupies two key slots. In this case,
     *             the next key slot following an AES256 key must be placed at N+2 (e.g keystore[N+2]), where N is the AES256 key slot index.
     *           - The maximum number of MSC keys is 128 x 128-bit keys or 64 x 256-bit keys or any combination in between. */
    uint8_t             mscKeySlotIdx;
    /** @brief   INPUT: MSC Instance (e.g. the instance of the HW accelerator on the host side).
     *           @note
     *           On S32ZE, field is ignored; there is only one MSC instance (e.g. ACE HW accelerator). */
    uint8_t             mscInstance;
    /** @brief   INPUT: 16 bits for Domain ID (DID) filtering. The didFlags is compared against "1<<bus DID value".
     *           @note
     *           On the buses the DID value is 4 bits only. The DID comparison works in this way:
     *           If bus DID = 4, it means bit 4 in didFlags must be set to be able to use the key. */
    uint16_t            aceDidFlags;
    /** @brief   INPUT: Restriction flags (see #hseKHTTRestrictFlags_t) */
    hseKHTTRestrictFlags_t restrictFlags;
    uint8_t             reserved[3];
} hseKHTTEntry_t;


/** @brief Configure the Key Handle Translation Table (KHTT) service.
 *         This service sends the Key Handle Translation Table (KHTT) which is statically defined by the application at configuration time.
 *         @note
 *         - The "Managed Security Component"(MSC) term is used below for any HW accelerator on host-side that uses keys managed by HSE FW.
 *         - Before configuring the MSC keys, the application shall enable the MSC clock (e.g ACE clock must be enabled by the application).
 *         - The Key Handle Translation Table (KHTT) is a table stored in SYS-IMG with correspondences between HSE KeyHandles and MSC key slots.
 *         - Using KHTT table, the HSE keys are mirrored by HSE subsystem in the MSC key store (e.g. ACE key store).
 *           This means that any key import/erase is automatically performed on both key stores (HSE and MSC keystores).
 *         - The KHTT table maps each HSE keyHandle to MSC mscKeySlotIdx. The key handles can be NVM or RAM keys.
 *           Only the NVM keys are stored in SYS-IMG (the RAM keys are not persistent).
 *         - The MSC keys can be loaded (at initialization) from SYS-IMG in MSC key store calling the
 *           #hsePushMscKeySrv_t service with the hseKeyHandle parameter equal with HSE_INVALID_KEY_HANDLE.
 *           The same service can be used to push only one HSE key slot to one MSC key slot, providing the corresponding hseKeyHandle.
 */
typedef struct
{
    /** @brief   INPUT: Number of KHTT entries. It shall be maximum 200 entries. */
    uint16_t            numOfKHTTEntries;
    uint8_t             reserved[2];
/** @brief   INPUT: Pointer to the Key Handle Translation Table(KHTT) that contains #numOfKHTTEntries entries of type #hseKHTTEntry_t. */
    HOST_ADDR           pKHTT;
}hseConfigKHTTSrv_t;

/** @brief Push one or more MSC keys.
 *         This service requests HSE to push one or more HSE keys in the corresponding MSC slots.
 *         The HSE key handle must be found in the Key Handle Translation Table (KHTT) (see #hseConfigKHTTSrv_t).
 * */
typedef struct
{
    /** @brief   INPUT: The HSE key handle to be pushed to MSC key slot.
     *                  If hseKeyHandle == HSE_INVALID_KEY_HANDLE, HSE pushes all key slots (not empty)
     *                  from KHTT table that do not have the #HSE_KHTT_RESTRICT_PUSH_MANY flag set.
     *         @note
     *         - This option can be used to load (at initialization time) the NVM HSE keys
     *           whose handles are found in the KHTT and have the #HSE_KHTT_RESTRICT_PUSH_MANY flag set.
     *         - If hseKeyHandle != HSE_INVALID_KEY_HANDLE, HSE pushes a single key which must be in the KHTT table.
     *         - The pushed key(s) must not be empty
     */
    hseKeyHandle_t      hseKeyHandle;
}hsePushMscKeySrv_t;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define HSE_STOP_PRAGMA_PACK
#include "hse_compiler_abs.h"

#ifdef __cplusplus
}
#endif

#endif /* HSE_SRV_MSC_KEY_MGMT_H */

/** @} */
