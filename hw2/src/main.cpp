#include <iostream>
#include <string>

#include "add_mode.h"
#include "text_mode.h"
#include "stats_mode.h"
using std::cout, std::endl, std::string;

int main(int argc, char* argv[]){
    if (argc < 2){
    	cout << "Usage: ./analyzer <mode> [arguments]" << endl;
	return 1;
    }
    
    int mode = -1;
    string mode_string = argv[1];
    if (mode_string == "text"){
        mode = 1;
    }
    else if (mode_string == "add"){
        mode = 2;
    }
    else if (mode_string == "stats"){
        mode = 3;
    }

    switch (mode){
    	case 1:
            text_mode::run(argc, argv);
	        break;
	    case 2:
            add_mode::run(argc, argv);
	        break;
    	case 3:
            stats_mode::run(argc, argv);
	        break;
	    default:
	        cout << "Invalid mode" << endl;
	        return 1;
    }
    return 0;
}
