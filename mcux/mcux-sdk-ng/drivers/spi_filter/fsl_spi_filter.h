/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_SPI_FILTER_H_
#define FSL_SPI_FILTER_H_

#include "fsl_common.h"

/*!
 * @addtogroup spi_filter
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
#define FSL_SPI_FILTER_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

#define FSL_SPI_FILTER_PORT_COUNT                (2U)
#define FSL_SPI_FILTER_FEATURE_OPCODE_COUNT      (5U)
#define FSL_SPI_FILTER_FEATURE_ADDR_REGION_COUNT (6U)

/*! @brief SPI Filter port selection. */
typedef enum _spi_filter_port
{
    kSPI_FilterPort0 = 0U, /*!< SPI Filter port 0. */
    kSPI_FilterPort1 = 1U, /*!< SPI Filter port 1. */
} spi_filter_port_t;

/*! @brief SPI Filter address mode. */
typedef enum _spi_filter_address_mode
{
    kSPI_Filter3ByteAddrMode = 0U, /*!< 3-byte address mode. */
    kSPI_Filter4ByteAddrMode = 1U, /*!< 4-byte address mode. */
} spi_filter_addr_mode_t;

/*! @brief SPI Filter flash mode. */
typedef enum _spi_filter_flash_mode
{
    kSPI_FilterDualFlashCS0Active = 0U, /*!< Dual flash mode, CS0 for read, CS1 for write. */
    kSPI_FilterDualFlashCS1Active = 1U, /*!< Dual flash mode, CS0 for write, CS1 for read. */
    kSPI_FilterSingleFlashCS0     = 2U, /*!< Single flash mode using CS0. */
    kSPI_FilterSingleFlashCS1     = 3U, /*!< Single flash mode using CS1. */
} spi_filter_flash_mode_t;

/*! @brief SPI Filter bypass mode. */
typedef enum _spi_filter_bypass_mode
{
    kSPI_FilterBypassNone = 0U, /*!< No bypass. */
    kSPI_FilterBypassCS0  = 1U, /*!< Bypass to CS0. */
    kSPI_FilterBypassCS1  = 2U, /*!< Bypass to CS1. */
} spi_filter_bypass_mode_t;

/*! @brief SPI Filter manufacturer. */
typedef enum _spi_filter_manufacturer
{
    kSPI_FilterMacronix = 0U, /*!< Macronix. */
    kSPI_FilterWinbond  = 1U, /*!< Winbond. */
    kSPI_FilterMicron   = 2U, /*!< Micron. */
} spi_filter_manufacturer_t;

/*! @brief SPI Filter interrupt enable flags. */
enum _spi_filter_interrupt_enable
{
    kSPI_FilterPort0F8InterruptEnable    = SPI_FILTER_IMR_P0_F8_MASK_MASK,    /*!< Port 0 F8 interrupt enable. */
    kSPI_FilterPort1F8InterruptEnable    = SPI_FILTER_IMR_P1_F8_MASK_MASK,    /*!< Port 1 F8 interrupt enable. */
    kSPI_FilterPort0DirtyInterruptEnable = SPI_FILTER_IMR_P0_DIRTY_MASK_MASK, /*!< Port 0 dirty interrupt enable. */
    kSPI_FilterPort1DirtyInterruptEnable = SPI_FILTER_IMR_P1_DIRTY_MASK_MASK, /*!< Port 1 dirty interrupt enable. */
    kSPI_FilterPort0BlockInterruptEnable = SPI_FILTER_IMR_P0_BLK_MASK_MASK,   /*!< Port 0 block interrupt enable. */
    kSPI_FilterPort1BlockInterruptEnable = SPI_FILTER_IMR_P1_BLK_MASK_MASK,   /*!< Port 1 block interrupt enable. */
    kSPI_FilterPort0ByteModeInterruptEnable =
        SPI_FILTER_IMR_P0_BYTEMODE_MASK_MASK,                                 /*!< Port 0 byte mode interrupt enable. */
    kSPI_FilterPort1ByteModeInterruptEnable =
        SPI_FILTER_IMR_P1_BYTEMODE_MASK_MASK,                                 /*!< Port 1 byte mode interrupt enable. */
};

/*! @brief SPI Filter status flags. */
enum _spi_filter_status_flags
{
    kSPI_FilterPort0DirtyFlag    = SPI_FILTER_SR_P0_DIRTY_MASK,     /*!< Port 0 dirty flag. */
    kSPI_FilterPort1DirtyFlag    = SPI_FILTER_SR_P1_DIRTY_MASK,     /*!< Port 1 dirty flag. */
    kSPI_FilterPort0ByteModeFlag = SPI_FILTER_SR_P0_BYTE_MODE_MASK, /*!< Port 0 byte mode flag. */
    kSPI_FilterPort1ByteModeFlag = SPI_FILTER_SR_P1_BYTE_MODE_MASK, /*!< Port 1 byte mode flag. */
    kSPI_FilterPort0WriteEnFlag  = SPI_FILTER_SR_P0_WRITE_EN_MASK,  /*!< Port 0 write enable flag. */
    kSPI_FilterPort1WriteEnFlag  = SPI_FILTER_SR_P1_WRITE_EN_MASK,  /*!< Port 1 write enable flag. */
};

/*! @brief SPI Filter interrupt status flags. */
enum _spi_filter_interrupt_status_flags
{
    kSPI_FilterPort0F8InterruptFlag    = SPI_FILTER_ISR_P0_F8_INT_MASK,    /*!< Port 0 F8 interrupt flag. */
    kSPI_FilterPort1F8InterruptFlag    = SPI_FILTER_ISR_P1_F8_INT_MASK,    /*!< Port 1 F8 interrupt flag. */
    kSPI_FilterPort0DirtyInterruptFlag = SPI_FILTER_ISR_P0_DIRTY_INT_MASK, /*!< Port 0 dirty interrupt flag. */
    kSPI_FilterPort1DirtyInterruptFlag = SPI_FILTER_ISR_P1_DIRTY_INT_MASK, /*!< Port 1 dirty interrupt flag. */
    kSPI_FilterPort0BlockInterruptFlag = SPI_FILTER_ISR_P0_BLK_INT_MASK,   /*!< Port 0 block interrupt flag. */
    kSPI_FilterPort1BlockInterruptFlag = SPI_FILTER_ISR_P1_BLK_INT_MASK,   /*!< Port 1 block interrupt flag. */
    kSPI_FilterPort0ByteModeInterruptFlag =
        SPI_FILTER_ISR_P0_BYTEMODE_INT_MASK,                               /*!< Port 0 byte mode interrupt flag. */
    kSPI_FilterPort1ByteModeInterruptFlag =
        SPI_FILTER_ISR_P1_BYTEMODE_INT_MASK,                               /*!< Port 1 byte mode interrupt flag. */
};

/*! @brief SPI Filter configuration structure. */
typedef struct _spi_filter_port_config
{
    bool enableFilter;                      /*!< Enable SPI filter. */
    spi_filter_addr_mode_t addrMode;        /*!< Address mode. */
    bool fixedAddrMode;                     /*!< Fixed address mode enable. */
    bool lockAddrMode;                      /*!< Lock address byte mode. Block the mode change command. */
    bool writeEnableAddrMode;               /*!< Write enable required for byte address mode switch. */
    spi_filter_flash_mode_t flashMode;      /*!< Flash mode. */
    bool singleFlashAllowWrite;             /*!< Allow write to unfiltered regions in single flash mode. */
    spi_filter_bypass_mode_t bypassMode;    /*!< Bypass mode. */
    spi_filter_manufacturer_t manufacturer; /*!< Manufacturer. */
    uint32_t maxFlashSize;                  /*!< Maximum flash size in bytes. Set to 0 to disable. */
} spi_filter_port_config_t;

/*! @brief SPI Filter configuration structure */
typedef struct _spi_filter_config
{
    spi_filter_port_config_t portConfig[FSL_SPI_FILTER_PORT_COUNT];
} spi_filter_config_t;

/*! @brief SPI Filter region configuration structure. */
typedef struct _spi_filter_region
{
    uint32_t startAddr; /*!< Region start address. */
    uint32_t endAddr;   /*!< Region end address. */
} spi_filter_region_t;

/*! @brief SPI Filter programmable opcode configuration. */
typedef struct _spi_filter_opcode
{
    uint8_t opcode;    /*!< Opcode value. */
    uint8_t state;     /*!< Filter state. */
    bool filter8thBit; /*!< Filter after 8th bit (true) or 7th bit (false). */
} spi_filter_opcode_t;

/*! @brief SPI Filter callback function pointer. */
typedef void (*spi_filter_callback_t)(SPI_FILTER_Type *base, spi_filter_port_t port, uint32_t status, void *userData);

/*! @brief SPI Filter handle structure. */
typedef struct _spi_filter_handle
{
    spi_filter_callback_t callback; /*!< Callback function. */
    void *userData;                 /*!< User data. */
} spi_filter_handle_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Initializes the SPI Filter peripheral.
 *
 * This function enables the SPI Filter clock and configures all filter ports
 * using the per-port configuration entries in `config->portConfig[]`.
 *
 * @param base SPI Filter peripheral base address.
 * @param config Pointer to the configuration structure.
 */
void SPI_FILTER_Init(SPI_FILTER_Type *base, const spi_filter_config_t *config);

/*!
 * @brief Deinitializes the SPI Filter peripheral.
 *
 * This function disables the SPI Filter peripheral and gates the SPI Filter clock.
 *
 * @param base SPI Filter peripheral base address.
 */
void SPI_FILTER_Deinit(SPI_FILTER_Type *base);

/*!
 * @brief Gets the default configuration structure.
 *
 * This function initializes the SPI Filter configuration structure to default values.
 *
 * @param config Pointer to the configuration structure.
 */
void SPI_FILTER_GetDefaultConfig(spi_filter_config_t *config);

/*! @} */

/*!
 * @name Status
 * @{
 */

/*!
 * @brief Gets the SPI Filter status flags.
 *
 * @param base SPI Filter peripheral base address.
 * @return Status flags. Use bitwise AND with #_spi_filter_status_flags to check specific status bits.
 */
static inline uint32_t SPI_FILTER_GetStatusFlags(SPI_FILTER_Type *base)
{
    return base->SR;
}

/*! @} */

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enables the SPI Filter interrupts.
 *
 * @param base SPI Filter peripheral base address.
 * @param mask Interrupt source, see #_spi_filter_interrupt_enable.
 */
static inline void SPI_FILTER_EnableInterrupts(SPI_FILTER_Type *base, uint32_t mask)
{
    base->IMR &= ~mask;
}

/*!
 * @brief Disables the SPI Filter interrupts.
 *
 * @param base SPI Filter peripheral base address.
 * @param mask Interrupt source, see #_spi_filter_interrupt_enable.
 */
static inline void SPI_FILTER_DisableInterrupts(SPI_FILTER_Type *base, uint32_t mask)
{
    base->IMR |= mask;
}

/*!
 * @brief Gets the enabled SPI Filter interrupts.
 *
 * @param base SPI Filter peripheral base address.
 * @return Enabled interrupts, see #_spi_filter_interrupt_enable.
 */
static inline uint32_t SPI_FILTER_GetEnabledInterrupts(SPI_FILTER_Type *base)
{
    /* Inverted because 0 = enabled, 1 = disabled. */
    return ~(base->IMR);
}

/*!
 * @brief Gets the SPI Filter interrupt status.
 *
 * @param base SPI Filter peripheral base address.
 * @return Interrupt status, see #_spi_filter_interrupt_status_flags.
 */
static inline uint32_t SPI_FILTER_GetInterruptStatus(SPI_FILTER_Type *base)
{
    return base->ISR;
}

/*! @} */

/*!
 * @name Filter Configuration
 * @{
 */

/*!
 * @brief Enables or disables the SPI filter.
 *
 * @param base SPI Filter peripheral base address.
 * @param port SPI Filter port.
 * @param enable True to enable, false to disable.
 */
void SPI_FILTER_Enable(SPI_FILTER_Type *base, spi_filter_port_t port, bool enable);

/*!
 * @brief Sets the flash manufacturer ID for a specific port.
 *
 * This function configures the manufacturer ID which is used by the filter logic
 * to distinguish between opcodes that are common between manufacturers but have
 * different functions and therefore require different actions by the filter.
 *
 * Supported manufacturers:
 * - Macronix (kSPI_FilterMacronix)
 * - Winbond (kSPI_FilterWinbond)
 * - Micron (kSPI_FilterMicron)
 *
 * @param base SPI Filter peripheral base address.
 * @param port SPI Filter port (kSPI_FilterPort0 or kSPI_FilterPort1).
 * @param manufacturerID Flash manufacturer ID. See @ref spi_filter_manufacturer_t.
 */
void SPI_FILTER_SetManufacturerID(SPI_FILTER_Type *base,
                                  spi_filter_port_t port,
                                  spi_filter_manufacturer_t manufacturerID);

/*! @} */

/*!
 * @name Address Mode Configuration
 * @{
 */

/*!
 * @brief Gets the current address byte mode.
 *
 * @param base SPI Filter peripheral base address.
 * @param port SPI Filter port.
 * @return Current address mode.
 */
spi_filter_addr_mode_t SPI_FILTER_GetAddressMode(SPI_FILTER_Type *base, spi_filter_port_t port);

/*! @} */

/*!
 * @name Flash State Management
 * @{
 */

/*!
 * @brief Gets the flash dirty state.
 *
 * @param base SPI Filter peripheral base address.
 * @param port SPI Filter port.
 * @return Flash dirty state.
 */
bool SPI_FILTER_GetFlashDirtyState(SPI_FILTER_Type *base, spi_filter_port_t port);

/*!
 * @brief Clears the flash dirty state.
 *
 * @param base SPI Filter peripheral base address.
 * @param port SPI Filter port.
 */
void SPI_FILTER_ClearFlashDirtyState(SPI_FILTER_Type *base, spi_filter_port_t port);

/*! @} */

/*!
 * @name Bypass Mode Configuration
 * @{
 */

/*!
 * @brief Sets the bypass mode.
 *
 * @param base SPI Filter peripheral base address.
 * @param port SPI Filter port.
 * @param mode Bypass mode to set.
 */
void SPI_FILTER_SetBypassMode(SPI_FILTER_Type *base, spi_filter_port_t port, spi_filter_bypass_mode_t mode);

/*! @} */

/*!
 * @name Region Configuration
 * @{
 */

/*!
 * @brief Sets a filter read/write region.
 *
 * @param base SPI Filter peripheral base address.
 * @param port SPI Filter port.
 * @param region Region number.
 * @param config Pointer to region configuration.
 * @retval kStatus_Success Region configured successfully.
 * @retval kStatus_InvalidArgument Invalid region number or misaligned address.
 */
status_t SPI_FILTER_SetRegion(SPI_FILTER_Type *base,
                              spi_filter_port_t port,
                              uint8_t region,
                              const spi_filter_region_t *config);

/*!
 * @brief Clears all filter read/write regions.
 *
 * @param base SPI Filter peripheral base address.
 * @param port SPI Filter port.
 */
void SPI_FILTER_ClearAllRegions(SPI_FILTER_Type *base, spi_filter_port_t port);

/*! @} */

/*!
 * @name Programmable Opcode Configuration
 * @{
 */

/*!
 * @brief Configures a programmable opcode.
 *
 * @param base SPI Filter peripheral base address.
 * @param idx Opcode index.
 * @param config Pointer to opcode configuration.
 * @retval kStatus_Success Opcode configured successfully.
 * @retval kStatus_InvalidArgument Invalid opcode index.
 */
status_t SPI_FILTER_ConfigureOpcode(SPI_FILTER_Type *base, uint8_t idx, const spi_filter_opcode_t *config);

/*!
 * @brief Gets the blocked opcode for a port.
 *
 * @param base SPI Filter peripheral base address.
 * @param port SPI Filter port.
 * @return Last blocked opcode value.
 */
uint32_t SPI_FILTER_GetBlockedOpcode(SPI_FILTER_Type *base, spi_filter_port_t port);

/*! @} */

/*!
 * @name Max Address Mask Configuration
 * @{
 */

/*!
 * @brief Sets the maximum flash size for address filtering.
 *
 * This function configures the maximum addressable flash size for the specified port.
 * Addresses beyond this size will be filtered/blocked by the SPI filter.
 * Set to 0 to disable the maximum flash size check.
 *
 * @param base SPI Filter peripheral base address.
 * @param port SPI Filter port.
 * @param size Maximum flash size in bytes. Set to 0 to disable.
 */
void SPI_FILTER_SetMaxFlashSize(SPI_FILTER_Type *base, spi_filter_port_t port, uint32_t size);

/*! @} */

/*!
 * @name Transactional
 * @{
 */

/*!
 * @brief Initializes the SPI Filter handle.
 *
 * @param base SPI Filter peripheral base address.
 * @param handle Pointer to the SPI Filter handle.
 * @param port SPI Filter port.
 * @param callback Callback function.
 * @param userData User data.
 */
void SPI_FILTER_TransferCreateHandle(SPI_FILTER_Type *base,
                                     spi_filter_handle_t *handle,
                                     spi_filter_port_t port,
                                     spi_filter_callback_t callback,
                                     void *userData);

/*!
 * @brief SPI Filter IRQ handle function.
 *
 * This function handles the SPI Filter IRQ request.
 *
 * @param base SPI Filter peripheral base address.
 * @param handle Pointer to the SPI Filter handle.
 */
void SPI_FILTER_HandleIRQ(SPI_FILTER_Type *base, spi_filter_handle_t *handle);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_SPI_FILTER_H_ */
