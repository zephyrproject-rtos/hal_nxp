/** @file  wls_processing.c
  *
  * @brief This file contains processing functions to calculate CSI correction for WLS time stamps
  *
  * Copyright 2023-2024 NXP
  *
  * SPDX-License-Identifier: BSD-3-Clause
  *
  */

/************************************************************************
* DFW processing functions to calculate CSI correction for WLS time stamps
************************************************************************/

#include <osa.h>
#if CONFIG_WLS_CSI_PROC

// Standard includes.
#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

#include "wls_radix4Fft.h"
#include "wls_structure_defs.h"
#include "wls_processing.h"
#ifdef FFT_PARALLEL
#include "wls_processing_parallel.h"
#endif
#ifdef ARM_DS5
#include "wls_processing_Neon_Intrinsic.h"
#endif
#include "wls_param_defines.h"

#ifdef FLOATING_POINT
#include <math.h>
#endif

#define NUM_ATAN_IT 10

//#define ONE_OVER_PI ((int)((1<<MPY_BIPT)/3.141592653589795f))
#define ONE_OVER_PI ((0x145F306D)>>(30-MPY_BIPT)) //0x145F306D=1.0/PI*(1<<30)
#define TABLE_SIZE_POW 6
#define TABLE_SIZE (1<<TABLE_SIZE_POW)

const unsigned char sqrtLUT[TABLE_SIZE] = {31, 44, 54, 63, 71, 77, 84, 90, 95, 100, 105, 110, 114, 119, 123, 127, 131, 135, 138, 142, 146, 149, 152, 156, 159, 162, 165, 168, 171, 174, 177, 180, 183, 186, 188, 191, 194, 196, 199, 201, 204, 206, 209, 211, 214, 216, 218, 221, 223, 225, 228, 230, 232, 234, 236, 238, 241, 243, 245, 247, 249, 251, 253, 255};

static const unsigned int pilotDummyArray[10] = {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};

// 80 MHz 128+[-125:-1 1:125]
// minus pilots on [-117, -100, -23, -6, 6, 23, 100, 117]

// SC5 VHT format with Ng=1, needs to skip pilot tones
const unsigned char pilotToneIndexVHT80[SC5_VHT80_PILOTS] = { 25, 53, 89, 117, 139, 167, 203, 231 };
const unsigned char pilotToneIndexVHT40[SC5_VHT40_PILOTS] = { 11, 39, 53, 75, 89, 117 };
const unsigned char pilotToneIndexVHT20[SC5_VHT20_PILOTS] = { 11, 25, 39, 53 };
const unsigned char pilotToneIndexHE80[SC5_HE80_PILOTS] = { 11, 28, 105, 122, 134, 151, 228, 245 };
const unsigned char pilotToneIndexHE40[SC5_HE40_PILOTS] = { 11, 28, 38, 55, 73, 90, 100, 117 };
const unsigned char pilotToneIndexHE20[SC5_HE20_PILOTS] = { 3, 20, 44, 61 };

const unsigned char pilotToneIndexHT20[SC5_HT20_PILOTS] = { 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 32, \
34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58,};
const unsigned char pilotToneIndexLEG20[SC5_HT20_PILOTS] = { 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 32, \
35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, };

#ifdef REMOVE_IIR
#define P(x) (((x*REMOVE_IIR*MAX_FFT_SIZE)>>IIR_FORMAT_NP)&(MAX_FFT_SIZE-1)) // adjust index format to twiddle table
#ifdef STA_20_ONLY
const short phiCorr64[64] = {P(-2560), P(-2049), P(-1731), P(-1527), P(-1376), P(-1254), P(-1151), P(-1061), P(-981), P(-910), P(-845), P(-785), P(-730), P(-679), P(-631), P(-586), P(-543), P(-502), P(-462), P(-424), P(-388), P(-352), P(-318), P(-284), P(-251), P(-218), P(-186), P(-155), P(-123), P(-92), P(-61), P(-31), P(0), P(31), P(61), P(92), P(123), P(155), P(186), P(218), P(251), P(284), P(318), P(352), P(388), P(424), P(462), P(502), P(543), P(586), P(631), P(679), P(730), P(785), P(845), P(910), P(981), P(1061), P(1151), P(1254), P(1376), P(1527), P(1731), P(2049)};
#else
const short phiCorr512[512] ={P(-2560), P(-2488), P(-2417), P(-2348), P(-2281), P(-2218), P(-2158), P(-2101), P(-2049), P(-1999), P(-1953), P(-1910), P(-1870), P(-1832), P(-1796), P(-1763), P(-1731), P(-1701), P(-1673), P(-1646), P(-1620), P(-1595), P(-1572), P(-1549), P(-1527), P(-1506), P(-1486), P(-1466), P(-1447), P(-1429), P(-1411), P(-1393), P(-1376), P(-1360), P(-1344), P(-1328), P(-1313), P(-1297), P(-1283), P(-1268), P(-1254), P(-1241), P(-1227), P(-1214), P(-1201), P(-1188), P(-1176), P(-1163), P(-1151), P(-1139), P(-1128), P(-1116), P(-1105), P(-1094), P(-1083), P(-1072), P(-1061), P(-1051), P(-1040), P(-1030), P(-1020), P(-1010), P(-1001), P(-991), P(-981), P(-972), P(-963), P(-954), P(-945), P(-936), P(-927), P(-918), P(-910), P(-901), P(-893), P(-885), P(-877), P(-869), P(-861), P(-853), P(-845), P(-837), P(-829), P(-822), P(-814), P(-807), P(-800), P(-792), P(-785), P(-778), P(-771), P(-764), P(-757), P(-750), P(-744), P(-737), P(-730), P(-724), P(-717), P(-711), P(-704), P(-698), P(-691), P(-685), P(-679), P(-673), P(-667), P(-661), P(-655), P(-649), P(-643), P(-637), P(-631), P(-625), P(-619), P(-614), P(-608), P(-602), P(-597), P(-591), P(-586), P(-580), P(-575), P(-569), P(-564), P(-558), P(-553), P(-548), P(-543), P(-537), P(-532), P(-527), P(-522), P(-517), P(-512), P(-507), P(-502), P(-497), P(-492), P(-487), P(-482), P(-477), P(-472), P(-467), P(-462), P(-457), P(-453), P(-448), P(-443), P(-438), P(-434), P(-429), P(-424), P(-420), P(-415), P(-410), P(-406), P(-401), P(-397), P(-392), P(-388), P(-383), P(-379), P(-374), P(-370), P(-365), P(-361), P(-357), P(-352), P(-348), P(-343), P(-339), P(-335), P(-330), P(-326), P(-322), P(-318), P(-313), P(-309), P(-305), P(-301), P(-296), P(-292), P(-288), P(-284), P(-280), P(-276), P(-271), P(-267), P(-263), P(-259), P(-255), P(-251), P(-247), P(-243), P(-238), P(-234), P(-230), P(-226), P(-222), P(-218), P(-214), P(-210), P(-206), P(-202), P(-198), P(-194), P(-190), P(-186), P(-182), P(-178), P(-174), P(-170), P(-166), P(-162), P(-159), P(-155), P(-151), P(-147), P(-143), P(-139), P(-135), P(-131), P(-127), P(-123), P(-119), P(-116), P(-112), P(-108), P(-104), P(-100), P(-96), P(-92), P(-88), P(-85), P(-81), P(-77), P(-73), P(-69), P(-65), P(-61), P(-58), P(-54), P(-50), P(-46), P(-42), P(-38), P(-35), P(-31), P(-27), P(-23), P(-19), P(-15), P(-11), P(-8), P(-4), P(0), P(4), P(8), P(11), P(15), P(19), P(23), P(27), P(31), P(35), P(38), P(42), P(46), P(50), P(54), P(58), P(61), P(65), P(69), P(73), P(77), P(81), P(85), P(88), P(92), P(96), P(100), P(104), P(108), P(112), P(116), P(119), P(123), P(127), P(131), P(135), P(139), P(143), P(147), P(151), P(155), P(159), P(162), P(166), P(170), P(174), P(178), P(182), P(186), P(190), P(194), P(198), P(202), P(206), P(210), P(214), P(218), P(222), P(226), P(230), P(234), P(238), P(243), P(247), P(251), P(255), P(259), P(263), P(267), P(271), P(276), P(280), P(284), P(288), P(292), P(296), P(301), P(305), P(309), P(313), P(318), P(322), P(326), P(330), P(335), P(339), P(343), P(348), P(352), P(357), P(361), P(365), P(370), P(374), P(379), P(383), P(388), P(392), P(397), P(401), P(406), P(410), P(415), P(420), P(424), P(429), P(434), P(438), P(443), P(448), P(453), P(457), P(462), P(467), P(472), P(477), P(482), P(487), P(492), P(497), P(502), P(507), P(512), P(517), P(522), P(527), P(532), P(537), P(543), P(548), P(553), P(558), P(564), P(569), P(575), P(580), P(586), P(591), P(597), P(602), P(608), P(614), P(619), P(625), P(631), P(637), P(643), P(649), P(655), P(661), P(667), P(673), P(679), P(685), P(691), P(698), P(704), P(711), P(717), P(724), P(730), P(737), P(744), P(750), P(757), P(764), P(771), P(778), P(785), P(792), P(800), P(807), P(814), P(822), P(829), P(837), P(845), P(853), P(861), P(869), P(877), P(885), P(893), P(901), P(910), P(918), P(927), P(936), P(945), P(954), P(963), P(972), P(981), P(991), P(1001), P(1010), P(1020), P(1030), P(1040), P(1051), P(1061), P(1072), P(1083), P(1094), P(1105), P(1116), P(1128), P(1139), P(1151), P(1163), P(1176), P(1188), P(1201), P(1214), P(1227), P(1241), P(1254), P(1268), P(1283), P(1297), P(1313), P(1328), P(1344), P(1360), P(1376), P(1393), P(1411), P(1429), P(1447), P(1466), P(1486), P(1506), P(1527), P(1549), P(1572), P(1595), P(1620), P(1646), P(1673), P(1701), P(1731), P(1763), P(1796), P(1832), P(1870), P(1910), P(1953), P(1999), P(2049), P(2101), P(2158), P(2218), P(2281), P(2348), P(2417), P(2488)};
const short phiCorrScBt512[512] ={P(-3584), P(-3243), P(-2979), P(-2789), P(-2648), P(-2534), P(-2440), P(-2358), P(-2286), P(-2220), P(-2161), P(-2106), P(-2056), P(-2009), P(-1965), P(-1924), P(-1886), P(-1850), P(-1815), P(-1783), P(-1752), P(-1722), P(-1694), P(-1667), P(-1642), P(-1617), P(-1593), P(-1570), P(-1548), P(-1526), P(-1506), P(-1485), P(-1466), P(-1447), P(-1429), P(-1411), P(-1393), P(-1376), P(-1360), P(-1343), P(-1328), P(-1312), P(-1297), P(-1282), P(-1268), P(-1253), P(-1240), P(-1226), P(-1213), P(-1199), P(-1187), P(-1174), P(-1161), P(-1149), P(-1137), P(-1125), P(-1114), P(-1102), P(-1091), P(-1080), P(-1069), P(-1059), P(-1048), P(-1038), P(-1027), P(-1017), P(-1007), P(-997), P(-988), P(-978), P(-969), P(-959), P(-950), P(-941), P(-932), P(-923), P(-915), P(-906), P(-898), P(-889), P(-881), P(-873), P(-864), P(-856), P(-848), P(-841), P(-833), P(-825), P(-817), P(-810), P(-802), P(-795), P(-788), P(-780), P(-773), P(-766), P(-759), P(-752), P(-745), P(-738), P(-732), P(-725), P(-718), P(-712), P(-705), P(-699), P(-692), P(-686), P(-679), P(-673), P(-667), P(-661), P(-655), P(-648), P(-642), P(-636), P(-630), P(-625), P(-619), P(-613), P(-607), P(-601), P(-596), P(-590), P(-584), P(-579), P(-573), P(-568), P(-562), P(-557), P(-551), P(-546), P(-540), P(-535), P(-530), P(-524), P(-519), P(-514), P(-509), P(-504), P(-498), P(-493), P(-488), P(-483), P(-478), P(-473), P(-468), P(-463), P(-458), P(-453), P(-449), P(-444), P(-439), P(-434), P(-429), P(-424), P(-420), P(-415), P(-410), P(-405), P(-401), P(-396), P(-391), P(-387), P(-382), P(-378), P(-373), P(-368), P(-364), P(-359), P(-355), P(-350), P(-346), P(-341), P(-337), P(-333), P(-328), P(-324), P(-319), P(-315), P(-311), P(-306), P(-302), P(-297), P(-293), P(-289), P(-284), P(-280), P(-276), P(-272), P(-267), P(-263), P(-259), P(-255), P(-250), P(-246), P(-242), P(-238), P(-234), P(-229), P(-225), P(-221), P(-217), P(-213), P(-209), P(-205), P(-200), P(-196), P(-192), P(-188), P(-184), P(-180), P(-176), P(-172), P(-168), P(-164), P(-159), P(-155), P(-151), P(-147), P(-143), P(-139), P(-135), P(-131), P(-127), P(-123), P(-119), P(-115), P(-111), P(-107), P(-103), P(-99), P(-95), P(-91), P(-87), P(-83), P(-79), P(-75), P(-71), P(-67), P(-63), P(-59), P(-55), P(-51), P(-47), P(-44), P(-40), P(-36), P(-32), P(-28), P(-24), P(-20), P(-16), P(-12), P(-8), P(-4), P(0), P(4), P(8), P(12), P(16), P(20), P(24), P(28), P(32), P(36), P(40), P(44), P(47), P(51), P(55), P(59), P(63), P(67), P(71), P(75), P(79), P(83), P(87), P(91), P(95), P(99), P(103), P(107), P(111), P(115), P(119), P(123), P(127), P(131), P(135), P(139), P(143), P(147), P(151), P(155), P(159), P(164), P(168), P(172), P(176), P(180), P(184), P(188), P(192), P(196), P(200), P(205), P(209), P(213), P(217), P(221), P(225), P(229), P(234), P(238), P(242), P(246), P(250), P(255), P(259), P(263), P(267), P(272), P(276), P(280), P(284), P(289), P(293), P(297), P(302), P(306), P(311), P(315), P(319), P(324), P(328), P(333), P(337), P(341), P(346), P(350), P(355), P(359), P(364), P(368), P(373), P(378), P(382), P(387), P(391), P(396), P(401), P(405), P(410), P(415), P(420), P(424), P(429), P(434), P(439), P(444), P(449), P(453), P(458), P(463), P(468), P(473), P(478), P(483), P(488), P(493), P(498), P(504), P(509), P(514), P(519), P(524), P(530), P(535), P(540), P(546), P(551), P(557), P(562), P(568), P(573), P(579), P(584), P(590), P(596), P(601), P(607), P(613), P(619), P(625), P(630), P(636), P(642), P(648), P(655), P(661), P(667), P(673), P(679), P(686), P(692), P(699), P(705), P(712), P(718), P(725), P(732), P(738), P(745), P(752), P(759), P(766), P(773), P(780), P(788), P(795), P(802), P(810), P(817), P(825), P(833), P(841), P(848), P(856), P(864), P(873), P(881), P(889), P(898), P(906), P(915), P(923), P(932), P(941), P(950), P(959), P(969), P(978), P(988), P(997), P(1007), P(1017), P(1027), P(1038), P(1048), P(1059), P(1069), P(1080), P(1091), P(1102), P(1114), P(1125), P(1137), P(1149), P(1161), P(1174), P(1187), P(1199), P(1213), P(1226), P(1240), P(1253), P(1268), P(1282), P(1297), P(1312), P(1328), P(1343), P(1360), P(1376), P(1393), P(1411), P(1429), P(1447), P(1466), P(1485), P(1506), P(1526), P(1548), P(1570), P(1593), P(1617), P(1642), P(1667), P(1694), P(1722), P(1752), P(1783), P(1815), P(1850), P(1886), P(1924), P(1965), P(2009), P(2056), P(2106), P(2161), P(2220), P(2286), P(2358), P(2440), P(2534), P(2648), P(2789), P(2979), P(3243)};
#endif
#endif

// input is in 16p14
#define ONE_16P14 (1<<14)
int myAsin(int x){

	int numerator, denominator, y, z;

	if(x >= ONE_16P14){
		return (1<<(MPY_BIPT-2)); // PI/2
	}
	else if(-x >= ONE_16P14){
		return -(1<<(MPY_BIPT-2)); // -PI/2
	}
	else if(x==0){
		return 0;
	}
	else{
		y = ONE_16P14 -((x*x)>>14);
		denominator = mySqrt(y);
		numerator = (x<<7);
		z = numerator/denominator;
		return myAtan2(ONE_16P14, z);
	}
}


int myAtan2(int valI, int valQ){

	int x, y_old, y_new;
	short cosValInt, sinValInt;
	int idx, zerosI, zerosQ;
	int ii, quadrant = 0;
	unsigned int tempVal;
	unsigned int *cosTablePtr = (unsigned int*)radix4FftTwiddleArr;

	if(!valI || !valQ){
		if(!valI && !valQ){ // undefined
			return 0;
		}
		else if(!valI){
			if(valQ>0) // PI/2
				return (1<<(MPY_BIPT-2));
			else // -PI/2
				return -(1<<(MPY_BIPT-2));
		}
		else{ // valQ == 0
			if(valI>0) // 0
				return 0;
			else // PI
				return (1<<(MPY_BIPT-1));
		}
	}

	// determine quadrant, change sign
	if(valQ<0){
		valQ = -valQ;
		quadrant+=2;
	}
	if(valI<0){
		valI=-valI;
		quadrant++;
	}
	//x = 1.0f*valQ/valI;
	zerosQ = __clz(valQ);
	valQ<<=(zerosQ-1);
	ii = zerosQ-1;
	zerosI = __clz(valI);
	if(zerosI<16){ // get at least 16 bit precision
		valI>>=(16-zerosI);
		ii += (16-zerosI);
	}
	x = valQ/valI;
	if(MPY_BIPT>ii)
		x<<=(MPY_BIPT-ii);
	else
		x>>=(ii-MPY_BIPT);

	// initialize
	if(x < 3<<(MPY_BIPT-2)) // 0.75
		y_old = (x*ONE_OVER_PI)>>(MPY_BIPT+1); //x/(2*PI);
	else if(x < 4<<MPY_BIPT){ // 4.0
		y_old = (x-(1<<MPY_BIPT))>>2;
		y_old += 3<<(MPY_BIPT-2); //(0.25f*(x-1)+0.75f)/(2*PI);
		y_old*=ONE_OVER_PI;
		y_old>>=MPY_BIPT+1;
	}
	else
		y_old = (15<<(MPY_BIPT-6)); // approx of (1.5f/(2*PI))<<MPY_BIPT

	// Newton's method with NUM_ATAN_IT=10 fixed iterations
	for(ii=0;ii<NUM_ATAN_IT;ii++){
		idx = (y_old*MAX_FFT_SIZE)>>(MPY_BIPT-1);
#ifdef TWIDDLE_HALF_SIZE
		tempVal = cosTablePtr[idx&(MAX_FFT_SIZE/2-1)];
		if(idx&(MAX_FFT_SIZE/2)){ // [-pi,0)
			cosValInt = -(short) (tempVal&0xffff);
			sinValInt = -(short) (tempVal>>16);
		}
		else{ // [0, pi)
			cosValInt = (short) (tempVal&0xffff);
			sinValInt = (short) (tempVal>>16);
		}
#else
		tempVal = cosTablePtr[idx&(MAX_FFT_SIZE-1)]; // apply modulo
		cosValInt = (short) (tempVal&0xffff);
		sinValInt = (short) (tempVal>>16);
#endif
		y_new = (x*(cosValInt+(1<<TWIDDLE_BIPT)))>>TWIDDLE_BIPT;
		y_new -=sinValInt>>(TWIDDLE_BIPT-MPY_BIPT);
		y_new *=ONE_OVER_PI;
		y_new >>=(MPY_BIPT+2);
		y_new +=y_old;

		if(y_new>(1<<(MPY_BIPT-2))-1)
			y_new = (1<<(MPY_BIPT-2))-8;

		y_old = y_new;
	}

	switch(quadrant){
		case 1:
			return -y_new+(1<<(MPY_BIPT-1));
		case 2:
			return -y_new;
		case 3:
			return y_new-(1<<(MPY_BIPT-1)); //-PI
		default:
			return y_new;
	}
}

unsigned int mySqrtLut(int x){
	unsigned int y = 0;
	int zerosX, shift, shiftBack, idx, offset;
	unsigned int y1;

	if(x>0){ // return 0 for non-positive values
		zerosX = __clz(x);
		shift = 32-TABLE_SIZE_POW-zerosX;
		shiftBack = (shift+1)>>1;
		if(shiftBack>0){
			idx = x>>(2*shiftBack);
			offset = x-(idx<<(2*shiftBack));
			y = sqrtLUT[idx-1]+1;
			y *=(1<<(2*shiftBack))-offset;
			y1 = sqrtLUT[idx]+1;
			y1 *=offset;
			y+=y1;
			shiftBack -=(2*shiftBack)+MY_SQRT_BIPT-(TABLE_SIZE_POW>>1);
		}
		else{
			idx = x<<(-2*shiftBack);
			y = sqrtLUT[idx-1]+1;
			shiftBack -=MY_SQRT_BIPT-(TABLE_SIZE_POW>>1);
		}
		if(shiftBack>0){
			y<<=shiftBack;
		}
		else{
			y>>=(-shiftBack);
		}
	}
	return y;
}

#ifndef ARM_DS5
unsigned int mySqrt(int x){
	int ii, digits, N;
	unsigned int bit, temp, res = 0;
	unsigned num = (x>0)? x:(-x);

	digits = 32-__clz(num);
	digits>>=1;
	N = digits+1;
	digits<<=1;
	bit = 1<<digits;

	for(ii=0;ii<N;ii++){ // res is scaled by 2^(N-1-ii)
		temp = res+bit;
		res>>=1;
		if(num>temp){
			num-=temp;
			res +=bit;
		}
		bit>>=2;
	}
	return res;
}
#endif

// general function: unpacks complex subcarriers, demodulates pilots, and estimates phase-roll and power per subband
void processSubCarrier(unsigned short *dataPtrTmp, short *writePtr, unsigned int pilotVals, const short* phiCorrPtr, int numCsiScHlf, int dataPtrStride, int phiCorrPtrStride, unsigned int *myStack){
	int ii;

#if defined(ARM_GCC) || defined(ARM_DS5)
#ifdef ARM_DS5
    int reg6, reg7, reg8;
#endif
#ifndef REMOVE_IIR
	unsigned int tempVal = myStack[0];
	unsigned int powerEst = myStack[1];
	int runningSumI = myStack[2];
	int runningSumQ = myStack[3];
#endif
#else
	signed char tempI, tempQ, pilotSym;
	unsigned int tempVal;
	unsigned short utemp16;
	short lastValI, lastValQ;
	short tempValI = (myStack[0])&0xffff;
	short tempValQ = ((myStack[0])>>16)&0xffff;
	unsigned int powerEst = myStack[1];
	int runningSumI = myStack[2];
	int runningSumQ = myStack[3];
#ifdef REMOVE_IIR
	int idx;
	short cosPhi, sinPhi;
	int resI, resQ;
#endif
#endif

	for(ii=0;ii<numCsiScHlf;ii++){
#if defined ARM_DS5
#ifdef REMOVE_IIR
        __asm volatile
        {
            LDRH reg6, [dataPtrTmp], (2*dataPtrStride)
            SXTB reg7, reg6
            SXTB reg8, reg6, ROR #8
            LDR reg6, [myStack, #4]
            PKHBT reg7, reg7, reg8, LSL #16
            SMLAD reg6, reg7, reg7, reg6
            STR reg6, [myStack, #4]
            LDRH reg8, [phiCorrPtr], (2*phiCorrPtrStride)
            LDR reg6, [radix4FftTwiddleArr, reg8, LSL#2]
            SMUSD reg8, reg6, reg7
            SMUADX reg7, reg6, reg7
            ASR reg8, reg8, #7
            LDR reg6, [myStack]
            PKHBT reg8, reg8, reg7, LSL #9
            STR reg8, [myStack]
            SMUAD reg7, reg6, reg8
            STR reg8, [writePtr], #4
            SMUSDX reg8, reg6, reg8
            LDR reg6, [myStack, #8]
            ADD reg6, reg6, reg7, ASR #12
            STR reg6, [myStack, #8]
            LDR reg7, [myStack, #12]
            ADD reg7, reg7, reg8, ASR #12
            STR reg7, [myStack, #12]
        }
#else
        __asm volatile
        {
            LDRH reg6, [dataPtrTmp], (2*dataPtrStride)
            SXTB reg7, reg6
            SXTB reg8, reg6, ROR #8
            MOV reg6, tempVal
            PKHBT tempVal, reg7, reg8, LSL #16
            SMLAD powerEst, tempVal, tempVal, powerEst
            SMLAD runningSumI, reg6, tempVal, runningSumI
            SMLSDX runningSumQ, reg6, tempVal, runningSumQ
            LSL reg7, reg7, #8
            PKHBT reg7, reg7, reg8, LSL #24
            STR reg7, [writePtr], #4
        }
#endif
#elif defined ARM_GCC
#ifdef REMOVE_IIR
		asm volatile (
			"LDRH r6, [%[read]], %[strideDw] \n\t"	// +r6
			"SXTB r7, r6 \n\t"						// +r7, r6
			"SXTB r8, r6, ROR #8 \n\t"				// +r8, r7, -r6
			"LDR r6, [%[myStack], #4] \n\t"			// +r6, ,r7, r8; load powerEst
			"PKHBT r7, r7, r8, LSL #16 \n\t"		// r6, r7, -r8
			"SMLAD r6, r7, r7, r6 \n\t"				// r6, r7
			"STR r6, [%[myStack], #4] \n\t"			// r7, -r6; store powerEst
			"LDRH r8, [%[phiCorr]], %[phiCorrStrideHw] \n\t" // +r8, r7
			"LDR r6, [%[twiddleArr], r8, LSL#2] \n\t" // +r6, r7, -r8
			"SMUSD r8, r6, r7 \n\t"					// +r8, r6, r7
			"SMUADX r7, r6, r7 \n\t"				// r7, r8, -r6
			"ASR r8, r8, #7 \n\t"					// r7, r8
			"LDR r6, [%[myStack]] \n\t"				// +r6, r7, r8; load tempVal
			"PKHBT r8, r8, r7, LSL #9 \n\t"			// r6, r8, -r7
			"STR r8, [%[myStack]] \n\t"				// r6, r8 ; store new tempVal
			"SMUAD r7, r6, r8 \n\t"					// +r7, r6, r8
			"STR r8, [%[write]], #4 \n\t"			// r6, r7, r8
			"SMUSDX r8, r6, r8 \n\t"				// r7, r8, -r6
			"LDR r6, [%[myStack], #8] \n\t"			// +r6, r7, r8; load runningSumI
			"ADD r6, r6, r7, ASR #12 \n\t"			// r6, r8, -r7
			"STR r6, [%[myStack], #8] \n\t"			// r8, -r6; store runningSumI
			"LDR r7, [%[myStack], #12] \n\t"		// +r7, r8; load runningSumQ
			"ADD r7, r7, r8, ASR #12 \n\t"			// r7, -r8
			"STR r7, [%[myStack], #12] \n\t"		// -r8; store runningSumQ
			: [read]"+r"(dataPtrTmp), [write]"+r"(writePtr), [phiCorr]"+r"(phiCorrPtr)
			: [strideDw]"r"(2*dataPtrStride), [phiCorrStrideHw]"r"(2*phiCorrPtrStride), [twiddleArr]"r"(radix4FftTwiddleArr), [myStack]"r"(myStack)
			: "r6", "r7", "r8", "memory");
#else
		asm volatile (
			"LDRH r6, [%[read]], %[strideDw] \n\t"
			"SXTB r7, r6 \n\t"
			"SXTB r8, r6, ROR #8 \n\t"
			"MOV r6, %[tempVal] \n\t"
			"PKHBT %[tempVal], r7, r8, LSL #16 \n\t"
			"SMLAD %[powerEst], %[tempVal], %[tempVal], %[powerEst] \n\t"
			"SMLAD %[sumI], r6, %[tempVal], %[sumI] \n\t"
			"SMLSDX %[sumQ], r6, %[tempVal], %[sumQ] \n\t"
			"LSL r7, r7, #8 \n\t"
			"PKHBT r7, r7, r8, LSL #24 \n\t"
			"STR r7, [%[write]], #4 \n\t"
			: [read]"+r"(dataPtrTmp), [write]"+r"(writePtr), [tempVal]"+r"(tempVal), [powerEst] "+r"(powerEst), [sumI]"+r"(runningSumI), [sumQ]"+r"(runningSumQ)
			: [strideDw]"r"(2*dataPtrStride)
			: "r6", "r7", "r8");
#endif
#elif !defined(ARM_DS5) && !defined(ARM_GCC) // no ARM
		utemp16 = *dataPtrTmp;
		dataPtrTmp+=dataPtrStride;
		tempI = utemp16&0xff;
		tempQ = (utemp16>>8);
		pilotSym = 2*(pilotVals&1)-1; pilotVals>>=1;
		lastValI = tempValI;
		lastValQ = tempValQ;
		tempValI = (short)tempI*pilotSym;
		tempValQ = (short)tempQ*pilotSym;
		powerEst += tempValI*tempValI + tempValQ*tempValQ;
#ifdef REMOVE_IIR
		idx = *phiCorrPtr; phiCorrPtr+=phiCorrPtrStride;
		cosPhi = radix4FftTwiddleArr[2*idx];
		sinPhi = radix4FftTwiddleArr[2*idx+1];
		resI = tempValI*cosPhi-tempValQ*sinPhi;
		resQ = tempValI*sinPhi+tempValQ*cosPhi;
		tempValI = (short)(resI>>(TWIDDLE_BIPT-8));
		tempValQ = (short)(resQ>>(TWIDDLE_BIPT-8));
		runningSumI += ((lastValI*tempValI) + (lastValQ*tempValQ))>>12;
		runningSumQ += ((lastValI*tempValQ) - (lastValQ*tempValI))>>12;
		writePtr[0] = tempValI;
		writePtr[1] = tempValQ;
#else
		runningSumI += ((lastValI*tempValI) + (lastValQ*tempValQ));
		runningSumQ += ((lastValI*tempValQ) - (lastValQ*tempValI));
		writePtr[0] = tempValI<<8;
		writePtr[1] = tempValQ<<8;
#endif
		writePtr+=2;
#endif
	}

#if defined(ARM_GCC) || defined(ARM_DS5)
#ifndef REMOVE_IIR
	myStack[0] = tempVal;
	myStack[1] = powerEst;
	myStack[2] = runningSumI;
	myStack[3] = runningSumQ;
#endif
#else
	tempVal = ((unsigned int)tempValQ)<<16;
	myStack[0] = (((unsigned int)tempValI)&0xffff) | tempVal;
	myStack[1] = powerEst;
	myStack[2] = runningSumI;
	myStack[3] = runningSumQ;
#endif
}


// separate function due to non-uniform spacing of subcarriers; keep zeros between subcarriers to avoid distortion
// FFT size is larger, but not significant due to 20 MHz case
void processSubCarrier20MHz(unsigned short *dataPtrTmp, short *writePtr, unsigned int pilotVals, const short* phiCorrPtr, int numCsiScHlf, int dataPtrStride, int phiCorrPtrStride, unsigned char Ng, unsigned char jumpIdx, unsigned int *myStack){
	int ii;
#if defined(ARM_GCC) || defined(ARM_DS5)

#ifdef ARM_DS5
	int reg6, reg7, reg8;
#endif
#ifndef REMOVE_IIR
	unsigned int tempVal = myStack[0];
	unsigned int powerEst = myStack[1];
	int runningSumI = myStack[2];
	int runningSumQ = myStack[3];
#endif

#else // not ARM

	signed char tempI, tempQ, pilotSym;
	unsigned int tempVal;
	unsigned short utemp16;
	short lastValI, lastValQ;
	short tempValI = (myStack[0])&0xffff;
	short tempValQ = ((myStack[0])>>16)&0xffff;
	unsigned int powerEst = myStack[1];
	int runningSumI = myStack[2];
	int runningSumQ = myStack[3];
#ifdef REMOVE_IIR
	int idx;
	short cosPhi, sinPhi;
	int resI, resQ;
#endif

#endif

	for(ii=0;ii<numCsiScHlf;ii++){
#if defined(ARM_DS5)
#ifdef REMOVE_IIR
    __asm volatile
    {
        LDRH reg6, [dataPtrTmp], (2*dataPtrStride)
        SXTB reg7, reg6
        SXTB reg8, reg6, ROR #8
        LDR reg6, [myStack, #4]
        PKHBT reg7, reg7, reg8, LSL #16
        SMLAD reg6, reg7, reg7, reg6
        STR reg6, [myStack, #4]
        LDRH reg8, [phiCorrPtr], (2*phiCorrPtrStride)
        LDR reg6, [radix4FftTwiddleArr, reg8, LSL#2]
        SMUSD reg8, reg6, reg7
        SMUADX reg7, reg6, reg7
        ASR reg8, reg8, #7
        LDR reg6, [myStack]
        PKHBT reg8, reg8, reg7, LSL #9
        STR reg8, [myStack]
        SMUAD reg7, reg6, reg8
        STR reg8, [writePtr], (4*Ng)
        SMUSDX reg8, reg6, reg8
        LDR reg6, [myStack, #8]
        ADD reg6, reg6, reg7, ASR #12
        STR reg6, [myStack, #8]
        LDR reg7, [myStack, #12]
        ADD reg7, reg7, reg8, ASR #12
        STR reg7, [myStack, #12]
    }
#else
    __asm volatile
    {
        LDRH reg6, [dataPtrTmp], (2*dataPtrStride)
        SXTB reg7, reg6
        SXTB reg8, reg6, ROR #8
        MOV reg6, tempVal
        PKHBT tempVal, reg7, reg8, LSL #16
        SMLAD powerEst, tempVal, tempVal, powerEst
        SMLAD runningSumI, reg6, tempVal, runningSumI
        SMLSDX runningSumQ, reg6, tempVal, runningSumQ
        LSL reg7, reg7, #8
        PKHBT reg7, reg7, reg8, LSL #24
        STR reg7, [writePtr], (4*Ng)
    }
#endif

#elif defined(ARM_GCC)
#ifdef REMOVE_IIR
	asm volatile (
		"LDRH r6, [%[read]], %[strideDw] \n\t"
		"SXTB r7, r6 \n\t"
		"SXTB r8, r6, ROR #8 \n\t"
		"LDR r6, [%[myStack], #4] \n\t"
		"PKHBT r7, r7, r8, LSL #16 \n\t"
		"SMLAD r6, r7, r7, r6 \n\t"
		"STR r6, [%[myStack], #4] \n\t"
		"LDRH r8, [%[phiCorr]], %[phiCorrStrideHw] \n\t"
		"LDR r6, [%[twiddleArr], r8, LSL#2] \n\t"
		"SMUSD r8, r6, r7 \n\t"
		"SMUADX r7, r6, r7 \n\t"
		"ASR r8, r8, #7 \n\t"
		"LDR r6, [%[myStack]] \n\t"
		"PKHBT r8, r8, r7, LSL #9 \n\t"
		"STR r8, [%[myStack]] \n\t"
		"SMUAD r7, r6, r8 \n\t"
		"STR r8, [%[write]], %[Ng] \n\t"
		"SMUSDX r8, r6, r8 \n\t"
		"LDR r6, [%[myStack], #8] \n\t"
		"ADD r6, r6, r7, ASR #12 \n\t"
		"STR r6, [%[myStack], #8] \n\t"
		"LDR r7, [%[myStack], #12] \n\t"
		"ADD r7, r7, r8, ASR #12 \n\t"
		"STR r7, [%[myStack], #12] \n\t"
		: [read]"+r"(dataPtrTmp), [write]"+r"(writePtr), [phiCorr]"+r"(phiCorrPtr)
		: [strideDw]"r"(2*dataPtrStride), [phiCorrStrideHw]"r"(2*phiCorrPtrStride), [twiddleArr]"r"(radix4FftTwiddleArr), [Ng]"r"(4*Ng), [myStack]"r"(myStack)
		: "r6", "r7", "r8");
#else
	asm volatile (
		"LDRH r6, [%[read]], %[strideDw] \n\t"
		"SXTB r7, r6 \n\t"
		"SXTB r8, r6, ROR #8 \n\t"
		"MOV r6, %[tempVal] \n\t"
		"PKHBT %[tempVal], r7, r8, LSL #16 \n\t"
		"SMLAD %[powerEst], %[tempVal], %[tempVal], %[powerEst] \n\t"
		"SMLAD %[sumI], r6, %[tempVal], %[sumI] \n\t"
		"SMLSDX %[sumQ], r6, %[tempVal], %[sumQ] \n\t"
		"LSL r7, r7, #8 \n\t"
		"PKHBT r7, r7, r8, LSL #24 \n\t"
		"STR r7, [%[write]], %[Ng] \n\t"
		: [read]"+r"(dataPtrTmp), [write]"+r"(writePtr), [pilots]"+r"(pilotVals), [tempVal]"+r"(tempVal), [powerEst] "+r"(powerEst), [sumI]"+r"(runningSumI), [sumQ]"+r"(runningSumQ)
		: [strideDw]"r"(2*dataPtrStride), [Ng]"r"(4*Ng)
		: "r6", "r7", "r8");
#endif
#elif !defined(ARM_GCC) && !defined(ARM_DS5)
		utemp16 = *dataPtrTmp;
		dataPtrTmp+=dataPtrStride;
		tempI = utemp16&0xff;
		tempQ = (utemp16>>8);
		pilotSym = 2*(pilotVals&1)-1; pilotVals>>=1;
		lastValI = tempValI;
		lastValQ = tempValQ;
		tempValI = (short)tempI*pilotSym;
		tempValQ = (short)tempQ*pilotSym;
		powerEst += tempValI*tempValI + tempValQ*tempValQ;
#ifdef REMOVE_IIR
		idx = *phiCorrPtr; phiCorrPtr+=phiCorrPtrStride;
		cosPhi = radix4FftTwiddleArr[2*idx];
		sinPhi = radix4FftTwiddleArr[2*idx+1];
		resI = tempValI*cosPhi-tempValQ*sinPhi;
		resQ = tempValI*sinPhi+tempValQ*cosPhi;
		tempValI = (short)(resI>>(TWIDDLE_BIPT-8));
		tempValQ = (short)(resQ>>(TWIDDLE_BIPT-8));
#else
		tempValI<<=8;
		tempValQ<<=8;
#endif
		runningSumI += ((lastValI*tempValI) + (lastValQ*tempValQ))>>12;
		runningSumQ += ((lastValI*tempValQ) - (lastValQ*tempValI))>>12;
		writePtr[0] = tempValI;
		writePtr[1] = tempValQ;
		writePtr+=2*Ng;
#endif
		if(ii == jumpIdx){
			writePtr-=2;
#ifdef REMOVE_IIR
			phiCorrPtr-=phiCorrPtrStride/Ng;
#endif
		}
	}
#if defined(ARM_GCC) || defined(ARM_DS5)
#ifndef REMOVE_IIR
	myStack[0] = tempVal;
	myStack[1] = powerEst;
	myStack[2] = runningSumI;
	myStack[3] = runningSumQ;
#endif
#else // not ARM
	tempVal = ((unsigned int)tempValQ)<<16;
	myStack[0] = (((unsigned int)tempValI)&0xffff) | tempVal;
	myStack[1] = powerEst;
	myStack[2] = runningSumI;
	myStack[3] = runningSumQ;
#endif
}

// function cycles through rx/tx combinations and then calls subfunction for processing
// for 40 MHz per 20 MHz subband, for 80/160 MHz per 40 MHz block
void readHexDataDemodulateProcessVhtHeNg1(hal_pktinfo_t *pktinfo, hal_wls_processing_input_params_t *inputVals, unsigned int* dataPtr, int csiDataSize, unsigned int *fftInBfr, unsigned int *powerPerSubband, int *phaseRollPtr, int chNum) {

	unsigned short *dataPtrTmp;
	short *writePtr;
	const short *phiCorrPtrTemp = 0;
	int ii, jj, kk, bb;
	int pp, nRx, nTx;
	int dcZeros = 0;
	int dcZeros2 = 0;
	int numBands = 1;
	short scStart = 0;
	short scStop = 0;
	int scStart2 = 0;
	int scStop2 = 0;
	int numTonesIt, tonePos;
	int nRx0 = pktinfo->nRx + 1;
	int nTx0 = pktinfo->nTx + 1;
	//int NgDsfShift = pktinfo->NgDsfShift;
	int sigSubbands = pktinfo->sigBw;
	//int subbandSize = 1 << (6 - NgDsfShift);
	int bandwidth = 20 << sigSubbands;
	int ifftSizeOsf = 1 << (pktinfo->fftSize + 6);
	int dataPtrStride = nTx0*nRx0; // now in 2 byte steps
	const unsigned int *pilotValsPtr = pilotDummyArray;
	int phiCorrPtrStride = 0;
	unsigned int tempPow, myStack[4]; // includes tempVal|powerEst| runningSumI|runningSumQ
	unsigned char pilotToneIndexVHT80[SC5_VHT80_PILOTS] = { 25,53,89,117,139,167,203,231 };
	unsigned char pilotToneIndexVHT40[SC5_VHT40_PILOTS] = { 11,39,53,75,89,117 };
	unsigned char pilotToneIndexVHT20[SC5_VHT20_PILOTS] = { 11,25,39,53 };
	const unsigned char *pilotIdx;
	int numPilots, pilotSkip, dcSkip;

#ifdef REMOVE_IIR
	int devSubbands = pktinfo->rxDevBw;
	const short *phiCorrPtr = 0;
	int phiCorrScale = 0;
	int channelOffset = 0;
	int deviceBandwidth = 20 << devSubbands;
	//if (deviceBandwidth > 80) { // 80+80, is really 80 MHz
	//	deviceBandwidth = 80;
	//	devSubbands = 2;
	//}
#ifdef STA_20_ONLY
	phiCorrPtr = phiCorr64;
#else
	phiCorrPtr = phiCorr512;
	if (pktinfo->rxDevBw) { // > 20 MHz
		phiCorrPtr = phiCorrScBt512;
	}
#endif
#endif
	nTx = (pktinfo->nTx<inputVals->nTx) ? (pktinfo->nTx + 1) : (inputVals->nTx + 1);
	if (MAX_TX<nTx) {
		nTx = MAX_TX;
	}
	pktinfo->nTx = nTx - 1;
	nRx = (pktinfo->nRx<inputVals->nRx) ? (pktinfo->nRx + 1) : (inputVals->nRx + 1);
	if (MAX_RX<nRx) {
		nRx = MAX_RX;
	}
	pktinfo->nRx = nRx - 1;

#if defined(REMOVE_IIR) && !defined(STA_20_ONLY)
	if (bandwidth<deviceBandwidth) {	// figure out channel offset
		if (chNum<36) { // 2.4 GHZ
			channelOffset = 0; // control channel always on bottom
		}
		else if (chNum<149) { // 5 GHz
			channelOffset = ((chNum - 36) >> (2 + sigSubbands))&((1 << (devSubbands - sigSubbands)) - 1);
		}
		else {
			channelOffset = ((chNum - 149) >> (2 + sigSubbands))&((1 << (devSubbands - sigSubbands)) - 1);
		}
		// add offset
		phiCorrPtr += channelOffset*(1 << (9 + sigSubbands - devSubbands));
	}
	phiCorrScale = 3 - devSubbands; // since filter is in 160 MHz resolution
#endif

	if (pktinfo->packetType == 3) { // VHT
		pilotSkip = 0;
		dcSkip = 0;
		if ((bandwidth == 80) || (bandwidth == 160)) {
			// 80 MHz 128+[-122:-2 2:122]
			// minus pilots on [103, 75, 39, 11, -103, -75, -39, -11]
			numPilots = SC5_VHT80_PILOTS;
			pilotIdx = pilotToneIndexVHT80;
			dcZeros = 3;
			scStart = 6;
			scStop = 127;
			scStart2 = 130;
			scStop2 = 251;
			if (bandwidth == 160) {
				numBands = 2;
				dcZeros2 = 11;
#ifndef COMPUTE_80P80_AS_160
				pktinfo->sigBw = pktinfo->sigBw - 1;
				pktinfo->nRx = 2 * nRx - 1;
#endif
			}
		}
		else if (bandwidth == 40) {
			// 40 MHz 64+[-58:-2 2:58]
			// minus pilots on [-53,-25,-11,11,25,53]
			numPilots = SC5_VHT40_PILOTS;
			pilotIdx = pilotToneIndexVHT40;
			dcZeros = 3;
			scStart = 6;
			scStop = 63;
			scStart2 = 66;
			scStop2 = 123;
		}
		else { //if(bandwidth == 20)
			   // 20 MHz 32+[-28:-1 1:28]
			   // minus pilots on [-21, -7, 7, 21]
			numPilots = SC5_VHT20_PILOTS;
			pilotIdx = pilotToneIndexVHT20;
			dcZeros = 1;
			scStart = 4;
			scStop = 32;
			scStart2 = 33;
			scStop2 = 61;
		}
	}
	else { // HE
		pilotSkip = 2;
		if ((bandwidth == 80) || (bandwidth == 160)) {
			// 80 MHz 128+[-125:-1 1:125]
			// minus pilots on [-117, -100, -23, -6, 6, 23, 100, 117]
			numPilots = SC5_HE80_PILOTS;
			pilotIdx = pilotToneIndexHE80;
			dcZeros = 1;
			dcSkip = 0;
			scStart = 3;
			scStop = 128;
			scStart2 = 129;
			scStop2 = 254;
			if (bandwidth == 160) {
				numBands = 2;
				dcZeros2 = 5;
#ifndef COMPUTE_80P80_AS_160
				pktinfo->sigBw = pktinfo->sigBw - 1;
				pktinfo->nRx = 2 * nRx - 1;
#endif
			}
		}
		else if (bandwidth == 40) {
			// 40 MHz 64+[-61:-1 1:61]
			// minus pilots on [-53,-36,-26,-9,9,26,36,53]
			numPilots = SC5_HE40_PILOTS;
			pilotIdx = pilotToneIndexHE40;
			dcZeros = 1;
			dcSkip = 0;
			scStart = 3;
			scStop = 64;
			scStart2 = 65;
			scStop2 = 126;
		}
		else { //if(bandwidth == 20)
			   // 20 MHz 32+[-31:0 1:31]
			   // minus pilots on [-29, -12, 12, 29]
			numPilots = SC5_HE20_PILOTS;
			pilotIdx = pilotToneIndexHE20;
			dcZeros = 0;
			dcSkip = 1;
			scStart = 1;
			scStop = 33;
			scStart2 = 33;
			scStop2 = 64;
		}
	}
#ifdef REMOVE_IIR
	phiCorrPtr += scStart << phiCorrScale;
	phiCorrPtrStride = 1 << phiCorrScale;
#endif

	pp = 0;
	for (ii = 0; ii<nTx; ii++) {
		for (jj = 0; jj<nRx; jj++) {
			dataPtrTmp = ((unsigned short*)dataPtr) + (ii + jj*nTx0);
			memset(myStack, 0, 4 * 4);
#if defined(COMPUTE_80P80_AS_160) && defined(REMOVE_IIR)
			phiCorrPtrTemp = phiCorrPtr;
#endif
			for (bb = 0; bb < numBands; bb++) {
#ifdef COMPUTE_80P80_AS_160
				writePtr = (short*)(fftInBfr + ifftSizeOsf*(jj + ii*nRx) + bb * 256);
				//memset(fftInBfr + ifftSizeOsf*(jj + ii*nRx) + bb*256, 0, 4 * ifftSizeOsf);
#else
				writePtr = (short*)(fftInBfr + ifftSizeOsf*(jj + bb* nRx + ii*nRx*numBands));
				//memset(fftInBfr + ifftSizeOsf*(jj + bb* nRx + ii*nRx*numBands), 0, 4 * ifftSizeOsf);
#ifdef REMOVE_IIR
				phiCorrPtrTemp = phiCorrPtr;
#endif
#endif
				memset(writePtr, 0, 4 * ifftSizeOsf);
				writePtr += 2 * scStart;
				tonePos = scStart;
				tempPow = 0;
				// negative spectrum half
				for (kk = 0; kk < numPilots / 2; kk++) {
					numTonesIt = pilotIdx[kk] - tonePos;
					processSubCarrier(dataPtrTmp, writePtr, pilotValsPtr[0], phiCorrPtrTemp, numTonesIt, dataPtrStride, phiCorrPtrStride, myStack);
					tonePos = pilotIdx[kk] + 1; // move write ptr
					dataPtrTmp += (numTonesIt + pilotSkip)*dataPtrStride; // move read ptr
#ifdef REMOVE_IIR
					phiCorrPtrTemp += (numTonesIt + 1)*phiCorrPtrStride;
#endif
					writePtr += 2 * (numTonesIt + 1);
					tempPow += myStack[1];
					myStack[0] = 0;
					myStack[1] = 0;
				}
				numTonesIt = scStop - tonePos;
				processSubCarrier(dataPtrTmp, writePtr, pilotValsPtr[0], phiCorrPtrTemp, numTonesIt, dataPtrStride, phiCorrPtrStride, myStack);
				dataPtrTmp += (numTonesIt + dcSkip)*dataPtrStride;
#ifdef REMOVE_IIR
				phiCorrPtrTemp += (numTonesIt + dcZeros)*phiCorrPtrStride;
#endif
				tempPow += myStack[1];
				myStack[1] = 0;

				powerPerSubband[pp++] = tempPow;

				// positive spectrum half
#ifdef COMPUTE_80P80_AS_160
				writePtr = (short*)(fftInBfr + ifftSizeOsf*(jj + ii*nRx) + bb * 256 + scStart2);
#else
				writePtr = (short*)(fftInBfr + ifftSizeOsf*(jj + bb* nRx + ii*nRx*numBands) + scStart2);
#endif
				tonePos = scStart2;
				tempPow = 0;
				// negative spectrum half
				for (; kk < numPilots; kk++) {
					numTonesIt = pilotIdx[kk] - tonePos;
					processSubCarrier(dataPtrTmp, writePtr, pilotValsPtr[0], phiCorrPtrTemp, numTonesIt, dataPtrStride, phiCorrPtrStride, myStack);
					tonePos = pilotIdx[kk] + 1;
					dataPtrTmp += (numTonesIt + pilotSkip)*dataPtrStride;
#ifdef REMOVE_IIR
					phiCorrPtrTemp += (numTonesIt + 1)*phiCorrPtrStride;
#endif
					writePtr += 2 * (numTonesIt + 1);
					tempPow += myStack[1];
					myStack[0] = 0;
					myStack[1] = 0;
				}
				numTonesIt = scStop2 - tonePos;
				processSubCarrier(dataPtrTmp, writePtr, pilotValsPtr[0], phiCorrPtrTemp, numTonesIt, dataPtrStride, phiCorrPtrStride, myStack);
				dataPtrTmp += numTonesIt*dataPtrStride;
				tempPow += myStack[1];
				myStack[1] = 0;

#ifdef REMOVE_IIR
				phiCorrPtrTemp += (numTonesIt + dcZeros2)*phiCorrPtrStride;
#endif
				powerPerSubband[pp++] = tempPow;
#ifndef COMPUTE_80P80_AS_160
				phaseRollPtr[(jj + bb* nRx + ii*nRx*numBands)] = myAtan2(myStack[2], myStack[3]);
				memset(myStack, 0, 4 * 4);
			}
#else
			}
			phaseRollPtr[(jj + ii*nRx)] = myAtan2(myStack[2], myStack[3]);
#endif
		}
	}
}

void detectPhaseJump(hal_pktinfo_t *pktinfo, hal_wls_processing_input_params_t *inputVals, unsigned int *fftInBfr,  int *phaseRollPtr) {

	int ii, jj, qq;
	int nRx = pktinfo->nRx + 1;
	int nTx = pktinfo->nTx + 1;
	int ifftSizeOsf = 1 << (pktinfo->fftSize + 6);
	unsigned int *cosTablePtr = (unsigned int*)radix4FftTwiddleArr;
	int dcEdge = 0;
	int runningSumI = 0;
	int runningSumQ = 0;

	unsigned int* readPtr;
	unsigned int tempValI, tempValQ, tempValLd;
	short tempI0, tempQ0, tempI1, tempQ1;
	short cosPhi, sinPhi;
	int resLeftI, resLeftQ, resRightI, resRightQ;
	int idx;
	pktinfo->dcPhase = 0;

	if (pktinfo->packetType == 3) { // VHT case
		dcEdge = 6;
	}
	else { // HE case
		dcEdge = 3;
	}

	for (ii = 0;ii < nTx;ii++) {
		for (jj = 0;jj < nRx;jj+= NUM_PARALLEL) {
			readPtr = (fftInBfr + NUM_PARALLEL * ifftSizeOsf * (jj + ii * nRx));

			for (qq = 0; qq < NUM_PARALLEL; qq++){
				// load dc edge I/Q values
				tempValI = readPtr[NUM_PARALLEL * (256 - dcEdge) + qq];
				tempI0 = (tempValI & 0xffff);
				tempQ0 = (tempValI >> 16);

				tempValQ = readPtr[NUM_PARALLEL * (256 + dcEdge) + qq];
				tempI1 = (tempValQ & 0xffff);
				tempQ1 = (tempValQ >> 16);

				// adjust for phase roll(2 * phaseRollNg*MAX_FFT_SIZE) >> MPY_BIPT;

				idx = (dcEdge*phaseRollPtr[qq + jj + ii*nRx] *MAX_FFT_SIZE) >> MPY_BIPT; // Ng=1
				idx &= (MAX_FFT_SIZE - 1); // apply modulo
				tempValLd = cosTablePtr[idx];
				cosPhi = (tempValLd & 0xffff);
				sinPhi = (tempValLd >> 16);

				resLeftI = ((int)cosPhi*tempI0) - ((int)sinPhi*tempQ0);
				resLeftQ = ((int)cosPhi*tempQ0) + ((int)sinPhi*tempI0);
				tempI0 = (short)(resLeftI >> TWIDDLE_BIPT);
				tempQ0 = (short)(resLeftQ >> TWIDDLE_BIPT);

				if (pktinfo->packetType == 3) { // account for tone rotation
					resRightI = - ((int)sinPhi*tempQ1) - ((int)cosPhi*tempI1);
					resRightQ = ((int)sinPhi*tempI1) - ((int)cosPhi*tempQ1);
				}
				else {
					resRightI = ((int)cosPhi*tempI1) + ((int)sinPhi*tempQ1);
					resRightQ = ((int)cosPhi*tempQ1) - ((int)sinPhi*tempI1);
				}
				tempI1 = (short)(resRightI >> TWIDDLE_BIPT);
				tempQ1 = (short)(resRightQ >> TWIDDLE_BIPT);

				// calculate phase jump
				runningSumI += (tempI0*tempI1 + tempQ0*tempQ1)/2;
				runningSumQ += (tempI0*tempQ1 - tempQ0*tempI1)/2;
			}
		}
	}

	idx = myAtan2(runningSumI, runningSumQ);

	if (idx > (1 << (MPY_BIPT - 3))) { // pi/4
		pktinfo->dcPhase = 0x1;
	}
	else if (idx < -(1 << (MPY_BIPT - 3))) { // -pi/4
		pktinfo->dcPhase = 0x3;
	}
}

void readHexDataDemodulateProcess(hal_pktinfo_t *pktinfo, hal_wls_processing_input_params_t *inputVals, unsigned int* dataPtr, int csiDataSize, unsigned int *fftInBfr, unsigned int *powerPerSubband, int *phaseRollPtr, int chNum){

	unsigned short *dataPtrTmp;
	short *writePtr;
	const short *phiCorrPtrTemp = 0;
#if (MAX_RX>1) || (MAX_TX>1)
	int ii, jj;
#endif
	int pp, nRx, nTx;
    int dcZeros = 0;
    int scStart = 0;
	int numCsiScHlf;
	int nRx0 = pktinfo->nRx+1;
	int nTx0 = pktinfo->nTx+1;
	int NgShift = 1+pktinfo->Ng;
	int Ng = 1<<NgShift;
	int NgDsfShift = pktinfo->NgDsfShift;
	int sigSubbands = pktinfo->sigBw;
	int subbandSize = 1<<(6-NgDsfShift);
	int bandwidth = 20<<sigSubbands;
	int ifftSizeOsf = 1<<(pktinfo->fftSize+6);
	int dataPtrStride = nTx0*nRx0; // now in 2 byte steps
	const unsigned int *pilotValsPtr;
	int phiCorrPtrStride = 0;
	unsigned int myStack[4]; // includes tempVal|powerEst| runningSumI|runningSumQ
#ifdef REMOVE_IIR
	const short *phiCorrPtr = 0;
	int devSubbands = pktinfo->rxDevBw;
	int phiCorrScale = 0;
	int deviceBandwidth = 20<<devSubbands;
	int channelOffset = 0;
#ifdef STA_20_ONLY
	phiCorrPtr = phiCorr64;
#else
	phiCorrPtr = phiCorr512;
	if(pktinfo->rxDevBw){ // > 20 MHz
		phiCorrPtr = phiCorrScBt512;
	}
#endif
#endif
	{
		pilotValsPtr = pilotDummyArray;
	}

	nTx = (pktinfo->nTx<inputVals->nTx)?(pktinfo->nTx+1):(inputVals->nTx+1);
	if(MAX_TX<nTx){
		nTx = MAX_TX;
    }
    pktinfo->nTx = nTx-1;
	nRx = (pktinfo->nRx<inputVals->nRx)?(pktinfo->nRx+1):(inputVals->nRx+1);
	if(MAX_RX<nRx){
		nRx = MAX_RX;
	}
	pktinfo->nRx = nRx-1;

#if defined(REMOVE_IIR) && !defined(STA_20_ONLY)
	if(bandwidth<deviceBandwidth){	// figure out channel offset
		if(chNum<36){ // 2.4 GHZ
			channelOffset = 0; // control channel always on bottom
		}
		else if(chNum<149){ // 5 GHz
			channelOffset = ((chNum-36)>>(2+sigSubbands))&((1<<(devSubbands-sigSubbands))-1);
		}
		else{
			channelOffset = ((chNum-149)>>(2+sigSubbands))&((1<<(devSubbands-sigSubbands))-1);
		}
		// add offset
		phiCorrPtr += channelOffset*(1<<(9+sigSubbands-devSubbands));
	}
	phiCorrScale = 3-devSubbands; // since filter is in 160 MHz resolution
#endif
	if(bandwidth == 20){ // 20 MHz [1:Ng:27 28 N-28:Ng:N-2 N-1];
		numCsiScHlf = (14>>(NgShift-1))+1;
		pilotValsPtr += Ng-2;
		dcZeros = 1;
		scStart = 4;
#ifdef REMOVE_IIR
		phiCorrPtr += 4<<phiCorrScale;
#endif
	}
	else if(bandwidth == 40){ // 40 MHz [2:Ng:58 N-58:Ng:N-2];
		numCsiScHlf = 29>>(NgShift-1); // = dataPerChannel/2
		pilotValsPtr += Ng+2;
		dcZeros = 2-NgShift;
		scStart = ((subbandSize<<sigSubbands)/2)-(numCsiScHlf+dcZeros/2);
#ifdef REMOVE_IIR
		phiCorrPtr += 6<<phiCorrScale;
#endif
	}
	else if(bandwidth == 80){ // 80 MHz [2:Ng:122 N-122:Ng:N-2 ];
		numCsiScHlf = 31; // Ng =4 = dataPerChannel/2
		pilotValsPtr += 8;
		dcZeros = 0;
		scStart = ((subbandSize<<sigSubbands)/2)-(numCsiScHlf+dcZeros/2);
#ifdef REMOVE_IIR
		phiCorrPtr += 6<<phiCorrScale;
#endif
	}
	else if(bandwidth == 160){ // 160 MHz [6:Ng:250 N-250:Ng:N-6];
		numCsiScHlf = 62/2; // since processing a quarter at a time
		pilotValsPtr += 8;
		dcZeros = 2;
		scStart = ((subbandSize<<sigSubbands)/2)-(2*numCsiScHlf+dcZeros/2);
#ifdef REMOVE_IIR
		phiCorrPtr += 6<<phiCorrScale;
#endif
	}
#ifdef REMOVE_IIR
	phiCorrPtrStride = Ng<<phiCorrScale;
#endif

	pp = 0;
#if (MAX_RX>1) || (MAX_TX>1)
	for(ii=0;ii<nTx;ii++){
		for(jj=0;jj<nRx;jj++){
			dataPtrTmp = ((unsigned short*)dataPtr)+(ii+jj*nTx0);
			memset(fftInBfr+ifftSizeOsf*(jj+ii*nRx),0,4*ifftSizeOsf);
			writePtr = (short*)(fftInBfr+ifftSizeOsf*(jj+ii*nRx)+scStart);
#else
	{
		{
			dataPtrTmp = ((unsigned short*)dataPtr);
			memset(fftInBfr,0,4*ifftSizeOsf);
			writePtr = (short*)(fftInBfr+scStart);
#endif
			memset(myStack,0,4*4);

#ifdef REMOVE_IIR
			phiCorrPtrTemp = phiCorrPtr;
#endif

			// negative spectrum half
			if(bandwidth == 20){
				processSubCarrier20MHz(dataPtrTmp, writePtr, pilotValsPtr[0], phiCorrPtrTemp, numCsiScHlf, dataPtrStride, phiCorrPtrStride, Ng, numCsiScHlf-2, myStack);
			}
			else {
				if (bandwidth == 160) {
					processSubCarrier(dataPtrTmp, writePtr, pilotValsPtr[0], phiCorrPtrTemp, numCsiScHlf, dataPtrStride, phiCorrPtrStride, myStack);
					dataPtrTmp += numCsiScHlf*dataPtrStride;
					writePtr += numCsiScHlf * 2;
#ifdef REMOVE_IIR
					phiCorrPtrTemp += numCsiScHlf*phiCorrPtrStride;
#endif
					powerPerSubband[pp++] = myStack[1];
					myStack[1] = 0;
				}
				processSubCarrier(dataPtrTmp, writePtr, pilotValsPtr[0], phiCorrPtrTemp, numCsiScHlf, dataPtrStride, phiCorrPtrStride, myStack);
			}
			powerPerSubband[pp++] = myStack[1];
			myStack[1] = 0;

			// positive spectrum half
			dataPtrTmp +=numCsiScHlf*dataPtrStride;
			writePtr +=(numCsiScHlf+dcZeros)*2;
#ifdef REMOVE_IIR
			phiCorrPtrTemp +=(numCsiScHlf+dcZeros)*phiCorrPtrStride;
#endif
			if(bandwidth == 20){
				unsigned char jumpIdx = (pktinfo->packetType) ? (numCsiScHlf - 2) : 0;
				writePtr +=((numCsiScHlf-1)*(Ng-1)-1)*2;
#ifdef REMOVE_IIR
				phiCorrPtrTemp -= 2*phiCorrPtrStride-phiCorrPtrStride/Ng;
#endif
				processSubCarrier20MHz(dataPtrTmp, writePtr, pilotValsPtr[1], phiCorrPtrTemp, numCsiScHlf, dataPtrStride, phiCorrPtrStride, Ng, jumpIdx, myStack);
			}
			else {
				if(bandwidth == 160){
					processSubCarrier(dataPtrTmp, writePtr, pilotValsPtr[0], phiCorrPtrTemp, numCsiScHlf, dataPtrStride, phiCorrPtrStride, myStack);
					dataPtrTmp +=numCsiScHlf*dataPtrStride;
					writePtr +=numCsiScHlf*2;
#ifdef REMOVE_IIR
					phiCorrPtrTemp +=numCsiScHlf*phiCorrPtrStride;
#endif
					powerPerSubband[pp++] = myStack[1];
					myStack[1] = 0;
				}
				processSubCarrier(dataPtrTmp, writePtr, pilotValsPtr[1], phiCorrPtrTemp, numCsiScHlf, dataPtrStride, phiCorrPtrStride, myStack);
			}
			powerPerSubband[pp++] = myStack[1];
			myStack[1] = 0;

#if (MAX_RX>1) || (MAX_TX>1)
			phaseRollPtr[(jj+ii*nRx)] = myAtan2(myStack[2], myStack[3]);
#else
			*phaseRollPtr = myAtan2(myStack[2], myStack[3]);
#endif
		}
	}
}

void calculateTotalPower(hal_pktinfo_t *pktinfo, unsigned int *powerPerSubband, unsigned int *totalpower){

	int ii, jj, tt, qq;
	unsigned int tempVal;
	int nRx = pktinfo->nRx+1;
	int nTx = pktinfo->nTx+1;
	int numSubbands = 1<<(pktinfo->sigBw);
	int numSubBlocks;
	if(pktinfo->sigBw>1){ // for 80 and 160 MHz, 40 MHz subbands
		numSubBlocks = numSubbands>>1;
	}
	else{ // 20 an 40 MHz
		numSubBlocks = 2;
	}

	// determine scaling
	for(ii=0;ii<nTx;ii++){
		for(jj=0;jj<nRx;jj+= NUM_PARALLEL){
			for (qq = 0; qq < NUM_PARALLEL; qq++) {
				tempVal = 0;
				for (tt = 0;tt < numSubBlocks;tt++) {
					tempVal += powerPerSubband[qq + tt*NUM_PARALLEL + (jj + ii*nRx)*numSubBlocks];
				}
				totalpower[qq + jj + ii*nRx] = tempVal;
			}
		}
	}
}

#ifndef STA_20_ONLY
void processLegacyPackets(hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, int bufferspacing, int *phaseRollPtr){

	int ii, jj;
	int nRx = pktinfo->nRx+1;
	int nTx = pktinfo->nTx+1;

	for(ii=0;ii<nTx;ii++){
		for(jj=0;jj<nRx;jj+=NUM_PARALLEL){
			if (pktinfo->sigBw == 0) { // 20 MHz cases
#if defined(FFT_PARALLEL) && defined(ARM_DS5)
				interpolateBandEdges20Intrinsic(pktinfo, fftInBuffer + bufferspacing*(jj + ii*nRx), phaseRollPtr + jj + ii*nRx);
#elif defined(FFT_PARALLEL) && !defined(ARM_DS5)
				interpolateBandEdges20Parallel(pktinfo, fftInBuffer + bufferspacing*(jj + ii*nRx), phaseRollPtr + jj + ii*nRx);
#else
				interpolateBandEdges20(pktinfo, fftInBuffer + bufferspacing*(jj + ii*nRx), phaseRollPtr[jj + ii*nRx]);
#endif
			}
			else{
				if (pktinfo->Ng) { // Ng=4 case
#if defined(FFT_PARALLEL) && defined(ARM_DS5)
					interpolateBandEdgesIntrinsic(pktinfo, fftInBuffer + bufferspacing*(jj + ii*nRx), phaseRollPtr + jj + ii*nRx);
#elif defined(FFT_PARALLEL) && !defined(ARM_DS5)
					interpolateBandEdgesParallel(pktinfo, fftInBuffer + bufferspacing*(jj + ii*nRx), phaseRollPtr + jj + ii*nRx);
#else
					interpolateBandEdges(pktinfo, fftInBuffer + bufferspacing*(jj + ii*nRx), phaseRollPtr[jj + ii*nRx]);
#endif
				}
				else { // 40 MHz case
#if defined(FFT_PARALLEL) && defined(ARM_DS5)
					interpolateBandEdges40Intrinsic(pktinfo, fftInBuffer + bufferspacing*(jj + ii*nRx), phaseRollPtr + jj + ii*nRx);
#elif defined(FFT_PARALLEL) && !defined(ARM_DS5)
					interpolateBandEdges40Parallel(pktinfo, fftInBuffer + bufferspacing*(jj + ii*nRx), phaseRollPtr + jj + ii*nRx);
#else
					interpolateBandEdges40(pktinfo, fftInBuffer + bufferspacing*(jj + ii*nRx), phaseRollPtr[jj + ii*nRx]);
#endif
				}
			}
		}
	}
}
#endif

void ifftProcessing(hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, unsigned int *fftOutBuffer, int bufferspacing){
	int ii, jj;
	int nRx = pktinfo->nRx+1;
	int nTx = pktinfo->nTx+1;
	int ifftSizeOsf = 1<<(pktinfo->fftSize+6);
	short *pSrc = (short*)fftInBuffer;
#ifndef FFT_INPLACE
	short *pDst = (short*)fftOutBuffer;
#endif

#ifdef FFT_INPLACE
	for (ii = 0;ii<nTx;ii++) {
		for (jj = 0;jj<nRx;jj += NUM_PARALLEL) {
#if defined(FFT_PARALLEL) && defined(ARM_DS5)
			radix2IfftIntrinsic(pSrc, ifftSizeOsf, radix4FftTwiddleArr, MAX_FFT_SIZE);
#elif defined(FFT_PARALLEL) && !defined(ARM_DS5)
			radix2IfftParallel(pSrc, ifftSizeOsf, radix4FftTwiddleArr, MAX_FFT_SIZE);
#else
			radix2Ifft(pSrc, ifftSizeOsf, radix4FftTwiddleArr, MAX_FFT_SIZE);
#endif
			pSrc += 2 * NUM_PARALLEL*bufferspacing;
		}
	}
#else

	for (ii = 0;ii<nTx;ii++) {
		for (jj = 0;jj<nRx;jj += NUM_PARALLEL) {
#if defined(FFT_PARALLEL) && defined(ARM_DS5)
			radix4IfftIntrinsic(pSrc, pDst, ifftSizeOsf, radix4FftTwiddleArr, MAX_FFT_SIZE);
#elif defined(FFT_PARALLEL) && !defined(ARM_DS5)
			radix4IfftParallel(pSrc, pDst, ifftSizeOsf, radix4FftTwiddleArr, MAX_FFT_SIZE);
#else
			radix4Ifft(pSrc, pDst, ifftSizeOsf, radix4FftTwiddleArr, MAX_FFT_SIZE);
#endif
			pSrc += 2 * NUM_PARALLEL*bufferspacing;
			pDst += 2 * NUM_PARALLEL*ifftSizeOsf; // can be larger for legacy packets, if ifftSizeOsf was reduced
		}
	}
#endif
}

void interpolatePilots(hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, int bufferspacing, int *phaseRollPtr, unsigned int *totalpower) {

	int ii, jj, kk, bb;
	int phaseRollNg, idx;
	int numPilots, dcZeros;
	const unsigned char *pilotIdx;
	unsigned int * readPtr;
	unsigned int tempValLd, tempValSt;
	short tempI, tempQ;
	int convertI, convertQ;
	int resLeftI, resLeftQ, resRightI, resRightQ, resMidI, resMidQ;
	short sinPhi1, cosPhi1, sinPhi2, cosPhi2, sinPhi3, cosPhi3;

	unsigned int *cosTablePtr = (unsigned int*)radix4FftTwiddleArr;
	int nRx = pktinfo->nRx + 1;
	int nTx = pktinfo->nTx + 1;
	int numSubbands = 1 << pktinfo->sigBw;
	int bandwidth = 20 * numSubbands;
	int fftSizeHalf = (32 * numSubbands) >> (pktinfo->NgDsfShift);
	int fftSize = 2 * fftSizeHalf;
	int numBands = 1;
	int NgShift = 0;
	int extraSc = 0;
	const unsigned char *extraScIdx = NULL;
	unsigned int powerScale = 1;

	if (pktinfo->packetType == 3) { // VHT
#ifndef STA_20_ONLY
		if ((bandwidth == 80) || (bandwidth == 160)) {
			// 80 MHz 128+[-122:-2 2:122]
			// minus pilots on [103, 75, 39, 11, -103, -75, -39, -11]
			numPilots = SC5_VHT80_PILOTS;
			pilotIdx = pilotToneIndexVHT80;
			dcZeros = 3;
			if (bandwidth == 160) {
				fftSizeHalf >>= 1;
				fftSize >>= 1;
				numBands = 2;
			}
		}
		else if (bandwidth == 40) {
			// 40 MHz 64+[-58:-2 2:58]
			// minus pilots on [-53,-25,-11,11,25,53]
			numPilots = SC5_VHT40_PILOTS;
			pilotIdx = pilotToneIndexVHT40;
			dcZeros = 3;
		}
		else
#endif
		{ //if(bandwidth == 20)
			// 20 MHz 32+[-28:-1 1:28]
			// minus pilots on [-21, -7, 7, 21]
			numPilots = SC5_VHT20_PILOTS;
			pilotIdx = pilotToneIndexVHT20;
			dcZeros = 1;
		}
	}
	else {
		if (pktinfo->packetType == 0) { // Leg 20in20 only
										// pilotToneIndexLEG20[SC5_HT20_PILOTS
										// 20 MHz 32+[-28:2:-2 -1 1 2:2:28]
			numPilots = SC5_HT20_PILOTS;
			pilotIdx = pilotToneIndexLEG20;
			dcZeros = 2; // not really DC
			NgShift = 1; // Ng=2
			extraSc = 0; //2; // change phase on two subcarriers
			powerScale = 2;
		}
		else if (pktinfo->packetType == 1) {
#ifndef STA_20_ONLY
			if(pktinfo->sigBw==1){ //HT40
				numPilots = 0;
				pilotIdx = pilotToneIndexHT20; // not used
				dcZeros = 1;
				extraSc = 0; // not used
			}
			else
#endif
			{ // HT 20
				// pilotToneIndexHT20[SC5_HT20_PILOTS
				// 20 MHz 32+[-28:2:-2 -1 1:2:27 28]
				// minus pilots on [-21, -7, 7, 21]
				numPilots = SC5_HT20_PILOTS;
				pilotIdx = pilotToneIndexHT20;
				dcZeros = 0;
				NgShift = 1; // Ng=2
				extraSc = 2; // change phase on two subcarriers
				extraScIdx = pilotToneIndexVHT20 + 2; // skip negative half
				powerScale = 2;
			}
		}
		else { // HE
#ifndef STA_20_ONLY
			if ((bandwidth == 80) || (bandwidth == 160)) {
				// 80 MHz 128+[-125:-1 1:125]
				// minus pilots on [-117, -100, -23, -6, 6, 23, 100, 117]
				numPilots = SC5_HE80_PILOTS;
				pilotIdx = pilotToneIndexHE80;
				dcZeros = 1;
				if (bandwidth == 160) {
					fftSizeHalf >>= 1;
					fftSize >>= 1;
					numBands = 2;
				}
			}
			else if (bandwidth == 40) {
				// 40 MHz 64+[-61:-1 1:61]
				// minus pilots on [-53,-36,-26,-9,9,26,36,53]
				numPilots = SC5_HE40_PILOTS;
				pilotIdx = pilotToneIndexHE40;
				dcZeros = 1;
			}
			else
#endif
			{ //if(bandwidth == 20)
				// 20 MHz 32+[-31:0 1:31]
				// minus pilots on [-29, -12, 12, 29]
				numPilots = SC5_HE20_PILOTS;
				pilotIdx = pilotToneIndexHE20;
				dcZeros = 0;
			}
		}
	}

	for (ii = 0; ii < nTx; ii++){
		for (jj = 0; jj < nRx; jj++){

			// account for extra non-zero subcarriers is substantial
			totalpower[jj + ii*nRx] = powerScale*totalpower[jj + ii*nRx];

			phaseRollNg = (phaseRollPtr[jj + ii*nRx])>> NgShift;

			idx = (phaseRollNg*MAX_FFT_SIZE) >> MPY_BIPT;
			idx &= (MAX_FFT_SIZE - 1); // apply modulo
			tempValLd = cosTablePtr[idx];
			cosPhi1 = (tempValLd & 0xffff);
			sinPhi1 = (tempValLd >> 16);
			if (dcZeros > 1){
				idx = (2 * phaseRollNg*MAX_FFT_SIZE) >> MPY_BIPT;
				idx &= (MAX_FFT_SIZE - 1); // apply modulo
				tempValLd = cosTablePtr[idx];
				cosPhi2 = (tempValLd & 0xffff);
				sinPhi2 = (tempValLd >> 16);

				idx = (3 * phaseRollNg*MAX_FFT_SIZE) >> MPY_BIPT;
				idx &= (MAX_FFT_SIZE - 1); // apply modulo
				tempValLd = cosTablePtr[idx];
				cosPhi3 = (tempValLd & 0xffff);
				sinPhi3 = (tempValLd >> 16);
			}

			for (bb = 0; bb < numBands; bb++){
				readPtr = fftInBuffer + bb*fftSize + bufferspacing*(jj + ii*nRx);

				for (kk = 0; kk < extraSc; kk++) {
					tempValLd = readPtr[extraScIdx[kk]];
					tempI = (tempValLd & 0xffff);
					tempQ = (tempValLd >> 16);

					resRightI = (((int)cosPhi1*tempI) + ((int)sinPhi1*tempQ));
					resRightQ = (((int)cosPhi1*tempQ) - ((int)sinPhi1*tempI));
					convertI = resRightI >> TWIDDLE_BIPT;
					convertQ = resRightQ >> TWIDDLE_BIPT;

					tempValSt = (convertI & 0xffff) | (convertQ << 16);
					readPtr[extraScIdx[kk]] = tempValSt;
				}

				if (dcZeros == 2) { // not really DC, just fix edge tones for Legacy 20 MHz
					tempValLd = readPtr[pilotToneIndexLEG20[0] + 1]; // first subcarrier
					tempI = (tempValLd & 0xffff);
					tempQ = (tempValLd >> 16);

					resRightI = (((int)cosPhi2*tempI) + ((int)sinPhi2*tempQ));
					resRightQ = (((int)cosPhi2*tempQ) - ((int)sinPhi2*tempI));
					convertI = resRightI >> TWIDDLE_BIPT;
					convertQ = resRightQ >> TWIDDLE_BIPT;

					tempValSt = (convertI & 0xffff) | (convertQ << 16);
					readPtr[pilotToneIndexLEG20[0] - 1] = tempValSt;

					tempValLd = readPtr[pilotToneIndexLEG20[SC5_HT20_PILOTS-1]-1]; // last subcarrier
					tempI = (tempValLd & 0xffff);
					tempQ = (tempValLd >> 16);

					resRightI = (((int)cosPhi2*tempI) - ((int)sinPhi2*tempQ));
					resRightQ = (((int)cosPhi2*tempQ) + ((int)sinPhi2*tempI));
					convertI = resRightI >> TWIDDLE_BIPT;
					convertQ = resRightQ >> TWIDDLE_BIPT;

					tempValSt = (convertI & 0xffff) | (convertQ << 16);
					readPtr[pilotToneIndexLEG20[SC5_HT20_PILOTS-1]+1] = tempValSt;
				}

				// interpolate pilots
				for (kk = 0; kk < numPilots; kk++){
					tempValLd = readPtr[pilotIdx[kk] + 1];
					tempI = (tempValLd & 0xffff);
					tempQ = (tempValLd >> 16);

					resRightI = (((int)cosPhi1*tempI) + ((int)sinPhi1*tempQ)) / 2;
					resRightQ = (((int)cosPhi1*tempQ) - ((int)sinPhi1*tempI)) / 2;

					tempValLd = readPtr[pilotIdx[kk] - 1];
					tempI = (tempValLd & 0xffff);
					tempQ = (tempValLd >> 16);

					resLeftI = (((int)cosPhi1*tempI) - ((int)sinPhi1*tempQ)) / 2;
					resLeftQ = (((int)cosPhi1*tempQ) + ((int)sinPhi1*tempI)) / 2;

					convertI = (resLeftI + resRightI) >> TWIDDLE_BIPT;
					convertQ = (resLeftQ + resRightQ) >> TWIDDLE_BIPT;

					tempValSt = (convertI & 0xffff) | (convertQ << 16);
					readPtr[pilotIdx[kk]] = tempValSt;
				}

				// interpolate DC
				if (dcZeros == 3){
					tempValLd = readPtr[fftSizeHalf + 2];
					tempI = (tempValLd & 0xffff);
					tempQ = (tempValLd >> 16);

					resRightI = (((int)cosPhi1*tempI) + ((int)sinPhi1*tempQ)) / 2;
					resRightQ = (((int)cosPhi1*tempQ) - ((int)sinPhi1*tempI)) / 2;

					resMidI = (((int)cosPhi2*tempI) + ((int)sinPhi2*tempQ)) / 2;
					resMidQ = (((int)cosPhi2*tempQ) - ((int)sinPhi2*tempI)) / 2;

					resLeftI = (((int)cosPhi3*tempI) + ((int)sinPhi3*tempQ)) / 2;
					resLeftQ = (((int)cosPhi3*tempQ) - ((int)sinPhi3*tempI)) / 2;

					tempValLd = readPtr[fftSizeHalf - 2];
					tempI = (tempValLd & 0xffff);
					tempQ = (tempValLd >> 16);

					resRightI += (((int)cosPhi3*tempI) - ((int)sinPhi3*tempQ)) / 2;
					resRightQ += (((int)cosPhi3*tempQ) + ((int)sinPhi3*tempI)) / 2;

					resMidI += (((int)cosPhi2*tempI) - ((int)sinPhi2*tempQ)) / 2;
					resMidQ += (((int)cosPhi2*tempQ) + ((int)sinPhi2*tempI)) / 2;

					resLeftI += (((int)cosPhi1*tempI) - ((int)sinPhi1*tempQ)) / 2;
					resLeftQ += (((int)cosPhi1*tempQ) + ((int)sinPhi1*tempI)) / 2;

					convertI = resRightI >> TWIDDLE_BIPT;
					convertQ = resRightQ >> TWIDDLE_BIPT;
					tempValSt = (convertI & 0xffff) | (convertQ << 16);
					readPtr[fftSizeHalf+1] = tempValSt;

					convertI = resMidI >> TWIDDLE_BIPT;
					convertQ = resMidQ >> TWIDDLE_BIPT;
					tempValSt = (convertI & 0xffff) | (convertQ << 16);
					readPtr[fftSizeHalf] = tempValSt;

					convertI = resLeftI >> TWIDDLE_BIPT;
					convertQ = resLeftQ >> TWIDDLE_BIPT;
					tempValSt = (convertI & 0xffff) | (convertQ << 16);
					readPtr[fftSizeHalf-1] = tempValSt;
				}
				else if (dcZeros == 1) { // dcZeros == 1
					tempValLd = readPtr[fftSizeHalf + 1];
					tempI = (tempValLd & 0xffff);
					tempQ = (tempValLd >> 16);
					resMidI = (((int)cosPhi1*tempI) + ((int)sinPhi1*tempQ)) / 2;
					resMidQ = (((int)cosPhi1*tempQ) - ((int)sinPhi1*tempI)) / 2;

					tempValLd = readPtr[fftSizeHalf - 1];
					tempI = (tempValLd & 0xffff);
					tempQ = (tempValLd >> 16);
					resMidI += (((int)cosPhi1*tempI) - ((int)sinPhi1*tempQ)) / 2;
					resMidQ += (((int)cosPhi1*tempQ) + ((int)sinPhi1*tempI)) / 2;

					convertI = resMidI >> TWIDDLE_BIPT;
					convertQ = resMidQ >> TWIDDLE_BIPT;
					tempValSt = (convertI & 0xffff) | (convertQ << 16);
					readPtr[fftSizeHalf] = tempValSt;
				}
			}
		}
	}

}

void interpolateBandEdges20(hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, int phaseRollNg) {

	unsigned int *cosTablePtr = (unsigned int*)radix4FftTwiddleArr;
	short sinPhi1, cosPhi1, sinPhi2, cosPhi2;
	short sinPhi0, cosPhi0;

	int convertI, convertQ;
	int resLeftI1, resLeftQ1, resRightI1, resRightQ1;
	int resLeftI2, resLeftQ2, resRightI2, resRightQ2;
	short tempI, tempQ;
	unsigned int tempValLd, tempValSt;

	int idx;

	int psb = pktinfo->psb;
	int NgDsfShift = pktinfo->NgDsfShift;
	int subbandSize = 1 << (6 - NgDsfShift);

	unsigned int *readPtr = fftInBuffer;

	idx = (phaseRollNg*MAX_FFT_SIZE) >> MPY_BIPT;
	idx &= (MAX_FFT_SIZE - 1); // apply modulo
	tempValLd = cosTablePtr[idx];
	cosPhi1 = (tempValLd & 0xffff);
	sinPhi1 = (tempValLd >> 16);

	if (pktinfo->rxDevBw == 1) { // 40 MHz device bandwidth
		idx = (2 * phaseRollNg*MAX_FFT_SIZE) >> MPY_BIPT;
		idx &= (MAX_FFT_SIZE - 1); // apply modulo
		tempValLd = cosTablePtr[idx];
		cosPhi2 = (tempValLd & 0xffff);
		sinPhi2 = (tempValLd >> 16);

		idx = (phaseRollNg*MAX_FFT_SIZE) >> (MPY_BIPT + 1); // divide by 2 for Ng=2
		idx &= (MAX_FFT_SIZE - 1); // apply modulo
		tempValLd = cosTablePtr[idx];
		cosPhi0 = (tempValLd & 0xffff);
		sinPhi0 = (tempValLd >> 16);

		// interpolate edge for 20/40
		if (psb == 0) { // left side, right edge
			tempValLd = readPtr[subbandSize - 3];
			tempI = (tempValLd & 0xffff);
			tempQ = (tempValLd >> 16);

			resLeftI1 = ((int)cosPhi2*tempI) - ((int)sinPhi2*tempQ);
			resLeftQ1 = ((int)cosPhi2*tempQ) + ((int)sinPhi2*tempI);

			resLeftI2 = ((int)cosPhi1*tempI) - ((int)sinPhi1*tempQ);
			resLeftQ2 = ((int)cosPhi1*tempQ) + ((int)sinPhi1*tempI);

			convertI = resLeftI1 >> TWIDDLE_BIPT;
			convertQ = resLeftQ1 >> TWIDDLE_BIPT;
			tempValSt = (convertI & 0xffff) | (convertQ << 16);
			readPtr[subbandSize - 1] = tempValSt;

			convertI = resLeftI2 >> TWIDDLE_BIPT;
			convertQ = resLeftQ2 >> TWIDDLE_BIPT;
			tempValSt = (convertI & 0xffff) | (convertQ << 16);
			readPtr[subbandSize - 2] = tempValSt;

			// change phase on sc -32 / 32
			tempValLd = readPtr[subbandSize / 2];
			tempI = (tempValLd & 0xffff);
			tempQ = (tempValLd >> 16);

			resLeftI2 = (((int)cosPhi0*tempI) - ((int)sinPhi0*tempQ));
			resLeftQ2 = (((int)cosPhi0*tempQ) + ((int)sinPhi0*tempI));

			convertI = resLeftI2 >> TWIDDLE_BIPT;
			convertQ = resLeftQ2 >> TWIDDLE_BIPT;
			tempValSt = (convertI & 0xffff) | (convertQ << 16);
			readPtr[subbandSize / 2] = tempValSt;
		}
		else {	//if (psb == 1)  // right side, left edge
			tempValLd = readPtr[subbandSize + 3];
			tempI = (tempValLd & 0xffff);
			tempQ = (tempValLd >> 16);

			resRightI2 = ((int)cosPhi1*tempI) + ((int)sinPhi1*tempQ);
			resRightQ2 = ((int)cosPhi1*tempQ) - ((int)sinPhi1*tempI);

			resRightI1 = ((int)cosPhi2*tempI) + ((int)sinPhi2*tempQ);
			resRightQ1 = ((int)cosPhi2*tempQ) - ((int)sinPhi2*tempI);

			convertI = resRightI2 >> TWIDDLE_BIPT;
			convertQ = resRightQ2 >> TWIDDLE_BIPT;
			tempValSt = (convertI & 0xffff) | (convertQ << 16);
			readPtr[subbandSize + 2] = tempValSt;

			convertI = resRightI1 >> TWIDDLE_BIPT;
			convertQ = resRightQ1 >> TWIDDLE_BIPT;
			tempValSt = (convertI & 0xffff) | (convertQ << 16);
			readPtr[subbandSize + 1] = tempValSt;

			// change phase on sc -32 / 32
			tempValLd = readPtr[3 * subbandSize / 2];
			tempI = (tempValLd & 0xffff);
			tempQ = (tempValLd >> 16);

			resRightI1 = (((int)cosPhi0*tempI) - ((int)sinPhi0*tempQ));
			resRightQ1 = (((int)cosPhi0*tempQ) + ((int)sinPhi0*tempI));

			convertI = resRightI1 >> TWIDDLE_BIPT;
			convertQ = resRightQ1 >> TWIDDLE_BIPT;
			tempValSt = (convertI & 0xffff) | (convertQ << 16);
			readPtr[3 * subbandSize / 2] = tempValSt;
		}
	}
	else { // pktinfo->rxDevBw == 2)  // 80 MHz device bandwidth
		tempValLd = readPtr[psb*subbandSize+1];
		tempI = (tempValLd & 0xffff);
		tempQ = (tempValLd >> 16);

		resLeftI1 = ((int)cosPhi1*tempI) + ((int)sinPhi1*tempQ);
		resLeftQ1 = ((int)cosPhi1*tempQ) - ((int)sinPhi1*tempI);

		convertI = resLeftI1 >> TWIDDLE_BIPT;
		convertQ = resLeftQ1 >> TWIDDLE_BIPT;
		tempValSt = (convertI & 0xffff) | (convertQ << 16);
		readPtr[psb*subbandSize] = tempValSt;

		tempValLd = readPtr[(psb+1)*subbandSize - 2]; // right edge
		tempI = (tempValLd & 0xffff);
		tempQ = (tempValLd >> 16);

		resRightI1 = (((int)cosPhi1*tempI) - ((int)sinPhi1*tempQ));
		resRightQ1 = (((int)cosPhi1*tempQ) + ((int)sinPhi1*tempI));

		convertI = resRightI1 >> TWIDDLE_BIPT;
		convertQ = resRightQ1 >> TWIDDLE_BIPT;
		tempValSt = (convertI & 0xffff) | (convertQ << 16);
		readPtr[(psb + 1)*subbandSize - 1] = tempValSt;
	}
}

void interpolateBandEdges40(hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, int phaseRollNg) {

	unsigned int *cosTablePtr = (unsigned int*)radix4FftTwiddleArr;
	short sinPhi1, cosPhi1, sinPhi2, cosPhi2, sinPhi3, cosPhi3;
	short sinPhi4, cosPhi4, sinPhi5, cosPhi5, sinPhi0, cosPhi0;

	int convertI, convertQ;
	int resLeftI1, resLeftQ1, resRightI1, resRightQ1, resMidI, resMidQ;
	int resLeftI2, resLeftQ2, resRightI2, resRightQ2;
	short tempI, tempQ;
	unsigned int tempValLd, tempValSt;

	int idx;

	int NgDsfShift = pktinfo->NgDsfShift;
	int subbandSize = 1 << (6 - NgDsfShift);

	unsigned int *readPtr = fftInBuffer;

	idx = (phaseRollNg*MAX_FFT_SIZE) >> MPY_BIPT;
	idx &= (MAX_FFT_SIZE - 1); // apply modulo
	tempValLd = cosTablePtr[idx];
	cosPhi1 = (tempValLd & 0xffff);
	sinPhi1 = (tempValLd >> 16);

	idx = (2 * phaseRollNg*MAX_FFT_SIZE) >> MPY_BIPT;
	idx &= (MAX_FFT_SIZE - 1); // apply modulo
	tempValLd = cosTablePtr[idx];
	cosPhi2 = (tempValLd & 0xffff);
	sinPhi2 = (tempValLd >> 16);

	idx = (3 * phaseRollNg*MAX_FFT_SIZE) >> MPY_BIPT;
	idx &= (MAX_FFT_SIZE - 1); // apply modulo
	tempValLd = cosTablePtr[idx];
	cosPhi3 = (tempValLd & 0xffff);
	sinPhi3 = (tempValLd >> 16);

	idx = (4 * phaseRollNg*MAX_FFT_SIZE) >> MPY_BIPT;
	idx &= (MAX_FFT_SIZE - 1); // apply modulo
	tempValLd = cosTablePtr[idx];
	cosPhi4 = (tempValLd & 0xffff);
	sinPhi4 = (tempValLd >> 16);

	idx = (5 * phaseRollNg*MAX_FFT_SIZE) >> MPY_BIPT;
	idx &= (MAX_FFT_SIZE - 1); // apply modulo
	tempValLd = cosTablePtr[idx];
	cosPhi5 = (tempValLd & 0xffff);
	sinPhi5 = (tempValLd >> 16);


	tempValLd = readPtr[subbandSize + 3];
	tempI = (tempValLd & 0xffff);
	tempQ = (tempValLd >> 16);

	resRightI2 = 5*(((int)cosPhi1*tempI) + ((int)sinPhi1*tempQ)) / 6;
	resRightQ2 = 5*(((int)cosPhi1*tempQ) - ((int)sinPhi1*tempI)) / 6;

	resRightI1 = 4*(((int)cosPhi2*tempI) + ((int)sinPhi2*tempQ)) / 6;
	resRightQ1 = 4*(((int)cosPhi2*tempQ) - ((int)sinPhi2*tempI)) / 6;

	resMidI = (((int)cosPhi3*tempI) + ((int)sinPhi3*tempQ)) / 2;
	resMidQ = (((int)cosPhi3*tempQ) - ((int)sinPhi3*tempI)) / 2;

	resLeftI1 = 2*(((int)cosPhi4*tempI) + ((int)sinPhi4*tempQ)) / 6;
	resLeftQ1 = 2*(((int)cosPhi4*tempQ) - ((int)sinPhi4*tempI)) / 6;

	resLeftI2 = (((int)cosPhi5*tempI) + ((int)sinPhi5*tempQ)) / 6;
	resLeftQ2 = (((int)cosPhi5*tempQ) - ((int)sinPhi5*tempI)) / 6;

	tempValLd = readPtr[subbandSize - 3];
	tempI = (tempValLd & 0xffff);
	tempQ = (tempValLd >> 16);

	resRightI2 += (((int)cosPhi5*tempI) - ((int)sinPhi5*tempQ)) / 6;
	resRightQ2 += (((int)cosPhi5*tempQ) + ((int)sinPhi5*tempI)) / 6;

	resRightI1 += 2*(((int)cosPhi4*tempI) - ((int)sinPhi4*tempQ)) / 6;
	resRightQ1 += 2*(((int)cosPhi4*tempQ) + ((int)sinPhi4*tempI)) / 6;

	resMidI += (((int)cosPhi3*tempI) - ((int)sinPhi3*tempQ)) / 2;
	resMidQ += (((int)cosPhi3*tempQ) + ((int)sinPhi3*tempI)) / 2;

	resLeftI1 += 4*(((int)cosPhi2*tempI) - ((int)sinPhi2*tempQ)) / 6;
	resLeftQ1 += 4*(((int)cosPhi2*tempQ) + ((int)sinPhi2*tempI)) / 6;

	resLeftI2 += 5*(((int)cosPhi1*tempI) - ((int)sinPhi1*tempQ)) / 6;
	resLeftQ2 += 5*(((int)cosPhi1*tempQ) + ((int)sinPhi1*tempI)) / 6;

	convertI = resRightI2 >> TWIDDLE_BIPT;
	convertQ = resRightQ2 >> TWIDDLE_BIPT;
	tempValSt = (convertI & 0xffff) | (convertQ << 16);
	readPtr[subbandSize + 2] = tempValSt;

	convertI = resRightI1 >> TWIDDLE_BIPT;
	convertQ = resRightQ1 >> TWIDDLE_BIPT;
	tempValSt = (convertI & 0xffff) | (convertQ << 16);
	readPtr[subbandSize + 1] = tempValSt;

	convertI = resMidI >> TWIDDLE_BIPT;
	convertQ = resMidQ >> TWIDDLE_BIPT;
	tempValSt = (convertI & 0xffff) | (convertQ << 16);
	readPtr[subbandSize] = tempValSt;

	convertI = resLeftI1 >> TWIDDLE_BIPT;
	convertQ = resLeftQ1 >> TWIDDLE_BIPT;
	tempValSt = (convertI & 0xffff) | (convertQ << 16);
	readPtr[subbandSize - 1] = tempValSt;

	convertI = resLeftI2 >> TWIDDLE_BIPT;
	convertQ = resLeftQ2 >> TWIDDLE_BIPT;
	tempValSt = (convertI & 0xffff) | (convertQ << 16);
	readPtr[subbandSize - 2] = tempValSt;

	// change phase on sc -32 / 32
	idx = (phaseRollNg*MAX_FFT_SIZE) >> (MPY_BIPT+1); // divide by 2 for Ng=2
	idx &= (MAX_FFT_SIZE - 1); // apply modulo
	tempValLd = cosTablePtr[idx];
	cosPhi0 = (tempValLd & 0xffff);
	sinPhi0 = (tempValLd >> 16);

	tempValLd = readPtr[subbandSize/2];
	tempI = (tempValLd & 0xffff);
	tempQ = (tempValLd >> 16);

	resLeftI2 = (((int)cosPhi0*tempI) - ((int)sinPhi0*tempQ));
	resLeftQ2 = (((int)cosPhi0*tempQ) + ((int)sinPhi0*tempI));

	convertI = resLeftI2 >> TWIDDLE_BIPT;
	convertQ = resLeftQ2 >> TWIDDLE_BIPT;
	tempValSt = (convertI & 0xffff) | (convertQ << 16);
	readPtr[subbandSize/2] = tempValSt;

	tempValLd = readPtr[3*subbandSize/2];
	tempI = (tempValLd & 0xffff);
	tempQ = (tempValLd >> 16);

	resRightI1 = (((int)cosPhi0*tempI) - ((int)sinPhi0*tempQ));
	resRightQ1 = (((int)cosPhi0*tempQ) + ((int)sinPhi0*tempI));

	convertI = resRightI1 >> TWIDDLE_BIPT;
	convertQ = resRightQ1 >> TWIDDLE_BIPT;
	tempValSt = (convertI & 0xffff) | (convertQ << 16);
	readPtr[3*subbandSize/2] = tempValSt;
}

void interpolateBandEdges(hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, int phaseRollNg){

	int ii;
	int NgDsfShift = pktinfo->NgDsfShift;
	int numSubbands = 1<<pktinfo->sigBw;
	int subbandSize = 1<<(6-NgDsfShift);
	unsigned int *readPtr = fftInBuffer+pktinfo->scOffset;

	readPtr[0] = 0;
	for(ii=1;ii<numSubbands;ii++){
		interpolatePairValue(readPtr+ii*subbandSize-1, readPtr+ii*subbandSize, phaseRollNg);
	}
	readPtr[numSubbands*subbandSize-1] = 0;
}

// H[k] in fft-in buffer are complex conjugate due to replacing iFFT with FFT
void interpolatePairValue(unsigned int *valLeft, unsigned int *valRight, int phaseRollNg){

	unsigned int tempValLd, tempValSt;
	short tempI, tempQ;
	int convertI, convertQ;

#ifdef FLOATING_POINT
	float resLeftI, resLeftQ, resRightI, resRightQ;
	float sinPhi1, cosPhi1, sinPhi2, cosPhi2;
	float angle = PI*phaseRollNg/(1<<(12-1));
	cosPhi1 = cosf(angle);
	sinPhi1 = sinf(angle);
	cosPhi2 = cosf(2*angle);
	sinPhi2 = sinf(2*angle);

#else
	int idx;
	unsigned int *cosTablePtr = (unsigned int*)radix4FftTwiddleArr;
	int resLeftI, resLeftQ, resRightI, resRightQ;
	short sinPhi1, cosPhi1, sinPhi2, cosPhi2;

	idx = (phaseRollNg*MAX_FFT_SIZE)>>MPY_BIPT;
	idx &=(MAX_FFT_SIZE-1); // apply modulo
	tempValLd = cosTablePtr[idx];
	cosPhi1 = (tempValLd&0xffff);
	sinPhi1 = (tempValLd>>16);

	idx = (phaseRollNg*MAX_FFT_SIZE)>>(MPY_BIPT-1);
	idx &=(MAX_FFT_SIZE-1); // apply modulo
	tempValLd = cosTablePtr[idx];
	cosPhi2 = (tempValLd&0xffff);
	sinPhi2 = (tempValLd>>16);
#endif

	// contribution by lltf_missing(2,:)+2
	tempValLd = valRight[2];
	tempI = (tempValLd&0xffff);
	tempQ = (tempValLd>>16);

	resRightI = (((int)cosPhi2*tempI)+((int)sinPhi2*tempQ))/4;
	resRightQ = (((int)cosPhi2*tempQ)-((int)sinPhi2*tempI))/4;

	// contribution by lltf_missing(2,:)+1
	tempValLd = valRight[1];
	tempI = (tempValLd&0xffff);
	tempQ = (tempValLd>>16);

	resRightI += (((int)cosPhi1*tempI)+((int)sinPhi1*tempQ))/2;
	resRightQ += (((int)cosPhi1*tempQ)-((int)sinPhi1*tempI))/2;

	resLeftI = (((int)cosPhi2*tempI)+((int)sinPhi2*tempQ))/4;
	resLeftQ = (((int)cosPhi2*tempQ)-((int)sinPhi2*tempI))/4;

	// contribution by lltf_missing(1,:)-1
	tempValLd = valLeft[-1];
	tempI = (tempValLd&0xffff);
	tempQ = (tempValLd>>16);

	resRightI += (((int)cosPhi2*tempI)-((int)sinPhi2*tempQ))/4;
	resRightQ += (((int)cosPhi2*tempQ)+((int)sinPhi2*tempI))/4;

	resLeftI += (((int)cosPhi1*tempI)-((int)sinPhi1*tempQ))/2;
	resLeftQ += (((int)cosPhi1*tempQ)+((int)sinPhi1*tempI))/2;
#ifdef FLOATING_POINT
	convertI = (int)floorf(resRightI+0.5f);
	convertQ = (int)floorf(resRightQ+0.5f);
#else
	convertI = resRightI>>TWIDDLE_BIPT;
	convertQ = resRightQ>>TWIDDLE_BIPT;
#endif
	tempValSt = (convertI&0xffff) | (convertQ<<16);
	valRight[0] = tempValSt;

	// contribution by lltf_missing(1,:)-2
	tempValLd = valLeft[-2];
	tempI = (tempValLd&0xffff);
	tempQ = (tempValLd>>16);

	resLeftI += (((int)cosPhi2*tempI)-((int)sinPhi2*tempQ))/4;
	resLeftQ += (((int)cosPhi2*tempQ)+((int)sinPhi2*tempI))/4;

#ifdef FLOATING_POINT
	convertI = (int)floorf(resLeftI+0.5f);
	convertQ = (int)floorf(resLeftQ+0.5f);
#else
	convertI = resLeftI>>TWIDDLE_BIPT;
	convertQ = resLeftQ>>TWIDDLE_BIPT;
#endif
	tempValSt = (convertI&0xffff) | (convertQ<<16);
	valLeft[0] = tempValSt;
}

void findActiveSubbands(hal_pktinfo_t *pktinfo, unsigned int *powerPerSubband, unsigned int *totalpower, int chNum, int ftmSignalBW){

	int ii, qq, rx, tx, subBandPer, numSubBlocks, fftSize;
	int subBlock, offset, channelMask, flag=1;
	int channelOffset = 0;

	int sigBwTemp = pktinfo->sigBw; // initialized to devBw
	int NgDsfShift = pktinfo->NgDsfShift;
	int numSubbands = 1<<sigBwTemp;
	int subbandSize = 1<<(6-NgDsfShift);
	int nRx = pktinfo->nRx+1;
	int nTx = pktinfo->nTx+1;
	unsigned int topHalf, bottomHalf, topHalfTemp, bottomHalfTemp;

	// figure out channel offset
	if(chNum>35){ // 5 GHz
		if(chNum<149){
			channelOffset = ((chNum-36)>>2)&(numSubbands-1);
		}
		else{
			channelOffset = ((chNum-149)>>2)&(numSubbands-1);
		}
	}
	pktinfo->scOffset = channelOffset;

	if(sigBwTemp>1){ // for 80 and 160 MHz, 40 MHz subbands
		subBandPer = 2;
		channelOffset>>=1;
	}
	else{
		subBandPer = 1;
	}

	numSubBlocks = numSubbands/subBandPer; offset =0;
	subBlock = numSubBlocks;

	if (numSubBlocks > 1) {
		do {
			channelMask = subBlock - 1;
			subBlock >>= 1;
			bottomHalf = 0;	topHalf = 0; flag = 0;
			for (tx = 0;tx < nTx;tx++) {
				for (rx = 0;rx < nRx;rx += NUM_PARALLEL) {
					for (qq = 0;qq < NUM_PARALLEL; qq++) {
						bottomHalfTemp = 0; topHalfTemp = 0;
						for (ii = 0;ii < subBlock;ii++) {
							bottomHalfTemp += powerPerSubband[qq + (ii + offset*subBlock)*NUM_PARALLEL + (rx + tx*nRx)*numSubBlocks];
							topHalfTemp += powerPerSubband[qq + (ii + (offset + 1)*subBlock)*NUM_PARALLEL + (rx + tx*nRx)*numSubBlocks];
						}
						totalpower[qq + rx + tx*nRx] = topHalfTemp + bottomHalfTemp;
						bottomHalf += bottomHalfTemp;
						topHalf += topHalfTemp;
					}
				}
			}
			bottomHalf /= subBlock*subbandSize*nTx*nRx;
			topHalf /= subBlock*subbandSize*nTx*nRx;

			if (((channelOffset &channelMask) >= subBlock) && ((bottomHalf < SUBBAND_DET_THRESH) || (ftmSignalBW < sigBwTemp))) {
				flag = 1;
				sigBwTemp--;
				offset = 2 * offset + 2;
				numSubbands >>= 1;
				//pktinfo->scOffset += numSubbands*subbandSize;
			}
			else if ((topHalf < SUBBAND_DET_THRESH) || (ftmSignalBW < sigBwTemp)) {
				flag = 1;
				sigBwTemp--;
				numSubbands >>= 1;
			}
		} while (flag && (subBlock > 1));
	}
	else {
		// determine scaling
		numSubBlocks = 2;
		for (tx = 0;tx < nTx;tx++) {
			for (rx = 0;rx < nRx;rx += NUM_PARALLEL) {
				for (qq = 0; qq < NUM_PARALLEL; qq++) {
					unsigned int tempVal = 0;
					for (ii = 0;ii < numSubBlocks;ii++) {
						tempVal += powerPerSubband[qq + ii*NUM_PARALLEL + (rx + tx*nRx)*numSubBlocks];
					}
					totalpower[qq + rx + tx*nRx] = tempVal;
				}
			}
		}
	}

	if (sigBwTemp > ftmSignalBW)
		sigBwTemp = ftmSignalBW;

	channelOffset = (pktinfo->scOffset) >> sigBwTemp;
	pktinfo->scOffset = subbandSize *(channelOffset << sigBwTemp);

	// write back
	if(sigBwTemp!=pktinfo->sigBw){
		pktinfo->sigBw = sigBwTemp;
		fftSize = pktinfo->sigBw +IFFT_OSF_SHIFT -pktinfo->NgDsfShift;
		pktinfo->fftSize = (fftSize > MIN_IFFT_SIZE_SHIFT)? fftSize:MIN_IFFT_SIZE_SHIFT;
	}
}

void zeroOutTones(hal_pktinfo_t *pktinfo, unsigned int *fftInBuffer, int bufferspacing){

	int ii, jj, kk;
	int nRx = pktinfo->nRx+1;
	int nTx = pktinfo->nTx+1;
	int scOffset = pktinfo->scOffset;
	int ifftSizeOsf = 1<<(pktinfo->fftSize+6);
	int numSubbands = 1<<(pktinfo->sigBw);
	int subbandSize = 1<<(6-pktinfo->NgDsfShift);

	unsigned int *writePtr;

	for(ii=0;ii<nTx;ii++){
		for(jj=0;jj<nRx;jj+=NUM_PARALLEL){
			writePtr = fftInBuffer+bufferspacing*(jj+ii*nRx);

			for(kk=0; kk < NUM_PARALLEL*scOffset; kk++){
				writePtr[kk]=0;
			}
			for(kk = NUM_PARALLEL*(scOffset+numSubbands*subbandSize); kk < NUM_PARALLEL*ifftSizeOsf ; kk++){
				writePtr[kk]=0;
			}
		}
	}
}

#ifndef STA_20_ONLY
void removeToneRotation(hal_pktinfo_t *pktinfo, unsigned int *fftInBfr, int bufferspacing){

	int ii, jj, kk;
	short *writePtr;
	int bandwidth = 20<<(pktinfo->sigBw);
	int subbandSize = 1<<(6-pktinfo->NgDsfShift);
	int nRx = pktinfo->nRx+1;
	int nTx = pktinfo->nTx+1;
#if defined(ARM_GCC) || defined(ARM_DS5)
	unsigned int myConst = 0x10001;
	unsigned int myZero = 0x0;
#ifdef ARM_DS5
    int reg6, reg7;
#endif
#else
	short tempI, tempQ;
#endif

	for(ii=0;ii<nTx;ii++){
		for(jj=0;jj<nRx;jj++){
			writePtr = (short*)(fftInBfr+bufferspacing*(jj+ii*nRx)+pktinfo->scOffset);
			if(bandwidth==40){ // second 20 MHz multiply by 1i
#if defined(ARM_GCC) || defined(ARM_DS5)
				writePtr+=2*subbandSize;
				for(kk=0;kk<subbandSize;kk++){
#if defined ARM_DS5
                    __asm volatile
                    {
                        LDR reg6, [writePtr]
                        SSAX reg7, myZero, reg6
                        STR reg7, [writePtr], #4
                    }
#elif defined ARM_GCC
					asm volatile (
						"LDR r6, [%[writePtr]] \n\t"
						"SSAX r7, %[myZero], r6 \n\t"
						"STR r7, [%[writePtr]], #4 \n\t"
						: [writePtr]"+r"(writePtr)
						: [myZero]"r"(myZero) : "r6", "r7");
#endif
				}
#else
				for(kk=subbandSize;kk<2*subbandSize;kk++){
					tempI = writePtr[2*kk];
					tempQ = writePtr[2*kk+1];
					writePtr[2*kk] = tempQ;
					writePtr[2*kk+1] = -tempI;
				}
#endif
			}
			else if( (bandwidth>=80) && (pktinfo->packetType<4) ){ // first 20 MHz multiply by -1
#if defined(ARM_GCC) || defined(ARM_DS5)
				for(kk=0;kk<subbandSize;kk++){
#if defined ARM_DS5
                    __asm volatile
                    {
                        LDR reg6, [writePtr]
                        MVN reg7, reg6
                        SADD16 reg7, reg7, myConst
                        STR reg7, [writePtr], #4
                    }
#elif defined ARM_GCC
					asm volatile (
						"LDR r6, [%[writePtr]] \n\t"
						"MVN r7, r6 \n\t"
						"SADD16 r7, r7, %[myConst] \n\t"
						"STR r7, [%[writePtr]], #4 \n\t"
						: [writePtr]"+r"(writePtr)
						: [myConst]"r"(myConst) : "r6", "r7");
#endif
			}
#else
				for(kk=0;kk<subbandSize;kk++){
                    tempI = writePtr[2*kk];
                    tempQ = writePtr[2*kk+1];
                    writePtr[2*kk] = -tempI;
                    writePtr[2*kk+1] = -tempQ;
				}
#endif
#ifdef SMAC_BFINFO
                if(bandwidth==160){ // first and fifth 20 MHz multiply by -1
#if defined(ARM_GCC) || defined(ARM_DS5)
                	writePtr+=2*3*subbandSize;
                	for(kk=0;kk<subbandSize;kk++){
#if defined ARM_DS5
                        __asm volatile
                        {
                            LDR reg6, [writePtr]
                            MVN reg7, reg6
                            SADD16 reg7, reg7, myConst
                            STR reg7, [writePtr], #4
                        }
#elif defined ARM_GCC
						asm volatile (
							"LDR r6, [%[writePtr]] \n\t"
							"MVN r7, r6 \n\t"
							"SADD16 r7, r7, %[myConst] \n\t"
							"STR r7, [%[writePtr]], #4 \n\t"
							: [writePtr]"+r"(writePtr)
							: [myConst]"r"(myConst) : "r6", "r7");
#endif
                	}
#else
					if (pktinfo->dcPhase == 0x3) { // case where we multiply by pi/2
						for (kk = 4 * subbandSize;kk < 5 * subbandSize;kk++) {
							tempI = writePtr[2 * kk];
							tempQ = writePtr[2 * kk + 1];
							writePtr[2 * kk] = tempQ;
							writePtr[2 * kk + 1] = -tempI;
						}
						for (kk = 5 * subbandSize;kk < 8 * subbandSize;kk++) {
							tempI = writePtr[2 * kk];
							tempQ = writePtr[2 * kk + 1];
							writePtr[2 * kk] = -tempQ;
							writePtr[2 * kk + 1] = tempI;
						}
					}
					else if (pktinfo->dcPhase == 0x1) { // case where we multiply by -pi/2
						for (kk = 4 * subbandSize;kk < 5 * subbandSize;kk++) {
							tempI = writePtr[2 * kk];
							tempQ = writePtr[2 * kk + 1];
							writePtr[2 * kk] = -tempQ;
							writePtr[2 * kk + 1] = tempI;
						}
						for (kk = 5 * subbandSize;kk < 8 * subbandSize;kk++) {
							tempI = writePtr[2 * kk];
							tempQ = writePtr[2 * kk + 1];
							writePtr[2 * kk] = tempQ;
							writePtr[2 * kk + 1] = -tempI;
						}
					}
					else { // no extra rotation
						for (kk = 4 * subbandSize;kk < 5 * subbandSize;kk++) {
							tempI = writePtr[2 * kk];
							tempQ = writePtr[2 * kk + 1];
							writePtr[2 * kk] = -tempI;
							writePtr[2 * kk + 1] = -tempQ;
						}
					}
#endif
				}
#endif
			}
			else if (pktinfo->packetType == 4) { // only HE160
				if (pktinfo->dcPhase == 0x3) { // case where we multiply by pi/2
					for (kk = 4 * subbandSize;kk < 8 * subbandSize;kk++) {
						tempI = writePtr[2 * kk];
						tempQ = writePtr[2 * kk + 1];
						writePtr[2 * kk] = -tempQ;
						writePtr[2 * kk + 1] = tempI;
					}
				}
				else if (pktinfo->dcPhase == 0x1) { // case where we multiply by -pi/2
					for (kk = 4 * subbandSize;kk < 8 * subbandSize;kk++) {
						tempI = writePtr[2 * kk];
						tempQ = writePtr[2 * kk + 1];
						writePtr[2 * kk] = tempQ;
						writePtr[2 * kk + 1] = -tempI;
					}
				}
			}
		}
	}

}

#endif // STA_20_ONLY

void calcPdpAndMaxRx(unsigned int *currentValPtr, unsigned int *pdpOutBuffer, int ifftSizeOsf, unsigned int* maxVals, int *maxIndeces){
#ifdef ARM_DS5
    int reg6;
#else
	short tempI, tempQ;
	unsigned int tempVal;
#endif
    int tt, maxIdx = -1;
    unsigned int currentSum, currentMax = 0;

    for(tt=0;tt<ifftSizeOsf;tt++){
#ifdef ARM_DS5
        __asm volatile
        {
            LDR reg6, [currentValPtr], #4
            MOV currentSum, #0
            SMLAD currentSum, reg6, reg6, currentSum
        }
#else
		tempVal = *currentValPtr++;
		tempI = tempVal&0xffff;
		tempQ = (tempVal>>16)&0xffff;
		tempVal = tempI*tempI;
		currentSum = tempVal;
		tempVal = tempQ*tempQ;
		currentSum += tempVal;
#endif
		pdpOutBuffer[tt]= currentSum;
		if(currentSum>currentMax){
			currentMax =currentSum;
			maxIdx = tt;
		}
	}
	*maxVals = currentMax;
	*maxIndeces = maxIdx;
}

void calcPdpAndMaxRxParallel(unsigned int *currentValPtr, unsigned int *pdpOutBuffer, int ifftSizeOsf, unsigned int* maxVals, int *maxIndeces) {
	short tempI, tempQ;
	unsigned int tempVal;
	int tt, pp, maxIdx[NUM_PARALLEL];
	unsigned int currentSum, currentMax[NUM_PARALLEL];

	for (pp = 0; pp < NUM_PARALLEL; pp++) {
		currentMax[pp] = 0;
		maxIdx[pp] = -1;
	}

	for (tt = 0;tt<ifftSizeOsf;tt++) {
		for (pp = 0; pp < NUM_PARALLEL; pp++) {
			tempVal = *currentValPtr++;
			tempI = tempVal & 0xffff;
			tempQ = (tempVal >> 16) & 0xffff;
			tempVal = tempI*tempI;
			currentSum = tempVal;
			tempVal = tempQ*tempQ;
			currentSum += tempVal;
			pdpOutBuffer[NUM_PARALLEL*tt+pp] = currentSum;
			if (currentSum > currentMax[pp]) {
				currentMax[pp] = currentSum;
				maxIdx[pp] = tt;
			}
		}
	}
	for (pp = 0; pp < NUM_PARALLEL; pp++) {
		maxVals[pp] = currentMax[pp];
		maxIndeces[pp] = maxIdx[pp];
	}
}

void calcPdpAndFirstPathMin(hal_pktinfo_t *pktinfo, unsigned int *fftOutBuffer, unsigned int *pdpOutBuffer, unsigned int *totalpower, int *idxRes, unsigned int *valRes, int *firstPathDelay){

	int ii, jj, pp, firstPathMin, maxIdx;
	unsigned short *tdScaling = (unsigned short*)totalpower;//[MAX_RX*MAX_TX];
	unsigned int *currentValPtr =fftOutBuffer;
	unsigned int tempVal, maxVals[MAX_RX*MAX_TX];
	int maxIndeces[MAX_RX*MAX_TX], firstPathRx[MAX_RX*MAX_TX];
	int nRx = pktinfo->nRx+1;
	int nTx = pktinfo->nTx+1;
	//int NgDsfShift = pktinfo->NgDsfShift;
	int numSubbands = 1<<pktinfo->sigBw;
	int ifftSizeOsf = 1<<(pktinfo->fftSize+6);
	int NgShift, subbandSize;
	if(pktinfo->packetType>2){ // Ng=1
		NgShift = 0;
	}
	else
	{
		NgShift = pktinfo->Ng+1;
	}
	subbandSize = 1<<(6-NgShift);

	// determine scaling
	for(ii=0;ii<nTx;ii++){
		for(jj=0;jj<nRx;jj++){
			//1.0f/(nRx*nTx*(aoaSysParam->fftSize/Ng)*powerH[jj+ii*nRx]);
			tempVal = totalpower[jj+ii*nRx];
			if(tempVal){
				tempVal *= nTx*nRx*(numSubbands*subbandSize);
				tempVal >>=(31-16-10);
				tdScaling[2*(jj+ii*nRx)] = (unsigned short)((ifftSizeOsf*ifftSizeOsf<<10)/tempVal); //(1<<31)
				tdScaling[2*(jj+ii*nRx)+1] = 0; // use 4 byte
			}
			else{
				tdScaling[jj+ii*nRx] =1;
			}
		}
	}

	for(ii=0;ii<nTx;ii++){
		for(jj=0;jj<nRx;jj+=NUM_PARALLEL){
			// calculate PDP for this Rx/Tx channel
#if defined(FFT_PARALLEL) && defined(ARM_DS5)
			calcPdpAndMaxRxIntrinsic(currentValPtr, pdpOutBuffer, ifftSizeOsf, maxVals + jj + ii*nRx, maxIndeces + jj + ii*nRx);
#else
			calcPdpAndMaxRxParallel(currentValPtr, pdpOutBuffer, ifftSizeOsf, maxVals + jj + ii*nRx, maxIndeces + jj + ii*nRx);
#endif
			currentValPtr += NUM_PARALLEL*ifftSizeOsf;

			// find first path
			for (pp = 0; pp < NUM_PARALLEL; pp++) {
				firstPathRx[pp + jj + ii*nRx] = findFirstPath(pktinfo, pdpOutBuffer + pp, maxIndeces[pp + jj + ii*nRx], maxVals[pp + jj + ii*nRx], NUM_PARALLEL);
			}
		}
	}

	// choose min as first path and average for max peak
	firstPathMin = (ifftSizeOsf<<TOA_FPATH_BIPT);
	maxIdx = 0; tempVal = 0;
	for(ii=0;ii<nTx;ii++){
		for(jj=0;jj<nRx;jj++){
			if(firstPathRx[jj+ii*nRx]<firstPathMin){
				firstPathMin = firstPathRx[jj+ii*nRx];
			}
			if(maxVals[jj+ii*nRx]>tempVal){
				tempVal = maxVals[jj+ii*nRx];
				maxIdx = jj+ii*nRx;
			}
		}
	}
	*idxRes = maxIndeces[maxIdx];
	*valRes = (tempVal*tdScaling[2*maxIdx])*nTx*nRx;
	*firstPathDelay = firstPathMin;
}


#if (MAX_RX>1) || (MAX_TX>1)
void calcPdpAndMax(hal_pktinfo_t *pktinfo, unsigned int *fftOutBuffer, unsigned int *pdpOutBuffer, unsigned int *totalpower, int *idxRes, unsigned int *valRes){

	int ii, jj, tt, maxIdx = -1;
	unsigned short *scalePtr, *tdScaling = (unsigned short*)totalpower;//[MAX_RX*MAX_TX];
	unsigned int *ldPtr, *currentValPtr =fftOutBuffer;
	unsigned int currentSum, tempVal, currentMax = 0;
	int nRx = pktinfo->nRx+1;
	int nTx = pktinfo->nTx+1;
	int numSubbands = 1<<pktinfo->sigBw;
	int ifftSizeOsf = 1<<(pktinfo->fftSize+6);
	int NgShift, subbandSize;
#if defined(ARM_DS5)
    int reg6, reg7, reg8;
#elif !defined(ARM_GCC)
	short tempI, tempQ;
    unsigned short scaleVal;
#endif

	if(pktinfo->packetType>2){ // Ng=1
		NgShift = 0;
	}
	else
	{
		NgShift = pktinfo->Ng+1;
	}
	subbandSize = 1<<(6-NgShift);

	// determine scaling
	for(ii=0;ii<nTx;ii++){
		for(jj=0;jj<nRx;jj++){
			//1.0f/(nRx*nTx*(aoaSysParam->fftSize/Ng)*powerH[jj+ii*nRx]);
			tempVal = totalpower[jj+ii*nRx];
			if(tempVal){
				tempVal *= nTx*nRx*(numSubbands*subbandSize);
				tempVal >>=(31-16-10);
				tdScaling[2*(jj+ii*nRx)] = (unsigned short)((ifftSizeOsf*ifftSizeOsf<<10)/tempVal); //(1<<31)
				tdScaling[2*(jj+ii*nRx)+1] = 0; // use 4 byte
			}
			else{
				tdScaling[jj+ii*nRx] =1;
			}
		}
	}

	for(tt=0;tt<ifftSizeOsf;tt++){
		currentSum = 0;
		ldPtr = currentValPtr;
		scalePtr = tdScaling;
		for(ii=0;ii<nTx;ii++){
			for(jj=0;jj<nRx;jj++){
#if defined(ARM_DS5)
                __asm volatile
                {
                    LDR reg6, [ldPtr], ifftSizeOsf, LSL #2
                    MOV reg7, #0
                    SMLAD reg7, reg6, reg6, reg7
                    LDRH reg8, [scalePtr], #4
                    MLA currentSum, reg7, reg8, currentSum
                }

#elif defined(ARM_GCC)
				asm volatile (
					"LDR r6, [%[ldPtr]], %[ifftSizeOsf] \n\t"
					"MOV r7, #0 \n\t"
					"SMLAD r7, r6, r6, r7 \n\t"
					"LDRH r8, [%[scalePtr]], #4 \n\t"
					"MLA %[currentSum], r7, r8, %[currentSum] \n\t"
					: [ldPtr]"+r"(ldPtr), [scalePtr]"+r"(scalePtr), [currentSum]"+r"(currentSum)
					: [ifftSizeOsf]"r"(4*ifftSizeOsf)
					: "r6", "r7", "r8");
#elif !(defined(ARM_DS5)||defined(ARM_GCC))
				tempVal = *ldPtr;
				ldPtr+=ifftSizeOsf;
				scaleVal = *scalePtr;
				scalePtr +=2;
				tempI = tempVal&0xffff;
				tempQ = (tempVal>>16)&0xffff;
				tempVal = tempI*tempI;
				currentSum += tempVal*scaleVal;
				tempVal = tempQ*tempQ;
				currentSum += tempVal*scaleVal;
#endif
			}
		}
		pdpOutBuffer[tt]= currentSum;
		currentValPtr++;

		if(currentSum>currentMax){
			currentMax =currentSum;
			maxIdx = tt;
		}
	}
	*idxRes = maxIdx;
	*valRes = currentMax;
}

void calcPdpAndMaxParallel(hal_pktinfo_t *pktinfo, unsigned int *fftOutBuffer, unsigned int *pdpOutBuffer, unsigned int *totalpower, int *idxRes, unsigned int *valRes) {

	int ii, jj, pp, tt, maxIdx = -1;
	unsigned short *scalePtr, *tdScaling = (unsigned short*)totalpower;//[MAX_RX*MAX_TX];
	unsigned int *ldPtr, *currentValPtr = fftOutBuffer;
	unsigned int currentSum, tempVal, currentMax = 0;
	int nRx = pktinfo->nRx + 1;
	int nTx = pktinfo->nTx + 1;
	int numSubbands = 1 << pktinfo->sigBw;
	int ifftSizeOsf = 1 << (pktinfo->fftSize + 6);
	int NgShift, subbandSize;
	short tempI, tempQ;
	unsigned short scaleVal;

	if (pktinfo->packetType>2) { // Ng=1
		NgShift = 0;
	}
	else
	{
		NgShift = pktinfo->Ng + 1;
	}
	subbandSize = 1 << (6 - NgShift);

	// determine scaling
	for (ii = 0;ii<nTx;ii++) {
		for (jj = 0;jj<nRx;jj++) {
			//1.0f/(nRx*nTx*(aoaSysParam->fftSize/Ng)*powerH[jj+ii*nRx]);
			tempVal = totalpower[jj + ii*nRx];
			if (tempVal) {
				tempVal *= nTx*nRx*(numSubbands*subbandSize);
				tempVal >>= (31 - 16 - 10);
				if(ifftSizeOsf>1024)
					tdScaling[2 * (jj + ii*nRx)] = (unsigned short)((ifftSizeOsf*ifftSizeOsf << 8) / (tempVal>>2)); //(1<<31)
				else
					tdScaling[2 * (jj + ii*nRx)] = (unsigned short)((ifftSizeOsf*ifftSizeOsf << 10) / tempVal ); //(1<<31)
				tdScaling[2 * (jj + ii*nRx) + 1] = 0; // use 4 byte
			}
			else {
				tdScaling[jj + ii*nRx] = 1;
			}
		}
	}

	for (tt = 0;tt<ifftSizeOsf;tt++) {
		currentSum = 0;
		ldPtr = currentValPtr;
		scalePtr = tdScaling;
		for (ii = 0;ii<nTx;ii++) {
			for (jj = 0;jj<nRx;jj+= NUM_PARALLEL) {
				for (pp = 0; pp < NUM_PARALLEL; pp++) {
					tempVal = *ldPtr;
					scaleVal = *scalePtr;
					tempI = tempVal & 0xffff;
					tempQ = (tempVal >> 16) & 0xffff;
					tempVal = tempI*tempI;
					currentSum += tempVal*scaleVal;
					tempVal = tempQ*tempQ;
					currentSum += tempVal*scaleVal;

					ldPtr++;
					scalePtr += 2;
				}
				ldPtr += NUM_PARALLEL*ifftSizeOsf-NUM_PARALLEL;
			}
		}
		pdpOutBuffer[tt] = currentSum;
		currentValPtr+= NUM_PARALLEL;

		if (currentSum>currentMax) {
			currentMax = currentSum;
			maxIdx = tt;
		}
	}
	*idxRes = maxIdx;
	*valRes = currentMax;
}

#else

void calcPdpAndMax(hal_pktinfo_t *pktinfo, unsigned int *fftOutBuffer, unsigned int *pdpOutBuffer, unsigned int *totalpower, int *idxRes, unsigned int *valRes){
	int tt, maxIdx = -1;
	unsigned short *tdScaling = (unsigned short*)totalpower;//[MAX_RX*MAX_TX];
	unsigned int *currentValPtr =fftOutBuffer;
	unsigned int currentSum, tempVal, currentMax = 0;
	//int nRx = pktinfo->nRx+1;
	//int nTx = pktinfo->nTx+1;
	int numSubbands = 1<<pktinfo->sigBw;
	int NgShift = pktinfo->Ng+1;
	int subbandSize = 1<<(6-NgShift);
	int ifftSizeOsf = 1<<(pktinfo->fftSize+6);
	short tempI, tempQ;
    unsigned short scaleVal;

	// determine scaling
	//1.0f/(nRx*nTx*(aoaSysParam->fftSize/Ng)*powerH[jj+ii*nRx]);
	tempVal = *totalpower;
	if(tempVal){
		tempVal *= numSubbands*subbandSize;
		tempVal >>=(31-16-10);
		tdScaling[0] = (unsigned short)((ifftSizeOsf*ifftSizeOsf<<10)/tempVal); //(1<<31)
		tdScaling[1] = 0; // use 4 byte
	}
	else{
		*tdScaling =1;
	}

	scaleVal = *tdScaling;
	for(tt=0;tt<ifftSizeOsf;tt++){
		tempVal = *currentValPtr;
		tempI = tempVal&0xffff;
		tempQ = (tempVal>>16)&0xffff;
		tempVal = tempI*tempI;
		currentSum = tempVal*scaleVal;
		tempVal = tempQ*tempQ;
		currentSum += tempVal*scaleVal;
		pdpOutBuffer[tt]= currentSum;
		currentValPtr++;

		if(currentSum>currentMax){
			currentMax =currentSum;
			maxIdx = tt;
		}
	}
	*idxRes = maxIdx;
	*valRes = currentMax;
}
#endif

int findFirstPath(hal_pktinfo_t *pktinfo, unsigned int *pdpOutBuffer, int maxIdx, unsigned int maxVal, int stride){

	int ii, firstLen, secondLen, mask;
	unsigned int y0, ym1, yp1, denominator, peakThresh, tempVal;
	int numerator, delta, interpDelay, firstPath;
	//unsigned short denomShort;
	unsigned int *readPtr;
	int NgDsfShift = pktinfo->NgDsfShift;
	int ifftSizeOsf = 1<<(pktinfo->fftSize+6);

	int totalLen, negLen, posLen;

	totalLen = ifftSizeOsf;
	totalLen /= (pktinfo->packetType>3)? (TD_FRAC_OF_FFT_HE >> NgDsfShift):(TD_FRAC_OF_FFT >> NgDsfShift);
	negLen = ifftSizeOsf / (FFT_ADV_FRAC >> NgDsfShift); //
	posLen = totalLen - negLen;

	peakThresh = maxVal>>PEAK_THRESH_SHIFT;
	if(peakThresh<PEAK_THRESH_MIN_ABS){
		peakThresh = PEAK_THRESH_MIN_ABS;
	}

	if(maxIdx>posLen){ // max in negative portion of PDP, no need to process positive part
		firstPath = maxIdx-ifftSizeOsf;
		firstLen = negLen+firstPath+2;
		secondLen = 0;
	}
	else{ // max in positive portion of PDP, start with negative part, positive next
		firstPath = maxIdx;
		firstLen = negLen;
		secondLen = firstPath;
	}

	// negative part
	readPtr = pdpOutBuffer+ stride*(ifftSizeOsf-negLen);
	ym1 = 0;
	y0 = maxVal;
	yp1 = readPtr[0];
	for(ii=1;ii<firstLen;ii++){ // find first path
		ym1 = y0;
		y0 = yp1;
		yp1 = readPtr[stride*ii];

		if((y0>ym1) && (y0>yp1)){ // local maximum
			if(y0>peakThresh){
				firstPath =ii-1-negLen;
				secondLen = 0; // no need for positive part
				break;
			}
		}
	}

	// positive part
	readPtr = pdpOutBuffer;
	for(ii=0;ii<secondLen;ii++){
		ym1 = y0;
		y0 = yp1;
		yp1 = readPtr[stride*ii];

		if((y0>ym1) && (y0>yp1)){ // local maximum
			if(y0>peakThresh){
				firstPath =ii-1;
				break;
			}
		}
	}

	// interpolate peak
	mask = ifftSizeOsf-1;
	// shift to avoid overflow
	ym1 = pdpOutBuffer[stride*((firstPath-1)&mask)]>>8;
	y0 = pdpOutBuffer[stride*(firstPath&mask)]>>8;
	yp1 = pdpOutBuffer[stride*((firstPath+1)&mask)]>>8;

	denominator = 2*(2*y0-yp1-ym1);
	numerator = (yp1-ym1);

	tempVal = (numerator>0)? numerator: (-numerator);
	ii = __clz(tempVal);
	if(ii>TOA_FPATH_BIPT){
		tempVal<<=TOA_FPATH_BIPT;
		delta = tempVal / denominator;
	}
	else{
		tempVal<<=(ii-1);
		delta = tempVal / (denominator>>(TOA_FPATH_BIPT-ii+1));
	}
	delta = (numerator>0)? delta:-delta;

	// format is 32.TOA_FPATH_BIPT
	//delta /=denomShort;
	//delta<<=TOA_FPATH_BIPT;
	//delta /= denominator;
	if((delta>(1<<(TOA_FPATH_BIPT-1))) || (-delta >(1<<(TOA_FPATH_BIPT-1)))){
		delta = 0; // overflow in division
	}
	interpDelay = (firstPath<<TOA_FPATH_BIPT) +delta;

	return interpDelay;
}


void dumpRawComplex(hal_pktinfo_t *pktinfo, unsigned int *fftBuffer, int peakIdx, unsigned int *destArray){

	int ii, jj, offset;
	int nRx = pktinfo->nRx+1;
	int nTx = pktinfo->nTx+1;
	int ifftSizeOsf = 1<<(pktinfo->fftSize+6);
	unsigned int *currentValPtr, tempVal;

	offset = (peakIdx+(1<<7))>>8; // round back
	if(offset<0){
		offset+=ifftSizeOsf;
	}
	currentValPtr = fftBuffer+offset;

	for(ii=0;ii<nTx;ii++){
		for(jj=0;jj<nRx;jj++){
			tempVal = currentValPtr[(jj+ii*nRx)*ifftSizeOsf];
			destArray[jj+ii*nRx] = tempVal;
		}
	}
}

#endif  /* CONFIG_WLS_CSI_PROC */
