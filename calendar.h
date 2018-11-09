/*********************************************************//**
 * Filename: calendar.h
 * Author: Leo Kim
 * Date: 11/08/2018
 *
 * This file declares the Calendar class and its members.
 ************************************************************/

#ifndef CALENDAR_H
#define CALENDAR_H

#include <stdlib.h>
#include <vector>
#include <unistd.h>
#include "module.h"
#include "event.h"

class Calendar: public Module
{

	//Public members
	public:
		Calendar();	//Constructor
		~Calendar(); //Destructor
		virtual void tick();
		virtual void refresh();
		void printEvents();

	//Private members
	private:
		std::vector<Event*> events;

};

#endif
