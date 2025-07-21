/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <inttypes.h>
#include "fsl_endat3.h"
#include "fsl_common.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.endat3"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
__WEAK uint32_t getTimestampMS()
{
	return 0;
}

status_t ENDAT3_RxTxClkConfig(ENDAT3_Type *base, uint32_t clk_sys, uint8_t rate, uint16_t watchdag_us)
{
	uint16_t clkdiv, dec[4];
	uint32_t watchDogVal;

	if (rate == ENDAT3_RXTX_RATE_12_5MBPS) {
		if (clk_sys == 100000000) {
			clkdiv = 8;
			dec[0] = 1;
			dec[1] = 8;
			dec[2] = 9;
			dec[3] = 15;
		}
		else {
			clkdiv = 16;
			dec[0] = 9;
			dec[1] = 18;
			dec[2] = 19;
			dec[3] = 26;
		}
	} else {
		clkdiv = 8;
		dec[0] = 1;
		dec[1] = 8;
		dec[2] = 9;
		dec[3] = 15;
	}

	watchDogVal = watchdag_us * (clk_sys / 1000000);
	base->CONFIG_1 = ENDAT3_CONFIG_1_CFG_CLKDIV(clkdiv);
	base->CONFIG_2 = ENDAT3_CONFIG_2_CFG_DEC_1(dec[1]) | ENDAT3_CONFIG_2_CFG_DEC_0(dec[0]);
	base->CONFIG_3 = ENDAT3_CONFIG_3_CFG_DEC_3(dec[3]) | ENDAT3_CONFIG_3_CFG_DEC_2(dec[2]);
	if (watchDogVal == 0 || watchDogVal > 0xFFFF) {
		base->CONFIG_4 = ENDAT3_CONFIG_4_CFG_WATCHDOG(0xffff);
	} else {
		base->CONFIG_4 = ENDAT3_CONFIG_4_CFG_WATCHDOG(watchDogVal);
	}

	return kStatus_Success;
}

status_t ENDAT3_FG_WaitingMasterReady(ENDAT3_Type *base)
{
	uint8_t fg_status = base->FG_STATUS & 0xFF;

	while (!(fg_status & ENDAT3_FG_STATUS_MASTER_READY_MASK)) {
		fg_status = base->FG_STATUS & 0xFF;
	}

	if (fg_status & (ENDAT3_FG_STATUS_STROBE_ERROR_MASK | ENDAT3_FG_STATUS_WD_ERROR_MASK | ENDAT3_FG_STATUS_PHY_ERROR_MASK | ENDAT3_FG_STATUS_CS_ERROR_MASK)) {
		if (fg_status & ENDAT3_FG_STATUS_STROBE_ERROR_MASK)
			return kStatus_Endat3_FG_Strobe_Error;
		else if (fg_status & ENDAT3_FG_STATUS_WD_ERROR_MASK)
			return kStatus_Endat3_FG_Watchdog_Error;
		else if (fg_status & ENDAT3_FG_STATUS_PHY_ERROR_MASK)
			return kStatus_Endat3_FG_PHY_Error;
		else if (fg_status & ENDAT3_FG_STATUS_CS_ERROR_MASK)
			return kStatus_Endat3_FG_CRC_Error;
	}

	return kStatus_Success;
}

bool ENDAT3_FG_CheckStatus(ENDAT3_Type *base)
{
	if (base->FG_STATUS & (ENDAT3_FG_STATUS_STROBE_ERROR_MASK | ENDAT3_FG_STATUS_WD_ERROR_MASK | ENDAT3_FG_STATUS_PHY_ERROR_MASK | ENDAT3_FG_STATUS_CS_ERROR_MASK))
		return false;
	else
		return true;
}

uint8_t ENDAT3_getRsp(ENDAT3_Type *base, uint8_t bus_addr, endat3_rsp_t *rsp)
{
	struct HPF *hpf = ENDAT3_GET_HPF_ADDR(base, bus_addr);
	struct LPH *lph = ENDAT3_GET_LPH_ADDR(base, bus_addr);
	struct LPF *lpf;
	int i;

	rsp->hpf.hpf64 = hpf->hpf64;
	rsp->lph.lph32 = lph->lph32;
	rsp->ydim = rsp->lph.lph.nlpf & 0xF;
	rsp->xdim = (rsp->lph.lph.nlpf >> 4) & 0xF;
	rsp->zdim = (rsp->lph.lph.status >> 4) & 0x07;
	for (i = 0; i < rsp->xdim; i++) {
		lpf = ENDAT3_GET_LPF_ADDR(base, bus_addr, i);
		rsp->lpf[i].lpf64 = lpf->lpf64;
	}
	return rsp->xdim;
}

status_t ENDAT3_FG_Req_Rsp(ENDAT3_Type *base, uint8_t req, uint16_t data, endat3_rsp_t *rsp)
{
	status_t status;
	ENDAT3_FG_Req(base, req, data);

	if ((status = ENDAT3_FG_WaitingMasterReady(base)) != kStatus_Success) {
		return status;
	}

	if (rsp != NULL)
		ENDAT3_getRsp(base, 0, rsp);

	return kStatus_Success;
}

/* FG Request: Hello */
status_t ENDAT3_FG_Hello(ENDAT3_Type *base)
{
	status_t status;
	uint32_t timeOutMS = getTimestampMS() + ENDAT3_HELLO_TIMEOUT;

	do {
		status = ENDAT3_FG_Req_Rsp(base, ENDAT3_FG_REQ_HELLO, ENDAT3_FG_DATA_HELLO, NULL);

		if (status == kStatus_Success) {
			return kStatus_Success;
		}
	} while (getTimestampMS() < timeOutMS);

	return kStatus_Endat3_FG_Hello_Failed;
}

/*FG Request: Echo */
status_t ENDAT3_FG_Echo(ENDAT3_Type *base, uint16_t arbitrary_data)
{
	endat3_rsp_t rsp;
	status_t status;

	if ((status = ENDAT3_FG_Req_Rsp(base, ENDAT3_FG_REQ_ECHO, arbitrary_data, &rsp)) != kStatus_Success) {
		return status;
	}

	if (ENDAT3_READ_HPF_STATUS_HPFV(rsp.hpf.hpf64) != 0x0) {
		return kStatus_Endat3_FG_ECHO_Failed;
	}

	if (rsp.hpf.hpf.data[1] != 0x0 || rsp.hpf.hpf.data[0] != 0x02) {
		return kStatus_Endat3_FG_ECHO_Failed;
	}

	if (rsp.hpf.hpf.data[5] != (arbitrary_data >> 8) || rsp.hpf.hpf.data[4] != (arbitrary_data & 0xFF)) {
		return kStatus_Endat3_FG_ECHO_Failed;
	}

	return kStatus_Success;
}

/* FG requests for BUS mode */

status_t ENDAT3_FG_Bus_Req_Rsp(ENDAT3_Type *base, uint8_t bus_addr, uint8_t req, uint16_t data, uint8_t busCode, uint16_t busData, endat3_rsp_t *rsp)
{
	status_t status;
	ENDAT3_FG_Bus_Req(base, req, data, busCode, busData);

	if ((status = ENDAT3_FG_WaitingMasterReady(base)) != kStatus_Success) {
		return status;
	}

	if (rsp != NULL)
		ENDAT3_getRsp(base, bus_addr, rsp);

	return kStatus_Success;
}

/* FG Request: Hello */
status_t ENDAT3_FG_Bus_P2P_Hello(ENDAT3_Type *base, uint8_t addr)
{
	status_t status;
	uint32_t timeOutMS = getTimestampMS() + ENDAT3_HELLO_TIMEOUT;

	do {
		status = ENDAT3_FG_Bus_P2P_Req_Rsp(base, addr, ENDAT3_FG_REQ_HELLO, ENDAT3_FG_DATA_HELLO, NULL);

		if (status == kStatus_Success) {
			return kStatus_Success;
		}
	} while (getTimestampMS() < timeOutMS);

	return kStatus_Endat3_FG_Hello_Failed;
}

/*FG Request: Echo */
status_t ENDAT3_FG_Bus_P2P_Echo(ENDAT3_Type *base, uint8_t addr, uint16_t arbitrary_data)
{
	endat3_rsp_t rsp;
	status_t status;

	if ((status = ENDAT3_FG_Bus_P2P_Req_Rsp(base, addr, ENDAT3_FG_REQ_ECHO, arbitrary_data, &rsp)) != kStatus_Success) {
		return status;
	}

	if (ENDAT3_READ_HPF_STATUS_HPFV(rsp.hpf.hpf64) != 0x0) {
		return kStatus_Endat3_FG_ECHO_Failed;
	}

	if (rsp.hpf.hpf.data[1] != 0x0 || rsp.hpf.hpf.data[0] != 0x02) {
		return kStatus_Endat3_FG_ECHO_Failed;
	}

	if (rsp.hpf.hpf.data[5] != (arbitrary_data >> 8) || rsp.hpf.hpf.data[4] != (arbitrary_data & 0xFF)) {
		return kStatus_Endat3_FG_ECHO_Failed;
	}

	return kStatus_Success;
}

/* API interface for BG commnunication*/
void ENDAT3_BG_Req(ENDAT3_Type *base, uint8_t bus_addr, struct BGREQ *req, uint8_t wait_rsp)
{
	uint32_t req_h32 = BSWAP32(req->BGREQ64 & 0xFFFFFFFF); 
	uint32_t req_l32 = BSWAP32(req->BGREQ64 >> 32); 
	uint64_t req64 = ((uint64_t)req_h32 << 32) | req_l32;
	base->BG_REQ_0 = ENDAT3_BG_REQ_0_BG_ADDR(bus_addr);
	base->BG_REQ_1 = ENDAT3_BG_REQ_1_BG_REQ_LO(req64 & 0xFFFFFFFF);
	base->BG_REQ_2 = ENDAT3_BG_REQ_2_BG_REQ_HI(req64 >> 32) | ENDAT3_BG_REQ_2_BG_STROBE(1) | ENDAT3_BG_REQ_2_WAIT_RSP(wait_rsp);
}

void ENDAT3_BG_WaitReqEmpty(ENDAT3_Type *base, uint8_t bus_addr, uint8_t fg_strobes)
{
	while (!(base->BG_RSP_1 & ENDAT3_BG_RSP_1_BG_REQ_EMPTY_MASK)) {
		if (fg_strobes) {
#if (ENDAT3_PARTICIPANTS_NUM > 1)
				ENDAT3_FG_Bus_P2P_Data(base, bus_addr, ENDAT3_FG_REQ_DATA0, NULL);
#else
				ENDAT3_FG_Data(base, ENDAT3_FG_REQ_DATA0, NULL);
#endif
		}
	}
}

status_t ENDAT3_BG_WaitReqFinished(ENDAT3_Type *base, uint8_t bus_addr, uint8_t fg_strobes, uint32_t timeout_ms)
{
	uint32_t timeout = getTimestampMS() + timeout_ms;
	while (!(base->BG_RSP_1 & (ENDAT3_BG_RSP_1_BG_HANDLER_IDLE_MASK | ENDAT3_BG_RSP_1_BG_HANDLER_ERROR_MASK))) {
		if (fg_strobes) {
#if (ENDAT3_PARTICIPANTS_NUM > 1)
			ENDAT3_FG_Bus_P2P_Data(base, bus_addr, ENDAT3_FG_REQ_DATA0, NULL);
#else
			ENDAT3_FG_Data(base, ENDAT3_FG_REQ_DATA0, NULL);
#endif
		}

		if (base->BG_RSP_1 & ENDAT3_BG_RSP_1_BG_HANDLER_ERROR_MASK) {
			return kStatus_Endat3_BG_Handler_Error;
		}

		if (timeout_ms && getTimestampMS() > timeout) {
			return kStatus_Timeout;
		}
	}
	return kStatus_Success;
}

uint64_t ENDAT3_BG_GetRsp(ENDAT3_Type *base)
{
	uint64_t temp = ((base->BG_RSP_1 & ENDAT3_BG_RSP_1_BG_RSP_HI_MASK));
	return ((temp <<32) | base->BG_RSP_0);
}

status_t ENDAT3_BG_Req_Rsp(ENDAT3_Type *base, uint8_t bus_addr, struct BGREQ *req, uint64_t *rsp, uint8_t fg_strobes, uint32_t timeout_ms)
{
	ENDAT3_BG_WaitReqEmpty(base, bus_addr, fg_strobes);
	ENDAT3_BG_Req(base, bus_addr, req, 1);
	ENDAT3_BG_WaitReqFinished(base, bus_addr, fg_strobes, timeout_ms);

	if (base->BG_RSP_1 & ENDAT3_BG_RSP_1_BG_HANDLER_ERROR_MASK) {
		return kStatus_Endat3_BG_Handler_Error;
	}

	*rsp = ENDAT3_BG_GetRsp(base);
	if (base->BG_RSP_1 & ENDAT3_BG_RSP_1_BG_ERR_EXEC_MASK) {
		return kStatus_Endat3_BG_Excute_Error;
	}
	return kStatus_Success;
}

status_t ENDAT3_BG_Nop(ENDAT3_Type *base, uint8_t bus_addr, uint64_t arbitrary, uint64_t *bg_rsp, uint8_t fg_strobes)
{
	struct BGREQ req = {0};

	req.NOP.code = ENDAT3_BG_OPCODE_NOP;
	req.NOP.arbitrary[0] = (arbitrary >> 32) & 0xFF;
	req.NOP.arbitrary[1] = (arbitrary >> 24) & 0xFF;
	req.NOP.arbitrary[2] = (arbitrary >> 16) & 0xFF;
	req.NOP.arbitrary[3] = (arbitrary >> 8) & 0xFF;
	req.NOP.arbitrary[4] = arbitrary & 0xFF;

	return ENDAT3_BG_Req_Rsp(base, bus_addr, &req, bg_rsp, fg_strobes, 2);
}

status_t ENDAT3_BG_Reconfigure(ENDAT3_Type *base, uint8_t bus_addr, uint8_t fg_strobes)
{
	struct BGREQ req = {0};
	uint64_t bg_rsp;

	req.RECONFIGURE.code = ENDAT3_BG_OPCODE_RECONFIGURE;
	req.RECONFIGURE.res1[0] = 0;
	req.RECONFIGURE.res1[1] = 0;
	req.RECONFIGURE.res1[2] = 0;
	req.RECONFIGURE.res1[3] = 0;
	req.RECONFIGURE.res1[4] = 0;
	return ENDAT3_BG_Req_Rsp(base, bus_addr, &req, &bg_rsp, fg_strobes, 100);
}

status_t ENDAT3_BG_Read(ENDAT3_Type *base, uint8_t bus_addr, uint32_t addr, uint8_t num_words, uint16_t *words, uint8_t fg_strobes)
{
	struct BGREQ req = {0};
	uint64_t bg_rsp;
	status_t status;
	req.READ.code = ENDAT3_BG_OPCODE_READ;
	req.READ.addr[0] = (addr >> 16) & 0xFF;
	req.READ.addr[1] = (addr >> 8) & 0xFF;
	req.READ.addr[2] = (addr) & 0xFF;
	req.READ.num_words = num_words;

	status = ENDAT3_BG_Req_Rsp(base, bus_addr, &req, &bg_rsp, fg_strobes, 6);

	if (num_words > 0) {
		words[0] = bg_rsp & 0xFFFF;
	}

	if (num_words > 1) {
		words[1] = (bg_rsp >> 16) & 0xFFFF;
	}

	if (num_words > 2) {
		words[2] = (bg_rsp >> 32) & 0xFFFF;
	}

	return status;
}

status_t ENDAT3_BG_Write(ENDAT3_Type *base, uint8_t bus_addr, uint32_t addr, const uint16_t word, uint8_t fg_strobes)
{
	struct BGREQ req = {0};
	uint64_t bg_rsp;

	req.WRITE.code = ENDAT3_BG_OPCODE_WRITE;
	req.WRITE.addr[0] = (addr >> 16) & 0xFF;
	req.WRITE.addr[1] = (addr >> 8) & 0xFF;
	req.WRITE.addr[2] = (addr) & 0xFF;
	req.WRITE.data[0] = (word >> 8) & 0xFF;
	req.WRITE.data[1] = (word) & 0xFF;

	return ENDAT3_BG_Req_Rsp(base, bus_addr, &req, &bg_rsp, fg_strobes, 10);
}

status_t ENDAT3_BG_Auth(ENDAT3_Type *base, uint8_t bus_addr, uint8_t usrlevel, uint32_t pass, uint8_t fg_strobes)
{
	struct BGREQ req = {0};
	uint64_t bg_rsp;
	req.AUTH.code = ENDAT3_BG_OPCODE_AUTH;
	req.AUTH.usrlevel = usrlevel;
	req.AUTH.pass = BSWAP32(pass);
	return ENDAT3_BG_Req_Rsp(base, bus_addr, &req, &bg_rsp, fg_strobes, 20);
}

status_t ENDAT3_BG_Setpass(ENDAT3_Type *base, uint8_t bus_addr, uint8_t usrlevel, uint32_t pass, uint8_t fg_strobes)
{
	struct BGREQ req = {0};
	uint64_t bg_rsp;
	req.SETPASS.code = ENDAT3_BG_OPCODE_SETPASS;
	req.SETPASS.usrlevel = usrlevel;
	req.SETPASS.pass = BSWAP32(pass);
	return ENDAT3_BG_Req_Rsp(base, bus_addr, &req, &bg_rsp, fg_strobes, 20);
}

status_t ENDAT3_BG_Protect(ENDAT3_Type *base, uint8_t bus_addr, uint32_t addr, uint8_t mode, const uint8_t acclevel, uint8_t *al_write, uint8_t *al_read, uint8_t fg_strobes)
{
	struct BGREQ req = {0};
	uint64_t bg_rsp;
	status_t status;
	req.PROTECT.code = ENDAT3_BG_OPCODE_PROTECT;
	req.PROTECT.address[0] = (addr >> 16) & 0xFF;
	req.PROTECT.address[1] = (addr >> 8) & 0xFF;
	req.PROTECT.address[2] = (addr) & 0xFF;
	req.PROTECT.mode = mode;
	req.PROTECT.acclevel = acclevel;

	status = ENDAT3_BG_Req_Rsp(base, bus_addr, &req, &bg_rsp, fg_strobes, 20);

	*al_write = (bg_rsp >> 8) & 0xFF;
	*al_read  = bg_rsp & 0xFF;

	return status;
}

status_t ENDAT3_BG_Locate(ENDAT3_Type *base, uint8_t bus_addr, uint8_t ctrl, uint8_t fg_strobes)
{
	struct BGREQ req = {0};
	uint64_t bg_rsp;
	req.LOCATE.code = ENDAT3_BG_OPCODE_LOCATE;
	req.LOCATE.ctrl = ctrl;
	return ENDAT3_BG_Req_Rsp(base, bus_addr, &req, &bg_rsp, fg_strobes, 20);
}

status_t ENDAT3_memRead(ENDAT3_Type *base, uint8_t bus_addr, uint32_t addr,  uint16_t n_words, uint16_t *pbuf, uint8_t fg_strobes)
{
	int n;
	uint16_t words[3];
	status_t status;

	while (n_words > 0) {

		/* 3 words for one BG read request*/
		if (n_words > 3) {
			n = 3;
			n_words -= 3;
		} else {
			n = n_words;
			n_words = 0;
		}

		if ((status = ENDAT3_BG_Read(base, bus_addr, addr, n, words, fg_strobes)) != kStatus_Success) {
			return status;
		}

		memcpy(pbuf, words, n * sizeof(n_words));
		pbuf += n;
		addr += n;
	}
	return kStatus_Success;
}

status_t ENDAT3_memWrite(ENDAT3_Type *base, uint8_t bus_addr, uint32_t addr,  uint16_t n_words, uint16_t *pbuf, uint8_t fg_strobes)
{
	status_t status;
	while (n_words > 0) {
		if ((status = ENDAT3_BG_Write(base, bus_addr, addr, *pbuf, fg_strobes)) != kStatus_Success) {
			return status;
		}
		addr++;
		n_words--;
		pbuf++;
	}

	return kStatus_Success;
}

status_t ENDAT3_memCacheInit(ENDAT3_Type *base, uint8_t bus_addr, uint32_t mem_base, endat3_mem_cache_t *cache, uint16_t *pbuf, uint32_t pbufSize, uint8_t fg_strobes)
{
	cache->memBase = mem_base;
	cache->cacheMem = pbuf;
	cache->cacheMemSize = pbufSize;
	cache->memSize = ENDAT3_memGetRangeSize(base, bus_addr, mem_base, fg_strobes);
	if (cache->memSize == 0) {
		return kStatus_Endat3_MEM_Cache_Not_Initialized;
	}

	if (cache->memSize > pbufSize || cache->memSize > MAX_MEMORY_AREA_SIZE) {
		return kStatus_Endat3_MEM_Cache_Size_Exceeded;
	}
	memset(cache->dirtyWordMap, 0, sizeof(uint32_t) * MAX_MEMORY_AREA_SIZE/32);
	return kStatus_Success;
}

void ENDAT3_memCacheSetDirty(endat3_mem_cache_t *cache, int word_index, int isDirty)
{
	uint32_t mod_index, mod_bit;
	mod_index = (word_index / 32);
	mod_bit = word_index % 32;
	if (isDirty)
		cache->dirtyWordMap[mod_index] |= (1 << mod_bit);
	else
		cache->dirtyWordMap[mod_index] &= ~(1 << mod_bit);
}

int ENDAT3_memCacheDirty(endat3_mem_cache_t *cache, int word_index)
{
	uint32_t mod_index, mod_bit;
	mod_index = (word_index / 32);
	mod_bit = word_index % 32;

	return cache->dirtyWordMap[mod_index] & (1 << mod_bit);
}

status_t ENDAT3_memCacheFlush(ENDAT3_Type *base, uint8_t bus_addr, endat3_mem_cache_t *cache, uint8_t fg_strobes)
{
	int i;
	status_t status;
	for (i = 0; i < cache->memSize; i++) {
		if (ENDAT3_memCacheDirty(cache, i)) {
			status = ENDAT3_BG_Write(base, bus_addr, cache->memBase + i, cache->cacheMem[i], fg_strobes);
			if (status != kStatus_Success) {
				return status;
			}
			ENDAT3_memCacheSetDirty(cache, i, 0);
		}
	}
	return kStatus_Success;
}

status_t ENDAT3_memCacheFetch(ENDAT3_Type *base, uint8_t bus_addr, endat3_mem_cache_t *cache, uint8_t fg_strobes)
{
	status_t status;
	if ((status = ENDAT3_memRead(base, bus_addr, cache->memBase, cache->memSize, cache->cacheMem, fg_strobes)) != kStatus_Success) {
		return status;
	}
	memset(cache->dirtyWordMap, 0, sizeof(uint32_t) * MAX_MEMORY_AREA_SIZE/32);
	return status;
}

uint16_t ENDAT3_memGetRangeSize(ENDAT3_Type *base, uint8_t bus_addr, uint32_t mem_base, uint8_t fg_strobes)
{
	uint32_t addr;
	uint16_t size;

	mem_base &= ~0xFFFF;
	switch (mem_base) {
		case ENDAT3_MEM_BASE_EL:
			addr = ENDAT3_MEM_EL_ELSIZE_OFFSET; break;
		case ENDAT3_MEM_BASE_XEL:
			addr = ENDAT3_MEM_EL_XELSIZE_OFFSET; break;
		case ENDAT3_MEM_BASE_SET:
			addr = ENDAT3_MEM_EL_SETSIZE_OFFSET; break;
		case ENDAT3_MEM_BASE_XSET:
			addr = ENDAT3_MEM_EL_XSETSIZE_OFFSET; break;
		case ENDAT3_MEM_BASE_LPFSET:
			addr = ENDAT3_MEM_EL_LPFSETSIZE_OFFSET; break;
		case ENDAT3_MEM_BASE_OEM1:
			addr = ENDAT3_MEM_EL_OEM1SIZE_OFFSET; break;
		case ENDAT3_MEM_BASE_OEM2:
			addr = ENDAT3_MEM_EL_OEM2SIZE_OFFSET; break;
		case ENDAT3_MEM_BASE_OEM3:
			addr = ENDAT3_MEM_EL_OEM3SIZE_OFFSET; break;
		case ENDAT3_MEM_BASE_SENSORS:
			addr = ENDAT3_MEM_EL_SENSORSSIZE_OFFSET; break;
		case ENDAT3_MEM_BASE_LPFLIVE:
			addr = ENDAT3_MEM_EL_LPFLIVESIZE_OFFSET; break;
		case ENDAT3_MEM_BASE_FEATURE:
			addr = ENDAT3_MEM_FEATURE_SIZE_OFFSET; break;
		case ENDAT3_MEM_BASE_FEATURE1:
			addr = ENDAT3_MEM_FEATURE1_SIZE_OFFSET; break;
		case ENDAT3_MEM_BASE_FEATURE2:
			addr = ENDAT3_MEM_FEATURE2_SIZE_OFFSET; break;
		default: return 0;

	}

	if (ENDAT3_memRead(base, bus_addr, addr, 1, &size, fg_strobes) != kStatus_Success) {
		return 0;
	}

	return size;
}

static uint32_t ENDAT3_memCalcCSReflect(uint32_t data, uint32_t bitnum)
{
	uint32_t i;
	uint32_t j = 1;
	uint32_t data_out = 0;

	for (i = (uint32_t)1 << (bitnum-1); i > 0; i = i >> 1) {
		if (data & i) {
			data_out = data_out | j;
		}

		j = j << 1;
	}

	return data_out;
}

static uint32_t ENDAT3_memCalcCS(uint16_t *p, const uint16_t len)
{
	const uint32_t order      = 32;
	const uint32_t polynom    = 0x04C11DB7;
	const uint32_t init_value = 0xFFFFFFFF;
	const uint32_t xor_value  = 0xFFFFFFFF;
	const uint32_t high_bit   = (uint32_t)1 << (order - 1);

	uint32_t i;
	uint32_t j;
	uint32_t c;
	uint32_t bit;
	uint32_t cs = init_value;

	for (i = 0; i < len; i++) {
		c = (uint32_t)p[i];
		c = ENDAT3_memCalcCSReflect(c, 16);

		for (j = 0x8000; j > 0; j = j >> 1) {
			bit = cs & high_bit;
			cs = cs << 1;
			if (c & j) {
				bit = bit ^ high_bit;
			}

			if (bit) {
				cs = cs ^ polynom;
			}
		}
	}

	cs = ENDAT3_memCalcCSReflect(cs, order);
	cs = cs ^ xor_value;

	return cs;
}

status_t ENDAT3_memCacheCheckCS(endat3_mem_cache_t *cache)
{
	uint32_t cs_calc= ENDAT3_memCalcCS(&cache->cacheMem[2], cache->memSize - 2);
	uint32_t cs_stored = (cache->cacheMem[1] << 16) + cache->cacheMem[0];
	if (cs_stored != cs_calc) {
		return kStatus_Endat3_MEM_Cache_Wrong_CS;
	}
	return kStatus_Success;
}

status_t ENDAT3_memCacheUpdataCS(endat3_mem_cache_t *cache)
{
	uint32_t cs_calc= ENDAT3_memCalcCS(&cache->cacheMem[2], cache->memSize - 2);

	cache->cacheMem[0] = cs_calc & 0xFFFF;
	cache->cacheMem[1] = (cs_calc >> 16) & 0xFFFF;
	ENDAT3_memCacheSetDirty(cache, 0, 1);
	ENDAT3_memCacheSetDirty(cache, 1, 1);
	return kStatus_Success;
}

uint16_t  ENDAT3_lpfCacheGetPointer(uint8_t z, endat3_mem_cache_t *lpf_cache)
{
	return *(lpf_cache->cacheMem + ENDAT3_MEM_LPFSET_LPFLIVE_HEAD_POINTER_1_OFFSET + z - 1);
}

void ENDAT3_lpfCacheGetXdimYdim(uint8_t z, endat3_mem_cache_t *lpf_cache, uint8_t *xdim, uint8_t *y_dim)
{
	uint8_t z_list = z - 1;
	uint16_t temp;
	temp = *(lpf_cache->cacheMem + ENDAT3_MEM_LPFSET_LPFLIVE_HEAD_YDIM_1_OFFSET + z_list / 2);
	temp = temp >> ((z_list % 2) * 8);
	*y_dim = (temp & 0xF) + 1;
	*xdim = (temp >> 4) & 0xF;
}

void ENDAT3_lpfCacheSetPointer(uint8_t z, endat3_mem_cache_t *lpf_cache, uint16_t pointer)
{
	ENDAT3_memCacheSetDirty(lpf_cache, ENDAT3_MEM_LPFSET_LPFLIVE_HEAD_POINTER_1_OFFSET  + z - 1, 1);
	*(lpf_cache->cacheMem + ENDAT3_MEM_LPFSET_LPFLIVE_HEAD_POINTER_1_OFFSET  + z - 1) = pointer;
}

void ENDAT3_lpfCacheSetXdimYdim(uint8_t z, endat3_mem_cache_t *lpf_cache, uint8_t xdim, uint8_t y_dim)
{
	uint8_t z_list, xy_dim, *addr;
	if (y_dim == 0) {
		return;
	}
	z_list = z - 1;
	xy_dim = (xdim << 4) | ((y_dim - 1) & 0xF);
	addr = (uint8_t *)(lpf_cache->cacheMem + ENDAT3_MEM_LPFSET_LPFLIVE_HEAD_YDIM_1_OFFSET + z_list / 2);
	ENDAT3_memCacheSetDirty(lpf_cache, ENDAT3_MEM_LPFSET_LPFLIVE_HEAD_YDIM_1_OFFSET  + z_list / 2, 1);
	addr += z_list % 2;
	*addr = xy_dim;
}

void ENDAT3_lpfCacheListSetFid(endat3_mem_cache_t *lpf_cache, uint8_t xdim, uint8_t x, uint8_t y, uint16_t pointer, uint8_t fid)
{
	uint8_t *addr = (uint8_t *)(lpf_cache->cacheMem + ENDAT3_LPF_HEAD_SIZE_WORDS) + pointer;
	ENDAT3_memCacheSetDirty(lpf_cache, ENDAT3_LPF_HEAD_SIZE_WORDS  + (pointer + y * xdim + x)/ 2, 1);
	addr += y * xdim + x;
	*addr = fid;
}

void ENDAT3_lpfCacheListSetSendlist(endat3_mem_cache_t *lpf_cache, uint8_t z, uint8_t xdim, uint8_t ydim, uint16_t pointer, uint8_t *fids)
{
	uint8_t x, y;
	ENDAT3_lpfCacheSetPointer(z, lpf_cache, pointer);
	ENDAT3_lpfCacheSetXdimYdim(z, lpf_cache, xdim, ydim);
	for(y = 0;y < ydim; y++) {
		for (x = 0; x < xdim; x++) {
			ENDAT3_lpfCacheListSetFid(lpf_cache, xdim, x, y, pointer, fids[y * xdim + x]);
		}
	}
}

uint8_t ENDAT3_lpfCacheListGetFid(endat3_mem_cache_t *lpf_cache, uint8_t xdim, uint8_t x, uint8_t y, uint16_t pointer)
{
	uint8_t *addr = (uint8_t *)(lpf_cache->cacheMem + ENDAT3_LPF_HEAD_SIZE_WORDS) + pointer;
	addr += y * xdim + x;
	return *addr;
}

status_t ENDAT3_lpfCacheUpdateFromEnconder(ENDAT3_Type *base, uint8_t bus_addr, endat3_mem_cache_t *lpf_cache, uint16_t *pdat, uint32_t pdat_size, uint8_t from_set, uint8_t fg_strobes)
{
	uint32_t mem_actual_size;
	status_t status;
	if (from_set) {
		mem_actual_size = ENDAT3_memGetRangeSize(base, bus_addr, ENDAT3_MEM_BASE_LPFSET, fg_strobes);
		lpf_cache->memBase = ENDAT3_MEM_BASE_LPFSET;
	} else {
		mem_actual_size = ENDAT3_memGetRangeSize(base, bus_addr, ENDAT3_MEM_BASE_LPFLIVE, fg_strobes);
		lpf_cache->memBase = ENDAT3_MEM_BASE_LPFLIVE;
	}

	if (mem_actual_size > pdat_size) {
		return kStatus_Endat3_MEM_Cache_Out_Of_Size;
	}

	lpf_cache->memSize = mem_actual_size;
	lpf_cache->cacheMem = pdat;

	if ((status = ENDAT3_memCacheFetch(base, bus_addr, lpf_cache, fg_strobes)) != kStatus_Success) {
		return status;
	}

	status = ENDAT3_memCacheCheckCS(lpf_cache);
	return status;
}

status_t ENDAT3_lpfCacheFlushToEncoder(ENDAT3_Type *base, uint8_t bus_addr, endat3_mem_cache_t *lpf_cache, uint8_t fg_strobes)
{
	ENDAT3_memCacheUpdataCS(lpf_cache);
	return ENDAT3_memCacheFlush(base, bus_addr, lpf_cache, fg_strobes);
}

void ENDAT3_lpfCacheListUpdate(endat3_mem_cache_t *global_cache, endat3_mem_cache_t *lpf_cache, uint8_t z, uint8_t xdim, uint8_t ydim, uint16_t pointer, uint8_t *fid)
{
	int32_t i,j;
	ENDAT3_lpfCacheSetPointer(z, global_cache, pointer);
	ENDAT3_lpfCacheSetXdimYdim(z, global_cache, xdim, ydim);
	for (i = 0; i < ydim; i++) {
		for (j = 0; j < xdim; j++) {
			ENDAT3_lpfCacheListSetFid(lpf_cache, xdim, j, i, pointer, fid[i*ydim + j]);
		}
	}
}

/* FID_BASED_MEM API */
status_t ENDAT3_FIDMEM_getLpf(ENDAT3_Type *base, uint8_t bus_addr, uint8_t fid, struct FID *fid_res)
{
	struct FID *temp =  ENDAT3_GET_FID_ADDR(base, bus_addr, fid);
	memcpy (fid_res, temp, sizeof(struct FID));
	return kStatus_Success;
}

uint8_t ENDAT3_FIDMEM_getTimestamp(ENDAT3_Type *base, uint8_t bus_addr, uint8_t fid)
{

	struct FID *temp =  ENDAT3_GET_FID_ADDR(base, bus_addr, fid);
	return temp->fid.timeStamp;
}


uint8_t ENDAT3_lpfGetLPFVByFID(ENDAT3_Type *base, uint8_t bus_addr, uint8_t fid)
{

	struct FID *temp =  ENDAT3_GET_FID_ADDR(base, bus_addr, fid);
	return temp->fid.lpfv;
}

uint64_t ENDAT3_FIDMEM_getData(ENDAT3_Type *base, uint8_t bus_addr, uint8_t fid)
{

	struct FID *temp =  ENDAT3_GET_FID_ADDR(base, bus_addr, fid);
	return ENDAT3_READ_FID_LPF_DATA(temp->fid64);
}

/* Assign bus address for all encoders */
status_t ENDAT3_Bus_Assign_Address(ENDAT3_Type *base, uint8_t encoderNum)
{
	int i;
	status_t status;
	uint16_t cache_buf[0x100];
	endat3_mem_cache_t mem_cache;

	for (i = encoderNum; i > 0; i--) {
		if ((status = ENDAT3_memCacheInit(base, 0, ENDAT3_MEM_BASE_SET, &mem_cache, cache_buf, 0x100, 1)) != kStatus_Success)
			return status;
		if ((status = ENDAT3_memCacheFetch(base, 0, &mem_cache, 1)) != kStatus_Success)
			return status;
		if ((status = ENDAT3_memCacheCheckCS(&mem_cache)) != kStatus_Success)
			return status;

		ENDAT3_MEM_CACHE_WRITE_SET_BUSADDRESS(&mem_cache, i);
		if ((status = ENDAT3_lpfCacheFlushToEncoder(base, 0, &mem_cache, 1)) != kStatus_Success)
			return status;
		if ((status = ENDAT3_FG_Bus_P2P_Reset(base, 0)) != kStatus_Success)
			return status;
		if ((status = ENDAT3_FG_Bus_P2P_Hello(base, i)) != kStatus_Success)
			return status;
	}
	return kStatus_Success;
}

char* ENDAT3_FID2str(const uint8_t fid)
{
	switch (fid) {
		case 0x00: return "NOP"            ; break;
		case 0x01: return "POS1"           ; break;
		case 0x02: return "POS2"           ; break;
		case 0x03: return "TOUCHPROBE"     ; break;
		case 0x04: return "POS_ABS"        ; break;
		case 0x05: return "ZERODATA"       ; break;
		case 0x0A: return "ERRMSG"         ; break;
		case 0x11: return "EVALNUM"        ; break;
		case 0x12: return "MOUNT0"         ; break;
		case 0x13: return "MOUNT1"         ; break;
		case 0x1A: return "COMMU"          ; break;
		case 0x20: return "SENSOR_TEMP_MAX"; break;
		case 0x21: return "SENSOR_TEMP_INT"; break;
		case 0x22: return "SENSOR_TEMP_M1" ; break;
		case 0x23: return "SENSOR_TEMP_M2" ; break;
		case 0x24: return "SENSOR_TEMP_M3" ; break;
		case 0x50: return "SF_POS1"        ; break;
		case 0x60: return "BGRSP"          ; break;
		case 0x68: return "BGREQ"          ; break;
		case 0x70: return "BUS_ADDR"       ; break;
	}
	return "UNKNOWN FID";
}

char *ENDAT3_Err2str(uint16_t errCode)
{
	switch (errCode)
	{
		// Foreground error codes
		case 0x0001: return "FGERR_RECONFIGURE"                     ; break;
		case 0x0002: return "FGERR_ECHO"                            ; break;
		case 0x0100: return "FGERR_INVALID_FID"                     ; break;
		case 0x0101: return "FGERR_DUPLICATE_FID"                   ; break;
		case 0x0200: return "FGERR_INVALID_DATA"                    ; break;
		case 0x0201: return "FGERR_INT_TRM"                         ; break;
		case 0x0300: return "FGERR_NO_SENSOR_DATA"                  ; break;

		// Background error codes
		case 0x1100: return "BGERR_USAGE"                           ; break;
		case 0x1101: return "BGERR_USAGE_OPCODE"                    ; break;
		case 0x1102: return "BGERR_USAGE_ARGUMENTS"                 ; break;
		case 0x1103: return "BGERR_USAGE_SEQUENCE"                  ; break;
		case 0x1104: return "BGERR_USAGE_ACCESS_DENIED"             ; break;
		case 0x1105: return "BGERR_USAGE_MEM_ADDRESS"               ; break;
		case 0x1106: return "BGERR_USAGE_NO_BG"                     ; break;
		case 0x1200: return "BGERR_BGERR_INTERNAL"                  ; break;
		case 0x1201: return "BGERR_BGERR_INTERNAL_MEMORY"           ; break;

		// C-API error codes
		case 0x8100: return "APIERR_ACTIVATION_HELLO_FAILED"        ; break;
		case 0x8101: return "APIERR_INIT_WRONG_CLK_FREQ"            ; break;
		case 0x8200: return "APIERR_FG_TRM_ERROR"                   ; break;
		case 0x8201: return "APIERR_FG_WATCHDOG_ERROR"              ; break;
		case 0x8300: return "APIERR_BG_PROC_ERROR"                  ; break;
		case 0x8301: return "APIERR_BG_ERR_EXEC"                    ; break;
		case 0x8400: return "APIERR_MEM_NOT_A_BASE_ADDRESS"         ; break;
		case 0x8401: return "APIERR_MEM_CACHE_SIZE_EXCEEDED"        ; break;
		case 0x8402: return "APIERR_MEM_CACHE_NOT_INITIALIZED"      ; break;
		case 0x8403: return "APIERR_MEM_CACHE_WRONG_BASE"           ; break;
		case 0x8404: return "APIERR_MEM_CACHE_OUT_OF_SIZE"          ; break;
		case 0x8405: return "APIERR_MEM_CACHE_WRONG_CS"             ; break;
		case 0x8500: return "APIERR_LPF_DATA_SIZE_EXCEEDED"         ; break;
		case 0x8501: return "APIERR_LPF_LIST_NOT_CONFIGURABLE"      ; break;
		case 0x8502: return "APIERR_LPF_LIST_ALREADY_CONFIGURED"    ; break;
		case 0x8503: return "APIERR_LPF_INVALID_FID_LOCATION"       ; break;
		case 0x8504: return "APIERR_LPF_INVALID_XY"                 ; break;
		case 0x8505: return "APIERR_LPF_LIST_SIZE_EXCEEDED"         ; break;

		// DLL error codes
		case 0x9000: return "DLLERR_OPEN_CONNECTION_FIRST"          ; break;
		case 0x9001: return "DLLERR_OPEN_ARGUMENT_NOT_OK"           ; break;
		case 0x9002: return "DLLERR_FTDI_DLL_NOT_FOUND"             ; break;
		case 0x9003: return "DLLERR_DLL_USB_CONNECTION_ALREADY_OPEN"; break;
		case 0x9004: return "DLLERR_EVALBOARD_NOT_FOUND_ON_USB"     ; break;
		case 0x9005: return "DLLERR_EVALBOARD_NOT_CONNECTED"        ; break;
		case 0x9006: return "DLLERR_GUI_USB_CONNECTION_NOT_OPEN"    ; break;
		case 0x9007: return "DLLERR_GUI_NOT_OPEN_ANY_MORE"          ; break;
		case 0x9008: return "DLLERR_WRONG_ADDRESS"                  ; break;
		case 0x9009: return "DLLERR_WRONG_API_VERSION"              ; break;
	}

	return "ERR_UNKNOWN";
}
