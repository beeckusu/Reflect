// calendar.h

#ifndef CALENDAR_H
#define CALENDAR_H

#include "module.h"

class Calendar: public Module
{

	//Public members
	public:
		Calendar();	//Constructor
		~Calendar();
		void tick();
		void refresh();

	//Private members
	private:


};

#endif
