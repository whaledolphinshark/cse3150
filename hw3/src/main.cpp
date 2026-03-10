#include <iostream>
#include <string>
#include <limits>

#include "../include/validation.h"
#include "../include/audit_mode.h"

using std::cout, std::endl, std::string, std::cin, std::string;

int main(int argc, char* argv[]){
    if (argc == 3){
        process_file(argv[1], argv[2]);
        return 0;
    }
    
    string input;
    while (true){
        run_menu();
        cin >> input;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (stoi(input)){
            case 1:
            {
                string password;
                cout << "input password: ";
                std::getline(cin, password);
                cout << password << endl;
                if (is_valid_password(password)){
                    cout << endl << "Valid" << endl;
                }
                else{
                    cout << endl << "Invalid" << endl;
                }
                break;
            }
            case 2:
            {
                string input_file, output_file;
                cout << "input file:";
                cin >> input_file;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "output file:";
                cin >> output_file;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                process_file(input_file, output_file);
                break;
            }
            case 3:
                return 0;
        }
    }

    return 0;
}
