// calendar.cpp

#include <fstream>
#include <string>
#include "json.hpp"
#include "calendar.h"

using json = nlohmann::json;
using namespace std;


Calendar::Calendar() : Module (){
	system("./pystuff/pyscript.sh");
	ifstream json_file;
	json json_data;

	// A loop that waits until calendar data is available
	while(true){
		json_file.open("./pystuff/caldata.json");
	    if(json_file.is_open()){
				break;
	    }
	}

	// calendar data is now available - write to json object for parsing
	json_file >> json_data;
	json_file.close();


	//Parse JSON and create event object for each event
	//using canned data for the time being
	for (json::iterator it = json_data["items"].begin(); it != json_data["items"].end(); ++it) {
		json j = it.value();
		// tm* start_time;
		// tm* end_time;
		// string title = j["summary"];
		// string location = "";
		// cout << typeid(j["end"]["dateTime"]).name() << endl;
		time_t t = time(0);
		events.push_back(new Event(localtime(&t),localtime(&t),"event1","Mary's house"));
	}

}

///Destructor of Calendar objects

/** Function Name: ~Calendar
 *  Description: Properly deconstructs Calendar object.
 *  Parameter Descriptions: No parameters
 *  Return Description: No return
 */
Calendar::~Calendar() {
}

void Calendar :: tick(){

}

void Calendar :: refresh(){

}

void Calendar :: printEvents(){
	for (int i = 0;  i < events.size(); i++){
		Event *e = events.at(i);
		cout << e->getStart_time() << endl;
		cout << e->getEnd_time() << endl;
		cout << e->getTitle() << endl;
		cout << e->getLocation() << endl;
	}
}

void Calendar :: getEvents(){

}
