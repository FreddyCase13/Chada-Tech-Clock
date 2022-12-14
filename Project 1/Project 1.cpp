#include "Clock.h"
#include "Validator.h"
#include <iostream>
#include <string>
#include <Windows.h>


using namespace std;

void handleInvalidInput(Validator validator) {   // Prints error message and provide the valid range
    
    cout << "Entered value is not valid, valid range is [";
    cout << validator.getMinValue() << " - " << validator.getMaxValue() << "]" << endl;
    cout << "Enter Selection:" << endl;
}

void displayMainMenu() {   // Prints the main menu 
    
    cout << endl;
    cout << "Main Menu" << endl;
    cout << "1 - Display Clock" << endl;
    cout << "2 - Update Clock" << endl;
    cout << "3 - Exit Program" << endl;
    cout << endl;
    cout << "Enter Selection:" << endl;
}

    void displayUpdateClockMenu() {   // Prints the menu to update the time
      
        cout << endl;
    cout << "Update Clock" << endl;
    cout << "1 - Add One Hour" << endl;
    cout << "2 - Add One Minute" << endl;
    cout << "3 - Add One Second" << endl;
    cout << endl;
    cout << "Enter Selection:" << endl;

}


    void displayClock(Clock clock) {   // Prints the clock's 12 hour and 24 hour formats.

        cout << "12 HOUR CLOCK      " << clock.get12HourFormat() << endl;
        cout << "24 HOUR CLOCK      " << clock.get24HourFormat() << endl;
}




    int main()
    {
        //Constants for menu choices
        const int DISPLAY_CLOCK_MENU_CHOICE = 1;
        const int UPDATE_CLOCK_MENU_CHOICE = 2;
        const int EXIT_PROGRAM_MENU_CHOICE = 3;
        const int ADD_ONE_HOUR_UPDATE_CLOCK = 1;
        const int ADD_ONE_MINUTE_UPDATE_CLOCK = 2;
        const int ADD_ONE_SECOND_UPDATE_CLOCK = 3;

        //Clock instance
        Clock clock(0, 0, 0);

        //Variable for main menu and update clock user choice
        int userMenuChoice = -1;
        int userUpdateClockChoice;

        Validator menuChoiceValidator(DISPLAY_CLOCK_MENU_CHOICE, EXIT_PROGRAM_MENU_CHOICE);   // Main menu validator variables.
        Validator displayClockValidator(ADD_ONE_HOUR_UPDATE_CLOCK, ADD_ONE_SECOND_UPDATE_CLOCK);   // Update clock validator variables.

        //do-while loop
        while (userMenuChoice != EXIT_PROGRAM_MENU_CHOICE) {
            //Clear the console screen
            system("cls");

            // Displays the clock times.
            displayClock(clock);

            //Displays main menu
            displayMainMenu();

            // asks for users input for main menu
            cin >> userMenuChoice;

            // Handles input validator user method
            while (!menuChoiceValidator.isValid(userMenuChoice)) {  // while loop that checks if userMenuChoice is within valid range.
                handleInvalidInput(menuChoiceValidator);   // Throws bad input.
                cout << endl;
                cout << "Enter Selection" << endl;   // asks for new input
                cin >> userMenuChoice;
            }

            //Main menu input
            if (userMenuChoice == DISPLAY_CLOCK_MENU_CHOICE) {   // If input is '1' then adds second to clock.
                clock.addSecond();
                cout << endl;
            }
            else if (userMenuChoice == UPDATE_CLOCK_MENU_CHOICE) { // If input is '2' then it opens Update Clock Menu.
                displayUpdateClockMenu();

                cin >> userUpdateClockChoice;   // gets user input for update clock menu.

                while (!displayClockValidator.isValid(userUpdateClockChoice)) {   // while loop that checks if userUpdateChoice is within valid range.

                    handleInvalidInput(displayClockValidator);   //throws bad input
                    cout << endl;
                    cout << "Enter Selection" << endl;   // asks for new input
                    cin >> userUpdateClockChoice;
                }

                if (userUpdateClockChoice == ADD_ONE_HOUR_UPDATE_CLOCK) {   // if input is '1' then it adds hour to clock.
                    clock.addHour();   // adds hour to clock.
                    cout << endl;
                }
                else if (userUpdateClockChoice == ADD_ONE_MINUTE_UPDATE_CLOCK) {   // if input is '2' then it adds minute to clock.
                    clock.addMinute();   // adds minute to clock.
                    cout << endl;
                }
                else if (userUpdateClockChoice == ADD_ONE_SECOND_UPDATE_CLOCK) {   // if input is '2' then it adds minute to clock.
                    clock.addSecond();   // adds second to clock.
                    cout << endl;
                }
            }
        }
        return 0;   // returns nothing.
    }
