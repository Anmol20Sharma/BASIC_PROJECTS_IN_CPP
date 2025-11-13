#include <bits/stdc++.h>
using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    int lower = 1, upper = 100; // Range of numbers
    int number = rand() % (upper - lower + 1) + lower; // Random number
    int guess;
    int attempts = 0;

    cout << " Welcome to the Number Guessing Game!\n";
    cout << "I'm thinking of a number between " << lower << " and " << upper << ".\n";

    // Game loop
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < number) {
            cout << "Too low. Try again.\n";
        } else if (guess > number) {
            cout << "Too high. Try again.\n";
        } else {
            cout << "Correct! You guessed the number in " << attempts << " attempts.\n";
        }

    } while (guess != number);

    return 0;
}
