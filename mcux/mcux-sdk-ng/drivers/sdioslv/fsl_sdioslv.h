/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_SDIOSLV_H_
#define FSL_SDIOSLV_H_

#include "fsl_common.h"

/*!
 * @addtogroup sdioslv_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief Driver version 2.0.0. */
#define FSL_SDIOSLV_DRIVER_VERSION (MAKE_VERSION(2U, 0U, 0U))
/*! @} */

#ifndef SDIOSLV_TRANSMIT_QUEUE_SIZE
/*! @brief SDIOSLV transfer queue size, user can refine it according to use case. */
#define SDIOSLV_TRANSMIT_QUEUE_SIZE (4)
#endif
/*! @brief TPL code definition */
#define SDIOSLV_TPL_CODE_CISTPL_NULL     0x00  /*!< Null tuple */
#define SDIOSLV_TPL_CODE_CISTPL_CHECKSUM 0x10  /*!< Checksum control */
#define SDIOSLV_TPL_CODE_CISTPL_VERS_1   0x15, /*!< The alternate language string tuple */
#define SDIOSLV_TPL_CODE_CISTPL_ALTSTR   0x16  /*!< Manufacturer identification string tuple */
#define SDIOSLV_TPL_CODE_CISTPL_MANFID   0x20  /*!< Function identification tuple */
#define SDIOSLV_TPL_CODE_CISTPL_FUNCID   0x21  /*!< Function extensions */
#define SDIOSLV_TPL_CODE_CISTPL_FUNCE    0x22  /*!< Function extensions */
#define SDIOSLV_TPL_CODE_CISTPL_SDIOSLV_STD                                     \
    0x91 /*!< Additional information for functions built to support application \
specifications for standard SDIO functions */
#define SDIOSLV_TPL_CODE_CISTPL_SDIOSLV_EXT 0x92 /*!< Reserved for future use with SDIO devices */
#define SDIOSLV_TPL_CODE_CISTPL_END         0xFF /*!< The end-of-chain tuple */

/*! @brief SDIO slave CCCR format
 * @param CCCR version
 * @param SDIO version
 * @param SD revision
 * @param support continuous SPI interrupt
 * @param  support direct command 52
 * @param  support block mode command 53
 * @param support read wait control operation
 * @param support suspend resume operation
 * @param support generate interrupt during a 4-bit multi block transfer
 * @param  low speed device
 * @param low speed card and 4-bit data transfer
 * @param support master power control
 * @param support high speed
 */
#define SDIOSLV_SLAVE_CCCR_CAPABILTIY(cccrVersion, sdioVersion, sdRevision, scsi, sdc, smb, srw, sbs, s4mi, lsc,  \
                                      s4bls, smpc, shs)                                                           \
    (uint32_t)((cccrVersion & 0xFU) | ((sdioVersion & 0xFU) << 4U) | ((sdRevision & 0xFU) << 8U) |                \
               ((scsi & 0x1U) << 12U) | ((sdc & 0x1U) << 13U) | ((smb & 0x1U) << 14U) | ((srw & 0x1U) << 15U) |   \
               ((sbs & 0x1U) << 16U) | ((s4mi & 0x1U) << 17U) | ((lsc & 0x1U) << 18U) | ((s4bls & 0x1U) << 19U) | \
               ((smpc & 0x1U) << 20U) | ((shs & 0x1U) << 21U))

/*! @brief SDIO slave io access mode
 * @param support SDR50 mode
 * @param support SDR104 mode
 * @param support DDR50 mode
 * @param support Driver strength type A
 * @param support driver strength type C
 * @param support driver strength type D
 * @param support async interrupt
 */
#define SDIOSLV_SLAVE_IO_ACCESS_CAPABILITY(supportSDR50, supportSDR104, supportDDR50, supportDTA, supportDTC, \
                                           supportDTD, supportAI)                                             \
    (uint32_t)((supportSDR50 & 0x1U) | ((supportSDR104 & 0x1U) << 1U) | ((supportDDR50 & 0x1U) << 2U) |       \
               ((supportDTA & 0x1U) << 3U) | ((supportDTC & 0x1U) << 4U) | ((supportDTD & 0x1U) << 5U) |      \
               ((supportAI & 0x1U) << 6U))
/*! @brief SDIO slave FBR configurations
 * @param io device code1
 * @param support CSA
 * @param extend device code
 * @param support high power
 */
#define SDIOSLV_SLAVE_FBR(iodeviceCode1, supportCSA, extendedDevCode, supportHighPower)                   \
    (uint32_t)((iodeviceCode1 & 0xFU) | ((supportCSA & 0x1U) << 4U) | ((extendedDevCode & 0xFFU) << 5U) | \
               ((supportHighPower & 0x1U) << 13U))

/*! @brief SDIO status */
enum _sdioslv_status
{
    kStatus_SDIOSLV_CardIsNotReady =
        MAKE_STATUS(kStatusGroup_SDIOSLV, 0U), /*!< Card is not ready to perform initialization. */
    kStatus_SDIOSLV_DMADataBufferAddrNotAlign =
        MAKE_STATUS(kStatusGroup_SDIOSLV, 1U), /*!< data buffer addr not align in DMA mode. */
    kStatus_SDIOSLV_Busy               = MAKE_STATUS(kStatusGroup_SDIOSLV, 2U),  /*!< SDIO slave is busy. */
    kStatus_SDIOSLV_Idle               = MAKE_STATUS(kStatusGroup_SDIOSLV, 3U),  /*!< SDIO slave is idle. */
    kStatus_SDIOSLV_QueueFull          = MAKE_STATUS(kStatusGroup_SDIOSLV, 4U),  /*!< SDIO slave transmit queue full. */
    kStatus_SDIOSLV_FuncEnabled        = MAKE_STATUS(kStatusGroup_SDIOSLV, 5U),  /*!< function enabled */
    kStatus_SDIOSLV_FuncDisabled       = MAKE_STATUS(kStatusGroup_SDIOSLV, 6U),  /*!< function disabled */
    kStatus_SDIOSLV_FuncSuspended      = MAKE_STATUS(kStatusGroup_SDIOSLV, 7U),  /*!< function suspended */
    kStatus_SDIOSLV_FuncResumed        = MAKE_STATUS(kStatusGroup_SDIOSLV, 8U),  /*!< function resumed */
    kStatus_SDIOSLV_FuncWriteComplete  = MAKE_STATUS(kStatusGroup_SDIOSLV, 9U),  /*!< function write complete */
    kStatus_SDIOSLV_FuncReadComplete   = MAKE_STATUS(kStatusGroup_SDIOSLV, 10U), /*!< function read complete */
    kStatus_SDIOSLV_FuncReceivedMSG    = MAKE_STATUS(kStatusGroup_SDIOSLV, 11U), /*!< function received message */
    kStatus_SDIOSLV_FuncTransmittedMSG = MAKE_STATUS(kStatusGroup_SDIOSLV, 12U), /*!< function trnasmitted message */
    kStatus_SDIOSLV_FuncWriteRequest   = MAKE_STATUS(kStatusGroup_SDIOSLV, 12U), /*!< function receive write request */
};

/*! @brief SDIO Card CCCR version number */
typedef enum _sdioslv_cccr_version
{
    kSDIOSLV_CCCRVersion1_00 = 0, /* CCCR/FBR Version 1.00 */
    kSDIOSLV_CCCRVersion1_10 = 1, /* CCCR/FBR Version 1.10 */
    kSDIOSLV_CCCRVersion2_00 = 2, /* CCCR/FBR Version 2.00 */
    kSDIOSLV_CCCRVersion3_00 = 3, /* CCCR/FBR Version 3.00 */
} sdioslv_cccr_version_t;

/*! @brief SDIO Card SDIO version number */
typedef enum _sdioslv_sdioslv_version
{
    kSDIOSLV_SDIOVersion1_00 = 0, /* SDIO Specification Version 1.00 */
    kSDIOSLV_SDIOVersion1_10 = 1, /* SDIO Specification Version 1.10 */
    kSDIOSLV_SDIOVersion1_20 = 2, /* SDIO Specification Version 1.20 */
    kSDIOSLV_SDIOVersion2_00 = 3, /* SDIO Specification Version 2.00 */
    kSDIOSLV_SDIOVersion3_00 = 4, /* SDIO Specification Version 3.00 */
} sdioslv_sdioslv_version_t;

/*! @brief SDIO Card SD Physical specification */
typedef enum _sdioslv_sd_version
{
    kSDIOSLV_SDVersion1_01 = 0, /* SD Physical Specification 1.01 */
    kSDIOSLV_SDVersion1_10 = 1, /* SD Physical Specification 1.10 */
    kSDIOSLV_SDVersion2_00 = 2, /* SD Physical Specification 2.00 */
    kSDIOSLV_SDVersion3_00 = 3, /* SD Physical Specification 3.00 */
} sdioslv_sd_version_t;

/*! @brief The SDIO Standard Function code */
typedef enum _sdioslv_standard_function_code
{
    kSDIOSLV_NullDevice          = 0x0U, /* No SDIO standard interface supported by this function */
    kSDIOSLV_StandardUART        = 0x1U, /* SDIO Standard UART */
    kSDIOSLV_BluetoothTypeA      = 0x2U, /* SDIO Bluetooth Type-A standard interface */
    kSDIOSLV_BluetoothTypeB      = 0x3U, /* SDIO Bluetooth Type-B standard interface */
    kSDIOSLV_GPS                 = 0x4U, /* SDIO GPS standard interface */
    kSDIOSLV_Camera              = 0x5U, /* SDIO Camera standard interface */
    kSDIOSLV_PHS                 = 0x6U, /* SDIO PHS standard interface */
    kSDIOSLV_WLAN                = 0x7U, /* SDIO WLAN interface */
    kSDIOSLV_EmbeddedSDIOSLV_ATA = 0x8U, /* Embedded SDIO-ATA standard interface */
    kSDIOSLV_BluetoothTypeA_AMP  = 0x9U, /* SDIO Bluetooth Type-A AMP standard interface */
    kSDIOSLV_ExtendedCode        = 0xFU, /* SDIO extension IO function code */
} sdioslv_standard_function_code_t;

/*! @brief SDIO card function number */
typedef enum _sdioslv_func_num
{
    kSDIOSLV_FunctionNum0 = 0, /*!< sdio function0 */
    kSDIOSLV_FunctionNum1 = 1, /*!< sdio function1 */
    kSDIOSLV_FunctionNum2 = 2, /*!< sdio function2 */
    kSDIOSLV_FunctionNum3 = 3, /*!< sdio function3 */
    kSDIOSLV_FunctionNum4 = 4, /*!< sdio function4 */
    kSDIOSLV_FunctionNum5 = 5, /*!< sdio function5 */
    kSDIOSLV_FunctionNum6 = 6, /*!< sdio function6 */
    kSDIOSLV_FunctionNum7 = 7, /*!< sdio function7 */
} sdioslv_func_t;

/*! @brief Global interrupt flag */
enum _sdioslv_global_interrupt_flag
{
    kSDIOSLV_Func0InterruptFlag = SDIOSLV_GLB_INT_EN_REG_FN0_INT_TO_ARM_EN_MASK, /* Function0 interrupt flag */
    kSDIOSLV_Func1InterruptFlag = SDIOSLV_GLB_INT_EN_REG_FN1_INT_TO_ARM_EN_MASK, /* Function1 interrupt flag */

    kSDIOSLV_GlobalAllInterruptFlag = (kSDIOSLV_Func0InterruptFlag | kSDIOSLV_Func1InterruptFlag),
};

/*! @brief Function0 interrupt status flag mask */
enum _sdioslv_function0_interrupt_status_flag
{
    kSDIOSLV_AHBSoftResetFlag     = SDIOSLV_FNO_INT_EN_AHBSOFT_RST_EN_MASK,     /*!< Soft reset interrupt flag */
    kSDIOSLV_VoltageSwitchCmdFlag = SDIOSLV_FNO_INT_EN_VOLT_SWITCH_CMD_EN_MASK, /*!< Voltage switch interrupt flag */
    kSDIOSLV_Cmd19ReadStartFlag   = SDIOSLV_FNO_INT_EN_CMD19_RD_STRT_EN_MASK,   /*!< CMD19 start flag */
    kSDIOSLV_Cmd19ReadTransferOverFlag = SDIOSLV_FNO_INT_EN_CMD19_RD_TRN_OVR_EN_MASK, /*!< CMD19 transfer over flag */
    kSDIOSLV_Func0WriteStartFlag = SDIOSLV_FNO_INT_EN_FN0_WR_STRT_EN_MASK, /*!< CMD53 Function0 write start flag */
    kSDIOSLV_Func0WriteTransferOverFlag =
        SDIOSLV_FNO_INT_EN_FN0_WR_TRN_OVR_EN_MASK,                        /*!< CMD53 Function0 write trans over flag */
    kSDIOSLV_Func0ReadStartFlag = SDIOSLV_FNO_INT_EN_FN0_RD_STRT_EN_MASK, /*!< CMD53 Function0 read start flag */
    kSDIOSLV_Func0ReadTransferOverFlag =
        SDIOSLV_FNO_INT_EN_FN0_RD_OVR_EN_MASK,                              /*!< CMD53 Function0 read trans over flag */
    kSDIOSLV_Func0ReadErrorFlag = SDIOSLV_FNO_INT_EN_FN0_RD_ERR_EN_MASK,    /*!< SD Host issue abort command during
                                                                       function 0 read transaction */
    kSDIOSLV_Func0AdmaEndBitFlag = SDIOSLV_FNO_INT_EN_FN0_ADMA_END_EN_MASK, /*!< Adma endbit is set during
                                                                     descriptor fetch indicate end of fetch */
    kSDIOSLV_Func0AdmaInterruptFlag = SDIOSLV_FNO_INT_EN_FN0_ADMA_INT_EN_MASK, /*!< Int bit is set in the ADMA attribute
                                                                         field during fetch operation */
    kSDIOSLV_Func0AdmaErrorFlag = SDIOSLV_FNO_INT_EN_FN0_ADMA_ERR_EN_MASK,     /*!< Adma error, set when ARM sets valid
                                                                         bit as 1'b0 in the attribute field during
                                                                         fetch operation */
    kSDIOSLV_Func0DataTransferInterruptFlag =
        (kSDIOSLV_Func0WriteStartFlag | kSDIOSLV_Func0WriteTransferOverFlag | kSDIOSLV_Func0ReadStartFlag |
         kSDIOSLV_Func0ReadTransferOverFlag | kSDIOSLV_Func0ReadErrorFlag | kSDIOSLV_Func0AdmaEndBitFlag),
    kSDIOSLV_Func0AllInterruptFlag =
        (kSDIOSLV_AHBSoftResetFlag | kSDIOSLV_VoltageSwitchCmdFlag | kSDIOSLV_Cmd19ReadStartFlag |
         kSDIOSLV_Cmd19ReadTransferOverFlag | kSDIOSLV_Func0WriteStartFlag | kSDIOSLV_Func0WriteTransferOverFlag |
         kSDIOSLV_Func0ReadStartFlag | kSDIOSLV_Func0ReadTransferOverFlag | kSDIOSLV_Func0ReadErrorFlag |
         kSDIOSLV_Func0AdmaEndBitFlag | kSDIOSLV_Func0AdmaInterruptFlag | kSDIOSLV_Func0AdmaErrorFlag),
};

/*! @brief Function1 interrupt status flag mask */
enum _sdioslv_function1_interrupt_status_flag
{
    kSDIOSLV_Func1WriteTransferOverFlag =
        SDIOSLV_FN1_INT_STS_FN1_WR_OVER_MASK, /*!< CMD53 Function1 Write transfer over flag */
    kSDIOSLV_Func1ReadTransferOverFlag = SDIOSLV_FN1_INT_STS_FN1_RD_OVER_MASK, /*!< CMD53 Function1 read transfer
                                                                                 over flag */
    kSDIOSLV_Func1ReadErroFlag = SDIOSLV_FN1_INT_STS_FN1_RD_ERROR_MASK,        /*!< SD Host issue abort command during
                                                                                  function 0 read transaction */
    kSDIOSLV_Func1DisableFlag     = SDIOSLV_FN1_INT_STS_FUN1_RST_MASK, /*!< Host disable IOEx bit in CCCR flag */
    kSDIOSLV_Func1HostMessageFlag = SDIOSLV_FN1_INT_STS_SD_HOST_FN1_MSG_RDY_MASK, /*!< Host program the SD Host General
                                                                              Purpose Register flag */
    kSDIOSLV_Func1AckToArmFlag = SDIOSLV_FN1_INT_STS_FN1_ACK_TO_ARM_MASK,         /*!< SD Host has read the ARM General
                                                                                   Purpose Register Flag */
    kSDIOSLV_Func1ReadStartFlag  = SDIOSLV_FN1_INT_STS_FN1_SDIO_RD_START_MASK, /*!< CMD53 Function1 read start flag */
    kSDIOSLV_Func1WriteStartFlag = SDIOSLV_FN1_INT_STS_FN1_SDIO_WR_START_MASK, /*!< CMD53 Function1 Write start flag */
    kSDIOSLV_Func1AdmaEndBitFlag = SDIOSLV_FN1_INT_STS_ADMA_END_INT_MASK,      /*!< Adma endbit is set during descriptor
                                                                                   fetch indicate end of fetch */
    kSDIOSLV_Func1SuspendFlag       = SDIOSLV_FN1_INT_STS_FN1_SUSPEND_MASK,    /*!< Function1 suspend flag */
    kSDIOSLV_Func1ResumeFlag        = SDIOSLV_FN1_INT_STS_RESUME_MASK,         /*!< Function1 resume flag */
    kSDIOSLV_Func1AdmaInterruptFlag = SDIOSLV_FN1_INT_STS_ADMA_INT_MASK,       /*!< Int bit is set in the ADMA attribute
                                                                                        field during fetch operation */
    kSDIOSLV_Func1AdmaErrorFlag = SDIOSLV_FN1_INT_STS_ADMA_ERR_MASK,           /*!< Adma error, set when ARM sets valid
                                                                                        bit as 1'b0 in the attribute field during
                                                                                        fetch operation */
    kSDIOSLV_Func1EnableFlag = SDIOSLV_FN1_INT_STS_FUN1_EN_MASK,               /*!< Host enable IOEx bit in CCCR flag */

    kSDIOSLV_Func1DataTransferInterruptFlag =
        (kSDIOSLV_Func1WriteStartFlag | kSDIOSLV_Func1WriteTransferOverFlag | kSDIOSLV_Func1ReadStartFlag |
         kSDIOSLV_Func1ReadTransferOverFlag | kSDIOSLV_Func1ReadErroFlag | kSDIOSLV_Func1AdmaEndBitFlag),
    kSDIOSLV_Func1AllInterruptFlag =
        (kSDIOSLV_Func1WriteTransferOverFlag | kSDIOSLV_Func1ReadTransferOverFlag | kSDIOSLV_Func1ReadErroFlag |
         kSDIOSLV_Func1DisableFlag | kSDIOSLV_Func1HostMessageFlag | kSDIOSLV_Func1AckToArmFlag |
         kSDIOSLV_Func1ReadStartFlag | kSDIOSLV_Func1WriteStartFlag | kSDIOSLV_Func1AdmaEndBitFlag |
         kSDIOSLV_Func1SuspendFlag | kSDIOSLV_Func1ResumeFlag | kSDIOSLV_Func1AdmaInterruptFlag |
         kSDIOSLV_Func1AdmaErrorFlag | kSDIOSLV_Func1EnableFlag),
};

/* ADMA descriptor table
 * |----------------|---------------|-------------|--------------------------|
 * | Address field  |     Length    | Reserved    |         Attribute        |
 * |----------------|---------------|-------------|--------------------------|
 * |63            32|31           16|15         06|05  |04  |03|02 |01 |00   |
 * |----------------|---------------|-------------|----|----|--|---|---|-----|
 * | 32-bit address | 16-bit length | 0000000000  |Act2|Act1| 0|Int|End|Valid|
 * |----------------|---------------|-------------|----|----|--|---|---|-----|
 *
 *
 * | Act2 | Act1 |     Comment     | Operation                                                         |
 * |------|------|-----------------|-------------------------------------------------------------------|
 * |   0  |   0  | No op           | Don't care                                                        |
 * |------|------|-----------------|-------------------------------------------------------------------|
 * |   0  |   1  | Reserved        | Read this line and go to next one                                 |
 * |------|------|-----------------|-------------------------------------------------------------------|
 * |   1  |   0  | Transfer data   | Transfer data with address and length set in this descriptor line |
 * |------|------|-----------------|-------------------------------------------------------------------|
 * |   1  |   1  | Link descriptor | Link to another descriptor                                        |
 * |------|------|-----------------|-------------------------------------------------------------------|
 */
/*! @brief The alignment size for ADDRESS field in ADMA's descriptor */
#define SDIOSLV_ADMA_ADDRESS_ALIGN (8U)
/*! @brief The alignment size for LENGTH filed in ADMA's descriptor */
#define SDIOSLV_ADMA_LENGTH_ALIGN (8U)
/*! @brief The adma descriptor length in words */
#define SDIOSLV_ADMA_LENGTH_IN_WORDS (2U)
/*! @brief The bit shift for LENGTH field in ADMA's descriptor */
#define SDIOSLV_ADMA_DESCRIPTOR_LENGTH_SHIFT (16U)
/*! @brief The bit mask for LENGTH field in ADMA's descriptor */
#define SDIOSLV_ADMA_DESCRIPTOR_LENGTH_MASK (0xFFFFU)
/*! @brief The maximum value of LENGTH field in ADMA's descriptor */
#define SDIOSLV_ADMA_DESCRIPTOR_MAX_LENGTH_PER_ENTRY (SDIOSLV_ADMA_DESCRIPTOR_LENGTH_MASK + 1)

/*! @brief ADMA1 descriptor control and status mask */
enum _sdioslv_adma_descriptor_flag
{
    kSDIOSLV_AdmaDescriptorValidFlag     = (1U << 0U), /*!< Valid flag */
    kSDIOSLV_AdmaDescriptorEndFlag       = (1U << 1U), /*!< End flag */
    kSDIOSLV_AdmaDescriptorInterruptFlag = (1U << 2U), /*!< Interrupt flag */
    kSDIOSLV_AdmaDescriptorActivity1Flag = (1U << 4U), /*!< Activity 1 mask */
    kSDIOSLV_AdmaDescriptorActivity2Flag = (1U << 5U), /*!< Activity 2 mask */

    kSDIOSLV_AdmaDescriptorTypeNop = (kSDIOSLV_AdmaDescriptorValidFlag), /*!< No operation */
    kSDIOSLV_AdmaDescriptorTypeReserved =
        (kSDIOSLV_AdmaDescriptorActivity1Flag | kSDIOSLV_AdmaDescriptorValidFlag), /*!< Reserved */
    kSDIOSLV_AdmaDescriptorTypeTransfer =
        (kSDIOSLV_AdmaDescriptorActivity2Flag | kSDIOSLV_AdmaDescriptorValidFlag), /*!< Transfer type */
    kSDIOSLV_AdmaDescriptorTypeLink = (kSDIOSLV_AdmaDescriptorActivity1Flag | kSDIOSLV_AdmaDescriptorActivity2Flag |
                                       kSDIOSLV_AdmaDescriptorValidFlag), /*!< Link type */
};

/*! @brief allocate adma descriptor.
 * To simplify user interface, this macro will help allocate descriptor memory,
 * user just need to provide the name and the number for the allocate descriptor.
 *
 * @param name, allocate decriptor name.
 * @param number, number of descriptor to be allocated.
 */
#define SDIOSLV_ALLOCATE_ADMA_DESCRIPTOR(name, number) \
    AT_NONCACHEABLE_SECTION_ALIGN(uint32_t name[number * 2], SDIOSLV_ADMA_ADDRESS_ALIGN)

/*! @brief DDR mode delay value */
typedef enum _sdioslv_ddr_delay
{
    kSDIOSLV_DDRDelay1500ps = 0U, /*!< DDR mode delay 1.5ns */
    kSDIOSLV_DDRDelay3000ps = 1U, /*!< DDR mode delay 3ns */
} sdioslv_ddr_delay_t;

/*! @brief OCR register voltage window */
enum _sdioslv_ocr_voltage
{
    kSDIOSLV_OcrVdd2V0_2V1 = 1U << 8U,  /*!< VDD 2.0-2.1 */
    kSDIOSLV_OcrVdd2V1_2V2 = 1U << 9U,  /*!< VDD 2.1-2.2 */
    kSDIOSLV_OcrVdd2V2_2V3 = 1U << 10U, /*!< VDD 2.2-2.3 */
    kSDIOSLV_OcrVdd2V3_2V4 = 1U << 11U, /*!< VDD 2.3-2.4 */
    kSDIOSLV_OcrVdd2V4_2V5 = 1U << 12U, /*!< VDD 2.4-2.5 */
    kSDIOSLV_OcrVdd2V5_2V6 = 1U << 13U, /*!< VDD 2.5-2.6 */
    kSDIOSLV_OcrVdd2V6_2V7 = 1U << 14U, /*!< VDD 2.6-2.7 */
    kSDIOSLV_OcrVdd2V7_2V8 = 1U << 15U, /*!< VDD 2.7-2.8 */
    kSDIOSLV_OcrVdd2V8_2V9 = 1U << 16U, /*!< VDD 2.8-2.9 */
    kSDIOSLV_OcrVdd2V9_3V0 = 1U << 17U, /*!< VDD 2.9-3.0 */
    kSDIOSLV_OcrVdd3V0_3V1 = 1U << 18U, /*!< VDD 2.9-3.0 */
    kSDIOSLV_OcrVdd3V1_3V2 = 1U << 19U, /*!< VDD 3.0-3.1 */
    kSDIOSLV_OcrVdd3V2_3V3 = 1U << 20U, /*!< VDD 3.1-3.2 */
    kSDIOSLV_OcrVdd3V3_3V4 = 1U << 21U, /*!< VDD 3.2-3.3 */
    kSDIOSLV_OcrVdd3V4_3V5 = 1U << 22U, /*!< VDD 3.3-3.4 */
    kSDIOSLV_OcrVdd3V5_3V6 = 1U << 23U, /*!< VDD 3.4-3.5 */
};

/*! @brief Defines the ADMA descriptor structure. */
typedef struct _sdioslv_adma_descriptor
{
    uint32_t attribute;     /*!< The control and status field */
    const uint8_t *address; /*!< The address field */
} sdioslv_adma_descriptor_t;

/*! @brief Data structure for SDIO card information structure. */
typedef struct _sdioslv_cis_config
{
    const uint8_t *base;
    uint32_t length;
} sdioslv_cis_config_t;

/*! @brief Data structure to initialize the SDIO */
typedef struct _sdioslv_config
{
    uint32_t commonCapability; /*!< CCCR Register. */
    uint32_t iocapability;     /*!< IO_ACC_MODE Register. */
    bool supportUHS;           /*!< UHS_SUPPORT Register. */
    sdioslv_ddr_delay_t ddrDelay;
    uint32_t voltageSwitchDelayCount; /*!< Wait time for the Controller before releasing cmd, data line for cmd11
                                         voltage switch. */
    uint32_t ocr;                     /*!< IO Operating voltage range. */
    uint32_t fbrRegConfig;            /*!< FBR register configurations */
    sdioslv_cis_config_t cisRegConfig[FSL_FEATURE_SOC_SDIOSLV_FUNCTION_COUNT]; /*!< CIS Register. */
} sdioslv_config_t;

/*! @brief sdio slave send transfer configuration */
typedef struct _sdioslv_transfer
{
    const uint8_t *dataAddr; /*!< send data address, word align data address */
    uint32_t dataSize;       /*!< send data size, word align data size */
} sdioslv_transfer_t;

/*! @brief SDIO transfer callback structure. */
typedef void (*sdioslv_transfer_callback_t)(
    SDIOSLV_Type *base, sdioslv_func_t func, status_t status, void *dataAddr, uint32_t dataSize, void *userData);

/*! @brief SDIO slave handle structure. */
typedef struct _sdioslv_handle
{
    uint32_t state;
    uint32_t transferredFunc0Size;

    sdioslv_transfer_t txQueue[SDIOSLV_TRANSMIT_QUEUE_SIZE]; /*!< ADMA descriptor queue for send transfer */
    uint32_t txSize[SDIOSLV_TRANSMIT_QUEUE_SIZE];
    volatile uint8_t txQueueUser;   /*!< Index for user to queue transfer */
    volatile uint8_t txQueueDriver; /*!< Index for driver to get the transfer data and size */

    uint32_t *descriptorBuffer; /*!< ADMA descriptor queue for send transfer */
    uint32_t descriptorLen;     /*!< receive descriptor memeory length in words */

    uint8_t *rxPingpongBuffer;              /*!< ring buffer address */
    uint32_t rxPingpongBufferSize;          /*!< ring buffer size */
    volatile uint8_t *rxPingpongBufferHead; /*!< ping pong buffer head */

    /* Callback functions */
    sdioslv_transfer_callback_t callback; /*!< Callback function. */
    void *userData;                       /*!< Parameter passed to the callback. */
} sdioslv_handle_t;

/*************************************************************************************************
 * API
 ************************************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */
/*!
 * @brief Sets the SDIO configuration structure to SDIO V2.0 default values.
 *
 * @note calling this function will involve the default cis table in the sdio slave driver, it may increase
 * the ram cost.
 * @param config A pointer to the user configuration structure.
 */
void SDIOSLV_GetSDIOV2Config(sdioslv_config_t *config);

/*!
 * @brief Sets the SDIO configuration structure to SDIOV3.0 default values.
 *
 * @note calling this function will involve the default cis table in the sdio slave driver, it may increase
 * the ram cost.
 * @param config A pointer to the user configuration structure.
 */
void SDIOSLV_GetSDIOV3Config(sdioslv_config_t *config);

/*!
 * @brief SDIO module initialization function.
 *
 * @param base SDIO peripheral base address.
 * @param config sdio slave configurations.
 */
void SDIOSLV_Init(SDIOSLV_Type *base, const sdioslv_config_t *config);

/*!
 * @brief SDIO module deinitialization function.
 *
 * @param base SDIO peripheral base address.
 */

void SDIOSLV_Deinit(SDIOSLV_Type *base);

/*!
 * @brief Set the SDIO function ready bit in CCCR.IOR[x].
 *
 * @param base SDIO peripheral base address.
 * @param func The specific function number.
 */
void SDIOSLV_SetIOReady(SDIOSLV_Type *base, sdioslv_func_t func);

/*!
 * @brief Clear the SDIO function ready bit in CCCR.IOR[x].
 *
 * @param base SDIO peripheral base address.
 * @param func The specific function number.
 */
void SDIOSLV_ClearIOReady(SDIOSLV_Type *base, sdioslv_func_t func);

/*!
 * @brief Set SDIO card ready status.
 *
 * @param base SDIO peripheral base address.
 */
static inline void SDIOSLV_SetFunctionReady(SDIOSLV_Type *base)
{
    base->SIG_FUN_RDY |= SDIOSLV_SIG_FUN_RDY_FUNRDY_REGISTER_MASK;
}

/*!
 * @brief Clear SDIO card ready status.
 *
 * @param base SDIO peripheral base address.
 */
static inline void SDIOSLV_ClearFunctionReady(SDIOSLV_Type *base)
{
    base->SIG_FUN_RDY &= ~SDIOSLV_SIG_FUN_RDY_FUNRDY_REGISTER_MASK;
}

/*! @} */

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enable/Disable the interrupt status.
 *
 * @param base SDIO peripheral base address.
 * @param mask The globle interrupt status flags mask(_sdioslv_global_interrupt_flag).
 * @param enable true is enable, false is disable.
 */
static inline void SDIOSLV_EnableGlobalInterrupts(SDIOSLV_Type *base, uint32_t mask, bool enable)
{
    if (enable)
    {
        base->GLB_INT_EN_REG |= mask;
    }
    else
    {
        base->GLB_INT_EN_REG &= ~mask;
    }
}

/*!
 * @brief Enables the interrupt signal corresponding to the interrupt status flag.
 *
 * @param base SDIO peripheral base address.
 * @param func The specific function number.
 * @param mask The function interrupt status flags mask(_sdioslv_function0_interrupt_status_flag or
 * _sdioslv_function1_interrupt_status_flag).
 */
void SDIOSLV_EnableFuncInterrupt(SDIOSLV_Type *base, sdioslv_func_t func, uint32_t mask);

/*!
 * @brief Disables the interrupt signal corresponding to the interrupt status flag.
 *
 * @param base SDIO peripheral base address.
 * @param func The specific function number.
 * @param mask The function interrupt status flags mask(_sdioslv_function0_interrupt_status_flag or
 * _sdioslv_function1_interrupt_status_flag).
 */
void SDIOSLV_DisableFuncInterrupt(SDIOSLV_Type *base, sdioslv_func_t func, uint32_t mask);

/*! @} */

/*!
 * @name Status
 * @{
 */
/*!
 * @brief Gets the card ready bit.
 *
 * @param base SDIO peripheral base address.
 * @return true for ready, false for not ready.
 */
static inline bool SDIOSLV_GetReadyStatus(SDIOSLV_Type *base)
{
    return (base->CARD_RDY & SDIOSLV_CARD_RDY_CARDRDY_REGISTER_MASK) ? true : false;
}

/*!
 * @brief Gets the current global interrupt status.
 *
 * @param base SDIO peripheral base address.
 * @return The current global interrupt status flags mask(_sdioslv_global_interrupt_flag).
 */
static inline uint32_t SDIOSLV_GetGlobalInterruptStatusFlags(SDIOSLV_Type *base)
{
    return (base->GLB_INT_STS_REG);
}

/*!
 * @brief Clear the current global interrupt status.
 *
 * @param base SDIO peripheral base address.
 * @param mask The global interrupt status flags mask(_sdioslv_global_interrupt_flag).
 */
static inline void SDIOSLV_ClearGlobalInterruptStatusFlags(SDIOSLV_Type *base, uint32_t mask)
{
    /* Write '1' to clear the interrupt status flag. */
    base->GLB_INT_STS_REG = mask;
}

/*!
 * @brief Gets the specific function interrupt status.
 *
 * @param base SDIO peripheral base address.
 * @param func The specific function number.
 * @return The function interrupt status flags mask(_sdioslv_function0_interrupt_status_flag or
 * _sdioslv_function1_interrupt_status_flag).
 */
uint32_t SDIOSLV_GetFuncInterruptStatusFlags(SDIOSLV_Type *base, sdioslv_func_t func);

/*!
 * @brief Clears a specified interrupt status of a specific function.
 *
 * @param base SDIO peripheral base address.
 * @param func the specific function number.
 * @param mask The function interrupt status flags mask(_sdioslv_function0_interrupt_status_flag or
 * _sdioslv_function1_interrupt_status_flag).
 */
void SDIOSLV_ClearFuncInterruptStatusFlags(SDIOSLV_Type *base, sdioslv_func_t func, uint32_t mask);

/*! @}*/

/*!
 * @name Bus operation
 * @{
 */

/*!
 * @brief Get a message word sent by SDIO host.
 *
 * @param base SDIO peripheral base address.
 * @return SDIO host message word.
 */
static inline uint32_t SDIOSLV_GetHostMessage(SDIOSLV_Type *base)
{
    return base->SD_HOST_MSG;
}

/*!
 * @brief Set a message word to SDIO host.
 *
 * @param base SDIO peripheral base address.
 * @param message SDIO slave message.
 */
static inline void SDIOSLV_SendSlaveMessage(SDIOSLV_Type *base, uint32_t message)
{
    base->ARM_MSG = message;
}

/*!
 * @brief Get SDIO transferred byte count of the writing operation.
 *
 * Only valid for current write operation, and always 0 for read operation.
 * Only valid when write over interrupt is triggered.
 *
 * @param base SDIO peripheral base address.
 * @return The transferred byte count.
 */
static inline uint32_t SDIOSLV_GetWriteTransferSize(SDIOSLV_Type *base)
{
    return base->XFER_CNT_REG & SDIOSLV_XFER_CNT_REG_XFER_CNT_REG_MASK;
}

/*!
 * @brief Get SDIO the block size of the current operation.
 *
 * For byte mode, block size equals byte count. For block mode, block size equals to block size in FBR.
 *
 * @param base SDIO peripheral base address.
 * @return The block size.
 */
static inline uint32_t SDIOSLV_GetBlockSize(SDIOSLV_Type *base)
{
    return base->SIN_MUL_BLK_SIZE & SDIOSLV_SIN_MUL_BLK_SIZE_BLK_SIZE_MASK;
}

/*!
 * @brief Get SDIO transferred block count of the writing operation.
 *
 * Always 1 at byte transaction.
 *
 * @param base SDIO peripheral base address.
 * @return The transferred block count.
 */
static inline uint32_t SDIOSLV_GetWriteBlockCount(SDIOSLV_Type *base)
{
    return base->WR_BLK_CNT;
}

/*!
 * @brief Get SDIO transferred block count of the reading operation.
 *
 * @param base SDIO peripheral base address.
 */
static inline uint32_t SDIOSLV_GetReadBlockCount(SDIOSLV_Type *base)
{
    return base->RD_BLK_CNT;
}

/*!
 * @brief Clear SDIO transferred block count of the writing operation.
 *
 * @param base SDIO peripheral base address.
 */
static inline void SDIOSLV_ClearWriteBlockCount(SDIOSLV_Type *base)
{
    base->WR_BLK_CNT = 0;
}

/*!
 * @brief Clear SDIO transferred block count of the reading operation.
 *
 * @param base SDIO peripheral base address.
 */
static inline void SDIOSLV_ClearReadBlockCount(SDIOSLV_Type *base)
{
    base->RD_BLK_CNT = 0;
}

/*!
 * @brief SDIO set data ready to inform SD host to fetch data.
 *
 * @param base SDIO peripheral base address.
 * @param dataBytes Transfer data count.
 */
void SDIOSLV_SetIO1ReadDataReady(SDIOSLV_Type *base, uint32_t dataBytes);

/*! @}*/

/*!
 * @name Transactional
 * @{
 */

/*!
 * @brief Creates the SDIO handle.
 *
 * @param base SDIO peripheral base address.
 * @param handle SDIO handle pointer.
 * @param callback Structure pointer to contain all callback functions.
 * @param userData Callback function parameter.
 */
void SDIOSLV_TransferCreateHandle(SDIOSLV_Type *base,
                                  sdioslv_handle_t *handle,
                                  sdioslv_transfer_callback_t callback,
                                  void *userData);

/*!
 * @brief SDIO Slave install ADMA descriptor memory.
 *
 * Note: A dummy descriptor is required for ADMA finished the ADMA pre-fetch operation, so application need to
 * provide desNum+1 descriptor memory.
 *
 * @param handle SDIO slave handler.
 * @param desAddr transmit descriptor address.
 * @param desNum transmit descriptor number.
 */
void SDIOSLV_InstallADMADescriptorMemory(sdioslv_handle_t *handle, void *desAddr, uint32_t desNum);

/*!
 * @brief SDIO Slave install ping pong buffer for host write transfer.
 *
 * Note: SDIOSLV driver assume the pingpong buffer size is pingpongBufferSize * 2U.
 *
 * @param handle SDIO slave handler.
 * @param pingpongBufferAddr ping pong buffer start address.
 * @param pingpongBufferSize  buffer size of the ping pong buffer, total buffer size should be 2 * pingpongBufferSize.
 */
void SDIOSLV_InstallPingpongBuffer(sdioslv_handle_t *handle, void *pingpongBufferAddr, uint32_t pingpongBufferSize);

/*!
 * @brief SDIOSLV send transfers.
 *
 * Call this API after calling the SDIOSLV_Init() and SDIOSLV_TransferCreateHandle() ,
 * SDIOSLV_InstallADMADescriptorMemory() to start processing transactions driven by an SD Host. The slave monitors the
 * SDIO bus. The callback is always invoked from the interrupt context.
 *
 * @param base SDIO peripheral base address.
 * @param handle Pointer to #sdioslv_handle_t structure which stores the transfer state.
 * @param transfer transfer configuration.
 * @retval #kStatus_SDIOSLV_QueueFull transmit buffer queue is full, application should check and wait until queue is
 * not full.
 * @retval #kStatus_SDIOSLV_DMADataBufferAddrNotAlign the transfer data address or data size is not word align.
 * @retval #kStatus_Success transfer configuration add into queue successfully.
 */
status_t SDIOSLV_TransferSendNonBlocking(SDIOSLV_Type *base, sdioslv_handle_t *handle, sdioslv_transfer_t *transfer);

/*!
 * @brief Starts accepting read transfers.
 *
 * This API should be called if pingpong buffer is not registered and kStatus_SDIOSLV_FuncWriteRequest callback is
 * received.
 *
 * @param base SDIO peripheral base address.
 * @param handle Pointer to #sdioslv_handle_t structure which stores the transfer state.
 * @param transfer transfer configuration.
 * @retval #kStatus_SDIOSLV_DMADataBufferAddrNotAlign the transfer data address or data size is not word align.
 * @retval #kStatus_Success transfer configuration add into queue successfully.
 */
status_t SDIOSLV_TransferReceiveNonBlocking(SDIOSLV_Type *base, sdioslv_handle_t *handle, sdioslv_transfer_t *transfer);

/*!
 * @brief IRQ handler for the SDIO.
 *
 * This function deals with the IRQs on the given host controller.
 *
 * @param base SDIO peripheral base address.
 * @param handle SDIO handle.
 */
void SDIOSLV_TransferHandleIRQ(SDIOSLV_Type *base, sdioslv_handle_t *handle);
/*! @}*/

#if defined(__cplusplus)
}
#endif
/*! @}*/

#endif /* FSL_SDIOSLV_H_ */
