/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*==========================================================================*/
/*!
 * @addtogroup MX9_CCM_driver
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the CCM (Clock Control Module) driver.
 */
/*==========================================================================*/

#ifndef FSL_CCM_H
#define FSL_CCM_H

/* Includes */

#include "fsl_common.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * @name CCM module functions
 * @{
 */

/*!
 * Get CCM clock root enable status
 *
 * @param[in]       rootIdx     CCM clock root ID
 *
 * This function gets clock root enable status.
 *
 * @return Clock root enable status. true if the clock root is enabled,
 *         otherwise false.
 */
bool CCM_RootGetEnable(uint32_t rootIdx);

/*!
 * Set CCM clock root enable
 *
 * @param[in]       rootIdx     CCM clock root ID
 * @param[in]       enable      Enable flag (1=enabled, 0=disabled)
 *
 * This function sets clock root enable flag.
 *
 * @return Returns true if clock enable status was updated, otherwise returns
 *         false.
 */
bool CCM_RootSetEnable(uint32_t rootIdx, bool enable);

/*!
 * Get CCM clock root rate
 *
 * @param[in]       rootIdx     CCM clock root ID
 *
 * This function returns clock root rate in Hz.
 *
 * @return Clock root rate in Hz.
 */
uint64_t CCM_RootGetRate(uint32_t rootIdx);

/*!
 * Set CCM clock root rate
 *
 * @param[in]       rootIdx     CCM clock root ID
 * @param[in]       rate        Clock root rate to be set
 * @param[in]       roundRule   Clock rounding option
 *
 * @return true if the clock root rate is set successfully, otherwise false.
 */
bool CCM_RootSetRate(uint32_t rootIdx, uint64_t rate, uint32_t roundRule);

/*!
 * Get number of mux inputs for CCM clock root
 *
 * @param[in]       rootIdx       CCM clock root ID
 * @param[out]      numMuxInputs  Pointer to return number of mux inputs
 *
 * This function returns number of mux inputs for CCM clock root
 *
 * @return Returns true if number of mux inputs read successfully.
 */
bool CCM_RootMuxNumInputsGet(uint32_t rootIdx, uint32_t *numMuxInputs);

/*!
 * Get specified mux input for CCM clock root
 *
 * @param[in]       rootIdx     CCM clock root ID
 * @param[in]       muxIdx      Clock root mux ID
 * @param[out]      muxInput    Mux input to clock root
 *
 * This function returns mux input for given \a rootIdx and \a muxIdx.
 *
 * @return Returns true if a valid mux input is found.
 */
bool CCM_RootMuxInputGet(uint32_t rootIdx, uint32_t muxIdx,
    uint32_t *muxInput);

/*!
 * Get CCM clock root parent
 *
 * @param[in]       rootIdx     CCM clock root ID
 * @param[out]      sourceIdx   Clock root parent ID
 *
 * This function gets parent ID (clock source) of given clock root.
 *
 * @return Returns true if a valid parent ID (clock source) is found for given
 *         clock root.
 */
bool CCM_RootGetParent(uint32_t rootIdx, uint32_t *sourceIdx);

/*!
 * Set CCM clock root parent
 *
 * @param[in]       rootIdx     CCM clock root ID
 * @param[in]       sourceIdx   Clock root parent to be set
 *
 * This function sets clock root's parent (clock source).
 *
 * @return Returns true if valid parent ID (clock source) is set for given
 *         clock root.
 */
bool CCM_RootSetParent(uint32_t rootIdx, uint32_t sourceIdx);

/*!
 * Get CCM clock root divider
 *
 * @param[in]       rootIdx     CCM clock root ID
 * @param[out]      divider     Clock root divider
 *
 * This function allows caller to get the divider for given clock root.
 *
 * @return Returns true if a valid divider is found for given clock root.
 */
bool CCM_RootGetDiv(uint32_t rootIdx, uint32_t *divider);

/*!
 * Set CCM clock root divider
 *
 * @param[in]       rootIdx     CCM clock root ID
 * @param[in]       divider     Clock root divider
 *
 * This function allows caller to set the divider for given clock root.
 *
 * @return Returns true if a valid divider is set for given clock root.
 */
bool CCM_RootSetDiv(uint32_t rootIdx, uint32_t divider);

/*!
 * Get CCM GPR-selected clock enable status
 *
 * @param[in]       gprSelIdx       GPR (general purpose register) select ID
 *
 * @return Returns true if GPR-selected mux is enabled.
 */
bool CCM_GprSelGetEnable(uint32_t gprSelIdx);

/*!
 * Get CCM GPR-selected rate for EXT clock
 *
 * @return Returns GPR (general purpose register) selected rate for EXT clock.
 */
uint64_t CCM_GprSelExtGetRate(void);

/*!
 * Get CCM GPR-selected clock rate
 *
 * @param[in]       gprSelIdx     GPR (general purpose register) select ID
 *
 * This function allows caller to get shared GPR-selected clock rate.
 *
 * @return Returns GPR-selected clock rate for given GPR-select ID.
 */
uint64_t CCM_GprSelGetRate(uint32_t gprSelIdx);

/*!
 * Get number of mux inputs for GPR-selected clock
 *
 * @param[in]       gprSelIdx       GPR (general purpose register) select ID
 * @param[out]      numMuxInputs    Number of mux inputs for GPR-selected ID
 *
 * This function allows caller to get number of mux inputs for given
 * GPR-selected ID.
 *
 * @return Returns true if number of mux inputs are found for given
 *         GPR-selected clock.
 */
bool CCM_GprSelMuxNumInputsGet(uint32_t gprSelIdx, uint32_t *numMuxInputs);

/*!
 * Get specified mux input for for GPR-selected clock
 *
 * @param[in]       gprSelIdx       GPR (general purpose register) select ID
 * @param[in]       muxIdx          Number of mux inputs for GPR-selected ID
 * @param[out]      muxInput        Mux input value for given \a gprSelIdx and
 *                                  \a muxIdx
 *
 * This function allows caller to get specified mux input value for given
 * \a gprSelIdx and \a muxIdx.
 *
 * @return Returns true if specified mux input is found.
 */
bool CCM_GprSelMuxInputGet(uint32_t gprSelIdx, uint32_t muxIdx,
    uint32_t *muxInput);

/*!
 * Get CCM GPR-selected clock's parent
 *
 * @param[in]       gprSelIdx       GPR (general purpose register) select ID
 * @param[out]      clkIdx          Clock ID for GPR-selected clock parent
 *
 * This function allows caller to get parent clock ID for GPR-selected clock.
 *
 * @return Returns true if GPR-selected clock parent is found.
 */
bool CCM_GprSelGetParent(uint32_t gprSelIdx, uint32_t *clkIdx);

/*!
 * Set CCM GPR-selected clock's parent
 *
 * @param[in]       gprSelIdx       GPR (general purpose register) select ID
 * @param[in]       clkIdx          Clock ID for GPR-selected clock parent
 *
 * This function allows caller to set parent clock ID for GPR-selected clock.
 *
 * @return Returns true if GPR-selected clock parent is updated.
 */
bool CCM_GprSelSetParent(uint32_t gprSelIdx, uint32_t clkIdx);

/*!
 * Set CCM GPR register
 *
 * @param[in]       gprIdx      GPR (general purpose register) ID
 * @param[in]       gprMask     GPR mask
 * @param[in]       gprVal      GPR value to be set
 *
 * This function allows caller to update GPR register.
 *
 * @return Returns true if GPR is updated.
 */
bool CCM_GprValSet(uint32_t gprIdx, uint32_t gprMask, uint32_t gprVal);

/*!
 * Get CCM CGC enable
 *
 * @param[in]       cgcIdx     CCM CGC index
 *
 * This function gets CGC clock enable status.
 *
 * @return Returns true if the CGC is enabled,
 *         otherwise false.
 */
bool CCM_CgcGetEnable(uint32_t cgcIdx);

/*!
 * Set CCM CGC enable
 *
 * @param[in]       cgcIdx     CCM CGC index
 * @param[in]       enable     Enable flag (1=enabled, 0=disabled)
 *
 * This function sets the CGC clock enable status.
 *
 * @return Returns true if clock enable status was updated, otherwise returns
 *         false.
 */
bool CCM_CgcSetEnable(uint32_t cgcIdx, bool enable);

/*!
 * Get CCM CGC clock root rate
 *
 * @param[in]       cgcIdx     CCM CGC index
 *
 * This function returns the CGC rate in Hz.
 *
 * @return CGC rate in Hz.
 */
uint64_t CCM_CgcGetRate(uint32_t cgcIdx);

/*!
 * Get CCM CGC parent
 *
 * @param[in]       cgcIdx      CCM CGC index
 * @param[out]      rootIdx     CCM clock root index sourcing CGC
 *
 * This function gets the parent (clock root index) of the CGC.
 *
 * @return Returns true if a valid parent (clock root index) is found for given
 *         CGC.
 */
bool CCM_CgcGetParent(uint32_t cgcIdx, uint32_t *rootIdx);

/*!
 * Get CCM LPCG direct control enable status
 *
 * @param[in]       lpcgIdx     LPCG register index
 *
 * This function queries the LPCG direct control enable status.
 *
 * @return LPCG direct control enable status.
 */
bool CCM_LpcgDirectCtrlGetEnable(uint32_t lpcgIdx);

/*!
 * Set CCM LPCG direct control enable
 *
 * @param[in]       lpcgIdx     LPCG register index
 * @param[in]       enable      Enable flag (1=enabled, 0=disabled)
 *
 * This function configures the LPCG direct control to enable/disable
 * the clock output of the LPCG.
 *
 * @return Returns true if LPCG direct control setting is updated.
 */
bool CCM_LpcgDirectCtrlSetEnable(uint32_t lpcgIdx, bool enable);

/*!
 * Set CCM LPCG low-power mode setting for specified CPU
 *
 * @param[in]       lpcgIdx         LPCG register index
 * @param[in]       cpuIdx          CPU Id
 * @param[in]       cpuLpmSetting   CPU low-power mode setting
 *
 * This function allows caller set LPCG low-power mode setting for specified
 * CPU.
 *
 * @return Returns true if LPCG low-power mode setting for specified CPU is
 *         updated.
 */
bool CCM_LpcgLpmSet(uint32_t lpcgIdx, uint32_t cpuIdx, uint32_t cpuLpmSetting);

/*!
 * Get CCM LPCG low-power mode setting for specified CPU
 *
 * @param[in]       lpcgIdx         LPCG register index
 * @param[in]       cpuIdx          CPU Id
 * @param[out]      cpuLpmSetting   CPU low-power mode setting
 *
 * This function allows caller get LPCG low-power mode setting for specified
 * CPU.
 *
 * @return Returns true if LPCG low-power mode setting for specified CPU is
 *         found.
 */
bool CCM_LpcgLpmGet(uint32_t lpcgIdx, uint32_t cpuIdx, uint32_t *cpuLpmSetting);

/*!
 * Set CCM LPCG LPM mode
 *
 * @param[in]       lpcgIdx         LPCG register index
 * @param[in]       lpcgMode        LPM mode for LPCG (1=enable, 0=disable)
 *
 * This function allows caller to set CPULPM mode for the given LPCG.
 *
 * @return Returns true if LPCG CPULPM mode is set successfully, otherwise
 *         false.
 */
bool CCM_LpcgModeSet(uint32_t lpcgIdx, uint32_t lpcgMode);

/*!
 * Set CCM LPCG access control list
 *
 * @param[in]       lpcgIdx         LPCG register index
 * @param[in]       accessList      LPCG access control list
 *
 * This function allows the caller to set the access control list for the given
 * LPCG.
 *
 * @return Returns true if LPCG access control list is set successfully, 
 *         otherwise false.
 */
bool CCM_LpcgAccessSet(uint32_t lpcgIdx, uint32_t accessList);

/*!
 * Get CCM LPCG access control list
 *
 * @param[in]       lpcgIdx         LPCG register index
 * @param[out]      accessList      LPCG access control list
 *
 * This function allows the caller to get the access control list for the given
 * LPCG.
 *
 * @return Returns true if LPCG access control list is read successfully, 
 *         otherwise false.
 */
bool CCM_LpcgAccessGet(uint32_t lpcgIdx, uint32_t *accessList);

/*!
 * Set CCM LPCG clock off handshake timeout enable
 *
 * @param[in]       lpcgIdx         LPCG register index
 * @param[in]       enable          Enable flag (1=enable, 0=disable)
 *
 * This function allows caller to enable/disable clock off handshake timeout
 * enable. When enabled, clock off acknowledge will be ignored and wait for
 * IPG clock timeout, when disabled, wait for clock off acknowledge.
 *
 * @return Returns true if LPCG clock off handshake timeout flag is set
 *         successfully, otherwise false.
 */
bool CCM_LpcgTimeoutSetEnable(uint32_t lpcgIdx, bool enable);

/** @} */

/* Externs */

#endif /* FSL_CCM_H */

/** @} */

