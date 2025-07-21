/*
 * Copyright 2021-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_memory.h"

static bool initialized = false;

#if (__CORTEX_M == 33U)
static uint32_t m33_ctcm_start;
static uint32_t m33_ctcm_end;
static uint32_t m33_ctcm_start_alias;
static uint32_t m33_ctcm_end_alias;
static uint32_t m33_ctcm_offset;
static uint32_t m33_stcm_start;
static uint32_t m33_stcm_end;
static uint32_t m33_stcm_start_alias;
static uint32_t m33_stcm_end_alias;
static uint32_t m33_stcm_offset;
#elif (__CORTEX_M == 7U)
static uint32_t m7_itcm_end;
static uint32_t m7_itcm_start_alias;
static uint32_t m7_itcm_end_alias;
static uint32_t m7_itcm_offset;
static uint32_t m7_dtcm_start;
static uint32_t m7_dtcm_end;
static uint32_t m7_dtcm_start_alias;
static uint32_t m7_dtcm_end_alias;
static uint32_t m7_dtcm_offset;
#endif

/* clang-format off */

/*!
 * @brief Get Memory Boundary Address
 *
 * This function translate CM33/CM7 TCM address between Core View and ALIAS System View
 * CM33 and CM7 TCM Address are determined by M33_CFG[TCM_SIZE] and M7_CFG[TCM_SIZE]
 *
 * | M7[TCM_SIZE] | ITCM START/ALIAS        | ITCM END/ALIAS          | DTCM START/ALIAS        | DTCM END/ALIAS          | Size    |
 * |--------------|-------------------------|-------------------------|-------------------------|-------------------------|---------|
 * | 000          | 0x0000_0000/0x203C_0000 | 0x0004_0000/0x2040_0000 | 0x2000_0000/0x2040_0000 | 0x2004_0000/0x2044_0000 | 256/256 |
 * | 001          | 0x0000_0000/0x2038_0000 | 0x0008_0000/0x2040_0000 | NA                      | NA                      | 512/0   |
 * | 010          | NA                      | NA                      | 0x2000_0000/0x2040_0000 | 0x2008_0000/0x2048_0000 | 0/512   |
 * | 100          | 0x0000_0000/0x203E_0000 | 0x0002_0000/0x2040_0000 | 0x2000_0000/0x2040_0000 | 0x2006_0000/0x2046_0000 | 128/384 |
 * | 101          | 0x0000_0000/0x203A_0000 | 0x0006_0000/0x2040_0000 | 0x2000_0000/0x2040_0000 | 0x2002_0000/0x2042_0000 | 384/128 |
 *
 * | M33[TCM_SIZE] | CTCM START/ALIAS        | CTCM END/ALIAS          | STCM START/ALIAS        | STCM END/ALIAS          | Size    |
 * |---------------|-------------------------|-------------------------|-------------------------|-------------------------|---------|
 * | 00            | 0x0FFE_0000/0x201E_0000 | 0x1000_0000/0x2020_0000 | 0x2000_0000/0x2020_0000 | 0x2002_0000/0x2022_0000 | 128/128 |
 * | 01            | 0x0FFC_0000/0x201C_0000 | 0x1000_0000/0x2020_0000 | NA                      | NA                      | 256/0   |
 * | 10            | NA                      | NA                      | 0x2000_0000/0x2020_0000 | 0x2004_0000/0x2024_0000 | 0/256   |
 * @param type address boundary to be retrieved.
 */

/* clang-format on */

uint32_t get_memory_address(addr_type_t type) {
  uint32_t m7_ctcm_size_cfg =
      (BLK_CTRL_S_AONMIX->M7_CFG & BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_MASK) >>
      BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_SHIFT;
  uint32_t m33_ctcm_size_cfg =
      (BLK_CTRL_S_AONMIX->M33_CFG & BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_MASK) >>
      BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_SHIFT;
  uint32_t transAddr = ADDRESS_NOT_AVAILABLE;
  switch (type) {
  case kCore_CM7_ITCM_START:
    switch (m7_ctcm_size_cfg) {
    case 0U:
    case 1U:
    case 4U:
    case 5U:
      transAddr = 0x0U;
      break;
    default:
      transAddr = ADDRESS_NOT_AVAILABLE;
      break;
    }
    break;
  case kCore_CM7_ITCM_START_ALIAS:
    switch (m7_ctcm_size_cfg) {
    case 0U:
      transAddr = 0x203C0000U;
      break;
    case 1U:
      transAddr = 0x20380000U;
      break;
    case 4U:
      transAddr = 0x203E0000U;
      break;
    case 5U:
      transAddr = 0x203A0000U;
      break;
    default:
      transAddr = ADDRESS_NOT_AVAILABLE;
      break;
    }
    break;
  case kCore_CM7_ITCM_END:
    switch (m7_ctcm_size_cfg) {
    case 0U:
      transAddr = 0x3FFFFU;
      break;
    case 1U:
      transAddr = 0x7FFFFU;
      break;
    case 4U:
      transAddr = 0x1FFFFU;
      break;
    case 5U:
      transAddr = 0x5FFFFU;
      break;
    default:
      transAddr = ADDRESS_NOT_AVAILABLE;
      break;
    }
    break;
  case kCore_CM7_ITCM_END_ALIAS:
    switch (m7_ctcm_size_cfg) {
    case 0U:
    case 1U:
    case 4U:
    case 5U:
      transAddr = 0x203FFFFFU;
      break;
    default:
      transAddr = ADDRESS_NOT_AVAILABLE;
      break;
    }
    break;
  case kCore_CM7_DTCM_START:
    switch (m7_ctcm_size_cfg) {
    case 0U:
    case 2U:
    case 4U:
    case 5U:
      transAddr = 0x20000000U;
      break;
    default:
      transAddr = ADDRESS_NOT_AVAILABLE;
      break;
    }
    break;
  case kCore_CM7_DTCM_START_ALIAS:
    switch (m7_ctcm_size_cfg) {
    case 0U:
    case 2U:
    case 4U:
    case 5U:
      transAddr = 0x20400000U;
      break;
    default:
      transAddr = ADDRESS_NOT_AVAILABLE;
      break;
    }
    break;
  case kCore_CM7_DTCM_END:
    switch (m7_ctcm_size_cfg) {
    case 0U:
      transAddr = 0x2003FFFFU;
      break;
    case 2U:
      transAddr = 0x2007FFFFU;
      break;
    case 4U:
      transAddr = 0x2005FFFFU;
      break;
    case 5U:
      transAddr = 0x2001FFFFU;
      break;
    default:
      transAddr = ADDRESS_NOT_AVAILABLE;
      break;
    }
    break;
  case kCore_CM7_DTCM_END_ALIAS:
    switch (m7_ctcm_size_cfg) {
    case 0U:
      transAddr = 0x2043FFFFU;
      break;
    case 2U:
      transAddr = 0x2047FFFFU;
      break;
    case 4U:
      transAddr = 0x2045FFFFU;
      break;
    case 5U:
      transAddr = 0x2041FFFFU;
      break;
    default:
      transAddr = ADDRESS_NOT_AVAILABLE;
      break;
    }
    break;
  case kCore_CM33_CTCM_START:
    switch (m33_ctcm_size_cfg) {
    case 0U:
      transAddr = 0xFFE0000U;
      break;
    case 1U:
      transAddr = 0xFFC0000U;
      break;
    default:
      transAddr = ADDRESS_NOT_AVAILABLE;
      break;
    }
    break;
  case kCore_CM33_CTCM_START_ALIAS:
    switch (m33_ctcm_size_cfg) {
    case 0U:
      transAddr = 0x201E0000U;
      break;
    case 1U:
      transAddr = 0x201C0000U;
      break;
    default:
      transAddr = ADDRESS_NOT_AVAILABLE;
      break;
    }
    break;
  case kCore_CM33_CTCM_END:
    switch (m33_ctcm_size_cfg) {
    case 0U:
    case 1U:
      transAddr = 0xFFFFFFFU;
      break;
    default:
      transAddr = ADDRESS_NOT_AVAILABLE;
      break;
    }
    break;
  case kCore_CM33_CTCM_END_ALIAS:
    switch (m33_ctcm_size_cfg) {
    case 0U:
    case 1U:
      transAddr = 0x201FFFFFU;
      break;
    default:
      transAddr = ADDRESS_NOT_AVAILABLE;
      break;
    }
    break;
  case kCore_CM33_STCM_START:
    switch (m33_ctcm_size_cfg) {
    case 0U:
    case 2U:
      transAddr = 0x20000000U;
      break;
    default:
      transAddr = ADDRESS_NOT_AVAILABLE;
      break;
    }
    break;
  case kCore_CM33_STCM_START_ALIAS:
    switch (m33_ctcm_size_cfg) {
    case 0U:
    case 2U:
      transAddr = 0x20200000U;
      break;
    default:
      transAddr = ADDRESS_NOT_AVAILABLE;
      break;
    }
    break;
  case kCore_CM33_STCM_END:
    switch (m33_ctcm_size_cfg) {
    case 0U:
      transAddr = 0x2001FFFFU;
      break;
    case 2U:
      transAddr = 0x2003FFFFU;
      break;
    default:
      transAddr = ADDRESS_NOT_AVAILABLE;
      break;
    }
    break;
  case kCore_CM33_STCM_END_ALIAS:
    switch (m33_ctcm_size_cfg) {
    case 0U:
      transAddr = 0x2021FFFF;
      break;
    case 2U:
      transAddr = 0x2023FFFF;
      break;
    default:
      transAddr = ADDRESS_NOT_AVAILABLE;
      break;
    }
    break;
  default:
    transAddr = ADDRESS_NOT_AVAILABLE;
    break;
  }
  return transAddr;
}

uint32_t MEMORY_ConvertMemoryMapAddress(uint32_t addr,
                                        mem_direction_t direction) {
  uint32_t dest;

  if (!initialized) {
#if (__CORTEX_M == 33U)
    m33_ctcm_start = get_memory_address(kCore_CM33_CTCM_START);
    m33_ctcm_end = get_memory_address(kCore_CM33_CTCM_END);
    m33_ctcm_start_alias = get_memory_address(kCore_CM33_CTCM_START_ALIAS);
    m33_ctcm_end_alias = get_memory_address(kCore_CM33_CTCM_END_ALIAS);
    m33_ctcm_offset = m33_ctcm_start_alias - m33_ctcm_start;
    m33_stcm_start = get_memory_address(kCore_CM33_STCM_START);
    m33_stcm_end = get_memory_address(kCore_CM33_STCM_END);
    m33_stcm_start_alias = get_memory_address(kCore_CM33_STCM_START_ALIAS);
    m33_stcm_end_alias = get_memory_address(kCore_CM33_STCM_END_ALIAS);
    m33_stcm_offset = m33_stcm_start_alias - m33_stcm_start;
#elif (__CORTEX_M == 7U)
    m7_itcm_end = get_memory_address(kCore_CM7_ITCM_END);
    m7_itcm_start_alias = get_memory_address(kCore_CM7_ITCM_START_ALIAS);
    m7_itcm_end_alias = get_memory_address(kCore_CM7_ITCM_END_ALIAS);
    m7_itcm_offset =
        m7_itcm_start_alias - get_memory_address(kCore_CM7_ITCM_START);
    m7_dtcm_start = get_memory_address(kCore_CM7_DTCM_START);
    m7_dtcm_end = get_memory_address(kCore_CM7_DTCM_END);
    m7_dtcm_start_alias = get_memory_address(kCore_CM7_DTCM_START_ALIAS);
    m7_dtcm_end_alias = get_memory_address(kCore_CM7_DTCM_END_ALIAS);
    m7_dtcm_offset = m7_dtcm_start_alias - m7_dtcm_start;
#endif
    initialized = true;
  }

  switch (direction) {
  case kMEMORY_Local2DMA: {
#if (__CORTEX_M == 33U)
    if (((addr >= m33_ctcm_start) && (addr <= m33_ctcm_end)) ||
        ((addr >= (m33_ctcm_start + FSL_MEM_M33_SECURE_ADDRESS_OFFSET)) &&
         (addr <= (m33_ctcm_end + FSL_MEM_M33_SECURE_ADDRESS_OFFSET)))) {
      dest = addr + m33_ctcm_offset;
    } else if (((addr >= m33_stcm_start) && (addr <= m33_stcm_end)) ||
               ((addr >=
                 (m33_stcm_start + FSL_MEM_M33_SECURE_ADDRESS_OFFSET)) &&
                (addr <= (m33_stcm_end + FSL_MEM_M33_SECURE_ADDRESS_OFFSET)))) {
      dest = addr + m33_stcm_offset;
    }
#elif (__CORTEX_M == 7U)
/* clang-format off */

          /*
           * For CM7, ITCM has valid memory 0, but for EDMA, 0 is also pointer NULL, which has specific
           * meaning. Considering we never use ITCM 0 as EDMA buffer, address translation for 0 is ignored
           */

/* clang-format on */
    if ((addr > 0U) && (addr <= m7_itcm_end)) {
      dest = addr + m7_itcm_offset;
    } else if ((addr >= m7_dtcm_start) && (addr <= m7_dtcm_end)) {
      dest = addr + m7_dtcm_offset;
    }
#endif
    else {
      dest = addr;
    }
    break;
  }
  case kMEMORY_DMA2Local: {
#if (__CORTEX_M == 33U)
    if (((addr >= m33_ctcm_start_alias) && (addr <= m33_ctcm_end_alias)) ||
        ((addr >= (m33_ctcm_start_alias + FSL_MEM_M33_SECURE_ADDRESS_OFFSET)) &&
         (addr <= (m33_ctcm_end_alias + FSL_MEM_M33_SECURE_ADDRESS_OFFSET)))) {
      dest = addr - m33_ctcm_offset;
    } else if (((addr >= m33_stcm_start_alias) &&
                (addr <= m33_stcm_end_alias)) ||
               ((addr >=
                 (m33_stcm_start_alias + FSL_MEM_M33_SECURE_ADDRESS_OFFSET)) &&
                (addr <=
                 (m33_stcm_end_alias + FSL_MEM_M33_SECURE_ADDRESS_OFFSET)))) {
      dest = addr - m33_stcm_offset;
    }
#elif (__CORTEX_M == 7U)
    if ((addr >= m7_itcm_start_alias) && (addr <= m7_itcm_end_alias)) {
      dest = addr - m7_itcm_offset;
    } else if ((addr >= m7_dtcm_start_alias) && (addr <= m7_dtcm_end_alias)) {
      dest = addr - m7_dtcm_offset;
    }
#endif
    else {
      dest = addr;
    }
    break;
  }
  default:
    dest = addr;
    break;
  }

  return dest;
}
