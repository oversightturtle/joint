/*
 * RoboCluster.h
 *
 *  Created on: Sep 21, 2016
 *      Author: oturt
 */

#ifndef ROBOCLUSTER_H_
#define ROBOCLUSTER_H_

class RoboCluster {
protected:
	int pitch, yaw, roll, lift1, lift2, base;
public:
	RoboCluster();
	virtual ~RoboCluster();
	RoboCluster(int b, int l1, int l2, int p, int y, int r);
	RoboCluster(int, int, int, int, int);
//	RoboCluster(ServoMod, ServoMod, ServoMod, ServoMod, ServoMod, ServoMod);
//	void mov6(double vb, double vl1, double vl2, double vp, double vy, double vr);

	int v1();
	int v2();
	int v3();
	int v4();
	int v5();
	int v6();
};

#endif /* ROBOCLUSTER_H_ */


