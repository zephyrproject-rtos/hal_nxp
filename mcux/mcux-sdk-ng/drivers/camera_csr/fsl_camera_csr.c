/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_camera_csr.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Fix Misra issue */
#define CAMERACSRErrorPiexlDataType                 (uint32_t)(0xFFU)
#define CAMERACSR_RAW32_CONTROL(vc)                 ((uint32_t)(0x1U)) << (vc)
#define CAMERACSR_PIXEL_DATATYPE(index)             ((uint32_t)(0x1U)) << (index)

/*******************************************************************************
 * Variables
 ******************************************************************************/
pixel_link_transfer_pixel_data_t pixel_data_array[] ={
    {kCSI2RX_DataTypeYUV420_8Bit,    (uint8_t)0U},
    {kCSI2RX_DataTypeYUV420_10Bit,   (uint8_t)1U},
    {kCSI2RX_DataTypeYUV420_8BitCS,  (uint8_t)4U},
    {kCSI2RX_DataTypeYUV420_10BitCS, (uint8_t)5U},
    {kCSI2RX_DataTypeYUV422_8Bit,    (uint8_t)6U},
    {kCSI2RX_DataTypeYUV422_10Bit,   (uint8_t)7U},

    {kCSI2RX_DataTypeRGB444,         (uint8_t)8U},
    {kCSI2RX_DataTypeRGB555,         (uint8_t)9U},
    {kCSI2RX_DataTypeRGB565,         (uint8_t)10U},
    {kCSI2RX_DataTypeRGB666,         (uint8_t)11U},
    {kCSI2RX_DataTypeRGB888,         (uint8_t)12U},

    {kCSI2RX_DataTypeRAW24,          (uint8_t)15U},
    {kCSI2RX_DataTypeRAW6,           (uint8_t)16U},
    {kCSI2RX_DataTypeRAW7,           (uint8_t)17U},
    {kCSI2RX_DataTypeRAW8,           (uint8_t)18U},
    {kCSI2RX_DataTypeRAW10,          (uint8_t)19U},
    {kCSI2RX_DataTypeRAW12,          (uint8_t)20U},
    {kCSI2RX_DataTypeRAW14,          (uint8_t)21U},
    {kCSI2RX_DataTypeRAW16,          (uint8_t)22U},
    {kCSI2RX_DataTypeRAW20,          (uint8_t)23U},
};
/*******************************************************************************
 * Code
 ******************************************************************************/

uint32_t CAMERACSR_GetPixelDataIndex(csi2rx_payload_t datatype)
{
    uint8_t i =0;

    for(i = 0; i< ARRAY_SIZE(pixel_data_array); i++)
    {
        if (datatype == pixel_data_array[i].datatype)
        {
            return (uint32_t)pixel_data_array[i].index;
        }
    }

    /* invalid pixel datatype format */
    return CAMERACSRErrorPiexlDataType;
}

void CAMERACSR_PixelFormatting(BLK_CTRL_CAMERAMIX_Type *camera_csr, camera_csr_pixel_formatting_config_t *config)
{
    assert(NULL != config);
    uint8_t csiinterface;
    uint32_t vc;
    uint32_t npdatatype; //Non pixel can be transfered data type
    uint8_t npnewvc; //Non pixel data retoute new virtual channel number
    bool npdataroute; //Defines if the non-pixel data are routed to another VC or not
    uint32_t pdatatype;
    uint8_t pnewvc;
    bool pdataroute;

    csiinterface = config->csiinterface;
    vc = config->mipiVc;
    npdatatype = config->NonPixelDataType;
    npnewvc = config->NonPixelDataNewVc;
    npdataroute = config->enableNonPixelDataRoute;

    pdatatype = CAMERACSR_GetPixelDataIndex(config->PixelDataType);
    assert(pdatatype != CAMERACSRErrorPiexlDataType);

    pnewvc = config->PixelDataNewVc;
    pdataroute = config->enablePixelDataRoute;

    if (csiinterface == (uint8_t)0)
    {
        /* CSI0 host interface */
        /*
         * Non-Pixel data type can be transported to Pixel Link, If the corresponding bit is set to '1', the non-pixel data type is transported on the pixel link. 
         * If set to '0', non-pixel data type are not transported on pixel line.
         */
        camera_csr->CSI0_NP_data_type_VC[vc] = npdatatype;
        if (config->enableNonPixelDataRoute != false)
        {
            /* Route Non-Pixel data type to a new virtual channel for ISI */
            camera_csr->CSI0_Non_Pixel_data_ctrl_VC[vc] |= BLK_CTRL_CAMERAMIX_CSI0_Non_Pixel_data_ctrl_VC_Reroute_VC(npnewvc) 
                                                         | BLK_CTRL_CAMERAMIX_CSI0_Non_Pixel_data_ctrl_VC_New_VC(npdataroute);
        }
        camera_csr->CSI0_Pixel_data_type_VC[vc] |= CAMERACSR_PIXEL_DATATYPE(pdatatype);
        if (config->enablePixelDataRoute != false)
        {
            /* Route Non-Pixel data type to a new virtual channel for ISI */
            camera_csr->CSI0_Pixel_data_ctrl_VC[vc] |= BLK_CTRL_CAMERAMIX_CSI0_Pixel_data_ctrl_VC_Reroute_VC(pnewvc) 
                                                         | BLK_CTRL_CAMERAMIX_CSI0_Pixel_data_ctrl_VC_New_VC(pdataroute);
        }
        if (config->enableRAW32 != false)
        {
            camera_csr->CSI0_RAW32_CTR |= CAMERACSR_RAW32_CONTROL(vc);
        }
    }
    else if (csiinterface == (uint8_t)1)
    {
        /* CSI1 host interface */
        camera_csr->CSI1_NP_data_type_VC[vc] = npdatatype;
        if (config->enableNonPixelDataRoute != false)
        {
            /* Route Non-Pixel data type to a new virtual channel for ISI */
            camera_csr->CSI1_Non_Pixel_data_ctrl_VC[vc] |= BLK_CTRL_CAMERAMIX_CSI0_Non_Pixel_data_ctrl_VC_Reroute_VC(npnewvc) 
                                                         | BLK_CTRL_CAMERAMIX_CSI0_Non_Pixel_data_ctrl_VC_New_VC(npdataroute);
        }
        camera_csr->CSI1_Pixel_data_type_VC[vc] |= CAMERACSR_PIXEL_DATATYPE(pdatatype);
        if (config->enablePixelDataRoute != false)
        {
            /* Route Non-Pixel data type to a new virtual channel for ISI */
            camera_csr->CSI1_Pixel_data_ctrl_VC[vc] |= BLK_CTRL_CAMERAMIX_CSI0_Pixel_data_ctrl_VC_Reroute_VC(pnewvc) 
                                                         | BLK_CTRL_CAMERAMIX_CSI0_Pixel_data_ctrl_VC_New_VC(pdataroute);
        }
        if (config->enableRAW32 != false)
        {
            camera_csr->CSI1_RAW32_CTR |= CAMERACSR_RAW32_CONTROL(vc);
        }
    }
    else
    {
        /* Fix misra issue */
    }
}
