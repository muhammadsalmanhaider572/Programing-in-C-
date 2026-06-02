#include <iostream>
#include <cstdlib> // Required for rand() and srand()
#include <ctime>   // Required for time()

using namespace std;

int main() {
    // Seed the random number generator using the system time
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = (rand() % 100) + 1;
    int guess = 0;
    int attempts = 0;

    cout << "=========================================" << endl;
    cout << "       WELCOME TO THE GUESSING GAME      " << endl;
    cout << "=========================================" << endl;
    cout << "I have chosen a number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    // Loop until the player guesses the correct number
    while (guess != secretNumber) {
        cout << "\nEnter your guess: ";
        cin >> guess;
        attempts++; // Increment the number of tries

        if (guess > secretNumber) {
            cout << "❌ Too high! Try a lower number." << endl;
        } 
        else if (guess < secretNumber) {
            cout << "❌ Too low! Try a higher number." << endl;
        } 
        else {
            cout << "\n🎉 CONGRATULATIONS! You guessed it!" << endl;
            cout << "The correct number was " << secretNumber << "." << endl;
            cout << "It took you " << attempts << " attempts to win." << endl;
        }
    }

    return 0;
}