#include "Clock.h"
#include <stdexcept>

using namespace std;

Clock::Clock(int hours, int minutes, int seconds) {

    // validates paramaters for hours, minutes, and seconds.
    this->hours = hours;
    if (this->hours < 0 || this->hours > 23) {  // if hours is less than '1' or greater than '23' then invalud argument gets thrown.

        throw std::invalid_argument("Input is invalid. Please Re-enter.");   // validator.
    }
    this->minutes = minutes;
    if (this->minutes < 0 || this->minutes > 59) {  // if minutes is less than '0' or greater than '59' then invalud argument gets thrown.
        
        throw std::invalid_argument("Input is invalid. Please Re-enter.");   // validator.
    }
    this->seconds = seconds;
    if (this->seconds < 0 || this->seconds > 59) {  // if seconds is less than '0' or greater than '59' then invalud argument gets thrown.
        
        throw std::invalid_argument("Input is invalid. Please Re-enter.");   // validator.
    }
}
    // adds hour to clock.
void Clock::addHour() {

    if (hours == 23) {   // if hours is equal to 23.
        this->hours = 0;  // sets hours to '0'.
        }
    else {   // else adds an hour to the clock.
        this->hours = this->hours + 1;
    }
}

    // adds minute to clock.
void Clock::addMinute() {

    if ((this->minutes == 59)) {   // minutes is equal to 59.
        this->minutes = 0;   // sets minutes to '0'.
        addHour();   // adds hour.
    }
    else {   // else adds a minute to the clock.
        this->minutes = this->minutes + 1; 
    }
}

    // adds second to clock.
void Clock::addSecond() {

    if (this->seconds == 59)  {
        this->seconds = 0;   // sets seconds to '0'.
        addMinute();   // adds minute.
    }
    else {   // else adds a second to the clock.
        this->seconds = this->seconds + 1;
    }
}

    // displays 24 hour clock.
string Clock::get24HourFormat() {

    string militaryTime = pad(hours) + ':' + pad(minutes) + ':' + pad(seconds);   // strings together 00:00:00

    return militaryTime;   // returns 00:00:00
}

    // displays 12 hour clock.
string Clock::get12HourFormat() {

    int tempHours = hours;   // integer that holds private hours value.
    string standardTime;   // string to hold 12:00:00 am/pm.
    
    if (tempHours >= 13) {   // if tempHours is greater than 13 than sets hour to standard to standard time equivelant.
        tempHours = tempHours - 12;
    }
    else if (tempHours == 0) {   // if tempHours is 0 sets clock to 12:00:00 am.
        tempHours = 12;
    }

    standardTime = to_string(tempHours) + ':' + pad(minutes) + ':' + pad(seconds) + ' ' + getSuffix();   // strings together 12:00:00 am/pm. 

    return standardTime;   // returns 12:00:00 am/pm
 
}

    // adds AM/PM suffix to 12 hour clock.
string Clock::getSuffix() {
    
    string suffix;   // string that holds am/pm.

    if (hours >= 0 && hours <= 11) {   // if hours is between '0' and '11' clock suffix will be 'AM'.
        suffix = "AM";
    }
    else {   // else the clock suffix will be 'PM'.
        suffix = "PM";
    }

    return suffix;   // returns AM/PM.
}

    //incantonates '0' to front of value if it is a single digit.
string Clock::pad(int value) {

    string valueString;   // string variable that holds the value of int variable 'value'.
    string padValue = "0";   // variable that holds '0'.
    
    // if else statement that checks to see if value needs a '0' concantonated.

    if (value < 10) {   
        valueString = to_string(value);   // casts int variable to a string variable.
        valueString = padValue.append(valueString);   // pads '0' in front of all variables less than 10.
          
    }
    else {
        valueString = to_string(value);  // casts int variable to a string.
    }
    return valueString;   // returns 'value' as a string.

}
