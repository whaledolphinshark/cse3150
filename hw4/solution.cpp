#include <iostream>
#include <string>
#include <limits>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes
void addStudent(char *name, double gpa, char *names[], double gpas[], int *size, int capacity);
void updateGPA(double *gpaPtr, double newGpa);
void printStudent(const char *name, const double& gpa);
double averageGPA(const double gpas[], int size);

// TODO: implement addStudent
void addStudent(char *name, double gpa, char *names[], double gpas[], int *size, int capacity){
    if (*size == capacity){
        std::cout << "List full" << std::endl;
        throw std::runtime_error("List full");
    }

    names[*size] = name;
    gpas[*size] = gpa;
    (*size)++;
}

// TODO: implement updateGPA
void updateGPA(double *gpaPtr, double newGpa){
    *gpaPtr = newGpa;
}

// TODO: implement printStudent
void printStudent(const char *name, const double& gpa){
   std::cout << name << " " << gpa << std::endl; 
}

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size){
    if (size == 0){
        std::cout << "No students" << std::endl;
        throw std::runtime_error("No students");
    }

    double average = 0;
    for (int i = 0; i < size; i++){
        average += gpas[i];
    }

    return average / size;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    // VLAs, not covered
    //char* names[capacity];
    //double gpas[capacity];
    int capacity = std::stoi(argv[1]);
    char** names = new char*[capacity];
    double* gpas = new double[capacity];
    int size = 0;
    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // TODO: implement menu logic
                std::string name_str;
                char *name = new char[100];
                double gpa;
                std::cin >> name_str;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> gpa;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::strcpy(name, name_str.c_str());
                try{
                    addStudent(name, gpa, names, gpas, &size, capacity);
                }
                catch (const char *msg){
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 2: {
                // TODO: implement menu logic
                int index;
                double new_gpa;
                std::cin >> index;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> new_gpa;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                updateGPA(gpas + index, new_gpa);
                break;
            }
            case 3: {
                // TODO: implement menu logic
                for (int i = 0; i < size; i++){
                    printStudent(names[i], gpas[i]);
                }
                break;
            }
            case 4: {
                // TODO: implement menu logic
                try{
                    std::cout << "Average GPA: " << static_cast<int>(averageGPA(gpas, size)) << std::endl;
                }
                catch (const char *msg){
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory
    for (int i =0 ; i < size; i++){
        delete[] names[i];
    }
    delete[] names;
    delete[] gpas;

    return 0;
}
