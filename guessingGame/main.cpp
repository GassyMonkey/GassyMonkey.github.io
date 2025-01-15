#include <cstdlib>
#include <iostream>
#include <limits>
#include "Random.h"


bool checkExtraction() {
    if (!std::cin) {
        if (std::cin.eof())
            std::exit(0);

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return true;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return false;
}

int getMinimum() {
    while (true) {
        int minimum{};
        std::cout << "Enter the minimum number: ";
        std::cin >> minimum;

        if (!checkExtraction())
            return minimum;
    }
}

int getMaximum() {
    while (true) {
        int maximum{};
        std::cout << "Enter the maximum number: ";
        std::cin >> maximum;

        if (!checkExtraction())
            return maximum;
    }
}

int getAttempts() {
    while (true) {
        int attempts{};
        std::cout << "Enter the amount of attempts: ";
        std::cin >> attempts;

        if (!checkExtraction())
            return attempts;
    }
}

void introGame(int minimum, int maximum, int attempts) {
    std::cout << "Let's play a game. I'm thinking of a number between " << minimum <<
        " and " << maximum << ". You have " << attempts << " tries to guess what it is.\n";
}

int getGuess(int tries, int min, int max) {
    while (true) {
        std::cout << "Guess #" << tries << ": ";
        int guess{};
        std::cin >> guess;

        bool success{ checkExtraction() };


        if (guess < min || success || guess > max)
            continue;

        return guess;
    }
}

bool returnResults(int guess, int randomNumber) {
    if (guess == randomNumber) {
        std::cout << "Correct! You Win!\n";
        return 1;
    }
    else if (guess < randomNumber)
        std::cout << "Your guess is too low.\n";
    else
        std::cout << "You guess is too high.\n";

    return 0;
}

void playGame() {
    int minimum{ getMinimum() };
    int maximum{ getMaximum() };
    int attempts{ getAttempts() };

    introGame(minimum, maximum, attempts);
    int randomNum{ Random::get(minimum, maximum) };

    for (int tries{ 1 }; tries <= attempts; ++tries) {
        int guess{ getGuess(tries, minimum, maximum) };

        if (returnResults(guess, randomNum)) {
            return;
        }
    }

    std::cout << "Sorry, you lose. The correct number was " << randomNum << ".\n";
}

bool askReplay() {
    char response{};
    bool success{};
    while (response != 'y' && response != 'n' && !success) {
        std::cout << "Would you like to play again (y/n) ? ";
        std::cin >> response;
        success = checkExtraction();
    }

    if (response == 'y')
        return 1;
    else
        return 0;
}

int main()
{
    do {
        playGame();

    } while (askReplay());

    std::cout << "Thank you for playing.\n";

    return 0;
}