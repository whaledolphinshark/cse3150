#include <iostream>
#include <limits>

#include "../include/string_utils.h"

using std::cout, std::endl, std::cin, std::getline, std::string;

namespace string_utils{
    int run_string_option(){
        int length;
	cout << "Enter string length: ";
	cin >> length;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (length >= 20){
	    cout << "Error: string length greater than or equal to 20" << endl;
	    return 0;
	}
	
	string str;
	cout << "Enter string: ";
	getline(cin, str);

	char c_style_string[20];
	for (int i = 0; i < length; i++){
	    c_style_string[i] = str[i];
	}
	c_style_string[length] = '\0';
	std::cout << "C-style string: " << c_style_string << endl;
	return 1;
    }
}
