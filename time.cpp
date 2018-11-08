/*********************************************************//**
  * Filename: time.cpp
  * Author: Gavin Lu
  * Date: 11/08/2018
  *
  * This file defines the Time class and its members.
  ************************************************************/
#include "time.h"

using namespace std;

///Constructor of Time objects

/** Function Name: Time
 *  Description: Calls tick() to initialize the current_time data member.
 *  Parameter Descriptions: No parameters
 *  Return Description: Returns a pointer to the newly constructed Time object.
 */
Time::Time() : Module (){
	tick();
}

///Destructor of Time objects

/** Function Name: ~Time
 *  Description: Properly deconstructs Time objects by deleting current_time pointer.
 *  Parameter Descriptions: No parameters
 *  Return Description: No return
 */
Time::~Time() {
	delete current_time;
}

///Function that returns a pointer to tm struct of the current time.

/** Function Name: get_time
 *  Description: Returns current_time.
 *  Parameter Descriptions: No parameters
 *  Return Description: Returns a pointer to tm struct that contains the current time.
 */
tm *Time::get_time() {
	return current_time;
}

///Function that refreshes current time values.

/** Function Name: tick
 *  Description: Get the current time by getting time_t of the current time, then
 *		create a tm struct from it.
 *  Parameter Descriptions: No parameters
 *  Return Description: Returns a pointer to a tm struct that contains the current time.
 */
void Time::tick() {
	time_t t = time(0);
	current_time = localtime(&t);
}

///Method that displays the time on the screen when it refreshes.

/** Function Name: refresh
 *  Description: Displays the current time on the screen. Currently, it only prints to
 		the console. In the future, it will handle displaying to the web-app window.
 *  Parameter Descriptions: No parameters
 *  Return Description: No return
 */
void Time::refresh() {

	//Temporary refresh
	//Later change to display on web-app
	cout << "=======Time=======" << endl;
    cout << "Date: " 
    	<< (current_time->tm_year + 1900) << '-' 
        << (current_time->tm_mon + 1) << '-'
        <<  current_time->tm_mday
        << endl;
    
    cout << "Time: " 
    	<< (current_time->tm_hour) << "h:";
    if (current_time->tm_min < 10) cout << '0';
    cout << (current_time->tm_min) << "m:";
    if (current_time->tm_sec < 10) cout << '0';
    cout << (current_time->tm_sec) << "s" << endl;

}

///Function that overrides the << operator to pretty print time to the output stream.

/** Function Name: operator<<
 *  Description: Override the << operator to print the date and time to the output stream.
 *  Parameter Descriptions:
 *		stream - 
 *		&t - Pointer to the Time object to be printed
 *  Return Description: No return
 */
ostream& operator<<(ostream& stream, Time &t) { 

	tm *current_time = t.get_time();
	stream << "=======Time=======" << endl;

	//Print the date
    stream << "Date: " 
    	<< (current_time->tm_year + 1900) << '-' 
        << (current_time->tm_mon + 1) << '-'
        <<  current_time->tm_mday
        << endl;
    //Print the time
    stream << "Time: " 
    	<< (current_time->tm_hour) << "h:";
    if (current_time->tm_min < 10) stream << '0';
    stream << (current_time->tm_min) << "m:";
    if (current_time->tm_sec < 10) stream << '0';
    stream << (current_time->tm_sec) << "s" << endl;

}
