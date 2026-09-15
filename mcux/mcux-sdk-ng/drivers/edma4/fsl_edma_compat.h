/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_EDMA_COMPAT_H_
#define FSL_EDMA_COMPAT_H_

/*
 * driver.edma4 is a deprecated alias of driver.edma_unified. The unified eDMA
 * driver (drivers/edma_unified) serves the eDMA3/eDMA4/eDMA5 IP versions and
 * provides the real implementation and public header (fsl_edma.h).
 *
 * This translation unit exists only so the deprecated driver.edma4 component
 * stays self-describing and resolvable for out-of-tree middleware/projects that
 * still reference driver.edma4; it defines no symbols of its own. driver.edma4
 * selects driver.edma_unified (see drivers/edma4/Kconfig), so both
 * driver.edma4 || driver.edma_unified resolve to the same unified driver files.
 *
 * New development should include "fsl_edma.h" and use driver.edma_unified
 * directly. (MCUX-88886)
 */
#include "fsl_edma.h"

#endif /* FSL_EDMA_COMPAT_H_ */
