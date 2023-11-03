/*! *********************************************************************************
 * \addtogroup BLE
 * @{
 ********************************************************************************** */
/*! *********************************************************************************
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2017, 2022 NXP
* All rights reserved.
* 
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef BLE_UTILS_H
#define BLE_UTILS_H

/************************************************************************************
*************************************************************************************
* Public constants & macros
*************************************************************************************
************************************************************************************/
/*! Type qualifier - does not affect local variables of integral type */
#ifndef PACKED_STRUCT
#if defined(__GNUC__)
#define PACKED_STRUCT struct __attribute__ ((__packed__))
#elif defined(__IAR_SYSTEMS_ICC__)
#define PACKED_STRUCT __packed struct
#else
#define PACKED_STRUCT struct
#endif
#endif

/*! Type qualifier - does not affect local variables of integral type */
#ifndef PACKED_UNION
#if defined(__GNUC__)
#define PACKED_UNION  union __attribute__ ((__packed__))
#elif defined(__IAR_SYSTEMS_ICC__)
#define PACKED_UNION __packed union
#elif defined(__CC_ARM)
#define PACKED_UNION union __attribute__((packed))
#else
#warning PACKED_UNION is not defined!
#endif
#endif

/*! Type qualifier - does not affect local variables of integral type */
#ifndef WEAK
#if defined(__GNUC__)
#define WEAK __attribute__ ((__weak__))
#elif defined(__IAR_SYSTEMS_ICC__)
#define WEAK __weak
#elif defined(__CC_ARM)
#define WEAK __weak
#endif
#endif

/*! Storage class modifier - alignment of a variable. It does not affect the type of the function */
#if defined(__IAR_SYSTEMS_ICC__)
#define ALIGN_8BIT  #pragma data_alignment(1)
#define ALIGN_16BIT #pragma data_alignment(2)
#define ALIGN_32BIT #pragma data_alignment(4)
#define ALIGN_64BIT #pragma data_alignment(8)
#elif defined(__GNUC__)
#define ALIGN_8BIT  #pragma pack(1)
#define ALIGN_16BIT #pragma pack(2)
#define ALIGN_32BIT #pragma pack(4)
#define ALIGN_64BIT #pragma pack(8)
#elif defined(__CC_ARM)
#define ALIGN_8BIT  #pragma pack(1)
#define ALIGN_16BIT #pragma pack(2)
#define ALIGN_32BIT #pragma pack(4)
#define ALIGN_64BIT #pragma pack(8)
#endif

/*! Marks a function that never returns. */
#if !defined(__IAR_SYSTEMS_ICC__)
#ifndef __noreturn
#define __noreturn
#endif
#endif

/*! Returns a uint16_t from a buffer, little-endian */
#define Utils_ExtractTwoByteValue(buf) \
    (((uint16_t)(*(buf))) | ( ((uint16_t)(*((buf) + 1U))) << 8U) )

/*! Returns a 3-byte value from a buffer, little-endian */
#define Utils_ExtractThreeByteValue(buf) \
( \
    (*(buf)) \
    | ( (*((buf) + 1U)) << 8U) \
    | ( (*((buf) + 2U)) << 16U) \
)

/*! Returns a uint32_t from a buffer, little-endian */
#define Utils_ExtractFourByteValue(buf) \
( \
    (*(buf)) \
    | ( ((uint32_t)(*((buf) + 1U))) << 8U) \
    | ( ((uint32_t)(*((buf) + 2U))) << 16U) \
    | ( ((uint32_t)(*((buf) + 3U))) << 24U) \
)

/*! Returns a uint16_t from a buffer, big-endian */
#define Utils_BeExtractTwoByteValue(buf) \
    ((*((buf) + 1U)) | ( (*(buf)) << 8U) )

/*! Returns a 3-byte value from a buffer, big-endian */
#define Utils_BeExtractThreeByteValue(buf) \
( \
    (*((buf) + 2U)) \
    | ( (*((buf) + 1U)) << 8U) \
    | ( (*(buf)) << 16U) \
)

/*! Returns a uint32_t from a buffer, big-endian */
#define Utils_BeExtractFourByteValue(buf) \
( \
    (*((buf) + 3U)) \
    | ( (*((buf) + 2U)) << 8U) \
    | ( (*((buf) + 1U)) << 16U) \
    | ( (*(buf)) << 24U) \
)

/*! Writes a uint16_t into a buffer, little-endian */
#define Utils_PackTwoByteValue(value, buf) \
{ \
    (buf)[0] = (uint8_t) ((value) & 0xFFU); \
    (buf)[1] = (uint8_t) (((uint16_t)(value) >> 8U) & 0xFFU); \
}

/*! Writes a 3-byte value into a buffer, little-endian */
#define Utils_PackThreeByteValue(value, buf) \
{ \
    (buf)[0] = (uint8_t) ((value) & 0xFFU); \
    (buf)[1] = (uint8_t) (((value) >> 8U) & 0xFFU); \
    (buf)[2] = (uint8_t) (((value) >> 16U) & 0xFFU); \
}

/*! Writes a uint32_t into a buffer, little-endian */
#define Utils_PackFourByteValue(value, buf) \
{ \
    (buf)[0] = (uint8_t) ((value) & 0xFFU); \
    (buf)[1] = (uint8_t) (((value) >> 8U) & 0xFFU); \
    (buf)[2] = (uint8_t) (((value) >> 16U) & 0xFFU); \
    (buf)[3] = (uint8_t) (((value) >> 24U) & 0xFFU); \
}

/*! Writes a uint16_t into a buffer, big-endian */
#define Utils_BePackTwoByteValue(value, buf) \
{ \
    (buf)[1] = (uint8_t) ((value) & 0xFFU); \
    (buf)[0] = (uint8_t) (((value) >> 8U) & 0xFFU); \
}

/*! Writes a 3-byte value into a buffer, big-endian */
#define Utils_BePackThreeByteValue(value, buf) \
{ \
    (buf)[2] = (uint8_t) ((value) & 0xFFU); \
    (buf)[1] = (uint8_t) (((value) >> 8U) & 0xFFU); \
    (buf)[0] = (uint8_t) (((value) >> 16U) & 0xFFU); \
}

/*! Writes a uint32_t into a buffer, big-endian */
#define Utils_BePackFourByteValue(value, buf) \
{ \
    (buf)[3] = (uint8_t) ((value) & 0xFFU); \
    (buf)[2] = (uint8_t) (((value) >> 8U) & 0xFFU); \
    (buf)[1] = (uint8_t) (((value) >> 16U) & 0xFFU); \
    (buf)[0] = (uint8_t) (((value) >> 24U) & 0xFFU); \
}

/*! Writes a uint8_t into a buffer, little-endian, and increments the pointer.*/
#define Utils_Copy8(ptr, val8) \
        {   *(ptr) = (uint8_t)(val8); \
             (ptr)++; }

/*! Writes a uint16_t into a buffer, little-endian, and increments the pointer. */
#define Utils_Copy16(ptr, val16) \
        {   *(ptr) = (uint8_t)(val16);\
             (ptr)++; \
            *(ptr) = (uint8_t)(((uint16_t)(val16)) >> SHIFT8);\
             (ptr)++; }

/*! Writes a uint32_t into a buffer, little-endian, and increments the pointer. */
#define Utils_Copy32(ptr, val32) \
        {   *(ptr) = (uint8_t)(val32);\
             (ptr)++; \
            *(ptr) = (uint8_t)((val32) >> SHIFT8);\
             (ptr)++; \
            *(ptr) = (uint8_t)((val32) >> SHIFT16);\
             (ptr)++; \
            *(ptr) = (uint8_t)((val32) >> SHIFT24);\
             (ptr)++; }

/*! Writes a uint64_t into a buffer, little-endian, and increments the pointer. */
#define Utils_Copy64(ptr, val64) \
        {   *(ptr) = (uint8_t)(val64);\
             (ptr)++; \
            *(ptr) = (uint8_t)((val64) >> SHIFT8);\
             (ptr)++; \
            *(ptr) = (uint8_t)((val64) >> SHIFT16);\
             (ptr)++; \
            *(ptr) = (uint8_t)((val64) >> SHIFT24);\
             (ptr)++; \
            *(ptr) = (uint8_t)((val64) >> SHIFT32);\
             (ptr)++; \
            *(ptr) = (uint8_t)((val64) >> SHIFT40);\
             (ptr)++; \
            *(ptr) = (uint8_t)((val64) >> SHIFT48);\
             (ptr)++; \
            *(ptr) = (uint8_t)((val64) >> SHIFT56);\
             (ptr)++; }

/*! Reverts the order of bytes in an array - useful for changing the endianness */
#define Utils_RevertByteArray(array, size) \
{ \
    uint8_t temp; \
    for (uint32_t j = 0U; j < (uint32_t)(size)/2U; j++) \
    { \
        temp = (array)[j]; \
        (array)[j] = (array)[(size) - 1U - j]; \
        (array)[(size) - 1U - j] = temp; \
    } \
}

#endif /* BLE_UTILS_H */

/*! *********************************************************************************
* @}
********************************************************************************** */
