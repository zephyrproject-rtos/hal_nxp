/*
 * The Clear BSD License
 * Copyright  2018 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 * that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_cmp.h"
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.jn_cmp"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
void CMP_Init(cmp_config_t *config)
{
    assert(config);

    uint32_t anaComp = 0U;

    anaComp = PMC->ANAMUXCOMP & (~(PMC_ANAMUXCOMP_COMP_HYST_MASK | PMC_ANAMUXCOMP_COMP_INNINT_MASK |
                                   PMC_ANAMUXCOMP_COMP_LOWPOWER_MASK | PMC_ANAMUXCOMP_COMP_INPUTSWAP_MASK));

    anaComp |= (config->src << PMC_ANAMUXCOMP_COMP_INNINT_SHIFT) |
               (config->mode << PMC_ANAMUXCOMP_COMP_LOWPOWER_SHIFT) |
               (((uint32_t)(config->enLowHysteris)) << PMC_ANAMUXCOMP_COMP_HYST_SHIFT);

    PMC->ANAMUXCOMP = anaComp;
}

void CMP_Deinit(void)
{
    /* nothing to do */
}

void CMP_SetInterruptConfig(cmp_interrupt_mask_t mask)
{
    uint32_t anaCtrl = SYSCON->ANACTRL_CTRL;

    if (mask & SYSCON_ANACTRL_CTRL_COMPINTRLVL_MASK)
    {
        /* level sensitive interrupt */
        anaCtrl |= SYSCON_ANACTRL_CTRL_COMPINTRLVL_MASK;
    }
    else
    {
        anaCtrl &= ~SYSCON_ANACTRL_CTRL_COMPINTRLVL_MASK;
    }
    /* interrupt polarity */
    anaCtrl = (anaCtrl & (~SYSCON_ANACTRL_CTRL_COMPINTRPOL_MASK)) |
              SYSCON_ANACTRL_CTRL_COMPINTRPOL(mask >> CMP_INT_POL_SHIFT_VALUE);

    SYSCON->ANACTRL_CTRL = anaCtrl;
}
