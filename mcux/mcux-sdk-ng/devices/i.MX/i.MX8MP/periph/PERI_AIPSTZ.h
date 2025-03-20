/*
** ###################################################################
**     Processors:          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 5.0, 2021-03-01
**     Build:               b240708
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AIPSTZ
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**
** ###################################################################
*/

/*!
 * @file AIPSTZ.h
 * @version 5.0
 * @date 2021-03-01
 * @brief CMSIS Peripheral Access Layer for AIPSTZ
 *
 * CMSIS Peripheral Access Layer for AIPSTZ
 */

#if !defined(AIPSTZ_H_)
#define AIPSTZ_H_                                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- AIPSTZ Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AIPSTZ_Peripheral_Access_Layer AIPSTZ Peripheral Access Layer
 * @{
 */

/** AIPSTZ - Register Layout Typedef */
typedef struct {
  __IO uint32_t MPR;                               /**< Master Priviledge Registers, offset: 0x0 */
       uint8_t RESERVED_0[60];
  __IO uint32_t OPACR;                             /**< Off-Platform Peripheral Access Control Registers, offset: 0x40 */
  __IO uint32_t OPACR1;                            /**< Off-Platform Peripheral Access Control Registers, offset: 0x44 */
  __IO uint32_t OPACR2;                            /**< Off-Platform Peripheral Access Control Registers, offset: 0x48 */
  __IO uint32_t OPACR3;                            /**< Off-Platform Peripheral Access Control Registers, offset: 0x4C */
  __IO uint32_t OPACR4;                            /**< Off-Platform Peripheral Access Control Registers, offset: 0x50 */
} AIPSTZ_Type;

/* ----------------------------------------------------------------------------
   -- AIPSTZ Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AIPSTZ_Register_Masks AIPSTZ Register Masks
 * @{
 */

/*! @name MPR - Master Priviledge Registers */
/*! @{ */

#define AIPSTZ_MPR_MPROT5_MASK                   (0xF00U)
#define AIPSTZ_MPR_MPROT5_SHIFT                  (8U)
/*! MPROT5
 *  0bxxx0..Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero) regardless of the hprot[1] access attribute.
 *  0bxxx1..Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used directly to determine ips_supervisor_access.
 *  0bxx0x..This master is not trusted for write accesses.
 *  0bxx1x..This master is trusted for write accesses.
 *  0bx0xx..This master is not trusted for read accesses.
 *  0bx1xx..This master is trusted for read accesses.
 *  0b1xxx..Write accesses from this master are allowed to be buffered
 */
#define AIPSTZ_MPR_MPROT5(x)                     (((uint32_t)(((uint32_t)(x)) << AIPSTZ_MPR_MPROT5_SHIFT)) & AIPSTZ_MPR_MPROT5_MASK)

#define AIPSTZ_MPR_MPROT3_MASK                   (0xF0000U)
#define AIPSTZ_MPR_MPROT3_SHIFT                  (16U)
/*! MPROT3
 *  0bxxx0..Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero) regardless of the hprot[1] access attribute.
 *  0bxxx1..Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used directly to determine ips_supervisor_access.
 *  0bxx0x..This master is not trusted for write accesses.
 *  0bxx1x..This master is trusted for write accesses.
 *  0bx0xx..This master is not trusted for read accesses.
 *  0bx1xx..This master is trusted for read accesses.
 *  0b1xxx..Write accesses from this master are allowed to be buffered
 */
#define AIPSTZ_MPR_MPROT3(x)                     (((uint32_t)(((uint32_t)(x)) << AIPSTZ_MPR_MPROT3_SHIFT)) & AIPSTZ_MPR_MPROT3_MASK)

#define AIPSTZ_MPR_MPROT2_MASK                   (0xF00000U)
#define AIPSTZ_MPR_MPROT2_SHIFT                  (20U)
/*! MPROT2
 *  0bxxx0..Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero) regardless of the hprot[1] access attribute.
 *  0bxxx1..Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used directly to determine ips_supervisor_access.
 *  0bxx0x..This master is not trusted for write accesses.
 *  0bxx1x..This master is trusted for write accesses.
 *  0bx0xx..This master is not trusted for read accesses.
 *  0bx1xx..This master is trusted for read accesses.
 *  0b1xxx..Write accesses from this master are allowed to be buffered
 */
#define AIPSTZ_MPR_MPROT2(x)                     (((uint32_t)(((uint32_t)(x)) << AIPSTZ_MPR_MPROT2_SHIFT)) & AIPSTZ_MPR_MPROT2_MASK)

#define AIPSTZ_MPR_MPROT1_MASK                   (0xF000000U)
#define AIPSTZ_MPR_MPROT1_SHIFT                  (24U)
/*! MPROT1
 *  0bxxx0..Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero) regardless of the hprot[1] access attribute.
 *  0bxxx1..Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used directly to determine ips_supervisor_access.
 *  0bxx0x..This master is not trusted for write accesses.
 *  0bxx1x..This master is trusted for write accesses.
 *  0bx0xx..This master is not trusted for read accesses.
 *  0bx1xx..This master is trusted for read accesses.
 *  0b1xxx..Write accesses from this master are allowed to be buffered
 */
#define AIPSTZ_MPR_MPROT1(x)                     (((uint32_t)(((uint32_t)(x)) << AIPSTZ_MPR_MPROT1_SHIFT)) & AIPSTZ_MPR_MPROT1_MASK)

#define AIPSTZ_MPR_MPROT0_MASK                   (0xF0000000U)
#define AIPSTZ_MPR_MPROT0_SHIFT                  (28U)
/*! MPROT0
 *  0bxxx0..Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero) regardless of the hprot[1] access attribute.
 *  0bxxx1..Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used directly to determine ips_supervisor_access.
 *  0bxx0x..This master is not trusted for write accesses.
 *  0bxx1x..This master is trusted for write accesses.
 *  0bx0xx..This master is not trusted for read accesses.
 *  0bx1xx..This master is trusted for read accesses.
 *  0b1xxx..Write accesses from this master are allowed to be buffered
 */
#define AIPSTZ_MPR_MPROT0(x)                     (((uint32_t)(((uint32_t)(x)) << AIPSTZ_MPR_MPROT0_SHIFT)) & AIPSTZ_MPR_MPROT0_MASK)
/*! @} */

/*! @name OPACR - Off-Platform Peripheral Access Control Registers */
/*! @{ */

#define AIPSTZ_OPACR_OPAC7_MASK                  (0xFU)
#define AIPSTZ_OPACR_OPAC7_SHIFT                 (0U)
/*! OPAC7
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR_OPAC7(x)                    (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR_OPAC7_SHIFT)) & AIPSTZ_OPACR_OPAC7_MASK)

#define AIPSTZ_OPACR_OPAC6_MASK                  (0xF0U)
#define AIPSTZ_OPACR_OPAC6_SHIFT                 (4U)
/*! OPAC6
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR_OPAC6(x)                    (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR_OPAC6_SHIFT)) & AIPSTZ_OPACR_OPAC6_MASK)

#define AIPSTZ_OPACR_OPAC5_MASK                  (0xF00U)
#define AIPSTZ_OPACR_OPAC5_SHIFT                 (8U)
/*! OPAC5
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR_OPAC5(x)                    (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR_OPAC5_SHIFT)) & AIPSTZ_OPACR_OPAC5_MASK)

#define AIPSTZ_OPACR_OPAC4_MASK                  (0xF000U)
#define AIPSTZ_OPACR_OPAC4_SHIFT                 (12U)
/*! OPAC4
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR_OPAC4(x)                    (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR_OPAC4_SHIFT)) & AIPSTZ_OPACR_OPAC4_MASK)

#define AIPSTZ_OPACR_OPAC3_MASK                  (0xF0000U)
#define AIPSTZ_OPACR_OPAC3_SHIFT                 (16U)
/*! OPAC3
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR_OPAC3(x)                    (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR_OPAC3_SHIFT)) & AIPSTZ_OPACR_OPAC3_MASK)

#define AIPSTZ_OPACR_OPAC2_MASK                  (0xF00000U)
#define AIPSTZ_OPACR_OPAC2_SHIFT                 (20U)
/*! OPAC2
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR_OPAC2(x)                    (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR_OPAC2_SHIFT)) & AIPSTZ_OPACR_OPAC2_MASK)

#define AIPSTZ_OPACR_OPAC1_MASK                  (0xF000000U)
#define AIPSTZ_OPACR_OPAC1_SHIFT                 (24U)
/*! OPAC1
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR_OPAC1(x)                    (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR_OPAC1_SHIFT)) & AIPSTZ_OPACR_OPAC1_MASK)

#define AIPSTZ_OPACR_OPAC0_MASK                  (0xF0000000U)
#define AIPSTZ_OPACR_OPAC0_SHIFT                 (28U)
/*! OPAC0
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR_OPAC0(x)                    (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR_OPAC0_SHIFT)) & AIPSTZ_OPACR_OPAC0_MASK)
/*! @} */

/*! @name OPACR1 - Off-Platform Peripheral Access Control Registers */
/*! @{ */

#define AIPSTZ_OPACR1_OPAC15_MASK                (0xFU)
#define AIPSTZ_OPACR1_OPAC15_SHIFT               (0U)
/*! OPAC15
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR1_OPAC15(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR1_OPAC15_SHIFT)) & AIPSTZ_OPACR1_OPAC15_MASK)

#define AIPSTZ_OPACR1_OPAC14_MASK                (0xF0U)
#define AIPSTZ_OPACR1_OPAC14_SHIFT               (4U)
/*! OPAC14
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR1_OPAC14(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR1_OPAC14_SHIFT)) & AIPSTZ_OPACR1_OPAC14_MASK)

#define AIPSTZ_OPACR1_OPAC13_MASK                (0xF00U)
#define AIPSTZ_OPACR1_OPAC13_SHIFT               (8U)
/*! OPAC13
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR1_OPAC13(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR1_OPAC13_SHIFT)) & AIPSTZ_OPACR1_OPAC13_MASK)

#define AIPSTZ_OPACR1_OPAC12_MASK                (0xF000U)
#define AIPSTZ_OPACR1_OPAC12_SHIFT               (12U)
/*! OPAC12
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR1_OPAC12(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR1_OPAC12_SHIFT)) & AIPSTZ_OPACR1_OPAC12_MASK)

#define AIPSTZ_OPACR1_OPAC11_MASK                (0xF0000U)
#define AIPSTZ_OPACR1_OPAC11_SHIFT               (16U)
/*! OPAC11
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR1_OPAC11(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR1_OPAC11_SHIFT)) & AIPSTZ_OPACR1_OPAC11_MASK)

#define AIPSTZ_OPACR1_OPAC10_MASK                (0xF00000U)
#define AIPSTZ_OPACR1_OPAC10_SHIFT               (20U)
/*! OPAC10
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR1_OPAC10(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR1_OPAC10_SHIFT)) & AIPSTZ_OPACR1_OPAC10_MASK)

#define AIPSTZ_OPACR1_OPAC9_MASK                 (0xF000000U)
#define AIPSTZ_OPACR1_OPAC9_SHIFT                (24U)
/*! OPAC9
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR1_OPAC9(x)                   (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR1_OPAC9_SHIFT)) & AIPSTZ_OPACR1_OPAC9_MASK)

#define AIPSTZ_OPACR1_OPAC8_MASK                 (0xF0000000U)
#define AIPSTZ_OPACR1_OPAC8_SHIFT                (28U)
/*! OPAC8
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR1_OPAC8(x)                   (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR1_OPAC8_SHIFT)) & AIPSTZ_OPACR1_OPAC8_MASK)
/*! @} */

/*! @name OPACR2 - Off-Platform Peripheral Access Control Registers */
/*! @{ */

#define AIPSTZ_OPACR2_OPAC23_MASK                (0xFU)
#define AIPSTZ_OPACR2_OPAC23_SHIFT               (0U)
/*! OPAC23
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR2_OPAC23(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR2_OPAC23_SHIFT)) & AIPSTZ_OPACR2_OPAC23_MASK)

#define AIPSTZ_OPACR2_OPAC22_MASK                (0xF0U)
#define AIPSTZ_OPACR2_OPAC22_SHIFT               (4U)
/*! OPAC22
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR2_OPAC22(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR2_OPAC22_SHIFT)) & AIPSTZ_OPACR2_OPAC22_MASK)

#define AIPSTZ_OPACR2_OPAC21_MASK                (0xF00U)
#define AIPSTZ_OPACR2_OPAC21_SHIFT               (8U)
/*! OPAC21
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR2_OPAC21(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR2_OPAC21_SHIFT)) & AIPSTZ_OPACR2_OPAC21_MASK)

#define AIPSTZ_OPACR2_OPAC20_MASK                (0xF000U)
#define AIPSTZ_OPACR2_OPAC20_SHIFT               (12U)
/*! OPAC20
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR2_OPAC20(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR2_OPAC20_SHIFT)) & AIPSTZ_OPACR2_OPAC20_MASK)

#define AIPSTZ_OPACR2_OPAC19_MASK                (0xF0000U)
#define AIPSTZ_OPACR2_OPAC19_SHIFT               (16U)
/*! OPAC19
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR2_OPAC19(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR2_OPAC19_SHIFT)) & AIPSTZ_OPACR2_OPAC19_MASK)

#define AIPSTZ_OPACR2_OPAC18_MASK                (0xF00000U)
#define AIPSTZ_OPACR2_OPAC18_SHIFT               (20U)
/*! OPAC18
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR2_OPAC18(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR2_OPAC18_SHIFT)) & AIPSTZ_OPACR2_OPAC18_MASK)

#define AIPSTZ_OPACR2_OPAC17_MASK                (0xF000000U)
#define AIPSTZ_OPACR2_OPAC17_SHIFT               (24U)
/*! OPAC17
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR2_OPAC17(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR2_OPAC17_SHIFT)) & AIPSTZ_OPACR2_OPAC17_MASK)

#define AIPSTZ_OPACR2_OPAC16_MASK                (0xF0000000U)
#define AIPSTZ_OPACR2_OPAC16_SHIFT               (28U)
/*! OPAC16
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR2_OPAC16(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR2_OPAC16_SHIFT)) & AIPSTZ_OPACR2_OPAC16_MASK)
/*! @} */

/*! @name OPACR3 - Off-Platform Peripheral Access Control Registers */
/*! @{ */

#define AIPSTZ_OPACR3_OPAC31_MASK                (0xFU)
#define AIPSTZ_OPACR3_OPAC31_SHIFT               (0U)
/*! OPAC31
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR3_OPAC31(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR3_OPAC31_SHIFT)) & AIPSTZ_OPACR3_OPAC31_MASK)

#define AIPSTZ_OPACR3_OPAC30_MASK                (0xF0U)
#define AIPSTZ_OPACR3_OPAC30_SHIFT               (4U)
/*! OPAC30
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR3_OPAC30(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR3_OPAC30_SHIFT)) & AIPSTZ_OPACR3_OPAC30_MASK)

#define AIPSTZ_OPACR3_OPAC29_MASK                (0xF00U)
#define AIPSTZ_OPACR3_OPAC29_SHIFT               (8U)
/*! OPAC29
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR3_OPAC29(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR3_OPAC29_SHIFT)) & AIPSTZ_OPACR3_OPAC29_MASK)

#define AIPSTZ_OPACR3_OPAC28_MASK                (0xF000U)
#define AIPSTZ_OPACR3_OPAC28_SHIFT               (12U)
/*! OPAC28
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR3_OPAC28(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR3_OPAC28_SHIFT)) & AIPSTZ_OPACR3_OPAC28_MASK)

#define AIPSTZ_OPACR3_OPAC27_MASK                (0xF0000U)
#define AIPSTZ_OPACR3_OPAC27_SHIFT               (16U)
/*! OPAC27
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR3_OPAC27(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR3_OPAC27_SHIFT)) & AIPSTZ_OPACR3_OPAC27_MASK)

#define AIPSTZ_OPACR3_OPAC26_MASK                (0xF00000U)
#define AIPSTZ_OPACR3_OPAC26_SHIFT               (20U)
/*! OPAC26
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR3_OPAC26(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR3_OPAC26_SHIFT)) & AIPSTZ_OPACR3_OPAC26_MASK)

#define AIPSTZ_OPACR3_OPAC25_MASK                (0xF000000U)
#define AIPSTZ_OPACR3_OPAC25_SHIFT               (24U)
/*! OPAC25
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR3_OPAC25(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR3_OPAC25_SHIFT)) & AIPSTZ_OPACR3_OPAC25_MASK)

#define AIPSTZ_OPACR3_OPAC24_MASK                (0xF0000000U)
#define AIPSTZ_OPACR3_OPAC24_SHIFT               (28U)
/*! OPAC24
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR3_OPAC24(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR3_OPAC24_SHIFT)) & AIPSTZ_OPACR3_OPAC24_MASK)
/*! @} */

/*! @name OPACR4 - Off-Platform Peripheral Access Control Registers */
/*! @{ */

#define AIPSTZ_OPACR4_OPAC33_MASK                (0xF000000U)
#define AIPSTZ_OPACR4_OPAC33_SHIFT               (24U)
/*! OPAC33
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR4_OPAC33(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR4_OPAC33_SHIFT)) & AIPSTZ_OPACR4_OPAC33_MASK)

#define AIPSTZ_OPACR4_OPAC32_MASK                (0xF0000000U)
#define AIPSTZ_OPACR4_OPAC32_SHIFT               (28U)
/*! OPAC32
 *  0bxxx0..Accesses from an untrusted master are allowed.
 *  0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *          the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
 *  0bxx0x..This peripheral allows write accesses.
 *  0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *          error response and no peripheral access is initiated on the IPS bus.
 *  0bx0xx..This peripheral does not require supervisor privilege level for accesses.
 *  0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *          indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
 *          be set. If not, the access is terminated with an error response and no peripheral access is initiated
 *          on the IPS bus.
 *  0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */
#define AIPSTZ_OPACR4_OPAC32(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR4_OPAC32_SHIFT)) & AIPSTZ_OPACR4_OPAC32_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AIPSTZ_Register_Masks */


/*!
 * @}
 */ /* end of group AIPSTZ_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* AIPSTZ_H_ */

