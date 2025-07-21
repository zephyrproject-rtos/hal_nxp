/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_HIPERFACE_H_
#define FSL_HIPERFACE_H_

 #include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*! @{ */
/*! @brief HIPERFACE driver version. */
#define FSL_HIPERFACE_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))

#define POS_READY_MODE_SHOWS_TIME_ALL_TRANSMISSIONS      1
#define POS_READY_MODE_SHOWS_TIME_SYNC_TRANSMISSIONS     0
#define SYNC_SIGNAL_POLARITY_TRAILING_EDGE               1
#define SYNC_SIGNAL_POLARITY_LEADING_EDGE                0

#ifndef BSWAP32
#define BSWAP32 __REV
#endif

#ifndef BSWAP16
#define BSWAP16 __REV16
#endif

#ifndef MY_UNUSED
#define MY_UNUSED __attribute__((unused))
#endif

enum
{
    kStatus_DSL_Invalid_ES = MAKE_STATUS(kStatusGroup_HIPERFACE, 0),
    kStatus_DSL_Invalid_SyncFreq = MAKE_STATUS(kStatusGroup_HIPERFACE, 1),
    kStatus_DSL_Fg_Trm_Error = MAKE_STATUS(kStatusGroup_HIPERFACE, 2),
    kStatus_DSL_Fg_Watchdog_Error = MAKE_STATUS(kStatusGroup_HIPERFACE, 3),
    kStatus_DSL_Bg_Proc_Error = MAKE_STATUS(kStatusGroup_HIPERFACE, 4),
    kStatus_DSL_Bg_Err_Exec = MAKE_STATUS(kStatusGroup_HIPERFACE, 5),
    kStatus_DSL_Mem_Not_A_Base_Address = MAKE_STATUS(kStatusGroup_HIPERFACE, 6),
    kStatus_DSL_Mem_Cache_Size_Exceeded = MAKE_STATUS(kStatusGroup_HIPERFACE, 7),
    kStatus_DSL_Mem_Cache_Not_Initialized = MAKE_STATUS(kStatusGroup_HIPERFACE, 8),
    kStatus_DSL_Mem_Cache_Wrong_Base = MAKE_STATUS(kStatusGroup_HIPERFACE, 9),
    kStatus_DSL_Mem_Cache_Out_Of_Size = MAKE_STATUS(kStatusGroup_HIPERFACE, 10),
    kStatus_DSL_Mem_Cache_Wrong_CS = MAKE_STATUS(kStatusGroup_HIPERFACE, 11),
    kStatus_DSL_Lpf_Data_SIze_Exceeded = MAKE_STATUS(kStatusGroup_HIPERFACE, 12),
    kStatus_DSL_Lpf_List_Not_Configurable = MAKE_STATUS(kStatusGroup_HIPERFACE, 13),
    kStatus_DSL_Lpf_List_Already_Configured = MAKE_STATUS(kStatusGroup_HIPERFACE, 14),
    kStatus_DSL_Lpf_Invalid_FID_Location = MAKE_STATUS(kStatusGroup_HIPERFACE, 15),
    kStatus_DSL_Lpf_Invalid_XY = MAKE_STATUS(kStatusGroup_HIPERFACE, 16),
    kStatus_DSL_Lpf_List_Size_Exceeded = MAKE_STATUS(kStatusGroup_HIPERFACE, 17),
    kStatus_DSL_Lmsg_Channel_Busy = MAKE_STATUS(kStatusGroup_HIPERFACE, 18),
    kStatus_DSL_Lmsg_Err_CausedByLmsg = MAKE_STATUS(kStatusGroup_HIPERFACE, 19),
    kStatus_DSL_Lmsg_Erroneous_Answer = MAKE_STATUS(kStatusGroup_HIPERFACE, 20),
};

#define DSL_SetProtocolRst(base)            do {(base)->SYS_CTRL &= ~HIPERFACE_SYS_CTRL_PRST_MASK;    (base)->SYS_CTRL |= HIPERFACE_SYS_CTRL_PRST(1);} while (0)
#define DSL_SetMessagesRst(base)            do {(base)->SYS_CTRL &= ~HIPERFACE_SYS_CTRL_MRST_MASK;    (base)->SYS_CTRL |= HIPERFACE_SYS_CTRL_MRST(1);} while (0)
#define DSL_SetPipelineRst(base)            do {(base)->SYS_CTRL &= ~HIPERFACE_SYS_CTRL_FRST_MASK;    (base)->SYS_CTRL |= HIPERFACE_SYS_CTRL_FRST(1);} while (0)
#define DSL_SetLoopTest(base)               do {(base)->SYS_CTRL &= ~HIPERFACE_SYS_CTRL_LOOP_MASK;    (base)->SYS_CTRL |= HIPERFACE_SYS_CTRL_LOOP(1);} while (0)

#define DSL_ClrProtocolRst(base)            (base)->SYS_CTRL &= ~HIPERFACE_SYS_CTRL_PRST_MASK
#define DSL_ClrMessagesRst(base)            (base)->SYS_CTRL &= ~HIPERFACE_SYS_CTRL_MRST_MASK
#define DSL_ClrPipelineRst(base)            (base)->SYS_CTRL &= ~HIPERFACE_SYS_CTRL_FRST_MASK
#define DSL_ClrLoopTest(base)                (base)->SYS_CTRL &= ~HIPERFACE_SYS_CTRL_LOOP_MASK

#define DSL_SetPosReadyMode(base, v)        do { \
                                                (base)->SYS_CTRL &= ~HIPERFACE_SYS_CTRL_PRDY_MASK; \
                                                (base)->SYS_CTRL |= HIPERFACE_SYS_CTRL_PRDY(v);} while (0)
#define DSL_SetSpiPipeActivate(base, v)     do { \
                                                (base)->SYS_CTRL &= ~HIPERFACE_SYS_CTRL_SPPE_MASK; \
                                                (base)->SYS_CTRL |= HIPERFACE_SYS_CTRL_SPPE(v);} while (0)
#define DSL_SetPolaritySyncPulse(base, v)   do { \
                                                (base)->SYS_CTRL &= ~HIPERFACE_SYS_CTRL_SPOL_MASK;  \
                                                (base)->SYS_CTRL |= HIPERFACE_SYS_CTRL_SPOL(v);} while (0)
#define DSL_SetOutputActivate(base, v)      do { \
                                                (base)->SYS_CTRL &= ~HIPERFACE_SYS_CTRL_OEN_MASK;  \
                                                (base)->SYS_CTRL |= HIPERFACE_SYS_CTRL_OEN(v);} while (0)

#define DSL_GetQualityMonitoringValue(base)     (((base)->MASTER_QM & HIPERFACE_MASTER_QM_QM_MASK) >> HIPERFACE_MASTER_QM_QM_SHIFT)
#define DSL_GetQualityMonitoringLink(base)      ((base)->MASTER_QM & HIPERFACE_MASTER_QM_LINK_MASK)

#define DSL_GetEventInterruptStatus(base)          ((base)->EVENT_H & HIPERFACE_EVENT_H_INT_MASK)
#define DSL_GetEventSlaveEventSum(base)            ((base)->EVENT_H & HIPERFACE_EVENT_H_SUM_MASK)
#define DSL_GetEventeEstimatorOn(base)             ((base)->EVENT_H & HIPERFACE_EVENT_H_POS_MASK)
#define DSL_GetEventEstimatorThresholdErr(base)    ((base)->EVENT_H & HIPERFACE_EVENT_H_DTE_MASK)
#define DSL_GetEventProtocolRstWarning(base)       ((base)->EVENT_H & HIPERFACE_EVENT_H_PRST_MASK)

#define DSl_GetEventMsgInitStatus(base)           ((base)->EVENT_L & HIPERFACE_EVENT_L_MIN_MASK)
#define DSl_GetEventLongMsgAnswerErr(base)        ((base)->EVENT_L & HIPERFACE_EVENT_L_ANS_MASK)
#define DSl_GetEventQMLowValueWarning(base)       ((base)->EVENT_L & HIPERFACE_EVENT_L_QMLW_MASK)
#define DSl_GetEventLongMsgChannelfree(base)      ((base)->EVENT_L & HIPERFACE_EVENT_L_FREL_MASK)

#define DSL_ClrEventSlaveEventSum(base)           (base)->EVENT_H &= ~HIPERFACE_EVENT_H_SUM_MASK
#define DSL_ClrEventeEstimatorOn(base)            (base)->EVENT_H &= ~HIPERFACE_EVENT_H_POS_MASK
#define DSL_ClrEventEstimatorThresholdErr(base)   (base)->EVENT_H &= ~HIPERFACE_EVENT_H_DTE_MASK
#define DSL_ClrEventProtocolRstWarning(base)      (base)->EVENT_H &= ~HIPERFACE_EVENT_H_PRST_MASK

#define DSl_ClrEventMsgInitStatus(base)         (base)->EVENT_L &= ~HIPERFACE_EVENT_L_MIN_MASK
#define DSl_ClrEventLongMsgAnswerErr(base)      (base)->EVENT_L &= ~HIPERFACE_EVENT_L_ANS_MASK
#define DSl_ClrEventQMLowValueWarning(base)     (base)->EVENT_L &= ~HIPERFACE_EVENT_L_QMLW_MASK
#define DSl_ClrEventLongMsgChannelfree(base)    (base)->EVENT_L &= ~HIPERFACE_EVENT_L_FREL_MASK

#define DSL_SetEventMaskMSUM(base, flag, v)        do {(base)->EVENT_MASK_H &= ~HIPERFACE_EVENT_MASK_H_MSUM_MASK;    (base)->EVENT_MASK_H |= HIPERFACE_EVENT_MASK_H_MSUM(v); \
                                                flag &= ~HIPERFACE_EVENT_MASK_H_MSUM_MASK;    flag |= HIPERFACE_EVENT_MASK_H_MSUM(v);} while (0)
#define DSL_SetEventMaskMPOS(base, flag, v)       do {(base)->EVENT_MASK_H &= ~HIPERFACE_EVENT_MASK_H_MPOS_MASK;    (base)->EVENT_MASK_H |= HIPERFACE_EVENT_MASK_H_MPOS(v); \
                                                flag &= ~HIPERFACE_EVENT_MASK_H_MPOS_MASK;     flag |= HIPERFACE_EVENT_MASK_H_MPOS(v);} while (0)
#define DSL_SetEventMaskMDTE(base, flag, v)       do {(base)->EVENT_MASK_H &= ~HIPERFACE_EVENT_MASK_H_MDTE_MASK;    (base)->EVENT_MASK_H |= HIPERFACE_EVENT_MASK_H_MDTE(v); \
                                                flag &= ~HIPERFACE_EVENT_MASK_H_MDTE_MASK;     flag |= HIPERFACE_EVENT_MASK_H_MDTE(v);} while (0)
#define DSL_SetEventMaskMPRST(base, flag, v)      do {(base)->EVENT_MASK_H &= ~HIPERFACE_EVENT_MASK_H_MPRST_MASK;    (base)->EVENT_MASK_H |= HIPERFACE_EVENT_MASK_H_MPRST(v); \
                                                flag &= ~HIPERFACE_EVENT_MASK_H_MPRST_MASK;    flag |= HIPERFACE_EVENT_MASK_H_MPRST(v);} while (0)

#define DSL_SetEventMaskMFREL(base, flag, v)        do {(base)->EVENT_MASK_L &= ~HIPERFACE_EVENT_MASK_L_MFREL_MASK;    (base)->EVENT_MASK_L |= HIPERFACE_EVENT_MASK_L_MFREL(v); \
                                                flag &= ~HIPERFACE_EVENT_MASK_L_MFREL_MASK;    flag |= HIPERFACE_EVENT_MASK_L_MFREL(v);} while (0)
#define DSL_SetEventMaskMQMLW(base, flag, v)         do {(base)->EVENT_MASK_L &= ~HIPERFACE_EVENT_MASK_L_MQMLW_MASK;    (base)->EVENT_MASK_L |= HIPERFACE_EVENT_MASK_L_MQMLW(v); \
                                                flag &= ~HIPERFACE_EVENT_MASK_L_MQMLW_MASK;   flag |= HIPERFACE_EVENT_MASK_L_MQMLW(v);} while (0)
#define DSL_SetEventMaskMANS(base, flag, v)         do {(base)->EVENT_MASK_L &= ~HIPERFACE_EVENT_MASK_L_MANS_MASK;    (base)->EVENT_MASK_L |= HIPERFACE_EVENT_MASK_L_MANS(v); \
                                                flag &= ~HIPERFACE_EVENT_MASK_L_MANS_MASK;    flag |= HIPERFACE_EVENT_MASK_L_MANS(v);} while (0)
#define DSL_SetEventMaskMMIN(base, flag, v)         do {(base)->EVENT_MASK_L &= ~HIPERFACE_EVENT_MASK_L_MMIN_MASK;    (base)->EVENT_MASK_L |= HIPERFACE_EVENT_MASK_L_MMIN(v); \
                                                flag &= ~HIPERFACE_EVENT_MASK_L_MMIN_MASK;    flag |= HIPERFACE_EVENT_MASK_L_MMIN(v);} while (0)

#define DSL_GetEventMaskMSUM(flag)      (flag & HIPERFACE_EVENT_MASK_H_MSUM_MASK)
#define DSL_GetEventMaskMPOS(flag)      (flag & HIPERFACE_EVENT_MASK_H_MPOS_MASK)
#define DSL_GetEventMaskMDTE(flag)      (flag & HIPERFACE_EVENT_MASK_H_MDTE_MASK)
#define DSL_GetEventMaskMPRST(flag)     (flag & HIPERFACE_EVENT_MASK_H_MPRST_MASK)

#define DSL_GetEventMaskMFREL(flag)      (flag & HIPERFACE_EVENT_MASK_L_MFREL_MASK)
#define DSL_GetEventMaskMQMLW(flag)      (flag & HIPERFACE_EVENT_MASK_L_MQMLW_MASK)
#define DSL_GetEventMaskMANS(flag)       (flag & HIPERFACE_EVENT_MASK_L_MANS_MASK)
#define DSL_GetEventMaskMMIN(flag)       (flag & HIPERFACE_EVENT_MASK_L_MMIN_MASK)

#define DSL_SetEventMask_H(base, flag)    (base)->EVENT_MASK_H = (flag)
#define DSL_SetEventMask_L(base, flag)    (base)->EVENT_MASK_L = (flag)
#define DSL_SetMaskSUM(base, flag)        (base)->MASK_SUM = (flag)


#define DSL_GetPrimEdges(base)                (((base)->EDGES_PRIM & HIPERFACE_EDGES_PRIM_EDGES_MASK) >> HIPERFACE_EDGES_PRIM_EDGES_SHIFT)
#define DSL_GetPrimCableDelay(base)           (((base)->DELAY_PRIM & HIPERFACE_DELAY_PRIM_CABLE_DELAY_MASK) >> HIPERFACE_DELAY_PRIM_CABLE_DELAY_SHIFT)
#define DSL_GetPrimSignalStrength(base)       (((base)->DELAY_PRIM & HIPERFACE_DELAY_PRIM_RSSI_MASK) >> HIPERFACE_DELAY_PRIM_RSSI_SHIFT)


#define DSL_GetSafeEdges(base)                (((base)->EDGES_SAFE & HIPERFACE_EDGES_SAFE_EDGES_MASK) >> HIPERFACE_EDGES_SAFE_EDGES_SHIFT)
#define DSL_GetSafeCableDelay(base)           (((base)->DELAY_SAFE & HIPERFACE_DELAY_SAFE_CABLE_DELAY_MASK) >> HIPERFACE_DELAY_SAFE_CABLE_DELAY_SHIFT)
#define DSL_GetSafeSignalStrength(base)       (((base)->DELAY_SAFE & HIPERFACE_DELAY_SAFE_RSSI_MASK) >> HIPERFACE_DELAY_SAFE_RSSI_SHIFT)


#define DSL_IRQ_AllEventDisable(base)         do {base->EVENT_MASK_H = 0;base->EVENT_MASK_L = 0;} while(0)

#define DSL_GetPrimVersionMinorRelease(base)      (((base)->VERSION_PRIM & HIPERFACE_VERSION_PRIM_MINOR_RELEASE_MASK) >> HIPERFACE_VERSION_PRIM_MINOR_RELEASE_SHIFT)
#define DSL_GetPrimVersionMajorRelease(base)      (((base)->VERSION_PRIM & HIPERFACE_VERSION_PRIM_MAJOR_RELEASE_MASK) >> HIPERFACE_VERSION_PRIM_MAJOR_RELEASE_SHIFT)
#define DSL_GetPrimVersionCoding(base)            (((base)->VERSION_PRIM & HIPERFACE_VERSION_PRIM_CODING_MASK) >> HIPERFACE_VERSION_PRIM_CODING_SHIFT)

#define DSL_GetSafeVersionMinorRelease(base)     (((base)->VERSION_SAFE & HIPERFACE_VERSION_SAFE_MINOR_RELEASE_MASK) >> HIPERFACE_VERSION_SAFE_MINOR_RELEASE_SHIFT)
#define DSL_GetSafeVersionMajorRelease(base)     (((base)->VERSION_SAFE & HIPERFACE_VERSION_SAFE_MAJOR_RELEASE_MASK) >> HIPERFACE_VERSION_SAFE_MAJOR_RELEASE_SHIFT)
#define DSL_GetSafeVersionCoding(base)           (((base)->VERSION_PRIM & HIPERFACE_VERSION_SAFE_CODING_MASK) >> HIPERFACE_VERSION_SAFE_CODING_SHIFT)

#define DSL_GetSecVersionMinorRelease(base)     (((base)->VERSION_SEC & HIPERFACE_VERSION_SEC_MINOR_RELEASE_MASK) >> HIPERFACE_VERSION_SEC_MINOR_RELEASE_SHIFT)
#define DSL_GetSecVersionMajorRelease(base)     (((base)->VERSION_SEC & HIPERFACE_VERSION_SEC_MAJOR_RELEASE_MASK) >> HIPERFACE_VERSION_SEC_MAJOR_RELEASE_SHIFT)
#define DSL_GetSecVersionCoding(base)           (((base)->VERSION_SEC & HIPERFACE_VERSION_SEC_CODING_MASK) >> HIPERFACE_VERSION_SEC_CODING_SHIFT)

#define DSL_GetPrimEncoderID(base)             (((base)->ENC_ID2_PRIM << 16) | ((base)->ENC_ID1_PRIM << 8) |((base)->ENC_ID0_PRIM))
#define DSL_GetSafeEncoderID(base)             (((base)->ENC_ID2_SAFE << 16) | ((base)->ENC_ID1_SAFE << 8) |((base)->ENC_ID0_SAFE))

#define DSL_GetAccValueLen(encoderID)      (((encoderID) & 0xF) + 8)
#define DSL_GetPosValueLen(encoderID)      ((((encoderID) >> 4) & 0x3F) + DSL_GetAccValueLen(encoderID))
#define DSL_GetPosSign(encoderID)          (((encoderID) >> 10) & 0x01)
#define DSL_GetSignMask(encoderID)         (0x01 << (DSL_GetPosValueLen(encoderID) - 1))
#define DSL_GetSignExtend(encoderID)       (~((0x01 << DSL_GetPosValueLen(encoderID)) - 1))

#define DSL_SetLmsgRead(var)                 (var) |= HIPERFACE_PC_ADD_H_LRW_MASK
#define DSL_SetLmsgWrite(var)                (var) &= ~HIPERFACE_PC_ADD_H_LRW_MASK

#define DSL_SetLmsgAddrWithOffset(var)       (var) |= HIPERFACE_PC_ADD_H_LOFF_MASK
#define DSL_SetLmsgAddrWithoutOffset(var)    (var) &= ~HIPERFACE_PC_ADD_H_LOFF_MASK

#define DSL_GetLmsgLastCauseError(base)      (((base)->PC_ADD_H & HIPERFACE_PC_ADD_H_LOFF_MASK))
#define DSL_GetLmsgLastStatus(base)          (((base)->PC_ADD_H & HIPERFACE_PC_ADD_H_LOFF_MASK))

#define DSL_SetLmsgAddrIndirect(var)         (var) |= HIPERFACE_PC_ADD_H_LIND_MASK
#define DSL_SetLmsgAddrDirect(var)           (var) &= ~HIPERFACE_PC_ADD_H_LIND_MASK

#define DSL_SetLmsgDataLen(var, len)         do { \
                                                (var) &= ~HIPERFACE_PC_ADD_H_LLEN_MASK; \
                                                (var) |= HIPERFACE_PC_ADD_H_LLEN(len);} while(0)

#define DSL_SetLmsgAddrOffset(base, offset)  do { \
                                                (base)->PC_OFF_H = HIPERFACE_PC_OFF_H_LID_MASK | \
                                                                   (((offset) >> 8) & HIPERFACE_PC_OFF_H_LOFFADD_MASK); \
                                                (base)->PC_OFF_L = (offset) & HIPERFACE_PC_OFF_L_LOFFADD_MASK;} while(0)

#define DSL_SetLmsgBuf(base, src, num)        memcpy((void *)((base)->PRIM), src, num)
#define DSL_GetLmsgBuf(base, des, num)        memcpy(des, (void *)((base)->PRIM), num)

#define DSL_SetLmsgAddr(base, var, addr)     do { \
                                                var |=  (addr >> 8) & HIPERFACE_PC_ADD_H_LADD_MASK; \
                                                (base)->PC_ADD_H = var; \
                                                (base)->PC_ADD_L = HIPERFACE_PC_ADD_L_LADD(addr);} while(0)

#define DSL_SetLmsgStart(base)                 (base)->PC_CTRL |= HIPERFACE_PC_CTRL_LSTA_MASK

#define LMSG_F_DIRECT           0x01
#define LMSG_F_OFFSET           0x02
#define LMSG_F_WRITE            0x04
#define LMSG_F_INDIRECT         0x08
#define LMSG_F_NO_OFFSET        0x10
#define LMSG_F_READ             0x12

#define DSL_RDB_AccessErr_ResourceIdentifierNotImplemented         0x04010
#define DSL_RDB_AccessErr_IncorrectLength                          0x04011
#define DSL_RDB_AccessErr_OffsetValueTooHigh                       0x04013
#define DSL_RDB_AccessErr_InvalidOffsetValue                       0x04014
#define DSL_RDB_AccessErr_InvalidData                              0x04015
#define DSL_RDB_AccessErr_WriteAccessNotPossible                   0x04110
#define DSL_RDB_AccessErr_ReadAccessNotPossible                    0x04111
#define DSL_RDB_AccessErr_WriteAccessDenied                        0x04112
#define DSL_RDB_AccessErr_ReadAccessDenied                         0x04113
#define DSL_RDB_AccessErr_DirectWriteAccessDenied                  0x04114
#define DSL_RDB_AccessErr_ResourceDatabasenodeCorrupt              0x04210
#define DSL_RDB_AccessErr_InternalProcessingError                  0x04211
#define DSL_RDB_AccessErr_FileNameNotFound                         0x04311
#define DSL_RDB_AccessErr_InvalidAddressForFileAccess              0x04312
#define DSL_RDB_AccessErr_FileNotDeletable                         0x04313
#define DSL_RDB_AccessErr_FileMemoryFull                           0x04314
#define DSL_RDB_AccessErr_FileAllocationTableCorrupt               0x04315
#define DSL_RDB_AccessErr_NoFileLoadedForAction                    0x04316
#define DSL_RDB_AccessErr_FileWithSameNameExists                   0x04317

/* RID definition for Nodes*/
#define DSL_RID_RootNode                  0x000
#define DSL_RID_IdentificationNode        0x001
#define DSL_RID_MonitoringNode            0x002
#define DSL_RID_AdministrationNode        0x003
#define DSL_RID_CounterNode               0x004
#define DSL_RID_DataStorageNode           0x005
#define DSL_RID_SensorHubNode             0x006

/* RID definition for Identification resources */
#define DSL_RID_TypeOfEncoder           0x080
#define DSL_RID_Resolution              0x081
#define DSL_RID_MeasurementRange        0x082
#define DSL_RID_TypeName                0x083
#define DSL_RID_SerialNumber            0x084
#define DSL_RID_baseiceVersion          0x085
#define DSL_RID_FirmwareDate            0x086
#define DSL_RID_EEPROMSize              0x087
#define DSL_RID_SafeChannel2Resolution  0x089
#define DSL_RID_SensorPeriods           0x08A

/* RID definition for Monitoring resources */
#define DSL_RID_TemperatureRange        0x0C0
#define DSL_RID_Temperature             0x0C1
#define DSL_RID_SensorMonitorRange      0x0C2
#define DSL_RID_SensorMonitor           0x0C3
#define DSL_RID_SupplyVoltageRange      0x0C4
#define DSL_RID_SupplyVoltage           0x0C5
#define DSL_RID_RotationSpeedRange      0x0C6
#define DSL_RID_RotationSpeed           0x0C7
#define DSL_RID_AccelerationRange       0x0C8
#define DSL_RID_Lifetime                0x0CB
#define DSL_RID_ErrorLog                0x0CC
#define DSL_RID_UsageHistogram          0x0CD
#define DSL_RID_ErrorLogFilter          0x0D5
#define DSL_RID_CodeDiskPositionRange   0x0D3
#define DSL_RID_CodeDiskPosition        0x0D4

/* RID definition for Administration resources */
#define DSL_RID_ResetShutdown            0x100
#define DSL_RID_SetPosition              0x101
#define DSL_RID_SetAccesslevel           0x104
#define DSL_RID_ChangeAccessKey          0x105
#define DSL_RID_UserDefinedWarnings      0x107
#define DSL_RID_FactorySettings          0x108
#define DSL_RID_UserDefinedEncoderIndex  0x109
#define DSL_RID_PositionFilterSetting    0x10A
#define DSL_RID_UserDefinedEncoderIndexAndIncorporationFunction  0x111
#define DSL_RID_Bootloader                0x11F

/* RID definition for Counter resources */
#define DSL_RID_ReadCounter             0x120
#define DSL_RID_IncrementCounter        0x121
#define DSL_RID_ResetCounter            0x122

/* RID definition for Data storage resources */
#define DSL_RID_LoadFile                0x130
#define DSL_RID_ReadWriteFile           0x131
#define DSL_RID_FileStatus              0x132
#define DSL_RID_CreateDeleteChangeFile  0x133
#define DSL_RID_Directory               0x134

/* RID definition for SensorHub resources*/
#define DSL_RID_AccessSimpleIOs          0x200
#define DSL_RID_ManageAimpleIOs          0x201
#define DSL_RID_IdentifySimpleIOs        0x202

#define _DSL_RDB_GetResourceName(base, rid, buf, error)         DSL_RDB_Read(base, rid, 0, buf, 8, LMSG_F_OFFSET | LMSG_F_READ  | LMSG_F_DIRECT, 1000, error)
#define _DSL_RDB_GetDataSize(base, rid, v16, error)             DSL_RDB_Read(base, rid, 1, v16, 2, LMSG_F_OFFSET | LMSG_F_READ  | LMSG_F_DIRECT, 1000, error)
#define _DSL_RDB_GetReadAccessLevel(base, rid, v16, error)      DSL_RDB_Read(base, rid, 2, v16, 2, LMSG_F_OFFSET | LMSG_F_READ  | LMSG_F_DIRECT, 1000, error)
#define _DSL_RDB_GetWriteAccessLevel(base, rid, v16, error)     DSL_RDB_Read(base, rid, 3, v16, 2, LMSG_F_OFFSET | LMSG_F_READ  | LMSG_F_DIRECT, 1000, error)
#define _DSL_RDB_GetTimeOverrun(base, rid, v16, error)          DSL_RDB_Read(base, rid, 4, v16, 2, LMSG_F_OFFSET | LMSG_F_READ  | LMSG_F_DIRECT, 1000, error)
#define _DSL_RDB_GetDataType(base, rid, v16, error)             DSL_RDB_Read(base, rid, 5, v16, 2, LMSG_F_OFFSET | LMSG_F_READ  | LMSG_F_DIRECT, 1000, error)

#define _DSL_RDB_GetNodeLinkedNum(base, root_rid, v8, timeout)  DSL_RDB_Read(base, rid, 0, v8, 1, LMSG_F_OFFSET | LMSG_F_READ | LMSG_F_INDIRECT, timeout, NULL)
#define _DSL_RDB_GetNodeLinkedRID(base, root_rid, rid, index, timeout)   DSL_RDB_Read(base, root_rid, index + 1, rid, 2, LMSG_F_OFFSET | LMSG_F_READ | LMSG_F_INDIRECT, timeout, NULL)

#define _DSL_RDB_GetLinkedNodeNum(base, rid, v16, errno)                 DSL_RDB_Read(base, rid, 0, v16, 2, LMSG_F_OFFSET | LMSG_F_READ | LMSG_F_INDIRECT, (node)->timeOverrun, errno)
#define _DSL_RDB_GetLinkedNodeRID(base, node, index, rid, errno)          DSL_RDB_Read(base, (node)->rid, (index)+1, rid, 2, LMSG_F_OFFSET | LMSG_F_READ | LMSG_F_INDIRECT, (node)->timeOverrun, errno)

#define RDB_DATA_TYPE_NODE_INDICATOR     0x00
#define RDB_DATA_TYPE_NO_DATA            0x01
#define RDB_DATA_TYPE_BIT                0x02
#define RDB_DATA_TYPE_UINT8              0x03
#define RDB_DATA_TYPE_UINT16             0x04
#define RDB_DATA_TYPE_UINT32             0x05
#define RDB_DATA_TYPE_UINT64             0x06
#define RDB_DATA_TYPE_INT8               0x07
#define RDB_DATA_TYPE_INT16              0x08
#define RDB_DATA_TYPE_INT32              0x09
#define RDB_DATA_TYPE_INT64              0x0A
#define RDB_DATA_TYPE_STRING             0x0B
#define RDB_DATA_TYPE_STRUCT_BASE        0x10
#define RDB_DATA_TYPE_STRUCT_END         0x4F

#define RDB_ACCESS_LEVEL_ALL                    0x0
#define RDB_ACCESS_LEVEL_OPERATOR               0x1
#define RDB_ACCESS_LEVEL_MAINTENANCE            0x2
#define RDB_ACCESS_LEVEL_AUTHORIZED             0x3
#define RDB_ACCESS_LEVEL_USER_SERVICE           0x4
#define RDB_ACCESS_LEVEL_MANUFACTURER_SERVICE   0x5
#define RDB_ACCESS_LEVEL_NO_POSSIBLE            0xF

#define HISTOGRAMS_ENCODER_PARAMETERS_TEMPERATURE               0x0
#define HISTOGRAMS_ENCODER_PARAMETERS_SENSOR_MONITOR            0x1
#define HISTOGRAMS_ENCODER_PARAMETERS_SUPPLY_VOLTAGE            0x2
#define HISTOGRAMS_ENCODER_PARAMETERS_ROTATION_SPEED            0x3
#define HISTOGRAMS_ENCODER_PARAMETERS_CODE_DISK_POSITION        0x4

#define HISTOGRAM_CLASS_TEMPERATURE_LESS_N40         0x00
#define HISTOGRAM_CLASS_TEMPERATURE_N40_N30          0x01
#define HISTOGRAM_CLASS_TEMPERATURE_N30_N20          0x02
#define HISTOGRAM_CLASS_TEMPERATURE_N20_N10          0x03
#define HISTOGRAM_CLASS_TEMPERATURE_N10_00           0x04
#define HISTOGRAM_CLASS_TEMPERATURE_00_10            0x05
#define HISTOGRAM_CLASS_TEMPERATURE_10_20            0x06
#define HISTOGRAM_CLASS_TEMPERATURE_20_30            0x07
#define HISTOGRAM_CLASS_TEMPERATURE_30_40            0x08
#define HISTOGRAM_CLASS_TEMPERATURE_40_50            0x09
#define HISTOGRAM_CLASS_TEMPERATURE_50_60            0x0A
#define HISTOGRAM_CLASS_TEMPERATURE_60_70            0x0B
#define HISTOGRAM_CLASS_TEMPERATURE_70_80            0x0C
#define HISTOGRAM_CLASS_TEMPERATURE_80_90            0x0D
#define HISTOGRAM_CLASS_TEMPERATURE_90_100           0x0E
#define HISTOGRAM_CLASS_TEMPERATURE_100_110          0x0F
#define HISTOGRAM_CLASS_TEMPERATURE_110_120          0x10
#define HISTOGRAM_CLASS_TEMPERATURE_GREATER_120      0x11

#define HISTOGRAM_CLASS_SUPPLY_VOLTAGE_LESS_6V      0x00
#define HISTOGRAM_CLASS_SUPPLY_VOLTAGE_6V_7V        0x01
#define HISTOGRAM_CLASS_SUPPLY_VOLTAGE_7V_8V        0x02
#define HISTOGRAM_CLASS_SUPPLY_VOLTAGE_8V_9V        0x03
#define HISTOGRAM_CLASS_SUPPLY_VOLTAGE_9V_10V       0x04
#define HISTOGRAM_CLASS_SUPPLY_VOLTAGE_10V_11V      0x05
#define HISTOGRAM_CLASS_SUPPLY_VOLTAGE_11V_12V      0x06
#define HISTOGRAM_CLASS_SUPPLY_VOLTAGE_12V_13V      0x07
#define HISTOGRAM_CLASS_SUPPLY_VOLTAGE_13V_14V      0x08
#define HISTOGRAM_CLASS_SUPPLY_VOLTAGE_GREATER_14   0x09

#define HISTOGRAM_CLASS_ROTATION_SPEED_0_500            0x00
#define HISTOGRAM_CLASS_ROTATION_SPEED_500_1000         0x01
#define HISTOGRAM_CLASS_ROTATION_SPEED_1000_1500        0x02
#define HISTOGRAM_CLASS_ROTATION_SPEED_1500_2000        0x03
#define HISTOGRAM_CLASS_ROTATION_SPEED_2000_2500        0x04
#define HISTOGRAM_CLASS_ROTATION_SPEED_2500_3000        0x05
#define HISTOGRAM_CLASS_ROTATION_SPEED_3000_3500        0x06
#define HISTOGRAM_CLASS_ROTATION_SPEED_3500_4000        0x07
#define HISTOGRAM_CLASS_ROTATION_SPEED_4000_4500        0x08
#define HISTOGRAM_CLASS_ROTATION_SPEED_4500_5000        0x09
#define HISTOGRAM_CLASS_ROTATION_SPEED_5000_5500        0x0A
#define HISTOGRAM_CLASS_ROTATION_SPEED_5500_6000        0x0B
#define HISTOGRAM_CLASS_ROTATION_SPEED_6000_6500        0x0C
#define HISTOGRAM_CLASS_ROTATION_SPEED_6500_7000        0x0D
#define HISTOGRAM_CLASS_ROTATION_SPEED_7000_7500        0x0E
#define HISTOGRAM_CLASS_ROTATION_SPEED_7500_8000        0x0F
#define HISTOGRAM_CLASS_ROTATION_SPEED_8000_8500        0x10
#define HISTOGRAM_CLASS_ROTATION_SPEED_8500_9000        0x11
#define HISTOGRAM_CLASS_ROTATION_SPEED_9000_9500        0x12
#define HISTOGRAM_CLASS_ROTATION_SPEED_9500_10000       0x13
#define HISTOGRAM_CLASS_ROTATION_SPEED_GREATER_10000    0x14

#define ERROR_LOG_FILTER_ON    1
#define ERROR_LOG_FILTER_OFF   0

#define RDB_DEFAULT_PASSWORD_OPERATOR                   0x31313131
#define RDB_DEFAULT_PASSWORD_MAINTENANCE                0x31313131
#define RDB_DEFAULT_PASSWORD_AUTHORIZED                 0x31313131
#define RDB_DEFAULT_PASSWORD_USER_SERVICE               0x31313131
#define RDB_DEFAULT_PASSWORD_MANUFACTURER_SERVICE       0x31313131

#define RDB_USER_DEFINED_WARNING_TYPE_SWITCHED_OFF         0x00 // Warning switched off
#define RDB_USER_DEFINED_WARNING_TYPE_BELOW_THRESHOLD      0x01 // Warning if monitored resource below threshold
#define RDB_USER_DEFINED_WARNING_TYPE_ABOVE_THRESHOLD      0x02 // Warning if monitored resource above threshold
#define RDB_USER_DEFINED_WARNING_TYPE_BIT_DELETED          0x03 // Warning if monitored resource bit is deleted
#define RDB_USER_DEFINED_WARNING_TYPE_BIT_SET              0x04 // Warning if monitored resource bit is set

#define RDB_USER_DEFINED_WARNING_THRESHOLD_DATA_FORMAT_U16     0x01 // 16 bit, unsigned
#define RDB_USER_DEFINED_WARNING_THRESHOLD_DATA_FORMAT_U32     0x02 // 32 bit, unsigned
#define RDB_USER_DEFINED_WARNING_THRESHOLD_DATA_FORMAT_U64     0x03 // 64 bit, unsigned
#define RDB_USER_DEFINED_WARNING_THRESHOLD_DATA_FORMAT_S16     0x05 // 16 bit, with sign
#define RDB_USER_DEFINED_WARNING_THRESHOLD_DATA_FORMAT_S32     0x06 // 32 bit, with sign
#define RDB_USER_DEFINED_WARNING_THRESHOLD_DATA_FORMAT_S64     0x07 // 64 bit, with sign

#define RDB_FACTORY_SETTINGS_RESET_USER_FILE_SYSTEM   0x00  // Code word to reset user file system only
#define RDB_FACTORY_SETTINGS_RESET_ALL                0x01  // Code word to revert to factory settings

typedef struct _hiperface_config
{
    uint8_t pos_ready_mode;
    uint8_t sync_signal_Polarity;
    uint8_t es;
    uint32_t syncFreqHz;
} hiperface_config_t;

typedef struct _dsl_encoder_version_info
{
    uint8_t coding;
    uint8_t majorNumber;
    uint8_t minorNumber;
    uint32_t year;
    uint8_t month;
    uint8_t day;
} dsl_encoder_version_info_t;

typedef struct _user_defined_warning
{
    uint8_t warningIndex;
    uint16_t monitiedRID;
    uint16_t monitiedOffset;
    uint8_t warningType;
    uint8_t format;
    uint8_t value[8];
} user_defined_warning_t;

typedef struct _dsl_rdb_node
{
    uint16_t rid;
    uint8_t resourceName[9];
    uint16_t resourceDataLen;
    uint16_t readAccessLevel;
    uint16_t writeAccessLevel;
    uint16_t timeOverrun;
    uint16_t dataType;
    uint16_t childrenNum;
    struct _dsl_rdb_node *nodes;
} dsl_rdb_node_t;

typedef struct _dsl_encoder
{
    HIPERFACE_Type *base;
    uint8_t sign;
    uint64_t signMask;
    uint64_t signExtend;
    uint8_t accValueLen;
    uint8_t posValueLen;
    uint32_t encoderID;
    dsl_rdb_node_t rootNode;
} dsl_encoder_t;

typedef struct _dsl_rdb_error_protocol
{
    uint32_t timeStamp;             // Error time information (operating time or real-time stamp)
    uint16_t temperature;           // Temperature in 0.1 °C during the error
    uint16_t technologySpecific;    // Technology specific (optical, capacitive)
    uint16_t internalSupplyVoltage; // Internal supply voltage in mV during the error
    uint16_t rotationSpeed;         // Rotation speed in min-1 during the error
    uint16_t reserved;
    uint16_t additionalErrorConde;    // Additional error code
    uint16_t errorConde;            // Error code
} dsl_rdb_error_protocol_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

void DSL_GetDefaultConfig(hiperface_config_t *config);
void DSL_MasterInit(HIPERFACE_Type *base, hiperface_config_t *config);
int DSL_SyncModeEnable(HIPERFACE_Type *base, uint32_t syncFreqHz, hiperface_config_t *config);
void DSL_GetMasterReleaseInfo(HIPERFACE_Type *base, dsl_encoder_version_info_t *info);
void DSL_EncoderInit(HIPERFACE_Type *base, dsl_encoder_t *enc);
status_t DSL_CheckLinkStatus(HIPERFACE_Type *base, uint32_t timeout_ms);
uint64_t DSL_GetFastPosition(HIPERFACE_Type *base, dsl_encoder_t *enc);
uint32_t DSL_GetSpeed(HIPERFACE_Type *base);
char *DSL_RDB_AccessErr2str(uint16_t errno);
status_t DSL_RDB_Wrire(HIPERFACE_Type *base, uint16_t addr, uint16_t offset, void *data,
                                uint32_t datLen, uint32_t flag, uint32_t timeout_ms, uint16_t *errno);
status_t DSL_RDB_Read(HIPERFACE_Type *base, uint16_t addr, uint16_t offset, void *data,
                            uint32_t datLen, uint32_t flag, uint32_t timeout_ms, uint16_t *errno);
status_t DSL_RDB_GetResourceName(HIPERFACE_Type *base, dsl_rdb_node_t *node, uint16_t rid);
status_t DSL_RDB_GetDataSize(HIPERFACE_Type *base, dsl_rdb_node_t *node, uint16_t rid);
status_t DSL_RDB_GetReadAccessLevel(HIPERFACE_Type *base, dsl_rdb_node_t *node, uint16_t rid);
status_t DSL_RDB_GetWriteAccessLevel(HIPERFACE_Type *base, dsl_rdb_node_t *node, uint16_t rid);
status_t DSL_RDB_GetTimeOverrun(HIPERFACE_Type *base, dsl_rdb_node_t *node, uint16_t rid);
status_t DSL_RDB_GetDataType(HIPERFACE_Type *base, dsl_rdb_node_t *node, uint16_t rid);
status_t DSL_RDB_ReadIndirectWithOffset(HIPERFACE_Type *base, dsl_rdb_node_t *node, void *data, uint32_t datLen, uint16_t offset);
status_t DSL_RDB_ReadIndirect(HIPERFACE_Type *base, dsl_rdb_node_t *node, void *data, uint32_t datLen);
status_t DSL_RDB_ReadIndirectMultiple(HIPERFACE_Type *base, dsl_rdb_node_t *node, void *data, uint32_t datLen);
status_t DSL_RDB_WriteIndirectWithOffset(HIPERFACE_Type *base, dsl_rdb_node_t *node, void *data, uint32_t datLen, uint16_t offset);
status_t DSL_RDB_WriteIndirect(HIPERFACE_Type *base, dsl_rdb_node_t *node, void *data, uint32_t datLen);
status_t DSL_RDB_WriteIndirectMultiple(HIPERFACE_Type *base, dsl_rdb_node_t *node, void *data, uint32_t datLen);
status_t DSL_RDB_GetNodeDefiningValue(HIPERFACE_Type *base, dsl_rdb_node_t *node, uint16_t rid);
status_t DSL_RDB_GetNodeLinkedNum(HIPERFACE_Type *base, dsl_rdb_node_t *node);
status_t DSL_RDB_GetNodeLinkedRID(HIPERFACE_Type *base, dsl_rdb_node_t *node, uint8_t index, uint16_t *rid);
status_t DSL_RDB_TraverseNodeDefiningValue(HIPERFACE_Type *base, dsl_rdb_node_t *root, uint16_t rid);
void DSL_RDB_FreeNodeDefiningValue(HIPERFACE_Type *base, dsl_rdb_node_t *root);
status_t DSL_RDB_ReadAllNodeDefiningValue(HIPERFACE_Type *base, dsl_encoder_t *enc);
void DSL_RDB_FreeAllNodeDefiningValue(HIPERFACE_Type *base, dsl_encoder_t *enc);
dsl_rdb_node_t *DSL_RDB_FindNodeFromCache(dsl_rdb_node_t *root, uint16_t rid);
char *DSL_RDB_AccessLevelToStr(uint16_t level);
char *DSL_RDB_DataTypeToStr(uint16_t type);
char *DSL_RDB_TypeOfEncoderTostr(uint16_t type);
status_t DSL_RDB_GetTypeOfEncoder(HIPERFACE_Type *base, uint16_t *type);
status_t DSL_RDB_GetResolution(HIPERFACE_Type *base, uint32_t *resolution);
status_t DSL_RDB_GetMeasurementRange(HIPERFACE_Type *base, uint32_t *range);
status_t DSL_RDB_GetTypeNameOfEncoder(HIPERFACE_Type *base, uint8_t *name, uint32_t len);
status_t DSL_RDB_GetSerialNumber(HIPERFACE_Type *base, uint8_t *serialNumber, uint32_t len);
status_t DSL_RDB_GetBaseiceVersion(HIPERFACE_Type *base, uint8_t *firmware_version, uint32_t len0, uint8_t *hardware_version, uint32_t len1);
status_t DSL_RDB_GetFirmwareDate(HIPERFACE_Type *base, uint8_t *date, uint32_t len);
status_t DSL_RDB_GetEEPROMSize(HIPERFACE_Type *base, uint16_t *size);
status_t DSL_RDB_GetSafeChannel2Resolution(HIPERFACE_Type *base, uint32_t *resolution);
status_t DSL_RDB_GetSensorPeriods(HIPERFACE_Type *base, uint16_t *sysPeriods, uint32_t *sysResolution);
status_t DSL_RDB_GetTemperatureRange(HIPERFACE_Type *base, float *maximum, float *minimum);
status_t DSL_RDB_GetTemperature(HIPERFACE_Type *base, float *temperature);
status_t DSL_RDB_GetSupplyVoltageRange(HIPERFACE_Type *base, uint16_t *maximum, uint16_t *minimum);
status_t DSL_RDB_GetSupplyVoltage(HIPERFACE_Type *base, uint16_t *voltage);
status_t DSL_RDB_GetRotationSpeedRange(HIPERFACE_Type *base, uint16_t *range);
status_t DSL_RDB_GetRotationSpeed(HIPERFACE_Type *base, uint16_t *speed);
status_t DSL_RDB_GetAccelerationRange(HIPERFACE_Type *base, uint16_t *range);
status_t DSL_RDB_GetLifetime(HIPERFACE_Type *base, uint32_t *operatingTime, uint32_t *shaftRotationsNum);
status_t DSL_RDB_GetLifetimeRemaining(HIPERFACE_Type *base, uint32_t *RemainingTaskLifetime);
status_t DSL_RDB_GetErrorLogNumber(HIPERFACE_Type *base, uint32_t *num);
status_t DSL_RDB_GetErrorLog(HIPERFACE_Type *base, uint32_t index, dsl_rdb_error_protocol_t *errlog);
status_t DSL_RDB_GetUsageHistogram(HIPERFACE_Type *base, uint8_t encoder_parameter, uint8_t histogram_class, uint32_t *value);
status_t DSL_RDB_GetErrorLogFilter(HIPERFACE_Type *base, uint8_t *status);
status_t DSL_RDB_SetErrorLogFilter(HIPERFACE_Type *base, uint8_t status);
status_t DSL_RDB_SetReset(HIPERFACE_Type *base);
status_t DSL_RDB_SetShutDown(HIPERFACE_Type *base);
status_t DSL_RDB_GetSetPosition(HIPERFACE_Type *base, uint64_t *pos);
status_t DSL_RDB_SetSetPosition(HIPERFACE_Type *base, uint64_t pos);
status_t DSL_RDB_GetCurrentAccessLevel(HIPERFACE_Type *base, uint8_t *accessLevel);
status_t DSL_RDB_SetAccessLevel(HIPERFACE_Type *base, uint8_t accessLevel, uint32_t password);
status_t DSL_RDB_ChangeAccessKey(HIPERFACE_Type *base, uint8_t accessLevel, uint32_t newPassword, uint32_t oldPassword);
status_t DSL_RDB_GetUserDefinedWarnings(HIPERFACE_Type *base, uint8_t warningIndex, user_defined_warning_t *warning);
status_t DSL_RDB_SetUserDefinedWarnings(HIPERFACE_Type *base, user_defined_warning_t *warning);
status_t DSL_RDB_SetFactorySettings(HIPERFACE_Type *base, uint8_t reset_mode);
status_t DSL_RDB_GetUserDefinedEncoderIndexRID109(HIPERFACE_Type *base, uint8_t *index);
status_t DSL_RDB_SetUserDefinedEncoderIndexRID109(HIPERFACE_Type *base, uint8_t index);
status_t DSL_RDB_SetPositionFilterSetting(HIPERFACE_Type *base, uint32_t positionFilter);
status_t DSL_RDB_GetPositionFilterSetting(HIPERFACE_Type *base, uint32_t *positionFilter);
status_t DSL_RDB_GetUserDefinedEncoderIndexRID111(HIPERFACE_Type *base, uint8_t *index);
status_t DSL_RDB_SetUserDefinedEncoderIndexRID111(HIPERFACE_Type *base, uint8_t index);
status_t DSL_RDB_GetEncoderIndexIncorporationfunction(HIPERFACE_Type *base, uint8_t *isEnabled);
status_t DSL_RDB_SetEncoderIndexIncorporationfunction(HIPERFACE_Type *base, uint8_t isEnabled);
status_t DSL_RDB_GetReadCounter(HIPERFACE_Type *base, uint32_t *counter);
status_t DSL_RDB_SetIncrementCounter(HIPERFACE_Type *base);
status_t DSL_RDB_SetResetcounter(HIPERFACE_Type *base);
status_t DSL_RDB_LoadFile(HIPERFACE_Type *base, char *fileName, uint8_t isVerified);
status_t DSL_RDB_ReadFile(HIPERFACE_Type *base, uint8_t *buf, int16_t len, uint16_t offset);
status_t DSL_RDB_WriteFile(HIPERFACE_Type *base, uint8_t *buf, int16_t len, uint16_t offset);
status_t DSL_RDB_GetFileStatus(HIPERFACE_Type *base, uint8_t *ReadAccessRight, uint8_t *writeAccessRight, uint16_t *fileSize);
status_t DSL_RDB_CreateFile(HIPERFACE_Type *base, char *fileName, uint8_t ReadAccessRight, uint8_t writeAccessRight);
status_t DSL_RDB_ChangeFile(HIPERFACE_Type *base, char *fileName, uint8_t ReadAccessRight, uint8_t writeAccessRight);
status_t DSL_RDB_DeleteFile(HIPERFACE_Type *base);
status_t DSL_RDB_GetDirectoryBasicData(HIPERFACE_Type *base, uint8_t *userFilesNumber, uint16_t *filledBytesNumber, uint16_t *emptyBytesNumber);
status_t DSL_RDB_GetDirectoryFileNmae(HIPERFACE_Type *base, char *fileName, uint32_t len, uint8_t index);
status_t DSL_RDB_DigitalOutputWithNumber(HIPERFACE_Type *base, uint8_t IO_index, uint8_t value);
status_t DSL_RDB_DigitalInputWithNumber(HIPERFACE_Type *base, uint8_t IO_index, uint8_t *value);
uint8_t ENC_ST_register_reading(HIPERFACE_Type *base, uint8_t offset);
void Slave_Mail_register_writing(HIPERFACE_Type *base, uint8_t value);
void Slave_Ping_register_writing(HIPERFACE_Type *base, uint8_t value);
uint8_t Slave_Ping_register_reading(HIPERFACE_Type *base);
uint8_t Slave_SRSSI_register_reading(HIPERFACE_Type *base);
uint8_t DSL_getMaxES(uint32_t syncFreqHz);
void DSL_GetFastPositionAndSpeed(HIPERFACE_Type *base, uint64_t *position, int32_t *speed);
#if defined(__cplusplus)
}
#endif /* __cplusplus */

/* @} */

#endif
