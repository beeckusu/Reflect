/*********************************************************//**
  * Filename: weather.cpp
  * Author: Adithya Sukumar
  * Date: 11/08/2018
  *
  * This file defines the Weather class and its members.
  ************************************************************/
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>

#include <curl/curl.h>
#include <json/json.h>

#include "weather.h"

namespace
{
    std::size_t callback(
            const char* in,
            std::size_t size,
            std::size_t num,
            char* out)
    {
        std::string data(in, (std::size_t) size * num);
        *((std::stringstream*) out) << data;
        return size * num;        
    }
}

/** Function Name: Weather
 *  Description: Calls tick() to initialize the httpData data member.
 *  Parameter Descriptions: No parameters
 *  Return Description: Returns a pointer to the newly constructed Weather object.
 */
Weather::Weather() : Module (){
	tick();
}

/** Function Name: get_temp
 *  Description: Returns temp.
 *  Parameter Descriptions: No parameters
 *  Return Description: Returns a pointer to the temperature.
 */
std::string Weather::get_temp() {
	return tempString;
}

/** Function Name: get_desc
 *  Description: Returns description.
 *  Parameter Descriptions: No parameters
 *  Return Description: Returns a pointer to a description of the weather.
 */
std::string Weather::get_desc() {
  return descString;
}

/** Function Name: get_humidity
 *  Description: Returns humidity.
 *  Parameter Descriptions: No parameters
 *  Return Description: Returns a pointer to the humidity.
 */
std::string Weather::get_humidity() {
  return humidityString;
}

/** Function Name: tick
 *  Description: Get the current weather by assigning values for weather
 *  Parameter Descriptions: No parameters
 *  Return Description: Void
 */
void Weather::tick() {
  
  std::string url("http://api.openweathermap.org/data/2.5/weather?q=London,ca&appid=ce9456a43b22ab732979cd430de6d200");
  
  CURL* curl = curl_easy_init();
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &httpData);
  int httpCode(0);
  curl_easy_perform(curl);
  curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
  curl_easy_cleanup(curl);

  if (httpCode == 200)
  {

    Json::Value jsonData;
    Json::CharReaderBuilder jsonReader;
    std::string errors;

    if (Json::parseFromStream(jsonReader, httpData, &jsonData, &errors))
    {
      Json::Value tempObject(jsonData["main"]["temp"]);
      Json::Value descObject(jsonData["weather"][0]["description"]);
      Json::Value humidityObject(jsonData["main"]["humidity"]);

      tempString = (std::to_string(tempObject.asDouble()-273.15));
      descString = (descObject.asString());
      humidityString = (humidityObject.asString());
    }
  }
}

///Method that displays the time on the screen when it refreshes.

/** Function Name: refresh
 *  Description: Displays the current weather on the screen. Currently, it only prints to
 		the console. In the future, it will handle displaying to the web-app window.
 *  Parameter Descriptions: No parameters
 *  Return Description: No return
 */
void Weather::refresh() {
  std::cout << "=======Weather=======" << std::endl;
  std::cout << "Temp: " << get_temp() << " degrees celcius" << std::endl;
  std::cout << "Description: " << get_desc() << std::endl;
  std::cout << "Humidity: " << get_humidity() << " percent" << std::endl;
  std::cout << std::endl;
}
