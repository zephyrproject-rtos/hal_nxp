/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef QSPI_IP_TYPES_H
#define QSPI_IP_TYPES_H

/**
*   @file Qspi_Ip_Types.h
*
*   @addtogroup IPV_QSPI
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"
#include "Qspi_Ip_Features.h"
#include "Qspi_Ip_CfgDefines.h"
#include "Qspi_Ip_HyperflashTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_TYPES_VENDOR_ID_CFG                    43
#define QSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION_CFG     4
#define QSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION_CFG     7
#define QSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION_CFG  0
#define QSPI_IP_TYPES_SW_MAJOR_VERSION_CFG             2
#define QSPI_IP_TYPES_SW_MINOR_VERSION_CFG             0
#define QSPI_IP_TYPES_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Qspi_Ip_Types header file and Std_Types.h header file are of the same Autosar version */
    #if ((QSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (QSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION_CFG != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Autosar Version Numbers of Qspi_Ip_Types.h and Std_Types.h are different"
    #endif
#endif

/* Check if current file and Qspi_Ip_Features header file are of the same vendor */
#if (QSPI_IP_TYPES_VENDOR_ID_CFG != QSPI_IP_FEATURES_VENDOR_ID_CFG)
    #error "Qspi_Ip_Types.h and Qspi_Ip_Features.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Features header file are of the same Autosar version */
#if ((QSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION_CFG    != QSPI_IP_FEATURES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (QSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION_CFG    != QSPI_IP_FEATURES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (QSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION_CFG != QSPI_IP_FEATURES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Types.h and Qspi_Ip_Features.h are different"
#endif
/* Check if current file and Qspi_Ip_Features header file are of the same Software version */
#if ((QSPI_IP_TYPES_SW_MAJOR_VERSION_CFG != QSPI_IP_FEATURES_SW_MAJOR_VERSION_CFG) || \
     (QSPI_IP_TYPES_SW_MINOR_VERSION_CFG != QSPI_IP_FEATURES_SW_MINOR_VERSION_CFG) || \
     (QSPI_IP_TYPES_SW_PATCH_VERSION_CFG != QSPI_IP_FEATURES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Qspi_Ip_Types.h and Qspi_Ip_Features.h are different"
#endif

/* Check if current file and Qspi_Ip_CfgDefines header file are of the same vendor */
#if (QSPI_IP_TYPES_VENDOR_ID_CFG != QSPI_IP_VENDOR_ID_CFG_DEFINES)
    #error "Qspi_Ip_Types.h and Qspi_Ip_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_CfgDefines header file are of the same Autosar version */
#if ((QSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION_CFG    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES) || \
     (QSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION_CFG    != QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG_DEFINES) || \
     (QSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION_CFG != QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG_DEFINES) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Types.h and Qspi_Ip_CfgDefines.h are different"
#endif
/* Check if current file and Qspi_Ip_CfgDefines header file are of the same Software version */
#if ((QSPI_IP_TYPES_SW_MAJOR_VERSION_CFG != QSPI_IP_SW_MAJOR_VERSION_CFG_DEFINES) || \
     (QSPI_IP_TYPES_SW_MINOR_VERSION_CFG != QSPI_IP_SW_MINOR_VERSION_CFG_DEFINES) || \
     (QSPI_IP_TYPES_SW_PATCH_VERSION_CFG != QSPI_IP_SW_PATCH_VERSION_CFG_DEFINES) \
    )
    #error "Software Version Numbers of Qspi_Ip_Types.h and Qspi_Ip_CfgDefines.h are different"
#endif

/* Check if current file and Qspi_Ip_HyperflashTypes header file are of the same vendor */
#if (QSPI_IP_TYPES_VENDOR_ID_CFG != QSPI_IP_HYPERFLASHTYPES_VENDOR_ID)
    #error "Qspi_Ip_Types.h and Qspi_Ip_HyperflashTypes.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_HyperflashTypes header file are of the same Autosar version */
#if ((QSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION_CFG    != QSPI_IP_HYPERFLASHTYPES_AR_RELEASE_MAJOR_VERSION) || \
     (QSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION_CFG    != QSPI_IP_HYPERFLASHTYPES_AR_RELEASE_MINOR_VERSION) || \
     (QSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION_CFG != QSPI_IP_HYPERFLASHTYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Types.h and Qspi_Ip_HyperflashTypes.h are different"
#endif
/* Check if current file and Qspi_Ip_HyperflashTypes header file are of the same Software version */
#if ((QSPI_IP_TYPES_SW_MAJOR_VERSION_CFG != QSPI_IP_HYPERFLASHTYPES_SW_MAJOR_VERSION) || \
     (QSPI_IP_TYPES_SW_MINOR_VERSION_CFG != QSPI_IP_HYPERFLASHTYPES_SW_MINOR_VERSION) || \
     (QSPI_IP_TYPES_SW_PATCH_VERSION_CFG != QSPI_IP_HYPERFLASHTYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Qspi_Ip_Types.h and Qspi_Ip_HyperflashTypes.h are different"
#endif


/*******************************************************************************
 * Macros.
 ******************************************************************************/

#if (CPU_TYPE == CPU_TYPE_64)
    typedef uint64 Qspi_Ip_UintPtrType;
#elif (CPU_TYPE == CPU_TYPE_32)
    typedef uint32 Qspi_Ip_UintPtrType;
#else
    #error "Unsupported CPU_TYPE"
#endif

/*! Number of erase types that can be supported by a flash device */
#define QSPI_IP_ERASE_TYPES                 (4U)

/*! @brief Number of AHB buffers in the device */
#define QSPI_IP_AHB_BUFFERS                 4

/*! Invalid index in virtual LUT, used for unsupported features */
#define QSPI_IP_LUT_INVALID                 (uint16)0xFFFFU

/*! End operation for a LUT sequence */
#define QSPI_IP_LUT_SEQ_END                 (uint16)0x0U

/*! Pack the two operations into a LUT register (each operation is a pair of instruction-operand) */
#define QSPI_IP_PACK_LUT_REG(ops0, ops1)    ((uint32)(ops0) + ((uint32)(ops1) << 16U))


/*******************************************************************************
 * Enumerations.
 ******************************************************************************/

/*! @brief qspi return codes
 */
typedef enum
{
    STATUS_QSPI_IP_SUCCESS              = 0x00U,   /*!< Successful job */
    STATUS_QSPI_IP_ERROR                = 0x01U,   /*!< IP is performing an operation */
    STATUS_QSPI_IP_BUSY                 = 0x02U,   /*!< Error - general code */
    STATUS_QSPI_IP_TIMEOUT              = 0x03U,   /*!< Error - exceeded timeout */
    STATUS_QSPI_IP_ERROR_PROGRAM_VERIFY = 0x04U,   /*!< Error - selected memory area doesn't contain desired value */
    STATUS_QSPI_IP_ERROR_BLANK_CHECK    = 0x05U,   /*!< Error - selected memory area isn't in erased state */
} Qspi_Ip_StatusType;


/*! @brief flash connection to the QSPI module
 */
typedef enum
{
    QSPI_IP_SIDE_A1    = 0x00U,  /*!< Serial flash connected on side A1    */
    QSPI_IP_SIDE_A2    = 0x01U,  /*!< Serial flash connected on side A2    */
    QSPI_IP_SIDE_B1    = 0x02U,  /*!< Serial flash connected on side B1    */
    QSPI_IP_SIDE_B2    = 0x03U,  /*!< Serial flash connected on side B2    */
} Qspi_Ip_ConnectionType;


/*! @brief flash operation type
 */
typedef enum
{
    QSPI_IP_OP_TYPE_CMD          = 0x00U,  /*!< Simple command                              */
    QSPI_IP_OP_TYPE_WRITE_REG    = 0x01U,  /*!< Write value in external flash register      */
    QSPI_IP_OP_TYPE_RMW_REG      = 0x02U,  /*!< RMW command on external flash register      */
    QSPI_IP_OP_TYPE_READ_REG     = 0x03U,  /*!< Read external flash register until expected value is read    */
    QSPI_IP_OP_TYPE_QSPI_CFG     = 0x04U,  /*!< Re-configure QSPI controller                */
} Qspi_Ip_OpType;

/*! @brief Lut commands
 */
typedef enum
{
    QSPI_IP_LUT_INSTR_STOP            = (0U << 10U),    /*!<  End of sequence                           */
    QSPI_IP_LUT_INSTR_CMD             = (1U << 10U),    /*!<  Command                                   */
    QSPI_IP_LUT_INSTR_ADDR            = (2U << 10U),    /*!<  Address                                   */
    QSPI_IP_LUT_INSTR_DUMMY           = (3U << 10U),    /*!<  Dummy cycles                              */
    QSPI_IP_LUT_INSTR_MODE            = (4U << 10U),    /*!<  8-bit mode                                */
    QSPI_IP_LUT_INSTR_MODE2           = (5U << 10U),    /*!<  2-bit mode                                */
    QSPI_IP_LUT_INSTR_MODE4           = (6U << 10U),    /*!<  4-bit mode                                */
    QSPI_IP_LUT_INSTR_READ            = (7U << 10U),    /*!<  Read data                                 */
    QSPI_IP_LUT_INSTR_WRITE           = (8U << 10U),    /*!<  Write data                                */
    QSPI_IP_LUT_INSTR_JMP_ON_CS       = (9U << 10U),    /*!<  Jump on chip select deassert and stop     */
    QSPI_IP_LUT_INSTR_ADDR_DDR        = (10U << 10U),   /*!<  Address - DDR mode                        */
    QSPI_IP_LUT_INSTR_MODE_DDR        = (11U << 10U),   /*!<  8-bit mode - DDR mode                     */
    QSPI_IP_LUT_INSTR_MODE2_DDR       = (12U << 10U),   /*!<  2-bit mode - DDR mode                     */
    QSPI_IP_LUT_INSTR_MODE4_DDR       = (13U << 10U),   /*!<  4-bit mode - DDR mode                     */
    QSPI_IP_LUT_INSTR_READ_DDR        = (14U << 10U),   /*!<  Read data - DDR mode                      */
    QSPI_IP_LUT_INSTR_WRITE_DDR       = (15U << 10U),   /*!<  Write data - DDR mode                     */
    QSPI_IP_LUT_INSTR_DATA_LEARN      = (16U << 10U),   /*!<  Data learning pattern                     */
    QSPI_IP_LUT_INSTR_CMD_DDR         = (17U << 10U),   /*!<  Command - DDR mode                        */
    QSPI_IP_LUT_INSTR_CADDR           = (18U << 10U),   /*!<  Column address                            */
    QSPI_IP_LUT_INSTR_CADDR_DDR       = (19U << 10U),   /*!<  Column address - DDR mode                 */
    QSPI_IP_LUT_INSTR_JMP_TO_SEQ      = (20U << 10U),   /*!<  Jump on chip select deassert and continue */
} Qspi_Ip_LutCommandsType;

/*! @brief Lut pad options
 */
typedef enum
{
    QSPI_IP_LUT_PADS_1              = (0U << 8U),    /*!<  1 Pad      */
    QSPI_IP_LUT_PADS_2              = (1U << 8U),    /*!<  2 Pads     */
    QSPI_IP_LUT_PADS_4              = (2U << 8U),    /*!<  4 Pads     */
    QSPI_IP_LUT_PADS_8              = (3U << 8U),    /*!<  8 Pads     */
} Qspi_Ip_LutPadsType;

/**
* brief Size of data to be processeed by CRC.
*/
typedef enum
{
    QSPI_IP_CRC_8_BITS = 0,
    QSPI_IP_CRC_16_BITS
} Qspi_Ip_CrcDataSizeType;

/*!
 * @brief Operation in a LUT sequence.
 *
 * This type describes one basic operation inside a LUT sequence. Each operation contains:
 *  - instruction (6 bits)
 *  - number of PADs (2 bits)
 *  - operand (8 bits)
 * Qspi_Ip_LutCommandsType and Qspi_Ip_LutPadsType types should be used to form operations
 */
typedef uint16 Qspi_Ip_InstrOpType;

/**
* @brief          Mem CRC Type
* @details        CRC computed over config set
*/
typedef uint16 Qspi_Ip_CrcType;

/*! @brief Read mode
 */
typedef enum
{
#if (FEATURE_QSPI_INTERNAL_DQS == 1)
    QSPI_IP_READ_MODE_INTERNAL_DQS        = 0U,  /*!< Use internally generated strobe signal       */
#endif
#if (FEATURE_QSPI_LOOPBACK == 1)
    QSPI_IP_READ_MODE_LOOPBACK            = 1U,  /*!< Use loopback clock from PAD as strobe signal */
#endif
#if (FEATURE_QSPI_LOOPBACK_DQS == 1)
    QSPI_IP_READ_MODE_LOOPBACK_DQS        = 2U,  /*!< Use loopback clock from PAD as strobe signal */
#endif
    QSPI_IP_READ_MODE_EXTERNAL_DQS        = 3U,  /*!< Use external strobe signal                   */
} Qspi_Ip_ReadModeType;


/*! @brief Clock phase used for sampling Rx data
 */
typedef enum
{
    QSPI_IP_DATA_RATE_SDR         = 0U,    /*!<  Single data rate    */
    QSPI_IP_DATA_RATE_DDR         = 1U,    /*!<  Double data rate    */
} Qspi_Ip_DataRateType;


/*! @brief Delay used for sampling Rx data
 */
typedef enum
{
    QSPI_IP_SAMPLE_DELAY_SAME_DQS              = 0U,    /*!<  Same DQS              */
    QSPI_IP_SAMPLE_DELAY_HALFCYCLE_EARLY_DQS   = 1U,    /*!<  Half-cycle early DQS  */
} Qspi_Ip_SampleDelayType;

/*! @brief Clock phase used for sampling Rx data
 */
typedef enum
{
    QSPI_IP_SAMPLE_PHASE_NON_INVERTED    = 0U,    /*!<  Sampling at non-inverted clock  */
    QSPI_IP_SAMPLE_PHASE_INVERTED        = 1U,    /*!<  Sampling at inverted clock      */
} Qspi_Ip_SamplePhaseType;

/*! @brief Alignment of outgoing data with serial clock
 */
typedef enum
{
    QSPI_IP_FLASH_DATA_ALIGN_REFCLK      = 0U,    /*!<  Data aligned with the posedge of Internal reference clock of QSPI  */
    QSPI_IP_FLASH_DATA_ALIGN_2X_REFCLK   = 1U,    /*!<  Data aligned with 2x serial flash half clock                          */
} Qspi_Ip_FlashDataAlignType;

/*! @brief DLL configuration modes
 */
typedef enum
{
    QSPI_IP_DLL_BYPASSED                 = 0U,    /*!<  DLL bypass mode                              */
    QSPI_IP_DLL_MANUAL_UPDATE            = 1U,    /*!<  DLL manual update mode                       */
    QSPI_IP_DLL_AUTO_UPDATE              = 2U,    /*!<  DLL auto update mode                         */
} Qspi_Ip_DllModeType;

/*! @brief Init callout pointer type
*/
typedef Qspi_Ip_StatusType (*Qspi_Ip_InitCalloutPtrType)(uint32 instance);

/*! @brief Reset callout pointer type
*/
typedef Qspi_Ip_StatusType (*Qspi_Ip_ResetCalloutPtrType)(uint32 instance);

/*! @brief Error Check callout pointer type
*/
typedef Qspi_Ip_StatusType (*Qspi_Ip_ErrorCheckCalloutPtrType)(uint32 instance);

/*! @brief Ecc Check callout pointer type
*/
typedef Qspi_Ip_StatusType (*Qspi_Ip_EccCheckCalloutPtrType)(uint32 instance, uint32 startAddress, uint32 dataLength);


/*******************************************************************************
* Definitions
******************************************************************************/

/*!
 * @brief DLL configuration structure
 *
 * This structure contains initialization settings for DLL and slave delay chain
 */
typedef struct
{
    Qspi_Ip_DllModeType dllMode;      /*!< Mode in which DLL is used                                                              */
    boolean freqEnable;               /*!< Selects delay-chain for high frequency of operation                                    */
    uint8 referenceCounter;           /*!< Select the "n+1" interval of DLL phase detection and reference delay updating interval */
    uint8 resolution;                 /*!< Minimum resolution for DLL phase detector                                              */
    uint8 coarseDelay;                /*!< Coarse delay DLL slave delay chain                                                     */
    uint8 fineDelay;                  /*!< Fine delay DLL slave delay chain                                                       */
    uint8 tapSelect;                  /*!< Selects the Nth tap provided by the slave delay-chain                                  */
} Qspi_Ip_DllSettingsType;

/*!
 * @brief AHB configuration structure
 *
 * This structure is used to provide configuration parameters for AHB access
 * to the external flash
 */
typedef struct
{
    uint8 masters[QSPI_IP_AHB_BUFFERS];    /*!< List of AHB masters assigned to each buffer          */
    uint16 sizes[QSPI_IP_AHB_BUFFERS];     /*!< List of buffer sizes                                 */
    boolean allMasters;                    /*!< Indicates that any master may access the last buffer */
} Qspi_Ip_ControllerAhbConfigType;



#if (FEATURE_QSPI_HAS_SFP == 1)

/** Access control type */
typedef enum
{
    QSPI_IP_SFP_ALL,
    QSPI_IP_SFP_MDAD,
    QSPI_IP_SFP_FRAD
} Qspi_Ip_Sfp_AccessControlType;

#if (QSPI_IP_SFP_ENABLE_GLOBAL == STD_ON)

#if (QSPI_IP_SFP_ENABLE_MDAD == STD_ON)

typedef enum
{
    QSPI_IP_SFP_RESERVED,
    QSPI_IP_SFP_UNSECURE,
    QSPI_IP_SFP_SECURE,
    QSPI_IP_SFP_BOTH
} Qspi_Ip_SfpSaType;

typedef enum
{
    QSPI_IP_SFP_MASK_AND,
    QSPI_IP_SFP_MASK_OR
} Qspi_Ip_SfpMasktypeType;

typedef struct
{
    Qspi_Ip_SfpSaType SecureAttribute;
    Qspi_Ip_SfpMasktypeType MaskType;
    boolean Valid;
    uint8 Mask;
    uint8 DomainId;
} Qspi_Ip_SfpTgCfgType;

#endif /* QSPI_IP_SFP_ENABLE_MDAD */

#if (QSPI_IP_SFP_ENABLE_FRAD == STD_ON)

/** FRADn_WORD3 :: Exclusive access Lock [EAL] */
typedef enum
{
    QSPI_IP_SFP_EAL_DISABLED    = 0,
    QSPI_IP_SFP_EAL_NONE         = 2,
    QSPI_IP_SFP_EAL_OWNER        = 3
} Qspi_Ip_SfpEalType;

/** Access Control Policy for write operations */
typedef enum
{
    QSPI_IP_SFP_ACP_NONE = 0,
    QSPI_IP_SFP_ACP_SECURE = 4,
    QSPI_IP_SFP_ACP_SECURE_PRIVILEGED = 5,
    QSPI_IP_SFP_ACP_ALL = 6,
    QSPI_IP_SFP_ACP_PRIVILEGED = 7
} Qspi_Ip_SfpAcpType;

typedef struct
{
    uint32 StartAddress;
    uint32 EndAddress;
    boolean Valid;
    Qspi_Ip_SfpAcpType Md0Acp;
    Qspi_Ip_SfpAcpType Md1Acp;
    Qspi_Ip_SfpEalType ExclusiveAccessLock;
    uint8 ExclusiveAccessOwner;
} Qspi_Ip_SfpFradCfgType;

#endif /* QSPI_IP_SFP_ENABLE_FRAD */

typedef struct
{
    uint32 MasterTimeout;
#if (QSPI_IP_SFP_ENABLE_MDAD == STD_ON)
    Qspi_Ip_SfpTgCfgType Tg[QuadSPI_MDAD_COUNT];
#endif
#if (QSPI_IP_SFP_ENABLE_FRAD == STD_ON)
    Qspi_Ip_SfpFradCfgType Frad[QuadSPI_FRAD_COUNT];
#endif
} Qspi_Ip_SfpConfigType;

#endif /* QSPI_IP_SFP_ENABLE_GLOBAL */

#endif /* FEATURE_QSPI_HAS_SFP */


/*!
 * @brief Driver configuration structure
 *
 * This structure is used to provide configuration parameters for the qspi driver
 * at initialization time.
 */
typedef struct
{

    Qspi_Ip_DataRateType dataRate;          /*!< Single/double data rate                                 */
    uint32 memSizeA1;                       /*!< Size of serial flash A1                                 */
    uint32 memSizeA2;                       /*!< Size of serial flash A2                                 */
    uint32 memSizeB1;                       /*!< Size of serial flash B1                                 */
    uint32 memSizeB2;                       /*!< Size of serial flash B2                                 */
    uint8 csHoldTime;                       /*!< CS hold time, expressed in serial clock cycles          */
    uint8 csSetupTime;                      /*!< CS setup time, expressed in serial clock cycles         */
    uint8 columnAddr;                       /*!< Width of the column address, 0 if not used              */
    boolean wordAddresable;                 /*!< True if serial flash is word addressable                */
    Qspi_Ip_ReadModeType readModeA;         /*!< Read mode for incoming data from serial flash A         */
    Qspi_Ip_ReadModeType readModeB;         /*!< Read mode for incoming data from serial flash B         */
    Qspi_Ip_SampleDelayType sampleDelay;    /*!< Delay (in clock cycles) used for sampling Rx data       */
    Qspi_Ip_SamplePhaseType samplePhase;    /*!< Clock phase used for sampling Rx data                   */

    Qspi_Ip_DllSettingsType dllSettingsA;   /*!< DLL settings for side A                                 */
    Qspi_Ip_DllSettingsType dllSettingsB;   /*!< DLL settings for side B                                 */

    boolean centerAlignedStrobeA;           /*!< Enable center-aligned read strobe                       */
    boolean centerAlignedStrobeB;           /*!< Enable center-aligned read strobe                       */
    boolean differentialClockA;             /*!< Enable clock on differential CKN pad                    */
    boolean differentialClockB;             /*!< Enable clock on differential CKN pad                    */
    Qspi_Ip_FlashDataAlignType dataAlign;   /*!< Alignment of output data sent to serial flash           */
    uint8 io2IdleValueA;                    /*!< (0 / 1) Logic level of IO[2] signal when not used on side A      */
    uint8 io3IdleValueA;                    /*!< (0 / 1) Logic level of IO[3] signal when not used on side A      */
    uint8 io2IdleValueB;                    /*!< (0 / 1) Logic level of IO[2] signal when not used on side B      */
    uint8 io3IdleValueB;                    /*!< (0 / 1) Logic level of IO[3] signal when not used on side B      */
    boolean dqsAsAnOutput;                  /*!< Enable DQS as an output                                 */
    boolean byteSwap;                       /*!< Enable byte swap in octal DDR mode                      */
#if (FEATURE_QSPI_HAS_SFP == 1)
#if (QSPI_IP_SFP_ENABLE_GLOBAL == STD_ON)
    Qspi_Ip_SfpConfigType SfpCfg;
#endif
#endif
    Qspi_Ip_ControllerAhbConfigType ahbConfig;  /*!< AHB buffers configuration                     */
#if (QSPI_IP_CHECK_CFG_CRC == STD_ON)
    Qspi_Ip_CrcType memCtrlCfgCRC;              /* Controller configuration CRC */
#endif
} Qspi_Ip_ControllerConfigType;

 /*!
 * @brief Status register configuration structure
 *
 * This structure contains information about the status registers of the external flash
 */
typedef struct
{
    uint16 statusRegInitReadLut;     /*!< Command used to read the status register during initialization                   */
    uint16 statusRegReadLut;         /*!< Command used to read the status register                                         */
    uint16 statusRegWriteLut;        /*!< Command used to write the status register                                        */
    uint16 writeEnableSRLut;         /*!< Write enable command used before writing to status register                      */
    uint16 writeEnableLut;           /*!< Write enable command used before write or erase operations                       */
    uint8 regSize;                   /*!< Size in bytes of status register                                                 */
    uint8 busyOffset;                /*!< Position of "busy" bit inside status register                                    */
    uint8 busyValue;                 /*!< Value of "busy" bit which indicates that the device is busy; can be 0 or 1       */
    uint8 writeEnableOffset;         /*!< Position of "write enable" bit inside status register                            */
    uint8 blockProtectionOffset;     /*!< Offset of block protection bits inside status register                           */
    uint8 blockProtectionWidth;      /*!< Width of block protection bitfield                                               */
    uint8 blockProtectionValue;      /*!< Value of block protection bitfield, indicate the protected area                  */
} Qspi_Ip_StatusConfigType;


 /*!
 * @brief Describes one type of erase
 *
 * This structure contains information about one type of erase supported by the external flash
 */
typedef struct
{
    uint16 eraseLut;              /*!< Lut index for erase command */
    uint8 size;                   /*!< Size of the erased area: 2 ^ size; e.g. 0x0C means 4 Kbytes */
} Qspi_Ip_EraseVarConfigType;


 /*!
 * @brief Erase capabilities configuration structure
 *
 * This structure contains information about the erase capabilities of the external flash
 */
typedef struct
{
    Qspi_Ip_EraseVarConfigType eraseTypes[QSPI_IP_ERASE_TYPES];      /*!< Erase types supported by the device  */
    uint16 chipEraseLut;                                             /*!< Lut index for chip erase command */
} Qspi_Ip_EraseConfigType;


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
} Qspi_Ip_ReadIdConfigType;


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
} Qspi_Ip_SuspendConfigType;


/*!
 * @brief Soft Reset capabilities configuration structure
 *
 * This structure contains information about the Soft Reset capabilities of the external flash
 */
typedef struct
{
    uint16 resetCmdLut;                   /*!< First command in reset sequence            */
    uint8 resetCmdCount;                  /*!< Number of commands in reset sequence       */
} Qspi_Ip_ResetConfigType;


/*!
* @brief Last command that was executed by the device flash
*/
typedef enum
{
    QSPI_IP_LAST_COMMAND_NONE                = 0U,  /* Command in progress                                 */
    QSPI_IP_LAST_COMMAND_WRITE               = 1U,  /* Erase command                                       */
    QSPI_IP_LAST_COMMAND_ERASE               = 2U,  /* write command                                       */
    QSPI_IP_LAST_COMMAND_WRITE_BUFFER_ABORT  = 3U,  /* Write buffer abort or CRC calculation abort         */
    QSPI_IP_LAST_COMMAND_WRITE_SUSPEND       = 4U,  /* Write suspend command                               */
    QSPI_IP_LAST_COMMAND_ERASE_SUSPEND       = 5U,  /* Erase command                                       */
    QSPI_IP_LAST_COMMAND_SECTOR_ERASE_STATUS = 6U,  /* Sector erase command                                */
    QSPI_IP_LAST_COMMAND_CRC_SUSPEND         = 7U   /* CRC suspend command                                 */
} Qspi_Ip_LastCommandType;


/*!
 * @brief List of LUT sequences.
 *
 * List of LUT sequences. Each sequence describes a command to the external flash. Sequences are separated by a 0 operation
 */
typedef struct
{
    uint16 opCount;                    /*!< Number of operations in the LUT table    */
    Qspi_Ip_InstrOpType *lutOps;       /*!< List of operations                       */
} Qspi_Ip_LutConfigType;


/*!
 * @brief Initialization operation
 *
 * This structure describes one initialization operation.
 */
typedef struct
{
    Qspi_Ip_OpType                       opType;       /*!< Operation type                                                                              */
    uint16                               command1Lut;  /*!< Index of first command sequence in Lut; for RMW type this is the read command               */
    uint16                               command2Lut;  /*!< Index of second command sequence in Lut, only used for RMW type, this is the write command  */
    uint16                               weLut;        /*!< Index of write enable sequence in Lut, only used for Write and RMW type                     */
    uint32                               addr;         /*!< Address, if used in command.                                                                */
    uint8                                size;         /*!< Size in bytes of configuration register                                                     */
    uint8                                shift;        /*!< Position of configuration field inside the register                                         */
    uint8                                width;        /*!< Width in bits of configuration field.                                                       */
    uint32                               value;        /*!< Value to set in the field                                                                   */
    const Qspi_Ip_ControllerConfigType  *ctrlCfgPtr;   /*!< New controller configuration, valid only for QSPI_IP_OP_TYPE_QSPI_CFG type                  */
} Qspi_Ip_InitOperationType;


/*!
 * @brief Initialization sequence
 *
 * Describe sequence that will be performed only once during initialization to put the flash in the desired state for operation.
 * This may include, for example, setting the QE bit, activating 4-byte addressing, activating XPI mode
 */
typedef struct
{
    uint8 opCount;                                     /*!< Number of operations  */
    Qspi_Ip_InitOperationType * operations;            /*!< List of operations    */
} Qspi_Ip_InitConfigType;


/*!
* @brief Parameter memory type
*/
typedef enum
{
    QSPI_IP_HYPER_FLASH     = 1U,           /*!< HyperFlash devices          */
    QSPI_IP_SERIAL_FLASH    = 0U            /*!< Traditional xSPI devices    */
} Qspi_Ip_FlashMemoryType;


/*!
 * @brief Driver configuration structure
 *
 * This structure is used to provide configuration parameters for the external flash driver
 * at initialization time.
 */
typedef struct
{
    Qspi_Ip_FlashMemoryType memType;                      /*!< Mmemory device type                              */
    const Qspi_Ip_HyperFlashConfigType * hfConfig;        /*!< Hyperflash configuration, NULL if not used       */
    uint32 memSize;                                       /*!< Memory size (in bytes)                           */
    uint32 pageSize;                                      /*!< Page size (in bytes)                             */
    uint16 readLut;                                       /*!< Command used to read data from flash             */
    uint16 writeLut;                                      /*!< Command used to write data to flash              */
    uint16 read0xxLut;                                    /*!< 0-x-x mode read command                          */
    uint16 read0xxLutAHB;                                 /*!< 0-x-x mode AHB read command                      */
    Qspi_Ip_ReadIdConfigType readIdSettings;              /*!< Erase settings of the external flash             */
    Qspi_Ip_EraseConfigType eraseSettings;                /*!< Erase settings of the external flash             */
    Qspi_Ip_StatusConfigType statusConfig;                /*!< Status register information                      */
    Qspi_Ip_SuspendConfigType suspendSettings;            /*!< Program / Erase Suspend settings                 */
    Qspi_Ip_ResetConfigType resetSettings;                /*!< Soft Reset settings, used at runtime             */
    Qspi_Ip_ResetConfigType initResetSettings;            /*!< Soft Reset settings, used for first time reset   */
    Qspi_Ip_InitConfigType initConfiguration;             /*!< Operations for initial flash configuration       */
    Qspi_Ip_LutConfigType lutSequences;                   /*!< List of LUT sequences describing flash commands  */
    Qspi_Ip_InitCalloutPtrType initCallout;               /*!< Pointer to init callout                          */
    Qspi_Ip_ResetCalloutPtrType resetCallout;             /*!< Pointer to reset callout                         */
    Qspi_Ip_ErrorCheckCalloutPtrType errorCheckCallout;   /*!< Pointer to error check callout                   */
    Qspi_Ip_EccCheckCalloutPtrType eccCheckCallout;       /*!< Pointer to ecc check callout                     */
    const Qspi_Ip_ControllerConfigType * ctrlAutoCfgPtr;  /*!< Initial controller configuration, if needed      */
#if (QSPI_IP_CHECK_CFG_CRC == STD_ON)
    Qspi_Ip_CrcType memCfgCRC;                            /*!< Memory device configuration CRC                  */
#endif
} Qspi_Ip_MemoryConfigType;


/*!
 * @brief Flash-controller conections configuration structure
 *
 * This structure specifies thte connecctions of each flash device to QSPI controllers
 * at initialization time.
 */
typedef struct
{
    uint32 qspiInstance;                /*!< QSPI Instance where this device is connected     */
    Qspi_Ip_ConnectionType connectionType;            /*!< Device connection to QSPI module                 */
    uint8  memAlignment;                              /*!< Memory alignment required by the external flash  */
#if (QSPI_IP_CHECK_CFG_CRC == STD_ON)
    Qspi_Ip_CrcType memCntCfgCRC;                    /*!< Flash-controller conections configuration CRC    */
#endif
} Qspi_Ip_MemoryConnectionType;


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* QSPI_IP_TYPES_H */

