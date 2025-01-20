/*
 * The Clear BSD License
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 *  that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
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

#ifndef FSL_CIC_IRB_PRIVATE_H_
#define FSL_CIC_IRB_PRIVATE_H_

#include "fsl_common.h"

/*!
 * @addtogroup jn_cic_irb
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*  Calculating the value of IRB_CTU
 *
 * Clock input frequency is 48 MHz. The value of IRB_CTU is calculated as...
 *
 * 							48000000
 * 		------------------------------------------------
 * 		(IRB_CLOW + 1 IRB_CHIGH + 1) * carrier frequency
 *
 * Round this value. The actual carrier frequency for this rounded value of IRB_CTU
 * is calculated as...
 *
 * 						48000000
 * 		-------------------------------------------
 * 		(IRB_CLOW + 1 IRB_CHIGH + 1) * rnd(IRB_CTU)
 *
 * A bit takes 1.778 ms in RC5, but this is for both the high and low parts of the wave, so
 * each part is half that, i.e. 0.889 ms.
 *
 * The envelope time for a single width pulse is 0.000889 * actual carrier frequency.
 *
 * RC5 36 kHz example...
 *
 * IRB_CTU = 48000000 / ((1 + 1 + 0 + 1) * 36000000)
 *
 *     	   = 444.4444
 *
 * Rounded value for IRB_CTU = 444
 *
 * Actual carrier frequency from a value of 444 for IRB_CTU = 48000000 / ((1 + 1 + 0 + 1) * 444)
 *
 * 															= 36.036kHz
 *
 * Envelope value for a single width pulse = 0.000889 * 36036
 *
 * 										   = 32.04
 *
 * Round this to 32.
 */

#define ENVELOPE_ARRAY_SIZE                50 /* Sufficient for all currently supported protocols */
#define CIC_IRB_FIFO_SIZE                  16 /* Hardware value */
#define INV_ENV_LAST_BIT                   0x2000
#define INV_ENV_INT_BIT                    0x1000
#define DUTY_CYCLE_33_PERCENT_CARRIER_HIGH 0 /* Suitable for all currently supported protocols */
#define DUTY_CYCLE_33_PERCENT_CARRIER_LOW  1
#define CTU_36KHZ                          444 /* 444.444, 444 gives 36.036 kHz */
#define CTU_38KHZ                          421 /* 421.052, 421 gives 38.004 kHz */
#define CTU_40KHZ                          400 /* 400.000, 400 gives 40.000 kHz */

/**
 * CIC IRB instance data structure
 *
 */
typedef struct
{
    /* General peripheral data */
    cic_irb_protocols_t selectedProtocol;             /* Currently selected protocols */
    cic_irb_carrier_frequency_t carrierFrequency;     /* Selected carrier frequency */
    volatile uint16_t envelopes[ENVELOPE_ARRAY_SIZE]; /* Holds the envelopes to be loaded into the FIFO representing the
                                                         pulse bursts */
    volatile int8_t envelopeCount;                    /* The number of entries in the envelope array */
    volatile uint8_t
        nextEnvelopeToSend; /* The position in the envelope array to start loading into the next FIFO load */
    bool busy;              /* Busy flags set during transmission of a frame */
    bool startLevel;        /* The level the protocol starts at, i.e. first envelope */
    bool enabled;           /* If driver enabled and ready to send */

    /* RCx data */
    uint32_t RCxSinglePulseEnvelopeWidth;
    uint32_t RCxDoublePulseEnvelopeWidth;

    /* RC6 data */
    uint32_t RC6TriplePulseEnvelopeWidth; /* Used for toggle bit envelopes */
    uint32_t RC6HexPulseEnvelopeWidth;    /* Used for initial start bit first envelope */
} cic_irb_instance_data_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*! @name CIC_IRB Get Instance Data */
/*! @{ */
/*!
 *
 * @brief CIC_IRB_GetInstanceData
 *
 * Get a pointer to the data structure containing context
 * information for a peripheral instance
 *
 * @param base CIC_IRB peripheral base address.
 *
 * @return Pointer to the instance data structure
 *
 * NOTES: Returns NULL if an instance not found for base
 *
 */
cic_irb_instance_data_t *CIC_IRB_GetInstanceData(CIC_IRB_Type *base);
/*! @} */

/*! @name CIC_IRB RC5 Initialise */
/*! @{ */
/*!
 *
 * @brief CIC_IRB_RC5Initialise
 *
 * Initialise the peripheral ready to send RC5 messages.
 *
 * @param base CIC_IRB peripheral base address.
 *
 *
 */
void CIC_IRB_RC5Initialise(CIC_IRB_Type *base);
/*! @} */

/*! @name CIC_IRB RC6 Initialise */
/*! @{ */
/*!
 *
 * @brief CIC_IRB_RC6Initialise
 *
 * Initialise the peripheral ready to send RC6 messages.
 *
 * @param base CIC_IRB peripheral base address.
 *
 *
 */
void CIC_IRB_RC6Initialise(CIC_IRB_Type *base);
/*! @} */

/*! @name CIC_IRB SIRC Initialise */
/*! @{ */
/*!
 *
 * @brief CIC_IRB_SIRCInitialise
 *
 * Initialise the peripheral ready to send SIRC messages.
 *
 * @param base CIC_IRB peripheral base address.
 *
 *
 */
void CIC_IRB_SIRCInitialise(CIC_IRB_Type *base);
/*! @} */

/*! @name CIC_IRB RCMM Initialise */
/*! @{ */
/*!
 *
 * @brief CIC_IRB_RCMMInitialise
 *
 * Initialise the peripheral ready to send RCMM messages.
 *
 * @param base CIC_IRB peripheral base address.
 *
 *
 */
void CIC_IRB_RCMMInitialise(CIC_IRB_Type *base);
/*! @} */

/*! @name CIC_IRB RC5 Get Instance */
/*! @{ */
/*!
 *
 * @brief CIC_IRB_GetInstance
 *
 * Get the CIC_IRB instance from peripheral base address.
 *
 * @param base CIC_IRB peripheral base address.
 *
 * @return CIC_IRB instance number.
 *
 * NOTES: Returns FSL_FEATURE_SOC_CIC_IRB_COUNT if instance for base not found.
 *
 */
uint8_t CIC_IRB_GetInstance(CIC_IRB_Type *base);
/*! @} */

/*! @name CIC_IRB Load And Send Fifo */
/*! @{ */
/*!
 *
 * @brief CIC_IRB_LoadAndSendFifo
 *
 * Load the FIFO with the first part of a series of envelopes to
 * send. If a message's complete set of envelopes fits within the
 * FIFO size then the whole message will be sent. If not then the
 * maximum number of envelopes is loaded into the FIFO that is
 * possible. Subsequent FIFO loads for the remaining envelopes are
 * loaded into the FIFO in the interrupt handler which is triggered
 * when the FIFO becomes empty.
 *
 * @param base CIC_IRB peripheral base address.
 *
 *
 */
void CIC_IRB_LoadAndSendFifo(CIC_IRB_Type *base);
/*! @} */

/*! @name CIC_IRB RCx Append Envelopes */
/*! @{ */
/*!
 *
 * @brief CIC_IRB_RCxAppendEnvelopes
 *
 * Take a bit pattern that comprises part of a RCx message and
 * encode this in envelopes using the appropriate type of
 * Manchester encoding. The envelopes can be appended to
 * an array of previously encoded envelopes or can be a complete
 * message.
 *
 * @param bitPattern the binary data to encode into the message
 * @param bitCount the number of bits in bitPattern
 * @param instanceData pointer to the peripheral instance data structure
 * @param previousEnvelopeLevel the level of the last envelope of the preceding part of the encoded message
 * @param envelope pointer to array to add this bit pattern's encoded envelopes
 * @param ManchesterEncodingIEEE802_3 type of Manchester encoding, true for IEEE 802.3, false for Thomas
 *
 */
void CIC_IRB_RCxAppendEnvelopes(uint32_t bitPattern,
                                uint8_t bitCount,
                                cic_irb_instance_data_t *instanceData,
                                uint8_t *previousEnvelopeLevel,
                                int8_t *envelope,
                                bool ManchesterEncodingIEEE802_3);
/*! @} */

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /* FSL_CIC_IRB_PRIVATE_H_ */
