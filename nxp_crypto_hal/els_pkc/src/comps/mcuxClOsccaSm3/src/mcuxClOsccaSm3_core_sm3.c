/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024 NXP                                                  */
/*                                                                          */
/* SPDX-License-Identifier: BSD-3-Clause                                    */
/*                                                                          */
/* Redistribution and use in source and binary forms, with or without       */
/* modification, are permitted provided that the following conditions are   */
/* met:                                                                     */
/*                                                                          */
/* 1. Redistributions of source code must retain the above copyright        */
/*    notice, this list of conditions and the following disclaimer.         */
/*                                                                          */
/* 2. Redistributions in binary form must reproduce the above copyright     */
/*    notice, this list of conditions and the following disclaimer in the   */
/*    documentation and/or other materials provided with the distribution.  */
/*                                                                          */
/* 3. Neither the name of the copyright holder nor the names of its         */
/*    contributors may be used to endorse or promote products derived from  */
/*    this software without specific prior written permission.              */
/*                                                                          */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  */
/* IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED    */
/* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A          */
/* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT       */
/* HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   */
/* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR   */
/* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF   */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING     */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS       */
/* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.             */
/*--------------------------------------------------------------------------*/

#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClOsccaSm3_Core_sm3.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>

#include <mcuxClOsccaSafo.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaSm3_Safo_Hash_PreLoad)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClOsccaSm3_Safo_Hash_PreLoad(uint32_t *workArea)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaSm3_Safo_Hash_PreLoad);
    uint32_t i;

    //step1:Setup the SM3 control SFRs for Loading partial HASH into SGI
    //SM3_MODE = 1'b1 (AUTO mode)
    //SM3_LOW_LIM = 4'b0000
    //SM3_HIGH_LIM = 4'b1111
    //SM3_COUNT_EN = 1'b0
    //HASH_RELOAD =1'b1
    //SM3_STOP = 1'b0
    //NO_AUTO_INIT = 1'b1
    //SM3_EN = 1'b1
    //SM3_SGI_SM3_CTRL =0x0001AF02;
    mcuxClOsccaSafo_Drv_configureSm3(MCUXCLOSCCASAFO_DRV_CONFIG_SM3_AUTOMODE_LOADIV);

    //Step2:Setup the SGI Control SFRs, Start SAFO SM3 processing
    // START = 1'b1
    //CRYPTO_OP = 3'b111
    //DATOUT_RES = 2'b00 (END_UP)
    //SM3_SGI_CTRL = 0x00000071;
    mcuxClOsccaSafo_Drv_start(MCUXCLOSCCASAFO_DRV_START_SM3);

    (void)mcuxClOsccaSafo_Drv_setByteOrder(MCUXCLOSCCASAFO_DRV_BYTE_ORDER_BE);
    //Step3: Load partial Hash
    for(i=0u;i<=7u;i++)
    {
        mcuxClOsccaSafo_Drv_loadFifo(0u);
    }
    for(i=8u;i<=15u;i++)
    {
        mcuxClOsccaSafo_Drv_loadFifo(workArea[15u - ((i) & 15u)]);
    }

    //Step4:Configure SGI_SM3_CTRL SFRs to stop AUTO mode
    // SM3_STOP = 1'b1
    mcuxClOsccaSafo_Drv_stopSm3();

    //Step5:Wait for the SM3 operation to complete
    mcuxClOsccaSafo_Drv_wait();

    /* update SC and return */
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClOsccaSm3_Safo_Hash_PreLoad);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaSm3_Safo_Hash_Norm)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClOsccaSm3_Safo_Hash_Norm(uint32_t *workArea, uint32_t *data)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaSm3_Safo_Hash_Norm);

    //step1:Setup the SM3 control SFRs
    //SM3_MODE = 1'b0 (NORM mode)
    //SM3_LOW_LIM = 4'b0000
    //SM3_HIGH_LIM = 4'b1111
    //SM3_COUNT_EN = 1'b0
    //SM3_STOP = 1'b0
    //NO_AUTO_INIT = 1'b0
    //SM3_EN = 1'b1
    mcuxClOsccaSafo_Drv_configureSm3(MCUXCLOSCCASAFO_DRV_CONFIG_SM3_NORMALMODE_LOADDATA_USELOADEDIV);

    //Step2:Load message into SFRs
    for(uint32_t i = 0u; i < 8u; i++)
    {
        mcuxClOsccaSafo_Drv_load(i, data[15u - i]);
    }
    for(uint32_t i = 0u; i < 8u; i++)
    {
        mcuxClOsccaSafo_Drv_loadKey(i, data[7u - i]);
    }

    //Step3:Setup the SGI control SRFs
    // START = 1'b1
    //CRYPTO_OP = 3'b111
    //DATOUT_RES = 2'b00 (END_UP)
    //SM3_SGI_CTRL = 0x00000070;
    mcuxClOsccaSafo_Drv_start(MCUXCLOSCCASAFO_DRV_START_SM3);

    //Step4:Wait for the SM3 operation to complete
    mcuxClOsccaSafo_Drv_wait();
    workArea[0] = mcuxClOsccaSafo_Drv_store(0);
    workArea[1] = mcuxClOsccaSafo_Drv_store(1);
    workArea[2] = mcuxClOsccaSafo_Drv_store(2);
    workArea[3] = mcuxClOsccaSafo_Drv_store(3);

    //Step5:Set the DATOUT_RES to TRIGGER_UP mode,then get the upper 128bits output
    //DATOUT_RES = 2'b10 (TRIGGER_UP)
    //START = 1'b1
    mcuxClOsccaSafo_Drv_triggerOutput();

    mcuxClOsccaSafo_Drv_wait();
    workArea[4] = mcuxClOsccaSafo_Drv_store(0);
    workArea[5] = mcuxClOsccaSafo_Drv_store(1);
    workArea[6] = mcuxClOsccaSafo_Drv_store(2);
    workArea[7] = mcuxClOsccaSafo_Drv_store(3);
    /* update SC and return */
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClOsccaSm3_Safo_Hash_Norm);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaSm3_Safo_Hash_Auto)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClOsccaSm3_Safo_Hash_Auto(uint32_t *workArea, uint32_t *data)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaSm3_Safo_Hash_Auto);

    //step1:Setup the SM3 control SFRs
    //SM3_MODE = 1'b1 (AUTO mode)
    //SM3_LOW_LIM = 4'b0000
    //SM3_HIGH_LIM = 4'b1111
    //SM3_COUNT_EN = 1'b0
    //HASH_RELOAD =1'b0
    //SM3_STOP = 1'b0
    //NO_AUTO_INIT = 1'b1
    //SM3_EN = 1'b1
    //SM3_SGI_SM3_CTRL =0x00018F02;
    mcuxClOsccaSafo_Drv_configureSm3(MCUXCLOSCCASAFO_DRV_CONFIG_SM3_AUTOMODE_LOADDATA_USELOADEDIV);

    //Step2:Setup the SGI Control SFRs
    // START = 1'b1
    //CRYPTO_OP = 3'b111
    //DATOUT_RES = 2'b00 (END_UP)
    //SM3_SGI_CTRL = 0x00000071;
    mcuxClOsccaSafo_Drv_start(MCUXCLOSCCASAFO_DRV_START_SM3);

    //Step3:Load message into SGI_SM3_FIFO SFRs
    for(uint32_t i=0u;i<=15u;i++)
    {
        mcuxClOsccaSafo_Drv_loadFifo(data[15u - ((i) & 15u)]);
    }

    //Step4:Configure SGI_SM3_CTRL SFRs to stop AUTO mode
    // SM3_STOP = 1'b1
    mcuxClOsccaSafo_Drv_stopSm3();

    //Step5:Wait for the SM3 operation to complete
    mcuxClOsccaSafo_Drv_wait();
    workArea[0] = mcuxClOsccaSafo_Drv_store(0);
    workArea[1] = mcuxClOsccaSafo_Drv_store(1);
    workArea[2] = mcuxClOsccaSafo_Drv_store(2);
    workArea[3] = mcuxClOsccaSafo_Drv_store(3);

    //Step6:Set the DATOUT_RES to TRIGGER_UP mode,then get the upper 128bits output
    //DATOUT_RES = 2'b10 (TRIGGER_UP)
    //START = 1'b1
    mcuxClOsccaSafo_Drv_triggerOutput();

    mcuxClOsccaSafo_Drv_wait();
    workArea[4] = mcuxClOsccaSafo_Drv_store(0);
    workArea[5] = mcuxClOsccaSafo_Drv_store(1);
    workArea[6] = mcuxClOsccaSafo_Drv_store(2);
    workArea[7] = mcuxClOsccaSafo_Drv_store(3);

    /* update SC and return */
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClOsccaSm3_Safo_Hash_Auto);
}
