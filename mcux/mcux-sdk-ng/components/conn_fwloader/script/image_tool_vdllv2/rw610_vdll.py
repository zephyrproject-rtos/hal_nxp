#/*
# * Copyright 2024 NXP
# * 
# * SPDX-License-Identifier: BSD-3-Clause
# * The BSD-3-Clause license can be found at https://spdx.org/licenses/BSD-3-Clause.html
# */

# coding=utf-8

import os.path
import json
import sys
import logging
import indentlog
import datetime
import shutil

logger = indentlog.IndentLoggerAdapter(logging.getLogger(__name__))
invocation_time = datetime.datetime.now()

# Constant for loader
CPU1_IMEM_DMEM_OFFSET = 0x41000000
CPU2_IMEM_DMEM_OFFSET = 0x44000000
SMU0_OFFSET           = 0xa0005000
VDLL_CMD              = b'\x0c\x00\x00\x00'
VDLL_BLOCK_LENGTH     = 0x200
CRC32_POLYNOMIAL      = 0x04C11DB7
# Constant for flash layout
FLASH_SIZE            = 0x800000
FCB_OFFSET            = 0x400
VERSION_OFFSET        = 0x600
CPU3_IMAGE_OFFSET     = 0x1000
WIFI_IMAGE_A_OFFSET   = 0x400000
WIFI_IMAGE_SIZE_MAX   = 0xa0000
BLE_IMAGE_SIZE_MAX    = 0x50000
COMBO_IMAGE_SIZE_MAX  = 0x50000
CPU3_IMAGE_SIZE_MAX   = WIFI_IMAGE_A_OFFSET  - CPU3_IMAGE_OFFSET	# 0x3ff000
WIFI_IMAGE_B_OFFSET   = WIFI_IMAGE_A_OFFSET  + WIFI_IMAGE_SIZE_MAX	# 0x4a0000
BLE_IMAGE_A_OFFSET    = WIFI_IMAGE_B_OFFSET  + WIFI_IMAGE_SIZE_MAX	# 0x540000
BLE_IMAGE_B_OFFSET    = BLE_IMAGE_A_OFFSET   + BLE_IMAGE_SIZE_MAX	# 0x590000
COMBO_IMAGE_A_OFFSET  = BLE_IMAGE_B_OFFSET   + BLE_IMAGE_SIZE_MAX	# 0x5e0000
COMBO_IMAGE_B_OFFSET  = COMBO_IMAGE_A_OFFSET + COMBO_IMAGE_SIZE_MAX	# 0x630000

if not sys.version_info.major == 3 and sys.version_info.minor >= 8:
	logger.error("Python 3.6 or higher is required.")
	logger.error("You are using Python {}.{}.".format(sys.version_info.major, sys.version_info.minor))
	sys.exit(1)

def get_root_path(work_dir):
	from pathlib import Path
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
	return os.path.join(dirname, basename_no_ext + "." + ext)

def get_artefact_base(executable):
	basename = os.path.basename(executable)
	basename_no_ext = os.path.splitext(basename)[0]
	return basename_no_ext

def copy_image_to_root_path(pathSrc, pathDst):
	shutil.copy(pathSrc, pathDst)

def int2str(i_data, data_width):
	b_data = ''
	width_in_nipple = 2 * data_width	
	for i in range(width_in_nipple-1, -1, -1):
		digit = (i_data >> (4*i)) & 0xf
		if digit <= 9: 
			b_data += chr(digit + 0x30)
		else:			
			b_data += chr(digit + 0x57)
	return b_data

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

def vdll_process(cwd):
	from elftools.elf.elffile import ELFFile
	print (f"VDLL Post Processing on \"{cwd}\"")
	dirs = os.listdir(cwd)
	elf_file_path = os.path.join(cwd, 'rw610w.axf')
	try:
		elf_file = open(elf_file_path, 'rb')
	except:
		print (f"Error: \"rw610w.axf\" not found in directory \"{cwd}\".")
		sys.exit(1)			
	elf_file = ELFFile(elf_file)
	elf_vdll_sections = {}
	for section in elf_file.iter_sections():
		if section.name.startswith("VDLL") and section.name.endswith('_ID') and (section.name != "VDLL_INFO_ID"):
			sh_addr = section.header['sh_addr']
			sh_addr = str(hex(sh_addr))
			item = {section.name: sh_addr}
			elf_vdll_sections.update(item)
	if len(elf_vdll_sections) == 0:
		print (f"Error: \"rw610w.axf\" is not a valid firmware with vdll feature.")
		sys.exit(1)				
	main_sb3_file_path = os.path.join(cwd, 'payload_cpu1_wifi.sb3')
	try:
		main_sb3_file = open(main_sb3_file_path, 'rb')
	except:
		print (f"Error: \"payload_cpu1_wifi.sb3\" not found in directory \"{cwd}\".")
		sys.exit(1)
	data = main_sb3_file.read()
	main_sb3_file.close()
	sb3_file_path = os.path.join(cwd, 'wifi_vdll.sb3.bin')
	sb3_file = open(sb3_file_path, 'wb')
	sb3_file.write(data)
	for key, value in elf_vdll_sections.items():
		found_flag = 0
		for file in dirs:
			if file.find(value) > 0:
				found_flag = 1
				vdll_file_path = os.path.join(cwd, file)
				vdll_file = open(vdll_file_path, 'rb')
				data = vdll_file.read()
				vdll_file.close()
				sb3_file.write(data)
		if found_flag==0:
			print (f"Error: SB3.1 container for VDLL feature \"{key}\" not found in directory \"{cwd}\".")
			sys.exit(1)			
	sb3_file.close()
	print(f"\n### WIFI VDLL SB3 Container Generated!")
	print(f"### {sb3_file_path}\n")

# path_fw:			C:\Project\Redfinch\image_tool\OTPS\NewRequest\iw624w.axf
# work_dir:			C:\Project\Redfinch\image_tool\elftosb\workspace\output_images\2023-10-18-16-53-47
# work_dir_base:	C:\Project\Redfinch\image_tool\elftosb\workspace\output_images\2023-10-18-16-53-47\rw610
# sb_file_path:		C:\Project\Redfinch\image_tool\elftosb\workspace\output_images\2023-10-18-16-53-47\rw610.sb.cpu1
# 					C:\Project\Redfinch\image_tool\elftosb\workspace\output_images\2023-10-18-16-53-47\rw610.sb.cpu2.ble
#					C:\Project\Redfinch\image_tool\elftosb\workspace\output_images\2023-10-18-16-53-47\rw610.sb.cpu2.combo
# vdll_dir:			C:\Project\Redfinch\image_tool\elftosb\workspace\output_images\2023-10-18-16-53-47\vdll
# vdll_dir_base:	C:\Project\Redfinch\image_tool\elftosb\workspace\output_images\2023-10-18-16-53-47\vdll\rw610

def parse_image_config(config, work_dir, path_elftosb,ateb_build_server):
#	import shutil
	import subprocess
	from pathlib import Path
	from elftools.elf.elffile import ELFFile
	base = "rw610"
	path_image_conf = config['config_path']
	pathDst = os.path.abspath('')
	work_dir_base = os.path.join(work_dir, base)
	with open(path_image_conf, "r") as fp:
		image_config = json.load(fp)
		path_fw = image_config["fw_elf"]
		if "image_version" in image_config.keys():
			fw_version = image_config["image_version"]
		else:
			fw_version = 0
		fw_version = extend_hex_str(hex(fw_version))
		fw_type_raw = image_config["image_type_raw"]
		image_partition_a = image_config["image_partition_a"]
		target_cpu1 = image_config["target_cpu1"]
		target_ble = image_config["target_ble"]
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

	if path_fw is not None:
		fw_file = open(path_fw, 'rb')
		elf_file = ELFFile(fw_file)
		elf_vdll_sections = {}
		vdll_flag = 0

		for section in elf_file.iter_sections():
			if section.name.startswith("VDLL"):
				item = {section.name: section.header}
				elf_vdll_sections.update(item)

		if len(elf_vdll_sections) > 0:
			vdll_dir = f"{work_dir}/vdll/"
			vdll_dir = Path(vdll_dir).resolve().absolute()
			vdll_dir.mkdir(parents=True, exist_ok=True)
			vdll_dir_base = os.path.join(vdll_dir, get_artefact_base(path_fw))
			section_VDLL_INFO_ID = elf_vdll_sections.pop('VDLL_INFO_ID')
			if not section_VDLL_INFO_ID:
				logger.error("No VDLL_INFO_ID section defined. Exit!")
				sys.exit(1)
			section_VDLL_INFO_STORE = elf_vdll_sections.pop('VDLL_INFO_STORE')
			if not section_VDLL_INFO_STORE:
				logger.error("No VDLL_INFO_STORE section defined. Exit!")
				sys.exit(1)
			vdll_flag = 1
			addr_VDLL_INFO_ID = section_VDLL_INFO_ID.get('sh_addr')
			addr_VDLL_INFO_STORE = section_VDLL_INFO_STORE.get('sh_addr')
			assert addr_VDLL_INFO_ID + 4 == addr_VDLL_INFO_STORE, 'address of VDLL_INFO_ID and VDLL_INFO_STORE unmatched!'
			addr_VDLL_INFO_ID = hex(addr_VDLL_INFO_ID)
			vdll_info_list = []
			vdll_info_addr = None
			vdll_segfile_path = None
			vdll_segfile = None
			vdll_tmpoffset = 0
			vdll_rawaddr = 0
			vdll_counter = 0
			for key,values in elf_vdll_sections.items():
				if key.endswith('_ID'):
					for segment in elf_file.iter_segments():
						if segment.header.p_type == 'PT_LOAD' and segment.header.p_filesz > 0:
							if segment.header.p_paddr == values.sh_addr:
								fw_file.seek(segment.header.p_offset)
								vdll_id = int.from_bytes(fw_file.read(2), byteorder='little', signed=False)
								vdll_sig = int.from_bytes(fw_file.read(2), byteorder='little', signed=False)
								assert vdll_sig == 0xbeef, 'vdll signature should be 0xbeef.'
								vdll_rawaddr = segment.header.p_paddr
								vdll_rawaddr = str(hex(segment.header.p_paddr))
								vdll_id_str = int2str(vdll_id, 2)
								vdll_segfile_path = f"{vdll_dir_base}.cpu1.seg_vdll_{vdll_id_str}_{vdll_rawaddr}"
								vdll_segfile = open(vdll_segfile_path, 'wb')
								fw_file.seek(segment.header.p_offset)
								blockData = fw_file.read(segment.header.p_filesz)
								vdll_segfile.write(blockData)
								vdll_segfile.close()
								vdll_info_list.append({'VDLLOFFSET': 0, 'ADDR': segment.header.p_paddr, 'BLOCKLEN': segment.header.p_filesz, 'VDLLID': vdll_id, 
									'TOTLEN': segment.header.p_filesz, 'NUMBLK': 1, 'SEG_FILE': vdll_segfile_path})
								vdll_counter += 1	
			vdll_info_file_path = f"{work_dir_base}.cpu1.seg_vdll_info_{str(addr_VDLL_INFO_ID)}"
			vdll_info_file = open(vdll_info_file_path, 'wb')
			
		if fw_type_raw is True: # raw binary
			tmp_dir_base = os.path.join(work_dir, get_artefact_base(path_fw))
			if target_cpu1 is True:
				logger.info(f"### Create cpu1 raw binary")
				raw_file_path = f"{tmp_dir_base}_raw_cpu1_vdllv2.bin"
			else:
				logger.info(f"### Create cpu2 raw binary")
				if target_ble is True:
					raw_file_path = f"{tmp_dir_base}.raw.cpu2.ble"
				else:
					raw_file_path = f"{tmp_dir_base}.raw.cpu2.combo"
			rawfile = open(raw_file_path, 'wb')
			if vdll_flag == 1:
				vdll_rawfile_list = []
				for vdll_info in vdll_info_list:
					vdll_segfile = open(vdll_info['SEG_FILE'], 'rb')
					seg_data = vdll_segfile.read()
					seg_size = vdll_segfile.tell()
					vdll_segfile.close()
					vdll_rawfile_path = f"{vdll_info['SEG_FILE']}.raw"
					vdll_rawfile_base = os.path.basename(vdll_rawfile_path)
					logger.info(f"    ==> Create cpu1 raw container for VDLL at {vdll_rawfile_base}")
					vdll_rawfile = open(vdll_rawfile_path, 'wb')
					vdll_rawfile.write(bytes('bwar','utf-8'))
					vdll_rawfile.write(bytes('lldv','utf-8'))
					vdll_rawfile.write(vdll_info['ADDR'].to_bytes(4, byteorder='little', signed=False))
					vdll_rawfile.write(seg_size.to_bytes(4, byteorder='little', signed=False))
					vdll_rawfile.write(seg_data)
					vdll_rawfile.close()
					vdll_rawfile_list.append(vdll_rawfile_path)
				logger.info(f"### Total %d vdll raw containers", vdll_counter)
				vdll_info_list.append({'VDLLOFFSET': 0xffffffff, 'ADDR': 0xffffffff, 'BLOCKLEN': 0xffff, 'VDLLID': 0xffff, 'TOTLEN': 0xffffff, 'NUMBLK': 0xff, 'SEG_FILE': None})
				vdll_index = 0
				offset = 0
				for vdll_info in vdll_info_list:
					if vdll_index == 0:
						vdll_rawfile = open(vdll_rawfile_list[vdll_index], 'rb')
						vdll_rawfile.seek(0, 2)
						offset = vdll_rawfile.tell() & 0xFFFFFFFF
						vdll_rawfile.close()
					elif vdll_index == vdll_counter:
						continue
					else:
						vdll_rawfile = open(vdll_rawfile_list[vdll_index], 'rb')
						vdll_rawfile.seek(0, 2)
						vdll_info['VDLLOFFSET'] = offset
						offset = (offset + vdll_rawfile.tell()) & 0xFFFFFFFF
						vdll_rawfile.close()
					vdll_index += 1
				vdll_info_list[0]['VDLLOFFSET'] = offset
				for vdll_info in vdll_info_list:
					vdll_info ['VDLLOFFSET'] = vdll_info ['VDLLOFFSET'] & 0xFFFFFFFF
					vdll_info_file.write(vdll_info['VDLLOFFSET'].to_bytes(4, byteorder='little', signed=False))
					vdll_info_file.write(vdll_info['ADDR'].to_bytes(4, byteorder='little', signed=False))
					vdll_info_file.write(vdll_info['BLOCKLEN'].to_bytes(2, byteorder='little', signed=False))
					vdll_info_file.write(vdll_info['VDLLID'].to_bytes(2, byteorder='little', signed=False))
					vdll_info_file.write(vdll_info['TOTLEN'].to_bytes(3, byteorder='little', signed=False))
					vdll_info_file.write(vdll_info['NUMBLK'].to_bytes(1, byteorder='little', signed=False))
				vdll_info_file.close()
			load_counter = 0
			total_raw_size = 0
			for segment in elf_file.iter_segments():
				if segment.header.p_type == 'PT_LOAD':
					if segment.header.p_filesz > 0:
						address = segment.header.p_paddr
						if target_cpu1 is True:
							if address < CPU1_IMEM_DMEM_OFFSET:
								address += CPU1_IMEM_DMEM_OFFSET
							elif address >= SMU0_OFFSET:
								raise ValueError(f"Invalid load address 0x{address:x}")
						else:
							if address < CPU2_IMEM_DMEM_OFFSET:
								address += CPU2_IMEM_DMEM_OFFSET
							elif address >= SMU0_OFFSET:
								raise ValueError(f"Invalid load address 0x{address:x}")
						fw_file.seek(segment.header.p_offset)
						if vdll_flag == 1:
							vdll_segment_flag = 0
							for vdll_info in vdll_info_list:
								if address == vdll_info['ADDR']:
									vdll_segment_flag = 1
							if vdll_segment_flag == 1: continue						
						if (vdll_flag == 1) and (segment.header.p_paddr == section_VDLL_INFO_ID.get('sh_addr')):
							vdll_info_addr = address
							vdll_info_id = fw_file.read(segment.header.p_filesz)
							continue
						else:
							logger.info(f"    ==> Create cpu1 load region at {str(hex(address)):>10}")
							code_size = segment.header.p_filesz
							blockData = fw_file.read(code_size)
						rawfile.write(bytes('bwar','utf-8'))
						rawfile.write(load_counter.to_bytes(4, byteorder='little', signed=False))
						rawfile.write(address.to_bytes(4, byteorder='little', signed=False))
						rawfile.write(code_size.to_bytes(4, byteorder='little', signed=False))
						rawfile.write(blockData)
						total_raw_size += code_size
						load_counter += 1
			if vdll_flag == 1:
				logger.info(f"    ==> Create cpu1 load region at {str(hex(vdll_info_addr)):>10} (vdll_info region)")
				vdll_info_file = open(vdll_info_file_path, 'rb+')				
				blockData = vdll_info_file.read()
				code_size = vdll_info_file.tell()
				code_size += 4
				vdll_info_file.seek(0, 0)
				vdll_info_file.write(vdll_info_id)
				vdll_info_file.write(blockData)
				vdll_info_file.close()
				rawfile.write(bytes('bwar','utf-8'))
				rawfile.write(load_counter.to_bytes(4, byteorder='little', signed=False))
				rawfile.write(vdll_info_addr.to_bytes(4, byteorder='little', signed=False))
				rawfile.write(code_size.to_bytes(4, byteorder='little', signed=False))
				rawfile.write(vdll_info_id)
				rawfile.write(blockData)
				total_raw_size += code_size
				# append an ending segment for raw file to fix issue of raw cpu1/cpu2 firmware with monolithic feature
				rawfile.write(bytes('bwar','utf-8'))
				rawfile.write(0xffffffff.to_bytes(4, byteorder='little', signed=False))
				rawfile.write(0xffffffff.to_bytes(4, byteorder='little', signed=False))
				rawfile.write(total_raw_size.to_bytes(4, byteorder='little', signed=False))
				load_counter += 1
				for vdll_rawfile_path in vdll_rawfile_list:
					vdll_rawfile = open(vdll_rawfile_path, 'rb')
					vdll_rawdata = vdll_rawfile.read()
					rawfile.write(vdll_rawdata)
					vdll_rawfile.close()
			else:
				# append an ending segment for raw file to fix issue of raw cpu1/cpu2 firmware with monolithic feature
				rawfile.write(bytes('bwar','utf-8'))
				rawfile.write(0xffffffff.to_bytes(4, byteorder='little', signed=False))
				rawfile.write(0xffffffff.to_bytes(4, byteorder='little', signed=False))
				rawfile.write(total_raw_size.to_bytes(4, byteorder='little', signed=False))
			logger.info(f"### Total %d load regions", load_counter)
			logger.info(f"### Result raw file at %s", raw_file_path)
			fw_file.close()
			rawfile.close()
			config['fw_path'] = raw_file_path
			if ateb_build_server == 'Yes':
				copy_image_to_root_path(raw_file_path, pathDst)

		else: # sb3.1 format
			if "sb3_config" not in image_config.keys():
				raise ValueError(r"Missing sb3 config file")
			path_config_sb = image_config["sb3_config"]
			with open(path_config_sb, "r") as fp:
				sb_image_config = json.load(fp)
			if target_cpu1 is True:
				logger.info(f"")
				logger.info(f"### Create cpu1 sb3 container")
				sb_file_path = get_artefact_path(work_dir_base, "sb.cpu1")
				path_config_temp_sb = get_artefact_path(work_dir_base, "elftosb.config.cpu1.sb.json")
				if sb_image_config['sb3FullOutput'] is True:
					dstpldfile = os.path.join(work_dir, "payload_cpu1_wifi.bin")
				if vdll_flag == 1:
					sb_vdll_file_path = get_artefact_path(work_dir_base, "sb.cpu1.vdll")
			else:
				if target_ble is True:
					logger.info(f"")
					logger.info(f"### Create cpu2 sb3 container for ble")
					sb_file_path = get_artefact_path(work_dir_base, "sb.cpu2.ble")
					path_config_temp_sb = get_artefact_path(work_dir_base, "elftosb.config.cpu2.ble.sb.json")
					if sb_image_config['sb3FullOutput'] is True:
						dstpldfile = os.path.join(work_dir, "payload_cpu2_ble.bin")
				else:
					logger.info(f"")
					logger.info(f"### Create cpu2 sb3 container for combo")
					sb_file_path = get_artefact_path(work_dir_base, "sb.cpu2.combo")
					path_config_temp_sb = get_artefact_path(work_dir_base, "elftosb.config.cpu2.combo.sb.json")
					if sb_image_config['sb3FullOutput'] is True:
						dstpldfile = os.path.join(work_dir, "payload_cpu2_combo.bin")
			sb_image_config["containerOutputFile"] = sb_file_path
			sb_image_config["commands"] = []
			if vdll_flag == 1:
				vdll_sb3file_list = []
				for vdll_info in vdll_info_list:
					vdll_sb3file_path = f"{vdll_info['SEG_FILE']}.sb3"
					vdll_sb3file_base = os.path.basename(vdll_sb3file_path)
					vdll_sb3payloadfile_path = f"{vdll_info['SEG_FILE']}.bin"
					vdll_sb3payloadfile_base = os.path.basename(vdll_sb3payloadfile_path)
					sb_image_config_temp = sb_image_config.copy()
					vdll_addr = str(hex(vdll_info['ADDR']))
					sb_image_config_temp["commands"] = [{"load": {"address": vdll_addr, "file": vdll_info['SEG_FILE'], "authentication": "none", "memoryId": "0x0"}}]
					sb_image_config_temp["containerOutputFile"] = vdll_sb3file_path
					vdll_sb3file_list.append(vdll_sb3file_path)
					path_sb_image_config_temp = f"{vdll_info['SEG_FILE']}.json"
					with open(path_sb_image_config_temp, "w") as fp:
						json.dump(sb_image_config_temp, fp)
					logger.info(f"    ==> Create cpu1 sb3 container for VDLL at {vdll_sb3file_base}")
					process = subprocess.run(args=[path_elftosb, "-V", "-d", "-f", "lpc55s3x", "-j", path_sb_image_config_temp],
						cwd=os.path.dirname(path_elftosb), check=True, capture_output=True, encoding="ascii")
					'''
					for line in process.stdout.split("\n"):
						logger.info(f"        elftosb (sb): {line}")
					'''
					if sb_image_config_temp['sb3FullOutput'] is True:
						dstpldfile_temp = os.path.join(vdll_dir, f"payload_{vdll_sb3payloadfile_base}")
						srcdirname = os.path.dirname(path_elftosb)
						srcfile = os.path.join(srcdirname, "payload.bin")
						shutil.move(srcfile,dstpldfile_temp)
				logger.info(f"### Total %d vdll sb3 containers", vdll_counter)
				vdll_info_list.append({'VDLLOFFSET': 0xffffffff, 'ADDR': 0xffffffff, 'BLOCKLEN': 0xffff, 'VDLLID': 0xffff, 'TOTLEN': 0xffffff, 'NUMBLK': 0xff, 'SEG_FILE': None})
				vdll_index = 0
				offset = 0
				for vdll_info in vdll_info_list:
					if vdll_index == 0:
						vdll_sb3file = open(vdll_sb3file_list[vdll_index], 'rb')
						vdll_sb3file.seek(0, 2)
						offset = vdll_sb3file.tell() & 0xFFFFFFFF
						vdll_sb3file.close()
					elif vdll_index == vdll_counter:						
						continue
					else:
						vdll_sb3file = open(vdll_sb3file_list[vdll_index], 'rb')
						vdll_sb3file.seek(0, 2)
						vdll_info['VDLLOFFSET'] = offset
						offset = (offset + vdll_sb3file.tell()) & 0xFFFFFFFF
						vdll_sb3file.close()
					vdll_index += 1
				vdll_info_list[0]['VDLLOFFSET'] = offset
				for vdll_info in vdll_info_list:
					vdll_info_file.write(vdll_info['VDLLOFFSET'].to_bytes(4, byteorder='little', signed=False))
					vdll_info_file.write(vdll_info['ADDR'].to_bytes(4, byteorder='little', signed=False))
					vdll_info_file.write(vdll_info['BLOCKLEN'].to_bytes(2, byteorder='little', signed=False))
					vdll_info_file.write(vdll_info['VDLLID'].to_bytes(2, byteorder='little', signed=False))
					vdll_info_file.write(vdll_info['TOTLEN'].to_bytes(3, byteorder='little', signed=False))
					vdll_info_file.write(vdll_info['NUMBLK'].to_bytes(1, byteorder='little', signed=False))
					vdll_index += 1
				vdll_info_file.close()
			load_counter = 0
			for segment in elf_file.iter_segments():
				if segment.header.p_type == 'PT_LOAD':
					if segment.header.p_filesz > 0:
						address = segment.header.p_paddr
						if vdll_flag == 1:
							vdll_segment_flag = 0
							for vdll_info in vdll_info_list:
								if address == vdll_info['ADDR']:
									vdll_segment_flag = 1
							if vdll_segment_flag == 1: continue
						if target_cpu1 is True:
							if address < CPU1_IMEM_DMEM_OFFSET:
								address += CPU1_IMEM_DMEM_OFFSET
							elif address >= SMU0_OFFSET:
								raise ValueError(f"Invalid load address 0x{address:x}")
						else:
							if address < CPU2_IMEM_DMEM_OFFSET:
								address += CPU2_IMEM_DMEM_OFFSET
							elif address >= SMU0_OFFSET:
								raise ValueError(f"Invalid load address 0x{address:x}")

						if (vdll_flag == 1) and (segment.header.p_paddr == section_VDLL_INFO_ID.get('sh_addr')):
							vdll_info_addr = address
							vdll_info_addr = hex(vdll_info_addr)
							fw_file.seek(segment.header.p_offset)
							vdll_info_id = fw_file.read(segment.header.p_filesz)
							continue

						address = hex(address)
						if target_cpu1 is True:
							tmpfile_path = f"{work_dir_base}.cpu1.seg_{load_counter}_{str(address)}"
						else:
							if target_ble is True:
								tmpfile_path = f"{work_dir_base}.cpu2.ble.seg_{load_counter}_{str(address)}"
							else:
								tmpfile_path = f"{work_dir_base}.cpu2.combo.seg_{load_counter}_{str(address)}"
						tmpfile = open(tmpfile_path, 'wb')
						fw_file.seek(segment.header.p_offset)
						blockData = fw_file.read(segment.header.p_filesz)
						tmpfile.write(blockData)
						tmpfile.close()
						logger.info(f"    ==> Create cpu1 load region at {str(address):>10}")
						sb_image_config["commands"] += [{"load": {"address": str(address), "file": tmpfile_path, "authentication": "none", "memoryId": "0x0"}}]
						load_counter += 1
			if vdll_flag == 1:
				logger.info(f"    ==> Create cpu1 load region at {str(vdll_info_addr):>10} (vdll_info region)")
				vdll_info_file = open(vdll_info_file_path, 'rb+')
				vdll_info_data = vdll_info_file.read()
				vdll_info_file.seek(0, 0)
				vdll_info_file.write(vdll_info_id)
				vdll_info_file.write(vdll_info_data)
				vdll_info_file.close()
				sb_image_config["commands"] += [{"load": {"address": str(vdll_info_addr), "file": vdll_info_file_path, "authentication": "none", "memoryId": "0x0"}}]
				load_counter += 1
			fw_file.close()
			sb_image_config["commands"] += [{"execute": {"address": "0" }}]
			logger.info(f"### Total %d load regions", load_counter)
			with open(path_config_temp_sb, "w") as fp:
				json.dump(sb_image_config, fp)
			process = subprocess.run(args=[path_elftosb, "-V", "-d", "-f", "lpc55s3x", "-j", path_config_temp_sb],
									cwd=os.path.dirname(path_elftosb),
									check=True, capture_output=True, encoding="ascii")
			'''
			for line in process.stdout.split("\n"):
				logger.info(f"    elftosb (sb): {line}")
			'''
			if sb_image_config['sb3FullOutput'] is True:
				srcdirname = os.path.dirname(path_elftosb)
				srcfile = os.path.join(srcdirname, "payload.bin")
				shutil.move(srcfile,dstpldfile)
			if vdll_flag == 1:
				sb3_vdll_file = open(sb_vdll_file_path, 'wb')
				sb3file = open(sb_file_path, 'rb')
				sb3 = sb3file.read()
				sb3_vdll_file.write(sb3)
				for vdll_sb3file_path in vdll_sb3file_list:
					vdll_sb3file = open(vdll_sb3file_path, 'rb')
					vdll_sb3 = vdll_sb3file.read()
					sb3_vdll_file.write(vdll_sb3)
					vdll_sb3file.close()
				sb3file.close()
				sb3_vdll_file.close()
			sbfile = open(sb_file_path, 'rb')
			sb_code = sbfile.read()
			sbfile.close()
			config['fw_path'] = sb_file_path
			logger.info(f"### Result file at %s", work_dir)

def create_flash_image(params):
	import subprocess
	# Decouple the argument names from internal variable names:
	path_config_sb = os.path.abspath(params.get("cpu3_sb3_config")) if params.get("cpu3_sb3_config") is not None else None
	path_elftosb = os.path.abspath(params.get("elftosb_path")) if params.get("elftosb_path") is not None else "../tools/elftosb/elftosb.exe"
	path_output = os.path.join(os.path.dirname(path_elftosb), "workspace/output_images")
	work_dir = setup_logging(path_output)
	ateb_build_server = params.get("ATEB_Build_Server")
	base = "rw610"
	path_cpu1_pt = None
	path_cpu1_wifi_conf = os.path.abspath(params.get("wifi_image_config")) if params.get("wifi_image_config") is not None else None	
	if path_cpu1_wifi_conf is not None:
		cpu1_wifi_config = {'config_path': path_cpu1_wifi_conf, 'fw_path': path_cpu1_pt,}
		parse_image_config(cpu1_wifi_config, work_dir, path_elftosb,ateb_build_server)
		path_cpu1_pt = cpu1_wifi_config['fw_path']

def usage():
	print("\nUsage: rw610_vdll [Options]")
	print("Description: Process RW61x ELF file to get RAW or SB3.1 format images for load service.\n")
	print("1) rw610_vdll")
	print("   This command will search the first *.json file under current directory as its configuration.")
	print("   Then generate raw binary or secure container per the configuration.")
	print("   An error will pop if no *.json file found under the current directory.\n")
	print("   A sample configuration *.json file.")
	print("   |{")
	print("   |    \"elftosb_path\": \"C:\\\\Project\\\\Redfinch\\\\image_tool\\\\elftosb\\\\elftosb.exe\",")
	print("   |    \"wifi_image_config\": \"C:\\\\Project\\\\Redfinch\\\\image_tool\\\\elftosb\\\\rw610_wifi_conf_vdll.json\"")
	print("   |}\n")
	print("2) rw610_vdll -c \\dir\\xxx.json")
	print("   rw610_vdll -config \\dir\\xxx.json")
	print("   This command will use the specified \"\\dir\\xxx.json\" file as its configuration.\n")
	print("3) rw610_vdll --vpp")
	print("   This command, as vdll post proccessing, will read in following files under current directory then concatenate them together to form a VDLL firmware image.")
	print("   - rw610w.axf,                                 the ELF file of RW610 wifi image")
	print("   - payload_cpu1_wifi.sb3,                      the basic wifi image in sb3.1 format ")
	print("   - rw610w.cpu1.seg_vdll_001d_0xXXXXXXXX.sb3,   the vdll image of feature id 0x001d in sb3.1 format ")
	print("   - rw610w.cpu1.seg_vdll_0006_0xXXXXXXXX.sb3,   the vdll image of feature id 0x0006 in sb3.1 format ")
	print("   - rw610w.cpu1.seg_vdll_0007_0xXXXXXXXX.sb3,   the vdll image of feature id 0x0007 in sb3.1 format ")
	print("   All vdll images of rw610w.axf in sb3.1 format must be present in the folder to successfully generate final VDLL firmware image.\n")
	print("4) rw610_vdll --vpp \\dir")
	print("   This vpp command will search required input files from the specified directory.\n")

if __name__ == "__main__":
	print("\nrw610_vdll version 2024-01-04\n")
	args_dict = None
	if len(sys.argv) == 1:
		cwd = os.getcwd()
		dirs = os.listdir(cwd)
		for cfg_file in dirs:
			if (os.path.isfile(cfg_file)) and cfg_file.endswith('.json'):
				with open(cfg_file, "r") as fp:
					args_dict = json.load(fp)
					print (f"RW61x Image Processing with configuration file \"{cfg_file}\".")
					create_flash_image(args_dict)
		if args_dict == None:
			print ("Error: no configuration file *.json found in current directory.")
			sys.exit(1)
	elif (sys.argv[1] == '-c') or (sys.argv[1] == '--config'):
		cfg_file = sys.argv[2]
		try: 
			with open(cfg_file, "r") as fp:
				args_dict = json.load(fp)
				print (f"RW61x Image Processing with assigned configuration file \"{cfg_file}\".")
				create_flash_image(args_dict)
		except:
			print (f"Error: assigned configuration file \"{cfg_file}\"not found.")
			sys.exit(1)
	elif sys.argv[1] == '--vpp':
		if len(sys.argv) == 2:
			cwd = os.getcwd()
		elif len(sys.argv) == 3:
			cwd = sys.argv[2]
		else:
			print ("Error: Invalid Parameters.")
			usage()
			sys.exit(1)
		vdll_process(cwd)
	elif (sys.argv[1] == '-h') or (sys.argv[1] == '--help'):
		usage()
		sys.exit(1)		
	else:
		print ("Error: Invalid Options")
		usage()
		sys.exit(1)

