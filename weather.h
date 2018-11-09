 /*********************************************************//**
  * Filename: weather.h
  * Author: Adithya Sukumar
  * Date: 11/08/2018
  *
  * This file declares the Weather class and its members.
  ************************************************************/
#ifndef WEATHER_H
#define WEATHER_H
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include "module.h"



#include <curl/curl.h>
#include <json/json.h>

class Weather : public Module
{

	//Public members
	public:
		Weather();	//Constructor
		std::string get_temp();
		std::string get_desc();
		std::string get_humidity();
		virtual void tick();
		virtual void refresh();
		inline std::ostream& operator<<(std::ostream& stream) { 
		  stream << "=======Weather=======" << std::endl;
		  stream << "Temp: " << get_temp() << " degrees celcius" << std::endl;
		  stream << "Description: " << get_desc() << std::endl;
		  stream << "Humidity: " << get_humidity() << " percent" << std::endl;
		  stream << std::endl;
		};

	//Private members
	private:
		std::stringstream httpData;
		std::string tempString;
		std::string descString;
		std::string humidityString;

};

#endif
