#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
using namespace std;
int main() {
	//variables for city and c/f
	string cityName;
	int fahrenheit, celcius;

	//This is used to open the .txt file
	fstream inputFile;
	inputFile.open("FahrenheitTemperature.txt");

	//This creates the writing to a file
	ofstream outputFile;
	outputFile.open("CelsiusTemperature.txt");

	//This throws an error if the file is corrupted etc..
	if (!inputFile) {
		cout << "File cannot be opened." << endl;
	}
	else {
		//This while loop reads the name of the city and it's temperature
		while (inputFile >> cityName >> fahrenheit) {
			//This command changes the fahrenheit to celcius
			celcius = (int)round(((fahrenheit - 32) * 5) / (double)9);
			//This writes the city name and converted to c temperature
			outputFile << cityName << " " << celcius << endl;
		}
	}

	//This ensures that the file is closed
	inputFile.close();
	outputFile.close();

	return 0;
}
