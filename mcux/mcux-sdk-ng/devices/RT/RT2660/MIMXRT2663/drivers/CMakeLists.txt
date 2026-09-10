# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# fsl_clock.c calls MODCON_GetCFG() (and the SoC reset path uses
# RESET_PeripheralReset()), both defined in fsl_modcon.c. The mcux component
# auto-selection does not pull driver.modcon for this lean tree, so force it on
# for the Zephyr MIMXRT2660-EVK baseline to satisfy the clock driver's dependency.
set(CONFIG_MCUX_COMPONENT_driver.modcon ON)

# fsl_power.c drives the memory controller directly (MEMCON_*), so driver.memcon
# has to be built alongside driver.power rather than only when something else
# selects it.
set(CONFIG_MCUX_COMPONENT_driver.memcon ON)

include(./CMakeLists_clock.txt)
include(./CMakeLists_edma_soc.txt)
include(./CMakeLists_iomuxc.txt)
include(./CMakeLists_memory.txt)
include(./CMakeLists_modcon.txt)
include(./CMakeLists_power.txt)
include(./CMakeLists_trdc_soc.txt)
include(./CMakeLists_mipi_dsi_soc.txt)
include(./CMakeLists_inputmux_connections.txt)
include(./CMakeLists_vbatcon.txt)
include(./CMakeLists_memcon.txt)
include(./CMakeLists_resetcon.txt)
include(./CMakeLists_mcm.txt)
