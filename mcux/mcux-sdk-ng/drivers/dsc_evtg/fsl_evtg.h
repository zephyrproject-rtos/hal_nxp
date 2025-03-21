/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_EVTG_H_
#define FSL_EVTG_H_

#include "fsl_common.h"

/*!
 * @defgroup evtg EVTG: Event Generator Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief EVTG driver version. */
#define FSL_EVTG_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup evtg_driver_log The Driver Change Log
 * @ingroup evtg
 * @{
 * The current EVTG driver version is 2.0.0
 *
 *  - 2.0.0
 *    - Initial version.
 * @}
 */

/*******************************************************************************
 * Introduction of peripheral and driver
 ******************************************************************************/
/*!
 * @defgroup evtg_intro EVTG Peripheral and Driver Overview
 * @ingroup evtg
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Peripheral feature and how this peripheral works
 * ==================================================
 * The Event Generator module is designed to be integrated in conjuction with one or more inter-peripheral crossbar
 * switch (XBAR) modules. A crossbar switch is typically used to select the 4 EVTG inputs from among available
 * peripheral outputs and GPIO signals. The EVTG outputs are typically used as additional inputs to a second crossbar
 * switch, adding to it the ability to connect to its outputs an arbitrary 4-input boolean function of its other inputs.
 * The input/output signals are chip specific, user has to check the reference manual or data sheet for the information.
 *
 * Features
 * ---------
 *  + The EVTG(Event Generator) module mainly includes two parts.
 *    - Two AND/OR/INVERT (known simply as the AOI) modules and one configurable Flip-Flop. It supports the
 *      generation of a configurable number of EVENT signals.
 *    - The two AOI combinational expressions share the four associated EVTG inputs: An, Bn, Cn, and Dn.
 *    - The Flip-Flop can be configured to make the two expressions act as the Reset port, Set port or D port, CLK port
 *	    or simply go through to EVTG output with FF(Flip-Flop) bypassed.
 *
 *  + Highly programmable module for creating combinational boolean events
 *    - Each EVTG has four inputs and two outputs.
 *      - Four inputs are from available peripheral outputs and GPIO signals.
 *      - Two outputs can operate as hardware trigger signals or for other purpose.
 *    - Each EVTG has two groups of AOI to generate two combinational expressions.
 *    - Each AOI evaluates a combinational boolean expression as the sum of four products where each product term
 *      includes all four selected input sources available as true or complement values.
 *
 *  + One flexible FF can be configured as RS, D-FF, T-FF, JK-FF, Latch.
 *
 *  + Programmable AOI output filter to remove AOI output glitch.
 *
 *  + All logics are synchronous in bus clk domain.
 *
 * How this peripheral works
 * -------------------------
 * EVTG module inside implements different kinds of Flip-Flop for the generation of desired EVTG output. Specific
 * functional differences can refer to reference manual. EVTG support sync to evtg inputs and filter function to AOI
 * output. The application scenario for both are different. Input sync feature makes evtg input sync for two bus_clk
 * cycles. Any glitch whose width is less than a bus clk period will be removed. But for Filter, though this module
 * works in bus_clk and have the same function as the first one, it's designed for filter. Any signal whose width
 * is less than Filter_Delay value will be filtered. Therefore, functions should be enabled depends on the actual
 * user case.Each selected AOI input term in each product term can be configured to produce a logical 0 or 1 or pass
 * the true or complement of the selected event input.
 *
 * How this driver is designed to make this peripheral work
 * =========================================================
 * This driver provide multiple APIs to configure Event Generator module. The APIs this driver provides can be
 * classified in 3 API groups:
 *
 *  + Initialization Interfaces
 *    - EVTG initial configuration covering all configurable fields.
 *
 *  + Force Init Flipflop Interfaces
 *    - The API in this function group can be used to force Flip-flop initial output value to be presented on
 *      flip-flop positive output.
 *
 *  + Input Interfaces
 *    - Configure each selected input term in each product term to produce a logical 0 or 1 or pass the true or
 *      complement of the selected event input.
 *
 *  How to use this driver
 *  =======================
 *  + To generate event output signals, invoke the EVTG_Init() function. It takes the argument in type of
 *    @ref evtg_config_t, which contains all EVTG features.
 *  + If needed, other API groups can be used to do individual EVTG configuration. invoke Force Init Flipflop Interface
 *    to force Flip-flop initial output value to be presented on flip-flop positive output. The functions in Input
 *    Interfaces can be used to configure each selected input term in each product term.
 *
 *  Typical Use Case
 *  ================
 *  EVTG module inside implements different kinds of Flip-Flop for the generation of desired EVTG output. Here take
 *  Bypass mode and JK-FF Mode as examples.
 *
 *  + Bypass Mode:
 *    - Configure an EVTG to expected Bypass mode.
 *    - In this mode, filp-flop will be passed, The two AOI expressions "AOI_0" and "AOI_1" will be directly assigned to
 *      EVTG outputs. User can choose to enable or disable input sync logic and filter function.
 *    - Here disable both input sync logic and filter function. The event logical expression example:(A & ~B)|(~A & B).
 *      Obviously, AOI0 expression is (A & ~B) | (~A & B).
 *    @code
          evtg_config_t sConfig;
          EVTG_GetDefaultConfig(&sConfig,kEVTG_FFMode_Bypass); //select Bypass mode as default.
          // Term0 is "A & ~B".
          sConfig.sAOI0Config.sProductTerm0.eAInput = kEVTG_Input_DirectPass;
          sConfig.sAOI0Config.sProductTerm0.eBInput = kEVTG_Input_Complement;
          sConfig.sAOI0Config.sProductTerm0.eCInput = kEVTG_Input_LogicOne;
          sConfig.sAOI0Config.sProductTerm0.eDInput = kEVTG_Input_LogicOne;
          // Term1 is "~A & B".
          sConfig.sAOI0Config.sProductTerm1.eAInput = kEVTG_Input_Complement;
          sConfig.sAOI0Config.sProductTerm1.eBInput = kEVTG_Input_DirectPass;
          sConfig.sAOI0Config.sProductTerm1.eCInput = kEVTG_Input_LogicOne;
          sConfig.sAOI0Config.sProductTerm1.eDInput = kEVTG_Input_LogicOne;

          EVTG_Init(EVTG, kEVTG_Index0, &sConfig);
 *    @endcode
 *
 *  + JK-FF Mode:
 *    - In general, JK Flip-Flop have four input ports: J, K , Q and CLK. And the logical expression is J&~Q | ~K&Q .
 *    - Suppose we set EVTG input "An" as "J" port, "Cn" as "K" port, "Dn" as "CLK" port, and "Q" port of Flip-Flop feed
 *      back and override "Bn", According to the JK logic expression, the AOI_0 expression will be "An&~Bn | Bn&~Cn",
 *      AOI_1 expression will be "Dn".
 *    @code
          evtg_config_t sConfig;
          // The AOI_0 expression is "An&~Bn | Bn&~Cn", the AOI_1 expression is "Dn".
          EVTG_GetDefaultConfig(&sConfig, kEVTG_FFMode_JKFF); //select kEVTG_FFMode_JKFF mode as default.

          EVTG_Init(EVTG, kEVTG_Index0, &sConfig);
 *    @endcode
 *
 * @}
 */

/*! @brief EVTG instance index. */
typedef enum _evtg_index
{
    kEVTG_Index0 = 0U, /*!< EVTG instance index 0. */
    kEVTG_Index1 = 1U, /*!< EVTG instance index 1. */
    kEVTG_Index2 = 2U, /*!< EVTG instance index 2. */
    kEVTG_Index3 = 3U  /*!< EVTG instance index 3. */
} evtg_index_t;

/*! @brief EVTG input index. */
typedef enum _evtg_input_index
{
    kEVTG_InputA = 0U, /*!< EVTG input A. */
    kEVTG_InputB = 1U, /*!< EVTG input B. */
    kEVTG_InputC = 2U, /*!< EVTG input C. */
    kEVTG_InputD = 3U  /*!< EVTG input D. */
} evtg_input_index_t;

/*! @brief EVTG AOI index. */
typedef enum _evtg_aoi_index
{
    kEVTG_AOI0 = 0U, /*!< EVTG AOI index 0. */
    kEVTG_AOI1 = 1U  /*!< EVTG AOI index 1. */
} evtg_aoi_index_t;

/*! @brief EVTG AOI product term index. */
typedef enum _evtg_aoi_product_term
{
    kEVTG_ProductTerm0 = 0U, /*!< EVTG AOI product term index 0. */
    kEVTG_ProductTerm1 = 1U, /*!< EVTG AOI product term index 1. */
    kEVTG_ProductTerm2 = 2U, /*!< EVTG AOI product term index 2. */
    kEVTG_ProductTerm3 = 3U  /*!< EVTG AOI product term index 3. */
} evtg_aoi_product_term_t;

/*! @brief EVTG input configuration. */
typedef enum _evtg_aoi_input_config
{
    kEVTG_Input_LogicZero  = 0U, /*!< Force input in product term to a logical zero. */
    kEVTG_Input_DirectPass = 1U, /*!< Pass input in product term. */
    kEVTG_Input_Complement = 2U, /*!< Complement input in product term. */
    kEVTG_Input_LogicOne   = 3U  /*!< Force input in product term to a logical one. */
} evtg_aoi_input_config_t;

/*! @brief EVTG AOI Output Filter Sample Count. */
typedef enum _evtg_aoi_outfilter_count
{
    kEVTG_AOIOutFilter_SampleCount3  = 0U, /*!< EVTG AOI output filter sample count is 3. */
    kEVTG_AOIOutFilter_SampleCount4  = 1U, /*!< EVTG AOI output filter sample count is 4. */
    kEVTG_AOIOutFilter_SampleCount5  = 2U, /*!< EVTG AOI output filter sample count is 5. */
    kEVTG_AOIOutFilter_SampleCount6  = 3U, /*!< EVTG AOI output filter sample count is 6. */
    kEVTG_AOIOutFilter_SampleCount7  = 4U, /*!< EVTG AOI output filter sample count is 7. */
    kEVTG_AOIOutFilter_SampleCount8  = 5U, /*!< EVTG AOI output filter sample count is 8. */
    kEVTG_AOIOutFilter_SampleCount9  = 6U, /*!< EVTG AOI output filter sample count is 9. */
    kEVTG_AOIOutFilter_SampleCount10 = 7U  /*!< EVTG AOI output filter sample count is 10. */
} evtg_aoi_outfilter_count_t;

/*!
 * @brief EVTG output feedback override control mode. When FF is configured as JK-FF mode,
 *        need EVTG_OUTA feedback to EVTG input and replace one of the four inputs.
 */
typedef enum _evtg_outfdbk_override_input
{
    kEVTG_Output_OverrideInputA = 0U, /*!< Replace input A. */
    kEVTG_Output_OverrideInputB = 1U, /*!< Replace input B. */
    kEVTG_Output_OverrideInputC = 2U, /*!< Replace input C. */
    kEVTG_Output_OverrideInputD = 3U, /*!< Replace input D. */
} evtg_outfdbk_override_input_t;

/*! @brief EVTG flip flop mode configuration. */
typedef enum _evtg_flipflop_mode
{
    kEVTG_FFMode_Bypass = 0U,    /*!< Bypass mode (default).In this mode, user can choose to enable
                                    or disable input sync logic and filter function. */
    kEVTG_FFMode_RSTrigger = 1U, /*!< RS trigger mode. In this mode, user can choose to enable
                                    or disable input sync logic and filter function. */
    kEVTG_FFMode_TFF = 2U,       /*!< T-FF mode. In this mode, input sync or filter has to be enabled
                                    to remove the possible glitch.*/
    kEVTG_FFMode_DFF = 3U,       /*!< D-FF mode. In this mode, input sync or filter has to be enabled
                                    to remove the possible glitch.*/
    kEVTG_FFMode_JKFF = 4U,      /*!< JK-FF mode. In this mode, input sync or filter has to be enabled
                                    to remove the possible glitch.*/
    kEVTG_FFMode_Latch = 5U      /*!< Latch mode. In this mode, input sync or filter has to be enabled
                                    to remove the possible glitch.*/
} evtg_flipflop_mode_t;

/*! @brief EVTG flip-flop initial value. */
typedef enum _evtg_flipflop_initoutput
{
    kEVTG_FF_InitOut0 = 0U, /*!< Configure the positive output of flip-flop as 0. */
    kEVTG_FF_InitOut1 = 1U, /*!< Configure the positive output of flip-flop as 1. */
} evtg_flipflop_init_output_t;

/*! @brief The structure for configuring an AOI output filter sample.
 *
 * AOI output filter sample count represent the number of consecutive samples that must agree prior to the AOI output
 * filter accepting an transition.
 * AOI output filter sample period represent the sampling period (in IP bus clock cycles) of the AOI output signals.
 * Each AOI output is sampled multiple times at the rate specified by this period.
 *
 * For the modes with Filter function enabled, filter delay is "(FILT_CNT + 3) x FILT_PER + 2".
 *
 */
typedef struct _evtg_aoi_outfilter_config
{
    evtg_aoi_outfilter_count_t eSampleCount; /*!< EVTG AOI output filter sample count.
                                                refer to @ref evtg_aoi_outfilter_count_t. */
    uint8_t u8SamplePeriod;                  /*!< EVTG AOI output filter sample period, within 0~255. If sample period
                                                value is 0x00 (default), then the input filter is bypassed. */
} evtg_aoi_outfilter_config_t;

/*! @brief The structure for configuring an AOI product term. */
typedef struct _evtg_aoi_product_term_config
{
    evtg_aoi_input_config_t eAInput : 2; /*!< Input A configuration. */
    evtg_aoi_input_config_t eBInput : 2; /*!< Input B configuration. */
    evtg_aoi_input_config_t eCInput : 2; /*!< Input C configuration. */
    evtg_aoi_input_config_t eDInput : 2; /*!< Input D configuration. */
} evtg_aoi_product_term_config_t;

/*! @brief EVTG AOI configuration structure. */
typedef struct _evtg_aoi_config
{
    /* AOI Output Filter configuration. */
    evtg_aoi_outfilter_config_t sAOIOutFilterConfig; /*!< EVTG AOI output filter sample
                                                        configuration structure. */

    /* Product term configuration. */
    evtg_aoi_product_term_config_t sProductTerm0; /*!< Configure AOI product term0. */
    evtg_aoi_product_term_config_t sProductTerm1; /*!< Configure AOI product term1. */
    evtg_aoi_product_term_config_t sProductTerm2; /*!< Configure AOI product term2. */
    evtg_aoi_product_term_config_t sProductTerm3; /*!< Configure AOI product term3. */
} evtg_aoi_config_t;

/*! @brief EVTG configuration covering all configurable fields. */
typedef struct _evtg_config
{
    /* Input configuration. */
    bool bEnableInputASync : 1; /*!< Enable/Disable EVTG A input synchronous with bus clk. */
    bool bEnableInputBSync : 1; /*!< Enable/Disable EVTG B input synchronous with bus clk. */
    bool bEnableInputCSync : 1; /*!< Enable/Disable EVTG C input synchronous with bus clk. */
    bool bEnableInputDSync : 1; /*!< Enable/Disable EVTG D input synchronous with bus clk. */
    evtg_outfdbk_override_input_t eOutfdbkOverideinput : 2; /*!< EVTG output feedback to EVTG input
                                                               and replace one of the four inputs. */

    /* Flip-flop configuration. */
    evtg_flipflop_mode_t eFlipflopMode : 3; /*!< Flip-Flop can be configured as one of Bypass mode, RS trigger mode,
                                               T-FF mode, D-FF mode, JK-FF mode, Latch mode. */
    bool bEnableFlipflopInitOutput : 1;     /*!< Flip-flop initial output value enable/disable. */
    evtg_flipflop_init_output_t eFlipflopInitOutputValue : 1; /*!< Flip-flop initial output value configuration. */

#if defined(FSL_FEATURE_EVTG_HAS_FORCE_BYPASS_FLIPFLOP) && FSL_FEATURE_EVTG_HAS_FORCE_BYPASS_FLIPFLOP
    bool bEnableForceBypassFlipFlopAOI0 : 1; /*!< Enable/Disable force bypass Flip-Flop and route the AOI_0(Filter_0)
                                                value directly to EVTG_OUTA */
    bool bEnableForceBypassFlipFlopAOI1 : 1; /*!< Enable/Disable force bypass Flip-Flop and route the AOI_1(Filter_1)
                                                value directly to EVTG_OUTB */
#endif

    /* AOI configuration. */
    evtg_aoi_config_t sAOI0Config; /*!< Configure EVTG AOI0. */
    evtg_aoi_config_t sAOI1Config; /*!< Configure EVTG AOI1. */
} evtg_config_t;

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization Interfaces
 * @{
 */

/*!
 * @brief Initialize EVTG with a user configuration structure.
 *
 * @param base       EVTG base address.
 * @param eEvtgIndex EVTG instance index.
 * @param psConfig   EVTG initial configuration structure pointer.
 */
void EVTG_Init(EVTG_Type *base, evtg_index_t eEvtgIndex, evtg_config_t *psConfig);

/*!
 * @brief Loads default values to the EVTG configuration structure.
 *
 *  The purpose of this API is to initialize the configuration structure to default value for @ref EVTG_Init()
 *  to use.
 *  The Flip-Flop can be configured as Bypass mode, RS trigger mode, T-FF mode, D-FF mode, JK-FF mode, Latch mode.
 *  Please check RM INTC chapter for more details.
 *
 * @param psConfig      EVTG initial configuration structure pointer.
 * @param eFlipflopMode EVTG flip flop mode. see @ ref _evtg_flipflop_mode
 */
static inline void EVTG_GetDefaultConfig(evtg_config_t *psConfig, evtg_flipflop_mode_t eFlipflopMode)
{
    /* Initializes the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(evtg_config_t));

    switch (eFlipflopMode)
    {
        case kEVTG_FFMode_Bypass:

            /*
             * In this mode, filp-flop will be passed, The two AOI expressions "AOI_0" and "AOI_1"
             * will be directly assigned to EVTG outputs(EVTG_OUTA and EVTG_OUTB).
             *
             * In this mode, user can choose to enable or disable input sync logic and filter function.
             * Here disable both input sync logic and filter function.
             */
            psConfig->eFlipflopMode = kEVTG_FFMode_Bypass;

            psConfig->bEnableInputASync = false;
            psConfig->bEnableInputBSync = false;
            psConfig->bEnableInputCSync = false;
            psConfig->bEnableInputDSync = false;

            break;

        case kEVTG_FFMode_RSTrigger:

            /*
             * In this mode, AOI_0 expression is Reset port, and AOI_1 is Set port. Both are active
             * high. When "R"(Reset) is high, whatever "S"(Set) is, EVTG_OUTA will be "0". When "R" is
             * low and "S" is high, EVTG_OUTA will be "1". If both "R" and "S" are low, EVTG output
             * will be kept. EVTG_OUTB is always the complement of EVTG_OUTA.
             *
             * In this mode, user can choose to enable or disable input sync logic and filter function.
             * Here disable both input sync logic and filter function.
             */
            psConfig->eFlipflopMode = kEVTG_FFMode_RSTrigger;

            psConfig->bEnableInputASync = false;
            psConfig->bEnableInputBSync = false;
            psConfig->bEnableInputCSync = false;
            psConfig->bEnableInputDSync = false;

            break;

        case kEVTG_FFMode_TFF:

            /*
             * In this mode, AOI_0 expression is T port of T-FF, AOI_1 is CLK port. When T assert,
             * the Q port (EVTG_OUTA) will turnover at the rising edge of "CLK". When T dis-assert,
             * Q(EVTG_OUTA) will be kept. EVTG_OUTB is always the complement of EVTG_OUTA.
             *
             * In this mode, input sync or filter has to be enabled to remove the possible glitch.
             * Here input sync is enabled, filter is disabled. User could override corresponding fields
             * depends on the actual user case to choose to enable or disable input sync logic and filter
             * function.
             */
            psConfig->eFlipflopMode = kEVTG_FFMode_TFF;

            psConfig->bEnableInputASync = true;
            psConfig->bEnableInputBSync = true;
            psConfig->bEnableInputCSync = true;
            psConfig->bEnableInputDSync = true;

            break;

        case kEVTG_FFMode_JKFF:

            /*
             * In general, JK Flip-Flop have four input ports: J, K , Q and CLK(Q is output of Flip-Flop).
             * And the logical expression is J&~Q | ~K&Q;  Here we implement the logic expression by AOI
             * so that we can reuse the D-FF to implement JK-FF. Suppose we set EVTG input "An" as "J" port,
             * "Cn" as "K" port, "Dn" as "CLK" port, and "Q" port of FF feed back and override "Bn".
             * According to the JK logic expression, the AOI_0 expression will be "An&~Bn | Bn&~Cn",
             * AOI_1 expression will be "Dn".
             *
             * In this mode, input sync or filter has to be enabled to remove the possible glitch.
             * Here input sync is enabled, filter is disabled. User could override corresponding fields
             * depends on the actual user case to choose to enable or disable input sync logic and filter
             * function.
             *
             * When FF Mode is configured as JK-FF mode, need EVTG_OUTA feedback to EVTG input and replace
             * one of the four inputs. Here input Bn is replaced, represents which EVTG input(EVTG_OUTA)
             * is replaced by FF output.
             */
            psConfig->eFlipflopMode        = kEVTG_FFMode_JKFF;
            psConfig->eOutfdbkOverideinput = kEVTG_Output_OverrideInputB;

            psConfig->bEnableInputASync = true;
            psConfig->bEnableInputBSync = true;
            psConfig->bEnableInputCSync = true;
            psConfig->bEnableInputDSync = true;

            break;

        case kEVTG_FFMode_Latch:

            /*
             * In this mode, AOI_0 expression is D port, AOI_1 is CLK port. Different from D-FF
             * mode, in Latch mode, D port will be passed only when CLK is high, and output will be
             * kept when CLK is low. EVTG_OUTB is always the complement of EVTG_OUTA.
             *
             * In this mode, input sync or filter has to be enabled to remove the possible glitch.
             * Here input sync is enabled, filter is disabled. User could override corresponding fields
             * depends on the actual user case to choose to enable or disable input sync logic and filter
             * function.
             */
            psConfig->eFlipflopMode = kEVTG_FFMode_Latch;

            psConfig->bEnableInputASync = true;
            psConfig->bEnableInputBSync = true;
            psConfig->bEnableInputCSync = true;
            psConfig->bEnableInputDSync = true;

            break;

        default:
            assert(false);
    }
    /* User could choose to enable or disable Flip-flop initial output value. */
    psConfig->bEnableFlipflopInitOutput = false;
    psConfig->eFlipflopInitOutputValue  = kEVTG_FF_InitOut0;

    /* User could choose to override this fields to enable filter function. */
    psConfig->sAOI0Config.sAOIOutFilterConfig.eSampleCount   = kEVTG_AOIOutFilter_SampleCount3;
    psConfig->sAOI0Config.sAOIOutFilterConfig.u8SamplePeriod = 0;

    psConfig->sAOI1Config.sAOIOutFilterConfig.eSampleCount   = kEVTG_AOIOutFilter_SampleCount3;
    psConfig->sAOI1Config.sAOIOutFilterConfig.u8SamplePeriod = 0;

#if defined(FSL_FEATURE_EVTG_HAS_FORCE_BYPASS_FLIPFLOP) && FSL_FEATURE_EVTG_HAS_FORCE_BYPASS_FLIPFLOP
    psConfig->bEnableForceBypassFlipFlopAOI0 = false;
    psConfig->bEnableForceBypassFlipFlopAOI1 = false;
#endif

    /*
     * For JK-FF Mode, Here we implement the logic expression by AOI so that we can reuse the
     * D-FF to implement JK-FF. Suppose we set EVTG input "An" as "J" port, "Cn" as "K" port, "Dn"
     * as "CLK" port, and "Q" port of FF feed back and override "Bn". According to the JK logic
     * expression, the AOI_0 expression will be "An&~Bn | Bn&~Cn", AOI_1 expression will be "Dn".
     *
     * For other FF Mode, the default input here is logical 0. User can configure to produce a logical 0
     * or 1 or pass the true or complement of the selected event input according to their requirement.
     */
    if (kEVTG_FFMode_JKFF == eFlipflopMode)
    {
        psConfig->sAOI0Config.sProductTerm0.eAInput = kEVTG_Input_DirectPass;
        psConfig->sAOI0Config.sProductTerm0.eBInput = kEVTG_Input_Complement;
        psConfig->sAOI0Config.sProductTerm0.eCInput = kEVTG_Input_LogicOne;
        psConfig->sAOI0Config.sProductTerm0.eDInput = kEVTG_Input_LogicOne;

        psConfig->sAOI0Config.sProductTerm1.eAInput = kEVTG_Input_LogicOne;
        psConfig->sAOI0Config.sProductTerm1.eBInput = kEVTG_Input_DirectPass;
        psConfig->sAOI0Config.sProductTerm1.eCInput = kEVTG_Input_Complement;
        psConfig->sAOI0Config.sProductTerm1.eDInput = kEVTG_Input_LogicOne;

        psConfig->sAOI0Config.sProductTerm2.eAInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm2.eBInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm2.eCInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm2.eDInput = kEVTG_Input_LogicZero;

        psConfig->sAOI0Config.sProductTerm3.eAInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm3.eBInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm3.eCInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm3.eDInput = kEVTG_Input_LogicZero;

        psConfig->sAOI1Config.sProductTerm0.eAInput = kEVTG_Input_LogicOne;
        psConfig->sAOI1Config.sProductTerm0.eBInput = kEVTG_Input_LogicOne;
        psConfig->sAOI1Config.sProductTerm0.eCInput = kEVTG_Input_LogicOne;
        psConfig->sAOI1Config.sProductTerm0.eDInput = kEVTG_Input_DirectPass;

        psConfig->sAOI1Config.sProductTerm1.eAInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm1.eBInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm1.eCInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm1.eDInput = kEVTG_Input_LogicZero;

        psConfig->sAOI1Config.sProductTerm2.eAInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm2.eBInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm2.eCInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm2.eDInput = kEVTG_Input_LogicZero;

        psConfig->sAOI1Config.sProductTerm3.eAInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm3.eBInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm3.eCInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm3.eDInput = kEVTG_Input_LogicZero;
    }
    else
    {
        psConfig->sAOI0Config.sProductTerm0.eAInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm0.eBInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm0.eCInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm0.eDInput = kEVTG_Input_LogicZero;

        psConfig->sAOI0Config.sProductTerm1.eAInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm1.eBInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm1.eCInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm1.eDInput = kEVTG_Input_LogicZero;

        psConfig->sAOI0Config.sProductTerm2.eAInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm2.eBInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm2.eCInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm2.eDInput = kEVTG_Input_LogicZero;

        psConfig->sAOI0Config.sProductTerm3.eAInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm3.eBInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm3.eCInput = kEVTG_Input_LogicZero;
        psConfig->sAOI0Config.sProductTerm3.eDInput = kEVTG_Input_LogicZero;

        psConfig->sAOI1Config.sProductTerm0.eAInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm0.eBInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm0.eCInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm0.eDInput = kEVTG_Input_LogicZero;

        psConfig->sAOI1Config.sProductTerm1.eAInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm1.eBInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm1.eCInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm1.eDInput = kEVTG_Input_LogicZero;

        psConfig->sAOI1Config.sProductTerm2.eAInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm2.eBInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm2.eCInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm2.eDInput = kEVTG_Input_LogicZero;

        psConfig->sAOI1Config.sProductTerm3.eAInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm3.eBInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm3.eCInput = kEVTG_Input_LogicZero;
        psConfig->sAOI1Config.sProductTerm3.eDInput = kEVTG_Input_LogicZero;
    }
}
/*! @} */

/*!
 * @name Force Init Flipflop Interfaces
 * @{
 */

/*!
 * @brief Force Flip-flop initial output value to be presented on flip-flop positive output.
 *
 * @param base                EVTG base address.
 * @param eEvtgIndex          EVTG instance index.
 * @param eFlipflopInitOutputValue EVTG flip-flop initial output control.
 *                                 see @ref evtg_flipflop_init_output_t
 */
static inline void EVTG_ForceFlipflopInitOutput(EVTG_Type *base,
                                                evtg_index_t eEvtgIndex,
                                                evtg_flipflop_init_output_t eFlipflopInitOutputValue)
{
    base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_CTRL &= (~EVTG_EVTG_CTRL_FF_INIT_MASK);
    base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_CTRL |= EVTG_EVTG_CTRL_FF_INIT((uint16_t)eFlipflopInitOutputValue);
    /* INIT_EN bit should be set after FF_INIT is set. */
    base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_CTRL |= EVTG_EVTG_CTRL_INIT_EN_MASK;
}
/*! @} */

/*!
 * @name Input Interfaces
 * @{
 */
/*!
 * @brief Configure each input value of AOI product term. Each selected input term in
 *        each product term can be configured to produce a logical 0 or 1 or pass the
 *        true or complement of the selected event input. Adapt to some simple aoi
 *        expressions.
 *
 * @param base         EVTG base address.
 * @param eEvtgIndex   EVTG instance index.
 * @param eAOIIndex    EVTG AOI index. see enum ref evtg_aoi_index_t
 * @param eProductTerm EVTG product term index.
 * @param eInputIndex  EVTG input index.
 * @param eInput       EVTG input configuration with enum @ref evtg_aoi_input_config_t.
 */
static inline void EVTG_SetProductTermInput(EVTG_Type *base,
                                            evtg_index_t eEvtgIndex,
                                            evtg_aoi_index_t eAOIIndex,
                                            evtg_aoi_product_term_t eProductTerm,
                                            evtg_input_index_t eInputIndex,
                                            evtg_aoi_input_config_t eInput)
{
    if (kEVTG_AOI0 == eAOIIndex)
    {
        if ((eProductTerm == kEVTG_ProductTerm0) || (eProductTerm == kEVTG_ProductTerm1))
        {
            base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI0_BFT01 &=
                (~(3U << ((3U - ((uint8_t)eInputIndex)) * 2U + (((3U - (uint8_t)eProductTerm) % 2U) * 8U))));
            base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI0_BFT01 |=
                (((uint16_t)(((uint16_t)(eInput))
                             << ((3U - ((uint8_t)eInputIndex)) * 2U + (((3U - (uint8_t)eProductTerm) % 2U) * 8U)))) &
                 (3U << ((3U - ((uint8_t)eInputIndex)) * 2U + (((3U - (uint8_t)eProductTerm) % 2U) * 8U))));
        }
        else
        {
            base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI0_BFT23 &=
                (~(3U << ((3U - ((uint8_t)eInputIndex)) * 2U + (((3U - (uint8_t)eProductTerm) % 2U) * 8U))));
            base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI0_BFT23 |=
                (((uint16_t)(((uint16_t)(eInput))
                             << ((3U - ((uint8_t)eInputIndex)) * 2U + (((3U - (uint8_t)eProductTerm) % 2U) * 8U)))) &
                 (3U << ((3U - ((uint8_t)eInputIndex)) * 2U + (((3U - (uint8_t)eProductTerm) % 2U) * 8U))));
        }
    }
    else if (kEVTG_AOI1 == eAOIIndex)
    {
        if ((eProductTerm == kEVTG_ProductTerm0) || (eProductTerm == kEVTG_ProductTerm1))
        {
            base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI1_BFT01 &=
                (~(3U << ((3U - ((uint8_t)eInputIndex)) * 2U + (((3U - (uint8_t)eProductTerm) % 2U) * 8U))));
            base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI1_BFT01 |=
                (((uint16_t)(((uint16_t)(eInput))
                             << ((3U - ((uint8_t)eInputIndex)) * 2U + (((3U - (uint8_t)eProductTerm) % 2U) * 8U)))) &
                 (3U << ((3U - ((uint8_t)eInputIndex)) * 2U + (((3U - (uint8_t)eProductTerm) % 2U) * 8U))));
        }
        else
        {
            base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI1_BFT23 &=
                (~(3U << ((3U - ((uint8_t)eInputIndex)) * 2U + (((3U - (uint8_t)eProductTerm) % 2U) * 8U))));
            base->EVTG_INST[(uint8_t)eEvtgIndex].EVTG_AOI1_BFT23 |=
                (((uint16_t)(((uint16_t)(eInput))
                             << ((3U - ((uint8_t)eInputIndex)) * 2U + (((3U - (uint8_t)eProductTerm) % 2U) * 8U)))) &
                 (3U << ((3U - ((uint8_t)eInputIndex)) * 2U + (((3U - (uint8_t)eProductTerm) % 2U) * 8U))));
        }
    }
}

/*!
 * @brief Configure AOI product term by initializing the product term
 *        configuration structure.
 *
 * @param base                EVTG base address.
 * @param eEvtgIndex          EVTG instance index.
 * @param eAOIIndex           EVTG AOI index. see enum @ref evtg_aoi_index_t
 * @param eProductTerm        EVTG AOI product term index.
 * @param psProductTermConfig Pointer to EVTG product term configuration structure.
 *                            see ref _evtg_aoi_product_term_config
 */
void EVTG_ConfigAOIProductTerm(EVTG_Type *base,
                               evtg_index_t eEvtgIndex,
                               evtg_aoi_index_t eAOIIndex,
                               evtg_aoi_product_term_t eProductTerm,
                               evtg_aoi_product_term_config_t *psProductTermConfig);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_EVTG_H_ */
