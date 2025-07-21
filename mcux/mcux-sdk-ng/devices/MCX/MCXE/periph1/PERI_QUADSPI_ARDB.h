/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for QuadSPI_ARDB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_QuadSPI_ARDB.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for QuadSPI_ARDB
 *
 * CMSIS Peripheral Access Layer for QuadSPI_ARDB
 */

#if !defined(PERI_QUADSPI_ARDB_H_)
#define PERI_QUADSPI_ARDB_H_                     /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE31BMPB))
#include "MCXE31B_COMMON.h"
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
   -- QuadSPI_ARDB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QuadSPI_ARDB_Peripheral_Access_Layer QuadSPI_ARDB Peripheral Access Layer
 * @{
 */

/** QuadSPI_ARDB - Size of Registers Arrays */
#define QuadSPI_ARDB_ARDB_COUNT                   128u

/** QuadSPI_ARDB - Register Layout Typedef */
typedef struct {
  __I  uint32_t ARDB[QuadSPI_ARDB_ARDB_COUNT];     /**< AHB RX Data Buffer Register, array offset: 0x0, array step: 0x4 */
} QuadSPI_ARDB_Type;

/* ----------------------------------------------------------------------------
   -- QuadSPI_ARDB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QuadSPI_ARDB_Register_Masks QuadSPI_ARDB Register Masks
 * @{
 */

/*! @name ARDB - AHB RX Data Buffer Register */
/*! @{ */

#define QuadSPI_ARDB_ARDB_ARXD_MASK              (0xFFFFFFFFU)
#define QuadSPI_ARDB_ARDB_ARXD_SHIFT             (0U)
/*! ARXD - ARDB provided RX buffer data */
#define QuadSPI_ARDB_ARDB_ARXD(x)                (((uint32_t)(((uint32_t)(x)) << QuadSPI_ARDB_ARDB_ARXD_SHIFT)) & QuadSPI_ARDB_ARDB_ARXD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group QuadSPI_ARDB_Register_Masks */


/*!
 * @}
 */ /* end of group QuadSPI_ARDB_Peripheral_Access_Layer */


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


#endif  /* PERI_QUADSPI_ARDB_H_ */

