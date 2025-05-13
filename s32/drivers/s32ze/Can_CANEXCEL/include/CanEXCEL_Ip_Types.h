/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CANEXCEL_IP_TYPES_H_
#define CANEXCEL_IP_TYPES_H_

/**
*   @file CanEXCEL_Ip_Types.h
*
*   @addtogroup CanEXCEL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CanEXCEL_Ip_Cfg.h"
#include "CanEXCEL_Ip_DevReg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANEXCEL_IP_TYPES_VENDOR_ID_H                      43
#define CANEXCEL_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H       4
#define CANEXCEL_IP_TYPES_AR_RELEASE_MINOR_VERSION_H       7
#define CANEXCEL_IP_TYPES_AR_RELEASE_REVISION_VERSION_H    0
#define CANEXCEL_IP_TYPES_SW_MAJOR_VERSION_H               2
#define CANEXCEL_IP_TYPES_SW_MINOR_VERSION_H               0
#define CANEXCEL_IP_TYPES_SW_PATCH_VERSION_H               1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanEXCEL_Ip_Cfg.h are of the same vendor */
#if (CANEXCEL_IP_TYPES_VENDOR_ID_H != CANEXCEL_IP_CFG_VENDOR_ID_H)
    #error "CanEXCEL_Ip_Types.h and CanEXCEL_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and CanEXCEL_Ip_Cfg.h are of the same Autosar version */
#if ((CANEXCEL_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H    != CANEXCEL_IP_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (CANEXCEL_IP_TYPES_AR_RELEASE_MINOR_VERSION_H    != CANEXCEL_IP_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (CANEXCEL_IP_TYPES_AR_RELEASE_REVISION_VERSION_H != CANEXCEL_IP_CFG_AR_RELEASE_REVISION_VERSION_H) \
)
    #error "AutoSar Version Numbers of CanEXCEL_Ip_Types.h and CanEXCEL_Ip_Cfg.h are different"
#endif
/* Check if current file and CanEXCEL_Ip_Cfg.h are of the same Software version */
#if ((CANEXCEL_IP_TYPES_SW_MAJOR_VERSION_H != CANEXCEL_IP_CFG_SW_MAJOR_VERSION_H) || \
     (CANEXCEL_IP_TYPES_SW_MINOR_VERSION_H != CANEXCEL_IP_CFG_SW_MINOR_VERSION_H) || \
     (CANEXCEL_IP_TYPES_SW_PATCH_VERSION_H != CANEXCEL_IP_CFG_SW_PATCH_VERSION_H) \
)
    #error "Software Version Numbers of CanEXCEL_Ip_Types.h and CanEXCEL_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**@brief This will enable Restricted Operation Mode  */
#define CANXL_IP_ROM_U32                         ((uint32)0x00000001U)
/**@brief Tx SMB Error Response  */
#define CANXL_IP_TX_ERROR_RESPONSE_U32           ((uint32)0x00000002U)
/**@brief Define how controller recover from bus off state */
#define CANXL_IP_BUSOFF_RECOVERY_U32             ((uint32)0x00000004U)
/**@brief Protocol Exception */
#define CANXL_IP_PROTOCOL_EXCEPTION_U32          ((uint32)0x00000008U)
/**@brief Edge Filter Enable */
#define CANXL_IP_EDGE_FILTER_U32                 ((uint32)0x00000010U)
/**@brief CAN XL Error Response as protocol exception */
#define CANXL_IP_XLER_U32                        ((uint32)0x00000020U)

/** @brief CanEXCEL SubModules Instances Pointers Structure
 *  @details CanEXCEL Cotains base address pointers to the subModules from CanEXCEL
 */
/* implements CANEXCEL_StructType_structure */
typedef struct {
    CANXL_SIC_Type ** EXL_SIC;
    CANXL_MRU_Type ** EXL_MRU;
    CANXL_GRP_CONTROL_Type ** EXL_GRP;
    CANXL_DSC_CONTROL_Type ** EXL_DESC_CTR;
    CANXL_MSG_DESCRIPTORS_Type ** EXL_MSGD;
    CANXL_RXFIFO_CONTROL_Type ** EXL_RXF_CNT;
    CANXL_RXFIFO_Type ** EXL_RXFIFO;
    CANXL_FILTER_BANK_Type ** EXL_FILTER;
#if (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON)
    CAN_TBS_Type ** EXL_TBS;
#endif
} CANEXCEL_StructType;

/** @brief CanEXCEL Message Buffer ID type
 *  @details CanEXCEL Id Type, Standard or Extended
 */
/* implements Canexcel_Ip_MsgBuffIdType_enum */
typedef enum
{
    CANEXCEL_MSG_ID_STD = 0,     /**< Standard ID*/
    CANEXCEL_MSG_ID_EXT          /**< Extended ID*/
} Canexcel_Ip_MsgBuffIdType;

/** @brief CanEXCEL Message Format type
 *  @details CanEXCEL CAN Frame type, Classic, FastData(FD), and XL
 */
/* implements Canexcel_Ip_FrameType_enum */
typedef enum
{
    CANEXCEL_CLASIC_FRAME,
    CANEXCEL_FD_FRAME,
    CANEXCEL_XL_FRAME
} Canexcel_Ip_FrameType;

/** @brief The status of data coherency mechanism for semaphore-based access to device RAM.
 *  @details The descriptor control Status mechanism
 */
 /* implements Canexcel_Ip_DesCntStatus_typedef */
typedef enum
{
    CANEXCEL_DESCNTSTATUS_UNLOCKED,         /**< Descriptor is not locked. */
    CANEXCEL_DESCNTSTATUS_LOCKED_HW,        /**< Descriptor is locked by CANEXCEL hardware. */
    CANEXCEL_DESCNTSTATUS_LOCKED_SYS,       /**< Descriptor is locked by system host. */
    CANEXCEL_DESCNTSTATUS_INVALID           /**< Invalid configuration, not possible. */
} Canexcel_Ip_DesCntStatus;

/** @brief The status of descriptor state.
 *  @details The descriptor control Status mechanism
 */
  /* implements Canexcel_Ip_DescState_typedef */
typedef enum
{
    CANEXCEL_DESC_STATE_INACTIVE,
    CANEXCEL_DESC_STATE_EMPTY,
    CANEXCEL_DESC_STATE_NOTFULL,
    CANEXCEL_DESC_STATE_FULL,
    CANEXCEL_DESC_STATE_OVERRUN
} Canexcel_Ip_DescState;

/** @brief Canexcel error interrupt types
 */
/* implements  Canexcel_Ip_ErrorIntType_enum */
typedef enum
{
    CANEXCEL_IP_INT_RX_WARNING,     /*!< RX warning interrupt*/
    CANEXCEL_IP_INT_TX_WARNING,     /*!< TX warning interrupt*/
    CANEXCEL_IP_INT_ERR,            /*!< Error interrupt*/
    CANEXCEL_IP_INT_ERR_FAST,       /*!< Error Fast interrupt*/
    CANEXCEL_IP_INT_ERR_XL,         /*!< Error XL interrupt*/
    CANEXCEL_IP_INT_ERR_INT,        /*!< Error Internal interrupt*/
    CANEXCEL_IP_INT_BUSOFF,         /*!< Bus off interrupt*/
    CANEXCEL_IP_INT_BUSOFF_DONE,    /*!< Bus off done interrupt*/
    CANEXCEL_IP_INT_PASS_ERR,       /*!< Passive error interrupt*/
    CANEXCEL_IP_INT_FREEZE,         /*!< ACk Freeze event interrupt*/
} Canexcel_Ip_ErrorIntType;

#if (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON)
/** @brief Canexcel Timestamp Clock Sources
 * This are define based on the resource file of each Chip support source selection */
/* implements  Canexcel_Ip_TimeBaseSelType_enum */
typedef enum
{
    CANTBS_TIMESURCE_BUS0,  /*!< This is NETC Source */
    CANTBS_TIMESURCE_BUS1,  /*!< This is GTM TBU0 Source */
    CANTBS_TIMESURCE_BUS2,  /*!< This is GTM TBU1 Source */
    CANTBS_TIMESURCE_BUS3   /*!< This is CE_STM_0 Source */
}Canexcel_Ip_TimeBaseSelType;

/** @brief Canexcel Timestamp Capture Point
 */
/* implements  Canexcel_Ip_TimeStampCaptureType_enum */
typedef enum
{
    CANEXCEL_TIMESTAMPCAPTURE_DISABLE,      /**< Time stamp capture disabled. */
    CANEXCEL_TIMESTAMPCAPTURE_END,          /**< Time stamp is captured in the point the frame is considered valid. */
    CANEXCEL_TIMESTAMPCAPTURE_SOF,          /**< The high resolution time stamp is captured in the start of the CAN frame */
    CANEXCEL_TIMESTAMPCAPTURE_START         /**< The high resolution time stamp is captured in the start of frame for classical CAN frames and
                                             in res bit for CAN FD frames and in the res XL bit for CAN XL frames */
}Canexcel_Ip_TimeStampCaptureType;
#endif /* (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON) */

/** @brief The status used and reported by Canexcel Ip driver.
 *  @details The CanEXCEL specific error codes
 */
/* implements  Canexcel_Ip_StatusType_enum */
typedef enum
{
    CANEXCEL_STATUS_SUCCESS  = E_OK,          /**< Successfull Operation Completed */
    CANEXCEL_STATUS_ERROR = E_NOT_OK,         /**< Error Operation Completed */
    CANEXCEL_STATUS_BUSY,                     /**< Busy Operation Completed */
    CANEXCEL_STATUS_TIMEOUT,                  /**< TimeOut Operation Completed */
    CANEXCEL_STATUS_BUFF_OUT_OF_RANGE,        /**< The specified MB index is out of the configurable range */
    CANEXCEL_STATUS_NO_TRANSFER_IN_PROGRESS,  /**< There is no transmission or reception in progress */
} Canexcel_Ip_StatusType;

/*! @brief CANXL operation modes
 */
/*  implements  Canexcel_Ip_ModesType_typedef */
typedef enum
{
    CANEXCEL_NORMAL_MODE,        /**< Normal mode or user mode @internal gui name="Normal" */
    CANEXCEL_LISTEN_ONLY_MODE,   /**< Listen-only mode @internal gui name="Listen-only" */
    CANEXCEL_LOOPBACK_MODE       /**< Loop-back mode @internal gui name="Loop back" */
} Canexcel_Ip_ModesType;

/*! @brief The type of the event which occurred when the callback was invoked.
 */
/* implements Canexcel_Ip_EventType_typedef */
typedef enum
{
    CANEXCEL_EVENT_RX_COMPLETE = 0U,     /**< A frame was received in the configured Rx Descriptor. */
    CANEXCEL_EVENT_TX_COMPLETE,          /**< A frame was sent from the configured Tx Descriptor. */
    CANEXCEL_EVENT_RXFIFO_COMPLETE,      /**< A frame was received in the Rx FIFO. */
    CANEXCEL_EVENT_RXFIFO_OVERFLOW,     /**< Rx FIFO is full (incoming message was lost). */
    CANEXCEL_EVENT_ERROR,               /**<  Errors detected in CAN frames of any format (interrupt mode only) */
    CANEXCEL_EVENT_ERROR_FD,            /**< Errors detected in the data phase of CAN FD frames with the BRS bit set only (interrupt mode only) */
    CANEXCEL_EVENT_ERROR_XL,            /**< Errors detected in the data phase of CAN XL frames*/
    CANEXCEL_EVENT_PASSIVE,             /**< The module enters in Passive State */
    CANEXCEL_EVENT_BUSOFF,              /**< The module enters in BusOff State */
    CANEXCEL_EVENT_RX_WARNING,          /**< The Rx error counter transitioned from less than 96 to greater than or equal to 96 (interrupt mode only) */
    CANEXCEL_EVENT_TX_WARNING           /**< The Tx error counter transitioned from less than 96 to greater than or equal to 96 (interrupt mode only) */
} Canexcel_Ip_EventType;

/*! @brief CanExcel Message Descriptor Queue Config */
/* implements Canexcel_Ip_QueueConf_typedef */
typedef struct{
    uint8 mdQueueWatermark; /*!< The Msg Descriptor Grup Watermark Level */
    uint8 mdQueueDepth;     /*!< The Msg Descriptor Grup Queue Depth */
} Canexcel_Ip_QueueConf;

/*! @brief CanExcel Rx FIFO filter type */
/* implements Canexcel_Ip_RxFifoFilterType_enum */
typedef enum
{
    CANEXCEL_IP_RX_FIFO_RANGE_FILTER = 0U,      /*!< Filter element with range scheme*/
    CANEXCEL_IP_RX_FIFO_MASK_FILTER,            /*!< Filter element with filter + mask scheme*/
} Canexcel_Ip_RxFifoFilterType;
/* implements  Canexcel_Ip_TransceiverModeType_typedef */
typedef struct{
    boolean PwmModeEnable;              /*!< Enable/disable PWM mode */
    uint8 PwmShortPhase;                /*!<  PWM Short Phase */
    uint8 PwmLongPhase;                 /*!<  PWM Long Phase */
    uint8 PwmOffset;                    /*!<  PWM Offset */
    boolean ProtocolExceptionEnable;    /*!<  TRUE to signalize errors as protocol exception; FALSE to signalize errors with Error frames */
} Canexcel_Ip_TransceiverModeType;
/* implements  Canexcel_Ip_RxFifoFilterID_ADDR_typedef */
typedef struct{
    Canexcel_Ip_RxFifoFilterType filterType;
    uint32 idAddrFilterH;    /* Filter ID/ADDR element in case of mask filter type this is ID/ADDR value, in case of range filter type this is the higher value. */
    uint32 idAddrFilterL;    /*Canexcel_Ip_RxFifoFilterID_ADDR Filter ID/ADDR element in case of mask filter type this is mask value, in case of range filter type this is the lower value. */
} Canexcel_Ip_RxFifoFilterID_ADDR;
/* implements  Canexcel_Ip_RxFifoFilterSDU_CAN_typedef */
typedef struct{
    Canexcel_Ip_RxFifoFilterType filterType;
    uint8 sduVcanFilterH;    /* Filter SDU/VCAN element in case of mask filter type this is SDU/VCAN value, in case of range filter type this is the higher value. */
    uint8 sduVcanFilterL;    /* Filter SDU/VCAN element in case of mask filter type this is mask value, in case of range filter type this is the lower value. */
} Canexcel_Ip_RxFifoFilterSDU_CAN;

/*! @brief CanExcel Rx FIFO filter Config Structure */
/* implements  Canexcel_Ip_RxFifoFilter_structure */
typedef struct{
    uint32 SecMask;
    uint32 SecFilter;
    uint8  noIdFilters;
    uint8  noActAddrFilters;
    uint8  noSduFilters;
    uint8  noVcanFilters;
    Canexcel_Ip_RxFifoFilterID_ADDR * IdFilterPtr;   /* Pointer to the array with ID filter configs */
    Canexcel_Ip_RxFifoFilterID_ADDR * AddrFilterPtr; /* Pointer to the array with Acceptance Address filter configs */
    Canexcel_Ip_RxFifoFilterSDU_CAN * SduFilterPtr;  /* Pointer to the array with Sdu Filter configs */
    Canexcel_Ip_RxFifoFilterSDU_CAN * VcanFilterPtr; /* Pointer to the array with VCAN Filter configs */
} Canexcel_Ip_RxFifoFilter;

/* implements  Canexcel_Ip_BankFilter_structure */
typedef struct{
    uint8  noActAddrFilters;                             /* No Of Address Accept Filters */
    uint8  noSduFilters;                                 /* No of SDU type Filters */
    uint8  noVcanFilters;                                /* No of VCAN Filters */
    const Canexcel_Ip_RxFifoFilterID_ADDR * AddrFilterPtr;     /* Pointer to the array with Acceptance Address filter configs */
    const Canexcel_Ip_RxFifoFilterSDU_CAN * SduFilterPtr;      /* Pointer to the array with Sdu Filter configs */
    const Canexcel_Ip_RxFifoFilterSDU_CAN * VcanFilterPtr;     /* Pointer to the array with VCAN Filter configs */
} Canexcel_Ip_BankFilter;

/* implements  Canexcel_Ip_DataInfoType_structure */
typedef struct{
    Canexcel_Ip_FrameType frame;
    Canexcel_Ip_MsgBuffIdType idType;
    uint8 priority;
    uint8 retransmission;
    boolean enable_brs;                    /**< Enable bit rate switch inside a CAN FD format frame*/
    uint8 fd_padding;                      /**< Set a value for padding. It will be used when the data length code (DLC)
                                                specifies a bigger payload size than data_length to fill the MB */
    uint16 dataLength;                     /**< Length of data in bytes */
    uint8 SDT;
    boolean SEC;
    uint8 VCID;
    uint32 AF;
    boolean is_polling;
} Canexcel_Ip_DataInfoType;

/* implements  Canexcel_TxMsgHeaderType_typedef */
typedef struct
{
    uint32 timeStampL;
    uint32 timeStampH;
    uint32 word2;
    uint32 word3;
    uint32 word4;
} Canexcel_TxMsgHeaderType;

/* implements  Canexcel_TxFdMsgType_typedef */
typedef struct{
    Canexcel_TxMsgHeaderType Header;
    uint8 data[64];
} Canexcel_TxFdMsgType;
/* implements  Canexcel_TxXlMsgType_typedef */
typedef struct{
    Canexcel_TxMsgHeaderType Header;
    uint32 AF;
    uint8 data[2048];
} Canexcel_TxXlMsgType;

/* implements  Canexcel_RxHeader_typedef */
typedef struct{
    uint32 Id;
    uint32 Control;
} Canexcel_RxHeader;
/* implements  Canexcel_RxFdMsg_typedef */
typedef struct{
    Canexcel_RxHeader Header;
    uint8 data[64];
    uint32 timeStampL;
    uint32 timeStampH;
}Canexcel_RxFdMsg;
/* implements  Canexcel_RxXlMsg_typedef */
typedef struct{
    Canexcel_RxHeader Header;
    uint32 AF;
    uint8 data[2048];
    uint32 timeStampL;
    uint32 timeStampH;
}Canexcel_RxXlMsg;

/*! @brief CAN Excel bitrate related structures
 */
/* implements  Canexcel_Ip_TimeSegmentType_structure */
typedef struct
{
    uint32 propSeg;         /**< Propagation segment*/
    uint32 phaseSeg1;       /**< Phase segment 1*/
    uint32 phaseSeg2;       /**< Phase segment 2*/
    uint32 preDivider;      /**< Clock prescaler division factor*/
    uint32 rJumpwidth;      /**< Resync jump width*/
} Canexcel_Ip_TimeSegmentType;

/*! @brief Information needed for internal handling of a given MessageDescriptor. */
/* implements  Canexcel_Ip_MDhandleType_structure */
typedef struct
{
    uint32  list[16];                  /**< The Can Message Buffer Pointer List array */
    boolean isPending[16];             /**< TRUE when the user pushes a pointer to the mb, FALSE when the mb processed in mainfunction/ISR */
    uint8   lastHwIdex;                /**< The No of Message Pointers List sent\received */
    uint8   noPointers;                /**< The No of Message Pointers List sent\received */
    boolean isPolling;                 /**< True if the transfer is Polling Mode  */
    boolean isRemote;                  /**< True if the frame is a remote frame */
    boolean isXLFrame;                 /**< True for XLFrame Types, False for Classic and FD frames. */
} Canexcel_Ip_MDhandleType;

/*!
 * @brief Internal driver state information.
 *
 * @note The contents of this structure are internal to the driver and should not be
 *      modified by users. Also, contents of the structure are subject to change in
 *      future releases.
 */
/* implements   Canexcel_Ip_StateType_structure */
typedef struct CanexcelState
{
   Canexcel_Ip_MDhandleType msgDesc[CANXL_MSG_DESCRIPTORS_MSGDSC_COUNT];
   Canexcel_Ip_MDhandleType rxFifo;
   boolean isIntActive;                                       /**< Save status of enabling/disabling interrupts in runtime. */
   void (*callback)(uint8 instance,
                    Canexcel_Ip_EventType eventType,
                    uint32 buffIdx,
                    const struct CanexcelState *driverState
          );                                         /**< IRQ handler callback function. */
   void * callbackParam;                                      /**< Parameter used to pass user data
                                                                   when invoking the callback
                                                                   function. */
   void (*error_callback)(uint8 instance,
                          Canexcel_Ip_EventType eventType,
                          uint32 u32SysStatus,
                          const struct CanexcelState *driverState
                );                                   /**< Error IRQ handler callback
                                                                   function. */
   void *errorCallbackParam;                                  /**< Parameter used to pass user data
                                                                   when invoking the error callback
                                                                   function. */
   uint8 u8MruMailboxAct;                                     /**< Sets 1 the serviced Mailbox from CanEXCEL MRU */
} Canexcel_Ip_StateType;

/* implements Canexcel_Ip_RxFifoConfig_Type_structure */
typedef struct{
    uint8 Rx_Fifo_Depth;
    uint8 Rx_Fifo_Watermark;
    uint16 Rx_Fifo_Msg_Size;
    boolean Rx_Fifo_KeepLast;
    boolean isPolling;
    Canexcel_Ip_FrameType frameType;
    uint32 * MsgBuffersPtr;
}Canexcel_Ip_RxFifoConfig_Type;


/*! @brief CanExcel Driver callback function type
 */
/* implements Canexcel_Ip_CallbackType_typedef */
typedef void (* Canexcel_Ip_CallbackType)(uint8 instance,
                                         Canexcel_Ip_EventType eventType,
                                         uint32 buffIdx,
                                         const Canexcel_Ip_StateType * canexcelState
                               );

/*! @brief CanExcel Driver error callback function type
 */
/* implements  Canexcel_Ip_ErrorCallbackType_typedef  */
typedef void (* Canexcel_Ip_ErrorCallbackType)(uint8 instance,
                                              Canexcel_Ip_EventType eventType,
                                              uint32 u32SysStatus,
                                              const Canexcel_Ip_StateType * canexcelState
                                    );

#if (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON)
/*! @brief CanEXCEL configuration for TimeStamp
 */
/* implements   Canexcel_Ip_TimeStampConf_Type_typedef */
typedef struct{
    boolean ts64bit;
    Canexcel_Ip_TimeStampCaptureType capture;
    Canexcel_Ip_TimeBaseSelType src;
} Canexcel_Ip_TimeStampConf_Type;
#endif

/*! @brief CanEXCEL configuration
 * @internal gui name="Common configuration" id="canexcelCfg"
 */
/* implements   Canexcel_Ip_ConfigType_structure */
typedef struct{
    uint8 rx_mbdesc;                               /**< No of Rx Descriptor to be used.*/
    uint8 tx_mbdesc;                               /**< No of Tx Descriptor to be used.*/
    Canexcel_Ip_ModesType CanxlMode;               /**< User configurable CanEXCEL operation modes.
                                                   @internal gui name="Canexcel Operation Mode" id="CanxlMode" */
    boolean fd_enable;                             /**< Enable/Disable the Flexible Data Rate feature. */
    boolean bitRateSwitch;                         /**< Enable of BitRate Switch support for FD frames */
    boolean xl_enable;                             /**< Enable/Disable the XL Frame feature. */
    uint32 ctrlOptions;                            /**< Use of different features support like EDGE_FILTER, AUTO_BussOffRecovery, Protocol_Exception. */
    boolean is_rx_fifo_needed;                     /**< 1 if needed; 0 if not. This controls whether the Rx FIFO feature is enabled or not.
                                                         @internal gui name="Use rx fifo" id="is_rx_fifo_needed" */
    Canexcel_Ip_RxFifoConfig_Type pRxFifoConfig;  /**<  The RxFifo configuration */
    Canexcel_Ip_QueueConf QueueMDConfig[CANXL_GRP_CONTROL_FIFOCTRLREQ_COUNT*2]; /**< The configurations for the Message Descriptor Queue Grups */
    Canexcel_Ip_TimeSegmentType bitrate;           /**< The bitrate used for standard frames or for the arbitration phase of FD frames. */
    Canexcel_Ip_TimeSegmentType Fd_bitrate;        /**< The bitrate used for the data phase of FD frames. */
    Canexcel_Ip_TimeSegmentType Xl_bitrate;        /**< The bitrate used for the data phase of XL frames. */
#if (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON)
    Canexcel_Ip_TimeStampConf_Type TimestampConfig;/**< The Timestamp configuration */
#endif
    Canexcel_Ip_CallbackType Callback;             /**< The Callback for Rx or Tx, FIFO Events */
    Canexcel_Ip_ErrorCallbackType ErrorCallback;   /**< The ErrorCallback for Error Events */
} Canexcel_Ip_ConfigType;

#ifdef __cplusplus
}
#endif /* __cplusplus */

/** @} */

#endif /* CANEXCEL_IP_TYPES_H_ */
