/*********************************************************//**
 * Filename: event.cpp
 * Author: Leo Kim
 * Date: 11/08/2018
 *
 * This file defines the Event class and its members.
 ************************************************************/
#include "event.h"
using namespace std;

Event::Event(tm* startTime,tm* endTime, int dur, string title_str, string location_str ){
  start_time = startTime;
  end_time =  endTime;
  duration = dur;
  title = title_str;
  location = location_str;
}

Event::~Event(){
  delete start_time;
  delete end_time;
}

tm* Event:: getStart_time(){
  return start_time;
}

tm* Event:: getEnd_time(){
  return end_time;
}

int Event:: getDuration(){
  return duration;
}

string Event:: getTitle(){
  return title;
}

string Event:: getLocation(){
  return location;
}
