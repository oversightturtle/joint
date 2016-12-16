/*
 * button.h
 *
 *  Created on: Sep 21, 2016
 *      Author: oturt
 */

#ifndef BUTTON_H_
#define BUTTON_H_



bool buttonState = HIGH;
bool lastButtonState = HIGH;

int waittime = 100;

void update_button()
{
	if (digitalRead(pin_s0_safe) == HIGH) {wait(waittime); if (digitalRead(pin_s0_safe) == HIGH){wait(waittime); if (digitalRead(pin_s0_safe) == HIGH){buttonState = HIGH;}}}
	else if (digitalRead(pin_s0_safe) == LOW) {wait(waittime); if (digitalRead(pin_s0_safe) == LOW){wait(waittime); if (digitalRead(pin_s0_safe) == LOW){buttonState = LOW;}}}
}

void inc_button()
{
	lastButtonState = buttonState;
}
#endif /* BUTTON_H_ */
