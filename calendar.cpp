// calendar.cpp
#include "calendar.h"
#include <stdlib.h>

Calendar::Calendar() : Module (){
}

///Destructor of Time objects

/** Function Name: ~Calendar
 *  Description: Properly deconstructs Calendar object.
 *  Parameter Descriptions: No parameters
 *  Return Description: No return
 */
Calendar::~Calendar() {
}

void Calendar :: tick(){

}

void Calendar :: refresh(){
	system("./pystuff/pyscript.sh");
}
