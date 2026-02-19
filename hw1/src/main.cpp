#include <iostream>
#include <limits>

#include "../include/integer_utils.h"
#include "../include/string_utils.h"
#include "../include/grade_utils.h"
#include "../include/while_count_utils.h"
#include "../include/do_while_count_utils.h"

using std::cout, std::endl, std::cin, std::string;

void display_menu(){
    cout << "1. Integer operations" << endl;
    cout << "2. Character arrays and C-style strings" << endl;
    cout << "3. Grade Evalution" << endl;
    cout << "4. While-loop counting" << endl;
    cout << "5. Do-while and range-based for counting" << endl;
    cout << "6. Quit" << endl;
}

int main(){
    int command;
    bool quit = false;
    while (!quit){
    	display_menu();
	cin >> command;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	switch (command){
	    case 1:
		integer_utils::run_integer_option();
		break;
	    case 2:
		if (string_utils::run_string_option() == 0){
		    return 1;
		}
		break;
	    case 3:
		if (grade_utils::calculate_grade() < 0){
		    return 1;
		}
		break;
	    case 4:
		while_count_utils::run_while_count();
		break;
	    case 5:
		do_while_count_utils::run_do_while_count();
		break;
	    case 6:
                cout << "Goodbye!" << endl;
		quit = true;
		break;
	}
    }
    return 0;
}
