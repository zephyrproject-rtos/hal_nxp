# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# fsl_clock.c calls MODCON_GetCFG() and the reset path uses
# RESET_PeripheralReset(), both in fsl_modcon.c; fsl_power.c drives MEMCON_*
# directly. Component auto-selection does not pull either for this lean tree,
# so force them on, as MIMXRT2663 does.
set(CONFIG_MCUX_COMPONENT_driver.modcon ON)
set(CONFIG_MCUX_COMPONENT_driver.memcon ON)

include(../../../RT2660/MIMXRT2663/drivers/CMakeLists_clock.txt)
include(../../../RT2660/MIMXRT2663/drivers/CMakeLists_edma_soc.txt)
include(../../../RT2660/MIMXRT2663/drivers/CMakeLists_iomuxc.txt)
include(../../../RT2660/MIMXRT2663/drivers/CMakeLists_memory.txt)
include(../../../RT2660/MIMXRT2663/drivers/CMakeLists_modcon.txt)
include(../../../RT2660/MIMXRT2663/drivers/CMakeLists_power.txt)
include(../../../RT2660/MIMXRT2663/drivers/CMakeLists_trdc_soc.txt)
include(../../../RT2660/MIMXRT2663/drivers/CMakeLists_mipi_dsi_soc.txt)
include(../../../RT2660/MIMXRT2663/drivers/CMakeLists_inputmux_connections.txt)
include(../../../RT2660/MIMXRT2663/drivers/CMakeLists_vbatcon.txt)
include(../../../RT2660/MIMXRT2663/drivers/CMakeLists_memcon.txt)
include(../../../RT2660/MIMXRT2663/drivers/CMakeLists_resetcon.txt)
include(../../../RT2660/MIMXRT2663/drivers/CMakeLists_mcm.txt)
