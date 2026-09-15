# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# Deprecated alias of driver.edma_unified. driver.edma4 selects driver.edma_unified
# (see Kconfig), so the real implementation and public header (fsl_edma.h) come from
# drivers/edma_unified. This component ships only a header-only compatibility shim
# (fsl_edma_compat.h, which forwards to fsl_edma.h) so the deprecated component stays
# self-describing and resolvable for out-of-tree consumers; it defines no symbols of
# its own and never duplicates the unified driver sources. (MCUX-88886)
if(CONFIG_MCUX_COMPONENT_driver.edma4)
    # Mirror driver.edma_unified's version so the deprecated alias carries a valid
    # section_info version (required by the sdk data schema); both resolve to the
    # same unified driver. (MCUX-88886)
    mcux_component_version(2.10.13)

    mcux_add_source(
        SOURCES
        fsl_edma_compat.h
    )

    mcux_add_include(INCLUDES .)

endif()
