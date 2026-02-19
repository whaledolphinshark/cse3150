#include <iostream>
#include <limits>

#include "../include/while_count_utils.h"

using std::cout, std::cin, std::endl;

namespace while_count_utils{
    void run_while_count(){
        int num;
	cout << "Enter a number to count to: ";
	cin >> num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (num > 10){
	    cout << "I'm programmed to only count up to 10!" << endl;
	    cout << "Enter a number to count to: ";
	    cin >> num;
	    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << endl;
	int i = 1;
	while (i <= num){
	    if (i != 5){
	    	cout << i << endl;
	    }
	    i++;
	}
    }
}
