#!/usr/bin/env python3

import argparse
import tempfile
import re
import os

HELPSTR = """
Fix generated pinctrl defintions
Generated i.MX RT 4-digit (RT1xxx) pinctrl definitions may be incorrect,
because the signal configuration XML file itself is not correct. Fix them
using fsl_iomuxc definitions. Only applies to parts with the IOMUXC IP;
3-digit RT parts (RT5xx/RT6xx/RT7xx) use IOCON/IOPCTL and are not affected.
"""

iomuxc_re = re.compile(r'#define (IOMUXC_[\w_]+)\s+([0x]*[\dA-F]+)[U]*, ([0x]*[\dA-F]+)[U]*,'
    r' ([0x]*[\dA-F]+)[U]*, ([0x]*[\dA-F]+)[U]*, ([0x]*[\dA-F]+)[U]*\n')

pinctrl_line1_re = re.compile(r'\t/omit-if-no-ref/ [\w_]+: ([\w_]+) {\n')
pinctrl_line2_re = re.compile(r'\t\tpinmux = <(0x[\da-f]+) '
    r'(\d+) (0x[\da-f]+) (\d+) (0x[\da-f]+)>;')


def parse_iomuxc_ground_truth(iomuxc_path):
    """
    Parse an fsl_iomuxc.h file and build a ground truth mapping.
    @param iomuxc_path: path to fsl_iomuxc.h file
    @return dict mapping (mux_reg, mux) to (name, daisy_reg, daisy, cfg_reg)
    """
    ground_truth = {}
    with open(iomuxc_path, 'r', encoding='utf8') as iomux_file:
        while True:
            line = iomux_file.readline()
            if line == '':
                break
            match = iomuxc_re.match(line)
            if match:
                mux_reg = int(match.group(2), 0)
                mux = int(match.group(3), 0)
                daisy_reg = int(match.group(4), 0)
                daisy = int(match.group(5), 0)
                cfg_reg = int(match.group(6), 0)
                if (mux_reg, mux, cfg_reg) in ground_truth:
                    raise RuntimeError("Duplicate mux_reg and mux value pairings")
                ground_truth[(mux_reg, mux)] = (match.group(1), daisy_reg, daisy, cfg_reg)
    return ground_truth


def fixup_pinctrl_file(pinctrl_path, ground_truth, check=False):
    """
    Fix daisy register values in a generated pinctrl file using ground truth
    from fsl_iomuxc.h.
    @param pinctrl_path: path to the pinctrl dtsi file to fix
    @param ground_truth: dict from parse_iomuxc_ground_truth()
    @param check: if True, only report errors without modifying the file
    @return number of errors found
    """
    error_count = 0
    with open(pinctrl_path, 'r+', encoding='utf8') as pinctrl_file:
        if not check:
            tmp = tempfile.TemporaryFile(mode='r+')
        while True:
            line = pinctrl_file.readline()
            if line == '':
                break
            if not check:
                if line == '&iomuxc {\n':
                    tmp.write('/*\n'
                        f' * NOTE: file fixup performed by {os.path.basename(__file__)}\n'
                        " * to correct missing daisy register values\n"
                        ' */\n\n')
                tmp.write(line)
            match = pinctrl_line1_re.match(line)
            if match:
                line = pinctrl_file.readline()
                match2 = pinctrl_line2_re.match(line)
                if match2:
                    mux_reg = int(match2.group(1), 0)
                    mux = int(match2.group(2), 0)
                    daisy_reg = int(match2.group(3), 0)
                    daisy = int(match2.group(4), 0)
                    cfg_reg = int(match2.group(5), 0)
                    name = match.group(1)
                    errors = False
                    if (mux_reg, mux) in ground_truth:
                        mux_truth = ground_truth[(mux_reg, mux)]
                        if mux_truth[1] != daisy_reg:
                            print(f"Bad daisy reg on {name}")
                            errors = True
                        if mux_truth[2] != daisy:
                            print(f"Bad daisy value on {name}")
                            errors = True
                        if mux_truth[3] != cfg_reg:
                            print(f"Bad cfg value on {name}")
                            errors = True
                        if errors:
                            error_count += 1
                        if (not check) and (errors):
                            new_line = (f"\t\tpinmux = <0x{mux_reg:x} {mux} "
                                f"0x{mux_truth[1]:x} {mux_truth[2]} 0x{mux_truth[3]:x}>;\n")
                            tmp.write(new_line)
                        elif not check:
                            tmp.write(line)
                    else:
                        print("WARNING: Mux name %s not preset in ground truth" % (name))
                        if not check:
                            tmp.write(line)
        if not check:
            tmp.seek(0)
            pinctrl_file.seek(0)
            while True:
                tmpline = tmp.readline()
                if tmpline == '':
                    break
                pinctrl_file.write(tmpline)
            tmp.close()
    return error_count


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=HELPSTR,
            formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('iomuxc_file', metavar = 'IOMUXC',
                        type=str,
                        help='iomuxc file to use as ground truth')
    parser.add_argument('pinctrl_file', metavar = 'pinctrl',
                        type=str,
                        help='pinctrl file to check against iomuxc file')
    parser.add_argument('--check', action='store_true',
                        help='do not edit pinctrl file, just check for errors')

    args = parser.parse_args()

    ground_truth = parse_iomuxc_ground_truth(args.iomuxc_file)
    fixup_pinctrl_file(args.pinctrl_file, ground_truth, check=args.check)
