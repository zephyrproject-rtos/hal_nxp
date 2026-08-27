/*
 * Copyright 2012-2020,2022,2023,2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __UWB_TML_PROPRIETARY_H__
#define __UWB_TML_PROPRIETARY_H__

#include "zephyr/uwb/tml.h"
#include "uwb_tml_status.h"

UWBSTATUS uwb_tml_set_mode_fwdld(void);

#if UWBIOT_UWBD_SR2XXT
/**
**
** Function         uwb_tml_Chip_Reset
**
** Description      Invoke this API to Reset the Chip
**
** Parameters       None
**
** Returns          void
**
*/
void uwb_tml_chip_reset(void);
UWBSTATUS uwb_tml_hdll_transceive(uint8_t *pWriteBuf, size_t writeBufLen, uint8_t *pRespBuf, size_t *pRspBufLen);
int uwb_tml_hdll_read(uint8_t *pBuffer, uint16_t *pRspBufLen);
#endif

#if UWBIOT_SESN_SNXXX
void uwb_tml_io_enable_uwb_irq();
#endif

#if UWBIOT_TML_PNP || UWBIOT_TML_SOCKET
UWBSTATUS uwb_tml_hdll_reset(bool isFWDownloadDone);
#endif

#endif /*  __UWB_TML_PROPRIETARY_H__  */
