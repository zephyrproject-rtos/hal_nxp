import os
import sys
import re
import shutil
from pathlib import Path
import argparse


# Keep these devices folders
DEVICES_KEEP = [
    'LPC54113',
    'LPC54114',
    'LPC5502CPXXXX',
    'LPC5504CPXXXX',
    'LPC5506CPXXXX',
    'LPC810',
    'LPC811',
    'LPC812',
    'MIMX8DX1',
    'MIMX8DX2',
    'MIMX8DX3',
    'MIMX8DX4',
    'MIMX8DX5',
    'MIMX8DX6',
    'MIMX8QM6',
    'MIMX8QX1',
    'MIMX8QX2',
    'MIMX8QX3',
    'MIMX8QX4',
    'MIMX8QX5',
    'MIMX8QX6',
    'MIMX8UX5',
    'MIMX8UX6',
    'MIMX8ML8',
    'MIMX8MM6',
    'MIMX8MN6',
    'MIMX8UD7',
    'MIMX9352',
    'MIMX9596',
    'MK22F12',
    'MK24F12',
    'MK26F18',
    'MK27FA15',
    'MK28FA15',
    'MK63F12',
    'MK64F12',
    'MK65F18',
    'MK66F18',
    'MK80F25615',
    'MK82F25615',
    'MKE04Z1284',
    'MKE04Z4',
    'MKE06Z4',
    'MKE14F16',
    'MKE16F16',
    'MKE18F16',
    'MKL17Z644',
    'MKL25Z4',
    'MKL27Z644',
    'MKV10Z1287'
    'MKV10Z7',
    'MKV11Z7',
    'MKV30F12810',
    'MKV31F12810',
    'MKV31F25612',
    'MKV31F51212',
    'MKV56F24',
    'MKV58F24',
    'MKW20Z4',
    'MKW21Z4',
    'MKW22D5',
    'MKW24D5',
    'MKW30Z4',
    'MKW31Z4',
    'MKW40Z4',
    'MKW41Z4'
]


def banner(*args):
    print('===', *args)

def small_banner(*args):
    print('---', *args)

def remove_file(path):
    path = Path(path)

    if path.exists():
        if path.is_file():
            path.unlink()
        elif path.is_dir():
            shutil.rmtree(path)


def remove_unused():
    banner('Remove unused folders')

    unused = [
        HAL_NXP_BASE / 'mcux' / 'components',
        HAL_NXP_SDK_BASE / 'cmsis_drivers',
        HAL_NXP_SDK_BASE / 'middleware', # Only mmcau, from hal_nxp.cmake, it is not used
        HAL_NXP_SDK_BASE / 'platform',   # Only rt1180 netc, will be in devices folder
    ]

    for d in unused:
        small_banner(f"Remove: {d}")
        remove_file(d)


def copy_drivers():

    banner('Copy Drivers')

    HAL_NXP_DRIVER = HAL_NXP_SDK_BASE / 'drivers'
    MCUXSDK_DRIVER = MCUXSDK_BASE / 'drivers'

    # Don't remove the old files, which will be used by legacy platforms.
    # Only remove the freertos drivers
    small_banner(f"Remove old drivers in {HAL_NXP_DRIVER}")
    for f in HAL_NXP_DRIVER.glob('**/*freertos*'):
        remove_file(f)

    # Only copy the "*.c", "*.h", "CmakeLists.txt", "Kconfig*", "*.cmake" files
    for root, dirs, files in os.walk(MCUXSDK_DRIVER):
        for file in files:
            if file == 'CMakeLists.txt' or file.endswith(('.c', '.h', '.cmake')) or file.startswith('Kconfig'):
                # Copy to HAL_NXP_BASE/drivers with the same folder structure
                src = Path(root) / file
                dst = HAL_NXP_DRIVER / src.relative_to(MCUXSDK_DRIVER)

                small_banner(f'Copy {src} to {dst}')

                dst.parent.mkdir(parents=True, exist_ok=True)
                shutil.copy(src, dst)

def copy_arch():

    banner('Copy ARCH')

    HAL_NXP_ARCH = HAL_NXP_SDK_BASE / 'arch'
    MCUXSDK_ARCH = MCUXSDK_BASE / 'arch'

    small_banner(f"Copy {MCUXSDK_ARCH} to {HAL_NXP_ARCH}")
    shutil.copytree(MCUXSDK_ARCH, HAL_NXP_ARCH, dirs_exist_ok=True)

    # Remove the CMSIS folder
    remove_file(HAL_NXP_ARCH / 'arm' / 'CMSIS')



def copy_boards():

    banner('Copy Boards')

    HAL_NXP_BOARD = HAL_NXP_SDK_BASE / 'boards'
    MCUXSDK_BOARD = MCUXSDK_BASE / 'examples' / '_boards'

    def _is_board_need_file(f):
        # In board folder, only the files for XIP and DCD are needed.
        f = str(f)
        return f.endswith(('.c', '.h')) and \
            (not re.search(r'demo_apps|examples', f)) and \
            re.search(r'(\bxmcd|\bdcd|\bflash_config|flexspi_nor_config|flexspi_nor_qspi_config)\.[ch]', f)

    # Before copying, remove the existing files
    small_banner(f"Remove old board files")
    for root, dirs, files in os.walk(HAL_NXP_BOARD):
        for file in files:
            f = Path(root) / file
            if not _is_board_need_file(f):
                small_banner(f"Remove {f}")
                remove_file(f)

    # Copy the new one
    for root, dirs, files in os.walk(MCUXSDK_BOARD):
        for file in files:
            f = Path(root) / file
            if _is_board_need_file(f):
                src = Path(root) / file
                dst = HAL_NXP_BOARD / src.relative_to(MCUXSDK_BOARD)

                small_banner(f'Copy {src} to {dst}')

                dst.parent.mkdir(parents=True, exist_ok=True)
                shutil.copy(src, dst)


def copy_devices():

    banner('Copy Devices')

    HAL_NXP_DEVICE = HAL_NXP_SDK_BASE / 'devices'
    MCUXSDK_DEVICE = MCUXSDK_BASE / 'devices'

    # Remove the old files in devices folder
    for d in HAL_NXP_DEVICE.iterdir():
        if d.is_dir() and d.name not in DEVICES_KEEP:
            shutil.rmtree(HAL_NXP_DEVICE / d)

    # Copy the new one
    # Only copy the "*.c", "*.h", "CmakeLists.txt", "Kconfig*", "*.cmake" files
    for root, dirs, files in os.walk(MCUXSDK_DEVICE):
        for file in files:
            if file == 'CMakeLists.txt' or file.endswith(('.c', '.h', '.cmake')) or file.startswith('Kconfig'):
                # Copy to HAL_NXP_BASE/drivers with the same folder structure
                src = Path(root) / file
                dst = HAL_NXP_DEVICE / src.relative_to(MCUXSDK_DEVICE)

                small_banner(f'Copy {src} to {dst}')

                dst.parent.mkdir(parents=True, exist_ok=True)
                shutil.copy(src, dst)

    # Remove the variables used in Kconfig, it is not supported in Zephyr
    for root, dirs, files in os.walk(HAL_NXP_DEVICE):
        for file in files:
            if file.startswith('Kconfig'):
                with open(f'{root}/{file}', 'r') as fd:
                    data = fd.read()

                data = re.sub(r'^(?!#)(.*\${core_id})', '# \g<1>', data, flags=re.M)

                with open(f'{root}/{file}', 'w') as fd:
                    fd.write(data)


def copy_tools():

    banner('Copy Tools')

    # Cmake functions
    HAL_NXP_CMAKE = HAL_NXP_SDK_BASE / 'cmake'
    MCUXSDK_CMAKE = MCUXSDK_BASE / 'cmake'

    # Copy the cmake files
    small_banner(f"Copy cmake files")
    cmake_extension_dir = HAL_NXP_CMAKE / 'extension'
    cmake_extension_dir.mkdir(parents=True, exist_ok=True)
    shutil.copy(MCUXSDK_CMAKE / 'extension' / 'function.cmake', HAL_NXP_CMAKE / 'extension')
    shutil.copy(MCUXSDK_CMAKE / 'extension' / 'logging.cmake', HAL_NXP_CMAKE / 'extension')

def parse_args():

    parser = argparse.ArgumentParser(allow_abbrev=False)

    parser.add_argument("--hal_nxp_dir", default='.',
                        help="hal_nxp repo path")

    parser.add_argument("--mcuxsdk_dir", default='~/github/mcuxsdk',
                        help="mcuxsdk repo path, like ~/mcuxsdk")

    args = parser.parse_args()

    return args

def main():
    global HAL_NXP_BASE, MCUXSDK_BASE, HAL_NXP_SDK_BASE

    args = parse_args()

    HAL_NXP_BASE = Path(args.hal_nxp_dir).expanduser().resolve()
    MCUXSDK_BASE = Path(args.mcuxsdk_dir).expanduser().resolve()
    HAL_NXP_SDK_BASE = HAL_NXP_BASE / 'mcux' / 'mcux-sdk'


    remove_unused()

    copy_tools()
    copy_arch()
    copy_drivers()
    copy_boards()
    copy_devices()


if __name__ == '__main__':
    main()
