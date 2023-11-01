/*
 * Copyright 2021-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    Siul2_Port_Ip.c
*
*   @addtogroup Port_IPL
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
#include "Siul2_Port_Ip.h"
#include "SchM_Port.h"
#ifdef PORT_ENABLE_USER_MODE_SUPPORT
   #define USER_MODE_REG_PROT_ENABLED   (PORT_ENABLE_USER_MODE_SUPPORT)
   #include "RegLockMacros.h"
   #include "OsIf_Internal.h"
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define SIUL2_PORT_IP_VENDOR_ID_C                     43
#define SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_C      4
#define SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_C      7
#define SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_C   0
#define SIUL2_PORT_IP_SW_MAJOR_VERSION_C              1
#define SIUL2_PORT_IP_SW_MINOR_VERSION_C              0
#define SIUL2_PORT_IP_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Siul2_Port_Ip.c and Siul2_Port_Ip.h are of the same version */
#if (SIUL2_PORT_IP_VENDOR_ID_C != SIUL2_PORT_IP_VENDOR_ID_H)
    #error "Siul2_Port_Ip.c and Siul2_Port_Ip.h have different vendor ids"
#endif
/* Check if Siul2_Port_Ip.c and Siul2_Port_Ip.h are of the same Autosar version */
#if ((SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_C    != SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_C    != SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_C != SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Siul2_Port_Ip.c and Siul2_Port_Ip.h are different"
#endif
/* Check if Siul2_Port_Ip.c and Siul2_Port_Ip.h are of the same Software version */
#if ((SIUL2_PORT_IP_SW_MAJOR_VERSION_C != SIUL2_PORT_IP_SW_MAJOR_VERSION_H) || \
     (SIUL2_PORT_IP_SW_MINOR_VERSION_C != SIUL2_PORT_IP_SW_MINOR_VERSION_H) || \
     (SIUL2_PORT_IP_SW_PATCH_VERSION_C != SIUL2_PORT_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Siul2_Port_Ip.c and Siul2_Port_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #ifdef PORT_ENABLE_USER_MODE_SUPPORT
        /* Check if the files Siul2_Port_Ip.c and RegLockMacros.h are of the same version */
        #if ((SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
             (SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of Siul2_Port_Ip.c and RegLockMacros.h are different"
        #endif
        /* Check if the files Siul2_Port_Ip.c and OsIf_Internal.h are of the same version */
        #if ((SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
             (SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_INTERNAL_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of Siul2_Port_Ip.c and OsIf_Internal.h are different"
        #endif
    #endif /* PORT_ENABLE_USER_MODE_SUPPORT */
    /* Check if the files Siul2_Port_Ip.c and SchM_Port.h are of the same version */
    #if ((SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_PORT_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_PORT_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Siul2_Port_Ip.c and SchM_Port.h are different"
    #endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#define SIUL2_NUM_OF_PIN_PORT_U16           ((uint16)16u)

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#if (defined(MCAL_ENABLE_USER_MODE_SUPPORT) && defined(PORT_ENABLE_USER_MODE_SUPPORT) && (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT))
    #define Call_Siul2_Port_Ip_PinInit(config)                                                  OsIf_Trusted_Call1param(Siul2_Port_Ip_PinInit, (config))
    #define Call_Siul2_Port_Ip_ConfigInternalResistor(base, pin, pullConfig)                    OsIf_Trusted_Call3params(Siul2_Port_Ip_ConfigInternalResistor, (base), (pin), (pullConfig))
    #define Call_Siul2_Port_Ip_ConfigOutputBuffer(base, pin, enable, mux)                       OsIf_Trusted_Call4params(Siul2_Port_Ip_ConfigOutputBuffer, (base), (pin), (enable), (mux))
    #define Call_Siul2_Port_Ip_ConfigInputBuffer(base, pin, enable, inputMuxReg, inputMux)      OsIf_Trusted_Call5params(Siul2_Port_Ip_ConfigInputBuffer, (base), (pin), (enable), (inputMuxReg), (inputMux))
    #define Call_Siul2_Port_Ip_ConfigPinDirection(base, pin, direction)                         OsIf_Trusted_Call3params(Siul2_Port_Ip_ConfigPinDirection, (base), (pin), (direction))
    #define Call_Siul2_Port_Ip_GetValueConfigRevertPin(base, pin)                               OsIf_Trusted_Call_Return2param(Siul2_Port_Ip_GetValueConfigRevertPin, (base), (pin))
    #define Call_Siul2_Port_Ip_GetValuePinConfiguration(base, config, pin)                      OsIf_Trusted_Call3params(Siul2_Port_Ip_GetValuePinConfiguration, (base), (config), (pin))
#else
    #define Call_Siul2_Port_Ip_PinInit(config)                                                  Siul2_Port_Ip_PinInit(config)
    #define Call_Siul2_Port_Ip_ConfigInternalResistor(base, pin, pullConfig)                    Siul2_Port_Ip_ConfigInternalResistor(base, pin, pullConfig)
    #define Call_Siul2_Port_Ip_ConfigOutputBuffer(base, pin, enable, mux)                       Siul2_Port_Ip_ConfigOutputBuffer(base, pin, enable, mux)
    #define Call_Siul2_Port_Ip_ConfigInputBuffer(base, pin, enable, inputMuxReg, inputMux)      Siul2_Port_Ip_ConfigInputBuffer(base, pin, enable, inputMuxReg, inputMux)
    #define Call_Siul2_Port_Ip_ConfigPinDirection(base, pin, direction)                         Siul2_Port_Ip_ConfigPinDirection(base, pin, direction)
    #define Call_Siul2_Port_Ip_GetValueConfigRevertPin(base, pin)                               Siul2_Port_Ip_GetValueConfigRevertPin(base, pin)
    #define Call_Siul2_Port_Ip_GetValuePinConfiguration(base, config, pin)                      Siul2_Port_Ip_GetValuePinConfiguration(base, config, pin)
#endif
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define PORT_START_SEC_CONST_32
#include "Port_MemMap.h"

#if (STD_ON == PORT_VIRTWRAPPER_SUPPORT)
/**
* @brief Base address array for Siul2 instances
*/
const uint32 Port_au32Siul2BaseAddr[SIUL2_PDAC_BASE_NUM][SIUL2_PDAC_SLOT]=
{
    {
        #ifdef SIUL2_0_PDAC0_BASE
        SIUL2_0_PDAC0_BASE,
        #endif
        #ifdef SIUL2_0_PDAC1_BASE
        SIUL2_0_PDAC1_BASE,
        #endif
        #ifdef SIUL2_0_PDAC2_BASE
        SIUL2_0_PDAC2_BASE,
        #endif
        #ifdef SIUL2_0_PDAC3_BASE
        SIUL2_0_PDAC3_BASE,
        #endif
    },
    {
        #ifdef SIUL2_1_PDAC0_BASE
        SIUL2_1_PDAC0_BASE,
        #endif
        #ifdef SIUL2_1_PDAC1_BASE
        SIUL2_1_PDAC1_BASE,
        #endif
        #ifdef SIUL2_1_PDAC2_BASE
        SIUL2_1_PDAC2_BASE,
        #endif
        #ifdef SIUL2_1_PDAC3_BASE
        SIUL2_1_PDAC3_BASE,
        #endif
    },
    {
        #ifdef SIUL2_3_PDAC0_BASE
        SIUL2_3_PDAC0_BASE,
        #endif
        #ifdef SIUL2_3_PDAC1_BASE
        SIUL2_3_PDAC1_BASE,
        #endif
        #ifdef SIUL2_3_PDAC2_BASE
        SIUL2_3_PDAC2_BASE,
        #endif
        #ifdef SIUL2_3_PDAC3_BASE
        SIUL2_3_PDAC3_BASE,
        #endif
    },
    {
        #ifdef SIUL2_4_PDAC0_BASE
        SIUL2_4_PDAC0_BASE,
        #endif
        #ifdef SIUL2_4_PDAC1_BASE
        SIUL2_4_PDAC1_BASE,
        #endif
        #ifdef SIUL2_4_PDAC2_BASE
        SIUL2_4_PDAC2_BASE,
        #endif
        #ifdef SIUL2_4_PDAC3_BASE
        SIUL2_4_PDAC3_BASE,
        #endif
    },
    {
        #ifdef SIUL2_5_PDAC0_BASE
        SIUL2_5_PDAC0_BASE,
        #endif
        #ifdef SIUL2_5_PDAC1_BASE
        SIUL2_5_PDAC1_BASE,
        #endif
        #ifdef SIUL2_5_PDAC2_BASE
        SIUL2_5_PDAC2_BASE,
        #endif
        #ifdef SIUL2_5_PDAC3_BASE
        SIUL2_5_PDAC3_BASE,
        #endif
    }
};
#else
/**
* @brief Base address array for Siul2 instances
*/
const uint32 Port_au32Siul2BaseAddr[] =
{
#ifdef IP_SIUL2_BASE
    IP_SIUL2_BASE
#endif
#ifdef IP_SIUL2_0_BASE
    IP_SIUL2_0_BASE
#endif
#ifdef IP_SIUL2_1_BASE
    ,IP_SIUL2_1_BASE
#endif
#ifdef IP_SIUL2_3_BASE
    ,IP_SIUL2_3_BASE
#endif
#ifdef IP_SIUL2_4_BASE
    ,IP_SIUL2_4_BASE
#endif
#ifdef IP_SIUL2_5_BASE
    ,IP_SIUL2_5_BASE
#endif
#ifdef IP_SIUL2_AE_BASE
    ,IP_SIUL2_AE_BASE
#endif
};
#endif /* STD_ON == PORT_VIRTWRAPPER_SUPPORT */

#define PORT_STOP_SEC_CONST_32
#include "Port_MemMap.h"

#define PORT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Port_MemMap.h"

static const Siul2_Port_Ip_PinSettingsConfig * pPort_Setting;

#define PORT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Port_MemMap.h"

#define PORT_START_SEC_VAR_CLEARED_32
#include "Port_MemMap.h"

static uint32 u32MaxPinConfigured;

#define PORT_STOP_SEC_VAR_CLEARED_32
#include "Port_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
/*!
 * @brief Get the SIUL2 instance of the pin with the given configuration structure
 *
 * This function get the SIUL2 instance of the pin with the options provided in the
 * given structure.
 *
 * @param[in] config the configuration structure
  */
static inline uint8 Siul2_Port_Ip_GetSiulInstance(const Siul2_Port_Ip_PinSettingsConfig * config);


/*!
 * @brief Get the instance of Input Multiplexed Signal Configuration Register
 *
 */
static inline void Siul2_Port_Ip_GetIMCRInstance(const Siul2_Port_Ip_PinSettingsConfig * config,
                                                 uint32 * imcrRegIdx,
                                                 SIUL2_Type ** imcrBase,
                                                 uint8 inputMuxIterator
                                                );

#ifdef IP_SIUL2_AE_BASE
/*!
 * @brief Get the instance of Input Multiplexed Signal Configuration Register of SIUL2_AE
 *
 */
static inline void Siul2_Port_Ip_Siul2AE_GetIMCRInstance(const Siul2_Port_Ip_PinSettingsConfig * config,
                                                         uint32 * imcrRegIdx,
                                                         SIUL2_AE_Type ** imcrBase,
                                                         uint8 inputMuxIterator
                                                        );
#endif /* IP_SIUL2_AE_BASE */

/*!
 * @brief Write to Input Multiplexed Signal Configuration Register
 *
 * This function configures the register with the provided in the
 * given structure.
 *
 * @param[in] config the configuration structure
  */
static inline void Siul2_Port_Ip_WriteIMCRConfiguration(const Siul2_Port_Ip_PinSettingsConfig * config);

/*!
 * @brief Get the MSCR configuration from the MSCR register
 *
 * @param[in] pinNumber the number of configured pins in structure
 * @param[in] config the configuration structure
  */
static inline void Siul2_Port_Ip_GetMSCRConfiguration(Siul2_Port_Ip_PinSettingsConfig * config,
                                                      const Siul2_Port_Ip_PortType * const base,
                                                      uint16 pin
                                                     );

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
/*!
 * @brief Get the SIUL2 instance of the pin with the given configuration structure
 *
 * This function get the SIUL2 instance of the pin with the options provided in the
 * given structure.
 *
 * @param[in] config the configuration structure
  */
static inline uint8 Siul2_Port_Ip_GetSiulInstance(const Siul2_Port_Ip_PinSettingsConfig * config)
{
    uint8 siulInstance = 0U;

    SIUL2_PORT_IP_DEV_ASSERT((boolean)(config != NULL_PTR));
#ifdef IP_SIUL2
    if (config->base == IP_SIUL2)
    {
        siulInstance = 0U;
    }
#endif /* IP_SIUL2 */

#if (defined(IP_SIUL2_0) && (PORT_VIRTWRAPPER_SUPPORT == STD_ON))
    if ((config->base == IP_SIUL2_0) || (config->base == SIUL2_0_PDAC0) || (config->base == SIUL2_0_PDAC1) || (config->base == SIUL2_0_PDAC2) || (config->base == SIUL2_0_PDAC3))
    {
        siulInstance = 0U;
    }
#elif defined(IP_SIUL2_0)
    if (config->base == IP_SIUL2_0)
    {
        siulInstance = 0U;
    }
#endif /* (defined(IP_SIUL2_0) && (PORT_VIRTWRAPPER_SUPPORT == STD_ON)) */

#if (defined(IP_SIUL2_1) && (PORT_VIRTWRAPPER_SUPPORT == STD_ON))
    else if ((config->base == IP_SIUL2_1) || (config->base == SIUL2_1_PDAC0) || (config->base == SIUL2_1_PDAC1) || (config->base == SIUL2_1_PDAC2) || (config->base == SIUL2_1_PDAC3))
    {
        siulInstance = 1U;
    }
#elif defined(IP_SIUL2_1)
    else if (config->base == IP_SIUL2_1)
    {
        siulInstance = 1U;
    }
#endif /* (defined(IP_SIUL2_1) && (PORT_VIRTWRAPPER_SUPPORT == STD_ON)) */

#if (defined(IP_SIUL2_3) && (PORT_VIRTWRAPPER_SUPPORT == STD_ON))
    else if ((config->base == IP_SIUL2_3) || (config->base == SIUL2_3_PDAC0) || (config->base == SIUL2_3_PDAC1) || (config->base == SIUL2_3_PDAC2) || (config->base == SIUL2_3_PDAC3))
    {
        siulInstance = 2U;
    }
#elif defined(IP_SIUL2_3)
    else if (config->base == IP_SIUL2_3)
    {
        siulInstance = 2U;
    }
#endif /* (defined(IP_SIUL2_3) && (PORT_VIRTWRAPPER_SUPPORT == STD_ON)) */

#if (defined(IP_SIUL2_4) && (PORT_VIRTWRAPPER_SUPPORT == STD_ON))
    else if ((config->base == IP_SIUL2_4) || (config->base == SIUL2_4_PDAC0) || (config->base == SIUL2_4_PDAC1) || (config->base == SIUL2_4_PDAC2) || (config->base == SIUL2_4_PDAC3))
    {
        siulInstance = 3U;
    }
#elif defined(IP_SIUL2_4)
    else if (config->base == IP_SIUL2_4)
    {
        siulInstance = 3U;
    }
#endif /* (defined(IP_SIUL2_4) && (PORT_VIRTWRAPPER_SUPPORT == STD_ON)) */

#if (defined(IP_SIUL2_5) && (PORT_VIRTWRAPPER_SUPPORT == STD_ON))
    else if ((config->base == IP_SIUL2_5) || (config->base == SIUL2_5_PDAC0) || (config->base == SIUL2_5_PDAC1) || (config->base == SIUL2_5_PDAC2) || (config->base == SIUL2_5_PDAC3))
    {
        siulInstance = 4U;
    }
#elif defined(IP_SIUL2_5)
    else if (config->base == IP_SIUL2_5)
    {
        siulInstance = 4U;
    }
#endif /* (defined(IP_SIUL2_5) && (PORT_VIRTWRAPPER_SUPPORT == STD_ON)) */

#ifdef IP_SIUL2_AE
    else if (config->baseAE == IP_SIUL2_AE)
    {
        siulInstance = 5U;
    }
#endif /* IP_SIUL2_AE */
    else
    {
        /* Do nothing */
    }

    return siulInstance;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : PINS_Init
 * Description   : This function configures the pin feature with the options
 * provided in the given structure.
 *
 *END**************************************************************************/

/*!
 * @brief Initializes the pins with the given configuration structure
 *
 * This function configures the pins with the options provided in the
 * given structure.
 *
 * @param[in] pinNumber the number of configured pins in structure
 * @param[in] config the configuration structure
  */
void Siul2_Port_Ip_PinInit(const Siul2_Port_Ip_PinSettingsConfig * config)
{
    uint32 pinsValues = 0U;
    uint8 siulInstance = 0U;

    SIUL2_PORT_IP_DEV_ASSERT((boolean)(config != NULL_PTR));
    SIUL2_PORT_IP_DEV_ASSERT((boolean)(config->pinPortIdx < SIUL2_MSCR_COUNT));

    siulInstance = Siul2_Port_Ip_GetSiulInstance(config);

    if (config->pullConfig != PORT_INTERNAL_PULL_NOT_ENABLED)
    {
#ifdef IP_SIUL2_AE
        if (config->baseAE == IP_SIUL2_AE)
        {
            pinsValues |= SIUL2_AE_MSCR_PUE(1);
            pinsValues |= SIUL2_AE_MSCR_PUS(config->pullConfig);
        }
        else
#endif /* IP_SIUL2_AE */
        {
            pinsValues |= SIUL2_MSCR_PUE(1);
            pinsValues |= SIUL2_MSCR_PUS(config->pullConfig);
        }
    }
    if (PORT_OUTPUT_BUFFER_NOT_AVAILABLE != config->outputBuffer)
    {
#ifdef IP_SIUL2_AE
        if (config->baseAE == IP_SIUL2_AE)
        {
            pinsValues |= SIUL2_AE_MSCR_OBE(config->outputBuffer);
        }
        else
#endif /* IP_SIUL2_AE */
        {
            pinsValues |= SIUL2_MSCR_OBE(config->outputBuffer);
        }
    }
#ifdef FEATURE_SIUL2_PORT_IP_HAS_INVERT_DATA
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_INVERT_DATA)
    if (PORT_INVERT_NOT_AVAILABLE != config->invert)
    {
        pinsValues |= SIUL2_MSCR_INV(config->invert);
    }
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_INVERT_DATA */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_INVERT_DATA */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_PULL_KEEPER
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_PULL_KEEPER)
    if (PORT_PULL_KEEP_NOT_AVAILABLE != config->pullKeep)
    {
        pinsValues |= SIUL2_MSCR_PKE(config->pullKeep);
    }
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_PULL_KEEPER */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_PULL_KEEPER */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_RECEIVER_SELECT
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_RECEIVER_SELECT)
    if (PORT_RECEIVER_NOT_AVAILABLE != config->receiverSel)
    {
        pinsValues |= SIUL2_MSCR_RCVR(config->receiverSel);
    }
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_RECEIVER_SELECT*/
#endif /* FEATURE_SIUL2_PORT_IP_HAS_RECEIVER_SELECT*/
#ifdef FEATURE_SIUL2_PORT_IP_HAS_OPEN_DRAIN
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_OPEN_DRAIN)
    if (PORT_OPEN_DRAIN_NOT_AVAILABLE != config->openDrain)
    {
        pinsValues |= SIUL2_MSCR_ODE(config->openDrain);
    }
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_OPEN_DRAIN */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_OPEN_DRAIN */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_DRIVE_STRENGTH
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_DRIVE_STRENGTH)
    if (PORT_DRIVE_STRENTGTH_NOT_AVAILABLE != config->driveStrength)
    {
        pinsValues |= SIUL2_MSCR_DSE(config->driveStrength);
    }
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_DRIVE_STRENGTH */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_DRIVE_STRENGTH */
    if (PORT_INPUT_BUFFER_NOT_AVAILABLE != config->inputBuffer)
    {
#ifdef IP_SIUL2_AE
        if (config->baseAE == IP_SIUL2_AE)
        {
            pinsValues |= SIUL2_AE_MSCR_IBE(config->inputBuffer);
        }
        else
#endif /* IP_SIUL2_AE */
        {
            pinsValues |= SIUL2_MSCR_IBE(config->inputBuffer);
        }
    }
    if (PORT_SLEW_RATE_NOT_AVAILABLE != config->slewRateCtrlSel)
    {
#ifdef IP_SIUL2_AE
        if (config->baseAE == IP_SIUL2_AE)
        {
            pinsValues |= SIUL2_AE_MSCR_SRE(config->slewRateCtrlSel);
        }
        else
#endif /* IP_SIUL2_AE */
        {
            pinsValues |= SIUL2_MSCR_SRE(config->slewRateCtrlSel);
        }
    }
    if (PORT_SAFE_MODE_NOT_AVAILABLE != config->safeMode)
    {
        pinsValues |= SIUL2_MSCR_SMC(config->safeMode);
    }
#ifdef FEATURE_SIUL2_PORT_IP_HAS_TERMINATION_RESISTOR
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_TERMINATION_RESISTOR)
    if (PORT_TERMINATION_RESISTOR_NOT_AVAILABLE != config->terminationResistor)
    {
        pinsValues |= SIUL2_MSCR_TRC(config->terminationResistor);
    }
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_TERMINATION_RESISTOR */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_TERMINATION_RESISTOR */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_HYSTERESIS
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_HYSTERESIS)
    if (PORT_HYSTERESIS_NOT_AVAILABLE != config->hysteresis)
    {
#ifdef SIUL2_AE_MSCR_HYS_MASK
        if (config->baseAE == IP_SIUL2_AE)
        {
            pinsValues |= SIUL2_AE_MSCR_HYS(config->hysteresis);
        }
#endif
    }
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_HYSTERESIS */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_HYSTERESIS */

#ifdef FEATURE_SIUL2_PORT_IP_HAS_ANALOG_PAD_CONTROL
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_ANALOG_PAD_CONTROL)
    if (PORT_ANALOG_PAD_CONTROL_NOT_AVAILABLE != config->analogPadControl)
    {
#ifdef SIUL2_AE_MSCR_APC_MASK
        if (config->baseAE == IP_SIUL2_AE)
        {
            pinsValues |= SIUL2_AE_MSCR_APC(config->analogPadControl);
        }
#endif
    }
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_ANALOG_PAD_CONTROL */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_ANALOG_PAD_CONTROL */

#ifdef FEATURE_SIUL2_PORT_IP_HAS_CURRENT_REFERENCE_CONTROL
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_CURRENT_REFERENCE_CONTROL)
    if (PORT_CURRENT_REFERENCE_CONTROL_NOT_AVAILABLE != config->currentReferenceControl)
    {
        pinsValues |= SIUL2_MSCR_CREF(config->currentReferenceControl);
    }
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_CURRENT_REFERENCE_CONTROL */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_CURRENT_REFERENCE_CONTROL */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_RX_CURRENT_BOOST
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_RX_CURRENT_BOOST)
    if (PORT_RX_CURRENT_BOOST_NOT_AVAILABLE != config->rxCurrentBoost)
    {
        pinsValues |= SIUL2_MSCR_RXCB(config->rxCurrentBoost);
    }
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_RX_CURRENT_BOOST */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_RX_CURRENT_BOOST */

#ifdef IP_SIUL2_AE
    if (config->baseAE == IP_SIUL2_AE)
    {
        pinsValues |= SIUL2_AE_MSCR_SSS(config->mux);
    }
    else
#endif /* IP_SIUL2_AE */
    {
        pinsValues |= SIUL2_MSCR_SSS(config->mux);
    }
    /* Configure initial value for GPIO pin in GPIO mux */
    if ((PORT_MUX_AS_GPIO == config->mux) && (PORT_OUTPUT_BUFFER_ENABLED == config->outputBuffer))
    {
#if (STD_ON == PORT_VIRTWRAPPER_SUPPORT)
        /* If the value is low or high */
        if (config->initValue != PORT_PIN_LEVEL_NOTCHANGED_U8)
        {
            /* Write the value into GPDO register */
            PORT_WRITE8(SIUL2_GPDO_ADDR8(siulInstance, config->mscrPdacSlot, (uint16)config->pinPortIdx), config->initValue);
        }
#else
        if (config->initValue != PORT_PIN_LEVEL_NOTCHANGED_U8)
        {
            /* Write the value into GPDO register */
            PORT_WRITE8(SIUL2_GPDO_ADDR8(siulInstance, (uint16)config->pinPortIdx), config->initValue);
        }
#endif /* STD_ON == PORT_VIRTWRAPPER_SUPPORT */
    }

    /* Write to Multiplexed Signal Configuration Register */
#ifdef IP_SIUL2_AE
    if (config->baseAE == IP_SIUL2_AE)
    {
        config->baseAE->MSCR[config->pinPortIdx] = pinsValues;
    }
    else
#endif /* IP_SIUL2_AE */
    {
        config->base->MSCR[config->pinPortIdx] = pinsValues;
    }

    /* Write to Input Multiplexed Signal Configuration Register */
    Siul2_Port_Ip_WriteIMCRConfiguration(config);
}

/*!
 * @brief Get the instance of Input Multiplexed Signal Configuration Register
 *
 */
static inline void Siul2_Port_Ip_GetIMCRInstance(const Siul2_Port_Ip_PinSettingsConfig * config,
                                                 uint32 * imcrRegIdx,
                                                 SIUL2_Type ** imcrBase,
                                                 uint8 inputMuxIterator
                                                )
{
#if (STD_ON == PORT_VIRTWRAPPER_SUPPORT)
    uint8 imcrPdacSlot;
#endif /* PORT_VIRTWRAPPER_SUPPORT*/

    /* Write to Input Mux register */
    *imcrRegIdx = config->inputMuxReg[inputMuxIterator];
    /* If the IMCR number is higher than 512 then the IMCR register is on SIUL2_3 */
    if (*imcrRegIdx < SIUL2_MAX_NUM_OF_IMCR_REG)
    {
        if (*imcrRegIdx <= PORT_SIUL2_0_IMCRS_IDX_END_U16)
        {
            /* Use the base address of SIUL2_0 */
#ifdef IP_SIUL2_0_BASE
            *imcrBase = (SIUL2_Type *)IP_SIUL2_0_BASE;
#endif /* IP_SIUL2_0_BASE */
#ifdef IP_SIUL2_BASE
            *imcrBase = (SIUL2_Type *)IP_SIUL2_BASE;
#endif /* IP_SIUL2_BASE */
#if (STD_ON == PORT_VIRTWRAPPER_SUPPORT)
            imcrPdacSlot = config->imcrPdacSlot;
            *imcrBase = (SIUL2_Type *)Port_au32Siul2BaseAddr[0][imcrPdacSlot];
#endif /* PORT_VIRTWRAPPER_SUPPORT*/
        }
#ifdef IP_SIUL2_1_BASE
        else if (*imcrRegIdx <= PORT_SIUL2_1_IMCRS_IDX_END_U16)
        {
            *imcrBase = (SIUL2_Type *)IP_SIUL2_1_BASE;
#if (STD_ON == PORT_VIRTWRAPPER_SUPPORT)
            imcrPdacSlot = config->imcrPdacSlot;
            *imcrBase = (SIUL2_Type *)Port_au32Siul2BaseAddr[1][imcrPdacSlot];
#endif /* PORT_VIRTWRAPPER_SUPPORT*/
        }
#endif /* IP_SIUL2_1_BASE */
#ifdef IP_SIUL2_4_BASE
        else if (*imcrRegIdx <= PORT_SIUL2_4_IMCRS_IDX_END_U16)
        {
            *imcrBase = (SIUL2_Type *)IP_SIUL2_4_BASE;
#if (STD_ON == PORT_VIRTWRAPPER_SUPPORT)
            imcrPdacSlot = config->imcrPdacSlot;
            *imcrBase = (SIUL2_Type *)Port_au32Siul2BaseAddr[3][imcrPdacSlot];
#endif /* PORT_VIRTWRAPPER_SUPPORT*/
        }
#endif /* IP_SIUL2_4_BASE */
#ifdef IP_SIUL2_5_BASE
        else if (*imcrRegIdx <= PORT_SIUL2_5_IMCRS_IDX_END_U16)
        {
            *imcrBase = (SIUL2_Type *)IP_SIUL2_5_BASE;
#if (STD_ON == PORT_VIRTWRAPPER_SUPPORT)
            imcrPdacSlot = config->imcrPdacSlot;
            *imcrBase = (SIUL2_Type *)Port_au32Siul2BaseAddr[4][imcrPdacSlot];
#endif /* PORT_VIRTWRAPPER_SUPPORT*/
        }
#endif /* IP_SIUL2_5_BASE */
        else
        {
            /* Do nothing */
        }
    }
#ifdef IP_SIUL2_3_BASE
    else if (SIUL2_AE_IMCR_IDX_OFFSET_U32 > *imcrRegIdx)
    {
        /* Use the base address of SIUL2_3 */
        *imcrBase = (SIUL2_Type *)IP_SIUL2_3_BASE;
        *imcrRegIdx = *imcrRegIdx - SIUL2_MAX_NUM_OF_IMCR_REG;
#if (STD_ON == PORT_VIRTWRAPPER_SUPPORT)
        imcrPdacSlot = config->imcrPdacSlot;
        *imcrBase = (SIUL2_Type *)Port_au32Siul2BaseAddr[2][imcrPdacSlot];
#endif /* PORT_VIRTWRAPPER_SUPPORT*/
    }
#endif /* IP_SIUL2_3_BASE */
    else
    {
        /* Do nothing */
    }
}

#ifdef IP_SIUL2_AE_BASE
/*!
 * @brief Get the instance of Input Multiplexed Signal Configuration Register of SIUL2_AE
 *
 */
static inline void Siul2_Port_Ip_Siul2AE_GetIMCRInstance(const Siul2_Port_Ip_PinSettingsConfig * config,
                                                         uint32 * imcrRegIdx,
                                                         SIUL2_AE_Type ** imcrBaseAE,
                                                         uint8 inputMuxIterator
                                                        )
{
    /* Write to Input Mux register */
    *imcrRegIdx = config->inputMuxReg[inputMuxIterator];

    if (SIUL2_AE_IMCR_IDX_OFFSET_U32 <= *imcrRegIdx)
    {
        *imcrBaseAE = (SIUL2_AE_Type *)IP_SIUL2_AE_BASE;
        *imcrRegIdx = *imcrRegIdx - SIUL2_AE_IMCR_IDX_OFFSET_U32;
    }
}
#endif /* IP_SIUL2_AE_BASE */

/*!
 * @brief Write to Input Multiplexed Signal Configuration Register (IMCR)
 *
 * This function configures the register with the provided in the
 * given structure.
 *
 * @param[in] config the configuration structure
  */
static inline void Siul2_Port_Ip_WriteIMCRConfiguration(const Siul2_Port_Ip_PinSettingsConfig * config)
{
    uint8 inputMuxIterator;
    uint32 imcrRegIdx = 0UL;
#ifdef IP_SIUL2_0_BASE
    SIUL2_Type * imcrBase = (SIUL2_Type *)IP_SIUL2_0_BASE;
#endif /* IP_SIUL2_0_BASE */
#ifdef IP_SIUL2_BASE
    SIUL2_Type * imcrBase = (SIUL2_Type *)IP_SIUL2_BASE;
#endif /* IP_SIUL2_BASE */
#ifdef IP_SIUL2_AE_BASE
    SIUL2_AE_Type * imcrBaseAE = (SIUL2_AE_Type *)IP_SIUL2_AE_BASE;
#endif /* IP_SIUL2_AE_BASE */

    /* Write to Input Multiplexed Signal Configuration Register (IMCR) */
    if (PORT_INPUT_BUFFER_ENABLED == config->inputBuffer)
    {
        for (inputMuxIterator = 0U; inputMuxIterator < FEATURE_SIUL2_MAX_NUMBER_OF_INPUT_U8; inputMuxIterator++)
        {
            /* Check if input mux information needs to be configured */
            if (PORT_INPUT_MUX_NO_INIT != config->inputMux[inputMuxIterator])
            {
                /* Get the instance of Input Multiplexed Signal Configuration Register (IMCR) */
#ifdef IP_SIUL2_AE_BASE
                if ((config->baseAE) != NULL_PTR)
                {
                    Siul2_Port_Ip_Siul2AE_GetIMCRInstance(config, &imcrRegIdx, &imcrBaseAE, inputMuxIterator);
                }
                else
#endif /* IP_SIUL2_AE_BASE */
                {
                    Siul2_Port_Ip_GetIMCRInstance(config, &imcrRegIdx, &imcrBase, inputMuxIterator);
                }
                if (imcrRegIdx < SIUL2_IMCR_COUNT)
                {
                    /* Config input signal */
#ifdef IP_SIUL2_AE
                    if ((config->baseAE) != NULL_PTR)
                    {
                        imcrBaseAE->IMCR[imcrRegIdx % SIUL2_MAX_NUM_OF_IMCR_REG] = SIUL2_AE_IMCR_SSS(config->inputMux[inputMuxIterator]);
                    }
                    else
#endif /* IP_SIUL2_AE */
                    {
                        imcrBase->IMCR[imcrRegIdx % SIUL2_MAX_NUM_OF_IMCR_REG] = SIUL2_IMCR_SSS(config->inputMux[inputMuxIterator]);
                    }
                }
            }
        }
    }
}

/*!
 * @brief Initializes the pins with the given configuration structure
 *
 * This function configures the pins with the options provided in the
 * given structure.
 *
 * @param[in] pinNumber the number of configured pins in structure
 * @param[in] config the configuration structure
  */
static inline void Siul2_Port_Ip_GetMSCRConfiguration(Siul2_Port_Ip_PinSettingsConfig * config,
                                                      const Siul2_Port_Ip_PortType * const base,
                                                      uint16 pin
                                                     )
{
    uint32 u32RegVal = 0UL;
    /* This var used to fix misra rule 10.8 to 10.5*/
    uint32 u32TempVal = 0UL;
    Siul2_Port_Ip_PortPullConfig pullValue;

    u32RegVal = base->MSCR[pin];
#ifdef IP_SIUL2_AE
    if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
    {
        u32TempVal = (u32RegVal & SIUL2_AE_MSCR_SSS_MASK) >> SIUL2_AE_MSCR_SSS_SHIFT;
    }
    else
#endif /* IP_SIUL2_AE */
    {
        u32TempVal = (u32RegVal & SIUL2_MSCR_SSS_MASK) >> SIUL2_MSCR_SSS_SHIFT;
    }
    config->mux = (Siul2_Port_Ip_PortMux)(u32TempVal);
    u32TempVal = (u32RegVal & SIUL2_MSCR_SMC_MASK) >> SIUL2_MSCR_SMC_SHIFT;
    config->safeMode = (Siul2_Port_Ip_PortSafeMode)(u32TempVal);

#ifdef IP_SIUL2_AE
    if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
    {
        if (0U == ((u32RegVal & SIUL2_AE_MSCR_PUE_MASK) >> SIUL2_AE_MSCR_PUE_SHIFT))
        {
            pullValue = PORT_INTERNAL_PULL_NOT_ENABLED;
        }
        else
        {
            u32TempVal = (u32RegVal & SIUL2_AE_MSCR_PUS_MASK) >> SIUL2_AE_MSCR_PUS_SHIFT;
            pullValue = (Siul2_Port_Ip_PortPullConfig)(u32TempVal);
        }

        config->pullConfig = pullValue;
        u32TempVal = (u32RegVal & SIUL2_AE_MSCR_SRE_MASK) >> SIUL2_AE_MSCR_SRE_SHIFT;
        config->slewRateCtrlSel = (Siul2_Port_Ip_PortSlewRateControl)(u32TempVal);
    }
    else
#endif /* IP_SIUL2_AE */
    {
        if (0U == ((u32RegVal & SIUL2_MSCR_PUE_MASK) >> SIUL2_MSCR_PUE_SHIFT))
        {
            pullValue = PORT_INTERNAL_PULL_NOT_ENABLED;
        }
        else
        {
            u32TempVal = (u32RegVal & SIUL2_MSCR_PUS_MASK) >> SIUL2_MSCR_PUS_SHIFT;
            pullValue = (Siul2_Port_Ip_PortPullConfig)(u32TempVal);
        }

        config->pullConfig = pullValue;
        u32TempVal = (u32RegVal & SIUL2_MSCR_SRE_MASK) >> SIUL2_MSCR_SRE_SHIFT;
        config->slewRateCtrlSel = (Siul2_Port_Ip_PortSlewRateControl)(u32TempVal);
    }
#ifdef FEATURE_SIUL2_PORT_IP_HAS_RECEIVER_SELECT
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_RECEIVER_SELECT)
    u32TempVal = (u32RegVal & SIUL2_MSCR_RCVR_MASK) >> SIUL2_MSCR_RCVR_SHIFT;
    config->receiverSel = (Siul2_Port_Ip_PortReceiverSelect)(u32TempVal);
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_RECEIVER_SELECT */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_RECEIVER_SELECT */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_OPEN_DRAIN
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_OPEN_DRAIN)
    u32TempVal = (u32RegVal & SIUL2_MSCR_ODE_MASK) >> SIUL2_MSCR_ODE_SHIFT;
    config->openDrain = (Siul2_Port_Ip_PortOpenDrain)(u32TempVal);
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_OPEN_DRAIN */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_OPEN_DRAIN */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_DRIVE_STRENGTH
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_DRIVE_STRENGTH)
    u32TempVal = (u32RegVal & SIUL2_MSCR_DSE_MASK) >> SIUL2_MSCR_DSE_SHIFT;
    config->driveStrength = (Siul2_Port_Ip_PortDriveStrength)(u32TempVal);
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_DRIVE_STRENGTH */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_DRIVE_STRENGTH */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_INPUT_FILTER
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_INPUT_FILTER)
    u32TempVal = (u32RegVal & SIUL2_MSCR_IFE_MASK) >> SIUL2_MSCR_IFE_SHIFT;
    config->inputFilter = (Siul2_Port_Ip_PortInputFilter)(u32TempVal);
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_INPUT_FILTER */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_INPUT_FILTER */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_INVERT_DATA
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_INVERT_DATA)
    u32TempVal = (u32RegVal & SIUL2_MSCR_INV_MASK) >> SIUL2_MSCR_INV_SHIFT;
    config->invert = (Siul2_Port_Ip_PortInvert)(u32TempVal);
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_INVERT_DATA */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_INVERT_DATA */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_PULL_KEEPER
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_PULL_KEEPER)
    u32TempVal = (u32RegVal & SIUL2_MSCR_PKE_MASK) >> SIUL2_MSCR_PKE_SHIFT;
    config->pullKeep = (Siul2_Port_Ip_PortPullKeep)(u32TempVal);
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_PULL_KEEPER */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_PULL_KEEPER */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_TERMINATION_RESISTOR
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_TERMINATION_RESISTOR)
    u32TempVal = (u32RegVal & SIUL2_MSCR_TRC_MASK) >> SIUL2_MSCR_TRC_SHIFT;
    config->terminationResistor = (Siul2_Port_Ip_PortTerminationResistor)(u32TempVal);
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_TERMINATION_RESISTOR */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_TERMINATION_RESISTOR */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_HYSTERESIS
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_HYSTERESIS)
    u32TempVal = (u32RegVal & SIUL2_AE_MSCR_HYS_MASK) >> SIUL2_AE_MSCR_HYS_SHIFT;
    config->hysteresis = (Siul2_Port_Ip_PortInputHysteresis)(u32TempVal);
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_HYSTERESIS */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_HYSTERESIS */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_CURRENT_REFERENCE_CONTROL
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_CURRENT_REFERENCE_CONTROL)
    u32TempVal = (u32RegVal & SIUL2_MSCR_CREF_MASK) >> SIUL2_MSCR_CREF_SHIFT;
    config->currentReferenceControl = (Siul2_Port_Ip_PortCurrentReferenceControl)(u32TempVal);
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_CURRENT_REFERENCE_CONTROL */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_CURRENT_REFERENCE_CONTROL */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_RX_CURRENT_BOOST
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_RX_CURRENT_BOOST)
    u32TempVal = (u32RegVal & SIUL2_MSCR_RXCB_MASK) >> SIUL2_MSCR_RXCB_SHIFT;
    config->rxCurrentBoost = (Siul2_Port_Ip_PortRxCurrentBoost)(u32TempVal);
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_RX_CURRENT_BOOST */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_RX_CURRENT_BOOST */
#ifdef IP_SIUL2_AE
    if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
    {
        u32TempVal = (u32RegVal & SIUL2_AE_MSCR_IBE_MASK) >> SIUL2_AE_MSCR_IBE_SHIFT;
    }
    else
#endif /* IP_SIUL2_AE */
    {
        u32TempVal = (u32RegVal & SIUL2_MSCR_IBE_MASK) >> SIUL2_MSCR_IBE_SHIFT;
    }
    config->inputBuffer = (Siul2_Port_Ip_PortInputBuffer)(u32TempVal);
#ifdef IP_SIUL2_AE
    if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
    {
        u32TempVal = (u32RegVal & SIUL2_AE_MSCR_OBE_MASK) >> SIUL2_AE_MSCR_OBE_SHIFT;
    }
    else
#endif /* IP_SIUL2_AE */
    {
        u32TempVal = (u32RegVal & SIUL2_MSCR_OBE_MASK) >> SIUL2_MSCR_OBE_SHIFT;
    }
    config->outputBuffer = (Siul2_Port_Ip_PortOutputBuffer)(u32TempVal);
#ifdef FEATURE_SIUL2_PORT_IP_HAS_ANALOG_PAD_CONTROL
#if (STD_ON == FEATURE_SIUL2_PORT_IP_HAS_ANALOG_PAD_CONTROL)
#ifdef IP_SIUL2_AE
    if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
    {
        u32TempVal = (u32RegVal & SIUL2_AE_MSCR_APC_MASK) >> SIUL2_AE_MSCR_APC_SHIFT;
        config->analogPadControl = (Siul2_Port_Ip_PortAnalogPadControl)(u32TempVal);
    }
#endif /* IP_SIUL2_AE */
#endif /* STD_ON == FEATURE_SIUL2_PORT_IP_HAS_ANALOG_PAD_CONTROL */
#endif/* FEATURE_SIUL2_PORT_IP_HAS_ANALOG_PAD_CONTROL */
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Siul2_Port_Ip_Init
 * Description   : This function configures the pins with the options provided
 * in the given structure.
 *
 * @implements Siul2_Port_Ip_Init_Activity
 *END**************************************************************************/
Siul2_Port_Ip_PortStatusType Siul2_Port_Ip_Init(uint32 pinCount,
                                                const Siul2_Port_Ip_PinSettingsConfig config[]
                                               )
{
    uint32 i;

    /* Store the configuration pointer */
    pPort_Setting = config;

    /* Store the number of configured pins */
    u32MaxPinConfigured = pinCount;
    for (i = 0U; i < pinCount; i++)
    {
        Call_Siul2_Port_Ip_PinInit(&config[i]);
    }

    return SIUL2_PORT_SUCCESS;
}


void Siul2_Port_Ip_ConfigInternalResistor(Siul2_Port_Ip_PortType * const base,
                                          uint16 pin,
                                          Siul2_Port_Ip_PortPullConfig pullConfig
                                         )
{
    uint32 regVal;
    uint32 pueVal;
    uint32 pusVal;

    /* If that pin belongs to SIUL2_AE*/
#ifdef IP_SIUL2_AE
    if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
    {
        pueVal = SIUL2_AE_MSCR_PUE_MASK;
        pusVal = SIUL2_AE_MSCR_PUS_MASK;
    }
    else
#endif /* IP_SIUL2_AE */
    {
        pueVal = SIUL2_MSCR_PUE_MASK;
        pusVal = SIUL2_MSCR_PUS_MASK;
    }

    /* Enter critical region */
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01();

    switch (pullConfig)
    {
        case PORT_INTERNAL_PULL_NOT_ENABLED:
        {
            /* Clear the Pull Enable bit field */
            base->MSCR[pin] &= ~pueVal;
            break;
        }
        case PORT_INTERNAL_PULL_DOWN_ENABLED:
        {
            regVal = base->MSCR[pin];
            /* Set the Pull Enable bit field */
            regVal |= pueVal;
            /* Clear the Pull Select bit field */
            regVal &= ~pusVal;
            base->MSCR[pin] = regVal;
            break;
        }
        case PORT_INTERNAL_PULL_UP_ENABLED:
        {
            regVal = base->MSCR[pin];
            /* Set the Pull Enable bit field */
            regVal |= pueVal;
            /* Set the Pull Select bit field */
            regVal |= pusVal;
            base->MSCR[pin] = regVal;
            break;
        }

        default:
            /* Invalid command */
            SIUL2_PORT_IP_DEV_ASSERT(FALSE);
            break;
    }

    /* Exit critical region */
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Siul2_Port_Ip_SetPullSel
 * Description   : This function configures the internal resistor.
 *
 * @implements Siul2_Port_Ip_SetPullSel_Activity
 *END**************************************************************************/
void Siul2_Port_Ip_SetPullSel(Siul2_Port_Ip_PortType * const base,
                              uint16 pin,
                              Siul2_Port_Ip_PortPullConfig pullConfig
                             )
{

    SIUL2_PORT_IP_DEV_ASSERT((boolean)(base != NULL_PTR));
    SIUL2_PORT_IP_DEV_ASSERT((boolean)(pin < SIUL2_NUM_OF_PIN_PORT_U16));

    Call_Siul2_Port_Ip_ConfigInternalResistor(base, pin, pullConfig);
}

void Siul2_Port_Ip_ConfigOutputBuffer(Siul2_Port_Ip_PortType * const base,
                                      uint16 pin,
                                      boolean enable,
                                      Siul2_Port_Ip_PortMux mux
                                     )
{
    /* Enter critical region */
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_02();

#ifdef IP_SIUL2_AE
    if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
    {
        /* Clear the OBE bit field */
        base->MSCR[pin] &= ~SIUL2_AE_MSCR_OBE_MASK;
        /* Write the OBE bit field with enable */
        base->MSCR[pin] |= SIUL2_AE_MSCR_OBE(enable ? 1UL : 0UL);
        /* Clear the SSS bit field */
        base->MSCR[pin] &= ~SIUL2_AE_MSCR_SSS_MASK;
        /* Write the SSS bit field with mux */
        base->MSCR[pin] |= SIUL2_AE_MSCR_SSS(mux);
    }
    else
#endif /* IP_SIUL2_AE */
    {
        /* Clear the OBE bit field */
        base->MSCR[pin] &= ~SIUL2_MSCR_OBE_MASK;
        /* Write the OBE bit field with enable */
        base->MSCR[pin] |= SIUL2_MSCR_OBE(enable ? 1UL : 0UL);
        /* Clear the SSS bit field */
        base->MSCR[pin] &= ~SIUL2_MSCR_SSS_MASK;
        /* Write the SSS bit field with mux */
        base->MSCR[pin] |= SIUL2_MSCR_SSS(mux);
    }
    /* Exit critical region */
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_02();
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Siul2_Port_Ip_SetOutputBuffer
 * Description   : This function configures the output buffer.
 *
 * @implements Siul2_Port_Ip_SetOutputBuffer_Activity
 *END**************************************************************************/
void Siul2_Port_Ip_SetOutputBuffer(Siul2_Port_Ip_PortType * const base,
                                   uint16 pin,
                                   boolean enable,
                                   Siul2_Port_Ip_PortMux mux
                                  )
{
    SIUL2_PORT_IP_DEV_ASSERT((boolean)(base != NULL_PTR));
    SIUL2_PORT_IP_DEV_ASSERT((boolean)(pin < SIUL2_NUM_OF_PIN_PORT_U16));

    Call_Siul2_Port_Ip_ConfigOutputBuffer(base, pin, enable, mux);
}

void Siul2_Port_Ip_ConfigInputBuffer(Siul2_Port_Ip_PortType * const base,
                                     uint16 pin,
                                     boolean enable,
                                     uint32 inputMuxReg,
                                     Siul2_Port_Ip_PortInputMux inputMux)
{
    /* Dummy address */
    SIUL2_Type * siul2Base = (SIUL2_Type *)0UL;
#ifdef IP_SIUL2_AE_BASE
    SIUL2_AE_Type * siul2BaseAE = (SIUL2_AE_Type *)0UL;
#endif
    uint32 imcrRegIdx = inputMuxReg;
    uint32 imcrVal;

#ifdef IP_SIUL2_AE_BASE
    if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
    {
        SIUL2_PORT_IP_DEV_ASSERT((boolean)(!((SIUL2_DIPORT_IMCR_AE_IDX_START_U32 <= inputMuxReg) && (SIUL2_DIPORT_IMCR_AE_IDX_END_U32 >= inputMuxReg))));
    }
#endif

    /* Enter critical region */
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_03();

    if (base != NULL_PTR)
    {
        /* Enable/disable input buffer for input signal */
#ifdef IP_SIUL2_AE
        if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
        {
            base->MSCR[pin] &= ~SIUL2_AE_MSCR_IBE_MASK;
            base->MSCR[pin] |= SIUL2_AE_MSCR_IBE(enable ? 1UL : 0UL);
        }
        else
#endif /* IP_SIUL2_AE */
        {
            base->MSCR[pin] &= ~SIUL2_MSCR_IBE_MASK;
            base->MSCR[pin] |= SIUL2_MSCR_IBE(enable ? 1UL : 0UL);
        }
    }
    /* Check input mux to configure input signal */
    if (inputMux != PORT_INPUT_MUX_NO_INIT)
    {
#ifdef IP_SIUL2_AE_BASE
        if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
        {
            siul2BaseAE = (SIUL2_AE_Type *)IP_SIUL2_AE_BASE;
        }
        else
        {
#endif /* IP_SIUL2_AE_BASE */
            if (imcrRegIdx < SIUL2_MAX_NUM_OF_IMCR_REG)
            {
                if (imcrRegIdx <= PORT_SIUL2_0_IMCRS_IDX_END_U16)
                {
#ifdef IP_SIUL2_0_BASE
                siul2Base = (SIUL2_Type *)IP_SIUL2_0_BASE;
#endif /* IP_SIUL2_0_BASE */
#ifdef IP_SIUL2_BASE
                    siul2Base = (SIUL2_Type *)IP_SIUL2_BASE;
#endif /* IP_SIUL2_BASE */
                }
#ifdef IP_SIUL2_1_BASE
                else if (imcrRegIdx <= PORT_SIUL2_1_IMCRS_IDX_END_U16)
                {
                    siul2Base = (SIUL2_Type *)IP_SIUL2_1_BASE;
                }
#endif /* IP_SIUL2_1_BASE */
#ifdef IP_SIUL2_4_BASE
                else if (imcrRegIdx <= PORT_SIUL2_4_IMCRS_IDX_END_U16)
                {
                    siul2Base = (SIUL2_Type *)IP_SIUL2_4_BASE;
                }
#endif /* IP_SIUL2_4_BASE */
#ifdef IP_SIUL2_5_BASE
                else
                {
                    siul2Base = (SIUL2_Type *)IP_SIUL2_5_BASE;
                }
#endif /* IP_SIUL2_5_BASE */
            }
#ifdef IP_SIUL2_3_BASE
            else
            {
                imcrRegIdx = imcrRegIdx - SIUL2_MAX_NUM_OF_IMCR_REG;
                siul2Base = (SIUL2_Type *)IP_SIUL2_3_BASE;
            }
#endif /* IP_SIUL2_3_BASE */
#ifdef IP_SIUL2_AE_BASE
        }
#endif /* IP_SIUL2_AE_BASE */
#ifdef IP_SIUL2_AE
        if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
        {
            if (imcrRegIdx < SIUL2_IMCR_COUNT)
            {
                /* Configure input mux */
                imcrVal  = siul2BaseAE->IMCR[imcrRegIdx % SIUL2_MAX_NUM_OF_IMCR_REG];
                imcrVal &= ~SIUL2_AE_IMCR_SSS_MASK;
                imcrVal |= SIUL2_AE_IMCR_SSS(inputMux);
                siul2BaseAE->IMCR[imcrRegIdx % SIUL2_MAX_NUM_OF_IMCR_REG] = imcrVal;
            }
        }
        else
#endif /* IP_SIUL2_AE */
        {
            if (imcrRegIdx < SIUL2_IMCR_COUNT)
            {
                /* Configure input mux */
                imcrVal  = siul2Base->IMCR[imcrRegIdx % SIUL2_MAX_NUM_OF_IMCR_REG];
                imcrVal &= ~SIUL2_IMCR_SSS_MASK;
                imcrVal |= SIUL2_IMCR_SSS(inputMux);
                siul2Base->IMCR[imcrRegIdx % SIUL2_MAX_NUM_OF_IMCR_REG] = imcrVal;
            }
        }
    }
    /* Exit critical region */
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_03();
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Siul2_Port_Ip_SetInputBuffer
 * Description   : This function configures the input buffer.
 *
 * @implements Siul2_Port_Ip_SetInputBuffer_Activity
 *END**************************************************************************/
void Siul2_Port_Ip_SetInputBuffer(Siul2_Port_Ip_PortType * const base,
                                  uint16 pin,
                                  boolean enable,
                                  uint32 inputMuxReg,
                                  Siul2_Port_Ip_PortInputMux inputMux
                                 )
{
    SIUL2_PORT_IP_DEV_ASSERT((boolean)(pin < SIUL2_NUM_OF_PIN_PORT_U16));
    Call_Siul2_Port_Ip_ConfigInputBuffer(base, pin, enable, inputMuxReg, inputMux);
}

void Siul2_Port_Ip_ConfigPinDirection(Siul2_Port_Ip_PortType * const base,
                                      uint16 pin,
                                      Siul2_Port_Ip_PortDirectionType direction
                                     )
{
    /* Enter critical region */
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_04();

    switch (direction)
    {
        /* If the pin's direction is input */
        case SIUL2_PORT_IN:
#ifdef IP_SIUL2_AE
            if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
            {
                base->MSCR[pin] &= ~SIUL2_AE_MSCR_OBE_MASK;
                base->MSCR[pin] |= SIUL2_AE_MSCR_IBE(1UL);
            }
            else
#endif /* IP_SIUL2_AE */
            {
                base->MSCR[pin] &= ~SIUL2_MSCR_OBE_MASK;
                base->MSCR[pin] |= SIUL2_MSCR_IBE(1UL);
            }
            break;
        /* If the pin's direction is output */
        case SIUL2_PORT_OUT:
#ifdef IP_SIUL2_AE
            if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
            {
                base->MSCR[pin] &= ~SIUL2_AE_MSCR_IBE_MASK;
                base->MSCR[pin] |= SIUL2_AE_MSCR_OBE(1UL);
            }
            else
#endif /* IP_SIUL2_AE */
            {
                base->MSCR[pin] &= ~SIUL2_MSCR_IBE_MASK;
                base->MSCR[pin] |= SIUL2_MSCR_OBE(1UL);
            }
            break;
        /* If the pin's direction is inout */
        case SIUL2_PORT_IN_OUT:
#ifdef IP_SIUL2_AE
            if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
            {
                base->MSCR[pin] |= (SIUL2_AE_MSCR_IBE_MASK | SIUL2_AE_MSCR_OBE_MASK);
            }
            else
#endif /* IP_SIUL2_AE */
            {
                base->MSCR[pin] |= (SIUL2_MSCR_IBE_MASK | SIUL2_MSCR_OBE_MASK);
            }
            break;
        /* If the pin's direction is hi_z */
        case SIUL2_PORT_HI_Z:
#ifdef IP_SIUL2_AE
            if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
            {
                base->MSCR[pin] &= ~(SIUL2_AE_MSCR_IBE_MASK | SIUL2_AE_MSCR_OBE_MASK);
            }
            else
#endif /* IP_SIUL2_AE */
            {
                base->MSCR[pin] &= ~(SIUL2_MSCR_IBE_MASK | SIUL2_MSCR_OBE_MASK);
            }
            break;
        default:
            /* Do nothing */
            break;
    }

    /* Exit critical region */
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_04();
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Siul2_Port_Ip_SetPinDirection
 * Description   : This function configures the pin direction
 *
 * @implements Siul2_Port_Ip_SetPinDirection_Activity
 *END**************************************************************************/
void Siul2_Port_Ip_SetPinDirection(Siul2_Port_Ip_PortType * const base,
                                   uint16 pin,
                                   Siul2_Port_Ip_PortDirectionType direction
                                  )
{
    SIUL2_PORT_IP_DEV_ASSERT((boolean)(base != NULL_PTR));
    SIUL2_PORT_IP_DEV_ASSERT((boolean)(pin < SIUL2_NUM_OF_PIN_PORT_U16));

    Call_Siul2_Port_Ip_ConfigPinDirection(base, pin, direction);
}

uint32 Siul2_Port_Ip_GetValueConfigRevertPin(const Siul2_Port_Ip_PortType * const base,
                                             uint16 pin
                                            )
{
    uint32 u32PinIdx;
    uint32 u32RegVal = 0xFFFFFFFFUL;
    const Siul2_Port_Ip_PinSettingsConfig * ConfigPtr = pPort_Setting;
    uint32 MaxPinConfigured = u32MaxPinConfigured;
    uint32 portNumber;
    uint32 u32MscrId;

    /* Get the PortID:  Subtract the address of the first mscr from the base parameter then divide to 4 and 16 because there are 16 ports but each MSCR has 4 bytes */
#if (2 <= SIUL2_NUM_SIUL2_INSTANCES_U8)
#ifdef SIUL2_PORT_IP_MULTIPLE_SIUL2_INSTANCES
    /* Check if that pin belongs to SIUL2_0, SIUL2_1, SIUL2_3, SIUL2_4, SIUL2_5 or SIUL2_AE */
#ifdef IP_SIUL2_AE_BASE
    if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
    {
        portNumber = (Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)base - (Siul2_Port_Ip_CoreType)SIUL2_AE_MSCR_BASE) >> 2U) >> 4U);
    }
    else
    {
#endif /* IP_SIUL2_AE_BASE */
        /* Only S32ZE has SIUL2_5 */
#ifdef IP_SIUL2_5_BASE
        if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_5_BASE)
        {
            portNumber = (Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)base - (Siul2_Port_Ip_CoreType)SIUL2_5_MSCR_BASE) >> 2U) >> 4U);
        }
        else
        {
#endif /* IP_SIUL2_5_BASE */
            if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_4_BASE)
            {
                portNumber = (Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)base - (Siul2_Port_Ip_CoreType)SIUL2_4_MSCR_BASE) >> 2U) >> 4U);
            }
            else if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_3_BASE)
            {
                portNumber = (Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)base - (Siul2_Port_Ip_CoreType)SIUL2_3_MSCR_BASE) >> 2U) >> 4U);
            }
            else
#endif /* SIUL2_PORT_IP_MULTIPLE_SIUL2_INSTANCES */
            {
                if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_1_BASE)
                {
                    portNumber = (Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)base - (Siul2_Port_Ip_CoreType)SIUL2_1_MSCR_BASE) >> 2U) >> 4U);
                }
                else
                {
                    portNumber = (Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)base - (Siul2_Port_Ip_CoreType)SIUL2_0_MSCR_BASE) >> 2U) >> 4U);
                }
            }
#ifdef IP_SIUL2_5_BASE
        }
#endif /* IP_SIUL2_5_BASE */
#ifdef IP_SIUL2_AE_BASE
    }
#endif /* IP_SIUL2_AE_BASE */
#else /* (2 <= SIUL2_NUM_SIUL2_INSTANCES_U8) */
    portNumber = (Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)base - (Siul2_Port_Ip_CoreType)SIUL2_MSCR_BASE) >> 2U) >> 4U);
#endif /* (2 <= SIUL2_NUM_SIUL2_INSTANCES_U8) */

    /* Get the MscrID: 16 is the maximum number of pins per port so the portNumber need to multiply 16 */
    u32MscrId = (portNumber << 4U) + (uint32)pin;

    /* The loop to find the Mscr Id in pin configuration's structure */
    for (u32PinIdx = 0UL; u32PinIdx < MaxPinConfigured; u32PinIdx++)
    {
        /* If we found that pin */
        if (ConfigPtr[u32PinIdx].pinPortIdx == u32MscrId)
        {
            Call_Siul2_Port_Ip_PinInit(&ConfigPtr[u32PinIdx]);
            u32RegVal = base->MSCR[pin];
            /* Break the loop. Do not need to search in all pin configuration's structure */
            break;
        }
    }

    return u32RegVal;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Siul2_Port_Ip_RevertPinConfiguration
 * Description   : This function configures the pin configuration with the values from the configuration structure
 *
 * @implements Siul2_Port_Ip_RevertPinConfiguration_Activity
 *END**************************************************************************/
uint32 Siul2_Port_Ip_RevertPinConfiguration(const Siul2_Port_Ip_PortType * const base,
                                            uint16 pin
                                           )
{
    uint32 u32RegVal = 0xFFFFFFFFUL;

    SIUL2_PORT_IP_DEV_ASSERT((boolean)(base != NULL_PTR));
    SIUL2_PORT_IP_DEV_ASSERT((boolean)(pin < SIUL2_NUM_OF_PIN_PORT_U16));

    u32RegVal = Call_Siul2_Port_Ip_GetValueConfigRevertPin(base, pin);
    /* Return the MSCR value */
    return u32RegVal;
}

void Siul2_Port_Ip_GetValuePinConfiguration(const Siul2_Port_Ip_PortType * const base,
                                            Siul2_Port_Ip_PinSettingsConfig * config,
                                            uint16 pin
                                           )
{
    const Siul2_Port_Ip_PinSettingsConfig * ConfigPtr = pPort_Setting;
    uint32 MaxPinConfigured = u32MaxPinConfigured;
    uint32 portNumber;
    uint32 u32MscrId;
    uint32 u32MscrBase;
    uint32 u32PinIdx;
    uint8 inputMuxIterator;

    /* Choose the MSCR base address for the pin */
#if (2 <= SIUL2_NUM_SIUL2_INSTANCES_U8)
#ifdef SIUL2_PORT_IP_MULTIPLE_SIUL2_INSTANCES
#ifdef IP_SIUL2_AE_BASE
    if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE)
    {
        u32MscrBase = (Siul2_Port_Ip_CoreType)SIUL2_AE_MSCR_BASE;
    }
    else
    {
#endif
        /* Only S32ZE has SIUL2_5 */
#ifdef IP_SIUL2_5_BASE
        if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_5_BASE)
        {
            u32MscrBase = (Siul2_Port_Ip_CoreType)SIUL2_5_MSCR_BASE;
        }
        else
        {
#endif /* IP_SIUL2_5_BASE */
            if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_4_BASE)
            {
                u32MscrBase = (Siul2_Port_Ip_CoreType)SIUL2_4_MSCR_BASE;
            }
            else if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_3_BASE)
            {
                u32MscrBase = (Siul2_Port_Ip_CoreType)SIUL2_3_MSCR_BASE;
            }
            else
#endif /* SIUL2_PORT_IP_MULTIPLE_SIUL2_INSTANCES */
            {
                if (base > (Siul2_Port_Ip_PortType *)IP_SIUL2_1_BASE)
                {
                    u32MscrBase = (Siul2_Port_Ip_CoreType)SIUL2_1_MSCR_BASE;
                }
                else
                {
                    u32MscrBase = (Siul2_Port_Ip_CoreType)SIUL2_0_MSCR_BASE;
                }
            }
#ifdef IP_SIUL2_5_BASE
        }
#endif /* IP_SIUL2_5_BASE */
#ifdef IP_SIUL2_AE_BASE
    }
#endif /* IP_SIUL2_AE_BASE */
#else /* (2 <= SIUL2_NUM_SIUL2_INSTANCES_U8) */
    u32MscrBase = (Siul2_Port_Ip_CoreType)SIUL2_MSCR_BASE;
#endif /* (2 <= SIUL2_NUM_SIUL2_INSTANCES_U8) */

    /* Get the PortID:  Subtract the address of the first mscr from the base parameter then divide to 4 and 16 because there are 16 ports and each MSCR has 4 bytes */
    portNumber = (Siul2_Port_Ip_CoreType)((Siul2_Port_Ip_CoreType)base - u32MscrBase) / 64UL;
    /* Get the MscrID: 16 is the maximum number of pins per port so the portNumber need to multiply 16 */
    u32MscrId = (portNumber << 4U) + (uint32)pin;

    for (u32PinIdx = 0UL; u32PinIdx < MaxPinConfigured; u32PinIdx++)
    {
        /* If that pin was found */
        if (ConfigPtr[u32PinIdx].pinPortIdx == u32MscrId)
        {
#ifdef IP_SIUL2_AE_BASE
            if ((Siul2_Port_Ip_PortType *)IP_SIUL2_AE_BASE < base)
            {
                config->baseAE = ConfigPtr[u32PinIdx].baseAE;
            }
            else
#endif /* IP_SIUL2_AE_BASE */
            {
                config->base = ConfigPtr[u32PinIdx].base;
            }
            config->pinPortIdx = ConfigPtr[u32PinIdx].pinPortIdx;
            config->initValue = ConfigPtr[u32PinIdx].initValue;

            for (inputMuxIterator = 0U; inputMuxIterator < FEATURE_SIUL2_MAX_NUMBER_OF_INPUT_U8; inputMuxIterator++)
            {
                config->inputMuxReg[inputMuxIterator] = ConfigPtr[u32PinIdx].inputMuxReg[inputMuxIterator];
                config->inputMux[inputMuxIterator] = ConfigPtr[u32PinIdx].inputMux[inputMuxIterator];
            }

            /* Get the MSCR configuration from register */
            Siul2_Port_Ip_GetMSCRConfiguration(config, base, pin);
            break;
        }
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Siul2_Port_Ip_GetPinConfiguration
 * Description   : This function returns the value of the pin configuration register.
 *
 * @implements Siul2_Port_Ip_GetPinConfiguration_Activity
 *END**************************************************************************/
void Siul2_Port_Ip_GetPinConfiguration(const Siul2_Port_Ip_PortType * const base,
                                       Siul2_Port_Ip_PinSettingsConfig * config,
                                       uint16 pin
                                      )
{

    SIUL2_PORT_IP_DEV_ASSERT((boolean)(base != NULL_PTR));
    SIUL2_PORT_IP_DEV_ASSERT((boolean)(pin < SIUL2_NUM_OF_PIN_PORT_U16));

    Call_Siul2_Port_Ip_GetValuePinConfiguration(base, config, pin);
}

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
