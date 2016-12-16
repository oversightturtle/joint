/*
 * mov.h
 *
 *  Created on: Sep 21, 2016
 *      Author: oturt
 */
/*
#ifndef MOV_H_
#define MOV_H_

//#define wait delay

//#include "../wait.h"
//#include "../pospoint.h"

#ifndef SERVONULL
#define SERVONULL

ServoMod SUPERNULL(0, 0);

#endif

#include "../wait.h"
#include "../pospoint.h"
#include "../ServoClass/ServoMod.h"

void coremov(  int n,
   int s1, double fin1,
   int s2, double fin2,
   int s3, double fin3,
   int s4, double fin4,
   int s5, double fin5,
   int s6, double fin6)


//#define wait delay
// core move function that supports up to 6 simlatinous movements;
{
  // calcultaes how many servos are initilized
  // ************* ARRAY SERVOMOD?!??!?!?!?
  int movele = n;

  // master mov index given n servos to move

  const int st = 5;

  double initial[movele];
  double fin[movele];

  // set values with respect to size
  //n will be a deincrementer and deinc after each new initilization until n = 0


  if (n > 0) {initial[0] = *(pPos[s1]); fin[0] =fin1; n--;}
  if (n > 0) {initial[1] = *(pPos[s2]); fin[1] =fin2; n--;}
  if (n > 0) {initial[2] = *(pPos[s3]); fin[2] =fin3; n--;}
  if (n > 0) {initial[3] = *(pPos[s4]); fin[3] =fin4; n--;}
  if (n > 0) {initial[4] = *(pPos[s5]); fin[4] =fin5; n--;}
  if (n > 0) {initial[5] = *(pPos[s6]); fin[5] =fin6; n--;}
//   int dir[movele];
    bool dir[movele];
  for (int aaa = 0; aaa != movele; aaa++)
  {
    if (fin[aaa] - initial[aaa] > 0) { dir[aaa] = 1;}
//    else if ( fin[aaa] - initial[aaa] > 0 ) {dir[aaa] = -1;}
    else {dir[aaa] = 0;}
  } // sets initial  direction val: 1 -> step up; 0-> step down;

  bool halt = false;
      int goon = false;
      //    CHANGED BOOL DIR TO INT DIR AND BROKE IT FIX OR REVERT1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  while(halt == false)
  {
  goon = false;
    for (int aaa = 0; aaa !=movele; aaa++)
    {
      // checks and sets goon true if there is a servo that needs movin
      double v = fin[aaa] - initial[aaa];
      if (v > 0.05 && dir[aaa] == 1) {goon = true; break;}
      if (v < 0.05 && dir[aaa] == 0) {goon = true; break;}
    }
    if (goon == false) {halt = true;}
    else
    {
      // starts moving the servos
      for (int aaa = 0; aaa != movele; aaa++)
      {
        double v = fin[aaa] - initial[aaa];
//          std::cout << "aaa = " << aaa << " v = " << v << " ";
//          std::cout << "direction " << dir[aaa] << std::endl;
//mvoes and checks if servo is not
        //fully moved in the right position
        if ((v > 0.05 && dir[aaa] == 1)||(v < 0.05 && dir[aaa] == 0))
        {
          if (v > 0.05) {initial[aaa] += st;}
            else if (v < 0.05){initial[aaa] -= st;}


            // mov servo an inc pos
      //      s.writepos(initial[aaa]);
  //          std::cout << "moving " <<  aaa << " ";
          //  std::cout << aaa << " " << initial[aaa] << std::endl;
            switch(aaa){
            case 0: tlc_setServo(s1, initial[aaa]); *(pPos[s1]) = initial[aaa]; break;
            case 1: tlc_setServo(s2, initial[aaa]); *(pPos[s2]) = initial[aaa];break;
            case 2: tlc_setServo(s3, initial[aaa]); *(pPos[s3]) = initial[aaa];break;
            case 3: tlc_setServo(s4, initial[aaa]); *(pPos[s4]) = initial[aaa];break;
            case 4: tlc_setServo(s5, initial[aaa]); *(pPos[s5]) = initial[aaa];break;
            case 5: tlc_setServo(s6, initial[aaa]); *(pPos[s6]) = initial[aaa];break;
            }
            Tlc.update();
            wait(100);
            // and so on
        }
      }
    }
  }
  wait(1000);
}

void mov() {;}

// defines positions for servomod, fin ... entry

void mov(ServoMod s1,double p1) {coremov(1, s1.vPin() ,p1+1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
void mov(ServoMod s1,double p1, ServoMod s2, double p2)
	{coremov(2, s1.vPin(),p1 + 1, s2.vPin(),p2 + 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
void mov(ServoMod s1,double p1, ServoMod s2, double p2, ServoMod s3, double p3)
	{coremov(3, s1.vPin(),p1 + 1, s2.vPin(),p2 + 1, s3.vPin(),p3 + 1, NULL, NULL, NULL, NULL, NULL, NULL);}
void mov(ServoMod s1,double p1, ServoMod s2, double p2, ServoMod s3, double p3, ServoMod s4, double p4)
	{coremov(4, s1.vPin(),p1 + 1, s2.vPin(),p2 + 1, s3.vPin(),p3 + 1, s4.vPin(),p4 + 1, NULL, NULL, NULL, NULL);}
void mov(ServoMod s1,double p1, ServoMod s2, double p2, ServoMod s3, double p3, ServoMod s4, double p4, ServoMod s5, double p5)
	{coremov(5, s1.vPin(),p1 + 1, s2.vPin(),p2 + 1, s3.vPin(),p3 + 1, s4.vPin(),p4 + 1, s5.vPin(),p5 + 1, NULL, NULL);}
void mov(ServoMod s1,double p1, ServoMod s2, double p2, ServoMod s3, double p3, ServoMod s4, double p4,
  ServoMod s5, double p5, ServoMod s6, double p6)
	{coremov(6, s1.vPin(),p1+ 1, s2.vPin(), p2+ 1, s3.vPin(), p3+ 1, s4.vPin(), p4+ 1, s5.vPin(), p5+ 1, s6.vPin(), p6+ 1);}


//defines positions for pinval, fin ... entry

void mov(int s1,double p1) {coremov(1, s1 ,p1+1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
void mov(int s1,double p1, int s2, double p2)
	{coremov(2, s1,p1 + 1, s2,p2 + 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
void mov(int s1,double p1, int s2, double p2, int s3, double p3)
	{coremov(3, s1 ,p1 + 1, s2 ,p2 + 1, s3 ,p3 + 1, NULL, NULL, NULL, NULL, NULL, NULL);}
void mov(int s1,double p1, int s2, double p2, int s3, double p3, int s4, double p4)
	{coremov(4, s1 ,p1 + 1, s2,p2 + 1, s3,p3 + 1, s4,p4 + 1, NULL, NULL, NULL, NULL);}
void mov(int s1,double p1, int s2, double p2, int s3, double p3, int s4, double p4, int s5, double p5)
	{coremov(5, s1,p1 + 1, s2,p2 + 1, s3,p3 + 1, s4,p4 + 1, s5,p5 + 1, NULL, NULL);}
void mov(int s1,double p1, int s2, double p2, int s3, double p3, int s4, double p4,
  int s5, double p5, int s6, double p6)
	{coremov(6, s1,p1+ 1, s2, p2+ 1, s3, p3+ 1, s4, p4+ 1, s5, p5+ 1, s6, p6+ 1);}





#endif /* MOV_H_ */

