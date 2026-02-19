#include <iostream>
#include <limits>

#include "../include/do_while_count_utils.h"

using std::cout, std::cin, std::endl;

namespace do_while_count_utils{
    void run_do_while_count(){
    	int num;

	do{
	    cout << "Enter a number between 1 and 5: ";
	    cin >> num;
	    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (num < 1 || num > 5);

	int array[5] = {1, 2, 3, 4, 5};

	for (int i : array){
	    cout << "Value: " << i << endl;
	    if (i == num){
	        break;
	    }
	}
    }
}
