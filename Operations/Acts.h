/*
 * General.h
 *
 *  Created on: Sep 30, 2016
 *      Author: oturt
 */

#ifndef ACTS_H_
#define ACTS_H_

#include "../Acts/act1.h"
#include "../Acts/act2.h"
#include "../Acts/act3.h"
#include "../Acts/act4.h"
#include "../Acts/act5.h"
#include "../Acts/act6.h"
#include "../Acts/act7.h"
#include "../Acts/act8.h"
#include "../Acts/act9.h"
#include "../Acts/act10.h"
#include "../Acts/act11.h"


void commit(int counter){
	switch (counter){
							// takes from stage1 and hovers over s2
	case 1: act1(); break;	// open stage 2
							// drops paper on s2
	case 2: act2(); break;	// folds s2 and unfolds
							// picks up s2 and moves over s3
							// drops over s3
	case 3: act3(); break;	// folds s3
							// pick up move to s4 to flip
	case 4: act4(); break;	// flips s4
							// pick up move to over s3
	case 5: act5(); break;	// folds s3 (other side)
							// moves to s5
	case 6: act6(); break;	// locks in s5{ attempts to expose s5} and flips s5
							// move to flipstation s4
	case 7: act7(); break;	// flip
							// moves back to s5 to expose other side
							//move to s6
	case 8: act8(); break;	// fold s6
							// move to flip at s4
	case 9: act9(); break;	// flips s4
							// moves to s6
	case 10: act10(); break;	// flips s6
	case 11: act11(); break;	// drops it at the end
	}
}




#endif /* ACTS_H_ */
