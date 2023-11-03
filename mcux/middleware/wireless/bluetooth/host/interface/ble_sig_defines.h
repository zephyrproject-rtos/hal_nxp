/*! *********************************************************************************
 * \addtogroup BLE
 * @{
 ********************************************************************************** */
/*! *********************************************************************************
* Copyright (c) 2014, Freescale Semiconductor, Inc.
* Copyright 2016-2019 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef BLE_SIG_DEFINES_H
#define BLE_SIG_DEFINES_H

/************************************************************************************
*************************************************************************************
* Public constants & macros
*************************************************************************************
************************************************************************************/

/*! Bluetooth SIG UUID constants for GATT declarations */

/*! Primary Service declaration UUID */
#define gBleSig_PrimaryService_d                0x2800U
/*! Secondary Service declaration UUID */
#define gBleSig_SecondaryService_d              0x2801U
/*! Include declaration UUID */
#define gBleSig_Include_d                       0x2802U
/*! Characteristic declaration UUID */
#define gBleSig_Characteristic_d                0x2803U

/*! Client Characteristic Configuration Descriptor declaration UUID */
#define gBleSig_CCCD_d                          0x2902U
/*! Server Characteristic Configuration Descriptor declaration UUID */
#define gBleSig_SCCD_d                          0x2903U
/*! Characteristic Presentation Format declaration UUID */
#define gBleSig_CharPresFormatDescriptor_d      0x2904U
/*! Valid Range Descriptor declaration UUID */
#define gBleSig_ValidRangeDescriptor_d          0x2906U


/*! GAP Service UUID */
#define gBleSig_GenericAccessProfile_d          0x1800U
/*! GATT Service UUID */
#define gBleSig_GenericAttributeProfile_d       0x1801U
/*! Immediate Alert Service UUID */
#define gBleSig_ImmediateAlertService_d         0x1802U
/*! Link Loss Service UUID */
#define gBleSig_LinkLossService_d               0x1803U
/*! Tx Power Service UUID */
#define gBleSig_TxPowerService_d                0x1804U
/*! Current Time Service UUID */
#define gBleSig_CurrentTimeService_d            0x1805U
/*! Reference Time Update Service UUID */
#define gBleSig_ReferenceTimeUpdateService_d    0x1806U
/*! Next DST Change Service UUID */
#define gBleSig_NextDSTChangeService_d          0x1807U
/*! Glucose Service UUID */
#define gBleSig_GlucoseService_d                0x1808U
/*! Health Thermometer Service UUID */
#define gBleSig_HealthThermometerService_d      0x1809U
/*! Device Information Service UUID */
#define gBleSig_DeviceInformationService_d      0x180AU
/*! Heart Rate Service UUID */
#define gBleSig_HeartRateService_d              0x180DU
/*! Phone Alert Status Service UUID */
#define gBleSig_PhoneAlertStatusService_d       0x180EU
/*! Battery Service UUID */
#define gBleSig_BatteryService_d                0x180FU
/*! Blood Pressure Service UUID */
#define gBleSig_BloodPressureService_d          0x1810U
/*! Alert Notification Service UUID */
#define gBleSig_AlertNotificationService_d      0x1811U
/*! HID Service UUID */
#define gBleSig_HidService_d                    0x1812U
/*! Running Speed And Cadence Service UUID */
#define gBleSig_RunningSpeedAndCadenceService_d 0x1814U
/*! Cycling Speed And Cadence Service UUID */
#define gBleSig_CyclingSpeedAndCadenceService_d 0x1816U
/*! Cycling Power Service UUID */
#define gBleSig_CyclingPowerService_d           0x1818U
/*! Location And Navigation Service UUID */
#define gBleSig_LocationAndNavigationService_d  0x1819U
/*! Internet Protocol Support Service UUID */
#define gBleSig_IpsService_d                    0x1820U
/*! Pulse Oximeter Service UUID */
#define gBleSig_PulseOximeterService_d          0x1822U
/*! HTTP Proxy Service UUID */
#define gBleSig_HTTPProxyService_d              0x1823U
/*! Wireless Power Transfer Service UUID */
#define gBleSig_WPTService_d                    0xFFFEU
/*! BTP Service UUID */
#define gBleSig_BtpService_d                    0xFEAFU

/*! GAP Device Name Characteristic UUID */
#define gBleSig_GapDeviceName_d                 0x2A00U
/*! GAP Appearance Characteristic UUID */
#define gBleSig_GapAppearance_d                 0x2A01U
/*! GAP Peripheral Preferred Connection Parameters Characteristic UUID */
#define gBleSig_GapPpcp_d                       0x2A04U
/*! GATT Service Changed Characteristic UUID */
#define gBleSig_GattServiceChanged_d            0x2A05U
/*! Alert Level Characteristic UUID */
#define gBleSig_AlertLevel_d                    0x2A06U
/*! TX Power Characteristic UUID */
#define gBleSig_TxPower_d                       0x2A07U
/*! Local Time Information Characteristic UUID */
#define gBleSig_LocalTimeInformation_d          0x2A0FU
/*! Time With DST Characteristic UUID */
#define gBleSig_TimeWithDST_d                   0x2A11U
/*! Reference Time Information Characteristic UUID */
#define gBleSig_ReferenceTimeInformation_d      0x2A14U
/*! Time Update Control Point Characteristic UUID */
#define gBleSig_TimeUpdateControlPoint_d        0x2A16U
/*! Time Update State Characteristic UUID */
#define gBleSig_TimeUpdateState_d               0x2A17U
/*! Glucose Measurement Characteristic UUID */
#define gBleSig_GlucoseMeasurement_d            0x2A18U
/*! Battery Level Characteristic UUID */
#define gBleSig_BatteryLevel_d                  0x2A19U
/*! Temperature Measurement Characteristic UUID */
#define gBleSig_TemperatureMeasurement_d        0x2A1CU
/*! Temperature Type Characteristic UUID */
#define gBleSig_TemperatureType_d               0x2A1DU
/*! Intermediate Temperature Characteristic UUID */
#define gBleSig_IntermediateTemperature_d       0x2A1EU
/*! Measurement Interval Characteristic UUID */
#define gBleSig_MeasurementInterval_d           0x2A21U
/*! System ID Characteristic UUID */
#define gBleSig_SystemId_d                      0x2A23U
/*! Model Number String Characteristic UUID */
#define gBleSig_ModelNumberString_d             0x2A24U
/*! Serial Number String Characteristic UUID */
#define gBleSig_SerialNumberString_d            0x2A25U
/*! Firmware Revision String Characteristic UUID */
#define gBleSig_FirmwareRevisionString_d        0x2A26U
/*! Hardware Revision String Characteristic UUID */
#define gBleSig_HardwareRevisionString_d        0x2A27U
/*! Software Revision String Characteristic UUID */
#define gBleSig_SoftwareRevisionString_d        0x2A28U
/*! Manufacturer Name String Characteristic UUID */
#define gBleSig_ManufacturerNameString_d        0x2A29U
/*! IEEE 11073-20601 Regulatory Certification Data List Characteristic UUID */
#define gBleSig_IeeeRcdl_d                      0x2A2AU
/*! Current Time Characteristic UUID */
#define gBleSig_CurrentTime_d                   0x2A2BU
/*! Boot Keyboard Input Report UUID */
#define gBleSig_BootKeyboardInputReport_d       0x2A22U
/*! Boot Keyboard output Report UUID */
#define gBleSig_BootKeyboardOutputReport_d      0x2A32U
/*! Boot Mouse Input Report UUID */
#define gBleSig_BootMouseInputReport_d          0x2A33U
/*! Glucose Measurement Context Characteristic UUID */
#define gBleSig_GlucoseMeasurementContext_d     0x2A34U
/*! Blood Pressure Measurement UUID */
#define gBleSig_BpMeasurement_d                 0x2A35U
/*! Intermediate Cuff Pressure UUID */
#define gBleSig_IntermediateCuffPressure_d      0x2A36U
/*! Heart Rate Measurement UUID */
#define gBleSig_HrMeasurement_d                 0x2A37U
/*! Body Sensor Location UUID */
#define gBleSig_BodySensorLocation_d            0x2A38U
/*! Heart Rate Control Point UUID */
#define gBleSig_HrControlPoint_d                0x2A39U
/*! Alert Status UUID */
#define gBleSig_AlertStatus_d                   0x2A3FU
/*! Ringer Control Point UUID */
#define gBleSig_RingerControlPoint_d            0x2A40U
/*! Ringer Setting UUID */
#define gBleSig_RingerSetting_d                 0x2A41U
/*! Alert Notif Control Point UUID */
#define gBleSig_AlertNotifControlPoint_d        0x2A44U
/*! Unread Alert Status UUID */
#define gBleSig_UnreadAlertStatus_d             0x2A45U
/*! New Alert UUID */
#define gBleSig_NewAlert_d                      0x2A46U
/*! Supported New Alert Category UUID */
#define gBleSig_SupportedNewAlertCategory_d     0x2A47U
/*! Supported Unread Alert Category UUID */
#define gBleSig_SupportedUnreadAlertCategory_d  0x2A48U
/*! Blood Pressure Feature UUID */
#define gBleSig_BloodPressureFeature_d          0x2A49U
/*! HID Information UUID */
#define gBleSig_HidInformation_d                0x2A4AU
/*! HID Control Point UUID */
#define gBleSig_HidCtrlPoint_d                  0x2A4CU
/*! Report UUID */
#define gBleSig_Report_d                        0x2A4DU
/*! Protocol Mode UUID */
#define gBleSig_ProtocolMode_d                  0x2A4EU
/*! Scan Interval Window UUID */
#define gBleSig_ScanIntervalWindow_d            0x2A4FU
/*! PnP Id UUID */
#define gBleSig_PnpId_d                         0x2A50U
/*! Glucose Feature Characteristic UUID */
#define gBleSig_GlucoseFeature_d                0x2A51U
/*! Record Access Ctrl Point Characteristic UUID */
#define gBleSig_RaCtrlPoint_d                   0x2A52U
/*! RSC Measurement UUID */
#define gBleSig_RscMeasurement_d                0x2A53U
/*! RSC Feature UUID */
#define gBleSig_RscFeature_d                    0x2A54U
/*! SC Control Point UUID */
#define gBleSig_ScControlPoint_d                0x2A55U
/*! CSC Measurement Characteristic UUID */
#define gBleSig_CscMeasurement_d                0x2A5BU
/*! CSC Feature Characteristic UUID */
#define gBleSig_CscFeature_d                    0x2A5CU
/*! Sensor Location Characteristic UUID */
#define gBleSig_SensorLocation_d                0x2A5DU
/*! PLX Spot-Check Measurement Characteristic UUID */
#define gBleSig_PlxSCMeasurement_d              0x2A5EU
/*! PLX Continuous Measurement Characteristic UUID */
#define gBleSig_PlxContMeasurement_d            0x2A5FU
/*! PLX Feature Characteristic UUID */
#define gBleSig_PulseOximeterFeature_d          0x2A60U
/*! CP Measurement Characteristic UUID */
#define gBleSig_CpMeasurement_d                 0x2A63U
/*! CP Measurement Vector UUID */
#define gBleSig_CpVector_d                      0x2A64U
/*! CP Feature CharacteristicUUID */
#define gBleSig_CpFeature_d                     0x2A65U
/*! CP Control Point UUID */
#define gBleSig_CpControlPoint_d                0x2A66U
/*! Location and Speed Characteristic UUID */
#define gBleSig_LocationAndSpeed_d              0x2A67U
/*! Navigation Characteristic UUID */
#define gBleSig_Navigation_d                    0x2A68U
/*! Position Quality Characteristic UUID */
#define gBleSig_PositionQuality_d               0x2A69U
/*! LN Feature Characteristic UUID */
#define gBleSig_LnFeature_d                     0x2A6AU
/*! LN Control Point Characteristic UUID */
#define gBleSig_LnControlPoint_d                0x2A6BU
/*! Temperature Characteristic UUID */
#define gBleSig_Temperature_d                   0x2A6EU
/*! Central Address Resolution Characteristic UUID */
#define gBleSig_CentralAddressResolution_d      0x2AA6U
/*! URI Characteristic UUID */
#define gBleSig_URI_d                           0x2AB6U
/*! HTTP Headers Characteristic UUID */
#define gBleSig_HTTP_Headers_d                  0x2AB7U
/*! HTTP Status Code Characteristic UUID */
#define gBleSig_HTTP_StatusCode_d               0x2AB8U
/*! HTTP Entity Body Characteristic UUID */
#define gBleSig_HTTP_EntityBody_d               0x2AB9U
/*! HTTP Control Point Characteristic UUID */
#define gBleSig_HTTP_ControlPoint_d             0x2ABAU
/*! HTTPS Security Characteristic UUID */
#define gBleSig_HTTPS_Security_d                0x2ABBU
/*! Resolvable Private Address Only Characteristic UUID */
#define gBleSig_ResolvablePrivateAddressOnly_d  0x2AC9U

/*! BLE Mesh Provisioning Service UUID */
#define gBleSig_MeshProvisioningService_d       0x1827U
/*! BLE Mesh Proxy Service UUID */
#define gBleSig_MeshProxyService_d              0x1828U
/*! BLE Mesh Prov Data In Char UUID */
#define gBleSig_MeshProvDataIn_d                0x2ADBU
/*! BLE Mesh Prov Data Out Char UUID */
#define gBleSig_MeshProvDataOut_d               0x2ADCU
/*! BLE Mesh Proxy Data In Char UUID */
#define gBleSig_MeshProxyDataIn_d               0x2ADDU
/*! BLE Mesh Proxy Data Out Char UUID */
#define gBleSig_MeshProxyDataOut_d              0x2ADEU

/*! Central Address Resolution Characteristic Values */
#define gBleSig_CAR_NotSupported_d              0x00U
#define gBleSig_CAR_Supported_d                 0x01U

/*! Resolvable Private Address Only Characteristic Values */
#define gBleSig_RPAO_Used_d                     0x00U

/*! Macro that returns whether or not an input 16-bit UUID is a grouping type. */
#define BleSig_IsGroupingAttributeUuid16(uuid16) \
 (((uuid16) == gBleSig_PrimaryService_d) || \
  ((uuid16) == gBleSig_SecondaryService_d) || \
  ((uuid16) == gBleSig_Include_d) || \
  ((uuid16) == gBleSig_Characteristic_d))

/*! Macro that returns whether or not an input 16-bit UUID is a Service declaration. */
#define BleSig_IsServiceDeclarationUuid16(uuid16) \
 (((uuid16) == gBleSig_PrimaryService_d) || \
  ((uuid16) == gBleSig_SecondaryService_d))

/*! Macro that declares a 16 bit UUID in a bleUuid_t union. */
#define Uuid16(uuid)   {.uuid16 = (uuid)}

/*! Macro that declares a 32 bit UUID in a bleUuid_t union. */
#define Uuid32(uuid)   {.uuid32 = (uuid)}

#define UuidArray(value)  ((value) & 0xFFU), ((value) >> 8U)
#endif /* BLE_SIG_DEFINES_H */

/*! *********************************************************************************
* @}
********************************************************************************** */
