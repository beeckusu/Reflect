// module.h
#ifndef MODULE_H
#define MODULE_H

#include <string>

class Module
{

	//Private members

	//Public members
	public:
		virtual ~Module();
		virtual void tick();
		virtual void refresh();

};

#endif