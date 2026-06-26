/** @file mlan_mgmt_ie.h
 *
 *  @brief This file contains MGMT IE information related
 *  definitions used in MLAN module.
 *
 *  Copyright 2026 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/******************************************************
Change log:
    05/11/2026: initial version
******************************************************/

#ifndef _MLAN_MGMT_IE_H_
#define _MLAN_MGMT_IE_H_

#ifdef __cplusplus
extern "C" {
#endif

#if defined(RW610)
/** Small buffer count in MGMT IE pool */
#define MLAN_MGMT_BUF_SM_CNT     4
/** Medium buffer count in MGMT IE pool */
#define MLAN_MGMT_BUF_MD_CNT     4
/** Large buffer count in MGMT IE pool */
#define MLAN_MGMT_BUF_LG_CNT     2
#else
/** Small buffer count in MGMT IE pool */
#define MLAN_MGMT_BUF_SM_CNT     6
/** Medium buffer count in MGMT IE pool */
#define MLAN_MGMT_BUF_MD_CNT     5
/** Large buffer count in MGMT IE pool */
#define MLAN_MGMT_BUF_LG_CNT     2
#endif

/** Small buffer size for MGMT IE buffer pool */
#define MLAN_MGMT_BUF_SM_SIZE    64
/** Medium buffer size for MGMT IE buffer pool */
#define MLAN_MGMT_BUF_MD_SIZE    192
/** Large buffer size for MGMT IE buffer pool */
#define MLAN_MGMT_BUF_LG_SIZE    256

/** MGMT IE mask for invalid index */
#define MLAN_MGMT_IE_INVALID_IDX    (0xFFFF)
/** MGMT IE mask indicating no valid mask */
#define MLAN_MGMT_IE_INVALID_MASK   (0xFFFF)
/** Flag indicating MGMT IE has been updated */
#define MLAN_MGMT_IE_UPDATED        (MBIT(7))

/** Magic number used to validate a buffer block */
#define MLAN_BUF_MAGIC 0xCAFEBABE

typedef struct _mlan_buf_block {
    struct _mlan_buf_block *next;
    t_u8  class_id;
    t_u32 magic;
    t_u8  data[];
} mlan_buf_block, *pmlan_buf_block;

typedef struct _mlan_buf_class {
    struct _mlan_buf_block *free_list;
    t_u16 buf_size;
    t_u16 total;
    t_u8  class_id;
    t_u8 *base;
} mlan_buf_class, *pmlan_buf_class;

typedef struct _mlan_buf_handle {
    t_u8 *mem_base;
    t_u32 mem_size;
    struct _mlan_buf_class *classes;
    t_u8 class_num;
    void *(*malloc_fn)(t_u32);
    void  (*free_fn)(void *);
} mlan_buf_handle, *pmlan_buf_handle;

typedef struct _mlan_buf_cfg {
    t_u16 buf_size;
    t_u8  buf_cnt;
} mlan_buf_cfg, *pmlan_buf_cfg;

/** Operation type for a batch IE request entry */
typedef enum {
    MGMT_IE_BATCH_SET,    /**< Set (add or update) an IE */
    MGMT_IE_BATCH_CLEAR,  /**< Clear an IE */
} mgmt_ie_batch_op;

/**
 * @brief Describes a single IE operation within a batch request.
 *
 * For MGMT_IE_BATCH_SET:   ie_mask, ie_buf, ie_len must be valid.
 * For MGMT_IE_BATCH_CLEAR: ie_mask/ie_buf/ie_len are ignored;
 *                          *index must not be MLAN_MGMT_IE_INVALID_IDX.
 */
typedef struct _mgmt_ie_batch_req {
    mgmt_ie_batch_op  op;   /**< Operation: SET or CLEAR */
    t_u16 *index;           /**< IN/OUT */
    t_u16  ie_mask;         /**< Management frame type mask */
    t_u16  ie_len;          /**< IE data length */
    t_u8  *ie_buf;          /**< IE data pointer */
} mgmt_ie_batch_req, *pmgmt_ie_batch_req;

/**
 * @brief Initialize MGMT IE parameters in the mlan adapter.
 *
 * Sets up the internal MGMT IE state within the given mlan adapter
 * instance. Must be called during adapter initialization.
 *
 * @param pmadapter    Pointer to the mlan adapter structure
 */
void wlan_init_mgmt_ie_param(pmlan_adapter pmadapter);

/**
 * @brief Initialize the MGMT IE buffer pool and IE mutex.
 *
 * Allocates and sets up the internal buffer pool used for MGMT IE
 * operations. Must be called before any MGMT IE API is used.
 *
 * @return     MLAN_STATUS_SUCCESS on success, error status otherwise
 */
mlan_status wifi_mgmt_ie_init(void);

/**
 * @brief Deinitialize the MGMT IE buffer pool and IE mutex.
 *
 * Frees all resources associated with the MGMT IE buffer pool.
 * Should be called during driver de-initialization.
 */
void wifi_mgmt_ie_deinit(void);

/**
 * @brief Set a Management IE for a given private interface.
 *
 * Stores the provided IE buffer into the MGMT IE table of the given
 * interface, associated with the specified IE mask. The index at which
 * the IE is stored is returned via the @p index parameter.
 *
 * @param priv         Pointer to the mlan private interface structure
 * @param ie_mask      Mask indicating the frame type(s) this IE applies to
 * @param ie_buf       Pointer to the IE data buffer
 * @param ie_len       Length of the IE data (in bytes)
 * @param index        Output pointer to store the assigned IE table index
 *
 * @return             MLAN_STATUS_SUCCESS on success, error status otherwise
 */
mlan_status wifi_mgmt_ie_set(mlan_private *priv, t_u16 ie_mask, t_u8 *ie_buf, t_u16 ie_len, t_u16 *index);

/**
 * @brief Set multiple Management IEs in a batch operation.
 *
 * @param priv         Pointer to the mlan private interface structure
 * @param reqs         Pointer to the array of batch IE requests
 * @param req_cnt      Number of requests in the array
 *
 * @return             MLAN_STATUS_SUCCESS on success, error status otherwise
 */
mlan_status wifi_mgmt_ie_set_batch(mlan_private *priv, mgmt_ie_batch_req *reqs, t_u8 req_cnt);

/**
 * @brief Clear a Management IE entry by index.
 *
 * Removes the IE stored at the given index from the MGMT IE table of the
 * specified interface. The index is set to MLAN_MGMT_IE_INVALID_IDX on
 * successful removal.
 *
 * @param priv         Pointer to the mlan private interface structure
 * @param index        Pointer to the IE table index to clear
 *
 * @return             MLAN_STATUS_SUCCESS on success, error status otherwise
 */
mlan_status wifi_mgmt_ie_clear(mlan_private *priv, t_u16 *index);

/**
 * @brief Replace a specific IE element within stored MGMT IEs.
 *
 * Searches the MGMT IE table for an existing IE matching the given IE ID
 * (and optionally OUI for vendor-specific IEs) and replaces it with the
 * new IE buffer provided.
 *
 * @param priv         Pointer to the mlan private interface structure
 * @param ie_buf       Pointer to the new IE data buffer
 * @param ie_len       Length of the new IE data (in bytes)
 * @param ie_id        IEEE element ID of the IE to replace
 * @param oui          Pointer to the OUI (used for vendor-specific IEs),
 *                     or NULL if not applicable
 *
 * @return             MLAN_STATUS_SUCCESS on success, error status otherwise
 */
mlan_status wifi_mgmt_ie_replace_elem(mlan_private *priv, t_u8 *ie_buf, t_u16 ie_len, IEEEtypes_ElementId_e ie_id, t_u8 *oui);

/**
 * @brief Fill a single mgmt_ie_batch_req entry.
 *
 * @param req      Pointer to the batch request entry to fill
 * @param index    IN/OUT: pointer to the IE index stored in priv
 * @param ie_mask  Management frame type mask
 * @param ie_buf   IE data buffer
 * @param ie_len   IE data length
 *
 * @return         MLAN_STATUS_SUCCESS if a request was filled, error status otherwise
 */
mlan_status wifi_mgmt_ie_req_fill(mgmt_ie_batch_req *req, t_u16 ie_mask, t_u8 *ie_buf, t_u16 ie_len, t_u16 *index);

/**
 * @brief Dump all MGMT IE entries for debugging purposes.
 *
 * Prints the contents of the MGMT IE table for all interfaces managed by
 * the given mlan adapter. Intended for debug use only.
 *
 * @param pmadapter    Pointer to the mlan adapter structure
 */
void wifi_mgmt_ie_dump(pmlan_adapter pmadapter);

#ifdef __cplusplus
}
#endif

#endif /* _MLAN_MGMT_IE_H_ */