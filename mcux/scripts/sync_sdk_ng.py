#!/usr/bin/env python3
#
# Copyright 2025 NXP
#
# SPDX-License-Identifier: Apache-2.0

import os
import sys
import shutil
import argparse
import re
from datetime import datetime

# Global variables
LOG_FILE = None
SOURCE_DIR = None
TARGET_DIR = None
LOG_OUTPUT_DIR = os.path.dirname(os.path.abspath(__file__))

class Tee:
    def __init__(self, *files):
        self.files = files
        
    def write(self, text):
        for f in self.files:
            if f == sys.stdout:
                f.write(text)
                f.flush()
            else:
                f.write(text)
    
    def flush(self):
        for f in self.files:
            f.flush()

def init_logging():
    global LOG_FILE
    log_filepath = os.path.join(LOG_OUTPUT_DIR, 'sync_log.txt')
    try:
        LOG_FILE = open(log_filepath, 'w')
        sys.stdout = Tee(sys.stdout, LOG_FILE)
        print(f"Log initialized at {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    except Exception as e:
        print(f"❌ Error initializing log: {str(e)}")
        raise

def should_ignore(path):
    ignore_dirs = ['.git', '.gitignore', 'doc', 'docs', 'doxygen', 'Doxygen']
    if os.path.basename(path) in ignore_dirs:
        return True
    if re.search(r'Kconfig(\.|\b)', os.path.basename(path), re.IGNORECASE):
        return True
    return False

def copy_arch_files(src_dir, dest_dir):
    print(f"\n=== Copying arch files from {src_dir} to {dest_dir} ===")
    if not os.path.exists(src_dir):
        print(f"⚠️ Source directory not found: {src_dir}")
        return
    os.makedirs(dest_dir, exist_ok=True)
    
    for root, dirs, files in os.walk(src_dir):
        # Skip CMSIS directory
        if 'CMSIS' in root.split(os.sep):
            continue
            
        for f in files:
            if not should_ignore(f) and f.endswith('.cmake'):
                src_file = os.path.join(root, f)
                rel_path = os.path.relpath(root, src_dir)
                dest_path = os.path.join(dest_dir, rel_path, f)
                os.makedirs(os.path.dirname(dest_path), exist_ok=True)
                shutil.copy2(src_file, dest_path)
                print(f"Coped: {src_file} --> {dest_path}")

def copy_drivers(src_dir, dest_dir):
    print(f"\n=== Copying drivers from {src_dir} to {dest_dir} ===")
    copy_with_ignore(src_dir, dest_dir)

def copy_components(src_dir, dest_dir):
    print(f"\n=== Copying components from {src_dir} to {dest_dir} ===")
    modules = [
        'conn_fwloader', 'imu_adapter', 'lists', 'misc_utilities', 
        'osa', 'phy', 'rpmsg', 'wifi_bt_module'
    ]
    
    # Copy standard modules
    for module in modules:
        src = os.path.join(src_dir, module)
        dest = os.path.join(dest_dir, module)
        if not os.path.exists(src):
            print(f"Skipping missing component: {src}")
            continue
        copy_with_ignore(src, dest)
    
    # Handle flash folder
    flash_src = os.path.join(src_dir, 'flash')
    flash_dest = os.path.join(dest_dir, 'flash')
    
    # Special flash sub-folders to copy
    flash_subs = ['mflash', 'nand', 'nor']
    for sub in flash_subs:
        src = os.path.join(flash_src, sub)
        dest = os.path.join(flash_dest, sub)
        if not os.path.exists(src):
            print(f"Skipping flash subfolder: {src}")
            continue
        copy_with_ignore(src, dest)
    
    # Copy fsl_flash.h
    fsl_file = os.path.join(flash_src, 'fsl_flash.h')
    os.makedirs(flash_dest, exist_ok=True)
    if os.path.exists(fsl_file):
        shutil.copy2(fsl_file, os.path.join(flash_dest, 'fsl_flash.h'))
        print(f"Coped: {fsl_file} --> {flash_dest}/fsl_flash.h")
    else:
        print(f"⚠️ Flash header missing: {fsl_file}")

def copy_usb_middleware(src_dir, dest_dir):
    print(f"\n=== Copying USB middleware from {src_dir} to {dest_dir} ===")
    copy_with_ignore(src_dir, dest_dir)

def copy_cmake_extensions(src_dir, dest_dir):
    print(f"\n=== Copying CMake extensions from {src_dir} to {dest_dir} ===")
    if not os.path.exists(src_dir):
        print(f"⚠️ Source directory not found: {src_dir}")
        return
        
    os.makedirs(dest_dir, exist_ok=True)
    files_to_copy = [
        'logging.cmake', 
        'function.cmake', 
        'basic_settings_lite.cmake'
    ]
    
    for f in files_to_copy:
        src_file = os.path.join(src_dir, f)
        if not os.path.exists(src_file):
            print(f"Missing file: {f}")
            continue
        shutil.copy2(src_file, dest_dir)
        print(f"Coped: {src_file} --> {dest_dir}/{f}")

def copy_and_clean_device(src_device_dir, dest_device_dir, clean_files=True):
    print(f"\n=== Copying device {os.path.basename(src_device_dir)} to {dest_device_dir} ===")
    try:
        # Copy entire directory
        copy_with_ignore(src_device_dir, dest_device_dir)
        
        if clean_files:
            clean_device_directory(dest_device_dir)
    except Exception as e:
        print(f"❌ Error copying device: {str(e)}")

def clean_device_directory(dest_dir):
    print(f"Cleaning device directory: {dest_dir}")
    
    patterns_to_delete = {
        'files': [
            'RTE_Device.h',
            'prj.conf',
            r'.*\.yml$', r'.*\.icf$', r'.*\.ld$', 
            r'.*\.scf$', r'.*\.FLM$', r'.*\.sdf$', 
            r'.*\.dbgconf$', 'startup.s', 'startup.S'
        ],
        'dirs': ['mcuxpresso', 'doxygen', 'Doxygen']
    }
    
    for root, dirs, files in os.walk(dest_dir, topdown=False):
        # Delete matching files
        for f in files:
            if any(
                re.match(pattern, f) or f == pattern 
                for pattern in patterns_to_delete['files']
            ):
                file_path = os.path.join(root, f)
                os.remove(file_path)
                print(f"Deleted: {file_path}")
        
        # Delete matching directories
        for d in dirs:
            if any(
                re.match(pattern, d) or d == pattern 
                for pattern in patterns_to_delete['dirs']
            ):
                dir_path = os.path.join(root, d)
                shutil.rmtree(dir_path)
                print(f"Deleted directory: {dir_path}")

def copy_boards_files():
    print(f"\n=== Copying boards files from MCUX SDK to {TARGET_DIR}/boards ===")
    
    # Define boards with their respective source paths and copy rules
    boards_config = [
        # (board_name, source_dir_type, dirs_to_copy, files_to_copy)
        ("evkbimxrt1050", "examples", ["xip"], ["dcd.c", "dcd.h"]),
        ("evkbmimxrt1060", "examples", ["xip"], ["dcd.c", "dcd.h"]),
        ("evkbmimxrt1170", "examples", ["xip"], ["dcd.c", "dcd.h", "xmcd.c", "xmcd.h"]),
        ("evkcmimxrt1060", "examples", ["xip"], []),
        ("evkmimxrt595", "examples", ["flash_config"], []),
        ("evkmimxrt685", "examples", ["flash_config"], []),
        ("evkmimxrt1010", "examples", ["xip"], []),
        ("evkmimxrt1015", "examples", ["xip"], []),
        ("evkmimxrt1020", "examples", ["xip"], ["dcd.c", "dcd.h"]),
        ("evkmimxrt1024", "examples", ["xip"], ["dcd.c", "dcd.h"]),
        ("evkmimxrt1040", "examples", ["xip"], ["dcd.c", "dcd.h"]),
        ("evkmimxrt1060", "examples_int", ["xip"], ["dcd.c", "dcd.h"]),
        ("evkmimxrt1064", "examples", ["xip"], ["dcd.c", "dcd.h"]),
        ("evkmimxrt1160", "examples", ["xip"], ["dcd.c", "dcd.h"]),
        ("evkmimxrt1170", "examples_int", ["xip"], ["dcd.c", "dcd.h", "xmcd.c", "xmcd.h"]),
        ("evkmimxrt1180", "examples", ["xip", "jlinkscript"], []),
        ("frdmmcxn947", "examples", ["xip"], []),
        ("mcxn9xxevk", "examples", ["xip"], []),
        ("mimxrt700evk", "examples", ["flash_config"], [])
    ]
    
    # Defining source directory mappings
    src_base_dirs = {
        "examples": os.path.join(SOURCE_DIR, "examples", "_boards"),
        "examples_int": os.path.join(SOURCE_DIR, "examples_int", "_boards")
    }
    
    total_copied = 0
    
    for board, src_type, dirs_to_copy, files_to_copy in boards_config:
        # Determine source path based on board type
        if src_type not in src_base_dirs:
            print(f"⚠️ Unknown source type '{src_type}' for board: {board}")
            continue
            
        src_board_path = os.path.join(src_base_dirs[src_type], board)
        dest_board_path = os.path.join(TARGET_DIR, "boards", board)
        
        if not os.path.exists(src_board_path):
            print(f"⚠️ Board source directory does not exist: {src_board_path}")
            continue
            
        # Create destination folder for this board
        os.makedirs(dest_board_path, exist_ok=True)
        board_copied = False
        
        # Copy directories
        for dir_name in dirs_to_copy:
            src_dir = os.path.join(src_board_path, dir_name)
            dest_dir = os.path.join(dest_board_path, dir_name)
            
            if not os.path.exists(src_dir):
                print(f"⚠️ Directory not found: {src_dir}")
                continue
                
            if copy_with_ignore(src_dir, dest_dir):
                board_copied = True
                total_copied += 1
                print(f"Coped directory: {src_dir} -> {dest_dir}")
        
        # Copy files
        for file_name in files_to_copy:
            src_file = os.path.join(src_board_path, file_name)
            dest_file = os.path.join(dest_board_path, file_name)
            
            if not os.path.exists(src_file):
                print(f"⚠️ File not found: {src_file}")
                continue
                
            if copy_with_ignore(src_file, dest_file):
                board_copied = True
                total_copied += 1
    
    print(f"Finished processing boards: copied {total_copied} items")

def copy_with_ignore(src, dst):
    if not os.path.exists(src):
        print(f"⚠️ Source path does not exist: {src}")
        return False
        
    # Create destination directory if necessary
    if os.path.isdir(src):
        os.makedirs(dst, exist_ok=True)
    else:
        os.makedirs(os.path.dirname(dst), exist_ok=True)
    
    # Skip if we need to ignore this path
    if should_ignore(os.path.basename(src)):
        print(f"Ignoring: {src}")
        return False
        
    # For directories, we need to copy recursively
    if os.path.isdir(src):
        try:
            # Copy using shutil.copytree with custom ignore function
            ignore_func = lambda d, names: [n for n in names if should_ignore(n)]
            shutil.copytree(src, dst, ignore=ignore_func, dirs_exist_ok=True)
            print(f"Copied directory: {src} -> {dst}")
            return True
        except Exception as e:
            print(f"❌ Error copying directory: {src} -> {dst} ({str(e)})")
            return False
    else:
        try:
            shutil.copy2(src, dst)
            print(f"Copied file: {src} -> {dst}")
            return True
        except Exception as e:
            print(f"❌ Error copying file: {src} -> {dst} ({str(e)})")
            return False

def process_modules(modules):
    mapping = {
        'arch': lambda: copy_arch_files(os.path.join(SOURCE_DIR, 'arch'), 
                                        os.path.join(TARGET_DIR, 'arch')),
        'driver': lambda: copy_drivers(os.path.join(SOURCE_DIR, 'drivers'), 
                                       os.path.join(TARGET_DIR, 'drivers')),
        'components': lambda: copy_components(os.path.join(SOURCE_DIR, 'components'), 
                                             os.path.join(TARGET_DIR, 'components')),
        'middleware/usb': lambda: copy_usb_middleware(os.path.join(SOURCE_DIR, 'middleware', 'usb'), 
                                                      os.path.join(TARGET_DIR, 'middleware', 'usb')),
        'cmake': lambda: copy_cmake_extensions(os.path.join(SOURCE_DIR, 'cmake', 'extension'), 
                                               os.path.join(TARGET_DIR, 'cmake', 'extension')),
        'boards': lambda: copy_boards_files(),
        'devices/i.MX': lambda: copy_and_clean_device(os.path.join(SOURCE_DIR, 'devices', 'i.MX'), 
                                                      os.path.join(TARGET_DIR, 'devices', 'i.MX')),
        'devices/Kinetis': lambda: copy_and_clean_device(os.path.join(SOURCE_DIR, 'devices', 'Kinetis'), 
                                                         os.path.join(TARGET_DIR, 'devices', 'Kinetis')),
        'devices/LPC': lambda: copy_and_clean_device(os.path.join(SOURCE_DIR, 'devices', 'LPC'), 
                                                     os.path.join(TARGET_DIR, 'devices', 'LPC')),
        'devices/MCX': lambda: copy_and_clean_device(os.path.join(SOURCE_DIR, 'devices', 'MCX'), 
                                                     os.path.join(TARGET_DIR, 'devices', 'MCX')),
        'devices/RT': lambda: copy_and_clean_device(os.path.join(SOURCE_DIR, 'devices', 'RT'), 
                                                    os.path.join(TARGET_DIR, 'devices', 'RT')),
        'devices/Wireless': lambda: copy_and_clean_device(os.path.join(SOURCE_DIR, 'devices', 'Wireless'), 
                                                          os.path.join(TARGET_DIR, 'devices', 'Wireless')),
        'devices/arm': lambda: copy_and_clean_device(os.path.join(SOURCE_DIR, 'devices', 'arm'), 
                                                     os.path.join(TARGET_DIR, 'devices', 'arm'), 
                                                     clean_files=False),
        'devices/xtensa': lambda: copy_and_clean_device(os.path.join(SOURCE_DIR, 'devices', 'xtensa'), 
                                                        os.path.join(TARGET_DIR, 'devices', 'xtensa'), 
                                                        clean_files=False)
    }
    
    for module in modules:
        if not module:
            continue
        module = module.strip()
        if module in mapping:
            print(f"\n{'='*60}")
            print(f"Processing module: {module}")
            print(f"{'='*60}")
            mapping[module]()
        else:
            print(f"\n⚠️ Unknown module: {module}")

def main():
    global SOURCE_DIR, TARGET_DIR, LOG_OUTPUT_DIR
    
    parser = argparse.ArgumentParser(description='MCUX SDK Sync Tool')
    parser.add_argument('--mcuxsdk_dir', required=True, help='Source MCUX SDK directory')
    parser.add_argument('--log_output_dir', help='Directory for log output')
    parser.add_argument('--copy_module', default='all', 
                        help='Comma-separated list of modules to copy (default: all)')
    
    args = parser.parse_args()
    
    # Set directories
    SOURCE_DIR = args.mcuxsdk_dir
    if args.log_output_dir:
        LOG_OUTPUT_DIR = args.log_output_dir
    
    script_dir = os.path.dirname(os.path.abspath(__file__))
    TARGET_DIR = os.path.join(script_dir, os.path.pardir, 'mcux-sdk-ng')
    TARGET_DIR = os.path.normpath(TARGET_DIR)
    
    os.makedirs(LOG_OUTPUT_DIR, exist_ok=True)
    
    # Initialize logging before any prints
    try:
        init_logging()
    except:
        sys.exit(1)
    
    # Verify source directory
    if not os.path.exists(SOURCE_DIR):
        print(f"❌ Error: Source directory does not exist: {SOURCE_DIR}")
        sys.exit(1)
    
    # Create target directory if needed
    os.makedirs(TARGET_DIR, exist_ok=True)
    
    print(f"MCUX SDK Sync Tool")
    print(f"==================================================")
    print(f"Source Directory: {SOURCE_DIR}")
    print(f"Target Directory: {TARGET_DIR}")
    print(f"Log Directory:    {LOG_OUTPUT_DIR}")
    
    # Determine modules to process
    if args.copy_module.strip().lower() == 'all':
        modules = [
            'arch', 'driver', 'components', 'middleware/usb', 'cmake', 'boards',
            'devices/i.MX', 'devices/Kinetis', 'devices/LPC', 
            'devices/MCX', 'devices/RT', 'devices/Wireless',
            'devices/arm', 'devices/xtensa'
        ]
    else:
        modules = [mod.strip() for mod in args.copy_module.split(',')]
    
    print(f"Modules to copy:  {', '.join(modules)}")
    print(f"Start Time:       {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    print(f"==================================================\n")
    
    # Process specified modules
    try:
        process_modules(modules)
        print("\nSync completed successfully!")
    except Exception as e:
        print(f"\n❌ Sync failed with error: {str(e)}")
    finally:
        if LOG_FILE:
            LOG_FILE.close()
            sys.stdout = sys.__stdout__
            print(f"\nLog file saved to: {os.path.join(LOG_OUTPUT_DIR, 'sync_log.txt')}")

if __name__ == "__main__":
    main()
