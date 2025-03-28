
#include <iostream>
#include <fstream>
using namespace std;
// Add this at the top
//MIsael Nunez
// TODO: Step 1 - Define the struct TemperatureRecord
// It should contain two integer fields: day and temperature.
//oo
struct TemperatureRecord {
    int day;
    int temperature;
};
// Constants
const int MAX_DAYS = 31;
//
// Function Prototypes
void readTemperatures(TemperatureRecord records[], int& size); // TODO: Fix the parameters
void printTemperatures(const TemperatureRecord records [], int size);
//TemperatureRecord findMin(const ? ? ? );
//TemperatureRecord findMax(const ? ? ? );
double findAverage(const TemperatureRecord records[], int size);

int main() {
   
    // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)
    TemperatureRecord records[MAX_DAYS];
    int size = 0;  // Actual number of records read

    // TODO: Step 3 - Call readTemperatures() to load data from file
    readTemperatures(records, size);
    // TODO: Step 4 - Print the temperatures
    cout << "Temperature Records:" << endl;
    cout << "Day   Temp" << endl;
    printTemperatures(records, size);
    //-----
    // TODO: Step 5 - Compute and display min, max, and average temperature
    double average = findAverage(records, size);
    cout << "Average Temperature: " << average << endl;

    return 0;
}

// TODO: Step 6 - Implement readTemperatures()
// Read from "temps.txt" and store data in the array
void readTemperatures(TemperatureRecord records[], int& size) {
    ifstream inFile("temps.txt");

    if (!inFile) {
        cout << "Error opening file." << endl;
        return;
    }
    int day;
    int temp;
    size = 0;

    while (inFile >> day >> temp && size < MAX_DAYS) {
        records[size].day = day;
        records[size].temperature = temp;
        size++;
    }
    inFile.close();

}
// TODO: Step 7 - Implement printTemperatures()
// Print all stored temperatures in a formatted table
void printTemperatures(const TemperatureRecord records[], int size) {

    for (int i = 0; i < size; ++i) {
        cout << records[i].day << "   " << records[i].temperature << endl;
    }
}

// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature

// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature

// TODO: Step 10 - Implement findAverage()
// Compute and return the average temperature
double findAverage(const TemperatureRecord records[], int size) {
    if (size == 0) {
        return 0.0;

    }
    int total = 0;
    for (int i = 0; i < size; ++i) {
         total += records[i].temperature;
     }
     return static_cast<double>(total) / size;
}
