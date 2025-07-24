#/*
# * Copyright 2024 NXP
# * 
# * SPDX-License-Identifier: BSD-3-Clause
# * The BSD-3-Clause license can be found at https://spdx.org/licenses/BSD-3-Clause.html
# */

import collections
import xml.etree.ElementTree as ET
import argparse
import os
import io
from enum import Enum
import sys
import logging
import indentlog

logger = indentlog.IndentLoggerAdapter(logging.getLogger(__name__))

# Input
#
# <fusemap>
#	<layout physical_words="512" word_width="4" line_width="8" ecc_words="408" non_ecc_words="2" banks="4"/>
#	<fuseword pos="0" type="MODE_ECC" data="0x12345678" />
#	<fuseword pos="1" type="MODE_ECC" data="0x12345678" />
#	<fuseword pos="2" type="MODE_ECC" data="0x12345678" />
#	<fuseword pos="3" type="MODE_ECC" data="0x00000000" />
#	<fuseword pos="4" type="MODE_ECC" data="0xFFFFFFFF" />
#	<fuseword pos="5" type="MODE_REDUND" data="0x1234" />
# </fusemap>
#
# Output
# 010001001000110100010101100111100000010010001101000101011001111000x // 0x1234567812345678
# 01000100100011010001010110011110000000000000000000000000000000000x0 // 0x1234567800000000
# 0111111111111111111111111111111111000100100011010000010010001101x00 // 0xffffffff12341234
# 010000000000000000000000000000000000000000000000000000000000000x000 // 0x0
# 01000000000000000000000000000000000000000000000000000000000000x0000 // 0x0
# ...
#

class WordType(Enum):
    MODE_REDUND = 0
    MODE_NONE = 1
    MODE_ECC = 2


# Structures
FuseWord = collections.namedtuple('FuseWord', 'pos type data')
FuseMap = collections.namedtuple('FuseMap', 'physical_words word_width line_width ecc_words non_ecc_words banks shadow')


def parse_xml(xmlfile):
    tree = ET.parse(xmlfile)
    root = tree.getroot()

    data = []
    for fuseword in root.findall('./fuseword'):
        data.append(int(fuseword.attrib['data'], 16))
    print_rodata(data)

    layout = root.find('./layout')
    physical_words = int(layout.attrib['physical_words'])
    word_width = int(layout.attrib['word_width'])
    line_width = int(layout.attrib['line_width'])
    ecc_words = int(layout.attrib['ecc_words'])
    non_ecc_words = int(layout.attrib['non_ecc_words'])
    banks = int(layout.attrib['banks'])
    shadow = [0] * physical_words * word_width

    fm = FuseMap(physical_words,
                 word_width,
                 line_width,
                 ecc_words,
                 non_ecc_words,
                 banks,
                 shadow)

    assert len(fm.shadow) == fm.physical_words * fm.word_width

    for fuseword in root.findall('./fuseword'):
        pos = int(fuseword.attrib['pos'])
        word_type = WordType[fuseword.attrib['type']]
        data = int(fuseword.attrib['data'], 16)
        fw = FuseWord(pos, word_type, data)
        add_fuse_word(fm, fw)
    return fm


def xor(w, r):
    p = 0
    for i in r:
        p ^= bit(w, i)
    return p


def bit(w, p):
    return w >> p & 1


def calculate_ecc(w):
    ep6 = xor(w, [31, 29, 25, 24, 21, 20, 16, 13, 12, 11, 10, 9, 4, 3, 1, 0])
    ep5 = xor(w, [31, 30, 29, 28, 25, 23, 21, 19, 16, 15, 13, 8, 4, 2, 1])
    ep4 = xor(w, [31, 27, 25, 23, 22, 21, 20, 19, 18, 16, 14, 13, 12, 8, 7, 4, 3, 2, 0])
    ep3 = xor(w, [31, 29, 28, 26, 25, 24, 23, 22, 20, 18, 17, 16, 12, 11, 8, 7, 6, 4, 3])
    ep2 = xor(w, [30, 28, 27, 25, 24, 23, 22, 21, 19, 17, 16, 15, 11, 10, 7, 6, 5, 3, 2])
    ep1 = xor(w, [29, 27, 26, 24, 23, 22, 21, 20, 18, 16, 15, 14, 10, 9, 6, 5, 4, 2, 1])
    ep0 = xor(w, [31, 30, 29, 26, 24, 22, 20, 17, 16, 14, 9, 5, 3, 2, 0])
    return (ep6 << 6) | (ep5 << 5) | (ep4 << 4) | (ep3 << 3) | (ep2 << 2) | (ep1 << 1) | (ep0 << 0)


def write_fuse_files():
    print("write")


def int2bin(x, width):
    hex2bin_map = {
        "0": "0000",
        "1": "0001",
        "2": "0010",
        "3": "0011",
        "4": "0100",
        "5": "0101",
        "6": "0110",
        "7": "0111",
        "8": "1000",
        "9": "1001",
        "A": "1010",
        "B": "1011",
        "C": "1100",
        "D": "1101",
        "E": "1110",
        "F": "1111",
    }
    hex_num = '{0:0{1}X}'.format(x, width * 2)
    return "".join(hex2bin_map[i] for i in hex_num)


def convert64bit2otpline(x, pos):
    bin_str = int2bin(x, 8)
    assert len(bin_str) == 64
    return '01' + bin_str[:pos] + 'x' + bin_str[pos:] + ' // 0x{0:0{1}x}'.format(x, 16)


def get_data_pos(fw, fm):
    if fw.pos % 2 == 0:
        data_pos = (fw.pos * fm.word_width) + fm.word_width
    else:
        data_pos = (fw.pos * fm.word_width) - fm.word_width
    return data_pos


def get_ecc_pos(fw, fm):
    ecc_region_offset = int(((fm.ecc_words + fm.non_ecc_words) * fm.word_width + fw.pos) / 8) * 8
    pos = fw.pos % 8
    if pos == 7:
        return ecc_region_offset + 0
    elif pos == 6:
        return ecc_region_offset + 1
    elif pos == 5:
        return ecc_region_offset + 2
    elif pos == 4:
        return ecc_region_offset + 3
    elif pos == 3:
        return ecc_region_offset + 4
    elif pos == 2:
        return ecc_region_offset + 5
    elif pos == 1:
        return ecc_region_offset + 6
    elif pos == 0:
        return ecc_region_offset + 7

def create_otp_backgrounds(fusemap_xml_filename, out_filename):
    fm = parse_xml(fusemap_xml_filename)
    write_fuse_words(fm, os.path.abspath(out_filename))
    logger.info("Generation of OTP fusemap background files complete!")

def add_fuse_word(fm, fw):
    if fw.type is WordType.MODE_REDUND:
        data = fw.data.to_bytes(2, 'big')
        word = data + data
        data_pos = get_data_pos(fw, fm)
        fm.shadow[data_pos:data_pos + fm.word_width] = word
        assert len(fm.shadow) == fm.physical_words * fm.word_width
    elif fw.type is WordType.MODE_ECC:
        word = fw.data.to_bytes(4, 'big')
        assert len(word) == 4
        ecc = calculate_ecc(fw.data)
        data_pos = get_data_pos(fw, fm)
        ecc_pos = get_ecc_pos(fw, fm)
        fm.shadow[data_pos:data_pos + fm.word_width] = word
        assert len(fm.shadow) == fm.physical_words * fm.word_width
        fm.shadow[ecc_pos] = ecc
        assert len(fm.shadow) == fm.physical_words * fm.word_width


def print_fuse_words(fm):
    for i in range(int(len(fm.shadow) / fm.line_width)):
        spos = i * fm.line_width
        epos = (i + 1) * fm.line_width
        line_raw = fm.shadow[spos:epos]
        assert len(line_raw) == fm.line_width
        line_int = int.from_bytes(line_raw, 'big', signed=False)
        bit_length = (fm.line_width * 8)
        print(convert64bit2otpline(line_int, bit_length - i % bit_length))


def write_fuse_words(fm, filename):
    for bank in range(fm.banks):
        f = io.open(filename + str(bank) + '.bin', 'w', newline='\n')

        tot_lines = int(len(fm.shadow) / fm.line_width)
        lines_per_bank = int(tot_lines / fm.banks)

        for i in range(bank * lines_per_bank, (bank + 1) * lines_per_bank):
            spos = i * fm.line_width
            epos = (i + 1) * fm.line_width
            line_raw = fm.shadow[spos:epos]
            assert len(line_raw) == fm.line_width
            line_int = int.from_bytes(line_raw, 'big', signed=False)
            bit_length = (fm.line_width * 8)
            f.write(convert64bit2otpline(line_int, bit_length - i % bit_length) + '\n')
        f.close()


def print_rodata(data):
    xml_file = open("fake_otp_rodata.h", "w")
    xml_file.write("const uint32_t otp[FUSEMAP_SIZE] = {")
    for i in range(len(data)):
        if ((i % 8) == 0):
            xml_file.write("\n    /*  %03d */ " % ((i / 8) * 8))
        xml_file.write("0x%08X, " % (data[i]))
    xml_file.write("\n};\n")
    xml_file.close
    logger.info("Generating fake OTP rodata array complete.")


def main():
    logging.basicConfig(level=logging.INFO, format='%(message)s')

    help_message = \
        """Generates OTP backgrounds. Usage options:
        (1) Provide directly XML file which will be used to generate OPT backgrounds.
            ex: python ocotp.py --xml file_name.xml --out filename
        Info: Latest Fusemap xlsx file can be found under -
            [https://nww.amec.sharepoint.nxp.com/sites/wirelessce/programs/RedfinchMW400/Shared%20Documents/Security/OCOTP?csf=1]"""

    parser = argparse.ArgumentParser(description=help_message)

    parser.add_argument('--xml', dest='xml', required=True,
                        help='path to the fusemap XML file')

    parser.add_argument('--out', dest='out', required=True,
                        help='filename of OTP output file(s).')
    try:
        args = parser.parse_args()
    except SystemExit:
        print(help_message)
        sys.exit(-1)

    fusemap_xml_filename = args.xml

    fm = parse_xml(fusemap_xml_filename)
    write_fuse_words(fm, os.path.abspath(args.out))
    logger.info("Generation of OTP fusemap background files complete!")

if __name__ == "__main__":
    main()
