#!/usr/bin/env python3

"""
Wrapper around imx_cfg_utils.py to provide arguments to module
"""
import argparse
import datetime
import re
import pathlib
import sys

import imx_cfg_utils


HELPSTR = """
Processes NXP iMX.RT MEX configuration files

Given a mex file, generates the board level pinctrl groups required for
Zephyr. Only supports iMX.RT parts.

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

board_name = imx_cfg_utils.get_board_name(args.mex_file)
processor_name = imx_cfg_utils.get_processor_name(args.mex_file)
package_name = imx_cfg_utils.get_package_name(args.mex_file)
soc_name = re.match(r'MIMXR?T?[0-9]+(M\w\d)*', processor_name).group(0)

# Set defaults for optional arguments
if not args.board_output:
    args.board_output = f"{board_name.lower().replace('-', '_')}-pinctrl.dtsi"
elif pathlib.Path(args.board_output).is_dir():
    # Add default name for file onto end of folder
    args.board_output = (str(pathlib.Path(args.board_output)) +
        f"/{board_name.lower().replace('-', '_')}-pinctrl.dtsi")

if not args.cfg_tool_root:
    print("configuration tool root argument ('--cfg-tool-root') is required!")
    sys.exit(1)
proc_root = pathlib.Path(args.cfg_tool_root) / processor_name / 'ksdk2_0' / package_name
if not proc_root.is_dir():
    print(f"Configuration tool root path {args.cfg_tool_root} is invalid")
    sys.exit(2)


if args.copyright:
    # Add default copyright
    COPYRIGHT = (f"Copyright (c) {datetime.datetime.today().year}, NXP\n"
    f" * SPDX-License-Identifier: Apache-2.0")
else:
    COPYRIGHT = ''
util = imx_cfg_utils.NXPSdkUtil(str(proc_root), copyright_header= COPYRIGHT)
print(f"Generating configuration for {board_name}")
util.write_pinctrl_groups(args.mex_file, args.board_output)
print(f"Wrote pinctrl dts file to {args.board_output}")
