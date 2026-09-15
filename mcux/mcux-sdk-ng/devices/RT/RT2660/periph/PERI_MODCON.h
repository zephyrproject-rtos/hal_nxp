/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MODCON
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_MODCON.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for MODCON
 *
 * CMSIS Peripheral Access Layer for MODCON
 */

#if !defined(PERI_MODCON_H_)
#define PERI_MODCON_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
#if !defined(MODCON_INSTANCE_T_)
#define MODCON_INSTANCE_T_
/*!
 * @addtogroup modcon_instance
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for MODCON INSTANCE
 *
 * Defines the enumeration for the MODCON INSTANCE collections.
 */
typedef enum _modcon_instance
{
    kModCON_Instance_AUDIO          = 0U,          /**< Audio subsystem MODCON instance */
    kModCON_Instance_CMPT           = 1U,          /**< Cmpt subsystem MODCON instance */
    kModCON_Instance_COMM           = 2U,          /**< Comm subsystem MODCON instance */
    kModCON_Instance_MAIN           = 3U,          /**< Main subsystem MODCON instance */
    kModCON_Instance_MEDIA          = 4U,          /**< Media subsystem MODCON instance */
    kModCON_Instance_WAKE           = 5U,          /**< Wake subsystem MODCON instance */
} modcon_instance_t;

/* @} */
#endif /* MODCON_INSTANCE_T_ */

#if !defined(AUDIO_MODCON_IP_T_)
#define AUDIO_MODCON_IP_T_
/*!
 * @addtogroup audio_modcon_ips
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for AUDIO MODCON IP
 *
 * Defines the enumeration for the AUDIO MODCON IP collections.
 */
typedef enum _audio_modcon_ip
{
    kModCon_AUDIO_MQS               = 0U,          /**< modcon0 ip index */
    kModCon_AUDIO_ASRC              = 1U,          /**< modcon0 ip index */
    kModCon_AUDIO_SPDIF             = 2U,          /**< modcon0 ip index */
    kModCon_AUDIO_SAI0              = 3U,          /**< modcon0 ip index */
    kModCon_AUDIO_SAI1              = 4U,          /**< modcon0 ip index */
    kModCon_AUDIO_SAI2              = 5U,          /**< modcon0 ip index */
    kModCon_AUDIO_MIC               = 6U,          /**< modcon0 ip index */
    kModCon_AUDIO_FREQME            = 7U,          /**< modcon0 ip index */
    kModCon_AUDIO_EDMA              = 8U,          /**< modcon0 ip index */
    kModCon_AUDIO_AXBS_CLKEN        = 10U,         /**< modcon0 ip index */
} audio_modcon_ip_t;

/* @} */
#endif /* AUDIO_MODCON_IP_T_ */

#if !defined(COMM_MODCON_IP_T_)
#define COMM_MODCON_IP_T_
/*!
 * @addtogroup comm_modcon_ips
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for COMM MODCON IP
 *
 * Defines the enumeration for the COMM MODCON IP collections.
 */
typedef enum _comm_modcon_ip
{
    kModCon_COMM_ETH0               = 0|0x200U,    /**< modcon2 ip index */
    kModCon_COMM_ETH1               = 1|0x200U,    /**< modcon2 ip index */
    kModCon_COMM_XENOPHY0           = 2|0x200U,    /**< modcon2 ip index */
    kModCon_COMM_XENOPHY1           = 3|0x200U,    /**< modcon2 ip index */
    kModCon_COMM_USB_MISC           = 4|0x200U,    /**< modcon2 ip index */
    kModCon_COMM_USB0               = 5|0x200U,    /**< modcon2 ip index */
    kModCon_COMM_USBPHY0            = 6|0x200U,    /**< modcon2 ip index */
    kModCon_COMM_USB1               = 7|0x200U,    /**< modcon2 ip index */
    kModCon_COMM_USDHC0             = 8|0x200U,    /**< modcon2 ip index */
    kModCon_COMM_USDHC1             = 9|0x200U,    /**< modcon2 ip index */
    kModCon_COMM_XSPIR              = 10|0x200U,   /**< modcon2 ip index */
    kModCon_COMM_FREQME             = 11|0x200U,   /**< modcon2 ip index */
} comm_modcon_ip_t;

/* @} */
#endif /* COMM_MODCON_IP_T_ */

#if !defined(CMPT_MODCON_IP_T_)
#define CMPT_MODCON_IP_T_
/*!
 * @addtogroup cmpt_modcon_ips
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for CMPT MODCON IP
 *
 * Defines the enumeration for the CMPT MODCON IP collections.
 */
typedef enum _cmpt_modcon_ip
{
    kModCon_CMPT_NPU                = 0|0x100U,    /**< modcon1 ip index */
    kModCon_CMPT_SRAMCTL0           = 1|0x100U,    /**< modcon1 ip index */
    kModCon_CMPT_SRAMCTL1           = 2|0x100U,    /**< modcon1 ip index */
    kModCon_CMPT_SRAMCTL2           = 3|0x100U,    /**< modcon1 ip index */
    kModCon_CMPT_FREQME             = 4|0x100U,    /**< modcon1 ip index */
    kModCon_CMPT_CM85               = 5|0x100U,    /**< modcon1 ip index */
    kModCon_CMPT_IAHBG              = 10|0x100U,   /**< modcon1 ip index */
    kModCon_CMPT_CM85_ECC_INIT      = 12|0x100U,   /**< modcon1 ip index */
    kModCon_CMPT_LLC                = 13|0x100U,   /**< modcon1 ip index */
    kModCon_CMPT_NIC                = 14|0x100U,   /**< modcon1 ip index */
} cmpt_modcon_ip_t;

/* @} */
#endif /* CMPT_MODCON_IP_T_ */

#if !defined(MAIN_MODCON_IP_T_)
#define MAIN_MODCON_IP_T_
/*!
 * @addtogroup main_modcon_ips
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for MAIN MODCON IP
 *
 * Defines the enumeration for the MAIN MODCON IP collections.
 */
typedef enum _main_modcon_ip
{
    kModCon_MAIN_EDMA0              = 0|0x300U,    /**< modcon3 ip index */
    kModCon_MAIN_EDMA1              = 1|0x300U,    /**< modcon3 ip index */
    kModCon_MAIN_XSPI0              = 2|0x300U,    /**< modcon3 ip index */
    kModCon_MAIN_XSPI1              = 3|0x300U,    /**< modcon3 ip index */
    kModCon_MAIN_SRAMC              = 5|0x300U,    /**< modcon3 ip index */
    kModCon_MAIN_FREQME             = 6|0x300U,    /**< modcon3 ip index */
    kModCon_MAIN_NIC                = 7|0x300U,    /**< modcon3 ip index */
    kModCon_MAIN_I3C                = 10|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_LPSPI0             = 11|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_LPSPI1             = 12|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_LPSPI2             = 13|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_LPSPI3             = 14|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_LPSPI4             = 15|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_LPI2C0             = 16|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_LPI2C1             = 17|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_LPUART0            = 18|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_LPUART1            = 19|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_LPUART2            = 20|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_LPUART3            = 21|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_LPUART4            = 22|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_LPUART5            = 23|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_CAN0               = 24|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_CAN1               = 25|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_CAN2               = 26|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_QDEC0              = 27|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_QDEC1              = 28|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_QDEC2              = 29|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_QDEC3              = 30|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_GPIO               = 31|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_LPIT0              = 32|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_LPIT1              = 33|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_FLEXIO0            = 34|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_FLEXIO1            = 35|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_FLEXIO2            = 36|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_FLEXPWM0           = 37|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_FLEXPWM1           = 38|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_FLEXPWM2           = 39|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_FLEXPWM3           = 40|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_SINC0              = 41|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_SINC1              = 42|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_QTPM0              = 43|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_EVTG0              = 46|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_EVTG1              = 47|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_EVTG2              = 48|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_EVTG3              = 49|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_CRC                = 50|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_IOMUX              = 51|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_CGUA               = 52|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_ELS                = 53|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_AXBS               = 55|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_STM                = 56|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_DAC                = 57|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_QTIMER0            = 59|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_QTIMER1            = 60|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_QTIMER2            = 61|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_QTIMER3            = 62|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_ADC0               = 64|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_ADC1               = 65|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_IOREFGEN           = 66|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_CLK24M_SEL         = 67|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_CCM                = 68|0x300U,   /**< modcon3 ip index */
    kModCon_MAIN_XHB500             = 69|0x300U,   /**< modcon3 ip index */
} main_modcon_ip_t;

/* @} */
#endif /* MAIN_MODCON_IP_T_ */

#if !defined(MEDIA_MODCON_IP_T_)
#define MEDIA_MODCON_IP_T_
/*!
 * @addtogroup media_modcon_ips
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for MEDIA MODCON IP
 *
 * Defines the enumeration for the MEDIA MODCON IP collections.
 */
typedef enum _media_modcon_ip
{
    kModCon_MEDIA_MIPI_CSI          = 0|0x400U,    /**< modcon ip index */
    kModCon_MEDIA_MIPI_DSI          = 1|0x400U,    /**< modcon ip index */
    kModCon_MEDIA_ISI               = 2|0x400U,    /**< modcon ip index */
    kModCon_MEDIA_DCIF              = 3|0x400U,    /**< modcon ip index */
    kModCon_MEDIA_JPEG_DECODER      = 4|0x400U,    /**< modcon ip index */
    kModCon_MEDIA_GPU               = 5|0x400U,    /**< modcon ip index */
    kModCon_MEDIA_REFORMATTER       = 6|0x400U,    /**< modcon ip index */
    kModCon_MEDIA_FREQME            = 7|0x400U,    /**< modcon ip index */
    kModCon_MEDIA_CSI               = 8|0x400U,    /**< modcon ip index */
} media_modcon_ip_t;

/* @} */
#endif /* MEDIA_MODCON_IP_T_ */

#if !defined(WAKE_MODCON_IP_T_)
#define WAKE_MODCON_IP_T_
/*!
 * @addtogroup wake_modcon_ips
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for WAKE MODCON IP
 *
 * Defines the enumeration for the WAKE MODCON IP collections.
 */
typedef enum _wake_modcon_ip
{
    kModCon_WAKE_LPI2C0             = 0|0x500U,    /**< modcon5 ip index */
    kModCon_WAKE_LPI2C1             = 1|0x500U,    /**< modcon5 ip index */
    kModCon_WAKE_LPSPI              = 2|0x500U,    /**< modcon5 ip index */
    kModCon_WAKE_LPTIMER0           = 3|0x500U,    /**< modcon5 ip index */
    kModCon_WAKE_LPTIMER1           = 4|0x500U,    /**< modcon5 ip index */
    kModCon_WAKE_LPUART0            = 5|0x500U,    /**< modcon5 ip index */
    kModCon_WAKE_LPUART1            = 6|0x500U,    /**< modcon5 ip index */
    kModCon_WAKE_EWM                = 7|0x500U,    /**< modcon5 ip index */
    kModCon_WAKE_I3C                = 8|0x500U,    /**< modcon5 ip index */
    kModCon_WAKE_WAKE_RGPIO         = 9|0x500U,    /**< modcon5 ip index */
    kModCon_WAKE_SWT0               = 10|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_SWT1               = 11|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_QTPM               = 12|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_FREQME             = 13|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_CM85               = 14|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_MIC                = 15|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_IOMUX              = 16|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_EDMA               = 17|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_AXBS_CLKEN         = 19|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_NMISRC             = 20|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_ACMP               = 21|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_PWRMUX             = 24|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_IOREFGEN           = 25|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_JTAG               = 26|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_SILICON_ID         = 27|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_CGUANA             = 28|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_MIPI_0V8           = 29|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_PMUANA             = 30|0x500U,   /**< modcon5 ip index */
    kModCon_WAKE_CGU                = 31|0x500U,   /**< modcon5 ip index */
} wake_modcon_ip_t;

/* @} */
#endif /* WAKE_MODCON_IP_T_ */


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
/*! @brief Extract MODCON instance from IP index */
#define getModConInstance(idx) ((idx & 0x700) >> 8)

/*! @brief Extract MODCON offset from IP index */
#define getModConOffset(idx) (idx & 0xff)


/* ----------------------------------------------------------------------------
   -- MODCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MODCON_Peripheral_Access_Layer MODCON Peripheral Access Layer
 * @{
 */

/** MODCON - Size of Registers Arrays */
#define MODCON_IP_CFG_COUNT                       4u
#define MODCON_IP_STATUS_COUNT                    5u
#define MODCON_IP_COUNT                           70u

/** MODCON - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< MODCON Version, offset: 0x0 */
  __IO uint32_t TRUSTCTRL;                         /**< MODCON Trust Control, offset: 0x4 */
       uint8_t RESERVED_0[504];
  struct {                                         /* offset: 0x200, array step: 0x200 */
    __IO uint32_t ACCESSCTRL;                        /**< LPI2C0 Access Control..XHB500 Access Control, array offset: 0x200, array step: 0x200, irregular array, not all indices are valid */
    __IO uint32_t RSTCTRL;                           /**< LPI2C0 Reset Control..ADC1 Reset Control, array offset: 0x204, array step: 0x200, irregular array, not all indices are valid */
         uint8_t RESERVED_0[8];
    __IO uint32_t CFG[MODCON_IP_CFG_COUNT];          /**< ENET_QOS Configuration..XHB500 Interrupt Control, array offset: 0x210, array step: index*0x200, index2*0x4, irregular array, not all indices are valid */
         uint8_t RESERVED_1[48];
    __IO uint32_t STATUS[MODCON_IP_STATUS_COUNT];    /**< NPU Status..ELE Status, array offset: 0x250, array step: index*0x200, index2*0x4, irregular array, not all indices are valid */
         uint8_t RESERVED_2[412];
  } IP[MODCON_IP_COUNT];
} MODCON_Type;

/* ----------------------------------------------------------------------------
   -- MODCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MODCON_Register_Masks MODCON Register Masks
 * @{
 */

/*! @name VERID - MODCON Version */
/*! @{ */

#define MODCON_VERID_VER_MASK                    (0xFFFFFFFFU)
#define MODCON_VERID_VER_SHIFT                   (0U)
/*! VER - MODCON Version */
#define MODCON_VERID_VER(x)                      (((uint32_t)(((uint32_t)(x)) << MODCON_VERID_VER_SHIFT)) & MODCON_VERID_VER_MASK)
/*! @} */

/*! @name TRUSTCTRL - MODCON Trust Control */
/*! @{ */

#define MODCON_TRUSTCTRL_NSM_MASK                (0x10000U)
#define MODCON_TRUSTCTRL_NSM_SHIFT               (16U)
/*! NSM - Non-Secure Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_TRUSTCTRL_NSM(x)                  (((uint32_t)(((uint32_t)(x)) << MODCON_TRUSTCTRL_NSM_SHIFT)) & MODCON_TRUSTCTRL_NSM_MASK)

#define MODCON_TRUSTCTRL_UM_MASK                 (0x20000U)
#define MODCON_TRUSTCTRL_UM_SHIFT                (17U)
/*! UM - User Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_TRUSTCTRL_UM(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_TRUSTCTRL_UM_SHIFT)) & MODCON_TRUSTCTRL_UM_MASK)

#define MODCON_TRUSTCTRL_LOCK_MASK               (0x80000000U)
#define MODCON_TRUSTCTRL_LOCK_SHIFT              (31U)
/*! LOCK - Lock
 *  0b0..No Lock
 *  0b1..Lock
 */
#define MODCON_TRUSTCTRL_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_TRUSTCTRL_LOCK_SHIFT)) & MODCON_TRUSTCTRL_LOCK_MASK)
/*! @} */

/*! @name ACCESSCTRL - LPI2C0 Access Control..XHB500 Access Control */
/*! @{ */

#define MODCON_ACCESSCTRL_DOMAIN_MASK            (0xFU)
#define MODCON_ACCESSCTRL_DOMAIN_SHIFT           (0U)
/*! DOMAIN - Domain ID */
#define MODCON_ACCESSCTRL_DOMAIN(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_ACCESSCTRL_DOMAIN_SHIFT)) & MODCON_ACCESSCTRL_DOMAIN_MASK)

#define MODCON_ACCESSCTRL_LOCK_MASK              (0x80000000U)
#define MODCON_ACCESSCTRL_LOCK_SHIFT             (31U)
/*! LOCK - Lock
 *  0b0..No Lock
 *  0b1..Lock
 */
#define MODCON_ACCESSCTRL_LOCK(x)                (((uint32_t)(((uint32_t)(x)) << MODCON_ACCESSCTRL_LOCK_SHIFT)) & MODCON_ACCESSCTRL_LOCK_MASK)
/*! @} */

/* The count of MODCON_ACCESSCTRL */
#define MODCON_ACCESSCTRL_COUNT                  (70U)

/*! @name RSTCTRL - LPI2C0 Reset Control..ADC1 Reset Control */
/*! @{ */

#define MODCON_RSTCTRL_RST_MASK                  (0x1U)
#define MODCON_RSTCTRL_RST_SHIFT                 (0U)
/*! RST - Reset
 *  0b0..Not Reset
 *  0b1..Reset
 */
#define MODCON_RSTCTRL_RST(x)                    (((uint32_t)(((uint32_t)(x)) << MODCON_RSTCTRL_RST_SHIFT)) & MODCON_RSTCTRL_RST_MASK)

#define MODCON_RSTCTRL_RST_ACMP0_MASK            (0x1U)
#define MODCON_RSTCTRL_RST_ACMP0_SHIFT           (0U)
/*! RST_ACMP0 - Reset ACMP0
 *  0b0..Not Reset
 *  0b1..Reset
 */
#define MODCON_RSTCTRL_RST_ACMP0(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_RSTCTRL_RST_ACMP0_SHIFT)) & MODCON_RSTCTRL_RST_ACMP0_MASK)

#define MODCON_RSTCTRL_RST_GPIO0_MASK            (0x1U)
#define MODCON_RSTCTRL_RST_GPIO0_SHIFT           (0U)
/*! RST_GPIO0 - Reset GPIO0
 *  0b0..Not Reset
 *  0b1..Reset
 */
#define MODCON_RSTCTRL_RST_GPIO0(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_RSTCTRL_RST_GPIO0_SHIFT)) & MODCON_RSTCTRL_RST_GPIO0_MASK)

#define MODCON_RSTCTRL_RST_ACMP1_MASK            (0x2U)
#define MODCON_RSTCTRL_RST_ACMP1_SHIFT           (1U)
/*! RST_ACMP1 - Reset ACMP1
 *  0b0..Not Reset
 *  0b1..Reset
 */
#define MODCON_RSTCTRL_RST_ACMP1(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_RSTCTRL_RST_ACMP1_SHIFT)) & MODCON_RSTCTRL_RST_ACMP1_MASK)

#define MODCON_RSTCTRL_RST_GLUE_MASK             (0x2U)
#define MODCON_RSTCTRL_RST_GLUE_SHIFT            (1U)
/*! RST_GLUE - Reset SWT1 Interrupt Logic
 *  0b0..Not Reset
 *  0b1..Reset
 */
#define MODCON_RSTCTRL_RST_GLUE(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_RSTCTRL_RST_GLUE_SHIFT)) & MODCON_RSTCTRL_RST_GLUE_MASK)

#define MODCON_RSTCTRL_RST_GPIO1_MASK            (0x2U)
#define MODCON_RSTCTRL_RST_GPIO1_SHIFT           (1U)
/*! RST_GPIO1 - Reset GPIO1
 *  0b0..Not Reset
 *  0b1..Reset
 */
#define MODCON_RSTCTRL_RST_GPIO1(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_RSTCTRL_RST_GPIO1_SHIFT)) & MODCON_RSTCTRL_RST_GPIO1_MASK)

#define MODCON_RSTCTRL_RST_IRQ_GLUE_MASK         (0x2U)
#define MODCON_RSTCTRL_RST_IRQ_GLUE_SHIFT        (1U)
/*! RST_IRQ_GLUE - Reset Interrupt Logic
 *  0b0..Not Reset
 *  0b1..Reset
 */
#define MODCON_RSTCTRL_RST_IRQ_GLUE(x)           (((uint32_t)(((uint32_t)(x)) << MODCON_RSTCTRL_RST_IRQ_GLUE_SHIFT)) & MODCON_RSTCTRL_RST_IRQ_GLUE_MASK)

#define MODCON_RSTCTRL_RST_ACMP2_MASK            (0x4U)
#define MODCON_RSTCTRL_RST_ACMP2_SHIFT           (2U)
/*! RST_ACMP2 - Reset ACMP2
 *  0b0..Not Reset
 *  0b1..Reset
 */
#define MODCON_RSTCTRL_RST_ACMP2(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_RSTCTRL_RST_ACMP2_SHIFT)) & MODCON_RSTCTRL_RST_ACMP2_MASK)

#define MODCON_RSTCTRL_RST_GPIO2_MASK            (0x4U)
#define MODCON_RSTCTRL_RST_GPIO2_SHIFT           (2U)
/*! RST_GPIO2 - Reset GPIO2
 *  0b0..Not Reset
 *  0b1..Reset
 */
#define MODCON_RSTCTRL_RST_GPIO2(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_RSTCTRL_RST_GPIO2_SHIFT)) & MODCON_RSTCTRL_RST_GPIO2_MASK)

#define MODCON_RSTCTRL_RST_ACMP3_MASK            (0x8U)
#define MODCON_RSTCTRL_RST_ACMP3_SHIFT           (3U)
/*! RST_ACMP3 - Reset ACMP3
 *  0b0..Not Reset
 *  0b1..Reset
 */
#define MODCON_RSTCTRL_RST_ACMP3(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_RSTCTRL_RST_ACMP3_SHIFT)) & MODCON_RSTCTRL_RST_ACMP3_MASK)

#define MODCON_RSTCTRL_RST_GPIO3_MASK            (0x8U)
#define MODCON_RSTCTRL_RST_GPIO3_SHIFT           (3U)
/*! RST_GPIO3 - Reset GPIO3
 *  0b0..Not Reset
 *  0b1..Reset
 */
#define MODCON_RSTCTRL_RST_GPIO3(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_RSTCTRL_RST_GPIO3_SHIFT)) & MODCON_RSTCTRL_RST_GPIO3_MASK)

#define MODCON_RSTCTRL_RST_GPIO4_MASK            (0x10U)
#define MODCON_RSTCTRL_RST_GPIO4_SHIFT           (4U)
/*! RST_GPIO4 - Reset GPIO4
 *  0b0..Not Reset
 *  0b1..Reset
 */
#define MODCON_RSTCTRL_RST_GPIO4(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_RSTCTRL_RST_GPIO4_SHIFT)) & MODCON_RSTCTRL_RST_GPIO4_MASK)

#define MODCON_RSTCTRL_LOCK_MASK                 (0x80000000U)
#define MODCON_RSTCTRL_LOCK_SHIFT                (31U)
/*! LOCK - Lock
 *  0b0..No Lock
 *  0b1..Lock
 */
#define MODCON_RSTCTRL_LOCK(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_RSTCTRL_LOCK_SHIFT)) & MODCON_RSTCTRL_LOCK_MASK)
/*! @} */

/* The count of MODCON_RSTCTRL */
#define MODCON_RSTCTRL_COUNT                     (70U)

/*! @name CFG - ENET_QOS Configuration..XHB500 Interrupt Control */
/*! @{ */

#define MODCON_CFG_APB_SLV_ERR_DISABLE_MASK      (0x1FFFFU)
#define MODCON_CFG_APB_SLV_ERR_DISABLE_SHIFT     (0U)
/*! APB_SLV_ERR_DISABLE - APB Acess Target Error Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_APB_SLV_ERR_DISABLE(x)        (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_APB_SLV_ERR_DISABLE_SHIFT)) & MODCON_CFG_APB_SLV_ERR_DISABLE_MASK)

#define MODCON_CFG_ARQOS_MASK                    (0xFU)
#define MODCON_CFG_ARQOS_SHIFT                   (0U)
/*! ARQOS - ArQoS */
#define MODCON_CFG_ARQOS(x)                      (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ARQOS_SHIFT)) & MODCON_CFG_ARQOS_MASK)

#define MODCON_CFG_AUTO_GATE_ENABLE_MASK         (0x1U)
#define MODCON_CFG_AUTO_GATE_ENABLE_SHIFT        (0U)
/*! AUTO_GATE_ENABLE - Auto Gate
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_AUTO_GATE_ENABLE(x)           (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_AUTO_GATE_ENABLE_SHIFT)) & MODCON_CFG_AUTO_GATE_ENABLE_MASK)

#define MODCON_CFG_AWQOS_Y_MASK                  (0xFU)
#define MODCON_CFG_AWQOS_Y_SHIFT                 (0U)
/*! AWQOS_Y - Address Write QoS for Port Y */
#define MODCON_CFG_AWQOS_Y(x)                    (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_AWQOS_Y_SHIFT)) & MODCON_CFG_AWQOS_Y_MASK)

#define MODCON_CFG_BUF_WRITE_ERR_MASK            (0x1U)
#define MODCON_CFG_BUF_WRITE_ERR_SHIFT           (0U)
/*! BUF_WRITE_ERR - BUF_WRITE_ERR Interrupt
 *  0b0..No interrupt
 *  0b1..Has Interrupt
 */
#define MODCON_CFG_BUF_WRITE_ERR(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_BUF_WRITE_ERR_SHIFT)) & MODCON_CFG_BUF_WRITE_ERR_MASK)

#define MODCON_CFG_BYPASS_MASK                   (0x1U)
#define MODCON_CFG_BYPASS_SHIFT                  (0U)
/*! BYPASS - Bypass
 *  0b0..Not bypass
 *  0b1..Bypass
 */
#define MODCON_CFG_BYPASS(x)                     (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_BYPASS_SHIFT)) & MODCON_CFG_BYPASS_MASK)

#define MODCON_CFG_BYPASS_CGU_RESET_HANDLER_MASK (0x1U)
#define MODCON_CFG_BYPASS_CGU_RESET_HANDLER_SHIFT (0U)
/*! BYPASS_CGU_RESET_HANDLER - CCM Reset Control
 *  0b0..Resets CCM by RESETCON.
 *  0b1..Resets CCM by VDDCORE OK flag from PMU
 */
#define MODCON_CFG_BYPASS_CGU_RESET_HANDLER(x)   (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_BYPASS_CGU_RESET_HANDLER_SHIFT)) & MODCON_CFG_BYPASS_CGU_RESET_HANDLER_MASK)

#define MODCON_CFG_CF_FLT_EN_MASK                (0x1U)
#define MODCON_CFG_CF_FLT_EN_SHIFT               (0U)
/*! CF_FLT_EN - Spike Filter Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_CF_FLT_EN(x)                  (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_CF_FLT_EN_SHIFT)) & MODCON_CFG_CF_FLT_EN_MASK)

#define MODCON_CFG_CNTS_FREEZE_MASK              (0x1U)
#define MODCON_CFG_CNTS_FREEZE_SHIFT             (0U)
/*! CNTS_FREEZE - Timer Counter Freeze
 *  0b0..Not reset
 *  0b1..Reset
 */
#define MODCON_CFG_CNTS_FREEZE(x)                (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_CNTS_FREEZE_SHIFT)) & MODCON_CFG_CNTS_FREEZE_MASK)

#define MODCON_CFG_COMM_CSYSREQ_MASK             (0x1U)
#define MODCON_CFG_COMM_CSYSREQ_SHIFT            (0U)
/*! COMM_CSYSREQ - Request COMM_NIC to Exit Low-power State
 *  0b0..Request to enter low-power state
 *  0b1..Request to exit low-power state
 */
#define MODCON_CFG_COMM_CSYSREQ(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_COMM_CSYSREQ_SHIFT)) & MODCON_CFG_COMM_CSYSREQ_MASK)

#define MODCON_CFG_DIR_MASK                      (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (8, 32), largest definition used */
#define MODCON_CFG_DIR_SHIFT                     (0U)
/*! DIR - XBAR IOMUX Direction
 *  0b00000000000000000000000000000000..Output, from XBAR0 to IOMUX.
 *  0b00000000000000000000000000000001..Input, from IOMUX to XBAR0.
 */
#define MODCON_CFG_DIR(x)                        (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_DIR_SHIFT)) & MODCON_CFG_DIR_MASK)  /* Merged from fields with different position or width, of widths (8, 32), largest definition used */

#define MODCON_CFG_EDMA0_AWCACHE_MASK            (0xFU)
#define MODCON_CFG_EDMA0_AWCACHE_SHIFT           (0U)
/*! EDMA0_AWCACHE - EDMA5 AWCACHE Override Value */
#define MODCON_CFG_EDMA0_AWCACHE(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_EDMA0_AWCACHE_SHIFT)) & MODCON_CFG_EDMA0_AWCACHE_MASK)

#define MODCON_CFG_ELS_HALT_ACK_MASK             (0x1U)
#define MODCON_CFG_ELS_HALT_ACK_SHIFT            (0U)
/*! ELS_HALT_ACK - ELE Halt and Clock Status
 *  0b0..Not fully halted, its clocks are enabled
 *  0b1..Fully halted, clocks may be removed
 */
#define MODCON_CFG_ELS_HALT_ACK(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ELS_HALT_ACK_SHIFT)) & MODCON_CFG_ELS_HALT_ACK_MASK)

#define MODCON_CFG_ENET1G_TX_CLK_SEL_MASK        (0x1U)
#define MODCON_CFG_ENET1G_TX_CLK_SEL_SHIFT       (0U)
/*! ENET1G_TX_CLK_SEL - ENET TX Clock Selection
 *  0b0..Driven by eth1_trxclk
 *  0b1..From pad
 */
#define MODCON_CFG_ENET1G_TX_CLK_SEL(x)          (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ENET1G_TX_CLK_SEL_SHIFT)) & MODCON_CFG_ENET1G_TX_CLK_SEL_MASK)

#define MODCON_CFG_ENET_QOS_REF_CLK_DIR_MASK     (0x1U)
#define MODCON_CFG_ENET_QOS_REF_CLK_DIR_SHIFT    (0U)
/*! ENET_QOS_REF_CLK_DIR - COMM_ENET_QOS_REF_CLK1 Direction Control
 *  0b0..Input
 *  0b1..Output
 */
#define MODCON_CFG_ENET_QOS_REF_CLK_DIR(x)       (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ENET_QOS_REF_CLK_DIR_SHIFT)) & MODCON_CFG_ENET_QOS_REF_CLK_DIR_MASK)

#define MODCON_CFG_INITL1RSTDIS_MASK             (0x1U)
#define MODCON_CFG_INITL1RSTDIS_SHIFT            (0U)
/*! INITL1RSTDIS - L1 Cache Invalidation Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_INITL1RSTDIS(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_INITL1RSTDIS_SHIFT)) & MODCON_CFG_INITL1RSTDIS_MASK)

#define MODCON_CFG_INITNSVTOR_MASK               (0x1FFFFFFU)
#define MODCON_CFG_INITNSVTOR_SHIFT              (0U)
/*! INITNSVTOR - Non-Secure Vector Table Offset */
#define MODCON_CFG_INITNSVTOR(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_INITNSVTOR_SHIFT)) & MODCON_CFG_INITNSVTOR_MASK)

#define MODCON_CFG_INITSVTOR_MASK                (0x1FFFFFFU)
#define MODCON_CFG_INITSVTOR_SHIFT               (0U)
/*! INITSVTOR - Secure Vector Table Offset */
#define MODCON_CFG_INITSVTOR(x)                  (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_INITSVTOR_SHIFT)) & MODCON_CFG_INITSVTOR_MASK)

#define MODCON_CFG_INIT_REQ_MASK                 (0x1U)
#define MODCON_CFG_INIT_REQ_SHIFT                (0U)
/*! INIT_REQ - Initialization Request
 *  0b0..Not request
 *  0b1..Request
 */
#define MODCON_CFG_INIT_REQ(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_INIT_REQ_SHIFT)) & MODCON_CFG_INIT_REQ_MASK)

#define MODCON_CFG_INVERT_MASK                   (0x1U)
#define MODCON_CFG_INVERT_SHIFT                  (0U)
/*! INVERT - Invert
 *  0b0..Not invert
 *  0b1..Invert
 */
#define MODCON_CFG_INVERT(x)                     (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_INVERT_SHIFT)) & MODCON_CFG_INVERT_MASK)

#define MODCON_CFG_IPG_CLK_ACTIVE_MASK           (0x1U)
#define MODCON_CFG_IPG_CLK_ACTIVE_SHIFT          (0U)
/*! IPG_CLK_ACTIVE - IPG_CLK Active
 *  0b0..Not active
 *  0b1..Active
 */
#define MODCON_CFG_IPG_CLK_ACTIVE(x)             (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_IPG_CLK_ACTIVE_SHIFT)) & MODCON_CFG_IPG_CLK_ACTIVE_MASK)

#define MODCON_CFG_IPG_STOP_MODE_MASK            (0x1U)
#define MODCON_CFG_IPG_STOP_MODE_SHIFT           (0U)
/*! IPG_STOP_MODE - ADC1 Stop Mode Selection
 *  0b0..Functional
 *  0b1..Not functional
 */
#define MODCON_CFG_IPG_STOP_MODE(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_IPG_STOP_MODE_SHIFT)) & MODCON_CFG_IPG_STOP_MODE_MASK)

#define MODCON_CFG_IRQCPU0_MASK                  (0x1FFU)
#define MODCON_CFG_IRQCPU0_SHIFT                 (0U)
/*! IRQCPU0 - NMI of CPU0 Source Selection */
#define MODCON_CFG_IRQCPU0(x)                    (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_IRQCPU0_SHIFT)) & MODCON_CFG_IRQCPU0_MASK)

#define MODCON_CFG_ISI_MASK                      (0x1U)
#define MODCON_CFG_ISI_SHIFT                     (0U)
/*! ISI - ISI
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_ISI(x)                        (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ISI_SHIFT)) & MODCON_CFG_ISI_MASK)

#define MODCON_CFG_ISI_V_AWCACHE_MASK            (0xFU)
#define MODCON_CFG_ISI_V_AWCACHE_SHIFT           (0U)
/*! ISI_V_AWCACHE - ISI_V AWCACHE Override Value */
#define MODCON_CFG_ISI_V_AWCACHE(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ISI_V_AWCACHE_SHIFT)) & MODCON_CFG_ISI_V_AWCACHE_MASK)

#define MODCON_CFG_JPEG_AWCACHE_MASK             (0xFU)
#define MODCON_CFG_JPEG_AWCACHE_SHIFT            (0U)
/*! JPEG_AWCACHE - JPEGDEC AWCACHE Override Value */
#define MODCON_CFG_JPEG_AWCACHE(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_JPEG_AWCACHE_SHIFT)) & MODCON_CFG_JPEG_AWCACHE_MASK)

#define MODCON_CFG_JPEG_DEC_MASK                 (0x1U)
#define MODCON_CFG_JPEG_DEC_SHIFT                (0U)
/*! JPEG_DEC - JPEGDEC
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_JPEG_DEC(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_JPEG_DEC_SHIFT)) & MODCON_CFG_JPEG_DEC_MASK)

#define MODCON_CFG_LPTX_MASK                     (0x1U)
#define MODCON_CFG_LPTX_SHIFT                    (0U)
/*! LPTX - LP-TX
 *  0b0..The highest impedance setting
 *  0b1..Mid-range impedance setting
 */
#define MODCON_CFG_LPTX(x)                       (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_LPTX_SHIFT)) & MODCON_CFG_LPTX_MASK)

#define MODCON_CFG_MAIN_AXBS0_MASK               (0x1U)
#define MODCON_CFG_MAIN_AXBS0_SHIFT              (0U)
/*! MAIN_AXBS0 - MAIN AXBS0
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_MAIN_AXBS0(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_MAIN_AXBS0_SHIFT)) & MODCON_CFG_MAIN_AXBS0_MASK)

#define MODCON_CFG_MAIN_CSYSREQ_MASK             (0x1U)
#define MODCON_CFG_MAIN_CSYSREQ_SHIFT            (0U)
/*! MAIN_CSYSREQ - MAIN_NIC Exit Low-power State Request
 *  0b0..In low-power state
 *  0b1..Exit low-power state
 */
#define MODCON_CFG_MAIN_CSYSREQ(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_MAIN_CSYSREQ_SHIFT)) & MODCON_CFG_MAIN_CSYSREQ_MASK)

#define MODCON_CFG_MEDIA_CSYSREQ_MASK            (0x1U)
#define MODCON_CFG_MEDIA_CSYSREQ_SHIFT           (0U)
/*! MEDIA_CSYSREQ - Request MEDIA_NIC to Exit Low-power State
 *  0b0..Request to enter low-power state
 *  0b1..Request to exit low-power state
 */
#define MODCON_CFG_MEDIA_CSYSREQ(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_MEDIA_CSYSREQ_SHIFT)) & MODCON_CFG_MEDIA_CSYSREQ_MASK)

#define MODCON_CFG_MQS_EN_MASK                   (0x1U)
#define MODCON_CFG_MQS_EN_SHIFT                  (0U)
/*! MQS_EN - MQS Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_MQS_EN(x)                     (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_MQS_EN_SHIFT)) & MODCON_CFG_MQS_EN_MASK)

#define MODCON_CFG_NB_COUNTER_RD_CFG_MASK        (0xFFFFFFFFU)
#define MODCON_CFG_NB_COUNTER_RD_CFG_SHIFT       (0U)
/*! NB_COUNTER_RD_CFG - Read Performance Counter Configuration */
#define MODCON_CFG_NB_COUNTER_RD_CFG(x)          (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_NB_COUNTER_RD_CFG_SHIFT)) & MODCON_CFG_NB_COUNTER_RD_CFG_MASK)

#define MODCON_CFG_NB_COUNTER_WR_CFG_MASK        (0xFFFFFFFFU)
#define MODCON_CFG_NB_COUNTER_WR_CFG_SHIFT       (0U)
/*! NB_COUNTER_WR_CFG - Write Performance Counter Configuration */
#define MODCON_CFG_NB_COUNTER_WR_CFG(x)          (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_NB_COUNTER_WR_CFG_SHIFT)) & MODCON_CFG_NB_COUNTER_WR_CFG_MASK)

#define MODCON_CFG_NPU_AWCACHE_MASK              (0xFU)
#define MODCON_CFG_NPU_AWCACHE_SHIFT             (0U)
/*! NPU_AWCACHE - NPU AWCACHE Override Value */
#define MODCON_CFG_NPU_AWCACHE(x)                (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_NPU_AWCACHE_SHIFT)) & MODCON_CFG_NPU_AWCACHE_MASK)

#define MODCON_CFG_OVERRIDE_IPG_MCLK_EN_MASK     (0x1U)
#define MODCON_CFG_OVERRIDE_IPG_MCLK_EN_SHIFT    (0U)
/*! OVERRIDE_IPG_MCLK_EN - Disable mclk Clock Dynamic Gate
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_OVERRIDE_IPG_MCLK_EN(x)       (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_OVERRIDE_IPG_MCLK_EN_SHIFT)) & MODCON_CFG_OVERRIDE_IPG_MCLK_EN_MASK)

#define MODCON_CFG_OVERRIDE_PE_CLK_EN_MASK       (0x1U)
#define MODCON_CFG_OVERRIDE_PE_CLK_EN_SHIFT      (0U)
/*! OVERRIDE_PE_CLK_EN - Override PE Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_OVERRIDE_PE_CLK_EN(x)         (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_OVERRIDE_PE_CLK_EN_SHIFT)) & MODCON_CFG_OVERRIDE_PE_CLK_EN_MASK)

#define MODCON_CFG_PERI_ROOTCLK0_MASK            (0x1U)
#define MODCON_CFG_PERI_ROOTCLK0_SHIFT           (0U)
/*! PERI_ROOTCLK0 - main_peri_rootclk0_div2 Select
 *  0b0..peri_rootclk0
 *  0b1..peri_rootclk0/2
 */
#define MODCON_CFG_PERI_ROOTCLK0(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_PERI_ROOTCLK0_SHIFT)) & MODCON_CFG_PERI_ROOTCLK0_MASK)

#define MODCON_CFG_PERI_ROOTCLK1_SEL_DIV2_MASK   (0x1U)
#define MODCON_CFG_PERI_ROOTCLK1_SEL_DIV2_SHIFT  (0U)
/*! PERI_ROOTCLK1_SEL_DIV2 - comm_peri_rootclk1_div2 Selection
 *  0b0..peri_rootclk1
 *  0b1..peri_rootclk1/2
 */
#define MODCON_CFG_PERI_ROOTCLK1_SEL_DIV2(x)     (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_PERI_ROOTCLK1_SEL_DIV2_SHIFT)) & MODCON_CFG_PERI_ROOTCLK1_SEL_DIV2_MASK)

#define MODCON_CFG_PMIC1V8_MASK                  (0x1U)
#define MODCON_CFG_PMIC1V8_SHIFT                 (0U)
/*! PMIC1V8 - PMIC 1V8 Power Supply
 *  0b0..Not available
 *  0b1..Available
 */
#define MODCON_CFG_PMIC1V8(x)                    (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_PMIC1V8_SHIFT)) & MODCON_CFG_PMIC1V8_MASK)

#define MODCON_CFG_PORT_GIPSP_B_MASK             (0x1U)
#define MODCON_CFG_PORT_GIPSP_B_SHIFT            (0U)
/*! PORT_GIPSP_B - Register Write Protect
 *  0b0..Protected
 *  0b1..Not Protect
 */
#define MODCON_CFG_PORT_GIPSP_B(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_PORT_GIPSP_B_SHIFT)) & MODCON_CFG_PORT_GIPSP_B_MASK)

#define MODCON_CFG_PWR_EN_MASK                   (0x1U)
#define MODCON_CFG_PWR_EN_SHIFT                  (0U)
/*! PWR_EN - Power Switch Enable
 *  0b0..Switch off
 *  0b1..Switch on
 */
#define MODCON_CFG_PWR_EN(x)                     (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_PWR_EN_SHIFT)) & MODCON_CFG_PWR_EN_MASK)

#define MODCON_CFG_SEL_MASK                      (0x1U)
#define MODCON_CFG_SEL_SHIFT                     (0U)
/*! SEL - Selection
 *  0b0..FRO_24M
 *  0b1..SXOSC_CLK
 */
#define MODCON_CFG_SEL(x)                        (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SEL_SHIFT)) & MODCON_CFG_SEL_MASK)

#define MODCON_CFG_SLEEP_DET_MASK                (0x1U)
#define MODCON_CFG_SLEEP_DET_SHIFT               (0U)
/*! SLEEP_DET - Sleep Supply_detection VDD3V3_USB
 *  0b0..Not enter
 *  0b1..Enter
 */
#define MODCON_CFG_SLEEP_DET(x)                  (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SLEEP_DET_SHIFT)) & MODCON_CFG_SLEEP_DET_MASK)

#define MODCON_CFG_SLEEP_DET0_MASK               (0x1U)
#define MODCON_CFG_SLEEP_DET0_SHIFT              (0U)
/*! SLEEP_DET0 - Sleep Supply_detection VDDIO1_1
 *  0b0..Not enter
 *  0b1..Enter
 */
#define MODCON_CFG_SLEEP_DET0(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SLEEP_DET0_SHIFT)) & MODCON_CFG_SLEEP_DET0_MASK)

#define MODCON_CFG_SOC_OUT_BUFFERABLE_EN_MASK    (0x1U)
#define MODCON_CFG_SOC_OUT_BUFFERABLE_EN_SHIFT   (0U)
/*! SOC_OUT_BUFFERABLE_EN - ELE AHB BUFFERABLE_EN Override
 *  0b0..Not override
 *  0b1..Override
 */
#define MODCON_CFG_SOC_OUT_BUFFERABLE_EN(x)      (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SOC_OUT_BUFFERABLE_EN_SHIFT)) & MODCON_CFG_SOC_OUT_BUFFERABLE_EN_MASK)

#define MODCON_CFG_SW_SEL_MASK                   (0x1U)
#define MODCON_CFG_SW_SEL_SHIFT                  (0U)
/*! SW_SEL - Select
 *  0b0..MAIN_SS power
 *  0b1..WAKE_SS power
 */
#define MODCON_CFG_SW_SEL(x)                     (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SW_SEL_SHIFT)) & MODCON_CFG_SW_SEL_MASK)

#define MODCON_CFG_USB_CRYSTAL_LESS_SEL_MASK     (0x1U)
#define MODCON_CFG_USB_CRYSTAL_LESS_SEL_SHIFT    (0U)
/*! USB_CRYSTAL_LESS_SEL - USB CRYSTAL_LESS Select
 *  0b0..USBHS
 *  0b1..USBFS
 */
#define MODCON_CFG_USB_CRYSTAL_LESS_SEL(x)       (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_USB_CRYSTAL_LESS_SEL_SHIFT)) & MODCON_CFG_USB_CRYSTAL_LESS_SEL_MASK)

#define MODCON_CFG_WDG_RESET_MASK                (0x1U)
#define MODCON_CFG_WDG_RESET_SHIFT               (0U)
/*! WDG_RESET - ELE WDOG Reset Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define MODCON_CFG_WDG_RESET(x)                  (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_WDG_RESET_SHIFT)) & MODCON_CFG_WDG_RESET_MASK)

#define MODCON_CFG_XENO_PHY_GLOBAL_ENABLE_MASK   (0x1U)
#define MODCON_CFG_XENO_PHY_GLOBAL_ENABLE_SHIFT  (0U)
/*! XENO_PHY_GLOBAL_ENABLE - TENBASET_PHY1 Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_XENO_PHY_GLOBAL_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_XENO_PHY_GLOBAL_ENABLE_SHIFT)) & MODCON_CFG_XENO_PHY_GLOBAL_ENABLE_MASK)

#define MODCON_CFG_initial_MASK                  (0x1U)
#define MODCON_CFG_initial_SHIFT                 (0U)
/*! initial - Initial
 *  0b0..Not initial
 *  0b1..Initial
 */
#define MODCON_CFG_initial(x)                    (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_initial_SHIFT)) & MODCON_CFG_initial_MASK)

#define MODCON_CFG_ulps_clk_active_MASK          (0x3FFU)
#define MODCON_CFG_ulps_clk_active_SHIFT         (0U)
/*! ulps_clk_active - Ultra Low Power State Clock Lane Active
 *  0b0..Not in Ultra Low-power state
 *  0b1..In Ultra Low-power state
 */
#define MODCON_CFG_ulps_clk_active(x)            (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ulps_clk_active_SHIFT)) & MODCON_CFG_ulps_clk_active_MASK)

#define MODCON_CFG_ulps_clk_enable_MASK          (0x1U)
#define MODCON_CFG_ulps_clk_enable_SHIFT         (0U)
/*! ulps_clk_enable - Ultra Low Power State Clock Lane Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_ulps_clk_enable(x)            (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ulps_clk_enable_SHIFT)) & MODCON_CFG_ulps_clk_enable_MASK)

#define MODCON_CFG_CF_WD_SCL_MASK                (0x1EU)
#define MODCON_CFG_CF_WD_SCL_SHIFT               (1U)
/*! CF_WD_SCL - Width of Glitch on SCL */
#define MODCON_CFG_CF_WD_SCL(x)                  (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_CF_WD_SCL_SHIFT)) & MODCON_CFG_CF_WD_SCL_MASK)

#define MODCON_CFG_DATA_EN_MASK                  (0x2U)
#define MODCON_CFG_DATA_EN_SHIFT                 (1U)
/*! DATA_EN - Data ISO Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_DATA_EN(x)                    (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_DATA_EN_SHIFT)) & MODCON_CFG_DATA_EN_MASK)

#define MODCON_CFG_ENET1G_REF_CLK_DIR_MASK       (0x2U)
#define MODCON_CFG_ENET1G_REF_CLK_DIR_SHIFT      (1U)
/*! ENET1G_REF_CLK_DIR - ENET Reference Clock Direction
 *  0b0..Input
 *  0b1..Output
 */
#define MODCON_CFG_ENET1G_REF_CLK_DIR(x)         (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ENET1G_REF_CLK_DIR_SHIFT)) & MODCON_CFG_ENET1G_REF_CLK_DIR_MASK)

#define MODCON_CFG_ENET_QOS_RGMII_EN_MASK        (0x2U)
#define MODCON_CFG_ENET_QOS_RGMII_EN_SHIFT       (1U)
/*! ENET_QOS_RGMII_EN - ENET_QOS RGMII TX Clock Output Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_ENET_QOS_RGMII_EN(x)          (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ENET_QOS_RGMII_EN_SHIFT)) & MODCON_CFG_ENET_QOS_RGMII_EN_MASK)

#define MODCON_CFG_EVENT_SYS_RESET_REQ_MASK      (0x2U)
#define MODCON_CFG_EVENT_SYS_RESET_REQ_SHIFT     (1U)
/*! EVENT_SYS_RESET_REQ - ELE Event Handler Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define MODCON_CFG_EVENT_SYS_RESET_REQ(x)        (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_EVENT_SYS_RESET_REQ_SHIFT)) & MODCON_CFG_EVENT_SYS_RESET_REQ_MASK)

#define MODCON_CFG_FORCE_INIT_DONE_MASK          (0x2U)
#define MODCON_CFG_FORCE_INIT_DONE_SHIFT         (1U)
/*! FORCE_INIT_DONE - Force Initiation Done
 *  0b0..Not force
 *  0b1..Force
 */
#define MODCON_CFG_FORCE_INIT_DONE(x)            (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_FORCE_INIT_DONE_SHIFT)) & MODCON_CFG_FORCE_INIT_DONE_MASK)

#define MODCON_CFG_LFRO32K_RDY_MASK              (0x2U)
#define MODCON_CFG_LFRO32K_RDY_SHIFT             (1U)
/*! LFRO32K_RDY - PMU FRO32K Ready
 *  0b0..Abnormal
 *  0b1..Normal
 */
#define MODCON_CFG_LFRO32K_RDY(x)                (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_LFRO32K_RDY_SHIFT)) & MODCON_CFG_LFRO32K_RDY_MASK)

#define MODCON_CFG_MAIN_AXBS1_MASK               (0x2U)
#define MODCON_CFG_MAIN_AXBS1_SHIFT              (1U)
/*! MAIN_AXBS1 - MAIN AXBS1
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_MAIN_AXBS1(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_MAIN_AXBS1_SHIFT)) & MODCON_CFG_MAIN_AXBS1_MASK)

#define MODCON_CFG_OVERRIDE_CHI_CLK_EN_MASK      (0x2U)
#define MODCON_CFG_OVERRIDE_CHI_CLK_EN_SHIFT     (1U)
/*! OVERRIDE_CHI_CLK_EN - Override CHI Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_OVERRIDE_CHI_CLK_EN(x)        (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_OVERRIDE_CHI_CLK_EN_SHIFT)) & MODCON_CFG_OVERRIDE_CHI_CLK_EN_MASK)

#define MODCON_CFG_PERI_ROOTCLK1_MASK            (0x2U)
#define MODCON_CFG_PERI_ROOTCLK1_SHIFT           (1U)
/*! PERI_ROOTCLK1 - main_peri_rootclk1_div2 Select
 *  0b0..peri_rootclk1
 *  0b1..peri_rootclk1/2
 */
#define MODCON_CFG_PERI_ROOTCLK1(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_PERI_ROOTCLK1_SHIFT)) & MODCON_CFG_PERI_ROOTCLK1_MASK)

#define MODCON_CFG_PERI_ROOTCLK2_SEL_DIV2_MASK   (0x2U)
#define MODCON_CFG_PERI_ROOTCLK2_SEL_DIV2_SHIFT  (1U)
/*! PERI_ROOTCLK2_SEL_DIV2 - comm_peri_rootclk2_div2 Selection
 *  0b0..peri_rootclk2
 *  0b1..peri_rootclk2/2
 */
#define MODCON_CFG_PERI_ROOTCLK2_SEL_DIV2(x)     (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_PERI_ROOTCLK2_SEL_DIV2_SHIFT)) & MODCON_CFG_PERI_ROOTCLK2_SEL_DIV2_MASK)

#define MODCON_CFG_SLEEP_DET1_MASK               (0x2U)
#define MODCON_CFG_SLEEP_DET1_SHIFT              (1U)
/*! SLEEP_DET1 - Sleep Supply_detection VDDIO1_4
 *  0b0..Not enter
 *  0b1..Enter
 */
#define MODCON_CFG_SLEEP_DET1(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SLEEP_DET1_SHIFT)) & MODCON_CFG_SLEEP_DET1_MASK)

#define MODCON_CFG_SW_MODE_MASK                  (0x2U)
#define MODCON_CFG_SW_MODE_SHIFT                 (1U)
/*! SW_MODE - Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_SW_MODE(x)                    (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SW_MODE_SHIFT)) & MODCON_CFG_SW_MODE_MASK)

#define MODCON_CFG_SW_RST_MASK                   (0x2U)
#define MODCON_CFG_SW_RST_SHIFT                  (1U)
/*! SW_RST - Reset
 *  0b0..Not Reset
 *  0b1..Reset
 */
#define MODCON_CFG_SW_RST(x)                     (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SW_RST_SHIFT)) & MODCON_CFG_SW_RST_MASK)

#define MODCON_CFG_periodic_MASK                 (0x2U)
#define MODCON_CFG_periodic_SHIFT                (1U)
/*! periodic - Periodic
 *  0b0..Not periodic
 *  0b1..Periodic
 */
#define MODCON_CFG_periodic(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_periodic_SHIFT)) & MODCON_CFG_periodic_MASK)

#define MODCON_CFG_ulps_active_MASK              (0xFFEU)
#define MODCON_CFG_ulps_active_SHIFT             (1U)
/*! ulps_active - Ultra Low Power State Data Lane Active
 *  0b00..Data lane 0 and data lane 1 are not in Ultra Low-power state
 *  0b01..Data lane 0 is in Ultra Low-power state, and data lane 1 is not in Ultra Low-power state
 *  0b10..Data lane 0 is not in Ultra Low-power state, and data lane 1 is in Ultra Low-power state
 *  0b11..Data lane 0 and data lane 1 are in Ultra Low-power state
 */
#define MODCON_CFG_ulps_active(x)                (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ulps_active_SHIFT)) & MODCON_CFG_ulps_active_MASK)

#define MODCON_CFG_ulps_enable_MASK              (0x6U)
#define MODCON_CFG_ulps_enable_SHIFT             (1U)
/*! ulps_enable - Ultra-Low Power State Data Lane Enable
 *  0b00..Disable data lane 0 and data lane 1 to be in Ultra Low-power state
 *  0b01..Enable data lane 0 and disable data lane 1 to be in Ultra Low-power state
 *  0b10..Disable data lane 0 and enable data lane 1 to be in Ultra Low-power state
 *  0b11..Enable data lane 0 and data lane 1 to be in Ultra Low-power state
 */
#define MODCON_CFG_ulps_enable(x)                (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ulps_enable_SHIFT)) & MODCON_CFG_ulps_enable_MASK)

#define MODCON_CFG_AHBS_MSFTOS_MASK              (0x4U)
#define MODCON_CFG_AHBS_MSFTOS_SHIFT             (2U)
/*! AHBS_MSFTOS - Fast2slow mode of ahb2ahb_ahbs */
#define MODCON_CFG_AHBS_MSFTOS(x)                (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_AHBS_MSFTOS_SHIFT)) & MODCON_CFG_AHBS_MSFTOS_MASK)

#define MODCON_CFG_BUCK_VDDCORE_PWM2PFM_AUTO_MASK (0x4U)
#define MODCON_CFG_BUCK_VDDCORE_PWM2PFM_AUTO_SHIFT (2U)
/*! BUCK_VDDCORE_PWM2PFM_AUTO - PWM to PFM Auto Switch
 *  0b0..Fixed
 *  0b1..Auto
 */
#define MODCON_CFG_BUCK_VDDCORE_PWM2PFM_AUTO(x)  (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_BUCK_VDDCORE_PWM2PFM_AUTO_SHIFT)) & MODCON_CFG_BUCK_VDDCORE_PWM2PFM_AUTO_MASK)

#define MODCON_CFG_COMMPFDX_ROOTCLK_SEL_DIV2_MASK (0x4U)
#define MODCON_CFG_COMMPFDX_ROOTCLK_SEL_DIV2_SHIFT (2U)
/*! COMMPFDX_ROOTCLK_SEL_DIV2 - commpfdx_rootclk_div2 Selection
 *  0b0..commpfdx_rootclk
 *  0b1..commpfdx_rootclk/2
 */
#define MODCON_CFG_COMMPFDX_ROOTCLK_SEL_DIV2(x)  (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_COMMPFDX_ROOTCLK_SEL_DIV2_SHIFT)) & MODCON_CFG_COMMPFDX_ROOTCLK_SEL_DIV2_MASK)

#define MODCON_CFG_ENET1G_RGMII_EN_MASK          (0x4U)
#define MODCON_CFG_ENET1G_RGMII_EN_SHIFT         (2U)
/*! ENET1G_RGMII_EN - ENET RGMII Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_ENET1G_RGMII_EN(x)            (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ENET1G_RGMII_EN_SHIFT)) & MODCON_CFG_ENET1G_RGMII_EN_MASK)

#define MODCON_CFG_LC_BRICKED_MASK               (0x4U)
#define MODCON_CFG_LC_BRICKED_SHIFT              (2U)
/*! LC_BRICKED - ELE LMDA Lifecycle Bricked Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define MODCON_CFG_LC_BRICKED(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_LC_BRICKED_SHIFT)) & MODCON_CFG_LC_BRICKED_MASK)

#define MODCON_CFG_MAINPFDX_ROOTCLK_MASK         (0x4U)
#define MODCON_CFG_MAINPFDX_ROOTCLK_SHIFT        (2U)
/*! MAINPFDX_ROOTCLK - mainpfdx_rootclk_div2 Select
 *  0b0..mainpfdx_rootclk
 *  0b1..mainpfdx_rootclk/2
 */
#define MODCON_CFG_MAINPFDX_ROOTCLK(x)           (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_MAINPFDX_ROOTCLK_SHIFT)) & MODCON_CFG_MAINPFDX_ROOTCLK_MASK)

#define MODCON_CFG_MAIN_SPLIT0_MASK              (0x4U)
#define MODCON_CFG_MAIN_SPLIT0_SHIFT             (2U)
/*! MAIN_SPLIT0 - MAIN SPLIT0
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_MAIN_SPLIT0(x)                (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_MAIN_SPLIT0_SHIFT)) & MODCON_CFG_MAIN_SPLIT0_MASK)

#define MODCON_CFG_OVERSAMPLE_MASK               (0x4U)
#define MODCON_CFG_OVERSAMPLE_SHIFT              (2U)
/*! OVERSAMPLE - Oversample Rate
 *  0b0..32
 *  0b1..64
 */
#define MODCON_CFG_OVERSAMPLE(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_OVERSAMPLE_SHIFT)) & MODCON_CFG_OVERSAMPLE_MASK)

#define MODCON_CFG_SLEEP_DET2_MASK               (0x4U)
#define MODCON_CFG_SLEEP_DET2_SHIFT              (2U)
/*! SLEEP_DET2 - Sleep mode for Supply_detection
 *  0b0..Not enter
 *  0b1..Enter
 */
#define MODCON_CFG_SLEEP_DET2(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SLEEP_DET2_SHIFT)) & MODCON_CFG_SLEEP_DET2_MASK)

#define MODCON_CFG_BUCK_VDDCORE_OCL_WARN_MASK    (0x8U)
#define MODCON_CFG_BUCK_VDDCORE_OCL_WARN_SHIFT   (3U)
/*! BUCK_VDDCORE_OCL_WARN - DCDC Over-current Limit Warning
 *  0b0..No warning
 *  0b1..Warning
 */
#define MODCON_CFG_BUCK_VDDCORE_OCL_WARN(x)      (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_BUCK_VDDCORE_OCL_WARN_SHIFT)) & MODCON_CFG_BUCK_VDDCORE_OCL_WARN_MASK)

#define MODCON_CFG_ENET_QOS_INTF_SEL_MASK        (0x38U)
#define MODCON_CFG_ENET_QOS_INTF_SEL_SHIFT       (3U)
/*! ENET_QOS_INTF_SEL - ENET_QOS PHY Interface Select */
#define MODCON_CFG_ENET_QOS_INTF_SEL(x)          (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ENET_QOS_INTF_SEL_SHIFT)) & MODCON_CFG_ENET_QOS_INTF_SEL_MASK)

#define MODCON_CFG_LMDA_SYS_FAIL_MASK            (0x8U)
#define MODCON_CFG_LMDA_SYS_FAIL_SHIFT           (3U)
/*! LMDA_SYS_FAIL - ELE System Failure Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define MODCON_CFG_LMDA_SYS_FAIL(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_LMDA_SYS_FAIL_SHIFT)) & MODCON_CFG_LMDA_SYS_FAIL_MASK)

#define MODCON_CFG_MAIN_SPLIT1_MASK              (0x8U)
#define MODCON_CFG_MAIN_SPLIT1_SHIFT             (3U)
/*! MAIN_SPLIT1 - MAIN SPLIT1
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_MAIN_SPLIT1(x)                (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_MAIN_SPLIT1_SHIFT)) & MODCON_CFG_MAIN_SPLIT1_MASK)

#define MODCON_CFG_SLEEP_DET3_MASK               (0x8U)
#define MODCON_CFG_SLEEP_DET3_SHIFT              (3U)
/*! SLEEP_DET3 - Sleep Supply_detection VDDIO3
 *  0b0..Not enter
 *  0b1..Enter
 */
#define MODCON_CFG_SLEEP_DET3(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SLEEP_DET3_SHIFT)) & MODCON_CFG_SLEEP_DET3_MASK)

#define MODCON_CFG_skewcal_active_MASK           (0x18U)
#define MODCON_CFG_skewcal_active_SHIFT          (3U)
/*! skewcal_active - Skew Calibration Data Lane Active
 *  0b00..Data lane 0 and data lane 1 are not engaged
 *  0b01..Data lane 0 is engaged, and data lane 1 is not engaged
 *  0b10..Data lane 0 is not engaged, and data lane 1 is engaged
 *  0b11..Data lane 0 and data lane 1 are engaged
 */
#define MODCON_CFG_skewcal_active(x)             (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_skewcal_active_SHIFT)) & MODCON_CFG_skewcal_active_MASK)

#define MODCON_CFG_EDMA0_ARCACHE_MASK            (0xF0U)
#define MODCON_CFG_EDMA0_ARCACHE_SHIFT           (4U)
/*! EDMA0_ARCACHE - EDMA5 ARCACHE Override Value */
#define MODCON_CFG_EDMA0_ARCACHE(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_EDMA0_ARCACHE_SHIFT)) & MODCON_CFG_EDMA0_ARCACHE_MASK)

#define MODCON_CFG_ENET1G_2_XENO_PINSEL_MASK     (0x10U)
#define MODCON_CFG_ENET1G_2_XENO_PINSEL_SHIFT    (4U)
/*! ENET1G_2_XENO_PINSEL - ENET XENO PHY PIN Selection
 *  0b0..Normal external PHY
 *  0b1..XENO PHY
 */
#define MODCON_CFG_ENET1G_2_XENO_PINSEL(x)       (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ENET1G_2_XENO_PINSEL_SHIFT)) & MODCON_CFG_ENET1G_2_XENO_PINSEL_MASK)

#define MODCON_CFG_HSP_SPLIT0_MASK               (0x10U)
#define MODCON_CFG_HSP_SPLIT0_SHIFT              (4U)
/*! HSP_SPLIT0 - HSP SPLIT0
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_HSP_SPLIT0(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_HSP_SPLIT0_SHIFT)) & MODCON_CFG_HSP_SPLIT0_MASK)

#define MODCON_CFG_JPEG_ARCACHE_MASK             (0xF0U)
#define MODCON_CFG_JPEG_ARCACHE_SHIFT            (4U)
/*! JPEG_ARCACHE - JPEGDEC ARCACHE Override Value */
#define MODCON_CFG_JPEG_ARCACHE(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_JPEG_ARCACHE_SHIFT)) & MODCON_CFG_JPEG_ARCACHE_MASK)

#define MODCON_CFG_NPU_ARCACHE_MASK              (0xF0U)
#define MODCON_CFG_NPU_ARCACHE_SHIFT             (4U)
/*! NPU_ARCACHE - NPU ARCACHE Override Value */
#define MODCON_CFG_NPU_ARCACHE(x)                (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_NPU_ARCACHE_SHIFT)) & MODCON_CFG_NPU_ARCACHE_MASK)

#define MODCON_CFG_PANIC_ARQOS_MASK              (0xF0U)
#define MODCON_CFG_PANIC_ARQOS_SHIFT             (4U)
/*! PANIC_ARQOS - Panic ArQoS */
#define MODCON_CFG_PANIC_ARQOS(x)                (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_PANIC_ARQOS_SHIFT)) & MODCON_CFG_PANIC_ARQOS_MASK)

#define MODCON_CFG_PANIC_AWQOS_Y_MASK            (0xF0U)
#define MODCON_CFG_PANIC_AWQOS_Y_SHIFT           (4U)
/*! PANIC_AWQOS_Y - Panic Address Write QoS for Port Y */
#define MODCON_CFG_PANIC_AWQOS_Y(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_PANIC_AWQOS_Y_SHIFT)) & MODCON_CFG_PANIC_AWQOS_Y_MASK)

#define MODCON_CFG_PMU_XTAL32K_RDY_MASK          (0x10U)
#define MODCON_CFG_PMU_XTAL32K_RDY_SHIFT         (4U)
/*! PMU_XTAL32K_RDY - PMU XTAL32K Ready
 *  0b0..Abnormal
 *  0b1..Normal
 */
#define MODCON_CFG_PMU_XTAL32K_RDY(x)            (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_PMU_XTAL32K_RDY_SHIFT)) & MODCON_CFG_PMU_XTAL32K_RDY_MASK)

#define MODCON_CFG_SLEEP_DET4_MASK               (0x10U)
#define MODCON_CFG_SLEEP_DET4_SHIFT              (4U)
/*! SLEEP_DET4 - Sleep Supply_detection VDDIO4
 *  0b0..Not enter
 *  0b1..Enter
 */
#define MODCON_CFG_SLEEP_DET4(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SLEEP_DET4_SHIFT)) & MODCON_CFG_SLEEP_DET4_MASK)

#define MODCON_CFG_CF_WD_SDA_MASK                (0x1E0U)
#define MODCON_CFG_CF_WD_SDA_SHIFT               (5U)
/*! CF_WD_SDA - Width of Glitch on SDA */
#define MODCON_CFG_CF_WD_SDA(x)                  (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_CF_WD_SDA_SHIFT)) & MODCON_CFG_CF_WD_SDA_MASK)

#define MODCON_CFG_CSSI_SPLIT0_MASK              (0x20U)
#define MODCON_CFG_CSSI_SPLIT0_SHIFT             (5U)
/*! CSSI_SPLIT0 - CSSI SPLIT0
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_CSSI_SPLIT0(x)                (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_CSSI_SPLIT0_SHIFT)) & MODCON_CFG_CSSI_SPLIT0_MASK)

#define MODCON_CFG_LMDA_RESET_REQ_MASK           (0x20U)
#define MODCON_CFG_LMDA_RESET_REQ_SHIFT          (5U)
/*! LMDA_RESET_REQ - ELE LMDA Reset Request Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define MODCON_CFG_LMDA_RESET_REQ(x)             (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_LMDA_RESET_REQ_SHIFT)) & MODCON_CFG_LMDA_RESET_REQ_MASK)

#define MODCON_CFG_SLEEP_DET5_MASK               (0x20U)
#define MODCON_CFG_SLEEP_DET5_SHIFT              (5U)
/*! SLEEP_DET5 - Sleep Supply_detection VDDIO5
 *  0b0..Not enter
 *  0b1..Enter
 */
#define MODCON_CFG_SLEEP_DET5(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SLEEP_DET5_SHIFT)) & MODCON_CFG_SLEEP_DET5_MASK)

#define MODCON_CFG_ENET_QOS_CLKGEN_EN_MASK       (0x40U)
#define MODCON_CFG_ENET_QOS_CLKGEN_EN_SHIFT      (6U)
/*! ENET_QOS_CLKGEN_EN - ENET_QOS Clock Generator Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_ENET_QOS_CLKGEN_EN(x)         (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ENET_QOS_CLKGEN_EN_SHIFT)) & MODCON_CFG_ENET_QOS_CLKGEN_EN_MASK)

#define MODCON_CFG_LMDA_32K_RESET_REQ_MASK       (0x40U)
#define MODCON_CFG_LMDA_32K_RESET_REQ_SHIFT      (6U)
/*! LMDA_32K_RESET_REQ - ELE LMDA 32K Clock Reset Request Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define MODCON_CFG_LMDA_32K_RESET_REQ(x)         (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_LMDA_32K_RESET_REQ_SHIFT)) & MODCON_CFG_LMDA_32K_RESET_REQ_MASK)

#define MODCON_CFG_ENET_QOS_EVENT0IN_SEL_MASK    (0x80U)
#define MODCON_CFG_ENET_QOS_EVENT0IN_SEL_SHIFT   (7U)
/*! ENET_QOS_EVENT0IN_SEL - ENET_QOS ENET_1588_EVENT0_IN Select
 *  0b0..From pad
 *  0b1..From GPT3_COMPARE1 output
 */
#define MODCON_CFG_ENET_QOS_EVENT0IN_SEL(x)      (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ENET_QOS_EVENT0IN_SEL_SHIFT)) & MODCON_CFG_ENET_QOS_EVENT0IN_SEL_MASK)

#define MODCON_CFG_FDET0_TCLK_ERR_IRQ_MASK       (0x80U)
#define MODCON_CFG_FDET0_TCLK_ERR_IRQ_SHIFT      (7U)
/*! FDET0_TCLK_ERR_IRQ - ELE FDET0 TCLK Stop Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define MODCON_CFG_FDET0_TCLK_ERR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_FDET0_TCLK_ERR_IRQ_SHIFT)) & MODCON_CFG_FDET0_TCLK_ERR_IRQ_MASK)

#define MODCON_CFG_AWQOS_U_MASK                  (0xF00U)
#define MODCON_CFG_AWQOS_U_SHIFT                 (8U)
/*! AWQOS_U - Address Write QoS for Port U */
#define MODCON_CFG_AWQOS_U(x)                    (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_AWQOS_U_SHIFT)) & MODCON_CFG_AWQOS_U_MASK)

#define MODCON_CFG_AXBS_AWCACHE_MASK             (0xF00U)
#define MODCON_CFG_AXBS_AWCACHE_SHIFT            (8U)
/*! AXBS_AWCACHE - MAIN_AXBS AWCACHE Override Value */
#define MODCON_CFG_AXBS_AWCACHE(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_AXBS_AWCACHE_SHIFT)) & MODCON_CFG_AXBS_AWCACHE_MASK)

#define MODCON_CFG_COMM_AWCACHE_MASK             (0xF00U)
#define MODCON_CFG_COMM_AWCACHE_SHIFT            (8U)
/*! COMM_AWCACHE - COMM masters AWCACHE override value */
#define MODCON_CFG_COMM_AWCACHE(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_COMM_AWCACHE_SHIFT)) & MODCON_CFG_COMM_AWCACHE_MASK)

#define MODCON_CFG_ELS_HALT_EXIT_IRQ_CLR_MASK    (0x100U)
#define MODCON_CFG_ELS_HALT_EXIT_IRQ_CLR_SHIFT   (8U)
/*! ELS_HALT_EXIT_IRQ_CLR - ELE Halt Exit Interrupt Clear
 *  0b0..Not clear
 *  0b1..Clear
 */
#define MODCON_CFG_ELS_HALT_EXIT_IRQ_CLR(x)      (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ELS_HALT_EXIT_IRQ_CLR_SHIFT)) & MODCON_CFG_ELS_HALT_EXIT_IRQ_CLR_MASK)

#define MODCON_CFG_ENET1G_DLY_TARGET_MASK        (0xF00U)
#define MODCON_CFG_ENET1G_DLY_TARGET_SHIFT       (8U)
/*! ENET1G_DLY_TARGET - ENET Delay Target */
#define MODCON_CFG_ENET1G_DLY_TARGET(x)          (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ENET1G_DLY_TARGET_SHIFT)) & MODCON_CFG_ENET1G_DLY_TARGET_MASK)

#define MODCON_CFG_ENET_QOS_DIS_CRC_CHK_MASK     (0x100U)
#define MODCON_CFG_ENET_QOS_DIS_CRC_CHK_SHIFT    (8U)
/*! ENET_QOS_DIS_CRC_CHK - ENET_QOS Disable CRC Check
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_ENET_QOS_DIS_CRC_CHK(x)       (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ENET_QOS_DIS_CRC_CHK_SHIFT)) & MODCON_CFG_ENET_QOS_DIS_CRC_CHK_MASK)

#define MODCON_CFG_FDET1_TCLK_ERR_IRQ_MASK       (0x100U)
#define MODCON_CFG_FDET1_TCLK_ERR_IRQ_SHIFT      (8U)
/*! FDET1_TCLK_ERR_IRQ - ELE FDET1 TCLK Stop Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define MODCON_CFG_FDET1_TCLK_ERR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_FDET1_TCLK_ERR_IRQ_SHIFT)) & MODCON_CFG_FDET1_TCLK_ERR_IRQ_MASK)

#define MODCON_CFG_ISI_U_AWCACHE_MASK            (0xF00U)
#define MODCON_CFG_ISI_U_AWCACHE_SHIFT           (8U)
/*! ISI_U_AWCACHE - ISI_U AWCACHE Override Value */
#define MODCON_CFG_ISI_U_AWCACHE(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ISI_U_AWCACHE_SHIFT)) & MODCON_CFG_ISI_U_AWCACHE_MASK)

#define MODCON_CFG_tx_active_MASK                (0x100U)
#define MODCON_CFG_tx_active_SHIFT               (8U)
/*! tx_active - TX Active
 *  0b0..Not active
 *  0b1..Active
 */
#define MODCON_CFG_tx_active(x)                  (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_tx_active_SHIFT)) & MODCON_CFG_tx_active_MASK)

#define MODCON_CFG_ELS_HALT_ACK_IRQ_CLR_MASK     (0x200U)
#define MODCON_CFG_ELS_HALT_ACK_IRQ_CLR_SHIFT    (9U)
/*! ELS_HALT_ACK_IRQ_CLR - ELE Halt ACK Interrupt Clear
 *  0b0..Not clear
 *  0b1..Clear
 */
#define MODCON_CFG_ELS_HALT_ACK_IRQ_CLR(x)       (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ELS_HALT_ACK_IRQ_CLR_SHIFT)) & MODCON_CFG_ELS_HALT_ACK_IRQ_CLR_MASK)

#define MODCON_CFG_ENET_QOS_2_XENO_PINSEL_MASK   (0x200U)
#define MODCON_CFG_ENET_QOS_2_XENO_PINSEL_SHIFT  (9U)
/*! ENET_QOS_2_XENO_PINSEL - ENET_QOS XENO PHY PIN Selection
 *  0b0..Normal external PHY interface.
 *  0b1..XENO PHY interface.
 */
#define MODCON_CFG_ENET_QOS_2_XENO_PINSEL(x)     (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ENET_QOS_2_XENO_PINSEL_SHIFT)) & MODCON_CFG_ENET_QOS_2_XENO_PINSEL_MASK)

#define MODCON_CFG_FDET2_TCLK_ERR_IRQ_MASK       (0x200U)
#define MODCON_CFG_FDET2_TCLK_ERR_IRQ_SHIFT      (9U)
/*! FDET2_TCLK_ERR_IRQ - ELE FDET2 TCLK Stop Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define MODCON_CFG_FDET2_TCLK_ERR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_FDET2_TCLK_ERR_IRQ_SHIFT)) & MODCON_CFG_FDET2_TCLK_ERR_IRQ_MASK)

#define MODCON_CFG_FDET3_TCLK_ERR_IRQ_MASK       (0x400U)
#define MODCON_CFG_FDET3_TCLK_ERR_IRQ_SHIFT      (10U)
/*! FDET3_TCLK_ERR_IRQ - ELE FDET3 TCLK Stop Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define MODCON_CFG_FDET3_TCLK_ERR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_FDET3_TCLK_ERR_IRQ_SHIFT)) & MODCON_CFG_FDET3_TCLK_ERR_IRQ_MASK)

#define MODCON_CFG_AXBS_ARCACHE_MASK             (0xF000U)
#define MODCON_CFG_AXBS_ARCACHE_SHIFT            (12U)
/*! AXBS_ARCACHE - MAIN_AXBS ARCACHE Override Value */
#define MODCON_CFG_AXBS_ARCACHE(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_AXBS_ARCACHE_SHIFT)) & MODCON_CFG_AXBS_ARCACHE_MASK)

#define MODCON_CFG_COMM_ARCACHE_MASK             (0xF000U)
#define MODCON_CFG_COMM_ARCACHE_SHIFT            (12U)
/*! COMM_ARCACHE - COMM_NIC Initiators ARCACHE Override Value */
#define MODCON_CFG_COMM_ARCACHE(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_COMM_ARCACHE_SHIFT)) & MODCON_CFG_COMM_ARCACHE_MASK)

#define MODCON_CFG_DCIF_ARCACHE_MASK             (0xF000U)
#define MODCON_CFG_DCIF_ARCACHE_SHIFT            (12U)
/*! DCIF_ARCACHE - DCIF ARCACHE Override Value */
#define MODCON_CFG_DCIF_ARCACHE(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_DCIF_ARCACHE_SHIFT)) & MODCON_CFG_DCIF_ARCACHE_MASK)

#define MODCON_CFG_PANIC_AWQOS_U_MASK            (0xF000U)
#define MODCON_CFG_PANIC_AWQOS_U_SHIFT           (12U)
/*! PANIC_AWQOS_U - Panic Address Write QoS for Port U */
#define MODCON_CFG_PANIC_AWQOS_U(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_PANIC_AWQOS_U_SHIFT)) & MODCON_CFG_PANIC_AWQOS_U_MASK)

#define MODCON_CFG_REF_LOCK_MASK                 (0x1000U)
#define MODCON_CFG_REF_LOCK_SHIFT                (12U)
/*! REF_LOCK - Reference Delay Line Lock
 *  0b0..Not locked
 *  0b1..Locked
 */
#define MODCON_CFG_REF_LOCK(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_REF_LOCK_SHIFT)) & MODCON_CFG_REF_LOCK_MASK)

#define MODCON_CFG_SLV_LOCK_MASK                 (0x2000U)
#define MODCON_CFG_SLV_LOCK_SHIFT                (13U)
/*! SLV_LOCK - Target Delay Line Lock
 *  0b0..Not locked
 *  0b1..Locked
 */
#define MODCON_CFG_SLV_LOCK(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SLV_LOCK_SHIFT)) & MODCON_CFG_SLV_LOCK_MASK)

#define MODCON_CFG_OVERRIDE_MODULE_CLKEN_MASK    (0x8000U)
#define MODCON_CFG_OVERRIDE_MODULE_CLKEN_SHIFT   (15U)
/*! OVERRIDE_MODULE_CLKEN - uSDHC1 Clock Dynamic Gate Override
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_OVERRIDE_MODULE_CLKEN(x)      (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_OVERRIDE_MODULE_CLKEN_SHIFT)) & MODCON_CFG_OVERRIDE_MODULE_CLKEN_MASK)

#define MODCON_CFG_AWQOS_V_MASK                  (0xF0000U)
#define MODCON_CFG_AWQOS_V_SHIFT                 (16U)
/*! AWQOS_V - Address Write QoS for Port V */
#define MODCON_CFG_AWQOS_V(x)                    (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_AWQOS_V_SHIFT)) & MODCON_CFG_AWQOS_V_MASK)

#define MODCON_CFG_BUF_WRITE_ERR_CLR_MASK        (0x10000U)
#define MODCON_CFG_BUF_WRITE_ERR_CLR_SHIFT       (16U)
/*! BUF_WRITE_ERR_CLR - BUF_WRITE_ERR Interrupt Clear
 *  0b0..Not Clear
 *  0b1..Clear
 */
#define MODCON_CFG_BUF_WRITE_ERR_CLR(x)          (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_BUF_WRITE_ERR_CLR_SHIFT)) & MODCON_CFG_BUF_WRITE_ERR_CLR_MASK)

#define MODCON_CFG_CLK_DIV_MASK                  (0xFF0000U)
#define MODCON_CFG_CLK_DIV_SHIFT                 (16U)
/*! CLK_DIV - Clock Divider
 *  0b00000000..1
 *  0b00000001..2
 *  0b00000010..3
 *  0b11111111..256
 */
#define MODCON_CFG_CLK_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_CLK_DIV_SHIFT)) & MODCON_CFG_CLK_DIV_MASK)

#define MODCON_CFG_COMM_CSYSACK_MASK             (0x10000U)
#define MODCON_CFG_COMM_CSYSACK_SHIFT            (16U)
/*! COMM_CSYSACK - Acknowledge Exit Low-power State Request
 *  0b0..Acknowledge enter the low-power state.
 *  0b1..Acknowledge exit from low-power state.
 */
#define MODCON_CFG_COMM_CSYSACK(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_COMM_CSYSACK_SHIFT)) & MODCON_CFG_COMM_CSYSACK_MASK)

#define MODCON_CFG_CSI_AWCACHE_MASK              (0xF0000U)
#define MODCON_CFG_CSI_AWCACHE_SHIFT             (16U)
/*! CSI_AWCACHE - CSI AWCACHE Override Value */
#define MODCON_CFG_CSI_AWCACHE(x)                (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_CSI_AWCACHE_SHIFT)) & MODCON_CFG_CSI_AWCACHE_MASK)

#define MODCON_CFG_ELS_LP_REQ_MASK               (0x10000U)
#define MODCON_CFG_ELS_LP_REQ_SHIFT              (16U)
/*! ELS_LP_REQ - Low-power Request
 *  0b0..Not send
 *  0b1..Send
 */
#define MODCON_CFG_ELS_LP_REQ(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ELS_LP_REQ_SHIFT)) & MODCON_CFG_ELS_LP_REQ_MASK)

#define MODCON_CFG_HALT_EXIT_MASK                (0x10000U)
#define MODCON_CFG_HALT_EXIT_SHIFT               (16U)
/*! HALT_EXIT - ELE Halt ACK Exit Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define MODCON_CFG_HALT_EXIT(x)                  (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_HALT_EXIT_SHIFT)) & MODCON_CFG_HALT_EXIT_MASK)

#define MODCON_CFG_ISI_AWCACHE_MASK              (0xF0000U)
#define MODCON_CFG_ISI_AWCACHE_SHIFT             (16U)
/*! ISI_AWCACHE - ISI AWCACHE Override Value */
#define MODCON_CFG_ISI_AWCACHE(x)                (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ISI_AWCACHE_SHIFT)) & MODCON_CFG_ISI_AWCACHE_MASK)

#define MODCON_CFG_MAIN_CSYSACK_MASK             (0x10000U)
#define MODCON_CFG_MAIN_CSYSACK_SHIFT            (16U)
/*! MAIN_CSYSACK - Acknowledge Exit Low-power State Request
 *  0b0..The request to enter the low-power state.
 *  0b1..The request to exit from low-power state.
 */
#define MODCON_CFG_MAIN_CSYSACK(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_MAIN_CSYSACK_SHIFT)) & MODCON_CFG_MAIN_CSYSACK_MASK)

#define MODCON_CFG_MEDIA_CSYSACK_MASK            (0x10000U)
#define MODCON_CFG_MEDIA_CSYSACK_SHIFT           (16U)
/*! MEDIA_CSYSACK - Acknowledge Exit Low-power State Request
 *  0b0..Acknowledge enter the low-power state.
 *  0b1..Acknowledge exit from low-power state.
 */
#define MODCON_CFG_MEDIA_CSYSACK(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_MEDIA_CSYSACK_SHIFT)) & MODCON_CFG_MEDIA_CSYSACK_MASK)

#define MODCON_CFG_SDA_LOW_IRQ_ENABLE_MASK       (0x10000U)
#define MODCON_CFG_SDA_LOW_IRQ_ENABLE_SHIFT      (16U)
/*! SDA_LOW_IRQ_ENABLE - Wakeup Interrupt On SDA Pulled Low Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_SDA_LOW_IRQ_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SDA_LOW_IRQ_ENABLE_SHIFT)) & MODCON_CFG_SDA_LOW_IRQ_ENABLE_MASK)

#define MODCON_CFG_SLEEP_REF_MASK                (0x10000U)
#define MODCON_CFG_SLEEP_REF_SHIFT               (16U)
/*! SLEEP_REF - Sleep Refgen VDD3V3_USB
 *  0b0..Not enter
 *  0b1..Enter
 */
#define MODCON_CFG_SLEEP_REF(x)                  (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SLEEP_REF_SHIFT)) & MODCON_CFG_SLEEP_REF_MASK)

#define MODCON_CFG_SLEEP_REF0_MASK               (0x10000U)
#define MODCON_CFG_SLEEP_REF0_SHIFT              (16U)
/*! SLEEP_REF0 - Sleep Refgen VDDIO1_1
 *  0b0..Not enter
 *  0b1..Enter
 */
#define MODCON_CFG_SLEEP_REF0(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SLEEP_REF0_SHIFT)) & MODCON_CFG_SLEEP_REF0_MASK)

#define MODCON_CFG_COMM_CACTIVE_MASK             (0x20000U)
#define MODCON_CFG_COMM_CACTIVE_SHIFT            (17U)
/*! COMM_CACTIVE - Clock Active
 *  0b0..Not active
 *  0b1..Acive
 */
#define MODCON_CFG_COMM_CACTIVE(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_COMM_CACTIVE_SHIFT)) & MODCON_CFG_COMM_CACTIVE_MASK)

#define MODCON_CFG_HALT_ACK_MASK                 (0x20000U)
#define MODCON_CFG_HALT_ACK_SHIFT                (17U)
/*! HALT_ACK - ELE Halt ACK Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define MODCON_CFG_HALT_ACK(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_HALT_ACK_SHIFT)) & MODCON_CFG_HALT_ACK_MASK)

#define MODCON_CFG_IRQ_DETECT_CLR_MASK           (0x20000U)
#define MODCON_CFG_IRQ_DETECT_CLR_SHIFT          (17U)
/*! IRQ_DETECT_CLR - Async Wakeup Interrupt Clear
 *  0b0..Not clear
 *  0b1..Clear
 */
#define MODCON_CFG_IRQ_DETECT_CLR(x)             (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_IRQ_DETECT_CLR_SHIFT)) & MODCON_CFG_IRQ_DETECT_CLR_MASK)

#define MODCON_CFG_MAIN_CACTIVE_MASK             (0x20000U)
#define MODCON_CFG_MAIN_CACTIVE_SHIFT            (17U)
/*! MAIN_CACTIVE - CATIVE Active
 *  0b0..Not active
 *  0b1..Acive
 */
#define MODCON_CFG_MAIN_CACTIVE(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_MAIN_CACTIVE_SHIFT)) & MODCON_CFG_MAIN_CACTIVE_MASK)

#define MODCON_CFG_MEDIA_CACTIVE_MASK            (0x20000U)
#define MODCON_CFG_MEDIA_CACTIVE_SHIFT           (17U)
/*! MEDIA_CACTIVE - Clock Active
 *  0b0..Not active
 *  0b1..Acive
 */
#define MODCON_CFG_MEDIA_CACTIVE(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_MEDIA_CACTIVE_SHIFT)) & MODCON_CFG_MEDIA_CACTIVE_MASK)

#define MODCON_CFG_SLEEP_REF1_MASK               (0x20000U)
#define MODCON_CFG_SLEEP_REF1_SHIFT              (17U)
/*! SLEEP_REF1 - Sleep Refgen VDDIO1_3
 *  0b0..Not enter
 *  0b1..Enter
 */
#define MODCON_CFG_SLEEP_REF1(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SLEEP_REF1_SHIFT)) & MODCON_CFG_SLEEP_REF1_MASK)

#define MODCON_CFG_SLEEP_REF2_MASK               (0x40000U)
#define MODCON_CFG_SLEEP_REF2_SHIFT              (18U)
/*! SLEEP_REF2 - Sleep VDDIO2
 *  0b0..Not enter
 *  0b1..Enter
 */
#define MODCON_CFG_SLEEP_REF2(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SLEEP_REF2_SHIFT)) & MODCON_CFG_SLEEP_REF2_MASK)

#define MODCON_CFG_SLEEP_REF3_MASK               (0x80000U)
#define MODCON_CFG_SLEEP_REF3_SHIFT              (19U)
/*! SLEEP_REF3 - Sleep VDDIO3
 *  0b0..Not enter
 *  0b1..Enter
 */
#define MODCON_CFG_SLEEP_REF3(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SLEEP_REF3_SHIFT)) & MODCON_CFG_SLEEP_REF3_MASK)

#define MODCON_CFG_CSI_ARCACHE_MASK              (0xF00000U)
#define MODCON_CFG_CSI_ARCACHE_SHIFT             (20U)
/*! CSI_ARCACHE - CSI ARCACHE Override Value */
#define MODCON_CFG_CSI_ARCACHE(x)                (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_CSI_ARCACHE_SHIFT)) & MODCON_CFG_CSI_ARCACHE_MASK)

#define MODCON_CFG_ISI_ARCACHE_MASK              (0xF00000U)
#define MODCON_CFG_ISI_ARCACHE_SHIFT             (20U)
/*! ISI_ARCACHE - ISI ARCACHE Override Value */
#define MODCON_CFG_ISI_ARCACHE(x)                (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ISI_ARCACHE_SHIFT)) & MODCON_CFG_ISI_ARCACHE_MASK)

#define MODCON_CFG_PANIC_AWQOS_V_MASK            (0xF00000U)
#define MODCON_CFG_PANIC_AWQOS_V_SHIFT           (20U)
/*! PANIC_AWQOS_V - Panic Address Write QoS for Port V */
#define MODCON_CFG_PANIC_AWQOS_V(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_PANIC_AWQOS_V_SHIFT)) & MODCON_CFG_PANIC_AWQOS_V_MASK)

#define MODCON_CFG_SLEEP_REF4_MASK               (0x100000U)
#define MODCON_CFG_SLEEP_REF4_SHIFT              (20U)
/*! SLEEP_REF4 - Sleep VDDIO4
 *  0b0..Not enter
 *  0b1..Enter
 */
#define MODCON_CFG_SLEEP_REF4(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SLEEP_REF4_SHIFT)) & MODCON_CFG_SLEEP_REF4_MASK)

#define MODCON_CFG_SLEEP_REF5_MASK               (0x200000U)
#define MODCON_CFG_SLEEP_REF5_SHIFT              (21U)
/*! SLEEP_REF5 - Sleep VDDIO5
 *  0b0..Not enter
 *  0b1..Enter
 */
#define MODCON_CFG_SLEEP_REF5(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_SLEEP_REF5_SHIFT)) & MODCON_CFG_SLEEP_REF5_MASK)

#define MODCON_CFG_ISI_V_OVERRIDE_DIS_MASK       (0x20000000U)
#define MODCON_CFG_ISI_V_OVERRIDE_DIS_SHIFT      (29U)
/*! ISI_V_OVERRIDE_DIS - ISI_V AxCACHE Override Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_ISI_V_OVERRIDE_DIS(x)         (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ISI_V_OVERRIDE_DIS_SHIFT)) & MODCON_CFG_ISI_V_OVERRIDE_DIS_MASK)

#define MODCON_CFG_JPEG_OVERRIDE_DIS_MASK        (0x20000000U)
#define MODCON_CFG_JPEG_OVERRIDE_DIS_SHIFT       (29U)
/*! JPEG_OVERRIDE_DIS - JPEGDEC AxCACHE Override Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_JPEG_OVERRIDE_DIS(x)          (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_JPEG_OVERRIDE_DIS_SHIFT)) & MODCON_CFG_JPEG_OVERRIDE_DIS_MASK)

#define MODCON_CFG_AXBS_OVERRIDE_DIS_MASK        (0x40000000U)
#define MODCON_CFG_AXBS_OVERRIDE_DIS_SHIFT       (30U)
/*! AXBS_OVERRIDE_DIS - MAIN_AXBS Initiator AxCACHE Override Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_AXBS_OVERRIDE_DIS(x)          (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_AXBS_OVERRIDE_DIS_SHIFT)) & MODCON_CFG_AXBS_OVERRIDE_DIS_MASK)

#define MODCON_CFG_DCIF_OVERRIDE_DIS_MASK        (0x40000000U)
#define MODCON_CFG_DCIF_OVERRIDE_DIS_SHIFT       (30U)
/*! DCIF_OVERRIDE_DIS - DCIF AxCACHE Override Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_DCIF_OVERRIDE_DIS(x)          (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_DCIF_OVERRIDE_DIS_SHIFT)) & MODCON_CFG_DCIF_OVERRIDE_DIS_MASK)

#define MODCON_CFG_ISI_U_OVERRIDE_DIS_MASK       (0x40000000U)
#define MODCON_CFG_ISI_U_OVERRIDE_DIS_SHIFT      (30U)
/*! ISI_U_OVERRIDE_DIS - ISI_U AxCACHE Override Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_ISI_U_OVERRIDE_DIS(x)         (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ISI_U_OVERRIDE_DIS_SHIFT)) & MODCON_CFG_ISI_U_OVERRIDE_DIS_MASK)

#define MODCON_CFG_NPU_OVERRIDE_DIS_MASK         (0x40000000U)
#define MODCON_CFG_NPU_OVERRIDE_DIS_SHIFT        (30U)
/*! NPU_OVERRIDE_DIS - NPU AxCACHE Override Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_NPU_OVERRIDE_DIS(x)           (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_NPU_OVERRIDE_DIS_SHIFT)) & MODCON_CFG_NPU_OVERRIDE_DIS_MASK)

#define MODCON_CFG_COMM_OVERRIDE_DIS_MASK        (0x80000000U)
#define MODCON_CFG_COMM_OVERRIDE_DIS_SHIFT       (31U)
/*! COMM_OVERRIDE_DIS - COMM_NIC AxCACHE Override Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_COMM_OVERRIDE_DIS(x)          (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_COMM_OVERRIDE_DIS_SHIFT)) & MODCON_CFG_COMM_OVERRIDE_DIS_MASK)

#define MODCON_CFG_CSI_OVERRIDE_DIS_MASK         (0x80000000U)
#define MODCON_CFG_CSI_OVERRIDE_DIS_SHIFT        (31U)
/*! CSI_OVERRIDE_DIS - CSI AxCACHE Override Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_CSI_OVERRIDE_DIS(x)           (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_CSI_OVERRIDE_DIS_SHIFT)) & MODCON_CFG_CSI_OVERRIDE_DIS_MASK)

#define MODCON_CFG_EDMA0_OVERRIDE_DIS_MASK       (0x80000000U)
#define MODCON_CFG_EDMA0_OVERRIDE_DIS_SHIFT      (31U)
/*! EDMA0_OVERRIDE_DIS - EDMA5 Initiator AxCACHE Override Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_EDMA0_OVERRIDE_DIS(x)         (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_EDMA0_OVERRIDE_DIS_SHIFT)) & MODCON_CFG_EDMA0_OVERRIDE_DIS_MASK)

#define MODCON_CFG_ISI_OVERRIDE_DIS_MASK         (0x80000000U)
#define MODCON_CFG_ISI_OVERRIDE_DIS_SHIFT        (31U)
/*! ISI_OVERRIDE_DIS - ISI AxCACHE Override Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define MODCON_CFG_ISI_OVERRIDE_DIS(x)           (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_ISI_OVERRIDE_DIS_SHIFT)) & MODCON_CFG_ISI_OVERRIDE_DIS_MASK)

#define MODCON_CFG_LOCK_MASK                     (0x80000000U)
#define MODCON_CFG_LOCK_SHIFT                    (31U)
/*! LOCK - Lock
 *  0b0..No Lock
 *  0b1..Lock
 */
#define MODCON_CFG_LOCK(x)                       (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_LOCK_SHIFT)) & MODCON_CFG_LOCK_MASK)

#define MODCON_CFG_NMIENCPU0_MASK                (0x80000000U)
#define MODCON_CFG_NMIENCPU0_SHIFT               (31U)
/*! NMIENCPU0 - NMI Source Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MODCON_CFG_NMIENCPU0(x)                  (((uint32_t)(((uint32_t)(x)) << MODCON_CFG_NMIENCPU0_SHIFT)) & MODCON_CFG_NMIENCPU0_MASK)
/*! @} */

/* The count of MODCON_CFG */
#define MODCON_CFG_COUNT                         (70U)

/* The count of MODCON_CFG */
#define MODCON_CFG_COUNT2                        (4U)

/*! @name STATUS - NPU Status..ELE Status */
/*! @{ */

#define MODCON_STATUS_CURRNS_MASK                (0x1U)
#define MODCON_STATUS_CURRNS_SHIFT               (0U)
/*! CURRNS - Security State of CM85 Processor
 *  0b0..In Secure state
 *  0b1..In Non-secure state
 */
#define MODCON_STATUS_CURRNS(x)                  (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_CURRNS_SHIFT)) & MODCON_STATUS_CURRNS_MASK)

#define MODCON_STATUS_CURRPRI_MASK               (0xFFU)
#define MODCON_STATUS_CURRPRI_SHIFT              (0U)
/*! CURRPRI - Interrupt Priority Level */
#define MODCON_STATUS_CURRPRI(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_CURRPRI_SHIFT)) & MODCON_STATUS_CURRPRI_MASK)

#define MODCON_STATUS_D0TCMMASTER_MASK           (0xFU)
#define MODCON_STATUS_D0TCMMASTER_SHIFT          (0U)
/*! D0TCMMASTER - D0TCMMASTER */
#define MODCON_STATUS_D0TCMMASTER(x)             (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_D0TCMMASTER_SHIFT)) & MODCON_STATUS_D0TCMMASTER_MASK)

#define MODCON_STATUS_DMEI0_MASK                 (0x3FFFFFFU)
#define MODCON_STATUS_DMEI0_SHIFT                (0U)
/*! DMEI0 - DMEI0 */
#define MODCON_STATUS_DMEI0(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_DMEI0_SHIFT)) & MODCON_STATUS_DMEI0_MASK)

#define MODCON_STATUS_DMEI1_MASK                 (0x3FFFFFFU)
#define MODCON_STATUS_DMEI1_SHIFT                (0U)
/*! DMEI1 - DMEI1 */
#define MODCON_STATUS_DMEI1(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_DMEI1_SHIFT)) & MODCON_STATUS_DMEI1_MASK)

#define MODCON_STATUS_IDLE_MASK                  (0x1U)
#define MODCON_STATUS_IDLE_SHIFT                 (0U)
/*! IDLE - Idle
 *  0b0..Busy
 *  0b1..Idle
 */
#define MODCON_STATUS_IDLE(x)                    (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_IDLE_SHIFT)) & MODCON_STATUS_IDLE_MASK)

#define MODCON_STATUS_INIT_DONE_MASK             (0x1U)
#define MODCON_STATUS_INIT_DONE_SHIFT            (0U)
/*! INIT_DONE - Initialization Done
 *  0b0..Not complete
 *  0b1..Complete
 */
#define MODCON_STATUS_INIT_DONE(x)               (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_INIT_DONE_SHIFT)) & MODCON_STATUS_INIT_DONE_MASK)

#define MODCON_STATUS_INIT_OCM_DONE_MASK         (0x1U)
#define MODCON_STATUS_INIT_OCM_DONE_SHIFT        (0U)
/*! INIT_OCM_DONE - Initialization Memory Done
 *  0b0..Not complete
 *  0b1..Complete
 */
#define MODCON_STATUS_INIT_OCM_DONE(x)           (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_INIT_OCM_DONE_SHIFT)) & MODCON_STATUS_INIT_OCM_DONE_MASK)

#define MODCON_STATUS_JTAG_ID_MASK               (0xFFFFFFFFU)
#define MODCON_STATUS_JTAG_ID_SHIFT              (0U)
/*! JTAG_ID - JTAG ID */
#define MODCON_STATUS_JTAG_ID(x)                 (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_JTAG_ID_SHIFT)) & MODCON_STATUS_JTAG_ID_MASK)

#define MODCON_STATUS_MINOR_MASK                 (0xFU)
#define MODCON_STATUS_MINOR_SHIFT                (0U)
/*! MINOR - Minor version */
#define MODCON_STATUS_MINOR(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_MINOR_SHIFT)) & MODCON_STATUS_MINOR_MASK)

#define MODCON_STATUS_NB_COUNTER_RD_STS_MASK     (0x3FFFFFFFU)
#define MODCON_STATUS_NB_COUNTER_RD_STS_SHIFT    (0U)
/*! NB_COUNTER_RD_STS - Read Performance Counter Status */
#define MODCON_STATUS_NB_COUNTER_RD_STS(x)       (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_NB_COUNTER_RD_STS_SHIFT)) & MODCON_STATUS_NB_COUNTER_RD_STS_MASK)

#define MODCON_STATUS_NB_COUNTER_WR_STS_MASK     (0x3FFFFFFFU)
#define MODCON_STATUS_NB_COUNTER_WR_STS_SHIFT    (0U)
/*! NB_COUNTER_WR_STS - Write Performance Counter Status */
#define MODCON_STATUS_NB_COUNTER_WR_STS(x)       (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_NB_COUNTER_WR_STS_SHIFT)) & MODCON_STATUS_NB_COUNTER_WR_STS_MASK)

#define MODCON_STATUS_WARM_RST_REQ_MASK          (0x1U)
#define MODCON_STATUS_WARM_RST_REQ_SHIFT         (0U)
/*! WARM_RST_REQ - ELE Warm Reset Request
 *  0b0..Not request
 *  0b1..Request
 */
#define MODCON_STATUS_WARM_RST_REQ(x)            (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_WARM_RST_REQ_SHIFT)) & MODCON_STATUS_WARM_RST_REQ_MASK)

#define MODCON_STATUS_CURRPC_MASK                (0xFFFFFFFEU)
#define MODCON_STATUS_CURRPC_SHIFT               (1U)
/*! CURRPC - Instruction Execution */
#define MODCON_STATUS_CURRPC(x)                  (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_CURRPC_SHIFT)) & MODCON_STATUS_CURRPC_MASK)

#define MODCON_STATUS_NPU_RESET_OUT_N_MASK       (0x2U)
#define MODCON_STATUS_NPU_RESET_OUT_N_SHIFT      (1U)
/*! NPU_RESET_OUT_N - NPU Out of Reset
 *  0b0..In reset
 *  0b1..Out of reset
 */
#define MODCON_STATUS_NPU_RESET_OUT_N(x)         (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_NPU_RESET_OUT_N_SHIFT)) & MODCON_STATUS_NPU_RESET_OUT_N_MASK)

#define MODCON_STATUS_D1TCMMASTER_MASK           (0xF0U)
#define MODCON_STATUS_D1TCMMASTER_SHIFT          (4U)
/*! D1TCMMASTER - D1TCMMASTER */
#define MODCON_STATUS_D1TCMMASTER(x)             (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_D1TCMMASTER_SHIFT)) & MODCON_STATUS_D1TCMMASTER_MASK)

#define MODCON_STATUS_D2TCMMASTER_MASK           (0xF00U)
#define MODCON_STATUS_D2TCMMASTER_SHIFT          (8U)
/*! D2TCMMASTER - D2TCMMASTER */
#define MODCON_STATUS_D2TCMMASTER(x)             (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_D2TCMMASTER_SHIFT)) & MODCON_STATUS_D2TCMMASTER_MASK)

#define MODCON_STATUS_INTNUM_MASK                (0x1FF00U)
#define MODCON_STATUS_INTNUM_SHIFT               (8U)
/*! INTNUM - Interrupt Number */
#define MODCON_STATUS_INTNUM(x)                  (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_INTNUM_SHIFT)) & MODCON_STATUS_INTNUM_MASK)

#define MODCON_STATUS_D3TCMMASTER_MASK           (0xF000U)
#define MODCON_STATUS_D3TCMMASTER_SHIFT          (12U)
/*! D3TCMMASTER - D3TCMMASTER */
#define MODCON_STATUS_D3TCMMASTER(x)             (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_D3TCMMASTER_SHIFT)) & MODCON_STATUS_D3TCMMASTER_MASK)

#define MODCON_STATUS_ITCMMASTER_MASK            (0xF0000U)
#define MODCON_STATUS_ITCMMASTER_SHIFT           (16U)
/*! ITCMMASTER - ITCMMASTER */
#define MODCON_STATUS_ITCMMASTER(x)              (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_ITCMMASTER_SHIFT)) & MODCON_STATUS_ITCMMASTER_MASK)

#define MODCON_STATUS_MAJOR_MASK                 (0xF0000U)
#define MODCON_STATUS_MAJOR_SHIFT                (16U)
/*! MAJOR - Major version */
#define MODCON_STATUS_MAJOR(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_MAJOR_SHIFT)) & MODCON_STATUS_MAJOR_MASK)

#define MODCON_STATUS_DMEL0_MASK                 (0x1C000000U)
#define MODCON_STATUS_DMEL0_SHIFT                (26U)
/*! DMEL0 - DMEL0 */
#define MODCON_STATUS_DMEL0(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_DMEL0_SHIFT)) & MODCON_STATUS_DMEL0_MASK)

#define MODCON_STATUS_DMEL1_MASK                 (0x1C000000U)
#define MODCON_STATUS_DMEL1_SHIFT                (26U)
/*! DMEL1 - DMEL1 */
#define MODCON_STATUS_DMEL1(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_DMEL1_SHIFT)) & MODCON_STATUS_DMEL1_MASK)

#define MODCON_STATUS_DMEV0_MASK                 (0x20000000U)
#define MODCON_STATUS_DMEV0_SHIFT                (29U)
/*! DMEV0 - DMEV0 */
#define MODCON_STATUS_DMEV0(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_DMEV0_SHIFT)) & MODCON_STATUS_DMEV0_MASK)

#define MODCON_STATUS_DMEV1_MASK                 (0x40000000U)
#define MODCON_STATUS_DMEV1_SHIFT                (30U)
/*! DMEV1 - DMEV1 */
#define MODCON_STATUS_DMEV1(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_DMEV1_SHIFT)) & MODCON_STATUS_DMEV1_MASK)

#define MODCON_STATUS_DMEV2_MASK                 (0x80000000U)
#define MODCON_STATUS_DMEV2_SHIFT                (31U)
/*! DMEV2 - DMEV2 */
#define MODCON_STATUS_DMEV2(x)                   (((uint32_t)(((uint32_t)(x)) << MODCON_STATUS_DMEV2_SHIFT)) & MODCON_STATUS_DMEV2_MASK)
/*! @} */

/* The count of MODCON_STATUS */
#define MODCON_STATUS_COUNT                      (70U)

/* The count of MODCON_STATUS */
#define MODCON_STATUS_COUNT2                     (5U)


/*!
 * @}
 */ /* end of group MODCON_Register_Masks */


/*!
 * @}
 */ /* end of group MODCON_Peripheral_Access_Layer */


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


#endif  /* PERI_MODCON_H_ */

