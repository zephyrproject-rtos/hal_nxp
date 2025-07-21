#/*
# * Copyright 2024 NXP
# * 
# * SPDX-License-Identifier: BSD-3-Clause
# * The BSD-3-Clause license can be found at https://spdx.org/licenses/BSD-3-Clause.html
# */

# coding=utf-8

import os.path
import subprocess
import json
import binascii
import sys
import re
import argparse
import logging
import indentlog
import datetime
import ocotp
from pathlib import Path
from shutil import copyfile
from elftools.elf.elffile import ELFFile

logger = indentlog.IndentLoggerAdapter(logging.getLogger(__name__))
invocation_time = datetime.datetime.now()

if not sys.version_info.major == 3 and sys.version_info.minor >= 8:
	logger.error("Python 3.6 or higher is required.")
	logger.error("You are using Python {}.{}.".format(sys.version_info.major, sys.version_info.minor))
	sys.exit(1)

def get_root_path(work_dir):
	work_directory = work_dir
	root_path = f"{work_directory}/{invocation_time.strftime('%Y-%m-%d-%H-%M-%S')}"
	return Path(root_path).resolve().absolute()

def setup_logging(work_dir):
	# set up logging to file - see previous section for more details
	work_dir = get_root_path(work_dir)
	work_dir.mkdir(parents=True, exist_ok=True)
	logging.basicConfig(level=logging.DEBUG,
						format='%(name)-12s %(levelname)-8s %(message)s',
						datefmt='%m-%d %H:%M',
						filename=str(work_dir.joinpath("generate.log")),
						filemode='w')
	# define a Handler which writes INFO messages or higher to the sys.stderr
	console = logging.StreamHandler()
	console.setLevel(logging.DEBUG)
	# set a format which is simpler for console use
	formatter = logging.Formatter('%(message)s')
	# tell the handler to use this format
	console.setFormatter(formatter)
	# add the handler to the root logger
	logging.getLogger('').addHandler(console)
	return work_dir

def get_artefact_base(executable):
	basename = os.path.basename(executable)
	basename_no_ext = os.path.splitext(basename)[0]
	return basename_no_ext

def create_flash_image(params):
	# Decouple the argument names from internal variable names:
	path_cpu1_fw = os.path.abspath(params.get("cpu1_fw")) if params.get("cpu1_fw") is not None else None
	path_cpu2_fw = os.path.abspath(params.get("cpu2_fw")) if params.get("cpu2_fw") is not None else None
	path_elftosb = os.path.abspath(params.get("elftosb_path")) if params.get("elftosb_path") is not None else "../tools/elftosb/elftosb.exe"
	path_output = os.path.join(os.path.dirname(path_elftosb), "workspace/output_images")
	work_dir = setup_logging(path_output)
	base = "rw610"

	# Constant for a given bootloader, perhaps not worth to make those
	# arguments as well
	cpu1_imem_dmem_offset = 0x41000000
	cpu2_imem_dmem_offset = 0x44000000
	smu0_offset = 0xa0005000

	if path_cpu1_fw is not None:
		logger.info(f"### Create cpu1 raw binary")
		i = 0
		cpu1_tmp_dir_base = os.path.join(work_dir, get_artefact_base(path_cpu1_fw))
		cpu1_tmpfile_path = f"{cpu1_tmp_dir_base}.raw.cpu1"
		cpu1_tmpfile = open(cpu1_tmpfile_path, 'wb')
		file = open(path_cpu1_fw, 'rb')
		elf_file = ELFFile(file)
		for segment in elf_file.iter_segments():
			if segment.header.p_type == 'PT_LOAD':
				if segment.header.p_filesz > 0:
					file.seek(segment.header.p_offset)
					blockData = file.read(segment.header.p_filesz)
					cpu1_tmpfile.write(bytes('bwar','utf-8'))
					cpu1_tmpfile.write(bytes([i,0,0,0]))
					address = segment.header.p_paddr
					if address < cpu1_imem_dmem_offset:
						address += cpu1_imem_dmem_offset						
					elif address >= smu0_offset:
						raise ValueError(f"Invalid load address {address}")
					address_b0 = address & 0xff
					address_b1 = (address >> 8) & 0xff
					address_b2 = (address >> 16) & 0xff
					address_b3 = (address >> 24) & 0xff
					cpu1_tmpfile.write(bytes([address_b0,address_b1,address_b2,address_b3]))
					filesize = segment.header.p_filesz
					filesize_b0 = filesize & 0xff
					filesize_b1 = (filesize >> 8) & 0xff
					filesize_b2 = (filesize >> 16) & 0xff
					filesize_b3 = (filesize >> 24) & 0xff
					cpu1_tmpfile.write(bytes([filesize_b0,filesize_b1,filesize_b2,filesize_b3]))
					cpu1_tmpfile.write(blockData)
					i += 1
		file.close()
		cpu1_tmpfile.close()

	if path_cpu2_fw is not None:
		logger.info(f"### Create cpu2 raw binary")
		i = 0
		cpu2_tmp_dir_base = os.path.join(work_dir, get_artefact_base(path_cpu2_fw))
		cpu2_tmpfile_path = f"{cpu2_tmp_dir_base}.raw.cpu2"
		cpu2_tmpfile = open(cpu2_tmpfile_path, 'wb')
		file = open(path_cpu2_fw, 'rb')
		elf_file = ELFFile(file)
		for segment in elf_file.iter_segments():
			if segment.header.p_type == 'PT_LOAD':
				if segment.header.p_filesz > 0:			
					file.seek(segment.header.p_offset)
					blockData = file.read(segment.header.p_filesz)
					cpu2_tmpfile.write(bytes('bwar','utf-8'))
					cpu2_tmpfile.write(bytes([i,0,0,0]))
					address = segment.header.p_paddr
					if address < cpu2_imem_dmem_offset:
						address += cpu2_imem_dmem_offset						
					elif address >= smu0_offset:
						raise ValueError(f"Invalid load address {address}")
					address_b0 = address & 0xff
					address_b1 = (address >> 8) & 0xff
					address_b2 = (address >> 16) & 0xff
					address_b3 = (address >> 24) & 0xff
					cpu2_tmpfile.write(bytes([address_b0,address_b1,address_b2,address_b3]))
					filesize = segment.header.p_filesz
					filesize_b0 = filesize & 0xff
					filesize_b1 = (filesize >> 8) & 0xff
					filesize_b2 = (filesize >> 16) & 0xff
					filesize_b3 = (filesize >> 24) & 0xff
					cpu2_tmpfile.write(bytes([filesize_b0,filesize_b1,filesize_b2,filesize_b3]))
					cpu2_tmpfile.write(blockData)
					i += 1
		file.close()
		cpu2_tmpfile.close()

if __name__ == "__main__":
	args_dict = {
					'cpu1_fw': 'rw610w.axf',
					'cpu2_fw': 'rw610n.axf',
					'elftosb_path': 'image_tool/elftosb/elftosb.exe'
				}

	create_flash_image(args_dict)
