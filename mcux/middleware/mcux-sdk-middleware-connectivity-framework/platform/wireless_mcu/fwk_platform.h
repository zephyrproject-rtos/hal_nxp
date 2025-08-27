/* -------------------------------------------------------------------------- */
/*                           Copyright 2020-2023, 2025 NXP                    */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_PLATFORM_H_
#define _FWK_PLATFORM_H_

/*!
 * @addtogroup FWK_Platform_module
 * The FWK_Platform module
 *
 * FWK_Platform module provides APIs to set platform parameters.
 * @{
 */
/*!
 * @addtogroup FWK_Platform
 * The FWK_Platform main module
 *
 * FWK_Platform main module provides APIs to set main platform parameters.
 * @{
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "EmbeddedTypes.h"
#include <stdbool.h>

/* -------------------------------------------------------------------------- */
/*                                 Definitions                                */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                Public types                                */
/* -------------------------------------------------------------------------- */

/*!
 * \brief  type definition for the list of reset status
 *
 */
typedef enum
{
    PLATFORM_LowPowerWakeup,
    PLATFORM_DeviceReset,
} PLATFORM_ResetStatus_t;

/*!
 * \brief  type definition for the list of constraint frequency available on the nbu
 *
 */
typedef enum
{
    PLATFORM_NBU_MIN_FREQ_16MHZ,
    PLATFORM_NBU_MIN_FREQ_24MHZ,
    PLATFORM_NBU_MIN_FREQ_32MHZ,
    PLATFORM_NBU_MIN_FREQ_48MHZ,
    PLATFORM_NBU_MIN_FREQ_64MHZ, /* LDO core output voltage needs to be set to 1.1V to support 64MHz on nbu */
} PLATFORM_NbuConstraintFrequency_t;

/*!
 * \brief Error callback used to handle error at platform level that can be registered with
 * PLATFORM_RegisterErrorCallback()
 *
 * \param[in] id of the caller of the callback.
 * \param[in] error_status given by the caller of the callback.
 *
 */
typedef void (*PLATFORM_ErrorCallback_t)(uint32_t id, int32_t error_status);

/*!
 * \brief  type definition for platform functions IDs used by the error callback system
 *
 */
typedef enum
{
    /* PLATFORM */
    PLATFORM_REMOTE_ACTIVE_REQ_ID,
    /* PLATFORM_BLE */
    PLATFORM_INIT_BLE_ID,
    PLATFORM_SEND_HCI_MESSAGE_ID,
} PLATFORM_Id_t;

/* -------------------------------------------------------------------------- */
/*                        Public functions declaration                        */
/* -------------------------------------------------------------------------- */
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * \brief  Initialize NBU
 *
 * \return int 0 if success, 1 if already initialized, negative value if error.
 */
int PLATFORM_InitNbu(void);

/*!
 * \brief  Initialize of the multicore
 *
 * \return int 0 if success, negative if error.
 */
int PLATFORM_InitMulticore(void);

/*!
 * \brief  get 4 words of information that uniquely identifies the MCU
 *
 * \param[out] aOutUid16B pointer to UID bytes
 * \param[out] pOutLen pointer to UID length
 */
void PLATFORM_GetMCUUid(uint8_t *aOutUid16B, uint8_t *pOutLen);

/*!
 * \brief Disable Controller low power entry
 *        Depending on the platform, this can concern multiple controllers
 *        Controller low power is always enabled by default, so this should be
 *        called mainly for debug purpose
 *
 */
void PLATFORM_DisableControllerLowPower(void);

/*!
 * \brief  Request Radio domain to be active
 *
 *  On return from this function, the Radio domain and all its HW ressources can be accessed safely
 *    until PLATFORM_RemoteActiveRel() is called
 *
 */
void PLATFORM_RemoteActiveReq(void);

/*!
 * \brief  Release Radio domain from being active
 *
 *  On return from this function, the Radio domain and all its HW ressources can not be accessed
 *    if the radio domain has turned into lowpower,
 *   Need to call PLATFORM_RemoteActiveReq() for accessing safely to the ressources it contains
 *
 */
void PLATFORM_RemoteActiveRel(void);

/*!
 * \brief Get the reset cause, the reason why the chip is awake
 *
 * \param[out] reset_status Reason of the last reset
 *
 */
void PLATFORM_GetResetCause(PLATFORM_ResetStatus_t *reset_status);

/*!
 * \brief Returns current timestamp
 *
 * \return uint64_t timestamp (raw TSTMR ticks)
 */
uint64_t PLATFORM_GetTimeStamp(void);

/*!
 * \brief Returns the max timestamp value that can be returned by PLATFORM_GetTimeStamp
 *        Can be used by the user to handle timestamp wrapping
 *
 * \return uint64_t the max timestamp value
 */
uint64_t PLATFORM_GetMaxTimeStamp(void);

/*!
 * \brief Compute number of microseconds between 2 timestamps expressed in number of 1MHz TSTMR ticks
 *
 * \param [in] timestamp0 start timestamp from which duration is assessed.
 * \param [in] timestamp1 end timestamp till which duration is assessed.
 *
 * \return uint64_t number of microseconds
 *
 */
uint64_t PLATFORM_GetTimeStampDeltaUs(uint64_t timestamp0, uint64_t timestamp1);

/*!
 * \brief  Tells if the timeout is expired
 *
 * \param[in] initial_timestamp (raw TSTMR value)
 * \param[in] delayUs time delay in us
 *
 * \return bool returns if timeout is expired
 *
 */
bool PLATFORM_IsTimeoutExpired(uint64_t initial_timestamp, uint64_t delayUs);

/*!
 * \brief  wait for the given delay in us
 *
 * \param[in] delayUs time delay in us
 *
 */
void PLATFORM_Delay(uint64_t delayUs);

/*!
 * \brief  wait for the given delay in us starting from
 *  given Timestamp. Timestamp shall be get from PLATFORM_GetTimeStamp()
 *
 * \param[in] timestamp (raw TSTMR value)
 * \param[in] delayUs time delay in us
 *
 */
void PLATFORM_WaitTimeout(uint64_t timestamp, uint64_t delayUs);

/*!
 * \brief  Set the frequency constraint to the nbu for the host
 * Nbu will choose the frequency to apply to its core depending this value and the value set in the controller
 * directly. It will take the value the much higher between the two constraint.
 *
 * \note If a value higher than 32MHz is set, the LDO core output voltage needs to be set to 1.1V.
 *
 * \param[in] freq_constraint See PLATFORM_NbuConstraintFrequency_t
 *
 */
void PLATFORM_SetNbuConstraintFrequency(PLATFORM_NbuConstraintFrequency_t freq_constraint);

/*!
 * \brief Register error callback for platform functions
 *
 * \param[in] cb error callback for platform module
 *
 */
void PLATFORM_RegisterErrorCallback(PLATFORM_ErrorCallback_t cb);

/*!
 * \brief  Query whether NBU is started so that messages could be sent to it without
 * causing any problem.
 *
 * \note This function is used to avoid blocking of PLATFORM_FwkSrvSendPacket if NBU core
 *       is not expecting messages yet.
 *
 * \return 0 if NBU was not started yet, 1 otherwise.
 *
 */
int PLATFORM_IsNbuStarted(void);

/*!
 * \brief  Detect if wake up from power down or Deep power down and clear IO isolation if true
 *
 * \return 1 if wakeup from power down or deep power down modes and IO isolation is cleared
 *         0 Otherwise
 *
 */
int PLATFORM_ClearIoIsolationFromLowPower(void);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*!
 * @}  end of FWK_Platform addtogroup
 */
/*!
 * @}  end of FWK_Platform_module addtogroup
 */
#endif /* _FWK_PLATFORM_H_ */
