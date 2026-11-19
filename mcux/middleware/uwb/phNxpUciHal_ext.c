/*
 * Copyright 2012-2023,2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "phNxpUciHal.h"
#include "phNxpUwbConfig.h"
#include "zephyr/uwb/tml.h"
#include "phUwbTypes.h"
#include <uwb_tml_transport.h>
#include <uwb_board.h>
#include "zephyr/uwb/uwb_core.h"
#include "uci_ext_defs.h"

#if !(UWBIOT_UWBD_SR040)

int phNxpUciHal_set_board_config()
{
    uint8_t payload[] = {BOARD_VARIANT, UWB_BOARD_VERSION};
    uint16_t payload_len = sizeof(payload);
    uint8_t response[10] = {0};
    uint32_t response_len = sizeof(response);

    int ret = uwb_uci_transceive_control_packet(UCI_GID_PROPRIETARY_CUSTOM_1, EXT_UCI_MSG_CORE_DEVICE_INIT,
                        payload, payload_len,
                        response, &response_len);

    if (0 != ret) {
        /** Could not transceive UCI packet */
        return -1;
    }
    return 0;
}

#endif //!(UWBIOT_UWBD_SR04X)
