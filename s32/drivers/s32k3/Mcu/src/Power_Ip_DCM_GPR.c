/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Power_Ip_DCM_GPR.c
*   @version    3.0.0
*
*   @brief
*   @brief   POWER driver implementations.
*   @details POWER driver implementations.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif





/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_Private.h"
#include "Power_Ip_DCM_GPR.h"

#if (defined(POWER_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT))
  #if (defined(MCAL_DCM_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_DCM_REG_PROT_AVAILABLE)
      #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
      #include "RegLockMacros.h"
    #endif /* (STD_ON == MCAL_DCM_REG_PROT_AVAILABLE) */
  #endif
#endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_DCM_GPR_VENDOR_ID_C                      43
#define POWER_IP_DCM_GPR_AR_RELEASE_MAJOR_VERSION_C       4
#define POWER_IP_DCM_GPR_AR_RELEASE_MINOR_VERSION_C       7
#define POWER_IP_DCM_GPR_AR_RELEASE_REVISION_VERSION_C    0
#define POWER_IP_DCM_GPR_SW_MAJOR_VERSION_C               3
#define POWER_IP_DCM_GPR_SW_MINOR_VERSION_C               0
#define POWER_IP_DCM_GPR_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_DCM_GPR.c file and Power_Ip_Private.h file are of the same vendor */
#if (POWER_IP_DCM_GPR_VENDOR_ID_C != POWER_IP_PRIVATE_VENDOR_ID)
    #error "Power_Ip_DCM_GPR.c and Power_Ip_Private.h have different vendor ids"
#endif

/* Check if Power_Ip_DCM_GPR.c file and Power_Ip_Private.h file are of the same Autosar version */
#if ((POWER_IP_DCM_GPR_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_DCM_GPR_AR_RELEASE_MINOR_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_DCM_GPR_AR_RELEASE_REVISION_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_DCM_GPR.c and Power_Ip_Private.h are different"
#endif

/* Check if Power_Ip_DCM_GPR.c file and Power_Ip_Private.h file are of the same Software version */
#if ((POWER_IP_DCM_GPR_SW_MAJOR_VERSION_C != POWER_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (POWER_IP_DCM_GPR_SW_MINOR_VERSION_C != POWER_IP_PRIVATE_SW_MINOR_VERSION) || \
     (POWER_IP_DCM_GPR_SW_PATCH_VERSION_C != POWER_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_DCM_GPR.c and Power_Ip_Private.h are different"
#endif

/* Check if Power_Ip_DCM_GPR.c file and Power_Ip_DCM_GPR.h file are of the same vendor */
#if (POWER_IP_DCM_GPR_VENDOR_ID_C != POWER_IP_DCM_GPR_VENDOR_ID)
    #error "Power_Ip_DCM_GPR.c and Power_Ip_DCM_GPR.h have different vendor ids"
#endif

/* Check if Power_Ip_DCM_GPR.c file and Power_Ip_DCM_GPR.h file are of the same Autosar version */
#if ((POWER_IP_DCM_GPR_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_DCM_GPR_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_DCM_GPR_AR_RELEASE_MINOR_VERSION_C != POWER_IP_DCM_GPR_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_DCM_GPR_AR_RELEASE_REVISION_VERSION_C != POWER_IP_DCM_GPR_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_DCM_GPR.c and Power_Ip_DCM_GPR.h are different"
#endif

/* Check if Power_Ip_DCM_GPR.c file and Power_Ip_DCM_GPR.h file are of the same Software version */
#if ((POWER_IP_DCM_GPR_SW_MAJOR_VERSION_C != POWER_IP_DCM_GPR_SW_MAJOR_VERSION) || \
     (POWER_IP_DCM_GPR_SW_MINOR_VERSION_C != POWER_IP_DCM_GPR_SW_MINOR_VERSION) || \
     (POWER_IP_DCM_GPR_SW_PATCH_VERSION_C != POWER_IP_DCM_GPR_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_DCM_GPR.c and Power_Ip_DCM_GPR.h are different"
#endif

#if (defined(POWER_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT))
  #if (defined(MCAL_DCM_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_DCM_REG_PROT_AVAILABLE)
        #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if Power_Ip_DCM_GPR.c file and RegLockMacros.h file are of the same Autosar version */
            #if ((POWER_IP_DCM_GPR_AR_RELEASE_MAJOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
                (POWER_IP_DCM_GPR_AR_RELEASE_MINOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Power_Ip_DCM_GPR.c and RegLockMacros.h are different"
            #endif
        #endif
    #endif /* (STD_ON == MCAL_DCM_REG_PROT_AVAILABLE) */
  #endif
#endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if (defined(POWER_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT))
  #if (defined(MCAL_DCM_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_DCM_REG_PROT_AVAILABLE)
/**
* @brief            This function will enable writing in User mode by configuring REG_PROT
*/
void Power_Ip_DCM_GPR_SetUserAccessAllowed(void)
{
#if (defined(IP_DCM_GPR_BASE))
    SET_USER_ACCESS_ALLOWED(IP_DCM_GPR_BASE, DCM_PROT_MEM_U32);
#endif
}
    #endif
  #endif /* MCAL_DCM_REG_PROT_AVAILABLE */
#endif /* POWER_IP_ENABLE_USER_MODE_SUPPORT */


/**
* @brief            This function configure the Device Configuration Module General-Purpose Registers
* @details          Control to bypass the SIRC trimming, PMC trimming and RGM DCF loading, FIRC trimming
*                   DCM scanning on standby exit.
*
* @param[in]        ConfigPtr   Pointer to DCM_GPR configuration structure.
*
* @return           void
*
*/
void Power_Ip_DCM_GPR_Config(const Power_Ip_DCM_GPR_ConfigType * ConfigPtr)
{
    (void)ConfigPtr;
    uint32 TempValue = 0U;

    if (TRUE == ConfigPtr->DcmGprUnderMcuControl)
    {
        /* Check the boot mode is Fast Standby */
        if (1U == ConfigPtr->BootMode)
        {
            /* Set Vector table address and Enable Fast Standby Exit */
            IP_DCM_GPR->DCMRWF5 = (ConfigPtr->BootAddress) | (uint32)(ConfigPtr->BootMode);
        }
        else
        {
            /* Reset value of the field Boot_Address and Boot Mode is Normal selected */
            IP_DCM_GPR->DCMRWF5 = 0U;
        }

        /* Set bypassed or not bypassed for the SIRC trimming, PMC trimming and RGM DCF loading, FIRC trimming DCM scanning */
        TempValue = IP_DCM_GPR->DCMRWF2;
        TempValue &= ~((uint32)((uint32)DCM_GPR_DCMRWF2_SIRC_TRIM_BYP_STDBY_EXT_MASK | (uint32)DCM_GPR_DCMRWF2_PMC_TRIM_RGM_DCF_BYP_STDBY_EXT_MASK | (uint32)DCM_GPR_DCMRWF2_FIRC_TRIM_BYP_STDBY_EXT_MASK | (uint32)DCM_GPR_DCMRWF2_DCM_SCAN_BYP_STDBY_EXT_MASK));
        TempValue |= (ConfigPtr->ConfigRegister);
        IP_DCM_GPR->DCMRWF2 = TempValue;
    }
}

/**
* @brief            This function configures The global padkeeping
* @details          Control global padkeeping before entering low power mode
*
* @param[in]        config   Value which writing to STANDBY_IO_CONFIG bitfield.
*
* @return           void
*
*/
void Power_Ip_DCM_GPR_GlobalPadkeepingConfig(uint8 Config)
{
    uint32 TempValue = 0U;

    TempValue = IP_DCM_GPR->DCMRWF1;
    TempValue &= ~((uint32)DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG_MASK);
    TempValue |= DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG(Config);
    IP_DCM_GPR->DCMRWF1 = TempValue;
}
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
