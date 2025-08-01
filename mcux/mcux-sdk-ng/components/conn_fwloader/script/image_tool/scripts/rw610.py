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
import shutil
from pathlib import Path
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

def get_artefact_path(executable, ext):
	dirname = os.path.dirname(executable)
	basename = os.path.basename(executable)
	basename_no_ext = os.path.splitext(basename)[0]
	return os.path.join(dirname, basename_no_ext + "_" + ext)

def get_artefact_base(executable):
	basename = os.path.basename(executable)
	basename_no_ext = os.path.splitext(basename)[0]
	return basename_no_ext

def copy_image_to_root_path(pathSrc, pathDst):
	shutil.copy(pathSrc, pathDst)

def hexstring(lines):
	result = ""
	for line in lines:
		line = line.strip()
		line = re.sub(r"//.*?$", "", line)
		line = re.sub(re.compile(r"\s+"), "", line)
		result += line
	return result

def extend_hex_str(hex_str):
	str_1_zero = '0'
	str_2_zero = '00'
	str_3_zero = '000'
	str_4_zero = '0000'
	str_5_zero = '00000'
	str_6_zero = '000000'
	str_7_zero = '0000000'
	if len(hex_str) == 3:
		str_list = list(hex_str)
		str_list.insert(2, str_7_zero)
	elif len(hex_str) == 4:
		str_list = list(hex_str)
		str_list.insert(2, str_6_zero)
	elif len(hex_str) == 5:
		str_list = list(hex_str)
		str_list.insert(2, str_5_zero)
	elif len(hex_str) == 6:
		str_list = list(hex_str)
		str_list.insert(2, str_4_zero)
	elif len(hex_str) == 7:
		str_list = list(hex_str)
		str_list.insert(2, str_3_zero)
	elif len(hex_str) == 8:
		str_list = list(hex_str)
		str_list.insert(2, str_2_zero)
	elif len(hex_str) == 9:
		str_list = list(hex_str)
		str_list.insert(2, str_1_zero)
	elif len(hex_str) == 10:
		str_list = list(hex_str)
	else:
		raise ValueError(f"Invalid hex_str input {hex_str}")
	hex_str = ''.join(str_list)	
	return hex_str

def read_hex_file(filename):
	with open(filename, "r") as fp:
		lines = fp.readlines()
	h = hexstring(lines)
	b = binascii.unhexlify(h)
	return b


def write_hex_file(filename, contents):
	with open(filename, 'w') as fp:
		remaining = len(contents)
		pos = 0
		while remaining > 0:
			block_size = min(16, remaining)
			block = contents[pos:pos + block_size]
			fp.write(binascii.hexlify(block, ' ').decode('ascii'))
			fp.write("\n")
			pos += block_size
			remaining -= block_size

def combine_sections(sections):
	image = b""
	for (key, section) in sorted(sections.items(), key=lambda kv: (kv[1]['start_addr'], kv[1]['start_addr'])):
		if len(image) > section['start_addr']:
			raise ValueError(f"Overlapping sections for section {key} with start address 0x{section['start_addr']:x}")
		required_len = section['start_addr']
		if len(image) < required_len:
			image += b"\xFF" * (required_len - len(image))
		image += section['data']
	return image

def get_fw_config(config_file_path):
	with open(config_file_path, "r") as fp:
		lines = fp.readlines()
	return lines

def parse_image_config(config, work_dir, path_elftosb):
	# Constant for loader
	cpu1_imem_dmem_offset = 0x41000000
	cpu2_imem_dmem_offset = 0x44000000
	smu0_offset           = 0xa0005000
	base = "rw610"
	path_image_conf = config['config_path']
	pathDst = os.path.abspath('')
	with open(path_image_conf, "r") as fp:
		image_config = json.load(fp)
		path_fw = image_config["fw_elf"]
		if "image_version" in image_config.keys():
			fw_version = image_config["image_version"]
		else:
			#print("Image_version not provided! Defalut 0 is used.")
			fw_version = 0
		fw_version = extend_hex_str(hex(fw_version))
		fw_type_raw = image_config["image_type_raw"]
		image_partition_a = image_config["image_partition_a"]
		target_cpu1 = image_config["target_cpu1"]
		target_ble = image_config["target_ble"]
		target_ble_audio = image_config["target_ble_audio"]
		target_ble_15_4_combo = image_config["target_ble_15_4_combo"]
	if fw_type_raw is True:
		fw_type_raw_byte = "0x01"
	else:
		fw_type_raw_byte = "0x00"
	if image_partition_a is True:
		image_partition_a_byte = "0x01"
	else:
		image_partition_a_byte = "0x00"
	if target_cpu1 is True:
		target_cpu1_byte = "0x01"
	else:
		target_cpu1_byte = "0x00"
	if target_ble is True:
		target_ble_byte = "0x01"
	else:
		target_ble_byte = "0x00"
	if target_ble_audio is True:
		target_ble_audio_byte = "0x01"
	else:
		target_ble_audio_byte = "0x00"
	if target_ble_15_4_combo is True:
		target_ble_15_4_combo_byte = "0x01"
	else:
		target_ble_15_4_combo_byte = "0x00"
	partition_table = b'tpxn'
	partition_table += binascii.unhexlify(fw_version[2:])[::-1]
	partition_table += binascii.unhexlify(fw_type_raw_byte[2:])[::-1]
	partition_table += binascii.unhexlify(image_partition_a_byte[2:])[::-1]
	partition_table += binascii.unhexlify(target_cpu1_byte[2:])[::-1]
	partition_table += binascii.unhexlify(target_ble_byte[2:])[::-1]
	partition_table += binascii.unhexlify(target_ble_audio_byte[2:])[::-1]
	partition_table += binascii.unhexlify(target_ble_15_4_combo_byte[2:])[::-1]
	if path_fw is not None:
		if os.access(path_fw, os.F_OK):
			if fw_type_raw is True: # raw binary
				tmp_dir_base = os.path.join(work_dir, get_artefact_base(path_fw))
				if target_cpu1 is True:
					logger.info(f"### Create cpu1 raw binary")
					raw_file_path = f"{tmp_dir_base}_raw_cpu1.bin"
				else:
					if target_ble_15_4_combo is True:
						logger.info(f"### Create cpu2 combo raw binary")
						raw_file_path = f"{tmp_dir_base}_raw_cpu2_ble_15_4_combo.bin"
					else:
						logger.info(f"### Create cpu2 raw binary")
						if target_ble is True:
							raw_file_path = f"{tmp_dir_base}_raw_cpu2_ble.bin"
						elif target_ble_audio is True:
							le_audio_dir_base = tmp_dir_base.strip('_le_audio')
							raw_file_path = f"{le_audio_dir_base}_raw_cpu2_le_audio.bin"
						else:
							raw_file_path = f"{tmp_dir_base}_raw_cpu2_15d4.bin"
				rawfile = open(raw_file_path, 'wb')
				file = open(path_fw, 'rb')
				elf_file = ELFFile(file)
				i = 0
				total_raw_size = 0
				for segment in elf_file.iter_segments():
					print(f"segment: {segment.header}")
					if segment.header.p_type == 'PT_LOAD':
						if segment.header.p_filesz > 0:
							file.seek(segment.header.p_offset)
							blockData = file.read(segment.header.p_filesz)
							rawfile.write(bytes('bwar','utf-8'))
							rawfile.write(bytes([i,0,0,0]))
							address = segment.header.p_paddr
							if target_cpu1 is True:
								if address < cpu1_imem_dmem_offset:
									address += cpu1_imem_dmem_offset						
								elif address >= smu0_offset:
									raise ValueError(f"Invalid load address {address}")
							else:
								if address < cpu2_imem_dmem_offset:
									address += cpu2_imem_dmem_offset						
								elif address >= smu0_offset:
									raise ValueError(f"Invalid load address {address}")
							rawfile.write(address.to_bytes(4, byteorder='little', signed=False))
							filesize = segment.header.p_filesz
							rawfile.write(filesize.to_bytes(4, byteorder='little', signed=False))
							rawfile.write(blockData)
							total_raw_size += filesize
							i += 1
				file.close()
				# append an ending segment for raw file to fix issue of raw cpu1/cpu2 firmware with monolithic feature
				rawfile.write(bytes('bwar','utf-8'))
				rawfile.write(0xffffffff.to_bytes(4, byteorder='little', signed=False))
				rawfile.write(0xffffffff.to_bytes(4, byteorder='little', signed=False))
				rawfile.write(total_raw_size.to_bytes(4, byteorder='little', signed=False))
				rawfile.close()
				config['fw_path'] = raw_file_path
				copy_image_to_root_path(raw_file_path, pathDst)
			else: # sb3.1 format
				if "sb3_config" not in image_config.keys():
					raise ValueError(r"Missing sb3 config file")
				path_config_sb = image_config["sb3_config"]
				with open(path_config_sb, "r") as fp:
					sb_image_config = json.load(fp)
				work_dir_base = os.path.join(work_dir, base)
				if target_cpu1 is True:
					logger.info(f"### Create cpu1 sb3 container")
					sb_file_path = get_artefact_path(work_dir_base, "sb.cpu1")
					path_config_temp_sb = get_artefact_path(work_dir_base, "elftosb.config.cpu1.sb.json")
					if sb_image_config['sb3FullOutput'] is True:
						dstpldfile = os.path.join(work_dir, "payload_cpu1_wifi.bin")
				else:
					if target_ble is True:
						logger.info(f"### Create cpu2 sb3 container for ble")
						sb_file_path = get_artefact_path(work_dir_base, "sb.cpu2.ble")
						path_config_temp_sb = get_artefact_path(work_dir_base, "elftosb.config.cpu2.ble.sb.json")
						if sb_image_config['sb3FullOutput'] is True:
							dstpldfile = os.path.join(work_dir, "payload_cpu2_ble.bin")
					elif target_ble_audio is True:
						logger.info(f"### Create cpu2 sb3 container for ble audio")
						sb_file_path = get_artefact_path(work_dir_base, "sb.cpu2.ble.audio")
						path_config_temp_sb = get_artefact_path(work_dir_base, "elftosb.config.cpu2.ble.audio.sb.json")
						if sb_image_config['sb3FullOutput'] is True:
							dstpldfile = os.path.join(work_dir, "payload_cpu2_ble_audio.bin")
					else:
						logger.info(f"### Create cpu2 sb3 container for 15d4")
						sb_file_path = get_artefact_path(work_dir_base, "sb.cpu2.15d4")
						path_config_temp_sb = get_artefact_path(work_dir_base, "elftosb.config.cpu2.15d4.sb.json")

						if sb_image_config['sb3FullOutput'] is True:
							dstpldfile = os.path.join(work_dir, "payload_cpu2_15d4.bin")
				tmp_dir_base = os.path.join(work_dir, get_artefact_base(path_fw))
				sb_image_config["containerOutputFile"] = sb_file_path
				sb_image_config["commands"] = []
				file = open(path_fw, 'rb')
				elf_file = ELFFile(file)
				i = 0
				for segment in elf_file.iter_segments():
					if segment.header.p_type == 'PT_LOAD':
						if segment.header.p_filesz > 0:
							if target_cpu1 is True:
								tmpfile_path = f"{tmp_dir_base}.cpu1.seg_{i}"
							else:
								if target_ble is True:
									tmpfile_path = f"{tmp_dir_base}.cpu2.ble.seg_{i}"
								elif target_ble_audio is True:
									tmpfile_path = f"{tmp_dir_base}.cpu2.ble.audio.seg_{i}"
								else:
									tmpfile_path = f"{tmp_dir_base}.cpu2.15d4.seg_{i}"
							tmpfile = open(tmpfile_path, 'wb')
							file.seek(segment.header.p_offset)
							blockData = file.read(segment.header.p_filesz)
							tmpfile.write(blockData)
							tmpfile.close()
							address = segment.header.p_paddr
							if target_cpu1 is True:
								if address < cpu1_imem_dmem_offset:
									address += cpu1_imem_dmem_offset						
								elif address >= smu0_offset:
									raise ValueError(f"Invalid load address {address}")
							else:
								if address < cpu2_imem_dmem_offset:
									address += cpu2_imem_dmem_offset						
								elif address >= smu0_offset:
									raise ValueError(f"Invalid load address {address}")
							address = hex(address)
							sb_image_config["commands"] += [{"load": {"address": str(address), "file": tmpfile_path, "authentication": "none", "memoryId": "0x0"}}]
							i += 1
				file.close()
				sb_image_config["commands"] += [{"execute": {"address": "0" }}]
				logger.info(f"### Total %d load regions", i)
				with open(path_config_temp_sb, "w") as fp:
					json.dump(sb_image_config, fp)
				process = subprocess.run(args=[path_elftosb, "-V", "-d", "-f", "lpc55s3x", "-j", path_config_temp_sb],
										cwd=os.path.dirname(path_elftosb),
										check=True, capture_output=True, encoding="ascii")
				for line in process.stdout.split("\n"):
					logger.info(f"    elftosb (sb): {line}")
				if sb_image_config['sb3FullOutput'] is True:
					srcdirname = os.path.dirname(path_elftosb)
					srcfile = os.path.join(srcdirname, "payload.bin")
					shutil.move(srcfile,dstpldfile)
				sbfile = open(sb_file_path, 'rb')
				sb_code = sbfile.read()
				sbfile.close()
				config['fw_path'] = sb_file_path
	return partition_table

def create_flash_image(params):
	# Decouple the argument names from internal variable names:
	path_fcb = os.path.abspath(params.get("flash_config_block")) if params.get(
		"flash_config_block") is not None else os.path.join("..", "tools", "scripts", "fcb_W25Q32JWxxIM.txt")
	path_otp_config = os.path.abspath(params.get("otp_config"))

	path_cpu2_fw = os.path.abspath(params.get("cpu2_fw")) if params.get("cpu2_fw") is not None else None
	path_cpu3_fw = os.path.abspath(params.get("cpu3_fw")) if params.get("cpu3_fw") is not None else None
	path_config_mb = os.path.abspath(params.get("cpu3_mb_config")) if params.get("cpu3_mb_config") is not None else None
	path_config_sb = os.path.abspath(params.get("cpu3_sb3_config")) if params.get("cpu3_sb3_config") is not None else None
	cpu3_image_version = int(params.get("cpu3_image_version")) if params.get("cpu3_image_version") is not None else 1
	path_elftosb = os.path.abspath(params.get("elftosb_path")) if params.get("elftosb_path") is not None else "../tools/elftosb/elftosb.exe"
	path_output = os.path.join(os.path.dirname(path_elftosb), "workspace/output_images")
	work_dir = setup_logging(path_output)
	base = "rw610"

	# Constant for a given bootloader
	flash_size            = 0x400000
	fcb_offset            = 0x400
	version_offset        = 0x600
	cpu3_image_offset     = 0x1000
	wifi_image_a_offset   = 0x400000
	wifi_image_size_max   = 0xa0000
	ble_image_size_max    = 0x50000
	z154_image_size_max   = 0x50000
	cpu3_image_size_max   = wifi_image_a_offset - cpu3_image_offset		# 0x3ff000
	wifi_image_b_offset   = wifi_image_a_offset + wifi_image_size_max	# 0x4a0000
	ble_image_a_offset    = wifi_image_b_offset + wifi_image_size_max	# 0x540000
	ble_image_b_offset    = ble_image_a_offset  + ble_image_size_max	# 0x590000
	z154_image_a_offset   = ble_image_b_offset  + ble_image_size_max	# 0x5e0000
	z154_image_b_offset   = z154_image_a_offset + z154_image_size_max	# 0x630000

	fcb = read_hex_file(path_fcb)
	otp_dir_base = os.path.join(work_dir, "demo")
	ocotp.create_otp_backgrounds(path_otp_config, otp_dir_base)
	image_version_full = (((~cpu3_image_version) << 16) & 0xFFFF0000) | (cpu3_image_version & 0xFFFF)
	version_bytes = binascii.unhexlify(hex(image_version_full)[2:])[::-1]
	#
	# Partition table
	#
	# 0~3	tag
	# 4~7	version
	# 8		raw falg
	# 9 	partition A flag
	# 10 	cpu1 flag
	# 11	cpu2 ble flag
	# 12~15 crc32
	#
	path_cpu1_pt = None
	path_cpu1_wifi_conf = os.path.abspath(params.get("wifi_image_config")) if params.get("wifi_image_config") is not None else None	
	if path_cpu1_wifi_conf is not None:
		cpu1_wifi_config = {'config_path': path_cpu1_wifi_conf, 'fw_path': path_cpu1_pt,}
		cpu1_partition_table = parse_image_config(cpu1_wifi_config, work_dir, path_elftosb)
		path_cpu1_pt = cpu1_wifi_config['fw_path']

	path_cpu2_ble_pt = None
	path_cpu2_ble_conf = os.path.abspath(params.get("ble_image_config")) if params.get("ble_image_config") is not None else None	
	if path_cpu2_ble_conf is not None:
		cpu2_ble_config = {'config_path': path_cpu2_ble_conf, 'fw_path': path_cpu2_ble_pt,}
		cpu2_ble_partition_table = parse_image_config(cpu2_ble_config, work_dir, path_elftosb)
		path_cpu2_ble_pt = cpu2_ble_config['fw_path']

	path_cpu2_ble_audio_pt = None
	path_cpu2_ble_audio_conf = os.path.abspath(params.get("ble_audio_image_config")) if params.get("ble_audio_image_config") is not None else None	
	if path_cpu2_ble_audio_conf is not None:
		cpu2_ble_audio_config = {'config_path': path_cpu2_ble_audio_conf, 'fw_path': path_cpu2_ble_audio_pt,}
		cpu2_ble_audio_partition_table = parse_image_config(cpu2_ble_audio_config, work_dir, path_elftosb)
		path_cpu2_ble_audio_pt = cpu2_ble_audio_config['fw_path']

	path_cpu2_15d4_pt = None
	path_cpu2_15d4_conf = os.path.abspath(params.get("15d4_image_config")) if params.get("15d4_image_config") is not None else None	
	if path_cpu2_15d4_conf is not None:
		cpu2_15d4_config = {'config_path': path_cpu2_15d4_conf, 'fw_path': path_cpu2_15d4_pt,}
		cpu2_15d4_partition_table = parse_image_config(cpu2_15d4_config, work_dir, path_elftosb)
		path_cpu2_15d4_pt = cpu2_15d4_config['fw_path']

	path_cpu2_ble_15d4_combo_pt = None
	path_cpu2_ble_15d4_combo_conf = os.path.abspath(params.get("ble_15d4_combo_image_config")) if params.get("ble_15d4_combo_image_config") is not None else None
	if path_cpu2_ble_15d4_combo_conf is not None:
		cpu2_ble_15d4_combo_config = {'config_path': path_cpu2_ble_15d4_combo_conf, 'fw_path': path_cpu2_ble_15d4_combo_pt,}
		cpu2_ble_15d4_combo_partition_table = parse_image_config(cpu2_ble_15d4_combo_config, work_dir, path_elftosb)
		path_cpu2_ble_15d4_combo_pt = cpu2_ble_15d4_combo_config['fw_path']

	if path_cpu3_fw is not None and path_config_mb is not None:
		if os.access(path_cpu3_fw, os.F_OK):
			with open(path_config_mb, "r") as fp:
				image_config = json.load(fp)
			work_dir_base = os.path.join(work_dir, base)
			#path_preload = get_artefact_path(work_dir_base, "mb.vmem")
			path_mb = get_artefact_path(work_dir_base, "mb_cpu3.bin")
			path_config_temp_mb = get_artefact_path(work_dir_base, "elftosb.config.mb.json")
			image_config["inputImageFile"] = path_cpu3_fw
			image_config["masterBootOutputFile"] = path_mb
			logger.info("### Create cpu3 masterboot image.")
			with open(path_config_temp_mb, "w") as fp:
				json.dump(image_config, fp)		
			process = subprocess.run(args=[path_elftosb, "-V", "-d", "-f", "lpc55s3x", "-J", path_config_temp_mb],
									cwd=os.path.dirname(path_elftosb),
									check=True, capture_output=True, encoding="ascii")
			for line in process.stdout.split("\n"):
				logger.info(f"    elftosb (mb): {line}")
			if os.path.getsize(path_mb) > cpu3_image_size_max:
				raise ValueError(f"cpu3 image size exceeds the limit!")
			logger.info("### Read masterboot image file.")
			with open(path_mb, "rb") as fp:
				cpu3_code = fp.read()

			sections = {
				'fcb': {'start_addr': fcb_offset, 'data': fcb},
				'version': {'start_addr': version_offset, 'data': version_bytes},
				'cpu3_code': {'start_addr': cpu3_image_offset, 'data': cpu3_code},
			}

			bytesfile = combine_sections(sections)
			rawfile = open(path_mb, 'wb')
			rawfile.write(bytesfile)

			'''
			if path_cpu1_pt is not None:
				if cpu1_partition_table[10] != 1:
					raise ValueError(f"Target cpu unmatched!")
				if cpu1_partition_table[9] == 1:
					logger.info("### locate at partition A for cpu1.")
					wifi_image_offset = wifi_image_a_offset
				else:
					logger.info("### locate at partition B for cpu1.")
					wifi_image_offset = wifi_image_b_offset
				if os.path.getsize(path_cpu1_pt) > wifi_image_size_max:
					raise ValueError(f"cpu1 image size exceeds the limit!")
				with open(path_cpu1_pt, "rb") as fp:
					cpu1_code = fp.read()
				item = {'cpu1_code': {'start_addr': wifi_image_offset, 'data': cpu1_code}}
				sections.update(item)

			if path_cpu2_ble_pt is not None:
				if cpu2_ble_partition_table[10] != 0:
					raise ValueError(f"Target cpu unmatched!")
				if cpu2_ble_partition_table[9] == 1:
					logger.info("### locate at partition A for cpu2 ble.")
					ble_image_offset = ble_image_a_offset
				else:
					logger.info("### locate at partition B for cpu2 ble.")
					ble_image_offset = ble_image_b_offset
				if os.path.getsize(path_cpu2_ble_pt) > ble_image_size_max:
					raise ValueError(f"cpu2 ble image size exceeds the limit!")
				with open(path_cpu2_ble_pt, "rb") as fp:
					cpu2_ble_code = fp.read()
				item = {'cpu2_ble_code': {'start_addr': ble_image_offset, 'data': cpu2_ble_code}}
				sections.update(item)

			if path_cpu2_15d4_pt is not None:
				if cpu2_15d4_partition_table[10] != 0:
					raise ValueError(f"Target cpu unmatched!")
				if cpu2_15d4_partition_table[9] == 1:
					logger.info("### locate at partition A for cpu2 15d4.")
					z154_image_offset = z154_image_a_offset
				else:
					logger.info("### locate at partition B for cpu2 15d4.")
					z154_image_offset = z154_image_b_offset
				if os.path.getsize(path_cpu2_15d4_pt) > z154_image_size_max:
					raise ValueError(f"cpu2 15d4 image size exceeds the limit!")
				with open(path_cpu2_15d4_pt, "rb") as fp:
					cpu2_15d4_code = fp.read()
				item = {'cpu2_15d4_code': {'start_addr': z154_image_offset, 'data': cpu2_15d4_code}}
				sections.update(item)

			path_wifi_alter_pt = os.path.abspath(params.get("append_wifi_alter_pt")) if params.get("append_wifi_alter_pt") is not None else None
			if path_wifi_alter_pt is not None and path_cpu1_pt is not None:
				if cpu1_partition_table[9] == 1:
					wifi_alt_image_offset = wifi_image_b_offset
					logger.info("### locate at partition B for cpu1 alt code.")
				else:
					wifi_alt_image_offset = wifi_image_a_offset
					logger.info("### locate at partition A for cpu1 alt code.")
				with open(path_wifi_alter_pt, "rb") as fp:
					cpu1_alt_code = fp.read()
				item = {'cpu1_alt_code': {'start_addr': wifi_alt_image_offset, 'data': cpu1_alt_code}}
				sections.update(item)

			path_ble_alter_pt = os.path.abspath(params.get("append_ble_alter_pt")) if params.get("append_ble_alter_pt") is not None else None
			if path_ble_alter_pt is not None and path_cpu2_ble_pt is not None:
				if cpu2_ble_partition_table[9] == 1:
					cpu2_ble_alt_image_offset = ble_image_b_offset
					logger.info("### locate at partition B for cpu2 ble alt code.")
				else:
					cpu2_ble_alt_image_offset = ble_image_a_offset
					logger.info("### locate at partition A for cpu2 ble alt code.")
				with open(path_ble_alter_pt, "rb") as fp:
					cpu2_ble_alt_code = fp.read()
				item = {'cpu2_ble_alt_code': {'start_addr': cpu2_ble_alt_image_offset, 'data': cpu2_ble_alt_code}}
				sections.update(item)

			path_15d4_alter_pt = os.path.abspath(params.get("append_15d4_alter_pt")) if params.get("append_15d4_alter_pt") is not None else None
			if path_15d4_alter_pt is not None and path_cpu2_15d4_pt is not None:
				if cpu2_15d4_partition_table[9] == 1:
					cpu2_15d4_alt_image_offset = z154_image_b_offset
					logger.info("### locate at partition B for cpu2 15d4 alt code.")
				else:
					cpu2_15d4_alt_image_offset = z154_image_a_offset
					logger.info("### locate at partition A for cpu2 15d4 alt code.")
				with open(path_15d4_alter_pt, "rb") as fp:
					cpu2_15d4_alt_code = fp.read()
				item = {'cpu2_15d4_alt_code': {'start_addr': cpu2_15d4_alt_image_offset, 'data': cpu2_15d4_alt_code}}
				sections.update(item)

			logger.info("### Create combined image with cpu3 mb image.")
			bytesfile = combine_sections(sections)
			logger.info("### Convert the executable to a vmem file.")
			write_hex_file(path_preload, bytesfile)
			logger.info(f"    written vmem file {path_preload}")
			'''

	if path_cpu3_fw is not None and path_config_sb is not None:
		if os.access(path_cpu3_fw, os.F_OK):
			with open(path_config_sb, "r") as fp:
				image_config = json.load(fp)
			work_dir_base = os.path.join(work_dir, base)
			path_preload = get_artefact_path(work_dir_base, "sb.vmem")
			path_sb = get_artefact_path(work_dir_base, "sb.cpu3")
			path_config_temp_sb = get_artefact_path(work_dir_base, "elftosb.config.sb.json")
			image_config["containerOutputFile"] = path_sb
			logger.info("### Create cpu3 sb3 image.")
			with open(path_config_temp_sb, "w") as fp:
				json.dump(image_config, fp)
			process = subprocess.run(args=[path_elftosb, "-V", "-d", "-f", "lpc55s3x", "-j", path_config_temp_sb],
									 cwd=os.path.dirname(path_elftosb),
									 check=True, capture_output=True, encoding="ascii")
			for line in process.stdout.split("\n"):
				logger.info(f"    elftosb (sb): {line}")
			if os.path.getsize(path_sb) > cpu3_image_size_max:
				raise ValueError(f"cpu3 image size exceeds the limit!")
			logger.info(f"### Read SB3.1 image file: {path_sb}")
			with open(path_sb, "rb") as fp:
				cpu3_code = fp.read()

			sections = {
				'fcb': {'start_addr': fcb_offset, 'data': fcb},
				'version': {'start_addr': version_offset, 'data': version_bytes},
				'cpu3_code': {'start_addr': cpu3_image_offset, 'data': cpu3_code},
			}

			if path_cpu1_pt is not None:
				if cpu1_partition_table[10] != 1:
					raise ValueError(f"Target cpu unmatched!")
				if cpu1_partition_table[9] == 1:
					logger.info("### locate at partition A for cpu1.")
					wifi_image_offset = wifi_image_a_offset
				else:
					logger.info("### locate at partition B for cpu1.")
					wifi_image_offset = wifi_image_b_offset
				if os.path.getsize(path_cpu1_pt) > wifi_image_size_max:
					raise ValueError(f"cpu1 image size exceeds the limit!")
				with open(path_cpu1_pt, "rb") as fp:
					cpu1_code = fp.read()
				item = {'cpu1_code': {'start_addr': wifi_image_offset, 'data': cpu1_code}}
				sections.update(item)

			if path_cpu2_ble_pt is not None:
				if cpu2_ble_partition_table[10] != 0:
					raise ValueError(f"Target cpu unmatched!")
				if cpu2_ble_partition_table[9] == 1:
					logger.info("### locate at partition A for cpu2 ble.")
					ble_image_offset = ble_image_a_offset
				else:
					logger.info("### locate at partition B for cpu2 ble.")
					ble_image_offset = ble_image_b_offset
				if os.path.getsize(path_cpu2_ble_pt) > ble_image_size_max:
					raise ValueError(f"cpu2 ble image size exceeds the limit!")
				with open(path_cpu2_ble_pt, "rb") as fp:
					cpu2_ble_code = fp.read()
				item = {'cpu2_ble_code': {'start_addr': ble_image_offset, 'data': cpu2_ble_code}}
				sections.update(item)

			if path_cpu2_ble_audio_pt is not None:
				if cpu2_ble_audio_partition_table[10] != 0:
					raise ValueError(f"Target cpu unmatched!")
				if cpu2_ble_audio_partition_table[9] == 1:
					logger.info("### locate at partition A for cpu2 ble audio.")
					ble_audio_image_offset = ble_image_a_offset
				else:
					logger.info("### locate at partition B for cpu2 ble audio.")
					ble_audio_image_offset = ble_image_b_offset
				if os.path.getsize(path_cpu2_ble_audio_pt) > ble_image_size_max:
					raise ValueError(f"cpu2 ble image size exceeds the limit!")
				with open(path_cpu2_ble_audio_pt, "rb") as fp:
					cpu2_ble_audio_code = fp.read()
				item = {'cpu2_ble_audio_code': {'start_addr': ble_audio_image_offset, 'data': cpu2_ble_audio_code}}
				sections.update(item)

			if path_cpu2_15d4_pt is not None:
				if cpu2_15d4_partition_table[10] != 0:
					raise ValueError(f"Target cpu unmatched!")
				if cpu2_15d4_partition_table[9] == 1:
					logger.info("### locate at partition A for cpu2 15d4.")
					z154_image_offset = z154_image_a_offset
				else:
					logger.info("### locate at partition B for cpu2 15d4.")
					z154_image_offset = z154_image_b_offset
				if os.path.getsize(path_cpu2_15d4_pt) > z154_image_size_max:
					raise ValueError(f"cpu2 15d4 image size exceeds the limit!")
				with open(path_cpu2_15d4_pt, "rb") as fp:
					cpu2_15d4_code = fp.read()
				item = {'cpu2_15d4_code': {'start_addr': z154_image_offset, 'data': cpu2_15d4_code}}
				sections.update(item)

			path_wifi_alter_pt = os.path.abspath(params.get("append_wifi_alter_pt")) if params.get("append_wifi_alter_pt") is not None else None
			if path_wifi_alter_pt is not None and path_cpu1_pt is not None:
				if cpu1_partition_table[9] == 1:
					wifi_alt_image_offset = wifi_image_b_offset
					logger.info("### locate at partition B for cpu1 alt code.")
				else:
					wifi_alt_image_offset = wifi_image_a_offset
					logger.info("### locate at partition A for cpu1 alt code.")
				with open(path_wifi_alter_pt, "rb") as fp:
					cpu1_alt_code = fp.read()
				item = {'cpu1_alt_code': {'start_addr': wifi_alt_image_offset, 'data': cpu1_alt_code}}
				sections.update(item)

			path_ble_alter_pt = os.path.abspath(params.get("append_ble_alter_pt")) if params.get("append_ble_alter_pt") is not None else None
			if path_ble_alter_pt is not None and path_cpu2_ble_pt is not None:
				if cpu2_ble_partition_table[9] == 1:
					cpu2_ble_alt_image_offset = ble_image_b_offset
					logger.info("### locate at partition B for cpu2 ble alt code.")
				else:
					cpu2_ble_alt_image_offset = ble_image_a_offset
					logger.info("### locate at partition A for cpu2 ble alt code.")
				with open(path_ble_alter_pt, "rb") as fp:
					cpu2_ble_alt_code = fp.read()
				item = {'cpu2_ble_alt_code': {'start_addr': cpu2_ble_alt_image_offset, 'data': cpu2_ble_alt_code}}
				sections.update(item)

			path_ble_audio_alter_pt = os.path.abspath(params.get("append_ble_audio_alter_pt")) if params.get("append_ble_audio_alter_pt") is not None else None
			if path_ble_audio_alter_pt is not None and path_cpu2_ble_audio_pt is not None:
				if cpu2_ble_audio_partition_table[9] == 1:
					cpu2_ble_audio_alt_image_offset = ble_image_b_offset
					logger.info("### locate at partition B for cpu2 ble audio alt code.")
				else:
					cpu2_ble_audio_alt_image_offset = ble_image_a_offset
					logger.info("### locate at partition A for cpu2 ble audio alt code.")
				with open(path_ble_audio_alter_pt, "rb") as fp:
					cpu2_ble_audio_alt_code = fp.read()
				item = {'cpu2_ble_audio_alt_code': {'start_addr': cpu2_ble_audio_alt_image_offset, 'data': cpu2_ble_audio_alt_code}}
				sections.update(item)

			path_15d4_alter_pt = os.path.abspath(params.get("append_15d4_alter_pt")) if params.get("append_15d4_alter_pt") is not None else None
			if path_15d4_alter_pt is not None and path_cpu2_15d4_pt is not None:
				if cpu2_15d4_partition_table[9] == 1:
					cpu2_15d4_alt_image_offset = z154_image_b_offset
					logger.info("### locate at partition B for cpu2 15d4 alt code.")
				else:
					cpu2_15d4_alt_image_offset = z154_image_a_offset
					logger.info("### locate at partition A for cpu2 15d4 alt code.")
				with open(path_15d4_alter_pt, "rb") as fp:
					cpu2_15d4_alt_code = fp.read()
				item = {'cpu2_15d4_alt_code': {'start_addr': cpu2_15d4_alt_image_offset, 'data': cpu2_15d4_alt_code}}
				sections.update(item)

			logger.info("### Create combined image with cpu3 sb image.")
			bytesfile = combine_sections(sections)
			logger.info("### Convert the executable to a vmem file.")
			write_hex_file(path_preload, bytesfile)
			logger.info(f"    written vmem file {path_preload}")

if __name__ == "__main__":
	args_dict = {
					'cpu3_fw': './sdk20-app.bin',
					'cpu3_image_version': 1,
					'cpu3_mb_config': './image_tool/elftosb/rw610_mb.json',
					'flash_config_block': './image_tool/scripts/fcb_W25Q32JWxxIM.txt',
					'otp_config': './image_tool/scripts/otp_fusemap_256.xml',
					'elftosb_path': './image_tool/elftosb/elftosb.exe',
					'wifi_image_config': './image_tool/elftosb/rw610_wifi_conf.json',
					'ble_image_config': './image_tool/elftosb/rw610_ble_conf.json',
					'ble_audio_image_config': './image_tool/elftosb/rw610_ble_audio_conf.json',
					'15d4_image_config': './image_tool/elftosb/rw610_15d4_conf.json',
					'ble_15d4_combo_image_config': './image_tool/elftosb/rw610n_combo_conf.json'
				}

	create_flash_image(args_dict)
