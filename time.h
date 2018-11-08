 /*********************************************************//**
  * Filename: time.h
  * Author: Gavin Lu
  * Date: 11/08/2018
  *
  * This file declares the Time class and its members.
  ************************************************************/
#ifndef TIME_H
#define TIME_H

#include <iostream>
#include "module.h"

class Time : public Module
{

	//Public members
	public:
		Time();	//Constructor
		~Time();
		tm *get_time();
		virtual void tick();
		virtual void refresh();
		inline std::ostream& operator<<(std::ostream& stream);

	//Private members
	private:
		tm *current_time;

};

#endif
