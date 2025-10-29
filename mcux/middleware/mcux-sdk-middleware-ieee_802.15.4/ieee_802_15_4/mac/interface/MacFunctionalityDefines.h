/*! *********************************************************************************
* \defgroup MacFunctionality Mac Functionality Definitions
* @{
********************************************************************************** */
/*! *********************************************************************************
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2025 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef _MAC_FUNCTIONALITY_DEFINES_H_
#define _MAC_FUNCTIONALITY_DEFINES_H_

/************************************************************************************
*************************************************************************************
* Include
*************************************************************************************
************************************************************************************/

/************************************************************************************
*************************************************************************************
* Public macros
*************************************************************************************
************************************************************************************/

/*! 2.4 GHz MAC 2006 for CM4 */
#define gMacFeatureSet_06M4_d        0
/*! 2.4 GHz MAC 2011 for CM4 */
#define gMacFeatureSet_11M4_d        1
/*! 2.4 GHz ZigBee PRO MAC for CM4 */
#define gMacFeatureSet_ZPM4_d        2
/*! 2.4 GHz Beacon Enabled MAC 2006 for CM4 */
#define gMacFeatureSet_06BEM4_d      3
/*! 2.4 GHz Beacon Enabled MAC 2006 with GTS for CM4 */
#define gMacFeatureSet_06BEGTSM4_d   4

/*! Sub-GHZ MAC 2006 for CM0 */
#define gMacFeatureSet_06gM0_d       5
/*! Sub-GHZ MAC 2011 for CM0 */
#define gMacFeatureSet_11gM0_d       6
/*! Sub-GHZ MAC 2006 with CLS and RIT for CM0 */
#define gMacFeatureSet_06eLEgM0_d    7
/*! Sub-GHZ MAC 2011 with CLS and RIT for CM0 */
#define gMacFeatureSet_11eLEgM0_d    8
/*! Sub-GHZ MAC 2006 with TSCH for CM0 */
#define gMacFeatureSet_06eTSCHgM0_d  9
/*! Sub-GHZ MAC 2011 with TSCH for CM0 */
#define gMacFeatureSet_11eTSCHgM0_d  10

/*! 2.4 GHz MAC 2006 for CM0 */
#define gMacFeatureSet_06M0_d        11
/*! 2.4 GHz MAC 2011 for CM0 */
#define gMacFeatureSet_11M0_d        12
/*! 2.4 GHz ZigBee PRO MAC for CM0 */
#define gMacFeatureSet_ZPM0_d        13
/*! 2.4 GHz Beacon Enabled MAC 2006 for CM0 */
#define gMacFeatureSet_06BEM0_d      14
/*! 2.4 GHz Beacon Enabled MAC 2006 with GTS for CM0 */
#define gMacFeatureSet_06BEGTSM0_d   15

/*! 2.4 GHz Thread MAC for CM4 */
#define gMacFeatureSet_THR_M4_d      16
/*! 2.4 GHz Thread MAC for CM0 */
#define gMacFeatureSet_THR_M0_d      17
/*! 2.4 GHz RFD Thread MAC for CM4 */
#define gMacFeatureSet_THRRFD_M4_d   18
/*! 2.4 GHz RFD Thread MAC for CM0 */
#define gMacFeatureSet_THRRFD_M0_d   19

/*! 2.4 GHz RFD MAC 2006 for CM4 */
#define gMacFeatureSet_06RFD_M4_d    20
/*! 2.4 GHz RFD MAC 2006 for CM0 */
#define gMacFeatureSet_06RFD_M0_d    21

#define gMacFeatureSet_THR_CSL_d     22


/*! *********************************************************************************
  MAC feature  | Description
  -------------|-------------
     06        | 2006 security
     11        | 2011 security
     g         | Used with g PHY
     e         | features followed by listing (LE/TSCH/DSME)
     LE        | 4e low energy features (CSL, RIT)
     TSCH      | 4e Time Slotted Channel Hopping
     DSME      | 4e Deterministic and Synchronous Multi-channel Extension
     BE        | Beacon order !=15 (for code size reduction purposes)
     GTS       | GTS support (for code size reduction purposes)
     ZP        | ZigBee PRO customizations
     M0        | Cortex M0+
     M4        | Cortex M4
 
********************************************************************************** */
#ifndef gMacFeatureSet_d
#define gMacFeatureSet_d gMacFeatureSet_06M4_d
#endif

/*! \cond DOXY_SKIP_TAG */
#if (gMacFeatureSet_d == gMacFeatureSet_06M4_d) || (gMacFeatureSet_d == gMacFeatureSet_06M0_d)
  #define gMacInternalDataSize_c      320 /* [bytes] */

#elif (gMacFeatureSet_d == gMacFeatureSet_11M4_d) || (gMacFeatureSet_d == gMacFeatureSet_11M0_d)
  #define gMacInternalDataSize_c      336 /* [bytes] */
  #define gMAC2011_d                  (1)

#elif (gMacFeatureSet_d == gMacFeatureSet_06RFD_M4_d) || (gMacFeatureSet_d == gMacFeatureSet_06RFD_M0_d)
  #define gMacInternalDataSize_c      360 /* [bytes] */
  #define gMacUseAssociation_d        (1)
  #define gMacUseOrphanScan_d         (0)
  #define gMacUsePromiscuous_d        (0)
  #define gMacUseMlmeStart_d          (0)
  #define gMacPanIdConflictDetect_d   (0)
  #define gMacCoordinatorCapability_d (0)

#elif (gMacFeatureSet_d == gMacFeatureSet_ZPM4_d) || (gMacFeatureSet_d == gMacFeatureSet_ZPM0_d)
  #define gMacInternalDataSize_c      376 /* [bytes] */
  #define gMacUsePackedStructs_d      (1)

#elif (gMacFeatureSet_d == gMacFeatureSet_THR_M4_d) || (gMacFeatureSet_d == gMacFeatureSet_THR_M0_d)
  #define gMacInternalDataSize_c      344 /* [bytes] */
  #define gMacUseAssociation_d        (0)
  #define gMacUseOrphanScan_d         (0)
  #define gMacUsePromiscuous_d        (0)
  #define gMacPanIdConflictDetect_d   (0)

#elif (gMacFeatureSet_d == gMacFeatureSet_THR_CSL_d)
  #define gMacInternalDataSize_c      400 /* [bytes] */
  #define gMacUseAssociation_d        (0)
  #define gMacUseOrphanScan_d         (0)
  #define gMacUsePromiscuous_d        (0)
  #define gMacUseRxEnableRequest_d    (1)
  #define gMacPanIdConflictDetect_d   (0)

#elif (gMacFeatureSet_d == gMacFeatureSet_THRRFD_M4_d) || (gMacFeatureSet_d == gMacFeatureSet_THRRFD_M0_d)
  #define gMacInternalDataSize_c      264 /* [bytes] */
  #define gMacUseAssociation_d        (0)
  #define gMacUseOrphanScan_d         (0)
  #define gMacUsePromiscuous_d        (0)
  #define gMacUseMlmeStart_d          (0)
  #define gMacPanIdConflictDetect_d   (0)
  #define gMacCoordinatorCapability_d (0)

#elif (gMacFeatureSet_d == gMacFeatureSet_06BEM4_d) || (gMacFeatureSet_d == gMacFeatureSet_06BEM0_d)
  #define gMacInternalDataSize_c      560 /* [bytes] */

#elif (gMacFeatureSet_d == gMacFeatureSet_06BEGTSM4_d) || (gMacFeatureSet_d == gMacFeatureSet_06BEGTSM0_d)
  #define gMacInternalDataSize_c      600 /* [bytes] */

#elif (gMacFeatureSet_d == gMacFeatureSet_06gM0_d)
  #define gMacInternalDataSize_c      464 /* [bytes] */
  
#elif (gMacFeatureSet_d == gMacFeatureSet_06eLEgM0_d)
  #define gMacInternalDataSize_c      568 /* [bytes] */

#elif (gMacFeatureSet_d == gMacFeatureSet_06eTSCHgM0_d)
  #define gMacInternalDataSize_c      552 /* [bytes] */

#elif (gMacFeatureSet_d == gMacFeatureSet_11gM0_d)
  #define gMacInternalDataSize_c      448 /* [bytes] */
  #define gMAC2011_d                  (1)

#elif (gMacFeatureSet_d == gMacFeatureSet_11eLEgM0_d)
  #define gMacInternalDataSize_c      560 /* [bytes] */
  #define gMAC2011_d                  (1)

#elif (gMacFeatureSet_d == gMacFeatureSet_11eTSCHgM0_d)
  #define gMacInternalDataSize_c      544 /* [bytes] */
  #define gMAC2011_d                  (1)

#else
  #error Unsupported MAC Feature Set

#endif
/*! \endcond */

/*! PACK all data structures from MAC interface */
#ifndef gMacUsePackedStructs_d
#define gMacUsePackedStructs_d      (0)
#endif

/*! MAC Association/Disassociation support */
#ifndef gMacUseAssociation_d
#define gMacUseAssociation_d        (1)
#endif

/*! MAC Orphan Scan support */
#ifndef gMacUseOrphanScan_d
#define gMacUseOrphanScan_d         (1)
#endif

/*! MAC Rx Enable support */
#ifndef gMacUseRxEnableRequest_d
#define gMacUseRxEnableRequest_d    (1)
#endif

/*! Promiscuous mode support */
#ifndef gMacUsePromiscuous_d
#define gMacUsePromiscuous_d        (1)
#endif 

/*! PAN creation support */
#ifndef gMacUseMlmeStart_d
#define gMacUseMlmeStart_d          (1)
#endif

/*! PAN Id conflict detection support */
#ifndef gMacPanIdConflictDetect_d
#define gMacPanIdConflictDetect_d   (1)
#endif

/*! MAC Coordinator functionality */
#ifndef gMacCoordinatorCapability_d
#define gMacCoordinatorCapability_d (1)
#endif

#endif /* _MAC_FUNCTIONALITY_DEFINES_H_ */

/*! *********************************************************************************
* @}
********************************************************************************** */
