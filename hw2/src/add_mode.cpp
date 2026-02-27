#include <iostream>

#include "../include/add_mode.h"

namespace add_mode{
    void run(int argc, char* argv[]){
        if (argc < 4){
            return;
        }
        size_t npos = std::string::npos;
        std::string arg1 = argv[2];
        std::string arg2 = argv[3];
        std::string digits = "0123456789";
        if (arg1.find_first_not_of(digits) == npos && arg2.find_first_not_of(digits) == npos){
            std::cout << "Result: " << std::to_string(add(std::stoi(arg1), std::stoi(arg2))) << std::endl;
        }
        else if (arg1.find('.') != npos || arg2.find('.') != npos){
            std::cout << "Result: " << std::to_string(add(std::stod(arg1), std::stod(arg2))) << std::endl;
        }
        else{
            std::cout << "Result: " << add(arg1, arg2) << std::endl;
        }
    }

    int add(int a, int b){
        return a + b;
    }

    double add(double a, double b){
        return a + b;
    }

    std::string add(std::string a, std::string b){
        return a + b;
    }
}
