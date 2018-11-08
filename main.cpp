 /*********************************************************//**
  * Filename: main.cpp
  * Author: Gavin Lu
  * Date: 11/08/2018
  *
  * This file is the main program that will be executed that
  * maintains the SmartMirror software.
  ************************************************************/
#include "mirror.h"
using namespace std;

///The main loop of the software.

/** Function Name: main
 *  Description: The main function of the software. It contains a loop
 *		that is responsible for calling the tick() and refresh() methods.
 *  Parameter Descriptions: No parameters
 *  Return Description: Returns the status.
 */
int main() {

	Mirror m; //Instantiates the Mirror object that will in turn initialize the modules
	int count = 0; //Debugging variable that will keep track of how many seconds the program has been running

	/** Loop Algorithm:
	  * 1) Increment time
	  * 2) Check if enough time has passed to update data values
	  * 3) If there is, run tick().
	  * 4) Check if enough time has passed to refresh the screen
	  * 5) If there is, run refresh().
	  */
	while(count < 60) { //Normally this loop runs endlessly until the user exits, but for now, it will run for up to a minute.

		//Increment time
		count++;
		//Implement later: Check for tick time
		m.tick();
		//Implement later: Check for refresh time
		m.refresh();

		sleep(1); //Debugging step that simulates time passing
	}

}
