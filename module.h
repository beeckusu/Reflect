// module.h
#ifndef MODULE_H
#define MODULE_H

#include <string>

class Module
{

	//Private members

	//Public members
	public:
		std::string name;
		virtual void tick();
		virtual void refresh();

};

#endif
