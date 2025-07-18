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
**         CMSIS Peripheral Access Layer for AIPSTZ
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
 * @file PERI_AIPSTZ.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AIPSTZ
 *
 * CMSIS Peripheral Access Layer for AIPSTZ
 */

#if !defined(PERI_AIPSTZ_H_)
#define PERI_AIPSTZ_H_                           /**< Symbol preventing repeated inclusion */

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
   -- AIPSTZ Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AIPSTZ_Peripheral_Access_Layer AIPSTZ Peripheral Access Layer
 * @{
 */

/** AIPSTZ - Register Layout Typedef */
typedef struct {
  __IO uint32_t MPR;                               /**< MPR, offset: 0x0 */
       uint8_t RESERVED_0[60];
  __IO uint32_t OPACR;                             /**< OPACR, offset: 0x40 */
  __IO uint32_t OPACR1;                            /**< OPACR1, offset: 0x44 */
  __IO uint32_t OPACR2;                            /**< OPACR2, offset: 0x48 */
  __IO uint32_t OPACR3;                            /**< OPACR3, offset: 0x4C */
  __IO uint32_t OPACR4;                            /**< OPACR4, offset: 0x50 */
} AIPSTZ_Type;

/* ----------------------------------------------------------------------------
   -- AIPSTZ Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AIPSTZ_Register_Masks AIPSTZ Register Masks
 * @{
 */

/*! @name MPR - MPR */
/*! @{ */

#define AIPSTZ_MPR_MPROT5_MASK                   (0xF00U)
#define AIPSTZ_MPR_MPROT5_SHIFT                  (8U)
/*! MPROT5 - MPROT5. */
#define AIPSTZ_MPR_MPROT5(x)                     (((uint32_t)(((uint32_t)(x)) << AIPSTZ_MPR_MPROT5_SHIFT)) & AIPSTZ_MPR_MPROT5_MASK)

#define AIPSTZ_MPR_MPROT3_MASK                   (0xF0000U)
#define AIPSTZ_MPR_MPROT3_SHIFT                  (16U)
/*! MPROT3 - MPROT3. */
#define AIPSTZ_MPR_MPROT3(x)                     (((uint32_t)(((uint32_t)(x)) << AIPSTZ_MPR_MPROT3_SHIFT)) & AIPSTZ_MPR_MPROT3_MASK)

#define AIPSTZ_MPR_MPROT2_MASK                   (0xF00000U)
#define AIPSTZ_MPR_MPROT2_SHIFT                  (20U)
/*! MPROT2 - MPROT2. */
#define AIPSTZ_MPR_MPROT2(x)                     (((uint32_t)(((uint32_t)(x)) << AIPSTZ_MPR_MPROT2_SHIFT)) & AIPSTZ_MPR_MPROT2_MASK)

#define AIPSTZ_MPR_MPROT1_MASK                   (0xF000000U)
#define AIPSTZ_MPR_MPROT1_SHIFT                  (24U)
/*! MPROT1 - MPROT1. */
#define AIPSTZ_MPR_MPROT1(x)                     (((uint32_t)(((uint32_t)(x)) << AIPSTZ_MPR_MPROT1_SHIFT)) & AIPSTZ_MPR_MPROT1_MASK)

#define AIPSTZ_MPR_MPROT0_MASK                   (0xF0000000U)
#define AIPSTZ_MPR_MPROT0_SHIFT                  (28U)
/*! MPROT0 - MPROT0. */
#define AIPSTZ_MPR_MPROT0(x)                     (((uint32_t)(((uint32_t)(x)) << AIPSTZ_MPR_MPROT0_SHIFT)) & AIPSTZ_MPR_MPROT0_MASK)
/*! @} */

/*! @name OPACR - OPACR */
/*! @{ */

#define AIPSTZ_OPACR_OPAC7_MASK                  (0xFU)
#define AIPSTZ_OPACR_OPAC7_SHIFT                 (0U)
/*! OPAC7 - OPAC7. */
#define AIPSTZ_OPACR_OPAC7(x)                    (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR_OPAC7_SHIFT)) & AIPSTZ_OPACR_OPAC7_MASK)

#define AIPSTZ_OPACR_OPAC6_MASK                  (0xF0U)
#define AIPSTZ_OPACR_OPAC6_SHIFT                 (4U)
/*! OPAC6 - OPAC6. */
#define AIPSTZ_OPACR_OPAC6(x)                    (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR_OPAC6_SHIFT)) & AIPSTZ_OPACR_OPAC6_MASK)

#define AIPSTZ_OPACR_OPAC5_MASK                  (0xF00U)
#define AIPSTZ_OPACR_OPAC5_SHIFT                 (8U)
/*! OPAC5 - OPAC5. */
#define AIPSTZ_OPACR_OPAC5(x)                    (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR_OPAC5_SHIFT)) & AIPSTZ_OPACR_OPAC5_MASK)

#define AIPSTZ_OPACR_OPAC4_MASK                  (0xF000U)
#define AIPSTZ_OPACR_OPAC4_SHIFT                 (12U)
/*! OPAC4 - OPAC4. */
#define AIPSTZ_OPACR_OPAC4(x)                    (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR_OPAC4_SHIFT)) & AIPSTZ_OPACR_OPAC4_MASK)

#define AIPSTZ_OPACR_OPAC3_MASK                  (0xF0000U)
#define AIPSTZ_OPACR_OPAC3_SHIFT                 (16U)
/*! OPAC3 - OPAC3. */
#define AIPSTZ_OPACR_OPAC3(x)                    (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR_OPAC3_SHIFT)) & AIPSTZ_OPACR_OPAC3_MASK)

#define AIPSTZ_OPACR_OPAC2_MASK                  (0xF00000U)
#define AIPSTZ_OPACR_OPAC2_SHIFT                 (20U)
/*! OPAC2 - OPAC2. */
#define AIPSTZ_OPACR_OPAC2(x)                    (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR_OPAC2_SHIFT)) & AIPSTZ_OPACR_OPAC2_MASK)

#define AIPSTZ_OPACR_OPAC1_MASK                  (0xF000000U)
#define AIPSTZ_OPACR_OPAC1_SHIFT                 (24U)
/*! OPAC1 - OPAC1. */
#define AIPSTZ_OPACR_OPAC1(x)                    (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR_OPAC1_SHIFT)) & AIPSTZ_OPACR_OPAC1_MASK)

#define AIPSTZ_OPACR_OPAC0_MASK                  (0xF0000000U)
#define AIPSTZ_OPACR_OPAC0_SHIFT                 (28U)
/*! OPAC0 - OPAC0. */
#define AIPSTZ_OPACR_OPAC0(x)                    (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR_OPAC0_SHIFT)) & AIPSTZ_OPACR_OPAC0_MASK)
/*! @} */

/*! @name OPACR1 - OPACR1 */
/*! @{ */

#define AIPSTZ_OPACR1_OPAC15_MASK                (0xFU)
#define AIPSTZ_OPACR1_OPAC15_SHIFT               (0U)
/*! OPAC15 - OPAC15. */
#define AIPSTZ_OPACR1_OPAC15(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR1_OPAC15_SHIFT)) & AIPSTZ_OPACR1_OPAC15_MASK)

#define AIPSTZ_OPACR1_OPAC14_MASK                (0xF0U)
#define AIPSTZ_OPACR1_OPAC14_SHIFT               (4U)
/*! OPAC14 - OPAC14. */
#define AIPSTZ_OPACR1_OPAC14(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR1_OPAC14_SHIFT)) & AIPSTZ_OPACR1_OPAC14_MASK)

#define AIPSTZ_OPACR1_OPAC13_MASK                (0xF00U)
#define AIPSTZ_OPACR1_OPAC13_SHIFT               (8U)
/*! OPAC13 - OPAC13. */
#define AIPSTZ_OPACR1_OPAC13(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR1_OPAC13_SHIFT)) & AIPSTZ_OPACR1_OPAC13_MASK)

#define AIPSTZ_OPACR1_OPAC12_MASK                (0xF000U)
#define AIPSTZ_OPACR1_OPAC12_SHIFT               (12U)
/*! OPAC12 - OPAC12. */
#define AIPSTZ_OPACR1_OPAC12(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR1_OPAC12_SHIFT)) & AIPSTZ_OPACR1_OPAC12_MASK)

#define AIPSTZ_OPACR1_OPAC11_MASK                (0xF0000U)
#define AIPSTZ_OPACR1_OPAC11_SHIFT               (16U)
/*! OPAC11 - OPAC11. */
#define AIPSTZ_OPACR1_OPAC11(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR1_OPAC11_SHIFT)) & AIPSTZ_OPACR1_OPAC11_MASK)

#define AIPSTZ_OPACR1_OPAC10_MASK                (0xF00000U)
#define AIPSTZ_OPACR1_OPAC10_SHIFT               (20U)
/*! OPAC10 - OPAC10. */
#define AIPSTZ_OPACR1_OPAC10(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR1_OPAC10_SHIFT)) & AIPSTZ_OPACR1_OPAC10_MASK)

#define AIPSTZ_OPACR1_OPAC9_MASK                 (0xF000000U)
#define AIPSTZ_OPACR1_OPAC9_SHIFT                (24U)
/*! OPAC9 - OPAC9. */
#define AIPSTZ_OPACR1_OPAC9(x)                   (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR1_OPAC9_SHIFT)) & AIPSTZ_OPACR1_OPAC9_MASK)

#define AIPSTZ_OPACR1_OPAC8_MASK                 (0xF0000000U)
#define AIPSTZ_OPACR1_OPAC8_SHIFT                (28U)
/*! OPAC8 - OPAC8. */
#define AIPSTZ_OPACR1_OPAC8(x)                   (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR1_OPAC8_SHIFT)) & AIPSTZ_OPACR1_OPAC8_MASK)
/*! @} */

/*! @name OPACR2 - OPACR2 */
/*! @{ */

#define AIPSTZ_OPACR2_OPAC23_MASK                (0xFU)
#define AIPSTZ_OPACR2_OPAC23_SHIFT               (0U)
/*! OPAC23 - OPAC23. */
#define AIPSTZ_OPACR2_OPAC23(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR2_OPAC23_SHIFT)) & AIPSTZ_OPACR2_OPAC23_MASK)

#define AIPSTZ_OPACR2_OPAC22_MASK                (0xF0U)
#define AIPSTZ_OPACR2_OPAC22_SHIFT               (4U)
/*! OPAC22 - OPAC22. */
#define AIPSTZ_OPACR2_OPAC22(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR2_OPAC22_SHIFT)) & AIPSTZ_OPACR2_OPAC22_MASK)

#define AIPSTZ_OPACR2_OPAC21_MASK                (0xF00U)
#define AIPSTZ_OPACR2_OPAC21_SHIFT               (8U)
/*! OPAC21 - OPAC21. */
#define AIPSTZ_OPACR2_OPAC21(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR2_OPAC21_SHIFT)) & AIPSTZ_OPACR2_OPAC21_MASK)

#define AIPSTZ_OPACR2_OPAC20_MASK                (0xF000U)
#define AIPSTZ_OPACR2_OPAC20_SHIFT               (12U)
/*! OPAC20 - OPAC20. */
#define AIPSTZ_OPACR2_OPAC20(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR2_OPAC20_SHIFT)) & AIPSTZ_OPACR2_OPAC20_MASK)

#define AIPSTZ_OPACR2_OPAC19_MASK                (0xF0000U)
#define AIPSTZ_OPACR2_OPAC19_SHIFT               (16U)
/*! OPAC19 - OPAC19. */
#define AIPSTZ_OPACR2_OPAC19(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR2_OPAC19_SHIFT)) & AIPSTZ_OPACR2_OPAC19_MASK)

#define AIPSTZ_OPACR2_OPAC18_MASK                (0xF00000U)
#define AIPSTZ_OPACR2_OPAC18_SHIFT               (20U)
/*! OPAC18 - OPAC18. */
#define AIPSTZ_OPACR2_OPAC18(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR2_OPAC18_SHIFT)) & AIPSTZ_OPACR2_OPAC18_MASK)

#define AIPSTZ_OPACR2_OPAC17_MASK                (0xF000000U)
#define AIPSTZ_OPACR2_OPAC17_SHIFT               (24U)
/*! OPAC17 - OPAC17. */
#define AIPSTZ_OPACR2_OPAC17(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR2_OPAC17_SHIFT)) & AIPSTZ_OPACR2_OPAC17_MASK)

#define AIPSTZ_OPACR2_OPAC16_MASK                (0xF0000000U)
#define AIPSTZ_OPACR2_OPAC16_SHIFT               (28U)
/*! OPAC16 - OPAC16. */
#define AIPSTZ_OPACR2_OPAC16(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR2_OPAC16_SHIFT)) & AIPSTZ_OPACR2_OPAC16_MASK)
/*! @} */

/*! @name OPACR3 - OPACR3 */
/*! @{ */

#define AIPSTZ_OPACR3_OPAC31_MASK                (0xFU)
#define AIPSTZ_OPACR3_OPAC31_SHIFT               (0U)
/*! OPAC31 - OPAC31. */
#define AIPSTZ_OPACR3_OPAC31(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR3_OPAC31_SHIFT)) & AIPSTZ_OPACR3_OPAC31_MASK)

#define AIPSTZ_OPACR3_OPAC30_MASK                (0xF0U)
#define AIPSTZ_OPACR3_OPAC30_SHIFT               (4U)
/*! OPAC30 - OPAC30. */
#define AIPSTZ_OPACR3_OPAC30(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR3_OPAC30_SHIFT)) & AIPSTZ_OPACR3_OPAC30_MASK)

#define AIPSTZ_OPACR3_OPAC29_MASK                (0xF00U)
#define AIPSTZ_OPACR3_OPAC29_SHIFT               (8U)
/*! OPAC29 - OPAC29. */
#define AIPSTZ_OPACR3_OPAC29(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR3_OPAC29_SHIFT)) & AIPSTZ_OPACR3_OPAC29_MASK)

#define AIPSTZ_OPACR3_OPAC28_MASK                (0xF000U)
#define AIPSTZ_OPACR3_OPAC28_SHIFT               (12U)
/*! OPAC28 - OPAC28. */
#define AIPSTZ_OPACR3_OPAC28(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR3_OPAC28_SHIFT)) & AIPSTZ_OPACR3_OPAC28_MASK)

#define AIPSTZ_OPACR3_OPAC27_MASK                (0xF0000U)
#define AIPSTZ_OPACR3_OPAC27_SHIFT               (16U)
/*! OPAC27 - OPAC27. */
#define AIPSTZ_OPACR3_OPAC27(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR3_OPAC27_SHIFT)) & AIPSTZ_OPACR3_OPAC27_MASK)

#define AIPSTZ_OPACR3_OPAC26_MASK                (0xF00000U)
#define AIPSTZ_OPACR3_OPAC26_SHIFT               (20U)
/*! OPAC26 - OPAC26. */
#define AIPSTZ_OPACR3_OPAC26(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR3_OPAC26_SHIFT)) & AIPSTZ_OPACR3_OPAC26_MASK)

#define AIPSTZ_OPACR3_OPAC25_MASK                (0xF000000U)
#define AIPSTZ_OPACR3_OPAC25_SHIFT               (24U)
/*! OPAC25 - OPAC25. */
#define AIPSTZ_OPACR3_OPAC25(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR3_OPAC25_SHIFT)) & AIPSTZ_OPACR3_OPAC25_MASK)

#define AIPSTZ_OPACR3_OPAC24_MASK                (0xF0000000U)
#define AIPSTZ_OPACR3_OPAC24_SHIFT               (28U)
/*! OPAC24 - OPAC24. */
#define AIPSTZ_OPACR3_OPAC24(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR3_OPAC24_SHIFT)) & AIPSTZ_OPACR3_OPAC24_MASK)
/*! @} */

/*! @name OPACR4 - OPACR4 */
/*! @{ */

#define AIPSTZ_OPACR4_OPAC33_MASK                (0xF000000U)
#define AIPSTZ_OPACR4_OPAC33_SHIFT               (24U)
/*! OPAC33 - OPAC33. */
#define AIPSTZ_OPACR4_OPAC33(x)                  (((uint32_t)(((uint32_t)(x)) << AIPSTZ_OPACR4_OPAC33_SHIFT)) & AIPSTZ_OPACR4_OPAC33_MASK)

#define AIPSTZ_OPACR4_OPAC32_MASK                (0xF0000000U)
#define AIPSTZ_OPACR4_OPAC32_SHIFT               (28U)
/*! OPAC32 - OPAC32. */
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
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_AIPSTZ_H_ */

