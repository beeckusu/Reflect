// calendar.h

#ifndef CALENDAR_H
#define CALENDAR_H

#include "module.h"

class Calendar: public Module
{

	//Private members
	private:


	//Public members
	public:
		void tick();
		void refresh();

};

#endif
