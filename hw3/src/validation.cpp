#include <string>
#include <cctype>

#include "../include/validation.h"

using std::string;

bool is_valid_password(string password){    
    bool upper = false;
    bool alnum = true;
    int length = password.length();
    for (char c : password){
        if (std::isupper(c)){
            upper = true;
        }
        if (!std::isalnum(c)){
            alnum = false;
        }
    }

    if (length < 8 || upper == false || alnum == true){
        return false;
    }

    return true;
}
