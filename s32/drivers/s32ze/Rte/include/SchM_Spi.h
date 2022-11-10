/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SCHM_SPI_H
#define SCHM_SPI_H

/**
*   @file
*
*   @addtogroup RTE_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_SPI_AR_RELEASE_MAJOR_VERSION     4
#define SCHM_SPI_AR_RELEASE_MINOR_VERSION     7
#define SCHM_SPI_AR_RELEASE_REVISION_VERSION  0
#define SCHM_SPI_SW_MAJOR_VERSION             0
#define SCHM_SPI_SW_MINOR_VERSION             9
#define SCHM_SPI_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define NUMBER_OF_CORES         (uint8)(14U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

#ifdef MCAL_TESTING_ENVIRONMENT
/** 
@brief   This function checks that all entered exclusive areas were also exited. 
@details This function checks that all entered exclusive areas were also exited. The check
         is done by verifying that all reentry_guard_* static variables are back to the
         zero value.
    
@param[in]     void       No input parameters
@return        void       This function does not return a value. Test asserts are used instead. 

@pre  None
@post None

@remarks Covers 
@remarks Implements 
*/
void SchM_Check_spi(void);
#endif /*MCAL_TESTING_ENVIRONMENT*/

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_01(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_01(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_02(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_02(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_03(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_03(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_04(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_04(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_05(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_05(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_06(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_06(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_07(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_07(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_08(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_08(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_09(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_09(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_10(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_10(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_11(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_11(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_12(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_12(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_13(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_13(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_14(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_14(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_15(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_15(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_16(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_16(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_17(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_17(void);

extern void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_18(void);
extern void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_18(void);


void Spi_MainFunction_Handling(void);

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SCHM_SPI_H */
