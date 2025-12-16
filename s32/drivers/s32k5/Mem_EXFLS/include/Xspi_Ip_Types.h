/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef XSPI_IP_TYPES_H
#define XSPI_IP_TYPES_H

/**
*   @file Xspi_Ip_Types.h
*
*   @addtogroup IPV_XSPI XSPI IPV Driver
*   @{
*/

/* implements Xspi_Ip_Types.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif

#include "Mcal.h"
#include "Std_Types.h"
#include "Xspi_Ip_Features.h"
#include "Xspi_Ip_CfgDefines.h"
#include "Xspi_Ip_HyperRamTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define XSPI_IP_TYPES_VENDOR_ID                    43
#define XSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define XSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION     9
#define XSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define XSPI_IP_TYPES_SW_MAJOR_VERSION             0
#define XSPI_IP_TYPES_SW_MINOR_VERSION             8
#define XSPI_IP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Xspi_Ip_Types header file and Std_Types.h header file are of the same Autosar version */
    #if ((XSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (XSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Autosar Version Numbers of Xspi_Ip_Types.h and Std_Types.h are different"
    #endif
#endif

/* Check if current file and Xspi_Ip_Features header file are of the same vendor */
#if (XSPI_IP_TYPES_VENDOR_ID != XSPI_IP_FEATURES_VENDOR_ID_CFG)
    #error "Xspi_Ip_Types.h and Xspi_Ip_Features.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Features header file are of the same Autosar version */
#if ((XSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != XSPI_IP_FEATURES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (XSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION    != XSPI_IP_FEATURES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (XSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION != XSPI_IP_FEATURES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_Types.h and Xspi_Ip_Features.h are different"
#endif
/* Check if current file and Xspi_Ip_Features header file are of the same Software version */
#if ((XSPI_IP_TYPES_SW_MAJOR_VERSION != XSPI_IP_FEATURES_SW_MAJOR_VERSION_CFG) || \
     (XSPI_IP_TYPES_SW_MINOR_VERSION != XSPI_IP_FEATURES_SW_MINOR_VERSION_CFG) || \
     (XSPI_IP_TYPES_SW_PATCH_VERSION != XSPI_IP_FEATURES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Xspi_Ip_Types.h and Xspi_Ip_Features.h are different"
#endif

/* Check if current file and Xspi_Ip_CfgDefines header file are of the same vendor */
#if (XSPI_IP_TYPES_VENDOR_ID != XSPI_IP_VENDOR_ID_CFG_DEFINES)
    #error "Xspi_Ip_Types.h and Xspi_Ip_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_CfgDefines header file are of the same Autosar version */
#if ((XSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != XSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES) || \
     (XSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION    != XSPI_IP_AR_RELEASE_MINOR_VERSION_CFG_DEFINES) || \
     (XSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION != XSPI_IP_AR_RELEASE_REVISION_VERSION_CFG_DEFINES) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_Types.h and Xspi_Ip_CfgDefines.h are different"
#endif
/* Check if current file and Xspi_Ip_CfgDefines header file are of the same Software version */
#if ((XSPI_IP_TYPES_SW_MAJOR_VERSION != XSPI_IP_SW_MAJOR_VERSION_CFG_DEFINES) || \
     (XSPI_IP_TYPES_SW_MINOR_VERSION != XSPI_IP_SW_MINOR_VERSION_CFG_DEFINES) || \
     (XSPI_IP_TYPES_SW_PATCH_VERSION != XSPI_IP_SW_PATCH_VERSION_CFG_DEFINES) \
    )
    #error "Software Version Numbers of Xspi_Ip_Types.h and Xspi_Ip_CfgDefines.h are different"
#endif

/* Check if current file and Xspi_Ip_HyperRamTypes header file are of the same vendor */
#if (XSPI_IP_TYPES_VENDOR_ID != XSPI_IP_HYPERRAMTYPES_VENDOR_ID)
    #error "Xspi_Ip_Types.h and Xspi_Ip_HyperRamTypes.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_HyperRamTypes header file are of the same Autosar version */
#if ((XSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != XSPI_IP_HYPERRAMTYPES_AR_RELEASE_MAJOR_VERSION) || \
     (XSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION    != XSPI_IP_HYPERRAMTYPES_AR_RELEASE_MINOR_VERSION) || \
     (XSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION != XSPI_IP_HYPERRAMTYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_Types.h and Xspi_Ip_HyperRamTypes.h are different"
#endif
/* Check if current file and Xspi_Ip_HyperRamTypes header file are of the same Software version */
#if ((XSPI_IP_TYPES_SW_MAJOR_VERSION != XSPI_IP_HYPERRAMTYPES_SW_MAJOR_VERSION) || \
     (XSPI_IP_TYPES_SW_MINOR_VERSION != XSPI_IP_HYPERRAMTYPES_SW_MINOR_VERSION) || \
     (XSPI_IP_TYPES_SW_PATCH_VERSION != XSPI_IP_HYPERRAMTYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xspi_Ip_Types.h and Xspi_Ip_HyperRamTypes.h are different"
#endif
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*! Number of erase types that can be supported by a flash device */
#define XSPI_IP_ERASE_TYPES                 (4U)

/*! @brief Number of AHB buffers in the device */
#define XSPI_IP_AHB_BUFFERS                 (4U)

/*! @brief Number of AHB sub-buffers per AHB buffer */
#define XSPI_IP_AHB_SUB_BUFFERS              (4U)

/*! LUT physical sequence numbers assigning list */
#define XSPI_IP_LUT_PHYS_SEQ_READ                  0U
#define XSPI_IP_LUT_PHYS_SEQ_WRITE                 1U
#define XSPI_IP_LUT_PHYS_SEQ_READ_DEVICEID         2U
#define XSPI_IP_LUT_PHYS_SEQ_ERASE                 3U
#define XSPI_IP_LUT_PHYS_SEQ_READ_STATUS           7U
#define XSPI_IP_LUT_PHYS_SEQ_WRITE_ENABLE          8U
#define XSPI_IP_LUT_PHYS_SEQ_CLEAR_ERR             9U
#define XSPI_IP_LUT_PHYS_SEQ_ERASE_SUSPEND         10U
#define XSPI_IP_LUT_PHYS_SEQ_ERASE_RESUME          11U
#define XSPI_IP_LUT_PHYS_SEQ_PROGRAM_SUSPEND       12U
#define XSPI_IP_LUT_PHYS_SEQ_PROGRAM_RESUME        13U
#define XSPI_IP_LUT_PHYS_SEQ_OPTIONAL_1            14U
#define XSPI_IP_LUT_PHYS_SEQ_OPTIONAL_2            15U

/*! Invalid index in virtual LUT, used for unsupported features */
#define XSPI_IP_LUT_INVALID                 (uint16)0xFFFFU

/*! End operation for a LUT sequence */
#define XSPI_IP_LUT_SEQ_END                 (uint16)0x0U

/*! Pack the two operations into a LUT register (each operation is a pair of instruction-operand) */
#define XSPI_IP_PACK_LUT_REG(ops0, ops1)    ( (uint32)(ops0) + ((uint32)(ops1) << 16U) )


#define XSPI_FRAD_COUNT   8U        /* Number of FRAD registers */
#define XSPI_MDAD_COUNT   2U        /* Number of MDAD registers */

/*! @brief xspi host interface structure
 */

#if defined(DERIVATIVE_S32N55) || defined(DERIVATIVE_S32N79)
#define XSPI_REG(name) FSS__XSPI_##name
#else
#define XSPI_REG(name) XSPI_##name
#endif

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*!
* @brief Parameter memory type
*/
typedef enum
{
#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
    XSPI_IP_HYPER_RAM       = 2U,           /*!< HyperRam devices            */
#endif
    XSPI_IP_SERIAL_FLASH    = 0U            /*!< Traditional xSPI devices    */
} Xspi_Ip_FlashMemoryType;

/*! @brief XSPI driver return codes
 */
typedef enum
{
    STATUS_XSPI_IP_SUCCESS              = 0x00U,   /*!< Successful job */
    STATUS_XSPI_IP_ERROR                = 0x01U,   /*!< IP is performing an operation */
    STATUS_XSPI_IP_BUSY                 = 0x02U,   /*!< Error - general code */
    STATUS_XSPI_IP_TIMEOUT              = 0x03U,   /*!< Error - exceeded timeout */
    STATUS_XSPI_IP_ERROR_PROGRAM_VERIFY = 0x04U,   /*!< Error - selected memory area doesn't contain desired value */
    STATUS_XSPI_IP_ERROR_BLANK_CHECK    = 0x05U,   /*!< Error - selected memory area isn't in erased state */
} Xspi_Ip_StatusType;

/*! @brief xspi hardware instance
 */
typedef enum
{
    XSPI_IP_INSTANCE_0 = 0x00U,  /*!< XSPI hardware instance 0          */
    XSPI_IP_INSTANCE_1 = 0x01U,  /*!< XSPI hardware instance 1          */
} Xspi_Ip_InstanceType;

/*! @brief flash connection to the XSPI module
 */
typedef enum
{
    XSPI_IP_SIDE_A1    = 0x00U,  /*!< Serial flash connected on side A1    */
    XSPI_IP_SIDE_A2    = 0x01U,  /*!< Serial flash connected on side A2    */
    XSPI_IP_SIDE_B1    = 0x02U,  /*!< Serial flash connected on side B1    */
    XSPI_IP_SIDE_B2    = 0x03U,  /*!< Serial flash connected on side B2    */
} Xspi_Ip_ConnectionType;


/*! @brief flash operation type
 */
typedef enum
{
    XSPI_IP_OP_TYPE_CMD          = 0x00U,  /*!< Simple command                              */
    XSPI_IP_OP_TYPE_WRITE_REG    = 0x01U,  /*!< Write value in external flash register      */
    XSPI_IP_OP_TYPE_RMW_REG      = 0x02U,  /*!< RMW command on external flash register      */
    XSPI_IP_OP_TYPE_READ_REG     = 0x03U,  /*!< Read external flash register until expected value is read    */
    XSPI_IP_OP_TYPE_XSPI_CFG     = 0x04U,  /*!< Re-configure XSPI controller                */
} Xspi_Ip_OpType;

/*! @brief Lut commands
 */
typedef enum
{
    XSPI_IP_LUT_INSTR_STOP            = (0U << 10U),    /*!<  End of sequence                           */
    XSPI_IP_LUT_INSTR_CMD             = (1U << 10U),    /*!<  Command                                   */
    XSPI_IP_LUT_INSTR_ADDR            = (2U << 10U),    /*!<  Address                                   */
    XSPI_IP_LUT_INSTR_DUMMY           = (3U << 10U),    /*!<  Dummy cycles                              */
    XSPI_IP_LUT_INSTR_MODE            = (4U << 10U),    /*!<  8-bit mode                                */
    XSPI_IP_LUT_INSTR_MODE2           = (5U << 10U),    /*!<  2-bit mode                                */
    XSPI_IP_LUT_INSTR_MODE4           = (6U << 10U),    /*!<  4-bit mode                                */
    XSPI_IP_LUT_INSTR_READ            = (7U << 10U),    /*!<  Read data                                 */
    XSPI_IP_LUT_INSTR_WRITE           = (8U << 10U),    /*!<  Write data                                */
    XSPI_IP_LUT_INSTR_JMP_ON_CS       = (9U << 10U),    /*!<  Jump on chip select deassert and stop     */
    XSPI_IP_LUT_INSTR_ADDR_DDR        = (10U << 10U),   /*!<  Address - DDR mode                        */
    XSPI_IP_LUT_INSTR_MODE_DDR        = (11U << 10U),   /*!<  8-bit mode - DDR mode                     */
    XSPI_IP_LUT_INSTR_MODE2_DDR       = (12U << 10U),   /*!<  2-bit mode - DDR mode                     */
    XSPI_IP_LUT_INSTR_MODE4_DDR       = (13U << 10U),   /*!<  4-bit mode - DDR mode                     */
    XSPI_IP_LUT_INSTR_READ_DDR        = (14U << 10U),   /*!<  Read data - DDR mode                      */
    XSPI_IP_LUT_INSTR_WRITE_DDR       = (15U << 10U),   /*!<  Write data - DDR mode                     */
    XSPI_IP_LUT_INSTR_DATA_LEARN      = (16U << 10U),   /*!<  Data learning pattern                     */
    XSPI_IP_LUT_INSTR_CMD_DDR         = (17U << 10U),   /*!<  Command - DDR mode                        */
    XSPI_IP_LUT_INSTR_CADDR           = (18U << 10U),   /*!<  Column address                            */
    XSPI_IP_LUT_INSTR_CADDR_DDR       = (19U << 10U),   /*!<  Column address - DDR mode                 */
    XSPI_IP_LUT_INSTR_JMP_TO_SEQ      = (20U << 10U),   /*!<  Jump on chip select deassert and continue */
} Xspi_Ip_LutCommandsType;

/*! @brief Lut pad options
 */
typedef enum
{
    XSPI_IP_LUT_PADS_1              = (0U << 8U),    /*!<  1 Pad      */
    XSPI_IP_LUT_PADS_2              = (1U << 8U),    /*!<  2 Pads     */
    XSPI_IP_LUT_PADS_4              = (2U << 8U),    /*!<  4 Pads     */
    XSPI_IP_LUT_PADS_8              = (3U << 8U),    /*!<  8 Pads     */
} Xspi_Ip_LutPadsType;

#if (XSPI_IP_CHECK_CFG_CRC == STD_ON)
/**
* @brief Size of data to be processeed by CRC.
*/
typedef enum
{
    XSPI_IP_CRC_8_BITS = 0,
    XSPI_IP_CRC_16_BITS
} Xspi_Ip_CrcDataSizeType;

/**
* @brief          Mem CRC Type
* @details        CRC computed over config set
*/
typedef uint16 Xspi_Ip_CrcType;
#endif

/*!
 * @brief Operation in a LUT sequence.
 *
 * This type describes one basic operation inside a LUT sequence. Each operation contains:
 *  - instruction (6 bits)
 *  - number of PADs (2 bits)
 *  - operand (8 bits)
 * Xspi_Ip_LutCommandsType and Xspi_Ip_LutPadsType types should be used to form operations
 */
typedef uint16 Xspi_Ip_InstrOpType;

/*! @brief Read mode
 */
typedef enum
{
    XSPI_IP_READ_MODE_LOOPBACK            = 1U,  /*!< Use loopback clock from PAD as strobe signal */
    XSPI_IP_READ_MODE_LOOPBACK_DQS        = 2U,  /*!< Use loopback clock from PAD as strobe signal */
    XSPI_IP_READ_MODE_EXTERNAL_DQS        = 3U,  /*!< Use external strobe signal                   */
} Xspi_Ip_ReadModeType;


/*! @brief Clock edge used for sampling Rx data
 */
typedef enum
{
    XSPI_IP_DATA_RATE_SDR         = 0U,    /*!<  Single data rate    */
    XSPI_IP_DATA_RATE_DDR         = 1U,    /*!<  Double data rate    */
} Xspi_Ip_DataRateType;


/*! @brief Delay used for sampling Rx data
 */
typedef enum
{
    XSPI_IP_SAMPLE_DELAY_SAME_DQS              = 0U,    /*!<  Same DQS              */
    XSPI_IP_SAMPLE_DELAY_HALFCYCLE_EARLY_DQS   = 1U,    /*!<  Half-cycle early DQS  */
} Xspi_Ip_SampleDelayType;

/*! @brief Clock phase used for sampling Rx data
 */
typedef enum
{
    XSPI_IP_SAMPLE_PHASE_NON_INVERTED    = 0U,    /*!<  Sampling at non-inverted clock  */
    XSPI_IP_SAMPLE_PHASE_INVERTED        = 1U,    /*!<  Sampling at inverted clock      */
} Xspi_Ip_SamplePhaseType;

/*! @brief Alignment of outgoing data with serial clock
 */
typedef enum
{
    XSPI_IP_FLASH_DATA_ALIGN_REFCLK      = 0U,    /*!<  Data aligned with the posedge of Internal reference clock of XSPI  */
    XSPI_IP_FLASH_DATA_ALIGN_2X_REFCLK   = 1U,    /*!<  Data aligned with 2x serial flash half clock                          */
} Xspi_Ip_FlashDataAlignType;

/*! @brief DLL configuration modes
 */
typedef enum
{
    XSPI_IP_DLL_BYPASSED                 = 0U,    /*!<  DLL bypass mode                              */
    XSPI_IP_DLL_AUTO_UPDATE              = 2U,    /*!<  DLL auto update mode                         */
} Xspi_Ip_DllModeType;

/*! @brief Init callout pointer type
*/
typedef Xspi_Ip_StatusType (*Xspi_Ip_InitCalloutPtrType)(uint32 instance);

/*! @brief Reset callout pointer type
*/
typedef Xspi_Ip_StatusType (*Xspi_Ip_ResetCalloutPtrType)(uint32 instance);

/*! @brief Error Check callout pointer type
*/
typedef Xspi_Ip_StatusType (*Xspi_Ip_ErrorCheckCalloutPtrType)(uint32 instance);

/*! @brief Ecc Check callout pointer type
*/
typedef Xspi_Ip_StatusType (*Xspi_Ip_EccCheckCalloutPtrType)(uint32 instance, uint32 startAddress, uint32 dataLength);

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*!
 * @brief DLL configuration structure
 *
 * This structure contains initialization settings for DLL and slave delay chain
 */
typedef struct
{
    Xspi_Ip_DllModeType dllMode;      /*!< Mode in which DLL is used                                                              */
    boolean freqEnable;               /*!< Selects delay-chain for high frequency of operation                                    */
    uint8 referenceCounter;           /*!< Select the "n+1" interval of DLL phase detection and reference delay updating interval */
    uint8 resolution;                 /*!< Minimum resolution for DLL phase detector                                              */
    uint8 coarseDelay;                /*!< Coarse delay DLL slave delay chain                                                     */
    uint8 fineDelay;                  /*!< Fine delay DLL slave delay chain                                                       */
    uint8 tapSelect;                  /*!< Selects the Nth tap provided by the slave delay-chain                                  */
} Xspi_Ip_DllSettingsType;

/*!
 * Possible dividers for AHB subbuffers
 */
typedef enum
{
    XSPI_IP_SUBBUF_0        = 0U,  /*!< 0 bytes         */
    XSPI_IP_SUBBUF_1_DIV_2  = 1U,  /*!< Buffer size /2  */
    XSPI_IP_SUBBUF_1_DIV_4  = 2U,  /*!< Buffer size /4  */
    XSPI_IP_SUBBUF_1_DIV_8  = 3U,  /*!< Buffer size /8  */
    XSPI_IP_SUBBUF_1_DIV_16 = 4U,  /*!< Buffer size /16 */
} Xspi_Ip_SubbufDivType;

/*!
 * @brief AHB sub-buffer configuration structure
 *
 * This structure contains information about how a buffer is split into subbuffers
 */
typedef struct
{
    boolean enabled;                                          /*!< Sub-buffers are enabled for the current buffer            */
    Xspi_Ip_SubbufDivType divFactor[XSPI_IP_AHB_SUB_BUFFERS - 1];   /*!< Division factor for each sub-buffer except the last one   */
    uint16 startAddr[XSPI_IP_AHB_SUB_BUFFERS];                /*!< Start address for each sub-buffer                         */
    uint16 endAddr[XSPI_IP_AHB_SUB_BUFFERS];                  /*!< End address for each sub-buffer                           */
} Xspi_Ip_ControllerAhbSubbufConfigType;


/*!
 * @brief AHB configuration structure
 *
 * This structure is used to provide configuration parameters for AHB access
 * to the external flash
 */
typedef struct
{
    uint8 masters[XSPI_IP_AHB_BUFFERS];    /*!< List of AHB masters assigned to each buffer          */
    uint16 sizes[XSPI_IP_AHB_BUFFERS];     /*!< List of buffer sizes                                 */
    Xspi_Ip_ControllerAhbSubbufConfigType subbufs[XSPI_IP_AHB_BUFFERS];     /*!< List of sub-buffer configurations                                 */
    boolean allMasters;                    /*!< Indicates that any master may access the last buffer */
} Xspi_Ip_ControllerAhbConfigType;

typedef enum
{
    XSPI_IP_SFP_RESERVED,
    XSPI_IP_SFP_UNSECURE,
    XSPI_IP_SFP_SECURE,
    XSPI_IP_SFP_BOTH
} Xspi_Ip_SfpSaType;

typedef enum
{
    XSPI_IP_SFP_MASK_AND,
    XSPI_IP_SFP_MASK_OR
} Xspi_Ip_SfpMasktypeType;

typedef struct
{
    Xspi_Ip_SfpSaType SecureAttribute;
    Xspi_Ip_SfpMasktypeType MaskType;
    boolean Valid;
    boolean Lock;
    uint8 Mask;
    uint8 DomainId;
} Xspi_Ip_SfpMdadCfgType;

/** Access Control Policy for write operations */
typedef enum
{
    XSPI_IP_SFP_ACP_ALL_R           = 0U,
    XSPI_IP_SFP_ACP_SEC_RW_NONSEC_R = 4U,
    XSPI_IP_SFP_ACP_SECPRI_RW_ALL_R = 5U,
    XSPI_IP_SFP_ACP_ALL_RW          = 6U,
    XSPI_IP_SFP_ACP_PRI_RW_USER_R   = 7U
} Xspi_Ip_SfpAcpType;

typedef struct
{
    uint32 StartAddress;
    uint32 EndAddress;
    boolean Valid;
    boolean Lock;
    Xspi_Ip_SfpAcpType MdAcp[XSPI_MDAD_COUNT];
} Xspi_Ip_SfpFradCfgType;

typedef struct
{
    Xspi_Ip_SfpMdadCfgType Mdad[XSPI_MDAD_COUNT];
    Xspi_Ip_SfpFradCfgType Frad[XSPI_FRAD_COUNT];
    boolean SfpEnable;
} Xspi_Ip_SfpConfigType;

#if(XSPI_IP_USE_SFDP_CFG == STD_ON)
/*!
* @brief SFDP read mode can be supported
*/
typedef enum
{
    XSPI_IP_SFDP_READ_MODE_1S_1S_2S     = 0U,
    XSPI_IP_SFDP_READ_MODE_1S_2S_2S     = 1U,
    XSPI_IP_SFDP_READ_MODE_1S_1S_4S     = 2U,
    XSPI_IP_SFDP_READ_MODE_1S_4S_4S     = 3U,
    XSPI_IP_SFDP_READ_MODE_4S_4S_4S     = 4U,
    XSPI_IP_SFDP_READ_MODE_1S_1S_8S     = 5U,
    XSPI_IP_SFDP_READ_MODE_1S_8S_8S     = 6U,
    XSPI_IP_SFDP_READ_MODE_1S_1S_1S     = 7U,
    XSPI_IP_SFDP_READ_MODE_8D_8D_8D     = 8U
} Xspi_Ip_Sfdp_ReadModeType;

#endif

/*!
 * @brief Driver configuration structure
 *
 * This structure is used to provide configuration parameters for the XSPI driver
 * at initialization time.
 */
typedef struct
{
    Xspi_Ip_DataRateType dataRate;          /*!< Single/double data rate                                 */
    uint32 memSizeA1;                       /*!< Size of serial flash A1                                 */
    uint32 memSizeA2;                       /*!< Size of serial flash A2                                 */
    uint8 csHoldTime;                       /*!< CS hold time, expressed in serial clock cycles          */
    uint8 csSetupTime;                      /*!< CS setup time, expressed in serial clock cycles         */
    uint8 columnAddr;                       /*!< Width of the column address, 0 if not used              */
    boolean wordAddresable;                 /*!< True if serial flash is 16-bit addressable              */
    boolean dWordAddresable;                /*!< True if serial flash is 32-bit addressable              */
    Xspi_Ip_ReadModeType readModeA;         /*!< Read mode for incoming data from serial flash A         */
    Xspi_Ip_SampleDelayType sampleDelay;    /*!< Delay (in clock cycles) used for sampling Rx data       */
    Xspi_Ip_SamplePhaseType samplePhase;    /*!< Clock phase used for sampling Rx data                   */
    Xspi_Ip_DllSettingsType dllSettings[XSPI_REG(DLLCR_COUNT)];   /*!< DLL settings for sides A/B        */
    boolean differentialClockA;             /*!< Enable clock on differential CKN pad                    */
#if FEATURE_XSPI_EXT_DQS_LATENCY
    boolean dqsLatency;                     /*!< Enable DQS latency for reads (Hyperflash)               */
#endif
    Xspi_Ip_FlashDataAlignType dataAlign;   /*!< Alignment of output data sent to serial flash           */
    uint8 io2IdleValueA;                    /*!< (0 / 1) Logic level of IO[2] signal when not used on side A      */
    uint8 io3IdleValueA;                    /*!< (0 / 1) Logic level of IO[3] signal when not used on side A      */
    boolean dqsAsAnOutput;                  /*!< Enable DQS as an output                                 */
    boolean byteSwap;                       /*!< Enable byte swap in octal DDR mode                      */
    boolean enableHrespMask;                /*!< Enable AHB HRESP error masking for error scenarios      */
    boolean Tg1FixPrio;                     /*!< Prioritize TG1 over TG 2..N */
    uint32 errPayloadHigh;                  /*!< Error Payload High, if AHB HRESP error masking is enabled */
    uint32 errPayloadLow;                   /*!< Error Payload Low, if AHB HRESP error masking is enabled */
    uint16 ahbTimeout;                      /*!< AHB transactions timeout                                */
    uint32 transactionTimeout;              /*!< IP transactions timeout                                 */
    uint32 arbitrationTimeout;              /*!< Arbitration lock timeout                                */
    Xspi_Ip_SfpConfigType SfpCfg;
    Xspi_Ip_ControllerAhbConfigType ahbConfig;  /*!< AHB buffers configuration                     */
    boolean lockConfiguration;              /*!< Locks configuration registers after Init until next reset  */
#if (XSPI_IP_CHECK_CFG_CRC == STD_ON)
    Xspi_Ip_CrcType memCtrlCfgCRC;              /* Controller configuration CRC */
#endif
} Xspi_Ip_ControllerConfigType;

 /*!
 * @brief Status register configuration structure
 *
 * This structure contains information about the status registers of the external flash
 */
typedef struct
{
    uint16 statusRegReadLut;         /*!< Command used to read the status register                                         */
    uint16 statusRegWriteLut;        /*!< Command used to write the status register                                        */
    uint16 writeEnableLut;           /*!< Write enable command used before write or erase operations                       */
    uint8 regSize;                   /*!< Size in bytes of status register                                                 */
    uint32 busyMask;                 /*!< Mask of bits determining the busy/idle state of the flash                        */
    uint32 busyValue;                /*!< Value of "busy" bits which indicates that the device is busy                     */
    uint32 idleValue;                /*!< Value of "busy" bits which indicates that the device is idle                     */
    uint16 clearErrLut;              /*!< Write enable command used before write or erase operations                       */
    uint8 writeEnableOffset;         /*!< Position of "write enable" bit inside status register                            */
    uint8 blockProtectionOffset;     /*!< Offset of block protection bits inside status register                           */
    uint8 blockProtectionWidth;      /*!< Width of block protection bitfield                                               */
    uint32 blockProtectionValue;     /*!< Value of block protection bitfield, indicate the protected area                  */
} Xspi_Ip_StatusConfigType;


 /*!
 * @brief Describes one type of erase
 *
 * This structure contains information about one type of erase supported by the external flash
 */
typedef struct
{
    uint16 eraseLut;              /*!< Lut index for erase command */
    uint8 size;                   /*!< Size of the erased area: 2 ^ size; e.g. 0x0C means 4 Kbytes */
} Xspi_Ip_EraseVarConfigType;


 /*!
 * @brief Erase capabilities configuration structure
 *
 * This structure contains information about the erase capabilities of the external flash
 */
typedef struct
{
    Xspi_Ip_EraseVarConfigType eraseTypes[XSPI_IP_ERASE_TYPES];      /*!< Erase types supported by the device  */
    uint16 chipEraseLut;                                             /*!< Lut index for chip erase command */
} Xspi_Ip_EraseConfigType;


 /*!
 * @brief Read Id capabilities configuration structure
 *
 * This structure contains information about the read manufacturer/device ID command
 */
typedef struct
{
    uint16 readIdLut;                                   /*!< Read Id command                                  */
    uint8  readIdSize;                                  /*!< Size of data returned by Read Id command         */
    uint8  readIdExpected[FEATURE_EXFLS_FLASH_MDID_SIZE]; /*!< Device ID configured value (Memory density | Memory type | Manufacturer ID) */
} Xspi_Ip_ReadIdConfigType;


 /*!
 * @brief Suspend capabilities configuration structure
 *
 * This structure contains information about the Program / Erase Suspend capabilities of the external flash
 */
typedef struct
{
    uint16 eraseSuspendLut;       /*!< Lut index for the erase suspend operation   */
    uint16 eraseResumeLut;        /*!< Lut index for the erase resume operation    */
    uint16 programSuspendLut;     /*!< Lut index for the program suspend operation */
    uint16 programResumeLut;      /*!< Lut index for the program resume operation  */
} Xspi_Ip_SuspendConfigType;


/*!
 * @brief Soft Reset capabilities configuration structure
 *
 * This structure contains information about the Soft Reset capabilities of the external flash
 */
typedef struct
{
    uint16 resetCmdLut;                   /*!< First command in reset sequence            */
    uint8 resetCmdCount;                  /*!< Number of commands in reset sequence       */
} Xspi_Ip_ResetConfigType;


/*!
 * @brief Optional commands
 * Additional flash commands to be programmed to the LUT.
 */
typedef struct
{
    uint16 OptionalLut1;
    uint16 OptionalLut2;
} Xspi_Ip_OptionalLutsType;


/*!
 * @brief List of LUT sequences.
 *
 * List of LUT sequences. Each sequence describes a command to the external flash. Sequences are separated by a 0 operation
 */
typedef struct
{
    uint16 opCount;                    /*!< Number of operations in the LUT table    */
    Xspi_Ip_InstrOpType *lutOps;       /*!< List of operations                       */
} Xspi_Ip_LutConfigType;

/*!
 * @brief Initialization operation
 *
 * This structure describes one initialization operation.
 */
typedef struct
{
    Xspi_Ip_OpType                       opType;       /*!< Operation type                                                                              */
    uint16                               command1Lut;  /*!< Index of first command sequence in Lut; for RMW type this is the read command               */
    uint16                               command2Lut;  /*!< Index of second command sequence in Lut, only used for RMW type, this is the write command  */
    uint16                               weLut;        /*!< Index of write enable sequence in Lut, only used for Write and RMW type                     */
    uint32                               addr;         /*!< Address, if used in command.                                                                */
    uint8                                size;         /*!< Size in bytes of configuration register                                                     */
    uint8                                shift;        /*!< Position of configuration field inside the register                                         */
    uint8                                width;        /*!< Width in bits of configuration field.                                                       */
    uint32                               value;        /*!< Value to set in the field                                                                   */
    const Xspi_Ip_ControllerConfigType  *ctrlCfgPtr;   /*!< New controller configuration, valid only for XSPI_IP_OP_TYPE_XSPI_CFG type                  */
} Xspi_Ip_InitOperationType;


/*!
 * @brief Initialization sequence
 *
 * Describe sequence that will be performed only once during initialization to put the flash in the desired state for operation.
 * This may include, for example, setting the QE bit, activating 4-byte addressing, activating XPI mode
 */
typedef struct
{
    uint8 opCount;                                     /*!< Number of operations  */
    Xspi_Ip_InitOperationType * operations;            /*!< List of operations    */
} Xspi_Ip_InitConfigType;


/*!
 * @brief Driver configuration structure
 *
 * This structure is used to provide configuration parameters for the external flash driver
 * at initialization time.
 */
typedef struct
{
    Xspi_Ip_FlashMemoryType memType;                      /*!< Mmemory device type                              */
#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
    const Xspi_Ip_HyperRamConfigType * hrConfig;          /*!< HyperRam configuration, NULL if not used         */
#endif
    uint32 memSize;                                       /*!< Memory size (in bytes)                                     */
    uint32 pageSize;                                      /*!< Page size (in bytes)                                       */
    uint16 readLut;                                       /*!< Command used to read data from flash                       */
    uint16 writeLut;                                      /*!< Command used to write data to flash                        */
    Xspi_Ip_ReadIdConfigType readIdSettings;              /*!< Erase settings of the external flash                       */
    Xspi_Ip_EraseConfigType eraseSettings;                /*!< Erase settings of the external flash                       */
    Xspi_Ip_StatusConfigType statusConfig;                /*!< Status register information                                */
    Xspi_Ip_SuspendConfigType suspendSettings;            /*!< Program / Erase Suspend settings                           */
    Xspi_Ip_ResetConfigType initResetSettings;            /*!< Soft Reset settings, used for first time reset             */
    Xspi_Ip_OptionalLutsType optionalLuts;                /*!< Additional flash commands to be programmed to the LUT      */
    Xspi_Ip_InitConfigType initConfiguration;             /*!< Operations for initial flash configuration                 */
    Xspi_Ip_LutConfigType lutSequences;                   /*!< List of LUT sequences describing flash commands            */
    uint16 accessRights[XSPI_MDAD_COUNT];                 /*!< Access rights to LUT sequences for each TG                 */
    Xspi_Ip_InitCalloutPtrType initCallout;               /*!< Pointer to init callout                                    */
    Xspi_Ip_ResetCalloutPtrType resetCallout;             /*!< Pointer to reset callout                                   */
    Xspi_Ip_ErrorCheckCalloutPtrType errorCheckCallout;   /*!< Pointer to error check callout                             */
    Xspi_Ip_EccCheckCalloutPtrType eccCheckCallout;       /*!< Pointer to ecc check callout                               */
    const Xspi_Ip_ControllerConfigType * ctrlAutoCfgPtr;  /*!< Initial controller configuration, if needed                */
#if (XSPI_IP_CHECK_CFG_CRC == STD_ON)
    Xspi_Ip_CrcType memCfgCRC;                            /*!< Memory device configuration CRC                  */
#endif
} Xspi_Ip_MemoryConfigType;


/*!
 * @brief Flash-controller conections configuration structure
 *
 * This structure specifies thte connecctions of each flash device to XSPI controllers
 * at initialization time.
 */
typedef struct
{
    uint32 xspiInstance;                              /*!< XSPI Instance where this device is connected      */
    Xspi_Ip_ConnectionType connectionType;            /*!< Device connection to XSPI module                  */
    uint8 hifInstance ;                               /*!< Host interface used for flash operations          */
    uint8 memAlignment;                               /*!< Memory alignment required by the external flash  */
    boolean initDevice ;                              /*!< Perform initial configuration of the flash device */
#if(XSPI_IP_USE_SFDP_CFG == STD_ON)
    const Xspi_Ip_Sfdp_ReadModeType *pSfdpReadModeList;     /*!< List of SFDP read modes will be scanned when ussing SFDP discovery */
    uint8 sfdpReadModeCount;                          /*!< Sise of the list SFDP read modes                                   */
#endif
#if (XSPI_IP_CHECK_CFG_CRC == STD_ON)
    Xspi_Ip_CrcType memCntCfgCRC;                     /*!< Flash-controller conections configuration CRC                      */
#endif
} Xspi_Ip_MemoryConnectionType;


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* XSPI_IP_TYPES_H */
