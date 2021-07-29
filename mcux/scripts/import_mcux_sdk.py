#!/usr/bin/env python3
#
# Copyright (c) 2018, NXP
#
# SPDX-License-Identifier: Apache-2.0

"""Import files from an NXP MCUXpresso SDK archive into Zephyr

The MCUXpresso SDK provides device header files and peripheral drivers for NXP
Kinetis, LPC, and i.MX SoCs. Zephyr drivers for these SoCs are shims that adapt
MCUXpresso SDK APIs to Zephyr APIs.

This script automates updating Zephyr to a newer version of the MCUXpresso SDK.
"""

import argparse
import os
import re
import shutil
import sys
import tempfile

#
# To save you some grief, the script requires Python 3.8 or newer due to
# usage of shutil.copytree() with 'dirs_exist_ok' parameter.
#
if not sys.version_info.major == 3 or sys.version_info.minor < 8:
    raise Exception("Script requires Python 3.8 or newer")

MCUX_HAL_BASE = os.path.join(sys.path[0], '..')

def get_soc_family(device):
    if device.startswith('MK'):
        return 'kinetis'
    elif device.startswith('LPC'):
        return 'lpc'
    elif device.startswith('MIMXRT685'):
        return 'imxrt6xx'
    elif device.startswith('MIMX'):
        return 'imx'

def get_files(src, pattern, skip_dirs = False):
    matches = []
    nonmatches = []
    always_exclude = "freertos|\.cmake"

    if os.path.exists(src):
        for filename in os.listdir(src):
            path = os.path.join(src, filename)
            if os.path.isdir(path) and skip_dirs:
                continue
            if re.search(pattern, filename):
                matches.append(path)
            elif not re.search(always_exclude, filename):
                nonmatches.append(path)

    return [matches, nonmatches]

def copy_files(files, dst):
    if not files:
        return
    always_exclude = "\.cmake"
    os.makedirs(dst, exist_ok=True)
    for f in files:
        if re.search(always_exclude, f):
            continue
        if os.path.isfile(f):
            shutil.copy2(f, dst)
        else:
            t = os.path.join(dst, os.path.basename(f))
            shutil.copytree(f, t, dirs_exist_ok=True, ignore = shutil.ignore_patterns("*.cmake"))

rt1176_device_files = [
   'cm4',
   'cm7',
   'fsl_acmp.c', 'fsl_acmp.h',
   'fsl_anatop_ai.c', 'fsl_anatop_ai.h',
   'fsl_clock.c', 'fsl_clock.h',
   'fsl_device_registers.h',
   'fsl_gpc.c', 'fsl_gpc.h',
   'fsl_iomuxc.h',
   'fsl_nic301.h',
   'fsl_pgmc.c', 'fsl_pgmc.h',
   'fsl_pmu.c', 'fsl_pmu.h',
   'fsl_romapi.c', 'fsl_romapi.h',
   'fsl_soc_mipi_csi2rx.c', 'fsl_soc_mipi_csi2rx.h',
   'fsl_soc_src.c', 'fsl_soc_src.h']

def import_sdk(directory, device_drivers_pattern = ""):
    devices = os.listdir(os.path.join(directory, 'devices'))
    boards = os.listdir(os.path.join(directory, 'boards'))
    print('********* devices *************')
    for device in devices:
        family = get_soc_family(device)
        print('device: {}, soc family: {}'.format(device,family))
        shared_dst = os.path.join(MCUX_HAL_BASE, 'drivers', family)
        device_dst = os.path.join(MCUX_HAL_BASE, 'devices', device)

        device_src = os.path.join(directory, 'devices', device)
        device_pattern = "|".join([device, 'fsl_device_registers'])
        device_headers, _ = get_files(device_src, device_pattern)

        drivers_src = os.path.join(directory, 'devices', device, 'drivers')
        drivers_pattern = "fsl_clock|fsl_iomuxc|fsl_power\.|fsl_reset\."

        if device_drivers_pattern != "":
            drivers_pattern = drivers_pattern + "|" + device_drivers_pattern
        #pattern fsl_power. has a full stop so other such as powerquad is not copied
        [device_drivers, shared_drivers] = get_files(drivers_src, drivers_pattern)

        xip_boot_src = os.path.join(directory, 'devices', device, 'xip')
        xip_boot_pattern = ".*"
        xip_boot, _ = get_files(xip_boot_src, xip_boot_pattern)

        #
        # Copying order:
        #   1) Device headers: devices/<device>/fsl_device_registers --> mcux/devices/<device>/
        #   2) Device specific drivers: devices/<device>/drivers --> mxux/devices/<device>/
        #   3) Special driver files that are unique to the device but found in
        #      the SDK drivers folder. (looking at you rt1176)
        #      devices/<device>/drivers -->mcux/devices/<device>
        #   4) Shared drivers: devices/<device>/drivers --> mcux/drivers
        #   5) XIP drivers: devices/<device>/XIP --> mcux/drivers/imx
        #
        print('Importing {} device headers to {}'.format(device, device_dst))
        #print('   device_src: {},\n   device_pattern: {},\n   device_dst: {}'.format(device_src, device_pattern, device_dst))
        copy_files(device_headers, device_dst)

        print('Importing {} device-specific drivers to {}'.format(device, device_dst))
        #print('   drivers_src: {},\n   drivers_pattern: {},\n   device_dst: {}'.format(drivers_src, drivers_pattern, device_dst))
        copy_files(device_drivers, device_dst)

        if device == 'MIMXRT1176':
            rt1176_tmp = []
            for i in range(len(shared_drivers) - 1, -1, -1):
                tfile = os.path.basename(shared_drivers[i])
                if tfile in rt1176_device_files:
                   rt1176_tmp.append(shared_drivers[i])
                   # clean up list of shared driver files so we don't end up
                   # copying the driver file to two locations
                   del shared_drivers[i]
            print('Importing {} special drivers to {}'.format(device, device_dst))
            copy_files(rt1176_tmp, device_dst)

        print('Importing {} family shared drivers to {}'.format(family, shared_dst))
        #print('   driver_src: {},\n   driver_pattern: {},\n   shared_dst: {}'.format(drivers_src, drivers_pattern, shared_dst))
        copy_files(shared_drivers, shared_dst)

        print('Importing {} xip boot to {}'.format(device, shared_dst))
        #print('   xip_boot_src: {},\n   xip_boot_pattern: {},\n   shared_dst: {}'.format(xip_boot_src, xip_boot_pattern, shared_dst))
        copy_files(xip_boot, shared_dst)

    print('********* boards *************')
    for board in boards:
        print(board)
        board_src = os.path.join(directory, 'boards', board)
        board_dst = os.path.join(MCUX_HAL_BASE, 'boards', board)

        print('Importing {} board drivers to {}'.format(board, board_dst))
        board_drivers_pattern = ".[ch]"
        board_drivers, _ = get_files(board_src, board_drivers_pattern, True)
        copy_files(board_drivers, board_dst)

        xip_config_src = os.path.join(board_src, 'xip')
        xip_config_pattern = ".*"
        xip_config, _ = get_files(xip_config_src, xip_config_pattern)

        print('Importing {} xip config to {}'.format(board, board_dst))
        copy_files(xip_config, board_dst)

        dcd_src = os.path.join(board_src, 'demo_apps', 'hello_world')
        if board == 'evkmimxrt1170':
            dcd_src = os.path.join(dcd_src, 'cm7')
        dcd_pattern = "dcd\.[ch]"
        dcd_files, _ = get_files(dcd_src, dcd_pattern)

        print('Importing {} dcd to {}'.format(board, board_dst))
        copy_files(dcd_files, board_dst)

        board_src = os.path.join(board_src, 'demo_apps', 'hello_world')
        if board == 'evkmimxrt1170':
            board_src = os.path.join(board_src, 'cm7')
        board_pattern = "clock_config.h|board.h"
        board_files, _ = get_files(board_src, board_pattern)

        print('Importing {} board files to {}'.format(board, board_dst))
        copy_files(board_files, board_dst)

        if board == 'evkmimxrt1170':
            board_src = os.path.join(directory, 'boards', board, 'display_examples', 'mipi_dsi_compliant_test', 'cm7')
            board_pattern = "display_support\.[ch]"
            board_files, _ = get_files(board_src, board_pattern)
            print('Importing {} board display sample files to {}'. format(board, board_dst))
            #print('  board_src: {}\n  board_pattern: {}\n  board_files: {}'.format(board_src, board_pattern, board_files))
            copy_files(board_files, board_dst)

def parse_args():
    parser = argparse.ArgumentParser(description=__doc__)

    parser.add_argument("-f", "--file", required=True,
                        help="MCUXpresso SDK archive file to import from")

    parser.add_argument("-d", "--device_driver", required=False, default='',
                        help="specify device specific driver file name pattern")

    args = parser.parse_args()

    if not os.path.exists(args.file):
        print("The file {} does not exist!".format(args.file))
        sys.exit(1)

    with tempfile.TemporaryDirectory() as d:
        print('Extracting MCUXpresso SDK into temporary directory {}'.format(d))
        shutil.unpack_archive(args.file, d)
        import_sdk(d, args.device_driver)

def main():
    parse_args()

if __name__ == "__main__":
    main()
