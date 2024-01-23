#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int secretNumber = std::rand() % 100 + 1;

    int guess;

    std::cout << "Welcome to the Number Guessing Game!\n";
    
    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number.\n";
        }
    } while (guess != secretNumber);

    return 0;
}
