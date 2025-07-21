/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_BISS_H_
#define FSL_BISS_H_

#include "fsl_common.h"

/*!
 * @addtogroup biss
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_BISS_DRIVER_VERSION (MAKE_VERSION(1, 0, 2)) /*!< Version 1.0.2 */
/*! @} */

/*! @name BiSS Command and IDA test setting of CTRLCOMM2 register */
/*! @{ */
#define BISS_CTRLCOMM2_CMD_MASK             (0x3000)
#define BISS_CTRLCOMM2_CMD_SHIFT            (12U)
#define BISS_CTRLCOMM2_CMD(x)               (((uint32_t)(((uint32_t)(x)) << BISS_CTRLCOMM2_CMD_SHIFT)) & BISS_CTRLCOMM2_CMD_MASK)

#define BISS_CTRLCOMM2_IDA_TEST_MASK        (0x800)
#define BISS_CTRLCOMM2_IDA_TEST_SHIFT       (11U)
#define BISS_CTRLCOMM2_IDA_TEST(x)          (((uint32_t)(((uint32_t)(x)) << BISS_CTRLCOMM2_IDA_TEST_SHIFT)) & BISS_CTRLCOMM2_IDA_TEST_MASK)
/*! @} */

/*! @name BiSS Master and Slave ID setting */
/*! @{ */
#define BISS_MASTER_COUNT                   (1U)
#define BISS_MAX_SLAVE_COUNT                (8U)
#define BISS_MAX_CHAN_COUNT                 (8U)

#define BISS_IDS_VALID_MASK                 (0b0)
#define BISS_STATUS1_SVALID_MASK(slvID)     ((uint32_t)1 << (9 + ((slvID) * 2)))
/*! @} */

/*! @name BiSS MA and SYS clock setting */
/*! @{ */
#define BISS_MIN_MA_FREQ                    (80000U)
#define BISS_MAX_SYS_CLK_FREQ               (25000000U)
/*! @} */

/*! @brief BiSS default MA clock 100KHZ */
#define BISS_FREQS_DEFAULT                  (0x9F) /* 100kHZ */
/* When setting BISS-C protocol, the FREQR should be set to 0x05 */
#define BISS_FREQR_DEFAULT                  (0x05U)

#define BISS_AGS_MIN                        (0x7CU)
#define BISS_AGS_INFINITE                   (0x7DU)

#define BISS_CMD_IDS_BOARDCAST              (0b00000000)
#define BISS_CMD_IDS_FRM_SLV(slvID)         (0b1 << (7 - (slvID)))

#define BISS_CFGCH_MASK(x)                  (0xFF << ((x) * 2))
#define BISS_CFGCH_SEL(x,y)                 ((y) << ((x) * 2))

#define BISS_CHSEL(x)                       (0b1 << (x - 1))
#define BISS_CHANNEL1                       (0x01)

#define BISS_CMD_BOARDCAST_ALL_DEACTIVATED  (0b00)
#define BISS_CMD_BOARDCAST_CTRL_ACTIVATED   (0b01)
#define BISS_CMD_BOARDCAST_DEACTIVATED_BUS  (0b10)
#define BISS_CMD_BOARDCAST_RESERVED         (0b11)

#define BISS_CMD_ADDRESSED_ACTIVATED        (0b00)
#define BISS_CMD_ADDRESSED_DEACTIVATED      (0b01)
#define BISS_CMD_ADDRESSED_ACTIVATE_BUS     (0b10)
#define BISS_CMD_ADDRESSED_FREE             (0b11)

#define BISS_CTRL_CMD                       (0b0)
#define BISS_REG_ACCESS                     (0b1)

#define BISS_MAX_RDATA_COUNT                (64U)
#define BISS_REG_ACCESS_READ                (0b0)
#define BISS_REG_ACCESS_WRITE               (0b1)

#define BISS_REGVERS_B                      (0b0)
#define BISS_REGVERS_C                      (0b1)

#define BISS_INIT_PROC                      (0b1)

#define BISS_EN_MO_DISABLE                  (0b0)
#define BISS_EN_MO_ENABLE                   (0b1)

/*! @name BiSS Instruction and AGS value */
/*! @{ */
#define BISS_INSTR_CDM_0                    (0b010)
#define BISS_INSTR_CDM_1                    (0b001)
#define BISS_INSTR_CDM_NOT                  (0b011)
#define BISS_INSTR_CTRL_FRAME               (0b100)
#define BISS_INSTR_REDUCE_CTRL_FRAME        (0b111)
#define BISS_AGS_ENABLE                     (1)
#define BISS_AGS_DISABLE                    (0)
/*! @} */

/*! @brief BiSS slave device register. */
#define BISS_DEV_REG_LEN_1                  1
#define BISS_DEV_REG_LEN_2                  2
#define BISS_DEV_REG_LEN_3                  3
#define BISS_DEV_REG_LEN_4                  4

#define BISS_DEV_BANK_SEL_ADDR              0x40
#define BISS_DEV_EDS_BANK_NUM_ADDR          0x41
#define BISS_DEV_PROFILE_ADDR               0x42
#define BISS_DEV_PROFILE_LEN                2
#define BISS_DEV_SN_ADDR                    0x44
#define BISS_DEV_SN_LEN                     4
#define BISS_DEV_ID_ADDR                    0x78
#define BISS_DEV_ID_LEN                     6U
#define BISS_DEV_MFR_ID_ADDR                0x7E
#define BISS_DEV_MFR_ID_LEN                 2

/*! @brief BiSS slave device EDS Commo register. */
#define BISS_EDS_VER_ADDR                   0x00
#define BISS_EDS_LEN_ADDR                   0x01
#define BISS_EDS_USR_STA_ADDR               0x02
#define BISS_EDS_USR_END_ADDR               0x03
#define BISS_EDS_TMA_ADDR                   0x04
#define BISS_EDS_TO_MIN_ADDR                0x05
#define BISS_EDS_TO_MAX_ADDR                0x06
#define BISS_EDS_TOS_MIN_ADDR               0x07
#define BISS_EDS_TOS_MAX_ADDR               0x08
#define BISS_EDS_TCLK_MIN_ADDR              0x09
#define BISS_EDS_TCLK_MAX_ADDR              0x0A
#define BISS_EDS_TCYC_ADDR                  0x0B
#define BISS_EDS_TBUSY_MAX_ADDR             0x0C
#define BISS_EDS_BUSY_S_ADDR                0x0D
#define BISS_EDS_PON_DLY_ADDR               0x0E
#define BISS_EDS_PON_DLY_LEN                2
#define BISS_EDS_DC_NUM_ADDR                0x10
#define BISS_EDS_SL_NUM_ADDR                0x11
#define BISS_EDS_SL_OFF_ADDR                0x12

#define BISS_EDS_BANK1_ADDR                 0x14
#define BISS_EDS_DLEN1_ADDR                 0x15
#define BISS_EDS_FORMAT1_ADDR               0x16
#define BISS_EDS_CPOLY1_ADDR                0x17

#define BISS_EDS_BANK_CHAN_BASE             0x14
#define BISS_EDS_CHAN_OFFSET                4
#define BISS_EDS_BANK_CHAN_ADDR(channel)    (BISS_EDS_BANK_CHAN_BASE + ((channel) * BISS_EDS_CHAN_OFFSET))
#define BISS_EDS_DLEN_CHAN_BASE             0x15
#define BISS_EDS_DLEN_CHAN_ADDR(channel)    (BISS_EDS_DLEN_CHAN_BASE + ((channel) * BISS_EDS_CHAN_OFFSET))
#define BISS_EDS_FORMAT_CHAN_BASE           0x16
#define BISS_EDS_FORMAT_CHAN_ADDR(channel)  (BISS_EDS_FORMAT_CHAN_BASE + ((channel) * BISS_EDS_CHAN_OFFSET))
#define BISS_EDS_CPOLY_CHAN_BASE            0x17
#define BISS_EDS_CPOLY_CHAN_ADDR(channel)   (BISS_EDS_CPOLY_CHAN_BASE + ((channel) * BISS_EDS_CHAN_OFFSET))

#define BISS_EDS_FORMAT_TYPE_OFFSET         (0U)
#define BISS_EDS_FORMAT_TYPE_MASK           (0x01)
#define BISS_EDS_FORMAT_GET_TYPE(x)         (((x) & BISS_EDS_FORMAT_TYPE_MASK) >> \
                                            BISS_EDS_FORMAT_TYPE_OFFSET)

#define BISS_EDS_FORMAT_ALIGN_OFFSET        (1U)
#define BISS_EDS_FORMAT_ALIGN_MASK          (0x02)
#define BISS_EDS_FORMAT_GET_ALIGN(x)        (((x) & BISS_EDS_FORMAT_ALIGN_MASK) >> \
                                            BISS_EDS_FORMAT_ALIGN_OFFSET)

#define BISS_EDS_FORMAT_STOPBIT_OFFSET      (3U)
#define BISS_EDS_FORMAT_STOPBIT_MASK        (0x08)
#define BISS_EDS_FORMAT_GET_STOPBIT(x)      (((x) & BISS_EDS_FORMAT_STOPBIT_MASK) >> \
                                            BISS_EDS_FORMAT_STOPBIT_OFFSET)

#define BISS_FORMAT_TYPE_MASK               (0x01)
#define BISS_FORMAT_TYPE_SHIFT              (0U)
#define BISS_FORMAT_GET_TYPE(x)             (((x) & BISS_FORMAT_TYPE_MASK) >> \
                                            BISS_FORMAT_TYPE_SHIFT)
#define BISS_SENSOR_ROLE                    (0x00)
#define BISS_ACTUATOR_ROLE                  (0x01)

#define BISS_FORMAT_LSTOP_MASK              (0x08)
#define BISS_FORMAT_LSTOP_SHIFT             (3U)
#define BISS_FORMAT_LSTOP_GET(x)            (((x) & BISS_FORMAT_LSTOP_MASK) >> \
                                            BISS_FORMAT_LSTOP_SHIFT)
#define BISS_FORMAT_LSTOP_DISABLE           (0x00)
#define BISS_FORMAT_LSTOP_ENABLE            (0x01)

#define BISS_FORMAT_ALIGN_MASK              (0x02)
#define BISS_FORMAT_ALIGN_SHIFT             (1U)
#define BISS_FORMAT_ALIGN_GET(x)            (((x) & BISS_FORMAT_ALIGN_MASK) >> \
                                            BISS_FORMAT_ALIGN_SHIFT)
#define BISS_FORMAT_ALIGN_RIGHT             (0x00)
#define BISS_FORMAT_ALIGN_LEFT              (0x01)

#define BISS_EDS_BC_OFFSET_ADDR             (0x34)
#define BISS_EDS_BC_OFFSET_LEN              (1U)
#define BISS_BC_ENABLE_MASK                 (0x10)
#define BISS_BC_OFFSET_MASK                 (0x0F)

#define BISS_EDS_MTLEN_ADDR                 (0x0A)
#define BISS_EDS_MTLEN_LEN                  (1U)

#define BISS_EDS_MTFMT_ADDR                 (0x0B)
#define BISS_EDS_MTFMT_LEN                  (1U)

#define BISS_EDS_SIPCNT_ADDR                (0x14)
#define BISS_EDS_SIPCNT_LEN                 (4U)

#define BISS_EDS_ENTYP_ADDR                 (0x08)
#define BISS_EDS_ENTYP_LEN                  (1U)

/*! @brief BiSS slave device BP0 register. */
#define BISS_BP0_PROFILE_ID                 (0x00)
#define BISS_BP0_PROFILE_ID_MASK            (0xE0)
#define BISS_BP0_PROFILE_ID_SHIFT           (5U)
#define BISS_BP0_PROFILE_ID_GET(x)          (((x) & BISS_BP0_PROFILE_ID_MASK) >> \
                                            BISS_BP0_PROFILE_ID_SHIFT)
#define BISS_BP0_DATA_LEN_MASK              (0x1F)
#define BISS_BP0_DATA_LEN_SHIFT             (0U)
#define BISS_BP0_DATA_LEN_GET(x)            ((uint8_t)(((x) & BISS_BP0_DATA_LEN_MASK) >> \
                                            BISS_BP0_DATA_LEN_SHIFT))
#define BISS_BP0_APL_ID_MASK                (0x7F00)
#define BISS_BP0_APL_ID_SHIFT               (8U)
#define BISS_BP0_APL_TYPE_MASK              (0x8000)
#define BISS_BP0_APL_TYPE_SHIFT             (15U)
#define BISS_BP0_APL_TYPE_GET(x)            (((x) & BISS_BP0_APL_TYPE_MASK) >> \
                                            BISS_BP0_APL_TYPE_SHIFT)
#define BISS_BP0_SENSOR                     (0x00)
#define BISS_BP0_ACTUATOR                   (0x01)
#define BISS_BP0_CRCPOLY                    (0x25)

#define BISS_TEMP_8BIT_MASK                 (0xFF)
#define BISS_TEMP_12BIT_SYM_MASK            (0x0800)
#define BISS_TEMP_16BIT_MASK                (0xFFFF)

/*! @brief BiSS slave device BP3 register. */
#define BISS_BP3_PROFILE_ID                 (0x06)
#define BISS_BP3_PROFILE_ID_MASK            (0xF0)
#define BISS_BP3_PROFILE_ID_SHIFT           (4U)
#define BISS_BP3_PROFILE_ID_GET(x)          (((x) & BISS_BP3_PROFILE_ID_MASK) >> \
                                            BISS_BP3_PROFILE_ID_SHIFT)
#define BISS_BP3_CRC_MASK                   (0x01)
#define BISS_BP3_VER_MASK                   (0x0E)
#define BISS_BP3_VER_SHIFT                  (1U)
#define BISS_BP3_DATA_LEN_MASK              (0xEF00)
#define BISS_BP3_DATA_LEN_SHIFT             (8U)
#define BISS_BP3_DATA_LEN_GET(x)            ((uint8_t)(((x) & BISS_BP3_DATA_LEN_MASK) >> \
                                            BISS_BP3_DATA_LEN_SHIFT))
#define BISS_BP3_CRCPOLY                    (0x43)

#define BISS_BP3S_PROFILE_ID                (0x07)
#define BISS_BP3S_PROFILE_ID_MASK           (0x70)
#define BISS_BP3S_PROFILE_ID_SHIFT          (4U)
#define BISS_BP3S_PROFILE_ID_GET(x)         (((x) & BISS_BP3S_PROFILE_ID_MASK) >> \
                                            BISS_BP3S_PROFILE_ID_SHIFT)
#define BISS_BP3S_CRC_MASK                  (0x01)
#define BISS_BP3S_VER_MASK                  (0x0E)
#define BISS_BP3S_VER_SHIFT                 (1U)
#define BISS_BP3S_DATA_LEN_MASK             (0x7F00)
#define BISS_BP3S_DATA_LEN_SHIFT            (8U)
#define BISS_BP3S_DATA_LEN_GET(x)           ((uint8_t)(((x) & BISS_BP3S_DATA_LEN_MASK) >> \
                                            BISS_BP3S_DATA_LEN_SHIFT))
#define BISS_BP3S_CRCPOLY                   (0x190D9)

#define BISS_SPEC_CPOLY_ADDR                (0x1C)
#define BISS_SPEC_CPOLY_LEN                 (4U)
#define BISS_SPEC_CSTART_ADDR               (0x20)
#define BISS_SPEC_CSTART_LEN                (4U)

#define BISS_SCD_BINARY_CODED               (0x00)
#define BISS_SCD_GRAY_CODED                 (0x01)

#define BISS_SEL_SCRCLEN                    (0x00)
#define BISS_SEL_SCRCPOLY                   (0x01)

#define BISS_LINEDELAY_MASK                 (0xFF)

#define BISS_BREAK_ENABLE                   (1U)

/*! @brief Defines the BiSS channel flag. */
typedef enum _biss_channel_flags_t
{
    BISS_UseCurrentChannel = 0U,
    BISS_UsePhyChannel1 = 1U,
    BISS_UseNextChannel = 1U,
} biss_chan_flag_t;

/*! @brief Defines the BiSS Master protocol type. */
typedef enum _biss_prot_type_t
{
    PROTOCOL_BISS_B = 0x00U,
    PROTOCOL_BISS_C = 0x01U,
    PROTOCOL_SSI = 0x02U,
    PROTOCOL_NOT_USED = 0x03U,
} biss_prot_type_t;

/*! @brief Defines the SCD align type. */
typedef enum _biss_align_type_t
{
    BISS_RightAlign = 0x00,
    BISS_LeftAlign
} biss_align_type_t;

/*! @brief Defines trigger mode.
 *
 * BISS_INSTR_TRIGGER - Data acquisition will be triggered by software
 * BISS_AGS_TRIGGER   - Data acquisition will automatically by setting repetion
 *                  time
 * BISS_PIN_TRIGGER   - Data acquistion will be triggered by a pin GETSENS
 */
typedef enum _biss_trigger_mode_t
{
    BISS_INSTR_TRIGGER = 0U,
    BISS_AGS_TRIGGER,
    BISS_TIMEOUT_TRIGGER,
    BISS_PIN_TRIGGER,
} biss_trigger_mode_t;

/*! @brief BiSS slave role type. */
typedef enum _biss_slave_role_t
{
    BISS_Actuator = 0U,
    BISS_BusCoupler = 1U,
    BISS_TempSensor = 2U,
    BISS_RotaryEncoder = 3U,
    BISS_LinearEncoder = 4U,
    BISS_UnknowRole = 5U,
} biss_slave_role_t;

typedef enum _biss_encoder_type_t
{
    BISS_SENSOR_ROTARY = 0x00,
    BISS_SENSOE_LINEAR = 0x01,
} biss_encoder_type_t;

typedef enum _biss_data_type_t
{
    BISS_DATA_SENSOR = 0u,
    BISS_DATA_ACTUATOR = 1u,
} biss_data_type_t;

/*! @brief BiSS slave information. */
typedef struct _biss_slave_info_t
{
    biss_slave_role_t   role;       /* !< slave role
                                     * BISS_Actuator
                                     * BISS_BusCoupler
                                     * BISS_TempSensor
                                     * BISS_RotaryEncoder
                                     * BISS_LinearEncoder
                                     * BISS_UnknowRole
                                     */
    bool                stopBit;    /*!< Stop bit enable flag, enabled with role is Actuator */
    uint16_t            profile;
    uint16_t            mid;
    uint32_t            sn;
    uint8_t             did[6];
    uint8_t             tma;        /* Minimum permitted clock period on MA Unit(1ns) */
    uint8_t             EDSSlvID;   /*!< The slave ID which has EDS info */
    uint8_t             commEDS;    /*!< common EDS ID, enabled with commEDS != 0 */
    uint8_t             profileEDS; /*!< specification EDS ID, enabled with specEDS != 0 */
    uint8_t             crcLen;      /*!< CRC length of tranfered data */
    uint32_t            crcPoly;    /*!< CRC poly for transfer, enabled with dataLen != 0 */
    uint32_t            crcStart;   /*!< CRC start value, enabled with dataLen != 0 */
    biss_data_type_t    dataType;   /*!< Sensor or Actuator */
    uint8_t             dataLen;    /*!< Data length of tranfered data */
    uint8_t             errWarLen;  /*!< error and warning bit number */
    uint8_t             mtLen;      /*!< Multiturn number, enabled with role = rotary */
    uint8_t             stLen;      /*!< Singleturn number, enabled with role = rotary */
    biss_align_type_t   dataAlign;  /*!< Data align type, the align show data format which
                                     * stored in SCData register, left align or right align */
    uint8_t             mtAlign;    /*!< Multiturn data align type */
    uint8_t             stAlign;    /*!< Singleturn data align type stored in SCData */
    uint64_t            mtMask;     /*!< Multiturn mask for multitrun data getting */
    uint64_t            stMask;     /*!< Singleturn mask for singleturn data getting */
    uint32_t            step;       /*!< The resolution ratio for singleturn data */
} biss_slave_info_t;

/*! @brief BiSS Master information. */
typedef struct _biss_master_t
{
    BISS_Type           *base;
    uint8_t             freqMADiv;
    uint8_t             freqAGSDiv;
    uint8_t             maxProcTime;    /*!< The max process time allowed */
    uint8_t             processTime;    /*!< Additional processing time SCD in clocks */
    uint8_t             slvCnt;
    uint8_t             lineDelay;
    uint32_t            dacq;
    uint32_t            ctrlcomm2;
    biss_prot_type_t    protType;
    biss_trigger_mode_t triggerMode;
    biss_slave_info_t   slvList[BISS_MAX_SLAVE_COUNT];
} biss_master_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @brief Get BiSS master handle pointer.
 *
 * @param base base BiSS peripheral address.
 */
biss_master_t *BISS_GetMaster(BISS_Type *base);

/*!
 * @brief Initialize the BiSS master.
 * This function configures the BISS module with the input parameters.
 * User should call this function before any BISS operations.
 * @param base BiSS peripheral base address.
 * @param srcClk_Hz BiSS sys clock frequency.
 * @param ma_Hz BiSS MA clock frequency.
 * @param ags_Hz BiSS AGS frequency.
 * @return The BiSS master handle pointer.
 */
biss_master_t *BISS_MasterInit(BISS_Type *base, uint32_t srcClk_Hz, uint32_t ma_Hz, uint32_t ags_Hz);

/*!
 * @brief Calculate BiSS MA master clock division valule
 *
 * @param master BiSS master handle pointer.
 * @param srcClk_Hz BiSS sys clock frequency.
 * @param ma_Hz BiSS MA clock frequency.
 * @return The division value. A negative number indicates an incorrect input.
 */
int BISS_CalculateMADiv(biss_master_t *master, uint32_t srcClk_Hz, uint32_t ma_Hz);

/*!
 * @brief Calculate BiSS frame repetition rate division valule
 *
 * @param master BiSS master handle pointer.
 * @param srcClk_Hz BiSS sys clock frequency.
 * @param AGSfre_Hz BiSS frame repetition frequency.
 * @return The division value. A negative number indicates an incorrect input.
 */
int BISS_CalculateAGSDiv(biss_master_t *master, uint32_t srcClk_Hz, uint32_t AGSfre_Hz);

/*!
 * @brief Set BiSS master MA clock division valule.
 *
 * @param master BiSS master handle pointer.
 * @param Div MA clock frequency division value.
 */
void BISS_SetFREQS(biss_master_t *master, uint8_t MADiv);

/*!
 * @brief Set BiSS frame repetition rate.
 *
 * @param master BiSS master handle pointer.
 * @param Div frame repetition rate division valule.
 */
void BISS_SetFREQAGS(biss_master_t *master, uint8_t AGSDiv);

/*!
 * @brief Set BiSS Register data clock frequency.
 *
 * @param master BiSS master handle pointer.
 * @param Div FREQR division value.
 */
void BISS_SetFREQR(biss_master_t *master, uint8_t FREQRDiv);

/*!
 * @brief Enable/disable CRC check.
 *
 * @param master BiSS master handle pointer.
 * @param NoCRC true - not stroe CRC, false - store CRC.
 */
void BISS_SetNOCRC(biss_master_t *master, bool NoCRC);

/*!
 * @brief Enable/disable single Bank.
 *
 * @param master BiSS master handle pointer.
 * @param SingleBank true - use one RAM bank, false - use two RAM banks.
 */
void BISS_SetSingleRAMBank(biss_master_t *master, bool SingleBank);

/*!
 * @brief Set BiSS master protocol.
 *
 * @param master BiSS master handle pointer.
 * @param protType BiSS protocol type.
 */
void BISS_SetProtocol(biss_master_t *master, biss_prot_type_t protType);

/*!
 * @brief set hold cmd after timeout.
 *
 * @param master BiSS master handle pointer.
 * @param holdcmd true - hold cdm, false - not hold cdm.
 */
void BISS_SetHoldCDM(biss_master_t *master, bool holdcdm);

/*!
 * @brief set default channel ID.
 *
 * @param master BiSS master handle pointer.
 * @param channel channel ID 1 - 8.
 */
void BISS_SetChannel(biss_master_t *master, int channel);

/*!
 * @brief set processing time by the delay of the start bit at MO
 *
 * @param master BiSS master handle pointer.
 * @param busy MO busy time.
 */
void BISS_SetMOBusy(biss_master_t *master, uint8_t busy);

/*!
 * @brief Enable/disable MO signal.
 *
 * @param master BiSS master handle pointer.
 * @param enmo true - enable MO signal, false - disable MO signal.
 */
void BISS_SetENMO(biss_master_t *master, bool enmo);

/*!
 * @brief Hold ram bank.
 *
 * @param master BiSS master handle pointer.
 * @param holdbank true - hold bank, false - not hold bank.
 */
void BISS_SetHoldBank(biss_master_t *master, bool holdbank);

/*!
 * @brief Initialize BiSS-C status.
 *
 * @param master BiSS master handle pointer.
 */
void BISS_InitBissStatus(biss_master_t *master);

/*!
 * @brief Abort data transmission.
 *
 * @param master BiSS master handle pointer.
 */
void BISS_AbortTrans(biss_master_t *master);

/*!
 * @brief Get BiSS master status1 register.
 *
 * @param master BiSS master handle pointer.
 * @return BiSS master status1 register value.
 */
uint32_t BISS_GetStatus(biss_master_t *master);

/*!
 * @brief Disable Automatic Get Sensor Data
 *
 * @param master BiSS master handle pointer.
 */
void BISS_DisableAGS(biss_master_t *master);

/*!
 * @brief Enable Automatic Get Sensor Data.
 *
 * @param master BiSS master handle pointer.
 */
void BISS_EnableAGS(biss_master_t *master);

/*!
 * @brief Get step value of BiSS slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @return step value.
 */
uint32_t BISS_GetStepVal(biss_master_t *master, uint8_t slvID);

/*!
 * @brief Get line delay.
 *
 * @param master BiSS master handle pointer.
 * @return line delay.
 */
uint8_t BISS_GetLineDelay(biss_master_t *master);

/*!
 * @brief Get BiSS trigger mode.
 *
 * @param master BiSS master handle pointer.
 * @return BiSS trigger mode.
 */
biss_trigger_mode_t BISS_GetTriggerMode(biss_master_t *master);

/*!
 * @brief Change BiSS trigger mode.
 *
 * @param master BiSS master handle pointer.
 * @param triggerMode BiSS trigger mode.
 */
void BISS_ChangeTriggerMode(biss_master_t *master, biss_trigger_mode_t triggerMode);


/*!
 * @brief Initialize BiSS sequence.
 *
 * @param master BiSS master handle pointer.
 */
void BISS_InitBissSequence(biss_master_t *master);

/*!
 * @brief send out instruction.
 *
 * @param master BiSS master handle pointer.
 * @param instr BiSS instruction
 * @param ags automatic get sensor data
 */
void BISS_InstrSend(biss_master_t *master, int instr, int ags);

/*!
 * @brief Wait for instruction to be processed.
 *
 * @param master BiSS master handle pointer.
 */
void BISS_InstrWait(biss_master_t *master);

/*!
 * @brief Send out instruction and wait for it to be processed.
 *
 * @param master BiSS master handle pointer.
 * @param instr BiSS instruction
 * @param ags automatic get sensor data
 */
void BISS_InstrSendandWait(biss_master_t *master, int instr, int ags);

/*!
 * @brief BiSS command process.
 *
 * @param master BiSS master handle pointer.
 * @param IDS slave device ID set.
 * @param cmd BiSS command.
 * @return kStatus_Success  Successfully process command.
 * @return kStatus_Fail failed to process command.
 */
status_t BISS_CMDProcess(biss_master_t *master, uint8_t IDS, uint8_t cmd);

/*!
 * @brief Activate all slave devices.
 *
 * @param master BiSS master handle pointer.
 * @return kStatus_Success  Successfully activate all slave devices.
 * @return kStatus_Fail failed to activate
 */
status_t BISS_ActivateAllSLV(biss_master_t *master);

/*!
 * @brief Return pointer of BiSS slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID Biss slave device ID 0 - 7.
 * @return pointer of BiSS slave device.
 */
biss_slave_info_t *BISS_SLVGet(biss_master_t *master, uint8_t slvID);

/*!
 * @brief Write BiSS slave device's registers.
 *
 * @param master BiSS master handle pointer.
 * @param slvID Biss slave device ID 0 - 7.
 * @param regAddr start register address.
 * @param regNum Register number.
 * @param buffer Data buffer.
 * @return kStatus_Success  Successfully write to register
 * @return kStatus_Fail failed to write register
 */
status_t BISS_SLVWriteRegister(biss_master_t *master, uint8_t slvID, uint8_t regAddr, uint8_t regNum, uint8_t *buffer);

/*!
 * @brief Read BiSS slave device's registers.
 *
 * @param master BiSS master handle pointer.
 * @param slvID Biss slave device ID 0 - 7.
 * @param regAddr start register address.
 * @param regNum Register number.
 * @param buffer Data buffer.
 * @return kStatus_Success  Successfully read from register
 * @return kStatus_Fail failed to read register
 */
status_t BISS_SLVReadRegister(biss_master_t *master, uint8_t slvID, uint8_t regAddr, uint8_t regNum, uint8_t *buffer);

/*!
 * @brief Enable/disable SCD of the slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @param enable true - SCD is available, false - SCD not available.
 */
void BISS_SLVSetSCDEN(biss_master_t *master, uint8_t slvID, bool enable);

/*!
 * @brief Set SCD length of the slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @param SCDLen SCD length.
 */
void BISS_SLVSetSCDLen(biss_master_t *master, uint8_t slvID, int SCDLen);

/*!
 * @brief Set CRC length of the slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @param CRCLen CRC length.
 */
void BISS_SLVSetCRCLen(biss_master_t *master, uint8_t slvID, int CRCLen);

/*!
 * @brief Set SCD length and CRC length of the slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvid slave device ID 0 - 7.
 * @param SCDLen SCD length.
 * @param CRCLen CRC length.
 */
void BISS_SLVSetSCD(biss_master_t *master, uint8_t slvID, int SCDLen, int CRCLen);

/*!
 * @brief Set CRC polynomial of the slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @param CRCPoly CRC polynomial.
 */
void BISS_SLVSetCRCPoly(biss_master_t *master, uint8_t slvID, int CRCPoly);

/*!
 * @brief Set CRC start value of the slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @param CRCStart CRC start value.
 */
void BISS_SLVSetCRCStart(biss_master_t *master, uint8_t slvID, uint32_t CRCStart);

/*!
 * @brief Set leading stop bit of the slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @param align with/without leading stop bit on actuator data.
 */
void BISS_SLVSetLStop(biss_master_t *master, uint8_t slvID, bool enable);

/*!
 * @brief Set data type of the slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @param dataType data type - sensor or actuator.
 */
void BISS_SLVSetDataType(biss_master_t *master, uint8_t slvID,
                         biss_data_type_t dataType);

/*!
 * @brief Get EDS bank number of the slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @param bank EDS bank number.
 * @return kStatus_Success  Successfully get EDS bank number.
 * @return kStatus_Fail failed to get EDS bank number.
 */
status_t BISS_SLVGetEDSBank(biss_master_t *master, uint8_t slvID, uint8_t* bank);

/*! @brief Slect Ram bank of the slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @param bank  bank number.
 * @return kStatus_Success  Successfully set bank number.
 * @return kStatus_Fail failed to set bank number.
 */
status_t BISS_SLVSelectBank(biss_master_t *master, uint8_t slvID, uint8_t bank);

/*!
 * @brief Get profile of the slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @param profile profile value.
 * @return kStatus_Success  Successfully get profile.
 * @return kStatus_Fail failed to get profile.
 */
status_t BISS_SLVGetProfile(biss_master_t *master, uint8_t slvID, uint16_t *profile);

/*!
 * @brief Get serial number of the slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @param serialNum serial number.
 * @return kStatus_Success  Successfully get serial number.
 * @return kStatus_Fail failed to get serial number.
 */
status_t BISS_SLVGetSerialNum(biss_master_t *master, uint8_t slvID, uint32_t *serialNum);

/*!
 * @brief Get manufacturer ID of the slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @param mfrID device ID.
 * @return kStatus_Success  Successfully get manufacturer ID.
 * @return kStatus_Fail failed to get manufacturer ID.
 */
status_t BISS_SLVGetManufacturerID(biss_master_t *master, uint8_t slvID, uint16_t *mfrID);

/*!
 * @brief Get device ID of the slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @param devID device ID.
 * @return kStatus_Success  Successfully get device ID.
 * @return kStatus_Fail failed to get device ID.
 */
status_t BISS_SLVGetDeviceID(biss_master_t *master, uint8_t slaveID, uint8_t *devID);

/*!
 * @brief Update slave device information via Profile.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @return kStatus_Success  Successfully update device information.
 * @return kStatus_Fail failed to update device information.
 */
status_t BISS_SLVUpdateWithProfile(biss_master_t *master, uint8_t slvID);

/*!
 * @brief Update slave device information via Common EDS.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @return kStatus_Success  Successfully update device information.
 * @return kStatus_Fail failed to update device information.
 */
status_t BISS_SLVUpdatewithCommonEDS(biss_master_t *master, uint8_t slvID);

/*!
 * @brief Update slave device information via ProfileEDS.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @return kStatus_Success  Successfully update device information.
 * @return kStatus_Fail failed to update device information.
 */
status_t BISS_SLVUpdatewithProfileEDS(biss_master_t *master, uint8_t slvID);

/*!
 * @brief scan slave device in the BiSS bus.
 *
 * @param master BiSS master handle pointer.
 * @return kStatus_Success  Successfully scan slave devices.
 * @return kStatus_Fail failed to scan slave devices.
 */
status_t BISS_SLVScan(biss_master_t *master);

/*!
 * @brief Deactivate slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @return kStatus_Success  Successfully deactivate slave device.
 * @return kStatus_Fail failed to deactivate slave device.
 */
status_t BISS_SLVDeactivate(biss_master_t *master, uint8_t slvID);

/*!
 * @brief Activate slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @return kStatus_Success  Successfully activate slave device.
 * @return kStatus_Fail failed to activate slave device.
 */
status_t BISS_SLVActivate(biss_master_t *master, uint8_t slvID);

/*!
 * @brief Get slave device count.
 *
 * @param master BiSS master handle pointer.
 * @return slave device count.
 */
uint8_t BISS_SLVGetCnt(biss_master_t *master);

/*!
 * @brief setup slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 */
void BISS_SLVSetup(biss_master_t *master, uint8_t slvID);

/*!
 * @brief Get SCD data of a slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @return SCD data.
 */
uint64_t BISS_SLVGetSCDRawData(biss_master_t *master, uint8_t slvID);

/*!
 * @brief Check if SCD data is valid
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @return kStatus_Success  SCD is valid.
 * @return kStatus_Fail SCD is invalid.
 */
status_t BISS_SLVCheckSVALID(biss_master_t *master, uint8_t slvID);

/*!
 * @brief Reset SVALID bit.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 */
void BISS_SLVResetSVALID(biss_master_t *master, uint8_t slvID);

/*!
 * @brief Get SCD data of a slave device.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @param SCData SCD data.
 * @return kStatus_Success  SCD is valid.
 * @return kStatus_Fail SCD is invalid.
 */
status_t BISS_SLVGetSCD(biss_master_t *master, uint8_t slvID, uint64_t *SCData);

/*!
 * @brief Get warning status from SCDdata.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @return warning status.
 */
int BISS_SCDGetnWarning(biss_master_t *master, uint8_t slvID, uint64_t SCData);

/*!
 * @brief Get error status from SCDdata.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @return error status.
 */
int BISS_SCDGetnERR(biss_master_t *master, uint8_t slvID, uint64_t SCData);

/*!
 * @brief Get linear data from SCDdata.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @return linear data.
 */
uint64_t BISS_SCDGetLinear(biss_master_t *master, uint8_t slvID, uint64_t SCData);

/*!
 * @brief Get multiple turn data from SCDdata.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @return multiple turn data.
 */
uint64_t BISS_SCDGetMtVal(biss_master_t *master,
                          uint8_t slvID, uint64_t SCData);

/*!
 * @brief Get single turn data from SCDdata.
 *
 * @param master BiSS master handle pointer.
 * @param slvID slave device ID 0 - 7.
 * @return single turn data.
 */
uint64_t BISS_SLVGetStVal(biss_master_t *master,
                          uint8_t slvID, uint64_t SCData);

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_BISS_H_ */
