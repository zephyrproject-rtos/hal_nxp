/*--------------------------------------------------------------------------*/
/* Copyright 2025 NXP                                                       */
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
 * @file  mcuxClSession_FeatureConfig.h
 * @brief Internal feature flag configurations for mcuxClSession features
 */

#ifndef MCUXCLSESSION_FEATURECONFIG_H_
#define MCUXCLSESSION_FEATURECONFIG_H_

#include <mcuxClConfig.h> // Exported features flags header


/*
 * This file collects all dependencies of mcuxClSession functionality
 * to other components and checks the platform's feature flags config
 * for consistency in the mcuxClSession domain.
 * Public feature flags are translated into internal mcuxClSession features
 * which are used for guarding functions. This is needed to avoid the
 * inclusion of Session object fields and functions, which are not used
 * at all in the current platform's feature scope, in the build.
 * The aim of these internally defined feature flags is to have
 * sounding names for inclusion guards, and to have a single
 * point of translation from public features to all internal
 * usages.
 */

/**********************************************************************/
/* Internal mcuxClSession object features depending on available features  */
/**********************************************************************/

/* Inclusion of the internal mcuxClSession_cleanup_freedWorkareas.
 * It is currently only used in mcuxClRandomModes_cleanupOnExit which is only
 * compiled if MCUXCL_FEATURE_RANDOMMODES_NORMALMODE or MCUXCL_FEATURE_RANDOMMODES_TESTMODE is set. */
#define MCUXCLSESSION_FEATURE_INTERNAL_CLEANUP_FREED_WA

#endif /* MCUXCLSESSION_FEATURECONFIG_H_ */
