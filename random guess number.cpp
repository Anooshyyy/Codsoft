#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    // Initialize the user's guess to something outside the valid range
    int userGuess = 0;

    std::cout << "Welcome to the Guess the Number game!\n";
    std::cout << "I have chosen a number between 1 and 100. Try to guess it.\n";

    while (userGuess != secretNumber) {
        // Get user input for their guess
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        // Provide feedback on the user's guess
        if (userGuess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else if (userGuess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number, " << secretNumber << "!\n";
        }
    }

    return 0;
}

