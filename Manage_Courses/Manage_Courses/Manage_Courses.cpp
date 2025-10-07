/*********************************************************************
* Name: Abhinab Chatterjee
* Project 1: Manage Courses
* Editor(s) used: Visual Studio
* Compiler(s) used: Windows
* Description:
* This program manages courses taken by a student.
**********************************************************************/



#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;


const int MAX_COURSES = 100;

// Declaring the function prototypes.
void displayMenu();
void listCourses(const int units[], const string titles[], int count);
void searchCourses(const int units[], const string titles[], int count, int minUnits);
bool readCatalog(const string& filename, int units[], string titles[], int& count);

/*********************************************************************
* Function: Main
**********************************************************************/
int main() {
    const string nameofFile = "catalog.txt";
    int units[MAX_COURSES];
    string titles[MAX_COURSES];
    int count = 0;

    if (!readCatalog(nameofFile, units, titles, count)) {
        cerr << "Error: Unable to open file '" << nameofFile << "'. Exiting program." << endl;
        return 1;
    }

    char option;
    bool running = true;

    cout << "Welcome to My Course Catalog Management System :)" << endl;

    while (running) {
        displayMenu();
        cout << "Enter your option: ";
        cin >> option;
        option = tolower(option);

        if (option == 'e') {
            running = false;
        }
        else if (option == 'l') {
            listCourses(units, titles, count);
        }
        else if (option == 'u') {
            int searchUnits;
            cout << "Enter your search unit: ";
            cin >> searchUnits;
            searchCourses(units, titles, count, searchUnits);
        }
        else {
            cout << "Invalid option. Try again." << endl;
        }
    }

    cout << "Thank you for using My Course Catalog Management System." << endl;
    return 0;
}

/*********************************************************************
* Function: Displays the menu options to the user.
*
* Parameters:
* NONE
* Return: NONE
**********************************************************************/
void displayMenu() {
    cout << "\nE End\t\tTerminate the program" << endl;
    cout << "L List\t\tShow all available courses in the catalog" << endl;
    cout << "U Search units>= number\tShow all courses in the catalog that have the number of units equal or greater than the given number" << endl;
}

/*********************************************************************
* Function: Lists all courses in the catalog.
*
* Parameters:
* units (IN): The array of course units
* titles (IN): The array of course titles
* count (IN): The number of courses in the catalog
* Return: NONE
**********************************************************************/
void listCourses(const int units[], const string titles[], int count) {
    cout << "\nCourses Catalog" << endl;
    cout << "Title\t\t\tUnit" << endl;
    for (int i = 0; i < count; ++i) {
        cout << titles[i] << "\t\t" << units[i] << endl;
    }
}

/*********************************************************************
* Function: Searches for courses with greater than or equal to units compared to
* the specified minimum units
*
* Parameters:
* units (IN): The array of course units
* titles (IN): The array of course titles
* count (IN): The number of courses in the catalog
* minUnits (IN): The minimum number of units to search for
* Return: NONE
**********************************************************************/
void searchCourses(const int units[], const string titles[], int count, int minUnits) {
    cout << "\nCourses matching your search:" << endl;
    cout << "Title\t\t\tUnit" << endl;
    for (int i = 0; i < count; ++i) {
        if (units[i] >= minUnits) {
            cout << titles[i] << "\t\t" << units[i] << endl;
        }
    }
}

/*********************************************************************
* Function: Reads the data from the course through a file and then inserts into the
* all_courses[] array
*
* Parameters:
* filename (IN): The name of the file containing course data
* units (OUT): The array to store course units
* titles (OUT): The array to store course titles
* count (IN): The number of courses read from the file
* Return: true if the file is correctly read, otherwise false
**********************************************************************/
bool readCatalog(const string& filename, int units[], string titles[], int& count) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    string line;
    while (getline(file, line) && count < MAX_COURSES) {
        istringstream iss(line);
        int unit;
        string title;

        if (iss >> unit) {
            getline(iss >> ws, title);
            units[count] = unit;
            titles[count] = title;
            count++;
        }
    }

    file.close();
    return true;
}