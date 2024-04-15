/*
 * Copyright 2018-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fwk_config.h"
#include "fwk_platform_extflash.h"
#include "fsl_os_abstraction.h"
#include "mflash_drv.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/
/* _SECTOR_ADDR returns the address of sector containing address */
#define _SECTOR_ADDR(addr) (((addr) & ~(PLATFORM_EXTFLASH_SECTOR_SIZE - 1U)))
/* _PAGE_ADDR returns the address of page containing address */
#define _PAGE_ADDR(addr) (((addr) & ~(PLATFORM_EXTFLASH_PAGE_SIZE - 1U)))

#if !defined PLATFORM_ACCESS_ALIGNMENT_CONSTRAINT_LOG
#define PLATFORM_ACCESS_ALIGNMENT_CONSTRAINT_LOG 0u
#endif

#define PLATFORM_ACCESS_UNIT_SZ  (1u << PLATFORM_ACCESS_ALIGNMENT_CONSTRAINT_LOG)
#define PLATFORM_ACCESS_UNIT_MSK (PLATFORM_ACCESS_UNIT_SZ - 1u)

#define _SZ_MULTIPLE_OF_ACCESS_UNIT(sz)           (((sz)&PLATFORM_ACCESS_UNIT_MSK) == 0u)
#define _ROUND_UP_MULTIPLE_OF_ACCESS_UNIT(length) ((length + PLATFORM_ACCESS_UNIT_MSK) & ~PLATFORM_ACCESS_UNIT_MSK)

/*
 * EXTFLASH_ALLOW_DIRECT_AHB_ACCESS is defined by default because performing direct AHB read is faster than
 * the explicit FlexSPI command method.
 * However keeping alternate code undefined because it may turn out useful when using remap feature for instance.
 */
#define EXTFLASH_ALLOW_DIRECT_AHB_ACCESS 1
/* -------------------------------------------------------------------------- */
/*                               Private functions                               */
/* -------------------------------------------------------------------------- */

static bool MemCmpToEraseValue(uint8_t *ptr, uint32_t blen)
{
    bool     ret            = true;
    uint32_t remaining_blen = blen;
    do
    {
        uint8_t *p_8 = ptr;
        uint32_t  unaligned_bytes = (uint32_t)ptr % 4;
        uint32_t *p_32;
        /* Compare byte by byte to 0xff till alignment */
        for (uint32_t i = 0u; i < unaligned_bytes; i++)
        {
            if (*p_8++ != 0xff)
            {
                ret = false;
                break; /* for */
            }
            remaining_blen--;
        }
        if (!ret)
        {
            break; /* do .. while */
        }
        /* offset_32b is at the word alignment offset in buffer */
        p_32 = (uint32_t *)&p_8[0];
        while (remaining_blen >= sizeof(uint32_t))
        {
            /* read word by word to compare to 0xffffffff */
            if (*p_32++ != ~0UL)
            {
                /* while */
                ret = false;
                break;
            }
            remaining_blen -= sizeof(uint32_t);
        }
        if (!ret)
        {
            /* do .. while */
            break;
        }
        p_8 = (uint8_t *)p_32;
        for (uint32_t i = 0u; i < remaining_blen; i++)
        {
            /* Unaligned trailing bytes */
            if (*p_8 != 0xffu)
            {
                ret = false;
                break;
            }
        }
    } while (false);
    return ret;
}

/*******************************************************************************
 * Public functions
 ******************************************************************************/

int PLATFORM_InitExternalFlash(void)
{
    status_t    st        = kStatus_Success;
    static bool init_done = false;
    if (!init_done)
    {
        st = mflash_drv_init();
        if (st == kStatus_Success)
        {
            init_done = true;
        }
    }
    return (int)st;
}

int PLATFORM_EraseExternalFlash(uint32_t address, uint32_t size)
{
    status_t st      = kStatus_Success;
    uint32_t endAddr = address + size;
    uint32_t startBlock, endBlock;
    uint32_t index;
    if ((endAddr & (PLATFORM_EXTFLASH_SECTOR_SIZE - 1U)) != 0U)
    {
        /* If the address is in the middle of a block, round up to the next block
         * This gives the upper block limit, every blocks before this one will be erased */
        endAddr = ((endAddr / PLATFORM_EXTFLASH_SECTOR_SIZE) + 1U) * PLATFORM_EXTFLASH_SECTOR_SIZE;
    }

    startBlock = address / PLATFORM_EXTFLASH_SECTOR_SIZE;
    endBlock   = endAddr / PLATFORM_EXTFLASH_SECTOR_SIZE;
    index      = startBlock;
    for (index = startBlock; (index < endBlock); index++)
    {
        uint32_t addr;

        /* The external flash driver is MFLASH, which has no Block Erase API, so limit to sector erase use only.
         * This is less optimal and operations take around 15% longer when erasing sectors one by one */
        addr = index * PLATFORM_EXTFLASH_SECTOR_SIZE;
        /* No address conversion to physical address */
        st = mflash_drv_sector_erase(addr);
        if (st != kStatus_Success)
        {
            break;
        }
    }
    return (int)st;
}

/* \brief Read from external flash to RAM buffer
 *
 * \dest[in/out] pointer of RAM destination to copy flash contents - arbitrary alignment
 * \param[in] length number of bytes - arbitrary byte length.
 * \param[in] address offset relative to the start of the flash device - not AHB address
 *
 * \return int return status: 0 for success, otherwise an error was raised.
 */
int PLATFORM_ReadExternalFlash(uint8_t *dest, uint32_t length, uint32_t address, bool requestFastRead)
{
    status_t st;
    (void)(requestFastRead);
#ifdef EXTFLASH_ALLOW_DIRECT_AHB_ACCESS
    memcpy(dest, (uint8_t *)EXTFLASH_PHYS_ADDR(address), length);
    st = 0;
#else
    do
    {
        uint8_t *p_dst;
        uint32_t read_sz;
        uint8_t  page_buf[PLATFORM_EXTFLASH_PAGE_SIZE + 4u];
        if ((uint32_t)dest % sizeof(uint32_t) == 0u)
        {
            read_sz = length & ~(sizeof(uint32_t) - 1);
            p_dst   = dest;
            st      = mflash_drv_read(address, (uint32_t *)p_dst, read_sz);
            if (kStatus_Success != st)
            {
                st = -1;
                break;
            }
            length -= read_sz;
            p_dst += read_sz; /* increased by read_sz that is necessarily a multiple of 4 */
            address += read_sz;
            if (length > 0u)
            {
                /* we cannot know whether the caller has left space for extra bytes to allow
                 * rounding size to next multiple of 4, so copy to page_buf and then memcpy the
                 * trailing bytes to the destination buffer */
                read_sz = (length + 3u) >> 2u << 2u;
                st      = mflash_drv_read(address, (uint32_t *)&page_buf[0], read_sz);
                if (kStatus_Success != st)
                {
                    st = -1;
                    break;
                }
                memcpy(p_dst, &page_buf[0], length);
            }
            st = 0;
        }
        else
        {
            uint32_t remaining_sz = length;

            while (remaining_sz > PLATFORM_EXTFLASH_PAGE_SIZE)
            {
                read_sz = PLATFORM_EXTFLASH_PAGE_SIZE;
                st      = mflash_drv_read(address, (uint32_t *)&page_buf[0], read_sz);
                if (kStatus_Success != st)
                {
                    st = -1;
                    break;
                }
                remaining_sz -= read_sz;
                address += read_sz;
                memcpy(dest, &page_buf[0], read_sz);
                dest += read_sz;
            }
            if (st < 0)
            {
                break;
            }
            if (remaining_sz > 0)
            {
                read_sz = (remaining_sz + 3u) >> 2u << 2u;
                st      = mflash_drv_read(address, (uint32_t *)&page_buf[0], read_sz);
                if (kStatus_Success != st)
                {
                    st = -1;
                    break;
                }
                memcpy(dest, &page_buf[0], remaining_sz);
            }
        }
        st = 0;
    } while (false);

#endif
    return (int)st;
}

/*
 * If address is not aligned, previous content may have been written to flash already.
 * Copy contents of partial page in RAM, add the new values at right offset in page buffer (256 bytes), then program
 * page. From that point on the remainder, if any, is page aligned. if any.
 */
int PLATFORM_WriteExternalFlash(uint8_t *data, uint32_t length, uint32_t address)
{
    status_t status;

    do
    {
        uint8_t  page_buf[PLATFORM_EXTFLASH_PAGE_SIZE];
        uint32_t page_addr;
        uint8_t *src;
        uint32_t write_len;
        uint32_t remaining_sz;

        src = (uint8_t *)data;

        remaining_sz = length;

        page_addr = address & ~(PLATFORM_EXTFLASH_PAGE_SIZE - 1U);
        if (page_addr != address)
        {
            uint32_t write_offset;
            /* copy partial contents of page - if any to RAM */
            /* The buffer receiving the contents of flash in RAM has alignment constraints dur to mflash / SPI
             programming. page_buf matches this condition */
            status = mflash_drv_read(page_addr, (uint32_t *)page_buf, PLATFORM_EXTFLASH_PAGE_SIZE);
            if (kStatus_Success != status)
            {
                break;
            }
            write_offset = (address - page_addr);
            write_len    = PLATFORM_EXTFLASH_PAGE_SIZE - write_offset;
            if (write_len > length)
            {
                write_len = length;
            }
            memcpy(&page_buf[write_offset], src, write_len);
            status = mflash_drv_page_program(page_addr, (uint32_t *)&page_buf[0]);
            if (kStatus_Success != status)
            {
                break;
            }
            src += write_len;
            page_addr += PLATFORM_EXTFLASH_PAGE_SIZE;
            remaining_sz -= write_len;
        }
        /* From now the address in flash is page aligned */

        while (remaining_sz >= PLATFORM_EXTFLASH_PAGE_SIZE)
        {
            memcpy(page_buf, src, PLATFORM_EXTFLASH_PAGE_SIZE);
            status = mflash_drv_page_program(page_addr, (uint32_t *)&page_buf[0]);
            if (status != kStatus_Success)
            {
                break;
            }
            remaining_sz -= PLATFORM_EXTFLASH_PAGE_SIZE;
            src += PLATFORM_EXTFLASH_PAGE_SIZE;
            page_addr += PLATFORM_EXTFLASH_PAGE_SIZE;
        }
        /* If a partial page has to be written, pad remainder with 0xff */
        if (remaining_sz > 0u)
        {
            /* partial page left*/
            memcpy(page_buf, src, remaining_sz);
            memset(&page_buf[remaining_sz], 0xffu, PLATFORM_EXTFLASH_PAGE_SIZE - remaining_sz);
            status = mflash_drv_page_program(page_addr, (uint32_t *)page_buf);
            if (status != kStatus_Success)
            {
                break;
            }
        }
        status = kStatus_Success;
    } while (0 != 0);

    return (int)status;
}

int PLATFORM_IsExternalFlashBusy(bool *isBusy)
{
    uint32_t dummy;
    status_t st;
    st      = mflash_drv_read(0U, (void *)&dummy, sizeof(uint32_t));
    *isBusy = (kStatus_Busy == st) ? 1U : 0U;
    return (int)st;
}

bool PLATFORM_ExternalFlashAreaIsBlank(uint32_t address, uint32_t len)
{
#ifdef EXTFLASH_ALLOW_DIRECT_AHB_ACCESS
    /*
     * Direct access to flash contents requires conversion from offset in flash to AHB address.
     */
    return MemCmpToEraseValue((uint8_t *)EXTFLASH_PHYS_ADDR(address), len);
#else
    bool     ret = false;
    uint8_t  page_buf[PLATFORM_EXTFLASH_PAGE_SIZE];
    uint32_t remaining_len = len;
    while (remaining_len > 0u)
    {
        uint32_t read_sz = MIN(PLATFORM_EXTFLASH_PAGE_SIZE, remaining_len);
        if (0 == PLATFORM_ReadExternalFlash(&page_buf[0], read_sz, address, true))
        {
            if (!MemCmpToEraseValue(&page_buf[0], read_sz))
            {
                break;
            }
        }
        else
        {
            assert(0);
            break;
        }
        remaining_len -= read_sz;
    }
    ret = (remaining_len == 0u);
    return ret;
#endif
}

bool PLATFORM_IsExternalFlashPageBlank(uint32_t address)
{
    /* Start from address of page containing argument address */
    uint32_t page_addr = _PAGE_ADDR(address);
    return PLATFORM_ExternalFlashAreaIsBlank(page_addr, PLATFORM_EXTFLASH_PAGE_SIZE);
}

bool PLATFORM_IsExternalFlashSectorBlank(uint32_t address)
{
    /* Start from address of sector containing argument address */
    uint32_t sect_addr = _SECTOR_ADDR(address);
    return PLATFORM_ExternalFlashAreaIsBlank(sect_addr, PLATFORM_EXTFLASH_SECTOR_SIZE);
}