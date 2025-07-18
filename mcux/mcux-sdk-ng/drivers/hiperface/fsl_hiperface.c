/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_hiperface.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
__WEAK uint32_t getTimestampMS()
{
	return 0;
}

void DSL_GetDefaultConfig(hiperface_config_t *config)
{
	config->pos_ready_mode = POS_READY_MODE_SHOWS_TIME_ALL_TRANSMISSIONS;
	config->sync_signal_Polarity = SYNC_SIGNAL_POLARITY_LEADING_EDGE;
	config->es = 0;
};

void DSL_MasterInit(HIPERFACE_Type *base, hiperface_config_t *config)
{
	DSL_SetProtocolRst(base);
	DSL_SetMessagesRst(base);
	DSL_SetPipelineRst(base);

	DSL_ClrProtocolRst(base);
	DSL_ClrMessagesRst(base);
	DSL_ClrPipelineRst(base);

	DSL_SetPolaritySyncPulse(base, config->sync_signal_Polarity);
	DSL_SetPosReadyMode(base, config->pos_ready_mode);
	DSL_SetOutputActivate(base, 0x01);
}

uint8_t DSL_getMaxES(uint32_t syncFreqHz)
{
	uint32_t maximum = (uint32_t) (1000000 / (syncFreqHz * 11.95));
	return maximum > 0xFF ? 0xFF : (maximum & 0xFF);
}

int DSL_SyncModeEnable(HIPERFACE_Type *base, uint32_t syncFreqHz, hiperface_config_t *config)
{
	uint32_t minimum, maximum;
	uint8_t ES = config->es;

	minimum = (uint32_t) (1000000 / (syncFreqHz * 27.0));
	maximum = (uint32_t) (1000000 / (syncFreqHz * 11.95));
	if (maximum > 0xFF) {
		maximum = 0xFF;
	}

	if (ES > maximum || ES < minimum) {
		return kStatus_DSL_Invalid_ES;
	}
	DSL_SetOutputActivate(base, 0x00);
	DSL_SetProtocolRst(base);
	DSL_SetMessagesRst(base);
	DSL_SetPipelineRst(base);

	DSL_ClrProtocolRst(base);
	DSL_ClrMessagesRst(base);
	DSL_ClrPipelineRst(base);

	DSL_SetPolaritySyncPulse(base, config->sync_signal_Polarity);
	DSL_SetPosReadyMode(base, config->pos_ready_mode);
	base->SYNC_CTRL = ES;
	DSL_SetOutputActivate(base, 0x01);
	return kStatus_Success;
}

void DSL_GetMasterReleaseInfo(HIPERFACE_Type *base, dsl_encoder_version_info_t *info)
{
	uint8_t version = base->VERSION_PRIM;
	info->year = 2000 + base->RELEASE_PRIM;
	info->month = base->RELEASE_PRIM;
	info->day = base->RELEASE_PRIM;
	info->coding = (version & HIPERFACE_VERSION_PRIM_CODING_MASK) >> HIPERFACE_VERSION_PRIM_CODING_SHIFT;
	info->majorNumber = (version & HIPERFACE_VERSION_PRIM_MAJOR_RELEASE_MASK) >> HIPERFACE_VERSION_PRIM_MAJOR_RELEASE_SHIFT;
	info->minorNumber = (version & HIPERFACE_VERSION_PRIM_MINOR_RELEASE_MASK) >> HIPERFACE_VERSION_PRIM_MINOR_RELEASE_SHIFT;
}

void DSL_EncoderInit(HIPERFACE_Type *base, dsl_encoder_t *enc)
{
	enc->base = base;
	enc->encoderID = DSL_GetPrimEncoderID(base);
	enc->sign = DSL_GetPosSign(enc->encoderID);

	enc->accValueLen = DSL_GetAccValueLen(enc->encoderID);
    enc->posValueLen = DSL_GetPosValueLen(enc->encoderID);
	enc->signExtend = DSL_GetSignExtend(enc->encoderID);
	enc->signMask = DSL_GetSignMask(enc->encoderID);
}

status_t DSL_CheckLinkStatus(HIPERFACE_Type *base, uint32_t timeout_ms)
{
	uint32_t target = getTimestampMS() + timeout_ms;
	do {
		if (DSL_GetQualityMonitoringLink(base)) {
			return kStatus_Success;
		}
	} while (getTimestampMS() < target);
	return kStatus_Timeout;
}

uint64_t DSL_GetFastPosition(HIPERFACE_Type *base, dsl_encoder_t *enc)
{
	volatile uint32_t pos_h = *(uint32_t *)&base->POS_PRIM[0];
	volatile uint32_t pos_l = *(uint32_t *)&base->POS_PRIM[4];
	pos_h = BSWAP32(pos_h);
	uint64_t pos_u64 = (((uint64_t)pos_h) << 8) + (pos_l & 0xFF);
	if (enc->sign && (pos_u64 | enc->signMask)) {
		return pos_u64 | enc->signExtend;
	}
	return pos_u64;
}

uint32_t DSL_GetSpeed(HIPERFACE_Type *base)
{
	return (base->VEL_PRIM[0] << 16) + (base->VEL_PRIM[1] << 8) + base->VEL_PRIM[0];
}

char *DSL_RDB_AccessErr2str(uint16_t errno)
{
	switch(errno) {
		case DSL_RDB_AccessErr_ResourceIdentifierNotImplemented:
			return "4010h - Resource identifier not implemented";
		case DSL_RDB_AccessErr_IncorrectLength:
			return "4011h - Incorrect length for resource access given";
		case DSL_RDB_AccessErr_OffsetValueTooHigh:
			return "4013h - Offset value too high";
		case DSL_RDB_AccessErr_InvalidOffsetValue:
			return "4014h - Invalid offset value";
		case DSL_RDB_AccessErr_InvalidData:
			return "4015h - Invalid data value";
		case DSL_RDB_AccessErr_WriteAccessNotPossible:
			return "4110h - Write access not possible";
		case DSL_RDB_AccessErr_ReadAccessNotPossible:
			return "4111h - Read access not possible";
		case DSL_RDB_AccessErr_WriteAccessDenied:
			return "4112h - Write access denied";
		case DSL_RDB_AccessErr_ReadAccessDenied:
			return "4113h - Read access denied";
		case DSL_RDB_AccessErr_DirectWriteAccessDenied:
			return "4114h - Direct write access denied";
		case DSL_RDB_AccessErr_ResourceDatabasenodeCorrupt:
			return "4210h - Resource database node corrupt";
		case DSL_RDB_AccessErr_InternalProcessingError:
			return "4212h - Internal processing error during resource access";
		case DSL_RDB_AccessErr_FileNameNotFound:
			return "4311h - File name was not found";
		case DSL_RDB_AccessErr_InvalidAddressForFileAccess:
			return "4312h - Invalid address for the file access";
		case DSL_RDB_AccessErr_FileNotDeletable:
			return "4313h - File cannot be deleted";
		case DSL_RDB_AccessErr_FileMemoryFull:
			return "4314h - File memory full";
		case DSL_RDB_AccessErr_FileAllocationTableCorrupt:
			return "4315h - File allocation table corrupt";
		case DSL_RDB_AccessErr_NoFileLoadedForAction:
			return "4316h - No file loaded for action";
		case DSL_RDB_AccessErr_FileWithSameNameExists:
			return "4317h - File with same name exists";
		default:
			return "Unknown RDB Access Errno";
		}
}

status_t DSL_RDB_Wrire(HIPERFACE_Type *base, uint16_t addr, uint16_t offset, void *data,
								uint32_t datLen, uint32_t flag, uint32_t timeout_ms, uint16_t *errno)
{
	uint32_t endTime;
	uint8_t  var = 0;
	assert(datLen <= 8);
	uint8_t len;
	if (datLen == 8)
		len = 3;
	else if(datLen == 4)
		len = 2;
	else if(datLen == 2)
		len = 1;
	else
		len = 0;

	if (!DSl_GetEventLongMsgChannelfree(base)) {
		return kStatus_DSL_Lmsg_Channel_Busy;
	}

	if (flag & LMSG_F_DIRECT)
		DSL_SetLmsgAddrDirect(var);
	else
		DSL_SetLmsgAddrIndirect(var);

	if (flag & LMSG_F_OFFSET) {
		DSL_SetLmsgAddrOffset(base, offset);
		DSL_SetLmsgAddrWithOffset(var);
	} else
		DSL_SetLmsgAddrWithoutOffset(var);

	DSL_SetLmsgDataLen(var, len);
	DSL_SetLmsgBuf(base, data, datLen);
	DSL_SetLmsgWrite(var);
	DSL_SetLmsgAddr(base, var, addr);
	DSL_SetLmsgStart(base);

	endTime = getTimestampMS() + timeout_ms;
	while (getTimestampMS() < endTime) {
		if (DSl_GetEventLongMsgChannelfree(base)) {
			if (DSL_GetLmsgLastCauseError(base) && errno != NULL) {
				*errno = (base->PRIM[1] << 8) + base->PRIM[0];
				return kStatus_DSL_Lmsg_Err_CausedByLmsg;
			}

			if (DSl_GetEventLongMsgAnswerErr(base)) {
				return kStatus_DSL_Lmsg_Erroneous_Answer;
			}

			return kStatus_Success;
		 }
	}

	/*The Parameters Channel is reset. Current long messages are discarded*/
	DSL_SetMessagesRst(base);
	DSL_ClrMessagesRst(base);
	return kStatus_Timeout;
}

status_t DSL_RDB_Read(HIPERFACE_Type *base, uint16_t addr, uint16_t offset, void *data,
							uint32_t datLen, uint32_t flag, uint32_t timeout_ms, uint16_t *errno)
{
	uint32_t endTime;
	uint8_t  var = 0;
	assert(datLen <= 8);
	uint8_t len;
	if (datLen > 4)
		len = 3;
	else if(datLen > 2)
		len = 2;
	else
		len = 1;

	if (!DSl_GetEventLongMsgChannelfree(base)) {
		return kStatus_DSL_Lmsg_Channel_Busy;
	}

	if (flag & LMSG_F_DIRECT)
		DSL_SetLmsgAddrDirect(var);
	else
		DSL_SetLmsgAddrIndirect(var);

	if (flag & LMSG_F_OFFSET) {
		DSL_SetLmsgAddrOffset(base, offset);
		DSL_SetLmsgAddrWithOffset(var);
	} else
		DSL_SetLmsgAddrWithoutOffset(var);

	DSL_SetLmsgRead(var);
	DSL_SetLmsgDataLen(var, len);
	DSL_SetLmsgAddr(base, var, addr);
	DSl_ClrEventLongMsgChannelfree(base);
	DSL_SetLmsgStart(base);

	endTime = getTimestampMS() + timeout_ms;
	while (getTimestampMS() < endTime) {
		if (DSl_GetEventLongMsgChannelfree(base)) {

	if (DSL_GetLmsgLastCauseError(base) && errno != NULL) {
		*errno = (base->PRIM[1] << 8) + base->PRIM[0];
		return kStatus_DSL_Lmsg_Err_CausedByLmsg;
	}

	if (DSl_GetEventLongMsgAnswerErr(base)) {
		return kStatus_DSL_Lmsg_Erroneous_Answer;
	}
			 DSL_GetLmsgBuf(base, data, datLen);
			return kStatus_Success;
		}
	}

	/*The Parameters Channel is reset. Current long messages are discarded*/
	DSL_SetMessagesRst(base);
	DSL_ClrMessagesRst(base);
	return kStatus_Timeout;
}

status_t DSL_RDB_GetResourceName(HIPERFACE_Type *base, dsl_rdb_node_t *node, uint16_t rid)
{
	uint16_t errno;
	status_t status;
	if ((status = _DSL_RDB_GetResourceName(base, rid, node->resourceName, &errno)) != kStatus_Success) {
		if (status == kStatus_DSL_Lmsg_Err_CausedByLmsg) {
			return status;
		}
	}
	return kStatus_Success;
}

status_t DSL_RDB_GetDataSize(HIPERFACE_Type *base, dsl_rdb_node_t *node, uint16_t rid)
{
	uint16_t errno;
	status_t status;
	if ((status = _DSL_RDB_GetDataSize(base, rid, &node->resourceDataLen, &errno)) != kStatus_Success) {
		if (status == kStatus_DSL_Lmsg_Err_CausedByLmsg) {
			return status;
		}
	}
	node->resourceDataLen = BSWAP16(node->resourceDataLen);
	return kStatus_Success;
}

status_t DSL_RDB_GetReadAccessLevel(HIPERFACE_Type *base, dsl_rdb_node_t *node, uint16_t rid)
{
	uint16_t errno;
	status_t status;
	if ((status = _DSL_RDB_GetReadAccessLevel(base, rid, &node->readAccessLevel, &errno)) != kStatus_Success) {
		if (status == kStatus_DSL_Lmsg_Err_CausedByLmsg) {
			return status;
		}
	}
	node->readAccessLevel = BSWAP16(node->readAccessLevel);
	return kStatus_Success;
}

status_t DSL_RDB_GetWriteAccessLevel(HIPERFACE_Type *base, dsl_rdb_node_t *node, uint16_t rid)
{
	uint16_t errno;
	status_t status;
	if ((status = _DSL_RDB_GetWriteAccessLevel(base, rid, &node->writeAccessLevel, &errno)) != kStatus_Success) {
		if (status == kStatus_DSL_Lmsg_Err_CausedByLmsg) {
			return status;
		}
	}
	node->writeAccessLevel = BSWAP16(node->writeAccessLevel);
	return kStatus_Success;
}

status_t DSL_RDB_GetTimeOverrun(HIPERFACE_Type *base, dsl_rdb_node_t *node, uint16_t rid)
{
	uint16_t errno;
	status_t status;
	if ((status = _DSL_RDB_GetTimeOverrun(base, rid, &node->timeOverrun, &errno)) != kStatus_Success) {
		if (status == kStatus_DSL_Lmsg_Err_CausedByLmsg) {
			return status;
		}
	}
	node->timeOverrun = BSWAP16(node->timeOverrun);
	/* The resource needs more than 254 ms for processing or the time overrun is not deterministic */
	if (node->timeOverrun == 255) {
		/* Assume that 3s is enough for slave processing*/
		node->timeOverrun = 3000;
	}
	return kStatus_Success;
}

status_t DSL_RDB_GetDataType(HIPERFACE_Type *base, dsl_rdb_node_t *node, uint16_t rid)
{
	uint16_t errno;
	status_t status;
	if ((status = _DSL_RDB_GetDataType(base, rid, &node->dataType, &errno)) != kStatus_Success) {
		if (status == kStatus_DSL_Lmsg_Err_CausedByLmsg) {
			return status;
		}
	}
	node->dataType = BSWAP16(node->dataType);
	return kStatus_Success;
}

/*Read Resource Data with specified offset*/
status_t DSL_RDB_ReadIndirectWithOffset(HIPERFACE_Type *base, dsl_rdb_node_t *node, void *data, uint32_t datLen, uint16_t offset)
{
	uint16_t errno;
	status_t status;
	assert(datLen <= 8);
	if ((status = DSL_RDB_Read(base, node->rid, offset, data, datLen,  LMSG_F_INDIRECT | LMSG_F_OFFSET, node->timeOverrun, &errno)) != kStatus_Success) {
		if (status == kStatus_DSL_Lmsg_Err_CausedByLmsg) {
			return status;
		}
	}
	return kStatus_Success;
}

/*Read Resource Data from offset 0 and the detLen is not greater than 8*/
status_t DSL_RDB_ReadIndirect(HIPERFACE_Type *base, dsl_rdb_node_t *node, void *data, uint32_t datLen)
{
	uint16_t errno;
	status_t status;
	assert(datLen <= 8);
	if ((status = DSL_RDB_Read(base, node->rid, 0, data, datLen,  LMSG_F_INDIRECT | LMSG_F_NO_OFFSET, node->timeOverrun, &errno)) != kStatus_Success) {
		if (status == kStatus_DSL_Lmsg_Err_CausedByLmsg) {
			return status;
		}
	}
	return kStatus_Success;
}

/*Write Resource Data from offset 0 and the detLen is not greater than 8*/
status_t DSL_RDB_ReadIndirectMultiple(HIPERFACE_Type *base, dsl_rdb_node_t *node, void *data, uint32_t datLen)
{
	uint16_t errno;
	status_t status;
	datLen = datLen > node->resourceDataLen ? node->resourceDataLen : datLen;
	int len = datLen > 8 ? 8 : datLen;
	int offset = 0;
	while (len) {
		if ((status = DSL_RDB_Read(base, node->rid, offset, (uint8_t *)data + offset, len,  LMSG_F_INDIRECT | LMSG_F_OFFSET, node->timeOverrun, &errno)) != kStatus_Success) {
			if (status == kStatus_DSL_Lmsg_Err_CausedByLmsg) {
				return status;
			}
			offset += len;
			datLen -= len;
			len = datLen > 8 ? 8 : datLen;
		}
	}
	return kStatus_Success;

}

/*Write Resource Data with specified offset*/
status_t DSL_RDB_WriteIndirectWithOffset(HIPERFACE_Type *base, dsl_rdb_node_t *node, void *data, uint32_t datLen, uint16_t offset)
{
	uint16_t errno;
	status_t status;
	assert(datLen <= 8);
	if ((status = DSL_RDB_Wrire(base, node->rid, offset, data, datLen,  LMSG_F_INDIRECT | LMSG_F_OFFSET, node->timeOverrun, &errno)) != kStatus_Success) {
		if (status == kStatus_DSL_Lmsg_Err_CausedByLmsg) {
			return status;
		}
	}
	return kStatus_Success;
}

/*Write Resource Data from offset 0 and the detLen is not greater than 8*/
status_t DSL_RDB_WriteIndirect(HIPERFACE_Type *base, dsl_rdb_node_t *node, void *data, uint32_t datLen)
{
	uint16_t errno;
	status_t status;
	assert(datLen <= 8);
	if ((status = DSL_RDB_Wrire(base, node->rid, 0, data, datLen,  LMSG_F_INDIRECT | LMSG_F_NO_OFFSET, node->timeOverrun, &errno)) != kStatus_Success) {
		if (status == kStatus_DSL_Lmsg_Err_CausedByLmsg) {
			return status;
		}
	}
	return kStatus_Success;
}


void DSL_GetFastPositionAndSpeed(HIPERFACE_Type *base, uint64_t *position, int32_t *speed)
{
	uint32_t pos0, pos1;
	pos0 = *(uint32_t*)(&base->POS_PRIM[0]);
	pos1 = *(uint32_t*)(&base->POS_PRIM[4]);
	*position = (((uint64_t)pos0) << 8) + (pos1 >> 24);
	if (pos1 & 0x800000) {
		*speed = pos1 | 0xFF000000;
	} else {
			*speed = pos1 & 0xFFFFFF;
	}
}

/*Write Resource Data from offset 0 and the detLen is greater than 8*/
status_t DSL_RDB_WriteIndirectMultiple(HIPERFACE_Type *base, dsl_rdb_node_t *node, void *data, uint32_t datLen)
{
	uint16_t errno;
	status_t status;
	datLen = datLen > node->resourceDataLen ? node->resourceDataLen : datLen;
	int len = datLen > 8 ? 8 : datLen;
	int offset = 0;
	while (len) {
		if ((status = DSL_RDB_Wrire(base, node->rid, offset, (uint8_t *)data + offset, len,  LMSG_F_INDIRECT | LMSG_F_OFFSET, node->timeOverrun, &errno)) != kStatus_Success) {
			if (status == kStatus_DSL_Lmsg_Err_CausedByLmsg) {
				return status;
			}
			offset += len;
			datLen -= len;
			len = datLen > 8 ? 8 : datLen;
		}
	}
	return kStatus_Success;

}

/* Read the defining values*/
status_t DSL_RDB_GetNodeDefiningValue(HIPERFACE_Type *base, dsl_rdb_node_t *node, uint16_t rid)
{
	status_t status;
	node->rid = rid;
	if ((status = DSL_RDB_GetResourceName(base, node, rid)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_GetDataSize(base, node, rid)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_GetReadAccessLevel(base, node, rid)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_GetWriteAccessLevel(base, node, rid)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_GetTimeOverrun(base, node, rid)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_GetDataType(base, node, rid)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;
}

status_t DSL_RDB_GetNodeLinkedNum(HIPERFACE_Type *base, dsl_rdb_node_t *node)
{
	uint16_t errno;
	status_t status;
	if ((status = _DSL_RDB_GetLinkedNodeNum(base, node->rid, &node->childrenNum, &errno)) != kStatus_Success) {
		if (status == kStatus_DSL_Lmsg_Err_CausedByLmsg) {
			return status;
		}

	}
	node->childrenNum = BSWAP16(node->childrenNum);
	return kStatus_Success;
}

status_t DSL_RDB_GetNodeLinkedRID(HIPERFACE_Type *base, dsl_rdb_node_t *node, uint8_t index, uint16_t *rid)
{
	uint16_t errno;
	status_t status;
	if ((status = _DSL_RDB_GetLinkedNodeRID(base, node, index, rid, &errno)) != kStatus_Success) {
		if (status == kStatus_DSL_Lmsg_Err_CausedByLmsg) {
			return status;
		}
	}
	*rid = BSWAP16(*rid);
	return kStatus_Success;
}

status_t DSL_RDB_TraverseNodeDefiningValue(HIPERFACE_Type *base, dsl_rdb_node_t *root, uint16_t rid)
{
	status_t status;
	dsl_rdb_node_t *newNodes;
	int i;

	if ((status = DSL_RDB_GetNodeDefiningValue(base, root, rid)) != kStatus_Success) {
		return status;
	}

	if (root->dataType == RDB_DATA_TYPE_NODE_INDICATOR) {
		if ((status = DSL_RDB_GetNodeLinkedNum(base, root)) != kStatus_Success) {
			return status;
	}

		newNodes = malloc(root->childrenNum * sizeof(dsl_rdb_node_t));
		if (newNodes == NULL) {
			return kStatus_Fail;
		}
		memset(newNodes, 0, root->childrenNum * sizeof(dsl_rdb_node_t));

		for (i = 0; i < root->childrenNum; i++) {
			if ((status = DSL_RDB_GetNodeLinkedRID(base, root, i, &rid)) != kStatus_Success) {
				break;
			}
			if ((status = DSL_RDB_TraverseNodeDefiningValue(base, newNodes + i, rid)) != kStatus_Success) {
				break;
			}
		}
		if (status != kStatus_Success) {
			free(newNodes);
		}

		root->nodes = newNodes;
	}
	return kStatus_Success;
}

void DSL_RDB_FreeNodeDefiningValue(HIPERFACE_Type *base, dsl_rdb_node_t *root)
{
	int i;
	if (root->dataType == RDB_DATA_TYPE_NODE_INDICATOR) {
		for (i = 0; i < root->childrenNum; i++) {
			if (root->nodes[i].dataType == RDB_DATA_TYPE_NODE_INDICATOR) {
				DSL_RDB_FreeNodeDefiningValue(base, &root->nodes[i]);
			}
		}
		free(root->nodes);
	}
}

status_t DSL_RDB_ReadAllNodeDefiningValue(HIPERFACE_Type *base, dsl_encoder_t *enc)
{
	return DSL_RDB_TraverseNodeDefiningValue(base, &enc->rootNode, DSL_RID_RootNode);
}

void DSL_RDB_FreeAllNodeDefiningValue(HIPERFACE_Type *base, dsl_encoder_t *enc)
{
	DSL_RDB_FreeNodeDefiningValue(base, &enc->rootNode);
}

dsl_rdb_node_t *DSL_RDB_FindNodeFromCache(dsl_rdb_node_t *root, uint16_t rid)
{
	int i;
	dsl_rdb_node_t *node;
	if (root->rid == rid) {
		return root;
	} else {
		if (root->dataType == RDB_DATA_TYPE_NODE_INDICATOR) {
			for (i = 0; i < root->childrenNum; i++) {
				if (root->nodes[i].dataType == RDB_DATA_TYPE_NODE_INDICATOR) {
					node = DSL_RDB_FindNodeFromCache(root->nodes + i, rid);
					if (node != NULL) {
						return node;
					}
				} else {
					if (root->nodes[i].rid == rid) {
						return &root->nodes[i];
					}
				}
			}
		}
	}
	return NULL;
}

char *DSL_RDB_AccessLevelToStr(uint16_t level)
{
	char *str;
	switch (level) {
		case 0: str = "Run (public)"; break;
		case 1: str = "Opterator"; break;
		case 2: str = "Maintenance"; break;
		case 3: str = "Authorized Client"; break;
		case 4: str = "Service (MFB Customer)"; break;
		case 5: str = "Service (MFB Manufacturer)"; break;
		case 15: str = "No access possible"; break;
		default: str = "Unknown";
	}
	return str;
}

char *DSL_RDB_DataTypeToStr(uint16_t type)
{
	char *str;
	if (type >= RDB_DATA_TYPE_STRUCT_BASE && type <= RDB_DATA_TYPE_STRUCT_END) {
		str = "Data structure";
	} else {
		switch(type) {
			case RDB_DATA_TYPE_NODE_INDICATOR:
				str = "Node indicator"; break;
			case RDB_DATA_TYPE_NO_DATA:
				str = "Void (no data)"; break;
			case RDB_DATA_TYPE_BIT:
				str = "Bit (1 = true, 0 = false)"; break;
			case RDB_DATA_TYPE_UINT8:
				str = "8 bit, unsigned"; break;
			case RDB_DATA_TYPE_UINT16:
				str = "16 bit, unsigned"; break;
			case RDB_DATA_TYPE_UINT32:
				str = "32 bit, unsigned"; break;
			case RDB_DATA_TYPE_UINT64:
				str = "64 bit, unsigned"; break;
			case RDB_DATA_TYPE_INT8:
				str = "8 bit, with sign"; break;
			case RDB_DATA_TYPE_INT16:
				str = "16 bit, with sign"; break;
			case RDB_DATA_TYPE_INT32:
				str = "32 bit, with sign"; break;
			case RDB_DATA_TYPE_INT64:
				str = "64 bit, with sign"; break;
			case RDB_DATA_TYPE_STRING:
				str = "String (character chain)"; break;
			default: str = "Unknown"; break;
		}
	}

	return str;
}

char *DSL_RDB_TypeOfEncoderTostr(uint16_t type)
{
	char *str;
	switch (type) {
		case 0x0000: str = "Rotary encoder, bipolar counting"; break;
		case 0x0001: str = "Linear encoder, bipolar counting"; break;
		case 0x0002: str = "Rotary encoder, unipolar counting"; break;
		case 0x0003: str = "Linear encoder, unipolar counting"; break;
		default: str = "unknown";
	}
	return str;
}

status_t DSL_RDB_GetTypeOfEncoder(HIPERFACE_Type *base, uint16_t *type)
{
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_TypeOfEncoder)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, type, 2)) != kStatus_Success) {
		return status;
	}

	*type = BSWAP16(*type);
	return kStatus_Success;
}

status_t DSL_RDB_GetResolution(HIPERFACE_Type *base, uint32_t *resolution)
{
	status_t status;
	dsl_rdb_node_t node= {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_Resolution)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, resolution, 4)) != kStatus_Success) {
		return status;
	}

	*resolution = BSWAP32(*resolution);
	return kStatus_Success;
}

status_t DSL_RDB_GetMeasurementRange(HIPERFACE_Type *base, uint32_t *range)
{
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_MeasurementRange)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, range, 4)) != kStatus_Success) {
		return status;
	}

	*range = BSWAP32(*range);
	return kStatus_Success;
}

status_t DSL_RDB_GetTypeNameOfEncoder(HIPERFACE_Type *base, uint8_t *name, uint32_t len)
{
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_TypeOfEncoder)) != kStatus_Success) {
		return status;
	}

	if (len < node.resourceDataLen + 1) {
		return kStatus_OutOfRange;
	}

	if ((status = DSL_RDB_ReadIndirectMultiple(base, &node, name, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}
	name[node.resourceDataLen] = '\0';

	return kStatus_Success;
}

status_t DSL_RDB_GetSerialNumber(HIPERFACE_Type *base, uint8_t *serialNumber, uint32_t len)
{
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_SerialNumber)) != kStatus_Success) {
		return status;
	}

	if (len < node.resourceDataLen + 1) {
		return kStatus_OutOfRange;
	}

	if ((status = DSL_RDB_ReadIndirectMultiple(base, &node, serialNumber, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}
	serialNumber[node.resourceDataLen] = '\0';

	return kStatus_Success;
}

status_t DSL_RDB_GetBaseiceVersion(HIPERFACE_Type *base, uint8_t *firmware_version, uint32_t len0, uint8_t *hardware_version, uint32_t len1)
{
	status_t status;
	dsl_rdb_node_t node = {0};
	uint8_t buf[20];

	assert(len0 > 16);
	assert(len1 > 4);

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_baseiceVersion)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirectMultiple(base, &node, buf, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	memcpy(firmware_version, buf, 16);
	memcpy(hardware_version, &buf[16], 4);
	firmware_version[16] = '\0';
	hardware_version[4] = '\0';

	return kStatus_Success;
}

status_t DSL_RDB_GetFirmwareDate(HIPERFACE_Type *base, uint8_t *date, uint32_t len)
{
	status_t status;
	dsl_rdb_node_t node = {0};
	assert(len > 8);
	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_FirmwareDate)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, date, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}
	date[node.resourceDataLen] = '\0';
	return kStatus_Success;
}

status_t DSL_RDB_GetEEPROMSize(HIPERFACE_Type *base, uint16_t *size)
{
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_EEPROMSize)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, size, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	*size = BSWAP16(*size);
	return kStatus_Success;
}

status_t DSL_RDB_GetSafeChannel2Resolution(HIPERFACE_Type *base, uint32_t *resolution)
{
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_SafeChannel2Resolution)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, resolution, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	*resolution = BSWAP32(*resolution);
	return kStatus_Success;
}

status_t DSL_RDB_GetSensorPeriods(HIPERFACE_Type *base, uint16_t *sysPeriods, uint32_t *sysResolution)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_SensorPeriods)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, buf, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	*sysPeriods = (buf[0] << 8) + buf[1];
	*sysResolution = (buf[2] << 24) + (buf[3] << 16) + (buf[4] << 8) + buf[5];
	return kStatus_Success;
}

status_t DSL_RDB_GetTemperatureRange(HIPERFACE_Type *base, float *maximum, float *minimum)
{
	uint8_t buf[8];
	int16_t temp;
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_TemperatureRange)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, buf, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	temp = (buf[0] << 8) | buf[0];
	*minimum = temp/ 10.0;
	temp = (buf[2] << 8) | buf[3];
	*maximum = temp/ 10.0;
	return kStatus_Success;
}

status_t DSL_RDB_GetTemperature(HIPERFACE_Type *base, float *temperature)
{
	uint8_t buf[8];
	int16_t temp;
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_Temperature)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, buf, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	temp = (buf[0] << 8) | buf[1];
	*temperature =temp / 10.0;
	return kStatus_Success;
}

status_t DSL_RDB_GetSupplyVoltageRange(HIPERFACE_Type *base, uint16_t *maximum, uint16_t *minimum)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_SupplyVoltageRange)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, buf, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	*minimum = (buf[0] << 8) + buf[1];
	*maximum = (buf[2] << 8) + buf[3];
	return kStatus_Success;
}

status_t DSL_RDB_GetSupplyVoltage(HIPERFACE_Type *base, uint16_t *voltage)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_SupplyVoltage)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, buf, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	*voltage = (buf[0] << 8) + buf[1];
	return kStatus_Success;
}

status_t DSL_RDB_GetRotationSpeedRange(HIPERFACE_Type *base, uint16_t *range)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_RotationSpeedRange)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, buf, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	*range = (buf[0] << 8) + buf[1];
	return kStatus_Success;
}

status_t DSL_RDB_GetRotationSpeed(HIPERFACE_Type *base, uint16_t *speed)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_RotationSpeed)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, buf, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	*speed = (buf[0] << 8) + buf[1];
	return kStatus_Success;
}

status_t DSL_RDB_GetAccelerationRange(HIPERFACE_Type *base, uint16_t *range)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_AccelerationRange)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, buf, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	*range = (buf[0] << 8) + buf[1];
	return kStatus_Success;
}

status_t DSL_RDB_GetLifetime(HIPERFACE_Type *base, uint32_t *operatingTime, uint32_t *shaftRotationsNum)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_Lifetime)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, buf, 8)) != kStatus_Success) {
		return status;
	}

	*operatingTime = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];
	*shaftRotationsNum = (buf[4] << 24) + (buf[5] << 16) + (buf[6] << 8) + buf[7];
	return kStatus_Success;
}

status_t DSL_RDB_GetLifetimeRemaining(HIPERFACE_Type *base, uint32_t *RemainingTaskLifetime)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_Lifetime)) != kStatus_Success) {
		return status;
	}

	if (node.resourceDataLen < 12) {
		return kStatus_Fail;
	}

	if ((status = DSL_RDB_ReadIndirectWithOffset(base, &node, buf, 4, 8)) != kStatus_Success) {
		return status;
	}

	*RemainingTaskLifetime = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];
	return kStatus_Success;
}

status_t DSL_RDB_GetErrorLogNumber(HIPERFACE_Type *base, uint32_t *num)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_ErrorLog)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirectWithOffset(base, &node, buf, 8, 0)) != kStatus_Success) {
		return status;
	}

	*num = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];
	return kStatus_Success;
}

status_t DSL_RDB_GetErrorLog(HIPERFACE_Type *base, uint32_t index, dsl_rdb_error_protocol_t *errlog)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_ErrorLog)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirectWithOffset(base, &node, buf, 8, index + 1)) != kStatus_Success) {
		return status;
	}

	errlog->timeStamp = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];
	errlog->temperature = (buf[4] << 8) + buf[5];
	errlog->technologySpecific = (buf[6] << 8) + buf[7];

	if ((status = DSL_RDB_ReadIndirectWithOffset(base, &node, buf, 8, index + 0x0101)) != kStatus_Success) {
		return status;
	}

	errlog->internalSupplyVoltage = (buf[0] << 8) + buf[1];
	errlog->rotationSpeed = (buf[2] << 8) + buf[3];
	errlog->reserved = (buf[4] << 8) + buf[5];
	errlog->additionalErrorConde = buf[6];
	errlog->errorConde = buf[7];

	return kStatus_Success;
}

status_t DSL_RDB_GetUsageHistogram(HIPERFACE_Type *base, uint8_t encoder_parameter, uint8_t histogram_class, uint32_t *value)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_UsageHistogram)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirectWithOffset(base, &node, buf, 4, (encoder_parameter << 8) + histogram_class)) != kStatus_Success) {
		return status;
	}

	if (histogram_class != buf[0]) {
		return status;
	}

	*value = (buf[1] << 16) + (buf[2] << 8) + buf[3];
	return kStatus_Success;
}

status_t DSL_RDB_GetErrorLogFilter(HIPERFACE_Type *base, uint8_t *st)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_ErrorLogFilter)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, buf, 2)) != kStatus_Success) {
		return status;
	}

	if (buf[0] == 0x50 && buf[1] == 0x00) {
		*st = ERROR_LOG_FILTER_ON;
	} else {
		*st = ERROR_LOG_FILTER_OFF;
	}

	return kStatus_Success;
}

status_t DSL_RDB_SetErrorLogFilter(HIPERFACE_Type *base, uint8_t st)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_ErrorLogFilter)) != kStatus_Success) {
		return status;
	}

	if (status == ERROR_LOG_FILTER_ON) {
		buf[1] = 0x00;
		buf[0] = 0x50;
	} else {
		buf[1] = 0x00;
		buf[0] = 0x00;
	}

	if ((status = DSL_RDB_WriteIndirect(base, &node, buf, 2)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;
}

status_t DSL_RDB_SetReset(HIPERFACE_Type *base)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_ResetShutdown)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirectWithOffset(base, &node, buf, 0, 0)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;
}

status_t DSL_RDB_SetShutDown(HIPERFACE_Type *base)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_ResetShutdown)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirectWithOffset(base, &node, buf, 0, 1)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;
}

status_t DSL_RDB_GetSetPosition(HIPERFACE_Type *base, uint64_t *pos)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_SetPosition)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, &buf[0], node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	*pos = ((uint64_t) buf[4] << 32) | (buf[3] << 24) | (buf[2] << 16) | (buf[1] << 8) | buf[0];
	return kStatus_Success;
}

status_t DSL_RDB_SetSetPosition(HIPERFACE_Type *base, uint64_t pos)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	buf[0] = pos & 0xFF;
	buf[1] = (pos >> 8) & 0xFF;
	buf[2] = (pos >> 16) & 0xFF;
	buf[3] = (pos >> 24) & 0xFF;
	buf[4] = (pos >> 32) & 0xFF;
	buf[5] = 0;
	buf[6] = 0;
	buf[7] = 0;

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_SetPosition)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirect(base, &node, buf, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;
}

status_t DSL_RDB_GetCurrentAccessLevel(HIPERFACE_Type *base, uint8_t *accessLevel)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_SetAccesslevel)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, buf, 2)) != kStatus_Success) {
		return status;
	}

	*accessLevel = buf[0];
	return kStatus_Success;
}

status_t DSL_RDB_SetAccessLevel(HIPERFACE_Type *base, uint8_t accessLevel, uint32_t password)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	buf[0] = accessLevel & 0x3;
	buf[1] = 0;
	buf[2] = 0;
	buf[3] = 0;
	buf[4] = (password >> 24) & 0xFF;
	buf[5] = (password >> 16) & 0xFF;
	buf[6] = (password >> 8) & 0xFF;
	buf[7] = (password >> 0) & 0xFF;

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_SetPosition)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirect(base, &node, buf, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;
}

status_t DSL_RDB_ChangeAccessKey(HIPERFACE_Type *base, uint8_t accessLevel, uint32_t newPassword, uint32_t oldPassword)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	buf[0] = (newPassword >> 24) & 0xFF;
	buf[1] = (newPassword >> 16) & 0xFF;
	buf[2] = (newPassword >> 8) & 0xFF;
	buf[3] = (newPassword >> 0) & 0xFF;
	buf[4] = (oldPassword >> 24) & 0xFF;
	buf[5] = (oldPassword >> 16) & 0xFF;
	buf[6] = (oldPassword >> 8) & 0xFF;
	buf[7] = (oldPassword >> 0) & 0xFF;

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_ChangeAccessKey)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirectWithOffset(base, &node, buf, node.resourceDataLen, accessLevel)) != kStatus_Success) {
		return status;
	}
	return kStatus_Success;
}

status_t DSL_RDB_GetUserDefinedWarnings(HIPERFACE_Type *base, uint8_t warningIndex, user_defined_warning_t *warning)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_UserDefinedWarnings)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirectWithOffset(base, &node, buf, 8, warningIndex)) != kStatus_Success) {
		return status;
	}

	warning->warningIndex = warningIndex;
	warning->monitiedRID = ((buf[0] & 0x3) << 8) | buf[1];
	warning->monitiedOffset = (buf[3] << 8) + buf[2];
	warning->warningType = ((buf[0] >> 5) & 0x7);
	warning->format = ((buf[0] >> 2) & 0x7);

	if ((status = DSL_RDB_ReadIndirectWithOffset(base, &node, buf, 8, warningIndex + 0x10)) != kStatus_Success) {
		return status;
	}
	memcpy(warning->value, buf, 8);
	return kStatus_Success;

}

status_t DSL_RDB_SetUserDefinedWarnings(HIPERFACE_Type *base, user_defined_warning_t *warning)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	buf[0] = ((warning->warningType & 0x7) << 5) | ((warning->format & 0x7) << 2) | ((warning->monitiedRID >> 8) & 0x3);
	buf[1] = warning->monitiedRID & 0xFF;
	buf[2] = warning->monitiedOffset & 0xFF;
	buf[3] = (warning->monitiedOffset >> 8) & 0xFF;
	buf[4] = 0;
	buf[5] = 0;
	buf[6] = 0;
	buf[7] = 0;

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_UserDefinedWarnings)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirectWithOffset(base, &node, buf, 8, warning->warningIndex)) != kStatus_Success) {
		return status;
	}

	memcpy(buf, warning->value, 8);
	if ((status = DSL_RDB_WriteIndirectWithOffset(base, &node, buf, 8, warning->warningIndex + 0x10)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;
}

status_t DSL_RDB_SetFactorySettings(HIPERFACE_Type *base, uint8_t reset_mode)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if (reset_mode == RDB_FACTORY_SETTINGS_RESET_USER_FILE_SYSTEM) {
		memcpy(buf, "RESETUFS", 8);
	} else {
		memcpy(buf, "RESETALL", 8);
	}

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_FactorySettings)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirect(base, &node, buf, 8)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;
}

status_t DSL_RDB_GetUserDefinedEncoderIndexRID109(HIPERFACE_Type *base, uint8_t *index)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_UserDefinedEncoderIndex)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, buf, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	*index = buf[0];
	return kStatus_Success;

}
status_t DSL_RDB_SetUserDefinedEncoderIndexRID109(HIPERFACE_Type *base, uint8_t index)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	buf[0] = index & 0xF;
	buf[1] = 0;

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_UserDefinedEncoderIndex)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirect(base, &node, buf, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;

}

status_t DSL_RDB_SetPositionFilterSetting(HIPERFACE_Type *base, uint32_t positionFilter)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	buf[0] = (positionFilter >> 24) & 0xFF;
	buf[1] = (positionFilter >> 16) & 0xFF;
	buf[2] = (positionFilter >> 8) & 0xFF;
	buf[3] = (positionFilter >> 0) & 0xFF;

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_PositionFilterSetting)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirect(base, &node, buf, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;
}

status_t DSL_RDB_GetPositionFilterSetting(HIPERFACE_Type *base, uint32_t *positionFilter)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_PositionFilterSetting)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, buf, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	*positionFilter = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];
	return kStatus_Success;

}

status_t DSL_RDB_GetUserDefinedEncoderIndexRID111(HIPERFACE_Type *base, uint8_t *index)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_UserDefinedEncoderIndexAndIncorporationFunction)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirectWithOffset(base, &node, buf, node.resourceDataLen, 0)) != kStatus_Success) {
		return status;
	}

	*index = buf[0];
	return kStatus_Success;

}

status_t DSL_RDB_SetUserDefinedEncoderIndexRID111(HIPERFACE_Type *base, uint8_t index)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	buf[1] = index & 0xF;
	buf[0] = 0;

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_UserDefinedEncoderIndexAndIncorporationFunction)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirectWithOffset(base, &node, buf, node.resourceDataLen, 0)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;

}

status_t DSL_RDB_GetEncoderIndexIncorporationfunction(HIPERFACE_Type *base, uint8_t *isEnabled)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_UserDefinedEncoderIndexAndIncorporationFunction)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirectWithOffset(base, &node, buf, node.resourceDataLen, 1)) != kStatus_Success) {
		return status;
	}

	if (buf[0] == 0xF)
		*isEnabled = 1;
	else
		*isEnabled = 0;
	return kStatus_Success;

}

status_t DSL_RDB_SetEncoderIndexIncorporationfunction(HIPERFACE_Type *base, uint8_t isEnabled)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if (isEnabled) {
		buf[0] = 0xF;
	}
	else {
		buf[0] = 0;
	}
	buf[1] = 0;

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_UserDefinedEncoderIndexAndIncorporationFunction)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirectWithOffset(base, &node, buf, node.resourceDataLen, 1)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;

}

status_t DSL_RDB_GetReadCounter(HIPERFACE_Type *base, uint32_t *counter)
{
	uint8_t buf[8];
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_ReadCounter)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, buf, node.resourceDataLen)) != kStatus_Success) {
		return status;
	}

	*counter = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];
	return kStatus_Success;
}

status_t DSL_RDB_SetIncrementCounter(HIPERFACE_Type *base)
{
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_IncrementCounter)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirect(base, &node, NULL, 0)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;
}

status_t DSL_RDB_SetResetcounter(HIPERFACE_Type *base)
{
	status_t status;
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_ReadCounter)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirect(base, &node, NULL, 0)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;
}

status_t DSL_RDB_LoadFile(HIPERFACE_Type *base, char *fileName, uint8_t isVerified)
{
	status_t status;
	char buf[8];
	uint16_t offset;
	dsl_rdb_node_t node = {0};
	int len, i;

	len = strlen(fileName);
	if (len > 8) {
		return kStatus_InvalidArgument;
	}

	strncpy(buf, fileName, 8);
	for (i = len; i < 8; i++) {
		buf[i] = '\0';
	}
	if (isVerified) {
		offset = 0x0;
	} else {
		offset = 0x10;
	}


	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_LoadFile)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirectWithOffset(base, &node, buf, 8, offset)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;

}

status_t DSL_RDB_ReadFile(HIPERFACE_Type *base, uint8_t *buf, int16_t len, uint16_t offset)
{
	status_t status;
	dsl_rdb_node_t node = {0};
	uint16_t l = 0;
	uint16_t index = 0;
	int i;

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_ReadWriteFile)) != kStatus_Success) {
		return status;
	}

	while (len) {
		l = len > 8 ? 8 : len;
		if (l % 2) {
			l += 1;
			buf[l] = '\0';
		}

		for (i = len; i < 8; i++) {
			buf[i] = '\0';
		}

		if ((status = DSL_RDB_ReadIndirectWithOffset(base, &node, buf + index, l, offset + index)) != kStatus_Success) {
			return status;
		}
		index += l;
	}

	return kStatus_Success;
}

status_t DSL_RDB_WriteFile(HIPERFACE_Type *base, uint8_t *buf, int16_t len, uint16_t offset)
{
	status_t status;
	dsl_rdb_node_t node = {0};
	uint16_t l = 0;
	uint16_t index = 0;
	int i;

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_ReadWriteFile)) != kStatus_Success) {
		return status;
	}

	while (len) {
		l = len > 8 ? 8 : len;
		if (l % 2) {
			l += 1;

			buf[l] = '\0';
		}

		for (i = len; i < 8; i++) {
			buf[i] = '\0';
		}

		if ((status = DSL_RDB_WriteIndirectWithOffset(base, &node, buf + index, l, offset + index)) != kStatus_Success) {
			return status;
		}
		index += l;
	}

	return kStatus_Success;
}


status_t DSL_RDB_GetFileStatus(HIPERFACE_Type *base, uint8_t *ReadAccessRight, uint8_t *writeAccessRight, uint16_t *fileSize)
{
	status_t status;
	uint8_t buf[8];
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_FileStatus)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirect(base, &node, buf, 4)) != kStatus_Success) {
		return status;
	}

	*ReadAccessRight = buf[0] & 0xF;
	*writeAccessRight = (buf[0] & 0xF0) >> 4;
	*fileSize = (buf[2] << 8) + buf[3];
	return kStatus_Success;
}

status_t DSL_RDB_CreateFile(HIPERFACE_Type *base, char *fileName, uint8_t ReadAccessRight, uint8_t writeAccessRight)
{
	status_t status;
	char buf[8];
	uint16_t offset;
	dsl_rdb_node_t node = {0};
	int len, i;

	len = strlen(fileName);
	if (len > 8) {
		return kStatus_InvalidArgument;
	}

	strncpy(buf, fileName, 8);
	for (i = len; i < 8; i++) {
		buf[i] = '\0';
	}

	offset = (0x3 << 8) | ((writeAccessRight & 0xF) << 4) | (ReadAccessRight & 0xF);

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_CreateDeleteChangeFile)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirectWithOffset(base, &node, buf, 8, offset)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;
}

status_t DSL_RDB_ChangeFile(HIPERFACE_Type *base, char *fileName, uint8_t ReadAccessRight, uint8_t writeAccessRight)
{
	status_t status;
	char buf[8];
	uint16_t offset;
	dsl_rdb_node_t node = {0};
	int len, i;

	len = strlen(fileName);
	if (len > 8) {
		return kStatus_InvalidArgument;
	}

	strncpy(buf, fileName, 8);
	for (i = len; i < 8; i++) {
		buf[i] = '\0';
	}

	offset = (0x1 << 8) | ((writeAccessRight & 0xF) << 4) | (ReadAccessRight & 0xF);

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_CreateDeleteChangeFile)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirectWithOffset(base, &node, buf, 8, offset)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;
}

status_t DSL_RDB_DeleteFile(HIPERFACE_Type *base)
{
	status_t status;
	dsl_rdb_node_t node = {0};


	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_CreateDeleteChangeFile)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_WriteIndirectWithOffset(base, &node, NULL, 0, 0)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;
}

status_t DSL_RDB_GetDirectoryBasicData(HIPERFACE_Type *base, uint8_t *userFilesNumber, uint16_t *filledBytesNumber, uint16_t *emptyBytesNumber)
{
	status_t status;
	uint8_t buf[8];
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_Directory)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirectWithOffset(base, &node, buf, 8, 0)) != kStatus_Success) {
		return status;
	}

	*userFilesNumber = buf[0];
	*filledBytesNumber = (buf[3] << 8) + buf[2];
	*emptyBytesNumber = (buf[5] << 8) + buf[4];
	return kStatus_Success;
}

status_t DSL_RDB_GetDirectoryFileNmae(HIPERFACE_Type *base, char *fileName, uint32_t len, uint8_t index)
{
	status_t status;
	char buf[9];
	dsl_rdb_node_t node = {0};
	uint32_t l;

	buf[8] = '\0';
	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_Directory)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirectWithOffset(base, &node, buf, 8, index)) != kStatus_Success) {
		return status;
	}

	l = strlen(buf);

	if (len <= l) {
		return kStatus_OutOfRange;
	}

	strncpy(fileName, buf, len);
	return kStatus_Success;
}

status_t DSL_RDB_DigitalOutputWithNumber(HIPERFACE_Type *base, uint8_t IO_index, uint8_t value)
{
	status_t status;
	uint8_t buf[8];
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_AccessSimpleIOs)) != kStatus_Success) {
		return status;
	}

	memset(buf, 0, 4);
	buf[3] = value > 0 ? 0x01 : 0x00;

	if ((status = DSL_RDB_WriteIndirectWithOffset(base, &node, buf, node.resourceDataLen, IO_index)) != kStatus_Success) {
		return status;
	}

	return kStatus_Success;
}

status_t DSL_RDB_DigitalInputWithNumber(HIPERFACE_Type *base, uint8_t IO_index, uint8_t *value)
{
	status_t status;
	uint8_t buf[8];
	dsl_rdb_node_t node = {0};

	if ((status = DSL_RDB_GetNodeDefiningValue(base, &node, DSL_RID_AccessSimpleIOs)) != kStatus_Success) {
		return status;
	}

	if ((status = DSL_RDB_ReadIndirectWithOffset(base, &node, buf, node.resourceDataLen, IO_index)) != kStatus_Success) {
		return status;
	}

	*value = buf[3];
	return kStatus_Success;
}

uint8_t ENC_ST_register_reading(HIPERFACE_Type *base, uint8_t offset)
{
	volatile uint8_t MY_UNUSED dummy;
	offset -= 0x40;
	volatile uint8_t const *enc_st_addr = &(base->ENC_ST[offset]) + 0x200 + (offset % 4) * 0x80;
	base->EVENT_S &= 0xFE;
	dummy = *enc_st_addr;
	while(!(base->EVENT_S & 0x01));
	return base->S_PC_DATA_SAFE;
}

uint8_t ENC_ST_register_writing(HIPERFACE_Type *base, uint8_t offset, uint8_t value)
{
	offset -= 0x40;
	volatile uint8_t *enc_st_addr = &(base->ENC_ST[offset]) + 0x200 + (offset % 4) * 0x80;
	base->EVENT_S &= 0xFE;
	*enc_st_addr = value;
	while(!(base->EVENT_S & 0x01));
	return base->S_PC_DATA_SAFE;
}

void Slave_Mail_register_writing(HIPERFACE_Type *base, uint8_t value)
{

	volatile uint8_t *enc_st_addr = &(base->MAIL) + 0x300;
	base->EVENT_S &= 0xFE;
	*enc_st_addr = value;
	while(!(base->EVENT_S & 0x01));
}

void Slave_Ping_register_writing(HIPERFACE_Type *base, uint8_t value)
{

	volatile uint8_t *enc_st_addr = &(base->PING) + 0x380;
	base->EVENT_S &= 0xFE;
	*enc_st_addr = value;
	while(!(base->EVENT_S & 0x01));
}

uint8_t Slave_Ping_register_reading(HIPERFACE_Type *base)
{
	volatile uint8_t MY_UNUSED dummy;
	volatile uint8_t const *enc_st_addr = &(base->PING) + 0x380;
	base->EVENT_S &= 0xFE;
	dummy = *enc_st_addr;
	while(!(base->EVENT_S & 0x01));
	return base->S_PC_DATA_SAFE;
}

uint8_t Slave_SRSSI_register_reading(HIPERFACE_Type *base)
{
	volatile uint8_t MY_UNUSED dummy;
	volatile uint8_t const *enc_st_addr = &(base->SRSSI_SAFE) + 0x200;
	base->EVENT_S &= 0xFE;
	dummy = *enc_st_addr;
	while(!(base->EVENT_S & 0x01));
	return base->S_PC_DATA_SAFE;
}
