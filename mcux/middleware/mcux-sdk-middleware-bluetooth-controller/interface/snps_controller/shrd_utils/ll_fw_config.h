/**
 ********************************************************************************
 * @file    ll_fw_config.h
 * @brief   This file contains the major configurations to the BLE controller.
 ******************************************************************************
 * @copy
 *
 * Synopsys MIT License:
 * Copyright (c) 2020-Present Synopsys, Inc
 * Permission is hereby granted, free of charge, to any person obtaining a copy of the Software,
 * to deal in the Software without restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and
 * to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or 
 * substantial portions of the Software.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,INCLUDING,
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE ARISING FROM,
 * OUT OF, OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE

 *
 * \n\n<b>References</b>\n
 * -Documents folder .
 *
 * <b>Edit History For File</b>\n
 *  This section contains comments describing changes made to this file.\n
 *  Notice that changes are listed in reverse chronological order.\n
 * <table border>
 * <tr>
 *   <td><b> when </b></td>
 *   <td><b> who </b></td>
 *   <td><b> what, where, why </b></td>
 * </tr>
 * <tr>
 * </tr>
 * </table>\n
 */
#ifndef INCLUDE_LL_FW_CONFIG_H
#define INCLUDE_LL_FW_CONFIG_H

/*************************** BLE Configuration *************************************/
/*Configurations of BLE will apply only when BLE is enabled*/
/* Roles configurations */
/* Allow compiling different flavours of the library
 * without creating a header file per combination */
#ifndef SUPPORT_EXPLCT_OBSERVER_ROLE
#define SUPPORT_EXPLCT_OBSERVER_ROLE				1 /* Enable\Disable Explicit observer role. Enable:1 - Disable:0 */
#endif
#ifndef SUPPORT_EXPLCT_BROADCASTER_ROLE
#define SUPPORT_EXPLCT_BROADCASTER_ROLE				1 /* Enable\Disable Explicit broadcaster role. Enable:1 - Disable:0 */
#endif
#ifndef SUPPORT_MASTER_CONNECTION
#define SUPPORT_MASTER_CONNECTION					1 /* Enable\Disable Master connection role. Enable:1 - Disable:0 */
#endif
#ifndef SUPPORT_SLAVE_CONNECTION
#define SUPPORT_SLAVE_CONNECTION					1 /* Enable\Disable Slave connection role. Enable:1 - Disable:0 */
#endif

/* Standard features configurations */
#ifndef SUPPORT_LE_ENCRYPTION
#define SUPPORT_LE_ENCRYPTION						1 /* Enable\Disable Encryption feature. Enable:1 - Disable:0 */
#endif
#ifndef SUPPORT_PRIVACY
#define SUPPORT_PRIVACY								1 /* Enable\Disable Privacy feature. Enable:1 - Disable:0 */
#endif
#ifndef SUPPORT_LE_EXTENDED_ADVERTISING
#define SUPPORT_LE_EXTENDED_ADVERTISING				1 /* Enable\Disable Extended advertising feature. Enable:1 - Disable:0 */
#endif
#ifndef SUPPORT_LE_PERIODIC_ADVERTISING
#define SUPPORT_LE_PERIODIC_ADVERTISING				1 /* Enable\Disable Periodic advertising feature. Enable:1 - Disable:0 */
#endif
#ifndef SUPPORT_LE_POWER_CLASS_1
#define SUPPORT_LE_POWER_CLASS_1					0 /* Enable\Disable Low power class 1 feature. Enable:1 - Disable:0 */
#endif
#ifndef SUPPORT_AOA_AOD
#define SUPPORT_AOA_AOD								0 /* Enable\Disable AOA_AOD feature. Enable:1 - Disable:0 */
#endif
#ifndef SUPPORT_PERIODIC_SYNC_TRANSFER
#define SUPPORT_PERIODIC_SYNC_TRANSFER				1 /* Enable\Disable PAST feature. Enable:1 - Disable:0 */
#endif
#ifndef SUPPORT_SLEEP_CLOCK_ACCURCY_UPDATES
#define SUPPORT_SLEEP_CLOCK_ACCURCY_UPDATES         1 /* Enable\Disable Sleep Clock Accuracy Updates Feature. Enable:1 - Disable:0 */
#endif
#ifndef SUPPORT_CONNECTED_ISOCHRONOUS
#define SUPPORT_CONNECTED_ISOCHRONOUS               0 /* Enable\Disable Connected Isochronous Channel Feature. Enable:1 - Disable:0 */
#endif
#ifndef SUPPORT_BRD_ISOCHRONOUS
#define SUPPORT_BRD_ISOCHRONOUS               		0 /* Enable\Disable Broadcast Isochronous Channel Feature. Enable:1 - Disable:0 */
#endif
#ifndef SUPPORT_SYNC_ISOCHRONOUS
#define SUPPORT_SYNC_ISOCHRONOUS               		0 /* Enable\Disable Broadcast Isochronous Synchronizer Channel Feature. Enable:1 - Disable:0 */
#endif
#ifndef SUPPORT_LE_POWER_CONTROL
#define SUPPORT_LE_POWER_CONTROL					1 /* Enable\Disable LE Power Control Feature. Enable:1 - Disable:0 */
#endif
/* Capabilities configurations */
#ifndef MAX_NUM_CNCRT_STAT_MCHNS
#define MAX_NUM_CNCRT_STAT_MCHNS					8 /* Set maximum number of states the controller can support */
#endif
#ifndef USE_NON_ACCURATE_32K_SLEEP_CLK
#define USE_NON_ACCURATE_32K_SLEEP_CLK				1 /* Allow to drive the sleep clock by sources other than the default crystal oscillator source.*/
#endif
													   /*LL can use crystal oscillator or RTC or RCO to drive the sleep clock.This selection is done via "DEFAULT_SLEEP_CLOCK_SOURCE" macro. */

/* Non-standard features configurations */
#ifndef NUM_OF_CTSM_EMNGR_HNDLS
#define NUM_OF_CTSM_EMNGR_HNDLS						1 /* Number of custom handles in event manager to be used for app specific needs */
#endif
#ifndef SUPPORT_PTA
#define SUPPORT_PTA									0 /* Enable\Disable PTA Feature. Enable:1 - Disable:0 */
#endif

/*************************** MAC Configuration *************************************/
/*Configurations of MAC will apply only when MAC is enabled*/
#define FFD_DEVICE_CONFIG							1 /* Enable\Disable FFD:1 - RFD:0 */
#ifdef SUPPORT_AUG_MAC_HCI_UART
#define RAL_NUMBER_OF_INSTANCE						2 /* The Number of RAL instances supported */
#else
#define RAL_NUMBER_OF_INSTANCE						1 /* The Number of RAL instances supported */
#endif
#define MAX_NUMBER_OF_INDIRECT_DATA 				2 /* The maximum number of supported indirect data buffers */
#define SUPPORT_OPENTHREAD_1_2                  	1 /* Enable / disable FW parts related to new features introduced in openthread 1.2*/
#define SUPPORT_SEC 								1 /* The MAC Security Supported : 1 - Not Supported:0 */
#define RADIO_CSMA									1 /* Enable\Disable CSMA Algorithm in Radio Layer, Must be Enabled if MAC_LAYER_BUILD */
#define SMPL_PRTCL_TEST_ENABLE 						0

#endif /* INCLUDE_LL_FW_CONFIG_H */
