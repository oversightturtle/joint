/*
 * Movetests.h
 *
 *  Created on: Sep 23, 2016
 *      Author: oturt
 */

#ifndef MOVETESTS_H_
#define MOVETESTS_H_

#include "../conTLC.h"
#include "../pospoint.h"

extern int order;
/*
void pulseall()
{
	for (int iii = 0; iii != NUM_TLCS * 16; iii++)
	{
		if ( pExist[iii] == 1){
			tlc_setServo(iii , pServo[iii]->vPulse());
		}
	}
	Tlc.update();
	wait(2000);
	for (int iii = 0; iii != NUM_TLCS * 16; iii++)
	{
		if ( pExist[iii] == 1){
			tlc_setServo(iii , pServo[iii]->vSafe());
		}
	}
	Tlc.update();
	wait(2000);
}
*/
/*
void pulseoneatatime()
{
	for (int iii = 0; iii != (order + 1); iii++)
	{
		tlc_directSetServo(pOrder[iii]->vPin() , pOrder[iii]->vBigPulse());
		Tlc.update();
		wait(500);
		tlc_directSetServo(pOrder[iii]->vPin() , pOrder[iii]->vSafe());
		Tlc.update();
		wait(500);
		debug1.invert();
		debug2.invert();
	}
	debug1.invert();
	debug2.invert();
	wait(200);
	debug1.invert();
	debug2.invert();
	wait(200);
	debug1.invert();
	debug2.invert();
	wait(200);
	debug1.invert();
	debug2.invert();
	wait(200);
	debug1.turn_off();
	debug2.turn_off();
}
*/
/*
void s4test(){
	sMove(FAST, s4_roll, s4_roll.vClose());
	wait(1000);
	sMove(FAST, s4_lift, s4_lift.vActive());
	wait(2000);
	sMove(FAST, s4_lift, s4_lift.vInactive());
	wait(2000);
	sMove(FAST, s4_roll, s4_roll.vOpen());
	wait(1000);
	sMove(FAST, s4_lift, s4_lift.vActive());
	wait(2000);
	sMove(FAST, s4_lift, s4_lift.vInactive());
	wait(2000);
}

void s0test(int d = 2000)
{
//	sMove(rs0, 70, 80, 100, 130, 100, 150);
	wait(2000);

//	sMove(rs0, 100, 80, 80, 50, 80, 30);
	wait(2000);
}

void s2test()
{
//	sMove(FAST, s2_place, 170);
	wait(1000);
//	sMove(FAST, s2_clock, 0);
	wait(1000);
//	sMove(FAST, s2_cclock, 170);
	wait(1000);
//	sMove(FAST, s2_big, 10);
	wait(1000);
//	sMove(FAST, s2_big, 170);
	wait(1000);
//	sMove(FAST, s2_clock, s2_clock.vSafe());
	wait(1000);
//	sMove(FAST, s2_cclock, s2_cclock.vSafe());
	wait(1000);
//	sMove(FAST, s2_place, s2_place.vSafe());
	wait(1000);
}

void s3test()
{
	sMove(FAST, s3_upplace, s3_upplace.vSafe() + 10, s3_downplace, s3_downplace.vClose());
	sMove(FAST, s3_fold1, s3_fold1.vSafe() - 10, s3_fold2, s3_fold2.vSafe() + 20);
	sMove(FAST, s3_fold1, s3_fold1.vSafe(), s3_fold2, s3_fold2.vSafe());
	sMove(FAST, s3_upplace, s3_upplace.vSafe(), s3_downplace, s3_downplace.vSafe());
}
*/


#endif /* sMoveETESTS_H_ */
