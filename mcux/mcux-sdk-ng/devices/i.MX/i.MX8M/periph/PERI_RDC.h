/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RDC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_RDC.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RDC
 *
 * CMSIS Peripheral Access Layer for RDC
 */

#if !defined(PERI_RDC_H_)
#define PERI_RDC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
#if !defined(RDC_MASTER_T_)
#define RDC_MASTER_T_
/*!
 * @addtogroup rdc_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the RDC mapping
 *
 * Defines the structure for the RDC resource collections.
 */

typedef enum _rdc_master
{
    kRDC_Master_A53                 = 0U,          /**< ARM Cortex-A53 RDC Master */
    kRDC_Master_M4                  = 1U,          /**< ARM Cortex-M4 RDC Master */
    kRDC_Master_PCIE1               = 2U,          /**< PCIE1 RDC Master */
    kRDC_Master_PCIE2               = 3U,          /**< PCIE2 RDC Master */
    kRDC_Master_VPU                 = 4U,          /**< VPU RDC Master */
    kRDC_Master_LCDIF               = 5U,          /**< LCDIF RDC Master */
    kRDC_Master_CSI1                = 6U,          /**< CSI1 PORT RDC Master */
    kRDC_Master_CSI2                = 7U,          /**< CSI2 RDC Master */
    kRDC_Master_Coresight           = 8U,          /**< CORESIGHT RDC Master */
    kRDC_Master_DAP                 = 9U,          /**< DAP RDC Master */
    kRDC_Master_CAAM                = 10U,         /**< CAAM RDC Master */
    kRDC_Master_SDMA1_PERIPH        = 11U,         /**< SDMA1 PERIPHERAL RDC Master */
    kRDC_Master_SDMA1_BURST         = 12U,         /**< SDMA1 BURST RDC Master */
    kRDC_Master_APBHDMA             = 13U,         /**< APBH DMA RDC Master */
    kRDC_Master_RAWNAND             = 14U,         /**< RAW NAND RDC Master */
    kRDC_Master_USDHC1              = 15U,         /**< USDHC1 RDC Master */
    kRDC_Master_USDHC2              = 16U,         /**< USDHC2 RDC Master */
    kRDC_Master_DP                  = 17U,         /**< DP RDC Master */
    kRDC_Master_GPU                 = 18U,         /**< GPU RDC Master */
    kRDC_Master_USB1                = 19U,         /**< USB1 RDC Master */
    kRDC_Master_USB2                = 20U,         /**< USB2 RDC Master */
    kRDC_Master_TESTPORT            = 21U,         /**< TESTPORT RDC Master */
    kRDC_Master_ENET1TX             = 22U,         /**< ENET1 TX RDC Master */
    kRDC_Master_ENET1RX             = 23U,         /**< ENET1 RX RDC Master */
    kRDC_Master_SDMA2_PERIPH        = 24U,         /**< SDMA2 PERIPH RDC Master */
    kRDC_Master_SDMA2_BURST         = 24U,         /**< SDMA2 BURST RDC Master */
    kRDC_Master_SDMA2_SPDA2         = 24U,         /**< SDMA2 to SPDA2 RDC Master */
    kRDC_Master_SDMA1_SPBA1         = 26U,         /**< SDMA1 to SPBA1 RDC Master */
} rdc_master_t;
#endif /* RDC_MASTER_T_ */

#if !defined(RDC_MEM_T_)
#define RDC_MEM_T_
typedef enum _rdc_mem
{
    kRDC_Mem_MRC0_0                 = 0U,          /**< MMDC/DRAM. Region resolution 4KB. */
    kRDC_Mem_MRC0_1                 = 1U,
    kRDC_Mem_MRC0_2                 = 2U,
    kRDC_Mem_MRC0_3                 = 3U,
    kRDC_Mem_MRC0_4                 = 4U,
    kRDC_Mem_MRC0_5                 = 5U,
    kRDC_Mem_MRC0_6                 = 6U,
    kRDC_Mem_MRC0_7                 = 7U,
    kRDC_Mem_MRC1_0                 = 8U,          /**< PCIE2. Region resolution 4KB. */
    kRDC_Mem_MRC1_1                 = 9U,
    kRDC_Mem_MRC1_2                 = 10U,
    kRDC_Mem_MRC1_3                 = 11U,
    kRDC_Mem_MRC2_0                 = 12U,         /**< QSPI. Region resolution 4KB. */
    kRDC_Mem_MRC2_1                 = 13U,
    kRDC_Mem_MRC2_2                 = 14U,
    kRDC_Mem_MRC2_3                 = 15U,
    kRDC_Mem_MRC2_4                 = 16U,
    kRDC_Mem_MRC2_5                 = 17U,
    kRDC_Mem_MRC2_6                 = 18U,
    kRDC_Mem_MRC2_7                 = 19U,
    kRDC_Mem_MRC3_0                 = 20U,         /**< PCIE1. Region resolution 4KB. */
    kRDC_Mem_MRC3_1                 = 21U,
    kRDC_Mem_MRC3_2                 = 22U,
    kRDC_Mem_MRC3_3                 = 23U,
    kRDC_Mem_MRC4_0                 = 24U,         /**< OCRAM. Region resolution 128B. */
    kRDC_Mem_MRC4_1                 = 25U,
    kRDC_Mem_MRC4_2                 = 26U,
    kRDC_Mem_MRC4_3                 = 27U,
    kRDC_Mem_MRC4_4                 = 28U,
    kRDC_Mem_MRC5_0                 = 29U,         /**< OCRAM_S. Region resolution 128B. */
    kRDC_Mem_MRC5_1                 = 30U,
    kRDC_Mem_MRC5_2                 = 31U,
    kRDC_Mem_MRC5_3                 = 32U,
    kRDC_Mem_MRC5_4                 = 33U,
    kRDC_Mem_MRC6_0                 = 34U,         /**< TCM. Region resolution 128B. */
    kRDC_Mem_MRC6_1                 = 35U,
    kRDC_Mem_MRC6_2                 = 36U,
    kRDC_Mem_MRC6_3                 = 37U,
    kRDC_Mem_MRC6_4                 = 38U,
    kRDC_Mem_MRC7_0                 = 39U,         /**< GIC. Region resolution 4KB. */
    kRDC_Mem_MRC7_1                 = 40U,
    kRDC_Mem_MRC7_2                 = 41U,
    kRDC_Mem_MRC7_3                 = 42U,
    kRDC_Mem_MRC8_0                 = 43U,         /**< USBMIX. Region resolution 4KB. */
    kRDC_Mem_MRC8_1                 = 44U,
    kRDC_Mem_MRC8_2                 = 45U,
    kRDC_Mem_MRC8_3                 = 46U,
    kRDC_Mem_MRC9_0                 = 47U,         /**< GPU. Region resolution 4KB. */
    kRDC_Mem_MRC9_1                 = 48U,
    kRDC_Mem_MRC9_2                 = 49U,
    kRDC_Mem_MRC9_3                 = 50U,
    kRDC_Mem_MRC10_0                = 51U,         /**< VPU(Decoder). Region resolution 4KB. */
    kRDC_Mem_MRC10_1                = 52U,
    kRDC_Mem_MRC10_2                = 53U,
    kRDC_Mem_MRC10_3                = 54U,
    kRDC_Mem_MRC11_0                = 55U,         /**< DEBUG(DAP). Region resolution 4KB. */
    kRDC_Mem_MRC11_1                = 56U,
    kRDC_Mem_MRC11_2                = 57U,
    kRDC_Mem_MRC11_3                = 58U,
    kRDC_Mem_MRC12_0                = 59U,         /**< DDRC(REG). Region resolution 4KB. */
    kRDC_Mem_MRC12_1                = 60U,
    kRDC_Mem_MRC12_2                = 61U,
    kRDC_Mem_MRC12_3                = 62U,
    kRDC_Mem_MRC12_4                = 63U,
} rdc_mem_t;
#endif /* RDC_MEM_T_ */

#if !defined(RDC_PERIPH_T_)
#define RDC_PERIPH_T_
typedef enum _rdc_periph
{
    kRDC_Periph_GPIO1               = 0U,          /**< GPIO1 RDC Peripheral */
    kRDC_Periph_GPIO2               = 1U,          /**< GPIO2 RDC Peripheral */
    kRDC_Periph_GPIO3               = 2U,          /**< GPIO3 RDC Peripheral */
    kRDC_Periph_GPIO4               = 3U,          /**< GPIO4 RDC Peripheral */
    kRDC_Periph_GPIO5               = 4U,          /**< GPIO5 RDC Peripheral */
    kRDC_Periph_ANA_TSENSOR         = 6U,          /**< ANA_TSENSOR RDC Peripheral */
    kRDC_Periph_ANA_OSC             = 7U,          /**< ANA_OSC RDC Peripheral */
    kRDC_Periph_WDOG1               = 8U,          /**< WDOG1 RDC Peripheral */
    kRDC_Periph_WDOG2               = 9U,          /**< WDOG2 RDC Peripheral */
    kRDC_Periph_WDOG3               = 10U,         /**< WDOG3 RDC Peripheral */
    kRDC_Periph_SDMA2               = 12U,         /**< SDMA2 RDC Peripheral */
    kRDC_Periph_GPT1                = 13U,         /**< GPT1 RDC Peripheral */
    kRDC_Periph_GPT2                = 14U,         /**< GPT2 RDC Peripheral */
    kRDC_Periph_GPT3                = 15U,         /**< GPT3 RDC Peripheral */
    kRDC_Periph_ROMCP               = 17U,         /**< ROMCP RDC Peripheral */
    kRDC_Periph_LCDIF               = 18U,         /**< LCDIF RDC Peripheral */
    kRDC_Periph_IOMUXC              = 19U,         /**< IOMUXC RDC Peripheral */
    kRDC_Periph_IOMUXC_GPR          = 20U,         /**< IOMUXC_GPR RDC Peripheral */
    kRDC_Periph_OCOTP_CTRL          = 21U,         /**< OCOTP_CTRL RDC Peripheral */
    kRDC_Periph_ANA_PLL             = 22U,         /**< ANA_PLL RDC Peripheral */
    kRDC_Periph_SNVS_HP             = 23U,         /**< SNVS_HP GPR RDC Peripheral */
    kRDC_Periph_CCM                 = 24U,         /**< CCM RDC Peripheral */
    kRDC_Periph_SRC                 = 25U,         /**< SRC RDC Peripheral */
    kRDC_Periph_GPC                 = 26U,         /**< GPC RDC Peripheral */
    kRDC_Periph_SEMAPHORE1          = 27U,         /**< SEMAPHORE1 RDC Peripheral */
    kRDC_Periph_SEMAPHORE2          = 28U,         /**< SEMAPHORE2 RDC Peripheral */
    kRDC_Periph_RDC                 = 29U,         /**< RDC RDC Peripheral */
    kRDC_Periph_CSU                 = 30U,         /**< CSU RDC Peripheral */
    kRDC_Periph_DC_MST0             = 32U,         /**< DC_MST0 RDC Peripheral */
    kRDC_Periph_DC_MST1             = 33U,         /**< DC_MST1 RDC Peripheral */
    kRDC_Periph_DC_MST2             = 34U,         /**< DC_MST2 RDC Peripheral */
    kRDC_Periph_DC_MST3             = 35U,         /**< DC_MST3 RDC Peripheral */
    kRDC_Periph_HDMI_SEC            = 36U,         /**< HDMI_SEC RDC Peripheral */
    kRDC_Periph_PWM1                = 38U,         /**< PWM1 RDC Peripheral */
    kRDC_Periph_PWM2                = 39U,         /**< PWM2 RDC Peripheral */
    kRDC_Periph_PWM3                = 40U,         /**< PWM3 RDC Peripheral */
    kRDC_Periph_PWM4                = 41U,         /**< PWM4 RDC Peripheral */
    kRDC_Periph_SYS_COUNTER_RD      = 42U,         /**< System counter read RDC Peripheral */
    kRDC_Periph_SYS_COUNTER_CMP     = 43U,         /**< System counter compare RDC Peripheral */
    kRDC_Periph_SYS_COUNTER_CTRL    = 44U,         /**< System counter control RDC Peripheral */
    kRDC_Periph_HDMI_CTRL           = 45U,         /**< HDMI_CTRL RDC Peripheral */
    kRDC_Periph_GPT6                = 46U,         /**< GPT6 RDC Peripheral */
    kRDC_Periph_GPT5                = 47U,         /**< GPT5 RDC Peripheral */
    kRDC_Periph_GPT4                = 48U,         /**< GPT4 RDC Peripheral */
    kRDC_Periph_TZASC               = 56U,         /**< TZASC RDC Peripheral */
    kRDC_Periph_MTR                 = 59U,         /**< MTR RDC Peripheral */
    kRDC_Periph_PERFMON1            = 60U,         /**< PERFMON1 RDC Peripheral */
    kRDC_Periph_PERFMON2            = 61U,         /**< PERFMON2 RDC Peripheral */
    kRDC_Periph_PLATFORM_CTRL       = 62U,         /**< PLATFORM_CTRL RDC Peripheral */
    kRDC_Periph_QOSC                = 63U,         /**< QOSC RDC Peripheral */
    kRDC_Periph_MIPI_PHY            = 64U,         /**< MIPI_PHY RDC Peripheral */
    kRDC_Periph_MIPI_DSI            = 65U,         /**< MIPI_DSI RDC Peripheral */
    kRDC_Periph_I2C1                = 66U,         /**< I2C1 RDC Peripheral */
    kRDC_Periph_I2C2                = 67U,         /**< I2C2 RDC Peripheral */
    kRDC_Periph_I2C3                = 68U,         /**< I2C3 RDC Peripheral */
    kRDC_Periph_I2C4                = 69U,         /**< I2C4 RDC Peripheral */
    kRDC_Periph_UART4               = 70U,         /**< UART4 RDC Peripheral */
    kRDC_Periph_MIPI_CSI1           = 71U,         /**< MIPI_CSI1 RDC Peripheral */
    kRDC_Periph_MIPI_CSI_PHY1       = 72U,         /**< MIPI_CSI_PHY1 RDC Peripheral */
    kRDC_Periph_CSI1                = 73U,         /**< CSI1 RDC Peripheral */
    kRDC_Periph_MU_A                = 74U,         /**< MU_A RDC Peripheral */
    kRDC_Periph_MU_B                = 75U,         /**< MU_B RDC Peripheral */
    kRDC_Periph_SEMAPHORE_HS        = 76U,         /**< SEMAPHORE_HS RDC Peripheral */
    kRDC_Periph_SAI1                = 78U,         /**< SAI1 RDC Peripheral */
    kRDC_Periph_SAI6                = 80U,         /**< SAI6 RDC Peripheral */
    kRDC_Periph_SAI5                = 81U,         /**< SAI5 RDC Peripheral */
    kRDC_Periph_SAI4                = 82U,         /**< SAI4 RDC Peripheral */
    kRDC_Periph_USDHC1              = 84U,         /**< USDHC1 RDC Peripheral */
    kRDC_Periph_USDHC2              = 85U,         /**< USDHC2 RDC Peripheral */
    kRDC_Periph_MIPI_CSI2           = 86U,         /**< MIPI_CSI2 RDC Peripheral */
    kRDC_Periph_MIPI_CSI_PHY2       = 87U,         /**< MIPI_CSI_PHY2 RDC Peripheral */
    kRDC_Periph_CSI2                = 88U,         /**< CSI2 RDC Peripheral */
    kRDC_Periph_SPBA2               = 90U,         /**< SPBA2 RDC Peripheral */
    kRDC_Periph_QSPI                = 91U,         /**< QSPI RDC Peripheral */
    kRDC_Periph_SDMA1               = 93U,         /**< SDMA1 RDC Peripheral */
    kRDC_Periph_ENET1               = 94U,         /**< ENET1 RDC Peripheral */
    kRDC_Periph_SPDIF1              = 97U,         /**< SPDIF1 RDC Peripheral */
    kRDC_Periph_ECSPI1              = 98U,         /**< ECSPI1 RDC Peripheral */
    kRDC_Periph_ECSPI2              = 99U,         /**< ECSPI2 RDC Peripheral */
    kRDC_Periph_ECSPI3              = 100U,        /**< ECSPI3 RDC Peripheral */
    kRDC_Periph_UART1               = 102U,        /**< UART1 RDC Peripheral */
    kRDC_Periph_UART3               = 104U,        /**< UART3 RDC Peripheral */
    kRDC_Periph_UART2               = 105U,        /**< UART2 RDC Peripheral */
    kRDC_Periph_SPDIF2              = 106U,        /**< SPDIF2 RDC Peripheral */
    kRDC_Periph_SAI2                = 107U,        /**< SAI2 RDC Peripheral */
    kRDC_Periph_SAI3                = 108U,        /**< SAI3 RDC Peripheral */
    kRDC_Periph_SPBA1               = 111U,        /**< SPBA1 RDC Peripheral */
    kRDC_Periph_CAAM                = 114U,        /**< CAAM RDC Peripheral */
} rdc_periph_t;

/* @} */
#endif /* RDC_PERIPH_T_ */


/*!
 * @}
 */ /* end of group Mapping_Information */


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
   -- RDC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RDC_Peripheral_Access_Layer RDC Peripheral Access Layer
 * @{
 */

/** RDC - Size of Registers Arrays */
#define RDC_MDA_COUNT                             27u
#define RDC_PDAP_COUNT                            118u
#define RDC_MR_COUNT                              52u

/** RDC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VIR;                               /**< Version Information, offset: 0x0 */
       uint8_t RESERVED_0[32];
  __IO uint32_t STAT;                              /**< Status, offset: 0x24 */
  __IO uint32_t INTCTRL;                           /**< Interrupt and Control, offset: 0x28 */
  __IO uint32_t INTSTAT;                           /**< Interrupt Status, offset: 0x2C */
       uint8_t RESERVED_1[464];
  __IO uint32_t MDA[RDC_MDA_COUNT];                /**< Master Domain Assignment, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_2[404];
  __IO uint32_t PDAP[RDC_PDAP_COUNT];              /**< Peripheral Domain Access Permissions, array offset: 0x400, array step: 0x4 */
       uint8_t RESERVED_3[552];
  struct {                                         /* offset: 0x800, array step: 0x10 */
    __IO uint32_t MRSA;                              /**< Memory Region Start Address, array offset: 0x800, array step: 0x10 */
    __IO uint32_t MREA;                              /**< Memory Region End Address, array offset: 0x804, array step: 0x10 */
    __IO uint32_t MRC;                               /**< Memory Region Control, array offset: 0x808, array step: 0x10 */
    __IO uint32_t MRVS;                              /**< Memory Region Violation Status, array offset: 0x80C, array step: 0x10 */
  } MR[RDC_MR_COUNT];
} RDC_Type;

/* ----------------------------------------------------------------------------
   -- RDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RDC_Register_Masks RDC Register Masks
 * @{
 */

/*! @name VIR - Version Information */
/*! @{ */

#define RDC_VIR_NDID_MASK                        (0xFU)
#define RDC_VIR_NDID_SHIFT                       (0U)
/*! NDID - Number of Domains */
#define RDC_VIR_NDID(x)                          (((uint32_t)(((uint32_t)(x)) << RDC_VIR_NDID_SHIFT)) & RDC_VIR_NDID_MASK)

#define RDC_VIR_NMSTR_MASK                       (0xFF0U)
#define RDC_VIR_NMSTR_SHIFT                      (4U)
/*! NMSTR - Number of Masters */
#define RDC_VIR_NMSTR(x)                         (((uint32_t)(((uint32_t)(x)) << RDC_VIR_NMSTR_SHIFT)) & RDC_VIR_NMSTR_MASK)

#define RDC_VIR_NPER_MASK                        (0xFF000U)
#define RDC_VIR_NPER_SHIFT                       (12U)
/*! NPER - Number of Peripherals */
#define RDC_VIR_NPER(x)                          (((uint32_t)(((uint32_t)(x)) << RDC_VIR_NPER_SHIFT)) & RDC_VIR_NPER_MASK)

#define RDC_VIR_NRGN_MASK                        (0xFF00000U)
#define RDC_VIR_NRGN_SHIFT                       (20U)
/*! NRGN - Number of Memory Regions */
#define RDC_VIR_NRGN(x)                          (((uint32_t)(((uint32_t)(x)) << RDC_VIR_NRGN_SHIFT)) & RDC_VIR_NRGN_MASK)
/*! @} */

/*! @name STAT - Status */
/*! @{ */

#define RDC_STAT_DID_MASK                        (0xFU)
#define RDC_STAT_DID_SHIFT                       (0U)
/*! DID - Domain ID */
#define RDC_STAT_DID(x)                          (((uint32_t)(((uint32_t)(x)) << RDC_STAT_DID_SHIFT)) & RDC_STAT_DID_MASK)

#define RDC_STAT_PDS_MASK                        (0x100U)
#define RDC_STAT_PDS_SHIFT                       (8U)
/*! PDS - Power Domain Status
 *  0b0..Power Down Domain is OFF
 *  0b1..Power Down Domain is ON
 */
#define RDC_STAT_PDS(x)                          (((uint32_t)(((uint32_t)(x)) << RDC_STAT_PDS_SHIFT)) & RDC_STAT_PDS_MASK)
/*! @} */

/*! @name INTCTRL - Interrupt and Control */
/*! @{ */

#define RDC_INTCTRL_RCI_EN_MASK                  (0x1U)
#define RDC_INTCTRL_RCI_EN_SHIFT                 (0U)
/*! RCI_EN - Restoration Complete Interrupt
 *  0b0..Interrupt Disabled
 *  0b1..Interrupt Enabled
 */
#define RDC_INTCTRL_RCI_EN(x)                    (((uint32_t)(((uint32_t)(x)) << RDC_INTCTRL_RCI_EN_SHIFT)) & RDC_INTCTRL_RCI_EN_MASK)
/*! @} */

/*! @name INTSTAT - Interrupt Status */
/*! @{ */

#define RDC_INTSTAT_INT_MASK                     (0x1U)
#define RDC_INTSTAT_INT_SHIFT                    (0U)
/*! INT - Interrupt Status
 *  0b0..No Interrupt Pending
 *  0b1..Interrupt Pending
 */
#define RDC_INTSTAT_INT(x)                       (((uint32_t)(((uint32_t)(x)) << RDC_INTSTAT_INT_SHIFT)) & RDC_INTSTAT_INT_MASK)
/*! @} */

/*! @name MDA - Master Domain Assignment */
/*! @{ */

#define RDC_MDA_DID_MASK                         (0x3U)
#define RDC_MDA_DID_SHIFT                        (0U)
/*! DID - Domain ID
 *  0b00..Master assigned to Processing Domain 0
 *  0b01..Master assigned to Processing Domain 1
 *  0b10..Master assigned to Processing Domain 2
 *  0b11..Master assigned to Processing Domain 3
 */
#define RDC_MDA_DID(x)                           (((uint32_t)(((uint32_t)(x)) << RDC_MDA_DID_SHIFT)) & RDC_MDA_DID_MASK)

#define RDC_MDA_LCK_MASK                         (0x80000000U)
#define RDC_MDA_LCK_SHIFT                        (31U)
/*! LCK
 *  0b0..Not Locked
 *  0b1..Locked
 */
#define RDC_MDA_LCK(x)                           (((uint32_t)(((uint32_t)(x)) << RDC_MDA_LCK_SHIFT)) & RDC_MDA_LCK_MASK)
/*! @} */

/*! @name PDAP - Peripheral Domain Access Permissions */
/*! @{ */

#define RDC_PDAP_D0W_MASK                        (0x1U)
#define RDC_PDAP_D0W_SHIFT                       (0U)
/*! D0W - Domain 0 Write Access
 *  0b0..No Write Access
 *  0b1..Write Access Allowed
 */
#define RDC_PDAP_D0W(x)                          (((uint32_t)(((uint32_t)(x)) << RDC_PDAP_D0W_SHIFT)) & RDC_PDAP_D0W_MASK)

#define RDC_PDAP_D0R_MASK                        (0x2U)
#define RDC_PDAP_D0R_SHIFT                       (1U)
/*! D0R - Domain 0 Read Access
 *  0b0..No Read Access
 *  0b1..Read Access Allowed
 */
#define RDC_PDAP_D0R(x)                          (((uint32_t)(((uint32_t)(x)) << RDC_PDAP_D0R_SHIFT)) & RDC_PDAP_D0R_MASK)

#define RDC_PDAP_D1W_MASK                        (0x4U)
#define RDC_PDAP_D1W_SHIFT                       (2U)
/*! D1W - Domain 1 Write Access
 *  0b0..No Write Access
 *  0b1..Write Access Allowed
 */
#define RDC_PDAP_D1W(x)                          (((uint32_t)(((uint32_t)(x)) << RDC_PDAP_D1W_SHIFT)) & RDC_PDAP_D1W_MASK)

#define RDC_PDAP_D1R_MASK                        (0x8U)
#define RDC_PDAP_D1R_SHIFT                       (3U)
/*! D1R - Domain 1 Read Access
 *  0b0..No Read Access
 *  0b1..Read Access Allowed
 */
#define RDC_PDAP_D1R(x)                          (((uint32_t)(((uint32_t)(x)) << RDC_PDAP_D1R_SHIFT)) & RDC_PDAP_D1R_MASK)

#define RDC_PDAP_D2W_MASK                        (0x10U)
#define RDC_PDAP_D2W_SHIFT                       (4U)
/*! D2W - Domain 2 Write Access
 *  0b0..No Write Access
 *  0b1..Write Access Allowed
 */
#define RDC_PDAP_D2W(x)                          (((uint32_t)(((uint32_t)(x)) << RDC_PDAP_D2W_SHIFT)) & RDC_PDAP_D2W_MASK)

#define RDC_PDAP_D2R_MASK                        (0x20U)
#define RDC_PDAP_D2R_SHIFT                       (5U)
/*! D2R - Domain 2 Read Access
 *  0b0..No Read Access
 *  0b1..Read Access Allowed
 */
#define RDC_PDAP_D2R(x)                          (((uint32_t)(((uint32_t)(x)) << RDC_PDAP_D2R_SHIFT)) & RDC_PDAP_D2R_MASK)

#define RDC_PDAP_D3W_MASK                        (0x40U)
#define RDC_PDAP_D3W_SHIFT                       (6U)
/*! D3W - Domain 3 Write Access
 *  0b0..No Write Access
 *  0b1..Write Access Allowed
 */
#define RDC_PDAP_D3W(x)                          (((uint32_t)(((uint32_t)(x)) << RDC_PDAP_D3W_SHIFT)) & RDC_PDAP_D3W_MASK)

#define RDC_PDAP_D3R_MASK                        (0x80U)
#define RDC_PDAP_D3R_SHIFT                       (7U)
/*! D3R - Domain 3 Read Access
 *  0b0..No Read Access
 *  0b1..Read Access Allowed
 */
#define RDC_PDAP_D3R(x)                          (((uint32_t)(((uint32_t)(x)) << RDC_PDAP_D3R_SHIFT)) & RDC_PDAP_D3R_MASK)

#define RDC_PDAP_SREQ_MASK                       (0x40000000U)
#define RDC_PDAP_SREQ_SHIFT                      (30U)
/*! SREQ - Semaphore Required
 *  0b0..Semaphores have no effect
 *  0b1..Semaphores are enforced
 */
#define RDC_PDAP_SREQ(x)                         (((uint32_t)(((uint32_t)(x)) << RDC_PDAP_SREQ_SHIFT)) & RDC_PDAP_SREQ_MASK)

#define RDC_PDAP_LCK_MASK                        (0x80000000U)
#define RDC_PDAP_LCK_SHIFT                       (31U)
/*! LCK - Peripheral Permissions Lock
 *  0b0..Not Locked
 *  0b1..Locked
 */
#define RDC_PDAP_LCK(x)                          (((uint32_t)(((uint32_t)(x)) << RDC_PDAP_LCK_SHIFT)) & RDC_PDAP_LCK_MASK)
/*! @} */

/*! @name MRSA - Memory Region Start Address */
/*! @{ */

#define RDC_MRSA_SADR_MASK                       (0xFFFFFF80U)
#define RDC_MRSA_SADR_SHIFT                      (7U)
/*! SADR - Start address for memory region */
#define RDC_MRSA_SADR(x)                         (((uint32_t)(((uint32_t)(x)) << RDC_MRSA_SADR_SHIFT)) & RDC_MRSA_SADR_MASK)
/*! @} */

/* The count of RDC_MRSA */
#define RDC_MRSA_COUNT                           (52U)

/*! @name MREA - Memory Region End Address */
/*! @{ */

#define RDC_MREA_EADR_MASK                       (0xFFFFFF80U)
#define RDC_MREA_EADR_SHIFT                      (7U)
/*! EADR - Upper bound for memory region */
#define RDC_MREA_EADR(x)                         (((uint32_t)(((uint32_t)(x)) << RDC_MREA_EADR_SHIFT)) & RDC_MREA_EADR_MASK)
/*! @} */

/* The count of RDC_MREA */
#define RDC_MREA_COUNT                           (52U)

/*! @name MRC - Memory Region Control */
/*! @{ */

#define RDC_MRC_D0W_MASK                         (0x1U)
#define RDC_MRC_D0W_SHIFT                        (0U)
/*! D0W - Domain 0 Write Access to Region
 *  0b0..Processing Domain 0 does not have Write access to the memory region
 *  0b1..Processing Domain 0 has Write access to the memory region
 */
#define RDC_MRC_D0W(x)                           (((uint32_t)(((uint32_t)(x)) << RDC_MRC_D0W_SHIFT)) & RDC_MRC_D0W_MASK)

#define RDC_MRC_D0R_MASK                         (0x2U)
#define RDC_MRC_D0R_SHIFT                        (1U)
/*! D0R - Domain 0 Read Access to Region
 *  0b0..Processing Domain 0 does not have Read access to the memory region
 *  0b1..Processing Domain 0 has Read access to the memory region
 */
#define RDC_MRC_D0R(x)                           (((uint32_t)(((uint32_t)(x)) << RDC_MRC_D0R_SHIFT)) & RDC_MRC_D0R_MASK)

#define RDC_MRC_D1W_MASK                         (0x4U)
#define RDC_MRC_D1W_SHIFT                        (2U)
/*! D1W - Domain 1 Write Access to Region
 *  0b0..Processing Domain 1 does not have Write access to the memory region
 *  0b1..Processing Domain 1 has Write access to the memory region
 */
#define RDC_MRC_D1W(x)                           (((uint32_t)(((uint32_t)(x)) << RDC_MRC_D1W_SHIFT)) & RDC_MRC_D1W_MASK)

#define RDC_MRC_D1R_MASK                         (0x8U)
#define RDC_MRC_D1R_SHIFT                        (3U)
/*! D1R - Domain 1 Read Access to Region
 *  0b0..Processing Domain 1 does not have Read access to the memory region
 *  0b1..Processing Domain 1 has Read access to the memory region
 */
#define RDC_MRC_D1R(x)                           (((uint32_t)(((uint32_t)(x)) << RDC_MRC_D1R_SHIFT)) & RDC_MRC_D1R_MASK)

#define RDC_MRC_D2W_MASK                         (0x10U)
#define RDC_MRC_D2W_SHIFT                        (4U)
/*! D2W - Domain 2 Write Access to Region
 *  0b0..Processing Domain 2 does not have Write access to the memory region
 *  0b1..Processing Domain 2 has Write access to the memory region
 */
#define RDC_MRC_D2W(x)                           (((uint32_t)(((uint32_t)(x)) << RDC_MRC_D2W_SHIFT)) & RDC_MRC_D2W_MASK)

#define RDC_MRC_D2R_MASK                         (0x20U)
#define RDC_MRC_D2R_SHIFT                        (5U)
/*! D2R - Domain 2 Read Access to Region
 *  0b0..Processing Domain 2 does not have Read access to the memory region
 *  0b1..Processing Domain 2 has Read access to the memory region
 */
#define RDC_MRC_D2R(x)                           (((uint32_t)(((uint32_t)(x)) << RDC_MRC_D2R_SHIFT)) & RDC_MRC_D2R_MASK)

#define RDC_MRC_D3W_MASK                         (0x40U)
#define RDC_MRC_D3W_SHIFT                        (6U)
/*! D3W - Domain 3 Write Access to Region
 *  0b0..Processing Domain 3 does not have Write access to the memory region
 *  0b1..Processing Domain 3 has Read access to the memory region
 */
#define RDC_MRC_D3W(x)                           (((uint32_t)(((uint32_t)(x)) << RDC_MRC_D3W_SHIFT)) & RDC_MRC_D3W_MASK)

#define RDC_MRC_D3R_MASK                         (0x80U)
#define RDC_MRC_D3R_SHIFT                        (7U)
/*! D3R - Domain 3 Read Access to Region
 *  0b0..Processing Domain 3 does not have Read access to the memory region
 *  0b1..Processing Domain 3 has Read access to the memory region
 */
#define RDC_MRC_D3R(x)                           (((uint32_t)(((uint32_t)(x)) << RDC_MRC_D3R_SHIFT)) & RDC_MRC_D3R_MASK)

#define RDC_MRC_ENA_MASK                         (0x40000000U)
#define RDC_MRC_ENA_SHIFT                        (30U)
/*! ENA - Region Enable
 *  0b0..Memory region is not defined or restricted.
 *  0b1..Memory boundaries, domain permissions and controls are in effect.
 */
#define RDC_MRC_ENA(x)                           (((uint32_t)(((uint32_t)(x)) << RDC_MRC_ENA_SHIFT)) & RDC_MRC_ENA_MASK)

#define RDC_MRC_LCK_MASK                         (0x80000000U)
#define RDC_MRC_LCK_SHIFT                        (31U)
/*! LCK - Region Lock
 *  0b0..No Lock. All fields in this register may be modified.
 *  0b1..Locked. No fields in this register may be modified except ENA, which may be set but not cleared.
 */
#define RDC_MRC_LCK(x)                           (((uint32_t)(((uint32_t)(x)) << RDC_MRC_LCK_SHIFT)) & RDC_MRC_LCK_MASK)
/*! @} */

/* The count of RDC_MRC */
#define RDC_MRC_COUNT                            (52U)

/*! @name MRVS - Memory Region Violation Status */
/*! @{ */

#define RDC_MRVS_VDID_MASK                       (0x3U)
#define RDC_MRVS_VDID_SHIFT                      (0U)
/*! VDID - Violating Domain ID
 *  0b00..Processing Domain 0
 *  0b01..Processing Domain 1
 *  0b10..Processing Domain 2
 *  0b11..Processing Domain 3
 */
#define RDC_MRVS_VDID(x)                         (((uint32_t)(((uint32_t)(x)) << RDC_MRVS_VDID_SHIFT)) & RDC_MRVS_VDID_MASK)

#define RDC_MRVS_AD_MASK                         (0x10U)
#define RDC_MRVS_AD_SHIFT                        (4U)
/*! AD - Access Denied */
#define RDC_MRVS_AD(x)                           (((uint32_t)(((uint32_t)(x)) << RDC_MRVS_AD_SHIFT)) & RDC_MRVS_AD_MASK)

#define RDC_MRVS_VADR_MASK                       (0xFFFFFFE0U)
#define RDC_MRVS_VADR_SHIFT                      (5U)
/*! VADR - Violating Address */
#define RDC_MRVS_VADR(x)                         (((uint32_t)(((uint32_t)(x)) << RDC_MRVS_VADR_SHIFT)) & RDC_MRVS_VADR_MASK)
/*! @} */

/* The count of RDC_MRVS */
#define RDC_MRVS_COUNT                           (52U)


/*!
 * @}
 */ /* end of group RDC_Register_Masks */


/*!
 * @}
 */ /* end of group RDC_Peripheral_Access_Layer */


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


#endif  /* PERI_RDC_H_ */

