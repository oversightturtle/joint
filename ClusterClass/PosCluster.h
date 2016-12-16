/*
 * PosCluster.h
 *
 *  Created on: Sep 30, 2016
 *      Author: oturt
 */

#ifndef POSCLUSTER_H_
#define POSCLUSTER_H_

class PosCluster {
private:
	int a1 = 9090, a2 = 9090, a3 = 9090, a4 = 9090, a5 = 9090, a6 = 9090;
public:
	PosCluster();
	virtual ~PosCluster();
	PosCluster(int, int, int, int, int, int);
	PosCluster(int, int, int, int, int);
	int v1();
	int v2();
	int v3();
	int v4();
	int v5();
	int v6();
};

#endif /* POSCLUSTER_H_ */
