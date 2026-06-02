#include <iostream>
#include <cstdlib> // Required for rand() and srand()
#include <ctime>   // Required for time()

using namespace std;

int main() {
    // Seed the random number generator so the results are different every run
    srand(time(0));

    char choice;

    cout << "Welcome to the Dice Rolling Simulator!" << endl;
    cout << "--------------------------------------" << endl;

    do {
        cout << "\nRolling the dice..." << endl;

        // rand() % 6 gives a number from 0 to 5. 
        // Adding 1 shifts the range to 1 to 6.
        int die1 = (rand() % 6) + 1;
        int die2 = (rand() % 6) + 1;
        int total = die1 + die2;

        // Display the results
        cout << "Die 1: " << die1 << endl;
        cout << "Die 2: " << die2 << endl;
        cout << "Total: " << total << endl;

        // Ask the user to continue
        cout << "\nWould you like to roll again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThanks for playing! Goodbye." << endl;

    return 0;
}