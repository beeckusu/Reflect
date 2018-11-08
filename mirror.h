 /*********************************************************//**
  * Filename: mirror.h
  * Author: Gavin Lu
  * Date: 11/08/2018
  *
  * This file defines the Mirror class and its members.
  * Many fields have been commented out to be implemented at
  * a later time.
  ************************************************************/
#ifndef MIRROR_H
#define MIRROR_H

#include <vector>
#include <unistd.h>
#include "module.h"
#include "time.h"
#include "calendar.h"
#include "weather.h"

//#define TICK_RATE 30
//#define REFRESH_RATE 30

class Mirror {

	public:
		Mirror(); //Constructor
		~Mirror();
		void tick();
		void refresh();

	private:
		std::vector<Module*> modules;
//		float tick_time = 1/TICK_RATE;
//		float refresh_time = 1/REFRESH_RATE;

//		float tick_count = 0;
//		float refresh_count = 0;

};

#endif
