#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "../include/audit_mode.h"
#include "../include/validation.h"

using std::string;

void process_file(string input, string output){
    char input_delimiter = '\t';
    char output_delimiter = '\t';
    if (input.find(".csv") != std::string::npos){
        input_delimiter = ',';
    }
    if (output.find(".csv") != std::string::npos){
        output_delimiter = ',';
    }
    
    string line, username, email, password;
    std::ifstream input_file(input);
    if (!input_file.is_open()){
        std::cout << "Error opening file" << std::endl;
        input_file.close();
        return;
    }
    std::ofstream output_file(output, std::ios::app);
    if (!output_file.is_open()){
        std::cout << "Error opening file" << std::endl;
        output_file.close();
        return;
    }

    while (std::getline(input_file, line)){
        std::istringstream line_stream(line);
        std::getline(line_stream, username, input_delimiter);
        std::getline(line_stream, email, input_delimiter);
        std::getline(line_stream, password);
        if(!is_valid_password(password)){
            output_file << username + output_delimiter + email + output_delimiter + password + '\n';
        }
    }
    input_file.close();
    output_file.close();
}

void run_menu(){
    std::cout << "1. Check a single password" << std::endl;
    std::cout << "2. Process a TSV/CSV file" << std::endl;
    std::cout << "3. Quit" << std::endl;
}
