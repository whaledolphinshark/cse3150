#include <iostream>
#include <string>
#include <cctype>

#include "../include/text_mode.h"

using std::cout, std::endl;

namespace text_mode{
    void run(int argc, char* argv[]){
        if (argc < 3){
            return;
        }
	    std::string str = argv[2];
	    cout << "Original " << argv[2] << endl;
	    size_t length = str.size();
	    cout << "Length " << length << endl;
	    int letters, digits, spaces, punctuation;
        letters = digits = spaces = punctuation = 0;
        std::string copy = "";
        for (size_t i = 0; i < length; i++){
            char c = str[i];
            if (std::isalpha(c)){
                letters++;
            }
            if (std::isdigit(c)){
                digits++;
            }
            if (std::isspace(c)){
                spaces++;
            }
            if (std::ispunct(c)){
                punctuation++;
            }
            str[i] = std::tolower(c);
	    }
        cout << "Letters " << letters << endl;
        cout << "Digits " << digits << endl;
        cout << "Spaces " << spaces << endl;
        cout << "Punctuation " << punctuation << endl;
        for (char c : str){
            copy += std::toupper(c);
        }
        cout << "Uppercase " << copy << endl;
        cout << "Lowercase " << str << endl;
    
        size_t pos = str.find("test");
        if (pos == std::string::npos){
            cout << "containstestno" << endl;
        }
        else{
            cout << "containstestyes" << endl;
        }
        size_t space_pos = str.find(' ');
        std::string substring = "";
        if (space_pos != std::string::npos){
            substring = str.substr(0, space_pos);
            cout << "First word " << substring << endl;
        }
        //else{
          //  cout << "firstword" << endl;
        //}
    }
}
