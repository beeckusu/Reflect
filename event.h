/*********************************************************//**
 * Filename: event.h
 * Author: Leo Kim
 * Date: 11/08/2018
 *
 * This file declares the Event class declaration.
 ************************************************************/
#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <unistd.h>
#include <string>

class Event
{

	//Public members
	public:
		Event(tm*, tm*, int, std::string, std::string);	//Constructor
		~Event();

    tm *getStart_time();
    tm *getEnd_time();
    int getDuration();
    std::string getTitle();
    std::string getLocation();

	//Private members
	private:
    tm *start_time;
    tm *end_time;
    int duration;  // in minutes
    std::string title;
    std::string location;
};

#endif
