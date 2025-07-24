/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOMUXC1
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IOMUXC1.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOMUXC1
 *
 * CMSIS Peripheral Access Layer for IOMUXC1
 */

#if !defined(PERI_IOMUXC1_H_)
#define PERI_IOMUXC1_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
#if !defined(IOMUXC1_SW_MUX_CTL_PAD_T_)
#define IOMUXC1_SW_MUX_CTL_PAD_T_
/*!
 * @addtogroup iomuxc1_pads
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the IOMUXC1 SW_MUX_CTL_PAD
 *
 * Defines the enumeration for the IOMUXC1 SW_MUX_CTL_PAD collections.
 */
typedef enum _iomuxc1_sw_mux_ctl_pad
{
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC0 = 0U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC1 = 1U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC2 = 2U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC3 = 3U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC4 = 4U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC5 = 5U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC6 = 6U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC7 = 7U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC8 = 8U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC9 = 9U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC10 = 10U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC11 = 11U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC12 = 12U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC13 = 13U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC14 = 14U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC15 = 15U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC16 = 16U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC17 = 17U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC18 = 18U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTC19 = 19U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED0 = 20U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED1 = 21U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED2 = 22U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED3 = 23U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED4 = 24U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED5 = 25U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED6 = 26U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED7 = 27U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED8 = 28U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED9 = 29U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED10 = 30U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED11 = 31U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTD0 = 32U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTD1 = 33U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTD2 = 34U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTD3 = 35U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTD4 = 36U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTD5 = 37U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTD6 = 38U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTD7 = 39U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTD8 = 40U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTD9 = 41U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTD10 = 42U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTD11 = 43U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED12 = 44U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED13 = 45U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED14 = 46U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED15 = 47U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED16 = 48U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED17 = 49U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED18 = 50U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED19 = 51U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED20 = 52U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED21 = 53U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED22 = 54U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED23 = 55U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED24 = 56U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED25 = 57U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED26 = 58U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED27 = 59U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED28 = 60U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED29 = 61U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED30 = 62U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED31 = 63U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTE0 = 64U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTE1 = 65U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTE2 = 66U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTE3 = 67U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTE4 = 68U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTE5 = 69U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTE6 = 70U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTE7 = 71U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTE8 = 72U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTE9 = 73U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTE10 = 74U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTE11 = 75U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTE12 = 76U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTE13 = 77U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTE14 = 78U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTE15 = 79U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED32 = 80U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED33 = 81U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED34 = 82U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED35 = 83U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED36 = 84U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED37 = 85U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED38 = 86U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED39 = 87U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED40 = 88U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED41 = 89U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED42 = 90U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED43 = 91U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED44 = 92U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED45 = 93U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED46 = 94U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_RESERVED47 = 95U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF0 = 96U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF1 = 97U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF2 = 98U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF3 = 99U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF4 = 100U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF5 = 101U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF6 = 102U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF7 = 103U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF8 = 104U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF9 = 105U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF10 = 106U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF11 = 107U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF12 = 108U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF13 = 109U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF14 = 110U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF15 = 111U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF16 = 112U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF17 = 113U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF18 = 114U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC1_IOMUXC1_SW_MUX_CTL_PAD_PTF19 = 115U,  /**< IOMUXC SW_MUX_CTL_PAD index */
} iomuxc1_sw_mux_ctl_pad_t;
#endif /* IOMUXC1_SW_MUX_CTL_PAD_T_ */

#if !defined(IOMUXC1_SELECT_INPUT_T_)
#define IOMUXC1_SELECT_INPUT_T_
/*!
 * @brief Enumeration for the IOMUXC1 select input
 *
 * Defines the enumeration for the IOMUXC1 select input collections.
 */
typedef enum _iomuxc1_select_input
{
    kIOMUXC1_IOMUXC1_USDHC1_IPP_WP_ON_SELECT_INPUT = 0U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_D_IP_FLEXIO_SYN1_IPP_IND_FLEXIO0_SELECT_INPUT = 1U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_D_IP_FLEXIO_SYN1_IPP_IND_FLEXIO1_SELECT_INPUT = 2U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_D_IP_FLEXIO_SYN1_IPP_IND_FLEXIO2_SELECT_INPUT = 3U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_D_IP_FLEXIO_SYN1_IPP_IND_FLEXIO3_SELECT_INPUT = 4U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_D_IP_FLEXIO_SYN1_IPP_IND_FLEXIO4_SELECT_INPUT = 5U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_D_IP_FLEXIO_SYN1_IPP_IND_FLEXIO5_SELECT_INPUT = 6U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_D_IP_FLEXIO_SYN1_IPP_IND_FLEXIO6_SELECT_INPUT = 7U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_D_IP_FLEXIO_SYN1_IPP_IND_FLEXIO7_SELECT_INPUT = 8U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_D_IP_FLEXIO_SYN1_IPP_IND_FLEXIO8_SELECT_INPUT = 9U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_D_IP_FLEXIO_SYN1_IPP_IND_FLEXIO9_SELECT_INPUT = 10U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_D_IP_FLEXIO_SYN1_IPP_IND_FLEXIO10_SELECT_INPUT = 11U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_D_IP_FLEXIO_SYN1_IPP_IND_FLEXIO11_SELECT_INPUT = 12U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_D_IP_FLEXIO_SYN1_IPP_IND_FLEXIO12_SELECT_INPUT = 13U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_D_IP_FLEXIO_SYN1_IPP_IND_FLEXIO13_SELECT_INPUT = 14U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_D_IP_FLEXIO_SYN1_IPP_IND_FLEXIO14_SELECT_INPUT = 15U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_D_IP_FLEXIO_SYN1_IPP_IND_FLEXIO15_SELECT_INPUT = 16U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPUART4_IPP_IND_LPUART_CTS_B_SELECT_INPUT = 17U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPUART4_IPP_IND_LPUART_RXD_SELECT_INPUT = 18U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPUART4_IPP_IND_LPUART_TXD_SELECT_INPUT = 19U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPUART5_IPP_IND_LPUART_CTS_B_SELECT_INPUT = 20U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPUART5_IPP_IND_LPUART_RXD_SELECT_INPUT = 21U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPUART5_IPP_IND_LPUART_TXD_SELECT_INPUT = 22U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPUART6_IPP_IND_LPUART_CTS_B_SELECT_INPUT = 23U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPUART6_IPP_IND_LPUART_RXD_SELECT_INPUT = 24U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPUART6_IPP_IND_LPUART_TXD_SELECT_INPUT = 25U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPUART7_IPP_IND_LPUART_CTS_B_SELECT_INPUT = 26U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPUART7_IPP_IND_LPUART_RXD_SELECT_INPUT = 27U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPUART7_IPP_IND_LPUART_TXD_SELECT_INPUT = 28U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPI2C4_IPP_IND_LPI2C_HREQ_SELECT_INPUT = 29U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPI2C4_IPP_IND_LPI2C_SCL_SELECT_INPUT = 30U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPI2C4_IPP_IND_LPI2C_SDA_SELECT_INPUT = 31U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM4_IPP_IND_LPTPM_CH0_SELECT_INPUT = 32U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM4_IPP_IND_LPTPM_CH1_SELECT_INPUT = 33U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM4_IPP_IND_LPTPM_CH2_SELECT_INPUT = 34U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM4_IPP_IND_LPTPM_CH3_SELECT_INPUT = 35U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM4_IPP_IND_LPTPM_CH4_SELECT_INPUT = 36U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM4_IPP_IND_LPTPM_CH5_SELECT_INPUT = 37U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM4_IPP_IND_LPTPM_CLK_SELECT_INPUT = 38U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPSPI2_IPP_IND_LPSPI_PCS0_SELECT_INPUT = 39U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPSPI2_IPP_IND_LPSPI_PCS1_SELECT_INPUT = 40U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPSPI2_IPP_IND_LPSPI_PCS2_SELECT_INPUT = 41U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPSPI2_IPP_IND_LPSPI_PCS3_SELECT_INPUT = 42U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPSPI2_IPP_IND_LPSPI_SCK_SELECT_INPUT = 43U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPSPI2_IPP_IND_LPSPI_SDI_SELECT_INPUT = 44U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPSPI2_IPP_IND_LPSPI_SDO_SELECT_INPUT = 45U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPI2C5_IPP_IND_LPI2C_HREQ_SELECT_INPUT = 46U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPI2C5_IPP_IND_LPI2C_SCL_SELECT_INPUT = 47U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPI2C5_IPP_IND_LPI2C_SDA_SELECT_INPUT = 48U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM5_IPP_IND_LPTPM_CH0_SELECT_INPUT = 49U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM5_IPP_IND_LPTPM_CH1_SELECT_INPUT = 50U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM5_IPP_IND_LPTPM_CLK_SELECT_INPUT = 51U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM6_IPP_IND_LPTPM_CH0_SELECT_INPUT = 52U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM6_IPP_IND_LPTPM_CH1_SELECT_INPUT = 53U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM6_IPP_IND_LPTPM_CLK_SELECT_INPUT = 54U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM7_IPP_IND_LPTPM_CH0_SELECT_INPUT = 55U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM7_IPP_IND_LPTPM_CH1_SELECT_INPUT = 56U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM7_IPP_IND_LPTPM_CH2_SELECT_INPUT = 57U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM7_IPP_IND_LPTPM_CH3_SELECT_INPUT = 58U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM7_IPP_IND_LPTPM_CH4_SELECT_INPUT = 59U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM7_IPP_IND_LPTPM_CH5_SELECT_INPUT = 60U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPTPM7_IPP_IND_LPTPM_CLK_SELECT_INPUT = 61U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPI2C6_IPP_IND_LPI2C_HREQ_SELECT_INPUT = 62U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPI2C6_IPP_IND_LPI2C_SCL_SELECT_INPUT = 63U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPI2C6_IPP_IND_LPI2C_SDA_SELECT_INPUT = 64U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPI2C7_IPP_IND_LPI2C_HREQ_SELECT_INPUT = 65U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPI2C7_IPP_IND_LPI2C_SCL_SELECT_INPUT = 66U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPI2C7_IPP_IND_LPI2C_SDA_SELECT_INPUT = 67U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPSPI3_IPP_IND_LPSPI_PCS0_SELECT_INPUT = 68U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPSPI3_IPP_IND_LPSPI_PCS1_SELECT_INPUT = 69U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPSPI3_IPP_IND_LPSPI_PCS2_SELECT_INPUT = 70U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPSPI3_IPP_IND_LPSPI_PCS3_SELECT_INPUT = 71U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPSPI3_IPP_IND_LPSPI_SCK_SELECT_INPUT = 72U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPSPI3_IPP_IND_LPSPI_SDI_SELECT_INPUT = 73U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_LPSPI3_IPP_IND_LPSPI_SDO_SELECT_INPUT = 74U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_USDHC1_IPP_CARD_DET_SELECT_INPUT = 75U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_USBO2_ULP1_IPP_IND_OTG_OC_SELECT_INPUT = 76U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_USBO2_ULP1_IPP_IND_OTG2_OC_SELECT_INPUT = 77U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_DA_IP_HS_USB2PHY_28FDSOI_USB_ID_SELECT_INPUT = 78U, /**< IOMUXC select input index */
    kIOMUXC1_IOMUXC1_VIDEO_IN_IPP_IND_DE_SELECT_INPUT = 79U, /**< IOMUXC select input index */
} iomuxc1_select_input_t;

/* @} */
#endif /* IOMUXC1_SELECT_INPUT_T_ */


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
   -- IOMUXC1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC1_Peripheral_Access_Layer IOMUXC1 Peripheral Access Layer
 * @{
 */

/** IOMUXC1 - Size of Registers Arrays */
#define IOMUXC1_SW_MUX_CTL_PAD_COUNT              116u
#define IOMUXC1_SELECT_INPUT_COUNT                80u

/** IOMUXC1 - Register Layout Typedef */
typedef struct {
  __IO uint32_t SW_MUX_CTL_PAD[IOMUXC1_SW_MUX_CTL_PAD_COUNT]; /**< SW_MUX_CTL_PAD SW MUX Control Register, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[48];
  __IO uint32_t SELECT_INPUT[IOMUXC1_SELECT_INPUT_COUNT]; /**< N_SELECT_INPUT DAISY Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_1[92];
  __IO uint32_t SW_MUX_CTL_PAD_RESET1_b;           /**< SW_MUX_CTL_PAD_RESET1_b SW MUX Control Register, offset: 0x39C */
} IOMUXC1_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC1_Register_Masks IOMUXC1 Register Masks
 * @{
 */

/*! @name SW_MUX_CTL_PAD - SW_MUX_CTL_PAD SW MUX Control Register */
/*! @{ */

#define IOMUXC1_SW_MUX_CTL_PAD_PS_MASK           (0x1U)
#define IOMUXC1_SW_MUX_CTL_PAD_PS_SHIFT          (0U)
/*! PS - Pull Select Field
 *  0b0..pull-down
 *  0b1..pull-up
 */
#define IOMUXC1_SW_MUX_CTL_PAD_PS(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_PS_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_PS_MASK)

#define IOMUXC1_SW_MUX_CTL_PAD_PE_MASK           (0x2U)
#define IOMUXC1_SW_MUX_CTL_PAD_PE_SHIFT          (1U)
/*! PE - Pull-up Enable Field
 *  0b0..pull disabled
 *  0b1..pull enabled
 */
#define IOMUXC1_SW_MUX_CTL_PAD_PE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_PE_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_PE_MASK)

#define IOMUXC1_SW_MUX_CTL_PAD_SRE_MASK          (0x4U)
#define IOMUXC1_SW_MUX_CTL_PAD_SRE_SHIFT         (2U)
/*! SRE - Slew Rate Enable Field
 *  0b0..Standard
 *  0b1..Slow
 */
#define IOMUXC1_SW_MUX_CTL_PAD_SRE(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_SRE_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_SRE_MASK)

#define IOMUXC1_SW_MUX_CTL_PAD_ODE_MASK          (0x20U)
#define IOMUXC1_SW_MUX_CTL_PAD_ODE_SHIFT         (5U)
/*! ODE - Open-drain Enable Field
 *  0b0..Push-pull
 *  0b1..Open-drain
 */
#define IOMUXC1_SW_MUX_CTL_PAD_ODE(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_ODE_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_ODE_MASK)

#define IOMUXC1_SW_MUX_CTL_PAD_DSE_MASK          (0x40U)
#define IOMUXC1_SW_MUX_CTL_PAD_DSE_SHIFT         (6U)
/*! DSE - Drive Strength Enable Field
 *  0b0..Standard
 *  0b1..Hi Drive
 */
#define IOMUXC1_SW_MUX_CTL_PAD_DSE(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_DSE_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_DSE_MASK)

#define IOMUXC1_SW_MUX_CTL_PAD_MUX_MODE_MASK     (0xF00U)
#define IOMUXC1_SW_MUX_CTL_PAD_MUX_MODE_SHIFT    (8U)
/*! MUX_MODE - MUX Mode Select Field. */
#define IOMUXC1_SW_MUX_CTL_PAD_MUX_MODE(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_MUX_MODE_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_MUX_MODE_MASK)

#define IOMUXC1_SW_MUX_CTL_PAD_LK_MASK           (0x8000U)
#define IOMUXC1_SW_MUX_CTL_PAD_LK_SHIFT          (15U)
/*! LK - Lock Field
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define IOMUXC1_SW_MUX_CTL_PAD_LK(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_LK_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_LK_MASK)

#define IOMUXC1_SW_MUX_CTL_PAD_IBE_MASK          (0x10000U)
#define IOMUXC1_SW_MUX_CTL_PAD_IBE_SHIFT         (16U)
/*! IBE - Input Buffer Enable Field
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define IOMUXC1_SW_MUX_CTL_PAD_IBE(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_IBE_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_IBE_MASK)

#define IOMUXC1_SW_MUX_CTL_PAD_OBE_MASK          (0x20000U)
#define IOMUXC1_SW_MUX_CTL_PAD_OBE_SHIFT         (17U)
/*! OBE - Output Buffer Enable Field
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define IOMUXC1_SW_MUX_CTL_PAD_OBE(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_OBE_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_OBE_MASK)
/*! @} */

/*! @name SELECT_INPUT - N_SELECT_INPUT DAISY Register */
/*! @{ */

#define IOMUXC1_SELECT_INPUT_DAISY_MASK          (0x7U)
#define IOMUXC1_SELECT_INPUT_DAISY_SHIFT         (0U)
/*! DAISY - Selects source pad for Module Input Function. Refer to "Input SSS" column from "Input Mux" tab on IOMUX Sheet. */
#define IOMUXC1_SELECT_INPUT_DAISY(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SELECT_INPUT_DAISY_SHIFT)) & IOMUXC1_SELECT_INPUT_DAISY_MASK)

#define IOMUXC1_SELECT_INPUT_INVERSION_MASK      (0x8000U)
#define IOMUXC1_SELECT_INPUT_INVERSION_SHIFT     (15U)
/*! INVERSION - Control the inversion of the pad->module input
 *  0b0..Disable inversion.
 *  0b1..Enable inversion.
 */
#define IOMUXC1_SELECT_INPUT_INVERSION(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SELECT_INPUT_INVERSION_SHIFT)) & IOMUXC1_SELECT_INPUT_INVERSION_MASK)
/*! @} */

/*! @name SW_MUX_CTL_PAD_RESET1_b - SW_MUX_CTL_PAD_RESET1_b SW MUX Control Register */
/*! @{ */

#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_PS_MASK  (0x1U)
#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_PS_SHIFT (0U)
/*! PS - Pull Select Field
 *  0b0..pull-down
 *  0b1..pull-up
 */
#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_PS(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_PS_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_PS_MASK)

#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_PE_MASK  (0x2U)
#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_PE_SHIFT (1U)
/*! PE - Pull-up Enable Field
 *  0b0..pull disabled
 *  0b1..pull enabled
 */
#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_PE(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_PE_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_PE_MASK)

#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_SRE_MASK (0x4U)
#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_SRE_SHIFT (2U)
/*! SRE - Slew Rate Enable Field
 *  0b0..Standard
 *  0b1..Slow
 */
#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_SRE(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_SRE_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_SRE_MASK)

#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_ODE_MASK (0x20U)
#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_ODE_SHIFT (5U)
/*! ODE - Open-drain Enable Field
 *  0b0..Push-pull
 *  0b1..Open-drain
 */
#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_ODE(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_ODE_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_ODE_MASK)

#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_DSE_MASK (0x40U)
#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_DSE_SHIFT (6U)
/*! DSE - Drive Strength Enable Field
 *  0b0..Standard
 *  0b1..Hi Drive
 */
#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_DSE(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_DSE_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_DSE_MASK)

#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_LK_MASK  (0x8000U)
#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_LK_SHIFT (15U)
/*! LK - Lock Field
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_LK(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_LK_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_RESET1_b_LK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IOMUXC1_Register_Masks */


/*!
 * @}
 */ /* end of group IOMUXC1_Peripheral_Access_Layer */


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


#endif  /* PERI_IOMUXC1_H_ */

