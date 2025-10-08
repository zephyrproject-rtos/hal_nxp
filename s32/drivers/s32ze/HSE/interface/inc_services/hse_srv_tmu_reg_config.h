/**
*   @file    hse_srv_tmu_reg_config.h
*
*   @brief   HSE Temperature Sensor service definition.
*   @details This file contains the temperature sensor service definition.
*
*   @addtogroup hse_srv_tmu_reg_config HSE Temperature Sensor service
*   @ingroup class_admin_services
*   @{
*/
/*==================================================================================================
*
*   Copyright 2022-2024 NXP
*
*   Redistribution and use in source and binary forms, with or without modification,
*   are permitted provided that the following conditions are met:
*
*   1. Redistributions of source code must retain the above copyright notice, this list
*      of conditions and the following disclaimer.
*
*   2. Redistributions in binary form must reproduce the above copyright notice, this
*      list of conditions and the following disclaimer in the documentation and/or
*      other materials provided with the distribution.
*
*   3. Neither the name of the copyright holder nor the names of its
*      contributors may be used to endorse or promote products derived from this
*      software without specific prior written permission.
*
*   This software is owned or controlled by NXP and may only be used strictly in accordance with
*   the applicable license terms. By expressly accepting such terms or by downloading, installing,
*   activating and/or otherwise using the software, you are agreeing that you have read, and that
*   you agree to comply with and are bound by, such license terms. If you do not agree to
*   be bound by the applicable license terms, then you may not retain, install, activate or
*   otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef HSE_SRV_TMU_REG_CONFIG_H
#define HSE_SRV_TMU_REG_CONFIG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "hse_common_types.h"

#define HSE_START_PRAGMA_PACK
#include "hse_compiler_abs.h"

#ifdef HSE_SPT_TMU_REG_CONFIG
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @brief  HSE TMU register operations. The operations are equivalent with the below macros:
 *  \code
 *      #define REG_WRITE32(address, value)       ((*(volatile uint32 *)(address)) = (value))
 *      #define REG_BIT_SET32(address, mask)      ((*(volatile uint32 *)(address)) |= (mask))
 *      #define REG_BIT_CLEAR32(address, mask)    ((*(volatile uint32 *)(address)) &= (~(mask)))
 *      #define REG_RMW32(address, mask, value)   (REG_WRITE32((address), ((REG_READ32(address) & ((uint32_t) ~ (mask))) | ((value) & (mask)))))
 *  \endcode
 */
typedef uint16_t hseTmuRegOp_t;
#define HSE_TMU_REG_WRITE32            ((hseTmuRegOp_t)3U << 0U)   /**< @brief Register write (32 bits) */
#define HSE_TMU_REG_BIT_SET32          ((hseTmuRegOp_t)3U << 2U)   /**< @brief Bits setting (32 bits) */
#define HSE_TMU_REG_BIT_CLEAR32        ((hseTmuRegOp_t)3U << 4U)   /**< @brief Bits clearing (32 bits) */
#define HSE_TMU_REG_RMW32              ((hseTmuRegOp_t)3U << 6U)   /**< @brief Clear bits and set with new value (Read-Modify-Write 32 bits) */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief        TMU Register Configuration service.
* @details      The TMU service performs different operations on TMU registers (see #hseTmuRegOp_t).
*               The registers from the table below can be modified.
*
*  @note 
*  Temperature calculation formula:
*  - SAF85XX: -42C <---> +152C
*      - for Temp < 0,  Lower Threshold  =  Temp_DegC * 64 + 2^16
*      - for Temp > 0,  Higher Threshold =  Temp_DegC * 64 <br>
*  Lower  Threshold : -42C * 64 + 2^16    = F580h <br>
*  Higher Threshold : 152C * 64           = 2600h
*
*  - S32R41: -45C <---> +155C <br>
*  Lower  Threshold : -45C + 273Kelvin    = E4h <br>
*  Higher Threshold : 155C + 273Kelvin    = 1ACh
*
*  |Register Name     | Reg Addr   |                                    Remark                                                                                              |
*  |-----------------:|:----------:|:--------------------------------------------------------------------------------------------------------------------------------------:|
*  | TMR              | 0x4008C000 |   Allowed OP: HSE_TMU_REG_WRITE32; <br> Changeable bits: bit[25,24] (the rest of the bit are ignored)                                  |
*  | TSR              | 0x4008C004 |   NA                                                                                                                                   |
*  | TIER             | 0x4008C020 |   Allowed OP: HSE_TMU_REG_WRITE32; <br> Changeable bits: bit[31,30], [28,27], [25,24] (the rest of the bit are ignored)                |
*  | TIDR             | 0x4008C024 |   NA                                                                                                                                   |
*  | TIISCR           | 0x4008C030 |   NA                                                                                                                                   |
*  | TIASCR           | 0x4008C034 |   NA                                                                                                                                   |
*  | TMHTCR           | 0x4008C040 |   NA                                                                                                                                   |
*  | TMLTCR           | 0x4008C044 |   NA                                                                                                                                   |
*  | TMRTRCR          | 0x4008C048 |   NA                                                                                                                                   |
*  | TMFTRCR          | 0x4008C04C |   NA                                                                                                                                   |
*  | TMHTITR          | 0x4008C050 |   NA                                                                                                                                   |
*  | TMHTATR          | 0x4008C054 |   NA                                                                                                                                   |
*  | TMHTACTR         | 0x4008C058 |  Allowed OP: HSE_TMU_REG_WRITE32; <br> SAF85XX: Min: F580h(-42C), Max: 2600h(152C), bit[0,15]; <br> S32R41: Min: E4h  (-45C), Max: 1ACh (155C), bit[0,8]; <br> (the rest of the bit are ignored)   |
*  | TMLTITR          | 0x4008C060 |   NA                                                                                                                                   |
*  | TMLTATR          | 0x4008C064 |   NA                                                                                                                                   |
*  | TMLTACTR         | 0x4008C068 |  Allowed OP: HSE_TMU_REG_WRITE32; <br> SAF85XX: Min: F580h(-42C), Max: 2600h(152C), bit[0,15]; <br> S32R41: Min: E4h  (-45C), Max: 1ACh (155C), bit[0,8]; <br> (the rest of the bit are ignored)   |
*  | TMRTRCTR         | 0x4008C070 |  Allowed OP: HSE_TMU_REG_WRITE32                                                                                                       |
*  | TMFTRCTR         | 0x4008C074 |  Allowed OP: HSE_TMU_REG_WRITE32                                                                                                       |
*  | TMCFG0R          | 0x4008C400 |  Only Valid for SAF85XX; <br> Allowed OP : HSE_TMU_REG_WRITE32; <br> Changeable bits: bit[0,1] (the rest of the bit are ignored)       |
*  | TTCFGR           | 0x4008C080 |  Only Valid for HSE_S32R41X; <br> Allowed OP : HSE_TMU_REG_WRITE32; <br> Changeable bits: [0,3] (the rest of the bit are ignored)   
*/
typedef struct
{
    /** @brief     INPUT: Specify the Tmu register operations (see #hseTmuRegOp_t). */
    hseTmuRegOp_t  hseTmuRegOp;
    uint8_t        reserved[2U];
    /** @brief     INPUT: The TMU register address . */
    uint32_t       regAddr;
    /** @brief     INPUT: The mask use for the operation. This parameter is ignored for #HSE_TMU_REG_WRITE32 operation.*/
    uint32_t       mask;
    /** @brief     INPUT: The value use for the operation. This parameter is ignored for #HSE_TMU_REG_BIT_SET32 and #HSE_TMU_REG_BIT_CLEAR32 operations.*/
    uint32_t       value;
} hseTmuRegConfigSrv_t;

#endif /*HSE_SPT_TMU_REG_CONFIG */
/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define HSE_STOP_PRAGMA_PACK
#include "hse_compiler_abs.h"

#ifdef __cplusplus
}
#endif

#endif /* HSE_SRV_TMU_REG_CONFIG_H */

/** @} */
