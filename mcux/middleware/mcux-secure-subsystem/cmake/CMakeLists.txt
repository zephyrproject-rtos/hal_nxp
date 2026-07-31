
if(CONFIG_MCUX_SECURE_SUBSYSTEM)

	zephyr_library_named(McuxSecureSubSystem)

	zephyr_compile_definitions(
		SSCP_CONFIG_FILE="fsl_sscp_config_elemu.h"
		SSS_CONFIG_FILE="fsl_sss_config_elemu.h"
	)

	zephyr_include_directories(
		${MCUX_SECURE_SUBSYSTEM_PATH}/inc
		${MCUX_SECURE_SUBSYSTEM_PATH}/inc/elemu
	)

	zephyr_library_sources(
		${MCUX_SECURE_SUBSYSTEM_PATH}/src/sscp/fsl_sscp_mu.c
		${MCUX_SECURE_SUBSYSTEM_PATH}/src/sscp/fsl_sss_mgmt.c
		${MCUX_SECURE_SUBSYSTEM_PATH}/src/sscp/fsl_sss_sscp.c
	)

	if(CONFIG_MCUX_SECURE_SUBSYSTEM_FIRMWARE_EL2GO)
		# Enable legacy macro
		zephyr_compile_definitions(
			ELEMU_HAS_LOADABLE_FW=1
		)

		zephyr_include_directories(
			${MCUX_SECURE_SUBSYSTEM_PATH}/firmware
		)

		# Select the correct FW binary and build a normalized absolute path to it
		if(CONFIG_FIRMWARE_S200_EL2GO_KW45)
			set(MCUX_S200_FW_BIN_DIR  ${ZEPHYR_HAL_NXP_MODULE_DIR}/zephyr/blobs/mcxw71/)
			set(MCUX_S200_FW_BIN_NAME KW45_K32W1xx_MCXW71_SDKFW3.0_RFP1.sb3)
		elseif(CONFIG_FIRMWARE_S200_EL2GO_KW47)
			set(MCUX_S200_FW_BIN_DIR  ${ZEPHYR_HAL_NXP_MODULE_DIR}/zephyr/blobs/mcxw72/)
			set(MCUX_S200_FW_BIN_NAME KW47_A2_1_SDKFW4_0.sb3)
		else()
			message(FATAL_ERROR "No valid configuration could be selected for the S200 firmware.")
		endif()

		cmake_path(SET MCUX_S200_FW_BIN_PATH NORMALIZE ${MCUX_S200_FW_BIN_DIR}/${MCUX_S200_FW_BIN_NAME})

		# Make sure we have access to the binary blob
		if (NOT EXISTS ${MCUX_S200_FW_BIN_PATH})
			message(FATAL_ERROR "Cannot find S200 firmware file at ${MCUX_S200_FW_BIN_PATH}. Make sure to fetch the firmware blob via \"west blobs\".")
		endif()

		generate_inc_file_for_target(
			${ZEPHYR_CURRENT_LIBRARY}
			${MCUX_S200_FW_BIN_PATH}
			${ZEPHYR_BINARY_DIR}/include/generated/edgelock_firmware.inc
		)
	endif()
endif()

if(CONFIG_MCUX_SECURE_SUBSYSTEM_LEGACY_CONN_PORT)
	zephyr_include_directories(
		${MCUX_SECURE_SUBSYSTEM_PATH}/port/kw45_k4w1
	)

	zephyr_library_sources(
		${MCUX_SECURE_SUBSYSTEM_PATH}/port/kw45_k4w1/sss_aes_cmac.c
		${MCUX_SECURE_SUBSYSTEM_PATH}/port/kw45_k4w1/sss_aes.c
		${MCUX_SECURE_SUBSYSTEM_PATH}/port/kw45_k4w1/sss_ccm.c
		${MCUX_SECURE_SUBSYSTEM_PATH}/port/kw45_k4w1/sss_crypto.h
		${MCUX_SECURE_SUBSYSTEM_PATH}/port/kw45_k4w1/sss_ecdh.c
		${MCUX_SECURE_SUBSYSTEM_PATH}/port/kw45_k4w1/sss_hmac_sha256.c
		${MCUX_SECURE_SUBSYSTEM_PATH}/port/kw45_k4w1/sss_init.c
		${MCUX_SECURE_SUBSYSTEM_PATH}/port/kw45_k4w1/sss_sha256.c
	)
endif()

if(CONFIG_ENTROPY_NXP_ELE_TRNG)
	# Leave this empty for now. The initial (partial) upstreaming was done such
	# that it only depended on CONFIG_ENTROPY_NXP_ELE_TRNG and by default it
	# pulled in the legacy port/kw45_k4w1 layer just to initialize entropy.
	#
	# So, for now, we leave this commented out to see if anyone depended on the
	# implicit enablement of port/kw45_k4w1. If yes, then the below configs can
	# be uncommented as a possible hotfix.
	#
	# Best case, all of this gets promptly removed altogether.
	#
	# zephyr_include_directories(
	# 	${MCUX_SECURE_SUBSYSTEM_PATH}/port/kw45_k4w1
	# )
	# zephyr_library_sources(
	# 	${MCUX_SECURE_SUBSYSTEM_PATH}/port/kw45_k4w1/sss_init.c
	# )
endif()
