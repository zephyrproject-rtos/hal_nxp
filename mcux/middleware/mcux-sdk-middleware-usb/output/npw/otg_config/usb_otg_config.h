/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __USB_0TG_CONFIG_H__
#define __USB_0TG_CONFIG_H__

/*!
 * @brief otg khci instance count, meantime it indicates khci enable or disable.
 *        - if 0, otg khci driver is disable.
 *        - if greater than 0, otg khci driver is enable.
 */
#define USB_OTG_CONFIG_KHCI (1U)

/*! if 1, the otg srp is enable; if 0, the otg srp is disbale */
#define USB_OTG_SRP_ENABLE (1U)

/*! if 1, the otg hnp is enable; if 0, the otg hnp is disbale */
#define USB_OTG_HNP_ENABLE (1U)

/*! if 1, the otg adp is enable; if 0, the otg adp is disbale */
#define USB_OTG_ADP_ENABLE (0U)

#if ((defined USB_OTG_CONFIG_KHCI) && (USB_OTG_CONFIG_KHCI))
/*!
 * @brief otg khci instance count, meantime it indicates khci enable or disable.
 *        - if 0, otg khci driver is disable.
 *        - if greater than 0, otg khci driver is enable.
 */
#define USB_OTG_KHCI_PERIPHERAL_ENABLE (1U)

#endif

#endif
