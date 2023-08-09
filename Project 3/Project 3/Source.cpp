#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class produceFrequency {
public:
    // Reads the input file and generates the frequency data
    void InputFile(string filename) {
        ifstream input(filename);
        if (input.fail()) {
            cout << "Error: Could not open file " << filename << endl;
            return;
        }
        string item;
        while (input >> item) {
            freqData[item]++;
        }
        input.close();
    }

    // Returns the frequency of a specific item
    int getItemFrequency(string item) {
        return freqData[item];
    }

    // Prints a list of all items and their frequencies
    void printFrequencyList() {
        for (auto it = freqData.begin(); it != freqData.end(); ++it) {
            cout << it->first << ": " << it->second << endl;
        }
    }

    // Prints a histogram of all items and their frequencies
    void printFrequencyHistogram() {
        for (auto it = freqData.begin(); it != freqData.end(); ++it) {
            cout << it->first << " ";
            for (int i = 0; i < it->second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }

    // Writes the frequency data to a backup file
    void backupFrequencyData(string filename) {
        ofstream output(filename);
        if (output.fail()) {
            cout << "Error: Could not open file " << filename << endl;
            return;
        }
        for (auto it = freqData.begin(); it != freqData.end(); ++it) {
            output << it->first << ": " << it->second << endl;
        }
        output.close();
    }

private:
    map<string, int> freqData;
};

int main() {
    produceFrequency produce;

    // Process the input file
    produce.InputFile("project_3_input_file.txt");

    // Main menu loop
    bool running = true;
    while (running) {
        // Display menu options
        cout << endl;
        cout << "Select an option:" << endl;
        cout << "1. Find item's frequency" << endl;
        cout << "2. Print list of all items and frequencies" << endl;
        cout << "3. Print histogram of item frequencies" << endl;
        cout << "4. Exit the program" << endl;

        // Get user input
        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        // Perform action based on user input
        switch (choice) {
        case 1: {
            string item;
            cout << "Enter the item to look up: ";
            cin >> item;
            int freq = produce.getItemFrequency(item);
            cout << "Frequency of " << item << ": " << freq << endl;
            break;
        }
        case 2: {
            produce.printFrequencyList();
            break;
        }
        case 3: {
            produce.printFrequencyHistogram();
            break;
        }
        case 4: {
            produce.backupFrequencyData("frequency.dat");
            running = false;
            break;
        }
        default: {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            break;
        }
        }
    }
    return 0;
}