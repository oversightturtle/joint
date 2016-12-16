/*
 * RoboCluster.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: oturt
 */

#include "RoboCluster.h"
//#include "mov_eq.h"


RoboCluster::RoboCluster() {
	// TODO Auto-generated constructor stub

}

RoboCluster::~RoboCluster() {
	// TODO Auto-generated destructor stub
}

RoboCluster::RoboCluster(int b, int l1, int l2, int p, int y, int r)
{
	base = b;
	lift1 = l1;
	lift2 = l2;
	pitch = p;
	yaw = y;
	roll = r;
}

RoboCluster::RoboCluster(int b, int l1, int l2, int p, int y)
{
	base = b;
	lift1 = l1;
	lift2 = l2;
	pitch = p;
	yaw = y;
}

int RoboCluster::v1() { return base;}
int RoboCluster::v2() { return lift1;}
int RoboCluster::v3() { return lift2;}
int RoboCluster::v4() { return pitch;}
int RoboCluster::v5() { return yaw;}
int RoboCluster::v6() { return roll;}
//void RoboCluster::mov6(double vb, double vl1, double vl2, double vp, double vy, double vr)
//{
//	mov_eq(base, vb, lift1, vl1, lift2, vl2, pitch, vp, yaw, vy, roll, vr);
//}


