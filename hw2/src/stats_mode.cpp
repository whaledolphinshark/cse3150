#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <algorithm>

#include "../include/stats_mode.h"

namespace stats_mode{
    void run(int argc, char* argv[]){
        if (argc < 3){
            return;
        }
        std::string arg1 = argv[2];
        std::cout << "Length " << arg1.length() << std::endl;
        std::set<char> unique_chars(arg1.begin(), arg1.end());
        size_t num_unique = unique_chars.size();
        std::cout << "Unique " << num_unique << std::endl;
        bool alnum_only = true;
        for (char c : arg1){
            if (!std::isalnum(c)){
                alnum_only = false;
                break;
            }
        }
        if (alnum_only){
            std::cout << "Alphanumeric Yes" << std::endl;
        }
        else{
            std::cout << "Alphanumeric No" << std::endl;
        }
        std::string rstr = "";
        for (int i = arg1.length() - 1; i >= 0; i--){
            rstr += arg1[i];
        }
        //std::reverse(arg1.begin(), arg1.end());
        std::cout << "Reversed " << rstr << std::endl;
        size_t fp = arg1.find(' ');
        if (fp == std::string::npos){
            std::cout << "withoutspaces" << arg1 << std::endl;
        }
        else{
            arg1.erase(std::remove(arg1.begin(), arg1.end(), ' '), arg1.end());
            std::cout << "Without spaces " << arg1 << std::endl;
        }
        size_t length = arg1.length();
        bool palindrome = true;
        for (int i = 0; i < length / 2; i++){
            if (std::tolower(arg1[i]) != std::tolower(arg1[length - 1 - i])){
                palindrome = false;
                break;
            }
        }
        if (palindrome){
            std::cout << "Palindrome Yes" << std::endl;
        }
        else{
            std::cout << "Palindrome No" << std::endl;
        }
    }
}
