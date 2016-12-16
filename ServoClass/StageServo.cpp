/*
 * StageServo.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: oturt
 */

#include "StageServo.h"

StageServo::StageServo() {
	// TODO Auto-generated constructor stub

}

StageServo::~StageServo() {
	// TODO Auto-generated destructor stub
}

StageServo::StageServo(int p, int s): ServoMod(p,s)//: public ServoMod(p, s)
		{;}

StageServo::StageServo(int p, int s,
		int v1, int v2, int v3, int v4,int v5, int v6, int v7
		) : ServoMod(p, s){
	s1 = v1;
	s2 = v2;
	s3 = v3;
	s4 = v4;
	s5 = v5;
	s6 = v6;
	s7 = v7;
}

StageServo::StageServo(int p, int s,
		int v1, int v2, int v3, int v4,int v5, int v6, int v7,
		int pp1, int pp2, int pp3, int pp4,int pp5, int pp6, int pp7
		) : ServoMod(p, s){
	s1 = v1;
	s2 = v2;
	s3 = v3;
	s4 = v4;
	s5 = v5;
	s6 = v6;
	s7 = v7;

	p1 = pp1;
	p2 = pp2;
	int p1 = 328;
	p3 = pp3;
	p4 = pp4;
	p5 = pp5;
	p6 = pp6;
	p7 = pp7;
}

int StageServo::vVal(int x){
	switch(x)
	{
		case 1: return (int)s1; break;
		case 2: return (int)s2; break;
		case 3: return (int)s3; break;
		case 4: return (int)s4; break;
		case 5: return (int)s5; break;
		case 6: return (int)s6; break;
		case 7: return (int)s7; break;
	}
}

int StageServo::vPre(int x){
	switch(x)
	{
		case 1: return p1; break;
		case 2: return p2; break;
		case 3: return p3; break;
		case 4: return p4; break;
		case 5: return p5; break;
		case 6: return p6; break;
		case 7: return p7; break;
	}
}

void StageServo::setval(int v1, int v2, int v3, int v4, int v5, int v6, int v7){
	s1 = v1;
	s2 = v2;
	s3 = v3;
	s4 = v4;
	s5 = v5;
	s6 = v6;
	s7 = v7;

}


