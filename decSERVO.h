/*
 * decPINS.h
 *
 *  Created on: Sep 21, 2016
 *      Author: oturt
 */

#ifndef DECSERVO_H_
#define DECSERVO_H_

//#include "ServoClass/StageServo.h"

#include "pospoint.h"
//#include "ServoClass/StageServo.h"

#define pin_safelight1 33
#define pin_safelight2 31

#define pin_s0_vac  47
#define pin_s0_safe 46

//>> SAFELOK



//CRITICAL DO NOT PUT ANYTHING ON PIN 2


// 102 ==>> 500 ms pulse ==>> 0 degrees

// 512 ==>> 2500 ms pulse ==>> 180 degrees

#define STAGE2VALUE 0

// BipolarServo ServoName(PINVAL, CLOSEVAL, SAFEvAL, OPEN); 
BipolarServo s2_big	(STAGE2VALUE, 102, 375, 493);
BipolarServo s2_clock	(STAGE2VALUE + 1, 102, 375, 490);
BipolarServo s2_place	(STAGE2VALUE + 2, 490, 239, 102);
BipolarServo s2_cclock	(STAGE2VALUE + 3, 490, 239, 102);

#define STAGE3VALUE 4
BipolarServo s3_upplace		(STAGE3VALUE, 102, 307, 512);
BipolarServo s3_fold1		(STAGE3VALUE + 1, 102, 421, 490);
BipolarServo s3_fold2		(STAGE3VALUE + 2, 490, 193, 125);

#define STAGE4VALUE 7
BipolarServo s4_roll	(STAGE4VALUE, 512, 284, 239);
//? counterroll???

#define STAGE5VALUE 8
BipolarServo S5_lift	(STAGE5VALUE, 0, 0, 0); // EDIT THIS <<<
//? hold???

#define STAGE6VALUE 9
BipolarServo s6_upplace		(41, 512, 307, 307);
BipolarServo s6_fold1		(STAGE6VALUE + 3, 102, 330, 375);
BipolarServo s6_fold2		(STAGE6VALUE + 2, 512, 284, 239);


//ServoMod testservo(2, 307);


#endif /* DECSERVO_H_ */
