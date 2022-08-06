/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


/**
*   @file Siul2_Dio_Ip.c
*
*   @addtogroup DIO_IPL
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
#include "Siul2_Dio_Ip.h"
#include "SchM_Dio.h"
#if (STD_ON == SIUL2_DIO_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif /* (STD_ON == SIUL2_DIO_IP_DEV_ERROR_DETECT) */

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define SIUL2_DIO_IP_VENDOR_ID_C                     43
#define SIUL2_DIO_IP_AR_RELEASE_MAJOR_VERSION_C      4
#define SIUL2_DIO_IP_AR_RELEASE_MINOR_VERSION_C      4
#define SIUL2_DIO_IP_AR_RELEASE_REVISION_VERSION_C   0
#define SIUL2_DIO_IP_SW_MAJOR_VERSION_C              0
#define SIUL2_DIO_IP_SW_MINOR_VERSION_C              8
#define SIUL2_DIO_IP_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Siul2_Dio_Ip source file and Siul2_Dio_Ip header file are of the same vendor */
#if (SIUL2_DIO_IP_VENDOR_ID_C != SIUL2_DIO_IP_VENDOR_ID_H)
    #error "Siul2_Dio_Ip.c and Siul2_Dio_Ip.h have different vendor ids"
#endif

/* Check if  Siul2_Dio_Ip source file and Siul2_Dio_Ip header file are of the same Autosar version */
#if ((SIUL2_DIO_IP_AR_RELEASE_MAJOR_VERSION_C    != SIUL2_DIO_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (SIUL2_DIO_IP_AR_RELEASE_MINOR_VERSION_C    != SIUL2_DIO_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (SIUL2_DIO_IP_AR_RELEASE_REVISION_VERSION_C != SIUL2_DIO_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Siul2_Dio_Ip.c and Siul2_Dio_Ip.h are different"
#endif

/* Check if Siul2_Dio_Ip source file and Siul2_Dio_Ip header file are of the same Software version */
#if ((SIUL2_DIO_IP_SW_MAJOR_VERSION_C != SIUL2_DIO_IP_SW_MAJOR_VERSION_H) || \
     (SIUL2_DIO_IP_SW_MINOR_VERSION_C != SIUL2_DIO_IP_SW_MINOR_VERSION_H) || \
     (SIUL2_DIO_IP_SW_PATCH_VERSION_C != SIUL2_DIO_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Siul2_Dio_Ip.c and Siul2_Dio_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Siul2_Dio_Ip source file and Devassert.h header file are of the same release version */
    #if (STD_ON == SIUL2_DIO_IP_DEV_ERROR_DETECT)
        #if ((SIUL2_DIO_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            (SIUL2_DIO_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION)     \
            )
            #error "AutoSar Version Numbers of Siul2_Dio_Ip.c and Devassert.h are different"
        #endif
    #endif /* (STD_ON == SIUL2_DIO_IP_DEV_ERROR_DETECT) */
    /* SchM_Dio.h version check start */
    #if ((SIUL2_DIO_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_DIO_AR_RELEASE_MAJOR_VERSION) ||   \
        (SIUL2_DIO_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_DIO_AR_RELEASE_MINOR_VERSION)       \
        )
        #error "AUTOSAR Version Numbers of Siul2_Dio_Ip.c and SchM_Dio.h are different"
    #endif
    /* SchM_Dio.h version check end */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#define SIUL2_DIO_IP_NUM_OF_PIN_PORT           16u

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
#define DIO_START_SEC_VAR_INIT_32
#include "Dio_MemMap.h"

#if (STD_ON == DIO_VIRTWRAPPER_SUPPORT)
#ifdef SIUL2_VIRTWRAPPER_MULTIINSTANCE
Siul2_Dio_Ip_CoreType Siul2_Dio_Ip_au32BaseAdresses[SIUL2_INSTANCE_COUNT] = IP_SIUL2_BASE_ADDRS;
#else
Siul2_Dio_Ip_CoreType Siul2_Dio_Ip_au32BaseAdresses[3] =
{
    DIO_SIUL2_VIRTWRAPPER_PDAC0,
    DIO_SIUL2_VIRTWRAPPER_PDAC1,
    DIO_SIUL2_VIRTWRAPPER_PDAC2
};
#endif
#else
Siul2_Dio_Ip_CoreType Siul2_Dio_Ip_au32BaseAdresses[SIUL2_INSTANCE_COUNT] = IP_SIUL2_BASE_ADDRS;
#endif
#define DIO_STOP_SEC_VAR_INIT_32
#include "Dio_MemMap.h"
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

static inline uint16 Siul2_Dio_Ip_Rev_Bit_16(uint16 value);

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/* Reverse bit order in each halfword independently */
static inline uint16 Siul2_Dio_Ip_Rev_Bit_16(uint16 value)
{
    uint8 i;
    uint16 ret = 0U;

    for (i = 0U; i < 8U; i++)
    {
        ret |= (uint16)((((value >> i) & 1U) << (15U - i)) | (((value << i) & 0x8000U) >> (15U - i)));
    }

    return ret;
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/**
 *Function Name : Siul2_Dio_Ip_WritePin
 * Description   : This function writes the given pin from a port, with the given value
 * ('0' represents LOW, '1' represents HIGH).
 *
 * @implements    Siul2_Dio_Ip_WritePin_Activity
 */
void Siul2_Dio_Ip_WritePin
(
    Siul2_Dio_Ip_GpioType * const base,
    Siul2_Dio_Ip_PinsChannelType pin,
    Siul2_Dio_Ip_PinsLevelType value
)
{
    SIUL2_DIO_IP_DEV_ASSERT(NULL_PTR != base);
    SIUL2_DIO_IP_DEV_ASSERT((boolean)(pin < SIUL2_DIO_IP_NUM_OF_PIN_PORT));
    SIUL2_DIO_IP_DEV_ASSERT((boolean)(value <= 1U));
    /* Enter critical region */
    SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_01();

    Siul2_Dio_Ip_PinsChannelType pinsValues = (Siul2_Dio_Ip_PinsChannelType)base->PGPDO;
    pinsValues &= (Siul2_Dio_Ip_PinsChannelType)(~((Siul2_Dio_Ip_PinsChannelType)1U << (15U - pin)));
    pinsValues |= (Siul2_Dio_Ip_PinsChannelType)(((Siul2_Dio_Ip_PinsChannelType)value & 1U) << (15U - pin));
    base->PGPDO = pinsValues;

    /* Exit critical region */
    SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_01();
}

/**
 * Function Name : Siul2_Dio_Ip_WritePins
 * Description   : This function writes all pins configured as output with the values given in
 * the parameter pins. '0' represents LOW, '1' represents HIGH.
 *
 * @implements    Siul2_Dio_Ip_WritePins_Activity
 */
void Siul2_Dio_Ip_WritePins
(
    Siul2_Dio_Ip_GpioType * const base,
    Siul2_Dio_Ip_PinsChannelType pins
)
{
    SIUL2_DIO_IP_DEV_ASSERT(NULL_PTR != base);
    base->PGPDO = Siul2_Dio_Ip_Rev_Bit_16(pins);
}

/**
 * Function Name : Siul2_Dio_Ip_GetPinsOutput
 * Description   : This function returns the current output that is written to a port. Only pins
 * that are configured as output will have meaningful values.
 *
 * @implements    Siul2_Dio_Ip_GetPinsOutput_Activity
 */
Siul2_Dio_Ip_PinsChannelType Siul2_Dio_Ip_GetPinsOutput
(
    const Siul2_Dio_Ip_GpioType * const base
)
{
    SIUL2_DIO_IP_DEV_ASSERT(NULL_PTR != base);
    Siul2_Dio_Ip_PinsChannelType returnValue = 0U;
    returnValue = (Siul2_Dio_Ip_PinsChannelType)Siul2_Dio_Ip_Rev_Bit_16(base->PGPDO);
    return returnValue;
}

/**
 * Function Name : Siul2_Dio_Ip_SetPins
 * Description   : This function configures output pins listed in parameter pins (bits that are
 * '1') to have a value of 'set' (HIGH). Pins corresponding to '0' will be
 * unaffected.
 *
 * @implements    Siul2_Dio_Ip_SetPins_Activity
 */
void Siul2_Dio_Ip_SetPins
(
    Siul2_Dio_Ip_GpioType * const base,
    Siul2_Dio_Ip_PinsChannelType pins
)
{
    SIUL2_DIO_IP_DEV_ASSERT(NULL_PTR != base);
    base->PGPDO |= Siul2_Dio_Ip_Rev_Bit_16(pins);
}

/**
 * Function Name : Siul2_Dio_Ip_ClearPins
 * Description   : This function configures output pins listed in parameter pins (bits that are
 * '1') to have a 'cleared' value (LOW). Pins corresponding to '0' will be
 * unaffected.
 *
 * @implements    Siul2_Dio_Ip_ClearPins_Activity
 */
void Siul2_Dio_Ip_ClearPins
(
    Siul2_Dio_Ip_GpioType * const base,
    Siul2_Dio_Ip_PinsChannelType pins
)
{
    SIUL2_DIO_IP_DEV_ASSERT(NULL_PTR != base);
    base->PGPDO &= (Siul2_Dio_Ip_PinsChannelType)(~Siul2_Dio_Ip_Rev_Bit_16(pins));
}

/**
 * Function Name : Siul2_Dio_Ip_TogglePins
 * Description   : This function toggles output pins listed in parameter pins (bits that are
 * '1'). Pins corresponding to '0' will be unaffected.
 *
 * @implements    Siul2_Dio_Ip_TogglePins_Activity
 */
void Siul2_Dio_Ip_TogglePins
(   Siul2_Dio_Ip_GpioType * const base,
    Siul2_Dio_Ip_PinsChannelType pins
)
{
    SIUL2_DIO_IP_DEV_ASSERT(NULL_PTR != base);
    base->PGPDO ^= Siul2_Dio_Ip_Rev_Bit_16(pins);
}

/**
 * Function Name : Siul2_Dio_Ip_ReadPins
 * Description   : This function returns the current input values from a port. Only pins
 * configured as input will have meaningful values.
 *
 * @implements    Siul2_Dio_Ip_ReadPins_Activity
 */
Siul2_Dio_Ip_PinsChannelType Siul2_Dio_Ip_ReadPins
(
    const Siul2_Dio_Ip_GpioType * const base
)
{
    SIUL2_DIO_IP_DEV_ASSERT(NULL_PTR != base);
    Siul2_Dio_Ip_PinsChannelType returnValue = 0U;
    returnValue = (Siul2_Dio_Ip_PinsChannelType)Siul2_Dio_Ip_Rev_Bit_16(base->PGPDI);
    return returnValue;
}

/**
 * Function Name : Siul2_Dio_Ip_ReadPin
 * Description   : This function returns the current  input value of the given pin from port. Only pin
 * configured as input will have meaningful value.
 *
 * @implements    Siul2_Dio_Ip_ReadPin_Activity
 */
Siul2_Dio_Ip_PinsLevelType Siul2_Dio_Ip_ReadPin
(
    const Siul2_Dio_Ip_GpioType * const base,
    Siul2_Dio_Ip_PinsChannelType pin
)
{
    SIUL2_DIO_IP_DEV_ASSERT(NULL_PTR != base);
    SIUL2_DIO_IP_DEV_ASSERT((boolean)(pin < SIUL2_DIO_IP_NUM_OF_PIN_PORT));
    Siul2_Dio_Ip_PinsLevelType returnValue = 0U;
    returnValue = (Siul2_Dio_Ip_PinsLevelType)((Siul2_Dio_Ip_Rev_Bit_16(base->PGPDI) & ((Siul2_Dio_Ip_PinsChannelType)1U << pin)) >> pin);
    return returnValue;
}

/**
 * Function Name : Siul2_Dio_Ip_MaskedWritePins
 * Description   : This function writes the masked pins configured as output with the values given
 * in the parameter pins. '0' represents LOW, '1' represents HIGH.
 *
 * @implements    Siul2_Dio_Ip_MaskedWritePins_Activity
 */
void Siul2_Dio_Ip_MaskedWritePins
(
    uint8 u8Siul2Instance,
    uint8 u8PortId,
    Siul2_Dio_Ip_PinsChannelType pins,
    Siul2_Dio_Ip_PinsChannelType mask
)
{
    SIUL2_Type * base = (SIUL2_Type *)Siul2_Dio_Ip_au32BaseAdresses[u8Siul2Instance];
    uint32 maskRev;
    uint32 pinsRev;

    maskRev = (uint32)(Siul2_Dio_Ip_Rev_Bit_16(mask));
    pinsRev = (uint32)(Siul2_Dio_Ip_Rev_Bit_16(pins));
    base->MPGPDO[u8PortId] = (maskRev << (uint32)16U) | pinsRev;
}


#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

/******************************************************************************
 * EOF
 *****************************************************************************/
