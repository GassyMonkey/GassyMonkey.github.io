#include <iostream>
#include "Random.h"

int getMinimum() {
    int minimum{};
    std::cout << "Enter the minimum number: ";
    std::cin >> minimum;

    return minimum;
}

int getMaximum() {
    int maximum{};
    std::cout << "Enter the maximum number: ";
    std::cin >> maximum;

    return maximum;
}

int getAttempts() {
    int attempts{};
    std::cout << "Enter the amount of attempts: ";
    std::cin >> attempts;

    return attempts;
}

void introGame(int minimum, int maximum, int attempts) {
    std::cout << "Let's play a game. I'm thinking of a number between " << minimum <<
       " and " << maximum << ". You have " << attempts << " tries to guess what it is.\n";
}

int getGuess(int tries) {
    std::cout << "Guess #" << tries << ": ";

    int guess{};
    std::cin >> guess;
    return guess;
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
        int guess{ getGuess(tries) };

        if (returnResults(guess, randomNum)) {
            return;
        }
    }

    std::cout << "Sorry, you lose. The correct number was " << randomNum << ".\n";
}

bool askReplay() {
    char response{};
    while (response != 'y' && response != 'n') {
        std::cout << "Would you like to play again (y/n) ? ";
        std::cin >> response;
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