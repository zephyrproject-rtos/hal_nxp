/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIUL2_DIO_IP_H
#define SIUL2_DIO_IP_H

/**
*   @file @file Siul2_Dio_Ip.h
*
*   @defgroup DIO_IPL Dio IPL
*   @{
*/

#if defined(__cplusplus)
extern "C" {
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Siul2_Dio_Ip_Cfg.h"

#if (CPU_TYPE == CPU_TYPE_64)
    typedef uint64 Siul2_Dio_Ip_CoreType;
#elif (CPU_TYPE == CPU_TYPE_32)
    typedef uint32 Siul2_Dio_Ip_CoreType;
#else
    #error "Unsupported CPU_TYPE"
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define SIUL2_DIO_IP_VENDOR_ID_H                     43
#define SIUL2_DIO_IP_AR_RELEASE_MAJOR_VERSION_H      4
#define SIUL2_DIO_IP_AR_RELEASE_MINOR_VERSION_H      7
#define SIUL2_DIO_IP_AR_RELEASE_REVISION_VERSION_H   0
#define SIUL2_DIO_IP_SW_MAJOR_VERSION_H              3
#define SIUL2_DIO_IP_SW_MINOR_VERSION_H              0
#define SIUL2_DIO_IP_SW_PATCH_VERSION_H              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Siul2_Dio_Ip header file and StandardTypes.h header file are of the same release version */
    #if ((SIUL2_DIO_IP_AR_RELEASE_MAJOR_VERSION_H != STD_AR_RELEASE_MAJOR_VERSION) || \
        (SIUL2_DIO_IP_AR_RELEASE_MINOR_VERSION_H != STD_AR_RELEASE_MINOR_VERSION)     \
        )
        #error "AutoSar Version Numbers of Siul2_Dio_Ip.h and StandardTypes.h are different"
    #endif
#endif

/* Check if Siul2_Dio_Ip header file and Siul2_Dio_Ip_Cfg configuration header file are of the same vendor */
#if (SIUL2_DIO_IP_VENDOR_ID_H != SIUL2_DIO_IP_VENDOR_ID_CFG_H)
    #error "Siul2_Dio_Ip.h and Siul2_Dio_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Siul2_Dio_Ip header file and Siul2_Dio_Ip_Cfg configuration header file are of the same Autosar version */
#if ((SIUL2_DIO_IP_AR_RELEASE_MAJOR_VERSION_H    != SIUL2_DIO_IP_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (SIUL2_DIO_IP_AR_RELEASE_MINOR_VERSION_H    != SIUL2_DIO_IP_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (SIUL2_DIO_IP_AR_RELEASE_REVISION_VERSION_H != SIUL2_DIO_IP_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
    #error "AutoSar Version Numbers of Siul2_Dio_Ip.h and Siul2_Dio_Ip_Cfg.h are different"
#endif

/* Check if Siul2_Dio_Ip header file and Siul2_Dio_Ip_Cfg configuration header file are of the same Software version */
#if ((SIUL2_DIO_IP_SW_MAJOR_VERSION_H != SIUL2_DIO_IP_SW_MAJOR_VERSION_CFG_H) || \
     (SIUL2_DIO_IP_SW_MINOR_VERSION_H != SIUL2_DIO_IP_SW_MINOR_VERSION_CFG_H) || \
     (SIUL2_DIO_IP_SW_PATCH_VERSION_H != SIUL2_DIO_IP_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Siul2_Dio_Ip.h and Siul2_Dio_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define  SIUL2_DIO_IP_GPDI_MASK_U8             ((uint8)0x1U)
#define  SIUL2_DIO_IP_PGPDO_OFFSET_U32         ((Siul2_Dio_Ip_CoreType)0x1700UL)
#define  SIUL2_DIO_IP_PGPDI_OFFSET_U32         ((uint32)0x1740UL)
#define  SIUL2_DIO_IP_GPDO_OFFSET_U32          ((uint32)0x1300UL)
#define  SIUL2_DIO_IP_GPDI_OFFSET_U32          ((uint32)0x1500UL)

#if (STD_ON == DIO_VIRTWRAPPER_SUPPORT)
#ifdef SIUL2_VIRTWRAPPER_MULTIINSTANCE
#define  SIUL2_DIO_IP_PDACSLOT_SIZE_U32        ((uint32)0x10000UL)
#endif
#endif

#define SIUL2_DIO_IP_PGPDO_ADDR32(SIUL2_INSTANCE,PGPDO_INDEX)  ((Siul2_Dio_Ip_CoreType)Siul2_Dio_Ip_au32BaseAdresses[SIUL2_INSTANCE] + SIUL2_DIO_IP_PGPDO_OFFSET_U32 +     \
                                                                (Siul2_Dio_Ip_CoreType)(((Siul2_Dio_Ip_CoreType)(((PGPDO_INDEX / 2UL) + 1UL) * 2UL) - (Siul2_Dio_Ip_CoreType)((PGPDO_INDEX % 2UL) + 1UL)) << 1UL)        \
                                                               )

#define SIUL2_DIO_IP_PGPDI_ADDR32(SIUL2_INSTANCE,PGPDI_INDEX)  (Siul2_Dio_Ip_au32BaseAdresses[SIUL2_INSTANCE] + SIUL2_DIO_IP_PGPDI_OFFSET_U32 +     \
                                                                (uint32)((uint32)((uint32)((uint32)((uint32)(PGPDI_INDEX / 2UL) + 1UL) * 2UL) -     \
                                                                                  (uint32)((uint32)(PGPDI_INDEX % 2UL) + 1UL)                       \
                                                                                 ) << 1UL                                                           \
                                                                        )                                                                           \
                                                               )

#if (STD_ON == DIO_VIRTWRAPPER_SUPPORT)
#ifdef SIUL2_VIRTWRAPPER_MULTIINSTANCE

#define SIUL2_DIO_IP_GPDO_ADDR32(SIUL2_INSTANCE,PDAC_INDEX,PIN)  (Siul2_Dio_Ip_au32BaseAdresses[SIUL2_INSTANCE] + PDAC_INDEX * SIUL2_DIO_IP_PDACSLOT_SIZE_U32 + SIUL2_DIO_IP_GPDO_OFFSET_U32 +(((PIN) & (~3UL)) | ((~((PIN) & 3UL)) & 3UL)))

#else

#define SIUL2_DIO_IP_GPDO_ADDR32(PDAC_INDEX,PIN)  (Siul2_Dio_Ip_au32BaseAdresses[PDAC_INDEX] + SIUL2_DIO_IP_GPDO_OFFSET_U32 +(((PIN) & (~3UL)) | ((~((PIN) & 3UL)) & 3UL)))

#endif  /*SIUL2_VIRTWRAPPER_MULTIINSTANCE*/
#else

#define SIUL2_DIO_IP_GPDO_ADDR32(SIUL2_INSTANCE,PIN)  (Siul2_Dio_Ip_au32BaseAdresses[(SIUL2_INSTANCE)] + SIUL2_DIO_IP_GPDO_OFFSET_U32 +(((PIN) & (~3UL)) | ((~((PIN) & 3UL)) & 3UL)))
#endif

#if (STD_ON == DIO_VIRTWRAPPER_SUPPORT)
#ifdef SIUL2_VIRTWRAPPER_MULTIINSTANCE

#define SIUL2_DIO_IP_GPDI_ADDR32(SIUL2_INSTANCE,PDAC_INDEX,PIN)  (Siul2_Dio_Ip_au32BaseAdresses[SIUL2_INSTANCE] + PDAC_INDEX * SIUL2_DIO_IP_PDACSLOT_SIZE_U32 + SIUL2_DIO_IP_GPDI_OFFSET_U32 +(((PIN) & (~3UL)) | ((~((PIN) & 3UL)) & 3UL)))

#else
#define SIUL2_DIO_IP_GPDI_ADDR32(PDAC_INDEX,PIN)  (Siul2_Dio_Ip_au32BaseAdresses[(PDAC_INDEX)] + SIUL2_DIO_IP_GPDI_OFFSET_U32 +(((PIN) & (~3UL)) | ((~((PIN) & 3UL)) & 3UL)))

#endif  /*SIUL2_VIRTWRAPPER_MULTIINSTANCE*/
#else

#define SIUL2_DIO_IP_GPDI_ADDR32(SIUL2_INSTANCE,PIN)  (Siul2_Dio_Ip_au32BaseAdresses[(SIUL2_INSTANCE)] + SIUL2_DIO_IP_GPDI_OFFSET_U32 +(((PIN) & (~3UL)) | ((~((PIN) & 3UL)) & 3UL)))

#endif

#if (STD_ON == DIO_VIRTWRAPPER_SUPPORT)
#define SIUL2_DIO_IP_MPGPDO_OFFSET_U32        ((uint32)0x1780UL)
#ifdef SIUL2_VIRTWRAPPER_MULTIINSTANCE

#define SIUL2_DIO_IP_MPGPDO_ADDR32(SIUL2_INSTANCE,PDAC_INDEX,MPGPDO_INDEX)   (Siul2_Dio_Ip_au32BaseAdresses[SIUL2_INSTANCE] + PDAC_INDEX * SIUL2_DIO_IP_PDACSLOT_SIZE_U32 + SIUL2_DIO_IP_MPGPDO_OFFSET_U32 + ((MPGPDO_INDEX) << 2UL))

#else

#define SIUL2_DIO_IP_MPGPDO_ADDR32(PDAC_INDEX,MPGPDO_INDEX)   (Siul2_Dio_Ip_au32BaseAdresses[(PDAC_INDEX)] + SIUL2_DIO_IP_MPGPDO_OFFSET_U32 + ((MPGPDO_INDEX) << 2UL))

#endif
#endif

#if (STD_ON == SIUL2_DIO_IP_DEV_ERROR_DETECT)
#define SIUL2_DIO_IP_DEV_ASSERT(par) DevAssert(par)
#else
#define SIUL2_DIO_IP_DEV_ASSERT(par)
#endif
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*!
 * @brief Type of a GPIO channel representation
 * Implements : Siul2_Dio_Ip_PinsChannelType_Class
 */
typedef uint16 Siul2_Dio_Ip_PinsChannelType;

/*!
 * @brief Type of a pin levels representation.
 * Implements : Siul2_Dio_Ip_PinsLevelType_Class
 */
typedef uint8 Siul2_Dio_Ip_PinsLevelType;

/*!
 * @brief Type of a parallel GPIO pad data in/out representation.
 * Implements : Siul2_Dio_Ip_GpioType_Class
 */
typedef struct
{
  __IO uint16 PGPDO;          /**< SIUL2 Parallel GPIO Pad Data Out Register, array offset: 0x1700, array step: 0x2 */
       uint16 RESERVED_1[31];
  __I  uint16 PGPDI;          /**< SIUL2 Parallel GPIO Pad Data In Register, array offset: 0x1740, array step: 0x2 */
} Siul2_Dio_Ip_GpioType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define DIO_START_SEC_VAR_INIT_32
#include "Dio_MemMap.h"

#if (STD_ON == DIO_VIRTWRAPPER_SUPPORT)
#ifdef SIUL2_VIRTWRAPPER_MULTIINSTANCE
extern Siul2_Dio_Ip_CoreType Siul2_Dio_Ip_au32BaseAdresses[SIUL2_INSTANCE_COUNT];
#else
extern Siul2_Dio_Ip_CoreType Siul2_Dio_Ip_au32BaseAdresses[6];
#endif
#else
extern Siul2_Dio_Ip_CoreType Siul2_Dio_Ip_au32BaseAdresses[SIUL2_INSTANCE_COUNT];
#endif

#define DIO_STOP_SEC_VAR_INIT_32
#include "Dio_MemMap.h"
/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

/*!
 * @brief Write a pin of a port with a given value
 *
 * This function writes the given pin from a port, with the given value
 * ('0' represents LOW, '1' represents HIGH).
 *
 * @param base  GPIO base pointer (PTA, PTB, PTC, etc.)
 * @param pin pin number to be written
 * @param value pin value to be written
 *        - 0: corresponding pin is set to LOW
 *        - 1: corresponding pin is set to HIGH
 */
void Siul2_Dio_Ip_WritePin
(
    Siul2_Dio_Ip_GpioType * const base,
    Siul2_Dio_Ip_PinsChannelType pin,
    Siul2_Dio_Ip_PinsLevelType value
);

/*!
 * @brief Write all pins of a port
 *
 * This function writes all pins configured as output with the values given in
 * the parameter pins. '0' represents LOW, '1' represents HIGH.
 *
 * @param[in] base GPIO base pointer (PTA, PTB, PTC, etc.)
 * @param[in] pins Pin mask to be written
 *        - 0: corresponding pin is set to LOW
 *        - 1: corresponding pin is set to HIGH
 */
void Siul2_Dio_Ip_WritePins
(
    Siul2_Dio_Ip_GpioType * const base,
    Siul2_Dio_Ip_PinsChannelType pins
);

/*!
 * @brief Get the current output from a port
 *
 * This function returns the current output that is written to a port. Only pins
 * that are configured as output will have meaningful values.
 *
 * @param[in] base GPIO base pointer (PTA, PTB, PTC, etc.)
 * @return GPIO outputs. Each bit represents one pin (LSB is pin 0, MSB is pin
 * 31). For each bit:
 *        - 0: corresponding pin is set to LOW
 *        - 1: corresponding pin is set to HIGH
 */
Siul2_Dio_Ip_PinsChannelType Siul2_Dio_Ip_GetPinsOutput
(
    const Siul2_Dio_Ip_GpioType * const base
);

/*!
 * @brief Write pins with 'Set' value
 *
 * This function configures output pins listed in parameter pins (bits that are
 * '1') to have a value of 'set' (HIGH). Pins corresponding to '0' will be
 * unaffected.
 *
 * @param[in] base GPIO base pointer (PTA, PTB, PTC, etc.)
 * @param[in] pins Pin mask of bits to be set. Each bit represents one pin (LSB is
 * pin 0, MSB is pin 31). For each bit:
 *        - 0: corresponding pin is unaffected
 *        - 1: corresponding pin is set to HIGH
 */
void Siul2_Dio_Ip_SetPins
(
    Siul2_Dio_Ip_GpioType * const base,
    Siul2_Dio_Ip_PinsChannelType pins
);

/*!
 * @brief Write pins to 'Clear' value
 *
 * This function configures output pins listed in parameter pins (bits that are
 * '1') to have a 'cleared' value (LOW). Pins corresponding to '0' will be
 * unaffected.
 *
 * @param[in] base GPIO base pointer (PTA, PTB, PTC, etc.)
 * @param[in] pins Pin mask of bits to be cleared. Each bit represents one pin (LSB
 * is pin 0, MSB is pin 31). For each bit:
 *        - 0: corresponding pin is unaffected
 *        - 1: corresponding pin is cleared(set to LOW)
 */
void Siul2_Dio_Ip_ClearPins
(
    Siul2_Dio_Ip_GpioType * const base,
    Siul2_Dio_Ip_PinsChannelType pins
);

/*!
 * @brief Toggle pins value
 *
 * This function toggles output pins listed in parameter pins (bits that are
 * '1'). Pins corresponding to '0' will be unaffected.
 *
 * @param[in] base GPIO base pointer (PTA, PTB, PTC, etc.)
 * @param[in] pins Pin mask of bits to be toggled.  Each bit represents one pin (LSB
 * is pin 0, MSB is pin 31). For each bit:
 *        - 0: corresponding pin is unaffected
 *        - 1: corresponding pin is toggled
 */
void Siul2_Dio_Ip_TogglePins
(
    Siul2_Dio_Ip_GpioType * const base,
    Siul2_Dio_Ip_PinsChannelType pins
);

/*!
 * @brief Read input pins
 *
 * This function returns the current input values from a port. Only pins
 * configured as input will have meaningful values.
 *
 * @param[in] base GPIO base pointer (PTA, PTB, PTC, etc.)
 * @return GPIO inputs. Each bit represents one pin (LSB is pin 0, MSB is pin
 * 31). For each bit:
 *        - 0: corresponding pin is read as LOW
 *        - 1: corresponding pin is read as HIGH
 */
Siul2_Dio_Ip_PinsChannelType Siul2_Dio_Ip_ReadPins
(
    const Siul2_Dio_Ip_GpioType * const base
);
/*!
 * @brief Write Port using MPGPDO
 *
 * This function writes the masked pins configured as output with the values given in the parameter pins.
 * '0' represents LOW, '1' represents HIGH.
 *
 * @param[in] u8Siul2Instance: instance number
 * @param[in] u8PortId: id of port need to be written (corresponds with index number of GPIO base (0-PTA, 1-PTB, etc))
 * @param[in] pins: Pin mask of bits to be cleared. Each bit represents one pin (LSB is pin 0, MSB is pin 31). For each bit: 0: corresponding
 *                  pin is unaffected. 1: corresponding pin is cleared(set to LOW).
 * @param[in] mask: mask for the affected pins
 * @return none
 */
void Siul2_Dio_Ip_MaskedWritePins
(
    uint8 u8Siul2Instance,
    uint8 u8PortId,
    Siul2_Dio_Ip_PinsChannelType pins,
    Siul2_Dio_Ip_PinsChannelType mask
);

/*!
 * @brief Read input pin
 *
 * This function returns the current  input value of the given pin from port. Only pin
 * configured as input will have meaningful value.
 *
 * @param[in] base GPIO base pointer (PTA, PTB, PTC, etc.)
 * @param[in] pin Pin index (0,1,2,3,..,15)
 * @return GPIO input value for coressponding pin
 *        - 0: corresponding pin is read as LOW
 *        - 1: corresponding pin is read as HIGH
 */
Siul2_Dio_Ip_PinsLevelType Siul2_Dio_Ip_ReadPin
(
    const Siul2_Dio_Ip_GpioType * const base,
    Siul2_Dio_Ip_PinsChannelType pin
);

#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* SIUL2_DIO_IP_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/
