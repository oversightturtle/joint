// DEFINE CORE MODES
#define MODE_AUX	// MODE SET TO AUX XOR GRBL
#define MODE_MASTER	// MODE SET TO ACTUAL XOR TEST XOR MASTER


// < -- JOINT LIBRARYS -- >

#include "Arduino.h"
#include "wait.h"
#include "com.h"
#include "conTLC.h"



#ifdef MODE_AUX

	#include "ServoClass/BipolarServo.h"
	#include "ServoClass/ServoMod.h"
	#include "ServoClass/StageServo.h"
	#include "Move/enum.h"
	#include "Move/sMove.h"
	#include "Move/MovSpeed.h"
	#include "Move/decMovSpeed.h"
	#include "decSERVO.h"
	#include "button.h"
	#include "ClusterClass/RoboCluster.h"
	#include "ClusterClass/PosCluster.h"
	#include "func.h" // inc vac
	#include "pospoint.h"
	#include "Operations/MoveTests.h"
	#include "Operations/PreOp.h"
	#include "Operations/Primary.h"
	#include "Operations/AltPrimary.h"
	#include "Operations/posfind.h"
	#include "LED/led.h"
	#include "LED/decLED.h"

#endif

#ifdef MODE_MASTER

int xpos;
int pin;
static int lastpin = 0;
int num1;
int num2;

#endif // MODE MASTER


// *** BEGIN THE SETUP

#ifdef MORE_GRBL

//#include "MarlinConfig.h"

// DISABLED FOR NOW

#endif

#ifdef MODE_AUX

	void setup()
	{

// *** JOINT DECLRATIONS
		init_pospoint(); // sync and declares position pins
		// safeloc(); <<< SETS ALL PINS TO SAFE MODE???
		tlc_initServos(); // init servo in the TLC library
	    conLED(); // sets all debug LED as outputs

// << END JOINT DEC

#ifdef MODE_ACTUAL
	pinMode(INCPIN_AUX , INPUT);
	pinMode(RECPIN_AUX, OUTPUT);
	pinMode(13, OUTPUT);
	digitalWrite(RECPIN_AUX, HIGH);
#endif

#ifdef MODE_TEST



#endif // MODE_TEST

#ifdef MODE_MASTER

Serial.begin(9600);
Serial.println();
Serial.println("< !!! --  ------- -- !!! >");
Serial.println("POSITIONSET 1.0.0");
Serial.print("min:");
Serial.print("SERVO_MIN_VALUE");
Serial.print(" >> max: ");
Serial.println("SERVO_MAX_VALUE");
Serial.println("inset >> pinnumber >> position >>");

#endif // MODE MASTER

	} // void setup

#endif // MODE_AUX


// *** BEGIN THE LOOPRZ



#ifdef MODE_GRBL


/*
sendorder(5);
sendorder(4);
sendorder(1);
sendorder(8);
sendorder(6);
sendorder(4);
sendorder(9);
sendorder(3);
*/

#endif

#ifdef MODE_AUX
void loop()
{
// read and exec order


	#ifdef MODE_ACTUAL

		int onum  = 0;

		onum = readorder();

		commit(onum);
	#endif

	#ifdef MODE_TEST

		tlc_directSetAllServo(250);
		wait(1000);
		tlc_directSetAllServo(350);
		wait(1000);

	#endif

	#ifdef MODE_MASTER

    while (Serial.available()>0)
    {
    	num1 = Serial.parseInt();
    	num2 = Serial.parseInt();

    	if(num2){ // TRUE if both pin1 and pin2 have values
    		pin = num1;
    		lastpin = pin;
    		xpos = num2;
    	} else if (!num2){ // TRUE if only pin 1 have a value
    		lastpin = pin;
    		xpos = num1;
    	}

      Serial.print(xpos);
      Serial.print(" ");
      Serial.println(pin);
      Serial.println(" >> RECIEVED AND MOVING");
      Serial.print("Enter position");
    }

    tlc_directSetServo(pin, xpos);
    Tlc.update();
    wait(100);
    

	#endif // MODE MASTER

} // void loop

#endif // MODE AUX


