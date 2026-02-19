#include <iostream>
#include <limits>

#include "../include/integer_utils.h"

using std::cout, std::endl, std::cin;

namespace integer_utils{
    void run_integer_option(){
	int num1, num2;
    	cout << "Enter first integer: ";
	cin >> num1;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
	cout << "Enter second integer: ";
	cin >> num2;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
	if (num2 == 0){
	    cout << "Error: division by zero" << endl;
	    return;
	}

	cout << "Result: " << (double)num1 / num2 << endl;
	// post increments then pre increments?
	cout << "After post-increment: " << num1++ << endl;
	cout << "After pre-increment: " << ++num1 << endl;
	return;
    }
}
