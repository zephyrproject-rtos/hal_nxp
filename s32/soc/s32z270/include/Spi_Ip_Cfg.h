/*
 * Copyright 2022-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SPI_IP_CFG_H
#define SPI_IP_CFG_H

/**
*   @file    Spi_Ip_Cfg.h
*   @version 2.0.1
*
*   @brief   AUTOSAR Spi - Spi configuration header file.
*   @details This file is the header containing all the necessary information for SPI
*            module configuration(s).
*   @addtogroup SPI_IP_DRIVER_CONFIGURATION Spi Ip Driver Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
* 4) user callback header files
==================================================================================================*/
#include <zephyr/devicetree.h>
#include "Mcal.h"
#include "OsIf.h"
#include "Spi_Ip_Sa_Init_PBcfg.h"
#include "S32Z2_SPI.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IP_VENDOR_ID_CFG                       43
#define SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG        4
#define SPI_IP_AR_RELEASE_MINOR_VERSION_CFG        7
#define SPI_IP_AR_RELEASE_REVISION_VERSION_CFG     0
#define SPI_IP_SW_MAJOR_VERSION_CFG                2
#define SPI_IP_SW_MINOR_VERSION_CFG                0
#define SPI_IP_SW_PATCH_VERSION_CFG                1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_IP_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_Ip_Cfg.h and Mcal.h are different"
    #endif

    /* Check if the current file and OsIf.h header file are of the same version */
    #if ((SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_IP_AR_RELEASE_MINOR_VERSION_CFG != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Spi_Ip_Cfg.h and OsIf.h are different"
    #endif
#endif

/* Check if Spi_Ip_INIT_PBcfg header file and Spi configuration header file are of the same vendor */
#if (SPI_IP_SA_INIT_VENDOR_ID_PBCFG != SPI_IP_VENDOR_ID_CFG)
    #error "Spi_Ip_Sa_INIT_PBcfg.h and Spi_Ip_Cfg.h have different vendor IDs"
#endif
    /* Check if Spi_Ip_INIT_PBcfg header file and Spi  configuration header file are of the same Autosar version */
#if ((SPI_IP_SA_INIT_AR_RELEASE_MAJOR_VERSION_PBCFG != SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SPI_IP_SA_INIT_AR_RELEASE_MINOR_VERSION_PBCFG != SPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SPI_IP_SA_INIT_AR_RELEASE_REVISION_VERSION_PBCFG != SPI_IP_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Spi_Ip_Sa_INIT_PBcfg.h and Spi_Ip_Cfg.h are different"
#endif
/* Check if Spi_Ip_INIT_PBcfg header file and Spi configuration header file are of the same software version */
#if ((SPI_IP_SA_INIT_SW_MAJOR_VERSION_PBCFG != SPI_IP_SW_MAJOR_VERSION_CFG) || \
     (SPI_IP_SA_INIT_SW_MINOR_VERSION_PBCFG != SPI_IP_SW_MINOR_VERSION_CFG) || \
     (SPI_IP_SA_INIT_SW_PATCH_VERSION_PBCFG != SPI_IP_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Spi_Ip_Sa_INIT_PBcfg.h and Spi_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                            CONSTANTS
==================================================================================================*/
#define SPI_IP_CONFIG_EXT \
    SPI_IP_SA_CONFIG_INIT_PB \

/** @brief Total number of SpiPhyUnit configured as SPI. */
#define SPI_IP_NUMBER_OF_INSTANCES (DT_NUM_INST_STATUS_OKAY(nxp_s32_spi))

/** @brief Number of FIFO entries supported */
#define SPI_IP_FIFO_SIZE_U16    ((uint16)5U)

/** @brief Enable Spi Slave Support */
#define SPI_IP_SLAVE_SUPPORT  IS_ENABLED(CONFIG_SPI_SLAVE)

/**
* @brief Defines if transfers are made using DMA or FIFO.
* @details Defines if transfers are made using DMA or FIFO.
*/
#define SPI_IP_DMA_USED    (STD_OFF)

/**
* @brief If enabled, allows dual MCU clock configuration settings.
* @details If enabled, allows dual MCU clock configuration settings.
*/
#define SPI_IP_DUAL_CLOCK_MODE  (STD_OFF)

/**
* @brief          Enable Dma Fast transfer support.
* @details        When SpiEnableDmaFastTransferSupport = TRUE,
*                 the SPI driver can be supported to transmit multiple transfers and CPU used only for processing end of sequence transfer.
*/
#define SPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT  (STD_OFF)

 /**
* @brief          Enable User Mode Support.
* @details        When SpiEnableUserModeSupport = TRUE,
*                 the SPI driver can be executed from both supervisor and user mode.
*
* @api
*/
#define SPI_IP_ENABLE_USER_MODE_SUPPORT           (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef SPI_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == SPI_IP_ENABLE_USER_MODE_SUPPORT)
   #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running  Spi in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == SPI_IP_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef MCAL_ENABLE_USER_MODE_SUPPORT */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT*/

/**
* @brief SPI registers is controlled by REG_PROT IP.
*/
#define SPI_IP_REG_PROT_AVAILABLE   (STD_OFF)

#if (STD_ON == SPI_IP_REG_PROT_AVAILABLE)
/**
* @brief The protection size
*/
    #define SPI_IP_PROT_MEM_U32                           ((uint32)4U)
#endif
/**
* @brief Maximum of frame size supported.
*/
#define SPI_IP_FRAMESIZE_MAX_U8                              ((uint8)32U)

/**
* @brief Minimum of frame size supported.
*/
#define SPI_IP_FRAMESIZE_MIN_U8                              ((uint8)4U)

/**
* @brief Define Timeout Method.
* @details Define a certain timeout method from OsIf will be used in the driver.
*/
#define SPI_IP_TIMEOUT_METHOD     (OSIF_COUNTER_SYSTEM)

/**
* @brief Switches ON or OFF for the detection and reporting of development errors(API parameter checking) at IP level.
*/
/** @implements SPI_IP_DEV_ERROR_DETECT_define  */
#define SPI_IP_DEV_ERROR_DETECT     (STD_OFF)
/*==================================================================================================
 *                                     DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
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
#endif

/** @} */
