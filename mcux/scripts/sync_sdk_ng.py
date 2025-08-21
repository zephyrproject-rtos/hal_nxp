#!/usr/bin/env python3
#
# Copyright 2025 NXP
#
# SPDX-License-Identifier: Apache-2.0

import os
import shutil
import argparse
import fnmatch
from functools import partial

def should_ignore(name):
    name_lower = name.lower()
    ignored_names = {'.git', '.gitignore', 'doc', 'docs', 'doxygen', 'Doxygen'}
    
    if name_lower in ignored_names:
        return True
    if name_lower.startswith('kconfig') or name_lower == 'kconfig':
        return True
    return False

def is_non_empty_file(file_path):
    return os.path.isfile(file_path) and os.path.getsize(file_path) > 0

def copy_filtered_files(src_dir, dest_dir, file_pattern="*", dir_ignore_func=None, file_ignore_func=None, skip_empty=True):
    os.makedirs(dest_dir, exist_ok=True)
    
    for root, dirs, files in os.walk(src_dir):
        dirs[:] = [d for d in dirs if not should_ignore(d)]
        
        if dir_ignore_func:
            dirs[:] = [d for d in dirs if not dir_ignore_func(d, root)]
        
        rel_path = os.path.relpath(root, src_dir)
        cur_dest_dir = os.path.join(dest_dir, rel_path)
        os.makedirs(cur_dest_dir, exist_ok=True)

        for file in files:
            src_file = os.path.join(root, file)
            dest_file = os.path.join(cur_dest_dir, file)
            
            if should_ignore(file):
                continue
            if file_ignore_func and file_ignore_func(file, root):
                continue
            if not fnmatch.fnmatch(file, file_pattern):
                continue
            if skip_empty and not is_non_empty_file(src_file):
                continue
                
            shutil.copy2(src_file, dest_file)

def copy_arch(src_sdk, dest_root):
    print("Copying arch...")
    arch_dirs = {
        'arm': os.path.join(src_sdk, 'arch', 'arm'),
        'xtensa': os.path.join(src_sdk, 'arch', 'xtensa')
    }
    
    for cpu_type, src_dir in arch_dirs.items():
        if not os.path.exists(src_dir):
            print(f"  Warning: Source not found - {src_dir}")
            continue
            
        dest_dir = os.path.join(dest_root, 'arch', cpu_type)
        
        def ignore_dir(dirname, parent_path):
            return dirname.lower() == "cmsis" and parent_path == src_dir
            
        copy_filtered_files(
            src_dir=src_dir,
            dest_dir=dest_dir,
            file_pattern="*.cmake",
            dir_ignore_func=ignore_dir,
            skip_empty=True
        )

def copy_drivers(src_sdk, dest_root):
    print("Copying drivers...")
    src_dir = os.path.join(src_sdk, 'drivers')
    dest_dir = os.path.join(dest_root, 'drivers')
    
    if not os.path.exists(src_dir):
        print(f"  Warning: Drivers source not found - {src_dir}")
        return

    def ignore_file(filename, _):
        return filename.endswith('template') or filename == 'template.readme'
        
    copy_filtered_files(
        src_dir=src_dir,
        dest_dir=dest_dir,
        file_ignore_func=ignore_file,
        skip_empty=True
    )

def copy_components(src_sdk, dest_root):
    print("Copying components...")
    components_map = [
        'conn_fwloader',
        'imu_adapter',
        'lists',
        'misc_utilities',
        'osa',
        'phy',
        'rpmsg',
        'wifi_bt_module',
        'flash/mflash',
        'flash/nand',
        'flash/nor'
    ]
    
    flash_header = {
        'src': os.path.join(src_sdk, 'components', 'flash', 'fsl_flash.h'),
        'dest': os.path.join(dest_root, 'components', 'flash', 'fsl_flash.h')
    }
    
    for comp_path in components_map:
        src = os.path.join(src_sdk, 'components', comp_path)
        dest = os.path.join(dest_root, 'components', comp_path)
        
        if not os.path.exists(src):
            print(f"  Warning: Component source not found - {src}")
            continue
            
        if os.path.isdir(src):
            copy_filtered_files(src, dest, skip_empty=True)
        else:
            print(f"  Warning: Component is not a directory - {src}")
    
    if os.path.isfile(flash_header['src']) and is_non_empty_file(flash_header['src']):
        os.makedirs(os.path.dirname(flash_header['dest']), exist_ok=True)
        shutil.copy2(flash_header['src'], flash_header['dest'])

def copy_middleware_usb(src_sdk, dest_root):
    print("Copying USB middleware...")
    src = os.path.join(src_sdk, 'middleware', 'usb')
    dest = os.path.join(dest_root, 'middleware', 'usb')
    
    if os.path.exists(src):
        copy_filtered_files(src, dest)
    else:
        print(f"  Warning: USB middleware source not found - {src}")

def copy_cmake_extension(src_sdk, dest_root):
    print("Copying cmake extensions...")
    src_dir = os.path.join(src_sdk, 'cmake', 'extension')
    dest_dir = os.path.join(dest_root, 'cmake', 'extension')
    files_to_copy = ['logging.cmake', 'function.cmake', 'basic_settings_lite.cmake']
    
    for file in files_to_copy:
        src_file = os.path.join(src_dir, file)
        if os.path.isfile(src_file) and is_non_empty_file(src_file):
            os.makedirs(dest_dir, exist_ok=True)
            shutil.copy2(src_file, os.path.join(dest_dir, file))
        else:
            print(f"  Warning: CMake file not found - {src_file}")

def copy_device_family(family, src_sdk, dest_root):
    print(f"Copying devices: {family}...")
    src_dir = os.path.join(src_sdk, 'devices', family)
    dest_dir = os.path.join(dest_root, 'devices', family)
    
    if not os.path.exists(src_dir):
        print(f"  Warning: Device family source not found - {src_dir}")
        return
    
    def family_ignore_dir(dirname, parent_path):
        return dirname.lower() in ['mcuxpresso', 'iar', 'arm', 'gcc', 'llvm', 'xtensa', 'doxygen']
        
    def family_ignore_file(filename, parent_path):
        ignore_exts = ['.yml', '.icf', '.ld', '.scf', '.flm', '.sdf', '.dbgconf']
        ignore_names = ['RTE_Device.h', 'startup.s', 'startup.S', 'prj.conf']
        
        if any(filename.lower().endswith(ext) for ext in ignore_exts):
            return True
        
        if filename in ignore_names:
            return True
            
        return False
        
    copy_filtered_files(
        src_dir=src_dir,
        dest_dir=dest_dir,
        dir_ignore_func=family_ignore_dir,
        file_ignore_func=family_ignore_file,
        skip_empty=True
    )

def copy_device_arch(src_sdk, dest_root):
    print("Copying device architecture...")
    for arch_type in ['arm', 'xtensa']:
        src = os.path.join(src_sdk, 'devices', arch_type)
        dest = os.path.join(dest_root, 'devices', arch_type)
        if os.path.exists(src):
            copy_filtered_files(src, dest, skip_empty=True)
        else:
            print(f"  Warning: Device arch source not found - {src}")

def main():
    parser = argparse.ArgumentParser(description='MCUx SDK SYNC TOOL')
    parser.add_argument('--mcuxsdk_dir', required=True, help='mcux sdk source dir')
    parser.add_argument('--copy_module', nargs='*', choices=[
        'arch', 'drivers', 'components',
        'middleware/usb', 'devices/arch', 'devices/i.MX',
        'devices/Kinetis', 'devices/LPC', 'devices/MCX',
        'devices/RT', 'devices/Wireless', 'cmake_extension'
    ], help='Please select the module to copy (default sync all modules)')
    
    args = parser.parse_args()
    
    script_dir = os.path.dirname(os.path.abspath(__file__))
    dest_root = os.path.join(script_dir, '..', 'mcux-sdk-ng')
    os.makedirs(dest_root, exist_ok=True)
    
    all_modules = [
        'arch', 'drivers', 'components',
        'middleware/usb', 'devices/arch', 'devices/i.MX',
        'devices/Kinetis', 'devices/LPC', 'devices/MCX',
        'devices/RT', 'devices/Wireless', 'cmake_extension'
    ]
    
    selected_modules = args.copy_module if args.copy_module else all_modules
    print(f"Selected modules: {', '.join(selected_modules)}")
    
    module_actions = {
        'arch': copy_arch,
        'drivers': copy_drivers,
        'components': copy_components,
        'middleware/usb': copy_middleware_usb,
        'cmake_extension': copy_cmake_extension,
        'devices/arch': copy_device_arch,
        'devices/i.MX': partial(copy_device_family, 'i.MX'),
        'devices/Kinetis': partial(copy_device_family, 'Kinetis'),
        'devices/LPC': partial(copy_device_family, 'LPC'),
        'devices/MCX': partial(copy_device_family, 'MCX'),
        'devices/RT': partial(copy_device_family, 'RT'),
        'devices/Wireless': partial(copy_device_family, 'Wireless')
    }
    
    for module in selected_modules:
        if module not in module_actions:
            print(f"  Warning: Unknown module '{module}', skipping...")
            continue
            
        try:
            action = module_actions[module]
            action(args.mcuxsdk_dir, dest_root)
        except Exception as e:
            print(f"  Error during copying {module}: {str(e)}")
        
    print("Copy complete!")

if __name__ == "__main__":
    main()
