/*--------------------------------------------------------------------------*/
/* Copyright 2020-2025 NXP                                                  */
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

/**
 * @file  mcuxCsslFlowProtection_FunctionIdentifiers.h
 * @brief Definition of function identifiers for the flow protection mechanism.
 *
 * @note This file might be post-processed to update the identifier values to
 * proper/secure values.
 */

#ifndef MCUX_CSSL_FLOW_PROTECTION_FUNCTION_IDENTIFIERS_H_
#define MCUX_CSSL_FLOW_PROTECTION_FUNCTION_IDENTIFIERS_H_

/* Flow Protection example values: */
#define MCUX_CSSL_FP_FUNCID_functionOnly0                     (0x50DDu)
#define MCUX_CSSL_FP_FUNCID_functionOnly1                     (0x5595u)
#define MCUX_CSSL_FP_FUNCID_functionOnly2                     (0x6B52u)
#define MCUX_CSSL_FP_FUNCID_functionCall                      (0x50BBu)
#define MCUX_CSSL_FP_FUNCID_functionCalls                     (0x4E71u)
#define MCUX_CSSL_FP_FUNCID_functionLoop                      (0x4AF2u)
#define MCUX_CSSL_FP_FUNCID_functionBranch                    (0x0D3Bu)
#define MCUX_CSSL_FP_FUNCID_functionBranch1                   (0x26A7u)
#define MCUX_CSSL_FP_FUNCID_functionSwitch                    (0x22AFu)
#define MCUX_CSSL_FP_FUNCID_functionOnly0Assert               (0x533Cu)
#define MCUX_CSSL_FP_FUNCID_functionOnly1Assert               (0x43E9u)
#define MCUX_CSSL_FP_FUNCID_functionAssert                    (0x21DEu)
/* Values for production use: */
#define MCUX_CSSL_FP_FUNCID_mcuxCsslParamIntegrity_Validate    (0x1AA7u)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Compare             (0x696Cu)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Copy                (0x7D21u)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Clear               (0x42D7u)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Set                 (0x44F9u)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_SecureClear         (0x29BCu)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_SecureCopy          (0x27AAu)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_SecureSet           (0x5B58u)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_SecureCompare       (0x79C2u)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_DPASecureCompare    (0x5AF0u)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_DPASecComp      (0x629Du)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_Comp            (0x1E8Eu)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_CopyWords       (0x3761u)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecCopyPow2     (0x4A5Du)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecComp         (0x187Eu)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecClear        (0x2C3Bu)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecSet          (0x6655u)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_SecureXOR           (0x3366u)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_SecureXORWithConst  (0x4A97u)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_XOR             (0x17C5u)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecureSet       (0x781Bu)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecXOR          (0x562Bu)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecXOR_asm      (0x562B)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecXORRev       (0x4AA7u)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecXORRev_asm   (0x4AA7)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecXORWithConst (0x14F9u)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecXORWithConst_asm (0x14F9)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_Set             (0x53C3u)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Compare_arm_asm     (0x4DC5)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecCopy         (0x2EC5)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecCopyRev      (0x7D44)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_Copy_arm_asm    (0x2AE3)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_CompareRev_arm_asm  (0x7274)
#define MCUX_CSSL_FP_FUNCID_mcuxClMemory_compare_reversed_int  (0x7CE0u)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_CopyRev_arm_asm (0x3E94)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecComp_arm_asm (0x75A4)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_FastCompare_arm_asm (0x35E4)
#define MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_FastCompareRev_arm_asm (0x63F0)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_30                 (0x62BAu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_31                 (0x7549u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_32                 (0x77C0u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_33                 (0x662Eu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_34                 (0x521Fu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_35                 (0x6671u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_36                 (0x711Du)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_37                 (0x684Fu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_38                 (0x52EAu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_39                 (0x1EACu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_40                 (0x4D66u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_41                 (0x4557u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_42                 (0x25F2u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_43                 (0x278Bu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_44                 (0x3C55u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_45                 (0x1796u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_46                 (0x6732u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_47                 (0x67D0u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_48                 (0x5627u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_49                 (0x6AB1u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_50                 (0x5927u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_51                 (0x51CEu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_52                 (0x7585u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_53                 (0x78B1u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_54                 (0x0B5Du)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_55                 (0x6A87u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_56                 (0x19ABu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_57                 (0x57C1u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_58                 (0x589Du)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_59                 (0x61E3u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_60                 (0x0D2Fu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_61                 (0x5B1Cu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_62                 (0x3CD4u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_63                 (0x0C6Fu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_64                 (0x21BDu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_65                 (0x1D9Cu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_66                 (0x5674u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_67                 (0x60DDu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_68                 (0x78AAu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_69                 (0x0F36u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_70                 (0x6B2Au)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_71                 (0x2D63u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_72                 (0x2F16u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_73                 (0x4F1Cu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_74                 (0x5B83u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_75                 (0x7833u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_76                 (0x3B26u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_77                 (0x34DCu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_78                 (0x6E46u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_79                 (0x6F21u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_80                 (0x2937u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_81                 (0x1BE2u)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_82                 (0x2A9Bu)
#define MCUX_CSSL_FP_FUNCID_mcuxCssl_unused_83                 (0x78A3u)

#endif /* MCUX_CSSL_FLOW_PROTECTION_FUNCTION_IDENTIFIERS_H_ */
