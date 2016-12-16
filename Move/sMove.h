/*
 * mov_eq.h
 *
 *  Created on: Sep 21, 2016
 *      Author: oturt
 */

#ifndef MOV_EQ_H_
#define MOV_EQ_H_



#include "../wait.h"
#include "../pospoint.h"
#include "../ServoClass/ServoMod.h"
#include "../ClusterClass/RoboCluster.h"
#include "decMovSpeed.h"
#include "../ClusterClass/PosCluster.h"

void sMove_core(MovSpeed, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
void sMove(MovSpeed, RoboCluster, int, int, int, int, int, int);
void sMove(RoboCluster, int, int, int, int, int, int);
void sMove(RoboCluster, int);
void sMove(MovSpeed, RoboCluster, int);
void sMove(RoboCluster, PosCluster);
void sMove(MovSpeed, RoboCluster, PosCluster);
//void sMove(MovSpeed, RoboCluster, int, int, int, int, int);
//void sMove(RoboCluster, int, int, int, int, int);
int fp(int);
int fp(ServoMod);
int convert(int, int);
int convert(ServoMod, int);
int convert(StageServo, int);
int convert(BipolarServo, int);



void sMove_core(MovSpeed x, int n,
   int s1 = 0, int fin1 = 0,
   int s2 = 0, int fin2 = 0,
   int s3 = 0, int fin3 = 0,
   int s4 = 0, int fin4 = 0,
   int s5 = 0, int fin5 = 0,
   int s6 = 0, int fin6 = 0,
   int s7 = 0, int fin7 = 0,
   int s8 = 0, int fin8 = 0,
   int s9 = 0, int fin9 = 0)

// core move function that supports up to 9 simlatinous movements;
{
  // calcultaes how many servos are initilized
  // ************* ARRAY SERVOMOD?!??!?!?!?
  int movele = n;

  int steps = x.vN();
  int sd = x.vD();
  int fd = x.vF();

  // master mov index given n servos to move


  double st[movele];

  double initial[movele];
  int fin[movele];

  // set values with respect to size
  //n will be a deincrementer and deinc after each new initilization until n = 0
  if (n > 0) {initial[0] = *(pPos[s1]); fin[0] =fin1; n--;}
  if (n > 0) {initial[1] = *(pPos[s2]); fin[1] =fin2; n--;}
  if (n > 0) {initial[2] = *(pPos[s3]); fin[2] =fin3; n--;}
  if (n > 0) {initial[3] = *(pPos[s4]); fin[3] =fin4; n--;}
  if (n > 0) {initial[4] = *(pPos[s5]); fin[4] =fin5; n--;}
  if (n > 0) {initial[5] = *(pPos[s6]); fin[5] =fin6; n--;}
  if (n > 0) {initial[6] = *(pPos[s7]); fin[6] =fin7; n--;}
  if (n > 0) {initial[7] = *(pPos[s8]); fin[7] =fin8; n--;}
  if (n > 0) {initial[8] = *(pPos[s9]); fin[8] =fin9; n--;}

  // TODO: CHECK BOUND AND SAFEVAL

  // functino cluster below checks if the servos are already in position;
  /*
  bool cont = false;
  for(int aaa = 0; aaa != movele; aaa++)
  {
	  if(initial[aaa] != fin[aaa]) { cont = true;}
  }
  if (!cont){ break;}
  */

  //belows calc the size of each step
  for(int aaa = 0; aaa != movele; aaa++)
  {
    st[aaa] = (fin[aaa] - initial[aaa]) / steps;
  }
// ****************be sure to defing step arg.
  for (int bbb = 0; bbb != steps; bbb++)
  {
    // incerments the initialpositions
    for(int ccc = 0; ccc != movele; ccc++) {initial[ccc] += st[ccc];}

    // moves the servos evnlt; halts when out of steps
    if (movele >= 1) {tlc_directSetServo(s1, initial[0]); *(pPos[s1]) = initial[0];}
    if (movele >= 2) {tlc_directSetServo(s2, initial[1]); *(pPos[s2]) = initial[1];}
    if (movele >= 3) {tlc_directSetServo(s3, initial[2]); *(pPos[s3]) = initial[2];}
    if (movele >= 4) {tlc_directSetServo(s4, initial[3]); *(pPos[s4]) = initial[3];}
    if (movele >= 5) {tlc_directSetServo(s5, initial[4]); *(pPos[s5]) = initial[4];}
    if (movele >= 6) {tlc_directSetServo(s6, initial[5]); *(pPos[s6]) = initial[5];}
    if (movele >= 7) {tlc_directSetServo(s7, initial[6]); *(pPos[s7]) = initial[6];}
    if (movele >= 8) {tlc_directSetServo(s8, initial[7]); *(pPos[s8]) = initial[7];}
    if (movele >= 9) {tlc_directSetServo(s9, initial[9]); *(pPos[s9]) = initial[8];}
    	Tlc.update();
                wait(sd);
  }
  for(int ddd = 0; ddd != n; ddd++)
  {
	  //*(pPos[]) = initial[0] *************************** CONFIRM WRITE IFNAL POSIION
	  // TODO: ARRAY THE SERVOPINVALS
  }

  wait(fd);

}

void sMove(RoboCluster r, int n){
	if (n == SAFE){
		if (pServo[r.v6()]->vSafe() == 9090){
			sMove(r, pServo[r.v1()]->vSafe(), pServo[r.v2()]->vSafe(), pServo[r.v3()]->vSafe(),
					pServo[r.v4()]->vSafe(), pServo[r.v5()]->vSafe(), 9090);
		} else {
			sMove(r, pServo[r.v1()]->vSafe(), pServo[r.v2()]->vSafe(), pServo[r.v3()]->vSafe(),
					pServo[r.v4()]->vSafe(), pServo[r.v5()]->vSafe(), pServo[r.v6()]->vSafe());
		}
	}
}
void sMove(MovSpeed m, RoboCluster r, int n){
	if (n == SAFE){
		if (pServo[r.v6()]->vSafe() == 9090){
			sMove(m, r, pServo[r.v1()]->vSafe(), pServo[r.v2()]->vSafe(), pServo[r.v3()]->vSafe(),
					pServo[r.v4()]->vSafe(), pServo[r.v5()]->vSafe(), 9090);
		} else {
			sMove(m, r, pServo[r.v1()]->vSafe(), pServo[r.v2()]->vSafe(), pServo[r.v3()]->vSafe(),
					pServo[r.v4()]->vSafe(), pServo[r.v5()]->vSafe(), pServo[r.v6()]->vSafe());
		}
	}
}

void sMove(RoboCluster r, PosCluster p){
	sMove(r, p.v1(), p.v2(), p.v3(), p.v4(), p.v5(), p.v6());
}
void sMove(MovSpeed m, RoboCluster r, PosCluster p){
	sMove(m, r, p.v1(), p.v2(), p.v3(), p.v4(), p.v5(), p.v6());
}

void sMove(MovSpeed x, RoboCluster r, int p1, int p2, int p3, int p4, int p5, int p6 = 9090)
	{ if (p6 == 9090) {
		sMove_core(x, 5, r.v1(), convert(r.v1(), p1), r.v2(), convert(r.v2(), p2), r.v3(), convert(r.v3(), p3),
				r.v4(), convert(r.v4(), p4), r.v5(), convert(r.v5(), p5));
		} else {
		sMove_core(x, 6, r.v1(), convert(r.v1(), p1), r.v2(), convert(r.v2(), p2), r.v3(), convert(r.v3(), p3),
				r.v4(), convert(r.v4(), p4), r.v5(), convert(r.v5(), p5),r.v6(), convert(r.v6(), p6)); // **************************************88
		}
	}

void sMove(RoboCluster r, int p1, int p2, int p3, int p4, int p5, int p6 = 9090)
	{ if (p6 == 9090) {
		sMove_core(NORMAL, 5, r.v1(), convert(r.v1(), p1), r.v2(), convert(r.v2(), p2), r.v3(), convert(r.v3(), p3),
					r.v4(), convert(r.v4(), p4), r.v5(), convert(r.v5(), p5));
		} else {
			sMove_core(NORMAL, 6, r.v1(), convert(r.v1(), p1), r.v2(), convert(r.v2(), p2), r.v3(), convert(r.v3(), p3),
					r.v4(), convert(r.v4(), p4), r.v5(), convert(r.v5(), p5),r.v6(), convert(r.v6(), p6)); // **************************************88
		}
	}

/*
void sMove(MovSpeed x, RoboCluster r, int p1, int p2, int p3, int p4, int p5)
	{coremov_eq(x, 5, r.v1(), convert(r.v1(), p1), r.v2(), convert(r.v2(), p2), r.v3(), convert(r.v3(), p3),
			r.v4(), convert(r.v4(), p4), r.v5(), convert(r.v5(), p5));} // **************************************88

void sMove(RoboCluster r, int p1, int p2, int p3, int p4, int p5)
	{coremov_eq(NORMAL, 5, r.v1(), convert(r.v1(), p1), r.v2(), convert(r.v2(), p2), r.v3(), convert(r.v3(), p3),
			r.v4(), convert(r.v4(), p4), r.v5(), convert(r.v5(), p5));}
*/
// finds the pins of SMod classes, returns pinval if input pinval

int fp(int x) {return x;}
int fp(ServoMod x) { return x.vPin();}

int convert(int pin, int def)
{
	switch(def)
	{
	case SAFE: return pServo[pin]->vSafe();
	default: return def;
	}
}

int convert(StageServo s, int def)
{
	switch(def)
	{
	case SAFE: return s.vSafe(); break;
	case OPEN: return s.vOpen(); break;
	case CLOSE: return s.vClose(); break;
	case ACTIVE: return s.vActive(); break;
	case INACTIVE: return s.vInactive(); break;
	case STAGE1: return s.vVal(1); break;
	case STAGE2: return s.vVal(2); break;
	case STAGE3: return s.vVal(3); break;
	case STAGE4: return s.vVal(4); break;
	case STAGE5: return s.vVal(5); break;
	case STAGE6: return s.vVal(6); break;
	case STAGE7: return s.vVal(7); break;
	case PRESTAGE1: return s.vPre(1); break;
	case PRESTAGE2: return s.vPre(2); break;
	case PRESTAGE3: return s.vPre(3); break;
	case PRESTAGE4: return s.vPre(4); break;
	case PRESTAGE5: return s.vPre(5); break;
	case PRESTAGE6: return s.vPre(6); break;
	case PRESTAGE7: return s.vPre(7); break;

	default: return def; break;
	}
}

int convert(ServoMod s, int def)
{
	switch(def)
	{
	case SAFE: return s.vSafe(); break;
	default: return def; break;
	}
}

int convert(BipolarServo s, int def)
{
	switch(def)
	{
	case SAFE: return s.vSafe(); break;
	case OPEN: return s.vOpen(); break;
	case CLOSE: return s.vClose(); break;
	case ACTIVE: return s.vActive(); break;
	case INACTIVE: return s.vInactive(); break;
	default: return def; break;
	}
}


// simplified move (mov(servo, SAFE) instead of mov(servo, servo.vSafe());
// if no movespeed is defined it wil return and assume normal
template<class S>
void sMove(S s1, int v1)
	{sMove_core(NORMAL, 1, fp(s1), convert(s1, v1));}
template<class S>
void sMove(S s1, int v1, S s2, int v2)
	{sMove_core(NORMAL, 2, fp(s1), convert(s1, v1), fp(s2), convert(s2, v2));}
template<class S>
void sMove(S s1, int v1, S s2, int v2, S s3, int v3)
	{sMove_core(NORMAL, 3, fp(s1), convert(s1, v1), fp(s2), convert(s2, v2), fp(s3), convert(s3, v3));}
template<class S>
void sMove(S s1, int v1, S s2, int v2, S s3, int v3, S s4, int v4)
	{sMove_core(NORMAL, 4, fp(s1), convert(s1, v1), fp(s2), convert(s2, v2), fp(s3), convert(s3, v3), fp(s4), convert(s4, v4));}
template<class S>
void sMove(S s1, int v1, S s2, int v2, S s3, int v3, S s4, int v4, S s5, int v5)
	{sMove_core(NORMAL, 5, fp(s1), convert(s1, v1), fp(s2), convert(s2, v2), fp(s3), convert(s3, v3), fp(s4), convert(s4, v4),
			fp(s5), convert(s5, v5));}
template<class S>
void sMove(S s1, int v1, S s2, int v2, S s3, int v3, S s4, int v4, S s5, int v5, S s6, int v6)
	{sMove_core(NORMAL, 6, fp(s1), convert(s1, v1), fp(s2), convert(s2, v2), fp(s3), convert(s3, v3), fp(s4), convert(s4, v4),
		fp(s5), convert(s5, v5), fp(s6), convert(s6, v6));}
template<class S>
void sMove(S s1, int v1, S s2, int v2, S s3, int v3, S s4, int v4, S s5, int v5, S s6, int v6, S s7, int v7)
	{sMove_core(NORMAL, 7, fp(s1), convert(s1, v1), fp(s2), convert(s2, v2), fp(s3), convert(s3, v3), fp(s4), convert(s4, v4),
		fp(s5), convert(s5, v5), fp(s6), convert(s6, v6), fp(s7), convert(s7, v7));}
template<class S>
void sMove(S s1, int v1, S s2, int v2, S s3, int v3, S s4, int v4, S s5, int v5, S s6, int v6, S s7, int v7, S s8, int v8)
	{sMove_core(NORMAL, 8, fp(s1), convert(s1, v1), fp(s2), convert(s2, v2), fp(s3), convert(s3, v3), fp(s4), convert(s4, v4),
		fp(s5), convert(s5, v5), fp(s6), convert(s6, v6), fp(s7), convert(s7, v7), fp(s8), convert(s8, v8));}
template<class S>
void sMove(S s1, int v1, S s2, int v2, S s3, int v3, S s4, int v4, S s5, int v5, S s6, int v6, S s7, int v7, S s8, int v8, S s9, int v9)
	{sMove_core(NORMAL, 9, fp(s1), convert(s1, v1), fp(s2), convert(s2, v2), fp(s3), convert(s3, v3), fp(s4), convert(s4, v4),
		fp(s5), convert(s5, v5), fp(s6), convert(s6, v6), fp(s7), convert(s7, v7), fp(s8), convert(s8, v8), fp(s9), convert(s9, v9));}

template<class S>
void sMove(MovSpeed x, S s1, int v1)
	{sMove_core(x, 1, fp(s1), convert(s1, v1));}
template<class S>
void sMove(MovSpeed x, S s1, int v1, S s2, int v2)
	{sMove_core(x, 2, fp(s1), convert(s1, v1), fp(s2), convert(s2, v2));}
template<class S>
void sMove(MovSpeed x, S s1, int v1, S s2, int v2, S s3, int v3)
	{sMove_core(x, 3, fp(s1), convert(s1, v1), fp(s2), convert(s2, v2), fp(s3), convert(s3, v3));}
template<class S>
void sMove(MovSpeed x, S s1, int v1, S s2, int v2, S s3, int v3, S s4, int v4)
	{sMove_core(x, 4, fp(s1), convert(s1, v1), fp(s2), convert(s2, v2), fp(s3), convert(s3, v3), fp(s4), convert(s4, v4));}
template<class S>
void sMove(MovSpeed x, S s1, int v1, S s2, int v2, S s3, int v3, S s4, int v4, S s5, int v5)
	{sMove_core(x, 5, fp(s1), convert(s1, v1), fp(s2), convert(s2, v2), fp(s3), convert(s3, v3), fp(s4), convert(s4, v4),
			fp(s5), convert(s5, v5));}
template<class S>
void sMove(MovSpeed x, S s1, int v1, S s2, int v2, S s3, int v3, S s4, int v4, S s5, int v5, S s6, int v6)
	{sMove_core(x, 6, fp(s1), convert(s1, v1), fp(s2), convert(s2, v2), fp(s3), convert(s3, v3), fp(s4), convert(s4, v4),
		fp(s5), convert(s5, v5), fp(s6), convert(s6, v6));}
template<class S>
void sMove(MovSpeed x, S s1, int v1, S s2, int v2, S s3, int v3, S s4, int v4, S s5, int v5, S s6, int v6, S s7, int v7)
	{sMove_core(x, 7, fp(s1), convert(s1, v1), fp(s2), convert(s2, v2), fp(s3), convert(s3, v3), fp(s4), convert(s4, v4),
		fp(s5), convert(s5, v5), fp(s6), convert(s6, v6), fp(s7), convert(s7, v7));}
template<class S>
void sMove(MovSpeed x, S s1, int v1, S s2, int v2, S s3, int v3, S s4, int v4, S s5, int v5, S s6, int v6, S s7, int v7, S s8, int v8)
	{sMove_core(x, 8, fp(s1), convert(s1, v1), fp(s2), convert(s2, v2), fp(s3), convert(s3, v3), fp(s4), convert(s4, v4),
		fp(s5), convert(s5, v5), fp(s6), convert(s6, v6), fp(s7), convert(s7, v7), fp(s8), convert(s8, v8));}
template<class S>
void sMove(MovSpeed x, S s1, int v1, S s2, int v2, S s3, int v3, S s4, int v4, S s5, int v5, S s6, int v6, S s7, int v7, S s8, int v8, S s9, int v9)
	{sMove_core(x, 9, fp(s1), convert(s1, v1), fp(s2), convert(s2, v2), fp(s3), convert(s3, v3), fp(s4), convert(s4, v4),
		fp(s5), convert(s5, v5), fp(s6), convert(s6, v6), fp(s7), convert(s7, v7), fp(s8), convert(s8, v8), fp(s9), convert(s9, v9));}


#endif /* MOV_EQ_H_ */

