#include <iostream>
#include <ctime>

class Clock {
private: //basic variables for the clock to work
    int hours; 
    int minutes;
    int seconds;  
    bool is12HourClock; 
    bool isAM; 
    bool is24HourFormat; 
    int timeZone; 
public:
    Clock() { // variables changed to allow for "local time"
        time_t currentTime = time(0); 
        tm * localTime = localtime(&currentTime); 
        hours = localTime->tm_hour; 
        minutes = localTime->tm_min; 
        seconds = localTime->tm_sec; 
        is12HourClock = true; 
        isAM = true; 
        is24HourFormat = true; 
        timeZone = 0; 
    }
    void addHour() {
        hours = (hours + 1) % 24; // increment the hours, % keeps 0-23 range
        if (hours == 0)
        {
            if (isAM)
            {
                isAM = false; // 
            }
            else
            {
                isAM = true; 
            }
        }
    }

    void addMinute() {
        minutes = (minutes + 1) % 60; // increment the minutes,% keep 0-59 range
        if (minutes == 0) {
            addHour(); // if minutes is 0, increment the hour
        }
    }

    void addSecond() {
        seconds = (seconds + 1) % 60; // increment the seconds, % keeps 0-59 range
        if (seconds == 0) {
            addMinute(); // if seconds is 0, increment the minutes
        }
    }

    void changeClockFormat() {
        is12HourClock = !is12HourClock; // changes the between 12 hour and 24 hour
    }

    void change24HourFormat() {
        is24HourFormat = !is24HourFormat; // changes between 24 hour and 12 hour
    }

    void setTimeZone(int timeZone) {
        this->timeZone = timeZone; // sets the time zone
    }

    void displayClock() {
        if (is24HourFormat) {
            std::cout << hours << ":" << minutes << ":" << seconds;
        }
        else {
            int hour = (hours % 12 == 0) ? 12 : hours % 12; 
            std::cout << hour << ":" << minutes << ":" << seconds;
            if (isAM)
            {
                std::cout << " AM";
            }
            else
            {
                std::cout << " PM";
            }
        }
        if (timeZone != 0) {
            std::cout << " (UTC " << ((timeZone > 0) ? "+" : "") << timeZone << ")";
        }
    }
};

int main() {
    Clock clock;

    while (true) {
        std::cout << "Clock: ";
        clock.displayClock();

        std::cout << "\n\nMenu: \n1. Add Hour \n2. Add Minute \n3. Add Second \n4. Toggle Clock Format \n5. Toggle 24 Hour Format \n6. Set Time Zone \n7. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) { //switch statement
        case 1:
            clock.addHour();
            break;
        case 2:
            clock.addMinute();
            break;
        case 3:
            clock.addSecond();
            break;
        case 4:
            clock.changeClockFormat();
            break;
        case 5:
            clock.change24HourFormat();
            break;
        case 6:
            int timeZone;
            std::cout << "Enter time zone (in hours): ";
            std::cin >> timeZone;
            clock.setTimeZone(timeZone);
            break;
        case 7:
            return 0;
        default:
            break;
        }
    }
    return 0;
}
