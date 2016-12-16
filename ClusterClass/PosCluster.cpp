/*
 * PosCluster.cpp
 *
 *  Created on: Sep 30, 2016
 *      Author: oturt
 */

#include "PosCluster.h"

PosCluster::PosCluster() {
	// TODO Auto-generated constructor stub

}

PosCluster::~PosCluster() {
	// TODO Auto-generated destructor stub
}

PosCluster::PosCluster(int x1 = 9090, int x2 = 9090, int x3 = 9090,
		int x4 = 9090, int x5 = 9090, int x6 = 9090){


	a1 = x1;
	a2 = x2;
	a3 = x3;
	a4 = x4;
	a5 = x5;
	a6 = x6;
}

PosCluster::PosCluster(int x1 = 9090, int x2 = 9090, int x3 = 9090,
		int x4 = 9090, int x5 = 9090){
	a1 = x1;
	a2 = x2;
	a3 = x3;
	a4 = x4;
	a5 = x5;
}

int PosCluster::v1(){
	return a1;
}

int PosCluster::v2(){
	return a2;
}

int PosCluster::v3(){
	return a3;
}

int PosCluster::v4(){
	return a5;
}

int PosCluster::v5(){
	return a5;
}

int PosCluster::v6(){
	return a6;
}

