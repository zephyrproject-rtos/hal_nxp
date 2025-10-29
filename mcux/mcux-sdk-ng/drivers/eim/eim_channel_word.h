/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef EIM_CHANNEL_WORD_H_
#define EIM_CHANNEL_WORD_H_

#define _REG(ch, i) ( (base)->EICHD##ch##_WORD##i )
#define _MASK_FUNC(ch, i, BIT) EIM_EICHD##ch##_WORD##i##_B##BIT##DATA_MASK
#define _MASK(ch, i, BIT) EIM_EICHD##ch##_WORD##i##_B##BIT##DATA_MASK_MASK
#define _SHIFT(ch, i, BIT) EIM_EICHD##ch##_WORD##i##_B##BIT##DATA_MASK_SHIFT

#define _SET(base, ch, i, BIT, mask) \
    _REG(ch, i) = _MASK_FUNC(ch, i, BIT)(mask); break;

#define _GET(base, ch, i, BIT) \
    mask = ( (_REG(ch, i) & _MASK(ch, i, BIT)) >> _SHIFT(ch, i, BIT) ); break;

#define SET_0_1 case 1: _SET(base,0,1,0_3,mask)
#define GET_0_1 case 1: _GET(base,0,1,0_3)

#if defined(EIM_EICHD0_WORD2_B4_7DATA_MASK_MASK)
#define SET_0_2 case 2: _SET(base,0,2,4_7,mask)
#define GET_0_2 case 2: _GET(base,0,2,4_7)
#else
#define SET_0_2
#define GET_0_2
#endif

#if defined(EIM_EICHD0_WORD3_B8_11DATA_MASK_MASK)
#define SET_0_3 case 3: _SET(base,0,3,8_11,mask)
#define GET_0_3 case 3: _GET(base,0,3,8_11)
#else
#define SET_0_3
#define GET_0_3
#endif

#if defined(EIM_EICHD0_WORD4_B12_15DATA_MASK_MASK)
#define SET_0_4 case 4: _SET(base,0,4,12_15,mask)
#define GET_0_4 case 4: _GET(base,0,4,12_15)
#else
#define SET_0_4
#define GET_0_4
#endif

#if defined(EIM_EICHD0_WORD5_B16_19DATA_MASK_MASK)
#define SET_0_5 case 5: _SET(base,0,5,16_19,mask)
#define GET_0_5 case 5: _GET(base,0,5,16_19)
#else
#define SET_0_5
#define GET_0_5
#endif

#if defined(EIM_EICHD0_WORD6_B20_23DATA_MASK_MASK)
#define SET_0_6 case 6: _SET(base,0,6,20_23,mask)
#define GET_0_6 case 6: _GET(base,0,6,20_23)
#else
#define SET_0_6
#define GET_0_6
#endif

#if defined(EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK)
#define SET_1_1 case 1: _SET(base,1,1,0_3,mask)
#define GET_1_1 case 1: _GET(base,1,1,0_3)
#else
#define SET_1_1
#define GET_1_1
#endif

#if defined(EIM_EICHD1_WORD2_B4_7DATA_MASK_MASK)
#define SET_1_2 case 2: _SET(base,1,2,4_7,mask)
#define GET_1_2 case 2: _GET(base,1,2,4_7)
#else
#define SET_1_2
#define GET_1_2
#endif

#if defined(EIM_EICHD1_WORD3_B8_11DATA_MASK_MASK)
#define SET_1_3 case 3: _SET(base,1,3,8_11,mask)
#define GET_1_3 case 3: _GET(base,1,3,8_11)
#else
#define SET_1_3
#define GET_1_3
#endif

#if defined(EIM_EICHD1_WORD4_B12_15DATA_MASK_MASK)
#define SET_1_4 case 4: _SET(base,1,4,12_15,mask)
#define GET_1_4 case 4: _GET(base,1,4,12_15)
#else
#define SET_1_4
#define GET_1_4
#endif

#if defined(EIM_EICHD1_WORD5_B16_19DATA_MASK_MASK)
#define SET_1_5 case 5: _SET(base,1,5,16_19,mask)
#define GET_1_5 case 5: _GET(base,1,5,16_19)
#else
#define SET_1_5
#define GET_1_5
#endif

#if defined(EIM_EICHD1_WORD6_B20_23DATA_MASK_MASK)
#define SET_1_6 case 6: _SET(base,1,6,20_23,mask)
#define GET_1_6 case 6: _GET(base,1,6,20_23)
#else
#define SET_1_6
#define GET_1_6
#endif

#if defined(EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK)
#define SET_2_1 case 1: _SET(base,2,1,0_3,mask)
#define GET_2_1 case 1: _GET(base,2,1,0_3)
#else
#define SET_2_1
#define GET_2_1
#endif

#if defined(EIM_EICHD2_WORD2_B4_7DATA_MASK_MASK)
#define SET_2_2 case 2: _SET(base,2,2,4_7,mask)
#define GET_2_2 case 2: _GET(base,2,2,4_7)
#else
#define SET_2_2
#define GET_2_2
#endif

#if defined(EIM_EICHD2_WORD3_B8_11DATA_MASK_MASK)
#define SET_2_3 case 3: _SET(base,2,3,8_11,mask)
#define GET_2_3 case 3: _GET(base,2,3,8_11)
#else
#define SET_2_3
#define GET_2_3
#endif

#if defined(EIM_EICHD2_WORD4_B12_15DATA_MASK_MASK)
#define SET_2_4 case 4: _SET(base,2,4,12_15,mask)
#define GET_2_4 case 4: _GET(base,2,4,12_15)
#else
#define SET_2_4
#define GET_2_4
#endif

#if defined(EIM_EICHD2_WORD5_B16_19DATA_MASK_MASK)
#define SET_2_5 case 5: _SET(base,2,5,16_19,mask)
#define GET_2_5 case 5: _GET(base,2,5,16_19)
#else
#define SET_2_5
#define GET_2_5
#endif

#if defined(EIM_EICHD2_WORD6_B20_23DATA_MASK_MASK)
#define SET_2_6 case 6: _SET(base,2,6,20_23,mask)
#define GET_2_6 case 6: _GET(base,2,6,20_23)
#else
#define SET_2_6
#define GET_2_6
#endif

#if defined(EIM_EICHD3_WORD1_B0_3DATA_MASK_MASK)
#define SET_3_1 case 1: _SET(base,3,1,0_3,mask)
#define GET_3_1 case 1: _GET(base,3,1,0_3)
#else
#define SET_3_1
#define GET_3_1
#endif

#if defined(EIM_EICHD3_WORD2_B4_7DATA_MASK_MASK)
#define SET_3_2 case 2: _SET(base,3,2,4_7,mask)
#define GET_3_2 case 2: _GET(base,3,2,4_7)
#else
#define SET_3_2
#define GET_3_2
#endif

#if defined(EIM_EICHD3_WORD3_B8_11DATA_MASK_MASK)
#define SET_3_3 case 3: _SET(base,3,3,8_11,mask)
#define GET_3_3 case 3: _GET(base,3,3,8_11)
#else
#define SET_3_3
#define GET_3_3
#endif

#if defined(EIM_EICHD3_WORD4_B12_15DATA_MASK_MASK)
#define SET_3_4 case 4: _SET(base,3,4,12_15,mask)
#define GET_3_4 case 4: _GET(base,3,4,12_15)
#else
#define SET_3_4
#define GET_3_4
#endif

#if defined(EIM_EICHD3_WORD5_B16_19DATA_MASK_MASK)
#define SET_3_5 case 5: _SET(base,3,5,16_19,mask)
#define GET_3_5 case 5: _GET(base,3,5,16_19)
#else
#define SET_3_5
#define GET_3_5
#endif

#if defined(EIM_EICHD3_WORD6_B20_23DATA_MASK_MASK)
#define SET_3_6 case 6: _SET(base,3,6,20_23,mask)
#define GET_3_6 case 6: _GET(base,3,6,20_23)
#else
#define SET_3_6
#define GET_3_6
#endif

#if defined(EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK)
#define SET_4_1 case 1: _SET(base,4,1,0_3,mask)
#define GET_4_1 case 1: _GET(base,4,1,0_3)
#else
#define SET_4_1
#define GET_4_1
#endif

#if defined(EIM_EICHD4_WORD2_B4_7DATA_MASK_MASK)
#define SET_4_2 case 2: _SET(base,4,2,4_7,mask)
#define GET_4_2 case 2: _GET(base,4,2,4_7)
#else
#define SET_4_2
#define GET_4_2
#endif

#if defined(EIM_EICHD4_WORD3_B8_11DATA_MASK_MASK)
#define SET_4_3 case 3: _SET(base,4,3,8_11,mask)
#define GET_4_3 case 3: _GET(base,4,3,8_11)
#else
#define SET_4_3
#define GET_4_3
#endif

#if defined(EIM_EICHD4_WORD4_B12_15DATA_MASK_MASK)
#define SET_4_4 case 4: _SET(base,4,4,12_15,mask)
#define GET_4_4 case 4: _GET(base,4,4,12_15)
#else
#define SET_4_4
#define GET_4_4
#endif

#if defined(EIM_EICHD4_WORD5_B16_19DATA_MASK_MASK)
#define SET_4_5 case 5: _SET(base,4,5,16_19,mask)
#define GET_4_5 case 5: _GET(base,4,5,16_19)
#else
#define SET_4_5
#define GET_4_5
#endif

#if defined(EIM_EICHD4_WORD6_B20_23DATA_MASK_MASK)
#define SET_4_6 case 6: _SET(base,4,6,20_23,mask)
#define GET_4_6 case 6: _GET(base,4,6,20_23)
#else
#define SET_4_6
#define GET_4_6
#endif

#if defined(EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK)
#define SET_5_1 case 1: _SET(base,5,1,0_3,mask)
#define GET_5_1 case 1: _GET(base,5,1,0_3)
#else
#define SET_5_1
#define GET_5_1
#endif

#if defined(EIM_EICHD5_WORD2_B4_7DATA_MASK_MASK)
#define SET_5_2 case 2: _SET(base,5,2,4_7,mask)
#define GET_5_2 case 2: _GET(base,5,2,4_7)
#else
#define SET_5_2
#define GET_5_2
#endif

#if defined(EIM_EICHD5_WORD3_B8_11DATA_MASK_MASK)
#define SET_5_3 case 3: _SET(base,5,3,8_11,mask)
#define GET_5_3 case 3: _GET(base,5,3,8_11)
#else
#define SET_5_3
#define GET_5_3
#endif

#if defined(EIM_EICHD5_WORD4_B12_15DATA_MASK_MASK)
#define SET_5_4 case 4: _SET(base,5,4,12_15,mask)
#define GET_5_4 case 4: _GET(base,5,4,12_15)
#else
#define SET_5_4
#define GET_5_4
#endif

#if defined(EIM_EICHD5_WORD5_B16_19DATA_MASK_MASK)
#define SET_5_5 case 5: _SET(base,5,5,16_19,mask)
#define GET_5_5 case 5: _GET(base,5,5,16_19)
#else
#define SET_5_5
#define GET_5_5
#endif

#if defined(EIM_EICHD5_WORD6_B20_23DATA_MASK_MASK)
#define SET_5_6 case 6: _SET(base,5,6,20_23,mask)
#define GET_5_6 case 6: _GET(base,5,6,20_23)
#else
#define SET_5_6
#define GET_5_6
#endif

#if defined(EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK)
#define SET_6_1 case 1: _SET(base,6,1,0_3,mask)
#define GET_6_1 case 1: _GET(base,6,1,0_3)
#else
#define SET_6_1
#define GET_6_1
#endif

#if defined(EIM_EICHD6_WORD2_B4_7DATA_MASK_MASK)
#define SET_6_2 case 2: _SET(base,6,2,4_7,mask)
#define GET_6_2 case 2: _GET(base,6,2,4_7)
#else
#define SET_6_2
#define GET_6_2
#endif

#if defined(EIM_EICHD6_WORD3_B8_11DATA_MASK_MASK)
#define SET_6_3 case 3: _SET(base,6,3,8_11,mask)
#define GET_6_3 case 3: _GET(base,6,3,8_11)
#else
#define SET_6_3
#define GET_6_3
#endif

#if defined(EIM_EICHD6_WORD4_B12_15DATA_MASK_MASK)
#define SET_6_4 case 4: _SET(base,6,4,12_15,mask)
#define GET_6_4 case 4: _GET(base,6,4,12_15)
#else
#define SET_6_4
#define GET_6_4
#endif

#if defined(EIM_EICHD6_WORD5_B16_19DATA_MASK_MASK)
#define SET_6_5 case 5: _SET(base,6,5,16_19,mask)
#define GET_6_5 case 5: _GET(base,6,5,16_19)
#else
#define SET_6_5
#define GET_6_5
#endif

#if defined(EIM_EICHD6_WORD6_B20_23DATA_MASK_MASK)
#define SET_6_6 case 6: _SET(base,6,6,20_23,mask)
#define GET_6_6 case 6: _GET(base,6,6,20_23)
#else
#define SET_6_6
#define GET_6_6
#endif

#if defined(EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK)
#define SET_7_1 case 1: _SET(base,7,1,0_3,mask)
#define GET_7_1 case 1: _GET(base,7,1,0_3)
#else
#define SET_7_1
#define GET_7_1
#endif

#if defined(EIM_EICHD7_WORD2_B4_7DATA_MASK_MASK)
#define SET_7_2 case 2: _SET(base,7,2,4_7,mask)
#define GET_7_2 case 2: _GET(base,7,2,4_7)
#else
#define SET_7_2
#define GET_7_2
#endif

#if defined(EIM_EICHD7_WORD3_B8_11DATA_MASK_MASK)
#define SET_7_3 case 3: _SET(base,7,3,8_11,mask)
#define GET_7_3 case 3: _GET(base,7,3,8_11)
#else
#define SET_7_3
#define GET_7_3
#endif

#if defined(EIM_EICHD7_WORD4_B12_15DATA_MASK_MASK)
#define SET_7_4 case 4: _SET(base,7,4,12_15,mask)
#define GET_7_4 case 4: _GET(base,7,4,12_15)
#else
#define SET_7_4
#define GET_7_4
#endif

#if defined(EIM_EICHD7_WORD5_B16_19DATA_MASK_MASK)
#define SET_7_5 case 5: _SET(base,7,5,16_19,mask)
#define GET_7_5 case 5: _GET(base,7,5,16_19)
#else
#define SET_7_5
#define GET_7_5
#endif

#if defined(EIM_EICHD7_WORD6_B20_23DATA_MASK_MASK)
#define SET_7_6 case 6: _SET(base,7,6,20_23,mask)
#define GET_7_6 case 6: _GET(base,7,6,20_23)
#else
#define SET_7_6
#define GET_7_6
#endif

#if defined(EIM_EICHD8_WORD1_B0_3DATA_MASK_MASK)
#define SET_8_1 case 1: _SET(base,8,1,0_3,mask)
#define GET_8_1 case 1: _GET(base,8,1,0_3)
#else
#define SET_8_1
#define GET_8_1
#endif

#if defined(EIM_EICHD8_WORD2_B4_7DATA_MASK_MASK)
#define SET_8_2 case 2: _SET(base,8,2,4_7,mask)
#define GET_8_2 case 2: _GET(base,8,2,4_7)
#else
#define SET_8_2
#define GET_8_2
#endif

#if defined(EIM_EICHD8_WORD3_B8_11DATA_MASK_MASK)
#define SET_8_3 case 3: _SET(base,8,3,8_11,mask)
#define GET_8_3 case 3: _GET(base,8,3,8_11)
#else
#define SET_8_3
#define GET_8_3
#endif

#if defined(EIM_EICHD8_WORD4_B12_15DATA_MASK_MASK)
#define SET_8_4 case 4: _SET(base,8,4,12_15,mask)
#define GET_8_4 case 4: _GET(base,8,4,12_15)
#else
#define SET_8_4
#define GET_8_4
#endif

#if defined(EIM_EICHD8_WORD5_B16_19DATA_MASK_MASK)
#define SET_8_5 case 5: _SET(base,8,5,16_19,mask)
#define GET_8_5 case 5: _GET(base,8,5,16_19)
#else
#define SET_8_5
#define GET_8_5
#endif

#if defined(EIM_EICHD8_WORD6_B20_23DATA_MASK_MASK)
#define SET_8_6 case 6: _SET(base,8,6,20_23,mask)
#define GET_8_6 case 6: _GET(base,8,6,20_23)
#else
#define SET_8_6
#define GET_8_6
#endif

#if defined(EIM_EICHD9_WORD1_B0_3DATA_MASK_MASK)
#define SET_9_1 case 1: _SET(base,9,1,0_3,mask)
#define GET_9_1 case 1: _GET(base,9,1,0_3)
#else
#define SET_9_1
#define GET_9_1
#endif

#if defined(EIM_EICHD9_WORD2_B4_7DATA_MASK_MASK)
#define SET_9_2 case 2: _SET(base,9,2,4_7,mask)
#define GET_9_2 case 2: _GET(base,9,2,4_7)
#else
#define SET_9_2
#define GET_9_2
#endif

#if defined(EIM_EICHD9_WORD3_B8_11DATA_MASK_MASK)
#define SET_9_3 case 3: _SET(base,9,3,8_11,mask)
#define GET_9_3 case 3: _GET(base,9,3,8_11)
#else
#define SET_9_3
#define GET_9_3
#endif

#if defined(EIM_EICHD9_WORD4_B12_15DATA_MASK_MASK)
#define SET_9_4 case 4: _SET(base,9,4,12_15,mask)
#define GET_9_4 case 4: _GET(base,9,4,12_15)
#else
#define SET_9_4
#define GET_9_4
#endif

#if defined(EIM_EICHD9_WORD5_B16_19DATA_MASK_MASK)
#define SET_9_5 case 5: _SET(base,9,5,16_19,mask)
#define GET_9_5 case 5: _GET(base,9,5,16_19)
#else
#define SET_9_5
#define GET_9_5
#endif

#if defined(EIM_EICHD9_WORD6_B20_23DATA_MASK_MASK)
#define SET_9_6 case 6: _SET(base,9,6,20_23,mask)
#define GET_9_6 case 6: _GET(base,9,6,20_23)
#else
#define SET_9_6
#define GET_9_6
#endif

#if defined(EIM_EICHD10_WORD1_B0_3DATA_MASK_MASK)
#define SET_10_1 case 1: _SET(base,10,1,0_3,mask)
#define GET_10_1 case 1: _GET(base,10,1,0_3)
#else
#define SET_10_1
#define GET_10_1
#endif

#if defined(EIM_EICHD10_WORD2_B4_7DATA_MASK_MASK)
#define SET_10_2 case 2: _SET(base,10,2,4_7,mask)
#define GET_10_2 case 2: _GET(base,10,2,4_7)
#else
#define SET_10_2
#define GET_10_2
#endif

#if defined(EIM_EICHD10_WORD3_B8_11DATA_MASK_MASK)
#define SET_10_3 case 3: _SET(base,10,3,8_11,mask)
#define GET_10_3 case 3: _GET(base,10,3,8_11)
#else
#define SET_10_3
#define GET_10_3
#endif

#if defined(EIM_EICHD10_WORD4_B12_15DATA_MASK_MASK)
#define SET_10_4 case 4: _SET(base,10,4,12_15,mask)
#define GET_10_4 case 4: _GET(base,10,4,12_15)
#else
#define SET_10_4
#define GET_10_4
#endif

#if defined(EIM_EICHD10_WORD5_B16_19DATA_MASK_MASK)
#define SET_10_5 case 5: _SET(base,10,5,16_19,mask)
#define GET_10_5 case 5: _GET(base,10,5,16_19)
#else
#define SET_10_5
#define GET_10_5
#endif

#if defined(EIM_EICHD10_WORD6_B20_23DATA_MASK_MASK)
#define SET_10_6 case 6: _SET(base,10,6,20_23,mask)
#define GET_10_6 case 6: _GET(base,10,6,20_23)
#else
#define SET_10_6
#define GET_10_6
#endif

#if defined(EIM_EICHD11_WORD1_B0_3DATA_MASK_MASK)
#define SET_11_1 case 1: _SET(base,11,1,0_3,mask)
#define GET_11_1 case 1: _GET(base,11,1,0_3)
#else
#define SET_11_1
#define GET_11_1
#endif

#if defined(EIM_EICHD11_WORD2_B4_7DATA_MASK_MASK)
#define SET_11_2 case 2: _SET(base,11,2,4_7,mask)
#define GET_11_2 case 2: _GET(base,11,2,4_7)
#else
#define SET_11_2
#define GET_11_2
#endif

#if defined(EIM_EICHD11_WORD3_B8_11DATA_MASK_MASK)
#define SET_11_3 case 3: _SET(base,11,3,8_11,mask)
#define GET_11_3 case 3: _GET(base,11,3,8_11)
#else
#define SET_11_3
#define GET_11_3
#endif

#if defined(EIM_EICHD11_WORD4_B12_15DATA_MASK_MASK)
#define SET_11_4 case 4: _SET(base,11,4,12_15,mask)
#define GET_11_4 case 4: _GET(base,11,4,12_15)
#else
#define SET_11_4
#define GET_11_4
#endif

#if defined(EIM_EICHD11_WORD5_B16_19DATA_MASK_MASK)
#define SET_11_5 case 5: _SET(base,11,5,16_19,mask)
#define GET_11_5 case 5: _GET(base,11,5,16_19)
#else
#define SET_11_5
#define GET_11_5
#endif

#if defined(EIM_EICHD11_WORD6_B20_23DATA_MASK_MASK)
#define SET_11_6 case 6: _SET(base,11,6,20_23,mask)
#define GET_11_6 case 6: _GET(base,11,6,20_23)
#else
#define SET_11_6
#define GET_11_6
#endif

#if defined(EIM_EICHD12_WORD1_B0_3DATA_MASK_MASK)
#define SET_12_1 case 1: _SET(base,12,1,0_3,mask)
#define GET_12_1 case 1: _GET(base,12,1,0_3)
#else
#define SET_12_1
#define GET_12_1
#endif

#if defined(EIM_EICHD12_WORD2_B4_7DATA_MASK_MASK)
#define SET_12_2 case 2: _SET(base,12,2,4_7,mask)
#define GET_12_2 case 2: _GET(base,12,2,4_7)
#else
#define SET_12_2
#define GET_12_2
#endif

#if defined(EIM_EICHD12_WORD3_B8_11DATA_MASK_MASK)
#define SET_12_3 case 3: _SET(base,12,3,8_11,mask)
#define GET_12_3 case 3: _GET(base,12,3,8_11)
#else
#define SET_12_3
#define GET_12_3
#endif

#if defined(EIM_EICHD12_WORD4_B12_15DATA_MASK_MASK)
#define SET_12_4 case 4: _SET(base,12,4,12_15,mask)
#define GET_12_4 case 4: _GET(base,12,4,12_15)
#else
#define SET_12_4
#define GET_12_4
#endif

#if defined(EIM_EICHD12_WORD5_B16_19DATA_MASK_MASK)
#define SET_12_5 case 5: _SET(base,12,5,16_19,mask)
#define GET_12_5 case 5: _GET(base,12,5,16_19)
#else
#define SET_12_5
#define GET_12_5
#endif

#if defined(EIM_EICHD12_WORD6_B20_23DATA_MASK_MASK)
#define SET_12_6 case 6: _SET(base,12,6,20_23,mask)
#define GET_12_6 case 6: _GET(base,12,6,20_23)
#else
#define SET_12_6
#define GET_12_6
#endif

#if defined(EIM_EICHD13_WORD1_B0_3DATA_MASK_MASK)
#define SET_13_1 case 1: _SET(base,13,1,0_3,mask)
#define GET_13_1 case 1: _GET(base,13,1,0_3)
#else
#define SET_13_1
#define GET_13_1
#endif

#if defined(EIM_EICHD13_WORD2_B4_7DATA_MASK_MASK)
#define SET_13_2 case 2: _SET(base,13,2,4_7,mask)
#define GET_13_2 case 2: _GET(base,13,2,4_7)
#else
#define SET_13_2
#define GET_13_2
#endif

#if defined(EIM_EICHD13_WORD3_B8_11DATA_MASK_MASK)
#define SET_13_3 case 3: _SET(base,13,3,8_11,mask)
#define GET_13_3 case 3: _GET(base,13,3,8_11)
#else
#define SET_13_3
#define GET_13_3
#endif

#if defined(EIM_EICHD13_WORD4_B12_15DATA_MASK_MASK)
#define SET_13_4 case 4: _SET(base,13,4,12_15,mask)
#define GET_13_4 case 4: _GET(base,13,4,12_15)
#else
#define SET_13_4
#define GET_13_4
#endif

#if defined(EIM_EICHD13_WORD5_B16_19DATA_MASK_MASK)
#define SET_13_5 case 5: _SET(base,13,5,16_19,mask)
#define GET_13_5 case 5: _GET(base,13,5,16_19)
#else
#define SET_13_5
#define GET_13_5
#endif

#if defined(EIM_EICHD13_WORD6_B20_23DATA_MASK_MASK)
#define SET_13_6 case 6: _SET(base,13,6,20_23,mask)
#define GET_13_6 case 6: _GET(base,13,6,20_23)
#else
#define SET_13_6
#define GET_13_6
#endif

#if defined(EIM_EICHD14_WORD1_B0_3DATA_MASK_MASK)
#define SET_14_1 case 1: _SET(base,14,1,0_3,mask)
#define GET_14_1 case 1: _GET(base,14,1,0_3)
#else
#define SET_14_1
#define GET_14_1
#endif

#if defined(EIM_EICHD14_WORD2_B4_7DATA_MASK_MASK)
#define SET_14_2 case 2: _SET(base,14,2,4_7,mask)
#define GET_14_2 case 2: _GET(base,14,2,4_7)
#else
#define SET_14_2
#define GET_14_2
#endif

#if defined(EIM_EICHD14_WORD3_B8_11DATA_MASK_MASK)
#define SET_14_3 case 3: _SET(base,14,3,8_11,mask)
#define GET_14_3 case 3: _GET(base,14,3,8_11)
#else
#define SET_14_3
#define GET_14_3
#endif

#if defined(EIM_EICHD14_WORD4_B12_15DATA_MASK_MASK)
#define SET_14_4 case 4: _SET(base,14,4,12_15,mask)
#define GET_14_4 case 4: _GET(base,14,4,12_15)
#else
#define SET_14_4
#define GET_14_4
#endif

#if defined(EIM_EICHD14_WORD5_B16_19DATA_MASK_MASK)
#define SET_14_5 case 5: _SET(base,14,5,16_19,mask)
#define GET_14_5 case 5: _GET(base,14,5,16_19)
#else
#define SET_14_5
#define GET_14_5
#endif

#if defined(EIM_EICHD14_WORD6_B20_23DATA_MASK_MASK)
#define SET_14_6 case 6: _SET(base,14,6,20_23,mask)
#define GET_14_6 case 6: _GET(base,14,6,20_23)
#else
#define SET_14_6
#define GET_14_6
#endif

#if defined(EIM_EICHD15_WORD1_B0_3DATA_MASK_MASK)
#define SET_15_1 case 1: _SET(base,15,1,0_3,mask)
#define GET_15_1 case 1: _GET(base,15,1,0_3)
#else
#define SET_15_1
#define GET_15_1
#endif

#if defined(EIM_EICHD15_WORD2_B4_7DATA_MASK_MASK)
#define SET_15_2 case 2: _SET(base,15,2,4_7,mask)
#define GET_15_2 case 2: _GET(base,15,2,4_7)
#else
#define SET_15_2
#define GET_15_2
#endif

#if defined(EIM_EICHD15_WORD3_B8_11DATA_MASK_MASK)
#define SET_15_3 case 3: _SET(base,15,3,8_11,mask)
#define GET_15_3 case 3: _GET(base,15,3,8_11)
#else
#define SET_15_3
#define GET_15_3
#endif

#if defined(EIM_EICHD15_WORD4_B12_15DATA_MASK_MASK)
#define SET_15_4 case 4: _SET(base,15,4,12_15,mask)
#define GET_15_4 case 4: _GET(base,15,4,12_15)
#else
#define SET_15_4
#define GET_15_4
#endif

#if defined(EIM_EICHD15_WORD5_B16_19DATA_MASK_MASK)
#define SET_15_5 case 5: _SET(base,15,5,16_19,mask)
#define GET_15_5 case 5: _GET(base,15,5,16_19)
#else
#define SET_15_5
#define GET_15_5
#endif

#if defined(EIM_EICHD15_WORD6_B20_23DATA_MASK_MASK)
#define SET_15_6 case 6: _SET(base,15,6,20_23,mask)
#define GET_15_6 case 6: _GET(base,15,6,20_23)
#else
#define SET_15_6
#define GET_15_6
#endif

#if defined(EIM_EICHD16_WORD1_B0_3DATA_MASK_MASK)
#define SET_16_1 case 1: _SET(base,16,1,0_3,mask)
#define GET_16_1 case 1: _GET(base,16,1,0_3)
#else
#define SET_16_1
#define GET_16_1
#endif

#if defined(EIM_EICHD16_WORD2_B4_7DATA_MASK_MASK)
#define SET_16_2 case 2: _SET(base,16,2,4_7,mask)
#define GET_16_2 case 2: _GET(base,16,2,4_7)
#else
#define SET_16_2
#define GET_16_2
#endif

#if defined(EIM_EICHD16_WORD3_B8_11DATA_MASK_MASK)
#define SET_16_3 case 3: _SET(base,16,3,8_11,mask)
#define GET_16_3 case 3: _GET(base,16,3,8_11)
#else
#define SET_16_3
#define GET_16_3
#endif

#if defined(EIM_EICHD16_WORD4_B12_15DATA_MASK_MASK)
#define SET_16_4 case 4: _SET(base,16,4,12_15,mask)
#define GET_16_4 case 4: _GET(base,16,4,12_15)
#else
#define SET_16_4
#define GET_16_4
#endif

#if defined(EIM_EICHD16_WORD5_B16_19DATA_MASK_MASK)
#define SET_16_5 case 5: _SET(base,16,5,16_19,mask)
#define GET_16_5 case 5: _GET(base,16,5,16_19)
#else
#define SET_16_5
#define GET_16_5
#endif

#if defined(EIM_EICHD16_WORD6_B20_23DATA_MASK_MASK)
#define SET_16_6 case 6: _SET(base,16,6,20_23,mask)
#define GET_16_6 case 6: _GET(base,16,6,20_23)
#else
#define SET_16_6
#define GET_16_6
#endif

#if defined(EIM_EICHD17_WORD1_B0_3DATA_MASK_MASK)
#define SET_17_1 case 1: _SET(base,17,1,0_3,mask)
#define GET_17_1 case 1: _GET(base,17,1,0_3)
#else
#define SET_17_1
#define GET_17_1
#endif

#if defined(EIM_EICHD17_WORD2_B4_7DATA_MASK_MASK)
#define SET_17_2 case 2: _SET(base,17,2,4_7,mask)
#define GET_17_2 case 2: _GET(base,17,2,4_7)
#else
#define SET_17_2
#define GET_17_2
#endif

#if defined(EIM_EICHD17_WORD3_B8_11DATA_MASK_MASK)
#define SET_17_3 case 3: _SET(base,17,3,8_11,mask)
#define GET_17_3 case 3: _GET(base,17,3,8_11)
#else
#define SET_17_3
#define GET_17_3
#endif

#if defined(EIM_EICHD17_WORD4_B12_15DATA_MASK_MASK)
#define SET_17_4 case 4: _SET(base,17,4,12_15,mask)
#define GET_17_4 case 4: _GET(base,17,4,12_15)
#else
#define SET_17_4
#define GET_17_4
#endif

#if defined(EIM_EICHD17_WORD5_B16_19DATA_MASK_MASK)
#define SET_17_5 case 5: _SET(base,17,5,16_19,mask)
#define GET_17_5 case 5: _GET(base,17,5,16_19)
#else
#define SET_17_5
#define GET_17_5
#endif

#if defined(EIM_EICHD17_WORD6_B20_23DATA_MASK_MASK)
#define SET_17_6 case 6: _SET(base,17,6,20_23,mask)
#define GET_17_6 case 6: _GET(base,17,6,20_23)
#else
#define SET_17_6
#define GET_17_6
#endif

#if defined(EIM_EICHD18_WORD1_B0_3DATA_MASK_MASK)
#define SET_18_1 case 1: _SET(base,18,1,0_3,mask)
#define GET_18_1 case 1: _GET(base,18,1,0_3)
#else
#define SET_18_1
#define GET_18_1
#endif

#if defined(EIM_EICHD18_WORD2_B4_7DATA_MASK_MASK)
#define SET_18_2 case 2: _SET(base,18,2,4_7,mask)
#define GET_18_2 case 2: _GET(base,18,2,4_7)
#else
#define SET_18_2
#define GET_18_2
#endif

#if defined(EIM_EICHD18_WORD3_B8_11DATA_MASK_MASK)
#define SET_18_3 case 3: _SET(base,18,3,8_11,mask)
#define GET_18_3 case 3: _GET(base,18,3,8_11)
#else
#define SET_18_3
#define GET_18_3
#endif

#if defined(EIM_EICHD18_WORD4_B12_15DATA_MASK_MASK)
#define SET_18_4 case 4: _SET(base,18,4,12_15,mask)
#define GET_18_4 case 4: _GET(base,18,4,12_15)
#else
#define SET_18_4
#define GET_18_4
#endif

#if defined(EIM_EICHD18_WORD5_B16_19DATA_MASK_MASK)
#define SET_18_5 case 5: _SET(base,18,5,16_19,mask)
#define GET_18_5 case 5: _GET(base,18,5,16_19)
#else
#define SET_18_5
#define GET_18_5
#endif

#if defined(EIM_EICHD18_WORD6_B20_23DATA_MASK_MASK)
#define SET_18_6 case 6: _SET(base,18,6,20_23,mask)
#define GET_18_6 case 6: _GET(base,18,6,20_23)
#else
#define SET_18_6
#define GET_18_6
#endif

#if defined(EIM_EICHD19_WORD1_B0_3DATA_MASK_MASK)
#define SET_19_1 case 1: _SET(base,19,1,0_3,mask)
#define GET_19_1 case 1: _GET(base,19,1,0_3)
#else
#define SET_19_1
#define GET_19_1
#endif

#if defined(EIM_EICHD19_WORD2_B4_7DATA_MASK_MASK)
#define SET_19_2 case 2: _SET(base,19,2,4_7,mask)
#define GET_19_2 case 2: _GET(base,19,2,4_7)
#else
#define SET_19_2
#define GET_19_2
#endif

#if defined(EIM_EICHD19_WORD3_B8_11DATA_MASK_MASK)
#define SET_19_3 case 3: _SET(base,19,3,8_11,mask)
#define GET_19_3 case 3: _GET(base,19,3,8_11)
#else
#define SET_19_3
#define GET_19_3
#endif

#if defined(EIM_EICHD19_WORD4_B12_15DATA_MASK_MASK)
#define SET_19_4 case 4: _SET(base,19,4,12_15,mask)
#define GET_19_4 case 4: _GET(base,19,4,12_15)
#else
#define SET_19_4
#define GET_19_4
#endif

#if defined(EIM_EICHD19_WORD5_B16_19DATA_MASK_MASK)
#define SET_19_5 case 5: _SET(base,19,5,16_19,mask)
#define GET_19_5 case 5: _GET(base,19,5,16_19)
#else
#define SET_19_5
#define GET_19_5
#endif

#if defined(EIM_EICHD19_WORD6_B20_23DATA_MASK_MASK)
#define SET_19_6 case 6: _SET(base,19,6,20_23,mask)
#define GET_19_6 case 6: _GET(base,19,6,20_23)
#else
#define SET_19_6
#define GET_19_6
#endif

#if defined(EIM_EICHD20_WORD1_B0_3DATA_MASK_MASK)
#define SET_20_1 case 1: _SET(base,20,1,0_3,mask)
#define GET_20_1 case 1: _GET(base,20,1,0_3)
#else
#define SET_20_1
#define GET_20_1
#endif

#if defined(EIM_EICHD20_WORD2_B4_7DATA_MASK_MASK)
#define SET_20_2 case 2: _SET(base,20,2,4_7,mask)
#define GET_20_2 case 2: _GET(base,20,2,4_7)
#else
#define SET_20_2
#define GET_20_2
#endif

#if defined(EIM_EICHD20_WORD3_B8_11DATA_MASK_MASK)
#define SET_20_3 case 3: _SET(base,20,3,8_11,mask)
#define GET_20_3 case 3: _GET(base,20,3,8_11)
#else
#define SET_20_3
#define GET_20_3
#endif

#if defined(EIM_EICHD20_WORD4_B12_15DATA_MASK_MASK)
#define SET_20_4 case 4: _SET(base,20,4,12_15,mask)
#define GET_20_4 case 4: _GET(base,20,4,12_15)
#else
#define SET_20_4
#define GET_20_4
#endif

#if defined(EIM_EICHD20_WORD5_B16_19DATA_MASK_MASK)
#define SET_20_5 case 5: _SET(base,20,5,16_19,mask)
#define GET_20_5 case 5: _GET(base,20,5,16_19)
#else
#define SET_20_5
#define GET_20_5
#endif

#if defined(EIM_EICHD20_WORD6_B20_23DATA_MASK_MASK)
#define SET_20_6 case 6: _SET(base,20,6,20_23,mask)
#define GET_20_6 case 6: _GET(base,20,6,20_23)
#else
#define SET_20_6
#define GET_20_6
#endif

#if defined(EIM_EICHD21_WORD1_B0_3DATA_MASK_MASK)
#define SET_21_1 case 1: _SET(base,21,1,0_3,mask)
#define GET_21_1 case 1: _GET(base,21,1,0_3)
#else
#define SET_21_1
#define GET_21_1
#endif

#if defined(EIM_EICHD21_WORD2_B4_7DATA_MASK_MASK)
#define SET_21_2 case 2: _SET(base,21,2,4_7,mask)
#define GET_21_2 case 2: _GET(base,21,2,4_7)
#else
#define SET_21_2
#define GET_21_2
#endif

#if defined(EIM_EICHD21_WORD3_B8_11DATA_MASK_MASK)
#define SET_21_3 case 3: _SET(base,21,3,8_11,mask)
#define GET_21_3 case 3: _GET(base,21,3,8_11)
#else
#define SET_21_3
#define GET_21_3
#endif

#if defined(EIM_EICHD21_WORD4_B12_15DATA_MASK_MASK)
#define SET_21_4 case 4: _SET(base,21,4,12_15,mask)
#define GET_21_4 case 4: _GET(base,21,4,12_15)
#else
#define SET_21_4
#define GET_21_4
#endif

#if defined(EIM_EICHD21_WORD5_B16_19DATA_MASK_MASK)
#define SET_21_5 case 5: _SET(base,21,5,16_19,mask)
#define GET_21_5 case 5: _GET(base,21,5,16_19)
#else
#define SET_21_5
#define GET_21_5
#endif

#if defined(EIM_EICHD21_WORD6_B20_23DATA_MASK_MASK)
#define SET_21_6 case 6: _SET(base,21,6,20_23,mask)
#define GET_21_6 case 6: _GET(base,21,6,20_23)
#else
#define SET_21_6
#define GET_21_6
#endif

#if defined(EIM_EICHD22_WORD1_B0_3DATA_MASK_MASK)
#define SET_22_1 case 1: _SET(base,22,1,0_3,mask)
#define GET_22_1 case 1: _GET(base,22,1,0_3)
#else
#define SET_22_1
#define GET_22_1
#endif

#if defined(EIM_EICHD22_WORD2_B4_7DATA_MASK_MASK)
#define SET_22_2 case 2: _SET(base,22,2,4_7,mask)
#define GET_22_2 case 2: _GET(base,22,2,4_7)
#else
#define SET_22_2
#define GET_22_2
#endif

#if defined(EIM_EICHD22_WORD3_B8_11DATA_MASK_MASK)
#define SET_22_3 case 3: _SET(base,22,3,8_11,mask)
#define GET_22_3 case 3: _GET(base,22,3,8_11)
#else
#define SET_22_3
#define GET_22_3
#endif

#if defined(EIM_EICHD22_WORD4_B12_15DATA_MASK_MASK)
#define SET_22_4 case 4: _SET(base,22,4,12_15,mask)
#define GET_22_4 case 4: _GET(base,22,4,12_15)
#else
#define SET_22_4
#define GET_22_4
#endif

#if defined(EIM_EICHD22_WORD5_B16_19DATA_MASK_MASK)
#define SET_22_5 case 5: _SET(base,22,5,16_19,mask)
#define GET_22_5 case 5: _GET(base,22,5,16_19)
#else
#define SET_22_5
#define GET_22_5
#endif

#if defined(EIM_EICHD22_WORD6_B20_23DATA_MASK_MASK)
#define SET_22_6 case 6: _SET(base,22,6,20_23,mask)
#define GET_22_6 case 6: _GET(base,22,6,20_23)
#else
#define SET_22_6
#define GET_22_6
#endif

#if defined(EIM_EICHD23_WORD1_B0_3DATA_MASK_MASK)
#define SET_23_1 case 1: _SET(base,23,1,0_3,mask)
#define GET_23_1 case 1: _GET(base,23,1,0_3)
#else
#define SET_23_1
#define GET_23_1
#endif

#if defined(EIM_EICHD23_WORD2_B4_7DATA_MASK_MASK)
#define SET_23_2 case 2: _SET(base,23,2,4_7,mask)
#define GET_23_2 case 2: _GET(base,23,2,4_7)
#else
#define SET_23_2
#define GET_23_2
#endif

#if defined(EIM_EICHD23_WORD3_B8_11DATA_MASK_MASK)
#define SET_23_3 case 3: _SET(base,23,3,8_11,mask)
#define GET_23_3 case 3: _GET(base,23,3,8_11)
#else
#define SET_23_3
#define GET_23_3
#endif

#if defined(EIM_EICHD23_WORD4_B12_15DATA_MASK_MASK)
#define SET_23_4 case 4: _SET(base,23,4,12_15,mask)
#define GET_23_4 case 4: _GET(base,23,4,12_15)
#else
#define SET_23_4
#define GET_23_4
#endif

#if defined(EIM_EICHD23_WORD5_B16_19DATA_MASK_MASK)
#define SET_23_5 case 5: _SET(base,23,5,16_19,mask)
#define GET_23_5 case 5: _GET(base,23,5,16_19)
#else
#define SET_23_5
#define GET_23_5
#endif

#if defined(EIM_EICHD23_WORD6_B20_23DATA_MASK_MASK)
#define SET_23_6 case 6: _SET(base,23,6,20_23,mask)
#define GET_23_6 case 6: _GET(base,23,6,20_23)
#else
#define SET_23_6
#define GET_23_6
#endif

#if defined(EIM_EICHD24_WORD1_B0_3DATA_MASK_MASK)
#define SET_24_1 case 1: _SET(base,24,1,0_3,mask)
#define GET_24_1 case 1: _GET(base,24,1,0_3)
#else
#define SET_24_1
#define GET_24_1
#endif

#if defined(EIM_EICHD24_WORD2_B4_7DATA_MASK_MASK)
#define SET_24_2 case 2: _SET(base,24,2,4_7,mask)
#define GET_24_2 case 2: _GET(base,24,2,4_7)
#else
#define SET_24_2
#define GET_24_2
#endif

#if defined(EIM_EICHD24_WORD3_B8_11DATA_MASK_MASK)
#define SET_24_3 case 3: _SET(base,24,3,8_11,mask)
#define GET_24_3 case 3: _GET(base,24,3,8_11)
#else
#define SET_24_3
#define GET_24_3
#endif

#if defined(EIM_EICHD24_WORD4_B12_15DATA_MASK_MASK)
#define SET_24_4 case 4: _SET(base,24,4,12_15,mask)
#define GET_24_4 case 4: _GET(base,24,4,12_15)
#else
#define SET_24_4
#define GET_24_4
#endif

#if defined(EIM_EICHD24_WORD5_B16_19DATA_MASK_MASK)
#define SET_24_5 case 5: _SET(base,24,5,16_19,mask)
#define GET_24_5 case 5: _GET(base,24,5,16_19)
#else
#define SET_24_5
#define GET_24_5
#endif

#if defined(EIM_EICHD24_WORD6_B20_23DATA_MASK_MASK)
#define SET_24_6 case 6: _SET(base,24,6,20_23,mask)
#define GET_24_6 case 6: _GET(base,24,6,20_23)
#else
#define SET_24_6
#define GET_24_6
#endif

#if defined(EIM_EICHD25_WORD1_B0_3DATA_MASK_MASK)
#define SET_25_1 case 1: _SET(base,25,1,0_3,mask)
#define GET_25_1 case 1: _GET(base,25,1,0_3)
#else
#define SET_25_1
#define GET_25_1
#endif

#if defined(EIM_EICHD25_WORD2_B4_7DATA_MASK_MASK)
#define SET_25_2 case 2: _SET(base,25,2,4_7,mask)
#define GET_25_2 case 2: _GET(base,25,2,4_7)
#else
#define SET_25_2
#define GET_25_2
#endif

#if defined(EIM_EICHD25_WORD3_B8_11DATA_MASK_MASK)
#define SET_25_3 case 3: _SET(base,25,3,8_11,mask)
#define GET_25_3 case 3: _GET(base,25,3,8_11)
#else
#define SET_25_3
#define GET_25_3
#endif

#if defined(EIM_EICHD25_WORD4_B12_15DATA_MASK_MASK)
#define SET_25_4 case 4: _SET(base,25,4,12_15,mask)
#define GET_25_4 case 4: _GET(base,25,4,12_15)
#else
#define SET_25_4
#define GET_25_4
#endif

#if defined(EIM_EICHD25_WORD5_B16_19DATA_MASK_MASK)
#define SET_25_5 case 5: _SET(base,25,5,16_19,mask)
#define GET_25_5 case 5: _GET(base,25,5,16_19)
#else
#define SET_25_5
#define GET_25_5
#endif

#if defined(EIM_EICHD25_WORD6_B20_23DATA_MASK_MASK)
#define SET_25_6 case 6: _SET(base,25,6,20_23,mask)
#define GET_25_6 case 6: _GET(base,25,6,20_23)
#else
#define SET_25_6
#define GET_25_6
#endif

#if defined(EIM_EICHD26_WORD1_B0_3DATA_MASK_MASK)
#define SET_26_1 case 1: _SET(base,26,1,0_3,mask)
#define GET_26_1 case 1: _GET(base,26,1,0_3)
#else
#define SET_26_1
#define GET_26_1
#endif

#if defined(EIM_EICHD26_WORD2_B4_7DATA_MASK_MASK)
#define SET_26_2 case 2: _SET(base,26,2,4_7,mask)
#define GET_26_2 case 2: _GET(base,26,2,4_7)
#else
#define SET_26_2
#define GET_26_2
#endif

#if defined(EIM_EICHD26_WORD3_B8_11DATA_MASK_MASK)
#define SET_26_3 case 3: _SET(base,26,3,8_11,mask)
#define GET_26_3 case 3: _GET(base,26,3,8_11)
#else
#define SET_26_3
#define GET_26_3
#endif

#if defined(EIM_EICHD26_WORD4_B12_15DATA_MASK_MASK)
#define SET_26_4 case 4: _SET(base,26,4,12_15,mask)
#define GET_26_4 case 4: _GET(base,26,4,12_15)
#else
#define SET_26_4
#define GET_26_4
#endif

#if defined(EIM_EICHD26_WORD5_B16_19DATA_MASK_MASK)
#define SET_26_5 case 5: _SET(base,26,5,16_19,mask)
#define GET_26_5 case 5: _GET(base,26,5,16_19)
#else
#define SET_26_5
#define GET_26_5
#endif

#if defined(EIM_EICHD26_WORD6_B20_23DATA_MASK_MASK)
#define SET_26_6 case 6: _SET(base,26,6,20_23,mask)
#define GET_26_6 case 6: _GET(base,26,6,20_23)
#else
#define SET_26_6
#define GET_26_6
#endif

#if defined(EIM_EICHD27_WORD1_B0_3DATA_MASK_MASK)
#define SET_27_1 case 1: _SET(base,27,1,0_3,mask)
#define GET_27_1 case 1: _GET(base,27,1,0_3)
#else
#define SET_27_1
#define GET_27_1
#endif

#if defined(EIM_EICHD27_WORD2_B4_7DATA_MASK_MASK)
#define SET_27_2 case 2: _SET(base,27,2,4_7,mask)
#define GET_27_2 case 2: _GET(base,27,2,4_7)
#else
#define SET_27_2
#define GET_27_2
#endif

#if defined(EIM_EICHD27_WORD3_B8_11DATA_MASK_MASK)
#define SET_27_3 case 3: _SET(base,27,3,8_11,mask)
#define GET_27_3 case 3: _GET(base,27,3,8_11)
#else
#define SET_27_3
#define GET_27_3
#endif

#if defined(EIM_EICHD27_WORD4_B12_15DATA_MASK_MASK)
#define SET_27_4 case 4: _SET(base,27,4,12_15,mask)
#define GET_27_4 case 4: _GET(base,27,4,12_15)
#else
#define SET_27_4
#define GET_27_4
#endif

#if defined(EIM_EICHD27_WORD5_B16_19DATA_MASK_MASK)
#define SET_27_5 case 5: _SET(base,27,5,16_19,mask)
#define GET_27_5 case 5: _GET(base,27,5,16_19)
#else
#define SET_27_5
#define GET_27_5
#endif

#if defined(EIM_EICHD27_WORD6_B20_23DATA_MASK_MASK)
#define SET_27_6 case 6: _SET(base,27,6,20_23,mask)
#define GET_27_6 case 6: _GET(base,27,6,20_23)
#else
#define SET_27_6
#define GET_27_6
#endif

#if defined(EIM_EICHD28_WORD1_B0_3DATA_MASK_MASK)
#define SET_28_1 case 1: _SET(base,28,1,0_3,mask)
#define GET_28_1 case 1: _GET(base,28,1,0_3)
#else
#define SET_28_1
#define GET_28_1
#endif

#if defined(EIM_EICHD28_WORD2_B4_7DATA_MASK_MASK)
#define SET_28_2 case 2: _SET(base,28,2,4_7,mask)
#define GET_28_2 case 2: _GET(base,28,2,4_7)
#else
#define SET_28_2
#define GET_28_2
#endif

#if defined(EIM_EICHD28_WORD3_B8_11DATA_MASK_MASK)
#define SET_28_3 case 3: _SET(base,28,3,8_11,mask)
#define GET_28_3 case 3: _GET(base,28,3,8_11)
#else
#define SET_28_3
#define GET_28_3
#endif

#if defined(EIM_EICHD28_WORD4_B12_15DATA_MASK_MASK)
#define SET_28_4 case 4: _SET(base,28,4,12_15,mask)
#define GET_28_4 case 4: _GET(base,28,4,12_15)
#else
#define SET_28_4
#define GET_28_4
#endif

#if defined(EIM_EICHD28_WORD5_B16_19DATA_MASK_MASK)
#define SET_28_5 case 5: _SET(base,28,5,16_19,mask)
#define GET_28_5 case 5: _GET(base,28,5,16_19)
#else
#define SET_28_5
#define GET_28_5
#endif

#if defined(EIM_EICHD28_WORD6_B20_23DATA_MASK_MASK)
#define SET_28_6 case 6: _SET(base,28,6,20_23,mask)
#define GET_28_6 case 6: _GET(base,28,6,20_23)
#else
#define SET_28_6
#define GET_28_6
#endif

#if defined(EIM_EICHD29_WORD1_B0_3DATA_MASK_MASK)
#define SET_29_1 case 1: _SET(base,29,1,0_3,mask)
#define GET_29_1 case 1: _GET(base,29,1,0_3)
#else
#define SET_29_1
#define GET_29_1
#endif

#if defined(EIM_EICHD29_WORD2_B4_7DATA_MASK_MASK)
#define SET_29_2 case 2: _SET(base,29,2,4_7,mask)
#define GET_29_2 case 2: _GET(base,29,2,4_7)
#else
#define SET_29_2
#define GET_29_2
#endif

#if defined(EIM_EICHD29_WORD3_B8_11DATA_MASK_MASK)
#define SET_29_3 case 3: _SET(base,29,3,8_11,mask)
#define GET_29_3 case 3: _GET(base,29,3,8_11)
#else
#define SET_29_3
#define GET_29_3
#endif

#if defined(EIM_EICHD29_WORD4_B12_15DATA_MASK_MASK)
#define SET_29_4 case 4: _SET(base,29,4,12_15,mask)
#define GET_29_4 case 4: _GET(base,29,4,12_15)
#else
#define SET_29_4
#define GET_29_4
#endif

#if defined(EIM_EICHD29_WORD5_B16_19DATA_MASK_MASK)
#define SET_29_5 case 5: _SET(base,29,5,16_19,mask)
#define GET_29_5 case 5: _GET(base,29,5,16_19)
#else
#define SET_29_5
#define GET_29_5
#endif

#if defined(EIM_EICHD29_WORD6_B20_23DATA_MASK_MASK)
#define SET_29_6 case 6: _SET(base,29,6,20_23,mask)
#define GET_29_6 case 6: _GET(base,29,6,20_23)
#else
#define SET_29_6
#define GET_29_6
#endif

#if defined(EIM_EICHD30_WORD1_B0_3DATA_MASK_MASK)
#define SET_30_1 case 1: _SET(base,30,1,0_3,mask)
#define GET_30_1 case 1: _GET(base,30,1,0_3)
#else
#define SET_30_1
#define GET_30_1
#endif

#if defined(EIM_EICHD30_WORD2_B4_7DATA_MASK_MASK)
#define SET_30_2 case 2: _SET(base,30,2,4_7,mask)
#define GET_30_2 case 2: _GET(base,30,2,4_7)
#else
#define SET_30_2
#define GET_30_2
#endif

#if defined(EIM_EICHD30_WORD3_B8_11DATA_MASK_MASK)
#define SET_30_3 case 3: _SET(base,30,3,8_11,mask)
#define GET_30_3 case 3: _GET(base,30,3,8_11)
#else
#define SET_30_3
#define GET_30_3
#endif

#if defined(EIM_EICHD30_WORD4_B12_15DATA_MASK_MASK)
#define SET_30_4 case 4: _SET(base,30,4,12_15,mask)
#define GET_30_4 case 4: _GET(base,30,4,12_15)
#else
#define SET_30_4
#define GET_30_4
#endif

#if defined(EIM_EICHD30_WORD5_B16_19DATA_MASK_MASK)
#define SET_30_5 case 5: _SET(base,30,5,16_19,mask)
#define GET_30_5 case 5: _GET(base,30,5,16_19)
#else
#define SET_30_5
#define GET_30_5
#endif

#if defined(EIM_EICHD30_WORD6_B20_23DATA_MASK_MASK)
#define SET_30_6 case 6: _SET(base,30,6,20_23,mask)
#define GET_30_6 case 6: _GET(base,30,6,20_23)
#else
#define SET_30_6
#define GET_30_6
#endif

#endif
