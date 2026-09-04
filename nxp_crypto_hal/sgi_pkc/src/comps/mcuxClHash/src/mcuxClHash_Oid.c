/*--------------------------------------------------------------------------*/
/* Copyright 2025-2026 NXP                                                  */
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

#include <mcuxClCore_Platform.h>
#include <internal/mcuxClHash_Internal.h>

/**********************************************************/
/* Hash Algorithm OIDs                                    */
/**********************************************************/
const uint8_t mcuxClHash_oidSha2_224[MCUXCLHASH_OID_SHA2SHA3_LEN] __attribute__((section(".rodata.hash.oid"))) =
{
  // OID: 2.16.840.1.101.3.4.2.4
  0x30U, 0x2dU, 0x30U, 0x0dU, 0x06U, 0x09U, 0x60U, 0x86U, 0x48U, 0x01U, 0x65U, 0x03U, 0x04U, 0x02U, 0x04U, 0x05U, 0x00U, 0x04U, 0x1cU
};

const uint8_t mcuxClHash_oidSha2_256[MCUXCLHASH_OID_SHA2SHA3_LEN] __attribute__((section(".rodata.hash.oid"))) =
{
  // OID: 2.16.840.1.101.3.4.2.1
  0x30U, 0x31U, 0x30U, 0x0dU, 0x06U, 0x09U, 0x60U, 0x86U, 0x48U, 0x01U, 0x65U, 0x03U, 0x04U, 0x02U, 0x01U, 0x05U, 0x00U, 0x04U, 0x20U
};

const uint8_t mcuxClHash_oidSha2_384[MCUXCLHASH_OID_SHA2SHA3_LEN] __attribute__((section(".rodata.hash.oid"))) =
{
  // OID: 2.16.840.1.101.3.4.2.2
  0x30U, 0x41U, 0x30U, 0x0dU, 0x06U, 0x09U, 0x60U, 0x86U, 0x48U, 0x01U, 0x65U, 0x03U, 0x04U, 0x02U, 0x02U, 0x05U, 0x00U, 0x04U, 0x30U
};

const uint8_t mcuxClHash_oidSha2_512[MCUXCLHASH_OID_SHA2SHA3_LEN] __attribute__((section(".rodata.hash.oid"))) =
{
  // OID: 2.16.840.1.101.3.4.2.3
  0x30U, 0x51U, 0x30U, 0x0dU, 0x06U, 0x09U, 0x60U, 0x86U, 0x48U, 0x01U, 0x65U, 0x03U, 0x04U, 0x02U, 0x03U, 0x05U, 0x00U, 0x04U, 0x40U
};



#if defined(MCUXCL_FEATURE_HASH_C_SHA3_SHAKE) || defined(MCUXCL_FEATURE_HASH_C_SHA3)
const uint8_t mcuxClHash_oidSha3_224[MCUXCLHASH_OID_SHA2SHA3_LEN] __attribute__((section(".rodata.hash.oid"))) =
{
  // OID: 2.16.840.1.101.3.4.2.7
  0x30U, 0x2dU, 0x30U, 0x0dU, 0x06U, 0x09U, 0x60U, 0x86U, 0x48U, 0x01U, 0x65U, 0x03U, 0x04U, 0x02U, 0x07U, 0x05U, 0x00U, 0x04U, 0x1cU
};

const uint8_t mcuxClHash_oidSha3_256[MCUXCLHASH_OID_SHA2SHA3_LEN] __attribute__((section(".rodata.hash.oid"))) =
{
  // OID: 2.16.840.1.101.3.4.2.8
  0x30U, 0x31U, 0x30U, 0x0dU, 0x06U, 0x09U, 0x60U, 0x86U, 0x48U, 0x01U, 0x65U, 0x03U, 0x04U, 0x02U, 0x08U, 0x05U, 0x00U, 0x04U, 0x20U
};

const uint8_t mcuxClHash_oidSha3_384[MCUXCLHASH_OID_SHA2SHA3_LEN] __attribute__((section(".rodata.hash.oid"))) =
{
  // OID: 2.16.840.1.101.3.4.2.9
  0x30U, 0x41U, 0x30U, 0x0dU, 0x06U, 0x09U, 0x60U, 0x86U, 0x48U, 0x01U, 0x65U, 0x03U, 0x04U, 0x02U, 0x09U, 0x05U, 0x00U, 0x04U, 0x30U
};

const uint8_t mcuxClHash_oidSha3_512[MCUXCLHASH_OID_SHA2SHA3_LEN] __attribute__((section(".rodata.hash.oid"))) =
{
  // OID: 2.16.840.1.101.3.4.2.10
  0x30U, 0x51U, 0x30U, 0x0dU, 0x06U, 0x09U, 0x60U, 0x86U, 0x48U, 0x01U, 0x65U, 0x03U, 0x04U, 0x02U, 0x0aU, 0x05U, 0x00U, 0x04U, 0x40U
};

const uint8_t mcuxClHash_oidSha3_shake_128[MCUXCLHASH_OID_SHA2SHA3_LEN] __attribute__((section(".rodata.hash.oid"))) =
{
  // OID: 2.16.840.1.101.3.4.2.11
  0x30U, 0xb9U, 0x30U, 0x0dU, 0x06U, 0x09U, 0x60U, 0x86U, 0x48U, 0x01U, 0x65U, 0x03U, 0x04U, 0x02U, 0x0bU, 0x05U, 0x00U, 0x04U, 0xa8U
};

const uint8_t mcuxClHash_oidSha3_shake_256[MCUXCLHASH_OID_SHA2SHA3_LEN] __attribute__((section(".rodata.hash.oid"))) =
{
  // OID: 2.16.840.1.101.3.4.2.12
  0x30U, 0x99U, 0x30U, 0x0dU, 0x06U, 0x09U, 0x60U, 0x86U, 0x48U, 0x01U, 0x65U, 0x03U, 0x04U, 0x02U, 0x0cU, 0x05U, 0x00U, 0x04U, 0x88U
};
#endif /* MCUXCL_FEATURE_HASH_C_SHA3_SHAKE || MCUXCL_FEATURE_HASH_C_SHA3 */


#ifdef MCUXCL_FEATURE_HASH_C_SHA1
const uint8_t mcuxClHash_oidSha1[MCUXCLHASH_OID_SHA1_LEN] __attribute__((section(".rodata.hash.oid"))) =
{
  // OID: 1.3.14.3.2.26
  0x30U, 0x21U, 0x30U, 0x09U, 0x06U, 0x05U, 0x2bU, 0x0eU, 0x03U, 0x02U, 0x1aU, 0x05U, 0x00U, 0x04U, 0x14U
};
#endif /* MCUXCL_FEATURE_HASH_C_SHA1 */
