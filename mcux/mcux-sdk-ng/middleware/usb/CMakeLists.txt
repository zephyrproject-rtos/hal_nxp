if(CONFIG_MCUX_COMPONENT_middleware.usb.common_header)
  mcux_add_include(INCLUDES include)
  mcux_add_source(SOURCES include/usb.h include/usb_misc.h include/usb_spec.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.common_header)
  mcux_add_include(INCLUDES device)
  mcux_add_source(SOURCES device/usb_device.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.khci)
  mcux_add_include(INCLUDES device)
  mcux_add_source(SOURCES device/usb_device_khci.c device/usb_device_khci.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.khci_config_header)
  mcux_add_include(INCLUDES config/device/khci TARGET_FILES
                   config/device/khci/usb_device_config.h)
  mcux_add_source(SOURCES config/device/khci/usb_device_config.h CONFIG TRUE)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.ehci)
  mcux_add_include(INCLUDES device)
  mcux_add_source(SOURCES device/usb_device_ehci.c device/usb_device_ehci.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.ehci_config_header)
  mcux_add_include(INCLUDES config/device/ehci TARGET_FILES
                   config/device/ehci/usb_device_config.h)
  mcux_add_source(SOURCES config/device/ehci/usb_device_config.h CONFIG TRUE)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.ip3511fs)
  mcux_add_include(INCLUDES device)
  mcux_add_source(SOURCES device/usb_device_lpcip3511.c
                  device/usb_device_lpcip3511.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.ip3511fs_config_header)
  mcux_add_include(INCLUDES config/device/ip3511fs TARGET_FILES
                   config/device/ip3511fs/usb_device_config.h)
  mcux_add_source(SOURCES config/device/ip3511fs/usb_device_config.h CONFIG
                  TRUE)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.ip3511hs)
  mcux_add_include(INCLUDES device)
  mcux_add_source(SOURCES device/usb_device_lpcip3511.c
                  device/usb_device_lpcip3511.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.ip3511hs_config_header)
  mcux_add_include(INCLUDES config/device/ip3511hs TARGET_FILES
                   config/device/ip3511hs/usb_device_config.h)
  mcux_add_source(SOURCES config/device/ip3511hs/usb_device_config.h CONFIG
                  TRUE)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.controller.driver)
  mcux_add_include(INCLUDES device)
  mcux_add_source(SOURCES device/usb_device_dci.c device/usb_device_dci.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.stack)
  mcux_add_include(INCLUDES device device/class)
  mcux_add_source(
    SOURCES device/usb_device_ch9.c device/usb_device_ch9.h
    device/class/usb_device_class.c device/class/usb_device_class.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.audio)
  mcux_add_include(INCLUDES device/class)
  mcux_add_source(SOURCES device/class/usb_device_audio.c
                  device/class/usb_device_audio.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.cdc)
  mcux_add_include(INCLUDES device/class)
  mcux_add_source(SOURCES device/class/usb_device_cdc_acm.c
                  device/class/usb_device_cdc_acm.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.cdc.ecm)
  mcux_add_include(INCLUDES device/class)
  mcux_add_source(SOURCES device/class/usb_device_cdc_ecm.c
                  device/class/usb_device_cdc_ecm.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.cdc.rndis)
  mcux_add_include(INCLUDES device/class)
  mcux_add_source(SOURCES device/class/usb_device_cdc_rndis.c
                  device/class/usb_device_cdc_rndis.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.hid)
  mcux_add_include(INCLUDES device/class)
  mcux_add_source(SOURCES device/class/usb_device_hid.c
                  device/class/usb_device_hid.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.dfu)
  mcux_add_include(INCLUDES device/class)
  mcux_add_source(SOURCES device/class/usb_device_dfu.c
                  device/class/usb_device_dfu.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.msd)
  mcux_add_include(INCLUDES device/class)
  mcux_add_source(
    SOURCES device/class/usb_device_msc.c device/class/usb_device_msc.h
    device/class/usb_device_msc_ufi.c device/class/usb_device_msc_ufi.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.mtp)
  mcux_add_include(INCLUDES device/class)
  mcux_add_source(
    SOURCES device/class/usb_device_mtp.c device/class/usb_device_mtp.h
    device/class/usb_device_mtp_operation.c
    device/class/usb_device_mtp_operation.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.phdc)
  mcux_add_include(INCLUDES device/class)
  mcux_add_source(SOURCES device/class/usb_device_phdc.c
                  device/class/usb_device_phdc.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.video)
  mcux_add_include(INCLUDES device/class)
  mcux_add_source(SOURCES device/class/usb_device_video.c
                  device/class/usb_device_video.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.ccid)
  mcux_add_include(INCLUDES device/class)
  mcux_add_source(SOURCES device/class/usb_device_ccid.c
                  device/class/usb_device_ccid.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.device.printer)
  mcux_add_include(INCLUDES device/class)
  mcux_add_source(SOURCES device/class/usb_device_printer.c
                  device/class/usb_device_printer.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.phy)
  mcux_add_include(INCLUDES phy)
  mcux_add_source(SOURCES phy/usb_phy.c phy/usb_phy.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.phydcd)
  mcux_add_include(INCLUDES dcd)
  mcux_add_source(SOURCES dcd/usb_phydcd.c dcd/usb_phydcd.h
                  dcd/usb_charger_detect.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.phydcd_config_header)
  mcux_add_include(INCLUDES config/dcd/phydcd TARGET_FILES
                   config/dcd/phydcd/usb_phydcd_config.h)
  mcux_add_source(SOURCES config/dcd/phydcd/usb_phydcd_config.h CONFIG TRUE)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.hsdcd)
  mcux_add_include(INCLUDES dcd)
  mcux_add_source(SOURCES dcd/usb_hsdcd.c dcd/usb_hsdcd.h
                  dcd/usb_charger_detect.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.hsdcd_config_header)
  mcux_add_include(INCLUDES config/dcd/hsdcd TARGET_FILES
                   config/dcd/hsdcd/usb_hsdcd_config.h)
  mcux_add_source(SOURCES config/dcd/hsdcd/usb_hsdcd_config.h CONFIG TRUE)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.common_header)
  mcux_add_include(INCLUDES host)
  mcux_add_source(SOURCES host/usb_host.h host/usb_host_hci.h
                  host/usb_host_devices.h host/usb_host_framework.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.khci)
  mcux_add_include(INCLUDES host)
  mcux_add_source(SOURCES host/usb_host_khci.c host/usb_host_khci.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.khci_config_header)
  mcux_add_include(INCLUDES config/host/khci TARGET_FILES
                   config/host/khci/usb_host_config.h)
  mcux_add_source(SOURCES config/host/khci/usb_host_config.h CONFIG TRUE)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.ehci)
  mcux_add_include(INCLUDES host)
  mcux_add_source(SOURCES host/usb_host_ehci.c host/usb_host_ehci.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.ehci_config_header)
  mcux_add_include(INCLUDES config/host/ehci TARGET_FILES
                   config/host/ehci/usb_host_config.h)
  mcux_add_source(SOURCES config/host/ehci/usb_host_config.h CONFIG TRUE)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.ohci)
  mcux_add_include(INCLUDES host)
  mcux_add_source(SOURCES host/usb_host_ohci.c host/usb_host_ohci.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.ohci_config_header)
  mcux_add_include(INCLUDES config/host/ohci TARGET_FILES
                   config/host/ohci/usb_host_config.h)
  mcux_add_source(SOURCES config/host/ohci/usb_host_config.h CONFIG TRUE)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.ip3516hs)
  mcux_add_include(INCLUDES host)
  mcux_add_source(SOURCES host/usb_host_ip3516hs.c host/usb_host_ip3516hs.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.ip3516hs_config_header)
  mcux_add_include(INCLUDES config/host/ip3516hs TARGET_FILES
                   config/host/ip3516hs/usb_host_config.h)
  mcux_add_source(SOURCES config/host/ip3516hs/usb_host_config.h CONFIG TRUE)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.stack)
  mcux_add_include(INCLUDES host host/class)
  mcux_add_source(
    SOURCES
    host/usb_host_hci.c
    host/usb_host_devices.c
    host/usb_host_framework.c
    host/class/usb_host_hub.c
    host/class/usb_host_hub.h
    host/class/usb_host_hub_app.c
    host/class/usb_host_hub_app.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.audio)
  mcux_add_include(INCLUDES host/class)
  mcux_add_source(SOURCES host/class/usb_host_audio.c
                  host/class/usb_host_audio.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.cdc)
  mcux_add_include(INCLUDES host/class)
  mcux_add_source(SOURCES host/class/usb_host_cdc.c host/class/usb_host_cdc.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.cdc_ecm)
  mcux_add_include(INCLUDES host/class)
  mcux_add_source(SOURCES host/class/usb_host_cdc_ecm.c
                  host/class/usb_host_cdc_ecm.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.cdc_rndis)
  mcux_add_include(INCLUDES host/class)
  mcux_add_source(SOURCES host/class/usb_host_cdc_rndis.c
                  host/class/usb_host_cdc_rndis.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.hid)
  mcux_add_include(INCLUDES host/class)
  mcux_add_source(SOURCES host/class/usb_host_hid.c host/class/usb_host_hid.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.msd)
  mcux_add_include(INCLUDES host/class)
  mcux_add_source(SOURCES host/class/usb_host_msd.c host/class/usb_host_msd.h
                  host/class/usb_host_msd_ufi.c)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.video)
  mcux_add_include(INCLUDES host/class)
  mcux_add_source(SOURCES host/class/usb_host_video.c
                  host/class/usb_host_video.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.phdc)
  mcux_add_include(INCLUDES host/class)
  mcux_add_source(SOURCES host/class/usb_host_phdc.c host/class/usb_host_phdc.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb.host.printer)
  mcux_add_include(INCLUDES host/class)
  mcux_add_source(SOURCES host/class/usb_host_printer.c
                  host/class/usb_host_printer.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb_pd)
  mcux_add_include(INCLUDES pd)
  mcux_add_source(
    SOURCES
    pd/usb_pd.h
    pd/usb_pd_connect.c
    pd/usb_pd_interface.h
    pd/usb_pd_interface.c
    pd/usb_pd_msg.c
    pd/usb_pd_phy.h
    pd/usb_pd_policy.c
    pd/usb_pd_spec.h
    pd/usb_pd_timer.c
    pd/usb_pd_timer.h
    pd/usb_pd_auto_policy.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb_pd.config_header)
  mcux_add_include(INCLUDES config/pd TARGET_FILES config/pd/usb_pd_config.h)
  mcux_add_source(SOURCES config/pd/usb_pd_config.h CONFIG TRUE)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb_pd.phy.ptn5110)
  mcux_add_include(INCLUDES pd pd/ptn5110 pd/phy_interface)
  mcux_add_source(
    SOURCES
    pd/ptn5110/usb_pd_ptn5110.h
    pd/ptn5110/usb_pd_ptn5110_connect.c
    pd/ptn5110/usb_pd_ptn5110_hal.c
    pd/ptn5110/usb_pd_ptn5110_interface.c
    pd/ptn5110/usb_pd_ptn5110_msg.c
    pd/ptn5110/usb_pd_ptn5110_register.h
    pd/usb_pd_timer.c
    pd/phy_interface/usb_pd_i2c.h
    pd/phy_interface/usb_pd_i2c.c)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb_pd.altmode)
  mcux_add_include(INCLUDES pd/alt_mode)
  mcux_add_source(
    SOURCES pd/alt_mode/usb_pd_alt_mode.c pd/alt_mode/usb_pd_alt_mode.h
    pd/alt_mode/usb_pd_alt_mode_dp.c pd/alt_mode/usb_pd_alt_mode_dp.h)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.usb_pd.compliance_test_report)
  mcux_add_source(
    SOURCES
    "pd/compliance_test_report/ellisys/consumer_provider/USB Compliance Report.html"
    "pd/compliance_test_report/ellisys/drp/USB Compliance Report.html"
    "pd/compliance_test_report/ellisys/drp_try_snk/USB Compliance Report.html"
    "pd/compliance_test_report/ellisys/drp_try_src/USB Compliance Report.html"
    "pd/compliance_test_report/ellisys/provider_consumer/USB Compliance Report.html"
    "pd/compliance_test_report/ellisys/displayport_dock/USB Compliance Report.html"
    "pd/compliance_test_report/ellisys/displayport_host/USB Compliance Report.html"
  )
endif()
