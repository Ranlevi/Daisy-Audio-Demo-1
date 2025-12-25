#include "daisy_seed.h" //High Level interface for the Daisy board for init/config.

/*
Demo Project 1
---------------
Author: Ran Levi
Version: 0.1

The goal is to experiment with as many Daisy Pod features as possible.
Version 0.1: Light LED_1 when pressing the SW1 button.
*/

using namespace daisy;
using namespace daisy::seed;

DaisySeed hw; //A class inside namespace daisy.

int main(void)
{
	hw.Init(); //Init the Daisy Seed.

	//An object for SW1 on the Pod.
	//SW1 is connected to GPIO D27.
	//When pressed - line is 0.
	GPIO sw1; 
	
	//An object for the LED_1 on the Pod.
	//LED_1 is connected to D20(R), D19(G), D18(B).
	//Drive to 0 to set ON.
	GPIO led1_R;
	GPIO led1_G;
	GPIO led1_B;

	//Configure with internal pull up.
	sw1.Init(D27, GPIO::Mode::INPUT, GPIO::Pull::PULLUP);

	led1_R.Init(D20, GPIO::Mode::OUTPUT);
	led1_G.Init(D19, GPIO::Mode::OUTPUT);
	led1_B.Init(D18, GPIO::Mode::OUTPUT);
	
	while(1) {
		bool sw1_state = sw1.Read();
		led1_R.Write(sw1_state);
		led1_G.Write(sw1_state);
		led1_B.Write(sw1_state);	
	}
}
