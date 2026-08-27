/*
 * Copyright 2012-2019,2021-2023 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * UWB Status Values - Function Return Codes
 */

#ifndef PHUWBSTATUS_H
#define PHUWBSTATUS_H

#include <phUwbTypes.h>
#include "uwb_tml_status.h"

/* Internally required by PHUWBSTVAL. */
#define PHUWBSTSHL8 (8U)
/* Required by PHUWBSTVAL. */
#define PHUWBSTBLOWER ((UWBSTATUS)(0x00FFU))

/** @defgroup UWBStatus UWB Status Codes
 */

/** @addtogroup UWBStatus
 *
 * @{
 */

/**
 *  UWB Status Composition Macro
 *
 *  This is the macro which must be used to compose status values.
 *
 *  phUwbCompID Component ID, as defined in phUwbCompId.h .
 *  phUwbStatus Status values, as defined in phUwbStatus.h .
 *
 *  The macro is not required for the #UWBSTATUS_SUCCESS value.
 *  This is the only return value to be used directly.
 *  For all other values it shall be used in assignment and conditional
 * statements, e.g.:
 *     UWBSTATUS status = PHUWBSTVAL(phUwbCompID, phUwbStatus); ...
 *     if (status == PHUWBSTVAL(phUwbCompID, phUwbStatus)) ...
 */
#define PHUWBSTVAL(phUwbCompID, phUwbStatus)  \
    (((phUwbStatus) == (UWBSTATUS_SUCCESS)) ? \
            (UWBSTATUS_SUCCESS) :             \
            ((((UWBSTATUS)(phUwbStatus)) & (PHUWBSTBLOWER)) | (((uint16_t)(phUwbCompID)) << (PHUWBSTSHL8))))

/** @} */

#endif /* PHUWBSTATUS_H */
