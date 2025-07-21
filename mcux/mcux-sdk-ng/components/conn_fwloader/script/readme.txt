The steps to generate image:
1. The files and tools needed in the image generation script include:
	a. Have python installed with version >= v3.8
	b. (optional)rw610w.axf, for CPU1, put it in “\script” folder
	c. (optional)rw610n.axf, for CPU2, put it in “\script” folder
	d. (optional)nbu_15_4.out, for CPU2, put it in “\script” folder
	e. (optional)sdk20-app.bin, for CPU3, put it in “\script” folder
	f. (optional)rw610n_combo.axf, for CPU2, put it in "\script" folder

2. Before run the tool, you need to install the python package(pyelftools), run this command:
	#pip install pyelftools

3. Change the image type, for sb3 or raw (default raw):
	In "\script\image_tool\elftosb\rw610_wifi_conf.json",
	or in "\script\image_tool\elftosb\rw610_ble_conf.json",
	or in "\script\image_tool\elftosb\rw610_15d4_conf.json",
	or in "\script\image_tool\elftosb\rw610n_combo_conf.json":

	Image_type	 Configuration
	raw image	 "image_type_raw": true,
	sb3 image	 "image_type_raw": false,

4. Choose the authentication type of output image, CRC or Sign (default CRC):
	CRC
		In "\image_tool\scripts\rw610.py":
			'cpu3_mb_config': './image_tool/elftosb/rw610_mb.json',
		In "\image_tool\scripts\otp_fusemap_256.xml":
			<fuseword pos="15" type="MODE_ECC" data="0x1" />
	Sign
		In "\image_tool\scripts\rw610.py":
			'cpu3_mb_config': './image_tool/elftosb/rw610_mb_256.json',
		In "\image_tool\scripts\otp_fusemap_256.xml":
			<fuseword pos="15" type="MODE_ECC" data=" 0x980001" />

5. Choose quad-spi or single-spi mode(temporarily, default single)
	Single spi:
		In "\image_tool\scripts\rw610.py":
			'flash_config_block': './image_tool/scripts/fcb_W25Q32JWxxIM.txt'
	Quad spi:
		In "\image_tool\scripts\rw610.py":
			'flash_config_block': './image_tool/scripts/fcb_W25Q32JWxxQM.txt'

6. To generate the image, enter the “\script” folder, and run the following script in CMD window:
	#python ./image_tool/scripts/rw610.py

7. After running the tool, you will get image files at “\script\image_tool\elftosb\workspace\output_images\2021-xx-xx-xx-xx-xx”:
	for raw image:
		a. rw610w.raw.cpu1 for CPU1
		b. rw610n.raw.cpu2.ble for CPU2_BLE
		c. nbu_15_4.raw.cpu2.15d4 for CPU2_15d4
		d. rw610.mb.cpu3 for CPU3
		e. rw610n_combo_raw_cpu2_ble_15_4_combo.bin for CPU2_BLE_15d4_combo
