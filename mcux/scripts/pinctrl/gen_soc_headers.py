#!/usr/bin/env python3
#
# Copyright 2023-2025 NXP
#
# SPDX-License-Identifier: Apache-2.0

"""
Wrapper around support libraries for i.MX RT, LPC, and Kinetis SOCs.
Allows user to generate pin control board files from MCUXpresso config
tools (MEX) files
"""
# Standard python libraries
import argparse
import tempfile
import zipfile
import pathlib
import sys
import datetime
import re

# SOC configuration data support libraries
from imx import imx_cfg_utils
from kinetis import kinetis_cfg_utils
from lpc import lpc_cfg_utils


HELPSTR = """
Processes NXP signal configuration files

Given a processor data pack, generates the SOC level pinctrl DTSI defintions
required for Zephyr. This tool is intended to be used with the configuration
data downloaded from NXP's MCUXpresso SDK builder.
"""


def parse_args():
    """
    Parses arguments, and returns object with parsed arguments
    as properties
    """
    parser = argparse.ArgumentParser(description=HELPSTR,
            formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('data_pack', metavar = 'DATA_PACK',
                        type=str,
                        help='Path to downloaded data package zip')
    parser.add_argument('--copyright', action='store_true',
                        help='Enable default NXP copyright')
    parser.add_argument('--soc-output', metavar = 'SOC_OUT', type=str,
                        help='Output directory for soc level dtsi files')
    parser.add_argument('--controller', metavar = 'CTRL', type=str,
                        help=("SOC pin controller type."
                        "Currently supports: [IOMUX, IOCON, PORT]"))

    return parser.parse_args()


def processor_to_controller(processor_name):
    """
    Returns pin controller type for processor, or None if
    processor is unknown
    """
    # Select family of pin controller based on SOC type
    if "IMXRT1" in processor_name:
        # Use IMX config tools
        return 'IOMUX'
    if "IMXRT7" in processor_name:
        # LPC config tools
        return 'IOCON'
    if "IMXRT6" in processor_name:
        # LPC config tools
        return 'IOCON'
    if "IMXRT5" in processor_name:
        # LPC config tools
        return 'IOCON'
    if "IMX8M" in processor_name:
        # IMX config tools
        return 'IOMUX'
    if "IMX9" in processor_name:
        # IMX config tools
        return 'IOMUX'
    if "LPC5" in processor_name:
        # LPC config tools
        return 'IOCON'
    if "MK" in processor_name:
        # Kinetis config tools
        return 'PORT'
    if "K32" in processor_name:
        # Kinetis config tools
        return 'PORT'
    if "MCX" in processor_name:
        # Kinetis config tools
        return 'PORT'
    # Unknown processor family
    return "UNKNOWN"

def get_pack_version(pack_dir):
    """
    Gets datapack version
    @param pack_dir: root directory data pack is in
    """
    # Check version of the config tools archive
    npi_data = pathlib.Path(pack_dir) / 'npidata.mf'
    data_version = 0.0
    with open(npi_data, 'r', encoding='UTF8') as stream:
        line = stream.readline()
        while line != '':
            match = re.search(r'data_version=([\d\.]+)', line)
            if match:
                data_version = float(match.group(1))
                break
            line = stream.readline()
    return data_version

def main():
    """
    Main entry point. Will process data pack, and generate board pin control
    headers
    """
    args = parse_args()
    if not args.soc_output:
        args.soc_output = "."
    elif not pathlib.Path(args.soc_output).is_dir():
        print('SOC output path must be a directory')
        sys.exit(255)

    # Extract the Data pack to a temporary directory
    temp_dir = tempfile.TemporaryDirectory()
    zipfile.ZipFile(args.data_pack).extractall(temp_dir.name)

    data_version = get_pack_version(temp_dir.name)
    print(f"Found data pack version {data_version}")
    if round(data_version) != 16:
        print("Warning: This tool is only verified for data pack version 16, "
            "other versions may not work")

    # Attempt to locate the signal XML files we will generate from
    proc_root = pathlib.Path(temp_dir.name) / 'processors'
    search_pattern = "*/ksdk2_0/*/signal_configuration.xml"
    # Pathlib glob returns an iteration, so use sum to count the length
    package_count = sum(1 for _ in proc_root.glob(search_pattern))
    if package_count == 0:
        search_pattern = "*/i_mx_2_0/*/signal_configuration.xml"
        package_count = sum(1 for _ in proc_root.glob(search_pattern))
        if package_count == 0:
            print("No signal configuration files were found in this data pack")
            sys.exit(255)
    if args.copyright:
        # Add default copyright
        nxp_copyright = (f"Copyright {datetime.datetime.today().year}, NXP\n"
        f" * SPDX-License-Identifier: Apache-2.0")
    else:
        nxp_copyright = ""
    for signal_xml in proc_root.glob(search_pattern):
        package_root = signal_xml.parent
        package_name = package_root.name
        if args.controller is None:
            # Determine pin controller type using SOC package name
            args.controller = processor_to_controller(package_name)
        # If controller is still unknown, error out
        if args.controller == "UNKNOWN":
            print(f"Error: package {package_name} is not currently supported by this tool")
            print("You can try specifying your pin controller family manually, "
                "but this is unsupported!")
            sys.exit(255)

        # Select correct config tool script for the signal file
        out_dir = args.soc_output.rstrip('/')
        if args.controller == 'IOMUX':
            cfg_util = imx_cfg_utils.NXPSdkUtil(str(package_root),
                                                copyright_header=nxp_copyright)
            out_path = f"{out_dir}/{cfg_util.get_part_num().lower()}-pinctrl.dtsi"
        elif args.controller == 'IOCON':
            cfg_util = lpc_cfg_utils.NXPSdkUtil(str(package_root),
                                                copyright_header=nxp_copyright)
            out_path = f"{out_dir}/{cfg_util.get_part_num().upper()}-pinctrl.h"
        elif args.controller == 'PORT':
            cfg_util = kinetis_cfg_utils.NXPSdkUtil(str(package_root),
                                                    copyright_header=nxp_copyright)
            out_path = f"{out_dir}/{cfg_util.get_part_num().upper()}-pinctrl.h"
        else:
            print("Error: unknown controller type")
            sys.exit(255)

        cfg_util.write_pinctrl_defs(out_path)
        print(f"Wrote pinctrl headers to {out_path}")


if __name__ == "__main__":
    main()
