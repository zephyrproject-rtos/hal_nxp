/************************************************************************
Change log:
     07/05/2022: Initial version
************************************************************************/
#ifndef _HOSTCMD_GENERATOR_H_
#define _HOSTCMD_GENERATOR_H_

#include    <stdio.h>
#include    <unistd.h>
#include    <string.h>
#include    <stdlib.h>
#include    <ctype.h>

/** Type definition: boolean */
typedef enum { FALSE, TRUE } boolean;

/** 16 bits byte swap */
#define swap_byte_16(x) \
((t_u16)((((t_u16)(x) & 0x00ffU) << 8) | \
		(((t_u16)(x) & 0xff00U) >> 8)))

/** 32 bits byte swap */
#define swap_byte_32(x) \
((t_u32)((((t_u32)(x) & 0x000000ffUL) << 24) | \
		 (((t_u32)(x) & 0x0000ff00UL) <<  8) | \
		 (((t_u32)(x) & 0x00ff0000UL) >>  8) | \
		 (((t_u32)(x) & 0xff000000UL) >> 24)))

/** Convert to correct endian format */
#ifdef BIG_ENDIAN_SUPPORT
/** CPU to little-endian convert for 16-bit */
#define     cpu_to_le16(x)  swap_byte_16(x)
/** CPU to little-endian convert for 32-bit */
#define     cpu_to_le32(x)  swap_byte_32(x)
/** Little-endian to CPU convert for 16-bit */
#define     le16_to_cpu(x)  swap_byte_16(x)
/** Little-endian to CPU convert for 32-bit */
#define     le32_to_cpu(x)  swap_byte_32(x)
#else
/** Do nothing */
#define     cpu_to_le16(x)  (x)
/** Do nothing */
#define     cpu_to_le32(x)  (x)
/** Do nothing */
#define     le16_to_cpu(x)  (x)
/** Do nothing */
#define     le32_to_cpu(x)  (x)
#endif

/** TLV header */
#define TLVHEADER       /** Tag */      \
						t_u16 tag;      \
						/** Length */   \
						t_u16 length

/** Length of TLV header */
#define TLVHEADER_LEN  4

/** Character, 1 byte */
typedef signed char t_s8;
/** Unsigned character, 1 byte */
typedef unsigned char t_u8;

/** Short integer */
typedef signed short t_s16;
/** Unsigned short integer */
typedef unsigned short t_u16;

/** Integer */
typedef signed int t_s32;
/** Unsigned integer */
typedef unsigned int t_u32;

/** Long long integer */
typedef signed long long t_s64;
/** Unsigned long long integer */
typedef unsigned long long t_u64;

/** Void pointer (4-bytes) */
typedef    void           t_void;

/** The attribute pack used for structure packing */
#ifndef __ATTRIB_PACK__
#define __ATTRIB_PACK__  __attribute__((packed))
#endif

/** Success */
#define MLAN_STATUS_SUCCESS         (0)
/** Failure */
#define MLAN_STATUS_FAILURE         (-1)
/** Not found */
#define MLAN_STATUS_NOTFOUND        (1)

#ifndef MIN
/** Find minimum value */
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif /* MIN */

/** Command buffer max length */
#define BUFFER_LENGTH       (4 * 1024)

/** HostCmd_DS_GEN */
typedef struct MAPP_HostCmd_DS_GEN
{
    /** Command */
    t_u16 command;
    /** Size */
    t_u16 size;
    /** Sequence number */
    t_u16 seq_num;
    /** Result */
    t_u16 result;
} __ATTRIB_PACK__ HostCmd_DS_GEN;

/** Size of HostCmd_DS_GEN */
#define S_DS_GEN    sizeof(HostCmd_DS_GEN)

/** Maximum length of lines in configuration file */
#define MAX_CONFIG_LINE         240

/** Size of command buffer */
#define MRVDRV_SIZE_OF_CMD_BUFFER       (3 * 1024)

#endif
