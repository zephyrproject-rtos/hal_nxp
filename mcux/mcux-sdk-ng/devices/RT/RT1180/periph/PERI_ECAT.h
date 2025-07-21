/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ECAT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ECAT.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ECAT
 *
 * CMSIS Peripheral Access Layer for ECAT
 */

#if !defined(PERI_ECAT_H_)
#define PERI_ECAT_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ECAT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ECAT_Peripheral_Access_Layer ECAT Peripheral Access Layer
 * @{
 */

/** ECAT - Size of Registers Arrays */
#define ECAT_RX_ERROR_CNTR_COUNT                  2u
#define ECAT_FORWARDED_RX_ERROR_CNTR_COUNT        2u
#define ECAT_LOST_LINK_CNTR_COUNT                 2u
#define ECAT_PHY_PORT_STATUS_COUNT                2u
#define ECAT_FMMU_COUNT                           8u
#define ECAT_SYNCMANAGER_COUNT                    16u

/** ECAT - Register Layout Typedef */
typedef struct {
  __I  uint8_t TYPE;                               /**< Type, offset: 0x0 */
  __I  uint8_t REVISION;                           /**< Revision, offset: 0x1 */
  __I  uint16_t BUILD;                             /**< Build, offset: 0x2 */
  __I  uint8_t FMMUS_SUPPORTED;                    /**< FMMUs supported, offset: 0x4 */
  __I  uint8_t SYNCMANAGERS_SUPPORTED;             /**< SyncManagers supported, offset: 0x5 */
  __I  uint8_t RAM_SIZE;                           /**< RAM Size, offset: 0x6 */
  __I  uint8_t PORT_DESCRIPTOR;                    /**< Port configuration, offset: 0x7 */
  __I  uint16_t ESC_FEATURES_SUPPORTED;            /**< Register ESC Features supported, offset: 0x8 */
       uint8_t RESERVED_0[6];
  union {                                          /* offset: 0x10 */
    __IO uint16_t CONFIGURED_STATION_ADDRESS;        /**< Configured Station Address, offset: 0x10 */
    __I  uint16_t CONFIGURED_STATION_ADDRESS_PDI;    /**< Configured Station Address, offset: 0x10 */
  };
  union {                                          /* offset: 0x12 */
    __I  uint16_t CONFIGURED_STATION_ALIAS;          /**< Configured Station Alias, offset: 0x12 */
    __IO uint16_t CONFIGURED_STATION_ALIAS_PDI;      /**< Configured Station Alias, offset: 0x12 */
  };
       uint8_t RESERVED_1[12];
  union {                                          /* offset: 0x20 */
    __IO uint8_t REGISTER_WRITE_ENABLE;              /**< Register Write Enable, offset: 0x20 */
    __I  uint8_t REGISTER_WRITE_ENABLE_PDI;          /**< Register Write Enable, offset: 0x20 */
  };
  union {                                          /* offset: 0x21 */
    __IO uint8_t REGISTER_WRITE_PROTECTION;          /**< Register Write Protection, offset: 0x21 */
    __I  uint8_t REGISTER_WRITE_PROTECTION_PDI;      /**< Register Write Protection, offset: 0x21 */
  };
       uint8_t RESERVED_2[14];
  union {                                          /* offset: 0x30 */
    __IO uint8_t ESC_WRITE_ENABLE;                   /**< ESC Write Enable, offset: 0x30 */
    __I  uint8_t ESC_WRITE_ENABLE_PDI;               /**< ESC Write Enable, offset: 0x30 */
  };
  union {                                          /* offset: 0x31 */
    __IO uint8_t ESC_WRITE_PROTECTION;               /**< ESC Write Protection, offset: 0x31 */
    __I  uint8_t ESC_WRITE_PROTECTION_PDI;           /**< ESC Write Protection, offset: 0x31 */
  };
       uint8_t RESERVED_3[14];
  union {                                          /* offset: 0x40 */
    __IO uint8_t ESC_RESET_ECAT_WRITE;               /**< ESC Reset ECAT WRITE, offset: 0x40 */
    __I  uint8_t ESC_RESET_ECAT_WRITE_PDI;           /**< ESC Reset ECAT WRITE, offset: 0x40 */
  };
  union {                                          /* offset: 0x41 */
    __I  uint8_t ESC_RESET_PDI_WRITE;                /**< ESC Reset PDI WRITE, offset: 0x41 */
    __IO uint8_t ESC_RESET_PDI_WRITE_PDI;            /**< ESC Reset PDI WRITE, offset: 0x41 */
  };
       uint8_t RESERVED_4[190];
  union {                                          /* offset: 0x100 */
    __IO uint32_t ESC_DL_CONTROL;                    /**< ESC DL Control, offset: 0x100 */
    __I  uint32_t ESC_DL_CONTROL_PDI;                /**< ESC DL Control, offset: 0x100 */
  };
       uint8_t RESERVED_5[4];
  union {                                          /* offset: 0x108 */
    __IO uint16_t PHYSICAL_READ_WRITE_OFFSET;        /**< Physical Read Write Offset, offset: 0x108 */
    __I  uint16_t PHYSICAL_READ_WRITE_OFFSET_PDI;    /**< Physical Read Write Offset, offset: 0x108 */
  };
       uint8_t RESERVED_6[6];
  __I  uint16_t ESC_DL_STATUS;                     /**< ESC DL Status, offset: 0x110 */
       uint8_t RESERVED_7[14];
  union {                                          /* offset: 0x120 */
    __IO uint16_t AL_CONTROL;                        /**< AL Control, offset: 0x120 */
    __I  uint16_t AL_CONTROL_PDI;                    /**< AL Control, offset: 0x120 */
  };
       uint8_t RESERVED_8[14];
  union {                                          /* offset: 0x130 */
    __I  uint16_t AL_STATUS;                         /**< AL Status, offset: 0x130 */
    __IO uint16_t AL_STATUS_PDI;                     /**< AL Status, offset: 0x130 */
  };
       uint8_t RESERVED_9[2];
  union {                                          /* offset: 0x134 */
    __I  uint16_t AL_STATUS_CODE;                    /**< AL Status Code, offset: 0x134 */
    __IO uint16_t AL_STATUS_CODE_PDI;                /**< AL Status Code, offset: 0x134 */
  };
       uint8_t RESERVED_10[2];
  __IO uint8_t RUN_LED_OVERRIDE;                   /**< RUN LED Override, offset: 0x138 */
  __IO uint8_t ERR_LED_OVERRIDE;                   /**< ERR LED Override, offset: 0x139 */
       uint8_t RESERVED_11[6];
  __I  uint8_t PDI_CONTROL;                        /**< PDI Control, offset: 0x140 */
  __I  uint8_t ESC_CONFIGURATION;                  /**< ESC Configuration, offset: 0x141 */
       uint8_t RESERVED_12[12];
  __I  uint16_t PDI_INFORMATION;                   /**< PDI Information, offset: 0x14E */
  __I  uint8_t PDI_ON_CHIP_BUS_CONFIGURATION;      /**< Register PDI On-chip bus configuration, offset: 0x150 */
  __I  uint8_t SYNC_LATCH_1_AND_0_PDI_CONFIGURATION; /**< PDI Configuration Sync Latch 1 and 0 PDI Configuration, offset: 0x151 */
  __I  uint16_t PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION; /**< Register PDI On-chip bus extended configuration., offset: 0x152 */
       uint8_t RESERVED_13[172];
  union {                                          /* offset: 0x200 */
    __IO uint16_t ECAT_EVENT_MASK;                   /**< ECAT Event Mask, offset: 0x200 */
    __I  uint16_t ECAT_EVENT_MASK_PDI;               /**< ECAT Event Mask, offset: 0x200 */
  };
       uint8_t RESERVED_14[2];
  union {                                          /* offset: 0x204 */
    __I  uint32_t PDI_AL_EVENT_MASK;                 /**< PDI AL Event Mask, offset: 0x204 */
    __IO uint32_t PDI_AL_EVENT_MASK_PDI;             /**< PDI AL Event Mask, offset: 0x204 */
  };
       uint8_t RESERVED_15[8];
  __I  uint16_t ECAT_EVENT_REQUEST;                /**< ECAT Event Request, offset: 0x210 */
       uint8_t RESERVED_16[14];
  __I  uint32_t AL_EVENT_REQUEST;                  /**< AL Event request, offset: 0x220 */
       uint8_t RESERVED_17[220];
  union {                                          /* offset: 0x300, array step: 0x2 */
    __IO uint16_t RX_ERROR_COUNTER_PORT[ECAT_RX_ERROR_CNTR_COUNT];   /**< RX Error Counter, array offset: 0x300, array step: 0x2 */
    __I  uint16_t RX_ERROR_COUNTER_PORT_PDI[ECAT_RX_ERROR_CNTR_COUNT];   /**< RX Error Counter, array offset: 0x300, array step: 0x2 */
  };
       uint8_t RESERVED_18[4];
  union {                                          /* offset: 0x308, array step: 0x1 */
    __IO uint8_t FORWARDED_RX_ERROR_COUNTER_PORT[ECAT_FORWARDED_RX_ERROR_CNTR_COUNT];   /**< Forwarded RX Error Counter, array offset: 0x308, array step: 0x1 */
    __I  uint8_t FORWARDED_RX_ERROR_COUNTER_PORT_PDI[ECAT_FORWARDED_RX_ERROR_CNTR_COUNT];   /**< Forwarded RX Error Counter, array offset: 0x308, array step: 0x1 */
  };
       uint8_t RESERVED_19[2];
  union {                                          /* offset: 0x30C */
    __IO uint8_t ECAT_PROCESSING_UNIT_ERROR_COUNTER;   /**< ECAT Processing Unit Error Counter, offset: 0x30C */
    __I  uint8_t ECAT_PROCESSING_UNIT_ERROR_COUNTER_PDI;   /**< ECAT Processing Unit Error Counter, offset: 0x30C */
  };
  union {                                          /* offset: 0x30D */
    __IO uint8_t PDI_ERROR_COUNTER;                  /**< PDI Error counter, offset: 0x30D */
    __I  uint8_t PDI_ERROR_COUNTER_PDI;              /**< PDI Error counter, offset: 0x30D */
  };
  __I  uint8_t ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER; /**< ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_PDI_ERROR_CODE., offset: 0x30E */
       uint8_t RESERVED_20[1];
  union {                                          /* offset: 0x310, array step: 0x1 */
    __IO uint8_t LOST_LINK_COUNTER_PORT[ECAT_LOST_LINK_CNTR_COUNT];   /**< Lost Link Counter, array offset: 0x310, array step: 0x1 */
    __I  uint8_t LOST_LINK_COUNTER_PORT_PDI[ECAT_LOST_LINK_CNTR_COUNT];   /**< Lost Link Counter, array offset: 0x310, array step: 0x1 */
  };
       uint8_t RESERVED_21[238];
  union {                                          /* offset: 0x400 */
    __IO uint16_t WATCHDOG_DIVIDER;                  /**< Watchdog Divider, offset: 0x400 */
    __I  uint16_t WATCHDOG_DIVIDER_PDI;              /**< Watchdog Divider, offset: 0x400 */
  };
       uint8_t RESERVED_22[14];
  union {                                          /* offset: 0x410 */
    __IO uint16_t WATCHDOG_TIME_PDI;                 /**< Register Watchdog Time PDI, offset: 0x410 */
    __I  uint16_t WATCHDOG_TIME_PDI_PDI;             /**< Register Watchdog Time PDI, offset: 0x410 */
  };
       uint8_t RESERVED_23[14];
  union {                                          /* offset: 0x420 */
    __IO uint16_t WATCHDOG_TIME_PROCESS_DATA;        /**< Regsister Watchdog Time Process Data, offset: 0x420 */
    __I  uint16_t WATCHDOG_TIME_PROCESS_DATA_PDI;    /**< Regsister Watchdog Time Process Data, offset: 0x420 */
  };
       uint8_t RESERVED_24[30];
  __I  uint16_t WATCHDOG_STATUS_PROCESS_DATA;      /**< Watchdog Status Process Data, offset: 0x440 */
  union {                                          /* offset: 0x442 */
    __IO uint8_t WATCHDOG_COUNTER_PROCESS_DATA;      /**< Watchdog Counter Process Data, offset: 0x442 */
    __I  uint8_t WATCHDOG_COUNTER_PROCESS_DATA_PDI;   /**< Watchdog Counter Process Data, offset: 0x442 */
  };
  union {                                          /* offset: 0x443 */
    __IO uint8_t WATCHDOG_COUNTER_PDI;               /**< Watchdog Counter PDI, offset: 0x443 */
    __I  uint8_t WATCHDOG_COUNTER_PDI_PDI;           /**< Watchdog Counter PDI, offset: 0x443 */
  };
       uint8_t RESERVED_25[188];
  union {                                          /* offset: 0x500 */
    __IO uint8_t EEPROM_CONFIGURATION;               /**< EEPROM Configuration, offset: 0x500 */
    __I  uint8_t EEPROM_CONFIGURATION_PDI;           /**< EEPROM Configuration, offset: 0x500 */
  };
  union {                                          /* offset: 0x501 */
    __I  uint8_t REGISTER_EEPROM_PDI_ACCESS_STATE;   /**< EEPROM PDI Access State, offset: 0x501 */
    __IO uint8_t REGISTER_EEPROM_PDI_ACCESS_STATE_PDI;   /**< EEPROM PDI Access State, offset: 0x501 */
  };
  union {                                          /* offset: 0x502 */
    __IO uint16_t EEPROM_CONTROL_STATUS;             /**< Register EEPROM Control/Status, offset: 0x502 */
    __IO uint16_t EEPROM_CONTROL_STATUS_PDI;         /**< Register EEPROM Control/Status, offset: 0x502 */
  };
  __IO uint32_t EEPROM_ADDRESS;                    /**< EEPROM Address, offset: 0x504 */
  __IO uint64_t EEPROM_DATA;                       /**< EEPROM Data, offset: 0x508 */
  union {                                          /* offset: 0x510 */
    __IO uint16_t MII_MANAGEMENT_CONTROL_OR_STATUS;   /**< MII Management Control/Status, offset: 0x510 */
    __IO uint16_t MII_MANAGEMENT_CONTROL_OR_STATUS_PDI;   /**< MII Management Control/Status, offset: 0x510 */
  };
  __IO uint8_t PHY_ADDRESS;                        /**< PHY Address, offset: 0x512 */
  __IO uint8_t PHY_REGISTER_ADDRESS;               /**< PHY Register Address, offset: 0x513 */
  __IO uint16_t PHY_DATA;                          /**< PHY Data, offset: 0x514 */
  union {                                          /* offset: 0x516 */
    __IO uint8_t MII_MANAGEMENT_ECAT_ACCESS_STATE;   /**< MII Management ECAT Access State, offset: 0x516 */
    __I  uint8_t MII_MANAGEMENT_ECAT_ACCESS_STATE_PDI;   /**< MII Management ECAT Access State, offset: 0x516 */
  };
  union {                                          /* offset: 0x517 */
    __IO uint8_t MII_MANAGEMENT_PDI_ACCESS_STATE;    /**< MII Management PDI Access State, offset: 0x517 */
    __IO uint8_t MII_MANAGEMENT_PDI_ACCESS_STATE_PDI;   /**< MII Management PDI Access State, offset: 0x517 */
  };
  __IO uint8_t PHY_PORT_STATUS[ECAT_PHY_PORT_STATUS_COUNT]; /**< PHY Port, array offset: 0x518, array step: 0x1 */
       uint8_t RESERVED_26[230];
  struct {                                         /* offset: 0x600, array step: 0x10 */
    union {                                          /* offset: 0x600, array step: 0x10 */
      __IO uint32_t LOGICAL_START_ADDRESS;             /**< Register Logical Start address FMMU, array offset: 0x600, array step: 0x10 */
      __I  uint32_t LOGICAL_START_ADDRESS_PDI;         /**< Register Logical Start address FMMU, array offset: 0x600, array step: 0x10 */
    };
    union {                                          /* offset: 0x604, array step: 0x10 */
      __IO uint16_t LENGTH;                            /**< Register Length FMMU, array offset: 0x604, array step: 0x10 */
      __I  uint16_t LENGTH_PDI;                        /**< Register Length FMMU, array offset: 0x604, array step: 0x10 */
    };
    union {                                          /* offset: 0x606, array step: 0x10 */
      __IO uint8_t LOGICAL_START_BIT;                  /**< Register Start bit FMMU y in logical address space, array offset: 0x606, array step: 0x10 */
      __I  uint8_t LOGICAL_START_BIT_PDI;              /**< Register Start bit FMMU y in logical address space, array offset: 0x606, array step: 0x10 */
    };
    union {                                          /* offset: 0x607, array step: 0x10 */
      __IO uint8_t LOGICAL_STOP_BIT;                   /**< Register Stop bit FMMU y in logical address space, array offset: 0x607, array step: 0x10 */
      __I  uint8_t LOGICAL_STOP_BIT_PDI;               /**< Register Stop bit FMMU y in logical address space, array offset: 0x607, array step: 0x10 */
    };
    union {                                          /* offset: 0x608, array step: 0x10 */
      __IO uint16_t PHYSICAL_START_ADDRESS;            /**< Register Physical Start address FMMU, array offset: 0x608, array step: 0x10 */
      __I  uint16_t PHYSICAL_START_ADDRESS_PDI;        /**< Register Physical Start address FMMU, array offset: 0x608, array step: 0x10 */
    };
    union {                                          /* offset: 0x60A, array step: 0x10 */
      __IO uint8_t PHYSICAL_START_BIT;                 /**< Register Physical Start bit FMMU, array offset: 0x60A, array step: 0x10 */
      __I  uint8_t PHYSICAL_START_BIT_PDI;             /**< Register Physical Start bit FMMU, array offset: 0x60A, array step: 0x10 */
    };
    union {                                          /* offset: 0x60B, array step: 0x10 */
      __IO uint8_t TYPE;                               /**< Register Type FMMU y, array offset: 0x60B, array step: 0x10 */
      __I  uint8_t TYPE_PDI;                           /**< Register Type FMMU y, array offset: 0x60B, array step: 0x10 */
    };
    union {                                          /* offset: 0x60C, array step: 0x10 */
      __IO uint8_t ACTIVATE;                           /**< Register Activate FMMU, array offset: 0x60C, array step: 0x10 */
      __I  uint8_t ACTIVATE_PDI;                       /**< Register Activate FMMU, array offset: 0x60C, array step: 0x10 */
    };
         uint8_t RESERVED_0[3];
  } FMMU[ECAT_FMMU_COUNT];
       uint8_t RESERVED_27[384];
  struct {                                         /* offset: 0x800, array step: 0x8 */
    union {                                          /* offset: 0x800, array step: 0x8 */
      __IO uint16_t PHYSICAL_START_ADDRESS;            /**< Register physical Start Address SyncManager, array offset: 0x800, array step: 0x8 */
      __I  uint16_t PHYSICAL_START_ADDRESS_PDI;        /**< Register physical Start Address SyncManager, array offset: 0x800, array step: 0x8 */
    };
    union {                                          /* offset: 0x802, array step: 0x8 */
      __IO uint16_t LENGTH;                            /**< Register Length SyncManager, array offset: 0x802, array step: 0x8 */
      __I  uint16_t LENGTH_PDI;                        /**< Register Length SyncManager, array offset: 0x802, array step: 0x8 */
    };
    union {                                          /* offset: 0x804, array step: 0x8 */
      __IO uint8_t CONTROL_REGISTER;                   /**< Register Control Register SyncManager, array offset: 0x804, array step: 0x8 */
      __I  uint8_t CONTROL_REGISTER_PDI;               /**< Register Control Register SyncManager, array offset: 0x804, array step: 0x8 */
    };
    __I  uint8_t STATUS;                             /**< Register Status Register SyncManager, array offset: 0x805, array step: 0x8 */
    union {                                          /* offset: 0x806, array step: 0x8 */
      __IO uint8_t ACTIVATE;                           /**< Register Activate SyncManager, array offset: 0x806, array step: 0x8 */
      __I  uint8_t ACTIVATE_PDI;                       /**< Register Activate SyncManager, array offset: 0x806, array step: 0x8 */
    };
    union {                                          /* offset: 0x807, array step: 0x8 */
      __I  uint8_t PDI_CONTROL;                        /**< Register PDI Control SyncManager, array offset: 0x807, array step: 0x8 */
      __IO uint8_t PDI_CONTROL_PDI;                    /**< Register PDI Control SyncManager, array offset: 0x807, array step: 0x8 */
    };
  } SYNCMANAGER[ECAT_SYNCMANAGER_COUNT];
       uint8_t RESERVED_28[128];
  union {                                          /* offset: 0x900 */
    __IO uint32_t RECEIVE_TIMES;                     /**< Distributed Clocks Receive Times, offset: 0x900 */
    __I  uint32_t RECEIVE_TIMES_PDI;                 /**< Distributed Clocks Receive Times, offset: 0x900 */
  };
  __I  uint32_t RECEIVE_TIME_PORT_1;               /**< Distributed Clocks Receive Time Port 1, offset: 0x904 */
       uint8_t RESERVED_29[8];
  union {                                          /* offset: 0x910 */
    __IO uint64_t SYSTEM_TIME;                       /**< Register System Time, offset: 0x910 */
    __IO uint64_t SYSTEM_TIME_PDI;                   /**< Register System Time, offset: 0x910 */
  };
  __I  uint64_t RECEIVE_TIME_ECAT_PROCESSING_UNIT; /**< Distributed Clocks Register Receive Time ECAT Processing Unit, offset: 0x918 */
  __IO uint64_t SYSTEM_TIME_OFFSET;                /**< Register System Time Offset, offset: 0x920 */
  __IO uint32_t SYSTEM_TIME_DELAY;                 /**< Register System Time Delay, offset: 0x928 */
  __I  uint32_t SYSTEM_TIME_DIFFERENCE;            /**< Register System Time Difference, offset: 0x92C */
  __IO uint16_t SPEED_COUNTER_START;               /**< Register Speed Counter Start, offset: 0x930 */
  __I  uint16_t SPEED_COUNTER_DIFF;                /**< Register Speed Counter Diff, offset: 0x932 */
  __IO uint8_t SYSTEM_TIME_DIFFERENCE_FILTER_DEPTH; /**< Register System Time Difference Filter Depth, offset: 0x934 */
  __IO uint8_t SPEED_COUNTER_FILTER_DEPTH;         /**< Register Speed Counter Filter Depth, offset: 0x935 */
       uint8_t RESERVED_30[74];
  union {                                          /* offset: 0x980 */
    __IO uint8_t CYCLIC_UNIT_CONTROL;                /**< Register Cyclic Unit Control, offset: 0x980 */
    __I  uint8_t CYCLIC_UNIT_CONTROL_PDI;            /**< Register Cyclic Unit Control, offset: 0x980 */
  };
  __IO uint8_t UNIT_ACTIVATION_REGISTER;           /**< Register Activation register, offset: 0x981 */
  __I  uint16_t UNI_PULSE_LENGTH_OF_SYNCSIGNALS;   /**< Register Pulse Length of SyncSignals, offset: 0x982 */
  __I  uint8_t UNIT_ACTIVATION_STATUS;             /**< Register Activation Status, offset: 0x984 */
       uint8_t RESERVED_31[9];
  __I  uint8_t UNIT_SYNC0_STATUS;                  /**< Register SYNC0 Status, offset: 0x98E */
  __I  uint8_t UNIT_SYNC1_STATUS;                  /**< Register SYNC1 Status, offset: 0x98F */
  __IO uint64_t UNIT_START_TIME_CYCLIC_OPERATION;  /**< Register Start Time Cyclic Operation, offset: 0x990 */
  __I  uint64_t UNIT_NEXT_SYNC1_PULSE;             /**< Register Next SYNC1 Pulse, offset: 0x998 */
  __IO uint32_t UNIT_SYNC0_CYCLE_TIME;             /**< Register SYNC0 Cycle Time, offset: 0x9A0 */
  __IO uint32_t UNIT_SYNC1_CYCLE_TIME;             /**< Register SYNC1 Cycle Time, offset: 0x9A4 */
  __IO uint8_t LATCH0_CONTROL;                     /**< Register Latch0 Control, offset: 0x9A8 */
  __IO uint8_t LATCH1_CONTROL;                     /**< Register Latch1 Control, offset: 0x9A9 */
       uint8_t RESERVED_32[4];
  __I  uint8_t LATCH0_STATUS;                      /**< Register Latch0 Status, offset: 0x9AE */
  __I  uint8_t LATCH1_STATUS;                      /**< Register Latch1 Status, offset: 0x9AF */
  __I  uint64_t LATCH0_TIME_POSITIVE_EDGE;         /**< Register Latch0 Time Positive Edge, offset: 0x9B0 */
  __I  uint64_t LATCH0_TIME_NEGATIVE_EDGE;         /**< Register Latch0 Time Negative Edge, offset: 0x9B8 */
  __I  uint64_t LATCH1_TIME_POSITIVE_EDGE;         /**< Register Latch1 Time Positive Edge, offset: 0x9C0 */
  __I  uint64_t LATCH1_TIME_NEGATIVE_EDGE;         /**< Register Latch1 Time Negative Edge, offset: 0x9C8 */
       uint8_t RESERVED_33[32];
  __I  uint32_t ETHERCAT_BUFFER_CHANGE_EVENT_TIME; /**< Register EtherCAT Buffer Change Event Time, offset: 0x9F0 */
       uint8_t RESERVED_34[4];
  __I  uint32_t PDI_BUFFER_START_EVENT_TIME;       /**< Register PDI Buffer Start Event Time, offset: 0x9F8 */
  __I  uint32_t PDI_BUFFER_CHANGE_EVENT_TIME;      /**< Register PDI Buffer Change Event Time, offset: 0x9FC */
       uint8_t RESERVED_35[1024];
  __I  uint64_t PRODUCT_ID_IP_CORE;                /**< Register Product ID IP Core, offset: 0xE00 */
  __I  uint64_t VENDOR_ID_IP_CORE;                 /**< Register Vendor ID IP Core, offset: 0xE08 */
       uint8_t RESERVED_36[256];
  __IO uint16_t GENERAL_PURPOSE_OUTPUTS;           /**< Register General Purpose Outputs, offset: 0xF10 */
       uint8_t RESERVED_37[6];
  __I  uint16_t GENERAL_PURPOSE_INPUTS;            /**< Register General Purpose Inputs, offset: 0xF18 */
} ECAT_Type;

/* ----------------------------------------------------------------------------
   -- ECAT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ECAT_Register_Masks ECAT Register Masks
 * @{
 */

/*! @name TYPE - Type */
/*! @{ */

#define ECAT_TYPE_BF0_MASK                       (0xFFU)
#define ECAT_TYPE_BF0_SHIFT                      (0U)
/*! BF0 - Type of EtherCAT controller */
#define ECAT_TYPE_BF0(x)                         (((uint8_t)(((uint8_t)(x)) << ECAT_TYPE_BF0_SHIFT)) & ECAT_TYPE_BF0_MASK)
/*! @} */

/*! @name REVISION - Revision */
/*! @{ */

#define ECAT_REVISION_BF0_MASK                   (0xFFU)
#define ECAT_REVISION_BF0_SHIFT                  (0U)
/*! BF0 - Revision of EtherCAT controller. */
#define ECAT_REVISION_BF0(x)                     (((uint8_t)(((uint8_t)(x)) << ECAT_REVISION_BF0_SHIFT)) & ECAT_REVISION_BF0_MASK)
/*! @} */

/*! @name BUILD - Build */
/*! @{ */

#define ECAT_BUILD_BF0_MASK                      (0xFFFFU)
#define ECAT_BUILD_BF0_SHIFT                     (0U)
/*! BF0 - Build of EtherCAT controller */
#define ECAT_BUILD_BF0(x)                        (((uint16_t)(((uint16_t)(x)) << ECAT_BUILD_BF0_SHIFT)) & ECAT_BUILD_BF0_MASK)
/*! @} */

/*! @name FMMUS_SUPPORTED - FMMUs supported */
/*! @{ */

#define ECAT_FMMUS_SUPPORTED_BF0_MASK            (0xFFU)
#define ECAT_FMMUS_SUPPORTED_BF0_SHIFT           (0U)
/*! BF0 - Number of supported FMMU channels (or entities) */
#define ECAT_FMMUS_SUPPORTED_BF0(x)              (((uint8_t)(((uint8_t)(x)) << ECAT_FMMUS_SUPPORTED_BF0_SHIFT)) & ECAT_FMMUS_SUPPORTED_BF0_MASK)
/*! @} */

/*! @name SYNCMANAGERS_SUPPORTED - SyncManagers supported */
/*! @{ */

#define ECAT_SYNCMANAGERS_SUPPORTED_BF0_MASK     (0xFFU)
#define ECAT_SYNCMANAGERS_SUPPORTED_BF0_SHIFT    (0U)
/*! BF0 - Number of supported SyncManager channels (or entities) */
#define ECAT_SYNCMANAGERS_SUPPORTED_BF0(x)       (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGERS_SUPPORTED_BF0_SHIFT)) & ECAT_SYNCMANAGERS_SUPPORTED_BF0_MASK)
/*! @} */

/*! @name RAM_SIZE - RAM Size */
/*! @{ */

#define ECAT_RAM_SIZE_BF0_MASK                   (0xFFU)
#define ECAT_RAM_SIZE_BF0_SHIFT                  (0U)
/*! BF0 - Process Data RAM size supported in KByte */
#define ECAT_RAM_SIZE_BF0(x)                     (((uint8_t)(((uint8_t)(x)) << ECAT_RAM_SIZE_BF0_SHIFT)) & ECAT_RAM_SIZE_BF0_MASK)
/*! @} */

/*! @name PORT_DESCRIPTOR - Port configuration */
/*! @{ */

#define ECAT_PORT_DESCRIPTOR_BF0_MASK            (0x3U)
#define ECAT_PORT_DESCRIPTOR_BF0_SHIFT           (0U)
/*! BF0 - Port 0 */
#define ECAT_PORT_DESCRIPTOR_BF0(x)              (((uint8_t)(((uint8_t)(x)) << ECAT_PORT_DESCRIPTOR_BF0_SHIFT)) & ECAT_PORT_DESCRIPTOR_BF0_MASK)

#define ECAT_PORT_DESCRIPTOR_BF2_MASK            (0xCU)
#define ECAT_PORT_DESCRIPTOR_BF2_SHIFT           (2U)
/*! BF2 - Port 1 */
#define ECAT_PORT_DESCRIPTOR_BF2(x)              (((uint8_t)(((uint8_t)(x)) << ECAT_PORT_DESCRIPTOR_BF2_SHIFT)) & ECAT_PORT_DESCRIPTOR_BF2_MASK)

#define ECAT_PORT_DESCRIPTOR_BF4_MASK            (0x30U)
#define ECAT_PORT_DESCRIPTOR_BF4_SHIFT           (4U)
/*! BF4 - Reserved */
#define ECAT_PORT_DESCRIPTOR_BF4(x)              (((uint8_t)(((uint8_t)(x)) << ECAT_PORT_DESCRIPTOR_BF4_SHIFT)) & ECAT_PORT_DESCRIPTOR_BF4_MASK)

#define ECAT_PORT_DESCRIPTOR_BF6_MASK            (0xC0U)
#define ECAT_PORT_DESCRIPTOR_BF6_SHIFT           (6U)
/*! BF6 - Reserved */
#define ECAT_PORT_DESCRIPTOR_BF6(x)              (((uint8_t)(((uint8_t)(x)) << ECAT_PORT_DESCRIPTOR_BF6_SHIFT)) & ECAT_PORT_DESCRIPTOR_BF6_MASK)
/*! @} */

/*! @name ESC_FEATURES_SUPPORTED - Register ESC Features supported */
/*! @{ */

#define ECAT_ESC_FEATURES_SUPPORTED_BF0_MASK     (0x1U)
#define ECAT_ESC_FEATURES_SUPPORTED_BF0_SHIFT    (0U)
/*! BF0 - FMMU Operation:
 *  0b0..Bit oriented
 *  0b1..Byte oriented
 */
#define ECAT_ESC_FEATURES_SUPPORTED_BF0(x)       (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_FEATURES_SUPPORTED_BF0_SHIFT)) & ECAT_ESC_FEATURES_SUPPORTED_BF0_MASK)

#define ECAT_ESC_FEATURES_SUPPORTED_BF1_MASK     (0x2U)
#define ECAT_ESC_FEATURES_SUPPORTED_BF1_SHIFT    (1U)
/*! BF1 - Unused register access:
 *  0b0..allowed
 *  0b1..not supported
 */
#define ECAT_ESC_FEATURES_SUPPORTED_BF1(x)       (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_FEATURES_SUPPORTED_BF1_SHIFT)) & ECAT_ESC_FEATURES_SUPPORTED_BF1_MASK)

#define ECAT_ESC_FEATURES_SUPPORTED_BF2_MASK     (0x4U)
#define ECAT_ESC_FEATURES_SUPPORTED_BF2_SHIFT    (2U)
/*! BF2 - Distributed Clocks:
 *  0b0..Not available
 *  0b1..Available
 */
#define ECAT_ESC_FEATURES_SUPPORTED_BF2(x)       (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_FEATURES_SUPPORTED_BF2_SHIFT)) & ECAT_ESC_FEATURES_SUPPORTED_BF2_MASK)

#define ECAT_ESC_FEATURES_SUPPORTED_BF3_MASK     (0x8U)
#define ECAT_ESC_FEATURES_SUPPORTED_BF3_SHIFT    (3U)
/*! BF3 - Distributed Clocks (width):
 *  0b0..32 bit
 *  0b1..64 bit
 */
#define ECAT_ESC_FEATURES_SUPPORTED_BF3(x)       (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_FEATURES_SUPPORTED_BF3_SHIFT)) & ECAT_ESC_FEATURES_SUPPORTED_BF3_MASK)

#define ECAT_ESC_FEATURES_SUPPORTED_BF6_MASK     (0x40U)
#define ECAT_ESC_FEATURES_SUPPORTED_BF6_SHIFT    (6U)
/*! BF6 - Enhanced Link Detection MII:
 *  0b0..Not available
 *  0b1..Available
 */
#define ECAT_ESC_FEATURES_SUPPORTED_BF6(x)       (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_FEATURES_SUPPORTED_BF6_SHIFT)) & ECAT_ESC_FEATURES_SUPPORTED_BF6_MASK)

#define ECAT_ESC_FEATURES_SUPPORTED_BF7_MASK     (0x80U)
#define ECAT_ESC_FEATURES_SUPPORTED_BF7_SHIFT    (7U)
/*! BF7 - Separate Handling of FCS Errors:
 *  0b0..Not supported
 *  0b1..Supported, frames with wrong FCS and additional nibble will be counted separately in Forwarded RX Error Counter
 */
#define ECAT_ESC_FEATURES_SUPPORTED_BF7(x)       (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_FEATURES_SUPPORTED_BF7_SHIFT)) & ECAT_ESC_FEATURES_SUPPORTED_BF7_MASK)

#define ECAT_ESC_FEATURES_SUPPORTED_BF8_MASK     (0x100U)
#define ECAT_ESC_FEATURES_SUPPORTED_BF8_SHIFT    (8U)
/*! BF8 - Enhanced DC SYNC Activation
 *  0b0..Not available
 *  0b1..Available
 */
#define ECAT_ESC_FEATURES_SUPPORTED_BF8(x)       (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_FEATURES_SUPPORTED_BF8_SHIFT)) & ECAT_ESC_FEATURES_SUPPORTED_BF8_MASK)

#define ECAT_ESC_FEATURES_SUPPORTED_BF9_MASK     (0x200U)
#define ECAT_ESC_FEATURES_SUPPORTED_BF9_SHIFT    (9U)
/*! BF9 - EtherCAT LRW command support:
 *  0b0..Supported
 *  0b1..Not supported
 */
#define ECAT_ESC_FEATURES_SUPPORTED_BF9(x)       (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_FEATURES_SUPPORTED_BF9_SHIFT)) & ECAT_ESC_FEATURES_SUPPORTED_BF9_MASK)

#define ECAT_ESC_FEATURES_SUPPORTED_BF10_MASK    (0x400U)
#define ECAT_ESC_FEATURES_SUPPORTED_BF10_SHIFT   (10U)
/*! BF10 - EtherCAT read/write command support (BRW, APRW, FPRW):
 *  0b0..Supported
 *  0b1..Not supported
 */
#define ECAT_ESC_FEATURES_SUPPORTED_BF10(x)      (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_FEATURES_SUPPORTED_BF10_SHIFT)) & ECAT_ESC_FEATURES_SUPPORTED_BF10_MASK)

#define ECAT_ESC_FEATURES_SUPPORTED_BF11_MASK    (0x800U)
#define ECAT_ESC_FEATURES_SUPPORTED_BF11_SHIFT   (11U)
/*! BF11 - Fixed FMMU/SyncManager configuration
 *  0b0..Variable configuration
 *  0b1..Fixed configuration (refer to documentation of supporting ESCs)
 */
#define ECAT_ESC_FEATURES_SUPPORTED_BF11(x)      (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_FEATURES_SUPPORTED_BF11_SHIFT)) & ECAT_ESC_FEATURES_SUPPORTED_BF11_MASK)

#define ECAT_ESC_FEATURES_SUPPORTED_BF12_MASK    (0xF000U)
#define ECAT_ESC_FEATURES_SUPPORTED_BF12_SHIFT   (12U)
/*! BF12 - Reserved */
#define ECAT_ESC_FEATURES_SUPPORTED_BF12(x)      (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_FEATURES_SUPPORTED_BF12_SHIFT)) & ECAT_ESC_FEATURES_SUPPORTED_BF12_MASK)
/*! @} */

/*! @name CONFIGURED_STATION_ADDRESS - Configured Station Address */
/*! @{ */

#define ECAT_CONFIGURED_STATION_ADDRESS_BF0_MASK (0xFFFFU)
#define ECAT_CONFIGURED_STATION_ADDRESS_BF0_SHIFT (0U)
/*! BF0 - Address used for node addressing (FPRD/FPWR/FPRW/FRMW commands). */
#define ECAT_CONFIGURED_STATION_ADDRESS_BF0(x)   (((uint16_t)(((uint16_t)(x)) << ECAT_CONFIGURED_STATION_ADDRESS_BF0_SHIFT)) & ECAT_CONFIGURED_STATION_ADDRESS_BF0_MASK)
/*! @} */

/*! @name CONFIGURED_STATION_ADDRESS_PDI - Configured Station Address */
/*! @{ */

#define ECAT_CONFIGURED_STATION_ADDRESS_PDI_BF0_MASK (0xFFFFU)
#define ECAT_CONFIGURED_STATION_ADDRESS_PDI_BF0_SHIFT (0U)
/*! BF0 - Address used for node addressing (FPRD/FPWR/FPRW/FRMW commands). */
#define ECAT_CONFIGURED_STATION_ADDRESS_PDI_BF0(x) (((uint16_t)(((uint16_t)(x)) << ECAT_CONFIGURED_STATION_ADDRESS_PDI_BF0_SHIFT)) & ECAT_CONFIGURED_STATION_ADDRESS_PDI_BF0_MASK)
/*! @} */

/*! @name CONFIGURED_STATION_ALIAS - Configured Station Alias */
/*! @{ */

#define ECAT_CONFIGURED_STATION_ALIAS_BF0_MASK   (0xFFFFU)
#define ECAT_CONFIGURED_STATION_ALIAS_BF0_SHIFT  (0U)
/*! BF0 - Alias Address used for node addressing (FPRD/FPWR/FPRW/FRMW commands). */
#define ECAT_CONFIGURED_STATION_ALIAS_BF0(x)     (((uint16_t)(((uint16_t)(x)) << ECAT_CONFIGURED_STATION_ALIAS_BF0_SHIFT)) & ECAT_CONFIGURED_STATION_ALIAS_BF0_MASK)
/*! @} */

/*! @name CONFIGURED_STATION_ALIAS_PDI - Configured Station Alias */
/*! @{ */

#define ECAT_CONFIGURED_STATION_ALIAS_PDI_BF0_MASK (0xFFFFU)
#define ECAT_CONFIGURED_STATION_ALIAS_PDI_BF0_SHIFT (0U)
/*! BF0 - Alias Address used for node addressing (FPRD/FPWR/FPRW/FRMW commands). */
#define ECAT_CONFIGURED_STATION_ALIAS_PDI_BF0(x) (((uint16_t)(((uint16_t)(x)) << ECAT_CONFIGURED_STATION_ALIAS_PDI_BF0_SHIFT)) & ECAT_CONFIGURED_STATION_ALIAS_PDI_BF0_MASK)
/*! @} */

/*! @name REGISTER_WRITE_ENABLE - Register Write Enable */
/*! @{ */

#define ECAT_REGISTER_WRITE_ENABLE_BF0_MASK      (0x1U)
#define ECAT_REGISTER_WRITE_ENABLE_BF0_SHIFT     (0U)
/*! BF0 - Register Write Enable. */
#define ECAT_REGISTER_WRITE_ENABLE_BF0(x)        (((uint8_t)(((uint8_t)(x)) << ECAT_REGISTER_WRITE_ENABLE_BF0_SHIFT)) & ECAT_REGISTER_WRITE_ENABLE_BF0_MASK)

#define ECAT_REGISTER_WRITE_ENABLE_BF1_MASK      (0xFEU)
#define ECAT_REGISTER_WRITE_ENABLE_BF1_SHIFT     (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_REGISTER_WRITE_ENABLE_BF1(x)        (((uint8_t)(((uint8_t)(x)) << ECAT_REGISTER_WRITE_ENABLE_BF1_SHIFT)) & ECAT_REGISTER_WRITE_ENABLE_BF1_MASK)
/*! @} */

/*! @name REGISTER_WRITE_ENABLE_PDI - Register Write Enable */
/*! @{ */

#define ECAT_REGISTER_WRITE_ENABLE_PDI_BF0_MASK  (0x1U)
#define ECAT_REGISTER_WRITE_ENABLE_PDI_BF0_SHIFT (0U)
/*! BF0 - Register Write Enable. */
#define ECAT_REGISTER_WRITE_ENABLE_PDI_BF0(x)    (((uint8_t)(((uint8_t)(x)) << ECAT_REGISTER_WRITE_ENABLE_PDI_BF0_SHIFT)) & ECAT_REGISTER_WRITE_ENABLE_PDI_BF0_MASK)

#define ECAT_REGISTER_WRITE_ENABLE_PDI_BF1_MASK  (0xFEU)
#define ECAT_REGISTER_WRITE_ENABLE_PDI_BF1_SHIFT (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_REGISTER_WRITE_ENABLE_PDI_BF1(x)    (((uint8_t)(((uint8_t)(x)) << ECAT_REGISTER_WRITE_ENABLE_PDI_BF1_SHIFT)) & ECAT_REGISTER_WRITE_ENABLE_PDI_BF1_MASK)
/*! @} */

/*! @name REGISTER_WRITE_PROTECTION - Register Write Protection */
/*! @{ */

#define ECAT_REGISTER_WRITE_PROTECTION_BF0_MASK  (0x1U)
#define ECAT_REGISTER_WRITE_PROTECTION_BF0_SHIFT (0U)
/*! BF0 - Register write protection.
 *  0b0..Protection disabled
 *  0b1..Protection enabled
 */
#define ECAT_REGISTER_WRITE_PROTECTION_BF0(x)    (((uint8_t)(((uint8_t)(x)) << ECAT_REGISTER_WRITE_PROTECTION_BF0_SHIFT)) & ECAT_REGISTER_WRITE_PROTECTION_BF0_MASK)

#define ECAT_REGISTER_WRITE_PROTECTION_BF1_MASK  (0xFEU)
#define ECAT_REGISTER_WRITE_PROTECTION_BF1_SHIFT (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_REGISTER_WRITE_PROTECTION_BF1(x)    (((uint8_t)(((uint8_t)(x)) << ECAT_REGISTER_WRITE_PROTECTION_BF1_SHIFT)) & ECAT_REGISTER_WRITE_PROTECTION_BF1_MASK)
/*! @} */

/*! @name REGISTER_WRITE_PROTECTION_PDI - Register Write Protection */
/*! @{ */

#define ECAT_REGISTER_WRITE_PROTECTION_PDI_BF0_MASK (0x1U)
#define ECAT_REGISTER_WRITE_PROTECTION_PDI_BF0_SHIFT (0U)
/*! BF0 - Register write protection.
 *  0b0..Protection disabled
 *  0b1..Protection enabled
 */
#define ECAT_REGISTER_WRITE_PROTECTION_PDI_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_REGISTER_WRITE_PROTECTION_PDI_BF0_SHIFT)) & ECAT_REGISTER_WRITE_PROTECTION_PDI_BF0_MASK)

#define ECAT_REGISTER_WRITE_PROTECTION_PDI_BF1_MASK (0xFEU)
#define ECAT_REGISTER_WRITE_PROTECTION_PDI_BF1_SHIFT (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_REGISTER_WRITE_PROTECTION_PDI_BF1(x) (((uint8_t)(((uint8_t)(x)) << ECAT_REGISTER_WRITE_PROTECTION_PDI_BF1_SHIFT)) & ECAT_REGISTER_WRITE_PROTECTION_PDI_BF1_MASK)
/*! @} */

/*! @name ESC_WRITE_ENABLE - ESC Write Enable */
/*! @{ */

#define ECAT_ESC_WRITE_ENABLE_BF0_MASK           (0x1U)
#define ECAT_ESC_WRITE_ENABLE_BF0_SHIFT          (0U)
/*! BF0 - ESC Write Enable */
#define ECAT_ESC_WRITE_ENABLE_BF0(x)             (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_WRITE_ENABLE_BF0_SHIFT)) & ECAT_ESC_WRITE_ENABLE_BF0_MASK)

#define ECAT_ESC_WRITE_ENABLE_BF1_MASK           (0xFEU)
#define ECAT_ESC_WRITE_ENABLE_BF1_SHIFT          (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_ESC_WRITE_ENABLE_BF1(x)             (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_WRITE_ENABLE_BF1_SHIFT)) & ECAT_ESC_WRITE_ENABLE_BF1_MASK)
/*! @} */

/*! @name ESC_WRITE_ENABLE_PDI - ESC Write Enable */
/*! @{ */

#define ECAT_ESC_WRITE_ENABLE_PDI_BF0_MASK       (0x1U)
#define ECAT_ESC_WRITE_ENABLE_PDI_BF0_SHIFT      (0U)
/*! BF0 - ESC Write Enable */
#define ECAT_ESC_WRITE_ENABLE_PDI_BF0(x)         (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_WRITE_ENABLE_PDI_BF0_SHIFT)) & ECAT_ESC_WRITE_ENABLE_PDI_BF0_MASK)

#define ECAT_ESC_WRITE_ENABLE_PDI_BF1_MASK       (0xFEU)
#define ECAT_ESC_WRITE_ENABLE_PDI_BF1_SHIFT      (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_ESC_WRITE_ENABLE_PDI_BF1(x)         (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_WRITE_ENABLE_PDI_BF1_SHIFT)) & ECAT_ESC_WRITE_ENABLE_PDI_BF1_MASK)
/*! @} */

/*! @name ESC_WRITE_PROTECTION - ESC Write Protection */
/*! @{ */

#define ECAT_ESC_WRITE_PROTECTION_BF0_MASK       (0x1U)
#define ECAT_ESC_WRITE_PROTECTION_BF0_SHIFT      (0U)
/*! BF0 - Write protect:
 *  0b0..Protection disabled
 *  0b1..Protection enabled
 */
#define ECAT_ESC_WRITE_PROTECTION_BF0(x)         (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_WRITE_PROTECTION_BF0_SHIFT)) & ECAT_ESC_WRITE_PROTECTION_BF0_MASK)

#define ECAT_ESC_WRITE_PROTECTION_BF1_MASK       (0xFEU)
#define ECAT_ESC_WRITE_PROTECTION_BF1_SHIFT      (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_ESC_WRITE_PROTECTION_BF1(x)         (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_WRITE_PROTECTION_BF1_SHIFT)) & ECAT_ESC_WRITE_PROTECTION_BF1_MASK)
/*! @} */

/*! @name ESC_WRITE_PROTECTION_PDI - ESC Write Protection */
/*! @{ */

#define ECAT_ESC_WRITE_PROTECTION_PDI_BF0_MASK   (0x1U)
#define ECAT_ESC_WRITE_PROTECTION_PDI_BF0_SHIFT  (0U)
/*! BF0 - Write protect:
 *  0b0..Protection disabled
 *  0b1..Protection enabled
 */
#define ECAT_ESC_WRITE_PROTECTION_PDI_BF0(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_WRITE_PROTECTION_PDI_BF0_SHIFT)) & ECAT_ESC_WRITE_PROTECTION_PDI_BF0_MASK)

#define ECAT_ESC_WRITE_PROTECTION_PDI_BF1_MASK   (0xFEU)
#define ECAT_ESC_WRITE_PROTECTION_PDI_BF1_SHIFT  (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_ESC_WRITE_PROTECTION_PDI_BF1(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_WRITE_PROTECTION_PDI_BF1_SHIFT)) & ECAT_ESC_WRITE_PROTECTION_PDI_BF1_MASK)
/*! @} */

/*! @name ESC_RESET_ECAT_WRITE - ESC Reset ECAT WRITE */
/*! @{ */

#define ECAT_ESC_RESET_ECAT_WRITE_BF0_MASK       (0xFFU)
#define ECAT_ESC_RESET_ECAT_WRITE_BF0_SHIFT      (0U)
/*! BF0 - A reset is asserted after writing 0x52 ('R'), 0x45 ('E') and 0x53 ('S') in this register with 3 consecutive frames. */
#define ECAT_ESC_RESET_ECAT_WRITE_BF0(x)         (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_RESET_ECAT_WRITE_BF0_SHIFT)) & ECAT_ESC_RESET_ECAT_WRITE_BF0_MASK)
/*! @} */

/*! @name ESC_RESET_ECAT_WRITE_PDI - ESC Reset ECAT WRITE */
/*! @{ */

#define ECAT_ESC_RESET_ECAT_WRITE_PDI_BF0_MASK   (0xFFU)
#define ECAT_ESC_RESET_ECAT_WRITE_PDI_BF0_SHIFT  (0U)
/*! BF0 - A reset is asserted after writing 0x52 ('R'), 0x45 ('E') and 0x53 ('S') in this register with 3 consecutive frames. */
#define ECAT_ESC_RESET_ECAT_WRITE_PDI_BF0(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_RESET_ECAT_WRITE_PDI_BF0_SHIFT)) & ECAT_ESC_RESET_ECAT_WRITE_PDI_BF0_MASK)
/*! @} */

/*! @name ESC_RESET_PDI_WRITE - ESC Reset PDI WRITE */
/*! @{ */

#define ECAT_ESC_RESET_PDI_WRITE_BF0_MASK        (0xFFU)
#define ECAT_ESC_RESET_PDI_WRITE_BF0_SHIFT       (0U)
/*! BF0 - A reset is asserted after writing 0x52 ('R'), 0x45 ('E') and 0x53 ('S') in this register with 3 consecutive commands. */
#define ECAT_ESC_RESET_PDI_WRITE_BF0(x)          (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_RESET_PDI_WRITE_BF0_SHIFT)) & ECAT_ESC_RESET_PDI_WRITE_BF0_MASK)
/*! @} */

/*! @name ESC_RESET_PDI_WRITE_PDI - ESC Reset PDI WRITE */
/*! @{ */

#define ECAT_ESC_RESET_PDI_WRITE_PDI_BF0_MASK    (0xFFU)
#define ECAT_ESC_RESET_PDI_WRITE_PDI_BF0_SHIFT   (0U)
/*! BF0 - A reset is asserted after writing 0x52 ('R'), 0x45 ('E') and 0x53 ('S') in this register with 3 consecutive commands. */
#define ECAT_ESC_RESET_PDI_WRITE_PDI_BF0(x)      (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_RESET_PDI_WRITE_PDI_BF0_SHIFT)) & ECAT_ESC_RESET_PDI_WRITE_PDI_BF0_MASK)
/*! @} */

/*! @name ESC_DL_CONTROL - ESC DL Control */
/*! @{ */

#define ECAT_ESC_DL_CONTROL_BF0_MASK             (0x1U)
#define ECAT_ESC_DL_CONTROL_BF0_SHIFT            (0U)
/*! BF0 - Forwarding Rule
 *  0b0..EtherCAT frames are processed, non-EtherCAT frames are forwarded without processing or modification.
 *  0b1..EtherCAT frames are processed, non-EtherCAT frames are destroyed.
 */
#define ECAT_ESC_DL_CONTROL_BF0(x)               (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_BF0_SHIFT)) & ECAT_ESC_DL_CONTROL_BF0_MASK)

#define ECAT_ESC_DL_CONTROL_BF1_MASK             (0x2U)
#define ECAT_ESC_DL_CONTROL_BF1_SHIFT            (1U)
/*! BF1 - Temporary use of settings in 0x0100:0x0103[8:15]:
 *  0b0..permanent use
 *  0b1..use for about 1 second, then revert to previous settings
 */
#define ECAT_ESC_DL_CONTROL_BF1(x)               (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_BF1_SHIFT)) & ECAT_ESC_DL_CONTROL_BF1_MASK)

#define ECAT_ESC_DL_CONTROL_BF2_MASK             (0xFCU)
#define ECAT_ESC_DL_CONTROL_BF2_SHIFT            (2U)
/*! BF2 - Reserved, Write 0 */
#define ECAT_ESC_DL_CONTROL_BF2(x)               (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_BF2_SHIFT)) & ECAT_ESC_DL_CONTROL_BF2_MASK)

#define ECAT_ESC_DL_CONTROL_BF8_MASK             (0x300U)
#define ECAT_ESC_DL_CONTROL_BF8_SHIFT            (8U)
/*! BF8 - Loop Port 0:
 *  0b00..Auto
 *  0b01..Auto Close
 *  0b10..Open
 *  0b11..Closed
 */
#define ECAT_ESC_DL_CONTROL_BF8(x)               (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_BF8_SHIFT)) & ECAT_ESC_DL_CONTROL_BF8_MASK)

#define ECAT_ESC_DL_CONTROL_BF10_MASK            (0xC00U)
#define ECAT_ESC_DL_CONTROL_BF10_SHIFT           (10U)
/*! BF10 - Loop Port 1:
 *  0b00..Auto
 *  0b01..Auto Close
 *  0b10..Open
 *  0b11..Closed
 */
#define ECAT_ESC_DL_CONTROL_BF10(x)              (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_BF10_SHIFT)) & ECAT_ESC_DL_CONTROL_BF10_MASK)

#define ECAT_ESC_DL_CONTROL_BF12_MASK            (0x3000U)
#define ECAT_ESC_DL_CONTROL_BF12_SHIFT           (12U)
/*! BF12 - Reserved */
#define ECAT_ESC_DL_CONTROL_BF12(x)              (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_BF12_SHIFT)) & ECAT_ESC_DL_CONTROL_BF12_MASK)

#define ECAT_ESC_DL_CONTROL_BF14_MASK            (0xC000U)
#define ECAT_ESC_DL_CONTROL_BF14_SHIFT           (14U)
/*! BF14 - Reserved */
#define ECAT_ESC_DL_CONTROL_BF14(x)              (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_BF14_SHIFT)) & ECAT_ESC_DL_CONTROL_BF14_MASK)

#define ECAT_ESC_DL_CONTROL_BF16_MASK            (0x70000U)
#define ECAT_ESC_DL_CONTROL_BF16_SHIFT           (16U)
/*! BF16 - RX FIFO Size (ESC delays start of forwarding until FIFO is at least half full). */
#define ECAT_ESC_DL_CONTROL_BF16(x)              (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_BF16_SHIFT)) & ECAT_ESC_DL_CONTROL_BF16_MASK)

#define ECAT_ESC_DL_CONTROL_BF20_MASK            (0x300000U)
#define ECAT_ESC_DL_CONTROL_BF20_SHIFT           (20U)
/*! BF20 - Reserved, write 0 */
#define ECAT_ESC_DL_CONTROL_BF20(x)              (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_BF20_SHIFT)) & ECAT_ESC_DL_CONTROL_BF20_MASK)

#define ECAT_ESC_DL_CONTROL_BF23_MASK            (0x800000U)
#define ECAT_ESC_DL_CONTROL_BF23_SHIFT           (23U)
/*! BF23 - Reserved, write 0 */
#define ECAT_ESC_DL_CONTROL_BF23(x)              (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_BF23_SHIFT)) & ECAT_ESC_DL_CONTROL_BF23_MASK)

#define ECAT_ESC_DL_CONTROL_BF24_MASK            (0x1000000U)
#define ECAT_ESC_DL_CONTROL_BF24_SHIFT           (24U)
/*! BF24 - Station alias:
 *  0b0..Ignore Station Alias
 *  0b1..Alias can be used for all configured address command types (FPRD, FPWR, ...)
 */
#define ECAT_ESC_DL_CONTROL_BF24(x)              (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_BF24_SHIFT)) & ECAT_ESC_DL_CONTROL_BF24_MASK)

#define ECAT_ESC_DL_CONTROL_BF25_MASK            (0xFE000000U)
#define ECAT_ESC_DL_CONTROL_BF25_SHIFT           (25U)
/*! BF25 - Reserved, write 0 */
#define ECAT_ESC_DL_CONTROL_BF25(x)              (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_BF25_SHIFT)) & ECAT_ESC_DL_CONTROL_BF25_MASK)
/*! @} */

/*! @name ESC_DL_CONTROL_PDI - ESC DL Control */
/*! @{ */

#define ECAT_ESC_DL_CONTROL_PDI_BF0_MASK         (0x1U)
#define ECAT_ESC_DL_CONTROL_PDI_BF0_SHIFT        (0U)
/*! BF0 - Forwarding Rule
 *  0b0..EtherCAT frames are processed, non-EtherCAT frames are forwarded without processing or modification.
 *  0b1..EtherCAT frames are processed, non-EtherCAT frames are destroyed.
 */
#define ECAT_ESC_DL_CONTROL_PDI_BF0(x)           (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_PDI_BF0_SHIFT)) & ECAT_ESC_DL_CONTROL_PDI_BF0_MASK)

#define ECAT_ESC_DL_CONTROL_PDI_BF1_MASK         (0x2U)
#define ECAT_ESC_DL_CONTROL_PDI_BF1_SHIFT        (1U)
/*! BF1 - Temporary use of settings in 0x0100:0x0103[8:15]:
 *  0b0..permanent use
 *  0b1..use for about 1 second, then revert to previous settings
 */
#define ECAT_ESC_DL_CONTROL_PDI_BF1(x)           (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_PDI_BF1_SHIFT)) & ECAT_ESC_DL_CONTROL_PDI_BF1_MASK)

#define ECAT_ESC_DL_CONTROL_PDI_BF2_MASK         (0xFCU)
#define ECAT_ESC_DL_CONTROL_PDI_BF2_SHIFT        (2U)
/*! BF2 - Reserved, Write 0 */
#define ECAT_ESC_DL_CONTROL_PDI_BF2(x)           (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_PDI_BF2_SHIFT)) & ECAT_ESC_DL_CONTROL_PDI_BF2_MASK)

#define ECAT_ESC_DL_CONTROL_PDI_BF8_MASK         (0x300U)
#define ECAT_ESC_DL_CONTROL_PDI_BF8_SHIFT        (8U)
/*! BF8 - Loop Port 0:
 *  0b00..Auto
 *  0b01..Auto Close
 *  0b10..Open
 *  0b11..Closed
 */
#define ECAT_ESC_DL_CONTROL_PDI_BF8(x)           (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_PDI_BF8_SHIFT)) & ECAT_ESC_DL_CONTROL_PDI_BF8_MASK)

#define ECAT_ESC_DL_CONTROL_PDI_BF10_MASK        (0xC00U)
#define ECAT_ESC_DL_CONTROL_PDI_BF10_SHIFT       (10U)
/*! BF10 - Loop Port 1:
 *  0b00..Auto
 *  0b01..Auto Close
 *  0b10..Open
 *  0b11..Closed
 */
#define ECAT_ESC_DL_CONTROL_PDI_BF10(x)          (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_PDI_BF10_SHIFT)) & ECAT_ESC_DL_CONTROL_PDI_BF10_MASK)

#define ECAT_ESC_DL_CONTROL_PDI_BF12_MASK        (0x3000U)
#define ECAT_ESC_DL_CONTROL_PDI_BF12_SHIFT       (12U)
/*! BF12 - Reserved */
#define ECAT_ESC_DL_CONTROL_PDI_BF12(x)          (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_PDI_BF12_SHIFT)) & ECAT_ESC_DL_CONTROL_PDI_BF12_MASK)

#define ECAT_ESC_DL_CONTROL_PDI_BF14_MASK        (0xC000U)
#define ECAT_ESC_DL_CONTROL_PDI_BF14_SHIFT       (14U)
/*! BF14 - Reserved */
#define ECAT_ESC_DL_CONTROL_PDI_BF14(x)          (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_PDI_BF14_SHIFT)) & ECAT_ESC_DL_CONTROL_PDI_BF14_MASK)

#define ECAT_ESC_DL_CONTROL_PDI_BF16_MASK        (0x70000U)
#define ECAT_ESC_DL_CONTROL_PDI_BF16_SHIFT       (16U)
/*! BF16 - RX FIFO Size (ESC delays start of forwarding until FIFO is at least half full). */
#define ECAT_ESC_DL_CONTROL_PDI_BF16(x)          (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_PDI_BF16_SHIFT)) & ECAT_ESC_DL_CONTROL_PDI_BF16_MASK)

#define ECAT_ESC_DL_CONTROL_PDI_BF20_MASK        (0x300000U)
#define ECAT_ESC_DL_CONTROL_PDI_BF20_SHIFT       (20U)
/*! BF20 - Reserved, write 0 */
#define ECAT_ESC_DL_CONTROL_PDI_BF20(x)          (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_PDI_BF20_SHIFT)) & ECAT_ESC_DL_CONTROL_PDI_BF20_MASK)

#define ECAT_ESC_DL_CONTROL_PDI_BF23_MASK        (0x800000U)
#define ECAT_ESC_DL_CONTROL_PDI_BF23_SHIFT       (23U)
/*! BF23 - Reserved, write 0 */
#define ECAT_ESC_DL_CONTROL_PDI_BF23(x)          (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_PDI_BF23_SHIFT)) & ECAT_ESC_DL_CONTROL_PDI_BF23_MASK)

#define ECAT_ESC_DL_CONTROL_PDI_BF24_MASK        (0x1000000U)
#define ECAT_ESC_DL_CONTROL_PDI_BF24_SHIFT       (24U)
/*! BF24 - Station alias:
 *  0b0..Ignore Station Alias
 *  0b1..Alias can be used for all configured address command types (FPRD, FPWR, ...)
 */
#define ECAT_ESC_DL_CONTROL_PDI_BF24(x)          (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_PDI_BF24_SHIFT)) & ECAT_ESC_DL_CONTROL_PDI_BF24_MASK)

#define ECAT_ESC_DL_CONTROL_PDI_BF25_MASK        (0xFE000000U)
#define ECAT_ESC_DL_CONTROL_PDI_BF25_SHIFT       (25U)
/*! BF25 - Reserved, write 0 */
#define ECAT_ESC_DL_CONTROL_PDI_BF25(x)          (((uint32_t)(((uint32_t)(x)) << ECAT_ESC_DL_CONTROL_PDI_BF25_SHIFT)) & ECAT_ESC_DL_CONTROL_PDI_BF25_MASK)
/*! @} */

/*! @name PHYSICAL_READ_WRITE_OFFSET - Physical Read Write Offset */
/*! @{ */

#define ECAT_PHYSICAL_READ_WRITE_OFFSET_BF0_MASK (0xFFFFU)
#define ECAT_PHYSICAL_READ_WRITE_OFFSET_BF0_SHIFT (0U)
/*! BF0 - This register is used for ReadWrite commands in Device Addressing mode (FPRW, APRW, BRW). */
#define ECAT_PHYSICAL_READ_WRITE_OFFSET_BF0(x)   (((uint16_t)(((uint16_t)(x)) << ECAT_PHYSICAL_READ_WRITE_OFFSET_BF0_SHIFT)) & ECAT_PHYSICAL_READ_WRITE_OFFSET_BF0_MASK)
/*! @} */

/*! @name PHYSICAL_READ_WRITE_OFFSET_PDI - Physical Read Write Offset */
/*! @{ */

#define ECAT_PHYSICAL_READ_WRITE_OFFSET_PDI_BF0_MASK (0xFFFFU)
#define ECAT_PHYSICAL_READ_WRITE_OFFSET_PDI_BF0_SHIFT (0U)
/*! BF0 - This register is used for ReadWrite commands in Device Addressing mode (FPRW, APRW, BRW). */
#define ECAT_PHYSICAL_READ_WRITE_OFFSET_PDI_BF0(x) (((uint16_t)(((uint16_t)(x)) << ECAT_PHYSICAL_READ_WRITE_OFFSET_PDI_BF0_SHIFT)) & ECAT_PHYSICAL_READ_WRITE_OFFSET_PDI_BF0_MASK)
/*! @} */

/*! @name ESC_DL_STATUS - ESC DL Status */
/*! @{ */

#define ECAT_ESC_DL_STATUS_BF0_MASK              (0x1U)
#define ECAT_ESC_DL_STATUS_BF0_SHIFT             (0U)
/*! BF0 - Register ESC DL Status
 *  0b0..PDI operational/EEPROM loaded correctly:
 *  0b1..EEPROM loaded correctly, PDI operational (access to Process Data RAM)
 */
#define ECAT_ESC_DL_STATUS_BF0(x)                (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_DL_STATUS_BF0_SHIFT)) & ECAT_ESC_DL_STATUS_BF0_MASK)

#define ECAT_ESC_DL_STATUS_BF1_MASK              (0x2U)
#define ECAT_ESC_DL_STATUS_BF1_SHIFT             (1U)
/*! BF1 - PDI Watchdog Status:
 *  0b0..Watchdog expired
 *  0b1..Watchdog reloaded
 */
#define ECAT_ESC_DL_STATUS_BF1(x)                (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_DL_STATUS_BF1_SHIFT)) & ECAT_ESC_DL_STATUS_BF1_MASK)

#define ECAT_ESC_DL_STATUS_BF2_MASK              (0x4U)
#define ECAT_ESC_DL_STATUS_BF2_SHIFT             (2U)
/*! BF2 - Enhanced Link detection:
 *  0b0..Deactivated for all ports
 *  0b1..Activated for at least one port
 */
#define ECAT_ESC_DL_STATUS_BF2(x)                (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_DL_STATUS_BF2_SHIFT)) & ECAT_ESC_DL_STATUS_BF2_MASK)

#define ECAT_ESC_DL_STATUS_BF3_MASK              (0x8U)
#define ECAT_ESC_DL_STATUS_BF3_SHIFT             (3U)
/*! BF3 - Reserved */
#define ECAT_ESC_DL_STATUS_BF3(x)                (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_DL_STATUS_BF3_SHIFT)) & ECAT_ESC_DL_STATUS_BF3_MASK)

#define ECAT_ESC_DL_STATUS_BF4_MASK              (0x10U)
#define ECAT_ESC_DL_STATUS_BF4_SHIFT             (4U)
/*! BF4 - Physical link on Port 0:
 *  0b0..No link
 *  0b1..Link detected
 */
#define ECAT_ESC_DL_STATUS_BF4(x)                (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_DL_STATUS_BF4_SHIFT)) & ECAT_ESC_DL_STATUS_BF4_MASK)

#define ECAT_ESC_DL_STATUS_BF5_MASK              (0x20U)
#define ECAT_ESC_DL_STATUS_BF5_SHIFT             (5U)
/*! BF5 - Physical link on Port 1:
 *  0b0..No link
 *  0b1..Link detected
 */
#define ECAT_ESC_DL_STATUS_BF5(x)                (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_DL_STATUS_BF5_SHIFT)) & ECAT_ESC_DL_STATUS_BF5_MASK)

#define ECAT_ESC_DL_STATUS_BF6_MASK              (0x40U)
#define ECAT_ESC_DL_STATUS_BF6_SHIFT             (6U)
/*! BF6 - Reserved */
#define ECAT_ESC_DL_STATUS_BF6(x)                (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_DL_STATUS_BF6_SHIFT)) & ECAT_ESC_DL_STATUS_BF6_MASK)

#define ECAT_ESC_DL_STATUS_BF7_MASK              (0x80U)
#define ECAT_ESC_DL_STATUS_BF7_SHIFT             (7U)
/*! BF7 - Reserved */
#define ECAT_ESC_DL_STATUS_BF7(x)                (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_DL_STATUS_BF7_SHIFT)) & ECAT_ESC_DL_STATUS_BF7_MASK)

#define ECAT_ESC_DL_STATUS_BF8_MASK              (0x100U)
#define ECAT_ESC_DL_STATUS_BF8_SHIFT             (8U)
/*! BF8 - Loop Port 0:
 *  0b0..Open
 *  0b1..Closed
 */
#define ECAT_ESC_DL_STATUS_BF8(x)                (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_DL_STATUS_BF8_SHIFT)) & ECAT_ESC_DL_STATUS_BF8_MASK)

#define ECAT_ESC_DL_STATUS_BF9_MASK              (0x200U)
#define ECAT_ESC_DL_STATUS_BF9_SHIFT             (9U)
/*! BF9 - Communication on Port 0:
 *  0b0..No stable communication
 *  0b1..Communication established
 */
#define ECAT_ESC_DL_STATUS_BF9(x)                (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_DL_STATUS_BF9_SHIFT)) & ECAT_ESC_DL_STATUS_BF9_MASK)

#define ECAT_ESC_DL_STATUS_BF10_MASK             (0x400U)
#define ECAT_ESC_DL_STATUS_BF10_SHIFT            (10U)
/*! BF10 - Loop Port 1
 *  0b0..Open
 *  0b1..Closed
 */
#define ECAT_ESC_DL_STATUS_BF10(x)               (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_DL_STATUS_BF10_SHIFT)) & ECAT_ESC_DL_STATUS_BF10_MASK)

#define ECAT_ESC_DL_STATUS_BF11_MASK             (0x800U)
#define ECAT_ESC_DL_STATUS_BF11_SHIFT            (11U)
/*! BF11 - Communication on Port 1:
 *  0b0..No stable communication
 *  0b1..Communication established
 */
#define ECAT_ESC_DL_STATUS_BF11(x)               (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_DL_STATUS_BF11_SHIFT)) & ECAT_ESC_DL_STATUS_BF11_MASK)

#define ECAT_ESC_DL_STATUS_BF12_MASK             (0x1000U)
#define ECAT_ESC_DL_STATUS_BF12_SHIFT            (12U)
/*! BF12 - Reserved */
#define ECAT_ESC_DL_STATUS_BF12(x)               (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_DL_STATUS_BF12_SHIFT)) & ECAT_ESC_DL_STATUS_BF12_MASK)

#define ECAT_ESC_DL_STATUS_BF13_MASK             (0x2000U)
#define ECAT_ESC_DL_STATUS_BF13_SHIFT            (13U)
/*! BF13 - Reserved */
#define ECAT_ESC_DL_STATUS_BF13(x)               (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_DL_STATUS_BF13_SHIFT)) & ECAT_ESC_DL_STATUS_BF13_MASK)

#define ECAT_ESC_DL_STATUS_BF14_MASK             (0x4000U)
#define ECAT_ESC_DL_STATUS_BF14_SHIFT            (14U)
/*! BF14 - Reserved */
#define ECAT_ESC_DL_STATUS_BF14(x)               (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_DL_STATUS_BF14_SHIFT)) & ECAT_ESC_DL_STATUS_BF14_MASK)

#define ECAT_ESC_DL_STATUS_BF15_MASK             (0x8000U)
#define ECAT_ESC_DL_STATUS_BF15_SHIFT            (15U)
/*! BF15 - Reserved */
#define ECAT_ESC_DL_STATUS_BF15(x)               (((uint16_t)(((uint16_t)(x)) << ECAT_ESC_DL_STATUS_BF15_SHIFT)) & ECAT_ESC_DL_STATUS_BF15_MASK)
/*! @} */

/*! @name AL_CONTROL - AL Control */
/*! @{ */

#define ECAT_AL_CONTROL_BF0_MASK                 (0xFU)
#define ECAT_AL_CONTROL_BF0_SHIFT                (0U)
/*! BF0 - Initiate State Transition of the Device State Machine: */
#define ECAT_AL_CONTROL_BF0(x)                   (((uint16_t)(((uint16_t)(x)) << ECAT_AL_CONTROL_BF0_SHIFT)) & ECAT_AL_CONTROL_BF0_MASK)

#define ECAT_AL_CONTROL_BF4_MASK                 (0x10U)
#define ECAT_AL_CONTROL_BF4_SHIFT                (4U)
/*! BF4 - Error Ind Ack
 *  0b0..No Ack of Error Ind in AL status register
 *  0b1..Ack of Error Ind in AL status register
 */
#define ECAT_AL_CONTROL_BF4(x)                   (((uint16_t)(((uint16_t)(x)) << ECAT_AL_CONTROL_BF4_SHIFT)) & ECAT_AL_CONTROL_BF4_MASK)

#define ECAT_AL_CONTROL_BF5_MASK                 (0x20U)
#define ECAT_AL_CONTROL_BF5_SHIFT                (5U)
/*! BF5 - Device Identification:
 *  0b0..No request
 *  0b1..Device Identification request
 */
#define ECAT_AL_CONTROL_BF5(x)                   (((uint16_t)(((uint16_t)(x)) << ECAT_AL_CONTROL_BF5_SHIFT)) & ECAT_AL_CONTROL_BF5_MASK)

#define ECAT_AL_CONTROL_BF6_MASK                 (0xFFC0U)
#define ECAT_AL_CONTROL_BF6_SHIFT                (6U)
/*! BF6 - Reserved, write 0 */
#define ECAT_AL_CONTROL_BF6(x)                   (((uint16_t)(((uint16_t)(x)) << ECAT_AL_CONTROL_BF6_SHIFT)) & ECAT_AL_CONTROL_BF6_MASK)
/*! @} */

/*! @name AL_CONTROL_PDI - AL Control */
/*! @{ */

#define ECAT_AL_CONTROL_PDI_BF0_MASK             (0xFU)
#define ECAT_AL_CONTROL_PDI_BF0_SHIFT            (0U)
/*! BF0 - Initiate State Transition of the Device State Machine: */
#define ECAT_AL_CONTROL_PDI_BF0(x)               (((uint16_t)(((uint16_t)(x)) << ECAT_AL_CONTROL_PDI_BF0_SHIFT)) & ECAT_AL_CONTROL_PDI_BF0_MASK)

#define ECAT_AL_CONTROL_PDI_BF4_MASK             (0x10U)
#define ECAT_AL_CONTROL_PDI_BF4_SHIFT            (4U)
/*! BF4 - Error Ind Ack
 *  0b0..No Ack of Error Ind in AL status register
 *  0b1..Ack of Error Ind in AL status register
 */
#define ECAT_AL_CONTROL_PDI_BF4(x)               (((uint16_t)(((uint16_t)(x)) << ECAT_AL_CONTROL_PDI_BF4_SHIFT)) & ECAT_AL_CONTROL_PDI_BF4_MASK)

#define ECAT_AL_CONTROL_PDI_BF5_MASK             (0x20U)
#define ECAT_AL_CONTROL_PDI_BF5_SHIFT            (5U)
/*! BF5 - Device Identification:
 *  0b0..No request
 *  0b1..Device Identification request
 */
#define ECAT_AL_CONTROL_PDI_BF5(x)               (((uint16_t)(((uint16_t)(x)) << ECAT_AL_CONTROL_PDI_BF5_SHIFT)) & ECAT_AL_CONTROL_PDI_BF5_MASK)

#define ECAT_AL_CONTROL_PDI_BF6_MASK             (0xFFC0U)
#define ECAT_AL_CONTROL_PDI_BF6_SHIFT            (6U)
/*! BF6 - Reserved, write 0 */
#define ECAT_AL_CONTROL_PDI_BF6(x)               (((uint16_t)(((uint16_t)(x)) << ECAT_AL_CONTROL_PDI_BF6_SHIFT)) & ECAT_AL_CONTROL_PDI_BF6_MASK)
/*! @} */

/*! @name AL_STATUS - AL Status */
/*! @{ */

#define ECAT_AL_STATUS_BF0_MASK                  (0xFU)
#define ECAT_AL_STATUS_BF0_SHIFT                 (0U)
/*! BF0 - Actual State of the Device State Machine: */
#define ECAT_AL_STATUS_BF0(x)                    (((uint16_t)(((uint16_t)(x)) << ECAT_AL_STATUS_BF0_SHIFT)) & ECAT_AL_STATUS_BF0_MASK)

#define ECAT_AL_STATUS_BF4_MASK                  (0x10U)
#define ECAT_AL_STATUS_BF4_SHIFT                 (4U)
/*! BF4 - Error Ind:
 *  0b0..Device is in State as requested or Flag cleared by command
 *  0b1..Device has not entered requested State or changed State as result of a local action
 */
#define ECAT_AL_STATUS_BF4(x)                    (((uint16_t)(((uint16_t)(x)) << ECAT_AL_STATUS_BF4_SHIFT)) & ECAT_AL_STATUS_BF4_MASK)

#define ECAT_AL_STATUS_BF5_MASK                  (0x20U)
#define ECAT_AL_STATUS_BF5_SHIFT                 (5U)
/*! BF5 - Device Identification:
 *  0b0..Device Identification not valid
 *  0b1..Device Identification loaded
 */
#define ECAT_AL_STATUS_BF5(x)                    (((uint16_t)(((uint16_t)(x)) << ECAT_AL_STATUS_BF5_SHIFT)) & ECAT_AL_STATUS_BF5_MASK)

#define ECAT_AL_STATUS_BF6_MASK                  (0xFFC0U)
#define ECAT_AL_STATUS_BF6_SHIFT                 (6U)
/*! BF6 - Reserved, write 0 */
#define ECAT_AL_STATUS_BF6(x)                    (((uint16_t)(((uint16_t)(x)) << ECAT_AL_STATUS_BF6_SHIFT)) & ECAT_AL_STATUS_BF6_MASK)
/*! @} */

/*! @name AL_STATUS_PDI - AL Status */
/*! @{ */

#define ECAT_AL_STATUS_PDI_BF0_MASK              (0xFU)
#define ECAT_AL_STATUS_PDI_BF0_SHIFT             (0U)
/*! BF0 - Actual State of the Device State Machine: */
#define ECAT_AL_STATUS_PDI_BF0(x)                (((uint16_t)(((uint16_t)(x)) << ECAT_AL_STATUS_PDI_BF0_SHIFT)) & ECAT_AL_STATUS_PDI_BF0_MASK)

#define ECAT_AL_STATUS_PDI_BF4_MASK              (0x10U)
#define ECAT_AL_STATUS_PDI_BF4_SHIFT             (4U)
/*! BF4 - Error Ind:
 *  0b0..Device is in State as requested or Flag cleared by command
 *  0b1..Device has not entered requested State or changed State as result of a local action
 */
#define ECAT_AL_STATUS_PDI_BF4(x)                (((uint16_t)(((uint16_t)(x)) << ECAT_AL_STATUS_PDI_BF4_SHIFT)) & ECAT_AL_STATUS_PDI_BF4_MASK)

#define ECAT_AL_STATUS_PDI_BF5_MASK              (0x20U)
#define ECAT_AL_STATUS_PDI_BF5_SHIFT             (5U)
/*! BF5 - Device Identification:
 *  0b0..Device Identification not valid
 *  0b1..Device Identification loaded
 */
#define ECAT_AL_STATUS_PDI_BF5(x)                (((uint16_t)(((uint16_t)(x)) << ECAT_AL_STATUS_PDI_BF5_SHIFT)) & ECAT_AL_STATUS_PDI_BF5_MASK)

#define ECAT_AL_STATUS_PDI_BF6_MASK              (0xFFC0U)
#define ECAT_AL_STATUS_PDI_BF6_SHIFT             (6U)
/*! BF6 - Reserved, write 0 */
#define ECAT_AL_STATUS_PDI_BF6(x)                (((uint16_t)(((uint16_t)(x)) << ECAT_AL_STATUS_PDI_BF6_SHIFT)) & ECAT_AL_STATUS_PDI_BF6_MASK)
/*! @} */

/*! @name AL_STATUS_CODE - AL Status Code */
/*! @{ */

#define ECAT_AL_STATUS_CODE_BF0_MASK             (0xFFFFU)
#define ECAT_AL_STATUS_CODE_BF0_SHIFT            (0U)
/*! BF0 - AL Status Code */
#define ECAT_AL_STATUS_CODE_BF0(x)               (((uint16_t)(((uint16_t)(x)) << ECAT_AL_STATUS_CODE_BF0_SHIFT)) & ECAT_AL_STATUS_CODE_BF0_MASK)
/*! @} */

/*! @name AL_STATUS_CODE_PDI - AL Status Code */
/*! @{ */

#define ECAT_AL_STATUS_CODE_PDI_BF0_MASK         (0xFFFFU)
#define ECAT_AL_STATUS_CODE_PDI_BF0_SHIFT        (0U)
/*! BF0 - AL Status Code */
#define ECAT_AL_STATUS_CODE_PDI_BF0(x)           (((uint16_t)(((uint16_t)(x)) << ECAT_AL_STATUS_CODE_PDI_BF0_SHIFT)) & ECAT_AL_STATUS_CODE_PDI_BF0_MASK)
/*! @} */

/*! @name RUN_LED_OVERRIDE - RUN LED Override */
/*! @{ */

#define ECAT_RUN_LED_OVERRIDE_BF0_MASK           (0xFU)
#define ECAT_RUN_LED_OVERRIDE_BF0_SHIFT          (0U)
/*! BF0 - LED code and AL Status */
#define ECAT_RUN_LED_OVERRIDE_BF0(x)             (((uint8_t)(((uint8_t)(x)) << ECAT_RUN_LED_OVERRIDE_BF0_SHIFT)) & ECAT_RUN_LED_OVERRIDE_BF0_MASK)

#define ECAT_RUN_LED_OVERRIDE_BF4_MASK           (0x10U)
#define ECAT_RUN_LED_OVERRIDE_BF4_SHIFT          (4U)
/*! BF4 - Enable Override:
 *  0b0..Override disabled
 *  0b1..Override enabled
 */
#define ECAT_RUN_LED_OVERRIDE_BF4(x)             (((uint8_t)(((uint8_t)(x)) << ECAT_RUN_LED_OVERRIDE_BF4_SHIFT)) & ECAT_RUN_LED_OVERRIDE_BF4_MASK)

#define ECAT_RUN_LED_OVERRIDE_BF5_MASK           (0xE0U)
#define ECAT_RUN_LED_OVERRIDE_BF5_SHIFT          (5U)
/*! BF5 - Reserved, write 0 */
#define ECAT_RUN_LED_OVERRIDE_BF5(x)             (((uint8_t)(((uint8_t)(x)) << ECAT_RUN_LED_OVERRIDE_BF5_SHIFT)) & ECAT_RUN_LED_OVERRIDE_BF5_MASK)
/*! @} */

/*! @name ERR_LED_OVERRIDE - ERR LED Override */
/*! @{ */

#define ECAT_ERR_LED_OVERRIDE_BF0_MASK           (0xFU)
#define ECAT_ERR_LED_OVERRIDE_BF0_SHIFT          (0U)
/*! BF0 - LED code */
#define ECAT_ERR_LED_OVERRIDE_BF0(x)             (((uint8_t)(((uint8_t)(x)) << ECAT_ERR_LED_OVERRIDE_BF0_SHIFT)) & ECAT_ERR_LED_OVERRIDE_BF0_MASK)

#define ECAT_ERR_LED_OVERRIDE_BF4_MASK           (0x10U)
#define ECAT_ERR_LED_OVERRIDE_BF4_SHIFT          (4U)
/*! BF4 - Enable Override:
 *  0b0..Override disabled
 *  0b1..Override enabled
 */
#define ECAT_ERR_LED_OVERRIDE_BF4(x)             (((uint8_t)(((uint8_t)(x)) << ECAT_ERR_LED_OVERRIDE_BF4_SHIFT)) & ECAT_ERR_LED_OVERRIDE_BF4_MASK)

#define ECAT_ERR_LED_OVERRIDE_BF5_MASK           (0xE0U)
#define ECAT_ERR_LED_OVERRIDE_BF5_SHIFT          (5U)
/*! BF5 - Reserved, write 0 */
#define ECAT_ERR_LED_OVERRIDE_BF5(x)             (((uint8_t)(((uint8_t)(x)) << ECAT_ERR_LED_OVERRIDE_BF5_SHIFT)) & ECAT_ERR_LED_OVERRIDE_BF5_MASK)
/*! @} */

/*! @name PDI_CONTROL - PDI Control */
/*! @{ */

#define ECAT_PDI_CONTROL_BF0_MASK                (0xFFU)
#define ECAT_PDI_CONTROL_BF0_SHIFT               (0U)
/*! BF0 - Process data interface:
 *  0b00000000..Interface deactivated (no PDI)
 *  0b00000001..4 Digital Input
 *  0b00000010..4 Digital Output
 *  0b00000011..2 Digital Input and 2 Digital Output
 *  0b00000100..Digital I/O
 *  0b00000101..SPI Slave
 *  0b00000110..Oversampling I/O
 *  0b00000111..Reserved
 *  0b00001000..16 Bit asynchronous Microcontroller interface
 *  0b00001001..8 Bit asynchronous Microcontroller interface
 *  0b00001010..16 Bit synchronous Microcontroller interface
 *  0b00001011..8 Bit synchronous Microcontroller interface
 *  0b00010000..32 Digital Input and 0 Digital Output
 *  0b00010001..24 Digital Input and 8 Digital Output
 *  0b00010010..16 Digital Input and 16 Digital Output
 *  0b00010011..8 Digital Input and 24 Digital Output
 *  0b00010100..0 Digital Input and 32 Digital Output
 *  0b10000000..On-chip bus.
 */
#define ECAT_PDI_CONTROL_BF0(x)                  (((uint8_t)(((uint8_t)(x)) << ECAT_PDI_CONTROL_BF0_SHIFT)) & ECAT_PDI_CONTROL_BF0_MASK)
/*! @} */

/*! @name ESC_CONFIGURATION - ESC Configuration */
/*! @{ */

#define ECAT_ESC_CONFIGURATION_BF0_MASK          (0x1U)
#define ECAT_ESC_CONFIGURATION_BF0_SHIFT         (0U)
/*! BF0 - Device emulation (control of AL status):
 *  0b0..AL status register has to be set by PDI
 *  0b1..AL status register will be set to value written to AL control register
 */
#define ECAT_ESC_CONFIGURATION_BF0(x)            (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_CONFIGURATION_BF0_SHIFT)) & ECAT_ESC_CONFIGURATION_BF0_MASK)

#define ECAT_ESC_CONFIGURATION_BF1_MASK          (0x2U)
#define ECAT_ESC_CONFIGURATION_BF1_SHIFT         (1U)
/*! BF1 - Enhanced Link detection all ports:
 *  0b0..disabled (if bits [7:4]=0)
 *  0b1..enabled at all ports (overrides bits [7:4])
 */
#define ECAT_ESC_CONFIGURATION_BF1(x)            (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_CONFIGURATION_BF1_SHIFT)) & ECAT_ESC_CONFIGURATION_BF1_MASK)

#define ECAT_ESC_CONFIGURATION_BF2_MASK          (0x4U)
#define ECAT_ESC_CONFIGURATION_BF2_SHIFT         (2U)
/*! BF2 - Distributed Clocks SYNC Out Unit:
 *  0b0..disabled (power saving)
 *  0b1..enabled
 */
#define ECAT_ESC_CONFIGURATION_BF2(x)            (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_CONFIGURATION_BF2_SHIFT)) & ECAT_ESC_CONFIGURATION_BF2_MASK)

#define ECAT_ESC_CONFIGURATION_BF3_MASK          (0x8U)
#define ECAT_ESC_CONFIGURATION_BF3_SHIFT         (3U)
/*! BF3 - Distributed Clocks Latch In Unit:
 *  0b0..disabled (power saving)
 *  0b1..enabled
 */
#define ECAT_ESC_CONFIGURATION_BF3(x)            (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_CONFIGURATION_BF3_SHIFT)) & ECAT_ESC_CONFIGURATION_BF3_MASK)

#define ECAT_ESC_CONFIGURATION_BF4_MASK          (0x10U)
#define ECAT_ESC_CONFIGURATION_BF4_SHIFT         (4U)
/*! BF4 - Enhanced Link port 0:
 *  0b0..disabled (if bit 1=0)
 *  0b1..enabled
 */
#define ECAT_ESC_CONFIGURATION_BF4(x)            (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_CONFIGURATION_BF4_SHIFT)) & ECAT_ESC_CONFIGURATION_BF4_MASK)

#define ECAT_ESC_CONFIGURATION_BF5_MASK          (0x20U)
#define ECAT_ESC_CONFIGURATION_BF5_SHIFT         (5U)
/*! BF5 - Enhanced Link port 1:
 *  0b0..disabled (if bit 1=0)
 *  0b1..enabled
 */
#define ECAT_ESC_CONFIGURATION_BF5(x)            (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_CONFIGURATION_BF5_SHIFT)) & ECAT_ESC_CONFIGURATION_BF5_MASK)

#define ECAT_ESC_CONFIGURATION_BF6_MASK          (0x40U)
#define ECAT_ESC_CONFIGURATION_BF6_SHIFT         (6U)
/*! BF6 - Reserved */
#define ECAT_ESC_CONFIGURATION_BF6(x)            (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_CONFIGURATION_BF6_SHIFT)) & ECAT_ESC_CONFIGURATION_BF6_MASK)

#define ECAT_ESC_CONFIGURATION_BF7_MASK          (0x80U)
#define ECAT_ESC_CONFIGURATION_BF7_SHIFT         (7U)
/*! BF7 - Reserved */
#define ECAT_ESC_CONFIGURATION_BF7(x)            (((uint8_t)(((uint8_t)(x)) << ECAT_ESC_CONFIGURATION_BF7_SHIFT)) & ECAT_ESC_CONFIGURATION_BF7_MASK)
/*! @} */

/*! @name PDI_INFORMATION - PDI Information */
/*! @{ */

#define ECAT_PDI_INFORMATION_BF0_MASK            (0x1U)
#define ECAT_PDI_INFORMATION_BF0_SHIFT           (0U)
/*! BF0 - PDI function
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ECAT_PDI_INFORMATION_BF0(x)              (((uint16_t)(((uint16_t)(x)) << ECAT_PDI_INFORMATION_BF0_SHIFT)) & ECAT_PDI_INFORMATION_BF0_MASK)

#define ECAT_PDI_INFORMATION_BF1_MASK            (0x2U)
#define ECAT_PDI_INFORMATION_BF1_SHIFT           (1U)
/*! BF1 - ESC configuration area loaded from EEPROM:
 *  0b0..not loaded
 *  0b1..loaded
 */
#define ECAT_PDI_INFORMATION_BF1(x)              (((uint16_t)(((uint16_t)(x)) << ECAT_PDI_INFORMATION_BF1_SHIFT)) & ECAT_PDI_INFORMATION_BF1_MASK)

#define ECAT_PDI_INFORMATION_BF2_MASK            (0x4U)
#define ECAT_PDI_INFORMATION_BF2_SHIFT           (2U)
/*! BF2 - PDI active:
 *  0b0..PDI not active
 *  0b1..PDI active
 */
#define ECAT_PDI_INFORMATION_BF2(x)              (((uint16_t)(((uint16_t)(x)) << ECAT_PDI_INFORMATION_BF2_SHIFT)) & ECAT_PDI_INFORMATION_BF2_MASK)

#define ECAT_PDI_INFORMATION_BF3_MASK            (0x8U)
#define ECAT_PDI_INFORMATION_BF3_SHIFT           (3U)
/*! BF3 - PDI configuration invalid:
 *  0b0..PDI configuration ok
 *  0b1..PDI configuration invalid
 */
#define ECAT_PDI_INFORMATION_BF3(x)              (((uint16_t)(((uint16_t)(x)) << ECAT_PDI_INFORMATION_BF3_SHIFT)) & ECAT_PDI_INFORMATION_BF3_MASK)

#define ECAT_PDI_INFORMATION_BF4_MASK            (0xFFF0U)
#define ECAT_PDI_INFORMATION_BF4_SHIFT           (4U)
/*! BF4 - Reserved */
#define ECAT_PDI_INFORMATION_BF4(x)              (((uint16_t)(((uint16_t)(x)) << ECAT_PDI_INFORMATION_BF4_SHIFT)) & ECAT_PDI_INFORMATION_BF4_MASK)
/*! @} */

/*! @name PDI_ON_CHIP_BUS_CONFIGURATION - Register PDI On-chip bus configuration */
/*! @{ */

#define ECAT_PDI_ON_CHIP_BUS_CONFIGURATION_BF0_MASK (0x1FU)
#define ECAT_PDI_ON_CHIP_BUS_CONFIGURATION_BF0_SHIFT (0U)
/*! BF0 - On-chip bus clock:
 *  0b00000..asynchronous
 *  0b00001-0b11111..synchronous multiplication factor (N * 25 MHz)
 */
#define ECAT_PDI_ON_CHIP_BUS_CONFIGURATION_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_PDI_ON_CHIP_BUS_CONFIGURATION_BF0_SHIFT)) & ECAT_PDI_ON_CHIP_BUS_CONFIGURATION_BF0_MASK)

#define ECAT_PDI_ON_CHIP_BUS_CONFIGURATION_BF5_MASK (0xE0U)
#define ECAT_PDI_ON_CHIP_BUS_CONFIGURATION_BF5_SHIFT (5U)
/*! BF5 - On-chip bus
 *  0b000..Intel® Avalon®
 *  0b001..AXI® 010: Xilinx® PLB v4.6
 *  0b100..Xilinx OPB
 */
#define ECAT_PDI_ON_CHIP_BUS_CONFIGURATION_BF5(x) (((uint8_t)(((uint8_t)(x)) << ECAT_PDI_ON_CHIP_BUS_CONFIGURATION_BF5_SHIFT)) & ECAT_PDI_ON_CHIP_BUS_CONFIGURATION_BF5_MASK)
/*! @} */

/*! @name SYNC_LATCH_1_AND_0_PDI_CONFIGURATION - PDI Configuration Sync Latch 1 and 0 PDI Configuration */
/*! @{ */

#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF0_MASK (0x3U)
#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF0_SHIFT (0U)
/*! BF0 - SYNC0 output driver/polarity:
 *  0b00..Push-Pull active low
 *  0b01..Open Drain (active low)
 *  0b10..Push-Pull active high
 *  0b11..Open Source (active high)
 */
#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF0_SHIFT)) & ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF0_MASK)

#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF2_MASK (0x4U)
#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF2_SHIFT (2U)
/*! BF2 - SYNC0/LATCH0 configuration*:
 *  0b0..LATCH0 Input
 *  0b1..SYNC0 Output
 */
#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF2(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF2_SHIFT)) & ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF2_MASK)

#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF3_MASK (0x8U)
#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF3_SHIFT (3U)
/*! BF3 - SYNC0 mapped to AL Event Request register 0x0220[2]:
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF3(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF3_SHIFT)) & ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF3_MASK)

#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF4_MASK (0x30U)
#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF4_SHIFT (4U)
/*! BF4 - SYNC1 output driver/polarity:
 *  0b00..Push-Pull active low
 *  0b01..Open Drain (active low)
 *  0b10..Push-Pull active high
 *  0b11..Open Source (active high)
 */
#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF4(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF4_SHIFT)) & ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF4_MASK)

#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF6_MASK (0x40U)
#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF6_SHIFT (6U)
/*! BF6 - SYNC1/LATCH1 configuration*
 *  0b0..LATCH1 input
 *  0b1..SYNC1 output
 */
#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF6(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF6_SHIFT)) & ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF6_MASK)

#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF7_MASK (0x80U)
#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF7_SHIFT (7U)
/*! BF7 - SYNC1 mapped to AL Event Request register 0x0220[3]:
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF7(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF7_SHIFT)) & ECAT_SYNC_LATCH_1_AND_0_PDI_CONFIGURATION_BF7_MASK)
/*! @} */

/*! @name PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION - Register PDI On-chip bus extended configuration. */
/*! @{ */

#define ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF0_MASK (0x3U)
#define ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF0_SHIFT (0U)
/*! BF0 - Read prefetch size (in cycles of PDI width):
 *  0b00..4 cycles
 *  0b01..1 cycle (typical)
 *  0b10..2 cycles
 *  0b11..Reserved
 */
#define ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF0(x) (((uint16_t)(((uint16_t)(x)) << ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF0_SHIFT)) & ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF0_MASK)

#define ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF2_MASK (0xFCU)
#define ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF2_SHIFT (2U)
/*! BF2 - Reserved */
#define ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF2(x) (((uint16_t)(((uint16_t)(x)) << ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF2_SHIFT)) & ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF2_MASK)

#define ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF8_MASK (0x700U)
#define ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF8_SHIFT (8U)
/*! BF8 - On-chip bus sub-type for AXI:
 *  0b000..AXI3
 *  0b001..AXI4
 *  0b010..AXI4 LITE
 */
#define ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF8(x) (((uint16_t)(((uint16_t)(x)) << ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF8_SHIFT)) & ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF8_MASK)

#define ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF11_MASK (0xF800U)
#define ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF11_SHIFT (11U)
/*! BF11 - Reserved */
#define ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF11(x) (((uint16_t)(((uint16_t)(x)) << ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF11_SHIFT)) & ECAT_PDI_ON_CHIP_BUS_EXTENDED_CONFIGURATION_BF11_MASK)
/*! @} */

/*! @name ECAT_EVENT_MASK - ECAT Event Mask */
/*! @{ */

#define ECAT_ECAT_EVENT_MASK_BF0_MASK            (0xFFFFU)
#define ECAT_ECAT_EVENT_MASK_BF0_SHIFT           (0U)
/*! BF0 - ECAT Event masking of the ECAT Event Request Events for mapping into ECAT event field of EtherCAT frames:
 *  0b0000000000000000..Corresponding ECAT Event Request register bit is not mapped
 *  0b0000000000000001..Corresponding ECAT Event Request register bit is mapped
 */
#define ECAT_ECAT_EVENT_MASK_BF0(x)              (((uint16_t)(((uint16_t)(x)) << ECAT_ECAT_EVENT_MASK_BF0_SHIFT)) & ECAT_ECAT_EVENT_MASK_BF0_MASK)
/*! @} */

/*! @name ECAT_EVENT_MASK_PDI - ECAT Event Mask */
/*! @{ */

#define ECAT_ECAT_EVENT_MASK_PDI_BF0_MASK        (0xFFFFU)
#define ECAT_ECAT_EVENT_MASK_PDI_BF0_SHIFT       (0U)
/*! BF0 - ECAT Event masking of the ECAT Event Request Events for mapping into ECAT event field of EtherCAT frames:
 *  0b0000000000000000..Corresponding ECAT Event Request register bit is not mapped
 *  0b0000000000000001..Corresponding ECAT Event Request register bit is mapped
 */
#define ECAT_ECAT_EVENT_MASK_PDI_BF0(x)          (((uint16_t)(((uint16_t)(x)) << ECAT_ECAT_EVENT_MASK_PDI_BF0_SHIFT)) & ECAT_ECAT_EVENT_MASK_PDI_BF0_MASK)
/*! @} */

/*! @name PDI_AL_EVENT_MASK - PDI AL Event Mask */
/*! @{ */

#define ECAT_PDI_AL_EVENT_MASK_BF0_MASK          (0xFFFFFFFFU)
#define ECAT_PDI_AL_EVENT_MASK_BF0_SHIFT         (0U)
/*! BF0 - AL Event masking of the AL Event Request register Events for mapping to PDI IRQ signal:
 *  0b00000000000000000000000000000000..Corresponding AL Event Request register bit is not mapped
 *  0b00000000000000000000000000000001..Corresponding AL Event Request register bit is mapped
 */
#define ECAT_PDI_AL_EVENT_MASK_BF0(x)            (((uint32_t)(((uint32_t)(x)) << ECAT_PDI_AL_EVENT_MASK_BF0_SHIFT)) & ECAT_PDI_AL_EVENT_MASK_BF0_MASK)
/*! @} */

/*! @name PDI_AL_EVENT_MASK_PDI - PDI AL Event Mask */
/*! @{ */

#define ECAT_PDI_AL_EVENT_MASK_PDI_BF0_MASK      (0xFFFFFFFFU)
#define ECAT_PDI_AL_EVENT_MASK_PDI_BF0_SHIFT     (0U)
/*! BF0 - AL Event masking of the AL Event Request register Events for mapping to PDI IRQ signal:
 *  0b00000000000000000000000000000000..Corresponding AL Event Request register bit is not mapped
 *  0b00000000000000000000000000000001..Corresponding AL Event Request register bit is mapped
 */
#define ECAT_PDI_AL_EVENT_MASK_PDI_BF0(x)        (((uint32_t)(((uint32_t)(x)) << ECAT_PDI_AL_EVENT_MASK_PDI_BF0_SHIFT)) & ECAT_PDI_AL_EVENT_MASK_PDI_BF0_MASK)
/*! @} */

/*! @name ECAT_EVENT_REQUEST - ECAT Event Request */
/*! @{ */

#define ECAT_ECAT_EVENT_REQUEST_BF0_MASK         (0x1U)
#define ECAT_ECAT_EVENT_REQUEST_BF0_SHIFT        (0U)
/*! BF0 - DC Latch event:
 *  0b0..No change on DC Latch Inputs
 *  0b1..At least one change on DC Latch Inputs
 */
#define ECAT_ECAT_EVENT_REQUEST_BF0(x)           (((uint16_t)(((uint16_t)(x)) << ECAT_ECAT_EVENT_REQUEST_BF0_SHIFT)) & ECAT_ECAT_EVENT_REQUEST_BF0_MASK)

#define ECAT_ECAT_EVENT_REQUEST_BF1_MASK         (0x2U)
#define ECAT_ECAT_EVENT_REQUEST_BF1_SHIFT        (1U)
/*! BF1 - Reserved */
#define ECAT_ECAT_EVENT_REQUEST_BF1(x)           (((uint16_t)(((uint16_t)(x)) << ECAT_ECAT_EVENT_REQUEST_BF1_SHIFT)) & ECAT_ECAT_EVENT_REQUEST_BF1_MASK)

#define ECAT_ECAT_EVENT_REQUEST_BF2_MASK         (0x4U)
#define ECAT_ECAT_EVENT_REQUEST_BF2_SHIFT        (2U)
/*! BF2 - DL Status event:
 *  0b0..No change in DL Status
 *  0b1..DL Status change
 */
#define ECAT_ECAT_EVENT_REQUEST_BF2(x)           (((uint16_t)(((uint16_t)(x)) << ECAT_ECAT_EVENT_REQUEST_BF2_SHIFT)) & ECAT_ECAT_EVENT_REQUEST_BF2_MASK)

#define ECAT_ECAT_EVENT_REQUEST_BF3_MASK         (0x8U)
#define ECAT_ECAT_EVENT_REQUEST_BF3_SHIFT        (3U)
/*! BF3 - AL Status event:
 *  0b0..No change in AL Status
 *  0b1..AL Status change
 */
#define ECAT_ECAT_EVENT_REQUEST_BF3(x)           (((uint16_t)(((uint16_t)(x)) << ECAT_ECAT_EVENT_REQUEST_BF3_SHIFT)) & ECAT_ECAT_EVENT_REQUEST_BF3_MASK)

#define ECAT_ECAT_EVENT_REQUEST_BF4_MASK         (0x10U)
#define ECAT_ECAT_EVENT_REQUEST_BF4_SHIFT        (4U)
/*! BF4 - Mirrors values of each SyncManager Status:
 *  0b0..No Sync Channel 0 event
 *  0b1..Sync Channel 0 event pending
 */
#define ECAT_ECAT_EVENT_REQUEST_BF4(x)           (((uint16_t)(((uint16_t)(x)) << ECAT_ECAT_EVENT_REQUEST_BF4_SHIFT)) & ECAT_ECAT_EVENT_REQUEST_BF4_MASK)

#define ECAT_ECAT_EVENT_REQUEST_BF5_MASK         (0x20U)
#define ECAT_ECAT_EVENT_REQUEST_BF5_SHIFT        (5U)
/*! BF5 - Mirrors values of each SyncManager Status:
 *  0b0..No Sync Channel 1 event
 *  0b1..Sync Channel 1 event pending
 */
#define ECAT_ECAT_EVENT_REQUEST_BF5(x)           (((uint16_t)(((uint16_t)(x)) << ECAT_ECAT_EVENT_REQUEST_BF5_SHIFT)) & ECAT_ECAT_EVENT_REQUEST_BF5_MASK)

#define ECAT_ECAT_EVENT_REQUEST_BF6_MASK         (0x40U)
#define ECAT_ECAT_EVENT_REQUEST_BF6_SHIFT        (6U)
/*! BF6 - Mirrors values of each SyncManager Status:
 *  0b0..No Sync Channel 2 event
 *  0b1..Sync Channel 2 event pending
 */
#define ECAT_ECAT_EVENT_REQUEST_BF6(x)           (((uint16_t)(((uint16_t)(x)) << ECAT_ECAT_EVENT_REQUEST_BF6_SHIFT)) & ECAT_ECAT_EVENT_REQUEST_BF6_MASK)

#define ECAT_ECAT_EVENT_REQUEST_BF7_MASK         (0x80U)
#define ECAT_ECAT_EVENT_REQUEST_BF7_SHIFT        (7U)
/*! BF7 - Mirrors values of each SyncManager Status:
 *  0b0..No Sync Channel 3 event
 *  0b1..Sync Channel 3 event pending
 */
#define ECAT_ECAT_EVENT_REQUEST_BF7(x)           (((uint16_t)(((uint16_t)(x)) << ECAT_ECAT_EVENT_REQUEST_BF7_SHIFT)) & ECAT_ECAT_EVENT_REQUEST_BF7_MASK)

#define ECAT_ECAT_EVENT_REQUEST_BF8_MASK         (0x100U)
#define ECAT_ECAT_EVENT_REQUEST_BF8_SHIFT        (8U)
/*! BF8 - Mirrors values of each SyncManager Status:
 *  0b0..No Sync Channel 4 event
 *  0b1..Sync Channel 4 event pending
 */
#define ECAT_ECAT_EVENT_REQUEST_BF8(x)           (((uint16_t)(((uint16_t)(x)) << ECAT_ECAT_EVENT_REQUEST_BF8_SHIFT)) & ECAT_ECAT_EVENT_REQUEST_BF8_MASK)

#define ECAT_ECAT_EVENT_REQUEST_BF9_MASK         (0x200U)
#define ECAT_ECAT_EVENT_REQUEST_BF9_SHIFT        (9U)
/*! BF9 - Mirrors values of each SyncManager Status:
 *  0b0..No Sync Channel 5 event
 *  0b1..Sync Channel 5 event pending
 */
#define ECAT_ECAT_EVENT_REQUEST_BF9(x)           (((uint16_t)(((uint16_t)(x)) << ECAT_ECAT_EVENT_REQUEST_BF9_SHIFT)) & ECAT_ECAT_EVENT_REQUEST_BF9_MASK)

#define ECAT_ECAT_EVENT_REQUEST_BF10_MASK        (0x400U)
#define ECAT_ECAT_EVENT_REQUEST_BF10_SHIFT       (10U)
/*! BF10 - Mirrors values of each SyncManager Status:
 *  0b0..No Sync Channel 6 event
 *  0b1..Sync Channel 6 event pending
 */
#define ECAT_ECAT_EVENT_REQUEST_BF10(x)          (((uint16_t)(((uint16_t)(x)) << ECAT_ECAT_EVENT_REQUEST_BF10_SHIFT)) & ECAT_ECAT_EVENT_REQUEST_BF10_MASK)

#define ECAT_ECAT_EVENT_REQUEST_BF11_MASK        (0x800U)
#define ECAT_ECAT_EVENT_REQUEST_BF11_SHIFT       (11U)
/*! BF11 - Mirrors values of each SyncManager Status:
 *  0b0..No Sync Channel 7 event
 *  0b1..Sync Channel 7 event pending
 */
#define ECAT_ECAT_EVENT_REQUEST_BF11(x)          (((uint16_t)(((uint16_t)(x)) << ECAT_ECAT_EVENT_REQUEST_BF11_SHIFT)) & ECAT_ECAT_EVENT_REQUEST_BF11_MASK)

#define ECAT_ECAT_EVENT_REQUEST_BF12_MASK        (0xF000U)
#define ECAT_ECAT_EVENT_REQUEST_BF12_SHIFT       (12U)
/*! BF12 - Reserved */
#define ECAT_ECAT_EVENT_REQUEST_BF12(x)          (((uint16_t)(((uint16_t)(x)) << ECAT_ECAT_EVENT_REQUEST_BF12_SHIFT)) & ECAT_ECAT_EVENT_REQUEST_BF12_MASK)
/*! @} */

/*! @name AL_EVENT_REQUEST - AL Event request */
/*! @{ */

#define ECAT_AL_EVENT_REQUEST_BF0_MASK           (0x1U)
#define ECAT_AL_EVENT_REQUEST_BF0_SHIFT          (0U)
/*! BF0 - AL Control event:
 *  0b0..No AL Control Register change
 *  0b1..AL Control Register has been written3
 */
#define ECAT_AL_EVENT_REQUEST_BF0(x)             (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF0_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF0_MASK)

#define ECAT_AL_EVENT_REQUEST_BF1_MASK           (0x2U)
#define ECAT_AL_EVENT_REQUEST_BF1_SHIFT          (1U)
/*! BF1 - DC Latch event:
 *  0b0..No change on DC Latch Inputs
 *  0b1..At least one change on DC Latch Inputs
 */
#define ECAT_AL_EVENT_REQUEST_BF1(x)             (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF1_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF1_MASK)

#define ECAT_AL_EVENT_REQUEST_BF2_MASK           (0x4U)
#define ECAT_AL_EVENT_REQUEST_BF2_SHIFT          (2U)
/*! BF2 - State of DC SYNC0 (if register 0x0151[3]=1): */
#define ECAT_AL_EVENT_REQUEST_BF2(x)             (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF2_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF2_MASK)

#define ECAT_AL_EVENT_REQUEST_BF3_MASK           (0x8U)
#define ECAT_AL_EVENT_REQUEST_BF3_SHIFT          (3U)
/*! BF3 - State of DC SYNC1 (if register 0x0151[7]=1): */
#define ECAT_AL_EVENT_REQUEST_BF3(x)             (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF3_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF3_MASK)

#define ECAT_AL_EVENT_REQUEST_BF4_MASK           (0x10U)
#define ECAT_AL_EVENT_REQUEST_BF4_SHIFT          (4U)
/*! BF4 - SyncManager activation register (SyncManager register offset 0x6) changed:
 *  0b0..No change in any SyncManager
 *  0b1..At least one SyncManager changed
 */
#define ECAT_AL_EVENT_REQUEST_BF4(x)             (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF4_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF4_MASK)

#define ECAT_AL_EVENT_REQUEST_BF5_MASK           (0x20U)
#define ECAT_AL_EVENT_REQUEST_BF5_SHIFT          (5U)
/*! BF5 - EEPROM Emulation:
 *  0b0..No command pending
 *  0b1..EEPROM command pending
 */
#define ECAT_AL_EVENT_REQUEST_BF5(x)             (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF5_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF5_MASK)

#define ECAT_AL_EVENT_REQUEST_BF6_MASK           (0x40U)
#define ECAT_AL_EVENT_REQUEST_BF6_SHIFT          (6U)
/*! BF6 - Watchdog Process Data:
 *  0b0..Has not expired
 *  0b1..Has expired
 */
#define ECAT_AL_EVENT_REQUEST_BF6(x)             (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF6_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF6_MASK)

#define ECAT_AL_EVENT_REQUEST_BF7_MASK           (0x80U)
#define ECAT_AL_EVENT_REQUEST_BF7_SHIFT          (7U)
/*! BF7 - Reserved */
#define ECAT_AL_EVENT_REQUEST_BF7(x)             (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF7_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF7_MASK)

#define ECAT_AL_EVENT_REQUEST_BF8_MASK           (0x100U)
#define ECAT_AL_EVENT_REQUEST_BF8_SHIFT          (8U)
/*! BF8 - SyncManager interrupts (SyncManager register offset 0x5, bit [0] or [1]):
 *  0b0..No SyncManager 0 interrupt
 *  0b1..SyncManager 0 interrupt pending
 */
#define ECAT_AL_EVENT_REQUEST_BF8(x)             (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF8_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF8_MASK)

#define ECAT_AL_EVENT_REQUEST_BF9_MASK           (0x200U)
#define ECAT_AL_EVENT_REQUEST_BF9_SHIFT          (9U)
/*! BF9 - Bit field access for ECAT: r/-
 *  0b0..No SyncManager 1 interrupt
 *  0b1..SyncManager 1 interrupt pending
 */
#define ECAT_AL_EVENT_REQUEST_BF9(x)             (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF9_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF9_MASK)

#define ECAT_AL_EVENT_REQUEST_BF10_MASK          (0x400U)
#define ECAT_AL_EVENT_REQUEST_BF10_SHIFT         (10U)
/*! BF10 - Bit field access for ECAT: r/-
 *  0b0..No SyncManager2 interrupt
 *  0b1..SyncManager 2 interrupt pending
 */
#define ECAT_AL_EVENT_REQUEST_BF10(x)            (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF10_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF10_MASK)

#define ECAT_AL_EVENT_REQUEST_BF11_MASK          (0x800U)
#define ECAT_AL_EVENT_REQUEST_BF11_SHIFT         (11U)
/*! BF11 - Bit field access for ECAT: r/-
 *  0b0..No SyncManager 3 interrupt
 *  0b1..SyncManager 3 interrupt pending
 */
#define ECAT_AL_EVENT_REQUEST_BF11(x)            (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF11_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF11_MASK)

#define ECAT_AL_EVENT_REQUEST_BF12_MASK          (0x1000U)
#define ECAT_AL_EVENT_REQUEST_BF12_SHIFT         (12U)
/*! BF12 - Bit field access for ECAT: r/-
 *  0b0..No SyncManager4 interrupt
 *  0b1..SyncManager 4 interrupt pending
 */
#define ECAT_AL_EVENT_REQUEST_BF12(x)            (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF12_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF12_MASK)

#define ECAT_AL_EVENT_REQUEST_BF13_MASK          (0x2000U)
#define ECAT_AL_EVENT_REQUEST_BF13_SHIFT         (13U)
/*! BF13 - Bit field access for ECAT: r/-
 *  0b0..No SyncManager 5 interrupt
 *  0b1..SyncManager 5 interrupt pending
 */
#define ECAT_AL_EVENT_REQUEST_BF13(x)            (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF13_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF13_MASK)

#define ECAT_AL_EVENT_REQUEST_BF14_MASK          (0x4000U)
#define ECAT_AL_EVENT_REQUEST_BF14_SHIFT         (14U)
/*! BF14 - Bit field access for ECAT: r/-
 *  0b0..No SyncManager 6 interrupt
 *  0b1..SyncManager6 interrupt pending
 */
#define ECAT_AL_EVENT_REQUEST_BF14(x)            (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF14_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF14_MASK)

#define ECAT_AL_EVENT_REQUEST_BF15_MASK          (0x8000U)
#define ECAT_AL_EVENT_REQUEST_BF15_SHIFT         (15U)
/*! BF15 - Bit field access for ECAT: r/-
 *  0b0..No SyncManager 7 interrupt
 *  0b1..SyncManager 7 interrupt pending
 */
#define ECAT_AL_EVENT_REQUEST_BF15(x)            (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF15_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF15_MASK)

#define ECAT_AL_EVENT_REQUEST_BF16_MASK          (0xFFFF0000U)
#define ECAT_AL_EVENT_REQUEST_BF16_SHIFT         (16U)
/*! BF16 - Reserved */
#define ECAT_AL_EVENT_REQUEST_BF16(x)            (((uint32_t)(((uint32_t)(x)) << ECAT_AL_EVENT_REQUEST_BF16_SHIFT)) & ECAT_AL_EVENT_REQUEST_BF16_MASK)
/*! @} */

/*! @name RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT - RX Error Counter */
/*! @{ */

#define ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_BF0_MASK (0xFFU)
#define ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_BF0_SHIFT (0U)
/*! BF0 - Invalid frame counter of Port y (counting is stopped when 0xFF is reached). */
#define ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_BF0(x) (((uint16_t)(((uint16_t)(x)) << ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_BF0_SHIFT)) & ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_BF0_MASK)

#define ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_BF8_MASK (0xFF00U)
#define ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_BF8_SHIFT (8U)
/*! BF8 - RX Error counter of Port y (counting is stopped when 0xFF is reached). */
#define ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_BF8(x) (((uint16_t)(((uint16_t)(x)) << ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_BF8_SHIFT)) & ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_BF8_MASK)
/*! @} */

/* The count of ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT */
#define ECAT_RX_ERROR_COUNT_E                    (2U)

/*! @name RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_PDI - RX Error Counter */
/*! @{ */

#define ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_PDI_BF0_MASK (0xFFU)
#define ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_PDI_BF0_SHIFT (0U)
/*! BF0 - Invalid frame counter of Port y (counting is stopped when 0xFF is reached). */
#define ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_PDI_BF0(x) (((uint16_t)(((uint16_t)(x)) << ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_PDI_BF0_SHIFT)) & ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_PDI_BF0_MASK)

#define ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_PDI_BF8_MASK (0xFF00U)
#define ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_PDI_BF8_SHIFT (8U)
/*! BF8 - RX Error counter of Port y (counting is stopped when 0xFF is reached). */
#define ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_PDI_BF8(x) (((uint16_t)(((uint16_t)(x)) << ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_PDI_BF8_SHIFT)) & ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_PDI_BF8_MASK)
/*! @} */

/* The count of ECAT_RX_ERROR_CNTR_RX_ERROR_COUNTER_PORT_PDI */
#define ECAT_RX_ERROR_COUNT_P                    (2U)

/*! @name FORWARDED_RX_ERROR_CNTR_FORWARDED_RX_ERROR_COUNTER_PORT - Forwarded RX Error Counter */
/*! @{ */

#define ECAT_FORWARDED_RX_ERROR_CNTR_FORWARDED_RX_ERROR_COUNTER_PORT_BF0_MASK (0xFFU)
#define ECAT_FORWARDED_RX_ERROR_CNTR_FORWARDED_RX_ERROR_COUNTER_PORT_BF0_SHIFT (0U)
/*! BF0 - Forwarded error counter of Port y (counting is stopped when 0xFF is reached). */
#define ECAT_FORWARDED_RX_ERROR_CNTR_FORWARDED_RX_ERROR_COUNTER_PORT_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_FORWARDED_RX_ERROR_CNTR_FORWARDED_RX_ERROR_COUNTER_PORT_BF0_SHIFT)) & ECAT_FORWARDED_RX_ERROR_CNTR_FORWARDED_RX_ERROR_COUNTER_PORT_BF0_MASK)
/*! @} */

/* The count of ECAT_FORWARDED_RX_ERROR_CNTR_FORWARDED_RX_ERROR_COUNTER_PORT */
#define ECAT_FORWARDED_RX_ERROR_COUNT_E          (2U)

/*! @name FORWARDED_RX_ERROR_CNTR_FORWARDED_RX_ERROR_COUNTER_PORT_PDI - Forwarded RX Error Counter */
/*! @{ */

#define ECAT_FORWARDED_RX_ERROR_CNTR_FORWARDED_RX_ERROR_COUNTER_PORT_PDI_BF0_MASK (0xFFU)
#define ECAT_FORWARDED_RX_ERROR_CNTR_FORWARDED_RX_ERROR_COUNTER_PORT_PDI_BF0_SHIFT (0U)
/*! BF0 - Forwarded error counter of Port y (counting is stopped when 0xFF is reached). */
#define ECAT_FORWARDED_RX_ERROR_CNTR_FORWARDED_RX_ERROR_COUNTER_PORT_PDI_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_FORWARDED_RX_ERROR_CNTR_FORWARDED_RX_ERROR_COUNTER_PORT_PDI_BF0_SHIFT)) & ECAT_FORWARDED_RX_ERROR_CNTR_FORWARDED_RX_ERROR_COUNTER_PORT_PDI_BF0_MASK)
/*! @} */

/* The count of ECAT_FORWARDED_RX_ERROR_CNTR_FORWARDED_RX_ERROR_COUNTER_PORT_PDI */
#define ECAT_FORWARDED_RX_ERROR_COUNT_P          (2U)

/*! @name ECAT_PROCESSING_UNIT_ERROR_COUNTER - ECAT Processing Unit Error Counter */
/*! @{ */

#define ECAT_ECAT_PROCESSING_UNIT_ERROR_COUNTER_BF0_MASK (0xFFU)
#define ECAT_ECAT_PROCESSING_UNIT_ERROR_COUNTER_BF0_SHIFT (0U)
/*! BF0 - ECAT Processing Unit error counter (counting is stopped when 0xFF is reached). Counts
 *    errors of frames passing the Processing Unit.
 */
#define ECAT_ECAT_PROCESSING_UNIT_ERROR_COUNTER_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_ECAT_PROCESSING_UNIT_ERROR_COUNTER_BF0_SHIFT)) & ECAT_ECAT_PROCESSING_UNIT_ERROR_COUNTER_BF0_MASK)
/*! @} */

/*! @name ECAT_PROCESSING_UNIT_ERROR_COUNTER_PDI - ECAT Processing Unit Error Counter */
/*! @{ */

#define ECAT_ECAT_PROCESSING_UNIT_ERROR_COUNTER_PDI_BF0_MASK (0xFFU)
#define ECAT_ECAT_PROCESSING_UNIT_ERROR_COUNTER_PDI_BF0_SHIFT (0U)
/*! BF0 - ECAT Processing Unit error counter (counting is stopped when 0xFF is reached). Counts
 *    errors of frames passing the Processing Unit.
 */
#define ECAT_ECAT_PROCESSING_UNIT_ERROR_COUNTER_PDI_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_ECAT_PROCESSING_UNIT_ERROR_COUNTER_PDI_BF0_SHIFT)) & ECAT_ECAT_PROCESSING_UNIT_ERROR_COUNTER_PDI_BF0_MASK)
/*! @} */

/*! @name PDI_ERROR_COUNTER - PDI Error counter */
/*! @{ */

#define ECAT_PDI_ERROR_COUNTER_BF0_MASK          (0xFFU)
#define ECAT_PDI_ERROR_COUNTER_BF0_SHIFT         (0U)
/*! BF0 - PDI Error counter (counting is stopped when 0xFF is reached). Counts if a PDI access has an interface error. */
#define ECAT_PDI_ERROR_COUNTER_BF0(x)            (((uint8_t)(((uint8_t)(x)) << ECAT_PDI_ERROR_COUNTER_BF0_SHIFT)) & ECAT_PDI_ERROR_COUNTER_BF0_MASK)
/*! @} */

/*! @name PDI_ERROR_COUNTER_PDI - PDI Error counter */
/*! @{ */

#define ECAT_PDI_ERROR_COUNTER_PDI_BF0_MASK      (0xFFU)
#define ECAT_PDI_ERROR_COUNTER_PDI_BF0_SHIFT     (0U)
/*! BF0 - PDI Error counter (counting is stopped when 0xFF is reached). Counts if a PDI access has an interface error. */
#define ECAT_PDI_ERROR_COUNTER_PDI_BF0(x)        (((uint8_t)(((uint8_t)(x)) << ECAT_PDI_ERROR_COUNTER_PDI_BF0_SHIFT)) & ECAT_PDI_ERROR_COUNTER_PDI_BF0_MASK)
/*! @} */

/*! @name ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER - ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_PDI_ERROR_CODE. */
/*! @{ */

#define ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF0_MASK (0x1U)
#define ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF0_SHIFT (0U)
/*! BF0 - Busy violation during read access
 *  0b0..no error
 *  0b1..error detected
 */
#define ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF0_SHIFT)) & ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF0_MASK)

#define ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF1_MASK (0x2U)
#define ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF1_SHIFT (1U)
/*! BF1 - Busy violation during write access
 *  0b0..no error
 *  0b1..error detected
 */
#define ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF1(x) (((uint8_t)(((uint8_t)(x)) << ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF1_SHIFT)) & ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF1_MASK)

#define ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF2_MASK (0x4U)
#define ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF2_SHIFT (2U)
/*! BF2 - Addressing error for a read access (odd address without BHE)
 *  0b0..no error
 *  0b1..error detected
 */
#define ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF2(x) (((uint8_t)(((uint8_t)(x)) << ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF2_SHIFT)) & ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF2_MASK)

#define ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF3_MASK (0x8U)
#define ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF3_SHIFT (3U)
/*! BF3 - Addressing error for a write access (odd address without BHE)
 *  0b0..no error
 *  0b1..error detected
 */
#define ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF3(x) (((uint8_t)(((uint8_t)(x)) << ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF3_SHIFT)) & ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF3_MASK)

#define ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF4_MASK (0xF0U)
#define ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF4_SHIFT (4U)
/*! BF4 - reserved */
#define ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF4(x) (((uint8_t)(((uint8_t)(x)) << ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF4_SHIFT)) & ECAT_ASYNCHRONOUS_SYNCHRONOUS_MICROCONTROLLER_BF4_MASK)
/*! @} */

/*! @name LOST_LINK_CNTR_LOST_LINK_COUNTER_PORT - Lost Link Counter */
/*! @{ */

#define ECAT_LOST_LINK_CNTR_LOST_LINK_COUNTER_PORT_BF0_MASK (0xFFU)
#define ECAT_LOST_LINK_CNTR_LOST_LINK_COUNTER_PORT_BF0_SHIFT (0U)
/*! BF0 - Lost Link counter of Port y (counting is stopped when 0xff is reached). */
#define ECAT_LOST_LINK_CNTR_LOST_LINK_COUNTER_PORT_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_LOST_LINK_CNTR_LOST_LINK_COUNTER_PORT_BF0_SHIFT)) & ECAT_LOST_LINK_CNTR_LOST_LINK_COUNTER_PORT_BF0_MASK)
/*! @} */

/* The count of ECAT_LOST_LINK_CNTR_LOST_LINK_COUNTER_PORT */
#define ECAT_LOST_LINK_CNTR_LOST_LINK_COUNTER_PORT_COUNT (2U)

/*! @name LOST_LINK_CNTR_LOST_LINK_COUNTER_PORT_PDI - Lost Link Counter */
/*! @{ */

#define ECAT_LOST_LINK_CNTR_LOST_LINK_COUNTER_PORT_PDI_BF0_MASK (0xFFU)
#define ECAT_LOST_LINK_CNTR_LOST_LINK_COUNTER_PORT_PDI_BF0_SHIFT (0U)
/*! BF0 - Lost Link counter of Port y (counting is stopped when 0xff is reached). */
#define ECAT_LOST_LINK_CNTR_LOST_LINK_COUNTER_PORT_PDI_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_LOST_LINK_CNTR_LOST_LINK_COUNTER_PORT_PDI_BF0_SHIFT)) & ECAT_LOST_LINK_CNTR_LOST_LINK_COUNTER_PORT_PDI_BF0_MASK)
/*! @} */

/* The count of ECAT_LOST_LINK_CNTR_LOST_LINK_COUNTER_PORT_PDI */
#define ECAT_LOST_LINK_CNTR_LOST_LINK_COUNTER_PORT_PDI_COUNT (2U)

/*! @name WATCHDOG_DIVIDER - Watchdog Divider */
/*! @{ */

#define ECAT_WATCHDOG_DIVIDER_BF0_MASK           (0xFFFFU)
#define ECAT_WATCHDOG_DIVIDER_BF0_SHIFT          (0U)
/*! BF0 - Watchdog divider: Number of 25 MHz tics (minus 2) that represent the basic watchdog
 *    increment. (Default value is 100us = 2498)
 */
#define ECAT_WATCHDOG_DIVIDER_BF0(x)             (((uint16_t)(((uint16_t)(x)) << ECAT_WATCHDOG_DIVIDER_BF0_SHIFT)) & ECAT_WATCHDOG_DIVIDER_BF0_MASK)
/*! @} */

/*! @name WATCHDOG_DIVIDER_PDI - Watchdog Divider */
/*! @{ */

#define ECAT_WATCHDOG_DIVIDER_PDI_BF0_MASK       (0xFFFFU)
#define ECAT_WATCHDOG_DIVIDER_PDI_BF0_SHIFT      (0U)
/*! BF0 - Watchdog divider: Number of 25 MHz tics (minus 2) that represent the basic watchdog
 *    increment. (Default value is 100us = 2498)
 */
#define ECAT_WATCHDOG_DIVIDER_PDI_BF0(x)         (((uint16_t)(((uint16_t)(x)) << ECAT_WATCHDOG_DIVIDER_PDI_BF0_SHIFT)) & ECAT_WATCHDOG_DIVIDER_PDI_BF0_MASK)
/*! @} */

/*! @name WATCHDOG_TIME_PDI - Register Watchdog Time PDI */
/*! @{ */

#define ECAT_WATCHDOG_TIME_PDI_BF0_MASK          (0xFFFFU)
#define ECAT_WATCHDOG_TIME_PDI_BF0_SHIFT         (0U)
/*! BF0 - Watchdog Time PDI: number or basic watchdog increments (Default value with Watchdog divider 100us means 100ms Watchdog) */
#define ECAT_WATCHDOG_TIME_PDI_BF0(x)            (((uint16_t)(((uint16_t)(x)) << ECAT_WATCHDOG_TIME_PDI_BF0_SHIFT)) & ECAT_WATCHDOG_TIME_PDI_BF0_MASK)
/*! @} */

/*! @name WATCHDOG_TIME_PDI_PDI - Register Watchdog Time PDI */
/*! @{ */

#define ECAT_WATCHDOG_TIME_PDI_PDI_BF0_MASK      (0xFFFFU)
#define ECAT_WATCHDOG_TIME_PDI_PDI_BF0_SHIFT     (0U)
/*! BF0 - Watchdog Time PDI: number or basic watchdog increments (Default value with Watchdog divider 100us means 100ms Watchdog) */
#define ECAT_WATCHDOG_TIME_PDI_PDI_BF0(x)        (((uint16_t)(((uint16_t)(x)) << ECAT_WATCHDOG_TIME_PDI_PDI_BF0_SHIFT)) & ECAT_WATCHDOG_TIME_PDI_PDI_BF0_MASK)
/*! @} */

/*! @name WATCHDOG_TIME_PROCESS_DATA - Regsister Watchdog Time Process Data */
/*! @{ */

#define ECAT_WATCHDOG_TIME_PROCESS_DATA_BF0_MASK (0xFFFFU)
#define ECAT_WATCHDOG_TIME_PROCESS_DATA_BF0_SHIFT (0U)
/*! BF0 - Watchdog Time Process Data */
#define ECAT_WATCHDOG_TIME_PROCESS_DATA_BF0(x)   (((uint16_t)(((uint16_t)(x)) << ECAT_WATCHDOG_TIME_PROCESS_DATA_BF0_SHIFT)) & ECAT_WATCHDOG_TIME_PROCESS_DATA_BF0_MASK)
/*! @} */

/*! @name WATCHDOG_TIME_PROCESS_DATA_PDI - Regsister Watchdog Time Process Data */
/*! @{ */

#define ECAT_WATCHDOG_TIME_PROCESS_DATA_PDI_BF0_MASK (0xFFFFU)
#define ECAT_WATCHDOG_TIME_PROCESS_DATA_PDI_BF0_SHIFT (0U)
/*! BF0 - Watchdog Time Process Data */
#define ECAT_WATCHDOG_TIME_PROCESS_DATA_PDI_BF0(x) (((uint16_t)(((uint16_t)(x)) << ECAT_WATCHDOG_TIME_PROCESS_DATA_PDI_BF0_SHIFT)) & ECAT_WATCHDOG_TIME_PROCESS_DATA_PDI_BF0_MASK)
/*! @} */

/*! @name WATCHDOG_STATUS_PROCESS_DATA - Watchdog Status Process Data */
/*! @{ */

#define ECAT_WATCHDOG_STATUS_PROCESS_DATA_BF0_MASK (0x1U)
#define ECAT_WATCHDOG_STATUS_PROCESS_DATA_BF0_SHIFT (0U)
/*! BF0 - Watchdog Status of Process Data (triggered by SyncManagers)
 *  0b0..Watchdog Process Data expired
 *  0b1..Watchdog Process Data is active or disabled
 */
#define ECAT_WATCHDOG_STATUS_PROCESS_DATA_BF0(x) (((uint16_t)(((uint16_t)(x)) << ECAT_WATCHDOG_STATUS_PROCESS_DATA_BF0_SHIFT)) & ECAT_WATCHDOG_STATUS_PROCESS_DATA_BF0_MASK)

#define ECAT_WATCHDOG_STATUS_PROCESS_DATA_BF1_MASK (0xFFFEU)
#define ECAT_WATCHDOG_STATUS_PROCESS_DATA_BF1_SHIFT (1U)
/*! BF1 - Reserved */
#define ECAT_WATCHDOG_STATUS_PROCESS_DATA_BF1(x) (((uint16_t)(((uint16_t)(x)) << ECAT_WATCHDOG_STATUS_PROCESS_DATA_BF1_SHIFT)) & ECAT_WATCHDOG_STATUS_PROCESS_DATA_BF1_MASK)
/*! @} */

/*! @name WATCHDOG_COUNTER_PROCESS_DATA - Watchdog Counter Process Data */
/*! @{ */

#define ECAT_WATCHDOG_COUNTER_PROCESS_DATA_BF0_MASK (0xFFU)
#define ECAT_WATCHDOG_COUNTER_PROCESS_DATA_BF0_SHIFT (0U)
/*! BF0 - Watchdog Counter Process Data (counting is stopped when 0xFF is reached). Counts if Process Data Watchdog expires. */
#define ECAT_WATCHDOG_COUNTER_PROCESS_DATA_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_WATCHDOG_COUNTER_PROCESS_DATA_BF0_SHIFT)) & ECAT_WATCHDOG_COUNTER_PROCESS_DATA_BF0_MASK)
/*! @} */

/*! @name WATCHDOG_COUNTER_PROCESS_DATA_PDI - Watchdog Counter Process Data */
/*! @{ */

#define ECAT_WATCHDOG_COUNTER_PROCESS_DATA_PDI_BF0_MASK (0xFFU)
#define ECAT_WATCHDOG_COUNTER_PROCESS_DATA_PDI_BF0_SHIFT (0U)
/*! BF0 - Watchdog Counter Process Data (counting is stopped when 0xFF is reached). Counts if Process Data Watchdog expires. */
#define ECAT_WATCHDOG_COUNTER_PROCESS_DATA_PDI_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_WATCHDOG_COUNTER_PROCESS_DATA_PDI_BF0_SHIFT)) & ECAT_WATCHDOG_COUNTER_PROCESS_DATA_PDI_BF0_MASK)
/*! @} */

/*! @name WATCHDOG_COUNTER_PDI - Watchdog Counter PDI */
/*! @{ */

#define ECAT_WATCHDOG_COUNTER_PDI_BF0_MASK       (0xFFU)
#define ECAT_WATCHDOG_COUNTER_PDI_BF0_SHIFT      (0U)
/*! BF0 - Watchdog PDI counter (counting is stopped when 0xFF is reached). */
#define ECAT_WATCHDOG_COUNTER_PDI_BF0(x)         (((uint8_t)(((uint8_t)(x)) << ECAT_WATCHDOG_COUNTER_PDI_BF0_SHIFT)) & ECAT_WATCHDOG_COUNTER_PDI_BF0_MASK)
/*! @} */

/*! @name WATCHDOG_COUNTER_PDI_PDI - Watchdog Counter PDI */
/*! @{ */

#define ECAT_WATCHDOG_COUNTER_PDI_PDI_BF0_MASK   (0xFFU)
#define ECAT_WATCHDOG_COUNTER_PDI_PDI_BF0_SHIFT  (0U)
/*! BF0 - Watchdog PDI counter (counting is stopped when 0xFF is reached). */
#define ECAT_WATCHDOG_COUNTER_PDI_PDI_BF0(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_WATCHDOG_COUNTER_PDI_PDI_BF0_SHIFT)) & ECAT_WATCHDOG_COUNTER_PDI_PDI_BF0_MASK)
/*! @} */

/*! @name EEPROM_CONFIGURATION - EEPROM Configuration */
/*! @{ */

#define ECAT_EEPROM_CONFIGURATION_BF0_MASK       (0x1U)
#define ECAT_EEPROM_CONFIGURATION_BF0_SHIFT      (0U)
/*! BF0 - EEPROM control is offered to PDI
 *  0b0..no
 *  0b1..yes (PDI has EEPROM control)
 */
#define ECAT_EEPROM_CONFIGURATION_BF0(x)         (((uint8_t)(((uint8_t)(x)) << ECAT_EEPROM_CONFIGURATION_BF0_SHIFT)) & ECAT_EEPROM_CONFIGURATION_BF0_MASK)

#define ECAT_EEPROM_CONFIGURATION_BF1_MASK       (0x2U)
#define ECAT_EEPROM_CONFIGURATION_BF1_SHIFT      (1U)
/*! BF1 - Force ECAT access
 *  0b0..Do not change Bit 0x0501[0]
 *  0b1..Reset Bit 0x0501[0] to 0
 */
#define ECAT_EEPROM_CONFIGURATION_BF1(x)         (((uint8_t)(((uint8_t)(x)) << ECAT_EEPROM_CONFIGURATION_BF1_SHIFT)) & ECAT_EEPROM_CONFIGURATION_BF1_MASK)

#define ECAT_EEPROM_CONFIGURATION_BF2_MASK       (0xFCU)
#define ECAT_EEPROM_CONFIGURATION_BF2_SHIFT      (2U)
/*! BF2 - Reserved, write 0 */
#define ECAT_EEPROM_CONFIGURATION_BF2(x)         (((uint8_t)(((uint8_t)(x)) << ECAT_EEPROM_CONFIGURATION_BF2_SHIFT)) & ECAT_EEPROM_CONFIGURATION_BF2_MASK)
/*! @} */

/*! @name EEPROM_CONFIGURATION_PDI - EEPROM Configuration */
/*! @{ */

#define ECAT_EEPROM_CONFIGURATION_PDI_BF0_MASK   (0x1U)
#define ECAT_EEPROM_CONFIGURATION_PDI_BF0_SHIFT  (0U)
/*! BF0 - EEPROM control is offered to PDI
 *  0b0..no
 *  0b1..yes (PDI has EEPROM control)
 */
#define ECAT_EEPROM_CONFIGURATION_PDI_BF0(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_EEPROM_CONFIGURATION_PDI_BF0_SHIFT)) & ECAT_EEPROM_CONFIGURATION_PDI_BF0_MASK)

#define ECAT_EEPROM_CONFIGURATION_PDI_BF1_MASK   (0x2U)
#define ECAT_EEPROM_CONFIGURATION_PDI_BF1_SHIFT  (1U)
/*! BF1 - Force ECAT access
 *  0b0..Do not change Bit 0x0501[0]
 *  0b1..Reset Bit 0x0501[0] to 0
 */
#define ECAT_EEPROM_CONFIGURATION_PDI_BF1(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_EEPROM_CONFIGURATION_PDI_BF1_SHIFT)) & ECAT_EEPROM_CONFIGURATION_PDI_BF1_MASK)

#define ECAT_EEPROM_CONFIGURATION_PDI_BF2_MASK   (0xFCU)
#define ECAT_EEPROM_CONFIGURATION_PDI_BF2_SHIFT  (2U)
/*! BF2 - Reserved, write 0 */
#define ECAT_EEPROM_CONFIGURATION_PDI_BF2(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_EEPROM_CONFIGURATION_PDI_BF2_SHIFT)) & ECAT_EEPROM_CONFIGURATION_PDI_BF2_MASK)
/*! @} */

/*! @name REGISTER_EEPROM_PDI_ACCESS_STATE - EEPROM PDI Access State */
/*! @{ */

#define ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_BF0_MASK (0x1U)
#define ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_BF0_SHIFT (0U)
/*! BF0 - Access to EEPROM:
 *  0b0..PDI releases EEPROM access
 *  0b1..PDI takes EEPROM access (PDI has EEPROM control)
 */
#define ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_BF0_SHIFT)) & ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_BF0_MASK)

#define ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_BF1_MASK (0xFEU)
#define ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_BF1_SHIFT (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_BF1(x) (((uint8_t)(((uint8_t)(x)) << ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_BF1_SHIFT)) & ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_BF1_MASK)
/*! @} */

/*! @name REGISTER_EEPROM_PDI_ACCESS_STATE_PDI - EEPROM PDI Access State */
/*! @{ */

#define ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_PDI_BF0_MASK (0x1U)
#define ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_PDI_BF0_SHIFT (0U)
/*! BF0 - Access to EEPROM:
 *  0b0..PDI releases EEPROM access
 *  0b1..PDI takes EEPROM access (PDI has EEPROM control)
 */
#define ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_PDI_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_PDI_BF0_SHIFT)) & ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_PDI_BF0_MASK)

#define ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_PDI_BF1_MASK (0xFEU)
#define ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_PDI_BF1_SHIFT (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_PDI_BF1(x) (((uint8_t)(((uint8_t)(x)) << ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_PDI_BF1_SHIFT)) & ECAT_REGISTER_EEPROM_PDI_ACCESS_STATE_PDI_BF1_MASK)
/*! @} */

/*! @name EEPROM_CONTROL_STATUS - Register EEPROM Control/Status */
/*! @{ */

#define ECAT_EEPROM_CONTROL_STATUS_BF0_MASK      (0x1U)
#define ECAT_EEPROM_CONTROL_STATUS_BF0_SHIFT     (0U)
/*! BF0 - ECAT write enable2
 *  0b0..Write requests are disabled
 *  0b1..Write requests are enabled
 */
#define ECAT_EEPROM_CONTROL_STATUS_BF0(x)        (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_BF0_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_BF0_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_BF1_MASK      (0x1EU)
#define ECAT_EEPROM_CONTROL_STATUS_BF1_SHIFT     (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_EEPROM_CONTROL_STATUS_BF1(x)        (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_BF1_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_BF1_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_BF5_MASK      (0x20U)
#define ECAT_EEPROM_CONTROL_STATUS_BF5_SHIFT     (5U)
/*! BF5 - EEPROM emulation:
 *  0b0..Normal operation (I2C interface used)
 *  0b1..PDI emulates EEPROM (I2C not used)
 */
#define ECAT_EEPROM_CONTROL_STATUS_BF5(x)        (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_BF5_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_BF5_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_BF6_MASK      (0x40U)
#define ECAT_EEPROM_CONTROL_STATUS_BF6_SHIFT     (6U)
/*! BF6 - Supported number of EEPROM read bytes:
 *  0b0..4 Bytes
 *  0b1..8 Bytes
 */
#define ECAT_EEPROM_CONTROL_STATUS_BF6(x)        (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_BF6_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_BF6_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_BF7_MASK      (0x80U)
#define ECAT_EEPROM_CONTROL_STATUS_BF7_SHIFT     (7U)
/*! BF7 - Selected EEPROM Algorithm:
 *  0b0..1 address byte (1Kbit to 16Kbit EEPROMs)
 *  0b1..2 address bytes (32Kbit to 4 Mbit EEPROMs)
 */
#define ECAT_EEPROM_CONTROL_STATUS_BF7(x)        (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_BF7_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_BF7_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_BF8_MASK      (0x700U)
#define ECAT_EEPROM_CONTROL_STATUS_BF8_SHIFT     (8U)
/*! BF8 - Command register
 *  0b000..No command/EEPROM idle (clear error bits)
 *  0b001..Read
 *  0b010..Write
 *  0b100..Reload
 */
#define ECAT_EEPROM_CONTROL_STATUS_BF8(x)        (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_BF8_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_BF8_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_BF11_MASK     (0x800U)
#define ECAT_EEPROM_CONTROL_STATUS_BF11_SHIFT    (11U)
/*! BF11 - Checksum Error in ESC Configuration Area:
 *  0b0..Checksum ok
 *  0b1..Checksum error
 */
#define ECAT_EEPROM_CONTROL_STATUS_BF11(x)       (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_BF11_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_BF11_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_BF12_MASK     (0x1000U)
#define ECAT_EEPROM_CONTROL_STATUS_BF12_SHIFT    (12U)
/*! BF12 - EEPROM loading status:
 *  0b0..EEPROM loaded, device information ok
 *  0b1..EEPROM not loaded, device information not available (EEPROM loading in progress or finished with a failure)
 */
#define ECAT_EEPROM_CONTROL_STATUS_BF12(x)       (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_BF12_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_BF12_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_BF13_MASK     (0x2000U)
#define ECAT_EEPROM_CONTROL_STATUS_BF13_SHIFT    (13U)
/*! BF13 - Error Acknowledge/Command3:
 *  0b0..No error
 *  0b1..Missing EEPROM acknowledge or invalid command
 */
#define ECAT_EEPROM_CONTROL_STATUS_BF13(x)       (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_BF13_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_BF13_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_BF14_MASK     (0x4000U)
#define ECAT_EEPROM_CONTROL_STATUS_BF14_SHIFT    (14U)
/*! BF14 - Error Write Enable3:
 *  0b0..No error
 *  0b1..Write Command without Write enable
 */
#define ECAT_EEPROM_CONTROL_STATUS_BF14(x)       (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_BF14_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_BF14_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_BF15_MASK     (0x8000U)
#define ECAT_EEPROM_CONTROL_STATUS_BF15_SHIFT    (15U)
/*! BF15 - Busy:
 *  0b0..EEPROM Interface is idle
 *  0b1..EEPROM Interface is busy
 */
#define ECAT_EEPROM_CONTROL_STATUS_BF15(x)       (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_BF15_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_BF15_MASK)
/*! @} */

/*! @name EEPROM_CONTROL_STATUS_PDI - Register EEPROM Control/Status */
/*! @{ */

#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF0_MASK  (0x1U)
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF0_SHIFT (0U)
/*! BF0 - ECAT write enable2
 *  0b0..Write requests are disabled
 *  0b1..Write requests are enabled
 */
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF0(x)    (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_PDI_BF0_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_PDI_BF0_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF1_MASK  (0x1EU)
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF1_SHIFT (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF1(x)    (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_PDI_BF1_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_PDI_BF1_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF5_MASK  (0x20U)
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF5_SHIFT (5U)
/*! BF5 - EEPROM emulation:
 *  0b0..Normal operation (I2C interface used)
 *  0b1..PDI emulates EEPROM (I2C not used)
 */
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF5(x)    (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_PDI_BF5_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_PDI_BF5_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF6_MASK  (0x40U)
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF6_SHIFT (6U)
/*! BF6 - Supported number of EEPROM read bytes:
 *  0b0..4 Bytes
 *  0b1..8 Bytes
 */
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF6(x)    (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_PDI_BF6_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_PDI_BF6_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF7_MASK  (0x80U)
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF7_SHIFT (7U)
/*! BF7 - Selected EEPROM Algorithm:
 *  0b0..1 address byte (1Kbit to 16Kbit EEPROMs)
 *  0b1..2 address bytes (32Kbit to 4 Mbit EEPROMs)
 */
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF7(x)    (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_PDI_BF7_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_PDI_BF7_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF8_MASK  (0x700U)
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF8_SHIFT (8U)
/*! BF8 - Command register
 *  0b000..No command/EEPROM idle (clear error bits)
 *  0b001..Read
 *  0b010..Write
 *  0b100..Reload
 */
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF8(x)    (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_PDI_BF8_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_PDI_BF8_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF11_MASK (0x800U)
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF11_SHIFT (11U)
/*! BF11 - Checksum Error in ESC Configuration Area:
 *  0b0..Checksum ok
 *  0b1..Checksum error
 */
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF11(x)   (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_PDI_BF11_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_PDI_BF11_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF12_MASK (0x1000U)
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF12_SHIFT (12U)
/*! BF12 - EEPROM loading status:
 *  0b0..EEPROM loaded, device information ok
 *  0b1..EEPROM not loaded, device information not available (EEPROM loading in progress or finished with a failure)
 */
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF12(x)   (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_PDI_BF12_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_PDI_BF12_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF13_MASK (0x2000U)
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF13_SHIFT (13U)
/*! BF13 - Error Acknowledge/Command3:
 *  0b0..No error
 *  0b1..Missing EEPROM acknowledge or invalid command
 */
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF13(x)   (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_PDI_BF13_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_PDI_BF13_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF14_MASK (0x4000U)
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF14_SHIFT (14U)
/*! BF14 - Error Write Enable3:
 *  0b0..No error
 *  0b1..Write Command without Write enable
 */
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF14(x)   (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_PDI_BF14_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_PDI_BF14_MASK)

#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF15_MASK (0x8000U)
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF15_SHIFT (15U)
/*! BF15 - Busy:
 *  0b0..EEPROM Interface is idle
 *  0b1..EEPROM Interface is busy
 */
#define ECAT_EEPROM_CONTROL_STATUS_PDI_BF15(x)   (((uint16_t)(((uint16_t)(x)) << ECAT_EEPROM_CONTROL_STATUS_PDI_BF15_SHIFT)) & ECAT_EEPROM_CONTROL_STATUS_PDI_BF15_MASK)
/*! @} */

/*! @name EEPROM_ADDRESS - EEPROM Address */
/*! @{ */

#define ECAT_EEPROM_ADDRESS_BF0_MASK             (0xFFFFFFFFU)
#define ECAT_EEPROM_ADDRESS_BF0_SHIFT            (0U)
/*! BF0 - EEPROM Address */
#define ECAT_EEPROM_ADDRESS_BF0(x)               (((uint32_t)(((uint32_t)(x)) << ECAT_EEPROM_ADDRESS_BF0_SHIFT)) & ECAT_EEPROM_ADDRESS_BF0_MASK)
/*! @} */

/*! @name EEPROM_DATA - EEPROM Data */
/*! @{ */

#define ECAT_EEPROM_DATA_BF0_MASK                (0xFFFFU)
#define ECAT_EEPROM_DATA_BF0_SHIFT               (0U)
/*! BF0 - EEPROM Write data (data to be written to EEPROM) or EEPROM Read data (data read from EEPROM,. lower bytes) */
#define ECAT_EEPROM_DATA_BF0(x)                  (((uint64_t)(((uint64_t)(x)) << ECAT_EEPROM_DATA_BF0_SHIFT)) & ECAT_EEPROM_DATA_BF0_MASK)

#define ECAT_EEPROM_DATA_BF16_MASK               (0xFFFFFFFFFFFF0000U)
#define ECAT_EEPROM_DATA_BF16_SHIFT              (16U)
/*! BF16 - EEPROM Read data (data read from EEPROM, higher bytes) */
#define ECAT_EEPROM_DATA_BF16(x)                 (((uint64_t)(((uint64_t)(x)) << ECAT_EEPROM_DATA_BF16_SHIFT)) & ECAT_EEPROM_DATA_BF16_MASK)
/*! @} */

/*! @name MII_MANAGEMENT_CONTROL_OR_STATUS - MII Management Control/Status */
/*! @{ */

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF0_MASK (0x1U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF0_SHIFT (0U)
/*! BF0 - Write enable*:
 *  0b0..Write disabled
 *  0b1..Write enabled
 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF0(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF0_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF0_MASK)

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF1_MASK (0x2U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF1_SHIFT (1U)
/*! BF1 - Management Interface can be controlled by PDI (registers 0x0516-0x0517):
 *  0b0..Only ECAT control
 *  0b1..PDI control possible
 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF1(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF1_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF1_MASK)

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF2_MASK (0x4U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF2_SHIFT (2U)
/*! BF2 - MI link detection and configuration:
 *  0b0..Disabled for all ports
 *  0b1..Enabled for at least one MII port, refer to PHY Port Status (0x0518 ff.) for details
 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF2(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF2_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF2_MASK)

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF3_MASK (0xF8U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF3_SHIFT (3U)
/*! BF3 - PHY address of port 0 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF3(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF3_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF3_MASK)

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF8_MASK (0x300U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF8_SHIFT (8U)
/*! BF8 - Command register*:
 *  0b00..No command/MI idle (clear error bits)
 *  0b01..Read
 *  0b10..Write
 *  0b11..Reserved/invalid command (do not issue)
 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF8(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF8_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF8_MASK)

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF10_MASK (0x1C00U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF10_SHIFT (10U)
/*! BF10 - Reserved, write 0 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF10(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF10_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF10_MASK)

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF13_MASK (0x2000U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF13_SHIFT (13U)
/*! BF13 - Read error:
 *  0b0..No read error
 *  0b1..Read error occurred (PHY or register not available)
 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF13(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF13_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF13_MASK)

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF14_MASK (0x4000U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF14_SHIFT (14U)
/*! BF14 - Command error:
 *  0b0..Last Command was successful
 *  0b1..Invalid command or write command without Write Enable
 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF14(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF14_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF14_MASK)

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF15_MASK (0x8000U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF15_SHIFT (15U)
/*! BF15 - Busy:
 *  0b0..MII Management Interface is idle
 *  0b1..MII Management Interface is busy
 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF15(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF15_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_BF15_MASK)
/*! @} */

/*! @name MII_MANAGEMENT_CONTROL_OR_STATUS_PDI - MII Management Control/Status */
/*! @{ */

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF0_MASK (0x1U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF0_SHIFT (0U)
/*! BF0 - Write enable*:
 *  0b0..Write disabled
 *  0b1..Write enabled
 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF0(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF0_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF0_MASK)

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF1_MASK (0x2U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF1_SHIFT (1U)
/*! BF1 - Management Interface can be controlled by PDI (registers 0x0516-0x0517):
 *  0b0..Only ECAT control
 *  0b1..PDI control possible
 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF1(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF1_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF1_MASK)

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF2_MASK (0x4U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF2_SHIFT (2U)
/*! BF2 - MI link detection and configuration:
 *  0b0..Disabled for all ports
 *  0b1..Enabled for at least one MII port, refer to PHY Port Status (0x0518 ff.) for details
 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF2(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF2_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF2_MASK)

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF3_MASK (0xF8U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF3_SHIFT (3U)
/*! BF3 - PHY address of port 0 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF3(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF3_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF3_MASK)

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF8_MASK (0x300U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF8_SHIFT (8U)
/*! BF8 - Command register*:
 *  0b00..No command/MI idle (clear error bits)
 *  0b01..Read
 *  0b10..Write
 *  0b11..Reserved/invalid command (do not issue)
 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF8(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF8_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF8_MASK)

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF10_MASK (0x1C00U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF10_SHIFT (10U)
/*! BF10 - Reserved, write 0 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF10(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF10_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF10_MASK)

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF13_MASK (0x2000U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF13_SHIFT (13U)
/*! BF13 - Read error:
 *  0b0..No read error
 *  0b1..Read error occurred (PHY or register not available)
 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF13(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF13_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF13_MASK)

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF14_MASK (0x4000U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF14_SHIFT (14U)
/*! BF14 - Command error:
 *  0b0..Last Command was successful
 *  0b1..Invalid command or write command without Write Enable
 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF14(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF14_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF14_MASK)

#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF15_MASK (0x8000U)
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF15_SHIFT (15U)
/*! BF15 - Busy:
 *  0b0..MII Management Interface is idle
 *  0b1..MII Management Interface is busy
 */
#define ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF15(x) (((uint16_t)(((uint16_t)(x)) << ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF15_SHIFT)) & ECAT_MII_MANAGEMENT_CONTROL_OR_STATUS_PDI_BF15_MASK)
/*! @} */

/*! @name PHY_ADDRESS - PHY Address */
/*! @{ */

#define ECAT_PHY_ADDRESS_BF0_MASK                (0x1FU)
#define ECAT_PHY_ADDRESS_BF0_SHIFT               (0U)
/*! BF0 - PHY Address */
#define ECAT_PHY_ADDRESS_BF0(x)                  (((uint8_t)(((uint8_t)(x)) << ECAT_PHY_ADDRESS_BF0_SHIFT)) & ECAT_PHY_ADDRESS_BF0_MASK)

#define ECAT_PHY_ADDRESS_BF5_MASK                (0x60U)
#define ECAT_PHY_ADDRESS_BF5_SHIFT               (5U)
/*! BF5 - Reserved, write 0 */
#define ECAT_PHY_ADDRESS_BF5(x)                  (((uint8_t)(((uint8_t)(x)) << ECAT_PHY_ADDRESS_BF5_SHIFT)) & ECAT_PHY_ADDRESS_BF5_MASK)

#define ECAT_PHY_ADDRESS_BF7_MASK                (0x80U)
#define ECAT_PHY_ADDRESS_BF7_SHIFT               (7U)
/*! BF7 - Show configured PHY address of port 0-3 in register 0x0510[7:3]. This is used if the PHY addresses are not consecutive.
 *  0b0..Register 0x0510[7:3] shows PHY address of port 0 (this is also the PHY address offset, if the PHY addresses are consecutive)
 *  0b1..Register 0x0510[7:3] shows PHY address of port 0x0512[4:0] (valid values 0-3)
 */
#define ECAT_PHY_ADDRESS_BF7(x)                  (((uint8_t)(((uint8_t)(x)) << ECAT_PHY_ADDRESS_BF7_SHIFT)) & ECAT_PHY_ADDRESS_BF7_MASK)
/*! @} */

/*! @name PHY_REGISTER_ADDRESS - PHY Register Address */
/*! @{ */

#define ECAT_PHY_REGISTER_ADDRESS_BF0_MASK       (0x1FU)
#define ECAT_PHY_REGISTER_ADDRESS_BF0_SHIFT      (0U)
/*! BF0 - Address of PHY Register that shall be read/written */
#define ECAT_PHY_REGISTER_ADDRESS_BF0(x)         (((uint8_t)(((uint8_t)(x)) << ECAT_PHY_REGISTER_ADDRESS_BF0_SHIFT)) & ECAT_PHY_REGISTER_ADDRESS_BF0_MASK)

#define ECAT_PHY_REGISTER_ADDRESS_BF5_MASK       (0xE0U)
#define ECAT_PHY_REGISTER_ADDRESS_BF5_SHIFT      (5U)
/*! BF5 - Reserved, write 0 */
#define ECAT_PHY_REGISTER_ADDRESS_BF5(x)         (((uint8_t)(((uint8_t)(x)) << ECAT_PHY_REGISTER_ADDRESS_BF5_SHIFT)) & ECAT_PHY_REGISTER_ADDRESS_BF5_MASK)
/*! @} */

/*! @name PHY_DATA - PHY Data */
/*! @{ */

#define ECAT_PHY_DATA_BF0_MASK                   (0xFFFFU)
#define ECAT_PHY_DATA_BF0_SHIFT                  (0U)
/*! BF0 - PHY Read/Write Data */
#define ECAT_PHY_DATA_BF0(x)                     (((uint16_t)(((uint16_t)(x)) << ECAT_PHY_DATA_BF0_SHIFT)) & ECAT_PHY_DATA_BF0_MASK)
/*! @} */

/*! @name MII_MANAGEMENT_ECAT_ACCESS_STATE - MII Management ECAT Access State */
/*! @{ */

#define ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_BF0_MASK (0x1U)
#define ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_BF0_SHIFT (0U)
/*! BF0 - Access to MII management:
 *  0b0..ECAT enables PDI takeover of MII management interface
 *  0b1..ECAT claims exclusive access to MII management interface
 */
#define ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_BF0_SHIFT)) & ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_BF0_MASK)

#define ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_BF1_MASK (0xFEU)
#define ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_BF1_SHIFT (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_BF1(x) (((uint8_t)(((uint8_t)(x)) << ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_BF1_SHIFT)) & ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_BF1_MASK)
/*! @} */

/*! @name MII_MANAGEMENT_ECAT_ACCESS_STATE_PDI - MII Management ECAT Access State */
/*! @{ */

#define ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_PDI_BF0_MASK (0x1U)
#define ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_PDI_BF0_SHIFT (0U)
/*! BF0 - Access to MII management:
 *  0b0..ECAT enables PDI takeover of MII management interface
 *  0b1..ECAT claims exclusive access to MII management interface
 */
#define ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_PDI_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_PDI_BF0_SHIFT)) & ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_PDI_BF0_MASK)

#define ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_PDI_BF1_MASK (0xFEU)
#define ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_PDI_BF1_SHIFT (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_PDI_BF1(x) (((uint8_t)(((uint8_t)(x)) << ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_PDI_BF1_SHIFT)) & ECAT_MII_MANAGEMENT_ECAT_ACCESS_STATE_PDI_BF1_MASK)
/*! @} */

/*! @name MII_MANAGEMENT_PDI_ACCESS_STATE - MII Management PDI Access State */
/*! @{ */

#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_BF0_MASK (0x1U)
#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_BF0_SHIFT (0U)
/*! BF0 - Access to MII management:
 *  0b0..ECAT has access to MII management
 *  0b1..PDI has access to MII management
 */
#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_BF0_SHIFT)) & ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_BF0_MASK)

#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_BF1_MASK (0x2U)
#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_BF1_SHIFT (1U)
/*! BF1 - Force PDI Access State:
 *  0b0..Do not change Bit 0x0517[0]
 *  0b1..Reset Bit 0x0517[0] to 0
 */
#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_BF1(x) (((uint8_t)(((uint8_t)(x)) << ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_BF1_SHIFT)) & ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_BF1_MASK)

#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_BF2_MASK (0xFCU)
#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_BF2_SHIFT (2U)
/*! BF2 - Reserved, write 0 */
#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_BF2(x) (((uint8_t)(((uint8_t)(x)) << ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_BF2_SHIFT)) & ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_BF2_MASK)
/*! @} */

/*! @name MII_MANAGEMENT_PDI_ACCESS_STATE_PDI - MII Management PDI Access State */
/*! @{ */

#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_PDI_BF0_MASK (0x1U)
#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_PDI_BF0_SHIFT (0U)
/*! BF0 - Access to MII management:
 *  0b0..ECAT has access to MII management
 *  0b1..PDI has access to MII management
 */
#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_PDI_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_PDI_BF0_SHIFT)) & ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_PDI_BF0_MASK)

#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_PDI_BF1_MASK (0x2U)
#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_PDI_BF1_SHIFT (1U)
/*! BF1 - Force PDI Access State:
 *  0b0..Do not change Bit 0x0517[0]
 *  0b1..Reset Bit 0x0517[0] to 0
 */
#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_PDI_BF1(x) (((uint8_t)(((uint8_t)(x)) << ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_PDI_BF1_SHIFT)) & ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_PDI_BF1_MASK)

#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_PDI_BF2_MASK (0xFCU)
#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_PDI_BF2_SHIFT (2U)
/*! BF2 - Reserved, write 0 */
#define ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_PDI_BF2(x) (((uint8_t)(((uint8_t)(x)) << ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_PDI_BF2_SHIFT)) & ECAT_MII_MANAGEMENT_PDI_ACCESS_STATE_PDI_BF2_MASK)
/*! @} */

/*! @name PHY_PORT_STATUS - PHY Port */
/*! @{ */

#define ECAT_PHY_PORT_STATUS_BF0_MASK            (0x1U)
#define ECAT_PHY_PORT_STATUS_BF0_SHIFT           (0U)
/*! BF0 - Physical link status (PHY status register 1.2):
 *  0b0..No physical link
 *  0b1..Physical link detected
 */
#define ECAT_PHY_PORT_STATUS_BF0(x)              (((uint8_t)(((uint8_t)(x)) << ECAT_PHY_PORT_STATUS_BF0_SHIFT)) & ECAT_PHY_PORT_STATUS_BF0_MASK)

#define ECAT_PHY_PORT_STATUS_BF1_MASK            (0x2U)
#define ECAT_PHY_PORT_STATUS_BF1_SHIFT           (1U)
/*! BF1 - Link status (100 Mbit/s, Full Duplex, Auto negotiation):
 *  0b0..No link
 *  0b1..Link detected
 */
#define ECAT_PHY_PORT_STATUS_BF1(x)              (((uint8_t)(((uint8_t)(x)) << ECAT_PHY_PORT_STATUS_BF1_SHIFT)) & ECAT_PHY_PORT_STATUS_BF1_MASK)

#define ECAT_PHY_PORT_STATUS_BF2_MASK            (0x4U)
#define ECAT_PHY_PORT_STATUS_BF2_SHIFT           (2U)
/*! BF2 - Link status error:
 *  0b0..No error
 *  0b1..Link error, link inhibited
 */
#define ECAT_PHY_PORT_STATUS_BF2(x)              (((uint8_t)(((uint8_t)(x)) << ECAT_PHY_PORT_STATUS_BF2_SHIFT)) & ECAT_PHY_PORT_STATUS_BF2_MASK)

#define ECAT_PHY_PORT_STATUS_BF3_MASK            (0x8U)
#define ECAT_PHY_PORT_STATUS_BF3_SHIFT           (3U)
/*! BF3 - Read error:
 *  0b0..No read error occurred
 *  0b1..A read error has occurred
 */
#define ECAT_PHY_PORT_STATUS_BF3(x)              (((uint8_t)(((uint8_t)(x)) << ECAT_PHY_PORT_STATUS_BF3_SHIFT)) & ECAT_PHY_PORT_STATUS_BF3_MASK)

#define ECAT_PHY_PORT_STATUS_BF4_MASK            (0x10U)
#define ECAT_PHY_PORT_STATUS_BF4_SHIFT           (4U)
/*! BF4 - Link partner error:
 *  0b0..No error detected
 *  0b1..Link partner error
 */
#define ECAT_PHY_PORT_STATUS_BF4(x)              (((uint8_t)(((uint8_t)(x)) << ECAT_PHY_PORT_STATUS_BF4_SHIFT)) & ECAT_PHY_PORT_STATUS_BF4_MASK)

#define ECAT_PHY_PORT_STATUS_BF5_MASK            (0x20U)
#define ECAT_PHY_PORT_STATUS_BF5_SHIFT           (5U)
/*! BF5 - PHY configuration updated
 *  0b0..No update
 *  0b1..PHY configuration was updated
 */
#define ECAT_PHY_PORT_STATUS_BF5(x)              (((uint8_t)(((uint8_t)(x)) << ECAT_PHY_PORT_STATUS_BF5_SHIFT)) & ECAT_PHY_PORT_STATUS_BF5_MASK)

#define ECAT_PHY_PORT_STATUS_BF6_MASK            (0xC0U)
#define ECAT_PHY_PORT_STATUS_BF6_SHIFT           (6U)
/*! BF6 - Reserved */
#define ECAT_PHY_PORT_STATUS_BF6(x)              (((uint8_t)(((uint8_t)(x)) << ECAT_PHY_PORT_STATUS_BF6_SHIFT)) & ECAT_PHY_PORT_STATUS_BF6_MASK)
/*! @} */

/*! @name FMMU_LOGICAL_START_ADDRESS - Register Logical Start address FMMU */
/*! @{ */

#define ECAT_FMMU_LOGICAL_START_ADDRESS_BF0_MASK (0xFFFFFFFFU)
#define ECAT_FMMU_LOGICAL_START_ADDRESS_BF0_SHIFT (0U)
/*! BF0 - Logical start address within the EtherCAT Address Space. */
#define ECAT_FMMU_LOGICAL_START_ADDRESS_BF0(x)   (((uint32_t)(((uint32_t)(x)) << ECAT_FMMU_LOGICAL_START_ADDRESS_BF0_SHIFT)) & ECAT_FMMU_LOGICAL_START_ADDRESS_BF0_MASK)
/*! @} */

/* The count of ECAT_FMMU_LOGICAL_START_ADDRESS */
#define ECAT_FMMU_LOGICAL_START_ADDRESS_COUNT    (8U)

/*! @name FMMU_LOGICAL_START_ADDRESS_PDI - Register Logical Start address FMMU */
/*! @{ */

#define ECAT_FMMU_LOGICAL_START_ADDRESS_PDI_BF0_MASK (0xFFFFFFFFU)
#define ECAT_FMMU_LOGICAL_START_ADDRESS_PDI_BF0_SHIFT (0U)
/*! BF0 - Logical start address within the EtherCAT Address Space. */
#define ECAT_FMMU_LOGICAL_START_ADDRESS_PDI_BF0(x) (((uint32_t)(((uint32_t)(x)) << ECAT_FMMU_LOGICAL_START_ADDRESS_PDI_BF0_SHIFT)) & ECAT_FMMU_LOGICAL_START_ADDRESS_PDI_BF0_MASK)
/*! @} */

/* The count of ECAT_FMMU_LOGICAL_START_ADDRESS_PDI */
#define ECAT_FMMU_LOGICAL_START_ADDRESS_PDI_COUNT (8U)

/*! @name FMMU_LENGTH - Register Length FMMU */
/*! @{ */

#define ECAT_FMMU_LENGTH_BF0_MASK                (0xFFFFU)
#define ECAT_FMMU_LENGTH_BF0_SHIFT               (0U)
/*! BF0 - Offset from the first logical FMMU byte to the last FMMU byte + 1 */
#define ECAT_FMMU_LENGTH_BF0(x)                  (((uint16_t)(((uint16_t)(x)) << ECAT_FMMU_LENGTH_BF0_SHIFT)) & ECAT_FMMU_LENGTH_BF0_MASK)
/*! @} */

/* The count of ECAT_FMMU_LENGTH */
#define ECAT_FMMU_LENGTH_COUNT                   (8U)

/*! @name FMMU_LENGTH_PDI - Register Length FMMU */
/*! @{ */

#define ECAT_FMMU_LENGTH_PDI_BF0_MASK            (0xFFFFU)
#define ECAT_FMMU_LENGTH_PDI_BF0_SHIFT           (0U)
/*! BF0 - Offset from the first logical FMMU byte to the last FMMU byte + 1 */
#define ECAT_FMMU_LENGTH_PDI_BF0(x)              (((uint16_t)(((uint16_t)(x)) << ECAT_FMMU_LENGTH_PDI_BF0_SHIFT)) & ECAT_FMMU_LENGTH_PDI_BF0_MASK)
/*! @} */

/* The count of ECAT_FMMU_LENGTH_PDI */
#define ECAT_FMMU_LENGTH_PDI_COUNT               (8U)

/*! @name FMMU_LOGICAL_START_BIT - Register Start bit FMMU y in logical address space */
/*! @{ */

#define ECAT_FMMU_LOGICAL_START_BIT_BF0_MASK     (0x7U)
#define ECAT_FMMU_LOGICAL_START_BIT_BF0_SHIFT    (0U)
/*! BF0 - Logical starting bit that shall be mapped (bits are counted from least significant bit 0 to most significant bit 7) */
#define ECAT_FMMU_LOGICAL_START_BIT_BF0(x)       (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_LOGICAL_START_BIT_BF0_SHIFT)) & ECAT_FMMU_LOGICAL_START_BIT_BF0_MASK)

#define ECAT_FMMU_LOGICAL_START_BIT_BF3_MASK     (0xF8U)
#define ECAT_FMMU_LOGICAL_START_BIT_BF3_SHIFT    (3U)
/*! BF3 - Reserved, write 0 */
#define ECAT_FMMU_LOGICAL_START_BIT_BF3(x)       (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_LOGICAL_START_BIT_BF3_SHIFT)) & ECAT_FMMU_LOGICAL_START_BIT_BF3_MASK)
/*! @} */

/* The count of ECAT_FMMU_LOGICAL_START_BIT */
#define ECAT_FMMU_LOGICAL_START_BIT_COUNT        (8U)

/*! @name FMMU_LOGICAL_START_BIT_PDI - Register Start bit FMMU y in logical address space */
/*! @{ */

#define ECAT_FMMU_LOGICAL_START_BIT_PDI_BF0_MASK (0x7U)
#define ECAT_FMMU_LOGICAL_START_BIT_PDI_BF0_SHIFT (0U)
/*! BF0 - Logical starting bit that shall be mapped (bits are counted from least significant bit 0 to most significant bit 7) */
#define ECAT_FMMU_LOGICAL_START_BIT_PDI_BF0(x)   (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_LOGICAL_START_BIT_PDI_BF0_SHIFT)) & ECAT_FMMU_LOGICAL_START_BIT_PDI_BF0_MASK)

#define ECAT_FMMU_LOGICAL_START_BIT_PDI_BF3_MASK (0xF8U)
#define ECAT_FMMU_LOGICAL_START_BIT_PDI_BF3_SHIFT (3U)
/*! BF3 - Reserved, write 0 */
#define ECAT_FMMU_LOGICAL_START_BIT_PDI_BF3(x)   (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_LOGICAL_START_BIT_PDI_BF3_SHIFT)) & ECAT_FMMU_LOGICAL_START_BIT_PDI_BF3_MASK)
/*! @} */

/* The count of ECAT_FMMU_LOGICAL_START_BIT_PDI */
#define ECAT_FMMU_LOGICAL_START_BIT_PDI_COUNT    (8U)

/*! @name FMMU_LOGICAL_STOP_BIT - Register Stop bit FMMU y in logical address space */
/*! @{ */

#define ECAT_FMMU_LOGICAL_STOP_BIT_BF0_MASK      (0x7U)
#define ECAT_FMMU_LOGICAL_STOP_BIT_BF0_SHIFT     (0U)
/*! BF0 - Last logical bit that shall be mapped (bits are counted from least significant bit 0 to most significant bit 7) */
#define ECAT_FMMU_LOGICAL_STOP_BIT_BF0(x)        (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_LOGICAL_STOP_BIT_BF0_SHIFT)) & ECAT_FMMU_LOGICAL_STOP_BIT_BF0_MASK)

#define ECAT_FMMU_LOGICAL_STOP_BIT_BF3_MASK      (0xF8U)
#define ECAT_FMMU_LOGICAL_STOP_BIT_BF3_SHIFT     (3U)
/*! BF3 - Reserved, write 0 */
#define ECAT_FMMU_LOGICAL_STOP_BIT_BF3(x)        (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_LOGICAL_STOP_BIT_BF3_SHIFT)) & ECAT_FMMU_LOGICAL_STOP_BIT_BF3_MASK)
/*! @} */

/* The count of ECAT_FMMU_LOGICAL_STOP_BIT */
#define ECAT_FMMU_LOGICAL_STOP_BIT_COUNT         (8U)

/*! @name FMMU_LOGICAL_STOP_BIT_PDI - Register Stop bit FMMU y in logical address space */
/*! @{ */

#define ECAT_FMMU_LOGICAL_STOP_BIT_PDI_BF0_MASK  (0x7U)
#define ECAT_FMMU_LOGICAL_STOP_BIT_PDI_BF0_SHIFT (0U)
/*! BF0 - Last logical bit that shall be mapped (bits are counted from least significant bit 0 to most significant bit 7) */
#define ECAT_FMMU_LOGICAL_STOP_BIT_PDI_BF0(x)    (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_LOGICAL_STOP_BIT_PDI_BF0_SHIFT)) & ECAT_FMMU_LOGICAL_STOP_BIT_PDI_BF0_MASK)

#define ECAT_FMMU_LOGICAL_STOP_BIT_PDI_BF3_MASK  (0xF8U)
#define ECAT_FMMU_LOGICAL_STOP_BIT_PDI_BF3_SHIFT (3U)
/*! BF3 - Reserved, write 0 */
#define ECAT_FMMU_LOGICAL_STOP_BIT_PDI_BF3(x)    (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_LOGICAL_STOP_BIT_PDI_BF3_SHIFT)) & ECAT_FMMU_LOGICAL_STOP_BIT_PDI_BF3_MASK)
/*! @} */

/* The count of ECAT_FMMU_LOGICAL_STOP_BIT_PDI */
#define ECAT_FMMU_LOGICAL_STOP_BIT_PDI_COUNT     (8U)

/*! @name FMMU_PHYSICAL_START_ADDRESS - Register Physical Start address FMMU */
/*! @{ */

#define ECAT_FMMU_PHYSICAL_START_ADDRESS_BF0_MASK (0xFFFFU)
#define ECAT_FMMU_PHYSICAL_START_ADDRESS_BF0_SHIFT (0U)
/*! BF0 - Physical Start Address (mapped to logical Start address) */
#define ECAT_FMMU_PHYSICAL_START_ADDRESS_BF0(x)  (((uint16_t)(((uint16_t)(x)) << ECAT_FMMU_PHYSICAL_START_ADDRESS_BF0_SHIFT)) & ECAT_FMMU_PHYSICAL_START_ADDRESS_BF0_MASK)
/*! @} */

/* The count of ECAT_FMMU_PHYSICAL_START_ADDRESS */
#define ECAT_FMMU_PHYSICAL_START_ADDRESS_COUNT   (8U)

/*! @name FMMU_PHYSICAL_START_ADDRESS_PDI - Register Physical Start address FMMU */
/*! @{ */

#define ECAT_FMMU_PHYSICAL_START_ADDRESS_PDI_BF0_MASK (0xFFFFU)
#define ECAT_FMMU_PHYSICAL_START_ADDRESS_PDI_BF0_SHIFT (0U)
/*! BF0 - Physical Start Address (mapped to logical Start address) */
#define ECAT_FMMU_PHYSICAL_START_ADDRESS_PDI_BF0(x) (((uint16_t)(((uint16_t)(x)) << ECAT_FMMU_PHYSICAL_START_ADDRESS_PDI_BF0_SHIFT)) & ECAT_FMMU_PHYSICAL_START_ADDRESS_PDI_BF0_MASK)
/*! @} */

/* The count of ECAT_FMMU_PHYSICAL_START_ADDRESS_PDI */
#define ECAT_FMMU_PHYSICAL_START_ADDRESS_PDI_COUNT (8U)

/*! @name FMMU_PHYSICAL_START_BIT - Register Physical Start bit FMMU */
/*! @{ */

#define ECAT_FMMU_PHYSICAL_START_BIT_BF0_MASK    (0x7U)
#define ECAT_FMMU_PHYSICAL_START_BIT_BF0_SHIFT   (0U)
/*! BF0 - Physical starting bit as target of logical start bit mapping (bits are counted from least
 *    significant bit 0 to most significant bit 7)
 */
#define ECAT_FMMU_PHYSICAL_START_BIT_BF0(x)      (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_PHYSICAL_START_BIT_BF0_SHIFT)) & ECAT_FMMU_PHYSICAL_START_BIT_BF0_MASK)

#define ECAT_FMMU_PHYSICAL_START_BIT_BF3_MASK    (0xF8U)
#define ECAT_FMMU_PHYSICAL_START_BIT_BF3_SHIFT   (3U)
/*! BF3 - Reserved, write 0 */
#define ECAT_FMMU_PHYSICAL_START_BIT_BF3(x)      (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_PHYSICAL_START_BIT_BF3_SHIFT)) & ECAT_FMMU_PHYSICAL_START_BIT_BF3_MASK)
/*! @} */

/* The count of ECAT_FMMU_PHYSICAL_START_BIT */
#define ECAT_FMMU_PHYSICAL_START_BIT_COUNT       (8U)

/*! @name FMMU_PHYSICAL_START_BIT_PDI - Register Physical Start bit FMMU */
/*! @{ */

#define ECAT_FMMU_PHYSICAL_START_BIT_PDI_BF0_MASK (0x7U)
#define ECAT_FMMU_PHYSICAL_START_BIT_PDI_BF0_SHIFT (0U)
/*! BF0 - Physical starting bit as target of logical start bit mapping (bits are counted from least
 *    significant bit 0 to most significant bit 7)
 */
#define ECAT_FMMU_PHYSICAL_START_BIT_PDI_BF0(x)  (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_PHYSICAL_START_BIT_PDI_BF0_SHIFT)) & ECAT_FMMU_PHYSICAL_START_BIT_PDI_BF0_MASK)

#define ECAT_FMMU_PHYSICAL_START_BIT_PDI_BF3_MASK (0xF8U)
#define ECAT_FMMU_PHYSICAL_START_BIT_PDI_BF3_SHIFT (3U)
/*! BF3 - Reserved, write 0 */
#define ECAT_FMMU_PHYSICAL_START_BIT_PDI_BF3(x)  (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_PHYSICAL_START_BIT_PDI_BF3_SHIFT)) & ECAT_FMMU_PHYSICAL_START_BIT_PDI_BF3_MASK)
/*! @} */

/* The count of ECAT_FMMU_PHYSICAL_START_BIT_PDI */
#define ECAT_FMMU_PHYSICAL_START_BIT_PDI_COUNT   (8U)

/*! @name FMMU_TYPE - Register Type FMMU y */
/*! @{ */

#define ECAT_FMMU_TYPE_BF0_MASK                  (0x1U)
#define ECAT_FMMU_TYPE_BF0_SHIFT                 (0U)
/*! BF0 - Bit field access for ECAT: r/w
 *  0b0..Ignore mapping for read accesses
 *  0b1..Use mapping for read accesses
 */
#define ECAT_FMMU_TYPE_BF0(x)                    (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_TYPE_BF0_SHIFT)) & ECAT_FMMU_TYPE_BF0_MASK)

#define ECAT_FMMU_TYPE_BF1_MASK                  (0x2U)
#define ECAT_FMMU_TYPE_BF1_SHIFT                 (1U)
/*! BF1 - Bit field access for ECAT: r/w
 *  0b0..Ignore mapping for write accesses
 *  0b1..Use mapping for write accesses
 */
#define ECAT_FMMU_TYPE_BF1(x)                    (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_TYPE_BF1_SHIFT)) & ECAT_FMMU_TYPE_BF1_MASK)

#define ECAT_FMMU_TYPE_BF2_MASK                  (0xFCU)
#define ECAT_FMMU_TYPE_BF2_SHIFT                 (2U)
/*! BF2 - Reserved, write 0 */
#define ECAT_FMMU_TYPE_BF2(x)                    (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_TYPE_BF2_SHIFT)) & ECAT_FMMU_TYPE_BF2_MASK)
/*! @} */

/* The count of ECAT_FMMU_TYPE */
#define ECAT_FMMU_TYPE_COUNT                     (8U)

/*! @name FMMU_TYPE_PDI - Register Type FMMU y */
/*! @{ */

#define ECAT_FMMU_TYPE_PDI_BF0_MASK              (0x1U)
#define ECAT_FMMU_TYPE_PDI_BF0_SHIFT             (0U)
/*! BF0
 *  0b0..Ignore mapping for read accesses
 *  0b1..Use mapping for read accesses
 */
#define ECAT_FMMU_TYPE_PDI_BF0(x)                (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_TYPE_PDI_BF0_SHIFT)) & ECAT_FMMU_TYPE_PDI_BF0_MASK)

#define ECAT_FMMU_TYPE_PDI_BF1_MASK              (0x2U)
#define ECAT_FMMU_TYPE_PDI_BF1_SHIFT             (1U)
/*! BF1
 *  0b0..Ignore mapping for write accesses
 *  0b1..Use mapping for write accesses
 */
#define ECAT_FMMU_TYPE_PDI_BF1(x)                (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_TYPE_PDI_BF1_SHIFT)) & ECAT_FMMU_TYPE_PDI_BF1_MASK)

#define ECAT_FMMU_TYPE_PDI_BF2_MASK              (0xFCU)
#define ECAT_FMMU_TYPE_PDI_BF2_SHIFT             (2U)
/*! BF2 - Reserved, write 0 */
#define ECAT_FMMU_TYPE_PDI_BF2(x)                (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_TYPE_PDI_BF2_SHIFT)) & ECAT_FMMU_TYPE_PDI_BF2_MASK)
/*! @} */

/* The count of ECAT_FMMU_TYPE_PDI */
#define ECAT_FMMU_TYPE_PDI_COUNT                 (8U)

/*! @name FMMU_ACTIVATE - Register Activate FMMU */
/*! @{ */

#define ECAT_FMMU_ACTIVATE_BF0_MASK              (0x1U)
#define ECAT_FMMU_ACTIVATE_BF0_SHIFT             (0U)
/*! BF0 - Bit field access for ECAT: r/w
 *  0b0..FMMU deactivated
 *  0b1..FMMU activated. FMMU checks logically addressed blocks to be mapped according to configured mapping
 */
#define ECAT_FMMU_ACTIVATE_BF0(x)                (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_ACTIVATE_BF0_SHIFT)) & ECAT_FMMU_ACTIVATE_BF0_MASK)

#define ECAT_FMMU_ACTIVATE_BF1_MASK              (0xFEU)
#define ECAT_FMMU_ACTIVATE_BF1_SHIFT             (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_FMMU_ACTIVATE_BF1(x)                (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_ACTIVATE_BF1_SHIFT)) & ECAT_FMMU_ACTIVATE_BF1_MASK)
/*! @} */

/* The count of ECAT_FMMU_ACTIVATE */
#define ECAT_FMMU_ACTIVATE_COUNT                 (8U)

/*! @name FMMU_ACTIVATE_PDI - Register Activate FMMU */
/*! @{ */

#define ECAT_FMMU_ACTIVATE_PDI_BF0_MASK          (0x1U)
#define ECAT_FMMU_ACTIVATE_PDI_BF0_SHIFT         (0U)
/*! BF0
 *  0b0..FMMU deactivated
 *  0b1..FMMU activated. FMMU checks logically addressed blocks to be mapped according to configured mapping
 */
#define ECAT_FMMU_ACTIVATE_PDI_BF0(x)            (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_ACTIVATE_PDI_BF0_SHIFT)) & ECAT_FMMU_ACTIVATE_PDI_BF0_MASK)

#define ECAT_FMMU_ACTIVATE_PDI_BF1_MASK          (0xFEU)
#define ECAT_FMMU_ACTIVATE_PDI_BF1_SHIFT         (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_FMMU_ACTIVATE_PDI_BF1(x)            (((uint8_t)(((uint8_t)(x)) << ECAT_FMMU_ACTIVATE_PDI_BF1_SHIFT)) & ECAT_FMMU_ACTIVATE_PDI_BF1_MASK)
/*! @} */

/* The count of ECAT_FMMU_ACTIVATE_PDI */
#define ECAT_FMMU_ACTIVATE_PDI_COUNT             (8U)

/*! @name SYNCMANAGER_PHYSICAL_START_ADDRESS - Register physical Start Address SyncManager */
/*! @{ */

#define ECAT_SYNCMANAGER_PHYSICAL_START_ADDRESS_BF0_MASK (0xFFFFU)
#define ECAT_SYNCMANAGER_PHYSICAL_START_ADDRESS_BF0_SHIFT (0U)
/*! BF0 - First byte that will be handled by SyncManager */
#define ECAT_SYNCMANAGER_PHYSICAL_START_ADDRESS_BF0(x) (((uint16_t)(((uint16_t)(x)) << ECAT_SYNCMANAGER_PHYSICAL_START_ADDRESS_BF0_SHIFT)) & ECAT_SYNCMANAGER_PHYSICAL_START_ADDRESS_BF0_MASK)
/*! @} */

/* The count of ECAT_SYNCMANAGER_PHYSICAL_START_ADDRESS */
#define ECAT_SYNCMANAGER_PHYSICAL_START_ADDRESS_COUNT (16U)

/*! @name SYNCMANAGER_PHYSICAL_START_ADDRESS_PDI - Register physical Start Address SyncManager */
/*! @{ */

#define ECAT_SYNCMANAGER_PHYSICAL_START_ADDRESS_PDI_BF0_MASK (0xFFFFU)
#define ECAT_SYNCMANAGER_PHYSICAL_START_ADDRESS_PDI_BF0_SHIFT (0U)
/*! BF0 - First byte that will be handled by SyncManager */
#define ECAT_SYNCMANAGER_PHYSICAL_START_ADDRESS_PDI_BF0(x) (((uint16_t)(((uint16_t)(x)) << ECAT_SYNCMANAGER_PHYSICAL_START_ADDRESS_PDI_BF0_SHIFT)) & ECAT_SYNCMANAGER_PHYSICAL_START_ADDRESS_PDI_BF0_MASK)
/*! @} */

/* The count of ECAT_SYNCMANAGER_PHYSICAL_START_ADDRESS_PDI */
#define ECAT_SYNCMANAGER_PHYSICAL_START_ADDRESS_PDI_COUNT (16U)

/*! @name SYNCMANAGER_LENGTH - Register Length SyncManager */
/*! @{ */

#define ECAT_SYNCMANAGER_LENGTH_BF0_MASK         (0xFFFFU)
#define ECAT_SYNCMANAGER_LENGTH_BF0_SHIFT        (0U)
/*! BF0 - Number of bytes assigned to SyncManager (shall be greater than 1 */
#define ECAT_SYNCMANAGER_LENGTH_BF0(x)           (((uint16_t)(((uint16_t)(x)) << ECAT_SYNCMANAGER_LENGTH_BF0_SHIFT)) & ECAT_SYNCMANAGER_LENGTH_BF0_MASK)
/*! @} */

/* The count of ECAT_SYNCMANAGER_LENGTH */
#define ECAT_SYNCMANAGER_LENGTH_COUNT            (16U)

/*! @name SYNCMANAGER_LENGTH_PDI - Register Length SyncManager */
/*! @{ */

#define ECAT_SYNCMANAGER_LENGTH_PDI_BF0_MASK     (0xFFFFU)
#define ECAT_SYNCMANAGER_LENGTH_PDI_BF0_SHIFT    (0U)
/*! BF0 - Number of bytes assigned to SyncManager (shall be greater than 1 */
#define ECAT_SYNCMANAGER_LENGTH_PDI_BF0(x)       (((uint16_t)(((uint16_t)(x)) << ECAT_SYNCMANAGER_LENGTH_PDI_BF0_SHIFT)) & ECAT_SYNCMANAGER_LENGTH_PDI_BF0_MASK)
/*! @} */

/* The count of ECAT_SYNCMANAGER_LENGTH_PDI */
#define ECAT_SYNCMANAGER_LENGTH_PDI_COUNT        (16U)

/*! @name SYNCMANAGER_CONTROL_REGISTER - Register Control Register SyncManager */
/*! @{ */

#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF0_MASK (0x3U)
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF0_SHIFT (0U)
/*! BF0 - Operation Mode:
 *  0b00..Buffered (3 buffer mode)
 *  0b01..Reserved
 *  0b10..Mailbox (Single buffer mode)
 *  0b11..Reserved
 */
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_CONTROL_REGISTER_BF0_SHIFT)) & ECAT_SYNCMANAGER_CONTROL_REGISTER_BF0_MASK)

#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF2_MASK (0xCU)
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF2_SHIFT (2U)
/*! BF2 - Direction:
 *  0b00..Read: ECAT read access, PDI write access.
 *  0b01..Write: ECAT write access, PDI read access.
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF2(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_CONTROL_REGISTER_BF2_SHIFT)) & ECAT_SYNCMANAGER_CONTROL_REGISTER_BF2_MASK)

#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF4_MASK (0x10U)
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF4_SHIFT (4U)
/*! BF4 - Interrupt in ECAT Event Request Register:
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF4(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_CONTROL_REGISTER_BF4_SHIFT)) & ECAT_SYNCMANAGER_CONTROL_REGISTER_BF4_MASK)

#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF5_MASK (0x20U)
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF5_SHIFT (5U)
/*! BF5 - Interrupt in AL Event Request Register:
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF5(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_CONTROL_REGISTER_BF5_SHIFT)) & ECAT_SYNCMANAGER_CONTROL_REGISTER_BF5_MASK)

#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF6_MASK (0x40U)
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF6_SHIFT (6U)
/*! BF6 - Watchdog Trigger Enable:
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF6(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_CONTROL_REGISTER_BF6_SHIFT)) & ECAT_SYNCMANAGER_CONTROL_REGISTER_BF6_MASK)

#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF7_MASK (0x80U)
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF7_SHIFT (7U)
/*! BF7 - Reserved, write 0 */
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_BF7(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_CONTROL_REGISTER_BF7_SHIFT)) & ECAT_SYNCMANAGER_CONTROL_REGISTER_BF7_MASK)
/*! @} */

/* The count of ECAT_SYNCMANAGER_CONTROL_REGISTER */
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_COUNT  (16U)

/*! @name SYNCMANAGER_CONTROL_REGISTER_PDI - Register Control Register SyncManager */
/*! @{ */

#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF0_MASK (0x3U)
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF0_SHIFT (0U)
/*! BF0 - Operation Mode:
 *  0b00..Buffered (3 buffer mode)
 *  0b01..Reserved
 *  0b10..Mailbox (Single buffer mode)
 *  0b11..Reserved
 */
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF0_SHIFT)) & ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF0_MASK)

#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF2_MASK (0xCU)
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF2_SHIFT (2U)
/*! BF2 - Direction:
 *  0b00..Read: ECAT read access, PDI write access.
 *  0b01..Write: ECAT write access, PDI read access.
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF2(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF2_SHIFT)) & ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF2_MASK)

#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF4_MASK (0x10U)
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF4_SHIFT (4U)
/*! BF4 - Interrupt in ECAT Event Request Register:
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF4(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF4_SHIFT)) & ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF4_MASK)

#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF5_MASK (0x20U)
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF5_SHIFT (5U)
/*! BF5 - Interrupt in AL Event Request Register:
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF5(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF5_SHIFT)) & ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF5_MASK)

#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF6_MASK (0x40U)
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF6_SHIFT (6U)
/*! BF6 - Watchdog Trigger Enable:
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF6(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF6_SHIFT)) & ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF6_MASK)

#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF7_MASK (0x80U)
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF7_SHIFT (7U)
/*! BF7 - Reserved, write 0 */
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF7(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF7_SHIFT)) & ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_BF7_MASK)
/*! @} */

/* The count of ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI */
#define ECAT_SYNCMANAGER_CONTROL_REGISTER_PDI_COUNT (16U)

/*! @name SYNCMANAGER_STATUS - Register Status Register SyncManager */
/*! @{ */

#define ECAT_SYNCMANAGER_STATUS_BF0_MASK         (0x1U)
#define ECAT_SYNCMANAGER_STATUS_BF0_SHIFT        (0U)
/*! BF0 - Interrupt Write:
 *  0b0..Interrupt cleared after first byte of buffer was read
 *  0b1..Interrupt after buffer was completely and successfully written
 */
#define ECAT_SYNCMANAGER_STATUS_BF0(x)           (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_STATUS_BF0_SHIFT)) & ECAT_SYNCMANAGER_STATUS_BF0_MASK)

#define ECAT_SYNCMANAGER_STATUS_BF1_MASK         (0x2U)
#define ECAT_SYNCMANAGER_STATUS_BF1_SHIFT        (1U)
/*! BF1 - Interrupt Read:
 *  0b0..Interrupt cleared after first byte of buffer was written
 *  0b1..Interrupt after buffer was completely and successfully read
 */
#define ECAT_SYNCMANAGER_STATUS_BF1(x)           (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_STATUS_BF1_SHIFT)) & ECAT_SYNCMANAGER_STATUS_BF1_MASK)

#define ECAT_SYNCMANAGER_STATUS_BF2_MASK         (0x4U)
#define ECAT_SYNCMANAGER_STATUS_BF2_SHIFT        (2U)
/*! BF2 - Reserved */
#define ECAT_SYNCMANAGER_STATUS_BF2(x)           (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_STATUS_BF2_SHIFT)) & ECAT_SYNCMANAGER_STATUS_BF2_MASK)

#define ECAT_SYNCMANAGER_STATUS_BF3_MASK         (0x8U)
#define ECAT_SYNCMANAGER_STATUS_BF3_SHIFT        (3U)
/*! BF3 - Mailbox mode: mailbox status:
 *  0b0..Mailbox empty
 *  0b1..Mailbox full
 */
#define ECAT_SYNCMANAGER_STATUS_BF3(x)           (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_STATUS_BF3_SHIFT)) & ECAT_SYNCMANAGER_STATUS_BF3_MASK)

#define ECAT_SYNCMANAGER_STATUS_BF4_MASK         (0x30U)
#define ECAT_SYNCMANAGER_STATUS_BF4_SHIFT        (4U)
/*! BF4 - Buffered mode: buffer status (last written buffer):
 *  0b00..1st buffer
 *  0b01..2nd buffer
 *  0b10..3rd buffer
 *  0b11..(no buffer written)
 */
#define ECAT_SYNCMANAGER_STATUS_BF4(x)           (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_STATUS_BF4_SHIFT)) & ECAT_SYNCMANAGER_STATUS_BF4_MASK)

#define ECAT_SYNCMANAGER_STATUS_BF6_MASK         (0x40U)
#define ECAT_SYNCMANAGER_STATUS_BF6_SHIFT        (6U)
/*! BF6 - Read buffer in use (opened) */
#define ECAT_SYNCMANAGER_STATUS_BF6(x)           (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_STATUS_BF6_SHIFT)) & ECAT_SYNCMANAGER_STATUS_BF6_MASK)

#define ECAT_SYNCMANAGER_STATUS_BF7_MASK         (0x80U)
#define ECAT_SYNCMANAGER_STATUS_BF7_SHIFT        (7U)
/*! BF7 - Write buffer in use (opened) */
#define ECAT_SYNCMANAGER_STATUS_BF7(x)           (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_STATUS_BF7_SHIFT)) & ECAT_SYNCMANAGER_STATUS_BF7_MASK)
/*! @} */

/* The count of ECAT_SYNCMANAGER_STATUS */
#define ECAT_SYNCMANAGER_STATUS_COUNT            (16U)

/*! @name SYNCMANAGER_ACTIVATE - Register Activate SyncManager */
/*! @{ */

#define ECAT_SYNCMANAGER_ACTIVATE_BF0_MASK       (0x1U)
#define ECAT_SYNCMANAGER_ACTIVATE_BF0_SHIFT      (0U)
/*! BF0 - SyncManager Enable/Disable:
 *  0b0..Disable: Access to Memory without SyncManager control
 *  0b1..Enable: SyncManager is active and controls Memory area set in configuration
 */
#define ECAT_SYNCMANAGER_ACTIVATE_BF0(x)         (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_ACTIVATE_BF0_SHIFT)) & ECAT_SYNCMANAGER_ACTIVATE_BF0_MASK)

#define ECAT_SYNCMANAGER_ACTIVATE_BF1_MASK       (0x2U)
#define ECAT_SYNCMANAGER_ACTIVATE_BF1_SHIFT      (1U)
/*! BF1 - Repeat Request: */
#define ECAT_SYNCMANAGER_ACTIVATE_BF1(x)         (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_ACTIVATE_BF1_SHIFT)) & ECAT_SYNCMANAGER_ACTIVATE_BF1_MASK)

#define ECAT_SYNCMANAGER_ACTIVATE_BF2_MASK       (0x3CU)
#define ECAT_SYNCMANAGER_ACTIVATE_BF2_SHIFT      (2U)
/*! BF2 - Reserved, write 0 */
#define ECAT_SYNCMANAGER_ACTIVATE_BF2(x)         (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_ACTIVATE_BF2_SHIFT)) & ECAT_SYNCMANAGER_ACTIVATE_BF2_MASK)

#define ECAT_SYNCMANAGER_ACTIVATE_BF6_MASK       (0x40U)
#define ECAT_SYNCMANAGER_ACTIVATE_BF6_SHIFT      (6U)
/*! BF6 - Latch Event ECAT:
 *  0b0..No
 *  0b1..Generate Latch event when EtherCAT master issues a buffer exchange
 */
#define ECAT_SYNCMANAGER_ACTIVATE_BF6(x)         (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_ACTIVATE_BF6_SHIFT)) & ECAT_SYNCMANAGER_ACTIVATE_BF6_MASK)

#define ECAT_SYNCMANAGER_ACTIVATE_BF7_MASK       (0x80U)
#define ECAT_SYNCMANAGER_ACTIVATE_BF7_SHIFT      (7U)
/*! BF7 - Latch Event PDI:
 *  0b0..No
 *  0b1..Generate Latch events when PDI issues a buffer exchange or when PDI accesses buffer start address
 */
#define ECAT_SYNCMANAGER_ACTIVATE_BF7(x)         (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_ACTIVATE_BF7_SHIFT)) & ECAT_SYNCMANAGER_ACTIVATE_BF7_MASK)
/*! @} */

/* The count of ECAT_SYNCMANAGER_ACTIVATE */
#define ECAT_SYNCMANAGER_ACTIVATE_COUNT          (16U)

/*! @name SYNCMANAGER_ACTIVATE_PDI - Register Activate SyncManager */
/*! @{ */

#define ECAT_SYNCMANAGER_ACTIVATE_PDI_BF0_MASK   (0x1U)
#define ECAT_SYNCMANAGER_ACTIVATE_PDI_BF0_SHIFT  (0U)
/*! BF0 - SyncManager Enable/Disable:
 *  0b0..Disable: Access to Memory without SyncManager control
 *  0b1..Enable: SyncManager is active and controls Memory area set in configuration
 */
#define ECAT_SYNCMANAGER_ACTIVATE_PDI_BF0(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_ACTIVATE_PDI_BF0_SHIFT)) & ECAT_SYNCMANAGER_ACTIVATE_PDI_BF0_MASK)

#define ECAT_SYNCMANAGER_ACTIVATE_PDI_BF1_MASK   (0x2U)
#define ECAT_SYNCMANAGER_ACTIVATE_PDI_BF1_SHIFT  (1U)
/*! BF1 - Repeat Request: */
#define ECAT_SYNCMANAGER_ACTIVATE_PDI_BF1(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_ACTIVATE_PDI_BF1_SHIFT)) & ECAT_SYNCMANAGER_ACTIVATE_PDI_BF1_MASK)

#define ECAT_SYNCMANAGER_ACTIVATE_PDI_BF2_MASK   (0x3CU)
#define ECAT_SYNCMANAGER_ACTIVATE_PDI_BF2_SHIFT  (2U)
/*! BF2 - Reserved, write 0 */
#define ECAT_SYNCMANAGER_ACTIVATE_PDI_BF2(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_ACTIVATE_PDI_BF2_SHIFT)) & ECAT_SYNCMANAGER_ACTIVATE_PDI_BF2_MASK)

#define ECAT_SYNCMANAGER_ACTIVATE_PDI_BF6_MASK   (0x40U)
#define ECAT_SYNCMANAGER_ACTIVATE_PDI_BF6_SHIFT  (6U)
/*! BF6 - Latch Event ECAT:
 *  0b0..No
 *  0b1..Generate Latch event when EtherCAT master issues a buffer exchange
 */
#define ECAT_SYNCMANAGER_ACTIVATE_PDI_BF6(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_ACTIVATE_PDI_BF6_SHIFT)) & ECAT_SYNCMANAGER_ACTIVATE_PDI_BF6_MASK)

#define ECAT_SYNCMANAGER_ACTIVATE_PDI_BF7_MASK   (0x80U)
#define ECAT_SYNCMANAGER_ACTIVATE_PDI_BF7_SHIFT  (7U)
/*! BF7 - Latch Event PDI:
 *  0b0..No
 *  0b1..Generate Latch events when PDI issues a buffer exchange or when PDI accesses buffer start address
 */
#define ECAT_SYNCMANAGER_ACTIVATE_PDI_BF7(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_ACTIVATE_PDI_BF7_SHIFT)) & ECAT_SYNCMANAGER_ACTIVATE_PDI_BF7_MASK)
/*! @} */

/* The count of ECAT_SYNCMANAGER_ACTIVATE_PDI */
#define ECAT_SYNCMANAGER_ACTIVATE_PDI_COUNT      (16U)

/*! @name SYNCMANAGER_PDI_CONTROL - Register PDI Control SyncManager */
/*! @{ */

#define ECAT_SYNCMANAGER_PDI_CONTROL_BF0_MASK    (0x1U)
#define ECAT_SYNCMANAGER_PDI_CONTROL_BF0_SHIFT   (0U)
/*! BF0 - Deactivate SyncManager: */
#define ECAT_SYNCMANAGER_PDI_CONTROL_BF0(x)      (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_PDI_CONTROL_BF0_SHIFT)) & ECAT_SYNCMANAGER_PDI_CONTROL_BF0_MASK)

#define ECAT_SYNCMANAGER_PDI_CONTROL_BF1_MASK    (0x2U)
#define ECAT_SYNCMANAGER_PDI_CONTROL_BF1_SHIFT   (1U)
/*! BF1 - Repeat Ack: */
#define ECAT_SYNCMANAGER_PDI_CONTROL_BF1(x)      (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_PDI_CONTROL_BF1_SHIFT)) & ECAT_SYNCMANAGER_PDI_CONTROL_BF1_MASK)

#define ECAT_SYNCMANAGER_PDI_CONTROL_BF2_MASK    (0xFCU)
#define ECAT_SYNCMANAGER_PDI_CONTROL_BF2_SHIFT   (2U)
/*! BF2 - Reserved, write 0 */
#define ECAT_SYNCMANAGER_PDI_CONTROL_BF2(x)      (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_PDI_CONTROL_BF2_SHIFT)) & ECAT_SYNCMANAGER_PDI_CONTROL_BF2_MASK)
/*! @} */

/* The count of ECAT_SYNCMANAGER_PDI_CONTROL */
#define ECAT_SYNCMANAGER_PDI_CONTROL_COUNT       (16U)

/*! @name SYNCMANAGER_PDI_CONTROL_PDI - Register PDI Control SyncManager */
/*! @{ */

#define ECAT_SYNCMANAGER_PDI_CONTROL_PDI_BF0_MASK (0x1U)
#define ECAT_SYNCMANAGER_PDI_CONTROL_PDI_BF0_SHIFT (0U)
/*! BF0 - Deactivate SyncManager: */
#define ECAT_SYNCMANAGER_PDI_CONTROL_PDI_BF0(x)  (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_PDI_CONTROL_PDI_BF0_SHIFT)) & ECAT_SYNCMANAGER_PDI_CONTROL_PDI_BF0_MASK)

#define ECAT_SYNCMANAGER_PDI_CONTROL_PDI_BF1_MASK (0x2U)
#define ECAT_SYNCMANAGER_PDI_CONTROL_PDI_BF1_SHIFT (1U)
/*! BF1 - Repeat Ack: */
#define ECAT_SYNCMANAGER_PDI_CONTROL_PDI_BF1(x)  (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_PDI_CONTROL_PDI_BF1_SHIFT)) & ECAT_SYNCMANAGER_PDI_CONTROL_PDI_BF1_MASK)

#define ECAT_SYNCMANAGER_PDI_CONTROL_PDI_BF2_MASK (0xFCU)
#define ECAT_SYNCMANAGER_PDI_CONTROL_PDI_BF2_SHIFT (2U)
/*! BF2 - Reserved, write 0 */
#define ECAT_SYNCMANAGER_PDI_CONTROL_PDI_BF2(x)  (((uint8_t)(((uint8_t)(x)) << ECAT_SYNCMANAGER_PDI_CONTROL_PDI_BF2_SHIFT)) & ECAT_SYNCMANAGER_PDI_CONTROL_PDI_BF2_MASK)
/*! @} */

/* The count of ECAT_SYNCMANAGER_PDI_CONTROL_PDI */
#define ECAT_SYNCMANAGER_PDI_CONTROL_PDI_COUNT   (16U)

/*! @name RECEIVE_TIMES - Distributed Clocks Receive Times */
/*! @{ */

#define ECAT_RECEIVE_TIMES_BF0_MASK              (0xFFU)
#define ECAT_RECEIVE_TIMES_BF0_SHIFT             (0U)
/*! BF0 - Write */
#define ECAT_RECEIVE_TIMES_BF0(x)                (((uint32_t)(((uint32_t)(x)) << ECAT_RECEIVE_TIMES_BF0_SHIFT)) & ECAT_RECEIVE_TIMES_BF0_MASK)

#define ECAT_RECEIVE_TIMES_BF8_MASK              (0xFFFFFF00U)
#define ECAT_RECEIVE_TIMES_BF8_SHIFT             (8U)
/*! BF8 - Local time at the beginning of the last receive frame containing a write access to register 0x0900. */
#define ECAT_RECEIVE_TIMES_BF8(x)                (((uint32_t)(((uint32_t)(x)) << ECAT_RECEIVE_TIMES_BF8_SHIFT)) & ECAT_RECEIVE_TIMES_BF8_MASK)
/*! @} */

/*! @name RECEIVE_TIMES_PDI - Distributed Clocks Receive Times */
/*! @{ */

#define ECAT_RECEIVE_TIMES_PDI_BF0_MASK          (0xFFU)
#define ECAT_RECEIVE_TIMES_PDI_BF0_SHIFT         (0U)
/*! BF0 - Write */
#define ECAT_RECEIVE_TIMES_PDI_BF0(x)            (((uint32_t)(((uint32_t)(x)) << ECAT_RECEIVE_TIMES_PDI_BF0_SHIFT)) & ECAT_RECEIVE_TIMES_PDI_BF0_MASK)

#define ECAT_RECEIVE_TIMES_PDI_BF8_MASK          (0xFFFFFF00U)
#define ECAT_RECEIVE_TIMES_PDI_BF8_SHIFT         (8U)
/*! BF8 - Local time at the beginning of the last receive frame containing a write access to register 0x0900. */
#define ECAT_RECEIVE_TIMES_PDI_BF8(x)            (((uint32_t)(((uint32_t)(x)) << ECAT_RECEIVE_TIMES_PDI_BF8_SHIFT)) & ECAT_RECEIVE_TIMES_PDI_BF8_MASK)
/*! @} */

/*! @name RECEIVE_TIME_PORT_1 - Distributed Clocks Receive Time Port 1 */
/*! @{ */

#define ECAT_RECEIVE_TIME_PORT_1_BF0_MASK        (0xFFFFFFFFU)
#define ECAT_RECEIVE_TIME_PORT_1_BF0_SHIFT       (0U)
/*! BF0 - Local time at the beginning of a frame (start first bit of preamble) received at port 1
 *    containing a BWR or FPWR to register 0x0900.
 */
#define ECAT_RECEIVE_TIME_PORT_1_BF0(x)          (((uint32_t)(((uint32_t)(x)) << ECAT_RECEIVE_TIME_PORT_1_BF0_SHIFT)) & ECAT_RECEIVE_TIME_PORT_1_BF0_MASK)
/*! @} */

/*! @name SYSTEM_TIME - Register System Time */
/*! @{ */

#define ECAT_SYSTEM_TIME_BF0ECAT_MASK            (0xFFFFFFFFFFFFFFFFU)
#define ECAT_SYSTEM_TIME_BF0ECAT_SHIFT           (0U)
/*! BF0ECAT - ECAT read access */
#define ECAT_SYSTEM_TIME_BF0ECAT(x)              (((uint64_t)(((uint64_t)(x)) << ECAT_SYSTEM_TIME_BF0ECAT_SHIFT)) & ECAT_SYSTEM_TIME_BF0ECAT_MASK)
/*! @} */

/*! @name SYSTEM_TIME_PDI - Register System Time */
/*! @{ */

#define ECAT_SYSTEM_TIME_PDI_BF0ECAT_MASK        (0xFFFFFFFFFFFFFFFFU)
#define ECAT_SYSTEM_TIME_PDI_BF0ECAT_SHIFT       (0U)
/*! BF0ECAT - PDI read access */
#define ECAT_SYSTEM_TIME_PDI_BF0ECAT(x)          (((uint64_t)(((uint64_t)(x)) << ECAT_SYSTEM_TIME_PDI_BF0ECAT_SHIFT)) & ECAT_SYSTEM_TIME_PDI_BF0ECAT_MASK)
/*! @} */

/*! @name RECEIVE_TIME_ECAT_PROCESSING_UNIT - Distributed Clocks Register Receive Time ECAT Processing Unit */
/*! @{ */

#define ECAT_RECEIVE_TIME_ECAT_PROCESSING_UNIT_BF0_MASK (0xFFFFFFFFFFFFFFFFU)
#define ECAT_RECEIVE_TIME_ECAT_PROCESSING_UNIT_BF0_SHIFT (0U)
/*! BF0 - Local time at the beginning of a frame (start first bit of preamble) received at the ECAT
 *    Processing Unit containing a write access to register 0x0900
 */
#define ECAT_RECEIVE_TIME_ECAT_PROCESSING_UNIT_BF0(x) (((uint64_t)(((uint64_t)(x)) << ECAT_RECEIVE_TIME_ECAT_PROCESSING_UNIT_BF0_SHIFT)) & ECAT_RECEIVE_TIME_ECAT_PROCESSING_UNIT_BF0_MASK)
/*! @} */

/*! @name SYSTEM_TIME_OFFSET - Register System Time Offset */
/*! @{ */

#define ECAT_SYSTEM_TIME_OFFSET_BF0_MASK         (0xFFFFFFFFFFFFFFFFU)
#define ECAT_SYSTEM_TIME_OFFSET_BF0_SHIFT        (0U)
/*! BF0 - Difference between local time and System Time. Offset is added to the local time. */
#define ECAT_SYSTEM_TIME_OFFSET_BF0(x)           (((uint64_t)(((uint64_t)(x)) << ECAT_SYSTEM_TIME_OFFSET_BF0_SHIFT)) & ECAT_SYSTEM_TIME_OFFSET_BF0_MASK)
/*! @} */

/*! @name SYSTEM_TIME_DELAY - Register System Time Delay */
/*! @{ */

#define ECAT_SYSTEM_TIME_DELAY_BF0_MASK          (0xFFFFFFFFU)
#define ECAT_SYSTEM_TIME_DELAY_BF0_SHIFT         (0U)
/*! BF0 - Delay between Reference Clock and the eCAT */
#define ECAT_SYSTEM_TIME_DELAY_BF0(x)            (((uint32_t)(((uint32_t)(x)) << ECAT_SYSTEM_TIME_DELAY_BF0_SHIFT)) & ECAT_SYSTEM_TIME_DELAY_BF0_MASK)
/*! @} */

/*! @name SYSTEM_TIME_DIFFERENCE - Register System Time Difference */
/*! @{ */

#define ECAT_SYSTEM_TIME_DIFFERENCE_BF0_MASK     (0x7FFFFFFFU)
#define ECAT_SYSTEM_TIME_DIFFERENCE_BF0_SHIFT    (0U)
/*! BF0 - Mean difference between local copy of system Time and received System Time values */
#define ECAT_SYSTEM_TIME_DIFFERENCE_BF0(x)       (((uint32_t)(((uint32_t)(x)) << ECAT_SYSTEM_TIME_DIFFERENCE_BF0_SHIFT)) & ECAT_SYSTEM_TIME_DIFFERENCE_BF0_MASK)

#define ECAT_SYSTEM_TIME_DIFFERENCE_BF31_MASK    (0x80000000U)
#define ECAT_SYSTEM_TIME_DIFFERENCE_BF31_SHIFT   (31U)
/*! BF31 - Bit field access for ECAT: r/-
 *  0b0..Local copy of System Time less than received System Time
 *  0b1..Local copy of System Time greater than or equal to received System Time
 */
#define ECAT_SYSTEM_TIME_DIFFERENCE_BF31(x)      (((uint32_t)(((uint32_t)(x)) << ECAT_SYSTEM_TIME_DIFFERENCE_BF31_SHIFT)) & ECAT_SYSTEM_TIME_DIFFERENCE_BF31_MASK)
/*! @} */

/*! @name SPEED_COUNTER_START - Register Speed Counter Start */
/*! @{ */

#define ECAT_SPEED_COUNTER_START_BF0_MASK        (0x7FFFU)
#define ECAT_SPEED_COUNTER_START_BF0_SHIFT       (0U)
/*! BF0 - Bandwidth for adjustment of local copy of system Time (larger values -> smaller bandwidth and smoother adjustment) */
#define ECAT_SPEED_COUNTER_START_BF0(x)          (((uint16_t)(((uint16_t)(x)) << ECAT_SPEED_COUNTER_START_BF0_SHIFT)) & ECAT_SPEED_COUNTER_START_BF0_MASK)

#define ECAT_SPEED_COUNTER_START_BF15_MASK       (0x8000U)
#define ECAT_SPEED_COUNTER_START_BF15_SHIFT      (15U)
/*! BF15 - Reserved, write 0 */
#define ECAT_SPEED_COUNTER_START_BF15(x)         (((uint16_t)(((uint16_t)(x)) << ECAT_SPEED_COUNTER_START_BF15_SHIFT)) & ECAT_SPEED_COUNTER_START_BF15_MASK)
/*! @} */

/*! @name SPEED_COUNTER_DIFF - Register Speed Counter Diff */
/*! @{ */

#define ECAT_SPEED_COUNTER_DIFF_BF0_MASK         (0xFFFFU)
#define ECAT_SPEED_COUNTER_DIFF_BF0_SHIFT        (0U)
/*! BF0 - Representation of the deviation between local clock period and Reference Clock's clock
 *    period (representation: two's complement)
 */
#define ECAT_SPEED_COUNTER_DIFF_BF0(x)           (((uint16_t)(((uint16_t)(x)) << ECAT_SPEED_COUNTER_DIFF_BF0_SHIFT)) & ECAT_SPEED_COUNTER_DIFF_BF0_MASK)
/*! @} */

/*! @name SYSTEM_TIME_DIFFERENCE_FILTER_DEPTH - Register System Time Difference Filter Depth */
/*! @{ */

#define ECAT_SYSTEM_TIME_DIFFERENCE_FILTER_DEPTH_BF0_MASK (0xFU)
#define ECAT_SYSTEM_TIME_DIFFERENCE_FILTER_DEPTH_BF0_SHIFT (0U)
/*! BF0 - Filter depth for averaging the received System Time deviation */
#define ECAT_SYSTEM_TIME_DIFFERENCE_FILTER_DEPTH_BF0(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYSTEM_TIME_DIFFERENCE_FILTER_DEPTH_BF0_SHIFT)) & ECAT_SYSTEM_TIME_DIFFERENCE_FILTER_DEPTH_BF0_MASK)

#define ECAT_SYSTEM_TIME_DIFFERENCE_FILTER_DEPTH_BF4_MASK (0xF0U)
#define ECAT_SYSTEM_TIME_DIFFERENCE_FILTER_DEPTH_BF4_SHIFT (4U)
/*! BF4 - Reserved, write 0 */
#define ECAT_SYSTEM_TIME_DIFFERENCE_FILTER_DEPTH_BF4(x) (((uint8_t)(((uint8_t)(x)) << ECAT_SYSTEM_TIME_DIFFERENCE_FILTER_DEPTH_BF4_SHIFT)) & ECAT_SYSTEM_TIME_DIFFERENCE_FILTER_DEPTH_BF4_MASK)
/*! @} */

/*! @name SPEED_COUNTER_FILTER_DEPTH - Register Speed Counter Filter Depth */
/*! @{ */

#define ECAT_SPEED_COUNTER_FILTER_DEPTH_BF0_MASK (0xFU)
#define ECAT_SPEED_COUNTER_FILTER_DEPTH_BF0_SHIFT (0U)
/*! BF0 - Filter depth for averaging the clock period deviation */
#define ECAT_SPEED_COUNTER_FILTER_DEPTH_BF0(x)   (((uint8_t)(((uint8_t)(x)) << ECAT_SPEED_COUNTER_FILTER_DEPTH_BF0_SHIFT)) & ECAT_SPEED_COUNTER_FILTER_DEPTH_BF0_MASK)

#define ECAT_SPEED_COUNTER_FILTER_DEPTH_BF4_MASK (0xF0U)
#define ECAT_SPEED_COUNTER_FILTER_DEPTH_BF4_SHIFT (4U)
/*! BF4 - Reserved, write 0 */
#define ECAT_SPEED_COUNTER_FILTER_DEPTH_BF4(x)   (((uint8_t)(((uint8_t)(x)) << ECAT_SPEED_COUNTER_FILTER_DEPTH_BF4_SHIFT)) & ECAT_SPEED_COUNTER_FILTER_DEPTH_BF4_MASK)
/*! @} */

/*! @name CYCLIC_UNIT_CONTROL - Register Cyclic Unit Control */
/*! @{ */

#define ECAT_CYCLIC_UNIT_CONTROL_BF0_MASK        (0x1U)
#define ECAT_CYCLIC_UNIT_CONTROL_BF0_SHIFT       (0U)
/*! BF0 - SYNC out unit control:
 *  0b0..ECAT-controlled
 *  0b1..PDI-controlled
 */
#define ECAT_CYCLIC_UNIT_CONTROL_BF0(x)          (((uint8_t)(((uint8_t)(x)) << ECAT_CYCLIC_UNIT_CONTROL_BF0_SHIFT)) & ECAT_CYCLIC_UNIT_CONTROL_BF0_MASK)

#define ECAT_CYCLIC_UNIT_CONTROL_BF1_MASK        (0xEU)
#define ECAT_CYCLIC_UNIT_CONTROL_BF1_SHIFT       (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_CYCLIC_UNIT_CONTROL_BF1(x)          (((uint8_t)(((uint8_t)(x)) << ECAT_CYCLIC_UNIT_CONTROL_BF1_SHIFT)) & ECAT_CYCLIC_UNIT_CONTROL_BF1_MASK)

#define ECAT_CYCLIC_UNIT_CONTROL_BF4_MASK        (0x10U)
#define ECAT_CYCLIC_UNIT_CONTROL_BF4_SHIFT       (4U)
/*! BF4 - Latch In unit 0:
 *  0b0..ECAT-controlled
 *  0b1..PDI-controlled
 */
#define ECAT_CYCLIC_UNIT_CONTROL_BF4(x)          (((uint8_t)(((uint8_t)(x)) << ECAT_CYCLIC_UNIT_CONTROL_BF4_SHIFT)) & ECAT_CYCLIC_UNIT_CONTROL_BF4_MASK)

#define ECAT_CYCLIC_UNIT_CONTROL_BF5_MASK        (0x20U)
#define ECAT_CYCLIC_UNIT_CONTROL_BF5_SHIFT       (5U)
/*! BF5 - Latch In unit 1:
 *  0b0..ECAT-controlled
 *  0b1..PDI-controlled
 */
#define ECAT_CYCLIC_UNIT_CONTROL_BF5(x)          (((uint8_t)(((uint8_t)(x)) << ECAT_CYCLIC_UNIT_CONTROL_BF5_SHIFT)) & ECAT_CYCLIC_UNIT_CONTROL_BF5_MASK)

#define ECAT_CYCLIC_UNIT_CONTROL_BF6_MASK        (0xC0U)
#define ECAT_CYCLIC_UNIT_CONTROL_BF6_SHIFT       (6U)
/*! BF6 - Reserved, write 0 */
#define ECAT_CYCLIC_UNIT_CONTROL_BF6(x)          (((uint8_t)(((uint8_t)(x)) << ECAT_CYCLIC_UNIT_CONTROL_BF6_SHIFT)) & ECAT_CYCLIC_UNIT_CONTROL_BF6_MASK)
/*! @} */

/*! @name CYCLIC_UNIT_CONTROL_PDI - Register Cyclic Unit Control */
/*! @{ */

#define ECAT_CYCLIC_UNIT_CONTROL_PDI_BF0_MASK    (0x1U)
#define ECAT_CYCLIC_UNIT_CONTROL_PDI_BF0_SHIFT   (0U)
/*! BF0 - SYNC out unit control:
 *  0b0..ECAT-controlled
 *  0b1..PDI-controlled
 */
#define ECAT_CYCLIC_UNIT_CONTROL_PDI_BF0(x)      (((uint8_t)(((uint8_t)(x)) << ECAT_CYCLIC_UNIT_CONTROL_PDI_BF0_SHIFT)) & ECAT_CYCLIC_UNIT_CONTROL_PDI_BF0_MASK)

#define ECAT_CYCLIC_UNIT_CONTROL_PDI_BF1_MASK    (0xEU)
#define ECAT_CYCLIC_UNIT_CONTROL_PDI_BF1_SHIFT   (1U)
/*! BF1 - Reserved, write 0 */
#define ECAT_CYCLIC_UNIT_CONTROL_PDI_BF1(x)      (((uint8_t)(((uint8_t)(x)) << ECAT_CYCLIC_UNIT_CONTROL_PDI_BF1_SHIFT)) & ECAT_CYCLIC_UNIT_CONTROL_PDI_BF1_MASK)

#define ECAT_CYCLIC_UNIT_CONTROL_PDI_BF4_MASK    (0x10U)
#define ECAT_CYCLIC_UNIT_CONTROL_PDI_BF4_SHIFT   (4U)
/*! BF4 - Latch In unit 0:
 *  0b0..ECAT-controlled
 *  0b1..PDI-controlled
 */
#define ECAT_CYCLIC_UNIT_CONTROL_PDI_BF4(x)      (((uint8_t)(((uint8_t)(x)) << ECAT_CYCLIC_UNIT_CONTROL_PDI_BF4_SHIFT)) & ECAT_CYCLIC_UNIT_CONTROL_PDI_BF4_MASK)

#define ECAT_CYCLIC_UNIT_CONTROL_PDI_BF5_MASK    (0x20U)
#define ECAT_CYCLIC_UNIT_CONTROL_PDI_BF5_SHIFT   (5U)
/*! BF5 - Latch In unit 1:
 *  0b0..ECAT-controlled
 *  0b1..PDI-controlled
 */
#define ECAT_CYCLIC_UNIT_CONTROL_PDI_BF5(x)      (((uint8_t)(((uint8_t)(x)) << ECAT_CYCLIC_UNIT_CONTROL_PDI_BF5_SHIFT)) & ECAT_CYCLIC_UNIT_CONTROL_PDI_BF5_MASK)

#define ECAT_CYCLIC_UNIT_CONTROL_PDI_BF6_MASK    (0xC0U)
#define ECAT_CYCLIC_UNIT_CONTROL_PDI_BF6_SHIFT   (6U)
/*! BF6 - Reserved, write 0 */
#define ECAT_CYCLIC_UNIT_CONTROL_PDI_BF6(x)      (((uint8_t)(((uint8_t)(x)) << ECAT_CYCLIC_UNIT_CONTROL_PDI_BF6_SHIFT)) & ECAT_CYCLIC_UNIT_CONTROL_PDI_BF6_MASK)
/*! @} */

/*! @name UNIT_ACTIVATION_REGISTER - Register Activation register */
/*! @{ */

#define ECAT_UNIT_ACTIVATION_REGISTER_BF0_MASK   (0x1U)
#define ECAT_UNIT_ACTIVATION_REGISTER_BF0_SHIFT  (0U)
/*! BF0 - Sync Out Unit activation:
 *  0b0..Deactivated
 *  0b1..Activated
 */
#define ECAT_UNIT_ACTIVATION_REGISTER_BF0(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_UNIT_ACTIVATION_REGISTER_BF0_SHIFT)) & ECAT_UNIT_ACTIVATION_REGISTER_BF0_MASK)

#define ECAT_UNIT_ACTIVATION_REGISTER_BF1_MASK   (0x2U)
#define ECAT_UNIT_ACTIVATION_REGISTER_BF1_SHIFT  (1U)
/*! BF1 - SYNC0 generation:
 *  0b0..Deactivated
 *  0b1..SYNC0 pulse is generated
 */
#define ECAT_UNIT_ACTIVATION_REGISTER_BF1(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_UNIT_ACTIVATION_REGISTER_BF1_SHIFT)) & ECAT_UNIT_ACTIVATION_REGISTER_BF1_MASK)

#define ECAT_UNIT_ACTIVATION_REGISTER_BF2_MASK   (0x4U)
#define ECAT_UNIT_ACTIVATION_REGISTER_BF2_SHIFT  (2U)
/*! BF2 - SYNC1 generation:
 *  0b0..Deactivated
 *  0b1..SYNC1 pulse is generated
 */
#define ECAT_UNIT_ACTIVATION_REGISTER_BF2(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_UNIT_ACTIVATION_REGISTER_BF2_SHIFT)) & ECAT_UNIT_ACTIVATION_REGISTER_BF2_MASK)

#define ECAT_UNIT_ACTIVATION_REGISTER_BF3_MASK   (0x8U)
#define ECAT_UNIT_ACTIVATION_REGISTER_BF3_SHIFT  (3U)
/*! BF3 - Auto-activation by writing Start Time Cyclic Operation (0x0990:0x0997):
 *  0b0..Disabled
 *  0b1..Auto-activation enabled. 0x0981[0] is set automatically after Start Time is written
 */
#define ECAT_UNIT_ACTIVATION_REGISTER_BF3(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_UNIT_ACTIVATION_REGISTER_BF3_SHIFT)) & ECAT_UNIT_ACTIVATION_REGISTER_BF3_MASK)

#define ECAT_UNIT_ACTIVATION_REGISTER_BF4_MASK   (0x10U)
#define ECAT_UNIT_ACTIVATION_REGISTER_BF4_SHIFT  (4U)
/*! BF4 - Extension of Start Time Cyclic Operation (0x0990:0x0993):
 *  0b0..No extension
 *  0b1..Extend 32 bit written Start Time to 64 bit
 */
#define ECAT_UNIT_ACTIVATION_REGISTER_BF4(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_UNIT_ACTIVATION_REGISTER_BF4_SHIFT)) & ECAT_UNIT_ACTIVATION_REGISTER_BF4_MASK)

#define ECAT_UNIT_ACTIVATION_REGISTER_BF5_MASK   (0x20U)
#define ECAT_UNIT_ACTIVATION_REGISTER_BF5_SHIFT  (5U)
/*! BF5 - Start Time plausibility check:
 *  0b0..Disabled. SyncSignal generation if Start Time is reached.
 *  0b1..Immediate SyncSignal generation if Start Time is outside near future (see 0x0981[6])
 */
#define ECAT_UNIT_ACTIVATION_REGISTER_BF5(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_UNIT_ACTIVATION_REGISTER_BF5_SHIFT)) & ECAT_UNIT_ACTIVATION_REGISTER_BF5_MASK)

#define ECAT_UNIT_ACTIVATION_REGISTER_BF6_MASK   (0x40U)
#define ECAT_UNIT_ACTIVATION_REGISTER_BF6_SHIFT  (6U)
/*! BF6 - Near future configuration (approx.):
 *  0b0..1/2 DC width future (2^31ns or 2^63ns)
 *  0b1..~2.1 sec. future (2^31ns)
 */
#define ECAT_UNIT_ACTIVATION_REGISTER_BF6(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_UNIT_ACTIVATION_REGISTER_BF6_SHIFT)) & ECAT_UNIT_ACTIVATION_REGISTER_BF6_MASK)

#define ECAT_UNIT_ACTIVATION_REGISTER_BF7_MASK   (0x80U)
#define ECAT_UNIT_ACTIVATION_REGISTER_BF7_SHIFT  (7U)
/*! BF7 - SyncSignal debug pulse (Vasily bit):
 *  0b0..Deactivated
 *  0b1..Immediately generate one ping only on SYNC0-1 according to 0x0981[2:1] for debugging.
 */
#define ECAT_UNIT_ACTIVATION_REGISTER_BF7(x)     (((uint8_t)(((uint8_t)(x)) << ECAT_UNIT_ACTIVATION_REGISTER_BF7_SHIFT)) & ECAT_UNIT_ACTIVATION_REGISTER_BF7_MASK)
/*! @} */

/*! @name UNI_PULSE_LENGTH_OF_SYNCSIGNALS - Register Pulse Length of SyncSignals */
/*! @{ */

#define ECAT_UNI_PULSE_LENGTH_OF_SYNCSIGNALS_BF0_MASK (0xFFFFU)
#define ECAT_UNI_PULSE_LENGTH_OF_SYNCSIGNALS_BF0_SHIFT (0U)
/*! BF0 - Pulse length of SyncSignals (in Units of 10ns)
 *  0b0000000000000000..Acknowledge mode: SyncSignal will be cleared by reading SYNC[1:0] Status register
 */
#define ECAT_UNI_PULSE_LENGTH_OF_SYNCSIGNALS_BF0(x) (((uint16_t)(((uint16_t)(x)) << ECAT_UNI_PULSE_LENGTH_OF_SYNCSIGNALS_BF0_SHIFT)) & ECAT_UNI_PULSE_LENGTH_OF_SYNCSIGNALS_BF0_MASK)
/*! @} */

/*! @name UNIT_ACTIVATION_STATUS - Register Activation Status */
/*! @{ */

#define ECAT_UNIT_ACTIVATION_STATUS_BF0_MASK     (0x1U)
#define ECAT_UNIT_ACTIVATION_STATUS_BF0_SHIFT    (0U)
/*! BF0 - SYNC0 activation state:
 *  0b0..First SYNC0 pulse is not pending
 *  0b1..First SYNC0 pulse is pending
 */
#define ECAT_UNIT_ACTIVATION_STATUS_BF0(x)       (((uint8_t)(((uint8_t)(x)) << ECAT_UNIT_ACTIVATION_STATUS_BF0_SHIFT)) & ECAT_UNIT_ACTIVATION_STATUS_BF0_MASK)

#define ECAT_UNIT_ACTIVATION_STATUS_BF1_MASK     (0x2U)
#define ECAT_UNIT_ACTIVATION_STATUS_BF1_SHIFT    (1U)
/*! BF1 - SYNC1 activation state:
 *  0b0..First SYNC1 pulse is not pending
 *  0b1..First SYNC1 pulse is pending
 */
#define ECAT_UNIT_ACTIVATION_STATUS_BF1(x)       (((uint8_t)(((uint8_t)(x)) << ECAT_UNIT_ACTIVATION_STATUS_BF1_SHIFT)) & ECAT_UNIT_ACTIVATION_STATUS_BF1_MASK)

#define ECAT_UNIT_ACTIVATION_STATUS_BF2_MASK     (0x4U)
#define ECAT_UNIT_ACTIVATION_STATUS_BF2_SHIFT    (2U)
/*! BF2 - Start Time Cyclic Operation (0x0990:0x0997) plausibility check result when Sync Out Unit was activated:
 *  0b0..Start Time was within near future
 *  0b1..Start Time was out of near future (0x0981[6])
 */
#define ECAT_UNIT_ACTIVATION_STATUS_BF2(x)       (((uint8_t)(((uint8_t)(x)) << ECAT_UNIT_ACTIVATION_STATUS_BF2_SHIFT)) & ECAT_UNIT_ACTIVATION_STATUS_BF2_MASK)

#define ECAT_UNIT_ACTIVATION_STATUS_BF3_MASK     (0xF8U)
#define ECAT_UNIT_ACTIVATION_STATUS_BF3_SHIFT    (3U)
/*! BF3 - Reserved */
#define ECAT_UNIT_ACTIVATION_STATUS_BF3(x)       (((uint8_t)(((uint8_t)(x)) << ECAT_UNIT_ACTIVATION_STATUS_BF3_SHIFT)) & ECAT_UNIT_ACTIVATION_STATUS_BF3_MASK)
/*! @} */

/*! @name UNIT_SYNC0_STATUS - Register SYNC0 Status */
/*! @{ */

#define ECAT_UNIT_SYNC0_STATUS_BF0_MASK          (0x1U)
#define ECAT_UNIT_SYNC0_STATUS_BF0_SHIFT         (0U)
/*! BF0 - SYNC0 state for Acknowledge mode. */
#define ECAT_UNIT_SYNC0_STATUS_BF0(x)            (((uint8_t)(((uint8_t)(x)) << ECAT_UNIT_SYNC0_STATUS_BF0_SHIFT)) & ECAT_UNIT_SYNC0_STATUS_BF0_MASK)

#define ECAT_UNIT_SYNC0_STATUS_BF1_MASK          (0xFEU)
#define ECAT_UNIT_SYNC0_STATUS_BF1_SHIFT         (1U)
/*! BF1 - Reserved */
#define ECAT_UNIT_SYNC0_STATUS_BF1(x)            (((uint8_t)(((uint8_t)(x)) << ECAT_UNIT_SYNC0_STATUS_BF1_SHIFT)) & ECAT_UNIT_SYNC0_STATUS_BF1_MASK)
/*! @} */

/*! @name UNIT_SYNC1_STATUS - Register SYNC1 Status */
/*! @{ */

#define ECAT_UNIT_SYNC1_STATUS_BF0_MASK          (0x1U)
#define ECAT_UNIT_SYNC1_STATUS_BF0_SHIFT         (0U)
/*! BF0 - SYNC1 state for Acknowledge mode. */
#define ECAT_UNIT_SYNC1_STATUS_BF0(x)            (((uint8_t)(((uint8_t)(x)) << ECAT_UNIT_SYNC1_STATUS_BF0_SHIFT)) & ECAT_UNIT_SYNC1_STATUS_BF0_MASK)

#define ECAT_UNIT_SYNC1_STATUS_BF1_MASK          (0xFEU)
#define ECAT_UNIT_SYNC1_STATUS_BF1_SHIFT         (1U)
/*! BF1 - Reserved */
#define ECAT_UNIT_SYNC1_STATUS_BF1(x)            (((uint8_t)(((uint8_t)(x)) << ECAT_UNIT_SYNC1_STATUS_BF1_SHIFT)) & ECAT_UNIT_SYNC1_STATUS_BF1_MASK)
/*! @} */

/*! @name UNIT_START_TIME_CYCLIC_OPERATION - Register Start Time Cyclic Operation */
/*! @{ */

#define ECAT_UNIT_START_TIME_CYCLIC_OPERATION_BF0_MASK (0xFFFFFFFFFFFFFFFFU)
#define ECAT_UNIT_START_TIME_CYCLIC_OPERATION_BF0_SHIFT (0U)
/*! BF0 - Write: Start time (System time) of cyclic operation in ns */
#define ECAT_UNIT_START_TIME_CYCLIC_OPERATION_BF0(x) (((uint64_t)(((uint64_t)(x)) << ECAT_UNIT_START_TIME_CYCLIC_OPERATION_BF0_SHIFT)) & ECAT_UNIT_START_TIME_CYCLIC_OPERATION_BF0_MASK)
/*! @} */

/*! @name UNIT_NEXT_SYNC1_PULSE - Register Next SYNC1 Pulse */
/*! @{ */

#define ECAT_UNIT_NEXT_SYNC1_PULSE_BF0_MASK      (0xFFFFFFFFFFFFFFFFU)
#define ECAT_UNIT_NEXT_SYNC1_PULSE_BF0_SHIFT     (0U)
/*! BF0 - System time of next SYNC1 pulse in ns */
#define ECAT_UNIT_NEXT_SYNC1_PULSE_BF0(x)        (((uint64_t)(((uint64_t)(x)) << ECAT_UNIT_NEXT_SYNC1_PULSE_BF0_SHIFT)) & ECAT_UNIT_NEXT_SYNC1_PULSE_BF0_MASK)
/*! @} */

/*! @name UNIT_SYNC0_CYCLE_TIME - Register SYNC0 Cycle Time */
/*! @{ */

#define ECAT_UNIT_SYNC0_CYCLE_TIME_BF0_MASK      (0xFFFFFFFFU)
#define ECAT_UNIT_SYNC0_CYCLE_TIME_BF0_SHIFT     (0U)
/*! BF0 - Time between two consecutive SYNC0 pulses in ns.
 *  0b00000000000000000000000000000000..Single shot mode, generate only one SYNC0 pulse.
 */
#define ECAT_UNIT_SYNC0_CYCLE_TIME_BF0(x)        (((uint32_t)(((uint32_t)(x)) << ECAT_UNIT_SYNC0_CYCLE_TIME_BF0_SHIFT)) & ECAT_UNIT_SYNC0_CYCLE_TIME_BF0_MASK)
/*! @} */

/*! @name UNIT_SYNC1_CYCLE_TIME - Register SYNC1 Cycle Time */
/*! @{ */

#define ECAT_UNIT_SYNC1_CYCLE_TIME_BF0_MASK      (0xFFFFFFFFU)
#define ECAT_UNIT_SYNC1_CYCLE_TIME_BF0_SHIFT     (0U)
/*! BF0 - Time between SYNC0 pulse and SYNC1 pulse in ns */
#define ECAT_UNIT_SYNC1_CYCLE_TIME_BF0(x)        (((uint32_t)(((uint32_t)(x)) << ECAT_UNIT_SYNC1_CYCLE_TIME_BF0_SHIFT)) & ECAT_UNIT_SYNC1_CYCLE_TIME_BF0_MASK)
/*! @} */

/*! @name LATCH0_CONTROL - Register Latch0 Control */
/*! @{ */

#define ECAT_LATCH0_CONTROL_BF0_MASK             (0x1U)
#define ECAT_LATCH0_CONTROL_BF0_SHIFT            (0U)
/*! BF0 - Latch0 positive edge:
 *  0b0..Continuous Latch active
 *  0b1..Single event (only first event active)
 */
#define ECAT_LATCH0_CONTROL_BF0(x)               (((uint8_t)(((uint8_t)(x)) << ECAT_LATCH0_CONTROL_BF0_SHIFT)) & ECAT_LATCH0_CONTROL_BF0_MASK)

#define ECAT_LATCH0_CONTROL_BF1_MASK             (0x2U)
#define ECAT_LATCH0_CONTROL_BF1_SHIFT            (1U)
/*! BF1 - Latch0 negative edge:
 *  0b0..Continuous Latch active
 *  0b1..Single event (only first event active)
 */
#define ECAT_LATCH0_CONTROL_BF1(x)               (((uint8_t)(((uint8_t)(x)) << ECAT_LATCH0_CONTROL_BF1_SHIFT)) & ECAT_LATCH0_CONTROL_BF1_MASK)

#define ECAT_LATCH0_CONTROL_BF2_MASK             (0xFCU)
#define ECAT_LATCH0_CONTROL_BF2_SHIFT            (2U)
/*! BF2 - Reserved, write 0 */
#define ECAT_LATCH0_CONTROL_BF2(x)               (((uint8_t)(((uint8_t)(x)) << ECAT_LATCH0_CONTROL_BF2_SHIFT)) & ECAT_LATCH0_CONTROL_BF2_MASK)
/*! @} */

/*! @name LATCH1_CONTROL - Register Latch1 Control */
/*! @{ */

#define ECAT_LATCH1_CONTROL_BF0_MASK             (0x1U)
#define ECAT_LATCH1_CONTROL_BF0_SHIFT            (0U)
/*! BF0 - Latch1 positive edge:
 *  0b0..Continuous Latch active
 *  0b1..Single event (only first event active)
 */
#define ECAT_LATCH1_CONTROL_BF0(x)               (((uint8_t)(((uint8_t)(x)) << ECAT_LATCH1_CONTROL_BF0_SHIFT)) & ECAT_LATCH1_CONTROL_BF0_MASK)

#define ECAT_LATCH1_CONTROL_BF1_MASK             (0x2U)
#define ECAT_LATCH1_CONTROL_BF1_SHIFT            (1U)
/*! BF1 - Latch1 negative edge:
 *  0b0..Continuous Latch active
 *  0b1..Single event (only first event active)
 */
#define ECAT_LATCH1_CONTROL_BF1(x)               (((uint8_t)(((uint8_t)(x)) << ECAT_LATCH1_CONTROL_BF1_SHIFT)) & ECAT_LATCH1_CONTROL_BF1_MASK)

#define ECAT_LATCH1_CONTROL_BF2_MASK             (0xFCU)
#define ECAT_LATCH1_CONTROL_BF2_SHIFT            (2U)
/*! BF2 - Reserved, write 0 */
#define ECAT_LATCH1_CONTROL_BF2(x)               (((uint8_t)(((uint8_t)(x)) << ECAT_LATCH1_CONTROL_BF2_SHIFT)) & ECAT_LATCH1_CONTROL_BF2_MASK)
/*! @} */

/*! @name LATCH0_STATUS - Register Latch0 Status */
/*! @{ */

#define ECAT_LATCH0_STATUS_BF0_MASK              (0x1U)
#define ECAT_LATCH0_STATUS_BF0_SHIFT             (0U)
/*! BF0 - Event Latch0 positive edge.
 *  0b0..Positive edge not detected or continuous mode
 *  0b1..Positive edge detected in single event mode only.
 */
#define ECAT_LATCH0_STATUS_BF0(x)                (((uint8_t)(((uint8_t)(x)) << ECAT_LATCH0_STATUS_BF0_SHIFT)) & ECAT_LATCH0_STATUS_BF0_MASK)

#define ECAT_LATCH0_STATUS_BF1_MASK              (0x2U)
#define ECAT_LATCH0_STATUS_BF1_SHIFT             (1U)
/*! BF1 - Event Latch0 negative edge.
 *  0b0..Negative edge not detected or continuous mode
 *  0b1..Negative edge detected in single event mode only
 */
#define ECAT_LATCH0_STATUS_BF1(x)                (((uint8_t)(((uint8_t)(x)) << ECAT_LATCH0_STATUS_BF1_SHIFT)) & ECAT_LATCH0_STATUS_BF1_MASK)

#define ECAT_LATCH0_STATUS_BF2_MASK              (0x4U)
#define ECAT_LATCH0_STATUS_BF2_SHIFT             (2U)
/*! BF2 - Latch0 pin state */
#define ECAT_LATCH0_STATUS_BF2(x)                (((uint8_t)(((uint8_t)(x)) << ECAT_LATCH0_STATUS_BF2_SHIFT)) & ECAT_LATCH0_STATUS_BF2_MASK)

#define ECAT_LATCH0_STATUS_BF3_MASK              (0xF8U)
#define ECAT_LATCH0_STATUS_BF3_SHIFT             (3U)
/*! BF3 - Reserved */
#define ECAT_LATCH0_STATUS_BF3(x)                (((uint8_t)(((uint8_t)(x)) << ECAT_LATCH0_STATUS_BF3_SHIFT)) & ECAT_LATCH0_STATUS_BF3_MASK)
/*! @} */

/*! @name LATCH1_STATUS - Register Latch1 Status */
/*! @{ */

#define ECAT_LATCH1_STATUS_BF0_MASK              (0x1U)
#define ECAT_LATCH1_STATUS_BF0_SHIFT             (0U)
/*! BF0 - Event Latch1 positive edge.
 *  0b0..Positive edge not detected or continuous mode
 *  0b1..Positive edge detected in single event mode only.
 */
#define ECAT_LATCH1_STATUS_BF0(x)                (((uint8_t)(((uint8_t)(x)) << ECAT_LATCH1_STATUS_BF0_SHIFT)) & ECAT_LATCH1_STATUS_BF0_MASK)

#define ECAT_LATCH1_STATUS_BF1_MASK              (0x2U)
#define ECAT_LATCH1_STATUS_BF1_SHIFT             (1U)
/*! BF1 - Event Latch1 negative edge.
 *  0b0..Negative edge not detected or continuous mode
 *  0b1..Negative edge detected in single event mode only.
 */
#define ECAT_LATCH1_STATUS_BF1(x)                (((uint8_t)(((uint8_t)(x)) << ECAT_LATCH1_STATUS_BF1_SHIFT)) & ECAT_LATCH1_STATUS_BF1_MASK)

#define ECAT_LATCH1_STATUS_BF2_MASK              (0x4U)
#define ECAT_LATCH1_STATUS_BF2_SHIFT             (2U)
/*! BF2 - Latch1 pin state */
#define ECAT_LATCH1_STATUS_BF2(x)                (((uint8_t)(((uint8_t)(x)) << ECAT_LATCH1_STATUS_BF2_SHIFT)) & ECAT_LATCH1_STATUS_BF2_MASK)

#define ECAT_LATCH1_STATUS_BF3_MASK              (0xF8U)
#define ECAT_LATCH1_STATUS_BF3_SHIFT             (3U)
/*! BF3 - Reserved */
#define ECAT_LATCH1_STATUS_BF3(x)                (((uint8_t)(((uint8_t)(x)) << ECAT_LATCH1_STATUS_BF3_SHIFT)) & ECAT_LATCH1_STATUS_BF3_MASK)
/*! @} */

/*! @name LATCH0_TIME_POSITIVE_EDGE - Register Latch0 Time Positive Edge */
/*! @{ */

#define ECAT_LATCH0_TIME_POSITIVE_EDGE_BF0_MASK  (0xFFFFFFFFFFFFFFFFU)
#define ECAT_LATCH0_TIME_POSITIVE_EDGE_BF0_SHIFT (0U)
/*! BF0 - System time at the positive edge of the Latch0 signal. */
#define ECAT_LATCH0_TIME_POSITIVE_EDGE_BF0(x)    (((uint64_t)(((uint64_t)(x)) << ECAT_LATCH0_TIME_POSITIVE_EDGE_BF0_SHIFT)) & ECAT_LATCH0_TIME_POSITIVE_EDGE_BF0_MASK)
/*! @} */

/*! @name LATCH0_TIME_NEGATIVE_EDGE - Register Latch0 Time Negative Edge */
/*! @{ */

#define ECAT_LATCH0_TIME_NEGATIVE_EDGE_BF0_MASK  (0xFFFFFFFFFFFFFFFFU)
#define ECAT_LATCH0_TIME_NEGATIVE_EDGE_BF0_SHIFT (0U)
/*! BF0 - System time at the negative edge of the Latch0 signal. */
#define ECAT_LATCH0_TIME_NEGATIVE_EDGE_BF0(x)    (((uint64_t)(((uint64_t)(x)) << ECAT_LATCH0_TIME_NEGATIVE_EDGE_BF0_SHIFT)) & ECAT_LATCH0_TIME_NEGATIVE_EDGE_BF0_MASK)
/*! @} */

/*! @name LATCH1_TIME_POSITIVE_EDGE - Register Latch1 Time Positive Edge */
/*! @{ */

#define ECAT_LATCH1_TIME_POSITIVE_EDGE_BF0_MASK  (0xFFFFFFFFFFFFFFFFU)
#define ECAT_LATCH1_TIME_POSITIVE_EDGE_BF0_SHIFT (0U)
/*! BF0 - System time at the positive edge of the Latch1 signal. */
#define ECAT_LATCH1_TIME_POSITIVE_EDGE_BF0(x)    (((uint64_t)(((uint64_t)(x)) << ECAT_LATCH1_TIME_POSITIVE_EDGE_BF0_SHIFT)) & ECAT_LATCH1_TIME_POSITIVE_EDGE_BF0_MASK)
/*! @} */

/*! @name LATCH1_TIME_NEGATIVE_EDGE - Register Latch1 Time Negative Edge */
/*! @{ */

#define ECAT_LATCH1_TIME_NEGATIVE_EDGE_BF0_MASK  (0xFFFFFFFFFFFFFFFFU)
#define ECAT_LATCH1_TIME_NEGATIVE_EDGE_BF0_SHIFT (0U)
/*! BF0 - System time at the negative edge of the Latch1 signal. */
#define ECAT_LATCH1_TIME_NEGATIVE_EDGE_BF0(x)    (((uint64_t)(((uint64_t)(x)) << ECAT_LATCH1_TIME_NEGATIVE_EDGE_BF0_SHIFT)) & ECAT_LATCH1_TIME_NEGATIVE_EDGE_BF0_MASK)
/*! @} */

/*! @name ETHERCAT_BUFFER_CHANGE_EVENT_TIME - Register EtherCAT Buffer Change Event Time */
/*! @{ */

#define ECAT_ETHERCAT_BUFFER_CHANGE_EVENT_TIME_BF0_MASK (0xFFFFFFFFU)
#define ECAT_ETHERCAT_BUFFER_CHANGE_EVENT_TIME_BF0_SHIFT (0U)
/*! BF0 - Local time at the beginning of the frame which causes at least one SyncManager to assert an ECAT event */
#define ECAT_ETHERCAT_BUFFER_CHANGE_EVENT_TIME_BF0(x) (((uint32_t)(((uint32_t)(x)) << ECAT_ETHERCAT_BUFFER_CHANGE_EVENT_TIME_BF0_SHIFT)) & ECAT_ETHERCAT_BUFFER_CHANGE_EVENT_TIME_BF0_MASK)
/*! @} */

/*! @name PDI_BUFFER_START_EVENT_TIME - Register PDI Buffer Start Event Time */
/*! @{ */

#define ECAT_PDI_BUFFER_START_EVENT_TIME_BF0_MASK (0xFFFFFFFFU)
#define ECAT_PDI_BUFFER_START_EVENT_TIME_BF0_SHIFT (0U)
/*! BF0 - Local time when at least one SyncManager asserts a PDI buffer start event */
#define ECAT_PDI_BUFFER_START_EVENT_TIME_BF0(x)  (((uint32_t)(((uint32_t)(x)) << ECAT_PDI_BUFFER_START_EVENT_TIME_BF0_SHIFT)) & ECAT_PDI_BUFFER_START_EVENT_TIME_BF0_MASK)
/*! @} */

/*! @name PDI_BUFFER_CHANGE_EVENT_TIME - Register PDI Buffer Change Event Time */
/*! @{ */

#define ECAT_PDI_BUFFER_CHANGE_EVENT_TIME_BF0_MASK (0xFFFFFFFFU)
#define ECAT_PDI_BUFFER_CHANGE_EVENT_TIME_BF0_SHIFT (0U)
/*! BF0 - Local time when at least one SyncManager asserts a PDI buffer change event */
#define ECAT_PDI_BUFFER_CHANGE_EVENT_TIME_BF0(x) (((uint32_t)(((uint32_t)(x)) << ECAT_PDI_BUFFER_CHANGE_EVENT_TIME_BF0_SHIFT)) & ECAT_PDI_BUFFER_CHANGE_EVENT_TIME_BF0_MASK)
/*! @} */

/*! @name PRODUCT_ID_IP_CORE - Register Product ID IP Core */
/*! @{ */

#define ECAT_PRODUCT_ID_IP_CORE_BF0_MASK         (0xFFFFFFFFFFFFFFFFU)
#define ECAT_PRODUCT_ID_IP_CORE_BF0_SHIFT        (0U)
/*! BF0 - Product ID */
#define ECAT_PRODUCT_ID_IP_CORE_BF0(x)           (((uint64_t)(((uint64_t)(x)) << ECAT_PRODUCT_ID_IP_CORE_BF0_SHIFT)) & ECAT_PRODUCT_ID_IP_CORE_BF0_MASK)
/*! @} */

/*! @name VENDOR_ID_IP_CORE - Register Vendor ID IP Core */
/*! @{ */

#define ECAT_VENDOR_ID_IP_CORE_BF0_MASK          (0xFFFFFFFFU)
#define ECAT_VENDOR_ID_IP_CORE_BF0_SHIFT         (0U)
/*! BF0 - Vendor ID */
#define ECAT_VENDOR_ID_IP_CORE_BF0(x)            (((uint64_t)(((uint64_t)(x)) << ECAT_VENDOR_ID_IP_CORE_BF0_SHIFT)) & ECAT_VENDOR_ID_IP_CORE_BF0_MASK)

#define ECAT_VENDOR_ID_IP_CORE_BF32_MASK         (0xFFFFFFFF00000000U)
#define ECAT_VENDOR_ID_IP_CORE_BF32_SHIFT        (32U)
/*! BF32 - Reserved */
#define ECAT_VENDOR_ID_IP_CORE_BF32(x)           (((uint64_t)(((uint64_t)(x)) << ECAT_VENDOR_ID_IP_CORE_BF32_SHIFT)) & ECAT_VENDOR_ID_IP_CORE_BF32_MASK)
/*! @} */

/*! @name GENERAL_PURPOSE_OUTPUTS - Register General Purpose Outputs */
/*! @{ */

#define ECAT_GENERAL_PURPOSE_OUTPUTS_BF0_MASK    (0xFFFFU)
#define ECAT_GENERAL_PURPOSE_OUTPUTS_BF0_SHIFT   (0U)
/*! BF0 - General Purpose Output Data */
#define ECAT_GENERAL_PURPOSE_OUTPUTS_BF0(x)      (((uint16_t)(((uint16_t)(x)) << ECAT_GENERAL_PURPOSE_OUTPUTS_BF0_SHIFT)) & ECAT_GENERAL_PURPOSE_OUTPUTS_BF0_MASK)
/*! @} */

/*! @name GENERAL_PURPOSE_INPUTS - Register General Purpose Inputs */
/*! @{ */

#define ECAT_GENERAL_PURPOSE_INPUTS_BF0_MASK     (0xFFFFU)
#define ECAT_GENERAL_PURPOSE_INPUTS_BF0_SHIFT    (0U)
/*! BF0 - General Purpose Input Data */
#define ECAT_GENERAL_PURPOSE_INPUTS_BF0(x)       (((uint16_t)(((uint16_t)(x)) << ECAT_GENERAL_PURPOSE_INPUTS_BF0_SHIFT)) & ECAT_GENERAL_PURPOSE_INPUTS_BF0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ECAT_Register_Masks */


/*!
 * @}
 */ /* end of group ECAT_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_ECAT_H_ */

