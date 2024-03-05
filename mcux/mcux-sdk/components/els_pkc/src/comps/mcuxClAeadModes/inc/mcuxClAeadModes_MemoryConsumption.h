/*--------------------------------------------------------------------------*/
/* Copyright 2021-2023 NXP                                                  */
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

/** @file  mcuxClAeadModes_MemoryConsumption.h
 *  @brief Defines the memory consumption for the clAeadModes component */

#ifndef MCUXCLAEADMODES_MEMORYCONSUMPTION_H_
#define MCUXCLAEADMODES_MEMORYCONSUMPTION_H_
/**
 * @defgroup mcuxClAead_MemoryConsumption mcuxClAead_MemoryConsumption
 * @brief Defines the memory consumption for the mcuxClAead component
 *        All work area sizes in bytes are a multiple of CPU wordsize.
 * @ingroup mcuxClAead
 * @{
 */

/* Macro to calculate the WA size in the CPU wordsize */
#define MCUXCLAEAD_SIZE_IN_CPUWORDS(size)  (((uint32_t) (size))  / (sizeof(uint32_t)))


#define MCUXCLAEAD_CRYPT_CPU_WA_BUFFER_SIZE          (124u)
#define MCUXCLAEAD_CRYPT_CPU_WA_BUFFER_SIZE_IN_WORDS MCUXCLAEAD_SIZE_IN_CPUWORDS(MCUXCLAEAD_CRYPT_CPU_WA_BUFFER_SIZE )

#define MCUXCLAEAD_INIT_CPU_WA_BUFFER_SIZE           (4u)
#define MCUXCLAEAD_INIT_CPU_WA_BUFFER_SIZE_IN_WORDS  MCUXCLAEAD_SIZE_IN_CPUWORDS(MCUXCLAEAD_INIT_CPU_WA_BUFFER_SIZE )




#define MCUXCLAEAD_PROCESS_CPU_WA_BUFFER_SIZE                (4u)
#define MCUXCLAEAD_PROCESS_CPU_WA_BUFFER_SIZE_IN_WORDS       MCUXCLAEAD_SIZE_IN_CPUWORDS(MCUXCLAEAD_PROCESS_CPU_WA_BUFFER_SIZE )
#define MCUXCLAEAD_PROCESS_ADATA_CPU_WA_BUFFER_SIZE          (4u)
#define MCUXCLAEAD_PROCESS_ADATA_CPU_WA_BUFFER_SIZE_IN_WORDS MCUXCLAEAD_SIZE_IN_CPUWORDS(MCUXCLAEAD_PROCESS_ADATA_CPU_WA_BUFFER_SIZE )
#define MCUXCLAEAD_FINISH_CPU_WA_BUFFER_SIZE                 (4u)
#define MCUXCLAEAD_FINISH_CPU_WA_BUFFER_SIZE_IN_WORDS        MCUXCLAEAD_SIZE_IN_CPUWORDS(MCUXCLAEAD_FINISH_CPU_WA_BUFFER_SIZE )
#define MCUXCLAEAD_VERIFY_CPU_WA_BUFFER_SIZE                 (4u)
#define MCUXCLAEAD_VERIFY_CPU_WA_BUFFER_SIZE_IN_WORDS        MCUXCLAEAD_SIZE_IN_CPUWORDS(MCUXCLAEAD_VERIFY_CPU_WA_BUFFER_SIZE )
#define MCUXCLAEAD_MAX_CPU_WA_BUFFER_SIZE                    (124u)
#define MCUXCLAEAD_MAX_CPU_WA_BUFFER_SIZE_IN_WORDS           MCUXCLAEAD_SIZE_IN_CPUWORDS(MCUXCLAEAD_MAX_CPU_WA_BUFFER_SIZE )

#define MCUXCLAEAD_CONTEXT_SIZE (124u)


/** @def MCUXCLAEAD_WA_SIZE_MAX
 *  @brief Define the max workarea size in bytes required for this component.
 *         Work area sizes in bytes are a multiple of CPU wordsize.
 */
#define MCUXCLAEAD_WA_SIZE_MAX (124u)
#define MCUXCLAEAD_WA_SIZE_IN_WORDS_MAX     MCUXCLAEAD_SIZE_IN_CPUWORDS(MCUXCLAEAD_WA_SIZE_MAX )

/**
 * @}
 */ /* mcuxClAead_MemoryConsumption */

#endif /* MCUXCLAEADMODES_MEMORYCONSUMPTION_H_ */
