/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021 NXP                                                  */
/*                                                                          */
/* NXP Confidential. This software is owned or controlled by NXP and may    */
/* only be used strictly in accordance with the applicable license terms.   */
/* By expressly accepting such terms or by downloading, installing,         */
/* activating and/or otherwise using the software, you are agreeing that    */
/* you have read, and that you agree to comply with and are bound by, such  */
/* license terms. If you do not agree to be bound by the applicable license */
/* terms, then you may not retain, install, activate or otherwise use the   */
/* software.                                                                */
/*--------------------------------------------------------------------------*/

/**
 * \file  mcuxCsslFlowProtection_Impl.h
 * \brief Selection of the implementation for the flow protection mechanism.
 */

#ifndef MCUX_CSSL_FLOW_PROTECTION_IMPL_H_
#define MCUX_CSSL_FLOW_PROTECTION_IMPL_H_

/* Include the configuration for the flow protection mechanism. */
#include <internal/mcuxCsslFlowProtection_Cfg.h>

/* Include the selected implementation of the flow protection mechanism. */
#if defined(MCUX_CSSL_FP_USE_HW_CSW) && (1 == MCUX_CSSL_FP_USE_HW_CSW)
#  include <internal/mcuxCsslFlowProtection_HW_CSW.h>
#elif defined(MCUX_CSSL_FP_USE_SECURE_COUNTER) \
      && (1 == MCUX_CSSL_FP_USE_SECURE_COUNTER)
#  include <internal/mcuxCsslSecureCounter_Cfg.h>
#  include <internal/mcuxCsslFlowProtection_SecureCounter_Common.h>
#  if defined(MCUX_CSSL_SC_USE_HW_SCM) && (1 == MCUX_CSSL_SC_USE_HW_SCM)
#    include <internal/mcuxCsslFlowProtection_SecureCounter_Global.h>
#  else
#    include <internal/mcuxCsslFlowProtection_SecureCounter_Local.h>
#  endif
#elif defined(MCUX_CSSL_FP_USE_NONE) && (1 == MCUX_CSSL_FP_USE_NONE)
#  include <internal/mcuxCsslFlowProtection_None.h>
#else
#  error "No flow protection implementation found/configured."
#endif

#endif /* MCUX_CSSL_FLOW_PROTECTION_IMPL_H_ */
