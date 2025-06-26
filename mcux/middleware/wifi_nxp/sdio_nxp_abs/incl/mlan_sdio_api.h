/*
 *  Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*! \file mlan_sdio_api.h
 * \brief SDIO Driver
 *
 *  The SDIO driver is used to configure and do
 *  data transfer over the SDIO interface
 *
 * \section mlan_sdio_usage Usage
 *
 *  Steps to use sdio with mlan:
 *
 *  1. Register gpio using \ref sdio_drv_init()
 *
 *  2. Open the device using sdio_drv_open() call.
 *     This will return a handler to gpio.
 *
 *  3. To do various SDIO related operations:
 *
 *	- sdio_drv_write() : Write using CMD53
 *	- sdio_drv_read() : Read using CMD53
 *	- sdio_drv_creg_write() : Write using CMD52
 *	- sdio_drv_creg_read() : Read using CMD52
 *
 *     Locking mechanism is implemented to provide atomic access.
 *
 *  4. Close the device using sdio_drv_close() call.
 */

#ifndef _MLAN_SDIO_API_H_
#define _MLAN_SDIO_API_H_

#include <wmlog.h>

#define sdio_e(...) wmlog_e("sdio", ##__VA_ARGS__)

#if CONFIG_WIFI_SDIO_DEBUG
#define sdio_d(...) wmlog("sdio", ##__VA_ARGS__)
#else
#define sdio_d(...)
#endif /* CONFIG_WIFI_SDIO_DEBUG */

#define SDIO_GO_IDLE_STATE      ((uint8_t)0)
#define SDIO_SET_REL_ADDR       ((uint8_t)3)
#define SDIO_SDIO_SEN_OP_COND   ((uint8_t)5)
#define SDIO_SEL_DESEL_CARD     ((uint8_t)7)
//#define SDIO_RW_DIRECT          ((uint8_t)52)
#define SDIO_RW_DIRECT_EXTENDED ((uint8_t)53)

/* Depends on DMA_BUFSZ */
#define DMA_BOUNDARY_SIZE (512 * 1024)

/** Read Card Register
 *
 * This is used to read card register using CMD52.
 * This is a blocking call.
 *
 *  \param addr Card Register Address
 *  \param fn Number of the function with the Card
 *  \param resp Response of CMD52
 *  \return true on success, false otherwise
 */
int sdio_drv_creg_read(int addr, int fn, uint32_t *resp);

/** Write to Card Register
 *
 * This is used to write to card register using CMD52.
 * This is a blocking call.
 *
 *  \param addr Card Register Address
 *  \param fn Number of the function with the Card
 *  \param data value to be written on register
 *  \param resp Response of CMD52
 *  \return true on success, false otherwise
 */
int sdio_drv_creg_write(int addr, int fn, uint8_t data, uint32_t *resp);

/** Read Data from SDIO
 *
 * This is used to read data from SDIO card using CMD53.
 * This is a blocking call.
 *
 *  \param addr Card Register Address
 *  \param fn Number of the function with the Card
 *  \param bcnt Number of blocks to be read
 *  \param bsize Size of each block
 *  \param buf Buffer to read the data into
 *  \param resp Response of CMD53
 *  \return true on success, false otherwise
 */
int sdio_drv_read(uint32_t addr, uint32_t fn, uint32_t bcnt, uint32_t bsize, uint8_t *buf, uint32_t *resp);

#if FSL_USDHC_ENABLE_SCATTER_GATHER_TRANSFER
void sg_init_table();
void sg_set_num(size_t num_sg);
void sg_set_buf(uint32_t *buf, size_t len);
int sdio_drv_read_mb(uint32_t addr, uint32_t fn, uint32_t bcnt, uint32_t bsize);
#endif

/** Write Data to SDIO
 *
 * This is used to write data to SDIO card using CMD53.
 * This is a blocking call.
 *
 *  \param addr Card Register Address
 *  \param fn Number of the function with the Card
 *  \param bcnt Number of blocks to be written
 *  \param bsize Size of each block
 *  \param buf Buffer to write the data into
 *  \param resp Response of CMD53
 *  \return true on success, false otherwise
 */
int sdio_drv_write(uint32_t addr, uint32_t fn, uint32_t bcnt, uint32_t bsize, uint8_t *buf, uint32_t *resp);

/** Initialize the SDIO Driver
 *
 * This should be called once before using the driver.
 * The callback for Card Interrupt can be registered using this call.
 *
 *  \param cd_int Callback for Card Detect Interrupt
 *  \return WM_SUCCESS or -WM_FAIL
 */
int sdio_drv_init(void (*cd_int)(int));

/** Deinitialize the SDIO Driver
 *
 *  \return void
 */
void sdio_drv_deinit(void);

#endif /* !_MDEV_SDIO_API_H_ */
