#!/usr/bin/env python3
#
# Copyright (c) 2022, NXP
#
# SPDX-License-Identifier: Apache-2.0

"""
Wrapper around kinetis_signal2dts.py to provide arguments
"""

import datetime
import argparse
import pathlib
import sys

import kinetis_cfg_utils

HELPSTR = """
Processes NXP Kinetis MEX configuration files
Given a mex file, generates the board level pinctrl groups required for
Zephyr. Only supports Kinetis parts.
This tool is intended to be used with the configuration data downloaded
from NXP's website. One way to extract this config data is to use the
MCUXpresso configuration tool to download processor defintions, locate
those defintions on the disk. Alternatively, individual processor config
data packs can be downloaded from the MCUXpresso SDK builder tool. Either way,
the path to the 'processors' directory must be provided as the 'cfg-tool-root'
parameter.
"""

parser = argparse.ArgumentParser(description=HELPSTR,
    formatter_class=argparse.RawDescriptionHelpFormatter)

parser.add_argument('mex_file', metavar = 'MEX',
                    type=str, help='path to source MEX file')
parser.add_argument('--cfg-tool-root', metavar = 'CFG_TOOL', type=str,
                    help='Path to root of MCUXpresso processors directory')
parser.add_argument('--copyright', action='store_true',
                    help='Enable default NXP copyright')
parser.add_argument('--board-output', metavar = 'BOARD_OUT', type=str,
                    help='Output path for board level DTS file')

args = parser.parse_args()

board_name = kinetis_cfg_utils.get_board_name(args.mex_file)
processor_name = kinetis_cfg_utils.get_processor_name(args.mex_file)
package_name = kinetis_cfg_utils.get_package_name(args.mex_file)

if not args.board_output:
    args.board_output = f"{board_name.lower().replace('-', '_')}-pinctrl.dtsi"
elif pathlib.Path(args.board_output).is_dir():
    # Append board name to path
    if not args.board_output.endswith('/'):
        args.board_output += '/'
    args.board_output += f"{board_name.lower().replace('-', '_')}-pinctrl.dtsi"

if args.cfg_tool_root:
    # Attempt to locate all the required config files automatically, using
    # the processor name given in the mex file
    proc_root = pathlib.Path(args.cfg_tool_root) / processor_name / 'ksdk2_0' / package_name
    if not proc_root.exists():
        print(f"Error: Path {args.cfg_tool_root} provided for config root is invalid")
        sys.exit(255)
    # Check for all the files we need
    signal_path = proc_root / 'signal_configuration.xml'
    # Verify files exist
    if not signal_path.exists():
        print("CFG tools path appears valid, but required files could not be found")
        sys.exit(254)
    signal_file = str(signal_path)



if args.copyright:
    # Add default copyright
    copyright_txt = (f"Copyright (c) {datetime.datetime.today().year}, NXP\n"
    f" * SPDX-License-Identifier: Apache-2.0")
    util = kinetis_cfg_utils.NXPSdkUtil(signal_file, copyright_header= copyright_txt)
else:
    util = kinetis_cfg_utils.NXPSdkUtil(signal_file)

print(f"Generating configuration for {board_name}")
util.write_pinctrl_groups(args.mex_file, args.board_output)
print(f"Wrote pinctrl dts file to {args.board_output}")
