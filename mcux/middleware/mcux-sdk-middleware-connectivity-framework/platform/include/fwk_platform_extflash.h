/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2023 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_PLATFORM_EXTFLASH_H_
#define _FWK_PLATFORM_EXTFLASH_H_

/*!
 * @addtogroup FWK_Platform_module
 * @{
 */
/*!
 * @addtogroup FWK_Platform_Flash
 * The FWK_Platform_Flash module
 *
 * FWK_Platform_Flash module provides APIs to handle internal/external flash
 * operations specific to the platform
 * @{
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>

/* -------------------------------------------------------------------------- */
/*                                Public macros                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Initialize platform specific ressources for external flash
 *
 * \return int 0 on success, other on failure
 */
int PLATFORM_InitExternalFlash(void);

/*!
 * \brief Uninitialize the external flash
 *
 * \return int 0 on success, other on failure
 */
int PLATFORM_UninitExternalFlash(void);

/*!
 * \brief Reinitialize the external flash after exiting low power mode
 *
 * \return int 0 on success, other on failure
 */
int PLATFORM_ReinitExternalFlash(void);

/*!
 * \brief Erase a range of external flash
 *
 * \param[in] address address to start erasing from
 * \param[in] size size to erase
 * \return 0 on success, other on failure
 */
int PLATFORM_EraseExternalFlash(uint32_t address, uint32_t size);

/*!
 * \brief Read data from the external flash
 *
 * \param[out] dest output buffer where the data is stored, provided by the caller
 * \param[in] length size of the data to read
 * \param[in] address address to start reading from
 * \param[in] requestFastRead request fast read or not (if the feature is supported)
 * \return 0  on success, other on failure
 */
int PLATFORM_ReadExternalFlash(uint8_t *dest, uint32_t length, uint32_t address, bool requestFastRead);

/*!
 * \brief Write data to the external flash
 *
 * \param[in] data input buffer containing the data to write to the external flash
 * \param[in] length size of the data to be written
 * \param[in] address address to start writing from
 * \return 0 on success, other on failure
 */
int PLATFORM_WriteExternalFlash(uint8_t *data, uint32_t length, uint32_t address);

/*!
 * \brief Check busy status of the external flash
 *
 * \param[out] isBusy true for busy, false for idle
 * \return 0 on success, other on failure
 */
int PLATFORM_IsExternalFlashBusy(bool *isBusy);

/*!
 * \brief Tell whether Flash area is blank
 *
 * \param[in] address address from which to start check
 * \param[in] len     length of area
 *
 * \return true if area in range [address..address+len[ is containing all 0xff.
 */
bool PLATFORM_ExternalFlashAreaIsBlank(uint32_t address, uint32_t len);

/*!
 * \brief Tell whether Flash Page is blank
 *
 * \param[in] address
 * \return true if page containing address if all 0xff
 */
bool PLATFORM_IsExternalFlashPageBlank(uint32_t address);

/*!
 * \brief Tell whether Flash Sector is blank
 *
 * \param[in] address
 * \return true if sector containing address is all 0xff
 */
bool PLATFORM_IsExternalFlashSectorBlank(uint32_t address);
/*!
 * @}  end of FWK_Platform_Flash addtogroup
 */
/*!
 * @}  end of FWK_Platform_module addtogroup
 */

#endif /* _FWK_PLATFORM_EXTFLASH_H_ */
