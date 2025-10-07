/*********************************************************************
* Name: Abhinab Chatterjee
* Project 1: Manage Courses
* Editor(s) used: Visual Studio
* Compiler(s) used: Windows
* Description:
* This program calculates the upper end, lower end, and average of scores inputted by the user.
**********************************************************************/


#include <iostream>
using namespace std;


/*********************************************************************
* Function: Calculates statistics for given scores
*
* Parameters:
* scores (IN): The array of scores
* scoreSize (IN): The # of scores in the array
* maxScore (OUT): Reference to store the max score
* minScore (OUT): Reference to store the min score
*
* Return: The average score
**********************************************************************/
double scoreStats(double scores[], int size, double& max, double& min) {
    double sum = 0;
    max = scores[0];
    min = scores[0];

    for (int i = 0; i < size; i++) {
        sum += scores[i];

        if (scores[i] > max) {
            max = scores[i];
        }
        if (scores[i] < min) {
            min = scores[i];
        }
    }

    return sum / size;
}


/*********************************************************************
* Function: Main
**********************************************************************/
int main() {
    const int SIZE = 5;
    double scores[SIZE];

    cout << "Enter 5 scores:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Score " << (i + 1) << ": ";
        cin >> scores[i];
    }

    double max, min;
    double average = scoreStats(scores, SIZE, max, min);

    cout << "\nStatistics:" << endl;
    cout << "Average score: " << average << endl;
    cout << "Maximum score: " << max << endl;
    cout << "Minimum score: " << min << endl;

    return 0;
}