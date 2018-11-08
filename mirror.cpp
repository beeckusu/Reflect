 /*********************************************************//**
  * Filename: mirror.cpp
  * Author: Gavin Lu
  * Date: 11/08/2018
  *
  * This file declares the Mirror class and its members.
  ************************************************************/
#include "mirror.h"

///Constructor of the Mirror object.

/** Function Name: Mirror Constructor
 *  Description: Pushes each module into the modules vector.
 *  Parameter Descriptions: No parameters
 *  Return Description: Returns a pointer to the Mirror object.
 */
Mirror::Mirror() {
	modules.push_back(new Time());
}

///Destructor of the Mirror object.

/** Function Name: operator<<
 *  Description: Override the << operator to print the date and time to the output stream.
 *  Parameter Descriptions:
 *		stream - 
 *		&t - Pointer to the Time object to be printed
 *  Return Description: No return
 */
Mirror::~Mirror() {
	while (modules.size() > 0) {
		Module *m = modules.back();
		modules.pop_back();
		delete m;
	}
}

///Function that overrides the << operator to pretty print time to the output stream.

/** Function Name: operator<<
 *  Description: Override the << operator to print the date and time to the output stream.
 *  Parameter Descriptions:
 *		stream - 
 *		&t - Pointer to the Time object to be printed
 *  Return Description: No return
 */
void Mirror::tick() {

	for (int i = 0; i < modules.size(); i++) {
		Module *m = modules.at(i);
		m->tick();
	}

}

///Function that overrides the << operator to pretty print time to the output stream.

/** Function Name: operator<<
 *  Description: Override the << operator to print the date and time to the output stream.
 *  Parameter Descriptions:
 *		stream - 
 *		&t - Pointer to the Time object to be printed
 *  Return Description: No return
 */
void Mirror::refresh() {

	for (int i = 0; i < modules.size(); i++) {
		Module *m = modules.at(i);
		m->refresh();
	}

}
