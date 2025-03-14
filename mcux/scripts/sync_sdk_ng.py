#!/usr/bin/env python3
#
# Copyright 2025 NXP
#
# SPDX-License-Identifier: Apache-2.0

import os
import sys
import re
import shutil
import argparse
from textwrap import dedent
from pathlib import Path

HELPSTR = f"""
This script synchronizes the MCUX SDK code to folder mcux/mcux-sdk-ng,
use the argument `--mcuxsdk_dir` to specify the MCUX SDK code folder,
like:
    {Path(__file__).name} --mcuxsdk_dir=~/mcuxsdk
"""

# Content to copy, use wildcard
COPY_CONTENT = [
    'devices/**/*',
    'drivers/**/*',
    'components/conn_fwloader/**/*',
    'components/flash/fsl_flash.h',
    'components/flash/mflash/**/*',
    'components/flash/nand/**/*',
    'components/flash/nor/**/*',
    'components/imu_adapter/**/*',
    'components/lists/**/*',
    'components/misc_utilities/**/*',
    'components/osa/**/*',
    'components/phy/**/*',
    'components/rpmsg/**/*',
    'components/wifi_bt_module/**/*',
    'middleware/usb/**/*',
]

# Content to remove, use wildcard
REMOVE_CONTENT = [
    '**/Kconfig*',
    'devices/**/RTE_Device.h',
    'devices/**/*.yml',
    'devices/**/*.icf',
    'devices/**/*.ld',
    'devices/**/*.scf',
    'devices/**/*.FLM',
    'devices/**/*.sdf',
    'devices/**/*.dbgconf',
    'devices/**/startup*.[sS]',
    'devices/**/mcuxpresso/startup_*.cpp',
    'devices/**/[Dd]oxygen',
    'devices/**/prj.conf',
    'drivers/**/[Dd]oxygen',
    'components/**/[Dd]oxygen',
    'middleware/usb/example',
    'middleware/usb/docs',
]

def banner(*args):
    print('===', *args)

def small_banner(*args):
    print('---', *args)


def copy_content():
    '''
    Copy the content specified by COPY_CONTENT
    '''
    for pattern in COPY_CONTENT:
        for f_src in MCUXSDK_BASE.glob(pattern):
            if '.git' in str(f_src):
                continue

            f_dst = HAL_NXP_SDK_BASE / f_src.relative_to(MCUXSDK_BASE)

            small_banner(f'Copy {f_src} to {f_dst}')

            f_dst.parent.mkdir(parents=True, exist_ok=True)
            if f_src.is_file():
                shutil.copy(f_src, f_dst)

def remove_content():
    '''
    Remove the content specified by REMOVE_CONTENT, this is called after
    `copy_content`.
    '''
    for pattern in REMOVE_CONTENT:
        for f in HAL_NXP_SDK_BASE.glob(pattern):
            small_banner(f'Remove {f}')
            if f.is_file():
                f.unlink()
            elif f.is_dir():
                shutil.rmtree(f)


def patch_clean_device_shared_cmake():
    '''
    Clean the shared.cmake file in devices folder, it adds the build flags,
    such as CC_FLAGS, LD_FLAGS, which are not used for zephyr.
    '''

    devices_dir = HAL_NXP_SDK_BASE / 'devices'

    for shared_cmake in devices_dir.rglob('shared.cmake'):
        small_banner(f'Clean the content of {shared_cmake}')
        with open(shared_cmake, 'w') as fd:
            fd.write('')

def patch_content():
    '''
    Patch the copied files from MCUX SDK, this is only for the changes which
    are not suitable to apply in MCUX SDK.
    '''
    patch_clean_device_shared_cmake()

def remove_empty_folders():
    '''
    Remove the empty folders.
    '''
    for folder in HAL_NXP_SDK_BASE.rglob('*'):
        if folder.is_dir() and not any(folder.iterdir()):
            small_banner(f'Remove empty folder {folder}')
            folder.rmdir()

def parse_args():

    parser = argparse.ArgumentParser(
        allow_abbrev=False,
        formatter_class=argparse.RawTextHelpFormatter,
        description = HELPSTR,
    )

    parser.add_argument("--mcuxsdk_dir", default='~/github/mcuxsdk',
                        help="mcuxsdk repo path, like ~/mcuxsdk, will copy files from here")

    args = parser.parse_args()

    return args


def main():
    global HAL_NXP_BASE, MCUXSDK_BASE, HAL_NXP_SDK_BASE

    args = parse_args()
    MCUXSDK_BASE = Path(args.mcuxsdk_dir).expanduser().resolve()

    HAL_NXP_BASE     = Path(__file__).parent.parent.parent.resolve()
    HAL_NXP_SDK_BASE = HAL_NXP_BASE / 'mcux' / 'mcux-sdk-ng'

    copy_content()
    remove_content()
    patch_content()

    remove_empty_folders()

    banner('=' * 80)
    banner('Copy completed.')


if __name__ == '__main__':
    main()
