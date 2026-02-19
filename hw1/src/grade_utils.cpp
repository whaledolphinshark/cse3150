#include <iostream>
#include <limits>

#include "../include/grade_utils.h"

using std::cout, std::cin, std::string, std::endl;

namespace grade_utils{
    double calculate_grade(){
	char type;
    	cout << "Enter student type (U for undergrad, G for grad): ";
	cin >> type;
	if (type == 'u'){
	    type = 'U';
	}
	else if (type == 'g'){
	    type = 'G';
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	double grade;
	cout << "Enter numeric grade: ";
	cin >> grade;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	if (grade < 0 || grade > 100){
	    cout << "Invalid grade" << endl;
	    return -1;
	}

	if ((type == 'U' && grade >= 60) || (type == 'G' && grade >= 70)){
	    cout << "Status: Pass" << endl;
	}
	else{
	    cout << "Status: Fail" << endl;
	}

	return grade;
    }
}
