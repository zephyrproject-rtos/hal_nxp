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

MCUX_HAL_BASE = os.path.join(sys.path[0], '..')

def get_soc_family(device):
    if device.startswith('MK'):
        return 'kinetis'
    elif device.startswith('LPC'):
        return 'lpc'
    elif device.startswith('MIMX'):
        return 'imx'

def get_files(src, pattern):
    matches = []
    nonmatches = []
    always_exclude = "freertos|\.cmake"
    if os.path.exists(src):
        for filename in os.listdir(src):
            path = os.path.join(src, filename)
            if re.search(pattern, filename):
                matches.append(path)
            elif not re.search(always_exclude, filename):
                nonmatches.append(path)
                print(filename)

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

def import_sdk(directory, device_drivers_pattern = ""):
    devices = os.listdir(os.path.join(directory, 'devices'))
    boards = os.listdir(os.path.join(directory, 'boards'))

    for device in devices:
        family = get_soc_family(device)
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

        print('Importing {} device headers to {}'.format(device, device_dst))
        copy_files(device_headers, device_dst)

        print('Importing {} device-specific drivers to {}'.format(device, device_dst))
        copy_files(device_drivers, device_dst)

        print('Importing {} family shared drivers to {}'.format(family, shared_dst))
        copy_files(shared_drivers, shared_dst)

        print('Importing {} xip boot to {}'.format(device, shared_dst))
        copy_files(xip_boot, shared_dst)

    for board in boards:
        board_src = os.path.join(directory, 'boards', board)
        board_dst = os.path.join(MCUX_HAL_BASE, 'boards', board)

        xip_config_src = os.path.join(board_src, 'xip')
        xip_config_pattern = ".*"
        xip_config, _ = get_files(xip_config_src, xip_config_pattern)

        print('Importing {} xip config to {}'.format(board, board_dst))
        copy_files(xip_config, board_dst)

def parse_args():
    parser = argparse.ArgumentParser(description=__doc__)

    parser.add_argument("-f", "--file", required=True,
                        help="MCUXpresso SDK archive file to import from")

    parser.add_argument("-d", "--device_driver", required=False,
                        help="specify device specific driver file name pattern")

    args = parser.parse_args()

    with tempfile.TemporaryDirectory() as d:
        print('Extracting MCUXpresso SDK into temporary directory {}'.format(d))
        shutil.unpack_archive(args.file, d)
        import_sdk(d, args.device_driver)

def main():
    parse_args()

if __name__ == "__main__":
    main()
