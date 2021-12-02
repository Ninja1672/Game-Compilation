/* This program is designed to let the user play a variety of games within a terminal window.*/

#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

void guessingGame();
void hangMan();
void displayMenu();

int main()
{
    int choice;
    bool cont = true;
    while (cont)
    {
        displayMenu();
        cin >> choice;
        switch (choice) // Look at display menu to understand the case numbers
        {
        case 1:
            guessingGame();
            break;
        case 2:
            hangMan();
            break;
        case 3: // Will make this game later
            cout << "In development, pick a different option please!" << endl;
            break;
        case 4:
            cont = false; // Exit
            break;
        default: // Some kind of number or letter we don't know was pressed
            cout << "You didn't input a valid response, please pick from displayed numbers." << endl;
            cin.clear();
            cin.ignore();
            break;
        }
    }
    cout << "Thanks for to playing my game!";
}

void displayMenu() // Quick way to display the menu
{
    cout << "What game would you like to play? " << endl;
    cout << "1. Guessing Number Game: 1 Player" << endl;
    cout << "2. HangMan: 2 Players" << endl;
    cout << "3. MineSweeper: 1 Player" << endl;
    cout << "4. Exit" << endl;
}

void hangMan() // This should be adjusted for error handling and adding features like not letting them guess a letter more than once.
{
    char guessed[26];
    int playerLife = 5;
    char letter;
    bool found = false;
    string hiddenWord;
    string emptyWord;
    int guessType;
    cout << "Player 1 please type a number into the terminal and don't tell player 2!" << endl;
    cout << "The program will hide what you type by entering enough newlines to move it off screen." << endl;
    cin >> hiddenWord;
    for (int i = 0; i < hiddenWord.length(); i++) {
        emptyWord += '_';
    }
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    
    while (hiddenWord != emptyWord && playerLife > 0)
    {
        found = false;
        for (int i = 0; i < emptyWord.length(); i++) {
            cout << emptyWord[i] << ' ';
        }
        cout << endl;

        cout << "Player 2 input a letter" << endl;
        cout << "Life: " << playerLife << endl;
        cin >> letter;
        for (int i = 0; i < hiddenWord.length(); i++) {
            if (letter == hiddenWord[i]) {
                emptyWord[i] = letter;
                found = true;
            }
        }
        if (!found) {
            playerLife--;
        }
    }
    if (playerLife > 0) {
        cout << "You won great! The word was " << hiddenWord << endl;
    }
    else {
        cout << "Good try, the word was " << hiddenWord << ". Better luck next time." << endl;
    }
    cout << endl << endl << endl;
}

void guessingGame()
{
    bool cont = true;
    int choice;
    int guesses = 0;
    cout << "What is the max number you want to guess between? " << endl;
    cout << "Make sure its an integer that isn't 0! It may crash things..." << endl;
    cin >> choice;
    if (choice < 1) {
        cout << "YOU HAD ONE JOB! ITS GOING TO CRASH!!!" << endl;
        cout << "OH THE PAIN! OH THE HUMANITY OF IT ALL!" << endl;
        cout << "EVERYTHING IS RUINED YOU MONSTER" << endl << endl << endl << endl;
        cout << "Please just give me a positive not 0 number next time!" << endl;
        return;
    }
    // Originally only gave 42 (the meaning of life anyone?) as its first number.
    // Now we should get truly random numbers with the next line.
    srand(time(0));
    int rand_num = rand() % choice + 1; // get random number
    // cout << rand_num << endl; // Comment this out if you aren't a cheater!

    while (cont) {
        try { // I just want to know if something implodes when they execute the code.
            cout << "What is your guess? ";

            cin >> choice;

            guesses++;

            if (choice > rand_num) {
                cout << "Too High!" << endl;
            }

            else if (choice < rand_num) {
                cout << "Too Low!" << endl;
            }

            else if (choice == rand_num) {
                cout << "Correct! :D" << endl;
                cont = false;
            }

        }
        catch (const exception& e) {
            cout << "We have thrown an exception in our while loop!" << endl;
            cout << &e;
        }
    }
    cout << "You found the number in " << guesses << " guesses. Nice!" << endl << endl << endl;
}