/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Note: this file is used to include those drivers only have .h file, for library build. */

#include "fsl_common.h"

#if defined(DMAMUX)
#include "fsl_dmamux.h"
#endif

#if defined(INTC)
#include "fsl_intc.h"
#endif

#if defined(PMC)
#include "fsl_pmc.h"
#endif

#if defined(SIM)
#include "fsl_sim.h"
#endif
