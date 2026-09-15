/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_MODCON_H_
#define _FSL_MODCON_H_

#include <stdint.h>
#include "fsl_common.h"

/*! @addtogroup modcon */
/*! @{ */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief MODCON driver version. */
#define FSL_MODCON_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))
/*! @} */

/*! @brief MODCON IP name arrays */

/*! @brief MODCON IP name array for ASRC. */
#define ASRC_MODCONS                                                                                                                       \
    {                                                                                                                                      \
        (uint32_t)kModCon_AUDIO_ASRC                                                                                                       \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for SPDIF. */
#define SPDIF_MODCONS                                                                                                                      \
    {                                                                                                                                      \
        (uint32_t)kModCon_AUDIO_SPDIF                                                                                                      \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for SAI. */
#define SAI_MODCONS                                                                                                                        \
    {                                                                                                                                      \
        (uint32_t)kModCon_AUDIO_SAI0, (uint32_t)kModCon_AUDIO_SAI1, (uint32_t)kModCon_AUDIO_SAI2                                           \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for PDM. */
#define PDM_MODCONS                                                                                                                        \
    {                                                                                                                                      \
        (uint32_t)kModCon_AUDIO_MIC, (uint32_t)kModCon_WAKE_MIC                                                                            \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for FREQME. */
#define FREQME_MODCONS                                                                                                                     \
    {                                                                                                                                      \
        (uint32_t)kModCon_AUDIO_FREQME, (uint32_t)kModCon_CMPT_FREQME, (uint32_t)kModCon_COMM_FREQME,                                      \
        (uint32_t)kModCon_MAIN_FREQME, (uint32_t)kModCon_MEDIA_FREQME, (uint32_t)kModCon_WAKE_FREQME                                       \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for EDMA3. */
#define EDMA3_MODCONS                                                                                                                      \
    {                                                                                                                                      \
        (uint32_t)kModCon_AUDIO_EDMA, (uint32_t)kModCon_MAIN_EDMA0, (uint32_t)kModCon_WAKE_EDMA                                            \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for EDMA5. */
#define EDMA5_MODCONS                                                                                                                      \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_EDMA1                                                                                                       \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for NPU. */
#define NPU_MODCONS                                                                                                                        \
    {                                                                                                                                      \
        (uint32_t)kModCon_CMPT_NPU                                                                                                         \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for SRAMCTL. */
#define SRAMCTL_MODCONS                                                                                                                    \
    {                                                                                                                                      \
        (uint32_t)kModCon_CMPT_SRAMCTL0, (uint32_t)kModCon_CMPT_SRAMCTL1, (uint32_t)kModCon_CMPT_SRAMCTL2                                  \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for NIC. */
#define NIC_MODCONS                                                                                                                        \
    {                                                                                                                                      \
        (uint32_t)kModCon_COMM_NIC, (uint32_t)kModCon_MAIN_NIC, (uint32_t)kModCon_MEDIA_NIC                                                \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for ROMCP. */
#define ROMCP_MODCONS                                                                                                                      \
    {                                                                                                                                      \
        (uint32_t)kModCon_CMPT_ROMCP                                                                                                       \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for ENET. */
#define ENET_MODCONS                                                                                                                       \
    {                                                                                                                                      \
        (uint32_t)kModCon_COMM_ETH0,                                                                                                       \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for ENET_QOS. */
#define ENET_QOS_MODCONS                                                                                                                   \
    {                                                                                                                                      \
        (uint32_t)kModCon_COMM_ETH1,                                                                                                       \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for TENBASET_PHY. */
#define TENBASET_PHY_MODCONS                                                                                                               \
    {                                                                                                                                      \
        (uint32_t)kModCon_COMM_XENOPHY0, (uint32_t)kModCon_COMM_XENOPHY1                                                                   \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for USDHC. */
#define USDHC_MODCONS                                                                                                                      \
    {                                                                                                                                      \
        (uint32_t)kModCon_COMM_USDHC0, (uint32_t)kModCon_COMM_USDHC1                                                                       \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for XSPIR. */
#define XSPIR_MODCONS                                                                                                                      \
    {                                                                                                                                      \
        (uint32_t)kModCon_COMM_XSPIR                                                                                                       \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for XSPI. */
#define XSPI_MODCONS                                                                                                                       \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_XSPI0, (uint32_t)kModCon_MAIN_XSPI1                                                                         \
    }                                                                                                                                      \
    
/*! @brief MODCON IP name array for SRAMC. */
#define SRAMC_MODCONS                                                                                                                      \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_SRAMC                                                                                                       \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for I3C. */
#define I3C_MODCONS                                                                                                                        \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_I3C, (uint32_t)kModCon_WAKE_I3C                                                                             \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for LPSPI. */
#define LPSPI_MODCONS                                                                                                                      \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_LPSPI0, (uint32_t)kModCon_MAIN_LPSPI1, (uint32_t)kModCon_MAIN_LPSPI2,                                       \
        (uint32_t)kModCon_MAIN_LPSPI3, (uint32_t)kModCon_MAIN_LPSPI4, (uint32_t)kModCon_WAKE_LPSPI                                         \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for LPI2C. */
#define LPI2C_MODCONS                                                                                                                      \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_LPI2C0, (uint32_t)kModCon_MAIN_LPI2C1, (uint32_t)kModCon_WAKE_LPI2C0, (uint32_t)kModCon_WAKE_LPI2C1         \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for LPUART. */
#define LPUART_MODCONS                                                                                                                     \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_LPUART0, (uint32_t)kModCon_MAIN_LPUART1, (uint32_t)kModCon_MAIN_LPUART2, (uint32_t)kModCon_MAIN_LPUART3,    \
        (uint32_t)kModCon_MAIN_LPUART4, (uint32_t)kModCon_MAIN_LPUART5, (uint32_t)kModCon_WAKE_LPUART0, (uint32_t)kModCon_WAKE_LPUART1     \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for CAN. */
#define CAN_MODCONS                                                                                                                        \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_CAN0, (uint32_t)kModCon_MAIN_CAN1, (uint32_t)kModCon_MAIN_CAN2                                              \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for EQDC. */
/* TBC :Is eqdc equal to qdec?*/
#define EQDC_MODCONS                                                                                                                       \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_EQDC0, (uint32_t)kModCon_MAIN_EQDC1, (uint32_t)kModCon_MAIN_EQDC2, (uint32_t)kModCon_MAIN_EQDC3             \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for GPIO. */
 /* TBC need further check for VBAT*/
#define GPIO_MODCONS                                                                                                                       \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_GPIO, (uint32_t)kModCon_MAIN_GPIO, (uint32_t)kModCon_MAIN_GPIO, (uint32_t)kModCon_MAIN_GPIO,                \
        (uint32_t)kModCon_MAIN_GPIO, (uint32_t)kModCon_WAKE_WAKE_GPIO, (uint32_t)kModCon_WAKE_WAKE_GPIO                                    \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for LPIT. */
#define LPIT_MODCONS                                                                                                                       \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_LPIT0, (uint32_t)kModCon_MAIN_LPIT1                                                                         \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for FLEXIO. */
#define FLEXIO_MODCONS                                                                                                                     \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_FLEXIO0, (uint32_t)kModCon_MAIN_FLEXIO1, (uint32_t)kModCon_MAIN_FLEXIO2                                     \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for FLEXPWM. */
#define FLEXPWM_MODCONS                                                                                                                    \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_FLEXPWM0, (uint32_t)kModCon_MAIN_FLEXPWM1, (uint32_t)kModCon_MAIN_FLEXPWM2, (uint32_t)kModCon_MAIN_FLEXPWM3 \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for SINC. */
#define SINC_MODCONS                                                                                                                       \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_SINC0, (uint32_t)kModCon_MAIN_SINC1                                                                         \
    }                                                                                                                                      \

/*
 * QTPM number has questions
 */


/*! @brief MODCON IP name array for CRC. */
#define CRC_MODCONS                                                                                                                        \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_CRC                                                                                                         \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for IOMUXC. */
/* TBC VBAT?*/
#define IOMUXC_MODCONS                                                                                                                     \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_IOMUX, (uint32_t)kModCon_WAKE_IOMUX, (uint32_t)kModCon_WAKE_IOMUX                                           \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for CGUA. */
#define CGUA_MODCONS                                                                                                                       \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_CGUA                                                                                                        \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for STM. */
#define STM_MODCONS                                                                                                                        \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_STM                                                                                                         \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for DAC. */
#define DAC_MODCONS                                                                                                                        \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_DAC                                                                                                         \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for QTMR. */
#define QTMR_MODCONS                                                                                                                       \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_QTIMER0, (uint32_t)kModCon_MAIN_QTIMER1, (uint32_t)kModCon_MAIN_QTIMER2, (uint32_t)kModCon_MAIN_QTIMER3     \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for ADC. */
#define ADC_MODCONS                                                                                                                        \
    {                                                                                                                                      \
        (uint32_t)kModCon_MAIN_ADC0, (uint32_t)kModCon_MAIN_ADC1                                                                           \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for MIPI_CSI. */
#define MIPI_CSI_MODCONS                                                                                                                   \
    {                                                                                                                                      \
        (uint32_t)kModCon_MEDIA_MIPI_CSI                                                                                                   \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for MIPI_DSI. */
#define MIPI_DSI_MODCONS                                                                                                                   \
    {                                                                                                                                      \
        (uint32_t)kModCon_MEDIA_MIPI_DSI                                                                                                   \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for ISI. */
#define ISI_MODCONS                                                                                                                        \
    {                                                                                                                                      \
        (uint32_t)kModCon_MEDIA_ISI                                                                                                        \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for DCIF. */
#define DCIF_MODCONS                                                                                                                       \
    {                                                                                                                                      \
        (uint32_t)kModCon_MEDIA_DCIF                                                                                                       \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for JPEG. */
#define JPEG_MODCONS                                                                                                                       \
    {                                                                                                                                      \
        (uint32_t)kModCon_MEDIA_JPEG                                                                                                       \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for GPU. */
#define GPU_MODCONS                                                                                                                        \
    {                                                                                                                                      \
        (uint32_t)kModCon_MEDIA_GPU                                                                                                        \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for REFORMATTER. */
#define REFORMATTER_MODCONS                                                                                                                \
    {                                                                                                                                      \
        (uint32_t)kModCon_MEDIA_REFORMATTER                                                                                                \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for CSI. */
#define CSI_MODCONS                                                                                                                        \
    {                                                                                                                                      \
        (uint32_t)kModCon_MEDIA_CSI                                                                                                        \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for LPTMR. */
/* TBC VBAT missing*/
#define LPTMR_MODCONS                                                                                                                      \
    {                                                                                                                                      \
        (uint32_t)kModCon_WAKE_LPTIMER0, (uint32_t)kModCon_WAKE_LPTIMER0, (uint32_t)kModCon_WAKE_LPTIMER1                                  \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for WAKE. */
#define WAKE_MODCONS                                                                                                                       \
    {                                                                                                                                      \
        (uint32_t)kModCon_WAKE_EWM                                                                                                         \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for SWT. */
#define SWT_MODCONS                                                                                                                        \
    {                                                                                                                                      \
        (uint32_t)kModCon_WAKE_SWT0, (uint32_t)kModCon_WAKE_SWT1                                                                           \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for ACMP. */
/* TBC 1 for all? */
#define ACMP_MODCONS                                                                                                                       \
    {                                                                                                                                      \
        (uint32_t)kModCon_WAKE_ACMP, (uint32_t)kModCon_WAKE_ACMP, (uint32_t)kModCon_WAKE_ACMP, (uint32_t)kModCon_WAKE_ACMP                 \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for CGUANA. */
#define CGUANA_MODCONS                                                                                                                     \
    {                                                                                                                                      \
        (uint32_t)kModCon_WAKE_CGUANA                                                                                                      \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for PMUANA. */
#define PMUANA_MODCONS                                                                                                                     \
    {                                                                                                                                      \
        (uint32_t)kModCon_WAKE_PMUANA                                                                                                      \
    }                                                                                                                                      \

/*! @brief MODCON IP name array for CGU. */
#define CGU_MODCONS                                                                                                                        \
    {                                                                                                                                      \
        (uint32_t)kModCon_WAKE_CGU                                                                                                         \
    }                                                                                                                                      \

/*
 * MEM, AXBS, IPD, CM85, CMPT, SSI, IAHBG, GF22, CM85_ECCINIT are missing
 */

/*
 * USB need further check
 */ 
/*
 * CCM need further check
 */
/*
 * What is MEDIA_CSI?
 */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @brief Get MODCON version.
 *
 * @param modcon MODCON instance.
 * @return MODCON version register value.
 */
uint32_t MODCON_GetVersion(modcon_instance_t modcon);

/*!
 * @brief Get MODCON trust mask.
 *
 * @param modcon MODCON instance.
 * @return MODCON trust mask register value.
 */
uint32_t MODCON_GetTrustMask(modcon_instance_t modcon);

/*!
 * @brief Set MODCON trust mask.
 *
 * @param modcon MODCON instance.
 * @param trustMask Trust mask value to set.
 * @param lock Whether to lock the trust mask setting.
 */
void MODCON_SetTrustMask(modcon_instance_t modcon, uint8_t trustMask, bool lock);

/*!
 * @brief Get IP domain mask.
 *
 * @param ip IP identifier.
 * @return IP domain mask register value.
 */
uint32_t MODCON_GetIPDomainMask(uint32_t ip);

/*!
 * @brief Set IP domain mask.
 *
 * @param ip IP identifier.
 * @param domainMask Domain mask value to set.
 * @param lock Whether to lock the domain mask setting.
 */
void MODCON_SetIPDomainMask(uint32_t ip, uint8_t domainMask, bool lock);

/*!
 * @brief Get IP reset status.
 *
 * @param ip IP identifier.
 * @return IP reset status register value.
 */
uint32_t MODCON_GetIPRST(uint32_t ip);

/*!
 * @brief Set IP reset.
 *
 * @param ip IP identifier.
 */
void MODCON_SetIPRST(uint32_t ip);

/*!
 * @brief Clear IP reset.
 *
 * @param ip IP identifier.
 */
void MODCON_ClearIPRST(uint32_t ip);

/*!
 * @brief Get IP configuration register value.
 *
 * @param ip IP identifier.
 * @param idx Configuration register index.
 * @return IP configuration register value.
 */
uint32_t MODCON_GetCFG(uint32_t ip, uint8_t idx);

/*!
 * @brief Set IP configuration register value.
 *
 * @param ip IP identifier.
 * @param idx Configuration register index.
 * @param value Configuration value to set.
 */
void MODCON_SetCFG(uint32_t ip, uint8_t idx, uint32_t value);

/*!
 * @brief Get IP status register value.
 *
 * @param ip IP identifier.
 * @param idx Status register index.
 * @return IP status register value.
 */
uint32_t MODCON_GetSts(uint32_t ip, uint8_t idx);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif
