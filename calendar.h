// calendar.h

#ifndef CALENDAR_H
#define CALENDAR_H

class Calendar: public Module
{

	//Private members
	private:
		util::Status Authorize();

	//Public members
	public:
		void tick();
		void refresh();
		static util::Status Startup(int arc, char* argv[]);

};

#endif
