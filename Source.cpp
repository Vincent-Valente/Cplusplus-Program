#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// Define a class called ItemTracker
class ItemTracker {
public:
    // Read data from file and store frequency of items in a map
    void readDataFile();
    // Display a menu with options to search for an item, print the frequency list, or print a histogram
    void displayMenu();
private:
    // Map to store frequency of each item
    map<string, int> itemFreq;
    // Search for an item in the map and print its frequency
    void searchItem();
    // Print the frequency of each item in the map
    void printFreqList();
    // Print a histogram of the frequency of each item in the map
    void printHistogram();
};

// Read data from file and store frequency of items in a map
void ItemTracker::readDataFile() {
    // Open input file
    ifstream dataFile("CS210_Project_Three_Input_File.txt");
    // Read each item from the file and update its frequency in the map
    string item;
    while (dataFile >> item) {
        itemFreq[item]++;
    }
    // Close the file
    dataFile.close();
    // Open the output file for writing
    ofstream outFile("frequency.dat");
    if (outFile.is_open()) {
        // write the frequency list to the output file
        for (auto const& item : itemFreq) {
            outFile << item.first << " " << item.second << endl;
        }
        outFile.close();
    }
    else {
        cout << "Error: Unable to open output file." << endl;
    }
}

// Display a menu with options to search for an item, print the frequency list, or print a histogram
void ItemTracker::displayMenu() {
    int choice;
    do {
        // Print menu options
        cout << "\nMenu\n";
        cout << "1. Search for an item\n";
        cout << "2. Print the frequency list\n";
        cout << "3. Print a histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        // Read user's choice
        cin >> choice;
        // Perform action based on user's choice
        switch (choice) {
        case 1:
            searchItem();
            break;
        case 2:
            printFreqList();
            break;
        case 3:
            printHistogram();
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}

// Search for an item in the map and print its frequency
void ItemTracker::searchItem() {
    string item;
    cout << "Enter the item to search for: ";
    cin >> item;
    if (itemFreq.find(item) == itemFreq.end()) {
        cout << item << " not found. Note: searches are case sensitive.\n";
    }
    else {
        cout << "Frequency of " << item << " = " << itemFreq[item] << endl;
    }
}

// Print the frequency of each item in the map
void ItemTracker::printFreqList() {
    cout << "Frequency list:\n";
    for (auto const& item : itemFreq) {
        cout << item.first << " " << item.second << endl;
    }

}

// Print a histogram of the frequency of each item in the map
void ItemTracker::printHistogram() {
    cout << "Histogram:\n";
    for (auto const& item : itemFreq) {
        cout << item.first << " ";
        // Print a number of asterisks equal to the item's frequency
        for (int i = 0; i < item.second; i++) {
            cout << "*";
        }
        // Move to the next line after printing the asterisks
        cout << endl;
    }
}

// Main function
int main() {
    ItemTracker itemTracker;
    itemTracker.readDataFile();
    itemTracker.displayMenu();
    return 0;
}