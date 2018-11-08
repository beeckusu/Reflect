// calendar.cpp

#include <fstream>
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

	json_file >> json_data;
	json_file.close();
	cout << json_data.dump(4) << endl;

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
