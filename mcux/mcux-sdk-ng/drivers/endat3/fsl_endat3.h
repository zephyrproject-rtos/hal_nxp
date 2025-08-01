/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_ENDAT3_H
#define FSL_ENDAT3_H

#include "fsl_common.h"
#include "endat3_mem_defs.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*! @{ */
/*! @brief ENDAT3 driver version. */
#define FSL_ENDAT3_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))

#ifndef BSWAP32
#define BSWAP32 __REV
#endif

typedef struct _endat3_dev
{
	uint8_t bus_addr;	//0: No bus; 1~0xFD: valid bus addresses
	ENDAT3_Type *base;
} endat3_dev;

enum {
	kStatus_Endat3_FG_Hello_Failed = MAKE_STATUS(kStatusGroup_ENDAT3, 0),
	kStatus_Endat3_FG_ECHO_Failed = MAKE_STATUS(kStatusGroup_ENDAT3, 0),
	kStatus_Endat3_FG_Strobe_Error = MAKE_STATUS(kStatusGroup_ENDAT3, 1),
	kStatus_Endat3_FG_Watchdog_Error = MAKE_STATUS(kStatusGroup_ENDAT3, 2),
	kStatus_Endat3_FG_PHY_Error = MAKE_STATUS(kStatusGroup_ENDAT3, 3),
	kStatus_Endat3_FG_CRC_Error = MAKE_STATUS(kStatusGroup_ENDAT3, 4),
	kStatus_Endat3_FG_HPF_W_Error = MAKE_STATUS(kStatusGroup_ENDAT3, 5),
	kStatus_Endat3_FG_HPF_F_Error = MAKE_STATUS(kStatusGroup_ENDAT3, 6),

	kStatus_Endat3_BG_Handler_Error = MAKE_STATUS(kStatusGroup_ENDAT3, 7),
	kStatus_Endat3_BG_Excute_Error = MAKE_STATUS(kStatusGroup_ENDAT3, 8),

	kStatus_Endat3_MEM_Cache_Size_Exceeded = MAKE_STATUS(kStatusGroup_ENDAT3, 9),
	kStatus_Endat3_MEM_Cache_Not_Initialized = MAKE_STATUS(kStatusGroup_ENDAT3, 10),
	kStatus_Endat3_MEM_Cache_Wrong_Base = MAKE_STATUS(kStatusGroup_ENDAT3, 11),
	kStatus_Endat3_MEM_Cache_Out_Of_Size = MAKE_STATUS(kStatusGroup_ENDAT3, 12),
	kStatus_Endat3_MEM_Cache_Wrong_CS = MAKE_STATUS(kStatusGroup_ENDAT3, 13),
	kStatus_Endat3_LPF_Data_Size_Exceeded = MAKE_STATUS(kStatusGroup_ENDAT3, 14),
	kStatus_Endat3_LPF_List_Not_Configurable = MAKE_STATUS(kStatusGroup_ENDAT3, 15),
	kStatus_Endat3_LPF_List_Already_Configured = MAKE_STATUS(kStatusGroup_ENDAT3, 16),
	kStatus_Endat3_LPF_Invalid_FID_Location = MAKE_STATUS(kStatusGroup_ENDAT3, 17),
	kStatus_Endat3_LPF_Invalid_XY = MAKE_STATUS(kStatusGroup_ENDAT3, 18),
	kStatus_Endat3_LPF_List_Size_Exceeded = MAKE_STATUS(kStatusGroup_ENDAT3, 19)
};

enum {
	BIM_BG_ERR_EXEC = 0x01,
	BIM_BG_RSP_DATA_UPDATED = 0x02,
	BIM_BG_REQ_EMPTY = 0x08,
	BIM_BG_HANDLER_IDLE = 0x10,
	BIM_BG_HANDLER_REQ = 0x20,
	BIM_BG_HANDLER_RSP = 0x40,
	BIM_BG_HANDLER_ERROR = 0x80
};

enum {
	FIxM_MASTER_READY =0x01,
	FIxM_HPFF = 0x4,
	FIxM_HPFW = 0x08,
	FIxM_CS_ERROR = 0x10,
	FIxM_PHY_ERROR = 0x20,
	FIxM_WD_ERROR = 0x40,
	FIxM_STROBE_ERROR = 0x80,
	FIxM_NEW_SAFETY_PACKET = 0x200000,
	FIxM_ADDR_CNT_EN = 0x40000000,
	FIxM_FRAME_CNT_EN = 0x80000000
};

enum {
	CLEAR_FG_IRQ2 = 0x08,
	CLEAR_FG_IRQ1 = 0x04,
	CLEAR_FG_IRQ0 = 0x02,
	CLEAR_BG_IRQ = 0x01
};

enum {
	ENDAT3_RXTX_RATE_25MBPS = 0x0,
	ENDAT3_RXTX_RATE_12_5MBPS,
};

__PACKED_STRUCT HPF {
	__PACKED_UNION {
		__PACKED_STRUCT {
			uint8_t data[6];
			uint8_t status;
			uint8_t cs;
		}hpf;
		uint64_t hpf64;
	};
} __packed;

__PACKED_STRUCT LPF
{
	__PACKED_UNION {
		__PACKED_STRUCT {
			uint8_t status;
			uint8_t data[6];
			uint8_t cs;
		}lpf;
		uint64_t lpf64;
	};
};

__PACKED_STRUCT LPH
{
	__PACKED_UNION {
		__PACKED_STRUCT {
			uint8_t status;
			uint8_t nlpf;
			uint8_t reserved;
			uint8_t cs;
		} lph;
		uint32_t lph32; //uint64_t lpf32; ?? need to check
	};
};

__PACKED_STRUCT FID
{
	__PACKED_UNION {
		__PACKED_STRUCT {
			uint8_t timeStamp;
			uint8_t lpfv;
			uint8_t lpf_data[6];
		} fid;
		uint64_t fid64;
	};
};

struct BGREQ
{
	__PACKED_UNION {
		__PACKED_STRUCT {
			uint8_t res0[2];
			uint8_t code;
			uint8_t arbitrary[5];
		} NOP;
		__PACKED_STRUCT {
			uint8_t res0[2];
			uint8_t code;
			uint8_t addr[3];
			uint8_t res1;
			uint8_t num_words;
		} READ;
		__PACKED_STRUCT {
			uint8_t res0[2];
			uint8_t code;
			uint8_t addr[3];
			uint8_t data[2];
		} WRITE;
		__PACKED_STRUCT {
			uint8_t res0[2];
			uint8_t code;
			uint8_t res1[5];
		} RECONFIGURE;
		__PACKED_STRUCT {
			uint8_t res0[2];
			uint8_t code;
			uint8_t usrlevel;
			uint32_t pass;
		} AUTH;
		__PACKED_STRUCT {
			uint8_t res0[2];
			uint8_t code;
			uint8_t address[3];
			uint8_t mode;
			uint8_t acclevel;
		} PROTECT;
		__PACKED_STRUCT {
			uint8_t res0[2];
			uint8_t code;
			uint8_t usrlevel;
			uint32_t pass;
		} SETPASS;
		__PACKED_STRUCT {
			uint8_t res0[2];
			uint8_t code;
			uint8_t res1[4];
			uint8_t ctrl;
		} LOCATE;
		uint64_t BGREQ64;
	};
};

typedef struct _Endat3_res
{
	uint8_t xdim;
	uint8_t ydim;
	uint8_t zdim;
	struct HPF hpf;
	struct LPH lph;
	struct LPF lpf[15];
} endat3_rsp_t;

#define MAX_MEMORY_AREA_SIZE	 0x100

typedef struct {
	uint32_t memBase;
	uint32_t memSize;
	uint16_t *cacheMem;
	uint32_t cacheMemSize;
	uint32_t dirtyWordMap[MAX_MEMORY_AREA_SIZE/32];
} endat3_mem_cache_t;

// EnDat 3 Foreground Request Codes
#define ENDAT3_FG_REQ_DATA0			  	0x00
#define ENDAT3_FG_REQ_DATA1			  	0x01
#define ENDAT3_FG_REQ_DATA2			  	0x02
#define ENDAT3_FG_REQ_DATA3			  	0x03
#define ENDAT3_FG_REQ_DATA4				0x04
#define ENDAT3_FG_REQ_DATA5			  	0x05
#define ENDAT3_FG_REQ_DATA6			  	0x06
#define ENDAT3_FG_REQ_DATA7			  	0x07
#define ENDAT3_FG_REQ_DATA			   	0x08
#define ENDAT3_FG_REQ_DATANOP			0x09
#define ENDAT3_FG_REQ_RESET			  	0x0B
#define ENDAT3_FG_REQ_CLEAR			  	0x0C
#define ENDAT3_FG_REQ_ECHO			   	0x0E
#define ENDAT3_FG_REQ_RATE			   	0x10
#define ENDAT3_FG_REQ_HELLO			  	0x22
#define ENDAT3_FG_REQ_BUSBC			  	0x80
#define ENDAT3_FG_REQ_BUSP2P			0x81
#define ENDAT3_FG_REQ_BUSINIT			0x82
#define ENDAT3_FG_REQ_FORCE			  	0x90

#define ENDAT3_FG_DATA_HELLO  			0x2222
#define ENDAT3_FG_DATA_RESET  			0xBBBB
#define ENDAT3_FG_DATA_RATE_12_5MBPS  	0x0001
#define ENDAT3_FG_DATA_RATE_25MBPS		0x0000
#define ENDAT3_FG_DATA_ClearF			0x0000
#define ENDAT3_FG_DATA_ClearW			0x0001
#define ENDAT3_FG_DATA_ClearREF			0x0002
#define ENDAT3_FG_DATA_BUSINIT			0x8282

// EnDat 3 Frame Identifiers (FIDs)
#define ENDAT3_FID_NOP				   	0x00
#define ENDAT3_FID_POS1				  	0x01
#define ENDAT3_FID_POS2				  	0x02
#define ENDAT3_FID_TOUCHPROBE			0x03
#define ENDAT3_FID_POS_ABS			   	0x04
#define ENDAT3_FID_ZERODATA			  	0x05
#define ENDAT3_FID_ERRMSG				0x0A
#define ENDAT3_FID_EVALNUM			   	0x11
#define ENDAT3_FID_MOUNT0				0x12
#define ENDAT3_FID_MOUNT1				0x13
#define ENDAT3_FID_COMMU				0x1A
#define ENDAT3_FID_SENSOR_TEMP_MAX	   	0x20
#define ENDAT3_FID_SENSOR_TEMP_INT	   	0x21
#define ENDAT3_FID_SENSOR_TEMP_M1		0x22
#define ENDAT3_FID_SENSOR_TEMP_M2		0x23
#define ENDAT3_FID_SENSOR_TEMP_M3		0x24
#define ENDAT3_FID_SF_POS1			   	0x50
#define ENDAT3_FID_BGRSP				0x60
#define ENDAT3_FID_BGREQ				0x68
#define ENDAT3_FID_BUS_ADDR			  	0x70

// EnDat 3 Background OpCodes
#define ENDAT3_BG_OPCODE_NOP			0x01
#define ENDAT3_BG_OPCODE_READ			0x02
#define ENDAT3_BG_OPCODE_WRITE		   	0x03
#define ENDAT3_BG_OPCODE_RECONFIGURE	0x04
#define ENDAT3_BG_OPCODE_AUTH			0x80
#define ENDAT3_BG_OPCODE_PROTECT		0x81
#define ENDAT3_BG_OPCODE_SETPASS		0x83
#define ENDAT3_BG_OPCODE_LOCATE		  	0x83

// EnDat 3 Background Request Data
#define ENDAT3_BG_PROTECT_MODE_QUERY	 0x01
#define ENDAT3_BG_PROTECT_MODE_SET_READ  0x02
#define ENDAT3_BG_PROTECT_MODE_SET_WRITE 0x03

#define ENDAT3_BG_ACCLEVEL_USER				0
#define ENDAT3_BG_ACCLEVEL_OEM2				1
#define ENDAT3_BG_ACCLEVEL_OEM1				2
#define ENDAT3_BG_ACCLEVEL_MANUFACTURER		3

// Timing
#define ENDAT3_HELLO_TIMEOUT 302

/////////////
#define CYCLE_BASED_MEM_HPF_LPF 0x1000
#define CYCLE_BASED_MEM_LPH		0x2000
#define FID_BASED_MEM			0x8000
#define SAFETY_COLLECTOR_MEM	0x3000

#define ENDAT3_GET_HPF_ADDR(base, bus_addr) 					(struct HPF *)(((uint8_t *) (base)) + CYCLE_BASED_MEM_HPF_LPF + ((bus_addr) << 7))
#define ENDAT3_GET_LPF_ADDR(base, bus_addr, index) 				(struct LPF *)(((uint8_t *) (base)) + CYCLE_BASED_MEM_HPF_LPF + ((bus_addr) << 7) + (((index) + 1) << 3))
#define ENDAT3_GET_LPH_ADDR(base, bus_addr) 					(struct LPH *)(((uint8_t *) (base)) + CYCLE_BASED_MEM_LPH + ((bus_addr) << 3))
#define ENDAT3_GET_FID_ADDR(base, bus_addr, fid) 				(struct FID *)(((uint8_t *) (base)) + FID_BASED_MEM + ((bus_addr) << 10) + ((fid) << 3))
#define ENDAT3_GET_SAFETY_FID_SD1_HPF(base, bus_addr, packet)	(struct HPF *)(((uint8_t *) (base)) + SAFETY_COLLECTOR_MEM + ((bus_addr) << 6) + ((packet) << 5))
#define ENDAT3_GET_SAFETY_FID_SD1_LPF(base, bus_addr, packet)	(struct LPF *)(((uint8_t *) (base)) + SAFETY_COLLECTOR_MEM + ((bus_addr) << 6) + ((packet) << 5))
#define ENDAT3_GET_SAFETY_FID_SD2_LPF(base, bus_addr, packet)	(struct LPF *)(((uint8_t *) (base)) + SAFETY_COLLECTOR_MEM + ((bus_addr) << 6) + ((packet) << 5) + 0x8)
#define ENDAT3_GET_SAFETY_FID_SF_LPF(base, bus_addr, packet)	(struct LPF *)(((uint8_t *) (base)) + SAFETY_COLLECTOR_MEM + ((bus_addr) << 6) + ((packet) << 5) + 0x10)

#define ENDAT3_FG_Bus_P2P_Req_Rsp(base, bus_addr, code, data, rsp) 				ENDAT3_FG_Bus_Req_Rsp(base, bus_addr, code, data, ENDAT3_FG_REQ_BUSP2P, (uint16_t)bus_addr, rsp)
#define ENDAT3_FG_Bus_BC_with_individual_FG_Req(base, bus_addr, code, data) 	ENDAT3_FG_Bus_Req(base, code, data, ENDAT3_FG_REQ_BUSBC, (uint16_t)bus_addr)
#define ENDAT3_FG_Bus_BC_without_individual_FG_Req(base, code, data) 			ENDAT3_FG_Bus_Req(base, code, data, ENDAT3_FG_REQ_BUSBC, 0)
#define ENDAT3_FG_Bus_BC_without_individual_FG_Req_and_strobe(base, code, data) ENDAT3_FG_Bus_Req_without_strobe(base, code, data, ENDAT3_FG_REQ_BUSBC, 0)

#define ENDAT3_FG_Reset(base)		   		ENDAT3_FG_Req_Rsp(base, ENDAT3_FG_REQ_RESET, ENDAT3_FG_DATA_RESET, NULL)
#define ENDAT3_FG_Rate(base, rate)	 		ENDAT3_FG_Req_Rsp(base, ENDAT3_FG_REQ_RATE, rate, NULL)
#define ENDAT3_FG_Clear(base, flag)			ENDAT3_FG_Req_Rsp(base, ENDAT3_FG_REQ_RATE, flag, NULL)
#define ENDAT3_FG_Force(base)	  			ENDAT3_FG_Req_Rsp(base, ENDAT3_FG_REQ_FORCE, 0x0, NULL)
#define ENDAT3_FG_BusInit(base)		 		ENDAT3_FG_Req_Rsp(base, ENDAT3_FG_REQ_BUSINIT, ENDAT3_FG_DATA_BUSINIT, NULL)
#define ENDAT3_FG_Data(base, DATAx, rsp)	ENDAT3_FG_Req_Rsp(base, DATAx, 0, rsp)

#define ENDAT3_FG_Bus_P2P_Reset(base, addr)		   		ENDAT3_FG_Bus_P2P_Req_Rsp(base, addr, ENDAT3_FG_REQ_RESET, ENDAT3_FG_DATA_RESET, NULL)
#define ENDAT3_FG_Bus_P2P_Rate(base, addr, rate)	  	ENDAT3_FG_Bus_P2P_Req_Rsp(base, addr, ENDAT3_FG_REQ_RATE, rate, NULL)
#define ENDAT3_FG_Bus_P2P_Clear(base, addr, flag)	 	ENDAT3_FG_Bus_P2P_Req_Rsp(base, addr, ENDAT3_FG_REQ_RATE, flag, NULL)
#define ENDAT3_FG_Bus_P2P_Force(base, addr)		  		ENDAT3_FG_Bus_P2P_Req_Rsp(base, addr, ENDAT3_FG_REQ_FORCE, 0x0, NULL)
#define ENDAT3_FG_Bus_P2P_BUSINIT(base, addr)			ENDAT3_FG_Bus_P2P_Req_Rsp(base, addr, ENDAT3_FG_REQ_BUSINIT, ENDAT3_FG_DATA_BUSINIT, NULL)
#define ENDAT3_FG_Bus_P2P_Data(base, addr, DATAx, rsp)	ENDAT3_FG_Bus_P2P_Req_Rsp(base, addr, DATAx, 0, rsp)

#define ENDAT3_LPF_HEAD_SIZE_WORDS 0x0E

#define ENDAT3_HPF_DATA_SHIFT					0
#define ENDAT3_HPF_DATA_POS_SINGLETURN_SHIFT 	0
#define ENDAT3_HPF_DATA_POS_MULTITURN_SHIFT  	32
#define ENDAT3_HPF_ERRORCODE_SHIFT		   		0
#define ENDAT3_HPF_STATUS_SHIFT			  		4
#define ENDAT3_HPF_STATUS_F_SHIFT				48
#define ENDAT3_HPF_STATUS_W_SHIFT				49
#define ENDAT3_HPF_STATUS_HPFV_SHIFT		 	50
#define ENDAT3_HPF_STATUS_RM_SHIFT		   		51
#define ENDAT3_HPF_STATUS_ERR_REQ_SHIFT	  		52
#define ENDAT3_HPF_CS_SHIFT				  		56

#define ENDAT3_LPH_STATUS_SHIFT			  		0
#define ENDAT3_LPH_STATUS_BG_STATUS_SHIFT		0
#define ENDAT3_LPH_STATUS_BG_ERR_EXEC_SHIFT  	2
#define ENDAT3_LPH_STATUS_RESERVED_0_SHIFT   	3
#define ENDAT3_LPH_STATUS_ZACT_SHIFT		 	4
#define ENDAT3_LPH_STATUS_RESERVED_1_SHIFT   	7
#define ENDAT3_LPH_NLPF_SHIFT					8
#define ENDAT3_LPH_NLPF_YACT_SHIFT		   		8
#define ENDAT3_LPH_NLPF_XDIM_SHIFT		   		12
#define ENDAT3_LPH_RESERVED_SHIFT				16
#define ENDAT3_LPH_CS_SHIFT				  		24

#define ENDAT3_LPF_STATUS_SHIFT			  		0
#define ENDAT3_LPF_STATUS_FID_SHIFT		  		0
#define ENDAT3_LPF_STATUS_LPFV_SHIFT		 	7
#define ENDAT3_LPF_DATA_SHIFT					8
#define ENDAT3_LPF_DATA_POS_SINGLETURN_SHIFT   			8
#define ENDAT3_LPF_DATA_POS_MULTITURN_SHIFT				40
#define ENDAT3_LPF_DATA_SF_POS1_AA_SHIFT	   			8
#define ENDAT3_LPF_DATA_SF_POS1_STATUS_F1_SHIFT		 	24
#define ENDAT3_LPF_DATA_SF_POS1_STATUS_F2_SHIFT		 	25
#define ENDAT3_LPF_DATA_SF_POS1_STATUS_IgF1_SHIFT	   	26
#define ENDAT3_LPF_DATA_SF_POS1_STATUS_IgF2_SHIFT	   	27
#define ENDAT3_LPF_DATA_SF_POS1_SOL_SHIFT			   	32
#define ENDAT3_LPF_DATA_SF_POS1_CSS_SHIFT			   	40
#define ENDAT3_LPF_ERRORCODE_SHIFT		   				8
#define ENDAT3_LPF_CS_SHIFT				  				56

#define ENDAT3_FID_TIMESTAMP_SHIFT						0
#define ENDAT3_FID_LPFV_SHIFT			 				8
#define ENDAT3_FID_LPF_DATA_SHIFT						16

#define ENDAT3_HPF_DATA_MASK							0xFFFFFFFFFFFF
#define ENDAT3_HPF_DATA_POS_SINGLETURN_MASK				0xFFFFFFFF
#define ENDAT3_HPF_DATA_POS_MULTITURN_MASK	 			0xFFFF
#define ENDAT3_HPF_ERRORCODE_MASK		   				0xFFFF
#define ENDAT3_HPF_STATUS_MASK			 				0xFF
#define ENDAT3_HPF_STATUS_F_MASK		   				0x01
#define ENDAT3_HPF_STATUS_W_MASK		   			 	0x01
#define ENDAT3_HPF_STATUS_HPFV_MASK					 	0x01
#define ENDAT3_HPF_STATUS_RM_MASK		  			 	0x01
#define ENDAT3_HPF_STATUS_ERR_REQ_MASK	 			 	0x01
#define ENDAT3_HPF_CS_MASK				 			 	0xFF
#define ENDAT3_LPH_STATUS_MASK			 			 	0xFF
#define ENDAT3_LPH_STATUS_BG_STATUS_MASK   			 	0x03
#define ENDAT3_LPH_STATUS_BG_ERR_EXEC_MASK 			 	0x01
#define ENDAT3_LPH_STATUS_RESERVED_0_MASK  			 	0x01
#define ENDAT3_LPH_STATUS_ZACT_MASK					 	0x07
#define ENDAT3_LPH_STATUS_RESERVED_1_MASK  			 	0x01
#define ENDAT3_LPH_NLPF_MASK			   			 	0xFF
#define ENDAT3_LPH_NLPF_YACT_MASK		  			 	0x0F
#define ENDAT3_LPH_NLPF_XDIM_MASK		  			 	0x0F
#define ENDAT3_LPH_RESERVED_MASK		   			 	0xFF
#define ENDAT3_LPH_CS_MASK				 			 	0xFF
#define ENDAT3_LPF_STATUS_MASK			 			 	0xFF
#define ENDAT3_LPF_STATUS_FID_MASK		 			 	0x7F
#define ENDAT3_LPF_STATUS_LPFV_MASK					 	0x01
#define ENDAT3_LPF_DATA_MASK			   			 	0xFFFFFFFFFFFF
#define ENDAT3_LPF_DATA_POS_SINGLETURN_MASK				0xFFFFFFFF
#define ENDAT3_LPF_DATA_POS_MULTITURN_MASK	 			0xFFFF
#define ENDAT3_LPF_DATA_SF_POS1_AA_MASK					0xFF
#define ENDAT3_LPF_DATA_SF_POS1_STATUS_F1_MASK		  	0x01
#define ENDAT3_LPF_DATA_SF_POS1_STATUS_F2_MASK		  	0x01
#define ENDAT3_LPF_DATA_SF_POS1_STATUS_IgF1_MASK		0x01
#define ENDAT3_LPF_DATA_SF_POS1_STATUS_IgF2_MASK		0x01
#define ENDAT3_LPF_DATA_SF_POS1_SOL_MASK				0xFF
#define ENDAT3_LPF_DATA_SF_POS1_CSS_MASK				0xFFF
#define ENDAT3_LPF_ERRORCODE_MASK		   				0xFFFF
#define ENDAT3_LPF_CS_MASK				 				0xFF
#define ENDAT3_FID_TIMESTAMP_MASK						0xFF
#define ENDAT3_FID_LPFV_MASK			 				0x01
#define ENDAT3_FID_LPF_DATA_MASK		 				0xFFFFFFFFFFFF

#define ENDAT3_HPF_DATA_TYPE							uint64_t
#define ENDAT3_HPF_DATA_POS_SINGLETURN_TYPE				uint32_t
#define ENDAT3_HPF_DATA_POS_MULTITURN_TYPE	 			uint16_t
#define ENDAT3_HPF_ERRORCODE_TYPE		   				uint16_t
#define ENDAT3_HPF_STATUS_TYPE			 				uint8_t
#define ENDAT3_HPF_STATUS_F_TYPE		   				uint8_t
#define ENDAT3_HPF_STATUS_W_TYPE		   			 	uint8_t
#define ENDAT3_HPF_STATUS_HPFV_TYPE					 	uint8_t
#define ENDAT3_HPF_STATUS_RM_TYPE		  			 	uint8_t
#define ENDAT3_HPF_STATUS_ERR_REQ_TYPE	 			 	uint8_t
#define ENDAT3_HPF_CS_TYPE				 			 	uint8_t

#define ENDAT3_LPH_STATUS_TYPE			 			 	uint8_t
#define ENDAT3_LPH_STATUS_BG_STATUS_TYPE   			 	uint8_t
#define ENDAT3_LPH_STATUS_BG_ERR_EXEC_TYPE 			 	uint8_t
#define ENDAT3_LPH_STATUS_RESERVED_0_TYPE  			 	uint8_t
#define ENDAT3_LPH_STATUS_ZACT_TYPE					 	uint8_t
#define ENDAT3_LPH_STATUS_RESERVED_1_TYPE  			 	uint8_t
#define ENDAT3_LPH_NLPF_TYPE			   			 	uint8_t
#define ENDAT3_LPH_NLPF_YACT_TYPE		  			 	uint8_t
#define ENDAT3_LPH_NLPF_XDIM_TYPE		  			 	uint8_t
#define ENDAT3_LPH_RESERVED_TYPE		   			 	uint8_t
#define ENDAT3_LPH_CS_TYPE				 			 	uint8_t

#define ENDAT3_LPF_STATUS_TYPE			 			 	uint8_t
#define ENDAT3_LPF_STATUS_FID_TYPE		 			 	uint8_t
#define ENDAT3_LPF_STATUS_LPFV_TYPE					 	uint8_t
#define ENDAT3_LPF_DATA_TYPE			   			 	uint64_t
#define ENDAT3_LPF_DATA_POS_SINGLETURN_TYPE				uint32_t
#define ENDAT3_LPF_DATA_POS_MULTITURN_TYPE	 			uint16_t
#define ENDAT3_LPF_DATA_SF_POS1_AA_TYPE					uint8_t
#define ENDAT3_LPF_DATA_SF_POS1_STATUS_F1_TYPE		  	uint8_t
#define ENDAT3_LPF_DATA_SF_POS1_STATUS_F2_TYPE		  	uint8_t
#define ENDAT3_LPF_DATA_SF_POS1_STATUS_IgF1_TYPE		uint8_t
#define ENDAT3_LPF_DATA_SF_POS1_STATUS_IgF2_TYPE		uint8_t
#define ENDAT3_LPF_DATA_SF_POS1_SOL_TYPE				uint8_t
#define ENDAT3_LPF_DATA_SF_POS1_CSS_TYPE				uint16_t
#define ENDAT3_LPF_ERRORCODE_TYPE				 		uint16_t
#define ENDAT3_LPF_CS_TYPE				  				uint8_t

#define ENDAT3_FID_TIMESTAMP_TYPE						uint8_t
#define ENDAT3_FID_LPFV_TYPE			 				uint8_t
#define ENDAT3_FID_LPF_DATA_TYPE		 				uint64_t

#define ENDAT3_READ_HPF_DATA(dat)  (ENDAT3_HPF_DATA_TYPE)(((dat) \
				   >> ENDAT3_HPF_DATA_SHIFT) & ENDAT3_HPF_DATA_MASK)

#define ENDAT3_READ_HPF_DATA_POS_SINGLETURN(dat)  (ENDAT3_HPF_DATA_POS_SINGLETURN_TYPE)(((dat) \
				   >> ENDAT3_HPF_DATA_POS_SINGLETURN_SHIFT) & ENDAT3_HPF_DATA_POS_SINGLETURN_MASK)

#define ENDAT3_READ_HPF_DATA_POS_MULTITURN(dat)  (ENDAT3_HPF_DATA_POS_MULTITURN_TYPE)(((dat) \
				   >> ENDAT3_HPF_DATA_POS_MULTITURN_SHIFT) & ENDAT3_HPF_DATA_POS_MULTITURN_MASK)

#define ENDAT3_READ_HPF_ERRORCODE(dat)  (ENDAT3_HPF_ERRORCODE_TYPE)(((dat) \
				   >> ENDAT3_HPF_ERRORCODE_SHIFT) & ENDAT3_HPF_ERRORCODE_MASK)

#define ENDAT3_READ_HPF_STATUS(dat)  (ENDAT3_HPF_STATUS_TYPE)(((dat) \
				   >> ENDAT3_HPF_STATUS_SHIFT) & ENDAT3_HPF_STATUS_MASK)

#define ENDAT3_READ_HPF_STATUS_F(dat)  (ENDAT3_HPF_STATUS_F_TYPE)(((dat) \
				   >> ENDAT3_HPF_STATUS_F_SHIFT) & ENDAT3_HPF_STATUS_F_MASK)

#define ENDAT3_READ_HPF_STATUS_W(dat)  (ENDAT3_HPF_STATUS_W_TYPE)(((dat) \
				   >> ENDAT3_HPF_STATUS_W_SHIFT) & ENDAT3_HPF_STATUS_W_MASK)

#define ENDAT3_READ_HPF_STATUS_HPFV(dat)  (ENDAT3_HPF_STATUS_HPFV_TYPE)(((dat) \
				   >> ENDAT3_HPF_STATUS_HPFV_SHIFT) & ENDAT3_HPF_STATUS_HPFV_MASK)

#define ENDAT3_READ_HPF_STATUS_RM(dat)  (ENDAT3_HPF_STATUS_RM_TYPE)(((dat) \
				   >> ENDAT3_HPF_STATUS_RM_SHIFT) & ENDAT3_HPF_STATUS_RM_MASK)

#define ENDAT3_READ_HPF_STATUS_ERR_REQ(dat)  (ENDAT3_HPF_STATUS_ERR_REQ_TYPE)(((dat) \
				   >> ENDAT3_HPF_STATUS_ERR_REQ_SHIFT) & ENDAT3_HPF_STATUS_ERR_REQ_MASK)

#define ENDAT3_READ_HPF_CS(dat)  (ENDAT3_HPF_CS_TYPE)(((dat) \
				   >> ENDAT3_HPF_CS_SHIFT) & ENDAT3_HPF_CS_MASK)

#define ENDAT3_READ_LPH_STATUS(dat)  (ENDAT3_LPH_STATUS_TYPE)(((dat) \
				   >> ENDAT3_LPH_STATUS_SHIFT) & ENDAT3_LPH_STATUS_MASK)

#define ENDAT3_READ_LPH_STATUS_BG_STATUS(dat)  (ENDAT3_LPH_STATUS_BG_STATUS_TYPE)(((dat) \
				   >> ENDAT3_LPH_STATUS_BG_STATUS_SHIFT) & ENDAT3_LPH_STATUS_BG_STATUS_MASK)

#define ENDAT3_READ_LPH_STATUS_BG_ERR_EXEC(dat)  (ENDAT3_LPH_STATUS_BG_ERR_EXEC_TYPE)(((dat) \
				   >> ENDAT3_LPH_STATUS_BG_ERR_EXEC_SHIFT) & ENDAT3_LPH_STATUS_BG_ERR_EXEC_MASK)

#define ENDAT3_READ_LPH_STATUS_RESERVED_0(dat)  (ENDAT3_LPH_STATUS_RESERVED_0_TYPE)(((dat) \
				   >> ENDAT3_LPH_STATUS_RESERVED_0_SHIFT) & ENDAT3_LPH_STATUS_RESERVED_0_MASK)

#define ENDAT3_READ_LPH_STATUS_ZACT(dat)  (ENDAT3_LPH_STATUS_ZACT_TYPE)(((dat) \
				   >> ENDAT3_LPH_STATUS_ZACT_SHIFT) & ENDAT3_LPH_STATUS_ZACT_MASK)

#define ENDAT3_READ_LPH_STATUS_RESERVED_1(dat)  (ENDAT3_LPH_STATUS_RESERVED_1_TYPE)(((dat) \
				   >> ENDAT3_LPH_STATUS_RESERVED_1_SHIFT) & ENDAT3_LPH_STATUS_RESERVED_1_MASK)

#define ENDAT3_READ_LPH_NLPF(dat)  (ENDAT3_LPH_NLPF_TYPE)(((dat) \
				   >> ENDAT3_LPH_NLPF_SHIFT) & ENDAT3_LPH_NLPF_MASK)

#define ENDAT3_READ_LPH_NLPF_YACT(dat)  (ENDAT3_LPH_NLPF_YACT_TYPE)(((dat) \
				   >> ENDAT3_LPH_NLPF_YACT_SHIFT) & ENDAT3_LPH_NLPF_YACT_MASK)

#define ENDAT3_READ_LPH_NLPF_XDIM(dat)  (ENDAT3_LPH_NLPF_XDIM_TYPE)(((dat) \
				   >> ENDAT3_LPH_NLPF_XDIM_SHIFT) & ENDAT3_LPH_NLPF_XDIM_MASK)

#define ENDAT3_READ_LPH_RESERVED(dat)  (ENDAT3_LPH_RESERVED_TYPE)(((dat) \
				   >> ENDAT3_LPH_RESERVED_SHIFT) & ENDAT3_LPH_RESERVED_MASK)

#define ENDAT3_READ_LPH_CS(dat)  (ENDAT3_LPH_CS_TYPE)(((dat) \
				   >> ENDAT3_LPH_CS_SHIFT) & ENDAT3_LPH_CS_MASK)

#define ENDAT3_READ_LPF_STATUS(dat)  (ENDAT3_LPF_STATUS_TYPE)(((dat) \
				   >> ENDAT3_LPF_STATUS_SHIFT) & ENDAT3_LPF_STATUS_MASK)

#define ENDAT3_READ_LPF_STATUS_FID(dat)  (ENDAT3_LPF_STATUS_FID_TYPE)(((dat) \
				   >> ENDAT3_LPF_STATUS_FID_SHIFT) & ENDAT3_LPF_STATUS_FID_MASK)

#define ENDAT3_READ_LPF_STATUS_LPFV(dat)  (ENDAT3_LPF_STATUS_LPFV_TYPE)(((dat) \
				   >> ENDAT3_LPF_STATUS_LPFV_SHIFT) & ENDAT3_LPF_STATUS_LPFV_MASK)

#define ENDAT3_READ_LPF_DATA(dat)  (ENDAT3_LPF_DATA_TYPE)(((dat) \
				   >> ENDAT3_LPF_DATA_SHIFT) & ENDAT3_LPF_DATA_MASK)

#define ENDAT3_READ_LPF_DATA_POS_SINGLETURN(dat)  (ENDAT3_LPF_DATA_POS_SINGLETURN_TYPE)(((dat) \
				   >> ENDAT3_LPF_DATA_POS_SINGLETURN_SHIFT) & ENDAT3_LPF_DATA_POS_SINGLETURN_MASK)

#define ENDAT3_READ_LPF_DATA_POS_MULTITURN(dat)  (ENDAT3_LPF_DATA_POS_MULTITURN_TYPE)(((dat) \
				   >> ENDAT3_LPF_DATA_POS_MULTITURN_SHIFT) & ENDAT3_LPF_DATA_POS_MULTITURN_MASK)

#define ENDAT3_READ_LPF_DATA_SF_POS1_AA(dat)  (ENDAT3_LPF_DATA_SF_POS1_AA_TYPE)(((dat) \
				   >> ENDAT3_LPF_DATA_SF_POS1_AA_SHIFT) & ENDAT3_LPF_DATA_SF_POS1_AA_MASK)

#define ENDAT3_READ_LPF_DATA_SF_POS1_STATUS_F1(dat)  (ENDAT3_LPF_DATA_SF_POS1_STATUS_F1_TYPE)(((dat) \
				   >> ENDAT3_LPF_DATA_SF_POS1_STATUS_F1_SHIFT) & ENDAT3_LPF_DATA_SF_POS1_STATUS_F1_MASK)

#define ENDAT3_READ_LPF_DATA_SF_POS1_STATUS_F2(dat)  (ENDAT3_LPF_DATA_SF_POS1_STATUS_F2_TYPE)(((dat) \
				   >> ENDAT3_LPF_DATA_SF_POS1_STATUS_F2_SHIFT) & ENDAT3_LPF_DATA_SF_POS1_STATUS_F2_MASK)

#define ENDAT3_READ_LPF_DATA_SF_POS1_STATUS_IgF1(dat)  (ENDAT3_LPF_DATA_SF_POS1_STATUS_IgF1_TYPE)(((dat) \
				   >> ENDAT3_LPF_DATA_SF_POS1_STATUS_IgF1_SHIFT) & ENDAT3_LPF_DATA_SF_POS1_STATUS_IgF1_MASK)

#define ENDAT3_READ_LPF_DATA_SF_POS1_STATUS_IgF2(dat)  (ENDAT3_LPF_DATA_SF_POS1_STATUS_IgF2_TYPE)(((dat) \
				   >> ENDAT3_LPF_DATA_SF_POS1_STATUS_IgF2_SHIFT) & ENDAT3_LPF_DATA_SF_POS1_STATUS_IgF2_MASK)

#define ENDAT3_READ_LPF_DATA_SF_POS1_SOL(dat)  (ENDAT3_LPF_DATA_SF_POS1_SOL_TYPE)(((dat) \
				   >> ENDAT3_LPF_DATA_SF_POS1_SOL_SHIFT) & ENDAT3_LPF_DATA_SF_POS1_SOL_MASK)

#define ENDAT3_READ_LPF_DATA_SF_POS1_CSS(dat)  (ENDAT3_LPF_DATA_SF_POS1_CSS_TYPE)(((dat) \
				   >> ENDAT3_LPF_DATA_SF_POS1_CSS_SHIFT) & ENDAT3_LPF_DATA_SF_POS1_CSS_MASK)

#define ENDAT3_READ_LPF_ERRORCODE(dat)  (ENDAT3_LPF_ERRORCODE_TYPE)(((dat) \
				   >> ENDAT3_LPF_ERRORCODE_SHIFT) & ENDAT3_LPF_ERRORCODE_MASK)

#define ENDAT3_READ_LPF_CS(dat)  (ENDAT3_LPF_CS_TYPE)(((dat) \
				   >> ENDAT3_LPF_CS_SHIFT) & ENDAT3_LPF_CS_MASK)

#define ENDAT3_READ_FID_TIMESTAMP(dat)  (ENDAT3_FID_TIMESTAMP_TYPE)(((dat) \
				   >> ENDAT3_FID_TIMESTAMP_SHIFT) & ENDAT3_FID_TIMESTAMP_MASK)

#define ENDAT3_READ_FID_LPFV(dat)  (ENDAT3_FID_LPFV_TYPE)(((dat) \
				   >> ENDAT3_FID_LPFV_SHIFT) & ENDAT3_FID_LPFV_MASK)

#define ENDAT3_READ_FID_LPF_DATA(dat)  (ENDAT3_FID_LPF_DATA_TYPE)(((dat) \
				   >> ENDAT3_FID_LPF_DATA_SHIFT) & ENDAT3_FID_LPF_DATA_MASK)

#define ENDAT3_READ_POS_SINGLETURN_HPF(dat)				ENDAT3_READ_HPF_DATA_POS_SINGLETURN(dat)
#define ENDAT3_READ_POS_SINGLETURN_LPF(dat)				ENDAT3_READ_LPF_DATA_POS_SINGLETURN(dat)
#define ENDAT3_READ_POS_MULTITURN_HPF(dat)					ENDAT3_READ_HPF_DATA_POS_MULTITURN(dat)
#define ENDAT3_READ_POS_MULTITURN_LPF(dat)					ENDAT3_READ_LPF_DATA_POS_MULTITURN(dat)

#define ENDAT3_FIDMEM_GetData(FID_res)						ENDAT3_READ_FID_LPF_DATA(FID_res->fid64)
#define ENDAT3_FIDMEM_GetLPFV(FID_res)							ENDAT3_READ_FID_LPFV(FID_res->fid64)
#define ENDAT3_FIDMEM_GetTimestamp(FID_res)					ENDAT3_READ_FID_TIMESTAMP(FID_res->fid64)

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * APIs
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

static inline void ENDAT3_SW_Reset(ENDAT3_Type *base)
{
	base->CONFIG_0 |= ENDAT3_CONFIG_0_SW_RESET_MASK;
}

static inline void ENDAT3_HW_Strobe_Enable(ENDAT3_Type *base)
{
	base->CONFIG_0 |= ENDAT3_CONFIG_0_HW_STROBE_EN_MASK;
}

static inline void ENDAT3_HW_Strobe_Disable(ENDAT3_Type *base)
{
	base->CONFIG_0 &= ~ENDAT3_CONFIG_0_HW_STROBE_EN_MASK;
}

static inline void ENDAT3_BG_Handler_Enable(ENDAT3_Type *base)
{
	base->CONFIG_0 |= ENDAT3_CONFIG_0_BG_HANDLER_EN_MASK;
}

static inline void ENDAT3_BG_Handler_Disable(ENDAT3_Type *base)
{
	base->CONFIG_0 &= ~ENDAT3_CONFIG_0_BG_HANDLER_EN_MASK;
}

static inline void ENDAT3_Set_Bus_Participants_Num(ENDAT3_Type *base, uint8_t num)
{
	base->CONFIG_0 &= ~ENDAT3_CONFIG_0_NUM_BUS_SLAVES_MASK;
	base->CONFIG_0 |= ENDAT3_CONFIG_0_NUM_BUS_SLAVES(num);
}

/* API interface for FG commnunication*/

static inline void ENDAT3_FG_IRQ_Enable_With_FIxM_Frame_Count(ENDAT3_Type *base, uint32_t irq_index, uint8_t counter)
{
	base->FG_IRQ_MASK[irq_index] &= ~ENDAT3_FG_IRQ_MASK_FIxM_FRAME_CNT_MASK;
	base->FG_IRQ_MASK[irq_index] |= ENDAT3_FG_IRQ_MASK_FIxM_FRAME_CNT(counter);
	base->FG_IRQ_MASK[irq_index] |= ENDAT3_FG_IRQ_MASK_FIxM_FRAME_CNT_EN_MASK;
}

static inline void ENDAT3_FG_IRQ_Enable_With_FIxM_Bus_Address_Count(ENDAT3_Type *base, uint32_t irq_index, uint8_t counter)
{
	base->FG_IRQ_MASK[irq_index] &= ~ENDAT3_FG_IRQ_MASK_FIxM_BUS_ADDR_CNT_MASK;
	base->FG_IRQ_MASK[irq_index] |= ENDAT3_FG_IRQ_MASK_FIxM_BUS_ADDR_CNT(counter);
	base->FG_IRQ_MASK[irq_index] |= ENDAT3_FG_IRQ_MASK_FIxM_ADDR_CNT_EN_MASK;
}

static inline void ENDAT3_BG_IRQ_Enable(ENDAT3_Type *base, uint32_t irq_mask)
{
	base->BG_IRQ_MASK |= irq_mask;
}

static inline void ENDAT3_BG_IRQ_Disable(ENDAT3_Type *base, uint32_t irq_mask)
{
	base->BG_IRQ_MASK &= ~irq_mask;
}

static inline void ENDAT3_FG_IRQ_Enable(ENDAT3_Type *base, uint32_t irq_index, uint32_t irq_mask)
{
	base->FG_IRQ_MASK[irq_index] |= irq_mask;
}

static inline void ENDAT3_FG_IRQ_Disable(ENDAT3_Type *base, uint32_t irq_index, uint32_t irq_mask)
{
	base->FG_IRQ_MASK[irq_index] &= ~irq_mask;
}

static inline void ENDAT3_IRQ_Clear(ENDAT3_Type *base, uint32_t irq)
{
	base->IRQ_CLEAR = irq;
}

static inline void ENDAT3_Safety_Packet0_SF_Cfg(ENDAT3_Type *base, uint8_t SF_FID)
{
	base->SAFETY_PACKET_0 &= ~ENDAT3_SAFETY_PACKET_0_FID_SF_0_MASK;
	base->SAFETY_PACKET_0 |= ENDAT3_SAFETY_PACKET_0_FID_SF_0(SF_FID);
}

static inline void ENDAT3_Safety_Packet0_SD2_Cfg(ENDAT3_Type *base, uint8_t SD2_FID)
{
	base->SAFETY_PACKET_0 &= ~ENDAT3_SAFETY_PACKET_0_FID_SD2_0_MASK;
	base->SAFETY_PACKET_0 |= ENDAT3_SAFETY_PACKET_0_FID_SD2_0(SD2_FID);
}

static inline void ENDAT3_Safety_Packet0_SD1_Cfg(ENDAT3_Type *base, uint8_t SD1_FID, uint8_t inHPF)
{
	base->SAFETY_PACKET_0 &= ~(ENDAT3_SAFETY_PACKET_0_FID_SD1_0_MASK | ENDAT3_SAFETY_PACKET_0_FID_SD1_HPF_0_MASK);
	base->SAFETY_PACKET_0 |= ENDAT3_SAFETY_PACKET_0_FID_SD1_0(SD1_FID);
	base->SAFETY_PACKET_0 |= ENDAT3_SAFETY_PACKET_0_FID_SD1_HPF_0(inHPF);
}

static inline void ENDAT3_Safety_Packet1_SF_Cfg(ENDAT3_Type *base, uint8_t SF_FID)
{
	base->SAFETY_PACKET_1 &= ENDAT3_SAFETY_PACKET_1_FID_SF_1_MASK;
	base->SAFETY_PACKET_1 |= ENDAT3_SAFETY_PACKET_1_FID_SF_1(SF_FID);
}

static inline void ENDAT3_Safety_Packet1_SD2_Cfg(ENDAT3_Type *base, uint8_t SD2_FID)
{
	base->SAFETY_PACKET_1 &= ENDAT3_SAFETY_PACKET_1_FID_SD2_1_MASK;
	base->SAFETY_PACKET_1 |= ENDAT3_SAFETY_PACKET_1_FID_SD2_1(SD2_FID);
}

static inline void ENDAT3_Safety_Packet1_SD1_Cfg(ENDAT3_Type *base, uint8_t SD1_FID, uint8_t inHPF)
{
	base->SAFETY_PACKET_1 &= ~(ENDAT3_SAFETY_PACKET_1_FID_SD1_1_MASK | ENDAT3_SAFETY_PACKET_1_FID_SD1_HPF_1_MASK);
	base->SAFETY_PACKET_1 |= ENDAT3_SAFETY_PACKET_1_FID_SD1_1(SD1_FID);
	base->SAFETY_PACKET_1 |= ENDAT3_SAFETY_PACKET_1_FID_SD1_HPF_1(inHPF);
}

static inline uint32_t ENDAT3_Safety_Packet_status(ENDAT3_Type *base, uint8_t packet, uint8_t addr)
{
	addr = addr > 0 ? addr - 1: 0;
	return (base->SC_STATUS[packet] >> addr) & 0x01;
}

static inline void ENDAT3_FG_Req(ENDAT3_Type *base, uint8_t code, uint16_t dat)
{
	base->FG_REQ_1 = ENDAT3_FG_REQ_1_REQ_CODE(code) | ENDAT3_FG_REQ_1_REQ_DATA(dat) | ENDAT3_FG_REQ_1_FG_STROBE(1);
}

static inline void ENDAT3_FG_Req_without_strobe(ENDAT3_Type *base, uint8_t code, uint16_t dat)
{
	base->FG_REQ_1 = ENDAT3_FG_REQ_1_REQ_CODE(code) | ENDAT3_FG_REQ_1_REQ_DATA(dat);
}

static inline void ENDAT3_FG_Bus_Req_without_strobe(ENDAT3_Type *base, uint8_t code, uint16_t dat, uint8_t busCode, uint16_t busDat)
{
	base->FG_REQ_0 = ENDAT3_FG_REQ_0_BUS_REQ_CODE(busCode) | ENDAT3_FG_REQ_0_BUS_REQ_DATA(busDat) | ENDAT3_FG_REQ_0_EN_BUS_REQ(1);
	base->FG_REQ_1 = ENDAT3_FG_REQ_1_REQ_CODE(code) | ENDAT3_FG_REQ_1_REQ_DATA(dat);
}

static inline void ENDAT3_FG_Bus_Req(ENDAT3_Type *base, uint8_t code, uint16_t dat, uint8_t busCode, uint16_t busDat)
{
	base->FG_REQ_0 = ENDAT3_FG_REQ_0_BUS_REQ_CODE(busCode) | ENDAT3_FG_REQ_0_BUS_REQ_DATA(busDat) | ENDAT3_FG_REQ_0_EN_BUS_REQ(1);
	base->FG_REQ_1 = ENDAT3_FG_REQ_1_REQ_CODE(code) | ENDAT3_FG_REQ_1_REQ_DATA(dat) | ENDAT3_FG_REQ_1_FG_STROBE(1);
}

void ENDAT3_FG_Req(ENDAT3_Type *base, uint8_t code, uint16_t dat);
void ENDAT3_FG_Req_Bus(ENDAT3_Type *base, uint8_t code, uint16_t dat, uint8_t busCode, uint16_t busDat);
status_t ENDAT3_FG_P2P_Hello(ENDAT3_Type *base);
status_t ENDAT3_FG_WaitingMasterReady(ENDAT3_Type *base);
bool ENDAT3_FG_CheckStatus(ENDAT3_Type *base);
uint8_t ENDAT3_getRsp(ENDAT3_Type *base, uint8_t bus_addr, endat3_rsp_t *rsp);
status_t ENDAT3_FG_Req_Rsp(ENDAT3_Type *base, uint8_t req, uint16_t data, endat3_rsp_t *rsp);
status_t ENDAT3_FG_Hello(ENDAT3_Type *base);
status_t ENDAT3_FG_Echo(ENDAT3_Type *base, uint16_t arbitrary_data);
status_t ENDAT3_FG_Bus_Req_Rsp(ENDAT3_Type *base, uint8_t bus_addr, uint8_t req, uint16_t data, uint8_t busCode, uint16_t busData, endat3_rsp_t *rsp);
status_t ENDAT3_FG_Bus_P2P_Hello(ENDAT3_Type *base, uint8_t addr);
status_t ENDAT3_FG_Bus_P2P_Echo(ENDAT3_Type *base, uint8_t addr, uint16_t arbitrary_data);

/* API interface for BG commnunication*/
void ENDAT3_BG_Req(ENDAT3_Type *base, uint8_t bus_addr, struct BGREQ *req, uint8_t wait_rsp);
void ENDAT3_BG_WaitReqEmpty(ENDAT3_Type *base, uint8_t bus_addr, uint8_t fg_strobes);
status_t ENDAT3_BG_WaitReqFinished(ENDAT3_Type *base, uint8_t bus_addr, uint8_t fg_strobes, uint32_t timeout_ms);
uint64_t ENDAT3_BG_GetRsp(ENDAT3_Type *base);
status_t ENDAT3_BG_Req_Rsp(ENDAT3_Type *base, uint8_t bus_addr, struct BGREQ *req, uint64_t *rsp, uint8_t fg_strobes, uint32_t timeout_ms);
status_t ENDAT3_BG_Nop(ENDAT3_Type *base, uint8_t bus_addr, uint64_t arbitrary, uint64_t *bg_rsp, uint8_t fg_strobes);
status_t ENDAT3_BG_Reconfigure(ENDAT3_Type *base, uint8_t bus_addr, uint8_t fg_strobes);
status_t ENDAT3_BG_Read(ENDAT3_Type *base, uint8_t bus_addr, uint32_t addr, uint8_t num_words, uint16_t *words, uint8_t fg_strobes);
status_t ENDAT3_BG_Write(ENDAT3_Type *base, uint8_t bus_addr, uint32_t addr, const uint16_t word, uint8_t fg_strobes);
status_t ENDAT3_BG_Auth(ENDAT3_Type *base, uint8_t bus_addr, uint8_t usrlevel, uint32_t pass, uint8_t fg_strobes);
status_t ENDAT3_BG_Setpass(ENDAT3_Type *base, uint8_t bus_addr, uint8_t usrlevel, uint32_t pass, uint8_t fg_strobes);
status_t ENDAT3_BG_Protect(ENDAT3_Type *base, uint8_t bus_addr, uint32_t addr, uint8_t mode, const uint8_t acclevel, uint8_t *al_write, uint8_t *al_read, uint8_t fg_strobes);
status_t ENDAT3_BG_Locate(ENDAT3_Type *base, uint8_t bus_addr, uint8_t ctrl, uint8_t fg_strobes);
status_t ENDAT3_RxTxClkConfig(ENDAT3_Type *base, uint32_t clk_sys, uint8_t rate, uint16_t watchdag_us);
status_t ENDAT3_memRead(ENDAT3_Type *base, uint8_t bus_addr, uint32_t addr,  uint16_t n_words, uint16_t *pbuf, uint8_t fg_strobes);
status_t ENDAT3_memWrite(ENDAT3_Type *base, uint8_t bus_addr, uint32_t addr,  uint16_t n_words, uint16_t *pbuf, uint8_t fg_strobes);
status_t ENDAT3_memCacheInit(ENDAT3_Type *base, uint8_t bus_addr, uint32_t mem_base, endat3_mem_cache_t *cache, uint16_t *pbuf, uint32_t pbufSize, uint8_t fg_strobes);
status_t ENDAT3_memCacheFlush(ENDAT3_Type *base, uint8_t bus_addr, endat3_mem_cache_t *cache, uint8_t fg_strobes);
status_t ENDAT3_memCacheFetch(ENDAT3_Type *base, uint8_t bus_addr, endat3_mem_cache_t *cache, uint8_t fg_strobes);
uint16_t ENDAT3_memGetRangeSize(ENDAT3_Type *base, uint8_t bus_addr, uint32_t mem_base, uint8_t fg_strobes);
status_t ENDAT3_memCacheCheckCS(endat3_mem_cache_t *cache);
status_t ENDAT3_memCacheUpdataCS(endat3_mem_cache_t *cache);
uint16_t ENDAT3_lpfCacheGetPointer(uint8_t z, endat3_mem_cache_t *lpf_cache);
void ENDAT3_lpfCacheGetXdimYdim(uint8_t z, endat3_mem_cache_t *lpf_cache, uint8_t *xdim, uint8_t *y_dim);
void ENDAT3_lpfCacheSetXdimYdim(uint8_t z, endat3_mem_cache_t *lpf_cache, uint8_t xdim, uint8_t y_dim);
void ENDAT3_lpfCacheSetPointer(uint8_t z, endat3_mem_cache_t *lpf_cache, uint16_t pointer);
void ENDAT3_lpfCacheListSetFid(endat3_mem_cache_t *cache, uint8_t xdim, uint8_t x, uint8_t y, uint16_t pointer, uint8_t fid);
void ENDAT3_lpfCacheListSetSendlist(endat3_mem_cache_t *cache, uint8_t z, uint8_t xdim, uint8_t ydim, uint16_t pointer, uint8_t *fids);
uint8_t ENDAT3_lpfCacheListGetFid(endat3_mem_cache_t *cache, uint8_t xdim, uint8_t x, uint8_t y, uint16_t pointer);
status_t ENDAT3_lpfCacheUpdateFromEnconder(ENDAT3_Type *base, uint8_t bus_addr, endat3_mem_cache_t *cache, uint16_t *pdat, uint32_t pdat_size, uint8_t from_set, uint8_t fg_strobes);
status_t ENDAT3_lpfCacheFlushToEncoder(ENDAT3_Type *base, uint8_t bus_addr, endat3_mem_cache_t *cache, uint8_t fg_strobes);
void ENDAT3_lpfCacheListUpdate(endat3_mem_cache_t *global_cache, endat3_mem_cache_t *cache, uint8_t z, uint8_t xdim, uint8_t ydim, uint16_t pointer, uint8_t *fid);
status_t ENDAT3_Bus_Assign_Address(ENDAT3_Type *base, uint8_t encoderNum);

char* ENDAT3_FID2str(const uint8_t fid);
char *ENDAT3_Err2str(uint16_t errCode);

/* FID_BASED_MEM API */
status_t ENDAT3_FIDMEM_getLpf(ENDAT3_Type *base, uint8_t bus_addr, uint8_t fid, struct FID *fid_res);
uint8_t ENDAT3_FIDMEM_getTimestamp(ENDAT3_Type *base, uint8_t bus_addr, uint8_t fid);
uint8_t ENDAT3_FIDMEM_getLpfv(ENDAT3_Type *base, uint8_t bus_addr, uint8_t fid);
uint64_t ENDAT3_FIDMEM_getData(ENDAT3_Type *base, uint8_t bus_addr, uint8_t fid);
#if defined(__cplusplus)
}

#endif /* __cplusplus */

/* @} */

#endif
