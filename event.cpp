/*********************************************************//**
 * Filename: event.cpp
 * Author: Leo Kim
 * Date: 11/08/2018
 *
 * This file defines the Event class and its members.
 ************************************************************/

#include "event.h"
using namespace std;

//Constructor for Event class

/** Function Name: Event
 *  Description: Properly constructs Event object.
 *  Parameter Descriptions: startTime is when the event starts,
      endTime is when the event ends, title_str is the event title and
      location_str is the location event.
 *  Return Description: returns an Event obj
 */
Event::Event(tm* startTime,tm* endTime, string title_str, string location_str ){
  start_time = startTime;
  end_time =  endTime;
  title = title_str;
  location = location_str;
}

//Destructor for Event class
Event::~Event(){
  delete start_time;
  delete end_time;
}

//Function that gets start_time attribute from Event obj

/** Function Name: getStart_time
 *  Description: returns private member start_time
 *  Parameter Descriptions: No parameters
 *  Return Description: time pointer
 */
tm* Event:: getStart_time(){
  return start_time;
}

//Function that gets end_time attribute from Event obj

/** Function Name: getEnd_time
 *  Description: returns private member end_time
 *  Parameter Descriptions: No parameters
 *  Return Description: time pointer
 */
tm* Event:: getEnd_time(){
  return end_time;
}

//Function that gets title attribute from Event obj

/** Function Name: getTitle
 *  Description: returns private member title
 *  Parameter Descriptions: No parameters
 *  Return Description: string
 */
string Event:: getTitle(){
  return title;
}

/** Function Name: getLocation
 *  Description: returns private member location
 *  Parameter Descriptions: No parameters
 *  Return Description: string
 */
string Event:: getLocation(){
  return location;
}
